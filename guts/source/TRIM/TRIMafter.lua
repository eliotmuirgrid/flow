function TRIMafter(Haystack, Needle)
   local Pos = STRINGfindReverse(Haystack, Needle);
   return Haystack:sub(1, Pos-1);
end
