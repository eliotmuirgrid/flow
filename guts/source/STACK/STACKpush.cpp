//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Thursday 30th July 2026
//       0x6A6BDB44 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include <STACK/STACKsize.h>
#include <LUA/LUAlua.h>
#include <COL/COLtrace.h>
COL_TRACE_INIT;

// Assumes that top of stack has the thing being pushed.
void STACKpush(lua_State* L, int i){
   COL_FUNCTION(STACKpush);
   int Size = STACKsize(L, i);
   lua_rawseti(L, i, Size+i);
}
