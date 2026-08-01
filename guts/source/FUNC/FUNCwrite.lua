COLrequire "FILEwrite"
COLrequire "DIRname"

function FUNCwrite(FileName, Content, Force)
   local Dir = DIRname(FileName);
   if (not FILEexists(Dir)) then
      print("About to create "..Dir);
      DIRcreate(Dir);
   end
   if (FILEexists(FileName) and not Force) then
      print("Will not overwrite: "..FileName)
      return;
   end
   FILEwrite(FileName, Content);
   print("Generated: "..FileName)
end

