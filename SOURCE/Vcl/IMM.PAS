
{*******************************************************}
{                                                       }
{       Borland Delphi Run-time Library                 }
{       Win32 IMM API Interface Unit                    }
{                                                       }
{       Copyright (c) 1985-1999, Microsoft Corporation  }
{                                                       }
{       Translator: Inprise Corporation                 }
{                                                       }
{*******************************************************}

unit Imm;

{$ALIGN ON}
{$MINENUMSIZE 4}
{$WEAKPACKAGEUNIT}

interface

uses Windows;

const
  {$EXTERNALSYM VK_PROCESSKEY}
  VK_PROCESSKEY = $E5;

type
  {$EXTERNALSYM HIMC}
  HIMC = Integer;

  PCompositionForm = ^TCompositionForm;
  {$EXTERNALSYM tagCOMPOSITIONFORM}
  tagCOMPOSITIONFORM = record
    dwStyle: DWORD;
    ptCurrentPos: TPOINT;
    rcArea: TRECT;
  end;
  TCompositionForm = tagCOMPOSITIONFORM;
  {$EXTERNALSYM COMPOSITIONFORM}
  COMPOSITIONFORM = tagCOMPOSITIONFORM;

  PCandidateForm = ^TCandidateForm;
  {$EXTERNALSYM tagCANDIDATEFORM}
  tagCANDIDATEFORM = record
    dwIndex: DWORD;
    dwStyle: DWORD;
    ptCurrentPos: TPOINT;
    rcArea: TRECT;
  end;
  TCandidateForm = tagCANDIDATEFORM;
  {$EXTERNALSYM CANDIDATEFORM}
  CANDIDATEFORM = tagCANDIDATEFORM;

  PCandidateList = ^TCandidateList;
  {$EXTERNALSYM tagCANDIDATELIST}
  tagCANDIDATELIST = record
    dwSize: DWORD;
    dwStyle: DWORD;
    dwCount: DWORD;
    dwSelection: DWORD;
    dwPageStart: DWORD;
    dwPageSize: DWORD;
    dwOffset: array[1..1] of DWORD;
  end;
  TCandidateList = tagCANDIDATELIST;
  {$EXTERNALSYM CANDIDATELIST}
  CANDIDATELIST = tagCANDIDATELIST;

  PRegisterWordA = ^TRegisterWordA;
  PRegisterWordW = ^TRegisterWordW;
  PRegisterWord = PRegisterWordA;
  {$EXTERNALSYM tagREGISTERWORDA}
  tagREGISTERWORDA = record
    lpReading: PAnsiChar;
    lpWord: PAnsiChar;
  end;
  {$EXTERNALSYM tagREGISTERWORDW}
  tagREGISTERWORDW = record
    lpReading: PWideChar;
    lpWord: PWideChar;
  end;
  {$EXTERNALSYM tagREGISTERWORD}
  tagREGISTERWORD = tagREGISTERWORDA;
  TRegisterWordA = tagREGISTERWORDA;
  TRegisterWordW = tagREGISTERWORDW;
  TRegisterWord = TRegisterWordA;
  {$EXTERNALSYM REGISTERWORDA}
  REGISTERWORDA = tagREGISTERWORDA;
  {$EXTERNALSYM REGISTERWORDW}
  REGISTERWORDW = tagREGISTERWORDW;
  {$EXTERNALSYM REGISTERWORD}
  REGISTERWORD = REGISTERWORDA;

const 
  {$EXTERNALSYM STYLE_DESCRIPTION_SIZE}
  STYLE_DESCRIPTION_SIZE = 32;

type
  PStyleBufA = ^TStyleBufA;
  PStyleBufW = ^TStyleBufW;
  PStyleBuf = PStyleBufA;
  {$EXTERNALSYM tagSTYLEBUFA}
  tagSTYLEBUFA = record
    dwStyle: DWORD;
    szDescription: array[0..STYLE_DESCRIPTION_SIZE-1] of AnsiChar; 
  end;
  {$EXTERNALSYM tagSTYLEBUFW}
  tagSTYLEBUFW = record
    dwStyle: DWORD;
    szDescription: array[0..STYLE_DESCRIPTION_SIZE-1] of WideChar; 
  end;
  {$EXTERNALSYM tagSTYLEBUF}
  tagSTYLEBUF = tagSTYLEBUFA;
  TStyleBufA = tagSTYLEBUFA;
  TStyleBufW = tagSTYLEBUFW;
  TStyleBuf = TStyleBufA;
  {$EXTERNALSYM STYLEBUFA}
  STYLEBUFA = tagSTYLEBUFA;
  {$EXTERNALSYM STYLEBUFW}
  STYLEBUFW = tagSTYLEBUFW;
  {$EXTERNALSYM STYLEBUF}
  STYLEBUF = STYLEBUFA;

{ prototype of IMM API }

{$EXTERNALSYM ImmInstallIMEA}
function ImmInstallIMEA(lpszIMEFileName, lpszLayoutText: PAnsiChar): HKL; stdcall;
{$EXTERNALSYM ImmInstallIMEW}
function ImmInstallIMEW(lpszIMEFileName, lpszLayoutText: PWideChar): HKL; stdcall;
{$EXTERNALSYM ImmInstallIME}
function ImmInstallIME(lpszIMEFileName, lpszLayoutText: PChar): HKL; stdcall;

{$EXTERNALSYM ImmGetDefaultIMEWnd}
function ImmGetDefaultIMEWnd(hWnd: HWND): HWND; stdcall;

{$EXTERNALSYM ImmGetDescriptionA}
function ImmGetDescriptionA(hKl: HKL; PAnsiChar: PAnsiChar; uBufLen: UINT): UINT; stdcall;
{$EXTERNALSYM ImmGetDescriptionW}
function ImmGetDescriptionW(hKl: HKL; PWideChar: PWideChar; uBufLen: UINT): UINT; stdcall;
{$EXTERNALSYM ImmGetDescription}
function ImmGetDescription(hKl: HKL; PChar: PChar; uBufLen: UINT): UINT; stdcall;

{$EXTERNALSYM ImmGetIMEFileNameA}
function ImmGetIMEFileNameA(hKl: HKL; PAnsiChar: PAnsiChar; uBufLen: UINT): UINT; stdcall;
{$EXTERNALSYM ImmGetIMEFileNameW}
function ImmGetIMEFileNameW(hKl: HKL; PWideChar: PWideChar; uBufLen: UINT): UINT; stdcall;
{$EXTERNALSYM ImmGetIMEFileName}
function ImmGetIMEFileName(hKl: HKL; PChar: PChar; uBufLen: UINT): UINT; stdcall;

{$EXTERNALSYM ImmGetProperty}
function ImmGetProperty(hKl: HKL; dWord: DWORD): DWORD; stdcall;

{$EXTERNALSYM ImmIsIME}
function ImmIsIME(hKl: HKL): Boolean; stdcall;

{$EXTERNALSYM ImmSimulateHotKey}
function ImmSimulateHotKey(hWnd: HWND; dWord: DWORD): Boolean; stdcall;

