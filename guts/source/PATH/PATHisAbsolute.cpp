//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Wednesday 12th August 2026
//       0x6A7CB91C seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "PATHisAbsolute.h"
#include "COLtrace.h"
COL_TRACE_INIT;

bool PATHisAbsolute(const COLstring& Path){
   COL_FUNCTION(PATHisAbsolute);
   return Path.size() && Path[0] == '/';
}
