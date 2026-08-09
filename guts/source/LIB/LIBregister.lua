function LIBregister(Name)
   COL_FUNCTION("LIBregister");
   print("Registering the function: "..Name);
   LISTconfigAdd("LIBlist", Name);
   LIBregenerate();
end
