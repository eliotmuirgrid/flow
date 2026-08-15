//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Wednesday 12th August 2026
//       0x6A7CBDB3 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "COLsplitStringToArray.h"
#include "COLarray.h"
#include "COLstring.h"
#include "COLtrace.h"
COL_TRACE_INIT;

void COLsplitStringToArray(const COLstring& String, char Delimiter, COLarray<COLstring>* pResult){
   COL_FUNCTION(COLsplitStringToArray);
   COLarray<COLstring>& Result = *pResult;
   int Start = 0;
   for (int i = 0; i <= String.size(); ++i) {
      if (i == String.size() || String[i] == Delimiter) {
         Result.push(COLstring(String.data() + Start, i - Start));
         Start = i + 1;
      }
   }
}
