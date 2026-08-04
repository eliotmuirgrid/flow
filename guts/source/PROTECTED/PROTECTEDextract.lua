function PROTECTEDextract(Content)
   local Protected = {}
   local Output = {}
   local Position = 1
   local Length = string.len(Content)

   while Position <= Length do
      local Character = string.sub(Content, Position, Position)

      if Character == '"' or Character == "'" then
         local Quote = Character
         local Start = Position

         Position = Position + 1

         while Position <= Length do
            Character = string.sub(Content, Position, Position)

            if Character == "\\" then
               Position = Position + 2
            elseif Character == Quote then
               Position = Position + 1
               break
            else
               Position = Position + 1
            end
         end

         local Text = string.sub(Content, Start, Position - 1)

         table.insert(Protected, Text)

         local Marker =
            "@@PROTECTED"..tostring(table.getn(Protected)).."@@"

         table.insert(Output, Marker)
      else
         table.insert(Output, Character)
         Position = Position + 1
      end
   end

   return table.concat(Output), Protected
end
