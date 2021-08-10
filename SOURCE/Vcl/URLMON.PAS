
{*******************************************************}
{                                                       }
{       Borland Delphi Runtime Library                  }
{       URL Moniker support interface unit              }
{                                                       }
{       Copyright (C) 1995-1998, Microsoft Corporation. }
{       All Rights Reserved.                            }
{                                                       }
{       Obtained on behalf of Inprise through:          }
{       Joint Endeavour of Delphi Innovators (JEDI)     }
{       http://www.delphi-jedi.org                      }
{       Translator: Rudolph Velthuis                    }
{                                                       }
{*******************************************************}

unit UrlMon;

{$WEAKPACKAGEUNIT}

interface

uses
  Windows, ActiveX;

{$HPPEMIT '//---------------------------------------------------------------------------'}
{$HPPEMIT '// if compilation errors occur while attempting to access structs, unions, or enums'}
{$HPPEMIT '// define NO_WIN32_LEAN_AND_MEAN so that the appropriate windows headers are included.'}
{$HPPEMIT '//---------------------------------------------------------------------------'}
{$HPPEMIT '#if defined(NO_WIN32_LEAN_AND_MEAN)'}
{$HPPEMIT '#include "rpc.h"'}
{$HPPEMIT '#include "rpcndr.h"'}
{$HPPEMIT '#include "urlmon.h"'}
{$HPPEMIT '  #ifndef COM_NO_WINDOWS_H'}
{$HPPEMIT '  #include "windows.h" '}
{$HPPEMIT '  #include "ole2.h"'}
{$HPPEMIT '  #endif'}
{$HPPEMIT '#endif'}

{$HPPEMIT 'DECLARE_DINTERFACE_TYPE(IPersistMoniker);'}
{$HPPEMIT 'DECLARE_DINTERFACE_TYPE(IBindProtocol);'}
{$HPPEMIT 'DECLARE_DINTERFACE_TYPE(IBinding);'}
{$HPPEMIT 'DECLARE_DINTERFACE_TYPE(IBindStatusCallback);'}
{$HPPEMIT 'DECLARE_DINTERFACE_TYPE(IAuthenticate);'}
{$HPPEMIT 'DECLARE_DINTERFACE_TYPE(IHttpNegotiate);'}
{$HPPEMIT 'DECLARE_DINTERFACE_TYPE(IWindowForBindingUI);'}
{$HPPEMIT 'DECLARE_DINTERFACE_TYPE(ICodeInstall);'}
{$HPPEMIT 'DECLARE_DINTERFACE_TYPE(IWinInetInfo);'}
{$HPPEMIT 'DECLARE_DINTERFACE_TYPE(IHttpSecurity);'}
{$HPPEMIT 'DECLARE_DINTERFACE_TYPE(IWinInetHttpInfo);'}
{$HPPEMIT 'DECLARE_DINTERFACE_TYPE(IBindHost);'}
{$HPPEMIT 'DECLARE_DINTERFACE_TYPE(IInternet);'}
{$HPPEMIT 'DECLARE_DINTERFACE_TYPE(IInternetBindInfo);'}
{$HPPEMIT 'DECLARE_DINTERFACE_TYPE(IInternetProtocolRoot);'}
{$HPPEMIT 'DECLARE_DINTERFACE_TYPE(IInternetProtocol);'}
{$HPPEMIT 'DECLARE_DINTERFACE_TYPE(IInternetProtocolSink);'}
{$HPPEMIT 'DECLARE_DINTERFACE_TYPE(IInternetSession);'}
{$HPPEMIT 'DECLARE_DINTERFACE_TYPE(IInternetThreadSwitch);'}
{$HPPEMIT 'DECLARE_DINTERFACE_TYPE(IInternetPriority);'}
{$HPPEMIT 'DECLARE_DINTERFACE_TYPE(IInternetProtocolInfo);'}
{$HPPEMIT 'DECLARE_DINTERFACE_TYPE(IInternetSecurityMgrSite);'}
{$HPPEMIT 'DECLARE_DINTERFACE_TYPE(IInternetSecurityManager);'}
{$HPPEMIT 'DECLARE_DINTERFACE_TYPE(IInternetHostSecurityManager);'}
{$HPPEMIT 'DECLARE_DINTERFACE_TYPE(IInternetZoneManager);'}
{$HPPEMIT 'DECLARE_DINTERFACE_TYPE(ISoftDistExt);'}
{$HPPEMIT 'DECLARE_DINTERFACE_TYPE(IDataFilter);'}
{$HPPEMIT 'DECLARE_DINTERFACE_TYPE(IEncodingFilterFactory);'}
{$HPPEMIT '#if !defined(NO__WIN32_LEAN_AND_MEAN)'}
{$HPPEMIT 'struct _tagBINDINFO;'}
{$HPPEMIT 'struct _REMSECURITY_ATTRIBUTES;'}
{$HPPEMIT 'struct _tagRemBINDINFO;'}
{$HPPEMIT 'struct tagRemFORMATETC;'}
{$HPPEMIT 'struct _tagPROTOCOLDATA;'}
{$HPPEMIT 'struct _ZONEATTRIBUTES;'}
{$HPPEMIT 'struct _tagCODEBASEHOLD;'}
{$HPPEMIT 'struct _tagSOFTDISTINFO;'}
{$HPPEMIT 'struct _tagPROTOCOLFILTERDATA;'}
{$HPPEMIT 'struct _tagDATAINFO;'}
{$HPPEMIT 'struct _tagHIT_LOGGING_INFO;'}
{$HPPEMIT '#endif'}

const
  {$EXTERNALSYM SZ_URLCONTEXT}
  SZ_URLCONTEXT: POLEStr   = 'URL Context';
  {$EXTERNALSYM SZ_ASYNC_CALLEE}
  SZ_ASYNC_CALLEE: POLEStr = 'AsyncCallee';

  {$EXTERNALSYM MKSYS_URLMONIKER}
  MKSYS_URLMONIKER = 6;

const
  // GUIDs for interfaces declared in this unit

  {$EXTERNALSYM IID_IPersistMoniker}
  IID_IPersistMoniker:       TGUID = '{79eac9c9-baf9-11ce-8c82-00aa004ba90b}';
  {$EXTERNALSYM IID_IBinding}
  IID_IBinding:              TGUID = '{79eac9c0-baf9-11ce-8c82-00aa004ba90b}';
  {$EXTERNALSYM IID_IBindStatusCallback}
  IID_IBindStatusCallback:   TGUID = '{79eac9c1-baf9-11ce-8c82-00aa004ba90b}';
  {$EXTERNALSYM IID_IAuthenticate}
  IID_IAuthenticate:         TGUID = '{79eac9d0-baf9-11ce-8c82-00aa004ba90b}';
  {$EXTERNALSYM IID_IHttpNegotiate}
  IID_IHttpNegotiate:        TGUID = '{79eac9d2-baf9-11ce-8c82-00aa004ba90b}';
  {$EXTERNALSYM IID_IWindowForBindingUI}
  IID_IWindowForBindingUI:   TGUID = '{79eac9d5-bafa-11ce-8c82-00aa004ba90b}';
  {$EXTERNALSYM IID_ICodeInstall}
  IID_ICodeInstall:          TGUID = '{79eac9d1-baf9-11ce-8c82-00aa004ba90b}';
  {$EXTERNALSYM IID_IWinInetInfo}
  IID_IWinInetInfo:          TGUID = '{79eac9d6-bafa-11ce-8c82-00aa004ba90b}';
  {$EXTERNALSYM IID_IHttpSecurity}
  IID_IHttpSecurity:         TGUID = '{79eac9d7-bafa-11ce-8c82-00aa004ba90b}';
  {$EXTERNALSYM IID_IWinInetHttpInfo}
  IID_IWinInetHttpInfo:      TGUID = '{79eac9d8-bafa-11ce-8c82-00aa004ba90b}';

  {$EXTERNALSYM IID_IBindHost}
  IID_IBindHost:             TGUID = '{fc4801a1-2ba9-11cf-a229-00aa003d7352}';

  {$EXTERNALSYM IID_IInternet}
  IID_IInternet:             TGUID = '{79eac9e0-baf9-11ce-8c82-00aa004ba90b}';
  {$EXTERNALSYM IID_IInternetBindInfo}
  IID_IInternetBindInfo:     TGUID = '{79eac9e1-baf9-11ce-8c82-00aa004ba90b}';
  {$EXTERNALSYM IID_IInternetProtocolRoot}
  IID_IInternetProtocolRoot: TGUID = '{79eac9e3-baf9-11ce-8c82-00aa004ba90b}';
  {$EXTERNALSYM IID_IInternetProtocol}
  IID_IInternetProtocol:     TGUID = '{79eac9e4-baf9-11ce-8c82-00aa004ba90b}';
  {$EXTERNALSYM IID_IInternetProtocolSink}
  IID_IInternetProtocolSink: TGUID = '{79eac9e5-baf9-11ce-8c82-00aa004ba90b}';
  {$EXTERNALSYM IID_IInternetSession}
  IID_IInternetSession:      TGUID = '{79eac9e7-baf9-11ce-8c82-00aa004ba90b}';
  {$EXTERNALSYM IID_IInternetThreadSwitch}
  IID_IInternetThreadSwitch: TGUID = '{79eac9e8-baf9-11ce-8c82-00aa004ba90b}';
  {$EXTERNALSYM IID_IInternetPriority}
  IID_IInternetPriority:     TGUID = '{79eac9eb-baf9-11ce-8c82-00aa004ba90b}';
  {$EXTERNALSYM IID_IInternetProtocolInfo}
  IID_IInternetProtocolInfo: TGUID = '{79eac9ec-baf9-11ce-8c82-00aa004ba90b}';

  {$EXTERNALSYM SID_IBindHost}
  SID_IBindHost:             TGUID = '{fc4801a1-2ba9-11cf-a229-00aa003d7352}';
  {$EXTERNALSYM SID_SBindHost}
  SID_SBindHost:             TGUID = '{fc4801a1-2ba9-11cf-a229-00aa003d7352}';

  {$EXTERNALSYM IID_IOInet}
  IID_IOInet:                TGUID = '{79eac9e0-baf9-11ce-8c82-00aa004ba90b}';
  {$EXTERNALSYM IID_IOInetBindInfo}
  IID_IOInetBindInfo:        TGUID = '{79eac9e1-baf9-11ce-8c82-00aa004ba90b}';
  {$EXTERNALSYM IID_IOInetProtocolRoot}
  IID_IOInetProtocolRoot:    TGUID = '{79eac9e3-baf9-11ce-8c82-00aa004ba90b}';
  {$EXTERNALSYM IID_IOInetProtocol}
  IID_IOInetProtocol:        TGUID = '{79eac9e4-baf9-11ce-8c82-00aa004ba90b}';
  {$EXTERNALSYM IID_IOInetProtocolSink}
  IID_IOInetProtocolSink:    TGUID = '{79eac9e5-baf9-11ce-8c82-00aa004ba90b}';
  {$EXTERNALSYM IID_IOInetProtocolInfo}
  IID_IOInetProtocolInfo:    TGUID = '{79eac9ec-baf9-11ce-8c82-00aa004ba90b}';
  {$EXTERNALSYM IID_IOInetSession}
  IID_IOInetSession:         TGUID = '{79eac9e7-baf9-11ce-8c82-00aa004ba90b}';
  {$EXTERNALSYM IID_IOInetPriority}
  IID_IOInetPriority:        TGUID = '{79eac9eb-baf9-11ce-8c82-00aa004ba90b}';
  {$EXTERNALSYM IID_IOInetThreadSwitch}
  IID_IOInetThreadSwitch:    TGUID = '{79eac9e8-baf9-11ce-8c82-00aa004ba90b}';

  {$EXTERNALSYM IID_IInternetSecurityMgrSite}
  IID_IInternetSecurityMgrSite:     TGUID = '{79eac9ed-baf9-11ce-8c82-00aa004ba90b}';
  {$EXTERNALSYM IID_IInternetSecurityManager}
  IID_IInternetSecurityManager:     TGUID = '{79eac9ee-baf9-11ce-8c82-00aa004ba90b}';
  {$EXTERNALSYM IID_IInternetHostSecurityManager}
  IID_IInternetHostSecurityManager: TGUID = '{3af280b6-cb3f-11d0-891e-00c04fb6bfc4}';

  // This service is used for delegation support on the Security Manager interface
  {$EXTERNALSYM SID_IInternetSecurityManager}
  SID_IInternetSecurityManager:     TGUID = '{79eac9ee-baf9-11ce-8c82-00aa004ba90b}';
  {$EXTERNALSYM SID_IInternetHostSecurityManager}
  SID_IInternetHostSecurityManager: TGUID = '{3af280b6-cb3f-11d0-891e-00c04fb6bfc4}';

  {$EXTERNALSYM IID_IInternetZoneManager}
  IID_IInternetZoneManager:   TGUID = '{79eac9ef-baf9-11ce-8c82-00aa004ba90b}';

  {$EXTERNALSYM IID_ISoftDistExt}
  IID_ISoftDistExt:           TGUID = '{B15B8DC1-C7E1-11d0-8680-00AA00BDCB71}';
  {$EXTERNALSYM IID_IDataFilter}
  IID_IDataFilter:            TGUID = '{69d14c80-c18e-11d0-a9ce-006097942311}';
  {$EXTERNALSYM IID_IEncodingFilterFactory}
  IID_IEncodingFilterFactory: TGUID = '{70bdde00-c18e-11d0-a9ce-006097942311}';

// Originally (in the .h) these were enumeration types
type
  TBindVerb = ULONG;
  TBindInfoF = ULONG;
  TBindF = ULONG;
  TBSCF = ULONG;
  TBindStatus = ULONG;
  TCIPStatus = ULONG;
  TBindString = ULONG;
  TPiFlags = ULONG;
  TOIBdgFlags = ULONG;
  TParseAction = ULONG;
  TPSUAction = ULONG;
  TQueryOption = ULONG;
  TPUAF = ULONG;
  TSZMFlags = ULONG;
  TUrlZone = ULONG;
  TUrlTemplate = ULONG;
  TZAFlags = ULONG;
  TUrlZoneReg = ULONG;

const
  // URLMON-specific defines for UrlMkSetSessionOption
  {$EXTERNALSYM URLMON_OPTION_USERAGENT}
  URLMON_OPTION_USERAGENT         = $10000001;
  {$EXTERNALSYM URLMON_OPTION_USERAGENT_REFRESH}
  URLMON_OPTION_USERAGENT_REFRESH = $10000002;

  {$EXTERNALSYM CF_NULL}
  CF_NULL = 0;

  {$EXTERNALSYM CFSTR_MIME_NULL}
  CFSTR_MIME_NULL        = 0;
  {$EXTERNALSYM CFSTR_MIME_TEXT}
  CFSTR_MIME_TEXT        = 'text/plain';
  {$EXTERNALSYM CFSTR_MIME_RICHTEXT}
  CFSTR_MIME_RICHTEXT    = 'text/richtext';
  {$EXTERNALSYM CFSTR_MIME_X_BITMAP}
  CFSTR_MIME_X_BITMAP    = 'image/x-xbitmap';
  {$EXTERNALSYM CFSTR_MIME_POSTSCRIPT}
  CFSTR_MIME_POSTSCRIPT  = 'application/postscript';
  {$EXTERNALSYM CFSTR_MIME_AIFF}
  CFSTR_MIME_AIFF        = 'audio/aiff';
  {$EXTERNALSYM CFSTR_MIME_BASICAUDIO}
  CFSTR_MIME_BASICAUDIO  = 'audio/basic';
  {$EXTERNALSYM CFSTR_MIME_WAV}
  CFSTR_MIME_WAV         = 'audio/wav';
  {$EXTERNALSYM CFSTR_MIME_X_WAV}
  CFSTR_MIME_X_WAV       = 'audio/x-wav';
  {$EXTERNALSYM CFSTR_MIME_GIF}
  CFSTR_MIME_GIF         = 'image/gif';
  {$EXTERNALSYM CFSTR_MIME_PJPEG}
  CFSTR_MIME_PJPEG       = 'image/pjpeg';
  {$EXTERNALSYM CFSTR_MIME_JPEG}
  CFSTR_MIME_JPEG        = 'image/jpeg';
  {$EXTERNALSYM CFSTR_MIME_TIFF}
  CFSTR_MIME_TIFF        = 'image/tiff';
  {$EXTERNALSYM CFSTR_MIME_X_PNG}
  CFSTR_MIME_X_PNG       = 'image/x-png';
  {$EXTERNALSYM CFSTR_MIME_BMP}
  CFSTR_MIME_BMP         = 'image/bmp';
  {$EXTERNALSYM CFSTR_MIME_X_ART}
  CFSTR_MIME_X_ART       = 'image/x-jg';
  {$EXTERNALSYM CFSTR_MIME_X_EMF}
  CFSTR_MIME_X_EMF       = 'image/x-emf';
  {$EXTERNALSYM CFSTR_MIME_X_WMF}
  CFSTR_MIME_X_WMF       = 'image/x-wmf';
  {$EXTERNALSYM CFSTR_MIME_AVI}
  CFSTR_MIME_AVI         = 'video/avi';
  {$EXTERNALSYM CFSTR_MIME_MPEG}
  CFSTR_MIME_MPEG        = 'video/mpeg';
  {$EXTERNALSYM CFSTR_MIME_FRACTALS}
  CFSTR_MIME_FRACTALS    = 'application/fractals';
  {$EXTERNALSYM CFSTR_MIME_RAWDATA}
  CFSTR_MIME_RAWDATA     = 'application/octet-stream';
  {$EXTERNALSYM CFSTR_MIME_RAWDATASTRM}
  CFSTR_MIME_RAWDATASTRM = 'application/octet-stream';
  {$EXTERNALSYM CFSTR_MIME_PDF}
  CFSTR_MIME_PDF         = 'application/pdf';
  {$EXTERNALSYM CFSTR_MIME_X_AIFF}
  CFSTR_MIME_X_AIFF      = 'audio/x-aiff';
  {$EXTERNALSYM CFSTR_MIME_X_REALAUDIO}
  CFSTR_MIME_X_REALAUDIO = 'audio/x-pn-realaudio';
  {$EXTERNALSYM CFSTR_MIME_XBM}
  CFSTR_MIME_XBM         = 'image/xbm';
  {$EXTERNALSYM CFSTR_MIME_QUICKTIME}
  CFSTR_MIME_QUICKTIME   = 'video/quicktime';
  {$EXTERNALSYM CFSTR_MIME_X_MSVIDEO}
  CFSTR_MIME_X_MSVIDEO   = 'video/x-msvideo';
  {$EXTERNALSYM CFSTR_MIME_X_SGI_MOVIE}
  CFSTR_MIME_X_SGI_MOVIE = 'video/x-sgi-movie';
  {$EXTERNALSYM CFSTR_MIME_HTML}
  CFSTR_MIME_HTML        = 'text/html';

// MessageId: MK_S_ASYNCHRONOUS
// MessageText: Operation is successful, but will complete asynchronously.

  {$EXTERNALSYM MK_S_ASYNCHRONOUS}
  MK_S_ASYNCHRONOUS = $000401E8;
  {$EXTERNALSYM S_ASYNCHRONOUS}
  S_ASYNCHRONOUS    = MK_S_ASYNCHRONOUS;

  {$EXTERNALSYM E_PENDING}
  E_PENDING = $8000000A;

// WinINet and protocol specific errors are mapped to one of the following
// error which are returned in IBSC.OnStopBinding
//
// Note: FACILITY C is split into ranges of 1k
// C0000 - C03FF  INET_E_ (URLMON's original hresult)
// C0400 - C07FF  INET_E_CLIENT_xxx
// C0800 - C0BFF  INET_E_SERVER_xxx
// C0C00 - C0FFF  INET_E_????
// C1000 - C13FF  INET_E_AGENT_xxx (info delivery agents)

// $$$ Original Borland translation:
// INET_E_INVALID_URL: HResult = $800C0002;
// This is not a direct copy of the .h

const
  {$EXTERNALSYM INET_E_INVALID_URL}
  INET_E_INVALID_URL                 = HResult($800C0002);
  {$EXTERNALSYM INET_E_NO_SESSION}
  INET_E_NO_SESSION                  = HResult($800C0003);
  {$EXTERNALSYM INET_E_CANNOT_CONNECT}
  INET_E_CANNOT_CONNECT              = HResult($800C0004);
  {$EXTERNALSYM INET_E_RESOURCE_NOT_FOUND}
  INET_E_RESOURCE_NOT_FOUND          = HResult($800C0005);
  {$EXTERNALSYM INET_E_OBJECT_NOT_FOUND}
  INET_E_OBJECT_NOT_FOUND            = HResult($800C0006);
  {$EXTERNALSYM INET_E_DATA_NOT_AVAILABLE}
  INET_E_DATA_NOT_AVAILABLE          = HResult($800C0007);
  {$EXTERNALSYM INET_E_DOWNLOAD_FAILURE}
  INET_E_DOWNLOAD_FAILURE            = HResult($800C0008);
  {$EXTERNALSYM INET_E_AUTHENTICATION_REQUIRED}
  INET_E_AUTHENTICATION_REQUIRED     = HResult($800C0009);
  {$EXTERNALSYM INET_E_NO_VALID_MEDIA}
  INET_E_NO_VALID_MEDIA              = HResult($800C000A);
  {$EXTERNALSYM INET_E_CONNECTION_TIMEOUT}
  INET_E_CONNECTION_TIMEOUT          = HResult($800C000B);
  {$EXTERNALSYM INET_E_INVALID_REQUEST}
  INET_E_INVALID_REQUEST             = HResult($800C000C);
  {$EXTERNALSYM INET_E_UNKNOWN_PROTOCOL}
  INET_E_UNKNOWN_PROTOCOL            = HResult($800C000D);
  {$EXTERNALSYM INET_E_SECURITY_PROBLEM}
  INET_E_SECURITY_PROBLEM            = HResult($800C000E);
  {$EXTERNALSYM INET_E_CANNOT_LOAD_DATA}
  INET_E_CANNOT_LOAD_DATA            = HResult($800C000F);
  {$EXTERNALSYM INET_E_CANNOT_INSTANTIATE_OBJECT}
  INET_E_CANNOT_INSTANTIATE_OBJECT   = HResult($800C0010);
  {$EXTERNALSYM INET_E_REDIRECT_FAILED}
  INET_E_REDIRECT_FAILED             = HResult($800C0014);
  {$EXTERNALSYM INET_E_REDIRECT_TO_DIR}
  INET_E_REDIRECT_TO_DIR             = HResult($800C0015);
  {$EXTERNALSYM INET_E_CANNOT_LOCK_REQUEST}
  INET_E_CANNOT_LOCK_REQUEST         = HResult($800C0016);
  {$EXTERNALSYM INET_E_ERROR_FIRST}
  INET_E_ERROR_FIRST                 = HResult($800C0002);
  {$EXTERNALSYM INET_E_ERROR_LAST}
  INET_E_ERROR_LAST                  = INET_E_REDIRECT_TO_DIR;


type
  IBinding = interface; // forward

  {$EXTERNALSYM IPersistMoniker}
  IPersistMoniker = interface
    ['{79eac9c9-baf9-11ce-8c82-00aa004ba90b}']
    function GetClassID(out ClassID: TCLSID): HResult; stdcall;
    function IsDirty: HResult; stdcall;
    function Load(fFullyAvailable: BOOL; pimkName: IMoniker; pibc: IBindCtx;
      grfMode: DWORD): HResult; stdcall;
    function Save(pimkName: IMoniker; pbc: IBindCtx; fRemember: BOOL): HResult; stdcall;
    function SaveCompleted(pimkName: IMoniker; pibc: IBindCtx): HResult; stdcall;
    function GetCurMoniker(ppimkName: IMoniker): HResult; stdcall;
   end;

  {$EXTERNALSYM IBindProtocol}
  IBindProtocol = interface
    ['{79eac9cd-baf9-11ce-8c82-00aa004ba90b}']
    function CreateBinding(szUrl: LPCWSTR; pbc: IBindCtx;
      out ppb: IBinding): HResult; stdcall;
  end;

  {$EXTERNALSYM IBinding}
  IBinding = interface
    ['{79eac9c0-baf9-11ce-8c82-00aa004ba90b}']
    function Abort: HResult; stdcall;
    function Suspend: HResult; stdcall;
    function Resume: HResult; stdcall;
    function SetPriority(nPriority: Longint): HResult; stdcall;
    function GetPriority(out nPriority: Longint): HResult; stdcall;
    function GetBindResult(out clsidProtocol: TCLSID; out dwResult: DWORD;
      out szResult: POLEStr; dwReserved: DWORD): HResult; stdcall;
  end;

const
  {$EXTERNALSYM BINDVERB_GET}
  BINDVERB_GET    = $00000000;
  {$EXTERNALSYM BINDVERB_POST}
  BINDVERB_POST   = $00000001;
  {$EXTERNALSYM BINDVERB_PUT}
  BINDVERB_PUT    = $00000002;
  {$EXTERNALSYM BINDVERB_CUSTOM}
  BINDVERB_CUSTOM = $00000003;

  {$EXTERNALSYM BINDINFOF_URLENCODESTGMEDDATA}
  BINDINFOF_URLENCODESTGMEDDATA  = $00000001;
  {$EXTERNALSYM BINDINFOF_URLENCODEDEXTRAINFO}
  BINDINFOF_URLENCODEDEXTRAINFO  = $00000002;

  {$EXTERNALSYM BINDF_ASYNCHRONOUS}
  BINDF_ASYNCHRONOUS             = $00000001;
  {$EXTERNALSYM BINDF_ASYNCSTORAGE}
  BINDF_ASYNCSTORAGE             = $00000002;
  {$EXTERNALSYM BINDF_NOPROGRESSIVERENDERING}
  BINDF_NOPROGRESSIVERENDERING   = $00000004;
  {$EXTERNALSYM BINDF_OFFLINEOPERATION}
  BINDF_OFFLINEOPERATION         = $00000008;
  {$EXTERNALSYM BINDF_GETNEWESTVERSION}
  BINDF_GETNEWESTVERSION         = $00000010;
  {$EXTERNALSYM BINDF_NOWRITECACHE}
  BINDF_NOWRITECACHE             = $00000020;
  {$EXTERNALSYM BINDF_NEEDFILE}
  BINDF_NEEDFILE                 = $00000040;
  {$EXTERNALSYM BINDF_PULLDATA}
  BINDF_PULLDATA                 = $00000080;
  {$EXTERNALSYM BINDF_IGNORESECURITYPROBLEM}
  BINDF_IGNORESECURITYPROBLEM    = $00000100;
  {$EXTERNALSYM BINDF_RESYNCHRONIZE}
  BINDF_RESYNCHRONIZE            = $00000200;
  {$EXTERNALSYM BINDF_HYPERLINK}
  BINDF_HYPERLINK                = $00000400;
  {$EXTERNALSYM BINDF_NO_UI}
  BINDF_NO_UI                    = $00000800;
  {$EXTERNALSYM BINDF_SILENTOPERATION}
  BINDF_SILENTOPERATION          = $00001000;
  {$EXTERNALSYM BINDF_PRAGMA_NO_CACHE}
  BINDF_PRAGMA_NO_CACHE          = $00002000;
  {$EXTERNALSYM BINDF_FREE_THREADED}
  BINDF_FREE_THREADED            = $00010000;
  {$EXTERNALSYM BINDF_DIRECT_READ}
  BINDF_DIRECT_READ              = $00020000;
  {$EXTERNALSYM BINDF_FORMS_SUBMIT}
  BINDF_FORMS_SUBMIT             = $00040000;
  {$EXTERNALSYM BINDF_GETFROMCACHE_IF_NET_FAIL}
  BINDF_GETFROMCACHE_IF_NET_FAIL = $00080000;
  
  // These are for backwards compatibility with previous URLMON versions 
  {$EXTERNALSYM BINDF_DONTUSECACHE}
  BINDF_DONTUSECACHE             = BINDF_GETNEWESTVERSION;
  {$EXTERNALSYM BINDF_DONTPUTINCACHE}
  BINDF_DONTPUTINCACHE           = BINDF_NOWRITECACHE;
  {$EXTERNALSYM BINDF_NOCOPYDATA}
  BINDF_NOCOPYDATA               = BINDF_PULLDATA;

  {$EXTERNALSYM BSCF_FIRSTDATANOTIFICATION}
  BSCF_FIRSTDATANOTIFICATION        = $00000001;
  {$EXTERNALSYM BSCF_INTERMEDIATEDATANOTIFICATION}
  BSCF_INTERMEDIATEDATANOTIFICATION = $00000002;
  {$EXTERNALSYM BSCF_LASTDATANOTIFICATION}
  BSCF_LASTDATANOTIFICATION         = $00000004;
  {$EXTERNALSYM BSCF_DATAFULLYAVAILABLE}
  BSCF_DATAFULLYAVAILABLE           = $00000008;
  {$EXTERNALSYM BSCF_AVAILABLEDATASIZEUNKNOWN}
  BSCF_AVAILABLEDATASIZEUNKNOWN     = $00000010;

  {$EXTERNALSYM BINDSTATUS_FINDINGRESOURCE}
  BINDSTATUS_FINDINGRESOURCE           = 1;
  {$EXTERNALSYM BINDSTATUS_CONNECTING}
  BINDSTATUS_CONNECTING                = BINDSTATUS_FINDINGRESOURCE + 1;
  {$EXTERNALSYM BINDSTATUS_REDIRECTING}
  BINDSTATUS_REDIRECTING               = BINDSTATUS_CONNECTING + 1;
  {$EXTERNALSYM BINDSTATUS_BEGINDOWNLOADDATA}
  BINDSTATUS_BEGINDOWNLOADDATA         = BINDSTATUS_REDIRECTING + 1;
  {$EXTERNALSYM BINDSTATUS_DOWNLOADINGDATA}
  BINDSTATUS_DOWNLOADINGDATA           = BINDSTATUS_BEGINDOWNLOADDATA + 1;
  {$EXTERNALSYM BINDSTATUS_ENDDOWNLOADDATA}
  BINDSTATUS_ENDDOWNLOADDATA           = BINDSTATUS_DOWNLOADINGDATA + 1;
  {$EXTERNALSYM BINDSTATUS_BEGINDOWNLOADCOMPONENTS}
  BINDSTATUS_BEGINDOWNLOADCOMPONENTS   = BINDSTATUS_ENDDOWNLOADDATA + 1;
  {$EXTERNALSYM BINDSTATUS_INSTALLINGCOMPONENTS}
  BINDSTATUS_INSTALLINGCOMPONENTS      = BINDSTATUS_BEGINDOWNLOADCOMPONENTS + 1;
  {$EXTERNALSYM BINDSTATUS_ENDDOWNLOADCOMPONENTS}
  BINDSTATUS_ENDDOWNLOADCOMPONENTS     = BINDSTATUS_INSTALLINGCOMPONENTS + 1;
  {$EXTERNALSYM BINDSTATUS_USINGCACHEDCOPY}
  BINDSTATUS_USINGCACHEDCOPY           = BINDSTATUS_ENDDOWNLOADCOMPONENTS + 1;
  {$EXTERNALSYM BINDSTATUS_SENDINGREQUEST}
  BINDSTATUS_SENDINGREQUEST            = BINDSTATUS_USINGCACHEDCOPY + 1;
  {$EXTERNALSYM BINDSTATUS_CLASSIDAVAILABLE}
  BINDSTATUS_CLASSIDAVAILABLE          = BINDSTATUS_SENDINGREQUEST + 1;
  {$EXTERNALSYM BINDSTATUS_MIMETYPEAVAILABLE}
  BINDSTATUS_MIMETYPEAVAILABLE         = BINDSTATUS_CLASSIDAVAILABLE + 1;
  {$EXTERNALSYM BINDSTATUS_CACHEFILENAMEAVAILABLE}
  BINDSTATUS_CACHEFILENAMEAVAILABLE    = BINDSTATUS_MIMETYPEAVAILABLE + 1;
  {$EXTERNALSYM BINDSTATUS_BEGINSYNCOPERATION}
  BINDSTATUS_BEGINSYNCOPERATION        = BINDSTATUS_CACHEFILENAMEAVAILABLE + 1;
  {$EXTERNALSYM BINDSTATUS_ENDSYNCOPERATION}
  BINDSTATUS_ENDSYNCOPERATION          = BINDSTATUS_BEGINSYNCOPERATION + 1;
  {$EXTERNALSYM BINDSTATUS_BEGINUPLOADDATA}
  BINDSTATUS_BEGINUPLOADDATA           = BINDSTATUS_ENDSYNCOPERATION + 1;
  {$EXTERNALSYM BINDSTATUS_UPLOADINGDATA}
  BINDSTATUS_UPLOADINGDATA             = BINDSTATUS_BEGINUPLOADDATA + 1;
  {$EXTERNALSYM BINDSTATUS_ENDUPLOADDATA}
  BINDSTATUS_ENDUPLOADDATA             = BINDSTATUS_UPLOADINGDATA + 1;
  {$EXTERNALSYM BINDSTATUS_PROTOCOLCLASSID}
  BINDSTATUS_PROTOCOLCLASSID           = BINDSTATUS_ENDUPLOADDATA + 1;
  {$EXTERNALSYM BINDSTATUS_ENCODING}
  BINDSTATUS_ENCODING                  = BINDSTATUS_PROTOCOLCLASSID + 1;
  {$EXTERNALSYM BINDSTATUS_VERIFIEDMIMETYPEAVAILABLE}
  BINDSTATUS_VERIFIEDMIMETYPEAVAILABLE = BINDSTATUS_ENCODING + 1;
  {$EXTERNALSYM BINDSTATUS_CLASSINSTALLLOCATION}
  BINDSTATUS_CLASSINSTALLLOCATION      = BINDSTATUS_VERIFIEDMIMETYPEAVAILABLE + 1;
  {$EXTERNALSYM BINDSTATUS_DECODING}
  BINDSTATUS_DECODING                  = BINDSTATUS_CLASSINSTALLLOCATION + 1;
  {$EXTERNALSYM BINDSTATUS_LOADINGMIMEHANDLER}
  BINDSTATUS_LOADINGMIMEHANDLER        = BINDSTATUS_DECODING + 1;

type
  PBindInfo = ^TBindInfo;
  {$EXTERNALSYM _tagBINDINFO}
  _tagBINDINFO = packed record
    cbSize: ULONG;
    szExtraInfo: LPWSTR;
    stgmedData: TStgMedium;
    grfBindInfoF: DWORD;
    dwBindVerb: DWORD;
    szCustomVerb: LPWSTR;
    cbstgmedData: DWORD;
    dwOptions: DWORD;
    dwOptionsFlags: DWORD;
    dwCodePage: DWORD;
    securityAttributes: TSecurityAttributes;
    iid: TGUID;
    pUnk: IUnknown;
    dwReserved: DWORD;
  end;
  TBindInfo = _tagBINDINFO;
  {$EXTERNALSYM BINDINFO}
  BINDINFO = _tagBINDINFO;

  PRemSecurityAttributes = ^TRemSecurityAttributes;
  {$EXTERNALSYM _REMSECURITY_ATTRIBUTES}
  _REMSECURITY_ATTRIBUTES = packed record
    nLength: DWORD;
    lpSecurityDescriptor: DWORD;
    bInheritHandle: BOOL;
  end;
  TRemSecurityAttributes = _REMSECURITY_ATTRIBUTES;
  {$EXTERNALSYM REMSECURITY_ATTRIBUTES}
  REMSECURITY_ATTRIBUTES = _REMSECURITY_ATTRIBUTES;

  PRemBindInfo = ^TRemBindInfo;
  {$EXTERNALSYM _tagRemBINDINFO}
  _tagRemBINDINFO = packed record
    cbSize: ULONG;
    szExtraInfo: LPWSTR;
    grfBindInfoF: DWORD;
    dwBindVerb: DWORD;
    szCustomVerb: LPWSTR;
    cbstgmedData: DWORD;
    dwOptions: DWORD;
    dwOptionsFlags: DWORD;
    dwCodePage: DWORD;
    securityAttributes: TRemSecurityAttributes;
    iid: TGUID;
    pUnk: IUnknown;
    dwReserved: DWORD;
  end;
  TRemBindInfo = _tagRemBINDINFO; 
  {$EXTERNALSYM RemBINDINFO}
  RemBINDINFO = _tagRemBINDINFO;
  
  PRemFormatEtc = ^TRemFormatEtc;
  {$EXTERNALSYM tagRemFORMATETC}
  tagRemFORMATETC = packed record
    cfFormat: DWORD;
    ptd: DWORD;
    dwAspect: DWORD;
    lindex: Longint;
    tymed: DWORD;
  end;
  TRemFormatEtc = tagRemFORMATETC;
  {$EXTERNALSYM RemFORMATETC}
  RemFORMATETC = tagRemFORMATETC;

  {$EXTERNALSYM IBindStatusCallback}
  IBindStatusCallback = interface
    ['{79eac9c1-baf9-11ce-8c82-00aa004ba90b}']
    function OnStartBinding(dwReserved: DWORD; pib: IBinding): HResult; stdcall;
    function GetPriority(out nPriority): HResult; stdcall;
    function OnLowResource(reserved: DWORD): HResult; stdcall;
    function OnProgress(ulProgress, ulProgressMax, ulStatusCode: ULONG;
      szStatusText: LPCWSTR): HResult; stdcall;
    function OnStopBinding(hresult: HResult; szError: LPCWSTR): HResult; stdcall;
    function GetBindInfo(out grfBINDF: DWORD; var bindinfo: TBindInfo): HResult; stdcall;
    function OnDataAvailable(grfBSCF: DWORD; dwSize: DWORD; formatetc: PFormatEtc;
      stgmed: PStgMedium): HResult; stdcall;
    function OnObjectAvailable(const iid: TGUID; punk: IUnknown): HResult; stdcall;
  end;

  {$EXTERNALSYM IAuthenticate}
  IAuthenticate = interface
    ['{79eac9d0-baf9-11ce-8c82-00aa004ba90b}']
    function Authenticate(var hwnd: HWnd; var szUserName, szPassWord: LPWSTR): HResult; stdcall;
  end;

  {$EXTERNALSYM IHttpNegotiate}
  IHttpNegotiate = interface
    ['{79eac9d2-baf9-11ce-8c82-00aa004ba90b}']
    function BeginningTransaction(szURL, szHeaders: LPCWSTR; dwReserved: DWORD;
      out szAdditionalHeaders: LPWSTR): HResult; stdcall;
    function OnResponse(dwResponseCode: DWORD; szResponseHeaders, szRequestHeaders: LPCWSTR;
      out szAdditionalRequestHeaders: LPWSTR): HResult; stdcall;
  end;

  {$EXTERNALSYM IWindowForBindingUI}
  IWindowForBindingUI = interface
    ['{79eac9d5-bafa-11ce-8c82-00aa004ba90b}']
    function GetWindow(const guidReason: TGUID; out hwnd): HResult; stdcall;
  end;

const
  {$EXTERNALSYM CIP_DISK_FULL}
  CIP_DISK_FULL                            = 0;
  {$EXTERNALSYM CIP_ACCESS_DENIED}
  CIP_ACCESS_DENIED                        = CIP_DISK_FULL + 1;
  {$EXTERNALSYM CIP_NEWER_VERSION_EXISTS}
  CIP_NEWER_VERSION_EXISTS                 = CIP_ACCESS_DENIED + 1;
  {$EXTERNALSYM CIP_OLDER_VERSION_EXISTS}
  CIP_OLDER_VERSION_EXISTS                 = CIP_NEWER_VERSION_EXISTS + 1;
  {$EXTERNALSYM CIP_NAME_CONFLICT}
  CIP_NAME_CONFLICT                        = CIP_OLDER_VERSION_EXISTS + 1;
  {$EXTERNALSYM CIP_TRUST_VERIFICATION_COMPONENT_MISSING}
  CIP_TRUST_VERIFICATION_COMPONENT_MISSING = CIP_NAME_CONFLICT + 1;
  {$EXTERNALSYM CIP_EXE_SELF_REGISTERATION_TIMEOUT}
  CIP_EXE_SELF_REGISTERATION_TIMEOUT       = CIP_TRUST_VERIFICATION_COMPONENT_MISSING + 1;
  {$EXTERNALSYM CIP_UNSAFE_TO_ABORT}
  CIP_UNSAFE_TO_ABORT                      = CIP_EXE_SELF_REGISTERATION_TIMEOUT + 1;
  {$EXTERNALSYM CIP_NEED_REBOOT}
  CIP_NEED_REBOOT                          = CIP_UNSAFE_TO_ABORT + 1;

type
  {$EXTERNALSYM ICodeInstall}
  ICodeInstall = interface(IWindowForBindingUI)
    ['{79eac9d1-baf9-11ce-8c82-00aa004ba90b}']
    function OnCodeInstallProblem(ulStatusCode: ULONG; szDestination, szSource: LPCWSTR;
      dwReserved: DWORD): HResult; stdcall;
  end;

  {$EXTERNALSYM IWinInetInfo}
  IWinInetInfo = interface
    ['{79eac9d6-bafa-11ce-8c82-00aa004ba90b}']
    function QueryOption(dwOption: DWORD; Buffer: Pointer; var cbBuf: DWORD): HResult; stdcall;
  end;

const
  {$EXTERNALSYM WININETINFO_OPTION_LOCK_HANDLE}
  WININETINFO_OPTION_LOCK_HANDLE   = 65534;

type
  {$EXTERNALSYM IHttpSecurity}
  IHttpSecurity = interface(IWindowForBindingUI)
    ['{79eac9d7-bafa-11ce-8c82-00aa004ba90b}']
    function OnSecurityProblem(dwProblem: DWORD): HResult; stdcall;
  end;

  {$EXTERNALSYM IWinInetHttpInfo}
  IWinInetHttpInfo = interface(IWinInetInfo)
    ['{79eac9d8-bafa-11ce-8c82-00aa004ba90b}']
    function QueryInfo(dwOption: DWORD; Buffer: Pointer;
      var cbBuf, dwFlags, dwReserved: DWORD): HResult; stdcall;
  end;

  {$EXTERNALSYM IBindHost}
  IBindHost = interface
    ['{fc4801a1-2ba9-11cf-a229-00aa003d7352}']
    function CreateMoniker(szName: POLEStr; BC: IBindCtx; out mk: IMoniker; dwReserved: DWORD): HResult; stdcall;
    function MonikerBindToStorage(Mk: IMoniker; BC: IBindCtx; BSC: IBindStatusCallback;
      const iid: TGUID; out pvObj: Pointer): HResult; stdcall;
    function MonikerBindToObject(Mk: IMoniker; BC: IBindCtx; BSC: IBindStatusCallback;
      const iid: TGUID; out pvObj: Pointer): HResult; stdcall;
  end;

const
  {$EXTERNALSYM URLOSTRM_USECACHEDCOPY_ONLY}
  URLOSTRM_USECACHEDCOPY_ONLY = $00000001;      // Only get from cache
  {$EXTERNALSYM URLOSTRM_USECACHEDCOPY}
  URLOSTRM_USECACHEDCOPY      = $00000002;      // Get from cache if available else download
  {$EXTERNALSYM URLOSTRM_GETNEWESTVERSION}
  URLOSTRM_GETNEWESTVERSION   = $00000003;      // Get new version only. But put it in cache too


{$EXTERNALSYM HlinkSimpleNavigateToString}
function HlinkSimpleNavigateToString(
  szTarget,                           // required - target document - null if local jump w/in doc
  szLocation,                         // optional, for navigation into middle of a doc
  szTargetFrameName: LPCWSTR;         // optional, for targeting frame-sets
  Unk: IUnknown;                      // required - we'll search this for other necessary interfaces
  pbc: IBindCtx;                      // optional. caller may register an IBSC in this
  BSC: IBindStatusCallback;
  grfHLNF,                            // flags
  dwReserved: DWORD): HResult; stdcall;

{$EXTERNALSYM HlinkSimpleNavigateToMoniker}
function HlinkSimpleNavigateToMoniker(
  mkTarget: Imoniker;                 // required - target document - (may be null
  szLocation,                         // optional, for navigation into middle of a doc
  szTargetFrameName: LPCWSTR;         // optional, for targeting frame-sets
  Unk: IUnknown;                      // required - we'll search this for other necessary interfaces
  bc: IBindCtx;                       // optional. caller may register an IBSC in this
  BSC: IBindStatusCallback;
  grfHLNF,                            // flags
  dwReserved: DWORD): HResult; stdcall;

{$EXTERNALSYM CreateURLMoniker}
function CreateURLMoniker(MkCtx: IMoniker; szURL: LPCWSTR; out mk: IMoniker): HResult; stdcall;
{$EXTERNALSYM GetClassURL}
function GetClassURL(szURL: LPCWSTR; const ClsID: TCLSID): HResult; stdcall;
{$EXTERNALSYM CreateAsyncBindCtx}
function CreateAsyncBindCtx(reserved: DWORD; pBSCb: IBindStatusCallback; pEFetc: IEnumFORMATETC;
  out ppBC: IBindCtx): HResult; stdcall;
{$EXTERNALSYM CreateAsyncBindCtxEx}
function CreateAsyncBindCtxEx(pbc: IBindCtx; dwOptions: DWORD; BSCb: IBindStatusCallback; Enum: IEnumFORMATETC;
  out ppBC: IBindCtx; reserved: DWORD): HResult; stdcall;
{$EXTERNALSYM MkParseDisplayNameEx}
function MkParseDisplayNameEx(pbc: IBindCtx; szDisplayName: LPCWSTR; out pchEaten: ULONG;
  out ppmk: IMoniker): HResult; stdcall;
{$EXTERNALSYM RegisterBindStatusCallback}
function RegisterBindStatusCallback(pBC: IBindCtx; pBSCb: IBindStatusCallback;
  out ppBSCBPrev: IBindStatusCallback; dwReserved: DWORD): HResult; stdcall;
{$EXTERNALSYM RevokeBindStatusCallback}
function RevokeBindStatusCallback(pBC: IBindCtx; pBSCb: IBindStatusCallback): HResult; stdcall;
{$EXTERNALSYM GetClassFileOrMime}
function GetClassFileOrMime(pBC: IBindCtx; szFilename: LPCWSTR; pBuffer: Pointer; cbSize: DWORD;
  szMime: LPCWSTR; dwReserved: DWORD; out pclsid: TCLSID): HResult; stdcall;
{$EXTERNALSYM IsValidURL}
function IsValidURL(pBC: IBindCtx; szURL: LPCWSTR; dwReserved: DWORD): HResult; stdcall;
{$EXTERNALSYM CoGetClassObjectFromURL}
function CoGetClassObjectFromURL(const rCLASSID: TCLSID; szCODE: LPCWSTR;
  dwFileVersionMS, dwFileVersionLS: DWORD; szTYPE: LPCWSTR; pBindCtx: IBindCtx; dwClsContext: DWORD;
  pvReserved: Pointer; const riid: TGUID; out ppv): HResult; stdcall;

//helper apis
{$EXTERNALSYM IsAsyncMoniker}
function IsAsyncMoniker(pmk: IMoniker): HResult; stdcall;
{$EXTERNALSYM CreateURLBinding}
function CreateURLBinding(lpszUrl: LPCWSTR; pbc: IBindCtx; out ppBdg: IBinding): HResult; stdcall;

{$EXTERNALSYM RegisterMediaTypes}
function RegisterMediaTypes(ctypes: UINT; const rgszTypes: LPCSTR; const rgcfTypes: TClipFormat): HResult; stdcall;
{$EXTERNALSYM FindMediaType}
function FindMediaType(rgszTypes: LPCSTR; rgcfTypes: PClipFormat): HResult; stdcall;
{$EXTERNALSYM CreateFormatEnumerator}
function CreateFormatEnumerator(cfmtetc: UINT; const rgfmtetc: TFormatEtc; out ppenumfmtetc: IEnumFormatEtc): HResult; stdcall;
{$EXTERNALSYM RegisterFormatEnumerator}
function RegisterFormatEnumerator(pBC: IBindCtx; pEFetc: IEnumFormatEtc; reserved: DWORD): HResult; stdcall;
{$EXTERNALSYM RevokeFormatEnumerator}
function RevokeFormatEnumerator(pBC: IBindCtx; pEFetc: IEnumFormatEtc): HResult; stdcall;
{$EXTERNALSYM RegisterMediaTypeClass}
function RegisterMediaTypeClass(pBC: IBindCtx; ctypes: UINT; const rgszTypes: LPCSTR; rgclsID: PCLSID; reserved: DWORD): HResult; stdcall;
{$EXTERNALSYM FindMediaTypeClass}
function FindMediaTypeClass(pBC: IBindCtx; szType: LPCSTR; const pclsID: TCLSID; reserved: DWORD): HResult; stdcall;
{$EXTERNALSYM UrlMkSetSessionOption}
function UrlMkSetSessionOption(dwOption: DWORD; pBuffer: Pointer; dwBufferLength, dwReserved: DWORD): HResult; stdcall;
{$EXTERNALSYM UrlMkGetSessionOption}
function UrlMkGetSessionOption(dwOption: DWORD; pBuffer: Pointer; dwBufferLength: DWORD; out pdwBufferLength: DWORD; dwReserved: DWORD): HResult; stdcall;
{$EXTERNALSYM FindMimeFromData}
function FindMimeFromData(
    pBC: IBindCtx;                      // bind context - can be nil
    pwzUrl: LPCWSTR;                    // url - can be nil
    pBuffer: Pointer;                   // buffer with data to sniff - can be nil (pwzUrl must be valid)
    cbSize: DWORD;                      // size of buffer
    pwzMimeProposed: LPCWSTR;           // proposed mime if - can be nil
    dwMimeFlags: DWORD;                 // will be defined
    out ppwzMimeOut: LPWSTR;            // the suggested mime
    dwReserved: DWORD                   // must be 0
  ): HResult; stdcall;
{$EXTERNALSYM ObtainUserAgentString}
function ObtainUserAgentString(dwOption: DWORD; pszUAOut: LPSTR; var cbSize: DWORD): HResult; stdcall;

{$EXTERNALSYM URLOpenStreamA}
function URLOpenStreamA(p1: IUnknown; p2: PAnsiChar; p3: DWORD; p4: IBindStatusCallback): HResult; stdcall;
{$EXTERNALSYM URLOpenStreamW}
function URLOpenStreamW(p1: IUnknown; p2: PWideChar; p3: DWORD; p4: IBindStatusCallback): HResult; stdcall;
{$EXTERNALSYM URLOpenStream}
function URLOpenStream(p1: IUnknown; p2: PChar; p3: DWORD; p4: IBindStatusCallback): HResult; stdcall;
{$EXTERNALSYM URLOpenPullStreamA}
function URLOpenPullStreamA(p1: IUnknown; p2: PAnsiChar; p3: DWORD; BSC: IBindStatusCallback): HResult; stdcall;
{$EXTERNALSYM URLOpenPullStreamW}
function URLOpenPullStreamW(p1: IUnknown; p2: PWideChar; p3: DWORD; BSC: IBindStatusCallback): HResult; stdcall;
{$EXTERNALSYM URLOpenPullStream}
function URLOpenPullStream(p1: IUnknown; p2: PChar; p3: DWORD; BSC: IBindStatusCallback): HResult; stdcall;
{$EXTERNALSYM URLDownloadToFileA}
function URLDownloadToFileA(p1: IUnknown; p2: PAnsiChar; p3: PAnsiChar; p4: DWORD; p5: IBindStatusCallback): HResult; stdcall;
{$EXTERNALSYM URLDownloadToFileW}
function URLDownloadToFileW(p1: IUnknown; p2: PWideChar; p3: PWideChar; p4: DWORD; p5: IBindStatusCallback): HResult; stdcall;
{$EXTERNALSYM URLDownloadToFile}
function URLDownloadToFile(p1: IUnknown; p2: PChar; p3: PChar; p4: DWORD; p5: IBindStatusCallback): HResult; stdcall;
{$EXTERNALSYM URLDownloadToCacheFileA}
function URLDownloadToCacheFileA(p1: IUnknown; p2: PAnsiChar; p3: PAnsiChar; p4: DWORD; p5: DWORD; p6: IBindStatusCallback): HResult; stdcall;
{$EXTERNALSYM URLDownloadToCacheFileW}
function URLDownloadToCacheFileW(p1: IUnknown; p2: PWideChar; p3: PWideChar; p4: DWORD; p5: DWORD; p6: IBindStatusCallback): HResult; stdcall;
{$EXTERNALSYM URLDownloadToCacheFile}
function URLDownloadToCacheFile(p1: IUnknown; p2: PChar; p3: PChar; p4: DWORD; p5: DWORD; p6: IBindStatusCallback): HResult; stdcall;
{$EXTERNALSYM URLOpenBlockingStreamA}
function URLOpenBlockingStreamA(p1: IUnknown; p2: PAnsiChar; out p3: IStream; p4: DWORD; p5: IBindStatusCallback): HResult; stdcall;
{$EXTERNALSYM URLOpenBlockingStreamW}
function URLOpenBlockingStreamW(p1: IUnknown; p2: PWideChar; out p3: IStream; p4: DWORD; p5: IBindStatusCallback): HResult; stdcall;
{$EXTERNALSYM URLOpenBlockingStream}
function URLOpenBlockingStream(p1: IUnknown; p2: PChar; out p3: IStream; p4: DWORD; p5: IBindStatusCallback): HResult; stdcall;

{$EXTERNALSYM HlinkGoBack}
function HlinkGoBack(unk: IUnknown): HResult; stdcall;
{$EXTERNALSYM HlinkGoForward}
function HlinkGoForward(unk: IUnknown): HResult; stdcall;
{$EXTERNALSYM HlinkNavigateString}
function HlinkNavigateString(unk: IUnknown; szTarget: LPCWSTR): HResult; stdcall;
{$EXTERNALSYM HlinkNavigateMoniker}
function HlinkNavigateMoniker(Unk: IUnknown; mkTarget: IMoniker): HResult; stdcall;

type
  {$EXTERNALSYM IInternet}
  IInternet = interface
    ['{79eac9e0-baf9-11ce-8c82-00aa004ba90b}']
  end;

const
  {$EXTERNALSYM BINDSTRING_HEADERS}
  BINDSTRING_HEADERS          = 1;
  {$EXTERNALSYM BINDSTRING_ACCEPT_MIMES}
  BINDSTRING_ACCEPT_MIMES     = BINDSTRING_HEADERS + 1;
  {$EXTERNALSYM BINDSTRING_EXTRA_URL}
  BINDSTRING_EXTRA_URL        = BINDSTRING_ACCEPT_MIMES + 1;
  {$EXTERNALSYM BINDSTRING_LANGUAGE}
  BINDSTRING_LANGUAGE         = BINDSTRING_EXTRA_URL + 1;
  {$EXTERNALSYM BINDSTRING_USERNAME}
  BINDSTRING_USERNAME         = BINDSTRING_LANGUAGE + 1;
  {$EXTERNALSYM BINDSTRING_PASSWORD}
  BINDSTRING_PASSWORD         = BINDSTRING_USERNAME + 1;
  {$EXTERNALSYM BINDSTRING_UA_PIXELS}
  BINDSTRING_UA_PIXELS        = BINDSTRING_PASSWORD + 1;
  {$EXTERNALSYM BINDSTRING_UA_COLOR}
  BINDSTRING_UA_COLOR         = BINDSTRING_UA_PIXELS + 1;
  {$EXTERNALSYM BINDSTRING_OS}
  BINDSTRING_OS               = BINDSTRING_UA_COLOR + 1;
  {$EXTERNALSYM BINDSTRING_USER_AGENT}
  BINDSTRING_USER_AGENT       = BINDSTRING_OS + 1;
  {$EXTERNALSYM BINDSTRING_ACCEPT_ENCODINGS}
  BINDSTRING_ACCEPT_ENCODINGS = BINDSTRING_USER_AGENT + 1;
  {$EXTERNALSYM BINDSTRING_POST_COOKIE}
  BINDSTRING_POST_COOKIE      = BINDSTRING_ACCEPT_ENCODINGS + 1;
  {$EXTERNALSYM BINDSTRING_POST_DATA_MIME}
  BINDSTRING_POST_DATA_MIME   = BINDSTRING_POST_COOKIE + 1;
  {$EXTERNALSYM BINDSTRING_URL}
  BINDSTRING_URL              = BINDSTRING_POST_DATA_MIME + 1;

type
  {$NODEFINE POLEStrArray}
  POLEStrArray = ^TOLESTRArray;
  {$NODEFINE TOLEStrArray}
  TOLEStrArray = array[0..MaxLongint div SizeOf(POLEStr) - 1] of POLEStr;

  {$EXTERNALSYM IInternetBindInfo}
  IInternetBindInfo = interface
    ['{79eac9e1-baf9-11ce-8c82-00aa004ba90b}']
    function GetBindInfo(out grfBINDF: DWORD; var bindinfo: TBindInfo): HResult; stdcall;
    function GetBindString(ulStringType: ULONG; wzStr: POLEStrArray; cEl: ULONG;
      var cElFetched: ULONG): HResult; stdcall;
  end;

const
  {$EXTERNALSYM PI_PARSE_URL}
  PI_PARSE_URL                = $00000001;
  {$EXTERNALSYM PI_FILTER_MODE}
  PI_FILTER_MODE              = $00000002;
  {$EXTERNALSYM PI_FORCE_ASYNC}
  PI_FORCE_ASYNC              = $00000004;
  {$EXTERNALSYM PI_USE_WORKERTHREAD}
  PI_USE_WORKERTHREAD         = $00000008;
  {$EXTERNALSYM PI_MIMEVERIFICATION}
  PI_MIMEVERIFICATION         = $00000010;
  {$EXTERNALSYM PI_CLSIDLOOKUP}
  PI_CLSIDLOOKUP              = $00000020;
  {$EXTERNALSYM PI_DATAPROGRESS}
  PI_DATAPROGRESS             = $00000040;
  {$EXTERNALSYM PI_SYNCHRONOUS}
  PI_SYNCHRONOUS              = $00000080;
  {$EXTERNALSYM PI_APARTMENTTHREADED}
  PI_APARTMENTTHREADED        = $00000100;
  {$EXTERNALSYM PI_CLASSINSTALL}
  PI_CLASSINSTALL             = $00000200;
  {$EXTERNALSYM PD_FORCE_SWITCH}
  PD_FORCE_SWITCH             = $00010000;

  {$EXTERNALSYM PI_DOCFILECLSIDLOOKUP}
  PI_DOCFILECLSIDLOOKUP       = PI_CLSIDLOOKUP;

type
  PProtocolData = ^TProtocolData;
  {$EXTERNALSYM _tagPROTOCOLDATA}
  _tagPROTOCOLDATA = packed record
    grfFlags: DWORD;
    dwState: DWORD;
    pData: Pointer;
    cbData: ULONG;
  end;
  TProtocolData = _tagPROTOCOLDATA;
  {$EXTERNALSYM _tagPROTOCOLDATA}
  PROTOCOLDATA = _tagPROTOCOLDATA;
  {$EXTERNALSYM PROTOCOLDATA}

  {$EXTERNALSYM IInternetProtocolSink}
  IInternetProtocolSink = interface; // forward

  {$EXTERNALSYM IInternetProtocolRoot}
  IInternetProtocolRoot = interface
    ['{79eac9e3-baf9-11ce-8c82-00aa004ba90b}']
    function Start(szUrl: LPCWSTR; OIProtSink: IInternetProtocolSink;
      OIBindInfo: IInternetBindInfo; grfPI, dwReserved: DWORD): HResult; stdcall;
    function Continue(const ProtocolData: TProtocolData): HResult; stdcall;
    function Abort(hrReason: HResult; dwOptions: DWORD): HResult; stdcall;
    function Terminate(dwOptions: DWORD): HResult; stdcall;
    function Suspend: HResult; stdcall;
    function Resume: HResult; stdcall;
  end;

  {$EXTERNALSYM IInternetProtocol}
  IInternetProtocol = interface(IInternetProtocolRoot)
    ['{79eac9e4-baf9-11ce-8c82-00aa004ba90b}']
    function Read(pv: Pointer; cb: ULONG; out cbRead: ULONG): HResult; stdcall;
    function Seek(dlibMove: LARGE_INTEGER; dwOrigin: DWORD; out libNewPosition: ULARGE_INTEGER): HResult; stdcall;
    function LockRequest(dwOptions: DWORD): HResult; stdcall;
    function UnlockRequest: HResult; stdcall;
  end;

  {$EXTERNALSYM IInternetProtocolSink}
  IInternetProtocolSink = interface
    ['{79eac9e5-baf9-11ce-8c82-00aa004ba90b}']
    function Switch(const ProtocolData: TProtocolData): HResult; stdcall;
    function ReportProgress(ulStatusCode: ULONG; szStatusText: LPCWSTR): HResult; stdcall;
    function ReportData(grfBSCF: DWORD; ulProgress, ulProgressMax: ULONG): HResult; stdcall;
    function ReportResult(hrResult: HResult; dwError: DWORD; szResult: LPCWSTR): HResult; stdcall;
  end;

const
  {$EXTERNALSYM OIBDG_APARTMENTTHREADED}
  OIBDG_APARTMENTTHREADED     = $00000100;

type
  {$NODEFINE TLPCWSTRArray}
  TLPCWSTRArray = array[0..MaxLongInt div SizeOf(LPCWSTR) - 1] of LPCWSTR;
  {$NODEFINE PLPCWSTRArray}
  PLPCWSTRArray = ^TLPCWSTRArray;

  {$EXTERNALSYM IInternetSession}
  IInternetSession = interface
    ['{79eac9e7-baf9-11ce-8c82-00aa004ba90b}']
    function RegisterNameSpace(CF: IClassFactory; const clsid: TCLSID; pwzProtocol: LPCWSTR;
      cPatterns: ULONG; const pwzPatterns: PLPCWSTRArray; dwReserved: DWORD): HResult; stdcall;
    function UnregisterNameSpace(CF: IClassFactory; pszProtocol: LPCWSTR): HResult; stdcall;
    function RegisterMimeFilter(CF: IClassFactory; const rclsid: TCLSID;
      pwzType: LPCWSTR): HResult; stdcall;
    function UnregisterMimeFilter(CF: IClassFactory; pwzType: LPCWSTR): HResult; stdcall;
    function CreateBinding(BC: IBindCtx; szUrl: LPCWSTR; UnkOuter: IUnknown; out Unk: IUnknown;
      out OINetProt: IInternetProtocol; dwOption: DWORD): HResult; stdcall;
    function SetSessionOption(dwOption: DWORD; pBuffer: Pointer; dwBufferLength: DWORD;
      dwReserved: DWORD): HResult; stdcall;
    function GetSessionOption(dwOption: DWORD; pBuffer: Pointer; var dwBufferLength: DWORD;
      dwReserved: DWORD): HResult; stdcall;
  end;

  {$EXTERNALSYM IInternetThreadSwitch}
  IInternetThreadSwitch = interface
    ['{79eac9e8-baf9-11ce-8c82-00aa004ba90b}']
    function Prepare: HResult; stdcall;
    function Continue: HResult; stdcall;
  end;

  {$EXTERNALSYM IInternetPriority}
  IInternetPriority = interface
    ['{79eac9eb-baf9-11ce-8c82-00aa004ba90b}']
    function SetPriority(nPriority: Longint): HResult; stdcall;
    function GetPriority(out nPriority: Longint): HResult; stdcall;
  end;

const
  {$EXTERNALSYM PARSE_CANONICALIZE}
  PARSE_CANONICALIZE    = 1;
  {$EXTERNALSYM PARSE_FRIENDLY}
  PARSE_FRIENDLY        = PARSE_CANONICALIZE + 1;
  {$EXTERNALSYM PARSE_SECURITY_URL}
  PARSE_SECURITY_URL    = PARSE_FRIENDLY + 1;
  {$EXTERNALSYM PARSE_ROOTDOCUMENT}
  PARSE_ROOTDOCUMENT    = PARSE_SECURITY_URL + 1;
  {$EXTERNALSYM PARSE_DOCUMENT}
  PARSE_DOCUMENT        = PARSE_ROOTDOCUMENT + 1;
  {$EXTERNALSYM PARSE_ANCHOR}
  PARSE_ANCHOR          = PARSE_DOCUMENT + 1;
  {$EXTERNALSYM PARSE_ENCODE}
  PARSE_ENCODE          = PARSE_ANCHOR + 1;
  {$EXTERNALSYM PARSE_DECODE}
  PARSE_DECODE          = PARSE_ENCODE + 1;
  {$EXTERNALSYM PARSE_PATH_FROM_URL}
  PARSE_PATH_FROM_URL   = PARSE_DECODE + 1;
  {$EXTERNALSYM PARSE_URL_FROM_PATH}
  PARSE_URL_FROM_PATH   = PARSE_PATH_FROM_URL + 1;
  {$EXTERNALSYM PARSE_MIME}
  PARSE_MIME            = PARSE_URL_FROM_PATH + 1;
  {$EXTERNALSYM PARSE_SERVER}
  PARSE_SERVER          = PARSE_MIME + 1;
  {$EXTERNALSYM PARSE_SCHEMA}
  PARSE_SCHEMA          = PARSE_SERVER + 1;
  {$EXTERNALSYM PARSE_SITE}
  PARSE_SITE            = PARSE_SCHEMA + 1;
  {$EXTERNALSYM PARSE_DOMAIN}
  PARSE_DOMAIN          = PARSE_SITE + 1;
  {$EXTERNALSYM PARSE_LOCATION}
  PARSE_LOCATION        = PARSE_DOMAIN + 1;
  {$EXTERNALSYM PARSE_SECURITY_DOMAIN}
  PARSE_SECURITY_DOMAIN = PARSE_LOCATION + 1;

  {$EXTERNALSYM PSU_DEFAULT}
  PSU_DEFAULT           = 1;
  {$EXTERNALSYM PSU_SECURITY_URL_ONLY}
  PSU_SECURITY_URL_ONLY = PSU_DEFAULT + 1;

  {$EXTERNALSYM QUERY_EXPIRATION_DATE}
  QUERY_EXPIRATION_DATE     = 1;
  {$EXTERNALSYM QUERY_TIME_OF_LAST_CHANGE}
  QUERY_TIME_OF_LAST_CHANGE = QUERY_EXPIRATION_DATE + 1;
  {$EXTERNALSYM QUERY_CONTENT_ENCODING}
  QUERY_CONTENT_ENCODING    = QUERY_TIME_OF_LAST_CHANGE + 1;
  {$EXTERNALSYM QUERY_CONTENT_TYPE}
  QUERY_CONTENT_TYPE        = QUERY_CONTENT_ENCODING + 1;
  {$EXTERNALSYM QUERY_REFRESH}
  QUERY_REFRESH             = QUERY_CONTENT_TYPE + 1;
  {$EXTERNALSYM QUERY_RECOMBINE}
  QUERY_RECOMBINE           = QUERY_REFRESH + 1;
  {$EXTERNALSYM QUERY_CAN_NAVIGATE}
  QUERY_CAN_NAVIGATE        = QUERY_RECOMBINE + 1;
  {$EXTERNALSYM QUERY_USES_NETWORK}
  QUERY_USES_NETWORK        = QUERY_CAN_NAVIGATE + 1;
  {$EXTERNALSYM QUERY_IS_CACHED}
  QUERY_IS_CACHED           = QUERY_USES_NETWORK + 1;
  {$EXTERNALSYM QUERY_IS_INSTALLEDENTRY}
  QUERY_IS_INSTALLEDENTRY   = QUERY_IS_CACHED + 1;
  {$EXTERNALSYM QUERY_IS_CACHED_OR_MAPPED}
  QUERY_IS_CACHED_OR_MAPPED = QUERY_IS_INSTALLEDENTRY + 1;
  {$EXTERNALSYM QUERY_USES_CACHE}
  QUERY_USES_CACHE          = QUERY_IS_CACHED_OR_MAPPED + 1;

type
  {$EXTERNALSYM IInternetProtocolInfo}
  IInternetProtocolInfo = interface
    ['{79eac9ec-baf9-11ce-8c82-00aa004ba90b}']
    function ParseUrl(pwzUrl: LPCWSTR; ParseAction: TParseAction; dwParseFlags: DWORD;
      pwzResult: LPWSTR; cchResult: DWORD; pcchResult: DWORD;
      dwReserved: DWORD): HResult; stdcall;
    function CombineUrl(pwzBaseUrl, pwzRelativeUrl: LPCWSTR; dwCombineFlags: DWORD;
      pwzResult: LPWSTR; cchResult: DWORD; out pcchResult: DWORD;
      dwReserved: DWORD): HResult; stdcall;
    function CompareUrl(pwzUrl1, pwzUrl2: LPCWSTR; dwCompareFlags: DWORD): HResult; stdcall;
    function QueryInfo(pwzUrl: LPCWSTR; QueryOption: TQueryOption; dwQueryFlags: DWORD;
      pBuffer: Pointer; cbBuffer: DWORD; var cbBuf: DWORD; dwReserved: DWORD): HResult; stdcall;
  end;

type
  {$EXTERNALSYM IOInet}
  IOInet =               IInternet;
  {$EXTERNALSYM IOInetBindInfo}
  IOInetBindInfo =       IInternetBindInfo;
  {$EXTERNALSYM IOInetProtocolRoot}
  IOInetProtocolRoot =   IInternetProtocolRoot;
  {$EXTERNALSYM IOInetProtocol}
  IOInetProtocol =       IInternetProtocol;
  {$EXTERNALSYM IOInetProtocolSink}
  IOInetProtocolSink =   IInternetProtocolSink;
  {$EXTERNALSYM IOInetProtocolInfo}
  IOInetProtocolInfo =   IInternetProtocolInfo;
  {$EXTERNALSYM IOInetSession}
  IOInetSession =        IInternetSession;
  {$EXTERNALSYM IOInetPriority}
  IOInetPriority =       IInternetPriority;
  {$EXTERNALSYM IOInetThreadSwitch}
  IOInetThreadSwitch =   IInternetThreadSwitch;

{$EXTERNALSYM CoInternetParseUrl}
function CoInternetParseUrl(pwzUrl: LPCWSTR; ParseAction: TParseAction;
  dwFlags: DWORD; pszResult: LPWSTR; cchResult: DWORD; var pcchResult: DWORD;
  dwReserved: DWORD): HResult; stdcall;
{$EXTERNALSYM CoInternetCombineUrl}
function CoInternetCombineUrl(pwzBaseUrl, pwzRelativeUrl: LPCWSTR;
  dwCombineFlags: DWORD; pszResult: LPWSTR; cchResult: DWORD;
  var pcchResult: DWORD; dwReserved: DWORD): HResult ; stdcall;
{$EXTERNALSYM CoInternetCompareUrl}
function CoInternetCompareUrl(pwzUrl1, pwzUrl2: LPCWSTR; dwFlags: DWORD): HResult; stdcall;
{$EXTERNALSYM CoInternetGetProtocolFlags}
function CoInternetGetProtocolFlags(pwzUrl: LPCWSTR; var dwFlags: DWORD;
  dwReserved: DWORD): HResult; stdcall;
{$EXTERNALSYM CoInternetQueryInfo}
function CoInternetQueryInfo(pwzUrl: LPCWSTR; QueryOptions: TQueryOption; dwQueryFlags: DWORD;
  pvBuffer: Pointer; cbBuffer: DWORD; var pcbBuffer: DWORD; dwReserved: DWORD): HResult; stdcall;
{$EXTERNALSYM CoInternetGetSession}
function CoInternetGetSession(dwSessionMode: DWORD; var pIInternetSession: IInternetSession;
  dwReserved: DWORD): HResult; stdcall;
{$EXTERNALSYM CoInternetGetSecurityUrl}
function CoInternetGetSecurityUrl(pwzUrl: LPCWSTR; var pwzSecUrl: LPWSTR; psuAction: TPSUAction;
  dwReserved: DWORD): HResult; stdcall;

// OInetXXX are synonyms for the previous functions
{$EXTERNALSYM OInetParseUrl}
function OInetParseUrl(pwzUrl: LPCWSTR; ParseAction: TParseAction; dwFlags: DWORD;
  pszResult: LPWSTR; cchResult: DWORD; var pcchResult: DWORD;
  dwReserved: DWORD): HResult; stdcall;
{$EXTERNALSYM OInetCombineUrl}
function OInetCombineUrl(pwzBaseUrl, pwzRelativeUrl: LPCWSTR; dwCombineFlags: DWORD;
  pszResult: LPWSTR; cchResult: DWORD; var pcchResult: DWORD;
  dwReserved: DWORD): HResult ; stdcall;
{$EXTERNALSYM OInetCompareUrl}
function OInetCompareUrl(pwzUrl1, pwzUrl2: LPCWSTR; dwFlags: DWORD): Hresult; stdcall;
{$EXTERNALSYM OInetGetProtocolFlags}
function OInetGetProtocolFlags(pwzUrl: LPCWSTR; var dwFlags: DWORD;
  dwReserved: DWORD): HResult; stdcall;
{$EXTERNALSYM OInetQueryInfo}
function OInetQueryInfo(pwzUrl: LPCWSTR; QueryOptions: TQueryOption; dwQueryFlags: DWORD;
  pvBuffer: Pointer; cbBuffer: DWORD; var pcbBuffer: DWORD; dwReserved: DWORD): HResult; stdcall;
{$EXTERNALSYM OInetGetSession}
function OInetGetSession(dwSessionMode: DWORD; var pIInternetSession: IInternetSession;
  dwReserved: DWORD): HResult; stdcall;
{$EXTERNALSYM OInetGetSecurityUrl}
function OInetGetSecurityUrl(pwzUrl: LPCWSTR; var pwzSecUrl: LPWSTR; psuAction: TPSUAction;
  dwReserved: DWORD): HResult; stdcall;

{$EXTERNALSYM CopyStgMedium}
function CopyStgMedium(const cstgmedSrc: TStgMedium; var stgmedDest: TStgMedium): HResult; stdcall;
{$EXTERNALSYM CopyBindInfo}
function CopyBindInfo(const cbiSrc: TBindInfo; var biDest: TBindInfo): HResult; stdcall;
{$EXTERNALSYM ReleaseBindInfo}
procedure ReleaseBindInfo(const bindinfo: TBindInfo); stdcall;

const
  {$EXTERNALSYM INET_E_USE_DEFAULT_PROTOCOLHANDLER}
  INET_E_USE_DEFAULT_PROTOCOLHANDLER = HResult($800C0011);
  {$EXTERNALSYM INET_E_USE_DEFAULT_SETTING}
  INET_E_USE_DEFAULT_SETTING         = HResult($800C0012);
  {$EXTERNALSYM INET_E_DEFAULT_ACTION}
  INET_E_DEFAULT_ACTION              = HResult($800C0011);
  {$EXTERNALSYM INET_E_QUERYOPTION_UNKNOWN}
  INET_E_QUERYOPTION_UNKNOWN         = HResult($800C0013);
  {$EXTERNALSYM INET_E_REDIRECTING}
  INET_E_REDIRECTING                 = HResult($800C0014);

  {$EXTERNALSYM PROTOCOLFLAG_NO_PICS_CHECK}
  PROTOCOLFLAG_NO_PICS_CHECK     = $00000001;

type
  {$EXTERNALSYM IInternetSecurityMgrSite}
  IInternetSecurityMgrSite = interface
    ['{79eac9ed-baf9-11ce-8c82-00aa004ba90b}']
    function GetWindow(out hwnd: HWnd): HResult; stdcall;
    function EnableModeless(fEnable: BOOL): HResult; stdcall;
  end;

const
  {$EXTERNALSYM MAX_SIZE_SECURITY_ID}
  MAX_SIZE_SECURITY_ID    = 512; // bytes;

  // MapUrlToZone returns the zone index given a URL
  {$EXTERNALSYM PUAF_DEFAULT}
  PUAF_DEFAULT            = $00000000;
  {$EXTERNALSYM PUAF_NOUI}
  PUAF_NOUI               = $00000001;
  {$EXTERNALSYM PUAF_ISFILE}
  PUAF_ISFILE             = $00000002;
  {$EXTERNALSYM PUAF_WARN_IF_DENIED}
  PUAF_WARN_IF_DENIED     = $00000004;
  {$EXTERNALSYM PUAF_FORCEUI_FOREGROUND}
  PUAF_FORCEUI_FOREGROUND = $00000008;
  {$EXTERNALSYM PUAF_CHECK_TIFS}
  PUAF_CHECK_TIFS         = $00000010;

// This is the wrapper function that most clients will use.
// It figures out the current Policy for the passed in Action,
// and puts up UI if the current Policy indicates that the user
// should be queried. It returns back the Policy which the caller
// will use to determine if the action should be allowed
// This is the wrapper function to conveniently read a custom policy.

// SetZoneMapping
//    lpszPattern: string denoting a URL pattern
//        Examples of valid patterns:
//            *://*.msn.com
//            http://*.sony.co.jp
//            *://et.msn.com
//            ftp://157.54.23.41/
//            https://localsvr
//            file:\localsvr\share
//            *://157.54.100-200.*
//        Examples of invalid patterns:
//            http://*.lcs.mit.edu
//            ftp://*
//    dwFlags: SZM_FLAGS values

  {$EXTERNALSYM SZM_CREATE}
  SZM_CREATE= $00000000;
  {$EXTERNALSYM SZM_DELETE}
  SZM_DELETE= $00000001;

type  
  {$EXTERNALSYM IInternetSecurityManager}
  IInternetSecurityManager = interface
    ['{79eac9ee-baf9-11ce-8c82-00aa004ba90b}']
    function SetSecuritySite(Site: IInternetSecurityMgrSite): HResult; stdcall;
    function GetSecuritySite(out Site: IInternetSecurityMgrSite): HResult; stdcall;
    function MapUrlToZone(pwszUrl: LPCWSTR; out dwZone: DWORD;
      dwFlags: DWORD): HResult; stdcall;
    function GetSecurityId(pwszUrl: LPCWSTR; pbSecurityId: Pointer;
      var cbSecurityId: DWORD; dwReserved: DWORD): HResult; stdcall;
    function ProcessUrlAction(pwszUrl: LPCWSTR; dwAction: DWORD;
      pPolicy: Pointer; cbPolicy: DWORD; pContext: Pointer; cbContext: DWORD;
      dwFlags, dwReserved: DWORD): HResult; stdcall;
    function QueryCustomPolicy(pwszUrl: LPCWSTR; const guidKey: TGUID;
      out pPolicy: Pointer; out cbPolicy: DWORD; pContext: Pointer; cbContext: DWORD;
      dwReserved: DWORD): HResult; stdcall;
    function SetZoneMapping(dwZone: DWORD; lpszPattern: LPCWSTR;
      dwFlags: DWORD): HResult; stdcall;
    function GetZoneMappings(dwZone: DWORD; out enumString: IEnumString;
      dwFlags: DWORD): HResult; stdcall;
  end;

  {$EXTERNALSYM IInternetHostSecurityManager}
  IInternetHostSecurityManager = interface
    ['{3af280b6-cb3f-11d0-891e-00c04fb6bfc4}']
    function GetSecurityId(pbSecurityId: Pointer; var cbSecurityId: DWORD;
      dwReserved: DWORD): HResult; stdcall;
    function ProcessUrlAction(dwAction: DWORD; pPolicy: Pointer; cbPolicy: DWORD;
      pContext: Pointer; cbContext, dwFlags, dwReserved: DWORD): HResult; stdcall;
    function QueryCustomPolicy(const guidKey: TGUID; out pPolicy: Pointer; out cbPolicy: DWORD;
      pContext: Pointer; cbContext, dwReserved: DWORD): HResult; stdcall;
  end;

const
  {$EXTERNALSYM URLACTION_MIN}
  URLACTION_MIN                                = $00001000;

  {$EXTERNALSYM URLACTION_DOWNLOAD_MIN}
  URLACTION_DOWNLOAD_MIN                       = $00001000;
  {$EXTERNALSYM URLACTION_DOWNLOAD_SIGNED_ACTIVEX}
  URLACTION_DOWNLOAD_SIGNED_ACTIVEX            = $00001001;
  {$EXTERNALSYM URLACTION_DOWNLOAD_UNSIGNED_ACTIVEX}
  URLACTION_DOWNLOAD_UNSIGNED_ACTIVEX          = $00001004;
  {$EXTERNALSYM URLACTION_DOWNLOAD_CURR_MAX}
  URLACTION_DOWNLOAD_CURR_MAX                  = $00001004;
  {$EXTERNALSYM URLACTION_DOWNLOAD_MAX}
  URLACTION_DOWNLOAD_MAX                       = $000011FF;

  {$EXTERNALSYM URLACTION_ACTIVEX_MIN}
  URLACTION_ACTIVEX_MIN                        = $00001200;
  {$EXTERNALSYM URLACTION_ACTIVEX_RUN}
  URLACTION_ACTIVEX_RUN                        = $00001200;
  {$EXTERNALSYM URLACTION_ACTIVEX_OVERRIDE_OBJECT_SAFETY}
  URLACTION_ACTIVEX_OVERRIDE_OBJECT_SAFETY     = $00001201; // aggregate next four
  {$EXTERNALSYM URLACTION_ACTIVEX_OVERRIDE_DATA_SAFETY}
  URLACTION_ACTIVEX_OVERRIDE_DATA_SAFETY       = $00001202; //
  {$EXTERNALSYM URLACTION_ACTIVEX_OVERRIDE_SCRIPT_SAFETY}
  URLACTION_ACTIVEX_OVERRIDE_SCRIPT_SAFETY     = $00001203; //
  {$EXTERNALSYM URLACTION_SCRIPT_OVERRIDE_SAFETY}
  URLACTION_SCRIPT_OVERRIDE_SAFETY             = $00001401; //
  {$EXTERNALSYM URLACTION_ACTIVEX_CONFIRM_NOOBJECTSAFETY}
  URLACTION_ACTIVEX_CONFIRM_NOOBJECTSAFETY     = $00001204; //
  {$EXTERNALSYM URLACTION_ACTIVEX_TREATASUNTRUSTED}
  URLACTION_ACTIVEX_TREATASUNTRUSTED           = $00001205;
  {$EXTERNALSYM URLACTION_ACTIVEX_CURR_MAX}
  URLACTION_ACTIVEX_CURR_MAX                   = $00001205;
  {$EXTERNALSYM URLACTION_ACTIVEX_MAX}
  URLACTION_ACTIVEX_MAX                        = $000013FF;

  {$EXTERNALSYM URLACTION_SCRIPT_MIN}
  URLACTION_SCRIPT_MIN                         = $00001400;
  {$EXTERNALSYM URLACTION_SCRIPT_RUN}
  URLACTION_SCRIPT_RUN                         = $00001400;
  {$EXTERNALSYM URLACTION_SCRIPT_JAVA_USE}
  URLACTION_SCRIPT_JAVA_USE                    = $00001402;
  {$EXTERNALSYM URLACTION_SCRIPT_SAFE_ACTIVEX}
  URLACTION_SCRIPT_SAFE_ACTIVEX                = $00001405;
  {$EXTERNALSYM URLACTION_SCRIPT_CURR_MAX}
  URLACTION_SCRIPT_CURR_MAX                    = $00001405;
  {$EXTERNALSYM URLACTION_SCRIPT_MAX}
  URLACTION_SCRIPT_MAX                         = $000015FF;

  {$EXTERNALSYM URLACTION_HTML_MIN}
  URLACTION_HTML_MIN                           = $00001600;
  {$EXTERNALSYM URLACTION_HTML_SUBMIT_FORMS}
  URLACTION_HTML_SUBMIT_FORMS                  = $00001601; // aggregate next two
  {$EXTERNALSYM URLACTION_HTML_SUBMIT_FORMS_FROM}
  URLACTION_HTML_SUBMIT_FORMS_FROM             = $00001602; //
  {$EXTERNALSYM URLACTION_HTML_SUBMIT_FORMS_TO}
  URLACTION_HTML_SUBMIT_FORMS_TO               = $00001603; //
  {$EXTERNALSYM URLACTION_HTML_FONT_DOWNLOAD}
  URLACTION_HTML_FONT_DOWNLOAD                 = $00001604;
  {$EXTERNALSYM URLACTION_HTML_JAVA_RUN}
  URLACTION_HTML_JAVA_RUN                      = $00001605; // derive from Java custom policy;
  {$EXTERNALSYM URLACTION_HTML_CURR_MAX}
  URLACTION_HTML_CURR_MAX                      = $00001605;
  {$EXTERNALSYM URLACTION_HTML_MAX}
  URLACTION_HTML_MAX                           = $000017FF;

  {$EXTERNALSYM URLACTION_SHELL_MIN}
  URLACTION_SHELL_MIN                          = $00001800;
  {$EXTERNALSYM URLACTION_SHELL_INSTALL_DTITEMS}
  URLACTION_SHELL_INSTALL_DTITEMS              = $00001800;
  {$EXTERNALSYM URLACTION_SHELL_MOVE_OR_COPY}
  URLACTION_SHELL_MOVE_OR_COPY                 = $00001802;
  {$EXTERNALSYM URLACTION_SHELL_FILE_DOWNLOAD}
  URLACTION_SHELL_FILE_DOWNLOAD                = $00001803;
  {$EXTERNALSYM URLACTION_SHELL_VERB}
  URLACTION_SHELL_VERB                         = $00001804;
  {$EXTERNALSYM URLACTION_SHELL_WEBVIEW_VERB}
  URLACTION_SHELL_WEBVIEW_VERB                 = $00001805;
  {$EXTERNALSYM URLACTION_SHELL_CURR_MAX}
  URLACTION_SHELL_CURR_MAX                     = $00001805;
  {$EXTERNALSYM URLACTION_SHELL_MAX}
  URLACTION_SHELL_MAX                          = $000019ff;

  {$EXTERNALSYM URLACTION_NETWORK_MIN}
  URLACTION_NETWORK_MIN                        = $00001A00;

  {$EXTERNALSYM URLACTION_CREDENTIALS_USE}
  URLACTION_CREDENTIALS_USE                    = $00001A00;
  {$EXTERNALSYM URLPOLICY_CREDENTIALS_SILENT_LOGON_OK}
  URLPOLICY_CREDENTIALS_SILENT_LOGON_OK        = $00000000;
  {$EXTERNALSYM URLPOLICY_CREDENTIALS_MUST_PROMPT_USER}
  URLPOLICY_CREDENTIALS_MUST_PROMPT_USER       = $00010000;
  {$EXTERNALSYM URLPOLICY_CREDENTIALS_CONDITIONAL_PROMPT}
  URLPOLICY_CREDENTIALS_CONDITIONAL_PROMPT     = $00020000;
  {$EXTERNALSYM URLPOLICY_CREDENTIALS_ANONYMOUS_ONLY}
  URLPOLICY_CREDENTIALS_ANONYMOUS_ONLY         = $00030000;

  {$EXTERNALSYM URLACTION_AUTHENTICATE_CLIENT}
  URLACTION_AUTHENTICATE_CLIENT                = $00001A01;
  {$EXTERNALSYM URLPOLICY_AUTHENTICATE_CLEARTEXT_OK}
  URLPOLICY_AUTHENTICATE_CLEARTEXT_OK          = $00000000;
  {$EXTERNALSYM URLPOLICY_AUTHENTICATE_CHALLENGE_RESPONSE}
  URLPOLICY_AUTHENTICATE_CHALLENGE_RESPONSE    = $00010000;
  {$EXTERNALSYM URLPOLICY_AUTHENTICATE_MUTUAL_ONLY}
  URLPOLICY_AUTHENTICATE_MUTUAL_ONLY           = $00030000;

  {$EXTERNALSYM URLACTION_NETWORK_CURR_MAX}
  URLACTION_NETWORK_CURR_MAX                   = $00001A01;
  {$EXTERNALSYM URLACTION_NETWORK_MAX}
  URLACTION_NETWORK_MAX                        = $00001BFF;

  {$EXTERNALSYM URLACTION_JAVA_MIN}
  URLACTION_JAVA_MIN                           = $00001C00;
  {$EXTERNALSYM URLACTION_JAVA_PERMISSIONS}
  URLACTION_JAVA_PERMISSIONS                   = $00001C00;
  {$EXTERNALSYM URLPOLICY_JAVA_PROHIBIT}
  URLPOLICY_JAVA_PROHIBIT                      = $00000000;
  {$EXTERNALSYM URLPOLICY_JAVA_HIGH}
  URLPOLICY_JAVA_HIGH                          = $00010000;
  {$EXTERNALSYM URLPOLICY_JAVA_MEDIUM}
  URLPOLICY_JAVA_MEDIUM                        = $00020000;
  {$EXTERNALSYM URLPOLICY_JAVA_LOW}
  URLPOLICY_JAVA_LOW                           = $00030000;
  {$EXTERNALSYM URLPOLICY_JAVA_CUSTOM}
  URLPOLICY_JAVA_CUSTOM                        = $00800000;
  {$EXTERNALSYM URLACTION_JAVA_CURR_MAX}
  URLACTION_JAVA_CURR_MAX                      = $00001C00;
  {$EXTERNALSYM URLACTION_JAVA_MAX}
  URLACTION_JAVA_MAX                           = $00001CFF;

// The following Infodelivery actions should have no default policies
// in the registry.  They assume that no default policy means fall
// back to the global restriction.  If an admin sets a policy per
// zone, then it overrides the global restriction.

  {$EXTERNALSYM URLACTION_INFODELIVERY_MIN}
  URLACTION_INFODELIVERY_MIN                       = $00001D00;
  {$EXTERNALSYM URLACTION_INFODELIVERY_NO_ADDING_CHANNELS}
  URLACTION_INFODELIVERY_NO_ADDING_CHANNELS        = $00001D00;
  {$EXTERNALSYM URLACTION_INFODELIVERY_NO_EDITING_CHANNELS}
  URLACTION_INFODELIVERY_NO_EDITING_CHANNELS       = $00001D01;
  {$EXTERNALSYM URLACTION_INFODELIVERY_NO_REMOVING_CHANNELS}
  URLACTION_INFODELIVERY_NO_REMOVING_CHANNELS      = $00001D02;
  {$EXTERNALSYM URLACTION_INFODELIVERY_NO_ADDING_SUBSCRIPTIONS}
  URLACTION_INFODELIVERY_NO_ADDING_SUBSCRIPTIONS   = $00001D03;
  {$EXTERNALSYM URLACTION_INFODELIVERY_NO_EDITING_SUBSCRIPTIONS}
  URLACTION_INFODELIVERY_NO_EDITING_SUBSCRIPTIONS  = $00001D04;
  {$EXTERNALSYM URLACTION_INFODELIVERY_NO_REMOVING_SUBSCRIPTIONS}
  URLACTION_INFODELIVERY_NO_REMOVING_SUBSCRIPTIONS = $00001D05;
  {$EXTERNALSYM URLACTION_INFODELIVERY_NO_CHANNEL_LOGGING}
  URLACTION_INFODELIVERY_NO_CHANNEL_LOGGING        = $00001D06;
  {$EXTERNALSYM URLACTION_INFODELIVERY_CURR_MAX}
  URLACTION_INFODELIVERY_CURR_MAX                  = $00001D06;
  {$EXTERNALSYM URLACTION_INFODELIVERY_MAX}
  URLACTION_INFODELIVERY_MAX                       = $00001Dff;
  {$EXTERNALSYM URLACTION_CHANNEL_SOFTDIST_MIN}
  URLACTION_CHANNEL_SOFTDIST_MIN                   = $00001E00;
  {$EXTERNALSYM URLACTION_CHANNEL_SOFTDIST_PERMISSIONS}
  URLACTION_CHANNEL_SOFTDIST_PERMISSIONS           = $00001E05;
  {$EXTERNALSYM URLPOLICY_CHANNEL_SOFTDIST_PROHIBIT}
  URLPOLICY_CHANNEL_SOFTDIST_PROHIBIT              = $00010000;
  {$EXTERNALSYM URLPOLICY_CHANNEL_SOFTDIST_PRECACHE}
  URLPOLICY_CHANNEL_SOFTDIST_PRECACHE              = $00020000;
  {$EXTERNALSYM URLPOLICY_CHANNEL_SOFTDIST_AUTOINSTALL}
  URLPOLICY_CHANNEL_SOFTDIST_AUTOINSTALL           = $00030000;
  {$EXTERNALSYM URLACTION_CHANNEL_SOFTDIST_MAX}
  URLACTION_CHANNEL_SOFTDIST_MAX                   = $00001EFF;

// For each action specified above the system maintains
// a set of policies for the action.
// The only policies supported currently are permissions (i.e. is something allowed)
// and logging status.
// IMPORTANT: If you are defining your own policies don't overload the meaning of the
// loword of the policy. You can use the hiword to store any policy bits which are only
// meaningful to your action.
// For an example of how to do this look at the URLPOLICY_JAVA above

// Permissions
  {$EXTERNALSYM URLPOLICY_ALLOW}
  URLPOLICY_ALLOW                = $00;
  {$EXTERNALSYM URLPOLICY_QUERY}
  URLPOLICY_QUERY                = $01;
  {$EXTERNALSYM URLPOLICY_DISALLOW}
  URLPOLICY_DISALLOW             = $03;

// Notifications are not done when user already queried.
  {$EXTERNALSYM URLPOLICY_NOTIFY_ON_ALLOW}
  URLPOLICY_NOTIFY_ON_ALLOW      = $10;
  {$EXTERNALSYM URLPOLICY_NOTIFY_ON_DISALLOW}
  URLPOLICY_NOTIFY_ON_DISALLOW   = $20;

// Logging is done regardless of whether user was queried.
  {$EXTERNALSYM URLPOLICY_LOG_ON_ALLOW}
  URLPOLICY_LOG_ON_ALLOW         = $40;
  {$EXTERNALSYM URLPOLICY_LOG_ON_DISALLOW}
  URLPOLICY_LOG_ON_DISALLOW      = $80;

  {$EXTERNALSYM URLPOLICY_MASK_PERMISSIONS}
  URLPOLICY_MASK_PERMISSIONS     = $0f;

{$EXTERNALSYM GetUrlPolicyPermissions}
function GetUrlPolicyPermissions(dw: DWORD): DWORD;
{$EXTERNALSYM SetUrlPolicyPermissions}
function SetUrlPolicyPermissions(dw, dw2: DWORD): DWORD;

// The ordinal #'s that define the predefined zones internet explorer knows about.
// When we support user-defined zones their zone numbers should be between
// URLZONE_USER_MIN and URLZONE_USER_MAX
  
const  
  {$EXTERNALSYM URLZONE_PREDEFINED_MIN}
  URLZONE_PREDEFINED_MIN =     0;
  {$EXTERNALSYM URLZONE_LOCAL_MACHINE}
  URLZONE_LOCAL_MACHINE  =     0;
  {$EXTERNALSYM URLZONE_INTRANET}
  URLZONE_INTRANET       = URLZONE_LOCAL_MACHINE + 1;
  {$EXTERNALSYM URLZONE_TRUSTED}
  URLZONE_TRUSTED        = URLZONE_INTRANET + 1;
  {$EXTERNALSYM URLZONE_INTERNET}
  URLZONE_INTERNET       = URLZONE_TRUSTED + 1;
  {$EXTERNALSYM URLZONE_UNTRUSTED}
  URLZONE_UNTRUSTED      = URLZONE_INTERNET + 1;
  {$EXTERNALSYM URLZONE_PREDEFINED_MAX}
  URLZONE_PREDEFINED_MAX =   999;
  {$EXTERNALSYM URLZONE_USER_MIN}
  URLZONE_USER_MIN       =  1000;
  {$EXTERNALSYM URLZONE_USER_MAX}
  URLZONE_USER_MAX       = 10000;

  {$EXTERNALSYM URLTEMPLATE_CUSTOM}
  URLTEMPLATE_CUSTOM         = $00000000;
  {$EXTERNALSYM URLTEMPLATE_PREDEFINED_MIN}
  URLTEMPLATE_PREDEFINED_MIN = $00010000;
  {$EXTERNALSYM URLTEMPLATE_LOW}
  URLTEMPLATE_LOW            = $00010000;
  {$EXTERNALSYM URLTEMPLATE_MEDIUM}
  URLTEMPLATE_MEDIUM         = $00011000;
  {$EXTERNALSYM URLTEMPLATE_HIGH}
  URLTEMPLATE_HIGH           = $00012000;
  {$EXTERNALSYM URLTEMPLATE_PREDEFINED_MAX}
  URLTEMPLATE_PREDEFINED_MAX = $00020000;

  {$EXTERNALSYM MAX_ZONE_PATH}
  MAX_ZONE_PATH              = 260;
  {$EXTERNALSYM MAX_ZONE_DESCRIPTION}
  MAX_ZONE_DESCRIPTION       = 200;

  {$EXTERNALSYM ZAFLAGS_CUSTOM_EDIT}
  ZAFLAGS_CUSTOM_EDIT            = $00000001;
  {$EXTERNALSYM ZAFLAGS_ADD_SITES}
  ZAFLAGS_ADD_SITES              = $00000002;
  {$EXTERNALSYM ZAFLAGS_REQUIRE_VERIFICATION}
  ZAFLAGS_REQUIRE_VERIFICATION   = $00000004;
  {$EXTERNALSYM ZAFLAGS_INCLUDE_PROXY_OVERRIDE}
  ZAFLAGS_INCLUDE_PROXY_OVERRIDE = $00000008;
  {$EXTERNALSYM ZAFLAGS_INCLUDE_INTRANET_SITES}
  ZAFLAGS_INCLUDE_INTRANET_SITES = $00000010;
  {$EXTERNALSYM ZAFLAGS_NO_UI}
  ZAFLAGS_NO_UI                  = $00000020;
  {$EXTERNALSYM ZAFLAGS_SUPPORTS_VERIFICATION}
  ZAFLAGS_SUPPORTS_VERIFICATION  = $00000040;
  {$EXTERNALSYM ZAFLAGS_UNC_AS_INTRANET}
  ZAFLAGS_UNC_AS_INTRANET        = $00000080;
  
type
  PZoneAttributes = ^TZoneAttributes;
  {$EXTERNALSYM _ZONEATTRIBUTES}
  _ZONEATTRIBUTES = packed record
    cbSize: ULONG;
    szDisplayName: array [0..260 - 1] of WideChar;
    szDescription: array [0..200 - 1] of WideChar;
    szIconPath: array [0..260 - 1] of WideChar;
    dwTemplateMinLevel: DWORD;
    dwTemplateRecommended: DWORD;
    dwTemplateCurrentLevel: DWORD;
    dwFlags: DWORD;
  end;
  TZoneAttributes = _ZONEATTRIBUTES;
  {$EXTERNALSYM ZONEATTRIBUTES}
  ZONEATTRIBUTES = _ZONEATTRIBUTES;

// Gets the zone attributes (information in registry other than actual security 
// policies associated with the zone).  Zone attributes are fixed as: 
// Sets the zone attributes (information in registry other than actual security 
// policies associated with the zone).  Zone attributes as above. 
// Returns S_OK or ??? if failed to write the zone attributes. 
{  Registry Flags 

    When reading, default behavior is: 
        If HKLM allows override and HKCU value exists 
            Then use HKCU value 
            Else use HKLM value 
    When writing, default behavior is same as HKCU 
        If HKLM allows override 
           Then Write to HKCU 
           Else Fail 
} 

const
  {$EXTERNALSYM URLZONEREG_DEFAULT}
  URLZONEREG_DEFAULT = 0;
  {$EXTERNALSYM URLZONEREG_HKLM}
  URLZONEREG_HKLM    = URLZONEREG_DEFAULT + 1;
  {$EXTERNALSYM URLZONEREG_HKCU}
  URLZONEREG_HKCU    = URLZONEREG_HKLM + 1;

// Gets a named custom policy associated with a zone; 
// e.g. the Java VM settings can be defined with a unique key such as 'Java'. 
// Custom policy support is intended to allow extensibility from the predefined 
// set of policies that IE4 has built in. 
//  
// pwszKey is the string name designating the custom policy.  Components are 
//   responsible for having unique names.
// ppPolicy is the callee allocated buffer for the policy byte blob; caller is
//   responsible for freeing this buffer eventually. 
// pcbPolicy is the size of the byte blob returned. 
// dwRegFlags determines how registry is accessed (see above). 
// Returns S_OK if key is found and buffer allocated; ??? if key is not found (no buffer alloced). 
// Sets a named custom policy associated with a zone;
// e.g. the Java VM settings can be defined with a unique key such as 'Java'. 
// Custom policy support is intended to allow extensibility from the predefined 
// set of policies that IE4 has built in.   
//  
// pwszKey is the string name designating the custom policy.  Components are 
//   responsible for having unique names. 
// ppPolicy is the caller allocated buffer for the policy byte blob. 
// pcbPolicy is the size of the byte blob to be set. 
// dwRegFlags determines if HTCU or HKLM is set. 
// Returns S_OK or ??? if failed to write the zone custom policy. 
// Gets action policy associated with a zone, the builtin, fixed-length policies info. 
 
// dwAction is the action code for the action as defined above. 
// pPolicy is the caller allocated buffer for the policy data. 
// cbPolicy is the size of the caller allocated buffer. 
// dwRegFlags determines how registry is accessed (see above). 
// Returns S_OK if action is valid; ??? if action is not valid. 

type
  {$EXTERNALSYM IInternetZoneManager}
  IInternetZoneManager = interface
    ['{79eac9ef-baf9-11ce-8c82-00aa004ba90b}']

    // Gets the zone attributes (information in registry other than actual security
    // policies associated with the zone).  Zone attributes are fixed as:
    function GetZoneAttributes(dwZone: DWORD;
      var ZoneAttributes: TZoneAttributes): HResult; stdcall;

    // Sets the zone attributes (information in registry other than actual security
    // policies associated with the zone).  Zone attributes as above.
    // Returns S_OK or ??? if failed to write the zone attributes.
    function SetZoneAttributes(dwZone: DWORD;
      const ZoneAttributes: TZoneAttributes): HResult; stdcall;
    function GetZoneCustomPolicy(dwZone: DWORD; const guidKey: TGUID; out pPolicy: Pointer;
      out cbPolicy: DWORD; urlZoneReg: TUrlZoneReg): HResult; stdcall;
    function SetZoneCustomPolicy(dwZone: DWORD; const guidKey: TGUID; pPolicy: Pointer;
      cbPolicy: DWORD; urlZoneReg: TUrlZoneReg): HResult; stdcall;
    function GetZoneActionPolicy(dwZone, dwAction: DWORD; pPolicy: Pointer;
      cbPolicy: DWORD; urlZoneReg: TUrlZoneReg): HResult; stdcall;
    function SetZoneActionPolicy(dwZone, dwAction: DWORD; pPolicy: Pointer;
      cbPolicy: DWORD; urlZoneReg: TUrlZoneReg): HResult; stdcall;
    function PromptAction(dwAction: DWORD; hwndParent: HWnd; pwszUrl, pwszText: LPCWSTR;
      dwPromptFlags: DWORD): HResult; stdcall;
    function LogAction(dwAction: DWORD; pwszUrl, pwszText: LPCWSTR;
      dwLogFlags: DWORD): HResult; stdcall;
    function CreateZoneEnumerator(out dwEnum, dwCount: DWORD;
      dwFlags: DWORD): HResult; stdcall;
    function GetZoneAt(dwEnum, dwIndex: DWORD; out dwZone: DWORD): HResult; stdcall;
    function DestroyZoneEnumerator(dwEnum: DWORD): HResult; stdcall;
    function CopyTemplatePoliciesToZone(dwTemplate, dwZone, dwReserved: DWORD): HResult; stdcall;
  end;

// Creates the security manager object. The first argument is the Service provider
// to allow for delegation
{$EXTERNALSYM CoInternetCreateSecurityManager}
function CoInternetCreateSecurityManager(SP: IServiceProvider; var SM: IInternetSecurityManager;
  dwReserved: DWORD): HResult; stdcall;
{$EXTERNALSYM CoInternetCreateZoneManager}
function CoInternetCreateZoneManager(SP: IServiceProvider; var ZM: IInternetZoneManager;
  dwReserved: DWORD): HResult; stdcall;

const
  {$EXTERNALSYM SOFTDIST_FLAG_USAGE_EMAIL}
  SOFTDIST_FLAG_USAGE_EMAIL         = $00000001;
  {$EXTERNALSYM SOFTDIST_FLAG_USAGE_PRECACHE}
  SOFTDIST_FLAG_USAGE_PRECACHE      = $00000002;
  {$EXTERNALSYM SOFTDIST_FLAG_USAGE_AUTOINSTALL}
  SOFTDIST_FLAG_USAGE_AUTOINSTALL   = $00000004;
  {$EXTERNALSYM SOFTDIST_FLAG_DELETE_SUBSCRIPTION}
  SOFTDIST_FLAG_DELETE_SUBSCRIPTION = $00000008;

  {$EXTERNALSYM SOFTDIST_ADSTATE_NONE}
  SOFTDIST_ADSTATE_NONE             = $00000000;
  {$EXTERNALSYM SOFTDIST_ADSTATE_AVAILABLE}
  SOFTDIST_ADSTATE_AVAILABLE        = $00000001;
  {$EXTERNALSYM SOFTDIST_ADSTATE_DOWNLOADED}
  SOFTDIST_ADSTATE_DOWNLOADED       = $00000002;
  {$EXTERNALSYM SOFTDIST_ADSTATE_INSTALLED}
  SOFTDIST_ADSTATE_INSTALLED        = $00000003;

type
  PCodeBaseHold = ^TCodeBaseHold;
  {$EXTERNALSYM _tagCODEBASEHOLD}
  _tagCODEBASEHOLD = packed record
    cbSize: ULONG;
    szDistUnit: LPWSTR;
    szCodeBase: LPWSTR;
    dwVersionMS: DWORD;
    dwVersionLS: DWORD;
    dwStyle: DWORD;
  end;
  TCodeBaseHold = _tagCODEBASEHOLD;
  {$EXTERNALSYM CODEBASEHOLD}
  CODEBASEHOLD = _tagCODEBASEHOLD;

  PSoftDistInfo = ^TSoftDistInfo;
  {$EXTERNALSYM _tagSOFTDISTINFO}
  _tagSOFTDISTINFO = packed record
    cbSize: ULONG;
    dwFlags: DWORD;
    dwAdState: DWORD;
    szTitle: LPWSTR;
    szAbstract: LPWSTR;
    szHREF: LPWSTR;
    dwInstalledVersionMS: DWORD;
    dwInstalledVersionLS: DWORD;
    dwUpdateVersionMS: DWORD;
    dwUpdateVersionLS: DWORD;
    dwAdvertisedVersionMS: DWORD;
    dwAdvertisedVersionLS: DWORD;
    dwReserved: DWORD;
  end;
  TSoftDistInfo = _tagSOFTDISTINFO;
  {$EXTERNALSYM SOFTDISTINFO}
  SOFTDISTINFO = _tagSOFTDISTINFO;

  {$EXTERNALSYM ISoftDistExt}
  ISoftDistExt = interface
    ['{B15B8DC1-C7E1-11d0-8680-00AA00BDCB71}']
    function ProcessSoftDist(szCDFURL: LPCWSTR; SoftDistElement: Pointer {IXMLElement};
      var lpdsi: TSoftDistInfo): HResult; stdcall;
    function GetFirstCodeBase(var szCodeBase: LPWSTR;
      const dwMaxSize: DWORD): HResult; stdcall;
    function GetNextCodeBase(var szCodeBase: LPWSTR;
      const dwMaxSize: DWORD): HResult; stdcall;
    function AsyncInstallDistributionUnit(bc: IBindCtx; pvReserved: Pointer;
      flags: DWORD; const cbh: TCodeBaseHold): HResult; stdcall;
  end;

{$EXTERNALSYM GetSoftwareUpdateInfo}
function GetSoftwareUpdateInfo(szDistUnit: LPCWSTR; var dsi: TSoftDistInfo): HResult; stdcall;
{$EXTERNALSYM SetSoftwareUpdateAdvertisementState}
function SetSoftwareUpdateAdvertisementState(szDistUnit: LPCWSTR;
  dwAdState, dwAdvertisedVersionMS, dwAdvertisedVersionLS: DWORD): HResult; stdcall;

type
  {$EXTERNALSYM IDataFilter}
  IDataFilter = interface
    ['{69d14c80-c18e-11d0-a9ce-006097942311}']
    function DoEncode(dwFlags: DWORD; lInBufferSize: Longint; pbInBuffer: Pointer;
      lOutBufferSize: Longint; pbOutBuffer: Pointer; lInBytesAvailable: Longint;
      out lInBytesRead, lOutBytesWritten: Longint; dwReserved: DWORD): HResult; stdcall;
    function DoDecode(dwFlags: DWORD; lInBufferSize: Longint; pbInBuffer: Pointer;
      lOutBufferSize: Longint; pbOutBuffer: Pointer; lInBytesAvailable: Longint;
      out lInBytesRead, lOutBytesWritten: Longint; dwReserved: DWORD): HResult; stdcall;
    function SetEncodingLevel(dwEncLevel: DWORD): HResult; stdcall;
  end;

  PProtocolFilterData = ^TProtocolFilterData;
  {$EXTERNALSYM _tagPROTOCOLFILTERDATA}
  _tagPROTOCOLFILTERDATA = packed record
    cbSize: DWORD;
    ProtocolSink: IInternetProtocolSink;
    Protocol: IInternetProtocol;
    Unk: IUnknown;
    dwFilterFlags: DWORD;
  end;
  TProtocolFilterData = _tagPROTOCOLFILTERDATA;
  {$EXTERNALSYM PROTOCOLFILTERDATA}
  PROTOCOLFILTERDATA = _tagPROTOCOLFILTERDATA;
  
  PDataInfo = ^TDataInfo;
  {$EXTERNALSYM _tagDATAINFO}
  _tagDATAINFO = packed record
    ulTotalSize: ULONG;
    ulavrPacketSize: ULONG;
    ulConnectSpeed: ULONG;
    ulProcessorSpeed: ULONG;
  end;
  TDataInfo = _tagDATAINFO;
  {$EXTERNALSYM DATAINFO}
  DATAINFO = _tagDATAINFO;

  {$EXTERNALSYM IEncodingFilterFactory}
  IEncodingFilterFactory = interface
    ['{70bdde00-c18e-11d0-a9ce-006097942311}']
    function FindBestFilter(pwzCodeIn, pwzCodeOut: LPCWSTR; info: TDataInfo;
      out DF: IDataFilter): HResult; stdcall;
    function GetDefaultFilter(pwzCodeIn, pwzCodeOut: LPCWSTR; info: TDataInfo;
      out DF: IDataFilter): HResult; stdcall;
  end;

// Logging-specific apis
{$EXTERNALSYM IsLoggingEnabledA}
function IsLoggingEnabledA(pszUrl: PAnsiChar): BOOL; stdcall;
{$EXTERNALSYM IsLoggingEnabledW}
function IsLoggingEnabledW(pszUrl: PWideChar): BOOL; stdcall;
{$EXTERNALSYM IsLoggingEnabled}
function IsLoggingEnabled(pszUrl: PChar): BOOL; stdcall;

type
  PHitLoggingInfo = ^THitLoggingInfo;
  {$EXTERNALSYM _tagHIT_LOGGING_INFO}
  _tagHIT_LOGGING_INFO = packed record
    dwStructSize: DWORD;
    lpszLoggedUrlName: LPSTR;
    StartTime: TSystemTime;
    EndTime: TSystemTime;
    lpszExtendedInfo: LPSTR;
  end;
  THitLoggingInfo = _tagHIT_LOGGING_INFO;
  {$EXTERNALSYM HIT_LOGGING_INFO}
  HIT_LOGGING_INFO = _tagHIT_LOGGING_INFO;

{$EXTERNALSYM WriteHitLogging}
function WriteHitLogging(const Logginginfo: THitLoggingInfo): BOOL; stdcall;

implementation

const
  UrlMonLib = 'URLMON.DLL';

// Macro implementations
function GetUrlPolicyPermissions(dw: DWORD): DWORD;
begin
  Result := dw and URLPOLICY_MASK_PERMISSIONS;
end;

function SetUrlPolicyPermissions(dw, dw2: DWORD): DWORD;
begin
  dw := (dw and not (URLPOLICY_MASK_PERMISSIONS)) or dw2;
  Result := dw;
end;

function CreateURLMoniker;                external UrlMonLib name 'CreateURLMoniker';
function GetClassURL;                     external UrlMonLib name 'GetClassURL';
function CreateAsyncBindCtx;              external UrlMonLib name 'CreateAsyncBindCtx';
function CreateAsyncBindCtxEx;            external UrlMonLib name 'CreateAsyncBindCtxEx';
function MkParseDisplayNameEx;            external UrlMonLib name 'MkParseDisplayNameEx';
function RegisterBindStatusCallback;      external UrlMonLib name 'RegisterBindStatusCallback';
function RevokeBindStatusCallback;        external UrlMonLib name 'RevokeBindStatusCallback';
function GetClassFileOrMime;              external UrlMonLib name 'GetClassFileOrMime';
function IsValidURL;                      external UrlMonLib name 'IsValidURL';
function CoGetClassObjectFromURL;         external UrlMonLib name 'CoGetClassObjectFromURL';
function IsAsyncMoniker;                  external UrlMonLib name 'IsAsyncMoniker';
function CreateURLBinding;                external UrlMonLib name 'CreateURLBinding';
function RegisterMediaTypes;              external UrlMonLib name 'RegisterMediaTypes';
function FindMediaType;                   external UrlMonLib name 'FindMediaType';
function CreateFormatEnumerator;          external UrlMonLib name 'CreateFormatEnumerator';
function RegisterFormatEnumerator;        external UrlMonLib name 'RegisterFormatEnumerator';
function RevokeFormatEnumerator;          external UrlMonLib name 'RevokeFormatEnumerator';
function RegisterMediaTypeClass;          external UrlMonLib name 'RegisterMediaTypeClass';
function FindMediaTypeClass;              external UrlMonLib name 'FindMediaTypeClass';
function UrlMkSetSessionOption;           external UrlMonLib name 'UrlMkSetSessionOption';
function UrlMkGetSessionOption;           external UrlMonLib name 'UrlMkGetSessionOption';
function FindMimeFromData;                external UrlMonLib name 'FindMimeFromData';
function ObtainUserAgentString;           external UrlMonLib name 'ObtainUserAgentString';
function HlinkSimpleNavigateToString;     external UrlMonLib name 'HlinkSimpleNavigateToString';
function HlinkSimpleNavigateToMoniker;    external UrlMonLib name 'HlinkSimpleNavigateToMoniker';
function URLOpenStreamA;                  external UrlMonLib name 'URLOpenStreamA';
function URLOpenStreamW;                  external UrlMonLib name 'URLOpenStreamW';
function URLOpenStream;                  external UrlMonLib name 'URLOpenStreamA';
function URLOpenPullStreamA;              external UrlMonLib name 'URLOpenPullStreamA';
function URLOpenPullStreamW;              external UrlMonLib name 'URLOpenPullStreamW';
function URLOpenPullStream;              external UrlMonLib name 'URLOpenPullStreamA';
function URLDownloadToFileA;              external UrlMonLib name 'URLDownloadToFileA';
function URLDownloadToFileW;              external UrlMonLib name 'URLDownloadToFileW';
function URLDownloadToFile;              external UrlMonLib name 'URLDownloadToFileA';
function URLDownloadToCacheFileA;         external UrlMonLib name 'URLDownloadToCacheFileA';
function URLDownloadToCacheFileW;         external UrlMonLib name 'URLDownloadToCacheFileW';
function URLDownloadToCacheFile;         external UrlMonLib name 'URLDownloadToCacheFileA';
function URLOpenBlockingStreamA;          external UrlMonLib name 'URLOpenBlockingStreamA';
function URLOpenBlockingStreamW;          external UrlMonLib name 'URLOpenBlockingStreamW';
function URLOpenBlockingStream;          external UrlMonLib name 'URLOpenBlockingStreamA';
function HlinkGoBack;                     external UrlMonLib name 'HlinkGoBack';
function HlinkGoForward;                  external UrlMonLib name 'HlinkGoForward';
function HlinkNavigateString;             external UrlMonLib name 'HlinkNavigateString';
function HlinkNavigateMoniker;            external UrlMonLib name 'HlinkNavigateMoniker';
function CoInternetParseUrl;              external UrlMonLib name 'CoInternetParseUrl';
function CoInternetCombineUrl;            external UrlMonLib name 'CoInternetCombineUrl';
function CoInternetCompareUrl;            external UrlMonLib name 'CoInternetCompareUrl';
function CoInternetGetProtocolFlags;      external UrlMonLib name 'CoInternetGetProtocolFlags';
function CoInternetQueryInfo;             external UrlMonLib name 'CoInternetQueryInfo';
function CoInternetGetSession;            external UrlMonLib name 'CoInternetGetSession';
function CoInternetGetSecurityUrl;        external UrlMonLib name 'CoInternetGetSecurityUrl';
function OInetParseUrl;                   external UrlMonLib name 'CoInternetParseUrl';
function OInetCombineUrl;                 external UrlMonLib name 'CoInternetCombineUrl';
function OInetCompareUrl;                 external UrlMonLib name 'CoInternetCompareUrl';
function OInetQueryInfo;                  external UrlMonLib name 'CoInternetQueryInfo';
function OInetGetSession;                 external UrlMonLib name 'CoInternetGetSession';
function OInetGetProtocolFlags;           external UrlMonLib name 'OInetGetProtocolFlags';
function OInetGetSecurityUrl;             external UrlMonLib name 'OInetGetSecurityUrl';
function CopyStgMedium;                   external UrlMonLib name 'CopyStgMedium';
function CopyBindInfo;                    external UrlMonLib name 'CopyBindInfo';
procedure ReleaseBindInfo;                external UrlMonLib name 'ReleaseBindInfo';
function CoInternetCreateSecurityManager; external UrlMonLib name 'CoInternetCreateSecurityManager';
function CoInternetCreateZoneManager;     external UrlMonLib name 'CoInternetCreateZoneManager';
function GetSoftwareUpdateInfo;           external UrlMonLib name 'GetSoftwareUpdateInfo';
function IsLoggingEnabledA;               external UrlMonLib name 'IsLoggingEnabledA';
function IsLoggingEnabledW;               external UrlMonLib name 'IsLoggingEnabledW';
function IsLoggingEnabled;               external UrlMonLib name 'IsLoggingEnabledA';
function WriteHitLogging;                 external UrlMonLib name 'WriteHitLogging';
function SetSoftwareUpdateAdvertisementState; external UrlMonLib name 'SetSoftwareUpdateAdvertisementState';

end.
