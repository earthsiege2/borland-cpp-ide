// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'PenWin.pas' rev: 6.00

#ifndef PenWinHPP
#define PenWinHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <MMSystem.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include "penwin.h"

namespace Penwin
{
//-- type declarations -------------------------------------------------------
typedef int *PALC;

typedef void *POEM;

typedef int *PSYV;

typedef int *PHPENDATA;

typedef int __stdcall (*TFNEnumProc)(PSYV p1, int p2, int p3);

typedef LPDF *PFNLPDF;

typedef int __stdcall (*TFNLPDF)(int p1, void * p2, void * p3, int p4, unsigned p5, unsigned p6);

typedef BOOL __stdcall (*TFNRCYieldProc)(void);

typedef tagABSTIME *PAbsTime;

typedef tagABSTIME  TAbsTime;

typedef tagCTLINITHEDIT *PCtlInitHEdit;

typedef tagCTLINITHEDIT  TCtlInitHEdit;

typedef tagBOXLAYOUT *PBoxLayout;

typedef tagBOXLAYOUT  TBoxLayout;

typedef tagIMECOLORS *PIMEColors;

typedef tagIMECOLORS  TIMEColors;

typedef tagCTLINITBEDIT *PCtlInitBEdit;

typedef tagCTLINITBEDIT  TCtlInitBEdit;

typedef tagBOXEDITINFO *PBoxEditInfo;

typedef tagBOXEDITINFO  TBoxEditInfo;

typedef tagRECTOFS *PRectOfs;

typedef tagRECTOFS  TRectOfs;

typedef tagPENDATAHEADER *PPenDataHeader;

typedef tagPENDATAHEADER  TPenDataHeader;

typedef tagSTROKEINFO *PStrokeInfo;

typedef tagSTROKEINFO  TStrokeInfo;

typedef tagPENTIP *PPenTip;

typedef tagPENTIP  TPenTip;

typedef BOOL __stdcall (*TFNAnimateProc)(int p1, unsigned p2, unsigned p3, PUINT p4, int p5);

typedef tagANIMATEINFO *PAnimateInfo;

typedef tagANIMATEINFO  TAnimateInfo;

typedef tagOEMPENINFO *POEMPenInfo;

typedef tagOEMPENINFO  TOEMPenInfo;

typedef tagPENPACKET *PPenPacket;

typedef tagPENPACKET  TPenPacket;

struct tagOEMPENPACKET;
typedef tagOEMPENPACKET *POEMPenPacket;

#pragma pack(push, 1)
struct tagOEMPENPACKET
{
	unsigned wTabletX;
	unsigned wTabletY;
	unsigned wPDK;
	unsigned rgwOemData[6];
	unsigned dwTime;
} ;
#pragma pack(pop)

typedef tagOEMPENPACKET  TOEMPenPacket;

typedef tagPENINFO *PPenInfo;

typedef tagPENINFO  TPenInfo;

typedef tagCALBSTRUCT *PCalbStruct;

typedef tagCALBSTRUCT  TCalbStruct;

typedef BOOL __stdcall (*TFNRawHook)(PPenPacket PenPacket);

typedef int *PHRC;

typedef int *PHRCRESULT;

typedef int *PHWL;

typedef BOOL __stdcall (*TFNHRCResultHookProc)(int p1, int p2, unsigned p3, unsigned p4, unsigned p5, void * p6);

typedef tagINTERVAL *PInterval;

typedef tagINTERVAL  TInterval;

typedef tagBOXRESULTS *PBoxResults;

typedef tagBOXRESULTS  TBoxResults;

typedef tagGUIDE *PGuide;

typedef tagGUIDE  TGuide;

typedef tagCTLINITIEDIT *PCtlInitIEdit;

typedef tagCTLINITIEDIT  TCtlInitIEdit;

typedef tagPDEVENT *PPDEvent;

typedef tagPDEVENT  TPDEvent;

typedef tagSTRKFMT *PStrkFmt;

typedef tagSTRKFMT  TStrkFmt;

typedef tagPCMINFO *PPCMInfo;

typedef tagPCMINFO  TPCMInfo;

typedef tagINKINGINFO *PInkingInfo;

typedef tagINKINGINFO  TInkingInfo;

#pragma pack(push, 1)
struct tagSYE
{
	int syv;
	int lRecogVal;
	int cl;
	int iSyc;
} ;
#pragma pack(pop)

typedef tagSYE  TSYE;

struct tagRC;
typedef tagRC *PRC;

#pragma pack(push, 1)
struct tagRC
{
	int hrec;
	HWND hwnd;
	unsigned wEventRef;
	unsigned wRcPreferences;
	int lRcOptions;
	RCYIELDPROC lpfnYield;
	Byte lpUser[32];
	unsigned wCountry;
	unsigned wIntlPreferences;
	char lpLanguage[44];
	LPDF *rglpdf[16];
	unsigned wTryDictionary;
	int clErrorLevel;
	int alc;
	int alcPriority;
	Byte rgbfAlc[32];
	unsigned wResultMode;
	unsigned wTimeOut;
	int lPcm;
	Types::TRect rectBound;
	Types::TRect rectExclude;
	tagGUIDE guide;
	unsigned wRcOrient;
	unsigned wRcDirect;
	int nInkWidth;
	unsigned rgbInk;
	unsigned dwAppParam;
	unsigned dwDictParam;
	unsigned dwRecognizer;
	unsigned rgwReserved[8];
} ;
#pragma pack(pop)

typedef tagRC  TRC;

typedef tagTARGET *PTarget;

typedef tagTARGET  TTarget;

typedef tagTARGINFO *PTargInfo;

typedef tagTARGINFO  TTargInfo;

typedef tagINPPARAMS *PInpParams;

typedef tagINPPARAMS  TInpParams;

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Penwin */
using namespace Penwin;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// PenWin
