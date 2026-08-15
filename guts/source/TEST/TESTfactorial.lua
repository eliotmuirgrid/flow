function TESTfactorial(N, A)
   COL_TRC("TESTfactorial")
   A = A or 1
   if N == 0 then
      return N;
   end
   A = A * N
   COL_VAR(A)
   
   return TESTfactorial(N-1,A)
end
