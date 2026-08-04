function STRINGfind(Haystack, Needle)
   local Pos = Haystack:find(Needle);
   COL_VAR(Pos)
   return nil ~= Pos ;
end
