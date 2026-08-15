//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Thursday 13th August 2026
//       0x6A7DC22E seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "FILopenWrite.h"
#include <fcntl.h>
#include "COLtrace.h"
COL_TRACE_INIT;

int FILopenWrite(const COLstring& Path){
   COL_FUNCTION(FILopenWrite)
   COL_VAR(Path);
   return open(Path.data(), O_WRONLY | O_CREAT | O_TRUNC, 0644);
}
