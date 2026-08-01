COLrequire 'LISTload'
COLrequire 'LISTremove'
COLrequire 'LISTsave'

function LISTconfigRemove(Config, Item)
   local List =  LISTload(Config);
   LISTremove(List, Name);
   LISTsave(Config, List);
end
