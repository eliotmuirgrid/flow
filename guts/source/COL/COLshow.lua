require "COL/COLshowTable"

function COLshow(V, Indent)
   local I = Indent or '                                                        ';
   if (type(V) == 'table') then return COLshowTable(V, I) end;
   return tostring(V); 
end
