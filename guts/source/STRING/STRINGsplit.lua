function STRINGsplit(String, Delimiter)
   local Result = {}
   COL_VAR(String, Delimiter);
   local Start = 1
   while true do
      local First, Last = string.find(String, Delimiter, Start, true)

      if not First then
         table.insert(Result, string.sub(String, Start))
         break
      end

      table.insert(Result, string.sub(String, Start, First - 1))
      Start = Last + 1
   end
   COL_VAR(Result);
   return Result
end
