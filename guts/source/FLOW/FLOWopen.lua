COLrequire 'OSexecute'
COLrequire 'TEMPLATEfill'

local NEOVIM_TEMPLATE=[[
LUA_PATH="@@PATH@@" \
nvim -c "set tabstop=3 shiftwidth=3 softtabstop=3 expandtab" \
     -c "lua require('boot')" @@NAME@@
]];


function FLOWopen(Name)
   if (FILEexists(Name)) then
      -- TODO come back and unify on flow with the Neovim extensions
      -- MESSY MESSY MESSY - LAZY ELIOT
      local Tokens = {}
      Tokens.PATH = ENVget("HOME").."/flowshell/nvim/?.lua";
      Tokens.NAME = Name
      local Command = TEMPLATEfill(NEOVIM_TEMPLATE, Tokens);
      COL_VAR(Command)
      OSexecute(Command);
      return true;
   else
      print("Unable to open "..Name); 
   end
end

