COLrequire "FUNCwrite"
COLrequire "FILEreadLines"
COLrequire "LISTaddUnique"
COLrequire "SORTalpha"
COLrequire "LIBregenerate"

function LIBregister(Name)
   COL_FUNCTION("LIBregister");
   print("Registering the function: "..Name);
   -- Code to load the list and add the new name.
   local ConfigFile=DIRflowCode().."LIB/LIBlist.config"
   local List = FILEreadLines(ConfigFile);
   LISTaddUnique(List, Name);
   SORTalpha(List);
   FLOWdeleteFile(ConfigFile);
   FUNCwrite(ConfigFile, table.concat(List, "\n"));
   LIBregenerate();
end
