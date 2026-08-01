//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Wednesday 29th July 2026
//       0x6A6A900E seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "LUAlua.h"
#include "COLtrace.h"
COL_TRACE_INIT;

void LUAprintValue(lua_State* L, int i, COLstream& Out){
   COL_FUNCTION(LUAprintValue);
   int type = lua_type(L, i);
   switch (type) {
      case LUA_TNIL:     Out << "nil";                                    break;
      case LUA_TBOOLEAN: Out << (lua_toboolean(L, i) ? "true" : "false"); break;
      case LUA_TNUMBER:  Out << lua_tonumber(L, i);                       break;
      case LUA_TSTRING:  Out << '"' << lua_tostring(L, i) << '"';         break;
      default:           Out << '<' << lua_typename(L, type) << '>';      break;
   }
}