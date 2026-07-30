//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Tuesday 28th July 2026
//       0x6A68DEC6 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include <LUA/LUAlua.h>
#include <LUA/LUAtraceFileGet.h>
#include <COL/COLstringL.h>
#include <COL/COLtrace.h>
COL_TRACE_INIT;

int LUAltrace(lua_State* L){
   COL_FUNCTION(LUAltrace);
   COLstring FileName = LUAtraceFileGet(L);
   if (!FileName.empty()){
      COLstring Message = COLstringL(L, 1);
      COL_VAR(Message);
      COLtimeStamp(FileName.data(), COLlog); COLlog << Message << newline;
   }
   return 0;
}
