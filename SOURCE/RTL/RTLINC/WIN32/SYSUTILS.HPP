//----------------------------------------------------------------------------
// SysUtils.hpp - bcbdcc32 generated hdr (DO NOT EDIT) rev: 0
// From: SysUtils.pas
//----------------------------------------------------------------------------
#ifndef SysUtilsHPP
#define SysUtilsHPP
//----------------------------------------------------------------------------
#include <Windows.hpp>
#include <System.hpp>
#pragma warn -par
#pragma warn -hid 
#pragma warn -inl

namespace Sysutils
{
//-- type declarations -------------------------------------------------------
#pragma pack(push, 1)
struct WordRec
{
	unsigned char Lo;
	unsigned char Hi;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct LongRec
{
	unsigned short Lo;
	unsigned short Hi;
} ;
#pragma pack(pop)

struct TMethod
{
	void *Code;
	void *Data;
} ;

typedef unsigned char TByteArray[32768];

typedef TByteArray *PByteArray;

typedef unsigned short TWordArray[16384];

typedef TWordArray *PWordArray;

typedef void __fastcall (*TProcedure)(void);

typedef System::AnsiString TFileName;

struct TSearchRec
{
	int Time;
	int Size;
	int Attr;
	System::AnsiString Name;
	int ExcludeAttr;
	int FindHandle;
	WIN32_FIND_DATAA FindData;
} ;

struct TFileRec
{
	int Handle;
	int Mode;
	unsigned int RecSize;
	unsigned char Private[28];
	unsigned char UserData[32];
	char Name[260];
} ;

typedef char TTextBuf[128];

typedef TTextBuf *PTextBuf;

struct TTextRec
{
	int Handle;
	int Mode;
	unsigned int BufSize;
	unsigned int BufPos;
	unsigned int BufEnd;
	char *BufPtr;
	void *OpenFunc;
	void *InOutFunc;
	void *FlushFunc;
	void *CloseFunc;
	unsigned char UserData[32];
	char Name[260];
	char Buffer[128];
} ;

enum TFloatValue { fvExtended, fvCurrency };

enum TFloatFormat { ffGeneral, ffExponent, ffFixed, ffNumber, ffCurrency };

#pragma pack(push, 1)
struct TFloatRec
{
	short Exponent;
	bool Negative;
	char Digits[21];
} ;
#pragma pack(pop)

struct TTimeStamp
{
	int Time;
	int Date;
} ;

enum TMbcsByteType { mbSingleByte, mbLeadByte, mbTrailByte };

#pragma pack(push, 1)
struct TSysLocale
{
	int DefaultLCID;
	unsigned short PriLangID;
	unsigned short SubLangID;
	bool FarEast;
} ;
#pragma pack(pop)

class __declspec(delphiclass) Exception;
class __declspec(pascalimplementation) Exception : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::AnsiString FMessage;
	int FHelpContext;
	
public:
	__fastcall Exception(const System::AnsiString Msg);
	__fastcall Exception(const System::AnsiString Msg, const System::TVarRec *Args, const int Args_Size
		);
	__fastcall Exception(int Ident);
	__fastcall Exception(int Ident, const System::TVarRec *Args, const int Args_Size);
	__fastcall Exception(const System::AnsiString Msg, int AHelpContext);
	__fastcall Exception(const System::AnsiString Msg, const System::TVarRec *Args, const int Args_Size
		, int AHelpContext);
	__fastcall Exception(int Ident, int AHelpContext);
	__fastcall Exception(int Ident, const System::TVarRec *Args, const int Args_Size, int AHelpContext)
		;
	__property int HelpContext = {read=FHelpContext, write=FHelpContext, nodefault};
	__property System::AnsiString Message = {read=FMessage, write=FMessage, nodefault};
public:
	/* TObject.Destroy */ __fastcall virtual ~Exception(void) { }
	
};

typedef System::TMetaClass*ExceptClass;

class __declspec(delphiclass) EAbort;
class __declspec(pascalimplementation) EAbort : public Exception
{
	typedef Exception inherited;
	
public:
	/* Exception.Create */ __fastcall EAbort(const System::AnsiString Msg) : Sysutils::Exception(Msg) { }
		
