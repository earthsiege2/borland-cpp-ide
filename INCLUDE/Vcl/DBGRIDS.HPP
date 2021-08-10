// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DBGrids.pas' rev: 6.00

#ifndef DBGridsHPP
#define DBGridsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ImgList.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <DBCtrls.hpp>	// Pascal unit
#include <Grids.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dbgrids
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TColumnValue { cvColor, cvWidth, cvFont, cvAlignment, cvReadOnly, cvTitleColor, cvTitleCaption, cvTitleAlignment, cvTitleFont, cvImeMode, cvImeName };
#pragma option pop

typedef Set<TColumnValue, cvColor, cvImeName>  TColumnValues;

class DELPHICLASS TColumnTitle;
class DELPHICLASS TColumn;
#pragma option push -b-
enum TColumnButtonStyle { cbsAuto, cbsEllipsis, cbsNone };
#pragma option pop

class DELPHICLASS TCustomDBGrid;
class PASCALIMPLEMENTATION TColumn : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	Db::TField* FField;
	AnsiString FFieldName;
	Graphics::TColor FColor;
	int FWidth;
	TColumnTitle* FTitle;
	Graphics::TFont* FFont;
	Controls::TImeMode FImeMode;
	AnsiString FImeName;
	Classes::TStrings* FPickList;
	Menus::TPopupMenu* FPopupMenu;
	unsigned FDropDownRows;
	TColumnButtonStyle FButtonStyle;
	Classes::TAlignment FAlignment;
	bool FReadonly;
	TColumnValues FAssignedValues;
	bool FVisible;
	bool FExpanded;
	bool FStored;
	void __fastcall FontChanged(System::TObject* Sender);
	Classes::TAlignment __fastcall GetAlignment(void);
	Graphics::TColor __fastcall GetColor(void);
	bool __fastcall GetExpanded(void);
	Db::TField* __fastcall GetField(void);
	Graphics::TFont* __fastcall GetFont(void);
	Controls::TImeMode __fastcall GetImeMode(void);
	AnsiString __fastcall GetImeName();
	TColumn* __fastcall GetParentColumn(void);
	Classes::TStrings* __fastcall GetPickList(void);
	bool __fastcall GetReadOnly(void);
	bool __fastcall GetShowing(void);
	int __fastcall GetWidth(void);
	bool __fastcall GetVisible(void);
	bool __fastcall IsAlignmentStored(void);
	bool __fastcall IsColorStored(void);
	bool __fastcall IsFontStored(void);
	bool __fastcall IsImeModeStored(void);
	bool __fastcall IsImeNameStored(void);
	bool __fastcall IsReadOnlyStored(void);
	bool __fastcall IsWidthStored(void);
	virtual void __fastcall SetAlignment(Classes::TAlignment Value);
	void __fastcall SetButtonStyle(TColumnButtonStyle Value);
	void __fastcall SetColor(Graphics::TColor Value);
	void __fastcall SetExpanded(bool Value);
	virtual void __fastcall SetField(Db::TField* Value);
	void __fastcall SetFieldName(const AnsiString Value);
	void __fastcall SetFont(Graphics::TFont* Value);
	virtual void __fastcall SetImeMode(Controls::TImeMode Value);
	virtual void __fastcall SetImeName(AnsiString Value);
	void __fastcall SetPickList(Classes::TStrings* Value);
	void __fastcall SetPopupMenu(Menus::TPopupMenu* Value);
	virtual void __fastcall SetReadOnly(bool Value);
	void __fastcall SetTitle(TColumnTitle* Value);
	virtual void __fastcall SetWidth(int Value);
	void __fastcall SetVisible(bool Value);
	bool __fastcall GetExpandable(void);
	
