// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdTunnelMaster.pas' rev: 6.00

#ifndef IdTunnelMasterHPP
#define IdTunnelMasterHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdComponent.hpp>	// Pascal unit
#include <SyncObjs.hpp>	// Pascal unit
#include <IdTunnelCommon.hpp>	// Pascal unit
#include <IdTCPClient.hpp>	// Pascal unit
#include <IdTCPServer.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idtunnelmaster
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS MClientThread;
class DELPHICLASS TIdTunnelMaster;
typedef void __fastcall (__closure *TSendTrnEvent)(Idtcpserver::TIdPeerThread* Thread, Idtunnelcommon::TIdHeader &Header, AnsiString &CustomMsg);

typedef void __fastcall (__closure *TSendMsgEvent)(Idtcpserver::TIdPeerThread* Thread, AnsiString &CustomMsg);

class PASCALIMPLEMENTATION TIdTunnelMaster : public Idtcpserver::TIdTCPServer 
{
	typedef Idtcpserver::TIdTCPServer inherited;
	
private:
	int fiMappedPort;
	AnsiString fsMappedHost;
	Classes::TThreadList* Clients;
	Idtcpserver::TIdServerThreadEvent fOnConnect;
	Idtcpserver::TIdServerThreadEvent fOnDisconnect;
	Idtcpserver::TIdServerThreadEvent fOnTransformRead;
	TSendTrnEvent fOnTransformSend;
	TSendMsgEvent fOnInterpretMsg;
	Syncobjs::TCriticalSection* OnlyOneThread;
	Syncobjs::TCriticalSection* StatisticsLocker;
	bool fbActive;
	bool fbLockDestinationHost;
	bool fbLockDestinationPort;
	Idtunnelcommon::TLogger* fLogger;
	int flConnectedSlaves;
	int flConnectedServices;
	int fNumberOfConnectionsValue;
	int fNumberOfPacketsValue;
	int fCompressionRatioValue;
	int fCompressedBytes;
	int fBytesRead;
	int fBytesWrite;
	void __fastcall ClientOperation(int Operation, int UserId, AnsiString s);
	void __fastcall SendMsg(Idtcpserver::TIdPeerThread* MasterThread, Idtunnelcommon::TIdHeader &Header, AnsiString s);
	void __fastcall DisconectAllUsers(void);
	void __fastcall DisconnectAllSubThreads(Idtcpserver::TIdPeerThread* TunnelThread);
	int __fastcall GetNumSlaves(void);
	int __fastcall GetNumServices(void);
	MClientThread* __fastcall GetClientThread(int UserID);
	
protected:
	virtual void __fastcall SetActive(bool pbValue);
	virtual void __fastcall DoConnect(Idtcpserver::TIdPeerThread* Thread);
	virtual void __fastcall DoDisconnect(Idtcpserver::TIdPeerThread* Thread);
	virtual bool __fastcall DoExecute(Idtcpserver::TIdPeerThread* Thread);
	virtual void __fastcall DoTransformRead(Idtcpserver::TIdPeerThread* Thread);
	virtual void __fastcall DoTransformSend(Idtcpserver::TIdPeerThread* Thread, Idtunnelcommon::TIdHeader &Header, AnsiString &CustomMsg);
	virtual void __fastcall DoInterpretMsg(Idtcpserver::TIdPeerThread* Thread, AnsiString &CustomMsg);
	void __fastcall LogEvent(AnsiString Msg);
	
__published:
	__property AnsiString MappedHost = {read=fsMappedHost, write=fsMappedHost};
	__property int MappedPort = {read=fiMappedPort, write=fiMappedPort, nodefault};
	__property bool LockDestinationHost = {read=fbLockDestinationHost, write=fbLockDestinationHost, default=0};
	__property bool LockDestinationPort = {read=fbLockDestinationPort, write=fbLockDestinationPort, default=0};
	__property Idtcpserver::TIdServerThreadEvent OnConnect = {read=fOnConnect, write=fOnConnect};
	__property Idtcpserver::TIdServerThreadEvent OnDisconnect = {read=fOnDisconnect, write=fOnDisconnect};
	__property Idtcpserver::TIdServerThreadEvent OnTransformRead = {read=fOnTransformRead, write=fOnTransformRead};
	__property TSendTrnEvent OnTransformSend = {read=fOnTransformSend, write=fOnTransformSend};
	__property TSendMsgEvent OnInterpretMsg = {read=fOnInterpretMsg, write=fOnInterpretMsg};
	
public:
	__property bool Active = {read=fbActive, write=SetActive, default=1};
	__property Idtunnelcommon::TLogger* Logger = {read=fLogger, write=fLogger};
	__property int NumSlaves = {read=GetNumSlaves, nodefault};
	__property int NumServices = {read=GetNumServices, nodefault};
	void __fastcall SetStatistics(int Module, int Value);
	void __fastcall GetStatistics(int Module, int &Value);
	__fastcall virtual TIdTunnelMaster(Classes::TComponent* AOwner);
	__fastcall virtual ~TIdTunnelMaster(void);
};


class PASCALIMPLEMENTATION MClientThread : public Classes::TThread 
{
	typedef Classes::TThread inherited;
	
public:
	TIdTunnelMaster* MasterParent;
	int UserId;
	Idtcpserver::TIdPeerThread* MasterThread;
	Idtcpclient::TIdTCPClient* OutboundClient;
	bool DisconnectedOnRequest;
	Syncobjs::TCriticalSection* Locker;
	bool SelfDisconnected;
	virtual void __fastcall Execute(void);
	__fastcall MClientThread(TIdTunnelMaster* master);
	__fastcall virtual ~MClientThread(void);
};


class DELPHICLASS TSlaveData;
class PASCALIMPLEMENTATION TSlaveData : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	Idtunnelcommon::TReceiver* Receiver;
	Idtunnelcommon::TSender* Sender;
	Syncobjs::TCriticalSection* Locker;
	bool SelfDisconnected;
	System::TObject* UserData;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TSlaveData(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TSlaveData(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TSendTrnEventC)(Idtunnelcommon::TIdHeader &Header, AnsiString &CustomMsg);

typedef void __fastcall (__closure *TTunnelEventC)(Idtunnelcommon::TReceiver* Receiver);

typedef void __fastcall (__closure *TSendMsgEventC)(AnsiString &CustomMsg);

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idtunnelmaster */
using namespace Idtunnelmaster;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdTunnelMaster
