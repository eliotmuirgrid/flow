function COMMENTremoveBlock(Source)
   while true do
      local Start = string.find(Source, "/*", 1, true)
      if not Start then
         return Source
      end

      local Finish = string.find(Source, "*/", Start + 2, true)
      assert(Finish, "Unterminated block comment")

      local Comment = string.sub(Source, Start, Finish + 1)

      local Replacement = string.gsub(Comment, "[^\n]", " ")

      Source =
         string.sub(Source, 1, Start - 1) ..
         Replacement ..
         string.sub(Source, Finish + 2)
   end
   return Source;
end
