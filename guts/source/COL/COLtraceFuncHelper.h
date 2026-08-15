#pragma once

class COLtraceFuncHelper{
public:
    COLtraceFuncHelper(const char* Name, const char* pModule, int Line, bool Trace);
    COLtraceFuncHelper(const char* Name, const char* pModule, int Line, const void* pThis, bool Trace);
    
    ~COLtraceFuncHelper();
private:
   bool m_Trace;
   const char* m_pName;
   const char* m_pModule; 
};

