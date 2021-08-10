// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'CtlPanel.pas' rev: 5.00

#ifndef CtlPanelHPP
#define CtlPanelHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Dialogs.hpp>	// Pascal unit
#include <CPL.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ctlpanel
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EAppletException;
class PASCALIMPLEMENTATION EAppletException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EAppletException(const AnsiString Msg) : Sysutils::Exception(
		Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EAppletException(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EAppletException(int Ident)/* overload */ : Sysutils::Exception(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EAppletException(int Ident, const System::TVarRec * 
		Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EAppletException(const AnsiString Msg, int AHelpContext
		) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EAppletException(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EAppletException(int Ident, int AHelpContext)/* overload */
		 : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EAppletException(System::PResStringRec ResStringRec
		, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EAppletException(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TInitEvent)(System::TObject* Sender, bool &AppInitOK);

typedef void __fastcall (__closure *TCountEvent)(System::TObject* Sender, int &AppCount);

typedef void __fastcall (__closure *TExitEvent)(System::TObject* Sender);

typedef void __fastcall (__closure *TSetupEvent)(System::TObject* Sender);

typedef void __fastcall (__closure *TActivateEvent)(System::TObject* Sender, int Data);

typedef void __fastcall (__closure *TStopEvent)(System::TObject* Sender, int Data);

typedef void __fastcall (__closure *TInquireEvent)(System::TObject* Sender, int &idIcon, int &idName
	, int &idInfo, int &lData);

typedef void __fastcall (__closure *TNewInquireEvent)(System::TObject* Sender, int &lData, HICON &hIcon
	, AnsiString &AppletName, AnsiString &AppletInfo);

typedef void __fastcall (__closure *TStartWParmsEvent)(System::TObject* Sender, AnsiString Params);

class DELPHICLASS TAppletModule;
class PASCALIMPLEMENTATION TAppletModule : public Forms::TDataModule 
{
	typedef Forms::TDataModule inherited;
	
private:
	TActivateEvent FOnActivate;
	TStopEvent FOnStop;
	TInquireEvent FOnInquire;
	TNewInquireEvent FOnNewInquire;
	TStartWParmsEvent FOnStartWParms;
	int FData;
	int FResidIcon;
	int FResidName;
	int FResidInfo;
	Graphics::TIcon* FAppletIcon;
	AnsiString FCaption;
	AnsiString FHelp;
	void __fastcall SetData(const int Value);
	void __fastcall SetResidIcon(const int Value);
	void __fastcall SetResidInfo(const int Value);
	void __fastcall SetResidName(const int Value);
	void __fastcall SetAppletIcon(const Graphics::TIcon* Value);
	void __fastcall SetCaption(const AnsiString Value);
	void __fastcall SetHelp(const AnsiString Value);
	AnsiString __fastcall GetCaption();
	
protected:
	DYNAMIC void __fastcall DoStop(int Data);
	DYNAMIC void __fastcall DoActivate(int Data);
	DYNAMIC void __fastcall DoInquire(tagCPLINFO &ACPLInfo);
	DYNAMIC void __fastcall DoNewInquire(tagNEWCPLINFOA &ANewCPLInfo);
	DYNAMIC void __fastcall DoStartWParms(AnsiString Params);
	
public:
	__fastcall virtual TAppletModule(Classes::TComponent* AOwner);
	__fastcall virtual ~TAppletModule(void);
	__property int Data = {read=FData, write=SetData, nodefault};
	
__published:
	__property TStopEvent OnStop = {read=FOnStop, write=FOnStop};
	__property TActivateEvent OnActivate = {read=FOnActivate, write=FOnActivate};
	__property TInquireEvent OnInquire = {read=FOnInquire, write=FOnInquire};
	__property TNewInquireEvent OnNewInquire = {read=FOnNewInquire, write=FOnNewInquire};
	__property TStartWParmsEvent OnStartWParms = {read=FOnStartWParms, write=FOnStartWParms};
	__property AnsiString Caption = {read=GetCaption, write=SetCaption};
	__property Graphics::TIcon* AppletIcon = {read=FAppletIcon, write=SetAppletIcon};
	__property AnsiString Help = {read=FHelp, write=SetHelp};
	__property int ResidIcon = {read=FResidIcon, write=SetResidIcon, nodefault};
	__property int ResidName = {read=FResidName, write=SetResidName, nodefault};
	__property int ResidInfo = {read=FResidInfo, write=SetResidInfo, nodefault};
public:
	#pragma option push -w-inl
	/* TDataModule.CreateNew */ inline __fastcall virtual TAppletModule(Classes::TComponent* AOwner, int 
		Dummy) : Forms::TDataModule(AOwner, Dummy) { }
	#pragma option pop
	
};


typedef TMetaClass*TAppletModuleClass;

typedef TMetaClass*TCPLAppletClass;

typedef TMetaClass*TDataModuleClass;

class DELPHICLASS TAppletApplication;
class PASCALIMPLEMENTATION TAppletApplication : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	TMetaClass*FComponentClass;
	unsigned FControlPanelHandle;
	Classes::TList* FModules;
	TInitEvent FOnInit;
	TCountEvent FOnCount;
	Classes::TNotifyEvent FOnExit;
	Classes::TNotifyEvent FOnSetup;
	int FModuleCount;
	void __fastcall OnExceptionHandler(System::TObject* Sender, Sysutils::Exception* E);
	TAppletModule* __fastcall GetModules(int Index);
	void __fastcall SetModules(int Index, const TAppletModule* Value);
	void __fastcall SetModuleCount(const int Value);
	int __fastcall GetModuleCount(void);
	
protected:
	DYNAMIC void __fastcall DoHandleException(Sysutils::Exception* E);
	DYNAMIC void __fastcall DoInit(bool &AppInitOK);
	DYNAMIC void __fastcall DoCount(int &AppCount);
	DYNAMIC void __fastcall DoExit(void);
	DYNAMIC void __fastcall DoSetup(void);
	
public:
	__fastcall virtual TAppletApplication(Classes::TComponent* AOwner);
	__fastcall virtual ~TAppletApplication(void);
	virtual void __fastcall CreateForm(TMetaClass* InstanceClass, void *Reference);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall Run(void);
	__property TAppletModule* Modules[int Index] = {read=GetModules, write=SetModules};
	__property int ModuleCount = {read=GetModuleCount, write=SetModuleCount, nodefault};
	__property unsigned ControlPanelHandle = {read=FControlPanelHandle, nodefault};
	__property TInitEvent OnInit = {read=FOnInit, write=FOnInit};
	__property TCountEvent OnCount = {read=FOnCount, write=FOnCount};
	__property Classes::TNotifyEvent OnExit = {read=FOnExit, write=FOnExit};
	__property Classes::TNotifyEvent OnSetup = {read=FOnSetup, write=FOnSetup};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TAppletApplication* Application;
extern PACKAGE int __stdcall CPlApplet(unsigned hwndCPl, unsigned uMsg, int lParam1, int lParam2);

}	/* namespace Ctlpanel */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Ctlpanel;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CtlPanel
