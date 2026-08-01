#pragma once
//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Thursday 30th July 2026
//       0x6A6C0E2C seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

class COLstream;
typedef struct lua_Debug lua_Debug;

void LUAdebugOut(COLstream& Stream, const struct lua_Debug& LD);

COLstream& operator<<(COLstream& Stream, const struct lua_Debug& LD);
