//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Thursday 30th July 2026
//       0x6A6BDA86 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include <LUA/LUAlua.h>
#include <COL/COLtrace.h>
COL_TRACE_INIT;

void STACKfetch(lua_State* L, int i, int j){
   COL_FUNCTION(STACKfetch);
   lua_rawgeti(L, i, j);
}
