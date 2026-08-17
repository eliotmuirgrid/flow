function COMMANDlistNormalize(ConfigName, AliasMap)
   local Commands = COMMANDlist(ConfigName);
   COL_VAR(Commands);
   local Map = {}
   for Command, FuncName in pairs(Commands) do
      local NormalCommand = COMMANDnormalize(Command,AliasMap);
      if (Map[NormalCommand]) then error(Command.." creates a collision!"); end;
      Map[NormalCommand] = FuncName;
   end
   COL_VAR(Map);
   return Map;
end
