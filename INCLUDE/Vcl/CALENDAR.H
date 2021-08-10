//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1997 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
#ifndef Calendar_HPP
#define Calendar_HPP

#include <Menus.hpp>
#include <SysUtils.hpp>
#include <Grids.hpp>
#include <StdCtrls.hpp>
#include <Graphics.hpp>
#include <Forms.hpp>
#include <Windows.hpp>
#include <Messages.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <System.hpp>

typedef short TDayOfWeek;

class PACKAGE TCalendar : public TCustomGrid
{
private:
  TDateTime FDate;
  Integer FMonthOffset;
  TNotifyEvent FOnChange;
  Boolean FReadOnly;
  TDayOfWeek FStartOfWeek;
  Boolean FUpdating;
  Boolean FUseCurrentDate;
  AnsiString __fastcall GetCellText(int ACol, int ARow);
  Integer __fastcall GetDateElement(Integer Index);
  void __fastcall SetCalendarDate(TDateTime Value);
  void __fastcall SetDateElement(int Index, int Value);
  void __fastcall SetStartOfWeek(TDayOfWeek Value);
  void __fastcall SetUseCurrentDate(bool Value);
  bool __fastcall StoreCalendarDate();

protected:
  virtual void __fastcall Change();
  void __fastcall ChangeMonth(Integer Delta);
  DYNAMIC void __fastcall Click(void);
  virtual int __fastcall DaysThisMonth();
  virtual void __fastcall DrawCell(int ACol, int ARow, const TRect &ARect,
    TGridDrawState AState);
  virtual bool __fastcall IsLeapYear(int AYear);
  virtual bool __fastcall SelectCell(int ACol, int ARow);
  void __fastcall WMSize(TWMSize& Message);

public:
  __fastcall virtual TCalendar(TComponent *AOwner);
  __fastcall virtual TCalendar(HWND Parent): TCustomGrid(Parent) {};
  __property TDateTime CalendarDate = {read=FDate, write=SetCalendarDate, stored=StoreCalendarDate};
  __property AnsiString CellText[Integer ACol][Integer ARow] = {read=GetCellText};
  void __fastcall NextMonth();
  void __fastcall NextYear();
  void __fastcall PrevMonth();
  void __fastcall PrevYear();
  virtual void __fastcall UpdateCalendar();
  virtual int __fastcall DaysPerMonth(int AYear, int AMonth);

__published:
  __property Align ;
  __property BorderStyle ;
  __property Color ;
  __property Ctl3D ;
  __property Integer Day = {read=GetDateElement, write=SetDateElement, stored=false, index=3, nodefault
    };
  __property Enabled ;
  __property Font ;
  __property GridLineWidth ;
  __property Integer Month = {read=GetDateElement, write=SetDateElement, stored=false, index=2, nodefault
    };
  __property ParentColor ;
  __property ParentFont ;
  __property ParentShowHint ;
  __property PopupMenu ;
  __property Boolean ReadOnly = {read=FReadOnly, write=FReadOnly, default=0};
  __property ShowHint ;
  __property TDayOfWeek StartOfWeek = {read=FStartOfWeek, write=SetStartOfWeek, default=1};
  __property TabOrder ;
  __property TabStop ;
  __property Boolean UseCurrentDate = {read=FUseCurrentDate, write=SetUseCurrentDate, default=1};
  __property Visible ;
  __property Integer Year = {read=GetDateElement, write=SetDateElement, stored=false, index=1, nodefault
    };
  __property OnClick ;
  __property TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
  __property OnDblClick ;
  __property OnDragDrop ;
  __property OnDragOver ;
  __property OnEndDrag ;
  __property OnEnter ;
  __property OnExit ;
  __property OnKeyDown ;
  __property OnKeyPress ;
  __property OnKeyUp ;

  BEGIN_MESSAGE_MAP
    VCL_MESSAGE_HANDLER(WM_SIZE, TWMSize, WMSize);
  END_MESSAGE_MAP(TCustomGrid);
};

#endif  // Calendar_HPP
