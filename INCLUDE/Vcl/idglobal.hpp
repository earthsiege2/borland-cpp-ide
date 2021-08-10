// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdGlobal.pas' rev: 6.00

#ifndef IdGlobalHPP
#define IdGlobalHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysUtils.hpp>	// Pascal unit
#include <IdException.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idglobal
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (*TStringEvent)(Classes::TComponent* ASender, const AnsiString AString);

typedef int __fastcall (*TPosProc)(const AnsiString Substr, const AnsiString S);

class DELPHICLASS TIdMimeTable;
class PASCALIMPLEMENTATION TIdMimeTable : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	Classes::TStringList* FMIMEList;
	Classes::TStringList* FFileExt;
	
public:
	virtual void __fastcall BuildCache(void);
	AnsiString __fastcall GetFileMIMEType(const AnsiString fileName);
	AnsiString __fastcall getDefaultFileExt(const AnsiString MIMEType);
	__fastcall virtual TIdMimeTable(bool Autofill);
	__fastcall virtual ~TIdMimeTable(void);
};


#pragma option push -b-
enum TCharSet { csGB2312, csBig5, csIso2022jp, csEucKR, csIso88591 };
#pragma option pop

typedef unsigned TIdPID;

class DELPHICLASS EIdFailedToRetreiveTimeZoneInfo;
class PASCALIMPLEMENTATION EIdFailedToRetreiveTimeZoneInfo : public Idexception::EIdException 
{
	typedef Idexception::EIdException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdFailedToRetreiveTimeZoneInfo(const AnsiString Msg) : Idexception::EIdException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdFailedToRetreiveTimeZoneInfo(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdFailedToRetreiveTimeZoneInfo(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdFailedToRetreiveTimeZoneInfo(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdFailedToRetreiveTimeZoneInfo(const AnsiString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFailedToRetreiveTimeZoneInfo(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdFailedToRetreiveTimeZoneInfo(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFailedToRetreiveTimeZoneInfo(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdFailedToRetreiveTimeZoneInfo(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdCorruptServicesFile;
class PASCALIMPLEMENTATION EIdCorruptServicesFile : public Idexception::EIdException 
{
	typedef Idexception::EIdException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdCorruptServicesFile(const AnsiString Msg) : Idexception::EIdException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdCorruptServicesFile(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdCorruptServicesFile(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdCorruptServicesFile(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdCorruptServicesFile(const AnsiString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdCorruptServicesFile(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdCorruptServicesFile(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdCorruptServicesFile(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdCorruptServicesFile(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint IdTimeoutDefault = 0xffffffff;
static const Shortint IdTimeoutInfinite = 0xfffffffe;
static const Shortint wsOk = 0x1;
static const Shortint wsErr = 0x0;
static const Shortint IdPORT_ECHO = 0x7;
static const Shortint IdPORT_DISCARD = 0x9;
static const Shortint IdPORT_SYSTAT = 0xb;
static const Shortint IdPORT_DAYTIME = 0xd;
static const Shortint IdPORT_NETSTAT = 0xf;
static const Shortint IdPORT_QOTD = 0x11;
static const Shortint IdPORT_CHARGEN = 0x13;
static const Shortint IdPORT_FTP = 0x15;
static const Shortint IdPORT_TELNET = 0x17;
static const Shortint IdPORT_SMTP = 0x19;
static const Shortint IdPORT_TIME = 0x25;
static const Shortint IdPORT_WHOIS = 0x2b;
static const Shortint IdPORT_DOMAIN = 0x35;
static const Shortint IdPORT_TFTP = 0x45;
static const Shortint IdPORT_GOPHER = 0x46;
static const Shortint IdPORT_FINGER = 0x4f;
static const Shortint IdPORT_HTTP = 0x50;
static const Shortint IdPORT_HOSTNAME = 0x65;
static const Shortint IdPORT_POP2 = 0x6d;
static const Shortint IdPORT_POP3 = 0x6e;
static const Shortint IdPORT_AUTH = 0x71;
static const Shortint IdPORT_NNTP = 0x77;
static const Shortint IdPORT_SNTP = 0x7b;
static const Byte IdPORT_IMAP4 = 0x8f;
static const Word IdPORT_SSL = 0x1bb;
static const Word IdPORT_LPD = 0x203;
static const Word IdPORT_DICT = 0xa44;
static const Word IdPORT_IRC = 0x1a0b;
#define gsIdProductName "Indy"
#define gsIdVersion "8.0.25"
static const char CHAR0 = '\x0';
static const char BACKSPACE = '\x8';
static const char LF = '\xa';
static const char CR = '\xd';
#define EOL "\r\n"
static const char TAB = '\x9';
static const char CHAR32 = '\x20';
static const char GPathSep = '\x5c';
extern PACKAGE TPosProc IndyPos;
extern PACKAGE bool __fastcall AnsiSameText(const AnsiString S1, const AnsiString S2);
extern PACKAGE AnsiString __fastcall IncludeTrailingBackSlash(const AnsiString APath);
extern PACKAGE void __fastcall FreeAndNil(void *Obj);
extern PACKAGE int __fastcall Max(int AValueOne, int AValueTwo);
extern PACKAGE int __fastcall Min(int AValueOne, int AValueTwo);
extern PACKAGE AnsiString __fastcall DateTimeToInternetStr(const System::TDateTime Value);
extern PACKAGE System::TDateTime __fastcall StrInternetToDateTime(AnsiString Value);
extern PACKAGE void __fastcall CommaSeperatedToStringList(Classes::TStrings* AList, const AnsiString Value);
extern PACKAGE bool __fastcall CopyFileTo(const AnsiString Source, const AnsiString Destination);
extern PACKAGE AnsiString __fastcall MakeTempFilename();
extern PACKAGE int __fastcall RPos(const AnsiString ASub, const AnsiString AIn, int AStart = 0xffffffff);
extern PACKAGE TCharSet __fastcall GetSystemLocale(void);
extern PACKAGE unsigned __fastcall FileSizeByName(AnsiString sFilename);
extern PACKAGE AnsiString __fastcall RightStr(AnsiString st, int Len);
extern PACKAGE System::TDateTime __fastcall OffsetFromUTC(void);
extern PACKAGE unsigned __fastcall StrToCard(AnsiString AVal);
extern PACKAGE double __fastcall TimeZoneBias(void);
extern PACKAGE unsigned __fastcall GetTickCount(void);
extern PACKAGE bool __fastcall SetLocalTime(System::TDateTime Value);
extern PACKAGE Classes::TList* __fastcall IdPorts(void);
extern PACKAGE AnsiString __fastcall Fetch(AnsiString &AInput, const AnsiString ADelim = " ", const bool ADelete = true);
extern PACKAGE int __fastcall PosInStrArray(AnsiString SearchStr, const AnsiString * Contents, const int Contents_Size, const bool CaseSensitive = true);
extern PACKAGE bool __fastcall IsCurrentThread(Classes::TThread* AThread);
extern PACKAGE bool __fastcall IsNumeric(char c);
extern PACKAGE Byte __fastcall StrToDay(const AnsiString ADay);
extern PACKAGE Byte __fastcall StrToMonth(const AnsiString AMonth);
extern PACKAGE AnsiString __fastcall UpCaseFirst(AnsiString S);
extern PACKAGE AnsiString __fastcall DateTimeToGmtOffSetStr(System::TDateTime ADateTime, bool SubGMT);
extern PACKAGE AnsiString __fastcall GetMIMETypeFromFile(AnsiString AFile);
extern PACKAGE void __fastcall ParseURI(AnsiString URI, AnsiString &Protocol, AnsiString &Host, AnsiString &path, AnsiString &Document, AnsiString &Port, AnsiString &Bookmark);
extern PACKAGE System::TDateTime __fastcall GmtOffsetStrToDateTime(AnsiString S);
extern PACKAGE System::TDateTime __fastcall GMTToLocalDateTime(AnsiString S);
extern PACKAGE void __fastcall Sleep(unsigned ATime);
extern PACKAGE AnsiString __fastcall IntToBin(unsigned Value);
extern PACKAGE unsigned __fastcall CurrentProcessId(void);
extern PACKAGE unsigned __fastcall ROL(unsigned val, Byte shift);
extern PACKAGE unsigned __fastcall ROR(unsigned val, Byte shift);
extern PACKAGE void __fastcall DebugOutput(const AnsiString AText);
extern PACKAGE bool __fastcall InMainThread(void);
extern PACKAGE void __fastcall SetThreadPriority(Classes::TThread* AThread, const Classes::TThreadPriority APriority);
extern PACKAGE AnsiString __fastcall URLDecode(AnsiString psSrc);
extern PACKAGE AnsiString __fastcall URLEncode(const AnsiString psSrc);

}	/* namespace Idglobal */
using namespace Idglobal;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdGlobal
