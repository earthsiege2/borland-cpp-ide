// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'NSToIS.pas' rev: 6.00

#ifndef NSToISHPP
#define NSToISHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SyncObjs.hpp>	// Pascal unit
#include <Nsapi.hpp>	// Pascal unit
#include <Isapi2.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Nstois
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TISAPIApplication;
class DELPHICLASS TISAPIApplicationList;
class PASCALIMPLEMENTATION TISAPIApplicationList : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TList* FList;
	Syncobjs::TCriticalSection* FCriticalSection;
	Nsapi::TFile *FLogfd;
	void __fastcall AddApplication(TISAPIApplication* ISAPIApplication);
	void __fastcall ClearApplications(void);
	TISAPIApplication* __fastcall FindApplication(const AnsiString AFileName);
	void __fastcall RemoveApplication(TISAPIApplication* ISAPIApplication);
	
public:
	__fastcall TISAPIApplicationList(void);
	__fastcall virtual ~TISAPIApplicationList(void);
	TISAPIApplication* __fastcall LoadApplication(const AnsiString AFileName);
	int __fastcall InitLog(Nsapi::PPblock pb, Nsapi::PSession sn, Nsapi::PRequest rq);
	void __fastcall LogMessage(const AnsiString Fmt, const System::TVarRec * Params, const int Params_Size);
};


class PASCALIMPLEMENTATION TISAPIApplication : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	unsigned FModule;
	AnsiString FFileName;
	#pragma pack(push, 1)
	Isapi2::HSE_VERSION_INFO FVersionInfo;
	#pragma pack(pop)
	
	TISAPIApplicationList* FOwner;
	
public:
	Isapi2::TGetExtensionVersion GetExtensionVersion;
	Isapi2::THttpExtensionProc HTTPExtensionProc;
	Isapi2::TTerminateExtension TerminateExtension;
	__fastcall TISAPIApplication(TISAPIApplicationList* AOWner, const AnsiString AFileName);
	__fastcall virtual ~TISAPIApplication(void);
	void __fastcall Load(void);
	void __fastcall Unload(bool Ask);
	__property Isapi2::HSE_VERSION_INFO VersionInfo = {read=FVersionInfo};
};


class DELPHICLASS EISAPIException;
class PASCALIMPLEMENTATION EISAPIException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EISAPIException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EISAPIException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EISAPIException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EISAPIException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EISAPIException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EISAPIException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EISAPIException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EISAPIException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EISAPIException(void) { }
	#pragma option pop
	
};


class DELPHICLASS TISAPISession;
class PASCALIMPLEMENTATION TISAPISession : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	#pragma pack(push, 1)
	Isapi2::TEXTENSION_CONTROL_BLOCK FECB;
	#pragma pack(pop)
	
	TISAPIApplication* FISAPIApplication;
	AnsiString FPathTranslated;
	Nsapi::TPblock *Fpb;
	Nsapi::TSession *Fsn;
	Nsapi::TRequest *Frq;
	char * *Fenv;
	Syncobjs::TEvent* FEvent;
	bool __fastcall GetServerVariable(char * VariableName, void * Buffer, unsigned &Size);
	bool __fastcall WriteClient(void * Buffer, unsigned &Bytes);
	bool __fastcall ReadClient(void * Buffer, unsigned &Size);
	bool __fastcall ServerSupportFunction(unsigned HSERequest, void * Buffer, PDWORD Size, PDWORD DataType);
	
public:
	__fastcall TISAPISession(Nsapi::PPblock pb, Nsapi::PSession sn, Nsapi::PRequest rq, TISAPIApplication* ISAPIApplication);
	__fastcall virtual ~TISAPISession(void);
	void __fastcall ProcessExtension(void);
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TISAPIApplicationList* ISAPIApplicationList;
extern PACKAGE AnsiString __fastcall UnixPathToDosPath(const AnsiString Path);
extern PACKAGE AnsiString __fastcall DosPathToUnixPath(const AnsiString Path);
extern PACKAGE void __fastcall LogMessage(const AnsiString Fmt, const System::TVarRec * Params, const int Params_Size);
extern PACKAGE void __fastcall InitISAPIApplicationList(void);
extern PACKAGE void __fastcall DoneISAPIAPplicationList(void);

}	/* namespace Nstois */
using namespace Nstois;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// NSToIS
