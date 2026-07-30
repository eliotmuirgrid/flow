COLrequire "FLOWedit"

function FLOWeditCommand(Arg)
   COL_VAR(Arg)
   local FName = Arg[3];
   if (not FName) then
      print "Please supply a name of a function.";
      return;
   end
   FLOWedit(FName);
end
