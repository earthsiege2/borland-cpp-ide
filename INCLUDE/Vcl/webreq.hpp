// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WebReq.pas' rev: 6.00

#ifndef WebReqHPP
#define WebReqHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <WebCntxt.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SyncObjs.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Webreq
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TRequestNotification { rnActivateModule, rnDeactivateModule, rnCreateModule, rnFreeModule, rnStartRequest, rnFinishRequest };
#pragma option pop

class DELPHICLASS TWebModuleFactoryList;
class PASCALIMPLEMENTATION TWebModuleFactoryList : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Httpapp::TAbstractWebModuleFactory* FAppModuleFactory;
	Contnrs::TObjectList* FList;
	int __fastcall GetItemCount(void);
	
protected:
	Httpapp::TAbstractWebModuleFactory* __fastcall GetItem(int I);
	
public:
	__fastcall TWebModuleFactoryList(void);
	__fastcall virtual ~TWebModuleFactoryList(void);
	void __fastcall AddFactory(Httpapp::TAbstractWebModuleFactory* AFactory);
	__property Httpapp::TAbstractWebModuleFactory* AppModuleFactory = {read=FAppModuleFactory};
	__property Httpapp::TAbstractWebModuleFactory* Items[int I] = {read=GetItem};
	__property int ItemCount = {read=GetItemCount, nodefault};
};


class DELPHICLASS TWebRequestHandler;
class DELPHICLASS TWebModuleList;
class PASCALIMPLEMENTATION TWebRequestHandler : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Syncobjs::TCriticalSection* FCriticalSection;
	Classes::TList* FActiveWebModules;
	int FAddingActiveModules;
	Classes::TList* FInactiveWebModules;
	int FMaxConnections;
	bool FCacheConnections;
	TWebModuleFactoryList* FWebModuleFactories;
	TMetaClass*FWebModuleClass;
	Contnrs::TComponentList* FRequestNotifies;
	int __fastcall GetActiveCount(void);
	int __fastcall GetInactiveCount(void);
	void __fastcall SetCacheConnections(bool Value);
	Httpapp::TAbstractWebModuleFactory* __fastcall GetWebModuleFactory(int I);
	int __fastcall GetWebModuleFactoryCount(void);
	
protected:
	TWebModuleList* __fastcall ActivateWebModules(void);
	void __fastcall DeactivateWebModules(TWebModuleList* WebModules);
	bool __fastcall HandleRequest(Httpapp::TWebRequest* Request, Httpapp::TWebResponse* Response);
	
public:
	__fastcall virtual TWebRequestHandler(Classes::TComponent* AOwner);
	__fastcall virtual ~TWebRequestHandler(void);
	void __fastcall HandleException(System::TObject* Sender);
	__property TMetaClass* WebModuleClass = {read=FWebModuleClass, write=FWebModuleClass};
	void __fastcall AddWebModuleFactory(Httpapp::TAbstractWebModuleFactory* AFactory);
	__property int ActiveCount = {read=GetActiveCount, nodefault};
	__property bool CacheConnections = {read=FCacheConnections, write=SetCacheConnections, nodefault};
	__property int InactiveCount = {read=GetInactiveCount, nodefault};
	__property int MaxConnections = {read=FMaxConnections, write=FMaxConnections, nodefault};
	__property int WebModuleFactoryCount = {read=GetWebModuleFactoryCount, nodefault};
	__property Httpapp::TAbstractWebModuleFactory* WebModuleFactory[int I] = {read=GetWebModuleFactory};
};


class PASCALIMPLEMENTATION TWebModuleList : public Httpapp::TAbstractWebModuleList 
{
	typedef Httpapp::TAbstractWebModuleList inherited;
	
private:
	TWebModuleFactoryList* FFactories;
	Contnrs::TComponentList* FList;
	int FFixupLevel;
	Classes::TIsUniqueGlobalComponentName FSaveIsUniqueGlobalComponentName;
	Classes::TStrings* FUnresolvedNames;
	Httpapp::TModuleAddedProc FModuleAddedProc;
	void __fastcall EndFixup(void);
	void __fastcall StartFixup(void);
	void __fastcall RecordUnresolvedName(const AnsiString AName);
	void __fastcall PromoteFactoryClass(const AnsiString AName);
	
protected:
	virtual Classes::TComponent* __fastcall GetItem(int I);
	virtual int __fastcall GetItemCount(void);
	virtual Httpapp::TModuleAddedProc __fastcall GetOnModuleAdded();
	virtual int __fastcall GetFactoryCount(void);
	virtual Httpapp::TAbstractWebModuleFactory* __fastcall GetFactory(int I);
	virtual void __fastcall SetOnModuleAdded(Httpapp::TModuleAddedProc AProc);
	__property TWebModuleFactoryList* Factories = {read=FFactories};
	
public:
	__fastcall TWebModuleList(const TWebModuleFactoryList* AFactories);
	__fastcall virtual ~TWebModuleList(void);
	virtual Classes::TComponent* __fastcall FindModuleClass(TMetaClass* AClass);
	virtual Classes::TComponent* __fastcall FindModuleName(const AnsiString AName);
	virtual Classes::TComponent* __fastcall AddModuleClass(TMetaClass* AClass);
	virtual Classes::TComponent* __fastcall AddModuleName(const AnsiString AName);
	void __fastcall AddModule(Classes::TComponent* AComponent);
	void __fastcall AutoCreateModules(void);
	void __fastcall AutoDestroyModules(void);
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TWebRequestHandler* __fastcall (*WebRequestHandlerProc)(void);
extern PACKAGE TWebRequestHandler* __fastcall WebRequestHandler(void);

}	/* namespace Webreq */
using namespace Webreq;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WebReq
