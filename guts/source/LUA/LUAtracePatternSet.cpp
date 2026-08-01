//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Wednesday 29th July 2026
//       0x6A6A9269 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "LUAlua.h"
#include "REGkeySet.h"
#include "COLtrace.h"
COL_TRACE_INIT;

void LUAtracePatternSet(lua_State* L, const COLstring& Pattern){
   COL_FUNCTION(LUAtracePatternSet);
   REGkeySet(L, "LUAtracePattern", Pattern);  // micro optimization possible
   COL_VAR(Pattern);
}