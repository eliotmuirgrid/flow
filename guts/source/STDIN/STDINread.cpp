//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Saturday 15th August 2026
//       0x6A80C091 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "STDINread.h"
#include "COLtrace.h"
COL_TRACE_INIT;

#include <unistd.h>

COLstring STDINread(){
   COL_FUNCTION(STDINread);
   COLstring Output;
   char Buffer[4096];
   for (;;){
      ssize_t Count = read(STDIN_FILENO, Buffer, sizeof(Buffer));
      COL_VAR(Count);
      if (Count == 0) break;
      if (Count < 0) break;  // handle EINTR/error properly if desired
      Output.append(Buffer, Count);
   }
   return Output;
}
