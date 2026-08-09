function BRACEelseSameLine(Content)
   return Content:gsub("}%s*else%s*{", "} else {")
end
