#pragma once
#include <pthread.h>

class COLlock {
public:
   COLlock();
   ~COLlock();

   void lock();
   void unlock();

   COLlock(const COLlock&) = delete;
   COLlock& operator=(const COLlock&) = delete;

private:
   pthread_mutex_t m_Mutex;
};
