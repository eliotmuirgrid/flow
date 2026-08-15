//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Saturday 15th August 2026
//       0x6A807E61 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "JSONarrayEncode.h"
#include "JSONvar.h"
#include "JSONvarEncode.h"
#include "COLtrace.h"
COL_TRACE_INIT;

void JSONarrayEncode(const JSONvar& Var, COLstring* pOut){
   COL_FUNCTION(JSONarrayEncode);
   COLstring& Out = *pOut;
   Out += '[';
   for (int i=0; i < Var.Array.size(); i++){
      if (i) Out += ',';
      JSONvarEncode(Var.Array[i], &Out);
   }
   Out += ']';
}
