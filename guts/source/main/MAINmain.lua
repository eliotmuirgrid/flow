require ("COL/COLtrace");
COLrequire("INIload");

function MAINmain(Arg)
   COL_VAR(Arg); 
   local Commands=INIload("/zip/guts/source/MAIN/commands.txt");
   COL_VAR(Commands);
   if not Commands[Arg[2]] then
      print "Please use a supported command:"
      for K, _ in pairs(Commands) do
         print("   "..K);
      end
      return;
   end
   COLrequire(Commands[Arg[2]]);
   _G[Commands[Arg[2]]](Arg);
end
