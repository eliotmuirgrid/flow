/*************************
 * Copyright (C) Eliot Muir Forever
 *
 * LUAtrace
 *
 * Date: Wed  1 Jul 2026 06:17:53 EST
 **************************/

#include <COL/COLstring.h>
#include <COL/COLglob.h>
#include <LUA/LUAlua.h>
#include <LUA/LUAtrace.h>
#include <LUA/LUAtraceEnable.h>
#include <FIL/FILpathNameNoExt.h>

#include "COL/COLtrace.h"
COL_TRACE_INIT;

static COLstring s_LUAmatch;

void LUAprintValue(lua_State* L, int i){
   int type = lua_type(L, i);
   switch (type) {
      case LUA_TNIL:     COLlog << "nil";                                    break;
      case LUA_TBOOLEAN: COLlog << (lua_toboolean(L, i) ? "true" : "false"); break;
      case LUA_TNUMBER:  COLlog << lua_tonumber(L, i);                       break;
      case LUA_TSTRING:  COLlog << '"' << lua_tostring(L, i) << '"';         break;
      default:           COLlog << '<' << lua_typename(L, type) << '>';      break;
   }
}

void LUAshowArgs(lua_State* L, lua_Debug* ar){
   COLlog << "(";
   for (int i = 1;; ++i) {
      const char* localName = lua_getlocal(L, ar, i);
      if (!localName) { break; }
      if (i > 1) { COLlog << ", "; }

      COLlog << localName << "=";
      LUAprintValue(L, -1);
      lua_pop(L, 1);
   }
   COLlog << ")";
}

void LUAdebugHook(lua_State* L, lua_Debug* ar){
   if (!lua_getinfo(L, "nSl", ar)){ return; }
   if (!ar->name){
      return;
   }
   COLstring source = ar->short_src[0] ? ar->short_src : "?";

   COL_TRC("Source before COL filtering =" << source);
   if (source.find("COLshow")){ COL_TRC("Matched COLshow"); return; }
   if (source.find("COLtrace")){ COL_TRC("Matched COLtrace"); return; }

   COL_HEX("Source:", source.data(), source.size());
   COL_VAR(source.data()[0]);
   bool Check =source.data()[0] == '[' || source.data()[0] == '(';
   COL_VAR(Check);
   if (Check) { COL_TRC("In C Function or tail call."); return; } // it equals [ HACK [C]
   source = FILpathNameNoExt(source);
   COL_TRC("Source after FILpathNameNoExt=" << source);
   if (!COLglobMatch(source.data(), s_LUAmatch.data())){ LUAtraceEnable(L, ""); return; }
   COLstring name = source;
   source += ".lua";
   LUAtraceEnable(L, source);
   
   switch (ar->event){
   case LUA_HOOKCALL: COLtimeStamp(source.data(), COLlog);COLlog << ">" << name; LUAshowArgs(L, ar); COLlog << newline; COLcallIncrease(); break;
   case LUA_HOOKRET : COLcallDecrease(); COLtimeStamp(source.data(), COLlog);COLlog << "<" << name << newline;                             break;
   }
}

void LUAtrace(lua_State* L, const COLstring& Match){
   s_LUAmatch = Match;
   lua_sethook(L, LUAdebugHook, LUA_MASKCALL | LUA_MASKRET, 0);
}
