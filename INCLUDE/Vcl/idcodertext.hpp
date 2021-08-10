// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdCoderText.pas' rev: 6.00

#ifndef IdCoderTextHPP
#define IdCoderTextHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdCoder.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idcodertext
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdQuotedPrintableEncoder;
class PASCALIMPLEMENTATION TIdQuotedPrintableEncoder : public Idcoder::TIdCoder 
{
	typedef Idcoder::TIdCoder inherited;
	
protected:
	AnsiString FQPOutputString;
	virtual void __fastcall QPOutput(const AnsiString sOut);
	AnsiString __fastcall ToQuotedPrintable(const Byte b);
	virtual void __fastcall Coder(void);
	virtual void __fastcall CompleteCoding(void);
	
public:
	__fastcall virtual TIdQuotedPrintableEncoder(Classes::TComponent* AOwner);
	__fastcall virtual ~TIdQuotedPrintableEncoder(void);
	virtual void __fastcall Reset(void);
};


class DELPHICLASS TIdQuotedPrintableDecoder;
class PASCALIMPLEMENTATION TIdQuotedPrintableDecoder : public Idcoder::TIdCoder 
{
	typedef Idcoder::TIdCoder inherited;
	
protected:
	AnsiString fQPTriple;
	Byte fInTriple;
	virtual void __fastcall Coder(void);
	virtual void __fastcall CompleteCoding(void);
	
public:
	__fastcall virtual TIdQuotedPrintableDecoder(Classes::TComponent* AOwner);
	__fastcall virtual ~TIdQuotedPrintableDecoder(void);
	virtual void __fastcall Reset(void);
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idcodertext */
using namespace Idcodertext;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdCoderText
