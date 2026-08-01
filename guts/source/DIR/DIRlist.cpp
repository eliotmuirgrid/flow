//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Wednesday 29th July 2026
//       0x6A6A5A0D seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------
#include "dirent.h"

#include "LUAlua.h"
#include "COLtrace.h"
COL_TRACE_INIT;

int DIRlist(lua_State* L){
   COL_FUNCTION(DIRlist);
   const char *path = luaL_checkstring(L, 1);
   DIR *directory = opendir(path);

   if (!directory) {
      return luaL_error(L, "cannot open directory: %s", path);
   }

   lua_newtable(L);

   int index = 1;
   struct dirent *entry;

   while ((entry = readdir(directory)) != NULL) {
      if (strcmp(entry->d_name, ".") == 0 ||
          strcmp(entry->d_name, "..") == 0) {
          continue;
      }
      lua_pushnumber(L, index++);
      lua_pushstring(L, entry->d_name);
      lua_settable(L, -3);
   }

   closedir(directory);
   return 1;
}