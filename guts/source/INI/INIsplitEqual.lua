

function INIsplitEqual(KV)
   COL_VAR(KV);
   local i = 1
   while i <= KV:len() do
      if KV:sub(i, i) == "=" then
	 break;
      end
      i = i + 1
   end
   COL_TRC("Found = "..i)
   local K,V = KV:sub(1, i-1), KV:sub(i+1) 
   COL_VAR2(K, V);
   return K,V
end	
