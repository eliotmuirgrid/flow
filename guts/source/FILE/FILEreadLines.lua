function FILEreadLines(Name)
   local Content = FILEread(Name);
   COL_VAR2(Name, Content);
   return SPLITlines(Content);
end
