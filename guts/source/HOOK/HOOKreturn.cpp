//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Thursday 30th July 2026
//       0x6A6BE1BB seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "LUAlua.h"
#include "LUAtracePatternGet.h"
#include "LUAtraceFileSet.h"
#include "FILpathNameNoExt.h"
#include "COLglobMatch.h"
#include "COLtrace.h"
COL_TRACE_INIT;

void HOOKreturn(lua_State* L, lua_Debug* ar){
   COL_FUNCTION(HOOKreturn);
   if (!lua_getinfo(L, "nSl", ar)){ return; }
   if (!ar->name){
      return;
   }
   COLstring source = ar->short_src[0] ? ar->short_src : "?";

   COL_TRC("Source before COL filtering =" << source);
   if (source.find("COLshow")){ COL_TRC("Matched COLshow"); return; }
   if (source.find("COLtrace")){ COL_TRC("Matched COLtrace"); return; }

   COL_HEX("Source:", source.data(), source.size());
   COL_VAR(source.data()[0]);
   bool Check =source.data ()[0] == '[' || source.data()[0] == '(';
   COL_VAR(Check);
   if (Check) { COL_TRC("In C Function or tail call."); return; } // it equals [ HACK [C]
   source = FILpathNameNoExt(source);
   COL_TRC("Source after FILpathNameNoExt=" << source);
   COLstring MatchPattern = LUAtracePatternGet(L);
   if (!COLglobMatch(source.data(), MatchPattern.data())){ LUAtraceFileSet(L, ""); return; }
   COLstring name = source;
   source += ".lua";
   LUAtraceFileSet(L, source);

   COLcallDecrease(); COLtimeStamp(source.data(), COLlog);COLlog << "<" << name << newline;                             
}