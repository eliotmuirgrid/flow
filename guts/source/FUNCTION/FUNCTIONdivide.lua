function FUNCTIONdivide(File)
   local FileName = FLOWfileCpp(File)
   local Content  = FILEread(FileName);
   Content = COMMENTremove(Content);
   Content = BRACEsameLine(Content);
   Content = BRACEelseSameLine(Content);
   FILEwrite(FileName,Content);
end
