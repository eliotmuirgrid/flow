COLrequire "FILEwrite"

function FUNCwrite(FileName, Content)
   print("Generated: "..FileName)
   FILEwrite(FileName, Content);
end
