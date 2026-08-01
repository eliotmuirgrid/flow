#pragma once
//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Lua C Helper
//
// Date: Thursday 30th July 2026
//       0x6A6BDC61 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

typedef struct lua_State lua_State;
const COLstring;

void STACKpushString(lua_State* L, int i, const COLstring& Value);