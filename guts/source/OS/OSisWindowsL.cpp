//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Thursday 30th July 2026
//       0x6A6B7BC1 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include <OS/OSisWindows.h>
#include <LUA/LUAlua.h>
#include <COL/COLtrace.h>
COL_TRACE_INIT;

int OSisWindowsL(lua_State* L){
   COL_FUNCTION(OSisWindowsL);
   lua_pushboolean(L, OSisWindows());
   return 1;
}
