function TABLEkeys(T)
   local S = {}
   for K, _ in pairs(T) do
      TABLEpush(S, K);
   end
   SORTalpha(S);
   return S;
end
