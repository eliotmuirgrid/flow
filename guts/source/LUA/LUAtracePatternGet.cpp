//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Wednesday 29th July 2026
//       0x6A6A9270 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include <LUA/LUAlua.h>
#include <COL/COLtrace.h>
#include <REG/REGkeyGet.h>
COL_TRACE_INIT;

COLstring LUAtracePatternGet(lua_State* L){
   COL_FUNCTION(LUAtracePatternGet);
   return REGkeyGet(L, "LUAtracePattern");  // TODO would a static string be better
}
