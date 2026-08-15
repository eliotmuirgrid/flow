//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Wednesday 12th August 2026
//       0x6A7CC322 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "COLreplaceChar.h"
#include "COLtrace.h"
COL_TRACE_INIT;

COLstring COLreplaceChar(const COLstring& Input, char From, char To){
   COL_FUNCTION(COLreplaceChar);
   COLstring Out = Input;
   int Size = Out.size();
   COL_VAR2(Out, Size);
   for (int i=0; i < Size; ++i){
      if (Out[i] == From) { Out[i] = To; }
   }
   COL_VAR(Out);
   return Out;
}
