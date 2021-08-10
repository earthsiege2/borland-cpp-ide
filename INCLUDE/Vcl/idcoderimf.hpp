// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdCoderIMF.pas' rev: 6.00

#ifndef IdCoderIMFHPP
#define IdCoderIMFHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysUtils.hpp>	// Pascal unit
#include <IdCoder.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idcoderimf
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdIMFDecoder;
class PASCALIMPLEMENTATION TIdIMFDecoder : public Idcoder::TIdCoder 
{
	typedef Idcoder::TIdCoder inherited;
	
protected:
	Byte FState;
	AnsiString FContentType;
	AnsiString FContentTransferEncoding;
	AnsiString FDefaultContentType;
	AnsiString FDefaultContentTransferEncoding;
	bool FDefaultContentFound;
	bool FDefaultContentTypeFound;
	bool FDefaultContentTransferEncodingFound;
	AnsiString FLastContentType;
	AnsiString FLastContentTransferEncoding;
	AnsiString FCurHeader;
	AnsiString FTrueString;
	Classes::TStringList* FMIMEBoundary;
	Idcoder::TIdCoder* FInternalDecoder;
	virtual void __fastcall CreateDecoder(void);
	virtual void __fastcall Coder(void);
	virtual void __fastcall CompleteCoding(void);
	virtual void __fastcall IMFStart(void);
	virtual void __fastcall IMFMessageStart(void);
	virtual void __fastcall IMFBoundaryEnd(void);
	virtual void __fastcall ProcessHeader(void);
	virtual void __fastcall RenewCoder(void);
	void __fastcall WriteOutput(Classes::TComponent* Sender, const AnsiString sOut);
	
public:
	__fastcall virtual TIdIMFDecoder(Classes::TComponent* AOwner);
	__fastcall virtual ~TIdIMFDecoder(void);
	virtual void __fastcall Reset(void);
};


class DELPHICLASS TIdIMFUUDecoder;
class PASCALIMPLEMENTATION TIdIMFUUDecoder : public TIdIMFDecoder 
{
	typedef TIdIMFDecoder inherited;
	
protected:
	virtual void __fastcall CreateDecoder(void);
	virtual void __fastcall RenewCoder(void);
	
public:
	__fastcall virtual TIdIMFUUDecoder(Classes::TComponent* AOwner);
	__fastcall virtual ~TIdIMFUUDecoder(void);
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint ConstIMFStart = 0x0;
static const Shortint ConstIMFMessageStart = 0x1;
static const Shortint ConstIMFBoundaryEnd = 0x2;
#define ConstContentType "content-type"
#define ConstContentTransferEncoding "content-transfer-encoding"
#define ConstContentDisposition "content-disposition"
#define ConstContentMD5 "content-md5"
#define ConstBoundary "boundary"
#define ConstFileName "filename"
#define ConstName "name"

}	/* namespace Idcoderimf */
using namespace Idcoderimf;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdCoderIMF
