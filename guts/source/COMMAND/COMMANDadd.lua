COLrequire 'LISTconfigAdd'
COLrequire 'FUNClua'
COLrequire 'FUNCluaCommandShell'

function COMMANDadd(Command)
   if not Command then
      print "Supply a command to add";
      return;
   end
   print("Adding command: "..Command);
   LISTconfigAdd("MAINcommands", Command.."Command");
   FUNCluaCommandShell(Command);
   FUNClua(Command);
end
