//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Monday 10th August 2026
//       0x6A7A1E39 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "FLOWbinDirGet.h"
#include "LUAlua.h"
#include "REGkeyGet.h"
#include "COLtrace.h"
COL_TRACE_INIT;

COLstring FLOWbinDirGet(lua_State* L){
   COL_FUNCTION(FLOWbinDirGet);
   return REGkeyGet(L, "FLOWroot");
}
