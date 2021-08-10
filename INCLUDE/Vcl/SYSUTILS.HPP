// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SysUtils.pas' rev: 6.00

#ifndef SysUtilsHPP
#define SysUtilsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysConst.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
namespace Sysutils {
extern PACKAGE System::Set<Byte, 0, 255>  LeadBytes;
} // namespace Sysutils

namespace Sysutils
{
//-- type declarations -------------------------------------------------------
typedef Set<char, 0, 255>  TSysCharSet;

typedef Set<Shortint, 0, 31>  TIntegerSet;

#pragma pack(push, 1)
struct WordRec
{
	
	union
	{
		struct 
		{
			Byte Bytes[2];
			
		};
		struct 
		{
			Byte Lo;
			Byte Hi;
			
		};
		
	};
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct LongRec
{
	
	union
	{
		struct 
		{
			Byte Bytes[4];
			
		};
		struct 
		{
			Word Words[2];
			
		};
		struct 
		{
			Word Lo;
			Word Hi;
			
		};
		
	};
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct Int64Rec
{
	
	union
	{
		struct 
		{
			Byte Bytes[8];
			
		};
		struct 
		{
			Word Words[4];
			
		};
		struct 
		{
			unsigned Cardinals[2];
			
		};
		struct 
		{
			unsigned Lo;
			unsigned Hi;
			
		};
		
	};
} ;
#pragma pack(pop)

typedef Byte TByteArray[32768];

typedef Byte *PByteArray;

typedef Word TWordArray[16384];

typedef Word *PWordArray;

typedef void __fastcall (*TProcedure)(void);

typedef AnsiString TFileName;

#pragma pack(push, 4)
struct TSearchRec
{
	int Time;
	int Size;
	int Attr;
	AnsiString Name;
	int ExcludeAttr;
	unsigned FindHandle;
	_WIN32_FIND_DATAA FindData;
} ;
#pragma pack(pop)

#pragma option push -b-
enum TFloatValue { fvExtended, fvCurrency };
#pragma option pop

#pragma option push -b-
enum TFloatFormat { ffGeneral, ffExponent, ffFixed, ffNumber, ffCurrency };
#pragma option pop

#pragma pack(push, 1)
struct TFloatRec
{
	short Exponent;
	bool Negative;
	char Digits[21];
} ;
#pragma pack(pop)

#pragma pack(push, 4)
struct TTimeStamp
{
	int Time;
	int Date;
} ;
#pragma pack(pop)

#pragma option push -b-
enum TMbcsByteType { mbSingleByte, mbLeadByte, mbTrailByte };
#pragma option pop

#pragma pack(push, 1)
struct TSysLocale
{
	int DefaultLCID;
	int PriLangID;
	int SubLangID;
	bool FarEast;
	bool MiddleEast;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TLangRec
{
	AnsiString FName;
	unsigned FLCID;
	AnsiString FExt;
} ;
#pragma pack(pop)

typedef DynamicArray<TLangRec >  SysUtils__2;

class DELPHICLASS TLanguages;
class PASCALIMPLEMENTATION TLanguages : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	DynamicArray<TLangRec >  FSysLangs;
	int __stdcall LocalesCallback(char * LocaleID);
	AnsiString __fastcall GetExt(int Index);
	AnsiString __fastcall GetID(int Index);
	unsigned __fastcall GetLCID(int Index);
	AnsiString __fastcall GetName(int Index);
	AnsiString __fastcall GetNameFromLocaleID(unsigned ID);
	AnsiString __fastcall GetNameFromLCID(const AnsiString ID);
	int __fastcall GetCount(void);
	
public:
	__fastcall TLanguages(void);
	int __fastcall IndexOf(unsigned ID);
	__property int Count = {read=GetCount, nodefault};
	__property AnsiString Name[int Index] = {read=GetName};
	__property AnsiString NameFromLocaleID[unsigned ID] = {read=GetNameFromLocaleID};
	__property AnsiString NameFromLCID[AnsiString ID] = {read=GetNameFromLCID};
	__property AnsiString ID[int Index] = {read=GetID};
	__property unsigned LocaleID[int Index] = {read=GetLCID};
	__property AnsiString Ext[int Index] = {read=GetExt};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TLanguages(void) { }
	#pragma option pop
	
};


class DELPHICLASS Exception;
class PASCALIMPLEMENTATION Exception : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	AnsiString FMessage;
	int FHelpContext;
	
public:
	__fastcall Exception(const AnsiString Msg);
	__fastcall Exception(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size);
	__fastcall Exception(int Ident)/* overload */;
	__fastcall Exception(System::PResStringRec ResStringRec)/* overload */;
	__fastcall Exception(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */;
	__fastcall Exception(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size)/* overload */;
	__fastcall Exception(const AnsiString Msg, int AHelpContext);
	__fastcall Exception(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext);
	__fastcall Exception(int Ident, int AHelpContext)/* overload */;
	__fastcall Exception(System::PResStringRec ResStringRec, int AHelpContext)/* overload */;
	__fastcall Exception(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */;
	__fastcall Exception(int Ident, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */;
	__property int HelpContext = {read=FHelpContext, write=FHelpContext, nodefault};
	__property AnsiString Message = {read=FMessage, write=FMessage};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~Exception(void) { }
	#pragma option pop
	
};


typedef TMetaClass*ExceptClass;

class DELPHICLASS EAbort;
class PASCALIMPLEMENTATION EAbort : public Exception 
{
	typedef Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EAbort(const AnsiString Msg) : Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EAbort(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EAbort(int Ident)/* overload */ : Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EAbort(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EAbort(const AnsiString Msg, int AHelpContext) : Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EAbort(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EAbort(int Ident, int AHelpContext)/* overload */ : Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EAbort(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EAbort(void) { }
	#pragma option pop
	
};


class DELPHICLASS EHeapException;
class PASCALIMPLEMENTATION EHeapException : public Exception 
{
	typedef Exception inherited;
	
private:
	bool AllowFree;
	
public:
	virtual void __fastcall FreeInstance(void);
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EHeapException(const AnsiString Msg) : Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EHeapException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EHeapException(int Ident)/* overload */ : Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EHeapException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EHeapException(const AnsiString Msg, int AHelpContext) : Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EHeapException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EHeapException(int Ident, int AHelpContext)/* overload */ : Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EHeapException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EHeapException(void) { }
	#pragma option pop
	
};


class DELPHICLASS EOutOfMemory;
class PASCALIMPLEMENTATION EOutOfMemory : public EHeapException 
{
	typedef EHeapException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EOutOfMemory(const AnsiString Msg) : EHeapException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EOutOfMemory(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EHeapException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EOutOfMemory(int Ident)/* overload */ : EHeapException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EOutOfMemory(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EHeapException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EOutOfMemory(const AnsiString Msg, int AHelpContext) : EHeapException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EOutOfMemory(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EHeapException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EOutOfMemory(int Ident, int AHelpContext)/* overload */ : EHeapException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EOutOfMemory(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EHeapException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EOutOfMemory(void) { }
	#pragma option pop
	
};


class DELPHICLASS EInOutError;
class PASCALIMPLEMENTATION EInOutError : public Exception 
{
	typedef Exception inherited;
	
public:
	int ErrorCode;
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EInOutError(const AnsiString Msg) : Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EInOutError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EInOutError(int Ident)/* overload */ : Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EInOutError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EInOutError(const AnsiString Msg, int AHelpContext) : Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EInOutError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EInOutError(int Ident, int AHelpContext)/* overload */ : Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EInOutError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EInOutError(void) { }
	#pragma option pop
	
};


struct TExceptionRecord;
typedef TExceptionRecord *PExceptionRecord;

#pragma pack(push, 4)
struct TExceptionRecord
{
	unsigned ExceptionCode;
	unsigned ExceptionFlags;
	TExceptionRecord *ExceptionRecord;
	void *ExceptionAddress;
	unsigned NumberParameters;
	unsigned ExceptionInformation[15];
} ;
#pragma pack(pop)

class DELPHICLASS EExternal;
class PASCALIMPLEMENTATION EExternal : public Exception 
{
	typedef Exception inherited;
	
public:
	TExceptionRecord *ExceptionRecord;
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EExternal(const AnsiString Msg) : Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EExternal(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EExternal(int Ident)/* overload */ : Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EExternal(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EExternal(const AnsiString Msg, int AHelpContext) : Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EExternal(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EExternal(int Ident, int AHelpContext)/* overload */ : Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EExternal(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EExternal(void) { }
	#pragma option pop
	
};


class DELPHICLASS EExternalException;
class PASCALIMPLEMENTATION EExternalException : public EExternal 
{
	typedef EExternal inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EExternalException(const AnsiString Msg) : EExternal(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EExternalException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EExternal(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EExternalException(int Ident)/* overload */ : EExternal(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EExternalException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EExternal(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EExternalException(const AnsiString Msg, int AHelpContext) : EExternal(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EExternalException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EExternal(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EExternalException(int Ident, int AHelpContext)/* overload */ : EExternal(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EExternalException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EExternal(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EExternalException(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIntError;
class PASCALIMPLEMENTATION EIntError : public EExternal 
{
	typedef EExternal inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIntError(const AnsiString Msg) : EExternal(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIntError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EExternal(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIntError(int Ident)/* overload */ : EExternal(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIntError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EExternal(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIntError(const AnsiString Msg, int AHelpContext) : EExternal(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIntError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EExternal(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIntError(int Ident, int AHelpContext)/* overload */ : EExternal(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIntError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EExternal(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIntError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EDivByZero;
class PASCALIMPLEMENTATION EDivByZero : public EIntError 
{
	typedef EIntError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EDivByZero(const AnsiString Msg) : EIntError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EDivByZero(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIntError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EDivByZero(int Ident)/* overload */ : EIntError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EDivByZero(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIntError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EDivByZero(const AnsiString Msg, int AHelpContext) : EIntError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EDivByZero(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIntError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EDivByZero(int Ident, int AHelpContext)/* overload */ : EIntError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EDivByZero(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIntError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EDivByZero(void) { }
	#pragma option pop
	
};


class DELPHICLASS ERangeError;
class PASCALIMPLEMENTATION ERangeError : public EIntError 
{
	typedef EIntError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ERangeError(const AnsiString Msg) : EIntError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ERangeError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIntError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ERangeError(int Ident)/* overload */ : EIntError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ERangeError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIntError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ERangeError(const AnsiString Msg, int AHelpContext) : EIntError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ERangeError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIntError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ERangeError(int Ident, int AHelpContext)/* overload */ : EIntError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ERangeError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIntError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ERangeError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIntOverflow;
class PASCALIMPLEMENTATION EIntOverflow : public EIntError 
{
	typedef EIntError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIntOverflow(const AnsiString Msg) : EIntError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIntOverflow(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIntError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIntOverflow(int Ident)/* overload */ : EIntError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIntOverflow(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIntError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIntOverflow(const AnsiString Msg, int AHelpContext) : EIntError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIntOverflow(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIntError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIntOverflow(int Ident, int AHelpContext)/* overload */ : EIntError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIntOverflow(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIntError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIntOverflow(void) { }
	#pragma option pop
	
};


class DELPHICLASS EMathError;
class PASCALIMPLEMENTATION EMathError : public EExternal 
{
	typedef EExternal inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EMathError(const AnsiString Msg) : EExternal(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EMathError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EExternal(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EMathError(int Ident)/* overload */ : EExternal(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EMathError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EExternal(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EMathError(const AnsiString Msg, int AHelpContext) : EExternal(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EMathError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EExternal(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EMathError(int Ident, int AHelpContext)/* overload */ : EExternal(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EMathError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EExternal(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EMathError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EInvalidOp;
class PASCALIMPLEMENTATION EInvalidOp : public EMathError 
{
	typedef EMathError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EInvalidOp(const AnsiString Msg) : EMathError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EInvalidOp(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EMathError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EInvalidOp(int Ident)/* overload */ : EMathError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EInvalidOp(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EMathError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EInvalidOp(const AnsiString Msg, int AHelpContext) : EMathError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalidOp(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EMathError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EInvalidOp(int Ident, int AHelpContext)/* overload */ : EMathError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidOp(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EMathError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EInvalidOp(void) { }
	#pragma option pop
	
};


class DELPHICLASS EZeroDivide;
class PASCALIMPLEMENTATION EZeroDivide : public EMathError 
{
	typedef EMathError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EZeroDivide(const AnsiString Msg) : EMathError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EZeroDivide(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EMathError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EZeroDivide(int Ident)/* overload */ : EMathError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EZeroDivide(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EMathError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EZeroDivide(const AnsiString Msg, int AHelpContext) : EMathError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EZeroDivide(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EMathError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EZeroDivide(int Ident, int AHelpContext)/* overload */ : EMathError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EZeroDivide(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EMathError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EZeroDivide(void) { }
	#pragma option pop
	
};


class DELPHICLASS EOverflow;
class PASCALIMPLEMENTATION EOverflow : public EMathError 
{
	typedef EMathError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EOverflow(const AnsiString Msg) : EMathError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EOverflow(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EMathError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EOverflow(int Ident)/* overload */ : EMathError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EOverflow(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EMathError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EOverflow(const AnsiString Msg, int AHelpContext) : EMathError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EOverflow(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EMathError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EOverflow(int Ident, int AHelpContext)/* overload */ : EMathError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EOverflow(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EMathError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EOverflow(void) { }
	#pragma option pop
	
};


class DELPHICLASS EUnderflow;
class PASCALIMPLEMENTATION EUnderflow : public EMathError 
{
	typedef EMathError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EUnderflow(const AnsiString Msg) : EMathError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EUnderflow(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EMathError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EUnderflow(int Ident)/* overload */ : EMathError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EUnderflow(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EMathError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EUnderflow(const AnsiString Msg, int AHelpContext) : EMathError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EUnderflow(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EMathError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EUnderflow(int Ident, int AHelpContext)/* overload */ : EMathError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EUnderflow(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EMathError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EUnderflow(void) { }
	#pragma option pop
	
};


class DELPHICLASS EInvalidPointer;
class PASCALIMPLEMENTATION EInvalidPointer : public EHeapException 
{
	typedef EHeapException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EInvalidPointer(const AnsiString Msg) : EHeapException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EInvalidPointer(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EHeapException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EInvalidPointer(int Ident)/* overload */ : EHeapException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EInvalidPointer(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EHeapException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EInvalidPointer(const AnsiString Msg, int AHelpContext) : EHeapException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalidPointer(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EHeapException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EInvalidPointer(int Ident, int AHelpContext)/* overload */ : EHeapException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidPointer(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EHeapException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EInvalidPointer(void) { }
	#pragma option pop
	
};


class DELPHICLASS EInvalidCast;
class PASCALIMPLEMENTATION EInvalidCast : public Exception 
{
	typedef Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EInvalidCast(const AnsiString Msg) : Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EInvalidCast(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EInvalidCast(int Ident)/* overload */ : Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EInvalidCast(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EInvalidCast(const AnsiString Msg, int AHelpContext) : Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalidCast(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EInvalidCast(int Ident, int AHelpContext)/* overload */ : Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidCast(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EInvalidCast(void) { }
	#pragma option pop
	
};


class DELPHICLASS EConvertError;
class PASCALIMPLEMENTATION EConvertError : public Exception 
{
	typedef Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EConvertError(const AnsiString Msg) : Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EConvertError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EConvertError(int Ident)/* overload */ : Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EConvertError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EConvertError(const AnsiString Msg, int AHelpContext) : Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EConvertError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EConvertError(int Ident, int AHelpContext)/* overload */ : Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EConvertError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EConvertError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EAccessViolation;
class PASCALIMPLEMENTATION EAccessViolation : public EExternal 
{
	typedef EExternal inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EAccessViolation(const AnsiString Msg) : EExternal(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EAccessViolation(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EExternal(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EAccessViolation(int Ident)/* overload */ : EExternal(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EAccessViolation(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EExternal(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EAccessViolation(const AnsiString Msg, int AHelpContext) : EExternal(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EAccessViolation(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EExternal(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EAccessViolation(int Ident, int AHelpContext)/* overload */ : EExternal(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EAccessViolation(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EExternal(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EAccessViolation(void) { }
	#pragma option pop
	
};


class DELPHICLASS EPrivilege;
class PASCALIMPLEMENTATION EPrivilege : public EExternal 
{
	typedef EExternal inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EPrivilege(const AnsiString Msg) : EExternal(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EPrivilege(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EExternal(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EPrivilege(int Ident)/* overload */ : EExternal(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EPrivilege(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EExternal(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EPrivilege(const AnsiString Msg, int AHelpContext) : EExternal(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EPrivilege(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EExternal(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EPrivilege(int Ident, int AHelpContext)/* overload */ : EExternal(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EPrivilege(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EExternal(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EPrivilege(void) { }
	#pragma option pop
	
};


class DELPHICLASS EStackOverflow;
class PASCALIMPLEMENTATION EStackOverflow : public EExternal 
{
	typedef EExternal inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EStackOverflow(const AnsiString Msg) : EExternal(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EStackOverflow(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EExternal(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EStackOverflow(int Ident)/* overload */ : EExternal(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EStackOverflow(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EExternal(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EStackOverflow(const AnsiString Msg, int AHelpContext) : EExternal(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EStackOverflow(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EExternal(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EStackOverflow(int Ident, int AHelpContext)/* overload */ : EExternal(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EStackOverflow(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EExternal(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EStackOverflow(void) { }
	#pragma option pop
	
};


class DELPHICLASS EControlC;
class PASCALIMPLEMENTATION EControlC : public EExternal 
{
	typedef EExternal inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EControlC(const AnsiString Msg) : EExternal(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EControlC(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EExternal(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EControlC(int Ident)/* overload */ : EExternal(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EControlC(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EExternal(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EControlC(const AnsiString Msg, int AHelpContext) : EExternal(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EControlC(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EExternal(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EControlC(int Ident, int AHelpContext)/* overload */ : EExternal(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EControlC(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EExternal(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EControlC(void) { }
	#pragma option pop
	
};


class DELPHICLASS EVariantError;
class PASCALIMPLEMENTATION EVariantError : public Exception 
{
	typedef Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EVariantError(const AnsiString Msg) : Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EVariantError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EVariantError(int Ident)/* overload */ : Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EVariantError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EVariantError(const AnsiString Msg, int AHelpContext) : Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EVariantError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EVariantError(int Ident, int AHelpContext)/* overload */ : Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EVariantError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EVariantError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EPropReadOnly;
class PASCALIMPLEMENTATION EPropReadOnly : public Exception 
{
	typedef Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EPropReadOnly(const AnsiString Msg) : Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EPropReadOnly(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EPropReadOnly(int Ident)/* overload */ : Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EPropReadOnly(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EPropReadOnly(const AnsiString Msg, int AHelpContext) : Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EPropReadOnly(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EPropReadOnly(int Ident, int AHelpContext)/* overload */ : Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EPropReadOnly(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EPropReadOnly(void) { }
	#pragma option pop
	
};


class DELPHICLASS EPropWriteOnly;
class PASCALIMPLEMENTATION EPropWriteOnly : public Exception 
{
	typedef Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EPropWriteOnly(const AnsiString Msg) : Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EPropWriteOnly(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EPropWriteOnly(int Ident)/* overload */ : Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EPropWriteOnly(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EPropWriteOnly(const AnsiString Msg, int AHelpContext) : Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EPropWriteOnly(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EPropWriteOnly(int Ident, int AHelpContext)/* overload */ : Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EPropWriteOnly(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EPropWriteOnly(void) { }
	#pragma option pop
	
};


class DELPHICLASS EAssertionFailed;
class PASCALIMPLEMENTATION EAssertionFailed : public Exception 
{
	typedef Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EAssertionFailed(const AnsiString Msg) : Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EAssertionFailed(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EAssertionFailed(int Ident)/* overload */ : Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EAssertionFailed(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EAssertionFailed(const AnsiString Msg, int AHelpContext) : Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EAssertionFailed(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EAssertionFailed(int Ident, int AHelpContext)/* overload */ : Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EAssertionFailed(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EAssertionFailed(void) { }
	#pragma option pop
	
};


class DELPHICLASS EAbstractError;
class PASCALIMPLEMENTATION EAbstractError : public Exception 
{
	typedef Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EAbstractError(const AnsiString Msg) : Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EAbstractError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EAbstractError(int Ident)/* overload */ : Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EAbstractError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EAbstractError(const AnsiString Msg, int AHelpContext) : Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EAbstractError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EAbstractError(int Ident, int AHelpContext)/* overload */ : Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EAbstractError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EAbstractError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIntfCastError;
class PASCALIMPLEMENTATION EIntfCastError : public Exception 
{
	typedef Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIntfCastError(const AnsiString Msg) : Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIntfCastError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIntfCastError(int Ident)/* overload */ : Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIntfCastError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIntfCastError(const AnsiString Msg, int AHelpContext) : Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIntfCastError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIntfCastError(int Ident, int AHelpContext)/* overload */ : Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIntfCastError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIntfCastError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EInvalidContainer;
class PASCALIMPLEMENTATION EInvalidContainer : public Exception 
{
	typedef Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EInvalidContainer(const AnsiString Msg) : Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EInvalidContainer(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EInvalidContainer(int Ident)/* overload */ : Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EInvalidContainer(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EInvalidContainer(const AnsiString Msg, int AHelpContext) : Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalidContainer(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EInvalidContainer(int Ident, int AHelpContext)/* overload */ : Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidContainer(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EInvalidContainer(void) { }
	#pragma option pop
	
};


class DELPHICLASS EInvalidInsert;
class PASCALIMPLEMENTATION EInvalidInsert : public Exception 
{
	typedef Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EInvalidInsert(const AnsiString Msg) : Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EInvalidInsert(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EInvalidInsert(int Ident)/* overload */ : Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EInvalidInsert(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EInvalidInsert(const AnsiString Msg, int AHelpContext) : Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalidInsert(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EInvalidInsert(int Ident, int AHelpContext)/* overload */ : Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidInsert(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EInvalidInsert(void) { }
	#pragma option pop
	
};


class DELPHICLASS EPackageError;
class PASCALIMPLEMENTATION EPackageError : public Exception 
{
	typedef Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EPackageError(const AnsiString Msg) : Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EPackageError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EPackageError(int Ident)/* overload */ : Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EPackageError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EPackageError(const AnsiString Msg, int AHelpContext) : Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EPackageError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EPackageError(int Ident, int AHelpContext)/* overload */ : Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EPackageError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EPackageError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EOSError;
class PASCALIMPLEMENTATION EOSError : public Exception 
{
	typedef Exception inherited;
	
public:
	unsigned ErrorCode;
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EOSError(const AnsiString Msg) : Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EOSError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EOSError(int Ident)/* overload */ : Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EOSError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EOSError(const AnsiString Msg, int AHelpContext) : Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EOSError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EOSError(int Ident, int AHelpContext)/* overload */ : Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EOSError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EOSError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EWin32Error;
class PASCALIMPLEMENTATION EWin32Error : public EOSError 
{
	typedef EOSError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EWin32Error(const AnsiString Msg) : EOSError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EWin32Error(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EOSError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EWin32Error(int Ident)/* overload */ : EOSError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EWin32Error(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EOSError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EWin32Error(const AnsiString Msg, int AHelpContext) : EOSError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EWin32Error(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EOSError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EWin32Error(int Ident, int AHelpContext)/* overload */ : EOSError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EWin32Error(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EOSError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EWin32Error(void) { }
	#pragma option pop
	
};


class DELPHICLASS ESafecallException;
class PASCALIMPLEMENTATION ESafecallException : public Exception 
{
	typedef Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ESafecallException(const AnsiString Msg) : Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ESafecallException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ESafecallException(int Ident)/* overload */ : Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ESafecallException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ESafecallException(const AnsiString Msg, int AHelpContext) : Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ESafecallException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ESafecallException(int Ident, int AHelpContext)/* overload */ : Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ESafecallException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ESafecallException(void) { }
	#pragma option pop
	
};


typedef AnsiString SysUtils__83[12];

typedef AnsiString SysUtils__93[12];

typedef AnsiString SysUtils__04[7];

typedef AnsiString SysUtils__14[7];

typedef AnsiString SysUtils__24[7];

typedef DynamicArray<AnsiString >  SysUtils__34;

typedef DynamicArray<AnsiString >  SysUtils__44;

#pragma option push -b-
enum TFilenameCaseMatch { mkNone, mkExactMatch, mkSingleMatch, mkAmbiguous };
#pragma option pop

typedef Word TDayTable[12];

typedef Word *PDayTable;

#pragma option push -b-
enum SysUtils__54 { rfReplaceAll, rfIgnoreCase };
#pragma option pop

typedef Set<SysUtils__54, rfReplaceAll, rfIgnoreCase>  TReplaceFlags;

#pragma option push -b-
enum TNameType { ntContainsUnit, ntRequiresPackage, ntDcpBpiName };
#pragma option pop

typedef void __fastcall (*TPackageInfoProc)(const AnsiString Name, TNameType NameType, Byte Flags, void * Param);

typedef bool __fastcall (*TTerminateProc)(void);

__interface IReadWriteSync;
typedef System::DelphiInterface<IReadWriteSync> _di_IReadWriteSync;
__interface IReadWriteSync  : public IInterface 
{
	
public:
	virtual void __fastcall BeginRead(void) = 0 ;
	virtual void __fastcall EndRead(void) = 0 ;
	virtual bool __fastcall BeginWrite(void) = 0 ;
	virtual void __fastcall EndWrite(void) = 0 ;
};

class DELPHICLASS TSimpleRWSync;
class PASCALIMPLEMENTATION TSimpleRWSync : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	_RTL_CRITICAL_SECTION FLock;
	
public:
	__fastcall TSimpleRWSync(void);
	__fastcall virtual ~TSimpleRWSync(void);
	void __fastcall BeginRead(void);
	void __fastcall EndRead(void);
	bool __fastcall BeginWrite(void);
	void __fastcall EndWrite(void);
private:
	void *__IReadWriteSync;	/* Sysutils::IReadWriteSync */
	
public:
	operator IReadWriteSync*(void) { return (IReadWriteSync*)&__IReadWriteSync; }
	
};


struct TThreadInfo;
typedef TThreadInfo *PThreadInfo;

#pragma pack(push, 4)
struct TThreadInfo
{
	TThreadInfo *Next;
	TThreadInfo *NextDead;
	unsigned ThreadID;
	unsigned RecursionCount;
} ;
#pragma pack(pop)

class DELPHICLASS TThreadLocalCounter;
class PASCALIMPLEMENTATION TThreadLocalCounter : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TThreadInfo *FHashTable[16];
	TThreadInfo *FPurgatory;
	int FOpenCount;
	Byte __fastcall HashIndex(void);
	PThreadInfo __fastcall Recycle(void);
	void __fastcall Reattach(PThreadInfo List);
	
protected:
	unsigned FHoldTime;
	
public:
	__fastcall TThreadLocalCounter(void);
	__fastcall virtual ~TThreadLocalCounter(void);
	void __fastcall Open(PThreadInfo &Thread);
	void __fastcall Delete(PThreadInfo &Thread);
	void __fastcall Close(PThreadInfo &Thread);
};


class DELPHICLASS TMultiReadExclusiveWriteSynchronizer;
class PASCALIMPLEMENTATION TMultiReadExclusiveWriteSynchronizer : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	int FSentinel;
	unsigned FReadSignal;
	unsigned FWriteSignal;
	unsigned FWaitRecycle;
	unsigned FWriteRecursionCount;
	TThreadLocalCounter* tls;
	unsigned FWriterID;
	unsigned FRevisionLevel;
	void __fastcall BlockReaders(void);
	void __fastcall UnblockReaders(void);
	void __fastcall UnblockOneWriter(void);
	void __fastcall WaitForReadSignal(void);
	void __fastcall WaitForWriteSignal(void);
	
public:
	__fastcall TMultiReadExclusiveWriteSynchronizer(void);
	__fastcall virtual ~TMultiReadExclusiveWriteSynchronizer(void);
	void __fastcall BeginRead(void);
	void __fastcall EndRead(void);
	bool __fastcall BeginWrite(void);
	void __fastcall EndWrite(void);
	__property unsigned RevisionLevel = {read=FRevisionLevel, nodefault};
private:
	void *__IReadWriteSync;	/* Sysutils::IReadWriteSync */
	
public:
	operator IReadWriteSync*(void) { return (IReadWriteSync*)&__IReadWriteSync; }
	
};


typedef TMultiReadExclusiveWriteSynchronizer TMREWSync;
;

//-- var, const, procedure ---------------------------------------------------
static const Shortint fmOpenRead = 0x0;
static const Shortint fmOpenWrite = 0x1;
static const Shortint fmOpenReadWrite = 0x2;
static const Shortint fmShareCompat = 0x0;
static const Shortint fmShareExclusive = 0x10;
static const Shortint fmShareDenyWrite = 0x20;
static const Shortint fmShareDenyRead = 0x30;
static const Shortint fmShareDenyNone = 0x40;
static const Shortint faReadOnly = 0x1;
static const Shortint faHidden = 0x2;
static const Shortint faSysFile = 0x4;
static const Shortint faVolumeID = 0x8;
static const Shortint faDirectory = 0x10;
static const Shortint faArchive = 0x20;
static const Shortint faAnyFile = 0x3f;
static const Shortint HoursPerDay = 0x18;
static const Word MinsPerDay = 0x5a0;
static const int SecsPerDay = 0x15180;
static const int MSecsPerDay = 0x5265c00;
static const int DateDelta = 0xa955a;
static const Word UnixDateDelta = 0x63e1;
extern PACKAGE AnsiString EmptyStr;
extern PACKAGE AnsiString *NullStr;
extern PACKAGE WideString EmptyWideStr;
extern PACKAGE WideString *NullWideStr;
extern PACKAGE int Win32Platform;
extern PACKAGE int Win32MajorVersion;
extern PACKAGE int Win32MinorVersion;
extern PACKAGE int Win32BuildNumber;
extern PACKAGE AnsiString Win32CSDVersion;
extern PACKAGE AnsiString CurrencyString;
extern PACKAGE Byte CurrencyFormat;
extern PACKAGE Byte NegCurrFormat;
extern PACKAGE char ThousandSeparator;
extern PACKAGE char DecimalSeparator;
extern PACKAGE Byte CurrencyDecimals;
extern PACKAGE char DateSeparator;
extern PACKAGE AnsiString ShortDateFormat;
extern PACKAGE AnsiString LongDateFormat;
extern PACKAGE char TimeSeparator;
extern PACKAGE AnsiString TimeAMString;
extern PACKAGE AnsiString TimePMString;
extern PACKAGE AnsiString ShortTimeFormat;
extern PACKAGE AnsiString LongTimeFormat;
extern PACKAGE AnsiString ShortMonthNames[12];
extern PACKAGE AnsiString LongMonthNames[12];
extern PACKAGE AnsiString ShortDayNames[7];
extern PACKAGE AnsiString LongDayNames[7];
extern PACKAGE TSysLocale SysLocale;
extern PACKAGE Word TwoDigitYearCenturyWindow;
extern PACKAGE char ListSeparator;
static const Shortint MaxEraCount = 0x7;
extern PACKAGE AnsiString EraNames[7];
extern PACKAGE int EraYearOffsets[7];
static const char PathDelim = '\x5c';
static const char DriveDelim = '\x3a';
static const char PathSep = '\x3b';
extern PACKAGE DynamicArray<AnsiString >  TrueBoolStrs;
extern PACKAGE DynamicArray<AnsiString >  FalseBoolStrs;
#define DefaultTrueBoolStr "True"
#define DefaultFalseBoolStr "False"
extern PACKAGE System::Currency MinCurrency;
extern PACKAGE System::Currency MaxCurrency;
extern PACKAGE Word MonthDays[2][12];
extern PACKAGE System::TDateTime MinDateTime;
extern PACKAGE System::TDateTime MaxDateTime;
#define SwitchChars (System::Set<char, 0, 255> () << '\x2d' << '\x2f' )
static const Shortint pfNeverBuild = 0x1;
static const Shortint pfDesignOnly = 0x2;
static const Shortint pfRunOnly = 0x4;
static const Shortint pfIgnoreDupUnits = 0x8;
static const unsigned pfModuleTypeMask = 0xc0000000;
static const Shortint pfExeModule = 0x0;
static const int pfPackageModule = 0x40000000;
static const int pfProducerMask = 0xc000000;
static const Shortint pfV3Produced = 0x0;
static const int pfProducerUndefined = 0x4000000;
static const int pfBCB4Produced = 0x8000000;
static const int pfDelphi4Produced = 0xc000000;
static const unsigned pfLibraryModule = 0x80000000;
static const Shortint ufMainUnit = 0x1;
static const Shortint ufPackageUnit = 0x2;
static const Shortint ufWeakUnit = 0x4;
static const Shortint ufOrgWeakUnit = 0x8;
static const Shortint ufImplicitUnit = 0x10;
static const Shortint ufWeakPackageUnit = 0x6;
extern PACKAGE AnsiString HexDisplayPrefix;
extern PACKAGE BOOL __stdcall (*GetDiskFreeSpaceEx)(char * Directory, __int64 &FreeAvailable, __int64 &TotalSpace, Windows::PLargeInteger TotalFree);
extern PACKAGE HRESULT __stdcall CreateGUID(/* out */ GUID &Guid);
extern PACKAGE GUID __fastcall StringToGUID(const AnsiString S);
extern PACKAGE AnsiString __fastcall GUIDToString(const GUID &GUID);
extern PACKAGE void * __fastcall AllocMem(unsigned Size);
extern PACKAGE void __fastcall AddExitProc(TProcedure Proc);
extern PACKAGE System::PAnsiString __fastcall NewStr(const AnsiString S);
extern PACKAGE void __fastcall DisposeStr(System::PAnsiString P);
extern PACKAGE void __fastcall AssignStr(System::PAnsiString &P, const AnsiString S);
extern PACKAGE void __fastcall AppendStr(AnsiString &Dest, const AnsiString S);
extern PACKAGE AnsiString __fastcall UpperCase(const AnsiString S);
extern PACKAGE AnsiString __fastcall LowerCase(const AnsiString S);
extern PACKAGE int __fastcall CompareStr(const AnsiString S1, const AnsiString S2);
extern PACKAGE bool __fastcall CompareMem(void * P1, void * P2, int Length);
extern PACKAGE int __fastcall CompareText(const AnsiString S1, const AnsiString S2);
extern PACKAGE bool __fastcall SameText(const AnsiString S1, const AnsiString S2);
extern PACKAGE AnsiString __fastcall AnsiUpperCase(const AnsiString S);
extern PACKAGE AnsiString __fastcall AnsiLowerCase(const AnsiString S);
extern PACKAGE int __fastcall AnsiCompareStr(const AnsiString S1, const AnsiString S2);
extern PACKAGE bool __fastcall AnsiSameStr(const AnsiString S1, const AnsiString S2);
extern PACKAGE int __fastcall AnsiCompareText(const AnsiString S1, const AnsiString S2);
extern PACKAGE bool __fastcall AnsiSameText(const AnsiString S1, const AnsiString S2);
extern PACKAGE int __fastcall AnsiStrComp(char * S1, char * S2);
extern PACKAGE int __fastcall AnsiStrIComp(char * S1, char * S2);
extern PACKAGE int __fastcall AnsiStrLComp(char * S1, char * S2, unsigned MaxLen);
extern PACKAGE int __fastcall AnsiStrLIComp(char * S1, char * S2, unsigned MaxLen);
extern PACKAGE char * __fastcall AnsiStrLower(char * Str);
extern PACKAGE char * __fastcall AnsiStrUpper(char * Str);
extern PACKAGE WideString __fastcall WideUpperCase(const WideString S);
extern PACKAGE WideString __fastcall WideLowerCase(const WideString S);
extern PACKAGE int __fastcall WideCompareStr(const WideString S1, const WideString S2);
extern PACKAGE bool __fastcall WideSameStr(const WideString S1, const WideString S2);
extern PACKAGE int __fastcall WideCompareText(const WideString S1, const WideString S2);
extern PACKAGE bool __fastcall WideSameText(const WideString S1, const WideString S2);
extern PACKAGE AnsiString __fastcall Trim(const AnsiString S)/* overload */;
extern PACKAGE WideString __fastcall Trim(const WideString S)/* overload */;
extern PACKAGE AnsiString __fastcall TrimLeft(const AnsiString S)/* overload */;
extern PACKAGE WideString __fastcall TrimLeft(const WideString S)/* overload */;
extern PACKAGE AnsiString __fastcall TrimRight(const AnsiString S)/* overload */;
extern PACKAGE WideString __fastcall TrimRight(const WideString S)/* overload */;
extern PACKAGE AnsiString __fastcall QuotedStr(const AnsiString S);
extern PACKAGE AnsiString __fastcall AnsiQuotedStr(const AnsiString S, char Quote);
extern PACKAGE AnsiString __fastcall AnsiExtractQuotedStr(char * &Src, char Quote);
extern PACKAGE AnsiString __fastcall AnsiDequotedStr(const AnsiString S, char AQuote);
extern PACKAGE AnsiString __fastcall AdjustLineBreaks(const AnsiString S, System::TTextLineBreakStyle Style = (System::TTextLineBreakStyle)(0x1));
extern PACKAGE bool __fastcall IsValidIdent(const AnsiString Ident);
extern PACKAGE AnsiString __fastcall IntToStr(int Value)/* overload */;
extern PACKAGE AnsiString __fastcall IntToStr(__int64 Value)/* overload */;
extern PACKAGE AnsiString __fastcall IntToHex(int Value, int Digits)/* overload */;
extern PACKAGE AnsiString __fastcall IntToHex(__int64 Value, int Digits)/* overload */;
extern PACKAGE int __fastcall StrToInt(const AnsiString S);
extern PACKAGE int __fastcall StrToIntDef(const AnsiString S, int Default);
extern PACKAGE bool __fastcall TryStrToInt(const AnsiString S, /* out */ int &Value);
extern PACKAGE __int64 __fastcall StrToInt64(const AnsiString S);
extern PACKAGE __int64 __fastcall StrToInt64Def(const AnsiString S, const __int64 Default);
extern PACKAGE bool __fastcall TryStrToInt64(const AnsiString S, /* out */ __int64 &Value);
extern PACKAGE bool __fastcall StrToBool(const AnsiString S);
extern PACKAGE bool __fastcall StrToBoolDef(const AnsiString S, const bool Default);
extern PACKAGE bool __fastcall TryStrToBool(const AnsiString S, /* out */ bool &Value);
extern PACKAGE AnsiString __fastcall BoolToStr(bool B, bool UseBoolStrs = false);
extern PACKAGE AnsiString __fastcall LoadStr(int Ident);
extern PACKAGE AnsiString __fastcall FmtLoadStr(int Ident, const System::TVarRec * Args, const int Args_Size);
extern PACKAGE int __fastcall FileOpen(const AnsiString FileName, unsigned Mode);
extern PACKAGE int __fastcall FileCreate(const AnsiString FileName)/* overload */;
extern PACKAGE int __fastcall FileCreate(const AnsiString FileName, int Rights)/* overload */;
extern PACKAGE int __fastcall FileRead(int Handle, void *Buffer, unsigned Count);
extern PACKAGE int __fastcall FileWrite(int Handle, const void *Buffer, unsigned Count);
extern PACKAGE int __fastcall FileSeek(int Handle, int Offset, int Origin)/* overload */;
extern PACKAGE __int64 __fastcall FileSeek(int Handle, const __int64 Offset, int Origin)/* overload */;
extern PACKAGE void __fastcall FileClose(int Handle);
extern PACKAGE int __fastcall FileAge(const AnsiString FileName);
extern PACKAGE bool __fastcall FileExists(const AnsiString FileName);
extern PACKAGE bool __fastcall DirectoryExists(const AnsiString Directory);
extern PACKAGE bool __fastcall ForceDirectories(AnsiString Dir);
extern PACKAGE int __fastcall FileGetDate(int Handle);
extern PACKAGE int __fastcall FileSetDate(const AnsiString FileName, int Age)/* overload */;
extern PACKAGE int __fastcall FileSetDate(int Handle, int Age)/* overload */;
extern PACKAGE int __fastcall FileGetAttr(const AnsiString FileName);
extern PACKAGE int __fastcall FileSetAttr(const AnsiString FileName, int Attr);
extern PACKAGE bool __fastcall FileIsReadOnly(const AnsiString FileName);
extern PACKAGE bool __fastcall FileSetReadOnly(const AnsiString FileName, bool ReadOnly);
extern PACKAGE int __fastcall FindFirst(const AnsiString Path, int Attr, TSearchRec &F);
extern PACKAGE int __fastcall FindNext(TSearchRec &F);
extern PACKAGE void __fastcall FindClose(TSearchRec &F);
extern PACKAGE bool __fastcall DeleteFile(const AnsiString FileName);
extern PACKAGE bool __fastcall RenameFile(const AnsiString OldName, const AnsiString NewName);
extern PACKAGE char * __fastcall AnsiStrLastChar(char * P);
extern PACKAGE char * __fastcall AnsiLastChar(const AnsiString S);
extern PACKAGE int __fastcall LastDelimiter(const AnsiString Delimiters, const AnsiString S);
extern PACKAGE AnsiString __fastcall ChangeFileExt(const AnsiString FileName, const AnsiString Extension);
extern PACKAGE AnsiString __fastcall ExtractFilePath(const AnsiString FileName);
extern PACKAGE AnsiString __fastcall ExtractFileDir(const AnsiString FileName);
extern PACKAGE AnsiString __fastcall ExtractFileDrive(const AnsiString FileName);
extern PACKAGE AnsiString __fastcall ExtractFileName(const AnsiString FileName);
extern PACKAGE AnsiString __fastcall ExtractFileExt(const AnsiString FileName);
extern PACKAGE AnsiString __fastcall ExpandFileName(const AnsiString FileName);
extern PACKAGE AnsiString __fastcall ExpandFileNameCase(const AnsiString FileName, /* out */ TFilenameCaseMatch &MatchFound);
extern PACKAGE AnsiString __fastcall ExpandUNCFileName(const AnsiString FileName);
extern PACKAGE AnsiString __fastcall ExtractRelativePath(const AnsiString BaseName, const AnsiString DestName);
extern PACKAGE AnsiString __fastcall ExtractShortPathName(const AnsiString FileName);
extern PACKAGE AnsiString __fastcall FileSearch(const AnsiString Name, const AnsiString DirList);
extern PACKAGE __int64 __fastcall DiskFree(Byte Drive);
extern PACKAGE __int64 __fastcall DiskSize(Byte Drive);
extern PACKAGE System::TDateTime __fastcall FileDateToDateTime(int FileDate);
extern PACKAGE int __fastcall DateTimeToFileDate(System::TDateTime DateTime);
extern PACKAGE AnsiString __fastcall GetCurrentDir();
extern PACKAGE bool __fastcall SetCurrentDir(const AnsiString Dir);
extern PACKAGE bool __fastcall CreateDir(const AnsiString Dir);
extern PACKAGE bool __fastcall RemoveDir(const AnsiString Dir);
extern PACKAGE unsigned __fastcall StrLen(const char * Str);
extern PACKAGE char * __fastcall StrEnd(const char * Str);
extern PACKAGE char * __fastcall StrMove(char * Dest, const char * Source, unsigned Count);
extern PACKAGE char * __fastcall StrCopy(char * Dest, const char * Source);
extern PACKAGE char * __fastcall StrECopy(char * Dest, const char * Source);
extern PACKAGE char * __fastcall StrLCopy(char * Dest, const char * Source, unsigned MaxLen);
extern PACKAGE char * __fastcall StrPCopy(char * Dest, const AnsiString Source);
extern PACKAGE char * __fastcall StrPLCopy(char * Dest, const AnsiString Source, unsigned MaxLen);
extern PACKAGE char * __fastcall StrCat(char * Dest, const char * Source);
extern PACKAGE char * __fastcall StrLCat(char * Dest, const char * Source, unsigned MaxLen);
extern PACKAGE int __fastcall StrComp(const char * Str1, const char * Str2);
extern PACKAGE int __fastcall StrIComp(const char * Str1, const char * Str2);
extern PACKAGE int __fastcall StrLComp(const char * Str1, const char * Str2, unsigned MaxLen);
extern PACKAGE int __fastcall StrLIComp(const char * Str1, const char * Str2, unsigned MaxLen);
extern PACKAGE char * __fastcall StrScan(const char * Str, char Chr);
extern PACKAGE char * __fastcall StrRScan(const char * Str, char Chr);
extern PACKAGE char * __fastcall StrPos(const char * Str1, const char * Str2);
extern PACKAGE char * __fastcall StrUpper(char * Str);
extern PACKAGE char * __fastcall StrLower(char * Str);
extern PACKAGE AnsiString __fastcall StrPas(const char * Str);
extern PACKAGE char * __fastcall StrAlloc(unsigned Size);
extern PACKAGE unsigned __fastcall StrBufSize(const char * Str);
extern PACKAGE char * __fastcall StrNew(const char * Str);
extern PACKAGE void __fastcall StrDispose(char * Str);
extern PACKAGE unsigned __fastcall FormatBuf(void *Buffer, unsigned BufLen, const void *Format, unsigned FmtLen, const System::TVarRec * Args, const int Args_Size);
extern PACKAGE char * __fastcall StrFmt(char * Buffer, char * Format, const System::TVarRec * Args, const int Args_Size);
extern PACKAGE char * __fastcall StrLFmt(char * Buffer, unsigned MaxBufLen, char * Format, const System::TVarRec * Args, const int Args_Size);
extern PACKAGE AnsiString __fastcall Format(const AnsiString Format, const System::TVarRec * Args, const int Args_Size);
extern PACKAGE void __fastcall FmtStr(AnsiString &Result, const AnsiString Format, const System::TVarRec * Args, const int Args_Size);
extern PACKAGE unsigned __fastcall WideFormatBuf(void *Buffer, unsigned BufLen, const void *Format, unsigned FmtLen, const System::TVarRec * Args, const int Args_Size);
extern PACKAGE void __fastcall WideFmtStr(WideString &Result, const WideString Format, const System::TVarRec * Args, const int Args_Size);
extern PACKAGE WideString __fastcall WideFormat(const WideString Format, const System::TVarRec * Args, const int Args_Size);
extern PACKAGE int __fastcall FloatToText(char * BufferArg, const void *Value, TFloatValue ValueType, TFloatFormat Format, int Precision, int Digits);
extern PACKAGE int __fastcall FloatToTextFmt(char * Buf, const void *Value, TFloatValue ValueType, char * Format);
extern PACKAGE void __fastcall FloatToDecimal(TFloatRec &Result, const void *Value, TFloatValue ValueType, int Precision, int Decimals);
extern PACKAGE bool __fastcall TextToFloat(char * Buffer, void *Value, TFloatValue ValueType);
extern PACKAGE AnsiString __fastcall FloatToStr(Extended Value);
extern PACKAGE AnsiString __fastcall CurrToStr(System::Currency Value);
extern PACKAGE bool __fastcall TryFloatToCurr(const Extended Value, /* out */ System::Currency &AResult);
extern PACKAGE System::Currency __fastcall FloatToCurr(const Extended Value);
extern PACKAGE AnsiString __fastcall FloatToStrF(Extended Value, TFloatFormat Format, int Precision, int Digits);
extern PACKAGE AnsiString __fastcall CurrToStrF(System::Currency Value, TFloatFormat Format, int Digits);
extern PACKAGE AnsiString __fastcall FormatFloat(const AnsiString Format, Extended Value);
extern PACKAGE AnsiString __fastcall FormatCurr(const AnsiString Format, System::Currency Value);
extern PACKAGE Extended __fastcall StrToFloat(const AnsiString S);
extern PACKAGE Extended __fastcall StrToFloatDef(const AnsiString S, const Extended Default);
extern PACKAGE bool __fastcall TryStrToFloat(const AnsiString S, /* out */ Extended &Value)/* overload */;
extern PACKAGE bool __fastcall TryStrToFloat(const AnsiString S, /* out */ double &Value)/* overload */;
extern PACKAGE bool __fastcall TryStrToFloat(const AnsiString S, /* out */ float &Value)/* overload */;
extern PACKAGE System::Currency __fastcall StrToCurr(const AnsiString S);
extern PACKAGE System::Currency __fastcall StrToCurrDef(const AnsiString S, const System::Currency Default);
extern PACKAGE bool __fastcall TryStrToCurr(const AnsiString S, /* out */ System::Currency &Value);
extern PACKAGE TTimeStamp __fastcall DateTimeToTimeStamp(System::TDateTime DateTime);
extern PACKAGE System::TDateTime __fastcall TimeStampToDateTime(const TTimeStamp &TimeStamp);
extern PACKAGE TTimeStamp __fastcall MSecsToTimeStamp(System::Comp MSecs);
extern PACKAGE System::Comp __fastcall TimeStampToMSecs(const TTimeStamp &TimeStamp);
extern PACKAGE bool __fastcall TryEncodeTime(Word Hour, Word Min, Word Sec, Word MSec, /* out */ System::TDateTime &Time);
extern PACKAGE System::TDateTime __fastcall EncodeTime(Word Hour, Word Min, Word Sec, Word MSec);
extern PACKAGE void __fastcall DecodeTime(const System::TDateTime DateTime, Word &Hour, Word &Min, Word &Sec, Word &MSec);
extern PACKAGE bool __fastcall IsLeapYear(Word Year);
extern PACKAGE bool __fastcall TryEncodeDate(Word Year, Word Month, Word Day, /* out */ System::TDateTime &Date);
extern PACKAGE System::TDateTime __fastcall EncodeDate(Word Year, Word Month, Word Day);
extern PACKAGE bool __fastcall DecodeDateFully(const System::TDateTime DateTime, Word &Year, Word &Month, Word &Day, Word &DOW);
extern PACKAGE void __fastcall DecodeDate(const System::TDateTime DateTime, Word &Year, Word &Month, Word &Day);
extern PACKAGE void __fastcall DateTimeToSystemTime(const System::TDateTime DateTime, _SYSTEMTIME &SystemTime);
extern PACKAGE System::TDateTime __fastcall SystemTimeToDateTime(const _SYSTEMTIME &SystemTime);
extern PACKAGE Word __fastcall DayOfWeek(const System::TDateTime DateTime);
extern PACKAGE System::TDateTime __fastcall Date(void);
extern PACKAGE System::TDateTime __fastcall Time(void);
extern PACKAGE System::TDateTime __fastcall Now(void);
extern PACKAGE System::TDateTime __fastcall IncMonth(const System::TDateTime DateTime, int NumberOfMonths = 0x1);
extern PACKAGE void __fastcall IncAMonth(Word &Year, Word &Month, Word &Day, int NumberOfMonths = 0x1);
extern PACKAGE void __fastcall ReplaceTime(System::TDateTime &DateTime, const System::TDateTime NewTime);
extern PACKAGE void __fastcall ReplaceDate(System::TDateTime &DateTime, const System::TDateTime NewDate);
extern PACKAGE Word __fastcall CurrentYear(void);
extern PACKAGE void __fastcall DateTimeToString(AnsiString &Result, const AnsiString Format, System::TDateTime DateTime);
extern PACKAGE bool __fastcall TryFloatToDateTime(const Extended Value, /* out */ System::TDateTime &AResult);
extern PACKAGE System::TDateTime __fastcall FloatToDateTime(const Extended Value);
extern PACKAGE AnsiString __fastcall DateToStr(const System::TDateTime DateTime);
extern PACKAGE AnsiString __fastcall TimeToStr(const System::TDateTime DateTime);
extern PACKAGE AnsiString __fastcall DateTimeToStr(const System::TDateTime DateTime);
extern PACKAGE AnsiString __fastcall FormatDateTime(const AnsiString Format, System::TDateTime DateTime);
extern PACKAGE System::TDateTime __fastcall StrToDate(const AnsiString S);
extern PACKAGE System::TDateTime __fastcall StrToDateDef(const AnsiString S, const System::TDateTime Default);
extern PACKAGE bool __fastcall TryStrToDate(const AnsiString S, /* out */ System::TDateTime &Value);
extern PACKAGE System::TDateTime __fastcall StrToTime(const AnsiString S);
extern PACKAGE System::TDateTime __fastcall StrToTimeDef(const AnsiString S, const System::TDateTime Default);
extern PACKAGE bool __fastcall TryStrToTime(const AnsiString S, /* out */ System::TDateTime &Value);
extern PACKAGE System::TDateTime __fastcall StrToDateTime(const AnsiString S);
extern PACKAGE System::TDateTime __fastcall StrToDateTimeDef(const AnsiString S, const System::TDateTime Default);
extern PACKAGE bool __fastcall TryStrToDateTime(const AnsiString S, /* out */ System::TDateTime &Value);
extern PACKAGE AnsiString __fastcall SysErrorMessage(int ErrorCode);
extern PACKAGE AnsiString __fastcall GetLocaleStr(int Locale, int LocaleType, const AnsiString Default);
extern PACKAGE char __fastcall GetLocaleChar(int Locale, int LocaleType, char Default);
extern PACKAGE int __fastcall ExceptionErrorMessage(System::TObject* ExceptObject, void * ExceptAddr, char * Buffer, int Size);
extern PACKAGE void __fastcall ShowException(System::TObject* ExceptObject, void * ExceptAddr);
extern PACKAGE void __fastcall Abort(void);
extern PACKAGE void __fastcall OutOfMemoryError(void);
extern PACKAGE bool __fastcall CheckWin32Version(int AMajor, int AMinor = 0x0);
extern PACKAGE void __fastcall Beep(void);
extern PACKAGE TMbcsByteType __fastcall ByteType(const AnsiString S, int Index);
extern PACKAGE TMbcsByteType __fastcall StrByteType(char * Str, unsigned Index);
extern PACKAGE int __fastcall ByteToCharLen(const AnsiString S, int MaxLen);
extern PACKAGE int __fastcall ByteToCharIndex(const AnsiString S, int Index);
extern PACKAGE int __fastcall CharToByteIndex(const AnsiString S, int Index);
extern PACKAGE int __fastcall CharToByteLen(const AnsiString S, int MaxLen);
extern PACKAGE int __fastcall StrCharLength(const char * Str);
extern PACKAGE char * __fastcall StrNextChar(const char * Str);
extern PACKAGE int __fastcall CharLength(const AnsiString S, int Index);
extern PACKAGE int __fastcall NextCharIndex(const AnsiString S, int Index);
extern PACKAGE bool __fastcall IsPathDelimiter(const AnsiString S, int Index);
extern PACKAGE bool __fastcall IsDelimiter(const AnsiString Delimiters, const AnsiString S, int Index);
extern PACKAGE AnsiString __fastcall IncludeTrailingBackslash(const AnsiString S);
extern PACKAGE AnsiString __fastcall IncludeTrailingPathDelimiter(const AnsiString S);
extern PACKAGE AnsiString __fastcall ExcludeTrailingBackslash(const AnsiString S);
extern PACKAGE AnsiString __fastcall ExcludeTrailingPathDelimiter(const AnsiString S);
extern PACKAGE int __fastcall AnsiPos(const AnsiString Substr, const AnsiString S);
extern PACKAGE int __fastcall AnsiCompareFileName(const AnsiString S1, const AnsiString S2);
extern PACKAGE bool __fastcall SameFileName(const AnsiString S1, const AnsiString S2);
extern PACKAGE AnsiString __fastcall AnsiLowerCaseFileName(const AnsiString S);
extern PACKAGE AnsiString __fastcall AnsiUpperCaseFileName(const AnsiString S);
extern PACKAGE char * __fastcall AnsiStrPos(char * Str, char * SubStr);
extern PACKAGE char * __fastcall AnsiStrRScan(char * Str, char Chr);
extern PACKAGE char * __fastcall AnsiStrScan(char * Str, char Chr);
extern PACKAGE void __fastcall GetFormatSettings(void);
extern PACKAGE AnsiString __fastcall StringReplace(const AnsiString S, const AnsiString OldPattern, const AnsiString NewPattern, TReplaceFlags Flags);
extern PACKAGE AnsiString __fastcall WrapText(const AnsiString Line, const AnsiString BreakStr, const TSysCharSet &BreakChars, int MaxCol)/* overload */;
extern PACKAGE AnsiString __fastcall WrapText(const AnsiString Line, int MaxCol = 0x2d)/* overload */;
extern PACKAGE bool __fastcall FindCmdLineSwitch(const AnsiString Switch, const TSysCharSet &Chars, bool IgnoreCase)/* overload */;
extern PACKAGE bool __fastcall FindCmdLineSwitch(const AnsiString Switch)/* overload */;
extern PACKAGE bool __fastcall FindCmdLineSwitch(const AnsiString Switch, bool IgnoreCase)/* overload */;
extern PACKAGE AnsiString __fastcall GetModuleName(unsigned Module);
extern PACKAGE void __fastcall InitializePackage(unsigned Module);
extern PACKAGE void __fastcall FinalizePackage(unsigned Module);
extern PACKAGE unsigned __fastcall LoadPackage(const AnsiString Name);
extern PACKAGE void __fastcall UnloadPackage(unsigned Module);
extern PACKAGE void __fastcall GetPackageInfo(unsigned Module, void * Param, int &Flags, TPackageInfoProc InfoProc);
extern PACKAGE AnsiString __fastcall GetPackageDescription(char * ModuleName);
extern PACKAGE void __fastcall RaiseLastOSError(void);
extern PACKAGE void __fastcall RaiseLastWin32Error(void);
extern PACKAGE BOOL __fastcall Win32Check(BOOL RetVal);
extern PACKAGE void __fastcall AddTerminateProc(TTerminateProc TermProc);
extern PACKAGE bool __fastcall CallTerminateProcs(void);
extern PACKAGE unsigned __fastcall GDAL(void);
extern PACKAGE void __fastcall RCS(void);
extern PACKAGE void __fastcall RPR(void);
extern PACKAGE void __fastcall FreeAndNil(void *Obj);
extern PACKAGE bool __fastcall Supports(const System::_di_IInterface Instance, const GUID &IID, /* out */ void *Intf)/* overload */;
extern PACKAGE bool __fastcall Supports(const System::TObject* Instance, const GUID &IID, /* out */ void *Intf)/* overload */;
extern PACKAGE bool __fastcall Supports(const System::_di_IInterface Instance, const GUID &IID)/* overload */;
extern PACKAGE bool __fastcall Supports(const System::TObject* Instance, const GUID &IID)/* overload */;
extern PACKAGE bool __fastcall Supports(const TMetaClass* AClass, const GUID &IID)/* overload */;
extern PACKAGE TLanguages* __fastcall Languages(void);
extern PACKAGE unsigned __fastcall SafeLoadLibrary(const AnsiString Filename, unsigned ErrorMode = (unsigned)(0x8000));
extern PACKAGE AnsiString __fastcall GetEnvironmentVariable(const AnsiString Name)/* overload */;

}	/* namespace Sysutils */
using namespace Sysutils;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SysUtils
