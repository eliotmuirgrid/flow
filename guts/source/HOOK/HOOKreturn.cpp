//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Thursday 30th July 2026
//       0x6A6BE1BB seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "DEBUGstackPop.h"
#include "FILpathNameNoExt.h"
#include "HOOKfilterTrace.h"
#include "HOOKfilterC.h"
#include "HOOKfilterTail.h"
#include "LUAlua.h"
#include "LUAtracePatternGet.h"
#include "LUACdebug.h"
#include "DEBUGstackDump.h"
#include "COLcallDecrease.h"
#include "COLassert.h"
#include "COLglobMatch.h"
#include "COLtrace.h"
COL_TRACE_INIT;

void HOOKreturn(lua_State* L, lua_Debug* ar){
   COL_FUNCTION(HOOKreturn);
   if (!lua_getinfo(L, "nSl", ar)){ return; }
   if (!ar->name){ COL_TRC("No name."); return; }
   COLstring source = ar->short_src[0] ? ar->short_src : "?";
   COL_VAR(source);

   COL_VAR(DEBUGstackDump(L));

   if (HOOKfilterTrace(source)){ COL_TRC("Filtered COLtrace/COLshow etc."); return; }
   if (HOOKfilterC    (source)){ COL_TRC("Filtered C call");                return; }
   if (HOOKfilterTail (source)){ COL_TRC("Filtered tail call");             return; }

   source = FILpathNameNoExt(source);
   DEBUGstackPop(L);
   COL_VAR(source);

   COLstring MatchPattern = LUAtracePatternGet(L);
   if (!COLglobMatch(source.data(), MatchPattern.data())){ return; }
   
   COLstring name = source;
   source += ".lua";

   COLcallDecrease(); 
   COLtraceTime(source.data(), COLtraceOut);
   COLtraceOut << "<" << name << newline; 
}
