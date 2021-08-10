// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ScktMain.pas' rev: 5.00

#ifndef ScktMainHPP
#define ScktMainHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ActnList.hpp>	// Pascal unit
#include <Registry.hpp>	// Pascal unit
#include <ScktComp.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <ShellAPI.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SvcMgr.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Scktmain
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TSocketProc)(Comctrls::TListItem* Item, Scktcomp::TCustomWinSocket* 
	Socket);

class DELPHICLASS TSocketForm;
class PASCALIMPLEMENTATION TSocketForm : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Menus::TPopupMenu* PopupMenu;
	Menus::TMenuItem* miClose;
	Menus::TMenuItem* N1;
	Menus::TMenuItem* miProperties;
	Extctrls::TTimer* UpdateTimer;
	Menus::TMainMenu* MainMenu1;
	Menus::TMenuItem* miPorts;
	Menus::TMenuItem* miAdd;
	Menus::TMenuItem* miRemove;
	Comctrls::TPageControl* Pages;
	Comctrls::TTabSheet* PropPage;
	Stdctrls::TGroupBox* PortGroup;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* PortDesc;
	Stdctrls::TEdit* PortNo;
	Comctrls::TUpDown* PortUpDown;
	Stdctrls::TGroupBox* ThreadGroup;
	Stdctrls::TLabel* Label4;
	Stdctrls::TLabel* ThreadDesc;
	Stdctrls::TEdit* ThreadSize;
	Comctrls::TUpDown* ThreadUpDown;
	Stdctrls::TGroupBox* InterceptGroup;
	Stdctrls::TLabel* Label5;
	Stdctrls::TLabel* GUIDDesc;
	Comctrls::TTabSheet* StatPage;
	Comctrls::TListView* ConnectionList;
	Menus::TMenuItem* Connections1;
	Menus::TMenuItem* miShowHostName;
	Menus::TMenuItem* miDisconnect;
	Menus::TMenuItem* N2;
	Stdctrls::TGroupBox* TimeoutGroup;
	Stdctrls::TLabel* Label7;
	Stdctrls::TEdit* Timeout;
	Comctrls::TUpDown* TimeoutUpDown;
	Stdctrls::TLabel* TimeoutDesc;
	Stdctrls::TEdit* InterceptGUID;
	Stdctrls::TButton* ApplyButton;
	Actnlist::TActionList* ActionList1;
	Actnlist::TAction* ApplyAction;
	Actnlist::TAction* DisconnectAction;
	Actnlist::TAction* ShowHostAction;
	Actnlist::TAction* RemovePortAction;
	Menus::TMenuItem* N3;
	Menus::TMenuItem* miExit;
	Extctrls::TPanel* Panel1;
	Stdctrls::TListBox* PortList;
	Comctrls::THeaderControl* HeaderControl1;
	Comctrls::TStatusBar* UserStatus;
	Menus::TMenuItem* ExportedObjectOnly1;
	Actnlist::TAction* RegisteredAction;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall miCloseClick(System::TObject* Sender);
	void __fastcall miPropertiesClick(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall FormCloseQuery(System::TObject* Sender, bool &CanClose);
	void __fastcall miDisconnectClick(System::TObject* Sender);
	void __fastcall miExitClick(System::TObject* Sender);
	void __fastcall ApplyActionExecute(System::TObject* Sender);
	void __fastcall ApplyActionUpdate(System::TObject* Sender);
	void __fastcall DisconnectActionUpdate(System::TObject* Sender);
	void __fastcall ShowHostActionExecute(System::TObject* Sender);
	void __fastcall miAddClick(System::TObject* Sender);
	void __fastcall RemovePortActionUpdate(System::TObject* Sender);
	void __fastcall RemovePortActionExecute(System::TObject* Sender);
	void __fastcall UpDownClick(System::TObject* Sender, Comctrls::TUDBtnType Button);
	void __fastcall PortListClick(System::TObject* Sender);
	void __fastcall ConnectionListCompare(System::TObject* Sender, Comctrls::TListItem* Item1, Comctrls::TListItem* 
		Item2, int Data, int &Compare);
	void __fastcall ConnectionListColumnClick(System::TObject* Sender, Comctrls::TListColumn* Column);
	void __fastcall IntegerExit(System::TObject* Sender);
	void __fastcall UpdateTimerTimer(System::TObject* Sender);
	void __fastcall RegisteredActionExecute(System::TObject* Sender);
	
private:
	unsigned FTaskMessage;
	_NOTIFYICONDATAA FIconData;
	bool FClosing;
	bool FProgmanOpen;
	bool FFromService;
	bool NT351;
	int FCurItem;
	int FSortCol;
	void __fastcall UpdateStatus(void);
	Scktcomp::TServerSocket* __fastcall GetSelectedSocket(void);
	int __fastcall GetItemIndex(void);
	void __fastcall SetItemIndex(int Value);
	void __fastcall CheckValues(void);
	
protected:
	void __fastcall AddClient(Scktcomp::TServerClientThread* Thread);
	void __fastcall RemoveClient(Scktcomp::TServerClientThread* Thread);
	void __fastcall ClearModifications(void);
	MESSAGE void __fastcall UIInitialize(Messages::TMessage &Message);
	MESSAGE void __fastcall WMMIDASIcon(Messages::TMessage &Message);
	void __fastcall AddIcon(void);
	void __fastcall ReadSettings(void);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	void __fastcall WriteSettings(void);
	
public:
	void __fastcall Initialize(bool FromService);
	__property Scktcomp::TServerSocket* SelectedSocket = {read=GetSelectedSocket};
	__property int ItemIndex = {read=GetItemIndex, write=SetItemIndex, nodefault};
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TSocketForm(Classes::TComponent* AOwner) : Forms::TForm(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TSocketForm(Classes::TComponent* AOwner, int 
		Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TSocketForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TSocketForm(HWND ParentWindow) : Forms::TForm(ParentWindow
		) { }
	#pragma option pop
	
};


class DELPHICLASS TSocketService;
class PASCALIMPLEMENTATION TSocketService : public Svcmgr::TService 
{
	typedef Svcmgr::TService inherited;
	
protected:
	void __fastcall Start(Svcmgr::TService* Sender, bool &Started);
	void __fastcall Stop(Svcmgr::TService* Sender, bool &Stopped);
	
public:
	virtual Svcmgr::TServiceController __fastcall GetServiceController(void);
	__fastcall virtual TSocketService(Classes::TComponent* AOwner, int Dummy);
public:
	#pragma option push -w-inl
	/* TService.Destroy */ inline __fastcall virtual ~TSocketService(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TDataModule.Create */ inline __fastcall virtual TSocketService(Classes::TComponent* AOwner) : Svcmgr::TService(
		AOwner) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Word WM_MIDASICON = 0x401;
static const Word UI_INITIALIZE = 0x402;
extern PACKAGE TSocketForm* SocketForm;
extern PACKAGE TSocketService* SocketService;

}	/* namespace Scktmain */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Scktmain;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ScktMain
