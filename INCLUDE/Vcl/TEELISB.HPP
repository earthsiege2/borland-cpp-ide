// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeLisB.pas' rev: 5.00

#ifndef TeeLisBHPP
#define TeeLisBHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teelisb
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TChartListBox;
typedef void __fastcall (__closure *TDblClickSeriesEvent)(TChartListBox* Sender, int Index);

struct TListBoxSection;
typedef TListBoxSection *PListBoxSection;

#pragma pack(push, 1)
struct TListBoxSection
{
	int Width;
	bool Visible;
} ;
#pragma pack(pop)

class DELPHICLASS TListBoxSections;
class PASCALIMPLEMENTATION TListBoxSections : public Classes::TList 
{
	typedef Classes::TList inherited;
	
private:
	TListBoxSection __fastcall GetSection(int Index);
	void __fastcall SetSection(int Index, const TListBoxSection &Value);
	
public:
	void __fastcall AddSection(int AWidth);
	int __fastcall SectionLeft(int Index);
	__property TListBoxSection Section[int Index] = {read=GetSection, write=SetSection/*, default*/};
public:
		
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TListBoxSections(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TListBoxSections(void) : Classes::TList() { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TChartListBox : public Stdctrls::TCustomListBox 
{
	typedef Stdctrls::TCustomListBox inherited;
	
private:
	Stdctrls::TCheckBox* FActiveSeries;
	bool FAllowDelete;
	bool FAskDelete;
	Chart::TCustomChart* FChart;
	Windows::TPoint FHitTest;
	TListBoxSections* FSections;
	TDblClickSeriesEvent FOnEditSeries;
	Classes::TStrings* FOtherItems;
	Classes::TNotifyEvent FOtherItemsChange;
	Classes::TNotifyEvent FRefresh;
	Graphics::TBitmap* FSeriesBitmap;
	bool ComingFromDoubleClick;
	void __fastcall LBSeriesClick(System::TObject* Sender);
	void __fastcall LBSeriesDragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall LBSeriesDrawItem(Controls::TWinControl* Control, int Index, const Windows::TRect &Rect
		, Windows::TOwnerDrawState State);
	void __fastcall LBSeriesDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, Controls::TDragState 
		State, bool &Accept);
	void __fastcall LBSeriesKeyUp(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall LBSeriesMouseDown(System::TObject* Sender, Controls::TMouseButton Button, Classes::TShiftState 
		Shift, int X, int Y);
	void __fastcall DoDblClick(System::TObject* Sender);
	void __fastcall DoRefresh(void);
	void __fastcall SetChart(Chart::TCustomChart* Value);
	void __fastcall SetSectionVisible(int Index, bool Value);
	
protected:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	HIDESBASE MESSAGE void __fastcall WMSetCursor(Messages::TWMSetCursor &Msg);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Messages::TWMNCHitTest &Msg);
	
public:
	__fastcall virtual TChartListBox(Classes::TComponent* AOwner);
	__fastcall virtual ~TChartListBox(void);
	__property Stdctrls::TCheckBox* ActiveCheckBox = {read=FActiveSeries};
	Teengine::TChartSeries* __fastcall AddSeriesGallery(void);
	void __fastcall ChangeTypeSeries(System::TObject* Sender);
	void __fastcall ClearItems(void);
	void __fastcall CloneSeries(void);
	void __fastcall DeleteSeries(void);
	void __fastcall FillSeries(Teengine::TChartSeries* OldSeries);
	void __fastcall MoveCurrentDown(void);
	void __fastcall MoveCurrentUp(void);
	__property Classes::TStrings* OtherItems = {read=FOtherItems, write=FOtherItems};
	bool __fastcall PointInSection(const Windows::TPoint &P, int ASection);
	void __fastcall RenameSeries(void);
	int __fastcall SeriesAtMousePos(Windows::TPoint &p);
	void __fastcall SwapSeries(int tmp1, int tmp2);
	Teengine::TChartSeries* __fastcall SelectedSeries(void);
	__property TListBoxSections* Sections = {read=FSections};
	void __fastcall UpdateSeries(void);
	bool __fastcall GetShowActive(void);
	void __fastcall SetShowActive(bool Value);
	bool __fastcall GetShowIcon(void);
	void __fastcall SetShowIcon(bool Value);
	bool __fastcall GetShowColor(void);
	void __fastcall SetShowColor(bool Value);
	bool __fastcall GetShowTitle(void);
	void __fastcall SetShowTitle(bool Value);
	
__published:
	__property bool AllowDeleteSeries = {read=FAllowDelete, write=FAllowDelete, default=1};
	__property bool AskDelete = {read=FAskDelete, write=FAskDelete, default=1};
	__property Chart::TCustomChart* Chart = {read=FChart, write=SetChart};
	__property Classes::TNotifyEvent OnOtherItemsChange = {read=FOtherItemsChange, write=FOtherItemsChange
		};
	__property TDblClickSeriesEvent OnDblClickSeries = {read=FOnEditSeries, write=FOnEditSeries};
	__property Classes::TNotifyEvent OnRefresh = {read=FRefresh, write=FRefresh};
	__property bool ShowActiveCheck = {read=GetShowActive, write=SetShowActive, default=1};
	__property bool ShowSeriesColor = {read=GetShowColor, write=SetShowColor, default=1};
	__property bool ShowSeriesIcon = {read=GetShowIcon, write=SetShowIcon, default=1};
	__property bool ShowSeriesTitle = {read=GetShowTitle, write=SetShowTitle, default=1};
	__property Align ;
	__property BorderStyle ;
	__property Color ;
	__property Ctl3D ;
	__property Enabled ;
	__property ExtendedSelect ;
	__property Font ;
	__property ImeMode ;
	__property ImeName ;
	__property MultiSelect ;
	__property ParentColor ;
	__property ParentCtl3D ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder ;
	__property TabStop ;
	__property Visible ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TChartListBox(HWND ParentWindow) : Stdctrls::TCustomListBox(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall MoveList(Stdctrls::TListBox* Source, Stdctrls::TListBox* Dest);
extern PACKAGE void __fastcall MoveListAll(Stdctrls::TListBox* Source, Stdctrls::TListBox* Dest);

}	/* namespace Teelisb */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Teelisb;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeLisB
