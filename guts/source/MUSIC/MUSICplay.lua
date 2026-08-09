function MUSICplay(Args)
   COL_VAR(Args)
   
   local Url = "https://open.spotify.com/search/query="..table.concat(Args, " ");
   COL_VAR(Url)
   URLopen(Url);
end
