function VIMbufferGet()
   return table.concat(vim.api.nvim_buf_get_lines(0, 0, -1, false), "\n").."\n"
end

