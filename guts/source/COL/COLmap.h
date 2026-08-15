#pragma once
//-----------------------------------------------------------------------------
// Copyright (C) Now Eliot Muir.  All Rights Reserved
//
// Module:      COLmap
//
// Description:
//-----------------------------------------------------------------------------
//
#include "COLpair.h"
#include "COLassert.h"
#include "COLstring.h"
#include "COLuint64.h"

/***************************\
*                           *
* AVL Tree collection class *
*                           *
\***************************/

#ifndef COLnull
#define COLnull 0
#endif

struct COLavlTreeNode
{
   COLavlTreeNode*   Up;         // 3-cornered node
   COLavlTreeNode*   Left;
   COLavlTreeNode*   Right;
   int            Balance;    // required for the tree re-balancing

   COLavlTreeNode();
};

typedef COLavlTreeNode*  COLavlTreePlace;

struct COLavlTreeBaseContext;    // used for zapping a node

class COLavlTreeBase{
private:
   COLavlTreePlace  RootNode;    // top of the tree
   COLuint64      NodeCount;   // number of nodes in the tree
public:
   COLavlTreeBase();
   virtual ~COLavlTreeBase() {}

   COLuint64 size() const { return NodeCount; }
   bool empty() const { return 0 == this->size(); }

   void clear();
   void remove(COLavlTreePlace Place);

   COLavlTreePlace first() const;
   COLavlTreePlace last() const;
   COLavlTreePlace previous(COLavlTreePlace Place) const;
   COLavlTreePlace next(COLavlTreePlace Place) const;
protected:
   bool removeItem(const void* Key);
   COLavlTreePlace addItem(const void* Key, COLavlTreePlace Item);
   COLavlTreePlace addUniqueItem(const void* Key, COLavlTreePlace Item);
   COLavlTreePlace findFirstItem(const void* Key) const;
   COLavlTreePlace findItem(const void* Key) const;
   COLavlTreePlace findNearestItem(const void* Key) const;
   COLavlTreePlace findBelowItem(const void* Key) const;
   COLavlTreePlace findAboveItem(const void* Key) const;
protected:
   virtual void destroyItem(COLavlTreePlace Place) = 0;
   virtual int compareKey(const void* Key, COLavlTreePlace Place) const = 0;
private:
   COLavlTreePlace downLeft(COLavlTreePlace Place) const;
   COLavlTreePlace downRight(COLavlTreePlace Place) const;
   COLavlTreePlace upLeft(COLavlTreePlace Place) const;
   COLavlTreePlace upRight(COLavlTreePlace Place) const;
   COLavlTreePlace insertIt(const void* Key, COLavlTreePlace Item, COLavlTreePlace& CurrNode, COLavlTreePlace NodeAbove, bool& Higher, bool Unique);
   bool zapIt(COLavlTreeBaseContext& Context, COLavlTreePlace& CurrNode, bool& Higher);
   bool zapIt(const void* Key, COLavlTreePlace& CurrNode, bool& Higher);
#ifdef COL_ENABLE_INVARIANT_INTEGRITY_CHECK
   void testLinkage(COLavlTreePlace Place) const;
   void invariant() const;
#else
   void invariant() const {}
#endif
   COLavlTreeBase(const COLavlTreeBase& Tree);               // disable copy constructor
   COLavlTreeBase& operator =(const COLavlTreeBase& Tree);   // disable assignment
};

template <class KeyType, class Type>
struct COLavlTreeItemNode: public COLavlTreeNode
{
   KeyType  Key;
   Type     Item;
   COLavlTreeItemNode(const KeyType& TheKey, const Type& TheItem): Key(TheKey), Item(TheItem) {}
};

