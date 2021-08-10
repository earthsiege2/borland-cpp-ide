// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdStackWinsock.pas' rev: 6.00

#ifndef IdStackWinsockHPP
#define IdStackWinsockHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <IdWinsock.hpp>	// Pascal unit
#include <IdStackConsts.hpp>	// Pascal unit
#include <IdStack.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idstackwinsock
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdStackVersionWinsock;
class PASCALIMPLEMENTATION TIdStackVersionWinsock : public Idstack::TIdStackVersion 
{
	typedef Idstack::TIdStackVersion inherited;
	
public:
	__fastcall virtual TIdStackVersionWinsock(void * InfoStruct);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIdStackVersionWinsock(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIdStackWinsock;
class PASCALIMPLEMENTATION TIdStackWinsock : public Idstack::TIdStack 
{
	typedef Idstack::TIdStack inherited;
	
protected:
	virtual void __fastcall PopulateLocalAddresses(void);
	virtual AnsiString __fastcall WSGetLocalAddress();
	virtual Classes::TStrings* __fastcall WSGetLocalAddresses(void);
	
public:
	__fastcall virtual TIdStackWinsock(void);
	__fastcall virtual ~TIdStackWinsock(void);
	virtual AnsiString __fastcall TInAddrToString(void *AInAddr);
	virtual void __fastcall TranslateStringToTInAddr(AnsiString AIP, void *AInAddr);
	virtual int __fastcall WSAccept(int ASocket, AnsiString &VIP, int &VPort);
	virtual int __fastcall WSBind(int ASocket, const int AFamily, const AnsiString AIP, const int APort);
	virtual int __fastcall WSCloseSocket(int ASocket);
	virtual int __fastcall WSConnect(const int ASocket, const int AFamily, const AnsiString AIP, const int APort);
	virtual AnsiString __fastcall WSGetHostByAddr(const AnsiString AAddress);
	virtual AnsiString __fastcall WSGetHostByName(const AnsiString AHostName);
	virtual AnsiString __fastcall WSGetHostName();
	virtual int __fastcall WSGetServByName(const AnsiString AServiceName);
	virtual Classes::TStrings* __fastcall WSGetServByPort(const int APortNumber);
	virtual void __fastcall WSGetPeerName(int ASocket, int &VFamily, AnsiString &VIP, int &VPort);
	virtual void __fastcall WSGetSockName(int ASocket, int &VFamily, AnsiString &VIP, int &VPort);
	virtual Word __fastcall WSHToNs(Word AHostShort);
	virtual int __fastcall WSListen(int ASocket, int ABackLog);
	virtual Word __fastcall WSNToHs(Word ANetShort);
	virtual unsigned __fastcall WSHToNL(unsigned AHostLong);
	virtual unsigned __fastcall WSNToHL(unsigned ANetLong);
	virtual int __fastcall WSRecv(int ASocket, void *ABuffer, int ABufferLength, int AFlags);
	virtual int __fastcall WSRecvFrom(const int ASocket, void *ABuffer, const int ALength, const int AFlags, AnsiString &VIP, int &VPort);
	virtual int __fastcall WSSelect(Classes::TList* ARead, Classes::TList* AWrite, Classes::TList* AErrors, int ATimeout);
	virtual int __fastcall WSSend(int ASocket, void *ABuffer, const int ABufferLength, const int AFlags);
	virtual int __fastcall WSSendTo(int ASocket, void *ABuffer, const int ABufferLength, const int AFlags, const AnsiString AIP, const int APort);
	virtual int __fastcall WSSetSockOpt(int ASocket, int ALevel, int AOptName, char * AOptVal, int AOptLen);
	virtual int __fastcall WSSocket(int AFamily, int AStruct, int AProtocol);
	virtual int __fastcall WSShutdown(int ASocket, int AHow);
	virtual int __fastcall WSGetLastError(void);
};


#pragma pack(push, 2)
struct TLinger
{
	Word l_onoff;
	Word l_linger;
} ;
#pragma pack(pop)

typedef TLinger  TIdLinger;

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idstackwinsock */
using namespace Idstackwinsock;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdStackWinsock
