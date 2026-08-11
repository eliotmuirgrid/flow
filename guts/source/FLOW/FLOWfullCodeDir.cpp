//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Monday 10th August 2026
//       0x6A7A2063 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "FLOWfullCodeDir.h"
#include "FLOWcodeDir.h"
#include "FLOWbinDirGet.h"
#include "LUAlua.h"
#include "COLtrace.h"
COL_TRACE_INIT;

COLstring FLOWfullCodeDir(lua_State* L){
   COL_FUNCTION(FLOWfullCodeDir);
   return FLOWbinDirGet(L) + FLOWcodeDir();
}
