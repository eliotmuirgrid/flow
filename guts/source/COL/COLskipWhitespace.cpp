//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Sunday 2nd August 2026
//       0x6A700DD1 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "COLskipWhitespace.h"
#include "COLtrace.h"
COL_TRACE_INIT;

// Utility function to skip whitespace in the JSON input
void COLskipWhitespace(const char*& i) {
    while (*i == ' ' || *i == '\n' || *i == '\r' || *i == '\t') { ++i;}
}