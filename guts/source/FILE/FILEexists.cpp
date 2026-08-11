//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Tuesday 28th July 2026
//       0x6A68EB84 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------
#include "FILexists.h"
#include "LUAlua.h"
#include "COLstringL.h"
#include "COLtrace.h"
COL_TRACE_INIT;

int FILEexists(lua_State* L){
   COL_FUNCTION(FILEexists);
   COLstring Path = COLstringL(L,-1);
   lua_pushboolean(L,FILexists(Path));
   return 1; // Number of returned Lua values
}