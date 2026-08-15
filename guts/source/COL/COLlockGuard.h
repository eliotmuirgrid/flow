#pragma once

class COLlock;

class COLlockGuard {
public:
   COLlockGuard(COLlock& Lock);
   ~COLlockGuard(); 

private:
   COLlock& m_Lock;

   COLlockGuard(const COLlockGuard&);
   COLlockGuard& operator=(const COLlockGuard&);
};
