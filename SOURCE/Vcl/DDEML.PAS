
{*******************************************************}
{                                                       }
{       Borland Delphi Run-time Library                 }
{       DDE Management Library interface unit           }
{                                                       }
{       Copyright (c) 1985-1999, Microsoft Corporation  }
{                                                       }
{       Translator: Inprise Corporation                 }
{                                                       }
{*******************************************************}

unit Ddeml;

{$WEAKPACKAGEUNIT}

{$HPPEMIT '#include <ddeml.h>'}

interface

uses Windows;

type
  HConvList = Longint;
  HConv = Longint;
  HSz = Longint;
  HDDEData = Longint;

type
  { the following structure is for use with xtyp_WildConnect processing. }
  PHSZPair = ^THSZPair;
  {$EXTERNALSYM tagHSZPAIR}
  tagHSZPAIR = record
    hszSvc: HSZ;
    hszTopic: HSZ;
  end;
  THSZPair = tagHSZPAIR;
  {$EXTERNALSYM HSZPAIR}
  HSZPAIR = tagHSZPAIR;

  { The following structure is used by DdeConnect() and DdeConnectList()
    and by xtyp_Connect and xtyp_WildConnect callbacks. }

  PConvContext = ^TConvContext;
  {$EXTERNALSYM tagCONVCONTEXT}
  tagCONVCONTEXT = record
    cb: UINT;            { set to sizeof(ConvCOnTEXT) }
    wFlags: UINT;        { none currently defined. }
    wCountryID: UINT;    { country code for topic/item strings used. }
    iCodePage: Integer;  { codepage used for topic/item strings. }
    dwLangID: DWORD;     { language ID for topic/item strings. }
    dwSecurity: DWORD;   { Private security code. }
    qos: TSecurityQualityOfService;  { used to support client impersonation }
  end;
  TConvContext = tagCONVCONTEXT;
  {$EXTERNALSYM CONVCONTEXT}
  CONVCONTEXT = tagCONVCONTEXT;

{ The following structure is used by DdeQueryConvInfo(): }

  PConvInfo = ^TConvInfo;
  {$EXTERNALSYM tagCONVINFO}
  tagCONVINFO = record
    cb: DWORD;            { sizeof(CONVINFO)  }
    hUser: DWORD;         { user specified field  }
    hConvPartner: HConv;    { hConv on other end or 0 if non-ddemgr partner  }
    hszSvcPartner: HSz;     { app name of partner if obtainable  }
    hszServiceReq: HSz;     { AppName requested for connection  }
    hszTopic: HSz;          { Topic name for conversation  }
    hszItem: HSz;           { transaction item name or NULL if quiescent  }
    wFmt: UINT;             { transaction format or NULL if quiescent  }
    wType: UINT;            { XTYP_ for current transaction  }
    wStatus: UINT;          { ST_ constant for current conversation  }
    wConvst: UINT;          { XST_ constant for current transaction  }
    wLastError: UINT;       { last transaction error.  }
    hConvList: HConvList;   { parent hConvList if this conversation is in a list }
    ConvCtxt: TConvContext; { conversation context }
    hwnd: HWND;             { window handle for this conversation }
    hwndPartner: HWND;      { partner window handle for this conversation }
  end;
  TConvInfo = tagCONVINFO;
  {$EXTERNALSYM CONVINFO}
  CONVINFO = tagCONVINFO;

