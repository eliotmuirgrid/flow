//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Tuesday 28th July 2026
//       0x6A68F1B6 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include <DIR/DIRicreate.h>
#include <LUA/LUAlua.h>
#include <COL/COLstringL.h>
#include <COL/COLtrace.h>
COL_TRACE_INIT;

int DIRcreate(lua_State* L){
   COL_FUNCTION(DIRcreate);
   COLstring Name = COLstringL(L, -1);
   COL_VAR(Name);
   bool Result = DIRicreate(Name);  // TODO worry about error checking later
   if (!Result) {
      return luaL_error(L, "BANG DIRcreate failed. Time you fixed me"); 
   }
   return 0;
}
