//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Thursday 30th July 2026
//       0x6A6BD434 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include <COL/COLstringPushL.h>
#include <LUA/LUAlua.h>
#include <COL/COLtrace.h>
COL_TRACE_INIT;

void REGtableGet(lua_State* L, const COLstring& Name){
   COL_FUNCTION(REGtableGet);
   COLstringPushL(L, Name);
   lua_rawget(L, LUA_REGISTRYINDEX);
}
