#include "COLstreamWithIndent.h"
#include "COLarray.h"
#include "COLsplitStringToArray.h"
#include "COLwriteIndent.h"
#include "COLtrace.h"
COL_TRACE_INIT;

void COLstreamWithIndent(COLstream& Stream, const COLstring& Output, int Indent){
   COL_FUNCTION(COLstreamWithIndent);
   COLarray<COLstring> Lines;
   COLsplitStringToArray(Output, '\n', &Lines);

   for (int i =0; i < Lines.size(); i++){
      Stream << Lines[i] << newline;
      if (i != Lines.size()-1){
         Stream << "                                                        ";
         COLwriteIndent(Stream.sink(), Indent);
      }
   }
}
