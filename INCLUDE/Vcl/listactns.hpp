// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ListActns.pas' rev: 6.00

#ifndef ListActnsHPP
#define ListActnsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ImgList.hpp>	// Pascal unit
#include <ActnList.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Listactns
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TListControlItem;
class DELPHICLASS TListControlItems;
#pragma option push -b-
enum TListItemsSortType { stNone, stData, stText, stBoth };
#pragma option pop

typedef int __fastcall (__closure *TListCompareEvent)(TListControlItems* List, TListControlItem* Item1, TListControlItem* Item2);

typedef int __fastcall (*TListItemsCompare)(TListControlItems* List, int Index1, int Index2);

class PASCALIMPLEMENTATION TListControlItems : public Classes::TOwnedCollection 
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TListControlItem* operator[](int Index) { return Items[Index]; }
	
private:
	bool FCaseSensitive;
	TListItemsSortType FSortType;
	TListCompareEvent FOnCompare;
	void __fastcall ExchangeItems(int Index1, int Index2);
	TListControlItem* __fastcall GetListItem(const int Index);
	void __fastcall QuickSort(int L, int R, TListItemsCompare SCompare);
	void __fastcall SetSortType(const TListItemsSortType Value);
	
protected:
	virtual int __fastcall CompareItems(TListControlItem* I1, TListControlItem* I2);
	
public:
	HIDESBASE TListControlItem* __fastcall Add(void);
	void __fastcall Sort(void);
	void __fastcall CustomSort(TListItemsCompare Compare);
	__property TListControlItem* Items[int Index] = {read=GetListItem/*, default*/};
	
__published:
	__property bool CaseSensitive = {read=FCaseSensitive, write=FCaseSensitive, nodefault};
	__property TListItemsSortType SortType = {read=FSortType, write=SetSortType, nodefault};
	__property TListCompareEvent OnCompare = {read=FOnCompare, write=FOnCompare};
public:
	#pragma option push -w-inl
	/* TOwnedCollection.Create */ inline __fastcall TListControlItems(Classes::TPersistent* AOwner, TMetaClass* ItemClass) : Classes::TOwnedCollection(AOwner, ItemClass) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TListControlItems(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TListControlItem : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	TListControlItems* FListControlItems;
	
protected:
	AnsiString FCaption;
	void *FData;
	Imglist::TImageIndex FImageIndex;
	HIDESBASE void __fastcall Changed(void);
	virtual AnsiString __fastcall GetDisplayName();
	virtual void __fastcall SetCaption(const AnsiString Value);
	virtual void __fastcall SetData(const void * Value);
	virtual void __fastcall SetImageIndex(const Imglist::TImageIndex Value);
	
public:
	__fastcall virtual TListControlItem(Classes::TCollection* Collection);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property void * Data = {read=FData, write=SetData};
	
__published:
	__property AnsiString Caption = {read=FCaption, write=SetCaption};
	__property Imglist::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, default=-1};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TListControlItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomListAction;
typedef void __fastcall (__closure *TGetItemCountEvent)(TCustomListAction* Sender, int &Count);

typedef void __fastcall (__closure *TItemSelectedEvent)(TCustomListAction* Sender, Controls::TControl* Control);

