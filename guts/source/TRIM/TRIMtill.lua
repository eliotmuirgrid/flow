function TRIMtill(Haystack, Needle)
   COL_VAR(Haystack, Needle); 
   local Pos = STRINGfind(Haystack, Needle)
   COL_VAR(Pos);
   return Haystack:sub(Pos+Needle:len());
end
