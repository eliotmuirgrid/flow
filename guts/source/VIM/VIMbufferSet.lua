function VIMbufferSet(Buffer)
   vim.api.nvim_buf_set_lines(0, 0, -1, false, vim.split(Buffer, "\n", {plain=true}));
end
