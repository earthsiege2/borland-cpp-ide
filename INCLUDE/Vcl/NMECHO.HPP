// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'NMEcho.pas' rev: 6.00

#ifndef NMEchoHPP
#define NMEchoHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <NMConst.hpp>	// Pascal unit
#include <Psock.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Nmecho
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TNMEcho;
class PASCALIMPLEMENTATION TNMEcho : public Psock::TPowersock 
{
	typedef Psock::TPowersock inherited;
	
private:
	AnsiString FEchoInStr;
	float FElapsedTime;
	
public:
	__fastcall virtual TNMEcho(Classes::TComponent* AOwner);
	AnsiString __fastcall Echo(AnsiString EchoString);
	__property float ElapsedTime = {read=FElapsedTime};
	
__published:
	__property OnConnectionRequired ;
public:
	#pragma option push -w-inl
	/* TPowersock.Destroy */ inline __fastcall virtual ~TNMEcho(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Nmecho */
using namespace Nmecho;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// NMEcho
