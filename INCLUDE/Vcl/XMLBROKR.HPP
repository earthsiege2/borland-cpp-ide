// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'XMLBrokr.pas' rev: 5.00

#ifndef XMLBrokrHPP
#define XMLBrokrHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Midas.hpp>	// Pascal unit
#include <Masks.hpp>	// Pascal unit
#include <WebComp.hpp>	// Pascal unit
#include <Provider.hpp>	// Pascal unit
#include <DBClient.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Xmlbrokr
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TRequestRecordsEvent)(System::TObject* Sender, Httpapp::TWebRequest* 
	Request, /* out */ int &RecCount, OleVariant &OwnerData, AnsiString &Records);

typedef void __fastcall (__closure *TRequestUpdateEvent)(System::TObject* Sender, Httpapp::TWebRequest* 
	Request, Httpapp::TWebResponse* Response, bool &Handled);

typedef void __fastcall (__closure *TGetErrorResponseEvent)(System::TObject* Sender, int ErrorCount, 
	AnsiString XMLErrors, Httpapp::TWebRequest* Request, Httpapp::TWebResponse* Response, bool &Handled
	);

typedef void __fastcall (__closure *TGetResponseEvent)(System::TObject* Sender, Httpapp::TWebRequest* 
	Request, Httpapp::TWebResponse* Response, bool &Handled);

