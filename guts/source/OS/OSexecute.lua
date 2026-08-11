function OSexecute(Command)
   local home = ENVget("HOME")
   if home then
      Command = Command:gsub("~", home)
   end
   return os.execute(Command)
end
