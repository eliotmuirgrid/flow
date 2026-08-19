function VIMcontext()
   return {
      file   = vim.fn.expand("%:p"),
      line   = vim.fn.line("."),
      column = vim.fn.col("."),
      pid    = vim.fn.getpid(),
      data   = table.concat(vim.api.nvim_buf_get_lines(0, 0, -1, false), "\n").."\n"
   }
end
