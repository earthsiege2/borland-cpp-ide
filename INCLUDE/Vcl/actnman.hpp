// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ActnMan.pas' rev: 6.00

#ifndef ActnManHPP
#define ActnManHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Buttons.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <ImgList.hpp>	// Pascal unit
#include <ToolWin.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <ActnList.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#pragma link "dclact.lib"

namespace Actnman
{
//-- type declarations -------------------------------------------------------
typedef TMetaClass*TActionClientItemClass;

typedef TMetaClass*TActionClientsClass;

typedef TMetaClass*TActionBarsClass;

typedef TMetaClass*TActionBarItemClass;

class DELPHICLASS TCustomActionManager;
class DELPHICLASS TActionBars;
class DELPHICLASS TActionClientsCollection;
class DELPHICLASS TActionClient;
class DELPHICLASS TCustomActionBar;
#pragma option push -b-
enum TBarOrientation { boLeftToRight, boRightToLeft, boTopToBottom, boBottomToTop };
#pragma option pop

class DELPHICLASS TCustomActionControl;
typedef void __fastcall (__closure *TControlCreatedEvent)(System::TObject* Sender, TCustomActionControl* &Control);

typedef TMetaClass*TCustomActionControlClass;

typedef void __fastcall (__closure *TGetControlClassEvent)(TCustomActionBar* Sender, TActionClient* AnItem, TMetaClass* &ControlClass);

class DELPHICLASS TActionClients;
class DELPHICLASS TActionClientItem;
class DELPHICLASS TCategoryDragObject;
class DELPHICLASS TActionDragObject;
#pragma option push -b-
enum TBarEdge { beLeft, beRight, beEither };
#pragma option pop

class PASCALIMPLEMENTATION TCustomActionBar : public Toolwin::TToolWindow 
{
	typedef Toolwin::TToolWindow inherited;
	
private:
	TActionClient* FActionClient;
	TCustomActionManager* FActionManager;
	bool FAllowHiding;
	Graphics::TCanvas* FCanvas;
	bool FDesignMode;
	bool FEnabledState;
	TBarOrientation FOrientation;
	int FSpacing;
	TControlCreatedEvent FOnControlCreated;
	TGetControlClassEvent FOnGetControlClass;
	Classes::TNotifyEvent FOnPaint;
	bool FPersistentHotKeys;
	int FHRowCount;
	int FVRowCount;
	int FVertMargin;
	int FHorzMargin;
	bool FHorzSeparator;
	#pragma pack(push, 1)
	Types::TPoint FSavedSize;
	#pragma pack(pop)
	
