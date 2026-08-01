function COMMANDcommandStrip(Command)
   local K = "Command";
   if Command:len() < K:len() then
      return Command;
   end
   if Command:sub(Command:len()-K:len()+1, Command:len()) == K then
      return Command:sub(1, Command:len()-K:len());
   end
   return Command;
end	
