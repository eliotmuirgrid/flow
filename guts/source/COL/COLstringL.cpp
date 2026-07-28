//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Tuesday 28th July 2026
//       0x6A690934 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include <LUA/LUAlua.h>
#include <COL/COLtrace.h>
COL_TRACE_INIT;

COLstring COLstringL(lua_State* L, int i){
   COL_FUNCTION(COLstringL);
   const char* S = lua_tostring(L, i);
   if (NULL == S) { return COLstring(); }
   size_t Len = lua_strlen(L, i);
   return  COLstring(S, Len);
}
