COLrequire "INCLUDEprocess"

function INCLUDEsearch(Dir)
   print (Dir);
   local I = DIRlist(Dir)
   for i =1, table.getn(I) do
      local Name = I[i];
      local E = FILEextension(Name);
      if (E == "h" or E == "cpp") then
         INCLUDEprocess(Dir.."/"..Name);
      end
   end 
end
