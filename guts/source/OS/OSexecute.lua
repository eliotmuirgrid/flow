COLrequire 'ENVget'

function OSexecute(Command)
   -- Replace any "~" with the user's home directory
   local home = ENVget("HOME")
   if home then
      Command = Command:gsub("~", home)
   end
   -- Execute the command
   return os.execute(Command)
end
