function LISTload(Name)
   local FileName = LISTconfigName(Name)
   COL_VAR(FileName);
   local List = FILEreadLines(FileName);
   COL_VAR(List);
   return List;
end
