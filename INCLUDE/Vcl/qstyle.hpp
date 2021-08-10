// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QStyle.pas' rev: 6.00

#ifndef QStyleHPP
#define QStyleHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QGraphics.hpp>	// Pascal unit
#include <Qt.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <QTypes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qstyle
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TScrollBarControl { sbcAddButton, sbcSubButton, sbcAddPage, sbcSubPage, sbcSlider, sbcNone };
#pragma option pop

typedef Set<TScrollBarControl, sbcAddButton, sbcNone>  TScrollBarControls;

typedef void __fastcall (__closure *TBeforeDrawButtonEvent)(System::TObject* Sender, System::TObject* Source, Qgraphics::TCanvas* Canvas, bool &DefaultDraw);

typedef void __fastcall (__closure *TAfterDrawButtonEvent)(System::TObject* Sender, System::TObject* Source, Qgraphics::TCanvas* Canvas);

typedef void __fastcall (__closure *TBeforeDrawMenuItemEvent)(System::TObject* Sender, System::TObject* Source, Qgraphics::TCanvas* Canvas, bool Highlighted, bool Enabled, const Types::TRect &Rect, bool Checkable, int CheckMaxWidth, int LabelWidth, bool &DefaultDraw);

typedef void __fastcall (__closure *TAfterDrawMenuItemEvent)(System::TObject* Sender, System::TObject* Source, Qgraphics::TCanvas* Canvas, bool Highlighted, bool Enabled, const Types::TRect &Rect, bool Checkable, int CheckMaxWidth, int LabelWidth);

typedef void __fastcall (__closure *TDrawButtonFrameEvent)(System::TObject* Sender, Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, bool Down, bool &DefaultDraw);

typedef void __fastcall (__closure *TDrawFocusRectEvent)(System::TObject* Sender, Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, bool AtBorder, bool &DefaultDraw);

typedef void __fastcall (__closure *TDrawHintEvent)(System::TObject* Sender, Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, bool &DefaultDraw);

typedef void __fastcall (__closure *TDrawCheckEvent)(System::TObject* Sender, Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, bool Checked, bool Grayed, bool Down, bool Enabled, bool &DefaultDraw);

typedef void __fastcall (__closure *TDrawMenuFrameEvent)(System::TObject* Sender, Qgraphics::TCanvas* Canvas, const Types::TRect &R, int LineWidth, bool &DefaultDraw);

typedef void __fastcall (__closure *TDrawRadioEvent)(System::TObject* Sender, Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, bool Checked, bool Down, bool Enabled, bool &DefaultDraw);

typedef void __fastcall (__closure *TDrawFrameEvent)(System::TObject* Sender, Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, bool Sunken, int LineWidth, bool &DefaultDraw);

typedef void __fastcall (__closure *TDrawMenuCheckEvent)(System::TObject* Sender, Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, bool Checked, bool Enabled);

typedef void __fastcall (__closure *TBeforeDrawItemEvent)(System::TObject* Sender, Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, int Flags, bool Enabled, Qgraphics::TBitmap* Bitmap, const WideString Text, int Length, Qgraphics::TColor Color, bool &DefaultDraw);

typedef void __fastcall (__closure *TAfterDrawItemEvent)(System::TObject* Sender, Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, int Flags, bool Enabled, Qgraphics::TBitmap* Bitmap, const WideString Text, int Length, Qgraphics::TColor Color);

typedef void __fastcall (__closure *TDrawComboButtonEvent)(System::TObject* Sender, Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, bool Sunken, bool ReadOnly, bool Enabled, bool &DefaultDraw);

typedef void __fastcall (__closure *TDrawMaskEvent)(System::TObject* Sender, Qgraphics::TCanvas* Canvas, const Types::TRect &Rect);

typedef void __fastcall (__closure *TDrawRadioMaskEvent)(System::TObject* Sender, Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, bool Checked);

typedef void __fastcall (__closure *TGetItemRectEvent)(System::TObject* Sender, Qgraphics::TCanvas* Canvas, Types::TRect &Rect, int Flags, bool Enabled, Qgraphics::TBitmap* Bitmap, const WideString Text);

typedef void __fastcall (__closure *TPolishEvent)(System::TObject* Sender, System::TObject* Source);

