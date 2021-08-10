// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdLogDebug.pas' rev: 6.00

#ifndef IdLogDebugHPP
#define IdLogDebugHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdIntercept.hpp>	// Pascal unit
#include <IdSocketHandle.hpp>	// Pascal unit
#include <IdException.hpp>	// Pascal unit
#include <IdLogBase.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idlogdebug
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdLogDebugTarget { ltFile, ltDebugOutput, ltEvent };
#pragma option pop

typedef void __fastcall (__closure *TLogItemEvent)(Classes::TComponent* ASender, AnsiString &AText);

class DELPHICLASS TIdLogDebug;
class PASCALIMPLEMENTATION TIdLogDebug : public Idlogbase::TIdLogBase 
{
	typedef Idlogbase::TIdLogBase inherited;
	
protected:
	AnsiString FFilename;
	Classes::TFileStream* FFileStream;
	TLogItemEvent FOnLogItem;
	TIdLogDebugTarget FTarget;
	virtual void __fastcall Log(AnsiString AText);
	virtual void __fastcall SetActive(const bool AValue);
	void __fastcall SetTarget(const TIdLogDebugTarget AValue);
	
public:
	__fastcall virtual TIdLogDebug(Classes::TComponent* AOwner);
	__fastcall virtual ~TIdLogDebug(void);
	
__published:
	__property AnsiString Filename = {read=FFilename, write=FFilename};
	__property TLogItemEvent OnLogItem = {read=FOnLogItem, write=FOnLogItem};
	__property TIdLogDebugTarget Target = {read=FTarget, write=SetTarget, default=0};
};


class DELPHICLASS EIdCanNotChangeTarget;
class PASCALIMPLEMENTATION EIdCanNotChangeTarget : public Idexception::EIdException 
{
	typedef Idexception::EIdException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdCanNotChangeTarget(const AnsiString Msg) : Idexception::EIdException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdCanNotChangeTarget(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdCanNotChangeTarget(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdCanNotChangeTarget(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdCanNotChangeTarget(const AnsiString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdCanNotChangeTarget(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdCanNotChangeTarget(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdCanNotChangeTarget(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdCanNotChangeTarget(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define ID_TIDLOGDEBUG_TARGET (TIdLogDebugTarget)(0)

}	/* namespace Idlogdebug */
using namespace Idlogdebug;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdLogDebug
