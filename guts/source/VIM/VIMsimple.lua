vim.api.nvim_create_autocmd("CmdUndefined", {pattern = "*", callback = 
function(T)
   LUAload('COMMANDlist');
   LUAload('VIMsimpleCall');
   local List = COMMANDlist("VIMcommands");
   print(List);
   COL_TRC("Hello!");
   print("CREATE:"..T.match)
   vim.api.nvim_create_user_command(T.match, function() local Result = VIMsimpleCall(); print(T.match.." gives "..Result) end, {});
end
});
