function DEBUGstackTrace()
   local Level = 2
   local Result = ""
   while true do
      local Info = debug.getinfo(Level, "Snl")
      if Info == nil then
         break
      end
      local Name = Info.name or "?"
      local Source = Info.short_src or "?"
      local Line = Info.currentline or 0
      Result = Result .. Source .. ":" .. Line .. " in " .. Name .. "\n"
      Level = Level + 1
   end
   return Result
end
