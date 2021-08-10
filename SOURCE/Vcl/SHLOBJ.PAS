
{*******************************************************}
{                                                       }
{       Borland Delphi Run-time Library                 }
{       Win32 API Shell objects Interface Unit          }
{                                                       }
{       Copyright (c) 1985-1999, Microsoft Corporation  }
{                                                       }
{       Translator: Borland Software Corporation        }
{                                                       }
{*******************************************************}

unit ShlObj;

{$WEAKPACKAGEUNIT}

interface

uses Windows, ActiveX, CommCtrl, ShellAPI, RegStr, Messages, WinInet, UrlMon;

{$HPPEMIT '// If problems occur when compiling win32 structs, records, or'}
{$HPPEMIT '// unions, please define NO_WIN32_LEAN_AND_MEAN to force inclusion'}
{$HPPEMIT '// of Windows header files. '}

{$HPPEMIT '#if defined(NO_WIN32_LEAN_AND_MEAN)'}

{$HPPEMIT '#include <ole2.h>'}
{$HPPEMIT '#include <prsht.h>'}
{$HPPEMIT '#include <commctrl.h>   // for LPTBBUTTON'}
{$HPPEMIT '#include <shlguid.h>'}
{$HPPEMIT '#include <shlobj.h>'}
{$HPPEMIT '#endif'}

{$HPPEMIT '#if !defined(NO_WIN32_LEAN_AND_MEAN)'}
{$HPPEMIT 'interface DECLSPEC_UUID("0000010f-0000-0000-C000-000000000046") IAdviseSink;'}
{$HPPEMIT 'interface DECLSPEC_UUID("000214e2-0000-0000-c000-000000000046") IShellBrowser;'}
{$HPPEMIT 'interface DECLSPEC_UUID("000214e3-0000-0000-c000-000000000046") IShellView;'}
{$HPPEMIT 'interface DECLSPEC_UUID("000214e4-0000-0000-c000-000000000046") IContextMenu;'}
{$HPPEMIT 'interface DECLSPEC_UUID("000214e5-0000-0000-c000-000000000046") IShellIcon;'}
{$HPPEMIT 'interface DECLSPEC_UUID("000214e6-0000-0000-c000-000000000046") IShellFolder;'}
{$HPPEMIT 'interface DECLSPEC_UUID("93F2F68C-1D1B-11d3-A30E-00C04F79ABD1") IShellFolder2;'}
{$HPPEMIT 'interface DECLSPEC_UUID("000214EC-0000-0000-C000-000000000046") IShellDetails;'}
{$HPPEMIT 'interface DECLSPEC_UUID("000214e8-0000-0000-c000-000000000046") IShellExtInit;'}
{$HPPEMIT 'interface DECLSPEC_UUID("000214e9-0000-0000-c000-000000000046") IShellPropSheetExt;'}
{$HPPEMIT 'interface DECLSPEC_UUID("000214ea-0000-0000-c000-000000000046") IPersistFolder;'}
{$HPPEMIT 'interface DECLSPEC_UUID("000214f1-0000-0000-c000-000000000046") ICommDlgBrowser;'}
{$HPPEMIT 'interface DECLSPEC_UUID("000214f2-0000-0000-c000-000000000046") IEnumIDList;'}
{$HPPEMIT 'interface DECLSPEC_UUID("000214f3-0000-0000-c000-000000000046") IFileViewerSite;'}
{$HPPEMIT 'interface DECLSPEC_UUID("000214f4-0000-0000-c000-000000000046") IContextMenu2;'}
{$HPPEMIT 'interface DECLSPEC_UUID("88e39e80-3578-11cf-ae69-08002b2e1262") IShellView2;'}
{$HPPEMIT 'interface DECLSPEC_UUID("000214e1-0000-0000-c000-000000000046") INewShortcutHookA;'}
{$HPPEMIT 'interface DECLSPEC_UUID("000214f7-0000-0000-c000-000000000046") INewShortcutHookW;'}
{$HPPEMIT 'interface DECLSPEC_UUID("000214f0-0000-0000-c000-000000000046") IFileViewerA;'}
{$HPPEMIT 'interface DECLSPEC_UUID("000214f8-0000-0000-c000-000000000046") IFileViewerW;'}
{$HPPEMIT 'interface DECLSPEC_UUID("000214ee-0000-0000-c000-000000000046") IShellLinkA;'}
{$HPPEMIT 'interface DECLSPEC_UUID("000214f9-0000-0000-c000-000000000046") IShellLinkW;'}
{$HPPEMIT 'interface DECLSPEC_UUID("000214eb-0000-0000-c000-000000000046") IExtractIconA;'}
{$HPPEMIT 'interface DECLSPEC_UUID("000214fa-0000-0000-c000-000000000046") IExtractIconW;'}
{$HPPEMIT 'interface DECLSPEC_UUID("000214f5-0000-0000-c000-000000000046") IShellExecuteHookA;'}
{$HPPEMIT 'interface DECLSPEC_UUID("000214fb-0000-0000-c000-000000000046") IShellExecuteHookW;'}
{$HPPEMIT 'interface DECLSPEC_UUID("000214EF-0000-0000-c000-000000000046") ICopyHookA;'}
{$HPPEMIT 'interface DECLSPEC_UUID("000214FC-0000-0000-c000-000000000046") ICopyHookW;'}
{$HPPEMIT '#endif'}

{$HPPEMIT 'typedef System::DelphiInterface<IAdviseSink> _di_IAdviseSink;'}
{$HPPEMIT 'typedef System::DelphiInterface<IShellBrowser> _di_IShellBrowser;'}
{$HPPEMIT 'typedef System::DelphiInterface<IShellView> _di_IShellView;'}
{$HPPEMIT 'typedef System::DelphiInterface<IContextMenu> _di_IContextMenu;'}
{$HPPEMIT 'typedef System::DelphiInterface<IShellIcon> _di_IShellIcon;'}
{$HPPEMIT 'typedef System::DelphiInterface<IShellFolder> _di_IShellFolder;'}
{$HPPEMIT 'typedef System::DelphiInterface<IShellFolder2> _di_IShellFolder2;'}
{$HPPEMIT 'typedef System::DelphiInterface<IShellDetails> _di_IShellDetails;'}
{$HPPEMIT 'typedef System::DelphiInterface<IShellExtInit> _di_IShellExtInit;'}
{$HPPEMIT 'typedef System::DelphiInterface<IShellPropSheetExt> _di_IShellPropSheetExt;'}
{$HPPEMIT 'typedef System::DelphiInterface<IPersistFolder> _di_IPersistFolder;'}
{$HPPEMIT 'typedef System::DelphiInterface<ICommDlgBrowser> _di_ICommDlgBrowser;'}
{$HPPEMIT 'typedef System::DelphiInterface<IEnumIDList> _di_IEnumIDList;'}
{$HPPEMIT 'typedef System::DelphiInterface<IFileViewerSite> _di_IFileViewerSite;'}
{$HPPEMIT 'typedef System::DelphiInterface<IContextMenu2> _di_IContextMenu2;'}
{$HPPEMIT 'typedef System::DelphiInterface<IShellView2> _di_IShellView2;'}
{$HPPEMIT 'typedef System::DelphiInterface<INewShortcutHookA> _di_INewShortcutHookA;'}
{$HPPEMIT 'typedef System::DelphiInterface<INewShortcutHookW> _di_INewShortcutHookW;'}
{$HPPEMIT 'typedef System::DelphiInterface<IFileViewerA> _di_IFileViewerA;'}
{$HPPEMIT 'typedef System::DelphiInterface<IFileViewerW> _di_IFileViewerW;'}
{$HPPEMIT 'typedef System::DelphiInterface<IShellLinkA> _di_IShellLinkA;'}
{$HPPEMIT 'typedef System::DelphiInterface<IShellLinkW> _di_IShellLinkW;'}
{$HPPEMIT 'typedef System::DelphiInterface<IExtractIconA> _di_IExtractIconA;'}
{$HPPEMIT 'typedef System::DelphiInterface<IExtractIconW> _di_IExtractIconW;'}
{$HPPEMIT 'typedef System::DelphiInterface<IShellExecuteHookA> _di_IShellExecuteHookA;'}
{$HPPEMIT 'typedef System::DelphiInterface<IShellExecuteHookW> _di_IShellExecuteHookW;'}
{$HPPEMIT 'typedef System::DelphiInterface<ICopyHookA> _di_ICopyHookA;'}
{$HPPEMIT 'typedef System::DelphiInterface<ICopyHookW> _di_ICopyHookW;'}

{$HPPEMIT '#ifdef UNICODE'}
{$HPPEMIT 'typedef _di_INewShortcutHookW _di_INewShortcutHook;'}
{$HPPEMIT 'typedef _di_IFileViewerW _di_IFileViewer;'}
{$HPPEMIT 'typedef _di_IShellLinkW _di_IShellLink;'}
{$HPPEMIT 'typedef _di_IExtractIconW _di_IExtractIcon;'}
{$HPPEMIT 'typedef _di_IShellExecuteHookW _di_IShellExecuteHook;'}
{$HPPEMIT 'typedef _di_ICopyHookW _di_ICopyHook;'}
{$HPPEMIT '#else'}
{$HPPEMIT 'typedef _di_INewShortcutHookA _di_INewShortcutHook;'}
{$HPPEMIT 'typedef _di_IFileViewerA _di_IFileViewer;'}
{$HPPEMIT 'typedef _di_IShellLinkA _di_IShellLink;'}
{$HPPEMIT 'typedef _di_IExtractIconA _di_IExtractIcon;'}
{$HPPEMIT 'typedef _di_IShellExecuteHookA _di_IShellExecuteHook;'}
{$HPPEMIT 'typedef _di_ICopyHookA _di_ICopyHook;'}
{$HPPEMIT '#endif'}

{$HPPEMIT '#if !defined(NO_WIN32_LEAN_AND_MEAN)'}
{$HPPEMIT 'struct _SHITEMID;'}
{$HPPEMIT 'struct _ITEMIDLIST;'}
{$HPPEMIT 'struct _CMINVOKECOMMANDINFO;'}
{$HPPEMIT 'struct _CMInvokeCommandInfoEx;'}
{$HPPEMIT 'struct FVSHOWINFO;'}
{$HPPEMIT 'struct FOLDERSETTINGS;'}
{$HPPEMIT 'struct _SV2CVW2_PARAMS;'}
{$HPPEMIT 'struct _STRRET;'}
{$HPPEMIT 'struct _SHELLDETAILS;'}
{$HPPEMIT 'struct DESKBANDINFO;'}
{$HPPEMIT 'struct _NRESARRAY;'}
{$HPPEMIT 'struct _IDA;'}
{$HPPEMIT 'struct _FILEDESCRIPTORA;'}
{$HPPEMIT 'struct _FILEDESCRIPTORW;'}
{$HPPEMIT 'struct _FILEGROUPDESCRIPTORW;'}
{$HPPEMIT 'struct _FILEGROUPDESCRIPTORA;'}
{$HPPEMIT 'struct _DROPFILES;'}
{$HPPEMIT 'struct _SHDESCRIPTIONID;'}
{$HPPEMIT 'struct SHELLFLAGSTATE;'}
{$HPPEMIT 'struct _browseinfoA;'}
{$HPPEMIT 'struct _browseinfoW;'}
{$HPPEMIT '#endif'}

{ Object identifiers in the explorer's name space (ItemID and IDList)
  All the items that the user can browse with the explorer (such as files,
  directories, servers, work-groups, etc.) has an identifier which is unique
  among items within the parent folder. Those identifiers are called item
  IDs (SHITEMID). Since all its parent folders have their own item IDs,
  any items can be uniquely identified by a list of item IDs, which is called
  an ID list (ITEMIDLIST).

  ID lists are almost always allocated by the task allocator (see some
  description below as well as OLE 2.0 SDK) and may be passed across
  some of shell interfaces (such as IShellFolder). Each item ID in an ID list
  is only meaningful to its parent folder (which has generated it), and all
  the clients must treat it as an opaque binary data except the first two
  bytes, which indicates the size of the item ID.

  When a shell extension -- which implements the IShellFolder interace --
  generates an item ID, it may put any information in it, not only the data
  with that it needs to identifies the item, but also some additional
  information, which would help implementing some other functions efficiently.
  For example, the shell's IShellFolder implementation of file system items
  stores the primary (long) name of a file or a directory as the item
  identifier, but it also stores its alternative (short) name, size and date
  etc.

  When an ID list is passed to one of shell APIs (such as SHGetPathFromIDList),
  it is always an absolute path -- relative from the root of the name space,
  which is the desktop folder. When an ID list is passed to one of IShellFolder
  member function, it is always a relative path from the folder (unless it
  is explicitly specified). }

const
// Class IDs        xx=00-9F
  {$EXTERNALSYM CLSID_ShellDesktop}
  CLSID_ShellDesktop: TGUID = (
    D1:$00021400; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));
  {$EXTERNALSYM CLSID_ShellLink}
  CLSID_ShellLink: TGUID = (
    D1:$00021401; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));
  CLSID_ActiveDesktop: TGUID = '{75048700-EF1F-11D0-9888-006097DEACF9}';

// Format IDs       xx=A0-CF
  {$EXTERNALSYM FMTID_Intshcut}
  FMTID_Intshcut: TGUID = (
    D1:$000214A0; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));
  {$EXTERNALSYM FMTID_InternetSite}
  FMTID_InternetSite: TGUID = (
    D1:$000214A1; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));

// command group ids xx=D0-DF
  {$EXTERNALSYM CGID_Explorer}
  CGID_Explorer: TGUID = (
    D1:$000214D0; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));
  {$EXTERNALSYM CGID_ShellDocView}
  CGID_ShellDocView: TGUID = (
    D1:$000214D1; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));

// Interface IDs    xx=E0-FF
  {$EXTERNALSYM IID_INewShortcutHookA}
  IID_INewShortcutHookA: TGUID = (
    D1:$000214E1; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));
  {$EXTERNALSYM IID_IShellBrowser}
  IID_IShellBrowser: TGUID = (
    D1:$000214E2; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));
  {$EXTERNALSYM IID_IShellView}
  IID_IShellView: TGUID = (
    D1:$000214E3; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));
  {$EXTERNALSYM IID_IContextMenu}
  IID_IContextMenu: TGUID = (
    D1:$000214E4; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));
  {$EXTERNALSYM IID_IShellIcon}
  IID_IShellIcon: TGUID = (
    D1:$000214E5; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));
  {$EXTERNALSYM IID_IShellFolder}
  IID_IShellFolder: TGUID = (
    D1:$000214E6; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));
  {$EXTERNALSYM IID_IShellExtInit}
  IID_IShellExtInit: TGUID = (
    D1:$000214E8; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));
  {$EXTERNALSYM IID_IShellPropSheetExt}
  IID_IShellPropSheetExt: TGUID = (
    D1:$000214E9; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));
  {$EXTERNALSYM IID_IPersistFolder}
  IID_IPersistFolder: TGUID = (
    D1:$000214EA; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));
  {$EXTERNALSYM IID_IExtractIconA}
  IID_IExtractIconA: TGUID = (
    D1:$000214EB; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));
  {$EXTERNALSYM IID_IShellLinkA}
  IID_IShellLinkA: TGUID = (
    D1:$000214EE; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));
  {$EXTERNALSYM IID_IShellCopyHookA}
  IID_IShellCopyHookA: TGUID = (
    D1:$000214EF; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));
  {$EXTERNALSYM IID_IFileViewerA}
  IID_IFileViewerA: TGUID = (
    D1:$000214F0; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));
  {$EXTERNALSYM IID_ICommDlgBrowser}
  IID_ICommDlgBrowser: TGUID = (
    D1:$000214F1; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));
  {$EXTERNALSYM IID_IEnumIDList}
  IID_IEnumIDList: TGUID = (
    D1:$000214F2; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));
  {$EXTERNALSYM IID_IFileViewerSite}
  IID_IFileViewerSite: TGUID = (
    D1:$000214F3; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));
  {$EXTERNALSYM IID_IContextMenu2}
  IID_IContextMenu2: TGUID = (
    D1:$000214F4; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));
  {$EXTERNALSYM IID_IShellExecuteHook}
  IID_IShellExecuteHook: TGUID = (
    D1:$000214F5; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));
  {$EXTERNALSYM IID_IPropSheetPage}
  IID_IPropSheetPage: TGUID = (
    D1:$000214F6; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));
  {$EXTERNALSYM IID_INewShortcutHookW}
  IID_INewShortcutHookW: TGUID = (
    D1:$000214F7; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));
  {$EXTERNALSYM IID_IFileViewerW}
  IID_IFileViewerW: TGUID = (
    D1:$000214F8; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));
  {$EXTERNALSYM IID_IShellLinkW}
  IID_IShellLinkW: TGUID = (
    D1:$000214F9; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));
  {$EXTERNALSYM IID_IExtractIconW}
  IID_IExtractIconW: TGUID = (
    D1:$000214FA; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));
  {$EXTERNALSYM IID_IShellExecuteHookW}
  IID_IShellExecuteHookW: TGUID = (
    D1:$000214FB; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));
  {$EXTERNALSYM IID_IShellCopyHookW}
  IID_IShellCopyHookW: TGUID = (
    D1:$000214FC; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));
  {$EXTERNALSYM IID_IShellView2}
  IID_IShellView2: TGUID = (
    D1:$88E39E80; D2:$3578; D3:$11CF; D4:($AE,$69,$08,$00,$2B,$2E,$12,$62));
  {$EXTERNALSYM IID_IShellFolder2}
  IID_IShellFolder2: TGUID = (
    D1:$B82C5AA8; D2:$A41B; D3:$11D2; D4:($BE,$32,$00,$C0,$4F,$B9,$36,$61));
  {$EXTERNALSYM IID_IShellDetails}
  IID_IShellDetails: TGUID = (
    D1:$000214EC; D2:$0000; D3:$0000; D4:($C0,$00,$00,$00,$00,$00,$00,$46));
  {$EXTERNALSYM IID_IEnumExtraSearch}
  IID_IEnumExtraSearch: TGUID = (
    D1:$E700BE1; D2: $9DB6; D3:$11D1; D4:($A1,$CE,$00,$C0,$4F,$D7,$5D,$13));


// String constants for Interface IDs
  SID_INewShortcutHookA  = '{000214E1-0000-0000-C000-000000000046}';
  SID_IShellBrowser      = '{000214E2-0000-0000-C000-000000000046}';
  SID_IShellView         = '{000214E3-0000-0000-C000-000000000046}';
  SID_IContextMenu       = '{000214E4-0000-0000-C000-000000000046}';
  SID_IShellIcon         = '{000214E5-0000-0000-C000-000000000046}';
  SID_IShellFolder       = '{000214E6-0000-0000-C000-000000000046}';
  SID_IShellExtInit      = '{000214E8-0000-0000-C000-000000000046}';
  SID_IShellPropSheetExt = '{000214E9-0000-0000-C000-000000000046}';
  SID_IPersistFolder     = '{000214EA-0000-0000-C000-000000000046}';
  SID_IExtractIconA      = '{000214EB-0000-0000-C000-000000000046}';
  SID_IShellLinkA        = '{000214EE-0000-0000-C000-000000000046}';
  SID_IShellCopyHookA    = '{000214EF-0000-0000-C000-000000000046}';
  SID_IFileViewerA       = '{000214F0-0000-0000-C000-000000000046}';
  SID_ICommDlgBrowser    = '{000214F1-0000-0000-C000-000000000046}';
  SID_IEnumIDList        = '{000214F2-0000-0000-C000-000000000046}';
  SID_IFileViewerSite    = '{000214F3-0000-0000-C000-000000000046}';
  SID_IContextMenu2      = '{000214F4-0000-0000-C000-000000000046}';
  SID_IShellExecuteHookA = '{000214F5-0000-0000-C000-000000000046}';
  SID_IPropSheetPage     = '{000214F6-0000-0000-C000-000000000046}';
  SID_INewShortcutHookW  = '{000214F7-0000-0000-C000-000000000046}';
  SID_IFileViewerW       = '{000214F8-0000-0000-C000-000000000046}';
  SID_IShellLinkW        = '{000214F9-0000-0000-C000-000000000046}';
  SID_IExtractIconW      = '{000214FA-0000-0000-C000-000000000046}';
  SID_IShellExecuteHookW = '{000214FB-0000-0000-C000-000000000046}';
  SID_IShellCopyHookW    = '{000214FC-0000-0000-C000-000000000046}';
  SID_IShellView2        = '{88E39E80-3578-11CF-AE69-08002B2E1262}';
  SID_IContextMenu3      = '{BCFCE0A0-EC17-11d0-8D10-00A0C90F2719}';
  SID_IPersistFolder2    = '{1AC3D9F0-175C-11d1-95BE-00609797EA4F}';
  SID_IShellIconOverlayIdentifier = '{0C6C4200-C589-11D0-999A-00C04FD655E1}';
  SID_IShellIconOverlay  = '{7D688A70-C613-11D0-999B-00C04FD655E1}';
  SID_IURLSearchHook     = '{AC60F6A0-0FD9-11D0-99CB-00C04FD64497}';
  SID_IInputObjectSite   = '{f1db8392-7331-11d0-8c99-00a0c92dbfe8}';
  SID_IInputObject       = '{68284faa-6a48-11d0-8c78-00c04fd918b4}';
  SID_IDockingWindowSite = '{2a342fc2-7b26-11d0-8ca9-00a0c92dbfe8}';
  SID_IDockingWindowFrame = '{47d2657a-7b27-11d0-8ca9-00a0c92dbfe8}';
  SID_IDockingWindow     = '{012dd920-7b26-11d0-8ca9-00a0c92dbfe8}';
  SID_IDeskBand          = '{EB0FE172-1A3A-11D0-89B3-00A0C90A90AC}';
  SID_IActiveDesktop     = '{F490EB00-1240-11D1-9888-006097DEACF9}';
  SID_IShellChangeNotify = '{00000000-0000-0000-0000-000000000000}';  // !!
  SID_IQueryInfo         = '{00021500-0000-0000-C000-000000000046}';
  SID_IShellDetails      = '{000214EC-0000-0000-C000-000000000046}';
  SID_IShellFolder2      = '{B82C5AA8-A41B-11D2-BE32-00C04FB93661}';
  SID_IEnumExtraSearch   = '{0E700BE1-9DB6-11D1-A1CE-00C04FD75D13}';
  
