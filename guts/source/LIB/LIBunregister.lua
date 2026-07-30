COLrequire "DIRflowCode"
COLrequire "FILEreadLines"
COLrequire "LISTremove"
COLrequire "FLOWdeleteFile"
COLrequire "FUNCwrite"
COLrequire "LIBregenerate"



function LIBunregister(Name)
   print("Unregistering the function: "..Name);
   -- Code to load the list and add the new name.
   local ConfigFile=DIRflowCode().."LIB/LIBlist.config"
   local List = FILEreadLines(ConfigFile);
   LISTremove(List, Name);
   FLOWdeleteFile(ConfigFile);
   FUNCwrite(ConfigFile, table.concat(List, "\n"));
   LIBregenerate();
end
