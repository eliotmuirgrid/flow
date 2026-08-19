function LUAdependencies(FuncName, Funcs)
   COL_TRC("Dependencies for "..FuncName);
   local FList = LUAfunctionList(FuncName);
   for FuncName,_ in pairs(FList) do
      if not Funcs[FuncName] then
         COL_TRC("Require "..FuncName);
         LUArequire(FuncName, Funcs) 
      end;
   end
end
