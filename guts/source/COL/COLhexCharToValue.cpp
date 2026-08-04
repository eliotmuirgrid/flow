//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Sunday 2nd August 2026
//       0x6A7010C0 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "COLhexCharToValue.h"
#include "COLtrace.h"
COL_TRACE_INIT;

// Converts a single hexadecimal character to its decimal value
bool COLhexCharToValue(char c, unsigned int& value) {
   COL_VAR(c);
   if (c >= '0' && c <= '9') { value = c - '0'; } else 
   if (c >= 'A' && c <= 'F') { value = 10 + (c - 'A'); } else 
   if (c >= 'a' && c <= 'f') { value = 10 + (c - 'a'); } else {
     return false; // Non-hexadecimal character
   }
   COL_VAR(value);
   return true;
}