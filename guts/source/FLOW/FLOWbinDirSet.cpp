//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Monday 10th August 2026
//       0x6A7A173C seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "FLOWbinDirSet.h"
#include "FILexists.h"
#include "FLOWcodeDir.h"
#include "LUAlua.h"
#include "REGkeySet.h"
#include "COLtrace.h"
COL_TRACE_INIT;

void FLOWbinDirSet(lua_State* L, const COLstring& Dir){
   COL_FUNCTION(FLOWcodeDirSet);
   COLstring CodeDir = Dir + FLOWcodeDir();
   COL_VAR2(Dir, CodeDir);
   if (!FILexists(CodeDir)){
      COL_TRC("No code dir so we are zip land!");
      CodeDir = "/zip/" + FLOWcodeDir();
   }
   COL_VAR(CodeDir);
   REGkeySet(L, "FLOWroot", CodeDir);
}
