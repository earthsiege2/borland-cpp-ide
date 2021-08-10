// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Menus.pas' rev: 5.00

#ifndef MenusHPP
#define MenusHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ActnList.hpp>	// Pascal unit
#include <ImgList.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Menus
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EMenuError;
class PASCALIMPLEMENTATION EMenuError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EMenuError(const AnsiString Msg) : Sysutils::Exception(Msg
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EMenuError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EMenuError(int Ident)/* overload */ : Sysutils::Exception(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EMenuError(int Ident, const System::TVarRec * Args, 
		const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EMenuError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(
		Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EMenuError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EMenuError(int Ident, int AHelpContext)/* overload */
		 : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EMenuError(System::PResStringRec ResStringRec, const 
		System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EMenuError(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TMenuBreak { mbNone, mbBreak, mbBarBreak };
#pragma option pop

class DELPHICLASS TMenuItem;
typedef void __fastcall (__closure *TMenuChangeEvent)(System::TObject* Sender, TMenuItem* Source, bool 
	Rebuild);

typedef void __fastcall (__closure *TMenuDrawItemEvent)(System::TObject* Sender, Graphics::TCanvas* 
	ACanvas, const Windows::TRect &ARect, bool Selected);

typedef void __fastcall (__closure *TAdvancedMenuDrawItemEvent)(System::TObject* Sender, Graphics::TCanvas* 
	ACanvas, const Windows::TRect &ARect, Windows::TOwnerDrawState State);

typedef void __fastcall (__closure *TMenuMeasureItemEvent)(System::TObject* Sender, Graphics::TCanvas* 
	ACanvas, int &Width, int &Height);

#pragma option push -b-
enum TMenuItemAutoFlag { maAutomatic, maManual, maParent };
#pragma option pop

typedef TMenuItemAutoFlag TMenuAutoFlag;

class DELPHICLASS TMenuActionLink;
class PASCALIMPLEMENTATION TMenuActionLink : public Actnlist::TActionLink 
{
	typedef Actnlist::TActionLink inherited;
	
protected:
	TMenuItem* FClient;
	virtual void __fastcall AssignClient(System::TObject* AClient);
	virtual bool __fastcall IsCaptionLinked(void);
	virtual bool __fastcall IsCheckedLinked(void);
	virtual bool __fastcall IsEnabledLinked(void);
	virtual bool __fastcall IsHelpContextLinked(void);
	virtual bool __fastcall IsHintLinked(void);
	virtual bool __fastcall IsImageIndexLinked(void);
	virtual bool __fastcall IsShortCutLinked(void);
	virtual bool __fastcall IsVisibleLinked(void);
	virtual bool __fastcall IsOnExecuteLinked(void);
	virtual void __fastcall SetCaption(const AnsiString Value);
	virtual void __fastcall SetChecked(bool Value);
	virtual void __fastcall SetEnabled(bool Value);
	virtual void __fastcall SetHelpContext(Classes::THelpContext Value);
	virtual void __fastcall SetHint(const AnsiString Value);
	virtual void __fastcall SetImageIndex(int Value);
	virtual void __fastcall SetShortCut(Classes::TShortCut Value);
	virtual void __fastcall SetVisible(bool Value);
	virtual void __fastcall SetOnExecute(Classes::TNotifyEvent Value);
public:
	#pragma option push -w-inl
	/* TBasicActionLink.Create */ inline __fastcall virtual TMenuActionLink(System::TObject* AClient) : 
		Actnlist::TActionLink(AClient) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBasicActionLink.Destroy */ inline __fastcall virtual ~TMenuActionLink(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TMenuActionLinkClass;

class DELPHICLASS TMenu;
#pragma option push -b-
enum TFindItemKind { fkCommand, fkHandle, fkShortCut };
#pragma option pop

class PASCALIMPLEMENTATION TMenu : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Classes::TBiDiMode FBiDiMode;
	TMenuItem* FItems;
	HWND FWindowHandle;
	AnsiString FMenuImage;
	bool FOwnerDraw;
	bool FParentBiDiMode;
	Imglist::TChangeLink* FImageChangeLink;
	Imglist::TCustomImageList* FImages;
	TMenuChangeEvent FOnChange;
	void __fastcall SetBiDiMode(Classes::TBiDiMode Value);
	void __fastcall SetOwnerDraw(bool Value);
	void __fastcall SetImages(Imglist::TCustomImageList* Value);
	void __fastcall SetParentBiDiMode(bool Value);
	void __fastcall SetWindowHandle(HWND Value);
	void __fastcall ImageListChange(System::TObject* Sender);
	bool __fastcall IsBiDiModeStored(void);
	bool __fastcall UpdateImage(void);
	TMenuAutoFlag __fastcall GetAutoHotkeys(void);
	void __fastcall SetAutoHotkeys(const TMenuAutoFlag Value);
	TMenuAutoFlag __fastcall GetAutoLineReduction(void);
	void __fastcall SetAutoLineReduction(const TMenuAutoFlag Value);
	
protected:
	void __fastcall AdjustBiDiBehavior(void);
	virtual void __fastcall DoChange(TMenuItem* Source, bool Rebuild);
	void __fastcall DoBiDiModeChanged(void);
	int __fastcall DoGetMenuString(HMENU Menu, unsigned ItemID, char * Str, int MaxCount, unsigned Flag
		);
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	virtual HMENU __fastcall GetHandle(void);
	bool __fastcall IsOwnerDraw(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall MenuChanged(System::TObject* Sender, TMenuItem* Source, bool Rebuild);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	DYNAMIC void __fastcall SetChildOrder(Classes::TComponent* Child, int Order);
	void __fastcall UpdateItems(void);
	__property TMenuChangeEvent OnChange = {read=FOnChange, write=FOnChange};
	
public:
	__fastcall virtual TMenu(Classes::TComponent* AOwner);
	__fastcall virtual ~TMenu(void);
	bool __fastcall DispatchCommand(Word ACommand);
	bool __fastcall DispatchPopup(HMENU AHandle);
	TMenuItem* __fastcall FindItem(int Value, TFindItemKind Kind);
	Classes::THelpContext __fastcall GetHelpContext(int Value, bool ByCommand);
	__property Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	bool __fastcall IsRightToLeft(void);
	DYNAMIC bool __fastcall IsShortCut(Messages::TWMKey &Message);
	void __fastcall ParentBiDiModeChanged(void)/* overload */;
	void __fastcall ParentBiDiModeChanged(System::TObject* AControl)/* overload */;
	void __fastcall ProcessMenuChar(Messages::TWMMenuChar &Message);
	__property TMenuAutoFlag AutoHotkeys = {read=GetAutoHotkeys, write=SetAutoHotkeys, default=0};
	__property TMenuAutoFlag AutoLineReduction = {read=GetAutoLineReduction, write=SetAutoLineReduction
		, default=0};
	__property Classes::TBiDiMode BiDiMode = {read=FBiDiMode, write=SetBiDiMode, stored=IsBiDiModeStored
		, nodefault};
	__property HMENU Handle = {read=GetHandle, nodefault};
	__property bool OwnerDraw = {read=FOwnerDraw, write=SetOwnerDraw, default=0};
	__property bool ParentBiDiMode = {read=FParentBiDiMode, write=SetParentBiDiMode, default=1};
	__property HWND WindowHandle = {read=FWindowHandle, write=SetWindowHandle, nodefault};
	
__published:
	__property TMenuItem* Items = {read=FItems};
};


class PASCALIMPLEMENTATION TMenuItem : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	AnsiString FCaption;
	HMENU FHandle;
	bool FChecked;
	bool FEnabled;
	bool FDefault;
	TMenuItemAutoFlag FAutoHotkeys;
	TMenuItemAutoFlag FAutoLineReduction;
	bool FRadioItem;
	bool FVisible;
	Byte FGroupIndex;
	Imglist::TImageIndex FImageIndex;
	TMenuActionLink* FActionLink;
	TMenuBreak FBreak;
	Graphics::TBitmap* FBitmap;
	Word FCommand;
	Classes::THelpContext FHelpContext;
	AnsiString FHint;
	Classes::TList* FItems;
	Classes::TShortCut FShortCut;
	TMenuItem* FParent;
	TMenuItem* FMerged;
	TMenuItem* FMergedWith;
	TMenu* FMenu;
	bool FStreamedRebuild;
	Imglist::TChangeLink* FImageChangeLink;
	Imglist::TCustomImageList* FSubMenuImages;
	TMenuChangeEvent FOnChange;
	Classes::TNotifyEvent FOnClick;
	TMenuDrawItemEvent FOnDrawItem;
	TAdvancedMenuDrawItemEvent FOnAdvancedDrawItem;
	TMenuMeasureItemEvent FOnMeasureItem;
	void __fastcall AppendTo(HMENU Menu, bool ARightToLeft);
	void __fastcall DoActionChange(System::TObject* Sender);
	void __fastcall ReadShortCutText(Classes::TReader* Reader);
	void __fastcall MergeWith(TMenuItem* Menu);
	void __fastcall RebuildHandle(void);
	void __fastcall PopulateMenu(void);
	void __fastcall SubItemChanged(System::TObject* Sender, TMenuItem* Source, bool Rebuild);
	void __fastcall TurnSiblingsOff(void);
	void __fastcall VerifyGroupIndex(int Position, Byte Value);
	Classes::TBasicAction* __fastcall GetAction(void);
	Graphics::TBitmap* __fastcall GetBitmap(void);
	void __fastcall SetAction(Classes::TBasicAction* Value);
	void __fastcall SetBitmap(Graphics::TBitmap* Value);
	void __fastcall SetSubMenuImages(Imglist::TCustomImageList* Value);
	void __fastcall ImageListChange(System::TObject* Sender);
	void __fastcall InitiateActions(void);
	bool __fastcall IsCaptionStored(void);
	bool __fastcall IsCheckedStored(void);
	bool __fastcall IsEnabledStored(void);
	bool __fastcall IsHelpContextStored(void);
	bool __fastcall IsHintStored(void);
	bool __fastcall IsImageIndexStored(void);
	bool __fastcall IsOnClickStored(void);
	bool __fastcall IsShortCutStored(void);
	bool __fastcall IsVisibleStored(void);
	bool __fastcall InternalRethinkHotkeys(bool ForceRethink);
	void __fastcall SetAutoHotkeys(const TMenuItemAutoFlag Value);
	bool __fastcall InternalRethinkLines(bool ForceRethink);
	void __fastcall SetAutoLineReduction(const TMenuItemAutoFlag Value);
	
protected:
	DYNAMIC void __fastcall ActionChange(System::TObject* Sender, bool CheckDefaults);
	virtual void __fastcall AdvancedDrawItem(Graphics::TCanvas* ACanvas, const Windows::TRect &ARect, Windows::TOwnerDrawState 
		State, bool TopLevel);
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	void __fastcall DoDrawText(Graphics::TCanvas* ACanvas, const AnsiString ACaption, Windows::TRect &Rect
		, bool Selected, int Flags);
	virtual void __fastcall DrawItem(Graphics::TCanvas* ACanvas, const Windows::TRect &ARect, bool Selected
		);
	DYNAMIC TMetaClass* __fastcall GetActionLinkClass(void);
	HMENU __fastcall GetHandle(void);
	int __fastcall GetCount(void);
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	TMenuItem* __fastcall GetItem(int Index);
	int __fastcall GetMenuIndex(void);
	bool __fastcall GetAutoHotkeys(void);
	bool __fastcall GetAutoLineReduction(void);
	int __fastcall InsertNewLine(bool ABefore, TMenuItem* AItem);
	void __fastcall MeasureItem(Graphics::TCanvas* ACanvas, int &Width, int &Height);
	virtual void __fastcall MenuChanged(bool Rebuild);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	void __fastcall SetBreak(TMenuBreak Value);
	void __fastcall SetCaption(const AnsiString Value);
	void __fastcall SetChecked(bool Value);
	DYNAMIC void __fastcall SetChildOrder(Classes::TComponent* Child, int Order);
	void __fastcall SetDefault(bool Value);
	void __fastcall SetEnabled(bool Value);
	void __fastcall SetGroupIndex(Byte Value);
	void __fastcall SetImageIndex(Imglist::TImageIndex Value);
	void __fastcall SetMenuIndex(int Value);
	DYNAMIC void __fastcall SetParentComponent(Classes::TComponent* Value);
	void __fastcall SetRadioItem(bool Value);
	void __fastcall SetShortCut(Classes::TShortCut Value);
	void __fastcall SetVisible(bool Value);
	void __fastcall UpdateItems(void);
	__property TMenuActionLink* ActionLink = {read=FActionLink, write=FActionLink};
	
public:
	__fastcall virtual TMenuItem(Classes::TComponent* AOwner);
	__fastcall virtual ~TMenuItem(void);
	virtual void __fastcall InitiateAction(void);
	HIDESBASE void __fastcall Insert(int Index, TMenuItem* Item);
	void __fastcall Delete(int Index);
	void __fastcall Clear(void);
	virtual void __fastcall Click(void);
	TMenuItem* __fastcall Find(AnsiString ACaption);
	int __fastcall IndexOf(TMenuItem* Item);
	bool __fastcall IsLine(void);
	Imglist::TCustomImageList* __fastcall GetImageList(void);
	DYNAMIC Classes::TComponent* __fastcall GetParentComponent(void);
	TMenu* __fastcall GetParentMenu(void);
	DYNAMIC bool __fastcall HasParent(void);
	int __fastcall NewTopLine(void);
	int __fastcall NewBottomLine(void);
	int __fastcall InsertNewLineBefore(TMenuItem* AItem);
	int __fastcall InsertNewLineAfter(TMenuItem* AItem);
	void __fastcall Add(TMenuItem* Item)/* overload */;
	void __fastcall Add(TMenuItem* const * AItems, const int AItems_Size)/* overload */;
	HIDESBASE void __fastcall Remove(TMenuItem* Item);
	bool __fastcall RethinkHotkeys(void);
	bool __fastcall RethinkLines(void);
	__property Word Command = {read=FCommand, nodefault};
	__property HMENU Handle = {read=GetHandle, nodefault};
	__property int Count = {read=GetCount, nodefault};
	__property TMenuItem* Items[int Index] = {read=GetItem/*, default*/};
	__property int MenuIndex = {read=GetMenuIndex, write=SetMenuIndex, nodefault};
	__property TMenuItem* Parent = {read=FParent};
	
__published:
	__property Classes::TBasicAction* Action = {read=GetAction, write=SetAction};
	__property TMenuItemAutoFlag AutoHotkeys = {read=FAutoHotkeys, write=SetAutoHotkeys, default=2};
	__property TMenuItemAutoFlag AutoLineReduction = {read=FAutoLineReduction, write=SetAutoLineReduction
		, default=2};
	__property Graphics::TBitmap* Bitmap = {read=GetBitmap, write=SetBitmap};
	__property TMenuBreak Break = {read=FBreak, write=SetBreak, default=0};
	__property AnsiString Caption = {read=FCaption, write=SetCaption, stored=IsCaptionStored};
	__property bool Checked = {read=FChecked, write=SetChecked, stored=IsCheckedStored, default=0};
	__property Imglist::TCustomImageList* SubMenuImages = {read=FSubMenuImages, write=SetSubMenuImages}
		;
	__property bool Default = {read=FDefault, write=SetDefault, default=0};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, stored=IsEnabledStored, default=1};
	__property Byte GroupIndex = {read=FGroupIndex, write=SetGroupIndex, default=0};
	__property Classes::THelpContext HelpContext = {read=FHelpContext, write=FHelpContext, stored=IsHelpContextStored
		, default=0};
	__property AnsiString Hint = {read=FHint, write=FHint, stored=IsHintStored};
	__property Imglist::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, stored=IsImageIndexStored
		, default=-1};
	__property bool RadioItem = {read=FRadioItem, write=SetRadioItem, default=0};
	__property Classes::TShortCut ShortCut = {read=FShortCut, write=SetShortCut, stored=IsShortCutStored
		, default=0};
	__property bool Visible = {read=FVisible, write=SetVisible, stored=IsVisibleStored, default=1};
	__property Classes::TNotifyEvent OnClick = {read=FOnClick, write=FOnClick, stored=IsOnClickStored};
		
	__property TMenuDrawItemEvent OnDrawItem = {read=FOnDrawItem, write=FOnDrawItem};
	__property TAdvancedMenuDrawItemEvent OnAdvancedDrawItem = {read=FOnAdvancedDrawItem, write=FOnAdvancedDrawItem
		};
	__property TMenuMeasureItemEvent OnMeasureItem = {read=FOnMeasureItem, write=FOnMeasureItem};
};


class DELPHICLASS TMainMenu;
class PASCALIMPLEMENTATION TMainMenu : public TMenu 
{
	typedef TMenu inherited;
	
private:
	HMENU FOle2Menu;
	bool FAutoMerge;
	void __fastcall ItemChanged(void);
	void __fastcall SetAutoMerge(bool Value);
	
protected:
	virtual void __fastcall MenuChanged(System::TObject* Sender, TMenuItem* Source, bool Rebuild);
	virtual HMENU __fastcall GetHandle(void);
	
public:
	void __fastcall Merge(TMainMenu* Menu);
	void __fastcall Unmerge(TMainMenu* Menu);
	void __fastcall PopulateOle2Menu(HMENU SharedMenu, const int * Groups, const int Groups_Size, int * 
		Widths, const int Widths_Size);
	void __fastcall GetOle2AcceleratorTable(HACCEL &AccelTable, int &AccelCount, const int * Groups, const 
		int Groups_Size);
	void __fastcall SetOle2MenuHandle(HMENU Handle);
	
__published:
	__property AutoHotkeys ;
	__property AutoLineReduction ;
	__property bool AutoMerge = {read=FAutoMerge, write=SetAutoMerge, default=0};
	__property BiDiMode ;
	__property Images ;
	__property OwnerDraw ;
	__property ParentBiDiMode ;
	__property OnChange ;
public:
	#pragma option push -w-inl
	/* TMenu.Create */ inline __fastcall virtual TMainMenu(Classes::TComponent* AOwner) : TMenu(AOwner)
		 { }
	#pragma option pop
	#pragma option push -w-inl
	/* TMenu.Destroy */ inline __fastcall virtual ~TMainMenu(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TPopupAlignment { paLeft, paRight, paCenter };
#pragma option pop

#pragma option push -b-
enum TTrackButton { tbRightButton, tbLeftButton };
#pragma option pop

#pragma option push -b-
enum TMenuAnimations { maLeftToRight, maRightToLeft, maTopToBottom, maBottomToTop, maNone };
#pragma option pop

typedef Set<TMenuAnimations, maLeftToRight, maNone>  TMenuAnimation;

class DELPHICLASS TPopupMenu;
class PASCALIMPLEMENTATION TPopupMenu : public TMenu 
{
	typedef TMenu inherited;
	
private:
	Windows::TPoint FPopupPoint;
	TPopupAlignment FAlignment;
	bool FAutoPopup;
	Classes::TComponent* FPopupComponent;
	TTrackButton FTrackButton;
	TMenuAnimation FMenuAnimation;
	Classes::TNotifyEvent FOnPopup;
	HIDESBASE Classes::THelpContext __fastcall GetHelpContext(void);
	void __fastcall SetHelpContext(Classes::THelpContext Value);
	void __fastcall SetBiDiModeFromPopupControl(void);
	
protected:
	bool __fastcall UseRightToLeftAlignment(void);
	virtual void __fastcall DoPopup(System::TObject* Sender);
	__property Windows::TPoint PopupPoint = {read=FPopupPoint};
	
public:
	__fastcall virtual TPopupMenu(Classes::TComponent* AOwner);
	__fastcall virtual ~TPopupMenu(void);
	virtual void __fastcall Popup(int X, int Y);
	__property Classes::TComponent* PopupComponent = {read=FPopupComponent, write=FPopupComponent};
	
__published:
	__property TPopupAlignment Alignment = {read=FAlignment, write=FAlignment, default=0};
	__property AutoHotkeys ;
	__property AutoLineReduction ;
	__property bool AutoPopup = {read=FAutoPopup, write=FAutoPopup, default=1};
	__property BiDiMode ;
	__property Classes::THelpContext HelpContext = {read=GetHelpContext, write=SetHelpContext, default=0
		};
	__property Images ;
	__property TMenuAnimation MenuAnimation = {read=FMenuAnimation, write=FMenuAnimation, default=0};
	__property OwnerDraw ;
	__property ParentBiDiMode ;
	__property TTrackButton TrackButton = {read=FTrackButton, write=FTrackButton, default=0};
	__property OnChange ;
	__property Classes::TNotifyEvent OnPopup = {read=FOnPopup, write=FOnPopup};
};


class DELPHICLASS TPopupList;
class PASCALIMPLEMENTATION TPopupList : public Classes::TList 
{
	typedef Classes::TList inherited;
	
protected:
	HWND FWindow;
	void __fastcall MainWndProc(Messages::TMessage &Message);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	
public:
	__property HWND Window = {read=FWindow, nodefault};
	HIDESBASE void __fastcall Add(TPopupMenu* Popup);
	HIDESBASE void __fastcall Remove(TPopupMenu* Popup);
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TPopupList(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TPopupList(void) : Classes::TList() { }
	#pragma option pop
	
};


typedef TMenuItem* *PMenuItem;

class DELPHICLASS TMenuItemStack;
class PASCALIMPLEMENTATION TMenuItemStack : public Contnrs::TStack 
{
	typedef Contnrs::TStack inherited;
	
public:
	void __fastcall ClearItem(TMenuItem* AItem);
public:
	#pragma option push -w-inl
	/* TOrderedList.Create */ inline __fastcall TMenuItemStack(void) : Contnrs::TStack() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TOrderedList.Destroy */ inline __fastcall virtual ~TMenuItemStack(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TPopupList* PopupList;
extern PACKAGE TMenuItemStack* ShortCutItems;
extern PACKAGE AnsiString ValidMenuHotkeys;
static const char cHotkeyPrefix = '\x26';
static const char cLineCaption = '\x2d';
#define cDialogSuffix "..."
extern PACKAGE Classes::TShortCut __fastcall ShortCut(Word Key, Classes::TShiftState Shift);
extern PACKAGE void __fastcall ShortCutToKey(Classes::TShortCut ShortCut, Word &Key, Classes::TShiftState 
	&Shift);
extern PACKAGE AnsiString __fastcall ShortCutToText(Classes::TShortCut ShortCut);
extern PACKAGE Classes::TShortCut __fastcall TextToShortCut(AnsiString Text);
extern PACKAGE TMainMenu* __fastcall NewMenu(Classes::TComponent* Owner, const AnsiString AName, TMenuItem* 
	const * Items, const int Items_Size);
extern PACKAGE TPopupMenu* __fastcall NewPopupMenu(Classes::TComponent* Owner, const AnsiString AName
	, TPopupAlignment Alignment, bool AutoPopup, TMenuItem* const * Items, const int Items_Size);
extern PACKAGE TMenuItem* __fastcall NewSubMenu(const AnsiString ACaption, Word hCtx, const AnsiString 
	AName, TMenuItem* const * Items, const int Items_Size, bool AEnabled);
extern PACKAGE TMenuItem* __fastcall NewItem(const AnsiString ACaption, Classes::TShortCut AShortCut
	, bool AChecked, bool AEnabled, Classes::TNotifyEvent AOnClick, Word hCtx, const AnsiString AName);
	
extern PACKAGE TMenuItem* __fastcall NewLine(void);
extern PACKAGE void __fastcall DrawMenuItem(TMenuItem* MenuItem, Graphics::TCanvas* ACanvas, const Windows::TRect 
	&ARect, Windows::TOwnerDrawState State);
extern PACKAGE AnsiString __fastcall StripHotkey(const AnsiString Text);
extern PACKAGE AnsiString __fastcall GetHotkey(const AnsiString Text);
extern PACKAGE bool __fastcall AnsiSameCaption(const AnsiString Text1, const AnsiString Text2);

}	/* namespace Menus */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Menus;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Menus
