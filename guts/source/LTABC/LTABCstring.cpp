#include "LTABCstring.h"
#include "LUAlua.h"
#include "JSONvar.h"
#include "COLstringL.h"
#include "COLtrace.h"
COL_TRACE_INIT;

void LTABCstring(lua_State* L, JSONvar* pVar){
   COL_FUNCTION(LTABCstring);

   pVar->Type   = LUA_TSTRING;
   pVar->String = COLstringL(L, -1);
}
