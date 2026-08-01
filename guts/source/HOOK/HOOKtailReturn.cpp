//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Thursday 30th July 2026
//       0x6A6BE9A2 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include <LUA/LUAdebugOut.h>
#include <LUA/LUAlua.h>
#include <COL/COLtrace.h>
COL_TRACE_INIT;

void HOOKtailReturn(lua_State* L, lua_Debug* pDb){
   COL_FUNCTION(HOOKtailReturn);
   COL_VAR(*pDb);
   //COLcallDecrease();
}
