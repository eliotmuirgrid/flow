COLrequire "FUNCwrite"
COLrequire "PREFIXget"
COLrequire "TEMPLATEfill"
COLrequire "DIRflowCode"
COLrequire "FLOWedit"

local Body=[[
function @@NAME@@()

end
]]

function FUNClua(Name)
   if (not Name) then
      print("Need a name of the function.");
      return;
   end	
   local Tokens={NAME=Name}
   COL_VAR(Tokens);
   local Prefix = PREFIXget(Name);
   COL_VAR2(Prefix, Remainder);
   local Dir   = DIRflowCode()..Prefix;
   local BName = Dir.."/"..Name..".lua" 
   local BContent = TEMPLATEfill(Body,Tokens);
   COL_VAR(BContent);
   FUNCwrite(BName, BContent);
   FLOWedit(Name);
end
