function COMMANDmap(Config, Command)
   COL_VAR(Command);
   local AliasMap = ALIASmap();

   local NormalCommand = COMMANDnormalize(Command, AliasMap);
   COL_VAR("Expected: "..NormalCommand);

   local NormalizedCommands = COMMANDlistNormalize(Config, AliasMap);
   COL_VAR(NormalizedCommands);
   local FuncName =  NormalizedCommands[NormalCommand];
   COL_VAR(FuncName);
   return FuncName;
end
