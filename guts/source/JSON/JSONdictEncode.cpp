//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Saturday 15th August 2026
//       0x6A807E68 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "JSONdictEncode.h"
#include "JSONvar.h"
#include "JSONvarEncode.h"
#include "JSONstringEncode.h"
#include "COLtrace.h"
COL_TRACE_INIT;

#include <stdio.h>

void JSONdictEncode(const JSONvar& Var, COLstring* pOut){
   COL_FUNCTION(JSONdictEncode);
   COLstring& Out = *pOut;
   Out += '{';
   bool Comma = false;
   for (int i=0; i < Var.Array.size(); i++){
      if (Comma) Out += ',';
      char Key[32];
      snprintf(Key, sizeof(Key), "%d", i+1);
      Out += JSONstringEncode(Key);
      Out += ':';
      JSONvarEncode(Var.Array[i], &Out);
      Comma = true;
   }

   for (auto i = Var.Dict.cbegin(); i != Var.Dict.cend(); ++i){
      if (Comma) Out += ',';
      Out += JSONstringEncode(i.key());
      Out += ':';
      JSONvarEncode(i.value(), &Out);
      Comma = true;
   }
   Out += '}';
}
