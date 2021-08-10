//    variant.cpp - support for delphi variants in C++
//
//    $Revision:   1.24.1.2  $
//    $Date:   26 Jan 2000 17:28:36  $
//
//    Copyright (c) 1997, 1999 Borland International

#include <system.hpp>
#include <oaidl.h>
#include <comobj.hpp>
#ifdef USE_VCLHLPR_PAS
#include <vclhlpr.hpp>
#else
#include <vclhlpr2.h>
#endif
#include "variant.hpp"
#include <oleauto.h>
#include <utilcls.h>

namespace System
{
  Variant __fastcall Variant::CreateObject(const String& ProgID)
  {
    return Variant(Comobj::CreateOleObject(const_cast<String&>(ProgID)));
  }

  Variant __fastcall Variant::GetActiveObject(const String& ProgID)
  {
    return Variant(Comobj::GetActiveOleObject(const_cast<String&>(ProgID)));
  }

  // Static ref. to be used for non-specified optional parameters
  //
  Variant& Variant::NoParam()
  {
    VariantError err;
    static Variant _noParam(err);
    _ASSERTE(_noParam.vt == VT_ERROR);
    _ASSERTE(V_ERROR(&_noParam) == DISP_E_PARAMNOTFOUND);
    return _noParam;
  }

  // Static ref. used for empty Variants
  //
  Variant& Variant::Empty()
  {
    static Variant _empty;
    _ASSERTE(_empty.vt == VT_EMPTY);
    return _empty;
  }

  // Ctr - From Variants
  __fastcall Variant::Variant()
  {
    ::VariantInit(reinterpret_cast<VARIANTARG *>(this));
  }

  __fastcall Variant::Variant(const Variant& rhs)
  {
    // Handle case where this == &rhs (Compiler messup)
    // NOTE: This copy *MUST* happen before the VARIANTINIT call
    //       because if the compiler calls with this=&rhs, we'll
    //       be wiping out our source!!
    char copy[sizeof(Variant)];
    memcpy(&copy, &rhs, sizeof(copy));

    // Initialize this object
    ::VariantInit(reinterpret_cast<VARIANTARG *>(this));

    // Use assignment operator
    *this = *(reinterpret_cast<Variant*>(&copy));
  }

