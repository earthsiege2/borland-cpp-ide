// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QMenus.pas' rev: 6.00

#ifndef QMenusHPP
#define QMenusHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QImgList.hpp>	// Pascal unit
#include <QActnList.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <QGraphics.hpp>	// Pascal unit
#include <Qt.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <QTypes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qmenus
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EMenuError;
class PASCALIMPLEMENTATION EMenuError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EMenuError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EMenuError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EMenuError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EMenuError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EMenuError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EMenuError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EMenuError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EMenuError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EMenuError(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMenuActionLink;
class DELPHICLASS TMenuItem;
#pragma option push -b-
enum TMenuItemAutoFlag { maAutomatic, maManual, maParent };
#pragma option pop

class DELPHICLASS TMenu;
typedef void __fastcall (__closure *TMenuChangeEvent)(System::TObject* Sender, TMenuItem* Source, bool Rebuild);

typedef TMenuItemAutoFlag TMenuAutoFlag;

#pragma option push -b-
enum TFindItemKind { fkID, fkHandle, fkShortCut };
#pragma option pop

class PASCALIMPLEMENTATION TMenu : public Qtypes::THandleComponent 
{
	typedef Qtypes::THandleComponent inherited;
	
private:
	TMenuChangeEvent FOnChange;
	TMenuItem* FItems;
	Qgraphics::TWidgetPalette* FPalette;
	Qgraphics::TColor FColor;
	Qimglist::TCustomImageList* FImages;
	Qimglist::TChangeLink* FImageChangeLink;
	void __cdecl ActivatedHook(int ItemID);
	void __fastcall ImageListChange(System::TObject* Sender);
	virtual void __cdecl HighlightedHook(int ItemID);
	void __fastcall SetColor(const Qgraphics::TColor Value);
	void __fastcall SetImages(const Qimglist::TCustomImageList* Value);
	void __fastcall UpdateItemImages(void);
	TMenuAutoFlag __fastcall GetAutoHotkeys(void);
	void __fastcall SetAutoHotkeys(const TMenuAutoFlag Value);
	bool __fastcall IsBitmapStored(void);
	Qgraphics::TBitmap* __fastcall GetBitmap(void);
	
protected:
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall MenuChanged(System::TObject* Sender, TMenuItem* Source, bool Rebuild);
	virtual Qt::QMenuDataH* __fastcall MenuDataHandle(void) = 0 ;
	virtual void __fastcall DoChange(TMenuItem* Source, bool Rebuild);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall PaletteChanged(System::TObject* Sender);
	virtual void __fastcall SetBitmap(Qgraphics::TBitmap* Value);
	DYNAMIC void __fastcall SetChildOrder(Classes::TComponent* Child, int Order);
	__property TMenuAutoFlag AutoHotkeys = {read=GetAutoHotkeys, write=SetAutoHotkeys, default=0};
	__property Qgraphics::TBitmap* Bitmap = {read=GetBitmap, write=SetBitmap, stored=IsBitmapStored};
	__property Qgraphics::TColor Color = {read=FColor, write=SetColor, default=-2};
	__property TMenuChangeEvent OnChange = {read=FOnChange, write=FOnChange};
	
public:
	__fastcall virtual TMenu(Classes::TComponent* AOwner);
	__fastcall virtual ~TMenu(void);
	TMenuItem* __fastcall FindItem(int Value, TFindItemKind Kind);
	virtual bool __fastcall IsShortCut(int Key, Classes::TShiftState Shift, const WideString KeyText);
	void __fastcall SetForm(System::TObject* Value);
	__property Qimglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	
__published:
	__property TMenuItem* Items = {read=FItems};
};


typedef TMetaClass*TMenuActionLinkClass;

class PASCALIMPLEMENTATION TMenuItem : public Qtypes::THandleComponent 
{
	typedef Qtypes::THandleComponent inherited;
	
public:
	TMenuItem* operator[](int Index) { return Items[Index]; }
	
private:
	TMenuActionLink* FActionLink;
	TMenuItemAutoFlag FAutoHotkeys;
	bool FVisible;
	bool FRadioItem;
	bool FChecked;
	bool FEnabled;
	Byte FGroupIndex;
	int FID;
	Classes::TList* FItems;
	Qgraphics::TBitmap* FBitmap;
	WideString FCaption;
	WideString FHint;
	TMenu* FMenu;
	Qt::QMenuDataH* FMenuData;
	TMenuItem* FMerged;
	TMenuItem* FMergedWith;
	TMenuChangeEvent FOnChange;
	TMenuItem* FParent;
	Classes::TNotifyEvent FOnClick;
	Classes::TNotifyEvent FOnHighlighted;
	Classes::TNotifyEvent FOnShow;
	Classes::TShortCut FShortCut;
	Qimglist::TImageIndex FImageIndex;
	TMenuItem* FCurrentItem;
	Qt::QMenuItemH* FMenuItemHandle;
	void __cdecl ActivatedHook(int ItemID);
	void __fastcall DoActionChange(System::TObject* Sender);
	void __fastcall DoSetImageIndex(const int Value);
	Classes::TBasicAction* __fastcall GetAction(void);
	void __fastcall SetAction(Classes::TBasicAction* Value);
	int __fastcall GetCount(void);
	TMenuItem* __fastcall GetItem(int Index);
	int __fastcall GetMenuIndex(void);
	void __cdecl HighlightedHook(int ItemID);
	void __fastcall ItemHandleNeeded(void);
	void __fastcall MergeWith(TMenuItem* Menu);
	void __fastcall RebuildMenu(void);
	void __fastcall RemoveItemHandle(void);
	void __fastcall SetBitmap(const Qgraphics::TBitmap* Value);
	void __fastcall SetCaption(const WideString Value);
	void __fastcall SetChecked(const bool Value);
	void __fastcall SetEnabled(const bool Value);
	void __fastcall SetGroupIndex(const Byte Value);
	void __fastcall SetMenuIndex(int Value);
	void __fastcall SetRadioItem(const bool Value);
	void __fastcall SetShortCut(const Classes::TShortCut Value);
	void __fastcall SetVisible(const bool Value);
	void __cdecl ShowHook(void);
	void __fastcall SubItemChanged(System::TObject* Sender, TMenuItem* Source, bool Rebuild);
	int __fastcall VisibleCount(void);
	void __fastcall TurnSiblingsOff(void);
	void __fastcall VerifyGroupIndex(int Position, Byte Value);
	HIDESBASE Qt::QPopupMenuH* __fastcall GetHandle(void);
	void __fastcall InitiateActions(void);
	void __fastcall SetImageIndex(const Qimglist::TImageIndex Value);
	void __fastcall ChangePixmap(Qt::QPixmapH* Value);
	bool __fastcall IsBitmapStored(void);
	bool __fastcall IsCaptionStored(void);
	bool __fastcall IsCheckedStored(void);
	bool __fastcall IsEnabledStored(void);
	HIDESBASE bool __fastcall IsHelpContextStored(void);
	bool __fastcall IsHintStored(void);
	bool __fastcall IsImageIndexStored(void);
	bool __fastcall IsOnClickStored(void);
	bool __fastcall IsShortCutStored(void);
	bool __fastcall IsVisibleStored(void);
	void __fastcall UpdateItems(void);
	bool __fastcall InternalRethinkHotkeys(bool ForceRethink);
	void __fastcall RemoveQtItemFromParent(void);
	void __fastcall SetAutoHotkeys(const TMenuItemAutoFlag Value);
	bool __fastcall GetAutoHotkeys(void);
	
protected:
	DYNAMIC void __fastcall ActionChange(System::TObject* Sender, bool CheckDefaults);
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	void __fastcall BitmapChanged(System::TObject* Sender);
	TMenuItem* __fastcall FindItem(int ItemID);
	DYNAMIC TMetaClass* __fastcall GetActionLinkClass(void);
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall CreateWidget(void);
	virtual void __fastcall DestroyWidget(void);
	Qgraphics::TBitmap* __fastcall GetBitmap(void);
	Qimglist::TCustomImageList* __fastcall GetImageList(void);
	Qt::QMenuItemH* __fastcall MenuItemHandle(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall Highlighted(void);
	virtual void __fastcall HookEvents(void);
	virtual void __fastcall InvokeHelp(void);
	int __fastcall InsertNewLine(bool ABefore, TMenuItem* AItem);
	virtual void __fastcall MenuChanged(bool Rebuild);
	DYNAMIC void __fastcall SetChildOrder(Classes::TComponent* Child, int Order);
	DYNAMIC void __fastcall SetParentComponent(Classes::TComponent* Value);
	DYNAMIC void __fastcall Show(void);
	bool __fastcall Showing(void);
	bool __fastcall DisplayBitmap(void);
	virtual void __fastcall WidgetDestroyed(void);
	__property TMenuActionLink* ActionLink = {read=FActionLink, write=FActionLink};
	
public:
	__fastcall virtual TMenuItem(Classes::TComponent* AOwner);
	__fastcall virtual ~TMenuItem(void);
	virtual void __fastcall InitiateAction(void);
	void __fastcall Add(TMenuItem* Item)/* overload */;
	void __fastcall Add(const TMenuItem* * AItems, const int AItems_Size)/* overload */;
	void __fastcall Clear(void);
	virtual void __fastcall Click(void);
	void __fastcall Delete(int Index);
	TMenuItem* __fastcall Find(const WideString ACaption)/* overload */;
	TMenuItem* __fastcall Find(Qt::QMenuItemH* AHandle)/* overload */;
	DYNAMIC Classes::TComponent* __fastcall GetParentComponent(void);
	TMenu* __fastcall GetParentMenu(void);
	bool __fastcall HasBitmap(void);
	DYNAMIC bool __fastcall HasParent(void);
	int __fastcall IndexOf(TMenuItem* Item);
	Qt::QMenuDataH* __fastcall MenuData(void);
	HIDESBASE void __fastcall Insert(int Index, TMenuItem* Item);
	int __fastcall InsertNewLineBefore(TMenuItem* AItem);
	int __fastcall InsertNewLineAfter(TMenuItem* AItem);
	bool __fastcall IsLine(void);
	HIDESBASE void __fastcall Remove(TMenuItem* Item);
	bool __fastcall RethinkHotkeys(void);
	__property int ID = {read=FID, nodefault};
	__property int Count = {read=GetCount, nodefault};
	__property Qt::QPopupMenuH* Handle = {read=GetHandle};
	__property TMenuItem* Items[int Index] = {read=GetItem/*, default*/};
	__property int MenuIndex = {read=GetMenuIndex, write=SetMenuIndex, nodefault};
	__property TMenuItem* Parent = {read=FParent};
	
__published:
	__property Classes::TBasicAction* Action = {read=GetAction, write=SetAction};
	__property TMenuItemAutoFlag AutoHotkeys = {read=FAutoHotkeys, write=SetAutoHotkeys, default=2};
	__property Qgraphics::TBitmap* Bitmap = {read=GetBitmap, write=SetBitmap, stored=IsBitmapStored};
	__property WideString Caption = {read=FCaption, write=SetCaption, stored=IsCaptionStored};
	__property bool Checked = {read=FChecked, write=SetChecked, stored=IsCheckedStored, default=0};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, stored=IsEnabledStored, default=1};
	__property Byte GroupIndex = {read=FGroupIndex, write=SetGroupIndex, default=0};
	__property WideString Hint = {read=FHint, write=FHint, stored=IsHintStored};
	__property Qimglist::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, stored=IsImageIndexStored, default=-1};
	__property bool RadioItem = {read=FRadioItem, write=SetRadioItem, default=0};
	__property Classes::TShortCut ShortCut = {read=FShortCut, write=SetShortCut, stored=IsShortCutStored, default=0};
	__property bool Visible = {read=FVisible, write=SetVisible, stored=IsVisibleStored, default=1};
	__property Classes::TNotifyEvent OnClick = {read=FOnClick, write=FOnClick, stored=IsOnClickStored};
	__property Classes::TNotifyEvent OnHighlighted = {read=FOnHighlighted, write=FOnHighlighted};
	__property Classes::TNotifyEvent OnShow = {read=FOnShow, write=FOnShow};
	__property HelpKeyword  = {stored=IsHelpContextStored};
	__property HelpType  = {stored=IsHelpContextStored, default=0};
	__property HelpContext  = {stored=IsHelpContextStored, default=0};
};


