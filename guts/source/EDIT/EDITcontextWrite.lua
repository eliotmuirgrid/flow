function EDITcontextWrite(Content)
   local Context = VIMcontext()
   local Name = DATEhumanPretty() .. "_" .. Context.pid .. ".json"
   local Path = os.getenv("HOME") .. "/.flow/edit/" .. Name

   FILEwrite(Path, JSONencode(Context))

   return Path
end
