#pragma once
//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// REGkeySet 
//
// To be documented by an AI agent later!
//
// Lua C Helper
//
// Date: Wednesday 29th July 2026
//       0x6A6A93EB seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

typedef struct lua_State lua_State;
class COLstring;

void REGkeySet(lua_State* L, const COLstring& Key, const COLstring& Value);