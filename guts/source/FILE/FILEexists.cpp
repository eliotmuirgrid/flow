//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Tuesday 28th July 2026
//       0x6A68EB84 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------
#include "sys/stat.h"
#include "LUAlua.h"
#include "COLtrace.h"
COL_TRACE_INIT;

int FILEexists(lua_State* L){
   COL_FUNCTION(FILEexists);
   // Check you have a string argument on the Lua stack
   const char* path = luaL_checkstring(L, 1);
   // Cosmopolitan stat() to check for file existence
   struct stat st;
   int exists = 0;
   if (!stat(path, &st)) {  // stat returns 0 on success
      exists = 1;
   }
   lua_pushboolean(L, exists);
   return 1; // Number of returned Lua values
}