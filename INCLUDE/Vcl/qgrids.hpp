// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QGrids.pas' rev: 6.00

#ifndef QGridsHPP
#define QGridsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QMask.hpp>	// Pascal unit
#include <QExtCtrls.hpp>	// Pascal unit
#include <QStdCtrls.hpp>	// Pascal unit
#include <QForms.hpp>	// Pascal unit
#include <QControls.hpp>	// Pascal unit
#include <QMenus.hpp>	// Pascal unit
#include <QGraphics.hpp>	// Pascal unit
#include <Qt.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qgrids
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EInvalidGridOperation;
class PASCALIMPLEMENTATION EInvalidGridOperation : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EInvalidGridOperation(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EInvalidGridOperation(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EInvalidGridOperation(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EInvalidGridOperation(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EInvalidGridOperation(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalidGridOperation(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EInvalidGridOperation(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidGridOperation(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EInvalidGridOperation(void) { }
	#pragma option pop
	
};


typedef int __fastcall (__closure *TGetExtentsFunc)(int Index);

struct TGridAxisDrawInfo
{
	int EffectiveLineWidth;
	int FixedBoundary;
	int GridBoundary;
	int GridExtent;
	int LastFullVisibleCell;
	int FullVisBoundary;
	int FixedCellCount;
	int FirstGridCell;
	int GridCellCount;
	TGetExtentsFunc GetExtent;
} ;

struct TGridDrawInfo
{
	TGridAxisDrawInfo Horz;
	TGridAxisDrawInfo Vert;
} ;

#pragma option push -b-
enum TGridState { gsNormal, gsSelecting, gsRowSizing, gsColSizing, gsRowMoving, gsColMoving };
#pragma option pop

typedef TGridState TGridMovement;

class DELPHICLASS TInplaceEdit;
class DELPHICLASS TCustomGrid;
#pragma pack(push, 4)
struct TGridCoord
{
	int X;
	int Y;
} ;
#pragma pack(pop)

class DELPHICLASS TGridScrollBar;
class PASCALIMPLEMENTATION TGridScrollBar : public Qstdctrls::TScrollBar 
{
	typedef Qstdctrls::TScrollBar inherited;
	
private:
	TCustomGrid* FGrid;
	bool FInternalVisible;
	bool FUpdating;
	bool __fastcall GetVisible(void);
	HIDESBASE void __fastcall SetVisible(bool Value);
	
protected:
	virtual void __fastcall InitWidget(void);
	DYNAMIC void __fastcall WidgetDestroyed(void);
	
public:
	__fastcall virtual TGridScrollBar(Classes::TComponent* AOwner);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	DYNAMIC bool __fastcall CanFocus(void);
	__property bool Visible = {read=GetVisible, write=SetVisible, nodefault};
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TGridScrollBar(Qt::QWidgetH* ParentWidget) : Qstdctrls::TScrollBar(ParentWidget) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWidgetControl.Destroy */ inline __fastcall virtual ~TGridScrollBar(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TGridOption { goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goRowSizing, goColSizing, goRowMoving, goColMoving, goEditing, goTabs, goRowSelect, goAlwaysShowEditor, goThumbTracking };
#pragma option pop

typedef Set<TGridOption, goFixedVertLine, goThumbTracking>  TGridOptions;

struct TGridRect;
#pragma option push -b-
enum QGrids__3 { gdSelected, gdFocused, gdFixed };
#pragma option pop

typedef Set<QGrids__3, gdSelected, gdFixed>  TGridDrawState;

#pragma option push -b-
enum QGrids__4 { sdLeft, sdRight, sdUp, sdDown };
#pragma option pop

typedef Set<QGrids__4, sdLeft, sdDown>  TGridScrollDirection;

class PASCALIMPLEMENTATION TCustomGrid : public Qcontrols::TCustomControl 
{
	typedef Qcontrols::TCustomControl inherited;
	
private:
	TGridCoord FAnchor;
	Qcontrols::TBorderStyle FBorderStyle;
	bool FCanEditModify;
	int FColCount;
	void *FColWidths;
	void *FTabStops;
	TGridCoord FCurrent;
	int FDefaultColWidth;
	int FDefaultRowHeight;
	int FFixedCols;
	int FFixedRows;
	Qgraphics::TColor FFixedColor;
	int FGridLineWidth;
	TGridScrollBar* FHScrollBar;
	TGridOptions FOptions;
	int FRowCount;
	void *FRowHeights;
	Qstdctrls::TScrollStyle FScrollBars;
	TGridCoord FTopLeft;
	int FSizingIndex;
	int FSizingPos;
	int FSizingOfs;
	TGridScrollBar* FVScrollBar;
	int FMoveIndex;
	int FMovePos;
	TInplaceEdit* FInplaceEdit;
	int FInplaceCol;
	int FInplaceRow;
	int FColOffset;
	bool FDefaultDrawing;
	bool FEditorMode;
	Qextctrls::TTimer* FTimer;
	bool FScrollBarsLocked;
	int __fastcall GetBorderSize(void);
	void __fastcall ScrollEvent(System::TObject* Sender, Qstdctrls::TScrollCode ScrollCode, int &ScrollPos);
	void __fastcall SetScrollRange(Qforms::TScrollBarKind ScrollBar, int Min, int Max);
	bool __fastcall UseRightToLeftAlignment(void);
	void __fastcall TimerEvent(System::TObject* Sender);
	HIDESBASE MESSAGE void __fastcall CMKeyDown(Qcontrols::TCMKeyDown &Msg);
	TGridCoord __fastcall CalcCoordFromPoint(int X, int Y, const TGridDrawInfo &DrawInfo);
	void __fastcall CalcDrawInfoXY(TGridDrawInfo &DrawInfo, int UseWidth, int UseHeight);
	TGridCoord __fastcall CalcMaxTopLeft(const TGridCoord &Coord, const TGridDrawInfo &DrawInfo);
	void __fastcall ChangeGridOrientation(bool RightToLeftOrientation);
	void __fastcall ChangeSize(int NewColCount, int NewRowCount);
	void __fastcall ClampInView(const TGridCoord &Coord);
	void __fastcall DrawSizingLine(const TGridDrawInfo &DrawInfo);
	void __fastcall DrawMove(void);
	void __fastcall FocusCell(int ACol, int ARow, bool MoveAnchor);
	void __fastcall GridRectToScreenRect(const TGridRect &GridRect, Types::TRect &ScreenRect, bool IncludeLine);
	void __fastcall HideEdit(void);
	void __fastcall Initialize(void);
	void __fastcall InvalidateGrid(void);
	HIDESBASE void __fastcall InvalidateRect(const TGridRect &ARect);
	void __fastcall MoveAdjust(int &CellPos, int FromIndex, int ToIndex);
	void __fastcall MoveAnchor(const TGridCoord &NewAnchor);
	void __fastcall MoveAndScroll(int Mouse, int CellHit, TGridDrawInfo &DrawInfo, TGridAxisDrawInfo &Axis, Qforms::TScrollBarKind Scrollbar, const Types::TPoint &MousePt);
	void __fastcall MoveCurrent(int ACol, int ARow, bool MoveAnchor, bool Show);
	void __fastcall MoveTopLeft(int ALeft, int ATop);
	void __fastcall ResizeCol(int Index, int OldSize, int NewSize);
	void __fastcall ResizeRow(int Index, int OldSize, int NewSize);
	void __fastcall SelectionMoved(const TGridRect &OldSel);
	void __fastcall ScrollDataInfo(int DX, int DY, TGridDrawInfo &DrawInfo);
	void __fastcall TopLeftMoved(const TGridCoord &OldTopLeft);
	void __fastcall UpdateScrollPos(void);
	void __fastcall UpdateScrollRange(void);
	int __fastcall GetColWidths(int Index);
	int __fastcall GetRowHeights(int Index);
	TGridRect __fastcall GetSelection();
	bool __fastcall GetTabStops(int Index);
	int __fastcall GetVisibleColCount(void);
	int __fastcall GetVisibleRowCount(void);
	void __fastcall ReadColWidths(Classes::TReader* Reader);
	void __fastcall ReadRowHeights(Classes::TReader* Reader);
	void __fastcall SetBorderStyle(Qcontrols::TControlBorderStyle Value);
	void __fastcall SetCol(int Value);
	void __fastcall SetColCount(int Value);
	void __fastcall SetColWidths(int Index, int Value);
	void __fastcall SetDefaultColWidth(int Value);
	void __fastcall SetDefaultRowHeight(int Value);
	void __fastcall SetEditorMode(bool Value);
	void __fastcall SetFixedColor(Qgraphics::TColor Value);
	void __fastcall SetFixedCols(int Value);
	void __fastcall SetFixedRows(int Value);
	void __fastcall SetGridLineWidth(int Value);
	void __fastcall SetLeftCol(int Value);
	void __fastcall SetOptions(TGridOptions Value);
	void __fastcall SetRow(int Value);
	void __fastcall SetRowCount(int Value);
	void __fastcall SetRowHeights(int Index, int Value);
	void __fastcall SetScrollBars(Qstdctrls::TScrollStyle Value);
	void __fastcall SetSelection(const TGridRect &Value);
	void __fastcall SetTabStops(int Index, bool Value);
	void __fastcall SetTopRow(int Value);
	void __fastcall UpdateEdit(void);
	void __fastcall UpdateText(void);
	void __fastcall WriteColWidths(Classes::TWriter* Writer);
	void __fastcall WriteRowHeights(Classes::TWriter* Writer);
	
protected:
	TGridState FGridState;
	bool FSaveCellExtents;
	TGridOptions DesignOptionsBoost;
	bool VirtualView;
	DYNAMIC void __fastcall BoundsChanged(void);
	DYNAMIC bool __fastcall CalcScrollBarVisible(Qstdctrls::TScrollStyle ScrollBar, const TGridAxisDrawInfo &AxisInfo, int Max);
	virtual TGridScrollBar* __fastcall CreateScrollBar(void);
	DYNAMIC void __fastcall DoEnter(void);
	virtual Types::TRect __fastcall GetClientRect();
	DYNAMIC void __fastcall FontChanged(void);
	virtual bool __fastcall IsActiveControl(void);
	virtual void __fastcall ModifyScrollBar(Qforms::TScrollBarKind ScrollBar, Qstdctrls::TScrollCode ScrollCode, unsigned Pos, bool UseRightToLeft);
	virtual bool __fastcall PtInGrid(const Types::TPoint &p);
	void __fastcall UpdateScrollBars(void);
	DYNAMIC void __fastcall VisibleChanged(void);
	virtual int __fastcall WidgetFlags(void);
	__property bool ScrollBarsLocked = {read=FScrollBarsLocked, write=FScrollBarsLocked, nodefault};
	__property TGridScrollBar* HScrollBar = {read=FHScrollBar};
	__property TGridScrollBar* VScrollBar = {read=FVScrollBar};
	void __fastcall CalcDrawInfo(TGridDrawInfo &DrawInfo);
	void __fastcall CalcFixedInfo(TGridDrawInfo &DrawInfo);
	virtual void __fastcall CalcSizingState(int X, int Y, TGridState &State, int &Index, int &SizingPos, int &SizingOfs, TGridDrawInfo &FixedInfo);
	virtual TInplaceEdit* __fastcall CreateEditor(void);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(char &Key);
	virtual void __fastcall GridKeyPress(char &Key);
	DYNAMIC void __fastcall MouseDown(Qcontrols::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Qcontrols::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	HIDESBASEDYNAMIC void __fastcall AdjustSize(int Index, int Amount, bool Rows);
	Types::TRect __fastcall BoxRect(int ALeft, int ATop, int ARight, int ABottom);
	DYNAMIC void __fastcall DoExit(void);
	Types::TRect __fastcall CellRect(int ACol, int ARow);
	DYNAMIC bool __fastcall CanEditAcceptKey(char Key);
	DYNAMIC bool __fastcall CanGridAcceptKey(Word Key, Classes::TShiftState Shift);
	DYNAMIC bool __fastcall CanEditModify(void);
	virtual bool __fastcall CanEditShow(void);
	DYNAMIC bool __fastcall DoMouseWheelDown(Classes::TShiftState Shift, const Types::TPoint &MousePos);
	DYNAMIC bool __fastcall DoMouseWheelUp(Classes::TShiftState Shift, const Types::TPoint &MousePos);
	DYNAMIC WideString __fastcall GetEditText(int ACol, int ARow);
	DYNAMIC void __fastcall SetEditText(int ACol, int ARow, const WideString Value);
	DYNAMIC WideString __fastcall GetEditMask(int ACol, int ARow);
	DYNAMIC int __fastcall GetEditLimit(void);
	int __fastcall GetGridWidth(void);
	int __fastcall GetGridHeight(void);
	void __fastcall HideEditor(void);
	void __fastcall ShowEditor(void);
	void __fastcall ShowEditorChar(char &Ch);
	void __fastcall InvalidateEditor(void);
	void __fastcall MoveColumn(int FromIndex, int ToIndex);
	DYNAMIC void __fastcall ColumnMoved(int FromIndex, int ToIndex);
	void __fastcall MoveRow(int FromIndex, int ToIndex);
	DYNAMIC void __fastcall RowMoved(int FromIndex, int ToIndex);
	virtual void __fastcall DrawCell(int ACol, int ARow, const Types::TRect &ARect, TGridDrawState AState) = 0 ;
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	void __fastcall MoveColRow(int ACol, int ARow, bool MoveAnchor, bool Show);
	virtual bool __fastcall SelectCell(int ACol, int ARow);
	DYNAMIC void __fastcall SizeChanged(int OldColCount, int OldRowCount);
	bool __fastcall Sizing(int X, int Y);
	void __fastcall ScrollData(int DX, int DY);
	void __fastcall InvalidateCell(int ACol, int ARow);
	void __fastcall InvalidateCol(int ACol);
	void __fastcall InvalidateRow(int ARow);
	DYNAMIC void __fastcall TopLeftChanged(void);
	DYNAMIC void __fastcall TimedScroll(TGridScrollDirection Direction);
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall ColWidthsChanged(void);
	DYNAMIC void __fastcall RowHeightsChanged(void);
	virtual void __fastcall DeleteColumn(int ACol);
	virtual void __fastcall DeleteRow(int ARow);
	void __fastcall UpdateDesigner(void);
	DYNAMIC bool __fastcall BeginColumnDrag(int &Origin, int &Destination, const Types::TPoint &MousePt);
	DYNAMIC bool __fastcall BeginRowDrag(int &Origin, int &Destination, const Types::TPoint &MousePt);
	DYNAMIC bool __fastcall CheckColumnDrag(int &Origin, int &Destination, const Types::TPoint &MousePt);
	DYNAMIC bool __fastcall CheckRowDrag(int &Origin, int &Destination, const Types::TPoint &MousePt);
	DYNAMIC bool __fastcall EndColumnDrag(int &Origin, int &Destination, const Types::TPoint &MousePt);
	DYNAMIC bool __fastcall EndRowDrag(int &Origin, int &Destination, const Types::TPoint &MousePt);
	__property int BorderSize = {read=GetBorderSize, nodefault};
	__property Qcontrols::TControlBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, default=1};
	__property int Col = {read=FCurrent.X, write=SetCol, nodefault};
	__property Color  = {default=-10};
	__property int ColCount = {read=FColCount, write=SetColCount, default=5};
	__property int ColWidths[int Index] = {read=GetColWidths, write=SetColWidths};
	__property int DefaultColWidth = {read=FDefaultColWidth, write=SetDefaultColWidth, default=64};
	__property bool DefaultDrawing = {read=FDefaultDrawing, write=FDefaultDrawing, default=1};
	__property int DefaultRowHeight = {read=FDefaultRowHeight, write=SetDefaultRowHeight, default=24};
	__property bool EditorMode = {read=FEditorMode, write=SetEditorMode, nodefault};
	__property Qgraphics::TColor FixedColor = {read=FFixedColor, write=SetFixedColor, default=-2};
	__property int FixedCols = {read=FFixedCols, write=SetFixedCols, default=1};
	__property int FixedRows = {read=FFixedRows, write=SetFixedRows, default=1};
	__property int GridHeight = {read=GetGridHeight, nodefault};
	__property int GridLineWidth = {read=FGridLineWidth, write=SetGridLineWidth, default=1};
	__property int GridWidth = {read=GetGridWidth, nodefault};
	__property TInplaceEdit* InplaceEditor = {read=FInplaceEdit};
	__property int LeftCol = {read=FTopLeft.X, write=SetLeftCol, nodefault};
	__property TGridOptions Options = {read=FOptions, write=SetOptions, default=31};
	__property ParentColor  = {default=0};
	__property int Row = {read=FCurrent.Y, write=SetRow, nodefault};
	__property int RowCount = {read=FRowCount, write=SetRowCount, default=5};
	__property int RowHeights[int Index] = {read=GetRowHeights, write=SetRowHeights};
	__property Qstdctrls::TScrollStyle ScrollBars = {read=FScrollBars, write=SetScrollBars, default=3};
	__property TGridRect Selection = {read=GetSelection, write=SetSelection};
	__property bool TabStops[int Index] = {read=GetTabStops, write=SetTabStops};
	__property int TopRow = {read=FTopLeft.Y, write=SetTopRow, nodefault};
	__property int VisibleColCount = {read=GetVisibleColCount, nodefault};
	__property int VisibleRowCount = {read=GetVisibleRowCount, nodefault};
	
public:
	__fastcall virtual TCustomGrid(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomGrid(void);
	TGridCoord __fastcall MouseCoord(int X, int Y);
	
__published:
	__property TabStop  = {default=1};
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TCustomGrid(Qt::QWidgetH* ParentWidget) : Qcontrols::TCustomControl(ParentWidget) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TInplaceEdit : public Qmask::TCustomMaskEdit 
{
	typedef Qmask::TCustomMaskEdit inherited;
	
private:
	TCustomGrid* FGrid;
	HIDESBASE MESSAGE void __fastcall CMKeyDown(Qcontrols::TCMKeyDown &Msg);
	void __fastcall InternalMove(const Types::TRect &Loc, bool Redraw);
	void __fastcall SetGrid(TCustomGrid* Value);
	bool __fastcall GetVisible(void);
	HIDESBASE void __fastcall SetVisible(bool Value);
	
protected:
	virtual void __fastcall Change(void);
	DYNAMIC void __fastcall DblClick(void);
	DYNAMIC bool __fastcall DoMouseWheel(Classes::TShiftState Shift, int WheelDelta, const Types::TPoint &MousePos);
	virtual bool __fastcall EditCanModify(void);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(char &Key);
	DYNAMIC void __fastcall KeyUp(Word &Key, Classes::TShiftState Shift);
	virtual void __fastcall UpdateContents(void);
	DYNAMIC bool __fastcall NeedKey(int Key, Classes::TShiftState Shift, const WideString KeyText);
	__property TCustomGrid* Grid = {read=FGrid};
	
public:
	__fastcall virtual TInplaceEdit(Classes::TComponent* AOwner);
	void __fastcall Deselect(void);
	HIDESBASE void __fastcall Hide(void);
	HIDESBASE void __fastcall Invalidate(void);
	void __fastcall Move(const Types::TRect &Loc);
	bool __fastcall PosEqual(const Types::TRect &Rect);
	HIDESBASE void __fastcall SetFocus(void);
	void __fastcall UpdateLoc(const Types::TRect &Loc);
	__property bool Visible = {read=GetVisible, write=SetVisible, nodefault};
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TInplaceEdit(Qt::QWidgetH* ParentWidget) : Qmask::TCustomMaskEdit(ParentWidget) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWidgetControl.Destroy */ inline __fastcall virtual ~TInplaceEdit(void) { }
	#pragma option pop
	
};


#pragma pack(push, 4)
struct TGridRect
{
	
	union
	{
		struct 
		{
			TGridCoord TopLeft;
			TGridCoord BottomRight;
			
		};
		struct 
		{
			int Left;
			int Top;
			int Right;
			int Bottom;
			
		};
		
	};
} ;
#pragma pack(pop)

typedef void __fastcall (__closure *TSelectCellEvent)(System::TObject* Sender, int ACol, int ARow, bool &CanSelect);

typedef void __fastcall (__closure *TDrawCellEvent)(System::TObject* Sender, int ACol, int ARow, const Types::TRect &Rect, TGridDrawState State);

typedef void __fastcall (__closure *TGetEditEvent)(System::TObject* Sender, int ACol, int ARow, WideString &Value);

typedef void __fastcall (__closure *TSetEditEvent)(System::TObject* Sender, int ACol, int ARow, const WideString Value);

typedef void __fastcall (__closure *TMovedEvent)(System::TObject* Sender, int FromIndex, int ToIndex);

class DELPHICLASS TDrawGrid;
class PASCALIMPLEMENTATION TDrawGrid : public TCustomGrid 
{
	typedef TCustomGrid inherited;
	
private:
	TMovedEvent FOnColumnMoved;
	TDrawCellEvent FOnDrawCell;
	TGetEditEvent FOnGetEditMask;
	TGetEditEvent FOnGetEditText;
	TMovedEvent FOnRowMoved;
	TSelectCellEvent FOnSelectCell;
	TSetEditEvent FOnSetEditText;
	Classes::TNotifyEvent FOnTopLeftChanged;
	
protected:
	DYNAMIC void __fastcall ColumnMoved(int FromIndex, int ToIndex);
	virtual void __fastcall DrawCell(int ACol, int ARow, const Types::TRect &ARect, TGridDrawState AState);
	DYNAMIC WideString __fastcall GetEditMask(int ACol, int ARow);
	DYNAMIC WideString __fastcall GetEditText(int ACol, int ARow);
	DYNAMIC void __fastcall RowMoved(int FromIndex, int ToIndex);
	virtual bool __fastcall SelectCell(int ACol, int ARow);
	DYNAMIC void __fastcall SetEditText(int ACol, int ARow, const WideString Value);
	DYNAMIC void __fastcall TopLeftChanged(void);
	
public:
	HIDESBASE Types::TRect __fastcall CellRect(int ACol, int ARow);
	void __fastcall MouseToCell(int X, int Y, int &ACol, int &ARow);
	__property Canvas ;
	__property Col ;
	__property ColWidths ;
	__property EditorMode ;
	__property GridHeight ;
	__property GridWidth ;
	__property LeftCol ;
	__property Selection ;
	__property Row ;
	__property RowHeights ;
	__property TabStops ;
	__property TopRow ;
	__property VisibleColCount ;
	__property VisibleRowCount ;
	
__published:
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property BorderStyle  = {default=1};
	__property Color  = {default=-10};
	__property ColCount  = {default=5};
	__property Constraints ;
	__property DefaultColWidth  = {default=64};
	__property DefaultRowHeight  = {default=24};
	__property DefaultDrawing  = {default=1};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property FixedColor  = {default=-2};
	__property FixedCols  = {default=1};
	__property RowCount  = {default=5};
	__property FixedRows  = {default=1};
	__property Font ;
	__property GridLineWidth  = {default=1};
	__property Options  = {default=31};
	__property ParentColor  = {default=0};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ScrollBars  = {default=3};
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Visible  = {default=1};
	__property OnClick ;
	__property TMovedEvent OnColumnMoved = {read=FOnColumnMoved, write=FOnColumnMoved};
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property TDrawCellEvent OnDrawCell = {read=FOnDrawCell, write=FOnDrawCell};
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property TGetEditEvent OnGetEditMask = {read=FOnGetEditMask, write=FOnGetEditMask};
	__property TGetEditEvent OnGetEditText = {read=FOnGetEditText, write=FOnGetEditText};
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyString ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnMouseWheelDown ;
	__property OnMouseWheelUp ;
	__property TMovedEvent OnRowMoved = {read=FOnRowMoved, write=FOnRowMoved};
	__property TSelectCellEvent OnSelectCell = {read=FOnSelectCell, write=FOnSelectCell};
	__property TSetEditEvent OnSetEditText = {read=FOnSetEditText, write=FOnSetEditText};
	__property OnStartDrag ;
	__property Classes::TNotifyEvent OnTopLeftChanged = {read=FOnTopLeftChanged, write=FOnTopLeftChanged};
public:
	#pragma option push -w-inl
	/* TCustomGrid.Create */ inline __fastcall virtual TDrawGrid(Classes::TComponent* AOwner) : TCustomGrid(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomGrid.Destroy */ inline __fastcall virtual ~TDrawGrid(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TDrawGrid(Qt::QWidgetH* ParentWidget) : TCustomGrid(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS TStringGridStrings;
class DELPHICLASS TStringGrid;
class PASCALIMPLEMENTATION TStringGrid : public TDrawGrid 
{
	typedef TDrawGrid inherited;
	
private:
	void *FData;
	void *FRows;
	void *FCols;
	bool FUpdating;
	bool FNeedsUpdating;
	int FEditUpdate;
	void __fastcall DisableEditUpdate(void);
	void __fastcall EnableEditUpdate(void);
	HIDESBASE void __fastcall Initialize(void);
	HIDESBASE void __fastcall Update(int ACol, int ARow);
	void __fastcall SetUpdateState(bool Updating);
	WideString __fastcall GetCells(int ACol, int ARow);
	Classes::TStrings* __fastcall GetCols(int Index);
	System::TObject* __fastcall GetObjects(int ACol, int ARow);
	Classes::TStrings* __fastcall GetRows(int Index);
	void __fastcall SetCells(int ACol, int ARow, const WideString Value);
	void __fastcall SetCols(int Index, Classes::TStrings* Value);
	void __fastcall SetObjects(int ACol, int ARow, System::TObject* Value);
	void __fastcall SetRows(int Index, Classes::TStrings* Value);
	TStringGridStrings* __fastcall EnsureColRow(int Index, bool IsCol);
	void * __fastcall EnsureDataRow(int ARow);
	
protected:
	DYNAMIC void __fastcall ColumnMoved(int FromIndex, int ToIndex);
	virtual void __fastcall DrawCell(int ACol, int ARow, const Types::TRect &ARect, TGridDrawState AState);
	DYNAMIC WideString __fastcall GetEditText(int ACol, int ARow);
	DYNAMIC void __fastcall SetEditText(int ACol, int ARow, const WideString Value);
	DYNAMIC void __fastcall RowMoved(int FromIndex, int ToIndex);
	
public:
	__fastcall virtual TStringGrid(Classes::TComponent* AOwner);
	__fastcall virtual ~TStringGrid(void);
	__property WideString Cells[int ACol][int ARow] = {read=GetCells, write=SetCells};
	__property Classes::TStrings* Cols[int Index] = {read=GetCols, write=SetCols};
	__property System::TObject* Objects[int ACol][int ARow] = {read=GetObjects, write=SetObjects};
	__property Classes::TStrings* Rows[int Index] = {read=GetRows, write=SetRows};
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TStringGrid(Qt::QWidgetH* ParentWidget) : TDrawGrid(ParentWidget) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TStringGridStrings : public Classes::TStrings 
{
	typedef Classes::TStrings inherited;
	
private:
	TStringGrid* FGrid;
	int FIndex;
	void __fastcall CalcXY(int Index, int &X, int &Y);
	
protected:
	virtual AnsiString __fastcall Get(int Index);
	virtual int __fastcall GetCount(void);
	virtual System::TObject* __fastcall GetObject(int Index);
	virtual void __fastcall Put(int Index, const AnsiString S);
	virtual void __fastcall PutObject(int Index, System::TObject* AObject);
	virtual void __fastcall SetUpdateState(bool Updating);
	
public:
	__fastcall TStringGridStrings(TStringGrid* AGrid, int AIndex);
	virtual int __fastcall Add(const AnsiString S);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall Clear(void);
	virtual void __fastcall Delete(int Index);
	virtual void __fastcall Insert(int Index, const AnsiString S);
public:
	#pragma option push -w-inl
	/* TStrings.Destroy */ inline __fastcall virtual ~TStringGridStrings(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const int MaxCustomExtents = 0x7ffffff;
static const Shortint MaxShortInt = 0x7f;

}	/* namespace Qgrids */
using namespace Qgrids;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QGrids
