// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QDBGrids.pas' rev: 6.00

#ifndef QDBGridsHPP
#define QDBGridsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DB.hpp>	// Pascal unit
#include <QMenus.hpp>	// Pascal unit
#include <QExtCtrls.hpp>	// Pascal unit
#include <QDBCtrls.hpp>	// Pascal unit
#include <QGrids.hpp>	// Pascal unit
#include <QImgList.hpp>	// Pascal unit
#include <QGraphics.hpp>	// Pascal unit
#include <QStdCtrls.hpp>	// Pascal unit
#include <QForms.hpp>	// Pascal unit
#include <QControls.hpp>	// Pascal unit
#include <Qt.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qdbgrids
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
	Qgraphics::TColor FColor;
	int FWidth;
	TColumnTitle* FTitle;
	Qgraphics::TFont* FFont;
	Classes::TStrings* FPickList;
	Qmenus::TPopupMenu* FPopupMenu;
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
	Qgraphics::TColor __fastcall GetColor(void);
	bool __fastcall GetExpanded(void);
	Db::TField* __fastcall GetField(void);
	Qgraphics::TFont* __fastcall GetFont(void);
	TColumn* __fastcall GetParentColumn(void);
	Classes::TStrings* __fastcall GetPickList(void);
	bool __fastcall GetReadOnly(void);
	bool __fastcall GetShowing(void);
	int __fastcall GetWidth(void);
	bool __fastcall GetVisible(void);
	bool __fastcall IsAlignmentStored(void);
	bool __fastcall IsColorStored(void);
	bool __fastcall IsFontStored(void);
	bool __fastcall IsReadOnlyStored(void);
	bool __fastcall IsWidthStored(void);
	virtual void __fastcall SetAlignment(Classes::TAlignment Value);
	void __fastcall SetButtonStyle(TColumnButtonStyle Value);
	void __fastcall SetColor(Qgraphics::TColor Value);
	void __fastcall SetExpanded(bool Value);
	virtual void __fastcall SetField(Db::TField* Value);
	void __fastcall SetFieldName(const AnsiString Value);
	void __fastcall SetFont(Qgraphics::TFont* Value);
	void __fastcall SetPickList(Classes::TStrings* Value);
	void __fastcall SetPopupMenu(Qmenus::TPopupMenu* Value);
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
	Qgraphics::TColor __fastcall DefaultColor(void);
	Qgraphics::TFont* __fastcall DefaultFont(void);
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
	__property Qgraphics::TColor Color = {read=GetColor, write=SetColor, stored=IsColorStored, nodefault};
	__property unsigned DropDownRows = {read=FDropDownRows, write=FDropDownRows, default=7};
	__property bool Expanded = {read=GetExpanded, write=SetExpanded, default=1};
	__property AnsiString FieldName = {read=FFieldName, write=SetFieldName};
	__property Qgraphics::TFont* Font = {read=GetFont, write=SetFont, stored=IsFontStored};
	__property Classes::TStrings* PickList = {read=GetPickList, write=SetPickList};
	__property Qmenus::TPopupMenu* PopupMenu = {read=FPopupMenu, write=SetPopupMenu};
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
	Qgraphics::TFont* FFont;
	Qgraphics::TColor FColor;
	Classes::TAlignment FAlignment;
	void __fastcall FontChanged(System::TObject* Sender);
	Classes::TAlignment __fastcall GetAlignment(void);
	Qgraphics::TColor __fastcall GetColor(void);
	AnsiString __fastcall GetCaption();
	Qgraphics::TFont* __fastcall GetFont(void);
	bool __fastcall IsAlignmentStored(void);
	bool __fastcall IsColorStored(void);
	bool __fastcall IsFontStored(void);
	bool __fastcall IsCaptionStored(void);
	void __fastcall SetAlignment(Classes::TAlignment Value);
	void __fastcall SetColor(Qgraphics::TColor Value);
	void __fastcall SetFont(Qgraphics::TFont* Value);
	virtual void __fastcall SetCaption(const AnsiString Value);
	
protected:
	void __fastcall RefreshDefaultFont(void);
	
