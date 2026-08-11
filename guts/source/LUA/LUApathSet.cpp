#include "LUApathSet.h"
#include "FLOWbinDirGet.h"
#include "stdlib.h"
#include "COLtrace.h"
COL_TRACE_INIT;

void LUApathSet(lua_State* L){
   COL_FUNCTION(LUApathSet);
   COLstring Path  = FLOWbinDirGet(L)+"?.lua";
   COL_VAR(Path);
   setenv("LUA_PATH", Path.data(), Path.size());
}
