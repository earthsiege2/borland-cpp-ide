// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'NMMSG.pas' rev: 5.00

#ifndef NMMSGHPP
#define NMMSGHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <NMConst.hpp>	// Pascal unit
#include <Psock.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Nmmsg
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TMSGEvent)(Classes::TComponent* Sender, const AnsiString sFrom, 
	const AnsiString sMsg);

class DELPHICLASS TNMMsg;
class PASCALIMPLEMENTATION TNMMsg : public Psock::TPowersock 
{
	typedef Psock::TPowersock inherited;
	
private:
	AnsiString sFromName;
	Classes::TNotifyEvent FOnMessageSent;
	
public:
	__fastcall virtual TNMMsg(Classes::TComponent* AOwner);
	virtual void __fastcall Abort(void);
	AnsiString __fastcall PostIt(const AnsiString sMsg);
	
__published:
	__property AnsiString FromName = {read=sFromName, write=sFromName};
	__property Classes::TNotifyEvent OnMessageSent = {read=FOnMessageSent, write=FOnMessageSent};
public:
		
	#pragma option push -w-inl
	/* TPowersock.Destroy */ inline __fastcall virtual ~TNMMsg(void) { }
	#pragma option pop
	
};


class DELPHICLASS TNMMSGServ;
class PASCALIMPLEMENTATION TNMMSGServ : public Psock::TNMGeneralServer 
{
	typedef Psock::TNMGeneralServer inherited;
	
private:
	TMSGEvent FOnMSG;
	
public:
	__fastcall virtual TNMMSGServ(Classes::TComponent* AOwner);
	virtual void __fastcall Serve(void);
	
__published:
	__property TMSGEvent OnMSG = {read=FOnMSG, write=FOnMSG};
public:
	#pragma option push -w-inl
	/* TNMGeneralServer.Destroy */ inline __fastcall virtual ~TNMMSGServ(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Nmmsg */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Nmmsg;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// NMMSG
