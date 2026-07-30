function FILEread(Name)
   local F, Err = io.open(Name, "r");
   if not F then
      error(Err); 
   end
   local C = F:read("*a");
   F:close()
   return C
end
