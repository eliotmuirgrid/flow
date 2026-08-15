//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Tuesday 11th August 2026
//       0x6A7BE10C seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "DEBUGstackDump.h"
#include "LUAlua.h"
#include "LUAstackCheck.h"
#include "REGtableGet.h"
#include "STACKstringArray.h"
#include "COLtrace.h"
COL_TRACE_INIT;

COLstring DEBUGstackDump(lua_State* L){
   COL_FUNCTION(DEBUGstackDump);
   LUAstackCheck Check(L, 0);
   REGtableGet(L, "DEBUGstack");
   COLstring Result = STACKstringArray(L,-1);
   lua_pop(L, 1);
   return Result;
}
