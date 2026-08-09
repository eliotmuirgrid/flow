require 'FLOW/FLOWfileLua'
require 'FILE/FILEread'
require 'LUA/LUAcommentRemove'
require 'LUA/LUAlistFunctions'
require 'PREFIX/PREFIXget'
require 'DIR/DIRflowCode'

function LUArequire(Name, List)
   if (List[Name]) then
      return;
   end

   List[Name] = true;

   local File = FLOWfileLua(Name);
   local Content = FILEread(File);
   local Simple = LUAcommentRemove(Content);
   local Funcs = LUAlistFunctions(Simple);
   for _, Func in ipairs(Funcs) do
      LUArequire(Func, List);
   end
end
