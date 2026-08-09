function COMMANDlist(List)
   local Out = {}
   for i=1, table.getn(List) do
      Out[COMMANDtranslate(List[i])] = List[i];
   end
   return Out;
end
