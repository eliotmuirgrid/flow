COLrequire 'LISTconfigName'
COLrequire 'FILEreadLines'

function LISTload(Name)
   local FileName = LISTconfigName(Name)
   print(FileName);
   local List = FILEreadLines(FileName);
   return List;
end
