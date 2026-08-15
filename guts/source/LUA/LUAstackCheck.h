#pragma once
//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Lua C Helper
//
// Date: Tuesday 11th August 2026
//       0x6A7B68BC seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

typedef struct lua_State lua_State;

class LUAstackCheck{
public:
   LUAstackCheck(lua_State* L, int Delta = 0);
   ~LUAstackCheck(); 
private:
   lua_State* L;
   int Top;
   int Delta;
};