const
  { conversation states (usState) }

  {$EXTERNALSYM XST_NULL}
  XST_NULL = 0;                 { quiescent states }
  {$EXTERNALSYM XST_INCOMPLETE}
  XST_INCOMPLETE = 1;
  {$EXTERNALSYM XST_CONNECTED}
  XST_CONNECTED = 2;
  {$EXTERNALSYM XST_INIT1}
  XST_INIT1 = 3;                { mid-initiation states }
  {$EXTERNALSYM XST_INIT2}
  XST_INIT2 = 4;
  {$EXTERNALSYM XST_REQSENT}
  XST_REQSENT = 5;              { active conversation states }
  {$EXTERNALSYM XST_DATARCVD}
  XST_DATARCVD = 6;
  {$EXTERNALSYM XST_POKESENT}
  XST_POKESENT = 7;
  {$EXTERNALSYM XST_POKEACKRCVD}
  XST_POKEACKRCVD = 8;
  {$EXTERNALSYM XST_EXECSENT}
  XST_EXECSENT = 9;
  {$EXTERNALSYM XST_EXECACKRCVD}
  XST_EXECACKRCVD = 10;
  {$EXTERNALSYM XST_ADVSENT}
  XST_ADVSENT = 11;
  {$EXTERNALSYM XST_UNADVSENT}
  XST_UNADVSENT = 12;
  {$EXTERNALSYM XST_ADVACKRCVD}
  XST_ADVACKRCVD = 13;
  {$EXTERNALSYM XST_UNADVACKRCVD}
  XST_UNADVACKRCVD = 14;
  {$EXTERNALSYM XST_ADVDATASENT}
  XST_ADVDATASENT = 15;
  {$EXTERNALSYM XST_ADVDATAACKRCVD}
  XST_ADVDATAACKRCVD = 16;

  { used in LOWORD(dwData1) of XTYP_ADVREQ callbacks... }

  {$EXTERNALSYM CADV_LATEACK}
  CADV_LATEACK = $FFFF;

  { conversation status bits (fsStatus) }

  {$EXTERNALSYM ST_CONNECTED}
  ST_CONNECTED = $0001;
  {$EXTERNALSYM ST_ADVISE}
  ST_ADVISE = $0002;
  {$EXTERNALSYM ST_ISLOCAL}
  ST_ISLOCAL = $0004;
  {$EXTERNALSYM ST_BLOCKED}
  ST_BLOCKED = $0008;
  {$EXTERNALSYM ST_CLIENT}
  ST_CLIENT = $0010;
  {$EXTERNALSYM ST_TERMINATED}
  ST_TERMINATED = $0020;
  {$EXTERNALSYM ST_INLIST}
  ST_INLIST = $0040;
  {$EXTERNALSYM ST_BLOCKNEXT}
  ST_BLOCKNEXT = $0080;
  {$EXTERNALSYM ST_ISSELF}
  ST_ISSELF = $0100;

  { DDE constants for wStatus field }

  {$EXTERNALSYM DDE_FACK}
  DDE_FACK = $8000;
  {$EXTERNALSYM DDE_FBUSY}
  DDE_FBUSY = $4000;
  {$EXTERNALSYM DDE_FDEFERUPD}
  DDE_FDEFERUPD = $4000;
  {$EXTERNALSYM DDE_FACKREQ}
  DDE_FACKREQ = $8000;
  {$EXTERNALSYM DDE_FRELEASE}
  DDE_FRELEASE = $2000;
  {$EXTERNALSYM DDE_FREQUESTED}
  DDE_FREQUESTED = $1000;
  {$EXTERNALSYM DDE_FAPPSTATUS}
  DDE_FAPPSTATUS = $00ff;
  {$EXTERNALSYM DDE_FNOTPROCESSED}
  DDE_FNOTPROCESSED = $0000;

  {$EXTERNALSYM DDE_FACKRESERVED}
  DDE_FACKRESERVED = $3ff0;
  {$EXTERNALSYM DDE_FADVRESERVED}
  DDE_FADVRESERVED = $3fff;
  {$EXTERNALSYM DDE_FDATRESERVED}
  DDE_FDATRESERVED = $4fff;
  {$EXTERNALSYM DDE_FPOKRESERVED}
  DDE_FPOKRESERVED = $dfff;

  { message filter hook types }

  {$EXTERNALSYM MSGF_DDEMGR}
  MSGF_DDEMGR = $8001;

  { default codepage for windows & old DDE convs. }

  {$EXTERNALSYM CP_WINANSI}
  CP_WINANSI = 1004;
  {$EXTERNALSYM CP_WINUNICODE}
  CP_WINUNICODE = 1200;

  {$EXTERNALSYM CP_WINNEUTRAL}
	{$IFDEF UNICODE}
	CP_WINNEUTRAL = CP_WINUNICODE;
	{$ELSE}
	CP_WINNEUTRAL = CP_WINANSI;
	{$ENDIF}
  { transaction types }

  {$EXTERNALSYM XTYPF_NOBLOCK}
  XTYPF_NOBLOCK = $0002; { CBR_BLOCK will not work }
  {$EXTERNALSYM XTYPF_NODATA}
  XTYPF_NODATA = $0004;  { DDE_FDEFERUPD }
  {$EXTERNALSYM XTYPF_ACKREQ}
  XTYPF_ACKREQ = $0008;  { DDE_FACKREQ }

  {$EXTERNALSYM XCLASS_MASK}
  XCLASS_MASK = $FC00;
  {$EXTERNALSYM XCLASS_BOOL}
  XCLASS_BOOL = $1000;
  {$EXTERNALSYM XCLASS_DATA}
  XCLASS_DATA = $2000;
  {$EXTERNALSYM XCLASS_FLAGS}
  XCLASS_FLAGS = $4000;
  {$EXTERNALSYM XCLASS_NOTIFICATION}
  XCLASS_NOTIFICATION = $8000;

  {$EXTERNALSYM XTYP_ERROR}
  XTYP_ERROR = $0000 or XCLASS_NOTIFICATION or XTYPF_NOBLOCK;
  {$EXTERNALSYM XTYP_ADVDATA}
  XTYP_ADVDATA = $0010 or XCLASS_FLAGS;
  {$EXTERNALSYM XTYP_ADVREQ}
  XTYP_ADVREQ = $0020 or XCLASS_DATA or XTYPF_NOBLOCK;
  {$EXTERNALSYM XTYP_ADVSTART}
  XTYP_ADVSTART = $0030 or XCLASS_BOOL;
  {$EXTERNALSYM XTYP_ADVSTOP}
  XTYP_ADVSTOP = $0040 or XCLASS_NOTIFICATION;
  {$EXTERNALSYM XTYP_EXECUTE}
  XTYP_EXECUTE = $0050 or XCLASS_FLAGS;
  {$EXTERNALSYM XTYP_CONNECT}
  XTYP_CONNECT = $0060 or XCLASS_BOOL or XTYPF_NOBLOCK;
  {$EXTERNALSYM XTYP_CONNECT_CONFIRM}
  XTYP_CONNECT_CONFIRM = $0070 or XCLASS_NOTIFICATION or XTYPF_NOBLOCK;
  {$EXTERNALSYM XTYP_XACT_COMPLETE}
  XTYP_XACT_COMPLETE = $0080 or XCLASS_NOTIFICATION;
  {$EXTERNALSYM XTYP_POKE}
  XTYP_POKE = $0090 or XCLASS_FLAGS;
  {$EXTERNALSYM XTYP_REGISTER}
  XTYP_REGISTER = $00A0 or XCLASS_NOTIFICATION or XTYPF_NOBLOCK;
  {$EXTERNALSYM XTYP_REQUEST}
  XTYP_REQUEST = $00B0 or XCLASS_DATA;
  {$EXTERNALSYM XTYP_DISCONNECT}
  XTYP_DISCONNECT = $00C0 or XCLASS_NOTIFICATION or XTYPF_NOBLOCK;
  {$EXTERNALSYM XTYP_UNREGISTER}
  XTYP_UNREGISTER = $00D0 or XCLASS_NOTIFICATION or XTYPF_NOBLOCK;
  {$EXTERNALSYM XTYP_WILDCONNECT}
  XTYP_WILDCONNECT = $00E0 or XCLASS_DATA or XTYPF_NOBLOCK;

  {$EXTERNALSYM XTYP_MASK}
  XTYP_MASK = $00F0;
  {$EXTERNALSYM XTYP_SHIFT}
  XTYP_SHIFT = 4;  { shift to turn xtyp_ into an index }

  { Timeout constants }

  {$EXTERNALSYM TIMEOUT_ASYNC}
  TIMEOUT_ASYNC =           DWORD(-1);

  { Transaction ID constatnts }
  {$EXTERNALSYM QID_SYNC}
  QID_SYNC =                DWORD(-1);

  { public strings used in DDE }

  {$EXTERNALSYM SZDDESYS_TOPIC}
  SZDDESYS_TOPIC = 'System';
  {$EXTERNALSYM SZDDESYS_ITEM_TOPICS}
  SZDDESYS_ITEM_TOPICS = 'Topics';
  {$EXTERNALSYM SZDDESYS_ITEM_SYSITEMS}
  SZDDESYS_ITEM_SYSITEMS = 'SysItems';
  {$EXTERNALSYM SZDDESYS_ITEM_RTNMSG}
  SZDDESYS_ITEM_RTNMSG = 'ReturnMessage';
  {$EXTERNALSYM SZDDESYS_ITEM_STATUS}
  SZDDESYS_ITEM_STATUS = 'Status';
  {$EXTERNALSYM SZDDESYS_ITEM_FORMATS}
  SZDDESYS_ITEM_FORMATS = 'Formats';
  {$EXTERNALSYM SZDDESYS_ITEM_HELP}
  SZDDESYS_ITEM_HELP = 'Help';
  {$EXTERNALSYM SZDDE_ITEM_ITEMLIST}
  SZDDE_ITEM_ITEMLIST = 'TopicItemList';

