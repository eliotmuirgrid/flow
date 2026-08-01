//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Thursday 30th July 2026
//       0x6A6BD393 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "LUAlua.h"
#include "COLstringPushL.h"
#include "COLtrace.h"
COL_TRACE_INIT;

void REGtableSet(lua_State* L, const COLstring& Name){
   COL_FUNCTION(REGtableSet);
   COLstringPushL(L, Name);
   lua_newtable(L);
   lua_rawset(L, LUA_REGISTRYINDEX);
   COL_TRC("Set registry table " << Name);
}