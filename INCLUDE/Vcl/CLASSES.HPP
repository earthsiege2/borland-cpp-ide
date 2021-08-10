// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Classes.pas' rev: 6.00

#ifndef ClassesHPP
#define ClassesHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TypInfo.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Classes
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TSeekOrigin { soBeginning, soCurrent, soEnd };
#pragma option pop

#pragma option push -b-
enum TAlignment { taLeftJustify, taRightJustify, taCenter };
#pragma option pop

typedef TAlignment TLeftRight;

#pragma option push -b-
enum TBiDiMode { bdLeftToRight, bdRightToLeft, bdRightToLeftNoAlign, bdRightToLeftReadingOnly };
#pragma option pop

#pragma option push -b-
enum Classes__1 { ssShift, ssAlt, ssCtrl, ssLeft, ssRight, ssMiddle, ssDouble };
#pragma option pop

typedef Set<Classes__1, ssShift, ssDouble>  TShiftState;

typedef int THelpContext;

#pragma option push -b-
enum THelpType { htKeyword, htContext };
#pragma option pop

typedef Word TShortCut;

typedef void __fastcall (__closure *TNotifyEvent)(System::TObject* Sender);

typedef void __fastcall (__closure *TGetStrProc)(const AnsiString S);

class DELPHICLASS EStreamError;
class PASCALIMPLEMENTATION EStreamError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EStreamError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EStreamError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EStreamError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EStreamError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EStreamError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EStreamError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EStreamError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EStreamError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EStreamError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EFCreateError;
class PASCALIMPLEMENTATION EFCreateError : public EStreamError 
{
	typedef EStreamError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EFCreateError(const AnsiString Msg) : EStreamError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EFCreateError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EStreamError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EFCreateError(int Ident)/* overload */ : EStreamError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EFCreateError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EStreamError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EFCreateError(const AnsiString Msg, int AHelpContext) : EStreamError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EFCreateError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EStreamError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EFCreateError(int Ident, int AHelpContext)/* overload */ : EStreamError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EFCreateError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EStreamError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EFCreateError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EFOpenError;
class PASCALIMPLEMENTATION EFOpenError : public EStreamError 
{
	typedef EStreamError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EFOpenError(const AnsiString Msg) : EStreamError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EFOpenError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EStreamError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EFOpenError(int Ident)/* overload */ : EStreamError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EFOpenError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EStreamError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EFOpenError(const AnsiString Msg, int AHelpContext) : EStreamError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EFOpenError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EStreamError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EFOpenError(int Ident, int AHelpContext)/* overload */ : EStreamError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EFOpenError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EStreamError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EFOpenError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EFilerError;
class PASCALIMPLEMENTATION EFilerError : public EStreamError 
{
	typedef EStreamError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EFilerError(const AnsiString Msg) : EStreamError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EFilerError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EStreamError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EFilerError(int Ident)/* overload */ : EStreamError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EFilerError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EStreamError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EFilerError(const AnsiString Msg, int AHelpContext) : EStreamError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EFilerError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EStreamError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EFilerError(int Ident, int AHelpContext)/* overload */ : EStreamError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EFilerError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EStreamError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EFilerError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EReadError;
class PASCALIMPLEMENTATION EReadError : public EFilerError 
{
	typedef EFilerError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EReadError(const AnsiString Msg) : EFilerError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EReadError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EFilerError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EReadError(int Ident)/* overload */ : EFilerError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EReadError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EFilerError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EReadError(const AnsiString Msg, int AHelpContext) : EFilerError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EReadError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EFilerError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EReadError(int Ident, int AHelpContext)/* overload */ : EFilerError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EReadError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EFilerError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EReadError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EWriteError;
class PASCALIMPLEMENTATION EWriteError : public EFilerError 
{
	typedef EFilerError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EWriteError(const AnsiString Msg) : EFilerError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EWriteError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EFilerError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EWriteError(int Ident)/* overload */ : EFilerError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EWriteError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EFilerError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EWriteError(const AnsiString Msg, int AHelpContext) : EFilerError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EWriteError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EFilerError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EWriteError(int Ident, int AHelpContext)/* overload */ : EFilerError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EWriteError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EFilerError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EWriteError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EClassNotFound;
class PASCALIMPLEMENTATION EClassNotFound : public EFilerError 
{
	typedef EFilerError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EClassNotFound(const AnsiString Msg) : EFilerError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EClassNotFound(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EFilerError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EClassNotFound(int Ident)/* overload */ : EFilerError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EClassNotFound(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EFilerError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EClassNotFound(const AnsiString Msg, int AHelpContext) : EFilerError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EClassNotFound(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EFilerError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EClassNotFound(int Ident, int AHelpContext)/* overload */ : EFilerError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EClassNotFound(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EFilerError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EClassNotFound(void) { }
	#pragma option pop
	
};


class DELPHICLASS EMethodNotFound;
class PASCALIMPLEMENTATION EMethodNotFound : public EFilerError 
{
	typedef EFilerError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EMethodNotFound(const AnsiString Msg) : EFilerError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EMethodNotFound(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EFilerError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EMethodNotFound(int Ident)/* overload */ : EFilerError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EMethodNotFound(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EFilerError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EMethodNotFound(const AnsiString Msg, int AHelpContext) : EFilerError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EMethodNotFound(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EFilerError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EMethodNotFound(int Ident, int AHelpContext)/* overload */ : EFilerError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EMethodNotFound(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EFilerError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EMethodNotFound(void) { }
	#pragma option pop
	
};


class DELPHICLASS EInvalidImage;
class PASCALIMPLEMENTATION EInvalidImage : public EFilerError 
{
	typedef EFilerError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EInvalidImage(const AnsiString Msg) : EFilerError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EInvalidImage(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EFilerError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EInvalidImage(int Ident)/* overload */ : EFilerError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EInvalidImage(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EFilerError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EInvalidImage(const AnsiString Msg, int AHelpContext) : EFilerError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalidImage(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EFilerError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EInvalidImage(int Ident, int AHelpContext)/* overload */ : EFilerError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidImage(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EFilerError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EInvalidImage(void) { }
	#pragma option pop
	
};


class DELPHICLASS EResNotFound;
class PASCALIMPLEMENTATION EResNotFound : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EResNotFound(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EResNotFound(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EResNotFound(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EResNotFound(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EResNotFound(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EResNotFound(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EResNotFound(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EResNotFound(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EResNotFound(void) { }
	#pragma option pop
	
};


class DELPHICLASS EListError;
class PASCALIMPLEMENTATION EListError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EListError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EListError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EListError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EListError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EListError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EListError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EListError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EListError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EListError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EBitsError;
class PASCALIMPLEMENTATION EBitsError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EBitsError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EBitsError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EBitsError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EBitsError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EBitsError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EBitsError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EBitsError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EBitsError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EBitsError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EStringListError;
class PASCALIMPLEMENTATION EStringListError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EStringListError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EStringListError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EStringListError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EStringListError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EStringListError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EStringListError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EStringListError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EStringListError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EStringListError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EComponentError;
class PASCALIMPLEMENTATION EComponentError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EComponentError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EComponentError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EComponentError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EComponentError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EComponentError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EComponentError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EComponentError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EComponentError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EComponentError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserError;
class PASCALIMPLEMENTATION EParserError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EOutOfResources;
class PASCALIMPLEMENTATION EOutOfResources : public Sysutils::EOutOfMemory 
{
	typedef Sysutils::EOutOfMemory inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EOutOfResources(const AnsiString Msg) : Sysutils::EOutOfMemory(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EOutOfResources(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::EOutOfMemory(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EOutOfResources(int Ident)/* overload */ : Sysutils::EOutOfMemory(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EOutOfResources(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::EOutOfMemory(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EOutOfResources(const AnsiString Msg, int AHelpContext) : Sysutils::EOutOfMemory(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EOutOfResources(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::EOutOfMemory(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EOutOfResources(int Ident, int AHelpContext)/* overload */ : Sysutils::EOutOfMemory(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EOutOfResources(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::EOutOfMemory(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EOutOfResources(void) { }
	#pragma option pop
	
};


class DELPHICLASS EInvalidOperation;
class PASCALIMPLEMENTATION EInvalidOperation : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EInvalidOperation(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EInvalidOperation(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EInvalidOperation(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EInvalidOperation(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EInvalidOperation(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalidOperation(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EInvalidOperation(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidOperation(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EInvalidOperation(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TDuplicates { dupIgnore, dupAccept, dupError };
#pragma option pop

typedef void *TPointerList[134217727];

typedef void * *PPointerList;

typedef int __fastcall (*TListSortCompare)(void * Item1, void * Item2);

#pragma option push -b-
enum TListNotification { lnAdded, lnExtracted, lnDeleted };
#pragma option pop

#pragma option push -b-
enum TListAssignOp { laCopy, laAnd, laOr, laXor, laSrcUnique, laDestUnique };
#pragma option pop

class DELPHICLASS TList;
class PASCALIMPLEMENTATION TList : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	void * operator[](int Index) { return Items[Index]; }
	
private:
	void * *FList;
	int FCount;
	int FCapacity;
	
protected:
	void * __fastcall Get(int Index);
	virtual void __fastcall Grow(void);
	void __fastcall Put(int Index, void * Item);
	virtual void __fastcall Notify(void * Ptr, TListNotification Action);
	void __fastcall SetCapacity(int NewCapacity);
	void __fastcall SetCount(int NewCount);
	
public:
	__fastcall virtual ~TList(void);
	int __fastcall Add(void * Item);
	virtual void __fastcall Clear(void);
	void __fastcall Delete(int Index);
	/* virtual class method */ virtual void __fastcall Error(TMetaClass* vmt, const AnsiString Msg, int Data)/* overload */;
	/*         class method */ static void __fastcall Error(TMetaClass* vmt, System::PResStringRec Msg, int Data)/* overload */;
	void __fastcall Exchange(int Index1, int Index2);
	TList* __fastcall Expand(void);
	void * __fastcall Extract(void * Item);
	void * __fastcall First(void);
	int __fastcall IndexOf(void * Item);
	void __fastcall Insert(int Index, void * Item);
	void * __fastcall Last(void);
	void __fastcall Move(int CurIndex, int NewIndex);
	int __fastcall Remove(void * Item);
	void __fastcall Pack(void);
	void __fastcall Sort(TListSortCompare Compare);
	void __fastcall Assign(TList* ListA, TListAssignOp AOperator = (TListAssignOp)(0x0), TList* ListB = (TList*)(0x0));
	__property int Capacity = {read=FCapacity, write=SetCapacity, nodefault};
	__property int Count = {read=FCount, write=SetCount, nodefault};
	__property void * Items[int Index] = {read=Get, write=Put/*, default*/};
	__property PPointerList List = {read=FList};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TList(void) : System::TObject() { }
	#pragma option pop
	
};


class DELPHICLASS TThreadList;
class PASCALIMPLEMENTATION TThreadList : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TList* FList;
	_RTL_CRITICAL_SECTION FLock;
	TDuplicates FDuplicates;
	
public:
	__fastcall TThreadList(void);
	__fastcall virtual ~TThreadList(void);
	void __fastcall Add(void * Item);
	void __fastcall Clear(void);
	TList* __fastcall LockList(void);
	void __fastcall Remove(void * Item);
	void __fastcall UnlockList(void);
	__property TDuplicates Duplicates = {read=FDuplicates, write=FDuplicates, nodefault};
};


__interface IInterfaceList;
typedef System::DelphiInterface<IInterfaceList> _di_IInterfaceList;
__interface INTERFACE_UUID("{285DEA8A-B865-11D1-AAA7-00C04FB17A72}") IInterfaceList  : public IInterface 
{
	
public:
	System::_di_IInterface operator[](int Index) { return Items[Index]; }
	
public:
	virtual System::_di_IInterface __fastcall Get(int Index) = 0 ;
	virtual int __fastcall GetCapacity(void) = 0 ;
	virtual int __fastcall GetCount(void) = 0 ;
	virtual void __fastcall Put(int Index, const System::_di_IInterface Item) = 0 ;
	virtual void __fastcall SetCapacity(int NewCapacity) = 0 ;
	virtual void __fastcall SetCount(int NewCount) = 0 ;
	virtual void __fastcall Clear(void) = 0 ;
	virtual void __fastcall Delete(int Index) = 0 ;
	virtual void __fastcall Exchange(int Index1, int Index2) = 0 ;
	virtual System::_di_IInterface __fastcall First(void) = 0 ;
	virtual int __fastcall IndexOf(const System::_di_IInterface Item) = 0 ;
	virtual int __fastcall Add(const System::_di_IInterface Item) = 0 ;
	virtual void __fastcall Insert(int Index, const System::_di_IInterface Item) = 0 ;
	virtual System::_di_IInterface __fastcall Last(void) = 0 ;
	virtual int __fastcall Remove(const System::_di_IInterface Item) = 0 ;
	virtual void __fastcall Lock(void) = 0 ;
	virtual void __fastcall Unlock(void) = 0 ;
	__property int Capacity = {read=GetCapacity, write=SetCapacity};
	__property int Count = {read=GetCount, write=SetCount};
	__property System::_di_IInterface Items[int Index] = {read=Get, write=Put/*, default*/};
};

class DELPHICLASS TInterfaceList;
class PASCALIMPLEMENTATION TInterfaceList : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
public:
	System::_di_IInterface operator[](int Index) { return Items[Index]; }
	
private:
	TThreadList* FList;
	
protected:
	System::_di_IInterface __fastcall Get(int Index);
	int __fastcall GetCapacity(void);
	int __fastcall GetCount(void);
	void __fastcall Put(int Index, const System::_di_IInterface Item);
	void __fastcall SetCapacity(int NewCapacity);
	void __fastcall SetCount(int NewCount);
	
public:
	__fastcall TInterfaceList(void);
	__fastcall virtual ~TInterfaceList(void);
	void __fastcall Clear(void);
	void __fastcall Delete(int Index);
	void __fastcall Exchange(int Index1, int Index2);
	TInterfaceList* __fastcall Expand(void);
	System::_di_IInterface __fastcall First();
	int __fastcall IndexOf(const System::_di_IInterface Item);
	int __fastcall Add(const System::_di_IInterface Item);
	void __fastcall Insert(int Index, const System::_di_IInterface Item);
	System::_di_IInterface __fastcall Last();
	int __fastcall Remove(const System::_di_IInterface Item);
	void __fastcall Lock(void);
	void __fastcall Unlock(void);
	__property int Capacity = {read=GetCapacity, write=SetCapacity, nodefault};
	__property int Count = {read=GetCount, write=SetCount, nodefault};
	__property System::_di_IInterface Items[int Index] = {read=Get, write=Put/*, default*/};
private:
	void *__IInterfaceList;	/* Classes::IInterfaceList */
	
public:
	operator IInterfaceList*(void) { return (IInterfaceList*)&__IInterfaceList; }
	
};


class DELPHICLASS TBits;
class PASCALIMPLEMENTATION TBits : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	bool operator[](int Index) { return Bits[Index]; }
	
private:
	int FSize;
	void *FBits;
	void __fastcall Error(void);
	void __fastcall SetSize(int Value);
	void __fastcall SetBit(int Index, bool Value);
	bool __fastcall GetBit(int Index);
	
public:
	__fastcall virtual ~TBits(void);
	int __fastcall OpenBit(void);
	__property bool Bits[int Index] = {read=GetBit, write=SetBit/*, default*/};
	__property int Size = {read=FSize, write=SetSize, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TBits(void) : System::TObject() { }
	#pragma option pop
	
};


class DELPHICLASS TPersistent;
class DELPHICLASS TFiler;
class PASCALIMPLEMENTATION TPersistent : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	void __fastcall AssignError(TPersistent* Source);
	
protected:
	virtual void __fastcall AssignTo(TPersistent* Dest);
	virtual void __fastcall DefineProperties(TFiler* Filer);
	DYNAMIC TPersistent* __fastcall GetOwner(void);
	
public:
	__fastcall virtual ~TPersistent(void);
	virtual void __fastcall Assign(TPersistent* Source);
	DYNAMIC AnsiString __fastcall GetNamePath();
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TPersistent(void) : System::TObject() { }
	#pragma option pop
	
};


typedef TMetaClass*TPersistentClass;

class DELPHICLASS TInterfacedPersistent;
class PASCALIMPLEMENTATION TInterfacedPersistent : public TPersistent 
{
	typedef TPersistent inherited;
	
private:
	System::_di_IInterface FOwnerInterface;
	
protected:
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	
public:
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	virtual void __fastcall AfterConstruction(void);
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TInterfacedPersistent(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TInterfacedPersistent(void) : TPersistent() { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TRecall;
class PASCALIMPLEMENTATION TRecall : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TPersistent* FStorage;
	TPersistent* FReference;
	
public:
	__fastcall TRecall(TPersistent* AStorage, TPersistent* AReference);
	__fastcall virtual ~TRecall(void);
	void __fastcall Store(void);
	void __fastcall Forget(void);
	__property TPersistent* Reference = {read=FReference};
};


class DELPHICLASS TCollectionItem;
class DELPHICLASS TCollection;
typedef TMetaClass*TCollectionItemClass;

#pragma option push -b-
enum TCollectionNotification { cnAdded, cnExtracting, cnDeleting };
#pragma option pop

class PASCALIMPLEMENTATION TCollection : public TPersistent 
{
	typedef TPersistent inherited;
	
private:
	TMetaClass*FItemClass;
	TList* FItems;
	int FUpdateCount;
	int FNextID;
	AnsiString FPropName;
	int __fastcall GetCount(void);
	AnsiString __fastcall GetPropName();
	void __fastcall InsertItem(TCollectionItem* Item);
	void __fastcall RemoveItem(TCollectionItem* Item);
	
protected:
	virtual void __fastcall Added(TCollectionItem* &Item);
	virtual void __fastcall Deleting(TCollectionItem* Item);
	__property int NextID = {read=FNextID, nodefault};
	virtual void __fastcall Notify(TCollectionItem* Item, TCollectionNotification Action);
	DYNAMIC int __fastcall GetAttrCount(void);
	DYNAMIC AnsiString __fastcall GetAttr(int Index);
	DYNAMIC AnsiString __fastcall GetItemAttr(int Index, int ItemIndex);
	void __fastcall Changed(void);
	TCollectionItem* __fastcall GetItem(int Index);
	void __fastcall SetItem(int Index, TCollectionItem* Value);
	virtual void __fastcall SetItemName(TCollectionItem* Item);
	virtual void __fastcall Update(TCollectionItem* Item);
	__property AnsiString PropName = {read=GetPropName, write=FPropName};
	__property int UpdateCount = {read=FUpdateCount, nodefault};
	
public:
	__fastcall TCollection(TMetaClass* ItemClass);
	__fastcall virtual ~TCollection(void);
	TPersistent* __fastcall Owner(void);
	TCollectionItem* __fastcall Add(void);
	virtual void __fastcall Assign(TPersistent* Source);
	virtual void __fastcall BeginUpdate(void);
	void __fastcall Clear(void);
	void __fastcall Delete(int Index);
	virtual void __fastcall EndUpdate(void);
	TCollectionItem* __fastcall FindItemID(int ID);
	DYNAMIC AnsiString __fastcall GetNamePath();
	TCollectionItem* __fastcall Insert(int Index);
	__property int Count = {read=GetCount, nodefault};
	__property TMetaClass* ItemClass = {read=FItemClass};
	__property TCollectionItem* Items[int Index] = {read=GetItem, write=SetItem};
};


class PASCALIMPLEMENTATION TCollectionItem : public TPersistent 
{
	typedef TPersistent inherited;
	
private:
	TCollection* FCollection;
	int FID;
	int __fastcall GetIndex(void);
	
protected:
	void __fastcall Changed(bool AllItems);
	DYNAMIC TPersistent* __fastcall GetOwner(void);
	virtual AnsiString __fastcall GetDisplayName();
	virtual void __fastcall SetCollection(TCollection* Value);
	virtual void __fastcall SetIndex(int Value);
	virtual void __fastcall SetDisplayName(const AnsiString Value);
	
public:
	__fastcall virtual TCollectionItem(TCollection* Collection);
	__fastcall virtual ~TCollectionItem(void);
	DYNAMIC AnsiString __fastcall GetNamePath();
	__property TCollection* Collection = {read=FCollection, write=SetCollection};
	__property int ID = {read=FID, nodefault};
	__property int Index = {read=GetIndex, write=SetIndex, nodefault};
	__property AnsiString DisplayName = {read=GetDisplayName, write=SetDisplayName};
};


class DELPHICLASS TOwnedCollection;
class PASCALIMPLEMENTATION TOwnedCollection : public TCollection 
{
	typedef TCollection inherited;
	
private:
	TPersistent* FOwner;
	
protected:
	DYNAMIC TPersistent* __fastcall GetOwner(void);
	
public:
	__fastcall TOwnedCollection(TPersistent* AOwner, TMetaClass* ItemClass);
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TOwnedCollection(void) { }
	#pragma option pop
	
};


class DELPHICLASS TStrings;
typedef void __fastcall (__closure *TGetModuleProc)(const AnsiString FileName, const AnsiString UnitName, const AnsiString FormName, const AnsiString DesignClass, TStrings* CoClasses);

__interface IStringsAdapter;
typedef System::DelphiInterface<IStringsAdapter> _di_IStringsAdapter;
__interface INTERFACE_UUID("{739C2F34-52EC-11D0-9EA6-0020AF3D82DA}") IStringsAdapter  : public IInterface 
{
	
public:
	virtual void __fastcall ReferenceStrings(TStrings* S) = 0 ;
	virtual void __fastcall ReleaseStrings(void) = 0 ;
};

#pragma option push -b-
enum Classes__92 { sdDelimiter, sdQuoteChar };
#pragma option pop

typedef Set<Classes__92, sdDelimiter, sdQuoteChar>  TStringsDefined;

class DELPHICLASS TReader;
class DELPHICLASS TWriter;
class DELPHICLASS TStream;
class PASCALIMPLEMENTATION TStrings : public TPersistent 
{
	typedef TPersistent inherited;
	
public:
	AnsiString operator[](int Index) { return Strings[Index]; }
	
private:
	TStringsDefined FDefined;
	char FDelimiter;
	char FQuoteChar;
	int FUpdateCount;
	_di_IStringsAdapter FAdapter;
	AnsiString __fastcall GetCommaText();
	AnsiString __fastcall GetDelimitedText();
	AnsiString __fastcall GetName(int Index);
	AnsiString __fastcall GetValue(const AnsiString Name);
	void __fastcall ReadData(TReader* Reader);
	void __fastcall SetCommaText(const AnsiString Value);
	void __fastcall SetDelimitedText(const AnsiString Value);
	void __fastcall SetStringsAdapter(const _di_IStringsAdapter Value);
	void __fastcall SetValue(const AnsiString Name, const AnsiString Value);
	void __fastcall WriteData(TWriter* Writer);
	char __fastcall GetDelimiter(void);
	void __fastcall SetDelimiter(const char Value);
	char __fastcall GetQuoteChar(void);
	void __fastcall SetQuoteChar(const char Value);
	
protected:
	virtual void __fastcall DefineProperties(TFiler* Filer);
	void __fastcall Error(const AnsiString Msg, int Data)/* overload */;
	void __fastcall Error(System::PResStringRec Msg, int Data)/* overload */;
	AnsiString __fastcall ExtractName(const AnsiString S);
	virtual AnsiString __fastcall Get(int Index) = 0 ;
	virtual int __fastcall GetCapacity(void);
	virtual int __fastcall GetCount(void) = 0 ;
	virtual System::TObject* __fastcall GetObject(int Index);
	virtual AnsiString __fastcall GetTextStr();
	virtual void __fastcall Put(int Index, const AnsiString S);
	virtual void __fastcall PutObject(int Index, System::TObject* AObject);
	virtual void __fastcall SetCapacity(int NewCapacity);
	virtual void __fastcall SetTextStr(const AnsiString Value);
	virtual void __fastcall SetUpdateState(bool Updating);
	__property int UpdateCount = {read=FUpdateCount, nodefault};
	virtual int __fastcall CompareStrings(const AnsiString S1, const AnsiString S2);
	
public:
	__fastcall virtual ~TStrings(void);
	virtual int __fastcall Add(const AnsiString S);
	virtual int __fastcall AddObject(const AnsiString S, System::TObject* AObject);
	void __fastcall Append(const AnsiString S);
	virtual void __fastcall AddStrings(TStrings* Strings);
	virtual void __fastcall Assign(TPersistent* Source);
	void __fastcall BeginUpdate(void);
	virtual void __fastcall Clear(void) = 0 ;
	virtual void __fastcall Delete(int Index) = 0 ;
	void __fastcall EndUpdate(void);
	bool __fastcall Equals(TStrings* Strings);
	virtual void __fastcall Exchange(int Index1, int Index2);
	virtual char * __fastcall GetText(void);
	virtual int __fastcall IndexOf(const AnsiString S);
	virtual int __fastcall IndexOfName(const AnsiString Name);
	virtual int __fastcall IndexOfObject(System::TObject* AObject);
	virtual void __fastcall Insert(int Index, const AnsiString S) = 0 ;
	virtual void __fastcall InsertObject(int Index, const AnsiString S, System::TObject* AObject);
	virtual void __fastcall LoadFromFile(const AnsiString FileName);
	virtual void __fastcall LoadFromStream(TStream* Stream);
	virtual void __fastcall Move(int CurIndex, int NewIndex);
	virtual void __fastcall SaveToFile(const AnsiString FileName);
	virtual void __fastcall SaveToStream(TStream* Stream);
	virtual void __fastcall SetText(char * Text);
	__property int Capacity = {read=GetCapacity, write=SetCapacity, nodefault};
	__property AnsiString CommaText = {read=GetCommaText, write=SetCommaText};
	__property int Count = {read=GetCount, nodefault};
	__property char Delimiter = {read=GetDelimiter, write=SetDelimiter, nodefault};
	__property AnsiString DelimitedText = {read=GetDelimitedText, write=SetDelimitedText};
	__property AnsiString Names[int Index] = {read=GetName};
	__property System::TObject* Objects[int Index] = {read=GetObject, write=PutObject};
	__property char QuoteChar = {read=GetQuoteChar, write=SetQuoteChar, nodefault};
	__property AnsiString Values[AnsiString Name] = {read=GetValue, write=SetValue};
	__property AnsiString Strings[int Index] = {read=Get, write=Put/*, default*/};
	__property AnsiString Text = {read=GetTextStr, write=SetTextStr};
	__property _di_IStringsAdapter StringsAdapter = {read=FAdapter, write=SetStringsAdapter};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TStrings(void) : TPersistent() { }
	#pragma option pop
	
};


struct TStringItem;
typedef TStringItem *PStringItem;

#pragma pack(push, 4)
struct TStringItem
{
	AnsiString FString;
	System::TObject* FObject;
} ;
#pragma pack(pop)

typedef TStringItem TStringItemList[134217728];

typedef TStringItem *PStringItemList;

class DELPHICLASS TStringList;
typedef int __fastcall (*TStringListSortCompare)(TStringList* List, int Index1, int Index2);

class PASCALIMPLEMENTATION TStringList : public TStrings 
{
	typedef TStrings inherited;
	
private:
	TStringItem *FList;
	int FCount;
	int FCapacity;
	bool FSorted;
	TDuplicates FDuplicates;
	bool FCaseSensitive;
	TNotifyEvent FOnChange;
	TNotifyEvent FOnChanging;
	void __fastcall ExchangeItems(int Index1, int Index2);
	void __fastcall Grow(void);
	void __fastcall QuickSort(int L, int R, TStringListSortCompare SCompare);
	void __fastcall SetSorted(bool Value);
	void __fastcall SetCaseSensitive(const bool Value);
	
protected:
	virtual void __fastcall Changed(void);
	virtual void __fastcall Changing(void);
	virtual AnsiString __fastcall Get(int Index);
	virtual int __fastcall GetCapacity(void);
	virtual int __fastcall GetCount(void);
	virtual System::TObject* __fastcall GetObject(int Index);
	virtual void __fastcall Put(int Index, const AnsiString S);
	virtual void __fastcall PutObject(int Index, System::TObject* AObject);
	virtual void __fastcall SetCapacity(int NewCapacity);
	virtual void __fastcall SetUpdateState(bool Updating);
	virtual int __fastcall CompareStrings(const AnsiString S1, const AnsiString S2);
	virtual void __fastcall InsertItem(int Index, const AnsiString S, System::TObject* AObject);
	
public:
	__fastcall virtual ~TStringList(void);
	virtual int __fastcall Add(const AnsiString S);
	virtual int __fastcall AddObject(const AnsiString S, System::TObject* AObject);
	virtual void __fastcall Clear(void);
	virtual void __fastcall Delete(int Index);
	virtual void __fastcall Exchange(int Index1, int Index2);
	virtual bool __fastcall Find(const AnsiString S, int &Index);
	virtual int __fastcall IndexOf(const AnsiString S);
	virtual void __fastcall Insert(int Index, const AnsiString S);
	virtual void __fastcall InsertObject(int Index, const AnsiString S, System::TObject* AObject);
	virtual void __fastcall Sort(void);
	virtual void __fastcall CustomSort(TStringListSortCompare Compare);
	__property TDuplicates Duplicates = {read=FDuplicates, write=FDuplicates, nodefault};
	__property bool Sorted = {read=FSorted, write=SetSorted, nodefault};
	__property bool CaseSensitive = {read=FCaseSensitive, write=SetCaseSensitive, nodefault};
	__property TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property TNotifyEvent OnChanging = {read=FOnChanging, write=FOnChanging};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TStringList(void) : TStrings() { }
	#pragma option pop
	
};


class DELPHICLASS TComponent;
class PASCALIMPLEMENTATION TStream : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	__int64 __fastcall GetPosition(void);
	void __fastcall SetPosition(const __int64 Pos);
	__int64 __fastcall GetSize(void);
	void __fastcall SetSize64(const __int64 NewSize);
	
protected:
	virtual void __fastcall SetSize(int NewSize)/* overload */;
	virtual void __fastcall SetSize(const __int64 NewSize)/* overload */;
	
public:
	virtual int __fastcall Read(void *Buffer, int Count) = 0 ;
	virtual int __fastcall Write(const void *Buffer, int Count) = 0 ;
	virtual int __fastcall Seek(int Offset, Word Origin)/* overload */;
	virtual __int64 __fastcall Seek(const __int64 Offset, TSeekOrigin Origin)/* overload */;
	void __fastcall ReadBuffer(void *Buffer, int Count);
	void __fastcall WriteBuffer(const void *Buffer, int Count);
	__int64 __fastcall CopyFrom(TStream* Source, __int64 Count);
	TComponent* __fastcall ReadComponent(TComponent* Instance);
	TComponent* __fastcall ReadComponentRes(TComponent* Instance);
	void __fastcall WriteComponent(TComponent* Instance);
	void __fastcall WriteComponentRes(const AnsiString ResName, TComponent* Instance);
	virtual void __fastcall WriteDescendent(TComponent* Instance, TComponent* Ancestor);
	void __fastcall WriteDescendentRes(const AnsiString ResName, TComponent* Instance, TComponent* Ancestor);
	void __fastcall WriteResourceHeader(const AnsiString ResName, /* out */ int &FixupInfo);
	void __fastcall FixupResourceHeader(int FixupInfo);
	void __fastcall ReadResHeader(void);
	__property __int64 Position = {read=GetPosition, write=SetPosition};
	__property __int64 Size = {read=GetSize, write=SetSize64};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TStream(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TStream(void) { }
	#pragma option pop
	
};


__interface IStreamPersist;
typedef System::DelphiInterface<IStreamPersist> _di_IStreamPersist;
__interface INTERFACE_UUID("{B8CD12A3-267A-11D4-83DA-00C04F60B2DD}") IStreamPersist  : public IInterface 
{
	
public:
	virtual void __fastcall LoadFromStream(TStream* Stream) = 0 ;
	virtual void __fastcall SaveToStream(TStream* Stream) = 0 ;
};

class DELPHICLASS THandleStream;
class PASCALIMPLEMENTATION THandleStream : public TStream 
{
	typedef TStream inherited;
	
protected:
	int FHandle;
	virtual void __fastcall SetSize(int NewSize)/* overload */;
	virtual void __fastcall SetSize(const __int64 NewSize)/* overload */;
	
public:
	__fastcall THandleStream(int AHandle);
	virtual int __fastcall Read(void *Buffer, int Count);
	virtual int __fastcall Write(const void *Buffer, int Count);
	virtual __int64 __fastcall Seek(const __int64 Offset, TSeekOrigin Origin)/* overload */;
	__property int Handle = {read=FHandle, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~THandleStream(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Seek(int Offset, Word Origin){ return TStream::Seek(Offset, Origin); }
	
};


class DELPHICLASS TFileStream;
class PASCALIMPLEMENTATION TFileStream : public THandleStream 
{
	typedef THandleStream inherited;
	
public:
	__fastcall TFileStream(const AnsiString FileName, Word Mode)/* overload */;
	__fastcall TFileStream(const AnsiString FileName, Word Mode, unsigned Rights)/* overload */;
	__fastcall virtual ~TFileStream(void);
};


class DELPHICLASS TCustomMemoryStream;
class PASCALIMPLEMENTATION TCustomMemoryStream : public TStream 
{
	typedef TStream inherited;
	
private:
	void *FMemory;
	int FSize;
	int FPosition;
	
protected:
	void __fastcall SetPointer(void * Ptr, int Size);
	
public:
	virtual int __fastcall Read(void *Buffer, int Count);
	virtual int __fastcall Seek(int Offset, Word Origin)/* overload */;
	void __fastcall SaveToStream(TStream* Stream);
	void __fastcall SaveToFile(const AnsiString FileName);
	__property void * Memory = {read=FMemory};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TCustomMemoryStream(void) : TStream() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TCustomMemoryStream(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
public:
	inline __int64 __fastcall  Seek(const __int64 Offset, TSeekOrigin Origin){ return TStream::Seek(Offset, Origin); }
	
};


class DELPHICLASS TMemoryStream;
class PASCALIMPLEMENTATION TMemoryStream : public TCustomMemoryStream 
{
	typedef TCustomMemoryStream inherited;
	
private:
	int FCapacity;
	void __fastcall SetCapacity(int NewCapacity);
	
protected:
	virtual void * __fastcall Realloc(int &NewCapacity);
	__property int Capacity = {read=FCapacity, write=SetCapacity, nodefault};
	
public:
	__fastcall virtual ~TMemoryStream(void);
	void __fastcall Clear(void);
	void __fastcall LoadFromStream(TStream* Stream);
	void __fastcall LoadFromFile(const AnsiString FileName);
	virtual void __fastcall SetSize(int NewSize)/* overload */;
	virtual int __fastcall Write(const void *Buffer, int Count);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TMemoryStream(void) : TCustomMemoryStream() { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  SetSize(const __int64 NewSize){ TStream::SetSize(NewSize); }
	
};


class DELPHICLASS TStringStream;
class PASCALIMPLEMENTATION TStringStream : public TStream 
{
	typedef TStream inherited;
	
private:
	AnsiString FDataString;
	int FPosition;
	
protected:
	virtual void __fastcall SetSize(int NewSize)/* overload */;
	
public:
	__fastcall TStringStream(const AnsiString AString);
	virtual int __fastcall Read(void *Buffer, int Count);
	AnsiString __fastcall ReadString(int Count);
	virtual int __fastcall Seek(int Offset, Word Origin)/* overload */;
	virtual int __fastcall Write(const void *Buffer, int Count);
	void __fastcall WriteString(const AnsiString AString);
	__property AnsiString DataString = {read=FDataString};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TStringStream(void) { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  SetSize(const __int64 NewSize){ TStream::SetSize(NewSize); }
	
public:
	inline __int64 __fastcall  Seek(const __int64 Offset, TSeekOrigin Origin){ return TStream::Seek(Offset, Origin); }
	
};


class DELPHICLASS TResourceStream;
class PASCALIMPLEMENTATION TResourceStream : public TCustomMemoryStream 
{
	typedef TCustomMemoryStream inherited;
	
private:
	unsigned HResInfo;
	unsigned HGlobal;
	void __fastcall Initialize(unsigned Instance, char * Name, char * ResType);
	
public:
	__fastcall TResourceStream(unsigned Instance, const AnsiString ResName, char * ResType);
	__fastcall TResourceStream(unsigned Instance, int ResID, char * ResType);
	__fastcall virtual ~TResourceStream(void);
	virtual int __fastcall Write(const void *Buffer, int Count);
};


#pragma option push -b-
enum TStreamOwnership { soReference, soOwned };
#pragma option pop

class DELPHICLASS TStreamAdapter;
class PASCALIMPLEMENTATION TStreamAdapter : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	TStream* FStream;
	TStreamOwnership FOwnership;
	
public:
	__fastcall TStreamAdapter(TStream* Stream, TStreamOwnership Ownership);
	__fastcall virtual ~TStreamAdapter(void);
	virtual HRESULT __stdcall Read(void * pv, int cb, PLongint pcbRead);
	virtual HRESULT __stdcall Write(void * pv, int cb, PLongint pcbWritten);
	virtual HRESULT __stdcall Seek(__int64 dlibMove, int dwOrigin, /* out */ __int64 &libNewPosition);
	virtual HRESULT __stdcall SetSize(__int64 libNewSize);
	virtual HRESULT __stdcall CopyTo(_di_IStream stm, __int64 cb, /* out */ __int64 &cbRead, /* out */ __int64 &cbWritten);
	virtual HRESULT __stdcall Commit(int grfCommitFlags);
	virtual HRESULT __stdcall Revert(void);
	virtual HRESULT __stdcall LockRegion(__int64 libOffset, __int64 cb, int dwLockType);
	virtual HRESULT __stdcall UnlockRegion(__int64 libOffset, __int64 cb, int dwLockType);
	virtual HRESULT __stdcall Stat(/* out */ tagSTATSTG &statstg, int grfStatFlag);
	virtual HRESULT __stdcall Clone(/* out */ _di_IStream &stm);
	__property TStream* Stream = {read=FStream};
	__property TStreamOwnership StreamOwnership = {read=FOwnership, write=FOwnership, nodefault};
private:
	void *__IStream;	/* IStream */
	
public:
	operator IStream*(void) { return (IStream*)&__IStream; }
	
};


typedef void __fastcall (__closure *TGetClass)(TMetaClass* AClass);

class DELPHICLASS TClassFinder;
class PASCALIMPLEMENTATION TClassFinder : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TList* FGroups;
	
public:
	__fastcall TClassFinder(TMetaClass* AClass, bool AIncludeActiveGroups);
	__fastcall virtual ~TClassFinder(void);
	TMetaClass* __fastcall GetClass(const AnsiString AClassName);
	void __fastcall GetClasses(TGetClass Proc);
};


#pragma option push -b-
enum TValueType { vaNull, vaList, vaInt8, vaInt16, vaInt32, vaExtended, vaString, vaIdent, vaFalse, vaTrue, vaBinary, vaSet, vaLString, vaNil, vaCollection, vaSingle, vaCurrency, vaDate, vaWString, vaInt64, vaUTF8String };
#pragma option pop

#pragma option push -b-
enum TFilerFlag { ffInherited, ffChildPos, ffInline };
#pragma option pop

typedef Set<TFilerFlag, ffInherited, ffInline>  TFilerFlags;

typedef void __fastcall (__closure *TReaderProc)(TReader* Reader);

typedef void __fastcall (__closure *TWriterProc)(TWriter* Writer);

typedef void __fastcall (__closure *TStreamProc)(TStream* Stream);

__interface IInterfaceComponentReference;
typedef System::DelphiInterface<IInterfaceComponentReference> _di_IInterfaceComponentReference;
__interface INTERFACE_UUID("{E28B1858-EC86-4559-8FCD-6B4F824151ED}") IInterfaceComponentReference  : public IInterface 
{
	
public:
	virtual TComponent* __fastcall GetComponent(void) = 0 ;
};

class PASCALIMPLEMENTATION TFiler : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TStream* FStream;
	void *FBuffer;
	int FBufSize;
	int FBufPos;
	int FBufEnd;
	TComponent* FRoot;
	TComponent* FLookupRoot;
	TPersistent* FAncestor;
	bool FIgnoreChildren;
	
protected:
	virtual void __fastcall SetRoot(TComponent* Value);
	
public:
	__fastcall TFiler(TStream* Stream, int BufSize);
	__fastcall virtual ~TFiler(void);
	virtual void __fastcall DefineProperty(const AnsiString Name, TReaderProc ReadData, TWriterProc WriteData, bool HasData) = 0 ;
	virtual void __fastcall DefineBinaryProperty(const AnsiString Name, TStreamProc ReadData, TStreamProc WriteData, bool HasData) = 0 ;
	virtual void __fastcall FlushBuffer(void) = 0 ;
	__property TComponent* Root = {read=FRoot, write=SetRoot};
	__property TComponent* LookupRoot = {read=FLookupRoot};
	__property TPersistent* Ancestor = {read=FAncestor, write=FAncestor};
	__property bool IgnoreChildren = {read=FIgnoreChildren, write=FIgnoreChildren, nodefault};
};


typedef TMetaClass*TComponentClass;

__interface IVarStreamable;
typedef System::DelphiInterface<IVarStreamable> _di_IVarStreamable;
__interface INTERFACE_UUID("{D60BA026-5E42-4C2A-BB01-3F1C8F30A28E}") IVarStreamable  : public IInterface 
{
	
public:
	virtual void __fastcall StreamIn(TVarData &Dest, const TStream* Stream) = 0 ;
	virtual void __fastcall StreamOut(const TVarData &Source, const TStream* Stream) = 0 ;
};

typedef void __fastcall (__closure *TFindMethodEvent)(TReader* Reader, const AnsiString MethodName, void * &Address, bool &Error);

typedef void __fastcall (__closure *TSetNameEvent)(TReader* Reader, TComponent* Component, AnsiString &Name);

typedef void __fastcall (__closure *TReferenceNameEvent)(TReader* Reader, AnsiString &Name);

typedef void __fastcall (__closure *TAncestorNotFoundEvent)(TReader* Reader, const AnsiString ComponentName, TMetaClass* ComponentClass, TComponent* &Component);

typedef void __fastcall (__closure *TReadComponentsProc)(TComponent* Component);

typedef void __fastcall (__closure *TReaderError)(TReader* Reader, const AnsiString Message, bool &Handled);

typedef void __fastcall (__closure *TFindComponentClassEvent)(TReader* Reader, const AnsiString ClassName, TMetaClass* &ComponentClass);

typedef void __fastcall (__closure *TCreateComponentEvent)(TReader* Reader, TMetaClass* ComponentClass, TComponent* &Component);

class PASCALIMPLEMENTATION TReader : public TFiler 
{
	typedef TFiler inherited;
	
private:
	TComponent* FOwner;
	TComponent* FParent;
	TList* FFixups;
	TList* FLoaded;
	TFindMethodEvent FOnFindMethod;
	TSetNameEvent FOnSetName;
	TReferenceNameEvent FOnReferenceName;
	TAncestorNotFoundEvent FOnAncestorNotFound;
	TReaderError FOnError;
	TFindComponentClassEvent FOnFindComponentClass;
	TCreateComponentEvent FOnCreateComponent;
	AnsiString FPropName;
	TClassFinder* FFinder;
	bool FCanHandleExcepts;
	void __fastcall DoFixupReferences(void);
	void __fastcall FreeFixups(void);
	TMetaClass* __fastcall GetFieldClass(System::TObject* Instance, const AnsiString ClassName);
	int __fastcall GetPosition(void);
	void __fastcall ReadBuffer(void);
	void __fastcall ReadDataInner(TComponent* Instance);
	TMetaClass* __fastcall FindComponentClass(const AnsiString ClassName);
	
protected:
	virtual bool __fastcall Error(const AnsiString Message);
	virtual TComponent* __fastcall FindAncestorComponent(const AnsiString Name, TMetaClass* ComponentClass);
	virtual void * __fastcall FindMethod(TComponent* Root, const AnsiString MethodName);
	virtual void __fastcall SetName(TComponent* Component, AnsiString &Name);
	void __fastcall ReadProperty(TPersistent* AInstance);
	void __fastcall ReadPropValue(TPersistent* Instance, void * PropInfo);
	virtual void __fastcall ReferenceName(AnsiString &Name);
	void __fastcall PropertyError(const AnsiString Name);
	void __fastcall ReadData(TComponent* Instance);
	int __fastcall ReadSet(void * SetType);
	void __fastcall SetPosition(int Value);
	void __fastcall SkipBytes(int Count);
	void __fastcall SkipSetBody(void);
	void __fastcall SkipProperty(void);
	void __fastcall SkipComponent(bool SkipHeader);
	__property AnsiString PropName = {read=FPropName};
	__property bool CanHandleExceptions = {read=FCanHandleExcepts, nodefault};
	
public:
	__fastcall virtual ~TReader(void);
	void __fastcall BeginReferences(void);
	void __fastcall CheckValue(TValueType Value);
	virtual void __fastcall DefineProperty(const AnsiString Name, TReaderProc ReadData, TWriterProc WriteData, bool HasData);
	virtual void __fastcall DefineBinaryProperty(const AnsiString Name, TStreamProc ReadData, TStreamProc WriteData, bool HasData);
	bool __fastcall EndOfList(void);
	void __fastcall EndReferences(void);
	void __fastcall FixupReferences(void);
	virtual void __fastcall FlushBuffer(void);
	TValueType __fastcall NextValue(void);
	void __fastcall Read(void *Buf, int Count);
	bool __fastcall ReadBoolean(void);
	char __fastcall ReadChar(void);
	void __fastcall ReadCollection(TCollection* Collection);
	TComponent* __fastcall ReadComponent(TComponent* Component);
	void __fastcall ReadComponents(TComponent* AOwner, TComponent* AParent, TReadComponentsProc Proc);
	Extended __fastcall ReadFloat(void);
	float __fastcall ReadSingle(void);
	System::Currency __fastcall ReadCurrency(void);
	System::TDateTime __fastcall ReadDate(void);
	AnsiString __fastcall ReadIdent();
	int __fastcall ReadInteger(void);
	__int64 __fastcall ReadInt64(void);
	void __fastcall ReadListBegin(void);
	void __fastcall ReadListEnd(void);
	virtual void __fastcall ReadPrefix(TFilerFlags &Flags, int &AChildPos);
	TComponent* __fastcall ReadRootComponent(TComponent* Root);
	void __fastcall ReadSignature(void);
	AnsiString __fastcall ReadStr();
	AnsiString __fastcall ReadString();
	WideString __fastcall ReadWideString();
	TValueType __fastcall ReadValue(void);
	Variant __fastcall ReadVariant();
	void __fastcall CopyValue(TWriter* Writer);
	void __fastcall SkipValue(void);
	__property TComponent* Owner = {read=FOwner, write=FOwner};
	__property TComponent* Parent = {read=FParent, write=FParent};
	__property int Position = {read=GetPosition, write=SetPosition, nodefault};
	__property TReaderError OnError = {read=FOnError, write=FOnError};
	__property TFindMethodEvent OnFindMethod = {read=FOnFindMethod, write=FOnFindMethod};
	__property TSetNameEvent OnSetName = {read=FOnSetName, write=FOnSetName};
	__property TReferenceNameEvent OnReferenceName = {read=FOnReferenceName, write=FOnReferenceName};
	__property TAncestorNotFoundEvent OnAncestorNotFound = {read=FOnAncestorNotFound, write=FOnAncestorNotFound};
	__property TCreateComponentEvent OnCreateComponent = {read=FOnCreateComponent, write=FOnCreateComponent};
	__property TFindComponentClassEvent OnFindComponentClass = {read=FOnFindComponentClass, write=FOnFindComponentClass};
public:
	#pragma option push -w-inl
	/* TFiler.Create */ inline __fastcall TReader(TStream* Stream, int BufSize) : TFiler(Stream, BufSize) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TFindAncestorEvent)(TWriter* Writer, TComponent* Component, const AnsiString Name, TComponent* &Ancestor, TComponent* &RootAncestor);

class PASCALIMPLEMENTATION TWriter : public TFiler 
{
	typedef TFiler inherited;
	
private:
	TComponent* FRootAncestor;
	AnsiString FPropPath;
	TList* FAncestorList;
	int FAncestorPos;
	int FChildPos;
	TFindAncestorEvent FOnFindAncestor;
	bool FUseQualifiedNames;
	void __fastcall AddAncestor(TComponent* Component);
	int __fastcall GetPosition(void);
	void __fastcall SetPosition(int Value);
	void __fastcall WriteBuffer(void);
	virtual void __fastcall WriteData(TComponent* Instance);
	void __fastcall WriteMinStr(const AnsiString LocaleStr, const AnsiString UTF8Str);
	
protected:
	virtual void __fastcall SetRoot(TComponent* Value);
	void __fastcall WriteBinary(TStreamProc WriteData);
	void __fastcall WritePrefix(TFilerFlags Flags, int AChildPos);
	void __fastcall WriteProperty(TPersistent* Instance, Typinfo::PPropInfo PropInfo);
	void __fastcall WriteProperties(TPersistent* Instance);
	void __fastcall WritePropName(const AnsiString PropName);
	void __fastcall WriteValue(TValueType Value);
	
public:
	__fastcall virtual ~TWriter(void);
	virtual void __fastcall DefineProperty(const AnsiString Name, TReaderProc ReadData, TWriterProc WriteData, bool HasData);
	virtual void __fastcall DefineBinaryProperty(const AnsiString Name, TStreamProc ReadData, TStreamProc WriteData, bool HasData);
	virtual void __fastcall FlushBuffer(void);
	void __fastcall Write(const void *Buf, int Count);
	void __fastcall WriteBoolean(bool Value);
	void __fastcall WriteCollection(TCollection* Value);
	void __fastcall WriteComponent(TComponent* Component);
	void __fastcall WriteChar(char Value);
	void __fastcall WriteDescendent(TComponent* Root, TComponent* AAncestor);
	void __fastcall WriteFloat(const Extended Value);
	void __fastcall WriteSingle(const float Value);
	void __fastcall WriteCurrency(const System::Currency Value);
	void __fastcall WriteDate(const System::TDateTime Value);
	void __fastcall WriteIdent(const AnsiString Ident);
	void __fastcall WriteInteger(int Value)/* overload */;
	void __fastcall WriteInteger(__int64 Value)/* overload */;
	void __fastcall WriteListBegin(void);
	void __fastcall WriteListEnd(void);
	void __fastcall WriteRootComponent(TComponent* Root);
	void __fastcall WriteSignature(void);
	void __fastcall WriteStr(const AnsiString Value);
	void __fastcall WriteString(const AnsiString Value);
	void __fastcall WriteWideString(const WideString Value);
	void __fastcall WriteVariant(const Variant &Value);
	__property int Position = {read=GetPosition, write=SetPosition, nodefault};
	__property TComponent* RootAncestor = {read=FRootAncestor, write=FRootAncestor};
	__property TFindAncestorEvent OnFindAncestor = {read=FOnFindAncestor, write=FOnFindAncestor};
	__property bool UseQualifiedNames = {read=FUseQualifiedNames, write=FUseQualifiedNames, nodefault};
public:
	#pragma option push -w-inl
	/* TFiler.Create */ inline __fastcall TWriter(TStream* Stream, int BufSize) : TFiler(Stream, BufSize) { }
	#pragma option pop
	
};


class DELPHICLASS TParser;
class PASCALIMPLEMENTATION TParser : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TStream* FStream;
	int FOrigin;
	char *FBuffer;
	char *FBufPtr;
	char *FBufEnd;
	char *FSourcePtr;
	char *FSourceEnd;
	char *FTokenPtr;
	char *FStringPtr;
	int FSourceLine;
	char FSaveChar;
	char FToken;
	char FFloatType;
	WideString FWideStr;
	void __fastcall ReadBuffer(void);
	void __fastcall SkipBlanks(void);
	
public:
	__fastcall TParser(TStream* Stream);
	__fastcall virtual ~TParser(void);
	void __fastcall CheckToken(char T);
	void __fastcall CheckTokenSymbol(const AnsiString S);
	void __fastcall Error(const AnsiString Ident);
	void __fastcall ErrorFmt(const AnsiString Ident, const System::TVarRec * Args, const int Args_Size);
	void __fastcall ErrorStr(const AnsiString Message);
	void __fastcall HexToBinary(TStream* Stream);
	char __fastcall NextToken(void);
	int __fastcall SourcePos(void);
	AnsiString __fastcall TokenComponentIdent();
	Extended __fastcall TokenFloat(void);
	__int64 __fastcall TokenInt(void);
	AnsiString __fastcall TokenString();
	WideString __fastcall TokenWideString();
	bool __fastcall TokenSymbolIs(const AnsiString S);
	__property char FloatType = {read=FFloatType, nodefault};
	__property int SourceLine = {read=FSourceLine, nodefault};
	__property char Token = {read=FToken, nodefault};
};


class DELPHICLASS EThread;
class PASCALIMPLEMENTATION EThread : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EThread(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EThread(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EThread(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EThread(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EThread(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EThread(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EThread(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EThread(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EThread(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TThreadMethod)(void);

#pragma option push -b-
enum TThreadPriority { tpIdle, tpLowest, tpLower, tpNormal, tpHigher, tpHighest, tpTimeCritical };
#pragma option pop

class DELPHICLASS TThread;
class PASCALIMPLEMENTATION TThread : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	unsigned FHandle;
	unsigned FThreadID;
	bool FCreateSuspended;
	bool FTerminated;
	bool FSuspended;
	bool FFreeOnTerminate;
	bool FFinished;
	int FReturnValue;
	TNotifyEvent FOnTerminate;
	TThreadMethod FMethod;
	System::TObject* FSynchronizeException;
	System::TObject* FFatalException;
	void __fastcall CheckThreadError(int ErrCode)/* overload */;
	void __fastcall CheckThreadError(bool Success)/* overload */;
	void __fastcall CallOnTerminate(void);
	TThreadPriority __fastcall GetPriority(void);
	void __fastcall SetPriority(TThreadPriority Value);
	void __fastcall SetSuspended(bool Value);
	
protected:
	virtual void __fastcall DoTerminate(void);
	virtual void __fastcall Execute(void) = 0 ;
	void __fastcall Synchronize(TThreadMethod Method);
	__property int ReturnValue = {read=FReturnValue, write=FReturnValue, nodefault};
	__property bool Terminated = {read=FTerminated, nodefault};
	
public:
	__fastcall TThread(bool CreateSuspended);
	__fastcall virtual ~TThread(void);
	virtual void __fastcall AfterConstruction(void);
	void __fastcall Resume(void);
	void __fastcall Suspend(void);
	void __fastcall Terminate(void);
	unsigned __fastcall WaitFor(void);
	__property System::TObject* FatalException = {read=FFatalException};
	__property bool FreeOnTerminate = {read=FFreeOnTerminate, write=FFreeOnTerminate, nodefault};
	__property unsigned Handle = {read=FHandle, nodefault};
	__property TThreadPriority Priority = {read=GetPriority, write=SetPriority, nodefault};
	__property bool Suspended = {read=FSuspended, write=SetSuspended, nodefault};
	__property unsigned ThreadID = {read=FThreadID, nodefault};
	__property TNotifyEvent OnTerminate = {read=FOnTerminate, write=FOnTerminate};
};


#pragma option push -b-
enum TOperation { opInsert, opRemove };
#pragma option pop

#pragma option push -b-
enum Classes__74 { csLoading, csReading, csWriting, csDestroying, csDesigning, csAncestor, csUpdating, csFixups, csFreeNotification, csInline, csDesignInstance };
#pragma option pop

typedef Set<Classes__74, csLoading, csDesignInstance>  TComponentState;

#pragma option push -b-
enum Classes__84 { csInheritable, csCheckPropAvail, csSubComponent, csTransient };
#pragma option pop

typedef Set<Classes__84, csInheritable, csTransient>  TComponentStyle;

typedef void __fastcall (__closure *TGetChildProc)(TComponent* Child);

typedef AnsiString TComponentName;

__interface IVCLComObject;
typedef System::DelphiInterface<IVCLComObject> _di_IVCLComObject;
__interface INTERFACE_UUID("{E07892A0-F52F-11CF-BD2F-0020AF0E5B81}") IVCLComObject  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall GetTypeInfoCount(/* out */ int &Count) = 0 ;
	virtual HRESULT __stdcall GetTypeInfo(int Index, int LocaleID, /* out */ void *TypeInfo) = 0 ;
	virtual HRESULT __stdcall GetIDsOfNames(const GUID &IID, void * Names, int NameCount, int LocaleID, void * DispIDs) = 0 ;
	virtual HRESULT __stdcall Invoke(int DispID, const GUID &IID, int LocaleID, Word Flags, void *Params, void * VarResult, void * ExcepInfo, void * ArgErr) = 0 ;
	virtual HRESULT __fastcall SafeCallException(System::TObject* ExceptObject, void * ExceptAddr) = 0 ;
	virtual void __fastcall FreeOnRelease(void) = 0 ;
};

__interface IDesignerNotify;
typedef System::DelphiInterface<IDesignerNotify> _di_IDesignerNotify;
__interface INTERFACE_UUID("{B971E807-E3A6-11D1-AAB1-00C04FB16FBC}") IDesignerNotify  : public IInterface 
{
	
public:
	virtual void __fastcall Modified(void) = 0 ;
	virtual void __fastcall Notification(TPersistent* AnObject, TOperation Operation) = 0 ;
};

class DELPHICLASS TBasicAction;
class PASCALIMPLEMENTATION TComponent : public TPersistent 
{
	typedef TPersistent inherited;
	
private:
	TComponent* FOwner;
	AnsiString FName;
	int FTag;
	TList* FComponents;
	TList* FFreeNotifies;
	int FDesignInfo;
	TComponentState FComponentState;
	void *FVCLComObject;
	System::_di_IInterface __fastcall GetComObject();
	TComponent* __fastcall GetComponent(int AIndex);
	int __fastcall GetComponentCount(void);
	int __fastcall GetComponentIndex(void);
	void __fastcall Insert(TComponent* AComponent);
	void __fastcall ReadLeft(TReader* Reader);
	void __fastcall ReadTop(TReader* Reader);
	void __fastcall Remove(TComponent* AComponent);
	void __fastcall RemoveNotification(TComponent* AComponent);
	void __fastcall SetComponentIndex(int Value);
	void __fastcall SetReference(bool Enable);
	void __fastcall WriteLeft(TWriter* Writer);
	void __fastcall WriteTop(TWriter* Writer);
	TComponent* __fastcall IntfGetComponent(void);
	
protected:
	TComponentStyle FComponentStyle;
	void __fastcall ChangeName(const AnsiString NewName);
	virtual void __fastcall DefineProperties(TFiler* Filer);
	DYNAMIC void __fastcall GetChildren(TGetChildProc Proc, TComponent* Root);
	DYNAMIC TComponent* __fastcall GetChildOwner(void);
	DYNAMIC TComponent* __fastcall GetChildParent(void);
	DYNAMIC TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(TComponent* AComponent, TOperation Operation);
	DYNAMIC void __fastcall PaletteCreated(void);
	virtual void __fastcall ReadState(TReader* Reader);
	void __fastcall SetAncestor(bool Value);
	void __fastcall SetDesigning(bool Value, bool SetChildren = true);
	void __fastcall SetInline(bool Value);
	void __fastcall SetDesignInstance(bool Value);
	virtual void __fastcall SetName(const AnsiString NewName);
	DYNAMIC void __fastcall SetChildOrder(TComponent* Child, int Order);
	DYNAMIC void __fastcall SetParentComponent(TComponent* Value);
	DYNAMIC void __fastcall Updating(void);
	DYNAMIC void __fastcall Updated(void);
	/* virtual class method */ virtual void __fastcall UpdateRegistry(TMetaClass* vmt, bool Register, const AnsiString ClassID, const AnsiString ProgID);
	virtual void __fastcall ValidateRename(TComponent* AComponent, const AnsiString CurName, const AnsiString NewName);
	DYNAMIC void __fastcall ValidateContainer(TComponent* AComponent);
	DYNAMIC void __fastcall ValidateInsert(TComponent* AComponent);
	virtual void __fastcall WriteState(TWriter* Writer);
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	HRESULT __stdcall GetTypeInfoCount(/* out */ int &Count);
	HRESULT __stdcall GetTypeInfo(int Index, int LocaleID, /* out */ void *TypeInfo);
	HRESULT __stdcall GetIDsOfNames(const GUID &IID, void * Names, int NameCount, int LocaleID, void * DispIDs);
	HRESULT __stdcall Invoke(int DispID, const GUID &IID, int LocaleID, Word Flags, void *Params, void * VarResult, void * ExcepInfo, void * ArgErr);
	
public:
	__fastcall virtual TComponent(TComponent* AOwner);
	__fastcall virtual ~TComponent(void);
	virtual void __fastcall BeforeDestruction(void);
	void __fastcall DestroyComponents(void);
	void __fastcall Destroying(void);
	DYNAMIC bool __fastcall ExecuteAction(TBasicAction* Action);
	TComponent* __fastcall FindComponent(const AnsiString AName);
	void __fastcall FreeNotification(TComponent* AComponent);
	void __fastcall RemoveFreeNotification(TComponent* AComponent);
	void __fastcall FreeOnRelease(void);
	DYNAMIC TComponent* __fastcall GetParentComponent(void);
	DYNAMIC AnsiString __fastcall GetNamePath();
	DYNAMIC bool __fastcall HasParent(void);
	void __fastcall InsertComponent(TComponent* AComponent);
	void __fastcall RemoveComponent(TComponent* AComponent);
	void __fastcall SetSubComponent(bool IsSubComponent);
	virtual HRESULT __fastcall SafeCallException(System::TObject* ExceptObject, void * ExceptAddr);
	DYNAMIC bool __fastcall UpdateAction(TBasicAction* Action);
	bool __fastcall IsImplementorOf(const System::_di_IInterface I);
	bool __fastcall ReferenceInterface(const System::_di_IInterface I, TOperation Operation);
	__property System::_di_IInterface ComObject = {read=GetComObject};
	__property TComponent* Components[int Index] = {read=GetComponent};
	__property int ComponentCount = {read=GetComponentCount, nodefault};
	__property int ComponentIndex = {read=GetComponentIndex, write=SetComponentIndex, nodefault};
	__property TComponentState ComponentState = {read=FComponentState, nodefault};
	__property TComponentStyle ComponentStyle = {read=FComponentStyle, nodefault};
	__property int DesignInfo = {read=FDesignInfo, write=FDesignInfo, nodefault};
	__property TComponent* Owner = {read=FOwner};
	__property void * VCLComObject = {read=FVCLComObject, write=FVCLComObject};
	
__published:
	__property AnsiString Name = {read=FName, write=SetName, stored=false};
	__property int Tag = {read=FTag, write=FTag, default=0};
private:
	void *__IInterface;	/* System::IInterface */
	void *__IInterfaceComponentReference;	/* Classes::IInterfaceComponentReference [GetComponent=IntfGetComponent] */
	
public:
	operator IInterfaceComponentReference*(void) { return (IInterfaceComponentReference*)&__IInterfaceComponentReference; }
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


class DELPHICLASS TBasicActionLink;
class PASCALIMPLEMENTATION TBasicActionLink : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TNotifyEvent FOnChange;
	
protected:
	TBasicAction* FAction;
	virtual void __fastcall AssignClient(System::TObject* AClient);
	virtual void __fastcall Change(void);
	virtual bool __fastcall IsOnExecuteLinked(void);
	virtual void __fastcall SetAction(TBasicAction* Value);
	virtual void __fastcall SetOnExecute(TNotifyEvent Value);
	
public:
	__fastcall virtual TBasicActionLink(System::TObject* AClient);
	__fastcall virtual ~TBasicActionLink(void);
	virtual bool __fastcall Execute(TComponent* AComponent = (TComponent*)(0x0));
	virtual bool __fastcall Update(void);
	__property TBasicAction* Action = {read=FAction, write=SetAction};
	__property TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
};


typedef TMetaClass*TBasicActionLinkClass;

class PASCALIMPLEMENTATION TBasicAction : public TComponent 
{
	typedef TComponent inherited;
	
private:
	TComponent* FActionComponent;
	TNotifyEvent FOnChange;
	TNotifyEvent FOnExecute;
	TNotifyEvent FOnUpdate;
	
protected:
	TList* FClients;
	virtual void __fastcall Change(void);
	virtual void __fastcall SetOnExecute(TNotifyEvent Value);
	__property TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	virtual void __fastcall Notification(TComponent* AComponent, TOperation Operation);
	
public:
	__fastcall virtual TBasicAction(TComponent* AOwner);
	__fastcall virtual ~TBasicAction(void);
	virtual bool __fastcall HandlesTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	DYNAMIC bool __fastcall Execute(void);
	void __fastcall RegisterChanges(TBasicActionLink* Value);
	void __fastcall UnRegisterChanges(TBasicActionLink* Value);
	virtual bool __fastcall Update(void);
	__property TComponent* ActionComponent = {read=FActionComponent, write=FActionComponent};
	__property TNotifyEvent OnExecute = {read=FOnExecute, write=SetOnExecute};
	__property TNotifyEvent OnUpdate = {read=FOnUpdate, write=FOnUpdate};
};


typedef TMetaClass*TBasicActionClass;

class DELPHICLASS TDataModule;
class PASCALIMPLEMENTATION TDataModule : public TComponent 
{
	typedef TComponent inherited;
	
private:
	#pragma pack(push, 1)
	Types::TPoint FDesignSize;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	Types::TPoint FDesignOffset;
	#pragma pack(pop)
	
	TNotifyEvent FOnCreate;
	TNotifyEvent FOnDestroy;
	bool FOldCreateOrder;
	void __fastcall ReadHeight(TReader* Reader);
	void __fastcall ReadHorizontalOffset(TReader* Reader);
	void __fastcall ReadVerticalOffset(TReader* Reader);
	void __fastcall ReadWidth(TReader* Reader);
	void __fastcall WriteWidth(TWriter* Writer);
	void __fastcall WriteHorizontalOffset(TWriter* Writer);
	void __fastcall WriteVerticalOffset(TWriter* Writer);
	void __fastcall WriteHeight(TWriter* Writer);
	
protected:
	virtual void __fastcall DoCreate(void);
	virtual void __fastcall DoDestroy(void);
	virtual void __fastcall DefineProperties(TFiler* Filer);
	DYNAMIC void __fastcall GetChildren(TGetChildProc Proc, TComponent* Root);
	DYNAMIC bool __fastcall HandleCreateException(void);
	virtual void __fastcall ReadState(TReader* Reader);
	
public:
	__fastcall virtual TDataModule(TComponent* AOwner);
	__fastcall virtual TDataModule(TComponent* AOwner, int Dummy);
	__fastcall virtual ~TDataModule(void);
	virtual void __fastcall AfterConstruction(void);
	virtual void __fastcall BeforeDestruction(void);
	__property Types::TPoint DesignOffset = {read=FDesignOffset, write=FDesignOffset};
	__property Types::TPoint DesignSize = {read=FDesignSize, write=FDesignSize};
	
__published:
	__property bool OldCreateOrder = {read=FOldCreateOrder, write=FOldCreateOrder, nodefault};
	__property TNotifyEvent OnCreate = {read=FOnCreate, write=FOnCreate};
	__property TNotifyEvent OnDestroy = {read=FOnDestroy, write=FOnDestroy};
};


#pragma option push -b-
enum TActiveXRegType { axrComponentOnly, axrIncludeDescendants };
#pragma option pop

#pragma pack(push, 4)
struct TIdentMapEntry
{
	int Value;
	AnsiString Name;
} ;
#pragma pack(pop)

typedef bool __fastcall (*TIdentToInt)(const AnsiString Ident, int &Int);

typedef bool __fastcall (*TIntToIdent)(int Int, AnsiString &Ident);

typedef TComponent* __fastcall (*TFindGlobalComponent)(const AnsiString Name);

typedef bool __fastcall (*TIsUniqueGlobalComponentName)(const AnsiString Name);

#pragma option push -b-
enum TStreamOriginalFormat { sofUnknown, sofBinary, sofText };
#pragma option pop

typedef void __fastcall (__closure *TWndMethod)(Messages::TMessage &Message);

//-- var, const, procedure ---------------------------------------------------
static const int MaxListSize = 0x7ffffff;
static const Shortint soFromBeginning = 0x0;
static const Shortint soFromCurrent = 0x1;
static const Shortint soFromEnd = 0x2;
static const Word fmCreate = 0xffff;
static const char toEOF = '\x0';
static const char toSymbol = '\x1';
static const char toString = '\x2';
static const char toInteger = '\x3';
static const char toFloat = '\x4';
static const char toWString = '\x5';
static const Word scShift = 0x2000;
static const Word scCtrl = 0x4000;
static const Word scAlt = 0x8000;
static const Shortint scNone = 0x0;
extern PACKAGE void __fastcall (__closure *AddDataModule)(TDataModule* DataModule);
extern PACKAGE void __fastcall (__closure *RemoveDataModule)(TDataModule* DataModule);
extern PACKAGE void __fastcall (__closure *ApplicationHandleException)(System::TObject* Sender);
extern PACKAGE void __fastcall (__closure *ApplicationShowException)(Sysutils::Exception* E);
extern PACKAGE void __fastcall (*RegisterComponentsProc)(const AnsiString Page, TMetaClass* const * ComponentClasses, const int ComponentClasses_Size);
extern PACKAGE void __fastcall (*RegisterNoIconProc)(TMetaClass* const * ComponentClasses, const int ComponentClasses_Size);
extern PACKAGE int CurrentGroup;
extern PACKAGE void __fastcall (*RegisterNonActiveXProc)(TMetaClass* const * ComponentClasses, const int ComponentClasses_Size, TActiveXRegType AxRegType);
extern PACKAGE void __fastcall (*CreateVCLComObjectProc)(TComponent* Component);
extern PACKAGE Sysutils::TMultiReadExclusiveWriteSynchronizer* GlobalNameSpace;
extern PACKAGE TIsUniqueGlobalComponentName IsUniqueGlobalComponentNameProc;
extern PACKAGE TNotifyEvent WakeMainThread;
extern PACKAGE Types::TPoint __fastcall Point(int AX, int AY);
extern PACKAGE Types::TSmallPoint __fastcall SmallPoint(short AX, short AY);
extern PACKAGE bool __fastcall PointsEqual(const Types::TPoint &P1, const Types::TPoint &P2)/* overload */;
extern PACKAGE bool __fastcall PointsEqual(const Types::TSmallPoint P1, const Types::TSmallPoint P2)/* overload */;
extern PACKAGE Types::TRect __fastcall Rect(int ALeft, int ATop, int ARight, int ABottom)/* overload */;
extern PACKAGE Types::TRect __fastcall Rect(const Types::TPoint &ATopLeft, const Types::TPoint &ABottomRight)/* overload */;
extern PACKAGE Types::TRect __fastcall Bounds(int ALeft, int ATop, int AWidth, int AHeight);
extern PACKAGE bool __fastcall InvalidPoint(int X, int Y)/* overload */;
extern PACKAGE bool __fastcall InvalidPoint(const Types::TPoint &At)/* overload */;
extern PACKAGE bool __fastcall InvalidPoint(const Types::TSmallPoint At)/* overload */;
extern PACKAGE TMetaClass* __fastcall GetClass(const AnsiString AClassName);
extern PACKAGE TMetaClass* __fastcall FindClass(const AnsiString ClassName);
extern PACKAGE void __fastcall RegisterClass(TMetaClass* AClass);
extern PACKAGE void __fastcall RegisterClasses(TMetaClass* const * AClasses, const int AClasses_Size);
extern PACKAGE void __fastcall RegisterClassAlias(TMetaClass* AClass, const AnsiString Alias);
extern PACKAGE void __fastcall UnRegisterClass(TMetaClass* AClass);
extern PACKAGE void __fastcall UnRegisterClasses(TMetaClass* const * AClasses, const int AClasses_Size);
extern PACKAGE void __fastcall UnRegisterModuleClasses(unsigned Module);
extern PACKAGE void __fastcall StartClassGroup(TMetaClass* AClass);
extern PACKAGE void __fastcall GroupDescendentsWith(TMetaClass* AClass, TMetaClass* AClassGroup);
extern PACKAGE TMetaClass* __fastcall ActivateClassGroup(TMetaClass* AClass);
extern PACKAGE TMetaClass* __fastcall ClassGroupOf(TMetaClass* AClass)/* overload */;
extern PACKAGE TMetaClass* __fastcall ClassGroupOf(TPersistent* Instance)/* overload */;
extern PACKAGE void __fastcall RegisterComponents(const AnsiString Page, TMetaClass* const * ComponentClasses, const int ComponentClasses_Size);
extern PACKAGE void __fastcall RegisterNoIcon(TMetaClass* const * ComponentClasses, const int ComponentClasses_Size);
extern PACKAGE void __fastcall RegisterNonActiveX(TMetaClass* const * ComponentClasses, const int ComponentClasses_Size, TActiveXRegType AxRegType);
extern PACKAGE void __fastcall RegisterIntegerConsts(void * AIntegerType, TIdentToInt AIdentToInt, TIntToIdent AIntToIdent);
extern PACKAGE void __fastcall UnregisterIntegerConsts(void * AIntegerType, TIdentToInt AIdentToInt, TIntToIdent AIntToIdent);
extern PACKAGE TIntToIdent __fastcall FindIntToIdent(void * AIntegerType);
extern PACKAGE TIdentToInt __fastcall FindIdentToInt(void * AIntegerType);
extern PACKAGE bool __fastcall IdentToInt(const AnsiString Ident, int &Int, const TIdentMapEntry * Map, const int Map_Size);
extern PACKAGE bool __fastcall IntToIdent(int Int, AnsiString &Ident, const TIdentMapEntry * Map, const int Map_Size);
extern PACKAGE void __fastcall RegisterFindGlobalComponentProc(TFindGlobalComponent AFindGlobalComponent);
extern PACKAGE void __fastcall UnregisterFindGlobalComponentProc(TFindGlobalComponent AFindGlobalComponent);
extern PACKAGE TComponent* __fastcall FindGlobalComponent(const AnsiString Name);
extern PACKAGE bool __fastcall IsUniqueGlobalComponentName(const AnsiString Name);
extern PACKAGE void __fastcall BeginGlobalLoading(void);
extern PACKAGE void __fastcall NotifyGlobalLoading(void);
extern PACKAGE void __fastcall EndGlobalLoading(void);
extern PACKAGE bool __fastcall InitInheritedComponent(TComponent* Instance, TMetaClass* RootAncestor);
extern PACKAGE bool __fastcall InitComponentRes(const AnsiString ResName, TComponent* Instance);
extern PACKAGE TComponent* __fastcall ReadComponentRes(const AnsiString ResName, TComponent* Instance);
extern PACKAGE TComponent* __fastcall ReadComponentResEx(unsigned HInstance, const AnsiString ResName);
extern PACKAGE TComponent* __fastcall ReadComponentResFile(const AnsiString FileName, TComponent* Instance);
extern PACKAGE void __fastcall WriteComponentResFile(const AnsiString FileName, TComponent* Instance);
extern PACKAGE bool __fastcall CollectionsEqual(TCollection* C1, TCollection* C2, TComponent* Owner1, TComponent* Owner2);
extern PACKAGE char * __fastcall LineStart(char * Buffer, char * BufPos);
extern PACKAGE int __fastcall ExtractStrings(const Sysutils::TSysCharSet &Separators, const Sysutils::TSysCharSet &WhiteSpace, char * Content, TStrings* Strings);
extern PACKAGE _di_IDesignerNotify __fastcall FindRootDesigner(TPersistent* Obj);
extern PACKAGE int __fastcall CountGenerations(TMetaClass* Ancestor, TMetaClass* Descendent);
extern PACKAGE TPersistent* __fastcall GetUltimateOwner(TCollectionItem* ACollectionItem)/* overload */;
extern PACKAGE TPersistent* __fastcall GetUltimateOwner(TCollection* ACollection)/* overload */;
extern PACKAGE TPersistent* __fastcall GetUltimateOwner(TPersistent* APersistent)/* overload */;
extern PACKAGE TComponent* __fastcall FindNestedComponent(TComponent* Root, const AnsiString NamePath);
extern PACKAGE void __fastcall GlobalFixupReferences(void);
extern PACKAGE void __fastcall GetFixupReferenceNames(TComponent* Root, TStrings* Names);
extern PACKAGE void __fastcall RedirectFixupReferences(TComponent* Root, const AnsiString OldRootName, const AnsiString NewRootName);
extern PACKAGE void __fastcall RemoveFixupReferences(TComponent* Root, const AnsiString RootName);
extern PACKAGE void __fastcall RemoveFixups(TPersistent* Instance);
extern PACKAGE void __fastcall GetFixupInstanceNames(TComponent* Root, const AnsiString ReferenceRootName, TStrings* Names);
extern PACKAGE void __fastcall BinToHex(char * Buffer, char * Text, int BufSize);
extern PACKAGE int __fastcall HexToBin(char * Text, char * Buffer, int BufSize);
extern PACKAGE void __fastcall ObjectBinaryToText(TStream* Input, TStream* Output)/* overload */;
extern PACKAGE void __fastcall ObjectBinaryToText(TStream* Input, TStream* Output, TStreamOriginalFormat &OriginalFormat)/* overload */;
extern PACKAGE void __fastcall ObjectTextToBinary(TStream* Input, TStream* Output)/* overload */;
extern PACKAGE void __fastcall ObjectTextToBinary(TStream* Input, TStream* Output, TStreamOriginalFormat &OriginalFormat)/* overload */;
extern PACKAGE void __fastcall ObjectResourceToText(TStream* Input, TStream* Output)/* overload */;
extern PACKAGE void __fastcall ObjectResourceToText(TStream* Input, TStream* Output, TStreamOriginalFormat &OriginalFormat)/* overload */;
extern PACKAGE void __fastcall ObjectTextToResource(TStream* Input, TStream* Output)/* overload */;
extern PACKAGE void __fastcall ObjectTextToResource(TStream* Input, TStream* Output, TStreamOriginalFormat &OriginalFormat)/* overload */;
extern PACKAGE TStreamOriginalFormat __fastcall TestStreamFormat(TStream* Stream);
extern PACKAGE bool __fastcall CheckSynchronize(void);
extern PACKAGE void * __fastcall MakeObjectInstance(TWndMethod Method);
extern PACKAGE void __fastcall FreeObjectInstance(void * ObjectInstance);
extern PACKAGE HWND __fastcall AllocateHWnd(TWndMethod Method);
extern PACKAGE void __fastcall DeallocateHWnd(HWND Wnd);

}	/* namespace Classes */
using namespace Classes;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Classes
