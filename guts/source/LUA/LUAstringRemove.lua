function LUAstringRemove(Code)
   local Result = "";
   local i = 1;
   while i <= string.len(Code) do
      local C = string.sub(Code, i, i);
      local N = string.sub(Code, i, i + 1);
      if C == '"' or C == "'" then
         local Q = C;
         Result = Result .. Q;
         i = i + 1;
         while i <= string.len(Code) do
            C = string.sub(Code, i, i);
            if C == "\\" then
               Result = Result .. "  ";
               i = i + 2;
            elseif C == Q then
               Result = Result .. Q;
               i = i + 1;
               break;
            else
               Result = Result .. (C == "\n" and "\n" or " ");
               i = i + 1;
            end
         end
      elseif N == "[[" then
         Result = Result .. "[[";
         i = i + 2;
         while i <= string.len(Code) and string.sub(Code, i, i + 1) ~= "]]" do
            C = string.sub(Code, i, i);
            Result = Result .. (C == "\n" and "\n" or " ");
            i = i + 1;
         end
         Result = Result .. "]]";
         i = i + 2;
      else
         Result = Result .. C;
         i = i + 1;
      end
   end
   return Result;
end
