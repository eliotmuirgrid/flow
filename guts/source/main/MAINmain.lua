require ("COL/COLtrace");
require ("LUA/LUAload");

function MAINmain(Arg)
   LUAload("MAINmain")
   COL_TRC("Starting MAINmain");
   COL_VAR(table.getn(Arg));
   local Commands = COMMANDlist("MAINcommands");
   local Action = Arg[2];
   if (Action and Commands[Action]) then
      COL_TRC("Run: "..Action.." using "..Commands[Action]);
      LUAload(Commands[Action]);
      _G[Commands[Action]](Arg);
      return
   end
   print "Commands recognized:";
   local C = TABLEkeys(Commands);
   for i=1, TABLEsize(C) do
      print("  "..C[i]);
   end	
end
