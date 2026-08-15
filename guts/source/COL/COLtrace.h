#pragma once
//-------------------------------------------------------
// Copyright (C) 2021 Eliot Muir.  All Rights Reserved
//
// COLtrace
// 
// Tracing framework
//
// To use it do:
// #include <COL/COLtrace.h>
// COL_TRACE_INIT;
//
// Then you can use:
//  COL_TRC("This is tracing.");   // Traces to output
//  COL_FUNCTION(myFunctionName);  // Gives entry into a function and out of it
//  COL_METHOD(Foo::MyMethod);     // Gives entry into a method and shows the this pointer and out of it
//  COL_VAR(AVariable);            // Gives name=value of a variable - use COL_VAR2, COL_VAR3 etc. to display 2, 3 variables etc.
//-------------------------------------------------------

#include "COLstream.h"
#include "COLstring.h"
#include "COLtraceTime.h"
#include "COLtraceFuncHelper.h"
#include "COLtraceModule.h"
#include "COLtraceHex.h"
#include "COLtraceEnabled.h"
#include "COLlockGuard.h"

void COLtrace(const char* Pattern);

extern COLstream   COLtraceOut;
extern COLlock     COLtraceLock;
extern const char* COLtracePattern;

#define COL_TRACE_INIT static COLtraceModule COLmod(__FILE__);

#define COL_ERR(X) do                                                                            { COLlockGuard Guard(COLtraceLock); COLtraceTime(COLmod.N, COLtraceOut);COLtraceOut << "ERROR: " << X << newline; } while(0);
#define COL_TRC(X) do { static int On; if (On > 0 || (On == 0 && COLtraceEnabled(COLmod.N, &On))){ COLlockGuard Guard(COLtraceLock); COLtraceTime(COLmod.N, COLtraceOut);COLtraceOut << X << newline;}} while(0);
#define COL_HEX(L, B, S) do { static int On; if (On > 0 || (On == 0 && COLtraceEnabled(COLmod.N, &On))){ COLtraceHex(L, S, B, COLmod.N); } } while(0)

#define COL_VAR(A)        COL_TRC(#A << " = " << A);
#define COL_VAR2(A,B)     COL_TRC(#A << " = " << A << ", " << #B << " = " << B);
#define COL_VAR3(A,B,C)   COL_TRC(#A << " = " << A << ", " << #B << " = " << B << ", " << #C << " = " << C);
#define COL_VAR4(A,B,C,D) COL_TRC(#A << " = " << A << ", " << #B << " = " << B << ", " << #C << " = " << C << ", " << #D << " = " << D);
#define COL_FUNCTION(NAME) static int COLfOn; COLtraceFuncHelper ggFFF(#NAME, COLmod.N, __LINE__,       (COLfOn > 0) || COLtraceEnabled(COLmod.N, &COLfOn));
#define COL_METHOD(NAME)   static int COLfOn; COLtraceFuncHelper ggFFF(#NAME, COLmod.N, __LINE__, this, (COLfOn > 0) || COLtraceEnabled(COLmod.N, &COLfOn));