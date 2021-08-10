// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Commctrl.pas' rev: 5.00

#ifndef CommctrlHPP
#define CommctrlHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

#include <CommCtrl.h>


namespace Commctrl
{
//-- type declarations -------------------------------------------------------
typedef void *HPropSheetPage;

typedef _PROPSHEETPAGEA *PPropSheetPageA;

typedef _PROPSHEETPAGEW *PPropSheetPageW;

typedef _PROPSHEETPAGEA *PPropSheetPage;

typedef int __stdcall (*TFNPSPCallbackA)(HWND Wnd, int Msg, PPropSheetPageA PPSP);

typedef int __stdcall (*TFNPSPCallbackW)(HWND Wnd, int Msg, PPropSheetPageW PPSP);

typedef int __stdcall (*TFNPSPCallback)(HWND Wnd, int Msg, PPropSheetPageA PPSP);

typedef _PROPSHEETPAGEA  TPropSheetPageA;

typedef _PROPSHEETPAGEW  TPropSheetPageW;

typedef _PROPSHEETPAGEA  TPropSheetPage;

typedef int __stdcall (*TFNPropSheetCallback)(HWND Wnd, int Msg, int LParam);

typedef _PROPSHEETHEADERA *PPropSheetHeaderA;

typedef _PROPSHEETHEADERW *PPropSheetHeaderW;

typedef _PROPSHEETHEADERA *PPropSheetHeader;

typedef _PROPSHEETHEADERA  TPropSheetHeaderA;

typedef _PROPSHEETHEADERW  TPropSheetHeaderW;

typedef _PROPSHEETHEADERA  TPropSheetHeader;

typedef BOOL __stdcall (*TFNAddPropSheetPage)(void * hPSP, int lParam);

typedef BOOL __stdcall (*TFNAddPropSheetPages)(void * lpvoid, LPFNADDPROPSHEETPAGE pfn, int lParam);
	

typedef tagINITCOMMONCONTROLSEX *PInitCommonControlsEx;

typedef tagINITCOMMONCONTROLSEX  TInitCommonControlsEx;

typedef tagCOLORSCHEME *PColorScheme;

typedef tagCOLORSCHEME  TColorScheme;

typedef tagNMMOUSE *PNMMouse;

typedef tagNMMOUSE  TNMMouse;

typedef tagNMMOUSE *PNMClick;

typedef tagNMMOUSE  TNMClick;

typedef tagNMOBJECTNOTIFY *PNMObjectNotify;

typedef tagNMOBJECTNOTIFY  TNMObjectNotify;

typedef tagNMKEY *PNMKey;

typedef tagNMKEY  TNMKey;

typedef tagNMCHAR *PNMChar;

typedef tagNMCHAR  TNMChar;

typedef tagNMCUSTOMDRAWINFO *PNMCustomDraw;

typedef tagNMCUSTOMDRAWINFO  TNMCustomDraw;

typedef tagNMTTCUSTOMDRAW *PNMTTCustomDraw;

typedef tagNMTTCUSTOMDRAW  TNMTTCustomDraw;

typedef _IMAGELISTDRAWPARAMS *PImageListDrawParams;

typedef _IMAGELISTDRAWPARAMS  TImageListDrawParams;

typedef _IMAGEINFO *PImageInfo;

typedef _IMAGEINFO  TImageInfo;

typedef _HD_ITEMA *PHDItemA;

typedef _HD_ITEMW *PHDItemW;

typedef _HD_ITEMA *PHDItem;

typedef _HD_ITEMA  THDItemA;

typedef _HD_ITEMW  THDItemW;

typedef _HD_ITEMA  THDItem;

typedef _HD_LAYOUT *PHDLayout;

typedef _HD_LAYOUT  THDLayout;

typedef _HD_HITTESTINFO *PHDHitTestInfo;

typedef _HD_HITTESTINFO  THDHitTestInfo;

typedef tagNMHEADERA *PHDNotifyA;

typedef tagNMHEADERW *PHDNotifyW;

typedef tagNMHEADERA *PHDNotify;

typedef tagNMHEADERA  THDNotifyA;

typedef tagNMHEADERW  THDNotifyW;

typedef tagNMHEADERA  THDNotify;

typedef tagNMHDDISPINFOA *PNMHDispInfoA;

typedef tagNMHDDISPINFOW *PNMHDispInfoW;

typedef tagNMHDDISPINFOA *PNMHDispInfo;

typedef tagNMHDDISPINFOA  TNMHDispInfoA;

typedef tagNMHDDISPINFOW  TNMHDispInfoW;

typedef tagNMHDDISPINFOA  TNMHDispInfo;

typedef _TBBUTTON *PTBButton;

typedef _TBBUTTON  TTBButton;

typedef _COLORMAP *PColorMap;

typedef _COLORMAP  TColorMap;

typedef _NMTBCUSTOMDRAW *PNMTBCustomDraw;

typedef _NMTBCUSTOMDRAW  TNMTBCustomDraw;

typedef tagTBADDBITMAP *PTBAddBitmap;

typedef tagTBADDBITMAP  TTBAddBitmap;

typedef tagTBSAVEPARAMSA *PTBSaveParamsA;

typedef tagTBSAVEPARAMSW *PTBSaveParamsW;

typedef tagTBSAVEPARAMSA *PTBSaveParams;

typedef tagTBSAVEPARAMSA  TTBSaveParamsA;

typedef tagTBSAVEPARAMSW  TTBSaveParamsW;

typedef tagTBSAVEPARAMSA  TTBSaveParams;

typedef TBINSERTMARK *PTBInsertMark;

typedef TBINSERTMARK  TTBInsertMark;

typedef TBREPLACEBITMAP *PTBReplaceBitmap;

typedef TBREPLACEBITMAP  TTBReplaceBitmap;

typedef TBBUTTONINFOA *PTBButtonInfoA;

typedef TBBUTTONINFOW *PTBButtonInfoW;

typedef TBBUTTONINFOA *PTBButtonInfo;

typedef TBBUTTONINFOA  TTBButtonInfoA;

typedef TBBUTTONINFOW  TTBButtonInfoW;

typedef TBBUTTONINFOA  TTBButtonInfo;

typedef tagNMTBHOTITEM *PNMTBHotItem;

typedef tagNMTBHOTITEM  TNMTBHotItem;

typedef tagNMTBGETINFOTIPA *PNMTBGetInfoTipA;

typedef tagNMTBGETINFOTIPW *PNMTBGetInfoTipW;

typedef tagNMTBGETINFOTIPA *PNMTBGetInfoTip;

typedef tagNMTBGETINFOTIPA  TNMTBGetInfoTipA;

typedef tagNMTBGETINFOTIPW  TNMTBGetInfoTipW;

typedef tagNMTBGETINFOTIPA  TNMTBGetInfoTip;

typedef NMTBDISPINFOA *PNMTBDispInfoA;

typedef NMTBDISPINFOW *PNMTBDispInfoW;

typedef NMTBDISPINFOA *PNMTBDispInfo;

typedef NMTBDISPINFOA  TNMTBDispInfoA;

typedef NMTBDISPINFOW  TNMTBDispInfoW;

typedef NMTBDISPINFOA  TNMTBDispInfo;

typedef tagNMTOOLBARA *PNMToolBarA;

typedef tagNMTOOLBARW *PNMToolBarW;

typedef tagNMTOOLBARA *PNMToolBar;

typedef tagNMTOOLBARA  TNMToolBarA;

typedef tagNMTOOLBARW  TNMToolBarW;

typedef tagNMTOOLBARA  TNMToolBar;

typedef tagREBARINFO *PReBarInfo;

typedef tagREBARINFO  TReBarInfo;

typedef tagREBARBANDINFOA *PReBarBandInfoA;

typedef tagREBARBANDINFOW *PReBarBandInfoW;

typedef tagREBARBANDINFOA *PReBarBandInfo;

typedef tagREBARBANDINFOA  TReBarBandInfoA;

typedef tagREBARBANDINFOW  TReBarBandInfoW;

typedef tagREBARBANDINFOA  TReBarBandInfo;

typedef tagNMREBARCHILDSIZE *PNMReBarChildSize;

typedef tagNMREBARCHILDSIZE  TNMReBarChildSize;

typedef tagNMREBAR *PNMReBar;

typedef tagNMREBAR  TNMReBar;

typedef tagNMRBAUTOSIZE *PNMRBAutoSize;

typedef tagNMRBAUTOSIZE  TNMRBAutoSize;

typedef _RB_HITTESTINFO *PRBHitTestInfo;

typedef _RB_HITTESTINFO  TRBHitTestInfo;

typedef tagTOOLINFOA *PToolInfoA;

typedef tagTOOLINFOW *PToolInfoW;

typedef tagTOOLINFOA *PToolInfo;

typedef tagTOOLINFOA  TToolInfoA;

typedef tagTOOLINFOW  TToolInfoW;

typedef tagTOOLINFOA  TToolInfo;

typedef _TT_HITTESTINFOA *PTTHitTestInfoA;

typedef _TT_HITTESTINFOW *PTTHitTestInfoW;

typedef _TT_HITTESTINFOA *PTTHitTestInfo;

typedef _TT_HITTESTINFOA  TTTHitTestInfoA;

typedef _TT_HITTESTINFOW  TTTHitTestInfoW;

typedef _TT_HITTESTINFOA  TTTHitTestInfo;

#pragma pack(push, 1)
struct tagNMTTDISPINFOA
{
	tagNMHDR hdr;
	char *lpszText;
	char szText[80];
	Windows::HINST hinst;
	unsigned uFlags;
	int lParam;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct tagNMTTDISPINFOW
{
	tagNMHDR hdr;
	wchar_t *lpszText;
	wchar_t szText[80];
	Windows::HINST hinst;
	unsigned uFlags;
	int lParam;
} ;
#pragma pack(pop)

typedef tagNMTTDISPINFOA  tagNMTTDISPINFO;

typedef tagNMTTDISPINFOA *PNMTTDispInfoA;

typedef tagNMTTDISPINFOW *PNMTTDispInfoW;

typedef tagNMTTDISPINFOA *PNMTTDispInfo;

typedef tagNMTTDISPINFOA  TNMTTDispInfoA;

typedef tagNMTTDISPINFOW  TNMTTDispInfoW;

typedef tagNMTTDISPINFOA  TNMTTDispInfo;

typedef tagNMTTDISPINFOA  TToolTipTextA;

typedef tagNMTTDISPINFOW  TToolTipTextW;

typedef tagNMTTDISPINFOA  TToolTipText;

typedef tagNMTTDISPINFOA *PToolTipTextA;

typedef tagNMTTDISPINFOW *PToolTipTextW;

typedef tagNMTTDISPINFOA *PToolTipText;

typedef tagDRAGLISTINFO *PDragListInfo;

typedef tagDRAGLISTINFO  TDragListInfo;

typedef _UDACCEL *PUDAccel;

typedef _UDACCEL  TUDAccel;

typedef _NM_UPDOWN *PNMUpDown;

typedef _NM_UPDOWN  TNMUpDown;

typedef PBRANGE *PPBRange;

typedef PBRANGE  TPBRange;

typedef tagLVITEMA *PLVItemA;

typedef tagLVITEMW *PLVItemW;

typedef tagLVITEMA *PLVItem;

typedef tagLVITEMA  TLVItemA;

typedef tagLVITEMW  TLVItemW;

typedef tagLVITEMA  TLVItem;

typedef tagLVFINDINFOA *PLVFindInfoA;

typedef tagLVFINDINFOW *PLVFindInfoW;

typedef tagLVFINDINFOA *PLVFindInfo;

typedef tagLVFINDINFOA  TLVFindInfoA;

typedef tagLVFINDINFOW  TLVFindInfoW;

typedef tagLVFINDINFOA  TLVFindInfo;

typedef tagLVHITTESTINFO *PLVHitTestInfo;

typedef tagLVHITTESTINFO  TLVHitTestInfo;

typedef tagLVCOLUMNA *PLVColumnA;

typedef tagLVCOLUMNW *PLVColumnW;

typedef tagLVCOLUMNA *PLVColumn;

typedef tagLVCOLUMNA  TLVColumnA;

typedef tagLVCOLUMNW  TLVColumnW;

typedef tagLVCOLUMNA  TLVColumn;

typedef int __stdcall (*TLVCompare)(int lParam1, int lParam2, int lParamSort);

typedef tagLVBKIMAGEA *PLVBKImageA;

typedef tagLVBKIMAGEW *PLVBKImageW;

typedef tagLVBKIMAGEA *PLVBKImage;

typedef tagLVBKIMAGEA  TLVBKImageA;

typedef tagLVBKIMAGEW  TLVBKImageW;

typedef tagLVBKIMAGEA  TLVBKImage;

typedef tagNMLISTVIEW *PNMListView;

typedef tagNMLISTVIEW  TNMListView;

typedef tagNMITEMACTIVATE *PNMItemActivate;

typedef tagNMITEMACTIVATE  TNMItemActivate;

typedef tagNMLVCUSTOMDRAW *PNMLVCustomDraw;

typedef tagNMLVCUSTOMDRAW  TNMLVCustomDraw;

typedef tagNMLVCACHEHINT *PNMLVCacheHint;

typedef tagNMLVCACHEHINT  TNMLVCacheHint;

typedef tagNMLVCACHEHINT *PNMCacheHint;

typedef tagNMLVCACHEHINT  TNMCacheHint;

typedef tagNMLVFINDITEMA *PNMLVFinditem;

typedef tagNMLVFINDITEMA  TNMLVFinditem;

typedef tagNMLVFINDITEMA *PNMFinditem;

typedef tagNMLVFINDITEMA  TNMFinditem;

typedef tagNMLVODSTATECHANGE *PNMLVODStateChange;

typedef tagNMLVODSTATECHANGE  TNMLVODStateChange;

typedef tagLVDISPINFO *PLVDispInfoA;

typedef tagLVDISPINFOW *PLVDispInfoW;

typedef tagLVDISPINFO *PLVDispInfo;

typedef tagLVDISPINFO  TLVDispInfoA;

typedef tagLVDISPINFOW  TLVDispInfoW;

typedef tagLVDISPINFO  TLVDispInfo;

typedef tagLVKEYDOWN *PLVKeyDown;

typedef tagLVKEYDOWN  TLVKeyDown;

typedef tagNMLVGETINFOTIPA *PNMLVGetInfoTipA;

typedef tagNMLVGETINFOTIPW *PNMLVGetInfoTipW;

typedef tagNMLVGETINFOTIPA *PNMLVGetInfoTip;

typedef tagNMLVGETINFOTIPA  TNMLVGetInfoTipA;

typedef tagNMLVGETINFOTIPW  TNMLVGetInfoTipW;

typedef tagNMLVGETINFOTIPA  TNMLVGetInfoTip;

typedef tagTVITEMA *PTVItemA;

typedef tagTVITEMW *PTVItemW;

typedef tagTVITEMA *PTVItem;

typedef tagTVITEMA  TTVItemA;

typedef tagTVITEMW  TTVItemW;

typedef tagTVITEMA  TTVItem;

typedef tagTVITEMEXA *PTVItemExA;

typedef tagTVITEMEXW *PTVItemExW;

typedef tagTVITEMEXA *PTVItemEx;

typedef tagTVITEMEXA  TTVItemExA;

typedef tagTVITEMEXW  TTVItemExW;

typedef tagTVITEMEXA  TTVItemEx;

typedef tagTVINSERTSTRUCTA *PTVInsertStructA;

typedef tagTVINSERTSTRUCTW *PTVInsertStructW;

typedef tagTVINSERTSTRUCTA *PTVInsertStruct;

typedef tagTVINSERTSTRUCTA  TTVInsertStructA;

typedef tagTVINSERTSTRUCTW  TTVInsertStructW;

typedef tagTVINSERTSTRUCTA  TTVInsertStruct;

typedef tagTVHITTESTINFO *PTVHitTestInfo;

typedef tagTVHITTESTINFO  TTVHitTestInfo;

typedef int __stdcall (*TTVCompare)(int lParam1, int lParam2, int lParamSort);

typedef tagTVSORTCB  TTVSortCB;

typedef tagNMTREEVIEWA *PNMTreeViewA;

typedef tagNMTREEVIEWW *PNMTreeViewW;

typedef tagNMTREEVIEWA *PNMTreeView;

typedef tagNMTREEVIEWA  TNMTreeViewA;

typedef tagNMTREEVIEWW  TNMTreeViewW;

typedef tagNMTREEVIEWA  TNMTreeView;

typedef tagTVDISPINFOA *PTVDispInfoA;

typedef tagTVDISPINFOW *PTVDispInfoW;

typedef tagTVDISPINFOA *PTVDispInfo;

typedef tagTVDISPINFOA  TTVDispInfoA;

typedef tagTVDISPINFOW  TTVDispInfoW;

typedef tagTVDISPINFOA  TTVDispInfo;

typedef tagTVKEYDOWN  TTVKeyDown;

typedef tagNMTVCUSTOMDRAW *PNMTVCustomDraw;

typedef tagNMTVCUSTOMDRAW  TNMTVCustomDraw;

typedef tagNMTVGETINFOTIPA *PNMTVGetInfoTipA;

typedef tagNMTVGETINFOTIPW *PNMTVGetInfoTipW;

typedef tagNMTVGETINFOTIPA *PNMTVGetInfoTip;

typedef tagNMTVGETINFOTIPA  TNMTVGetInfoTipA;

typedef tagNMTVGETINFOTIPW  TNMTVGetInfoTipW;

typedef tagNMTVGETINFOTIPA  TNMTVGetInfoTip;

typedef tagCOMBOBOXEXITEMA *PComboBoxExItemA;

typedef tagCOMBOBOXEXITEMW *PComboBoxExItemW;

typedef tagCOMBOBOXEXITEMA *PComboBoxExItem;

typedef tagCOMBOBOXEXITEMA  TComboBoxExItemA;

typedef tagCOMBOBOXEXITEMW  TComboBoxExItemW;

typedef tagCOMBOBOXEXITEMA  TComboBoxExItem;

typedef NMCOMBOBOXEXA *PNMComboBoxExA;

typedef NMCOMBOBOXEXW *PNMComboBoxExW;

typedef NMCOMBOBOXEXA *PNMComboBoxEx;

typedef NMCOMBOBOXEXA  TNMComboBoxExA;

typedef NMCOMBOBOXEXW  TNMComboBoxExW;

typedef NMCOMBOBOXEXA  TNMComboBoxEx;

typedef NMCBEDRAGBEGINA *PNMCBEDragBeginA;

typedef NMCBEDRAGBEGINW *PNMCBEDragBeginW;

typedef NMCBEDRAGBEGINA *PNMCBEDragBegin;

typedef NMCBEDRAGBEGINA  TNMCBEDragBeginA;

typedef NMCBEDRAGBEGINW  TNMCBEDragBeginW;

typedef NMCBEDRAGBEGINA  TNMCBEDragBegin;

typedef NMCBEENDEDITA *PNMCBEEndEditA;

typedef NMCBEENDEDITW *PNMCBEEndEditW;

typedef NMCBEENDEDITA *PNMCBEEndEdit;

typedef NMCBEENDEDITA  TNMCBEEndEditA;

typedef NMCBEENDEDITW  TNMCBEEndEditW;

typedef NMCBEENDEDITA  TNMCBEEndEdit;

typedef tagTCITEMHEADERA *PTCItemHeaderA;

typedef tagTCITEMHEADERW *PTCItemHeaderW;

typedef tagTCITEMHEADERA *PTCItemHeader;

typedef tagTCITEMHEADERA  TTCItemHeaderA;

typedef tagTCITEMHEADERW  TTCItemHeaderW;

typedef tagTCITEMHEADERA  TTCItemHeader;

typedef tagTCITEMA *PTCItemA;

typedef tagTCITEMW *PTCItemW;

typedef tagTCITEMA *PTCItem;

typedef tagTCITEMA  TTCItemA;

typedef tagTCITEMW  TTCItemW;

typedef tagTCITEMA  TTCItem;

typedef tagTCHITTESTINFO *PTCHitTestInfo;

typedef tagTCHITTESTINFO  TTCHitTestInfo;

typedef tagTCKEYDOWN  TTCKeyDown;

typedef unsigned *PMonthDayState;

typedef unsigned TMonthDayState;

typedef MCHITTESTINFO *PMCHitTestInfo;

typedef MCHITTESTINFO  TMCHitTestInfo;

typedef tagNMSELCHANGE *PNMSelChange;

typedef tagNMSELCHANGE  TNMSelChange;

typedef tagNMDAYSTATE *PNMDayState;

typedef tagNMDAYSTATE  TNMDayState;

typedef tagNMSELCHANGE *PNMSelect;

typedef tagNMSELCHANGE  TNMSelect;

typedef tagNMDATETIMECHANGE *PNMDateTimeChange;

typedef tagNMDATETIMECHANGE  TNMDateTimeChange;

typedef tagNMDATETIMESTRINGA *PNMDateTimeStringA;

typedef tagNMDATETIMESTRINGW *PNMDateTimeStringW;

typedef tagNMDATETIMESTRINGA *PNMDateTimeString;

typedef tagNMDATETIMESTRINGA  TNMDateTimeStringA;

typedef tagNMDATETIMESTRINGW  TNMDateTimeStringW;

typedef tagNMDATETIMESTRINGA  TNMDateTimeString;

typedef tagNMDATETIMEWMKEYDOWNA *PNMDateTimeWMKeyDownA;

typedef tagNMDATETIMEWMKEYDOWNW *PNMDateTimeWMKeyDownW;

typedef tagNMDATETIMEWMKEYDOWNA *PNMDateTimeWMKeyDown;

typedef tagNMDATETIMEWMKEYDOWNA  TNMDateTimeWMKeyDownA;

typedef tagNMDATETIMEWMKEYDOWNW  TNMDateTimeWMKeyDownW;

typedef tagNMDATETIMEWMKEYDOWNA  TNMDateTimeWMKeyDown;

typedef tagNMDATETIMEFORMATA *PNMDateTimeFormatA;

typedef tagNMDATETIMEFORMATW *PNMDateTimeFormatW;

typedef tagNMDATETIMEFORMATA *PNMDateTimeFormat;

typedef tagNMDATETIMEFORMATA  TNMDateTimeFormatA;

typedef tagNMDATETIMEFORMATW  TNMDateTimeFormatW;

typedef tagNMDATETIMEFORMATA  TNMDateTimeFormat;

typedef tagNMDATETIMEFORMATQUERYA *PNMDateTimeFormatQueryA;

typedef tagNMDATETIMEFORMATQUERYW *PNMDateTimeFormatQueryW;

typedef tagNMDATETIMEFORMATQUERYA *PNMDateTimeFormatQuery;

typedef tagNMDATETIMEFORMATQUERYA  TNMDateTimeFormatQueryA;

typedef tagNMDATETIMEFORMATQUERYW  TNMDateTimeFormatQueryW;

typedef tagNMDATETIMEFORMATQUERYA  TNMDateTimeFormatQuery;

typedef tagNMIPADDRESS *PNMIPAddress;

typedef tagNMIPADDRESS  TNMIPAddress;

typedef NMPGSCROLL *PNMPGScroll;

typedef NMPGSCROLL  TNMPGScroll;

typedef NMPGCALCSIZE *PNMPGCalcSize;

typedef NMPGCALCSIZE  TNMPGCalcSize;

typedef tagTRACKMOUSEEVENT *PTrackMouseEvent;

typedef tagTRACKMOUSEEVENT  TTrackMouseEvent;

//-- var, const, procedure ---------------------------------------------------
static const Shortint PSH_MULTILINETABS = 0x10;
static const Word RB_GETBANDINFO_PRE_IE4 = 0x405;
#define HOTKEYCLASS "msctls_hotkey32"
static const Shortint LVA_ALIGNRIGHT = 0x3;
static const Shortint LVA_ALIGNBOTTOM = 0x4;
static const Word LVA_SORTASCENDING = 0x100;
static const Word LVA_SORTDESCENDING = 0x200;
static const Shortint MCS_NOTODAY_PRE_IE4 = 0x8;

}	/* namespace Commctrl */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Commctrl;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Commctrl
