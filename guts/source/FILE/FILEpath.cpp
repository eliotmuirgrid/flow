//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Sunday 2nd August 2026
//       0x6A6F4C87 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "FILEpath.h"
#include "LUAlua.h"
#include "FILpathName.h"
#include "COLstringL.h"
#include "COLstringPushL.h"
#include "COLtrace.h"
COL_TRACE_INIT;

int FILEpath(lua_State* L){
   COL_FUNCTION(FILEpath);
   COLstring Path = COLstringL(L, -1);
   COLstring Result = FILpathName(Path);
   COLstringPushL(L, Result);
   return 1;
}
