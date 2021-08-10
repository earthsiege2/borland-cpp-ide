//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// FmxUtils.hpp - dcc32 generated hdr (DO NOT EDIT) rev: 0
// From: FmxUtils.pas
//----------------------------------------------------------------------------
#ifndef FmxUtilsHPP
#define FmxUtilsHPP
//----------------------------------------------------------------------------
#include <consts.hpp>
#include <Classes.hpp>
#include <Windows.hpp>
#include <SysUtils.hpp>
#include <System.hpp>
//-- type declarations -------------------------------------------------------
class __declspec(delphiclass) EInvalidDest;
class __declspec(pascalimplementation) EInvalidDest : public EStreamError
{
	typedef EStreamError inherited;
	
public:
	/* Exception.Create */ __fastcall EInvalidDest(const AnsiString Msg) : EStreamError(Msg) { }
	/* Exception.CreateFmt */ __fastcall EInvalidDest(const AnsiString Msg, const TVarRec *Args, const 
		int Args_Size) : EStreamError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ __fastcall EInvalidDest(int Ident) : EStreamError(Ident) { }
	/* Exception.CreateResFmt */ __fastcall EInvalidDest(int Ident, const TVarRec *Args, const int Args_Size
		) : EStreamError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ __fastcall EInvalidDest(const AnsiString Msg, int AHelpContext) : EStreamError(
		Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ __fastcall EInvalidDest(const AnsiString Msg, const TVarRec *Args, const 
		int Args_Size, int AHelpContext) : EStreamError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ __fastcall EInvalidDest(int Ident, int AHelpContext) : EStreamError(Ident
		, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ __fastcall EInvalidDest(int Ident, const TVarRec *Args, const int
		Args_Size, int AHelpContext) : EStreamError(Ident, Args, Args_Size, AHelpContext) { }

public:
	/* TObject.Destroy */ __fastcall virtual ~EInvalidDest(void) { }

};

class EFCantMove : public EStreamError
{
	typedef EStreamError inherited;

public:
	/* Exception.Create */ __fastcall EFCantMove(const AnsiString Msg) : EStreamError(Msg) { }
	/* Exception.CreateFmt */ __fastcall EFCantMove(const AnsiString Msg, const TVarRec *Args, const int
		Args_Size) : EStreamError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ __fastcall EFCantMove(int Ident) : EStreamError(Ident) { }
	/* Exception.CreateResFmt */ __fastcall EFCantMove(int Ident, const TVarRec *Args, const int Args_Size
		) : EStreamError(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ __fastcall EFCantMove(const AnsiString Msg, int AHelpContext) : EStreamError(
		Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ __fastcall EFCantMove(const AnsiString Msg, const TVarRec *Args, const 
		int Args_Size, int AHelpContext) : EStreamError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ __fastcall EFCantMove(int Ident, int AHelpContext) : EStreamError(Ident
		, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ __fastcall EFCantMove(int Ident, const TVarRec *Args, const int Args_Size
		, int AHelpContext) : EStreamError(Ident, Args, Args_Size, AHelpContext) { }
	
public:
	/* TObject.Destroy */ __fastcall virtual ~EFCantMove(void) { }
	
};

//-- var, const, procedure ---------------------------------------------------
extern void __fastcall CopyFile(const AnsiString FileName, const AnsiString DestName);
extern void __fastcall MoveFile(const AnsiString FileName, const AnsiString DestName);
extern long __fastcall GetFileSize(const AnsiString FileName);
extern TDateTime __fastcall FileDateTime(const AnsiString FileName);
extern bool __fastcall HasAttr(const AnsiString FileName, unsigned short Attr);
extern int __fastcall ExecuteFile(const AnsiString FileName, const AnsiString Params, const AnsiString 
	DefaultDir, int ShowCmd);
//-- end unit ----------------------------------------------------------------
#endif	// FmxUtils
