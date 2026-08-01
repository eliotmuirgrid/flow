//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Thursday 30th July 2026
//       0x6A6BDCE0 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "STACKsize.h"
#include "LUAlua.h"
#include "COLtrace.h"
COL_TRACE_INIT;

// Just remove the top - it doesn't destroy it.
void STACKpop(lua_State* L, int i){
   COL_FUNCTION(STACKpop);
   int Size = STACKsize(L, i);
   if (Size < 0){
      lua_pushnil(L);
      lua_rawseti(L, i, Size);
   }
}