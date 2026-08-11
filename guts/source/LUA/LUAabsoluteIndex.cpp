//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Sunday 9th August 2026
//       0x6A794BEA seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "LUAabsoluteIndex.h"
#include "LUAlua.h"
#include "COLtrace.h"
COL_TRACE_INIT;

int LUAabsoluteIndex(lua_State* L, int i){
   COL_FUNCTION(LUAabsoluteIndex);
   if (i > 0 || i <= LUA_REGISTRYINDEX){
      return i;
   }

   return lua_gettop(L) + i + 1;
}
