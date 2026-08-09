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
#include "COLstringL.h"
#include "COLglobMatch.h"
#include "COLtrace.h"
COL_TRACE_INIT;

int LUAltrace(lua_State* L){
   COL_FUNCTION(LUAltrace);
   COLstring FileName = DEBUGcurrentFunc(L);
   COL_VAR(FileName);
   if (!FileName.empty()){
      COLstring TracePattern = LUAtracePatternGet(L);
      COL_VAR(TracePattern);
      if (COLglobMatch(FileName.data(), TracePattern.data())){ 
         COLstring Message = COLstringL(L, 1);
         COL_VAR(Message);
         // TODO convert \n to indented 
         COLtimeStamp((FileName + ".lua").data(), COLlog); COLlog << Message << newline;
      }
   }
   return 0;
}
