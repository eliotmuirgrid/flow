//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Thursday 13th August 2026
//       0x6A7DB9BB seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "COLlock.h"
#include "COLtrace.h"

COLlock::COLlock(){
   pthread_mutex_init(&m_Mutex, 0);
}

COLlock::~COLlock(){
   pthread_mutex_destroy(&m_Mutex);
}

void COLlock::lock(){
   pthread_mutex_lock(&m_Mutex);
}

void COLlock::unlock(){
   pthread_mutex_unlock(&m_Mutex);
}
