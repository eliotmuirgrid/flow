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
#include "DEBUGcurrentFunc.h"
#include "DEBUGstackDump.h"
#include "HOOKfilterTrace.h"
#include "HOOKfilterC.h"
//#include "HOOKfilterTail.h"

#include "COLcallDecrease.h"
#include "COLglobMatch.h"
#include "COLtrace.h"
COL_TRACE_INIT;

void HOOKtailReturn(lua_State* L, lua_Debug* ar){
   COL_FUNCTION(HOOKtailReturn);

   if (!ar->name){ COL_TRC("No name."); return; }
   COLstring source = ar->short_src[0] ? ar->short_src : "?";
   COL_VAR(source);

   if (HOOKfilterTrace(source)){ COL_TRC("Filtered COLtrace/COLshow etc."); return; }
   if (HOOKfilterC    (source)){ COL_TRC("Filtered C call");                return; }
   //if (HOOKfilterTail (source)){ COL_TRC("Filtered tail call");             return; }

   COLstring Func = DEBUGcurrentFunc(L);
   COL_VAR(Func);
   DEBUGstackPop(L);
   COL_VAR(DEBUGstackDump(L));
//   Func = DEBUGcurrentFunc(L);
//   COL_VAR(Func);

   COLstring MatchPattern = LUAtracePatternGet(L);
   if (!COLglobMatch(Func.data(), MatchPattern.data())){ return; }
   COLstring Source = Func+".lua";  
   COLcallDecrease(); COLtraceTime(Source.data(), COLtraceOut);COLtraceOut << "<" << Func << newline;    
}
