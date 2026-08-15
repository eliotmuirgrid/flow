//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Wednesday 12th August 2026
//       0x6A7CC243 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "PATHsystem.h"
#include "COLreplaceChar.h"
#include "COLtrace.h"
COL_TRACE_INIT;

#include <stdlib.h>

COLstring PATHsystem(){
   COL_FUNCTION(PATHsystem);
   const char* pPath = getenv("PATH");
   COLstring Path = pPath ? pPath : "";    
   COL_VAR(Path);
   Path = COLreplaceChar(Path, ';', ':');
   return Path;
}
