//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Monday 10th August 2026
//       0x6A7A22AD seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "FLOWfileLua.h"
#include "FLOWfile.h"
#include "COLtrace.h"
COL_TRACE_INIT;

COLstring FLOWfileLua(const COLstring& FName){
   COL_FUNCTION(FLOWfileLua);
   return FLOWfile(FName, "lua");
}
