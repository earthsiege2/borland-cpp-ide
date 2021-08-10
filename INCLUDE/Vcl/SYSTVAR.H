// SYSTVAR.H: Pascal TVarRec support (Pascal const parameter types)
//
// $Revision:   1.14  $
// $Date:   02 Sep 1999 18:01:08  $
//
// Copyright (c) 1997, 1999 Borland International

#if !defined(SYSTVAR_H)
#define SYSTVAR_H

#if !defined(SystemHPP)
#error Do not include this file directly.  Include 'system.hpp'.
#endif

#if !defined(SYSMAC_H)
#include <sysmac.h>
#endif

#if !defined(DSTRING_H)
#include <dstring.h>
#endif

#if !defined(WSTRING_H)
#include <wstring.h>
#endif

typedef struct tagSAFEARRAY SAFEARRAY;
typedef struct tagVARIANT VARIANT;

#pragma option push -w-inl -w-lvc

namespace System
{
  // TVarData = VARIANT
  struct TVarData
  {
    union
    {
      Word        VType;    // Delphi-compatible - Variant Type member
      VARTYPE     vt;       // tagVARIANT compatible member
    };
    Word Reserved1;
    Word Reserved2;
    Word Reserved3;
    union
    {
      // Delphi-compatible Variant members
      Smallint      VSmallint;    //  iVal
      Integer       VInteger;     //  lVal
      Single        VSingle;      //  fltVal
      Double        VDouble;      //  dblVal
      CurrencyBase  VCurrency;    //  cyVal
      TDateTimeBase VDate;        //  date
      PWideChar     VOleStr;      //  bstrVal
      IDispatch*    VDispatch;    //  pdispVal
      HResult       VError;       //  scode
      WordBool      VBoolean;     //  boolVal
      IUnknown*     VUnknown;     //  punkVal
      Byte          VByte;        //  bVal
      Pointer       VString;      //  ??????
      PVarArray     VArray;       //  parray
      Pointer       VPointer;     //  byref

      // tagVARIANT compatible members (from OAIDL.H)
      // Allowing all types marked as [V] (may appear in a VARIANT to be initialized
      LONG          lVal;
      BYTE          bVal;
      SHORT         iVal;
      FLOAT         fltVal;
      DOUBLE        dblVal;
      VARIANT_BOOL  boolVal;
      SCODE         scode;
      CY            cyVal;
      DATE          date;
      BSTR          bstrVal;
      IUnknown     *punkVal;
      IDispatch    *pdispVal;
      SAFEARRAY    *parray;
      BYTE         *pbVal;
      SHORT        *piVal;
      LONG         *plVal;
      FLOAT        *pfltVal;
      DOUBLE       *pdblVal;
      VARIANT_BOOL *pboolVal;
      SCODE        *pscode;
      CY           *pcyVal;
      DATE         *pdate;
      BSTR         *pbstrVal;
      IUnknown    **ppunkVal;
      IDispatch   **ppdispVal;
      SAFEARRAY   **pparray;
      VARIANT      *pvarVal;
      PVOID         byref;
      CHAR          cVal;
      USHORT        uiVal;
      ULONG         ulVal;
      INT           intVal;
      UINT          uintVal;
      DECIMAL      *pdecVal;
      CHAR         *pcVal;
      USHORT       *puiVal;
      ULONG        *pulVal;
      INT          *pintVal;
      UINT         *puintVal;
    };
  };

  class   TVarRec;
  typedef TVarRec* PVarRec;

  class TVarRec
  {
  public:
    union
    {
      Integer      VInteger;
      Boolean      VBoolean;
      Char         VChar;
      PExtended    VExtended;
      PShortString VString;
      Pointer      VPointer;
      PChar        VPChar;
      TObject*     VObject;
      TClass       VClass;
      WideChar     VWideChar;
      PWideChar    VPWideChar;
      Pointer      VAnsiString;
      PCurrency    VCurrency;
      PVariant     VVariant;
    };
    union
    {
      Byte VType;
      /*
      long ForceAlignment;
  #if 0
    //! The ForceAlignment should be removed, if alignment set to 4
    //! we don't need this
  #endif
      */
    };

