COLrequire 'FUNCwrite'
COLrequire 'LISTconfigName'

function LISTsave(Name, List)
   local FileName = LISTconfigName(Name);
   FUNCwrite(FileName, table.concat(List, "\n"), true);
end
