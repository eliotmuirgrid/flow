//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Wednesday 12th August 2026
//       0x6A7CF56A seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "COLcallDecrease.h"
#include "COLcallIncrease.h"
#include "COLassert.h"

void COLcallDecrease(){
   COLASSERT(s_COLindentLevel > 0);
   s_COLindentLevel--;
}
