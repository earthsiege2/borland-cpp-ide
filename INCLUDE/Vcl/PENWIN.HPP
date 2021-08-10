// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'PenWin.pas' rev: 5.00

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

typedef tagOEMPENPACKET *POEMPenPacket;

typedef tagOEMPENPACKET  TOEMPenPacket;

typedef tagPENINFO *PPenInfo;

typedef tagPENINFO  TPenInfo;

typedef tagCALBSTRUCT *PCalbStruct;

typedef tagCALBSTRUCT  TCalbStruct;

typedef BOOL __stdcall (*TFNRawHook)(PPenPacket PenPacket);

typedef int *PHRC;

typedef int *PHRCRESULT;

typedef int *PHWL;

typedef BOOL __stdcall (*TFNHRCResultHookProc)(int p1, int p2, unsigned p3, unsigned p4, unsigned p5
	, void * p6);

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

typedef tagSYC *PSYC;

typedef tagSYC  TSYC;

typedef tagSYE *PSYE;

typedef tagSYE  TSYE;

typedef tagSYG *PSYG;

typedef tagSYG  TSYG;

typedef tagRC *PRC;

typedef tagRC  TRC;

typedef tagRCRESULT *PRCResult;

typedef tagRCRESULT  TRCResult;

typedef int __stdcall (*TFNFuncResults)(PRCResult p1, int p2);

typedef tagTARGET *PTarget;

typedef tagTARGET  TTarget;

typedef tagTARGINFO *PTargInfo;

typedef tagTARGINFO  TTargInfo;

typedef tagINPPARAMS *PInpParams;

typedef tagINPPARAMS  TInpParams;

typedef tagSKBINFO *PSKBInfo;

typedef tagSKBINFO  TSKBInfo;

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Penwin */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Penwin;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// PenWin
