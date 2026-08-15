//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Thursday 13th August 2026
//       0x6A7DCA97 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "COLtraceEnabled.h"
#include "COLglobMatch.h"
#include "COLtrace.h"

bool COLtraceEnabled(const char* Name, int* pResult){
   if (COLglobMatch(Name, COLtracePattern)){ *pResult =  1; return true;  }
   else                                    { *pResult = -1; return false; }
}

