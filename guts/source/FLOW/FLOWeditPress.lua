function FLOWeditPress(Path)
   local FullPath = ENVget("HOME").."/press"..Path..".md";
   print(FullPath);

   if FILEexists(FullPath) then
      print ("This exists!");
      FLOWopen(FullPath);
   else
      print ("This doesn't exist!");
   end
end
