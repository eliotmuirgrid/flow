//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Saturday 15th August 2026
//       0x6A807A45 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "JSONvarEncode.h"
#include "JSONarrayEncode.h"
#include "JSONdictEncode.h"
#include "JSONnumberEncode.h"
#include "JSONstringEncode.h"
#include "JSONvar.h"
#include "LUAlua.h"
#include "COLtrace.h"
COL_TRACE_INIT;

void JSONvarEncode(const JSONvar& Var, COLstring* pString){
   COL_FUNCTION(JSONvarEncode);
   COLstring& Out = *pString;

   switch (Var.Type){
      case LUA_TNIL:     Out += "null";                          break;
      case LUA_TBOOLEAN: Out += Var.Boolean ? "true" : "false";  break;
      case LUA_TSTRING:  Out += JSONstringEncode(Var.String);    break;
      case LUA_TNUMBER:  Out += JSONnumberEncode(Var.Number);    break;
      case LUA_TTABLE:   if (Var.Dict.size() == 0) {
                            JSONarrayEncode(Var, pString); 
                         } else {
                            JSONdictEncode(Var, pString);      
                         }
   }
}
