//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Wednesday 12th August 2026
//       0x6A7CB453 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "CRASHenable.h"
#include "COLtrace.h"
COL_TRACE_INIT;

#ifdef _COSMO_SOURCE
   #include "libc/runtime/runtime.h"
#endif

void CRASHenable(){
   COL_FUNCTION(CRASHenable);
#ifdef _COSMO_SOURCE
   ShowCrashReports();
#endif
}
