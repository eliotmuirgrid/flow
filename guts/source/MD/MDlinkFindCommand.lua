function MDlinkFindCommand(Arg)
   local Root = Arg[3] or "press"
   local Dir = ENVget("HOME").."/"..Root.."/"
   COL_TRC("Exploring: "..Dir);
   MDlinkFind(Dir)
end
