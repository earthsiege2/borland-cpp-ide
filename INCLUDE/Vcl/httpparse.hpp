// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'HTTPParse.pas' rev: 6.00

#ifndef HTTPParseHPP
#define HTTPParseHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Httpparse
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS THTTPParser;
class PASCALIMPLEMENTATION THTTPParser : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TStream* FStream;
	int FOrigin;
	char *FBuffer;
	char *FBufPtr;
	char *FBufEnd;
	char *FSourcePtr;
	char *FSourceEnd;
	char *FStringPtr;
	int FSourceLine;
	char FSaveChar;
	char FToken;
	bool FHeaderField;
	char *FTokenPtr;
	void __fastcall ReadBuffer(void);
	void __fastcall SkipBlanks(void);
	
public:
	__fastcall THTTPParser(Classes::TStream* Stream);
	__fastcall virtual ~THTTPParser(void);
	void __fastcall CheckToken(char T);
	void __fastcall CheckTokenSymbol(const AnsiString S);
	AnsiString __fastcall CopyTo(int Length);
	AnsiString __fastcall CopyToEOL();
	AnsiString __fastcall CopyToEOF();
	void __fastcall Error(const AnsiString Ident);
	void __fastcall ErrorFmt(const AnsiString Ident, const System::TVarRec * Args, const int Args_Size);
	void __fastcall ErrorStr(const AnsiString Message);
	void __fastcall HexToBinary(Classes::TStream* Stream);
	char __fastcall NextToken(void);
	void __fastcall SkipEOL(void);
	int __fastcall SourcePos(void);
	Extended __fastcall TokenFloat(void);
	int __fastcall TokenInt(void);
	AnsiString __fastcall TokenString();
	bool __fastcall TokenSymbolIs(const AnsiString S);
	Classes::TStream* __fastcall BufferRequest(int Length);
	__property int SourceLine = {read=FSourceLine, nodefault};
	__property char Token = {read=FToken, nodefault};
	__property bool HeaderField = {read=FHeaderField, write=FHeaderField, nodefault};
	__property char * SourcePtr = {read=FSourcePtr, write=FSourcePtr};
	__property char * TokenPtr = {read=FTokenPtr, write=FTokenPtr};
	__property Classes::TStream* Stream = {read=FStream};
	__property char * SourceEnd = {read=FSourceEnd};
};


//-- var, const, procedure ---------------------------------------------------
static const char toEOL = '\x5';
static const char toGET = '\x6';
static const char toHEAD = '\x7';
static const char toPUT = '\x8';
static const char toDELETE = '\x9';
static const char toPOST = '\xa';
static const char toPATCH = '\xb';
static const char toCOPY = '\xc';
static const char toUserAgent = '\xd';
static const char toAccept = '\xe';
static const char toContentType = '\xf';
static const char toContentLength = '\x10';
static const char toReferer = '\x11';
static const char toAuthorization = '\x12';
static const char toCacheControl = '\x13';
static const char toDate = '\x14';
static const char toFrom = '\x15';
static const char toHost = '\x16';
static const char toIfModified = '\x17';
static const char toContentEncoding = '\x18';
static const char toContentVersion = '\x19';
static const char toAllow = '\x1a';
static const char toConnection = '\x1b';
static const char toCookie = '\x1c';
static const char toContentDisposition = '\x1d';
static const Word hcGET = 0x14f5;
static const Word hcPUT = 0x4af5;
static const Word hcDELETE = 0x92b2;
static const Word hcPOST = 0x361d;
static const Word hcCacheControl = 0x4ff6;
static const Word hcDate = 0xee6;
static const Word hcFrom = 0x418f;
static const Word hcHost = 0x3611;
static const Word hcIfModified = 0xddf0;
static const Word hcAllow = 0x3d80;
static const Word hcUserAgent = 0xe890;
static const Word hcAccept = 0x1844;
static const Word hcContentEncoding = 0xc586;
static const Word hcContentVersion = 0xedf4;
static const Word hcContentType = 0xf0e0;
static const Word hcContentLength = 0xb0c4;
static const Word hcReferer = 0xcea5;
static const Word hcAuthorization = 0xabca;
static const Word hcConnection = 0xede;
static const Word hcCookie = 0x27b3;
static const Word hcContentDisposition = 0xcbeb;

}	/* namespace Httpparse */
using namespace Httpparse;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// HTTPParse
