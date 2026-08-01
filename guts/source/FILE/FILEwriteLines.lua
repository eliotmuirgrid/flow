COLrequire 'FILEwrite'

function FILEwriteLines(FileName, Lines)
   local Content = table.concat(Lines, "\n"); 
   --print(FileName, Content);
   FILEwrite(FileName,Content);
end
