function URLopen(Url)
   COL_VAR(Url)
   local Windows = 'start "'..Url..'"'
   local Mac     = 'open "'..Url..'"'

   if (OSisMac()) then 
      os.execute(Mac);	
   elseif (OSisWindows()) then
      os.execute(Windows);
   else
      error("Sorry URLopen doesn't support your operating system yet.");
   end
   print "Eliot suggests be careful about using URLopen with any URLs you didn't create yourself"
   print "This code is unsafe - but a lot of engineering effort will be required to make it safe.  Later!"
end
