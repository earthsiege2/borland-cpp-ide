// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QComCtrls.pas' rev: 6.00

#ifndef QComCtrlsHPP
#define QComCtrlsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QActnList.hpp>	// Pascal unit
#include <QButtons.hpp>	// Pascal unit
#include <QExtCtrls.hpp>	// Pascal unit
#include <QDialogs.hpp>	// Pascal unit
#include <QMenus.hpp>	// Pascal unit
#include <QImgList.hpp>	// Pascal unit
#include <QStdActns.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <QGraphics.hpp>	// Pascal unit
#include <QStdCtrls.hpp>	// Pascal unit
#include <QControls.hpp>	// Pascal unit
#include <QTypes.hpp>	// Pascal unit
#include <Qt.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qcomctrls
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EListViewException;
class PASCALIMPLEMENTATION EListViewException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EListViewException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EListViewException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EListViewException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EListViewException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EListViewException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EListViewException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EListViewException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EListViewException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EListViewException(void) { }
	#pragma option pop
	
};


class DELPHICLASS EListColumnException;
class PASCALIMPLEMENTATION EListColumnException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EListColumnException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EListColumnException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EListColumnException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EListColumnException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EListColumnException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EListColumnException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EListColumnException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EListColumnException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EListColumnException(void) { }
	#pragma option pop
	
};


class DELPHICLASS EStatusBarException;
class PASCALIMPLEMENTATION EStatusBarException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EStatusBarException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EStatusBarException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EStatusBarException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EStatusBarException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EStatusBarException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EStatusBarException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EStatusBarException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EStatusBarException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EStatusBarException(void) { }
	#pragma option pop
	
};


class DELPHICLASS EHeaderException;
class PASCALIMPLEMENTATION EHeaderException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EHeaderException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EHeaderException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EHeaderException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EHeaderException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EHeaderException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EHeaderException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EHeaderException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EHeaderException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EHeaderException(void) { }
	#pragma option pop
	
};


