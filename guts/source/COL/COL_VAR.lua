function COL_VAR(...)
   local Output = ""
   for i = 1, table.getn(arg) do
      if i > 1 then Output = Output .. ", " end
      Output = Output .. COLshow(arg[i])
   end
   LUAltrace(Output)
end
