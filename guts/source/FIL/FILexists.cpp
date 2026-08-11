//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Monday 10th August 2026
//       0x6A79CC91 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "FILexists.h"
#include "COLtrace.h"
#include "sys/stat.h"
COL_TRACE_INIT;

bool FILexists(const COLstring& File){
   COL_FUNCTION(FILexists);
   struct stat Stat;
   bool Exists = !stat(File.data(), &Stat);
   COL_VAR(Exists);
   return Exists;
}