type
  { API entry points }
  {$EXTERNALSYM PFNCALLBACK}
  PFNCALLBACK = function (CallType, Fmt: UINT; Conv: HConv; hsz1, hsz2: HSZ;
    Data: HDDEData; Data1, Data2: DWORD): HDDEData stdcall;
  TFNCallback = PFNCALLBACK;

const
  {$EXTERNALSYM CBR_BLOCK}
  CBR_BLOCK = $FFFFFFFF;

{ DLL registration functions }

{$EXTERNALSYM DdeInitializeA}
function DdeInitializeA(var Inst: Longint; Callback: TFNCallback;
  Cmd, Res: Longint): Longint; stdcall;
{$EXTERNALSYM DdeInitializeW}
function DdeInitializeW(var Inst: Longint; Callback: TFNCallback;
  Cmd, Res: Longint): Longint; stdcall;
{$EXTERNALSYM DdeInitialize}
function DdeInitialize(var Inst: Longint; Callback: TFNCallback;
  Cmd, Res: Longint): Longint; stdcall;

const
  { Callback filter flags for use with standard apps. }

  {$EXTERNALSYM CBF_FAIL_SELFCONNECTIONS}
  CBF_FAIL_SELFCONNECTIONS = $00001000;
  {$EXTERNALSYM CBF_FAIL_CONNECTIONS}
  CBF_FAIL_CONNECTIONS = $00002000;
  {$EXTERNALSYM CBF_FAIL_ADVISES}
  CBF_FAIL_ADVISES = $00004000;
  {$EXTERNALSYM CBF_FAIL_EXECUTES}
  CBF_FAIL_EXECUTES = $00008000;
  {$EXTERNALSYM CBF_FAIL_POKES}
  CBF_FAIL_POKES = $00010000;
  {$EXTERNALSYM CBF_FAIL_REQUESTS}
  CBF_FAIL_REQUESTS = $00020000;
  {$EXTERNALSYM CBF_FAIL_ALLSVRXACTIONS}
  CBF_FAIL_ALLSVRXACTIONS = $0003f000;

  {$EXTERNALSYM CBF_SKIP_CONNECT_CONFIRMS}
  CBF_SKIP_CONNECT_CONFIRMS = $00040000;
  {$EXTERNALSYM CBF_SKIP_REGISTRATIONS}
  CBF_SKIP_REGISTRATIONS = $00080000;
  {$EXTERNALSYM CBF_SKIP_UNREGISTRATIONS}
  CBF_SKIP_UNREGISTRATIONS = $00100000;
  {$EXTERNALSYM CBF_SKIP_DISCONNECTS}
  CBF_SKIP_DISCONNECTS = $00200000;
  {$EXTERNALSYM CBF_SKIP_ALLNOTIFICATIONS}
  CBF_SKIP_ALLNOTIFICATIONS = $003c0000;

  { Application command flags }

  {$EXTERNALSYM APPCMD_CLIENTONLY}
  APPCMD_CLIENTONLY = $00000010;
  {$EXTERNALSYM APPCMD_FILTERINITS}
  APPCMD_FILTERINITS = $00000020;
  {$EXTERNALSYM APPCMD_MASK}
  APPCMD_MASK = $00000FF0;

  { Application classification flags }

  {$EXTERNALSYM APPCLASS_STANDARD}
  APPCLASS_STANDARD = $00000000;
  {$EXTERNALSYM APPCLASS_MASK}
  APPCLASS_MASK = $0000000F;

