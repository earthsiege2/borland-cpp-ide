// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Mapi.pas' rev: 6.00

#ifndef MapiHPP
#define MapiHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <mapi.h>

namespace Mapi
{
//-- type declarations -------------------------------------------------------
typedef unsigned *PLHANDLE;

typedef MapiFileDesc *PMapiFileDesc;

typedef MapiFileDesc  TMapiFileDesc;

typedef MapiFileTagExt *PMapiFileTagExt;

typedef MapiFileTagExt  TMapiFileTagExt;

typedef MapiRecipDesc *PMapiRecipDesc;

typedef MapiRecipDesc  TMapiRecipDesc;

typedef MapiMessage *PMapiMessage;

typedef MapiMessage  TMapiMessage;

typedef unsigned __stdcall (*TFNMapiLogOn)(unsigned ulUIParam, char * lpszProfileName, char * lpszPassword, unsigned flFlags, unsigned ulReserved, PLHANDLE lplhSession);

typedef TFNMapiLogOn *PFNMapiLogon;

typedef unsigned __stdcall (*TFNMapiLogOff)(unsigned lhSession, unsigned ulUIParam, unsigned flFlags, unsigned ulReserved);

typedef TFNMapiLogOff *PFNMapiLogOff;

typedef unsigned __stdcall (*TFNMapiSendMail)(unsigned lhSession, unsigned ulUIParam, MapiMessage &lpMessage, unsigned flFlags, unsigned ulReserved);

typedef TFNMapiSendMail *PFNMapiSendMail;

typedef unsigned __stdcall (*TFNMapiSendDocuments)(unsigned ulUIParam, char * lpszDelimChar, char * lpszFilePaths, char * lpszFileNames, unsigned ulReserved);

typedef TFNMapiSendDocuments *PFNMapiSendDocuments;

typedef unsigned __stdcall (*TFNMapiFindNext)(unsigned lhSession, unsigned ulUIParam, char * lpszMessageType, char * lpszSeedMessageID, unsigned flFlags, unsigned ulReserved, char * lpszMessageID);

typedef TFNMapiFindNext *PFNMapiFindNext;

typedef unsigned __stdcall (*TFNMapiReadMail)(unsigned lhSession, unsigned ulUIParam, char * lpszMessageID, unsigned flFlags, unsigned ulReserved, PMapiMessage &lppMessage);

typedef TFNMapiReadMail *PFNMapiReadMail;

typedef unsigned __stdcall (*TFNMapiSaveMail)(unsigned lhSession, unsigned ulUIParam, MapiMessage &lpMessage, unsigned flFlags, unsigned ulReserved, char * lpszMessageID);

typedef TFNMapiSaveMail *PFNMapiSaveMail;

typedef unsigned __stdcall (*TFNMapiDeleteMail)(unsigned lhSession, unsigned ulUIParam, char * lpszMessageID, unsigned flFlags, unsigned ulReserved);

typedef TFNMapiDeleteMail *PFNMapiDeleteMail;

typedef unsigned __stdcall (*TFNMapiFreeBuffer)(void * pv);

typedef TFNMapiFreeBuffer *PFNMapiFreeBuffer;

typedef unsigned __stdcall (*TFNMapiAddress)(unsigned lhSession, unsigned ulUIParam, char * lpszCaption, unsigned nEditFields, char * lpszLabels, unsigned nRecips, MapiRecipDesc &lpRecips, unsigned flFlags, unsigned ulReserved, PULONG lpnNewRecips, PMapiRecipDesc &lppNewRecips);

typedef TFNMapiAddress *PFNMapiAddress;

typedef unsigned __stdcall (*TFNMapiDetails)(unsigned lhSession, unsigned ulUIParam, MapiRecipDesc &lpRecip, unsigned flFlags, unsigned ulReserved);

typedef TFNMapiDetails *PFNMapiDetails;

typedef unsigned __stdcall (*TFNMapiResolveName)(unsigned lhSession, unsigned ulUIParam, char * lpszName, unsigned flFlags, unsigned ulReserved, PMapiRecipDesc &lppRecip);

typedef TFNMapiResolveName *PFNMapiResolveName;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE AnsiString MAPIDLL;
extern PACKAGE unsigned __fastcall MapiLogOn(unsigned ulUIParam, char * lpszProfileName, char * lpszPassword, unsigned flFlags, unsigned ulReserved, PLHANDLE lplhSession);
extern PACKAGE unsigned __fastcall MapiLogOff(unsigned lhSession, unsigned ulUIParam, unsigned flFlags, unsigned ulReserved);
extern PACKAGE unsigned __fastcall MapiSendMail(unsigned lhSession, unsigned ulUIParam, MapiMessage &lpMessage, unsigned flFlags, unsigned ulReserved);
extern PACKAGE unsigned __fastcall MapiSendDocuments(unsigned ulUIParam, char * lpszDelimChar, char * lpszFilePaths, char * lpszFileNames, unsigned ulReserved);
extern PACKAGE unsigned __fastcall MapiFindNext(unsigned lhSession, unsigned ulUIParam, char * lpszMessageType, char * lpszSeedMessageID, unsigned flFlags, unsigned ulReserved, char * lpszMessageID);
extern PACKAGE unsigned __fastcall MapiReadMail(unsigned lhSession, unsigned ulUIParam, char * lpszMessageID, unsigned flFlags, unsigned ulReserved, PMapiMessage &lppMessage);
extern PACKAGE unsigned __fastcall MapiSaveMail(unsigned lhSession, unsigned ulUIParam, MapiMessage &lpMessage, unsigned flFlags, unsigned ulReserved, char * lpszMessageID);
extern PACKAGE unsigned __fastcall MapiDeleteMail(unsigned lhSession, unsigned ulUIParam, char * lpszMessageID, unsigned flFlags, unsigned ulReserved);
extern PACKAGE unsigned __fastcall MapiFreeBuffer(void * pv);
extern PACKAGE unsigned __fastcall MapiAddress(unsigned lhSession, unsigned ulUIParam, char * lpszCaption, unsigned nEditFields, char * lpszLabels, unsigned nRecips, MapiRecipDesc &lpRecips, unsigned flFlags, unsigned ulReserved, PULONG lpnNewRecips, PMapiRecipDesc &lppNewRecips);
extern PACKAGE unsigned __fastcall MapiDetails(unsigned lhSession, unsigned ulUIParam, MapiRecipDesc &lpRecip, unsigned flFlags, unsigned ulReserved);
extern PACKAGE unsigned __fastcall MapiResolveName(unsigned lhSession, unsigned ulUIParam, char * lpszName, unsigned flFlags, unsigned ulReserved, PMapiRecipDesc &lppRecip);

}	/* namespace Mapi */
using namespace Mapi;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Mapi