protected:
	virtual TColumnTitle* __fastcall CreateTitle(void);
	TCustomDBGrid* __fastcall GetGrid(void);
	virtual AnsiString __fastcall GetDisplayName();
	void __fastcall RefreshDefaultFont(void);
	virtual void __fastcall SetIndex(int Value);
	__property bool IsStored = {read=FStored, write=FStored, default=1};
	
public:
	__fastcall virtual TColumn(Classes::TCollection* Collection);
	__fastcall virtual ~TColumn(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	Classes::TAlignment __fastcall DefaultAlignment(void);
	Graphics::TColor __fastcall DefaultColor(void);
	Graphics::TFont* __fastcall DefaultFont(void);
	Controls::TImeMode __fastcall DefaultImeMode(void);
	AnsiString __fastcall DefaultImeName();
	bool __fastcall DefaultReadOnly(void);
	int __fastcall DefaultWidth(void);
	int __fastcall Depth(void);
	virtual void __fastcall RestoreDefaults(void);
	__property TCustomDBGrid* Grid = {read=GetGrid};
	__property TColumnValues AssignedValues = {read=FAssignedValues, nodefault};
	__property bool Expandable = {read=GetExpandable, nodefault};
	__property Db::TField* Field = {read=GetField, write=SetField};
	__property TColumn* ParentColumn = {read=GetParentColumn};
	__property bool Showing = {read=GetShowing, nodefault};
	
__published:
	__property Classes::TAlignment Alignment = {read=GetAlignment, write=SetAlignment, stored=IsAlignmentStored, nodefault};
	__property TColumnButtonStyle ButtonStyle = {read=FButtonStyle, write=SetButtonStyle, default=0};
	__property Graphics::TColor Color = {read=GetColor, write=SetColor, stored=IsColorStored, nodefault};
	__property unsigned DropDownRows = {read=FDropDownRows, write=FDropDownRows, default=7};
	__property bool Expanded = {read=GetExpanded, write=SetExpanded, default=1};
	__property AnsiString FieldName = {read=FFieldName, write=SetFieldName};
	__property Graphics::TFont* Font = {read=GetFont, write=SetFont, stored=IsFontStored};
	__property Controls::TImeMode ImeMode = {read=GetImeMode, write=SetImeMode, stored=IsImeModeStored, nodefault};
	__property AnsiString ImeName = {read=GetImeName, write=SetImeName, stored=IsImeNameStored};
	__property Classes::TStrings* PickList = {read=GetPickList, write=SetPickList};
	__property Menus::TPopupMenu* PopupMenu = {read=FPopupMenu, write=SetPopupMenu};
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, stored=IsReadOnlyStored, nodefault};
	__property TColumnTitle* Title = {read=FTitle, write=SetTitle};
	__property int Width = {read=GetWidth, write=SetWidth, stored=IsWidthStored, nodefault};
	__property bool Visible = {read=GetVisible, write=SetVisible, nodefault};
};


class PASCALIMPLEMENTATION TColumnTitle : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	TColumn* FColumn;
	AnsiString FCaption;
	Graphics::TFont* FFont;
	Graphics::TColor FColor;
	Classes::TAlignment FAlignment;
	void __fastcall FontChanged(System::TObject* Sender);
	Classes::TAlignment __fastcall GetAlignment(void);
	Graphics::TColor __fastcall GetColor(void);
	AnsiString __fastcall GetCaption();
	Graphics::TFont* __fastcall GetFont(void);
	bool __fastcall IsAlignmentStored(void);
	bool __fastcall IsColorStored(void);
	bool __fastcall IsFontStored(void);
	bool __fastcall IsCaptionStored(void);
	void __fastcall SetAlignment(Classes::TAlignment Value);
	void __fastcall SetColor(Graphics::TColor Value);
	void __fastcall SetFont(Graphics::TFont* Value);
	virtual void __fastcall SetCaption(const AnsiString Value);
	
protected:
	void __fastcall RefreshDefaultFont(void);
	
