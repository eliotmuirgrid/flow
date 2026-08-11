//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Thursday 30th July 2026
//       0x6A6BDB44 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "STACKsize.h"
#include "LUAlua.h"
#include "COLassert.h"
#include "COLtrace.h"
COL_TRACE_INIT;

// Assumes that top of stack has the thing being pushed.
void STACKpush(lua_State* L, int i){
   COL_FUNCTION(STACKpush);
   COL_VAR(i);
   COLASSERT(lua_istable(L,i));
   int Size = STACKsize(L, i);
   COL_VAR(Size);
   lua_rawseti(L, i, Size+1);
   int Size2 = STACKsize(L,i);
   COLASSERT(Size2 == Size+1);
}
