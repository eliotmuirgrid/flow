//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Friday 14th August 2026
//       0x6A7F17DF seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "LTABCboolean.h"
#include "LUAlua.h"
#include "JSONvar.h"
#include "COLtrace.h"
COL_TRACE_INIT;

void LTABCboolean(lua_State* L, JSONvar* pVar){
   COL_FUNCTION(LTABCboolean);
   pVar->Type    = LUA_TBOOLEAN;
   pVar->Boolean = lua_toboolean(L, -1) != 0; 
}
