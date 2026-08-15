//-------------------------------------------------------
// Copyright (C) 2021 Eliot Muir.  All Rights Reserved
//
// COLsinkFile
//-------------------------------------------------------

#include "COLsinkFile.h"
#include "fcntl.h"
#include "unistd.h"


COLsinkFile::COLsinkFile(int FileHandle) : m_FileHandle(FileHandle){}

int COLsinkFile::write(const char* pData, int Size){
   return ::write(m_FileHandle, pData, Size);
} 

void COLsinkFile::flush(){
   ::fsync(m_FileHandle);
} 
