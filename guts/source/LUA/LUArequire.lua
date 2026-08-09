require 'FLOW/FLOWfileLua'
require 'FILE/FILEread'
require 'LUA/LUAcommentRemove'
require 'LUA/LUAlistFunctions'
require 'LUA/LUAstringRemove'
require 'PREFIX/PREFIXget'
require 'DIR/DIRflowCode'

function LUArequire(Name, List)
   if (List[Name]) then
      return;
   end

   List[Name] = true;

   local File = FLOWfileLua(Name);
   if (not FILEexists(File)) then
      return;
   end
   local Simple = FILEread(File);
   Simple = LUAstringRemove(Simple);
   Simple = LUAcommentRemove(Simple);
   local Funcs = LUAlistFunctions(Simple);
   for _, Func in ipairs(Funcs) do
      LUArequire(Func, List);
   end
end
