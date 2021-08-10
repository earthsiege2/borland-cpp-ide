// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Variants.pas' rev: 6.00

#ifndef VariantsHPP
#define VariantsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysUtils.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Variants
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TVariantRelationship { vrEqual, vrLessThan, vrGreaterThan, vrNotEqual };
#pragma option pop

#pragma option push -b-
enum TVarCompareResult { crLessThan, crEqual, crGreaterThan };
#pragma option pop

class DELPHICLASS TCustomVariantType;
class PASCALIMPLEMENTATION TCustomVariantType : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Word FVarType;
	
protected:
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	void __fastcall SimplisticClear(TVarData &V);
	void __fastcall SimplisticCopy(TVarData &Dest, const TVarData &Source, const bool Indirect = false);
	void __fastcall RaiseInvalidOp(void);
	void __fastcall RaiseCastError(void);
	void __fastcall RaiseDispError(void);
	virtual bool __fastcall LeftPromotion(const TVarData &V, const int Operator, /* out */ Word &RequiredVarType);
	virtual bool __fastcall RightPromotion(const TVarData &V, const int Operator, /* out */ Word &RequiredVarType);
	virtual bool __fastcall OlePromotion(const TVarData &V, /* out */ Word &RequiredVarType);
	virtual void __fastcall DispInvoke(TVarData &Dest, const TVarData &Source, System::PCallDesc CallDesc, void * Params);
	void __fastcall VarDataInit(TVarData &Dest);
	void __fastcall VarDataClear(TVarData &Dest);
	void __fastcall VarDataCopy(TVarData &Dest, const TVarData &Source);
	void __fastcall VarDataCopyNoInd(TVarData &Dest, const TVarData &Source);
	void __fastcall VarDataCast(TVarData &Dest, const TVarData &Source);
	void __fastcall VarDataCastTo(TVarData &Dest, const TVarData &Source, const Word AVarType)/* overload */;
	void __fastcall VarDataCastTo(TVarData &Dest, const Word AVarType)/* overload */;
	void __fastcall VarDataCastToOleStr(TVarData &Dest);
	void __fastcall VarDataFromStr(TVarData &V, const AnsiString Value);
	void __fastcall VarDataFromOleStr(TVarData &V, const WideString Value);
	AnsiString __fastcall VarDataToStr(const TVarData &V);
	bool __fastcall VarDataIsEmptyParam(const TVarData &V);
	bool __fastcall VarDataIsByRef(const TVarData &V);
	bool __fastcall VarDataIsArray(const TVarData &V);
	bool __fastcall VarDataIsOrdinal(const TVarData &V);
	bool __fastcall VarDataIsFloat(const TVarData &V);
	bool __fastcall VarDataIsNumeric(const TVarData &V);
	bool __fastcall VarDataIsStr(const TVarData &V);
	
public:
	__fastcall TCustomVariantType(void)/* overload */;
	__fastcall TCustomVariantType(Word RequestedVarType)/* overload */;
	__fastcall virtual ~TCustomVariantType(void);
	__property Word VarType = {read=FVarType, nodefault};
	virtual bool __fastcall IsClear(const TVarData &V);
	virtual void __fastcall Cast(TVarData &Dest, const TVarData &Source);
	virtual void __fastcall CastTo(TVarData &Dest, const TVarData &Source, const Word AVarType);
	virtual void __fastcall CastToOle(TVarData &Dest, const TVarData &Source);
	virtual void __fastcall Clear(TVarData &V) = 0 ;
	virtual void __fastcall Copy(TVarData &Dest, const TVarData &Source, const bool Indirect) = 0 ;
	virtual void __fastcall BinaryOp(TVarData &Left, const TVarData &Right, const int Operator);
	virtual void __fastcall UnaryOp(TVarData &Right, const int Operator);
	virtual bool __fastcall CompareOp(const TVarData &Left, const TVarData &Right, const int Operator);
	virtual void __fastcall Compare(const TVarData &Left, const TVarData &Right, TVarCompareResult &Relationship);
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