  __fastcall Variant::Variant(const VARIANT& rhs)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    ::VariantCopy(reinterpret_cast<VARIANTARG *>(this), &(const_cast<VARIANT&>(rhs)));
  }

  __fastcall Variant::Variant(const TVariant& rhs)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    ::VariantCopy(reinterpret_cast<VARIANTARG *>(this), &(const_cast<TVariant&>(rhs)));
  }

  // Ctr - From basic C++ types
  __fastcall Variant::Variant(const bool src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VAR(BOOL, (src? VARIANT_TRUE : VARIANT_FALSE));
  }

  __fastcall Variant::Variant(const char src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VAR(I1, src);
  }

  __fastcall Variant::Variant(const signed char src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VAR(I1, src);
  }

  __fastcall Variant::Variant(const unsigned char src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VAR(UI1, src);
  }

  __fastcall Variant::Variant(const short src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VAR(I2, src);
  }

  __fastcall Variant::Variant(const unsigned short src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VAR(UI2, src);
  }

  __fastcall Variant::Variant(const int src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VAR(I4, src);
  }

  __fastcall Variant::Variant(const unsigned int src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VAR(UI4, src);
  }

  __fastcall Variant::Variant(const long src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VAR(I4, src);
  }

  __fastcall Variant::Variant(const unsigned long src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VAR(UI4, src);
  }

  __fastcall Variant::Variant(const float src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VAR(R4, src);
  }

  __fastcall Variant::Variant(const double src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VAR(R8, src);
  }

  __fastcall Variant::Variant(const long double src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VAR(R8, double(src));
  }

  // Ctr - From OLE Structures
  __fastcall Variant::Variant(const CURRENCY& src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VAR(CY, src);
  }

  __fastcall Variant::Variant(SAFEARRAY& src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VAR(ARRAY, &src);
  }

  __fastcall Variant::Variant(SAFEARRAY* src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VAR(ARRAY, src);
  }

  __fastcall Variant::Variant(VARIANT* src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));

    // NOTE: We could hold on to the Variant by ref...
    /* i.e. SET_VTYPE_AND_VARREF(VARIANT, src); */

    // However, it safer to copy since only one level of indirection is allowed
    //
    ::VariantCopy(reinterpret_cast<VARIANTARG *>(this), src);
  }

  // Ctr - From Utility classes
  // NOTE: This is not OLE compatible (i.e. True VARIANT cannot hold on to an
  //       MBCS string. You must ensure that this Variant is not sent to OLE
  //       in an Invoke call for example. The late-bound functions (Exec,
  //       OleProcedure, OleFunction etc.) exposed by the Variant class
  //       ensures that the string is widened. The code generated by importing
  //       TypeLibraries never utilizes AnsiString. So, in general, we should
  //       be safe.
  //
  __fastcall Variant::Variant(const AnsiString& src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG *>(this));
    VType = varString;
    VString = 0;
    (AnsiString&)VString = src;
  }

  __fastcall Variant::Variant(const Currency& src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG *>(this));
    VType = varCurrency;
    VCurrency = src;
  }

  __fastcall Variant::Variant(const TDateTime& src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG *>(this));
    VType = varDate;
    VDate = src;
  }

  __fastcall Variant::Variant(const VariantError& src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG *>(this));
    SET_VTYPE_AND_VAR(ERROR, src);
  }

  __fastcall Variant::Variant(const WideString& src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG *>(this));
    VType = varOleStr;
    VOleStr = src.Copy();
  }


  // Ctr - Asciiz Pointer
  // We currently treat 'const char*' as a string.
  // However, it could also be viewed as a character by reference!!!!
  __fastcall Variant::Variant(const char* src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG *>(this));
    VType = varString;
    VString = 0;
    (AnsiString&)VString = src;
  }

  // Ctr - OLE Ptrs
  // NOTE: We assume the wchar_t* is a BSTR (i.e. a SysAllocString'ed pointer)
  __fastcall Variant::Variant(wchar_t* src)         // BSTR
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VAR(BSTR, src);
  }

  __fastcall Variant::Variant(LPDISPATCH src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    if (src)
      src->AddRef();
    SET_VTYPE_AND_VAR(DISPATCH, src);
  }

  __fastcall Variant::Variant(LPUNKNOWN src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    if (src)
      src->AddRef();
    SET_VTYPE_AND_VAR(UNKNOWN, src);
  }


  __fastcall Variant::Variant(signed char* src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VARREF(I1, reinterpret_cast<CHAR*>(src));
  }

  __fastcall Variant::Variant(unsigned char* src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VARREF(UI1, src);
  }

  __fastcall Variant::Variant(short* src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VARREF(I2, src);
  }

  __fastcall Variant::Variant(unsigned short* src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VARREF(UI2, src);
  }

  __fastcall Variant::Variant(int* src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VARREF(I4, reinterpret_cast<LONG*>(src));
  }

  __fastcall Variant::Variant(unsigned int* src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VARREF(UI4, reinterpret_cast<ULONG*>(src));

  }

  __fastcall Variant::Variant(long* src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VARREF(I4, src);
  }

  __fastcall Variant::Variant(unsigned long* src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VARREF(UI4, src);
  }

  __fastcall Variant::Variant(float* src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VARREF(R4, src);
  }

  __fastcall Variant::Variant(double* src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VARREF(R8, src);
  }

  __fastcall Variant::Variant(CURRENCY* src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VARREF(CY, src);
  }

  __fastcall Variant::Variant(SAFEARRAY** src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VARREF(ARRAY, src);
  }

  __fastcall Variant::Variant(wchar_t** src)        // VT_BSTR|VT_BYREF
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VARREF(BSTR, src);
  }

  // Ctr - Ref Utility classes
  __fastcall Variant::Variant(Currency* src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    VType = varCurrency | varByRef;
    VPointer = src;
  }

  __fastcall Variant::Variant(TDateTime* src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    VType = varDate | varByRef;
    VPointer = src;
  }

  __fastcall Variant::Variant(Variant* src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    SET_VTYPE_AND_VARREF(VARIANT, reinterpret_cast<VARIANTARG*>(src));
  }

  // Ctr - Arrays
  // Construct a Variant array of type varType
  //
  // For example: Variant ArrayVar(OPENARRAY(int, (0, 0)), varVariant);
  //              Varaint ArrayVar(OpenArray<int>(0, 0)), OpenArrayCount<int>(0, 0).GetHigh(), varVariant);
  __fastcall Variant::Variant(const int* bounds, const int boundsSize, Word varType)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG*>(this));
    *this = System::VarArrayCreate(bounds, boundsSize, varType);
  }

  // Construct a one dimensional Variant array of type varVariant
  // and fill with values
  __fastcall Variant::Variant(const Variant* values, const int valuesSize)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG *>(this));
    *this = System::VarArrayOf(values, valuesSize);
  }

  __fastcall Variant::Variant(const System::DelphiInterface<IDispatch>& src)
  {
    ::VariantInit(reinterpret_cast<VARIANTARG *>(this));
    VType = varDispatch;
    if (!!src)
      src->AddRef();
    VDispatch = src;
  }

  // Dtr
  __fastcall Variant::~Variant()
  {
    Clear();
  }

  // Assignments
  //
  Variant& __fastcall Variant::operator =(const Variant& rhs)
  {
    Clear();
#ifdef USE_VCLHLPR_PAS
    Vclhlpr::VariantCpy(rhs, *this);
#else
    Vclhlpr::VarCopy(*this, rhs);
#endif
    _ASSERTE(/* Dest */vt == /* source */rhs.vt);
    return *this;
  }

  Variant& __fastcall Variant::operator =(const bool rhs)
  {
    Clear();
    SET_VTYPE_AND_VAR(BOOL, (rhs? VARIANT_TRUE : VARIANT_FALSE));
    return *this;
  }

  Variant& __fastcall Variant::operator =(const char rhs)
  {
    Clear();
    SET_VTYPE_AND_VAR(I1, rhs);
    return *this;
  }

  Variant& __fastcall Variant::operator =(const signed char rhs)
  {
    Clear();
    SET_VTYPE_AND_VAR(I1, rhs);
    return *this;
  }

  Variant& __fastcall Variant::operator =(const unsigned char rhs)
  {
    Clear();
    SET_VTYPE_AND_VAR(UI1, rhs);
    return *this;
  }

  Variant& __fastcall Variant::operator =(const short rhs)
  {
    Clear();
    SET_VTYPE_AND_VAR(I2, rhs);
    return *this;
  }

  Variant& __fastcall Variant::operator =(const unsigned short rhs)
  {
    Clear();
    SET_VTYPE_AND_VAR(UI2, rhs);
    return *this;
  }

  Variant& __fastcall Variant::operator =(const int rhs)
  {
    Clear();
    SET_VTYPE_AND_VAR(I4, rhs);
    return *this;
  }

  Variant& __fastcall Variant::operator =(const unsigned int rhs)
  {
    Clear();
    SET_VTYPE_AND_VAR(UI4, rhs);
    return *this;
  }

  Variant& __fastcall Variant::operator =(const long rhs)
  {
    Clear();
    SET_VTYPE_AND_VAR(I4, INT(rhs));
    return *this;
  }

  Variant& __fastcall Variant::operator =(const unsigned long rhs)
  {
    Clear();
    SET_VTYPE_AND_VAR(UI4, INT(rhs));
    return *this;
  }

  Variant& __fastcall Variant::operator =(const float rhs)
  {
    Clear();
    SET_VTYPE_AND_VAR(R4, rhs);
    return *this;
  }

  Variant& __fastcall Variant::operator =(const double rhs)
  {
    Clear();
    SET_VTYPE_AND_VAR(R8, rhs);
    return *this;
  }

  Variant& __fastcall Variant::operator =(const CURRENCY& rhs)
  {
    Clear();
    SET_VTYPE_AND_VAR(CY, rhs);
    return *this;
  }

  Variant& __fastcall Variant::operator =(SAFEARRAY& rhs)
  {
    Clear();
    SET_VTYPE_AND_VAR(ARRAY, &rhs);
    return *this;
  }

  Variant& __fastcall Variant::operator =(SAFEARRAY* rhs)
  {
    Clear();
    SET_VTYPE_AND_VAR(ARRAY, rhs);
    return *this;
  }

  Variant& __fastcall Variant::operator =(const VARIANT& rhs)
  {
    Clear();
    ::VariantCopy(reinterpret_cast<VARIANTARG *>(this), const_cast<VARIANT*>(&rhs));
    return *this;
  }

  Variant& __fastcall Variant::operator =(const TVariant& rhs)
  {
    Clear();
    ::VariantCopy(reinterpret_cast<VARIANTARG *>(this), const_cast<TVariant*>(&rhs));
    return *this;
  }

  Variant& __fastcall Variant::operator =(VARIANT *rhs)
  {
    Clear();

    // Can only have one level of indirection with VT_VARIANT
    //
    if (rhs && rhs->vt != VT_VARIANT && rhs->vt != (VT_VARIANT|VT_BYREF))
    {
      SET_VTYPE_AND_VARREF(VARIANT, rhs);
    }
    else
      ::VariantCopy(reinterpret_cast<VARIANTARG *>(this), rhs);
    return *this;
  }

  Variant& __fastcall Variant::operator =(TVariant *rhs)
  {
    return this->operator=(static_cast<VARIANT*>(rhs));
  }

  // NOTE: We assume the wchar_t* is a BSTR (i.e. a SysAllocString'ed pointer)
  Variant& __fastcall Variant::operator =(wchar_t* rhs)
  {
    Clear();
    SET_VTYPE_AND_VAR(BSTR, rhs);
    return *this;
  }

  Variant& __fastcall Variant::operator =(IUnknown* rhs)
  {
    if (rhs)
      rhs->AddRef();
    Clear();
    SET_VTYPE_AND_VAR(UNKNOWN, rhs);
    return *this;
  }

  Variant& __fastcall Variant::operator =(IDispatch* rhs)
  {
    if (rhs)
      rhs->AddRef();
    Clear();
    SET_VTYPE_AND_VAR(DISPATCH, rhs);
    return *this;
  }

  Variant& __fastcall Variant::operator =(const AnsiString& rhs)
  {
    Clear();
    VType = varString;
    VString = 0;
    (AnsiString&)VString = rhs;
    return *this;
  }

  Variant& __fastcall Variant::operator =(const Currency& rhs)
  {
    Clear();
    VType = varCurrency;
    VCurrency = rhs;
    return *this;
  }

  Variant& __fastcall Variant::operator =(const TDateTime& rhs)
  {
    Clear();
    VType = varDate;
    VDate = rhs;
    return *this;
  }

  Variant& __fastcall Variant::operator =(const VariantError& rhs)
  {
    Clear();
    SET_VTYPE_AND_VAR(ERROR, rhs);
    return *this;
  }

  Variant& __fastcall Variant::operator =(const WideString& src)
  {
    Clear();
    VType = varOleStr;
    VOleStr = src.Copy();
    return *this;
  }

  Variant& __fastcall Variant::operator =(const System::DelphiInterface<IDispatch>& rhs)
  {
    // NOTE: Relies on fact that operat T*() of DelphiInterface does not AddRef!!
    return this->operator=(LPDISPATCH(rhs));
  }


  Variant& __fastcall Variant::operator =(const char* src)            // Treated as pointer Asciiz string
  {
    Clear();
    (*this) = WideString(src);
    return *this;
  }

  Variant& __fastcall Variant::operator =(signed char* src)
  {
    Clear();
    SET_VTYPE_AND_VARREF(I1, (char*)src);
    return *this;
  }

  Variant& __fastcall Variant::operator =(unsigned char* src)
  {
    Clear();
    SET_VTYPE_AND_VARREF(UI1, src);
    return *this;
  }

  Variant& __fastcall Variant::operator =(short* src)
  {
    Clear();
    SET_VTYPE_AND_VARREF(I2, src);
    return *this;
  }

  Variant& __fastcall Variant::operator =(unsigned short* src)
  {
    Clear();
    SET_VTYPE_AND_VARREF(UI2, src);
    return *this;
  }

  Variant& __fastcall Variant::operator =(int* src)
  {
    Clear();
    SET_VTYPE_AND_VARREF(I4, reinterpret_cast<LONG*>(src));
    return *this;
  }

  Variant& __fastcall Variant::operator =(unsigned int* src)
  {
    Clear();
    SET_VTYPE_AND_VARREF(UI4, reinterpret_cast<ULONG*>(src));
    return *this;
  }

  Variant& __fastcall Variant::operator =(long* src)
  {
    Clear();
    SET_VTYPE_AND_VARREF(I4, src);
    return *this;
  }

  Variant& __fastcall Variant::operator =(unsigned long* src)
  {
    Clear();
    SET_VTYPE_AND_VARREF(UI4, src);
    return *this;
  }

  Variant& __fastcall Variant::operator =(float* src)
  {
    Clear();
    SET_VTYPE_AND_VARREF(R4, src);
    return *this;
  }

  Variant& __fastcall Variant::operator =(double* src)
  {
    Clear();
    SET_VTYPE_AND_VARREF(R8, src);
    return *this;
  }

  Variant& __fastcall Variant::operator =(CURRENCY* src)
  {
    Clear();
    SET_VTYPE_AND_VARREF(CY, src);
    return *this;
  }

  Variant& __fastcall Variant::operator =(SAFEARRAY** src)
  {
    Clear();
    SET_VTYPE_AND_VARREF(ARRAY, src);
    return *this;
  }

  Variant& __fastcall Variant::operator =(wchar_t** src) // VT_BSTR|VT_BYREF
  {
    Clear();
    SET_VTYPE_AND_VARREF(BSTR, src);
    return *this;
  }

  Variant& __fastcall Variant::operator =(IUnknown** src)
  {
    Clear();
    SET_VTYPE_AND_VARREF(UNKNOWN, src);
    return *this;
  }

  Variant& __fastcall Variant::operator =(IDispatch** src)
  {
    Clear();
    SET_VTYPE_AND_VARREF(DISPATCH, src);
    return *this;
  }

  Variant& __fastcall Variant::operator =(Currency* src)
  {
    Clear();
    VType = varCurrency | varByRef;
    VPointer = src;
    return *this;
  }

  Variant& __fastcall Variant::operator =(TDateTime* src)
  {
    Clear();
    VType = varDate | varByRef;
    VPointer = src;
    return *this;
  }

  Variant& __fastcall Variant::operator =(Variant* src)
  {
    Clear();
    SET_VTYPE_AND_VARREF(VARIANT, reinterpret_cast<VARIANTARG*>(src));
    return *this;
  }


  Variant& __fastcall Variant::operator +=(const Variant& src)
  {
#ifdef USE_VCLHLPR_PAS
    Vclhlpr::VariantAdd(src, *this);
#else
    Vclhlpr::VarAdd(*this, src);
#endif
    return *this;
  }

  Variant& __fastcall Variant::operator -=(const Variant& src)
  {
#ifdef USE_VCLHLPR_PAS
    Vclhlpr::VariantSub(src, *this);
#else
    Vclhlpr::VarSub(*this, src);
#endif
    return *this;
  }

  Variant& __fastcall Variant::operator *=(const Variant& src)
  {
#ifdef USE_VCLHLPR_PAS
    Vclhlpr::VariantMul(src, *this);
#else
    Vclhlpr::VarMul(*this, src);
#endif
    return *this;
  }

  Variant& __fastcall Variant::operator /=(const Variant& src)
  {
#ifdef USE_VCLHLPR_PAS
    Vclhlpr::VariantDiv(src, *this);
#else
    Vclhlpr::VarDiv(*this, src);
#endif
    return *this;
  }

  Variant& __fastcall Variant::operator %=(const Variant& src)
  {
#ifdef USE_VCLHLPR_PAS
    Vclhlpr::VariantMod(src, *this);
#else
    Vclhlpr::VarMod(*this, src);
#endif
    return *this;
  }

  Variant& __fastcall Variant::operator &=(const Variant& src)
  {
#ifdef USE_VCLHLPR_PAS
    Vclhlpr::VariantAnd(src, *this);
#else
    Vclhlpr::VarAnd(*this, src);
#endif
    return *this;
  }

  Variant& __fastcall Variant::operator |=(const Variant& src)
  {
#ifdef USE_VCLHLPR_PAS
    Vclhlpr::VariantOr(src, *this);
#else
    Vclhlpr::VarOr(*this, src);
#endif
    return *this;
  }

  Variant& __fastcall Variant::operator ^=(const Variant& src)
  {
#ifdef USE_VCLHLPR_PAS
    Vclhlpr::VariantXor(src, *this);
#else
    Vclhlpr::VarXor(*this, src);
#endif
    return *this;
  }

  Variant& __fastcall Variant::operator <<=(const Variant& src)
  {
#ifdef USE_VCLHLPR_PAS
    Vclhlpr::VariantShl(src, *this);
#else
    Vclhlpr::VarShl(*this, src);
#endif
    return *this;
  }

  Variant& __fastcall Variant::operator >>=(const Variant& src)
  {
#ifdef USE_VCLHLPR_PAS
    Vclhlpr::VariantShr(src, *this);
#else
    Vclhlpr::VarShr(*this, src);
#endif
    return *this;
  }

  bool __fastcall Variant::operator ==(const Variant& src) const
  {
#ifdef USE_VCLHLPR_PAS
    return VariantCmp(src, *this);
#else
    return Vclhlpr::VarCmp(*this, src) == 0;
#endif
  }

  bool __fastcall Variant::operator !=(const Variant& src) const
  {
#ifdef USE_VCLHLPR_PAS
    return !VariantCmp(src, *this);
#else
    return Vclhlpr::VarCmp(*this, src) != 0;
#endif
  }

  bool __fastcall Variant::operator <(const Variant& rhs) const
  {
    // Handle some stuff on C++ side (BCB-40469, BCB-13561)
    //
    if (vt == rhs.vt)
    {
      switch (vt)
      {
        case VT_I1:   return V_I1(this)  < V_I1(&rhs);
        case VT_UI1:  return V_UI1(this) < V_UI1(&rhs);
        case VT_I2:   return V_I2(this)  < V_I2(&rhs);
        case VT_UI2:  return V_UI2(this) < V_UI2(&rhs);
        case VT_I4:   return V_I4(this)  < V_I4(&rhs);
        case VT_UI4:  return V_UI4(this) < V_UI4(&rhs);
        case VT_R4:   return V_R4(this)  < V_R4(&rhs);
        case VT_R8:   return V_R8(this)  < V_R8(&rhs);
      }
    }

#ifdef USE_VCLHLPR_PAS
    return Vclhlpr::VariantLT(*this, rhs);
#else
    return Vclhlpr::VarCmp(*this, rhs) < 0;
#endif
  }

  bool __fastcall Variant::operator >(const Variant& rhs) const
  {
    // Handle some stuff on C++ side (BCB-40469, BCB-13561)
    //
    if (vt == rhs.vt)
    {
      switch (vt)
      {
        case VT_I1:   return V_I1(this)  > V_I1(&rhs);
        case VT_UI1:  return V_UI1(this) > V_UI1(&rhs);
        case VT_I2:   return V_I2(this)  > V_I2(&rhs);
        case VT_UI2:  return V_UI2(this) > V_UI2(&rhs);
        case VT_I4:   return V_I4(this)  > V_I4(&rhs);
        case VT_UI4:  return V_UI4(this) > V_UI4(&rhs);
        case VT_R4:   return V_R4(this)  > V_R4(&rhs);
        case VT_R8:   return V_R8(this)  > V_R8(&rhs);
      }
    }

#ifdef USE_VCLHLPR_PAS
    return Vclhlpr::VariantGT(*this, rhs);
#else
    return Vclhlpr::VarCmp(*this, rhs) > 0;
#endif
  }


  bool __fastcall Variant::operator <=(const Variant& rhs) const
  {
    return !operator >(rhs);
  }

  bool __fastcall Variant::operator >=(const Variant& rhs) const
  {
    return !operator <(rhs);
  }

  Variant __fastcall Variant::operator +(const Variant& rhs) const
  {
#ifdef USE_VCLHLPR_PAS
    return Vclhlpr::VariantAdd2(rhs, *this);
#else
    return Variant(*this) += rhs;
#endif
  }

  Variant __fastcall Variant::operator -(const Variant& rhs) const
  {
#ifdef USE_VCLHLPR_PAS
    return Vclhlpr::VariantSub2(rhs, *this);
#else
    return Variant(*this) -= rhs;
#endif
  }

  Variant __fastcall Variant::operator *(const Variant& rhs) const
  {
#ifdef USE_VCLHLPR_PAS
    return Vclhlpr::VariantMul2(rhs, *this);
#else
    return Variant(*this) *= rhs;
#endif
  }

  Variant __fastcall Variant::operator /(const Variant& rhs) const
  {
#ifdef USE_VCLHLPR_PAS
    return Vclhlpr::VariantDiv2(rhs, *this);
#else
    return Variant(*this) /= rhs;
#endif
  }

  Variant __fastcall Variant::operator %(const Variant& rhs) const
  {
#ifdef USE_VCLHLPR_PAS
    return Vclhlpr::VariantMod2(rhs, *this);
#else
    return Variant(*this) %= rhs;
#endif
  }

  Variant __fastcall Variant::operator &(const Variant& rhs) const
  {
#ifdef USE_VCLHLPR_PAS
    return Vclhlpr::VariantAnd2(rhs, *this);
#else
    return Variant(*this) &= rhs;
#endif
  }

  Variant __fastcall Variant::operator |(const Variant& rhs) const
  {
#ifdef USE_VCLHLPR_PAS
    return Vclhlpr::VariantOr2(rhs, *this);
#else
    return Variant(*this) |= rhs;
#endif
  }

  Variant __fastcall Variant::operator ^(const Variant& rhs) const
  {
#ifdef USE_VCLHLPR_PAS
    return Vclhlpr::VariantXor2(rhs, *this);
#else
    return Variant(*this) ^= rhs;
#endif
  }

  Variant __fastcall Variant::operator <<(const Variant& rhs) const
  {
#ifdef USE_VCLHLPR_PAS
    return Vclhlpr::VariantShl2(rhs, *this);
#else
    return Variant(*this) <<= rhs;
#endif
  }

  Variant __fastcall Variant::operator >>(const Variant& rhs) const
  {
#ifdef USE_VCLHLPR_PAS
    return Vclhlpr::VariantShr2(rhs, *this);
#else
    return Variant(*this) >>= rhs;
#endif
  }

  Variant __fastcall Variant::operator -() const
  {
#ifdef USE_VCLHLPR_PAS
    return Vclhlpr::VariantNeg(*this);
#else
    Variant rc(*this);
    Vclhlpr::VarNeg(rc);
    return rc;
#endif
  }

  Variant __fastcall Variant::operator !() const
  {
#ifdef USE_VCLHLPR_PAS
    return Vclhlpr::VariantNot(*this);
#else
    Variant rc(*this);
    Vclhlpr::VarNot(rc);
    return rc;
#endif
  }

  // Conversion operators

  __fastcall Variant::operator bool() const
  {
    Variant tmp;
    System::VarCast(tmp, *this, VT_BOOL);
    return V_BOOL(&tmp) != VARIANT_FALSE;
  }

  __fastcall Variant::operator char() const
  {
    Variant tmp;
    System::VarCast(tmp, *this, VT_I1);
    return V_I1(&tmp);
  }

  __fastcall Variant::operator signed char() const
  {
    Variant tmp;
    System::VarCast(tmp, *this, VT_I1);
    return V_I1(&tmp);
  }

  __fastcall Variant::operator unsigned char() const
  {
    Variant tmp;
    System::VarCast(tmp, *this, VT_UI1);
    return V_UI1(&tmp);
  }

  __fastcall Variant::operator short() const
  {
    Variant tmp;
    System::VarCast(tmp, *this, VT_I2);
    return V_I2(&tmp);
  }

  __fastcall Variant::operator unsigned short() const
  {
    Variant tmp;
    System::VarCast(tmp, *this, VT_UI2);
    return V_UI2(&tmp);
  }

  __fastcall Variant::operator int() const
  {
    Variant tmp;
    System::VarCast(tmp, *this, VT_I4);
    return V_I4(&tmp);
  }

  __fastcall Variant::operator unsigned int() const
  {
    Variant tmp;
    System::VarCast(tmp, *this, VT_UI4);
    return V_UI4(&tmp);
  }

  __fastcall Variant::operator long() const
  {
    Variant tmp;
    System::VarCast(tmp, *this, VT_I4);
    return V_I4(&tmp);
  }

  __fastcall Variant::operator unsigned long() const
  {
    Variant tmp;
    System::VarCast(tmp, *this, VT_UI4);
    return V_UI4(&tmp);
  }

  __fastcall Variant::operator float() const
  {
    Variant tmp;
    System::VarCast(tmp, *this, VT_R4);
    return V_R4(&tmp);
  }

  __fastcall Variant::operator double() const
  {
    Variant tmp;
    System::VarCast(tmp, *this, VT_R8);
    return V_R8(&tmp);
  }

  __fastcall Variant::operator AnsiString() const
  {
    Variant tmp;
    System::VarCast(tmp, *this, varString);
    return AnsiString((AnsiString&)(tmp.VString));
  }

  __fastcall Variant::operator Currency() const
  {
    Variant tmp;
    System::VarCast(tmp, *this, varCurrency);
    return tmp.VCurrency;
  }

  __fastcall Variant::operator TDateTime() const
  {
    Variant tmp;
    System::VarCast(tmp, *this, varDate);
    return tmp.VDate;
  }

  __fastcall Variant::operator WideString() const
  {
    Variant tmp;
    System::VarCast(tmp, *this, varOleStr);
    return WideString(WideString::Copy(tmp.VOleStr));
  }

  __fastcall Variant::operator CURRENCY() const
  {
    Variant tmp;
    System::VarCast(tmp, *this, VT_CY);
    return V_CY(&tmp);
  }

  __fastcall Variant::operator VARIANT()
  {
    VARIANT tmp;
    ::VariantInit(&tmp);

    // Handle case where 'Variant' contains non-standard MBCS string
    //
    if (Type() == varString)
    {
      V_BSTR(&tmp) = WideString(AnsiString(*this)).Detach();
      tmp.vt = VT_BSTR;
    }
    else
      ::VariantCopy(&tmp, reinterpret_cast<VARIANTARG*>(this));

    return tmp;
  }

  __fastcall Variant::operator TVariant()
  {
    return TVariant(*(reinterpret_cast<VARIANT*>(this)));
  }

  __fastcall Variant::operator wchar_t*() const
  {
    Variant tmp;
    System::VarCast(tmp, *this, varOleStr);
    return WideString::Copy(tmp.VOleStr);
  }

  __fastcall Variant::operator IDispatch*()
  {
    // Handle easy case right away
    //
    if (vt==VT_NULL || vt==VT_EMPTY)
      return 0;

    LPUNKNOWN  punk;
    LPDISPATCH disp= 0;
    Variant*   pVar= GetBaseVariant();

    // Get data out of Variant
    //
    switch(pVar->vt)
    {
      case VT_DISPATCH:
      case VT_DISPATCH|VT_BYREF:
        disp = (vt==VT_DISPATCH ? V_DISPATCH(pVar) : (*(V_DISPATCHREF(pVar))));
        if (disp)
          disp->AddRef();
        return disp;

      case VT_UNKNOWN:
      case VT_UNKNOWN|VT_BYREF:
        punk = (vt==VT_UNKNOWN ? V_UNKNOWN(pVar) : (*(V_UNKNOWNREF(pVar))));
        punk->QueryInterface(IID_IDispatch, (LPVOID*)&disp);
        return disp;

      default:
        Variant tmp;
        System::VarCast(tmp, *pVar, varDispatch);
        if (tmp.VDispatch)
          tmp.VDispatch->AddRef();
        return tmp.VDispatch;
    }
  }

  __fastcall Variant::operator IUnknown*()
  {
    // Handle easy case right away
    //
    if (vt==VT_NULL || vt==VT_EMPTY)
      return 0;

    LPDISPATCH disp;
    LPUNKNOWN  punk = 0;
    Variant*   pVar = GetBaseVariant();

    // Get Data out of Variant
    //
    switch(pVar->vt)
    {
      case VT_UNKNOWN:
      case VT_UNKNOWN|VT_BYREF:
        punk = (vt==VT_UNKNOWN ? V_UNKNOWN(pVar) : (*(V_UNKNOWNREF(pVar))));
        punk->AddRef();
        return punk;

      case VT_DISPATCH:
      case VT_DISPATCH|VT_BYREF:
        disp = (vt==VT_DISPATCH ? V_DISPATCH(pVar) : (*(V_DISPATCHREF(pVar))));
        if (disp)
          disp->QueryInterface(IID_IUnknown, (LPVOID*)&punk);
        return punk;

      // Hopefully, we'll never get here, but as last resort
      //
      default:
        Variant tmp;
        System::VarCast(tmp, *pVar, varUnknown);
        if (tmp.VUnknown)
          tmp.VUnknown->AddRef();
        return tmp.VUnknown;
    }
  }

  // By ref conversion operators

