// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'MConnect.pas' rev: 6.00

#ifndef MConnectHPP
#define MConnectHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Provider.hpp>	// Pascal unit
#include <ComObj.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <DBClient.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <Midas.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Mconnect
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCustomObjectBroker;
class PASCALIMPLEMENTATION TCustomObjectBroker : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
public:
	virtual void __fastcall SetConnectStatus(AnsiString ComputerName, bool Success) = 0 ;
	virtual AnsiString __fastcall GetComputerForGUID(const GUID &GUID) = 0 ;
	virtual AnsiString __fastcall GetComputerForProgID(const void *ProgID) = 0 ;
	virtual int __fastcall GetPortForComputer(const AnsiString ComputerName) = 0 ;
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TCustomObjectBroker(Classes::TComponent* AOwner) : Classes::TComponent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TCustomObjectBroker(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDispatchAppServer;
class PASCALIMPLEMENTATION TDispatchAppServer : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	Midas::_di_IAppServerDisp FAppServer;
	HRESULT __stdcall GetTypeInfoCount(/* out */ int &Count);
	HRESULT __stdcall GetTypeInfo(int Index, int LocaleID, /* out */ void *TypeInfo);
	HRESULT __stdcall GetIDsOfNames(const GUID &IID, void * Names, int NameCount, int LocaleID, void * DispIDs);
	HRESULT __stdcall Invoke(int DispID, const GUID &IID, int LocaleID, Word Flags, void *Params, void * VarResult, void * ExcepInfo, void * ArgErr);
	HRESULT __safecall AS_ApplyUpdates(const WideString ProviderName, const OleVariant Delta, int MaxErrors, /* out */ int &ErrorCount, OleVariant &OwnerData, OleVariant &AS_ApplyUpdates_result);
	HRESULT __safecall AS_GetRecords(const WideString ProviderName, int Count, /* out */ int &RecsOut, int Options, const WideString CommandText, OleVariant &Params, OleVariant &OwnerData, OleVariant &AS_GetRecords_result);
	HRESULT __safecall AS_DataRequest(const WideString ProviderName, const OleVariant Data, OleVariant &AS_DataRequest_result);
	HRESULT __safecall AS_GetProviderNames(OleVariant &AS_GetProviderNames_result);
	HRESULT __safecall AS_GetParams(const WideString ProviderName, OleVariant &OwnerData, OleVariant &AS_GetParams_result);
	HRESULT __safecall AS_RowRequest(const WideString ProviderName, const OleVariant Row, int RequestType, OleVariant &OwnerData, OleVariant &AS_RowRequest_result);
	HRESULT __safecall AS_Execute(const WideString ProviderName, const WideString CommandText, OleVariant &Params, OleVariant &OwnerData);
	HRESULT __stdcall InterfaceSupportsErrorInfo(const GUID &iid);
	
public:
	__fastcall TDispatchAppServer(const Midas::_di_IAppServerDisp AppServer);
	virtual HRESULT __fastcall SafeCallException(System::TObject* ExceptObject, void * ExceptAddr);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TDispatchAppServer(void) { }
	#pragma option pop
	
private:
	void *__IAppServer;	/* Midas::IAppServer */
	void *__ISupportErrorInfo;	/* ISupportErrorInfo */
	
public:
	operator ISupportErrorInfo*(void) { return (ISupportErrorInfo*)&__ISupportErrorInfo; }
	operator IAppServer*(void) { return (IAppServer*)&__IAppServer; }
	
};


class DELPHICLASS TLocalConnection;
class PASCALIMPLEMENTATION TLocalConnection : public Dbclient::TCustomRemoteServer 
{
	typedef Dbclient::TCustomRemoteServer inherited;
	
private:
	Midas::_di_IAppServer FAppServer;
	Classes::TList* FProviders;
	int __fastcall GetProviderCount(void);
	
protected:
	virtual Provider::TCustomProvider* __fastcall GetProvider(const AnsiString ProviderName);
	HRESULT __safecall AS_GetProviderNames(OleVariant &AS_GetProviderNames_result);
	HRESULT __safecall AS_ApplyUpdates(const WideString ProviderName, const OleVariant Delta, int MaxErrors, /* out */ int &ErrorCount, OleVariant &OwnerData, OleVariant &AS_ApplyUpdates_result);
	HRESULT __safecall AS_GetRecords(const WideString ProviderName, int Count, /* out */ int &RecsOut, int Options, const WideString CommandText, OleVariant &Params, OleVariant &OwnerData, OleVariant &AS_GetRecords_result);
	HRESULT __safecall AS_DataRequest(const WideString ProviderName, const OleVariant Data, OleVariant &AS_DataRequest_result);
	HRESULT __safecall AS_GetParams(const WideString ProviderName, OleVariant &OwnerData, OleVariant &AS_GetParams_result);
	HRESULT __safecall AS_RowRequest(const WideString ProviderName, const OleVariant Row, int RequestType, OleVariant &OwnerData, OleVariant &AS_RowRequest_result);
	HRESULT __safecall AS_Execute(const WideString ProviderName, const WideString CommandText, OleVariant &Params, OleVariant &OwnerData);
	virtual bool __fastcall GetConnected(void);
	virtual void __fastcall GetProviderNames(Classes::TGetStrProc Proc);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall RegisterProvider(Provider::TCustomProvider* Prov);
	void __fastcall UnRegisterProvider(Provider::TCustomProvider* Prov);
	
public:
	__fastcall virtual TLocalConnection(Classes::TComponent* AOwner);
	__fastcall virtual ~TLocalConnection(void);
	__property Midas::_di_IAppServer AppServer = {read=FAppServer};
	virtual Midas::_di_IAppServer __fastcall GetServer();
	__property Provider::TCustomProvider* Providers[AnsiString ProviderName] = {read=GetProvider};
	__property int ProviderCount = {read=GetProviderCount, nodefault};
private:
	void *__IAppServer;	/* Midas::IAppServer */
	
public:
	operator IAppServer*(void) { return (IAppServer*)&__IAppServer; }
	
};


class DELPHICLASS TDispatchConnection;
class PASCALIMPLEMENTATION TDispatchConnection : public Dbclient::TCustomRemoteServer 
{
	typedef Dbclient::TCustomRemoteServer inherited;
	
private:
	#pragma pack(push, 1)
	GUID FServerGUID;
	#pragma pack(pop)
	
