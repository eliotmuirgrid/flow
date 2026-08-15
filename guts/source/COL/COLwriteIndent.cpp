#include "COLwriteIndent.h"
#include "COLsink.h"

#define G ". . . . . . . . . . . . . . . . . . . . . . . . . "
static const char* s_pIndent = G G G G G G G G G G G G G G G G G G G G G G G G G G G G G G;

void COLwriteIndent(COLsink* pSink, int Level){
   pSink->write(s_pIndent, Level*2);
}
