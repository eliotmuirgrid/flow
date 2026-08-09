function MUSICplayCommand(Args)
   COL_TRC("In the MUSICplayCommand");
   table.remove(Args,1);
   table.remove(Args,1);
   MUSICplay(Args);
end
