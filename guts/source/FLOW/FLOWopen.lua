COLrequire 'OSexecute'

function FLOWopen(Name)
   if (FILEexists(Name)) then
      -- TODO come back and unify on flow with the Neovim extensions
      -- MESSY MESSY MESSY - LAZY ELIOT
      local Path = ENVget("HOME").."/flowshell/nvim/?.lua"; 
      OSexecute([[LUA_PATH=]]..Path..[[ nvim -c "lua require('boot')" ]]..Name);
      return true;
   else
      print("Unable to open "..Name); 
   end
end

