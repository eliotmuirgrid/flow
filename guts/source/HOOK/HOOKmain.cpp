//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Thursday 30th July 2026
//       0x6A6BE0AC seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include <LUA/LUAlua.h>
#include <HOOK/HOOKcall.h>
#include <HOOK/HOOKreturn.h>
#include <HOOK/HOOKtailReturn.h>

#include <COL/COLtrace.h>
COL_TRACE_INIT;

void HOOKmain(lua_State* L, lua_Debug* pDb){
   COL_FUNCTION(HOOKmain);
   switch(pDb->event){
   case LUA_HOOKCALL   : HOOKcall      (L, pDb); break;
   case LUA_HOOKRET    : HOOKreturn    (L, pDb); break;
   case LUA_HOOKTAILRET: HOOKreturn    (L, pDb); break; 
   }
}