typedef void __fastcall (__closure *TDrawHeaderSectionEvent)(System::TObject* Sender, Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, bool Down, bool &DefaultDraw);

typedef void __fastcall (__closure *TButtonRectEvent)(System::TObject* Sender, Types::TRect &Rect);

typedef void __fastcall (__closure *TDrawArrowEvent)(System::TObject* Sender, Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, Qt::ArrowType Arrow, bool Down, bool Enabled);

typedef void __fastcall (__closure *TDrawCheckMaskEvent)(System::TObject* Sender, Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, bool Checked, bool Grayed);

typedef void __fastcall (__closure *TTabMetricsEvent)(System::TObject* Sender, System::TObject* Source, int &HorizonalPadding, int &VerticalPadding, int &Overlap);

typedef void __fastcall (__closure *TDrawTabEvent)(System::TObject* Sender, System::TObject* Source, Qgraphics::TCanvas* Canvas, int Index, int HorizonalPadding, int VerticalPadding, int Overlap, bool Selected);

typedef void __fastcall (__closure *TScrollBarMetricsEvent)(System::TObject* Sender, Qt::QScrollBarH* ScrollBar, int &SliderLength, int &ButtonSize);

typedef void __fastcall (__closure *TDrawScrollBarEvent)(System::TObject* Sender, Qt::QScrollBarH* ScrollBar, Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, int SliderStart, int SliderLength, int ButtonSize, TScrollBarControls Controls, TScrollBarControl DownControl, bool &DefaultDraw);

typedef void __fastcall (__closure *TDrawTrackBarEvent)(System::TObject* Sender, Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, bool Horizontal, bool TickAbove, bool TickBelow, bool &DefaultDraw);

typedef void __fastcall (__closure *TDrawTrackBarGrooveEvent)(System::TObject* Sender, Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, bool Horizontal, bool &DefaultDraw);

typedef void __fastcall (__closure *TDrawSplitterEvent)(System::TObject* Sender, Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, bool Vertical, bool &DefaultDraw);

typedef void __fastcall (__closure *TExtraMenuItemWidthEvent)(System::TObject* Sender, System::TObject* Source, bool HasCheckmark, int ImageWidth, Qt::QFontMetricsH* FontMetrics, int &ExtraWidth);

typedef void __fastcall (__closure *TSubmenuIndicatorWidthEvent)(System::TObject* Sender, Qt::QFontMetricsH* FontMetrics, int &Width);

typedef void __fastcall (__closure *TMenuItemHeightEvent)(System::TObject* Sender, System::TObject* Source, bool Checkable, Qt::QFontMetricsH* FontMetrics, int &Height);

#pragma option push -b-
enum TDefaultStyle { dsWindows, dsMotif, dsMotifPlus, dsCDE, dsQtSGI, dsPlatinum, dsSystemDefault };
#pragma option pop

