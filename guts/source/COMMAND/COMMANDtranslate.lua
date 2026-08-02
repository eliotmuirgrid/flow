COLrequire 'STRINGtoLower'
COLrequire 'STRINGisUpper'
COLrequire 'COMMANDcommandStrip'
COLrequire 'PREFIXget'

function COMMANDtranslate(Command)
   local Orig = Command;
   Command = COMMANDcommandStrip(Command);
   local Prefix = PREFIXget(Command);
   local Out = '';
   if Prefix ~= 'FLOW' then  -- FLOW is special!
      Out=STRINGtoLower(Prefix)..":"
   end
   Command = Command:sub(Prefix:len()+1, Command:len());
   for i=1, Command:len() do  -- not super efficient shrug
      local Char = Command:sub(i, i);
      if STRINGisUpper(Char) then 
         Out=Out..":" 
	 Out=Out..STRINGtoLower(Char);
      else
	 Out=Out..Char;
      end
   end
   COL_VAR(Orig.." -> "..Out);
   return Out;
end
