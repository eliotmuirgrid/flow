#pragma once
//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// FILdirList 
//
// To be documented by an AI agent later!
//
// Date: Wednesday 29th July 2026
//       0x6A6A23B4 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "COL/COLbase.h"

class COLstring;

class COLfile{
public:
   bool IsDir;
};
   
bool FILdirList(const COLstring& Dir, COLdictSorted<COLstring, COLfile>* pList); 