template <class KeyType, class Type>
class COLavlTree: public COLavlTreeBase {
public:
   typedef int (*CompareProc)(const KeyType& Key1, const KeyType& Key2);
   COLavlTree(CompareProc TheCompareProc)
   : Compare(TheCompareProc) {
   }
   virtual ~COLavlTree() {
      clear(); 
   }
   Type& operator [](COLavlTreePlace Place) {
      COLASSERT(Place != COLnull);
      return((COLavlTreeItemNode<KeyType, Type>*) Place)->Item;
   }
   const Type& operator [](COLavlTreePlace Place) const {
      COLASSERT(Place != COLnull);
      return((COLavlTreeItemNode<KeyType, Type>*) Place)->Item;
   }
   const KeyType& key(COLavlTreePlace Place) const {
      COLASSERT(Place != COLnull);
      return((COLavlTreeItemNode<KeyType, Type>*) Place)->Key;
   }
   bool removeKey(const KeyType& Key) {
      return this->removeItem(&Key);
   }
   COLavlTreePlace add(const KeyType& Key, const Type& Item) {
      return this->addItem(&Key, new COLavlTreeItemNode<KeyType, Type>(Key, Item));
   }
   COLavlTreePlace addUnique(const KeyType& Key, const Type& Item) {
      return this->addUniqueItem(&Key, new COLavlTreeItemNode<KeyType, Type>(Key, Item));
   }
   //returns the first place matching the key, or COLnull if the key isn't mapped
   COLavlTreePlace findFirst(const KeyType& Key) const {
      return this->findFirstItem(&Key);
   }
   COLavlTreePlace findNearest(const KeyType& Key) const {
      return this->findNearestItem(&Key);
   }
   COLavlTreePlace findBelow(const KeyType& Key) const {
      return this->findBelowItem(&Key);
   }
   COLavlTreePlace findAbove(const KeyType& Key) const {
      return this->findAboveItem(&Key);
   }
protected:
   virtual void destroyItem(COLavlTreePlace Place) {
      delete (COLavlTreeItemNode<KeyType, Type>*) Place;
   }
   virtual int compareKey(const void* Key, COLavlTreePlace Place) const {
      return Compare(*(KeyType*) Key, ((COLavlTreeItemNode<KeyType, Type>*) Place)->Key);
   }
private:
   CompareProc Compare;
};

typedef COLavlTreePlace COLmapPlace;

// This template provides an easier way to construct sorted lists without writing 
// compare functions.
// 
// This compare function is used as the default depends on the < operator of the Type.
//
// To specify a completely different compare function, use the one that doesn't use > and < operators
// simply pass in the third parameter for COLmap as a new class.
// Note that this means that an external compare class must contain the static function of the prototype
//
// static int compare(const Type& A, const Type& B);
//
// neither the external compare class nor the compare function itself needs to be templated.
template <class Type>
class COLmapCompare {
public:
   //generic implementation - only use operator<()
   static int compare(const Type& A, const Type& B) {
      if (B < A) {
         return 1;
      } else if (A < B) {
         return -1;
      }
      return 0;
   }
};

//COLstring specialization
template <>
class COLmapCompare<COLstring>{
public:
   static int compare( const COLstring& A, const COLstring& B ){
     return A.compare(B);
   }
};

// Case-insensitive COLstring specialization.
class COLmapCaseInsensitiveCompare{
public:
   static int compare( const COLstring& A, const COLstring& B ){
     return A.compare(B);
   }
};

template <class KeyType, class Type, class CompareType = COLmapCompare<KeyType> >
class COLmap : public COLavlTree<KeyType, Type>{
public:
   //public typedefs for generic functions
   typedef KeyType      TKey;
   typedef Type         TValue;
   typedef COLmapPlace  TPlace;

