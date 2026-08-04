#pragma once
//---------------------------------------------------------------------------
// Copyright (C) 2026 Eliot Muir.  All Rights Reserved
//
// Module: COLpair
//---------------------------------------------------------------------------

template <class T1, class T2>
struct COLpair {
   typedef T1 first_type;
   typedef T2 second_type;

   T1 first;
   T2 second;

   COLpair() : first(), second() {}
   COLpair(const COLpair& rhs) : first(rhs.first), second(rhs.second) {}
   COLpair(T1 t1, T2 t2) : first(t1), second(t2) {}

   // non-standard -> operators to support iter->first, iter->second syntax.
   const COLpair* operator->() const { return this; }
   COLpair*       operator->()       { return this; }
};

template<class T1, class T2>
inline bool operator==(const COLpair<T1,T2>& t1, const COLpair<T1,T2>& t2) {
   return t1.first  == t2.first
       && t1.second == t2.second;
}

template<class T1, class T2>
inline bool operator!=(const COLpair<T1,T2>& t1, const COLpair<T1,T2>& t2) {
   return !(t1 == t2);
}

template<class T1, class T2>
inline COLpair<T1,T2> make_COLpair(T1 t1, T2 t2) {
   return COLpair<T1,T2>(t1,t2);
}
