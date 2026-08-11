require 'FLOW/FLOWfileLua'
require 'FILE/FILEread'
require 'LUA/LUAcommentRemove'
require 'LUA/LUAlistFunctions'
require 'LUA/LUAstringRemove'
require 'PREFIX/PREFIXget'
require 'DIR/DIRflowCode'

function LUArequire(Name, List)
   List[Name] = true;

   local File = FLOWfileLua(Name);
   if (not FILEexists(File)) then
      return;
   end
   local Simple = FILEread(File);
   COL_VAR(Simple);
   -- TODO this isn't robust enough yet.
   -- We should start with very robust removal
   -- of comments.
   Simple = LUAstringRemove(Simple);
   COL_VAR(Simple);
   Simple = LUAcommentRemove(Simple);
   COL_VAR(Simple);
   local Funcs = LUAlistFunctions(Simple);
   for _, Func in ipairs(Funcs) do
      if (not List[Func]) then
         LUArequire(Func, List);
      end
   end
end
