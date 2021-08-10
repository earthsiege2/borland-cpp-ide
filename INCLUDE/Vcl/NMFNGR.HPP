// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'NMFngr.pas' rev: 5.00

#ifndef NMFngrHPP
#define NMFngrHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <NMConst.hpp>	// Pascal unit
#include <Psock.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Nmfngr
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TNMFinger;
class PASCALIMPLEMENTATION TNMFinger : public Psock::TPowersock 
{
	typedef Psock::TPowersock inherited;
	
private:
	AnsiString FUser;
	AnsiString __fastcall GetFingerString();
	
public:
	__fastcall virtual TNMFinger(Classes::TComponent* AOwner);
	
__published:
	__property AnsiString FingerStr = {read=GetFingerString};
	__property AnsiString User = {read=FUser, write=FUser};
public:
	#pragma option push -w-inl
	/* TPowersock.Destroy */ inline __fastcall virtual ~TNMFinger(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Nmfngr */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Nmfngr;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// NMFngr
