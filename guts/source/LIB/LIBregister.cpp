//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Thursday 30th July 2026
//       0x6A6B8DBC the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include <LUA/LUAlua.h>
#include <DIR/DIRcreate.h>
#include <DIR/DIRdelete.h>
#include <DIR/DIRlist.h>
#include <FILE/FILEexists.h>
#include <LUA/LUAltrace.h>
#include <OS/OSisMacL.h>
#include <OS/OSisWindowsL.h>
#include <STRING/STRINGsplit.h>

#include <COL/COLtrace.h>
COL_TRACE_INIT;

// This file is auto generated. 
void LIBregister(lua_State* L){
   COL_FUNCTION(LIBregister);
   lua_register(L, "DIRcreate", DIRcreate);
   lua_register(L, "DIRdelete", DIRdelete);
   lua_register(L, "DIRlist", DIRlist);
   lua_register(L, "FILEexists", FILEexists);
   lua_register(L, "LUAltrace", LUAltrace);
   lua_register(L, "OSisMac", OSisMacL);
   lua_register(L, "OSisWindows", OSisWindowsL);
   lua_register(L, "STRINGsplit", STRINGsplit);
}
