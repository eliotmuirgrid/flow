require "COL/COLshow"

function COL_VAR (V) 
   LUAltrace(COLshow(V)); 
end	

function COL_VAR2(V1, V2) 
   LUAltrace(COLshow(V1)..", "..COLshow(V2)); 
end	
--function COL_VAR3(V) LUAltrace(COLshow(V)..", "..COLshow(V))..", "..COLshow(V))                ; end	

function COL_FUNCTION(V) LUAltrace("F:"..V); end;


function COL_TRC(T) LUAltrace(T) end

--TODO get #T and #S to work
function COLcount(T)
   if type(T)     == "string" then return string.len(T)
   elseif type(T) == "table"  then return table.getn(T)
   end
   error("COLcount "..type(T))
end

function COLrequire(Filename)
   COL_VAR(Filename);
   local P = ""
   local i = 1
   while i <= Filename:len() do
      local byte = Filename:byte(i)
      if byte >= 65 and byte <= 90 then -- ASCII A-Z
         P = P..Filename:sub(i,i)
         i = i + 1
      else
         break
      end
   end
   COL_VAR(P);
   local F = P.."/"..Filename
   COL_VAR(F);
   require(F);
end