class DELPHICLASS TStyle;
class PASCALIMPLEMENTATION TStyle : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Qt::QClxStyleH* FHandle;
	Qt::QClxStyleHooksH* FHooks;
	Classes::TNotifyEvent FOnChange;
	TDrawFocusRectEvent FDrawFocusRect;
	TBeforeDrawMenuItemEvent FBeforeDrawMenuItem;
	TAfterDrawMenuItemEvent FAfterDrawMenuItem;
	TDrawMenuFrameEvent FDrawMenuFrame;
	TBeforeDrawButtonEvent FBeforeDrawButton;
	TAfterDrawButtonEvent FAfterDrawButton;
	TDrawButtonFrameEvent FDrawButtonFrame;
	TBeforeDrawButtonEvent FDrawButtonLabel;
	TDrawCheckEvent FDrawCheck;
	TDrawRadioEvent FDrawRadio;
	TDefaultStyle FDefaultStyle;
	TDrawMenuCheckEvent FDrawMenuCheck;
	TAfterDrawItemEvent FAfterDrawItem;
	TBeforeDrawItemEvent FBeforeDrawItem;
	TDrawComboButtonEvent FDrawComboButton;
	TDrawMaskEvent FDrawButtonMask;
	TGetItemRectEvent FGetItemRect;
	TDrawHeaderSectionEvent FDrawHeaderSection;
	TDrawHintEvent FDrawHint;
	TButtonRectEvent FHeaderSectionRect;
	TButtonRectEvent FButtonRect;
	TDrawArrowEvent FDrawArrow;
	TDrawRadioMaskEvent FDrawRadioMask;
	TDrawCheckMaskEvent FDrawCheckMask;
	TButtonRectEvent FComboButtonRect;
	TButtonRectEvent FComboButtonFocusRect;
	TDrawMaskEvent FDrawComboButtonMask;
	TTabMetricsEvent FTabMetrics;
	TDrawTabEvent FDrawTab;
	TDrawTabEvent FDrawTabMask;
	TScrollBarMetricsEvent FScrollBarMetrics;
	TDrawScrollBarEvent FDrawScrollBar;
	TDrawTrackBarEvent FDrawTrackBar;
	TDrawTrackBarEvent FDrawTrackBarMask;
	TDrawTrackBarGrooveEvent FDrawTrackBarGroove;
	TDrawTrackBarGrooveEvent FDrawTrackBarGrooveMask;
	TDrawSplitterEvent FDrawSplitter;
	TExtraMenuItemWidthEvent FExtraMenuItemWidth;
	TSubmenuIndicatorWidthEvent FSubmenuIndicatorWidth;
	TMenuItemHeightEvent FMenuItemHeight;
	TDrawFrameEvent FDrawFrame;
	void __cdecl BevelButtonRectHook(int &x, int &y, int &w, int &h);
	void __cdecl ButtonRectHook(int &x, int &y, int &w, int &h);
	void __cdecl ComboButtonRectHook(int &x, int &y, int &w, int &h);
	void __cdecl ComboButtonFocusRectHook(int &x, int &y, int &w, int &h);
	void __cdecl DrawArrowHook(Qt::QPainterH* p, Qt::ArrowType _type, bool down, int x, int y, int w, int h, Qt::QColorGroupH* g, bool enabled, Qt::QBrushH* fill);
	void __cdecl DrawBevelButtonHook(Qt::QPainterH* p, int x, int y, int w, int h, Qt::QColorGroupH* g, bool sunken, Qt::QBrushH* fill, int &Stage);
	void __cdecl DrawButtonHook(Qt::QPainterH* p, int x, int y, int w, int h, Qt::QColorGroupH* g, bool sunken, Qt::QBrushH* fill, int &Stage);
	void __cdecl DrawButtonMaskHook(Qt::QPainterH* p, int x, int y, int w, int h);
	void __cdecl DrawCheckHook(Qt::QPainterH* p, int x, int y, int w, int h, Qt::QColorGroupH* g, int State, bool Down, bool Enabled, int &Stage);
	void __cdecl DrawComboButtonHook(Qt::QPainterH* p, int x, int y, int w, int h, Qt::QColorGroupH* g, bool sunken, bool editable, bool enabled, Qt::QBrushH* fill, int &Stage);
	void __cdecl DrawComboButtonMaskHook(Qt::QPainterH* p, int x, int y, int w, int h);
	void __cdecl DrawFocusRectHook(Qt::QPainterH* p1, Types::PRect p2, Qt::QColorGroupH* p3, Qt::QColorH* bg, bool p5, int &Stage);
	void __cdecl DrawIndicatorMaskHook(Qt::QPainterH* p, int x, int y, int w, int h, int state);
	void __cdecl DrawItemHook(Qt::QPainterH* p, int x, int y, int w, int h, int flags, Qt::QColorGroupH* g, bool enabled, Qt::QPixmapH* pixmap, System::PAnsiString text, int len, Qt::QColorH* penColor, int &Stage);
	void __cdecl DrawMenuCheckHook(Qt::QPainterH* p, int x, int y, int w, int h, Qt::QColorGroupH* g, bool act, bool dis);
	void __cdecl DrawPopupMenuItemHook(Qt::QPainterH* p, bool checkable, int maxpmw, int tab, Qt::QMenuItemH* mi, int itemID, bool act, bool enabled, int x, int y, int w, int h, int &Stage);
	void __cdecl DrawPopupPanelHook(Qt::QPainterH* p, int x, int y, int w, int h, Qt::QColorGroupH* p6, int lineWidth, Qt::QBrushH* fill, int &Stage);
	void __cdecl DrawPushButtonHook(Qt::QPushButtonH* btn, Qt::QPainterH* p, int &Stage);
	void __cdecl DrawPushButtonLabelHook(Qt::QPushButtonH* btn, Qt::QPainterH* p, int &Stage);
	void __cdecl DrawRadioHook(Qt::QPainterH* p, int x, int y, int w, int h, Qt::QColorGroupH* g, bool _on, bool down, bool enabled, int &Stage);
	void __cdecl DrawRadioMaskHook(Qt::QPainterH* p, int x, int y, int w, int h, bool _on);
	void __cdecl DrawScrollBarHook(Qt::QPainterH* p1, Qt::QScrollBarH* p2, int sliderStart, int controls, int activeControl, int &Stage);
	void __cdecl DrawSliderHook(Qt::QPainterH* p, int x, int y, int w, int h, Qt::QColorGroupH* g, Qt::Orientation p7, bool tickAbove, bool tickBelow, int &Stage);
	void __cdecl DrawSliderMaskHook(Qt::QPainterH* p, int x, int y, int w, int h, Qt::Orientation p6, bool tickAbove, bool tickBelow);
	void __cdecl DrawSliderGrooveHook(Qt::QPainterH* p, int x, int y, int w, int h, Qt::QColorGroupH* g, Qt::QCOORD c, Qt::Orientation p8, int &Stage);
	void __cdecl DrawSliderGrooveMaskHook(Qt::QPainterH* p, int x, int y, int w, int h, Qt::QCOORD c, Qt::Orientation p8);
	void __cdecl DrawSplitterHook(Qt::QPainterH* p, int x, int y, int w, int h, Qt::QColorGroupH* g, Qt::Orientation p7, int &Stage);
	void __cdecl DrawTabHook(Qt::QPainterH* p1, QTabBarH* p2, int index, bool selected);
	void __cdecl DrawTabMaskHook(Qt::QPainterH* p1, QTabBarH* p2, int index, bool selected);
	void __cdecl DrawPanelHook(Qt::QPainterH* p, int x, int y, int w, int h, Qt::QColorGroupH* p6, bool sunken, int lineWidth, Qt::QBrushH* fill, int &Stage);
	void __cdecl ExtraMenuItemWidthHook(bool checkable, int maxpmw, Qt::QMenuItemH* mi, Qt::QFontMetricsH* fm, int &Retval);
	void __cdecl ItemRectHook(Qt::QPainterH* p, int &x, int &y, int &w, int &h, int flags, bool enabled, Qt::QPixmapH* pixmap, System::PAnsiString text, int len);
	void __cdecl MenuItemHeightHook(bool checkable, Qt::QMenuItemH* mi, Qt::QFontMetricsH* fm, int &Height);
	void __cdecl ScrollBarMetricsHook(Qt::QScrollBarH* p1, int &sliderMin, int &sliderMax, int &sliderLength, int &buttonDim);
	void __cdecl SubmenuIndicatorWidthHook(Qt::QFontMetricsH* fm, int &Retval);
	void __cdecl TabBarMetricsHook(QTabBarH* p1, int &hFrame, int &vFrame, int &overlap);
	Types::TPoint __fastcall GetButtonShift();
	tagSIZE __fastcall GetCheckSize();
	int __fastcall GetDefaultFrameWidth(void);
	Qt::QClxStyleH* __fastcall GetHandle(void);
	int __fastcall GetMaxSliderDragDistance(void);
	tagSIZE __fastcall GetRadioSize();
	int __fastcall GetSliderLength(void);
	void __fastcall SetAfterDrawButton(const TAfterDrawButtonEvent Value);
	void __fastcall SetAfterDrawItem(const TAfterDrawItemEvent Value);
	void __fastcall SetAfterDrawMenuItem(const TAfterDrawMenuItemEvent Value);
	void __fastcall SetBeforeDrawButton(const TBeforeDrawButtonEvent Value);
	void __fastcall SetBeforeDrawItem(const TBeforeDrawItemEvent Value);
	void __fastcall SetBeforeDrawMenuItem(const TBeforeDrawMenuItemEvent Value);
	void __fastcall SetButtonRect(const TButtonRectEvent Value);
	void __fastcall SetButtonShift(const Types::TPoint &Value);
	void __fastcall SetCheckSize(const tagSIZE &Value);
	void __fastcall SetComboButtonRect(const TButtonRectEvent Value);
	void __fastcall SetComboButtonFocusRect(const TButtonRectEvent Value);
	void __fastcall SetDefaultFrameWidth(const int Value);
	virtual void __fastcall SetDefaultStyle(const TDefaultStyle Value);
	void __fastcall SetDrawArrow(const TDrawArrowEvent Value);
	void __fastcall SetDrawButtonMask(const TDrawMaskEvent Value);
	void __fastcall SetDrawButtonFrame(const TDrawButtonFrameEvent Value);
	void __fastcall SetDrawButtonLabel(const TBeforeDrawButtonEvent Value);
	void __fastcall SetDrawCheck(const TDrawCheckEvent Value);
	void __fastcall SetDrawCheckMask(const TDrawCheckMaskEvent Value);
	void __fastcall SetDrawComboButton(const TDrawComboButtonEvent Value);
	void __fastcall SetDrawComboButtonMask(const TDrawMaskEvent Value);
	void __fastcall SetDrawFocusRect(const TDrawFocusRectEvent Value);
	void __fastcall SetDrawHint(const TDrawHintEvent Value);
	void __fastcall SetDrawHeaderSection(const TDrawHeaderSectionEvent Value);
	void __fastcall SetDrawMenuCheck(const TDrawMenuCheckEvent Value);
	void __fastcall SetDrawMenuFrame(const TDrawMenuFrameEvent Value);
	void __fastcall SetDrawRadio(const TDrawRadioEvent Value);
	void __fastcall SetDrawRadioMask(const TDrawRadioMaskEvent Value);
	void __fastcall SetDrawScrollBar(const TDrawScrollBarEvent Value);
	void __fastcall SetDrawTrackBar(const TDrawTrackBarEvent Value);
	void __fastcall SetDrawTrackBarMask(const TDrawTrackBarEvent Value);
	void __fastcall SetDrawTrackBarGroove(const TDrawTrackBarGrooveEvent Value);
	void __fastcall SetDrawTrackBarGrooveMask(const TDrawTrackBarGrooveEvent Value);
	void __fastcall SetDrawSplitter(const TDrawSplitterEvent Value);
	void __fastcall SetDrawTab(const TDrawTabEvent Value);
	void __fastcall SetDrawTabMask(const TDrawTabEvent Value);
	void __fastcall SetExtraMenuItemWidth(const TExtraMenuItemWidthEvent Value);
	void __fastcall SetGetItemRect(const TGetItemRectEvent Value);
	void __fastcall SetHeaderSectionRect(const TButtonRectEvent Value);
	void __fastcall SetMaxSliderDragDistance(const int Value);
	void __fastcall SetMenuItemHeight(const TMenuItemHeightEvent Value);
	void __fastcall SetRadioSize(const tagSIZE &Value);
	void __fastcall SetScrollBarMetrics(const TScrollBarMetricsEvent Value);
	void __fastcall SetSliderLength(const int Value);
	void __fastcall SetSubmenuIndicatorWidth(const TSubmenuIndicatorWidthEvent Value);
	void __fastcall SetTabMetrics(const TTabMetricsEvent Value);
	void __fastcall SetDrawFrame(const TDrawFrameEvent Value);
	
