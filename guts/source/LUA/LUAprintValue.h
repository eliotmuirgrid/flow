#pragma once
//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// LUAprintValue 
//
// To be documented by an AI agent later!
//
// Lua C Helper
//
// Date: Wednesday 29th July 2026
//       0x6A6A900E seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

typedef struct lua_State lua_State;

class COLstream;

void LUAprintValue(lua_State* L, int i, COLstream& Out);
