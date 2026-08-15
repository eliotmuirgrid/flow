//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Tuesday 11th August 2026
//       0x6A7B68BC seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "LUAstackCheck.h"
#include "LUAlua.h"
#include "COLassert.h"
#include "COLtrace.h"
COL_TRACE_INIT;


LUAstackCheck::LUAstackCheck(lua_State* iL, int iDelta) : L(iL), Top(lua_gettop(iL)), Delta(iDelta){
   COL_METHOD(LUAstackCheck::LUAstackCheck);
}

LUAstackCheck::~LUAstackCheck(){
   COL_METHOD(LUAstackCheck::~LUAstackCheck);
   COLASSERT(lua_gettop(L) == Top + Delta);
}
