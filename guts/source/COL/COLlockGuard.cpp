//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Thursday 13th August 2026
//       0x6A7DB9D4 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "COLlockGuard.h"
#include "COLlock.h"
#include "COLtrace.h"
COL_TRACE_INIT;

COLlockGuard::COLlockGuard(COLlock& Lock)
   : m_Lock(Lock){
   m_Lock.lock();
}

COLlockGuard::~COLlockGuard(){
   m_Lock.unlock();
}
