COLrequire "FUNCwrite"
COLrequire "FILEreadLines"
COLrequire "DATEhumanPretty"
COLrequire "DATEcomputerPretty"
COLrequire "TEMPLATEfill"
COLrequire "PREFIXget"
COLrequire "DIRflowCode"
COLrequire "FLOWdeleteFile"
COLrequire "FLOWstripTrailingL"

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

function LIBregenerate()
   COL_FUNCTION("LIBregister");
   local Tokens={
      HUMAN_DATE =DATEhumanPretty(),
      HEX_DATE   =DATEcomputerPretty(),
      YEAR       =os.date("%Y"),
   }
   -- Code to load the list and add the new name.
   local List = FILEreadLines(DIRflowCode().."LIB/LIBlist.config");
   local IList = '';
   local RList = '';
   for i=1, table.getn(List) do
      local Prefix = PREFIXget(List[i]);
      IList = IList.."#include <"..Prefix.."/"..List[i]..".h>\n";
      RList = RList..'   lua_register(L, "'..FLOWstripTrailingL(List[i])..'", '..List[i]..");\n";
   end
   Tokens.INCLUDE_LIST  = IList;
   Tokens.REGISTER_LIST = RList;
   local BContent = TEMPLATEfill(Body,Tokens);
   local RFile = DIRflowCode().."LIB/LIBregister.cpp";
   FLOWdeleteFile(RFile);
   FUNCwrite(RFile, BContent);
end
