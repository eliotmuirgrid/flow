#include "LTABCtable.h"
#include "LTABCvar.h"
#include "LUAlua.h"
#include "JSONvar.h"
#include "COLstringL.h"
#include "COLtrace.h"
COL_TRACE_INIT;

void LTABCtable(lua_State* L, JSONvar* pVar){
   COL_FUNCTION(LTABCtable);

   pVar->Type = LUA_TTABLE;

   int TableIndex = lua_gettop(L);

   lua_pushnil(L);

   while (lua_next(L, TableIndex)){
      if (lua_type(L, -2) == LUA_TNUMBER){
         int Index = (int)lua_tonumber(L, -2);

         if (pVar->Array.size() < Index){
            pVar->Array.resize(Index);
         }

         LTABCvar(L, &pVar->Array[Index - 1]);
      }
      else if (lua_type(L, -2) == LUA_TSTRING){
         COLstring Key = COLstringL(L, -2);
         LTABCvar(L, &pVar->Dict[Key]);
      }

      lua_pop(L, 1);
   }
}
