//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Tuesday 28th July 2026
//       0x6A68F264 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "libc/calls/calls.h"
#include "libc/errno.h"
#include "libc/stdio/stdio.h"
#include "libc/sysv/consts/s.h"

#include "COLtrace.h"
COL_TRACE_INIT;

bool DIRicreate(const COLstring& Path){
   COL_FUNCTION(DIRicreate);
   if (mkdir(Path.data(), 0755) == 0) {
      return true;
   }

   if (errno == EEXIST) {
      return true;
   }
   // TODO get fancy about error checking later
   //perror(Path);
   return false;
}