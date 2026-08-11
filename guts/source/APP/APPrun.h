#pragma once
//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Monday 10th August 2026
//       0x6A79D2D0 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "COLbase.h"
typedef struct lua_State lua_State;

void APPrun(lua_State* L, const COLstring& Func, const COLarray<COLstring>& Args);
