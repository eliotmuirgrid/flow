//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Thursday 30th July 2026
//       0x6A6B775F seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "unistd.h"
#include "LUAlua.h"
#include "COLstringL.h"
#include "COLtrace.h"
COL_TRACE_INIT;

int DIRdelete(lua_State* L){
   COL_FUNCTION(DIRdelete);
   COLstring Path = COLstringL(L, -1); 
   bool Result = rmdir(Path.data()) == 0;
   lua_pushboolean(L, Result);
   return 1;
}