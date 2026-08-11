//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Monday 10th August 2026
//       0x6A79D2D0 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "APPrun.h"
#include "LUApathSet.h"
#include "LUAloadLib.h"
#include "LUAlua.h"
#include "LUApushArray.h"
#include "LIBregister.h"
#include "FILexists.h"
#include "FLOWbinDirSet.h"
#include "FLOWbinDirGet.h"
#include "FLOWfileLua.h"
#include "FILdirExe.h"
#include "COLstringL.h"
#include "COLarray.h"
#include "COLtrace.h"
COL_TRACE_INIT;

void APPrun(lua_State* L, const COLstring& Func, const COLarray<COLstring>& Args){
   COL_FUNCTION(APPrun);
   LUAloadLib(L);
   LIBregister(L);  // TODO wonder if we should do this on demand?
   FLOWbinDirSet(L, FILdirExe(Args[0]));
   LUApathSet(L);
   COLstring FileName = FLOWbinDirGet(L) + FLOWfileLua(Func);
   COL_VAR(FileName);
   if (luaL_loadfile(L, FileName.data()) || lua_pcall(L, 0, 0, 0)) {
      COLout << "luaL_loadfile failed:" << COLstringL(L, -1) << newline;
      lua_close(L);
      return;
   }
   COL_TRC("About to get: " << Func);
   lua_getglobal(L, Func.data());
   if (lua_isnil(L, -1)) {
      COLout << "Unable to find function: " << Func << newline;
      lua_close(L);
      return;
   }
   LUApushArray(L, Args);
   if (lua_pcall(L, 1, 0, 0)){
      COLout << COLstringL(L, -1) << newline;
      lua_close(L);
      return;
   }
   lua_close(L);
}
