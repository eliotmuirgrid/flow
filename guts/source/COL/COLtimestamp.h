#pragma once
#include "COLint64.h"
#include "time.h"

class COLtimestamp{
public:
   time_t Seconds;
   COLint64 Microseconds;
};

