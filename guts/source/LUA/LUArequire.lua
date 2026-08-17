function LUArequire(FuncName, Funcs)
   Funcs[FuncName] = true
   LUAdependencies(FuncName, Funcs);
end
