function LUAinstallFunc(FuncName)
   local F = PREFIXget(FuncName).."/"..FuncName;
   COL_VAR(F)
   if not FILEexists(FLOWfileLua(FuncName)) then
      COL_VAR(FuncName.. " is probably a C+ function");
      return;  
   end   
   local Success, Err = pcall(require,F);
   if (not Success) then
      print("Warning unable to load: "..F.." because of "..Err);
   end   
end
