//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Saturday 15th August 2026
//       0x6A80C0EB the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "LUAlua.h"
#include "DIRcreate.h"
#include "DIRdelete.h"
#include "DIRisDir.h"
#include "DIRlist.h"
#include "FILEexists.h"
#include "FILEextension.h"
#include "FILEpath.h"
#include "JSONencode.h"
#include "JSONstringDecodeL.h"
#include "OSisMacL.h"
#include "OSisWindowsL.h"
#include "STDINreadL.h"
#include "STRINGsplit.h"

#include "COLtrace.h"
COL_TRACE_INIT;

// This file is auto generated. 
void LIBregister(lua_State* L){
   COL_FUNCTION(LIBregister);
   lua_register(L, "DIRcreate", DIRcreate);
   lua_register(L, "DIRdelete", DIRdelete);
   lua_register(L, "DIRisDir", DIRisDir);
   lua_register(L, "DIRlist", DIRlist);
   lua_register(L, "FILEexists", FILEexists);
   lua_register(L, "FILEextension", FILEextension);
   lua_register(L, "FILEpath", FILEpath);
   lua_register(L, "JSONencode", JSONencode);
   lua_register(L, "JSONstringDecode", JSONstringDecodeL);
   lua_register(L, "OSisMac", OSisMacL);
   lua_register(L, "OSisWindows", OSisWindowsL);
   lua_register(L, "STDINread", STDINreadL);
   lua_register(L, "STRINGsplit", STRINGsplit);
}
