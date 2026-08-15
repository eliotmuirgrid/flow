//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// To be documented by an AI agent later!
//
// Date: Tuesday 11th August 2026
//       0x6A7B530E seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "LUACdebug.h"
#include "COLtrace.h"
COL_TRACE_INIT;

void LUAdebugOut(COLstream& Stream, const struct lua_Debug& LD){
   COL_FUNCTION(LUAdebugOut);
   Stream << "event=" << LD.event << newline
          << " name=" << (LD.name ? LD.name : "(COLnull)") << newline
          << " namewhat=" << (LD.namewhat ? LD.namewhat : "(COLnull)") << newline
          << " what=" << (LD.what ? LD.what : "(COLnull)") << newline
          << " source=" << (LD.source ? LD.source : "(COLnull)") << newline
          << " short_src=" << LD.short_src << newline
          << " currentline=" << LD.currentline << newline
          << " linedefined=" << LD.linedefined << newline
          << " nups=" << LD.nups << newline;
}

COLstream& operator<<(COLstream& Stream, const struct lua_Debug& LD){
   LUAdebugOut(Stream, LD);
   return Stream;
}
