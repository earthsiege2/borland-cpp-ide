// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'NMDayTim.pas' rev: 6.00

#ifndef NMDayTimHPP
#define NMDayTimHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <NMConst.hpp>	// Pascal unit
#include <WinSock.hpp>	// Pascal unit
#include <Psock.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Nmdaytim
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TNMDayTime;
class PASCALIMPLEMENTATION TNMDayTime : public Psock::TPowersock 
{
	typedef Psock::TPowersock inherited;
	
private:
	AnsiString __fastcall GetTimeStr();
	
public:
	__fastcall virtual TNMDayTime(Classes::TComponent* AOwner);
	__property AnsiString DayTimeStr = {read=GetTimeStr};
public:
	#pragma option push -w-inl
	/* TPowersock.Destroy */ inline __fastcall virtual ~TNMDayTime(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Nmdaytim */
using namespace Nmdaytim;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// NMDayTim
