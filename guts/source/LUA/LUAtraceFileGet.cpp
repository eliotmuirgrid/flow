//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Tuesday 28th July 2026
//       0x6A68FA30 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include <REG/REGkeyGet.h>
#include <COL/COLtrace.h>
COL_TRACE_INIT;

COLstring LUAtraceFileGet(lua_State* L){
   COL_FUNCTION(LUAtraceEnabled);
   return REGkeyGet(L, "LUAtraceFile");
}
