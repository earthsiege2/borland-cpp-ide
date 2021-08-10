// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'NMUUE.pas' rev: 5.00

#ifndef NMUUEHPP
#define NMUUEHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <NMConst.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Nmuue
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum UUMethods { uuMime, uuCode };
#pragma option pop

typedef char ExchangeTable[64];

class DELPHICLASS TNMUUProcessor;
class PASCALIMPLEMENTATION TNMUUProcessor : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Classes::TNotifyEvent FOnBeginEncode;
	Classes::TNotifyEvent FOnEndEncode;
	Classes::TNotifyEvent FOnBeginDecode;
	Classes::TNotifyEvent FOnEndDecode;
	char EncodingTable[64];
	Classes::TStream* FInputStream;
	Classes::TStream* FOutputStream;
	void __fastcall StdDecode(void);
	void __fastcall Base64Decode(void);
	void __fastcall ReadLnFromStream(Classes::TStream* FromStream, AnsiString &Dline);
	
protected:
	UUMethods fUUMethod;
	void __fastcall SetEncodeTable(void);
	Byte __fastcall UuDEC(Byte InByte);
	
public:
	__fastcall virtual TNMUUProcessor(Classes::TComponent* AOwner);
	void __fastcall Encode(void);
	void __fastcall Decode(void);
	__property Classes::TStream* InputStream = {read=FInputStream, write=FInputStream};
	__property Classes::TStream* OutputStream = {read=FOutputStream, write=FOutputStream};
	
__published:
	__property UUMethods Method = {read=fUUMethod, write=fUUMethod, default=0};
	__property Classes::TNotifyEvent OnBeginEncode = {read=FOnBeginEncode, write=FOnBeginEncode};
	__property Classes::TNotifyEvent OnEndEncode = {read=FOnEndEncode, write=FOnEndEncode};
	__property Classes::TNotifyEvent OnBeginDecode = {read=FOnBeginDecode, write=FOnBeginDecode};
	__property Classes::TNotifyEvent OnEndDecode = {read=FOnEndDecode, write=FOnEndDecode};
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TNMUUProcessor(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define CRLF "\r\n"
static const char CR = '\xd';
static const char LF = '\xa';
extern PACKAGE char UUTABLE[64];
extern PACKAGE char MimeTable[64];
extern PACKAGE Byte base64Table[80];

}	/* namespace Nmuue */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Nmuue;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// NMUUE
