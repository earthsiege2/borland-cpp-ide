// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ShlObj.pas' rev: 5.00

#ifndef ShlObjHPP
#define ShlObjHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <UrlMon.hpp>	// Pascal unit
#include <WinInet.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <RegStr.hpp>	// Pascal unit
#include <ShellAPI.hpp>	// Pascal unit
#include <Commctrl.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
//---------------------------------------------------------------------------
// if compilation errors occur while attempting to access structs, unions, or enums
// define NO_WIN32_LEAN_AND_MEAN so that the appropriate windows headers are included.
//---------------------------------------------------------------------------
#if defined(NO_WIN32_LEAN_AND_MEAN)
#include <ole2.h>
#include <prsht.h>
#include <commctrl.h>   // for LPTBBUTTON
#include <shlguid.h>
#include <shlobj.h>
#endif
DECLARE_DINTERFACE_TYPE(IAdviseSink);
DECLARE_DINTERFACE_TYPE(IShellBrowser);
DECLARE_DINTERFACE_TYPE(IShellView);
DECLARE_DINTERFACE_TYPE(IContextMenu);
DECLARE_DINTERFACE_TYPE(IShellIcon);
DECLARE_DINTERFACE_TYPE(IShellFolder);
DECLARE_DINTERFACE_TYPE(IShellFolder2);
DECLARE_DINTERFACE_TYPE(IShellDetails);
DECLARE_DINTERFACE_TYPE(IShellExtInit);
DECLARE_DINTERFACE_TYPE(IShellPropSheetExt);
DECLARE_DINTERFACE_TYPE(IPersistFolder);
DECLARE_DINTERFACE_TYPE(ICommDlgBrowser);
DECLARE_DINTERFACE_TYPE(IEnumIDList);
DECLARE_DINTERFACE_TYPE(IFileViewerSite);
DECLARE_DINTERFACE_TYPE(IContextMenu2);
DECLARE_DINTERFACE_TYPE(IShellView2);
DECLARE_DINTERFACE_TYPE(INewShortcutHookA);
DECLARE_DINTERFACE_TYPE(INewShortcutHookW);
DECLARE_DINTERFACE_TYPE(IFileViewerA);
DECLARE_DINTERFACE_TYPE(IFileViewerW);
DECLARE_DINTERFACE_TYPE(IShellLinkA);
DECLARE_DINTERFACE_TYPE(IShellLinkW);
DECLARE_DINTERFACE_TYPE(IExtractIconA);
DECLARE_DINTERFACE_TYPE(IExtractIconW);
DECLARE_DINTERFACE_TYPE(IShellExecuteHookA);
DECLARE_DINTERFACE_TYPE(IShellExecuteHookW);
DECLARE_DINTERFACE_TYPE(ICopyHookA);
DECLARE_DINTERFACE_TYPE(ICopyHookW);
#ifdef UNICODE
typedef _di_INewShortcutHookW _di_INewShortcutHook;
typedef _di_IFileViewerW _di_IFileViewer;
typedef _di_IShellLinkW _di_IShellLink;
typedef _di_IExtractIconW _di_IExtractIcon;
typedef _di_IShellExecuteHookW _di_IShellExecuteHook;
typedef _di_ICopyHookW _di_ICopyHook;
#else
typedef _di_INewShortcutHookA _di_INewShortcutHook;
typedef _di_IFileViewerA _di_IFileViewer;
typedef _di_IShellLinkA _di_IShellLink;
typedef _di_IExtractIconA _di_IExtractIcon;
typedef _di_IShellExecuteHookA _di_IShellExecuteHook;
typedef _di_ICopyHookA _di_ICopyHook;
#endif
#if !defined(NO_WIN32_LEAN_AND_MEAN)
struct _SHITEMID;
struct _ITEMIDLIST;
struct _CMINVOKECOMMANDINFO;
struct _CMInvokeCommandInfoEx;
struct FVSHOWINFO;
struct FOLDERSETTINGS;
struct _SV2CVW2_PARAMS;
struct _STRRET;
struct _SHELLDETAILS;
struct DESKBANDINFO;
struct _NRESARRAY;
struct _IDA;
struct _FILEDESCRIPTORA;
struct _FILEDESCRIPTORW;
struct _FILEGROUPDESCRIPTORW;
struct _FILEGROUPDESCRIPTORA;
struct _DROPFILES;
struct _SHDESCRIPTIONID;
struct SHELLFLAGSTATE;
struct _browseinfoA;
struct _browseinfoW;
#endif