	AnsiString FServerName;
	TCustomObjectBroker* FObjectBroker;
	AnsiString __fastcall GetServerGUID();
	void __fastcall SetServerGUID(const AnsiString Value);
	void __fastcall SetServerName(const AnsiString Value);
	void __fastcall SetObjectBroker(TCustomObjectBroker* Value);
	
protected:
	virtual OleVariant __fastcall GetServerList();
	virtual void __fastcall DoDisconnect(void);
	virtual bool __fastcall GetConnected(void);
	virtual void __fastcall SetConnected(bool Value);
	GUID __fastcall GetServerCLSID();
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	__property TCustomObjectBroker* ObjectBroker = {read=FObjectBroker, write=SetObjectBroker};
	
public:
	__fastcall virtual TDispatchConnection(Classes::TComponent* AOwner);
	virtual Midas::_di_IAppServer __fastcall GetServer();
	
__published:
	__property Connected  = {default=0};
	__property LoginPrompt  = {default=0};
	__property AnsiString ServerGUID = {read=GetServerGUID, write=SetServerGUID};
	__property AnsiString ServerName = {read=FServerName, write=SetServerName};
	__property AfterConnect ;
	__property AfterDisconnect ;
	__property BeforeConnect ;
	__property BeforeDisconnect ;
	__property OnGetUsername ;
	__property OnLogin ;
public:
	#pragma option push -w-inl
	/* TCustomConnection.Destroy */ inline __fastcall virtual ~TDispatchConnection(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCOMConnection;
class PASCALIMPLEMENTATION TCOMConnection : public TDispatchConnection 
{
	typedef TDispatchConnection inherited;
	
protected:
	virtual void __fastcall SetConnected(bool Value);
	virtual void __fastcall DoConnect(void);
public:
	#pragma option push -w-inl
	/* TDispatchConnection.Create */ inline __fastcall virtual TCOMConnection(Classes::TComponent* AOwner) : TDispatchConnection(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomConnection.Destroy */ inline __fastcall virtual ~TCOMConnection(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDCOMConnection;
class PASCALIMPLEMENTATION TDCOMConnection : public TCOMConnection 
{
	typedef TCOMConnection inherited;
	
private:
	AnsiString FComputerName;
	void __fastcall SetComputerName(const AnsiString Value);
	bool __fastcall IsComputerNameStored(void);
	
protected:
	virtual void __fastcall DoConnect(void);
	
public:
	__fastcall virtual TDCOMConnection(Classes::TComponent* AOwner);
	
__published:
	__property AnsiString ComputerName = {read=FComputerName, write=SetComputerName, stored=IsComputerNameStored};
	__property ObjectBroker ;
public:
	#pragma option push -w-inl
	/* TCustomConnection.Destroy */ inline __fastcall virtual ~TDCOMConnection(void) { }
	#pragma option pop
	
};


class DELPHICLASS TOLEnterpriseConnection;
class PASCALIMPLEMENTATION TOLEnterpriseConnection : public TCOMConnection 
{
	typedef TCOMConnection inherited;
	
private:
	AnsiString FComputerName;
	AnsiString FBrokerName;
	void __fastcall SetComputerName(const AnsiString Value);
	void __fastcall SetBrokerName(const AnsiString Value);
	
protected:
	virtual void __fastcall DoConnect(void);
	
__published:
	__property AnsiString ComputerName = {read=FComputerName, write=SetComputerName};
	__property AnsiString BrokerName = {read=FBrokerName, write=SetBrokerName};
public:
	#pragma option push -w-inl
	/* TDispatchConnection.Create */ inline __fastcall virtual TOLEnterpriseConnection(Classes::TComponent* AOwner) : TCOMConnection(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomConnection.Destroy */ inline __fastcall virtual ~TOLEnterpriseConnection(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSharedConnection;
class PASCALIMPLEMENTATION TSharedConnection : public Dbclient::TCustomRemoteServer 
{
	typedef Dbclient::TCustomRemoteServer inherited;
	
private:
	TDispatchConnection* FParentConnection;
	AnsiString FChildName;
	void __fastcall SetParentConnection(const TDispatchConnection* Value);
	
protected:
	void __fastcall ConnectEvent(System::TObject* Sender, bool Connecting);
	virtual void __fastcall DoConnect(void);
	virtual void __fastcall DoDisconnect(void);
	virtual bool __fastcall GetConnected(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	__fastcall virtual ~TSharedConnection(void);
	virtual Midas::_di_IAppServer __fastcall GetServer();
	
__published:
	__property TDispatchConnection* ParentConnection = {read=FParentConnection, write=SetParentConnection};
	__property AnsiString ChildName = {read=FChildName, write=FChildName};
	__property AfterConnect ;
	__property AfterDisconnect ;
	__property BeforeConnect ;
	__property BeforeDisconnect ;
public:
	#pragma option push -w-inl
	/* TCustomRemoteServer.Create */ inline __fastcall virtual TSharedConnection(Classes::TComponent* AOwner) : Dbclient::TCustomRemoteServer(AOwner) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall GetMIDASAppServerList(Classes::TStringList* List, const AnsiString RegCheck);

}	/* namespace Mconnect */
using namespace Mconnect;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// MConnect
