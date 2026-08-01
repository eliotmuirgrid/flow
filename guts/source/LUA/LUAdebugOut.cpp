//----------------------------------------------------------------
// Copyright (C) Eliot Muir 2026 All rights reserved.
//
// Implementation
//
// Date: Thursday 30th July 2026
//       0x6A6C0E2C seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include <LUA/LUAlua.h>
#include <LUA/LUAdebugOut.h>
#include <COL/COLtrace.h>
COL_TRACE_INIT;

void LUAdebugOut(COLstream& Stream, const struct lua_Debug& LD){
   COL_FUNCTION(LUAdebugOut);
   Stream << "event=" << LD.event << newline
          << " name=" << (LD.name ? LD.name : "(null)") << newline
          << " namewhat=" << (LD.namewhat ? LD.namewhat : "(null)") << newline
          << " what=" << (LD.what ? LD.what : "(null)") << newline
          << " source=" << (LD.source ? LD.source : "(null)") << newline
          << " short_src=" << LD.short_src << newline
          << " currentline=" << LD.currentline << newline
          << " linedefined=" << LD.linedefined << newline
          << " nups=" << LD.nups << newline;
}

COLstream& operator<<(COLstream& Stream, const struct lua_Debug& LD){
   LUAdebugOut(Stream, LD);
   return Stream;
}
