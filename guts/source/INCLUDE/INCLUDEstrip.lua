function INCLUDEstrip(FileName)
   local Lines = FILEreadLines(FileName)
   COL_VAR(Lines);
   for i=1, table.getn(Lines) do
      if STRINGstartsWith(Lines[i], "COL_TRACE_INIT;") then
	      COL_TRC("Truncating at line "..i);
         return table.concat(Lines, "\n", i+1, table.getn(Lines));
      end
   end	
end
