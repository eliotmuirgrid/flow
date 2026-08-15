//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Wednesday 12th August 2026
//       0x6A7CF1BE seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "COLtraceFuncHelper.h"
#include "COLtraceTime.h"
#include "COLcallIncrease.h"
#include "COLcallDecrease.h"
#include "COLlockGuard.h"
#include "COLtrace.h"

COLtraceFuncHelper::COLtraceFuncHelper(const char* Name, const char* pModule, int Line, bool Trace) : m_pModule(pModule), m_pName(Name), m_Trace(Trace) {
   if (Trace){
      COLlockGuard Guard(COLtraceLock);
      COLtraceTime(pModule, COLtraceOut); COLtraceOut << ">" << Name << " Line:" << Line << newline;
      COLcallIncrease();
   }
}

COLtraceFuncHelper::COLtraceFuncHelper(const char* Name, const char* pModule, int Line, const void* pInstance, bool Trace) : m_pModule(pModule), m_pName(Name), m_Trace(Trace) {
   if (Trace){
      {
         COLlockGuard Guard(COLtraceLock);
         COLtraceTime(pModule, COLtraceOut); COLtraceOut << ">" << Name << " Line:" << Line << " this=" << pInstance << newline;
      }
      COLcallIncrease();
   }
}

COLtraceFuncHelper::~COLtraceFuncHelper(){
   if (m_Trace){
      COLcallDecrease();
      COLlockGuard Guard(COLtraceLock);
      COLtraceTime(m_pModule, COLtraceOut); COLtraceOut << "<" << m_pName << newline;
   }
}