{$EXTERNALSYM ImmCreateContext}
function ImmCreateContext: HIMC; stdcall;
{$EXTERNALSYM ImmDestroyContext}
function ImmDestroyContext(hImc: HIMC): Boolean; stdcall;
{$EXTERNALSYM ImmGetContext}
function ImmGetContext(hWnd: HWND): HIMC; stdcall;
{$EXTERNALSYM ImmReleaseContext}
function ImmReleaseContext(hWnd: HWND; hImc: HIMC): Boolean; stdcall;
{$EXTERNALSYM ImmAssociateContext}
function ImmAssociateContext(hWnd: HWND; hImc: HIMC): HIMC; stdcall;

{$EXTERNALSYM ImmGetCompositionStringA}
function ImmGetCompositionStringA(hImc: HIMC; dWord1: DWORD; lpBuf: pointer; dwBufLen: DWORD): Longint; stdcall;
{$EXTERNALSYM ImmGetCompositionStringW}
function ImmGetCompositionStringW(hImc: HIMC; dWord1: DWORD; lpBuf: pointer; dwBufLen: DWORD): Longint; stdcall;
{$EXTERNALSYM ImmGetCompositionString}
function ImmGetCompositionString(hImc: HIMC; dWord1: DWORD; lpBuf: pointer; dwBufLen: DWORD): Longint; stdcall;

{$EXTERNALSYM ImmSetCompositionStringA}
function ImmSetCompositionStringA(hImc: HIMC; dwIndex: DWORD; lpComp: pointer; dwCompLen: DWORD; lpRead: pointer; dwReadLen: DWORD):Boolean; stdcall;
{$EXTERNALSYM ImmSetCompositionStringW}
function ImmSetCompositionStringW(hImc: HIMC; dwIndex: DWORD; lpComp: pointer; dwCompLen: DWORD; lpRead: pointer; dwReadLen: DWORD):Boolean; stdcall;
{$EXTERNALSYM ImmSetCompositionString}
function ImmSetCompositionString(hImc: HIMC; dwIndex: DWORD; lpComp: pointer; dwCompLen: DWORD; lpRead: pointer; dwReadLen: DWORD):Boolean; stdcall;

{$EXTERNALSYM ImmGetCandidateListCountA}
function ImmGetCandidateListCountA(hImc: HIMC; var ListCount: DWORD): DWORD; stdcall;
{$EXTERNALSYM ImmGetCandidateListCountW}
function ImmGetCandidateListCountW(hImc: HIMC; var ListCount: DWORD): DWORD; stdcall;
{$EXTERNALSYM ImmGetCandidateListCount}
function ImmGetCandidateListCount(hImc: HIMC; var ListCount: DWORD): DWORD; stdcall;

{$EXTERNALSYM ImmGetCandidateListA}
function ImmGetCandidateListA(hImc: HIMC; deIndex: DWORD; lpCandidateList: PCANDIDATELIST; dwBufLen: DWORD): DWORD; stdcall;
{$EXTERNALSYM ImmGetCandidateListW}
function ImmGetCandidateListW(hImc: HIMC; deIndex: DWORD; lpCandidateList: PCANDIDATELIST; dwBufLen: DWORD): DWORD; stdcall;
{$EXTERNALSYM ImmGetCandidateList}
function ImmGetCandidateList(hImc: HIMC; deIndex: DWORD; lpCandidateList: PCANDIDATELIST; dwBufLen: DWORD): DWORD; stdcall;

{$EXTERNALSYM ImmGetGuideLineA}
function ImmGetGuideLineA(hImc: HIMC; dwIndex: DWORD; lpBuf: PAnsiChar; dwBufLen: DWORD): DWORD; stdcall;
{$EXTERNALSYM ImmGetGuideLineW}
function ImmGetGuideLineW(hImc: HIMC; dwIndex: DWORD; lpBuf: PWideChar; dwBufLen: DWORD): DWORD; stdcall;
{$EXTERNALSYM ImmGetGuideLine}
function ImmGetGuideLine(hImc: HIMC; dwIndex: DWORD; lpBuf: PChar; dwBufLen: DWORD): DWORD; stdcall;

{$EXTERNALSYM ImmGetConversionStatus}
function ImmGetConversionStatus(hImc: HIMC; var Conversion, Sentence: DWORD): Boolean; stdcall;
{$EXTERNALSYM ImmSetConversionStatus}
function ImmSetConversionStatus(hImc: HIMC; Conversion, Sentence: DWORD): Boolean; stdcall;
{$EXTERNALSYM ImmGetOpenStatus}
function ImmGetOpenStatus(hImc: HIMC): Boolean; stdcall;
{$EXTERNALSYM ImmSetOpenStatus}
function ImmSetOpenStatus(hImc: HIMC; fOpen: Boolean): Boolean; stdcall;

{$EXTERNALSYM ImmGetCompositionFontA}
function ImmGetCompositionFontA(hImc: HIMC; lpLogfont: PLOGFONTA): Boolean; stdcall;
{$EXTERNALSYM ImmGetCompositionFontW}
function ImmGetCompositionFontW(hImc: HIMC; lpLogfont: PLOGFONTW): Boolean; stdcall;
{$EXTERNALSYM ImmGetCompositionFont}
function ImmGetCompositionFont(hImc: HIMC; lpLogfont: PLOGFONT): Boolean; stdcall;

{$EXTERNALSYM ImmSetCompositionFontA}
function ImmSetCompositionFontA(hImc: HIMC; lpLogfont: PLOGFONTA): Boolean; stdcall;
{$EXTERNALSYM ImmSetCompositionFontW}
function ImmSetCompositionFontW(hImc: HIMC; lpLogfont: PLOGFONTW): Boolean; stdcall;
{$EXTERNALSYM ImmSetCompositionFont}
function ImmSetCompositionFont(hImc: HIMC; lpLogfont: PLOGFONT): Boolean; stdcall;

{$EXTERNALSYM ImmConfigureIMEA}
function ImmConfigureIMEA(hKl: HKL; hWnd: HWND; dwMode: DWORD; lpData: pointer): Boolean; stdcall;
{$EXTERNALSYM ImmConfigureIMEW}
function ImmConfigureIMEW(hKl: HKL; hWnd: HWND; dwMode: DWORD; lpData: pointer): Boolean; stdcall;
{$EXTERNALSYM ImmConfigureIME}
function ImmConfigureIME(hKl: HKL; hWnd: HWND; dwMode: DWORD; lpData: pointer): Boolean; stdcall;

{$EXTERNALSYM ImmEscapeA}
function ImmEscapeA(hKl: HKL; hImc: HIMC; uEscape: UINT; lpData: pointer): LRESULT; stdcall;
{$EXTERNALSYM ImmEscapeW}
function ImmEscapeW(hKl: HKL; hImc: HIMC; uEscape: UINT; lpData: pointer): LRESULT; stdcall;
{$EXTERNALSYM ImmEscape}
function ImmEscape(hKl: HKL; hImc: HIMC; uEscape: UINT; lpData: pointer): LRESULT; stdcall;

