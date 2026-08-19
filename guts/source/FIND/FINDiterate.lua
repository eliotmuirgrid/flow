function FINDiterate(Dir, Depends)
   COL_VAR(Dir);
   local Dirs = DIRlist(Dir)
   COL_VAR(Dirs);
   for _, SubDir in ipairs(Dirs) do
      COL_VAR(SubDir);
      local Ext = FILEextension(SubDir);
      COL_VAR(Ext);
      if Ext == "lua" then
         FINDlinkOutFileGenerate(SubDir:sub(1, SubDir:len()-4), Depends);
      elseif DIRisDir(Dir..SubDir) then
         FINDiterate(Dir..SubDir.."/", Depends);
      end
   end
end
