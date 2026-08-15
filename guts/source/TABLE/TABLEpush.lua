function TABLEpush(List, Value)
   if not Value then 
       error("TABLEpush needs Value to be non COLnull");
   end   
   List[table.getn(List) + 1] = Value
end
