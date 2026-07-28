COLrequire('FILEreadLines');
COLrequire('INIsplitEqual');

function INIload(FileName)
   COL_VAR(FileName);
   local Lines = FILEreadLines(FileName);
   COL_VAR(Lines);
   local R = {};
   for i =1, COLcount(Lines) do
      local K, V = INIsplitEqual(Lines[1]);
      R[K] = V;
   end
   return R;
end
