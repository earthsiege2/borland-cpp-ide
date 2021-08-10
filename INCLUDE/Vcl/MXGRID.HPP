// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'MXGRID.pas' rev: 6.00

#ifndef MXGRIDHPP
#define MXGRIDHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ImgList.hpp>	// Pascal unit
#include <MXCOMMON.hpp>	// Pascal unit
#include <MXBUTTON.hpp>	// Pascal unit
#include <MXDB.hpp>	// Pascal unit
#include <Mxconsts.hpp>	// Pascal unit
#include <Mxarrays.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Grids.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Mxgrid
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TValueArray;
class PASCALIMPLEMENTATION TValueArray : public Mxarrays::TSmallIntArray 
{
	typedef Mxarrays::TSmallIntArray inherited;
	
public:
	#pragma option push -w-inl
	/* TSmallIntArray.Create */ inline __fastcall virtual TValueArray(int itemcount, int dummy) : Mxarrays::TSmallIntArray(itemcount, dummy) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TBaseArray.Destroy */ inline __fastcall virtual ~TValueArray(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TDecisionGridOption { cgGridLines, cgOutliner, cgPivotable };
#pragma option pop

typedef Set<TDecisionGridOption, cgGridLines, cgPivotable>  TDecisionGridOptions;

#pragma option push -b-
enum TDecisionGridState { csNormal, csPivoting };
#pragma option pop

#pragma option push -b-
enum TDecisionDrawStates { dsGroupStart, dsRowCaption, dsColCaption, dsSum, dsRowValue, dsColValue, dsData, dsOpenAfter, dsCloseAfter, dsCloseBefore, dsOpenBefore, dsRowIndicator, dsColIndicator, dsRowPlus, dsColPlus, dsNone };
#pragma option pop

#pragma option push -b-
enum TDecisionPivotState { psNone, psLeftPivot, psMiddlePivot, psRightPivot, psTopPivot };
#pragma option pop

typedef Set<TDecisionDrawStates, dsGroupStart, dsNone>  TDecisionDrawState;

typedef void __fastcall (__closure *TDecisionDrawCellEvent)(System::TObject* Sender, int Col, int Row, AnsiString &Value, Graphics::TFont* &aFont, Graphics::TColor &aColor, Grids::TGridDrawState AState, TDecisionDrawState aDrawState);

typedef void __fastcall (__closure *TDecisionExamineCellEvent)(System::TObject* Sender, int iCol, int iRow, int iSum, const TValueArray* ValueArray);

#pragma option push -b-
enum TDecisionCellType { ctNone, ctCaptionRow, ctCaptionCol, ctNewCaptionCol, ctRowLabel, ctColLabel, ctData, ctRowPlus, ctColPlus, ctRowIndicator, ctColIndicator };
#pragma option pop

#pragma option push -b-
enum TButtonPlace { bpLeft, bpMiddle, bpRight };
#pragma option pop

class DELPHICLASS TDecisionGridDataLink;
class DELPHICLASS TCustomDecisionGrid;
class DELPHICLASS TDisplayDims;
class DELPHICLASS TDisplayDim;
typedef TMetaClass*TDisplayDimClass;

#pragma option push -b-
enum TDDNotifyType { tdDisplay, tdSubTotals, tdMetaData };
#pragma option pop

class PASCALIMPLEMENTATION TDisplayDims : public Classes::TCollection 
{
	typedef Classes::TCollection inherited;
	
public:
	TDisplayDim* operator[](int Index) { return Items[Index]; }
	
private:
	bool bQuiet;
	TDisplayDim* __fastcall GetDisplayDim(int Index);
	void __fastcall SetDisplayDim(int Index, TDisplayDim* Value);
	__fastcall TDisplayDims(TCustomDecisionGrid* Grid, TMetaClass* ItemClass);
	
protected:
	TCustomDecisionGrid* FGrid;
	DYNAMIC Classes::TPersistent* __fastcall GetOwner(void);
	void __fastcall NotifyOwner(TDDNotifyType aType);
	
public:
	__property TDisplayDim* Items[int Index] = {read=GetDisplayDim, write=SetDisplayDim/*, default*/};
public:
	#pragma option push -w-inl
	/* TCollection.Create */ inline __fastcall TDisplayDims(TMetaClass* ItemClass) : Classes::TCollection(ItemClass) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TDisplayDims(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TCustomDecisionGrid : public Grids::TCustomGrid 
{
	typedef Grids::TCustomGrid inherited;
	
private:
	bool FActiveGrid;
	Mxbutton::TQuickMenu* FMenu;
	TDecisionGridDataLink* FDataLink;
	TDisplayDims* FDisplayDims;
	TDecisionGridOptions FOptions;
	Controls::TImageList* FIndicators;
	Grids::TGridCoord FSourceCell;
	Grids::TGridCoord FTargetCell;
	bool FTargetSwitch;
	Byte FCaptionRow;
	Byte FCaptionCol;
	bool FChanging;
	Byte FRowOffset;
	Byte fColOffset;
	int FActRows;
	int FActCols;
	int FTotRows;
	int FTotCols;
	int FColWidth;
	int FRowHeight;
	Graphics::TFont* FLabelFont;
	Graphics::TColor FLabelColor;
	Graphics::TColor FLabelSumColor;
	Graphics::TColor FCaptionColor;
	Graphics::TFont* FCaptionFont;
	Graphics::TFont* FDataFont;
	Graphics::TColor FDataColor;
	Graphics::TColor FDataSumColor;
	Graphics::TColor FGridLineColor;
	int FGridLineWidth;
	bool FShowCubeEditor;
	TDecisionExamineCellEvent FOnDecisionExamineCell;
	TDecisionDrawCellEvent FOnDecisionDrawCell;
	Classes::TNotifyEvent FOnTopLeftChanged;
	void __fastcall InvalidateTargetCell(void);
	TButtonPlace __fastcall GetHorzButtonPlace(int X, int Y);
	void __fastcall PerformPivot(void);
	void __fastcall RawToDataCoord(int &X, int &Y);
	void __fastcall DataToRawCoord(int &X, int &Y);
	int __fastcall DataToRawX(int X);
	int __fastcall DataToRawY(int Y);
	void __fastcall DrawSpecialState(Graphics::TCanvas* ACanvas, const Types::TRect &ARect, TDecisionDrawState DrawState, TDecisionPivotState PivotState);
	TDecisionPivotState __fastcall GetSpecialState(int ARow, int AColumn);
	AnsiString __fastcall GetDataPoint(int ARow, int AColumn, TDecisionDrawState &State, Classes::TAlignment &Alignment);
	TDecisionCellType __fastcall WhichCoord(const Grids::TGridCoord &Coord);
	TDecisionCellType __fastcall WhichCoordExCap(const Grids::TGridCoord &Coord);
	int __fastcall GetDimensionIndex(TDecisionCellType cellType, const Grids::TGridCoord &Coord, Mxdb::TDimGroup &dimGroup, bool &bExists);
	Grids::TGridCoord __fastcall MouseToDataCoord(int X, int Y);
	void __fastcall SetNearestTargetCell(int X, int Y);
	void __fastcall GetHitTypes(int ARow, int AColumn, int &ValueIndex, TDecisionDrawState &DrawState, TDecisionCellType &CellType);
	void __fastcall NewDataStructure(void);
	void __fastcall NewGridLayout(void);
	AnsiString __fastcall GetData(int ARow, int AColumn, int &SubLevel);
	AnsiString __fastcall GetCaption(Mxdb::TDimGroup dimGroup, int Index);
	AnsiString __fastcall GetLabel(Mxdb::TDimGroup dimGroup, int Index, int ValueIndex);
	Mxdb::TDecisionSource* __fastcall GeTDecisionSource(void);
	void __fastcall SeTDecisionSource(Mxdb::TDecisionSource* Value);
	void __fastcall SetColWidth(int Value);
	void __fastcall SetRowHeight(int Value);
	HIDESBASE void __fastcall SetGridLineWidth(int Value);
	void __fastcall SetGridLineColor(Graphics::TColor Value);
	void __fastcall SetLabelFont(Graphics::TFont* Value);
	void __fastcall SetLabelColor(Graphics::TColor Value);
	void __fastcall SetLabelSumColor(Graphics::TColor Value);
	void __fastcall SetCaptionFont(Graphics::TFont* Value);
	void __fastcall SetCaptionColor(Graphics::TColor Value);
	void __fastcall SetDataFont(Graphics::TFont* Value);
	void __fastcall SetDataColor(Graphics::TColor Value);
	void __fastcall SetDataSumColor(Graphics::TColor Value);
	HIDESBASE void __fastcall FontChanged(System::TObject* Sender);
	HIDESBASE void __fastcall SetOptions(TDecisionGridOptions Value);
	HIDESBASE MESSAGE void __fastcall CMDesignHitTest(Messages::TWMMouse &Msg);
	void __fastcall RightMouse(System::TObject* Sender);
	void __fastcall SelectDimOptions(System::TObject* Sender);
	void __fastcall SelectGridOptions(System::TObject* Sender);
	void __fastcall InitializeGridCells(void);
	void __fastcall SetTotals(bool Value);
	bool __fastcall GetTotals(void);
	int __fastcall GetFixedRows(void);
	int __fastcall GetFixedCols(void);
	int __fastcall GetRowCount(void);
	int __fastcall GetColCount(void);
	__property int ColWidth = {read=FColWidth, write=SetColWidth, nodefault};
	__property int RowHeight = {read=FRowHeight, write=SetRowHeight, nodefault};
	
protected:
	TDecisionGridState FGridStateX;
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall DrawCell(int ACol, int ARow, const Types::TRect &ARect, Grids::TGridDrawState AState);
	virtual bool __fastcall SelectCell(int Arow, int AColumn);
	DYNAMIC void __fastcall TopLeftChanged(void);
	DYNAMIC void __fastcall ColWidthsChanged(void);
	DYNAMIC void __fastcall RowHeightsChanged(void);
	virtual void __fastcall Paint(void);
	__property TDecisionGridOptions Options = {read=FOptions, write=SetOptions, default=7};
	__property int GridLineWidth = {read=FGridLineWidth, write=SetGridLineWidth, nodefault};
	__property Graphics::TColor GridLineColor = {read=FGridLineColor, write=SetGridLineColor, nodefault};
	__property Graphics::TFont* CaptionFont = {read=FCaptionFont, write=SetCaptionFont};
	__property Graphics::TColor CaptionColor = {read=FCaptionColor, write=SetCaptionColor, nodefault};
	__property Graphics::TFont* DataFont = {read=FDataFont, write=SetDataFont};
	__property Graphics::TColor DataColor = {read=FDataColor, write=SetDataColor, nodefault};
	__property Graphics::TColor DataSumColor = {read=FDataSumColor, write=SetDataSumColor, nodefault};
	__property Graphics::TFont* LabelFont = {read=FLabelFont, write=SetLabelFont};
	__property Graphics::TColor LabelColor = {read=FLabelColor, write=SetLabelColor, nodefault};
	__property Graphics::TColor LabelSumColor = {read=FLabelSumColor, write=SetLabelSumColor, nodefault};
	__property TDisplayDims* Dimensions = {read=FDisplayDims, write=FDisplayDims};
	AnsiString __fastcall GetCells(int ACol, int ARow);
	__property int FixedRows = {read=GetFixedRows, nodefault};
	__property int RowCount = {read=GetRowCount, nodefault};
	__property int FixedCols = {read=GetFixedCols, nodefault};
	__property int ColCount = {read=GetColCount, nodefault};
	__property int DefaultColWidth = {read=FColWidth, write=SetColWidth, nodefault};
	__property int DefaultRowHeight = {read=FRowHeight, write=SetRowHeight, nodefault};
	
public:
	__fastcall virtual TCustomDecisionGrid(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomDecisionGrid(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	__property Mxdb::TDecisionSource* DecisionSource = {read=GeTDecisionSource, write=SeTDecisionSource};
	HIDESBASE Types::TRect __fastcall CellRect(int ACol, int ARow);
	bool __fastcall CellValueArray(int ACol, int ARow, TValueArray* &ValueArray);
	bool __fastcall CellDrawState(int ACol, int ARow, AnsiString &Value, TDecisionDrawState &DrawState);
	__property bool Totals = {read=GetTotals, write=SetTotals, nodefault};
	__property TDecisionExamineCellEvent OnDecisionExamineCell = {read=FOnDecisionExamineCell, write=FOnDecisionExamineCell};
	__property TDecisionDrawCellEvent OnDecisionDrawCell = {read=FOnDecisionDrawCell, write=FOnDecisionDrawCell};
	__property Classes::TNotifyEvent OnTopLeftChanged = {read=FOnTopLeftChanged, write=FOnTopLeftChanged};
	__property AnsiString Cells[int ACol][int ARow] = {read=GetCells};
	__property bool ShowCubeEditor = {read=FShowCubeEditor, write=FShowCubeEditor, nodefault};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomDecisionGrid(HWND ParentWindow) : Grids::TCustomGrid(ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TDecisionGridDataLink : public Mxdb::TDecisionDataLink 
{
	typedef Mxdb::TDecisionDataLink inherited;
	
private:
	TCustomDecisionGrid* FGrid;
	
protected:
	virtual void __fastcall DecisionDataEvent(Mxdb::TDecisionDataEvent Event);
	
public:
	__fastcall TDecisionGridDataLink(TCustomDecisionGrid* AGrid);
	__fastcall virtual ~TDecisionGridDataLink(void);
};


class PASCALIMPLEMENTATION TDisplayDim : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	AnsiString FName;
	AnsiString FFieldName;
	AnsiString FFormat;
	Classes::TAlignment FAlignment;
	Graphics::TColor FColor;
	bool FSubs;
	Classes::TCollection* FOwner;
	void __fastcall SetName(AnsiString Value);
	void __fastcall SetFieldName(AnsiString Value);
	void __fastcall SetFormat(AnsiString Value);
	void __fastcall SetAlignment(Classes::TAlignment Value);
	void __fastcall SetColor(Graphics::TColor Value);
	void __fastcall SetSubs(bool Value);
	void __fastcall NotifyCollection(TDDNotifyType aType);
	
public:
	__fastcall virtual TDisplayDim(Classes::TCollection* Collection);
	virtual void __fastcall assign(Classes::TPersistent* Value);
	
__published:
	__property AnsiString DisplayName = {read=FName, write=SetName};
	__property AnsiString FieldName = {read=FFieldName, write=SetFieldName};
	__property Graphics::TColor Color = {read=FColor, write=SetColor, nodefault};
	__property AnsiString Format = {read=FFormat, write=SetFormat};
	__property Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, nodefault};
	__property bool Subtotals = {read=FSubs, write=SetSubs, nodefault};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TDisplayDim(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDecisionGrid;
class PASCALIMPLEMENTATION TDecisionGrid : public TCustomDecisionGrid 
{
	typedef TCustomDecisionGrid inherited;
	
public:
	__property RowCount ;
	__property ColCount ;
	__property FixedRows ;
	__property FixedCols ;
	
__published:
	__property Options  = {default=7};
	__property DefaultColWidth ;
	__property DefaultRowHeight ;
	__property CaptionColor ;
	__property CaptionFont ;
	__property DataColor ;
	__property DataSumColor ;
	__property DataFont ;
	__property LabelFont ;
	__property LabelColor ;
	__property LabelSumColor ;
	__property DecisionSource ;
	__property Dimensions ;
	__property Totals ;
	__property ShowCubeEditor ;
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property BorderStyle  = {default=1};
	__property Color  = {default=-2147483643};
	__property Constraints ;
	__property Ctl3D ;
	__property DefaultDrawing  = {default=1};
	__property DragCursor  = {default=-12};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property GridLineWidth ;
	__property GridLineColor ;
	__property ParentColor  = {default=0};
	__property ParentCtl3D  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ScrollBars  = {default=3};
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Visible  = {default=1};
	__property OnClick ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnDecisionDrawCell ;
	__property OnDecisionExamineCell ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnResize ;
	__property OnStartDrag ;
	__property OnTopLeftChanged ;
public:
	#pragma option push -w-inl
	/* TCustomDecisionGrid.Create */ inline __fastcall virtual TDecisionGrid(Classes::TComponent* AOwner) : TCustomDecisionGrid(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomDecisionGrid.Destroy */ inline __fastcall virtual ~TDecisionGrid(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDecisionGrid(HWND ParentWindow) : TCustomDecisionGrid(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Mxgrid */
using namespace Mxgrid;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// MXGRID
