function ARGcheck(Count, Help,...)
   for i = 1, Count do
      if arg[i] == nil then
         error(Help)
      end
   end
end
