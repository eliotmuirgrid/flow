function LISTremove(List, Value)
   for i, V in ipairs(List) do
      if V == Value then
         table.remove(List, i)
         return
      end
   end
end
