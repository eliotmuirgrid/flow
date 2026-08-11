//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Sunday 9th August 2026
//       0x6A790EA3 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "DEBUGstackPush.h"
#include "DEBUGcurrentFunc.h"
#include "LUAlua.h"
#include "LUAabsoluteIndex.h"
#include "STACKpushString.h"
#include "STACKsize.h"
#include "REGtableGet.h"
#include "COLerror.h"
#include "COLtrace.h"
COL_TRACE_INIT;

void DEBUGstackPush(lua_State* L, const COLstring& Func){
   COL_FUNCTION(DEBUGstackPush);
   COL_VAR(Func);
   REGtableGet(L, "DEBUGstack");
   if (lua_isnil(L, -1)){
      lua_pop(L, 1);
      COL_TRC("WARNING didn't get the DEBUGstack.");
      return;
   }
   int t = LUAabsoluteIndex(L, -1);
   COLASSERT(lua_istable(L, t));
   STACKpushString(L, t, Func);
   COLASSERT(lua_istable(L, t));
   COL_VAR(STACKsize(L, t));
   lua_pop(L, 1);
   COL_VAR(DEBUGcurrentFunc(L));
}
