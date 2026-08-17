//---------------------------------------------------------------------------
// Copyright (C) Eliot Muir.  All Rights Reserved
//
// Module: COLlist
//
// Description:
//
// Templated double linked list class
//---------------------------------------------------------------------------
#include "COLassert.h"
#include "COLlist.h"
#include "COLtrace.h"
COL_TRACE_INIT;

COLvoidList::COLvoidList(): Size(0), Head(COLnull), Tail(COLnull){}


void COLvoidList::clear(){
   COLlistPlace Place = Head;
   while (Place != COLnull){
      COLlistPlace Current = Place;
      Place = Place->Next;
      destroyItem(Current);
   }
   Size = 0;
   Head = COLnull;
   Tail = COLnull;
   invariant();
}

void COLvoidList::remove(COLlistPlace Place){
   COLASSERT(Place != COLnull);
   if (Place == COLnull){
      return; // TODO not needed if precondition is used
   }

   if (Place->Previous == COLnull){
      Head = Place->Next;
   } else {
      Place->Previous->Next = Place->Next;
   }

   if (Place->Next == COLnull) {
      Tail = Place->Previous;
   } else{
      Place->Next->Previous = Place->Previous;
   }

   destroyItem(Place);
   Size--;
   invariant();
}

void COLvoidList::exchange(COLlistPlace Place1, COLlistPlace Place2){
   COLASSERT(Place1 != COLnull && Place2 != COLnull);
   if (Place1 == COLnull || Place2 == COLnull){
      return; // TODO not needed if precondition is used
   }

   if (Place1 != Place2){
      COLlistPlace Previous = Place1->Previous;
      COLlistPlace Next = Place1->Next;
      Place1->Previous = Place2->Previous;
      Place1->Next = Place2->Next;
      Place2->Previous = Previous;
      Place2->Next = Next;

      if (Place1->Previous != COLnull){
         if (Place1->Previous == Place1){
            Place1->Previous = Place2;
         } else {
            Place1->Previous->Next = Place1;
         }
      }

      if (Place1->Next != COLnull){
         if (Place1->Next == Place1){
            Place1->Next = Place2;
         } else {
            Place1->Next->Previous = Place1;
         }
      }

      if (Place2->Previous != COLnull) {
         if (Place2->Previous == Place2) {
            Place2->Previous = Place1;
         } else {
            Place2->Previous->Next = Place2;
         }
      }

      if (Place2->Next != COLnull) {
         if (Place2->Next == Place2){
            Place2->Next = Place1;
         } else {
            Place2->Next->Previous = Place2;
         }
      }

      if (Head == Place1){
         Head = Place2;
      } else if (Head == Place2){
         Head = Place1;
      }

      if (Tail == Place1){
         Tail = Place2;
      } else if (Tail == Place2) {
         Tail = Place1;
      }
      invariant();
   }
}

COLlistPlace COLvoidList::previous(COLlistPlace Place) const{
   return Place == COLnull ? Tail : Place->Previous;
}

COLlistPlace COLvoidList::next(COLlistPlace Place) const{
   return Place == COLnull ? Head : Place->Next;
}

COLlistPlace COLvoidList::insertItem(COLlistPlace Item, COLlistPlace Place){
   COLASSERT(Item != COLnull);
   if (Place == COLnull){
      return addItem(Item);
   }
   Item->Previous = Place->Previous;
   Item->Next = Place;
   if (Item->Previous == COLnull){
      Head = Item;
   } else {
      Item->Previous->Next = Item;
   }
   Place->Previous = Item;
   Size++;
   invariant();
   return Item;
}

COLlistPlace COLvoidList::addItem(COLlistPlace Item){
   COLASSERT(Item != COLnull);
   Item->Previous = Tail;
   Item->Next = COLnull;
   if (Tail == COLnull){
      Head = Item;
   } else {
      Tail->Next = Item;
   }
   Tail = Item;
   Size++;
   invariant();
   return Item;
}

#ifdef COL_ENABLE_INVARIANT_INTEGRITY_CHECK
void COLvoidList::invariant() const{
   if (Size == 0) {
      COLASSERT(Head == COLnull && Tail == COLnull);
   } else {
      COLASSERT(Head != COLnull && Tail != COLnull);
      COLASSERT(Head->Previous == COLnull && Tail->Next == COLnull);
   }
   COLlistPlace Place = Head;
   for (COLindex i = 0; i < Size; i++){
      COLASSERT(Place != COLnull);
      if (Place->Next == COLnull) {
         COLASSERT(Place == Tail);
      } else {
         COLASSERT(Place->Next->Previous == Place);
      }
      Place = Place->Next;
   }
   COLASSERT(Place == COLnull);
}
#endif // DEBUG
