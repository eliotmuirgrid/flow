//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Tuesday 28th July 2026
//       0x6A68F8AA seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include <REG/REGkeySet.h>
#include <COL/COLtrace.h>
COL_TRACE_INIT;

void LUAtraceFileSet(lua_State* L, const COLstring& File){
   COL_FUNCTION(LUAtraceFileSet);
   COL_VAR(File);
   REGkeySet(L, "LUAtraceFile", File);
}
