//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Thursday 30th July 2026
//       0x6A6B7A0D seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "OSisMac.h"
#include "COLtrace.h"
COL_TRACE_INIT;

#ifdef _COSMO_SOURCE
#include "libc/dce.h"

bool OSisMac(){
   COL_FUNCTION(OSisMac);
   return IsXnu();  // WTF Justine - clearly not a English Major
}
#else
bool OSisMac(){
   COL_FUNCTION(OSisMac);
   return true;  // Assuming we are doing memcheck build.
}
#endif
