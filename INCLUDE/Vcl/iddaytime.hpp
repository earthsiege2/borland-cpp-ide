// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdDayTime.pas' rev: 6.00

#ifndef IdDayTimeHPP
#define IdDayTimeHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdComponent.hpp>	// Pascal unit
#include <IdTCPConnection.hpp>	// Pascal unit
#include <IdTCPClient.hpp>	// Pascal unit
#include <IdGlobal.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Iddaytime
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdDayTime;
class PASCALIMPLEMENTATION TIdDayTime : public Idtcpclient::TIdTCPClient 
{
	typedef Idtcpclient::TIdTCPClient inherited;
	
protected:
	AnsiString __fastcall GetDayTimeStr();
	
public:
	__fastcall virtual TIdDayTime(Classes::TComponent* AOwner);
	__property AnsiString DayTimeStr = {read=GetDayTimeStr};
	
__published:
	__property Port  = {default=13};
public:
	#pragma option push -w-inl
	/* TIdTCPClient.Destroy */ inline __fastcall virtual ~TIdDayTime(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Iddaytime */
using namespace Iddaytime;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdDayTime
