// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'VirtIntf.pas' rev: 6.00

#ifndef VirtIntfHPP
#define VirtIntfHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Virtintf
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TInterface;
class PASCALIMPLEMENTATION TInterface : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	int FRefCount;
	
public:
	__fastcall TInterface(void);
	HIDESBASE void __fastcall Free(void);
	virtual int __stdcall AddRef(void);
	virtual int __stdcall Release(void);
	virtual int __stdcall GetVersion(void);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TInterface(void) { }
	#pragma option pop
	
};


__interface IStreamModifyTime;
typedef System::DelphiInterface<IStreamModifyTime> _di_IStreamModifyTime;
__interface INTERFACE_UUID("{12452621-5F8A-11D1-9FB6-0020AF3D82DA}") IStreamModifyTime  : public IInterface 
{
	
public:
	virtual int __stdcall GetModifyTime(void) = 0 ;
	virtual void __stdcall SetModifyTime(int Time) = 0 ;
};

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE AnsiString __fastcall ReleaseException();

}	/* namespace Virtintf */
using namespace Virtintf;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// VirtIntf
