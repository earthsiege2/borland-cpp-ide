// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IBInstall.pas' rev: 6.00

#ifndef IBInstallHPP
#define IBInstallHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IBXConst.hpp>	// Pascal unit
#include <IBIntf.hpp>	// Pascal unit
#include <IBInstallHeader.hpp>	// Pascal unit
#include <IB.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ibinstall
{
//-- type declarations -------------------------------------------------------
typedef int TIscError;

#pragma option push -b-
enum TIBInstallerError { ieSuccess, ieDelphiException, ieNoOptionsSet, ieNoDestinationDirectory, ieNosourceDirectory, ieNoUninstallFile, ieOptionNeedsClient, ieOptionNeedsServer, ieInvalidOption, ieInvalidOnErrorResult, ieInvalidOnStatusResult };
#pragma option pop

#pragma option push -b-
enum TMainOption { moServer, moClient, moConServer, moGuiTools, moDocumentation, moDevelopment };
#pragma option pop

#pragma option push -b-
enum TExamplesOption { exDB, exAPI };
#pragma option pop

#pragma option push -b-
enum TCmdOption { cmDBMgmt, cmDBQuery, cmUsrMgmt };
#pragma option pop

#pragma option push -b-
enum TConnectivityOption { cnODBC, cnOLEDB, cnJDBC };
#pragma option pop

typedef Set<TMainOption, moServer, moDevelopment>  TMainOptions;

typedef Set<TExamplesOption, exDB, exAPI>  TExamplesOptions;

typedef Set<TCmdOption, cmDBMgmt, cmUsrMgmt>  TCmdOptions;

typedef Set<TConnectivityOption, cnODBC, cnJDBC>  TConnectivityOptions;

#pragma option push -b-
enum TErrorResult { erAbort, erContinue, erRetry };
#pragma option pop

#pragma option push -b-
enum TStatusResult { srAbort, srContinue };
#pragma option pop

#pragma option push -b-
enum TWarningResult { wrAbort, wrContinue };
#pragma option pop

typedef TStatusResult __fastcall (__closure *TIBSetupOnStatus)(System::TObject* Sender, AnsiString StatusComment);

typedef TWarningResult __fastcall (__closure *TIBSetupOnWarning)(System::TObject* Sender, int WarningCode, AnsiString WarningMessage);

typedef TErrorResult __fastcall (__closure *TIBSetupOnError)(System::TObject* Sender, int IscCode, AnsiString ErrorMessage, AnsiString ErrorComment);

class DELPHICLASS EIBInstall;
class PASCALIMPLEMENTATION EIBInstall : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
private:
	int FIscError;
	TIBInstallerError FInstallerError;
	
public:
	__fastcall virtual EIBInstall(int IscCode, AnsiString IscMessage)/* overload */;
	__fastcall virtual EIBInstall(TIBInstallerError ECode, AnsiString EMessage)/* overload */;
	__property int InstallError = {read=FIscError, nodefault};
	__property TIBInstallerError InstallerError = {read=FInstallerError, nodefault};
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIBInstall(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIBInstall(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIBInstall(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIBInstall(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIBInstall(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIBInstall(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIBInstall(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIBInstall(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIBInstallError;
class PASCALIMPLEMENTATION EIBInstallError : public EIBInstall 
{
	typedef EIBInstall inherited;
	
public:
	#pragma option push -w-inl
	/* EIBInstall.Create */ inline __fastcall virtual EIBInstallError(int IscCode, AnsiString IscMessage)/* overload */ : EIBInstall(IscCode, IscMessage) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIBInstallError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIBInstall(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIBInstallError(int Ident)/* overload */ : EIBInstall(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIBInstallError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIBInstall(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIBInstallError(const AnsiString Msg, int AHelpContext) : EIBInstall(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIBInstallError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIBInstall(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIBInstallError(int Ident, int AHelpContext)/* overload */ : EIBInstall(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIBInstallError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIBInstall(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIBInstallError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIBInstallerError;
class PASCALIMPLEMENTATION EIBInstallerError : public EIBInstall 
{
	typedef EIBInstall inherited;
	
public:
	#pragma option push -w-inl
	/* EIBInstall.Create */ inline __fastcall virtual EIBInstallerError(int IscCode, AnsiString IscMessage)/* overload */ : EIBInstall(IscCode, IscMessage) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIBInstallerError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIBInstall(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIBInstallerError(int Ident)/* overload */ : EIBInstall(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIBInstallerError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIBInstall(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIBInstallerError(const AnsiString Msg, int AHelpContext) : EIBInstall(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIBInstallerError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIBInstall(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIBInstallerError(int Ident, int AHelpContext)/* overload */ : EIBInstall(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIBInstallerError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIBInstall(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIBInstallerError(void) { }
	#pragma option pop
	
};


class DELPHICLASS TInstallOptions;
class PASCALIMPLEMENTATION TInstallOptions : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	TMainOptions FMainComponents;
	TExamplesOptions FExamples;
	TCmdOptions FCmdLineTools;
	TConnectivityOptions FConnectivityClients;
	
__published:
	__property TMainOptions MainComponents = {read=FMainComponents, write=FMainComponents, nodefault};
	__property TCmdOptions CmdLineTools = {read=FCmdLineTools, write=FCmdLineTools, nodefault};
	__property TConnectivityOptions ConnectivityClients = {read=FConnectivityClients, write=FConnectivityClients, nodefault};
	__property TExamplesOptions Examples = {read=FExamples, write=FExamples, nodefault};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TInstallOptions(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TInstallOptions(void) : Classes::TPersistent() { }
	#pragma option pop
	
};


class DELPHICLASS TIBSetup;
class PASCALIMPLEMENTATION TIBSetup : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	bool FIBInstallLoaded;
	bool FRebootToComplete;
	int FProgress;
	AnsiString FMsgFilePath;
	TIBSetupOnStatus FOnStatusChange;
	void *FStatusContext;
	TIBSetupOnError FOnError;
	void *FErrorContext;
	TIBSetupOnWarning FOnWarning;
	void __fastcall SetMsgFilePath(const AnsiString Value);
	
protected:
	int __fastcall StatusInternal(int Status, const char * ActionDescription);
	int __fastcall ErrorInternal(int IscCode, const char * ActionDescription);
	void __fastcall Call(int IscCode);
	void __fastcall IBInstallError(int IscCode);
	AnsiString __fastcall GetInstallMessage(int IscCode);
	
public:
	__fastcall virtual TIBSetup(Classes::TComponent* AOwner);
	__property bool RebootToComplete = {read=FRebootToComplete, nodefault};
	__property int Progress = {read=FProgress, nodefault};
	__property void * StatusContext = {read=FStatusContext, write=FStatusContext};
	__property void * ErrorContext = {read=FErrorContext, write=FErrorContext};
	__property AnsiString MsgFilePath = {read=FMsgFilePath, write=SetMsgFilePath};
	
__published:
	__property TIBSetupOnWarning OnWarning = {read=FOnWarning, write=FOnWarning};
	__property TIBSetupOnError OnError = {read=FOnError, write=FOnError};
	__property TIBSetupOnStatus OnStatusChange = {read=FOnStatusChange, write=FOnStatusChange};
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TIBSetup(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIBInstall;
class PASCALIMPLEMENTATION TIBInstall : public TIBSetup 
{
	typedef TIBSetup inherited;
	
private:
	AnsiString FUnInstallFile;
	AnsiString FSourceDir;
	AnsiString FDestinationDir;
	AnsiString FSuggestedDestination;
	TInstallOptions* FInstallOptions;
	void __fastcall GetOptionProperty(int InfoType, TExamplesOption Option, void * Buffer, unsigned BufferLen)/* overload */;
	void __fastcall GetOptionProperty(int InfoType, TMainOption Option, void * Buffer, unsigned BufferLen)/* overload */;
	void __fastcall GetOptionProperty(int InfoType, TConnectivityOption Option, void * Buffer, unsigned BufferLen)/* overload */;
	void __fastcall GetOptionProperty(int InfoType, TCmdOption Option, void * Buffer, unsigned BufferLen)/* overload */;
	void __fastcall InternalSetOptions(Ibinstallheader::POPTIONS_HANDLE pHandle);
	void __fastcall SetDestination(const AnsiString Value);
	void __fastcall SetSource(const AnsiString Value);
	void __fastcall SetInstallOptions(const TInstallOptions* Value);
	void __fastcall SuggestDestination(void);
	
public:
	__fastcall virtual TIBInstall(Classes::TComponent* AOwner);
	__fastcall virtual ~TIBInstall(void);
	void __fastcall InstallCheck(void);
	void __fastcall InstallExecute(void);
	AnsiString __fastcall GetOptionDescription(TExamplesOption Option)/* overload */;
	AnsiString __fastcall GetOptionDescription(TMainOption Option)/* overload */;
	AnsiString __fastcall GetOptionDescription(TConnectivityOption Option)/* overload */;
	AnsiString __fastcall GetOptionDescription(TCmdOption Option)/* overload */;
	AnsiString __fastcall GetOptionName(TExamplesOption Option)/* overload */;
	AnsiString __fastcall GetOptionName(TMainOption Option)/* overload */;
	AnsiString __fastcall GetOptionName(TConnectivityOption Option)/* overload */;
	AnsiString __fastcall GetOptionName(TCmdOption Option)/* overload */;
	unsigned __fastcall GetOptionSpaceRequired(TExamplesOption Option)/* overload */;
	unsigned __fastcall GetOptionSpaceRequired(TMainOption Option)/* overload */;
	unsigned __fastcall GetOptionSpaceRequired(TConnectivityOption Option)/* overload */;
	unsigned __fastcall GetOptionSpaceRequired(TCmdOption Option)/* overload */;
	__property AnsiString UnInstallFile = {read=FUnInstallFile};
	__property AnsiString SuggestedDestination = {read=FSuggestedDestination};
	
__published:
	__property AnsiString SourceDirectory = {read=FSourceDir, write=SetSource};
	__property AnsiString DestinationDirectory = {read=FDestinationDir, write=SetDestination};
	__property TInstallOptions* InstallOptions = {read=FInstallOptions, write=SetInstallOptions};
};


class DELPHICLASS TIBUnInstall;
class PASCALIMPLEMENTATION TIBUnInstall : public TIBSetup 
{
	typedef TIBSetup inherited;
	
private:
	AnsiString FUnInstallFile;
	
public:
	void __fastcall UnInstallCheck(void);
	void __fastcall UnInstallExecute(void);
	__property AnsiString UnInstallFile = {read=FUnInstallFile, write=FUnInstallFile};
public:
	#pragma option push -w-inl
	/* TIBSetup.Create */ inline __fastcall virtual TIBUnInstall(Classes::TComponent* AOwner) : TIBSetup(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TIBUnInstall(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Ibinstall */
using namespace Ibinstall;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IBInstall
