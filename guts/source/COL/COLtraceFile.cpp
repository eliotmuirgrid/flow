//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Thursday 13th August 2026
//       0x6A7DC4F9 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "COLtraceFile.h"
#include "FILopenWrite.h"
#include "COLsinkFile.h"
#include "COLtrace.h"

bool COLtraceFile(const COLstring& TraceFile){
   int FileNo = FILopenWrite(TraceFile);
   if (-1 == FileNo){
      COLout << "### Failed to open " << TraceFile << " for trace log file." << newline;
      return false;
   }
   COLtraceOut.setSink(new COLsinkFile(FileNo));
   COLtraceOut << "### Tracing redirected into " << TraceFile << newline;
   return true;
}
