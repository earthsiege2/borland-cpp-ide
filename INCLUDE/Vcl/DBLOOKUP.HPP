// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DBLookup.pas' rev: 5.00

#ifndef DBLookupHPP
#define DBLookupHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DBCtrls.hpp>	// Pascal unit
#include <Grids.hpp>	// Pascal unit
#include <DBTables.hpp>	// Pascal unit
#include <DBGrids.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dblookup
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TDBLookupComboStyle { csDropDown, csDropDownList };
#pragma option pop

#pragma option push -b-
enum TDBLookupListOption { loColLines, loRowLines, loTitles };
#pragma option pop

typedef Set<TDBLookupListOption, loColLines, loTitles>  TDBLookupListOptions;

class DELPHICLASS TDBLookupCombo;
class DELPHICLASS TPopupGrid;
class DELPHICLASS TDBLookupList;
class PASCALIMPLEMENTATION TDBLookupList : public Dbgrids::TCustomDBGrid 
{
	typedef Dbgrids::TCustomDBGrid inherited;
	
private:
	Dbctrls::TFieldDataLink* FFieldLink;
	AnsiString FLookupDisplay;
	AnsiString FLookupField;
	Db::TField* FDisplayFld;
	Db::TField* FValueFld;
	AnsiString FValue;
	AnsiString FDisplayValue;
	int FHiliteRow;
	TDBLookupListOptions FOptions;
	int FTitleOffset;
	bool FFoundValue;
	bool FInCellSelect;
	Classes::TNotifyEvent FOnListClick;
	AnsiString __fastcall GetDataField();
	HIDESBASE Db::TDataSource* __fastcall GetDataSource(void);
	Db::TDataSource* __fastcall GetLookupSource(void);
	bool __fastcall GetReadOnly(void);
	void __fastcall FieldLinkActive(System::TObject* Sender);
	void __fastcall DataChange(System::TObject* Sender);
	void __fastcall SetDataField(const AnsiString Value);
	HIDESBASE void __fastcall SetDataSource(Db::TDataSource* Value);
	void __fastcall SetLookupSource(Db::TDataSource* Value);
	void __fastcall SetLookupDisplay(const AnsiString Value);
	void __fastcall SetLookupField(const AnsiString Value);
	void __fastcall SetValue(const AnsiString Value);
	void __fastcall SetDisplayValue(const AnsiString Value);
	void __fastcall SetReadOnly(bool Value);
	HIDESBASE void __fastcall SetOptions(TDBLookupListOptions Value);
	HIDESBASE void __fastcall UpdateData(System::TObject* Sender);
	void __fastcall NewLayout(void);
	void __fastcall DoLookup(void);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	HIDESBASE MESSAGE void __fastcall CMEnter(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall CMExit(Messages::TWMNoParams &Message);
	
protected:
	virtual bool __fastcall HighlightCell(int DataCol, int DataRow, const AnsiString Value, Grids::TGridDrawState 
		AState);
	DYNAMIC bool __fastcall CanGridAcceptKey(Word Key, Classes::TShiftState Shift);
	virtual void __fastcall DefineFieldMap(void);
	virtual void __fastcall SetColumnAttributes(void);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, 
		int Y);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int 
		Y);
	virtual bool __fastcall CanEdit(void);
	void __fastcall InitFields(bool ShowError);
	virtual void __fastcall CreateWnd(void);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(char &Key);
	virtual void __fastcall LinkActive(bool Value);
	virtual void __fastcall Paint(void);
	virtual void __fastcall Scroll(int Distance);
	DYNAMIC void __fastcall ListClick(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	
public:
	__fastcall virtual TDBLookupList(Classes::TComponent* AOwner);
	__fastcall virtual ~TDBLookupList(void);
	__property AnsiString Value = {read=FValue, write=SetValue};
	__property AnsiString DisplayValue = {read=FDisplayValue, write=SetDisplayValue};
	
__published:
	__property AnsiString DataField = {read=GetDataField, write=SetDataField};
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property Db::TDataSource* LookupSource = {read=GetLookupSource, write=SetLookupSource};
	__property AnsiString LookupDisplay = {read=FLookupDisplay, write=SetLookupDisplay};
	__property AnsiString LookupField = {read=FLookupField, write=SetLookupField};
	__property TDBLookupListOptions Options = {read=FOptions, write=SetOptions, default=0};
	__property Classes::TNotifyEvent OnClick = {read=FOnListClick, write=FOnListClick};
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
	__property Align ;
	__property Anchors ;
	__property BorderStyle ;
	__property Color ;
	__property Constraints ;
	__property Ctl3D ;
	__property DragCursor ;
	__property DragMode ;
	__property Enabled ;
	__property Font ;
	__property ImeMode ;
	__property ImeName ;
	__property ParentColor ;
	__property ParentCtl3D ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder ;
	__property TabStop ;
	__property Visible ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDBLookupList(HWND ParentWindow) : Dbgrids::TCustomDBGrid(
		ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TPopupGrid : public TDBLookupList 
{
	typedef TDBLookupList inherited;
	
private:
	TDBLookupCombo* FCombo;
	HIDESBASE MESSAGE void __fastcall CMHintShow(Messages::TMessage &Message);
	
protected:
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	HIDESBASE MESSAGE void __fastcall WMLButtonUp(Messages::TWMMouse &Message);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, 
		int Y);
	virtual bool __fastcall CanEdit(void);
	virtual void __fastcall LinkActive(bool Value);
	
public:
	__property RowCount ;
	__fastcall virtual TPopupGrid(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TDBLookupList.Destroy */ inline __fastcall virtual ~TPopupGrid(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TPopupGrid(HWND ParentWindow) : TDBLookupList(ParentWindow
		) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TDBLookupCombo : public Stdctrls::TCustomEdit 
{
	typedef Stdctrls::TCustomEdit inherited;
	
private:
	Controls::TControlCanvas* FCanvas;
	int FDropDownCount;
	int FDropDownWidth;
	int FTextMargin;
	Dbctrls::TFieldDataLink* FFieldLink;
	TPopupGrid* FGrid;
	Buttons::TSpeedButton* FButton;
	Controls::TWinControl* FBtnControl;
	TDBLookupComboStyle FStyle;
	Classes::TNotifyEvent FOnDropDown;
	AnsiString __fastcall GetDataField();
	Db::TDataSource* __fastcall GetDataSource(void);
	Db::TDataSource* __fastcall GetLookupSource(void);
	AnsiString __fastcall GetLookupDisplay();
	AnsiString __fastcall GetLookupField();
	bool __fastcall GetReadOnly(void);
	AnsiString __fastcall GetValue();
	AnsiString __fastcall GetDisplayValue();
	int __fastcall GetMinHeight(void);
	TDBLookupListOptions __fastcall GetOptions(void);
	bool __fastcall CanEdit(void);
	bool __fastcall Editable(void);
	void __fastcall SetValue(const AnsiString NewValue);
	void __fastcall SetDisplayValue(const AnsiString NewValue);
	void __fastcall DataChange(System::TObject* Sender);
	void __fastcall EditingChange(System::TObject* Sender);
	void __fastcall SetDataField(const AnsiString Value);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	void __fastcall SetLookupSource(Db::TDataSource* Value);
	void __fastcall SetLookupDisplay(const AnsiString Value);
	void __fastcall SetLookupField(const AnsiString Value);
	HIDESBASE void __fastcall SetReadOnly(bool Value);
	void __fastcall SetOptions(TDBLookupListOptions Value);
	void __fastcall SetStyle(TDBLookupComboStyle Value);
	void __fastcall UpdateData(System::TObject* Sender);
	void __fastcall FieldLinkActive(System::TObject* Sender);
	void __fastcall NonEditMouseDown(Messages::TWMMouse &Message);
	void __fastcall DoSelectAll(void);
	void __fastcall SetEditRect(void);
	MESSAGE void __fastcall WMPaste(Messages::TMessage &Message);
	MESSAGE void __fastcall WMCut(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Messages::TWMKillFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	MESSAGE void __fastcall CMCancelMode(Controls::TCMCancelMode &Message);
	HIDESBASE MESSAGE void __fastcall CMExit(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDblClk(Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonUp(Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Messages::TWMSetFocus &Message);
	HIDESBASE MESSAGE void __fastcall CMEnter(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall CMHintShow(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMPaint(Messages::TWMPaint &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Messages::TMessage &Message);
	
protected:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	DYNAMIC void __fastcall Change(void);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(char &Key);
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	void __fastcall GridClick(System::TObject* Sender);
	virtual void __fastcall Loaded(void);
	
public:
	__fastcall virtual TDBLookupCombo(Classes::TComponent* AOwner);
	__fastcall virtual ~TDBLookupCombo(void);
	DYNAMIC void __fastcall DropDown(void);
	DYNAMIC void __fastcall CloseUp(void);
	__property AnsiString Value = {read=GetValue, write=SetValue};
	__property AnsiString DisplayValue = {read=GetDisplayValue, write=SetDisplayValue};
	
__published:
	__property AnsiString DataField = {read=GetDataField, write=SetDataField};
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property Db::TDataSource* LookupSource = {read=GetLookupSource, write=SetLookupSource};
	__property AnsiString LookupDisplay = {read=GetLookupDisplay, write=SetLookupDisplay};
	__property AnsiString LookupField = {read=GetLookupField, write=SetLookupField};
	__property TDBLookupListOptions Options = {read=GetOptions, write=SetOptions, default=0};
	__property TDBLookupComboStyle Style = {read=FStyle, write=SetStyle, default=0};
	__property Anchors ;
	__property AutoSelect ;
	__property Color ;
	__property Constraints ;
	__property Ctl3D ;
	__property DragCursor ;
	__property DragMode ;
	__property int DropDownCount = {read=FDropDownCount, write=FDropDownCount, default=8};
	__property int DropDownWidth = {read=FDropDownWidth, write=FDropDownWidth, default=0};
	__property Enabled ;
	__property Font ;
	__property ImeMode ;
	__property ImeName ;
	__property MaxLength ;
	__property ParentColor ;
	__property ParentCtl3D ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
	__property ShowHint ;
	__property TabOrder ;
	__property TabStop ;
	__property Visible ;
	__property OnChange ;
	__property OnClick ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property Classes::TNotifyEvent OnDropDown = {read=FOnDropDown, write=FOnDropDown};
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDBLookupCombo(HWND ParentWindow) : Stdctrls::TCustomEdit(
		ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TComboButton;
class PASCALIMPLEMENTATION TComboButton : public Buttons::TSpeedButton 
{
	typedef Buttons::TSpeedButton inherited;
	
protected:
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, 
		int Y);
public:
	#pragma option push -w-inl
	/* TSpeedButton.Create */ inline __fastcall virtual TComboButton(Classes::TComponent* AOwner) : Buttons::TSpeedButton(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TSpeedButton.Destroy */ inline __fastcall virtual ~TComboButton(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Dblookup */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Dblookup;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DBLookup