class PASCALIMPLEMENTATION TCustomListAction : public Actnlist::TCustomAction 
{
	typedef Actnlist::TCustomAction inherited;
	
public:
	AnsiString operator[](int Index) { return Strings[Index]; }
	
private:
	bool FActive;
	bool FActivated;
	Imglist::TCustomImageList* FImages;
	bool FInUpdate;
	Imglist::TCustomImageList* FLoadedImages;
	bool FLoading;
	TGetItemCountEvent FOnGetItemCount;
	TItemSelectedEvent FOnItemSelected;
	int FItemIndex;
	void __fastcall SetActive(const bool Value);
	void __fastcall SetImages(const Imglist::TCustomImageList* Value);
	void __fastcall SetItemIndex(const int Value);
	
protected:
	virtual int __fastcall GetCount(void);
	virtual AnsiString __fastcall GetString(int Index);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall SetString(int Index, const AnsiString Value);
	__property Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property int ItemIndex = {read=FItemIndex, write=SetItemIndex, nodefault};
	__property bool Loading = {read=FLoading, nodefault};
	__property TGetItemCountEvent OnGetItemCount = {read=FOnGetItemCount, write=FOnGetItemCount};
	__property TItemSelectedEvent OnItemSelected = {read=FOnItemSelected, write=FOnItemSelected};
	
public:
	__fastcall virtual TCustomListAction(Classes::TComponent* AOwner);
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual bool __fastcall HandlesTarget(System::TObject* Target);
	__property bool Active = {read=FActive, write=SetActive, default=1};
	__property int Count = {read=GetCount, nodefault};
	__property AnsiString Strings[int Index] = {read=GetString, write=SetString/*, default*/};
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TCustomListAction(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TGetVirtualItemEvent)(TCustomListAction* Sender, const int Index, AnsiString &Value, int &ImageIndex, void * &Data);

class DELPHICLASS TVirtualListAction;
class PASCALIMPLEMENTATION TVirtualListAction : public TCustomListAction 
{
	typedef TCustomListAction inherited;
	
private:
	TGetVirtualItemEvent FOnGetItem;
	
protected:
	bool __fastcall GetItem(const int Index, AnsiString &Value, int &ImageIndex, void * &Data);
	
public:
	__property Count ;
	
__published:
	__property Active  = {default=1};
	__property Caption ;
	__property Enabled  = {default=1};
	__property HelpContext  = {default=0};
	__property Hint ;
	__property Images ;
	__property ItemIndex  = {default=-1};
	__property ShortCut  = {default=0};
	__property SecondaryShortCuts ;
	__property Visible  = {default=1};
	__property TGetVirtualItemEvent OnGetItem = {read=FOnGetItem, write=FOnGetItem};
	__property OnGetItemCount ;
	__property OnItemSelected ;
	__property OnHint ;
public:
	#pragma option push -w-inl
	/* TCustomListAction.Create */ inline __fastcall virtual TVirtualListAction(Classes::TComponent* AOwner) : TCustomListAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TVirtualListAction(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TGetItemEvent)(TCustomListAction* Sender, const int Index, TListControlItem* &Item);

class DELPHICLASS TStaticListItems;
class DELPHICLASS TStaticListAction;
typedef TMetaClass*TListControlItemClass;

class PASCALIMPLEMENTATION TStaticListAction : public TCustomListAction 
{
	typedef TCustomListAction inherited;
	
private:
	TStaticListItems* FListItems;
	TGetItemEvent FOnGetItem;
	void __fastcall SetListitems(const TStaticListItems* Value);
	
protected:
	virtual TMetaClass* __fastcall GetItemClass(void);
	virtual int __fastcall GetCount(void);
	bool __fastcall GetItem(const int Index, TListControlItem* AnItem);
	virtual AnsiString __fastcall GetString(int Index);
	virtual void __fastcall SetString(int Index, const AnsiString Value);
	
public:
	__fastcall virtual TStaticListAction(Classes::TComponent* AOwner);
	__fastcall virtual ~TStaticListAction(void);
	__property Count ;
	
__published:
	__property Active  = {default=1};
	__property Caption ;
	__property Enabled  = {default=1};
	__property HelpContext  = {default=0};
	__property Hint ;
	__property Images ;
	__property ItemIndex  = {default=-1};
	__property TStaticListItems* Items = {read=FListItems, write=SetListitems};
	__property ShortCut  = {default=0};
	__property SecondaryShortCuts ;
	__property Visible  = {default=1};
	__property TGetItemEvent OnGetItem = {read=FOnGetItem, write=FOnGetItem};
	__property OnItemSelected ;
	__property OnHint ;
	__property OnUpdate ;
};


class PASCALIMPLEMENTATION TStaticListItems : public TListControlItems 
{
	typedef TListControlItems inherited;
	
private:
	TStaticListAction* FStaticListAction;
	
protected:
	virtual void __fastcall Notify(Classes::TCollectionItem* Item, Classes::TCollectionNotification Action);
	virtual void __fastcall Update(Classes::TCollectionItem* Item);
public:
	#pragma option push -w-inl
	/* TOwnedCollection.Create */ inline __fastcall TStaticListItems(Classes::TPersistent* AOwner, TMetaClass* ItemClass) : TListControlItems(AOwner, ItemClass) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TStaticListItems(void) { }
	#pragma option pop
	
};


class DELPHICLASS TListActionLink;
class PASCALIMPLEMENTATION TListActionLink : public Controls::TWinControlActionLink 
{
	typedef Controls::TWinControlActionLink inherited;
	
protected:
	virtual bool __fastcall IsActiveLinked(void);
	virtual void __fastcall SetActive(const bool Value);
	virtual bool __fastcall IsImagesLinked(void);
	virtual void __fastcall SetAction(Classes::TBasicAction* Value);
	virtual void __fastcall SetImages(Imglist::TCustomImageList* Value);
	virtual void __fastcall SetItemIndex(const int Value);
	virtual void __fastcall AddItem(TListControlItem* AnItem)/* overload */;
	virtual void __fastcall AddItem(AnsiString ACaption, int AImageIndex, void * DataPtr)/* overload */;
	void __fastcall RefreshControl(void);
public:
	#pragma option push -w-inl
	/* TBasicActionLink.Create */ inline __fastcall virtual TListActionLink(System::TObject* AClient) : Controls::TWinControlActionLink(AClient) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBasicActionLink.Destroy */ inline __fastcall virtual ~TListActionLink(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Listactns */
using namespace Listactns;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ListActns
