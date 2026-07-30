//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Wednesday 29th July 2026
//       0x6A6A9004 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include <LUA/LUAlua.h>
#include <LUA/LUAprintValue.h>
#include <COL/COLtrace.h>
COL_TRACE_INIT;

void LUAshowArgs(lua_State* L, lua_Debug* ar, COLstream& Out){
   COL_FUNCTION(LUAshowArgs);
   Out << "(";
   for (int i = 1;; ++i) {
      const char* localName = lua_getlocal(L, ar, i);
      if (!localName) { break; }
      if (i > 1) { Out << ", "; }

      COLlog << localName << "=";
      LUAprintValue(L, -1, Out);
      lua_pop(L, 1);
   }
   Out << ")";
}
