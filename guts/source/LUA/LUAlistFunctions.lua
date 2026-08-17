function LUAlistFunctions(Code, Funcs)
   COL_VAR(Code)
   for FuncName in string.gfind(Code, "([%u_][%w_]*)%s*%(") do
      if FuncName:sub(1,4) ~= "COL_" then
	 if not Funcs[FuncName] then LUArequire(FuncName, Funcs); end;     
      end
   end
end
