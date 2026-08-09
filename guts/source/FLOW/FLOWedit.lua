function FLOWedit(FName)
   if not FName         then FLOWopen("i.md", true); return; end
   if FILEexists(FName) then FLOWopen(FName);  return; end
   local WebRoot = "https://interfaceware.com/"
   if STRINGstartsWith(FName, WebRoot) then
      print("Flow is about now");
      FLOWeditPress(FName:sub(WebRoot:len(), FName:len()));
      return;
   end
   local Ext = FILEextension(FName);
   print(Ext)
   if (Ext == "md") then FLOWopen(FName, true); return; end;

   if (Ext:len() > 0) then
      FName = FName:sub(1, FName:len()-Ext:len()-1);
      COL_VAR("Stripped extension: "..FName);
   end

   local LFile = FLOWfileLua(FName);
   local CFile = FLOWfileCpp(FName);
   local HFile = FLOWfileH(FName);
   local ConfigFile = FLOWfileConfig(FName);
 
   print(LFile);
   if (FILEexists(LFile)) then FLOWopen(LFile) 
   elseif (FILEexists(CFile)) then FLOWopen(CFile); FLOWopen(HFile); 
   elseif (FILEexists(ConfigFile)) then FLOWopen(ConfigFile) else
      print ("That function "..FName.." does not exist.");
   end
end
