/////////////////////////////////////////////////////////////////////////////
//  SAFEARRY.H - Helpers to handle SAFEARRAY in C++
//
//  $Revision:   1.15  $
//  $Date:   27 May 1999 12:31:36  $
//
//  Copyright (c) 1997, 1998 Borland International
/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
#if   0

Using the TSafeArrayT template:
===============================

////////////////////////////////////////////////////////////////////////////////////////
// Create a single dim. SAFEARRAY of BSTR
// Initialize to some strings.
// Read back the data
////////////////////////////////////////////////////////////////////////////////////////
void SAFEARRAY_OF_BSTR()
{
  TSafeArrayDim1  dim(10);            // 1D dimension set to 10
  TSafeArrayBSTR1 bstrArray(dim);     // Creates Safearray for 10 BSTRs

  // Iterate through array, setting some strings
  //
  for (int i=0; i < bstrArray.BoundsLength[0]; i++)
  {
    TCHAR buffer[_MAX_PATH];
    wsprintf(buffer, "String %i", i);
    bstrArray[i] = WideString(buffer).Detach();
  }

  // Iterate through array extracting strings
  //
  for (int i=0; i < bstrArray.BoundsLength[0]; i++)
    printf("%02i: %s \n", i, AnsiString(bstrArray[i]).c_str());
}


////////////////////////////////////////////////////////////////////////////////////////
// Display the contents of a 2DIM SAFEARRAY of integers
////////////////////////////////////////////////////////////////////////////////////////
void Show2DIntArray(SAFEARRAY* psa)
{
  TSafeArrayInt2 intArray;  // Create 2D SafeArray of integers
  intArray.Attach(psa);     // Attach to SAFEARRAY data passed to us

  for (int i=0; i < intArray.BoundsLength[0]; i++)    // Length of first dimension
    for (int j=0; j < intArray.BoundsLength[1]; j++)  // Length of second dimension
      printf("i:%i, j:%i - Data=%i \n", i, j, int(intArray[i][j]));
}


////////////////////////////////////////////////////////////////////////////////////////
// Create a 2DIM SAFEARRAY of integers.
// Initialize to some values
////////////////////////////////////////////////////////////////////////////////////////
void SAFEARRAY_OF_INT()
{
  TSafeArrayDim2 dim(9, 5);           // Create twoD bounds
  TSafeArrayInt2 intArray(dim);       // Create twoD Safearray of integers of above size

  // Assert dimension (debugging)
  //
  unsigned dimension = intArray.Dimension;
  assert(dimension == 2); //  Should be twoD array

  // Initialize ARRAY
  //
  for (int i=0; i < intArray.BoundsLength[0]; i++)
    for (int j=0; j < intArray.BoundsLength[1]; j++)
      intArray[i][j] = i*10 + j;

  // Pass array to function that displays values
  //
  Show2DIntArray(intArray.Detach());
}


////////////////////////////////////////////////////////////////////////////////////////
// Server style code: Code illustrates a Server returning a SAFEARRAY property
//
// This illustrates a potential server get_SomeArray property implementation.
// NOTE: Often servers will expose SAFEARRAYs as VARIANTs instead of raw SAFEARRAY
//       The principle is exactly identical except for the line that calls Detach():
//       you'll simply assign what Detach() returns to a dereferenced TVariant!
////////////////////////////////////////////////////////////////////////////////////////
HRESULT Returns_A_SafeArray_Property(SAFEARRAY** /*[out, retval]*/ ppsa)
{
  // Create 3D array
  //
  TSafeArrayDim3 dim(5, 6, 7);
  TSafeArrayDouble3 doubleArray(dim);

  // Initialize SAFEARRAY
  //
  for (int x=0; x < doubleArray.BoundsLength[0]; x++)
    for (int y=0; y < doubleArray.BoundsLength[1]; y++)
      for (int z=0; z < doubleArray.BoundsLength[2]; z++)
        doubleArray[x][y][z] = double(x) * double(y+1) / double(z+2);

  // Detach - passes ownership of SAFEARRAY to caller - caller must destroy array
  //
  *ppsa = doubleArray.Detach();

  // Return SUCCESS
  //
  return S_OK;
}

#endif  // #if 0 (documentation)
////////////////////////////////////////////////////////////////////////////////////////


#if !defined(__SAFEARRAY_H)
#define __SAFEARRAY_H

#include <oaidl.h>
#include <utilcls.h>


// SAFEARRAYBOUND[] wrapper
//
template <int DIM>
class TArrayDimT
{
public:
  TArrayDimT<DIM>(int dim1Len);
  TArrayDimT<DIM>(int dim1Len, int dim2Len);
  TArrayDimT<DIM>(int dim1Len, int dim2Len, int dim3Len);

  operator SAFEARRAYBOUND* ();

  void  set_BoundsLength(int index, long length);
  long  get_BoundsLength(int index);

  __property  long BoundsLength[int index] = { read = get_BoundsLength, write = set_BoundsLength };

protected:
  SAFEARRAYBOUND m_Bounds[DIM];
};


template <int DIM>
TArrayDimT<DIM>::TArrayDimT(int dim1Len)
{
  _ASSERTE(DIM == 1);
  m_Bounds[0].lLbound   = 0;
  m_Bounds[0].cElements = dim1Len;
}

template <int DIM>
TArrayDimT<DIM>::TArrayDimT(int dim1Len, int dim2Len)
{
  _ASSERTE(DIM == 2);
  m_Bounds[0].lLbound   = 0;
  m_Bounds[0].cElements = dim1Len;
  m_Bounds[1].lLbound   = 0;
  m_Bounds[1].cElements = dim2Len;
}

template <int DIM>
TArrayDimT<DIM>::TArrayDimT(int dim1Len, int dim2Len, int dim3Len)
{
  _ASSERTE(DIM == 3);
  m_Bounds[0].lLbound   = 0;
  m_Bounds[0].cElements = dim1Len;
  m_Bounds[1].lLbound   = 0;
  m_Bounds[1].cElements = dim2Len;
  m_Bounds[2].lLbound   = 0;
  m_Bounds[2].cElements = dim3Len;
}

template <int DIM>
TArrayDimT<DIM>::operator SAFEARRAYBOUND* ()
{
  return m_Bounds;
}

template <int DIM> void
TArrayDimT<DIM>::set_BoundsLength(int index, long length)
{
  _ASSERTE(index >= 0);
  _ASSERTE(index < DIM);
  m_Bounds[index].cElements = length;
}

template <int DIM> long
TArrayDimT<DIM>::get_BoundsLength(int index)
{
  _ASSERTE(index >= 0);
  _ASSERTE(index < DIM);
  return m_Bounds[index].cElements;
}


// Template to allow easy access to SAFEARRAY data using []
//
template <class T, int DIM>
class TSAAccessorT
{
public:
  TSAAccessorT(SAFEARRAY* psa, int index) : m_psa(psa), m_Indices(new long[DIM+1]), m_Alloc(true)
  {
    // Store number of dimensions & current index
    m_Indices[DIM] = DIM;
    m_Indices[0]   = index;
    m_Indices++;
  }

  TSAAccessorT<T, DIM-1> operator[](int index)
  {
    *m_Indices = index;
    return TSAAccessorT<T, DIM-1>(m_psa, m_Indices+1);
  }

 ~TSAAccessorT()
  {
    if (m_Alloc)
      delete[] m_Indices;
  }

  friend  TSAAccessorT<T, DIM+1>;

protected:
  TSAAccessorT(SAFEARRAY* psa, long *indices) : m_psa(psa), m_Indices(indices), m_Alloc(false)
  {}

private:
  long*       m_Indices;
  bool        m_Alloc;
  SAFEARRAY*  m_psa;
};

// OLE Documentation: The variant types VT_DISPATCH, VT_UNKNOWN, and VT_BSTR are pointers,
//                    and do not require another level of indirection.
//                    We handle this via a template + specialization
template <class T>
T* TweakTeacake(T& t)
{
  return &t;
}
/* template <> */ inline
BSTR TweakTeacake(BSTR b)
{
  return b;
}
/* template <> */ inline
LPUNKNOWN TweakTeacake(LPUNKNOWN punk)
{
  return punk;
}
/* template <> */ inline
LPDISPATCH TweakTeacake(LPDISPATCH pdsp)
{
  return pdsp;
}

// Specialized version of TSAAccessor for index(1)
//
template <class T>
class TSAAccessorT<T, 1>
{
public:

  TSAAccessorT<T, 1>(SAFEARRAY* psa, int index) : m_psa(psa), m_Indices(m_IndexSingleDim)
  {
    *m_Indices = index;
     m_Indices++;
    *m_Indices = 1;
  }

  operator T ();                // Getter (extracts Element from SAFEARRAY)
  void operator = (T t);        // Putter (puts Element in SAFEARRAY)

protected:
  long*       m_Indices;
  SAFEARRAY*  m_psa;
  long        m_IndexSingleDim[2];

public:
  TSAAccessorT<T, 1>(SAFEARRAY* psa, long *indices) : m_psa(psa), m_Indices(indices)
  {}
};

template <class T>
TSAAccessorT<T, 1>::operator T ()
{
  T t;
  long *pindices =  m_Indices;
  long  idxCount = *pindices;
  while (idxCount--)
    pindices--;
  OLECHECK(::SafeArrayGetElement(m_psa, pindices, (T*)&t));
  return t;
}

template <class T> void
TSAAccessorT<T, 1>::operator = (T t)
{
  long *pindices =  m_Indices;
  long  idxCount = *pindices;
  while (idxCount--)
    pindices--;
  OLECHECK(::SafeArrayPutElement(m_psa, pindices, TweakTeacake(t)));
}

// SAFEARRAY* wrapper
//
template <class T, VARENUM vt, int DIM>
class TSafeArrayT
{
public:
  TSafeArrayT();
  TSafeArrayT(SAFEARRAY *psa);
  TSafeArrayT(TArrayDimT<DIM>& dim);
 ~TSafeArrayT();

  TSafeArrayT(const TSafeArrayT<T, vt, DIM>& src);
  TSafeArrayT<T, vt, DIM>& operator=(const TSafeArrayT<T, vt, DIM>& src);

  TSAAccessorT<T, DIM> operator[] (int index);
  SAFEARRAY**          operator& ();

  long        get_BoundsLength(long idx) const;
  VARENUM     get_VarType() const;
  unsigned    get_Dimension() const;

  long        Elements();

  void        Attach(SAFEARRAY* psa);
  SAFEARRAY*  Detach();
  void        Destroy();

  __property long BoundsLength[long idx] = { read=get_BoundsLength };

  __property VARENUM  VarType   = { read=get_VarType };
  __property unsigned Dimension = { read=get_Dimension };

protected:
  SAFEARRAY   *m_psa;

private:
};

template <class T, VARENUM vt, int DIM>
TSafeArrayT<T, vt, DIM>::TSafeArrayT() : m_psa(0)
{}

template <class T, VARENUM vt, int DIM>
TSafeArrayT<T, vt, DIM>::TSafeArrayT(SAFEARRAY *psa) : m_psa(0)
{
  Attach(psa);
}

template <class T, VARENUM vt, int DIM>
TSafeArrayT<T, vt, DIM>::TSafeArrayT(TArrayDimT<DIM>& dim) : m_psa(0)
{
  m_psa = ::SafeArrayCreate(vt, DIM, dim);
}

template <class T, VARENUM vt, int DIM>
TSafeArrayT<T, vt, DIM>::TSafeArrayT(const TSafeArrayT<T, vt, DIM>& src) : m_psa(0)
{
  if (src.m_psa)
    ::SafeArrayCopy(src.m_psa, &m_psa);
}

template <class T, VARENUM vt, int DIM>
TSafeArrayT<T, vt, DIM>::~TSafeArrayT()
{
  Destroy();
}

template <class T, VARENUM vt, int DIM> TSAAccessorT<T, DIM>
TSafeArrayT<T, vt, DIM>::operator[] (int index)
{
  return TSAAccessorT<T, DIM>(m_psa, index);
}

template <class T, VARENUM vt, int DIM> SAFEARRAY** 
TSafeArrayT<T, vt, DIM>::operator& ()
{
  OLECHECK(/* Only allow access to underlying pointer if null */ m_psa == 0);
  return &m_psa;
}

template <class T, VARENUM vt, int DIM> long
TSafeArrayT<T, vt, DIM>::get_BoundsLength(long idx) const
{
  _ASSERTE(idx >= 0);
  _ASSERTE(unsigned(idx) < Dimension);
  long len = 0;
  if (m_psa)
  {
    long lb, ub;
    ::SafeArrayGetUBound(m_psa, idx+1/*1-based*/, &ub);
    ::SafeArrayGetLBound(m_psa, idx+1/*1-based*/, &lb);
    len = (ub-lb) + 1;
  }
  return len;
}

template <class T, VARENUM vt, int DIM> VARENUM
TSafeArrayT<T, vt, DIM>::get_VarType() const
{
  VARENUM varType = vt;
  if (m_psa)
  {
    static TDll oleAut32(_T("OLEAUT32.DLL")); // SafeArrayGetVartype - Not in all flavors of OLEAUT32.DLL!
    static TDllStdProc2<SAFEARRAY*, VARTYPE*> SafeArrayGetVartypeProc(oleAut32, _T("SafeArrayGetVartype"));
    if (SafeArrayGetVartypeProc)
      SafeArrayGetVartypeProc(m_psa, reinterpret_cast<VARTYPE*>(&varType));
  }
  return varType;
}

template <class T, VARENUM vt, int DIM> unsigned
TSafeArrayT<T, vt, DIM>::get_Dimension() const
{
  return m_psa ? ::SafeArrayGetDim(m_psa) : unsigned(DIM);
}

