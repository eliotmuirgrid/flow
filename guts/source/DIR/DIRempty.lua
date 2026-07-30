function DIRempty(Dir)
   local List = DIRlist(Dir);
   return table.getn(List) == 0;
end
