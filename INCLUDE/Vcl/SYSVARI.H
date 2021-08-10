// SYSVARI.H: Pascal Variant & Olevariant classes
//
// $Revision:   1.20.2.0.1.9  $
// $Date:   25 Jan 2002 12:54:26  $
//
// Copyright (c) 1997, 2002 Borland Software Corporation

#define TVARIANT_ON

#if !defined(SYSVARI_H)
#define SYSVARI_H

#if !defined(SystemHPP)
#error Do not include this file directly.  Include 'system.hpp'.
#endif

#if !defined(SYSMAC_H)
#include <sysmac.h>
#endif

// The following bring in basic windows types + IUnknown
//

// are these available under linux? almost certainly not. Is there a linux
// available definition of IUnknown and IDispatch? if so, where? --aph

#include <wtypes.h>
#include <unknwn.h>

#if !defined(DISPATCH_METHOD)
#define DISPATCH_METHOD         0x1
#endif
#if !defined(DISPATCH_PROPERTYGET)
#define DISPATCH_PROPERTYGET    0x2
#endif
#if !defined(DISPATCH_PROPERTYPUT)
#define DISPATCH_PROPERTYPUT    0x4
#endif
#if !defined(DISPATCH_PROPERTYPUTREF)
#define DISPATCH_PROPERTYPUTREF 0x8
#endif

// The following are Automation related structures required by either Variant
// or some other VCL Header. We forward ref. the tagStruct and #define the
// typedef name to the tagStruct.
//
interface IDispatch;
typedef union     tagCY   CURRENCY;
typedef struct    tagSAFEARRAY  SAFEARRAY;
typedef struct    tagVARIANT  VARIANT;
struct    tagSTATSTG;
class     TAutoArgsBase;
template <int count> class  TAutoArgs;

#ifdef TVARIANT_ON
template  <class T> class     TVariantT;
typedef   TVariantT<VARIANT>  TVariant;
#endif


#if !defined(SYSTVAR_H)
#include <systvar.h>
#endif

#pragma option push -w-inl -w-lvc

namespace System
{

// NOTE: Defined in OLEAUTO - Keep in sync.
//
static const short int MaxDispArgs = 0x20; // (BCB-42024)


// Variant Type Descriptors (from System unit)
//
//  varEmpty      <=> VT_EMPTY
//  varNull       <=> VT_NULL
//  varSmallint   <=> VT_I2
//  varInteger    <=> VT_I3
//  varSingle     <=> VT_R4
//  varDouble     <=> VT_R8
//  varCurrency   <=> VT_CY
//  varDate       <=> VT_DATE
//  varOleStr     <=> VT_BSTR
//  varDispatch   <=> VT_DISPATCH
//  varError      <=> VT_ERROR
//  varBoolean    <=> VT_BOOL
//  varVariant    <=> VT_VARIANT
//  varUnknown    <=> VT_UNKNOWN
//  varByte       <=> VT_UI1
//  varString     <=> ??_??
//  varTypeMask   <=> VT_TYPEMASK
//  varArray      <=> VT_ARRAY
//  varByRef      <=> VT_BYREF
//  varStrArg     <=> VT_CLSID

  // Encapsulates error code to be stored in Variant
  //
  class VariantError
  {
  public:
    VariantError(SCODE err = DISP_E_PARAMNOTFOUND) : m_scode(err)
    {}
    operator SCODE () const
    {
       return m_scode;
    }
    VariantError& operator = (SCODE err)
    {
      m_scode = err;
      return *this;
    }

  protected:
    SCODE m_scode;
  };

  class AutoCmd;

  class RTL_DELPHIRETURN Variant: public TVarData
  {
    friend class AutoCmd;

// NOTE: Insertion/Extraction operators of VCL classes are only visible
//       if VCL_IOSTREAM is defined.
//
#if defined(VCL_IOSTREAM)
    friend ostream& operator << (ostream& os, const Variant& arg);
#endif

  public:
    static Variant __fastcall CreateObject(const String& ProgID);
    static Variant __fastcall GetActiveObject(const String& ProgID);

    // Default Ctr
    __fastcall Variant();

    // Copy Ctr
    __fastcall Variant(const Variant& src);

    // Ctr - From basic C++ types
    __fastcall Variant(const bool src);

    __fastcall Variant(const char src);
    __fastcall Variant(const signed char src);
    __fastcall Variant(const unsigned char src);

    __fastcall Variant(const short src);
    __fastcall Variant(const unsigned short src);

    __fastcall Variant(const int src);
    __fastcall Variant(const unsigned int src);

    __fastcall Variant(const long src);
    __fastcall Variant(const unsigned long src);

    __fastcall Variant(const float src);
    __fastcall Variant(const double src);
    __fastcall Variant(const long double src);
    __fastcall Variant(const __int64 src);

    // Ctr - From OLE structures
    __fastcall Variant(const CURRENCY& src);
    __fastcall Variant(SAFEARRAY& src);
    __fastcall Variant(SAFEARRAY* src);
#ifdef WIN32
    __fastcall Variant(const VARIANT& src);
    __fastcall Variant(VARIANT*   src);
#endif
#ifdef TVARIANT_ON
    __fastcall Variant(const TVariant& src);
#endif

    // Ctr - From utility classes
    __fastcall Variant(const AnsiString& src);
    __fastcall Variant(const Currency& src);
    __fastcall Variant(const TDateTime& src);
    __fastcall Variant(const VariantError& src);
    __fastcall Variant(const WideString& src);

    // Asciiz pointer
    __fastcall Variant(const char* src);            // Treated as pointer Asciiz string

    // Ctr - OLE ptrs
    __fastcall Variant(wchar_t* src);               // BSTR support
    __fastcall Variant(IUnknown* src);
    __fastcall Variant(IInterface* src);
    __fastcall Variant(IDispatch* src);

    // Ref-counted Dispatch interface object
    __fastcall Variant(const System::DelphiInterface<IDispatch>& src);

    //By ref constructors
    __fastcall Variant(signed char* src);
    __fastcall Variant(unsigned char* src);

    __fastcall Variant(short* src);
    __fastcall Variant(unsigned short* src);

    __fastcall Variant(int* src);
    __fastcall Variant(unsigned int* src);

    __fastcall Variant(long* src);
    __fastcall Variant(unsigned long* src);

    __fastcall Variant(float* src);
    __fastcall Variant(double* src);

    __fastcall Variant(__int64* src);

    __fastcall Variant(CURRENCY* src);
    __fastcall Variant(SAFEARRAY** src);

    __fastcall Variant(wchar_t** src);              // VT_BSTR|VT_BYREF

    // Ref Vcl classes
    __fastcall Variant(Currency* src);
    __fastcall Variant(TDateTime* src);
    __fastcall Variant(Variant* src);

    // Constructor for array of variants of type varType
    __fastcall Variant(const int* bounds, const int boundsSize, Word varType);

    // Constructor for one dimensional array of type Variant
    __fastcall Variant(const Variant* values, const int valuesSize);

    __fastcall ~Variant();

    // Assignments
    Variant& __fastcall operator =(const Variant& rhs);

    Variant& __fastcall operator =(const bool src);

    Variant& __fastcall operator =(const char src);
    Variant& __fastcall operator =(const signed char src);
    Variant& __fastcall operator =(const unsigned char src);

    Variant& __fastcall operator =(const short src);
    Variant& __fastcall operator =(const unsigned short src);

    Variant& __fastcall operator =(const int src);
    Variant& __fastcall operator =(const unsigned int src);

    Variant& __fastcall operator =(const long src);
    Variant& __fastcall operator =(const unsigned long src);

    Variant& __fastcall operator =(const float src);
    Variant& __fastcall operator =(const double src);
    Variant& __fastcall operator =(const __int64 src);

    Variant& __fastcall operator =(const CURRENCY& src);
    Variant& __fastcall operator =(SAFEARRAY* src);
    Variant& __fastcall operator =(SAFEARRAY& src);
#ifdef WIN32
    Variant& __fastcall operator =(const VARIANT& rhs);
    Variant& __fastcall operator =(VARIANT* rhs);
#endif
#ifdef TVARIANT_ON
    Variant& __fastcall operator =(const TVariant& rhs);
    Variant& __fastcall operator =(TVariant* rhs);
#endif

    Variant& __fastcall operator =(const AnsiString& src);
    Variant& __fastcall operator =(const Currency& src);
    Variant& __fastcall operator =(const TDateTime& src);
    Variant& __fastcall operator =(const VariantError& src);
    Variant& __fastcall operator =(const WideString& src);
    Variant& __fastcall operator =(const System::DelphiInterface<IDispatch>& src);


    Variant& __fastcall operator =(wchar_t* src);             // BSTR support
    Variant& __fastcall operator =(IUnknown* src);
    Variant& __fastcall operator =(IInterface* src);
    Variant& __fastcall operator =(IDispatch* src);

    // By ref Assignment
    Variant& __fastcall operator =(const char* src);          // Treated as pointer Asciiz string
    Variant& __fastcall operator =(signed char* src);
    Variant& __fastcall operator =(unsigned char* src);

    Variant& __fastcall operator =(short* src);
    Variant& __fastcall operator =(unsigned short* src);

    Variant& __fastcall operator =(int* src);
    Variant& __fastcall operator =(unsigned int* src);

    Variant& __fastcall operator =(long* src);
    Variant& __fastcall operator =(unsigned long* src);

    Variant& __fastcall operator =(float* src);
    Variant& __fastcall operator =(double* src);
    Variant& __fastcall operator =(__int64* src);

    Variant& __fastcall operator =(CURRENCY* src);
    Variant& __fastcall operator =(SAFEARRAY** src);

    Variant& __fastcall operator =(wchar_t** src);            // VT_BSTR|VT_BYREF
    Variant& __fastcall operator =(IUnknown** src);
    Variant& __fastcall operator =(IInterface**src);
    Variant& __fastcall operator =(IDispatch** src);

    Variant& __fastcall operator =(Currency* src);
    Variant& __fastcall operator =(TDateTime* src);
    Variant& __fastcall operator =(Variant* src);

    // Exotic operators
    Variant& __fastcall operator +=(const Variant& rhs);
    Variant& __fastcall operator -=(const Variant& rhs);
    Variant& __fastcall operator *=(const Variant& rhs);
    Variant& __fastcall operator /=(const Variant& rhs);
    Variant& __fastcall operator %=(const Variant& rhs);
    Variant& __fastcall operator &=(const Variant& rhs);
    Variant& __fastcall operator |=(const Variant& rhs);
    Variant& __fastcall operator ^=(const Variant& rhs);
    Variant& __fastcall operator <<=(const Variant& rhs);
    Variant& __fastcall operator >>=(const Variant& rhs);

    // comparisons (Variant on right)
    bool __fastcall operator ==(const Variant& rhs) const;
    bool __fastcall operator !=(const Variant& rhs) const;
    bool __fastcall operator < (const Variant& rhs) const;
    bool __fastcall operator > (const Variant& rhs) const;
    bool __fastcall operator <=(const Variant& rhs) const;
    bool __fastcall operator >=(const Variant& rhs) const;

    // comparisons (int on right)
    bool __fastcall operator ==(int rhs) const
    {return operator ==(Variant(rhs));}
    bool __fastcall operator !=(int rhs) const
    {return operator !=(Variant(rhs));}
    bool __fastcall operator < (int rhs) const
    {return operator < (Variant(rhs));}
    bool __fastcall operator > (int rhs) const
    {return operator > (Variant(rhs));}
    bool __fastcall operator <=(int rhs) const
    {return operator <=(Variant(rhs));}
    bool __fastcall operator >=(int rhs) const
    {return operator >=(Variant(rhs));}

    // comparisons (string on right)
    bool __fastcall operator ==(const AnsiString& rhs) const
    { return AnsiString(*this) == rhs;}

    // comparisons (double on right)
    bool __fastcall operator ==(double rhs) const
    {return operator ==(Variant(rhs));}
    bool __fastcall operator !=(double rhs) const
    {return operator !=(Variant(rhs));}
    bool __fastcall operator < (double rhs) const
    {return operator <(Variant(rhs));}
    bool __fastcall operator > (double rhs) const
    {return operator >(Variant(rhs));}
    bool __fastcall operator <=(double rhs) const
    {return operator <=(Variant(rhs));}
    bool __fastcall operator >=(double rhs) const
    {return operator >=(Variant(rhs));}

    // binary operators (Variant on right)
    Variant __fastcall operator +(const Variant& rhs) const;
    Variant __fastcall operator -(const Variant& rhs) const;
    Variant __fastcall operator *(const Variant& rhs) const;
    Variant __fastcall operator /(const Variant& rhs) const;
    Variant __fastcall operator %(const Variant& rhs) const;
    Variant __fastcall operator &(const Variant& rhs) const;
    Variant __fastcall operator |(const Variant& rhs) const;
    Variant __fastcall operator ^(const Variant& rhs) const;
    Variant __fastcall operator <<(const Variant& rhs) const;
    Variant __fastcall operator >>(const Variant& rhs) const;

    // binary operators (AnsiString on right)
    Variant __fastcall operator -(const AnsiString& rhs) const
    {return operator -(Variant(rhs));}
    Variant __fastcall operator *(const AnsiString& rhs) const
    {return operator *(Variant(rhs));}
    Variant __fastcall operator /(const AnsiString& rhs) const
    {return operator /(Variant(rhs));}
    Variant __fastcall operator %(const AnsiString& rhs) const
    {return operator %(Variant(rhs));}
    Variant __fastcall operator &(const AnsiString& rhs) const
    {return operator &(Variant(rhs));}
    Variant __fastcall operator |(const AnsiString& rhs) const
    {return operator |(Variant(rhs));}
    Variant __fastcall operator ^(const AnsiString& rhs) const
    {return operator ^(Variant(rhs));}
    Variant __fastcall operator <<(const AnsiString& rhs) const
    {return operator <<(Variant(rhs));}
    Variant __fastcall operator >>(const AnsiString& rhs) const
    {return operator >>(Variant(rhs));}

    // binary operators (int on right)
    Variant __fastcall operator +(int rhs) const
    {return operator +(Variant(rhs));}
    Variant __fastcall operator -(int rhs) const
    {return operator -(Variant(rhs));}
    Variant __fastcall operator *(int rhs) const
    {return operator *(Variant(rhs));}
    Variant __fastcall operator /(int rhs) const
    {return operator /(Variant(rhs));}
    Variant __fastcall operator %(int rhs) const
    {return operator %(Variant(rhs));}
    Variant __fastcall operator &(int rhs) const
    {return operator &(Variant(rhs));}
    Variant __fastcall operator |(int rhs) const
    {return operator |(Variant(rhs));}
    Variant __fastcall operator ^(int rhs) const
    {return operator ^(Variant(rhs));}
    Variant __fastcall operator <<(int rhs) const
    {return operator <<(Variant(rhs));}
    Variant __fastcall operator >>(int rhs) const
    {return operator >>(Variant(rhs));}

    // binary operators (double on right)
    Variant __fastcall operator +(double rhs) const
    {return operator +(Variant(rhs));}
    Variant __fastcall operator -(double rhs) const
    {return operator -(Variant(rhs));}
    Variant __fastcall operator *(double rhs) const
    {return operator *(Variant(rhs));}
    Variant __fastcall operator /(double rhs) const
    {return operator /(Variant(rhs));}
    Variant __fastcall operator %(double rhs) const
    {return operator %(Variant(rhs));}
    Variant __fastcall operator &(double rhs) const
    {return operator &(Variant(rhs));}
    Variant __fastcall operator |(double rhs) const
    {return operator |(Variant(rhs));}
    Variant __fastcall operator ^(double rhs) const
    {return operator ^(Variant(rhs));}
    Variant __fastcall operator <<(double rhs) const
    {return operator <<(Variant(rhs));}
    Variant __fastcall operator >>(double rhs) const
    {return operator >>(Variant(rhs));}

    // unary operators
    Variant __fastcall operator -() const;
    Variant __fastcall operator !() const;

    // Conversion operators
    __fastcall operator bool()            const;

    __fastcall operator char()            const;
    __fastcall operator signed char()     const;
    __fastcall operator unsigned char()   const;

    __fastcall operator short()           const;
    __fastcall operator unsigned short()  const;

    __fastcall operator int()             const;
    __fastcall operator unsigned int()    const;

    __fastcall operator long()            const;
    __fastcall operator unsigned long()   const;

    __fastcall operator float()           const;
    __fastcall operator double()          const;
    __fastcall operator __int64()         const;

    __fastcall operator AnsiString()      const;
    __fastcall operator Currency()        const;
    __fastcall operator TDateTime()       const;
    __fastcall operator WideString()      const;

    __fastcall operator CURRENCY()        const;
#ifdef WIN32
    __fastcall operator VARIANT();
#endif
#ifdef TVARIANT_ON
    __fastcall operator TVariant();
#endif

    __fastcall operator wchar_t*()        const;
    __fastcall operator IDispatch*();
    __fastcall operator IUnknown*();
    __fastcall operator IInterface*();

    // by ref conversion operators
    /*__fastcall operator char*();*/  // Dangerous - easily used as string instead of VT_I1|VT_BYREF
    __fastcall operator signed char*();
    __fastcall operator unsigned char*();


    __fastcall operator short*();
    __fastcall operator unsigned short*();

    __fastcall operator int*();
    __fastcall operator unsigned int*();

    __fastcall operator long*();
    __fastcall operator unsigned long*();

    __fastcall operator float*();
    __fastcall operator double*();

    /*__fastcall operator CURRENCY*()       const;*/
    /*__fastcall operator SAFEARRAY**()     const;*/
#ifdef WIN32
    __fastcall operator VARIANT*();
#endif
#ifdef TVARIANT_ON
    __fastcall operator TVariant*();
#endif

    __fastcall operator Currency*();
    __fastcall operator TDateTime*();
    __fastcall operator wchar_t**();

    // HRESULT methods
    //
    void    __fastcall SetError(const HResult err);
    HResult __fastcall GetError() const;

    // Manipulate/Set vt_xxx Type
    //
    void      __fastcall Clear();
    Variant&  __fastcall ChangeType(int VarType);
    Variant   __fastcall AsType(int VarType) const;
    Variant   __fastcall Sanitized() const;

    // Query vt_xxx Type
    //
    int   __fastcall Type()     const;
    bool  __fastcall IsNull()   const;
    bool  __fastcall IsEmpty()  const;

    // Get Base Variant (when vt==VT_VARIANT)
    //
    Variant* __fastcall GetBaseVariant();

    // Array support
    //
    bool    __fastcall IsArray() const;
    Variant __fastcall GetElement(const int i1) const;
    Variant __fastcall GetElement(const int i1, const int i2) const;
    Variant __fastcall GetElement(const int i1, const int i2, const int i3) const;
    Variant __fastcall GetElement(const int i1, const int i2, const int i3, const int i4) const;
    Variant __fastcall GetElement(const int i1, const int i2, const int i3, const int i4, const int i5) const;
    void    __fastcall PutElement(const Variant& data, const int i1);
    void    __fastcall PutElement(const Variant& data, const int i1, const int i2);
    void    __fastcall PutElement(const Variant& data, const int i1, const int i2,const int i3);
    void    __fastcall PutElement(const Variant& data, const int i1, const int i2,const int i3, const int i4);
    void    __fastcall PutElement(const Variant& data, const int i1, const int i2,const int i3, const int i4, const int i5);