{$EXTERNALSYM DdeUninitialize}
function DdeUninitialize(Inst: DWORD): BOOL; stdcall;

{ conversation enumeration functions }

{$EXTERNALSYM DdeConnectList}
function DdeConnectList(Inst: DWORD; Service, Topic: HSZ;
  ConvList: HConvList; CC: PConvContext): HConvList; stdcall;
{$EXTERNALSYM DdeQueryNextServer}
function DdeQueryNextServer(ConvList: HConvList; ConvPrev: HConv): HConv; stdcall;
{$EXTERNALSYM DdeDisconnectList}
function DdeDisconnectList(ConvList: HConvList): BOOL; stdcall;

{ conversation control functions }

{$EXTERNALSYM DdeConnect}
function DdeConnect(Inst: DWORD; Service, Topic: HSZ;
  CC: PConvContext): HConv; stdcall;
{$EXTERNALSYM DdeDisconnect}
function DdeDisconnect(Conv: HConv): BOOL; stdcall;
{$EXTERNALSYM DdeReconnect}
function DdeReconnect(Conv: HConv): HConv; stdcall;

{$EXTERNALSYM DdeQueryConvInfo}
function DdeQueryConvInfo(Conv: HConv; Transaction: DWORD;
 ConvInfo: PConvInfo): UINT; stdcall;
{$EXTERNALSYM DdeSetUserHandle}
function DdeSetUserHandle(Conv: HConv; ID, User: DWORD): BOOL; stdcall;

