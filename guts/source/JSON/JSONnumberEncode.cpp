//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Saturday 15th August 2026
//       0x6A807C00 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "JSONnumberEncode.h"
#include "math.h"
#include "COLtrace.h"
COL_TRACE_INIT;

#include <stdio.h>

COLstring JSONnumberEncode(double Num){
   COL_FUNCTION(JSONnumberEncode);
   char Buffer[32];
   if (floor(Num) == Num)
      snprintf(Buffer, sizeof(Buffer), "%.0f", Num);
   else
      snprintf(Buffer, sizeof(Buffer), "%.17g", Num);
   return Buffer;
}
