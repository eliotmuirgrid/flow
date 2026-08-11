#include "LUAlua.h"
#include "LUAdebug.h"

#include "FLAGpresentWithArg.h"
#include "FLAGpresent.h"
#include "APPrun.h"
#include "COLstring.h"
#include "COLstream.h"
#include "COLarray.h"
#include "COLarrayCopy.h"
#include "COLtrace.h"
COL_TRACE_INIT;

int main (int argc, const char** argv) {
   COL_FUNCTION(main);
   COLarray<COLstring> Args;
   COLarrayCopy(argc, argv, &Args);

   bool NoCpp = FLAGpresent("nocpp", &Args);
   COLstring Trace;
   FLAGpresentWithArg("trace", &Trace, &Args);
   bool NoLua = FLAGpresent("nolua", &Args);
   COL_VAR(NoLua);
   
   COLstring Func = "MAINmain";
   FLAGpresentWithArg("func", &Func, &Args);

   lua_State* L = lua_open();
   if (!Trace.empty() && !NoCpp)            { COLtrace(Trace.data());}
   if (!Trace.empty() && !NoLua)            { LUAdebug(L, Trace);    }
   if (!Trace.empty() && (!NoLua && !NoCpp)){ COLheader();           }

   COL_VAR(Func);
   APPrun(L, Func, Args);

   return 0;  // 0 means success.  Nothing is success apparently.
}
