// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdMessageClient.pas' rev: 6.00

#ifndef IdMessageClientHPP
#define IdMessageClientHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdComponent.hpp>	// Pascal unit
#include <IdTCPConnection.hpp>	// Pascal unit
#include <IdCoderText.hpp>	// Pascal unit
#include <IdCoder3To4.hpp>	// Pascal unit
#include <IdCoderIMF.hpp>	// Pascal unit
#include <IdCoder.hpp>	// Pascal unit
#include <IdHeaderList.hpp>	// Pascal unit
#include <IdTCPClient.hpp>	// Pascal unit
#include <IdMessage.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idmessageclient
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdMessageClient;
class PASCALIMPLEMENTATION TIdMessageClient : public Idtcpclient::TIdTCPClient 
{
	typedef Idtcpclient::TIdTCPClient inherited;
	
protected:
	Word FMsgLineLength;
	AnsiString FMsgLineFold;
	virtual void __fastcall ReceiveBody(Idmessage::TIdMessage* AMsg);
	virtual void __fastcall ReceiveHeader(Idmessage::TIdMessage* AMsg, const AnsiString ADelim);
	virtual void __fastcall ReceiveMsg(Idmessage::TIdMessage* AMsg, const AnsiString ADelim);
	virtual void __fastcall SendBody(Idmessage::TIdMessage* AMsg, const int Attcount, const int Textcount, const int RelCount);
	virtual void __fastcall SendMsg(Idmessage::TIdMessage* AMsg);
	virtual void __fastcall SendHeader(Idmessage::TIdMessage* AMsg, int &AttCount, int &TextCount, int &RelCount);
	void __fastcall WriteFoldedLine(const AnsiString ALine);
	
public:
	__fastcall virtual TIdMessageClient(Classes::TComponent* AOwner);
	__property Word MsgLineLength = {read=FMsgLineLength, write=FMsgLineLength, nodefault};
	__property AnsiString MsgLineFold = {read=FMsgLineFold, write=FMsgLineFold};
public:
	#pragma option push -w-inl
	/* TIdTCPClient.Destroy */ inline __fastcall virtual ~TIdMessageClient(void) { }
	#pragma option pop
	
};


struct TIMFCoderUsage;
typedef TIMFCoderUsage *PIMFCoderUsage;

#pragma pack(push, 4)
struct TIMFCoderUsage
{
	bool InUse;
	Idcoder::TIdCoder* BodyCoder;
	Idmessage::TIdMessagePart* MP;
} ;
#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
#define MultiPartBoundary "=_NextPart_2rfkindysadvnqw3nerasdf"
#define MultiPartAlternativeBoundary "=_NextPart_2altrfkindysadvnqw3nerasdf"
#define MultiPartRelatedBoundary "=_NextPart_2relrfksadvnqindyw3nerasdf"
#define MIMEGenericText "text/"
#define MIME7Bit "7bit"

}	/* namespace Idmessageclient */
using namespace Idmessageclient;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdMessageClient
