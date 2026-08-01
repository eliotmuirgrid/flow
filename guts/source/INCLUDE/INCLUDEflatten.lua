function INCLUDEflatten(line)
   local before = line
   local s, e, Inc = line:find('"([^"]+)"')  -- TODO backport match
   if Inc then
      local Slash = Inc:find("/")
      if Slash then
         local Prefix = Inc:sub(1, Slash-1)
         local Name   = Inc:sub(Slash+1)

         if Prefix == Name:sub(1, Prefix:len()) then
            line = line:gsub('"' .. Inc .. '"', '"' .. Name .. '"')
         end
      end
   end
   COL_VAR(line);
   print (line);
   return line;
end
