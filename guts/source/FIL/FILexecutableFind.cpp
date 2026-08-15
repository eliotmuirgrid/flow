//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Wednesday 12th August 2026
//       0x6A7CBF8F seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "PATHisQualified.h"
#include "FILexecutableFind.h"
#include "FILexists.h"
#include "PATHsystem.h"
#include "COLsplitStringToArray.h"
#include "COLarray.h"
#include "COLtrace.h"
COL_TRACE_INIT;

COLstring FILexecutableFind(const COLstring& ExeName){
   COL_FUNCTION(FILexecutableFind);
   if (PATHisQualified(ExeName)) {
      return FILexists(ExeName) ? ExeName : "";
   }
   COLarray<COLstring> Paths;
   COLsplitStringToArray(PATHsystem(), ':', &Paths);
   for (int i = 0; i < Paths.size(); ++i) {
      const COLstring& Path = Paths[i];
      COLstring Candidate = Path + "/" + ExeName;
      COL_VAR(Candidate);
      if (FILexists(Candidate)) {
         COL_TRC("Found candidate");
         return Candidate;
      }
   }
   COL_TRC("No candidate found.");
   return "";
}
