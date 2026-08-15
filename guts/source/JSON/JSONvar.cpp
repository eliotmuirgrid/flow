//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Friday 14th August 2026
//       0x6A7F1464 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "JSONvar.h"
#include "JSONvarEncode.h"
#include "COLtrace.h"
#include "LUAlua.h"  // for LUA_TNIL
COL_TRACE_INIT;

JSONvar::JSONvar() : Type(LUA_TNIL), Boolean(false), Number(0) {
   COL_METHOD(JSONvar::JSONvar);
}

JSONvar::~JSONvar(){
   COL_METHOD(JSONvar::~JSONvar);
}

COLstream& operator<<(COLstream& Stream, const JSONvar& Var){
   COLstring Out;
   JSONvarEncode(Var, &Out);
   Stream << Out;
   return Stream;
}