{$EXTERNALSYM DdeAbandonTransaction}
function DdeAbandonTransaction(Inst: DWORD; Conv: HConv;
  Transaction: DWORD): BOOL; stdcall;

{ app server interface functions }

{$EXTERNALSYM DdePostAdvise}
function DdePostAdvise(Inst: DWORD; Topic, Item: HSZ): BOOL; stdcall;
{$EXTERNALSYM DdeEnableCallback}
function DdeEnableCallback(Inst: DWORD; Conv: HConv; Cmd: UINT): BOOL; stdcall;

const
  {$EXTERNALSYM EC_ENABLEALL}
  EC_ENABLEALL = 0;
  {$EXTERNALSYM EC_ENABLEONE}
  EC_ENABLEONE = ST_BLOCKNEXT;
  {$EXTERNALSYM EC_DISABLE}
  EC_DISABLE = ST_BLOCKED;
  {$EXTERNALSYM EC_QUERYWAITING}
  EC_QUERYWAITING = 2;

{$EXTERNALSYM DdeNameService}
function DdeNameService(Inst: DWORD; hsz1, hsz2: HSZ; Cmd: UINT): HDDEData; stdcall;

const
  {$EXTERNALSYM DNS_REGISTER}
  DNS_REGISTER = $0001;
  {$EXTERNALSYM DNS_UNREGISTER}
  DNS_UNREGISTER = $0002;
  {$EXTERNALSYM DNS_FILTERON}
  DNS_FILTERON = $0004;
  {$EXTERNALSYM DNS_FILTEROFF}
  DNS_FILTEROFF = $0008;

{ app client interface functions }

{$EXTERNALSYM DdeClientTransaction}
function DdeClientTransaction(Data: Pointer; DataLen: DWORD;
  Conv: HConv; Item: HSZ; Fmt, DataType: UINT; Timeout: DWORD;
  Result: PDWORD): HDDEData; stdcall;

{ data transfer functions }

{$EXTERNALSYM DdeCreateDataHandle}
function DdeCreateDataHandle(Inst: DWORD; Src: Pointer;
  cb, Off: DWORD; Item: HSZ; Fmt, Cmd: UINT): HDDEData; stdcall;

{$EXTERNALSYM DdeAddData}
function DdeAddData(Data: HDDEData; Src: Pointer;
  cb, Off: DWORD): HDDEData; stdcall;
{$EXTERNALSYM DdeGetData}
function DdeGetData(Data: HDDEData; Dst: Pointer;
  Max, Off: DWORD): DWORD; stdcall;
{$EXTERNALSYM DdeAccessData}
function DdeAccessData(Data: HDDEData; DataSize: PDWORD): Pointer; stdcall;
{$EXTERNALSYM DdeUnaccessData}
function DdeUnaccessData(Data: HDDEData): BOOL; stdcall;
{$EXTERNALSYM DdeFreeDataHandle}
function DdeFreeDataHandle(Data: HDDEData): BOOL; stdcall;

const
  {$EXTERNALSYM HDATA_APPOWNED}
  HDATA_APPOWNED = $0001;

{$EXTERNALSYM DdeGetLastError}
function DdeGetLastError(Inst: DWORD): UINT; stdcall;

