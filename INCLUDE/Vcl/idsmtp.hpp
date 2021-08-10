// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdSMTP.pas' rev: 6.00

#ifndef IdSMTPHPP
#define IdSMTPHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdComponent.hpp>	// Pascal unit
#include <IdTCPConnection.hpp>	// Pascal unit
#include <IdTCPClient.hpp>	// Pascal unit
#include <IdMessageClient.hpp>	// Pascal unit
#include <IdHeaderList.hpp>	// Pascal unit
#include <IdEMailAddress.hpp>	// Pascal unit
#include <IdMessage.hpp>	// Pascal unit
#include <IdGlobal.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsmtp
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TAuthenticationType { atNone, atLogin };
#pragma option pop

class DELPHICLASS TIdSMTP;
class PASCALIMPLEMENTATION TIdSMTP : public Idmessageclient::TIdMessageClient 
{
	typedef Idmessageclient::TIdMessageClient inherited;
	
protected:
	bool FDidAuthenticate;
	TAuthenticationType FAuthenticationType;
	Classes::TStringList* FAuthSchemesSupported;
	AnsiString FMailAgent;
	AnsiString FPassword;
	AnsiString FUserId;
	void __fastcall GetAuthTypes(void);
	virtual bool __fastcall IsAuthProtocolAvailable(TAuthenticationType Auth);
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual bool __fastcall Authenticate(void);
	virtual void __fastcall Connect(void);
	__fastcall virtual TIdSMTP(Classes::TComponent* AOwner);
	__fastcall virtual ~TIdSMTP(void);
	virtual void __fastcall Disconnect(void);
	/*         class method */ static void __fastcall QuickSend(TMetaClass* vmt, const AnsiString AHost, const AnsiString ASubject, const AnsiString ATo, const AnsiString AFrom, const AnsiString AText);
	virtual void __fastcall Send(Idmessage::TIdMessage* AMsg);
	__property Classes::TStringList* AuthSchemesSupported = {read=FAuthSchemesSupported};
	
__published:
	__property TAuthenticationType AuthenticationType = {read=FAuthenticationType, write=FAuthenticationType, default=0};
	__property AnsiString MailAgent = {read=FMailAgent, write=FMailAgent};
	__property AnsiString Password = {read=FPassword, write=FPassword};
	__property AnsiString UserId = {read=FUserId, write=FUserId};
	__property Port  = {default=25};
};


//-- var, const, procedure ---------------------------------------------------
#define ID_TIDSMTP_AUTH_TYPE (TAuthenticationType)(0)

}	/* namespace Idsmtp */
using namespace Idsmtp;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdSMTP
