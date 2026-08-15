//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Monday 10th August 2026
//       0x6A7A90BE seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "LUAlua.h"
#include "HOOKcallToString.h"
#include "COLtrace.h"
COL_TRACE_INIT;

COLstring HOOKcallToString(int Code){
   switch(Code){
      case LUA_HOOKCALL   : return "HOOK_CALL";
      case LUA_HOOKRET    : return "HOOK_RETURN";
      case LUA_HOOKLINE   : return "HOOK_LINE";
      case LUA_HOOKCOUNT  : return "HOOK_COUNT";
      case LUA_HOOKTAILRET: return "HOOK_TAIL_RETURN";
      default             : return "HOOK_UNKNOWN";
   }
}
