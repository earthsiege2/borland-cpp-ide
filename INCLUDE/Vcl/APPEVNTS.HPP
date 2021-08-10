// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'AppEvnts.pas' rev: 6.00

#ifndef AppEvntsHPP
#define AppEvntsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ActnList.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Appevnts
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCustomApplicationEvents;
class PASCALIMPLEMENTATION TCustomApplicationEvents : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Actnlist::TActionEvent FOnActionExecute;
	Actnlist::TActionEvent FOnActionUpdate;
	Forms::TExceptionEvent FOnException;
	Forms::TMessageEvent FOnMessage;
	Forms::THelpEvent FOnHelp;
	Classes::TNotifyEvent FOnHint;
	Forms::TIdleEvent FOnIdle;
	Classes::TNotifyEvent FOnDeactivate;
	Classes::TNotifyEvent FOnActivate;
	Classes::TNotifyEvent FOnMinimize;
	Classes::TNotifyEvent FOnRestore;
	Forms::TShortCutEvent FOnShortCut;
	Forms::TShowHintEvent FOnShowHint;
	Forms::TSettingChangeEvent FOnSettingChange;
	void __fastcall DoActionExecute(Classes::TBasicAction* Action, bool &Handled);
	void __fastcall DoActionUpdate(Classes::TBasicAction* Action, bool &Handled);
	void __fastcall DoActivate(System::TObject* Sender);
	void __fastcall DoDeactivate(System::TObject* Sender);
	void __fastcall DoException(System::TObject* Sender, Sysutils::Exception* E);
	void __fastcall DoIdle(System::TObject* Sender, bool &Done);
	bool __fastcall DoHelp(Word Command, int Data, bool &CallHelp);
	void __fastcall DoHint(System::TObject* Sender);
	void __fastcall DoMessage(tagMSG &Msg, bool &Handled);
	void __fastcall DoMinimize(System::TObject* Sender);
	void __fastcall DoRestore(System::TObject* Sender);
	void __fastcall DoShowHint(AnsiString &HintStr, bool &CanShow, Forms::THintInfo &HintInfo);
	void __fastcall DoShortcut(Messages::TWMKey &Msg, bool &Handled);
	void __fastcall DoSettingChange(System::TObject* Sender, int Flag, const AnsiString Section, int &Result);
	
protected:
	__property Actnlist::TActionEvent OnActionExecute = {read=FOnActionExecute, write=FOnActionExecute};
	__property Actnlist::TActionEvent OnActionUpdate = {read=FOnActionUpdate, write=FOnActionUpdate};
	__property Classes::TNotifyEvent OnActivate = {read=FOnActivate, write=FOnActivate};
	__property Classes::TNotifyEvent OnDeactivate = {read=FOnDeactivate, write=FOnDeactivate};
	__property Forms::TExceptionEvent OnException = {read=FOnException, write=FOnException};
	__property Forms::TIdleEvent OnIdle = {read=FOnIdle, write=FOnIdle};
	__property Forms::THelpEvent OnHelp = {read=FOnHelp, write=FOnHelp};
	__property Classes::TNotifyEvent OnHint = {read=FOnHint, write=FOnHint};
	__property Forms::TMessageEvent OnMessage = {read=FOnMessage, write=FOnMessage};
	__property Classes::TNotifyEvent OnMinimize = {read=FOnMinimize, write=FOnMinimize};
	__property Classes::TNotifyEvent OnRestore = {read=FOnRestore, write=FOnRestore};
	__property Forms::TShowHintEvent OnShowHint = {read=FOnShowHint, write=FOnShowHint};
	__property Forms::TShortCutEvent OnShortCut = {read=FOnShortCut, write=FOnShortCut};
	__property Forms::TSettingChangeEvent OnSettingChange = {read=FOnSettingChange, write=FOnSettingChange};
	
public:
	__fastcall virtual TCustomApplicationEvents(Classes::TComponent* AOwner);
	void __fastcall Activate(void);
	void __fastcall CancelDispatch(void);
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TCustomApplicationEvents(void) { }
	#pragma option pop
	
};


class DELPHICLASS TApplicationEvents;
class PASCALIMPLEMENTATION TApplicationEvents : public TCustomApplicationEvents 
{
	typedef TCustomApplicationEvents inherited;
	
__published:
	__property OnActionExecute ;
	__property OnActionUpdate ;
	__property OnActivate ;
	__property OnDeactivate ;
	__property OnException ;
	__property OnIdle ;
	__property OnHelp ;
	__property OnHint ;
	__property OnMessage ;
	__property OnMinimize ;
	__property OnRestore ;
	__property OnShowHint ;
	__property OnShortCut ;
	__property OnSettingChange ;
public:
	#pragma option push -w-inl
	/* TCustomApplicationEvents.Create */ inline __fastcall virtual TApplicationEvents(Classes::TComponent* AOwner) : TCustomApplicationEvents(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TApplicationEvents(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Appevnts */
using namespace Appevnts;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// AppEvnts
