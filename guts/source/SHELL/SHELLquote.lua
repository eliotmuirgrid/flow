function SHELLquote(S)
   return "'"..S:gsub("'","'\\''").."'"
end
