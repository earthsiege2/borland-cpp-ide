// SYSDYN.H: Pascal Dynamic array type
//
// $Revision:   1.22  $
// $Date:   14 Jul 1999 12:32:26  $
//
// Copyright (c) 1997, 1999 Borland International

#if !defined(SYSDYN_H)      // dynamic array
#define SYSDYN_H

#if !defined(SystemHPP)
#error Do not include this file directly.  Include 'system.hpp'.
#endif

#if !defined(SYSMAC_H)
#include <sysmac.h>
#endif

#if !defined(SystemHPP)
#include <system.hpp>
#endif

#include <stdlib.h>		// malloc, free

namespace System
{
  class DynArrayException
  {};

  /////////////////////////////////////////////////////////////////////////////
  // Exception thrown when 'out-of-range' of an DynamicArray
  /////////////////////////////////////////////////////////////////////////////
  class DynArrayOutOfRange : public DynArrayException
  {
  public:
    DynArrayOutOfRange(int index, int count) : m_Index(index),
                                               m_Count(count)
    {}

    int m_Index;
    int m_Count;
  };

  /////////////////////////////////////////////////////////////////////////////
  // Exceptions thrown when 'accessing a Null' DynamicArray
  /////////////////////////////////////////////////////////////////////////////
  class DynArrayNullData : public DynArrayException
  {};


  template <class T> class RTL_DELPHIRETURN DynamicArray;

  /////////////////////////////////////////////////////////////////////////////
  // NOTE: The following two template functions are used to determine the number of
  //       dimensions in a dynamic array. This approach relies on the fact that the
  //       resolution mechanism will use the first version of 'GetDimensions' as long
  //       as we're dealing with a DynamicArray Of DynamicArray.
  /////////////////////////////////////////////////////////////////////////////
  template <class T> inline int
  GetDimensions(const DynamicArray<T>& t) { return t.DimCount();}

  template <class T> inline int
  GetDimensions(const T&) { return 0;}



  /////////////////////////////////////////////////////////////////////////////
  // DynamicArray
  // ============
  // Template providing Delphi style Dynamic Array support in C++
  /////////////////////////////////////////////////////////////////////////////
  template<class T> class RTL_DELPHIRETURN DynamicArray
  {
  public:
    DynamicArray();
   ~DynamicArray();

    // Construct from another DynArray
    DynamicArray(const DynamicArray<T>& src);

    // Assign data from another DynArray
    DynamicArray& operator=(const DynamicArray<T>& src);

    // Subscript operator to access data
    T& operator[](int index);
    T  operator[](int index) const;

    // Comparison (NOTE: only pointer is compared)
    bool operator == (const DynamicArray<T> &other) const;

    // Make copy of data (non-refcounted)
    DynamicArray<T> Copy() const;
    void            Copy(DynamicArray<T> &dst) const;
    DynamicArray<T> CopyRange(int startIndex, int count) const;
    void            CopyRange(DynamicArray<T> &dst, int startIndex, int count) const;

    // High and low bounds of DynArray
    int             get_high() const;
    int             get_low() const;

    // Set/get length of DynArray
    int             get_length() const;
    void            set_length(int l);

#if defined(DEBUG)
    int             get_refCount() const;
#endif

    // Properties
  __property    int Length = {read=get_length, write=set_length};
  __property    int High   = {read=get_high};
  __property    int Low    = {read=get_low};

#if defined(DEBUG)
  __property    int RefCount = {read=get_refCount};
#endif

    // Returns number of dimensions of dynamic array
    // NOTE: Used with 'GetDimensions' template functions above.
    //       If T happens to be another DynamicArray, the compiler
    //       resolves the call to the first version of GetDimensions.
    //       Otherwise, it defaults to the second version.
    //
    static  int     DimCount()
    {
      return 1 + GetDimensions(*((T*)(0)));
    }

  protected:
    void            IncRefCount();
    void            DecRefCount();
    static T*       AllocData(int count);
    void            SetData(T* t);
    void            FreeData();

  private:
      T*              Data;
  };

  // Operator used in placement syntax
  //
  inline void* operator new(size_t size, char *p)
  {
    return p;
  }


  template <class T>
  DynamicArray<T>::DynamicArray() : Data(0)
  {}

  template <class T>
  DynamicArray<T>::~DynamicArray()
  {
    DecRefCount();
    Data = 0;
  }

  template <class T>
  DynamicArray<T>::DynamicArray(const DynamicArray<T>& src) : Data(src.Data)
  {
    IncRefCount();
  }

  template <class T> DynamicArray<T>&
  DynamicArray<T>::operator =(const DynamicArray<T>& src)
  {
    if (&src != this)
    {
      DecRefCount();
      Data = src.Data;
      IncRefCount();
    }
    return *this;
  }

