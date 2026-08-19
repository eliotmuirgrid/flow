function MUSICplay(Args)
   COL_VAR(Args)
   
   local Url = "https://open.spotify.com/search/"..table.concat(Args, " ");
   COL_VAR(Url)
   URLopen(Url);
end
