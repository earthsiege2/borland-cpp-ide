
{*******************************************************}
{                                                       }
{       Borland Delphi Run-time Library                 }
{       Win32 Common Dialogs interface unit             }
{                                                       }
{       Copyright (c) 1985-1999, Microsoft Corporation  }
{                                                       }
{       Translator: Inprise Corporation                 }
{                                                       }
{*******************************************************}

unit CommDlg;

{$WEAKPACKAGEUNIT}

{$HPPEMIT '#include <commdlg.h>'}

interface

uses Windows, Messages, ShlObj;

type
  POpenFilenameA = ^TOpenFilenameA;
  POpenFilenameW = ^TOpenFilenameW;
  POpenFilename = POpenFilenameA;
  {$EXTERNALSYM tagOFNA}
  tagOFNA = packed record
    lStructSize: DWORD;
    hWndOwner: HWND;
    hInstance: HINST;
    lpstrFilter: PAnsiChar;
    lpstrCustomFilter: PAnsiChar;
    nMaxCustFilter: DWORD;
    nFilterIndex: DWORD;
    lpstrFile: PAnsiChar;
    nMaxFile: DWORD;
    lpstrFileTitle: PAnsiChar;
    nMaxFileTitle: DWORD;
    lpstrInitialDir: PAnsiChar;
    lpstrTitle: PAnsiChar;
    Flags: DWORD;
    nFileOffset: Word;
    nFileExtension: Word;
    lpstrDefExt: PAnsiChar;
    lCustData: LPARAM;
    lpfnHook: function(Wnd: HWND; Msg: UINT; wParam: WPARAM; lParam: LPARAM): UINT stdcall;
    lpTemplateName: PAnsiChar;
  end;
  {$EXTERNALSYM tagOFNW}
  tagOFNW = packed record
    lStructSize: DWORD;
    hWndOwner: HWND;
    hInstance: HINST;
    lpstrFilter: PWideChar;
    lpstrCustomFilter: PWideChar;
    nMaxCustFilter: DWORD;
    nFilterIndex: DWORD;
    lpstrFile: PWideChar;
    nMaxFile: DWORD;
    lpstrFileTitle: PWideChar;
    nMaxFileTitle: DWORD;
    lpstrInitialDir: PWideChar;
    lpstrTitle: PWideChar;
    Flags: DWORD;
    nFileOffset: Word;
    nFileExtension: Word;
    lpstrDefExt: PWideChar;
    lCustData: LPARAM;
    lpfnHook: function(Wnd: HWND; Msg: UINT; wParam: WPARAM; lParam: LPARAM): UINT stdcall;
    lpTemplateName: PWideChar;
  end;
  {$EXTERNALSYM tagOFN}
  tagOFN = tagOFNA;
  TOpenFilenameA = tagOFNA;
  TOpenFilenameW = tagOFNW;
  TOpenFilename = TOpenFilenameA;
  {$EXTERNALSYM OPENFILENAMEA}
  OPENFILENAMEA = tagOFNA;
  {$EXTERNALSYM OPENFILENAMEW}
  OPENFILENAMEW = tagOFNW;
  {$EXTERNALSYM OPENFILENAME}
  OPENFILENAME = OPENFILENAMEA;

{$EXTERNALSYM GetOpenFileNameA}
function GetOpenFileNameA(var OpenFile: TOpenFilenameA): Bool; stdcall;
{$EXTERNALSYM GetOpenFileNameW}
function GetOpenFileNameW(var OpenFile: TOpenFilenameW): Bool; stdcall;
{$EXTERNALSYM GetOpenFileName}
function GetOpenFileName(var OpenFile: TOpenFilename): Bool; stdcall;
{$EXTERNALSYM GetSaveFileNameA}
function GetSaveFileNameA(var OpenFile: TOpenFilenameA): Bool; stdcall;
{$EXTERNALSYM GetSaveFileNameW}
function GetSaveFileNameW(var OpenFile: TOpenFilenameW): Bool; stdcall;
{$EXTERNALSYM GetSaveFileName}
function GetSaveFileName(var OpenFile: TOpenFilename): Bool; stdcall;
{$EXTERNALSYM GetFileTitleA}
function GetFileTitleA(FileName: PAnsiChar; Title: PAnsiChar; TitleSize: Word): Smallint; stdcall;
{$EXTERNALSYM GetFileTitleW}
function GetFileTitleW(FileName: PWideChar; Title: PWideChar; TitleSize: Word): Smallint; stdcall;
{$EXTERNALSYM GetFileTitle}
function GetFileTitle(FileName: PChar; Title: PChar; TitleSize: Word): Smallint; stdcall;

const
  {$EXTERNALSYM OFN_READONLY}
  OFN_READONLY = $00000001;
  {$EXTERNALSYM OFN_OVERWRITEPROMPT}
  OFN_OVERWRITEPROMPT = $00000002;
  {$EXTERNALSYM OFN_HIDEREADONLY}
  OFN_HIDEREADONLY = $00000004;
  {$EXTERNALSYM OFN_NOCHANGEDIR}
  OFN_NOCHANGEDIR = $00000008;
  {$EXTERNALSYM OFN_SHOWHELP}
  OFN_SHOWHELP = $00000010;
  {$EXTERNALSYM OFN_ENABLEHOOK}
  OFN_ENABLEHOOK = $00000020;
  {$EXTERNALSYM OFN_ENABLETEMPLATE}
  OFN_ENABLETEMPLATE = $00000040;
  {$EXTERNALSYM OFN_ENABLETEMPLATEHANDLE}
  OFN_ENABLETEMPLATEHANDLE = $00000080;
  {$EXTERNALSYM OFN_NOVALIDATE}
  OFN_NOVALIDATE = $00000100;
  {$EXTERNALSYM OFN_ALLOWMULTISELECT}
  OFN_ALLOWMULTISELECT = $00000200;
  {$EXTERNALSYM OFN_EXTENSIONDIFFERENT}
  OFN_EXTENSIONDIFFERENT = $00000400;
  {$EXTERNALSYM OFN_PATHMUSTEXIST}
  OFN_PATHMUSTEXIST = $00000800;
  {$EXTERNALSYM OFN_FILEMUSTEXIST}
  OFN_FILEMUSTEXIST = $00001000;
  {$EXTERNALSYM OFN_CREATEPROMPT}
  OFN_CREATEPROMPT = $00002000;
  {$EXTERNALSYM OFN_SHAREAWARE}
  OFN_SHAREAWARE = $00004000;
  {$EXTERNALSYM OFN_NOREADONLYRETURN}
  OFN_NOREADONLYRETURN = $00008000;
  {$EXTERNALSYM OFN_NOTESTFILECREATE}
  OFN_NOTESTFILECREATE = $00010000;
  {$EXTERNALSYM OFN_NONETWORKBUTTON}
  OFN_NONETWORKBUTTON = $00020000;
  {$EXTERNALSYM OFN_NOLONGNAMES}
  OFN_NOLONGNAMES = $00040000;
  {$EXTERNALSYM OFN_EXPLORER}
  OFN_EXPLORER = $00080000;
  {$EXTERNALSYM OFN_NODEREFERENCELINKS}
  OFN_NODEREFERENCELINKS = $00100000;
  {$EXTERNALSYM OFN_LONGNAMES}
  OFN_LONGNAMES = $00200000;
  {$EXTERNALSYM OFN_ENABLEINCLUDENOTIFY}
  OFN_ENABLEINCLUDENOTIFY = $00400000;
  {$EXTERNALSYM OFN_ENABLESIZING}
  OFN_ENABLESIZING = $00800000;


