// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'OleAuto.pas' rev: 6.00

#ifndef OleAutoHPP
#define OleAutoHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysUtils.hpp>	// Pascal unit
#include <OleCtl.hpp>	// Pascal unit
#include <Ole2.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <comobj.hpp>

namespace Oleauto
{
//-- type declarations -------------------------------------------------------
typedef TMetaClass*TAutoClass;

#pragma option push -b-
enum TAutoClassInstancing { acInternal, acSingleInstance, acMultiInstance };
#pragma option pop

#pragma pack(push, 4)
struct TAutoClassInfo
{
	TMetaClass*AutoClass;
	AnsiString ProgID;
	AnsiString ClassID;
	AnsiString Description;
	TAutoClassInstancing Instancing;
} ;
#pragma pack(pop)

class DELPHICLASS TRegistryClass;
class PASCALIMPLEMENTATION TRegistryClass : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TRegistryClass* FNext;
	TMetaClass*FAutoClass;
	AnsiString FProgID;
	GUID FClassID;
	AnsiString FDescription;
	TAutoClassInstancing FInstancing;
	int FRegister;
	
public:
	__fastcall TRegistryClass(const TAutoClassInfo &AutoClassInfo);
	__fastcall virtual ~TRegistryClass(void);
	void __fastcall UpdateRegistry(bool Register);
};


#pragma option push -b-
enum TStartMode { smStandalone, smAutomation, smRegServer, smUnregServer };
#pragma option pop

typedef void __fastcall (__closure *TLastReleaseEvent)(bool &Shutdown);

class DELPHICLASS TAutomation;
class PASCALIMPLEMENTATION TAutomation : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TRegistryClass* FRegistryList;
	int FAutoObjectCount;
	int FClassFactoryCount;
	bool FIsInprocServer;
	TStartMode FStartMode;
	TLastReleaseEvent FOnLastRelease;
	void __fastcall CountAutoObject(bool Created);
	void __fastcall Initialize(void);
	void __fastcall LastReleased(void);
	
public:
	__fastcall TAutomation(void);
	__fastcall virtual ~TAutomation(void);
	void __fastcall RegisterClass(const TAutoClassInfo &AutoClassInfo);
	void __fastcall UpdateRegistry(bool Register);
	__property int AutoObjectCount = {read=FAutoObjectCount, nodefault};
	__property bool IsInprocServer = {read=FIsInprocServer, write=FIsInprocServer, nodefault};
	__property TStartMode StartMode = {read=FStartMode, nodefault};
	__property TLastReleaseEvent OnLastRelease = {read=FOnLastRelease, write=FOnLastRelease};
};


class DELPHICLASS EOleError;
class PASCALIMPLEMENTATION EOleError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EOleError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EOleError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EOleError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EOleError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EOleError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EOleError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EOleError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EOleError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EOleError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EOleSysError;
class PASCALIMPLEMENTATION EOleSysError : public EOleError 
{
	typedef EOleError inherited;
	
private:
	int FErrorCode;
	
public:
	__fastcall EOleSysError(int ErrorCode);
	__property int ErrorCode = {read=FErrorCode, nodefault};
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EOleSysError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EOleError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EOleSysError(int Ident, const double* Dummy)/* overload */ : EOleError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EOleSysError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EOleError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EOleSysError(const AnsiString Msg, int AHelpContext) : EOleError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EOleSysError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EOleError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EOleSysError(int Ident, int AHelpContext)/* overload */ : EOleError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EOleSysError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EOleError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EOleSysError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EOleException;
class PASCALIMPLEMENTATION EOleException : public EOleError 
{
	typedef EOleError inherited;
	
private:
	int FErrorCode;
	AnsiString FSource;
	AnsiString FHelpFile;
	
public:
	__fastcall EOleException(const tagEXCEPINFO &ExcepInfo);
	__property int ErrorCode = {read=FErrorCode, nodefault};
	__property AnsiString HelpFile = {read=FHelpFile};
	__property AnsiString Source = {read=FSource};
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EOleException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EOleError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EOleException(int Ident, const double* Dummy)/* overload */ : EOleError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EOleException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EOleError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EOleException(const AnsiString Msg, int AHelpContext) : EOleError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EOleException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EOleError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EOleException(int Ident, int AHelpContext)/* overload */ : EOleError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EOleException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EOleError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EOleException(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint MaxDispArgs = 0x20;
extern PACKAGE TAutomation* Automation;
extern PACKAGE void __fastcall OleError(HRESULT ErrorCode);
extern PACKAGE void __fastcall OleCheck(HRESULT Result);
extern PACKAGE GUID __fastcall StringToClassID(const AnsiString S);
extern PACKAGE AnsiString __fastcall ClassIDToString(const GUID &ClassID);
extern PACKAGE GUID __fastcall ProgIDToClassID(const AnsiString ProgID);
extern PACKAGE AnsiString __fastcall ClassIDToProgID(const GUID &ClassID);
extern PACKAGE Variant __fastcall VarFromInterface(IUnknown* Unknown);
extern PACKAGE IDispatch* __fastcall VarToInterface(const Variant &V);
extern PACKAGE Variant __fastcall CreateOleObject(const AnsiString ClassName);
extern PACKAGE Variant __fastcall GetActiveOleObject(const AnsiString ClassName);
extern PACKAGE void __fastcall DispInvoke(IDispatch* Dispatch, System::PCallDesc CallDesc, Ole2::PDispIDList DispIDs, void * Params, System::PVariant Result);
extern PACKAGE void __fastcall DispInvokeError(HRESULT Status, const tagEXCEPINFO &ExcepInfo);
extern PACKAGE HRESULT __stdcall DllGetClassObject(const GUID &CLSID, const GUID &IID, void *Obj);
extern PACKAGE HRESULT __stdcall DllCanUnloadNow(void);
extern PACKAGE HRESULT __stdcall DllRegisterServer(void);
extern PACKAGE HRESULT __stdcall DllUnregisterServer(void);

}	/* namespace Oleauto */
using namespace Oleauto;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// OleAuto
