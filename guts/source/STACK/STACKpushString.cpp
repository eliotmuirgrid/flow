//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Thursday 30th July 2026
//       0x6A6BDC61 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include <STACK/STACKpush.h>
#include <LUA/LUAlua.h>
#include <COL/COLstringPushL.h>
#include <COL/COLtrace.h>
COL_TRACE_INIT;

void STACKpushString(lua_State* L, int i, const COLstring& Value){
   COL_FUNCTION(STACKpushString);
   COLstringPushL(L, Value);
   STACKpush(L, i);
}
