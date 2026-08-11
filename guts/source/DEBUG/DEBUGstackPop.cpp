//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Sunday 9th August 2026
//       0x6A790FE6 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "DEBUGstackPop.h"
#include "DEBUGcurrentFunc.h"
#include "LUAlua.h"
#include "LUAabsoluteIndex.h"
#include "STACKpop.h"
#include "STACKsize.h"
#include "REGtableGet.h"
#include "COLtrace.h"
COL_TRACE_INIT;

void DEBUGstackPop(lua_State* L){
   COL_FUNCTION(DEBUGstackPop);
   REGtableGet(L, "DEBUGstack");
   if (lua_isnil(L, -1)){
      lua_pop(L, 1);
      COL_TRC("WARNING didn't get the DEBUGstack.");
      return;
   }
   int t = LUAabsoluteIndex(L, -1);
   COL_VAR(t);
   STACKpop(L, t);
   COL_VAR(STACKsize(L, t));
   lua_pop(L, 1);
   COL_VAR(DEBUGcurrentFunc(L));
}
