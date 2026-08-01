/*************************
 * Copyright (C) Eliot Muir Forever
 *
 * Date: Wed  1 Jul 2026 06:17:53 EST
 **************************/

#include "COLstring.h"
#include "COLglobMatch.h"
#include "LUAlua.h"
#include "LUAdebug.h"
#include "LUAtraceFileSet.h"
#include "HOOKmain.h"
#include "LUAtracePatternSet.h"

#include "COLtrace.h"
COL_TRACE_INIT;

void LUAdebug(lua_State* L, const COLstring& Match){
   COL_FUNCTION(LUAdebug);
   COL_VAR(Match);
   LUAtracePatternSet(L, Match);
   lua_sethook(L, HOOKmain, LUA_MASKCALL | LUA_MASKRET, 0);
   // TODO this is really ugly Eliot you should be ashamed of yourself!  CLEAN ME!
   if (COLglobMatch("MAINmain", Match.data())){ 
      COL_TRC("Tracing MAINmain.lua");
      LUAtraceFileSet(L, "MAINmain.lua");
   }
}