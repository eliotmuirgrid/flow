//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Tuesday 11th August 2026
//       0x6A7B1BC5 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "COLassert.h"

#include <stdlib.h>

#include "COLtrace.h"
COL_TRACE_INIT;

void COLassert(const char* expr, const char* file, int line, const char* func){
   COLout << "Assertion: " << expr << " in " << file << ":" << line << " in " << func;
   abort();
}
