function FILEwrite(FileName, Content)
   COL_VAR(FileName); 
   local F = io.open(FileName, "w") -- open the file for writing ("w" mode)
   if not F then
      error("Unable to write file "..FileName);
   end
   F:write(Content)
   F:close()
end
