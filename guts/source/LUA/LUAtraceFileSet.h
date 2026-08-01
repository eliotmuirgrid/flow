#pragma once
//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Lua C Helper
//
// Date: Tuesday 28th July 2026
//       0x6A68F8AA seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

class COLstring;
typedef struct lua_State lua_State;

void LUAtraceFileSet(lua_State* L, const COLstring& File); // empty to turn off tracing.