//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Monday 10th August 2026
//       0x6A7A9553 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "HOOKfilterC.h"
#include "COLtrace.h"
COL_TRACE_INIT;

bool HOOKfilterC(const COLstring& Source){
   COL_FUNCTION(HOOKfilterC);
   COL_VAR(Source);
   if (Source.data()[0] == '[') {
      COL_TRC("In C Function");
      return true;
   }
   return false;
}
