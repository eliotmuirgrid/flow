function URLopen(Url)
   COL_VAR(Url)
   -- Bill instead of worrying about Africa couldn't you have fixed your
   -- operating system?
   local Windows = 'C:\\\\Windows\\\\System32\\\\cmd.exe /c start " " "'..Url..'"'
   local Mac     = 'open "'..Url..'"'
   COL_VAR(Windows,Mac);

   if (OSisMac()) then 
      os.execute(Mac);	
   elseif (OSisWindows()) then
      os.execute(Windows);
   else
      error("Sorry URLopen doesn't support your operating system yet.");
   end
   COL_TRC("Eliot suggests be careful about using URLopen with any URLs you didn't create yourself")
   COL_TRC("This code is unsafe - but a lot of engineering effort will be required to make it safe.  Later!")
end