public:
	__fastcall TColumnTitle(TColumn* Column);
	__fastcall virtual ~TColumnTitle(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	Classes::TAlignment __fastcall DefaultAlignment(void);
	Graphics::TColor __fastcall DefaultColor(void);
	Graphics::TFont* __fastcall DefaultFont(void);
	AnsiString __fastcall DefaultCaption();
	virtual void __fastcall RestoreDefaults(void);
	__property TColumn* Column = {read=FColumn};
	
__published:
	__property Classes::TAlignment Alignment = {read=GetAlignment, write=SetAlignment, stored=IsAlignmentStored, nodefault};
	__property AnsiString Caption = {read=GetCaption, write=SetCaption, stored=IsCaptionStored};
	__property Graphics::TColor Color = {read=GetColor, write=SetColor, stored=IsColorStored, nodefault};
	__property Graphics::TFont* Font = {read=GetFont, write=SetFont, stored=IsFontStored};
};


typedef TMetaClass*TColumnClass;

#pragma option push -b-
enum TDBGridColumnsState { csDefault, csCustomized };
#pragma option pop

class DELPHICLASS TDBGridColumns;
class PASCALIMPLEMENTATION TDBGridColumns : public Classes::TCollection 
{
	typedef Classes::TCollection inherited;
	
public:
	TColumn* operator[](int Index) { return Items[Index]; }
	
private:
	TCustomDBGrid* FGrid;
	TColumn* __fastcall GetColumn(int Index);
	TColumn* __fastcall InternalAdd(void);
	void __fastcall SetColumn(int Index, TColumn* Value);
	void __fastcall SetState(TDBGridColumnsState NewState);
	TDBGridColumnsState __fastcall GetState(void);
	
protected:
	DYNAMIC Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Update(Classes::TCollectionItem* Item);
	
public:
	__fastcall TDBGridColumns(TCustomDBGrid* Grid, TMetaClass* ColumnClass);
	HIDESBASE TColumn* __fastcall Add(void);
	void __fastcall LoadFromFile(const AnsiString Filename);
	void __fastcall LoadFromStream(Classes::TStream* S);
	void __fastcall RestoreDefaults(void);
	void __fastcall RebuildColumns(void);
	void __fastcall SaveToFile(const AnsiString Filename);
	void __fastcall SaveToStream(Classes::TStream* S);
	__property TDBGridColumnsState State = {read=GetState, write=SetState, nodefault};
	__property TCustomDBGrid* Grid = {read=FGrid};
	__property TColumn* Items[int Index] = {read=GetColumn, write=SetColumn/*, default*/};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TDBGridColumns(void) { }
	#pragma option pop
	
};


typedef DynamicArray<int >  DBGrids__5;

class DELPHICLASS TGridDataLink;
class PASCALIMPLEMENTATION TGridDataLink : public Db::TDataLink 
{
	typedef Db::TDataLink inherited;
	
private:
	TCustomDBGrid* FGrid;
	int FFieldCount;
	DynamicArray<int >  FFieldMap;
	bool FModified;
	bool FInUpdateData;
	bool FSparseMap;
	bool __fastcall GetDefaultFields(void);
	Db::TField* __fastcall GetFields(int I);
	
protected:
	virtual void __fastcall ActiveChanged(void);
	void __fastcall BuildAggMap(void);
	virtual void __fastcall DataSetChanged(void);
	virtual void __fastcall DataSetScrolled(int Distance);
	virtual void __fastcall FocusControl(Db::TFieldRef Field);
	virtual void __fastcall EditingChanged(void);
	virtual bool __fastcall IsAggRow(int Value);
	virtual void __fastcall LayoutChanged(void);
	virtual void __fastcall RecordChanged(Db::TField* Field);
	virtual void __fastcall UpdateData(void);
	int __fastcall GetMappedIndex(int ColIndex);
	
public:
	__fastcall TGridDataLink(TCustomDBGrid* AGrid);
	__fastcall virtual ~TGridDataLink(void);
	bool __fastcall AddMapping(const AnsiString FieldName);
	void __fastcall ClearMapping(void);
	void __fastcall Modified(void);
	void __fastcall Reset(void);
	__property bool DefaultFields = {read=GetDefaultFields, nodefault};
	__property int FieldCount = {read=FFieldCount, nodefault};
	__property Db::TField* Fields[int I] = {read=GetFields};
	__property bool SparseMap = {read=FSparseMap, write=FSparseMap, nodefault};
	__property TCustomDBGrid* Grid = {read=FGrid};
};


