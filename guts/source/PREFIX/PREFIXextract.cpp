//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Monday 10th August 2026
//       0x6A7A0428 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "PREFIXextract.h"
#include "ALPHAisCapital.h"
#include "COLtrace.h"
COL_TRACE_INIT;

COLstring PREFIXextract(const COLstring& String){
   COL_FUNCTION(PREFIXextract);
   int i = 0;
   while (i < String.size() && ALPHAisCapital(String[i])){ ++i; }
   COLstring Prefix = String.substr(0, i);
   COL_VAR(Prefix);
   return Prefix;
}
