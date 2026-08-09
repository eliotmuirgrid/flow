function INCLUDEreduce()
   local Dir = DIRflowCode();
   local I = DIRlist(Dir);
   for i =1, table.getn(I) do
      if not DSstoreDelete(Dir, I[i]) and I[i] ~= "makefile" then
         INCLUDEsearch(Dir..I[i]);
      end
   end	
end
