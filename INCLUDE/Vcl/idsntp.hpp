// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdSNTP.pas' rev: 6.00

#ifndef IdSNTPHPP
#define IdSNTPHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdComponent.hpp>	// Pascal unit
#include <IdUDPBase.hpp>	// Pascal unit
#include <IdUDPClient.hpp>	// Pascal unit
#include <IdGlobal.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsntp
{
//-- type declarations -------------------------------------------------------
#pragma pack(push, 1)
struct TNTPGram
{
	Byte Head1;
	Byte Head2;
	Byte Head3;
	Byte Head4;
	int RootDelay;
	int RootDispersion;
	int RefID;
	int Ref1;
	int Ref2;
	int Org1;
	int Org2;
	int Rcv1;
	int Rcv2;
	int Xmit1;
	int Xmit2;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TLr
{
	Byte L1;
	Byte L2;
	Byte L3;
	Byte L4;
} ;
#pragma pack(pop)

class DELPHICLASS TIdSNTP;
class PASCALIMPLEMENTATION TIdSNTP : public Idudpclient::TIdUDPClient 
{
	typedef Idudpclient::TIdUDPClient inherited;
	
protected:
	System::TDateTime FDestinationTimestamp;
	System::TDateTime FLocalClockOffset;
	System::TDateTime FOriginateTimestamp;
	System::TDateTime FReceiveTimestamp;
	System::TDateTime FRoundTripDelay;
	System::TDateTime FTransmitTimestamp;
	bool __fastcall Disregard(const TNTPGram &NTPMessage);
	System::TDateTime __fastcall GetAdjustmentTime(void);
	System::TDateTime __fastcall GetDateTime(void);
	
public:
	__fastcall virtual TIdSNTP(Classes::TComponent* AOwner);
	bool __fastcall SyncTime(void);
	__property System::TDateTime AdjustmentTime = {read=GetAdjustmentTime};
	__property System::TDateTime DateTime = {read=GetDateTime};
	__property System::TDateTime RoundTripDelay = {read=FRoundTripDelay};
	__property Port  = {default=123};
public:
	#pragma option push -w-inl
	/* TIdUDPBase.Destroy */ inline __fastcall virtual ~TIdSNTP(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define NTPMaxInt  (4.294967E+09)

}	/* namespace Idsntp */
using namespace Idsntp;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdSNTP
