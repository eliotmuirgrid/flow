//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Monday 10th August 2026
//       0x6A7A9359 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "HOOKfilterTrace.h"
#include "COLtrace.h"
COL_TRACE_INIT;

bool HOOKfilterTrace(const COLstring& Source){
   COL_FUNCTION(HOOKfilterTrace);
   if (Source.find("COLshow")) { COL_TRC("Matched COLshow") ; return true; }
   if (Source.find("COLtrace")){ COL_TRC("Matched COLtrace"); return true; }
   return false;
}
