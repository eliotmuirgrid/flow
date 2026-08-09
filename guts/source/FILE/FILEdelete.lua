function FILEdelete(File)
   if FILEexists(File) then
      COL_TRC("Removing "..File);
      os.remove(File)
   else
      COL_TRC("File already removed:"..File);
   end
end