type
{ TSHItemID -- Item ID }
  PSHItemID = ^TSHItemID;
  {$EXTERNALSYM _SHITEMID}
  _SHITEMID = record
    cb: Word;                         { Size of the ID (including cb itself) }
    abID: array[0..0] of Byte;        { The item ID (variable length) }
  end;
  TSHItemID = _SHITEMID;
  {$EXTERNALSYM SHITEMID}
  SHITEMID = _SHITEMID;


{ TItemIDList -- List if item IDs (combined with 0-terminator) }
  PItemIDList = ^TItemIDList;
  {$EXTERNALSYM _ITEMIDLIST}
  _ITEMIDLIST = record
     mkid: TSHItemID;
   end;
  TItemIDList = _ITEMIDLIST;
  {$EXTERNALSYM ITEMIDLIST}
  ITEMIDLIST = _ITEMIDLIST;


{ Task allocator API }

{ All the shell extensions MUST use the task allocator (see OLE 2.0
 programming guild for its definition) when they allocate or free
 memory objects (mostly ITEMIDLIST) that are returned across any
 shell interfaces. There are two ways to access the task allocator
 from a shell extension depending on whether or not it is linked with
 OLE32.DLL or not (virtual; stdcall; abstractly for efficiency).

 (1) A shell extension which calls any OLE API (i.e., linked with
  OLE32.DLL) should call OLE's task allocator (by retrieving
  the task allocator by calling CoGetMalloc API).

 (2) A shell extension which does not call any OLE API (i.e., not linked
  with OLE32.DLL) should call the shell task allocator API (defined
  below), so that the shell can quickly loads it when OLE32.DLL is not
  loaded by any application at that point. }

