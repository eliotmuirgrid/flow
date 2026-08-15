//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Wednesday 12th August 2026
//       0x6A7CB71F seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "DIRworking.h"
#include "COLnull.h"
#include "COLtrace.h"
COL_TRACE_INIT;

#include "unistd.h"
#include "stdlib.h"

COLstring DIRworking(){
   COL_FUNCTION(DIRworking);
   char* Path = getcwd(COLnull, 0);
   COLstring Result = Path;
   free(Path);
   return Result;
}
