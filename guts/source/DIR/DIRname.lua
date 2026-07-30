function DIRname(Path)
   for i = Path:len(), 1, -1 do
      local c = string.byte(Path, i)
      if c == 47 or c == 92 then  -- / or \
         return Path:sub(1, i - 1)
      end
   end
   return "."
end
