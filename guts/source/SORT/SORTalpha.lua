function SORTalpha(T)
   table.sort(T, function(a, b)
      return string.lower(a) < string.lower(b)
   end)
end
