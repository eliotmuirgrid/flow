/***************************************
 * Copyright (C) Eliot Muir Forever
 *
 * Set a lua path
 *
 * Date: Wed  1 Jul 2026 06:17:53 EST
 ***************************************/

#include "LUAloadLib.h"
#include "LUAlua.h"
#include "LUAstringRegister.h"

#include "COLtrace.h"
COL_TRACE_INIT;

void LUAloadLib(lua_State* L){
   COL_FUNCTION(LUAloadLib);
   luaopen_base(L);
   luaopen_table(L);
   luaopen_io(L);
   luaopen_string(L);
   luaopen_math(L);
   luaopen_debug(L);
   LUAstringRegister(L);
}