   struct iterator {
      iterator() : map_(COLnull), place_(COLnull) { }
      iterator(const iterator& that) : map_(that.map_), place_(that.place_) { }
      iterator& operator=(const iterator& that) {
         map_ = that.map_;
         place_ = that.place_;
         return *this;
      }
      iterator& operator++() {
         COLASSERT(place_);
         place_ = map_->next(place_);
         return *this;
      }
      iterator operator++(int) {
         iterator tmp(*this);
         ++*this;
         return tmp;
      }
      iterator& operator--() {
         COLASSERT(place_);
         place_ = map_->previous(place_);
         return *this;
      }
      iterator operator--(int) {
         iterator tmp(*this);
         --*this;
         return tmp;
      }
      bool operator==(const iterator& that) const {
         COLASSERT(that.map_ == this->map_);
         return this->place_ == that.place_;
      }
      bool operator!=(const iterator& that) const {
         return !operator==(that);
      }
      // non-standard method to support (*iter).first, (*iter).second syntax
      COLpair<const KeyType&,Type&> operator*() {
         return COLpair<const KeyType&,Type&>(this->key(), this->value());
      }
      // non-standard method to support iter->first, iter->second syntax
      COLpair<const KeyType&,Type&> operator->() {
         return COLpair<const KeyType&,Type&>(this->key(), this->value());
      }
      //
      // non-STL methods
      //
      operator COLavlTreePlace() const { return place_; } // for legacy find()
      const KeyType& key() const { return map_->key(place_); }
      Type& value() { return map_->operator[](place_); }
      //
      // not public interface - treat as private
      //
      iterator(COLmap<KeyType,Type,CompareType>* m, COLavlTreePlace p) : map_(m), place_(p) { }
      COLmap<KeyType,Type,CompareType>* map_;
      COLavlTreePlace place_;
   };

   struct const_iterator {
      const_iterator() : map_(COLnull), place_(COLnull) { }
      const_iterator(const const_iterator& that) : map_(that.map_), place_(that.place_) { }
      const_iterator(const iterator& that) : map_(that.map_), place_(that.place_) { }
      const_iterator& operator=(const const_iterator& that) {
         map_ = that.map_;
         place_ = that.place_;
         return *this;
      }
      const_iterator& operator=(const iterator& that) {
         map_ = that.map_;
         place_ = that.place_;
         return *this;
      }
      const_iterator& operator++() {
         COLASSERT(place_);
         place_ = map_->next(place_);
         return *this;
      }
      const_iterator operator++(int) {
         const_iterator tmp(*this);
         ++*this;
         return tmp;
      }
      const_iterator& operator--() {
         COLASSERT(place_);
         place_ = map_->previous(place_);
         return *this;
      }
      const_iterator operator--(int) {
         const_iterator tmp(*this);
         --*this;
         return tmp;
      }
      bool operator==(const const_iterator& that) const {
         COLASSERT(that.map_== this->map_);
         return that.place_ == this->place_;
      }
      bool operator!=(const const_iterator& that) const {
         return !operator==(that);
      }
      // non-standard method to support (*iter).first, (*iter).second syntax
      COLpair<const KeyType&,const Type&> operator*() const {
         return COLpair<const KeyType&,const Type&>(this->key(), this->value());
      }
      // non-standard method to support iter->first, iter->second syntax
      const COLpair<const KeyType&,const Type&> operator->() const {
         return COLpair<const KeyType&,const Type&>(this->key(), this->value());
      }
      //
      // non-STL methods
      //
      operator COLavlTreePlace() const { return place_; } // for legacy find()
      const KeyType& key() const { return map_->key(place_); }
      const Type& value() const { return map_->operator[](place_); }
      //
      // not public interface - treat as private
      //
      const_iterator(const COLmap<KeyType,Type,CompareType>* m, COLavlTreePlace p) : map_(m), place_(p) { }
      const COLmap<KeyType,Type,CompareType>* map_;
      COLavlTreePlace place_;
   };

   iterator       begin()        { return       iterator(this, COLavlTreeBase::first()); }
   const_iterator begin()  const { return const_iterator(this, COLavlTreeBase::first()); }
   const_iterator cbegin() const { return const_iterator(this, COLavlTreeBase::first()); }

   iterator       end()          { return       iterator(this, COLnull); }
   const_iterator end()  const   { return const_iterator(this, COLnull); }
   const_iterator cend() const   { return const_iterator(this, COLnull); }

