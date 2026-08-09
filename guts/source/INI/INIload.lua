function INIload(FileName)
   COL_VAR(FileName);
   local Lines = FILEreadLines(FileName);
   COL_VAR(Lines);
   local R = {};
   for i =1, COLcount(Lines) do
      local K, V = INIsplitEqual(Lines[i]);
      R[K] = V;
   end
   COL_VAR(R);
   return R;
end