typedef TMetaClass*TCustomVariantTypeClass;

typedef DynamicArray<TVarData >  TVarDataArray;

__interface IVarInvokeable;
typedef System::DelphiInterface<IVarInvokeable> _di_IVarInvokeable;
__interface INTERFACE_UUID("{1CB65C52-BBCB-41A6-9E58-7FB916BEEB2D}") IVarInvokeable  : public IInterface 
{
	
public:
	virtual bool __fastcall DoFunction(TVarData &Dest, const TVarData &V, const AnsiString Name, const TVarDataArray Arguments) = 0 ;
	virtual bool __fastcall DoProcedure(const TVarData &V, const AnsiString Name, const TVarDataArray Arguments) = 0 ;
	virtual bool __fastcall GetProperty(TVarData &Dest, const TVarData &V, const AnsiString Name) = 0 ;
	virtual bool __fastcall SetProperty(const TVarData &V, const AnsiString Name, const TVarData &Value) = 0 ;
};

class DELPHICLASS TInvokeableVariantType;
class PASCALIMPLEMENTATION TInvokeableVariantType : public TCustomVariantType 
{
	typedef TCustomVariantType inherited;
	
protected:
	virtual void __fastcall DispInvoke(TVarData &Dest, const TVarData &Source, System::PCallDesc CallDesc, void * Params);
	
public:
	virtual bool __fastcall DoFunction(TVarData &Dest, const TVarData &V, const AnsiString Name, const TVarDataArray Arguments);
	virtual bool __fastcall DoProcedure(const TVarData &V, const AnsiString Name, const TVarDataArray Arguments);
	virtual bool __fastcall GetProperty(TVarData &Dest, const TVarData &V, const AnsiString Name);
	virtual bool __fastcall SetProperty(const TVarData &V, const AnsiString Name, const TVarData &Value);
public:
	#pragma option push -w-inl
	/* TCustomVariantType.Create */ inline __fastcall TInvokeableVariantType(void)/* overload */ : TCustomVariantType() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomVariantType.Destroy */ inline __fastcall virtual ~TInvokeableVariantType(void) { }
	#pragma option pop
	
private:
	void *__IVarInvokeable;	/* Variants::IVarInvokeable */
	
public:
	operator IVarInvokeable*(void) { return (IVarInvokeable*)&__IVarInvokeable; }
	
};


__interface IVarInstanceReference;
typedef System::DelphiInterface<IVarInstanceReference> _di_IVarInstanceReference;
__interface INTERFACE_UUID("{5C176802-3F89-428D-850E-9F54F50C2293}") IVarInstanceReference  : public IInterface 
{
	
public:
	virtual System::TObject* __fastcall GetInstance(const TVarData &V) = 0 ;
};

typedef void __fastcall (*TAnyProc)(TVarData &V);

typedef void __cdecl (*TVarDispProc)(System::PVariant Dest, const Variant &Source, System::PCallDesc CallDesc, void * Params);

