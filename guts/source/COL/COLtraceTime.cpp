//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Wednesday 12th August 2026
//       0x6A7CF2DF seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "COLtraceTime.h"
#include "COLtimestamp.h"
#include "COLcurrentTime.h"
#include "COLcurrentTime.h"
#include "COLthreadId.h"
#include "COLwriteIndent.h"
#include "COLcallIncrease.h" // ICK for static variable
#include "COLsink.h" // ICK for static variable
#include "COLtrace.h"

#include "stdio.h"

static char   s_COLtimeBuffer[64];
static time_t s_COLlastTimeStamp=0;

void COLtraceTime(const char* pModule, COLstream& Stream){
   COLtimestamp Time = COLcurrentTime();
   if (s_COLlastTimeStamp != Time.Seconds){  //Calculating the Julian date from unix epoch is CPU intensive, so only do it when you need to.
      s_COLlastTimeStamp = Time.Seconds;
      struct tm* tm = localtime(&s_COLlastTimeStamp);
      strftime(s_COLtimeBuffer, sizeof(s_COLtimeBuffer), "  %H:%M:%S", tm); 
   }
   COLtraceOut << s_COLtimeBuffer;
   char Buffer[50];
   int Count = snprintf(Buffer, sizeof(Buffer), ".%06lli ", Time.Microseconds);  // pad milliseconds and thread id.
   Stream.sink()->write(Buffer, Count);
   Count = snprintf(Buffer, sizeof(Buffer), "%-9llu ", COLthreadId());
   Stream.sink()->write(Buffer, Count);
   Count = snprintf(Buffer, sizeof(Buffer), "%-25s ", pModule); 
   Stream.sink()->write(Buffer, Count);
   COLwriteIndent(Stream.sink(), s_COLindentLevel);
}
