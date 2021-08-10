// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'OleCtl.pas' rev: 6.00

#ifndef OleCtlHPP
#define OleCtlHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Ole2.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

#include <ocidl.h>
#include <olectl.h>


namespace Olectl
{
//-- type declarations -------------------------------------------------------
typedef tagTEXTMETRICW *PTextMetricOle;

typedef tagTEXTMETRICW  TTextMetricOle;

typedef int TOleColor;

#pragma option push -b-
enum OLE_TRISTATE { triUnchecked, triChecked, triGray };
#pragma option pop

typedef HRESULT __stdcall (*TDLLRegisterServer)(void);

typedef HRESULT __stdcall (*TDLLUnregisterServer)(void);

typedef tagPOINTFX *PPointF;

typedef tagPOINTFX  TPointF;

typedef tagCONTROLINFO *PControlInfo;

typedef tagCONTROLINFO  TControlInfo;

typedef tagCONNECTDATA *PConnectData;

typedef tagCONNECTDATA  TConnectData;

typedef tagLICINFO *PLicInfo;

typedef tagLICINFO  TLicInfo;

typedef GUID TGUIDList[65536];

typedef GUID *PGUIDList;

#pragma pack(push, 4)
struct TCAGUID
{
	int cElems;
	GUID *pElems;
} ;
#pragma pack(pop)

typedef TCAGUID *PCAGUID;

struct TCAPOleStr;
typedef TCAPOleStr *PCAPOleStr;

#pragma pack(push, 4)
struct TCAPOleStr
{
	int cElems;
	wchar_t * *pElems;
} ;
#pragma pack(pop)

typedef int TLongintList[65536];

typedef int *PLongintList;

#pragma pack(push, 4)
struct TCALongint
{
	int cElems;
	int *pElems;
} ;
#pragma pack(pop)

typedef TCALongint *PCALongint;

typedef tagOCPFIPARAMS *POCPFIParams;

typedef tagOCPFIPARAMS  TOCPFIParams;

typedef tagPROPPAGEINFO *PPropPageInfo;

typedef tagPROPPAGEINFO  TPropPageInfo;

typedef tagFONTDESC *PFontDesc;

typedef tagFONTDESC  TFontDesc;

typedef tagPICTDESC *PPictDesc;

typedef tagPICTDESC  TPictDesc;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE GUID CLSID_CFontPropPage;
extern PACKAGE GUID CLSID_CColorPropPage;
extern PACKAGE GUID CLSID_CPicturePropPage;
extern PACKAGE GUID CLSID_PersistPropset;
extern PACKAGE GUID CLSID_ConvertVBX;
extern PACKAGE GUID CLSID_StdFont;
extern PACKAGE GUID CLSID_StdPicture;

}	/* namespace Olectl */
using namespace Olectl;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// OleCtl
