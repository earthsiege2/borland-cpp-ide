// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'AutoDisp.pas' rev: 6.00

#ifndef AutoDispHPP
#define AutoDispHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Masks.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Autodisp
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TWebDispatch;
class DELPHICLASS TWebPathInfo;
class PASCALIMPLEMENTATION TWebPathInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Masks::TMask* FMask;
	AnsiString FMaskPathInfo;
	AnsiString FPathInfo;
	Classes::TComponent* FOwner;
	Masks::TMask* __fastcall GetMask(void);
	AnsiString __fastcall GetPathInfo();
	void __fastcall SetPathInfo(const AnsiString Value);
	
public:
	__fastcall TWebPathInfo(Classes::TComponent* AOwner);
	__fastcall virtual ~TWebPathInfo(void);
	__property Masks::TMask* Mask = {read=GetMask};
	__property AnsiString PathInfo = {read=GetPathInfo, write=SetPathInfo};
};


class PASCALIMPLEMENTATION TWebDispatch : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	TWebPathInfo* FPathInfo;
	Httpapp::TMethodType FMethodType;
	bool FEnabled;
	Masks::TMask* __fastcall GetMask(void);
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	void __fastcall SetPathInfo(const AnsiString Value);
	AnsiString __fastcall GetPathInfo();
	
public:
	__fastcall TWebDispatch(Classes::TComponent* AComponent);
	__fastcall virtual ~TWebDispatch(void);
	__property Masks::TMask* Mask = {read=GetMask};
	
__published:
	__property bool Enabled = {read=FEnabled, write=FEnabled, default=1};
	__property Httpapp::TMethodType MethodType = {read=FMethodType, write=FMethodType, default=3};
	__property AnsiString PathInfo = {read=GetPathInfo, write=SetPathInfo};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Autodisp */
using namespace Autodisp;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// AutoDisp
