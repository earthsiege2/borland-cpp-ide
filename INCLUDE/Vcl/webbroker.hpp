// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WebBroker.pas' rev: 5.00

#ifndef WebBrokerHPP
#define WebBrokerHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Contnrs.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Masks.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SyncObjs.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Webbroker
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TWebApplication;
class PASCALIMPLEMENTATION TWebApplication : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	TMetaClass*FWebModuleClass;
	Syncobjs::TCriticalSection* FCriticalSection;
	Classes::TList* FActiveWebModules;
	Classes::TList* FInactiveWebModules;
	AnsiString FTitle;
	int FMaxConnections;
	bool FCacheConnections;
	int __fastcall GetActiveCount(void);
	int __fastcall GetInactiveCount(void);
	void __fastcall SetCacheConnections(bool Value);
	void __fastcall OnExceptionHandler(System::TObject* Sender, Sysutils::Exception* E);
	
protected:
	Forms::TDataModule* __fastcall ActivateWebModule(void);
	void __fastcall DeactivateWebModule(Forms::TDataModule* DataModule);
	DYNAMIC void __fastcall DoHandleException(Sysutils::Exception* E);
	bool __fastcall HandleRequest(Httpapp::TWebRequest* Request, Httpapp::TWebResponse* Response);
	
public:
	__fastcall virtual TWebApplication(Classes::TComponent* AOwner);
	__fastcall virtual ~TWebApplication(void);
	virtual void __fastcall CreateForm(TMetaClass* InstanceClass, void *Reference);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall Run(void);
	__property int ActiveCount = {read=GetActiveCount, nodefault};
	__property bool CacheConnections = {read=FCacheConnections, write=SetCacheConnections, nodefault};
	__property int InactiveCount = {read=GetInactiveCount, nodefault};
	__property int MaxConnections = {read=FMaxConnections, write=FMaxConnections, nodefault};
	__property AnsiString Title = {read=FTitle, write=FTitle};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TWebApplication* Application;

}	/* namespace Webbroker */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Webbroker;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WebBroker
