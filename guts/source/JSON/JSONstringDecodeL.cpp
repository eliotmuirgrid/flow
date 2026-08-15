//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Saturday 15th August 2026
//       0x6A809B91 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "JSONstringDecodeL.h"
#include "JSONstringDecode.h"
#include "LUAlua.h"
#include "COLstringL.h"
#include "COLstringPushL.h"
#include "COLtrace.h"
COL_TRACE_INIT;

int JSONstringDecodeL(lua_State* L){
   COL_FUNCTION(JSONstringDecodeL);
   COLstring Input = COLstringL(L,-1);
   COLstring Output;
   JSONstringDecode(Input, &Output);
   COLstringPushL(L,Output);
   return 1;
}
