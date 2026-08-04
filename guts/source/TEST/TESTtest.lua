COLrequire 'TESTtest2'

function TESTtest()
   COL_VAR("Testing one");
   local Json = '[11, 12,14]';
   local A = JSONparse{data=Json}
   --TESTtest2() 
   print(COLshow(A));
end
