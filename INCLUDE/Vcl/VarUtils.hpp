// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'VarUtils.pas' rev: 6.00

#ifndef VarUtilsHPP
#define VarUtilsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Types.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Varutils
{
//-- type declarations -------------------------------------------------------
#pragma pack(push, 4)
struct TVarTypeToElementInfo
{
	bool ValidBase;
	bool ValidElement;
	int Size;
	Word Flags;
} ;
#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const bool GenericVarUtils = false;
static const bool GenericVariants = false;
static const bool GenericOperations = false;
static const bool GenericSafeArrays = false;
static const bool GenericSafeArrayUsesLibC = false;
static const HRESULT VAR_OK = 0x0;
static const HRESULT VAR_TYPEMISMATCH = 0x80020005;
static const HRESULT VAR_BADVARTYPE = 0x80020008;
static const HRESULT VAR_EXCEPTION = 0x80020009;
static const HRESULT VAR_OVERFLOW = 0x8002000a;
static const HRESULT VAR_BADINDEX = 0x8002000b;
static const HRESULT VAR_ARRAYISLOCKED = 0x8002000d;
static const HRESULT VAR_NOTIMPL = 0x80004001;
static const HRESULT VAR_OUTOFMEMORY = 0x8007000e;
static const HRESULT VAR_INVALIDARG = 0x80070057;
static const HRESULT VAR_UNEXPECTED = 0x8000ffff;
static const Shortint ARR_NONE = 0x0;
static const Shortint ARR_FIXEDSIZE = 0x10;
static const Word ARR_OLESTR = 0x100;
static const Word ARR_UNKNOWN = 0x200;
static const Word ARR_DISPATCH = 0x400;
static const Word ARR_VARIANT = 0x800;
static const Shortint CMinArrayVarType = 0x0;
static const Shortint CMaxArrayVarType = 0x15;
extern PACKAGE TVarTypeToElementInfo CVarTypeToElementInfo[22];
extern PACKAGE HRESULT __fastcall VarExceptionToResult(const Sysutils::Exception* E);
extern "C" HRESULT __stdcall VariantInit(TVarData &V);
extern "C" HRESULT __stdcall VariantClear(TVarData &V);
extern "C" HRESULT __stdcall VariantCopy(TVarData &Dest, const TVarData &Source);
extern "C" HRESULT __stdcall VariantCopyInd(TVarData &Dest, const TVarData &Source);
extern "C" HRESULT __stdcall VariantChangeTypeEx(TVarData &Dest, const TVarData &Source, int LCID, Word wFlags, Word VarType);
extern "C" HRESULT __stdcall VarNeg(const TVarData &Source, TVarData &Dest);
extern "C" HRESULT __stdcall VarNot(const TVarData &Source, TVarData &Dest);
extern "C" HRESULT __stdcall VarI4FromStr(const WideString strIn, int LCID, int dwFlags, /* out */ int &lOut);
extern "C" HRESULT __stdcall VarR8FromStr(const WideString strIn, int LCID, int dwFlags, /* out */ double &dblOut);
extern "C" HRESULT __stdcall VarDateFromStr(const WideString strIn, unsigned lcid, int dwFlags, /* out */ System::TDateTime &dateOut);
extern "C" HRESULT __stdcall VarCyFromStr(const WideString strIn, unsigned lcid, int dwFlags, /* out */ System::Currency &cyOut);
extern "C" HRESULT __stdcall VarBoolFromStr(const WideString strIn, int LCID, int dwFlags, /* out */ Word &boolOut);
extern "C" HRESULT __stdcall VarBstrFromCy(System::Currency cyIn, int LCID, int dwFlags, /* out */ WideString &bstrOut);
extern "C" HRESULT __stdcall VarBstrFromDate(System::TDateTime dateIn, int LCID, int dwFlags, /* out */ WideString &bstrOut);
extern "C" HRESULT __stdcall VarBstrFromBool(Word boolIn, int LCID, int dwFlags, /* out */ WideString &bstrOut);
extern "C" System::PVarArray __stdcall SafeArrayCreate(int VarType, int DimCount, const System::TVarArrayBound * Bounds);
extern "C" HRESULT __stdcall SafeArrayAllocDescriptor(int DimCount, /* out */ System::PVarArray &VarArray);
extern "C" HRESULT __stdcall SafeArrayAllocData(System::PVarArray VarArray);
extern "C" HRESULT __stdcall SafeArrayDestroy(System::PVarArray VarArray);
extern "C" HRESULT __stdcall SafeArrayDestroyDescriptor(System::PVarArray VarArray);
extern "C" HRESULT __stdcall SafeArrayDestroyData(System::PVarArray VarArray);
extern "C" HRESULT __stdcall SafeArrayRedim(System::PVarArray VarArray, const System::TVarArrayBound &NewBound);
extern "C" HRESULT __stdcall SafeArrayCopy(System::PVarArray SourceArray, /* out */ System::PVarArray &TargetArray);
extern "C" HRESULT __stdcall SafeArrayCopyData(System::PVarArray SourceArray, System::PVarArray TargetArray);
extern "C" HRESULT __stdcall SafeArrayGetLBound(System::PVarArray VarArray, int Dim, /* out */ int &LBound);
extern "C" HRESULT __stdcall SafeArrayGetUBound(System::PVarArray VarArray, int Dim, /* out */ int &UBound);
extern "C" int __stdcall SafeArrayGetDim(System::PVarArray VarArray);
extern "C" HRESULT __stdcall SafeArrayAccessData(System::PVarArray VarArray, /* out */ void * &Data);
extern "C" HRESULT __stdcall SafeArrayUnaccessData(System::PVarArray VarArray);
extern "C" HRESULT __stdcall SafeArrayLock(System::PVarArray VarArray);
extern "C" HRESULT __stdcall SafeArrayUnlock(System::PVarArray VarArray);
extern "C" HRESULT __stdcall SafeArrayGetElement(System::PVarArray VarArray, System::PVarArrayCoorArray Indices, void * Data);
extern "C" HRESULT __stdcall SafeArrayPutElement(System::PVarArray VarArray, System::PVarArrayCoorArray Indices, const void * Data);
extern "C" HRESULT __stdcall SafeArrayPtrOfIndex(System::PVarArray VarArray, System::PVarArrayCoorArray Indices, void * &Address);
extern "C" unsigned __stdcall SafeArrayGetElemSize(System::PVarArray VarArray);

}	/* namespace Varutils */
using namespace Varutils;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// VarUtils
