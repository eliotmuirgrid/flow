//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Thursday 30th July 2026
//       0x6A6BD9C0 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "LUAlua.h"
#include "COLtrace.h"
COL_TRACE_INIT;

int STACKsize(lua_State* L, int i){
   COL_FUNCTION(STACKsize);
   int Size = luaL_getn(L, i);
   COL_VAR(Size);
   return Size;
}