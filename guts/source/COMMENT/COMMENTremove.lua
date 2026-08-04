function COMMENTremove(Content)
   local Output = {}
   local Position = 1
   local Length = string.len(Content)

   while Position <= Length do
      local Character = string.sub(Content, Position, Position)
      local Next = string.sub(Content, Position + 1, Position + 1)

      -- Remove // comments, but keep the terminating newline.
      if Character == "/" and Next == "/" then
         local Finish = string.find(Content, "\n", Position + 2, true)

         if Finish then
            table.insert(Output, "\n")
            Position = Finish + 1
         else
            break
         end

      -- Remove /* ... */ comments completely.
      elseif Character == "/" and Next == "*" then
         local Finish = string.find(Content, "*/", Position + 2, true)
         assert(Finish, "Unterminated block comment")
         Position = Finish + 2

      else
         table.insert(Output, Character)
         Position = Position + 1
      end
   end

   local Result = table.concat(Output)

   -- Remove runs of blank lines left behind.
   while true do
      local NewResult, Count =
         string.gsub(Result, "\n%s*\n", "\n")

      Result = NewResult

      if Count == 0 then
         break
      end
   end

   return Result
end
