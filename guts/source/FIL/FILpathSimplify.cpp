#include "FILdirSeparator.h"
#include "COLarray.h"
#include "COLtrace.h"
COL_TRACE_INIT;

#include "string.h"

static bool FILisThisAlpha(const char C){
   return ((0x41 <= C && C <= 0x5a) || (0x61 <= C && C <= 0x7A));
}
bool FILpathSimplify(COLstring* pPath){
   COL_FUNCTION(FILpathSimplify);
   COLstring& Path = *pPath;
   COL_VAR(Path);
   const char* pInput = Path.data();
   COLstring Buffer;
   Buffer.setCapacity(Path.size() + 1);
   char* pOutputStart = Buffer.data();
   char* pOutput = pOutputStart;
   COLarray<char*> DirectoryOffsets;
   char Separator = FILdirSeparator[0];
   enum {
      ST_START,
      ST_DATA,
      ST_DOT,
      ST_DOTDOT
   } State = ST_START;
   if (Path.size() >= 1 && *pInput == '/'){
      COL_TRC("POSIX style absolute path.");
      Separator = '/';
      *pOutput++ = *pInput++;
   }
   else if (Path.size() >= 2 && ::memcmp(pInput, "\\\\", 2) == 0){
      COL_TRC("Samba style absolute path.");
      Separator = '\\';
      ::memcpy(pOutput, pInput, 2);
      pOutput += 2;
      pInput += 2;
   } else if (Path.size() >= 3 && FILisThisAlpha(pInput[0]) && pInput[1]==':' && (pInput[2]=='/' || pInput[2]=='\\')){
      COL_TRC("Windows style absolute path.");
      Separator = '\\';
      pOutput[0] = pInput[0];
      pOutput[1] = pInput[1];
      pOutput[2] = Separator;
      pOutput += 3;
      pInput += 3;
   } else {
      COL_TRC("Relative path.");
   }
   DirectoryOffsets.push(pOutput);
   while (*pInput){
      char LastChar = *pInput;
      switch (LastChar){
         case '\\':
         case '/': LastChar = Separator; break;
         default: break;
      }
      pInput++;
      *pOutput++ = LastChar;
      switch (State){
         case ST_START:
            switch (LastChar){
               case '.': State = ST_DOT; break;
               case '\\':
               case '/': pOutput--; State = ST_START; break;
               default: State = ST_DATA; break;
            }
            break;
         case ST_DATA:
            switch (LastChar){
               case '\\':
               case '/': State = ST_START; DirectoryOffsets.push(pOutput); break;
               default: break;
            }
            break;
         case ST_DOT:
            switch (LastChar){
               case '\\':
               case '/': pOutput = DirectoryOffsets[DirectoryOffsets.size() - 1]; State = ST_START; break;
               case '.': State = ST_DOTDOT; break;
               default: State = ST_DATA; break;
            }
            break;
         case ST_DOTDOT:
            switch (LastChar){
               case '\\':
               case '/':
                  if (DirectoryOffsets.size() >= 2){
                     DirectoryOffsets.pop();
                     pOutput = DirectoryOffsets[DirectoryOffsets.size() - 1];
                  }
                  State = ST_START;
                  break;
               default:
                  State = ST_DATA; break;
            }
            break;
      }
   }
   switch (State){
      case ST_DOT:
         pOutput = DirectoryOffsets[DirectoryOffsets.size() - 1];
         break;
      case ST_DOTDOT:
         if (DirectoryOffsets.size() >= 2){
            DirectoryOffsets.pop();
            pOutput = DirectoryOffsets[DirectoryOffsets.size() - 1];
         }
         break;
      default:;
   }
   COLstring SimplePath(pOutputStart, pOutput - pOutputStart);
   COL_VAR(SimplePath);
   Path = SimplePath;
   return true;
}
