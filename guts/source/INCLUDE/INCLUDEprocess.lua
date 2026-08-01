COLrequire "FILEreadLines"


function INCLUDEprocess(File)
   local L = FILEreadLines(File)
   for i = 1, table.getn(L) do
      if (L[i]:sub(1, 9) == "#include ") then
         print(L[i])
      end
   end	
end
