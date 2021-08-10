// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'CopyPrsr.pas' rev: 6.00

#ifndef CopyPrsrHPP
#define CopyPrsrHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Copyprsr
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCopyParser;
class PASCALIMPLEMENTATION TCopyParser : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TStream* FStream;
	Classes::TStream* FOutStream;
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
	void __fastcall ReadBuffer(void);
	void __fastcall SkipBlanks(bool DoCopy);
	char __fastcall SkipToNextToken(bool CopyBlanks, bool DoCopy);
	AnsiString __fastcall CopySkipTo(int Length, bool DoCopy);
	AnsiString __fastcall CopySkipToToken(char AToken, bool DoCopy);
	AnsiString __fastcall CopySkipToEOL(bool DoCopy);
	AnsiString __fastcall CopySkipToEOF(bool DoCopy);
	void __fastcall UpdateOutStream(char * StartPos);
	
public:
	__fastcall TCopyParser(Classes::TStream* Stream, Classes::TStream* OutStream);
	__fastcall virtual ~TCopyParser(void);
	void __fastcall CheckToken(char T);
	void __fastcall CheckTokenSymbol(const AnsiString S);
	AnsiString __fastcall CopyTo(int Length);
	AnsiString __fastcall CopyToToken(char AToken);
	AnsiString __fastcall CopyToEOL();
	AnsiString __fastcall CopyToEOF();
	void __fastcall CopyTokenToOutput(void);
	void __fastcall Error(const AnsiString Ident);
	void __fastcall ErrorFmt(const AnsiString Ident, const System::TVarRec * Args, const int Args_Size);
	void __fastcall ErrorStr(const AnsiString Message);
	char __fastcall NextToken(void);
	char __fastcall SkipToken(bool CopyBlanks);
	void __fastcall SkipEOL(void);
	AnsiString __fastcall SkipTo(int Length);
	AnsiString __fastcall SkipToToken(char AToken);
	AnsiString __fastcall SkipToEOL();
	AnsiString __fastcall SkipToEOF();
	int __fastcall SourcePos(void);
	AnsiString __fastcall TokenComponentIdent();
	Extended __fastcall TokenFloat(void);
	int __fastcall TokenInt(void);
	AnsiString __fastcall TokenString();
	bool __fastcall TokenSymbolIs(const AnsiString S);
	__property int SourceLine = {read=FSourceLine, nodefault};
	__property char Token = {read=FToken, nodefault};
	__property Classes::TStream* OutputStream = {read=FOutStream, write=FOutStream};
};


//-- var, const, procedure ---------------------------------------------------
static const char toEOL = '\x5';

}	/* namespace Copyprsr */
using namespace Copyprsr;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CopyPrsr
