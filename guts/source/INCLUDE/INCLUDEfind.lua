function INCLUDEfind(FName)
   COL_VAR(FName)
   local F = FLOWfileCpp(FName);
   COL_VAR(F)
   local Body = INCLUDEstrip(F);
   COL_VAR(Body)
   local ListC = FLOWlistC("COL");
   COL_VAR(ListC);
   SORTalpha(ListC)
   local IList = {};
   for i=1, table.getn(ListC) do
      if STRINGfind(Body, ListC[i]) then
         print("Found "..ListC[i]);
         TABLEpush(IList, ListC[i])
      end
   end	
   print(COLshow(IList))
end
