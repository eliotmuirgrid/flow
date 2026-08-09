function FILEread(Name)
   local F, Err = io.open(Name, "r");
   if not F then
      error(DEBUGstackTrace()..Err.." while opening "..Name); 
   end
   local C = F:read("*a");
   F:close()
   return C
end
