function HTTPpost(T)
   local url     = T.url
   local headers = T.headers
   local data    = T.data 
   local A = {"curl", "-s", SHELLquote(url)}

   if headers then
      for k, v in pairs(headers) do
         table.insert(A, "-H")
         table.insert(A, SHELLquote(k..": "..v))
      end
   end

   if data then
      table.insert(A, "-d")
      table.insert(A,SHELLquote(JSONencode(data)))
   end

   COL_VAR(A);
   return PROCESScall(A)
end
