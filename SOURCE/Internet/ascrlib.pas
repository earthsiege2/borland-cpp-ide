unit AscrLib;         

// PASTLWTR : $Revision:   1.8  $
// File generated on 7/27/00 12:13:00 PM from Type Library described below.

// ************************************************************************ //
// Type Lib: E:\tp\internet\temp.tlb (1)
// IID\LCID: {B1376415-E2EF-11D1-A693-00AA00125A98}\0
// Helpfile: 
// DepndLst: 
//   (1) v2.0 stdole, (C:\WINNT\System32\STDOLE2.TLB)
//   (2) v4.0 StdVCL, (z:\Iliad\Bin\STDVCL40.DLL)
// ************************************************************************ //

{$TYPEDADDRESS OFF} // Unit must be compiled without type-checked pointers. 
interface

uses Windows, ActiveX, Classes, StdVCL;
      
// *********************************************************************//
// GUIDS declared in the TypeLibrary. Following prefixes are used:        
//   Type Libraries     : LIBID_xxxx                                      
//   CoClasses          : CLASS_xxxx                                      
//   DISPInterfaces     : DIID_xxxx                                       
//   Non-DISP interfaces: IID_xxxx                                        
// *********************************************************************//
const
  // TypeLibrary Major and minor versions
  ActiveScriptLibMajorVersion = 1;
  ActiveScriptLibMinorVersion = 0;

  LIBID_ActiveScriptLib: TGUID = '{B1376415-E2EF-11D1-A693-00AA00125A98}';

  IID_IActiveScript: TGUID = '{BB1A2AE1-A4F9-11CF-8F20-00805F2CD064}';
  IID_IActiveScriptSite: TGUID = '{DB01A1E3-A42B-11CF-8F20-00805F2CD064}';
  IID_IActiveScriptError: TGUID = '{EAE1BA61-A4ED-11CF-8F20-00805F2CD064}';
  IID_IActiveScriptParse: TGUID = '{BB1A2AE2-A4F9-11CF-8F20-00805F2CD064}';
  IID_IActiveScriptSiteWindow: TGUID = '{D10F6761-83E9-11CF-8F20-00805F2CD064}';

// *********************************************************************//
// Declaration of Enumerations defined in Type Library                    
// *********************************************************************//
// Constants for enum tagSCRIPTSTATE
type
  tagSCRIPTSTATE = TOleEnum;
const
  SCRIPTSTATE_UNINITIALIZED = $00000000;
  SCRIPTSTATE_INITIALIZED = $00000005;
  SCRIPTSTATE_STARTED = $00000001;
  SCRIPTSTATE_CONNECTED = $00000002;
  SCRIPTSTATE_DISCONNECTED = $00000003;
  SCRIPTSTATE_CLOSED = $00000004;

// Constants for enum tagSCRIPTTHREADSTATE
type
  tagSCRIPTTHREADSTATE = TOleEnum;
const
  SCRIPTTHREADSTATE_NOTINSCRIPT = $00000000;
  SCRIPTTHREADSTATE_RUNNING = $00000001;

// Constants for enum tagSCRIPTINFO
type
  tagSCRIPTINFO = TOleEnum;
const
  SCRIPTINFO_IUNKNOWN = $00000001;
  SCRIPTINFO_ITYPEINFO = $00000002;

// Constants for enum tagSCRIPTITEM
type
  tagSCRIPTITEM = TOleEnum;
const
  SCRIPTITEM_ISVISIBLE = $00000002;
  SCRIPTITEM_ISSOURCE = $00000004;
  SCRIPTITEM_GLOBALMEMBERS = $00000008;
  SCRIPTITEM_ISPERSISTENT = $00000040;
  SCRIPTITEM_CODEONLY = $00000200;
  SCRIPTITEM_NOCODE = $00000400;

type

// *********************************************************************//
// Forward declaration of types defined in TypeLibrary                    
// *********************************************************************//
  IActiveScript = interface;
  IActiveScriptSite = interface;
  IActiveScriptError = interface;
  IActiveScriptParse = interface;
  IActiveScriptSiteWindow = interface;

// *********************************************************************//
// Declaration of structures, unions and aliases.                         
// *********************************************************************//
  // wireHWND = ^Integer;
  wireHWND = hWnd;