const
  { error codes }

  {$EXTERNALSYM DMLERR_NO_ERROR}
  DMLERR_NO_ERROR = 0;       { must be 0 }

  {$EXTERNALSYM DMLERR_FIRST}
  DMLERR_FIRST = $4000;

  {$EXTERNALSYM DMLERR_ADVACKTIMEOUT}
  DMLERR_ADVACKTIMEOUT = $4000;
  {$EXTERNALSYM DMLERR_BUSY}
  DMLERR_BUSY = $4001;
  {$EXTERNALSYM DMLERR_DATAACKTIMEOUT}
  DMLERR_DATAACKTIMEOUT = $4002;
  {$EXTERNALSYM DMLERR_DLL_NOT_INITIALIZED}
  DMLERR_DLL_NOT_INITIALIZED = $4003;
  {$EXTERNALSYM DMLERR_DLL_USAGE}
  DMLERR_DLL_USAGE = $4004;
  {$EXTERNALSYM DMLERR_EXECACKTIMEOUT}
  DMLERR_EXECACKTIMEOUT = $4005;
  {$EXTERNALSYM DMLERR_INVALIDPARAMETER}
  DMLERR_INVALIDPARAMETER = $4006;
  {$EXTERNALSYM DMLERR_LOW_MEMORY}
  DMLERR_LOW_MEMORY = $4007;
  {$EXTERNALSYM DMLERR_MEMORY_ERROR}
  DMLERR_MEMORY_ERROR = $4008;
  {$EXTERNALSYM DMLERR_NOTPROCESSED}
  DMLERR_NOTPROCESSED = $4009;
  {$EXTERNALSYM DMLERR_NO_CONV_ESTABLISHED}
  DMLERR_NO_CONV_ESTABLISHED = $400a;
  {$EXTERNALSYM DMLERR_POKEACKTIMEOUT}
  DMLERR_POKEACKTIMEOUT = $400b;
  {$EXTERNALSYM DMLERR_POSTMSG_FAILED}
  DMLERR_POSTMSG_FAILED = $400c;
  {$EXTERNALSYM DMLERR_REENTRANCY}
  DMLERR_REENTRANCY = $400D;
  {$EXTERNALSYM DMLERR_SERVER_DIED}
  DMLERR_SERVER_DIED = $400E;
  {$EXTERNALSYM DMLERR_SYS_ERROR}
  DMLERR_SYS_ERROR = $400F;
  {$EXTERNALSYM DMLERR_UNADVACKTIMEOUT}
  DMLERR_UNADVACKTIMEOUT = $4010;
  {$EXTERNALSYM DMLERR_UNFOUND_QUEUE_ID}
  DMLERR_UNFOUND_QUEUE_ID = $4011;

  {$EXTERNALSYM DMLERR_LAST}
  DMLERR_LAST = $4011;

{$EXTERNALSYM DdeCreateStringHandleA}
function DdeCreateStringHandleA(Inst: DWORD; psz: PAnsiChar;
  CodePage: Integer): HSZ; stdcall;
{$EXTERNALSYM DdeCreateStringHandleW}
function DdeCreateStringHandleW(Inst: DWORD; psz: PWideChar;
  CodePage: Integer): HSZ; stdcall;
{$EXTERNALSYM DdeCreateStringHandle}
function DdeCreateStringHandle(Inst: DWORD; psz: PChar;
  CodePage: Integer): HSZ; stdcall;
{$EXTERNALSYM DdeQueryStringA}
function DdeQueryStringA(Inst: DWORD; HSZ: HSZ; psz: PAnsiChar;
  Max: DWORD; CodePage: Integer): DWORD; stdcall;
{$EXTERNALSYM DdeQueryStringW}
function DdeQueryStringW(Inst: DWORD; HSZ: HSZ; psz: PWideChar;
  Max: DWORD; CodePage: Integer): DWORD; stdcall;
{$EXTERNALSYM DdeQueryString}
function DdeQueryString(Inst: DWORD; HSZ: HSZ; psz: PChar;
  Max: DWORD; CodePage: Integer): DWORD; stdcall;
{$EXTERNALSYM DdeFreeStringHandle}
function DdeFreeStringHandle(Inst: DWORD; HSZ: HSZ): BOOL; stdcall;
{$EXTERNALSYM DdeKeepStringHandle}
function DdeKeepStringHandle(Inst: DWORD; HSZ: HSZ): BOOL; stdcall;
{$EXTERNALSYM DdeCmpStringHandles}
function DdeCmpStringHandles(hsz1, hsz2: HSZ): Integer; stdcall;

