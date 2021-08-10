// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Calendar.pas' rev: 6.00

#ifndef CalendarHPP
#define CalendarHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Grids.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Calendar
{
//-- type declarations -------------------------------------------------------
typedef Shortint TDayOfWeek;

class DELPHICLASS TCalendar;
class PASCALIMPLEMENTATION TCalendar : public Grids::TCustomGrid 
{
	typedef Grids::TCustomGrid inherited;
	
private:
	System::TDateTime FDate;
	int FMonthOffset;
	Classes::TNotifyEvent FOnChange;
	bool FReadOnly;
	TDayOfWeek FStartOfWeek;
	bool FUpdating;
	bool FUseCurrentDate;
	AnsiString __fastcall GetCellText(int ACol, int ARow);
	int __fastcall GetDateElement(int Index);
	void __fastcall SetCalendarDate(System::TDateTime Value);
	void __fastcall SetDateElement(int Index, int Value);
	void __fastcall SetStartOfWeek(TDayOfWeek Value);
	void __fastcall SetUseCurrentDate(bool Value);
	bool __fastcall StoreCalendarDate(void);
	
protected:
	DYNAMIC void __fastcall Change(void);
	void __fastcall ChangeMonth(int Delta);
	DYNAMIC void __fastcall Click(void);
	virtual int __fastcall DaysPerMonth(int AYear, int AMonth);
	virtual int __fastcall DaysThisMonth(void);
	virtual void __fastcall DrawCell(int ACol, int ARow, const Types::TRect &ARect, Grids::TGridDrawState AState);
	virtual bool __fastcall IsLeapYear(int AYear);
	virtual bool __fastcall SelectCell(int ACol, int ARow);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	
public:
	__fastcall virtual TCalendar(Classes::TComponent* AOwner);
	__property System::TDateTime CalendarDate = {read=FDate, write=SetCalendarDate, stored=StoreCalendarDate};
	__property AnsiString CellText[int ACol][int ARow] = {read=GetCellText};
	void __fastcall NextMonth(void);
	void __fastcall NextYear(void);
	void __fastcall PrevMonth(void);
	void __fastcall PrevYear(void);
	virtual void __fastcall UpdateCalendar(void);
	
__published:
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property BorderStyle  = {default=1};
	__property Color  = {default=-2147483643};
	__property Constraints ;
	__property Ctl3D ;
	__property int Day = {read=GetDateElement, write=SetDateElement, stored=false, index=3, nodefault};
	__property DragCursor  = {default=-12};
	__property DragKind  = {default=0};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property GridLineWidth  = {default=1};
	__property int Month = {read=GetDateElement, write=SetDateElement, stored=false, index=2, nodefault};
	__property ParentColor  = {default=0};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property bool ReadOnly = {read=FReadOnly, write=FReadOnly, default=0};
	__property ShowHint ;
	__property TDayOfWeek StartOfWeek = {read=FStartOfWeek, write=SetStartOfWeek, nodefault};
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property bool UseCurrentDate = {read=FUseCurrentDate, write=SetUseCurrentDate, default=1};
	__property Visible  = {default=1};
	__property int Year = {read=GetDateElement, write=SetDateElement, stored=false, index=1, nodefault};
	__property OnClick ;
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnStartDock ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TCustomGrid.Destroy */ inline __fastcall virtual ~TCalendar(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCalendar(HWND ParentWindow) : Grids::TCustomGrid(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Calendar */
using namespace Calendar;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Calendar
