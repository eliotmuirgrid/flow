local NEOVIM_TEMPLATE=[[
LUA_PATH="@@PATH@@" \
neovide --fork @@NAME@@ -- \
     -c "set tabstop=3 shiftwidth=3 softtabstop=3 expandtab" \
     -c "lua require('VIM/VIMportable'); require('LUA/LUAload'); require('VIM/VIMsimple');" \
     -c 'lua vim.o.guifont="Menlo:h18"' 
]];

-- LUAload("VIMbind"); VIMbind();" \
--
function FLOWopen(Name, Create)
   if (not FILEexists(Name) and not Create) then
      print("Unable to open "..Name);
      return;
   end
   local Tokens = {}
   --Tokens.PATH = ENVget("HOME").."/flowshell/nvim/?.lua";
   Tokens.PATH = ENVget("HOME").."/flow/guts/source/?.lua";
   Tokens.NAME = Name
   --Tokens.LINE_COUNT = FILElineCount(Name);
   local Command = TEMPLATEfill(NEOVIM_TEMPLATE, Tokens);
   COL_VAR(Command)
   OSexecute(Command);
   return true;
end

--local NEOVIM_TEMPLATE=[[
--LUA_PATH="@@PATH@@" \
--neovide --fork @@NAME@@ -- \
--     -c "set tabstop=3 shiftwidth=3 softtabstop=3 expandtab" \
--     -c "lua require('VIM/VIMportable'); require('LUA/LUAload'); LUAload('VIMbind');" \
--     -c 'lua vim.o.guifont="Menlo:h18"' 
--]];