   // legacy COLavlTreePlace find(const KeyType& Key) const replaced with iterator versions.
   // iterator classes have an operator COLavlTreePlace() method for backwards compatibility.
   //
   const_iterator find(const KeyType& Key) const {
      return const_iterator(this, this->findItem(&Key));
   }
   iterator find(const KeyType& Key) {
      return iterator(this, this->findItem(&Key));
   }

   iterator lower_bound(const KeyType& Key) {
      // As per the standard, find the lowest map element whose key is equal to
      // OR GREATER than the target Key.  Return end() if no such key is found.
      iterator it = iterator(this, this->findBelowItem(&Key));
      if (this->size() && this->end() == it) {
         // Special case if Key is less than the first element's key.
         return this->begin();
      }
      while (it != this->end() && CompareType::compare(it->first,Key) < 0) {
         ++it;
      }
      return it;
   }
   const_iterator lower_bound(const KeyType& Key) const {
      return const_cast<COLmap*>(this)->lower_bound(Key);
   }

   iterator upper_bound(const KeyType& Key) {
      // As per the standard, find the first element whose key is AFTER Key.
      // Return end() if no keys are found after Key.
      return iterator(this, this->findAboveItem(&Key));
   }
   const_iterator upper_bound(const KeyType& Key) const {
      return const_cast<COLmap*>(this)->upper_bound(Key);
   }

   COLpair<iterator,iterator> equal_range(const KeyType& Key) {
      return COLpair<iterator,iterator>(this->lower_bound(Key), this->upper_bound(Key));
   }
   COLpair<const_iterator,const_iterator> equal_range(const KeyType& Key) const {
      return COLpair<const_iterator,const_iterator>(this->lower_bound(Key), this->upper_bound(Key));
   }

   int count(const KeyType& Key) const {
      int n = 0;
      const_iterator it = this->lower_bound(Key);
      for (; it != this->end() && CompareType::compare(it->first,Key)==0; ++it) {
         ++n;
      }
      return n;
   }

   void emplace(const KeyType& Key, const Type& Item) {
      this->add(Key, Item);
   }

   iterator erase(iterator position) {
      COLASSERT(this == position.map_); // iterator must match map instance
      if (position.place_) {
         COLavlTreePlace Next = this->next(position.place_);
         this->remove(position.place_);
         return iterator(this, Next);
      }
      // it is not an error to erase(end())
      return this->end();
   }

   iterator erase(const KeyType& key) {
      return this->erase(this->find(key));
   }

   COLmap(): COLavlTree<KeyType, Type>( CompareType::compare ) {}
   COLmap(typename COLavlTree<KeyType, Type>::CompareProc TheCompareProc): COLavlTree<KeyType, Type>(TheCompareProc) {}
   COLmap(const COLmap& that) : COLavlTree<KeyType,Type>(CompareType::compare) {
      COLavlTree<KeyType,Type>& me = *this;
      for (auto i = that.cbegin(); i!= that.cend(); i++){
         me.add(i->first, i->second);
      }
   }
   COLmap& operator=(const COLmap& that) {
      if (this != &that) {
         COLavlTree<KeyType,Type>& me = *this;
         me.clear();
         for (auto i = that.cbegin(); i!= that.cend(); i++){
            me.add(i->first, i->second);
         }
      }
      return *this;
   }
   Type& operator[](const KeyType& key) {
      COLavlTree<KeyType,Type>& me = *this;
      TPlace place = this->find(key);
      if (place==COLnull)
         place = this->addUnique(key, TValue());
      return me.operator[](place);
   }
   const Type& operator[](const KeyType& key) const {
      const COLavlTree<KeyType,Type>& me = *this;
      TPlace place = this->find(key);
      COLASSERT(place != COLnull);
      return me.operator[](place);
   }
   const Type& operator[](COLavlTreePlace place) const {
      const COLavlTree<KeyType,Type>& me = *this;
      return me[place];
   }
   Type& operator[](COLavlTreePlace place) {
      COLavlTree<KeyType,Type>& me = *this;
      return me[place];
   }
};

COLstream& operator<<(COLstream& Stream, const COLmap<COLstring, COLstring>& Map);
