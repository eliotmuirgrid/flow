//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Tuesday 28th July 2026
//       0x6A68DEC6 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "LUAlua.h"
#include "LUAtracePatternGet.h"
#include "DEBUGcurrentFunc.h"
#include "DEBUGstackDump.h"
#include "COLstreamWithIndent.h"
#include "COLstringL.h"
#include "COLglobMatch.h"
#include "COLlockGuard.h"
#include "COLassert.h"
#include "COLcallIncrease.h"
#include "COLtrace.h"
COL_TRACE_INIT;

int LUAltrace(lua_State* L){
   COL_FUNCTION(LUAltrace);
   COL_VAR(lua_type(L,-1));
   COLASSERT(lua_isstring(L,-1));
   COLstring Message = COLstringL(L, -1);
   COL_VAR(Message);

   COL_VAR(DEBUGstackDump(L));
         
   COLstring FileName = DEBUGcurrentFunc(L);
   COL_VAR(FileName);
   if (!FileName.empty()){
      COLstring TracePattern = LUAtracePatternGet(L);
      COL_VAR(TracePattern);
      if (COLglobMatch(FileName.data(), TracePattern.data())){ 
         COLlockGuard Guard(COLtraceLock);
         // TODO convert \n to indented 
         COLtraceTime((FileName + ".lua").data(), COLtraceOut); 
         COLstreamWithIndent(COLtraceOut,Message, s_COLindentLevel); 
      }
   }
   return 0;
}
