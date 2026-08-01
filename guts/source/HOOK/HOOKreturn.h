#pragma once
//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Thursday 30th July 2026
//       0x6A6BE1BB seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

typedef struct lua_State lua_State;
typedef struct lua_Debug lua_Debug;

void HOOKreturn(lua_State* L, lua_Debug* pDb);
