#pragma once
//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Tuesday 11th August 2026
//       0x6A7B1BC5 seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------
//
void COLassert(const char *expr, const char *file, int line, const char *func);

#define COLASSERT(X) ((X) ? (void)0 : COLassert(#X, __FILE__, __LINE__, __func__))
