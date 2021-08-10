// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdFTP.pas' rev: 6.00

#ifndef IdFTPHPP
#define IdFTPHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdComponent.hpp>	// Pascal unit
#include <IdURI.hpp>	// Pascal unit
#include <IdThread.hpp>	// Pascal unit
#include <IdTCPClient.hpp>	// Pascal unit
#include <IdTCPConnection.hpp>	// Pascal unit
#include <IdSocketHandle.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <IdGlobal.hpp>	// Pascal unit
#include <IdException.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idftp
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdFTPTransferType { ftBinary, ftASCII };
#pragma option pop

class DELPHICLASS TIdFTP;
class PASCALIMPLEMENTATION TIdFTP : public Idtcpclient::TIdTCPClient 
{
	typedef Idtcpclient::TIdTCPClient inherited;
	
protected:
	AnsiString FUser;
	bool FPassive;
	AnsiString FPassword;
	AnsiString FSystemDesc;
	TIdFTPTransferType FTransferType;
	Idtcpconnection::TIdTCPConnection* FDataChannel;
	void __fastcall InternalGet(const AnsiString ACommand, Classes::TStream* ADest);
	void __fastcall InternalPut(const AnsiString ACommand, Classes::TStream* ASource);
	void __fastcall SendPassive(AnsiString &VIP, int &VPort);
	void __fastcall SendPort(Idsockethandle::TIdSocketHandle* AHandle);
	void __fastcall SendTransferType(void);
	void __fastcall SetDataChannelWorkEvents(void);
	void __fastcall SetTransferType(TIdFTPTransferType AValue);
	
public:
	virtual void __fastcall Abort(void);
	void __fastcall ChangeDir(const AnsiString ADirName);
	void __fastcall ChangeDirUp(void);
	HIDESBASE void __fastcall Connect(bool AutoLogin = true);
	__fastcall virtual TIdFTP(Classes::TComponent* AOwner);
	void __fastcall Delete(const AnsiString AFilename);
	void __fastcall Get(const AnsiString ASourceFile, Classes::TStream* ADest)/* overload */;
	void __fastcall Get(const AnsiString ASourceFile, const AnsiString ADestFile, const bool ACanOverwrite = false)/* overload */;
	virtual void __fastcall KillDataChannel(void);
	void __fastcall List(Classes::TStrings* ADest, const AnsiString ASpecifier = "", const bool ADetails = true);
	void __fastcall MakeDir(const AnsiString ADirName);
	void __fastcall Noop(void);
	void __fastcall Put(const Classes::TStream* ASource, const AnsiString ADestFile = "", const bool AAppend = false)/* overload */;
	void __fastcall Put(const AnsiString ASourceFile, const AnsiString ADestFile = "", const bool AAppend = false)/* overload */;
	void __fastcall Quit(void);
	void __fastcall RemoveDir(const AnsiString ADirName);
	void __fastcall Rename(const AnsiString ASourceFile, const AnsiString ADestFile);
	AnsiString __fastcall RetrieveCurrentDir();
	void __fastcall Site(const AnsiString ACommand);
	int __fastcall Size(const AnsiString AFileName);
	__property AnsiString SystemDesc = {read=FSystemDesc};
	
__published:
	__property bool Passive = {read=FPassive, write=FPassive, default=0};
	__property AnsiString Password = {read=FPassword, write=FPassword};
	__property TIdFTPTransferType TransferType = {read=FTransferType, write=SetTransferType, default=0};
	__property AnsiString User = {read=FUser, write=FUser};
	__property Port  = {default=21};
public:
	#pragma option push -w-inl
	/* TIdTCPClient.Destroy */ inline __fastcall virtual ~TIdFTP(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdFTPFileAlreadyExists;
class PASCALIMPLEMENTATION EIdFTPFileAlreadyExists : public Idexception::EIdException 
{
	typedef Idexception::EIdException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdFTPFileAlreadyExists(const AnsiString Msg) : Idexception::EIdException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdFTPFileAlreadyExists(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdFTPFileAlreadyExists(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdFTPFileAlreadyExists(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdFTPFileAlreadyExists(const AnsiString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdFTPFileAlreadyExists(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdFTPFileAlreadyExists(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdFTPFileAlreadyExists(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdFTPFileAlreadyExists(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define Id_TIdFTP_TransferType (TIdFTPTransferType)(0)
static const bool Id_TIdFTP_Passive = false;

}	/* namespace Idftp */
using namespace Idftp;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdFTP
