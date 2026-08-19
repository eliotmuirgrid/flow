local TEMPLATE_PROMPT=[[
Determine whether the C++ pair of files contains executable code.
Answer EMPTY only if, after ignoring whitespace, comments, and 
COL_* instrumentation statements, there are zero executable statements.
Assignments, local declarations with expressions, function calls, if, 
loops, and return all count as executable statements.
Do not judge whether the function is complete, useful, or whether 
logic is delegated to other functions.
If you say EMPTY explain your reasoning.
Otherwise answer IMPLEMENTED.

Here is the code:
@@HEADER@@

// End of header - start of body.

@@BODY@@

]]

function FUNCisEmptyCpp(FuncName, Model)
   COL_VAR(FuncName);
   local HFile = FLOWfileCpp(FuncName);
   COL_VAR(HFile);
   local Tokens={}
   Tokens.HEADER = FILEread(FLOWfileH  (FuncName));
   Tokens.BODY   = FILEread(FLOWfileCpp(FuncName));
   local Prompt = TEMPLATEfill(TEMPLATE_PROMPT, Tokens);
   COL_VAR(Prompt);
   local Result = AGENTlocal(Prompt, Model);
   COL_VAR(Result);
   if Result:find("EMPTY") then
      return true, Tokens.HEADER.."\n\n"..Tokens.BODY..Result;
   else
      return false;
   end
end
