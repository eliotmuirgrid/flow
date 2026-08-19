function FINDlinkOutFileGenerate(FuncName, Depends)
   COL_VAR(FuncName);
   local List = LUAfunctionList(FuncName);
   COL_VAR(List);
   local Content=''
   for DepFunc, _ in pairs(List) do
      Content=Content..DepFunc.."\n";
      if not Depends[DepFunc] then Depends[DepFunc] = {} end
      Depends[DepFunc][FuncName] = true;
   end
   local FileName= FLOWfileOut(FuncName);
   COL_VAR(Content);
   COL_VAR(FileName);
   FILEwrite(FileName, Content);
end
