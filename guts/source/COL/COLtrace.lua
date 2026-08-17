require "COL/COLshow"

function COL_VAR(...)
   local Output = ""
   for i = 1, table.getn(arg) do
      if i > 1 then Output = Output .. ", " end
      Output = Output .. COLshow(arg[i])
   end
   LUAltrace(Output)
end

function COL_FUNCTION(V) LUAltrace("F:"..V); end;

function COL_TRC(T) LUAltrace(T) end

--TODO get #T and #S to work
function COLcount(T)
   if type(T)     == "string" then return string.len(T)
   elseif type(T) == "table"  then return table.getn(T)
   end
   error("COLcount "..type(T))
end
