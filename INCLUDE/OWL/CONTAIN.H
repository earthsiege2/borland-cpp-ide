//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.3  $
//
// Definition of container classes used and made available by OWL
//----------------------------------------------------------------------------
#if !defined(OWL_CONTAIN_H)
#define OWL_CONTAIN_H

#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif
#if !defined(CLASSLIB_ARRAYS_H)
# include <classlib/arrays.h>
#endif
#include <limits.h>

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TStringArray
// ~~~~~ ~~~~~~~~~~~~
class _OWLCLASS TStringArray {
  public:
    typedef void (*IterFunc)(string&, void*);
    typedef int  (*CondFunc)(const string&, void*);

    TStringArray(int upper, int lower, int delta);
    int LowerBound() const;
    int UpperBound() const;
    uint ArraySize() const;
    int IsFull() const;
    int IsEmpty() const;
    uint GetItemsInContainer() const;
    int Add(const string& t);
    int Detach(const string& t);
    int Detach(int loc);
    int Destroy(const string& t);
    int Destroy(int loc);
    int HasMember(const string& t) const;
    int Find(const string& t) const;
    string& operator [](int loc);
    string& operator [](int loc) const;
    void ForEach(IterFunc iter, void* args);
    string* FirstThat(CondFunc cond, void* args) const;
    string* LastThat(CondFunc cond, void* args) const;
    void Flush();

  private:
    TArrayAsVector<string> Data;

  friend class TStringArrayIterator;
};

//
// class TStringArrayIterator
// ~~~~~ ~~~~~~~~~~~~~~~~~~~~
class TStringArrayIterator : public TArrayAsVectorIterator<string> {
  public:
    TStringArrayIterator(const TStringArray& array);
};

//
// class TInt
// ~~~~~ ~~~~
// Wrapper for an int to allow it to be contained by a BIDS container. This
// is to avoid collision with an function overloaded on both int and T
//
class TInt {
  public:
    TInt() {}
    TInt(int _i) {i = _i;}
    operator int() const {return i;}

  private:
    int i;
};

//
// class TIntArray
// ~~~~~ ~~~~~~~~~
class _OWLCLASS TIntArray {
  public:
    typedef void (*IterFunc)(TInt&, void*);
    typedef int  (*CondFunc)(const TInt&, void*);

    TIntArray(int upper, int lower, int delta);
    int LowerBound() const;
    int UpperBound() const;
    uint ArraySize() const;
    int IsFull() const;
    int IsEmpty() const;
    uint GetItemsInContainer() const;
    int Add(const TInt& t);
    int Detach(const TInt& t);
    int Detach(int loc);
    int Destroy(const TInt& t);
    int Destroy(int loc);
    int HasMember(const TInt& t) const;
    int Find(const TInt& t) const;
    TInt& operator [](int loc);
    TInt& operator [](int loc) const;
    void ForEach(IterFunc iter, void* args);
    TInt* FirstThat(CondFunc cond, void* args) const;
    TInt* LastThat(CondFunc cond, void* args) const;
    void Flush();

  private:
    TArrayAsVector<TInt> Data;

  friend class TIntArrayIterator;
};

//
// class TIntArrayIterator
// ~~~~~ ~~~~~~~~~~~~~~~~~
class TIntArrayIterator : public TArrayAsVectorIterator<TInt> {
  public:
    TIntArrayIterator(const TIntArray& array);
};

//
// class TUint32Array
// ~~~~~ ~~~~~~~~~~~~
class _OWLCLASS TUint32Array {
  public:
    typedef void (*IterFunc)(uint32&, void*);
    typedef int  (*CondFunc)(const uint32&, void*);

    TUint32Array(int upper, int lower, int delta);

    int LowerBound() const;
    int UpperBound() const;
    uint ArraySize() const;
    int IsFull() const;
    int IsEmpty() const;
    uint GetItemsInContainer() const;
    int Add(const uint32& t);
    int Detach(const uint32& t);
    int Detach(int loc);
    int Destroy(const uint32& t);
    int Destroy(int loc);
    int HasMember(const uint32& t) const;
    int Find(const uint32& t) const;
    uint32& operator [](int loc);
    uint32& operator [](int loc) const;
    void ForEach(IterFunc iter, void* args);
    uint32* FirstThat(CondFunc cond, void* args) const;
    uint32* LastThat(CondFunc cond, void* args) const;
    void Flush();

  private:
    TArrayAsVector<uint32> Data;

  friend class TUint32ArrayIterator;
};

