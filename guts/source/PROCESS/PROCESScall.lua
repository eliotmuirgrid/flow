function PROCESScall(CommandArray)
   local Command = table.concat(CommandArray, " ");
   COL_VAR(Command);
   local Pipe = io.popen(Command, "r")
   local Output = Pipe:read("*a")
   Pipe:close()
   COL_VAR(Output)
   return Output
end
