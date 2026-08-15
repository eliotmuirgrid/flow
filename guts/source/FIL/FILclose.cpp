//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Thursday 13th August 2026
//       0x6A7DC3C8 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "FILclose.h"
#include "unistd.h"
#include "COLtrace.h"
COL_TRACE_INIT;

void FILclose(int Handle){
   COL_FUNCTION(FILclose);
   COL_VAR(Handle);
   close(Handle);
}