class DELPHICLASS ERangeException;
class PASCALIMPLEMENTATION ERangeException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ERangeException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ERangeException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ERangeException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ERangeException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ERangeException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ERangeException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ERangeException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ERangeException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ERangeException(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TTabButtons { tbLeft, tbRight };
#pragma option pop

#pragma option push -b-
enum TTabStyle { tsTabs, tsButtons, tsFlatButtons, tsNoTabs };
#pragma option pop

typedef void __fastcall (__closure *TTabChangedEvent)(System::TObject* Sender, int TabID);

typedef void __fastcall (__closure *TTabGetImageEvent)(System::TObject* Sender, int TabIndex, int &ImageIndex);

typedef void __fastcall (__closure *TTabChangingEvent)(System::TObject* Sender, bool &AllowChange);

class DELPHICLASS TCustomTabControl;
typedef void __fastcall (__closure *TDrawTabEvent)(TCustomTabControl* Control, int TabIndex, const Types::TRect &Rect, bool Active, bool &DefaultDraw);

class DELPHICLASS TTab;
class DELPHICLASS TTabs;
class PASCALIMPLEMENTATION TTab : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	bool FEnabled;
	WideString FCaption;
	#pragma pack(push, 1)
	Types::TRect FTabRect;
	#pragma pack(pop)
	
	int FRow;
	int FImageIndex;
	bool FVisible;
	bool FSelected;
	bool FHighlighted;
	TTabs* __fastcall GetTabs(void);
	int __fastcall CalculateWidth(void);
	int __fastcall CalculateHeight(void);
	void __fastcall SetCaption(const WideString Value);
	void __fastcall SetEnabled(const bool Value);
	int __fastcall GetHeight(void);
	int __fastcall GetWidth(void);
	void __fastcall SetHeight(const int Value);
	void __fastcall SetWidth(const int Value);
	int __fastcall GetLeft(void);
	int __fastcall GetTop(void);
	void __fastcall SetLeft(const int Value);
	void __fastcall SetTop(const int Value);
	void __fastcall SetVisible(const bool Value);
	int __fastcall GetImageIndex(void);
	void __fastcall SetImageIndex(const int Value);
	void __fastcall SetSelected(const bool Value);
	void __fastcall SetHighlighted(const bool Value);
	
protected:
	virtual AnsiString __fastcall GetDisplayName();
	__property int Left = {read=GetLeft, write=SetLeft, nodefault};
	__property int Top = {read=GetTop, write=SetTop, nodefault};
	__property int Height = {read=GetHeight, write=SetHeight, nodefault};
	__property int Width = {read=GetWidth, write=SetWidth, nodefault};
	
public:
	__fastcall virtual TTab(Classes::TCollection* Collection);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property TTabs* Tabs = {read=GetTabs};
	__property int Row = {read=FRow, nodefault};
	__property Types::TRect TabRect = {read=FTabRect};
	
__published:
	__property WideString Caption = {read=FCaption, write=SetCaption};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	__property bool Highlighted = {read=FHighlighted, write=SetHighlighted, default=0};
	__property int ImageIndex = {read=GetImageIndex, write=SetImageIndex, nodefault};
	__property bool Selected = {read=FSelected, write=SetSelected, default=0};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TTab(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TTabs : public Classes::TCollection 
{
	typedef Classes::TCollection inherited;
	
public:
	TTab* operator[](int Index) { return Items[Index]; }
	
private:
	TCustomTabControl* FTabControl;
	bool FUpdating;
	HIDESBASE TTab* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, const TTab* Value);
	int __fastcall CalculateTabHeight(const WideString S);
	
protected:
	DYNAMIC Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Update(Classes::TCollectionItem* Item);
	__property TCustomTabControl* TabControl = {read=FTabControl};
	
public:
	__fastcall TTabs(TCustomTabControl* TabControl);
	HIDESBASE TTab* __fastcall Add(const WideString ACaption);
	__property TTab* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TTabs(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TTabSide { tsLeft, tsTop, tsRight, tsBottom };
#pragma option pop

class PASCALIMPLEMENTATION TCustomTabControl : public Qcontrols::TCustomControl 
{
	typedef Qcontrols::TCustomControl inherited;
	
private:
	Qgraphics::TBitmap* FBitmap;
	Qbuttons::TSpeedButton* FButtons[2];
	bool FErase;
	Qgraphics::TBitmap* FDblBuffer;
	int FFirstVisibleTab;
	Qimglist::TCustomImageList* FHotImages;
	bool FHotTrack;
	Qgraphics::TColor FHotTrackColor;
	int FImageBorder;
	Qimglist::TChangeLink* FImageChangeLink;
	Qimglist::TCustomImageList* FImages;
	int FLastVisibleTab;
	int FLayoutCount;
	int FMouseOver;
	bool FMultiLine;
	bool FMultiSelect;
	bool FOwnerDraw;
	bool FRaggedRight;
	int FRowCount;
	bool FShowFrame;
	TTabStyle FStyle;
	int FTabIndex;
	TTabs* FTabs;
	#pragma pack(push, 1)
	Types::TSmallPoint FTabSize;
	#pragma pack(pop)
	
	int FTracking;
	Classes::TNotifyEvent FOnChange;
	TTabChangedEvent FOnChanged;
	TTabChangingEvent FOnChanging;
	TDrawTabEvent FOnDrawTab;
	TTabGetImageEvent FOnGetImageIndex;
	bool FUpdating;
	int __fastcall RightSide(void);
	void __fastcall ButtonClick(System::TObject* Sender);
	void __fastcall EraseControlFlag(const bool Value = true);
	void __fastcall DisplayScrollButtons(void);
	void __fastcall DrawFocus(void);
	int __fastcall GetTabHeight(void);
	void __fastcall CalcImageTextOffset(const Types::TRect &ARect, const WideString S, Qimglist::TCustomImageList* Image, Types::TPoint &ImagePos, Types::TPoint &TextPos);
	void __fastcall CalculateRows(int SelectedRow);
	void __fastcall CalculateTabPositions(void);
	void __fastcall EnableScrollButtons(void);
	int __fastcall FindNextVisibleTab(int Index);
	int __fastcall FindPrevVisibleTab(int Index);
	void __fastcall BeginDblBuffer(void);
	void __fastcall EndDblBuffer(void);
	void __fastcall StretchTabs(int ARow);
	void __fastcall CreateButtons(void);
	Types::TRect __fastcall GetDisplayRect();
	Qimglist::TCustomImageList* __fastcall GetImageRef(void);
	int __fastcall GetTabIndex(void);
	int __fastcall GetTotalTabHeight(void);
	bool __fastcall HasImages(TTab* ATab);
	void __fastcall InternalDrawTabFrame(Qgraphics::TCanvas* ACanvas, const Types::TRect &ARect, TTab* Tab, bool HotTracking = false);
	void __fastcall InternalDrawTabContents(Qgraphics::TCanvas* ACanvas, const Types::TRect &ARect, TTab* Tab, bool HotTracking = false);
	void __fastcall InternalDrawFrame(Qgraphics::TCanvas* ACanvas, const Types::TRect &ARect, bool AShowFrame = true, bool Sunken = false, bool Fill = true);
	TTabs* __fastcall GetTabs(void);
	void __fastcall PositionButtons(void);
	int __fastcall RightSideAdjustment(void);
	void __fastcall SetTabs(const TTabs* Value);
	void __fastcall SetHotTrack(const bool Value);
	void __fastcall SetHotTrackColor(const Qgraphics::TColor Value);
	void __fastcall SetImages(const Qimglist::TCustomImageList* Value);
	void __fastcall SetMultiLine(const bool Value);
	void __fastcall SetMultiSelect(const bool Value);
	void __fastcall DoHotTrack(const int Value);
	void __fastcall SetOwnerDraw(const bool Value);
	void __fastcall SetRaggedRight(const bool Value);
	HIDESBASE void __fastcall SetStyle(TTabStyle Value);
	void __fastcall SetTabHeight(const short Value);
	void __fastcall SetTabIndex(const int Value);
	void __fastcall SetTabWidth(const short Value);
	void __fastcall TabsChanged(void);
	void __fastcall SetShowFrame(const bool Value);
	void __fastcall DrawHighlight(Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, bool ASelected, bool AHighlight, bool AEnabled);
	void __fastcall SetHotImages(const Qimglist::TCustomImageList* Value);
	void __fastcall UnselectTabs(void);
	
protected:
	virtual void __fastcall AdjustClientRect(Types::TRect &Rect);
	virtual void __fastcall AdjustTabClientRect(Types::TRect &Rect);
	virtual void __fastcall AdjustTabRect(Types::TRect &Rect);
	DYNAMIC bool __fastcall CanChange(void);
	virtual bool __fastcall CanShowTab(int TabIndex);
	DYNAMIC void __fastcall Change(void);
	DYNAMIC void __fastcall Changed(int Value);
	DYNAMIC bool __fastcall DoMouseWheel(Classes::TShiftState Shift, int WheelDelta, const Types::TPoint &MousePos);
	DYNAMIC bool __fastcall DoMouseWheelDown(Classes::TShiftState Shift, const Types::TPoint &MousePos);
	DYNAMIC bool __fastcall DoMouseWheelUp(Classes::TShiftState Shift, const Types::TPoint &MousePos);
	virtual bool __fastcall DrawTab(int TabIndex, const Types::TRect &Rect, bool Active);
	DYNAMIC void __fastcall EnabledChanged(void);
	DYNAMIC void __fastcall FontChanged(void);
	virtual int __fastcall GetImageIndex(int ATabIndex);
	virtual void __fastcall ImageListChange(System::TObject* Sender);
	DYNAMIC void __fastcall KeyUp(Word &Key, Classes::TShiftState Shift);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall LayoutTabs(void);
	DYNAMIC void __fastcall MouseDown(Qcontrols::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseLeave(Qcontrols::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Qcontrols::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall Resize(void);
	DYNAMIC void __fastcall RequestAlign(void);
	DYNAMIC void __fastcall RequestLayout(void);
	void __fastcall UpdateTabImages(void);
	DYNAMIC bool __fastcall WantKey(int Key, Classes::TShiftState Shift, const WideString KeyText);
	virtual int __fastcall WidgetFlags(void);
	__property Types::TRect DisplayRect = {read=GetDisplayRect};
	__property Qimglist::TCustomImageList* HotImages = {read=FHotImages, write=SetHotImages};
	__property bool HotTrack = {read=FHotTrack, write=SetHotTrack, default=0};
	__property Qgraphics::TColor HotTrackColor = {read=FHotTrackColor, write=SetHotTrackColor, default=16711680};
	__property int ImageBorder = {read=FImageBorder, write=FImageBorder, default=4};
	__property Qimglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property bool MultiLine = {read=FMultiLine, write=SetMultiLine, default=0};
	__property bool MultiSelect = {read=FMultiSelect, write=SetMultiSelect, default=0};
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	__property bool OwnerDraw = {read=FOwnerDraw, write=SetOwnerDraw, default=0};
	__property bool RaggedRight = {read=FRaggedRight, write=SetRaggedRight, default=0};
	__property bool ShowFrame = {read=FShowFrame, write=SetShowFrame, default=0};
	__property TTabStyle Style = {read=FStyle, write=SetStyle, default=0};
	__property short TabHeight = {read=FTabSize.y, write=SetTabHeight, default=0};
	__property int TabIndex = {read=GetTabIndex, write=SetTabIndex, default=0};
	__property TTabs* Tabs = {read=GetTabs, write=SetTabs};
	__property short TabWidth = {read=FTabSize.x, write=SetTabWidth, default=0};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property TTabChangedEvent OnChanged = {read=FOnChanged, write=FOnChanged};
	__property TTabChangingEvent OnChanging = {read=FOnChanging, write=FOnChanging};
	__property TDrawTabEvent OnDrawTab = {read=FOnDrawTab, write=FOnDrawTab};
	__property TTabGetImageEvent OnGetImageIndex = {read=FOnGetImageIndex, write=FOnGetImageIndex};
	
public:
	__fastcall virtual TCustomTabControl(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomTabControl(void);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	int __fastcall IndexOfTabAt(int X, int Y);
	void __fastcall ScrollTabs(int Delta);
	Types::TRect __fastcall TabRect(int Index);
	__property Canvas ;
	__property int RowCount = {read=FRowCount, nodefault};
	__property TabStop  = {default=1};
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TCustomTabControl(Qt::QWidgetH* ParentWidget) : Qcontrols::TCustomControl(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS TTabControl;
class PASCALIMPLEMENTATION TTabControl : public TCustomTabControl 
{
	typedef TCustomTabControl inherited;
	
__published:
	__property Anchors  = {default=3};
	__property Align  = {default=0};
	__property Constraints ;
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property HotImages ;
	__property HotTrack  = {default=0};
	__property HotTrackColor  = {default=16711680};
	__property Images ;
	__property MultiLine  = {default=0};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property RaggedRight  = {default=0};
	__property ShowFrame  = {default=0};
	__property ShowHint ;
	__property Style  = {default=0};
	__property MultiSelect  = {default=0};
	__property TabHeight  = {default=0};
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Tabs ;
	__property TabIndex  = {default=0};
	__property TabWidth  = {default=0};
	__property Visible  = {default=1};
	__property OnChange ;
	__property OnChanged ;
	__property OnContextPopup ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnGetImageIndex ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnResize ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TCustomTabControl.Create */ inline __fastcall virtual TTabControl(Classes::TComponent* AOwner) : TCustomTabControl(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomTabControl.Destroy */ inline __fastcall virtual ~TTabControl(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TTabControl(Qt::QWidgetH* ParentWidget) : TCustomTabControl(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS TTabSheet;
class DELPHICLASS TPageControl;
typedef void __fastcall (__closure *TPageChangingEvent)(System::TObject* Sender, TTabSheet* NewPage, bool &AllowChange);

class PASCALIMPLEMENTATION TPageControl : public TCustomTabControl 
{
	typedef TCustomTabControl inherited;
	
private:
	Classes::TList* FPages;
	TTabSheet* FActivePage;
	Classes::TNotifyEvent FOnPageChange;
	TPageChangingEvent FOnPageChanging;
	void __fastcall DeleteTab(TTabSheet* Page, int Index);
	int __fastcall GetActivePageIndex(void);
	TTabSheet* __fastcall GetPage(int Index);
	int __fastcall GetPageCount(void);
	void __fastcall SetActivePage(TTabSheet* aPage);
	void __fastcall SetActivePageIndex(const int Value);
	void __fastcall ChangeActivePage(TTabSheet* Page);
	void __fastcall MoveTab(int CurIndex, int NewIndex);
	void __fastcall InsertPage(const TTabSheet* APage);
	void __fastcall InsertTab(TTabSheet* Page);
	void __fastcall RemovePage(const TTabSheet* APage);
	void __fastcall UpdateTab(TTabSheet* Page);
	
protected:
	DYNAMIC void __fastcall DoContextPopup(const Types::TPoint &MousePos, bool &Handled);
	virtual bool __fastcall CanShowTab(int TabIndex);
	DYNAMIC void __fastcall Changed(int Value);
	DYNAMIC void __fastcall Change(void);
	DYNAMIC bool __fastcall DesignEventQuery(Qt::QObjectH* Sender, Qt::QEventH* Event);
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	DYNAMIC void __fastcall PageChange(void);
	DYNAMIC void __fastcall PageChanging(TTabSheet* NewPage, bool &AllowChange);
	DYNAMIC void __fastcall SetChildOrder(Classes::TComponent* Child, int Order);
	virtual void __fastcall ShowControl(Qcontrols::TControl* AControl);
	virtual void __fastcall UpdateActivePage(void);
	
public:
	__fastcall virtual TPageControl(Classes::TComponent* AOwner);
	__fastcall virtual ~TPageControl(void);
	TTabSheet* __fastcall FindNextPage(TTabSheet* CurPage, bool GoForward, bool CheckTabVisible);
	void __fastcall SelectNextPage(bool GoForward);
	virtual void __fastcall Update(void);
	__property int ActivePageIndex = {read=GetActivePageIndex, write=SetActivePageIndex, nodefault};
	__property int PageCount = {read=GetPageCount, nodefault};
	__property TTabSheet* Pages[int Index] = {read=GetPage};
	
__published:
	__property TTabSheet* ActivePage = {read=FActivePage, write=SetActivePage};
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property Constraints ;
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property HotTrack  = {default=0};
	__property HotTrackColor  = {default=16711680};
	__property HotImages ;
	__property Images ;
	__property MultiLine  = {default=0};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property RaggedRight  = {default=0};
	__property ShowFrame  = {default=0};
	__property ShowHint ;
	__property Style  = {default=0};
	__property TabHeight  = {default=0};
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property TabWidth  = {default=0};
	__property Visible  = {default=1};
	__property Classes::TNotifyEvent OnChange = {read=FOnPageChange, write=FOnPageChange};
	__property OnChanging ;
	__property OnContextPopup ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnGetImageIndex ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property TPageChangingEvent OnPageChanging = {read=FOnPageChanging, write=FOnPageChanging};
	__property OnResize ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TPageControl(Qt::QWidgetH* ParentWidget) : TCustomTabControl(ParentWidget) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TTabSheet : public Qcontrols::TCustomControl 
{
	typedef Qcontrols::TCustomControl inherited;
	
private:
	Qextctrls::TBorderWidth FBorderWidth;
	Qimglist::TImageIndex FImageIndex;
	bool FHighlighted;
	TPageControl* FPageControl;
	bool FTabVisible;
	Classes::TNotifyEvent FOnHide;
	Classes::TNotifyEvent FOnShow;
	TTab* FTab;
	int __fastcall GetPageIndex(void);
	int __fastcall GetTabIndex(void);
	void __fastcall SetBorderWidth(const Qextctrls::TBorderWidth Value);
	void __fastcall SetHighlighted(const bool Value);
	void __fastcall SetImageIndex(const Qimglist::TImageIndex Value);
	void __fastcall SetPageControl(const TPageControl* Value);
	void __fastcall SetPageIndex(const int Value);
	void __fastcall SetTabVisible(const bool Value);
	
protected:
	virtual void __fastcall AdjustClientRect(Types::TRect &Rect);
	DYNAMIC void __fastcall DoHide(void);
	DYNAMIC void __fastcall DoShow(void);
	DYNAMIC void __fastcall EnabledChanged(void);
	virtual void __fastcall ReadState(Classes::TReader* Reader);
	DYNAMIC void __fastcall ShowingChanged(void);
	DYNAMIC void __fastcall TextChanged(void);
	
public:
	__fastcall virtual TTabSheet(Classes::TComponent* AOwner);
	__fastcall virtual ~TTabSheet(void);
	virtual void __fastcall InitWidget(void);
	__property TPageControl* PageControl = {read=FPageControl, write=SetPageControl};
	__property int TabIndex = {read=GetTabIndex, nodefault};
	
__published:
	__property Qextctrls::TBorderWidth BorderWidth = {read=FBorderWidth, write=SetBorderWidth, default=0};
	__property Caption ;
	__property Color  = {default=-10};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property Height  = {stored=false};
	__property bool Highlighted = {read=FHighlighted, write=SetHighlighted, default=0};
	__property Qimglist::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, default=0};
	__property Left  = {stored=false};
	__property int PageIndex = {read=GetPageIndex, write=SetPageIndex, stored=false, nodefault};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint ;
	__property bool TabVisible = {read=FTabVisible, write=SetTabVisible, default=1};
	__property Top  = {stored=false};
	__property Visible  = {stored=false, default=1};
	__property Width  = {stored=false};
	__property OnContextPopup ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property Classes::TNotifyEvent OnHide = {read=FOnHide, write=FOnHide};
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnResize ;
	__property Classes::TNotifyEvent OnShow = {read=FOnShow, write=FOnShow};
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TTabSheet(Qt::QWidgetH* ParentWidget) : Qcontrols::TCustomControl(ParentWidget) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TPanelPosition { ppLeft, ppRight };
#pragma option pop

#pragma option push -b-
enum TStatusPanelStyle { psText, psOwnerDraw };
#pragma option pop

#pragma option push -b-
enum TStatusPanelBevel { pbNone, pbLowered, pbRaised };
#pragma option pop

class DELPHICLASS TStatusPanel;
class DELPHICLASS TStatusPanels;
class PASCALIMPLEMENTATION TStatusPanel : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	Classes::TAlignment FAlignment;
	TStatusPanelBevel FBevel;
	#pragma pack(push, 1)
	Types::TRect FBounds;
	#pragma pack(pop)
	
	bool FHidden;
	TPanelPosition FPanelPosition;
	TStatusPanelStyle FStyle;
	WideString FText;
	bool FVisible;
	int FWidth;
	void __fastcall SetAlignment(const Classes::TAlignment Value);
	void __fastcall SetBevel(const TStatusPanelBevel Value);
	void __fastcall SetStyle(TStatusPanelStyle Value);
	void __fastcall SetText(const WideString Value);
	void __fastcall SetWidth(const int Value);
	void __fastcall SetPanelPosition(const TPanelPosition Value);
	void __fastcall SetVisible(const bool Value);
	TStatusPanels* __fastcall GetStatusPanels(void);
	
protected:
	virtual AnsiString __fastcall GetDisplayName();
	__property TStatusPanels* StatusPanels = {read=GetStatusPanels};
	
public:
	__fastcall virtual TStatusPanel(Classes::TCollection* Collection);
	__fastcall virtual ~TStatusPanel(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, default=0};
	__property TStatusPanelBevel Bevel = {read=FBevel, write=SetBevel, default=1};
	__property TPanelPosition PanelPosition = {read=FPanelPosition, write=SetPanelPosition, default=0};
	__property TStatusPanelStyle Style = {read=FStyle, write=SetStyle, default=0};
	__property WideString Text = {read=FText, write=SetText};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	__property int Width = {read=FWidth, write=SetWidth, default=50};
};


class DELPHICLASS TStatusBar;
typedef void __fastcall (__closure *TDrawPanelEvent)(TStatusBar* StatusBar, TStatusPanel* Panel, const Types::TRect &Rect);

typedef void __fastcall (__closure *TPanelClick)(System::TObject* Sender, TStatusPanel* Panel);

class PASCALIMPLEMENTATION TStatusBar : public Qextctrls::TCustomPanel 
{
	typedef Qextctrls::TCustomPanel inherited;
	
private:
	bool FAutoHint;
	int FUpdateCount;
	bool FSimplePanel;
	WideString FSimpleText;
	TStatusPanels* FPanels;
	TDrawPanelEvent FOnDrawPanel;
	Classes::TNotifyEvent FOnHint;
	bool FSizeGrip;
	Qt::QSizeGripH* FSizeGripHandle;
	TPanelClick FOnPanelClick;
	HIDESBASE bool __fastcall IsFontStored(void);
	void __fastcall SetPanels(const TStatusPanels* Value);
	void __fastcall SetSimplePanel(const bool Value);
	void __fastcall SetSimpleText(const WideString Value);
	void __fastcall UpdatePanels(void);
	void __fastcall SetSizeGrip(const bool Value);
	void __fastcall PositionSizeGrip(void);
	void __fastcall ValidateSizeGrip(void);
	TStatusPanel* __fastcall GetPanel(TPanelPosition PanelPosition, int Index);
	Qextctrls::TBorderWidth __fastcall GetBorderWidth(void);
	HIDESBASE void __fastcall SetBorderWidth(const Qextctrls::TBorderWidth Value);
	MESSAGE void __fastcall CMRecreateWindow(Qcontrols::TMessage &Message);
	
protected:
	DYNAMIC void __fastcall ControlsAligned(void);
	DYNAMIC void __fastcall CursorChanged(void);
	virtual bool __fastcall DoHint(void);
	DYNAMIC void __fastcall DoPanelClick(TStatusPanel* Panel);
	DYNAMIC void __fastcall DrawPanel(TStatusPanel* Panel, const Types::TRect &Rect);
	DYNAMIC void __fastcall EnabledChanged(void);
	virtual void __fastcall InitWidget(void);
	DYNAMIC void __fastcall MouseUp(Qcontrols::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall PaletteCreated(void);
	DYNAMIC void __fastcall RequestAlign(void);
	DYNAMIC void __fastcall Resize(void);
	
public:
	__fastcall virtual TStatusBar(Classes::TComponent* AOwner);
	__fastcall virtual ~TStatusBar(void);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	TStatusPanel* __fastcall FindPanel(TPanelPosition PanelPosition, int Index);
	DYNAMIC void __fastcall FlipChildren(bool AllLevels);
	virtual void __fastcall Invalidate(void);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	virtual void __fastcall Update(void);
	__property Canvas ;
	__property TStatusPanel* Panel[TPanelPosition PanelPosition][int Index] = {read=GetPanel};
	
__published:
	__property Action ;
	__property Align  = {default=2};
	__property Anchors  = {default=3};
	__property bool AutoHint = {read=FAutoHint, write=FAutoHint, default=0};
	__property Qextctrls::TBorderWidth BorderWidth = {read=GetBorderWidth, write=SetBorderWidth, default=0};
	__property Color  = {default=-11};
	__property Constraints ;
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font  = {stored=IsFontStored};
	__property TStatusPanels* Panels = {read=FPanels, write=SetPanels};
	__property ParentColor  = {default=0};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint ;
	__property bool SimplePanel = {read=FSimplePanel, write=SetSimplePanel, default=0};
	__property WideString SimpleText = {read=FSimpleText, write=SetSimpleText};
	__property bool SizeGrip = {read=FSizeGrip, write=SetSizeGrip, default=1};
	__property Visible  = {default=1};
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property TDrawPanelEvent OnDrawPanel = {read=FOnDrawPanel, write=FOnDrawPanel};
	__property OnEndDrag ;
	__property Classes::TNotifyEvent OnHint = {read=FOnHint, write=FOnHint};
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property TPanelClick OnPanelClick = {read=FOnPanelClick, write=FOnPanelClick};
	__property OnResize ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TStatusBar(Qt::QWidgetH* ParentWidget) : Qextctrls::TCustomPanel(ParentWidget) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TStatusPanels : public Classes::TCollection 
{
	typedef Classes::TCollection inherited;
	
public:
	TStatusPanel* operator[](int Index) { return Items[Index]; }
	
private:
	int FFixedPanelCount;
	TStatusBar* FStatusBar;
	HIDESBASE TStatusPanel* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, const TStatusPanel* Value);
	
protected:
	DYNAMIC Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Update(Classes::TCollectionItem* Item);
	__property TStatusBar* StatusBar = {read=FStatusBar};
	
public:
	__fastcall TStatusPanels(TStatusBar* StatusBar);
	HIDESBASE TStatusPanel* __fastcall Add(void);
	__property TStatusPanel* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TStatusPanels(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TTrackBarOrientation { trHorizontal, trVertical };
#pragma option pop

#pragma option push -b-
enum TTickMark { tmBottomRight, tmTopLeft, tmBoth };
#pragma option pop

#pragma option push -b-
enum TTickStyle { tsNone, tsAuto };
#pragma option pop

#pragma option push -b-
enum QTickSetting { qtsNoMarks, qtsAbove, qtsLeft, qtsBelow, qtsRight, qtsBoth };
#pragma option pop

class DELPHICLASS TTrackBar;
class PASCALIMPLEMENTATION TTrackBar : public Qcontrols::TWidgetControl 
{
	typedef Qcontrols::TWidgetControl inherited;
	
private:
	int FMin;
	int FMax;
	Classes::TNotifyEvent FOnChange;
	TTickMark FTickMarks;
	TTickStyle FTickStyle;
	TTrackBarOrientation FOrientation;
	void __fastcall ChangeAspectRatio(void);
	HIDESBASE Qt::QClxSliderH* __fastcall GetHandle(void);
	void __fastcall SetFrequency(const int Value);
	void __fastcall SetLineSize(const int Value);
	void __fastcall SetMax(const int Value);
	void __fastcall SetMin(const int Value);
	void __fastcall SetOrientation(const TTrackBarOrientation Value);
	void __fastcall SetPageSize(const int Value);
	void __fastcall SetPosition(const int Value);
	void __fastcall SetRange(const int AMin, const int AMax);
	void __fastcall SetTickMarks(const TTickMark Value);
	void __fastcall SetTickStyle(const TTickStyle Value);
	TTrackBarOrientation __fastcall GetOrientation(void);
	int __fastcall GetFrequency(void);
	Qt::QRangeControlH* __fastcall GetRangeControl(void);
	int __fastcall GetLineSize(void);
	int __fastcall GetPageSize(void);
	int __fastcall GetMax(void);
	int __fastcall GetMin(void);
	int __fastcall GetPosition(void);
	TTickMark __fastcall GetTickMarks(void);
	TTickStyle __fastcall GetTickStyle(void);
	void __fastcall UpdateSettings(void);
	void __cdecl ValueChangedHook(int Value);
	
protected:
	DYNAMIC void __fastcall Changed(void);
	virtual void __fastcall CreateWidget(void);
	virtual void __fastcall HookEvents(void);
	virtual void __fastcall InitWidget(void);
	virtual void __fastcall Loaded(void);
	__property Qt::QRangeControlH* RangeControl = {read=GetRangeControl};
	
public:
	__fastcall virtual TTrackBar(Classes::TComponent* AOwner);
	__property Qt::QClxSliderH* Handle = {read=GetHandle};
	
__published:
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property Bitmap ;
	__property Constraints ;
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property int Frequency = {read=GetFrequency, write=SetFrequency, default=1};
	__property Hint ;
	__property int LineSize = {read=GetLineSize, write=SetLineSize, default=1};
	__property Masked  = {default=0};
	__property int Max = {read=GetMax, write=SetMax, default=10};
	__property int Min = {read=GetMin, write=SetMin, default=0};
	__property TTrackBarOrientation Orientation = {read=GetOrientation, write=SetOrientation, default=0};
	__property int PageSize = {read=GetPageSize, write=SetPageSize, default=2};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property int Position = {read=GetPosition, write=SetPosition, default=0};
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property TTickMark TickMarks = {read=GetTickMarks, write=SetTickMarks, default=0};
	__property TTickStyle TickStyle = {read=GetTickStyle, write=SetTickStyle, default=1};
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
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TTrackBar(Qt::QWidgetH* ParentWidget) : Qcontrols::TWidgetControl(ParentWidget) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWidgetControl.Destroy */ inline __fastcall virtual ~TTrackBar(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TProgressBarChangeEvent)(System::TObject* Sender, WideString &Text, int NewPosition);

#pragma option push -b-
enum TProgressBarOrientation { pbHorizontal, pbVertical };
#pragma option pop

class DELPHICLASS TProgressBar;
class PASCALIMPLEMENTATION TProgressBar : public Qcontrols::TGraphicControl 
{
	typedef Qcontrols::TGraphicControl inherited;
	
private:
	Qextctrls::TBorderWidth FBorderWidth;
	Qgraphics::TColor FFillColor;
	#pragma pack(push, 1)
	Types::TRect FFillArea;
	#pragma pack(pop)
	
	int FSections;
	int FStep;
	int FMin;
	int FMax;
	TProgressBarOrientation FOrientation;
	int FPosition;
	WideString FPrevText;
	bool FShowCaption;
	bool FSmooth;
	bool FTransparent;
	WideString FText;
	Qgraphics::TColor FTextColor;
	int FTotalSteps;
	bool FWrapRange;
	TProgressBarChangeEvent FOnChanging;
	Types::TRect __fastcall AdjustToParent(const Types::TRect &Rect);
	Types::TRect __fastcall CalcTextRect(const Types::TRect &Rect, const Types::TRect &BoundingRect, const WideString AText);
	void __fastcall EraseText(const WideString AText, Qgraphics::TColor BackgroundColor);
	void __fastcall InternalPaint(void);
	void __fastcall InternalDrawFrame(void);
	int __fastcall ScalePosition(int Value);
	void __fastcall SetBorderWidth(const Qextctrls::TBorderWidth Value);
	void __fastcall SetFillColor(const Qgraphics::TColor Value);
	void __fastcall SetMax(const int Value);
	void __fastcall SetMin(const int Value);
	void __fastcall SetOrientation(const TProgressBarOrientation Value);
	void __fastcall SetPosition(int Value);
	void __fastcall SetRange(const int AMin, const int AMax);
	void __fastcall SetShowCaption(const bool Value);
	void __fastcall SetSmooth(const bool Value);
	void __fastcall SetStep(const int Value);
	void __fastcall SetTransparent(const bool Value);
	
protected:
	DYNAMIC void __fastcall Changing(WideString &Text, int NewPosition);
	DYNAMIC void __fastcall FontChanged(void);
	virtual WideString __fastcall GetText();
	virtual void __fastcall Paint(void);
	virtual void __fastcall SetText(const WideString Value);
	__property bool WrapRange = {read=FWrapRange, write=FWrapRange, nodefault};
	
public:
	__fastcall virtual TProgressBar(Classes::TComponent* AOwner);
	void __fastcall StepBy(int Delta);
	virtual void __fastcall StepIt(void);
	
__published:
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property Qextctrls::TBorderWidth BorderWidth = {read=FBorderWidth, write=SetBorderWidth, default=0};
	__property Caption ;
	__property Color  = {default=-10};
	__property Constraints ;
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Qgraphics::TColor FillColor = {read=FFillColor, write=SetFillColor, default=-13};
	__property Font ;
	__property Hint ;
	__property int Max = {read=FMax, write=SetMax, default=100};
	__property int Min = {read=FMin, write=SetMin, default=0};
	__property TProgressBarOrientation Orientation = {read=FOrientation, write=SetOrientation, default=0};
	__property ParentColor  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property int Position = {read=FPosition, write=SetPosition, default=0};
	__property bool ShowCaption = {read=FShowCaption, write=SetShowCaption, default=0};
	__property ShowHint ;
	__property bool Smooth = {read=FSmooth, write=SetSmooth, default=0};
	__property int Step = {read=FStep, write=SetStep, default=10};
	__property bool Transparent = {read=FTransparent, write=SetTransparent, default=0};
	__property Visible  = {default=1};
	__property TProgressBarChangeEvent OnChanging = {read=FOnChanging, write=FOnChanging};
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
	/* TGraphicControl.Destroy */ inline __fastcall virtual ~TProgressBar(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMimeSourceFactory;
class PASCALIMPLEMENTATION TMimeSourceFactory : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	Classes::TStrings* FFilePath;
	void __fastcall SetFilePath(const Classes::TStrings* Value);
	
protected:
	Qt::QMimeSourceFactoryH* FHandle;
	virtual void __fastcall CreateHandle(void);
	virtual void __fastcall DestroyWidget(void);
	Qt::QMimeSourceFactoryH* __fastcall GetHandle(void);
	bool __fastcall HandleAllocated(void);
	void __fastcall HandleNeeded(void);
	void __cdecl DoGetDataHook(System::PWideString AbsoluteName, Qt::QMimeSourceH* &ResolvedData);
	virtual void __fastcall GetData(const AnsiString AbsoluteName, Qt::QMimeSourceH* &ResolvedData);
	
public:
	__fastcall TMimeSourceFactory(void);
	__fastcall virtual ~TMimeSourceFactory(void);
	void __fastcall AddDataToFactory(const WideString Name, Qt::QMimeSourceH* Data);
	void __fastcall AddImageToFactory(const WideString Name, Qt::QImageH* Data);
	void __fastcall AddPixmapToFactory(const WideString Name, Qt::QPixmapH* Data);
	void __fastcall AddTextToFactory(const WideString Name, const AnsiString Data);
	Qt::QMimeSourceH* __fastcall GetMimeSource(const WideString MimeType);
	void __fastcall RegisterMimeType(const WideString FileExt, const AnsiString MimeType);
	__property Qt::QMimeSourceFactoryH* Handle = {read=GetHandle};
	
__published:
	__property Classes::TStrings* FilePath = {read=FFilePath, write=SetFilePath};
};


#pragma option push -b-
enum TTextFormat { tfPlainText, tfText, tfAutoText };
#pragma option pop

class DELPHICLASS TCustomTextViewer;
class PASCALIMPLEMENTATION TCustomTextViewer : public Qcontrols::TFrameControl 
{
	typedef Qcontrols::TFrameControl inherited;
	
private:
	Qgraphics::TBrush* FBrush;
	TMimeSourceFactory* FFactory;
	bool FUseDefaultFactory;
	Qt::QWidgetH* FViewportHandle;
	Qt::QWidget_hookH* FViewportHook;
	Qgraphics::TColor FTextColor;
	AnsiString FFileName;
	bool FUnderlineLink;
	Qgraphics::TColor FLinkColor;
	TTextFormat FTextFormat;
	Qt::QScrollBarH* FVScrollHandle;
	Qt::QScrollBarH* FHScrollHandle;
	Qt::QScrollBar_hookH* FVScrollHook;
	Qt::QScrollBar_hookH* FHScrollHook;
	void __fastcall SubmitTextColor(void);
	void __fastcall SetTextFormat(const TTextFormat Value);
	void __fastcall SetUnderlineLink(const bool Value);
	WideString __fastcall GetDocumentTitle();
	bool __fastcall GetIsTextSelected(void);
	WideString __fastcall GetSelectedText();
	Qgraphics::TBrush* __fastcall GetBrush(void);
	HIDESBASE void __fastcall SetBrush(const Qgraphics::TBrush* Value);
	void __fastcall SetTextColor(const Qgraphics::TColor Value);
	WideString __fastcall GetDocumentText();
	void __fastcall SetLinkColor(const Qgraphics::TColor Value);
	virtual void __fastcall SetDocumentText(const WideString Value);
	TMimeSourceFactory* __fastcall GetFactory(void);
	void __fastcall SetFactory(const TMimeSourceFactory* Value);
	void __fastcall SetDefaultFactory(const bool Value);
	void __fastcall SetFileName(const AnsiString Value);
	void __fastcall UpdateViewableContents(void);
	
protected:
	virtual void __fastcall CreateWidget(void);
	virtual Qt::QWidgetH* __fastcall GetChildHandle(void);
	HIDESBASE QTextViewH* __fastcall GetHandle(void);
	virtual void __fastcall InitWidget(void);
	void __fastcall PaperChanged(System::TObject* Sender);
	Qt::QWidgetH* __fastcall ViewportHandle(void);
	DYNAMIC void __fastcall WidgetDestroyed(void);
	__property WideString DocumentTitle = {read=GetDocumentTitle};
	__property QTextViewH* Handle = {read=GetHandle};
	__property BorderStyle  = {default=6};
	__property TMimeSourceFactory* Factory = {read=GetFactory, write=SetFactory};
	__property AnsiString FileName = {read=FFileName, write=SetFileName};
	__property Height  = {default=150};
	__property bool IsTextSelected = {read=GetIsTextSelected, nodefault};
	__property Qgraphics::TColor LinkColor = {read=FLinkColor, write=SetLinkColor, default=16711680};
	__property Qgraphics::TBrush* Paper = {read=GetBrush, write=SetBrush};
	__property WideString SelectedText = {read=GetSelectedText};
	__property WideString Text = {read=GetDocumentText, write=SetDocumentText};
	__property Qgraphics::TColor TextColor = {read=FTextColor, write=SetTextColor, default=0};
	__property TTextFormat TextFormat = {read=FTextFormat, write=SetTextFormat, default=2};
	__property bool UnderlineLink = {read=FUnderlineLink, write=SetUnderlineLink, default=1};
	__property bool UseDefaultFactory = {read=FUseDefaultFactory, write=SetDefaultFactory, nodefault};
	__property Width  = {default=200};
	
public:
	__fastcall virtual TCustomTextViewer(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomTextViewer(void);
	void __fastcall SelectAll(void);
	void __fastcall CopyToClipboard(void);
	virtual void __fastcall LoadFromFile(const AnsiString AFileName);
	void __fastcall LoadFromStream(Classes::TStream* Stream);
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TCustomTextViewer(Qt::QWidgetH* ParentWidget) : Qcontrols::TFrameControl(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS TTextViewer;
class PASCALIMPLEMENTATION TTextViewer : public TCustomTextViewer 
{
	typedef TCustomTextViewer inherited;
	
public:
	__property DocumentTitle ;
	__property Factory ;
	__property Handle ;
	__property IsTextSelected ;
	__property Paper ;
	__property SelectedText ;
	__property Text ;
	
__published:
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property BorderStyle  = {default=6};
	__property Constraints ;
	__property DragMode  = {default=0};
	__property Height  = {default=150};
	__property FileName ;
	__property LinkColor  = {default=16711680};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=0};
	__property TextColor  = {default=0};
	__property TextFormat  = {default=2};
	__property UnderlineLink  = {default=1};
	__property Width  = {default=200};
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
	/* TCustomTextViewer.Create */ inline __fastcall virtual TTextViewer(Classes::TComponent* AOwner) : TCustomTextViewer(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomTextViewer.Destroy */ inline __fastcall virtual ~TTextViewer(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TTextViewer(Qt::QWidgetH* ParentWidget) : TCustomTextViewer(ParentWidget) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TRTBHighlightTextEvent)(System::TObject* Sender, const WideString HighlightedText);

class DELPHICLASS TCustomTextBrowser;
class PASCALIMPLEMENTATION TCustomTextBrowser : public TCustomTextViewer 
{
	typedef TCustomTextViewer inherited;
	
private:
	bool FBackwardAvailable;
	bool FForwardAvailable;
	TRTBHighlightTextEvent FRTBHighlightText;
	Classes::TNotifyEvent FTextChanged;
	virtual void __fastcall SetDocumentText(const WideString Value);
	void __cdecl HookBackwardAvailable(bool p1);
	void __cdecl HookForwardAvailable(bool p1);
	void __cdecl HookHighlightText(System::PWideString p1);
	void __cdecl HookTextChanged(void);
	void __fastcall SetHighlightText(const TRTBHighlightTextEvent Value);
	void __fastcall SetTextChanged(const Classes::TNotifyEvent Value);
	
protected:
	virtual void __fastcall CreateWidget(void);
	DYNAMIC void __fastcall WidgetDestroyed(void);
	virtual void __fastcall HookEvents(void);
	HIDESBASE QTextBrowserH* __fastcall GetHandle(void);
	__property QTextBrowserH* Handle = {read=GetHandle};
	__property TRTBHighlightTextEvent OnHighlightText = {read=FRTBHighlightText, write=SetHighlightText};
	__property Classes::TNotifyEvent OnTextChanged = {read=FTextChanged, write=SetTextChanged};
	
public:
	virtual void __fastcall LoadFromFile(const AnsiString AFileName);
	void __fastcall ScrollToAnchor(const WideString AnchorName);
	bool __fastcall CanGoBackward(void);
	void __fastcall Backward(void);
	bool __fastcall CanGoForward(void);
	void __fastcall Forward(void);
	void __fastcall Home(void);
public:
	#pragma option push -w-inl
	/* TCustomTextViewer.Create */ inline __fastcall virtual TCustomTextBrowser(Classes::TComponent* AOwner) : TCustomTextViewer(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomTextViewer.Destroy */ inline __fastcall virtual ~TCustomTextBrowser(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TCustomTextBrowser(Qt::QWidgetH* ParentWidget) : TCustomTextViewer(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS TTextBrowser;
class PASCALIMPLEMENTATION TTextBrowser : public TCustomTextBrowser 
{
	typedef TCustomTextBrowser inherited;
	
public:
	__property DocumentTitle ;
	__property Handle ;
	__property IsTextSelected ;
	__property Paper ;
	__property SelectedText ;
	__property Text ;
	
__published:
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property BorderStyle  = {default=6};
	__property Constraints ;
	__property DragMode  = {default=0};
	__property Factory ;
	__property FileName ;
	__property Height  = {default=150};
	__property LinkColor  = {default=16711680};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=0};
	__property TextColor  = {default=0};
	__property TextFormat  = {default=2};
	__property UnderlineLink  = {default=1};
	__property Width  = {default=200};
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnHighlightText ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDrag ;
	__property OnTextChanged ;
public:
	#pragma option push -w-inl
	/* TCustomTextViewer.Create */ inline __fastcall virtual TTextBrowser(Classes::TComponent* AOwner) : TCustomTextBrowser(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomTextViewer.Destroy */ inline __fastcall virtual ~TTextBrowser(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TTextBrowser(Qt::QWidgetH* ParentWidget) : TCustomTextBrowser(ParentWidget) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TSEButtonType { btNext, btPrev };
#pragma option pop

#pragma option push -b-
enum TSEButtonStyle { bsArrows, bsPlusMinus };
#pragma option pop

#pragma option push -b-
enum TSEDownDirection { sedNone, sedUp, sedDown };
#pragma option pop

typedef void __fastcall (__closure *TSEChangedEvent)(System::TObject* Sender, int NewValue);

class DELPHICLASS TCustomSpinEdit;
class PASCALIMPLEMENTATION TCustomSpinEdit : public Qcontrols::TWidgetControl 
{
	typedef Qcontrols::TWidgetControl inherited;
	
private:
	Qt::QWidget_hookH* FButtonUpHook;
	Qt::QWidget_hookH* FButtonDownHook;
	Qt::QWidgetH* FEditHandle;
	Qt::QWidget_hookH* FEditHook;
	Qt::QWidgetH* FDownButtonHandle;
	int FMin;
	int FMax;
	Qt::QWidgetH* FUpButtonHandle;
	TSEChangedEvent FOnChanged;
	TSEButtonStyle __fastcall GetButtonStyle(void);
	WideString __fastcall GetCleanText();
	int __fastcall GetIncrement(void);
	int __fastcall GetMax(void);
	int __fastcall GetMin(void);
	WideString __fastcall GetPrefix();
	Qt::QRangeControlH* __fastcall GetRangeControl(void);
	WideString __fastcall GetSuffix();
	WideString __fastcall GetSpecialText();
	int __fastcall GetValue(void);
	bool __fastcall GetWrap(void);
	void __cdecl ValueChangedHook(int AValue);
	void __fastcall SetButtonStyle(TSEButtonStyle AValue);
	void __fastcall SetIncrement(int AValue);
	void __fastcall SetMax(int AValue);
	void __fastcall SetMin(int AValue);
	void __fastcall SetPrefix(const WideString AValue);
	void __fastcall SetRange(const int AMin, const int AMax);
	void __fastcall SetSuffix(const WideString AValue);
	void __fastcall SetSpecialText(const WideString AValue);
	void __fastcall SetWrap(bool AValue);
	HIDESBASE Qt::QClxSpinBoxH* __fastcall GetHandle(void);
	void __fastcall SetValue(const int AValue);
	
protected:
	virtual void __fastcall CreateWidget(void);
	DYNAMIC void __fastcall WidgetDestroyed(void);
	virtual bool __fastcall EventFilter(Qt::QObjectH* Sender, Qt::QEventH* Event);
	virtual void __fastcall HookEvents(void);
	DYNAMIC void __fastcall Change(int AValue);
	virtual WideString __fastcall GetText();
	virtual void __fastcall InitWidget(void);
	virtual void __fastcall Loaded(void);
	DYNAMIC void __fastcall PaletteChanged(System::TObject* Sender);
	__property TSEButtonStyle ButtonStyle = {read=GetButtonStyle, write=SetButtonStyle, default=0};
	__property WideString CleanText = {read=GetCleanText};
	__property Qt::QClxSpinBoxH* Handle = {read=GetHandle};
	__property int Max = {read=GetMax, write=SetMax, default=100};
	__property int Min = {read=GetMin, write=SetMin, default=0};
	__property int Increment = {read=GetIncrement, write=SetIncrement, default=1};
	__property WideString Prefix = {read=GetPrefix, write=SetPrefix};
	__property Qt::QRangeControlH* RangeControl = {read=GetRangeControl};
	__property WideString SpecialText = {read=GetSpecialText, write=SetSpecialText};
	__property WideString Suffix = {read=GetSuffix, write=SetSuffix};
	__property TabStop  = {default=1};
	__property WideString Text = {read=GetText};
	__property int Value = {read=GetValue, write=SetValue, default=0};
	__property bool Wrap = {read=GetWrap, write=SetWrap, default=0};
	__property TSEChangedEvent OnChanged = {read=FOnChanged, write=FOnChanged};
	
public:
	__fastcall virtual TCustomSpinEdit(Classes::TComponent* AOwner);
	void __fastcall StepUp(void);
	void __fastcall StepDown(void);
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TCustomSpinEdit(Qt::QWidgetH* ParentWidget) : Qcontrols::TWidgetControl(ParentWidget) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWidgetControl.Destroy */ inline __fastcall virtual ~TCustomSpinEdit(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSpinEdit;
class PASCALIMPLEMENTATION TSpinEdit : public TCustomSpinEdit 
{
	typedef TCustomSpinEdit inherited;
	
public:
	__property CleanText ;
	__property Text ;
	
__published:
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property ButtonStyle  = {default=0};
	__property Constraints ;
	__property Color  = {default=-10};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Hint ;
	__property Max  = {default=100};
	__property Min  = {default=0};
	__property Increment  = {default=1};
	__property PopupMenu ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Value  = {default=0};
	__property Visible  = {default=1};
	__property ParentShowHint  = {default=1};
	__property Prefix ;
	__property ShowHint ;
	__property SpecialText ;
	__property Suffix ;
	__property Wrap  = {default=0};
	__property OnChanged ;
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
	/* TCustomSpinEdit.Create */ inline __fastcall virtual TSpinEdit(Classes::TComponent* AOwner) : TCustomSpinEdit(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TSpinEdit(Qt::QWidgetH* ParentWidget) : TCustomSpinEdit(ParentWidget) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWidgetControl.Destroy */ inline __fastcall virtual ~TSpinEdit(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomHeaderSection;
class DELPHICLASS TCustomHeaderControl;
#pragma option push -b-
enum THeaderOrientation { hoHorizontal, hoVertical };
#pragma option pop

class DELPHICLASS TCustomHeaderSections;
typedef TMetaClass*THeaderSectionClass;

class PASCALIMPLEMENTATION TCustomHeaderSections : public Classes::TCollection 
{
	typedef Classes::TCollection inherited;
	
public:
	TCustomHeaderSection* operator[](int Index) { return Items[Index]; }
	
private:
	TCustomHeaderControl* FHeaderControl;
	void __fastcall UpdateImages(void);
	
protected:
	DYNAMIC Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Update(Classes::TCollectionItem* Item);
	HIDESBASE TCustomHeaderSection* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TCustomHeaderSection* Value);
	
public:
	__fastcall TCustomHeaderSections(TCustomHeaderControl* HeaderControl, TMetaClass* SectionClass);
	__property TCustomHeaderSection* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TCustomHeaderSections(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TSectionNotifyEvent)(TCustomHeaderControl* HeaderControl, TCustomHeaderSection* Section);

class PASCALIMPLEMENTATION TCustomHeaderControl : public Qcontrols::TWidgetControl 
{
	typedef Qcontrols::TWidgetControl inherited;
	
private:
	bool FClickable;
	bool FDragReorder;
	bool FResizable;
	bool FTracking;
	THeaderOrientation FOrientation;
	TCustomHeaderSections* FSections;
	Classes::TMemoryStream* FMemStream;
	TSectionNotifyEvent FOnSectionResize;
	TSectionNotifyEvent FOnSectionClick;
	TSectionNotifyEvent FOnSectionMoved;
	Qgraphics::TCanvas* FCanvas;
	Qimglist::TCustomImageList* FImages;
	Qimglist::TChangeLink* FImageChanges;
	bool FDontResubmit;
	void __fastcall OnImageChanges(System::TObject* Sender);
	void __cdecl SectionClicked(int SectionIndex);
	void __cdecl SectionSizeChanged(int SectionIndex, int OldSize, int NewSize);
	void __cdecl SectionMoved(int FromIndex, int ToIndex);
	void __fastcall SetClickable(const bool Value);
	void __fastcall SetDragReorder(const bool Value);
	void __fastcall SetOrientation(const THeaderOrientation Value);
	void __fastcall SetResizable(const bool Value);
	void __fastcall SetTracking(const bool Value);
	void __fastcall SetSections(const TCustomHeaderSections* Value);
	TCustomHeaderSections* __fastcall GetSections(void);
	void __fastcall SetImages(const Qimglist::TCustomImageList* Value);
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	HIDESBASE virtual Qt::QHeaderH* __fastcall GetHandle(void);
	virtual void __fastcall CreateWidget(void);
	virtual void __fastcall HookEvents(void);
	virtual void __fastcall ChangeBounds(int ALeft, int ATop, int AWidth, int AHeight);
	DYNAMIC void __fastcall ColumnClicked(TCustomHeaderSection* Section);
	DYNAMIC void __fastcall ColumnMoved(TCustomHeaderSection* Section);
	DYNAMIC void __fastcall ColumnResized(TCustomHeaderSection* Section);
	DYNAMIC void __fastcall ImageListChanged(void);
	virtual void __fastcall InitWidget(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall RestoreWidgetState(void);
	virtual void __fastcall SaveWidgetState(void);
	__property Align  = {default=1};
	__property Qgraphics::TCanvas* Canvas = {read=FCanvas};
	__property bool Clickable = {read=FClickable, write=SetClickable, default=0};
	__property Qt::QHeaderH* Handle = {read=GetHandle};
	__property Height  = {default=19};
	__property bool DragReorder = {read=FDragReorder, write=SetDragReorder, default=0};
	__property Qimglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property bool Resizable = {read=FResizable, write=SetResizable, default=0};
	__property TCustomHeaderSections* Sections = {read=GetSections, write=SetSections};
	__property bool Tracking = {read=FTracking, write=SetTracking, default=0};
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnResize ;
	__property TSectionNotifyEvent OnSectionClick = {read=FOnSectionClick, write=FOnSectionClick};
	__property TSectionNotifyEvent OnSectionResize = {read=FOnSectionResize, write=FOnSectionResize};
	__property TSectionNotifyEvent OnSectionMoved = {read=FOnSectionMoved, write=FOnSectionMoved};
	__property THeaderOrientation Orientation = {read=FOrientation, write=SetOrientation, default=0};
	
public:
	__fastcall virtual TCustomHeaderControl(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomHeaderControl(void);
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TCustomHeaderControl(Qt::QWidgetH* ParentWidget) : Qcontrols::TWidgetControl(ParentWidget) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TCustomHeaderSection : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	bool FAllowResize;
	bool FAllowClick;
	int FMaxWidth;
	int FWidth;
	int FMinWidth;
	TCustomHeaderControl* FHeader;
	Qimglist::TImageIndex FImageIndex;
	bool FAutoSize;
	WideString FText;
	void __fastcall UpdateWidth(void);
	TCustomHeaderControl* __fastcall Header(void);
	void __fastcall SetAllowClick(const bool Value);
	void __fastcall SetAllowResize(const bool Value);
	void __fastcall SetMaxWidth(const int Value);
	void __fastcall SetMinWidth(const int Value);
	void __fastcall SetWidth(int Value);
	int __fastcall GetLeft(void);
	int __fastcall GetRight(void);
	void __fastcall SetImageIndex(const Qimglist::TImageIndex Value);
	void __fastcall UpdateImage(void);
	void __fastcall SetAutoSize(const bool Value);
	int __fastcall CalcSize(void);
	
protected:
	virtual void __fastcall AddSection(void);
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	virtual AnsiString __fastcall GetDisplayName();
	virtual int __fastcall GetWidth(void);
	virtual void __fastcall Resubmit(void);
	virtual void __fastcall SetWidthVal(const int Value);
	__property bool AllowClick = {read=FAllowClick, write=SetAllowClick, nodefault};
	__property bool AllowResize = {read=FAllowResize, write=SetAllowResize, nodefault};
	__property bool AutoSize = {read=FAutoSize, write=SetAutoSize, nodefault};
	__property Qimglist::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, nodefault};
	__property int Left = {read=GetLeft, nodefault};
	__property int MaxWidth = {read=FMaxWidth, write=SetMaxWidth, nodefault};
	__property int MinWidth = {read=FMinWidth, write=SetMinWidth, nodefault};
	__property int Right = {read=GetRight, nodefault};
	__property int Width = {read=GetWidth, write=SetWidth, nodefault};
	
public:
	__fastcall virtual TCustomHeaderSection(Classes::TCollection* Collection);
public:
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TCustomHeaderSection(void) { }
	#pragma option pop
	
};


class DELPHICLASS THeaderSection;
class PASCALIMPLEMENTATION THeaderSection : public TCustomHeaderSection 
{
	typedef TCustomHeaderSection inherited;
	
private:
	void __fastcall SetText(const WideString Value);
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	virtual void __fastcall SetWidthVal(const int Value);
	WideString __fastcall GetText();
	
public:
	__fastcall virtual ~THeaderSection(void);
	__property Index ;
	__property Left ;
	__property Right ;
	
__published:
	__property AllowClick  = {default=1};
	__property AllowResize  = {default=1};
	__property AutoSize  = {default=0};
	__property ImageIndex  = {default=-1};
	__property MaxWidth  = {default=1000};
	__property MinWidth ;
	__property WideString Text = {read=GetText, write=SetText};
	__property Width  = {default=50};
public:
	#pragma option push -w-inl
	/* TCustomHeaderSection.Create */ inline __fastcall virtual THeaderSection(Classes::TCollection* Collection) : TCustomHeaderSection(Collection) { }
	#pragma option pop
	
};


class DELPHICLASS THeaderSections;
class PASCALIMPLEMENTATION THeaderSections : public TCustomHeaderSections 
{
	typedef TCustomHeaderSections inherited;
	
public:
	THeaderSection* operator[](int Index) { return Items[Index]; }
	
protected:
	HIDESBASE THeaderSection* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, THeaderSection* Value);
	
public:
	HIDESBASE THeaderSection* __fastcall Add(void);
	__property THeaderSection* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TCustomHeaderSections.Create */ inline __fastcall THeaderSections(TCustomHeaderControl* HeaderControl, TMetaClass* SectionClass) : TCustomHeaderSections(HeaderControl, SectionClass) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~THeaderSections(void) { }
	#pragma option pop
	
};


class DELPHICLASS THeaderControl;
class PASCALIMPLEMENTATION THeaderControl : public TCustomHeaderControl 
{
	typedef TCustomHeaderControl inherited;
	
private:
	HIDESBASE void __fastcall SetSections(const THeaderSections* Value);
	HIDESBASE THeaderSections* __fastcall GetSections(void);
	void __fastcall Init(TMetaClass* AHeaderSectionClass);
	
protected:
	virtual void __fastcall CreateWidget(void);
	virtual void __fastcall InitWidget(void);
	
public:
	__fastcall virtual THeaderControl(Classes::TComponent* AOwner)/* overload */;
	__fastcall THeaderControl(Classes::TComponent* AOwner, TMetaClass* AHeaderSectionClass)/* overload */;
	__fastcall virtual ~THeaderControl(void);
	__property Canvas ;
	
__published:
	__property Align  = {default=1};
	__property Anchors  = {default=3};
	__property Clickable  = {default=0};
	__property Constraints ;
	__property DragMode  = {default=0};
	__property DragReorder  = {default=0};
	__property Height  = {default=19};
	__property Hint ;
	__property Images ;
	__property Orientation  = {default=0};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property Resizable  = {default=0};
	__property THeaderSections* Sections = {read=GetSections, write=SetSections};
	__property ShowHint ;
	__property Tracking  = {default=0};
	__property OnConstrainedResize ;
	__property OnContextPopup ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnResize ;
	__property OnSectionClick ;
	__property OnSectionResize ;
	__property OnSectionMoved ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall THeaderControl(Qt::QWidgetH* ParentWidget) : TCustomHeaderControl(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS TListColumn;
class DELPHICLASS TCustomViewControl;
class PASCALIMPLEMENTATION TListColumn : public TCustomHeaderSection 
{
	typedef TCustomHeaderSection inherited;
	
private:
	Classes::TAlignment FAlignment;
	bool FAutoSize;
	void __fastcall SetCaption(const WideString Value);
	HIDESBASE void __fastcall SetAutoSize(const bool Value);
	void __fastcall SetAlignment(const Classes::TAlignment Value);
	bool __fastcall HeaderIsListHeader(void);
	WideString __fastcall GetCaption();
	
protected:
	virtual void __fastcall AddSection(void);
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	virtual int __fastcall GetWidth(void);
	virtual void __fastcall Resubmit(void);
	virtual void __fastcall SetWidthVal(const int Value);
	TCustomViewControl* __fastcall ViewControl(void);
	
public:
	__fastcall virtual ~TListColumn(void);
	__property Index ;
	
__published:
	__property Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, default=0};
	__property AllowClick  = {default=1};
	__property AllowResize  = {default=1};
	__property bool AutoSize = {read=FAutoSize, write=SetAutoSize, default=0};
	__property WideString Caption = {read=GetCaption, write=SetCaption};
	__property MaxWidth  = {default=1000};
	__property MinWidth  = {default=0};
	__property Width ;
public:
	#pragma option push -w-inl
	/* TCustomHeaderSection.Create */ inline __fastcall virtual TListColumn(Classes::TCollection* Collection) : TCustomHeaderSection(Collection) { }
	#pragma option pop
	
};


class DELPHICLASS TListColumns;
class PASCALIMPLEMENTATION TListColumns : public TCustomHeaderSections 
{
	typedef TCustomHeaderSections inherited;
	
public:
	TListColumn* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TListColumn* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TListColumn* Value);
	TCustomViewControl* __fastcall GetViewControl(void);
	
protected:
	virtual void __fastcall Added(Classes::TCollectionItem* &Item);
	virtual void __fastcall Update(Classes::TCollectionItem* Item);
	__property TCustomViewControl* ViewControl = {read=GetViewControl};
	
public:
	HIDESBASE TListColumn* __fastcall Add(void);
	__property TListColumn* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TCustomHeaderSections.Create */ inline __fastcall TListColumns(TCustomHeaderControl* HeaderControl, TMetaClass* SectionClass) : TCustomHeaderSections(HeaderControl, SectionClass) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TListColumns(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TListViewItemType { itDefault, itCheckBox, itRadioButton, itController };
#pragma option pop

class DELPHICLASS TViewItemsList;
class DELPHICLASS TCustomViewItem;
class PASCALIMPLEMENTATION TViewItemsList : public Contnrs::TObjectList 
{
	typedef Contnrs::TObjectList inherited;
	
public:
	TCustomViewItem* operator[](int Index) { return Items[Index]; }
	
protected:
	HIDESBASE TCustomViewItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TCustomViewItem* AObject);
	__property TCustomViewItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TObjectList.Create */ inline __fastcall TViewItemsList(void)/* overload */ : Contnrs::TObjectList() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TViewItemsList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomViewItems;
class PASCALIMPLEMENTATION TCustomViewItems : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
public:
	TCustomViewItem* operator[](int Index) { return Item[Index]; }
	
private:
	unsigned FUpdateCount;
	TCustomViewControl* FOwner;
	TViewItemsList* FItems;
	TCustomViewItem* __fastcall GetItem(int Index);
	void __fastcall SetItem(int Index, const TCustomViewItem* Value);
	int __fastcall GetCount(void);
	
protected:
	Qt::QListViewH* __fastcall GetHandle(void);
	TCustomViewItem* __fastcall FindViewItem(Qt::QListViewItemH* ItemH);
	void __fastcall SetUpdateState(bool Updating);
	__property TCustomViewControl* Owner = {read=FOwner};
	__property Qt::QListViewH* Handle = {read=GetHandle};
	
public:
	__fastcall virtual TCustomViewItems(TCustomViewControl* AOwner);
	__fastcall virtual ~TCustomViewItems(void);
	void __fastcall BeginUpdate(void);
	void __fastcall Clear(void);
	void __fastcall EndUpdate(void);
	void __fastcall ChangeItemTypes(TListViewItemType NewType);
	int __fastcall IndexOf(TCustomViewItem* Value);
	void __fastcall Delete(int Index);
	__property int Count = {read=GetCount, nodefault};
	__property TCustomViewItem* Item[int Index] = {read=GetItem, write=SetItem/*, default*/};
};


typedef TMetaClass*TListItemClass;

class DELPHICLASS TListItems;
class DELPHICLASS TListItem;
class DELPHICLASS TCustomListView;
class PASCALIMPLEMENTATION TListItems : public TCustomViewItems 
{
	typedef TCustomViewItems inherited;
	
public:
	TListItem* operator[](int Index) { return Item[Index]; }
	
private:
	TMetaClass*FListItemClass;
	HIDESBASE TListItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, const TListItem* Value);
	TCustomListView* __fastcall GetItemsOwner(void);
	
protected:
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	TListItem* __fastcall FindItem(Qt::QListViewItemH* ItemH);
	void __fastcall ReadData(Classes::TStream* Stream);
	void __fastcall WriteData(Classes::TStream* Stream);
	
public:
	__fastcall virtual TListItems(TCustomViewControl* AOwner)/* overload */;
	__fastcall TListItems(TCustomViewControl* AOwner, TMetaClass* AItemClass)/* overload */;
	TListItem* __fastcall Add(void);
	TListItem* __fastcall AddItem(TListItem* Item, int Index = 0xffffffff);
	TListItem* __fastcall Insert(int Index);
	void __fastcall SetItemClass(TMetaClass* AListItemClass);
	__property TListItem* Item[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property TCustomListView* Owner = {read=GetItemsOwner};
public:
	#pragma option push -w-inl
	/* TCustomViewItems.Destroy */ inline __fastcall virtual ~TListItems(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TItemState { isNone, isFocused, isSelected, isActivating };
#pragma option pop

typedef Set<TItemState, isNone, isActivating>  TItemStates;

class PASCALIMPLEMENTATION TCustomViewItem : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	Classes::TStrings* FSubItems;
	TCustomViewItems* FOwner;
	TListViewItemType FItemType;
	TCustomViewItem* FParent;
	TCustomViewItem* FNextItem;
	TCustomViewItem* FPrevItem;
	TCustomViewItem* FLastChild;
	void *FData;
	bool FChecked;
	bool FExpandable;
	bool FSelectable;
	WideString FText;
	TItemStates FStates;
	Qimglist::TImageIndex FImageIndex;
	bool FDestroying;
	bool __fastcall ViewControlValid(void);
	void __fastcall DetermineCreationType(void);
	void __fastcall SetCaption(const WideString Value);
	int __fastcall GetChildCount(void);
	int __fastcall GetTotalHeight(void);
	bool __fastcall GetExpanded(void);
	void __fastcall SetExpanded(const bool Value);
	int __fastcall GetHeight(void);
	bool __fastcall GetSelected(void);
	void __fastcall SetExpandable(const bool Value);
	void __fastcall SetSelectable(const bool Value);
	void __fastcall SetSelected(const bool Value);
	void __fastcall SetChecked(const bool Value);
	void __fastcall SetItemType(const TListViewItemType Value);
	void __fastcall SetParent(const TCustomViewItem* Value);
	int __fastcall GetIndex(void);
	void __fastcall SetImageIndex(const Qimglist::TImageIndex Value);
	int __fastcall GetSubItemImages(int Column);
	void __fastcall SetSubItemImages(int Column, const int Value);
	Qt::QClxListViewHooksH* __fastcall ItemHook(void);
	int __fastcall GetWidth(void);
	void __fastcall SetSubItems(const Classes::TStrings* Value);
	Classes::TStrings* __fastcall GetSubItems(void);
	void __fastcall UpdateImages(void);
	bool __fastcall GetFocused(void);
	void __fastcall SetFocused(const bool Value);
	
protected:
	Qt::QListViewItemH* FHandle;
	void __fastcall Collapse(void);
	void __fastcall CreateWidget(TCustomViewItem* AParent, TCustomViewItem* After);
	void __fastcall DestroyWidget(void);
	void __fastcall Expand(void);
	Qt::QListViewItemH* __fastcall GetHandle(void);
	bool __fastcall HandleAllocated(void);
	virtual void __fastcall ImageIndexChange(int ColIndex, int NewIndex);
	void __fastcall InsertItem(TCustomViewItem* AItem);
	int __fastcall ParentCount(void);
	void __fastcall ReCreateItem(void);
	void __fastcall RemoveItem(TCustomViewItem* AItem);
	void __fastcall Repaint(void);
	virtual void __fastcall ResetFields(void);
	TCustomViewControl* __fastcall ViewControl(void);
	__property WideString Caption = {read=FText, write=SetCaption};
	__property bool Checked = {read=FChecked, write=SetChecked, nodefault};
	__property int ChildCount = {read=GetChildCount, nodefault};
	__property void * Data = {read=FData, write=FData};
	__property bool Expandable = {read=FExpandable, write=SetExpandable, nodefault};
	__property bool Expanded = {read=GetExpanded, write=SetExpanded, nodefault};
	__property bool Focused = {read=GetFocused, write=SetFocused, nodefault};
	__property Qt::QListViewItemH* Handle = {read=GetHandle};
	__property int Height = {read=GetHeight, nodefault};
	__property Qimglist::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, nodefault};
	__property int Index = {read=GetIndex, nodefault};
	__property TListViewItemType ItemType = {read=FItemType, write=SetItemType, nodefault};
	__property TCustomViewItems* Owner = {read=FOwner};
	__property TCustomViewItem* Parent = {read=FParent, write=SetParent};
	__property bool Selectable = {read=FSelectable, write=SetSelectable, nodefault};
	__property bool Selected = {read=GetSelected, write=SetSelected, nodefault};
	__property TItemStates States = {read=FStates, nodefault};
	__property int SubItemImages[int Column] = {read=GetSubItemImages, write=SetSubItemImages};
	__property Classes::TStrings* SubItems = {read=GetSubItems, write=SetSubItems};
	__property int TotalHeight = {read=GetTotalHeight, nodefault};
	__property int Width = {read=GetWidth, nodefault};
	
public:
	__fastcall virtual TCustomViewItem(TCustomViewItems* AOwner, TCustomViewItem* AParent, TCustomViewItem* After);
	__fastcall virtual ~TCustomViewItem(void);
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	void __fastcall Delete(void);
	Types::TRect __fastcall DisplayRect();
	void __fastcall MakeVisible(bool PartialOK);
};


class PASCALIMPLEMENTATION TListItem : public TCustomViewItem 
{
	typedef TCustomViewItem inherited;
	
private:
	TCustomListView* __fastcall GetListView(void);
	TListItems* __fastcall GetOwnerlist(void);
	bool __fastcall IsEqual(TListItem* Item);
	WideString __fastcall GetCaption();
	HIDESBASE void __fastcall SetCaption(WideString Value);
	
public:
	__fastcall virtual ~TListItem(void);
	__property Caption  = {read=GetCaption, write=SetCaption};
	__property Checked ;
	__property Data ;
	__property Focused ;
	__property Handle ;
	__property ImageIndex ;
	__property Index ;
	__property ItemType ;
	__property TCustomListView* ListView = {read=GetListView};
	__property TListItems* Owner = {read=GetOwnerlist};
	__property Selectable ;
	__property Selected ;
	__property SubItemImages ;
	__property SubItems ;
public:
	#pragma option push -w-inl
	/* TCustomViewItem.Create */ inline __fastcall virtual TListItem(TCustomViewItems* AOwner, TCustomViewItem* AParent, TCustomViewItem* After) : TCustomViewItem(AOwner, AParent, After) { }
	#pragma option pop
	
};


class DELPHICLASS TItemEditor;
class PASCALIMPLEMENTATION TItemEditor : public Qstdctrls::TCustomEdit 
{
	typedef Qstdctrls::TCustomEdit inherited;
	
private:
	Qt::QPopupMenu_hookH* FMenuHook;
	TCustomViewItem* FItem;
	bool FEditing;
	bool FShouldClose;
	Qt::QPopupMenuH* FPopup;
	Qt::QFrameH* FFrame;
	Qt::QFrame_hookH* FFrameHooks;
	TCustomViewControl* FViewControl;
	void __cdecl FrameDestroyedHook(void);
	bool __cdecl PopupMenuFilter(Qt::QObjectH* Sender, Qt::QEventH* Event);
	
protected:
	void __fastcall ClearMenuHook(void);
	virtual void __fastcall CreateWidget(void);
	virtual void __fastcall Execute(void);
	virtual void __fastcall EditFinished(bool Accepted);
	virtual bool __fastcall EventFilter(Qt::QObjectH* Sender, Qt::QEventH* Event);
	virtual void __fastcall HookEvents(void);
	void __fastcall InitItem(void);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyUp(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(char &Key);
	DYNAMIC void __fastcall KeyString(WideString &S, bool &Handled);
	
public:
	__fastcall virtual TItemEditor(Classes::TComponent* AOwner);
	__fastcall virtual ~TItemEditor(void);
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TItemEditor(Qt::QWidgetH* ParentWidget) : Qstdctrls::TCustomEdit(ParentWidget) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TItemChange { ctText, ctImage, ctState };
#pragma option pop

#pragma option push -b-
enum TSortDirection { sdAscending, sdDescending };
#pragma option pop

#pragma option push -b-
enum QComCtrls__83 { cdsSelected, cdsGrayed, cdsDisabled, cdsChecked, cdsFocused, cdsDefault, cdsHot, cdsMarked, cdsIndeterminate };
#pragma option pop

typedef Set<QComCtrls__83, cdsSelected, cdsIndeterminate>  TCustomDrawState;

#pragma option push -b-
enum TCustomDrawStage { cdPrePaint, cdPostPaint };
#pragma option pop

typedef void __fastcall (__closure *TViewColumnRClickEvent)(System::TObject* Sender, TListColumn* Column, const Types::TPoint &Point);

typedef void __fastcall (__closure *TViewColumnEvent)(System::TObject* Sender, TListColumn* Column);

typedef void __fastcall (__closure *TViewColumnClickEvent)(System::TObject* Sender, TListColumn* Column);

typedef void __fastcall (__closure *TViewColumnResizeEvent)(System::TObject* Sender, TListColumn* Column);

typedef void __fastcall (__closure *TViewColumnMovedEvent)(System::TObject* Sender, TListColumn* Column);

typedef void __fastcall (__closure *TCustomDrawViewItemEvent)(TCustomViewControl* Sender, TCustomViewItem* Item, Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, TCustomDrawState State, TCustomDrawStage Stage, bool &DefaultDraw);

typedef void __fastcall (__closure *TCustomDrawViewSubItemEvent)(TCustomViewControl* Sender, TCustomViewItem* Item, int SubItem, Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, TCustomDrawState State, TCustomDrawStage Stage, bool &DefaultDraw);

class PASCALIMPLEMENTATION TCustomViewControl : public Qcontrols::TFrameControl 
{
	typedef Qcontrols::TFrameControl inherited;
	
private:
	bool FShowColumnSortIndicators;
	bool FMultiSelect;
	bool FRowSelect;
	bool FShowColumnHeaders;
	Qimglist::TCustomImageList* FImageList;
	TCustomHeaderControl* FHeader;
	Classes::TMemoryStream* FMemStream;
	Qt::QWidgetH* FViewportHandle;
	Qt::QWidget_hookH* FViewportHooks;
	Qt::QScrollBar_hookH* FHScrollHooks;
	Qt::QScrollBar_hookH* FVScrollHooks;
	Qt::QScrollBarH* FVScrollHandle;
	Qt::QScrollBarH* FHScrollHandle;
	Qt::QClxListViewHooksH* FItemHooks;
	TViewColumnEvent FOnColumnClick;
	TViewColumnEvent FColumnDragged;
	TViewColumnEvent FColumnResize;
	TCustomDrawViewItemEvent FOnCustomDrawItem;
	TCustomDrawViewSubItemEvent FOnCustomDrawSubItem;
	TCustomDrawViewItemEvent FOnCustomDrawBranch;
	bool FSorted;
	int FSortColumn;
	TSortDirection FSortDirection;
	bool FOwnerDraw;
	Qextctrls::TTimer* FTimer;
	bool FAllowEdit;
	bool FReadOnly;
	TItemEditor* FEditor;
	int FSelCount;
	int FIndent;
	Qimglist::TChangeLink* FImageLink;
	void __fastcall ImageListChange(System::TObject* Sender);
	virtual void __fastcall RepopulateItems(void);
	void __fastcall CheckRemoveEditor(void);
	void __fastcall SetIndent(const int Value);
	HIDESBASE Qt::QListViewH* __fastcall GetHandle(void);
	int __fastcall GetIndent(void);
	void __fastcall SetMultiSelect(const bool Value);
	bool __fastcall GetMultiSelect(void);
	bool __fastcall GetRowSelect(void);
	void __fastcall SetRowSelect(const bool Value);
	void __fastcall SetImageList(const Qimglist::TCustomImageList* Value);
	void __cdecl ItemDestroyedHook(Qt::QListViewItemH* AItem);
	virtual void __fastcall ItemDestroyed(Qt::QListViewItemH* AItem);
	void __cdecl ItemPaintHook(Qt::QPainterH* p, Qt::QListViewItemH* item, int column, int width, int alignment, int &stage);
	void __cdecl BranchPaintHook(Qt::QPainterH* p, Qt::QListViewItemH* item, int w, int y, int h, Qt::GUIStyle style, int &stage);
	void __cdecl ItemChangeHook(Qt::QListViewItemH* item, TItemChange _type);
	virtual void __fastcall ItemChange(Qt::QListViewItemH* item, TItemChange _type);
	void __cdecl ItemChangingHook(Qt::QListViewItemH* item, TItemChange _type, bool &Allow);
	virtual void __fastcall ItemChanging(Qt::QListViewItemH* item, TItemChange _type, bool &Allow);
	void __cdecl ItemSelectedHook(Qt::QListViewItemH* item, bool wasSelected);
	virtual void __fastcall ItemSelected(Qt::QListViewItemH* item, bool wasSelected);
	void __cdecl ItemExpandingHook(Qt::QListViewItemH* item, bool Expand, bool &Allow);
	virtual void __fastcall ItemExpanding(Qt::QListViewItemH* item, bool Expand, bool &Allow);
	void __cdecl ItemExpandedHook(Qt::QListViewItemH* item, bool Expand);
	virtual void __fastcall ItemExpanded(Qt::QListViewItemH* item, bool Expand);
	void __cdecl ItemCheckedHook(Qt::QListViewItemH* item, bool Checked);
	virtual void __fastcall ItemChecked(Qt::QListViewItemH* item, bool Checked);
	bool __fastcall GetColumnClick(void);
	void __fastcall SetColumnClick(const bool Value);
	void __fastcall SetColumns(const TListColumns* Value);
	TListColumns* __fastcall GetColumns(void);
	void __fastcall SetShowColumnSortIndicators(const bool Value);
	bool __fastcall GetColumnResize(void);
	void __fastcall SetColumnResize(const bool Value);
	bool __fastcall GetColumnMove(void);
	void __fastcall SetColumnMove(const bool Value);
	void __fastcall SetSorted(const bool Value);
	void __fastcall SetOwnerDraw(const bool Value);
	void __fastcall TimerIntervalElapsed(System::TObject* Sender);
	void __fastcall StartEditTimer(void);
	void __fastcall EditItem(void);
	void __cdecl ViewportDestroyed(void);
	
protected:
	DYNAMIC void __fastcall BeginAutoDrag(void);
	DYNAMIC void __fastcall ColorChanged(void);
	virtual void __fastcall CreateWidget(void);
	virtual TItemEditor* __fastcall CreateEditor(void);
	virtual bool __fastcall DoCustomDrawViewItem(TCustomViewItem* Item, Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, TCustomDrawState State, TCustomDrawStage Stage);
	virtual bool __fastcall DoCustomDrawViewSubItem(TCustomViewItem* Item, int SubItem, Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, TCustomDrawState State, TCustomDrawStage Stage);
	virtual bool __fastcall DoCustomDrawViewBranch(TCustomViewItem* Item, Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, TCustomDrawState State, TCustomDrawStage Stage);
	virtual void __fastcall DoDrawItem(TCustomViewItem* Item, Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, Qstdctrls::TOwnerDrawState State);
	DYNAMIC void __fastcall DoEditing(TCustomViewItem* AItem, bool &AllowEdit);
	DYNAMIC void __fastcall DoEdited(TCustomViewItem* AItem, WideString &S);
	virtual void __fastcall DoGetImageIndex(TCustomViewItem* item);
	virtual bool __fastcall EventFilter(Qt::QObjectH* Sender, Qt::QEventH* Event);
	TCustomViewItem* __fastcall FindDropTarget(void);
	virtual Qt::QWidgetH* __fastcall GetChildHandle(void);
	virtual void __fastcall HookEvents(void);
	virtual void __fastcall InitWidget(void);
	virtual bool __fastcall IsCustomDrawn(void);
	virtual bool __fastcall IsOwnerDrawn(void);
	DYNAMIC bool __fastcall NeedKey(int Key, Classes::TShiftState Shift, const WideString KeyText);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall ImageListChanged(void);
	void __fastcall SetShowColumnHeaders(const bool Value);
	void __fastcall UpdateControl(void);
	Qt::QWidgetH* __fastcall ViewportHandle(void);
	DYNAMIC void __fastcall WidgetDestroyed(void);
	__property bool ColumnClick = {read=GetColumnClick, write=SetColumnClick, default=0};
	__property bool ColumnResize = {read=GetColumnResize, write=SetColumnResize, default=0};
	__property bool ColumnMove = {read=GetColumnMove, write=SetColumnMove, default=1};
	__property TListColumns* Columns = {read=GetColumns, write=SetColumns};
	__property Qimglist::TCustomImageList* Images = {read=FImageList, write=SetImageList};
	__property Height  = {default=97};
	__property int Indent = {read=GetIndent, write=SetIndent, default=20};
	__property bool MultiSelect = {read=GetMultiSelect, write=SetMultiSelect, nodefault};
	__property bool OwnerDraw = {read=FOwnerDraw, write=SetOwnerDraw, default=0};
	__property ParentColor  = {default=0};
	__property bool ReadOnly = {read=FReadOnly, write=FReadOnly, default=0};
	__property bool RowSelect = {read=GetRowSelect, write=SetRowSelect, default=0};
	__property int SelCount = {read=FSelCount, default=0};
	__property bool ShowColumnHeaders = {read=FShowColumnHeaders, write=SetShowColumnHeaders, default=0};
	__property bool ShowColumnSortIndicators = {read=FShowColumnSortIndicators, write=SetShowColumnSortIndicators, default=0};
	__property int SortColumn = {read=FSortColumn, write=FSortColumn, default=0};
	__property TSortDirection SortDirection = {read=FSortDirection, write=FSortDirection, default=0};
	__property bool Sorted = {read=FSorted, write=SetSorted, default=0};
	__property TabStop  = {default=1};
	__property Width  = {default=121};
	__property TViewColumnEvent OnColumnClick = {read=FOnColumnClick, write=FOnColumnClick};
	__property TViewColumnEvent OnColumnDragged = {read=FColumnDragged, write=FColumnDragged};
	__property TViewColumnEvent OnColumnResize = {read=FColumnResize, write=FColumnResize};
	__property TCustomDrawViewItemEvent OnCustomDrawBranch = {read=FOnCustomDrawBranch, write=FOnCustomDrawBranch};
	__property TCustomDrawViewItemEvent OnCustomDrawItem = {read=FOnCustomDrawItem, write=FOnCustomDrawItem};
	__property TCustomDrawViewSubItemEvent OnCustomDrawSubItem = {read=FOnCustomDrawSubItem, write=FOnCustomDrawSubItem};
	
public:
	__fastcall virtual TCustomViewControl(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomViewControl(void);
	void __fastcall InvertSelection(void);
	bool __fastcall IsEditing(void);
	void __fastcall Sort(int Column, TSortDirection Direction);
	__property Qt::QListViewH* Handle = {read=GetHandle};
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TCustomViewControl(Qt::QWidgetH* ParentWidget) : Qcontrols::TFrameControl(ParentWidget) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TItemFind { ifData, ifPartialString, ifExactString, ifNearest };
#pragma option pop

#pragma option push -b-
enum TSearchDirection { sdAbove, sdBelow, sdAll };
#pragma option pop

#pragma option push -b-
enum TViewStyle { vsList, vsReport };
#pragma option pop

typedef void __fastcall (__closure *TLVNotifyEvent)(System::TObject* Sender, TListItem* Item);

typedef void __fastcall (__closure *TLVChangeEvent)(System::TObject* Sender, TListItem* Item, TItemChange Change);

typedef void __fastcall (__closure *TLVChangingEvent)(System::TObject* Sender, TListItem* Item, TItemChange Change, bool &AllowChange);

typedef void __fastcall (__closure *TLVItemExitViewportEnterEvent)(System::TObject* Sender);

typedef void __fastcall (__closure *TLVSelectItemEvent)(System::TObject* Sender, TListItem* Item, bool Selected);

typedef void __fastcall (__closure *TLVItemClickEvent)(System::TObject* Sender, Qcontrols::TMouseButton Button, TListItem* Item, const Types::TPoint &Pt, int ColIndex);

typedef void __fastcall (__closure *TLVItemDoubleClickEvent)(System::TObject* Sender, TListItem* Item);

typedef void __fastcall (__closure *TLVEditingEvent)(System::TObject* Sender, TListItem* Item, bool &AllowEdit);

typedef void __fastcall (__closure *TLVEditedEvent)(System::TObject* Sender, TListItem* Item, WideString &S);

typedef void __fastcall (__closure *TLVButtonDownEvent)(System::TObject* Sender, Qcontrols::TMouseButton Button, TListItem* Item, const Types::TPoint &Pt, int ColIndex);

typedef void __fastcall (__closure *TLVViewportButtonDownEvent)(System::TObject* Sender, Qcontrols::TMouseButton Button, const Types::TPoint &Pt);

typedef void __fastcall (__closure *TListViewDrawItemEvent)(TCustomListView* Sender, TListItem* Item, Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, Qstdctrls::TOwnerDrawState State);

class PASCALIMPLEMENTATION TCustomListView : public TCustomViewControl 
{
	typedef TCustomViewControl inherited;
	
private:
	TListItem* FSelected;
	TListItems* FItems;
	bool FCheckBoxes;
	TLVNotifyEvent FOnInsert;
	TLVChangeEvent FOnChange;
	TLVChangingEvent FOnChanging;
	TLVNotifyEvent FOnDeletion;
	TLVSelectItemEvent FOnSelectItem;
	TLVItemClickEvent FOnItemClick;
	TLVNotifyEvent FOnItemDoubleClick;
	TLVNotifyEvent FOnItemEnter;
	Classes::TNotifyEvent FOnItemExitViewportEnter;
	TLVButtonDownEvent FOnMouseDown;
	TLVViewportButtonDownEvent FOnViewportMouseDown;
	TLVEditingEvent FOnEditing;
	TLVEditedEvent FOnEdited;
	TViewStyle FViewStyle;
	bool FDownsHooked;
	TLVNotifyEvent FOnGetImageIndex;
	TListViewDrawItemEvent FOnDrawItem;
	virtual void __fastcall RepopulateItems(void);
	void __fastcall SetItems(const TListItems* Value);
	void __fastcall SetCheckBoxes(const bool Value);
	void __fastcall UpdateItemTypes(void);
	void __fastcall HookMouseDowns(void);
	void __cdecl DoItemDoubleClick(Qt::QListViewItemH* ListItem);
	void __cdecl DoItemClick(int Button, Qt::QListViewItemH* ListItem, Types::PPoint Pt, int ColIndex);
	void __cdecl DoOnItemEnter(Qt::QListViewItemH* ListItem);
	void __cdecl DoOnItemExitViewportEnter(void);
	void __cdecl DoLVMouseDown(int Button, Qt::QListViewItemH* ListItem, Types::PPoint Pt, int ColIndex);
	void __fastcall SetOnItemDoubleClick(const TLVNotifyEvent Value);
	void __fastcall SetOnItemEnter(const TLVNotifyEvent Value);
	void __fastcall SetOnItemExitViewportEnter(const Classes::TNotifyEvent Value);
	void __fastcall SetOnMouseDown(const TLVButtonDownEvent Value);
	void __fastcall SetOnViewportButtonDown(const TLVViewportButtonDownEvent Value);
	void __fastcall SetViewStyle(const TViewStyle Value);
	TListItem* __fastcall GetSelected(void);
	void __fastcall SetSelected(const TListItem* Value);
	TListItem* __fastcall GetItemFocused(void);
	void __fastcall SetItemFocused(const TListItem* Value);
	void __fastcall SetTopItem(const TListItem* AItem);
	TListItem* __fastcall GetTopItem(void);
	
protected:
	virtual void __fastcall DoDrawItem(TCustomViewItem* Item, Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, Qstdctrls::TOwnerDrawState State);
	DYNAMIC void __fastcall DoEdited(TCustomViewItem* AItem, WideString &S);
	DYNAMIC void __fastcall DoEditing(TCustomViewItem* AItem, bool &AllowEdit);
	virtual void __fastcall DoGetImageIndex(TCustomViewItem* item);
	TListItem* __fastcall GetDropTarget(void);
	virtual void __fastcall HookEvents(void);
	virtual void __fastcall ImageListChanged(void);
	virtual void __fastcall Init(TMetaClass* AListItemClass);
	virtual void __fastcall InitWidget(void);
	virtual bool __fastcall IsOwnerDrawn(void);
	virtual void __fastcall ItemChange(Qt::QListViewItemH* item, TItemChange _type);
	virtual void __fastcall ItemChanging(Qt::QListViewItemH* item, TItemChange _type, bool &Allow);
	virtual void __fastcall ItemChecked(Qt::QListViewItemH* item, bool Checked);
	virtual void __fastcall ItemDestroyed(Qt::QListViewItemH* AItem);
	virtual void __fastcall ItemSelected(Qt::QListViewItemH* item, bool wasSelected);
	virtual void __fastcall RestoreWidgetState(void);
	virtual void __fastcall SaveWidgetState(void);
	__property bool CheckBoxes = {read=FCheckBoxes, write=SetCheckBoxes, default=0};
	__property Height  = {default=150};
	__property TListItems* Items = {read=FItems, write=SetItems};
	__property ReadOnly  = {default=0};
	__property SortDirection  = {default=0};
	__property TViewStyle ViewStyle = {read=FViewStyle, write=SetViewStyle, default=0};
	__property TLVChangeEvent OnChange = {read=FOnChange, write=FOnChange};
	__property TLVChangingEvent OnChanging = {read=FOnChanging, write=FOnChanging};
	__property TLVNotifyEvent OnDeletion = {read=FOnDeletion, write=FOnDeletion};
	__property TListViewDrawItemEvent OnDrawItem = {read=FOnDrawItem, write=FOnDrawItem};
	__property TLVEditedEvent OnEdited = {read=FOnEdited, write=FOnEdited};
	__property TLVEditingEvent OnEditing = {read=FOnEditing, write=FOnEditing};
	__property TLVNotifyEvent OnGetImageIndex = {read=FOnGetImageIndex, write=FOnGetImageIndex};
	__property TLVNotifyEvent OnInsert = {read=FOnInsert, write=FOnInsert};
	__property TLVItemClickEvent OnItemClick = {read=FOnItemClick, write=FOnItemClick};
	__property TLVNotifyEvent OnItemDoubleClick = {read=FOnItemDoubleClick, write=SetOnItemDoubleClick};
	__property TLVNotifyEvent OnItemEnter = {read=FOnItemEnter, write=SetOnItemEnter};
	__property Classes::TNotifyEvent OnItemExitViewportEnter = {read=FOnItemExitViewportEnter, write=SetOnItemExitViewportEnter};
	__property TLVButtonDownEvent OnItemMouseDown = {read=FOnMouseDown, write=SetOnMouseDown};
	__property TLVSelectItemEvent OnSelectItem = {read=FOnSelectItem, write=FOnSelectItem};
	__property TLVViewportButtonDownEvent OnViewPortMouseDown = {read=FOnViewportMouseDown, write=SetOnViewportButtonDown};
	
public:
	__fastcall virtual TCustomListView(Classes::TComponent* AOwner)/* overload */;
	__fastcall TCustomListView(Classes::TComponent* AOwner, TMetaClass* AListItemClass)/* overload */;
	__fastcall virtual ~TCustomListView(void);
	bool __fastcall AlphaSort(void);
	TListItem* __fastcall FindData(int StartIndex, void * Value, bool Inclusive, bool Wrap);
	TListItem* __fastcall FindCaption(int StartIndex, const WideString Value, bool Partial, bool Inclusive, bool Wrap);
	TListItem* __fastcall GetItemAt(int X, int Y);
	TListItem* __fastcall GetNearestItem(const Types::TPoint &Point, TSearchDirection Direction);
	TListItem* __fastcall GetNextItem(TListItem* StartItem, TSearchDirection Direction, TItemStates States);
	void __fastcall Scroll(int DX, int DY);
	void __fastcall UpdateItems(int FirstIndex, int LastIndex);
	__property TListItem* DropTarget = {read=GetDropTarget};
	__property TListItem* ItemFocused = {read=GetItemFocused, write=SetItemFocused};
	__property TListItem* Selected = {read=GetSelected, write=SetSelected};
	__property TListItem* TopItem = {read=GetTopItem, write=SetTopItem};
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TCustomListView(Qt::QWidgetH* ParentWidget) : TCustomViewControl(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS TListView;
class PASCALIMPLEMENTATION TListView : public TCustomListView 
{
	typedef TCustomListView inherited;
	
public:
	__property SortColumn  = {default=0};
	
__published:
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property BorderStyle  = {default=6};
	__property CheckBoxes  = {default=0};
	__property Color  = {default=-10};
	__property ColumnClick  = {default=1};
	__property ColumnMove  = {default=1};
	__property ColumnResize  = {default=1};
	__property Columns ;
	__property Constraints ;
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property Height  = {default=150};
	__property Hint ;
	__property Images ;
	__property Items ;
	__property MultiSelect  = {default=0};
	__property OwnerDraw  = {default=0};
	__property RowSelect  = {default=0};
	__property ParentColor  = {default=0};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ReadOnly  = {default=0};
	__property SelCount  = {default=0};
	__property ShowColumnSortIndicators  = {default=0};
	__property ShowHint ;
	__property SortDirection  = {default=0};
	__property Sorted  = {default=0};
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property ViewStyle  = {default=0};
	__property Visible  = {default=1};
	__property Width  = {default=121};
	__property OnChange ;
	__property OnChanging ;
	__property OnClick ;
	__property OnColumnClick ;
	__property OnColumnDragged ;
	__property OnColumnResize ;
	__property OnContextPopup ;
	__property OnCustomDrawItem ;
	__property OnCustomDrawSubItem ;
	__property OnDblClick ;
	__property OnDeletion ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnDrawItem ;
	__property OnEdited ;
	__property OnEditing ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnGetImageIndex ;
	__property OnInsert ;
	__property OnItemClick ;
	__property OnItemDoubleClick ;
	__property OnItemEnter ;
	__property OnItemExitViewportEnter ;
	__property OnItemMouseDown ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyString ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnResize ;
	__property OnSelectItem ;
	__property OnStartDrag ;
	__property OnViewPortMouseDown ;
public:
	#pragma option push -w-inl
	/* TCustomListView.Create */ inline __fastcall virtual TListView(Classes::TComponent* AOwner)/* overload */ : TCustomListView(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomListView.Destroy */ inline __fastcall virtual ~TListView(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TListView(Qt::QWidgetH* ParentWidget) : TCustomListView(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS ETreeViewError;
class PASCALIMPLEMENTATION ETreeViewError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ETreeViewError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ETreeViewError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ETreeViewError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ETreeViewError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ETreeViewError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ETreeViewError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ETreeViewError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ETreeViewError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ETreeViewError(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TNodeAttachMode { naAdd, naAddFirst, naAddChild, naAddChildFirst, naInsert };
#pragma option pop

#pragma option push -b-
enum TAddMode { taAddFirst, taAdd, taInsert };
#pragma option pop

typedef TMetaClass*TTreeNodeClass;

class DELPHICLASS TTreeNodes;
class DELPHICLASS TTreeNode;
class DELPHICLASS TCustomTreeView;
class PASCALIMPLEMENTATION TTreeNodes : public TCustomViewItems 
{
	typedef TCustomViewItems inherited;
	
public:
	TTreeNode* operator[](int Index) { return Item[Index]; }
	
private:
	TMetaClass*FNodeClass;
	HIDESBASE TTreeNode* __fastcall GetItem(int Index);
	TCustomTreeView* __fastcall GetNodesOwner(void);
	void __fastcall ReadData(Classes::TStream* Stream);
	void __fastcall WriteData(Classes::TStream* Stream);
	
protected:
	TTreeNode* __fastcall CreateNode(TTreeNode* ParentNode = (TTreeNode*)(0x0), TTreeNode* AfterNode = (TTreeNode*)(0x0));
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	TTreeNode* __fastcall InternalAddObject(TTreeNode* Node, const WideString S, void * Ptr, TAddMode AddMode);
	TTreeNode* __fastcall FindItem(Qt::QListViewItemH* ItemH);
	TTreeNode* __fastcall FindPrevSibling(TTreeNode* ANode);
	
public:
	TTreeNode* __fastcall Add(TTreeNode* Node, const WideString S);
	TTreeNode* __fastcall AddChild(TTreeNode* Node, const WideString S);
	TTreeNode* __fastcall AddChildFirst(TTreeNode* Node, const WideString S);
	TTreeNode* __fastcall AddChildObject(TTreeNode* Node, const WideString S, void * Ptr);
	TTreeNode* __fastcall AddChildObjectFirst(TTreeNode* Node, const WideString S, void * Ptr);
	TTreeNode* __fastcall AddFirst(TTreeNode* Node, const WideString S);
	TTreeNode* __fastcall AddObject(TTreeNode* Node, const WideString S, void * Ptr);
	TTreeNode* __fastcall AddObjectFirst(TTreeNode* Node, const WideString S, void * Ptr);
	virtual void __fastcall Assign(Classes::TPersistent* Dest);
	HIDESBASE void __fastcall Clear(void);
	HIDESBASE void __fastcall Delete(TTreeNode* Node);
	TTreeNode* __fastcall GetFirstNode(void);
	TTreeNode* __fastcall GetNode(Qt::QListViewItemH* ItemH);
	TTreeNode* __fastcall Insert(TTreeNode* Node, const WideString S);
	TTreeNode* __fastcall InsertObject(TTreeNode* Node, const WideString S, void * Ptr);
	void __fastcall SetNodeClass(TMetaClass* NewNodeClass);
	__property TTreeNode* Item[int Index] = {read=GetItem/*, default*/};
	__property TCustomTreeView* Owner = {read=GetNodesOwner};
public:
	#pragma option push -w-inl
	/* TCustomViewItems.Create */ inline __fastcall virtual TTreeNodes(TCustomViewControl* AOwner) : TCustomViewItems(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomViewItems.Destroy */ inline __fastcall virtual ~TTreeNodes(void) { }
	#pragma option pop
	
};


struct TNodeInfo;
typedef TNodeInfo *PNodeInfo;

#pragma pack(push, 1)
struct TNodeInfo
{
	int ImageIndex;
	int SelectedIndex;
	int StateIndex;
	int SubItemCount;
	void *Data;
	int Count;
	System::SmallString<255>  Text;
} ;
#pragma pack(pop)

class PASCALIMPLEMENTATION TTreeNode : public TCustomViewItem 
{
	typedef TCustomViewItem inherited;
	
public:
	TTreeNode* operator[](int Index) { return Item[Index]; }
	
private:
	bool FDeleting;
	int FSelectedIndex;
	bool __fastcall DoCanExpand(bool Expand);
	void __fastcall ExpandItem(bool Expand, bool Recurse);
	int __fastcall GetCount(void);
	TTreeNode* __fastcall GetItem(int Index);
	int __fastcall GetLevel(void);
	TTreeNode* __fastcall GetParent(void);
	HIDESBASE int __fastcall GetIndex(void);
	TCustomTreeView* __fastcall GetTreeView(void);
	bool __fastcall IsNodeVisible(void);
	bool __fastcall IsEqual(TTreeNode* Node);
	void __fastcall SetItem(int Index, const TTreeNode* Value);
	TTreeNodes* __fastcall GetNodeOwner(void);
	void __fastcall SetNodeParent(const TTreeNode* Value);
	void __fastcall SetSelectedIndex(const int Value);
	bool __fastcall GetDropTarget(void);
	HIDESBASE bool __fastcall GetSelected(void);
	HIDESBASE void __fastcall SetSelected(const bool Value);
	bool __fastcall GetExpandable(void);
	HIDESBASE void __fastcall SetExpandable(const bool Value);
	WideString __fastcall GetCaption();
	HIDESBASE void __fastcall SetCaption(const WideString Value);
	
protected:
	bool __fastcall CompareCount(int CompareMe);
	int __fastcall GetAbsoluteIndex(void);
	virtual void __fastcall ImageIndexChange(int ColIndex, int NewIndex);
	void __fastcall ReadData(Classes::TStream* Stream, PNodeInfo Info);
	void __fastcall WriteData(Classes::TStream* Stream, PNodeInfo Info);
	
public:
	__fastcall virtual TTreeNode(TCustomViewItems* AOwner, TCustomViewItem* AParent, TCustomViewItem* After);
	__fastcall virtual ~TTreeNode(void);
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	HIDESBASE void __fastcall Collapse(bool Recurse);
	bool __fastcall AlphaSort(bool Ascending);
	HIDESBASE void __fastcall Delete(void);
	void __fastcall DeleteChildren(void);
	bool __fastcall EditText(void);
	HIDESBASE void __fastcall Expand(bool Recurse);
	TTreeNode* __fastcall getFirstChild(void);
	TTreeNode* __fastcall GetLastChild(void);
	TTreeNode* __fastcall GetNext(void);
	TTreeNode* __fastcall GetNextChild(TTreeNode* Value);
	TTreeNode* __fastcall getNextSibling(void);
	TTreeNode* __fastcall GetNextVisible(void);
	TTreeNode* __fastcall GetPrev(void);
	TTreeNode* __fastcall GetPrevChild(TTreeNode* Value);
	TTreeNode* __fastcall getPrevSibling(void);
	TTreeNode* __fastcall GetPrevVisible(void);
	bool __fastcall HasAsParent(TTreeNode* Value);
	int __fastcall IndexOf(TTreeNode* Value);
	virtual void __fastcall MoveTo(TTreeNode* Destination, TNodeAttachMode Mode);
	__property int AbsoluteIndex = {read=GetAbsoluteIndex, nodefault};
	__property Checked ;
	__property int Count = {read=GetCount, nodefault};
	__property Data ;
	__property bool Deleting = {read=FDeleting, nodefault};
	__property bool DropTarget = {read=GetDropTarget, nodefault};
	__property bool Focused = {read=GetSelected, write=SetSelected, nodefault};
	__property Expanded ;
	__property Handle ;
	__property bool HasChildren = {read=GetExpandable, write=SetExpandable, nodefault};
	__property Height ;
	__property ImageIndex ;
	__property int Index = {read=GetIndex, nodefault};
	__property bool IsVisible = {read=IsNodeVisible, nodefault};
	__property ItemType ;
	__property TTreeNode* Item[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property int Level = {read=GetLevel, nodefault};
	__property TTreeNodes* Owner = {read=GetNodeOwner};
	__property TTreeNode* Parent = {read=GetParent, write=SetNodeParent};
	__property Selected ;
	__property int SelectedIndex = {read=FSelectedIndex, write=SetSelectedIndex, nodefault};
	__property WideString Text = {read=GetCaption, write=SetCaption};
	__property TotalHeight ;
	__property TCustomTreeView* TreeView = {read=GetTreeView};
	__property Selectable ;
	__property SubItemImages ;
	__property SubItems ;
};


#pragma option push -b-
enum TSortType { stNone, stText };
#pragma option pop

typedef void __fastcall (__closure *TTVItemNotifyEvent)(System::TObject* Sender, TTreeNode* Node);

typedef void __fastcall (__closure *TTVDeletedEvent)(System::TObject* Sender, TTreeNode* Node);

typedef void __fastcall (__closure *TTVItemEnterEvent)(System::TObject* Sender, TTreeNode* Node);

typedef void __fastcall (__closure *TTVItemExitViewportEnterEvent)(System::TObject* Sender);

typedef void __fastcall (__closure *TTVChangedEvent)(System::TObject* Sender, TTreeNode* Node);

typedef void __fastcall (__closure *TTVChangingEvent)(System::TObject* Sender, TTreeNode* Node, bool &AllowChange);

typedef void __fastcall (__closure *TTVExpandingEvent)(System::TObject* Sender, TTreeNode* Node, bool &AllowExpansion);

typedef void __fastcall (__closure *TTVCollapsingEvent)(System::TObject* Sender, TTreeNode* Node, bool &AllowCollapse);

typedef void __fastcall (__closure *TTVExpandedEvent)(System::TObject* Sender, TTreeNode* Node);

typedef void __fastcall (__closure *TTVCollapsedEvent)(System::TObject* Sender, TTreeNode* Node);

typedef void __fastcall (__closure *TTVSelectItemEvent)(System::TObject* Sender, TTreeNode* Node, bool Selected);

typedef void __fastcall (__closure *TTVEditingEvent)(System::TObject* Sender, TTreeNode* Node, bool &AllowEdit);

typedef void __fastcall (__closure *TTVEditedEvent)(System::TObject* Sender, TTreeNode* Node, WideString &S);

typedef void __fastcall (__closure *TTVItemClickEvent)(System::TObject* Sender, Qcontrols::TMouseButton Button, TTreeNode* Node, const Types::TPoint &Pt);

typedef void __fastcall (__closure *TTVItemDoubleClickEvent)(System::TObject* Sender, TTreeNode* Node);

typedef void __fastcall (__closure *TTVButtonDownEvent)(System::TObject* Sender, Qcontrols::TMouseButton Button, TTreeNode* Node, const Types::TPoint &Pt);

typedef void __fastcall (__closure *TTVViewportButtonDownEvent)(System::TObject* Sender, Qcontrols::TMouseButton Button, const Types::TPoint &Pt);

class PASCALIMPLEMENTATION TCustomTreeView : public TCustomViewControl 
{
	typedef TCustomViewControl inherited;
	
private:
	TTreeNodes* FTreeNodes;
	TTreeNode* FSelectedNode;
	TTreeNode* FLastNode;
	TSortType FSortType;
	bool FShowButtons;
	Classes::TMemoryStream* FMemStream;
	TTVItemNotifyEvent FOnChange;
	TTVChangingEvent FOnChanging;
	TTVCollapsingEvent FOnCollapsing;
	TTVItemNotifyEvent FOnDeletion;
	TTVItemNotifyEvent FOnCollapsed;
	TTVItemNotifyEvent FOnExpanded;
	TTVExpandingEvent FOnExpanding;
	bool FAutoExpand;
	TTVButtonDownEvent FOnMouseDown;
	TTVItemNotifyEvent FOnInsert;
	TTVItemClickEvent FOnItemClick;
	TTVItemDoubleClickEvent FOnItemDoubleClick;
	TTVItemNotifyEvent FOnItemEnter;
	Classes::TNotifyEvent FOnItemExitViewportEnter;
	TTVViewportButtonDownEvent FOnViewportMouseDown;
	TTVEditedEvent FOnEdited;
	TTVEditingEvent FOnEditing;
	TTVItemNotifyEvent FOnGetImageIndex;
	TTVItemNotifyEvent FOnGetSelectedIndex;
	bool FFullExpansion;
	int FItemMargin;
	virtual void __fastcall RepopulateItems(void);
	void __fastcall DoAutoExpand(TTreeNode* ExpandedNode);
	void __fastcall SetSortType(const TSortType Value);
	void __fastcall SetAutoExpand(const bool Value);
	TTreeNode* __fastcall GetSelected(void);
	void __fastcall SetSelected(const TTreeNode* Value);
	void __fastcall SetItemMargin(const int Value);
	void __fastcall HookMouseDowns(void);
	void __cdecl DoItemClick(int p1, Qt::QListViewItemH* p2, Types::PPoint p3, int p4);
	void __cdecl DoItemDoubleClick(Qt::QListViewItemH* p1);
	void __cdecl DoOnItemEnter(Qt::QListViewItemH* item);
	void __cdecl DoOnItemExitViewportEnter(void);
	void __cdecl DoOnMouseDown(int p1, Qt::QListViewItemH* p2, Types::PPoint p3, int p4);
	void __fastcall SetOnItemDoubleClick(const TTVItemDoubleClickEvent Value);
	void __fastcall SetOnItemEnter(const TTVItemNotifyEvent Value);
	void __fastcall SetOnItemExitViewportEnter(const Classes::TNotifyEvent Value);
	void __fastcall SetOnMouseDown(const TTVButtonDownEvent Value);
	void __fastcall SetOnViewportButtonDown(const TTVViewportButtonDownEvent Value);
	void __fastcall SetShowButtons(const bool Value);
	void __fastcall SetItems(const TTreeNodes* Value);
	void __fastcall SetTopItem(const TTreeNode* AItem);
	TTreeNode* __fastcall GetTopItem(void);
	virtual void __fastcall ItemChanging(Qt::QListViewItemH* item, TItemChange _type, bool &Allow);
	virtual void __fastcall ItemDestroyed(Qt::QListViewItemH* AItem);
	virtual void __fastcall ItemExpanding(Qt::QListViewItemH* item, bool Expand, bool &Allow);
	virtual void __fastcall ItemExpanded(Qt::QListViewItemH* item, bool Expand);
	virtual void __fastcall ItemChecked(Qt::QListViewItemH* item, bool Checked);
	virtual void __fastcall ItemSelected(Qt::QListViewItemH* item, bool wasSelected);
	
protected:
	DYNAMIC bool __fastcall CanCollapse(TTreeNode* Node);
	DYNAMIC bool __fastcall CanExpand(TTreeNode* Node);
	DYNAMIC void __fastcall Change(TTreeNode* Node);
	DYNAMIC void __fastcall Collapse(TTreeNode* Node);
	DYNAMIC void __fastcall Delete(TTreeNode* Node);
	DYNAMIC void __fastcall DoEdited(TCustomViewItem* AItem, WideString &S);
	DYNAMIC void __fastcall DoEditing(TCustomViewItem* AItem, bool &AllowEdit);
	virtual void __fastcall DoGetImageIndex(TCustomViewItem* item);
	virtual bool __fastcall EventFilter(Qt::QObjectH* Sender, Qt::QEventH* Event);
	TTreeNode* __fastcall GetDropTarget(void);
	DYNAMIC void __fastcall Expand(TTreeNode* Node);
	virtual void __fastcall HookEvents(void);
	virtual void __fastcall ImageListChanged(void);
	virtual void __fastcall Init(TMetaClass* ANodeClass);
	virtual void __fastcall InitWidget(void);
	virtual bool __fastcall IsCustomDrawn(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall RestoreWidgetState(void);
	virtual void __fastcall SaveWidgetState(void);
	__property bool AutoExpand = {read=FAutoExpand, write=SetAutoExpand, default=0};
	__property int ItemMargin = {read=FItemMargin, write=SetItemMargin, default=1};
	__property TTreeNodes* Items = {read=FTreeNodes, write=SetItems};
	__property bool ShowButtons = {read=FShowButtons, write=SetShowButtons, default=1};
	__property TSortType SortType = {read=FSortType, write=SetSortType, default=0};
	__property TTVItemNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property TTVChangingEvent OnChanging = {read=FOnChanging, write=FOnChanging};
	__property TTVItemNotifyEvent OnCollapsed = {read=FOnCollapsed, write=FOnCollapsed};
	__property TTVCollapsingEvent OnCollapsing = {read=FOnCollapsing, write=FOnCollapsing};
	__property TTVItemNotifyEvent OnDeletion = {read=FOnDeletion, write=FOnDeletion};
	__property TTVEditedEvent OnEdited = {read=FOnEdited, write=FOnEdited};
	__property TTVEditingEvent OnEditing = {read=FOnEditing, write=FOnEditing};
	__property TTVExpandingEvent OnExpanding = {read=FOnExpanding, write=FOnExpanding};
	__property TTVItemNotifyEvent OnExpanded = {read=FOnExpanded, write=FOnExpanded};
	__property TTVItemNotifyEvent OnGetImageIndex = {read=FOnGetImageIndex, write=FOnGetImageIndex};
	__property TTVItemNotifyEvent OnGetSelectedIndex = {read=FOnGetSelectedIndex, write=FOnGetSelectedIndex};
	__property TTVItemNotifyEvent OnInsert = {read=FOnInsert, write=FOnInsert};
	__property TTVItemClickEvent OnItemClick = {read=FOnItemClick, write=FOnItemClick};
	__property TTVItemDoubleClickEvent OnItemDoubleClick = {read=FOnItemDoubleClick, write=SetOnItemDoubleClick};
	__property TTVItemNotifyEvent OnItemEnter = {read=FOnItemEnter, write=SetOnItemEnter};
	__property Classes::TNotifyEvent OnItemExitViewportEnter = {read=FOnItemExitViewportEnter, write=SetOnItemExitViewportEnter};
	__property TTVButtonDownEvent OnItemMouseDown = {read=FOnMouseDown, write=SetOnMouseDown};
	__property TTVViewportButtonDownEvent OnViewPortMouseDown = {read=FOnViewportMouseDown, write=SetOnViewportButtonDown};
	
public:
	__fastcall virtual TCustomTreeView(Classes::TComponent* AOwner)/* overload */;
	__fastcall TCustomTreeView(Classes::TComponent* AOwner, TMetaClass* ANodeClass)/* overload */;
	__fastcall virtual ~TCustomTreeView(void);
	bool __fastcall AlphaSort(void);
	void __fastcall FullCollapse(void);
	void __fastcall FullExpand(void);
	TTreeNode* __fastcall GetNodeAt(int X, int Y);
	void __fastcall LoadFromFile(const AnsiString FileName);
	void __fastcall LoadFromStream(Classes::TStream* Stream);
	void __fastcall SaveToFile(const AnsiString FileName);
	void __fastcall SaveToStream(Classes::TStream* Stream);
	void __fastcall SelectAll(bool Select);
	__property TTreeNode* DropTarget = {read=GetDropTarget};
	__property TTreeNode* Selected = {read=GetSelected, write=SetSelected};
	__property TTreeNode* TopItem = {read=GetTopItem, write=SetTopItem};
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TCustomTreeView(Qt::QWidgetH* ParentWidget) : TCustomViewControl(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS TTreeView;
class PASCALIMPLEMENTATION TTreeView : public TCustomTreeView 
{
	typedef TCustomTreeView inherited;
	
private:
	int __fastcall GetSelCount(void);
	
public:
	__property SortColumn  = {default=0};
	
__published:
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property AutoExpand  = {default=0};
	__property BorderStyle  = {default=6};
	__property Color  = {default=-10};
	__property ColumnClick  = {default=1};
	__property ColumnMove  = {default=1};
	__property ColumnResize  = {default=1};
	__property Columns ;
	__property Constraints ;
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property Height  = {default=97};
	__property Hint ;
	__property Images ;
	__property ItemMargin  = {default=1};
	__property Items ;
	__property Indent  = {default=20};
	__property MultiSelect  = {default=0};
	__property ParentColor  = {default=0};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ReadOnly  = {default=0};
	__property RowSelect  = {default=0};
	__property int SelectionCount = {read=GetSelCount, default=0};
	__property ShowColumnHeaders  = {default=0};
	__property ShowColumnSortIndicators  = {default=0};
	__property ShowButtons  = {default=1};
	__property ShowHint ;
	__property Sorted  = {default=0};
	__property SortType  = {default=0};
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Visible  = {default=1};
	__property Width  = {default=121};
	__property OnChange ;
	__property OnChanging ;
	__property OnClick ;
	__property OnCollapsed ;
	__property OnCollapsing ;
	__property OnColumnClick ;
	__property OnColumnDragged ;
	__property OnColumnResize ;
	__property OnContextPopup ;
	__property OnCustomDrawBranch ;
	__property OnCustomDrawItem ;
	__property OnCustomDrawSubItem ;
	__property OnDblClick ;
	__property OnDeletion ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEdited ;
	__property OnEditing ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnExpanding ;
	__property OnExpanded ;
	__property OnGetImageIndex ;
	__property OnGetSelectedIndex ;
	__property OnInsert ;
	__property OnItemClick ;
	__property OnItemDoubleClick ;
	__property OnItemEnter ;
	__property OnItemExitViewportEnter ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyString ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDrag ;
	__property OnItemMouseDown ;
	__property OnViewPortMouseDown ;
public:
	#pragma option push -w-inl
	/* TCustomTreeView.Create */ inline __fastcall virtual TTreeView(Classes::TComponent* AOwner)/* overload */ : TCustomTreeView(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomTreeView.Destroy */ inline __fastcall virtual ~TTreeView(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TTreeView(Qt::QWidgetH* ParentWidget) : TCustomTreeView(ParentWidget) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TArrangement { arLeftToRight, arTopToBottom };
#pragma option pop

#pragma option push -b-
enum TResizeMode { rmFixed, rmAdjust };
#pragma option pop

#pragma option push -b-
enum TItemTextPos { itpBottom, itpRight };
#pragma option pop

class DELPHICLASS TIconViewItem;
class DELPHICLASS TIconViewItems;
class DELPHICLASS TCustomIconView;
typedef void __fastcall (__closure *TIVItemClickEvent)(System::TObject* Sender, TIconViewItem* Item);

typedef void __fastcall (__closure *TIVItemEvent)(System::TObject* Sender, TIconViewItem* Item);

typedef void __fastcall (__closure *TIVEditedEvent)(System::TObject* Sender, TIconViewItem* Item, const WideString NewName);

typedef void __fastcall (__closure *TIVChangeEvent)(System::TObject* Sender, TIconViewItem* Item, TItemChange Change);

typedef void __fastcall (__closure *TIVChangingEvent)(System::TObject* Sender, TIconViewItem* Item, TItemChange Change, bool &AllowChange);

typedef void __fastcall (__closure *TIVSelectItemEvent)(System::TObject* Sender, TIconViewItem* Item, bool Selected);

class DELPHICLASS TIconOptions;
#pragma option push -b-
enum TIconArrangement { iaTop, iaLeft };
#pragma option pop

class PASCALIMPLEMENTATION TIconOptions : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	bool FAutoArrange;
	TIconArrangement FArrangement;
	bool FWrapText;
	TCustomIconView* FIconView;
	void __fastcall SetArrangement(TIconArrangement Value);
	void __fastcall SetAutoArrange(bool Value);
	void __fastcall SetWrapText(bool Value);
	
public:
	__fastcall TIconOptions(TCustomIconView* AOwner);
	
__published:
	__property TIconArrangement Arrangement = {read=FArrangement, write=SetArrangement, default=1};
	__property bool AutoArrange = {read=FAutoArrange, write=SetAutoArrange, default=1};
	__property bool WrapText = {read=FWrapText, write=SetWrapText, default=1};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TIconOptions(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TCustomIconView : public Qcontrols::TFrameControl 
{
	typedef Qcontrols::TFrameControl inherited;
	
private:
	bool FItemsMovable;
	bool FMultiSelect;
	TResizeMode FResizeMode;
	bool FShowToolTips;
	bool FSort;
	int FSpacing;
	int FSelCount;
	TItemTextPos FTextPosition;
	TSortDirection FSortDirection;
	Qt::QClxIconViewHooksH* FItemHooks;
	TIconViewItems* FIconViewItems;
	TIVItemClickEvent FOnItemClicked;
	TIVItemEvent FOnItemDoubleClick;
	TIVItemEvent FOnItemEnter;
	Classes::TNotifyEvent FOnItemExitViewportEnter;
	TIVEditedEvent FOnEdited;
	TIVChangeEvent FOnItemChange;
	TIVChangingEvent FOnItemChanging;
	Qimglist::TCustomImageList* FImages;
	Qimglist::TChangeLink* FImageChanges;
	Qt::QWidgetH* FViewportHandle;
	Qt::QWidget_hookH* FViewportHooks;
	TIVSelectItemEvent FOnSelectItem;
	TIconOptions* FIconOptions;
	TIconViewItem* FSelected;
	void __fastcall OnImageChanges(System::TObject* Sender);
	HIDESBASE Qt::QIconViewH* __fastcall GetHandle(void);
	void __fastcall SetMultiSelect(const bool Value);
	void __fastcall SetSpacing(const int Value);
	void __fastcall SetTextPos(const TItemTextPos Value);
	void __fastcall SetResizeMode(const TResizeMode Value);
	void __fastcall SetShowToolTips(const bool Value);
	void __fastcall SetIconViewItems(const TIconViewItems* Value);
	void __fastcall SetSort(const bool Value);
	void __fastcall SetSortDirection(const TSortDirection Value);
	void __fastcall SetItemsMovable(const bool Value);
	void __cdecl DoItemClicked(Qt::QIconViewItemH* item);
	void __cdecl DoItemDoubleClicked(Qt::QIconViewItemH* item);
	void __cdecl DoItemEnter(Qt::QIconViewItemH* item);
	void __cdecl DoViewportEnter(void);
	void __cdecl DoEdited(Qt::QIconViewItemH* item, System::PWideString p2);
	void __cdecl ItemDestroyedHook(Qt::QIconViewItemH* item);
	void __cdecl ChangingHook(Qt::QIconViewItemH* item, TItemChange _type, bool &Allow);
	void __cdecl ChangeHook(Qt::QIconViewItemH* item, TItemChange _type);
	void __cdecl SelectedHook(Qt::QIconViewItemH* item, bool Value);
	void __cdecl PaintCellHook(Qt::QPainterH* p, Qt::QIconViewItemH* item, Qt::QColorGroupH* cg, int &stage);
	void __cdecl PaintFocusHook(Qt::QPainterH* p, Qt::QIconViewItemH* item, Qt::QColorGroupH* cg, int &stage);
	void __fastcall SetOnItemClicked(const TIVItemClickEvent Value);
	void __fastcall SetOnItemDoubleClick(const TIVItemEvent Value);
	void __fastcall SetOnItemEnter(const TIVItemEvent Value);
	void __fastcall SetOnItemExitViewportEnter(const Classes::TNotifyEvent Value);
	void __fastcall SetOnEdited(const TIVEditedEvent Value);
	void __fastcall SetImages(const Qimglist::TCustomImageList* Value);
	void __fastcall SetSelected(const TIconViewItem* Value);
	void __fastcall SetIconOptions(const TIconOptions* Value);
	
protected:
	DYNAMIC void __fastcall BeginAutoDrag(void);
	DYNAMIC void __fastcall ColorChanged(void);
	virtual void __fastcall CreateWidget(void);
	DYNAMIC void __fastcall DoChange(TIconViewItem* Item, TItemChange Change);
	DYNAMIC void __fastcall DoChanging(TIconViewItem* Item, TItemChange Change, bool &AllowChange);
	virtual void __fastcall HookEvents(void);
	DYNAMIC void __fastcall ImageListChanged(void);
	virtual void __fastcall InitWidget(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	Qt::QWidgetH* __fastcall ViewportHandle(void);
	DYNAMIC void __fastcall WidgetDestroyed(void);
	__property BorderStyle  = {default=6};
	__property Height  = {default=97};
	__property TIconOptions* IconOptions = {read=FIconOptions, write=SetIconOptions};
	__property Qimglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property TIconViewItems* Items = {read=FIconViewItems, write=SetIconViewItems};
	__property bool ItemsMovable = {read=FItemsMovable, write=SetItemsMovable, default=1};
	__property bool MultiSelect = {read=FMultiSelect, write=SetMultiSelect, default=0};
	__property ParentColor  = {default=0};
	__property TResizeMode ResizeMode = {read=FResizeMode, write=SetResizeMode, default=1};
	__property int SelCount = {read=FSelCount, nodefault};
	__property TIconViewItem* Selected = {read=FSelected, write=SetSelected};
	__property bool ShowToolTips = {read=FShowToolTips, write=SetShowToolTips, default=1};
	__property bool Sort = {read=FSort, write=SetSort, default=0};
	__property TSortDirection SortDirection = {read=FSortDirection, write=SetSortDirection, default=0};
	__property int Spacing = {read=FSpacing, write=SetSpacing, default=5};
	__property TabStop  = {default=1};
	__property TItemTextPos TextPosition = {read=FTextPosition, write=SetTextPos, default=0};
	__property Width  = {default=121};
	__property TIVChangeEvent OnChange = {read=FOnItemChange, write=FOnItemChange};
	__property TIVChangingEvent OnChanging = {read=FOnItemChanging, write=FOnItemChanging};
	__property TIVItemEvent OnItemDoubleClick = {read=FOnItemDoubleClick, write=SetOnItemDoubleClick};
	__property Classes::TNotifyEvent OnItemExitViewportEnter = {read=FOnItemExitViewportEnter, write=SetOnItemExitViewportEnter};
	__property TIVItemEvent OnItemEnter = {read=FOnItemEnter, write=SetOnItemEnter};
	__property TIVEditedEvent OnEdited = {read=FOnEdited, write=SetOnEdited};
	__property TIVItemClickEvent OnItemClicked = {read=FOnItemClicked, write=SetOnItemClicked};
	__property TIVSelectItemEvent OnSelectItem = {read=FOnSelectItem, write=FOnSelectItem};
	
public:
	__fastcall virtual TCustomIconView(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomIconView(void);
	__property Qt::QIconViewH* Handle = {read=GetHandle};
	void __fastcall Clear(void);
	void __fastcall SelectAll(bool Select);
	TIconViewItem* __fastcall FindItemByText(const WideString Str);
	TIconViewItem* __fastcall FindItemByPoint(const Types::TPoint &Pt);
	TIconViewItem* __fastcall GetNextItem(TIconViewItem* StartItem, TSearchDirection Direction, TItemStates States);
	void __fastcall RepaintItem(TIconViewItem* AItem);
	void __fastcall EnsureItemVisible(TIconViewItem* AItem);
	TIconViewItem* __fastcall FindVisibleItem(bool First, const Types::TRect &ARect);
	void __fastcall UpdateControl(void);
	void __fastcall UpdateItems(int FirstIndex, int LastIndex);
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TCustomIconView(Qt::QWidgetH* ParentWidget) : Qcontrols::TFrameControl(ParentWidget) { }
	#pragma option pop
	
};


typedef TMetaClass*TIconViewItemClass;

class PASCALIMPLEMENTATION TIconViewItems : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
public:
	TIconViewItem* operator[](int Index) { return Item[Index]; }
	
private:
	TCustomIconView* FOwner;
	TMetaClass*FIconViewItemClass;
	int FUpdateCount;
	Contnrs::TObjectList* FItems;
	
protected:
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	TIconViewItem* __fastcall FindItem(Qt::QIconViewItemH* ItemH);
	int __fastcall GetCount(void);
	TIconViewItem* __fastcall GetItem(int Index);
	Qt::QIconViewH* __fastcall IconViewHandle(void);
	void __fastcall ReadData(Classes::TStream* Stream);
	void __fastcall SetItem(int Index, TIconViewItem* AObject);
	virtual void __fastcall SetUpdateState(bool Updating);
	void __fastcall UpdateImages(void);
	void __fastcall WriteData(Classes::TStream* Stream);
	
public:
	__fastcall TIconViewItems(TCustomIconView* AOwner)/* overload */;
	__fastcall TIconViewItems(TCustomIconView* AOwner, TMetaClass* AItemClass)/* overload */;
	__fastcall virtual ~TIconViewItems(void);
	TIconViewItem* __fastcall Add(void);
	void __fastcall BeginUpdate(void);
	void __fastcall Clear(void);
	void __fastcall Delete(int Index);
	void __fastcall EndUpdate(void);
	int __fastcall IndexOf(TIconViewItem* Value);
	TIconViewItem* __fastcall Insert(int Index);
	void __fastcall SetItemClass(TMetaClass* AItemClass);
	__property int Count = {read=GetCount, nodefault};
	__property TIconViewItem* Item[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property TCustomIconView* Owner = {read=FOwner};
};


class PASCALIMPLEMENTATION TIconViewItem : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	TIconViewItems* FOwner;
	bool FDestroying;
	Qimglist::TImageIndex FImageIndex;
	TItemStates FStates;
	bool FAllowRename;
	WideString FCaption;
	bool FSelectable;
	void __fastcall SetAllowRename(const bool Value);
	Qt::QIconViewItemH* __fastcall GetHandle(void);
	void __fastcall SetCaption(const WideString Value);
	int __fastcall GetIndex(void);
	bool __fastcall GetSelected(void);
	void __fastcall SetSelected(const bool Value);
	void __fastcall SetSelectable(const bool Value);
	bool __fastcall IconViewValid(void);
	void __fastcall UpdateImage(void);
	void __fastcall SetImageIndex(const Qimglist::TImageIndex Value);
	void __fastcall SetStates(const TItemStates Value);
	TCustomIconView* __fastcall GetIconView(void);
	int __fastcall GetLeft(void);
	int __fastcall GetTop(void);
	int __fastcall GetWidth(void);
	int __fastcall GetHeight(void);
	
protected:
	Qt::QIconViewItemH* FHandle;
	void __fastcall CreateWidget(TIconViewItem* AfterItem);
	void __fastcall InitWidget(void);
	void __fastcall DestroyWidget(void);
	bool __fastcall HandleAllocated(void);
	bool __fastcall IsEqual(TIconViewItem* AItem);
	__property TCustomIconView* IconView = {read=GetIconView};
	
public:
	__fastcall TIconViewItem(TIconViewItems* AOwner, TIconViewItem* AfterItem);
	__fastcall virtual ~TIconViewItem(void);
	Types::TRect __fastcall BoundingRect();
	Types::TRect __fastcall IconRect();
	void __fastcall MakeVisible(void);
	void __fastcall Move(const Types::TPoint &Pt);
	void __fastcall MoveBy(const Types::TPoint &Pt);
	void __fastcall Repaint(void);
	Types::TRect __fastcall TextRect();
	__property bool AllowRename = {read=FAllowRename, write=SetAllowRename, default=1};
	__property WideString Caption = {read=FCaption, write=SetCaption};
	__property Qt::QIconViewItemH* Handle = {read=GetHandle};
	__property int Height = {read=GetHeight, nodefault};
	__property Qimglist::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, nodefault};
	__property int Index = {read=GetIndex, nodefault};
	__property int Left = {read=GetLeft, nodefault};
	__property bool Selectable = {read=FSelectable, write=SetSelectable, default=1};
	__property bool Selected = {read=GetSelected, write=SetSelected, nodefault};
	__property TItemStates States = {read=FStates, write=SetStates, nodefault};
	__property int Top = {read=GetTop, nodefault};
	__property int Width = {read=GetWidth, nodefault};
};


typedef void __fastcall (__closure *TIVItemMouseEvent)(System::TObject* Sender, Qcontrols::TMouseButton Button, TIconViewItem* Item, const Types::TPoint &Pt);

typedef void __fastcall (__closure *TIVMouseEvent)(System::TObject* Sender, Qcontrols::TMouseButton Button, const Types::TPoint &Pt);

typedef void __fastcall (__closure *TIVItemDoubleClickEvent)(System::TObject* Sender, TIconViewItem* Item);

typedef void __fastcall (__closure *TIVItemExitViewportEnterEvent)(System::TObject* Sender);

typedef void __fastcall (__closure *TIVItemEnterEvent)(System::TObject* Sender, TIconViewItem* Item);

typedef void __fastcall (__closure *TIVViewportClickedEvent)(System::TObject* Sender, Qcontrols::TMouseButton Button, const Types::TPoint &Pt);

class DELPHICLASS TIconView;
class PASCALIMPLEMENTATION TIconView : public TCustomIconView 
{
	typedef TCustomIconView inherited;
	
public:
	__property SelCount ;
	__property Selected ;
	
__published:
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property BorderStyle  = {default=6};
	__property Color  = {default=-10};
	__property Constraints ;
	__property DragMode  = {default=0};
	__property Height  = {default=97};
	__property Hint ;
	__property IconOptions ;
	__property Images ;
	__property Items ;
	__property ItemsMovable  = {default=1};
	__property MultiSelect  = {default=0};
	__property ParentColor  = {default=0};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ResizeMode  = {default=1};
	__property ShowHint ;
	__property ShowToolTips  = {default=1};
	__property Sort  = {default=0};
	__property SortDirection  = {default=0};
	__property Spacing  = {default=5};
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property TextPosition  = {default=0};
	__property Width  = {default=121};
	__property Visible  = {default=1};
	__property OnContextPopup ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnItemDoubleClick ;
	__property OnItemExitViewportEnter ;
	__property OnItemEnter ;
	__property OnEdited ;
	__property OnItemClicked ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyString ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnSelectItem ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TCustomIconView.Create */ inline __fastcall virtual TIconView(Classes::TComponent* AOwner) : TCustomIconView(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomIconView.Destroy */ inline __fastcall virtual ~TIconView(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TIconView(Qt::QWidgetH* ParentWidget) : TCustomIconView(ParentWidget) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TToolButtonStyle { tbsButton, tbsCheck, tbsDropDown, tbsSeparator, tbsDivider };
#pragma option pop

#pragma option push -b-
enum TToolButtonState { tbsChecked, tbsPressed, tbsEnabled, tbsHidden, tbsIndeterminate, tbsWrap, tbsEllipses, tbsMarked };
#pragma option pop

class DELPHICLASS TToolButtonActionLink;
class DELPHICLASS TToolButton;
class DELPHICLASS TToolBar;
#pragma option push -b-
enum TGroupChangeReason { gcDownState, gcAllowAllUp };
#pragma option pop

class PASCALIMPLEMENTATION TToolBar : public Qcontrols::TCustomControl 
{
	typedef Qcontrols::TCustomControl inherited;
	
private:
	int FButtonWidth;
	int FButtonHeight;
	bool FWrapable;
	bool FAutoSize;
	Qextctrls::TBorderWidth FBorderWidth;
	Classes::TList* FControls;
	Qgraphics::TEdgeBorders FEdgeBorders;
	Qgraphics::TEdgeStyle FEdgeOuter;
	Qgraphics::TEdgeStyle FEdgeInner;
	int FIndent;
	bool FFlat;
	bool FList;
	bool FShowCaptions;
	Qimglist::TCustomImageList* FHotImages;
	Qimglist::TCustomImageList* FImages;
	Qimglist::TCustomImageList* FDisabledImages;
	int FImageWidth;
	int FImageHeight;
	Qimglist::TChangeLink* FImageChangeLink;
	int FResizeCount;
	int FRightEdge;
	HIDESBASE void __fastcall AdjustSize(void);
	void __fastcall DoPaint(Qgraphics::TCanvas* ACanvas);
	int __fastcall EdgeSpacing(Qgraphics::TEdgeBorder Edge);
	HIDESBASE Qcontrols::TControl* __fastcall GetControl(int Index);
	void __fastcall GroupChange(TToolButton* Requestor, TGroupChangeReason Reason);
	bool __fastcall HasImages(void);
	void __fastcall ImageListChange(System::TObject* Sender);
	void __fastcall InternalSetButtonWidth(const int Value, bool RestrictSize);
	Qcontrols::TControl* __fastcall LastControl(void);
	void __fastcall ResizeButtons(TToolButton* Button);
	void __fastcall SetWrapable(const bool Value);
	void __fastcall SetButtonHeight(const int Value);
	void __fastcall SetButtonWidth(const int Value);
	void __fastcall SetAutoSize(const bool Value);
	void __fastcall SetBorderWidth(const Qextctrls::TBorderWidth Value);
	void __fastcall SetEdgeBorders(const Qgraphics::TEdgeBorders Value);
	void __fastcall SetEdgeInner(const Qgraphics::TEdgeStyle Value);
	void __fastcall SetEdgeOuter(const Qgraphics::TEdgeStyle Value);
	void __fastcall SetIndent(const int Value);
	void __fastcall SetFlat(const bool Value);
	void __fastcall SetShowCaptions(const bool Value);
	void __fastcall SetDisabledImages(const Qimglist::TCustomImageList* Value);
	void __fastcall SetHotImages(const Qimglist::TCustomImageList* Value);
	void __fastcall SetImages(const Qimglist::TCustomImageList* Value);
	void __fastcall SetList(const bool Value);
	
protected:
	DYNAMIC void __fastcall ControlsAligned(void);
	DYNAMIC void __fastcall ControlsListChanged(Qcontrols::TControl* Control, bool Inserting);
	virtual bool __fastcall CustomAlignInsertBefore(Qcontrols::TControl* C1, Qcontrols::TControl* C2);
	virtual void __fastcall CustomAlignPosition(Qcontrols::TControl* Control, int &NewLeft, int &NewTop, int &NewWidth, int &NewHeight, Types::TRect &AlignRect);
	void __fastcall DoResize(void);
	virtual bool __fastcall EventFilter(Qt::QObjectH* Sender, Qt::QEventH* Event);
	DYNAMIC void __fastcall FontChanged(void);
	virtual void __fastcall InitWidget(void);
	virtual void __fastcall AdjustClientRect(Types::TRect &Rect);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall Paint(void);
	
public:
	__fastcall virtual TToolBar(Classes::TComponent* AOwner);
	__fastcall virtual ~TToolBar(void);
	int __fastcall ButtonCount(void);
	HIDESBASE int __fastcall ControlCount(void);
	virtual void __fastcall Invalidate(void);
	__property Qcontrols::TControl* Controls[int Index] = {read=GetControl};
	
__published:
	__property Align  = {default=1};
	__property Anchors  = {default=3};
	__property bool AutoSize = {read=FAutoSize, write=SetAutoSize, default=0};
	__property Bitmap ;
	__property Qextctrls::TBorderWidth BorderWidth = {read=FBorderWidth, write=SetBorderWidth, default=0};
	__property int ButtonHeight = {read=FButtonHeight, write=SetButtonHeight, default=22};
	__property int ButtonWidth = {read=FButtonWidth, write=SetButtonWidth, default=23};
	__property Caption ;
	__property Color  = {default=-10};
	__property Constraints ;
	__property Qimglist::TCustomImageList* DisabledImages = {read=FDisabledImages, write=SetDisabledImages};
	__property DragMode  = {default=0};
	__property Qgraphics::TEdgeBorders EdgeBorders = {read=FEdgeBorders, write=SetEdgeBorders, default=2};
	__property Qgraphics::TEdgeStyle EdgeInner = {read=FEdgeInner, write=SetEdgeInner, default=1};
	__property Qgraphics::TEdgeStyle EdgeOuter = {read=FEdgeOuter, write=SetEdgeOuter, default=2};
	__property Enabled  = {default=1};
	__property bool Flat = {read=FFlat, write=SetFlat, default=0};
	__property Font ;
	__property Height  = {default=32};
	__property Qimglist::TCustomImageList* HotImages = {read=FHotImages, write=SetHotImages};
	__property Qimglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property int Indent = {read=FIndent, write=SetIndent, default=1};
	__property bool List = {read=FList, write=SetList, default=0};
	__property Masked  = {default=0};
	__property ParentColor  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property bool ShowCaptions = {read=FShowCaptions, write=SetShowCaptions, default=0};
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=0};
	__property Visible  = {default=1};
	__property bool Wrapable = {read=FWrapable, write=SetWrapable, default=1};
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
	/* TWidgetControl.CreateParented */ inline __fastcall TToolBar(Qt::QWidgetH* ParentWidget) : Qcontrols::TCustomControl(ParentWidget) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TToolButton : public Qcontrols::TCustomControl 
{
	typedef Qcontrols::TCustomControl inherited;
	
private:
	bool FAllowAllUp;
	bool FAutoSize;
	bool FDown;
	bool FGrouped;
	bool FMouseIn;
	Qimglist::TImageIndex FImageIndex;
	bool FIndeterminate;
	bool FMarked;
	Qmenus::TPopupMenu* FDropDownMenu;
	bool FMenuDropped;
	bool FWrap;
	TToolButtonStyle FStyle;
	int FUpdateCount;
	bool FJustChecked;
	WideString FCaption;
	Types::TRect __fastcall DropDownRect();
	int __fastcall GetIndex(void);
	bool __fastcall IsCheckedStored(void);
	bool __fastcall IsImageIndexStored(void);
	bool __fastcall IsWidthStored(void);
	void __fastcall SetAutoSize(bool Value);
	void __fastcall SetDown(bool Value);
	void __fastcall SetDropDownMenu(Qmenus::TPopupMenu* Value);
	void __fastcall SetGrouped(bool Value);
	void __fastcall SetImageIndex(Qimglist::TImageIndex Value);
	void __fastcall SetIndeterminate(bool Value);
	void __fastcall SetMarked(bool Value);
	HIDESBASE void __fastcall SetStyle(TToolButtonStyle Value);
	void __fastcall SetWrap(bool Value);
	void __fastcall SetAllowAllUp(const bool Value);
	
protected:
	TToolBar* FToolBar;
	DYNAMIC void __fastcall ActionChange(System::TObject* Sender, bool CheckDefaults);
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	virtual void __fastcall BeginUpdate(void);
	void __fastcall DoPaint(Qgraphics::TCanvas* Canvas);
	virtual int __fastcall DropDownWidth(void);
	virtual void __fastcall EndUpdate(void);
	virtual bool __fastcall EventFilter(Qt::QObjectH* Sender, Qt::QEventH* Event);
	virtual void __fastcall InitWidget(void);
	bool __fastcall IsEnabled(void);
	DYNAMIC TMetaClass* __fastcall GetActionLinkClass(void);
	virtual WideString __fastcall GetText();
	DYNAMIC void __fastcall MouseEnter(Qcontrols::TControl* AControl);
	DYNAMIC void __fastcall MouseLeave(Qcontrols::TControl* AControl);
	DYNAMIC void __fastcall MouseDown(Qcontrols::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall Paint(void);
	virtual void __fastcall SetName(const AnsiString Value);
	virtual void __fastcall SetParent(const Qcontrols::TWidgetControl* Value);
	virtual void __fastcall SetText(const WideString Value);
	void __fastcall SetToolBar(TToolBar* AToolBar);
	DYNAMIC void __fastcall ValidateContainer(Classes::TComponent* AComponent);
	DYNAMIC bool __fastcall WantKey(int Key, Classes::TShiftState Shift, const WideString KeyText);
	
public:
	__fastcall virtual TToolButton(Classes::TComponent* AOwner);
	DYNAMIC bool __fastcall CheckMenuDropDown(void);
	DYNAMIC void __fastcall Click(void);
	virtual void __fastcall ChangeBounds(int ALeft, int ATop, int AWidth, int AHeight);
	__property int Index = {read=GetIndex, nodefault};
	__property TToolBar* Toolbar = {read=FToolBar, write=SetToolBar};
	
__published:
	__property TToolButtonStyle Style = {read=FStyle, write=SetStyle, default=0};
	__property Action ;
	__property bool AllowAllUp = {read=FAllowAllUp, write=SetAllowAllUp, default=0};
	__property bool AutoSize = {read=FAutoSize, write=SetAutoSize, default=0};
	__property Caption ;
	__property bool Down = {read=FDown, write=SetDown, stored=IsCheckedStored, default=0};
	__property DragMode  = {default=0};
	__property Qmenus::TPopupMenu* DropDownMenu = {read=FDropDownMenu, write=SetDropDownMenu};
	__property Enabled  = {default=1};
	__property bool Grouped = {read=FGrouped, write=SetGrouped, default=0};
	__property Qimglist::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, stored=IsImageIndexStored, default=-1};
	__property bool Indeterminate = {read=FIndeterminate, write=SetIndeterminate, default=0};
	__property bool Marked = {read=FMarked, write=SetMarked, default=0};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property bool Wrap = {read=FWrap, write=SetWrap, default=0};
	__property ShowHint ;
	__property Visible  = {default=1};
	__property Width  = {stored=IsWidthStored};
	__property OnClick ;
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
	/* TCustomControl.Destroy */ inline __fastcall virtual ~TToolButton(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TToolButton(Qt::QWidgetH* ParentWidget) : Qcontrols::TCustomControl(ParentWidget) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TToolButtonActionLink : public Qcontrols::TControlActionLink 
{
	typedef Qcontrols::TControlActionLink inherited;
	
protected:
	TToolButton* FClient;
	virtual void __fastcall AssignClient(System::TObject* AClient);
	virtual bool __fastcall IsCheckedLinked(void);
	virtual bool __fastcall IsImageIndexLinked(void);
	virtual void __fastcall SetChecked(bool Value);
	virtual void __fastcall SetImageIndex(int Value);
public:
	#pragma option push -w-inl
	/* TBasicActionLink.Create */ inline __fastcall virtual TToolButtonActionLink(System::TObject* AClient) : Qcontrols::TControlActionLink(AClient) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBasicActionLink.Destroy */ inline __fastcall virtual ~TToolButtonActionLink(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TToolButtonActionLinkClass;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall CheckRange(int AMin, int AMax);
extern PACKAGE TMimeSourceFactory* __fastcall DefaultMimeFactory(void);
extern PACKAGE void __fastcall SetDefaultMimeFactory(TMimeSourceFactory* Value);

}	/* namespace Qcomctrls */
using namespace Qcomctrls;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QComCtrls
