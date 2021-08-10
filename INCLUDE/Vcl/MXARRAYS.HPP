// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'mxarrays.pas' rev: 5.00

#ifndef mxarraysHPP
#define mxarraysHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <mxConsts.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Mxarrays
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EArrayError;
class PASCALIMPLEMENTATION EArrayError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EArrayError(const AnsiString Msg) : Sysutils::Exception(Msg
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EArrayError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EArrayError(int Ident)/* overload */ : Sysutils::Exception(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EArrayError(int Ident, const System::TVarRec * Args, 
		const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EArrayError(const AnsiString Msg, int AHelpContext) : 
		Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EArrayError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EArrayError(int Ident, int AHelpContext)/* overload */
		 : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EArrayError(System::PResStringRec ResStringRec, 
		const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EArrayError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EUnsupportedTypeError;
class PASCALIMPLEMENTATION EUnsupportedTypeError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EUnsupportedTypeError(const AnsiString Msg) : Sysutils::Exception(
		Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EUnsupportedTypeError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EUnsupportedTypeError(int Ident)/* overload */ : Sysutils::Exception(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EUnsupportedTypeError(int Ident, const System::TVarRec 
		* Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EUnsupportedTypeError(const AnsiString Msg, int AHelpContext
		) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EUnsupportedTypeError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EUnsupportedTypeError(int Ident, int AHelpContext)/* overload */
		 : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EUnsupportedTypeError(System::PResStringRec ResStringRec
		, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EUnsupportedTypeError(void) { }
	#pragma option pop
	
};


class DELPHICLASS ELowCapacityError;
class PASCALIMPLEMENTATION ELowCapacityError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ELowCapacityError(const AnsiString Msg) : Sysutils::Exception(
		Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ELowCapacityError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ELowCapacityError(int Ident)/* overload */ : Sysutils::Exception(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ELowCapacityError(int Ident, const System::TVarRec * 
		Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ELowCapacityError(const AnsiString Msg, int AHelpContext
		) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ELowCapacityError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ELowCapacityError(int Ident, int AHelpContext)/* overload */
		 : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ELowCapacityError(System::PResStringRec ResStringRec
		, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ELowCapacityError(void) { }
	#pragma option pop
	
};


typedef int __fastcall (*TCompareProc)(void *item1, void *item2);

#pragma option push -b-
enum TSortOrder { tsNone, tsAscending, tsDescending };
#pragma option pop

#pragma option push -b-
enum TArrayFlags { afOwnsData, afAutoSize, afCanCompare, afSortUnique };
#pragma option pop

typedef Set<TArrayFlags, afOwnsData, afSortUnique>  TArrayFlagSet;

#pragma option push -b-
enum TDuplicates { dupIgnore, dupAccept, dupError };
#pragma option pop

struct TStringItem
{
	AnsiString FString;
	System::TObject* FObject;
} ;

class DELPHICLASS TBaseArray;
class PASCALIMPLEMENTATION TBaseArray : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	void *FMemory;
	int FCapacity;
	int FItemSize;
	int FCount;
	TSortOrder FSortOrder;
	TArrayFlagSet FFlags;
	TDuplicates FDuplicates;
	TCompareProc FCompProc;
	void * __fastcall GetItemPtr(int index);
	void __fastcall CopyFrom(int toIndex, int numItems, void *Source);
	void __fastcall SetCount(int NewCount);
	int __fastcall GetLimit(void);
	
protected:
	bool __fastcall ValidIndex(int Index);
	bool __fastcall HasFlag(TArrayFlags aFlag);
	void __fastcall SetFlag(TArrayFlags aFlag);
	void __fastcall ClearFlag(TArrayFlags aFlag);
	void __fastcall SetAutoSize(bool aSize);
	void __fastcall BlockCopy(TBaseArray* Source, int fromIndex, int toIndex, int numitems);
	bool __fastcall GetAutoSize(void);
	bool __fastcall ValidateBounds(int atIndex, int &numItems);
	void __fastcall RemoveRange(int atIndex, int numItems);
	void __fastcall InternalHandleException(void);
	virtual void __fastcall InvalidateItems(int atIndex, int numItems);
	virtual void __fastcall SetCapacity(int NewCapacity);
	virtual void __fastcall Grow(void);
	
public:
	__fastcall virtual TBaseArray(int itemcount, int iSize);
	__fastcall virtual ~TBaseArray(void);
	void __fastcall Clear(void);
	void __fastcall InsertAt(int Index, void *Value);
	virtual void __fastcall Insert(int Index, void *Value);
	void __fastcall PutItem(int index, void *Value);
	void __fastcall GetItem(int index, void *Value);
	void __fastcall RemoveItem(int Index);
	virtual void __fastcall Delete(int Index);
	virtual void __fastcall Exchange(int Index1, int Index2);
	virtual int __fastcall IndexOf(void *Item);
	bool __fastcall FindItem(int &Index, void *Value);
	virtual void __fastcall Sort(TCompareProc Compare);
	__property TCompareProc CompareProc = {read=FCompProc, write=FCompProc};
	__property TDuplicates Duplicates = {read=FDuplicates, write=FDuplicates, nodefault};
	__property TSortOrder SortOrder = {read=FSortOrder, write=FSortOrder, nodefault};
	__property int Capacity = {read=FCapacity, write=SetCapacity, nodefault};
	__property int Limit = {read=GetLimit, write=SetCapacity, nodefault};
	__property int ItemSize = {read=FItemSize, nodefault};
	__property bool AutoSize = {read=GetAutoSize, write=SetAutoSize, nodefault};
	__property int Count = {read=FCount, write=SetCount, nodefault};
	__property void * List = {read=FMemory};
};


class DELPHICLASS TSmallIntArray;
class PASCALIMPLEMENTATION TSmallIntArray : public TBaseArray 
{
	typedef TBaseArray inherited;
	
public:
	__fastcall virtual TSmallIntArray(int itemcount, int dummy);
	HIDESBASE void __fastcall PutItem(int index, short value);
	HIDESBASE short __fastcall GetItem(int index);
	int __fastcall Add(short Value);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property short Items[int Index] = {read=GetItem, write=PutItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TBaseArray.Destroy */ inline __fastcall virtual ~TSmallIntArray(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIntArray;
class PASCALIMPLEMENTATION TIntArray : public TBaseArray 
{
	typedef TBaseArray inherited;
	
public:
	__fastcall virtual TIntArray(int itemcount, int dummy);
	HIDESBASE void __fastcall PutItem(int index, int value);
	HIDESBASE int __fastcall GetItem(int index);
	int __fastcall Add(int Value);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	bool __fastcall Find(int &Index, int Value);
	__property int Items[int Index] = {read=GetItem, write=PutItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TBaseArray.Destroy */ inline __fastcall virtual ~TIntArray(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSingleArray;
class PASCALIMPLEMENTATION TSingleArray : public TBaseArray 
{
	typedef TBaseArray inherited;
	
public:
	__fastcall virtual TSingleArray(int itemcount, int dummy);
	HIDESBASE void __fastcall PutItem(int index, float value);
	HIDESBASE float __fastcall GetItem(int index);
	int __fastcall Add(float Value);
	bool __fastcall Find(int &Index, float Value);
	virtual int __fastcall IndexOf(void *Item);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property float Items[int Index] = {read=GetItem, write=PutItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TBaseArray.Destroy */ inline __fastcall virtual ~TSingleArray(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDoubleArray;
class PASCALIMPLEMENTATION TDoubleArray : public TBaseArray 
{
	typedef TBaseArray inherited;
	
public:
	__fastcall virtual TDoubleArray(int itemcount, int dummy);
	HIDESBASE void __fastcall PutItem(int index, double value);
	HIDESBASE double __fastcall GetItem(int index);
	int __fastcall Add(double Value);
	bool __fastcall Find(int &Index, double Value);
	virtual int __fastcall IndexOf(void *Item);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property double Items[int Index] = {read=GetItem, write=PutItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TBaseArray.Destroy */ inline __fastcall virtual ~TDoubleArray(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCurrencyArray;
class PASCALIMPLEMENTATION TCurrencyArray : public TBaseArray 
{
	typedef TBaseArray inherited;
	
public:
	__fastcall virtual TCurrencyArray(int itemcount, int dummy);
	HIDESBASE void __fastcall PutItem(int index, System::Currency value);
	HIDESBASE System::Currency __fastcall GetItem(int index);
	int __fastcall Add(System::Currency Value);
	bool __fastcall Find(int &Index, System::Currency Value);
	virtual int __fastcall IndexOf(void *Item);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property System::Currency Items[int Index] = {read=GetItem, write=PutItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TBaseArray.Destroy */ inline __fastcall virtual ~TCurrencyArray(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWordArray;
class PASCALIMPLEMENTATION TWordArray : public TBaseArray 
{
	typedef TBaseArray inherited;
	
public:
	__fastcall virtual TWordArray(int itemcount, int dummy);
	HIDESBASE void __fastcall PutItem(int index, Word value);
	HIDESBASE Word __fastcall GetItem(int index);
	int __fastcall Add(Word Value);
	bool __fastcall Find(int &Index, Word Value);
	virtual int __fastcall IndexOf(void *Item);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property Word Items[int Index] = {read=GetItem, write=PutItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TBaseArray.Destroy */ inline __fastcall virtual ~TWordArray(void) { }
	#pragma option pop
	
};


class DELPHICLASS TPointerArray;
class PASCALIMPLEMENTATION TPointerArray : public TBaseArray 
{
	typedef TBaseArray inherited;
	
public:
	__fastcall virtual TPointerArray(int itemcount, int dummy);
	void __fastcall PutData(int index, void * value);
	void * __fastcall GetData(int index);
	HIDESBASE void __fastcall CopyFrom(void *Source, int toIndex, int numItems);
	void __fastcall CopyTo(void *Dest, int fromIndex, int numItems);
	virtual void __fastcall InvalidateItems(int atIndex, int numItems);
	virtual void * __fastcall CloneItem(void * item);
	virtual void __fastcall FreeItem(void * item);
	__property void * AsPtr[int Index] = {read=GetData, write=PutData};
	__property void * Data[int Index] = {read=GetData, write=PutData};
public:
	#pragma option push -w-inl
	/* TBaseArray.Destroy */ inline __fastcall virtual ~TPointerArray(void) { }
	#pragma option pop
	
};


class DELPHICLASS TStringArray;
class PASCALIMPLEMENTATION TStringArray : public TBaseArray 
{
	typedef TBaseArray inherited;
	
private:
	void __fastcall ExchangeItems(int Index1, int Index2);
	void __fastcall QuickSort(int L, int R);
	void __fastcall InsertItem(int Index, const AnsiString S);
	void __fastcall AddStrings(TStringArray* Strings);
	
protected:
	AnsiString __fastcall GetString(int Index);
	void __fastcall PutString(int Index, const AnsiString S);
	System::TObject* __fastcall GetObject(int Index);
	void __fastcall PutObject(int Index, System::TObject* AObject);
	virtual void __fastcall InvalidateItems(int atIndex, int numItems);
	virtual void __fastcall Grow(void);
	
public:
	__fastcall virtual TStringArray(int itemcount, int dummy);
	int __fastcall Add(const AnsiString S);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall Exchange(int Index1, int Index2);
	bool __fastcall Find(AnsiString S, int &Index);
	virtual int __fastcall IndexOf(void *Item);
	virtual void __fastcall Sort(TCompareProc Compare);
	virtual void __fastcall Insert(int Index, void *Value);
	__property AnsiString Strings[int Index] = {read=GetString, write=PutString/*, default*/};
public:
	#pragma option push -w-inl
	/* TBaseArray.Destroy */ inline __fastcall virtual ~TStringArray(void) { }
	#pragma option pop
	
};


typedef int TMatrixNDX;

typedef int TDynArrayNDX;

typedef TSmallIntArray* TMatrixElements[536870911];

typedef TSmallIntArray* *PMatrixElements;

class DELPHICLASS EDynArrayRangeError;
class PASCALIMPLEMENTATION EDynArrayRangeError : public Sysutils::ERangeError 
{
	typedef Sysutils::ERangeError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EDynArrayRangeError(const AnsiString Msg) : Sysutils::ERangeError(
		Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EDynArrayRangeError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : Sysutils::ERangeError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EDynArrayRangeError(int Ident)/* overload */ : Sysutils::ERangeError(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EDynArrayRangeError(int Ident, const System::TVarRec 
		* Args, const int Args_Size)/* overload */ : Sysutils::ERangeError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EDynArrayRangeError(const AnsiString Msg, int AHelpContext
		) : Sysutils::ERangeError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EDynArrayRangeError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::ERangeError(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EDynArrayRangeError(int Ident, int AHelpContext)/* overload */
		 : Sysutils::ERangeError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EDynArrayRangeError(System::PResStringRec ResStringRec
		, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::ERangeError(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EDynArrayRangeError(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTwoDimArray;
class PASCALIMPLEMENTATION TTwoDimArray : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TDynArrayNDX FRows;
	TMatrixNDX FColumns;
	int FMemAllocated;
	short __fastcall GetElement(TDynArrayNDX row, TMatrixNDX column);
	void __fastcall SetElement(TDynArrayNDX row, TMatrixNDX column, const short NewValue);
	
protected:
	TSmallIntArray* *mtxElements;
	
public:
	__fastcall TTwoDimArray(void);
	__fastcall virtual ~TTwoDimArray(void);
	void __fastcall SetSize(TDynArrayNDX NumRows, TMatrixNDX NumColumns);
	__property TDynArrayNDX rows = {read=FRows, nodefault};
	__property TMatrixNDX columns = {read=FColumns, nodefault};
	__property short Element[TDynArrayNDX row][TMatrixNDX column] = {read=GetElement, write=SetElement/*
		, default*/};
};


typedef int TIndexNDX;

typedef TSmallIntArray* TIndexElements[536870911];

typedef TSmallIntArray* *PIndexElements;

class DELPHICLASS TIndexArray;
class PASCALIMPLEMENTATION TIndexArray : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	int FMemAllocated;
	int FCount;
	TIndexNDX FCapacity;
	bool FAutosize;
	TSmallIntArray* __fastcall GetElement(TIndexNDX Element);
	void __fastcall SetElement(TIndexNDX Element, const TSmallIntArray* NewValue);
	
protected:
	TSmallIntArray* *idxElements;
	
public:
	__fastcall TIndexArray(void);
	__fastcall virtual ~TIndexArray(void);
	void __fastcall SetSize(TIndexNDX Elements);
	void __fastcall Expand(void);
	int __fastcall Add(const TSmallIntArray* NewValue);
	__property int MemoryUsage = {read=FMemAllocated, nodefault};
	__property bool Autosize = {read=FAutosize, write=FAutosize, nodefault};
	__property TIndexNDX Capacity = {read=FCapacity, write=SetSize, nodefault};
	__property int Count = {read=FCount, nodefault};
	__property TSmallIntArray* Items[TIndexNDX Element] = {read=GetElement, write=SetElement/*, default
		*/};
};


class DELPHICLASS TCustomArray;
class PASCALIMPLEMENTATION TCustomArray : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	int FDataType;
	void *FArray;
	AnsiString FBlankStringVal;
	Variant FBlankDateVal;
	Word FBlankBoolVal;
	int FBlankCount;
	void __fastcall UnsupportedTypeError(int vType);
	
protected:
	Variant __fastcall GetItem(int Index);
	void __fastcall SetItem(int Index, const Variant &Value);
	TCompareProc __fastcall GetCompProc(void);
	void __fastcall SetCompProc(TCompareProc Proc);
	int __fastcall GetMemberCount(void);
	bool __fastcall GetSort(void);
	void __fastcall SetSort(bool Value);
	TDuplicates __fastcall GetDups(void);
	void __fastcall SetDups(TDuplicates Value);
	
public:
	__fastcall TCustomArray(int Items, int VarType);
	__fastcall virtual ~TCustomArray(void);
	Variant __fastcall ConvertVar(const Variant &Value);
	int __fastcall Add(const Variant &Value);
	bool __fastcall IsBlank(int Index);
	virtual int __fastcall MemoryUsage(void);
	void __fastcall SetSize(int size);
	int __fastcall IndexOf(const Variant &Value);
	void __fastcall Assign(TCustomArray* Value, bool bSorted, bool bUnique);
	double __fastcall GetDouble(int Index);
	System::Currency __fastcall GetCurrency(int Index);
	int __fastcall GetInteger(int Index);
	__property void * List = {read=FArray};
	__property TDuplicates Duplicates = {read=GetDups, write=SetDups, nodefault};
	__property bool Sorted = {read=GetSort, write=SetSort, nodefault};
	__property AnsiString BlankStringVal = {read=FBlankStringVal, write=FBlankStringVal};
	__property Variant BlankDateVal = {read=FBlankDateVal, write=FBlankDateVal};
	__property Word BlankBoolVal = {read=FBlankBoolVal, write=FBlankBoolVal, nodefault};
	__property TCompareProc CompareProc = {read=GetCompProc, write=SetCompProc};
	__property int MemberCount = {read=GetMemberCount, nodefault};
	__property int DataType = {read=FDataType, nodefault};
	__property int BlankCount = {read=FBlankCount, nodefault};
	__property Variant Items[int I] = {read=GetItem, write=SetItem/*, default*/};
};


class DELPHICLASS TThreadCustomArray;
class PASCALIMPLEMENTATION TThreadCustomArray : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TCustomArray* FCustomArray;
	_RTL_CRITICAL_SECTION FLock;
	
public:
	__fastcall TThreadCustomArray(int Items, int VarType);
	__fastcall virtual ~TThreadCustomArray(void);
	int __fastcall Add(const Variant &Item);
	TCustomArray* __fastcall LockArray(void);
	Variant __fastcall GetItem(int Index);
	int __fastcall MemoryUsage(void);
	void __fastcall UnlockArray(void);
};


//-- var, const, procedure ---------------------------------------------------
static const int vMaxRow = 0x3ffffff8;
static const int vMaxCol = 0x1ffffffe;
extern PACKAGE void __fastcall SetMemoryCapacity(int Value);
extern PACKAGE int __fastcall GetMemoryCapacity(void);

}	/* namespace Mxarrays */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Mxarrays;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// mxarrays
