function HTTPpost(T)
   local url     = T.url
   local headers = T.headers
   local data    = T.data 
   local A = {"curl", "-s", url}
   if headers then
      for k, v in pairs(headers) do
         table.insert(A, "-H")
         table.insert(A, k .. ": " .. v)
      end
   end
   if data then
      table.insert(A, "-d")
      table.insert(A, JSONencode(data))
   end
   local Result = Call(A).stdout
   return Result
end