#pragma option push -w-rvl

  __fastcall Variant::operator signed char*()
  {
    if (vt== (VT_I1|VT_BYREF))
      return (signed char*)V_I1REF(this);
    else if (vt== VT_I1)
      return (signed char*)&(V_I1(this));
    else
      throw EVariantError(sOpBytePtr);
  }

  __fastcall Variant::operator unsigned char*()
  {
    if (vt == (VT_UI1 | VT_BYREF))
      return V_UI1REF(this);
    else if (vt == VT_UI1)
      return &(V_UI1(this));
    else
      throw EVariantError(sOpBytePtr);
  }

  __fastcall Variant::operator short*()
  {
    if (vt == (VT_I2|VT_BYREF))
      return V_I2REF(this);
    else if (vt == VT_I2)
      return &(V_I2(this));
    else
      throw EVariantError(sOpShortPtr);
  }

  __fastcall Variant::operator unsigned short*()
  {
    if (vt == (VT_UI2|VT_BYREF))
      return V_UI2REF(this);
    else if (vt == VT_UI2)
      return &(V_UI2(this));
    else
      throw EVariantError(sOpShortPtr);
  }

  __fastcall Variant::operator int*()
  {
    if (vt == (VT_I4|VT_BYREF))
      return (int*)V_I4REF(this);
    else if (vt == VT_I4)
      return (int*)&(V_I4(this));
    else
      throw EVariantError(sOpIntPtr);
  }

  __fastcall Variant::operator unsigned int*()
  {
    if (vt == (VT_UI4|VT_BYREF))
      return (unsigned int*)V_UI4REF(this);
    else if (vt == VT_UI4)
      return (unsigned int*)&(V_UI4(this));
    else
      throw EVariantError(sOpIntPtr);
  }

  __fastcall Variant::operator float*()
  {
    if (vt == (VT_R4|VT_BYREF))
      return V_R4REF(this);
    else if (vt == VT_R4)
      return &(V_R4(this));
    else
      throw EVariantError(sOpFloatPtr);
  }

  __fastcall Variant::operator double*()
  {
    if (vt == (VT_R8|VT_BYREF))
      return V_R8REF(this);
    else if (vt == VT_R8)
      return &(V_R8(this));
    else
      throw EVariantError(sOpDoublePtr);
  }

  __fastcall Variant::operator Currency*()
  {
    if (VType == (varCurrency | varByRef))
      return reinterpret_cast<Currency*>(VPointer);
    else if (VType == varCurrency)
      return reinterpret_cast<Currency*>(&VCurrency);
    else
      throw EVariantError(sOpCurrencyPtr);
  }

  __fastcall Variant::operator TDateTime*()
  {
    if (VType == (varDate | varByRef))
      return reinterpret_cast<TDateTime*>(VPointer);
    else if (VType == varDate)
      return reinterpret_cast<TDateTime*>(&VDate);
    else
      throw EVariantError(sOpTDateTimePtr);
  }

  __fastcall Variant::operator wchar_t**()
  {
    if (VType == (varOleStr | varByRef))
      return reinterpret_cast<wchar_t**>(VPointer);
    else if (VType == varOleStr)
      return &VOleStr;
    else
      throw EVariantError(sOpWCharTPtr);
  }

