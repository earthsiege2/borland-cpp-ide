// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'OleDlg.pas' rev: 6.00

#ifndef OleDlgHPP
#define OleDlgHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ActiveX.hpp>	// Pascal unit
#include <CommCtrl.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

#include <oledlg.h>


namespace Oledlg
{
//-- type declarations -------------------------------------------------------
typedef int __stdcall (*TFNOleUIHook)(HWND Wnd, int Msg, int WParam, int LParam);

typedef tagOLEUIINSERTOBJECTA *POleUIInsertObject;

typedef tagOLEUIINSERTOBJECTA  TOleUIInsertObject;

typedef tagOLEUIPASTEENTRYA *POleUIPasteEntry;

typedef tagOLEUIPASTEENTRYA  TOleUIPasteEntry;

typedef tagOLEUIPASTESPECIALA *POleUIPasteSpecial;

typedef tagOLEUIPASTESPECIALA  TOleUIPasteSpecial;

typedef tagOLEUIEDITLINKSA *POleUIEditLinks;

typedef tagOLEUIEDITLINKSA  TOleUIEditLinks;

typedef tagOLEUICHANGEICONA *POleUIChangeIcon;

typedef tagOLEUICHANGEICONA  TOleUIChangeIcon;

typedef tagOLEUICONVERTA *POleUIConvert;

typedef tagOLEUICONVERTA  TOleUIConvert;

typedef tagOLEUIBUSYA *POleUIBusy;

typedef tagOLEUIBUSYA  TOleUIBusy;

typedef tagOLEUIGNRLPROPSA *POleUIGnrlProps;

typedef tagOLEUIGNRLPROPSA  TOleUIGnrlProps;

typedef tagOLEUIVIEWPROPSA *POleUIViewProps;

typedef tagOLEUIVIEWPROPSA  TOleUIViewProps;

typedef tagOLEUILINKPROPSA *POleUILinkProps;

typedef tagOLEUILINKPROPSA  TOleUILinkProps;

typedef tagOLEUIOBJECTPROPSA *POleUIObjectProps;

typedef tagOLEUIOBJECTPROPSA  TOleUIObjectProps;

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Oledlg */
using namespace Oledlg;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// OleDlg
