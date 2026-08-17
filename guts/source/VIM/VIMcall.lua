function VIMcall(CommandName)
   local FileName = vim.fn.expand("%:p")
   local Line     = vim.fn.line(".")
   local Column   = vim.fn.col(".")
   local Data     = VIMbufferGet();
   local LogFile = vim.fn.expand("~/.neovim.log");

   local Result = vim.fn.system({
      "/bin/zsh",
      "-c",
      'exec "$1" "$2" "$3" "$4" "$5" "$6" "$7" "$8"',
      "flow",
      "flow.com",
      "vim:invoke",
      CommandName,
      FileName,
      tostring(Line),
      tostring(Column),
      "--file",
      LogFile, 
      "--trace",
      "VIM* main"
   }, Data)
   VIMbufferSet(Result);
end
