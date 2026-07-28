require "FUNC/FUNCwrite"
require "FILE/FILEreadLines"
require "DATE/DATEhumanPretty"
require "DATE/DATEcomputerPretty"
require "LIST/LISTaddUnique"
require "SORT/SORTalpha"
require "TEMPLATE/TEMPLATEfill"

local Body=[[
//----------------------------------------------------------------
// Copyright (C) Eliot Muir @@YEAR@@ All rights reserved.
//
// Implementation
//
// Date: @@HUMAN_DATE@@
//       @@HEX_DATE@@ the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include <LUA/LUAlua.h>
@@INCLUDE_LIST@@
#include <COL/COLtrace.h>
COL_TRACE_INIT;

// This file is auto generated. 
void LIBregister(lua_State* L){
   COL_FUNCTION(LIBregister);
@@REGISTER_LIST@@}
]]

function LIBregister(Name)
   COL_FUNCTION("LIBregister");
   print("Registering the function.");
   local Tokens={
      HUMAN_DATE =DATEhumanPretty(),
      HEX_DATE   =DATEcomputerPretty(),
      YEAR       =os.date("%Y"),
   }
   -- Code to load the list and add the new name.
   local List = FILEreadLines(DIRflowCode().."LIB/LIBlist.config");
   LISTaddUnique(List, Name);
   SORTalpha(List);
   FUNCwrite(DIRflowCode().."LIB/LIBlist.config", table.concat(List, "\n"));

   local IList = '';
   local RList = '';
   for i=1, table.getn(List) do
      local Prefix, Remainder = CODEprefixRemainder(List[i]);
      IList = IList.."#include <"..Prefix.."/"..Prefix..Remainder..".h>\n";
      RList = RList..'   lua_register(L, "'..List[i]..'", '..List[i]..");\n";
   end
   Tokens.INCLUDE_LIST  = IList;
   Tokens.REGISTER_LIST = RList;
   local BContent = TEMPLATEfill(Body,Tokens);
   FUNCwrite(DIRflowCode().."LIB/LIBregister.cpp", BContent);
end