#pragma option pop // -w-rvl

  __fastcall Variant::operator VARIANT*()
  {
    return reinterpret_cast<VARIANT*>(GetBaseVariant());
  }

  __fastcall Variant::operator TVariant*()
  {
    return reinterpret_cast<TVariant*>((VARIANT*)(*this));
  }

  void __fastcall Variant::SetError(const HResult err)
  {
    Clear();
    VType = varError;
    VError = err;
  }

  HResult __fastcall Variant::GetError() const
  {
    Variant tmp;
    System::VarCast(tmp, *this, varError);
    return tmp.VError;
  }

  // Returns pointer to base Variant type when Variant holds other Variant
  //
  Variant* __fastcall Variant::GetBaseVariant()
  {
    Variant *pVar = this;

    // NOTE: Technically there could only be one level of indirection for VT_VARIANT
    //       Additionally, VT_VARIANT should always be used in combination with VT_BYREF
    //       However, it does not hurt to catch multiple indirection or check a simple
    //       VT_VARIANT VARTYPE. Never know what's being packed and sent down out there
    //
    while (((pVar->vt == VT_VARIANT) || (pVar->vt == (VT_VARIANT|VT_BYREF))) && (V_VARIANTREF(pVar)))
      pVar = reinterpret_cast<Variant*>(V_VARIANTREF(pVar));
    return pVar;
  }

  Variant& __fastcall Variant::ChangeType(int varType)
  {
    Variant tmp;
    System::VarCast(tmp, *this, varType);
    return operator =(tmp);
  }

  Variant __fastcall Variant::AsType(int varType) const
  {
    Variant tmp;
    System::VarCast(tmp, *this, varType);
    return tmp;
  }

  Variant __fastcall Variant::Sanitized() const
  {
    Variant tmp;
    // A VARIANT abomination!!
    if (tmp.VType == varString)
    {
      tmp = WideString(AnsiString(*this)).Detach();
    }
    else
    {
      tmp = *this;
    }
    return tmp;
  }

  void __fastcall Variant::Clear()
  {
    System::VarClear(*this);
  }

  int __fastcall Variant::Type() const
  {
    return System::VarType(*this);
  }

  bool __fastcall Variant::IsNull() const
  {
    return System::VarIsNull(*this);
  }

  bool __fastcall Variant::IsEmpty() const
  {
    return System::VarIsEmpty(*this);
  }

  bool __fastcall Variant::IsArray() const
  {
    return System::VarIsArray(*this);
  }

  int __fastcall Variant::ArrayDimCount() const
  {
    return System::VarArrayDimCount(*this);
  }

  int __fastcall Variant::ArrayLowBound(const int dim) const
  {
    return System::VarArrayLowBound(*this, dim);
  }

  int __fastcall Variant::ArrayHighBound(const int dim) const
  {
    return System::VarArrayHighBound(*this, dim);
  }

  void __fastcall Variant::ArrayRedim(int highBound)
  {
    System::VarArrayRedim(*this, highBound);
  }

  Pointer __fastcall Variant::ArrayLock()
  {
    return System::VarArrayLock(*this);
  }

  void    __fastcall Variant::ArrayUnlock()
  {
    System::VarArrayUnlock(*this);
  }

  Variant& __fastcall Variant::operator [](const int idx)
  {
    // Only use this function for arrays of type Variant!
    //
    if (!IsArray() || idx < ArrayLowBound() || idx > ArrayHighBound())
      throw EVariantError(sVarRangeArray);

    Variant* array((Variant*)ArrayLock());
    Variant* v(array + idx);
    ArrayUnlock();
    return *v;
  }

  Variant __fastcall Variant::GetElement(const int i1) const
  {
#ifdef USE_VCLHLPR_PAS
    return Vclhlpr::VariantGetElement(*this, i1);
#else
    return Vclhlpr::VarArrayGet(*this, 1, i1);
#endif
  }

  Variant __fastcall Variant::GetElement(const int i1, const int i2) const
  {
#ifdef USE_VCLHLPR_PAS
    return Vclhlpr::VariantGetElement(*this, i1, i2);
#else
    return Vclhlpr::VarArrayGet(*this, 2, i1, i2);
#endif
  }

  Variant __fastcall Variant::GetElement(const int i1, const int i2, const int i3) const
  {
#ifdef USE_VCLHLPR_PAS
    return Vclhlpr::VariantGetElement(*this, i1, i2, i3);
#else
    return Vclhlpr::VarArrayGet(*this, 3, i1, i2, i3);
#endif
  }

  Variant __fastcall Variant::GetElement(const int i1, const int i2, const int i3, const int i4) const
  {
#ifdef USE_VCLHLPR_PAS
    return Vclhlpr::VariantGetElement(*this, i1, i2, i3, i4);
#else
    return Vclhlpr::VarArrayGet(*this, 4, i1, i2, i3, i4);
#endif
  }

  Variant __fastcall Variant::GetElement(const int i1, const int i2, const int i3, const int i4, const int i5) const
  {
#ifdef USE_VCLHLPR_PAS
    return Vclhlpr::VariantGetElement(*this, i1, i2, i3, i4, i5);
#else
    return Vclhlpr::VarArrayGet(*this, 5, i1, i2, i3, i4, i5);
#endif
  }

  void __fastcall Variant::PutElement(const Variant& data, const int i1)
  {
#ifdef USE_VCLHLPR_PAS
    return Vclhlpr::VariantPutElement(*this, data, i1);
#else
    Vclhlpr::VarArrayPut(*this, data, 1, i1);
#endif
  }

  void __fastcall Variant::PutElement(const Variant& data, const int i1, const int i2)
  {
#ifdef USE_VCLHLPR_PAS
    return Vclhlpr::VariantPutElement(*this, data, i1, i2);
#else
    Vclhlpr::VarArrayPut(*this, data, 2, i1, i2);
#endif
  }

  void __fastcall Variant::PutElement(const Variant& data, const int i1, const int i2, const int i3)
  {
#ifdef USE_VCLHLPR_PAS
    return Vclhlpr::VariantPutElement(*this, data, i1, i2, i3);
#else
    Vclhlpr::VarArrayPut(*this, data, 3, i1, i2, i3);
#endif
  }

  void __fastcall Variant::PutElement(const Variant& data, const int i1, const int i2, const int i3, const int i4)
  {
#ifdef USE_VCLHLPR_PAS
    return Vclhlpr::VariantPutElement(*this, data, i1, i2, i3, i4);
#else
    Vclhlpr::VarArrayPut(*this, data, 4, i1, i2, i3, i4);
#endif
  }

  void __fastcall Variant::PutElement(const Variant& data, const int i1, const int i2, const int i3, const int i4, const int i5)
  {
#ifdef USE_VCLHLPR_PAS
    return Vclhlpr::VariantPutElement(*this, data, i1, i2, i3, i4, i5);
#else
    Vclhlpr::VarArrayPut(*this, data, 5, i1, i2, i3, i4, i5);
#endif
  }

  Variant __fastcall Variant::Exec(AutoCmd& cmd, Integer) const
  {
    //Result
    Variant tmp;
    Variant* ptmp = 0;

    if (cmd.RequestResult())
      ptmp = &tmp;

    //construct a call descriptor
    TCallDesc callDesc;
    TCallDesc* pcallDesc = &callDesc;

    // set calltype, argcount, named arg count
    callDesc.CallType      = cmd.GetCallType();
    callDesc.ArgCount      = cmd.GetArgCount();
    callDesc.NamedArgCount = cmd.GetNamedArgCount();

    // fill in arg types for named args
    for (Byte i = 0; i < callDesc.NamedArgCount; i++)
    {
      int argType = cmd.GetNamedArgType(i);
      if (argType == varString)
        callDesc.ArgTypes[i] = varStrArg;
      else if (argType == (varString | varByRef))
        callDesc.ArgTypes[i] = varStrArg + 128;
      else
      {
        callDesc.ArgTypes[i] = (Byte)(argType & varTypeMask);
        callDesc.ArgTypes[i] += (Byte)((argType & varByRef) ? 128 : 0);
      }
    }

    // fill in arg types for un-named args
    for (Byte i = callDesc.NamedArgCount; i < callDesc.ArgCount; i++)
    {
      int argType = cmd.GetArgType((Byte)(i-callDesc.NamedArgCount));
      if (argType == varString)
        callDesc.ArgTypes[i] = varStrArg;
      else if (argType == (varString | varByRef))
        callDesc.ArgTypes[i] = varStrArg + 128;
      else
      {
        callDesc.ArgTypes[i] = (Byte)(argType & varTypeMask);
        callDesc.ArgTypes[i] += (Byte)((argType & varByRef) ? 128 : 0);
      }
    }

    // get ptr that points after all argtypes
    char* p = (char*) &callDesc.ArgTypes[callDesc.ArgCount];

    // fill in the name of the cmd
    p = stpcpy(p, (char*)cmd.GetName().c_str());

    // fill in names of named args
    for (Byte i = 0; i < callDesc.NamedArgCount; i++)
      p = stpcpy(p+1, (char*)cmd.GetNamedParmName(i).c_str());

    // fill an array of values/addresses of named args (makes asm easier)
    void* namedParms[MaxDispArgs*2];
    void* namedParmsPtr = &namedParms;
    Byte namedCursor = 0;
    for (Byte i = 0; i < callDesc.NamedArgCount; i++)
    {
      Variant* v = &cmd.GetNamedParm(i);
      int argType= cmd.GetNamedArgType(i) & varTypeMask;
      bool byRef = cmd.GetNamedArgType(i) & varByRef;
      if (!byRef)
      {
        switch (argType)
        {
        case varDouble:
        case varDate:
        case varCurrency:
          namedParms[namedCursor++] = reinterpret_cast<void*>(v->VInteger);  // other half
          namedParms[namedCursor++] = reinterpret_cast<void*>(*((&v->VInteger) + 1));     //half
          break;
        case varSingle:
        case varDispatch:
        case varInteger:
        case varBoolean:
        case varOleStr:
        case varUnknown:
          namedParms[namedCursor++] = reinterpret_cast<void*>(v->VInteger);  // pick 1 (union)
          break;
        case varSmallint:
          namedParms[namedCursor++] = reinterpret_cast<void*>((int)v->VSmallint);
          break;
        case varByte:
          namedParms[namedCursor++] = reinterpret_cast<void*>((int)v->VByte);
          break;
        case varVariant:
          namedParms[namedCursor++] = v;
          break;
        }
      }
      else // byRef
      {
          namedParms[namedCursor++] = v->VPointer;
      }
    }
    // fill an array of values/addresses of un-named args (makes asm easier)
    void* parms[MaxDispArgs*2];
    void* parmsPtr = &parms;
    Byte cursor = 0;
    for (Byte i = 0; i < callDesc.ArgCount - callDesc.NamedArgCount; i++)
    {
      Variant* v = &cmd.GetParm(i);
      int argType= cmd.GetArgType(i) & varTypeMask;
      bool byRef = cmd.GetArgType(i) & varByRef;
      if (!byRef)
      {
        switch  (argType)
        {
        case varDouble:
        case varDate:
        case varCurrency:
          parms[cursor++] = reinterpret_cast<void*>(v->VInteger);  // other half
          parms[cursor++] = reinterpret_cast<void*>(*((&v->VInteger) + 1)); //half
          break;
        case varSingle:
        case varDispatch:
        case varInteger:
        case varBoolean:
        case varOleStr:
        case varUnknown:
          parms[cursor++] = reinterpret_cast<void*>(v->VInteger);  // pick 1 (union)
          break;
        case varSmallint:
          parms[cursor++] = reinterpret_cast<void*>((int)v->VSmallint);
          break;
        case varByte:
          parms[cursor++] = reinterpret_cast<void*>((int)v->VByte);
          break;
        case varVariant:
          parms[cursor++] = v;
          break;
        }
      }
      else // byRef
      {
          parms[cursor++] = v->VPointer;
      }
    }

    _EDX  = 0x0;                          // xor  edx, edx
    _DL   = cursor;                       // mov  dl, cursor
    _EDX -= 1;                            // dec  edx
    _EDX <<= 2;                           // shl  edx, 2
    _EAX  = (unsigned long)parmsPtr;      // mov  eax, parmsPtr
    _EDX += _EAX;                         // add  edx, eax
    int cl = cursor;

    while (--cl >= 0)                     // 
    {
      _EAX = *((unsigned long*)_EDX);     // mov  eax, [edx]
      __emit__(0x50);                     // push eax
      _EDX -= 4;                          // sub  edx, 4
    }

    _EDX  = 0x0;                          // xor  edx, edx
    _DL   = namedCursor;                  // mov  dl, namedCursor
    _EDX -= 1;                            // dec  edx
    _EDX <<= 2;                           // shl  edx, 2
    _EAX  = (unsigned long)namedParmsPtr; // mov  eax, namedParmsPtr
    _EDX += _EAX;                         // add  edx, eax
    cl   = namedCursor;                  // mov  cl, namedCursor

    while (--cl >= 0)                     // 
    {
      _EAX = *((unsigned long*)_EDX);     // mov  eax, [edx]
      __emit__(0x50);                     // push eax
      _EDX -= 4;                          // sub  edx, 4
    }

#ifdef USE_VCLHLPR_PAS
    (*Vclhlpr::TVarDispProc(System::VarDispProc))(ptmp, *this, pcallDesc);
#else
    typedef void __cdecl (*TVarDispProc)(System::PVariant Result,
                                         const Variant &Instance,
                                         Comobj::PCallDesc CallDesc);
    (*TVarDispProc(System::VarDispProc))(ptmp, *this, pcallDesc);
#endif

    // NOTE: C++ Compiler cleans up 12 bytes for above 3 parameters.
    //       We only need to clean the extra parameters we pushed

    _ECX  = 0;                            // xor  ecx, ecx
    _CL   = cursor;                       // mov  cl, cursor
    _CL  += namedCursor;                  // add  cl, namedcursor
    _ECX *= 4;                            // shl  ecx, 2
    _ESP += _ECX;                         // add  esp, ecx

/* Original assembly code that required TASM
    asm
    {
      extrn   @System@@DispInvoke$qv:near
      xor     edx, edx
      mov     dl, cursor
      dec     edx
      imul    edx, 4
      add     edx, parmsPtr
      mov     cl, cursor
      @@0:
      dec     cl
      test    cl,  cl
      jl      @@1
      mov     eax, [edx]
      push    eax
      sub     edx, 4
      jmp     @@0

      @@1:
      xor     edx, edx
      mov     dl, namedCursor
      dec     edx
      imul    edx, 4
      add     edx, namedParmsPtr
      mov     cl, namedCursor
      @@2:
      dec     cl
      test    cl,  cl
      jl      @@3
      mov     eax, [edx]
      push    eax
      sub     edx, 4
      jmp     @@2
      @@3:

      push    pcallDesc
      push    this
      push    ptmp

      call    @System@@DispInvoke$qv

      xor     ecx, ecx
      mov     cl, cursor
      add     cl, namedCursor
      imul    ecx, 4
      add     ecx, 12
      add     esp, ecx
    }
*/

    // if no result is returned, return a true
    if (!cmd.RequestResult())
      tmp = true;

    return tmp;
  }


  void Variant::OleProcedure(const String& name, TAutoArgsBase* args)
  {
    // Bind to IDispatch in this Variant
    //
    TAutoDriver<IDispatch> disp;
    disp.Bind(*this /* operator LPDISPATCH() AddRef()s already */, false);

    // Look up the dispid of the name passed
    //
    DISPID id;
    OleCheck(disp.GetIDsOfNames(WideString(name), id));

    // Do Invoke
    //
    if (args)
      OleCheck(disp.OleProcedure(id, *args));
    else
      OleCheck(disp.OleProcedure(id));
  }

  Variant Variant::OleFunction(const String& name, TAutoArgsBase* args)
  {
    // Bind to IDispatch in this Variant
    //
    TAutoDriver<IDispatch> disp;
    disp.Bind(*this /* operator LPDISPATCH() AddRef()s already */, false);

    // Look up the dispid of the name passed
    //
    DISPID id;
    OleCheck(disp.GetIDsOfNames(WideString(name), id));

    // OleFunctions need args array since it returns value
    //
    TAutoArgs<0> _a;
    if (!args)
      args = &_a;

    // Do Invoke
    //
    OleCheck(disp.OleFunction(id, *args));
    return Variant(args->GetRetVariant());
  }

  Variant Variant::OlePropertyGet(const String& name, TAutoArgsBase* args)
  {
    // Bind to IDispatch in this Variant
    //
    TAutoDriver<IDispatch> disp;
    disp.Bind(*this /* operator LPDISPATCH() AddRef()s already */, false);

    // Look up the dispid of the name passed
    //
    DISPID id;
    OleCheck(disp.GetIDsOfNames(WideString(name), id));

    // OlePropertyGets need args array since it returns value
    //
    TAutoArgs<0> _a;
    if (!args)
      args = &_a;

    // Do Invoke
    //
    OleCheck(disp.OlePropertyGet(id, *args));
    return Variant(args->GetRetVariant());
  }

  void Variant::OlePropertySet(const String& name, TAutoArgsBase& args)
  {

    // Bind to IDispatch in this Variant
    //
    TAutoDriver<IDispatch> disp;
    disp.Bind(*this /* operator LPDISPATCH() AddRef()s already */, false);

    // Look up the dispid of the name passed
    //
    DISPID id;
    OleCheck(disp.GetIDsOfNames(WideString(name), id));

    // Do Invoke
    //
    OleCheck(disp.OlePropertyPut(id, args));
  }


  // AutoCmd
  //
  AutoCmd::AutoCmd(const String& name): Name(name)
  {}

  AutoCmd::AutoCmd(const AutoCmd& src): Name(src.Name),
                                        Parms(src.Parms),
                                        ParmTypes(src.ParmTypes),
                                        NamedParms(src.NamedParms),
                                        NamedParmTypes(src.NamedParmTypes),
                                        NamedParmNames(src.NamedParmNames)
  {}

  AutoCmd::~AutoCmd()
  {}

  AutoCmd& AutoCmd::SetName(const String& name)
  {
    Name = name;
    return *this;
  }

  AutoCmd& AutoCmd::Clear()
  {
    ClearName();
    ClearArgs();
    return *this;
  }

  AutoCmd& AutoCmd::ClearName()
  {
    SetName("");
    return *this;
  }

  AutoCmd& AutoCmd::ClearArgs()
  {
    Parms.Clear();
    ParmTypes.Clear();

    NamedParms.Clear();
    NamedParmTypes.Clear();
    NamedParmNames.Clear();

    return *this;
  }

  int AutoCmd::GetArgType(const Byte idx) const
  {
    if (ParmTypes.IsEmpty() || ParmTypes.ArrayHighBound() < idx)
      throw EVariantError(sAcGatRange);
    return ParmTypes.GetElement(idx);
  }

  int AutoCmd::GetNamedArgType(const Byte idx) const
  {
    if (NamedParmTypes.IsEmpty() || NamedParmTypes.ArrayHighBound() < idx)
      throw EVariantError(sAcGnatRange);
    return NamedParmTypes.GetElement(idx);
  }

  Byte AutoCmd::GetArgCount() const
  {
    int count = GetNamedArgCount();
    if (!Parms.IsEmpty())
      count += Parms.ArrayHighBound() + 1;
    return (Byte) count;
  }

  Byte AutoCmd::GetNamedArgCount() const
  {
    int count = 0;
    if (!NamedParms.IsEmpty())
      count += NamedParms.ArrayHighBound() + 1;
    return (Byte)count;
  }

  Variant& AutoCmd::GetParm(const Byte idx)
  {
    if (Parms.IsEmpty() || Parms.ArrayHighBound() < idx)
      throw EVariantError(sAcGpRange);
    return Parms[idx];
  }

  Variant& AutoCmd::GetNamedParm(const Byte idx)
  {
    if (NamedParms.IsEmpty() || NamedParms.ArrayHighBound() < idx)
      throw EVariantError(sAcGnpRange);
    return NamedParms[idx];
  }

  String AutoCmd::GetNamedParmName(const Byte idx) const
  {
    if (NamedParms.IsEmpty() || NamedParms.ArrayHighBound() < idx)
      throw EVariantError(sAcGnpnRange);
    return NamedParmNames.GetElement(idx);
  }

  void AutoCmd::AddElement()
  {
    if (Parms.IsEmpty())
    {
      Parms = Variant(OPENARRAY(int, (0, 0)), varVariant);
      _ASSERTE(Parms.vt == (VT_ARRAY|VT_VARIANT));
      ParmTypes = Variant(OPENARRAY(int, (0, 0)), varInteger);
      _ASSERTE(ParmTypes.vt == (VT_ARRAY|VT_I4));
    }
    else
    {
      Parms.ArrayRedim(Parms.ArrayHighBound()+1);
      ParmTypes.ArrayRedim(ParmTypes.ArrayHighBound()+1);
    }
  }

  AutoCmd& AutoCmd::operator <<(const Variant& v)
  {
    AddElement();

    // Handle case where Variant contains a non-Automation compatible AnsiString
    Variant tmp(v);
    if (tmp.vt == varString)
      tmp.ChangeType(varOleStr);
    Parms.PutElement(tmp, Parms.ArrayHighBound());
    ParmTypes.PutElement(tmp.Type(), ParmTypes.ArrayHighBound());
    return *this;
  }

  AutoCmd& AutoCmd::operator <<(const short arg)
  {
    AddElement();
    Parms.PutElement(arg, Parms.ArrayHighBound());
    ParmTypes.PutElement(varSmallint, ParmTypes.ArrayHighBound());
    return *this;
  }

  AutoCmd& AutoCmd::operator <<(const int arg)
  {
    AddElement();
    Parms.PutElement(arg, Parms.ArrayHighBound());
    ParmTypes.PutElement(varInteger, ParmTypes.ArrayHighBound());
    return *this;
  }

  AutoCmd& AutoCmd::operator <<(const float arg)
  {
    AddElement();
    Parms.PutElement(arg, Parms.ArrayHighBound());
    ParmTypes.PutElement(varSingle, ParmTypes.ArrayHighBound());
    return *this;
  }

  AutoCmd& AutoCmd::operator <<(const double arg)
  {
    AddElement();
    Parms.PutElement(arg, Parms.ArrayHighBound());
    ParmTypes.PutElement(varDouble, ParmTypes.ArrayHighBound());
    return *this;
  }

  AutoCmd& AutoCmd::operator <<(const Currency arg)
  {
    AddElement();
    Parms.PutElement(arg, Parms.ArrayHighBound());
    ParmTypes.PutElement(varCurrency, ParmTypes.ArrayHighBound());
    return *this;
  }

  AutoCmd& AutoCmd::operator <<(const TDateTime arg)
  {
    AddElement();
    Parms.PutElement(arg, Parms.ArrayHighBound());
    ParmTypes.PutElement(varDate, ParmTypes.ArrayHighBound());
    return *this;
  }

  AutoCmd& AutoCmd::operator <<(const bool arg)
  {
    AddElement();
    Parms.PutElement(arg, Parms.ArrayHighBound());
    ParmTypes.PutElement(varBoolean, ParmTypes.ArrayHighBound());
    return *this;
  }

  AutoCmd& AutoCmd::operator <<(const WordBool arg)
  {
    AddElement();
    Parms.PutElement(arg, Parms.ArrayHighBound());
    ParmTypes.PutElement(varBoolean, ParmTypes.ArrayHighBound());
    return *this;
  }

  AutoCmd& AutoCmd::operator <<(const Byte arg)
  {
    AddElement();
    Parms.PutElement(arg, Parms.ArrayHighBound());
    ParmTypes.PutElement(varByte, ParmTypes.ArrayHighBound());
    return *this;
  }

  AutoCmd& AutoCmd::operator <<(const AnsiString& arg)
  {
    AddElement();
    // NOTE: AnsiString is converted to BSTR
    Parms.PutElement(WideString(arg).Detach(), Parms.ArrayHighBound());
    ParmTypes.PutElement(varOleStr, ParmTypes.ArrayHighBound());
    return *this;
  }

  AutoCmd& AutoCmd::operator <<(IDispatch* arg)
  {
    AddElement();
    Parms.PutElement(arg, Parms.ArrayHighBound());
    ParmTypes.PutElement(varDispatch, ParmTypes.ArrayHighBound());
    return *this;
  }

  AutoCmd& AutoCmd::operator <<(wchar_t* arg)
  {
    AddElement();
    Parms.PutElement(arg, Parms.ArrayHighBound());
    ParmTypes.PutElement(varOleStr, ParmTypes.ArrayHighBound());
    return *this;
  }

  AutoCmd& AutoCmd::operator <<(IUnknown* arg)
  {
    AddElement();
    Parms.PutElement(arg, Parms.ArrayHighBound());
    ParmTypes.PutElement(varUnknown, ParmTypes.ArrayHighBound());
    return *this;
  }

  AutoCmd& AutoCmd::operator <<(Variant* arg)
  {
    AddElement();
    Parms.PutElement(arg, Parms.ArrayHighBound());
    ParmTypes.PutElement(varVariant | varByRef, ParmTypes.ArrayHighBound());
    return *this;
  }

  AutoCmd& AutoCmd::operator <<(short* arg)
  {
    AddElement();
    Parms.PutElement(arg, Parms.ArrayHighBound());
    ParmTypes.PutElement(varSmallint | varByRef, ParmTypes.ArrayHighBound());
    return *this;
  }

  AutoCmd& AutoCmd::operator <<(int* arg)
  {
    AddElement();
    Parms.PutElement(arg, Parms.ArrayHighBound());
    ParmTypes.PutElement(varInteger | varByRef, ParmTypes.ArrayHighBound());
    return *this;
  }

  AutoCmd& AutoCmd::operator <<(float* arg)
  {
    AddElement();
    Parms.PutElement(arg, Parms.ArrayHighBound());
    ParmTypes.PutElement(varSingle | varByRef, ParmTypes.ArrayHighBound());
    return *this;
  }

  AutoCmd& AutoCmd::operator <<(double* arg)
  {
    AddElement();
    Parms.PutElement(arg, Parms.ArrayHighBound());
    ParmTypes.PutElement(varDouble | varByRef, ParmTypes.ArrayHighBound());
    return *this;
  }

  AutoCmd& AutoCmd::operator <<(Currency* arg)
  {
    AddElement();
    Parms.PutElement(arg, Parms.ArrayHighBound());
    ParmTypes.PutElement(varCurrency | varByRef, ParmTypes.ArrayHighBound());
    return *this;
  }

  AutoCmd& AutoCmd::operator <<(TDateTime* arg)
  {
    AddElement();
    Parms.PutElement(arg, Parms.ArrayHighBound());
    ParmTypes.PutElement(varDate | varByRef, ParmTypes.ArrayHighBound());
    return *this;
  }

  AutoCmd& AutoCmd::operator <<(WordBool* arg)
  {
    AddElement();
    Parms.PutElement(arg, Parms.ArrayHighBound());
    ParmTypes.PutElement(varBoolean | varByRef, ParmTypes.ArrayHighBound());
    return *this;
  }

  AutoCmd& AutoCmd::operator <<(Byte* arg)
  {
    AddElement();
    Parms.PutElement(arg, Parms.ArrayHighBound());
    ParmTypes.PutElement(varByte | varByRef, ParmTypes.ArrayHighBound());
    return *this;
  }

  AutoCmd& AutoCmd::operator <<(AnsiString* arg)
  {
    // Automation Server does not support the non-OLE MBCS string type.
    // Hence, we turn the string into a plain string
    return this->operator << (*arg);
  }

  AutoCmd& AutoCmd::operator <<(const NamedParm& np)
  {
    if (NamedParms.IsEmpty())
    {
      NamedParms     = Variant(OPENARRAY(int, (0, 0)), varVariant);
      NamedParmTypes = Variant(OPENARRAY(int, (0, 0)), varInteger);
      NamedParmNames = Variant(OPENARRAY(int, (0, 0)), varVariant);
    }
    else
    {
      NamedParms.ArrayRedim(NamedParms.ArrayHighBound()+1);
      NamedParmTypes.ArrayRedim(NamedParmTypes.ArrayHighBound()+1);
      NamedParmNames.ArrayRedim(NamedParmNames.ArrayHighBound()+1);
    }

    NamedParmNames.PutElement(np.GetParmName(), NamedParmNames.ArrayHighBound());
    NamedParmTypes.PutElement(np.GetType(), NamedParmTypes.ArrayHighBound());
    NamedParms.PutElement(np.GetParm(), NamedParms.ArrayHighBound());

    return *this;
  }
} // namespace System

