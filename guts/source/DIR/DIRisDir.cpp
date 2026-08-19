//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Thursday 13th August 2026
//       0x6A7E1F37 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "DIRisDir.h"
#include "LUAlua.h"
#include "COLtrace.h"
COL_TRACE_INIT;

#include <sys/stat.h>

int DIRisDir(lua_State* L){
   COL_FUNCTION(DIRisDir);
   const char* Path = luaL_checkstring(L, 1);
   struct stat Info;
   if (stat(Path, &Info) != 0) {
      lua_pushboolean(L, 0);
      return 1;
   }
   lua_pushboolean(L, S_ISDIR(Info.st_mode));
   return 1; 
}