{ Return values for the registered message sent to the hook function
  when a sharing violation occurs.  OFN_SHAREFALLTHROUGH allows the
  filename to be accepted, OFN_SHARENOWARN rejects the name but puts
  up no warning (returned when the app has already put up a warning
  message), and OFN_SHAREWARN puts up the default warning message
  for sharing violations.

  Note:  Undefined return values map to OFN_SHAREWARN, but are
         reserved for future use. }

  {$EXTERNALSYM OFN_SHAREFALLTHROUGH}
  OFN_SHAREFALLTHROUGH = 2;
  {$EXTERNALSYM OFN_SHARENOWARN}
  OFN_SHARENOWARN = 1;
  {$EXTERNALSYM OFN_SHAREWARN}
  OFN_SHAREWARN = 0;

type
  POFNotifyA = ^TOFNotifyA;
  POFNotifyW = ^TOFNotifyW;
  POFNotify = POFNotifyA;
  {$EXTERNALSYM _OFNOTIFYA}
  _OFNOTIFYA = packed record
    hdr: TNMHdr;
    lpOFN: POpenFilenameA;
    pszFile: PAnsiChar;
  end;
  {$EXTERNALSYM _OFNOTIFYW}
  _OFNOTIFYW = packed record
    hdr: TNMHdr;
    lpOFN: POpenFilenameW;
    pszFile: PWideChar;
  end;
  {$EXTERNALSYM _OFNOTIFY}
  _OFNOTIFY = _OFNOTIFYA;
  TOFNotifyA = _OFNOTIFYA;
  TOFNotifyW = _OFNOTIFYW;
  TOFNotify = TOFNotifyA;
  {$EXTERNALSYM OFNOTIFYA}
  OFNOTIFYA = _OFNOTIFYA;
  {$EXTERNALSYM OFNOTIFYW}
  OFNOTIFYW = _OFNOTIFYW;
  {$EXTERNALSYM OFNOTIFY}
  OFNOTIFY = OFNOTIFYA;


  POFNotifyExA = ^TOFNotifyExA;
  POFNotifyExW = ^TOFNotifyExW;
  POFNotifyEx = POFNotifyExA;
  {$EXTERNALSYM _OFNOTIFYEXA}
  _OFNOTIFYEXA = packed record
    hdr: TNMHdr;
    lpOFN: POpenFilenameA;
    psf: IShellFolder;
    pidl: Pointer;
  end;
  {$EXTERNALSYM _OFNOTIFYEXW}
  _OFNOTIFYEXW = packed record
    hdr: TNMHdr;
    lpOFN: POpenFilenameW;
    psf: IShellFolder;
    pidl: Pointer;
  end;
  {$EXTERNALSYM _OFNOTIFYEX}
  _OFNOTIFYEX = _OFNOTIFYEXA;
  TOFNotifyExA = _OFNOTIFYEXA;
  TOFNotifyExW = _OFNOTIFYEXW;
  TOFNotifyEx = TOFNotifyExA;
  {$EXTERNALSYM OFNOTIFYEXA}
  OFNOTIFYEXA = _OFNOTIFYEXA;
  {$EXTERNALSYM OFNOTIFYEXW}
  OFNOTIFYEXW = _OFNOTIFYEXW;
  {$EXTERNALSYM OFNOTIFYEX}
  OFNOTIFYEX = OFNOTIFYEXA;

const
  {$EXTERNALSYM CDN_FIRST}
  CDN_FIRST = -601;
  {$EXTERNALSYM CDN_LAST}
  CDN_LAST = -699;

{ Notifications when Open or Save dialog status changes }

  {$EXTERNALSYM CDN_INITDONE}
  CDN_INITDONE = CDN_FIRST - 0;
  {$EXTERNALSYM CDN_SELCHANGE}
  CDN_SELCHANGE = CDN_FIRST - 1;
  {$EXTERNALSYM CDN_FOLDERCHANGE}
  CDN_FOLDERCHANGE = CDN_FIRST - 2;
  {$EXTERNALSYM CDN_SHAREVIOLATION}
  CDN_SHAREVIOLATION = CDN_FIRST - 3;
  {$EXTERNALSYM CDN_HELP}
  CDN_HELP = CDN_FIRST - 4;
  {$EXTERNALSYM CDN_FILEOK}
  CDN_FILEOK = CDN_FIRST - 5;
  {$EXTERNALSYM CDN_TYPECHANGE}
  CDN_TYPECHANGE = CDN_FIRST - 6;
  {$EXTERNALSYM CDN_INCLUDEITEM}
  CDN_INCLUDEITEM = CDN_FIRST - 7;

  {$EXTERNALSYM CDM_FIRST}
  CDM_FIRST = WM_USER + 100;
  {$EXTERNALSYM CDM_LAST}
  CDM_LAST = WM_USER + 200;

{ Messages to query information from the Open or Save dialogs }

{ lParam = pointer to text buffer that gets filled in
  wParam = max number of characters of the text buffer (including NULL)
  return = < 0 if error; number of characters needed (including NULL) }

  {$EXTERNALSYM CDM_GETSPEC}
  CDM_GETSPEC = CDM_FIRST + 0;

{ lParam = pointer to text buffer that gets filled in
  wParam = max number of characters of the text buffer (including NULL)
  return = < 0 if error; number of characters needed (including NULL) }

  {$EXTERNALSYM CDM_GETFILEPATH}
  CDM_GETFILEPATH = CDM_FIRST + 1;

{ lParam = pointer to text buffer that gets filled in
  wParam = max number of characters of the text buffer (including NULL)
  return = < 0 if error; number of characters needed (including NULL) }

  {$EXTERNALSYM CDM_GETFOLDERPATH}
  CDM_GETFOLDERPATH = CDM_FIRST + 2;

