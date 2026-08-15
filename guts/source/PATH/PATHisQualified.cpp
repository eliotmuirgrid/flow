//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Wednesday 12th August 2026
//       0x6A7CBCA5 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "PATHisQualified.h"
#include "COLtrace.h"
COL_TRACE_INIT;

bool PATHisQualified(const COLstring& Path){
   COL_FUNCTION(PATHisQualified);
   return Path.find("/");
}
