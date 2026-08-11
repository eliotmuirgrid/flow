function LUAlistFunctions(Code)
   --print(Code)
   local Functions = {};
   for Name in string.gfind(Code, "([%u_][%w_]*)%s*%(") do
      if (Name:sub(1,7) ~= "COL_VAR" and Name:sub(1,7) ~= "COL_TRC" and Name ~= "COL_FUNCTION") then 
         if (not _G[Name] or debug.getinfo(_G[Name], "S").what ~= "C") then
           table.insert(Functions, Name);
         end 
      end
   end
   return Functions;
end
