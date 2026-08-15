#pragma once
/*************************
 * Copyright (C) Eliot Muir Forever
 *
 * Date: Wed  1 Jul 2026 06:17:53 EST
 **************************/

class COLstring;
typedef struct lua_State lua_State;

void LUAdebug(lua_State* L, const COLstring& Trace);
