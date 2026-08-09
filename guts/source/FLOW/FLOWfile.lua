function FLOWfile(FName, Ext)
   local P = PREFIXget(FName);
   local B = DIRflowCode()..P.."/"..FName;
   local FileName = B.."."..Ext;
   return FileName
end
