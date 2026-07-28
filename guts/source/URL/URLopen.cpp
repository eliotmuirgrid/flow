//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Friday 24th July 2026
//       0x6A63F9F7 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include <LUA/LUAlua.h>
#include <libc/dce.h>  // for IsWindows(), IsMac(), system(), etc.

#include <COL/COLtrace.h>
COL_TRACE_INIT;

// TODO we have to write AI routines to clean up this code.

// Opens the given URL in default browser on Mac and Windows
// Usage from Lua: URLopen("http://example.com")
int URLopen(lua_State* L){
   COL_FUNCTION(URLopen);
   // Check if we have a string argument
  /* if (!lua_isstring(L, 1)) {
      lua_pushstring(L, "URLopen: Argument must be a string.");
      lua_error(L);
   }
   const char* url = lua_tostring(L, 1);  // TODO 
   int ret = 0;
   if (IsWindows()) {
      // Windows: Use 'start "" "<url>"'
      char cmd[1024];
      snprintf(cmd, sizeof(cmd), "start \"\" \"%s\"", url);
      ret = system(cmd);
   } else if (IsXnu()) {
      // macOS: Use 'open "<url>"'
      char cmd[1024];
      snprintf(cmd, sizeof(cmd), "open \"%s\"", url);
      ret = system(cmd);
   } else {
      lua_pushstring(L, "URLopen: Unsupported platform.");
      lua_error(L);
   }
   // Return true/false to Lua based on ret
   lua_pushboolean(L, ret == 0);*/
   return 1;
}
