function AIfindFunc(Purpose)
   COL_VAR(Purpose);
   local List = DIRlist(DIRflowCode());
   COL_VAR(List);
   local Prompt =[[
I am looking for a directory which will have code
for the purpose: ]]..Purpose..[[

These directories contain custom Lua and C++ code.  Do not assume
that they contain library code from third parties.

Name only two directories that you will look in first.

]]
   for i=1, table.getn(List) do
      Prompt = Prompt..List[i].."\n";
   end
   COL_VAR(Prompt);
   local Response = AGENTlocal(Prompt);
   print(Response)
end