	bool FVertSeparator;
	int FTallest;
	int FWidest;
	bool FContextBar;
	void __fastcall SetActionManager(const TCustomActionManager* Value);
	void __fastcall SetHorzMargin(const int Value);
	void __fastcall SetHorzSeparator(const bool Value);
	void __fastcall SetSpacing(const int Value);
	void __fastcall SetVertMargin(const int Value);
	void __fastcall SetVertSeparator(const bool Value);
	HIDESBASE MESSAGE void __fastcall CMEnabledchanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMResetBar(Messages::TMessage &Message);
	TActionClients* __fastcall GetItems(void);
	HIDESBASE MESSAGE void __fastcall WMContextMenu(Messages::TWMContextMenu &Message);
	bool __fastcall GetAutoSizing(void);
	
protected:
	bool FSavedWrapState;
	virtual void __fastcall AlignControls(Controls::TControl* AControl, Types::TRect &Rect);
	virtual void __fastcall AutoSizingChanged(void);
	Types::TPoint __fastcall BackgroundSize();
	virtual void __fastcall Clear(void);
	int __fastcall CalcInsertPosition(TCustomActionControl* Control, int X, int Y);
	virtual TCustomActionControl* __fastcall CreateControl(TActionClientItem* AnItem);
	virtual void __fastcall CreateControls(void);
	virtual bool __fastcall CustomAlignInsertBefore(Controls::TControl* C1, Controls::TControl* C2);
	virtual void __fastcall CustomAlignPosition(Controls::TControl* Control, int &NewLeft, int &NewTop, int &NewWidth, int &NewHeight, Types::TRect &AlignRect, const Controls::TAlignInfo &AlignInfo);
	DYNAMIC TMetaClass* __fastcall DoGetControlClass(TActionClientItem* AnItem);
	virtual void __fastcall DoControlCreated(TCustomActionControl* Control);
	virtual void __fastcall DoDropCategory(TCategoryDragObject* Source, const int X, const int Y);
	virtual void __fastcall DoDropActions(TActionDragObject* Source, const int X, const int Y);
	DYNAMIC void __fastcall DragOver(System::TObject* Source, int X, int Y, Controls::TDragState State, bool &Accept);
	virtual TActionClientItem* __fastcall FindLast(void);
	TActionClientItem* __fastcall FindAccelItem(const Word Accel);
	TCustomActionControl* __fastcall FindItemAt(const Types::TPoint &P);
	TCustomActionControl* __fastcall FindItemCaption(const AnsiString ACaption);
	TCustomActionControl* __fastcall FindNearestControl(const Types::TPoint &Point);
	TActionClientItem* __fastcall FindNextVisibleItem(TActionClientItem* AClient);
	TActionClientItem* __fastcall FindPreviousVisibleItem(TActionClientItem* AClient);
	TActionClientItem* __fastcall FindLeastUsedItem(const bool Visible = true);
	virtual TActionClientItem* __fastcall FindNext(TActionClientItem* AClient, const bool Wrap = true);
	virtual TActionClientItem* __fastcall FindPrevious(TActionClientItem* AClient, const bool Wrap = true);
	int __fastcall GetBannerWidth(TBarEdge BarEdge);
	virtual int __fastcall GetBarHeight(void);
	virtual int __fastcall GetBarWidth(void);
	virtual bool __fastcall GetDesignMode(void);
	virtual TCustomActionControl* __fastcall GetActionControl(const int Index);
	virtual TMetaClass* __fastcall GetControlClass(TActionClientItem* AnItem);
	bool __fastcall HasItems(void);
	virtual int __fastcall ItemCount(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall DrawBackground(void);
	virtual void __fastcall Paint(void);
	virtual void __fastcall PaintWindow(HDC DC);
	virtual void __fastcall Reset(void);
	DYNAMIC void __fastcall Resize(void);
	virtual void __fastcall SetActionClient(const TActionClient* Value);
	virtual void __fastcall SetAutoSizing(const bool Value);
	virtual void __fastcall SetDesignMode(const bool Value);
	virtual void __fastcall SetOrientation(const TBarOrientation Value);
	virtual void __fastcall SetPersistentHotKeys(const bool Value);
	virtual void __fastcall SetBiDiMode(Classes::TBiDiMode Value);
	DYNAMIC void __fastcall VisibleChanging(void);
	__property Graphics::TCanvas* Canvas = {read=FCanvas};
	__property int HRowCount = {read=FHRowCount, nodefault};
	__property TActionClients* Items = {read=GetItems};
	__property bool PersistentHotKeys = {read=FPersistentHotKeys, write=SetPersistentHotKeys, nodefault};
	__property int VRowCount = {read=FVRowCount, nodefault};
	
public:
	__fastcall virtual TCustomActionBar(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomActionBar(void);
	DYNAMIC void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	virtual TActionClientItem* __fastcall FindFirst(void);
	TActionClientItem* __fastcall FindFirstVisibleItem(void);
	TActionClientItem* __fastcall FindLastVisibleItem(void);
	__property TCustomActionManager* ActionManager = {read=FActionManager, write=SetActionManager};
	__property TActionClient* ActionClient = {read=FActionClient, write=SetActionClient};
	__property bool AllowHiding = {read=FAllowHiding, write=FAllowHiding, nodefault};
	__property bool AutoSizing = {read=GetAutoSizing, write=SetAutoSizing, nodefault};
	__property Caption ;
	__property Color  = {default=-2147483643};
	__property bool ContextBar = {read=FContextBar, write=FContextBar, nodefault};
	__property bool DesignMode = {read=GetDesignMode, write=SetDesignMode, nodefault};
	__property int HorzMargin = {read=FHorzMargin, write=SetHorzMargin, default=1};
	__property bool HorzSeparator = {read=FHorzSeparator, write=SetHorzSeparator, nodefault};
	__property TBarOrientation Orientation = {read=FOrientation, write=SetOrientation, nodefault};
	__property TCustomActionControl* ActionControls[int Index] = {read=GetActionControl};
	__property int Spacing = {read=FSpacing, write=SetSpacing, nodefault};
	__property int VertMargin = {read=FVertMargin, write=SetVertMargin, default=1};
	__property bool VertSeparator = {read=FVertSeparator, write=SetVertSeparator, nodefault};
	__property TControlCreatedEvent OnControlCreated = {read=FOnControlCreated, write=FOnControlCreated};
	__property TGetControlClassEvent OnGetControlClass = {read=FOnGetControlClass, write=FOnGetControlClass};
	__property Classes::TNotifyEvent OnPaint = {read=FOnPaint, write=FOnPaint};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomActionBar(HWND ParentWindow) : Toolwin::TToolWindow(ParentWindow) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TBackgroundLayout { blNormal, blStretch, blTile, blLeftBanner, blRightBanner };
#pragma option pop

#pragma option push -b-
enum TChangesAllowed { caModify, caMove, caDelete };
#pragma option pop

typedef Set<TChangesAllowed, caModify, caDelete>  TChangesAllowedSet;

class PASCALIMPLEMENTATION TActionClient : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	TCustomActionBar* FActionBar;
	Graphics::TPicture* FBackground;
	TBackgroundLayout FBackgroundLayout;
	TCustomActionBar* FChildActionBar;
	TActionClients* FContextItems;
	AnsiString FCaption;
	Graphics::TColor FColor;
	bool FSmallIcons;
	TActionClients* FItems;
	bool FVisible;
	TChangesAllowedSet FChangesAllowed;
	TActionClients* __fastcall GetContextItems(void);
	void __fastcall SetActionBar(const TCustomActionBar* Value);
	void __fastcall SetItems(const TActionClients* Value);
	void __fastcall SetBackground(const Graphics::TPicture* Value);
	void __fastcall SetBackgroundLayout(const TBackgroundLayout Value);
	void __fastcall SetContextItems(const TActionClients* Value);
	bool __fastcall IsBackgroundStored(void);
	bool __fastcall AreContextItemsStored(void);
	Graphics::TPicture* __fastcall GetBackground(void);
	TActionClients* __fastcall GetItems(void);
	bool __fastcall IsItemsStored(void);
	bool __fastcall GetHasItems(void);
	TActionClientsCollection* __fastcall GetOwningCollection(void);
	
protected:
	void __fastcall ClearActionBar(void);
	virtual void __fastcall ColorChanged(void);
	void __fastcall FreeChildren(void);
	bool __fastcall HasVisibleItems(void);
	bool __fastcall IsChildItem(TActionClient* AClient);
	virtual void __fastcall SetChangesAllowed(const TChangesAllowedSet Value);
	virtual void __fastcall SetColor(const Graphics::TColor Value);
	virtual void __fastcall SetVisible(const bool Value);
	__property TActionClientsCollection* OwningCollection = {read=GetOwningCollection};
	
public:
	__fastcall virtual TActionClient(Classes::TCollection* Collection);
	__fastcall virtual ~TActionClient(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	bool __fastcall HasBackground(void);
	virtual void __fastcall Refresh(void);
	__property TCustomActionBar* ActionBar = {read=FActionBar, write=SetActionBar};
	__property TCustomActionBar* ChildActionBar = {read=FChildActionBar, write=FChildActionBar};
	__property bool HasItems = {read=GetHasItems, nodefault};
	
__published:
	__property TChangesAllowedSet ChangesAllowed = {read=FChangesAllowed, write=SetChangesAllowed, default=7};
	__property Graphics::TColor Color = {read=FColor, write=SetColor, default=536870912};
	__property TActionClients* ContextItems = {read=GetContextItems, write=SetContextItems, stored=AreContextItemsStored};
	__property Graphics::TPicture* Background = {read=GetBackground, write=SetBackground, stored=IsBackgroundStored};
	__property TBackgroundLayout BackgroundLayout = {read=FBackgroundLayout, write=SetBackgroundLayout, default=0};
	__property TActionClients* Items = {read=GetItems, write=SetItems, stored=IsItemsStored};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
};


typedef void __fastcall (__closure *TActionProc)(TActionClient* AClient);

class PASCALIMPLEMENTATION TActionClientsCollection : public Classes::TOwnedCollection 
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TActionClient* operator[](int Index) { return ActionClients[Index]; }
	
private:
	TActionClient* FParentItem;
	bool FCustomizable;
	TActionClient* __fastcall GetActionClient(const int Index);
	void __fastcall SetActionClient(const int Index, const TActionClient* Value);
	
protected:
	TCustomActionManager* __fastcall GetActionManager(void);
	bool __fastcall InternalRethinkHotkeys(bool ForceRethink);
	__property TActionClient* ActionClients[int Index] = {read=GetActionClient, write=SetActionClient/*, default*/};
	__property TActionClient* ParentItem = {read=FParentItem, write=FParentItem};
	
public:
	virtual void __fastcall AfterConstruction(void);
	void __fastcall IterateClients(TActionClientsCollection* Clients, TActionProc ActionProc);
	__property TCustomActionManager* ActionManager = {read=GetActionManager};
	__property bool Customizable = {read=FCustomizable, write=FCustomizable, default=1};
public:
	#pragma option push -w-inl
	/* TOwnedCollection.Create */ inline __fastcall TActionClientsCollection(Classes::TPersistent* AOwner, TMetaClass* ItemClass) : Classes::TOwnedCollection(AOwner, ItemClass) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TActionClientsCollection(void) { }
	#pragma option pop
	
};


class DELPHICLASS TActionBarItem;
class PASCALIMPLEMENTATION TActionBars : public TActionClientsCollection 
{
	typedef TActionClientsCollection inherited;
	
public:
	TActionBarItem* operator[](int Index) { return ActionBars[Index]; }
	
private:
	int FSessionCount;
	bool FShowHint;
	TActionBarItem* __fastcall GetActionBar(const int Index);
	void __fastcall SetShowHints(const bool Value);
	void __fastcall SetHintShortCuts(const bool Value);
	bool __fastcall GetHintShortCuts(void);
	
protected:
	void __fastcall DoShowHint(TActionClient* AClient);
	virtual void __fastcall Notify(Classes::TCollectionItem* Item, Classes::TCollectionNotification Action);
	
public:
	__fastcall TActionBars(Classes::TPersistent* AOwner, TMetaClass* ItemClass);
	HIDESBASE TActionBarItem* __fastcall Add(void);
	__property TActionBarItem* ActionBars[int Index] = {read=GetActionBar/*, default*/};
	
__published:
	__property Customizable  = {default=1};
	__property bool HintShortCuts = {read=GetHintShortCuts, write=SetHintShortCuts, default=1};
	__property int SessionCount = {read=FSessionCount, write=FSessionCount, default=0};
	__property bool ShowHints = {read=FShowHint, write=SetShowHints, default=1};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TActionBars(void) { }
	#pragma option pop
	
};


class DELPHICLASS TActionListCollection;
class DELPHICLASS TActionListItem;
class PASCALIMPLEMENTATION TActionListCollection : public Classes::TOwnedCollection 
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TActionListItem* operator[](int Index) { return ListItems[Index]; }
	
private:
	TCustomActionManager* __fastcall GetActionManager(void);
	TActionListItem* __fastcall GetListItem(int Index);
	void __fastcall SetListItem(int Index, const TActionListItem* Value);
	
public:
	__property TCustomActionManager* ActionManager = {read=GetActionManager};
	__property TActionListItem* ListItems[int Index] = {read=GetListItem, write=SetListItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TOwnedCollection.Create */ inline __fastcall TActionListCollection(Classes::TPersistent* AOwner, TMetaClass* ItemClass) : Classes::TOwnedCollection(AOwner, ItemClass) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TActionListCollection(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TCustomActionManager : public Actnlist::TCustomActionList 
{
	typedef Actnlist::TCustomActionList inherited;
	
private:
	TActionBars* FActionBars;
	TActionListCollection* FLinkedActionLists;
	TActionBars* FDefaultActionBars;
	AnsiString FFileName;
	bool FLoading;
	Classes::TStringList* FPrioritySchedule;
	bool FSaved;
	void __fastcall SetActionBars(const TActionBars* Value);
	void __fastcall SetPrioritySchedule(const Classes::TStringList* Value);
	bool __fastcall IsPriorityScheduleStored(void);
	void __fastcall SetLinkedActionLists(const TActionListCollection* Value);
	bool __fastcall IsLinkedActionListsStored(void);
	bool __fastcall IsActionBarsStored(void);
	
protected:
	virtual void __fastcall Change(void);
	TActionBars* __fastcall CreateActionBars(void);
	TActionClientItem* __fastcall FindActionClient(Actnlist::TContainedAction* AnAction, TActionClientsCollection* Clients = (TActionClientsCollection*)(0x0));
	TActionClient* __fastcall FindActionBar(TCustomActionBar* ActionBar, TActionClientsCollection* Clients = (TActionClientsCollection*)(0x0));
	TMetaClass* __fastcall GetActionBarsClass(void);
	TMetaClass* __fastcall GetActionBarItemClass(void);
	TMetaClass* __fastcall GetActionClientsClass(void);
	TMetaClass* __fastcall GetActionClientItemClass(void);
	virtual bool __fastcall GetUsage(TActionClientItem* AnItem);
	virtual void __fastcall Loaded(void);
	void __fastcall LoadMenu(TActionClients* Clients, Menus::TMenuItem* AMenu);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall SetupActionBars(TActionClientsCollection* ActionBars);
	virtual void __fastcall SetImages(Imglist::TCustomImageList* Value);
	__property bool Loading = {read=FLoading, nodefault};
	
public:
	__fastcall virtual TCustomActionManager(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomActionManager(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall LoadFromFile(const AnsiString Filename);
	void __fastcall LoadFromStream(Classes::TStream* S);
	void __fastcall ResetActionBar(int Index);
	void __fastcall ResetUsageData(void);
	void __fastcall SaveToFile(const AnsiString Filename);
	void __fastcall SaveToStream(Classes::TStream* S);
	__property TActionBars* ActionBars = {read=FActionBars, write=SetActionBars, stored=IsActionBarsStored};
	__property TActionBars* DefaultActionBars = {read=FDefaultActionBars};
	__property TActionListCollection* LinkedActionLists = {read=FLinkedActionLists, write=SetLinkedActionLists, stored=IsLinkedActionListsStored};
	__property AnsiString FileName = {read=FFileName, write=FFileName};
	__property Images ;
	__property Classes::TStringList* PrioritySchedule = {read=FPrioritySchedule, write=SetPrioritySchedule, stored=IsPriorityScheduleStored};
};


class DELPHICLASS TActionManager;
class PASCALIMPLEMENTATION TActionManager : public TCustomActionManager 
{
	typedef TCustomActionManager inherited;
	
__published:
	__property FileName ;
	__property ActionBars ;
	__property LinkedActionLists ;
	__property Images ;
	__property PrioritySchedule ;
	__property State  = {default=0};
	__property OnChange ;
	__property OnExecute ;
	__property OnUpdate ;
public:
	#pragma option push -w-inl
	/* TCustomActionManager.Create */ inline __fastcall virtual TActionManager(Classes::TComponent* AOwner) : TCustomActionManager(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomActionManager.Destroy */ inline __fastcall virtual ~TActionManager(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TActionListItem : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	Actnlist::TCustomActionList* FActionList;
	AnsiString FCaption;
	void __fastcall SetActionList(const Actnlist::TCustomActionList* Value);
	AnsiString __fastcall GetCaption();
	
protected:
	virtual AnsiString __fastcall GetDisplayName();
	TActionListCollection* __fastcall Owner(void);
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property Actnlist::TCustomActionList* ActionList = {read=FActionList, write=SetActionList};
	__property AnsiString Caption = {read=GetCaption, write=FCaption};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Create */ inline __fastcall virtual TActionListItem(Classes::TCollection* Collection) : Classes::TCollectionItem(Collection) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TActionListItem(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TActionBarItem : public TActionClient 
{
	typedef TActionClient inherited;
	
private:
	bool FAutoSize;
	Buttons::TButtonLayout FGlyphLayout;
	TActionBars* __fastcall GetActionBars(void);
	void __fastcall SetAutoSize(const bool Value);
	void __fastcall SetGlyphLayout(const Buttons::TButtonLayout Value);
	
protected:
	virtual void __fastcall ColorChanged(void);
	virtual AnsiString __fastcall GetDisplayName();
	virtual void __fastcall SetVisible(const bool Value);
	__property TActionBars* ActionBars = {read=GetActionBars};
	
public:
	__fastcall virtual TActionBarItem(Classes::TCollection* Collection);
	__fastcall virtual ~TActionBarItem(void);
	virtual void __fastcall Refresh(void);
	
__published:
	__property ActionBar ;
	__property bool AutoSize = {read=FAutoSize, write=SetAutoSize, default=1};
	__property Buttons::TButtonLayout GlyphLayout = {read=FGlyphLayout, write=SetGlyphLayout, default=0};
};


typedef TMetaClass*TActionClientClass;

#pragma option push -b-
enum TCaptionOptions { coNone, coSelective, coAll };
#pragma option pop

class PASCALIMPLEMENTATION TActionClients : public TActionClientsCollection 
{
	typedef TActionClientsCollection inherited;
	
public:
	TActionClientItem* operator[](int Index) { return ActionClients[Index]; }
	
private:
	TCaptionOptions FCaptionOptions;
	bool FSmallIcons;
	bool FHideUnused;
	bool FAutoHotKeys;
	HIDESBASE TActionClientItem* __fastcall GetActionClient(const int Index);
	HIDESBASE void __fastcall SetActionClient(const int Index, const TActionClientItem* Value);
	void __fastcall SetCaptionOptions(const TCaptionOptions Value);
	void __fastcall SetSmallIcons(const bool Value);
	void __fastcall SetHideUnused(const bool Value);
	void __fastcall SetAutoHotKeys(const bool Value);
	
protected:
	void __fastcall DoHideUnused(TActionClient* AClient);
	void __fastcall DoShowCaptions(TActionClient* AClient);
	void __fastcall ToggleSmallIcons(TActionClients* Clients, bool Small);
	virtual void __fastcall Notify(Classes::TCollectionItem* Item, Classes::TCollectionNotification Action);
	
public:
	__fastcall TActionClients(Classes::TPersistent* AOwner, TMetaClass* ItemClass);
	HIDESBASE TActionClientItem* __fastcall Add(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	int __fastcall VisibleCount(void);
	__property TActionClientItem* ActionClients[int Index] = {read=GetActionClient, write=SetActionClient/*, default*/};
	__property TCustomActionManager* ActionManager = {read=GetActionManager};
	
__published:
	__property bool AutoHotKeys = {read=FAutoHotKeys, write=SetAutoHotKeys, default=1};
	__property Customizable  = {default=1};
	__property bool HideUnused = {read=FHideUnused, write=SetHideUnused, default=1};
	__property TCaptionOptions CaptionOptions = {read=FCaptionOptions, write=SetCaptionOptions, default=1};
	__property bool SmallIcons = {read=FSmallIcons, write=SetSmallIcons, default=1};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TActionClients(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TActionClientLinkClass;

class DELPHICLASS TActionClientLink;
class PASCALIMPLEMENTATION TActionClientLink : public Actnlist::TActionLink 
{
	typedef Actnlist::TActionLink inherited;
	
protected:
	TActionClientItem* FClient;
	virtual void __fastcall AssignClient(System::TObject* AClient);
	virtual bool __fastcall IsCaptionLinked(void);
	virtual bool __fastcall IsEnabledLinked(void);
	virtual bool __fastcall IsHintLinked(void);
	virtual bool __fastcall IsImageIndexLinked(void);
	virtual bool __fastcall IsOnExecuteLinked(void);
	virtual bool __fastcall IsShortCutLinked(void);
	virtual bool __fastcall IsVisibleLinked(void);
	virtual void __fastcall SetCaption(const AnsiString Value);
	virtual void __fastcall SetChecked(bool Value);
	virtual void __fastcall SetEnabled(bool Value);
	virtual void __fastcall SetHint(const AnsiString Value);
	virtual void __fastcall SetImageIndex(int Value);
	virtual void __fastcall SetOnExecute(Classes::TNotifyEvent Value);
	virtual void __fastcall SetShortCut(Classes::TShortCut Value);
	virtual void __fastcall SetVisible(bool Value);
public:
	#pragma option push -w-inl
	/* TBasicActionLink.Create */ inline __fastcall virtual TActionClientLink(System::TObject* AClient) : Actnlist::TActionLink(AClient) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBasicActionLink.Destroy */ inline __fastcall virtual ~TActionClientLink(void) { }
	#pragma option pop
	
};


typedef int TMergeRange;

class PASCALIMPLEMENTATION TActionClientItem : public TActionClient 
{
	typedef TActionClient inherited;
	
private:
	TActionClientLink* FActionLink;
	bool FCheckUnused;
	TCustomActionControl* FControl;
	int FUsageCount;
	Classes::TShortCut FShortCut;
	TMergeRange FMergeIndex;
	bool FSeparator;
	bool FShowCaption;
	bool FShowShortCut;
	AnsiString FShortCutText;
	int FImageIndex;
	int FLastSession;
	bool FUnused;
	bool FShowGlyph;
	void __fastcall DoActionChange(System::TObject* Sender);
	void __fastcall SetAction(const Actnlist::TContainedAction* Value);
	void __fastcall SetUsageCount(const int Value);
	TActionClients* __fastcall GetActionClients(void);
	void __fastcall SetShortCut(const Classes::TShortCut Value);
	void __fastcall SetControl(const TCustomActionControl* Value);
	void __fastcall SetMergeIndex(const TMergeRange Value);
	void __fastcall SetShowShortCut(const bool Value);
	void __fastcall SetImageIndex(const int Value);
	void __fastcall SetCaption(const AnsiString Value);
	void __fastcall SetShowCaption(const bool Value);
	AnsiString __fastcall GetCaption();
	Actnlist::TContainedAction* __fastcall GetAction(void);
	void __fastcall SetShowGlyph(const bool Value);
	bool __fastcall IsCaptionStored(void);
	TActionClient* __fastcall GetParentItem(void);
	void __fastcall SetLastSession(const int Value);
	
protected:
	DYNAMIC void __fastcall ActionChange(System::TObject* Sender, bool CheckDefaults);
	virtual void __fastcall ColorChanged(void);
	DYNAMIC TMetaClass* __fastcall GetActionLinkClass(void);
	virtual AnsiString __fastcall GetDisplayName();
	void __fastcall ResetUsageData(void);
	virtual void __fastcall SetChangesAllowed(const TChangesAllowedSet Value);
	virtual void __fastcall SetCollection(Classes::TCollection* Value);
	virtual void __fastcall SetIndex(int Value);
	virtual void __fastcall SetVisible(const bool Value);
	
public:
	__fastcall virtual TActionClientItem(Classes::TCollection* Collection);
	__fastcall virtual ~TActionClientItem(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	bool __fastcall HasGlyph(void);
	virtual void __fastcall InitiateAction(void);
	virtual void __fastcall Refresh(void);
	bool __fastcall Unused(void);
	__property TActionClients* ActionClients = {read=GetActionClients};
	__property TActionClientLink* ActionLink = {read=FActionLink, write=FActionLink};
	__property bool CheckUnused = {read=FCheckUnused, write=FCheckUnused, nodefault};
	__property TCustomActionControl* Control = {read=FControl, write=SetControl};
	__property TActionClient* ParentItem = {read=GetParentItem};
	__property bool Separator = {read=FSeparator, nodefault};
	__property AnsiString ShortCutText = {read=FShortCutText};
	
__published:
	__property Actnlist::TContainedAction* Action = {read=GetAction, write=SetAction};
	__property AnsiString Caption = {read=GetCaption, write=SetCaption, stored=IsCaptionStored};
	__property int ImageIndex = {read=FImageIndex, write=SetImageIndex, default=-1};
	__property TMergeRange MergeIndex = {read=FMergeIndex, write=SetMergeIndex, default=0};
	__property int LastSession = {read=FLastSession, write=SetLastSession, default=0};
	__property bool ShowCaption = {read=FShowCaption, write=SetShowCaption, default=1};
	__property bool ShowGlyph = {read=FShowGlyph, write=SetShowGlyph, default=1};
	__property bool ShowShortCut = {read=FShowShortCut, write=SetShowShortCut, default=1};
	__property Classes::TShortCut ShortCut = {read=FShortCut, write=SetShortCut, default=0};
	__property int UsageCount = {read=FUsageCount, write=SetUsageCount, default=0};
};


class DELPHICLASS TCustomActionClass;
class PASCALIMPLEMENTATION TCustomActionClass : public Actnlist::TCustomAction 
{
	typedef Actnlist::TCustomAction inherited;
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual TCustomActionClass(Classes::TComponent* AOwner) : Actnlist::TCustomAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TCustomActionClass(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TActionDragObject : public Controls::TDragObjectEx 
{
	typedef Controls::TDragObjectEx inherited;
	
private:
	Classes::TList* FActions;
	TCustomActionManager* FActionManager;
	Actnlist::TContainedAction* __fastcall GetAction(int Index);
	int __fastcall GetActionCount(void);
	
protected:
	bool FActionClasses;
	
public:
	__fastcall TActionDragObject(void);
	__fastcall virtual ~TActionDragObject(void);
	void __fastcall AddAction(Actnlist::TContainedAction* AnAction);
	void __fastcall AddActionClass(TCustomActionClass* AnActionClass);
	__property int ActionCount = {read=GetActionCount, nodefault};
	__property TCustomActionManager* ActionManager = {read=FActionManager, write=FActionManager};
	__property Actnlist::TContainedAction* Actions[int Index] = {read=GetAction};
};


class PASCALIMPLEMENTATION TCategoryDragObject : public TActionDragObject 
{
	typedef TActionDragObject inherited;
	
private:
	AnsiString FCategory;
	
public:
	__fastcall TCategoryDragObject(AnsiString ACategory);
	__property AnsiString Category = {read=FCategory};
public:
	#pragma option push -w-inl
	/* TActionDragObject.Destroy */ inline __fastcall virtual ~TCategoryDragObject(void) { }
	#pragma option pop
	
};


class DELPHICLASS TActionItemDragObject;
class PASCALIMPLEMENTATION TActionItemDragObject : public Controls::TDragObjectEx 
{
	typedef Controls::TDragObjectEx inherited;
	
private:
	TActionClientItem* FClientItem;
	
protected:
	virtual void __fastcall Finished(System::TObject* Target, int X, int Y, bool Accepted);
	
public:
	__property TActionClientItem* ClientItem = {read=FClientItem};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TActionItemDragObject(void) : Controls::TDragObjectEx() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TActionItemDragObject(void) { }
	#pragma option pop
	
};


#pragma pack(push, 4)
struct TCMItemMsg
{
	unsigned Msg;
	int Unused;
	TCustomActionControl* Sender;
	int Result;
} ;
#pragma pack(pop)

class PASCALIMPLEMENTATION TCustomActionControl : public Controls::TGraphicControl 
{
	typedef Controls::TGraphicControl inherited;
	
private:
	TCustomActionBar* FActionBar;
	TActionClientItem* FActionClient;
	Buttons::TButtonLayout FGlyphLayout;
	#pragma pack(push, 1)
	Types::TPoint FGlyphPos;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	Types::TRect FMargins;
	#pragma pack(pop)
	
	bool FSelected;
	bool FSmallIcon;
	int FSpacing;
	#pragma pack(push, 1)
	Types::TRect FTextBounds;
	#pragma pack(pop)
	
	bool FTransparent;
	int __fastcall CaptionLength(void);
	int __fastcall CaptionHeight(void);
	int __fastcall ActualSpacing(const Types::TPoint &ImageSize);
	MESSAGE void __fastcall CMTextChanged(Messages::TMessage &Message);
	TCustomActionBar* __fastcall GetActionBar(void);
	void __fastcall SetMargins(const Types::TRect &Value);
	void __fastcall SetTransparent(const bool Value);
	void __fastcall SetSmallIcon(const bool Value);
	void __fastcall SetSpacing(const int Value);
	void __fastcall SetGlyphLayout(const Buttons::TButtonLayout Value);
	HIDESBASE MESSAGE void __fastcall WMContextMenu(Messages::TWMContextMenu &Message);
	
protected:
	DYNAMIC void __fastcall BeginAutoDrag(void);
	virtual void __fastcall CalcLayout(void);
	DYNAMIC bool __fastcall DesignWndProc(Messages::TMessage &Message);
	virtual void __fastcall DoDragDrop(System::TObject* DragObject, int X, int Y);
	DYNAMIC void __fastcall DragOver(System::TObject* Source, int X, int Y, Controls::TDragState State, bool &Accept);
	virtual Classes::TBasicAction* __fastcall GetAction(void);
	virtual bool __fastcall GetShowCaption(void);
	virtual bool __fastcall GetShowShortCut(void);
	HIDESBASE MESSAGE void __fastcall CMDesignHitTest(Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMItemSelected(TCMItemMsg &Message);
	DYNAMIC void __fastcall DoStartDrag(Controls::TDragObject* &DragObject);
	virtual void __fastcall DrawDesignFocus(Types::TRect &PaintRect);
	void __fastcall DrawDragDropPoint(void);
	virtual void __fastcall DrawGlyph(const Types::TPoint &Location);
	virtual void __fastcall DrawBackground(Types::TRect &PaintRect);
	virtual void __fastcall DrawText(Types::TRect &ARect, unsigned &Flags, AnsiString Text);
	virtual void __fastcall DrawSeparator(const int Offset);
	virtual Types::TPoint __fastcall GetImageSize();
	bool __fastcall HasGlyph(void);
	virtual bool __fastcall IsChecked(void);
	virtual bool __fastcall IsGrouped(void);
	virtual bool __fastcall GetSeparator(void);
	virtual void __fastcall Paint(void);
	virtual void __fastcall PositionChanged(void);
	void __fastcall ResetUsageData(void);
	virtual void __fastcall SetActionClient(TActionClientItem* Value);
	virtual void __fastcall SetSelected(bool Value);
	void __fastcall UpdateSelection(void);
	void __fastcall UpdateTextBounds(void);
	MESSAGE void __fastcall WMSetText(Messages::TWMSetText &Message);
	__property Types::TPoint GlyphPos = {read=FGlyphPos, write=FGlyphPos};
	
public:
	__fastcall virtual TCustomActionControl(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomActionControl(void);
	virtual void __fastcall CalcBounds(void);
	DYNAMIC void __fastcall Click(void);
	DYNAMIC void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	virtual void __fastcall InitiateAction(void);
	virtual void __fastcall Keyed(void);
	__property TCustomActionBar* ActionBar = {read=GetActionBar};
	__property TActionClientItem* ActionClient = {read=FActionClient, write=SetActionClient};
	__property Buttons::TButtonLayout GlyphLayout = {read=FGlyphLayout, write=SetGlyphLayout, nodefault};
	__property Types::TRect Margins = {read=FMargins, write=SetMargins};
	__property bool Selected = {read=FSelected, write=SetSelected, nodefault};
	__property bool Separator = {read=GetSeparator, nodefault};
	__property bool ShowCaption = {read=GetShowCaption, nodefault};
	__property bool ShowShortCut = {read=GetShowShortCut, nodefault};
	__property bool SmallIcon = {read=FSmallIcon, write=SetSmallIcon, nodefault};
	__property int Spacing = {read=FSpacing, write=SetSpacing, default=4};
	__property Types::TRect TextBounds = {read=FTextBounds, write=FTextBounds};
	__property bool Transparent = {read=FTransparent, write=SetTransparent, nodefault};
	__property OnClick ;
};


__interface IActionBarDesigner;
typedef System::DelphiInterface<IActionBarDesigner> _di_IActionBarDesigner;
__interface INTERFACE_UUID("{7CFC301B-1C59-11D4-8184-00C04F6BB89F}") IActionBarDesigner  : public IInterface 
{
	
public:
	virtual Actnlist::TContainedAction* __fastcall CreateAction(TMetaClass* AnActionClass) = 0 ;
	virtual void __fastcall EditAction(Actnlist::TContainedAction* Action) = 0 ;
	virtual void __fastcall Modified(TCustomActionBar* ActionBar) = 0 ;
	virtual void __fastcall SetActiveMenu(TCustomActionBar* Menu) = 0 ;
	virtual void __fastcall SetItemSelection(const TActionClient* * Items, const int Items_Size) = 0 ;
	virtual void __fastcall SetSelection(Classes::TPersistent* APersistent) = 0 ;
};

class DELPHICLASS TXToolDockForm;
class PASCALIMPLEMENTATION TXToolDockForm : public Toolwin::TToolDockForm 
{
	typedef Toolwin::TToolDockForm inherited;
	
private:
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Messages::TMessage &Message);
public:
	#pragma option push -w-inl
	/* TToolDockForm.Create */ inline __fastcall virtual TXToolDockForm(Classes::TComponent* AOwner) : Toolwin::TToolDockForm(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TXToolDockForm(Classes::TComponent* AOwner, int Dummy) : Toolwin::TToolDockForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TXToolDockForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TXToolDockForm(HWND ParentWindow) : Toolwin::TToolDockForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Word CM_ITEMSELECTED = 0xb402;
static const Word CM_ITEMCLICKED = 0xb403;
static const Word CM_ITEMKEYED = 0xb404;
static const Word CM_SCROLLCLICKED = 0xb406;
static const Word CM_RESETBAR = 0xb409;
static const Word CM_ENTERMENULOOP = 0xb410;
#define caAllChanges (System::Set<TChangesAllowed, caModify, caDelete> () << TChangesAllowed(0) << TChangesAllowed(1) << TChangesAllowed(2) )
extern PACKAGE Controls::TDragMode ControlDragMode[2];
extern PACKAGE AnsiString cDefaultSchedule;
extern PACKAGE _di_IActionBarDesigner ActionBarDesigner;
extern PACKAGE void __fastcall NotifyDesigner(TCustomActionBar* ActionBar);

}	/* namespace Actnman */
using namespace Actnman;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ActnMan
