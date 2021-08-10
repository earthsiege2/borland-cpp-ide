// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdPOP3.pas' rev: 6.00

#ifndef IdPOP3HPP
#define IdPOP3HPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdComponent.hpp>	// Pascal unit
#include <IdTCPConnection.hpp>	// Pascal unit
#include <IdTCPClient.hpp>	// Pascal unit
#include <IdMessageClient.hpp>	// Pascal unit
#include <IdMessage.hpp>	// Pascal unit
#include <IdGlobal.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idpop3
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdPOP3;
class PASCALIMPLEMENTATION TIdPOP3 : public Idmessageclient::TIdMessageClient 
{
	typedef Idmessageclient::TIdMessageClient inherited;
	
protected:
	AnsiString FPassword;
	AnsiString FUserId;
	
public:
	bool __fastcall RetrieveRaw(const int MsgNum, const Classes::TStrings* Dest);
	int __fastcall CheckMessages(void);
	virtual void __fastcall Connect(void);
	__fastcall virtual TIdPOP3(Classes::TComponent* AOwner);
	bool __fastcall Delete(const int MsgNum);
	virtual void __fastcall Disconnect(void);
	void __fastcall KeepAlive(void);
	bool __fastcall Reset(void);
	bool __fastcall Retrieve(const int MsgNum, Idmessage::TIdMessage* AMsg);
	bool __fastcall RetrieveHeader(const int MsgNum, Idmessage::TIdMessage* AMsg);
	int __fastcall RetrieveMsgSize(const int MsgNum);
	int __fastcall RetrieveMailBoxSize(void);
	
__published:
	__property AnsiString Password = {read=FPassword, write=FPassword};
	__property AnsiString UserId = {read=FUserId, write=FUserId};
	__property Port  = {default=110};
public:
	#pragma option push -w-inl
	/* TIdTCPClient.Destroy */ inline __fastcall virtual ~TIdPOP3(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idpop3 */
using namespace Idpop3;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdPOP3
