// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'NMFtp.pas' rev: 6.00

#ifndef NMFtpHPP
#define NMFtpHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <NMConst.hpp>	// Pascal unit
#include <WinSock.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Psock.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Nmftp
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TFirewallType { FTUser, FtOpen, FtSite };
#pragma option pop

class DELPHICLASS TFTPDirectoryList;
class PASCALIMPLEMENTATION TFTPDirectoryList : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TStringList* FAttribute;
	Classes::TStringList* FName;
	Classes::TStringList* FModifDate;
	Classes::TStringList* FSize;
	System::ShortString tokens[25];
	int NoTokens;
	
public:
	__fastcall TFTPDirectoryList(void);
	__fastcall virtual ~TFTPDirectoryList(void);
	virtual void __fastcall ParseLine(AnsiString Line);
	void __fastcall Clear(void);
	__property Classes::TStringList* Attribute = {read=FAttribute};
	__property Classes::TStringList* name = {read=FName};
	__property Classes::TStringList* Size = {read=FSize};
	__property Classes::TStringList* ModifDate = {read=FModifDate};
};


class DELPHICLASS TFTPUnixList;
class PASCALIMPLEMENTATION TFTPUnixList : public TFTPDirectoryList 
{
	typedef TFTPDirectoryList inherited;
	
public:
	virtual void __fastcall ParseLine(AnsiString Line);
public:
	#pragma option push -w-inl
	/* TFTPDirectoryList.Create */ inline __fastcall TFTPUnixList(void) : TFTPDirectoryList() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TFTPDirectoryList.Destroy */ inline __fastcall virtual ~TFTPUnixList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFTPNETWAREList;
class PASCALIMPLEMENTATION TFTPNETWAREList : public TFTPDirectoryList 
{
	typedef TFTPDirectoryList inherited;
	
public:
	virtual void __fastcall ParseLine(AnsiString Line);
public:
	#pragma option push -w-inl
	/* TFTPDirectoryList.Create */ inline __fastcall TFTPNETWAREList(void) : TFTPDirectoryList() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TFTPDirectoryList.Destroy */ inline __fastcall virtual ~TFTPNETWAREList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFTPDOSList;
class PASCALIMPLEMENTATION TFTPDOSList : public TFTPDirectoryList 
{
	typedef TFTPDirectoryList inherited;
	
public:
	virtual void __fastcall ParseLine(AnsiString Line);
public:
	#pragma option push -w-inl
	/* TFTPDirectoryList.Create */ inline __fastcall TFTPDOSList(void) : TFTPDirectoryList() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TFTPDirectoryList.Destroy */ inline __fastcall virtual ~TFTPDOSList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFTPVMSList;
class PASCALIMPLEMENTATION TFTPVMSList : public TFTPDirectoryList 
{
	typedef TFTPDirectoryList inherited;
	
public:
	virtual void __fastcall ParseLine(AnsiString Line);
public:
	#pragma option push -w-inl
	/* TFTPDirectoryList.Create */ inline __fastcall TFTPVMSList(void) : TFTPDirectoryList() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TFTPDirectoryList.Destroy */ inline __fastcall virtual ~TFTPVMSList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFTPMVSList;
class PASCALIMPLEMENTATION TFTPMVSList : public TFTPDirectoryList 
{
	typedef TFTPDirectoryList inherited;
	
public:
	virtual void __fastcall ParseLine(AnsiString Line);
public:
	#pragma option push -w-inl
	/* TFTPDirectoryList.Create */ inline __fastcall TFTPMVSList(void) : TFTPDirectoryList() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TFTPDirectoryList.Destroy */ inline __fastcall virtual ~TFTPMVSList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFTPVMList;
class PASCALIMPLEMENTATION TFTPVMList : public TFTPDirectoryList 
{
	typedef TFTPDirectoryList inherited;
	
public:
	virtual void __fastcall ParseLine(AnsiString Line);
public:
	#pragma option push -w-inl
	/* TFTPDirectoryList.Create */ inline __fastcall TFTPVMList(void) : TFTPDirectoryList() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TFTPDirectoryList.Destroy */ inline __fastcall virtual ~TFTPVMList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFTPMACOSList;
class PASCALIMPLEMENTATION TFTPMACOSList : public TFTPDirectoryList 
{
	typedef TFTPDirectoryList inherited;
	
public:
	virtual void __fastcall ParseLine(AnsiString Line);
public:
	#pragma option push -w-inl
	/* TFTPDirectoryList.Create */ inline __fastcall TFTPMACOSList(void) : TFTPDirectoryList() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TFTPDirectoryList.Destroy */ inline __fastcall virtual ~TFTPMACOSList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFTPAS400List;
class PASCALIMPLEMENTATION TFTPAS400List : public TFTPDirectoryList 
{
	typedef TFTPDirectoryList inherited;
	
public:
	virtual void __fastcall ParseLine(AnsiString Line);
public:
	#pragma option push -w-inl
	/* TFTPDirectoryList.Create */ inline __fastcall TFTPAS400List(void) : TFTPDirectoryList() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TFTPDirectoryList.Destroy */ inline __fastcall virtual ~TFTPAS400List(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFTPOTHERList;
class PASCALIMPLEMENTATION TFTPOTHERList : public TFTPDirectoryList 
{
	typedef TFTPDirectoryList inherited;
	
public:
	virtual void __fastcall ParseLine(AnsiString Line);
public:
	#pragma option push -w-inl
	/* TFTPDirectoryList.Create */ inline __fastcall TFTPOTHERList(void) : TFTPDirectoryList() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TFTPDirectoryList.Destroy */ inline __fastcall virtual ~TFTPOTHERList(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TCmdType { cmdChangeDir, cmdMakeDir, cmdDelete, cmdRemoveDir, cmdList, cmdRename, cmdUpRestore, cmdDownRestore, cmdDownload, cmdUpload, cmdAppend, cmdReInit, cmdAllocate, cmdNList, cmdDoCommand, cmdCurrentDir };
#pragma option pop

class DELPHICLASS FTPException;
class PASCALIMPLEMENTATION FTPException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall FTPException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall FTPException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall FTPException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall FTPException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall FTPException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall FTPException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall FTPException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall FTPException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~FTPException(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TFailureEvent)(bool &Handled, TCmdType Trans_Type);

typedef void __fastcall (__closure *TSuccessEvent)(TCmdType Trans_Type);

typedef void __fastcall (__closure *TUnsupportedEvent)(TCmdType Trans_Type);

typedef void __fastcall (__closure *TNMListItem)(AnsiString Listing);

class DELPHICLASS TNMFTP;
class PASCALIMPLEMENTATION TNMFTP : public Psock::TPowersock 
{
	typedef Psock::TPowersock inherited;
	
private:
	_RTL_CRITICAL_SECTION ProcessLock;
	bool CurrentlyListing;
	AnsiString FUserID;
	AnsiString FPassword;
	bool FPassive;
	Psock::TPowersock* DataSocket;
	Classes::TNotifyEvent FTransactionStart;
	Classes::TNotifyEvent FTransactionStop;
	TSuccessEvent FOnSuccess;
	TFailureEvent FOnFailure;
	Psock::THandlerEvent FOnAuthenticationNeeded;
	Psock::THandlerEvent FOnAuthenticationFailed;
	TNMListItem FOnListItem;
	Classes::TNotifyEvent FOnConnect;
	TUnsupportedEvent FOnUnSupportedFunction;
	int FVendor;
	TFTPDirectoryList* FFTPDirectoryList;
	bool FParseList;
	TFirewallType FFirewallType;
	AnsiString FFWUserID;
	AnsiString FFWPassword;
	bool FFWAuth;
	int __fastcall GetBytesRcvd(void);
	int __fastcall GetBytesSent(void);
	int __fastcall GetBytesTotal(AnsiString Replymess);
	virtual AnsiString __fastcall Transaction(const AnsiString CommandString);
	void __fastcall CheckRead(System::TObject* Sender);
	AnsiString __fastcall GetCurrentDir();
	void __fastcall ReadExtraLines(AnsiString Replymess);
	void __fastcall Flush(void);
	
public:
	__fastcall virtual TNMFTP(Classes::TComponent* AOwner);
	virtual void __fastcall Connect(void);
	__fastcall virtual ~TNMFTP(void);
	virtual void __fastcall Disconnect(void);
	void __fastcall DoCommand(AnsiString CommandStr);
	void __fastcall ChangeDir(AnsiString DirName);
	void __fastcall Mode(int TheMode);
	void __fastcall Delete(AnsiString Filename);
	void __fastcall MakeDirectory(AnsiString DirectoryName);
	void __fastcall RemoveDir(AnsiString DirectoryName);
	void __fastcall List(void);
	void __fastcall Rename(AnsiString Filename, AnsiString FileName2);
	void __fastcall Download(AnsiString RemoteFile, AnsiString LocalFile);
	void __fastcall DownloadRestore(AnsiString RemoteFile, AnsiString LocalFile);
	void __fastcall Upload(AnsiString LocalFile, AnsiString RemoteFile);
	void __fastcall UploadUnique(AnsiString LocalFile);
	void __fastcall UploadAppend(AnsiString LocalFile, AnsiString RemoteFile);
	void __fastcall UploadRestore(AnsiString LocalFile, AnsiString RemoteFile, int Position);
	void __fastcall Reinitialize(void);
	void __fastcall Allocate(int FileSize);
	void __fastcall Nlist(void);
	virtual void __fastcall Abort(void);
	__property AnsiString CurrentDir = {read=GetCurrentDir};
	__property int BytesSent = {read=GetBytesSent, nodefault};
	__property int BytesRecvd = {read=GetBytesRcvd, nodefault};
	__property TFTPDirectoryList* FTPDirectoryList = {read=FFTPDirectoryList};
	
__published:
	__property OnPacketRecvd ;
	__property OnPacketSent ;
	__property OnError ;
	__property OnConnectionRequired ;
	__property Classes::TNotifyEvent OnConnect = {read=FOnConnect, write=FOnConnect};
	__property AnsiString UserID = {read=FUserID, write=FUserID};
	__property AnsiString Password = {read=FPassword, write=FPassword};
	__property Classes::TNotifyEvent OnTransactionStart = {read=FTransactionStart, write=FTransactionStart};
	__property Classes::TNotifyEvent OnTransactionStop = {read=FTransactionStop, write=FTransactionStop};
	__property Psock::THandlerEvent OnAuthenticationNeeded = {read=FOnAuthenticationNeeded, write=FOnAuthenticationNeeded};
	__property Psock::THandlerEvent OnAuthenticationFailed = {read=FOnAuthenticationFailed, write=FOnAuthenticationFailed};
	__property TFailureEvent OnFailure = {read=FOnFailure, write=FOnFailure};
	__property TSuccessEvent OnSuccess = {read=FOnSuccess, write=FOnSuccess};
	__property TNMListItem OnListItem = {read=FOnListItem, write=FOnListItem};
	__property TUnsupportedEvent OnUnSupportedFunction = {read=FOnUnSupportedFunction, write=FOnUnSupportedFunction};
	__property int Vendor = {read=FVendor, write=FVendor, nodefault};
	__property bool ParseList = {read=FParseList, write=FParseList, nodefault};
	__property Proxy ;
	__property ProxyPort ;
	__property bool Passive = {read=FPassive, write=FPassive, nodefault};
	__property TFirewallType FirewallType = {read=FFirewallType, write=FFirewallType, nodefault};
	__property AnsiString FWUserID = {read=FFWUserID, write=FFWUserID};
	__property AnsiString FWPassword = {read=FFWPassword, write=FFWPassword};
	__property bool FWAuthenticate = {read=FFWAuth, write=FFWAuth, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint MODE_ASCII = 0x1;
static const Shortint MODE_IMAGE = 0x2;
static const Shortint MODE_BYTE = 0x3;
#define Cont_Quit "QUIT"
#define Cont_User "USER "
#define Cont_Pass "PASS "
#define Cont_Cwd "CWD "
#define Cont_Rnfr "RNFR "
#define Cont_Rnto "RNTO "
#define Cont_Dele "DELE "
#define Cont_Mkd "MKD "
#define Cont_Rmd "RMD "
#define Cont_Port "PORT "
#define Cont_List "LIST"
#define Cont_Nlst "NLST"
#define Cont_Retr "RETR "
#define Cont_Stou "STOU"
#define Cont_Stor "STOR "
#define Cont_Pwd "PWD"
#define Cont_Typ "TYPE "
#define No_Byte "BYTE"
#define Cont_Rein "REIN"
#define Cont_Allo "ALLO "
#define Cont_Appe "APPE "
#define Cont_Rest "REST "
static const Shortint NMOS_UNKNOWN = 0xffffffff;
static const Word NMOS_FIRST = 0x960;
static const Word NMOS_UNIX = 0x960;
static const Word NMOS_WINDOWS = 0x961;
static const Word NMOS_VM = 0x962;
static const Word NMOS_BULL = 0x963;
static const Word NMOS_MAC = 0x964;
static const Word NMOS_TOPS20 = 0x965;
static const Word NMOS_VMS = 0x966;
static const Word NMOS_OS2 = 0x967;
static const Word NMOS_MVS_IBM = 0x968;
static const Word NMOS_MVS_INTERLINK = 0x969;
static const Word NMOS_OTHER = 0x96a;
static const Word NMOS_AUTO = 0x96b;
static const Word NMOS_NT = 0x96c;
static const Word NMOS_TANDEM = 0x96d;
static const Word NMOS_AS400 = 0x96e;
static const Word NMOS_OS9 = 0x96f;
static const Word NMOS_NETWARE = 0x970;

}	/* namespace Nmftp */
using namespace Nmftp;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// NMFtp
