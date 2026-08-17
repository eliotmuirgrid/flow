require 'DIR/DIRflowCode'
require 'FLOW/FLOWbase'
require 'FLOW/FLOWfile'
require 'FLOW/FLOWfileLua'
require 'FILE/FILEread'
require 'LUA/LUAremoveSingleLineComments'
require 'LUA/LUAcommentRemove'
require 'LUA/LUArequire'
require 'LUA/LUAinstallFunc'
require 'LUA/LUAlistFunctions'
require 'LUA/LUAstringRemove'
require 'LUA/LUAdependencies'
require 'PREFIX/PREFIXget'

function LUAload(FunctionName)
   COL_VAR(FunctionName);
   local Funcs = {}
   LUArequire(FunctionName, Funcs)
   COL_VAR(Funcs);
   for FuncName,_ in pairs(Funcs) do
      LUAinstallFunc(FuncName)
   end
end
