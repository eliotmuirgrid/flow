//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Thursday 13th August 2026
//       0x6A7DC778 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "COLtraceModule.h"
#include "COLtrace.h"

#include "string.h"

COLtraceModule::COLtraceModule(const char* pFileName){
   const char* pName = strrchr(pFileName, '/');
   pName = pName ? pName + 1 : pFileName;

   strncpy(N, pName, sizeof(N) - 1);
   N[sizeof(N) - 1] = '\0';
}