//
// class TUint32ArrayIterator
// ~~~~~ ~~~~~~~~~~~~~~~~~~~~
class TUint32ArrayIterator : public TArrayAsVectorIterator<uint32> {
  public:
    TUint32ArrayIterator(const TUint32Array& array);
};

//
// Old names provided for compatability
//
typedef TUint32Array TDwordArray;
typedef TUint32ArrayIterator TDwordArrayIterator;


//----------------------------------------------------------------------------

//
// Maximum number of entries in each Vector
//
const uint MAXENTRIES = uint((ulong(UINT_MAX) - sizeof(uint))/
                                     sizeof(void*));
//
// class TCollection
// ~~~~~ ~~~~~~~~~~~
// Simple template holding pointers to Ts used internally by
// ObjectWindows Controls
//
template <class T> class TCollection {
  public:
    TCollection(uint aLimit, uint aDelta, bool shldDel = true);
   ~TCollection();

    T&          operator [](uint index) const;
    int         GetCount() const;

    int         Append(T* item);
    void        InsertAt(uint index, T* item);
    void        RemoveAt(uint index);
    void        RemoveAll();
    void        FreeAt(uint index);
    void        FreeAll();

  protected:
    void        SetLimit(uint aLimit);

  private:
    TCollection(const TCollection&);
    TCollection& operator =(const TCollection&);

    void        FreeItem(T* item);
    T**         items;              // Pointer to array of T*
    uint        count;              // Number of items
    uint        limit;              // Size array is allocated for
    uint        delta;              // Inc. delta for resizing
    bool        shouldDelete;       // Should free in destructor
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//----------------------------------------------------------------------------
// Inline implementations
//

//
inline TStringArrayIterator::TStringArrayIterator(const TStringArray& array)
:
  TArrayAsVectorIterator<string>(array.Data)
{
}

//
inline TIntArrayIterator::TIntArrayIterator(const TIntArray& array)
:
  TArrayAsVectorIterator<TInt>(array.Data)
{
}

//
inline TUint32ArrayIterator::TUint32ArrayIterator(const TUint32Array& array)
:
  TArrayAsVectorIterator<uint32>(array.Data)
{
}

//
template<class T>
TCollection<T>::TCollection(uint aLimit, uint aDelta, bool shldDel)
: count(0), items(0), limit(0), delta(aDelta), shouldDelete(shldDel)
{
  SetLimit(aLimit);
}

//
template<class T>
TCollection<T>::~TCollection()
{
  if (shouldDelete)
    FreeAll();
  SetLimit(0);
}

//
template<class T>
int TCollection<T>::GetCount() const
{
  return count;
}

//
template<class T>
void TCollection<T>::RemoveAll()
{
  count = 0;
}

//
template<class T>
T& TCollection<T>::operator[](uint index) const
{
  PRECONDITION(index < count);
  return *items[index];
}

//
template<class T>
int TCollection<T>::Append(T* item)
{
  InsertAt(count, item);
  return count-1;
}

//
template<class T>
void TCollection<T>::InsertAt(uint index, T* item)
{
  PRECONDITION(index <= count);
  if (count == limit)
    SetLimit(count + delta);
  if (count-index != 0)
    memmove((void*)&items[index+1], (void*)&items[index],
            (count-index)*sizeof(T*));
  items[index] = item;
  count++;
}

//
template<class T>
void TCollection<T>::RemoveAt(uint index)
{
  PRECONDITION(index < count);
  if (index != count-1)
    memmove((void*)&items[index], (void*)&items[index+1],
            (count-(index+1))*sizeof(T*));
  count--;
}

//
template<class T>
void TCollection<T>::FreeAt(uint index)
{
  T& item = operator[](index);
  RemoveAt(index);
  FreeItem(&item);
}

//
template<class T>
void TCollection<T>::FreeAll()
{
  for (uint i = 0; i < count; i++)
    FreeItem(&(operator[](i)));
  count = 0;
}

//
template<class T>
void TCollection<T>::FreeItem(T* item)
{
  delete item;
}

//
template<class T>
void TCollection<T>::SetLimit(uint aLimit)
{
  if (aLimit < count)
    aLimit = count;
  CHECK(aLimit <= MAXENTRIES);

  if (aLimit != limit) {
    T **aItems;

    if (aLimit == 0)
      aItems = 0;
    else {
      aItems = new T *[aLimit];
      if (count != 0)
        memcpy(aItems, items, count*sizeof(T*));
    }
    delete [] items;
    items = aItems;
    limit = aLimit;
  }
}

#endif  // OWL_CONTAIN_H
