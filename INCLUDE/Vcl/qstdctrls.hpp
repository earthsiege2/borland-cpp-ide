// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QStdCtrls.pas' rev: 6.00

#ifndef QStdCtrlsHPP
#define QStdCtrlsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QStyle.hpp>	// Pascal unit
#include <QActnList.hpp>	// Pascal unit
#include <QGraphics.hpp>	// Pascal unit
#include <QMenus.hpp>	// Pascal unit
#include <QForms.hpp>	// Pascal unit
#include <QControls.hpp>	// Pascal unit
#include <QTypes.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Qt.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qstdctrls
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCustomGroupBox;
class PASCALIMPLEMENTATION TCustomGroupBox : public Qcontrols::TFrameControl 
{
	typedef Qcontrols::TFrameControl inherited;
	
private:
	WideString FCaption;
	HIDESBASE Qt::QGroupBoxH* __fastcall GetHandle(void);
	
protected:
	virtual void __fastcall AlignControls(Qcontrols::TControl* AControl, Types::TRect &Rect);
	virtual void __fastcall CreateWidget(void);
	DYNAMIC void __fastcall FontChanged(void);
	virtual WideString __fastcall GetText();
	virtual void __fastcall InitWidget(void);
	virtual void __fastcall SetText(const WideString Value);
	Classes::TAlignment __fastcall GetAlignment(void);
	void __fastcall SetAlignment(const Classes::TAlignment Value);
	DYNAMIC bool __fastcall WantKey(int Key, Classes::TShiftState Shift, const WideString KeyText);
	virtual int __fastcall WidgetFlags(void);
	__property Classes::TAlignment Alignment = {read=GetAlignment, write=SetAlignment, default=0};
	
public:
	__fastcall virtual TCustomGroupBox(Classes::TComponent* AOwner);
	virtual void __fastcall Invalidate(void);
	__property Qt::QGroupBoxH* Handle = {read=GetHandle};
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TCustomGroupBox(Qt::QWidgetH* ParentWidget) : Qcontrols::TFrameControl(ParentWidget) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWidgetControl.Destroy */ inline __fastcall virtual ~TCustomGroupBox(void) { }
	#pragma option pop
	
};


