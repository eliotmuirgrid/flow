#include "COLtraceHex.h"
#include "COLlockGuard.h"
#include "COLstreamString.h"
#include "COLhex.h"
#include "COLtrace.h"

void COLtraceHex(const char* pLabel, int Size, const void* pBuffer, const char* pName){
   COLstreamString LogStream;
   LogStream << pLabel;
   LogStream << "= (size=" << Size << ")" << newline;
   COLhex(Size, pBuffer, LogStream.sink(), 60);
   LogStream << newline;
   COLlockGuard Guard(COLtraceLock);
   COLtraceTime(pName, COLtraceOut);
   COLtraceOut << LogStream.m_String;
}
