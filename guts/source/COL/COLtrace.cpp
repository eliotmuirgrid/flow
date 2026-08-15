//-------------------------------------------------------
// Copyright (C) 2021 Eliot Muir.  All Rights Reserved
//
// COLtrace
// 
// Implementation
//-------------------------------------------------------

#include "COLtrace.h"
#include "COLsinkFile.h"
#include "COLlock.h"

#include "string.h"

COLlock     COLtraceLock;
const char* COLtracePattern = "";
COLstream   COLtraceOut(new COLsinkFile(1), false);  // purposely leaked.

void COLtrace(const char* pPattern){
   COLout << "# Tracing files matching: " << pPattern << newline;
   COLtracePattern = strdup(pPattern);  // purposely leaked.
}

