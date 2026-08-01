//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Wednesday 29th July 2026
//       0x6A6A93E5 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "LUAlua.h"
#include "COLstringPushL.h"
#include "COLstringL.h"
#include "COLtrace.h"
COL_TRACE_INIT;

COLstring REGkeyGet(lua_State* L, const COLstring& Key){
   COL_FUNCTION(REGkeyGet);
   COLstringPushL(L, Key);
   lua_rawget(L, LUA_REGISTRYINDEX);
   COLstring Result = COLstringL(L, -1);
   lua_pop(L, 1);
   COL_VAR(Result);
   return Result;
}