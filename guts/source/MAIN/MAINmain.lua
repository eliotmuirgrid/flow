require ("COL/COLtrace");
require ("LUA/LUAload");

function MAINmain(Arg)
   LUAload("MAINmain")
   COL_TRC("Starting MAINmain");
   COL_VAR(table.getn(Arg));
   local Action = Arg[2];
   if (Action) then
      local FuncName = COMMANDmap("MAINcommands", Action);
      if (FuncName) then
         COL_TRC("Run: "..Action.." using "..FuncName);
         LUAload(FuncName);
         _G[FuncName](Arg);
         return
      end
   end
   HELPcommands();
end
