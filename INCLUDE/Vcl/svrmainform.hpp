// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SvrMainForm.pas' rev: 6.00

#ifndef SvrMainFormHPP
#define SvrMainFormHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SvrStatsFrame.hpp>	// Pascal unit
#include <SvrLogFrame.hpp>	// Pascal unit
#include <SvrLog.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Registry.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <SvrHTTP.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ActnList.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Svrmainform
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TWebAppDbgMainForm;
class PASCALIMPLEMENTATION TWebAppDbgMainForm : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* pbToggle;
	Actnlist::TActionList* ActionList1;
	Actnlist::TAction* ToggleServerAction;
	Menus::TMainMenu* MainMenu1;
	Menus::TMenuItem* PropertiesItem;
	Menus::TMenuItem* StartServer1;
	Menus::TMenuItem* StopServer1;
	Menus::TMenuItem* Properties1;
	Menus::TMenuItem* Exit1;
	Menus::TMenuItem* N1;
	Menus::TMenuItem* N2;
	Menus::TMenuItem* Help1;
	Menus::TMenuItem* About1;
	Actnlist::TAction* ExitAction;
	Actnlist::TAction* StopAction;
	Actnlist::TAction* StartAction;
	Actnlist::TAction* AboutAction;
	Actnlist::TAction* PropertiesAction;
	Actnlist::TAction* BrowseAction;
	Menus::TPopupMenu* PopupMenu1;
	Menus::TMenuItem* Properties2;
	Menus::TMenuItem* StartServer2;
	Menus::TMenuItem* StopServer2;
	Menus::TMenuItem* Exit2;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Home;
	Actnlist::TAction* MainUpdateAction;
	Actnlist::TAction* ClearAction;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Port;
	Stdctrls::TGroupBox* GroupBox1;
	Svrlogframe::TLogFrame* LogFrame;
	Actnlist::TAction* ToggleLogAction;
	Stdctrls::TCheckBox* CheckBox1;
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabSheet1;
	Comctrls::TTabSheet* TabSheet2;
	Svrstatsframe::TStatsFrame* StatsFrame;
	void __fastcall ToggleServerActionExecute(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall ToggleServerActionUpdate(System::TObject* Sender);
	void __fastcall StopActionExecute(System::TObject* Sender);
	void __fastcall StopActionUpdate(System::TObject* Sender);
	void __fastcall StartActionExecute(System::TObject* Sender);
	void __fastcall StartActionUpdate(System::TObject* Sender);
	void __fastcall PropertiesActionExecute(System::TObject* Sender);
	void __fastcall ExitActionExecute(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall HomeClick(System::TObject* Sender);
	void __fastcall HideActionExecute(System::TObject* Sender);
	void __fastcall SysTray1DblClick(System::TObject* Sender);
	void __fastcall FormClose(System::TObject* Sender, Forms::TCloseAction &Action);
	void __fastcall MainUpdateActionExecute(System::TObject* Sender);
	void __fastcall MainUpdateActionUpdate(System::TObject* Sender);
	void __fastcall ToggleLogActionExecute(System::TObject* Sender);
	void __fastcall ToggleLogActionUpdate(System::TObject* Sender);
	void __fastcall AboutActionExecute(System::TObject* Sender);
	
private:
	bool FShowAtStartup;
	bool FActiveAtStartup;
	bool FHideOnClose;
	Svrhttp::TCustomWebServer* FWebServer;
	bool FLogOn;
	AnsiString __fastcall GetSearchPath();
	bool __fastcall GetServerActive(void);
	int __fastcall GetServerPort(void);
	void __fastcall SetSearchPath(const AnsiString Value);
	void __fastcall SetServerActive(const bool Value);
	void __fastcall SetServerPort(const int Value);
	AnsiString __fastcall GetDefaultURL();
	void __fastcall SetDefaultURL(const AnsiString Value);
	Registry::TRegIniFile* __fastcall CreateRegistry(void);
	void __fastcall Load(Registry::TRegIniFile* Reg);
	void __fastcall Save(Registry::TRegIniFile* Reg);
	AnsiString __fastcall GetTranslatedDefaultURL();
	void __fastcall OnLog(System::TObject* Sender, Svrlog::TTransactionLogEntry* Transaction, bool &Release);
	int __fastcall GetLogMax(void);
	void __fastcall SetLogMax(const int Value);
	int __fastcall GetLogDelete(void);
	void __fastcall SetLogDelete(const int Value);
	__property bool ServerActive = {read=GetServerActive, write=SetServerActive, nodefault};
	__property AnsiString ServerSearchPath = {read=GetSearchPath, write=SetSearchPath};
	__property int ServerPort = {read=GetServerPort, write=SetServerPort, nodefault};
	__property AnsiString DefaultURL = {read=GetDefaultURL, write=SetDefaultURL};
	__property AnsiString TranslatedDefaultURL = {read=GetTranslatedDefaultURL};
	__property int LogMax = {read=GetLogMax, write=SetLogMax, nodefault};
	__property int LogDelete = {read=GetLogDelete, write=SetLogDelete, nodefault};
	__property bool ShowAtStartup = {read=FShowAtStartup, write=FShowAtStartup, nodefault};
	__property bool ActiveAtStartup = {read=FActiveAtStartup, write=FActiveAtStartup, nodefault};
	__property bool HideOnClose = {read=FHideOnClose, write=FHideOnClose, nodefault};
	__property bool LogOn = {read=FLogOn, write=FLogOn, nodefault};
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TWebAppDbgMainForm(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TWebAppDbgMainForm(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TWebAppDbgMainForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TWebAppDbgMainForm(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TWebAppDbgMainForm* WebAppDbgMainForm;

}	/* namespace Svrmainform */
using namespace Svrmainform;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SvrMainForm
