function AGENTlocal(Prompt, Model)
   Model = Model or "llama3.2:latest";
   local P = {}
   P.url = 'http://localhost:11434/api/generate'
   P.headers = {}
   P.headers["Content-Type"] = 'application/json'
   P.data = {
      model  = "llama3.2:latest",
      prompt = Prompt,
      stream = false
   }
   local Response = HTTPpost(P)
   COL_VAR(Response);
   Response = TRIMtill(Response, [["response":]]);
   COL_VAR(Response);
   Response = TRIMafter(Response, [[,"done":true]]);
   COL_VAR(Response);
   Response = JSONstringDecode(Response);
   COL_VAR(Response);
   return Response;
end
