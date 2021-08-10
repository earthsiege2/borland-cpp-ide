// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdCoderMessageDigest.pas' rev: 6.00

#ifndef IdCoderMessageDigestHPP
#define IdCoderMessageDigestHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdCoder.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idcodermessagedigest
{
//-- type declarations -------------------------------------------------------
typedef Byte T64BitRecord[8];

typedef Byte T128BitRecord[16];

typedef unsigned T4x4LongWordRecord[4];

typedef unsigned T4x4x4LongWordRecord[4][4];

typedef unsigned T16x4LongWordRecord[16];

typedef Byte T160BitRecord[20];

typedef Byte T384BitRecord[48];

class DELPHICLASS TIdCoderMD2;
class PASCALIMPLEMENTATION TIdCoderMD2 : public Idcoder::TIdCoder 
{
	typedef Idcoder::TIdCoder inherited;
	
protected:
	Byte FBuffer[16];
	Byte FChecksum[16];
	int FCount;
	Byte FCheckSumScore;
	Byte FState[16];
	Byte FX[48];
	virtual void __fastcall Coder(void);
	virtual void __fastcall CompleteCoding(void);
	
public:
	__fastcall virtual TIdCoderMD2(Classes::TComponent* AOwner);
	virtual void __fastcall Reset(void);
	virtual void __fastcall FillSamples(Classes::TStrings* AStringList);
	virtual void __fastcall SetBufferSize(unsigned ASize);
public:
	#pragma option push -w-inl
	/* TIdCoder.Destroy */ inline __fastcall virtual ~TIdCoderMD2(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIdCoderMD4;
class PASCALIMPLEMENTATION TIdCoderMD4 : public Idcoder::TIdCoder 
{
	typedef Idcoder::TIdCoder inherited;
	
protected:
	unsigned FBitsProcessed;
	unsigned FBuffer[4];
	Byte FCount[8];
	bool FDone;
	virtual void __fastcall Coder(void);
	virtual void __fastcall CompleteCoding(void);
	virtual unsigned __fastcall func_f(unsigned x, unsigned y, unsigned z);
	virtual unsigned __fastcall func_g(unsigned x, unsigned y, unsigned z);
	virtual unsigned __fastcall func_h(unsigned x, unsigned y, unsigned z);
	
public:
	__fastcall virtual TIdCoderMD4(Classes::TComponent* AOwner);
	virtual void __fastcall Reset(void);
	virtual void __fastcall FillSamples(Classes::TStrings* AStringList);
	virtual void __fastcall SetBufferSize(unsigned ASize);
public:
	#pragma option push -w-inl
	/* TIdCoder.Destroy */ inline __fastcall virtual ~TIdCoderMD4(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIdCoderMD5;
class PASCALIMPLEMENTATION TIdCoderMD5 : public TIdCoderMD4 
{
	typedef TIdCoderMD4 inherited;
	
protected:
	virtual void __fastcall Coder(void);
	virtual unsigned __fastcall func_g(unsigned x, unsigned y, unsigned z);
	virtual unsigned __fastcall func_i(unsigned x, unsigned y, unsigned z);
	
public:
	__fastcall virtual TIdCoderMD5(Classes::TComponent* AOwner);
	virtual void __fastcall FillSamples(Classes::TStrings* AStringList);
public:
	#pragma option push -w-inl
	/* TIdCoder.Destroy */ inline __fastcall virtual ~TIdCoderMD5(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idcodermessagedigest */
using namespace Idcodermessagedigest;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdCoderMessageDigest
