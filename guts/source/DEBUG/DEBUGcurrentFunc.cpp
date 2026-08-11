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
#include "REGtableGet.h"
#include "LUAabsoluteIndex.h"
#include "STACKtop.h"
#include "COLstringL.h"
#include "COLtrace.h"
COL_TRACE_INIT;

COLstring DEBUGcurrentFunc(lua_State* L){
   COL_FUNCTION(DEBUGcurrentFunc);
   REGtableGet(L, "DEBUGstack");
   if (lua_isnil(L, -1)){
      lua_pop(L, 1);
      COL_TRC("WARNING didn't get the DEBUGstack.");
      return "";
   }
   int t = LUAabsoluteIndex(L, -1);
   COLstring Result;
   STACKtop(L,t);
   Result = COLstringL(L, -1);
   lua_pop(L,-1);

   COL_VAR(Result);
   return Result;
}