{ lParam = pointer to ITEMIDLIST buffer that gets filled in
  wParam = size of the ITEMIDLIST buffer
  return = < 0 if error; length of buffer needed }

  {$EXTERNALSYM CDM_GETFOLDERIDLIST}
  CDM_GETFOLDERIDLIST = CDM_FIRST + 3;

{ lParam = pointer to a string
  wParam = ID of control to change
  return = not used }

  {$EXTERNALSYM CDM_SETCONTROLTEXT}
  CDM_SETCONTROLTEXT = CDM_FIRST + 4;

{ lParam = not used
  wParam = ID of control to change
  return = not used }

  {$EXTERNALSYM CDM_HIDECONTROL}
  CDM_HIDECONTROL = CDM_FIRST + 5;

{ lParam = pointer to default extension (no dot)
  wParam = not used
  return = not used }

  {$EXTERNALSYM CDM_SETDEFEXT}
  CDM_SETDEFEXT = CDM_FIRST + 6;

type
  PChooseColorA = ^TChooseColorA;
  PChooseColorW = ^TChooseColorW;
  PChooseColor = PChooseColorA;
  {$EXTERNALSYM tagCHOOSECOLORA}
  tagCHOOSECOLORA = packed record
    lStructSize: DWORD;
    hWndOwner: HWND;
    hInstance: HWND;
    rgbResult: COLORREF;
    lpCustColors: ^COLORREF;
    Flags: DWORD;
    lCustData: LPARAM;
    lpfnHook: function(Wnd: HWND; Message: UINT; wParam: WPARAM; lParam: LPARAM): UINT stdcall;
    lpTemplateName: PAnsiChar;
  end;
  {$EXTERNALSYM tagCHOOSECOLORW}
  tagCHOOSECOLORW = packed record
    lStructSize: DWORD;
    hWndOwner: HWND;
    hInstance: HWND;
    rgbResult: COLORREF;
    lpCustColors: ^COLORREF;
    Flags: DWORD;
    lCustData: LPARAM;
    lpfnHook: function(Wnd: HWND; Message: UINT; wParam: WPARAM; lParam: LPARAM): UINT stdcall;
    lpTemplateName: PWideChar;
  end;
  {$EXTERNALSYM tagCHOOSECOLOR}
  tagCHOOSECOLOR = tagCHOOSECOLORA;
  TChooseColorA = tagCHOOSECOLORA;
  TChooseColorW = tagCHOOSECOLORW;
  TChooseColor = TChooseColorA;

{$EXTERNALSYM ChooseColorA}
function ChooseColorA(var CC: TChooseColorA): Bool; stdcall;
{$EXTERNALSYM ChooseColorW}
function ChooseColorW(var CC: TChooseColorW): Bool; stdcall;
{$EXTERNALSYM ChooseColor}
function ChooseColor(var CC: TChooseColor): Bool; stdcall;

const
  {$EXTERNALSYM CC_RGBINIT}
  CC_RGBINIT = $00000001;
  {$EXTERNALSYM CC_FULLOPEN}
  CC_FULLOPEN = $00000002;
  {$EXTERNALSYM CC_PREVENTFULLOPEN}
  CC_PREVENTFULLOPEN = $00000004;
  {$EXTERNALSYM CC_SHOWHELP}
  CC_SHOWHELP = $00000008;
  {$EXTERNALSYM CC_ENABLEHOOK}
  CC_ENABLEHOOK = $00000010;
  {$EXTERNALSYM CC_ENABLETEMPLATE}
  CC_ENABLETEMPLATE = $00000020;
  {$EXTERNALSYM CC_ENABLETEMPLATEHANDLE}
  CC_ENABLETEMPLATEHANDLE = $00000040;
  {$EXTERNALSYM CC_SOLIDCOLOR}
  CC_SOLIDCOLOR = $00000080;
  {$EXTERNALSYM CC_ANYCOLOR}
  CC_ANYCOLOR = $00000100;

