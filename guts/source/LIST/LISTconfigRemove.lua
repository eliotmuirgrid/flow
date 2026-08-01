COLrequire 'LISTload'
COLrequire 'LISTremove'
COLrequire 'LISTsave'

function LISTconfigRemove(Config, Item)
   local List =  LISTload(Config);
   LISTremove(List, Item);
   LISTsave(Config, List);
end
