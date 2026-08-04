//-------------------------------------------------------
// Copyright (C) 2021 Eliot Muir.  All Rights Reserved
//
// COLstring
// 
// Implementation
//-------------------------------------------------------
#include "COLstring.h"
#include "COLstream.h"
#include "COLsink.h"
#include "COLtrace.h"
COL_TRACE_INIT;

#include "new" 
#include "string.h"
#include "ctype.h"

COLstring::COLstring(){
   init();
}

COLstring::COLstring(const char* pString){
   init();
   append(pString, strlen(pString));
}

COLstring::COLstring(const char* pString, int Size){
   init();
   append(pString, Size);
}

COLstring::COLstring(const COLstring& Orig){
   init();
   append(Orig.data(), Orig.size());
}

COLstring& COLstring::operator=(const char* pString){
   m_Size = 0;
   append(pString, strlen(pString));
   return *this;
}

// TODO - could optimize more for small strings.
COLstring& COLstring::operator=(const COLstring& Orig){
   m_Size = 0;
   append(Orig.data(), Orig.size());
   return *this;
}

COLstring::~COLstring(){
   if (m_Capacity >= sizeof(m_pData.ShortBuffer)){
      delete []m_pData.pHeap;
   } 
}

COLstring& COLstring::append(const char* pData){
   return append(pData, strlen(pData));
}

COLstring& COLstring::append(const COLstring& Orig){
   return append(Orig.data(), Orig.size());
}



COLstring& COLstring::append(const char* pData, int AddSize){
   if (m_Size + AddSize > m_Capacity){
      setCapacity(COLupperPowerOfTwo(m_Size+AddSize+1));
   }
   strncpy((data() + m_Size), pData, AddSize);
   m_Size += AddSize;
   data()[m_Size] = 0;  // NULL terminate
   return *this;   
}

// Short --> Short
// Short --> Long
// Long --> Short
// Long --> Long
void COLstring::setCapacity(int NewCapacity){
   if (m_Capacity < sizeof(m_pData.ShortBuffer)){
      if (NewCapacity < sizeof(m_pData.ShortBuffer)){
         m_Capacity = NewCapacity;
      } else {
         char* pNewHeap = new char[NewCapacity];
         strncpy(pNewHeap, data(), m_Size+1);
         m_Capacity = NewCapacity;
         m_pData.pHeap = pNewHeap;
      }
      return;
   }
   // Coming from Long
   if (NewCapacity < sizeof(m_pData.ShortBuffer)){
      char* pOldHeap = m_pData.pHeap;
      m_Capacity = NewCapacity;
      strncpy(m_pData.ShortBuffer, pOldHeap, m_Size+1);
      delete pOldHeap;
   } else {
      char* pOldHeap = m_pData.pHeap;
      char* pNewHeap = new char[NewCapacity];
      strncpy(pNewHeap, pOldHeap, m_Size+1);
      m_Capacity = NewCapacity;
      m_pData.pHeap = pNewHeap;
      delete pOldHeap;
   }
}

COLstring& COLstring::operator+=(const char Char){
   return append(&Char,1);
}

COLstring& COLstring::operator+=(const char* pData){
   return append(pData, strlen(pData));
}

COLstring& COLstring::operator+=(const COLstring& Orig){
   return append(Orig.data(), Orig.size());
}

int COLstring::compare(const COLstring& Lhs) const { 
   return strcmp(data(), Lhs.data());
}

bool COLstring::operator!=(const char* pData) const{
   return strcmp(data(), pData) != 0;
}

bool COLstring::operator==(const COLstring& Rhs) const{
   if (size() != Rhs.size()){
      return false;
   }
   return memcmp(data(), Rhs.data(), size()) == 0; 
}

bool COLstring::operator!=(const COLstring& Rhs) const{
   return !operator==(Rhs);
}

int COLstring::reverseFind(char Char) const{
   COL_METHOD(COLstring::reverseFind);
   COL_VAR2(Char, *this); 
   for (int i=size()-1; i>=0; i--){
     if (data()[i] == Char){
	return i;
     }
   }
   return -1;
}

bool COLstring::find(const char* Needle) const{
   COL_METHOD(COLstring::find);
   const char* P = strstr(data(), Needle);
   return NULL != P;
}

void COLstring::swap(COLstring* pThat) {
   if (!pThat || pThat == this) {
      return;
   }

   unsigned char Temp[sizeof(COLstring)];
   memcpy(Temp,  pThat, sizeof(COLstring));
   memcpy(pThat, this, sizeof(COLstring));
   memcpy(this,  Temp, sizeof(COLstring));
}

int COLstring::icompare(const char* s1, const char* s2) {
   const unsigned char* us1 = (const unsigned char*)s1;
   const unsigned char* us2 = (const unsigned char*)s2;
   int i1, i2; // must be int
   for (; (i1 = toupper(*us1)) == (i2 = toupper(*us2)); ++us1, ++us2) {
      if (i1 == 0) {
         return 0;
      }
   }
   return i1 - i2;
}

int COLstring::icompare(const COLstring& s) const { return icompare(data(), s.data()); }
int COLstring::icompare(const char*      s) const { return icompare(data(), s);        }

void COLstring::clear(){
   data()[0] = 0;
   m_Size = 0;
}

void COLstring::set(const char* s, int len){
   clear();
   append(s, len);
}


// TODO boundary checks
COLstring COLstring::substr(int Start, int Size) const{ return COLstring(data()+Start, Size);         }
COLstring COLstring::substr(int Start) const          { return COLstring(data()+Start, size()-Start); }

COLstring operator+(const COLstring& Lhs, const char*     pRhs) { COLstring X(Lhs); X+= pRhs; return X;}
COLstring operator+(const COLstring& Lhs, const COLstring& Rhs) { COLstring X(Lhs); X+= Rhs;  return X;}

COLstream& operator<<(COLstream& Stream, const COLstring& String){
   Stream.sink()->write(String.data(), String.size());
   return Stream;
}

unsigned int COLupperPowerOfTwo(unsigned int v){
   v--;
   v |= v >> 1;
   v |= v >> 2;
   v |= v >> 4;
   v |= v >> 8;
   v |= v >> 16;
   v++;
   return v;
}


bool COLisThisAlpha(char Character){
   return (Character >= 'A' && Character <= 'Z') ||
          (Character >= 'a' && Character <= 'z');
}