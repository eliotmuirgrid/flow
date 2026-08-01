COLrequire 'LISTconfigAdd'
COLrequire 'FUNClua'

function COMMANDadd(Command)
   if not Command then
      print "Supply a command to add";
      return;
   end
   print("Adding command: "..Command);
   LISTconfigAdd("MAINcommands", Command);
   FUNClua(Command);
end
