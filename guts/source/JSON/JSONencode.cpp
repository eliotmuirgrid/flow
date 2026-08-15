//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Saturday 15th August 2026
//       0x6A80605D seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "JSONencode.h"
#include "JSONvar.h"
#include "JSONvarEncode.h"
#include "LUAlua.h"
#include "LTABCvar.h"
#include "COLstringPushL.h"
#include "COLtrace.h"
COL_TRACE_INIT;

int JSONencode(lua_State* L){
   COL_FUNCTION(JSONencode);
   JSONvar Input;
   LTABCvar(L, &Input);
   COL_VAR(Input);
   COLstring Out;
   JSONvarEncode(Input, &Out);
   COL_VAR(Out);
   COLstringPushL(L, Out);
   return 1;
}
