COLrequire 'LISTconfigRemove'
COLrequire 'FUNClua'
COLrequire 'FLOWdelete'

function COMMANDremove(Command)
   if not Command then
      print "Supply a command to add";
      return;
   end
   print("Removing command: "..Command);
   LISTconfigRemove("MAINcommands", Command);
   FLOWdelete(Command);
end
