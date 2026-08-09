function COMMANDremove(Command)
   if not Command then
      print "Supply a command to add";
      return;
   end
   print("Removing command: "..Command);
   LISTconfigRemove("MAINcommands", Command.."Command");
   FLOWdelete(Command.."Command");
end
