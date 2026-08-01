#pragma once
//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Lua C Helper
//
// Date: Thursday 30th July 2026
//       0x6A6BD434 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

typedef struct lua_State lua_State;
class COLstring;

void REGtableGet(lua_State* L, const COLstring& Name);
