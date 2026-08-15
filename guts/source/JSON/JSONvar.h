#pragma once

#include "COLarray.h"
#include "COLstring.h"
#include "COLdictSorted.h"

class JSONvar {
public:
   JSONvar();
   ~JSONvar();
   
   int      Type;  // Corresponds to LUA types

   bool      Boolean;
   double    Number;
   COLstring String;

   // Table entries
   COLarray<JSONvar> Array;
   COLdictSorted<COLstring, JSONvar> Dict;
};

COLstream& operator<<(COLstream& Stream, const JSONvar& Var);
