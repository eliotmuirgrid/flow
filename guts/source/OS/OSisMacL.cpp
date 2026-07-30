//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Thursday 30th July 2026
//       0x6A6B7B5C seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include <OS/OSisMac.h>
#include <LUA/LUAlua.h>
#include <COL/COLtrace.h>
COL_TRACE_INIT;

int OSisMacL(lua_State* L){
   COL_FUNCTION(OSisMacL);
   lua_pushboolean(L, OSisMac()); 
   return 1;
}
