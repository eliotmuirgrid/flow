function LISTconfigAdd(Config, Item)
   local List =  LISTload(Config);
   LISTaddUnique(List, Item);
   LISTsave(Config, List);
end
