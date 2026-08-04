function STRINGstartsWith(Str, With)
   COL_VAR(Str, With);
   if Str:sub(1, With:len()) == With then
      COL_TRC(Str.." starts with "..With);
      return true;
   else
      COL_TRC(Str.." doesn not start with "..With);
      return false
   end
end