  template <class T> T&
  DynamicArray<T>::operator[](int index)
  {
    if (index < 0 || index >= this->Length)
      throw DynArrayOutOfRange(index, this->Length);
    if (!Data)
      throw DynArrayNullData();

    return *(Data + index);
  }

  template <class T> T
  DynamicArray<T>::operator[](int index) const
  {
    if (index < 0 || index >= this->Length)
      throw DynArrayOutOfRange(index, this->Length);
    if (!Data)
      throw DynArrayNullData();

    return *(Data + index);
  }

  template <class T> bool
  DynamicArray<T>::operator == (const DynamicArray<T> &other) const
  {
    return Data == other.Data;
  }

  template <class T> DynamicArray<T>
  DynamicArray<T>::Copy() const
  {
    DynamicArray<T> cpy;
    Copy(cpy);
    return cpy;
  }

  template <class T> void
  DynamicArray<T>::Copy(DynamicArray<T>& dst) const
  {
    // Update length of destination if necessary
    int l = (*this).Length;
    if (dst.Length != l)
      dst.Length = l;

    // Copy data over
    for (int i=0; i<l; i++)
      dst[i] = (*this)[i];
  }

  template <class T> DynamicArray<T>
  DynamicArray<T>::CopyRange(int startIndex, int  count) const
  {
    DynamicArray<T> cpy;
    CopyRange(cpy, startIndex, count);
    return cpy;
  }

  template <class T> void
  DynamicArray<T>::CopyRange(DynamicArray<T>& dst, int startIndex, int count) const
  {
    // Resize destination if necessary
    // (Could optimize to only resize if too small!! However, Delphi always resizes)
    if (dst.Length != count)
      dst.Length = count;
    // Copy data over
    for (int i=0; i<count; i++)
      dst[i] = (*this)[startIndex+i];
  }

  template <class T> int
  DynamicArray<T>::get_high() const
  {
    return Data ? get_length()-1 : 0;
  }

  template <class T> int
  DynamicArray<T>::get_low() const
  {
    return 0;
  }

  template <class T> int
  DynamicArray<T>::get_length() const
  {
    int *p_i = (int*)Data;
    return Data ? *(p_i-1) : 0;
  }

  template <class T> void
  DynamicArray<T>::set_length(int l)
  {
    // Allocate space for new length
    T* p = AllocData(l);

    // Copy data other if necessary
    if (p)
    {
      // Compute length of data to be copied
      int copyLen = (*this).Length;
      if (l < copyLen)
        copyLen = l;

      // Copy data
      while (copyLen-- > 0)
        p[copyLen] = (*this)[copyLen];
    }

    // Assign new data...
    SetData(p);
  }

#if defined(DEBUG)
  template <class T> int
  DynamicArray<T>::get_refCount() const
  {
    int* p_i = (int*)Data;
    return Data ? *(p_i-2) : 0;
  }
#endif;

  template <class T> void
  DynamicArray<T>::IncRefCount()
  {
    if (Data)
    {
      int* p_i = (int*)Data;
      int &refcount = *(p_i-2);
      refcount++;
    }
  }

  template <class T> void
  DynamicArray<T>::DecRefCount()
  {
    if (Data)
    {
      int* p_i = (int*)Data;
      int &refcount = *(p_i-2);
      if (--refcount == 0)
        FreeData();
    }
  }

  template <class T> T*
  DynamicArray<T>::AllocData(int count)
  {
    // NOTE: Length of zero results in a null data pointer
    if (count == 0)
      return 0;

    // Allocate memory: Array members + 2 integers (refcount and length)
    //  NOTE: Don't use new to be compatible with Pascal memory manager
    /* int *pi = (int*)new char[sizeof(T)*count + 2*sizeof(int)]; */
    int *pi = (int*)malloc(sizeof(T)*count + 2*sizeof(int));

    // Initialize refcount + length
    *pi++ = 1;         // RefCount initialized to 1
    *pi++ = count;     // Set length of array

    T *pt = (T*)pi;
    char *pc = (char*)pi;
    T *p  = (T*)pc;

    // Invoke constructor for each member of array
    while (count-- > 0)
    {
      new  (pc) T;
      pc = (char*)(++p);
    }

    // Return pointer
    return pt;
  }

  template <class T> void
  DynamicArray<T>::SetData(T* t)
  {
    if (Data != t)
    {
      DecRefCount();
      Data = t;
    }
  }

  template <class T> void
  DynamicArray<T>::FreeData()
  {
    if (Data)
    {
      // Invoke destructor on each element
      T*  p = Data;
      int l = (*this).Length;

      for (; l-- > 0; p++)
        p->~T();

      // Free chunk of memory
      // NOTE: Don't use delete []p_i to be compatible with Delphi's memory manager
      int* p_i = (int*)Data;
      p_i -= 2;
      free(p_i);
      Data = 0;
    }
  }

} // namespace System


#endif
