function LUAinstallFunc(FuncName)
   local F = PREFIXget(FuncName).."/"..FuncName;
   COL_VAR(F)
   local Success, Err = pcall(require,F);
   if (not Success) then
      COL_VAR("Warning unable to load: "..F);
   end   
end
