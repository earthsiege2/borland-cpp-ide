// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'OleServer.pas' rev: 6.00

#ifndef OleServerHPP
#define OleServerHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ComObj.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Oleserver
{
//-- type declarations -------------------------------------------------------
typedef DynamicArray<OleVariant >  TVariantArray;

#pragma option push -b-
enum TConnectKind { ckRunningOrNew, ckNewInstance, ckRunningInstance, ckRemote, ckAttachToInterface };
#pragma option pop

class DELPHICLASS TServerEventDispatch;
class DELPHICLASS TOleServer;
struct TServerData;
typedef TServerData *PServerData;

class PASCALIMPLEMENTATION TOleServer : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	TServerData *FServerData;
	int FRefCount;
	TServerEventDispatch* FEventDispatch;
	int FEventsConnection;
	bool FAutoConnect;
	AnsiString FRemoteMachineName;
	TConnectKind FConnectKind;
	
protected:
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	HIDESBASE int __stdcall _AddRef(void);
	HIDESBASE int __stdcall _Release(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall InitServerData(void) = 0 ;
	virtual System::_di_IInterface __fastcall GetServer();
	void __fastcall ConnectEvents(const System::_di_IInterface Obj);
	void __fastcall DisconnectEvents(const System::_di_IInterface Obj);
	virtual void __fastcall InvokeEvent(int DispID, TVariantArray &Params);
	TConnectKind __fastcall GetConnectKind(void);
	void __fastcall SetConnectKind(TConnectKind ck);
	bool __fastcall GetAutoConnect(void);
	void __fastcall SetAutoConnect(bool flag);
	__property PServerData ServerData = {read=FServerData, write=FServerData};
	__property TServerEventDispatch* EventDispatch = {read=FEventDispatch, write=FEventDispatch};
	
public:
	__fastcall virtual TOleServer(Classes::TComponent* AOwner);
	__fastcall virtual ~TOleServer(void);
	virtual void __fastcall Connect(void) = 0 ;
	virtual void __fastcall Disconnect(void) = 0 ;
	
__published:
	__property bool AutoConnect = {read=GetAutoConnect, write=SetAutoConnect, nodefault};
	__property TConnectKind ConnectKind = {read=GetConnectKind, write=SetConnectKind, nodefault};
	__property AnsiString RemoteMachineName = {read=FRemoteMachineName, write=FRemoteMachineName};
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class PASCALIMPLEMENTATION TServerEventDispatch : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TOleServer* FServer;
	int InternalRefCount;
	
protected:
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	HRESULT __stdcall GetTypeInfoCount(/* out */ int &Count);
	HRESULT __stdcall GetTypeInfo(int Index, int LocaleID, /* out */ void *TypeInfo);
	HRESULT __stdcall GetIDsOfNames(const GUID &IID, void * Names, int NameCount, int LocaleID, void * DispIDs);
	HRESULT __stdcall Invoke(int DispID, const GUID &IID, int LocaleID, Word Flags, void *Params, void * VarResult, void * ExcepInfo, void * ArgErr);
	__property TOleServer* Server = {read=FServer};
	bool __fastcall ServerDisconnect(void);
	
public:
	__fastcall TServerEventDispatch(TOleServer* Server);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TServerEventDispatch(void) { }
	#pragma option pop
	
private:
	void *__IDispatch;	/* IDispatch */
	
public:
	operator IDispatch*(void) { return (IDispatch*)&__IDispatch; }
	operator IInterface*(void) { return (IInterface*)&__IDispatch; }
	
};


#pragma pack(push, 4)
struct TServerData
{
	GUID ClassID;
	GUID IntfIID;
	GUID EventIID;
	void *LicenseKey;
	int Version;
	int InstanceCount;
} ;
#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Oleserver */
using namespace Oleserver;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// OleServer
