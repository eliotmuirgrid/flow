//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Friday 14th August 2026
//       0x6A7F1464 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "JSONvar.h"
#include "COLtrace.h"
#include "LUAlua.h"  // for LUA_TNIL
COL_TRACE_INIT;

JSONvar::JSONvar() : Type(LUA_TNIL), Boolean(false), Number(0) {
   COL_METHOD(JSONvar::JSONvar);
}

JSONvar::~JSONvar(){
   COL_METHOD(JSONvar::~JSONvar);
}

COLstream& operator<<(COLstream& Stream, const JSONvar& Var){
   COL_FUNCTION(operator<<);
   switch(Var.Type){
      case LUA_TNIL:     Stream << "null";                           break;
      case LUA_TBOOLEAN: Stream << (Var.Boolean ? "true" : "false"); break;
      case LUA_TNUMBER:  Stream << Var.Number;                       break;
      case LUA_TSTRING:  Stream << '"' << Var.String << '"';         break;
      case LUA_TTABLE:{
         Stream << "{";
         bool First = true;
         for (int i=0; i<Var.Array.size(); i++){
            if (!First) Stream << ", ";
            Stream << Var.Array[i];
            First = false;
         }
         for (auto i=Var.Dict.cbegin(); i != Var.Dict.cend(); ++i){
            if (!First) Stream << ", ";
            Stream << '"' << i.key() << "\": " << i.value();
            First = false;
         }
         Stream << "}";
         break;
      }
      default:
         Stream << "<unknown JSONvar type " << Var.Type << ">";
   }
   return Stream;
}
