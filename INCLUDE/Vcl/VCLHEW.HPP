// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'VclHew.pas' rev: 5.00

#ifndef VclHewHPP
#define VclHewHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <AxCtrls.hpp>	// Pascal unit
#include <StdVCL.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <ComObj.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Vclhew
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TPropertyPageImplHack;
class PASCALIMPLEMENTATION TPropertyPageImplHack : public Axctrls::TPropertyPageImpl 
{
	typedef Axctrls::TPropertyPageImpl inherited;
	
public:
	HIDESBASE HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	HIDESBASE int __stdcall _AddRef(void);
	HIDESBASE int __stdcall _Release(void);
public:
	#pragma option push -w-inl
	/* TAggregatedObject.Create */ inline __fastcall TPropertyPageImplHack(_di_IUnknown Controller) : Axctrls::TPropertyPageImpl(
		Controller) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TPropertyPageImplHack(void) { }
	#pragma option pop
	
private:
	void *__IUnknown;	/* IUnknown */
	
public:
	operator IUnknown*(void) { return (IUnknown*)&__IUnknown; }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall VariantCpy(const Variant &src, Variant &dst);
extern PACKAGE void __fastcall VariantAdd(const Variant &src, Variant &dst);
extern PACKAGE void __fastcall VariantSub(const Variant &src, Variant &dst);
extern PACKAGE void __fastcall VariantMul(const Variant &src, Variant &dst);
extern PACKAGE void __fastcall VariantDiv(const Variant &src, Variant &dst);
extern PACKAGE void __fastcall VariantMod(const Variant &src, Variant &dst);
extern PACKAGE void __fastcall VariantAnd(const Variant &src, Variant &dst);
extern PACKAGE void __fastcall VariantOr(const Variant &src, Variant &dst);
extern PACKAGE void __fastcall VariantXor(const Variant &src, Variant &dst);
extern PACKAGE void __fastcall VariantShl(const Variant &src, Variant &dst);
extern PACKAGE void __fastcall VariantShr(const Variant &src, Variant &dst);
extern PACKAGE bool __fastcall VariantCmp(const Variant &v1, const Variant &V2);
extern PACKAGE bool __fastcall VariantLT(const Variant &V1, const Variant &V2);
extern PACKAGE bool __fastcall VariantGT(const Variant &V1, const Variant &V2);
extern PACKAGE Variant __fastcall VariantAdd2(const Variant &V1, const Variant &V2);
extern PACKAGE Variant __fastcall VariantSub2(const Variant &V1, const Variant &V2);
extern PACKAGE Variant __fastcall VariantMul2(const Variant &V1, const Variant &V2);
extern PACKAGE Variant __fastcall VariantDiv2(const Variant &V1, const Variant &V2);
extern PACKAGE Variant __fastcall VariantMod2(const Variant &V1, const Variant &V2);
extern PACKAGE Variant __fastcall VariantAnd2(const Variant &V1, const Variant &V2);
extern PACKAGE Variant __fastcall VariantOr2(const Variant &V1, const Variant &V2);
extern PACKAGE Variant __fastcall VariantXor2(const Variant &V1, const Variant &V2);
extern PACKAGE Variant __fastcall VariantShl2(const Variant &V1, const Variant &V2);
extern PACKAGE Variant __fastcall VariantShr2(const Variant &V1, const Variant &V2);
extern PACKAGE Variant __fastcall VariantNot(const Variant &V1);
extern PACKAGE Variant __fastcall VariantNeg(const Variant &V1);
extern PACKAGE Variant __fastcall VariantGetElement(const Variant &V, int i1)/* overload */;
extern PACKAGE Variant __fastcall VariantGetElement(const Variant &V, int i1, int i2)/* overload */;
	
extern PACKAGE Variant __fastcall VariantGetElement(const Variant &V, int i1, int i2, int i3)/* overload */
	;
extern PACKAGE Variant __fastcall VariantGetElement(const Variant &V, int i1, int i2, int i3, int i4
	)/* overload */;
extern PACKAGE Variant __fastcall VariantGetElement(const Variant &V, int i1, int i2, int i3, int i4
	, int i5)/* overload */;
extern PACKAGE void __fastcall VariantPutElement(Variant &V, const Variant &data, int i1)/* overload */
	;
extern PACKAGE void __fastcall VariantPutElement(Variant &V, const Variant &data, int i1, int i2)/* overload */
	;
extern PACKAGE void __fastcall VariantPutElement(Variant &V, const Variant &data, int i1, int i2, int 
	i3)/* overload */;
extern PACKAGE void __fastcall VariantPutElement(Variant &V, const Variant &data, int i1, int i2, int 
	i3, int i4)/* overload */;
extern PACKAGE void __fastcall VariantPutElement(Variant &V, const Variant &data, int i1, int i2, int 
	i3, int i4, int i5)/* overload */;

}	/* namespace Vclhew */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Vclhew;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// VclHew
