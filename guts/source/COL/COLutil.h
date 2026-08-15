#pragma once
//-------------------------------------------------------
// Copyright (C) 2021 Eliot Muir.  All Rights Reserved
//
// COLutil
//
// MAX/MIN macros etc.
//-------------------------------------------------------

#define COL_MAX(A, B) ((A) > (B) ? (A) : (B))
#define COL_MIN(A, B) ((A) < (B) ? (A) : (B))

void COLsleep(int Milliseconds);
