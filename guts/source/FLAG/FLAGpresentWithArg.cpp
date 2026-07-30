//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Thursday 30th July 2026
//       0x6A6B6474 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include <FLAG/FLAGpresentWithArg.h>
#include <COL/COLarray.h>
#include <COL/COLtrace.h>
COL_TRACE_INIT;

bool FLAGpresentWithArg(const COLstring& Name, COLstring* pValue, COLarray<COLstring>* pArgs){
   COL_FUNCTION(FLAGpresentWithArg);
   COLarray<COLstring>& Args = *pArgs;
   COL_VAR2(Name, Args);
   COLstring Search = "--" + Name;
   for (int i=1; i < Args.size()-1; i++){
      if (Search == Args[i]){
         *pValue = Args[i+1];
	 Args.remove(i);
	 Args.remove(i);
	 return true;
      }
   }
   return false;
}