    //---- constructors ----
    __fastcall TVarRec(): VType(vtInteger), VInteger(0) {} //default int 0
    __fastcall TVarRec(Integer src): VType(vtInteger), VInteger(src) {}
    __fastcall TVarRec(Boolean src): VType(vtBoolean), VBoolean(src) {}
    __fastcall TVarRec(char src): VType(vtChar), VChar(src) {}
    __fastcall TVarRec(const Extended& src): VType(vtExtended), VExtended(const_cast<Extended*>(&src)) {}
    __fastcall TVarRec(const ShortString& src): VType(vtString), VString(const_cast<PShortString>(&src)) {}
    __fastcall TVarRec(const Pointer src): VType(vtPointer), VPointer(src) {}
    __fastcall TVarRec(const PChar src): VType(vtPChar), VPChar(src) {}
    __fastcall TVarRec(const char* src): VType(vtPChar), VPChar(reinterpret_cast<PChar>(const_cast<char*>(src))) {}
    __fastcall TVarRec(const TObject& src): VType(vtObject), VObject(const_cast<TObject*>(&src)) {}
    __fastcall TVarRec(const TClass src): VType(vtClass), VClass(src) {}
    __fastcall TVarRec(WideChar src): VType(vtWideChar), VWideChar(src) {}
    __fastcall TVarRec(const PWideChar src): VType(vtPWideChar), VPWideChar(src) {}
    __fastcall TVarRec(const AnsiString src): VType(vtAnsiString), VAnsiString(const_cast<void*>(src.data())) {}
    __fastcall TVarRec(const Currency& src): VType(vtCurrency), VCurrency(const_cast<PCurrency>(&src)) {}
    __fastcall TVarRec(const Variant& src): VType(vtVariant), VVariant(const_cast<PVariant>(&src)) {}

    //---- assignments ----
    TVarRec& __fastcall operator =(Integer src)
    {
      VType = vtInteger;
      VInteger = src;
      return *this;
    }

    TVarRec& __fastcall operator =(Boolean src)
    {
      VType = vtBoolean;
      VBoolean = src;
      return *this;
    }

    TVarRec& __fastcall operator =(char src)
    {
      VType = vtChar;
      VChar = src;
      return *this;
    }

    TVarRec& __fastcall operator =(const Extended& src)
    {
      VType = vtExtended;
      VExtended = const_cast<PExtended>(&src);
      return *this;
    }

    TVarRec& __fastcall operator =(const ShortString& src)
    {
      VType = vtString;
      VString = const_cast<PShortString>(&src);
      return *this;
    }

    TVarRec& __fastcall operator =(const Pointer src)
    {
      VType = vtPointer;
      VPointer = src;
      return *this;
    }

    TVarRec& __fastcall operator =(const PChar src)
    {
      VType = vtPChar;
      VPChar = src;
      return *this;
    }

    TVarRec& __fastcall operator =(const char* src)
    {
      VType = vtPChar;
      VPChar = reinterpret_cast<PChar>(const_cast<char*>(src));
      return *this;
    }

    TVarRec& __fastcall operator =(const TObject& src)
    {
      VType = vtObject;
      VObject = const_cast<TObject*>(&src);
      return *this;
    }

    TVarRec& __fastcall operator =(const TClass src)
    {
      VType = vtClass;
      VClass = src;
      return *this;
    }

    TVarRec& __fastcall operator =(WideChar src)
    {
      VType = vtWideChar;
      VWideChar = src;
      return *this;
    }

    TVarRec& __fastcall operator =(const PWideChar src)
    {
      VType = vtPWideChar;
      VPWideChar = src;
      return *this;
    }

    TVarRec& __fastcall operator =(const AnsiString src)
    {
      VType = vtAnsiString;
      VAnsiString = const_cast<void*>(src.data());
      return *this;
    }

    TVarRec& __fastcall operator =(const Currency& src)
    {
      VType = vtCurrency;
      VCurrency = const_cast<PCurrency>(&src);
      return *this;
    }

    TVarRec& __fastcall operator =(const Variant& src)
    {
      VType = vtVariant;
      VVariant = const_cast<PVariant>(&src);
      return *this;
    }

  };
}

#pragma option 			 pop

#endif