class DELPHICLASS TXMLParams;
class PASCALIMPLEMENTATION TXMLParams : public Db::TParams 
{
	typedef Db::TParams inherited;
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	
public:
	void __fastcall AssignStrings(Classes::TStrings* Value);
public:
	#pragma option push -w-inl
	/* TParams.Create */ inline __fastcall TXMLParams(Classes::TPersistent* Owner)/* overload */ : Db::TParams(
		Owner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TXMLParams(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TXMLOption { xoQuote };
#pragma option pop

typedef Set<TXMLOption, xoQuote, xoQuote>  TXMLOptions;

class DELPHICLASS TXMLBroker;
class DELPHICLASS TWebDispatch;
class DELPHICLASS TWebPathInfo;
class PASCALIMPLEMENTATION TWebPathInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Masks::TMask* FMask;
	AnsiString FMaskPathInfo;
	AnsiString FPathInfo;
	Classes::TComponent* FOwner;
	Masks::TMask* __fastcall GetMask(void);
	AnsiString __fastcall GetPathInfo();
	void __fastcall SetPathInfo(const AnsiString Value);
	
public:
	__fastcall TWebPathInfo(Classes::TComponent* AOwner);
	__fastcall virtual ~TWebPathInfo(void);
	__property Masks::TMask* Mask = {read=GetMask};
	__property AnsiString PathInfo = {read=GetPathInfo, write=SetPathInfo};
};


class PASCALIMPLEMENTATION TWebDispatch : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	TWebPathInfo* FPathInfo;
	Httpapp::TMethodType FMethodType;
	bool FEnabled;
	Masks::TMask* __fastcall GetMask(void);
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	void __fastcall SetPathInfo(const AnsiString Value);
	AnsiString __fastcall GetPathInfo();
	
public:
	__fastcall TWebDispatch(Classes::TComponent* AComponent);
	__fastcall virtual ~TWebDispatch(void);
	__property Masks::TMask* Mask = {read=GetMask};
	
__published:
	__property bool Enabled = {read=FEnabled, write=FEnabled, default=1};
	__property Httpapp::TMethodType MethodType = {read=FMethodType, write=FMethodType, default=3};
	__property AnsiString PathInfo = {read=GetPathInfo, write=SetPathInfo};
};


class PASCALIMPLEMENTATION TXMLBroker : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	TWebDispatch* FWebDispatch;
	Midas::_di_IAppServer FAppServer;
	AnsiString FProviderName;
	Dbclient::TCustomRemoteServer* FRemoteServer;
	TXMLParams* FParams;
	int FMaxRecords;
	TRequestRecordsEvent FRequestRecords;
	Httpapp::THTTPMethodEvent FBeforeDispatch;
	Httpapp::THTTPMethodEvent FAfterDispatch;
	TRequestUpdateEvent FRequestUpdate;
	int FMaxErrors;
	Httpapp::TCustomContentProducer* FReconcileProducer;
	TGetResponseEvent FGetResponse;
	TGetErrorResponseEvent FGetErrorResponse;
	AnsiString FErrors;
	int FErrorCount;
	Classes::TList* FNotify;
	
protected:
	void __fastcall AS_FetchParams(void);
	OleVariant __fastcall AS_GetRecords(int Count, /* out */ int &RecsOut, int Options, const WideString 
		CommandText, const OleVariant &Params, OleVariant &OwnerData);
	OleVariant __fastcall AS_ApplyUpdates(const OleVariant &Delta, int MaxErrors, /* out */ int &ErrorCount
		);
	bool __fastcall DispatchEnabled(void);
	Httpapp::TMethodType __fastcall DispatchMethodType(void);
	bool __fastcall DispatchRequest(System::TObject* Sender, Httpapp::TWebRequest* Request, Httpapp::TWebResponse* 
		Response);
	Masks::TMask* __fastcall DispatchMask(void);
	Classes::_di_IInterfaceList __fastcall DispatchSubItems();
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	void __fastcall SetWebDispatch(const TWebDispatch* Value);
	Midas::_di_IAppServer __fastcall GetAppServer();
	bool __fastcall GetHasAppServer(void);
	void __fastcall SetAppServer(Midas::_di_IAppServer Value);
	void __fastcall SetProviderName(const AnsiString Value);
	void __fastcall SetRemoteServer(Dbclient::TCustomRemoteServer* Value);
	bool __fastcall GetConnected(void);
	void __fastcall SetConnected(bool Value);
	void __fastcall CheckInactive(void);
	void __fastcall SetParams(const TXMLParams* Value);
	bool __fastcall GetErrorResponse(int ErrorCount, AnsiString XMLErrors, Httpapp::TWebRequest* Request
		, Httpapp::TWebResponse* Response);
	bool __fastcall GetResponse(Httpapp::TWebRequest* Request, Httpapp::TWebResponse* Response);
	AnsiString __fastcall GetProducerName(Httpapp::TWebRequest* Request);
	AnsiString __fastcall GetRedirect(Httpapp::TWebRequest* Request);
	void __fastcall SendConnectEvent(bool Connecting);
	System::TObject* __fastcall GetNotify(int Index);
	int __fastcall GetNotifyCount(void);
	void __fastcall SetReconcileProducer(const Httpapp::TCustomContentProducer* Value);
	
public:
	__fastcall virtual TXMLBroker(Classes::TComponent* AOwner);
	__fastcall virtual ~TXMLBroker(void);
	AnsiString __fastcall GetXMLRecords(int &RecsOut, OleVariant &OwnerData, TXMLOptions XMLOptions);
	AnsiString __fastcall ApplyXMLUpdates(const AnsiString Delta, /* out */ int &ErrorCount);
	AnsiString __fastcall GetDelta(Httpapp::TWebRequest* Request);
	AnsiString __fastcall GetErrors();
	int __fastcall GetErrorCount(void);
	AnsiString __fastcall HTMLSubmitFormName();
	AnsiString __fastcall SubmitFormVarName();
	AnsiString __fastcall RowSetVarName(Classes::TStrings* Path);
	AnsiString __fastcall MasterRowSetVarName(Classes::TStrings* Path);
	__property bool HasAppServer = {read=GetHasAppServer, nodefault};
	void __fastcall SetProvider(Classes::TComponent* Provider);
	__property Midas::_di_IAppServer AppServer = {read=GetAppServer, write=SetAppServer};
	virtual AnsiString __fastcall RequestRecords(System::TObject* Sender, Httpapp::TWebRequest* Request
		, /* out */ int &RecCount, OleVariant &OwnerData, TXMLOptions XMLOptions);
	virtual bool __fastcall RequestUpdate(System::TObject* Sender, Httpapp::TWebRequest* Request, Httpapp::TWebResponse* 
		Response);
	virtual void __fastcall FetchParams(void);
	void __fastcall AddNotify(System::TObject* ANotify);
	void __fastcall RemoveNotify(System::TObject* ANotify);
	__property System::TObject* Notify[int Index] = {read=GetNotify};
	__property int NotifyCount = {read=GetNotifyCount, nodefault};
	
__published:
	__property bool Connected = {read=GetConnected, write=SetConnected, stored=false, nodefault};
	__property int MaxRecords = {read=FMaxRecords, write=FMaxRecords, default=-1};
	__property int MaxErrors = {read=FMaxErrors, write=FMaxErrors, default=-1};
	__property TXMLParams* Params = {read=FParams, write=SetParams};
	__property AnsiString ProviderName = {read=FProviderName, write=SetProviderName};
	__property Dbclient::TCustomRemoteServer* RemoteServer = {read=FRemoteServer, write=SetRemoteServer
		};
	__property TWebDispatch* WebDispatch = {read=FWebDispatch, write=SetWebDispatch};
	__property TRequestRecordsEvent OnRequestRecords = {read=FRequestRecords, write=FRequestRecords};
	__property TRequestUpdateEvent OnRequestUpdate = {read=FRequestUpdate, write=FRequestUpdate};
	__property Httpapp::THTTPMethodEvent BeforeDispatch = {read=FBeforeDispatch, write=FBeforeDispatch}
		;
	__property Httpapp::THTTPMethodEvent AfterDispatch = {read=FAfterDispatch, write=FAfterDispatch};
	__property Httpapp::TCustomContentProducer* ReconcileProducer = {read=FReconcileProducer, write=SetReconcileProducer
		};
	__property TGetErrorResponseEvent OnGetErrorResponse = {read=FGetErrorResponse, write=FGetErrorResponse
		};
	__property TGetResponseEvent OnGetResponse = {read=FGetResponse, write=FGetResponse};
private:
	void *__IWebDispatch;	/* Httpapp::IWebDispatch */
	
public:
	operator IWebDispatch*(void) { return (IWebDispatch*)&__IWebDispatch; }
	
};


__interface INotifyConnectionChange;
typedef System::DelphiInterface<INotifyConnectionChange> _di_INotifyConnectionChange;
__interface INTERFACE_UUID("{0BC29A90-0EEC-11D3-AFED-00C04FB16EC3}") INotifyConnectionChange  : public IUnknown 
	
{
	
public:
	virtual void __fastcall ConnectionChange(Classes::TComponent* Sender, bool Connected) = 0 ;
};

//-- var, const, procedure ---------------------------------------------------
#define sProducer "PRODUCER"
#define sPostDelta "postdelta"
#define sRedirect "REDIRECT"
extern PACKAGE AnsiString __fastcall FormatXML(const AnsiString Value, TXMLOptions XMLOptions);

}	/* namespace Xmlbrokr */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Xmlbrokr;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// XMLBrokr
