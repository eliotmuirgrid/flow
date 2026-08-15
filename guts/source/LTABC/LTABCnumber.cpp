#include "LTABCnumber.h"
#include "LUAlua.h"
#include "JSONvar.h"
#include "COLtrace.h"
COL_TRACE_INIT;

void LTABCnumber(lua_State* L, JSONvar* pVar){
   COL_FUNCTION(LTABCnumber);

   pVar->Type   = LUA_TNUMBER;
   pVar->Number = lua_tonumber(L, -1);
}
