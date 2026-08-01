require ("COL/COLtrace");
COLrequire "LISTload";
COLrequire "COMMANDlist";
COLrequire "TABLEkeys";
COLrequire "TABLEsize";

function MAINmain(Arg)
   COL_VAR(Arg); 
   local Functions =LISTload("MAINcommands");
   COL_VAR(Functions);
   local Commands = COMMANDlist(Functions);
   local Action = Arg[2];
   if (Action and Commands[Action]) then
      print("Run: "..Action.." using "..Commands[Action]);
      COLrequire(Commands[Action]);
      _G[Commands[Action]](Arg);
      return
   end
   
   print "Commands recognized:";
   local C = TABLEkeys(Commands);
   for i=1, TABLEsize(C) do
      print("  "..C[i]);
   end	
end
