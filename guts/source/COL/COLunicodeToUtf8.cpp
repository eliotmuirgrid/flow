//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Sunday 2nd August 2026
//       0x6A70110B seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "COLunicodeToUtf8.h"
#include "COLtrace.h"
COL_TRACE_INIT;

// Converts a Unicode code point to a UTF-8 encoded string
bool COLunicodeToUtf8(unsigned int codepoint, COLstring& output) {
   if (codepoint < 0x80) { 
      output += static_cast<char>(codepoint); } else 
   if (codepoint < 0x800) {
      output += static_cast<char>(192 + (codepoint / 64)); 
      output += static_cast<char>(128 + (codepoint % 64)); } else 
   if (codepoint < 0x10000) {
      output += static_cast<char>(224 + (codepoint / 4096));
      output += static_cast<char>(128 + ((codepoint / 64) % 64));
      output += static_cast<char>(128 + (codepoint % 64));} else 
   if (codepoint < 0x110000) {
      output += static_cast<char>(240 +  (codepoint / 262144));
      output += static_cast<char>(128 + ((codepoint / 4096) % 64));
      output += static_cast<char>(128 + ((codepoint / 64) % 64));
      output += static_cast<char>(128 + (codepoint % 64));
   }
   return true;
}