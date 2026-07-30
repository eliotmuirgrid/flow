
function PREFIXget(FName)
   local prefix = ""
   local i = 1
   while i <= FName:len() do
      local byte = FName:byte(i)
      if byte >= 65 and byte <= 90 then -- ASCII A-Z
         prefix = prefix..FName:sub(i,i)
         i = i + 1
      else
         break
      end
   end
   return prefix;
end
