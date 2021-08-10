// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'CustomizeDlg.pas' rev: 6.00

#ifndef CustomizeDlgHPP
#define CustomizeDlgHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Buttons.hpp>	// Pascal unit
#include <ActnMenus.hpp>	// Pascal unit
#include <ActnCtrls.hpp>	// Pascal unit
#include <ActnMan.hpp>	// Pascal unit
#include <ImgList.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <CheckLst.hpp>	// Pascal unit
#include <ActnList.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#pragma link "dclact.lib"

namespace Customizedlg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCustomizeFrm;
class PASCALIMPLEMENTATION TCustomizeFrm : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* CloseBtn;
	Comctrls::TPageControl* Tabs;
	Comctrls::TTabSheet* ToolbarsTab;
	Comctrls::TTabSheet* ActionsTab;
	Comctrls::TTabSheet* OptionsTab;
	Stdctrls::TLabel* ToolbarsLbl;
	Checklst::TCheckListBox* ActionBarList;
	Stdctrls::TButton* ResetBtn;
	Menus::TPopupMenu* CloseMenu;
	Menus::TMenuItem* CloseItem;
	Stdctrls::TLabel* PersonalizeLbl;
	Extctrls::TBevel* OptionsBevel2;
	Stdctrls::TCheckBox* RecentlyUsedChk;
	Stdctrls::TButton* ResetUsageBtn;
	Stdctrls::TCheckBox* LargeIconsChk;
	Stdctrls::TCheckBox* ShowTipsChk;
	Stdctrls::TCheckBox* ShortCutTipsChk;
	Extctrls::TBevel* OptionsBevel1;
	Stdctrls::TLabel* OtherLbl;
	Controls::TImageList* ActionImages;
	Stdctrls::TLabel* Label1;
	Stdctrls::TComboBox* MenuAnimationStyles;
	Stdctrls::TLabel* InfoLbl;
	Stdctrls::TGroupBox* DescGroupBox;
	Stdctrls::TLabel* HintLbl;
	Stdctrls::TLabel* ActionsCatLbl;
	Stdctrls::TListBox* CatList;
	Stdctrls::TListBox* ActionsList;
	Stdctrls::TLabel* ActionsActionsLbl;
	Actnlist::TActionList* ActionList1;
	Actnlist::TAction* ResetActn;
	Actnlist::TAction* CloseActn;
	Actnlist::TAction* ResetUsageDataActn;
	Actnlist::TAction* RecentlyUsedActn;
	Actnlist::TAction* FullMenusActn;
	Actnlist::TAction* ShowHintsActn;
	Actnlist::TAction* ShowShortCutsInTipsActn;
	Extctrls::TPanel* ListPanel;
	Extctrls::TPanel* ComboPanel;
	Stdctrls::TComboBox* ListCombo;
	Actnlist::TAction* ApplyToAllActn;
	Stdctrls::TGroupBox* CaptionOptionsGrp;
	Stdctrls::TCheckBox* ApplyToAllChk;
	Stdctrls::TLabel* Label4;
	Actnlist::TAction* LargeIconsActn;
	Stdctrls::TComboBox* CaptionOptionsCombo;
	Stdctrls::TLabel* Label2;
	void __fastcall CatListClick(System::TObject* Sender);
	void __fastcall ActionsListStartDrag(System::TObject* Sender, Controls::TDragObject* &DragObject);
	void __fastcall ActionsListDrawItem(Controls::TWinControl* Control, int Index, const Types::TRect &Rect, Windows::TOwnerDrawState State);
	void __fastcall FormClose(System::TObject* Sender, Forms::TCloseAction &Action);
	void __fastcall CloseBtnClick(System::TObject* Sender);
	void __fastcall CatListStartDrag(System::TObject* Sender, Controls::TDragObject* &DragObject);
	void __fastcall ActionBarListClickCheck(System::TObject* Sender);
	void __fastcall ActionsListMeasureItem(Controls::TWinControl* Control, int Index, int &Height);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall ActionsListClick(System::TObject* Sender);
	void __fastcall MenuAnimationStylesChange(System::TObject* Sender);
	void __fastcall ResetActnUpdate(System::TObject* Sender);
	void __fastcall ResetActnExecute(System::TObject* Sender);
	void __fastcall ResetUsageDataActnExecute(System::TObject* Sender);
	void __fastcall RecentlyUsedActnExecute(System::TObject* Sender);
	void __fastcall ShowHintsActnExecute(System::TObject* Sender);
	void __fastcall ShowHintsActnUpdate(System::TObject* Sender);
	void __fastcall ShowShortCutsInTipsActnExecute(System::TObject* Sender);
	void __fastcall RecentlyUsedActnUpdate(System::TObject* Sender);
	void __fastcall ActionBarListClick(System::TObject* Sender);
	void __fastcall ActionsListData(Controls::TWinControl* Control, int Index, AnsiString &Data);
	void __fastcall LargeIconsActnExecute(System::TObject* Sender);
	void __fastcall ListComboSelect(System::TObject* Sender);
	void __fastcall CaptionOptionsComboChange(System::TObject* Sender);
	void __fastcall FormResize(System::TObject* Sender);
	void __fastcall LargeIconsActnUpdate(System::TObject* Sender);
	
private:
	Actnman::TCustomActionManager* FActionManager;
	Actnlist::TCustomActionList* FActiveActionList;
	void __fastcall SetActionManager(const Actnman::TCustomActionManager* Value);
	void __fastcall SetupListCombo(void);
	
protected:
	AnsiString __fastcall AddAction(Actnlist::TContainedAction* AnAction);
	bool __fastcall IsDupShortCut(Classes::TShortCut AShortCut, Actnlist::TContainedAction* &Action);
	virtual void __fastcall ClearCatList(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall FindActionBars(void);
	void __fastcall SetActiveActionList(const Actnlist::TCustomActionList* Value);
	virtual void __fastcall UpdateDialog(void);
	HIDESBASE MESSAGE void __fastcall CMVisiblechanged(Messages::TMessage &Message);
	
public:
	__property Actnman::TCustomActionManager* ActionManager = {read=FActionManager, write=SetActionManager};
	__property Actnlist::TCustomActionList* ActiveActionList = {read=FActiveActionList, write=SetActiveActionList};
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TCustomizeFrm(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TCustomizeFrm(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TCustomizeFrm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomizeFrm(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomizeDlg;
class PASCALIMPLEMENTATION TCustomizeDlg : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	TCustomizeFrm* FCustomizeFrm;
	bool FStayOnTop;
	Classes::TNotifyEvent FOnClose;
	Classes::TNotifyEvent FOnShow;
	Actnman::TCustomActionManager* FActionManager;
	void __fastcall SetStayOnTop(const bool Value);
	void __fastcall SetActionManager(const Actnman::TCustomActionManager* Value);
	
protected:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall SetupDlg(void);
	
public:
	void __fastcall Show(void);
	__property TCustomizeFrm* CustomizeForm = {read=FCustomizeFrm};
	
__published:
	__property Actnman::TCustomActionManager* ActionManager = {read=FActionManager, write=SetActionManager};
	__property bool StayOnTop = {read=FStayOnTop, write=SetStayOnTop, nodefault};
	__property Classes::TNotifyEvent OnClose = {read=FOnClose, write=FOnClose};
	__property Classes::TNotifyEvent OnShow = {read=FOnShow, write=FOnShow};
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TCustomizeDlg(Classes::TComponent* AOwner) : Classes::TComponent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TCustomizeDlg(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Customizedlg */
using namespace Customizedlg;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CustomizeDlg
