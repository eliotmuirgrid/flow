function VIMbind()
   local List = COMMANDlist("VIMcommands")

   for _, FuncName in pairs(List) do
      print(FuncName)
      vim.api.nvim_create_user_command(FuncName, function()
         VIMcall(FuncName)
      end, {})
   end

   vim.api.nvim_create_autocmd("CmdUndefined", {
      pattern = "*",
      callback = function(T)
         local Name = T.match

         vim.api.nvim_create_user_command(Name, function()
            print("FLOW handled " .. Name)
         end, {})
      end
   })
end

VIMbind()
vim.api.nvim_create_user_command("Hello", function() print("FLOW handled") end, {});

VIMbind()
