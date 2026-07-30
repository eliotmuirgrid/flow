function FLOWstripTrailingL(Name)
   local Length = Name:len()
   if Length > 0 and Name:sub(Length, Length) == "L" then
      return Name:sub(1, Length - 1)
   end
   return Name
end
