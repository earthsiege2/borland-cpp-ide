// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WebFact.pas' rev: 6.00

#ifndef WebFactHPP
#define WebFactHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Webfact
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TBaseWebModuleFactory;
class PASCALIMPLEMENTATION TBaseWebModuleFactory : public Httpapp::TAbstractWebModuleFactory 
{
	typedef Httpapp::TAbstractWebModuleFactory inherited;
	
private:
	TMetaClass*FComponentClass;
	Httpapp::TWebModuleCacheMode FCacheMode;
	Httpapp::TWebModuleCreateMode FCreateMode;
	
protected:
	virtual AnsiString __fastcall GetModuleName();
	virtual bool __fastcall GetIsAppModule(void);
	virtual Httpapp::TWebModuleCreateMode __fastcall GetCreateMode(void);
	virtual Httpapp::TWebModuleCacheMode __fastcall GetCacheMode(void);
	virtual TMetaClass* __fastcall GetComponentClass(void);
	__fastcall TBaseWebModuleFactory(TMetaClass* AComponentClass, Httpapp::TWebModuleCreateMode ACreateMode, Httpapp::TWebModuleCacheMode ACacheMode);
	
public:
	virtual void __fastcall PreventDestruction(void);
	virtual Classes::TComponent* __fastcall GetModule(void);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TBaseWebModuleFactory(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TWebPageAccessFlags { wpPublished, wpLoginRequired };
#pragma option pop

typedef Set<TWebPageAccessFlags, wpPublished, wpLoginRequired>  TWebPageAccess;

class DELPHICLASS TBaseWebPageInfo;
class PASCALIMPLEMENTATION TBaseWebPageInfo : public Httpapp::TAbstractWebPageInfo 
{
	typedef Httpapp::TAbstractWebPageInfo inherited;
	
private:
	AnsiString FFile;
	AnsiString FName;
	TWebPageAccess FAccess;
	AnsiString FDescription;
	AnsiString FTitle;
	AnsiString FViewAccess;
	
protected:
	__fastcall TBaseWebPageInfo(TWebPageAccess AAccess, const AnsiString AFile, const AnsiString AName, const AnsiString ATitle, const AnsiString ADescription, const AnsiString AViewAccess);
	virtual AnsiString __fastcall GetPageFile();
	virtual AnsiString __fastcall GetPageHREF();
	virtual AnsiString __fastcall GetPageName();
	virtual bool __fastcall GetIsPublished(void);
	virtual bool __fastcall GetIsLoginRequired(void);
	virtual AnsiString __fastcall GetPageDescription();
	virtual AnsiString __fastcall GetPageTitle();
	virtual AnsiString __fastcall GetViewAccess();
	virtual void __fastcall SetFactory(Httpapp::TAbstractWebPageModuleFactory* AFactory);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TBaseWebPageInfo(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWebPageInfo;
class PASCALIMPLEMENTATION TWebPageInfo : public TBaseWebPageInfo 
{
	typedef TBaseWebPageInfo inherited;
	
public:
	__fastcall TWebPageInfo(TWebPageAccess AAccess, const AnsiString APageFile, const AnsiString APageName, const AnsiString ACaption, const AnsiString ADescription, const AnsiString AViewAccess);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TWebPageInfo(void) { }
	#pragma option pop
	
};


class DELPHICLASS TBaseWebPageModuleFactory;
class PASCALIMPLEMENTATION TBaseWebPageModuleFactory : public Httpapp::TAbstractWebPageModuleFactory 
{
	typedef Httpapp::TAbstractWebPageModuleFactory inherited;
	
private:
	TMetaClass*FComponentClass;
	Httpapp::TWebModuleCacheMode FCacheMode;
	Httpapp::TWebModuleCreateMode FCreateMode;
	
protected:
	__fastcall TBaseWebPageModuleFactory(TMetaClass* AComponentClass, Httpapp::TAbstractWebPageInfo* AWebPageInfo, Httpapp::TWebModuleCreateMode ACreateMode, Httpapp::TWebModuleCacheMode ACacheMode);
	virtual AnsiString __fastcall GetModuleName();
	virtual bool __fastcall GetIsAppModule(void);
	virtual Httpapp::TWebModuleCreateMode __fastcall GetCreateMode(void);
	virtual Httpapp::TWebModuleCacheMode __fastcall GetCacheMode(void);
	virtual TMetaClass* __fastcall GetComponentClass(void);
	
public:
	virtual void __fastcall PreventDestruction(void);
	virtual Classes::TComponent* __fastcall GetModule(void);
public:
	#pragma option push -w-inl
	/* TAbstractWebPageModuleFactory.Destroy */ inline __fastcall virtual ~TBaseWebPageModuleFactory(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWebPageModuleFactory;
class PASCALIMPLEMENTATION TWebPageModuleFactory : public TBaseWebPageModuleFactory 
{
	typedef TBaseWebPageModuleFactory inherited;
	
public:
	__fastcall TWebPageModuleFactory(TMetaClass* AComponentClass, Httpapp::TAbstractWebPageInfo* AWebPageInfo, Httpapp::TWebModuleCreateMode ACreateMode, Httpapp::TWebModuleCacheMode ACacheMode);
public:
	#pragma option push -w-inl
	/* TAbstractWebPageModuleFactory.Destroy */ inline __fastcall virtual ~TWebPageModuleFactory(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWebDataModuleFactory;
class PASCALIMPLEMENTATION TWebDataModuleFactory : public TBaseWebModuleFactory 
{
	typedef TBaseWebModuleFactory inherited;
	
public:
	__fastcall TWebDataModuleFactory(TMetaClass* AComponentClass, Httpapp::TWebModuleCreateMode ACreateMode, Httpapp::TWebModuleCacheMode ACacheMode);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TWebDataModuleFactory(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWebAppDataModuleFactory;
class PASCALIMPLEMENTATION TWebAppDataModuleFactory : public TBaseWebModuleFactory 
{
	typedef TBaseWebModuleFactory inherited;
	
protected:
	virtual bool __fastcall GetIsAppModule(void);
	
public:
	__fastcall TWebAppDataModuleFactory(TMetaClass* AComponentClass, Httpapp::TWebModuleCacheMode ACacheMode);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TWebAppDataModuleFactory(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWebAppPageModuleFactory;
class PASCALIMPLEMENTATION TWebAppPageModuleFactory : public TBaseWebPageModuleFactory 
{
	typedef TBaseWebPageModuleFactory inherited;
	
protected:
	virtual bool __fastcall GetIsAppModule(void);
	
public:
	__fastcall TWebAppPageModuleFactory(TMetaClass* AComponentClass, Httpapp::TAbstractWebPageInfo* AWebPageInfo, Httpapp::TWebModuleCacheMode ACacheMode);
public:
	#pragma option push -w-inl
	/* TAbstractWebPageModuleFactory.Destroy */ inline __fastcall virtual ~TWebAppPageModuleFactory(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Webfact */
using namespace Webfact;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WebFact
