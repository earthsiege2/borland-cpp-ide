// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdNNTPServer.pas' rev: 6.00

#ifndef IdNNTPServerHPP
#define IdNNTPServerHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdComponent.hpp>	// Pascal unit
#include <IdTCPServer.hpp>	// Pascal unit
#include <IdGlobal.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idnntpserver
{
//-- type declarations -------------------------------------------------------
typedef AnsiString IdNNTPServer__1[26];

typedef void __fastcall (__closure *TGetEvent)(Idtcpserver::TIdPeerThread* AThread);

typedef void __fastcall (__closure *TOtherEvent)(Idtcpserver::TIdPeerThread* AThread, AnsiString ACommand, AnsiString AParm, bool &AHandled);

typedef void __fastcall (__closure *TDoByIDEvent)(Idtcpserver::TIdPeerThread* AThread, AnsiString AActualID);

typedef void __fastcall (__closure *TDoByNoEvent)(Idtcpserver::TIdPeerThread* AThread, unsigned AActualNumber);

typedef void __fastcall (__closure *TGroupEvent)(Idtcpserver::TIdPeerThread* AThread, AnsiString AGroup);

typedef void __fastcall (__closure *TNewsEvent)(Idtcpserver::TIdPeerThread* AThread, AnsiString AParm);

typedef void __fastcall (__closure *TDataEvent)(Idtcpserver::TIdPeerThread* AThread, System::TObject* AData);

class DELPHICLASS TIdNNTPServer;
class PASCALIMPLEMENTATION TIdNNTPServer : public Idtcpserver::TIdTCPServer 
{
	typedef Idtcpserver::TIdTCPServer inherited;
	
protected:
	TOtherEvent fOnCommandAuthInfo;
	TDoByIDEvent fOnCommandArticleID;
	TDoByNoEvent fOnCommandArticleNO;
	TDoByIDEvent fOnCommandBodyID;
	TDoByNoEvent fOnCommandBodyNO;
	TDoByIDEvent fOnCommandHeadID;
	TDoByNoEvent fOnCommandHeadNO;
	TDoByIDEvent fOnCommandStatID;
	TDoByNoEvent fOnCommandStatNO;
	TGroupEvent fOnCommandGroup;
	TNewsEvent fOnCommandList;
	TGetEvent fOnCommandHelp;
	TDoByIDEvent fOnCommandIHave;
	TGetEvent fOnCommandLast;
	TNewsEvent fOnCommandMode;
	TNewsEvent fOnCommandNewGroups;
	TNewsEvent fOnCommandNewNews;
	TGetEvent fOnCommandNext;
	TGetEvent fOnCommandPost;
	TGetEvent fOnCommandQuit;
	TGetEvent fOnCommandSlave;
	TNewsEvent fOnCommandXOver;
	TNewsEvent fOnCommandXHDR;
	TGetEvent fOnCommandDate;
	TNewsEvent fOnCommandListgroup;
	TDoByIDEvent fOnCommandTakeThis;
	TDoByIDEvent fOnCommandCheck;
	TNewsEvent fOnCommandXThread;
	TNewsEvent fOnCommandXGTitle;
	TNewsEvent fOnCommandXPat;
	TOtherEvent fOnCommandOther;
	virtual bool __fastcall DoExecute(Idtcpserver::TIdPeerThread* AThread);
	
public:
	__fastcall virtual TIdNNTPServer(Classes::TComponent* AOwner);
	
__published:
	__property TOtherEvent OnCommandAuthInfo = {read=fOnCommandAuthInfo, write=fOnCommandAuthInfo};
	__property TDoByIDEvent OnCommandArticleID = {read=fOnCommandArticleID, write=fOnCommandArticleID};
	__property TDoByNoEvent OnCommandArticleNo = {read=fOnCommandArticleNO, write=fOnCommandArticleNO};
	__property TDoByIDEvent OnCommandBodyID = {read=fOnCommandBodyID, write=fOnCommandBodyID};
	__property TDoByNoEvent OnCommandBodyNo = {read=fOnCommandBodyNO, write=fOnCommandBodyNO};
	__property TDoByIDEvent OnCommandCheck = {read=fOnCommandCheck, write=fOnCommandCheck};
	__property TDoByIDEvent OnCommandHeadID = {read=fOnCommandHeadID, write=fOnCommandHeadID};
	__property TDoByNoEvent OnCommandHeadNo = {read=fOnCommandHeadNO, write=fOnCommandHeadNO};
	__property TDoByIDEvent OnCommandStatID = {read=fOnCommandStatID, write=fOnCommandStatID};
	__property TDoByNoEvent OnCommandStatNo = {read=fOnCommandStatNO, write=fOnCommandStatNO};
	__property TGroupEvent OnCommandGroup = {read=fOnCommandGroup, write=fOnCommandGroup};
	__property TNewsEvent OnCommandList = {read=fOnCommandList, write=fOnCommandList};
	__property TGetEvent OnCommandHelp = {read=fOnCommandHelp, write=fOnCommandHelp};
	__property TDoByIDEvent OnCommandIHave = {read=fOnCommandIHave, write=fOnCommandIHave};
	__property TGetEvent OnCommandLast = {read=fOnCommandLast, write=fOnCommandLast};
	__property TNewsEvent OnCommandMode = {read=fOnCommandMode, write=fOnCommandMode};
	__property TNewsEvent OnCommandNewGroups = {read=fOnCommandNewGroups, write=fOnCommandNewGroups};
	__property TNewsEvent OnCommandNewNews = {read=fOnCommandNewNews, write=fOnCommandNewNews};
	__property TGetEvent OnCommandNext = {read=fOnCommandNext, write=fOnCommandNext};
	__property TGetEvent OnCommandPost = {read=fOnCommandPost, write=fOnCommandPost};
	__property TGetEvent OnCommandQuit = {read=fOnCommandQuit, write=fOnCommandQuit};
	__property TGetEvent OnCommandSlave = {read=fOnCommandSlave, write=fOnCommandSlave};
	__property TDoByIDEvent OnCommandTakeThis = {read=fOnCommandTakeThis, write=fOnCommandTakeThis};
	__property TNewsEvent OnCommandXOver = {read=fOnCommandXOver, write=fOnCommandXOver};
	__property TNewsEvent OnCommandXHDR = {read=fOnCommandXHDR, write=fOnCommandXHDR};
	__property TGetEvent OnCommandDate = {read=fOnCommandDate, write=fOnCommandDate};
	__property TNewsEvent OnCommandListgroup = {read=fOnCommandListgroup, write=fOnCommandListgroup};
	__property TNewsEvent OnCommandXThread = {read=fOnCommandXThread, write=fOnCommandXThread};
	__property TNewsEvent OnCommandXGTitle = {read=fOnCommandXGTitle, write=fOnCommandXGTitle};
	__property TNewsEvent OnCommandXPat = {read=fOnCommandXPat, write=fOnCommandXPat};
	__property TOtherEvent OnCommandOther = {read=fOnCommandOther, write=fOnCommandOther};
	__property DefaultPort  = {default=119};
public:
	#pragma option push -w-inl
	/* TIdTCPServer.Destroy */ inline __fastcall virtual ~TIdNNTPServer(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE AnsiString KnownCommands[26];

}	/* namespace Idnntpserver */
using namespace Idnntpserver;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdNNTPServer
