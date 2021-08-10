// SYSSET.H: Pascal Set types
// Copyright (c) 1997, 1999 Borland International

#if !defined(SYSSET_H)
#define SYSSET_H

#if !defined(SystemHPP)
#error Do not include this file directly.  Include 'system.hpp'.
#endif

#if !defined(SYSMAC_H)
#include <sysmac.h>
#endif

#pragma option push -w-inl -w-lvc

namespace System
{
  // SetBase<> & Set<> are used to emulate Delphi set types

  template<class T, unsigned char minEl, unsigned char maxEl> class RTL_DELPHIRETURN SetBase
  {
  protected:
    unsigned char Data[((((int)(maxEl/8))-((int)(minEl/8))+1) != 3)?
         (((int)(maxEl/8))-((int)(minEl/8))+1): 4];
  };

  template<class T, unsigned char minEl, unsigned char maxEl> class RTL_DELPHIRETURN Set : SetBase<T, minEl, maxEl>
  {

    // Used to generate debug information. (Please, do not remove)
    //
    typedef T TSetTypeRTTI;

  public:
    __fastcall Set() {memset(Data, 0, sizeof (Data));}
    __fastcall Set(const Set& src)
    {
  #pragma option push -w-inl
    for (int i = 0; i < sizeof (Data); i++)
      Data[i] = src.Data[i];
  #pragma option pop
    }

    Set& __fastcall operator =(const Set& rhs)
    {
  #pragma option push -w-inl
    if (this != &rhs)
    {
      for (int i = 0; i < sizeof (Data); i++)
      Data[i] = rhs.Data[i];
    }
    return *this;
  #pragma option pop
    }
    Set& __fastcall operator +=(const Set& rhs)     //Union
    {
  #pragma option push -w-inl
    for (int i = 0; i < sizeof (Data); i++)
      Data[i] |= rhs.Data[i];
    return *this;
  #pragma option pop
    }
    Set& __fastcall operator -=(const Set& rhs)     //Difference
    {
  #pragma option push -w-inl
    for (int i = 0; i < sizeof (Data); i++)
      Data[i] ^= (Data[i] & rhs.Data[i]);
    return *this;
  #pragma option pop
    }
    Set& __fastcall operator *=(const Set& rhs)     //Intersection
    {
  #pragma option push -w-inl
    for (int i = 0; i < sizeof (Data); i++)
      Data[i] &= rhs.Data[i];
    return *this;
  #pragma option pop
    }

    Set __fastcall operator +(const Set& rhs) const //Union
    {
  #pragma option push -w-inl
    Set<T, minEl, maxEl> s;
    for (int i = 0; i < sizeof (Data); i++)
      s.Data[i] = Data[i] | rhs.Data[i];
    return s;
  #pragma option pop
    }
    Set __fastcall operator -(const Set& rhs) const //Difference
    {
  #pragma option push -w-inl
    Set<T, minEl, maxEl> s;
    for (int i = 0; i < sizeof (Data); i++)
      s.Data[i] = Data[i] ^ (Data[i] & rhs.Data[i]);
    return s;
  #pragma option pop
    }
    Set __fastcall operator *(const Set& rhs) const //Intersection
    {
  #pragma option push -w-inl
    Set<T, minEl, maxEl> s;
    for (int i = 0; i < sizeof (Data); i++)
      s.Data[i] = Data[i] & rhs.Data[i];
    return s;
  #pragma option pop
    }

    Set& __fastcall operator <<(const T el) //Add element
    {
  #pragma warn -ccc
  #pragma warn -rng
    if (el >= minEl && el <= maxEl)
  #pragma warn .ccc
  #pragma warn .rng
      Data[(int)(el/8) - (int)(minEl/8)] |=
      (unsigned char)((unsigned short)1 << (el % 8));
    return *this;
    }
    Set& __fastcall operator >>(const T el) //Remove element
    {
  #pragma warn -ccc
  #pragma warn -rng
    if (el >= minEl && el <= maxEl)
  #pragma warn .ccc
  #pragma warn .rng
      Data[(int)(el/8) - (int)(minEl/8)] &=
      (unsigned char)~((unsigned short)1 << (el % 8));
    return *this;
    }

    bool __fastcall Contains(const T el) const
    {
  #pragma warn -ccc
  #pragma warn -rng
    return (el >= minEl && el <= maxEl)?
  #pragma warn .ccc
  #pragma warn .rng
    (Data[(int)(el/8) - (int)(minEl/8)] &
     (unsigned char)((unsigned short)1 << (el % 8))): false;
    }

    Set& __fastcall Clear()
    {
  #pragma option push -w-inl
    for (int i = 0; i < sizeof (Data); i++)
      Data[i] = 0;
    return *this;
  #pragma option pop
    }

    bool __fastcall operator ==(const Set& rhs) const
    {
  #pragma option push -w-inl
    for (int i = 0; i < sizeof (Data); i++)
      if (Data[i] != rhs.Data[i])
      // Not so fast, if first or last byte, make sure that
      // the compare does not include unused bits (mask them)
      if (i == 0)
      {
        if (((0xFF >> (8-(minEl%8))) ^ Data[i]) !=
        ((0xFF >> (8-(minEl%8))) ^ rhs.Data[i]))
        return false;
      }
      else if (sizeof (Data) > 1 && i == sizeof (Data) - 1)
      {
        if (((0xFF << (1+(maxEl%8))) ^ Data[i]) !=
        ((0xFF << (1+(maxEl%8))) ^ rhs.Data[i]))
        return false;
      }
      else
        return false;
    return true;
  #pragma option pop
    }
    bool __fastcall operator !=(const Set& rhs) const {return !operator==(rhs);}
  };
}

// NOTE: Insertion/Extraction operators of VCL classes are only visible
//       if VCL_IOSTREAM is defined.
//
#if defined(VCL_IOSTREAM)

template <class T, unsigned char minEl, unsigned char maxEl>
ostream& operator <<(ostream& os, const Set<T, minEl, maxEl> & arg)
{
  for (int i = minEl; i <= maxEl; i++) {
    if (arg.Contains(static_cast<T>(i)))
      os << '1';
    else
      os << '0';
  }
  return os;
}

template <class T, unsigned char minEl, unsigned char maxEl>
istream& operator >> (istream& is, Set<T, minEl, maxEl> & arg)
{
  unsigned char el;

  arg.Clear();
  for (int i = minEl; i <= maxEl; i++)
  {
    is >> el;
    if (!is)
      break;

    if (el == '1')
      arg << static_cast<T>(i);
  }
  return is;
}

#endif  // VCL_IOSTREAM

#pragma option pop

#endif
