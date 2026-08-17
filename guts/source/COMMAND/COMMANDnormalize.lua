function COMMANDnormalize(Command, AliasMap)
   local Words = STRINGsplit(Command, ":");
   COL_VAR(Words);
   for i = 1, table.getn(Words) do
      local Map = AliasMap[Words[i]];
      if Map then
         Words[i] = Map;
      end
   end
   COL_VAR(Words);
   SORTalpha(Words);
   COL_VAR(Words);
   local NormalCommand = table.concat(Words, ":");
   COL_VAR(NormalCommand);
   return NormalCommand;
end
