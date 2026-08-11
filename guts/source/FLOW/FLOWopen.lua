local NEOVIM_TEMPLATE=[[
LUA_PATH="@@PATH@@" \
neovide --fork @@NAME@@ -- \
     -c "set tabstop=3 shiftwidth=3 softtabstop=3 expandtab" \
     -c "lua require('boot')" \
     -c 'lua vim.o.guifont="Menlo:h18"' 
]];

-- -c "lua vim.o.lines = @@LINE_COUNT@@"


function FLOWopen(Name, Create)
   if (not FILEexists(Name) and not Create) then
      print("Unable to open "..Name);
      return;
   end
   -- TODO come back and unify on flow with the Neovim extensions
   -- MESSY MESSY MESSY - LAZY ELIOT
   local Tokens = {}
   Tokens.PATH = ENVget("HOME").."/flowshell/nvim/?.lua";
   Tokens.NAME = Name
   --Tokens.LINE_COUNT = FILElineCount(Name);
   local Command = TEMPLATEfill(NEOVIM_TEMPLATE, Tokens);
   COL_VAR(Command)
   OSexecute(Command);
   APPfocus("neovide");
   return true;
end

