//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Tuesday 11th August 2026
//       0x6A7BE01F seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "STACKstringArray.h"
#include "STACKsize.h"
#include "STACKfetch.h"
#include "LUAlua.h"
#include "COLstringL.h"
#include "COLtrace.h"
COL_TRACE_INIT;

COLstring STACKstringArray(lua_State* L, int i){
   COL_FUNCTION(STACKstringArray);
   COLstring Result = "[";
   int Size = STACKsize(L, i);
   COL_VAR(Size);
   for (int j=1; j<=Size; j++){
      COL_VAR2(i,j);
      STACKfetch(L, i, j);
      if (j > 1) Result += ", ";
      Result += "\"" + COLstringL(L, -1) + "\"";
      COL_VAR3(j, Result, lua_type(L, -1));
      lua_pop(L, 1);
   }
   Result += "]";
   return Result;
}
