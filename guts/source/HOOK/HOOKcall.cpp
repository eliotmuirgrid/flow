//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Thursday 30th July 2026
//       0x6A6BE214 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "DEBUGstackPush.h"
#include "FILpathNameNoExt.h"
#include "HOOKfilterTrace.h"
#include "HOOKfilterC.h"
#include "HOOKfilterTail.h"
#include "LUAlua.h"
#include "LUAtracePatternGet.h"
#include "LUACdebug.h"
#include "COLglobMatch.h"
#include "COLtrace.h"
COL_TRACE_INIT;

void HOOKcall(lua_State* L, lua_Debug* ar){
   COL_FUNCTION(HOOKcall);
   if (!lua_getinfo(L, "nSl", ar)){ return; }
   if (!ar->name){
      return;
   }
   COLstring source = ar->short_src[0] ? ar->short_src : "?";

   COL_VAR2(source, *ar);

   if (HOOKfilterTrace(source)){ return; }
   if (HOOKfilterC    (source)){ return; }
   if (HOOKfilterTail (source)){ return; }

   source = FILpathNameNoExt(source);
   DEBUGstackPush(L, source);
   COL_VAR(source);

   COLstring MatchPattern = LUAtracePatternGet(L);
   if (!COLglobMatch(source.data(), MatchPattern.data())){ return; }

   COLstring name = source;
   source += ".lua";

   COLtimeStamp(source.data(), COLlog);
   COLlog << ">" << name << "()" << newline; COLcallIncrease();   
}
