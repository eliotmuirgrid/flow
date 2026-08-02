COLrequire "LISTload"
COLrequire "FLOWstripTrailing"
COLrequire "TABLEsize"

function LIBcList()
   COL_FUNCTION("LIBregister");
   -- Code to load the list and add the new name.
   local List = LISTload("LIBlist");
   for i=1, TABLEsize(List) do
      List[i] = FLOWstripTrailing(List[i])
   end

   return List;
end
