//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Monday 10th August 2026
//       0x6A7A9628 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "HOOKfilterTail.h"
#include "COLtrace.h"
COL_TRACE_INIT;

bool HOOKfilterTail(const COLstring& Source){
   COL_FUNCTION(HOOKfilterTail);
   COL_VAR(Source);
   if (Source.data()[0] == '(') {
      COL_TRC("In Tail Function");
      return true;
   }
   return false;
}
