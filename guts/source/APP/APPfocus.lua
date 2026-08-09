function APPfocus(App)
   local Cmd = [[
osascript \
-e 'tell application "System Events" to tell process "]] .. App .. [[" to set frontmost to true' \
-e 'tell application "System Events" to tell process "]] .. App .. [[" to perform action "AXRaise" of window 1'
]]
   os.execute(Cmd);
end
