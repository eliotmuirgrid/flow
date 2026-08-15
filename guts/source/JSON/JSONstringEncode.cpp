//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Thursday 13th August 2026
//       0x6A7E4AE9 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "JSONstringEncode.h"
#include "JSONescapeCharacter.h"
#include "COLtrace.h"
COL_TRACE_INIT;

COLstring JSONstringEncode(const COLstring& String){
   COL_FUNCTION(JSONstringEncode);
   COLstring Result;
   Result += '"';
   for (char Character : String){
      JSONescapeCharacter(&Result, Character);
   }
   Result += '"';
   return Result;
}
