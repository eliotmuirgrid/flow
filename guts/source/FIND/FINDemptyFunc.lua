function FINDemptyFunc(Dir, Model)
   local List = DIRlist(DIRflowCode()..Dir);
   COL_VAR(List);
   for i =1, table.getn(List) do
      if FILEextension(List[i]) == "lua" then 
         local Empty, Body = FUNCisEmptyLua(List[i]:sub(1, List[i]:len()-4), Model);
         if Empty then
            print ("[L+]"..List[i]);
            print(Body);
         end
      elseif FILEextension(List[i]) == "cfpp" then 
         local Empty, Body = FUNCisEmptyCpp(List[i]:sub(1, List[i]:len()-4), Model);
         if Empty then
            print ("[C+]"..List[i]);
            print(Body);
         end
      end
   end   
end
