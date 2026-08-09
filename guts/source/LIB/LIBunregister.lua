function LIBunregister(Name)
   print("Unregistering the function: "..Name);
   -- Code to load the list and add the new name.
   LISTconfigRemove("LIBlist", Name);
   LIBregenerate();
end
