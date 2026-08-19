function LUAfunctionList(FuncName)
   local File = FLOWfileLua(FuncName)
   if not FILEexists(File) then
      return {} 
   end
   local Code = FILEread(File)
   COL_TRC("Raw:"..Code)
   Code = LUAremoveSingleLineComments(Code);
   COL_TRC("After removing single line comments:"..Code)
   Code = LUAstringRemove(Code)
   COL_TRC("After string:"..Code)
   Code = LUAcommentRemove(Code)
   COL_TRC("After comments:"..Code)
   COL_VAR(Code)
   local List = {}
   for Depend in string.gfind(Code, "([%u_][%w_]*)%s*%(") do
      List[Depend] = true;
   end
   List[FuncName] = nil;
   return List;
end
