function LUAremoveSingleLineComments(Text)
   COL_TRC("Code In="..Text);
   local Result = ""
   local Index = 1
   local Length = string.len(Text)
   local Quote = nil
   while Index <= Length do
      local Char = string.sub(Text, Index, Index)
      local Next = string.sub(Text, Index + 1, Index + 1)
      if Quote then
         Result = Result .. Char
         if Char == "\\" then
            Index = Index + 1
            if Index <= Length then
               Result = Result .. string.sub(Text, Index, Index)
            end
         elseif Char == Quote then
            Quote = nil
         end
      elseif Char == "'" or Char == '"' then
         Quote = Char
         Result = Result .. Char
      elseif Char == "-" and Next == "-" then
         Index = Index + 2
         while Index <= Length and string.sub(Text, Index, Index) ~= "\n" do
            Index = Index + 1
         end
         if Index <= Length then
            Result = Result .. "\n"
         end
      else
         Result = Result .. Char
      end
      Index = Index + 1
   end
   COL_TRC("Code Out="..Result);
   return Result
end