class DELPHICLASS TBookmarkList;
class PASCALIMPLEMENTATION TBookmarkList : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	AnsiString operator[](int Index) { return Items[Index]; }
	
private:
	Classes::TStringList* FList;
	TCustomDBGrid* FGrid;
	AnsiString FCache;
	int FCacheIndex;
	bool FCacheFind;
	bool FLinkActive;
	int __fastcall GetCount(void);
	bool __fastcall GetCurrentRowSelected(void);
	AnsiString __fastcall GetItem(int Index);
	void __fastcall SetCurrentRowSelected(bool Value);
	void __fastcall StringsChanged(System::TObject* Sender);
	
protected:
	AnsiString __fastcall CurrentRow();
	int __fastcall Compare(const AnsiString Item1, const AnsiString Item2);
	void __fastcall LinkActive(bool Value);
	
public:
	__fastcall TBookmarkList(TCustomDBGrid* AGrid);
	__fastcall virtual ~TBookmarkList(void);
	void __fastcall Clear(void);
	void __fastcall Delete(void);
	bool __fastcall Find(const AnsiString Item, int &Index);
	int __fastcall IndexOf(const AnsiString Item);
	bool __fastcall Refresh(void);
	__property int Count = {read=GetCount, nodefault};
	__property bool CurrentRowSelected = {read=GetCurrentRowSelected, write=SetCurrentRowSelected, nodefault};
	__property AnsiString Items[int Index] = {read=GetItem/*, default*/};
};


#pragma option push -b-
enum TDBGridOption { dgEditing, dgAlwaysShowEditor, dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit, dgMultiSelect };
#pragma option pop

typedef Set<TDBGridOption, dgEditing, dgMultiSelect>  TDBGridOptions;

typedef void __fastcall (__closure *TDrawDataCellEvent)(System::TObject* Sender, const Types::TRect &Rect, Db::TField* Field, Grids::TGridDrawState State);

typedef void __fastcall (__closure *TDrawColumnCellEvent)(System::TObject* Sender, const Types::TRect &Rect, int DataCol, TColumn* Column, Grids::TGridDrawState State);

typedef void __fastcall (__closure *TDBGridClickEvent)(TColumn* Column);

