require ("COL/COLtrace");
COLrequire "FILEreadLines";
COLrequire "COMMANDlist";

function MAINmain(Arg)
   COL_VAR(Arg); 
   local Functions =FILEreadLines("/zip/guts/source/MAIN/MAINcommands.config");
   COL_VAR(Functions);
   local Commands = COMMANDlist(Functions);
   local Action = Arg[2];
   if (Action and Commands[Action]) then
      COLrequire(Commands[Action]);
      _G[Commands[Action]](Arg);
      return
   end
   
   COL_TRC("TODO put into helper");
   print "Commands recognized:";
   for K, _ in pairs(Commands) do
      print("  "..K);
   end	
end
