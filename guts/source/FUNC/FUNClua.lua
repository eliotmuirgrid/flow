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
   local BName = FLOWfileLua(Name);
   local BContent = TEMPLATEfill(Body,Tokens);
   COL_VAR(BContent);
   FUNCwrite(BName, BContent);
   FLOWedit(Name);
end