class PASCALIMPLEMENTATION TMenuActionLink : public Qactnlist::TActionLink 
{
	typedef Qactnlist::TActionLink inherited;
	
protected:
	TMenuItem* FClient;
	virtual void __fastcall AssignClient(System::TObject* AClient);
	virtual bool __fastcall IsCaptionLinked(void);
	virtual bool __fastcall IsCheckedLinked(void);
	virtual bool __fastcall IsEnabledLinked(void);
	virtual bool __fastcall IsHelpLinked(void);
	virtual bool __fastcall IsHintLinked(void);
	virtual bool __fastcall IsImageIndexLinked(void);
	virtual bool __fastcall IsShortCutLinked(void);
	virtual bool __fastcall IsVisibleLinked(void);
	virtual bool __fastcall IsOnExecuteLinked(void);
	virtual void __fastcall SetCaption(const WideString Value);
	virtual void __fastcall SetChecked(bool Value);
	virtual void __fastcall SetEnabled(bool Value);
	virtual void __fastcall SetHelpContext(Classes::THelpContext Value);
	virtual void __fastcall SetHelpKeyword(const AnsiString Value);
	virtual void __fastcall SetHelpType(Classes::THelpType Value);
	virtual void __fastcall SetHint(const WideString Value);
	virtual void __fastcall SetImageIndex(int Value);
	virtual void __fastcall SetShortCut(Classes::TShortCut Value);
	virtual void __fastcall SetVisible(bool Value);
	virtual void __fastcall SetOnExecute(Classes::TNotifyEvent Value);
public:
	#pragma option push -w-inl
	/* TBasicActionLink.Create */ inline __fastcall virtual TMenuActionLink(System::TObject* AClient) : Qactnlist::TActionLink(AClient) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBasicActionLink.Destroy */ inline __fastcall virtual ~TMenuActionLink(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMainMenu;
class PASCALIMPLEMENTATION TMainMenu : public TMenu 
{
	typedef TMenu inherited;
	
private:
	bool FAutoMerge;
	HIDESBASE Qt::QMenuBarH* __fastcall GetHandle(void);
	void __fastcall ItemChanged(void);
	void __fastcall SetAutoMerge(const bool Value);
	
protected:
	virtual void __fastcall CreateWidget(void);
	virtual void __fastcall HookEvents(void);
	virtual void __fastcall MenuChanged(System::TObject* Sender, TMenuItem* Source, bool Rebuild);
	virtual Qt::QMenuDataH* __fastcall MenuDataHandle(void);
	
public:
	__property Qt::QMenuBarH* Handle = {read=GetHandle};
	virtual bool __fastcall IsShortCut(int Key, Classes::TShiftState Shift, const WideString KeyText);
	void __fastcall Merge(TMainMenu* Menu);
	void __fastcall Unmerge(TMainMenu* Menu);
	
__published:
	__property AutoHotkeys  = {default=0};
	__property bool AutoMerge = {read=FAutoMerge, write=SetAutoMerge, default=0};
	__property Color  = {default=-2};
	__property Bitmap ;
	__property Images ;
	__property OnChange ;
	__property HelpType  = {default=0};
	__property HelpKeyword ;
	__property HelpContext  = {default=0};
public:
	#pragma option push -w-inl
	/* TMenu.Create */ inline __fastcall virtual TMainMenu(Classes::TComponent* AOwner) : TMenu(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TMenu.Destroy */ inline __fastcall virtual ~TMainMenu(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TPopupAlignment { paLeft, paRight, paCenter };
#pragma option pop

class DELPHICLASS TPopupMenu;
class PASCALIMPLEMENTATION TPopupMenu : public TMenu 
{
	typedef TMenu inherited;
	
private:
	#pragma pack(push, 1)
	Types::TPoint FPopupPoint;
	#pragma pack(pop)
	
	TPopupAlignment FAlignment;
	bool FAutoPopup;
	Classes::TComponent* FPopupComponent;
	TMenuItem* FCurrentItem;
	Classes::TNotifyEvent FOnPopup;
	HIDESBASE Qt::QPopupMenuH* __fastcall GetHandle(void);
	virtual void __cdecl HighlightedHook(int ItemID);
	void __cdecl ShowHook(void);
	
protected:
	virtual Qt::QMenuDataH* __fastcall MenuDataHandle(void);
	virtual void __fastcall CreateWidget(void);
	virtual void __fastcall DoPopup(System::TObject* Sender);
	virtual void __fastcall HookEvents(void);
	virtual void __fastcall InvokeHelp(void);
	
public:
	__fastcall virtual TPopupMenu(Classes::TComponent* AOwner);
	virtual void __fastcall Popup(int X, int Y);
	__property Classes::TComponent* PopupComponent = {read=FPopupComponent, write=FPopupComponent};
	__property Qt::QPopupMenuH* Handle = {read=GetHandle};
	
__published:
	__property TPopupAlignment Alignment = {read=FAlignment, write=FAlignment, default=0};
	__property AutoHotkeys  = {default=0};
	__property bool AutoPopup = {read=FAutoPopup, write=FAutoPopup, default=1};
	__property Color  = {default=-2};
	__property Bitmap ;
	__property HelpContext  = {default=0};
	__property HelpKeyword ;
	__property HelpType  = {default=0};
	__property Images ;
	__property OnChange ;
	__property Classes::TNotifyEvent OnPopup = {read=FOnPopup, write=FOnPopup};
public:
	#pragma option push -w-inl
	/* TMenu.Destroy */ inline __fastcall virtual ~TPopupMenu(void) { }
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
static const Word ShortCutKeyMask = 0xffff;
static const Word KeyMask = 0x1fff;
static const Shortint midSeparator = 0xffffffff;
static const Shortint midInvisible = 0x0;
#define QEventType_MenuClick (Qt::QEventType)(1064)
static const char cHotkeyPrefix = '\x26';
static const char cLineCaption = '\x2d';
#define cDialogSuffix "..."
extern PACKAGE AnsiString ValidMenuHotkeys;
extern PACKAGE TMenuItemStack* ShortCutItems;
extern PACKAGE WideString __fastcall StripHotkey(const WideString Text);
extern PACKAGE WideString __fastcall GetHotkey(const WideString Text);
extern PACKAGE bool __fastcall AnsiSameCaption(const AnsiString Text1, const AnsiString Text2);
extern PACKAGE bool __fastcall WideSameCaption(const WideString Text1, const WideString Text2);
extern PACKAGE TMainMenu* __fastcall NewMenu(Classes::TComponent* Owner, const AnsiString AName, const TMenuItem* * Items, const int Items_Size);
extern PACKAGE TPopupMenu* __fastcall NewPopupMenu(Classes::TComponent* Owner, const AnsiString AName, TPopupAlignment Alignment, bool AutoPopup, const TMenuItem* * Items, const int Items_Size);
extern PACKAGE TMenuItem* __fastcall NewSubMenu(const WideString ACaption, Classes::THelpContext hCtx, const AnsiString AName, const TMenuItem* * Items, const int Items_Size, bool AEnabled = true);
extern PACKAGE TMenuItem* __fastcall NewItem(const WideString ACaption, Classes::TShortCut AShortCut, bool AChecked, bool AEnabled, Classes::TNotifyEvent AOnClick, Classes::THelpContext hCtx, const AnsiString AName);
extern PACKAGE TMenuItem* __fastcall NewLine(void);
extern PACKAGE Classes::TShortCut __fastcall ShortCut(Word Key, Classes::TShiftState Shift);
extern PACKAGE void __fastcall ShortCutToKey(Classes::TShortCut ShortCut, Word &Key, Classes::TShiftState &Shift);
extern PACKAGE WideString __fastcall ShortCutToText(Classes::TShortCut ShortCut);
extern PACKAGE Classes::TShortCut __fastcall TextToShortCut(const AnsiString AText);

}	/* namespace Qmenus */
using namespace Qmenus;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QMenus
