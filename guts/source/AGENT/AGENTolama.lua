function AGENTolama()
   local T = {}
   T.agent = "chatgpt"
   T.prompt = "Guekins"
   T.strong = true;
   T.count = 10;
   T.array = {1,2,3}
   COL_VAR(T);
   JSONencode(T);
end
