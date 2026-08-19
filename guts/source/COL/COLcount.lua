--TODO get #T and #S to work
function COLcount(T)
   if type(T)     == "string" then return string.len(T)
   elseif type(T) == "table"  then return table.getn(T)
   end
   error("COLcount "..type(T))
end
