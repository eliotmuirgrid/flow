//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Monday 10th August 2026
//       0x6A7A20FD seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "FLOWfile.h"
#include "PREFIXextract.h"
#include "COLtrace.h"
COL_TRACE_INIT;

COLstring FLOWfile(const COLstring& Name, const COLstring& Ext){
   COL_FUNCTION(FLOWfile);
   COLstring Prefix = PREFIXextract(Name);  // TODO what is nothing?
   COLstring Path   = Prefix + "/" + Name + "." + Ext;
   COL_VAR(Path);
   return Path;
}