protected:
	DYNAMIC void __fastcall Changed(System::TObject* Sender);
	virtual void __fastcall CreateHandle(void);
	virtual void __fastcall DoAfterDrawButton(System::TObject* Source, Qgraphics::TCanvas* Canvas);
	virtual void __fastcall DoAfterDrawItem(Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, int Flags, bool Enabled, Qgraphics::TBitmap* Bitmap, const WideString Text, int Length, Qgraphics::TColor Color);
	virtual bool __fastcall DoBeforeDrawButton(System::TObject* Source, Qgraphics::TCanvas* Canvas);
	virtual bool __fastcall DoBeforeDrawItem(Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, int Flags, bool Enabled, Qgraphics::TBitmap* Bitmap, const WideString Text, int Length, Qgraphics::TColor Color);
	virtual void __fastcall DoButtonRect(Types::TRect &Rect);
	virtual void __fastcall DoComboButtonRect(Types::TRect &Rect);
	virtual void __fastcall DoComboButtonFocusRect(Types::TRect &Rect);
	virtual void __fastcall DoDrawArrow(Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, Qt::ArrowType Arrow, bool Down, bool Enabled);
	virtual bool __fastcall DoDrawButtonFrame(Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, bool Down);
	virtual bool __fastcall DoDrawButtonLabel(System::TObject* Source, Qgraphics::TCanvas* Canvas);
	virtual void __fastcall DoDrawButtonMask(Qgraphics::TCanvas* Canvas, const Types::TRect &Rect);
	virtual bool __fastcall DoDrawCheck(Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, bool Checked, bool Grayed, bool Down, bool Enabled);
	virtual void __fastcall DoDrawCheckMask(Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, bool Checked, bool Grayed);
	virtual bool __fastcall DoDrawComboButton(Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, bool Sunken, bool ReadOnly, bool Enabled);
	virtual void __fastcall DoDrawComboButtonMask(Qgraphics::TCanvas* Canvas, const Types::TRect &Rect);
	virtual bool __fastcall DoDrawFocusRect(Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, bool AtBorder);
	virtual bool __fastcall DoDrawHeaderSection(Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, bool Down);
	virtual bool __fastcall DoDrawMenuFrame(Qgraphics::TCanvas* Canvas, const Types::TRect &R, int LineWidth);
	virtual void __fastcall DoDrawMenuItem(System::TObject* Source, Qgraphics::TCanvas* Canvas, bool Highlighted, bool Enabled, const Types::TRect &Rect, bool Checkable, int CheckMaxWidth, int LabelWidth, int &Stage);
	virtual void __fastcall DoDrawMenuCheck(Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, bool Highlighted, bool Enabled);
	virtual void __fastcall DoDrawRadioMask(Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, bool Checked);
	virtual bool __fastcall DoDrawRadio(Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, bool Checked, bool Down, bool Enabled);
	virtual bool __fastcall DoDrawScrollBar(Qt::QScrollBarH* ScrollBar, Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, int SliderStart, int SliderLength, int ButtonSize, TScrollBarControls Controls, TScrollBarControl DownControl);
	virtual bool __fastcall DoDrawTrackBar(Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, bool Horizontal, bool TickAbove, bool TickBelow);
	virtual bool __fastcall DoDrawTrackBarMask(Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, bool Horizontal, bool TickAbove, bool TickBelow);
	virtual bool __fastcall DoDrawTrackBarGroove(Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, bool Horizontal);
	virtual bool __fastcall DoDrawTrackBarGrooveMask(Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, bool Horizontal);
	virtual bool __fastcall DoDrawSplitter(Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, bool Vertical);
	virtual void __fastcall DoDrawTab(System::TObject* Source, Qgraphics::TCanvas* Canvas, int Index, int HorizontalPadding, int VerticalPadding, int Overlap, bool Selected);
	virtual void __fastcall DoDrawTabMask(System::TObject* Source, Qgraphics::TCanvas* Canvas, int Index, int HorizontalPadding, int VerticalPadding, int Overlap, bool Selected);
	virtual void __fastcall DoExtraMenuItemWidth(System::TObject* Source, bool HasCheckmark, int ImageWidth, Qt::QFontMetricsH* FontMetrics, int &ExtraWidth);
	void __fastcall DoGetItemRect(Qgraphics::TCanvas* Canvas, Types::TRect &Rect, int Flags, bool Enabled, Qgraphics::TBitmap* Bitmap, const WideString Text);
	virtual bool __fastcall DoDrawFrame(Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, bool Sunken, int LineWidth);
	virtual void __fastcall DoHeaderSectionRect(Types::TRect &Rect);
	virtual void __fastcall DoMenuItemHeight(System::TObject* Source, bool Checkable, Qt::QFontMetricsH* FontMetrics, int &Height);
	virtual void __fastcall DoScrollBarMetrics(Qt::QScrollBarH* ScrollBar, int &SliderMin, int &SliderMax, int &SliderLength, int &ButtonSize);
	virtual void __fastcall DoSubmenuIndicatorWidth(Qt::QFontMetricsH* FontMetrics, int &Width);
	virtual void __fastcall DoTabMetrics(System::TObject* Source, int &HorizontalPadding, int &VerticalPadding, int &Overlap);
	void __cdecl StyleDestroyedHook(void);
	virtual void __fastcall StyleDestroyed(void);
	
