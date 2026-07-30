function URLopen(Url)
   COL_VAR(Url)
   local C
   if     (OSisMac())     then C='open "'..Url..'"' 
   elseif (OSisWindows()) then C='start '..Url      else
      error("Sorry URLopen doesn't support your operating system yet.");
   end
   print "Eliot suggests be careful about using URLopen with any URLs you didn't create yourself"
   print "This code is unsafe - but a lot of engineering effort will be required to make it safe.  Later!"
   os.execute(C);
end
