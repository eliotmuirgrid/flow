function AGENTolama(Prompt)
   if (not Prompt) then print "Enter prompt."; return; end
   local Response = AGENTlocal(Prompt); 
   print(Response);
end
