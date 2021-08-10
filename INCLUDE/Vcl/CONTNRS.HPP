// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Contnrs.pas' rev: 5.00

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
	HIDESBASE int __fastcall Remove(System::TObject* AObject);
	HIDESBASE int __fastcall IndexOf(System::TObject* AObject);
	int __fastcall FindInstanceOf(TMetaClass* AClass, bool AExact, int AStartAt);
	HIDESBASE void __fastcall Insert(int Index, System::TObject* AObject);
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
	HIDESBASE int __fastcall Remove(Classes::TComponent* AComponent);
	HIDESBASE int __fastcall IndexOf(Classes::TComponent* AComponent);
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
	
protected:
	TMetaClass* __fastcall GetItems(int Index);
	void __fastcall SetItems(int Index, TMetaClass* AClass);
	
public:
	HIDESBASE int __fastcall Add(TMetaClass* aClass);
	HIDESBASE int __fastcall Remove(TMetaClass* aClass);
	HIDESBASE int __fastcall IndexOf(TMetaClass* aClass);
	HIDESBASE void __fastcall Insert(int Index, TMetaClass* aClass);
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
	void __fastcall Push(void * AItem);
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
	HIDESBASE void __fastcall Push(System::TObject* AObject);
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
	HIDESBASE void __fastcall Push(System::TObject* AObject);
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


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Contnrs */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Contnrs;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Contnrs
