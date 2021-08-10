// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QExtCtrls.pas' rev: 6.00

#ifndef QExtCtrlsHPP
#define QExtCtrlsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QMenus.hpp>	// Pascal unit
#include <QConsts.hpp>	// Pascal unit
#include <QForms.hpp>	// Pascal unit
#include <QStdCtrls.hpp>	// Pascal unit
#include <QGraphics.hpp>	// Pascal unit
#include <QControls.hpp>	// Pascal unit
#include <QTypes.hpp>	// Pascal unit
#include <Qt.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qextctrls
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TShapeType { stRectangle, stSquare, stRoundRect, stRoundSquare, stEllipse, stCircle };
#pragma option pop

class DELPHICLASS TShape;
class PASCALIMPLEMENTATION TShape : public Qcontrols::TGraphicControl 
{
	typedef Qcontrols::TGraphicControl inherited;
	
private:
	TShapeType FShape;
	void __fastcall SetBrush(Qgraphics::TBrush* Value);
	void __fastcall SetPen(Qgraphics::TPen* Value);
	void __fastcall SetShape(TShapeType Value);
	Qgraphics::TBrush* __fastcall GetBrush(void);
	Qgraphics::TPen* __fastcall GetPen(void);
	
protected:
	DYNAMIC void __fastcall ColorChanged(void);
	virtual void __fastcall Paint(void);
	
public:
	__fastcall virtual TShape(Classes::TComponent* AOwner);
	
__published:
	void __fastcall StyleChanged(System::TObject* Sender);
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property Qgraphics::TBrush* Brush = {read=GetBrush, write=SetBrush};
	__property Color  = {default=-10};
	__property Constraints ;
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property ParentShowHint  = {default=1};
	__property Qgraphics::TPen* Pen = {read=GetPen, write=SetPen};
	__property TShapeType Shape = {read=FShape, write=SetShape, default=0};
	__property ShowHint ;
	__property Visible  = {default=1};
	__property OnContextPopup ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TGraphicControl.Destroy */ inline __fastcall virtual ~TShape(void) { }
	#pragma option pop
	
};