    int     __fastcall ArrayDimCount() const;
    int     __fastcall ArrayLowBound(const int dim = 1) const;
    int     __fastcall ArrayHighBound(const int dim = 1) const;
    void    __fastcall ArrayRedim(int highBound);
    Pointer __fastcall ArrayLock();
    void    __fastcall ArrayUnlock();

    // Automation Goodies
    //
    Variant __fastcall Exec(AutoCmd& cmd, Integer lcid = LOCALE_SYSTEM_DEFAULT) const;

    // Helper routines used by template member functions
    //
    void    OleProcedure  (const String& name, TAutoArgsBase* args = 0);
    Variant OleFunction   (const String& name, TAutoArgsBase* args = 0);
    Variant OlePropertyGet(const String& name, TAutoArgsBase* args = 0);
    void    OlePropertySet(const String& name, TAutoArgsBase& args);


    template <class P1>
    void OleProcedure(const String& name, P1 p1);

    template <class P1, class P2>
    void OleProcedure(const String& name, P1 p1, P2 p2);

    template <class P1, class P2, class P3>
    void OleProcedure(const String& name, P1 p1, P2 p2, P3 p3);

    template <class P1, class P2, class P3, class P4>
    void OleProcedure(const String& name, P1 p1, P2 p2, P3 p3, P4 p4);

