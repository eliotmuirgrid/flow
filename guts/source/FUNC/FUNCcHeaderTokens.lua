COLrequire "DATEhumanPretty"
COLrequire "DATEcomputerPretty"

function FUNCcHeaderTokens(Tokens, Name)
   Tokens.NAME       =Name;
   Tokens.HUMAN_DATE =DATEhumanPretty();
   Tokens.HEX_DATE   =DATEcomputerPretty();
   Tokens.YEAR       =os.date("%Y");
   Tokens.EXPLANATION="To be documented by an AI agent later!";
end