public:
	__fastcall virtual TStyle(void);
	void __fastcall HandleNeeded(void);
	void __fastcall Refresh(void);
	Qt::QClxStyleHooksH* __fastcall GetHooks(void);
	__property Types::TPoint ButtonShift = {read=GetButtonShift, write=SetButtonShift};
	__property tagSIZE CheckSize = {read=GetCheckSize, write=SetCheckSize};
	__property TDefaultStyle DefaultStyle = {read=FDefaultStyle, write=SetDefaultStyle, nodefault};
	__property Qt::QClxStyleH* Handle = {read=GetHandle};
	__property Qt::QClxStyleHooksH* Hooks = {read=GetHooks};
	__property int MaxSliderDragDistance = {read=GetMaxSliderDragDistance, write=SetMaxSliderDragDistance, nodefault};
	__property tagSIZE RadioSize = {read=GetRadioSize, write=SetRadioSize};
	__property int SliderLength = {read=GetSliderLength, write=SetSliderLength, nodefault};
	__property TAfterDrawButtonEvent AfterDrawButton = {read=FAfterDrawButton, write=SetAfterDrawButton};
	__property TAfterDrawItemEvent AfterDrawItem = {read=FAfterDrawItem, write=SetAfterDrawItem};
	__property TAfterDrawMenuItemEvent AfterDrawMenuItem = {read=FAfterDrawMenuItem, write=SetAfterDrawMenuItem};
	__property TBeforeDrawButtonEvent BeforeDrawButton = {read=FBeforeDrawButton, write=SetBeforeDrawButton};
	__property TBeforeDrawItemEvent BeforeDrawItem = {read=FBeforeDrawItem, write=SetBeforeDrawItem};
	__property TBeforeDrawMenuItemEvent BeforeDrawMenuItem = {read=FBeforeDrawMenuItem, write=SetBeforeDrawMenuItem};
	__property TButtonRectEvent ButtonRect = {read=FButtonRect, write=SetButtonRect};
	__property TButtonRectEvent ComboButtonRect = {read=FComboButtonRect, write=SetComboButtonRect};
	__property TButtonRectEvent ComboButtonFocusRect = {read=FComboButtonFocusRect, write=SetComboButtonFocusRect};
	__property int DefaultFrameWidth = {read=GetDefaultFrameWidth, write=SetDefaultFrameWidth, nodefault};
	__property TDrawHintEvent DrawHint = {read=FDrawHint, write=SetDrawHint};
	__property TDrawArrowEvent DrawArrow = {read=FDrawArrow, write=SetDrawArrow};
	__property TBeforeDrawButtonEvent DrawButtonLabel = {read=FDrawButtonLabel, write=SetDrawButtonLabel};
	__property TDrawButtonFrameEvent DrawButtonFrame = {read=FDrawButtonFrame, write=SetDrawButtonFrame};
	__property TDrawMaskEvent DrawButtonMask = {read=FDrawButtonMask, write=SetDrawButtonMask};
	__property TDrawCheckEvent DrawCheck = {read=FDrawCheck, write=SetDrawCheck};
	__property TDrawCheckMaskEvent DrawCheckMask = {read=FDrawCheckMask, write=SetDrawCheckMask};
	__property TDrawComboButtonEvent DrawComboButton = {read=FDrawComboButton, write=SetDrawComboButton};
	__property TDrawMaskEvent DrawComboButtonMask = {read=FDrawComboButtonMask, write=SetDrawComboButtonMask};
	__property TDrawFocusRectEvent DrawFocusRect = {read=FDrawFocusRect, write=SetDrawFocusRect};
	__property TDrawHeaderSectionEvent DrawHeaderSection = {read=FDrawHeaderSection, write=SetDrawHeaderSection};
	__property TDrawMenuCheckEvent DrawMenuCheck = {read=FDrawMenuCheck, write=SetDrawMenuCheck};
	__property TDrawMenuFrameEvent DrawMenuFrame = {read=FDrawMenuFrame, write=SetDrawMenuFrame};
	__property TDrawRadioEvent DrawRadio = {read=FDrawRadio, write=SetDrawRadio};
	__property TDrawRadioMaskEvent DrawRadioMask = {read=FDrawRadioMask, write=SetDrawRadioMask};
	__property TDrawScrollBarEvent DrawScrollBar = {read=FDrawScrollBar, write=SetDrawScrollBar};
	__property TDrawTrackBarEvent DrawTrackBar = {read=FDrawTrackBar, write=SetDrawTrackBar};
	__property TDrawTrackBarEvent DrawTrackBarMask = {read=FDrawTrackBarMask, write=SetDrawTrackBarMask};
	__property TDrawTrackBarGrooveEvent DrawTrackBarGroove = {read=FDrawTrackBarGroove, write=SetDrawTrackBarGroove};
	__property TDrawTrackBarGrooveEvent DrawTrackBarGrooveMask = {read=FDrawTrackBarGrooveMask, write=SetDrawTrackBarGrooveMask};
	__property TDrawSplitterEvent DrawSplitter = {read=FDrawSplitter, write=SetDrawSplitter};
	__property TDrawTabEvent DrawTab = {read=FDrawTab, write=SetDrawTab};
	__property TDrawTabEvent DrawTabMask = {read=FDrawTabMask, write=SetDrawTabMask};
	__property TExtraMenuItemWidthEvent ExtraMenuItemWidth = {read=FExtraMenuItemWidth, write=SetExtraMenuItemWidth};
	__property TGetItemRectEvent GetItemRect = {read=FGetItemRect, write=SetGetItemRect};
	__property TDrawFrameEvent DrawFrame = {read=FDrawFrame, write=SetDrawFrame};
	__property TButtonRectEvent HeaderSectionRect = {read=FHeaderSectionRect, write=SetHeaderSectionRect};
	__property TMenuItemHeightEvent MenuItemHeight = {read=FMenuItemHeight, write=SetMenuItemHeight};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property TScrollBarMetricsEvent ScrollBarMetrics = {read=FScrollBarMetrics, write=SetScrollBarMetrics};
	__property TSubmenuIndicatorWidthEvent SubmenuIndicatorWidth = {read=FSubmenuIndicatorWidth, write=SetSubmenuIndicatorWidth};
	__property TTabMetricsEvent TabMetrics = {read=FTabMetrics, write=SetTabMetrics};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TStyle(void) { }
	#pragma option pop
	
};


