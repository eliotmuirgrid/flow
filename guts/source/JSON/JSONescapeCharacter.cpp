//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Thursday 13th August 2026
//       0x6A7E4C79 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "JSONescapeCharacter.h"
#include "COLtrace.h"
COL_TRACE_INIT;

void JSONescapeCharacter(COLstring* pOutput, char Character){
   COL_FUNCTION(JSONescapeCharacter);
   COLstring& Output = *pOutput;

   switch (Character){
      case '"':  Output += "\\\""; return;
      case '\\': Output += "\\\\"; return;
      case '\b': Output += "\\b";  return;
      case '\f': Output += "\\f";  return;
      case '\n': Output += "\\n";  return;
      case '\r': Output += "\\r";  return;
      case '\t': Output += "\\t";  return;
   }
   unsigned char Value = static_cast<unsigned char>(Character);
   if (Value < 0x20){
      static const char Hex[] = "0123456789abcdef";
      Output += "\\u00";
      Output += Hex[(Value >> 4) & 0x0f];
      Output += Hex[Value & 0x0f];
      return;
   }
   Output += Character;
}
