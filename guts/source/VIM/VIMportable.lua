
function COL_VAR(...)

end

function COL_FUNCTION(V)  end;

function COL_TRC(T) end

function FILEexists(File)
   return vim.fn.filereadable(File) == 1
end

string.gfind = string.gmatch
