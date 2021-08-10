// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'mxpivsrc.pas' rev: 5.00

#ifndef mxpivsrcHPP
#define mxpivsrcHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <mxcommon.hpp>	// Pascal unit
#include <mxstore.hpp>	// Pascal unit
#include <mxbutton.hpp>	// Pascal unit
#include <mxDB.hpp>	// Pascal unit
#include <mxConsts.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <DBTables.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <Bde.hpp>	// Pascal unit
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
	virtual void __fastcall AdjustClientRect(Windows::TRect &Rect);
	HIDESBASE void __fastcall SetBorderWidth(Controls::TBorderWidth Value);
	Controls::TBorderWidth __fastcall GetBorderWidth(void);
	HIDESBASE void __fastcall SetBorderStyle(Forms::TBorderStyle Value);
	Forms::TBorderStyle __fastcall GetBorderStyle(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
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
	__property Controls::TBorderWidth BorderWidth = {read=GetBorderWidth, write=SetBorderWidth, nodefault
		};
	__property Forms::TBorderStyle BorderStyle = {read=GetBorderStyle, write=SetBorderStyle, nodefault}
		;
	__property Align ;
	__property Alignment ;
	__property BevelInner ;
	__property BevelOuter ;
	__property BevelWidth ;
	__property DragCursor ;
	__property DragMode ;
	__property Enabled ;
	__property Font ;
	__property Color ;
	__property Ctl3D ;
	__property ParentColor ;
	__property ParentCtl3D ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder ;
	__property TabStop ;
	__property Visible ;
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
	/* TWinControl.CreateParented */ inline __fastcall TDecisionPivot(HWND ParentWindow) : Extctrls::TCustomPanel(
		ParentWindow) { }
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
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Mxpivsrc;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// mxpivsrc
