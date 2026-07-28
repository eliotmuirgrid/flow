-- TODO require cannot handle circular requires.

function COLshowTable(V, Indent)
   local R = ''
   Indent = Indent..'  ';
   R = "{\n";
   for k, v in pairs(V) do
      R=R..Indent..tostring(k).." = "..COLshow(v, Indent).."\n";
   end
   Indent = Indent:sub(1, Indent:len()-2);
   R = R..Indent.."}";
   return R;
end
