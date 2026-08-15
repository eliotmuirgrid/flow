//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Wednesday 12th August 2026
//       0x6A7CF628 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "COLcurrentTime.h"
#include "COLtimestamp.h"

COLtimestamp COLcurrentTime(){
   struct timespec Time;
   clock_gettime(CLOCK_REALTIME, &Time);

   COLtimestamp Timestamp;
   Timestamp.Seconds      = Time.tv_sec;
   Timestamp.Microseconds = Time.tv_nsec / 1000;
   return Timestamp;
}
