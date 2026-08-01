COLrequire 'SORTalpha'

function LISTaddUnique(List, Value)
   for _, V in ipairs(List) do
      if V == Value then
         return
      end
   end
   table.insert(List, Value)
   SORTalpha(List);
end	