type
  { DDEML public debugging header file info }

  {$EXTERNALSYM tagDDEML_MSG_HOOK_DATA}
  tagDDEML_MSG_HOOK_DATA = packed record  { new for NT }
    uiLo: UINT;      { unpacked lo and hi parts of lParam }
    uiHi: UINT;
    cbData: DWORD;   { amount of data in message, if any. May be > than 32 bytes. }
    Data: array [0..7] of DWORD; { data peeking by DDESPY is limited to 32 bytes. }
  end;
  TDdemlMsgHookData = tagDDEML_MSG_HOOK_DATA;
  {$EXTERNALSYM DDEML_MSG_HOOK_DATA}
  DDEML_MSG_HOOK_DATA = tagDDEML_MSG_HOOK_DATA;

  {$EXTERNALSYM tagMONMSGSTRUCT}
  tagMONMSGSTRUCT = packed record
    cb: UINT;
    hWndTo: HWND;
    dwTime: DWORD;
    hTask: THandle;
    wMsg: UINT;
    wParam: WPARAM;
    lParam: LPARAM;
    dmhd: TDdemlMsgHookData;
  end;
  TMonMsgStruct = tagMONMSGSTRUCT;
  {$EXTERNALSYM MONMSGSTRUCT}
  MONMSGSTRUCT = tagMONMSGSTRUCT;

  {$EXTERNALSYM tagMONCBSTRUCT}
  tagMONCBSTRUCT = packed record
    cb: UINT;
    dwTime: DWORD;
    hTask: THandle;
    dwRet: DWORD;
    wType: UINT;
    wFmt: UINT;
    hConv: HConv;
    hsz1: HSZ;
    hsz2: HSZ;
    hData: HDDEData;
    dwData1: DWORD;
    dwData2: DWORD;
    cc: TConvContext;  { new for NT for XTYP_CONNECT callbacks }
    cbData: DWORD;     { new for NT for data peeking }
    Data: array [0..7] of DWORD; { new for NT for data peeking }
  end;
  TMonCBStruct = tagMONCBSTRUCT;
  {$EXTERNALSYM MONCBSTRUCT}
  MONCBSTRUCT = tagMONCBSTRUCT;

  {$EXTERNALSYM tagMONHSZSTRUCTA}
  tagMONHSZSTRUCTA = record
    cb: UINT;
    fsAction: BOOL;    { mh_ value }
    dwTime: DWORD;
    HSZ: HSZ;
    hTask: THandle;
    wReserved: UINT;
    Str: array[0..0] of AnsiChar;
  end;
  {$EXTERNALSYM tagMONHSZSTRUCTW}
  tagMONHSZSTRUCTW = record
    cb: UINT;
    fsAction: BOOL;    { mh_ value }
    dwTime: DWORD;
    HSZ: HSZ;
    hTask: THandle;
    wReserved: UINT;
    Str: array[0..0] of WideChar;
  end;
  {$EXTERNALSYM tagMONHSZSTRUCT}
  tagMONHSZSTRUCT = tagMONHSZSTRUCTA;
  TMonHSZStructA = tagMONHSZSTRUCTA;
  TMonHSZStructW = tagMONHSZSTRUCTW;
  TMonHSZStruct = TMonHSZStructA;
  {$EXTERNALSYM MONHSZSTRUCTA}
  MONHSZSTRUCTA = tagMONHSZSTRUCTA;
  {$EXTERNALSYM MONHSZSTRUCTW}
  MONHSZSTRUCTW = tagMONHSZSTRUCTW;
  {$EXTERNALSYM MONHSZSTRUCT}
  MONHSZSTRUCT = MONHSZSTRUCTA;

const
  {$EXTERNALSYM MH_CREATE}
  MH_CREATE = 1;
  {$EXTERNALSYM MH_KEEP}
  MH_KEEP = 2;
  {$EXTERNALSYM MH_DELETE}
  MH_DELETE = 3;
  {$EXTERNALSYM MH_CLEANUP}
  MH_CLEANUP = 4;

type
  PMonErrStruct = ^TMonErrStruct;
  {$EXTERNALSYM tagMONERRSTRUCT}
  tagMONERRSTRUCT = packed record
    cb: UINT;
    wLastError: UINT;
    dwTime: DWORD;
    hTask: THandle;
  end;
  TMonErrStruct = tagMONERRSTRUCT;
  {$EXTERNALSYM MONERRSTRUCT}
  MONERRSTRUCT = tagMONERRSTRUCT;

  PMonLinkStruct = ^TMonLinkStruct;
  {$EXTERNALSYM tagMONLINKSTRUCT}
  tagMONLINKSTRUCT = packed record
    cb: UINT;
    dwTime: DWORD;
    hTask: THandle;
    fEstablished: BOOL;
    fNoData: BOOL;
    hszSvc: HSz;
    hszTopic: HSz;
    hszItem: HSz;
    wFmt: UINT;
    fServer: BOOL;
    hConvServer: HConv;
    hConvClient: HConv;
  end;
  TMonLinkStruct = tagMONLINKSTRUCT;
  {$EXTERNALSYM MONLINKSTRUCT}
  MONLINKSTRUCT = tagMONLINKSTRUCT;

  PMonConvStruct = ^TMonConvStruct;
  {$EXTERNALSYM tagMONCONVSTRUCT}
  tagMONCONVSTRUCT = packed record
    cb: UINT;
    fConnect: BOOL;
    dwTime: DWORD;
    hTask: THandle;
    hszSvc: HSz;
    hszTopic: HSz;
    hConvClient: HConv;
    hConvServer: HConv;
  end;
  TMonConvStruct = tagMONCONVSTRUCT;
  {$EXTERNALSYM MONCONVSTRUCT}
  MONCONVSTRUCT = tagMONCONVSTRUCT;

