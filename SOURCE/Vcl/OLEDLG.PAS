
{*******************************************************}
{                                                       }
{       Borland Delphi Runtime Library                  }
{       OLE dialogs interface unit                      }
{                                                       }
{       Copyright (C) 1996,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit OleDlg;

{$WEAKPACKAGEUNIT}

interface

(*$HPPEMIT '' *)
(*$HPPEMIT '#include <oledlg.h>' *)
(*$HPPEMIT '' *)

uses Windows, CommCtrl, ActiveX;

const

{ Help Button Identifier }

  {$EXTERNALSYM IDC_OLEUIHELP}
  IDC_OLEUIHELP                   = 99;

{ Insert Object Dialog identifiers }

  {$EXTERNALSYM IDC_IO_CREATENEW}
  IDC_IO_CREATENEW                = 2100;
  {$EXTERNALSYM IDC_IO_CREATEFROMFILE}
  IDC_IO_CREATEFROMFILE           = 2101;
  {$EXTERNALSYM IDC_IO_LINKFILE}
  IDC_IO_LINKFILE                 = 2102;
  {$EXTERNALSYM IDC_IO_OBJECTTYPELIST}
  IDC_IO_OBJECTTYPELIST           = 2103;
  {$EXTERNALSYM IDC_IO_DISPLAYASICON}
  IDC_IO_DISPLAYASICON            = 2104;
  {$EXTERNALSYM IDC_IO_CHANGEICON}
  IDC_IO_CHANGEICON               = 2105;
  {$EXTERNALSYM IDC_IO_FILE}
  IDC_IO_FILE                     = 2106;
  {$EXTERNALSYM IDC_IO_FILEDISPLAY}
  IDC_IO_FILEDISPLAY              = 2107;
  {$EXTERNALSYM IDC_IO_RESULTIMAGE}
  IDC_IO_RESULTIMAGE              = 2108;
  {$EXTERNALSYM IDC_IO_RESULTTEXT}
  IDC_IO_RESULTTEXT               = 2109;
  {$EXTERNALSYM IDC_IO_ICONDISPLAY}
  IDC_IO_ICONDISPLAY              = 2110;
  {$EXTERNALSYM IDC_IO_OBJECTTYPETEXT}
  IDC_IO_OBJECTTYPETEXT           = 2111;
  {$EXTERNALSYM IDC_IO_FILETEXT}
  IDC_IO_FILETEXT                 = 2112;
  {$EXTERNALSYM IDC_IO_FILETYPE}
  IDC_IO_FILETYPE                 = 2113;
  {$EXTERNALSYM IDC_IO_INSERTCONTROL}
  IDC_IO_INSERTCONTROL            = 2114;
  {$EXTERNALSYM IDC_IO_ADDCONTROL}
  IDC_IO_ADDCONTROL               = 2115;
  {$EXTERNALSYM IDC_IO_CONTROLTYPELIST}
  IDC_IO_CONTROLTYPELIST          = 2116;

{ Paste Special Dialog identifiers }

  {$EXTERNALSYM IDC_PS_PASTE}
  IDC_PS_PASTE                    = 500;
  {$EXTERNALSYM IDC_PS_PASTELINK}
  IDC_PS_PASTELINK                = 501;
  {$EXTERNALSYM IDC_PS_SOURCETEXT}
  IDC_PS_SOURCETEXT               = 502;
  {$EXTERNALSYM IDC_PS_PASTELIST}
  IDC_PS_PASTELIST                = 503;
  {$EXTERNALSYM IDC_PS_PASTELINKLIST}
  IDC_PS_PASTELINKLIST            = 504;
  {$EXTERNALSYM IDC_PS_DISPLAYLIST}
  IDC_PS_DISPLAYLIST              = 505;
  {$EXTERNALSYM IDC_PS_DISPLAYASICON}
  IDC_PS_DISPLAYASICON            = 506;
  {$EXTERNALSYM IDC_PS_ICONDISPLAY}
  IDC_PS_ICONDISPLAY              = 507;
  {$EXTERNALSYM IDC_PS_CHANGEICON}
  IDC_PS_CHANGEICON               = 508;
  {$EXTERNALSYM IDC_PS_RESULTIMAGE}
  IDC_PS_RESULTIMAGE              = 509;
  {$EXTERNALSYM IDC_PS_RESULTTEXT}
  IDC_PS_RESULTTEXT               = 510;

{ Change Icon Dialog identifiers }

  {$EXTERNALSYM IDC_CI_GROUP}
  IDC_CI_GROUP                    = 120;
  {$EXTERNALSYM IDC_CI_CURRENT}
  IDC_CI_CURRENT                  = 121;
  {$EXTERNALSYM IDC_CI_CURRENTICON}
  IDC_CI_CURRENTICON              = 122;
  {$EXTERNALSYM IDC_CI_DEFAULT}
  IDC_CI_DEFAULT                  = 123;
  {$EXTERNALSYM IDC_CI_DEFAULTICON}
  IDC_CI_DEFAULTICON              = 124;
  {$EXTERNALSYM IDC_CI_FROMFILE}
  IDC_CI_FROMFILE                 = 125;
  {$EXTERNALSYM IDC_CI_FROMFILEEDIT}
  IDC_CI_FROMFILEEDIT             = 126;
  {$EXTERNALSYM IDC_CI_ICONLIST}
  IDC_CI_ICONLIST                 = 127;
  {$EXTERNALSYM IDC_CI_LABEL}
  IDC_CI_LABEL                    = 128;
  {$EXTERNALSYM IDC_CI_LABELEDIT}
  IDC_CI_LABELEDIT                = 129;
  {$EXTERNALSYM IDC_CI_BROWSE}
  IDC_CI_BROWSE                   = 130;
  {$EXTERNALSYM IDC_CI_ICONDISPLAY}
  IDC_CI_ICONDISPLAY              = 131;

{ Convert Dialog identifiers }

  {$EXTERNALSYM IDC_CV_OBJECTTYPE}
  IDC_CV_OBJECTTYPE               = 150;
  {$EXTERNALSYM IDC_CV_DISPLAYASICON}
  IDC_CV_DISPLAYASICON            = 152;
  {$EXTERNALSYM IDC_CV_CHANGEICON}
  IDC_CV_CHANGEICON               = 153;
  {$EXTERNALSYM IDC_CV_ACTIVATELIST}
  IDC_CV_ACTIVATELIST             = 154;
  {$EXTERNALSYM IDC_CV_CONVERTTO}
  IDC_CV_CONVERTTO                = 155;
  {$EXTERNALSYM IDC_CV_ACTIVATEAS}
  IDC_CV_ACTIVATEAS               = 156;
  {$EXTERNALSYM IDC_CV_RESULTTEXT}
  IDC_CV_RESULTTEXT               = 157;
  {$EXTERNALSYM IDC_CV_CONVERTLIST}
  IDC_CV_CONVERTLIST              = 158;
  {$EXTERNALSYM IDC_CV_ICONDISPLAY}
  IDC_CV_ICONDISPLAY              = 165;

{ Edit Links Dialog identifiers }

  {$EXTERNALSYM IDC_EL_CHANGESOURCE}
  IDC_EL_CHANGESOURCE             = 201;
  {$EXTERNALSYM IDC_EL_AUTOMATIC}
  IDC_EL_AUTOMATIC                = 202;
  {$EXTERNALSYM IDC_EL_CANCELLINK}
  IDC_EL_CANCELLINK               = 209;
  {$EXTERNALSYM IDC_EL_UPDATENOW}
  IDC_EL_UPDATENOW                = 210;
  {$EXTERNALSYM IDC_EL_OPENSOURCE}
  IDC_EL_OPENSOURCE               = 211;
  {$EXTERNALSYM IDC_EL_MANUAL}
  IDC_EL_MANUAL                   = 212;
  {$EXTERNALSYM IDC_EL_LINKSOURCE}
  IDC_EL_LINKSOURCE               = 216;
  {$EXTERNALSYM IDC_EL_LINKTYPE}
  IDC_EL_LINKTYPE                 = 217;
  {$EXTERNALSYM IDC_EL_LINKSLISTBOX}
  IDC_EL_LINKSLISTBOX             = 206;
  {$EXTERNALSYM IDC_EL_COL1}
  IDC_EL_COL1                     = 220;
  {$EXTERNALSYM IDC_EL_COL2}
  IDC_EL_COL2                     = 221;
  {$EXTERNALSYM IDC_EL_COL3}
  IDC_EL_COL3                     = 222;

{ Busy dialog identifiers }

  {$EXTERNALSYM IDC_BZ_RETRY}
  IDC_BZ_RETRY                    = 600;
  {$EXTERNALSYM IDC_BZ_ICON}
  IDC_BZ_ICON                     = 601;
  {$EXTERNALSYM IDC_BZ_MESSAGE1}
  IDC_BZ_MESSAGE1                 = 602;
  {$EXTERNALSYM IDC_BZ_SWITCHTO}
  IDC_BZ_SWITCHTO                 = 604;

{ Update Links dialog identifiers }

  {$EXTERNALSYM IDC_UL_METER}
  IDC_UL_METER                    = 1029;
  {$EXTERNALSYM IDC_UL_STOP}
  IDC_UL_STOP                     = 1030;
  {$EXTERNALSYM IDC_UL_PERCENT}
  IDC_UL_PERCENT                  = 1031;
  {$EXTERNALSYM IDC_UL_PROGRESS}
  IDC_UL_PROGRESS                 = 1032;

{ User Prompt dialog identifiers }

  {$EXTERNALSYM IDC_PU_LINKS}
  IDC_PU_LINKS                    = 900;
  {$EXTERNALSYM IDC_PU_TEXT}
  IDC_PU_TEXT                     = 901;
  {$EXTERNALSYM IDC_PU_CONVERT}
  IDC_PU_CONVERT                  = 902;
  {$EXTERNALSYM IDC_PU_ICON}
  IDC_PU_ICON                     = 908;

{ General Properties identifiers }

  {$EXTERNALSYM IDC_GP_OBJECTNAME}
  IDC_GP_OBJECTNAME               = 1009;
  {$EXTERNALSYM IDC_GP_OBJECTTYPE}
  IDC_GP_OBJECTTYPE               = 1010;
  {$EXTERNALSYM IDC_GP_OBJECTSIZE}
  IDC_GP_OBJECTSIZE               = 1011;
  {$EXTERNALSYM IDC_GP_CONVERT}
  IDC_GP_CONVERT                  = 1013;
  {$EXTERNALSYM IDC_GP_OBJECTICON}
  IDC_GP_OBJECTICON               = 1014;
  {$EXTERNALSYM IDC_GP_OBJECTLOCATION}
  IDC_GP_OBJECTLOCATION           = 1022;

{ View Properties identifiers }

  {$EXTERNALSYM IDC_VP_PERCENT}
  IDC_VP_PERCENT                  = 1000;
  {$EXTERNALSYM IDC_VP_CHANGEICON}
  IDC_VP_CHANGEICON               = 1001;
  {$EXTERNALSYM IDC_VP_EDITABLE}
  IDC_VP_EDITABLE                 = 1002;
  {$EXTERNALSYM IDC_VP_ASICON}
  IDC_VP_ASICON                   = 1003;
  {$EXTERNALSYM IDC_VP_RELATIVE}
  IDC_VP_RELATIVE                 = 1005;
  {$EXTERNALSYM IDC_VP_SPIN}
  IDC_VP_SPIN                     = 1006;
  {$EXTERNALSYM IDC_VP_SCALETXT}
  IDC_VP_SCALETXT                 = 1034;
  {$EXTERNALSYM IDC_VP_ICONDISPLAY}
  IDC_VP_ICONDISPLAY              = 1021;
  {$EXTERNALSYM IDC_VP_RESULTIMAGE}
  IDC_VP_RESULTIMAGE              = 1033;

{ Link Properties identifiers }

  {$EXTERNALSYM IDC_LP_OPENSOURCE}
  IDC_LP_OPENSOURCE               = 1006;
  {$EXTERNALSYM IDC_LP_UPDATENOW}
  IDC_LP_UPDATENOW                = 1007;
  {$EXTERNALSYM IDC_LP_BREAKLINK}
  IDC_LP_BREAKLINK                = 1008;
  {$EXTERNALSYM IDC_LP_LINKSOURCE}
  IDC_LP_LINKSOURCE               = 1012;
  {$EXTERNALSYM IDC_LP_CHANGESOURCE}
  IDC_LP_CHANGESOURCE             = 1015;
  {$EXTERNALSYM IDC_LP_AUTOMATIC}
  IDC_LP_AUTOMATIC                = 1016;
  {$EXTERNALSYM IDC_LP_MANUAL}
  IDC_LP_MANUAL                   = 1017;
  {$EXTERNALSYM IDC_LP_DATE}
  IDC_LP_DATE                     = 1018;
  {$EXTERNALSYM IDC_LP_TIME}
  IDC_LP_TIME                     = 1019;

{ Dialog Identifiers as passed in Help messages to identify the source }

  {$EXTERNALSYM IDD_INSERTOBJECT}
  IDD_INSERTOBJECT                = 1000;
  {$EXTERNALSYM IDD_CHANGEICON}
  IDD_CHANGEICON                  = 1001;
  {$EXTERNALSYM IDD_CONVERT}
  IDD_CONVERT                     = 1002;
  {$EXTERNALSYM IDD_PASTESPECIAL}
  IDD_PASTESPECIAL                = 1003;
  {$EXTERNALSYM IDD_EDITLINKS}
  IDD_EDITLINKS                   = 1004;
  {$EXTERNALSYM IDD_BUSY}
  IDD_BUSY                        = 1006;
  {$EXTERNALSYM IDD_UPDATELINKS}
  IDD_UPDATELINKS                 = 1007;
  {$EXTERNALSYM IDD_CHANGESOURCE}
  IDD_CHANGESOURCE                = 1009;
  {$EXTERNALSYM IDD_INSERTFILEBROWSE}
  IDD_INSERTFILEBROWSE            = 1010;
  {$EXTERNALSYM IDD_CHANGEICONBROWSE}
  IDD_CHANGEICONBROWSE            = 1011;
  {$EXTERNALSYM IDD_CONVERTONLY}
  IDD_CONVERTONLY                 = 1012;
  {$EXTERNALSYM IDD_CHANGESOURCE4}
  IDD_CHANGESOURCE4               = 1013;
  {$EXTERNALSYM IDD_GNRLPROPS}
  IDD_GNRLPROPS                   = 1100;
  {$EXTERNALSYM IDD_VIEWPROPS}
  IDD_VIEWPROPS                   = 1101;
  {$EXTERNALSYM IDD_LINKPROPS}
  IDD_LINKPROPS                   = 1102;

{ The following Dialogs are message dialogs used by OleUIPromptUser API }

  {$EXTERNALSYM IDD_CANNOTUPDATELINK}
  IDD_CANNOTUPDATELINK            = 1008;
  {$EXTERNALSYM IDD_LINKSOURCEUNAVAILABLE}
  IDD_LINKSOURCEUNAVAILABLE       = 1020;
  {$EXTERNALSYM IDD_SERVERNOTFOUND}
  IDD_SERVERNOTFOUND              = 1023;
  {$EXTERNALSYM IDD_OUTOFMEMORY}
  IDD_OUTOFMEMORY                 = 1024;
  {$EXTERNALSYM IDD_SERVERNOTREG}
  IDD_SERVERNOTREG                = 1021;
  {$EXTERNALSYM IDD_LINKTYPECHANGED}
  IDD_LINKTYPECHANGED             = 1022;

{ Delimeter used to separate ItemMoniker pieces of a composite moniker }

  {$EXTERNALSYM OLESTDDELIM}
  OLESTDDELIM = '\';

{ Strings for registered messages }

  {$EXTERNALSYM SZOLEUI_MSG_HELP}
  SZOLEUI_MSG_HELP                = 'OLEUI_MSG_HELP';
  {$EXTERNALSYM SZOLEUI_MSG_ENDDIALOG}
  SZOLEUI_MSG_ENDDIALOG           = 'OLEUI_MSG_ENDDIALOG';
  {$EXTERNALSYM SZOLEUI_MSG_BROWSE}
  SZOLEUI_MSG_BROWSE              = 'OLEUI_MSG_BROWSE';
  {$EXTERNALSYM SZOLEUI_MSG_CHANGEICON}
  SZOLEUI_MSG_CHANGEICON          = 'OLEUI_MSG_CHANGEICON';
  {$EXTERNALSYM SZOLEUI_MSG_CLOSEBUSYDIALOG}
  SZOLEUI_MSG_CLOSEBUSYDIALOG     = 'OLEUI_MSG_CLOSEBUSYDIALOG';
  {$EXTERNALSYM SZOLEUI_MSG_CONVERT}
  SZOLEUI_MSG_CONVERT             = 'OLEUI_MSG_CONVERT';
  {$EXTERNALSYM SZOLEUI_MSG_CHANGESOURCE}
  SZOLEUI_MSG_CHANGESOURCE        = 'OLEUI_MSG_CHANGESOURCE';
  {$EXTERNALSYM SZOLEUI_MSG_ADDCONTROL}
  SZOLEUI_MSG_ADDCONTROL          = 'OLEUI_MSG_ADDCONTROL';
  {$EXTERNALSYM SZOLEUI_MSG_BROWSE_OFN}
  SZOLEUI_MSG_BROWSE_OFN          = 'OLEUI_MSG_BROWSE_OFN';

{ Identifiers for SZOLEUI_MSG_BROWSE_OFN (in wParam) }

  {$EXTERNALSYM ID_BROWSE_CHANGEICON}
  ID_BROWSE_CHANGEICON            = 1;
  {$EXTERNALSYM ID_BROWSE_INSERTFILE}
  ID_BROWSE_INSERTFILE            = 2;
  {$EXTERNALSYM ID_BROWSE_ADDCONTROL}
  ID_BROWSE_ADDCONTROL            = 3;
  {$EXTERNALSYM ID_BROWSE_CHANGESOURCE}
  ID_BROWSE_CHANGESOURCE          = 4;

{ Standard success/error definitions }

  {$EXTERNALSYM OLEUI_FALSE}
  OLEUI_FALSE                     = 0;
  {$EXTERNALSYM OLEUI_SUCCESS}
  OLEUI_SUCCESS                   = 1;   { No error, same as OLEUI_OK }
  {$EXTERNALSYM OLEUI_OK}
  OLEUI_OK                        = 1;   { OK button pressed }
  {$EXTERNALSYM OLEUI_CANCEL}
  OLEUI_CANCEL                    = 2;   { Cancel button pressed }

  {$EXTERNALSYM OLEUI_ERR_STANDARDMIN}
  OLEUI_ERR_STANDARDMIN           = 100;
  {$EXTERNALSYM OLEUI_ERR_STRUCTURENULL}
  OLEUI_ERR_STRUCTURENULL         = 101; { Standard field validation }
  {$EXTERNALSYM OLEUI_ERR_STRUCTUREINVALID}
  OLEUI_ERR_STRUCTUREINVALID      = 102;
  {$EXTERNALSYM OLEUI_ERR_CBSTRUCTINCORRECT}
  OLEUI_ERR_CBSTRUCTINCORRECT     = 103;
  {$EXTERNALSYM OLEUI_ERR_HWNDOWNERINVALID}
  OLEUI_ERR_HWNDOWNERINVALID      = 104;
  {$EXTERNALSYM OLEUI_ERR_LPSZCAPTIONINVALID}
  OLEUI_ERR_LPSZCAPTIONINVALID    = 105;
  {$EXTERNALSYM OLEUI_ERR_LPFNHOOKINVALID}
  OLEUI_ERR_LPFNHOOKINVALID       = 106;
  {$EXTERNALSYM OLEUI_ERR_HINSTANCEINVALID}
  OLEUI_ERR_HINSTANCEINVALID      = 107;
  {$EXTERNALSYM OLEUI_ERR_LPSZTEMPLATEINVALID}
  OLEUI_ERR_LPSZTEMPLATEINVALID   = 108;
  {$EXTERNALSYM OLEUI_ERR_HRESOURCEINVALID}
  OLEUI_ERR_HRESOURCEINVALID      = 109;

  {$EXTERNALSYM OLEUI_ERR_FINDTEMPLATEFAILURE}
  OLEUI_ERR_FINDTEMPLATEFAILURE   = 110; { Initialization errors }
  {$EXTERNALSYM OLEUI_ERR_LOADTEMPLATEFAILURE}
  OLEUI_ERR_LOADTEMPLATEFAILURE   = 111;
  {$EXTERNALSYM OLEUI_ERR_DIALOGFAILURE}
  OLEUI_ERR_DIALOGFAILURE         = 112;
  {$EXTERNALSYM OLEUI_ERR_LOCALMEMALLOC}
  OLEUI_ERR_LOCALMEMALLOC         = 113;
  {$EXTERNALSYM OLEUI_ERR_GLOBALMEMALLOC}
  OLEUI_ERR_GLOBALMEMALLOC        = 114;
  {$EXTERNALSYM OLEUI_ERR_LOADSTRING}
  OLEUI_ERR_LOADSTRING            = 115;
  {$EXTERNALSYM OLEUI_ERR_OLEMEMALLOC}
  OLEUI_ERR_OLEMEMALLOC           = 116;

  {$EXTERNALSYM OLEUI_ERR_STANDARDMAX}
  OLEUI_ERR_STANDARDMAX           = 117; { Start here for specific errors }

{ Hook type used in all structures }

type
  TFNOleUIHook = function(Wnd: HWnd; Msg, WParam, LParam: Longint): Longint stdcall;

{ Miscellaneous utility functions }

function OleUIAddVerbMenu(oleObj: IOleObject; pszShortType: PChar;
  menu: HMenu; uPos: Integer; uIDVerbMin: Integer; uIDVerbMax: Integer;
  bAddConvert: BOOL; idConvert: Integer; var outMenu: HMenu): BOOL; stdcall;
{$EXTERNALSYM OleUIAddVerbMenu}

{ **** Insert Object dialog **** }

{ Insert object dialog structure }

type
  POleUIInsertObject = ^TOleUIInsertObject;
  {$EXTERNALSYM tagOLEUIINSERTOBJECTA}
  tagOLEUIINSERTOBJECTA = record
    cbStruct: Longint;                  { Structure Size }
    dwFlags: Longint;                   { IN-OUT: Flags }
    hWndOwner: HWnd;                    { Owning window }
    lpszCaption: PChar;                 { Dialog caption bar contents }
    lpfnHook: TFNOleUIHook;             { Hook callback }
    lCustData: Longint;                 { Custom data to pass to hook }
    hInstance: THandle;                 { Instance for customized template name }
    lpszTemplate: PChar;                { Customized template name }
    hResource: HRsrc;                   { Customized template handle }
    clsid: TCLSID;                      { OUT: Return space for class ID }
    lpszFile: PChar;                    { IN-OUT: Filename for inserts or links }
    cchFile: Integer;                   { IN: Size of lpszFile buffer: MAX_PATH }
    cClsidExclude: Integer;             { IN: CLSIDs in lpClsidExclude }
    lpClsidExclude: PCLSID;             { IN: List of CLSIDs to exclude from listing }
    iid: TIID;                          { IN: Requested interface on creation }
    oleRender: Longint;                 { IN: Rendering option }
    lpFormatEtc: PFormatEtc;            { IN: Desired format }
    lpIOleClientSite: IOleClientSite;   { IN: Site to be use for the object }
    lpIStorage: IStorage;               { IN: Storage used for the object }
    ppvObj: Pointer;                    { OUT: Where the object is returned }
    sc: HResult;                        { OUT: Result of creation calls }
    hMetaPict: HGlobal;                 { OUT: metafile aspect (METAFILEPICT) }
  end;
  TOleUIInsertObject = tagOLEUIINSERTOBJECTA;

{ Insert object dialog function }

function OleUIInsertObject(var Info: TOleUIInsertObject): Integer; stdcall;
{$EXTERNALSYM OleUIInsertObject}

{ Insert Object flags }

const
  {$EXTERNALSYM IOF_SHOWHELP}
  IOF_SHOWHELP                    = $00000001;
  {$EXTERNALSYM IOF_SELECTCREATENEW}
  IOF_SELECTCREATENEW             = $00000002;
  {$EXTERNALSYM IOF_SELECTCREATEFROMFILE}
  IOF_SELECTCREATEFROMFILE        = $00000004;
  {$EXTERNALSYM IOF_CHECKLINK}
  IOF_CHECKLINK                   = $00000008;
  {$EXTERNALSYM IOF_CHECKDISPLAYASICON}
  IOF_CHECKDISPLAYASICON          = $00000010;
  {$EXTERNALSYM IOF_CREATENEWOBJECT}
  IOF_CREATENEWOBJECT             = $00000020;
  {$EXTERNALSYM IOF_CREATEFILEOBJECT}
  IOF_CREATEFILEOBJECT            = $00000040;
  {$EXTERNALSYM IOF_CREATELINKOBJECT}
  IOF_CREATELINKOBJECT            = $00000080;
  {$EXTERNALSYM IOF_DISABLELINK}
  IOF_DISABLELINK                 = $00000100;
  {$EXTERNALSYM IOF_VERIFYSERVERSEXIST}
  IOF_VERIFYSERVERSEXIST          = $00000200;
  {$EXTERNALSYM IOF_DISABLEDISPLAYASICON}
  IOF_DISABLEDISPLAYASICON        = $00000400;
  {$EXTERNALSYM IOF_HIDECHANGEICON}
  IOF_HIDECHANGEICON              = $00000800;
  {$EXTERNALSYM IOF_SHOWINSERTCONTROL}
  IOF_SHOWINSERTCONTROL           = $00001000;
  {$EXTERNALSYM IOF_SELECTCREATECONTROL}
  IOF_SELECTCREATECONTROL         = $00002000;

{ Insert Object specific error codes }

const
  {$EXTERNALSYM OLEUI_IOERR_LPSZFILEINVALID}
  OLEUI_IOERR_LPSZFILEINVALID         = OLEUI_ERR_STANDARDMAX + 0;
  {$EXTERNALSYM OLEUI_IOERR_LPSZLABELINVALID}
  OLEUI_IOERR_LPSZLABELINVALID        = OLEUI_ERR_STANDARDMAX + 1;
  {$EXTERNALSYM OLEUI_IOERR_HICONINVALID}
  OLEUI_IOERR_HICONINVALID            = OLEUI_ERR_STANDARDMAX + 2;
  {$EXTERNALSYM OLEUI_IOERR_LPFORMATETCINVALID}
  OLEUI_IOERR_LPFORMATETCINVALID      = OLEUI_ERR_STANDARDMAX + 3;
  {$EXTERNALSYM OLEUI_IOERR_PPVOBJINVALID}
  OLEUI_IOERR_PPVOBJINVALID           = OLEUI_ERR_STANDARDMAX + 4;
  {$EXTERNALSYM OLEUI_IOERR_LPIOLECLIENTSITEINVALID}
  OLEUI_IOERR_LPIOLECLIENTSITEINVALID = OLEUI_ERR_STANDARDMAX + 5;
  {$EXTERNALSYM OLEUI_IOERR_LPISTORAGEINVALID}
  OLEUI_IOERR_LPISTORAGEINVALID       = OLEUI_ERR_STANDARDMAX + 6;
  {$EXTERNALSYM OLEUI_IOERR_SCODEHASERROR}
  OLEUI_IOERR_SCODEHASERROR           = OLEUI_ERR_STANDARDMAX + 7;
  {$EXTERNALSYM OLEUI_IOERR_LPCLSIDEXCLUDEINVALID}
  OLEUI_IOERR_LPCLSIDEXCLUDEINVALID   = OLEUI_ERR_STANDARDMAX + 8;
  {$EXTERNALSYM OLEUI_IOERR_CCHFILEINVALID}
  OLEUI_IOERR_CCHFILEINVALID          = OLEUI_ERR_STANDARDMAX + 9;

{ **** Paste Special dialog **** }

{ The OLEUIPASTE_xxx values are used by the TOleUIPasteEntry structure.

  OLEUIPASTE_ENABLEICON: If the container does not specify this flag for
       the entry in the TOleUIPasteEntry array passed as input to
       OleUIPasteSpecial, the DisplayAsIcon button will be unchecked and
       disabled when the the user selects the format that corresponds to
       the entry.

  OLEUIPASTE_PASTEONLY: Indicates that the entry in the TOleUIPasteEntry
       array is valid for pasting only.

  OLEUIPASTE_PASTE: Indicates that the entry in the TOleUIPasteEntry array
       is valid for pasting. It may also be valid for linking if any of
       the following linking flags are specified.

  If the entry in the TOleUIPasteEntry array is valid for linking, the
  following flags indicate which link types are acceptable by OR'ing
  together the appropriate OLEUIPASTE_LINKTYPE<#> values.

  These values correspond as follows to the array of link types passed to
  OleUIPasteSpecial:

    OLEUIPASTE_LINKTYPE1 = arrLinkTypes[0]
    OLEUIPASTE_LINKTYPE2 = arrLinkTypes[1]
    OLEUIPASTE_LINKTYPE3 = arrLinkTypes[2]
    OLEUIPASTE_LINKTYPE4 = arrLinkTypes[3]
    OLEUIPASTE_LINKTYPE5 = arrLinkTypes[4]
    OLEUIPASTE_LINKTYPE6 = arrLinkTypes[5]
    OLEUIPASTE_LINKTYPE7 = arrLinkTypes[6]
    OLEUIPASTE_LINKTYPE8 = arrLinkTypes[7]

  where,
    UINT arrLinkTypes[8] is an array of registered clipboard formats for
    linking. A maximium of 8 link types are allowed. }

const
  {$EXTERNALSYM OLEUIPASTE_ENABLEICON}
  OLEUIPASTE_ENABLEICON    = 2048;  { enable display as icon }
  {$EXTERNALSYM OLEUIPASTE_PASTEONLY}
  OLEUIPASTE_PASTEONLY     = 0;
  {$EXTERNALSYM OLEUIPASTE_PASTE}
  OLEUIPASTE_PASTE         = 512;
  {$EXTERNALSYM OLEUIPASTE_LINKANYTYPE}
  OLEUIPASTE_LINKANYTYPE   = 1024;
  {$EXTERNALSYM OLEUIPASTE_LINKTYPE1}
  OLEUIPASTE_LINKTYPE1     = 1;
  {$EXTERNALSYM OLEUIPASTE_LINKTYPE2}
  OLEUIPASTE_LINKTYPE2     = 2;
  {$EXTERNALSYM OLEUIPASTE_LINKTYPE3}
  OLEUIPASTE_LINKTYPE3     = 4;
  {$EXTERNALSYM OLEUIPASTE_LINKTYPE4}
  OLEUIPASTE_LINKTYPE4     = 8;
  {$EXTERNALSYM OLEUIPASTE_LINKTYPE5}
  OLEUIPASTE_LINKTYPE5     = 16;
  {$EXTERNALSYM OLEUIPASTE_LINKTYPE6}
  OLEUIPASTE_LINKTYPE6     = 32;
  {$EXTERNALSYM OLEUIPASTE_LINKTYPE7}
  OLEUIPASTE_LINKTYPE7     = 64;
  {$EXTERNALSYM OLEUIPASTE_LINKTYPE8}
  OLEUIPASTE_LINKTYPE8     = 128;

{ TOleUIPasteEntry structure

  An array of TOleUIPasteEntry entries is specified for the PasteSpecial
  dialog box. Each entry includes a TFormatEtc which specifies the
  formats that are acceptable, a string that is to represent the format
  in the  dialog's list box, a string to customize the result text of the
  dialog and a set of flags from the OLEUIPASTE_xxx constants.  The
  flags indicate if the entry is valid for pasting only, linking only or
  both pasting and linking. }

type
  POleUIPasteEntry = ^TOleUIPasteEntry;
  {$EXTERNALSYM tagOLEUIPASTEENTRYA}
  tagOLEUIPASTEENTRYA = record
    fmtetc: TFormatEtc;         { Format that is acceptable }
    lpstrFormatName: PChar;     { String that represents the format
                                  to the user. %s is replaced by the
                                  full user type name of the object }
    lpstrResultText: PChar;     { String to customize the result text
                                  of the dialog when the user
                                  selects the format correspoding to
                                  this entry. Any %s in this string
                                  is replaced by the the application
                                  name or FullUserTypeName of the
                                  object on the clipboard }
    dwFlags: Longint;           { Values from OLEUIPASTE_xxx set }
    dwScratchSpace: Longint;    { Scratch space used internally }
  end;
  TOleUIPasteEntry = tagOLEUIPASTEENTRYA;
  {$EXTERNALSYM OLEUIPASTEENTRY}
  OLEUIPASTEENTRY = tagOLEUIPASTEENTRYA;

{ Maximum number of link types }

const
  {$EXTERNALSYM PS_MAXLINKTYPES}
  PS_MAXLINKTYPES = 8;

type
  POleUIPasteSpecial = ^TOleUIPasteSpecial;
  {$EXTERNALSYM tagOLEUIPASTESPECIALA}
  tagOLEUIPASTESPECIALA = record
    cbStruct: Longint;                  { Structure Size }
    dwFlags: Longint;                   { IN-OUT: Flags }
    hWndOwner: HWnd;                    { Owning window }
    lpszCaption: PChar;                 { Dialog caption bar contents }
    lpfnHook: TFNOleUIHook;             { Hook callback }
    lCustData: Longint;                 { Custom data to pass to hook }
    hInstance: THandle;                 { Instance for customized template name }
    lpszTemplate: PChar;                { Customized template name }
    hResource: HRsrc;                   { Customized template handle }
    lpSrcDataObj: IDataObject;          { IN-OUT: Source IDataObject on the clipboard }
    arrPasteEntries: POleUIPasteEntry;  { IN: Array of acceptable formats }
    cPasteEntries: Integer;             { IN: No. of TOleUIPasteEntry array entries }
    arrLinkTypes: PLongint;             { IN: List of acceptable link types }
    cLinkTypes: Integer;                { IN: Number of link types }
    cClsidExclude: Integer;             { IN: Number of CLSIDs in lpClsidExclude }
    lpClsidExclude: PCLSID;             { IN: List of CLSIDs to exclude from list }
    nSelectedIndex: Integer;            { OUT: Index that the user selected }
    fLink: BOOL;                        { OUT: Indicates if Paste or PasteLink }
    hMetaPict: HGlobal;                 { OUT: Handle to Metafile containing icon }
    sizel: TSize;                       { OUT: size of object/link in its source
                                          may be 0,0 if different display
                                          aspect is chosen }
  end;
  TOleUIPasteSpecial = tagOLEUIPASTESPECIALA;

function OleUIPasteSpecial(var Info: TOleUIPasteSpecial): Integer; stdcall;
{$EXTERNALSYM OleUIPasteSpecial}

{ Paste Special specific flags }

const
  {$EXTERNALSYM PSF_SHOWHELP}
  PSF_SHOWHELP                    = $00000001;
  {$EXTERNALSYM PSF_SELECTPASTE}
  PSF_SELECTPASTE                 = $00000002;
  {$EXTERNALSYM PSF_SELECTPASTELINK}
  PSF_SELECTPASTELINK             = $00000004;
  {$EXTERNALSYM PSF_CHECKDISPLAYASICON}
  PSF_CHECKDISPLAYASICON          = $00000008;
  {$EXTERNALSYM PSF_DISABLEDISPLAYASICON}
  PSF_DISABLEDISPLAYASICON        = $00000010;
  {$EXTERNALSYM PSF_HIDECHANGEICON}
  PSF_HIDECHANGEICON              = $00000020;
  {$EXTERNALSYM PSF_STAYONCLIPBOARDCHANGE}
  PSF_STAYONCLIPBOARDCHANGE       = $00000040;
  {$EXTERNALSYM PSF_NOREFRESHDATAOBJECT}
  PSF_NOREFRESHDATAOBJECT         = $00000080;

{ Paste Special specific error codes }

const
  {$EXTERNALSYM OLEUI_IOERR_SRCDATAOBJECTINVALID}
  OLEUI_IOERR_SRCDATAOBJECTINVALID   = OLEUI_ERR_STANDARDMAX + 0;
  {$EXTERNALSYM OLEUI_IOERR_ARRPASTEENTRIESINVALID}
  OLEUI_IOERR_ARRPASTEENTRIESINVALID = OLEUI_ERR_STANDARDMAX + 1;
  {$EXTERNALSYM OLEUI_IOERR_ARRLINKTYPESINVALID}
  OLEUI_IOERR_ARRLINKTYPESINVALID    = OLEUI_ERR_STANDARDMAX + 2;
  {$EXTERNALSYM OLEUI_PSERR_CLIPBOARDCHANGED}
  OLEUI_PSERR_CLIPBOARDCHANGED       = OLEUI_ERR_STANDARDMAX + 3;
  {$EXTERNALSYM OLEUI_PSERR_GETCLIPBOARDFAILED}
  OLEUI_PSERR_GETCLIPBOARDFAILED     = OLEUI_ERR_STANDARDMAX + 4;

{ **** Edit Links dialog **** }

{ IOleUILinkContainer interface

  This interface must be implemented by container applications that
  want to use the EditLinks dialog. the EditLinks dialog calls back
  to the container app to perform the OLE functions to manipulate
  the links within the container. }

type
  IOleUILinkContainer = interface(IUnknown)
  ['{00000000-0000-0000-0000-000000000000}']  //!!!
    function GetNextLink(dwLink: Longint): Longint; stdcall;
    function SetLinkUpdateOptions(dwLink: Longint; dwUpdateOpt: Longint): HResult; stdcall;
    function GetLinkUpdateOptions(dwLink: Longint;
      var dwUpdateOpt: Longint): HResult; stdcall;
    function SetLinkSource(dwLink: Longint; pszDisplayName: PChar;
      lenFileName: Longint; var chEaten: Longint;
      fValidateSource: BOOL): HResult; stdcall;
    function GetLinkSource(dwLink: Longint; var pszDisplayName: PChar;
      var lenFileName: Longint; var pszFullLinkType: PChar;
      var pszShortLinkType: PChar; var fSourceAvailable: BOOL;
      var fIsSelected: BOOL): HResult; stdcall;
    function OpenLinkSource(dwLink: Longint): HResult; stdcall;
    function UpdateLink(dwLink: Longint; fErrorMessage: BOOL;
      fErrorAction: BOOL): HResult; stdcall;
    function CancelLink(dwLink: Longint): HResult; stdcall;
  end;
  {$EXTERNALSYM IOleUILinkContainer}

{ TOleIUEditLinks structure }

type
  POleUIEditLinks = ^TOleUIEditLinks;
  {$EXTERNALSYM tagOLEUIEDITLINKSA}
  tagOLEUIEDITLINKSA = record
    cbStruct: Longint;                  { Structure Size }
    dwFlags: Longint;                   { IN-OUT: Flags }
    hWndOwner: HWnd;                    { Owning window }
    lpszCaption: PChar;                 { Dialog caption bar contents }
    lpfnHook: TFNOleUIHook;             { Hook callback }
    lCustData: Longint;                 { Custom data to pass to hook }
    hInstance: THandle;                 { Instance for customized template name }
    lpszTemplate: PChar;                { Customized template name }
    hResource: HRsrc;                   { Customized template handle }
    OleUILinkContainer: IOleUILinkContainer; { IN: Interface to manipulate
                                          links in the container }
  end;
  TOleUIEditLinks = tagOLEUIEDITLINKSA;

const
  {$EXTERNALSYM OLEUI_ELERR_LINKCNTRNULL}
  OLEUI_ELERR_LINKCNTRNULL    = OLEUI_ERR_STANDARDMAX + 0;
  {$EXTERNALSYM OLEUI_ELERR_LINKCNTRINVALID}
  OLEUI_ELERR_LINKCNTRINVALID = OLEUI_ERR_STANDARDMAX + 1;

{$EXTERNALSYM OleUIEditLinks}
function OleUIEditLinks(var Info: TOleUIEditLinks): Integer; stdcall;

{ Edit Links flags }

const
  {$EXTERNALSYM ELF_SHOWHELP}
  ELF_SHOWHELP                    = $00000001;
  {$EXTERNALSYM ELF_DISABLEUPDATENOW}
  ELF_DISABLEUPDATENOW            = $00000002;
  {$EXTERNALSYM ELF_DISABLEOPENSOURCE}
  ELF_DISABLEOPENSOURCE           = $00000004;
  {$EXTERNALSYM ELF_DISABLECHANGESOURCE}
  ELF_DISABLECHANGESOURCE         = $00000008;
  {$EXTERNALSYM ELF_DISABLECANCELLINK}
  ELF_DISABLECANCELLINK           = $00000010;

{ **** Change Icon dialog **** }

type
  POleUIChangeIcon = ^TOleUIChangeIcon;
  {$EXTERNALSYM tagOLEUICHANGEICONA}
  tagOLEUICHANGEICONA = record
    cbStruct: Longint;                  { Structure Size }
    dwFlags: Longint;                   { IN-OUT: Flags }
    hWndOwner: HWnd;                    { Owning window }
    lpszCaption: PChar;                 { Dialog caption bar contents }
    lpfnHook: TFNOleUIHook;             { Hook callback }
    lCustData: Longint;                 { Custom data to pass to hook }
    hInstance: THandle;                 { Instance for customized template name }
    lpszTemplate: PChar;                { Customized template name }
    hResource: HRsrc;                   { Customized template handle }
    hMetaPict: HGlobal;                 { IN-OUT: Current and final image.
                                          Source of the icon is embedded in
                                          the metafile itself }
    clsid: TCLSID;                      { IN: class used to get Default icon }
    szIconExe: array[0..MAX_PATH - 1] of Char; { IN: exlicit icon source path }
    cchIconExe: Integer;                { IN: number of characters in szIconExe }
  end;
  TOleUIChangeIcon = tagOLEUICHANGEICONA;

{$EXTERNALSYM OleUIChangeIcon}
function OleUIChangeIcon(var Info: TOleUIChangeIcon): Integer; stdcall;

{ Change Icon flags }

const
  {$EXTERNALSYM CIF_SHOWHELP}
  CIF_SHOWHELP                    = $00000001;
  {$EXTERNALSYM CIF_SELECTCURRENT}
  CIF_SELECTCURRENT               = $00000002;
  {$EXTERNALSYM CIF_SELECTDEFAULT}
  CIF_SELECTDEFAULT               = $00000004;
  {$EXTERNALSYM CIF_SELECTFROMFILE}
  CIF_SELECTFROMFILE              = $00000008;
  {$EXTERNALSYM CIF_USEICONEXE}
  CIF_USEICONEXE                  = $00000010;

{ Change Icon specific error codes }

const
  {$EXTERNALSYM OLEUI_CIERR_MUSTHAVECLSID}
  OLEUI_CIERR_MUSTHAVECLSID           = OLEUI_ERR_STANDARDMAX + 0;
  {$EXTERNALSYM OLEUI_CIERR_MUSTHAVECURRENTMETAFILE}
  OLEUI_CIERR_MUSTHAVECURRENTMETAFILE = OLEUI_ERR_STANDARDMAX + 1;
  {$EXTERNALSYM OLEUI_CIERR_SZICONEXEINVALID}
  OLEUI_CIERR_SZICONEXEINVALID        = OLEUI_ERR_STANDARDMAX + 2;

{ Property used by ChangeIcon dialog to give its parent window access to
  its hDlg. The PasteSpecial dialog may need to force the ChgIcon dialog
  down if the clipboard contents change underneath it. If so it will send
  a IDCANCEL command to the ChangeIcon dialog. }

const
  {$EXTERNALSYM PROP_HWND_CHGICONDLG}
  PROP_HWND_CHGICONDLG = 'HWND_CIDLG';

{ **** Convert dialog **** }

type
  POleUIConvert = ^TOleUIConvert;
  {$EXTERNALSYM tagOLEUICONVERTA}
  tagOLEUICONVERTA = record
    cbStruct: Longint;                  { Structure Size }
    dwFlags: Longint;                   { IN-OUT: Flags }
    hWndOwner: HWnd;                    { Owning window }
    lpszCaption: PChar;                 { Dialog caption bar contents }
    lpfnHook: TFNOleUIHook;             { Hook callback }
    lCustData: Longint;                 { Custom data to pass to hook }
    hInstance: THandle;                 { Instance for customized template name }
    lpszTemplate: PChar;                { Customized template name }
    hResource: HRsrc;                   { Customized template handle }
    clsid: TCLSID;                      { IN: Class ID sent in to dialog: IN only }
    clsidConvertDefault: TCLSID;        { IN: use as convert default: IN only }
    clsidActivateDefault: TCLSID;       { IN: use as activate default: IN only }
    clsidNew: TCLSID;                   { OUT: Selected Class ID }
    dvAspect: Longint;                  { IN-OUT: either DVASPECT_CONTENT or
                                          DVASPECT_ICON }
    wFormat: Word;                      { IN" Original data format }
    fIsLinkedObject: BOOL;              { IN: true if object is linked }
    hMetaPict: HGlobal;                 { IN-OUT: metafile icon image }
    lpszUserType: PChar;                { IN-OUT: user type name of original class.
                                          We'll do lookup if NULL. This gets freed
                                          on exit }
    fObjectsIconChanged: BOOL;          { OUT: TRUE == ChangeIcon was called }
    lpszDefLabel: PChar;                { IN-OUT: default label to use for icon.
                                          if NULL, the short user type name
                                          will be used. if the object is a
                                          link, the caller should pass the
                                          DisplayName of the link source
                                          This gets freed on exit }
    cClsidExclude: Integer;             { IN: No. of CLSIDs in lpClsidExclude }
    lpClsidExclude: PCLSID;             { IN: List of CLSIDs to exclude from list }
  end;
  TOleUIConvert = tagOLEUICONVERTA;

{$EXTERNALSYM OleUIConvert}
function OleUIConvert(var Info: TOleUIConvert): Integer; stdcall;

{ Determine if there is at least one class that can Convert or ActivateAs
  the given clsid }

{$EXTERNALSYM OleUICanConvertOrActivateAs}
function OleUICanConvertOrActivateAs(const clsid: TCLSID;
  fIsLinkedObject: BOOL; wFormat: Word): BOOL; stdcall;

{ Convert Dialog flags }

const
  {$EXTERNALSYM CF_SHOWHELPBUTTON}
  CF_SHOWHELPBUTTON               = $00000001;
  {$EXTERNALSYM CF_SETCONVERTDEFAULT}
  CF_SETCONVERTDEFAULT            = $00000002;
  {$EXTERNALSYM CF_SETACTIVATEDEFAULT}
  CF_SETACTIVATEDEFAULT           = $00000004;
  {$EXTERNALSYM CF_SELECTCONVERTTO}
  CF_SELECTCONVERTTO              = $00000008;
  {$EXTERNALSYM CF_SELECTACTIVATEAS}
  CF_SELECTACTIVATEAS             = $00000010;
  {$EXTERNALSYM CF_DISABLEDISPLAYASICON}
  CF_DISABLEDISPLAYASICON         = $00000020;
  {$EXTERNALSYM CF_DISABLEACTIVATEAS}
  CF_DISABLEACTIVATEAS            = $00000040;
  {$EXTERNALSYM CF_HIDECHANGEICON}
  CF_HIDECHANGEICON               = $00000080;
  {$EXTERNALSYM CF_CONVERTONLY}
  CF_CONVERTONLY                  = $00000100;

{ Convert specific error codes }

const
  {$EXTERNALSYM OLEUI_CTERR_CLASSIDINVALID}
  OLEUI_CTERR_CLASSIDINVALID      = OLEUI_ERR_STANDARDMAX + 1;
  {$EXTERNALSYM OLEUI_CTERR_DVASPECTINVALID}
  OLEUI_CTERR_DVASPECTINVALID     = OLEUI_ERR_STANDARDMAX + 2;
  {$EXTERNALSYM OLEUI_CTERR_CBFORMATINVALID}
  OLEUI_CTERR_CBFORMATINVALID     = OLEUI_ERR_STANDARDMAX + 3;
  {$EXTERNALSYM OLEUI_CTERR_HMETAPICTINVALID}
  OLEUI_CTERR_HMETAPICTINVALID    = OLEUI_ERR_STANDARDMAX + 4;
  {$EXTERNALSYM OLEUI_CTERR_STRINGINVALID}
  OLEUI_CTERR_STRINGINVALID       = OLEUI_ERR_STANDARDMAX + 5;

{ **** Busy dialog **** }

type
  POleUIBusy = ^TOleUIBusy;
  {$EXTERNALSYM tagOLEUIBUSYA}
  tagOLEUIBUSYA = record
    cbStruct: Longint;                  { Structure Size }
    dwFlags: Longint;                   { IN-OUT: Flags }
    hWndOwner: HWnd;                    { Owning window }
    lpszCaption: PChar;                 { Dialog caption bar contents }
    lpfnHook: TFNOleUIHook;             { Hook callback }
    lCustData: Longint;                 { Custom data to pass to hook }
    hInstance: THandle;                 { Instance for customized template name }
    lpszTemplate: PChar;                { Customized template name }
    hResource: HRsrc;                   { Customized template handle }
    task: HTask;                        { IN: HTask which is blocking }
    lphWndDialog: ^HWnd;                { IN: Dialog's HWND is placed here }
  end;
  TOleUIBusy = tagOLEUIBUSYA;

{$EXTERNALSYM OleUIBusy}
function OleUIBusy(var Info: TOleUIBusy): Integer; stdcall;

{ Flags for the Busy dialog }

const
  {$EXTERNALSYM BZ_DISABLECANCELBUTTON}
  BZ_DISABLECANCELBUTTON          = $00000001;
  {$EXTERNALSYM BZ_DISABLESWITCHTOBUTTON}
  BZ_DISABLESWITCHTOBUTTON        = $00000002;
  {$EXTERNALSYM BZ_DISABLERETRYBUTTON}
  BZ_DISABLERETRYBUTTON           = $00000004;
  {$EXTERNALSYM BZ_NOTRESPONDINGDIALOG}
  BZ_NOTRESPONDINGDIALOG          = $00000008;

{ Busy specific error/return codes }

const
  {$EXTERNALSYM OLEUI_BZERR_HTASKINVALID}
  OLEUI_BZERR_HTASKINVALID     = OLEUI_ERR_STANDARDMAX + 0;
  {$EXTERNALSYM OLEUI_BZ_SWITCHTOSELECTED}
  OLEUI_BZ_SWITCHTOSELECTED    = OLEUI_ERR_STANDARDMAX + 1;
  {$EXTERNALSYM OLEUI_BZ_RETRYSELECTED}
  OLEUI_BZ_RETRYSELECTED       = OLEUI_ERR_STANDARDMAX + 2;
  {$EXTERNALSYM OLEUI_BZ_CALLUNBLOCKED}
  OLEUI_BZ_CALLUNBLOCKED       = OLEUI_ERR_STANDARDMAX + 3;

{ **** Object Properties dialog **** }

type
  IOleUIObjInfo = interface(IUnknown)
  ['{00000000-0000-0000-0000-000000000000}'] //!!!
    function GetObjectInfo(dwObject: Longint;
      var dwObjSize: Longint; var lpszLabel: PChar;
      var lpszType: PChar; var lpszShortType: PChar;
      var lpszLocation: PChar): HResult; stdcall;
    function GetConvertInfo(dwObject: Longint; var ClassID: TCLSID;
      var wFormat: Word; var ConvertDefaultClassID: TCLSID;
      var lpClsidExclude: PCLSID; var cClsidExclude: Longint): HResult; stdcall;
    function ConvertObject(dwObject: Longint; const clsidNew: TCLSID): HResult; stdcall;
    function GetViewInfo(dwObject: Longint; var hMetaPict: HGlobal;
      var dvAspect: Longint; var nCurrentScale: Integer): HResult; stdcall;
    function SetViewInfo(dwObject: Longint; hMetaPict: HGlobal;
      dvAspect: Longint; nCurrentScale: Integer;
      bRelativeToOrig: BOOL): HResult; stdcall;
  end;
  {$EXTERNALSYM IOleUIObjInfo}

type
  IOleUILinkInfo = interface(IOleUILinkContainer)
  ['{00000000-0000-0000-0000-000000000000}']  //!!!
    function GetLastUpdate(dwLink: Longint; var LastUpdate: TFileTime): HResult; stdcall;
  end;
  {$EXTERNALSYM IOleUILinkInfo}

type
  POleUIGnrlProps = ^TOleUIGnrlProps;
  {$EXTERNALSYM tagOLEUIGNRLPROPSA}
  tagOLEUIGNRLPROPSA = record
    cbStruct: Longint;
    dwFlags: Longint;
    dwReserved1: array[1..2] of Longint;
    lpfnHook: TFNOleUIHook;
    lCustData: Longint;
    dwReserved2: array[1..3] of Longint;
    lpOP: Pointer;
  end;
  TOleUIGnrlProps = tagOLEUIGNRLPROPSA;
  {$EXTERNALSYM OLEUIGNRLPROPS}
  OLEUIGNRLPROPS = tagOLEUIGNRLPROPSA;

type
  POleUIViewProps = ^TOleUIViewProps;
  {$EXTERNALSYM tagOLEUIVIEWPROPSA}
  tagOLEUIVIEWPROPSA = record
    cbStruct: Longint;
    dwFlags: Longint;
    dwReserved1: array[1..2] of Longint;
    lpfnHook: TFNOleUIHook;
    lCustData: Longint;
    dwReserved2: array[1..3] of Longint;
    lpOP: Pointer;
    nScaleMin: Integer;
    nScaleMax: Integer;
  end;
  TOleUIViewProps = tagOLEUIVIEWPROPSA;
  {$EXTERNALSYM OLEUIVIEWPROPS}
  OLEUIVIEWPROPS = tagOLEUIVIEWPROPSA;

{ Flags for TOleUIViewProps }

const
  {$EXTERNALSYM VPF_SELECTRELATIVE}
  VPF_SELECTRELATIVE          = $00000001;  { IN: relative to orig }
  {$EXTERNALSYM VPF_DISABLERELATIVE}
  VPF_DISABLERELATIVE         = $00000002;  { IN: disable relative to orig }
  {$EXTERNALSYM VPF_DISABLESCALE}
  VPF_DISABLESCALE            = $00000004;  { IN: disable scale option }

type
  POleUILinkProps = ^TOleUILinkProps;
  {$EXTERNALSYM tagOLEUILINKPROPSA}
  tagOLEUILINKPROPSA = record
    cbStruct: Longint;
    dwFlags: Longint;
    dwReserved1: array[1..2] of Longint;
    lpfnHook: TFNOleUIHook;
    lCustData: Longint;
    dwReserved2: array[1..3] of Longint;
    lpOP: Pointer;
  end;
  TOleUILinkProps = tagOLEUILINKPROPSA;
  {$EXTERNALSYM OLEUILINKPROPS}
  OLEUILINKPROPS = tagOLEUILINKPROPSA;

type
  POleUIObjectProps = ^TOleUIObjectProps;
  {$EXTERNALSYM tagOLEUIOBJECTPROPSA}
  tagOLEUIOBJECTPROPSA = record
    cbStruct: Longint;          { Structure Size }
    dwFlags: Longint;           { IN-OUT: global flags for the sheet }
    lpPS: PPropSheetHeader;     { IN: property sheet header }
    dwObject: Longint;          { IN: identifier for the object }
    lpObjInfo: IOleUIObjInfo;   { IN: interface to manipulate object }
    dwLink: Longint;            { IN: identifier for the link }
    lpLinkInfo: IOleUILinkInfo; { IN: interface to manipulate link }
    lpGP: POleUIGnrlProps;      { IN: general page }
    lpVP: POleUIViewProps;      { IN: view page }
    lpLP: POleUILinkProps;      { IN: link page }
  end;
  TOleUIObjectProps = tagOLEUIOBJECTPROPSA;
  {$EXTERNALSYM OLEUIOBJECTPROPS}
  OLEUIOBJECTPROPS = tagOLEUIOBJECTPROPSA;

{$EXTERNALSYM OleUIObjectProperties}
function OleUIObjectProperties(var Info: TOleUIObjectProps): Integer; stdcall;

{ Flags for OLEUIOBJECTPROPS }

const
  {$EXTERNALSYM OPF_OBJECTISLINK}
  OPF_OBJECTISLINK                = $00000001;
  {$EXTERNALSYM OPF_NOFILLDEFAULT}
  OPF_NOFILLDEFAULT               = $00000002;
  {$EXTERNALSYM OPF_SHOWHELP}
  OPF_SHOWHELP                    = $00000004;
  {$EXTERNALSYM OPF_DISABLECONVERT}
  OPF_DISABLECONVERT              = $00000008;

{ Errors for OleUIObjectProperties }

const
  {$EXTERNALSYM OLEUI_OPERR_SUBPROPNULL}
  OLEUI_OPERR_SUBPROPNULL           = OLEUI_ERR_STANDARDMAX + 0;
  {$EXTERNALSYM OLEUI_OPERR_SUBPROPINVALID}
  OLEUI_OPERR_SUBPROPINVALID        = OLEUI_ERR_STANDARDMAX + 1;
  {$EXTERNALSYM OLEUI_OPERR_PROPSHEETNULL}
  OLEUI_OPERR_PROPSHEETNULL         = OLEUI_ERR_STANDARDMAX + 2;
  {$EXTERNALSYM OLEUI_OPERR_PROPSHEETINVALID}
  OLEUI_OPERR_PROPSHEETINVALID      = OLEUI_ERR_STANDARDMAX + 3;
  {$EXTERNALSYM OLEUI_OPERR_SUPPROP}
  OLEUI_OPERR_SUPPROP               = OLEUI_ERR_STANDARDMAX + 4;
  {$EXTERNALSYM OLEUI_OPERR_PROPSINVALID}
  OLEUI_OPERR_PROPSINVALID          = OLEUI_ERR_STANDARDMAX + 5;
  {$EXTERNALSYM OLEUI_OPERR_PAGESINCORRECT}
  OLEUI_OPERR_PAGESINCORRECT        = OLEUI_ERR_STANDARDMAX + 6;
  {$EXTERNALSYM OLEUI_OPERR_INVALIDPAGES}
  OLEUI_OPERR_INVALIDPAGES          = OLEUI_ERR_STANDARDMAX + 7;
  {$EXTERNALSYM OLEUI_OPERR_NOTSUPPORTED}
  OLEUI_OPERR_NOTSUPPORTED          = OLEUI_ERR_STANDARDMAX + 8;
  {$EXTERNALSYM OLEUI_OPERR_DLGPROCNOTNULL}
  OLEUI_OPERR_DLGPROCNOTNULL        = OLEUI_ERR_STANDARDMAX + 9;
  {$EXTERNALSYM OLEUI_OPERR_LPARAMNOTZERO}
  OLEUI_OPERR_LPARAMNOTZERO         = OLEUI_ERR_STANDARDMAX + 10;
  {$EXTERNALSYM OLEUI_GPERR_STRINGINVALID}
  OLEUI_GPERR_STRINGINVALID         = OLEUI_ERR_STANDARDMAX + 11;
  {$EXTERNALSYM OLEUI_GPERR_CLASSIDINVALID}
  OLEUI_GPERR_CLASSIDINVALID        = OLEUI_ERR_STANDARDMAX + 12;
  {$EXTERNALSYM OLEUI_GPERR_LPCLSIDEXCLUDEINVALID}
  OLEUI_GPERR_LPCLSIDEXCLUDEINVALID = OLEUI_ERR_STANDARDMAX + 13;
  {$EXTERNALSYM OLEUI_GPERR_CBFORMATINVALID}
  OLEUI_GPERR_CBFORMATINVALID       = OLEUI_ERR_STANDARDMAX + 14;
  {$EXTERNALSYM OLEUI_VPERR_METAPICTINVALID}
  OLEUI_VPERR_METAPICTINVALID       = OLEUI_ERR_STANDARDMAX + 15;
  {$EXTERNALSYM OLEUI_VPERR_DVASPECTINVALID}
  OLEUI_VPERR_DVASPECTINVALID       = OLEUI_ERR_STANDARDMAX + 16;
  {$EXTERNALSYM OLEUI_LPERR_LINKCNTRNULL}
  OLEUI_LPERR_LINKCNTRNULL          = OLEUI_ERR_STANDARDMAX + 17;
  {$EXTERNALSYM OLEUI_LPERR_LINKCNTRINVALID}
  OLEUI_LPERR_LINKCNTRINVALID       = OLEUI_ERR_STANDARDMAX + 18;
  {$EXTERNALSYM OLEUI_OPERR_PROPERTYSHEET}
  OLEUI_OPERR_PROPERTYSHEET         = OLEUI_ERR_STANDARDMAX + 19;

{ wParam used by PSM_QUERYSIBLINGS }

const
  {$EXTERNALSYM OLEUI_QUERY_GETCLASSID}
  OLEUI_QUERY_GETCLASSID          = $FF00;  { override class id for icon }
  {$EXTERNALSYM OLEUI_QUERY_LINKBROKEN}
  OLEUI_QUERY_LINKBROKEN          = $FF01;  { after link broken }

implementation

const
  OleDlgDLL = 'oledlg.dll';

function OleUIAddVerbMenu;              external OleDlgDLL name 'OleUIAddVerbMenuA';
function OleUIInsertObject;             external OleDlgDLL name 'OleUIInsertObjectA';
function OleUIPasteSpecial;             external OleDlgDLL name 'OleUIPasteSpecialA';
function OleUIEditLinks;                external OleDlgDLL name 'OleUIEditLinksA';
function OleUIChangeIcon;               external OleDlgDLL name 'OleUIChangeIconA';
function OleUIConvert;                  external OleDlgDLL name 'OleUIConvertA';
function OleUICanConvertOrActivateAs;   external OleDlgDLL name 'OleUICanConvertOrActivateAs';
function OleUIBusy;                     external OleDlgDLL name 'OleUIBusyA';
function OleUIObjectProperties;         external OleDlgDLL name 'OleUIObjectPropertiesA';

end.