template <class T, VARENUM vt, int DIM> void
TSafeArrayT<T, vt, DIM>::Attach(SAFEARRAY *psa)
{
  if (m_psa)
    Destroy();
  if (psa)
  {
    m_psa = psa;
    /* Check that the SAFEARRAY we're attaching to is of a compatible VARENUM type & Dimension */
    _ASSERTE(VarType == vt);
    _ASSERTE(Dimension == DIM);
  }
}

template <class T, VARENUM vt, int DIM> SAFEARRAY*
TSafeArrayT<T, vt, DIM>::Detach()
{
  SAFEARRAY *psa = m_psa;
  m_psa = 0;
  return psa;
}

template <class T, VARENUM vt, int DIM> void
TSafeArrayT<T, vt, DIM>::Destroy()
{
  if (m_psa)
  {
    ::SafeArrayDestroy(m_psa);
    m_psa = 0;
  }
}

// Typedefs for commonly used SAFEARRAY types. The appended number identifies the
// number of dimensions in the underlying SAFEARRAY
//
typedef TArrayDimT<1>                           TSafeArrayDim1;
typedef TArrayDimT<2>                           TSafeArrayDim2;
typedef TArrayDimT<3>                           TSafeArrayDim3;

typedef TSafeArrayT<char, VT_I1, 1>             TSafeArrayChar1;
typedef TSafeArrayT<char, VT_I1, 2>             TSafeArrayChar2;
typedef TSafeArrayT<char, VT_I1, 3>             TSafeArrayChar3;

typedef TSafeArrayT<unsigned char, VT_UI1, 1>   TSafeArrayUChar1;
typedef TSafeArrayT<unsigned char, VT_UI1, 2>   TSafeArrayUChar2;
typedef TSafeArrayT<unsigned char, VT_UI1, 3>   TSafeArrayUChar3;

typedef TSafeArrayT<short, VT_I2, 1>            TSafeArrayShort1;
typedef TSafeArrayT<short, VT_I2, 2>            TSafeArrayShort2;
typedef TSafeArrayT<short, VT_I2, 3>            TSafeArrayShort3;

typedef TSafeArrayT<unsigned short, VT_I2, 1>   TSafeArrayUShort1;
typedef TSafeArrayT<unsigned short, VT_I2, 2>   TSafeArrayUShort2;
typedef TSafeArrayT<unsigned short, VT_I2, 3>   TSafeArrayUShort3;

typedef TSafeArrayT<int, VT_I4, 1>              TSafeArrayInt1;
typedef TSafeArrayT<int, VT_I4, 2>              TSafeArrayInt2;
typedef TSafeArrayT<int, VT_I4, 3>              TSafeArrayInt3;

typedef TSafeArrayT<long, VT_I4, 1>             TSafeArrayLong1;
typedef TSafeArrayT<long, VT_I4, 2>             TSafeArrayLong2;
typedef TSafeArrayT<long, VT_I4, 3>             TSafeArrayLong3;

typedef TSafeArrayT<unsigned int, VT_I4, 1>     TSafeArrayUInt1;
typedef TSafeArrayT<unsigned int, VT_I4, 2>     TSafeArrayUInt2;
typedef TSafeArrayT<unsigned int, VT_I4, 3>     TSafeArrayUInt3;

typedef TSafeArrayT<double, VT_R8, 1>           TSafeArrayDouble1;
typedef TSafeArrayT<double, VT_R8, 2>           TSafeArrayDouble2;
typedef TSafeArrayT<double, VT_R8, 3>           TSafeArrayDouble3;

typedef TSafeArrayT<BSTR, VT_BSTR, 1>           TSafeArrayBSTR1;
typedef TSafeArrayT<BSTR, VT_BSTR, 2>           TSafeArrayBSTR2;
typedef TSafeArrayT<BSTR, VT_BSTR, 3>           TSafeArrayBSTR3;

typedef TSafeArrayT<LPUNKNOWN, VT_UNKNOWN, 1>   TSafeArrayUnknown1;
typedef TSafeArrayT<LPUNKNOWN, VT_UNKNOWN, 2>   TSafeArrayUnknown2;
typedef TSafeArrayT<LPUNKNOWN, VT_UNKNOWN, 3>   TSafeArrayUnknown3;

typedef TSafeArrayT<LPDISPATCH, VT_DISPATCH, 1> TSafeArrayDispatch1;
typedef TSafeArrayT<LPDISPATCH, VT_DISPATCH, 2> TSafeArrayDispatch2;
typedef TSafeArrayT<LPDISPATCH, VT_DISPATCH, 3> TSafeArrayDispatch3;


#endif  //  __SAFEARRAY_H