class DELPHICLASS TPaintBox;
class PASCALIMPLEMENTATION TPaintBox : public Qcontrols::TGraphicControl 
{
	typedef Qcontrols::TGraphicControl inherited;
	
private:
	Classes::TNotifyEvent FOnPaint;
	
protected:
	virtual void __fastcall Paint(void);
	
public:
	__fastcall virtual TPaintBox(Classes::TComponent* AOwner);
	__property Canvas ;
	
__published:
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property Color  = {default=-10};
	__property Constraints ;
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property ParentColor  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint ;
	__property Visible  = {default=1};
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property Classes::TNotifyEvent OnPaint = {read=FOnPaint, write=FOnPaint};
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TGraphicControl.Destroy */ inline __fastcall virtual ~TPaintBox(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TBevelStyle { bsLowered, bsRaised };
#pragma option pop

#pragma option push -b-
enum TBevelShape { bsBox, bsFrame, bsTopLine, bsBottomLine, bsLeftLine, bsRightLine, bsSpacer };
#pragma option pop

class DELPHICLASS TBevel;
class PASCALIMPLEMENTATION TBevel : public Qcontrols::TGraphicControl 
{
	typedef Qcontrols::TGraphicControl inherited;
	
private:
	TBevelStyle FStyle;
	TBevelShape FShape;
	void __fastcall SetStyle(TBevelStyle Value);
	void __fastcall SetShape(TBevelShape Value);
	
protected:
	virtual void __fastcall Paint(void);
	
public:
	__fastcall virtual TBevel(Classes::TComponent* AOwner);
	
__published:
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property Constraints ;
	__property ParentShowHint  = {default=1};
	__property TBevelShape Shape = {read=FShape, write=SetShape, default=0};
	__property ShowHint ;
	__property TBevelStyle Style = {read=FStyle, write=SetStyle, default=0};
	__property Visible  = {default=1};
public:
	#pragma option push -w-inl
	/* TGraphicControl.Destroy */ inline __fastcall virtual ~TBevel(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTimer;
class PASCALIMPLEMENTATION TTimer : public Qtypes::THandleComponent 
{
	typedef Qtypes::THandleComponent inherited;
	
private:
	unsigned FInterval;
	Classes::TNotifyEvent FOnTimer;
	bool FEnabled;
	void __fastcall SetEnabled(bool Value);
	void __fastcall SetInterval(unsigned Value);
	
protected:
	virtual void __fastcall CreateWidget(void);
	HIDESBASE QTimerH* __fastcall GetHandle(void);
	virtual void __fastcall HookEvents(void);
	virtual void __cdecl Timer(void);
	
public:
	__fastcall virtual TTimer(Classes::TComponent* AOwner);
	__property QTimerH* Handle = {read=GetHandle};
	
__published:
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	__property unsigned Interval = {read=FInterval, write=SetInterval, default=1000};
	__property Classes::TNotifyEvent OnTimer = {read=FOnTimer, write=FOnTimer};
public:
	#pragma option push -w-inl
	/* THandleComponent.Destroy */ inline __fastcall virtual ~TTimer(void) { }
	#pragma option pop
	
};


typedef Qcontrols::TBevelCut TPanelBevel;

typedef int TBevelWidth;

typedef int TBorderWidth;

class DELPHICLASS TCustomPanel;
class PASCALIMPLEMENTATION TCustomPanel : public Qcontrols::TCustomControl 
{
	typedef Qcontrols::TCustomControl inherited;
	
private:
	Qcontrols::TBevelCut FBevelInner;
	Qcontrols::TBevelCut FBevelOuter;
	TBevelWidth FBevelWidth;
	TBorderWidth FBorderWidth;
	Qcontrols::TBorderStyle FBorderStyle;
	Classes::TAlignment FAlignment;
	WideString FCaption;
	void __fastcall SetAlignment(const Classes::TAlignment Value);
	void __fastcall SetBevelInner(const Qcontrols::TBevelCut Value);
	void __fastcall SetBevelOuter(const Qcontrols::TBevelCut Value);
	void __fastcall SetBevelWidth(const TBevelWidth Value);
	void __fastcall SetBorderWidth(const TBorderWidth Value);
	void __fastcall SetBorderStyle(const Qcontrols::TControlBorderStyle Value);
	HIDESBASE Qt::QFrameH* __fastcall GetHandle(void);
	
protected:
	virtual void __fastcall AdjustClientRect(Types::TRect &Rect);
	virtual WideString __fastcall GetText();
	virtual void __fastcall SetText(const WideString Value);
	virtual void __fastcall CreateWidget(void);
	virtual void __fastcall Paint(void);
	__property Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, default=2};
	__property Qcontrols::TBevelCut BevelInner = {read=FBevelInner, write=SetBevelInner, default=0};
	__property Qcontrols::TBevelCut BevelOuter = {read=FBevelOuter, write=SetBevelOuter, default=2};
	__property TBevelWidth BevelWidth = {read=FBevelWidth, write=SetBevelWidth, default=1};
	__property TBorderWidth BorderWidth = {read=FBorderWidth, write=SetBorderWidth, default=0};
	__property Qcontrols::TControlBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, default=0};
	__property Color  = {default=-2};
	__property Caption  = {read=GetText, write=SetText};
	__property Qt::QFrameH* Handle = {read=GetHandle};
	__property ParentColor  = {default=1};
	
public:
	__fastcall virtual TCustomPanel(Classes::TComponent* AOwner);
	virtual void __fastcall Invalidate(void);
public:
	#pragma option push -w-inl
	/* TCustomControl.Destroy */ inline __fastcall virtual ~TCustomPanel(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TCustomPanel(Qt::QWidgetH* ParentWidget) : Qcontrols::TCustomControl(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS TPanel;
class PASCALIMPLEMENTATION TPanel : public TCustomPanel 
{
	typedef TCustomPanel inherited;
	
__published:
	__property Align  = {default=0};
	__property Alignment  = {default=2};
	__property Anchors  = {default=3};
	__property BevelInner  = {default=0};
	__property BevelOuter  = {default=2};
	__property BevelWidth  = {default=1};
	__property Bitmap ;
	__property BorderWidth  = {default=0};
	__property BorderStyle  = {default=0};
	__property Caption ;
	__property Color  = {default=-11};
	__property Constraints ;
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property ParentColor  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=0};
	__property Visible  = {default=1};
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnResize ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TCustomPanel.Create */ inline __fastcall virtual TPanel(Classes::TComponent* AOwner) : TCustomPanel(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomControl.Destroy */ inline __fastcall virtual ~TPanel(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TPanel(Qt::QWidgetH* ParentWidget) : TCustomPanel(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS TImage;
class PASCALIMPLEMENTATION TImage : public Qcontrols::TGraphicControl 
{
	typedef Qcontrols::TGraphicControl inherited;
	
private:
	Qgraphics::TPicture* FPicture;
	Qgraphics::TProgressEvent FOnProgress;
	bool FStretch;
	bool FCenter;
	bool FIncrementalDisplay;
	bool FTransparent;
	bool FDrawing;
	bool FAutoSize;
	Qgraphics::TCanvas* __fastcall GetCanvas(void);
	void __fastcall PictureChanged(System::TObject* Sender);
	void __fastcall SetCenter(bool Value);
	void __fastcall SetPicture(Qgraphics::TPicture* Value);
	void __fastcall SetStretch(bool Value);
	void __fastcall SetTransparent(bool Value);
	void __fastcall SetAutoSize(const bool Value);
	
protected:
	void __fastcall DoAutoSize(void);
	Types::TRect __fastcall DestRect();
	bool __fastcall DoPaletteChange(void);
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall Progress(System::TObject* Sender, Qgraphics::TProgressStage Stage, Byte PercentDone, bool RedrawNow, const Types::TRect &R, const WideString Msg);
	DYNAMIC void __fastcall Resize(void);
	
public:
	__fastcall virtual TImage(Classes::TComponent* AOwner);
	__fastcall virtual ~TImage(void);
	__property Qgraphics::TCanvas* Canvas = {read=GetCanvas};
	
__published:
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property bool AutoSize = {read=FAutoSize, write=SetAutoSize, default=0};
	__property bool Center = {read=FCenter, write=SetCenter, default=0};
	__property Constraints ;
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property bool IncrementalDisplay = {read=FIncrementalDisplay, write=FIncrementalDisplay, default=0};
	__property ParentShowHint  = {default=1};
	__property Qgraphics::TPicture* Picture = {read=FPicture, write=SetPicture};
	__property PopupMenu ;
	__property ShowHint ;
	__property bool Stretch = {read=FStretch, write=SetStretch, default=0};
	__property bool Transparent = {read=FTransparent, write=SetTransparent, default=0};
	__property Visible  = {default=1};
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property Qgraphics::TProgressEvent OnProgress = {read=FOnProgress, write=FOnProgress};
	__property OnStartDrag ;
};


typedef int NaturalNumber;

typedef void __fastcall (__closure *TCanResizeEvent)(System::TObject* Sender, int &NewSize, bool &Accept);

#pragma option push -b-
enum TResizeStyle { rsNone, rsLine, rsUpdate, rsPattern };
#pragma option pop

class DELPHICLASS TSplitter;
class PASCALIMPLEMENTATION TSplitter : public Qcontrols::TGraphicControl 
{
	typedef Qcontrols::TGraphicControl inherited;
	
private:
	Qcontrols::TCursor FOldCur;
	Qcontrols::TWidgetControl* FActiveControl;
	bool FAutoSnap;
	bool FBeveled;
	Qgraphics::TBrush* FBrush;
	Qcontrols::TControl* FControl;
	#pragma pack(push, 1)
	Types::TPoint FDownPos;
	#pragma pack(pop)
	
	NaturalNumber FMinSize;
	int FMaxSize;
	int FNewSize;
	Qcontrols::TKeyEvent FOldKeyDown;
	int FOldSize;
	TResizeStyle FResizeStyle;
	int FSplit;
	TCanResizeEvent FOnCanResize;
	Classes::TNotifyEvent FOnMoved;
	Classes::TNotifyEvent FOnPaint;
	void __fastcall CalcSplitSize(int X, int Y, int &NewSize, int &Split);
	void __fastcall DrawLine(void);
	Qcontrols::TControl* __fastcall FindControl(void);
	void __fastcall FocusKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall SetBeveled(bool Value);
	void __fastcall UpdateControlSize(void);
	void __fastcall UpdateSize(int X, int Y);
	bool __fastcall CanResize(int &NewSize);
	
protected:
	virtual bool __fastcall DoCanResize(int &NewSize);
	DYNAMIC void __fastcall MouseDown(Qcontrols::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Qcontrols::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall RequestAlign(void);
	DYNAMIC void __fastcall StopSizing(void);
	
public:
	__fastcall virtual TSplitter(Classes::TComponent* AOwner);
	__fastcall virtual ~TSplitter(void);
	__property Canvas ;
	
__published:
	__property Align  = {default=3};
	__property Anchors  = {default=3};
	__property bool AutoSnap = {read=FAutoSnap, write=FAutoSnap, default=1};
	__property bool Beveled = {read=FBeveled, write=SetBeveled, default=0};
	__property Color  = {default=-2};
	__property Constraints ;
	__property Cursor  = {default=-14};
	__property Height  = {default=22};
	__property NaturalNumber MinSize = {read=FMinSize, write=FMinSize, default=30};
	__property ParentColor  = {default=0};
	__property ParentShowHint  = {default=1};
	__property TResizeStyle ResizeStyle = {read=FResizeStyle, write=FResizeStyle, default=3};
	__property ShowHint ;
	__property Visible  = {default=1};
	__property Width  = {default=3};
	__property TCanResizeEvent OnCanResize = {read=FOnCanResize, write=FOnCanResize};
	__property Classes::TNotifyEvent OnMoved = {read=FOnMoved, write=FOnMoved};
	__property Classes::TNotifyEvent OnPaint = {read=FOnPaint, write=FOnPaint};
};


#pragma option push -b-
enum TOrientation { orVertical, orHorizontal };
#pragma option pop

class DELPHICLASS TCustomRadioGroup;
class PASCALIMPLEMENTATION TCustomRadioGroup : public Qstdctrls::TCustomGroupBox 
{
	typedef Qstdctrls::TCustomGroupBox inherited;
	
private:
	Classes::TStrings* FItems;
	Classes::TList* FButtons;
	int FItemIndex;
	int FLastIndex;
	int FColumns;
	TOrientation FOrientation;
	void __cdecl ClickedHook(int Index);
	void __fastcall ForceLayout(void);
	HIDESBASE Qt::QButtonGroupH* __fastcall GetHandle(void);
	void __fastcall ItemsChange(System::TObject* Sender);
	void __fastcall SetButtonCount(int Value);
	void __fastcall SetColumns(int Value);
	void __fastcall SetItemIndex(int Value);
	void __fastcall SetItems(Classes::TStrings* Value);
	void __fastcall UpdateButtons(void);
	void __fastcall SetOrientation(const TOrientation Value);
	
protected:
	virtual bool __fastcall CanModify(void);
	virtual void __fastcall CreateWidget(void);
	DYNAMIC void __fastcall CursorChanged(void);
	virtual bool __fastcall EventFilter(Qt::QObjectH* Sender, Qt::QEventH* Event);
	virtual void __fastcall HookEvents(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall RestoreWidgetState(void);
	virtual void __fastcall SaveWidgetState(void);
	DYNAMIC void __fastcall ShowingChanged(void);
	DYNAMIC bool __fastcall WantKey(int Key, Classes::TShiftState Shift, const WideString KeyText);
	__property int Columns = {read=FColumns, write=SetColumns, default=1};
	__property int ItemIndex = {read=FItemIndex, write=SetItemIndex, default=-1};
	__property Classes::TStrings* Items = {read=FItems, write=SetItems};
	__property TOrientation Orientation = {read=FOrientation, write=SetOrientation, default=0};
	
public:
	__fastcall virtual TCustomRadioGroup(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomRadioGroup(void);
	virtual void __fastcall SetFocus(void);
	__property Qt::QButtonGroupH* Handle = {read=GetHandle};
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TCustomRadioGroup(Qt::QWidgetH* ParentWidget) : Qstdctrls::TCustomGroupBox(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS TRadioGroup;
class PASCALIMPLEMENTATION TRadioGroup : public TCustomRadioGroup 
{
	typedef TCustomRadioGroup inherited;
	
__published:
	__property Items ;
	__property Orientation  = {default=0};
	__property Align  = {default=0};
	__property Alignment  = {default=0};
	__property Bitmap ;
	__property Anchors  = {default=3};
	__property Caption ;
	__property Color  = {default=-11};
	__property Columns  = {default=1};
	__property Constraints ;
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property ItemIndex  = {default=-1};
	__property Masked  = {default=0};
	__property ParentColor  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint  = {default=0};
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Visible  = {default=1};
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TCustomRadioGroup.Create */ inline __fastcall virtual TRadioGroup(Classes::TComponent* AOwner) : TCustomRadioGroup(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomRadioGroup.Destroy */ inline __fastcall virtual ~TRadioGroup(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TRadioGroup(Qt::QWidgetH* ParentWidget) : TCustomRadioGroup(ParentWidget) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TBandPaintOption { bpoGrabber, bpoFrame };
#pragma option pop

typedef Set<TBandPaintOption, bpoGrabber, bpoFrame>  TBandPaintOptions;

typedef void __fastcall (__closure *TBandDragEvent)(System::TObject* Sender, Qcontrols::TControl* Control, bool &Drag);

typedef void __fastcall (__closure *TBandInfoEvent)(System::TObject* Sender, Qcontrols::TControl* Control, Types::TRect &Insets, int &PreferredSize, int &RowCount);

typedef void __fastcall (__closure *TBandMoveEvent)(System::TObject* Sender, Qcontrols::TControl* Control, Types::TRect &ARect);

typedef void __fastcall (__closure *TBandPaintEvent)(System::TObject* Sender, Qcontrols::TControl* Control, Qgraphics::TCanvas* Canvas, Types::TRect &ARect, TBandPaintOptions &Options);

typedef int TRowSize;

class DELPHICLASS TCustomControlBar;
class PASCALIMPLEMENTATION TCustomControlBar : public Qcontrols::TCustomControl 
{
	typedef Qcontrols::TCustomControl inherited;
	
private:
	bool FAligning;
	bool FAutoDrag;
	Qcontrols::TCursor FGrabCursor;
	Qcontrols::TCursor FSaveCursor;
	Qcontrols::TControl* FDockingControl;
	Qcontrols::TControl* FDragControl;
	#pragma pack(push, 1)
	Types::TPoint FDragOffset;
	#pragma pack(pop)
	
	bool FDrawing;
	Classes::TList* FItems;
	Qgraphics::TPicture* FPicture;
	TRowSize FRowSize;
	bool FRowSnap;
	TBandDragEvent FOnBandDrag;
	TBandInfoEvent FOnBandInfo;
	TBandMoveEvent FOnBandMove;
	TBandPaintEvent FOnBandPaint;
	Classes::TNotifyEvent FOnPaint;
	Qcontrols::TBevelEdges FBevelEdges;
	Qcontrols::TBevelCut FBevelOuter;
	Qcontrols::TBevelCut FBevelInner;
	bool FAutoSize;
	HIDESBASE void __fastcall AdjustSize(void);
	void __fastcall MarkDirty(void);
	void __fastcall DoAlignControl(Qcontrols::TControl* AControl);
	void * __fastcall FindPos(Qcontrols::TControl* AControl);
	void * __fastcall HitTest2(int X, int Y);
	Qcontrols::TControl* __fastcall HitTest3(int X, int Y);
	void __fastcall DockControl(Qcontrols::TControl* AControl, const Types::TRect &ARect, Classes::TList* BreakList, Classes::TList* IndexList, Classes::TList* SizeList, void * Parent, bool ChangedPriorBreak, const Types::TRect &Insets, int PreferredSize, int RowCount, bool Existing);
	int __fastcall EdgeSpacing(Qcontrols::TBevelEdge Edge);
	void __fastcall PictureChanged(System::TObject* Sender);
	void __fastcall SetPicture(const Qgraphics::TPicture* Value);
	void __fastcall SetRowSize(TRowSize Value);
	void __fastcall SetRowSnap(bool Value);
	void __fastcall UnDockControl(Qcontrols::TControl* AControl);
	bool __fastcall UpdateItems(Qcontrols::TControl* AControl);
	void __fastcall SetBevelEdges(const Qcontrols::TBevelEdges Value);
	void __fastcall SetBevelInner(const Qcontrols::TBevelCut Value);
	void __fastcall SetBevelOuter(const Qcontrols::TBevelCut Value);
	void __fastcall SetAutoSize(const bool Value);
	
protected:
	virtual void __fastcall AlignControls(Qcontrols::TControl* AControl, Types::TRect &ARect);
	DYNAMIC void __fastcall ControlsListChanged(Qcontrols::TControl* Control, bool Inserting);
	virtual void __fastcall DoBandMove(Qcontrols::TControl* Control, Types::TRect &ARect);
	virtual void __fastcall DoBandPaint(Qcontrols::TControl* Control, Qgraphics::TCanvas* Canvas, Types::TRect &ARect, TBandPaintOptions &Options);
	virtual bool __fastcall EventFilter(Qt::QObjectH* Sender, Qt::QEventH* Event);
	virtual bool __fastcall DragControl(Qcontrols::TControl* AControl, int X, int Y, bool KeepCapture = false);
	virtual Types::TRect __fastcall GetClientRect();
	virtual void __fastcall GetControlInfo(Qcontrols::TControl* AControl, Types::TRect &Insets, int &PreferredSize, int &RowCount);
	HIDESBASE Qcontrols::TControl* __fastcall HitTest(int X, int Y);
	DYNAMIC void __fastcall MouseDown(Qcontrols::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Qcontrols::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Paint(void);
	virtual void __fastcall PaintControlFrame(Qgraphics::TCanvas* Canvas, Qcontrols::TControl* AControl, Types::TRect &ARect);
	
public:
	__fastcall virtual TCustomControlBar(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomControlBar(void);
	DYNAMIC void __fastcall FlipChildren(bool AllLevels);
	virtual void __fastcall StickControls(void);
	__property Qgraphics::TPicture* Picture = {read=FPicture, write=SetPicture};
	
protected:
	__property bool AutoSize = {read=FAutoSize, write=SetAutoSize, default=0};
	__property Qcontrols::TCursor GrabCursor = {read=FGrabCursor, write=FGrabCursor, default=0};
	__property Qcontrols::TBevelEdges BevelEdges = {read=FBevelEdges, write=SetBevelEdges, default=15};
	__property Qcontrols::TBevelCut BevelInner = {read=FBevelInner, write=SetBevelInner, default=2};
	__property Qcontrols::TBevelCut BevelOuter = {read=FBevelOuter, write=SetBevelOuter, default=1};
	__property Color  = {default=-2};
	__property ParentColor  = {default=0};
	__property TRowSize RowSize = {read=FRowSize, write=SetRowSize, default=26};
	__property bool RowSnap = {read=FRowSnap, write=SetRowSnap, default=1};
	__property TBandDragEvent OnBandDrag = {read=FOnBandDrag, write=FOnBandDrag};
	__property TBandInfoEvent OnBandInfo = {read=FOnBandInfo, write=FOnBandInfo};
	__property TBandMoveEvent OnBandMove = {read=FOnBandMove, write=FOnBandMove};
	__property TBandPaintEvent OnBandPaint = {read=FOnBandPaint, write=FOnBandPaint};
	__property Classes::TNotifyEvent OnPaint = {read=FOnPaint, write=FOnPaint};
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TCustomControlBar(Qt::QWidgetH* ParentWidget) : Qcontrols::TCustomControl(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS TControlBar;
class PASCALIMPLEMENTATION TControlBar : public TCustomControlBar 
{
	typedef TCustomControlBar inherited;
	
public:
	__property Canvas ;
	
__published:
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property AutoSize  = {default=0};
	__property Color  = {default=-2};
	__property Constraints ;
	__property DragMode  = {default=0};
	__property BevelEdges  = {default=15};
	__property BevelInner  = {default=2};
	__property BevelOuter  = {default=1};
	__property Enabled  = {default=1};
	__property GrabCursor  = {default=0};
	__property ParentColor  = {default=0};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property Picture ;
	__property PopupMenu ;
	__property RowSize  = {default=26};
	__property RowSnap  = {default=1};
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=0};
	__property Visible  = {default=1};
	__property OnBandDrag ;
	__property OnBandInfo ;
	__property OnBandMove ;
	__property OnBandPaint ;
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnPaint ;
	__property OnResize ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TCustomControlBar.Create */ inline __fastcall virtual TControlBar(Classes::TComponent* AOwner) : TCustomControlBar(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomControlBar.Destroy */ inline __fastcall virtual ~TControlBar(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TControlBar(Qt::QWidgetH* ParentWidget) : TCustomControlBar(ParentWidget) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall Frame3D(Qgraphics::TCanvas* Canvas, Types::TRect &Rect, Qgraphics::TColor TopColor, Qgraphics::TColor BottomColor, int Width);

}	/* namespace Qextctrls */
using namespace Qextctrls;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QExtCtrls
