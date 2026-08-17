function HELPcommands()
   local Commands = COMMANDlist("MAINcommands");
   print "Commands recognized:";
   local C = TABLEkeys(Commands);
   for i=1, TABLEsize(C) do
      print("  "..C[i]);
   end	
end;
