//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Sunday 2nd August 2026
//       0x6A6FB472 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "COLintToString.h"
#include "COLstring.h"
#include "COLtrace.h"
COL_TRACE_INIT;

#include <stdio.h>

COLstring COLintToString(int V){
   COL_FUNCTION(COLintToString);
   char Result[32]; // Room for a 64-bit int.
   snprintf(Result, 32, "%d", V);
   return Result;
}
