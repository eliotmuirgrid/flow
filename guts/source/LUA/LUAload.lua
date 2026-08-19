require 'DIR/DIRflowCode'
require 'FLOW/FLOWbase'
require 'FLOW/FLOWfile'
require 'FLOW/FLOWfileLua'
require 'FILE/FILEread'
require 'LUA/LUAremoveSingleLineComments'
require 'LUA/LUAcommentRemove'
require 'LUA/LUArequire'
require 'LUA/LUAinstallFunc'
require 'LUA/LUAfunctionList'
require 'LUA/LUAstringRemove'
require 'LUA/LUAdependencies'
require 'PREFIX/PREFIXget'

function LUAload(FunctionName)
   COL_VAR(FunctionName);
   local Funcs = {};
   Funcs.COL_VAR       = true
   Funcs.COL_TRC       = true
   Funcs.COL_FUNCTION  = true
   LUArequire(FunctionName, Funcs)
   COL_VAR(Funcs);
   for FuncName,_ in pairs(Funcs) do
      LUAinstallFunc(FuncName)
   end
end