{$EXTERNALSYM ImmGetConversionListA}
function ImmGetConversionListA(hKl: HKL; hImc: HIMC; lpSrc: PAnsiChar; lpDst: PCANDIDATELIST; dwBufLen: DWORD; uFlag: UINT ): DWORD; stdcall;
{$EXTERNALSYM ImmGetConversionListW}
function ImmGetConversionListW(hKl: HKL; hImc: HIMC; lpSrc: PWideChar; lpDst: PCANDIDATELIST; dwBufLen: DWORD; uFlag: UINT ): DWORD; stdcall;
{$EXTERNALSYM ImmGetConversionList}
function ImmGetConversionList(hKl: HKL; hImc: HIMC; lpSrc: PChar; lpDst: PCANDIDATELIST; dwBufLen: DWORD; uFlag: UINT ): DWORD; stdcall;

{$EXTERNALSYM ImmNotifyIME}
function ImmNotifyIME(hImc: HIMC; dwAction, dwIndex, dwValue: DWORD): Boolean; stdcall;

{$EXTERNALSYM ImmGetStatusWindowPos}
function ImmGetStatusWindowPos(hImc: HIMC; var lpPoint : TPoint): Boolean; stdcall;
{$EXTERNALSYM ImmSetStatusWindowPos}
function ImmSetStatusWindowPos(hImc: HIMC; lpPoint: PPOINT): Boolean; stdcall;
{$EXTERNALSYM ImmGetCompositionWindow}
function ImmGetCompositionWindow(hImc: HIMC; lpCompForm: PCOMPOSITIONFORM): Boolean; stdcall;
{$EXTERNALSYM ImmSetCompositionWindow}
function ImmSetCompositionWindow(hImc: HIMC; lpCompForm: PCOMPOSITIONFORM): Boolean; stdcall;
{$EXTERNALSYM ImmGetCandidateWindow}
function ImmGetCandidateWindow(hImc: HIMC; dwBufLen: DWORD; lpCandidate: PCANDIDATEFORM): Boolean; stdcall;
{$EXTERNALSYM ImmSetCandidateWindow}
function ImmSetCandidateWindow(hImc: HIMC; lpCandidate: PCANDIDATEFORM): Boolean; stdcall;

{$EXTERNALSYM ImmIsUIMessageA}
function ImmIsUIMessageA(hWnd: HWND; msg: UINT; wParam: WPARAM; lParam: LPARAM): Boolean; stdcall;
{$EXTERNALSYM ImmIsUIMessageW}
function ImmIsUIMessageW(hWnd: HWND; msg: UINT; wParam: WPARAM; lParam: LPARAM): Boolean; stdcall;
{$EXTERNALSYM ImmIsUIMessage}
function ImmIsUIMessage(hWnd: HWND; msg: UINT; wParam: WPARAM; lParam: LPARAM): Boolean; stdcall;

{$EXTERNALSYM ImmGetVirtualKey}
function ImmGetVirtualKey(hWnd: HWND): UINT; stdcall;

type
  RegisterWordEnumProcA = Function(lpReading: PAnsiChar; dwStyle: DWORD; lpszString: PAnsiChar; lpData: pointer): integer;
  {$EXTERNALSYM RegisterWordEnumProcA}
  RegisterWordEnumProcW = Function(lpReading: PWideChar; dwStyle: DWORD; lpszString: PWideChar; lpData: pointer): integer;
  {$EXTERNALSYM RegisterWordEnumProcW}
  RegisterWordEnumProc = RegisterWordEnumProcA;

{$EXTERNALSYM ImmRegisterWordA}
function ImmRegisterWordA(hKl: HKL; lpszReading: PAnsiChar; dwStyle: DWORD; lpszRegister: PAnsiChar): Boolean; stdcall;
{$EXTERNALSYM ImmRegisterWordW}
function ImmRegisterWordW(hKl: HKL; lpszReading: PWideChar; dwStyle: DWORD; lpszRegister: PWideChar): Boolean; stdcall;
{$EXTERNALSYM ImmRegisterWord}
function ImmRegisterWord(hKl: HKL; lpszReading: PChar; dwStyle: DWORD; lpszRegister: PChar): Boolean; stdcall;

{$EXTERNALSYM ImmUnregisterWordA}
function ImmUnregisterWordA(hKl: HKL; lpszReading: PAnsiChar; dwStyle: DWORD; lpszUnregister: PAnsiChar): Boolean; stdcall;
{$EXTERNALSYM ImmUnregisterWordW}
function ImmUnregisterWordW(hKl: HKL; lpszReading: PWideChar; dwStyle: DWORD; lpszUnregister: PWideChar): Boolean; stdcall;
{$EXTERNALSYM ImmUnregisterWord}
function ImmUnregisterWord(hKl: HKL; lpszReading: PChar; dwStyle: DWORD; lpszUnregister: PChar): Boolean; stdcall;

{$EXTERNALSYM ImmGetRegisterWordStyleA}
function ImmGetRegisterWordStyleA(hKl: HKL; nItem: UINT; lpStyleBuf: PSTYLEBUFA): UINT; stdcall;
{$EXTERNALSYM ImmGetRegisterWordStyleW}
function ImmGetRegisterWordStyleW(hKl: HKL; nItem: UINT; lpStyleBuf: PSTYLEBUFW): UINT; stdcall;
{$EXTERNALSYM ImmGetRegisterWordStyle}
function ImmGetRegisterWordStyle(hKl: HKL; nItem: UINT; lpStyleBuf: PSTYLEBUF): UINT; stdcall;

{$EXTERNALSYM ImmEnumRegisterWordA}
function ImmEnumRegisterWordA(hKl: HKL; lpfnEnumProc: REGISTERWORDENUMPROCA; lpszReading: PAnsiChar; dwStyle: DWORD; lpszRegister: PAnsiChar; lpData : pointer): UINT; stdcall;
{$EXTERNALSYM ImmEnumRegisterWordW}
function ImmEnumRegisterWordW(hKl: HKL; lpfnEnumProc: REGISTERWORDENUMPROCW; lpszReading: PWideChar; dwStyle: DWORD; lpszRegister: PWideChar; lpData : pointer): UINT; stdcall;
{$EXTERNALSYM ImmEnumRegisterWord}
function ImmEnumRegisterWord(hKl: HKL; lpfnEnumProc: REGISTERWORDENUMPROC; lpszReading: PChar; dwStyle: DWORD; lpszRegister: PChar; lpData : pointer): UINT; stdcall;

