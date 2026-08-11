//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Thursday 30th July 2026
//       0x6A6BE9A2 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "DEBUGstackPop.h"
#include "FILpathNameNoExt.h"
#include "HOOKfilterTrace.h"
#include "HOOKfilterC.h"
#include "LUAlua.h"
#include "LUAtracePatternGet.h"
#include "LUACdebug.h"
#include "COLglobMatch.h"
#include "COLtrace.h"
COL_TRACE_INIT;

void HOOKtailReturn(lua_State* L, lua_Debug* ar){
   COL_FUNCTION(HOOKtailReturn);
   if (!lua_getinfo(L, "nSl", ar)){ return; }
   if (!ar->name){
      return;
   }
   COLstring source = ar->short_src[0] ? ar->short_src : "?";
   COL_VAR2(source,*ar);
 
   if (HOOKfilterTrace(source)){ return; }
   if (HOOKfilterC    (source)){ return; }
  
   source = FILpathNameNoExt(source);
   DEBUGstackPop(L);
   COL_VAR(source);

   COLstring MatchPattern = LUAtracePatternGet(L);
   if (!COLglobMatch(source.data(), MatchPattern.data())){ return; }
  
   COLstring name = source;
   source += ".lua";
   COLcallDecrease(); COLtimeStamp(source.data(), COLlog);COLlog << "<" << name << newline;    
   
}
