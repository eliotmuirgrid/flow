//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Thursday 30th July 2026
//       0x6A6BCF56 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "COLstringL.h"
#include "COLstringPushL.h"
#include "LUAlua.h"
#include "COLtrace.h"
COL_TRACE_INIT;

int FILEextension(lua_State* L){
   COL_FUNCTION(FILEextension);
   COLstring File = COLstringL(L, -1);
   int Position = File.reverseFind('.');
   COLstring Ext;
   if (Position == -1) {
      COL_TRC("No extention");
   } else {
      Ext = File.substr(Position+1);
   }
   COL_VAR2(File, Ext);
   COLstringPushL(L, Ext);
   return 1;
}