namespace Shlobj
{
//-- type declarations -------------------------------------------------------
typedef _SHITEMID *PSHItemID;

typedef _SHITEMID  TSHItemID;

typedef _ITEMIDLIST *PItemIDList;

typedef _ITEMIDLIST  TItemIDList;

typedef _CMINVOKECOMMANDINFO *PCMInvokeCommandInfo;

typedef _CMINVOKECOMMANDINFO  TCMInvokeCommandInfo;

typedef _CMInvokeCommandInfoEx *PCMInvokeCommandInfoEx;

typedef _CMInvokeCommandInfoEx  TCMInvokeCommandInfoEx;

typedef FVSHOWINFO *PFVShowInfo;

typedef FVSHOWINFO  TFVShowInfo;

typedef FOLDERSETTINGS *PFolderSettings;

typedef FOLDERSETTINGS  TFolderSettings;

typedef GUID  TShellViewID;

typedef GUID *PShellViewID;

typedef _SV2CVW2_PARAMS *PSV2CreateParams;

typedef _SV2CVW2_PARAMS  TSV2CreateParams;

typedef _STRRET *PSTRRet;

typedef _STRRET  TStrRet;

typedef int __stdcall (*TFNBFFCallBack)(HWND Wnd, unsigned uMsg, int lParam, int lpData);

typedef _browseinfoA *PBrowseInfoA;

typedef _browseinfoW *PBrowseInfoW;

typedef _browseinfoA *PBrowseInfo;

typedef _browseinfoA  TBrowseInfoA;

typedef _browseinfoW  TBrowseInfoW;

typedef _browseinfoA  TBrowseInfo;

typedef DESKBANDINFO *PDeskBandInfo;

typedef DESKBANDINFO  TDeskBandInfo;

typedef _NRESARRAY *PNResArray;

typedef _NRESARRAY  TNResArray;

typedef _IDA *PIDA;

typedef _IDA  TIDA;

typedef _FILEDESCRIPTORA *PFileDescriptorA;

typedef _FILEDESCRIPTORW *PFileDescriptorW;

typedef _FILEDESCRIPTORA *PFileDescriptor;

typedef _FILEDESCRIPTORA  TFileDescriptorA;

typedef _FILEDESCRIPTORW  TFileDescriptorW;

typedef _FILEDESCRIPTORA  TFileDescriptor;

typedef _FILEGROUPDESCRIPTORA *PFileGroupDescriptorA;

typedef _FILEGROUPDESCRIPTORW *PFileGroupDescriptorW;

typedef _FILEGROUPDESCRIPTORA *PFileGroupDescriptor;

typedef _FILEGROUPDESCRIPTORA  TFileGroupDescriptorA;

typedef _FILEGROUPDESCRIPTORW  TFileGroupDescriptorW;

typedef _FILEGROUPDESCRIPTORA  TFileGroupDescriptor;

typedef _DROPFILES *PDropFiles;

typedef _DROPFILES  TDropFiles;

typedef _SHDESCRIPTIONID *PSHDescriptionID;

typedef _SHDESCRIPTIONID  TSHDescriptionID;

typedef SHELLFLAGSTATE *PShellFlagState;

typedef SHELLFLAGSTATE  TShellFlagState;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE GUID CLSID_ActiveDesktop;
#define SID_INewShortcutHookA "{000214E1-0000-0000-C000-000000000046}"
#define SID_IShellBrowser "{000214E2-0000-0000-C000-000000000046}"
#define SID_IShellView "{000214E3-0000-0000-C000-000000000046}"
#define SID_IContextMenu "{000214E4-0000-0000-C000-000000000046}"
#define SID_IShellIcon "{000214E5-0000-0000-C000-000000000046}"
#define SID_IShellFolder "{000214E6-0000-0000-C000-000000000046}"
#define SID_IShellExtInit "{000214E8-0000-0000-C000-000000000046}"
#define SID_IShellPropSheetExt "{000214E9-0000-0000-C000-000000000046}"
#define SID_IPersistFolder "{000214EA-0000-0000-C000-000000000046}"
#define SID_IExtractIconA "{000214EB-0000-0000-C000-000000000046}"
#define SID_IShellLinkA "{000214EE-0000-0000-C000-000000000046}"
#define SID_IShellCopyHookA "{000214EF-0000-0000-C000-000000000046}"
#define SID_IFileViewerA "{000214F0-0000-0000-C000-000000000046}"
#define SID_ICommDlgBrowser "{000214F1-0000-0000-C000-000000000046}"
#define SID_IEnumIDList "{000214F2-0000-0000-C000-000000000046}"
#define SID_IFileViewerSite "{000214F3-0000-0000-C000-000000000046}"
#define SID_IContextMenu2 "{000214F4-0000-0000-C000-000000000046}"
#define SID_IShellExecuteHookA "{000214F5-0000-0000-C000-000000000046}"
#define SID_IPropSheetPage "{000214F6-0000-0000-C000-000000000046}"
#define SID_INewShortcutHookW "{000214F7-0000-0000-C000-000000000046}"
#define SID_IFileViewerW "{000214F8-0000-0000-C000-000000000046}"
#define SID_IShellLinkW "{000214F9-0000-0000-C000-000000000046}"
#define SID_IExtractIconW "{000214FA-0000-0000-C000-000000000046}"
#define SID_IShellExecuteHookW "{000214FB-0000-0000-C000-000000000046}"
#define SID_IShellCopyHookW "{000214FC-0000-0000-C000-000000000046}"
#define SID_IShellView2 "{88E39E80-3578-11CF-AE69-08002B2E1262}"
#define SID_IContextMenu3 "{BCFCE0A0-EC17-11d0-8D10-00A0C90F2719}"
#define SID_IPersistFolder2 "{1AC3D9F0-175C-11d1-95BE-00609797EA4F}"
#define SID_IShellIconOverlayIdentifier "{0C6C4200-C589-11D0-999A-00C04FD655E1}"
#define SID_IShellIconOverlay "{7D688A70-C613-11D0-999B-00C04FD655E1}"
#define SID_IURLSearchHook "{AC60F6A0-0FD9-11D0-99CB-00C04FD64497}"
#define SID_IInputObjectSite "{f1db8392-7331-11d0-8c99-00a0c92dbfe8}"
#define SID_IInputObject "{68284faa-6a48-11d0-8c78-00c04fd918b4}"
#define SID_IDockingWindowSite "{2a342fc2-7b26-11d0-8ca9-00a0c92dbfe8}"
#define SID_IDockingWindowFrame "{47d2657a-7b27-11d0-8ca9-00a0c92dbfe8}"
#define SID_IDockingWindow "{012dd920-7b26-11d0-8ca9-00a0c92dbfe8}"
#define SID_IDeskBand "{EB0FE172-1A3A-11D0-89B3-00A0C90A90AC}"
#define SID_IActiveDesktop "{F490EB00-1240-11D1-9888-006097DEACF9}"
#define SID_IShellChangeNotify "{00000000-0000-0000-0000-000000000000}"
#define SID_IQueryInfo "{00021500-0000-0000-C000-000000000046}"
static const int SHCNE_EXTENDED_EVENT_PRE_IE4 = 0x80000;

}	/* namespace Shlobj */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Shlobj;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ShlObj