public:
	__fastcall TColumnTitle(TColumn* Column);
	__fastcall virtual ~TColumnTitle(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	Classes::TAlignment __fastcall DefaultAlignment(void);
	Qgraphics::TColor __fastcall DefaultColor(void);
	Qgraphics::TFont* __fastcall DefaultFont(void);
	AnsiString __fastcall DefaultCaption();
	virtual void __fastcall RestoreDefaults(void);
	__property TColumn* Column = {read=FColumn};
	
__published:
	__property Classes::TAlignment Alignment = {read=GetAlignment, write=SetAlignment, stored=IsAlignmentStored, nodefault};
	__property AnsiString Caption = {read=GetCaption, write=SetCaption, stored=IsCaptionStored};
	__property Qgraphics::TColor Color = {read=GetColor, write=SetColor, stored=IsColorStored, nodefault};
	__property Qgraphics::TFont* Font = {read=GetFont, write=SetFont, stored=IsFontStored};
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


typedef DynamicArray<int >  QDBGrids__5;

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


class DELPHICLASS TSubGridForm;
class PASCALIMPLEMENTATION TSubGridForm : public Qcontrols::TWidgetControl 
{
	typedef Qcontrols::TWidgetControl inherited;
	
private:
	TCustomDBGrid* FSubGrid;
	
protected:
	virtual int __fastcall WidgetFlags(void);
	virtual void __fastcall InitWidget(void);
	
public:
	__fastcall TSubGridForm(Qt::QWidgetH* ParentWidget, TCustomDBGrid* AGrid);
	__property TCustomDBGrid* SubGrid = {read=FSubGrid};
public:
	#pragma option push -w-inl
	/* TWidgetControl.Create */ inline __fastcall virtual TSubGridForm(Classes::TComponent* AOwner) : Qcontrols::TWidgetControl(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWidgetControl.Destroy */ inline __fastcall virtual ~TSubGridForm(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TDBGridOption { dgEditing, dgAlwaysShowEditor, dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit, dgMultiSelect };
#pragma option pop

typedef Set<TDBGridOption, dgEditing, dgMultiSelect>  TDBGridOptions;

typedef void __fastcall (__closure *TDrawDataCellEvent)(System::TObject* Sender, const Types::TRect &Rect, Db::TField* Field, Qgrids::TGridDrawState State);

typedef void __fastcall (__closure *TDrawColumnCellEvent)(System::TObject* Sender, const Types::TRect &Rect, int DataCol, TColumn* Column, Qgrids::TGridDrawState State);

typedef void __fastcall (__closure *TDBGridClickEvent)(TColumn* Column);

class PASCALIMPLEMENTATION TCustomDBGrid : public Qgrids::TCustomGrid 
{
	typedef Qgrids::TCustomGrid inherited;
	
private:
	Qimglist::TImageList* FIndicators;
	Qgraphics::TFont* FTitleFont;
	bool FReadOnly;
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
	TDBGridColumns* FColumns;
	Classes::TList* FVisibleColumns;
	TBookmarkList* FBookmarks;
	AnsiString FSelectionAnchor;
	Classes::TNotifyEvent FOnEditButtonClick;
	Qgrids::TMovedEvent FOnColumnMoved;
	TDBGridClickEvent FOnCellClick;
	TDBGridClickEvent FOnTitleClick;
	TColumn* FDragCol;
	bool FTextLocked;
	bool FDatasetLocked;
	bool __fastcall IsRightToLeft(void);
	HIDESBASE bool __fastcall UseRightToLeftAlignment(void);
	AnsiString __fastcall GetInPlaceEditText();
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
	void __fastcall SetColumns(TDBGridColumns* Value);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	HIDESBASE void __fastcall SetOptions(TDBGridOptions Value);
	void __fastcall SetSelectedField(Db::TField* Value);
	void __fastcall SetSelectedIndex(int Value);
	void __fastcall SetTitleFont(Qgraphics::TFont* Value);
	void __fastcall TitleFontChanged(System::TObject* Sender);
	void __fastcall UpdateData(void);
	void __fastcall UpdateActive(void);
	void __fastcall UpdateScrollBar(void);
	void __fastcall UpdateRowCount(void);
	void __fastcall WriteColumns(Classes::TWriter* Writer);
	
protected:
	bool FUpdateFields;
	bool FAcquireFocus;
	DYNAMIC void __fastcall BoundsChanged(void);
	DYNAMIC bool __fastcall CalcScrollBarVisible(Qstdctrls::TScrollStyle ScrollBar, const Qgrids::TGridAxisDrawInfo &AxisInfo, int Max);
	DYNAMIC void __fastcall DoExit(void);
	virtual bool __fastcall EventFilter(Qt::QObjectH* Sender, Qt::QEventH* Event);
	DYNAMIC void __fastcall FontChanged(void);
	virtual bool __fastcall IsActiveControl(void);
	virtual void __fastcall ModifyScrollBar(Qforms::TScrollBarKind ScrollBar, Qstdctrls::TScrollCode ScrollCode, unsigned Pos, bool UseRightToLeft);
	DYNAMIC void __fastcall ParentFontChanged(void);
	int __fastcall RawToDataColumn(int ACol);
	int __fastcall DataToRawColumn(int ACol);
	bool __fastcall AcquireLayoutLock(void);
	void __fastcall BeginLayout(void);
	void __fastcall BeginUpdate(void);
	virtual void __fastcall CalcSizingState(int X, int Y, Qgrids::TGridState &State, int &Index, int &SizingPos, int &SizingOfs, Qgrids::TGridDrawInfo &FixedInfo);
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
	virtual Qgrids::TInplaceEdit* __fastcall CreateEditor(void);
	void __fastcall DeferLayout(void);
	virtual void __fastcall DefineFieldMap(void);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual void __fastcall DrawCell(int ACol, int ARow, const Types::TRect &ARect, Qgrids::TGridDrawState AState);
	DYNAMIC void __fastcall DrawDataCell(const Types::TRect &Rect, Db::TField* Field, Qgrids::TGridDrawState State);
	DYNAMIC void __fastcall DrawColumnCell(const Types::TRect &Rect, int DataCol, TColumn* Column, Qgrids::TGridDrawState State);
	DYNAMIC void __fastcall EditButtonClick(void);
	void __fastcall EndLayout(void);
	void __fastcall EndUpdate(void);
	Db::TField* __fastcall GetColField(int DataCol);
	DYNAMIC int __fastcall GetEditLimit(void);
	DYNAMIC WideString __fastcall GetEditMask(int ACol, int ARow);
	DYNAMIC WideString __fastcall GetEditText(int ACol, int ARow);
	AnsiString __fastcall GetFieldValue(int ACol);
	virtual bool __fastcall HighlightCell(int DataCol, int DataRow, const AnsiString Value, Qgrids::TGridDrawState AState);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	virtual void __fastcall GridKeyPress(char &Key);
	void __fastcall InvalidateTitles(void);
	virtual void __fastcall LayoutChanged(void);
	virtual void __fastcall LinkActive(bool Value);
	virtual void __fastcall Loaded(void);
	DYNAMIC void __fastcall MouseDown(Qcontrols::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Qcontrols::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall Scroll(int Distance);
	virtual void __fastcall SetColumnAttributes(void);
	DYNAMIC void __fastcall SetEditText(int ACol, int ARow, const WideString Value);
	bool __fastcall StoreColumns(void);
	DYNAMIC void __fastcall TimedScroll(Qgrids::TGridScrollDirection Direction);
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
	__property Qgraphics::TFont* TitleFont = {read=FTitleFont, write=SetTitleFont};
	__property Byte UpdateLock = {read=FUpdateLock, nodefault};
	__property Classes::TNotifyEvent OnColEnter = {read=FOnColEnter, write=FOnColEnter};
	__property Classes::TNotifyEvent OnColExit = {read=FOnColExit, write=FOnColExit};
	__property TDrawDataCellEvent OnDrawDataCell = {read=FOnDrawDataCell, write=FOnDrawDataCell};
	__property TDrawColumnCellEvent OnDrawColumnCell = {read=FOnDrawColumnCell, write=FOnDrawColumnCell};
	__property Classes::TNotifyEvent OnEditButtonClick = {read=FOnEditButtonClick, write=FOnEditButtonClick};
	__property Qgrids::TMovedEvent OnColumnMoved = {read=FOnColumnMoved, write=FOnColumnMoved};
	__property TDBGridClickEvent OnCellClick = {read=FOnCellClick, write=FOnCellClick};
	__property TDBGridClickEvent OnTitleClick = {read=FOnTitleClick, write=FOnTitleClick};
	
public:
	__fastcall virtual TCustomDBGrid(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomDBGrid(void);
	void __fastcall DefaultDrawDataCell(const Types::TRect &Rect, Db::TField* Field, Qgrids::TGridDrawState State);
	void __fastcall DefaultDrawColumnCell(const Types::TRect &Rect, int DataCol, TColumn* Column, Qgrids::TGridDrawState State);
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
	/* TWidgetControl.CreateParented */ inline __fastcall TCustomDBGrid(Qt::QWidgetH* ParentWidget) : Qgrids::TCustomGrid(ParentWidget) { }
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
	__property BorderStyle  = {default=1};
	__property Color  = {default=-10};
	__property Columns  = {stored=false};
	__property Constraints ;
	__property DataSource ;
	__property DefaultDrawing  = {default=1};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property FixedColor  = {default=-2};
	__property Font ;
	__property Options  = {default=3325};
	__property ParentColor  = {default=0};
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
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyString ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
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
	/* TWidgetControl.CreateParented */ inline __fastcall TDBGrid(Qt::QWidgetH* ParentWidget) : TCustomDBGrid(ParentWidget) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define ColumnTitleValues (System::Set<TColumnValue, cvColor, cvImeName> () << TColumnValue(5) << TColumnValue(6) << TColumnValue(7) << TColumnValue(8) )
static const Shortint IndicatorWidth = 0xb;

}	/* namespace Qdbgrids */
using namespace Qdbgrids;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QDBGrids