const
{ the IME related messages  ( removed in 4.0 SDK }
  {$EXTERNALSYM WM_CONVERTREQUESTEX}
  WM_CONVERTREQUESTEX            = $0108;
  {$EXTERNALSYM WM_IME_STARTCOMPOSITION}
  WM_IME_STARTCOMPOSITION        = $010D;
  {$EXTERNALSYM WM_IME_ENDCOMPOSITION}
  WM_IME_ENDCOMPOSITION          = $010E;
  {$EXTERNALSYM WM_IME_COMPOSITION}
  WM_IME_COMPOSITION             = $010F;
  {$EXTERNALSYM WM_IME_KEYLAST}
  WM_IME_KEYLAST                 = $010F;

  {$EXTERNALSYM WM_IME_SETCONTEXT}
  WM_IME_SETCONTEXT              = $0281;
  {$EXTERNALSYM WM_IME_NOTIFY}
  WM_IME_NOTIFY                  = $0282;
  {$EXTERNALSYM WM_IME_CONTROL}
  WM_IME_CONTROL                 = $0283;
  {$EXTERNALSYM WM_IME_COMPOSITIONFULL}
  WM_IME_COMPOSITIONFULL         = $0284;
  {$EXTERNALSYM WM_IME_SELECT}
  WM_IME_SELECT                  = $0285;
  {$EXTERNALSYM WM_IME_CHAR}
  WM_IME_CHAR                    = $0286;

  {$EXTERNALSYM WM_IME_KEYDOWN}
  WM_IME_KEYDOWN                 = $0290;
  {$EXTERNALSYM WM_IME_KEYUP}
  WM_IME_KEYUP                   = $0291;

{ wParam for WM_IME_CONTROL }
  {$EXTERNALSYM IMC_GETCANDIDATEPOS}
  IMC_GETCANDIDATEPOS            = $0007;
  {$EXTERNALSYM IMC_SETCANDIDATEPOS}
  IMC_SETCANDIDATEPOS            = $0008;
  {$EXTERNALSYM IMC_GETCOMPOSITIONFONT}
  IMC_GETCOMPOSITIONFONT         = $0009;
  {$EXTERNALSYM IMC_SETCOMPOSITIONFONT}
  IMC_SETCOMPOSITIONFONT         = $000A;
  {$EXTERNALSYM IMC_GETCOMPOSITIONWINDOW}
  IMC_GETCOMPOSITIONWINDOW       = $000B;
  {$EXTERNALSYM IMC_SETCOMPOSITIONWINDOW}
  IMC_SETCOMPOSITIONWINDOW       = $000C;
  {$EXTERNALSYM IMC_GETSTATUSWINDOWPOS}
  IMC_GETSTATUSWINDOWPOS         = $000F;
  {$EXTERNALSYM IMC_SETSTATUSWINDOWPOS}
  IMC_SETSTATUSWINDOWPOS         = $0010;
  {$EXTERNALSYM IMC_CLOSESTATUSWINDOW}
  IMC_CLOSESTATUSWINDOW          = $0021;
  {$EXTERNALSYM IMC_OPENSTATUSWINDOW}
  IMC_OPENSTATUSWINDOW           = $0022;

{ wParam for WM_IME_CONTROL to the soft keyboard }
{ dwAction for ImmNotifyIME }
  {$EXTERNALSYM NI_OPENCANDIDATE}
  NI_OPENCANDIDATE               = $0010;
  {$EXTERNALSYM NI_CLOSECANDIDATE}
  NI_CLOSECANDIDATE              = $0011;
  {$EXTERNALSYM NI_SELECTCANDIDATESTR}
  NI_SELECTCANDIDATESTR          = $0012;
  {$EXTERNALSYM NI_CHANGECANDIDATELIST}
  NI_CHANGECANDIDATELIST         = $0013;
  {$EXTERNALSYM NI_FINALIZECONVERSIONRESULT}
  NI_FINALIZECONVERSIONRESULT    = $0014;
  {$EXTERNALSYM NI_COMPOSITIONSTR}
  NI_COMPOSITIONSTR              = $0015;
  {$EXTERNALSYM NI_SETCANDIDATE_PAGESTART}
  NI_SETCANDIDATE_PAGESTART      = $0016;
  {$EXTERNALSYM NI_SETCANDIDATE_PAGESIZE}
  NI_SETCANDIDATE_PAGESIZE       = $0017;

{ lParam for WM_IME_SETCONTEXT }
  {$EXTERNALSYM ISC_SHOWUICANDIDATEWINDOW}
  ISC_SHOWUICANDIDATEWINDOW      = $00000001;
  {$EXTERNALSYM ISC_SHOWUICOMPOSITIONWINDOW}
  ISC_SHOWUICOMPOSITIONWINDOW    = $80000000;
  {$EXTERNALSYM ISC_SHOWUIGUIDELINE}
  ISC_SHOWUIGUIDELINE            = $40000000;
  {$EXTERNALSYM ISC_SHOWUIALLCANDIDATEWINDOW}
  ISC_SHOWUIALLCANDIDATEWINDOW   = $0000000F;
  {$EXTERNALSYM ISC_SHOWUIALL}
  ISC_SHOWUIALL                  = $C000000F;

{ dwIndex for ImmNotifyIME/NI_COMPOSITIONSTR }
  {$EXTERNALSYM CPS_COMPLETE}
  CPS_COMPLETE                   = $0001;
  {$EXTERNALSYM CPS_CONVERT}
  CPS_CONVERT                    = $0002;
  {$EXTERNALSYM CPS_REVERT}
  CPS_REVERT                     = $0003;
  {$EXTERNALSYM CPS_CANCEL}
  CPS_CANCEL                     = $0004;

{ the modifiers of hot key }
  {$EXTERNALSYM MOD_ALT}
  MOD_ALT                        = $0001;
  {$EXTERNALSYM MOD_CONTROL}
  MOD_CONTROL                    = $0002;
  {$EXTERNALSYM MOD_SHIFT}
  MOD_SHIFT                      = $0004;

  {$EXTERNALSYM MOD_LEFT}
  MOD_LEFT                       = $8000;
  {$EXTERNALSYM MOD_RIGHT}
  MOD_RIGHT                      = $4000;

  {$EXTERNALSYM MOD_ON_KEYUP}
  MOD_ON_KEYUP                   = $0800;
  {$EXTERNALSYM MOD_IGNORE_ALL_MODIFIER}
  MOD_IGNORE_ALL_MODIFIER        = $0400;

{ Windows for Simplified Chinese Edition hot key ID from #10 - #2F }
  {$EXTERNALSYM IME_CHOTKEY_IME_NONIME_TOGGLE}
  IME_CHOTKEY_IME_NONIME_TOGGLE          = $10;
  {$EXTERNALSYM IME_CHOTKEY_SHAPE_TOGGLE}
  IME_CHOTKEY_SHAPE_TOGGLE               = $11;
  {$EXTERNALSYM IME_CHOTKEY_SYMBOL_TOGGLE}
  IME_CHOTKEY_SYMBOL_TOGGLE              = $12;

{ Windows for Japanese Edition hot key ID from #30 - #4F }
  {$EXTERNALSYM IME_JHOTKEY_CLOSE_OPEN}
  IME_JHOTKEY_CLOSE_OPEN                 = $30;

{ Windows for Korean Edition hot key ID from #50 - #6F }
  {$EXTERNALSYM IME_KHOTKEY_SHAPE_TOGGLE}
  IME_KHOTKEY_SHAPE_TOGGLE               = $50;
  {$EXTERNALSYM IME_KHOTKEY_HANJACONVERT}
  IME_KHOTKEY_HANJACONVERT               = $51;
  {$EXTERNALSYM IME_KHOTKEY_ENGLISH}
  IME_KHOTKEY_ENGLISH                    = $52;

{ Windows for Tranditional Chinese Edition hot key ID from #70 - #8F }
  {$EXTERNALSYM IME_THOTKEY_IME_NONIME_TOGGLE}
  IME_THOTKEY_IME_NONIME_TOGGLE          = $70;
  {$EXTERNALSYM IME_THOTKEY_SHAPE_TOGGLE}
  IME_THOTKEY_SHAPE_TOGGLE               = $71;
  {$EXTERNALSYM IME_THOTKEY_SYMBOL_TOGGLE}
  IME_THOTKEY_SYMBOL_TOGGLE              = $72;

{ direct switch hot key ID from #100 - #11F }
  {$EXTERNALSYM IME_HOTKEY_DSWITCH_FIRST}
  IME_HOTKEY_DSWITCH_FIRST               = $100;
  {$EXTERNALSYM IME_HOTKEY_DSWITCH_LAST}
  IME_HOTKEY_DSWITCH_LAST                = $11F;

{ IME private hot key from #200 - #21F }
  {$EXTERNALSYM IME_HOTKEY_PRIVATE_FIRST}
  IME_HOTKEY_PRIVATE_FIRST               = $200;
  {$EXTERNALSYM IME_ITHOTKEY_RESEND_RESULTSTR}
  IME_ITHOTKEY_RESEND_RESULTSTR          = $200;
  {$EXTERNALSYM IME_ITHOTKEY_PREVIOUS_COMPOSITION}
  IME_ITHOTKEY_PREVIOUS_COMPOSITION      = $201;
  {$EXTERNALSYM IME_ITHOTKEY_UISTYLE_TOGGLE}
  IME_ITHOTKEY_UISTYLE_TOGGLE            = $202;
  {$EXTERNALSYM IME_HOTKEY_PRIVATE_LAST}
  IME_HOTKEY_PRIVATE_LAST                = $21F;

{ parameter of ImmGetCompositionString }
  {$EXTERNALSYM GCS_COMPREADSTR}
  GCS_COMPREADSTR                = $0001;
  {$EXTERNALSYM GCS_COMPREADATTR}
  GCS_COMPREADATTR               = $0002;
  {$EXTERNALSYM GCS_COMPREADCLAUSE}
  GCS_COMPREADCLAUSE             = $0004;
  {$EXTERNALSYM GCS_COMPSTR}
  GCS_COMPSTR                    = $0008;
  {$EXTERNALSYM GCS_COMPATTR}
  GCS_COMPATTR                   = $0010;
  {$EXTERNALSYM GCS_COMPCLAUSE}
  GCS_COMPCLAUSE                 = $0020;
  {$EXTERNALSYM GCS_CURSORPOS}
  GCS_CURSORPOS                  = $0080;
  {$EXTERNALSYM GCS_DELTASTART}
  GCS_DELTASTART                 = $0100;
  {$EXTERNALSYM GCS_RESULTREADSTR}
  GCS_RESULTREADSTR              = $0200;
  {$EXTERNALSYM GCS_RESULTREADCLAUSE}
  GCS_RESULTREADCLAUSE           = $0400;
  {$EXTERNALSYM GCS_RESULTSTR}
  GCS_RESULTSTR                  = $0800;
  {$EXTERNALSYM GCS_RESULTCLAUSE}
  GCS_RESULTCLAUSE               = $1000;

{ style bit flags for WM_IME_COMPOSITION }
  {$EXTERNALSYM CS_INSERTCHAR}
  CS_INSERTCHAR                  = $2000;
  {$EXTERNALSYM CS_NOMOVECARET}
  CS_NOMOVECARET                 = $4000;

{ bits of fdwInit of INPUTCONTEXT }
{ IME version constants }
  {$EXTERNALSYM IMEVER_0310}
  IMEVER_0310                    = $0003000A;
  {$EXTERNALSYM IMEVER_0400}
  IMEVER_0400                    = $00040000;

{ IME property bits }
  {$EXTERNALSYM IME_PROP_AT_CARET}
  IME_PROP_AT_CARET              = $00010000;
  {$EXTERNALSYM IME_PROP_SPECIAL_UI}
  IME_PROP_SPECIAL_UI            = $00020000;
  {$EXTERNALSYM IME_PROP_CANDLIST_START_FROM_1}
  IME_PROP_CANDLIST_START_FROM_1 = $00040000;
  {$EXTERNALSYM IME_PROP_UNICODE}
  IME_PROP_UNICODE               = $00080000;

{ IME UICapability bits }
  {$EXTERNALSYM UI_CAP_2700}
  UI_CAP_2700                    = $00000001;
  {$EXTERNALSYM UI_CAP_ROT90}
  UI_CAP_ROT90                   = $00000002;
  {$EXTERNALSYM UI_CAP_ROTANY}
  UI_CAP_ROTANY                  = $00000004;

{ ImmSetCompositionString Capability bits }
  {$EXTERNALSYM SCS_CAP_COMPSTR}
  SCS_CAP_COMPSTR                = $00000001;
  {$EXTERNALSYM SCS_CAP_MAKEREAD}
  SCS_CAP_MAKEREAD               = $00000002;

{ IME WM_IME_SELECT inheritance Capability bits }
  {$EXTERNALSYM SELECT_CAP_CONVERSION}
  SELECT_CAP_CONVERSION          = $00000001;
  {$EXTERNALSYM SELECT_CAP_SENTENCE}
  SELECT_CAP_SENTENCE            = $00000002;

{ ID for deIndex of ImmGetGuideLine }
  {$EXTERNALSYM GGL_LEVEL}
  GGL_LEVEL                      = $00000001;
  {$EXTERNALSYM GGL_INDEX}
  GGL_INDEX                      = $00000002;
  {$EXTERNALSYM GGL_STRING}
  GGL_STRING                     = $00000003;
  {$EXTERNALSYM GGL_PRIVATE}
  GGL_PRIVATE                    = $00000004;

{ ID for dwLevel of GUIDELINE Structure }
  {$EXTERNALSYM GL_LEVEL_NOGUIDELINE}
  GL_LEVEL_NOGUIDELINE           = $00000000;
  {$EXTERNALSYM GL_LEVEL_FATAL}
  GL_LEVEL_FATAL                 = $00000001;
  {$EXTERNALSYM GL_LEVEL_ERROR}
  GL_LEVEL_ERROR                 = $00000002;
  {$EXTERNALSYM GL_LEVEL_WARNING}
  GL_LEVEL_WARNING               = $00000003;
  {$EXTERNALSYM GL_LEVEL_INFORMATION}
  GL_LEVEL_INFORMATION           = $00000004;

{ ID for dwIndex of GUIDELINE Structure }
  {$EXTERNALSYM GL_ID_UNKNOWN}
  GL_ID_UNKNOWN                  = $00000000;
  {$EXTERNALSYM GL_ID_NOMODULE}
  GL_ID_NOMODULE                 = $00000001;
  {$EXTERNALSYM GL_ID_NODICTIONARY}
  GL_ID_NODICTIONARY             = $00000010;
  {$EXTERNALSYM GL_ID_CANNOTSAVE}
  GL_ID_CANNOTSAVE               = $00000011;
  {$EXTERNALSYM GL_ID_NOCONVERT}
  GL_ID_NOCONVERT                = $00000020;
  {$EXTERNALSYM GL_ID_TYPINGERROR}
  GL_ID_TYPINGERROR              = $00000021;
  {$EXTERNALSYM GL_ID_TOOMANYSTROKE}
  GL_ID_TOOMANYSTROKE            = $00000022;
  {$EXTERNALSYM GL_ID_READINGCONFLICT}
  GL_ID_READINGCONFLICT          = $00000023;
  {$EXTERNALSYM GL_ID_INPUTREADING}
  GL_ID_INPUTREADING             = $00000024;
  {$EXTERNALSYM GL_ID_INPUTRADICAL}
  GL_ID_INPUTRADICAL             = $00000025;
  {$EXTERNALSYM GL_ID_INPUTCODE}
  GL_ID_INPUTCODE                = $00000026;
  {$EXTERNALSYM GL_ID_INPUTSYMBOL}
  GL_ID_INPUTSYMBOL              = $00000027;
  {$EXTERNALSYM GL_ID_CHOOSECANDIDATE}
  GL_ID_CHOOSECANDIDATE          = $00000028;
  {$EXTERNALSYM GL_ID_REVERSECONVERSION}
  GL_ID_REVERSECONVERSION        = $00000029;
  {$EXTERNALSYM GL_ID_PRIVATE_FIRST}
  GL_ID_PRIVATE_FIRST            = $00008000;
  {$EXTERNALSYM GL_ID_PRIVATE_LAST}
  GL_ID_PRIVATE_LAST             = $0000FFFF;

{ ID for dwIndex of ImmGetProperty }
  {$EXTERNALSYM IGP_GETIMEVERSION}
  IGP_GETIMEVERSION              = 4;
  {$EXTERNALSYM IGP_PROPERTY}
  IGP_PROPERTY                   = $00000004;
  {$EXTERNALSYM IGP_CONVERSION}
  IGP_CONVERSION                 = $00000008;
  {$EXTERNALSYM IGP_SENTENCE}
  IGP_SENTENCE                   = $0000000c;
  {$EXTERNALSYM IGP_UI}
  IGP_UI                         = $00000010;
  {$EXTERNALSYM IGP_SETCOMPSTR}
  IGP_SETCOMPSTR                 = $00000014;
  {$EXTERNALSYM IGP_SELECT}
  IGP_SELECT                     = $00000018;

{ dwIndex for ImmSetCompositionString API }
  {$EXTERNALSYM SCS_SETSTR}
  SCS_SETSTR                     = (GCS_COMPREADSTR or GCS_COMPSTR);
  {$EXTERNALSYM SCS_CHANGEATTR}
  SCS_CHANGEATTR                 = (GCS_COMPREADATTR or GCS_COMPATTR);
  {$EXTERNALSYM SCS_CHANGECLAUSE}
  SCS_CHANGECLAUSE               = (GCS_COMPREADCLAUSE or GCS_COMPCLAUSE);

{ attribute for COMPOSITIONSTRING Structure }
  {$EXTERNALSYM ATTR_INPUT}
  ATTR_INPUT                     = $00;
  {$EXTERNALSYM ATTR_TARGET_CONVERTED}
  ATTR_TARGET_CONVERTED          = $01;
  {$EXTERNALSYM ATTR_CONVERTED}
  ATTR_CONVERTED                 = $02;
  {$EXTERNALSYM ATTR_TARGET_NOTCONVERTED}
  ATTR_TARGET_NOTCONVERTED       = $03;
  {$EXTERNALSYM ATTR_INPUT_ERROR}
  ATTR_INPUT_ERROR               = $04;

{ bit field for IMC_SETCOMPOSITIONWINDOW, IMC_SETCANDIDATEWINDOW }
  {$EXTERNALSYM CFS_DEFAULT}
  CFS_DEFAULT                    = $0000;
  {$EXTERNALSYM CFS_RECT}
  CFS_RECT                       = $0001;
  {$EXTERNALSYM CFS_POINT}
  CFS_POINT                      = $0002;
  CFS_SCREEN                     = $0004;	{ removed in 4.0 SDK }
  {$EXTERNALSYM CFS_FORCE_POSITION}
  CFS_FORCE_POSITION             = $0020;
  {$EXTERNALSYM CFS_CANDIDATEPOS}
  CFS_CANDIDATEPOS               = $0040;
  {$EXTERNALSYM CFS_EXCLUDE}
  CFS_EXCLUDE                    = $0080;

{ conversion direction for ImmGetConversionList }
  {$EXTERNALSYM GCL_CONVERSION}
  GCL_CONVERSION                 = $0001;
  {$EXTERNALSYM GCL_REVERSECONVERSION}
  GCL_REVERSECONVERSION          = $0002;
  {$EXTERNALSYM GCL_REVERSE_LENGTH}
  GCL_REVERSE_LENGTH             = $0003;

{ bit field for conversion mode }
  {$EXTERNALSYM IME_CMODE_ALPHANUMERIC}
  IME_CMODE_ALPHANUMERIC         = $0000;
  {$EXTERNALSYM IME_CMODE_NATIVE}
  IME_CMODE_NATIVE               = $0001;
  {$EXTERNALSYM IME_CMODE_CHINESE}
  IME_CMODE_CHINESE              = IME_CMODE_NATIVE;
  {$EXTERNALSYM IME_CMODE_HANGEUL}
  IME_CMODE_HANGEUL              = IME_CMODE_NATIVE;
  {$EXTERNALSYM IME_CMODE_HANGUL}
  IME_CMODE_HANGUL               = IME_CMODE_NATIVE;
  {$EXTERNALSYM IME_CMODE_JAPANESE}
  IME_CMODE_JAPANESE             = IME_CMODE_NATIVE;
  {$EXTERNALSYM IME_CMODE_KATAKANA}
  IME_CMODE_KATAKANA             = $0002;  { effective only under IME_CMODE_NATIVE}
  {$EXTERNALSYM IME_CMODE_LANGUAGE}
  IME_CMODE_LANGUAGE             = $0003;
  {$EXTERNALSYM IME_CMODE_FULLSHAPE}
  IME_CMODE_FULLSHAPE            = $0008;
  {$EXTERNALSYM IME_CMODE_ROMAN}
  IME_CMODE_ROMAN                = $0010;
  {$EXTERNALSYM IME_CMODE_CHARCODE}
  IME_CMODE_CHARCODE             = $0020;
  {$EXTERNALSYM IME_CMODE_HANJACONVERT}
  IME_CMODE_HANJACONVERT         = $0040;
  {$EXTERNALSYM IME_CMODE_SOFTKBD}
  IME_CMODE_SOFTKBD              = $0080;
  {$EXTERNALSYM IME_CMODE_NOCONVERSION}
  IME_CMODE_NOCONVERSION         = $0100;
  {$EXTERNALSYM IME_CMODE_EUDC}
  IME_CMODE_EUDC                 = $0200;
  {$EXTERNALSYM IME_CMODE_SYMBOL}
  IME_CMODE_SYMBOL               = $0400;

  {$EXTERNALSYM IME_SMODE_NONE}
  IME_SMODE_NONE                 = $0000;
  {$EXTERNALSYM IME_SMODE_PLAURALCLAUSE}
  IME_SMODE_PLAURALCLAUSE        = $0001;
  {$EXTERNALSYM IME_SMODE_SINGLECONVERT}
  IME_SMODE_SINGLECONVERT        = $0002;
  {$EXTERNALSYM IME_SMODE_AUTOMATIC}
  IME_SMODE_AUTOMATIC            = $0004;
  {$EXTERNALSYM IME_SMODE_PHRASEPREDICT}
  IME_SMODE_PHRASEPREDICT        = $0008;

{ style of candidate }
  {$EXTERNALSYM IME_CAND_UNKNOWN}
  IME_CAND_UNKNOWN               = $0000;
  {$EXTERNALSYM IME_CAND_READ}
  IME_CAND_READ                  = $0001;
  {$EXTERNALSYM IME_CAND_CODE}
  IME_CAND_CODE                  = $0002;
  {$EXTERNALSYM IME_CAND_MEANING}
  IME_CAND_MEANING               = $0003;
  {$EXTERNALSYM IME_CAND_RADICAL}
  IME_CAND_RADICAL               = $0004;
  {$EXTERNALSYM IME_CAND_STROKE}
  IME_CAND_STROKE                = $0005;

{ wParam of report message WM_IME_NOTIFY }
  {$EXTERNALSYM IMN_CLOSESTATUSWINDOW}
  IMN_CLOSESTATUSWINDOW          = $0001;
  {$EXTERNALSYM IMN_OPENSTATUSWINDOW}
  IMN_OPENSTATUSWINDOW           = $0002;
  {$EXTERNALSYM IMN_CHANGECANDIDATE}
  IMN_CHANGECANDIDATE            = $0003;
  {$EXTERNALSYM IMN_CLOSECANDIDATE}
  IMN_CLOSECANDIDATE             = $0004;
  {$EXTERNALSYM IMN_OPENCANDIDATE}
  IMN_OPENCANDIDATE              = $0005;
  {$EXTERNALSYM IMN_SETCONVERSIONMODE}
  IMN_SETCONVERSIONMODE          = $0006;
  {$EXTERNALSYM IMN_SETSENTENCEMODE}
  IMN_SETSENTENCEMODE            = $0007;
  {$EXTERNALSYM IMN_SETOPENSTATUS}
  IMN_SETOPENSTATUS              = $0008;
  {$EXTERNALSYM IMN_SETCANDIDATEPOS}
  IMN_SETCANDIDATEPOS            = $0009;
  {$EXTERNALSYM IMN_SETCOMPOSITIONFONT}
  IMN_SETCOMPOSITIONFONT         = $000A;
  {$EXTERNALSYM IMN_SETCOMPOSITIONWINDOW}
  IMN_SETCOMPOSITIONWINDOW       = $000B;
  {$EXTERNALSYM IMN_SETSTATUSWINDOWPOS}
  IMN_SETSTATUSWINDOWPOS         = $000C;
  {$EXTERNALSYM IMN_GUIDELINE}
  IMN_GUIDELINE                  = $000D;
  {$EXTERNALSYM IMN_PRIVATE}
  IMN_PRIVATE                    = $000E;

{ error code of ImmGetCompositionString }
  {$EXTERNALSYM IMM_ERROR_NODATA}
  IMM_ERROR_NODATA               = -1;
  {$EXTERNALSYM IMM_ERROR_GENERAL}
  IMM_ERROR_GENERAL              = -2;

{ dialog mode of ImmConfigureIME }
  {$EXTERNALSYM IME_CONFIG_GENERAL}
  IME_CONFIG_GENERAL             = 1;
  {$EXTERNALSYM IME_CONFIG_REGISTERWORD}
  IME_CONFIG_REGISTERWORD        = 2;
  {$EXTERNALSYM IME_CONFIG_SELECTDICTIONARY}
  IME_CONFIG_SELECTDICTIONARY    = 3;

{ dialog mode of ImmEscape }
  {$EXTERNALSYM IME_ESC_QUERY_SUPPORT}
  IME_ESC_QUERY_SUPPORT          = $0003;
  {$EXTERNALSYM IME_ESC_RESERVED_FIRST}
  IME_ESC_RESERVED_FIRST         = $0004;
  {$EXTERNALSYM IME_ESC_RESERVED_LAST}
  IME_ESC_RESERVED_LAST          = $07FF;
  {$EXTERNALSYM IME_ESC_PRIVATE_FIRST}
  IME_ESC_PRIVATE_FIRST          = $0800;
  {$EXTERNALSYM IME_ESC_PRIVATE_LAST}
  IME_ESC_PRIVATE_LAST           = $0FFF;
  {$EXTERNALSYM IME_ESC_SEQUENCE_TO_INTERNAL}
  IME_ESC_SEQUENCE_TO_INTERNAL   = $1001;
  {$EXTERNALSYM IME_ESC_GET_EUDC_DICTIONARY}
  IME_ESC_GET_EUDC_DICTIONARY    = $1003;
  {$EXTERNALSYM IME_ESC_SET_EUDC_DICTIONARY}
  IME_ESC_SET_EUDC_DICTIONARY    = $1004;
  {$EXTERNALSYM IME_ESC_MAX_KEY}
  IME_ESC_MAX_KEY                = $1005;
  {$EXTERNALSYM IME_ESC_IME_NAME}
  IME_ESC_IME_NAME               = $1006;
  {$EXTERNALSYM IME_ESC_SYNC_HOTKEY}
  IME_ESC_SYNC_HOTKEY            = $1007;
  {$EXTERNALSYM IME_ESC_HANJA_MODE}
  IME_ESC_HANJA_MODE             = $1008;
  {$EXTERNALSYM IME_ESC_AUTOMATA}
  IME_ESC_AUTOMATA               = $1009;

  {$EXTERNALSYM IME_ESC_PRIVATE_HOTKEY}
  IME_ESC_PRIVATE_HOTKEY         = $100A;
  
{ style of word registration }
  {$EXTERNALSYM IME_REGWORD_STYLE_EUDC}
  IME_REGWORD_STYLE_EUDC         = $00000001;
  {$EXTERNALSYM IME_REGWORD_STYLE_USER_FIRST}
  IME_REGWORD_STYLE_USER_FIRST   = $80000000;
  {$EXTERNALSYM IME_REGWORD_STYLE_USER_LAST}
  IME_REGWORD_STYLE_USER_LAST    = $FFFFFFFF;

{ type of soft keyboard }
{ for Windows Tranditional Chinese Edition }
  {$EXTERNALSYM SOFTKEYBOARD_TYPE_T1}
  SOFTKEYBOARD_TYPE_T1           = $0001;
{ for Windows Simplified Chinese Edition }
  {$EXTERNALSYM SOFTKEYBOARD_TYPE_C1}
  SOFTKEYBOARD_TYPE_C1           = $0002;

const
  imm32 = 'imm32.dll';

implementation

function ImmInstallIMEA; external imm32 name 'ImmInstallIMEA';
function ImmInstallIMEW; external imm32 name 'ImmInstallIMEW';
function ImmInstallIME; external imm32 name 'ImmInstallIMEA';
function ImmGetDefaultIMEWnd; external imm32 name 'ImmGetDefaultIMEWnd';
function ImmGetDescriptionA; external imm32 name 'ImmGetDescriptionA';
function ImmGetDescriptionW; external imm32 name 'ImmGetDescriptionW';
function ImmGetDescription; external imm32 name 'ImmGetDescriptionA';
function ImmGetIMEFileNameA; external imm32 name 'ImmGetIMEFileNameA';
function ImmGetIMEFileNameW; external imm32 name 'ImmGetIMEFileNameW';
function ImmGetIMEFileName; external imm32 name 'ImmGetIMEFileNameA';
function ImmGetProperty; external imm32 name 'ImmGetProperty';
function ImmIsIME; external imm32 name 'ImmIsIME';
function ImmSimulateHotKey; external imm32 name 'ImmSimulateHotKey';
function ImmCreateContext; external imm32 name 'ImmCreateContext';
function ImmDestroyContext; external imm32 name 'ImmDestroyContext';
function ImmGetContext; external imm32 name 'ImmGetContext';
function ImmReleaseContext; external imm32 name 'ImmReleaseContext';
function ImmAssociateContext; external imm32 name 'ImmAssociateContext';
function ImmGetCompositionStringA; external imm32 name 'ImmGetCompositionStringA';
function ImmGetCompositionStringW; external imm32 name 'ImmGetCompositionStringW';
function ImmGetCompositionString; external imm32 name 'ImmGetCompositionStringA';
function ImmSetCompositionStringA; external imm32 name 'ImmSetCompositionStringA';
function ImmSetCompositionStringW; external imm32 name 'ImmSetCompositionStringW';
function ImmSetCompositionString; external imm32 name 'ImmSetCompositionStringA';
function ImmGetCandidateListCountA; external imm32 name 'ImmGetCandidateListCountA';
function ImmGetCandidateListCountW; external imm32 name 'ImmGetCandidateListCountW';
function ImmGetCandidateListCount; external imm32 name 'ImmGetCandidateListCountA';
function ImmGetCandidateListA; external imm32 name 'ImmGetCandidateListA';
function ImmGetCandidateListW; external imm32 name 'ImmGetCandidateListW';
function ImmGetCandidateList; external imm32 name 'ImmGetCandidateListA';
function ImmGetGuideLineA; external imm32 name 'ImmGetGuideLineA';
function ImmGetGuideLineW; external imm32 name 'ImmGetGuideLineW';
function ImmGetGuideLine; external imm32 name 'ImmGetGuideLineA';
function ImmGetConversionStatus; external imm32 name 'ImmGetConversionStatus';
function ImmSetConversionStatus; external imm32 name 'ImmSetConversionStatus';
function ImmGetOpenStatus; external imm32 name 'ImmGetOpenStatus';
function ImmSetOpenStatus; external imm32 name 'ImmSetOpenStatus';
function ImmGetCompositionFontA; external imm32 name 'ImmGetCompositionFontA';
function ImmGetCompositionFontW; external imm32 name 'ImmGetCompositionFontW';
function ImmGetCompositionFont; external imm32 name 'ImmGetCompositionFontA';
function ImmSetCompositionFontA; external imm32 name 'ImmSetCompositionFontA';
function ImmSetCompositionFontW; external imm32 name 'ImmSetCompositionFontW';
function ImmSetCompositionFont; external imm32 name 'ImmSetCompositionFontA';
function ImmConfigureIMEA; external imm32 name 'ImmConfigureIMEA';
function ImmConfigureIMEW; external imm32 name 'ImmConfigureIMEW';
function ImmConfigureIME; external imm32 name 'ImmConfigureIMEA';
function ImmEscapeA; external imm32 name 'ImmEscapeA';
function ImmEscapeW; external imm32 name 'ImmEscapeW';
function ImmEscape; external imm32 name 'ImmEscapeA';
function ImmGetConversionListA; external imm32 name 'ImmGetConversionListA';
function ImmGetConversionListW; external imm32 name 'ImmGetConversionListW';
function ImmGetConversionList; external imm32 name 'ImmGetConversionListA';
function ImmNotifyIME; external imm32 name 'ImmNotifyIME';
function ImmGetStatusWindowPos; external imm32 name 'ImmGetStatusWindowPos';
function ImmSetStatusWindowPos; external imm32 name 'ImmSetStatusWindowPos';
function ImmGetCompositionWindow; external imm32 name 'ImmGetCompositionWindow';
function ImmSetCompositionWindow; external imm32 name 'ImmSetCompositionWindow';
function ImmGetCandidateWindow; external imm32 name 'ImmGetCandidateWindow';
function ImmSetCandidateWindow; external imm32 name 'ImmSetCandidateWindow';
function ImmIsUIMessageA; external imm32 name 'ImmIsUIMessageA';
function ImmIsUIMessageW; external imm32 name 'ImmIsUIMessageW';
function ImmIsUIMessage; external imm32 name 'ImmIsUIMessageA';
function ImmGetVirtualKey; external imm32 name 'ImmGetVirtualKey';
function ImmRegisterWordA; external imm32 name 'ImmRegisterWordA';
function ImmRegisterWordW; external imm32 name 'ImmRegisterWordW';
function ImmRegisterWord; external imm32 name 'ImmRegisterWordA';
function ImmUnregisterWordA; external imm32 name 'ImmUnregisterWordA';
function ImmUnregisterWordW; external imm32 name 'ImmUnregisterWordW';
function ImmUnregisterWord; external imm32 name 'ImmUnregisterWordA';
function ImmGetRegisterWordStyleA; external imm32 name 'ImmGetRegisterWordStyleA';
function ImmGetRegisterWordStyleW; external imm32 name 'ImmGetRegisterWordStyleW';
function ImmGetRegisterWordStyle; external imm32 name 'ImmGetRegisterWordStyleA';
function ImmEnumRegisterWordA; external imm32 name 'ImmEnumRegisterWordA';
function ImmEnumRegisterWordW; external imm32 name 'ImmEnumRegisterWordW';
function ImmEnumRegisterWord; external imm32 name 'ImmEnumRegisterWordA';

end.

