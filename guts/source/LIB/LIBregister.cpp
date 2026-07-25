//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Friday 24th July 2026
//       0x6A63FBD5 the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include <LUA/LUAlua.h>
#include <STRING/STRINGsplit.h>
#include <URL/URLopen.h>

#include <COL/COLtrace.h>
COL_TRACE_INIT;

// This file is auto generated. 
void LIBregister(lua_State* L){
   COL_FUNCTION(LIBregister);
   lua_register(L, "STRINGsplit", STRINGsplit);
   lua_register(L, "URLopen", URLopen);
}
