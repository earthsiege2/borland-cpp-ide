// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'NMSTRM.pas' rev: 5.00

#ifndef NMSTRMHPP
#define NMSTRMHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <NMConst.hpp>	// Pascal unit
#include <Psock.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Nmstrm
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TStrmEvent)(Classes::TComponent* Sender, const AnsiString sFrom, 
	Classes::TStream* strm);

class DELPHICLASS TNMStrm;
class PASCALIMPLEMENTATION TNMStrm : public Psock::TPowersock 
{
	typedef Psock::TPowersock inherited;
	
private:
	AnsiString sFromName;
	Classes::TNotifyEvent FOnMessageSent;
	
public:
	__fastcall virtual TNMStrm(Classes::TComponent* AOwner);
	virtual void __fastcall Abort(void);
	AnsiString __fastcall PostIt(const Classes::TStream* sStrm);
	
__published:
	__property OnPacketRecvd ;
	__property OnPacketSent ;
	__property AnsiString FromName = {read=sFromName, write=sFromName};
	__property Classes::TNotifyEvent OnMessageSent = {read=FOnMessageSent, write=FOnMessageSent};
public:
		
	#pragma option push -w-inl
	/* TPowersock.Destroy */ inline __fastcall virtual ~TNMStrm(void) { }
	#pragma option pop
	
};


class DELPHICLASS TNMStrmServ;
class PASCALIMPLEMENTATION TNMStrmServ : public Psock::TNMGeneralServer 
{
	typedef Psock::TNMGeneralServer inherited;
	
private:
	TStrmEvent FOnMSG;
	
public:
	__fastcall virtual TNMStrmServ(Classes::TComponent* AOwner);
	virtual void __fastcall Serve(void);
	
__published:
	__property TStrmEvent OnMSG = {read=FOnMSG, write=FOnMSG};
public:
	#pragma option push -w-inl
	/* TNMGeneralServer.Destroy */ inline __fastcall virtual ~TNMStrmServ(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Nmstrm */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Nmstrm;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// NMSTRM
