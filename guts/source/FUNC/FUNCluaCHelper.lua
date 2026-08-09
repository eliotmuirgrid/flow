local Header=[[
#pragma once
//----------------------------------------------------------------
// Copyright (C) Eliot Muir @@YEAR@@ All rights reserved.
//
// @@EXPLANATION@@
//
// Lua C Helper
//
// Date: @@HUMAN_DATE@@
//       @@HEX_DATE@@ seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

typedef struct lua_State lua_State;

void @@NAME@@(lua_State* L);
]]

local Body=[[
//----------------------------------------------------------------
// Copyright (C) Eliot Muir @@YEAR@@ All rights reserved.
//
// Implementation
//
// Date: @@HUMAN_DATE@@
//       @@HEX_DATE@@ seconds since the beginning of the Unix Epoch time
//       The dawn of our new age. 
// ---------------------------------------------------------------

#include "@@NAME@@.h"
#include "LUAlua.h"
#include "COLtrace.h"
COL_TRACE_INIT;

void @@NAME@@(lua_State* L){
   COL_FUNCTION(@@NAME@@);

}
]]

function FUNCluaCHelper(Args)
   local Name = Args[3]; 
   if (not Name) then
      print("Need a name of the function.");
      return;
   end	
   local Tokens={
      NAME       =Name,
      HUMAN_DATE =DATEhumanPretty(),
      HEX_DATE   =DATEcomputerPretty(),
      YEAR       =os.date("%Y"),
      EXPLANATION="To be documented by an AI agent later!"
   }
   --print("Got Tokens");
   COL_VAR(Tokens);
   local HContent = TEMPLATEfill(Header,Tokens);
   COL_VAR(HContent);
   local Prefix, Remainder = CODEprefixRemainder(Name);
   COL_VAR2(Prefix, Remainder);
   local HName = DIRflowCode()..Prefix.."/"..Prefix..Remainder..".h" 
   local BName = DIRflowCode()..Prefix.."/"..Prefix..Remainder..".cpp" 

   local BContent = TEMPLATEfill(Body,Tokens);
   --print(BContent);
   COL_VAR2(HName, BName);
   FUNCwrite(HName, HContent);
   FUNCwrite(BName, BContent);
   --print ("Now lets edit "..Name);
   FLOWedit(Name);
end
