//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Tuesday 28th July 2026
//       0x6A68F8AA seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include <LUA/LUAlua.h>
#include <LUA/LUAtraceEnable.h>
#include <COL/COLtrace.h>
COL_TRACE_INIT;

void LUAtraceEnable(lua_State* L, const COLstring& File){
   COL_FUNCTION(LUAtraceEnable);
   lua_pushstring(L, LUA_TRACE_ENABLED);  // key
   lua_pushstring(L, File.data());        // value
   lua_rawset(L, LUA_REGISTRYINDEX);
   COL_VAR(File);
}
