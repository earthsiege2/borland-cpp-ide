// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ScktCnst.pas' rev: 6.00

#ifndef ScktCnstHPP
#define ScktCnstHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Scktcnst
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
#define KEY_SOCKETSERVER "\\SOFTWARE\\Borland\\Socket Server"
#define KEY_IE "SOFTWARE\\Microsoft\\Internet Explorer"
#define csSettings "Settings"
#define ckPort "Port"
#define ckThreadCacheSize "ThreadCacheSize"
#define ckInterceptGUID "InterceptGUID"
#define ckShowHost "ShowHost"
#define ckTimeout "Timeout"
#define ckRegistered "RegisteredOnly"
#define SServiceName "SocketServer"
#define SApplicationName "Borland Socket Server"
extern PACKAGE System::ResourceString _SServiceOnly;
#define Scktcnst_SServiceOnly System::LoadResourceString(&Scktcnst::_SServiceOnly)
extern PACKAGE System::ResourceString _SErrClose;
#define Scktcnst_SErrClose System::LoadResourceString(&Scktcnst::_SErrClose)
extern PACKAGE System::ResourceString _SErrChangeSettings;
#define Scktcnst_SErrChangeSettings System::LoadResourceString(&Scktcnst::_SErrChangeSettings)
extern PACKAGE System::ResourceString _SQueryDisconnect;
#define Scktcnst_SQueryDisconnect System::LoadResourceString(&Scktcnst::_SQueryDisconnect)
extern PACKAGE System::ResourceString _SOpenError;
#define Scktcnst_SOpenError System::LoadResourceString(&Scktcnst::_SOpenError)
extern PACKAGE System::ResourceString _SHostUnknown;
#define Scktcnst_SHostUnknown System::LoadResourceString(&Scktcnst::_SHostUnknown)
extern PACKAGE System::ResourceString _SNotShown;
#define Scktcnst_SNotShown System::LoadResourceString(&Scktcnst::_SNotShown)
extern PACKAGE System::ResourceString _SNoWinSock2;
#define Scktcnst_SNoWinSock2 System::LoadResourceString(&Scktcnst::_SNoWinSock2)
extern PACKAGE System::ResourceString _SStatusline;
#define Scktcnst_SStatusline System::LoadResourceString(&Scktcnst::_SStatusline)
extern PACKAGE System::ResourceString _SAlreadyRunning;
#define Scktcnst_SAlreadyRunning System::LoadResourceString(&Scktcnst::_SAlreadyRunning)
extern PACKAGE System::ResourceString _SNotUntilRestart;
#define Scktcnst_SNotUntilRestart System::LoadResourceString(&Scktcnst::_SNotUntilRestart)

}	/* namespace Scktcnst */
using namespace Scktcnst;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ScktCnst