class PASCALIMPLEMENTATION TCustomDBGrid : public Grids::TCustomGrid 
{
	typedef Grids::TCustomGrid inherited;
	
private:
	Controls::TImageList* FIndicators;
	Graphics::TFont* FTitleFont;
	bool FReadOnly;
	AnsiString FOriginalImeName;
	Controls::TImeMode FOriginalImeMode;
	bool FUserChange;
	bool FIsESCKey;
	bool FLayoutFromDataset;
	TDBGridOptions FOptions;
	Byte FTitleOffset;
	Byte FIndicatorOffset;
	Byte FUpdateLock;
	Byte FLayoutLock;
	bool FInColExit;
	bool FDefaultDrawing;
	bool FSelfChangingTitleFont;
	bool FSelecting;
	int FSelRow;
	TGridDataLink* FDataLink;
	Classes::TNotifyEvent FOnColEnter;
	Classes::TNotifyEvent FOnColExit;
	TDrawDataCellEvent FOnDrawDataCell;
	TDrawColumnCellEvent FOnDrawColumnCell;
	AnsiString FEditText;
	TDBGridColumns* FColumns;
	Classes::TList* FVisibleColumns;
	TBookmarkList* FBookmarks;
	AnsiString FSelectionAnchor;
	Classes::TNotifyEvent FOnEditButtonClick;
	Grids::TMovedEvent FOnColumnMoved;
	TDBGridClickEvent FOnCellClick;
	TDBGridClickEvent FOnTitleClick;
	TColumn* FDragCol;
	bool __fastcall AcquireFocus(void);
	void __fastcall DataChanged(void);
	void __fastcall EditingChanged(void);
	Db::TDataSource* __fastcall GetDataSource(void);
	int __fastcall GetFieldCount(void);
	Db::TField* __fastcall GetFields(int FieldIndex);
	Db::TField* __fastcall GetSelectedField(void);
	int __fastcall GetSelectedIndex(void);
	void __fastcall InternalLayout(void);
	void __fastcall MoveCol(int RawCol, int Direction);
	bool __fastcall PtInExpandButton(int X, int Y, TColumn* &MasterCol);
	void __fastcall ReadColumns(Classes::TReader* Reader);
	void __fastcall RecordChanged(Db::TField* Field);
	HIDESBASE void __fastcall SetIme(void);
	void __fastcall SetColumns(TDBGridColumns* Value);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	HIDESBASE void __fastcall SetOptions(TDBGridOptions Value);
	void __fastcall SetSelectedField(Db::TField* Value);
	void __fastcall SetSelectedIndex(int Value);
	void __fastcall SetTitleFont(Graphics::TFont* Value);
	void __fastcall TitleFontChanged(System::TObject* Sender);
	void __fastcall UpdateData(void);
	void __fastcall UpdateActive(void);
	void __fastcall UpdateIme(void);
	void __fastcall UpdateScrollBar(void);
	void __fastcall UpdateRowCount(void);
	void __fastcall WriteColumns(Classes::TWriter* Writer);
	HIDESBASE MESSAGE void __fastcall CMBiDiModeChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMExit(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMParentFontChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMDeferLayout(void *Message);
	HIDESBASE MESSAGE void __fastcall CMDesignHitTest(Messages::TWMMouse &Msg);
	HIDESBASE MESSAGE void __fastcall WMSetCursor(Messages::TWMSetCursor &Msg);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	HIDESBASE MESSAGE void __fastcall WMVScroll(Messages::TWMScroll &Message);
	HIDESBASE MESSAGE void __fastcall WMIMEStartComp(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Messages::TWMSetFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Messages::TMessage &Message);
	
protected:
	bool FUpdateFields;
	bool FAcquireFocus;
	int __fastcall RawToDataColumn(int ACol);
	int __fastcall DataToRawColumn(int ACol);
	bool __fastcall AcquireLayoutLock(void);
	void __fastcall BeginLayout(void);
	void __fastcall BeginUpdate(void);
	virtual void __fastcall CalcSizingState(int X, int Y, Grids::TGridState &State, int &Index, int &SizingPos, int &SizingOfs, Grids::TGridDrawInfo &FixedInfo);
	void __fastcall CancelLayout(void);
	DYNAMIC bool __fastcall CanEditAcceptKey(char Key);
	DYNAMIC bool __fastcall CanEditModify(void);
	virtual bool __fastcall CanEditShow(void);
	DYNAMIC void __fastcall CellClick(TColumn* Column);
	DYNAMIC void __fastcall ColumnMoved(int FromIndex, int ToIndex);
	Types::TRect __fastcall CalcTitleRect(TColumn* Col, int ARow, TColumn* &MasterCol);
	TColumn* __fastcall ColumnAtDepth(TColumn* Col, int ADepth);
	DYNAMIC void __fastcall ColEnter(void);
	DYNAMIC void __fastcall ColExit(void);
	DYNAMIC void __fastcall ColWidthsChanged(void);
	DYNAMIC TDBGridColumns* __fastcall CreateColumns(void);
	virtual Grids::TInplaceEdit* __fastcall CreateEditor(void);
	DYNAMIC TGridDataLink* __fastcall CreateDataLink(void);
	virtual void __fastcall CreateWnd(void);
	void __fastcall DeferLayout(void);
	virtual void __fastcall DefineFieldMap(void);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual void __fastcall DrawCell(int ACol, int ARow, const Types::TRect &ARect, Grids::TGridDrawState AState);
	DYNAMIC void __fastcall DrawDataCell(const Types::TRect &Rect, Db::TField* Field, Grids::TGridDrawState State);
	DYNAMIC void __fastcall DrawColumnCell(const Types::TRect &Rect, int DataCol, TColumn* Column, Grids::TGridDrawState State);
	DYNAMIC void __fastcall EditButtonClick(void);
	void __fastcall EndLayout(void);
	void __fastcall EndUpdate(void);
	Db::TField* __fastcall GetColField(int DataCol);
	DYNAMIC int __fastcall GetEditLimit(void);
	DYNAMIC AnsiString __fastcall GetEditMask(int ACol, int ARow);
	DYNAMIC Grids::TEditStyle __fastcall GetEditStyle(int ACol, int ARow);
	DYNAMIC AnsiString __fastcall GetEditText(int ACol, int ARow);
	AnsiString __fastcall GetFieldValue(int ACol);
	virtual bool __fastcall HighlightCell(int DataCol, int DataRow, const AnsiString Value, Grids::TGridDrawState AState);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(char &Key);
	void __fastcall InvalidateTitles(void);
	virtual void __fastcall LayoutChanged(void);
	virtual void __fastcall LinkActive(bool Value);
	virtual void __fastcall Loaded(void);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall Scroll(int Distance);
	virtual void __fastcall SetColumnAttributes(void);
	DYNAMIC void __fastcall SetEditText(int ACol, int ARow, const AnsiString Value);
	bool __fastcall StoreColumns(void);
	DYNAMIC void __fastcall TimedScroll(Grids::TGridScrollDirection Direction);
	DYNAMIC void __fastcall TitleClick(TColumn* Column);
	DYNAMIC void __fastcall TopLeftChanged(void);
	bool __fastcall UseRightToLeftAlignmentForField(const Db::TField* AField, Classes::TAlignment Alignment);
	DYNAMIC bool __fastcall BeginColumnDrag(int &Origin, int &Destination, const Types::TPoint &MousePt);
	DYNAMIC bool __fastcall CheckColumnDrag(int &Origin, int &Destination, const Types::TPoint &MousePt);
	DYNAMIC bool __fastcall EndColumnDrag(int &Origin, int &Destination, const Types::TPoint &MousePt);
	__property TDBGridColumns* Columns = {read=FColumns, write=SetColumns};
	__property bool DefaultDrawing = {read=FDefaultDrawing, write=FDefaultDrawing, default=1};
	__property TGridDataLink* DataLink = {read=FDataLink};
	__property Byte IndicatorOffset = {read=FIndicatorOffset, nodefault};
	__property Byte LayoutLock = {read=FLayoutLock, nodefault};
	__property TDBGridOptions Options = {read=FOptions, write=SetOptions, default=3325};
	__property ParentColor  = {default=0};
	__property bool ReadOnly = {read=FReadOnly, write=FReadOnly, default=0};
	__property TBookmarkList* SelectedRows = {read=FBookmarks};
	__property Graphics::TFont* TitleFont = {read=FTitleFont, write=SetTitleFont};
	__property Byte UpdateLock = {read=FUpdateLock, nodefault};
	__property Classes::TNotifyEvent OnColEnter = {read=FOnColEnter, write=FOnColEnter};
	__property Classes::TNotifyEvent OnColExit = {read=FOnColExit, write=FOnColExit};
	__property TDrawDataCellEvent OnDrawDataCell = {read=FOnDrawDataCell, write=FOnDrawDataCell};
	__property TDrawColumnCellEvent OnDrawColumnCell = {read=FOnDrawColumnCell, write=FOnDrawColumnCell};
	__property Classes::TNotifyEvent OnEditButtonClick = {read=FOnEditButtonClick, write=FOnEditButtonClick};
	__property Grids::TMovedEvent OnColumnMoved = {read=FOnColumnMoved, write=FOnColumnMoved};
	__property TDBGridClickEvent OnCellClick = {read=FOnCellClick, write=FOnCellClick};
	__property TDBGridClickEvent OnTitleClick = {read=FOnTitleClick, write=FOnTitleClick};
	
public:
	__fastcall virtual TCustomDBGrid(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomDBGrid(void);
	void __fastcall DefaultDrawDataCell(const Types::TRect &Rect, Db::TField* Field, Grids::TGridDrawState State);
	void __fastcall DefaultDrawColumnCell(const Types::TRect &Rect, int DataCol, TColumn* Column, Grids::TGridDrawState State);
	virtual void __fastcall DefaultHandler(void *Msg);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	DYNAMIC void __fastcall ShowPopupEditor(TColumn* Column, int X = 0x80000000, int Y = 0x80000000);
	DYNAMIC bool __fastcall UpdateAction(Classes::TBasicAction* Action);
	bool __fastcall ValidFieldIndex(int FieldIndex);
	__property EditorMode ;
	__property int FieldCount = {read=GetFieldCount, nodefault};
	__property Db::TField* Fields[int FieldIndex] = {read=GetFields};
	__property Db::TField* SelectedField = {read=GetSelectedField, write=SetSelectedField};
	__property int SelectedIndex = {read=GetSelectedIndex, write=SetSelectedIndex, nodefault};
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomDBGrid(HWND ParentWindow) : Grids::TCustomGrid(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TDBGrid;
class PASCALIMPLEMENTATION TDBGrid : public TCustomDBGrid 
{
	typedef TCustomDBGrid inherited;
	
public:
	__property Canvas ;
	__property SelectedRows ;
	
__published:
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property BiDiMode ;
	__property BorderStyle  = {default=1};
	__property Color  = {default=-2147483643};
	__property Columns  = {stored=false};
	__property Constraints ;
	__property Ctl3D ;
	__property DataSource ;
	__property DefaultDrawing  = {default=1};
	__property DragCursor  = {default=-12};
	__property DragKind  = {default=0};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property FixedColor  = {default=-2147483633};
	__property Font ;
	__property ImeMode  = {default=3};
	__property ImeName ;
	__property Options  = {default=3325};
	__property ParentBiDiMode  = {default=1};
	__property ParentColor  = {default=0};
	__property ParentCtl3D  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ReadOnly  = {default=0};
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property TitleFont ;
	__property Visible  = {default=1};
	__property OnCellClick ;
	__property OnColEnter ;
	__property OnColExit ;
	__property OnColumnMoved ;
	__property OnDrawDataCell ;
	__property OnDrawColumnCell ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEditButtonClick ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDock ;
	__property OnStartDrag ;
	__property OnTitleClick ;
public:
	#pragma option push -w-inl
	/* TCustomDBGrid.Create */ inline __fastcall virtual TDBGrid(Classes::TComponent* AOwner) : TCustomDBGrid(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomDBGrid.Destroy */ inline __fastcall virtual ~TDBGrid(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDBGrid(HWND ParentWindow) : TCustomDBGrid(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define ColumnTitleValues (System::Set<TColumnValue, cvColor, cvImeName> () << TColumnValue(5) << TColumnValue(6) << TColumnValue(7) << TColumnValue(8) )
static const Word cm_DeferLayout = 0x464;
static const Shortint IndicatorWidth = 0xb;

}	/* namespace Dbgrids */
using namespace Dbgrids;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DBGrids
