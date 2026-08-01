//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Wednesday 29th July 2026
//       0x6A6A93EB seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "LUAlua.h"
#include "COLtrace.h"
#include "COLstringPushL.h"
COL_TRACE_INIT;

void REGkeySet(lua_State* L, const COLstring& K, const COLstring& V){
   COL_FUNCTION(REGkeySet);
   COLstringPushL(L, K);
   COLstringPushL(L, V);
   lua_rawset(L, LUA_REGISTRYINDEX);
   COL_TRC("Set registry " << K << "=" << V);
}