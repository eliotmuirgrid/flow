COLrequire 'FLOWfileCpp'
COLrequire 'FILEread'
COLrequire 'FILEwrite'
COLrequire 'COMMENTremove'

function FUNCTIONdivide(File)
   local FileName = FLOWfileCpp(File)
   local Content  = FILEread(FileName);
   Content = COMMENTremove(Content);
   FILEwrite(FileName,Content);
end
