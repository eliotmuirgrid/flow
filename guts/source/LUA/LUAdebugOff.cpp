//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Tuesday 11th August 2026
//       0x6A7BB16D seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "LUAdebugOff.h"
#include "LUAltraceOff.h"
#include "LUAlua.h"
#include "COLtrace.h"
COL_TRACE_INIT;

void LUAdebugOff(lua_State* L){
   COL_FUNCTION(LUAdebugOff);
   lua_register(L, "LUAltrace", LUAltraceOff);
}
