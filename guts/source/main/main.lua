require ("COL/COLtrace");
COLrequire("INIload");

function main(Arg)
   local Commands=INIload("commands.txt");
   if not Commands[Arg[2]] then
      print "Please use a supported command:"
      for K, _ in pairs(Commands) do
         print("   "..K);
      end
      return;
   end
   print ("Execute "..Commands[Arg[2]]);
   COLrequire(Commands[Arg[2]]);
   _G[Commands[Arg[2]]](Arg);
end
