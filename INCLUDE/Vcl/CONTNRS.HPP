// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Contnrs.pas' rev: 6.00

#ifndef ContnrsHPP
#define ContnrsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Contnrs
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TObjectList;
class PASCALIMPLEMENTATION TObjectList : public Classes::TList 
{
	typedef Classes::TList inherited;
	
public:
	System::TObject* operator[](int Index) { return Items[Index]; }
	
private:
	bool FOwnsObjects;
	
protected:
	virtual void __fastcall Notify(void * Ptr, Classes::TListNotification Action);
	System::TObject* __fastcall GetItem(int Index);
	void __fastcall SetItem(int Index, System::TObject* AObject);
	
public:
	__fastcall TObjectList(void)/* overload */;
	__fastcall TObjectList(bool AOwnsObjects)/* overload */;
	HIDESBASE int __fastcall Add(System::TObject* AObject);
	HIDESBASE System::TObject* __fastcall Extract(System::TObject* Item);
	HIDESBASE int __fastcall Remove(System::TObject* AObject);
	HIDESBASE int __fastcall IndexOf(System::TObject* AObject);
	int __fastcall FindInstanceOf(TMetaClass* AClass, bool AExact = true, int AStartAt = 0x0);
	HIDESBASE void __fastcall Insert(int Index, System::TObject* AObject);
	HIDESBASE System::TObject* __fastcall First(void);
	HIDESBASE System::TObject* __fastcall Last(void);
	__property bool OwnsObjects = {read=FOwnsObjects, write=FOwnsObjects, nodefault};
	__property System::TObject* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TObjectList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TComponentList;
class PASCALIMPLEMENTATION TComponentList : public TObjectList 
{
	typedef TObjectList inherited;
	
public:
	Classes::TComponent* operator[](int Index) { return Items[Index]; }
	
private:
	Classes::TComponent* FNexus;
	
protected:
	virtual void __fastcall Notify(void * Ptr, Classes::TListNotification Action);
	Classes::TComponent* __fastcall GetItems(int Index);
	void __fastcall SetItems(int Index, Classes::TComponent* AComponent);
	void __fastcall HandleFreeNotify(System::TObject* Sender, Classes::TComponent* AComponent);
	
public:
	__fastcall virtual ~TComponentList(void);
	HIDESBASE int __fastcall Add(Classes::TComponent* AComponent);
	HIDESBASE Classes::TComponent* __fastcall Extract(Classes::TComponent* Item);
	HIDESBASE int __fastcall Remove(Classes::TComponent* AComponent);
	HIDESBASE int __fastcall IndexOf(Classes::TComponent* AComponent);
	HIDESBASE Classes::TComponent* __fastcall First(void);
	HIDESBASE Classes::TComponent* __fastcall Last(void);
	HIDESBASE void __fastcall Insert(int Index, Classes::TComponent* AComponent);
	__property Classes::TComponent* Items[int Index] = {read=GetItems, write=SetItems/*, default*/};
public:
	#pragma option push -w-inl
	/* TObjectList.Create */ inline __fastcall TComponentList(void)/* overload */ : TObjectList() { }
	#pragma option pop
	
};


class DELPHICLASS TClassList;
class PASCALIMPLEMENTATION TClassList : public Classes::TList 
{
	typedef Classes::TList inherited;
	
public:
	TMetaClass* operator[](int Index) { return Items[Index]; }
	
protected:
	TMetaClass* __fastcall GetItems(int Index);
	void __fastcall SetItems(int Index, TMetaClass* AClass);
	
public:
	HIDESBASE int __fastcall Add(TMetaClass* AClass);
	HIDESBASE TMetaClass* __fastcall Extract(TMetaClass* Item);
	HIDESBASE int __fastcall Remove(TMetaClass* AClass);
	HIDESBASE int __fastcall IndexOf(TMetaClass* AClass);
	HIDESBASE TMetaClass* __fastcall First(void);
	HIDESBASE TMetaClass* __fastcall Last(void);
	HIDESBASE void __fastcall Insert(int Index, TMetaClass* AClass);
	__property TMetaClass* Items[int Index] = {read=GetItems, write=SetItems/*, default*/};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TClassList(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TClassList(void) : Classes::TList() { }
	#pragma option pop
	
};


class DELPHICLASS TOrderedList;
class PASCALIMPLEMENTATION TOrderedList : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TList* FList;
	
protected:
	virtual void __fastcall PushItem(void * AItem) = 0 ;
	virtual void * __fastcall PopItem(void);
	virtual void * __fastcall PeekItem(void);
	__property Classes::TList* List = {read=FList};
	
public:
	__fastcall TOrderedList(void);
	__fastcall virtual ~TOrderedList(void);
	int __fastcall Count(void);
	bool __fastcall AtLeast(int ACount);
	void * __fastcall Push(void * AItem);
	void * __fastcall Pop(void);
	void * __fastcall Peek(void);
};


class DELPHICLASS TStack;
class PASCALIMPLEMENTATION TStack : public TOrderedList 
{
	typedef TOrderedList inherited;
	
protected:
	virtual void __fastcall PushItem(void * AItem);
public:
	#pragma option push -w-inl
	/* TOrderedList.Create */ inline __fastcall TStack(void) : TOrderedList() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TOrderedList.Destroy */ inline __fastcall virtual ~TStack(void) { }
	#pragma option pop
	
};


class DELPHICLASS TObjectStack;
class PASCALIMPLEMENTATION TObjectStack : public TStack 
{
	typedef TStack inherited;
	
public:
	HIDESBASE System::TObject* __fastcall Push(System::TObject* AObject);
	HIDESBASE System::TObject* __fastcall Pop(void);
	HIDESBASE System::TObject* __fastcall Peek(void);
public:
	#pragma option push -w-inl
	/* TOrderedList.Create */ inline __fastcall TObjectStack(void) : TStack() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TOrderedList.Destroy */ inline __fastcall virtual ~TObjectStack(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQueue;
class PASCALIMPLEMENTATION TQueue : public TOrderedList 
{
	typedef TOrderedList inherited;
	
protected:
	virtual void __fastcall PushItem(void * AItem);
public:
	#pragma option push -w-inl
	/* TOrderedList.Create */ inline __fastcall TQueue(void) : TOrderedList() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TOrderedList.Destroy */ inline __fastcall virtual ~TQueue(void) { }
	#pragma option pop
	
};


class DELPHICLASS TObjectQueue;
class PASCALIMPLEMENTATION TObjectQueue : public TQueue 
{
	typedef TQueue inherited;
	
public:
	HIDESBASE System::TObject* __fastcall Push(System::TObject* AObject);
	HIDESBASE System::TObject* __fastcall Pop(void);
	HIDESBASE System::TObject* __fastcall Peek(void);
public:
	#pragma option push -w-inl
	/* TOrderedList.Create */ inline __fastcall TObjectQueue(void) : TQueue() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TOrderedList.Destroy */ inline __fastcall virtual ~TObjectQueue(void) { }
	#pragma option pop
	
};


#pragma pack(push, 4)
struct TBucketItem
{
	void *Item;
	void *Data;
} ;
#pragma pack(pop)

typedef DynamicArray<TBucketItem >  TBucketItemArray;

#pragma pack(push, 4)
struct TBucket
{
	int Count;
	DynamicArray<TBucketItem >  Items;
} ;
#pragma pack(pop)

typedef DynamicArray<TBucket >  TBucketArray;

typedef void __fastcall (*TBucketProc)(void * AInfo, void * AItem, void * AData, /* out */ bool &AContinue);

class DELPHICLASS TCustomBucketList;
class PASCALIMPLEMENTATION TCustomBucketList : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	void * operator[](void * AItem) { return Data[AItem]; }
	
private:
	DynamicArray<TBucket >  FBuckets;
	int FBucketCount;
	bool FListLocked;
	void * __fastcall GetData(void * AItem);
	void __fastcall SetData(void * AItem, const void * AData);
	void __fastcall SetBucketCount(const int Value);
	
protected:
	__property TBucketArray Buckets = {read=FBuckets};
	__property int BucketCount = {read=FBucketCount, write=SetBucketCount, nodefault};
	virtual int __fastcall BucketFor(void * AItem) = 0 ;
	virtual bool __fastcall FindItem(void * AItem, /* out */ int &ABucket, /* out */ int &AIndex);
	virtual void * __fastcall AddItem(int ABucket, void * AItem, void * AData);
	virtual void * __fastcall DeleteItem(int ABucket, int AIndex);
	
public:
	__fastcall virtual ~TCustomBucketList(void);
	void __fastcall Clear(void);
	void * __fastcall Add(void * AItem, void * AData);
	void * __fastcall Remove(void * AItem);
	bool __fastcall ForEach(TBucketProc AProc, void * AInfo = (void *)(0x0));
	void __fastcall Assign(TCustomBucketList* AList);
	bool __fastcall Exists(void * AItem);
	bool __fastcall Find(void * AItem, /* out */ void * &AData);
	__property void * Data[void * AItem] = {read=GetData, write=SetData/*, default*/};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TCustomBucketList(void) : System::TObject() { }
	#pragma option pop
	
};


#pragma option push -b-
enum TBucketListSizes { bl2, bl4, bl8, bl16, bl32, bl64, bl128, bl256 };
#pragma option pop

class DELPHICLASS TBucketList;
class PASCALIMPLEMENTATION TBucketList : public TCustomBucketList 
{
	typedef TCustomBucketList inherited;
	
private:
	Byte FBucketMask;
	
protected:
	virtual int __fastcall BucketFor(void * AItem);
	
public:
	__fastcall TBucketList(TBucketListSizes ABuckets);
public:
	#pragma option push -w-inl
	/* TCustomBucketList.Destroy */ inline __fastcall virtual ~TBucketList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TObjectBucketList;
class PASCALIMPLEMENTATION TObjectBucketList : public TBucketList 
{
	typedef TBucketList inherited;
	
public:
	System::TObject* operator[](System::TObject* AItem) { return Data[AItem]; }
	
protected:
	HIDESBASE System::TObject* __fastcall GetData(System::TObject* AItem);
	HIDESBASE void __fastcall SetData(System::TObject* AItem, const System::TObject* AData);
	
public:
	HIDESBASE System::TObject* __fastcall Add(System::TObject* AItem, System::TObject* AData);
	HIDESBASE System::TObject* __fastcall Remove(System::TObject* AItem);
	__property System::TObject* Data[System::TObject* AItem] = {read=GetData, write=SetData/*, default*/};
public:
	#pragma option push -w-inl
	/* TBucketList.Create */ inline __fastcall TObjectBucketList(TBucketListSizes ABuckets) : TBucketList(ABuckets) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomBucketList.Destroy */ inline __fastcall virtual ~TObjectBucketList(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall RaiseListError(const AnsiString ATemplate, const System::TVarRec * AData, const int AData_Size);

}	/* namespace Contnrs */
using namespace Contnrs;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Contnrs
