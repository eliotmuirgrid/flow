#include "LUAlua.h"
#include "LUAdebug.h"
#include "LUAdebugOff.h"
#include "CRASHenable.h"
#include "FLAGpresentWithArg.h"
#include "FLAGpresent.h"
#include "APPrun.h"
#include "COLstring.h"
#include "COLstream.h"
#include "COLarray.h"
#include "COLarrayCopy.h"
#include "COLtraceHeader.h"
#include "COLtraceFile.h"
#include "COLtrace.h"
COL_TRACE_INIT;

int main (int argc, const char** argv) {
   COL_FUNCTION(main);
   CRASHenable();
   COLarray<COLstring> Args;
   COLarrayCopy(argc, argv, &Args);

   bool NoLua = FLAGpresent("nolua", &Args);
   bool NoCpp = FLAGpresent("nocpp", &Args);

   COLstring TraceFile;
   if (FLAGpresentWithArg("file", &TraceFile, &Args)){ COLtraceFile(TraceFile); }

   COLstring Trace;
   FLAGpresentWithArg("trace", &Trace, &Args);
   
   COLstring Func = "MAINmain";
   FLAGpresentWithArg("func", &Func, &Args);

   lua_State* L = lua_open();
   if (!Trace.empty() && !NoCpp)            { COLtrace(Trace.data()); }
   if (!Trace.empty() && !NoLua)            { LUAdebug(L, Trace);     } 
   else                                     { LUAdebugOff(L);         }
   if (!Trace.empty() && (!NoLua && !NoCpp)){ COLtraceHeader();       }
   COL_VAR4(NoCpp, NoLua, TraceFile, Func);
   APPrun(L, Func, Args);

   return 0;  // 0 means success.  Nothing is success apparently.
}
