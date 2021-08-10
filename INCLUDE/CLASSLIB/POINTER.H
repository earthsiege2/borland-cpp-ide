//----------------------------------------------------------------------------
// Borland Class Library
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.7  $
//
// Various types of smart pointer templatized classes
//----------------------------------------------------------------------------
#if !defined(CLASSLIB_POINTER_H)
#define CLASSLIB_POINTER_H

#if !defined(CLASSLIB_DEFS_H)
# include <classlib/defs.h>
#endif
#include <new.h>  // for size_t

//
// A pair of smart pointer template classes. Provides basic conversion
// operator to T*, as well as dereferencing (*), and 0-checking (!).
// These classes assume that they alone are responsible for deleting the
// object or array unless Relinquish() is called.
//

//
// class TPointerBase
// ~~~~~ ~~~~~~~~~~~~
template<class T> class TPointerBase {
  public:
    T&   operator  *() {return *P;}
         operator T*() {return P;}
    int  operator  !() const {return P==0;}
    T*   Relinquish() {T* p = P; P = 0; return p;}

  protected:
    TPointerBase(T* pointer) : P(pointer) {}
    TPointerBase() : P(0) {}

    T* P;

  private:
    void* operator new(size_t) {return 0;}  // prohibit use of new
    void operator delete(void* p) {((TPointerBase<T>*)p)->P=0;}
};

//
// class TPointer
// ~~~~~ ~~~~~~~~
// Pointer to a single object. Provides member access operator ->
//
template<class T> class TPointer : public TPointerBase<T> {
  public:
    TPointer() : TPointerBase<T>() {}
    TPointer(T* pointer) : TPointerBase<T>(pointer) {}
   ~TPointer() {delete P;}
    TPointer<T>& operator =(T* src) {delete P; P = src; return *this;}
    T* operator->() {return P;}  // Could throw exception if P==0
};

//
// class TAPointer
// ~~~~~ ~~~~~~~~~
// Pointer to an array of type T. Provides an array subscript operator and uses
// array delete[]
//
template<class T> class TAPointer : public TPointerBase<T> {
  public:
    TAPointer() : TPointerBase<T>() {}
    TAPointer(T array[]) : TPointerBase<T>(array) {}
   ~TAPointer() {delete[] P;}
    TAPointer<T>& operator =(T src[]) {delete[] P; P = src; return *this;}
    T& operator[](int i) {return P[i];}  // Could throw exception if P==0
};

//----------------------------------------------------------------------------

//
// Envelope-letter type of smart pointers. In this implementation the envelope
// acts as a smart pointer to a reference-counted internal letter. This allows
// a lot of flexibility & safety in working with a single object (associated
// with the letter) being assigned to numerous envelopes in many scopes. An 'A'
// version is provided for use with arrays.
//
// Use like:
//   TEnvelope<T> e1 = new T(x,y,x);   // e1 now owns a T in a letter
//   e1->Func();                       // invokes Func() on the new T
//   Func(*e1);                        // passing a T& or a T this way
//   TEnvelope<T> e2 = e1;             // e2 safely shares the letter with e1
//
//   TAEnvelope<T> e1 = new T[99];     // e1 now owns T[] in a letter
//   e1[i].Func();                     // invokes Func() on a T element
//   Func(e1[i]);                      // passing a T& or a T this way
//   TAEnvelope<T> e2 = e1;            // e2 safely shares the letter with e1
//

//
// class TEnvelope
// ~~~~~ ~~~~~~~~~
template<class T> class TEnvelope {
  public:
    TEnvelope(T* object) : Letter(new TLetter(object)) {}
    TEnvelope(const TEnvelope& src) : Letter(src.Letter) {Letter->AddRef();}
   ~TEnvelope() {Letter->Release();}

    TEnvelope& operator =(const TEnvelope& src);
    TEnvelope& operator =(T* object);

    T* operator->() { return Letter->Object; }
    T& operator *() { return *Letter->Object; }

  private:
    struct TLetter {
      TLetter(T* object) : Object(object), RefCount(1) {}
     ~TLetter() { delete Object; }

      void AddRef() { RefCount++; }
      void Release() { if (--RefCount == 0) delete this; }

      T*  Object;
      int RefCount;
    };
    TLetter* Letter;
};

template<class T>
TEnvelope<T>& TEnvelope<T>::operator =(const TEnvelope<T>& src)
{
  Letter->Release();
  Letter = src.Letter;
  Letter->AddRef();
  return *this;
}

template<class T>
TEnvelope<T>& TEnvelope<T>::operator =(T* object)
{
  Letter->Release();
  Letter = new TLetter(object);  // Assumes non-null! Use with new
  return *this;
}

//
// class TAEnvelope
// ~~~~~ ~~~~~~~~~~
template<class T> class TAEnvelope {
  public:
    TAEnvelope(T array[]) : Letter(new TLetter(array)) {}
    TAEnvelope(const TAEnvelope& src) : Letter(src.Letter) {Letter->AddRef();}
   ~TAEnvelope() { Letter->Release(); }

    TAEnvelope& operator =(const TAEnvelope& src);
    TAEnvelope& operator =(T array[]);

    T& operator[](int i) { return Letter->Array[i]; }
    T* operator *() { return Letter->Array; }

  private:
    struct TLetter {
      TLetter(T array[]) : Array(array), RefCount(1) {}
     ~TLetter() { delete[] Array; }

      void AddRef() { RefCount++; }
      void Release() { if (--RefCount == 0) delete this; }

      T*  Array;
      int RefCount;
    };
    TLetter* Letter;
};

template<class T>
TAEnvelope<T>& TAEnvelope<T>::operator =(const TAEnvelope<T>& src)
{
  Letter->Release();
  Letter = src.Letter;
  Letter->AddRef();
  return *this;
}

template<class T>
TAEnvelope<T>& TAEnvelope<T>::operator =(T array[])
{
  Letter->Release();
  Letter = new TLetter(array);  // Assumes non-null! Use with new
  return *this;
}

//----------------------------------------------------------------------------

//
// Obsolete, should use TAPointer<char> for char[]'s
//
class TPointer<char> : public TPointerBase<char> {
  public:
    TPointer() : TPointerBase<char>() {}
    TPointer(char pointer[]) : TPointerBase<char>(pointer) {}
   ~TPointer() {delete[] P;}
    char* operator =(char src[]) {delete[] P; return P = src;}
    char* operator =(const TPointer<char>& src) {delete[] P; return P = src.P;}
    char& operator[](int i) {return P[i];}
};

#endif  // CLASSLIB_POINTER_H
