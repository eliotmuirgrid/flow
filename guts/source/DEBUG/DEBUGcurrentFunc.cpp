//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Sunday 9th August 2026
//       0x6A78FAB1 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "DEBUGcurrentFunc.h"
#include "LUAlua.h"
#include "COLtrace.h"
COL_TRACE_INIT;

COLstring DEBUGcurrentFunc(lua_State* L){
   COL_FUNCTION(DEBUGcurrentFunc);
   lua_Debug D;
   if (!lua_getstack(L, 2, &D)) {
      return "";
   }
   if (!lua_getinfo(L, "n", &D)) {
      return "";
   }
   COLstring Result = D.name ? D.name : "";
   COL_VAR(Result);
   return Result;
}
