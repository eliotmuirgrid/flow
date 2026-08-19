local ALIASmapInfo = {}

ALIASmapInfo["delete"] = {"remove", "destroy", "erase", "rm", "del"}
ALIASmapInfo["create"] = {"make", "new", "add", "build", "generate"}
ALIASmapInfo["copy"] = {"duplicate", "clone", "cp"}
ALIASmapInfo["move"] = {"relocate", "mv", "rename"}
ALIASmapInfo["read"] = {"open", "fetch", "show", "view"}
ALIASmapInfo["find"] = {"search", "locate", "lookup", "seek"}
ALIASmapInfo["list"] = {"show", "display", "enumerate", "ls"}
ALIASmapInfo["run"] = {"execute", "start", "launch", "exec"}
ALIASmapInfo["stop"] = {"end", "terminate", "kill", "halt"}
ALIASmapInfo["func"] = {"function", "module"}
ALIASmapInfo["restart"] = {"reboot", "reload"}
ALIASmapInfo["enable"] = {"activate", "on"}
ALIASmapInfo["disable"] = {"deactivate", "off"}
ALIASmapInfo["check"] = {"test", "verify", "validate"}
ALIASmapInfo["convert"] = {"transform", "translate"}
ALIASmapInfo["split"] = {"separate", "divide"}
ALIASmapInfo["join"] = {"combine", "merge", "concat", "concatenate"}
ALIASmapInfo["clear"] = {"empty", "reset", "clean"}
ALIASmapInfo["edit"] = {"go", "update", "alter", "change", "modify", "revise"}

function ALIASmap()
   local Map = {}
   for Normal, Aliases in pairs(ALIASmapInfo) do
      Map[Normal] = Normal
      for _, Alias in ipairs(Aliases) do
         Map[Alias] = Normal
      end
   end
   return Map
end
