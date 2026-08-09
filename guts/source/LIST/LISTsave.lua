function LISTsave(Name, List)
   local FileName = LISTconfigName(Name);
   local Content = table.concat(List, "\n");
   COL_VAR(Content)
   COL_VAR("Written to :"..FileName);
   FUNCwrite(FileName, Content, true);
end
