function FINDlinks(Dir)
   local Depends = {}
   FINDiterate(DIRflowCode(), Depends);
   COL_VAR(Depends);
   local Count = 1;
   for Func, Deps in pairs(Depends) do
      Count = Count + 1;
      local Content = '';
      for Caller, _ in pairs(Deps) do
         Content=Content..Caller.."\n" 
      end
      local FileName = FLOWfileIn(Func);
      COL_VAR(Content, FileName);
      FILEwrite(FileName, Content);
   end   
   print ("Functions analysed: "..Count);
end
