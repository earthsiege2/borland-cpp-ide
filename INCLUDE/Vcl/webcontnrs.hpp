// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WebContnrs.pas' rev: 6.00

#ifndef WebContnrsHPP
#define WebContnrsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Webcontnrs
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS ENamedVariantsError;
class PASCALIMPLEMENTATION ENamedVariantsError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ENamedVariantsError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ENamedVariantsError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ENamedVariantsError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ENamedVariantsError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ENamedVariantsError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ENamedVariantsError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ENamedVariantsError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ENamedVariantsError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ENamedVariantsError(void) { }
	#pragma option pop
	
};


class DELPHICLASS TAbstractNamedVariants;
class PASCALIMPLEMENTATION TAbstractNamedVariants : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	int FUpdateCount;
	AnsiString __fastcall GetName(int Index);
	Variant __fastcall GetValue(const AnsiString Name);
	void __fastcall ReadData(Classes::TReader* Reader);
	void __fastcall SetValue(const AnsiString Name, const Variant &Value);
	void __fastcall WriteData(Classes::TWriter* Writer);
	void __fastcall AddNamedVariants(TAbstractNamedVariants* ANamedVariants);
	Variant __fastcall GetVariant(int Index);
	void __fastcall PutVariant(int Index, const Variant &Value);
	
protected:
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	void __fastcall Error(const AnsiString Msg, int Data)/* overload */;
	virtual bool __fastcall Get(int Index, /* out */ AnsiString &AName, /* out */ Variant &AValue) = 0 ;
	virtual int __fastcall GetCapacity(void);
	virtual int __fastcall GetCount(void) = 0 ;
	virtual void __fastcall Put(int Index, const AnsiString AName, const Variant &AValue) = 0 ;
	virtual void __fastcall SetCapacity(int NewCapacity);
	virtual void __fastcall SetUpdateState(bool Updating);
	__property int UpdateCount = {read=FUpdateCount, nodefault};
	virtual int __fastcall CompareStrings(const AnsiString S1, const AnsiString S2);
	
public:
	__fastcall virtual ~TAbstractNamedVariants(void);
	virtual int __fastcall Add(const AnsiString S, const Variant &AValue);
	void __fastcall Append(const AnsiString S, const Variant &AValue);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall BeginUpdate(void);
	virtual void __fastcall Clear(void) = 0 ;
	virtual void __fastcall Delete(int Index) = 0 ;
	void __fastcall EndUpdate(void);
	bool __fastcall Equals(TAbstractNamedVariants* ANamedVariants);
	virtual void __fastcall Exchange(int Index1, int Index2);
	virtual int __fastcall IndexOfName(const AnsiString Name);
	virtual void __fastcall Insert(int Index, const AnsiString S, const Variant &AValue) = 0 ;
	virtual void __fastcall Move(int CurIndex, int NewIndex);
	__property int Capacity = {read=GetCapacity, write=SetCapacity, nodefault};
	__property int Count = {read=GetCount, nodefault};
	__property AnsiString Names[int Index] = {read=GetName};
	__property Variant Values[AnsiString Name] = {read=GetValue, write=SetValue};
	__property Variant Variants[int Index] = {read=GetVariant, write=PutVariant};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TAbstractNamedVariants(void) : Classes::TPersistent() { }
	#pragma option pop
	
};


struct TNamedVariantItem;
typedef TNamedVariantItem *PNamedVariantItem;

struct TNamedVariantItem
{
	AnsiString FString;
	Variant FVariant;
} ;

typedef TNamedVariantItem TNamedVariantList[83333334];

typedef TNamedVariantItem *PNamedVariantList;

class DELPHICLASS TNamedVariantsList;
class PASCALIMPLEMENTATION TNamedVariantsList : public TAbstractNamedVariants 
{
	typedef TAbstractNamedVariants inherited;
	
private:
	TNamedVariantItem *FList;
	int FCount;
	int FCapacity;
	void __fastcall Grow(void);
	
protected:
	virtual void __fastcall SetCapacity(int NewCapacity);
	virtual int __fastcall GetCapacity(void);
	virtual bool __fastcall Get(int Index, /* out */ AnsiString &AName, /* out */ Variant &AValue);
	virtual void __fastcall Put(int Index, const AnsiString AName, const Variant &AValue);
	virtual int __fastcall GetCount(void);
	
public:
	__fastcall virtual ~TNamedVariantsList(void);
	virtual void __fastcall Clear(void);
	virtual void __fastcall Delete(int Index);
	virtual void __fastcall Insert(int Index, const AnsiString S, const Variant &AValue);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TNamedVariantsList(void) : TAbstractNamedVariants() { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Webcontnrs */
using namespace Webcontnrs;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WebContnrs
