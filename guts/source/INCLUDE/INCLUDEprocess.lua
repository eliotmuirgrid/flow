COLrequire "FILEreadLines"
COLrequire "FILEwriteLines"
COLrequire "INCLUDEflatten"

function INCLUDEprocess(File)
   local L = FILEreadLines(File)
   for i = 1, table.getn(L) do
      if (L[i]:sub(1, 9) == "#include ") then
	 L[i] = L[i]:gsub("[<>]", '"')
	 L[i] = INCLUDEflatten(L[i]);
      end
   end
   FILEwriteLines(File, L);
end
