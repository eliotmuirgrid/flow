//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Thursday 30th July 2026
//       0x6A6B607C seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include <FLAG/FLAGpresent.h>
#include <COL/COLarray.h>
#include <COL/COLtrace.h>
COL_TRACE_INIT;

bool FLAGpresent(const COLstring& Name,  COLarray<COLstring>* pArgs){
   COL_FUNCTION(FLAGpresent);
   COLarray<COLstring>& Args = *pArgs;
   COL_VAR2(Name, Args);
   COLstring Search = "--" + Name;
   for (int i=1; i < Args.size(); i++){
      if (Search == Args[i]){
         Args.remove(i);
	      return true;
      }
   }
   return false;
}