type
  PFindReplaceA = ^TFindReplaceA;
  PFindReplaceW = ^TFindReplaceW;
  PFindReplace = PFindReplaceA;
  {$EXTERNALSYM tagFINDREPLACEA}
  tagFINDREPLACEA = packed record
    lStructSize: DWORD;        { size of this struct $20 }
    hWndOwner: HWND;             { handle to owner's window }
    hInstance: HINST;        { instance handle of.EXE that
                                   contains cust. dlg. template }
    Flags: DWORD;                { one or more of the fr_?? }
    lpstrFindWhat: PAnsiChar;       { ptr. to search string    }
    lpstrReplaceWith: PAnsiChar;    { ptr. to replace string   }
    wFindWhatLen: Word;          { size of find buffer      }
    wReplaceWithLen: Word;       { size of replace buffer   }
    lCustData: LPARAM;           { data passed to hook fn.  }
    lpfnHook: function(Wnd: HWND; Message: UINT; wParam: WPARAM; lParam: LPARAM): UINT stdcall;
                                 { ptr. to hook fn. or nil }
    lpTemplateName: PAnsiChar;     { custom template name     }
  end;
  {$EXTERNALSYM tagFINDREPLACEW}
  tagFINDREPLACEW = packed record
    lStructSize: DWORD;        { size of this struct $20 }
    hWndOwner: HWND;             { handle to owner's window }
    hInstance: HINST;        { instance handle of.EXE that
                                   contains cust. dlg. template }
    Flags: DWORD;                { one or more of the fr_?? }
    lpstrFindWhat: PWideChar;       { ptr. to search string    }
    lpstrReplaceWith: PWideChar;    { ptr. to replace string   }
    wFindWhatLen: Word;          { size of find buffer      }
    wReplaceWithLen: Word;       { size of replace buffer   }
    lCustData: LPARAM;           { data passed to hook fn.  }
    lpfnHook: function(Wnd: HWND; Message: UINT; wParam: WPARAM; lParam: LPARAM): UINT stdcall;
                                 { ptr. to hook fn. or nil }
    lpTemplateName: PWideChar;     { custom template name     }
  end;
  {$EXTERNALSYM tagFINDREPLACE}
  tagFINDREPLACE = tagFINDREPLACEA;
  TFindReplaceA = tagFINDREPLACEA;
  TFindReplaceW = tagFINDREPLACEW;
  TFindReplace = TFindReplaceA;
  {$EXTERNALSYM FINDREPLACEA}
  FINDREPLACEA = tagFINDREPLACEA;
  {$EXTERNALSYM FINDREPLACEW}
  FINDREPLACEW = tagFINDREPLACEW;
  {$EXTERNALSYM FINDREPLACE}
  FINDREPLACE = FINDREPLACEA;

const
  {$EXTERNALSYM FR_DOWN}
  FR_DOWN = $00000001;
  {$EXTERNALSYM FR_WHOLEWORD}
  FR_WHOLEWORD = $00000002;
  {$EXTERNALSYM FR_MATCHCASE}
  FR_MATCHCASE = $00000004;
  {$EXTERNALSYM FR_FINDNEXT}
  FR_FINDNEXT = $00000008;
  {$EXTERNALSYM FR_REPLACE}
  FR_REPLACE = $00000010;
  {$EXTERNALSYM FR_REPLACEALL}
  FR_REPLACEALL = $00000020;
  {$EXTERNALSYM FR_DIALOGTERM}
  FR_DIALOGTERM = $00000040;
  {$EXTERNALSYM FR_SHOWHELP}
  FR_SHOWHELP = $00000080;
  {$EXTERNALSYM FR_ENABLEHOOK}
  FR_ENABLEHOOK = $00000100;
  {$EXTERNALSYM FR_ENABLETEMPLATE}
  FR_ENABLETEMPLATE = $00000200;
  {$EXTERNALSYM FR_NOUPDOWN}
  FR_NOUPDOWN = $00000400;
  {$EXTERNALSYM FR_NOMATCHCASE}
  FR_NOMATCHCASE = $00000800;
  {$EXTERNALSYM FR_NOWHOLEWORD}
  FR_NOWHOLEWORD = $00001000;
  {$EXTERNALSYM FR_ENABLETEMPLATEHANDLE}
  FR_ENABLETEMPLATEHANDLE = $00002000;
  {$EXTERNALSYM FR_HIDEUPDOWN}
  FR_HIDEUPDOWN = $00004000;
  {$EXTERNALSYM FR_HIDEMATCHCASE}
  FR_HIDEMATCHCASE = $00008000;
  {$EXTERNALSYM FR_HIDEWHOLEWORD}
  FR_HIDEWHOLEWORD = $00010000;

{$EXTERNALSYM FindTextA}
function FindTextA(var FindReplace: TFindReplaceA): HWND; stdcall;
{$EXTERNALSYM FindTextW}
function FindTextW(var FindReplace: TFindReplaceW): HWND; stdcall;
{$EXTERNALSYM FindText}
function FindText(var FindReplace: TFindReplace): HWND; stdcall;
{$EXTERNALSYM ReplaceTextA}
function ReplaceTextA(var FindReplace: TFindReplaceA): HWND; stdcall;
{$EXTERNALSYM ReplaceTextW}
function ReplaceTextW(var FindReplace: TFindReplaceW): HWND; stdcall;
{$EXTERNALSYM ReplaceText}
function ReplaceText(var FindReplace: TFindReplace): HWND; stdcall;

type
  PChooseFontA = ^TChooseFontA;
  PChooseFontW = ^TChooseFontW;
  PChooseFont = PChooseFontA;
  {$EXTERNALSYM tagCHOOSEFONTA}
  tagCHOOSEFONTA = packed record
    lStructSize: DWORD;
    hWndOwner: HWnd;            { caller's window handle }
    hDC: HDC;                   { printer DC/IC or nil }
    lpLogFont: PLogFontA;     { pointer to a LOGFONT struct }
    iPointSize: Integer;        { 10 * size in points of selected font }
    Flags: DWORD;               { dialog flags }
    rgbColors: COLORREF;        { returned text color }
    lCustData: LPARAM;          { data passed to hook function }
    lpfnHook: function(Wnd: HWND; Message: UINT; wParam: WPARAM; lParam: LPARAM): UINT stdcall;
                                { pointer to hook function }
    lpTemplateName: PAnsiChar;    { custom template name }
    hInstance: HINST;       { instance handle of EXE that contains
                                  custom dialog template }
    lpszStyle: PAnsiChar;         { return the style field here
                                  must be lf_FaceSize or bigger }
    nFontType: Word;            { same value reported to the EnumFonts
                                  call back with the extra fonttype_
                                  bits added }
    wReserved: Word;
    nSizeMin: Integer;          { minimum point size allowed and }
    nSizeMax: Integer;          { maximum point size allowed if
                                  cf_LimitSize is used }
  end;
  {$EXTERNALSYM tagCHOOSEFONTW}
  tagCHOOSEFONTW = packed record
    lStructSize: DWORD;
    hWndOwner: HWnd;            { caller's window handle }
    hDC: HDC;                   { printer DC/IC or nil }
    lpLogFont: PLogFontW;     { pointer to a LOGFONT struct }
    iPointSize: Integer;        { 10 * size in points of selected font }
    Flags: DWORD;               { dialog flags }
    rgbColors: COLORREF;        { returned text color }
    lCustData: LPARAM;          { data passed to hook function }
    lpfnHook: function(Wnd: HWND; Message: UINT; wParam: WPARAM; lParam: LPARAM): UINT stdcall;
                                { pointer to hook function }
    lpTemplateName: PWideChar;    { custom template name }
    hInstance: HINST;       { instance handle of EXE that contains
                                  custom dialog template }
    lpszStyle: PWideChar;         { return the style field here
                                  must be lf_FaceSize or bigger }
    nFontType: Word;            { same value reported to the EnumFonts
                                  call back with the extra fonttype_
                                  bits added }
    wReserved: Word;
    nSizeMin: Integer;          { minimum point size allowed and }
    nSizeMax: Integer;          { maximum point size allowed if
                                  cf_LimitSize is used }
  end;
  {$EXTERNALSYM tagCHOOSEFONT}
  tagCHOOSEFONT = tagCHOOSEFONTA;
  TChooseFontA = tagCHOOSEFONTA;
  TChooseFontW = tagCHOOSEFONTW;
  TChooseFont = TChooseFontA;

{$EXTERNALSYM ChooseFontA}
function ChooseFontA(var ChooseFont: TChooseFontA): Bool; stdcall;
{$EXTERNALSYM ChooseFontW}
function ChooseFontW(var ChooseFont: TChooseFontW): Bool; stdcall;
{$EXTERNALSYM ChooseFont}
function ChooseFont(var ChooseFont: TChooseFont): Bool; stdcall;

const
  {$EXTERNALSYM CF_SCREENFONTS}
  CF_SCREENFONTS = $00000001;
  {$EXTERNALSYM CF_PRINTERFONTS}
  CF_PRINTERFONTS = $00000002;
  {$EXTERNALSYM CF_BOTH}
  CF_BOTH = CF_SCREENFONTS OR CF_PRINTERFONTS;
  {$EXTERNALSYM CF_SHOWHELP}
  CF_SHOWHELP = $00000004;
  {$EXTERNALSYM CF_ENABLEHOOK}
  CF_ENABLEHOOK = $00000008;
  {$EXTERNALSYM CF_ENABLETEMPLATE}
  CF_ENABLETEMPLATE = $00000010;
  {$EXTERNALSYM CF_ENABLETEMPLATEHANDLE}
  CF_ENABLETEMPLATEHANDLE = $00000020;
  {$EXTERNALSYM CF_INITTOLOGFONTSTRUCT}
  CF_INITTOLOGFONTSTRUCT = $00000040;
  {$EXTERNALSYM CF_USESTYLE}
  CF_USESTYLE = $00000080;
  {$EXTERNALSYM CF_EFFECTS}
  CF_EFFECTS = $00000100;
  {$EXTERNALSYM CF_APPLY}
  CF_APPLY = $00000200;
  {$EXTERNALSYM CF_ANSIONLY}
  CF_ANSIONLY = $00000400;
  {$EXTERNALSYM CF_SCRIPTSONLY}
  CF_SCRIPTSONLY = CF_ANSIONLY;
  {$EXTERNALSYM CF_NOVECTORFONTS}
  CF_NOVECTORFONTS = $00000800;
  {$EXTERNALSYM CF_NOOEMFONTS}
  CF_NOOEMFONTS = CF_NOVECTORFONTS;
  {$EXTERNALSYM CF_NOSIMULATIONS}
  CF_NOSIMULATIONS = $00001000;
  {$EXTERNALSYM CF_LIMITSIZE}
  CF_LIMITSIZE = $00002000;
  {$EXTERNALSYM CF_FIXEDPITCHONLY}
  CF_FIXEDPITCHONLY = $00004000;
  {$EXTERNALSYM CF_WYSIWYG}
  CF_WYSIWYG = $00008000; { must also have CF_SCREENFONTS & CF_PRINTERFONTS }
  {$EXTERNALSYM CF_FORCEFONTEXIST}
  CF_FORCEFONTEXIST = $00010000;
  {$EXTERNALSYM CF_SCALABLEONLY}
  CF_SCALABLEONLY = $00020000;
  {$EXTERNALSYM CF_TTONLY}
  CF_TTONLY = $00040000;
  {$EXTERNALSYM CF_NOFACESEL}
  CF_NOFACESEL = $00080000;
  {$EXTERNALSYM CF_NOSTYLESEL}
  CF_NOSTYLESEL = $00100000;
  {$EXTERNALSYM CF_NOSIZESEL}
  CF_NOSIZESEL = $00200000;
  {$EXTERNALSYM CF_SELECTSCRIPT}
  CF_SELECTSCRIPT = $00400000;
  {$EXTERNALSYM CF_NOSCRIPTSEL}
  CF_NOSCRIPTSEL = $00800000;
  {$EXTERNALSYM CF_NOVERTFONTS}
  CF_NOVERTFONTS = $01000000;

{ these are extra nFontType bits that are added to what is returned to the
  EnumFonts callback routine }

  {$EXTERNALSYM SIMULATED_FONTTYPE}
  SIMULATED_FONTTYPE = $8000;
  {$EXTERNALSYM PRINTER_FONTTYPE}
  PRINTER_FONTTYPE = $4000;
  {$EXTERNALSYM SCREEN_FONTTYPE}
  SCREEN_FONTTYPE = $2000;
  {$EXTERNALSYM BOLD_FONTTYPE}
  BOLD_FONTTYPE = $0100;
  {$EXTERNALSYM ITALIC_FONTTYPE}
  ITALIC_FONTTYPE = $0200;
  {$EXTERNALSYM REGULAR_FONTTYPE}
  REGULAR_FONTTYPE = $0400;

  {$EXTERNALSYM OPENTYPE_FONTTYPE}
  OPENTYPE_FONTTYPE = $10000;
  {$EXTERNALSYM TYPE1_FONTTYPE}
  TYPE1_FONTTYPE = $20000;
  {$EXTERNALSYM DSIG_FONTTYPE}
  DSIG_FONTTYPE = $40000;

  {$EXTERNALSYM WM_CHOOSEFONT_GETLOGFONT}
  WM_CHOOSEFONT_GETLOGFONT = WM_USER + 1;
  {$EXTERNALSYM WM_CHOOSEFONT_SETLOGFONT}
  WM_CHOOSEFONT_SETLOGFONT = WM_USER + 101; { removed in 4.0 SDK }
  {$EXTERNALSYM WM_CHOOSEFONT_SETFLAGS}
  WM_CHOOSEFONT_SETFLAGS   = WM_USER + 102; { removed in 4.0 SDK }

{ strings used to obtain unique window message for communication
  between dialog and caller }

  {$EXTERNALSYM LBSELCHSTRING}
  LBSELCHSTRING = 'commdlg_LBSelChangedNotify';
  {$EXTERNALSYM SHAREVISTRING}
  SHAREVISTRING = 'commdlg_ShareViolation';
  {$EXTERNALSYM FILEOKSTRING}
  FILEOKSTRING  = 'commdlg_FileNameOK';
  {$EXTERNALSYM COLOROKSTRING}
  COLOROKSTRING = 'commdlg_ColorOK';
  {$EXTERNALSYM SETRGBSTRING}
  SETRGBSTRING  = 'commdlg_SetRGBColor';
  {$EXTERNALSYM FINDMSGSTRING}
  FINDMSGSTRING = 'commdlg_FindReplace';
  {$EXTERNALSYM HELPMSGSTRING}
  HELPMSGSTRING = 'commdlg_help';

{ HIWORD values for lParam of commdlg_LBSelChangeNotify message }

const
  {$EXTERNALSYM CD_LBSELNOITEMS}
  CD_LBSELNOITEMS = -1;
  {$EXTERNALSYM CD_LBSELCHANGE}
  CD_LBSELCHANGE  = 0;
  {$EXTERNALSYM CD_LBSELSUB}
  CD_LBSELSUB     = 1;
  {$EXTERNALSYM CD_LBSELADD}
  CD_LBSELADD     = 2;

type
  PPrintDlgA = ^TPrintDlgA;
  PPrintDlgW = ^TPrintDlgW;
  PPrintDlg = PPrintDlgA;
  {$EXTERNALSYM tagPDA}
  tagPDA = packed record
    lStructSize: DWORD;
    hWndOwner: HWND;
    hDevMode: HGLOBAL;
    hDevNames: HGLOBAL;
    hDC: HDC;
    Flags: DWORD;
    nFromPage: Word;
    nToPage: Word;
    nMinPage: Word;
    nMaxPage: Word;
    nCopies: Word;
    hInstance: HINST;
    lCustData: LPARAM;
    lpfnPrintHook: function(Wnd: HWND; Message: UINT; wParam: WPARAM; lParam: LPARAM): UINT stdcall;
    lpfnSetupHook: function(Wnd: HWND; Message: UINT; wParam: WPARAM; lParam: LPARAM): UINT stdcall;
    lpPrintTemplateName: PAnsiChar;
    lpSetupTemplateName: PAnsiChar;
    hPrintTemplate: HGLOBAL;
    hSetupTemplate: HGLOBAL;
  end;
  {$EXTERNALSYM tagPDW}
  tagPDW = packed record
    lStructSize: DWORD;
    hWndOwner: HWND;
    hDevMode: HGLOBAL;
    hDevNames: HGLOBAL;
    hDC: HDC;
    Flags: DWORD;
    nFromPage: Word;
    nToPage: Word;
    nMinPage: Word;
    nMaxPage: Word;
    nCopies: Word;
    hInstance: HINST;
    lCustData: LPARAM;
    lpfnPrintHook: function(Wnd: HWND; Message: UINT; wParam: WPARAM; lParam: LPARAM): UINT stdcall;
    lpfnSetupHook: function(Wnd: HWND; Message: UINT; wParam: WPARAM; lParam: LPARAM): UINT stdcall;
    lpPrintTemplateName: PWideChar;
    lpSetupTemplateName: PWideChar;
    hPrintTemplate: HGLOBAL;
    hSetupTemplate: HGLOBAL;
  end;
  {$EXTERNALSYM tagPD}
  tagPD = tagPDA;
  TPrintDlgA = tagPDA;
  TPrintDlgW = tagPDW;
  TPrintDlg = TPrintDlgA;

{$EXTERNALSYM PrintDlgA}
function PrintDlgA(var PrintDlg: TPrintDlgA): Bool; stdcall;
{$EXTERNALSYM PrintDlgW}
function PrintDlgW(var PrintDlg: TPrintDlgW): Bool; stdcall;
{$EXTERNALSYM PrintDlg}
function PrintDlg(var PrintDlg: TPrintDlg): Bool; stdcall;

const
  {$EXTERNALSYM PD_ALLPAGES}
  PD_ALLPAGES = $00000000;
  {$EXTERNALSYM PD_SELECTION}
  PD_SELECTION = $00000001;
  {$EXTERNALSYM PD_PAGENUMS}
  PD_PAGENUMS = $00000002;
  {$EXTERNALSYM PD_NOSELECTION}
  PD_NOSELECTION = $00000004;
  {$EXTERNALSYM PD_NOPAGENUMS}
  PD_NOPAGENUMS = $00000008;
  {$EXTERNALSYM PD_COLLATE}
  PD_COLLATE = $00000010;
  {$EXTERNALSYM PD_PRINTTOFILE}
  PD_PRINTTOFILE = $00000020;
  {$EXTERNALSYM PD_PRINTSETUP}
  PD_PRINTSETUP = $00000040;
  {$EXTERNALSYM PD_NOWARNING}
  PD_NOWARNING = $00000080;
  {$EXTERNALSYM PD_RETURNDC}
  PD_RETURNDC = $00000100;
  {$EXTERNALSYM PD_RETURNIC}
  PD_RETURNIC = $00000200;
  {$EXTERNALSYM PD_RETURNDEFAULT}
  PD_RETURNDEFAULT = $00000400;
  {$EXTERNALSYM PD_SHOWHELP}
  PD_SHOWHELP = $00000800;
  {$EXTERNALSYM PD_ENABLEPRINTHOOK}
  PD_ENABLEPRINTHOOK = $00001000;
  {$EXTERNALSYM PD_ENABLESETUPHOOK}
  PD_ENABLESETUPHOOK = $00002000;
  {$EXTERNALSYM PD_ENABLEPRINTTEMPLATE}
  PD_ENABLEPRINTTEMPLATE = $00004000;
  {$EXTERNALSYM PD_ENABLESETUPTEMPLATE}
  PD_ENABLESETUPTEMPLATE = $00008000;
  {$EXTERNALSYM PD_ENABLEPRINTTEMPLATEHANDLE}
  PD_ENABLEPRINTTEMPLATEHANDLE = $00010000;
  {$EXTERNALSYM PD_ENABLESETUPTEMPLATEHANDLE}
  PD_ENABLESETUPTEMPLATEHANDLE = $00020000;
  {$EXTERNALSYM PD_USEDEVMODECOPIES}
  PD_USEDEVMODECOPIES = $00040000;
  {$EXTERNALSYM PD_USEDEVMODECOPIESANDCOLLATE}
  PD_USEDEVMODECOPIESANDCOLLATE = $00040000;
  {$EXTERNALSYM PD_DISABLEPRINTTOFILE}
  PD_DISABLEPRINTTOFILE = $00080000;
  {$EXTERNALSYM PD_HIDEPRINTTOFILE}
  PD_HIDEPRINTTOFILE = $00100000;
  {$EXTERNALSYM PD_NONETWORKBUTTON}
  PD_NONETWORKBUTTON = $00200000;

type
  PDevNames = ^TDevNames;
  {$EXTERNALSYM tagDEVNAMES}
  tagDEVNAMES = record
    wDriverOffset: Word;
    wDeviceOffset: Word;
    wOutputOffset: Word;
    wDefault: Word;
  end;
  TDevNames = tagDEVNAMES;
  {$EXTERNALSYM DEVNAMES}
  DEVNAMES = tagDEVNAMES;

const
  {$EXTERNALSYM DN_DEFAULTPRN}
  DN_DEFAULTPRN = $0001;

{$EXTERNALSYM CommDlgExtendedError}
function CommDlgExtendedError: DWORD; stdcall;

const
  {$EXTERNALSYM WM_PSD_PAGESETUPDLG}
  WM_PSD_PAGESETUPDLG     = WM_USER;
  {$EXTERNALSYM WM_PSD_FULLPAGERECT}
  WM_PSD_FULLPAGERECT     = WM_USER + 1;
  {$EXTERNALSYM WM_PSD_MINMARGINRECT}
  WM_PSD_MINMARGINRECT    = WM_USER + 2;
  {$EXTERNALSYM WM_PSD_MARGINRECT}
  WM_PSD_MARGINRECT       = WM_USER + 3;
  {$EXTERNALSYM WM_PSD_GREEKTEXTRECT}
  WM_PSD_GREEKTEXTRECT    = WM_USER + 4;
  {$EXTERNALSYM WM_PSD_ENVSTAMPRECT}
  WM_PSD_ENVSTAMPRECT     = WM_USER + 5;
  {$EXTERNALSYM WM_PSD_YAFULLPAGERECT}
  WM_PSD_YAFULLPAGERECT   = WM_USER + 6;

type
  PPageSetupDlgA = ^TPageSetupDlgA;
  PPageSetupDlgW = ^TPageSetupDlgW;
  PPageSetupDlg = PPageSetupDlgA;
  {$EXTERNALSYM tagPSDA}
  tagPSDA = packed record
    lStructSize: DWORD;
    hwndOwner: HWND;
    hDevMode: HGLOBAL;
    hDevNames: HGLOBAL;
    Flags: DWORD;
    ptPaperSize: TPoint;
    rtMinMargin: TRect;
    rtMargin: TRect;
    hInstance: HINST;
    lCustData: LPARAM;
    lpfnPageSetupHook: function(Wnd: HWND; Message: UINT; wParam: WPARAM; lParam: LPARAM): UINT stdcall;
    lpfnPagePaintHook: function(Wnd: HWND; Message: UINT; wParam: WPARAM; lParam: LPARAM): UINT stdcall;
    lpPageSetupTemplateName: PAnsiChar;
    hPageSetupTemplate: HGLOBAL;
  end;
  {$EXTERNALSYM tagPSDW}
  tagPSDW = packed record
    lStructSize: DWORD;
    hwndOwner: HWND;
    hDevMode: HGLOBAL;
    hDevNames: HGLOBAL;
    Flags: DWORD;
    ptPaperSize: TPoint;
    rtMinMargin: TRect;
    rtMargin: TRect;
    hInstance: HINST;
    lCustData: LPARAM;
    lpfnPageSetupHook: function(Wnd: HWND; Message: UINT; wParam: WPARAM; lParam: LPARAM): UINT stdcall;
    lpfnPagePaintHook: function(Wnd: HWND; Message: UINT; wParam: WPARAM; lParam: LPARAM): UINT stdcall;
    lpPageSetupTemplateName: PWideChar;
    hPageSetupTemplate: HGLOBAL;
  end;
  {$EXTERNALSYM tagPSD}
  tagPSD = tagPSDA;
  TPageSetupDlgA = tagPSDA;
  TPageSetupDlgW = tagPSDW;
  TPageSetupDlg = TPageSetupDlgA;

{$EXTERNALSYM PageSetupDlgA}
function PageSetupDlgA(var PgSetupDialog: TPageSetupDlgA): BOOL; stdcall;
{$EXTERNALSYM PageSetupDlgW}
function PageSetupDlgW(var PgSetupDialog: TPageSetupDlgW): BOOL; stdcall;
{$EXTERNALSYM PageSetupDlg}
function PageSetupDlg(var PgSetupDialog: TPageSetupDlg): BOOL; stdcall;

const
  {$EXTERNALSYM PSD_DEFAULTMINMARGINS}
  PSD_DEFAULTMINMARGINS             = $00000000; { default (printer's) }
  {$EXTERNALSYM PSD_INWININIINTLMEASURE}
  PSD_INWININIINTLMEASURE           = $00000000; { 1st of 4 possible }

  {$EXTERNALSYM PSD_MINMARGINS}
  PSD_MINMARGINS                    = $00000001; { use caller's }
  {$EXTERNALSYM PSD_MARGINS}
  PSD_MARGINS                       = $00000002; { use caller's }
  {$EXTERNALSYM PSD_INTHOUSANDTHSOFINCHES}
  PSD_INTHOUSANDTHSOFINCHES         = $00000004; { 2nd of 4 possible }
  {$EXTERNALSYM PSD_INHUNDREDTHSOFMILLIMETERS}
  PSD_INHUNDREDTHSOFMILLIMETERS     = $00000008; { 3rd of 4 possible }
  {$EXTERNALSYM PSD_DISABLEMARGINS}
  PSD_DISABLEMARGINS                = $00000010;
  {$EXTERNALSYM PSD_DISABLEPRINTER}
  PSD_DISABLEPRINTER                = $00000020;
  {$EXTERNALSYM PSD_NOWARNING}
  PSD_NOWARNING                     = $00000080; { must be same as PD_* }
  {$EXTERNALSYM PSD_DISABLEORIENTATION}
  PSD_DISABLEORIENTATION            = $00000100;
  {$EXTERNALSYM PSD_RETURNDEFAULT}
  PSD_RETURNDEFAULT                 = $00000400; { must be same as PD_* }
  {$EXTERNALSYM PSD_DISABLEPAPER}
  PSD_DISABLEPAPER                  = $00000200;
  {$EXTERNALSYM PSD_SHOWHELP}
  PSD_SHOWHELP                      = $00000800; { must be same as PD_* }
  {$EXTERNALSYM PSD_ENABLEPAGESETUPHOOK}
  PSD_ENABLEPAGESETUPHOOK           = $00002000; { must be same as PD_* }
  {$EXTERNALSYM PSD_ENABLEPAGESETUPTEMPLATE}
  PSD_ENABLEPAGESETUPTEMPLATE       = $00008000; { must be same as PD_* }
  {$EXTERNALSYM PSD_ENABLEPAGESETUPTEMPLATEHANDLE}
  PSD_ENABLEPAGESETUPTEMPLATEHANDLE = $00020000; { must be same as PD_* }
  {$EXTERNALSYM PSD_ENABLEPAGEPAINTHOOK}
  PSD_ENABLEPAGEPAINTHOOK           = $00040000;
  {$EXTERNALSYM PSD_DISABLEPAGEPAINTING}
  PSD_DISABLEPAGEPAINTING           = $00080000;
  {$EXTERNALSYM PSD_NONETWORKBUTTON}
  PSD_NONETWORKBUTTON               = $00200000; { must be same as PD_* }


{ Common dialog error return codes }

const
  {$EXTERNALSYM CDERR_DIALOGFAILURE}
  CDERR_DIALOGFAILURE    = $FFFF;

  {$EXTERNALSYM CDERR_GENERALCODES}
  CDERR_GENERALCODES     = $0000;
  {$EXTERNALSYM CDERR_STRUCTSIZE}
  CDERR_STRUCTSIZE       = $0001;
  {$EXTERNALSYM CDERR_INITIALIZATION}
  CDERR_INITIALIZATION   = $0002;
  {$EXTERNALSYM CDERR_NOTEMPLATE}
  CDERR_NOTEMPLATE       = $0003;
  {$EXTERNALSYM CDERR_NOHINSTANCE}
  CDERR_NOHINSTANCE      = $0004;
  {$EXTERNALSYM CDERR_LOADSTRFAILURE}
  CDERR_LOADSTRFAILURE   = $0005;
  {$EXTERNALSYM CDERR_FINDRESFAILURE}
  CDERR_FINDRESFAILURE   = $0006;
  {$EXTERNALSYM CDERR_LOADRESFAILURE}
  CDERR_LOADRESFAILURE   = $0007;
  {$EXTERNALSYM CDERR_LOCKRESFAILURE}
  CDERR_LOCKRESFAILURE   = $0008;
  {$EXTERNALSYM CDERR_MEMALLOCFAILURE}
  CDERR_MEMALLOCFAILURE  = $0009;
  {$EXTERNALSYM CDERR_MEMLOCKFAILURE}
  CDERR_MEMLOCKFAILURE   = $000A;
  {$EXTERNALSYM CDERR_NOHOOK}
  CDERR_NOHOOK           = $000B;
  {$EXTERNALSYM CDERR_REGISTERMSGFAIL}
  CDERR_REGISTERMSGFAIL  = $000C;

  {$EXTERNALSYM PDERR_PRINTERCODES}
  PDERR_PRINTERCODES     = $1000;
  {$EXTERNALSYM PDERR_SETUPFAILURE}
  PDERR_SETUPFAILURE     = $1001;
  {$EXTERNALSYM PDERR_PARSEFAILURE}
  PDERR_PARSEFAILURE     = $1002;
  {$EXTERNALSYM PDERR_RETDEFFAILURE}
  PDERR_RETDEFFAILURE    = $1003;
  {$EXTERNALSYM PDERR_LOADDRVFAILURE}
  PDERR_LOADDRVFAILURE   = $1004;
  {$EXTERNALSYM PDERR_GETDEVMODEFAIL}
  PDERR_GETDEVMODEFAIL   = $1005;
  {$EXTERNALSYM PDERR_INITFAILURE}
  PDERR_INITFAILURE      = $1006;
  {$EXTERNALSYM PDERR_NODEVICES}
  PDERR_NODEVICES        = $1007;
  {$EXTERNALSYM PDERR_NODEFAULTPRN}
  PDERR_NODEFAULTPRN     = $1008;
  {$EXTERNALSYM PDERR_DNDMMISMATCH}
  PDERR_DNDMMISMATCH     = $1009;
  {$EXTERNALSYM PDERR_CREATEICFAILURE}
  PDERR_CREATEICFAILURE  = $100A;
  {$EXTERNALSYM PDERR_PRINTERNOTFOUND}
  PDERR_PRINTERNOTFOUND  = $100B;
  {$EXTERNALSYM PDERR_DEFAULTDIFFERENT}
  PDERR_DEFAULTDIFFERENT = $100C;

  {$EXTERNALSYM CFERR_CHOOSEFONTCODES}
  CFERR_CHOOSEFONTCODES  = $2000;
  {$EXTERNALSYM CFERR_NOFONTS}
  CFERR_NOFONTS          = $2001;
  {$EXTERNALSYM CFERR_MAXLESSTHANMIN}
  CFERR_MAXLESSTHANMIN   = $2002;

  {$EXTERNALSYM FNERR_FILENAMECODES}
  FNERR_FILENAMECODES    = $3000;
  {$EXTERNALSYM FNERR_SUBCLASSFAILURE}
  FNERR_SUBCLASSFAILURE  = $3001;
  {$EXTERNALSYM FNERR_INVALIDFILENAME}
  FNERR_INVALIDFILENAME  = $3002;
  {$EXTERNALSYM FNERR_BUFFERTOOSMALL}
  FNERR_BUFFERTOOSMALL   = $3003;

  {$EXTERNALSYM FRERR_FINDREPLACECODES}
  FRERR_FINDREPLACECODES = $4000;
  {$EXTERNALSYM FRERR_BUFFERLENGTHZERO}
  FRERR_BUFFERLENGTHZERO = $4001;

  {$EXTERNALSYM CCERR_CHOOSECOLORCODES}
  CCERR_CHOOSECOLORCODES = $5000;

implementation

function GetOpenFileNameA;      external 'comdlg32.dll'  name 'GetOpenFileNameA';
function GetOpenFileNameW;      external 'comdlg32.dll'  name 'GetOpenFileNameW';
function GetOpenFileName;      external 'comdlg32.dll'  name 'GetOpenFileNameA';
function GetSaveFileNameA;   external 'comdlg32.dll'  name 'GetSaveFileNameA';
function GetSaveFileNameW;   external 'comdlg32.dll'  name 'GetSaveFileNameW';
function GetSaveFileName;   external 'comdlg32.dll'  name 'GetSaveFileNameA';
function GetFileTitleA;      external 'comdlg32.dll'  name 'GetFileTitleA';
function GetFileTitleW;      external 'comdlg32.dll'  name 'GetFileTitleW';
function GetFileTitle;      external 'comdlg32.dll'  name 'GetFileTitleA';
function ChooseColorA;       external 'comdlg32.dll'  name 'ChooseColorA';
function ChooseColorW;       external 'comdlg32.dll'  name 'ChooseColorW';
function ChooseColor;       external 'comdlg32.dll'  name 'ChooseColorA';
function FindTextA;          external 'comdlg32.dll'  name 'FindTextA';
function FindTextW;          external 'comdlg32.dll'  name 'FindTextW';
function FindText;          external 'comdlg32.dll'  name 'FindTextA';
function ReplaceTextA;       external 'comdlg32.dll'  name 'ReplaceTextA';
function ReplaceTextW;       external 'comdlg32.dll'  name 'ReplaceTextW';
function ReplaceText;       external 'comdlg32.dll'  name 'ReplaceTextA';
function ChooseFontA;        external 'comdlg32.dll'  name 'ChooseFontA';
function ChooseFontW;        external 'comdlg32.dll'  name 'ChooseFontW';
function ChooseFont;        external 'comdlg32.dll'  name 'ChooseFontA';
function PrintDlgA;          external 'comdlg32.dll'  name 'PrintDlgA';
function PrintDlgW;          external 'comdlg32.dll'  name 'PrintDlgW';
function PrintDlg;          external 'comdlg32.dll'  name 'PrintDlgA';
function CommDlgExtendedError; external 'comdlg32.dll'  name 'CommDlgExtendedError';
function PageSetupDlgA;      external 'comdlg32.dll'  name 'PageSetupDlgA';
function PageSetupDlgW;      external 'comdlg32.dll'  name 'PageSetupDlgW';
function PageSetupDlg;      external 'comdlg32.dll'  name 'PageSetupDlgA';

end.

