// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdCoder3To4.pas' rev: 6.00

#ifndef IdCoder3To4HPP
#define IdCoder3To4HPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdException.hpp>	// Pascal unit
#include <IdCoder.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idcoder3to4
{
//-- type declarations -------------------------------------------------------
#pragma pack(push, 4)
struct TIdCardinalBytes
{
	
	union
	{
		struct 
		{
			unsigned Whole;
			
		};
		struct 
		{
			Byte Byte1;
			Byte Byte2;
			Byte Byte3;
			Byte Byte4;
			
		};
		
	};
} ;
#pragma pack(pop)

class DELPHICLASS TIdASCIICoder;
class PASCALIMPLEMENTATION TIdASCIICoder : public Idcoder::TIdCoder 
{
	typedef Idcoder::TIdCoder inherited;
	
protected:
	AnsiString FCodingTable;
	int FCodeTableLength;
	int __fastcall GetTableIndex(const char AChar);
	virtual void __fastcall SetCodingTable(AnsiString NewTable);
	
public:
	__property AnsiString CodingTable = {read=FCodingTable, write=SetCodingTable};
	__fastcall virtual TIdASCIICoder(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TIdCoder.Destroy */ inline __fastcall virtual ~TIdASCIICoder(void) { }
	#pragma option pop
	
};


class DELPHICLASS TId3To4Coder;
class PASCALIMPLEMENTATION TId3To4Coder : public TIdASCIICoder 
{
	typedef TIdASCIICoder inherited;
	
protected:
	void __fastcall Code3To4(Byte In1, Byte In2, Byte In3, Byte &Out1, Byte &Out2, Byte &Out3, Byte &Out4);
	void __fastcall Code4To3(const Byte AIn1, const Byte AIn2, const Byte AIn3, const Byte AIn4, Byte &AOut1, Byte &AOut2, Byte &AOut3);
	AnsiString __fastcall CodeLine3To4();
	AnsiString __fastcall CompleteLine3To4();
	AnsiString __fastcall CodeLine4To3();
	
public:
	__fastcall virtual TId3To4Coder(Classes::TComponent* AOwner);
	__fastcall virtual ~TId3To4Coder(void);
};


class DELPHICLASS TIdBase64Encoder;
typedef TIdBase64Encoder* *PIdBase64Encoder;

class PASCALIMPLEMENTATION TIdBase64Encoder : public TId3To4Coder 
{
	typedef TId3To4Coder inherited;
	
protected:
	virtual void __fastcall Coder(void);
	virtual void __fastcall CompleteCoding(void);
	
public:
	__fastcall virtual TIdBase64Encoder(Classes::TComponent* AOwner);
	__fastcall virtual ~TIdBase64Encoder(void);
};


class DELPHICLASS TIdBase64Decoder;
typedef TIdBase64Decoder* *PIdBase64Decoder;

class PASCALIMPLEMENTATION TIdBase64Decoder : public TId3To4Coder 
{
	typedef TId3To4Coder inherited;
	
protected:
	virtual void __fastcall Coder(void);
	virtual void __fastcall CompleteCoding(void);
	
public:
	__fastcall virtual TIdBase64Decoder(Classes::TComponent* AOwner);
	__fastcall virtual ~TIdBase64Decoder(void);
};


class DELPHICLASS TIdUUEncoder;
typedef TIdUUEncoder* *PIdUUEncoder;

class PASCALIMPLEMENTATION TIdUUEncoder : public TId3To4Coder 
{
	typedef TId3To4Coder inherited;
	
protected:
	bool FTableNeeded;
	bool FIsFirstRound;
	int FPrivilege;
	virtual void __fastcall Coder(void);
	virtual void __fastcall CompleteCoding(void);
	virtual void __fastcall OutputHeader(void);
	
public:
	__fastcall virtual TIdUUEncoder(Classes::TComponent* AOwner);
	__fastcall virtual ~TIdUUEncoder(void);
	virtual void __fastcall SetCodingTable(AnsiString NewTable);
	void __fastcall SetPrivilege(int Priv);
	__property int Privilege = {read=FPrivilege, write=SetPrivilege, nodefault};
	__property bool TableNeeded = {read=FTableNeeded, write=FTableNeeded, nodefault};
};


class DELPHICLASS TIdUUDecoder;
typedef TIdUUDecoder* *PIdUUDecoder;

class PASCALIMPLEMENTATION TIdUUDecoder : public TId3To4Coder 
{
	typedef TId3To4Coder inherited;
	
protected:
	bool FError;
	bool FCompleted;
	Classes::TStringList* FErrList;
	int FState;
	int FRealBufferSize;
	bool FIsFirstRound;
	int FPrivilege;
	virtual void __fastcall Coder(void);
	virtual void __fastcall CompleteCoding(void);
	virtual void __fastcall CheckForHeader(int DataSize);
	
public:
	__fastcall virtual TIdUUDecoder(Classes::TComponent* AOwner);
	__fastcall virtual ~TIdUUDecoder(void);
	virtual void __fastcall SetCodingTable(AnsiString NewTable);
	void __fastcall SetPrivilege(int Priv);
	__property int Privilege = {read=FPrivilege, write=SetPrivilege, nodefault};
};


class DELPHICLASS TIdXXEncoder;
typedef TIdXXEncoder* *PIdXXEncoder;

class PASCALIMPLEMENTATION TIdXXEncoder : public TIdUUEncoder 
{
	typedef TIdUUEncoder inherited;
	
public:
	__fastcall virtual TIdXXEncoder(Classes::TComponent* AOwner);
	__fastcall virtual ~TIdXXEncoder(void);
};


class DELPHICLASS TIdXXDecoder;
typedef TIdXXDecoder* *PIdXXDecoder;

class PASCALIMPLEMENTATION TIdXXDecoder : public TIdUUDecoder 
{
	typedef TIdUUDecoder inherited;
	
public:
	__fastcall virtual TIdXXDecoder(Classes::TComponent* AOwner);
	__fastcall virtual ~TIdXXDecoder(void);
};


class DELPHICLASS EIdTableNotFound;
class PASCALIMPLEMENTATION EIdTableNotFound : public Idexception::EIdException 
{
	typedef Idexception::EIdException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdTableNotFound(const AnsiString Msg) : Idexception::EIdException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdTableNotFound(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdTableNotFound(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdTableNotFound(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdTableNotFound(const AnsiString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdTableNotFound(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdTableNotFound(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdTableNotFound(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdTableNotFound(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint CTL3To4 = 0x40;
static const Shortint HalfCodeTable = 0x20;
extern PACKAGE AnsiString Base64CodeTable;
extern PACKAGE AnsiString UUCodeTable;
extern PACKAGE AnsiString XXCodeTable;
#define UUTable "TABLE"
#define UUBegin "BEGIN "
#define UUEnd "END"
static const Word minPriv = 0x258;
static const Word maxPriv = 0x31f;
static const Shortint UUStarted = 0x0;
static const Shortint UUTableBegun = 0x1;
static const Shortint UUTableOneLine = 0x2;
static const Shortint UUTableBeenRead = 0x3;
static const Shortint UUDataStarted = 0x4;
static const Shortint UUBEGINFound = 0x5;
static const Shortint UUPrivilegeFound = 0x6;
static const Shortint UUInitialLength = 0x8;
static const Shortint UULastCharFound = 0x9;
static const Shortint UUENDFound = 0xa;
static const bool UUErrTableNotAtEnd = false;
#define UUErrIncompletePrivilege "Not enough chars for three-digit Privilege"
#define UUErrIncompletePrivilege2 "Too many chars for three-digit Privilege"
#define UUErrorPivilageNotNumeric "Privilege chars not numeric"
#define UUErrorNoBEGINAfterTABLE "No BEGIN statement followed a TABLE"
#define UUErrorDataEndWithoutEND " Data ended without an END statment"
extern PACKAGE AnsiString __fastcall Base64Encode(const AnsiString s);

}	/* namespace Idcoder3to4 */
using namespace Idcoder3to4;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdCoder3To4
