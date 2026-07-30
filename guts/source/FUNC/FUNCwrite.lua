COLrequire "FILEwrite"
COLrequire "DIRname"

function FUNCwrite(FileName, Content)
   local Dir = DIRname(FileName);
   if (not FILEexists(Dir)) then
      print("About to create "..Dir);
      DIRcreate(Dir);
   end
   if (FILEexists(FileName)) then
      print("You dummy - this exists already: "..FileName)
      return;
   end
   FILEwrite(FileName, Content);
   print("Generated: "..FileName)
end

