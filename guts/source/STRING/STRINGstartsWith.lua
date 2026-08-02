function STRINGstartsWith(Str, With)
   COL_VAR(Str, With);
   if Str:sub(1, With:len()) == With then
      print(Str.." starts with "..With);
      return true;
   else
      print(Str.." doesn not start with "..With);
      return false
   end
end
