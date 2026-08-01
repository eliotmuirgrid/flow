COLrequire 'FILEdelete'

function DSstoreDelete(Dir, File)
   if File == ".DS_Store" then
      FILEdelete(Dir..File);
      return true
   end
   return false
end
