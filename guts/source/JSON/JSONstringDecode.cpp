//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Saturday 15th August 2026
//       0x6A809989 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "JSONstringDecode.h"
#include "COLtrace.h"
COL_TRACE_INIT;

void JSONstringDecode(const COLstring& Input, COLstring* pOutput){
   COL_FUNCTION(JSONstringDecode);
   const char* p = Input.data() + 1;
   const char* pEnd = Input.data() + Input.size() - 1;
   while (p < pEnd){
      if (*p != '\\'){
         *pOutput += *p++;
         continue;
      }
      p++;
      switch (*p++){
         case '"':  *pOutput += '"';  break;
         case '\\': *pOutput += '\\'; break;
         case '/':  *pOutput += '/';  break;
         case 'b':  *pOutput += '\b'; break;
         case 'f':  *pOutput += '\f'; break;
         case 'n':  *pOutput += '\n'; break;
         case 'r':  *pOutput += '\r'; break;
         case 't':  *pOutput += '\t'; break;
         case 'u': {
            unsigned Code = 0;
            for (int i=0; i<4; i++){
               char C = *p++;
               Code <<= 4;
               if      (C >= '0' && C <= '9') Code += C - '0';
               else if (C >= 'A' && C <= 'F') Code += C - 'A' + 10;
               else if (C >= 'a' && C <= 'f') Code += C - 'a' + 10;
            }
            if (Code >= 0xD800 && Code <= 0xDBFF){
               p += 2;
               unsigned Low = 0;
               for (int i=0; i<4; i++){
                  char C = *p++;
                  Low <<= 4;
                  if      (C >= '0' && C <= '9') Low += C - '0';
                  else if (C >= 'A' && C <= 'F') Low += C - 'A' + 10;
                  else if (C >= 'a' && C <= 'f') Low += C - 'a' + 10;
               }
               Code = 0x10000 + ((Code - 0xD800) << 10) + (Low - 0xDC00);
            }
            char Utf8[4];
            int Size;
            if (Code <= 0x7F){
               Utf8[0] = Code;
               Size = 1;
            } else if (Code <= 0x7FF){
               Utf8[0] = 0xC0 | (Code >> 6);
               Utf8[1] = 0x80 | (Code & 0x3F);
               Size = 2;
            } else if (Code <= 0xFFFF){
               Utf8[0] = 0xE0 | (Code >> 12);
               Utf8[1] = 0x80 | ((Code >> 6) & 0x3F);
               Utf8[2] = 0x80 | (Code & 0x3F);
               Size = 3;
            } else {
               Utf8[0] = 0xF0 | (Code >> 18);
               Utf8[1] = 0x80 | ((Code >> 12) & 0x3F);
               Utf8[2] = 0x80 | ((Code >> 6) & 0x3F);
               Utf8[3] = 0x80 | (Code & 0x3F);
               Size = 4;
            }
            pOutput->append(Utf8, Size);
            break;
         }
      }
   }
}
