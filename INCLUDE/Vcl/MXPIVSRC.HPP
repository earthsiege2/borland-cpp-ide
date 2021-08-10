// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'MXPIVSRC.pas' rev: 6.00

#ifndef MXPIVSRCHPP
#define MXPIVSRCHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <MXCOMMON.hpp>	// Pascal unit
#include <Mxstore.hpp>	// Pascal unit
#include <MXBUTTON.hpp>	// Pascal unit
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
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Mxpivsrc
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TDecisionButtonPosition { xtHorizontal, xtVertical, xtLeftTop };
#pragma option pop

#pragma option push -b-
enum TDecisionPivotOption { xtRows, xtColumns, xtSummaries };
#pragma option pop

typedef Set<TDecisionPivotOption, xtRows, xtSummaries>  TDecisionPivotOptions;

class DELPHICLASS TPivotDataLink;
class DELPHICLASS TDecisionPivot;
class PASCALIMPLEMENTATION TDecisionPivot : public Extctrls::TCustomPanel 
{
	typedef Extctrls::TCustomPanel inherited;
	
private:
	bool FActive;
	TPivotDataLink* FDataLink;
	Mxdb::TDecisionSource* FSource;
	Classes::TList* FControls;
	Mxbutton::TPivotButton* FSummaryBox;
	Mxbutton::TPivotButton* FInActiveBox;
	Mxbutton::TPivotButton* FRowTarget;
	Mxbutton::TPivotButton* FColTarget;
	int FRows;
	int FCols;
	int FPages;
	int FExtras;
	bool FAutosize;
	TDecisionButtonPosition FStyle;
	TDecisionPivotOptions FContents;
	int FSpacing;
	int FControlWidth;
	int FControlHeight;
	int FGroupSpacing;
	int FTargetSize;
	HIDESBASE void __fastcall SetAutoSize(bool Value);
	void __fastcall GetButtonSizes(int &CellWidth, int &CellHeight);
	void __fastcall SetStyle(TDecisionButtonPosition Style);
	void __fastcall SetContents(TDecisionPivotOptions Contents);
	void __fastcall SetSpacing(int Value);
	void __fastcall SetControlWidth(int Value);
	void __fastcall SetControlHeight(int Value);
	void __fastcall SetGroupSpacing(int Value);
	void __fastcall SeTDecisionSource(Mxdb::TDecisionSource* aSource);
	
protected:
	virtual void __fastcall AdjustClientRect(Types::TRect &Rect);
	HIDESBASE void __fastcall SetBorderWidth(Controls::TBorderWidth Value);
	Controls::TBorderWidth __fastcall GetBorderWidth(void);
	HIDESBASE void __fastcall SetBorderStyle(Forms::TBorderStyle Value);
	Forms::TBorderStyle __fastcall GetBorderStyle(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall NewPanelSetup(void);
	void __fastcall NewDimLayout(void);
	void __fastcall DimStateChange(int iDim);
	__property int Rows = {read=FRows, nodefault};
	__property int Cols = {read=FCols, nodefault};
	__property int Pages = {read=FPages, nodefault};
	__property int Extras = {read=FExtras, nodefault};
	
public:
	__fastcall virtual TDecisionPivot(Classes::TComponent* AOwner);
	__fastcall virtual ~TDecisionPivot(void);
	virtual void __fastcall SetBounds(int Left, int Top, int Height, int Width);
	
__published:
	__property bool ButtonAutoSize = {read=FAutosize, write=SetAutoSize, nodefault};
	__property Mxdb::TDecisionSource* DecisionSource = {read=FSource, write=SeTDecisionSource};
	__property TDecisionButtonPosition GroupLayout = {read=FStyle, write=SetStyle, nodefault};
	__property TDecisionPivotOptions Groups = {read=FContents, write=SetContents, nodefault};
	__property int ButtonSpacing = {read=FSpacing, write=SetSpacing, nodefault};
	__property int ButtonWidth = {read=FControlWidth, write=SetControlWidth, nodefault};
	__property int ButtonHeight = {read=FControlHeight, write=SetControlHeight, nodefault};
	__property int GroupSpacing = {read=FGroupSpacing, write=SetGroupSpacing, nodefault};
	__property Controls::TBorderWidth BorderWidth = {read=GetBorderWidth, write=SetBorderWidth, nodefault};
	__property Forms::TBorderStyle BorderStyle = {read=GetBorderStyle, write=SetBorderStyle, nodefault};
	__property Align  = {default=0};
	__property Alignment  = {default=2};
	__property BevelInner  = {default=0};
	__property BevelOuter  = {default=2};
	__property BevelWidth  = {default=1};
	__property DragCursor  = {default=-12};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property Color  = {default=-2147483633};
	__property Ctl3D ;
	__property ParentColor  = {default=0};
	__property ParentCtl3D  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=0};
	__property Visible  = {default=1};
	__property OnClick ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnResize ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDecisionPivot(HWND ParentWindow) : Extctrls::TCustomPanel(ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TPivotDataLink : public Mxdb::TDecisionDataLink 
{
	typedef Mxdb::TDecisionDataLink inherited;
	
private:
	TDecisionPivot* FPivot;
	
protected:
	virtual void __fastcall DecisionDataEvent(Mxdb::TDecisionDataEvent Event);
	
public:
	__fastcall TPivotDataLink(TDecisionPivot* aPivot);
	__fastcall virtual ~TPivotDataLink(void);
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Mxpivsrc */
using namespace Mxpivsrc;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// MXPIVSRC
