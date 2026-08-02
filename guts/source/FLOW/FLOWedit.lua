COLrequire 'PREFIXget'
COLrequire 'DIRflowCode'
COLrequire 'FLOWopen'
COLrequire 'FLOWeditPress'
COLrequire 'STRINGstartsWith'

function FLOWedit(FName)
   if FName == "commands.txt" then  -- TODO Flow is not architecturally proud - we do what makes thing flow in immediately and keep going
      FLOWopen(DIRflowCode().."MAIN/commands.txt");
      return
   end
   local WebRoot = "https://interfaceware.com/"
   if STRINGstartsWith(FName, WebRoot) then
      print("Flow is about now");
      FLOWeditPress(FName:sub(WebRoot:len(), FName:len()));
      return;
   end
   local Ext = FILEextension(FName);
   if (Ext:len() > 0) then
      FName = FName:sub(1, FName:len()-Ext:len()-1);
      COL_VAR("Stripped extension: "..FName);
   end

   local P = PREFIXget(FName);
   local B = DIRflowCode()..P.."/"..FName;
   local LFile = B..".lua";
   local CFile = B..".cpp";
   local HFile = B..".h";

   if (not FILEexists(LFile) and not FILEexists(CFile)) then
      print ("Do you need mental health care?  That function "..FName.." does not exist.");
      print ("I checked:");
      print (LFile)
      print (CFile)
      return;
   end
   if (FILEexists(LFile)) then FLOWopen(LFile) end
   if (FILEexists(CFile)) then FLOWopen(CFile) end
   if (FILEexists(HFile)) then FLOWopen(HFile) end
end
