COLrequire 'DSstoreDelete'

function MDlinkFind(Dir, Base, Paths)
   local Base = Base or '/';
   local Paths = Paths or {};
   COL_VAR2(Dir, Base)
   local C = DIRlist(Dir);
   COL_VAR(C)
   for i, File in ipairs(C) do
      DSstoreDelete(Dir, File);
      if (File == "i.md") then
         table.insert(Paths, Base);
      elseif (FILEextension(File) == "md") then
	 table.insert(Paths, Base..File.sub(1, File:len()-3));    
      end
   end
   COL_VAR(Paths);
   print(Paths);
end
