// ---------------------------------------------------------------------------
// Copyright (C) Eliot.  All Rights Reserved
//
// Module: FILdir
//
// Description:
//
// Implementation
//
// Author: Eliot Muir 
// Date:   Wednesday 01 July 2026 - 07:40PM
// ---------------------------------------------------------------------------

#include "FILdirExe.h"
#include "FILpathName.h"

#include "COLtrace.h"
COL_TRACE_INIT;

COLstring FILdirExe(const COLstring& ExeFile){
   COL_FUNCTION(FILdirExe);
   COL_VAR(ExeFile);
   COLstring Dir = ExeFile.substr(0, ExeFile.size() - FILpathName(ExeFile).size());
   COL_VAR(Dir);
   return Dir;
}