const
  {$EXTERNALSYM MAX_MONITORS}
  MAX_MONITORS = 4;
  {$EXTERNALSYM APPCLASS_MONITOR}
  APPCLASS_MONITOR = 1;
  {$EXTERNALSYM XTYP_MONITOR}
  XTYP_MONITOR = $00F0 or XCLASS_NOTIFICATION or XTYPF_NOBLOCK;

{ Callback filter flags for use with MONITOR apps - 0 implies no monitor
  callbacks. }

const
  {$EXTERNALSYM MF_HSZ_INFO}
  MF_HSZ_INFO = $01000000;
  {$EXTERNALSYM MF_SENDMSGS}
  MF_SENDMSGS = $02000000;
  {$EXTERNALSYM MF_POSTMSGS}
  MF_POSTMSGS = $04000000;
  {$EXTERNALSYM MF_CALLBACKS}
  MF_CALLBACKS = $08000000;
  {$EXTERNALSYM MF_ERRORS}
  MF_ERRORS = $10000000;
  {$EXTERNALSYM MF_LINKS}
  MF_LINKS = $20000000;
  {$EXTERNALSYM MF_CONV}
  MF_CONV = $40000000;


  ddelib = 'user32.dll';

implementation

function DdeInitializeA;         external ddelib name 'DdeInitializeA';
function DdeInitializeW;         external ddelib name 'DdeInitializeW';
function DdeInitialize;         external ddelib name 'DdeInitializeA';
function DdeUninitialize;          external ddelib name 'DdeUninitialize';
function DdeConnectList;           external ddelib name 'DdeConnectList';
function DdeQueryNextServer;       external ddelib name 'DdeQueryNextServer';
function DdeDisconnectList;        external ddelib name 'DdeDisconnectList';
function DdeConnect;               external ddelib name 'DdeConnect';
function DdeDisconnect;            external ddelib name 'DdeDisconnect';
function DdeReconnect;             external ddelib name 'DdeReconnect';
function DdeQueryConvInfo;         external ddelib name 'DdeQueryConvInfo';
function DdeSetUserHandle;         external ddelib name 'DdeSetUserHandle';
function DdeAbandonTransaction;    external ddelib name 'DdeAbandonTransaction';
function DdePostAdvise;            external ddelib name 'DdePostAdvise';
function DdeEnableCallback;        external ddelib name 'DdeEnableCallback';
function DdeNameService;           external ddelib name 'DdeNameService';
function DdeClientTransaction;     external ddelib name 'DdeClientTransaction';
function DdeCreateDataHandle;      external ddelib name 'DdeCreateDataHandle';
function DdeAddData;               external ddelib name 'DdeAddData';
function DdeGetData;               external ddelib name 'DdeGetData';
function DdeAccessData;            external ddelib name 'DdeAccessData';
function DdeUnaccessData;          external ddelib name 'DdeUnaccessData';
function DdeFreeDataHandle;        external ddelib name 'DdeFreeDataHandle';
function DdeGetLastError;          external ddelib name 'DdeGetLastError';
function DdeCreateStringHandleA; external ddelib name 'DdeCreateStringHandleA';
function DdeCreateStringHandleW; external ddelib name 'DdeCreateStringHandleW';
function DdeCreateStringHandle; external ddelib name 'DdeCreateStringHandleA';
function DdeQueryStringA;        external ddelib name 'DdeQueryStringA';
function DdeQueryStringW;        external ddelib name 'DdeQueryStringW';
function DdeQueryString;        external ddelib name 'DdeQueryStringA';
function DdeFreeStringHandle;      external ddelib name 'DdeFreeStringHandle';
function DdeKeepStringHandle;      external ddelib name 'DdeKeepStringHandle';
function DdeCmpStringHandles;      external ddelib name 'DdeCmpStringHandles';

end.
