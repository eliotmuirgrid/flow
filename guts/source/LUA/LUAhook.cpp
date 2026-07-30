//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Wednesday 29th July 2026
//       0x6A6A8FDF seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include <LUA/LUAlua.h>
#include <LUA/LUAhook.h>
#include <LUA/LUAtracePatternGet.h>
#include <LUA/LUAtraceFileSet.h>
#include <FIL/FILpathNameNoExt.h>
#include <COL/COLglobMatch.h>
#include <COL/COLtrace.h>
COL_TRACE_INIT;

void LUAhook(lua_State* L, lua_Debug* ar){
   COL_FUNCTION(LUAhook);
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
   COLstring MatchPattern = LUAtracePatternGet(L);
   if (!COLglobMatch(source.data(), MatchPattern.data())){ LUAtraceFileSet(L, ""); return; }
   COLstring name = source;
   source += ".lua";
   LUAtraceFileSet(L, source);

   switch (ar->event){
   case LUA_HOOKCALL: COLtimeStamp(source.data(), COLlog);COLlog << ">" << name << "()" << newline; COLcallIncrease(); break;
   case LUA_HOOKRET : COLcallDecrease(); COLtimeStamp(source.data(), COLlog);COLlog << "<" << name << newline;                             break;
   }
}