	/* Exception.CreateFmt */ __fastcall EAbort(const System::AnsiString Msg, const System::TVarRec *Args
		, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ __fastcall EAbort(int Ident) : Sysutils::Exception(Ident) { }
	/* Exception.CreateResFmt */ __fastcall EAbort(int Ident, const System::TVarRec *Args, const int Args_Size
		) : Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ __fastcall EAbort(const System::AnsiString Msg, int AHelpContext) : Sysutils::
		Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ __fastcall EAbort(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	/* Exception.CreateResHelp */ __fastcall EAbort(int Ident, int AHelpContext) : Sysutils::Exception(
		Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ __fastcall EAbort(int Ident, const System::TVarRec *Args, const int 
		Args_Size, int AHelpContext) : Sysutils::Exception(Ident, Args, Args_Size, AHelpContext) { }
	
public:
	/* TObject.Destroy */ __fastcall virtual ~EAbort(void) { }
	
};

class __declspec(delphiclass) EOutOfMemory;
class __declspec(pascalimplementation) EOutOfMemory : public Exception
{
	typedef Exception inherited;
	
public:
	__fastcall virtual ~EOutOfMemory(void);
	virtual void __fastcall FreeInstance(void);
public:
	/* Exception.Create */ __fastcall EOutOfMemory(const System::AnsiString Msg) : Sysutils::Exception(
		Msg) { }
	/* Exception.CreateFmt */ __fastcall EOutOfMemory(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ __fastcall EOutOfMemory(int Ident) : Sysutils::Exception(Ident) { }
	/* Exception.CreateResFmt */ __fastcall EOutOfMemory(int Ident, const System::TVarRec *Args, const 
		int Args_Size) : Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ __fastcall EOutOfMemory(const System::AnsiString Msg, int AHelpContext) : 
		Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ __fastcall EOutOfMemory(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	/* Exception.CreateResHelp */ __fastcall EOutOfMemory(int Ident, int AHelpContext) : Sysutils::Exception(
		Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ __fastcall EOutOfMemory(int Ident, const System::TVarRec *Args, const 
		int Args_Size, int AHelpContext) : Sysutils::Exception(Ident, Args, Args_Size, AHelpContext) { }
	
};

class __declspec(delphiclass) EInOutError;
class __declspec(pascalimplementation) EInOutError : public Exception
{
	typedef Exception inherited;
	
public:
	int ErrorCode;
public:
	/* Exception.Create */ __fastcall EInOutError(const System::AnsiString Msg) : Sysutils::Exception(Msg
		) { }
	/* Exception.CreateFmt */ __fastcall EInOutError(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ __fastcall EInOutError(int Ident) : Sysutils::Exception(Ident) { }
	/* Exception.CreateResFmt */ __fastcall EInOutError(int Ident, const System::TVarRec *Args, const int 
		Args_Size) : Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ __fastcall EInOutError(const System::AnsiString Msg, int AHelpContext) : 
		Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ __fastcall EInOutError(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	/* Exception.CreateResHelp */ __fastcall EInOutError(int Ident, int AHelpContext) : Sysutils::Exception(
		Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ __fastcall EInOutError(int Ident, const System::TVarRec *Args, const 
		int Args_Size, int AHelpContext) : Sysutils::Exception(Ident, Args, Args_Size, AHelpContext) { }
	
public:
	/* TObject.Destroy */ __fastcall virtual ~EInOutError(void) { }
	
};

class __declspec(delphiclass) EIntError;
class __declspec(pascalimplementation) EIntError : public Exception
{
	typedef Exception inherited;
	
public:
	/* Exception.Create */ __fastcall EIntError(const System::AnsiString Msg) : Sysutils::Exception(Msg
		) { }
	/* Exception.CreateFmt */ __fastcall EIntError(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ __fastcall EIntError(int Ident) : Sysutils::Exception(Ident) { }
	/* Exception.CreateResFmt */ __fastcall EIntError(int Ident, const System::TVarRec *Args, const int 
		Args_Size) : Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ __fastcall EIntError(const System::AnsiString Msg, int AHelpContext) : Sysutils::
		Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ __fastcall EIntError(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	/* Exception.CreateResHelp */ __fastcall EIntError(int Ident, int AHelpContext) : Sysutils::Exception(
		Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ __fastcall EIntError(int Ident, const System::TVarRec *Args, const 
		int Args_Size, int AHelpContext) : Sysutils::Exception(Ident, Args, Args_Size, AHelpContext) { }
	
public:
	/* TObject.Destroy */ __fastcall virtual ~EIntError(void) { }
	
};

class __declspec(delphiclass) EDivByZero;
class __declspec(pascalimplementation) EDivByZero : public EIntError
{
	typedef EIntError inherited;
	
public:
	/* Exception.Create */ __fastcall EDivByZero(const System::AnsiString Msg) : Sysutils::EIntError(Msg
		) { }
	/* Exception.CreateFmt */ __fastcall EDivByZero(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size) : Sysutils::EIntError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ __fastcall EDivByZero(int Ident) : Sysutils::EIntError(Ident) { }
	/* Exception.CreateResFmt */ __fastcall EDivByZero(int Ident, const System::TVarRec *Args, const int 
		Args_Size) : Sysutils::EIntError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ __fastcall EDivByZero(const System::AnsiString Msg, int AHelpContext) : 
		Sysutils::EIntError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ __fastcall EDivByZero(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size, int AHelpContext) : Sysutils::EIntError(Msg, Args, Args_Size, AHelpContext
		) { }
	/* Exception.CreateResHelp */ __fastcall EDivByZero(int Ident, int AHelpContext) : Sysutils::EIntError(
		Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ __fastcall EDivByZero(int Ident, const System::TVarRec *Args, const 
		int Args_Size, int AHelpContext) : Sysutils::EIntError(Ident, Args, Args_Size, AHelpContext) { }
	
public:
	/* TObject.Destroy */ __fastcall virtual ~EDivByZero(void) { }
	
};

class __declspec(delphiclass) ERangeError;
class __declspec(pascalimplementation) ERangeError : public EIntError
{
	typedef EIntError inherited;
	
public:
	/* Exception.Create */ __fastcall ERangeError(const System::AnsiString Msg) : Sysutils::EIntError(Msg
		) { }
	/* Exception.CreateFmt */ __fastcall ERangeError(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size) : Sysutils::EIntError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ __fastcall ERangeError(int Ident) : Sysutils::EIntError(Ident) { }
	/* Exception.CreateResFmt */ __fastcall ERangeError(int Ident, const System::TVarRec *Args, const int 
		Args_Size) : Sysutils::EIntError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ __fastcall ERangeError(const System::AnsiString Msg, int AHelpContext) : 
		Sysutils::EIntError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ __fastcall ERangeError(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size, int AHelpContext) : Sysutils::EIntError(Msg, Args, Args_Size, AHelpContext
		) { }
	/* Exception.CreateResHelp */ __fastcall ERangeError(int Ident, int AHelpContext) : Sysutils::EIntError(
		Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ __fastcall ERangeError(int Ident, const System::TVarRec *Args, const 
		int Args_Size, int AHelpContext) : Sysutils::EIntError(Ident, Args, Args_Size, AHelpContext) { }
	
public:
	/* TObject.Destroy */ __fastcall virtual ~ERangeError(void) { }
	
};

class __declspec(delphiclass) EIntOverflow;
class __declspec(pascalimplementation) EIntOverflow : public EIntError
{
	typedef EIntError inherited;
	
public:
	/* Exception.Create */ __fastcall EIntOverflow(const System::AnsiString Msg) : Sysutils::EIntError(
		Msg) { }
	/* Exception.CreateFmt */ __fastcall EIntOverflow(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size) : Sysutils::EIntError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ __fastcall EIntOverflow(int Ident) : Sysutils::EIntError(Ident) { }
	/* Exception.CreateResFmt */ __fastcall EIntOverflow(int Ident, const System::TVarRec *Args, const 
		int Args_Size) : Sysutils::EIntError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ __fastcall EIntOverflow(const System::AnsiString Msg, int AHelpContext) : 
		Sysutils::EIntError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ __fastcall EIntOverflow(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size, int AHelpContext) : Sysutils::EIntError(Msg, Args, Args_Size, AHelpContext
		) { }
	/* Exception.CreateResHelp */ __fastcall EIntOverflow(int Ident, int AHelpContext) : Sysutils::EIntError(
		Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ __fastcall EIntOverflow(int Ident, const System::TVarRec *Args, const 
		int Args_Size, int AHelpContext) : Sysutils::EIntError(Ident, Args, Args_Size, AHelpContext) { }
	
public:
	/* TObject.Destroy */ __fastcall virtual ~EIntOverflow(void) { }
	
};

class __declspec(delphiclass) EMathError;
class __declspec(pascalimplementation) EMathError : public Exception
{
	typedef Exception inherited;
	
public:
	/* Exception.Create */ __fastcall EMathError(const System::AnsiString Msg) : Sysutils::Exception(Msg
		) { }
	/* Exception.CreateFmt */ __fastcall EMathError(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ __fastcall EMathError(int Ident) : Sysutils::Exception(Ident) { }
	/* Exception.CreateResFmt */ __fastcall EMathError(int Ident, const System::TVarRec *Args, const int 
		Args_Size) : Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ __fastcall EMathError(const System::AnsiString Msg, int AHelpContext) : 
		Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ __fastcall EMathError(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	/* Exception.CreateResHelp */ __fastcall EMathError(int Ident, int AHelpContext) : Sysutils::Exception(
		Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ __fastcall EMathError(int Ident, const System::TVarRec *Args, const 
		int Args_Size, int AHelpContext) : Sysutils::Exception(Ident, Args, Args_Size, AHelpContext) { }
	
public:
	/* TObject.Destroy */ __fastcall virtual ~EMathError(void) { }
	
};

class __declspec(delphiclass) EInvalidOp;
class __declspec(pascalimplementation) EInvalidOp : public EMathError
{
	typedef EMathError inherited;
	
public:
	/* Exception.Create */ __fastcall EInvalidOp(const System::AnsiString Msg) : Sysutils::EMathError(Msg
		) { }
	/* Exception.CreateFmt */ __fastcall EInvalidOp(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size) : Sysutils::EMathError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ __fastcall EInvalidOp(int Ident) : Sysutils::EMathError(Ident) { }
	/* Exception.CreateResFmt */ __fastcall EInvalidOp(int Ident, const System::TVarRec *Args, const int 
		Args_Size) : Sysutils::EMathError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ __fastcall EInvalidOp(const System::AnsiString Msg, int AHelpContext) : 
		Sysutils::EMathError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ __fastcall EInvalidOp(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size, int AHelpContext) : Sysutils::EMathError(Msg, Args, Args_Size, AHelpContext
		) { }
	/* Exception.CreateResHelp */ __fastcall EInvalidOp(int Ident, int AHelpContext) : Sysutils::EMathError(
		Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ __fastcall EInvalidOp(int Ident, const System::TVarRec *Args, const 
		int Args_Size, int AHelpContext) : Sysutils::EMathError(Ident, Args, Args_Size, AHelpContext) { }
	
public:
	/* TObject.Destroy */ __fastcall virtual ~EInvalidOp(void) { }
	
};

class __declspec(delphiclass) EZeroDivide;
class __declspec(pascalimplementation) EZeroDivide : public EMathError
{
	typedef EMathError inherited;
	
public:
	/* Exception.Create */ __fastcall EZeroDivide(const System::AnsiString Msg) : Sysutils::EMathError(
		Msg) { }
	/* Exception.CreateFmt */ __fastcall EZeroDivide(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size) : Sysutils::EMathError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ __fastcall EZeroDivide(int Ident) : Sysutils::EMathError(Ident) { }
	/* Exception.CreateResFmt */ __fastcall EZeroDivide(int Ident, const System::TVarRec *Args, const int 
		Args_Size) : Sysutils::EMathError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ __fastcall EZeroDivide(const System::AnsiString Msg, int AHelpContext) : 
		Sysutils::EMathError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ __fastcall EZeroDivide(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size, int AHelpContext) : Sysutils::EMathError(Msg, Args, Args_Size, AHelpContext
		) { }
	/* Exception.CreateResHelp */ __fastcall EZeroDivide(int Ident, int AHelpContext) : Sysutils::EMathError(
		Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ __fastcall EZeroDivide(int Ident, const System::TVarRec *Args, const 
		int Args_Size, int AHelpContext) : Sysutils::EMathError(Ident, Args, Args_Size, AHelpContext) { }
	
public:
	/* TObject.Destroy */ __fastcall virtual ~EZeroDivide(void) { }
	
};

class __declspec(delphiclass) EOverflow;
class __declspec(pascalimplementation) EOverflow : public EMathError
{
	typedef EMathError inherited;
	
public:
	/* Exception.Create */ __fastcall EOverflow(const System::AnsiString Msg) : Sysutils::EMathError(Msg
		) { }
	/* Exception.CreateFmt */ __fastcall EOverflow(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size) : Sysutils::EMathError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ __fastcall EOverflow(int Ident) : Sysutils::EMathError(Ident) { }
	/* Exception.CreateResFmt */ __fastcall EOverflow(int Ident, const System::TVarRec *Args, const int 
		Args_Size) : Sysutils::EMathError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ __fastcall EOverflow(const System::AnsiString Msg, int AHelpContext) : Sysutils::
		EMathError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ __fastcall EOverflow(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size, int AHelpContext) : Sysutils::EMathError(Msg, Args, Args_Size, AHelpContext
		) { }
	/* Exception.CreateResHelp */ __fastcall EOverflow(int Ident, int AHelpContext) : Sysutils::EMathError(
		Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ __fastcall EOverflow(int Ident, const System::TVarRec *Args, const 
		int Args_Size, int AHelpContext) : Sysutils::EMathError(Ident, Args, Args_Size, AHelpContext) { }
	
public:
	/* TObject.Destroy */ __fastcall virtual ~EOverflow(void) { }
	
};

class __declspec(delphiclass) EUnderflow;
class __declspec(pascalimplementation) EUnderflow : public EMathError
{
	typedef EMathError inherited;
	
public:
	/* Exception.Create */ __fastcall EUnderflow(const System::AnsiString Msg) : Sysutils::EMathError(Msg
		) { }
	/* Exception.CreateFmt */ __fastcall EUnderflow(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size) : Sysutils::EMathError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ __fastcall EUnderflow(int Ident) : Sysutils::EMathError(Ident) { }
	/* Exception.CreateResFmt */ __fastcall EUnderflow(int Ident, const System::TVarRec *Args, const int 
		Args_Size) : Sysutils::EMathError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ __fastcall EUnderflow(const System::AnsiString Msg, int AHelpContext) : 
		Sysutils::EMathError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ __fastcall EUnderflow(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size, int AHelpContext) : Sysutils::EMathError(Msg, Args, Args_Size, AHelpContext
		) { }
	/* Exception.CreateResHelp */ __fastcall EUnderflow(int Ident, int AHelpContext) : Sysutils::EMathError(
		Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ __fastcall EUnderflow(int Ident, const System::TVarRec *Args, const 
		int Args_Size, int AHelpContext) : Sysutils::EMathError(Ident, Args, Args_Size, AHelpContext) { }
	
public:
	/* TObject.Destroy */ __fastcall virtual ~EUnderflow(void) { }
	
};

class __declspec(delphiclass) EInvalidPointer;
class __declspec(pascalimplementation) EInvalidPointer : public Exception
{
	typedef Exception inherited;
	
public:
	/* Exception.Create */ __fastcall EInvalidPointer(const System::AnsiString Msg) : Sysutils::Exception(
		Msg) { }
	/* Exception.CreateFmt */ __fastcall EInvalidPointer(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ __fastcall EInvalidPointer(int Ident) : Sysutils::Exception(Ident) { }
	/* Exception.CreateResFmt */ __fastcall EInvalidPointer(int Ident, const System::TVarRec *Args, const 
		int Args_Size) : Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ __fastcall EInvalidPointer(const System::AnsiString Msg, int AHelpContext
		) : Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ __fastcall EInvalidPointer(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	/* Exception.CreateResHelp */ __fastcall EInvalidPointer(int Ident, int AHelpContext) : Sysutils::Exception(
		Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ __fastcall EInvalidPointer(int Ident, const System::TVarRec *Args, 
		const int Args_Size, int AHelpContext) : Sysutils::Exception(Ident, Args, Args_Size, AHelpContext)
		 { }
	
public:
	/* TObject.Destroy */ __fastcall virtual ~EInvalidPointer(void) { }
	
};

class __declspec(delphiclass) EInvalidCast;
class __declspec(pascalimplementation) EInvalidCast : public Exception
{
	typedef Exception inherited;
	
public:
	/* Exception.Create */ __fastcall EInvalidCast(const System::AnsiString Msg) : Sysutils::Exception(
		Msg) { }
	/* Exception.CreateFmt */ __fastcall EInvalidCast(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ __fastcall EInvalidCast(int Ident) : Sysutils::Exception(Ident) { }
	/* Exception.CreateResFmt */ __fastcall EInvalidCast(int Ident, const System::TVarRec *Args, const 
		int Args_Size) : Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ __fastcall EInvalidCast(const System::AnsiString Msg, int AHelpContext) : 
		Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ __fastcall EInvalidCast(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	/* Exception.CreateResHelp */ __fastcall EInvalidCast(int Ident, int AHelpContext) : Sysutils::Exception(
		Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ __fastcall EInvalidCast(int Ident, const System::TVarRec *Args, const 
		int Args_Size, int AHelpContext) : Sysutils::Exception(Ident, Args, Args_Size, AHelpContext) { }
	
public:
	/* TObject.Destroy */ __fastcall virtual ~EInvalidCast(void) { }
	
};

class __declspec(delphiclass) EConvertError;
class __declspec(pascalimplementation) EConvertError : public Exception
{
	typedef Exception inherited;
	
public:
	/* Exception.Create */ __fastcall EConvertError(const System::AnsiString Msg) : Sysutils::Exception(
		Msg) { }
	/* Exception.CreateFmt */ __fastcall EConvertError(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ __fastcall EConvertError(int Ident) : Sysutils::Exception(Ident) { }
	/* Exception.CreateResFmt */ __fastcall EConvertError(int Ident, const System::TVarRec *Args, const 
		int Args_Size) : Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ __fastcall EConvertError(const System::AnsiString Msg, int AHelpContext)
		 : Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ __fastcall EConvertError(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	/* Exception.CreateResHelp */ __fastcall EConvertError(int Ident, int AHelpContext) : Sysutils::Exception(
		Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ __fastcall EConvertError(int Ident, const System::TVarRec *Args, const 
		int Args_Size, int AHelpContext) : Sysutils::Exception(Ident, Args, Args_Size, AHelpContext) { }
	
public:
	/* TObject.Destroy */ __fastcall virtual ~EConvertError(void) { }
	
};

class __declspec(delphiclass) EAccessViolation;
class __declspec(pascalimplementation) EAccessViolation : public Exception
{
	typedef Exception inherited;
	
public:
	/* Exception.Create */ __fastcall EAccessViolation(const System::AnsiString Msg) : Sysutils::Exception(
		Msg) { }
	/* Exception.CreateFmt */ __fastcall EAccessViolation(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ __fastcall EAccessViolation(int Ident) : Sysutils::Exception(Ident) { }
	/* Exception.CreateResFmt */ __fastcall EAccessViolation(int Ident, const System::TVarRec *Args, const 
		int Args_Size) : Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ __fastcall EAccessViolation(const System::AnsiString Msg, int AHelpContext
		) : Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ __fastcall EAccessViolation(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	/* Exception.CreateResHelp */ __fastcall EAccessViolation(int Ident, int AHelpContext) : Sysutils::
		Exception(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ __fastcall EAccessViolation(int Ident, const System::TVarRec *Args
		, const int Args_Size, int AHelpContext) : Sysutils::Exception(Ident, Args, Args_Size, AHelpContext
		) { }
	
public:
	/* TObject.Destroy */ __fastcall virtual ~EAccessViolation(void) { }
	
};

class __declspec(delphiclass) EPrivilege;
class __declspec(pascalimplementation) EPrivilege : public Exception
{
	typedef Exception inherited;
	
public:
	/* Exception.Create */ __fastcall EPrivilege(const System::AnsiString Msg) : Sysutils::Exception(Msg
		) { }
	/* Exception.CreateFmt */ __fastcall EPrivilege(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ __fastcall EPrivilege(int Ident) : Sysutils::Exception(Ident) { }
	/* Exception.CreateResFmt */ __fastcall EPrivilege(int Ident, const System::TVarRec *Args, const int 
		Args_Size) : Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ __fastcall EPrivilege(const System::AnsiString Msg, int AHelpContext) : 
		Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ __fastcall EPrivilege(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	/* Exception.CreateResHelp */ __fastcall EPrivilege(int Ident, int AHelpContext) : Sysutils::Exception(
		Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ __fastcall EPrivilege(int Ident, const System::TVarRec *Args, const 
		int Args_Size, int AHelpContext) : Sysutils::Exception(Ident, Args, Args_Size, AHelpContext) { }
	
public:
	/* TObject.Destroy */ __fastcall virtual ~EPrivilege(void) { }
	
};

class __declspec(delphiclass) EStackOverflow;
class __declspec(pascalimplementation) EStackOverflow : public Exception
{
	typedef Exception inherited;
	
public:
	/* Exception.Create */ __fastcall EStackOverflow(const System::AnsiString Msg) : Sysutils::Exception(
		Msg) { }
	/* Exception.CreateFmt */ __fastcall EStackOverflow(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ __fastcall EStackOverflow(int Ident) : Sysutils::Exception(Ident) { }
	/* Exception.CreateResFmt */ __fastcall EStackOverflow(int Ident, const System::TVarRec *Args, const 
		int Args_Size) : Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ __fastcall EStackOverflow(const System::AnsiString Msg, int AHelpContext
		) : Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ __fastcall EStackOverflow(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	/* Exception.CreateResHelp */ __fastcall EStackOverflow(int Ident, int AHelpContext) : Sysutils::Exception(
		Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ __fastcall EStackOverflow(int Ident, const System::TVarRec *Args, 
		const int Args_Size, int AHelpContext) : Sysutils::Exception(Ident, Args, Args_Size, AHelpContext)
		 { }
	
public:
	/* TObject.Destroy */ __fastcall virtual ~EStackOverflow(void) { }
	
};

class __declspec(delphiclass) EControlC;
class __declspec(pascalimplementation) EControlC : public Exception
{
	typedef Exception inherited;
	
public:
	/* Exception.Create */ __fastcall EControlC(const System::AnsiString Msg) : Sysutils::Exception(Msg
		) { }
	/* Exception.CreateFmt */ __fastcall EControlC(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ __fastcall EControlC(int Ident) : Sysutils::Exception(Ident) { }
	/* Exception.CreateResFmt */ __fastcall EControlC(int Ident, const System::TVarRec *Args, const int 
		Args_Size) : Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ __fastcall EControlC(const System::AnsiString Msg, int AHelpContext) : Sysutils::
		Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ __fastcall EControlC(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	/* Exception.CreateResHelp */ __fastcall EControlC(int Ident, int AHelpContext) : Sysutils::Exception(
		Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ __fastcall EControlC(int Ident, const System::TVarRec *Args, const 
		int Args_Size, int AHelpContext) : Sysutils::Exception(Ident, Args, Args_Size, AHelpContext) { }
	
public:
	/* TObject.Destroy */ __fastcall virtual ~EControlC(void) { }
	
};

class __declspec(delphiclass) EVariantError;
class __declspec(pascalimplementation) EVariantError : public Exception
{
	typedef Exception inherited;
	
public:
	/* Exception.Create */ __fastcall EVariantError(const System::AnsiString Msg) : Sysutils::Exception(
		Msg) { }
	/* Exception.CreateFmt */ __fastcall EVariantError(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ __fastcall EVariantError(int Ident) : Sysutils::Exception(Ident) { }
	/* Exception.CreateResFmt */ __fastcall EVariantError(int Ident, const System::TVarRec *Args, const 
		int Args_Size) : Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ __fastcall EVariantError(const System::AnsiString Msg, int AHelpContext)
		 : Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ __fastcall EVariantError(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	/* Exception.CreateResHelp */ __fastcall EVariantError(int Ident, int AHelpContext) : Sysutils::Exception(
		Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ __fastcall EVariantError(int Ident, const System::TVarRec *Args, const 
		int Args_Size, int AHelpContext) : Sysutils::Exception(Ident, Args, Args_Size, AHelpContext) { }
	
public:
	/* TObject.Destroy */ __fastcall virtual ~EVariantError(void) { }
	
};

class __declspec(delphiclass) EPropReadOnly;
class __declspec(pascalimplementation) EPropReadOnly : public Exception
{
	typedef Exception inherited;
	
public:
	/* Exception.Create */ __fastcall EPropReadOnly(const System::AnsiString Msg) : Sysutils::Exception(
		Msg) { }
	/* Exception.CreateFmt */ __fastcall EPropReadOnly(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ __fastcall EPropReadOnly(int Ident) : Sysutils::Exception(Ident) { }
	/* Exception.CreateResFmt */ __fastcall EPropReadOnly(int Ident, const System::TVarRec *Args, const 
		int Args_Size) : Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ __fastcall EPropReadOnly(const System::AnsiString Msg, int AHelpContext)
		 : Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ __fastcall EPropReadOnly(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	/* Exception.CreateResHelp */ __fastcall EPropReadOnly(int Ident, int AHelpContext) : Sysutils::Exception(
		Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ __fastcall EPropReadOnly(int Ident, const System::TVarRec *Args, const 
		int Args_Size, int AHelpContext) : Sysutils::Exception(Ident, Args, Args_Size, AHelpContext) { }
	
public:
	/* TObject.Destroy */ __fastcall virtual ~EPropReadOnly(void) { }
	
};

class __declspec(delphiclass) EPropWriteOnly;
class __declspec(pascalimplementation) EPropWriteOnly : public Exception
{
	typedef Exception inherited;
	
public:
	/* Exception.Create */ __fastcall EPropWriteOnly(const System::AnsiString Msg) : Sysutils::Exception(
		Msg) { }
	/* Exception.CreateFmt */ __fastcall EPropWriteOnly(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ __fastcall EPropWriteOnly(int Ident) : Sysutils::Exception(Ident) { }
	/* Exception.CreateResFmt */ __fastcall EPropWriteOnly(int Ident, const System::TVarRec *Args, const 
		int Args_Size) : Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ __fastcall EPropWriteOnly(const System::AnsiString Msg, int AHelpContext
		) : Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ __fastcall EPropWriteOnly(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	/* Exception.CreateResHelp */ __fastcall EPropWriteOnly(int Ident, int AHelpContext) : Sysutils::Exception(
		Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ __fastcall EPropWriteOnly(int Ident, const System::TVarRec *Args, 
		const int Args_Size, int AHelpContext) : Sysutils::Exception(Ident, Args, Args_Size, AHelpContext)
		 { }
	
public:
	/* TObject.Destroy */ __fastcall virtual ~EPropWriteOnly(void) { }
	
};

class __declspec(delphiclass) EExternalException;
class __declspec(pascalimplementation) EExternalException : public Exception
{
	typedef Exception inherited;
	
public:
	EXCEPTION_RECORD *ExceptionRecord;
public:
	/* Exception.Create */ __fastcall EExternalException(const System::AnsiString Msg) : Sysutils::Exception(
		Msg) { }
	/* Exception.CreateFmt */ __fastcall EExternalException(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ __fastcall EExternalException(int Ident) : Sysutils::Exception(Ident) { }
		
	/* Exception.CreateResFmt */ __fastcall EExternalException(int Ident, const System::TVarRec *Args, 
		const int Args_Size) : Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ __fastcall EExternalException(const System::AnsiString Msg, int AHelpContext
		) : Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ __fastcall EExternalException(const System::AnsiString Msg, const System::TVarRec 
		*Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	/* Exception.CreateResHelp */ __fastcall EExternalException(int Ident, int AHelpContext) : Sysutils::
		Exception(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ __fastcall EExternalException(int Ident, const System::TVarRec *Args
		, const int Args_Size, int AHelpContext) : Sysutils::Exception(Ident, Args, Args_Size, AHelpContext
		) { }
	
public:
	/* TObject.Destroy */ __fastcall virtual ~EExternalException(void) { }
	
};

//-- var, const, procedure ---------------------------------------------------
#define fmOpenRead (unsigned char)(0)
#define fmOpenWrite (unsigned char)(1)
#define fmOpenReadWrite (unsigned char)(2)
#define fmShareCompat (unsigned char)(0)
#define fmShareExclusive (unsigned char)(16)
#define fmShareDenyWrite (unsigned char)(32)
#define fmShareDenyRead (unsigned char)(48)
#define fmShareDenyNone (unsigned char)(64)
#define faReadOnly (unsigned char)(1)
#define faHidden (unsigned char)(2)
#define faSysFile (unsigned char)(4)
#define faVolumeID (unsigned char)(8)
#define faDirectory (unsigned char)(16)
#define faArchive (unsigned char)(32)
#define faAnyFile (unsigned char)(63)
#define fmClosed (int)(55216)
#define fmInput (int)(55217)
#define fmOutput (int)(55218)
#define fmInOut (int)(55219)
#define SecsPerDay (int)(86400)
#define MSecsPerDay (int)(86400000)
#define DateDelta (int)(693594)
extern System::AnsiString EmptyStr;
extern System::AnsiString *NullStr;
extern int Win32Platform;
extern System::AnsiString CurrencyString;
extern unsigned char CurrencyFormat;
extern unsigned char NegCurrFormat;
extern char ThousandSeparator;
extern char DecimalSeparator;
extern unsigned char CurrencyDecimals;
extern char DateSeparator;
extern System::AnsiString ShortDateFormat;
extern System::AnsiString LongDateFormat;
extern char TimeSeparator;
extern System::AnsiString TimeAMString;
extern System::AnsiString TimePMString;
extern System::AnsiString ShortTimeFormat;
extern System::AnsiString LongTimeFormat;
extern System::AnsiString ShortMonthNames[12];
extern System::AnsiString LongMonthNames[12];
extern System::AnsiString ShortDayNames[7];
extern System::AnsiString LongDayNames[7];
extern TSysLocale SysLocale;
//extern Set<Byte, 0, 255>  LeadBytes;
extern void * __fastcall AllocMem(unsigned int Size);
extern void __fastcall AddExitProc(TProcedure Proc);
extern System::PAnsiString __fastcall NewStr(const System::AnsiString S);
extern void __fastcall DisposeStr(System::PAnsiString P);
extern void __fastcall AssignStr(System::PAnsiString &P, const System::AnsiString S);
extern void __fastcall AppendStr( System::AnsiString &Dest, const System::AnsiString S);
extern System::AnsiString __fastcall UpperCase(const System::AnsiString S);
extern System::AnsiString __fastcall LowerCase(const System::AnsiString S);
extern int __fastcall CompareStr(const System::AnsiString S1, const System::AnsiString S2);
extern int __fastcall CompareText(const System::AnsiString S1, const System::AnsiString S2);
extern System::AnsiString __fastcall AnsiUpperCase(const System::AnsiString S);
extern System::AnsiString __fastcall AnsiLowerCase(const System::AnsiString S);
extern int __fastcall AnsiCompareStr(const System::AnsiString S1, const System::AnsiString S2);
extern int __fastcall AnsiCompareText(const System::AnsiString S1, const System::AnsiString S2);
extern int __fastcall AnsiStrComp(char * S1, char * S2);
extern int __fastcall AnsiStrIComp(char * S1, char * S2);
extern int __fastcall AnsiStrLComp(char * S1, char * S2, unsigned int MaxLen);
extern int __fastcall AnsiStrLIComp(char * S1, char * S2, unsigned int MaxLen);
extern char * __fastcall AnsiStrLower(char * Str);
extern char * __fastcall AnsiStrUpper(char * Str);
extern System::AnsiString __fastcall Trim(const System::AnsiString S);
extern System::AnsiString __fastcall TrimLeft(const System::AnsiString S);
extern System::AnsiString __fastcall TrimRight(const System::AnsiString S);
extern System::AnsiString __fastcall QuotedStr(const System::AnsiString S);
extern System::AnsiString __fastcall AnsiQuotedStr(const System::AnsiString S, char Quote);
extern System::AnsiString __fastcall AnsiExtractQuotedStr(char * &Src, char Quote);
extern System::AnsiString __fastcall AdjustLineBreaks(const System::AnsiString S);
extern bool __fastcall IsValidIdent(const System::AnsiString Ident);
extern System::AnsiString __fastcall IntToStr(int Value);
extern System::AnsiString __fastcall IntToHex(int Value, int Digits);
extern int __fastcall StrToInt(const System::AnsiString S);
extern int __fastcall StrToIntDef(const System::AnsiString S, int Default);
extern System::AnsiString __fastcall LoadStr(int Ident);
extern System::AnsiString __fastcall FmtLoadStr(int Ident, const System::TVarRec *Args, const int Args_Size
	);
extern int __fastcall FileOpen(const System::AnsiString FileName, int Mode);
extern int __fastcall FileCreate(const System::AnsiString FileName);
extern int __fastcall FileRead(int Handle, void *Buffer, int Count);
extern int __fastcall FileWrite(int Handle, const void *Buffer, int Count);
extern int __fastcall FileSeek(int Handle, int Offset, int Origin);
extern void __fastcall FileClose(int Handle);
extern int __fastcall FileAge(const System::AnsiString FileName);
extern bool __fastcall FileExists(const System::AnsiString FileName);
extern int __fastcall FileGetDate(int Handle);
extern int __fastcall FileSetDate(int Handle, int Age);
extern int __fastcall FileGetAttr(const System::AnsiString FileName);
extern int __fastcall FileSetAttr(const System::AnsiString FileName, int Attr);
extern int __fastcall FindFirst(const System::AnsiString Path, int Attr, TSearchRec &F);
extern int __fastcall FindNext(TSearchRec &F);
extern bool __fastcall RenameFile(const System::AnsiString OldName, const System::AnsiString NewName
	);
extern char * __fastcall AnsiStrLastChar(char * P);
extern char * __fastcall AnsiLastChar(const System::AnsiString S);
extern int __fastcall LastDelimiter(const System::AnsiString Delimiters, const System::AnsiString S)
	;
extern System::AnsiString __fastcall ChangeFileExt(const System::AnsiString FileName, const System::AnsiString 
	Extension);
extern System::AnsiString __fastcall ExtractFilePath(const System::AnsiString FileName);
extern System::AnsiString __fastcall ExtractFileDir(const System::AnsiString FileName);
extern System::AnsiString __fastcall ExtractFileDrive(const System::AnsiString FileName);
extern System::AnsiString __fastcall ExtractFileName(const System::AnsiString FileName);
extern System::AnsiString __fastcall ExtractFileExt(const System::AnsiString FileName);
extern System::AnsiString __fastcall ExpandFileName(const System::AnsiString FileName);
extern System::AnsiString __fastcall ExpandUNCFileName(const System::AnsiString FileName);
extern System::AnsiString __fastcall FileSearch(const System::AnsiString Name, const System::AnsiString 
	DirList);
extern int __fastcall DiskFree(unsigned char Drive);
extern int __fastcall DiskSize(unsigned char Drive);
extern System::TDateTime __fastcall FileDateToDateTime(int FileDate);
extern int __fastcall DateTimeToFileDate(System::TDateTime DateTime);
extern System::AnsiString __fastcall GetCurrentDir(void);
extern bool __fastcall SetCurrentDir(const System::AnsiString Dir);
extern bool __fastcall CreateDir(const System::AnsiString Dir);
extern bool __fastcall RemoveDir(const System::AnsiString Dir);
extern unsigned int __fastcall StrLen(char * Str);
extern char * __fastcall StrEnd(char * Str);
extern char * __fastcall StrMove(char * Dest, char * Source, unsigned int Count);
extern char * __fastcall StrCopy(char * Dest, char * Source);
extern char * __fastcall StrECopy(char * Dest, char * Source);
extern char * __fastcall StrLCopy(char * Dest, char * Source, unsigned int MaxLen);
extern char * __fastcall StrPCopy(char * Dest, const System::AnsiString Source);
extern char * __fastcall StrPLCopy(char * Dest, const System::AnsiString Source, unsigned int MaxLen
	);
extern char * __fastcall StrCat(char * Dest, char * Source);
extern char * __fastcall StrLCat(char * Dest, char * Source, unsigned int MaxLen);
extern int __fastcall StrComp(char * Str1, char * Str2);
extern int __fastcall StrIComp(char * Str1, char * Str2);
extern int __fastcall StrLComp(char * Str1, char * Str2, unsigned int MaxLen);
extern int __fastcall StrLIComp(char * Str1, char * Str2, unsigned int MaxLen);
extern char * __fastcall StrScan(char * Str, char Chr);
extern char * __fastcall StrRScan(char * Str, char Chr);
extern char * __fastcall StrPos(char * Str1, char * Str2);
extern char * __fastcall StrUpper(char * Str);
extern char * __fastcall StrLower(char * Str);
extern System::AnsiString __fastcall StrPas(char * Str);
extern char * __fastcall StrAlloc(unsigned int Size);
extern unsigned int __fastcall StrBufSize(char * Str);
extern char * __fastcall StrNew(char * Str);
extern void __fastcall StrDispose(char * Str);
extern unsigned int __fastcall FormatBuf(void *Buffer, unsigned int BufLen, const void *Format, unsigned int 
	FmtLen, const System::TVarRec *Args, const int Args_Size);
extern char * __fastcall StrFmt(char * Buffer, char * Format, const System::TVarRec *Args, const int 
	Args_Size);
extern char * __fastcall StrLFmt(char * Buffer, unsigned int MaxLen, char * Format, const System::TVarRec 
	*Args, const int Args_Size);
extern System::AnsiString __fastcall Format(const System::AnsiString Format, const System::TVarRec *
	Args, const int Args_Size);
extern void __fastcall FmtStr( System::AnsiString &Result, const System::AnsiString Format, const System::TVarRec 
	*Args, const int Args_Size);
extern System::AnsiString __fastcall FloatToStr(long double Value);
extern System::AnsiString __fastcall CurrToStr(System::Currency Value);
extern System::AnsiString __fastcall FloatToStrF(long double Value, TFloatFormat Format, int Precision
	, int Digits);
extern System::AnsiString __fastcall CurrToStrF(System::Currency Value, TFloatFormat Format, int Digits
	);
extern System::AnsiString __fastcall FormatFloat(const System::AnsiString Format, long double Value)
	;
extern System::AnsiString __fastcall FormatCurr(const System::AnsiString Format, System::Currency Value
	);
extern long double __fastcall StrToFloat(const System::AnsiString S);
extern System::Currency __fastcall StrToCurr(const System::AnsiString S);
extern TTimeStamp __fastcall DateTimeToTimeStamp(System::TDateTime DateTime);
extern System::TDateTime __fastcall TimeStampToDateTime(const TTimeStamp &TimeStamp);
extern TTimeStamp __fastcall MSecsToTimeStamp(System::Comp MSecs);
extern System::Comp __fastcall TimeStampToMSecs(const TTimeStamp &TimeStamp);
extern System::TDateTime __fastcall EncodeTime(unsigned short Hour, unsigned short Min, unsigned short 
	Sec, unsigned short MSec);
extern void __fastcall DecodeTime(System::TDateTime Time, unsigned short &Hour, unsigned short &Min, 
	unsigned short &Sec, unsigned short &MSec);
extern System::TDateTime __fastcall EncodeDate(unsigned short Year, unsigned short Month, unsigned short 
	Day);
extern void __fastcall DecodeDate(System::TDateTime Date, unsigned short &Year, unsigned short &Month
	, unsigned short &Day);
extern int __fastcall DayOfWeek(System::TDateTime Date);
extern System::TDateTime __fastcall Date(void);
extern System::TDateTime __fastcall Time(void);
extern System::TDateTime __fastcall Now(void);
extern void __fastcall DateTimeToString( System::AnsiString &Result, const System::AnsiString Format
	, System::TDateTime DateTime);
extern System::AnsiString __fastcall DateToStr(System::TDateTime Date);
extern System::AnsiString __fastcall TimeToStr(System::TDateTime Time);
extern System::AnsiString __fastcall DateTimeToStr(System::TDateTime DateTime);
extern System::AnsiString __fastcall FormatDateTime(const System::AnsiString Format, System::TDateTime 
	DateTime);
extern System::TDateTime __fastcall StrToDate(const System::AnsiString S);
extern System::TDateTime __fastcall StrToTime(const System::AnsiString S);
extern System::TDateTime __fastcall StrToDateTime(const System::AnsiString S);
extern System::AnsiString __fastcall SysErrorMessage(int ErrorCode);
extern System::AnsiString __fastcall GetLocaleStr(int Locale, int LocaleType, const System::AnsiString 
	Default);
extern char __fastcall GetLocaleChar(int Locale, int LocaleType, char Default);
extern void __fastcall GetFormatSettings(void);
extern System::TObject* __fastcall ExceptObject(void);
extern void * __fastcall ExceptAddr(void);
extern void __fastcall ShowException(System::TObject* ExceptObject, void * ExceptAddr);
extern void __fastcall Abort(void);
extern void __fastcall OutOfMemoryError(void);
extern TMbcsByteType __fastcall ByteType(const System::AnsiString S, int Index);
extern TMbcsByteType __fastcall StrByteType(char * Str, unsigned int Index);
extern int __fastcall ByteToCharLen(const System::AnsiString S, int MaxLen);
extern int __fastcall ByteToCharIndex(const System::AnsiString S, int Index);
extern int __fastcall CharToByteIndex(const System::AnsiString S, int Index);
extern int __fastcall CharToByteLen(const System::AnsiString S, int MaxLen);
extern bool __fastcall IsPathDelimiter(const System::AnsiString S, int Index);
extern bool __fastcall IsDelimiter(const System::AnsiString Delimiters, const System::AnsiString S, 
	int Index);
extern int __fastcall AnsiPos(const System::AnsiString Substr, const System::AnsiString S);
extern int __fastcall AnsiCompareFileName(const System::AnsiString S1, const System::AnsiString S2);
	
extern System::AnsiString __fastcall AnsiLowerCaseFileName(const System::AnsiString S);
extern System::AnsiString __fastcall AnsiUpperCaseFileName(const System::AnsiString S);
extern char * __fastcall AnsiStrPos(char * Str, char * SubStr);
extern char * __fastcall AnsiStrRScan(char * Str, char Chr);
extern char * __fastcall AnsiStrScan(char * Str, char Chr);
extern int __fastcall FloatToText(char * Buffer, const void *Value, TFloatValue ValueType, TFloatFormat 
	Format, int Precision, int Digits);
extern int __fastcall FloatToTextFmt(char * Buffer, const void *Value, TFloatValue ValueType, char * 
	Format);
extern void __fastcall FloatToDecimal(TFloatRec &Result, const void *Value, TFloatValue ValueType, int 
	Precision, int Decimals);
extern bool __fastcall TextToFloat(char * Buffer, void *Value, TFloatValue ValueType);
//-- template instantiations -------------------------------------------------
//template class Set<Byte, 0, 255>  ;

}	/* namespace Sysutils */

#pragma warn .par
#pragma warn .hid 
#pragma warn .inl

#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Sysutils;
#endif
//-- end unit ----------------------------------------------------------------
#endif	// SysUtils
