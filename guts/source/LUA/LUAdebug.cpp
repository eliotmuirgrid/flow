/*************************
 * Copyright (C) Eliot Muir Forever
 *
 * Date: Wed  1 Jul 2026 06:17:53 EST
 **************************/

#include "COLstring.h"
#include "COLglobMatch.h"
#include "DEBUGstackPush.h"
#include "HOOKmain.h"
#include "LUAlua.h"
#include "LUAdebug.h"
#include "LUAltrace.h"
#include "LUAtracePatternSet.h"
#include "REGtableSet.h"

#include "COLtrace.h"
COL_TRACE_INIT;

void LUAdebug(lua_State* L, const COLstring& Match){
   COL_FUNCTION(LUAdebug);
   COL_VAR(Match);
   LUAtracePatternSet(L, Match);
   lua_sethook(L, HOOKmain, LUA_MASKCALL | LUA_MASKRET, 0);
   REGtableSet(L, "DEBUGstack");
   lua_register(L, "LUAltrace", LUAltrace);
}
