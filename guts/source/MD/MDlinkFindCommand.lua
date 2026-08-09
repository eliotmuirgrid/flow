function MDlinkFindCommand(Arg)
   local Root = Arg[3] or "press"
   local Dir = ENVget("HOME").."/"..Root.."/"
   MDlinkFind(Dir)
end