class DELPHICLASS TGroupBox;
class PASCALIMPLEMENTATION TGroupBox : public TCustomGroupBox 
{
	typedef TCustomGroupBox inherited;
	
__published:
	__property Align  = {default=0};
	__property Alignment  = {default=0};
	__property Anchors  = {default=3};
	__property Bitmap ;
	__property BorderStyle  = {default=7};
	__property Caption ;
	__property Color  = {default=-11};
	__property Constraints ;
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property Masked  = {default=0};
	__property ParentColor  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint  = {default=0};
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
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TCustomGroupBox.Create */ inline __fastcall virtual TGroupBox(Classes::TComponent* AOwner) : TCustomGroupBox(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TGroupBox(Qt::QWidgetH* ParentWidget) : TCustomGroupBox(ParentWidget) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWidgetControl.Destroy */ inline __fastcall virtual ~TGroupBox(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TLCDMode { lcdHexadecimal, lcdDecimal, lcdOctal, lcdBinary };
#pragma option pop

#pragma option push -b-
enum TLCDSegmentStyle { ssOutline, ssFilled, ssFlat };
#pragma option pop

#pragma option push -b-
enum TLCDPointSize { ptSmall, ptLarge };
#pragma option pop

typedef Shortint TNumDigits;

class DELPHICLASS TCustomLCDNumber;
class PASCALIMPLEMENTATION TCustomLCDNumber : public Qcontrols::TFrameControl 
{
	typedef Qcontrols::TFrameControl inherited;
	
private:
	AnsiString FValue;
	Classes::TNotifyEvent FOnOverflow;
	bool FAutoSize;
	TLCDMode FMode;
	TLCDSegmentStyle FSegmentStyle;
	TLCDPointSize FPtSize;
	TNumDigits FNumDigits;
	void __fastcall SetMode(const TLCDMode Value);
	void __fastcall SetNumDigits(const TNumDigits Value);
	void __fastcall SetPointSize(const TLCDPointSize Value);
	void __fastcall SetSegmentStyle(const TLCDSegmentStyle Value);
	void __fastcall SetValue(const AnsiString Value);
	void __cdecl DoOverflow(void);
	void __fastcall SetOnOverflow(const Classes::TNotifyEvent Value);
	void __fastcall ResizeView(void);
	void __fastcall SetAutoSize(const bool Value);
	HIDESBASE Qt::QLCDNumberH* __fastcall GetHandle(void);
	
protected:
	virtual void __fastcall CreateWidget(void);
	DYNAMIC void __fastcall ColorChanged(void);
	__property bool AutoSize = {read=FAutoSize, write=SetAutoSize, nodefault};
	__property BorderStyle  = {default=8};
	__property Color  = {default=-11};
	__property TNumDigits Digits = {read=FNumDigits, write=SetNumDigits, nodefault};
	__property TLCDMode Mode = {read=FMode, write=SetMode, nodefault};
	__property TLCDPointSize PointSize = {read=FPtSize, write=SetPointSize, nodefault};
	__property TLCDSegmentStyle SegmentStyle = {read=FSegmentStyle, write=SetSegmentStyle, nodefault};
	__property AnsiString Value = {read=FValue, write=SetValue};
	__property Classes::TNotifyEvent OnOverflow = {read=FOnOverflow, write=SetOnOverflow};
	
public:
	__fastcall virtual TCustomLCDNumber(Classes::TComponent* AOwner);
	__property Qt::QLCDNumberH* Handle = {read=GetHandle};
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TCustomLCDNumber(Qt::QWidgetH* ParentWidget) : Qcontrols::TFrameControl(ParentWidget) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWidgetControl.Destroy */ inline __fastcall virtual ~TCustomLCDNumber(void) { }
	#pragma option pop
	
};


class DELPHICLASS TLCDNumber;
class PASCALIMPLEMENTATION TLCDNumber : public TCustomLCDNumber 
{
	typedef TCustomLCDNumber inherited;
	
protected:
	virtual void __fastcall InitWidget(void);
	
__published:
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property AutoSize  = {default=0};
	__property Bitmap ;
	__property BorderStyle  = {default=8};
	__property Color  = {default=-11};
	__property Constraints ;
	__property Digits  = {default=4};
	__property DragMode  = {default=0};
	__property Hint ;
	__property Mode  = {default=1};
	__property ParentColor  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PointSize  = {default=0};
	__property SegmentStyle  = {default=0};
	__property ShowHint ;
	__property Value ;
	__property OnContextPopup ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnOverflow ;
	__property OnStartDrag ;
	__property OnClick ;
	__property OnDblClick ;
	__property OnMouseMove ;
	__property OnMouseDown ;
	__property OnMouseUp ;
public:
	#pragma option push -w-inl
	/* TCustomLCDNumber.Create */ inline __fastcall virtual TLCDNumber(Classes::TComponent* AOwner) : TCustomLCDNumber(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TLCDNumber(Qt::QWidgetH* ParentWidget) : TCustomLCDNumber(ParentWidget) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWidgetControl.Destroy */ inline __fastcall virtual ~TLCDNumber(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TTextLayout { tlTop, tlCenter, tlBottom };
#pragma option pop

class DELPHICLASS TCustomLabel;
class PASCALIMPLEMENTATION TCustomLabel : public Qcontrols::TFrameControl 
{
	typedef Qcontrols::TFrameControl inherited;
	
private:
	bool FAutoSize;
	Qcontrols::TWidgetControl* FFocusControl;
	bool FShowAccel;
	void __fastcall DoAutoSize(void);
	void __fastcall GetSize(int &AWidth, int &AHeight);
	Classes::TAlignment __fastcall GetAlignment(void);
	void __fastcall SetAlignment(const Classes::TAlignment Value);
	void __fastcall SetFocusControl(const Qcontrols::TWidgetControl* Value);
	void __fastcall SetLayout(const TTextLayout Value);
	void __fastcall SetWordWrap(const bool Value);
	TTextLayout __fastcall GetLayout(void);
	bool __fastcall GetWordWrap(void);
	HIDESBASE Qt::QLabelH* __fastcall GetHandle(void);
	bool __fastcall GetTransparent(void);
	void __fastcall SetTransparent(const bool Value);
	void __fastcall SetShowAccel(const bool Value);
	
protected:
	virtual WideString __fastcall GetText();
	virtual void __fastcall SetText(const WideString Value);
	virtual void __fastcall CreateWidget(void);
	DYNAMIC void __fastcall FontChanged(void);
	virtual WideString __fastcall GetLabelText();
	virtual void __fastcall InitWidget(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall SetAutoSize(bool Value);
	DYNAMIC void __fastcall TextChanged(void);
	DYNAMIC bool __fastcall WantKey(int Key, Classes::TShiftState Shift, const WideString KeyText);
	__property Classes::TAlignment Alignment = {read=GetAlignment, write=SetAlignment, default=0};
	__property bool AutoSize = {read=FAutoSize, write=SetAutoSize, default=1};
	__property BorderStyle  = {default=0};
	__property WideString Caption = {read=GetText, write=SetText};
	__property Qcontrols::TWidgetControl* FocusControl = {read=FFocusControl, write=SetFocusControl};
	__property TTextLayout Layout = {read=GetLayout, write=SetLayout, default=0};
	__property ParentColor  = {default=1};
	__property bool ShowAccelChar = {read=FShowAccel, write=SetShowAccel, default=1};
	__property ShowHint  = {default=0};
	__property bool Transparent = {read=GetTransparent, write=SetTransparent, default=0};
	__property bool WordWrap = {read=GetWordWrap, write=SetWordWrap, default=0};
	
public:
	__fastcall virtual TCustomLabel(Classes::TComponent* AOwner);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	__property Qt::QLabelH* Handle = {read=GetHandle};
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TCustomLabel(Qt::QWidgetH* ParentWidget) : Qcontrols::TFrameControl(ParentWidget) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWidgetControl.Destroy */ inline __fastcall virtual ~TCustomLabel(void) { }
	#pragma option pop
	
};


class DELPHICLASS TLabel;
class PASCALIMPLEMENTATION TLabel : public TCustomLabel 
{
	typedef TCustomLabel inherited;
	
__published:
	__property Align  = {default=0};
	__property Alignment  = {default=0};
	__property Anchors  = {default=3};
	__property AutoSize  = {default=1};
	__property Bitmap ;
	__property BorderStyle  = {default=0};
	__property Caption ;
	__property Color  = {default=-10};
	__property Constraints ;
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property FocusControl ;
	__property Font ;
	__property Masked  = {default=0};
	__property ParentColor  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property ShowAccelChar  = {default=1};
	__property ShowHint  = {default=0};
	__property Transparent  = {default=0};
	__property Layout  = {default=0};
	__property Visible  = {default=1};
	__property WordWrap  = {default=0};
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TCustomLabel.Create */ inline __fastcall virtual TLabel(Classes::TComponent* AOwner) : TCustomLabel(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TLabel(Qt::QWidgetH* ParentWidget) : TCustomLabel(ParentWidget) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWidgetControl.Destroy */ inline __fastcall virtual ~TLabel(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TEditCharCase { ecNormal, ecUpperCase, ecLowerCase };
#pragma option pop

#pragma option push -b-
enum TEchoMode { emNormal, emNone, emPassword };
#pragma option pop

class DELPHICLASS TCustomEdit;
class PASCALIMPLEMENTATION TCustomEdit : public Qcontrols::TWidgetControl 
{
	typedef Qcontrols::TWidgetControl inherited;
	
private:
	Classes::TNotifyEvent FOnChange;
	Classes::TNotifyEvent FOnReturnPressed;
	TEditCharCase FCharCase;
	bool FAutoSize;
	bool FHideSelection;
	bool FIgnoreEvents;
	int FMaxLength;
	int __fastcall FontHeight(void);
	Classes::TAlignment __fastcall GetAlignment(void);
	Qcontrols::TControlBorderStyle __fastcall GetBorderStyle(void);
	TEchoMode __fastcall GetEchoMode(void);
	HIDESBASE Qt::QClxLineEditH* __fastcall GetHandle(void);
	bool __fastcall GetModified(void);
	void __cdecl ReturnPressedHook(void);
	void __fastcall SetAlignment(const Classes::TAlignment Value);
	void __fastcall SetBorderStyle(const Qcontrols::TControlBorderStyle Value);
	void __fastcall SetEchoMode(const TEchoMode Value);
	void __fastcall SetMaxLength(const int Value);
	void __fastcall SetModified(const bool Value);
	void __fastcall SetOnReturnPressed(const Classes::TNotifyEvent Value);
	void __cdecl TextChangedHook(System::PWideString Text);
	bool __fastcall GetAutoSelect(void);
	void __fastcall SetAutoSelect(const bool Value);
	bool __fastcall GetReadOnly(void);
	void __fastcall SetReadOnly(const bool Value);
	void __fastcall SetAutoSize(const bool Value);
	void __fastcall SetHideSelection(const bool Value);
	void __fastcall UpdateHeight(void);
	
protected:
	virtual void __fastcall Change(void);
	virtual void __fastcall CreateWidget(void);
	virtual bool __fastcall EventFilter(Qt::QObjectH* Sender, Qt::QEventH* Event);
	DYNAMIC void __fastcall FontChanged(void);
	virtual int __fastcall GetSelLength(void);
	virtual int __fastcall GetSelStart(void);
	virtual WideString __fastcall GetSelText();
	virtual WideString __fastcall GetText();
	virtual void __fastcall HookEvents(void);
	virtual void __fastcall InitWidget(void);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall SetSelLength(int Value);
	virtual void __fastcall SetSelStart(int Value);
	virtual void __fastcall SetSelText(const WideString Value);
	virtual void __fastcall SetText(const WideString Value);
	__property Classes::TAlignment Alignment = {read=GetAlignment, write=SetAlignment, default=0};
	__property bool AutoSelect = {read=GetAutoSelect, write=SetAutoSelect, default=1};
	__property bool AutoSize = {read=FAutoSize, write=SetAutoSize, default=1};
	__property Qcontrols::TControlBorderStyle BorderStyle = {read=GetBorderStyle, write=SetBorderStyle, default=1};
	__property TEditCharCase CharCase = {read=FCharCase, write=FCharCase, default=0};
	__property Color  = {default=-10};
	__property DragMode  = {default=0};
	__property TEchoMode EchoMode = {read=GetEchoMode, write=SetEchoMode, default=0};
	__property bool HideSelection = {read=FHideSelection, write=SetHideSelection, default=1};
	__property int MaxLength = {read=FMaxLength, write=SetMaxLength, default=-1};
	__property ParentColor  = {default=0};
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
	__property ShowHint  = {default=0};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property Classes::TNotifyEvent OnReturnPressed = {read=FOnReturnPressed, write=SetOnReturnPressed};
	
public:
	__fastcall virtual TCustomEdit(Classes::TComponent* AOwner);
	virtual void __fastcall Clear(void);
	void __fastcall ClearSelection(void);
	void __fastcall CopyToClipboard(void);
	virtual void __fastcall CutToClipboard(void);
	int __fastcall GetSelTextBuf(char * Buffer, int BufSize);
	virtual void __fastcall PasteFromClipboard(void);
	void __fastcall SelectAll(void);
	void __fastcall SetSelTextBuf(char * Buffer);
	__property Qt::QClxLineEditH* Handle = {read=GetHandle};
	__property bool Modified = {read=GetModified, write=SetModified, nodefault};
	__property int SelLength = {read=GetSelLength, write=SetSelLength, nodefault};
	__property int SelStart = {read=GetSelStart, write=SetSelStart, nodefault};
	__property WideString SelText = {read=GetSelText, write=SetSelText};
	__property WideString Text = {read=GetText, write=SetText};
	
__published:
	__property TabStop  = {default=1};
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TCustomEdit(Qt::QWidgetH* ParentWidget) : Qcontrols::TWidgetControl(ParentWidget) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWidgetControl.Destroy */ inline __fastcall virtual ~TCustomEdit(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEdit;
class PASCALIMPLEMENTATION TEdit : public TCustomEdit 
{
	typedef TCustomEdit inherited;
	
__published:
	__property Anchors  = {default=3};
	__property AutoSelect  = {default=1};
	__property AutoSize  = {default=1};
	__property Alignment  = {default=0};
	__property BorderStyle  = {default=1};
	__property CharCase  = {default=0};
	__property Color  = {default=-10};
	__property Constraints ;
	__property DragMode  = {default=0};
	__property EchoMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property HideSelection  = {default=1};
	__property MaxLength  = {default=-1};
	__property ParentColor  = {default=0};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ReadOnly  = {default=0};
	__property ShowHint  = {default=0};
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Text ;
	__property Visible  = {default=1};
	__property OnChange ;
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
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
	__property OnReturnPressed ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TCustomEdit.Create */ inline __fastcall virtual TEdit(Classes::TComponent* AOwner) : TCustomEdit(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TEdit(Qt::QWidgetH* ParentWidget) : TCustomEdit(ParentWidget) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWidgetControl.Destroy */ inline __fastcall virtual ~TEdit(void) { }
	#pragma option pop
	
};


#pragma pack(push, 4)
struct TCaretPos
{
	int Line;
	int Col;
} ;
#pragma pack(pop)

#pragma pack(push, 4)
struct TMemoSelection
{
	
	union
	{
		struct 
		{
			TCaretPos TopLeft;
			TCaretPos BottomRight;
			
		};
		struct 
		{
			int Line1;
			int Col1;
			int Line2;
			int Col2;
			
		};
		
	};
} ;
#pragma pack(pop)

#pragma option push -b-
enum TWrapMode { wmNone, wmWidth, wmPixel, wmColumn };
#pragma option pop

#pragma option push -b-
enum TWrapBreak { wbWhitespace, wbAnywhere };
#pragma option pop

#pragma option push -b-
enum TScrollStyle { ssNone, ssHorizontal, ssVertical, ssBoth, ssAutoHorizontal, ssAutoVertical, ssAutoBoth };
#pragma option pop

class DELPHICLASS TCustomMemo;
class PASCALIMPLEMENTATION TCustomMemo : public Qcontrols::TFrameControl 
{
	typedef Qcontrols::TFrameControl inherited;
	
private:
	Classes::TStrings* FLines;
	Classes::TNotifyEvent FOnReturnPressed;
	Classes::TNotifyEvent FOnChange;
	bool FWantTabs;
	bool FWantReturns;
	TScrollStyle FScrollBars;
	TWrapMode FWrapMode;
	bool FWordWrap;
	int FMaxLength;
	int __fastcall CaretPosToPos(const TCaretPos &CaretPos);
	Classes::TAlignment __fastcall GetAlignment(void);
	TCaretPos __fastcall GetCaretPos();
	HIDESBASE Qt::QOpenMultiLineEditH* __fastcall GetHandle(void);
	int __fastcall GetHMargin(void);
	bool __fastcall GetModified(void);
	bool __fastcall GetReadOnly(void);
	TMemoSelection __fastcall GetSelection();
	int __fastcall GetTextWidth(int LineNum);
	TWrapBreak __fastcall GetWrapBreak(void);
	int __fastcall GetWrapValue(void);
	void __fastcall InternalSetWrapMode(TWrapMode NewMode);
	TCaretPos __fastcall PosToCaretPos(int Pos);
	void __cdecl ReturnPressedHook(void);
	void __cdecl TextChangedHook(void);
	HIDESBASE MESSAGE void __fastcall CMKeyDown(Qcontrols::TCMKeyDown &Msg);
	
protected:
	virtual void __fastcall Change(void);
	virtual void __fastcall CreateWidget(void);
	DYNAMIC void __fastcall FontChanged(void);
	virtual int __fastcall GetSelLength(void);
	virtual int __fastcall GetSelStart(void);
	virtual WideString __fastcall GetSelText();
	virtual WideString __fastcall GetText();
	virtual void __fastcall HookEvents(void);
	virtual void __fastcall InitWidget(void);
	int __fastcall LineLength(int Index);
	virtual void __fastcall Loaded(void);
	DYNAMIC bool __fastcall NeedKey(int Key, Classes::TShiftState Shift, const WideString KeyText);
	virtual void __fastcall ReturnPressed(void);
	virtual void __fastcall SetText(const WideString Value);
	virtual void __fastcall SetSelText(const WideString Value);
	virtual void __fastcall SetSelStart(const int Value);
	virtual void __fastcall SetSelLength(const int Value);
	virtual void __fastcall SetModified(const bool Value);
	virtual void __fastcall SetReadOnly(const bool Value);
	void __fastcall SetCaretPos(const TCaretPos &Value);
	void __fastcall SetHMargin(const int Value);
	void __fastcall SetLines(const Classes::TStrings* Value);
	void __fastcall SetScrollBars(const TScrollStyle Value);
	void __fastcall SetWordWrap(const bool Value);
	void __fastcall SetMaxLength(const int Value);
	void __fastcall SetAlignment(const Classes::TAlignment Value);
	void __fastcall SetWrapMode(const TWrapMode Value);
	void __fastcall SetWrapValue(const int Value);
	void __fastcall SetWrapBreak(const TWrapBreak Value);
	__property ParentColor  = {default=0};
	__property TScrollStyle ScrollBars = {read=FScrollBars, write=SetScrollBars, default=0};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property Classes::TNotifyEvent OnReturnPressed = {read=FOnReturnPressed, write=FOnReturnPressed};
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
	__property int HMargin = {read=GetHMargin, write=SetHMargin, default=3};
	__property Classes::TAlignment Alignment = {read=GetAlignment, write=SetAlignment, default=0};
	__property BorderStyle  = {default=6};
	__property Classes::TStrings* Lines = {read=FLines, write=SetLines};
	__property int MaxLength = {read=FMaxLength, write=SetMaxLength, default=-1};
	__property ShowHint  = {default=0};
	__property TabStop  = {default=1};
	__property bool WantReturns = {read=FWantReturns, write=FWantReturns, default=1};
	__property bool WantTabs = {read=FWantTabs, write=FWantTabs, default=0};
	__property bool WordWrap = {read=FWordWrap, write=SetWordWrap, default=1};
	__property int WrapAtValue = {read=GetWrapValue, write=SetWrapValue, default=-1};
	__property TWrapBreak WrapBreak = {read=GetWrapBreak, write=SetWrapBreak, default=0};
	__property TWrapMode WrapMode = {read=FWrapMode, write=SetWrapMode, default=1};
	
public:
	void __fastcall Append(const WideString Text);
	bool __fastcall AtEOF(void);
	virtual void __fastcall Clear(void);
	void __fastcall ClearSelection(void);
	void __fastcall UnSelect(void);
	void __fastcall CopyToClipboard(void);
	void __fastcall CutToClipboard(void);
	int __fastcall GetTextBuf(char * Buffer, int BufSize);
	int __fastcall GetTextLen(void);
	bool __fastcall HasSelection(void);
	HIDESBASE void __fastcall Insert(const WideString Text, bool Mark = false)/* overload */;
	HIDESBASE void __fastcall Insert(const WideString Text, int Column, int Row, bool Mark = false)/* overload */;
	void __fastcall PasteFromClipboard(void);
	void __fastcall SelectAll(void);
	__property TCaretPos CaretPos = {read=GetCaretPos, write=SetCaretPos};
	__property Qt::QOpenMultiLineEditH* Handle = {read=GetHandle};
	__property bool Modified = {read=GetModified, write=SetModified, nodefault};
	__property TMemoSelection Selection = {read=GetSelection};
	__property int SelLength = {read=GetSelLength, write=SetSelLength, nodefault};
	__property int SelStart = {read=GetSelStart, write=SetSelStart, nodefault};
	__property WideString SelText = {read=GetSelText, write=SetSelText};
	__property WideString Text = {read=GetText, write=SetText};
	__property int TextWidth[int LineNum] = {read=GetTextWidth};
	__fastcall virtual TCustomMemo(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomMemo(void);
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TCustomMemo(Qt::QWidgetH* ParentWidget) : Qcontrols::TFrameControl(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS TMemo;
class PASCALIMPLEMENTATION TMemo : public TCustomMemo 
{
	typedef TCustomMemo inherited;
	
__published:
	__property Align  = {default=0};
	__property Alignment  = {default=0};
	__property Anchors  = {default=3};
	__property BorderStyle  = {default=6};
	__property Color  = {default=-10};
	__property Constraints ;
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property HMargin  = {default=3};
	__property Lines ;
	__property MaxLength  = {default=-1};
	__property ParentColor  = {default=0};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ReadOnly  = {default=0};
	__property ScrollBars  = {default=0};
	__property ShowHint  = {default=0};
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Visible  = {default=1};
	__property WantReturns  = {default=1};
	__property WantTabs  = {default=0};
	__property WordWrap  = {default=1};
	__property WrapAtValue  = {default=-1};
	__property WrapBreak  = {default=0};
	__property WrapMode  = {default=1};
	__property OnChange ;
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
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
public:
	#pragma option push -w-inl
	/* TCustomMemo.Create */ inline __fastcall virtual TMemo(Classes::TComponent* AOwner) : TCustomMemo(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomMemo.Destroy */ inline __fastcall virtual ~TMemo(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TMemo(Qt::QWidgetH* ParentWidget) : TCustomMemo(ParentWidget) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TComboBoxStyle { csDropDown, csDropDownList, csOwnerDrawFixed, csOwnerDrawVariable };
#pragma option pop

#pragma option push -b-
enum TComboBoxInsertMode { ciNone, ciTop, ciCurrent, ciBottom, ciAfterCurrent, ciBeforeCurrent };
#pragma option pop

#pragma option push -b-
enum QStdCtrls__11 { odSelected, odGrayed, odDisabled, odChecked, odFocused, odDefault, odHotLight, odInactive, odNoAccel, odNoFocusRect, odReserved1, odReserved2, odComboBoxEdit };
#pragma option pop

typedef Set<QStdCtrls__11, odSelected, odComboBoxEdit>  TOwnerDrawState;

typedef void __fastcall (__closure *TComboBoxHighlightEvent)(System::TObject* Sender, int Index);

typedef void __fastcall (__closure *TDrawItemEvent)(System::TObject* Sender, int Index, const Types::TRect &Rect, TOwnerDrawState State, bool &Handled);

typedef void __fastcall (__closure *TMeasureItemEvent)(Qcontrols::TWidgetControl* Control, int Index, int &Height);

class DELPHICLASS TCustomComboBox;
class PASCALIMPLEMENTATION TCustomComboBox : public Qcontrols::TWidgetControl 
{
	typedef Qcontrols::TWidgetControl inherited;
	
private:
	Qgraphics::TCanvas* FCanvas;
	Classes::TStrings* FItems;
	int FMaxItems;
	int FMaxLength;
	TComboBoxStyle FStyle;
	Qt::QLineEdit_hookH* FEditHook;
	Qt::QLineEditH* FEditHandle;
	Qt::QListBox_hookH* FListHook;
	Qt::QListBoxH* FListBoxHandle;
	Qt::QClxListBoxHooksH* FListBoxDrawHooks;
	int FItemHeight;
	bool FJustDropped;
	Classes::TMemoryStream* FMemStream;
	Classes::TNotifyEvent FOnChange;
	TComboBoxHighlightEvent FOnHighlighted;
	Classes::TNotifyEvent FOnSelect;
	TEditCharCase FCharCase;
	Classes::TNotifyEvent FOnCloseUp;
	TDrawItemEvent FOnDrawItem;
	TMeasureItemEvent FOnMeasureItem;
	Classes::TNotifyEvent FOnDropDown;
	int __fastcall AdjustHeight(void);
	void __cdecl ChangeHook(System::PWideString Text);
	bool __cdecl EditEventFilter(Qt::QObjectH* Sender, Qt::QEventH* Event);
	bool __cdecl ListEventFilter(Qt::QObjectH* Sender, Qt::QEventH* Event);
	Qt::QLineEditH* __fastcall EditHandle(void);
	bool __fastcall GetAutoComplete(void);
	int __fastcall GetDropDownCount(void);
	HIDESBASE Qt::QOpenComboBoxH* __fastcall GetHandle(void);
	int __fastcall GetItemIndex(void);
	void __cdecl HighlightedHook(int Index);
	void __cdecl SelectedHook(int Index);
	void __fastcall SetAutoComplete(const bool Value);
	void __fastcall SetDropDownCount(const int Value);
	void __fastcall SetItemIndex(const int Value);
	void __fastcall SetItems(const Classes::TStrings* Value);
	void __fastcall SetMaxItems(const int Value);
	TComboBoxInsertMode __fastcall GetInsertMode(void);
	void __fastcall SetInsertMode(const TComboBoxInsertMode Value);
	void __fastcall SetDuplicates(const Classes::TDuplicates Value);
	Classes::TDuplicates __fastcall GetDuplicates(void);
	bool __fastcall GetDroppedDown(void);
	void __fastcall SetDroppedDown(const bool Value);
	int __fastcall GetSelLength(void);
	int __fastcall GetSelStart(void);
	WideString __fastcall GetSelText();
	void __fastcall SetSelLength(const int Value);
	void __fastcall SetSelStart(const int Value);
	void __fastcall SetSelText(const WideString Value);
	void __cdecl ItemPaintHook(Qt::QListBoxH* listBox, Qt::QPainterH* p, int Index, Types::PRect Rect, int Flags, bool &Handled);
	void __cdecl ItemMeasureHook(int index, int &height, int &width);
	void __fastcall SetSorted(const bool Value);
	bool __fastcall GetSorted(void);
	void __fastcall SetItemHeight(const int Value);
	int __fastcall GetItemHeight(void);
	void __fastcall DoDropDown(void);
	void __fastcall DoCloseUp(void);
	HIDESBASE MESSAGE void __fastcall CMKeyDown(Qcontrols::TCMKeyDown &Msg);
	void __fastcall SetMaxLength(const int Value);
	
protected:
	Qt::QListBoxH* __fastcall ListBoxHandle(void);
	DYNAMIC void __fastcall Change(void);
	DYNAMIC void __fastcall Click(void);
	DYNAMIC void __fastcall CloseUp(void);
	virtual void __fastcall CreateWidget(void);
	DYNAMIC void __fastcall CursorChanged(void);
	virtual void __fastcall HookEvents(void);
	virtual void __fastcall DestroyWidget(void);
	virtual bool __fastcall DrawItem(int Index, const Types::TRect &Rect, TOwnerDrawState State);
	DYNAMIC void __fastcall DoEnter(void);
	DYNAMIC void __fastcall DoExit(void);
	virtual bool __fastcall EventFilter(Qt::QObjectH* Sender, Qt::QEventH* Event);
	virtual void __fastcall MeasureItem(Qcontrols::TWidgetControl* Control, int Index, int &Height, int &Width);
	DYNAMIC void __fastcall DropDown(void);
	DYNAMIC void __fastcall FontChanged(void);
	DYNAMIC void __fastcall Highlighted(int Index);
	virtual void __fastcall InitWidget(void);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyUp(Word &Key, Classes::TShiftState Shift);
	virtual void __fastcall Loaded(void);
	DYNAMIC void __fastcall PaletteChanged(System::TObject* Sender);
	virtual WideString __fastcall GetText();
	virtual void __fastcall SetText(const WideString Value);
	virtual void __fastcall RestoreWidgetState(void);
	virtual void __fastcall SaveWidgetState(void);
	DYNAMIC void __fastcall Select(void);
	HIDESBASE virtual void __fastcall SetStyle(TComboBoxStyle Value);
	__property bool AutoComplete = {read=GetAutoComplete, write=SetAutoComplete, default=0};
	__property int DropDownCount = {read=GetDropDownCount, write=SetDropDownCount, default=8};
	__property Classes::TDuplicates Duplicates = {read=GetDuplicates, write=SetDuplicates, default=1};
	__property TComboBoxInsertMode InsertMode = {read=GetInsertMode, write=SetInsertMode, default=0};
	__property int ItemHeight = {read=GetItemHeight, write=SetItemHeight, default=16};
	__property int MaxItems = {read=FMaxItems, write=SetMaxItems, default=-1};
	__property int MaxLength = {read=FMaxLength, write=SetMaxLength, default=-1};
	__property ParentColor  = {default=0};
	__property bool Sorted = {read=GetSorted, write=SetSorted, default=0};
	__property TComboBoxStyle Style = {read=FStyle, write=SetStyle, default=0};
	__property WideString Text = {read=GetText, write=SetText};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property Classes::TNotifyEvent OnCloseUp = {read=FOnCloseUp, write=FOnCloseUp};
	__property Classes::TNotifyEvent OnDropDown = {read=FOnDropDown, write=FOnDropDown};
	__property TComboBoxHighlightEvent OnHighlighted = {read=FOnHighlighted, write=FOnHighlighted};
	__property Classes::TNotifyEvent OnSelect = {read=FOnSelect, write=FOnSelect};
	__property TDrawItemEvent OnDrawItem = {read=FOnDrawItem, write=FOnDrawItem};
	__property TMeasureItemEvent OnMeasureItem = {read=FOnMeasureItem, write=FOnMeasureItem};
	
public:
	__fastcall virtual TCustomComboBox(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomComboBox(void);
	void __fastcall Clear(void);
	DYNAMIC bool __fastcall Focused(void);
	void __fastcall SelectAll(void);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	void __fastcall Sort(void);
	__property Qgraphics::TCanvas* Canvas = {read=FCanvas};
	__property bool DroppedDown = {read=GetDroppedDown, write=SetDroppedDown, nodefault};
	__property Qt::QOpenComboBoxH* Handle = {read=GetHandle};
	__property Classes::TStrings* Items = {read=FItems, write=SetItems};
	__property int ItemIndex = {read=GetItemIndex, write=SetItemIndex, default=-1};
	__property int SelLength = {read=GetSelLength, write=SetSelLength, nodefault};
	__property int SelStart = {read=GetSelStart, write=SetSelStart, nodefault};
	__property WideString SelText = {read=GetSelText, write=SetSelText};
	
__published:
	__property TEditCharCase CharCase = {read=FCharCase, write=FCharCase, default=0};
	__property TabStop  = {default=1};
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TCustomComboBox(Qt::QWidgetH* ParentWidget) : Qcontrols::TWidgetControl(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS TComboBox;
class PASCALIMPLEMENTATION TComboBox : public TCustomComboBox 
{
	typedef TCustomComboBox inherited;
	
__published:
	__property Style  = {default=0};
	__property Anchors  = {default=3};
	__property AutoComplete  = {default=0};
	__property CharCase  = {default=0};
	__property Color  = {default=-10};
	__property Constraints ;
	__property DragMode  = {default=0};
	__property DropDownCount  = {default=8};
	__property Duplicates  = {default=1};
	__property Enabled  = {default=1};
	__property Font ;
	__property InsertMode  = {default=0};
	__property ItemHeight  = {default=16};
	__property Items ;
	__property ItemIndex  = {default=-1};
	__property MaxItems  = {default=-1};
	__property MaxLength  = {default=-1};
	__property ParentColor  = {default=0};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint  = {default=0};
	__property Sorted  = {default=0};
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Text ;
	__property Visible  = {default=1};
	__property OnChange ;
	__property OnClick ;
	__property OnCloseUp ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnDrawItem ;
	__property OnDropDown ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnHighlighted ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyString ;
	__property OnKeyUp ;
	__property OnMeasureItem ;
	__property OnSelect ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TCustomComboBox.Create */ inline __fastcall virtual TComboBox(Classes::TComponent* AOwner) : TCustomComboBox(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomComboBox.Destroy */ inline __fastcall virtual ~TComboBox(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TComboBox(Qt::QWidgetH* ParentWidget) : TCustomComboBox(ParentWidget) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TToggleState { tsOff, tsNoChange, tsOn };
#pragma option pop

typedef void __fastcall (__closure *TToggledEvent)(System::TObject* Sender, bool Toggled);

typedef void __fastcall (__closure *TStateChangedEvent)(System::TObject* Sender, TToggleState State);

class DELPHICLASS TButtonActionLink;
class DELPHICLASS TButtonControl;
class PASCALIMPLEMENTATION TButtonControl : public Qcontrols::TWidgetControl 
{
	typedef Qcontrols::TWidgetControl inherited;
	
private:
	bool FClicksDisabled;
	char FAccelChar;
	TStateChangedEvent FOnStateChanged;
	bool __fastcall IsCheckedStored(void);
	void __cdecl StateChangedHook(int State);
	bool __fastcall GetAutoRepeat(void);
	bool __fastcall GetDown(void);
	HIDESBASE Qt::QButtonH* __fastcall GetHandle(void);
	TToggleState __fastcall GetState(void);
	void __fastcall SetAutoRepeat(const bool Value);
	void __fastcall SetDown(const bool Value);
	bool __fastcall IsToggleButton(void);
	
protected:
	virtual WideString __fastcall GetText();
	virtual void __fastcall SetText(const WideString Value);
	DYNAMIC void __fastcall ActionChange(System::TObject* Sender, bool CheckDefaults);
	DYNAMIC TMetaClass* __fastcall GetActionLinkClass(void);
	virtual bool __fastcall GetChecked(void);
	virtual void __fastcall HookEvents(void);
	virtual void __fastcall SetChecked(bool Value);
	DYNAMIC void __fastcall StateChanged(TToggleState State);
	DYNAMIC bool __fastcall WantKey(int Key, Classes::TShiftState Shift, const WideString KeyText);
	__property WideString Caption = {read=GetText, write=SetText};
	__property bool Checked = {read=GetChecked, write=SetChecked, stored=IsCheckedStored, default=0};
	__property bool Down = {read=GetDown, write=SetDown, nodefault};
	__property TToggleState State = {read=GetState, nodefault};
	__property bool AutoRepeat = {read=GetAutoRepeat, write=SetAutoRepeat, default=0};
	__property bool ClicksDisabled = {read=FClicksDisabled, write=FClicksDisabled, nodefault};
	__property TStateChangedEvent OnStateChanged = {read=FOnStateChanged, write=FOnStateChanged};
	
public:
	__fastcall virtual TButtonControl(Classes::TComponent* AOwner);
	char __fastcall AccelChar(void);
	void __fastcall AnimateClick(void);
	virtual void __fastcall Toggle(void);
	__property Qt::QButtonH* Handle = {read=GetHandle};
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TButtonControl(Qt::QWidgetH* ParentWidget) : Qcontrols::TWidgetControl(ParentWidget) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWidgetControl.Destroy */ inline __fastcall virtual ~TButtonControl(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TButtonActionLink : public Qcontrols::TWidgetControlActionLink 
{
	typedef Qcontrols::TWidgetControlActionLink inherited;
	
protected:
	TButtonControl* FClient;
	virtual void __fastcall AssignClient(System::TObject* AClient);
	virtual bool __fastcall IsCheckedLinked(void);
	virtual void __fastcall SetChecked(bool Value);
public:
	#pragma option push -w-inl
	/* TBasicActionLink.Create */ inline __fastcall virtual TButtonActionLink(System::TObject* AClient) : Qcontrols::TWidgetControlActionLink(AClient) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBasicActionLink.Destroy */ inline __fastcall virtual ~TButtonActionLink(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TButtonActionLinkClass;

class DELPHICLASS TButton;
class PASCALIMPLEMENTATION TButton : public TButtonControl 
{
	typedef TButtonControl inherited;
	
private:
	bool FCancel;
	bool FDefault;
	Qforms::TModalResult FModalResult;
	TToggledEvent FOnToggled;
	HIDESBASE Qt::QPushButtonH* __fastcall GetHandle(void);
	bool __fastcall GetToggleButton(void);
	void __fastcall SetOnToggled(const TToggledEvent Value);
	void __fastcall SetToggleButton(const bool Value);
	void __cdecl ToggleHook(bool IsToggled);
	void __fastcall SetDefault(const bool Value);
	
protected:
	DYNAMIC void __fastcall BeginAutoDrag(void);
	virtual void __fastcall CreateWidget(void);
	virtual bool __fastcall EventFilter(Qt::QObjectH* Sender, Qt::QEventH* Event);
	DYNAMIC void __fastcall KeyUp(Word &Key, Classes::TShiftState Shift);
	DYNAMIC bool __fastcall NeedKey(int Key, Classes::TShiftState Shift, const WideString KeyText);
	DYNAMIC void __fastcall Toggled(bool IsToggled);
	DYNAMIC bool __fastcall WantKey(int Key, Classes::TShiftState Shift, const WideString KeyText);
	
public:
	__fastcall virtual TButton(Classes::TComponent* AOwner);
	DYNAMIC void __fastcall Click(void);
	__property Qt::QPushButtonH* Handle = {read=GetHandle};
	__property Down ;
	
__published:
	__property Action ;
	__property Anchors  = {default=3};
	__property Bitmap ;
	__property bool Cancel = {read=FCancel, write=FCancel, default=0};
	__property Caption ;
	__property Color  = {default=-2};
	__property Constraints ;
	__property bool Default = {read=FDefault, write=SetDefault, default=0};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property Qforms::TModalResult ModalResult = {read=FModalResult, write=FModalResult, default=0};
	__property ParentColor  = {default=0};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint  = {default=0};
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property bool ToggleButton = {read=GetToggleButton, write=SetToggleButton, default=0};
	__property Visible  = {default=1};
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDragDrop ;
	__property OnDragOver ;
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
	__property OnStateChanged ;
	__property TToggledEvent OnToggled = {read=FOnToggled, write=SetOnToggled};
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TButton(Qt::QWidgetH* ParentWidget) : TButtonControl(ParentWidget) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWidgetControl.Destroy */ inline __fastcall virtual ~TButton(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TCheckBoxState { cbUnchecked, cbChecked, cbGrayed };
#pragma option pop

class DELPHICLASS TCustomCheckBox;
class PASCALIMPLEMENTATION TCustomCheckBox : public TButtonControl 
{
	typedef TButtonControl inherited;
	
private:
	bool FAllowGrayed;
	TCheckBoxState FState;
	HIDESBASE Qt::QCheckBoxH* __fastcall GetHandle(void);
	void __fastcall SetState(TCheckBoxState Value);
	void __fastcall SetAllowGrayed(const bool Value);
	
protected:
	virtual void __fastcall CreateWidget(void);
	virtual bool __fastcall GetChecked(void);
	virtual void __fastcall SetChecked(bool Value);
	DYNAMIC void __fastcall StateChanged(TToggleState State);
	DYNAMIC bool __fastcall WantKey(int Key, Classes::TShiftState Shift, const WideString KeyText);
	__property bool AllowGrayed = {read=FAllowGrayed, write=SetAllowGrayed, default=0};
	__property TCheckBoxState State = {read=FState, write=SetState, default=0};
	
public:
	__fastcall virtual TCustomCheckBox(Classes::TComponent* AOwner);
	virtual void __fastcall Toggle(void);
	__property Qt::QCheckBoxH* Handle = {read=GetHandle};
	
__published:
	__property TabStop  = {default=1};
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TCustomCheckBox(Qt::QWidgetH* ParentWidget) : TButtonControl(ParentWidget) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWidgetControl.Destroy */ inline __fastcall virtual ~TCustomCheckBox(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCheckBox;
class PASCALIMPLEMENTATION TCheckBox : public TCustomCheckBox 
{
	typedef TCustomCheckBox inherited;
	
__published:
	__property Action ;
	__property AllowGrayed  = {default=0};
	__property Anchors  = {default=3};
	__property Bitmap ;
	__property Caption ;
	__property Checked  = {default=0};
	__property Color  = {default=-11};
	__property Constraints ;
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property Masked  = {default=0};
	__property ParentColor  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint  = {default=0};
	__property State  = {default=0};
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
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyString ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TCustomCheckBox.Create */ inline __fastcall virtual TCheckBox(Classes::TComponent* AOwner) : TCustomCheckBox(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TCheckBox(Qt::QWidgetH* ParentWidget) : TCustomCheckBox(ParentWidget) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWidgetControl.Destroy */ inline __fastcall virtual ~TCheckBox(void) { }
	#pragma option pop
	
};


class DELPHICLASS TRadioButton;
class PASCALIMPLEMENTATION TRadioButton : public TButtonControl 
{
	typedef TButtonControl inherited;
	
private:
	void __cdecl ClickedHook(void);
	HIDESBASE Qt::QRadioButtonH* __fastcall GetHandle(void);
	void __fastcall TurnSiblingsOff(void);
	
protected:
	virtual void __fastcall CreateWidget(void);
	virtual bool __fastcall EventFilter(Qt::QObjectH* Sender, Qt::QEventH* Event);
	virtual bool __fastcall GetChecked(void);
	virtual void __fastcall HookEvents(void);
	DYNAMIC void __fastcall MouseDown(Qcontrols::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall SetChecked(bool Value);
	DYNAMIC bool __fastcall WantKey(int Key, Classes::TShiftState Shift, const WideString KeyText);
	
public:
	__fastcall virtual TRadioButton(Classes::TComponent* AOwner);
	DYNAMIC void __fastcall Click(void);
	__property Qt::QRadioButtonH* Handle = {read=GetHandle};
	
__published:
	__property Action ;
	__property Anchors  = {default=3};
	__property Bitmap ;
	__property Caption ;
	__property Checked  = {default=0};
	__property Color  = {default=-11};
	__property Constraints ;
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
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
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
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
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TRadioButton(Qt::QWidgetH* ParentWidget) : TButtonControl(ParentWidget) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWidgetControl.Destroy */ inline __fastcall virtual ~TRadioButton(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TListBoxLayout { llFixedNumber, llFitToWidth, llVariable };
#pragma option pop

#pragma option push -b-
enum TListBoxStyle { lbStandard, lbOwnerDrawFixed, lbOwnerDrawVariable };
#pragma option pop

class DELPHICLASS TCustomListBox;
class PASCALIMPLEMENTATION TCustomListBox : public Qcontrols::TFrameControl 
{
	typedef Qcontrols::TFrameControl inherited;
	
private:
	bool FDeleting;
	Classes::TStrings* FItems;
	Qgraphics::TCanvas* FCanvas;
	TListBoxStyle FStyle;
	TDrawItemEvent FOnDrawItem;
	TMeasureItemEvent FOnMeasureItem;
	Qt::QWidget_hookH* FViewportHook;
	Qt::QWidgetH* FViewportHandle;
	Qt::QClxListBoxHooksH* FDrawHooks;
	int FItemHeight;
	Classes::TStringList* FSaveItems;
	bool FExtendedSelect;
	bool FMultiSelect;
	bool FClicking;
	void __fastcall DrawEmptyFocus(void);
	HIDESBASE Qt::QListBoxH* __fastcall GetHandle(void);
	int __fastcall GetColumns(void);
	int __fastcall GetItemIndex(void);
	int __fastcall GetSelCount(void);
	bool __fastcall GetSelected(int Index);
	int __fastcall GetTopIndex(void);
	void __fastcall SetColumns(const int Value);
	void __fastcall SetExtendedSelect(const bool Value);
	void __fastcall SetItemIndex(const int Value);
	void __fastcall SetItems(const Classes::TStrings* Value);
	void __fastcall SetMultiSelect(const bool Value);
	void __fastcall SetSelected(int Index, const bool Value);
	void __fastcall SetSorted(const bool Value);
	void __fastcall SetTopIndex(const int Value);
	int __fastcall GetRows(void);
	void __fastcall SetRows(const int Value);
	TListBoxLayout __fastcall GetColumnLayout(void);
	TListBoxLayout __fastcall GetRowLayout(void);
	void __fastcall SetColumnLayout(const TListBoxLayout Value);
	void __fastcall SetRowLayout(const TListBoxLayout Value);
	bool __cdecl ViewportEventFilter(Qt::QObjectH* Sender, Qt::QEventH* Event);
	void __cdecl ItemPaintHook(Qt::QListBoxH* listBox, Qt::QPainterH* p, int Index, Types::PRect Rect, int Flags, bool &Handled);
	void __cdecl ItemMeasureHook(int index, int &height, int &width);
	HIDESBASE void __fastcall SetStyle(const TListBoxStyle Value);
	bool __fastcall GetSorted(void);
	void __fastcall SetItemHeight(const int Value);
	void __cdecl SelChangeHook(void);
	void __fastcall AdjustHeight(void);
	
protected:
	virtual void __fastcall Changed(void);
	virtual void __fastcall CreateWidget(void);
	virtual Qt::QWidgetH* __fastcall GetChildHandle(void);
	DYNAMIC void __fastcall DblClick(void);
	DYNAMIC void __fastcall DeleteString(int Index);
	virtual bool __fastcall DrawItem(int Index, const Types::TRect &Rect, TOwnerDrawState State);
	DYNAMIC void __fastcall EnabledChanged(void);
	virtual void __fastcall MeasureItem(Qcontrols::TWidgetControl* Control, int Index, int &Height, int &Width);
	virtual bool __fastcall EventFilter(Qt::QObjectH* Sender, Qt::QEventH* Event);
	DYNAMIC void __fastcall FontChanged(void);
	DYNAMIC int __fastcall GetItemData(int Index);
	virtual void __fastcall InitWidget(void);
	virtual void __fastcall HookEvents(void);
	virtual void __fastcall Loaded(void);
	DYNAMIC void __fastcall MouseDown(Qcontrols::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall ResetContent(void);
	virtual void __fastcall RestoreWidgetState(void);
	virtual void __fastcall SaveWidgetState(void);
	DYNAMIC void __fastcall SetItemData(int Index, int AData);
	DYNAMIC void __fastcall WidgetDestroyed(void);
	__property BorderStyle  = {default=6};
	__property int Columns = {read=GetColumns, write=SetColumns, default=1};
	__property TListBoxLayout ColumnLayout = {read=GetColumnLayout, write=SetColumnLayout, default=0};
	__property bool ExtendedSelect = {read=FExtendedSelect, write=SetExtendedSelect, default=1};
	__property int ItemHeight = {read=FItemHeight, write=SetItemHeight, default=16};
	__property bool MultiSelect = {read=FMultiSelect, write=SetMultiSelect, default=0};
	__property ParentColor  = {default=0};
	__property TListBoxLayout RowLayout = {read=GetRowLayout, write=SetRowLayout, default=2};
	__property int Rows = {read=GetRows, write=SetRows, default=1};
	__property bool Sorted = {read=GetSorted, write=SetSorted, default=0};
	__property TListBoxStyle Style = {read=FStyle, write=SetStyle, default=0};
	
public:
	__fastcall virtual TCustomListBox(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomListBox(void);
	void __fastcall Clear(void);
	void __fastcall ClearSelection(void);
	int __fastcall ItemAtPos(const Types::TPoint &Pos, bool Existing);
	Types::TRect __fastcall ItemRect(int Index);
	bool __fastcall ItemVisible(int Index);
	void __fastcall MakeCurrentVisible(void);
	void __fastcall Sort(void);
	virtual void __fastcall Update(void);
	int __fastcall VisibleItemCount(void);
	__property Qgraphics::TCanvas* Canvas = {read=FCanvas};
	__property Qt::QListBoxH* Handle = {read=GetHandle};
	__property Classes::TStrings* Items = {read=FItems, write=SetItems};
	__property int ItemIndex = {read=GetItemIndex, write=SetItemIndex, nodefault};
	__property int SelCount = {read=GetSelCount, nodefault};
	__property bool Selected[int Index] = {read=GetSelected, write=SetSelected};
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	__property int TopIndex = {read=GetTopIndex, write=SetTopIndex, nodefault};
	__property TDrawItemEvent OnDrawItem = {read=FOnDrawItem, write=FOnDrawItem};
	__property TMeasureItemEvent OnMeasureItem = {read=FOnMeasureItem, write=FOnMeasureItem};
	
__published:
	__property TabStop  = {default=1};
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TCustomListBox(Qt::QWidgetH* ParentWidget) : Qcontrols::TFrameControl(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS TListBox;
class PASCALIMPLEMENTATION TListBox : public TCustomListBox 
{
	typedef TCustomListBox inherited;
	
__published:
	__property Style  = {default=0};
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property BorderStyle  = {default=6};
	__property Color  = {default=-10};
	__property Columns  = {default=1};
	__property ColumnLayout  = {default=0};
	__property Constraints ;
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property ExtendedSelect  = {default=1};
	__property Font ;
	__property ItemHeight  = {default=16};
	__property Items ;
	__property MultiSelect  = {default=0};
	__property ParentColor  = {default=0};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property RowLayout  = {default=2};
	__property Rows  = {default=1};
	__property ShowHint  = {default=0};
	__property Sorted  = {default=0};
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Visible  = {default=1};
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnDrawItem ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyString ;
	__property OnKeyUp ;
	__property OnMeasureItem ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TCustomListBox.Create */ inline __fastcall virtual TListBox(Classes::TComponent* AOwner) : TCustomListBox(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomListBox.Destroy */ inline __fastcall virtual ~TListBox(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TListBox(Qt::QWidgetH* ParentWidget) : TCustomListBox(ParentWidget) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TScrollCode { scLineUp, scLineDown, scPageUp, scPageDown, scPosition, scTrack, scTop, scBottom, scEndScroll };
#pragma option pop

typedef void __fastcall (__closure *TScrollEvent)(System::TObject* Sender, TScrollCode ScrollCode, int &ScrollPos);

class DELPHICLASS TScrollBar;
class PASCALIMPLEMENTATION TScrollBar : public Qcontrols::TWidgetControl 
{
	typedef Qcontrols::TWidgetControl inherited;
	
private:
	bool FParamsChanging;
	Qforms::TScrollBarKind FKind;
	Qt::QRangeControlH* FRangeControl;
	Classes::TNotifyEvent FOnChange;
	TScrollEvent FOnScroll;
	void __fastcall DoScroll(TScrollCode Code);
	HIDESBASE Qt::QScrollBarH* __fastcall GetHandle(void);
	void __cdecl NextLineHook(void);
	void __cdecl NextPageHook(void);
	void __cdecl PrevLineHook(void);
	void __cdecl PrevPageHook(void);
	void __fastcall SetKind(Qforms::TScrollBarKind Value);
	void __fastcall SetMax(int Value);
	void __fastcall SetMin(int Value);
	void __fastcall SetPosition(int Value);
	bool __fastcall GetTracking(void);
	void __fastcall SetTracking(const bool Value);
	void __cdecl SliderPressedHook(void);
	void __cdecl SliderReleasedHook(void);
	void __cdecl ValueChangedHook(int Value);
	int __fastcall GetPosition(void);
	Qforms::TScrollBarInc __fastcall GetLargeChange(void);
	int __fastcall GetMax(void);
	int __fastcall GetMin(void);
	Qforms::TScrollBarInc __fastcall GetSmallChange(void);
	Qt::QRangeControlH* __fastcall RangeControl(void);
	void __fastcall SetLargeChange(const Qforms::TScrollBarInc Value);
	void __fastcall SetSmallChange(const Qforms::TScrollBarInc Value);
	
protected:
	DYNAMIC void __fastcall Change(void);
	virtual void __fastcall CreateWidget(void);
	virtual void __fastcall HookEvents(void);
	virtual void __fastcall InitWidget(void);
	DYNAMIC void __fastcall KeyUp(Word &Key, Classes::TShiftState Shift);
	virtual void __fastcall Loaded(void);
	DYNAMIC void __fastcall MouseUp(Qcontrols::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall Scroll(TScrollCode ScrollCode, int &ScrollPos);
	DYNAMIC void __fastcall TabStopChanged(void);
	
public:
	__fastcall virtual TScrollBar(Classes::TComponent* AOwner);
	void __fastcall SetParams(int APosition, int AMin, int AMax);
	__property Qt::QScrollBarH* Handle = {read=GetHandle};
	
__published:
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property Bitmap ;
	__property Color  = {default=-11};
	__property Constraints ;
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Qforms::TScrollBarKind Kind = {read=FKind, write=SetKind, default=0};
	__property Qforms::TScrollBarInc LargeChange = {read=GetLargeChange, write=SetLargeChange, default=1};
	__property int Max = {read=GetMax, write=SetMax, default=100};
	__property int Min = {read=GetMin, write=SetMin, default=0};
	__property ParentColor  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property int Position = {read=GetPosition, write=SetPosition, default=0};
	__property ShowHint  = {default=0};
	__property Qforms::TScrollBarInc SmallChange = {read=GetSmallChange, write=SetSmallChange, default=1};
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property bool Track = {read=GetTracking, write=SetTracking, default=1};
	__property Visible  = {default=1};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property OnContextPopup ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyString ;
	__property OnKeyUp ;
	__property TScrollEvent OnScroll = {read=FOnScroll, write=FOnScroll};
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TScrollBar(Qt::QWidgetH* ParentWidget) : Qcontrols::TWidgetControl(ParentWidget) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWidgetControl.Destroy */ inline __fastcall virtual ~TScrollBar(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define QEventType_LBClick (Qt::QEventType)(1032)

}	/* namespace Qstdctrls */
using namespace Qstdctrls;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QStdCtrls
