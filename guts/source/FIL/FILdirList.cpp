//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Wednesday 29th July 2026
//       0x6A6A23B4 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "FILdirList.h"

#include "dirent.h"

#include "COLdictSorted.h"
#include "COLnull.h"
#include "COLtrace.h"
COL_TRACE_INIT;

bool FILdirList(const COLstring& Dir, COLdictSorted<COLstring, COLfile>* pList){
   COL_FUNCTION(FILdirList);
   DIR* dir = opendir(Dir.data());

   if (!dir) { return false; }

   struct dirent* ent;

   while ((ent = readdir(dir)) != COLnull) {
      pList->add(ent->d_name, COLfile()); 
   }
   closedir(dir);
   return true;
}
