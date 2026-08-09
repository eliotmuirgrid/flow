function FLOWlist(Prefix)
   if (not Prefix) then
      print("Give a prefix like LIST or something");
      return;
   end
   local Dir = DIRflowCode().."/"..Prefix;

   --local DList = DIRlistWild(Dir);
   --print (COLshow(DList));
   if not FILEexists(Dir) then
      print(Prefix.." does not exist.");
      return;
   end 
   local L = DIRlist(Dir);
   for i=1, TABLEsize(L) do
      if FILEextension(L[i]) == "lua" then
	 print("[L+] "..L[i]:sub(1, L[i]:len()-4));
      end
   end
   local C = LIBcList();
   for i=1, TABLEsize(C) do
      if (C[i]:sub(1, Prefix:len()) == Prefix) then
         print("[C+] "..C[i]);
      end
   end
end
