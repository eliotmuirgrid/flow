local TEMPLATE_PROMPT=[[
Determine whether the Lua function body contains code.
Answer EMPTY after ignoring whitespace, comments, and COL_VAR, COL_TRC and COL_FUNCTION instrumentation statements,
there are zero statements or calls to other functions within the function body.
If you say EMPTY explain your reasoning.
Otherwise answer IMPLEMENTED.

Here is the code:

@@BODY@@
]]

function FUNCisEmptyLua(FuncName, Model)
   COL_VAR(FuncName);
   local Depends = {}
   LUArequire(FuncName, Depends);
   Depends[FuncName] = nil;
   COL_VAR(Depends);
   if (next(Depends)) then
      COL_TRC("Dependencies exist so this function is not empty.");
      return false;
   end   
   local FileName = FLOWfileLua(FuncName);
   COL_VAR(FileName);
   local Tokens={}
   Tokens.BODY = FILEread(FileName);
   local Prompt = TEMPLATEfill(TEMPLATE_PROMPT, Tokens);
   COL_VAR(Prompt);
   local Result = AGENTlocal(Prompt, Model);
   COL_VAR(Result);
   if Result:find("EMPTY") then
      return true, Tokens.BODY..Result;
   else
      return false;
   end
end
