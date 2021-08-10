// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'MXBUTTON.pas' rev: 6.00

#ifndef MXBUTTONHPP
#define MXBUTTONHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <MXCOMMON.hpp>	// Pascal unit
#include <Mxstore.hpp>	// Pascal unit
#include <MXDB.hpp>	// Pascal unit
#include <Mxconsts.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <DBTables.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <BDE.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Grids.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Mxbutton
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TMenuProp { tmChecked, tmRadio, tmNone };
#pragma option pop

class DELPHICLASS TQuickMenuItem;
class PASCALIMPLEMENTATION TQuickMenuItem : public Menus::TMenuItem 
{
	typedef Menus::TMenuItem inherited;
	
private:
	int Action;
public:
	#pragma option push -w-inl
	/* TMenuItem.Create */ inline __fastcall virtual TQuickMenuItem(Classes::TComponent* AOwner) : Menus::TMenuItem(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TMenuItem.Destroy */ inline __fastcall virtual ~TQuickMenuItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQuickMenu;
class PASCALIMPLEMENTATION TQuickMenu : public Menus::TPopupMenu 
{
	typedef Menus::TPopupMenu inherited;
	
private:
	Classes::TNotifyEvent FOnSelected;
	void __fastcall EHOnItemClick(System::TObject* Sender);
	
public:
	int FAction;
	int iDim;
	Mxdb::TDimGroup dimGroup;
	bool isGroupStart;
	int Index;
	int Cell;
	int ValueIndex;
	void __fastcall Clear(void);
	void __fastcall SetTitle(AnsiString value);
	void __fastcall AddLine(const AnsiString value, TMenuProp Prop, int Action);
	void __fastcall PopUpAtMe(Controls::TWinControl* aControl, int x, int y);
	__property Classes::TNotifyEvent OnSelected = {read=FOnSelected, write=FOnSelected};
public:
	#pragma option push -w-inl
	/* TPopupMenu.Create */ inline __fastcall virtual TQuickMenu(Classes::TComponent* AOwner) : Menus::TPopupMenu(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPopupMenu.Destroy */ inline __fastcall virtual ~TQuickMenu(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TPivotButtonMouseState { xmNone, xmPushed, xmDragging };
#pragma option pop

#pragma option push -b-
enum TPivotButtonType { pbDimension, pbTarget, pbSummary, pbInactive };
#pragma option pop

class DELPHICLASS TPivotButton;
class PASCALIMPLEMENTATION TPivotButton : public Buttons::TSpeedButton 
{
	typedef Buttons::TSpeedButton inherited;
	
private:
	TPivotButtonType FType;
	Mxdb::TDecisionSource* FSource;
	TQuickMenu* FMenu;
	TPivotButtonMouseState FMouseState;
	int SaveX;
	int SaveY;
	int myDim;
	Mxdb::TDimInfo myDimInfo;
	void __fastcall SetState(TPivotButtonMouseState Value);
	void __fastcall SetMyDim(int iDim);
	void __fastcall SetDecisionSource(Mxdb::TDecisionSource* Value);
	void __fastcall SelectButtonValue(void);
	void __fastcall SelectButtonProperties(void);
	void __fastcall EHOnValue(System::TObject* Sender);
	void __fastcall EHOnProperty(System::TObject* Sender);
	
protected:
	HIDESBASE MESSAGE void __fastcall CMDesignHitTest(Messages::TWMMouse &Msg);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall DragOver(System::TObject* Source, int X, int Y, Controls::TDragState State, bool &Accept);
	DYNAMIC void __fastcall DragCanceled(void);
	virtual void __fastcall Paint(void);
	
public:
	__fastcall virtual TPivotButton(Classes::TComponent* AOwner);
	__fastcall virtual ~TPivotButton(void);
	DYNAMIC void __fastcall Click(void);
	DYNAMIC void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	__property Mxdb::TDimInfo DimInfo = {read=myDimInfo};
	void __fastcall NewState(void);
	void __fastcall SetType(TPivotButtonType Value);
	
__published:
	__property Parent ;
	__property Mxdb::TDecisionSource* DecisionSource = {read=FSource, write=SetDecisionSource};
	__property int iDim = {read=myDim, write=SetMyDim, nodefault};
};


#pragma option push -b-
enum TDecisionButtonPosition { xtHorizontal, xtVertical, xtLeftTop };
#pragma option pop

#pragma option push -b-
enum TDecisionButtonGrouping { xtCheck, xtRadio, xtSequential };
#pragma option pop

#pragma option push -b-
enum TDecisionPivotOption { xtRows, xtColumns, xtSummaries };
#pragma option pop

typedef Set<TDecisionPivotOption, xtRows, xtSummaries>  TDecisionPivotOptions;

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Mxbutton */
using namespace Mxbutton;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// MXBUTTON
