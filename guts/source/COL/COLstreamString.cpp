//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Thursday 13th August 2026
//       0x6A7DD4CF seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "COLstreamString.h"
#include "COLsinkString.h"
#include "COLtrace.h"
COL_TRACE_INIT;

COLstreamString::COLstreamString() : COLstream(new COLsinkString(&m_String), true) {}
COLstreamString::~COLstreamString() {}
