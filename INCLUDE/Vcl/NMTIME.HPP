// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'NMTime.pas' rev: 5.00

#ifndef NMTimeHPP
#define NMTimeHPP

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

namespace Nmtime
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TNMTime;
class PASCALIMPLEMENTATION TNMTime : public Psock::TPowersock 
{
	typedef Psock::TPowersock inherited;
	
private:
	AnsiString __fastcall GetTimeStr();
	int __fastcall GetTimeInt(void);
	
public:
	__fastcall virtual TNMTime(Classes::TComponent* AOwner);
	
__published:
	__property AnsiString TimeStr = {read=GetTimeStr};
	__property int TimeInt = {read=GetTimeInt, nodefault};
public:
	#pragma option push -w-inl
	/* TPowersock.Destroy */ inline __fastcall virtual ~TNMTime(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Nmtime */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Nmtime;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// NMTime
