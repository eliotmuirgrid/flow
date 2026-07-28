//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Tuesday 28th July 2026
//       0x6A693EFA the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include <LUA/LUAlua.h>
#include <DIR/DIRcreate.h>
#include <FOO/FOOhelper.h>
#include <LUA/LUAltrace.h>
#include <STRING/STRINGsplit.h>
#include <URL/URLopen.h>

#include <COL/COLtrace.h>
COL_TRACE_INIT;

// This file is auto generated. 
void LIBregister(lua_State* L){
   COL_FUNCTION(LIBregister);
   lua_register(L, "DIRcreate", DIRcreate);
   lua_register(L, "FOOhelper", FOOhelper);
   lua_register(L, "LUAltrace", LUAltrace);
   lua_register(L, "STRINGsplit", STRINGsplit);
   lua_register(L, "URLopen", URLopen);
}