class DELPHICLASS TApplicationStyle;
class PASCALIMPLEMENTATION TApplicationStyle : public TStyle 
{
	typedef TStyle inherited;
	
private:
	bool FRecreating;
	TPolishEvent FOnPolish;
	void __cdecl PolishHook(Qt::QApplicationH* p1);
	void __fastcall SetOnPolish(const TPolishEvent Value);
	
protected:
	virtual void __fastcall DoPolish(System::TObject* Source);
	virtual void __fastcall CreateHandle(void);
	virtual void __fastcall SetDefaultStyle(const TDefaultStyle Value);
	virtual void __fastcall StyleDestroyed(void);
	
public:
	__fastcall virtual ~TApplicationStyle(void);
	__property TPolishEvent OnPolish = {read=FOnPolish, write=SetOnPolish};
public:
	#pragma option push -w-inl
	/* TStyle.Create */ inline __fastcall virtual TApplicationStyle(void) : TStyle() { }
	#pragma option pop
	
};


class DELPHICLASS TWidgetStyle;
class PASCALIMPLEMENTATION TWidgetStyle : public TStyle 
{
	typedef TStyle inherited;
	
private:
	TPolishEvent FOnPolish;
	void __cdecl PolishHook(Qt::QWidgetH* p1);
	void __fastcall SetOnPolish(const TPolishEvent Value);
	
protected:
	virtual void __fastcall DoPolish(System::TObject* Source);
	virtual void __fastcall SetDefaultStyle(const TDefaultStyle Value);
	
public:
	__property TPolishEvent OnPolish = {read=FOnPolish, write=SetOnPolish};
public:
	#pragma option push -w-inl
	/* TStyle.Create */ inline __fastcall virtual TWidgetStyle(void) : TStyle() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TWidgetStyle(void) { }
	#pragma option pop
	
};


typedef AnsiString QStyle__4[7];

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE AnsiString cStyles[7];

}	/* namespace Qstyle */
using namespace Qstyle;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QStyle
