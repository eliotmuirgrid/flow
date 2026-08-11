require 'LUA/LUArequire'

function LUAloadFunc(Filename)
   local P = ""
   local i = 1
   while i <= Filename:len() do
      local byte = Filename:byte(i)
      if byte >= 65 and byte <= 90 then -- ASCII A-Z
         P = P..Filename:sub(i,i)
         i = i + 1
      else
         break
      end
   end
   local F = P.."/"..Filename
   local Success, Err = pcall(require,F);
   if (not Success) then
      print("Warning unable to load: "..F);
   end   
end

function LUAload(FName)
   local List = {}
   LUArequire(FName, List);
   --print(COLshow(List));
   for K,V in pairs(List) do
      LUAloadFunc(K);
   end
end