// *********************************************************************//
// Interface: IActiveScript
// Flags:     (0)
// GUID:      {BB1A2AE1-A4F9-11CF-8F20-00805F2CD064}
// *********************************************************************//
  IActiveScript = interface(IUnknown)
    ['{BB1A2AE1-A4F9-11CF-8F20-00805F2CD064}']
    function  SetScriptSite {Flags(1), (1/1) CC:4, INV:1, DBG:6}({VT_29:1}const pass: IActiveScriptSite): HResult; stdcall;
    function  GetScriptSite {Flags(1), (2/2) CC:4, INV:1, DBG:6}({VT_29:1}var riid: TGUID; 
                                                                 {VT_24:2}out ppvObject: Pointer): HResult; stdcall;
    function  SetScriptState {Flags(1), (1/1) CC:4, INV:1, DBG:6}({VT_29:0}ss: tagSCRIPTSTATE): HResult; stdcall;
    function  GetScriptState {Flags(1), (1/1) CC:4, INV:1, DBG:6}({VT_29:1}out pssState: tagSCRIPTSTATE): HResult; stdcall;
    function  Close {Flags(1), (0/0) CC:4, INV:1, DBG:6}: HResult; stdcall;
    function  AddNamedItem {Flags(1), (2/2) CC:4, INV:1, DBG:6}({VT_31:0}pstrName: PWideChar; 
                                                                {VT_19:0}dwFlags: LongWord): HResult; stdcall;
    function  AddTypeLib {Flags(1), (4/4) CC:4, INV:1, DBG:6}({VT_29:1}var rguidTypeLib: TGUID; 
                                                              {VT_19:0}dwMajor: LongWord; 
                                                              {VT_19:0}dwMinor: LongWord; 
                                                              {VT_19:0}dwFlags: LongWord): HResult; stdcall;
    function  GetScriptDispatch {Flags(1), (2/2) CC:4, INV:1, DBG:6}({VT_31:0}pstrItemName: PWideChar; 
                                                                     {VT_9:1}out ppdisp: IDispatch): HResult; stdcall;
    function  GetCurrentScriptThreadID {Flags(1), (1/1) CC:4, INV:1, DBG:6}({VT_19:1}out pstidThread: LongWord): HResult; stdcall;
    function  GetScriptThreadID {Flags(1), (2/2) CC:4, INV:1, DBG:6}({VT_19:0}dwWin32ThreadId: LongWord; 
                                                                     {VT_19:1}out pstidThread: LongWord): HResult; stdcall;
    function  GetScriptThreadState {Flags(1), (2/2) CC:4, INV:1, DBG:6}({VT_19:0}stidThread: LongWord; 
                                                                        {VT_29:1}out pstsState: tagSCRIPTTHREADSTATE): HResult; stdcall;
    function  InterruptScriptThread {Flags(1), (3/3) CC:4, INV:1, DBG:6}({VT_19:0}stidThread: LongWord; 
                                                                         {VT_29:1}var pexcepinfo: EXCEPINFO; 
                                                                         {VT_19:0}dwFlags: LongWord): HResult; stdcall;
    function  Clone {Flags(1), (1/1) CC:4, INV:1, DBG:6}({VT_29:2}out ppscript: IActiveScript): HResult; stdcall;
  end;

// *********************************************************************//
// Interface: IActiveScriptSite
// Flags:     (0)
// GUID:      {DB01A1E3-A42B-11CF-8F20-00805F2CD064}
// *********************************************************************//
  IActiveScriptSite = interface(IUnknown)
    ['{DB01A1E3-A42B-11CF-8F20-00805F2CD064}']
    function  GetLCID {Flags(1), (1/1) CC:4, INV:1, DBG:6}({VT_19:1}out plcid: LongWord): HResult; stdcall;
    function  GetItemInfo {Flags(1), (4/4) CC:4, INV:1, DBG:6}({VT_31:0}pstrName: PWideChar;
                                                               {VT_19:0}dwReturnMask: LongWord;
                                                               {VT_13:1}out ppiunkItem: IUnknown;
                                                               {VT_29:2}out ppti: IUnknown): HResult; stdcall;
    function  GetDocVersionString {Flags(1), (1/1) CC:4, INV:1, DBG:6}({VT_8:1}out pbstrVersion: WideString): HResult; stdcall;
    function  OnScriptTerminate {Flags(1), (2/2) CC:4, INV:1, DBG:6}({VT_12:1}var pvarResult: OleVariant; 
                                                                     {VT_3:1}var pexcepinfo: EXCEPINFO): HResult; stdcall;
    function  OnStateChange {Flags(1), (1/1) CC:4, INV:1, DBG:6}({VT_29:0}ssScriptState: tagSCRIPTSTATE): HResult; stdcall;
    function  OnScriptError {Flags(1), (1/1) CC:4, INV:1, DBG:6}({VT_29:1}const pscripterror: IActiveScriptError): HResult; stdcall;
    function  OnEnterScript {Flags(1), (0/0) CC:4, INV:1, DBG:6}: HResult; stdcall;
    function  OnLeaveScript {Flags(1), (0/0) CC:4, INV:1, DBG:6}: HResult; stdcall;
  end;

