function FILEreadLines(Name)
   local Content = FILEread(Name);
   COL_VAR(Name, Content);
   return SPLITlines(Content);
end
