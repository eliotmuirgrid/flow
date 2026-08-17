function VIMinvoke(Command, FilePath, Line, Cursor)
   COL_VAR(Command, FilePath, Line, Cursor);
   local FileContent = STDINread();
   COL_VAR(FileContent);
   print("Hello!\n"..FileContent);
end
