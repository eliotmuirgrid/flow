#include "FILpathName.h"
#include "COLstring.h"
#include "COLtrace.h"
COL_TRACE_INIT;
COLstring FILpathNameNoExt(const COLstring& Path){
   COL_FUNCTION(FILpathNameWithoutLastExt);
   COLstring FileNameOnly = FILpathName(Path);
   int DotIndex = FileNameOnly.reverseFind('.');
   if(DotIndex < 0){
      return FileNameOnly; 
   }
   COL_VAR(DotIndex);
   return FileNameOnly.substr(0, DotIndex);
};