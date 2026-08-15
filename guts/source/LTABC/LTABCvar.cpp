#include "LTABCvar.h"
#include "LTABCboolean.h"
#include "LTABCnumber.h"
#include "LTABCstring.h"
#include "LTABCtable.h"
#include "LUAlua.h"
#include "JSONvar.h"
#include "COLtrace.h"
COL_TRACE_INIT;

void LTABCvar(lua_State* L, JSONvar* pVar){
   COL_FUNCTION(LTABCvar);

   switch (lua_type(L, -1)){
      case LUA_TNIL:     pVar->Type = LUA_TNIL;      break;
      case LUA_TBOOLEAN: LTABCboolean(L, pVar);      break;
      case LUA_TNUMBER:  LTABCnumber (L, pVar);      break;
      case LUA_TSTRING:  LTABCstring (L, pVar);      break;
      case LUA_TTABLE:   LTABCtable  (L, pVar);      break;
   }
}
