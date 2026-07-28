COLrequire "FOOtest"

function FOObar()
   local A = "Fred"
   COL_TRC("Hello");
   COL_VAR(A);
   FOOtest();
end	
