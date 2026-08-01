#include "LUAlua.h"

#include "LUAC/lua.h"
#include "LUAC/lauxlib.h"
#include "LUAC/lualib.h"

#include "LIBregister.h"
#include "LUAarray.h"
#include "LUApathSet.h"
#include "LUAloadLib.h"
#include "LUAdebug.h"
#include "FILdirExe.h"

#include "FLAGpresentWithArg.h"
#include "FLAGpresent.h"
#include "COLstring.h"
#include "COLstream.h"
#include "COLarray.h"
#include "COLarrayCopy.h"
#include "COLtrace.h"
COL_TRACE_INIT;

void APPrun(lua_State* L, const COLarray<COLstring>& Args){
   COL_FUNCTION(APPrun);
   LUAloadLib(L);
   LIBregister(L);  // TODO wonder if we should do this on demand?
   LUApathSet(L, Args[0]);
   //COLstring FileName =FILdirExe(Args[0])+"guts/source/main/main.lua";
   COLstring FileName ="/zip/guts/source/MAIN/MAINmain.lua";
   if (luaL_loadfile(L, FileName.data()) || lua_pcall(L, 0, 0, 0)) {
      fprintf(stderr, "%s\n", lua_tostring(L, -1));
      lua_close(L);
      return;
   }
   lua_getglobal(L, "MAINmain");
   LUApushArray(L, Args);
   if (lua_pcall(L, 1, 0, 0)){
      fprintf(stderr, "%s\n", lua_tostring(L, -1));
      lua_close(L);
      return;
   }
   lua_close(L);
}

int main (int argc, const char** argv) {
  COL_FUNCTION(main);
  COLarray<COLstring> Args;
  COLarrayCopy(argc, argv, &Args);

  bool NoCpp = FLAGpresent("nocpp", &Args);
  COLstring Trace;
  FLAGpresentWithArg("trace", &Trace, &Args);
  bool NoLua = FLAGpresent("nolua", &Args);
  COL_VAR(NoLua);
  lua_State* L = lua_open();
  if (!Trace.empty() && !NoCpp)            { COLtrace(Trace.data());}
  if (!Trace.empty() && !NoLua)            { LUAdebug(L, Trace);    }
  if (!Trace.empty() && (!NoLua && !NoCpp)){ COLheader();           }
  APPrun(L, Args);

  return 0;  // 0 means success.  Nothing is success apparently.
}
