function SPLITlines(Content)
   COL_VAR(Content);
   local Lines = {}
   local Pos = 1
   while true do
      local StartPos, EndPos = string.find(Content, "\n", Pos, true)
      if not StartPos then
         local Last = string.sub(Content, Pos)
         if Last ~= "" then
            table.insert(Lines, Last)
         end
         break
      end
      table.insert(Lines, string.sub(Content, Pos, StartPos - 1))
      Pos = EndPos + 1
   end
   return Lines
end
