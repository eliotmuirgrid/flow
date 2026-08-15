//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Thursday 30th July 2026
//       0x6A6B7A8F seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "OSisWindows.h"
#include "COLtrace.h"
COL_TRACE_INIT;

#ifdef _COSMO_SOURCE
#include "libc/dce.h"

bool OSisWindows(){
   COL_FUNCTION(OSisWindows);
   return IsWindows();
}
#else
bool OSisWindows(){
   COL_FUNCTION(OSisWindows);
   return false;
}
#endif
