COLrequire "FUNCwrite"
COLrequire "FUNCcHeaderTokens"
COLrequire "FUNCcHeader"
COLrequire "DATEhumanPretty"
COLrequire "DATEcomputerPretty"
COLrequire "CODEprefixRemainder"
COLrequire "TEMPLATEfill"
COLrequire "DIRflowCode"
COLrequire "FLOWedit"

local HeaderT=[[
#pragma once
]]
local HeaderB=[[

void @@NAME@@();
]]

local Body=[[

#include "@@NAME@@.h"
#include "COLtrace.h"
COL_TRACE_INIT;

void @@NAME@@(){
   COL_FUNCTION(@@NAME@@);

}
]]

function FUNCc(Args)
   local Name = Args[3]; 
   if (not Name) then
      print("Need a name of the function.");
      return;
   end
   local Tokens = {}
   FUNCcHeaderTokens(Tokens, Name);
   COL_VAR(Tokens);
   local HContent = TEMPLATEfill(HeaderT..FUNCcHeader(Name)..HeaderB,Tokens);
   COL_VAR(HContent);
   local Prefix, Remainder = CODEprefixRemainder(Name);
   COL_VAR2(Prefix, Remainder);
   local HName = DIRflowCode()..Prefix.."/"..Prefix..Remainder..".h" 
   local BName = DIRflowCode()..Prefix.."/"..Prefix..Remainder..".cpp" 

   local BContent = TEMPLATEfill(FUNCcHeader(Name)..Body,Tokens);
   COL_VAR(BContent);
   COL_VAR2(HName, BName);
   FUNCwrite(HName, HContent);
   FUNCwrite(BName, BContent);
   print ("Let's edit "..Name);
   FLOWedit(Name);
end
