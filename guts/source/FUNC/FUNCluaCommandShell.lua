local Body=[[
function @@NAME@@Command(Arg)
   @@NAME@@(Arg[3])
end
]]

function FUNCluaCommandShell(Name)
   if (not Name) then
      print("Need a name of the function.");
      return;
   end	
   local Tokens={NAME=Name}
   COL_VAR(Tokens);
   local Prefix = PREFIXget(Name);
   COL_VAR2(Prefix, Remainder);
   local Dir   = DIRflowCode()..Prefix;
   local BName = Dir.."/"..Name.."Command.lua" 
   local BContent = TEMPLATEfill(Body,Tokens);
   COL_VAR(BContent);
   FUNCwrite(BName, BContent);
   FLOWedit(Name.."Command");
end
