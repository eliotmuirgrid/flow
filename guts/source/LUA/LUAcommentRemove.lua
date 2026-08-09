function LUAcommentRemove(Content)
   local Result;
   Result = Content:gsub("%-%-%[%[.-%]%]", "");
   Result = Result:gsub("%-%-[^\n]*", "");
   return Result;
end
