-- Hard to find and I am confused about whether this is a command or a helper function?
function FLOWlistC(Prefix)
   if (not Prefix) then
      print("Give a prefix like LIST or something");
      return;
   end
   local Dir = DIRflowCode().."/"..Prefix;

   if not FILEexists(Dir) then
      print(Prefix.." does not exist.");
      return;
   end 
   local L = DIRlist(Dir);
   local CList = {}
   for i=1, TABLEsize(L) do
      if FILEextension(L[i]) == "cpp" then
	      local Item = L[i]:sub(1, L[i]:len()-4);
	      TABLEpush(CList, Item);
      end
   end
   return CList;
end
