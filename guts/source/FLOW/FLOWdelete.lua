function FLOWdelete(FName)
   local P = PREFIXget(FName);
   local Dir = DIRflowCode()..P.."/"
   local Base = Dir..FName;
   local LFile = Base..".lua";
   local CFile = Base..".cpp";
   local HFile = Base..".h";
   

   if (FILEexists(LFile)) then FLOWdeleteFile(LFile) end
   if (FILEexists(CFile)) then FLOWdeleteFile(CFile) end
   if (FILEexists(HFile)) then FLOWdeleteFile(HFile) end
   LIBunregister(FName);
   if (not FILEexists(Dir)) then
      print(Dir.." already not there - wahoo no work to do!");
      return;
   end
   if (DIRempty(Dir)) then
      if (DIRdelete(Dir)) then
         print ("Deleted: "..Dir);
      else
	 print ("The deletion of "..Dir.." mysteriously failed.  Time to write code to find out why!");
      end
   end
end
