//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Thursday 30th July 2026
//       0x6A6BDA0E seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include <STACK/STACKfetch.h>
#include <STACK/STACKsize.h>
#include <LUA/LUAlua.h>
#include <COL/COLtrace.h>
COL_TRACE_INIT;

void STACKtop(lua_State* L, int i){
   COL_FUNCTION(STACKtop);
   int Size = STACKsize(L, i);
   STACKfetch(L, i, Size);
}
