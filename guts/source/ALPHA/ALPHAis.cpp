//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Monday 10th August 2026
//       0x6A79ED71 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "ALPHAis.h"
#include "COLtrace.h"
COL_TRACE_INIT;

bool ALPHAis(char Character){
   return (Character >= 'A' && Character <= 'Z') ||
          (Character >= 'a' && Character <= 'z');
}
