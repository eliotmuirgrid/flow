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
#include "FILpathSimplify.h"
#include "FILexecutableFind.h"
#include "DIRworking.h"
#include "PATHisAbsolute.h"

#include "COLtrace.h"
COL_TRACE_INIT;

COLstring FILdirExe(const COLstring& ExeFile){
   COL_FUNCTION(FILdirExe);
   COL_VAR(ExeFile);
   COLstring Resolved = FILexecutableFind(ExeFile);

   COLstring Dir = Resolved.substr(0, Resolved.size() - FILpathName(Resolved).size());
   FILpathSimplify(&Dir);  // TODO should I check
   COL_VAR(Dir);
   return Dir;
}