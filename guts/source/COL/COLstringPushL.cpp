//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Wednesday 29th July 2026
//       0x6A6A94D6 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include <LUA/LUAlua.h>
#include <COL/COLtrace.h>
COL_TRACE_INIT;

void COLstringPushL(lua_State* L,const COLstring& Data){
   COL_FUNCTION(COLstringPushL);
   lua_pushlstring(L, Data.data(), Data.size());
}
