//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Tuesday 28th July 2026
//       0x6A68FA30 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include <LUA/LUAlua.h>
#include <LUA/LUAtraceEnable.h>
#include <COL/COLstringL.h>
#include <COL/COLtrace.h>
COL_TRACE_INIT;

COLstring LUAtraceEnabled(lua_State* L){
   COL_FUNCTION(LUAtraceEnabled);
   lua_pushstring(L, LUA_TRACE_ENABLED);
   lua_rawget(L, LUA_REGISTRYINDEX);
   COL_TRC("About to fetch string");
   COLstring File = COLstringL(L, -1);
   lua_pop(L, 1);
   COL_VAR(File);
   return File;
}