class DELPHICLASS EVariantInvalidOpError;
class PASCALIMPLEMENTATION EVariantInvalidOpError : public Sysutils::EVariantError 
{
	typedef Sysutils::EVariantError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EVariantInvalidOpError(const AnsiString Msg) : Sysutils::EVariantError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EVariantInvalidOpError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::EVariantError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EVariantInvalidOpError(int Ident)/* overload */ : Sysutils::EVariantError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EVariantInvalidOpError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::EVariantError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EVariantInvalidOpError(const AnsiString Msg, int AHelpContext) : Sysutils::EVariantError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EVariantInvalidOpError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::EVariantError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EVariantInvalidOpError(int Ident, int AHelpContext)/* overload */ : Sysutils::EVariantError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EVariantInvalidOpError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::EVariantError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EVariantInvalidOpError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EVariantTypeCastError;
class PASCALIMPLEMENTATION EVariantTypeCastError : public Sysutils::EVariantError 
{
	typedef Sysutils::EVariantError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EVariantTypeCastError(const AnsiString Msg) : Sysutils::EVariantError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EVariantTypeCastError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::EVariantError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EVariantTypeCastError(int Ident)/* overload */ : Sysutils::EVariantError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EVariantTypeCastError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::EVariantError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EVariantTypeCastError(const AnsiString Msg, int AHelpContext) : Sysutils::EVariantError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EVariantTypeCastError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::EVariantError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EVariantTypeCastError(int Ident, int AHelpContext)/* overload */ : Sysutils::EVariantError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EVariantTypeCastError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::EVariantError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EVariantTypeCastError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EVariantOverflowError;
class PASCALIMPLEMENTATION EVariantOverflowError : public Sysutils::EVariantError 
{
	typedef Sysutils::EVariantError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EVariantOverflowError(const AnsiString Msg) : Sysutils::EVariantError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EVariantOverflowError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::EVariantError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EVariantOverflowError(int Ident)/* overload */ : Sysutils::EVariantError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EVariantOverflowError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::EVariantError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EVariantOverflowError(const AnsiString Msg, int AHelpContext) : Sysutils::EVariantError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EVariantOverflowError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::EVariantError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EVariantOverflowError(int Ident, int AHelpContext)/* overload */ : Sysutils::EVariantError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EVariantOverflowError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::EVariantError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EVariantOverflowError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EVariantInvalidArgError;
class PASCALIMPLEMENTATION EVariantInvalidArgError : public Sysutils::EVariantError 
{
	typedef Sysutils::EVariantError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EVariantInvalidArgError(const AnsiString Msg) : Sysutils::EVariantError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EVariantInvalidArgError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::EVariantError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EVariantInvalidArgError(int Ident)/* overload */ : Sysutils::EVariantError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EVariantInvalidArgError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::EVariantError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EVariantInvalidArgError(const AnsiString Msg, int AHelpContext) : Sysutils::EVariantError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EVariantInvalidArgError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::EVariantError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EVariantInvalidArgError(int Ident, int AHelpContext)/* overload */ : Sysutils::EVariantError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EVariantInvalidArgError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::EVariantError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EVariantInvalidArgError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EVariantBadVarTypeError;
class PASCALIMPLEMENTATION EVariantBadVarTypeError : public Sysutils::EVariantError 
{
	typedef Sysutils::EVariantError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EVariantBadVarTypeError(const AnsiString Msg) : Sysutils::EVariantError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EVariantBadVarTypeError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::EVariantError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EVariantBadVarTypeError(int Ident)/* overload */ : Sysutils::EVariantError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EVariantBadVarTypeError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::EVariantError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EVariantBadVarTypeError(const AnsiString Msg, int AHelpContext) : Sysutils::EVariantError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EVariantBadVarTypeError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::EVariantError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EVariantBadVarTypeError(int Ident, int AHelpContext)/* overload */ : Sysutils::EVariantError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EVariantBadVarTypeError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::EVariantError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EVariantBadVarTypeError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EVariantBadIndexError;
class PASCALIMPLEMENTATION EVariantBadIndexError : public Sysutils::EVariantError 
{
	typedef Sysutils::EVariantError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EVariantBadIndexError(const AnsiString Msg) : Sysutils::EVariantError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EVariantBadIndexError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::EVariantError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EVariantBadIndexError(int Ident)/* overload */ : Sysutils::EVariantError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EVariantBadIndexError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::EVariantError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EVariantBadIndexError(const AnsiString Msg, int AHelpContext) : Sysutils::EVariantError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EVariantBadIndexError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::EVariantError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EVariantBadIndexError(int Ident, int AHelpContext)/* overload */ : Sysutils::EVariantError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EVariantBadIndexError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::EVariantError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EVariantBadIndexError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EVariantArrayLockedError;
class PASCALIMPLEMENTATION EVariantArrayLockedError : public Sysutils::EVariantError 
{
	typedef Sysutils::EVariantError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EVariantArrayLockedError(const AnsiString Msg) : Sysutils::EVariantError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EVariantArrayLockedError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::EVariantError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EVariantArrayLockedError(int Ident)/* overload */ : Sysutils::EVariantError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EVariantArrayLockedError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::EVariantError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EVariantArrayLockedError(const AnsiString Msg, int AHelpContext) : Sysutils::EVariantError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EVariantArrayLockedError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::EVariantError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EVariantArrayLockedError(int Ident, int AHelpContext)/* overload */ : Sysutils::EVariantError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EVariantArrayLockedError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::EVariantError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EVariantArrayLockedError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EVariantNotAnArrayError;
class PASCALIMPLEMENTATION EVariantNotAnArrayError : public Sysutils::EVariantError 
{
	typedef Sysutils::EVariantError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EVariantNotAnArrayError(const AnsiString Msg) : Sysutils::EVariantError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EVariantNotAnArrayError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::EVariantError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EVariantNotAnArrayError(int Ident)/* overload */ : Sysutils::EVariantError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EVariantNotAnArrayError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::EVariantError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EVariantNotAnArrayError(const AnsiString Msg, int AHelpContext) : Sysutils::EVariantError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EVariantNotAnArrayError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::EVariantError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EVariantNotAnArrayError(int Ident, int AHelpContext)/* overload */ : Sysutils::EVariantError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EVariantNotAnArrayError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::EVariantError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EVariantNotAnArrayError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EVariantArrayCreateError;
class PASCALIMPLEMENTATION EVariantArrayCreateError : public Sysutils::EVariantError 
{
	typedef Sysutils::EVariantError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EVariantArrayCreateError(const AnsiString Msg) : Sysutils::EVariantError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EVariantArrayCreateError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::EVariantError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EVariantArrayCreateError(int Ident)/* overload */ : Sysutils::EVariantError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EVariantArrayCreateError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::EVariantError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EVariantArrayCreateError(const AnsiString Msg, int AHelpContext) : Sysutils::EVariantError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EVariantArrayCreateError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::EVariantError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EVariantArrayCreateError(int Ident, int AHelpContext)/* overload */ : Sysutils::EVariantError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EVariantArrayCreateError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::EVariantError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EVariantArrayCreateError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EVariantNotImplError;
class PASCALIMPLEMENTATION EVariantNotImplError : public Sysutils::EVariantError 
{
	typedef Sysutils::EVariantError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EVariantNotImplError(const AnsiString Msg) : Sysutils::EVariantError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EVariantNotImplError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::EVariantError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EVariantNotImplError(int Ident)/* overload */ : Sysutils::EVariantError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EVariantNotImplError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::EVariantError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EVariantNotImplError(const AnsiString Msg, int AHelpContext) : Sysutils::EVariantError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EVariantNotImplError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::EVariantError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EVariantNotImplError(int Ident, int AHelpContext)/* overload */ : Sysutils::EVariantError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EVariantNotImplError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::EVariantError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EVariantNotImplError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EVariantOutOfMemoryError;
class PASCALIMPLEMENTATION EVariantOutOfMemoryError : public Sysutils::EVariantError 
{
	typedef Sysutils::EVariantError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EVariantOutOfMemoryError(const AnsiString Msg) : Sysutils::EVariantError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EVariantOutOfMemoryError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::EVariantError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EVariantOutOfMemoryError(int Ident)/* overload */ : Sysutils::EVariantError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EVariantOutOfMemoryError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::EVariantError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EVariantOutOfMemoryError(const AnsiString Msg, int AHelpContext) : Sysutils::EVariantError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EVariantOutOfMemoryError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::EVariantError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EVariantOutOfMemoryError(int Ident, int AHelpContext)/* overload */ : Sysutils::EVariantError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EVariantOutOfMemoryError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::EVariantError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EVariantOutOfMemoryError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EVariantUnexpectedError;
class PASCALIMPLEMENTATION EVariantUnexpectedError : public Sysutils::EVariantError 
{
	typedef Sysutils::EVariantError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EVariantUnexpectedError(const AnsiString Msg) : Sysutils::EVariantError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EVariantUnexpectedError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::EVariantError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EVariantUnexpectedError(int Ident)/* overload */ : Sysutils::EVariantError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EVariantUnexpectedError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::EVariantError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EVariantUnexpectedError(const AnsiString Msg, int AHelpContext) : Sysutils::EVariantError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EVariantUnexpectedError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::EVariantError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EVariantUnexpectedError(int Ident, int AHelpContext)/* overload */ : Sysutils::EVariantError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EVariantUnexpectedError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::EVariantError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EVariantUnexpectedError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EVariantDispatchError;
class PASCALIMPLEMENTATION EVariantDispatchError : public Sysutils::EVariantError 
{
	typedef Sysutils::EVariantError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EVariantDispatchError(const AnsiString Msg) : Sysutils::EVariantError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EVariantDispatchError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::EVariantError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EVariantDispatchError(int Ident)/* overload */ : Sysutils::EVariantError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EVariantDispatchError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::EVariantError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EVariantDispatchError(const AnsiString Msg, int AHelpContext) : Sysutils::EVariantError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EVariantDispatchError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::EVariantError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EVariantDispatchError(int Ident, int AHelpContext)/* overload */ : Sysutils::EVariantError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EVariantDispatchError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::EVariantError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EVariantDispatchError(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TVarDispProc VarDispProc;
extern PACKAGE TAnyProc ClearAnyProc;
extern PACKAGE TAnyProc ChangeAnyProc;
extern PACKAGE TAnyProc RefAnyProc;
extern PACKAGE bool PackVarCreation;
extern PACKAGE void __fastcall VarCastError(void)/* overload */;
extern PACKAGE void __fastcall VarCastError(const Word ASourceType, const Word ADestType)/* overload */;
extern PACKAGE void __fastcall VarInvalidOp(void);
extern PACKAGE void __fastcall VarOverflowError(const Word ASourceType, const Word ADestType);
extern PACKAGE void __fastcall VarArrayCreateError(void);
extern PACKAGE void __fastcall VarResultCheck(HRESULT AResult)/* overload */;
extern PACKAGE void __fastcall VarResultCheck(HRESULT AResult, Word ASourceType, Word ADestType)/* overload */;
extern PACKAGE void __fastcall HandleConversionException(const Word ASourceType, const Word ADestType);
extern PACKAGE void __fastcall VarCopyNoInd(Variant &Dest, const Variant &Source);
extern PACKAGE AnsiString __fastcall VarTypeAsText(const Word AType);
extern PACKAGE Word __fastcall VarType(const Variant &V);
extern PACKAGE PVarData __fastcall FindVarData(const Variant &V);
extern PACKAGE Variant __fastcall VarAsType(const Variant &V, Word AVarType);
extern PACKAGE bool __fastcall VarIsType(const Variant &V, Word AVarType)/* overload */;
extern PACKAGE bool __fastcall VarIsType(const Variant &V, const Word * AVarTypes, const int AVarTypes_Size)/* overload */;
extern PACKAGE bool __fastcall VarIsClear(const Variant &V);
extern PACKAGE bool __fastcall VarIsCustom(const Variant &V);
extern PACKAGE bool __fastcall VarIsOrdinal(const Variant &V);
extern PACKAGE bool __fastcall VarIsFloat(const Variant &V);
extern PACKAGE bool __fastcall VarIsNumeric(const Variant &V);
extern PACKAGE bool __fastcall VarIsStr(const Variant &V);
extern PACKAGE bool __fastcall VarIsEmpty(const Variant &V);
extern PACKAGE void __fastcall VarCheckEmpty(const Variant &V);
extern PACKAGE bool __fastcall VarIsNull(const Variant &V);
extern PACKAGE AnsiString __fastcall VarToStr(const Variant &V);
extern PACKAGE AnsiString __fastcall VarToStrDef(const Variant &V, const AnsiString ADefault);
extern PACKAGE WideString __fastcall VarToWideStr(const Variant &V);
extern PACKAGE WideString __fastcall VarToWideStrDef(const Variant &V, const WideString ADefault);
extern PACKAGE Variant __fastcall VarFromDateTime(const System::TDateTime DateTime);
extern PACKAGE System::TDateTime __fastcall VarToDateTime(const Variant &V);
extern PACKAGE bool __fastcall VarInRange(const Variant &AValue, const Variant &AMin, const Variant &AMax);
extern PACKAGE Variant __fastcall VarEnsureRange(const Variant &AValue, const Variant &AMin, const Variant &AMax);
extern PACKAGE bool __fastcall VarSameValue(const Variant &A, const Variant &B);
extern PACKAGE TVariantRelationship __fastcall VarCompareValue(const Variant &A, const Variant &B);
extern PACKAGE bool __fastcall VarIsEmptyParam(const Variant &V);
extern PACKAGE bool __fastcall VarIsByRef(const Variant &V);
extern PACKAGE bool __fastcall VarSupports(const Variant &V, const GUID &IID, /* out */ void *Intf)/* overload */;
extern PACKAGE bool __fastcall VarSupports(const Variant &V, const GUID &IID)/* overload */;
extern PACKAGE Variant __fastcall VarArrayCreate(const int * Bounds, const int Bounds_Size, Word AVarType);
extern PACKAGE Variant __fastcall VarArrayOf(const Variant * Values, const int Values_Size);
extern PACKAGE int __fastcall VarArrayDimCount(const Variant &A);
extern PACKAGE int __fastcall VarArrayLowBound(const Variant &A, int Dim);
extern PACKAGE int __fastcall VarArrayHighBound(const Variant &A, int Dim);
extern PACKAGE void * __fastcall VarArrayLock(const Variant &A);
extern PACKAGE void __fastcall VarArrayUnlock(const Variant &A);
extern PACKAGE Variant __fastcall VarArrayRef(const Variant &A);
extern PACKAGE bool __fastcall VarIsArray(const Variant &A)/* overload */;
extern PACKAGE bool __fastcall VarIsArray(const Variant &A, bool AResolveByRef)/* overload */;
extern PACKAGE bool __fastcall VarTypeIsValidArrayType(const Word AVarType);
extern PACKAGE bool __fastcall VarTypeIsValidElementType(const Word AVarType);
extern PACKAGE Variant __fastcall VarArrayGet(const Variant &A, const int * Indices, const int Indices_Size);
extern PACKAGE void __fastcall VarArrayPut(Variant &A, const Variant &Value, const int * Indices, const int Indices_Size);
extern PACKAGE void __fastcall DynArrayToVariant(Variant &V, const void * DynArray, void * TypeInfo);
extern PACKAGE void __fastcall DynArrayFromVariant(void * &DynArray, const Variant &V, void * TypeInfo);
extern PACKAGE bool __fastcall FindCustomVariantType(const Word AVarType, /* out */ TCustomVariantType* &CustomVariantType)/* overload */;
extern PACKAGE bool __fastcall FindCustomVariantType(const AnsiString TypeName, /* out */ TCustomVariantType* &CustomVariantType)/* overload */;
extern PACKAGE Variant __fastcall Unassigned();
extern PACKAGE Variant __fastcall Null();

}	/* namespace Variants */
using namespace Variants;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Variants
