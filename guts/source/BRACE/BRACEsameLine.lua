function BRACEsameLine(Content)
   return Content:gsub("%)%s*{", "){")
end