// *********************************************************************//
// Interface: IActiveScriptError
// Flags:     (0)
// GUID:      {EAE1BA61-A4ED-11CF-8F20-00805F2CD064}
// *********************************************************************//
  IActiveScriptError = interface(IUnknown)
    ['{EAE1BA61-A4ED-11CF-8F20-00805F2CD064}']
    function  GetExceptionInfo {Flags(1), (1/1) CC:4, INV:1, DBG:6}({VT_24:1}out pexcepinfo: EXCEPINFO): HResult; stdcall;
    function  GetSourcePosition {Flags(1), (3/3) CC:4, INV:1, DBG:6}({VT_19:1}out pdwSourceContext: LongWord; 
                                                                     {VT_19:1}out pulLineNumber: LongWord; 
                                                                     {VT_3:1}out plCharacterPosition: Integer): HResult; stdcall;
    function  GetSourceLineText {Flags(1), (1/1) CC:4, INV:1, DBG:6}({VT_8:1}out pbstrSourceLine: WideString): HResult; stdcall;
  end;

// *********************************************************************//
// Interface: IActiveScriptParse
// Flags:     (0)
// GUID:      {BB1A2AE2-A4F9-11CF-8F20-00805F2CD064}
// *********************************************************************//
  IActiveScriptParse = interface(IUnknown)
    ['{BB1A2AE2-A4F9-11CF-8F20-00805F2CD064}']
    function  InitNew {Flags(1), (0/0) CC:4, INV:1, DBG:6}: HResult; stdcall;
    function  AddScriptlet {Flags(1), (11/11) CC:4, INV:1, DBG:6}({VT_31:0}pstrDefaultName: PWideChar; 
                                                                  {VT_31:0}pstrCode: PWideChar; 
                                                                  {VT_31:0}pstrItemName: PWideChar; 
                                                                  {VT_31:0}pstrSubItemName: PWideChar;
                                                                  {VT_31:0}pstrEventName: PWideChar; 
                                                                  {VT_31:0}pstrDelimiter: PWideChar; 
                                                                  {VT_19:0}dwSourceContextCookie: LongWord; 
                                                                  {VT_19:0}ulStartingLineNumber: LongWord; 
                                                                  {VT_19:0}dwFlags: LongWord; 
                                                                  {VT_8:1}out pBstrName: WideString; 
                                                                  {VT_29:1}out pexcepinfo: TGUID): HResult; stdcall;
    function  ParseScriptText {Flags(1), (9/9) CC:4, INV:1, DBG:6}({VT_31:0}pstrCode: PWideChar;
                                                                   {VT_31:0}pstrItemName: PWideChar;
                                                                   {VT_13:0}const punkContext: IUnknown;
                                                                   {VT_31:0}pstrDelimiter: PWideChar;
                                                                   {VT_19:0}dwSourceContextCookie: LongWord;
                                                                   {VT_19:0}ulStartingLineNumber: LongWord;
                                                                   {VT_19:0}dwFlags: LongWord;
                                                                   {VT_12:1}pvarResult: Pointer;
                                                                   {VT_29:1}out pexcepinfo: EXCEPINFO): HResult; stdcall;
  end;

// *********************************************************************//
// Interface: IActiveScriptSiteWindow
// Flags:     (0)
// GUID:      {D10F6761-83E9-11CF-8F20-00805F2CD064}
// *********************************************************************//
  IActiveScriptSiteWindow = interface(IUnknown)
    ['{D10F6761-83E9-11CF-8F20-00805F2CD064}']
    function  GetWindow {Flags(1), (1/1) CC:4, INV:1, DBG:6}({VT_3:2}out phwnd: wireHWND): HResult; stdcall;
    function  EnableModeless {Flags(1), (1/1) CC:4, INV:1, DBG:6}({VT_3:0}fEnable: Integer): HResult; stdcall;
  end;

implementation

uses ComObj;

end.