    template <class P1, class P2, class P3, class P4, class P5>
    void OleProcedure(const String& name, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6>
    void OleProcedure(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7>
    void OleProcedure(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8>
    void OleProcedure(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9>
    void OleProcedure(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10>
    void OleProcedure(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11>
    void OleProcedure(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12>
    void OleProcedure(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13>
    void OleProcedure(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14>
    void OleProcedure(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15>
    void OleProcedure(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16>
    void OleProcedure(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17>
    void OleProcedure(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17, class P18>
    void OleProcedure(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17, P18 p18);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17, class P18, class P19>
    void OleProcedure(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17, P18 p18, P19 p19);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17, class P18, class P19, class P20>
    void OleProcedure(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17, P18 p18, P19 p19, P20 p20);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17, class P18, class P19, class P20,
              class P21>
    void OleProcedure(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
      P21 p21);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17, class P18, class P19, class P20,
              class P21, class P22>
    void OleProcedure(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
      P21 p21, P22 p22);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17, class P18, class P19, class P20,
              class P21, class P22, class P23>
    void OleProcedure(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
      P21 p21, P22 p22, P23 p23);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17, class P18, class P19, class P20,
              class P21, class P22, class P23, class P24>
    void OleProcedure(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
      P21 p21, P22 p22, P23 p23, P24 p24);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17, class P18, class P19, class P20,
              class P21, class P22, class P23, class P24, class P25>
    void OleProcedure(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
      P21 p21, P22 p22, P23 p23, P24 p24, P25 p25);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17, class P18, class P19, class P20,
              class P21, class P22, class P23, class P24, class P25,
              class P26>
    void OleProcedure(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
      P21 p21, P22 p22, P23 p23, P24 p24, P25 p25,
      P26 p26);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17, class P18, class P19, class P20,
              class P21, class P22, class P23, class P24, class P25,
              class P26, class P27>
    void OleProcedure(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
      P21 p21, P22 p22, P23 p23, P24 p24, P25 p25,
      P26 p26, P27 p27);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17, class P18, class P19, class P20,
              class P21, class P22, class P23, class P24, class P25,
              class P26, class P27, class P28>
    void OleProcedure(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
      P21 p21, P22 p22, P23 p23, P24 p24, P25 p25,
      P26 p26, P27 p27, P28 p28);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17, class P18, class P19, class P20,
              class P21, class P22, class P23, class P24, class P25,
              class P26, class P27, class P28, class P29>
    void OleProcedure(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
      P21 p21, P22 p22, P23 p23, P24 p24, P25 p25,
      P26 p26, P27 p27, P28 p28, P29 p29);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17, class P18, class P19, class P20,
              class P21, class P22, class P23, class P24, class P25,
              class P26, class P27, class P28, class P29, class P30>
    void OleProcedure(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
      P21 p21, P22 p22, P23 p23, P24 p24, P25 p25,
      P26 p26, P27 p27, P28 p28, P29 p29, P30 p30);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17, class P18, class P19, class P20,
              class P21, class P22, class P23, class P24, class P25,
              class P26, class P27, class P28, class P29, class P30,
              class P31>
    void OleProcedure(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
      P21 p21, P22 p22, P23 p23, P24 p24, P25 p25,
      P26 p26, P27 p27, P28 p28, P29 p29, P30 p30,
      P31 p31);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17, class P18, class P19, class P20,
              class P21, class P22, class P23, class P24, class P25,
              class P26, class P27, class P28, class P29, class P30,
              class P31, class P32>
    void OleProcedure(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
      P21 p21, P22 p22, P23 p23, P24 p24, P25 p25,
      P26 p26, P27 p27, P28 p28, P29 p29, P30 p30,
      P31 p31, P32 p32);

    template <class P1>
    Variant OleFunction(const String& name, P1 p1);

    template <class P1, class P2>
    Variant OleFunction(const String& name, P1 p1, P2 p2);

    template <class P1, class P2, class P3>
    Variant OleFunction(const String& name, P1 p1, P2 p2, P3 p3);

    template <class P1, class P2, class P3, class P4>
    Variant OleFunction(const String& name, P1 p1, P2 p2, P3 p3, P4 p4);

    template <class P1, class P2, class P3, class P4, class P5>
    Variant OleFunction(const String& name, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6>
    Variant OleFunction(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7>
    Variant OleFunction(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8>
    Variant OleFunction(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9>
    Variant OleFunction(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10>
    Variant OleFunction(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11>
    Variant OleFunction(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12>
    Variant OleFunction(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13>
    Variant OleFunction(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14>
    Variant OleFunction(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15>
    Variant OleFunction(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16>
    Variant OleFunction(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17>
    Variant OleFunction(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17, class P18>
    Variant OleFunction(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17, P18 p18);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17, class P18, class P19>
    Variant OleFunction(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17, P18 p18, P19 p19);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17, class P18, class P19, class P20>
    Variant OleFunction(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17, P18 p18, P19 p19, P20 p20);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17, class P18, class P19, class P20,
              class P21>
    Variant OleFunction(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
      P21 p21);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17, class P18, class P19, class P20,
              class P21, class P22>
    Variant OleFunction(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
      P21 p21, P22 p22);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17, class P18, class P19, class P20,
              class P21, class P22, class P23>
    Variant OleFunction(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
      P21 p21, P22 p22, P23 p23);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17, class P18, class P19, class P20,
              class P21, class P22, class P23, class P24>
    Variant OleFunction(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
      P21 p21, P22 p22, P23 p23, P24 p24);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17, class P18, class P19, class P20,
              class P21, class P22, class P23, class P24, class P25>
    Variant OleFunction(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
      P21 p21, P22 p22, P23 p23, P24 p24, P25 p25);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17, class P18, class P19, class P20,
              class P21, class P22, class P23, class P24, class P25,
              class P26>
    Variant OleFunction(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
      P21 p21, P22 p22, P23 p23, P24 p24, P25 p25,
      P26 p26);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17, class P18, class P19, class P20,
              class P21, class P22, class P23, class P24, class P25,
              class P26, class P27>
    Variant OleFunction(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
      P21 p21, P22 p22, P23 p23, P24 p24, P25 p25,
      P26 p26, P27 p27);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17, class P18, class P19, class P20,
              class P21, class P22, class P23, class P24, class P25,
              class P26, class P27, class P28>
    Variant OleFunction(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
      P21 p21, P22 p22, P23 p23, P24 p24, P25 p25,
      P26 p26, P27 p27, P28 p28);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17, class P18, class P19, class P20,
              class P21, class P22, class P23, class P24, class P25,
              class P26, class P27, class P28, class P29>
    Variant OleFunction(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
      P21 p21, P22 p22, P23 p23, P24 p24, P25 p25,
      P26 p26, P27 p27, P28 p28, P29 p29);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17, class P18, class P19, class P20,
              class P21, class P22, class P23, class P24, class P25,
              class P26, class P27, class P28, class P29, class P30>
    Variant OleFunction(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
      P21 p21, P22 p22, P23 p23, P24 p24, P25 p25,
      P26 p26, P27 p27, P28 p28, P29 p29, P30 p30);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17, class P18, class P19, class P20,
              class P21, class P22, class P23, class P24, class P25,
              class P26, class P27, class P28, class P29, class P30,
              class P31>
    Variant OleFunction(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
      P21 p21, P22 p22, P23 p23, P24 p24, P25 p25,
      P26 p26, P27 p27, P28 p28, P29 p29, P30 p30,
      P31 p31);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10,
              class P11, class P12, class P13, class P14, class P15,
              class P16, class P17, class P18, class P19, class P20,
              class P21, class P22, class P23, class P24, class P25,
              class P26, class P27, class P28, class P29, class P30,
              class P31, class P32>
    Variant OleFunction(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
      P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
      P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
      P21 p21, P22 p22, P23 p23, P24 p24, P25 p25,
      P26 p26, P27 p27, P28 p28, P29 p29, P30 p30,
      P31 p31, P32 p32);

    template <class P1>
    Variant OlePropertyGet(const String& name, P1 p1);

    template <class P1, class P2>
    Variant OlePropertyGet(const String& name, P1 p1, P2 p2);

    template <class P1, class P2, class P3>
    Variant OlePropertyGet(const String& name, P1 p1, P2 p2, P3 p3);

    template <class P1, class P2, class P3, class P4>
    Variant OlePropertyGet(const String& name, P1 p1, P2 p2, P3 p3, P4 p4);

    template <class P1, class P2, class P3, class P4, class P5>
    Variant OlePropertyGet(const String& name, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6>
    Variant OlePropertyGet(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7>
    Variant OlePropertyGet(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8>
    Variant OlePropertyGet(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9>
    Variant OlePropertyGet(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10>
    Variant OlePropertyGet(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10);

    template <class P1>
    void OlePropertySet(const String& name, P1 p1);

    template <class P1, class P2>
    void OlePropertySet(const String& name, P1 p1, P2 p2);

    template <class P1, class P2, class P3>
    void OlePropertySet(const String& name, P1 p1, P2 p2, P3 p3);

    template <class P1, class P2, class P3, class P4>
    void OlePropertySet(const String& name, P1 p1, P2 p2, P3 p3, P4 p4);

    template <class P1, class P2, class P3, class P4, class P5>
    void OlePropertySet(const String& name, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6>
    void OlePropertySet(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7>
    void OlePropertySet(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8>
    void OlePropertySet(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9>
    void OlePropertySet(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9);

    template <class P1, class P2, class P3, class P4, class P5,
              class P6, class P7, class P8, class P9, class P10>
    void OlePropertySet(const String& name,
      P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
      P6 p6, P7 p7, P8 p8, P9 p9, P10 p10);


    // End of Alternate Syntax for Automation

    // Ref. to Variant which can be used for non-specified optional parameters or 'Empty' parameters
    static Variant& NoParam();
    static Variant& Empty();

  private:
    // AutoCmd::GetParm & GetNamedParm uses operator [] (AutoCmd is a friend)
    // operator[] can only be used for arrays of type Variant
    Variant& __fastcall operator [](const int idx);
};
}
#if !defined(__AUTOARGS_DEFINED)
#define __AUTOARGS_DEFINED
class TAutoArgsBase
{
protected:
  TAutoArgsBase(Variant *pVariant, int count) : m_Variant(pVariant), m_Count(count)
  {}

public:
  Variant& operator[](int index) const
  {
    // NOTE: It's OK to use Count - there's an extra Variant for return result
    //       Zero'th entry's reserved for return value.
    //
   /* _ASSERTE_(index <= m_Count);
    _ASSERTE_(index >= 0);         */

    // Make up for C++ vs. Basic reverse indexing
    //
    return m_Variant[index ? (m_Count+1-index) : 0];
  }

  Variant* GetRetVal() const
  {
    return &m_Variant[0];
  }

  Variant& GetRetVariant()
  {
    return *m_Variant;
  }

  Variant* GetArgs() const
  {
    return (Variant*)(m_Variant+1);
  }

  int GetCount() const
  {
    return m_Count;
  }

private:
  TAutoArgsBase(const TAutoArgsBase&);
  TAutoArgsBase& operator=(const TAutoArgsBase&);

  Variant   *m_Variant;
  int         m_Count;
};


// TAutoArgs - Encapsulates array of Variants. Use for Invoke calls

// note: this class is logically identical to the TAutoArgs class in
// Utilcls.h. It is included here because utilcls is windows only so
// this file should not depend on it.

template <int Count>
class TAutoArgs : public TAutoArgsBase
{
public:
 TAutoArgs() : TAutoArgsBase(m_Array, Count) {};
 ~TAutoArgs() {};
 TAutoArgs(TAutoArgs& src);

private:
  // Allocate an extra Variant. It's the first entry  and
  // it is reserved for return result. The rest are for parameters
  //
  Variant m_Array[Count+1];
};
#endif

namespace System
{
  template <class P1>
  void Variant::OleProcedure(const String& name, P1 p1)
  {
    TAutoArgs<1> args;
    args[1] = p1;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2>
  void Variant::OleProcedure(const String& name, P1 p1, P2 p2)
  {
    TAutoArgs<2> args;
    args[1] = p1;  args[2] = p2;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3>
  void Variant::OleProcedure(const String& name, P1 p1, P2 p2, P3 p3)
  {
    TAutoArgs<3> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4>
  void Variant::OleProcedure(const String& name, P1 p1, P2 p2, P3 p3, P4 p4)
  {
    TAutoArgs<4> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5>
  void Variant::OleProcedure(const String& name, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
  {
    TAutoArgs<5> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6>
  void Variant::OleProcedure(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6)
  {
    TAutoArgs<6> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7>
  void Variant::OleProcedure(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7)
  {
    TAutoArgs<7> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8>
  void Variant::OleProcedure(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8)
  {
    TAutoArgs<8> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9>
  void Variant::OleProcedure(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9)
  {
    TAutoArgs<9> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10>
  void Variant::OleProcedure(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10)
  {
    TAutoArgs<10> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11>
  void Variant::OleProcedure(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11)
  {
    TAutoArgs<11> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12>
  void Variant::OleProcedure(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12)
  {
    TAutoArgs<12> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13>
  void Variant::OleProcedure(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13)
  {
    TAutoArgs<13> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14>
  void Variant::OleProcedure(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14)
  {
    TAutoArgs<14> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15>
  void Variant::OleProcedure(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15)
  {
    TAutoArgs<15> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16>
  void Variant::OleProcedure(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16)
  {
    TAutoArgs<16> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17>
  void Variant::OleProcedure(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17)
  {
    TAutoArgs<17> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17, class P18>
  void Variant::OleProcedure(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17, P18 p18)
  {
    TAutoArgs<18> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;  args[18] = p18;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17, class P18, class P19>
  void Variant::OleProcedure(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17, P18 p18, P19 p19)
  {
    TAutoArgs<19> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;  args[18] = p18;
    args[19] = p19;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17, class P18, class P19, class P20>
  void Variant::OleProcedure(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17, P18 p18, P19 p19, P20 p20)
  {
    TAutoArgs<20> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;  args[18] = p18;
    args[19] = p19;  args[20] = p20;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17, class P18, class P19, class P20,
            class P21>
  void Variant::OleProcedure(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
    P21 p21)
  {
    TAutoArgs<21> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;  args[18] = p18;
    args[19] = p19;  args[20] = p20;  args[21] = p21;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17, class P18, class P19, class P20,
            class P21, class P22>
  void Variant::OleProcedure(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
    P21 p21, P22 p22)
  {
    TAutoArgs<22> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;  args[18] = p18;
    args[19] = p19;  args[20] = p20;  args[21] = p21;
    args[22] = p22;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17, class P18, class P19, class P20,
            class P21, class P22, class P23>
  void Variant::OleProcedure(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
    P21 p21, P22 p22, P23 p23)
  {
    TAutoArgs<23> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;  args[18] = p18;
    args[19] = p19;  args[20] = p20;  args[21] = p21;
    args[22] = p22;  args[23] = p23;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17, class P18, class P19, class P20,
            class P21, class P22, class P23, class P24>
  void Variant::OleProcedure(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
    P21 p21, P22 p22, P23 p23, P24 p24)
  {
    TAutoArgs<24> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;  args[18] = p18;
    args[19] = p19;  args[20] = p20;  args[21] = p21;
    args[22] = p22;  args[23] = p23;  args[24] = p24;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17, class P18, class P19, class P20,
            class P21, class P22, class P23, class P24, class P25>
  void Variant::OleProcedure(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
    P21 p21, P22 p22, P23 p23, P24 p24, P25 p25)
  {
    TAutoArgs<25> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;  args[18] = p18;
    args[19] = p19;  args[20] = p20;  args[21] = p21;
    args[22] = p22;  args[23] = p23;  args[24] = p24;
    args[25] = p25;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17, class P18, class P19, class P20,
            class P21, class P22, class P23, class P24, class P25,
            class P26>
  void Variant::OleProcedure(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
    P21 p21, P22 p22, P23 p23, P24 p24, P25 p25,
    P26 p26)
  {
    TAutoArgs<26> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;  args[18] = p18;
    args[19] = p19;  args[20] = p20;  args[21] = p21;
    args[22] = p22;  args[23] = p23;  args[24] = p24;
    args[25] = p25;  args[26] = p26;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17, class P18, class P19, class P20,
            class P21, class P22, class P23, class P24, class P25,
            class P26, class P27>
  void Variant::OleProcedure(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
    P21 p21, P22 p22, P23 p23, P24 p24, P25 p25,
    P26 p26, P27 p27)
  {
    TAutoArgs<27> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;  args[18] = p18;
    args[19] = p19;  args[20] = p20;  args[21] = p21;
    args[22] = p22;  args[23] = p23;  args[24] = p24;
    args[25] = p25;  args[26] = p26;  args[27] = p27;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17, class P18, class P19, class P20,
            class P21, class P22, class P23, class P24, class P25,
            class P26, class P27, class P28>
  void Variant::OleProcedure(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
    P21 p21, P22 p22, P23 p23, P24 p24, P25 p25,
    P26 p26, P27 p27, P28 p28)
  {
    TAutoArgs<28> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;  args[18] = p18;
    args[19] = p19;  args[20] = p20;  args[21] = p21;
    args[22] = p22;  args[23] = p23;  args[24] = p24;
    args[25] = p25;  args[26] = p26;  args[27] = p27;
    args[28] = p28;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17, class P18, class P19, class P20,
            class P21, class P22, class P23, class P24, class P25,
            class P26, class P27, class P28, class P29>
  void Variant::OleProcedure(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
    P21 p21, P22 p22, P23 p23, P24 p24, P25 p25,
    P26 p26, P27 p27, P28 p28, P29 p29)
  {
    TAutoArgs<29> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;  args[18] = p18;
    args[19] = p19;  args[20] = p20;  args[21] = p21;
    args[22] = p22;  args[23] = p23;  args[24] = p24;
    args[25] = p25;  args[26] = p26;  args[27] = p27;
    args[28] = p28;  args[29] = p29;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17, class P18, class P19, class P20,
            class P21, class P22, class P23, class P24, class P25,
            class P26, class P27, class P28, class P29, class P30>
  void Variant::OleProcedure(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
    P21 p21, P22 p22, P23 p23, P24 p24, P25 p25,
    P26 p26, P27 p27, P28 p28, P29 p29, P30 p30)
  {
    TAutoArgs<30> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;  args[18] = p18;
    args[19] = p19;  args[20] = p20;  args[21] = p21;
    args[22] = p22;  args[23] = p23;  args[24] = p24;
    args[25] = p25;  args[26] = p26;  args[27] = p27;
    args[28] = p28;  args[29] = p29;  args[30] = p30;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17, class P18, class P19, class P20,
            class P21, class P22, class P23, class P24, class P25,
            class P26, class P27, class P28, class P29, class P30,
            class P31>
  void Variant::OleProcedure(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
    P21 p21, P22 p22, P23 p23, P24 p24, P25 p25,
    P26 p26, P27 p27, P28 p28, P29 p29, P30 p30,
    P31 p31)
  {
    TAutoArgs<31> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;  args[18] = p18;
    args[19] = p19;  args[20] = p20;  args[21] = p21;
    args[22] = p22;  args[23] = p23;  args[24] = p24;
    args[25] = p25;  args[26] = p26;  args[27] = p27;
    args[28] = p28;  args[29] = p29;  args[30] = p30;
    args[31] = p31;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17, class P18, class P19, class P20,
            class P21, class P22, class P23, class P24, class P25,
            class P26, class P27, class P28, class P29, class P30,
            class P31, class P32>
  void Variant::OleProcedure(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
    P21 p21, P22 p22, P23 p23, P24 p24, P25 p25,
    P26 p26, P27 p27, P28 p28, P29 p29, P30 p30,
    P31 p31, P32 p32)
  {
    TAutoArgs<32> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;  args[18] = p18;
    args[19] = p19;  args[20] = p20;  args[21] = p21;
    args[22] = p22;  args[23] = p23;  args[24] = p24;
    args[25] = p25;  args[26] = p26;  args[27] = p27;
    args[28] = p28;  args[29] = p29;  args[30] = p30;
    args[31] = p31;  args[32] = p32;
    OleProcedure(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1>
  Variant Variant::OleFunction(const String& name, P1 p1)
  {
    TAutoArgs<1> args;
    args[1] = p1;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2>
  Variant Variant::OleFunction(const String& name, P1 p1, P2 p2)
  {
    TAutoArgs<2> args;
    args[1] = p1;  args[2] = p2;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3>
  Variant Variant::OleFunction(const String& name, P1 p1, P2 p2, P3 p3)
  {
    TAutoArgs<3> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4>
  Variant Variant::OleFunction(const String& name, P1 p1, P2 p2, P3 p3, P4 p4)
  {
    TAutoArgs<4> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5>
  Variant Variant::OleFunction(const String& name, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
  {
    TAutoArgs<5> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6>
  Variant Variant::OleFunction(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6)
  {
    TAutoArgs<6> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7>
  Variant Variant::OleFunction(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7)
  {
    TAutoArgs<7> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8>
  Variant Variant::OleFunction(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8)
  {
    TAutoArgs<8> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9>
  Variant Variant::OleFunction(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9)
  {
    TAutoArgs<9> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10>
  Variant Variant::OleFunction(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10)
  {
    TAutoArgs<10> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11>
  Variant Variant::OleFunction(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11)
  {
    TAutoArgs<11> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12>
  Variant Variant::OleFunction(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12)
  {
    TAutoArgs<12> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13>
  Variant Variant::OleFunction(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13)
  {
    TAutoArgs<13> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14>
  Variant Variant::OleFunction(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14)
  {
    TAutoArgs<14> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15>
  Variant Variant::OleFunction(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15)
  {
    TAutoArgs<15> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16>
  Variant Variant::OleFunction(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16)
  {
    TAutoArgs<16> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17>
  Variant Variant::OleFunction(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17)
  {
    TAutoArgs<17> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17, class P18>
  Variant Variant::OleFunction(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17, P18 p18)
  {
    TAutoArgs<18> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;  args[18] = p18;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17, class P18, class P19>
  Variant Variant::OleFunction(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17, P18 p18, P19 p19)
  {
    TAutoArgs<19> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;  args[18] = p18;
    args[19] = p19;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17, class P18, class P19, class P20>
  Variant Variant::OleFunction(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17, P18 p18, P19 p19, P20 p20)
  {
    TAutoArgs<20> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;  args[18] = p18;
    args[19] = p19;  args[20] = p20;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17, class P18, class P19, class P20,
            class P21>
  Variant Variant::OleFunction(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
    P21 p21)
  {
    TAutoArgs<21> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;  args[18] = p18;
    args[19] = p19;  args[20] = p20;  args[21] = p21;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17, class P18, class P19, class P20,
            class P21, class P22>
  Variant Variant::OleFunction(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
    P21 p21, P22 p22)
  {
    TAutoArgs<22> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;  args[18] = p18;
    args[19] = p19;  args[20] = p20;  args[21] = p21;
    args[22] = p22;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17, class P18, class P19, class P20,
            class P21, class P22, class P23>
  Variant Variant::OleFunction(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
    P21 p21, P22 p22, P23 p23)
  {
    TAutoArgs<23> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;  args[18] = p18;
    args[19] = p19;  args[20] = p20;  args[21] = p21;
    args[22] = p22;  args[23] = p23;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17, class P18, class P19, class P20,
            class P21, class P22, class P23, class P24>
  Variant Variant::OleFunction(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
    P21 p21, P22 p22, P23 p23, P24 p24)
  {
    TAutoArgs<24> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;  args[18] = p18;
    args[19] = p19;  args[20] = p20;  args[21] = p21;
    args[22] = p22;  args[23] = p23;  args[24] = p24;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17, class P18, class P19, class P20,
            class P21, class P22, class P23, class P24, class P25>
  Variant Variant::OleFunction(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
    P21 p21, P22 p22, P23 p23, P24 p24, P25 p25)
  {
    TAutoArgs<25> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;  args[18] = p18;
    args[19] = p19;  args[20] = p20;  args[21] = p21;
    args[22] = p22;  args[23] = p23;  args[24] = p24;
    args[25] = p25;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17, class P18, class P19, class P20,
            class P21, class P22, class P23, class P24, class P25,
            class P26>
  Variant Variant::OleFunction(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
    P21 p21, P22 p22, P23 p23, P24 p24, P25 p25,
    P26 p26)
  {
    TAutoArgs<26> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;  args[18] = p18;
    args[19] = p19;  args[20] = p20;  args[21] = p21;
    args[22] = p22;  args[23] = p23;  args[24] = p24;
    args[25] = p25;  args[26] = p26;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17, class P18, class P19, class P20,
            class P21, class P22, class P23, class P24, class P25,
            class P26, class P27>
  Variant Variant::OleFunction(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
    P21 p21, P22 p22, P23 p23, P24 p24, P25 p25,
    P26 p26, P27 p27)
  {
    TAutoArgs<27> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;  args[18] = p18;
    args[19] = p19;  args[20] = p20;  args[21] = p21;
    args[22] = p22;  args[23] = p23;  args[24] = p24;
    args[25] = p25;  args[26] = p26;  args[27] = p27;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17, class P18, class P19, class P20,
            class P21, class P22, class P23, class P24, class P25,
            class P26, class P27, class P28>
  Variant Variant::OleFunction(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
    P21 p21, P22 p22, P23 p23, P24 p24, P25 p25,
    P26 p26, P27 p27, P28 p28)
  {
    TAutoArgs<28> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;  args[18] = p18;
    args[19] = p19;  args[20] = p20;  args[21] = p21;
    args[22] = p22;  args[23] = p23;  args[24] = p24;
    args[25] = p25;  args[26] = p26;  args[27] = p27;
    args[28] = p28;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17, class P18, class P19, class P20,
            class P21, class P22, class P23, class P24, class P25,
            class P26, class P27, class P28, class P29>
  Variant Variant::OleFunction(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
    P21 p21, P22 p22, P23 p23, P24 p24, P25 p25,
    P26 p26, P27 p27, P28 p28, P29 p29)
  {
    TAutoArgs<29> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;  args[18] = p18;
    args[19] = p19;  args[20] = p20;  args[21] = p21;
    args[22] = p22;  args[23] = p23;  args[24] = p24;
    args[25] = p25;  args[26] = p26;  args[27] = p27;
    args[28] = p28;  args[29] = p29;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17, class P18, class P19, class P20,
            class P21, class P22, class P23, class P24, class P25,
            class P26, class P27, class P28, class P29, class P30>
  Variant Variant::OleFunction(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
    P21 p21, P22 p22, P23 p23, P24 p24, P25 p25,
    P26 p26, P27 p27, P28 p28, P29 p29, P30 p30)
  {
    TAutoArgs<30> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;  args[18] = p18;
    args[19] = p19;  args[20] = p20;  args[21] = p21;
    args[22] = p22;  args[23] = p23;  args[24] = p24;
    args[25] = p25;  args[26] = p26;  args[27] = p27;
    args[28] = p28;  args[29] = p29;  args[30] = p30;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17, class P18, class P19, class P20,
            class P21, class P22, class P23, class P24, class P25,
            class P26, class P27, class P28, class P29, class P30,
            class P31>
  Variant Variant::OleFunction(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
    P21 p21, P22 p22, P23 p23, P24 p24, P25 p25,
    P26 p26, P27 p27, P28 p28, P29 p29, P30 p30,
    P31 p31)
  {
    TAutoArgs<31> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;  args[18] = p18;
    args[19] = p19;  args[20] = p20;  args[21] = p21;
    args[22] = p22;  args[23] = p23;  args[24] = p24;
    args[25] = p25;  args[26] = p26;  args[27] = p27;
    args[28] = p28;  args[29] = p29;  args[30] = p30;
    args[31] = p31;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10,
            class P11, class P12, class P13, class P14, class P15,
            class P16, class P17, class P18, class P19, class P20,
            class P21, class P22, class P23, class P24, class P25,
            class P26, class P27, class P28, class P29, class P30,
            class P31, class P32>
  Variant Variant::OleFunction(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10,
    P11 p11, P12 p12, P13 p13, P14 p14, P15 p15,
    P16 p16, P17 p17, P18 p18, P19 p19, P20 p20,
    P21 p21, P22 p22, P23 p23, P24 p24, P25 p25,
    P26 p26, P27 p27, P28 p28, P29 p29, P30 p30,
    P31 p31, P32 p32)
  {
    TAutoArgs<32> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;  args[11] = p11;  args[12] = p12;
    args[13] = p13;  args[14] = p14;  args[15] = p15;
    args[16] = p16;  args[17] = p17;  args[18] = p18;
    args[19] = p19;  args[20] = p20;  args[21] = p21;
    args[22] = p22;  args[23] = p23;  args[24] = p24;
    args[25] = p25;  args[26] = p26;  args[27] = p27;
    args[28] = p28;  args[29] = p29;  args[30] = p30;
    args[31] = p31;  args[32] = p32;
    return OleFunction(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1>
  Variant Variant::OlePropertyGet(const String& name, P1 p1)
  {
    TAutoArgs<1> args;
    args[1] = p1;
    return OlePropertyGet(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2>
  Variant Variant::OlePropertyGet(const String& name, P1 p1, P2 p2)
  {
    TAutoArgs<2> args;
    args[1] = p1;  args[2] = p2;
    return OlePropertyGet(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3>
  Variant Variant::OlePropertyGet(const String& name, P1 p1, P2 p2, P3 p3)
  {
    TAutoArgs<3> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    return OlePropertyGet(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4>
  Variant Variant::OlePropertyGet(const String& name, P1 p1, P2 p2, P3 p3, P4 p4)
  {
    TAutoArgs<4> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;
    return OlePropertyGet(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5>
  Variant Variant::OlePropertyGet(const String& name, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
  {
    TAutoArgs<5> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;
    return OlePropertyGet(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6>
  Variant Variant::OlePropertyGet(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6)
  {
    TAutoArgs<6> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    return OlePropertyGet(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7>
  Variant Variant::OlePropertyGet(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7)
  {
    TAutoArgs<7> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;
    return OlePropertyGet(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8>
  Variant Variant::OlePropertyGet(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8)
  {
    TAutoArgs<8> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;
    return OlePropertyGet(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9>
  Variant Variant::OlePropertyGet(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9)
  {
    TAutoArgs<9> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    return OlePropertyGet(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10>
  Variant Variant::OlePropertyGet(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10)
  {
    TAutoArgs<10> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;
    return OlePropertyGet(name, static_cast<TAutoArgsBase*>(&args));
  }

  template <class P1>
  void Variant::OlePropertySet(const String& name, P1 p1)
  {
    TAutoArgs<1> args;
    args[1] = p1;
    OlePropertySet(name, static_cast<TAutoArgsBase&>(args));
  }

  template <class P1, class P2>
  void Variant::OlePropertySet(const String& name, P1 p1, P2 p2)
  {
    TAutoArgs<2> args;
    args[1] = p1;  args[2] = p2;
    OlePropertySet(name, static_cast<TAutoArgsBase&>(args));
  }

  template <class P1, class P2, class P3>
  void Variant::OlePropertySet(const String& name, P1 p1, P2 p2, P3 p3)
  {
    TAutoArgs<3> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    OlePropertySet(name, static_cast<TAutoArgsBase&>(args));
  }

  template <class P1, class P2, class P3, class P4>
  void Variant::OlePropertySet(const String& name, P1 p1, P2 p2, P3 p3, P4 p4)
  {
    TAutoArgs<4> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;
    OlePropertySet(name, static_cast<TAutoArgsBase&>(args));
  }

  template <class P1, class P2, class P3, class P4, class P5>
  void Variant::OlePropertySet(const String& name, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
  {
    TAutoArgs<5> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;
    OlePropertySet(name, static_cast<TAutoArgsBase&>(args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6>
  void Variant::OlePropertySet(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6)
  {
    TAutoArgs<6> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    OlePropertySet(name, static_cast<TAutoArgsBase&>(args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7>
  void Variant::OlePropertySet(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7)
  {
    TAutoArgs<7> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;
    OlePropertySet(name, static_cast<TAutoArgsBase&>(args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8>
  void Variant::OlePropertySet(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8)
  {
    TAutoArgs<8> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;
    OlePropertySet(name, static_cast<TAutoArgsBase&>(args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9>
  void Variant::OlePropertySet(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9)
  {
    TAutoArgs<9> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    OlePropertySet(name, static_cast<TAutoArgsBase&>(args));
  }

  template <class P1, class P2, class P3, class P4, class P5,
            class P6, class P7, class P8, class P9, class P10>
  void Variant::OlePropertySet(const String& name,
    P1 p1, P2 p2, P3 p3, P4 p4, P5 p5,
    P6 p6, P7 p7, P8 p8, P9 p9, P10 p10)
  {
    TAutoArgs<10> args;
    args[1] = p1;  args[2] = p2;  args[3] = p3;
    args[4] = p4;  args[5] = p5;  args[6] = p6;
    args[7] = p7;  args[8] = p8;  args[9] = p9;
    args[10] = p10;
    OlePropertySet(name, static_cast<TAutoArgsBase&>(args));
  }



  class RTL_DELPHIRETURN OleVariant: protected Variant
  {
  public:
    __fastcall OleVariant()                     : Variant()     {}
    __fastcall OleVariant(const OleVariant& src): Variant(src)  {}
    __fastcall OleVariant(const Variant& src)   : Variant()     {
      // To handle Variants that contain non-standard AnsiStrings
      //
      *this = src;
    }

    //By value constructors
    __fastcall OleVariant(const char src)           : Variant(src)  {}
    __fastcall OleVariant(const unsigned char src)  : Variant(src)  {}
    __fastcall OleVariant(const short src)          : Variant(src)  {}
    __fastcall OleVariant(const unsigned short src) : Variant(src)  {}
    __fastcall OleVariant(const int src)            : Variant(src)  {}
    __fastcall OleVariant(const unsigned int src)   : Variant(src)  {}
    __fastcall OleVariant(const float src)          : Variant(src)  {}
    __fastcall OleVariant(const double src)         : Variant(src)  {}
    __fastcall OleVariant(const __int64 src)        : Variant(src)  {}
    __fastcall OleVariant(const Currency src)       : Variant(src)  {}
    __fastcall OleVariant(const TDateTime src)      : Variant(src)  {}
    __fastcall OleVariant(const WideString& src)    : Variant(src)  {}
    __fastcall OleVariant(const bool src)           : Variant(src)  {}
    __fastcall OleVariant(const AnsiString& src)    : Variant(WideString(src).Detach()) {}


    // By ref constructors
    __fastcall OleVariant(wchar_t* const src)   : Variant(src)  {}
    __fastcall OleVariant(IDispatch* const src) : Variant(src)  {}
    __fastcall OleVariant(IUnknown* const src)  : Variant(src)  {}
    __fastcall OleVariant(IInterface* const src) : Variant(src) {}
#ifdef WIN32
    __fastcall OleVariant(VARIANT* src)         : Variant(src)  {}
#endif
#ifdef TVARIANT_ON
    __fastcall OleVariant(const TVariant& src)     : Variant(src)  {}
#endif

    __fastcall OleVariant(signed char* src)     : Variant(src)  {}
    __fastcall OleVariant(unsigned char* src)   : Variant(src)  {}

    __fastcall OleVariant(short* src)           : Variant(src)  {}
    __fastcall OleVariant(unsigned short* src)  : Variant(src)  {}

    __fastcall OleVariant(int* src)             : Variant(src)  {}
    __fastcall OleVariant(unsigned int* src)    : Variant(src)  {}

    __fastcall OleVariant(long* src)            : Variant(src)  {}
    __fastcall OleVariant(unsigned long* src)   : Variant(src)  {}

    __fastcall OleVariant(float* src)           : Variant(src)  {}
    __fastcall OleVariant(double* src)          : Variant(src)  {}
    __fastcall OleVariant(__int64* src)         : Variant(src)  {}

    __fastcall OleVariant(Currency* src)        : Variant(src)  {}
    __fastcall OleVariant(TDateTime* src)       : Variant(src)  {}
    __fastcall OleVariant(wchar_t** src)        : Variant(src)  {}

    // constructor for array of variants of type varType
    __fastcall OleVariant(const int* bounds, const int boundsSize, Word varType)  :   Variant(bounds, boundsSize, varType) {}

    // constructor for one dimensional array of type OleVariant
    __fastcall OleVariant(const OleVariant* values, const int valuesSize) : Variant(values, valuesSize) {}

    __fastcall ~OleVariant() {}


    // Assignment operators
    //
    OleVariant& __fastcall operator =(const OleVariant& rhs)
    {
      PVariant(this)->operator=(rhs);
      return *this;
    }
    OleVariant& __fastcall operator =(const Variant& rhs)
    {
      PVariant(this)->operator=(rhs.Sanitized());
      return *this;
    }
#ifdef WIN32
    OleVariant& __fastcall operator =(VARIANT& rhs)
    {
      PVariant(this)->operator=(rhs);
      return *this;
    }
#endif

    OleVariant& __fastcall operator =(const AnsiString& rhs)
    {
      PVariant(this)->operator=(WideString(rhs).Detach());
      return *this;
    }

    OleVariant& __fastcall operator =(const char rhs)
    {
      PVariant(this)->operator=(rhs);
      return *this;
    }

    OleVariant& __fastcall operator =(const signed char rhs)
    {
      PVariant(this)->operator=(rhs);
      return *this;
    }

    OleVariant& __fastcall operator =(const unsigned char rhs)
    {
      PVariant(this)->operator=(rhs);
      return *this;
    }

    OleVariant& __fastcall operator =(const short rhs)
    {
      PVariant(this)->operator=(rhs);
      return *this;
    }

    OleVariant& __fastcall operator =(const unsigned short rhs)
    {
      PVariant(this)->operator=(rhs);
      return *this;
    }

    OleVariant& __fastcall operator =(const int rhs)
    {
      PVariant(this)->operator=(rhs);
      return *this;
    }

    OleVariant& __fastcall operator =(const unsigned int rhs)
    {
      PVariant(this)->operator=(rhs);
      return *this;
    }

    OleVariant& __fastcall operator =(const long rhs)
    {
      PVariant(this)->operator=(rhs);
      return *this;
    }

    OleVariant& __fastcall operator =(const unsigned long rhs)
    {
      PVariant(this)->operator=(rhs);
      return *this;
    }

    OleVariant& __fastcall operator =(const float rhs)
    {
      PVariant(this)->operator=(rhs);
      return *this;
    }

    OleVariant& __fastcall operator =(const double rhs)
    {
      PVariant(this)->operator=(rhs);
      return *this;
    }

    OleVariant& __fastcall operator =(const __int64 rhs)
    {
      PVariant(this)->operator=(rhs);
      return *this;
    }

    OleVariant& __fastcall operator =(const CURRENCY& rhs)
    {
      PVariant(this)->operator=(rhs);
      return *this;
    }

    OleVariant& __fastcall operator =(const TDateTime rhs)
    {
      PVariant(this)->operator=(rhs);
      return *this;
    }

    OleVariant& __fastcall operator =(const bool rhs)
    {
      PVariant(this)->operator=(rhs);
      return *this;
    }

  public:

    TVarData::VType;
    TVarData::Reserved1;
    TVarData::Reserved2;
    TVarData::Reserved3;
    TVarData::VSmallint;
    TVarData::VInteger;
    TVarData::VSingle;
    TVarData::VDouble;
    TVarData::VCurrency;
    TVarData::VDate;
    TVarData::VOleStr;
    TVarData::VDispatch;
    TVarData::VError;
    TVarData::VBoolean;
    TVarData::VUnknown;
    TVarData::VByte;

    /*  (Hide this - OleVariant cannot hold MBCS string)
    TVarData::VString;
    */
    TVarData::VArray;
    TVarData::VPointer;


    Variant::operator += ;
    Variant::operator -= ;
    Variant::operator *= ;
    Variant::operator /= ;
    Variant::operator %= ;
    Variant::operator &= ;
    Variant::operator |= ;
    Variant::operator ^= ;
    Variant::operator <<=;
    Variant::operator >>=;

    // comparisons (Variant on right)
    Variant::operator == ;
    Variant::operator != ;
    Variant::operator <  ;
    Variant::operator >  ;
    Variant::operator <= ;
    Variant::operator >= ;

    // unary operators
    Variant::operator -;
    Variant::operator !;

    // conversion operators
    Variant::operator char;
    Variant::operator signed char;
    Variant::operator unsigned char;
    Variant::operator short;
    Variant::operator unsigned short;
    Variant::operator int;
    Variant::operator unsigned int;
    Variant::operator long;
    Variant::operator unsigned long;
    Variant::operator float;
    Variant::operator double;
    Variant::operator __int64;
    Variant::operator Currency;
    Variant::operator TDateTime;
    Variant::operator bool;
    Variant::operator AnsiString;
    Variant::operator WideString;
    Variant::operator unsigned short;
    Variant::operator IDispatch*;
    Variant::operator IUnknown*;
    Variant::operator IInterface*;
#ifdef WIN32
    Variant::operator VARIANT;
#endif
#ifdef TVARIANT_ON
    Variant::operator TVariant;
#endif


    // by ref conversion operators
    Variant::operator short*;
    Variant::operator int*;
    Variant::operator float*;
    Variant::operator double*;
    Variant::operator Currency*;
    Variant::operator TDateTime*;
    Variant::operator unsigned short*;
    Variant::operator Byte*;
    Variant::operator wchar_t**;
#ifdef WIN32
    Variant::operator VARIANT*;
#endif
#ifdef TVARIANT_ON
    Variant::operator TVariant*;
#endif


    // HRESULT methods
    Variant::SetError;
    Variant::GetError;

    Variant::Clear;
    Variant::ChangeType;
    Variant::AsType;

    Variant::Type;
    Variant::IsNull;
    Variant::IsEmpty;

    // variant array stuff
    Variant::IsArray;
    Variant::GetElement;
    Variant::PutElement;
    Variant::ArrayDimCount;
    Variant::ArrayLowBound;
    Variant::ArrayHighBound;
    Variant::ArrayRedim;
    Variant::ArrayLock;
    Variant::ArrayUnlock;

    // Automation Goodies
    Variant::Exec;

    // Alternate Syntax for Automation
    Variant::OleProcedure;
    Variant::OleFunction;
    Variant::OlePropertyGet;
    Variant::OlePropertySet;

  private:

    // binary operators (AnsiString on right)
    OleVariant __fastcall operator * (const AnsiString& rhs) const;
    OleVariant __fastcall operator / (const AnsiString& rhs) const;
    OleVariant __fastcall operator % (const AnsiString& rhs) const;
    OleVariant __fastcall operator & (const AnsiString& rhs) const;
    OleVariant __fastcall operator | (const AnsiString& rhs) const;
    OleVariant __fastcall operator ^ (const AnsiString& rhs) const;
    OleVariant __fastcall operator <<(const AnsiString& rhs) const;
    OleVariant __fastcall operator >>(const AnsiString& rhs) const;
  };

// Variant global scope comparisons (int on left)
  inline bool __fastcall operator ==(int lhs, const Variant& rhs)
  {return Variant(lhs).operator ==(rhs);}
  inline bool __fastcall operator !=(int lhs, const Variant& rhs)
  {return Variant(lhs).operator !=(rhs);}
  inline bool __fastcall operator < (int lhs, const Variant& rhs)
  {return Variant(lhs).operator < (rhs);}
  inline bool __fastcall operator > (int lhs, const Variant& rhs)
  {return Variant(lhs).operator > (rhs);}
  inline bool __fastcall operator <=(int lhs, const Variant& rhs)
  {return Variant(lhs).operator <=(rhs);}
  inline bool __fastcall operator >=(int lhs, const Variant& rhs)
  {return Variant(lhs).operator >=(rhs);}

// Variant global scope comparisons (double on left)
  inline bool __fastcall operator ==(double lhs, const Variant& rhs)
  {return Variant(lhs).operator ==(rhs);}
  inline bool __fastcall operator !=(double lhs, const Variant& rhs)
  {return Variant(lhs).operator !=(rhs);}
  inline bool __fastcall operator < (double lhs, const Variant& rhs)
  {return Variant(lhs).operator < (rhs);}
  inline bool __fastcall operator > (double lhs, const Variant& rhs)
  {return Variant(lhs).operator > (rhs);}
  inline bool __fastcall operator <=(double lhs, const Variant& rhs)
  {return Variant(lhs).operator <=(rhs);}
  inline bool __fastcall operator >=(double lhs, const Variant& rhs)
  {return Variant(lhs).operator >=(rhs);}

// Variant binary global scope operators (AnsiString on left)
  inline Variant __fastcall operator - (const AnsiString& lhs, const Variant& rhs)
  {return Variant(lhs).operator -(rhs);}
  inline Variant __fastcall operator * (const AnsiString& lhs, const Variant& rhs)
  {return Variant(lhs).operator *(rhs);}
  inline Variant __fastcall operator / (const AnsiString& lhs, const Variant& rhs)
  {return Variant(lhs).operator /(rhs);}
  inline Variant __fastcall operator % (const AnsiString& lhs, const Variant& rhs)
  {return Variant(lhs).operator %(rhs);}
  inline Variant __fastcall operator & (const AnsiString& lhs, const Variant& rhs)
  {return Variant(lhs).operator &(rhs);}
  inline Variant __fastcall operator | (const AnsiString& lhs, const Variant& rhs)
  {return Variant(lhs).operator |(rhs);}
  inline Variant __fastcall operator ^ (const AnsiString& lhs, const Variant& rhs)
  {return Variant(lhs).operator ^(rhs);}
  inline Variant __fastcall operator <<(const AnsiString& lhs, const Variant& rhs)
  {return Variant(lhs).operator <<(rhs);}
  inline Variant __fastcall operator >>(const AnsiString& lhs, const Variant& rhs)
  {return Variant(lhs).operator >>(rhs);}

// Variant binary global scope operators (int on left)
  inline Variant __fastcall operator +(int lhs, const Variant& rhs)
  {return Variant(lhs).operator +(rhs);}
  inline Variant __fastcall operator -(int lhs, const Variant& rhs)
  {return Variant(lhs).operator -(rhs);}
  inline Variant __fastcall operator *(int lhs, const Variant& rhs)
  {return Variant(lhs).operator *(rhs);}
  inline Variant __fastcall operator /(int lhs, const Variant& rhs)
  {return Variant(lhs).operator /(rhs);}
  inline Variant __fastcall operator %(int lhs, const Variant& rhs)
  {return Variant(lhs).operator %(rhs);}
  inline Variant __fastcall operator &(int lhs, const Variant& rhs)
  {return Variant(lhs).operator &(rhs);}
  inline Variant __fastcall operator |(int lhs, const Variant& rhs)
  {return Variant(lhs).operator |(rhs);}
  inline Variant __fastcall operator ^(int lhs, const Variant& rhs)
  {return Variant(lhs).operator ^(rhs);}
  inline Variant __fastcall operator <<(int lhs, const Variant& rhs)
  {return Variant(lhs).operator <<(rhs);}
  inline Variant __fastcall operator >>(int lhs, const Variant& rhs)
  {return Variant(lhs).operator >>(rhs);}

// Variant binary global scope operators (double on left)
  inline Variant __fastcall operator +(double lhs, const Variant& rhs)
  {return Variant(lhs).operator +(rhs);}
  inline Variant __fastcall operator -(double lhs, const Variant& rhs)
  {return Variant(lhs).operator -(rhs);}
  inline Variant __fastcall operator *(double lhs, const Variant& rhs)
  {return Variant(lhs).operator *(rhs);}
  inline Variant __fastcall operator /(double lhs, const Variant& rhs)
  {return Variant(lhs).operator /(rhs);}
  inline Variant __fastcall operator %(double lhs, const Variant& rhs)
  {return Variant(lhs).operator %(rhs);}
  inline Variant __fastcall operator &(double lhs, const Variant& rhs)
  {return Variant(lhs).operator &(rhs);}
  inline Variant __fastcall operator |(double lhs, const Variant& rhs)
  {return Variant(lhs).operator |(rhs);}
  inline Variant __fastcall operator ^(double lhs, const Variant& rhs)
  {return Variant(lhs).operator ^(rhs);}
  inline Variant __fastcall operator <<(double lhs, const Variant& rhs)
  {return Variant(lhs).operator <<(rhs);}
  inline Variant __fastcall operator >>(double lhs, const Variant& rhs)
  {return Variant(lhs).operator >>(rhs);}

  class NamedParm;
  class AutoCmd
  {
  public:
    AutoCmd(const String& name);
    AutoCmd(const AutoCmd& src);
   ~AutoCmd();

    // Set(update) name of command
    AutoCmd& SetName(const String& name);

    // Named arg
    AutoCmd& operator <<(const NamedParm& np);

    // By value args
    AutoCmd& operator <<(const Variant& arg);
    AutoCmd& operator <<(const short arg);
    AutoCmd& operator <<(const int arg);
    AutoCmd& operator <<(const float arg);
    AutoCmd& operator <<(const double arg);
    AutoCmd& operator <<(const Currency arg);
    AutoCmd& operator <<(const TDateTime arg);
    AutoCmd& operator <<(const bool arg);
    AutoCmd& operator <<(const WordBool arg);
    AutoCmd& operator <<(const Byte arg);
    AutoCmd& operator <<(const AnsiString& arg);

    // Treat 'const char*' as an ASCIIz string
    AutoCmd& operator <<(const char* arg) {return operator <<(WideString(arg));}

    AutoCmd& operator <<(wchar_t* arg);
    AutoCmd& operator <<(IDispatch* arg);
    AutoCmd& operator <<(IUnknown* arg);
    AutoCmd& operator <<(IInterface* arg);

    //By ref args
    AutoCmd& operator <<(Variant* arg);
    AutoCmd& operator <<(short* arg);
    AutoCmd& operator <<(int* arg);
    AutoCmd& operator <<(float* arg);
    AutoCmd& operator <<(double* arg);
    AutoCmd& operator <<(Currency* arg);
    AutoCmd& operator <<(TDateTime* arg);
    AutoCmd& operator <<(WordBool* arg);
    AutoCmd& operator <<(Byte* arg);
    AutoCmd& operator <<(wchar_t** arg);

    AutoCmd& operator <<(AnsiString* arg);

    AutoCmd&          Clear();                 // ClearName() + ClearArgs()
    AutoCmd&          ClearName();             // SetName("")
    AutoCmd&          ClearArgs();             // Clear Parms and NamedParms

    // Overriden in Procedure, Function, PropertyGet and PropertySet classes
    //
    virtual Byte      GetCallType()   const = 0;
    virtual bool      RequestResult() const = 0;

    int               GetArgType(const Byte idx) const;
    int               GetNamedArgType(const Byte idx) const;
    String            GetName() const { return Name;}
    Byte              GetArgCount() const;
    Byte              GetNamedArgCount() const;
    Variant&          GetParm(const Byte idx);
    Variant&          GetNamedParm(const Byte idx);
    String            GetNamedParmName(const Byte idx) const;

  protected:
    void              AddElement();
    String            Name;                             // name of command
    Variant           Parms;                            // positional arguments
    Variant           ParmTypes;                        // types of positional arguments
    Variant           NamedParms;                       // named arguments
    Variant           NamedParmTypes;                   // types of named arguments
    Variant           NamedParmNames;                   // names of named arguments
  };

  class NamedParm
  {
  public:
    //By value ctors
    NamedParm(const String& name, const Variant& arg):    Name(name), Type(varVariant), Parm(arg) {}
    NamedParm(const String& name, const short arg):       Name(name), Type(varSmallint), Parm(arg) {}
    NamedParm(const String& name, const int arg):         Name(name), Type(varInteger), Parm(arg) {}
    NamedParm(const String& name, const float arg):       Name(name), Type(varSingle), Parm(arg) {}
    NamedParm(const String& name, const double arg):      Name(name), Type(varDouble), Parm(arg) {}
    NamedParm(const String& name, const Currency arg):    Name(name), Type(varCurrency), Parm(arg) {}
    NamedParm(const String& name, const TDateTime arg):   Name(name), Type(varDate), Parm(arg) {}
    NamedParm(const String& name, const bool arg):        Name(name), Type(varBoolean), Parm(arg) {}
    NamedParm(const String& name, const WordBool arg):    Name(name), Type(varBoolean), Parm(arg) {}
    NamedParm(const String& name, const Byte arg):        Name(name), Type(varByte), Parm(arg) {}
    NamedParm(const String& name, const AnsiString& arg): Name(name), Type(varOleStr), Parm(WideString(arg).Detach()) {}
    NamedParm(const String& name, const char* arg):       Name(name), Type(varOleStr), Parm(WideString(arg).Detach()) {}
    NamedParm(const String& name, wchar_t* /*BSTR*/ arg): Name(name), Type(varOleStr), Parm(arg) {}
    NamedParm(const String& name, IDispatch* const arg):  Name(name), Type(varDispatch), Parm(arg) {}
    NamedParm(const String& name, IUnknown* const arg):   Name(name), Type(varUnknown), Parm(arg) {}
    NamedParm(const String& name, IInterface* const arg): Name(name), Type(varUnknown), Parm(arg) {}

    //By ref ctors
    NamedParm(const String& name, Variant* arg):   Name(name), Type(varVariant | varByRef), Parm(arg) {}
    NamedParm(const String& name, short* arg):     Name(name), Type(varSmallint | varByRef), Parm(arg) {}
    NamedParm(const String& name, int* arg):       Name(name), Type(varInteger | varByRef), Parm(arg) {}
    NamedParm(const String& name, float* arg):     Name(name), Type(varSingle | varByRef), Parm(arg) {}
    NamedParm(const String& name, double* arg):    Name(name), Type(varDouble | varByRef), Parm(arg) {}
    NamedParm(const String& name, Currency* arg):  Name(name), Type(varCurrency | varByRef), Parm(arg) {}
    NamedParm(const String& name, TDateTime* arg): Name(name), Type(varDate | varByRef), Parm(arg) {}
    NamedParm(const String& name, WordBool* arg):  Name(name), Type(varBoolean | varByRef), Parm(arg) {}
    NamedParm(const String& name, Byte* arg):      Name(name), Type(varByte | varByRef), Parm(arg) {}
    NamedParm(const String& name, wchar_t** arg):  Name(name), Type(varOleStr | varByRef), Parm(arg) {}
    NamedParm(const String& name, String* arg):    Name(name), Type(varOleStr), Parm(WideString(*arg).Detach()) {}

    Variant           GetParm() const     { return Parm;}
    int               GetType() const     { return Type;}
    String            GetParmName() const { return Name;}
  protected:
    void              AddElement();
    String            Name;
    Variant           Parm;
    int               Type;
  };


  class Procedure : public AutoCmd
  {
  public:
    Procedure(const String& name): AutoCmd(name) {}
    Procedure(const AutoCmd& src): AutoCmd(src)  {}
    Byte      GetCallType()   const { return DISPATCH_METHOD;}
    bool      RequestResult() const { return false;          }
  };

  class Function : public AutoCmd
  {
  public:
    Function(const String& name): AutoCmd(name) {}
    Function(const AutoCmd& src): AutoCmd(src)  {}
    Byte      GetCallType()   const { return DISPATCH_METHOD;}
    bool      RequestResult() const { return true;           }
  };

  class PropertySet : public AutoCmd
  {
  public:
    PropertySet(const String& name): AutoCmd(name) {}
    PropertySet(const AutoCmd& src): AutoCmd(src)  {}
    Byte      GetCallType()   const { return DISPATCH_PROPERTYPUT; }
    bool      RequestResult() const { return false;                }
  };

  class PropertyGet : public AutoCmd
  {
  public:
    PropertyGet(const String& name): AutoCmd(name) {}
    PropertyGet(const AutoCmd& src): AutoCmd(src)  {}
    Byte      GetCallType()   const { return DISPATCH_PROPERTYGET;}
    bool      RequestResult() const { return true;                }
  };

  extern void __fastcall  VarClear(Variant& v); /* variant.cpp */
  extern void __fastcall  VarCast(Variant &dest, const Variant& source, int type); /* variant.cpp */
  extern void __fastcall  VarArrayRedim(Variant& a, int high); /* variant.cpp */

}

#pragma option pop


// VARIANT, Variant, TVariant and OleVariant - some many deviations - Ensure they're in alignment!
//
#if 0
#if sizeof(TVarData) < sizeof(VARIANT)
#pragma message "ERROR: sizeof(TVarData) < sizeof(VARIANT)'
#endif
#if sizeof(TVarData) > sizeof(VARIANT)
#pragma message "ERROR: sizeof(TVarData) > sizeof(VARIANT)'
#endif
#if sizeof(OleVariant) < sizeof(VARIANT)
#pragma message "ERROR: sizeof(OleVariant) < sizeof(VARIANT)'
#endif
#if sizeof(OleVariant) > sizeof(VARIANT)
#pragma message "ERROR: sizeof(OleVariant) > sizeof(VARIANT)'
#endif
#endif


#endif