{ !!! Notes:
  In next version of Windowso release, SHGetMalloc will be replaced by
 the following macro.

 #define SHGetMalloc(ppmem)     CoGetMalloc(MEMCTX_TASK, ppmem) }

{$EXTERNALSYM SHGetMalloc}
function SHGetMalloc(var ppMalloc: IMalloc): HResult; stdcall;

{ IContextMenu interface }

{ [OverView] }

{ The shell uses the IContextMenu interface in following three cases.

 case-1: The shell is loading context menu extensions.
   When the user clicks the right mouse button on an item within the shell's
  name space (i.g., file, directory, server, work-group, etc.), it creates
  the default context menu for its type, then loads context menu extensions
  that are registered for that type (and its base type) so that they can
  add extra menu items. Those context menu extensions are registered at
  HKCR\beginProgIDend\shellex\ContextMenuHandlers.

 case-2: The shell is retrieving a context menu of sub-folders in extended
   name-space.
   When the explorer's name space is extended by name space extensions,
  the shell calls their IShellFolder::GetUIObjectOf to get the IContextMenu
  objects when it creates context menus for folders under those extended
  name spaces.

 case-3: The shell is loading non-default drag and drop handler for directories.
   When the user performed a non-default drag and drop onto one of file
  system folders (i.e., directories), it loads shell extensions that are
  registered at HKCR\beginProgIDend\DragDropHandlers. }

{ [Member functions] }

{ IContextMenu::QueryContextMenu }

{ This member function may insert one or more menuitems to the specified
  menu (hmenu) at the specified location (indexMenu which is never be -1).
  The IDs of those menuitem must be in the specified range (idCmdFirst and
  idCmdLast). It returns the maximum menuitem ID offset (ushort) in the
  'code' field (low word) of the scode.

  The uFlags specify the context. It may have one or more of following
  flags.

  CMF_DEFAULTONLY: This flag is passed if the user is invoking the default
  action (typically by double-clicking, case 1 and 2 only). Context menu
  extensions (case 1) should not add any menu items, and returns NOERROR.

  CMF_VERBSONLY: The explorer passes this flag if it is constructing
  a context menu for a short-cut object (case 1 and case 2 only). If this
  flag is passed, it should not add any menu-items that is not appropriate
  from a short-cut.
  A good example is the 'Delete' menuitem, which confuses the user
  because it is not clear whether it deletes the link source item or the
  link itself.

  CMF_EXPLORER: The explorer passes this flag if it has the left-side pane
   (case 1 and 2 only). Context menu extensions should ignore this flag.

  High word (16-bit) are reserved for context specific communications
  and the rest of flags (13-bit) are reserved by the system. }


{ IContextMenu::InvokeCommand }

{ This member is called when the user has selected one of menuitems that
  are inserted by previous QueryContextMenu member. In this case, the
  LOWORD(lpici->lpVerb) contains the menuitem ID offset (menuitem ID -
  idCmdFirst).

   This member function may also be called programmatically. In such a case,
  lpici->lpVerb specifies the canonical name of the command to be invoked,
  which is typically retrieved by GetCommandString member previously.

  Parameters in lpci:
    cbSize -- Specifies the size of this structure (sizeof(*lpci))
    hwnd   -- Specifies the owner window for any message/dialog box.
    fMask  -- Specifies whether or not dwHotkey/hIcon paramter is valid.
    lpVerb -- Specifies the command to be invoked.
    lpParameters -- Parameters (optional)
    lpDirectory  -- Working directory (optional)
    nShow -- Specifies the flag to be passed to ShowWindow (SW_*).
    dwHotKey -- Hot key to be assigned to the app after invoked (optional).
    hIcon -- Specifies the icon (optional).
    hMonitor -- Specifies the default monitor (optional). }


{ IContextMenu::GetCommandString }

{ This member function is called by the explorer either to get the
  canonical (language independent) command name (uFlags == GCS_VERB) or
  the help text ((uFlags & GCS_HELPTEXT) != 0) for the specified command.
  The retrieved canonical string may be passed to its InvokeCommand
  member function to invoke a command programmatically. The explorer
  displays the help texts in its status bar; therefore, the length of
  the help text should be reasonably short (<40 characters).

  Parameters:
   idCmd -- Specifies menuitem ID offset (from idCmdFirst)
   uFlags -- Either GCS_VERB or GCS_HELPTEXT
   pwReserved -- Reserved (must pass NULL when calling, must ignore when called)
   pszName -- Specifies the string buffer.
   cchMax -- Specifies the size of the string buffer. }


const
{ QueryContextMenu uFlags }

  {$EXTERNALSYM CMF_NORMAL}
  CMF_NORMAL             = $00000000;
  {$EXTERNALSYM CMF_DEFAULTONLY}
  CMF_DEFAULTONLY        = $00000001;
  {$EXTERNALSYM CMF_VERBSONLY}
  CMF_VERBSONLY          = $00000002;
  {$EXTERNALSYM CMF_EXPLORE}
  CMF_EXPLORE            = $00000004;
  {$EXTERNALSYM CMF_NOVERBS}
  CMF_NOVERBS            = $00000008;
  {$EXTERNALSYM CMF_CANRENAME}
  CMF_CANRENAME          = $00000010;
  {$EXTERNALSYM CMF_NODEFAULT}
  CMF_NODEFAULT          = $00000020;
  {$EXTERNALSYM CMF_INCLUDESTATIC}
  CMF_INCLUDESTATIC      = $00000040;
  {$EXTERNALSYM CMF_RESERVED}
  CMF_RESERVED           = $FFFF0000;      { View specific }

{ GetCommandString uFlags }

  {$EXTERNALSYM GCS_VERBA}
  GCS_VERBA            = $00000000;     { canonical verb }
  {$EXTERNALSYM GCS_HELPTEXTA}
  GCS_HELPTEXTA        = $00000001;     { help text (for status bar) }
  {$EXTERNALSYM GCS_VALIDATEA}
  GCS_VALIDATEA        = $00000002;     { validate command exists }
  {$EXTERNALSYM GCS_VERBW}
  GCS_VERBW            = $00000004;     { canonical verb (unicode) }
  {$EXTERNALSYM GCS_HELPTEXTW}
  GCS_HELPTEXTW        = $00000005;     { help text (unicode version) }
  {$EXTERNALSYM GCS_VALIDATEW}
  GCS_VALIDATEW        = $00000006;     { validate command exists (unicode) }
  {$EXTERNALSYM GCS_UNICODE}
  GCS_UNICODE          = $00000004;     { for bit testing - Unicode string }









  {$EXTERNALSYM GCS_VERB}
  GCS_VERB            = GCS_VERBA;
  {$EXTERNALSYM GCS_HELPTEXT}
  GCS_HELPTEXT        = GCS_HELPTEXTA;
  {$EXTERNALSYM GCS_VALIDATE}
  GCS_VALIDATE        = GCS_VALIDATEA;


  {$EXTERNALSYM CMDSTR_NEWFOLDERA}
  CMDSTR_NEWFOLDERA       = 'NewFolder';
  {$EXTERNALSYM CMDSTR_VIEWLISTA}
  CMDSTR_VIEWLISTA        = 'ViewList';
  {$EXTERNALSYM CMDSTR_VIEWDETAILSA}
  CMDSTR_VIEWDETAILSA     = 'ViewDetails';
  {$EXTERNALSYM CMDSTR_NEWFOLDERW}
  CMDSTR_NEWFOLDERW       = 'NewFolder'; // !!! make WideString() ?
  {$EXTERNALSYM CMDSTR_VIEWLISTW}
  CMDSTR_VIEWLISTW        = 'ViewList';
  {$EXTERNALSYM CMDSTR_VIEWDETAILSW}
  CMDSTR_VIEWDETAILSW     = 'ViewDetails';









  {$EXTERNALSYM CMDSTR_NEWFOLDER}
  CMDSTR_NEWFOLDER        = CMDSTR_NEWFOLDERA;
  {$EXTERNALSYM CMDSTR_VIEWLIST}
  CMDSTR_VIEWLIST         = CMDSTR_VIEWLISTA;
  {$EXTERNALSYM CMDSTR_VIEWDETAILS}
  CMDSTR_VIEWDETAILS      = CMDSTR_VIEWDETAILSA;


  {$EXTERNALSYM CMIC_MASK_HOTKEY}
  CMIC_MASK_HOTKEY            = SEE_MASK_HOTKEY;
  {$EXTERNALSYM CMIC_MASK_ICON}
  CMIC_MASK_ICON              = SEE_MASK_ICON;
  {$EXTERNALSYM CMIC_MASK_FLAG_NO_UI}
  CMIC_MASK_FLAG_NO_UI        = SEE_MASK_FLAG_NO_UI;
  {$EXTERNALSYM CMIC_MASK_UNICODE}
  CMIC_MASK_UNICODE           = SEE_MASK_UNICODE;
  {$EXTERNALSYM CMIC_MASK_NO_CONSOLE}
  CMIC_MASK_NO_CONSOLE        = SEE_MASK_NO_CONSOLE;
//  CMIC_MASK_HASLINKNAME       = SEE_MASK_HASLINKNAME; - not defined in shellapi
//  CMIC_MASK_FLAG_SEP_VDM      = SEE_MASK_FLAG_SEPVDM; - not defined in shellapi
//  CMIC_MASK_HASTITLE          = SEE_MASK_HASTITLE; - not defined in shellapi
  {$EXTERNALSYM CMIC_MASK_ASYNCOK}
  CMIC_MASK_ASYNCOK           = SEE_MASK_ASYNCOK;

  {$EXTERNALSYM CMIC_MASK_PTINVOKE}
  CMIC_MASK_PTINVOKE          = $20000000;

type
  // NOTE: When SEE_MASK_HMONITOR is set, hIcon is treated as hMonitor
  PCMInvokeCommandInfo = ^TCMInvokeCommandInfo;
  {$EXTERNALSYM _CMINVOKECOMMANDINFO}
  _CMINVOKECOMMANDINFO = record
    cbSize: DWORD;        { must be sizeof(CMINVOKECOMMANDINFO) }
    fMask: DWORD;         { any combination of CMIC_MASK_* }
    hwnd: HWND;           { might be NULL (indicating no owner window) }
    lpVerb: LPCSTR;       { either a string of MAKEINTRESOURCE(idOffset) }
    lpParameters: LPCSTR; { might be NULL (indicating no parameter) }
    lpDirectory: LPCSTR;  { might be NULL (indicating no specific directory) }
    nShow: Integer;       { one of SW_ values for ShowWindow() API }
    dwHotKey: DWORD;
    hIcon: THandle;
  end;
  TCMInvokeCommandInfo = _CMINVOKECOMMANDINFO;
  {$EXTERNALSYM CMINVOKECOMMANDINFO}
  CMINVOKECOMMANDINFO = _CMINVOKECOMMANDINFO;

  PCMInvokeCommandInfoEx = ^TCMInvokeCommandInfoEx;
  {$EXTERNALSYM _CMInvokeCommandInfoEx}
  _CMInvokeCommandInfoEx = record
    cbSize: DWORD;       { must be sizeof(CMINVOKECOMMANDINFOEX) }
    fMask: DWORD;        { any combination of CMIC_MASK_* }
    hwnd: HWND;          { might be NULL (indicating no owner window) }
    lpVerb: LPCSTR;      { either a string or MAKEINTRESOURCE(idOffset) }
    lpParameters: LPCSTR;{ might be NULL (indicating no parameter) }
    lpDirectory: LPCSTR; { might be NULL (indicating no specific directory) }
    nShow: Integer;      { one of SW_ values for ShowWindow() API }
    dwHotKey: DWORD;
    hIcon: THandle;
    lpTitle: LPCSTR;        { For CreateProcess-StartupInfo.lpTitle }
    lpVerbW: LPCWSTR;       { Unicode verb (for those who can use it) }
    lpParametersW: LPCWSTR; { Unicode parameters (for those who can use it) }
    lpDirectoryW: LPCWSTR;  { Unicode directory (for those who can use it) }
    lpTitleW: LPCWSTR;      { Unicode title (for those who can use it) }
    ptInvoke: TPoint;       { Point where it's invoked }
  end;
  TCMInvokeCommandInfoEx = _CMINVOKECOMMANDINFOEX;
  {$EXTERNALSYM CMINVOKECOMMANDINFOEX}
  CMINVOKECOMMANDINFOEX = _CMINVOKECOMMANDINFOEX;


  {$EXTERNALSYM IContextMenu}
  IContextMenu = interface(IUnknown)
    [SID_IContextMenu]
    function QueryContextMenu(Menu: HMENU;
      indexMenu, idCmdFirst, idCmdLast, uFlags: UINT): HResult; stdcall;
    function InvokeCommand(var lpici: TCMInvokeCommandInfo): HResult; stdcall;
    function GetCommandString(idCmd, uType: UINT; pwReserved: PUINT;
      pszName: LPSTR; cchMax: UINT): HResult; stdcall;
  end;

{ IContextMenu2 (IContextMenu with one new member) }
{ IContextMenu2.HandleMenuMsg }

{  This function is called, if the client of IContextMenu is aware of }
{ IContextMenu2 interface and receives one of following messages while }
{ it is calling TrackPopupMenu (in the window proc of hwndOwner): }
{      WM_INITPOPUP, WM_DRAWITEM and WM_MEASUREITEM }
{  The callee may handle these messages to draw owner draw menuitems. }

  {$EXTERNALSYM IContextMenu2}
  IContextMenu2 = interface(IContextMenu)
    [SID_IContextMenu2]
    function HandleMenuMsg(uMsg: UINT; WParam, LParam: Integer): HResult; stdcall;
  end;

{ IContextMenu3 (IContextMenu2 with one new member }
{ IContextMenu3::HandleMenuMsg2 }

{  This function is called, if the client of IContextMenu is aware of }
{ IContextMenu3 interface and receives a menu message while }
{ it is calling TrackPopupMenu (in the window proc of hwndOwner): }

  {$EXTERNALSYM IContextMenu3}
  IContextMenu3 = interface(IContextMenu2)
    [SID_IContextMenu3]
    function HandleMenuMsg2(uMsg: UINT; wParam, lParam: Integer;
      var lpResult: Integer): HResult; stdcall;
  end;

{ Interface: IShellExtInit }

{ The IShellExtInit interface is used by the explorer to initialize shell
  extension objects. The explorer (1) calls CoCreateInstance (or equivalent)
  with the registered CLSID and IID_IShellExtInit, (2) calls its Initialize
  member, then (3) calls its QueryInterface to a particular interface (such
  as IContextMenu or IPropSheetExt and (4) performs the rest of operation. }

{ [Member functions] }

{ IShellExtInit.Initialize }

{ This member function is called when the explorer is initializing either
  context menu extension, property sheet extension or non-default drag-drop
  extension.

  Parameters: (context menu or property sheet extension)
   pidlFolder -- Specifies the parent folder
   lpdobj -- Spefifies the set of items selected in that folder.
   hkeyProgID -- Specifies the type of the focused item in the selection.

  Parameters: (non-default drag-and-drop extension)
   pidlFolder -- Specifies the target (destination) folder
   lpdobj -- Specifies the items that are dropped (see the description
    about shell's clipboard below for clipboard formats).
   hkeyProgID -- Specifies the folder type. }

type
  {$EXTERNALSYM IShellExtInit}
  IShellExtInit = interface(IUnknown)
    [SID_IShellExtInit]
    function Initialize(pidlFolder: PItemIDList; lpdobj: IDataObject;
      hKeyProgID: HKEY): HResult; stdcall;
  end;

{=========================================================================== }

{ Interface: IShellPropSheetExt }

{ The explorer uses the IShellPropSheetExt to allow property sheet
  extensions or control panel extensions to add additional property
  sheet pages. }

{ [Member functions] }

{ IShellPropSheetExt.AddPages }

{ The explorer calls this member function when it finds a registered
  property sheet extension for a particular type of object. For each
  additional page, the extension creates a page object by calling
  CreatePropertySheetPage API and calls lpfnAddPage.

   Parameters:
    lpfnAddPage -- Specifies the callback function.
    lParam -- Specifies the opaque handle to be passed to the callback function. }


{ IShellPropSheetExt.ReplacePage }

{ The explorer never calls this member of property sheet extensions. The
  explorer calls this member of control panel extensions, so that they
  can replace some of default control panel pages (such as a page of
  mouse control panel).

   Parameters:
    uPageID -- Specifies the page to be replaced.
    lpfnReplace Specifies the callback function.
    lParam -- Specifies the opaque handle to be passed to the callback function. }

type
  {$EXTERNALSYM IShellPropSheetExt}
  IShellPropSheetExt = interface(IUnknown)
    [SID_IShellPropSheetExt]
    function AddPages(lpfnAddPage: TFNAddPropSheetPage; lParam: LPARAM): HResult; stdcall;
    function ReplacePage(uPageID: UINT; lpfnReplaceWith: TFNAddPropSheetPage;
      lParam: LPARAM): HResult; stdcall;
  end;

{ IPersistFolder Interface }
{  The IPersistFolder interface is used by the file system implementation of }
{ IShellFolder::BindToObject when it is initializing a shell folder object. }

{ IPersistFolder::Initialize }
{  This member function is called when the explorer is initializing a }
{ shell folder object. }
{  Parameters: }
{   pidl -- Specifies the absolute location of the folder. }

  {$EXTERNALSYM IPersistFolder}
  IPersistFolder = interface(IPersist)
    [SID_IPersistFolder]
    function Initialize(pidl: PItemIDList): HResult; stdcall;
  end;

  {$EXTERNALSYM IPersistFolder2}
  IPersistFolder2 = interface(IPersistFolder)
    [SID_IPersistFolder2]
    function GetCurFolder(var pidl: PItemIDList): HResult; stdcall;
  end;

{ IExtractIcon interface }

{ This interface is used in two different places in the shell.

  Case-1: Icons of sub-folders for the scope-pane of the explorer.

   It is used by the explorer to get the 'icon location' of
  sub-folders from each shell folders. When the user expands a folder
  in the scope pane of the explorer, the explorer does following:
   (1) binds to the folder (gets IShellFolder),
   (2) enumerates its sub-folders by calling its EnumObjects member,
   (3) calls its GetUIObjectOf member to get IExtractIcon interface
      for each sub-folders.
   In this case, the explorer uses only IExtractIcon.GetIconLocation
  member to get the location of the appropriate icon. An icon location
  always consists of a file name (typically DLL or EXE) and either an icon
  resource or an icon index.


  Case-2: Extracting an icon image from a file

   It is used by the shell when it extracts an icon image
  from a file. When the shell is extracting an icon from a file,
  it does following:
   (1) creates the icon extraction handler object (by getting its CLSID
      under the beginProgIDend\shell\ExtractIconHanler key and calling
      CoCreateInstance requesting for IExtractIcon interface).
   (2) Calls IExtractIcon.GetIconLocation.
   (3) Then, calls IExtractIcon.Extract with the location/index pair.
   (4) If (3) returns NOERROR, it uses the returned icon.
   (5) Otherwise, it recursively calls this logic with new location
      assuming that the location string contains a fully qualified path name.

   From extension programmer's point of view, there are only two cases
  where they provide implementations of IExtractIcon:
   Case-1) providing explorer extensions (i.e., IShellFolder).
   Case-2) providing per-instance icons for some types of files.

  Because Case-1 is described above, we'll explain only Case-2 here.

  When the shell is about display an icon for a file, it does following:
   (1) Finds its ProgID and ClassID.
   (2) If the file has a ClassID, it gets the icon location string from the
     'DefaultIcon' key under it. The string indicates either per-class
     icon (e.g., 'FOOBAR.DLL,2') or per-instance icon (e.g., '%1,1').
   (3) If a per-instance icon is specified, the shell creates an icon
     extraction handler object for it, and extracts the icon from it
     (which is described above).

   It is important to note that the shell calls IExtractIcon.GetIconLocation
  first, then calls IExtractIcon.Extract. Most application programs
  that support per-instance icons will probably store an icon location
  (DLL/EXE name and index/id) rather than an icon image in each file.
  In those cases, a programmer needs to implement only the GetIconLocation
  member and it Extract member simply returns S_FALSE. They need to
  implement Extract member only if they decided to store the icon images
  within files themselved or some other database (which is very rare). }

{ [Member functions] }

{ IExtractIcon.GetIconLocation }

{ This function returns an icon location.

  Parameters:
   uFlags     [in]  -- Specifies if it is opened or not (GIL_OPENICON or 0)
   szIconFile [out] -- Specifies the string buffer buffer for a location name.
   cchMax     [in]  -- Specifies the size of szIconFile (almost always MAX_PATH)
   piIndex    [out] -- Sepcifies the address of UINT for the index.
   pwFlags    [out] -- Returns GIL_* flags
  Returns:
   NOERROR, if it returns a valid location; S_FALSE, if the shell use a
   default icon.

  Notes: The location may or may not be a path to a file. The caller can
   not assume anything unless the subsequent Extract member call returns
   S_FALSE.

   if the returned location is not a path to a file, GIL_NOTFILENAME should
   be set in the returned flags. }

{ IExtractIcon.Extract }

{ This function extracts an icon image from a specified file.

  Parameters:
   pszFile [in] -- Specifies the icon location (typically a path to a file).
   nIconIndex [in] -- Specifies the icon index.
   phiconLarge [out] -- Specifies the HICON variable for large icon.
   phiconSmall [out] -- Specifies the HICON variable for small icon.
   nIconSize [in] -- Specifies the size icon required (size of large icon)
                     LOWORD is the requested large icon size
                     HIWORD is the requested small icon size
  Returns:
   NOERROR, if it extracted the from the file.
   S_FALSE, if the caller should extract from the file specified in the
           location. }

const
  {$EXTERNALSYM GIL_OPENICON}
  GIL_OPENICON         = $0001;      { allows containers to specify an "open" look }
  {$EXTERNALSYM GIL_FORSHELL}
  GIL_FORSHELL         = $0002;      { icon is to be displayed in a ShellFolder }
  {$EXTERNALSYM GIL_ASYNC}
  GIL_ASYNC            = $0020;      { this is an async extract, return E_ASYNC }

{ GetIconLocation() return flags }

  {$EXTERNALSYM GIL_SIMULATEDOC}
  GIL_SIMULATEDOC      = $0001;      { simulate this document icon for this }
  {$EXTERNALSYM GIL_PERINSTANCE}
  GIL_PERINSTANCE      = $0002;      { icons from this class are per instance (each file has its own) }
  {$EXTERNALSYM GIL_PERCLASS}
  GIL_PERCLASS         = $0004;      { icons from this class per class (shared for all files of this type) }
  {$EXTERNALSYM GIL_NOTFILENAME}
  GIL_NOTFILENAME      = $0008;      { location is not a filename, must call ::ExtractIcon }
  {$EXTERNALSYM GIL_DONTCACHE}
  GIL_DONTCACHE        = $0010;      { this icon should not be cached }

type
  {$EXTERNALSYM IExtractIconA}
  IExtractIconA = interface(IUnknown)
    [SID_IExtractIconA]
    function GetIconLocation(uFlags: UINT; szIconFile: PAnsiChar; cchMax: UINT;
      out piIndex: Integer; out pwFlags: UINT): HResult; stdcall;
    function Extract(pszFile: PAnsiChar; nIconIndex: UINT;
      out phiconLarge, phiconSmall: HICON; nIconSize: UINT): HResult; stdcall;
  end;
  {$EXTERNALSYM IExtractIconW}
  IExtractIconW = interface(IUnknown)
    [SID_IExtractIconW]
    function GetIconLocation(uFlags: UINT; szIconFile: PWideChar; cchMax: UINT;
      out piIndex: Integer; out pwFlags: UINT): HResult; stdcall;
    function Extract(pszFile: PWideChar; nIconIndex: UINT;
      out phiconLarge, phiconSmall: HICON; nIconSize: UINT): HResult; stdcall;
  end;
  {$EXTERNALSYM IExtractIcon}
  IExtractIcon = IExtractIconA;


{ IShellIcon Interface }
{ Used to get a icon index for a IShellFolder object.

 This interface can be implemented by a IShellFolder, as a quick way to
 return the icon for a object in the folder.

 An instance of this interface is only created once for the folder, unlike
 IExtractIcon witch is created once for each object.

 If a ShellFolder does not implement this interface, the standard
 GetUIObject(....IExtractIcon) method will be used to get a icon
 for all objects.

 The following standard imagelist indexs can be returned:

      0   document (blank page) (not associated)
      1   document (with stuff on the page)
      2   application (exe, com, bat)
      3   folder (plain)
      4   folder (open)

 IShellIcon.GetIconOf(pidl, flags, lpIconIndex)

      pidl            object to get icon for.
      flags           GIL_* input flags (GIL_OPEN, ...)
      lpIconIndex     place to return icon index.

  returns:
      NOERROR, if lpIconIndex contains the correct system imagelist index.
      S_FALSE, if unable to get icon for this object, go through
               GetUIObject, IExtractIcon, methods. }

  {$EXTERNALSYM IShellIcon}
  IShellIcon = interface(IUnknown)
    [SID_IShellIcon]
    function GetIconOf(pidl: PItemIDList; flags: UINT;
      out IconIndex: Integer): HResult; stdcall;
  end;

{ IShellIconOverlayIdentifier }
{
 Used to identify a file as a member of the group of files that have this specific
 icon overlay

 Users can create new IconOverlayIdentifiers and place them in the following registry
 location together with the Icon overlay image and their priority.
 HKEY_LOCAL_MACHINE "Software\\Microsoft\\Windows\\CurrentVersion\\ShellIconOverlayIdentifiers"

 The shell will enumerate through all IconOverlayIdentifiers at start, and prioritize
 them according to internal rules, in case the internal rules don't apply, we use their
 input priority

 IShellIconOverlayIdentifier:IsMemberOf(LPCWSTR pwszPath, DWORD dwAttrib)
      pwszPath        full path of the file
      dwAttrib        attribute of this file

  returns:
      S_OK,    if the file is a member
      S_FALSE, if the file is not a member
      E_FAIL,  if the operation failed due to bad WIN32_FIND_DATA

 IShellIconOverlayIdentifier::GetOverlayInfo(LPWSTR pwszIconFile, int * pIndex, DWORD * dwFlags) PURE;
      pszIconFile    the path of the icon file
      pIndex         Depend on the flags, this could contain the IconIndex or the Sytem Imagelist Index
      dwFlags        defined below

 IShellIconOverlayIdentifier::GetPriority(int * pIPriority) PURE;
      pIPriority     the priority of this Overlay Identifier
}

  {$EXTERNALSYM IShellIconOverlayIdentifier}
  IShellIconOverlayIdentifier = interface(IUnknown)
    [SID_IShellIconOverlayIdentifier]
    function IsMemberOf(pwszPath: PWideChar; dwAttrib: DWORD): HResult; stdcall;
    function GetOverlayInfo(pwszIconFile: PWideChar; cchMax: Integer;
      var pIndex: Integer; var pdwFlags: DWORD): HResult; stdcall;
    function GetPriority(out pIPriority: Integer): HResult; stdcall;
  end;

const
  {$EXTERNALSYM ISIOI_ICONFILE}
  ISIOI_ICONFILE            = $00000001;  // path is returned through pwszIconFile
  {$EXTERNALSYM ISIOI_ICONINDEX}
  ISIOI_ICONINDEX           = $00000002;  // icon index in pwszIconFile is returned through pIndex
  {$EXTERNALSYM ISIOI_SYSIMAGELISTINDEX}
  ISIOI_SYSIMAGELISTINDEX   = $00000004;  // system imagelist icon index is returned through pIndex

{ IShellIconOverlay }
{
 Used to return the icon overlay index or its icon index for an IShellFolder object,
 this is always implemented with IShellFolder

 IShellIconOverlay:GetOverlayIndex(LPCITEMIDLIST pidl, DWORD * pdwIndex)
      pidl            object to identify icon overlay for.
      pdwIndex        the Overlay Index in the system image list

 IShellIconOverlay:GetOverlayIconIndex(LPCITEMIDLIST pidl, DWORD * pdwIndex)
      pdwIconIndex    the Overlay Icon index in the system image list
 This method is only used for those who are interested in seeing the real bits
 of the Overlay Icon

  returns:
      S_OK,  if the index of an Overlay is found
      S_FALSE, if no Overlay exists for this file
      E_FAIL, if pidl is bad
}
type
  {$EXTERNALSYM IShellIconOverlay}
  IShellIconOverlay = interface(IUnknown)
    [SID_IShellIconOverlay]
    function GetOverlayIndex(pidl: PItemIDList; out pIndex: Integer): HResult; stdcall;
    function GetOverlayIconIndex(pidl: PItemIDList; out pIconIndex: Integer): HResult; stdcall;
  end;

{ IShellLink Interface }
const
  { IShellLink.Resolve fFlags }
  {$EXTERNALSYM SLR_NO_UI}
  SLR_NO_UI           = $0001;
  {$EXTERNALSYM SLR_ANY_MATCH}
  SLR_ANY_MATCH       = $0002;
  {$EXTERNALSYM SLR_UPDATE}
  SLR_UPDATE          = $0004;
  {$EXTERNALSYM SLR_NOUPDATE}
  SLR_NOUPDATE        = $0008;

  { IShellLink.GetPath fFlags }
  {$EXTERNALSYM SLGP_SHORTPATH}
  SLGP_SHORTPATH      = $0001;
  {$EXTERNALSYM SLGP_UNCPRIORITY}
  SLGP_UNCPRIORITY    = $0002;
  {$EXTERNALSYM SLGP_RAWPATH}
  SLGP_RAWPATH        = $0004;

type
  {$EXTERNALSYM IShellLinkA}
  IShellLinkA = interface(IUnknown) { sl }
    [SID_IShellLinkA]
    function GetPath(pszFile: PAnsiChar; cchMaxPath: Integer;
      var pfd: TWin32FindData; fFlags: DWORD): HResult; stdcall;
    function GetIDList(var ppidl: PItemIDList): HResult; stdcall;
    function SetIDList(pidl: PItemIDList): HResult; stdcall;
    function GetDescription(pszName: PAnsiChar; cchMaxName: Integer): HResult; stdcall;
    function SetDescription(pszName: PAnsiChar): HResult; stdcall;
    function GetWorkingDirectory(pszDir: PAnsiChar; cchMaxPath: Integer): HResult; stdcall;
    function SetWorkingDirectory(pszDir: PAnsiChar): HResult; stdcall;
    function GetArguments(pszArgs: PAnsiChar; cchMaxPath: Integer): HResult; stdcall;
    function SetArguments(pszArgs: PAnsiChar): HResult; stdcall;
    function GetHotkey(var pwHotkey: Word): HResult; stdcall;
    function SetHotkey(wHotkey: Word): HResult; stdcall;
    function GetShowCmd(out piShowCmd: Integer): HResult; stdcall;
    function SetShowCmd(iShowCmd: Integer): HResult; stdcall;
    function GetIconLocation(pszIconPath: PAnsiChar; cchIconPath: Integer;
      out piIcon: Integer): HResult; stdcall;
    function SetIconLocation(pszIconPath: PAnsiChar; iIcon: Integer): HResult; stdcall;
    function SetRelativePath(pszPathRel: PAnsiChar; dwReserved: DWORD): HResult; stdcall;
    function Resolve(Wnd: HWND; fFlags: DWORD): HResult; stdcall;
    function SetPath(pszFile: PAnsiChar): HResult; stdcall;
  end;
  {$EXTERNALSYM IShellLinkW}
  IShellLinkW = interface(IUnknown) { sl }
    [SID_IShellLinkW]
    function GetPath(pszFile: PWideChar; cchMaxPath: Integer;
      var pfd: TWin32FindData; fFlags: DWORD): HResult; stdcall;
    function GetIDList(var ppidl: PItemIDList): HResult; stdcall;
    function SetIDList(pidl: PItemIDList): HResult; stdcall;
    function GetDescription(pszName: PWideChar; cchMaxName: Integer): HResult; stdcall;
    function SetDescription(pszName: PWideChar): HResult; stdcall;
    function GetWorkingDirectory(pszDir: PWideChar; cchMaxPath: Integer): HResult; stdcall;
    function SetWorkingDirectory(pszDir: PWideChar): HResult; stdcall;
    function GetArguments(pszArgs: PWideChar; cchMaxPath: Integer): HResult; stdcall;
    function SetArguments(pszArgs: PWideChar): HResult; stdcall;
    function GetHotkey(var pwHotkey: Word): HResult; stdcall;
    function SetHotkey(wHotkey: Word): HResult; stdcall;
    function GetShowCmd(out piShowCmd: Integer): HResult; stdcall;
    function SetShowCmd(iShowCmd: Integer): HResult; stdcall;
    function GetIconLocation(pszIconPath: PWideChar; cchIconPath: Integer;
      out piIcon: Integer): HResult; stdcall;
    function SetIconLocation(pszIconPath: PWideChar; iIcon: Integer): HResult; stdcall;
    function SetRelativePath(pszPathRel: PWideChar; dwReserved: DWORD): HResult; stdcall;
    function Resolve(Wnd: HWND; fFlags: DWORD): HResult; stdcall;
    function SetPath(pszFile: PWideChar): HResult; stdcall;
  end;
  {$EXTERNALSYM IShellLink}
  IShellLink = IShellLinkA;

{ IShellExecuteHook Interface }

  {$EXTERNALSYM IShellExecuteHookA}
  IShellExecuteHookA = interface(IUnknown) { sl }
    [SID_IShellExecuteHookA]
    function Execute(var ShellExecuteInfo: TShellExecuteInfo): HResult; stdcall;
  end;
  {$EXTERNALSYM IShellExecuteHookW}
  IShellExecuteHookW = interface(IUnknown) { sl }
    [SID_IShellExecuteHookW]
    function Execute(var ShellExecuteInfo: TShellExecuteInfo): HResult; stdcall;
  end;
  {$EXTERNALSYM IShellExecuteHook}
  IShellExecuteHook = IShellExecuteHookA;

{ IURLSearchHook Interface }

  {$EXTERNALSYM IURLSearchHook}
  IURLSearchHook = interface(IUnknown)
    [SID_IURLSearchHook]
    function Translate(lpwszSearchURL: PWideChar; cchBufferSize: DWORD): HResult; stdcall;
  end;

{ INewShortcutHook Interface }

  {$EXTERNALSYM INewShortcutHookA}
  INewShortcutHookA = interface(IUnknown) { sl }
    [SID_INewShortcutHookA]
    function SetReferent(pcszReferent: PAnsiChar; Wnd: HWND): HResult; stdcall;
    function GetReferent(pcszReferent: PAnsiChar; cchReferent: Integer): HResult; stdcall;
    function SetFolder(pcszFolder: PAnsiChar; Wnd: HWND): HResult; stdcall;
    function GetFolder(pcszFolder: PAnsiChar; cchFolder: Integer): HResult; stdcall;
    function GetName(pcszName: PAnsiChar; cchName: Integer): HResult; stdcall;
    function GetExtension(pcszExtension: PAnsiChar; cchExtension: Integer): HResult; stdcall;
  end;
  {$EXTERNALSYM INewShortcutHookW}
  INewShortcutHookW = interface(IUnknown) { sl }
    [SID_INewShortcutHookW]
    function SetReferent(pcszReferent: PWideChar; Wnd: HWND): HResult; stdcall;
    function GetReferent(pcszReferent: PWideChar; cchReferent: Integer): HResult; stdcall;
    function SetFolder(pcszFolder: PWideChar; Wnd: HWND): HResult; stdcall;
    function GetFolder(pcszFolder: PWideChar; cchFolder: Integer): HResult; stdcall;
    function GetName(pcszName: PWideChar; cchName: Integer): HResult; stdcall;
    function GetExtension(pcszExtension: PWideChar; cchExtension: Integer): HResult; stdcall;
  end;
  {$EXTERNALSYM INewShortcutHook}
  INewShortcutHook = INewShortcutHookA;

{ ICopyHook Interface }

{ The copy hook is called whenever file system directories are
  copy/moved/deleted/renamed via the shell.  It is also called by the shell
  on changes of status of printers.
  Clients register their id under STRREG_SHEX_COPYHOOK for file system hooks
  and STRREG_SHEx_PRNCOPYHOOK for printer hooks.
  the CopyCallback is called prior to the action, so the hook has the chance
  to allow, deny or cancel the operation by returning the falues:
     IDYES  -  means allow the operation
     IDNO   -  means disallow the operation on this file, but continue with
              any other operations (eg. batch copy)
     IDCANCEL - means disallow the current operation and cancel any pending
              operations
   arguments to the CopyCallback
      hwnd - window to use for any UI
      wFunc - what operation is being done
      wFlags - and flags (FOF_*) set in the initial call to the file operation
      pszSrcFile - name of the source file
      dwSrcAttribs - file attributes of the source file
      pszDestFile - name of the destiation file (for move and renames)
      dwDestAttribs - file attributes of the destination file }

type
  {$EXTERNALSYM ICopyHookA}
  ICopyHookA = interface(IUnknown) { sl }
    [SID_IShellCopyHookA]
    function CopyCallback(Wnd: HWND; wFunc, wFlags: UINT; pszSrcFile: PAnsiChar;
      dwSrcAttribs: DWORD; pszDestFile: PAnsiChar; dwDestAttribs: DWORD): UINT; stdcall;
  end;
  {$EXTERNALSYM ICopyHookW}
  ICopyHookW = interface(IUnknown) { sl }
    [SID_IShellCopyHookW]
    function CopyCallback(Wnd: HWND; wFunc, wFlags: UINT; pszSrcFile: PWideChar;
      dwSrcAttribs: DWORD; pszDestFile: PWideChar; dwDestAttribs: DWORD): UINT; stdcall;
  end;
  {$EXTERNALSYM ICopyHook}
  ICopyHook = ICopyHookA;

{ IFileViewerSite Interface }

type
  {$EXTERNALSYM IFileViewerSite}
  IFileViewerSite = interface(IUnknown)
    [SID_IFileViewerSite]
    function SetPinnedWindow(Wnd: HWND): HResult; stdcall;
    function GetPinnedWindow(var Wnd: HWND): HResult; stdcall;
  end;

{ IFileViewer Interface }

{ Implemented in a FileViewer component object.  Used to tell a
  FileViewer to PrintTo or to view, the latter happening though
  ShowInitialize and Show.  The filename is always given to the
  viewer through IPersistFile. }

type
  // !!! unnamed struct
  PFVShowInfo = ^FVSHOWINFO;
  FVSHOWINFO = packed record
    { Stuff passed into viewer (in) }
    cbSize: DWORD;           { Size of structure for future expansion... }
    hwndOwner: HWND;         { who is the owner window. }
    iShow: Integer;          { The show command }

    { Passed in and updated  (in/Out) }
    dwFlags: DWORD;          { flags }
    rect: TRECT;             { Where to create the window may have defaults }
    punkRel: IUNKNOWN;       { Relese this interface when window is visible }

    { Stuff that might be returned from viewer (out) }
    strNewFile: array[0..MAX_PATH-1] of TOleChar;   { New File to view. }
  end;
  {$EXTERNALSYM FVSHOWINFO}
  TFVShowInfo = FVSHOWINFO;
  LPFVSHOWINFO = PFVShowInfo;
  {$EXTERNALSYM LPFVSHOWINFO}
  
const
{ Define File View Show Info Flags. }

  {$EXTERNALSYM FVSIF_RECT}
  FVSIF_RECT      = $00000001;      { The rect variable has valid data. }
  {$EXTERNALSYM FVSIF_PINNED}
  FVSIF_PINNED    = $00000002;      { We should Initialize pinned }

  {$EXTERNALSYM FVSIF_NEWFAILED}
  FVSIF_NEWFAILED = $08000000;      { The new file passed back failed
                                       to be viewed. }

  {$EXTERNALSYM FVSIF_NEWFILE}
  FVSIF_NEWFILE   = $80000000;      { A new file to view has been returned }
  {$EXTERNALSYM FVSIF_CANVIEWIT}
  FVSIF_CANVIEWIT = $40000000;      { The viewer can view it. }

type
  {$EXTERNALSYM IFileViewerA}
  IFileViewerA = interface(IUnknown)
    [SID_IFileViewerA]
    function ShowInitialize(fsi: IFileViewerSite): HResult; stdcall;
    function Show(var pvsi: TFVShowInfo): HResult; stdcall;
    function PrintTo(pszDriver: PAnsiChar; fSuppressUI: BOOL): HResult; stdcall;
  end;
  {$EXTERNALSYM IFileViewerW}
  IFileViewerW = interface(IUnknown)
    [SID_IFileViewerW]
    function ShowInitialize(fsi: IFileViewerSite): HResult; stdcall;
    function Show(var pvsi: TFVShowInfo): HResult; stdcall;
    function PrintTo(pszDriver: PWideChar; fSuppressUI: BOOL): HResult; stdcall;
  end;
  {$EXTERNALSYM IFileViewer}
  IFileViewer = IFileViewerA;

{ CommandTarget ids. for shell doc view wedge }

  {$EXTERNALSYM TSHDVIDEnums}
  TSHDVIDEnums = (
    SHDVID_SETPROGRESSPOS,
    SHDVID_SETPROGRESSRANGE,
    SHDVID_SETSTATUSTEXT,        { variantIn  bstr }
    SHDVID_REFRESH,
    SHDVID_STOP,
    SHDVID_UPDATECOMMANDS, { / this forces a re-querystatus of the command targets. }
                           { / the arg in can specify a specific one to update or NIL for evrything }
    SHDVID_SETTITLE,            { variantIn bstr }
    SHDVID_FINALTITLEAVAIL,     { variantIn bstr - sent after final SETTITLE is sent }
    SHDVID_STARTLOAD,           { NIL for everything }
    SHDVID_STOPLOAD,            { NIL for everything }
    SHDVID_CCALLBACK,           { callback to arbitrary C func }
    SHDVID_MENUEXEC,            { do menu command }
    SHDVID_MENUQS               { query menu commands }
  );

{ IShellBrowser/IShellView/IShellFolder interface }

{  These three interfaces are used when the shell communicates with }
{ name space extensions. The shell (explorer) provides IShellBrowser }
{ interface, and extensions implements IShellFolder and IShellView }
{ interfaces. }

{ ========================================================================== }


{ -------------------------------------------------------------------------- }

{ Command/menuitem IDs }

{  The explorer dispatches WM_COMMAND messages based on the range of }
{ command/menuitem IDs. All the IDs of menuitems that the view (right }
{ pane) inserts must be in FCIDM_SHVIEWFIRST/LAST (otherwise, the explorer }
{ won't dispatch them). The view should not deal with any menuitems }
{ in FCIDM_BROWSERFIRST/LAST (otherwise, it won't work with the future }
{ version of the shell). }

{  FCIDM_SHVIEWFIRST/LAST      for the right pane (IShellView) }
{  FCIDM_BROWSERFIRST/LAST     for the explorer frame (IShellBrowser) }
{  FCIDM_GLOBAL/LAST           for the explorer's submenu IDs }

const
  {$EXTERNALSYM FCIDM_SHVIEWFIRST}
  FCIDM_SHVIEWFIRST               = $0000;
  {$EXTERNALSYM FCIDM_SHVIEWLAST}
  FCIDM_SHVIEWLAST                = $7fff;
  {$EXTERNALSYM FCIDM_BROWSERFIRST}
  FCIDM_BROWSERFIRST              = $a000;
  {$EXTERNALSYM FCIDM_BROWSERLAST}
  FCIDM_BROWSERLAST               = $bf00;
  {$EXTERNALSYM FCIDM_GLOBALFIRST}
  FCIDM_GLOBALFIRST               = $8000;
  {$EXTERNALSYM FCIDM_GLOBALLAST}
  FCIDM_GLOBALLAST                = $9fff;


{ Global submenu IDs and separator IDs }

  {$EXTERNALSYM FCIDM_MENU_FILE}
  FCIDM_MENU_FILE                 = FCIDM_GLOBALFIRST+$0000;
  {$EXTERNALSYM FCIDM_MENU_EDIT}
  FCIDM_MENU_EDIT                 = FCIDM_GLOBALFIRST+$0040;
  {$EXTERNALSYM FCIDM_MENU_VIEW}
  FCIDM_MENU_VIEW                 = FCIDM_GLOBALFIRST+$0080;
  {$EXTERNALSYM FCIDM_MENU_VIEW_SEP_OPTIONS}
  FCIDM_MENU_VIEW_SEP_OPTIONS     = FCIDM_GLOBALFIRST+$0081;
  {$EXTERNALSYM FCIDM_MENU_TOOLS}
  FCIDM_MENU_TOOLS                = FCIDM_GLOBALFIRST+$00c0;
  {$EXTERNALSYM FCIDM_MENU_TOOLS_SEP_GOTO}
  FCIDM_MENU_TOOLS_SEP_GOTO       = FCIDM_GLOBALFIRST+$00c1;
  {$EXTERNALSYM FCIDM_MENU_HELP}
  FCIDM_MENU_HELP                 = FCIDM_GLOBALFIRST+$0100;
  {$EXTERNALSYM FCIDM_MENU_FIND}
  FCIDM_MENU_FIND                 = FCIDM_GLOBALFIRST+$0140;
  {$EXTERNALSYM FCIDM_MENU_EXPLORE}
  FCIDM_MENU_EXPLORE              = FCIDM_GLOBALFIRST+$0150;
  {$EXTERNALSYM FCIDM_MENU_FAVORITES}
  FCIDM_MENU_FAVORITES            = FCIDM_GLOBALFIRST+$0170;

{ -------------------------------------------------------------------------- }
{ control IDs known to the view }
{ -------------------------------------------------------------------------- }

  {$EXTERNALSYM FCIDM_TOOLBAR}
  FCIDM_TOOLBAR          = FCIDM_BROWSERFIRST + 0;
  {$EXTERNALSYM FCIDM_STATUS}
  FCIDM_STATUS           = FCIDM_BROWSERFIRST + 1;

  { The resource id of the offline cursor }
  { This cursor is avaialble in shdocvw.dll }
  {$EXTERNALSYM IDC_OFFLINE_HAND}
  IDC_OFFLINE_HAND       = 103;

{ -------------------------------------------------------------------------- }

{ FOLDERSETTINGS }

{  FOLDERSETTINGS is a data structure that explorer passes from one folder }
{ view to another, when the user is browsing. It calls ISV::GetCurrentInfo }
{ member to get the current settings and pass it to ISV::CreateViewWindow }
{ to allow the next folder view "inherit" it. These settings assumes a }
{ particular UI (which the shell's folder view has), and shell extensions }
{ may or may not use those settings. }

{ -------------------------------------------------------------------------- }

{ NB Bitfields. }
{ FWF_DESKTOP implies FWF_TRANSPARENT/NOCLIENTEDGE/NOSCROLL }
const
  {$EXTERNALSYM FWF_AUTOARRANGE}
  FWF_AUTOARRANGE = $0001;
  {$EXTERNALSYM FWF_ABBREVIATEDNAMES}
  FWF_ABBREVIATEDNAMES = $0002;
  {$EXTERNALSYM FWF_SNAPTOGRID}
  FWF_SNAPTOGRID = $0004;
  {$EXTERNALSYM FWF_OWNERDATA}
  FWF_OWNERDATA = $0008;
  {$EXTERNALSYM FWF_BESTFITWINDOW}
  FWF_BESTFITWINDOW = $0010;
  {$EXTERNALSYM FWF_DESKTOP}
  FWF_DESKTOP = $0020;
  {$EXTERNALSYM FWF_SINGLESEL}
  FWF_SINGLESEL = $0040;
  {$EXTERNALSYM FWF_NOSUBFOLDERS}
  FWF_NOSUBFOLDERS = $0080;
  {$EXTERNALSYM FWF_TRANSPARENT}
  FWF_TRANSPARENT = $0100;
  {$EXTERNALSYM FWF_NOCLIENTEDGE}
  FWF_NOCLIENTEDGE = $0200;
  {$EXTERNALSYM FWF_NOSCROLL}
  FWF_NOSCROLL    = $0400;
  {$EXTERNALSYM FWF_ALIGNLEFT}
  FWF_ALIGNLEFT   = $0800;
  {$EXTERNALSYM FWF_NOICONS}
  FWF_NOICONS     = $1000;
  {$EXTERNALSYM FWF_SINGLECLICKACTIVATE}
  FWF_SINGLECLICKACTIVATE = $8000; { TEMPORARY -- NO UI FOR THIS }

  {$EXTERNALSYM FVM_ICON}
  FVM_ICON = 1;
  {$EXTERNALSYM FVM_SMALLICON}
  FVM_SMALLICON = 2;
  {$EXTERNALSYM FVM_LIST}
  FVM_LIST = 3;
  {$EXTERNALSYM FVM_DETAILS}
  FVM_DETAILS = 4;

type
  // !!! unnamed struct
  PFolderSettings = ^FOLDERSETTINGS;
  FOLDERSETTINGS = packed record
    ViewMode: UINT;      { View mode (FOLDERVIEWMODE values) }
    fFlags: UINT;        { View options (FOLDERFLAGS bits) }
  end;
  {$EXTERNALSYM FOLDERSETTINGS}
  TFolderSettings = FOLDERSETTINGS;
  LPFOLDERSETTINGS = PFolderSettings;
  {$EXTERNALSYM LPFOLDERSETTINGS} 

{ -------------------------------------------------------------------------- }

{ Interface:   IShellBrowser }

{  IShellBrowser interface is the interface that is provided by the shell }
{ explorer/folder frame window. When it creates the "contents pane" of }
{ a shell folder (which provides IShellFolder interface), it calls its }
{ CreateViewObject member function to create an IShellView object. Then, }
{ it calls its CreateViewWindow member to create the "contents pane" }
{ window. The pointer to the IShellBrowser interface is passed to }
{ the IShellView object as a parameter to this CreateViewWindow member }
{ function call. }

{    +--------------------------+  <-- Explorer window }
{    | [] Explorer              | }
{    |--------------------------+       IShellBrowser }
{    | File Edit View ..        | }
{    |--------------------------| }
{    |        |                 | }
{    |        |              <-------- Content pane }
{    |        |                 | }
{    |        |                 |       IShellView }
{    |        |                 | }
{    |        |                 | }
{    +--------------------------+ }



{ [Member functions] }


{ IShellBrowser.GetWindow(phwnd) }

{   Inherited from IOleWindow.GetWindow. }


{ IShellBrowser.ContextSensitiveHelp(fEnterMode) }

{   Inherited from IOleWindow.ContextSensitiveHelp. }


{ IShellBrowser.InsertMenusSB(hmenuShared, lpMenuWidths) }

{   Similar to the IOleInPlaceFrame.InsertMenus. The explorer will put }
{  "File" and "Edit" pulldown in the File menu group, "View" and "Tools" }
{  in the Container menu group and "Help" in the Window menu group. Each }
{  pulldown menu will have a uniqu ID, FCIDM_MENU_FILE/EDIT/VIEW/TOOLS/HELP. }
{  The view is allowed to insert menuitems into those sub-menus by those }
{  IDs must be between FCIDM_SHVIEWFIRST and FCIDM_SHVIEWLAST. }


{ IShellBrowser.SetMenuSB(hmenuShared, holemenu, hwndActiveObject) }

{   Similar to the IOleInPlaceFrame.SetMenu. The explorer ignores the }
{  holemenu parameter (reserved for future enhancement)  and performs }
{  menu-dispatch based on the menuitem IDs (see the description above). }
{  It is important to note that the explorer will add different }
{  set of menuitems depending on whether the view has a focus or not. }
{  Therefore, it is very important to call ISB.OnViewWindowActivate }
{  whenever the view window (or its children) gets the focus. }


{ IShellBrowser.RemoveMenusSB(hmenuShared) }

{   Same as the IOleInPlaceFrame.RemoveMenus. }


{ IShellBrowser.SetStatusTextSB(lpszStatusText) }

{   Same as the IOleInPlaceFrame.SetStatusText. It is also possible to }
{  send messages directly to the status window via SendControlMsg. }


{ IShellBrowser.EnableModelessSB(fEnable) }

{   Same as the IOleInPlaceFrame.EnableModeless. }

{ IShellBrowser.TranslateAcceleratorSB(lpmsg, wID) }

{   Same as the IOleInPlaceFrame.TranslateAccelerator, but will be }
{  never called because we don't support EXEs (i.e., the explorer has }
{  the message loop). This member function is defined here for possible }
{  future enhancement. }


{ IShellBrowser.BrowseObject(pidl, wFlags) }

{   The view calls this member to let shell explorer browse to another }
{  folder. The pidl and wFlags specifies the folder to be browsed. }

{  Following three flags specifies whether it creates another window or not. }
{   SBSP_SAMEBROWSER  -- Browse to another folder with the same window. }
{   SBSP_NEWBROWSER   -- Creates another window for the specified folder. }
{   SBSP_DEFBROWSER   -- Default behavior (respects the view option). }

{  Following three flags specifies open, explore, or default mode. These   . }
{  are ignored if SBSP_SAMEBROWSER or (SBSP_DEFBROWSER && (single window   . }
{  browser || explorer)).                                                  . }
{   SBSP_OPENMODE     -- Use a normal folder window }
{   SBSP_EXPLOREMODE  -- Use an explorer window }
{   SBSP_DEFMODE      -- Use the same as the current window }

{  Following three flags specifies the pidl. }
{   SBSP_ABSOLUTE -- pidl is an absolute pidl (relative from desktop) }
{   SBSP_RELATIVE -- pidl is relative from the current folder. }
{   SBSP_PARENT   -- Browse the parent folder (ignores the pidl) }
{   SBSP_NAVIGATEBACK    -- Navigate back (ignores the pidl) }
{   SBSP_NAVIGATEFORWARD -- Navigate forward (ignores the pidl) }

{  Following two flags control history manipulation as result of navigate }
{   SBSP_WRITENOHISTORY -- write no history (shell folder) entry }
{   SBSP_NOAUTOSELECT -- suppress selection in history pane }


{ IShellBrowser.GetViewStateStream(grfMode, ppstm) }

{   The browser returns an IStream interface as the storage for view }
{  specific state information. }

{   grfMode -- Specifies the read/write access (STGM_READ/WRITE/READWRITE) }
{   ppstm   -- Specifies the LPSTREAM variable to be filled. }


{ IShellBrowser.GetControlWindow(id, phwnd) }

{   The shell view may call this member function to get the window handle }
{  of Explorer controls (toolbar or status winodw -- FCW_TOOLBAR or }
{  FCW_STATUS). }


{ IShellBrowser.SendControlMsg(id, uMsg, wParam, lParam, pret) }

{   The shell view calls this member function to send control messages to }
{  one of Explorer controls (toolbar or status window -- FCW_TOOLBAR or }
{  FCW_STATUS). }


{ IShellBrowser.QueryActiveShellView(IShellView * ppshv) }

{   This member returns currently activated (displayed) shellview object. }
{  A shellview never need to call this member function. }


{ IShellBrowser.OnViewWindowActive(pshv) }

{   The shell view window calls this member function when the view window }
{  (or one of its children) got the focus. It MUST call this member before }
{  calling IShellBrowser.InsertMenus, because it will insert different }
{  set of menu items depending on whether the view has the focus or not. }


{ IShellBrowser.SetToolbarItems(lpButtons, nButtons, uFlags) }

{   The view calls this function to add toolbar items to the exporer's }
{  toolbar. "lpButtons" and "nButtons" specifies the array of toolbar }
{  items. "uFlags" must be one of FCT_MERGE, FCT_CONFIGABLE, FCT_ADDTOEND. }

{ ------------------------------------------------------------------------- }


{ Values for wFlags parameter of ISB.BrowseObject() member. }
const
  {$EXTERNALSYM SBSP_DEFBROWSER}
  SBSP_DEFBROWSER      = $0000;
  {$EXTERNALSYM SBSP_SAMEBROWSER}
  SBSP_SAMEBROWSER     = $0001;
  {$EXTERNALSYM SBSP_NEWBROWSER}
  SBSP_NEWBROWSER      = $0002;

  {$EXTERNALSYM SBSP_DEFMODE}
  SBSP_DEFMODE         = $0000;
  {$EXTERNALSYM SBSP_OPENMODE}
  SBSP_OPENMODE        = $0010;
  {$EXTERNALSYM SBSP_EXPLOREMODE}
  SBSP_EXPLOREMODE     = $0020;

  {$EXTERNALSYM SBSP_ABSOLUTE}
  SBSP_ABSOLUTE        = $0000;
  {$EXTERNALSYM SBSP_RELATIVE}
  SBSP_RELATIVE        = $1000;
  {$EXTERNALSYM SBSP_PARENT}
  SBSP_PARENT          = $2000;
  {$EXTERNALSYM SBSP_NAVIGATEBACK}
  SBSP_NAVIGATEBACK    = $4000;
  {$EXTERNALSYM SBSP_NAVIGATEFORWARD}
  SBSP_NAVIGATEFORWARD = $8000;

  {$EXTERNALSYM SBSP_ALLOW_AUTONAVIGATE}
  SBSP_ALLOW_AUTONAVIGATE = $10000;

  {$EXTERNALSYM SBSP_INITIATEDBYHLINKFRAME}
  SBSP_INITIATEDBYHLINKFRAME            = $80000000;
  {$EXTERNALSYM SBSP_REDIRECT}
  SBSP_REDIRECT                         = $40000000;

  {$EXTERNALSYM SBSP_WRITENOHISTORY}
  SBSP_WRITENOHISTORY     = $08000000;
  {$EXTERNALSYM SBSP_NOAUTOSELECT}
  SBSP_NOAUTOSELECT       = $04000000;

{ Values for id parameter of ISB.GetWindow/SendControlMsg members. }

{ WARNING: }
{  Any shell extensions which sends messages to those control windows }
{ might not work in the future version of windows. If you really need }
{ to send messages to them, (1) don't assume that those control window }
{ always exist (i.e. GetControlWindow may fail) and (2) verify the window }
{ class of the window before sending any messages. }

  {$EXTERNALSYM FCW_STATUS}
  FCW_STATUS          = $0001;
  {$EXTERNALSYM FCW_TOOLBAR}
  FCW_TOOLBAR         = $0002;
  {$EXTERNALSYM FCW_TREE}
  FCW_TREE            = $0003;
  {$EXTERNALSYM FCW_INTERNETBAR}
  FCW_INTERNETBAR     = $0006;
  {$EXTERNALSYM FCW_PROGRESS}
  FCW_PROGRESS        = $0008;


{ Values for uFlags paremeter of ISB.SetToolbarItems member. }

  {$EXTERNALSYM FCT_MERGE}
  FCT_MERGE           = $0001;
  {$EXTERNALSYM FCT_CONFIGABLE}
  FCT_CONFIGABLE      = $0002;
  {$EXTERNALSYM FCT_ADDTOEND}
  FCT_ADDTOEND        = $0004;

{ ICommDlgBrowser.OnStateChange values }

  {$EXTERNALSYM CDBOSC_SETFOCUS}
  CDBOSC_SETFOCUS         = $00000000;
  {$EXTERNALSYM CDBOSC_KILLFOCUS}
  CDBOSC_KILLFOCUS        = $00000001;
  {$EXTERNALSYM CDBOSC_SELCHANGE}
  CDBOSC_SELCHANGE        = $00000002;
  {$EXTERNALSYM CDBOSC_RENAME}
  CDBOSC_RENAME           = $00000003;

{ shellview select item flags }

  {$EXTERNALSYM SVSI_DESELECT}
  SVSI_DESELECT           = $0000;
  {$EXTERNALSYM SVSI_SELECT}
  SVSI_SELECT             = $0001;
  {$EXTERNALSYM SVSI_EDIT}
  SVSI_EDIT               = $0003;  { includes select }
  {$EXTERNALSYM SVSI_DESELECTOTHERS}
  SVSI_DESELECTOTHERS     = $0004;
  {$EXTERNALSYM SVSI_ENSUREVISIBLE}
  SVSI_ENSUREVISIBLE      = $0008;
  {$EXTERNALSYM SVSI_FOCUSED}
  SVSI_FOCUSED            = $0010;
  {$EXTERNALSYM SVSI_TRANSLATEPT}
  SVSI_TRANSLATEPT        = $0020;

{ shellview get item object flags }

  {$EXTERNALSYM SVGIO_BACKGROUND}
  SVGIO_BACKGROUND        = $00000000;
  {$EXTERNALSYM SVGIO_SELECTION}
  SVGIO_SELECTION         = $00000001;
  {$EXTERNALSYM SVGIO_ALLVIEW}
  SVGIO_ALLVIEW           = $00000002;

type
  {$EXTERNALSYM HOLEMENU}
  HOLEMENU = HGLOBAL; // !!! should this be in ole2.pas?

  IShellView = interface;

  {$EXTERNALSYM IShellBrowser}
  IShellBrowser = interface(IOleWindow)
    [SID_IShellBrowser]
    function InsertMenusSB(hMenuShared: HMENU;
      out MenuWidths: TOleMenuGroupWidths): HResult; stdcall;
    function SetMenuSB(hMenuShared: HMENU;
      hOleMenuReserved: HOLEMENU; hwndActiveObject: HWND): HResult; stdcall;
    function RemoveMenusSB(hMenuShared: HMENU): HResult; stdcall;
    function SetStatusTextSB(StatusText: POleStr): HResult; stdcall;
    function EnableModelessSB(Enable: BOOL): HResult; stdcall;
    function TranslateAcceleratorSB(Msg: PMsg; ID: Word): HResult; stdcall;
    function BrowseObject(pidl: PItemIDList; flags: UINT): HResult; stdcall;
    function GetViewStateStream(Mode: DWORD; out Stream: IStream): HResult; stdcall;
    function GetControlWindow(ID: UINT; out Wnd: HWND): HResult; stdcall;
    function SendControlMsg(ID, Msg: UINT; wParm: WPARAM; lParm: LPARAM;
      var Rslt: LResult): HResult; stdcall;
    function QueryActiveShellView(var ShellView: IShellView): HResult; stdcall;
    function OnViewWindowActive(var ShellView: IShellView): HResult; stdcall;
    function SetToolbarItems(TBButton: PTBButton;
      nButtons, uFlags: UINT): HResult; stdcall;
  end;

  {$EXTERNALSYM TSBSCEnums}
  TSBSCEnums = (SBSC_HIDE, SBSC_SHOW, SBSC_TOGGLE, SBSC_QUERY);

  {$EXTERNALSYM TSBOEnums}
  TSBOEnums = (SBO_DEFAULT, SBO_NOBROWSERPAGES);


{ CommandTarget ids. }
  {$EXTERNALSYM TSBCMDIDEnums}
  TSBCMDIDEnums = (
    SBCMDID_ENABLESHOWTREE,
    SBCMDID_SHOWCONTROL,                { variant vt_i4 = loword = FCW_* hiword = SBSC_* }
    SBCMDID_CANCELNAVIGATION,           { cancel last navigation }
    SBCMDID_MAYSAVECHANGES,             { about to close and may save changes }
    SBCMDID_SETHLINKFRAME,              { variant vt_i4 = phlinkframe }
    SBCMDID_ENABLESTOP,                 { variant vt_bool = fEnable }
    SBCMDID_OPTIONS                     { the view.options page }
  );


{ ICommDlgBrowser interface }

{  ICommDlgBrowser interface is the interface that is provided by the new }
{ common dialog window to hook and modify the behavior of IShellView.  When }
{ a default view is created, it queries its parent IShellBrowser for the }
{ ICommDlgBrowser interface.  If supported, it calls out to that interface }
{ in several cases that need to behave differently in a dialog. }

{ Member functions: }

{  ICommDlgBrowser.OnDefaultCommand() }
{    Called when the user double-clicks in the view or presses Enter.  The }
{   browser should return S_OK if it processed the action itself, S_FALSE }
{   to let the view perform the default action. }

{  ICommDlgBrowser.OnStateChange(ULONG uChange) }
{    Called when some states in the view change.  'uChange' is one of the }
{   CDBOSC_* values.  This call is made after the state (selection, focus, }
{   etc) has changed.  There is no return value. }

{  ICommDlgBrowser.IncludeObject(LPCITEMIDLIST pidl) }
{    Called when the view is enumerating objects.  'pidl' is a relative }
{   IDLIST.  The browser should return S_OK to include the object in the }
{   view, S_FALSE to hide it }

{ ------------------------------------------------------------------------- }

  {$EXTERNALSYM ICommDlgBrowser}
  ICommDlgBrowser = interface(IUnknown)
    [SID_ICommDlgBrowser]
    function OnDefaultCommand(const ppshv: IShellView): HResult; stdcall;
    function OnStateChange(const ppshv: IShellView; Change: ULONG): HResult; stdcall;
    function IncludeObject(const ppshv: IShellView; pidl: PItemIDList): HResult; stdcall;
  end;


{ Interface:   IShellView }

{ IShellView.ContextSensitiveHelp(fEnterMode) }

{   Inherited from IOleWindow.ContextSensitiveHelp. }


{ IShellView.TranslateAccelerator(lpmsg) }

{   Similar to IOleInPlaceActiveObject.TranlateAccelerator. The explorer }
{  calls this function BEFORE any other translation. Returning S_OK }
{  indicates that the message was translated (eaten) and should not be }
{  translated or dispatched by the explorer. }


{ IShellView.EnableModeless(fEnable) }

{   Similar to IOleInPlaceActiveObject.EnableModeless. }


{ IShellView.UIActivate(uState) }

{   The explorer calls this member function whenever the activation }
{  state of the view window is changed by a certain event that is }
{  NOT caused by the shell view itself. }

{   SVUIA_DEACTIVATE will be passed when the explorer is about to }
{  destroy the shell view window; the shell view is supposed to remove }
{  all the extended UIs (typically merged menu and modeless popup windows). }

{   SVUIA_ACTIVATE_NOFOCUS will be passsed when the shell view is losing }
{  the input focus or the shell view has been just created without the }
{  input focus; the shell view is supposed to set menuitems appropriate }
{  for non-focused state (no selection specific items should be added). }

{   SVUIA_ACTIVATE_FOCUS will be passed when the explorer has just }
{  created the view window with the input focus; the shell view is }
{  supposed to set menuitems appropriate for focused state. }

{   SVUIA_INPLACEACTIVATE(new) will be passed when the shell view is opened }
{  within an ActiveX control, which is not a UI active. In this case, }
{  the shell view should not merge menus or put toolbas. To be compatible }
{  with Win95 client, we don't pass this value unless the view supports }
{  IShellView2. }

{   The shell view should not change focus within this member function. }
{  The shell view should not hook the WM_KILLFOCUS message to remerge }
{  menuitems. However, the shell view typically hook the WM_SETFOCUS }
{  message, and re-merge the menu after calling IShellBrowser. }
{  OnViewWindowActivated. }


{ IShellView.Refresh() }

{   The explorer calls this member when the view needs to refresh its }
{  contents (such as when the user hits F5 key). }


{ IShellView.CreateViewWindow }

{   This member creates the view window (right-pane of the explorer or the }
{  client window of the folder window). }


{ IShellView.DestroyViewWindow }

{   This member destroys the view window. }


{ IShellView.GetCurrentInfo }

{   This member returns the folder settings. }


{ IShellView.AddPropertySHeetPages }

{   The explorer calls this member when it is opening the option property }
{  sheet. This allows the view to add additional pages to it. }


{ IShellView.SaveViewState() }

{   The explorer calls this member when the shell view is supposed to }
{  store its view settings. The shell view is supposed to get a view }
{  stream by calling IShellBrowser.GetViewStateStream and store the }
{  current view state into that stream. }


{ IShellView.SelectItem(pidlItem, uFlags) }

{   The explorer calls this member to change the selection state of }
{  item(s) within the shell view window.  If pidlItem is NULL and uFlags }
{  is SVSI_DESELECTOTHERS, all items should be deselected. }

{ ------------------------------------------------------------------------- }

{ uState values for IShellView.UIActivate }

  {$EXTERNALSYM TSVUIAEnums}
  TSVUIAEnums = (
    SVUIA_DEACTIVATE,
    SVUIA_ACTIVATE_NOFOCUS,
    SVUIA_ACTIVATE_FOCUS,
    SVUIA_INPLACEACTIVATE               { new flag for IShellView2 }
  );

  {$EXTERNALSYM IShellView}
  IShellView = interface(IOleWindow)
    [SID_IShellView]
    function TranslateAccelerator(var Msg: TMsg): HResult; stdcall;
    function EnableModeless(Enable: Boolean): HResult; stdcall;
    function UIActivate(State: UINT): HResult; stdcall;
    function Refresh: HResult; stdcall;
    function CreateViewWindow(PrevView: IShellView;
      var FolderSettings: TFolderSettings; ShellBrowser: IShellBrowser;
      var Rect: TRect; out Wnd: HWND): HResult; stdcall;
    function DestroyViewWindow: HResult; stdcall;
    function GetCurrentInfo(out FolderSettings: TFolderSettings): HResult; stdcall;
    function AddPropertySheetPages(Reseved: DWORD;
      var lpfnAddPage: TFNAddPropSheetPage; lParam: LPARAM): HResult; stdcall;
    function SaveViewState: HResult; stdcall;
    function SelectItem(pidl: PItemIDList; flags: UINT): HResult; stdcall;
    function GetItemObject(Item: UINT; const iid: TIID; var IPtr: Pointer): HResult; stdcall;
  end;

const
  {$EXTERNALSYM SV2GV_CURRENTVIEW}
  SV2GV_CURRENTVIEW     = -1;
  {$EXTERNALSYM SV2GV_DEFAULTVIEW}
  SV2GV_DEFAULTVIEW     = -2;

type
  {$EXTERNALSYM SHELLVIEWID}
  SHELLVIEWID = TGUID;
  TShellViewID = SHELLVIEWID;
  PShellViewID = ^TShellViewID;

  PSV2CreateParams = ^TSV2CreateParams;
  {$EXTERNALSYM _SV2CVW2_PARAMS}
  _SV2CVW2_PARAMS = record
    cbSize: DWORD;
    psvPrev: IShellView;
    pfs: PFolderSettings;
    psbOwner: IShellBrowser;
    prcView: PRect;
    pvid: PShellViewID;
    hwndView: HWND;
  end;
  TSV2CreateParams = _SV2CVW2_PARAMS;
  {$EXTERNALSYM SV2CVW2_PARAMS}
  SV2CVW2_PARAMS = _SV2CVW2_PARAMS;


  {$EXTERNALSYM IShellView2}
  IShellView2 = interface(IShellView)
    [SID_IShellView2]
    function GetView(pvid: PShellViewID; uView: ULONG): HResult; stdcall;
    function CreateViewWindow2(SV2CreateParams: PSV2CreateParams): HResult; stdcall;
    function HandleRename(pidlNew: PItemIDList): HResult; stdcall;
    function SelectAndPositionItem(pidlItem: PItemIDList; uFlags: UINT;
      var Point: TPoint): HResult; stdcall;
  end;

{ ------------------------------------------------------------------------- }

const
  {$EXTERNALSYM STRRET_WSTR}
  STRRET_WSTR         = $0000;          { Use STRRET.pOleStr }
  {$EXTERNALSYM STRRET_OFFSET}
  STRRET_OFFSET       = $0001;          { Use STRRET.uOffset to Ansi }
  {$EXTERNALSYM STRRET_CSTR}
  STRRET_CSTR         = $0002;          { Use STRRET.cStr }

type
{ record for returning strings from IShellFolder member functions }

  PSTRRet = ^TStrRet;
  {$EXTERNALSYM _STRRET}
  _STRRET = record
     uType: UINT;              { One of the STRRET_* values }
     case Integer of
       0: (pOleStr: LPWSTR);                    { must be freed by caller of GetDisplayNameOf }
       1: (pStr: LPSTR);                        { NOT USED }
       2: (uOffset: UINT);                      { Offset into SHITEMID (ANSI) }
       3: (cStr: array[0..MAX_PATH-1] of Char); { Buffer to fill in }
    end;
  TStrRet = _STRRET;
  {$EXTERNALSYM STRRET}
  STRRET = _STRRET;

 { IShellDetails is supported on Win9x and NT4; for >= NT5 use IShellFolder2 }
  PShellDetails = ^TShellDetails;
  {$EXTERNALSYM _SHELLDETAILS}
  _SHELLDETAILS = record
    fmt,
    cxChar: Integer;
    str: STRRET;
  end;
  TShellDetails = _SHELLDETAILS;
  {$EXTERNALSYM SHELLDETAILS}
  SHELLDETAILS = _SHELLDETAILS;

  IShellDetails = interface(IUnknown)
    [SID_IShellDetails]
    function GetDetailsOf(pidl: PItemIDList; iColumn: UINT;
      var pDetails: TShellDetails): HResult; stdcall;
    function ColumnClick(iColumn: UINT): HResult; stdcall;
  end;

{ SHGetPathFromIDList }

{ This function assumes the size of the buffer (MAX_PATH). The pidl
  should point to a file system object. }

{$EXTERNALSYM SHGetPathFromIDList}
function SHGetPathFromIDList(pidl: PItemIDList; pszPath: PChar): BOOL; stdcall;
{$EXTERNALSYM SHGetPathFromIDListA}
function SHGetPathFromIDListA(pidl: PItemIDList; pszPath: PAnsiChar): BOOL; stdcall;
{$EXTERNALSYM SHGetPathFromIDListW}
function SHGetPathFromIDListW(pidl: PItemIDList; pszPath: PWideChar): BOOL; stdcall;

{ SHGetSpecialFolderLocation }

{ Caller should use SHGetMalloc to obtain an allocator that can free the pidl }

const
{ registry entries for special paths are kept in : }

  {$EXTERNALSYM REGSTR_PATH_SPECIAL_FOLDERS}
  REGSTR_PATH_SPECIAL_FOLDERS   = REGSTR_PATH_EXPLORER + '\Shell Folders';
  {$EXTERNALSYM CSIDL_DESKTOP}
  CSIDL_DESKTOP                       = $0000;
  {$EXTERNALSYM CSIDL_INTERNET}
  CSIDL_INTERNET                      = $0001;
  {$EXTERNALSYM CSIDL_PROGRAMS}
  CSIDL_PROGRAMS                      = $0002;
  {$EXTERNALSYM CSIDL_CONTROLS}
  CSIDL_CONTROLS                      = $0003;
  {$EXTERNALSYM CSIDL_PRINTERS}
  CSIDL_PRINTERS                      = $0004;
  {$EXTERNALSYM CSIDL_PERSONAL}
  CSIDL_PERSONAL                      = $0005;
  {$EXTERNALSYM CSIDL_FAVORITES}
  CSIDL_FAVORITES                     = $0006;
  {$EXTERNALSYM CSIDL_STARTUP}
  CSIDL_STARTUP                       = $0007;
  {$EXTERNALSYM CSIDL_RECENT}
  CSIDL_RECENT                        = $0008;
  {$EXTERNALSYM CSIDL_SENDTO}
  CSIDL_SENDTO                        = $0009;
  {$EXTERNALSYM CSIDL_BITBUCKET}
  CSIDL_BITBUCKET                     = $000a;
  {$EXTERNALSYM CSIDL_STARTMENU}
  CSIDL_STARTMENU                     = $000b;
  {$EXTERNALSYM CSIDL_DESKTOPDIRECTORY}
  CSIDL_DESKTOPDIRECTORY              = $0010;
  {$EXTERNALSYM CSIDL_DRIVES}
  CSIDL_DRIVES                        = $0011;
  {$EXTERNALSYM CSIDL_NETWORK}
  CSIDL_NETWORK                       = $0012;
  {$EXTERNALSYM CSIDL_NETHOOD}
  CSIDL_NETHOOD                       = $0013;
  {$EXTERNALSYM CSIDL_FONTS}
  CSIDL_FONTS                         = $0014;
  {$EXTERNALSYM CSIDL_TEMPLATES}
  CSIDL_TEMPLATES                     = $0015;
  {$EXTERNALSYM CSIDL_COMMON_STARTMENU}
  CSIDL_COMMON_STARTMENU              = $0016;
  {$EXTERNALSYM CSIDL_COMMON_PROGRAMS}
  CSIDL_COMMON_PROGRAMS               = $0017;
  {$EXTERNALSYM CSIDL_COMMON_STARTUP}
  CSIDL_COMMON_STARTUP                = $0018;
  {$EXTERNALSYM CSIDL_COMMON_DESKTOPDIRECTORY}
  CSIDL_COMMON_DESKTOPDIRECTORY       = $0019;
  {$EXTERNALSYM CSIDL_APPDATA}
  CSIDL_APPDATA                       = $001a;
  {$EXTERNALSYM CSIDL_PRINTHOOD}
  CSIDL_PRINTHOOD                     = $001b;
  {$EXTERNALSYM CSIDL_ALTSTARTUP}
  CSIDL_ALTSTARTUP                = $001d;         // DBCS
  {$EXTERNALSYM CSIDL_COMMON_ALTSTARTUP}
  CSIDL_COMMON_ALTSTARTUP         = $001e;         // DBCS
  {$EXTERNALSYM CSIDL_COMMON_FAVORITES}
  CSIDL_COMMON_FAVORITES          = $001f;
  {$EXTERNALSYM CSIDL_INTERNET_CACHE}
  CSIDL_INTERNET_CACHE            = $0020;
  {$EXTERNALSYM CSIDL_COOKIES}
  CSIDL_COOKIES                   = $0021;
  {$EXTERNALSYM CSIDL_HISTORY}
  CSIDL_HISTORY                   = $0022;

{$EXTERNALSYM SHGetSpecialFolderLocation}
function SHGetSpecialFolderLocation(hwndOwner: HWND; nFolder: Integer;
  var ppidl: PItemIDList): HResult; stdcall;

function SHGetSpecialFolderPath(hwndOwner: HWND; lpszPath: PChar;
  nFolder: Integer; fCreate: BOOL): BOOL; stdcall;
{$EXTERNALSYM SHGetSpecialFolderPath}
function SHGetSpecialFolderPathA(hwndOwner: HWND; lpszPath: PAnsiChar;
  nFolder: Integer; fCreate: BOOL): BOOL; stdcall;
{$EXTERNALSYM SHGetSpecialFolderPathA}
function SHGetSpecialFolderPathW(hwndOwner: HWND; lpszPath: PWideChar;
  nFolder: Integer; fCreate: BOOL): BOOL; stdcall;
{$EXTERNALSYM SHGetSpecialFolderPathW}

{ SHBrowseForFolder API }

type
  {$EXTERNALSYM BFFCALLBACK}
  BFFCALLBACK = function(Wnd: HWND; uMsg: UINT; lParam, lpData: LPARAM): Integer stdcall;
  TFNBFFCallBack = type BFFCALLBACK;

  PBrowseInfoA = ^TBrowseInfoA;
  PBrowseInfoW = ^TBrowseInfoW;
  PBrowseInfo = PBrowseInfoA;
  {$EXTERNALSYM _browseinfoA}
  _browseinfoA = record
    hwndOwner: HWND;
    pidlRoot: PItemIDList;
    pszDisplayName: PAnsiChar;  { Return display name of item selected. }
    lpszTitle: PAnsiChar;      { text to go in the banner over the tree. }
    ulFlags: UINT;           { Flags that control the return stuff }
    lpfn: TFNBFFCallBack;
    lParam: LPARAM;          { extra info that's passed back in callbacks }
    iImage: Integer;         { output var: where to return the Image index. }
  end;
  {$EXTERNALSYM _browseinfoW}
  _browseinfoW = record
    hwndOwner: HWND;
    pidlRoot: PItemIDList;
    pszDisplayName: PWideChar;  { Return display name of item selected. }
    lpszTitle: PWideChar;      { text to go in the banner over the tree. }
    ulFlags: UINT;           { Flags that control the return stuff }
    lpfn: TFNBFFCallBack;
    lParam: LPARAM;          { extra info that's passed back in callbacks }
    iImage: Integer;         { output var: where to return the Image index. }
  end;
  {$EXTERNALSYM _browseinfo}
  _browseinfo = _browseinfoA;
  TBrowseInfoA = _browseinfoA;
  TBrowseInfoW = _browseinfoW;
  TBrowseInfo = TBrowseInfoA;
  {$EXTERNALSYM BROWSEINFOA}
  BROWSEINFOA = _browseinfoA;
  {$EXTERNALSYM BROWSEINFOW}
  BROWSEINFOW = _browseinfoW;
  {$EXTERNALSYM BROWSEINFO}
  BROWSEINFO = BROWSEINFOA;

const
{ Browsing for directory. }

  {$EXTERNALSYM BIF_RETURNONLYFSDIRS}
  BIF_RETURNONLYFSDIRS   = $0001;  { For finding a folder to start document searching }
  {$EXTERNALSYM BIF_DONTGOBELOWDOMAIN}
  BIF_DONTGOBELOWDOMAIN  = $0002;  { For starting the Find Computer }
  {$EXTERNALSYM BIF_STATUSTEXT}
  BIF_STATUSTEXT         = $0004;
  {$EXTERNALSYM BIF_RETURNFSANCESTORS}
  BIF_RETURNFSANCESTORS  = $0008;
  {$EXTERNALSYM BIF_EDITBOX}
  BIF_EDITBOX            = $0010;
  {$EXTERNALSYM BIF_VALIDATE}
  BIF_VALIDATE           = $0020;  { insist on valid result (or CANCEL) }

  {$EXTERNALSYM BIF_BROWSEFORCOMPUTER}
  BIF_BROWSEFORCOMPUTER  = $1000;  { Browsing for Computers. }
  {$EXTERNALSYM BIF_BROWSEFORPRINTER}
  BIF_BROWSEFORPRINTER   = $2000;  { Browsing for Printers }
  {$EXTERNALSYM BIF_BROWSEINCLUDEFILES}
  BIF_BROWSEINCLUDEFILES = $4000;  { Browsing for Everything }

{ message from browser }

  {$EXTERNALSYM BFFM_INITIALIZED}
  BFFM_INITIALIZED       = 1;
  {$EXTERNALSYM BFFM_SELCHANGED}
  BFFM_SELCHANGED        = 2;
  {$EXTERNALSYM BFFM_VALIDATEFAILEDA}
  BFFM_VALIDATEFAILEDA   = 3;   { lParam:szPath ret:1(cont),0(EndDialog) }
  {$EXTERNALSYM BFFM_VALIDATEFAILEDW}
  BFFM_VALIDATEFAILEDW   = 4;   { lParam:wzPath ret:1(cont),0(EndDialog) }

{ messages to browser }

  {$EXTERNALSYM BFFM_SETSTATUSTEXTA}
  BFFM_SETSTATUSTEXTA         = WM_USER + 100;
  {$EXTERNALSYM BFFM_ENABLEOK}
  BFFM_ENABLEOK               = WM_USER + 101;
  {$EXTERNALSYM BFFM_SETSELECTIONA}
  BFFM_SETSELECTIONA          = WM_USER + 102;
  {$EXTERNALSYM BFFM_SETSELECTIONW}
  BFFM_SETSELECTIONW          = WM_USER + 103;
  {$EXTERNALSYM BFFM_SETSTATUSTEXTW}
  BFFM_SETSTATUSTEXTW         = WM_USER + 104;









  {$EXTERNALSYM BFFM_VALIDATEFAILED}
  BFFM_VALIDATEFAILED     = BFFM_VALIDATEFAILEDA;
  {$EXTERNALSYM BFFM_SETSTATUSTEXT}
  BFFM_SETSTATUSTEXT      = BFFM_SETSTATUSTEXTA;
  {$EXTERNALSYM BFFM_SETSELECTION}
  BFFM_SETSELECTION       = BFFM_SETSELECTIONA;


{$EXTERNALSYM SHBrowseForFolder}
function SHBrowseForFolder(var lpbi: TBrowseInfo): PItemIDList; stdcall;
{$EXTERNALSYM SHBrowseForFolderA}
function SHBrowseForFolderA(var lpbi: TBrowseInfoA): PItemIDList; stdcall;
{$EXTERNALSYM SHBrowseForFolderW}
function SHBrowseForFolderW(var lpbi: TBrowseInfoW): PItemIDList; stdcall;

{ SHLoadInProc }

{ When this function is called, the shell calls CoCreateInstance
  (or equivalent) with CLSCTX_INPROC_SERVER and the specified CLSID
  from within the shell's process and release it immediately. }

{$EXTERNALSYM SHLoadInProc}
function SHLoadInProc(rclsid: TCLSID): HRESULT; stdcall;

{ IEnumIDList interface }

{ IShellFolder.EnumObjects member returns an IEnumIDList object. }

type
  {$EXTERNALSYM IEnumIDList}
  IEnumIDList = interface(IUnknown)
    [SID_IEnumIDList]
    function Next(celt: ULONG; out rgelt: PItemIDList;
      var pceltFetched: ULONG): HResult; stdcall;
    function Skip(celt: ULONG): HResult; stdcall;
    function Reset: HResult; stdcall;
    function Clone(out ppenum: IEnumIDList): HResult; stdcall;
  end;

{ IShellFolder interface }

{ [Member functions] }

{ IShellFolder.BindToObject(pidl, pbc, riid, ppvOut)
  This function returns an instance of a sub-folder which is specified
  by the IDList (pidl).
 IShellFolder.BindToStorage(pidl, pbc, riid, ppvObj)
   This function returns a storage instance of a sub-folder which is
   specified by the IDList (pidl). The shell never calls this member
   function in the first release of Win95.
 IShellFolder.CompareIDs(lParam, pidl1, pidl2)
   This function compares two IDLists and returns the result. The shell
   explorer always passes 0 as lParam, which indicates 'sort by name'.
   It should return 0 (as CODE of the scode), if two id indicates the
   same object; negative value if pidl1 should be placed before pidl2;
   positive value if pidl2 should be placed before pidl1.
 IShellFolder.CreateViewObject(hwndOwner, riid, ppvOut)
   This function creates a view object of the folder itself. The view
   object is a difference instance from the shell folder object.
   "hwndOwner" can be used  as the owner window of its dialog box or
      menu during the lifetime of the view object.
   instance which has only one reference count. The explorer may create
   more than one instances of view object from one shell folder object
   and treat them as separate instances.
 IShellFolder.GetAttributesOf(cidl, apidl, prgfInOut)
   This function returns the attributes of specified objects in that
   folder. 'cidl' and 'apidl' specifies objects. 'apidl' contains only
   simple IDLists. The explorer initializes *prgfInOut with a set of
   flags to be evaluated. The shell folder may optimize the operation
   by not returning unspecified flags.
 IShellFolder.GetUIObjectOf(hwndOwner, cidl, apidl, riid, prgfInOut, ppvOut)
   This function creates a UI object to be used for specified objects.
   The shell explorer passes either IID_IDataObject (for transfer operation)
   or IID_IContextMenu (for context menu operation) as riid.
 IShellFolder.GetDisplayNameOf
   This function returns the display name of the specified object.
   If the ID contains the display name (in the locale character set),
   it returns the offset to the name. Otherwise, it returns a pointer
   to the display name string (UNICODE), which is allocated by the
   task allocator, or fills in a buffer.
 IShellFolder.SetNameOf
   This function sets the display name of the specified object.
   If it changes the ID as well, it returns the new ID which is
   alocated by the task allocator. }

const
{ IShellFolder.GetDisplayNameOf/SetNameOf uFlags }

  {$EXTERNALSYM SHGDN_NORMAL}
  SHGDN_NORMAL           = 0;         { default (display purpose) }
  {$EXTERNALSYM SHGDN_INFOLDER}
  SHGDN_INFOLDER         = 1;         { displayed under a folder (relative) }

  {$EXTERNALSYM SHGDN_FOREDITING}
  SHGDN_FOREDITING       = $1000;     { for in-place editing text }
  {$EXTERNALSYM SHGDN_INCLUDE_NONFILESYS}
  SHGDN_INCLUDE_NONFILESYS = $2000;   { if not set, display names for shell
                                        name space items that are not in the
                                        file system will fail. }
  {$EXTERNALSYM SHGDN_FORADDRESSBAR}
  SHGDN_FORADDRESSBAR      = $4000;     { for displaying in the address (drives dropdown) bar }
  {$EXTERNALSYM SHGDN_FORPARSING}
  SHGDN_FORPARSING         = $8000;     { for ParseDisplayName or path }

{ IShellFolder.EnumObjects }

  {$EXTERNALSYM SHCONTF_FOLDERS}
  SHCONTF_FOLDERS         = 32;       { for shell browser }
  {$EXTERNALSYM SHCONTF_NONFOLDERS}
  SHCONTF_NONFOLDERS      = 64;       { for default view }
  {$EXTERNALSYM SHCONTF_INCLUDEHIDDEN}
  SHCONTF_INCLUDEHIDDEN   = 128;      { for hidden/system objects }

{ IShellFolder.GetAttributesOf flags }

  {$EXTERNALSYM SFGAO_CANCOPY}
  SFGAO_CANCOPY           = DROPEFFECT_COPY; { Objects can be copied }
  {$EXTERNALSYM SFGAO_CANMOVE}
  SFGAO_CANMOVE           = DROPEFFECT_MOVE; { Objects can be moved }
  {$EXTERNALSYM SFGAO_CANLINK}
  SFGAO_CANLINK           = DROPEFFECT_LINK; { Objects can be linked }
  {$EXTERNALSYM SFGAO_CANRENAME}
  SFGAO_CANRENAME         = $00000010;       { Objects can be renamed }
  {$EXTERNALSYM SFGAO_CANDELETE}
  SFGAO_CANDELETE         = $00000020;       { Objects can be deleted }
  {$EXTERNALSYM SFGAO_HASPROPSHEET}
  SFGAO_HASPROPSHEET      = $00000040;       { Objects have property sheets }
  {$EXTERNALSYM SFGAO_DROPTARGET}
  SFGAO_DROPTARGET        = $00000100;       { Objects are drop target }
  {$EXTERNALSYM SFGAO_CAPABILITYMASK}
  SFGAO_CAPABILITYMASK    = $00000177;
  {$EXTERNALSYM SFGAO_LINK}
  SFGAO_LINK              = $00010000;       { Shortcut (link) }
  {$EXTERNALSYM SFGAO_SHARE}
  SFGAO_SHARE             = $00020000;       { shared }
  {$EXTERNALSYM SFGAO_READONLY}
  SFGAO_READONLY          = $00040000;       { read-only }
  {$EXTERNALSYM SFGAO_GHOSTED}
  SFGAO_GHOSTED           = $00080000;       { ghosted icon }
  {$EXTERNALSYM SFGAO_HIDDEN}
  SFGAO_HIDDEN            = $00080000;       { hidden object }
  {$EXTERNALSYM SFGAO_DISPLAYATTRMASK}
  SFGAO_DISPLAYATTRMASK   = $000F0000;
  {$EXTERNALSYM SFGAO_FILESYSANCESTOR}
  SFGAO_FILESYSANCESTOR   = $10000000;       { It contains file system folder }
  {$EXTERNALSYM SFGAO_FOLDER}
  SFGAO_FOLDER            = $20000000;       { It's a folder. }
  {$EXTERNALSYM SFGAO_FILESYSTEM}
  SFGAO_FILESYSTEM        = $40000000;       { is a file system thing (file/folder/root) }
  {$EXTERNALSYM SFGAO_HASSUBFOLDER}
  SFGAO_HASSUBFOLDER      = $80000000;       { Expandable in the map pane }
  {$EXTERNALSYM SFGAO_CONTENTSMASK}
  SFGAO_CONTENTSMASK      = $80000000;
  {$EXTERNALSYM SFGAO_VALIDATE}
  SFGAO_VALIDATE          = $01000000;       { invalidate cached information }
  {$EXTERNALSYM SFGAO_REMOVABLE}
  SFGAO_REMOVABLE         = $02000000;       { is this removeable media? }
  {$EXTERNALSYM SFGAO_COMPRESSED}
  SFGAO_COMPRESSED        = $04000000;       { Object is compressed (use alt color) }
  {$EXTERNALSYM SFGAO_BROWSABLE}
  SFGAO_BROWSABLE         = $08000000;       { is in-place browsable }
  {$EXTERNALSYM SFGAO_NONENUMERATED}
  SFGAO_NONENUMERATED     = $00100000;       { is a non-enumerated object }
  {$EXTERNALSYM SFGAO_NEWCONTENT}
  SFGAO_NEWCONTENT        = $00200000;       { should show bold in explorer tree }

type
  {$EXTERNALSYM IShellFolder}
  IShellFolder = interface(IUnknown)
    [SID_IShellFolder]
    function ParseDisplayName(hwndOwner: HWND;
      pbcReserved: Pointer; lpszDisplayName: POLESTR; out pchEaten: ULONG;
      out ppidl: PItemIDList; var dwAttributes: ULONG): HResult; stdcall;
    function EnumObjects(hwndOwner: HWND; grfFlags: DWORD;
      out EnumIDList: IEnumIDList): HResult; stdcall;
    function BindToObject(pidl: PItemIDList; pbcReserved: Pointer;
      const riid: TIID; out ppvOut): HResult; stdcall;
    function BindToStorage(pidl: PItemIDList; pbcReserved: Pointer;
      const riid: TIID; out ppvObj): HResult; stdcall;
    function CompareIDs(lParam: LPARAM;
      pidl1, pidl2: PItemIDList): HResult; stdcall;
    function CreateViewObject(hwndOwner: HWND; const riid: TIID;
      out ppvOut): HResult; stdcall;
    function GetAttributesOf(cidl: UINT; var apidl: PItemIDList;
      var rgfInOut: UINT): HResult; stdcall;
    function GetUIObjectOf(hwndOwner: HWND; cidl: UINT; var apidl: PItemIDList;
      const riid: TIID; prgfInOut: Pointer; out ppvOut): HResult; stdcall;
    function GetDisplayNameOf(pidl: PItemIDList; uFlags: DWORD;
      var lpName: TStrRet): HResult; stdcall;
    function SetNameOf(hwndOwner: HWND; pidl: PItemIDList; lpszName: POLEStr;
      uFlags: DWORD; var ppidlOut: PItemIDList): HResult; stdcall;
  end;

  {$EXTERNALSYM PExtraSearch}
  PExtraSearch = ^TExtraSearch;
  {$EXTERNALSYM tagExtraSearch}
  tagExtraSearch = record
    guidSearch: TGUID;
    wszFriendlyName,
    wszMenuText: array[0..79] of WideChar;
    wszHelpText: array[0..MAX_PATH] of WideChar;
    wszUrl: array[0..2047] of WideChar;
    wszIcon,
    wszGreyIcon,
    wszClrIcon: array[0..MAX_PATH+10] of WideChar;
  end;
  {$EXTERNALSYM TExtraSearch}
  TExtraSearch = tagExtraSearch;

  {$EXTERNALSYM IEnumExtraSearch}
  IEnumExtraSearch = interface(IUnknown)
    [SID_IEnumExtraSearch]
    function Next(celt: ULONG; out rgelt: PExtraSearch;
      out pceltFetched: ULONG): HResult; stdcall;
    function Skip(celt: ULONG): HResult; stdcall;
    function Reset: HResult; stdcall;
    function Clone(out ppEnum: IEnumExtraSearch): HResult; stdcall;
  end;

const
  {IShellFolder2.GetDefaultColumnState Values}
  SHCOLSTATE_TYPE_STR     = $00000001;
  SHCOLSTATE_TYPE_INT     = $00000002;
  SHCOLSTATE_TYPE_DATE    = $00000003;
  SHCOLSTATE_TYPEMASK     = $0000000F;
  SHCOLSTATE_ONBYDEFAULT  = $00000010;   // should on by default in details view
  SHCOLSTATE_SLOW         = $00000020;   // will be slow to compute; do on a background thread
  SHCOLSTATE_EXTENDED     = $00000040;   // provided by a handler; not the folder
  SHCOLSTATE_SECONDARYUI  = $00000080;   // not displayed in context menu; but listed in the "More..." dialog
  SHCOLSTATE_HIDDEN       = $00000100;   // not displayed in the UI

type
  {$EXTERNALSYM PShColumnID}
  PShColumnID = ^TShColumnID;
  {$EXTERNALSYM SHCOLUMNID}
  SHCOLUMNID = record
    fmtid: TGUID;
    pid: DWORD;
  end;
  {$EXTERNALSYM TShColumnID}
  TShColumnID = SHCOLUMNID;

  {$EXTERNALSYM IShellFolder2}
  IShellFolder2 = interface(IShellFolder)
    [SID_IShellFolder2]
    function GetDefaultSearchGUID(out pguid: TGUID): HResult; stdcall;
    function EnumSearches(out ppEnum: IEnumExtraSearch): HResult; stdcall;
    function GetDefaultColumn(dwRes: DWORD; var pSort: ULONG;
      var pDisplay: ULONG): HResult; stdcall;
    function GetDefaultColumnState(iColumn: UINT; var pcsFlags: DWORD): HResult; stdcall;
    function GetDetailsEx(pidl: PItemIDList; const pscid: SHCOLUMNID;
      pv: POleVariant): HResult; stdcall;
    function GetDetailsOf(pidl: PItemIDList; iColumn: UINT;
      var psd: TShellDetails): HResult; stdcall;
    function MapNameToSCID(pwszName: LPCWSTR; var pscid: TShColumnID): HResult; stdcall;
  end;

{ Helper function which returns a IShellFolder interface to the desktop
  folder. This is equivalent to call CoCreateInstance with CLSID_ShellDesktop. }

{$EXTERNALSYM SHGetDesktopFolder}
function SHGetDesktopFolder(var ppshf: IShellFolder): HResult; stdcall;

{ IInputObjectSite/IInputObject interfaces

 These interfaces allow us (or ISVs) to install/update external Internet
 Toolbar for IE and the shell. The frame will simply get the CLSID from
 registry (to be defined) and CoCreateInstance it. }

{ IInputObjectSite interface }
{
 A site implements this interface so the object can communicate
 focus change to it.

 [Member functions]

 IInputObjectSite::OnFocusChangeIS(punkObj, fSetFocus)
   Object (punkObj) is getting or losing the focus.
}
type
  {$EXTERNALSYM IInputObjectSite}
  IInputObjectSite = interface(IUnknown)
    [SID_IInputObjectSite]
    function OnFocusChangeIS(punkObj: IUnknown; fSetFocus: BOOL): HResult; stdcall;
  end;

{ IInputObject interface }
{
   An object implements this interface so the site can communicate
 activation and accelerator events to it.

 [Member functions]

 IInputObject::UIActivateIO(fActivate, lpMsg)
   Activates or deactivates the object.  lpMsg may be NULL.  Returns
   S_OK if the activation succeeded.

 IInputObject::HasFocusIO()
   Returns S_OK if the object has the focus, S_FALSE if not.

 IInputObject::TranslateAcceleratorIO(lpMsg)
   Allow the object to process the message.  Returns S_OK if the
   message was processed (eaten).
}
  {$EXTERNALSYM IInputObject}
  IInputObject = interface(IUnknown)
    [SID_IInputObject]
    function UIActivateIO(fActivate: BOOL; var lpMsg: TMsg): HResult; stdcall;
    function HasFocusIO: HResult; stdcall;
    function TranslateAcceleratorIO(var lpMsg: TMsg): HResult; stdcall;
  end;


{ ========================================================================== }
{ IDockingWindowSite/IDockingWindow/IDockingWindowFrame interfaces }
{
 These interfaces allow us (or ISVs) to install/update external Internet
 Toolbar for IE and the shell. The frame will simply get the CLSID from
 registry (to be defined) and CoCreateInstance it.

{ IDockingWindowSite interface }
{
  A site implements this interface so the object can negotiate for
 and inquire about real estate on the site.

 [Member functions]

 IDockingWindowSite::GetBorderDW(punkObj, prcBorder)
   Site returns the bounding rectangle of the given source object
   (punkObj).

 IDockingWindowSite::RequestBorderSpaceDW(punkObj, pbw)
   Object requests that the site makes room for it, as specified in
   *pbw.

 IDockingWindowSite::SetBorderSpaceDW(punkObj, pbw)
   Object requests that the site set the border spacing to the size
   specified in *pbw.
}
  {$EXTERNALSYM IDockingWindowSite}
  IDockingWindowSite = interface(IOleWindow)
    [SID_IDockingWindowSite]
    function GetBorderDW(punkObj: IUnknown; var prcBorder: TRect): HResult; stdcall;
    function RequestBorderSpaceDW(punkObj: IUnknown; var pbw: TBorderWidths): HResult; stdcall;
    function SetBorderSpaceDW(punkObj: IUnknown; var pbw: TBorderWidths): HResult; stdcall;
  end;

{ IDockingWindowFrame interface }
{
 [Member functions]

 IDockingWindowFrame::AddToolbar(punkSrc, pwszItem, dwReserved)

 IDockingWindowFrame::RemoveToolbar(punkSrc, dwRemoveFlags)

 IDockingWindowFrame::FindToolbar(pwszItem, riid, ppvObj)
}
const
  // flags for RemoveToolbar
  {$EXTERNALSYM DWFRF_NORMAL}
  DWFRF_NORMAL            = $0000;
  {$EXTERNALSYM DWFRF_DELETECONFIGDATA}
  DWFRF_DELETECONFIGDATA  = $0001;

  // flags for AddToolbar
  {$EXTERNALSYM DWFAF_HIDDEN}
  DWFAF_HIDDEN            = $0001;   { add hidden }

type
  {$EXTERNALSYM IDockingWindowFrame}
  IDockingWindowFrame = interface(IOleWindow)
    [SID_IDockingWindowFrame]
    function AddToolbar(punkSrc: IUnknown; pwszItem: PWideChar;
      dwAddFlags: DWORD): HResult; stdcall;
    function RemoveToolbar(punkSrc: IUnknown; dwRemoveFlags: DWORD): HResult; stdcall;
    function FindToolbar(pwszItem: PWideChar; const riid: TIID;
      var ppvObj: Pointer): HResult; stdcall;
  end;

{ IDockingWindow interface }
{
 An object (docking window) implements this interface so the site can
 communicate with it.  An example of a docking window is a toolbar.

 [Member functions]

 IDockingWindow::ShowDW(fShow)
   Shows or hides the docking window.

 IDockingWindow::CloseDW(dwReserved)
   Closes the docking window.  dwReserved must be 0.

 IDockingWindow::ResizeBorderDW(prcBorder, punkToolbarSite, fReserved)
   Resizes the docking window's border to *prcBorder.  fReserved must
   be 0.
 IObjectWithSite::SetSite(punkSite)
   IDockingWindow usually paired with IObjectWithSite.
   Provides the IUnknown pointer of the site to the docking window.
}
  {$EXTERNALSYM IDockingWindow}
  IDockingWindow = interface(IOleWindow)
    [SID_IDockingWindow]
    function ShowDW(fShow: BOOL): HResult; stdcall;
    function CloseDW(dwReserved: DWORD): HResult; stdcall;
    function ResizeBorderDW(var prcBorder: TRect; punkToolbarSite: IUnknown;
      fReserved: BOOL): HResult; stdcall;
  end;

{ IDeskBand interface }
{
 [Member functions]

 IDeskBand::GetBandInfo(dwBandID, dwViewMode, pdbi)
   Returns info on the given band in *pdbi, according to the mask
   field in the DESKBANDINFO structure and the given viewmode.
}
const
  // Mask values for DESKBANDINFO
  {$EXTERNALSYM DBIM_MINSIZE}
  DBIM_MINSIZE    = $0001;
  {$EXTERNALSYM DBIM_MAXSIZE}
  DBIM_MAXSIZE    = $0002;
  {$EXTERNALSYM DBIM_INTEGRAL}
  DBIM_INTEGRAL   = $0004;
  {$EXTERNALSYM DBIM_ACTUAL}
  DBIM_ACTUAL     = $0008;
  {$EXTERNALSYM DBIM_TITLE}
  DBIM_TITLE      = $0010;
  {$EXTERNALSYM DBIM_MODEFLAGS}
  DBIM_MODEFLAGS  = $0020;
  {$EXTERNALSYM DBIM_BKCOLOR}
  DBIM_BKCOLOR    = $0040;

type
  {$EXTERNALSYM DESKBANDINFO}
  DESKBANDINFO = packed record
    dwMask: DWORD;
    ptMinSize: TPointL;
    ptMaxSize: TPointL;
    ptIntegral: TPointL;
    ptActual: TPointL;
    wszTitle: array[0..255] of WideChar;
    dwModeFlags: DWORD;
    crBkgnd: COLORREF;
  end;
  PDeskBandInfo = ^TDeskBandInfo;
  TDeskBandInfo = DESKBANDINFO;

const
  // DESKBANDINFO dwModeFlags values
  {$EXTERNALSYM DBIMF_NORMAL}
  DBIMF_NORMAL            = $0000;
  {$EXTERNALSYM DBIMF_VARIABLEHEIGHT}
  DBIMF_VARIABLEHEIGHT    = $0008;
  {$EXTERNALSYM DBIMF_DEBOSSED}
  DBIMF_DEBOSSED          = $0020;
  {$EXTERNALSYM DBIMF_BKCOLOR}
  DBIMF_BKCOLOR           = $0040;

  // GetBandInfo view mode values
  {$EXTERNALSYM DBIF_VIEWMODE_NORMAL}
  DBIF_VIEWMODE_NORMAL         = $0000;
  {$EXTERNALSYM DBIF_VIEWMODE_VERTICAL}
  DBIF_VIEWMODE_VERTICAL       = $0001;
  {$EXTERNALSYM DBIF_VIEWMODE_FLOATING}
  DBIF_VIEWMODE_FLOATING       = $0002;
  {$EXTERNALSYM DBIF_VIEWMODE_TRANSPARENT}
  DBIF_VIEWMODE_TRANSPARENT    = $0004;

type
  {$EXTERNALSYM IDeskBand}
  IDeskBand = interface(IDockingWindow)
    [SID_IDeskBand]
    function GetBandInfo(dwBandID, dwViewMode: DWORD; var pdbi: TDeskBandInfo):
      HResult; stdcall;
  end;

const
  // Command Target IDs
  {$EXTERNALSYM DBID_BANDINFOCHANGED}
  DBID_BANDINFOCHANGED = 0;
    //  tmp! replace w/ cbs::Select
  {$EXTERNALSYM DBID_SHOWONLY}
  DBID_SHOWONLY        = 1;
  {$EXTERNALSYM DBID_MAXIMIZEBAND}
  DBID_MAXIMIZEBAND    = 2;  // Maximize the specified band (VT_UI4 == dwID)

type
  //  Flags and structures used by IActiveDesktop

  {$EXTERNALSYM _tagWALLPAPEROPT}
  _tagWALLPAPEROPT = packed record
    dwSize: DWORD;     // size of this Structure.
    dwStyle: DWORD;    // WPSTYLE_* mentioned above
  end;
  PWallPaperOpt = ^TWallPaperOpt;
  {$EXTERNALSYM PWallPaperOpt }
  TWallPaperOpt = _tagWALLPAPEROPT;
  {$EXTERNALSYM TWallPaperOpt }

  {$EXTERNALSYM _tagCOMPONENTSOPT}
  _tagCOMPONENTSOPT = packed record
    dwSize: DWORD;             // Size of this structure
    fEnableComponents: BOOL;   // Enable components?
    fActiveDesktop: BOOL;      // Active desktop enabled ?
  end;
  PComponentsOpt = ^TComponentsOpt;
  {$EXTERNALSYM PComponentsOpt }
  TComponentsOpt = _tagCOMPONENTSOPT;
  {$EXTERNALSYM TComponentsOpt }

  {$EXTERNALSYM _tagCOMPPOS}
  _tagCOMPPOS = packed record
    dwSize: DWORD;             //Size of this structure
    iLeft: Integer;            //Left of top-left corner in screen co-ordinates.
    iTop: Integer;             //Top of top-left corner in screen co-ordinates.
    dwWidth: DWORD;            // Width in pixels.
    dwHeight: DWORD;           // Height in pixels.
    izIndex: Integer;          // Indicates the Z-order of the component.
    fCanResize: BOOL;          // Is the component resizeable?
    fCanResizeX: BOOL;         // Resizeable in X-direction?
    fCanResizeY: BOOL;         // Resizeable in Y-direction?
    iPreferredLeftPercent: Integer;  //Left of top-left corner as percent of screen width
    iPreferredTopPercent: Integer;   //Top of top-left corner as percent of screen height
  end;
  PCompPos = ^TCompPos;
  {$EXTERNALSYM PCompPos }
  TCompPos = _tagCOMPPOS;
  {$EXTERNALSYM TCompPos }

const
  {$EXTERNALSYM COMPONENT_TOP}
  COMPONENT_TOP = $7fffffff;  // izOrder value meaning component is at the top

  // iCompType values
  {$EXTERNALSYM COMP_TYPE_HTMLDOC}
  COMP_TYPE_HTMLDOC       = 0;
  {$EXTERNALSYM COMP_TYPE_PICTURE}
  COMP_TYPE_PICTURE       = 1;
  {$EXTERNALSYM COMP_TYPE_WEBSITE}
  COMP_TYPE_WEBSITE       = 2;
  {$EXTERNALSYM COMP_TYPE_CONTROL}
  COMP_TYPE_CONTROL       = 3;
  {$EXTERNALSYM COMP_TYPE_CFHTML}
  COMP_TYPE_CFHTML        = 4;
  {$EXTERNALSYM COMP_TYPE_MAX}
  COMP_TYPE_MAX           = 4;

type
  {$EXTERNALSYM _tagCOMPONENT}
  _tagCOMPONENT = packed record
    dwSize: DWORD;            // Size of this structure
    dwID: DWORD;              // Reserved: Set it always to zero.
    iComponentType: Integer;  // One of COMP_TYPE_*
    fChecked: BOOL;           // Is this component enabled?
    fDirty: BOOL;             // Had the component been modified and not yet saved to disk?
    fNoScroll: BOOL;          // Is the component scrollable?
    cpPos: TCompPos;          // Width, height etc.,
    wszFriendlyName: array[0..MAX_PATH - 1] of WideChar;  // Friendly name of component.
    wszSource: array[0..INTERNET_MAX_URL_LENGTH - 1] of WideChar; //URL of the component.
    wszSubscribedURL: array[0..INTERNET_MAX_URL_LENGTH - 1] of WideChar; //Subscrined URL
  end;
  PShComponent = ^TShComponent;
  {$EXTERNALSYM PShComponent }
  TShComponent = _tagCOMPONENT;
  {$EXTERNALSYM TShComponent }

const
  // Flags for IActiveDesktop::ApplyChanges()
  {$EXTERNALSYM AD_APPLY_SAVE}
  AD_APPLY_SAVE         = $00000001;
  {$EXTERNALSYM AD_APPLY_HTMLGEN}
  AD_APPLY_HTMLGEN      = $00000002;
  {$EXTERNALSYM AD_APPLY_REFRESH}
  AD_APPLY_REFRESH      = $00000004;
  {$EXTERNALSYM AD_APPLY_ALL}
  AD_APPLY_ALL          = AD_APPLY_SAVE or AD_APPLY_HTMLGEN or AD_APPLY_REFRESH;
  {$EXTERNALSYM AD_APPLY_FORCE}
  AD_APPLY_FORCE        = $00000008;
  {$EXTERNALSYM AD_APPLY_BUFFERED_REFRESH}
  AD_APPLY_BUFFERED_REFRESH = $00000010;

  // Flags for IActiveDesktop::GetWallpaperOptions()
  //           IActiveDesktop::SetWallpaperOptions()
  {$EXTERNALSYM WPSTYLE_CENTER}
  WPSTYLE_CENTER      = 0;
  {$EXTERNALSYM WPSTYLE_TILE}
  WPSTYLE_TILE        = 1;
  {$EXTERNALSYM WPSTYLE_STRETCH}
  WPSTYLE_STRETCH     = 2;
  {$EXTERNALSYM WPSTYLE_MAX}
  WPSTYLE_MAX         = 3;

  // Flags for IActiveDesktop::ModifyComponent()
  {$EXTERNALSYM COMP_ELEM_TYPE}
  COMP_ELEM_TYPE          = $00000001;
  {$EXTERNALSYM COMP_ELEM_CHECKED}
  COMP_ELEM_CHECKED       = $00000002;
  {$EXTERNALSYM COMP_ELEM_DIRTY}
  COMP_ELEM_DIRTY         = $00000004;
  {$EXTERNALSYM COMP_ELEM_NOSCROLL}
  COMP_ELEM_NOSCROLL      = $00000008;
  {$EXTERNALSYM COMP_ELEM_POS_LEFT}
  COMP_ELEM_POS_LEFT      = $00000010;
  {$EXTERNALSYM COMP_ELEM_POS_TOP}
  COMP_ELEM_POS_TOP       = $00000020;
  {$EXTERNALSYM COMP_ELEM_SIZE_WIDTH}
  COMP_ELEM_SIZE_WIDTH    = $00000040;
  {$EXTERNALSYM COMP_ELEM_SIZE_HEIGHT}
  COMP_ELEM_SIZE_HEIGHT   = $00000080;
  {$EXTERNALSYM COMP_ELEM_POS_ZINDEX}
  COMP_ELEM_POS_ZINDEX    = $00000100;
  {$EXTERNALSYM COMP_ELEM_SOURCE}
  COMP_ELEM_SOURCE        = $00000200;
  {$EXTERNALSYM COMP_ELEM_FRIENDLYNAME}
  COMP_ELEM_FRIENDLYNAME  = $00000400;
  {$EXTERNALSYM COMP_ELEM_SUBSCRIBEDURL}
  COMP_ELEM_SUBSCRIBEDURL = $00000800;

  {$EXTERNALSYM COMP_ELEM_ALL}
  COMP_ELEM_ALL           = COMP_ELEM_TYPE or COMP_ELEM_CHECKED or
                            COMP_ELEM_DIRTY or COMP_ELEM_NOSCROLL or
                            COMP_ELEM_POS_LEFT or COMP_ELEM_SIZE_WIDTH  or
                            COMP_ELEM_SIZE_HEIGHT or COMP_ELEM_POS_ZINDEX or
                            COMP_ELEM_SOURCE or COMP_ELEM_FRIENDLYNAME;

  // Flags for IActiveDesktop::AddUrl()
  {$EXTERNALSYM ADDURL_SILENT}
  ADDURL_SILENT           = $0001;

type
  // Flags for IActiveDesktop::AddDesktopItemWithUI()
  {$EXTERNALSYM tagDTI_ADTIWUI}
  tagDTI_ADTIWUI = (DTI_ADDUI_DEFAULT, DTI_ADDUI_DISPSUBWIZARD);

{ Interface for manipulating the Active Desktop. }

  {$EXTERNALSYM IActiveDesktop}
  IActiveDesktop = interface(IUnknown)
    [SID_IActiveDesktop]
    function ApplyChanges(dwFlags: DWORD): HResult; stdcall;
    function GetWallpaper(pwszWallpaper: PWideChar; cchWallpaper: UINT;
      dwReserved: DWORD): HResult; stdcall;
    function SetWallpaper(pwszWallpaper: PWideChar; dwReserved: DWORD): HResult; stdcall;
    function GetWallpaperOptions(var pwpo: TWallPaperOpt; dwReserved: DWORD): HResult; stdcall;
    function SetWallpaperOptions(var pwpo: TWallPaperOpt; dwReserved: DWORD): HResult; stdcall;
    function GetPattern(pwszPattern: PWideChar; cchPattern: UINT;
      dwReserved: DWORD): HResult; stdcall;
    function SetPattern(pwszPattern: PWideChar; dwReserved: DWORD): HResult; stdcall;
    function GetDesktopItemOptions(var pco: TComponentsOpt; dwReserved: DWORD):
      HResult; stdcall;
    function SetDesktopItemOptions(var pco: TComponentsOpt; dwReserved: DWORD):
      HResult; stdcall;
    function AddDesktopItem(var pcomp: TShComponent; dwReserved: DWORD): HResult; stdcall;
    function AddDesktopItemWithUI(hwnd: HWND; var pcomp: TShComponent;
      dwReserved: DWORD): HResult; stdcall;
    function ModifyDesktopItem(var pcomp: TShComponent; dwReserved: DWORD): HResult; stdcall;
    function RemoveDesktopItem(var pcomp: TShComponent; dwReserved: DWORD): HResult; stdcall;
    function GetDesktopItemCount(var lpiCount: Integer; dwReserved: DWORD): HResult; stdcall;
    function GetDesktopItem(nComponent: Integer; var pcomp: TShComponent;
      dwReserved: DWORD): HResult; stdcall;
    function GetDesktopItemByID(dwID: DWORD; var pcomp: TShComponent;
      dwReserved: DWORD): HResult; stdcall;
    function GenerateDesktopItemHtml(pwszFileName: PWideChar;
      var pcomp: TShComponent; dwReserved: DWORD): HResult; stdcall;
    function AddUrl(hwnd: HWND; pszSource: PWideChar; var pcomp: TShComponent;
      dwFlags: DWORD): HResult; stdcall;
    function GetDesktopItemBySource(pwszSource: PWideChar; var pcomp: TShComponent;
      dwReserved: DWORD): HResult; stdcall;
  end;

const
{ Clipboard format which may be supported by IDataObject from system
  defined shell folders (such as directories, network, ...). }

  {$EXTERNALSYM CFSTR_SHELLIDLIST}
  CFSTR_SHELLIDLIST           = 'Shell IDList Array';     { CF_IDLIST }
  {$EXTERNALSYM CFSTR_SHELLIDLISTOFFSET}
  CFSTR_SHELLIDLISTOFFSET     = 'Shell Object Offsets';   { CF_OBJECTPOSITIONS }
  {$EXTERNALSYM CFSTR_NETRESOURCES}
  CFSTR_NETRESOURCES          = 'Net Resource';           { CF_NETRESOURCE }
  {$EXTERNALSYM CFSTR_FILEDESCRIPTORA}
  CFSTR_FILEDESCRIPTORA       = 'FileGroupDescriptor';    { CF_FILEGROUPDESCRIPTORA }
  {$EXTERNALSYM CFSTR_FILEDESCRIPTORW}
  CFSTR_FILEDESCRIPTORW       = 'FileGroupDescriptorW';   { CF_FILEGROUPDESCRIPTORW }
  {$EXTERNALSYM CFSTR_FILECONTENTS}
  CFSTR_FILECONTENTS          = 'FileContents';           { CF_FILECONTENTS }
  {$EXTERNALSYM CFSTR_FILENAMEA}
  CFSTR_FILENAMEA             = 'FileName';               { CF_FILENAMEA }
  {$EXTERNALSYM CFSTR_FILENAMEW}
  CFSTR_FILENAMEW             = 'FileNameW';              { CF_FILENAMEW }
  {$EXTERNALSYM CFSTR_PRINTERGROUP}
  CFSTR_PRINTERGROUP          = 'PrinterFriendlyName';    { CF_PRINTERS }
  {$EXTERNALSYM CFSTR_FILENAMEMAPA}
  CFSTR_FILENAMEMAPA          = 'FileNameMap';            { CF_FILENAMEMAPA }
  {$EXTERNALSYM CFSTR_FILENAMEMAPW}
  CFSTR_FILENAMEMAPW          = 'FileNameMapW';           { CF_FILENAMEMAPW }
  {$EXTERNALSYM CFSTR_SHELLURL}
  CFSTR_SHELLURL              = 'UniformResourceLocator';
  {$EXTERNALSYM CFSTR_PREFERREDDROPEFFECT}
  CFSTR_PREFERREDDROPEFFECT   = 'Preferred DropEffect';
  {$EXTERNALSYM CFSTR_PERFORMEDDROPEFFECT}
  CFSTR_PERFORMEDDROPEFFECT   = 'Performed DropEffect';
  {$EXTERNALSYM CFSTR_PASTESUCCEEDED}
  CFSTR_PASTESUCCEEDED        = 'Paste Succeeded';
  {$EXTERNALSYM CFSTR_INDRAGLOOP}
  CFSTR_INDRAGLOOP            = 'InShellDragLoop';









  {$EXTERNALSYM CFSTR_FILEDESCRIPTOR}
  CFSTR_FILEDESCRIPTOR        = CFSTR_FILEDESCRIPTORA;
  {$EXTERNALSYM CFSTR_FILENAME}
  CFSTR_FILENAME              = CFSTR_FILENAMEA;
  {$EXTERNALSYM CFSTR_FILENAMEMAP}
  CFSTR_FILENAMEMAP           = CFSTR_FILENAMEMAPA;



{ CF_OBJECTPOSITIONS }

  {$EXTERNALSYM DVASPECT_SHORTNAME}
  DVASPECT_SHORTNAME     = 2; { use for CF_HDROP to get short name version }


type
{ format of CF_NETRESOURCE }

  PNResArray = ^TNResArray;
  {$EXTERNALSYM _NRESARRAY}
  _NRESARRAY = record
    cItems: UINT;
    nr: array[0..0] of TNetResource;
  end;
  TNResArray = _NRESARRAY;
  {$EXTERNALSYM NRESARRAY}
  NRESARRAY = _NRESARRAY;


{ format of CF_IDLIST }

  PIDA = ^TIDA;
  {$EXTERNALSYM _IDA}
  _IDA = record
    cidl: UINT;                      { number of relative IDList }
    aoffset: array[0..0] of UINT;    { [0]: folder IDList, [1]-[cidl]: item IDList }
  end;
  TIDA = _IDA;
  {$EXTERNALSYM CIDA}
  CIDA = _IDA;



const
{ FILEDESCRIPTOR.dwFlags field indicate which fields are to be used }

  {$EXTERNALSYM FD_CLSID}
  FD_CLSID            = $0001;
  {$EXTERNALSYM FD_SIZEPOINT}
  FD_SIZEPOINT        = $0002;
  {$EXTERNALSYM FD_ATTRIBUTES}
  FD_ATTRIBUTES       = $0004;
  {$EXTERNALSYM FD_CREATETIME}
  FD_CREATETIME       = $0008;
  {$EXTERNALSYM FD_ACCESSTIME}
  FD_ACCESSTIME       = $0010;
  {$EXTERNALSYM FD_WRITESTIME}
  FD_WRITESTIME       = $0020;
  {$EXTERNALSYM FD_FILESIZE}
  FD_FILESIZE         = $0040;
  {$EXTERNALSYM FD_LINKUI}
  FD_LINKUI           = $8000;       { 'link' UI is prefered }

type
  PFileDescriptorA = ^TFileDescriptorA;
  PFileDescriptorW = ^TFileDescriptorW;
  PFileDescriptor = PFileDescriptorA;
  {$EXTERNALSYM _FILEDESCRIPTORA}
  _FILEDESCRIPTORA = record
    dwFlags: DWORD;
    clsid: TCLSID;
    sizel: TSize;
    pointl: TPoint;
    dwFileAttributes: DWORD;
    ftCreationTime: TFileTime;
    ftLastAccessTime: TFileTime;
    ftLastWriteTime: TFileTime;
    nFileSizeHigh: DWORD;
    nFileSizeLow: DWORD;
    cFileName: array[0..MAX_PATH-1] of AnsiChar;
  end;
  {$EXTERNALSYM _FILEDESCRIPTORW}
  _FILEDESCRIPTORW = record
    dwFlags: DWORD;
    clsid: TCLSID;
    sizel: TSize;
    pointl: TPoint;
    dwFileAttributes: DWORD;
    ftCreationTime: TFileTime;
    ftLastAccessTime: TFileTime;
    ftLastWriteTime: TFileTime;
    nFileSizeHigh: DWORD;
    nFileSizeLow: DWORD;
    cFileName: array[0..MAX_PATH-1] of WideChar;
  end;
  {$EXTERNALSYM _FILEDESCRIPTOR}
  _FILEDESCRIPTOR = _FILEDESCRIPTORA;
  TFileDescriptorA = _FILEDESCRIPTORA;
  TFileDescriptorW = _FILEDESCRIPTORW;
  TFileDescriptor = TFileDescriptorA;
  {$EXTERNALSYM FILEDESCRIPTORA}
  FILEDESCRIPTORA = _FILEDESCRIPTORA;
  {$EXTERNALSYM FILEDESCRIPTORW}
  FILEDESCRIPTORW = _FILEDESCRIPTORW;
  {$EXTERNALSYM FILEDESCRIPTOR}
  FILEDESCRIPTOR = FILEDESCRIPTORA;

{ format of CF_FILEGROUPDESCRIPTOR }

  PFileGroupDescriptorA = ^TFileGroupDescriptorA;
  PFileGroupDescriptorW = ^TFileGroupDescriptorW;
  PFileGroupDescriptor = PFileGroupDescriptorA;
  {$EXTERNALSYM _FILEGROUPDESCRIPTORA}
  _FILEGROUPDESCRIPTORA = record
    cItems: UINT;
    fgd: array[0..0] of TFileDescriptor;
  end;
  {$EXTERNALSYM _FILEGROUPDESCRIPTORW}
  _FILEGROUPDESCRIPTORW = record
    cItems: UINT;
    fgd: array[0..0] of TFileDescriptor;
  end;
  {$EXTERNALSYM _FILEGROUPDESCRIPTOR}
  _FILEGROUPDESCRIPTOR = _FILEGROUPDESCRIPTORA;
  TFileGroupDescriptorA = _FILEGROUPDESCRIPTORA;
  TFileGroupDescriptorW = _FILEGROUPDESCRIPTORW;
  TFileGroupDescriptor = TFileGroupDescriptorA;
  {$EXTERNALSYM FILEGROUPDESCRIPTORA}
  FILEGROUPDESCRIPTORA = _FILEGROUPDESCRIPTORA;
  {$EXTERNALSYM FILEGROUPDESCRIPTORW}
  FILEGROUPDESCRIPTORW = _FILEGROUPDESCRIPTORW;
  {$EXTERNALSYM FILEGROUPDESCRIPTOR}
  FILEGROUPDESCRIPTOR = FILEGROUPDESCRIPTORA;

{ format of CF_HDROP and CF_PRINTERS, in the HDROP case the data that follows
  is a double null terinated list of file names, for printers they are printer
  friendly names }

  PDropFiles = ^TDropFiles;
  {$EXTERNALSYM _DROPFILES}
  _DROPFILES = record
    pFiles: DWORD;                       { offset of file list }
    pt: TPoint;                          { drop point (client coords) }
    fNC: BOOL;                           { is it on NonClient area }
                                         { and pt is in screen coords }
    fWide: BOOL;                         { WIDE character switch }
  end;
  TDropFiles = _DROPFILES;
  {$EXTERNALSYM DROPFILES}
  DROPFILES = _DROPFILES;


{ File System Notification APIs }

const
{ File System Notification flags }

  {$EXTERNALSYM SHCNE_RENAMEITEM}
  SHCNE_RENAMEITEM          = $00000001;
  {$EXTERNALSYM SHCNE_CREATE}
  SHCNE_CREATE              = $00000002;
  {$EXTERNALSYM SHCNE_DELETE}
  SHCNE_DELETE              = $00000004;
  {$EXTERNALSYM SHCNE_MKDIR}
  SHCNE_MKDIR               = $00000008;
  {$EXTERNALSYM SHCNE_RMDIR}
  SHCNE_RMDIR               = $00000010;
  {$EXTERNALSYM SHCNE_MEDIAINSERTED}
  SHCNE_MEDIAINSERTED       = $00000020;
  {$EXTERNALSYM SHCNE_MEDIAREMOVED}
  SHCNE_MEDIAREMOVED        = $00000040;
  {$EXTERNALSYM SHCNE_DRIVEREMOVED}
  SHCNE_DRIVEREMOVED        = $00000080;
  {$EXTERNALSYM SHCNE_DRIVEADD}
  SHCNE_DRIVEADD            = $00000100;
  {$EXTERNALSYM SHCNE_NETSHARE}
  SHCNE_NETSHARE            = $00000200;
  {$EXTERNALSYM SHCNE_NETUNSHARE}
  SHCNE_NETUNSHARE          = $00000400;
  {$EXTERNALSYM SHCNE_ATTRIBUTES}
  SHCNE_ATTRIBUTES          = $00000800;
  {$EXTERNALSYM SHCNE_UPDATEDIR}
  SHCNE_UPDATEDIR           = $00001000;
  {$EXTERNALSYM SHCNE_UPDATEITEM}
  SHCNE_UPDATEITEM          = $00002000;
  {$EXTERNALSYM SHCNE_SERVERDISCONNECT}
  SHCNE_SERVERDISCONNECT    = $00004000;
  {$EXTERNALSYM SHCNE_UPDATEIMAGE}
  SHCNE_UPDATEIMAGE         = $00008000;
  {$EXTERNALSYM SHCNE_DRIVEADDGUI}
  SHCNE_DRIVEADDGUI         = $00010000;
  {$EXTERNALSYM SHCNE_RENAMEFOLDER}
  SHCNE_RENAMEFOLDER        = $00020000;
  {$EXTERNALSYM SHCNE_FREESPACE}
  SHCNE_FREESPACE           = $00040000;
  {$EXTERNALSYM SHCNE_EXTENDED_EVENT}
  SHCNE_EXTENDED_EVENT      = $04000000;
  SHCNE_EXTENDED_EVENT_PRE_IE4 = $00080000;

  {$EXTERNALSYM SHCNE_ASSOCCHANGED}
  SHCNE_ASSOCCHANGED        = $08000000;

  {$EXTERNALSYM SHCNE_DISKEVENTS}
  SHCNE_DISKEVENTS          = $0002381F;
  {$EXTERNALSYM SHCNE_GLOBALEVENTS}
  SHCNE_GLOBALEVENTS        = $0C0581E0; { Events that dont match pidls first }
  {$EXTERNALSYM SHCNE_ALLEVENTS}
  SHCNE_ALLEVENTS           = $7FFFFFFF;
  {$EXTERNALSYM SHCNE_INTERRUPT}
  SHCNE_INTERRUPT           = $80000000; { The presence of this flag indicates }
                                         { that the event was generated by an }
                                         { interrupt.  It is stripped out before }
                                         { the clients of SHCNNotify_ see it. }
  {$EXTERNALSYM SHCNEE_THEMECHANGED}
  SHCNEE_THEMECHANGED       = $00000001;
  {$EXTERNALSYM SHCNEE_ORDERCHANGED}
  SHCNEE_ORDERCHANGED       = $00000002; { dwItem2 is the pidl of the changed folder }


{ uFlags & SHCNF_TYPE is an ID which indicates what dwItem1 and dwItem2 mean }

  {$EXTERNALSYM SHCNF_IDLIST}
  SHCNF_IDLIST          = $0000;        { LPITEMIDLIST }
  {$EXTERNALSYM SHCNF_PATHA}
  SHCNF_PATHA           = $0001;        { path name }
  {$EXTERNALSYM SHCNF_PRINTERA}
  SHCNF_PRINTERA        = $0002;        { printer friendly name }
  {$EXTERNALSYM SHCNF_DWORD}
  SHCNF_DWORD           = $0003;        { DWORD }
  {$EXTERNALSYM SHCNF_PATHW}
  SHCNF_PATHW           = $0005;        { path name }
  {$EXTERNALSYM SHCNF_PRINTERW}
  SHCNF_PRINTERW        = $0006;        { printer friendly name }
  {$EXTERNALSYM SHCNF_TYPE}
  SHCNF_TYPE            = $00FF;
  {$EXTERNALSYM SHCNF_FLUSH}
  SHCNF_FLUSH           = $1000;
  {$EXTERNALSYM SHCNF_FLUSHNOWAIT}
  SHCNF_FLUSHNOWAIT     = $2000;







  {$EXTERNALSYM SHCNF_PATH}
  SHCNF_PATH          = SHCNF_PATHA;
  {$EXTERNALSYM SHCNF_PRINTER}
  SHCNF_PRINTER       = SHCNF_PRINTERA;


{ APIs }

{$EXTERNALSYM SHChangeNotify}
procedure SHChangeNotify(wEventId: Longint; uFlags: UINT;
  dwItem1, dwItem2: Pointer); stdcall;

{ IShellChangeNotify }

type
  {$EXTERNALSYM IShellChangeNotify}
  IShellChangeNotify = interface(IUnknown)
    [SID_IShellChangeNotify]
    function OnChange(lEvent: Longint; var pidl1, pidl2: TItemIDList): HResult; stdcall;
  end;

{ IQueryInfo }

  {$EXTERNALSYM IQueryInfo}
  IQueryInfo = interface(IUnknown)
    [SID_IQueryInfo]
    function GetInfoTip(dwFlags: DWORD; var ppwszTip: PWideChar): HResult; stdcall;
    function GetInfoFlags(out pdwFlags: DWORD): HResult; stdcall;
  end;

const
  {$EXTERNALSYM QIF_CACHED}
  QIF_CACHED           = $00000001;
  {$EXTERNALSYM QIF_DONTEXPANDFOLDER}
  QIF_DONTEXPANDFOLDER = $00000002;

{$EXTERNALSYM SHAddToRecentDocs}
procedure SHAddToRecentDocs(uFlags: UINT; pv: Pointer); stdcall;
{$EXTERNALSYM SHGetInstanceExplorer}
function SHGetInstanceExplorer(var ppUnk: IUnknown): HResult; stdcall;

{ SHAddToRecentDocs }

const
  {$EXTERNALSYM SHARD_PIDL}
  SHARD_PIDL          = $00000001;
  {$EXTERNALSYM SHARD_PATHA}
  SHARD_PATHA         = $00000002;
  {$EXTERNALSYM SHARD_PATHW}
  SHARD_PATHW         = $00000003;





  {$EXTERNALSYM SHARD_PATH}
  SHARD_PATH      = SHARD_PATHA;



{ SHGetDataFromIDList}

const
  {$EXTERNALSYM SHGDFIL_FINDDATA}
  SHGDFIL_FINDDATA            = 1;
  {$EXTERNALSYM SHGDFIL_NETRESOURCE}
  SHGDFIL_NETRESOURCE         = 2;
  {$EXTERNALSYM SHGDFIL_DESCRIPTIONID}
  SHGDFIL_DESCRIPTIONID       = 3;

  {$EXTERNALSYM SHDID_ROOT_REGITEM}
  SHDID_ROOT_REGITEM              = 1;
  {$EXTERNALSYM SHDID_FS_FILE}
  SHDID_FS_FILE                   = 2;
  {$EXTERNALSYM SHDID_FS_DIRECTORY}
  SHDID_FS_DIRECTORY              = 3;
  {$EXTERNALSYM SHDID_FS_OTHER}
  SHDID_FS_OTHER                  = 4;
  {$EXTERNALSYM SHDID_COMPUTER_DRIVE35}
  SHDID_COMPUTER_DRIVE35          = 5;
  {$EXTERNALSYM SHDID_COMPUTER_DRIVE525}
  SHDID_COMPUTER_DRIVE525         = 6;
  {$EXTERNALSYM SHDID_COMPUTER_REMOVABLE}
  SHDID_COMPUTER_REMOVABLE        = 7;
  {$EXTERNALSYM SHDID_COMPUTER_FIXED}
  SHDID_COMPUTER_FIXED            = 8;
  {$EXTERNALSYM SHDID_COMPUTER_NETDRIVE}
  SHDID_COMPUTER_NETDRIVE         = 9;
  {$EXTERNALSYM SHDID_COMPUTER_CDROM}
  SHDID_COMPUTER_CDROM            = 10;
  {$EXTERNALSYM SHDID_COMPUTER_RAMDISK}
  SHDID_COMPUTER_RAMDISK          = 11;
  {$EXTERNALSYM SHDID_COMPUTER_OTHER}
  SHDID_COMPUTER_OTHER            = 12;
  {$EXTERNALSYM SHDID_NET_DOMAIN}
  SHDID_NET_DOMAIN                = 13;
  {$EXTERNALSYM SHDID_NET_SERVER}
  SHDID_NET_SERVER                = 14;
  {$EXTERNALSYM SHDID_NET_SHARE}
  SHDID_NET_SHARE                 = 15;
  {$EXTERNALSYM SHDID_NET_RESTOFNET}
  SHDID_NET_RESTOFNET             = 16;
  {$EXTERNALSYM SHDID_NET_OTHER}
  SHDID_NET_OTHER                 = 17;

type
  PSHDescriptionID = ^TSHDescriptionID;
  {$EXTERNALSYM _SHDESCRIPTIONID}
  _SHDESCRIPTIONID = record
    dwDescriptionId: DWORD;
    Id: TCLSID;
  end;
  TSHDescriptionID = _SHDESCRIPTIONID;
  {$EXTERNALSYM SHDESCRIPTIONID}
  SHDESCRIPTIONID = _SHDESCRIPTIONID;


{$EXTERNALSYM SHGetDataFromIDList}
function SHGetDataFromIDList(psf: IShellFolder; pidl: PItemIDList;
  nFormat: Integer; ptr: Pointer; cb: Integer): HResult; stdcall;
{$EXTERNALSYM SHGetDataFromIDListA}
function SHGetDataFromIDListA(psf: IShellFolder; pidl: PItemIDList;
  nFormat: Integer; ptr: Pointer; cb: Integer): HResult; stdcall;
{$EXTERNALSYM SHGetDataFromIDListW}
function SHGetDataFromIDListW(psf: IShellFolder; pidl: PItemIDList;
  nFormat: Integer; ptr: Pointer; cb: Integer): HResult; stdcall;

{ PROPIDs for Internet Shortcuts (FMTID_Intshcut) to be used with }
{ IPropertySetStorage/IPropertyStorage }
{
 The known property ids and their variant types are:
      PID_IS_URL          [VT_LPWSTR]   URL
      PID_IS_NAME         [VT_LPWSTR]   Name of the internet shortcut
      PID_IS_WORKINGDIR   [VT_LPWSTR]   Working directory for the shortcut
      PID_IS_HOTKEY       [VT_UI2]      Hotkey for the shortcut
      PID_IS_SHOWCMD      [VT_I4]       Show command for shortcut
      PID_IS_ICONINDEX    [VT_I4]       Index into file that has icon
      PID_IS_ICONFILE     [VT_LPWSTR]   File that has the icon
      PID_IS_WHATSNEW     [VT_LPWSTR]   What's New text
      PID_IS_AUTHOR       [VT_LPWSTR]   Author
      PID_IS_DESCRIPTION  [VT_LPWSTR]   Description text of site
      PID_IS_COMMENT      [VT_LPWSTR]   User annotated comment
}

const
  {$EXTERNALSYM PID_IS_URL}
  PID_IS_URL           = 2;
  {$EXTERNALSYM PID_IS_NAME}
  PID_IS_NAME          = 4;
  {$EXTERNALSYM PID_IS_WORKINGDIR}
  PID_IS_WORKINGDIR    = 5;
  {$EXTERNALSYM PID_IS_HOTKEY}
  PID_IS_HOTKEY        = 6;
  {$EXTERNALSYM PID_IS_SHOWCMD}
  PID_IS_SHOWCMD       = 7;
  {$EXTERNALSYM PID_IS_ICONINDEX}
  PID_IS_ICONINDEX     = 8;
  {$EXTERNALSYM PID_IS_ICONFILE}
  PID_IS_ICONFILE      = 9;
  {$EXTERNALSYM PID_IS_WHATSNEW}
  PID_IS_WHATSNEW      = 10;
  {$EXTERNALSYM PID_IS_AUTHOR}
  PID_IS_AUTHOR        = 11;
  {$EXTERNALSYM PID_IS_DESCRIPTION}
  PID_IS_DESCRIPTION   = 12;
  {$EXTERNALSYM PID_IS_COMMENT}
  PID_IS_COMMENT       = 13;

{ PROPIDs for Internet Sites (FMTID_InternetSite) to be used with }
{ IPropertySetStorage/IPropertyStorage }
{
 The known property ids and their variant types are:
      PID_INTSITE_WHATSNEW     [VT_LPWSTR]   What's New text
      PID_INTSITE_AUTHOR       [VT_LPWSTR]   Author
      PID_INTSITE_LASTVISIT    [VT_FILETIME] Time site was last visited
      PID_INTSITE_LASTMOD      [VT_FILETIME] Time site was last modified
      PID_INTSITE_VISITCOUNT   [VT_UI4]      Number of times user has visited
      PID_INTSITE_DESCRIPTION  [VT_LPWSTR]   Description text of site
      PID_INTSITE_COMMENT      [VT_LPWSTR]   User annotated comment
      PID_INTSITE_RECURSE      [VT_UI4]      Levels to recurse (0-3)
      PID_INTSITE_WATCH        [VT_UI4]      PIDISM_ flags
      PID_INTSITE_SUBSCRIPTION [VT_UI8]      Subscription cookie
      PID_INTSITE_URL          [VT_LPWSTR]   URL
      PID_INTSITE_TITLE        [VT_LPWSTR]   Title
      PID_INTSITE_CODEPAGE     [VT_UI4]      Codepage of the document
      PID_INTSITE_TRACKING     [VT_UI4]      Tracking
}

  {$EXTERNALSYM PID_INTSITE_WHATSNEW}
  PID_INTSITE_WHATSNEW      = 2;
  {$EXTERNALSYM PID_INTSITE_AUTHOR}
  PID_INTSITE_AUTHOR        = 3;
  {$EXTERNALSYM PID_INTSITE_LASTVISIT}
  PID_INTSITE_LASTVISIT     = 4;
  {$EXTERNALSYM PID_INTSITE_LASTMOD}
  PID_INTSITE_LASTMOD       = 5;
  {$EXTERNALSYM PID_INTSITE_VISITCOUNT}
  PID_INTSITE_VISITCOUNT    = 6;
  {$EXTERNALSYM PID_INTSITE_DESCRIPTION}
  PID_INTSITE_DESCRIPTION   = 7;
  {$EXTERNALSYM PID_INTSITE_COMMENT}
  PID_INTSITE_COMMENT       = 8;
  {$EXTERNALSYM PID_INTSITE_FLAGS}
  PID_INTSITE_FLAGS         = 9;
  {$EXTERNALSYM PID_INTSITE_CONTENTLEN}
  PID_INTSITE_CONTENTLEN    = 10;
  {$EXTERNALSYM PID_INTSITE_CONTENTCODE}
  PID_INTSITE_CONTENTCODE   = 11;
  {$EXTERNALSYM PID_INTSITE_RECURSE}
  PID_INTSITE_RECURSE       = 12;
  {$EXTERNALSYM PID_INTSITE_WATCH}
  PID_INTSITE_WATCH         = 13;
  {$EXTERNALSYM PID_INTSITE_SUBSCRIPTION}
  PID_INTSITE_SUBSCRIPTION  = 14;
  {$EXTERNALSYM PID_INTSITE_URL}
  PID_INTSITE_URL           = 15;
  {$EXTERNALSYM PID_INTSITE_TITLE}
  PID_INTSITE_TITLE         = 16;
  {$EXTERNALSYM PID_INTSITE_CODEPAGE}
  PID_INTSITE_CODEPAGE      = 18;
  {$EXTERNALSYM PID_INTSITE_TRACKING}
  PID_INTSITE_TRACKING      = 19;

  // Flags for PID_IS_FLAGS
  {$EXTERNALSYM PIDISF_RECENTLYCHANGED}
  PIDISF_RECENTLYCHANGED  = $00000001;
  {$EXTERNALSYM PIDISF_CACHEDSTICKY}
  PIDISF_CACHEDSTICKY     = $00000002;
  {$EXTERNALSYM PIDISF_CACHEIMAGES}
  PIDISF_CACHEIMAGES      = $00000010;
  {$EXTERNALSYM PIDISF_FOLLOWALLLINKS}
  PIDISF_FOLLOWALLLINKS   = $00000020;

  // Values for PID_INTSITE_WATCH
  {$EXTERNALSYM PIDISM_GLOBAL}
  PIDISM_GLOBAL           = 0;       // Monitor based on global setting
  {$EXTERNALSYM PIDISM_WATCH}
  PIDISM_WATCH            = 1;       // User says watch
  {$EXTERNALSYM PIDISM_DONTWATCH}
  PIDISM_DONTWATCH        = 2;       // User says don't watch

{ The shell keeps track of some per-user state to handle display
  options that is of major interest to ISVs.
  The key one requested right now is "DoubleClickInWebView". }

type
  {$EXTERNALSYM SHELLFLAGSTATE}
  SHELLFLAGSTATE = packed record
    Data: Word;
{   BOOL fShowAllObjects : 1;
    BOOL fShowExtensions : 1;
    BOOL fNoConfirmRecycle : 1;
    BOOL fShowSysFiles : 1;
    BOOL fShowCompColor : 1;
    BOOL fDoubleClickInWebView : 1;
    BOOL fDesktopHTML : 1;
    BOOL fWin95Classic : 1;
    BOOL fDontPrettyPath : 1;
    BOOL fShowAttribCol : 1;
    BOOL fMapNetDrvBtn : 1;
    BOOL fShowInfoTip : 1;
    BOOL fHideIcons : 1;
    UINT fRestFlags : 3;}
  end;
  PShellFlagState = ^TShellFlagState;
  TShellFlagState = SHELLFLAGSTATE;

const
  {$EXTERNALSYM SSF_SHOWALLOBJECTS}
  SSF_SHOWALLOBJECTS          = $0001;
  {$EXTERNALSYM SSF_SHOWEXTENSIONS}
  SSF_SHOWEXTENSIONS          = $0002;
  {$EXTERNALSYM SSF_SHOWCOMPCOLOR}
  SSF_SHOWCOMPCOLOR           = $0008;
  {$EXTERNALSYM SSF_SHOWSYSFILES}
  SSF_SHOWSYSFILES            = $0020;
  {$EXTERNALSYM SSF_DOUBLECLICKINWEBVIEW}
  SSF_DOUBLECLICKINWEBVIEW    = $0080;
  {$EXTERNALSYM SSF_SHOWATTRIBCOL}
  SSF_SHOWATTRIBCOL           = $0100;
  {$EXTERNALSYM SSF_DESKTOPHTML}
  SSF_DESKTOPHTML             = $0200;
  {$EXTERNALSYM SSF_WIN95CLASSIC}
  SSF_WIN95CLASSIC            = $0400;
  {$EXTERNALSYM SSF_DONTPRETTYPATH}
  SSF_DONTPRETTYPATH          = $0800;
  {$EXTERNALSYM SSF_SHOWINFOTIP}
  SSF_SHOWINFOTIP             = $2000;
  {$EXTERNALSYM SSF_MAPNETDRVBUTTON}
  SSF_MAPNETDRVBUTTON         = $1000;
  {$EXTERNALSYM SSF_NOCONFIRMRECYCLE}
  SSF_NOCONFIRMRECYCLE        = $8000;
  {$EXTERNALSYM SSF_HIDEICONS}
  SSF_HIDEICONS               = $4000;

{ Specify the bits you are interested in in dwMask and they will be
 filled out in the lpss structure.

 When these settings change, a WM_SETTINGCHANGE message is sent
 with the string lParam value of "ShellState". }

procedure SHGetSettings(var lpss: TShellFlagState; dwMask: DWORD); stdcall;
{$EXTERNALSYM SHGetSettings}

{ SoftwareUpdateMessageBox }
{
    Provides a standard message box for the alerting the user that a software
    update is available or installed. No UI will be displayed if there is no
    update available or if the available update version is less than or equal
    to the Advertised update version.

    hWnd                - [in] Handle of owner window
    szDistUnit          - [in] Unique identifier string for a code distribution unit. For
                               ActiveX controls and Active Setup installed components, this
                               is typically a GUID string.
    dwFlags             - [in] Must be 0.
    psdi                - [in,out] Pointer to SOFTDISTINFO ( see URLMon.h ). May be NULL.
                                cbSize should be initialized
                                by the caller to sizeof(SOFTDISTINFO), dwReserved should be set to 0.

    RETURNS:

    IDNO     - The user chose cancel. If *pbRemind is FALSE, the caller should save the 
               update version from the SOFTDISTINFO and pass it in as the Advertised
               version in future calls.

    IDYES    - The user has selected Update Now/About Update. The caller should navigate to
               the SOFTDISTINFO's pszHREF to initiate the install or learn about it.
               The caller should save the update version from the SOFTDISTINFO and pass
               it in as the Advertised version in future calls.

    IDIGNORE - There is no pending software update. Note: There is
               no Ignore button in the standard UI. This occurs if the available
               version is less than the installed version or is not present or if the
               Advertised version is greater than or equal to the update version.

    IDABORT  - An error occured. Call GetSoftwareUpdateInfo() for a more specific HRESULT.
               Note: There is no Abort button in the standard UI.
}

function SoftwareUpdateMessageBox(hWnd: HWND; szDistUnit: PWideChar;
  dwFlags: DWORD; var psdi: TSoftDistInfo): DWORD; stdcall;
{$EXTERNALSYM SoftwareUpdateMessageBox}

implementation

const
  shell32 = 'shell32.dll';

procedure SHAddToRecentDocs;             external shell32 name 'SHAddToRecentDocs';
function SHBrowseForFolder;          external shell32 name 'SHBrowseForFolderA';
function SHBrowseForFolderA;          external shell32 name 'SHBrowseForFolderA';
function SHBrowseForFolderW;          external shell32 name 'SHBrowseForFolderW';
procedure SHChangeNotify;                external shell32 name 'SHChangeNotify';
function SHGetDataFromIDList;        external shell32 name 'SHGetDataFromIDListA';
function SHGetDataFromIDListA;        external shell32 name 'SHGetDataFromIDListA';
function SHGetDataFromIDListW;        external shell32 name 'SHGetDataFromIDListW';
function SHGetDesktopFolder;            external shell32 name 'SHGetDesktopFolder';
function SHGetInstanceExplorer;         external shell32 name 'SHGetInstanceExplorer';
function SHGetMalloc;                   external shell32 name 'SHGetMalloc';
function SHGetPathFromIDList;        external shell32 name 'SHGetPathFromIDListA';
function SHGetPathFromIDListA;        external shell32 name 'SHGetPathFromIDListA';
function SHGetPathFromIDListW;        external shell32 name 'SHGetPathFromIDListW';
function SHGetSpecialFolderLocation;    external shell32 name 'SHGetSpecialFolderLocation';
function SHLoadInProc;                  external shell32 name 'SHLoadInProc';
function SHGetSpecialFolderPath;     external shell32 name 'SHGetSpecialFolderPathA'
function SHGetSpecialFolderPathA;     external shell32 name 'SHGetSpecialFolderPathA'
function SHGetSpecialFolderPathW;     external shell32 name 'SHGetSpecialFolderPathW'
procedure SHGetSettings;                external shell32 name 'SHGetSettings'
function SoftwareUpdateMessageBox;      external shell32 name 'SoftwareUpdateMessageBox'

end.


