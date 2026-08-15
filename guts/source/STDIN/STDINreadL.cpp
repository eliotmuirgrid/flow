//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Saturday 15th August 2026
//       0x6A80C0EB seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "STDINreadL.h"
#include "STDINread.h"
#include "LUAlua.h"
#include "COLstringPushL.h"
#include "COLtrace.h"
COL_TRACE_INIT;

int STDINreadL(lua_State* L){
   COL_FUNCTION(STDINreadL);
   COLstring Input = STDINread();
   COLstringPushL(L, Input); 
   return 1;
}
