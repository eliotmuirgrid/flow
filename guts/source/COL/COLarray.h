#pragma once
//-------------------------------------------------------
// Copyright (C) 2021 Eliot Muir.  All Rights Reserved
//
// COLarray
//-------------------------------------------------------

#include "COLstream.h"
#include "COLassert.h"

void COLcheckBoundary(int i, int m_Size);
unsigned int COLcalculateCapacity(unsigned int v);

template<typename VType> class COLarray {
public:
   typedef VType*       iterator;
   typedef const VType* const_iterator;

   COLarray() : m_Size(0), m_Capacity(0), m_pItems(0) {}

   COLarray(int DesiredCapacity) : m_Size(0) {
      m_Capacity = COLcalculateCapacity(DesiredCapacity);
      m_pItems = new VType[m_Capacity];
   }

   ~COLarray() { delete []m_pItems; }

   int size() const { return m_Size; }

   void clear() { m_Size = 0; }

   void remove(int Index) {
      COLcheckBoundary(Index, m_Size);
      for (int i = Index; i < m_Size - 1; ++i) {
         m_pItems[i] = m_pItems[i + 1];
      }
      --m_Size;
   }

   void zero() {
      m_Size = 0;
      delete []m_pItems;
      m_pItems = 0;
      m_Capacity = 0;
   }

   VType& push(const VType& Value) {
      checkCapacity(m_Size + 1);
      m_pItems[m_Size] = Value;
      return m_pItems[m_Size++];
   }

   void pop() {
      COLASSERT(m_Size > 0);
      --m_Size;
   }

   void resize(int NewSize) {
      checkCapacity(NewSize + 1);
      m_Size = NewSize;
   }

   VType& operator[](int i) {
      COLcheckBoundary(i, m_Size);
      return m_pItems[i];
   }

   const VType& operator[](int i) const {
      COLcheckBoundary(i, m_Size);
      return m_pItems[i];
   }

   void checkCapacity(int DesiredCapacity) {
      if (DesiredCapacity <= m_Capacity) {
         return;
      }
      int NewCapacity = COLcalculateCapacity(DesiredCapacity);
      VType* pNewSpace = new VType[NewCapacity];

      VType* pEnd = pNewSpace + m_Size;
      for (VType* i = pNewSpace, *j = m_pItems; i != pEnd; ++i, ++j) {
         *i = *j;
      }

      delete []m_pItems;

      m_Capacity = NewCapacity;
      m_pItems = pNewSpace;
   }

   iterator begin() { return m_pItems; }

   iterator end() { return m_pItems + m_Size; }

   const_iterator begin() const { return m_pItems; }

   const_iterator end() const { return m_pItems + m_Size; }

   const_iterator cbegin() const { return m_pItems; }

   const_iterator cend() const { return m_pItems + m_Size; }

   void printOn(COLstream& Stream) const {
      Stream << "Vector  Size=" << m_Size << ", Capacity=" << m_Capacity;
      int Count = 0;
      for (auto i = cbegin(); i != cend(); ++i, ++Count) {
         Stream << newline << " " << Count << " " << *i;
      }
   }

private:
   VType* m_pItems;
   int    m_Size;
   int    m_Capacity;
};

template<typename VType>
COLstream& operator<<(COLstream& Stream, const COLarray<VType>& Vector) {
   Vector.printOn(Stream);
   return Stream;
}
