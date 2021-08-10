{ *************************************************************************** }
{                                                                             }
{ Delphi and Kylix Cross-Platform Visual Component Library                    }
{                                                                             }
{ Copyright (c) 2000, 2001 Borland Software Corporation                       }
{                                                                             }
{ *************************************************************************** }


unit QDialogs;

{$R-,T-,H+,X+}

interface

uses
  {$IFDEF MSWINDOWS} Windows, Messages, ShlObj, ActiveX, CommDlg, {$ENDIF}
  SysUtils, Types, QTypes, Qt, Classes, QGraphics, QControls, QStdCtrls, QForms,
  QExtCtrls;

const

{ Maximum number of custom colors in color dialog }

  MaxCustomColors = 16;

type
  EQtDialogException = class(Exception);

  TDialog = class(TComponent)
  private
    FHelpType: THelpType;
    FHelpContext: THelpContext;
    FHelpKeyword: string;
    FOnClose: TNotifyEvent;
    FOnShow: TNotifyEvent;
    FModal: Boolean;
    FPosition: TPoint;
    FWidth: Integer;
    FHeight: Integer;
    FTitle: WideString;
    FShowing: Boolean;
    FScaleFlags: TScalingFlags;
    procedure SetPosition(const Value: TPoint);
    function GetPosition: TPoint;
    function GetHeight: Integer;
    function GetWidth: Integer;
    procedure SetHeight(const Value: Integer);
    procedure SetWidth(const Value: Integer);
  protected
    procedure DoClose; dynamic;
    function DoExecute: Boolean; virtual; abstract;
    procedure DoShow; dynamic;
    function GetBounds: TRect; virtual; abstract;
    procedure SetBounds(ALeft, ATop, AWidth, AHeight: Integer); virtual; abstract;
    procedure SetTitle(const Value: WideString); virtual;
    property Height: Integer read GetHeight write SetHeight;
    property Modal: Boolean read FModal write FModal;
    property Position: TPoint read GetPosition write SetPosition;
    property Title: WideString read FTitle write SetTitle;
    property Width: Integer read GetWidth write SetWidth;
    property OnClose: TNotifyEvent read FOnClose write FOnClose;
    property OnShow: TNotifyEvent read FOnShow write FOnShow;
  public
    function Execute: Boolean; virtual;
  published
    property HelpType: THelpType read FHelpType write FHelpType default htKeyword;
    property HelpContext: THelpContext read FHelpContext write FHelpContext default 0;
    property HelpKeyword: string read FHelpKeyword write FHelpKeyword;
  end;

  { TQtDialog }

  TQtDialog = class(TDialog)
  private
    FHooks: QObject_hookH;
    FHandle: QDialogH;
{$IFDEF MSWINDOWS}
    FUseNative: Boolean;
    FNativeFlags: Integer;
{$ENDIF}    
    function GetHandle: QDialogH;
    procedure CreateHandle;
    procedure DestroyedHook; cdecl;
    procedure HandleNeeded;
    procedure InvokeHelp;
    function GetHooks: QObject_hookH;
  protected
    function AppEventFilter(Sender: QObjectH; Event: QEventH): Boolean; virtual; cdecl;
    procedure CreateWidget; virtual;
    procedure DestroyWidget;
    procedure InitWidget; virtual;
    function GetBounds: TRect; override;
    procedure HookEvents; virtual;
    function DoExecute: Boolean; override;
    procedure DoShow; override;
    {$IFDEF MSWINDOWS}
    function NativeExecute(Flags: Integer): Boolean; virtual;
    {$ENDIF}
    procedure SetBounds(ALeft, ATop, AWidth, AHeight: Integer); override;
    procedure SetTitle(const Value: WideString); override;
    function EventFilter(Sender: QObjectH; Event: QEventH): Boolean; virtual; cdecl;
    function WidgetFlags: Integer; virtual;
    property Hooks: QObject_hookH read GetHooks write FHooks;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function Execute: Boolean; override;
    function HandleAllocated: Boolean;
    property Handle: QDialogH read GetHandle;
    property Position;
  published
    property Height default 0;
    {$IFDEF MSWINDOWS}
    property NativeFlags: Integer read FNativeFlags write FNativeFlags default 0;
    property UseNativeDialog: Boolean read FUseNative write FUseNative default True;
    {$ENDIF}
    property Width default 0;
  end;

{ TOpenDialog }

  TOpenOption = (ofShowHidden, ofOverwritePrompt, ofNoChangeDir, ofAllowMultiSelect,
    ofExtensionDifferent, ofPathMustExist, ofFileMustExist, ofEnableSizing,
    ofViewDetail);
  TOpenOptions = set of TOpenOption;

  TFileAddEvent = procedure(Sender: TObject; const Filename: string; const Readable,
    Writeable, Executable: Boolean; var CanAdd: Boolean) of object;
  TFileSelectEvent = procedure(Sender: TObject; const Filename: string) of object;
  TDirChangeEvent = procedure(Sender: TObject; const Dir: string) of object;

  TOpenDialog = class(TQtDialog)
  private
    FHistoryList: TStrings;
    FFilter: string;
    FInitialDir: string;
    FSaveDir: string;
    FDefaultExt: string;
    FFileName: TFileName;
    FFiles: TStrings;
    FFilterIndex: Integer;
    FOptions: TOpenOptions;
    FTempFiles: TStringList;
    FTempFilename: string;
    FOnFileAdd: TFileAddEvent;
    FOnFolderChange: TDirChangeEvent;
    FOnSelected: TFileSelectEvent;
    FOnCanClose: TCloseQueryEvent;
    procedure CanCloseHook(canClose: PBoolean); cdecl;
    procedure DirEnteredHook(P1: PWideString); cdecl;
    procedure FileAddHook(Filename: PString; const Readable, Writeable, Executable: Boolean;
      var CanAdd: Boolean); cdecl;
    procedure FilterChangedHook(Index: Integer); cdecl;
    function GetHandle: QClxFileDialogH;
    procedure FileHighlightedHook(P1: PWideString); cdecl;
    procedure SetHistoryList(Value: TStrings);
  protected
    procedure CreateWidget; override;
    procedure DefineProperties(Filer: TFiler); override;
    procedure DoCanClose(var CanClose: Boolean); virtual;
    function DoExecute: Boolean; override;
    function DoFileAdd(const Filename: string; const Readable, Writeable, Executable: Boolean): Boolean; virtual;
    procedure DoFolderChange(const Dir: string); dynamic;
    procedure DoSelected(const Filename: string); dynamic;
    procedure HookEvents; override;
{$IFDEF MSWINDOWS}
    function NativeExecute(Flags: Integer): Boolean; override;
{$ENDIF}
    procedure SetOptions; virtual;
    procedure RetrieveOptions; virtual;
    function WidgetFlags: Integer; override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Refresh;
    property Files: TStrings read FFiles;
    property Handle: QClxFileDialogH read GetHandle;
    property HistoryList: TStrings read FHistoryList write SetHistoryList;
  published
    property DefaultExt: string read FDefaultExt write FDefaultExt;
    property FileName: TFileName read FFileName write FFileName;
    property Filter: string read FFilter write FFilter;
    property FilterIndex: Integer read FFilterIndex write FFilterIndex default 1;
    property InitialDir: string read FInitialDir write FInitialDir;
    property Options: TOpenOptions read FOptions write FOptions default [ofEnableSizing];
    property Height default 350;
    property Title;
    property Width default 550;
    property OnClose;
    property OnCanClose: TCloseQueryEvent read FOnCanClose write FOnCanClose;
    property OnFileAdd: TFileAddEvent read FOnFileAdd write FOnFileAdd;
    property OnFolderChange: TDirChangeEvent read FOnFolderChange write FOnFolderChange;
    property OnSelected: TFileSelectEvent read FOnSelected write FOnSelected;
    property OnShow;
  end;

{ TSaveDialog }

  TSaveDialog = class(TOpenDialog)
  protected
{$IFDEF MSWINDOWS}
    function NativeExecute(Flags: Integer): Boolean; override;
{$ENDIF}
    procedure SetOptions; override;
  public
    constructor Create(AOwner: TComponent); override;
  end;

{ TColorDialog }

  TCustomColors = array[0..MaxCustomColors - 1] of Longint;

  TColorDialog = class(TQtDialog)
  private
    FColor: TColor;
    FCustomColors: TStrings;
    procedure SetCustomColors(Value: TStrings);
  protected
    function DoExecute: Boolean; override;
{$IFDEF MSWINDOWS}
    function NativeExecute(Flags: Integer): Boolean; override;
{$ENDIF}
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  published
    property Color: TColor read FColor write FColor default clBlack;
    property CustomColors: TStrings read FCustomColors write SetCustomColors;
  end;

{ TFontDialog }

  TFontDialog = class(TQtDialog)
  private
    FFont: TFont;
    procedure SetFont(Value: TFont);
  protected
    function DoExecute: Boolean; override;
{$IFDEF MSWINDOWS}
    function NativeExecute(Flags: Integer): Boolean; override;
{$ENDIF}
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  published
    property Font: TFont read FFont write SetFont;
  end;

  TCustomDialog = class;

  TDialogForm = class(TCustomForm)
  private
    FDialog: TCustomDialog;
  public
    procedure InvokeHelp; override;
  end;

  TCustomDialog = class(TDialog)
  private
    FForm: TDialogForm;
    procedure Close(Sender: TObject; var Action: TCloseAction);
  protected
    function CreateForm: TDialogForm; virtual; abstract;
    function DoExecute: Boolean; override;
    procedure DoShow; override;
    procedure DoClose; override;
    function GetBounds: TRect; override;
    procedure SetBounds(ALeft, ATop, AWidth, AHeight: Integer); override;
    procedure SetTitle(const Value: WideString); override;
  public
    function Execute: Boolean; override;
    procedure InvokeHelp;
  end;

{ TFindDialog }

  TFindOption = (frDown, frFindNext, frHideMatchCase, frHideWholeWord,
    frHideUpDown, frMatchCase, frDisableMatchCase, frDisableUpDown,
    frDisableWholeWord, frReplace, frReplaceAll, frWholeWord, frShowHelp);
  TFindOptions = set of TFindOption;

  TFindDialogForm = class(TDialogForm)
  private
    FindEdit: TEdit;
    FindLabel: TLabel;
    WholeWord: TCheckBox;
    MatchCase: TCheckBox;
    Direction: TRadioGroup;
    FindNext: TButton;
    Cancel: TButton;
    Help: TButton;
    DialogUnits: TPoint;
  protected
    procedure ButtonPress(Sender: TObject); virtual;
    procedure CheckboxCheck(Sender: TObject);
    procedure DirectionClick(Sender: TObject);
    procedure EditChanged(Sender: TObject); virtual;
    procedure SetDialogOption(Option: TFindOption; Value: Boolean);
  public
    constructor Create(AOwner: TComponent); override;
  end;

  TFindDialog = class(TCustomDialog)
  private
    FOptions: TFindOptions;
    FOnFind: TNotifyEvent;
    FFindText: WideString;
    procedure SetFindText(const Value: WideString);
  protected
    function CreateForm: TDialogForm; override;
    procedure DoShow; override;
    procedure Find; dynamic;
  public
    constructor Create(AOwner: TComponent); override;
    property Position;
  published
    property FindText: WideString read FFindText write SetFindText;
    property Options: TFindOptions read FOptions write FOptions default [frDown];
    property Title;
    property OnClose;
    property OnFind: TNotifyEvent read FOnFind write FOnFind;
    property OnShow;
  end;

  TReplaceDialogForm = class(TFindDialogForm)
  private
    ReplaceBtn: TButton;
    ReplaceAll: TButton;
    ReplaceEdit: TEdit;
    ReplaceLabel: TLabel;
  protected
    procedure EditChanged(Sender: TObject); override;
    procedure ButtonPress(Sender: TObject); override;
  public
    constructor Create(AOwner: TComponent); override;
  end;

{ TReplaceDialog }

  TReplaceDialog = class(TFindDialog)
  private
    FReplaceText: WideString;
    FOnReplace: TNotifyEvent;
    procedure SetReplaceText(const Value: WideString);
  protected
    function CreateForm: TDialogForm; override;
    procedure DoShow; override;
    procedure Replace; dynamic;
  public
    constructor Create(AOwner: TComponent); override;
  published
    property ReplaceText: WideString read FReplaceText write SetReplaceText;
    property OnReplace: TNotifyEvent read FOnReplace write FOnReplace;
  end;

{ Message dialog }

type
  TMsgDlgType = (mtCustom, mtInformation, mtWarning, mtError, mtConfirmation);
  TMsgDlgBtn = (mbNone, mbOk, mbCancel, mbYes, mbNo, mbAbort, mbRetry, mbIgnore);
  TMsgDlgButtons = set of TMsgDlgBtn;

const
  mbYesNoCancel = [mbYes, mbNo, mbCancel];
  mbYesNo = [mbYes, mbNo];
  mbOKCancel = [mbOK, mbCancel];
  mbAbortRetryIgnore = [mbAbort, mbRetry, mbIgnore];

function MessageDlg(const Msg: WideString; DlgType: TMsgDlgType;
  Buttons: TMsgDlgButtons; HelpCtx: Longint; DefaultBtn: TMsgDlgBtn = mbNone;
  Bitmap: TBitmap = nil): Integer; overload;
function MessageDlg(const Caption: WideString; const Msg: WideString;
  DlgType: TMsgDlgType; Buttons: TMsgDlgButtons; HelpCtx: Longint;
  DefaultBtn: TMsgDlgBtn = mbNone; Bitmap: TBitmap = nil): Integer; overload;
function MessageDlg(const Caption: WideString; const Msg: WideString;
  DlgType: TMsgDlgType; Buttons: TMsgDlgButtons; HelpCtx: Longint;
  X, Y: Integer; DefaultBtn: TMsgDlgBtn = mbNone; Bitmap: TBitmap = nil): Integer; overload;
function MessageDlg(const Caption: WideString; const Msg: WideString;
  DlgType: TMsgDlgType; Button1, Button2, Button3: TMsgDlgBtn; HelpCtx: Longint;
  X, Y: Integer; DefaultBtn: TMsgDlgBtn = mbNone; Bitmap: TBitmap = nil): Integer; overload;

function MessageDlgPos(const Msg: WideString; DlgType: TMsgDlgType;
  Buttons: TMsgDlgButtons; HelpCtx: Longint; X, Y: Integer;
  DefaultBtn: TMsgDlgBtn = mbNone; Bitmap: TBitmap = nil): Integer;

procedure ShowMessage(const Msg: WideString); overload;
procedure ShowMessage(const Msg: WideString; Params: array of const); overload;
procedure ShowMessageFmt(const Msg: WideString; Params: array of const);
procedure ShowMessagePos(const Msg: WideString; X, Y: Integer);

{ Input dialogs }

function InputBox(const ACaption, APrompt, ADefault: WideString): WideString; overload;
function InputBox(const ACaption, APrompt: WideString; ADefault: Integer;
  Min: Integer = Low(Integer); Max: Integer = High(Integer);
  Increment: Integer = 1): Integer; overload;
function InputBox(const ACaption, APrompt: WideString; ADefault: Double;
  Min: Double = Low(Integer); Max: Double = High(Integer);
  Decimals: Integer = 1): Double; overload;

function InputQuery(const ACaption, APrompt: WideString;
  var Value: WideString): Boolean; overload;
function InputQuery(const ACaption, APrompt: WideString;
  var Value: string): Boolean; overload;
function InputQuery(const ACaption, APrompt: WideString; var Value: Integer;
  Min: Integer = Low(Integer); Max: Integer = High(Integer);
  Increment: Integer = 1): Boolean; overload;
function InputQuery(const ACaption, APrompt: WideString; var Value: Double;
  Min: Double = Low(Integer); Max: Double = High(Integer);
  Decimals: Integer = 1): Boolean; overload;

{$IFDEF LINUX}
function SelectDirectory(const Caption: WideString; const Root: string;
  var Directory: string): Boolean;
{$ENDIF}
{$IFDEF MSWINDOWS}
function SelectDirectory(const Caption: string; const Root: WideString;
  out Directory: string): Boolean;
{$ENDIF}

implementation

uses QConsts {$IFDEF LINUX}, DirSel {$ENDIF};

{$R *.res}

var
  CustomColorCount: Integer;

type
  TOpenApplication = class(TApplication);

{$IFDEF LINUX}
function SelectDirectory(const Caption: WideString; const Root: string;
  var Directory: string): Boolean;
var
  Dlg: TDirSelDlg;
begin
  Dlg := TDirSelDlg.Create(Application);
  try
    Dlg.RootDirectory := Root;
    Dlg.Directory := Directory;
    Dlg.Caption := Caption;
    Result := Dlg.ShowModal = mrOK;
    if Result then Directory := Dlg.SelectedDir;
  finally
    Dlg.Free;
  end;
end;
{$ENDIF}

{$IFDEF MSWINDOWS}
type
  PTaskWindow = ^TTaskWindow;
  TTaskWindow = record
    Next: PTaskWindow;
    Window: HWnd;
  end;

var
  TaskActiveWindow: HWnd = 0;
  TaskFirstWindow: HWnd = 0;
  TaskFirstTopMost: HWnd = 0;
  TaskWindowList: PTaskWindow = nil;

function DoDisableWindow(Window: HWnd; Data: Longint): Bool; stdcall;
var
  P: PTaskWindow;
begin
  if (Window <> TaskActiveWindow) and IsWindowVisible(Window) and
    IsWindowEnabled(Window) then
  begin
    New(P);
    P^.Next := TaskWindowList;
    P^.Window := Window;
    TaskWindowList := P;
    EnableWindow(Window, False);
  end;
  Result := True;
end;

procedure EnableTaskWindows(WindowList: Pointer);
var
  P: PTaskWindow;
begin
  while WindowList <> nil do
  begin
    P := WindowList;
    if IsWindow(P^.Window) then EnableWindow(P^.Window, True);
    WindowList := P^.Next;
    Dispose(P);
  end;
end;

function DisableTaskWindows(ActiveWindow: HWnd): Pointer;
var
  SaveActiveWindow: HWND;
  SaveWindowList: Pointer;
begin
  Result := nil;
  SaveActiveWindow := TaskActiveWindow;
  SaveWindowList := TaskWindowList;
  TaskActiveWindow := ActiveWindow;
  TaskWindowList := nil;
  try
    try
      EnumThreadWindows(GetCurrentThreadID, @DoDisableWindow, 0);
      Result := TaskWindowList;
    except
      EnableTaskWindows(TaskWindowList);
      raise;
    end;
  finally
    TaskWindowList := SaveWindowList;
    TaskActiveWindow := SaveActiveWindow;
  end;
end;

var
  CreationControl: TQtDialog = nil;
  WndProcPtrAtom: TAtom = 0;
  InstancePtrAtom: TAtom = 0;

function TaskModalDialog(DialogFunc: Pointer; var DialogData): Bool;
type
  TDialogFunc = function(var DialogData): Bool stdcall;
var
  ActiveWindow: HWnd;
  WindowList: Pointer;
  FPUControlWord: Word;
  AtomText: array[0..31] of Char;
begin
  ActiveWindow := GetActiveWindow;
  WindowList := DisableTaskWindows(0);
  WndProcPtrAtom := GlobalAddAtom(StrFmt(AtomText,
    'WndProcPtr%.8X%.8X', [HInstance, GetCurrentThreadID]));
  InstancePtrAtom := GlobalAddAtom(StrFmt(AtomText,
    'DlgInstancePtr%.8X%.8X', [HInstance, GetCurrentThreadID]));
  try
    asm
      // Avoid FPU control word change in NETRAP.dll, NETAPI32.dll, etc
      FNSTCW  FPUControlWord
    end;
    try
      Result := TDialogFunc(DialogFunc)(DialogData);
    finally
      asm
        FNCLEX
        FLDCW FPUControlWord
      end;
    end;
  finally
    if WndProcPtrAtom <> 0 then GlobalDeleteAtom(WndProcPtrAtom);
    if InstancePtrAtom <> 0 then GlobalDeleteAtom(WndProcPtrAtom);
    EnableTaskWindows(WindowList);
    SetActiveWindow(ActiveWindow);
  end;
end;

{ Open and Save dialog routines for Windows native dialog }

procedure GetFileNames(OpenDialog: TOpenDialog; var OpenFileName: TOpenFileName);
var
  Separator: Char;

  function ExtractFileName(P: PChar; var S: TFilename): PChar;
  begin
    Result := AnsiStrScan(P, Separator);
    if Result = nil then
    begin
      S := P;
      Result := StrEnd(P);
    end
    else
    begin
      SetString(S, P, Result - P);
      Inc(Result);
    end;
  end;

  procedure ExtractFileNames(P: PChar);
  var
    DirName, FileName: TFilename;
  begin
    P := ExtractFileName(P, DirName);
    P := ExtractFileName(P, FileName);
    if FileName = '' then
      OpenDialog.FFiles.Add(DirName)
    else
    begin
      if AnsiLastChar(DirName)^ <> '\' then
        DirName := DirName + '\';
      repeat
        if (FileName[1] <> '\') and ((Length(FileName) <= 3) or
          (FileName[2] <> ':') or (FileName[3] <> '\')) then
          FileName := DirName + FileName;
        OpenDialog.FFiles.Add(FileName);
        P := ExtractFileName(P, FileName);
      until FileName = '';
    end;
  end;

begin
  Separator := #0;
  with OpenFileName do
  begin
    if ofAllowMultiSelect in OpenDialog.FOptions then
    begin
      ExtractFileNames(lpstrFile);
      OpenDialog.FFileName := OpenDialog.FFiles[0];
    end else
    begin
      ExtractFileName(lpstrFile, OpenDialog.FFileName);
      OpenDialog.FFiles.Add(OpenDialog.FFileName);
    end;
  end;
end;

function OpenWndProc(Wnd: HWND; Msg, WParam, LParam: Longint): Longint; stdcall;

  function StrRetToString(PIDL: PItemIDList; StrRet: TStrRet): string;
  var
    P: PChar;
  begin
    case StrRet.uType of
      STRRET_CSTR:
        SetString(Result, StrRet.cStr, lStrLen(StrRet.cStr));
      STRRET_OFFSET:
        begin
          P := @PIDL.mkid.abID[StrRet.uOffset - SizeOf(PIDL.mkid.cb)];
          SetString(Result, P, PIDL.mkid.cb - StrRet.uOffset);
        end;
      STRRET_WSTR:
        Result := StrRet.pOleStr;
    end;
  end;

  function CallDefWndProc: Longint;
  begin
    Result := CallWindowProc(Pointer(GetProp(Wnd,
      MakeIntAtom(WndProcPtrAtom))), Wnd, Msg, WParam, LParam);
  end;

var
  Instance: TOpenDialog;
  CanClose: Boolean;
  Include: Boolean;
  StrRet: TStrRet;
  Path: array[0..MAX_PATH] of Char;
begin
  Result := 0;
  { If not ofOldStyleDialog then DoShow on CDN_INITDONE, not WM_INITDIALOG }
  if (Msg = WM_INITDIALOG) {and not (ofOldStyleDialog in Options) }then Exit;
  Instance := TOpenDialog(GetProp(Wnd, MakeIntAtom(InstancePtrAtom)));
  case Msg of
    WM_NOTIFY:
      case (POFNotify(LParam)^.hdr.code) of
        CDN_FILEOK:
          begin
            CanClose := True;
            GetFileNames(Instance, POFNotify(LParam)^.lpOFN^);
            Instance.DoCanClose(CanClose);
            Instance.FFiles.Clear;
            if not CanClose then
            begin
              Result := 1;
              SetWindowLong(Wnd, DWL_MSGRESULT, Result);//Wnd??
              Exit;
            end;
          end;
        CDN_INITDONE:
          Instance.DoShow;
        CDN_SELCHANGE:
          begin
            SendMessage(GetParent(Longint(Instance.FHandle)), CDM_GETFILEPATH,
              SizeOf(Path), Integer(@Path));
            Instance.DoSelected(Path);
          end;
        CDN_FOLDERCHANGE:
          begin
            SendMessage(GetParent(Longint(Instance.FHandle)), CDM_GETFOLDERPATH,
              SizeOf(Path), Integer(@Path));
            Instance.DoFolderChange(Path);
          end;
        CDN_INCLUDEITEM:
          if (LParam <> 0) and Assigned(Instance.OnFileAdd) then
          begin
            POFNotifyEx(LParam)^.psf.GetDisplayNameOf(POFNotifyEx(LParam)^.pidl, SHGDN_FORPARSING, StrRet);
            Include := Instance.DoFileAdd(StrRetToString(POFNotifyEx(LParam)^.pidl, StrRet), True, True, True);
            Result := Byte(Include);
            Exit;
          end;
      end;
    WM_NCDESTROY:
      begin
        Result := CallDefWndProc;
        Instance.FHandle := nil;
        RemoveProp(Wnd, MakeIntAtom(InstancePtrAtom));
        RemoveProp(Wnd, MakeIntAtom(WndProcPtrAtom));
        Exit;
      end;
  end;
  Result := CallDefWndProc;
end;

function OpenDialogHook(Wnd: HWnd; Msg: UINT; WParam: WPARAM; LParam: LPARAM): UINT; stdcall;
begin
  Result := 0;
  if Msg = WM_INITDIALOG then
  begin
    SetProp(Wnd, MakeIntAtom(InstancePtrAtom), Longint(POpenFileName(LParam)^.lCustData));
    SetProp(Wnd, MakeIntAtom(WndProcPtrAtom), GetWindowLong(Wnd, GWL_WNDPROC));
    TOpenDialog(POpenFileName(LParam)^.lCustData).FHandle := QDialogH(Wnd);
    SetWindowLong(Wnd, GWL_WNDPROC, Longint(@OpenWndProc));
    Result := 1;
  end;
end;

function WinFileDialogExecute(Dialog: TOpenDialog; DlgFunc: Pointer; ODFlags: DWORD): Boolean;
const
  MultiSelectBufferSize = High(Word) - 16;
  OpenOptions: array [TOpenOption] of DWORD = (
    OFN_FORCESHOWHIDDEN, OFN_OVERWRITEPROMPT, OFN_NOCHANGEDIR,
    OFN_ALLOWMULTISELECT, OFN_EXTENSIONDIFFERENT, OFN_PATHMUSTEXIST,
    OFN_FILEMUSTEXIST, OFN_ENABLESIZING, 0);
var
  Option: TOpenOption;
  OpenFilename: TOpenFilename;

  function AllocFilterStr(const S: string): string;
  var
    P, P1: PChar;
    Desc, Mask: string;
    I, J: Integer;
  begin
    { It is assumed the filter string is in CLX (Qt-native) format and needs to
     be translated to what Windows expects }
    Result := '';
    if S <> '' then
    begin
      P := PChar(S);
      P1 := StrPos(P, '|');
      if P1 = nil then
        P1 := P + StrLen(P);

      while P - PChar(S) < Length(S) do
      begin
        SetString(Desc, P, Integer(P1-P));
        I := Pos('(', Desc);
        J := Pos(')', Desc);
        Result := Result + Desc + #0;
        if (I > 0) and (J > 0) and (J > I) then
          Mask := Copy(Desc, I+1, J-I-1)
        else
          Mask := Desc;
        Result := Result + Mask + #0;
        P := P1 + 1;
        P1 := StrPos(P, '|');
        if P1 = nil then
          P1 := P + StrLen(P);
      end;
      Result := Result + #0;
    end;
  end;

var
  TempFilter, TempFilename, TempExt: string;
  ATitle: string;
begin
  Dialog.FFiles.Clear;
  FillChar(OpenFileName, SizeOf(OpenFileName), 0);
  with OpenFilename do
  begin
    if (Win32MajorVersion >= 5) and (Win32Platform = VER_PLATFORM_WIN32_NT) or { Win2k }
    ((Win32Platform = VER_PLATFORM_WIN32_WINDOWS) and (Win32MajorVersion >= 4) and (Win32MinorVersion >= 90)) then { WinME }
      lStructSize := SizeOf(TOpenFilename)
    else
      lStructSize := SizeOf(TOpenFilename) - (SizeOf(DWORD) shl 1) - SizeOf(Pointer); { subtract size of added fields }

    hInstance := SysInit.HInstance;
    TempFilter := AllocFilterStr(Dialog.Filter);
    lpstrFilter := PChar(TempFilter);
    nFilterIndex := Dialog.FilterIndex;
    if ofAllowMultiSelect in Dialog.Options then
      nMaxFile := MultiSelectBufferSize else
      nMaxFile := MAX_PATH;
    SetLength(TempFilename, nMaxFile + 2);
    lpstrFile := PChar(TempFilename);
    FillChar(lpstrFile^, nMaxFile + 2, 0);
    StrLCopy(lpstrFile, PChar(Dialog.FileName), nMaxFile);
    if (Dialog.InitialDir = '') then
      lpstrInitialDir := '.'
    else
      lpstrInitialDir := PChar(Dialog.InitialDir);
    ATitle := Dialog.Title;
    lpstrTitle := PChar(ATitle);
    if ODFlags = 0 then
      Flags := OFN_HIDEREADONLY or OFN_NOREADONLYRETURN
    else
      Flags := ODFlags;
    Flags := Flags or OFN_ENABLEHOOK or OFN_ENABLEINCLUDENOTIFY or OFN_EXPLORER;
    for Option := Low(Option) to High(Option) do
      if Option in Dialog.Options then
        Flags := Flags or OpenOptions[Option];
    TempExt := Dialog.DefaultExt;
    if (TempExt = '') and (Flags and OFN_EXPLORER = 0) then
    begin
      TempExt := ExtractFileExt(Dialog.Filename);
      Delete(TempExt, 1, 1);
    end;
    if TempExt <> '' then lpstrDefExt := PChar(TempExt);
    lCustData := Integer(Dialog);
    lpfnHook := OpenDialogHook;
    hWndOwner := GetActiveWindow;
    Result := TaskModalDialog(DlgFunc, OpenFileName);
    if Result then
    begin
      GetFileNames(Dialog, OpenFilename);
      if (Flags and OFN_EXTENSIONDIFFERENT) <> 0 then
        Include(Dialog.FOptions, ofExtensionDifferent) else
        Exclude(Dialog.FOptions, ofExtensionDifferent);
      Dialog.FFilterIndex := nFilterIndex;
    end;
  end;
end;

{ Font dialog routine for Windows native dialog }

function WinFontDialogExecute(FontDialog: TFontDialog; FDFlags: DWORD = 0): Boolean;
var
  FontCharSetModified: Boolean;

  procedure UpdateFromLogFont(const LogFont: TLogFont);
  var
    Style: TFontStyles;
  begin
    with LogFont do
    begin
      FontDialog.Font.Name := LogFont.lfFaceName;
      FontDialog.Font.Height := LogFont.lfHeight;
      if FontCharsetModified then
        FontDialog.Font.Charset := TFontCharset(LogFont.lfCharSet);
      Style := [];
      with LogFont do
      begin
        if lfWeight > FW_REGULAR then Include(Style, fsBold);
        if lfItalic <> 0 then Include(Style, fsItalic);
        if lfUnderline <> 0 then Include(Style, fsUnderline);
        if lfStrikeOut <> 0 then Include(Style, fsStrikeOut);
      end;
      FontDialog.Font.Style := Style;
    end;
  end;

var
  ChooseFontRec: TChooseFont;
  LogFont: TLogFont;
  OriginalFaceName: string;
begin
  with ChooseFontRec do
  begin
    lStructSize := SizeOf(ChooseFontRec);
    hDC := 0;
    lpLogFont := @LogFont;
    GetObject(QFont_handle(FontDialog.Font.Handle), SizeOf(LogFont), @LogFont);
    OriginalFaceName := LogFont.lfFaceName;
    if FDFlags = 0 then
      Flags := CF_BOTH or CF_EFFECTS
    else
      Flags := FDFlags;
    Flags := Flags or CF_INITTOLOGFONTSTRUCT;
    rgbColors := FontDialog.Font.Color;
    lCustData := 0;
    lpfnHook := nil;
    hWndOwner := GetActiveWindow;
    Result := TaskModalDialog(@ChooseFont, ChooseFontRec);
    if Result then
    begin
      if AnsiCompareText(OriginalFaceName, LogFont.lfFaceName) <> 0 then
        FontCharsetModified := True;
      UpdateFromLogFont(LogFont);
      FontDialog.Font.Color := rgbColors;
    end;
  end;
end;

function WinColorDialogExecute(ColorDialog: TColorDialog; CDFlags: DWORD = 0): Boolean;
var
  ChooseColorRec: TChooseColor;
  CustomColorsArray: TCustomColors;

const
  ColorPrefix = 'Color';

  procedure GetCustomColorsArray;
  var
    I: Integer;
  begin
    for I := 0 to MaxCustomColors - 1 do
      ColorDialog.CustomColors.Values[ColorPrefix + Char(Ord('A') + I)] :=
        Format('%.6x', [CustomColorsArray[I]]);
  end;

  procedure SetCustomColorsArray;
  var
    Value: string;
    I: Integer;
  begin
    for I := 0 to MaxCustomColors - 1 do
    begin
      Value := ColorDialog.CustomColors.Values[ColorPrefix + Char(Ord('A') + I)];
      if Value <> '' then
        CustomColorsArray[I] := StrToInt('$' + Value) else
        CustomColorsArray[I] := -1;
    end;
  end;

begin
  with ChooseColorRec do
  begin
    SetCustomColorsArray;
    lStructSize := SizeOf(ChooseColorRec);
    hInstance := SysInit.HInstance;
    rgbResult := ColorToRGB(ColorDialog.Color);
    lpCustColors := @CustomColorsArray;
    if CDFlags = 0 then
      Flags := CC_FULLOPEN or CC_ANYCOLOR
    else
      Flags := CDFlags;
    Flags := Flags or CC_RGBINIT;
    lpfnHook := nil;
    hWndOwner := GetActiveWindow;
    Result := TaskModalDialog(@ChooseColor, ChooseColorRec);
    if Result then
    begin
      ColorDialog.Color := rgbResult;
      GetCustomColorsArray;
    end;
  end;
end;

function SelectDirectory(const Caption: string; const Root: WideString;
  out Directory: string): Boolean;
var
  WindowList: Pointer;
  BrowseInfo: TBrowseInfo;
  Buffer: PChar;
  RootItemIDList, ItemIDList: PItemIDList;
  ShellMalloc: IMalloc;
  IDesktopFolder: IShellFolder;
  Eaten, Flags: LongWord;
begin
  Result := False;
  Directory := '';
  FillChar(BrowseInfo, SizeOf(BrowseInfo), 0);
  if (ShGetMalloc(ShellMalloc) = S_OK) and (ShellMalloc <> nil) then
  begin
    Buffer := ShellMalloc.Alloc(MAX_PATH);
    try
      RootItemIDList := nil;
      if Root <> '' then
      begin
        SHGetDesktopFolder(IDesktopFolder);
        IDesktopFolder.ParseDisplayName(0, nil,
          POleStr(Root), Eaten, RootItemIDList, Flags);
      end;
      with BrowseInfo do
      begin
        hwndOwner := 0;
        pidlRoot := RootItemIDList;
        pszDisplayName := Buffer;
        lpszTitle := PChar(Caption);
        ulFlags := BIF_RETURNONLYFSDIRS;
      end;
     WindowList := DisableTaskWindows(0);
      try
        ItemIDList := ShBrowseForFolder(BrowseInfo);
      finally
        EnableTaskWindows(WindowList);
      end;
      Result :=  ItemIDList <> nil;
      if Result then
      begin
        ShGetPathFromIDList(ItemIDList, Buffer);
        ShellMalloc.Free(ItemIDList);
        Directory := Buffer;
      end;
    finally
      ShellMalloc.Free(Buffer);
    end;
  end;
end;
{$ENDIF}


function MessageDlg(const Caption: WideString; const Msg: WideString;
  DlgType: TMsgDlgType; Button1, Button2, Button3: TMsgDlgBtn; HelpCtx: Longint;
  X, Y: Integer; DefaultBtn: TMsgDlgBtn = mbNone; Bitmap: TBitmap = nil): Integer; overload;
const
  ConfirmResName = 'MSGDLG_CONFIRM';
  MessageBox_DefaultMask = $100;
  MessageBox_EscapeMask = $200;
var
  MB: QMessageBoxH;
  B1, B2, B3: Integer;
  CaptureControl: TControl;
  Title: WideString;
  FreeBitmap: Boolean;
  DlgParent: QWidgetH;
  DlgLabel: QLabelH;
begin
  if Application.Terminated then
  begin
    Result := -1;
    Exit;
  end;

  FreeBitmap := (Bitmap = nil) and (DlgType = mtConfirmation);
  case DlgType of
    mtCustom: Title := Caption;
    mtInformation: Title := SMsgDlgInformation;
    mtError: Title := SMsgDlgError;
    mtWarning: Title := SMsgDlgWarning;
    mtConfirmation:
      begin
        Title := SMsgDlgConfirm;
        if Bitmap = nil then
        begin
          Bitmap := TBitmap.Create;
          Bitmap.LoadFromResourceName(hInstance, ConfirmResName);
        end;
      end;
  end;

  B1 := Ord(Button1);
  B2 := Ord(Button2);
  B3 := Ord(Button3);

  if Button1 = DefaultBtn then
    B1 := B1 or MessageBox_DefaultMask
  else if Button2 = DefaultBtn then
    B2 := B2 or MessageBox_DefaultMask
  else if Button3 = DefaultBtn then
    B3 := B3 or MessageBox_DefaultMask;

  if DlgType = mtConfirmation then
  begin
    DlgType := mtCustom;
    Bitmap.Transparent := True;
  end;

  if (Screen.ActiveCustomForm <> nil) and Screen.ActiveCustomForm.HandleAllocated then
    DlgParent := Screen.ActiveCustomForm.Handle
  else
    DlgParent := TOpenApplication(Application).AppWidget;

  MB := QMessageBox_create(PWideString(@Title), PWideString(@Msg),
    QMessageBoxIcon(DlgType), B1, B2, B3, DlgParent, nil, True, 0);

  try
    if Bitmap <> nil then
      QMessageBox_setIconPixmap(MB, Bitmap.Handle);
    if (X >= 0) and (Y >= 0) then QDialog_move(MB, X, Y);

    //force wordbreak alignment of dialog label.
    DlgLabel := QLabelH(QObject_child(MB, 'text', nil));
    if DlgLabel <> nil then
      QLabel_setAlignment(DlgLabel, QLabel_alignment(DlgLabel)
        or Integer(AlignmentFlags_WordBreak));

    CaptureControl := GetCaptureControl;
    try
      SetCaptureControl(nil);
      QForms.Application.ModalStarted(nil);
      try
        Result := QDialog_exec(MB);
      finally
        QForms.Application.ModalFinished(nil);
      end;
    finally
      SetCaptureControl(CaptureControl);
    end;
  finally
    QMessageBox_destroy(MB);
    if FreeBitmap then Bitmap.Free;
  end;
end;

function MessageDlg(const Caption: WideString; const Msg: WideString;
  DlgType: TMsgDlgType; Buttons: TMsgDlgButtons; HelpCtx: Longint;
  X, Y: Integer; DefaultBtn: TMsgDlgBtn = mbNone; Bitmap: TBitmap = nil): Integer; overload;
var
  Btns: array[0..2] of TMsgDlgBtn;
  B: TMsgDlgBtn;
  I: Integer;
begin
  I := 0;
  FillChar(Btns, SizeOf(Btns), 0);

  { Button order is hard-coded in Windows. We follow their conventions here. }
  if Buttons = mbYesNoCancel then
  begin
    Btns[0] := mbYes;
    Btns[1] := mbNo;
    Btns[2] := mbCancel;
  end;

  if Buttons = mbYesNo then
  begin
    Btns[0] := mbYes;
    Btns[1] := mbNo;
    Btns[2] := mbNone;
  end;

  if Buttons = mbOkCancel then
  begin
    Btns[0] := mbOk;
    Btns[1] := mbCancel;
    Btns[2] := mbNone;
  end;

  if Buttons = mbAbortRetryIgnore then
  begin
    Btns[0] := mbAbort;
    Btns[1] := mbRetry;
    Btns[2] := mbIgnore;
  end;

  for B := Low(TMsgDlgBtn) to High(TMsgDlgBtn) do
    if B in Buttons then
    begin
      Inc(I);
      if I > Ord(High(TMsgDlgBtn)) then
        raise EInvalidOperation.CreateRes(@STooManyMessageBoxButtons);
    end;

  Result := MessageDlg(Caption, Msg, DlgType, Btns[0], Btns[1], Btns[2],
   HelpCtx, X, Y, DefaultBtn, Bitmap);
end;

function MessageDlg(const Msg: WideString; DlgType: TMsgDlgType;
  Buttons: TMsgDlgButtons; HelpCtx: Longint; DefaultBtn: TMsgDlgBtn = mbNone;
  Bitmap: TBitmap = nil): Integer;
begin
  Result := MessageDlg(Application.Title, Msg, DlgType, Buttons, HelpCtx, -1,
    -1, DefaultBtn, Bitmap);
end;

function MessageDlg(const Caption: WideString; const Msg: WideString;
  DlgType: TMsgDlgType; Buttons: TMsgDlgButtons; HelpCtx: Longint;
  DefaultBtn: TMsgDlgBtn = mbNone; Bitmap: TBitmap = nil): Integer;
begin
  Result := MessageDlg(Caption, Msg, DlgType, Buttons, HelpCtx, -1, -1,
    DefaultBtn, Bitmap);
end;

function MessageDlgPos(const Msg: WideString; DlgType: TMsgDlgType;
  Buttons: TMsgDlgButtons; HelpCtx: Longint; X, Y: Integer;
  DefaultBtn: TMsgDlgBtn = mbNone; Bitmap: TBitmap = nil): Integer;
begin
  Result := MessageDlg(Application.Title, Msg, DlgType, Buttons, HelpCtx,
    X, Y, DefaultBtn, Bitmap);
end;

procedure ShowMessage(const Msg: WideString);
begin
  MessageDlg(Msg, mtCustom, [mbOk], 0);
end;

procedure ShowMessage(const Msg: WideString; Params: array of const);
begin
  ShowMessageFmt(Msg, Params);
end;

procedure ShowMessageFmt(const Msg: WideString; Params: array of const);
begin
  ShowMessage(Format(Msg, Params));
end;

procedure ShowMessagePos(const Msg: WideString; X, Y: Integer);
begin
  MessageDlg(Application.Title, Msg, mtCustom, [mbOk], 0, X, Y);
end;

function InputQuery(const ACaption, APrompt: WideString;
  var Value: WideString): Boolean;
var
  RetVal: WideString;
  CaptureControl: TControl;
begin
  CaptureControl := GetCaptureControl;
  try
    SetCaptureControl(nil);
    QForms.Application.ModalStarted(nil);
    try
      QInputDialog_getText(PWideString(@RetVal), PWideString(@ACaption),
        PWideString(@APrompt), PWideString(@Value), @Result, nil, nil);
      if Result then Value := RetVal;
    finally
      QForms.Application.ModalFinished(nil);
    end;
  finally
    SetCaptureControl(CaptureControl);
  end;
end;

function InputQuery(const ACaption, APrompt: WideString;
  var Value: string): Boolean;
var
  WValue: WideString;
begin
  WValue := Value;
  Result := InputQuery(ACaption, APrompt, WValue);
  if Result then Value := WValue;
end;

function InputQuery(const ACaption, APrompt: WideString; var Value: Integer;
  Min: Integer = Low(Integer); Max: Integer = High(Integer);
  Increment: Integer = 1): Boolean;
var
  RetVal: Integer;
  CaptureControl: TControl;
begin
  CaptureControl := GetCaptureControl;
  try
    SetCaptureControl(nil);
    QForms.Application.ModalStarted(nil);
    try
      RetVal := QInputDialog_getInteger(PWideString(@ACaption),
        PWideString(@APrompt), Value, Min, Max, Increment, @Result, nil, nil);
      if Result then Value := RetVal;
    finally
      QForms.Application.ModalFinished(nil);
    end;
  finally
    SetCaptureControl(CaptureControl);
  end;
end;

function InputQuery(const ACaption, APrompt: WideString; var Value: Double;
  Min: Double = Low(Integer); Max: Double = High(Integer);
  Decimals: Integer = 1): Boolean;
var
  RetVal: Double;
  CaptureControl: TControl;
begin
  CaptureControl := GetCaptureControl;
  try
    SetCaptureControl(nil);
    QForms.Application.ModalStarted(nil);
    try
      RetVal := QInputDialog_getDouble(PWideString(@ACaption), PWideString(@APrompt),
        Value, Min, Max, Decimals, @Result, nil, nil);
      if Result then Value := RetVal;
    finally
      QForms.Application.ModalFinished(nil);
    end;
  finally
    SetCaptureControl(CaptureControl);
  end;
end;

function InputBox(const ACaption, APrompt, ADefault: WideString): WideString;
begin
  Result := ADefault;
  InputQuery(ACaption, APrompt, Result);
end;

function InputBox(const ACaption, APrompt: WideString; ADefault: Integer;
  Min: Integer = Low(Integer); Max: Integer = High(Integer);
  Increment: Integer = 1): Integer;
begin
  Result := ADefault;
  InputQuery(ACaption, APrompt, Result, Min, Max, Increment);
end;

function InputBox(const ACaption, APrompt: WideString; ADefault: Double;
  Min: Double = Low(Integer); Max: Double = High(Integer);
  Decimals: Integer = 1): Double;
begin
  Result := ADefault;
  InputQuery(ACaption, APrompt, Result, Min, Max, Decimals);
end;              

{ TDialog }

procedure TDialog.DoClose;
begin
  FWidth := Width;
  FHeight := Height;
  if Assigned(FOnClose) then FOnClose(Self);
end;

procedure TDialog.DoShow;
begin
  if Assigned(FOnShow) then FOnShow(Self);
end;

function TDialog.Execute: Boolean;
var
  ALeft, ATop, AWidth, AHeight: Integer;
  GrabControl: TControl;
begin
  GrabControl := GetMouseGrabControl;
  try
    SetMouseGrabControl(nil);
    { accept defaults if necessary. }
    if not (sfLeft in FScaleFlags) then ALeft := GetPosition.X else ALeft := FPosition.X;
    if not (sfTop in FScaleFlags) then ATop := GetPosition.Y else ATop := FPosition.Y;
    if not (sfWidth in FScaleFlags) then AWidth := GetWidth else AWidth := FWidth;
    if not (sfHeight in FScaleFlags) then AHeight := GetHeight else AHeight := FHeight;
    SetBounds(ALeft, ATop, AWidth, AHeight);
    Result := DoExecute;
  finally
    SetMouseGrabControl(GrabControl);
  end;
end;

function TDialog.GetHeight: Integer;
begin
  Result := GetBounds.Bottom;
end;

function TDialog.GetPosition: TPoint;
begin
  Result.X := GetBounds.Left;
  Result.Y := GetBounds.Top;
end;

function TDialog.GetWidth: Integer;
begin
  Result := GetBounds.Right;
end;

procedure TDialog.SetHeight(const Value: Integer);
begin
  SetBounds(Position.X, Position.Y, Width, Value);
  Include(FScaleFlags, sfHeight);
end;

procedure TDialog.SetPosition(const Value: TPoint);
begin
  SetBounds(Value.X, Value.Y, Width, Height);
  Include(FScaleFlags, sfLeft);
  Include(FScaleFlags, sfTop);
end;

procedure TDialog.SetTitle(const Value: WideString);
begin
  FTitle := Value;
end;

procedure TDialog.SetWidth(const Value: Integer);
begin
  SetBounds(Position.X, Position.Y, Value, Height);
  Include(FScaleFlags, sfWidth);
end;

{ TQtDialog }

function TQtDialog.AppEventFilter(Sender: QObjectH; Event: QEventH): Boolean;
begin
  Result := False;
  try
    Result := (QEvent_type(Event) = QEventType_KeyPress)
      and (QKeyEvent_key(QKeyEventH(Event)) = Application.HelpKey) and
      (QWidget_topLevelWidget(QWidgetH(Sender)) = Handle);
    if Result then InvokeHelp;
  except
    Application.HandleException(Self);
  end;
end;

constructor TQtDialog.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FModal := True;
  FShowing := False;
{$IFDEF MSWINDOWS}
  FUseNative := True;
{$ENDIF}
end;

procedure TQtDialog.CreateHandle;
begin
{$IFDEF MSWINDOWS}
  if UseNativeDialog then Exit;
{$ENDIF}
  if FHandle = nil then
  begin
    CreateWidget;
    InitWidget;
    HookEvents;
    if (FHandle = nil) then
      raise EQtDialogException.CreateResFmt(@SInvalidCreateWidget, [ClassName]);
    QClxObjectMap_add(QWidgetH(FHandle), Integer(Self));
  end;
end;

procedure TQtDialog.CreateWidget;
begin
  FHandle := QDialog_create(nil, nil, FModal, WidgetFlags);
  FHooks := QWidget_hook_create(FHandle);
end;

procedure TQtDialog.DestroyedHook;
begin
  try
    QClxObjectMap_remove(FHandle);
    FHandle := nil;
    QObject_hook_destroy(FHooks);
    FHooks := nil;
    Application.EnableQtAccelerators := False;
  except
    Application.HandleException(Self);
  end;
end;

function TQtDialog.DoExecute: Boolean;
begin
  QDialog_show(Handle);
  if FModal then
  begin
    try
      Result := QDialog_result(Handle) = Integer(QDialogDialogCode_Accepted);
    finally
      QDialog_destroy(Handle);
    end;
  end
  else
    Result := True;
end;

function TQtDialog.EventFilter(Sender: QObjectH; Event: QEventH): Boolean;
begin
  try
    Result := False;
    case QEvent_type(Event) of
      QEventType_WindowActivate:
        { for modeless Qt dialogs}
        Application.EnableQtAccelerators := True;
      QEventType_WindowDeactivate:
        { for modeless Qt dialogs}
        Application.EnableQtAccelerators := False;
      QEventType_Show:
        begin
          Application.EnableQtAccelerators := True;
          FShowing := True;
          DoShow;
        end;
      QEventType_Hide:
        begin
          Application.EnableQtAccelerators := False;
          DoClose;
          FShowing := False;
        end;
    end;
  except
    Application.HandleException(Self);
    Result := False;
  end;
end;

function TQtDialog.GetHandle: QDialogH;
begin
{$IFDEF MSWINDOWS}
  if not UseNativeDialog then
{$ENDIF}
  HandleNeeded;
  Result := FHandle;
end;

function TQtDialog.GetHooks: QObject_hookH;
begin
  HandleNeeded;
  Result := FHooks;
end;

function TQtDialog.HandleAllocated: Boolean;
begin
  Result := FHandle <> nil;
end;

procedure TQtDialog.HandleNeeded;
begin
  if FHandle = nil then CreateHandle;
end;

procedure TQtDialog.HookEvents;
var
   Method: TMethod;
begin
  if FHooks = nil then
  begin
    Assert(FHandle <> nil);
    FHooks := QObject_hook_create(Handle);
  end;

  TEventFilterMethod(Method) := EventFilter;
  Qt_hook_hook_events(FHooks, Method);

  QObject_destroyed_event(Method) := Self.DestroyedHook;
  QObject_hook_hook_destroyed(FHooks, Method);
end;

procedure TQtDialog.InitWidget;
begin
  Application.EnableQtAccelerators := True;
end;

procedure TQtDialog.InvokeHelp;
begin
  case HelpType of
    htKeyword:
      Application.KeywordHelp(HelpKeyword);
    htContext:
      Application.ContextHelp(HelpContext);
  end;
end;

procedure TQtDialog.SetBounds(ALeft, ATop, AWidth, AHeight: Integer);
begin
  if not (csDesigning in ComponentState) and HandleAllocated then
  begin
    QWidget_move(Handle, ALeft, ATop);
    QWidget_resize(Handle, AWidth, AHeight);
  end;
  FPosition.X := ALeft;
  FPosition.Y := ATop;
  FWidth := AWidth;
  FHeight := AHeight;
end;

procedure TQtDialog.SetTitle(const Value: WideString);
begin
  inherited;
  if {$IFDEF MSWINDOWS} not UseNativeDialog and {$ENDIF} HandleAllocated then
    QWidget_setCaption(Handle, PWideString(@FTitle));
end;

function TQtDialog.WidgetFlags: Integer;
begin
  Result := Integer(WidgetFlags_WStyle_DialogBorder) or
    Integer(WidgetFlags_WStyle_Title) or
    Integer(WidgetFlags_WStyle_Customize) or
    Integer(WidgetFlags_WStyle_SysMenu) or
    Integer(WidgetFlags_WStyle_ContextHelp);
end;

procedure TQtDialog.DestroyWidget;
begin
  if FHandle <> nil then QObject_destroy(FHandle);
  FHandle := nil;
end;

destructor TQtDialog.Destroy;
begin
  if FHandle <> nil then
  begin
    DestroyWidget;
    FHandle := nil;
  end;
  inherited Destroy;
end;

function TQtDialog.GetBounds: TRect;
begin
  if HandleAllocated {$IFDEF MSWINDOWS} and not UseNativeDialog {$ENDIF} then
  begin
    QWidget_geometry(Handle, @Result);
    Result.Right := Result.Right - Result.Left;
    Result.Bottom := Result.Bottom - Result.Top;
  end
  else
    Result := Rect(FPosition.X, FPosition.Y, FWidth, FHeight);
end;

procedure TQtDialog.DoShow;
begin
{$IFDEF MSWINDOWS}
  if not UseNativeDialog then
{$ENDIF}
  QWidget_setCaption(Handle, PWideString(@FTitle));
  inherited;
end;

{$IFDEF MSWINDOWS}
function TQtDialog.NativeExecute(Flags: Integer): Boolean;
begin
  Result := False;
end;
{$ENDIF}

function TQtDialog.Execute: Boolean;
var
  AppHook: QObject_hookH;
  Method: TMethod;
{$IFDEF MSWINDOWS}
  GrabControl: TControl;
{$ENDIF}
begin
{$IFDEF MSWINDOWS}
  if UseNativeDialog then
  begin
    GrabControl := GetMouseGrabControl;
    try
      SetMouseGrabControl(nil);
      Result := NativeExecute(FNativeFlags);
    finally
      SetMouseGrabControl(GrabControl);
    end;
  end
  else
{$ENDIF}
  if FShowing then
  begin
    QWidget_raise(Handle);
    Result := True;
  end
  else
  begin
    Application.ModalStarted(Self);
    try
      HandleNeeded;
      AppHook := QObject_Hook_create(Application.Handle);
      try
        TEventFilterMethod(Method) := AppEventFilter;
        Qt_hook_hook_events(AppHook, Method);
        Result := inherited Execute;
      finally
        QObject_hook_destroy(AppHook);
        if FModal then DestroyWidget;
      end;
    finally
      Application.ModalFinished(Self);
    end;
  end;
end;

{ TOpenDialog }

function ConvertSeparators(const S: string): string;
begin
{$IFDEF MSWINDOWS}
  Result := StringReplace(S, '/', '\', [rfReplaceAll]);
{$ENDIF}
{$IFDEF LINUX}
  Result := S;
{$ENDIF}
end;

procedure TOpenDialog.CanCloseHook(canClose: PBoolean);

  procedure GetFilename;
  var
    WFilename: WideString;
  begin
    QClxFileDialog_selectedFile(Handle, PWideString(@WFilename));
    FFilename := ExpandFileName(ConvertSeparators(WFilename));
    FFiles.Add(FFilename);
  end;

var
  QFilesH: QStringListH;
  I: Integer;
  WS, SelExt, ThisExt: WideString;
begin
  try
    FTempFilename := FFilename;
    FTempFiles.Assign(FFiles);

    if ofAllowMultiSelect in FOptions then
    begin
      QFilesH := QStringList_create;
      try
        QClxFileDialog_selectedFiles(Handle, QFilesH);
        FFiles.Clear;
        if QOpenStringList_count(QOpenStringListH(QFilesH)) = 0 then
          GetFilename
        else
          for I := 0 to QOpenStringList_count(QOpenStringListH(QFilesH)) - 1 do
          begin
            QOpenStringList_value(QOpenStringListH(QFilesH), PWideString(@WS),
              I);
            FFiles.Add(ExpandFileName(ConvertSeparators(WS)));
          end;
      finally
        QStringList_destroy(QFilesH);
      end;
      FFilename := FFiles[0];
    end else
      GetFilename;


    if FDefaultExt <> '' then
    begin
      QClxFileDialog_selectedExt(Handle, @SelExt);
      begin
        if SelExt = '' then
          SelExt := FDefaultExt;
        SelExt := '.' + SelExt;

        if not FileExists(FFilename) then
        begin
          ThisExt := ExtractFileExt(FFilename);
          if Length(ThisExt) > 0 then Delete(ThisExt, 1, 1);
          if not QClxFileDialog_isRegisteredExtension(Handle, @ThisExt)
          and (AnsiCompareStr(ExtractFileExt(FFilename), SelExt) <> 0) then
            FFilename := FFilename + SelExt;
        end;

        for I := 0 to FFiles.Count - 1 do
        begin
          if not FileExists(FFiles[I]) then
          begin
            ThisExt := ExtractFileExt(FFiles[I]);
            if Length(ThisExt) > 0 then Delete(ThisExt, 1, 1);
            if not QClxFileDialog_isRegisteredExtension(Handle, @ThisExt)
            and (AnsiCompareStr(ExtractFileExt(FFiles[I]), SelExt) <> 0) then
              FFiles[I] := FFiles[I] + SelExt;
          end;
        end;
      end;
    end;

    if (Self is TSaveDialog) and (ofOverwritePrompt in Options) and FileExists(FFilename) then
      canClose^ := MessageDlg(Format(SOverwriteCaption, [FFilename]),
        Format(SOverwriteText, [FFilename]), mtWarning, [mbNo, mbYes], 0, mbNo) = mrYes
    else if canClose^ and ((ofPathMustExist in Options) or (ofFileMustExist in Options)) then
      for I := 0 to FFiles.Count - 1 do
      begin
        if ofFileMustExist in Options then
        begin
          canClose^ := FileExists(FFiles[I]);
          if not canClose^ then
          begin
            MessageDlg(Title, Format(SFileMustExist, [FFiles[I]]),
              mtCustom, [mbOk], 0);
            QWidget_show(Handle);
          end;
        end
        else if ofPathMustExist in Options then
        begin
          canClose^ := DirectoryExists(ExtractFilePath(FFiles[I]));
          if not canClose^ then
          begin
            MessageDlg(Title, Format(SPathMustExist, [ExtractFilePath(FFiles[I])]),
              mtCustom, [mbOk], 0);
            QWidget_show(Handle);
          end;
        end;
      end;

    if canClose^ then DoCanClose(canClose^);

    if not canClose^ then
    begin
      FFiles.Assign(FTempFiles);
      FFilename := FTempFilename;
    end;

  except
    Application.HandleException(Self);
  end;
end;

constructor TOpenDialog.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FFiles := TStringList.Create;
  FHistoryList := TStringList.Create;
  FFilterIndex := 1;
  FTitle := SOpen;
  FTempFiles := TStringList.Create;
  FOptions := [ofEnableSizing];
  FWidth := 550;
  FHeight := 350;
end;

procedure TOpenDialog.CreateWidget;
begin
  FHandle := QClxFileDialog_create(nil, True, WidgetFlags);
  FHooks := QClxFileDialog_hook_create(FHandle);
end;

procedure TOpenDialog.DefineProperties(Filer: TFiler);
begin
  inherited DefineProperties(Filer);
end;

destructor TOpenDialog.Destroy;
begin
  FFiles.Free;
  FHistoryList.Free;
  FTempFiles.Free;
  inherited Destroy;
end;

procedure TOpenDialog.DirEnteredHook(P1: PWideString);
begin
  try
    DoFolderChange(ConvertSeparators(P1^));
  except
    Application.HandleException(Self);
  end;
end;

procedure TOpenDialog.DoCanClose(var CanClose: Boolean);
begin
  if Assigned(FOnCanClose) then FOnCanClose(Self, CanClose);
end;

function TOpenDialog.DoExecute: Boolean;
begin
  SetOptions;
  Result := QDialog_exec(Handle) = Integer(QDialogDialogCode_Accepted);
  if Result then RetrieveOptions;
end;

function TOpenDialog.DoFileAdd(const Filename: string; const Readable, Writeable,
  Executable: Boolean): Boolean;
begin
  Result := True;
  if Assigned(FOnFileAdd) then FOnFileAdd(Self, Filename, Readable, Writeable,
    Executable, Result);
end;

procedure TOpenDialog.DoFolderChange(const Dir: string);
begin
  if Assigned(FOnFolderChange) then
    FOnFolderChange(Self, ConvertSeparators(Dir));
end;

procedure TOpenDialog.FileAddHook(Filename: PString; const Readable, Writeable,
  Executable: Boolean; var CanAdd: Boolean);
begin
  if Filename <> nil then
    CanAdd := DoFileAdd(Filename^, Readable, Writeable, Executable);
end;

procedure TOpenDialog.DoSelected(const Filename: string);
begin
  {$IFDEF LINUX}
  FFilename := Filename;
  {$ENDIF}
  if Assigned(FOnSelected) then FOnSelected(Self, Filename);
end;

procedure TOpenDialog.FileHighlightedHook(P1: PWideString);
begin
  try
    DoSelected(ConvertSeparators(P1^));
  except
    Application.HandleException(Self);
  end;
end;

procedure TOpenDialog.FilterChangedHook(Index: Integer);
begin
  FFilterIndex := Index + 1;
end;

function TOpenDialog.GetHandle: QClxFileDialogH;
begin
  HandleNeeded;
  Result := QClxFileDialogH(FHandle);
end;

type
  QClxFileDialog_fileAdd_Event = procedure(Filename: PString; const Readable, Writeable,
    Executable: Boolean; var CanAdd: Boolean) of object cdecl;

procedure TOpenDialog.HookEvents;
var
  Method: TMethod;
begin
  QClxFileDialog_fileHighlighted_Event(Method) := FileHighlightedHook;
  QClxFileDialog_hook_hook_fileHighlighted(QClxFileDialog_hookH(Hooks), Method);
  QClxFileDialog_hook_hook_fileSelected(QClxFileDialog_hookH(Hooks), Method);

  QClxFileDialog_dirEntered_Event(Method) := DirEnteredHook;
  QClxFileDialog_hook_hook_DirEntered(QClxFileDialog_hookH(Hooks), Method);

  QClxFileDialog_closeRequest_Event(Method) := CanCloseHook;
  QClxFileDialog_hook_hook_closeRequest(QClxFileDialog_hookH(Hooks), Method);

  QClxFileDialog_filterChanged_Event(Method) := FilterChangedHook;
  QClxFileDialog_hook_hook_filterChanged(QClxFileDialog_hookH(Hooks), Method);

  if Assigned(FOnFileAdd) then
  begin
    //FileAddHook does not operate off a signal for performance reasons; it's
    //a direct callback which doesn't use emit().
    QClxFileDialog_fileAdd_Event(Method) := FileAddHook;
    QClxFileDialog_hook_addFile(QClxFileDialogH(FHandle), Method);
  end;

  inherited HookEvents;
end;

{$IFDEF MSWINDOWS}
function TOpenDialog.NativeExecute(Flags: Integer): Boolean;
begin
  Result := WinFileDialogExecute(Self, @GetOpenFileName, Flags);
end;
{$ENDIF}

procedure TOpenDialog.Refresh;
begin
  if Handle <> nil then QClxFileDialog_rereadDir(Handle);
end;

procedure TOpenDialog.RetrieveOptions;
var
  ViewMode: QClxFileDialogViewMode;
begin
  if not (ofNoChangeDir in FOptions) then
    FSaveDir := ExtractFilePath(FFilename);
  SetCurrentDir(FSaveDir);

  if AnsiCompareStr(ExtractFileExt(FFilename), FDefaultExt) <> 0 then
    Include(FOptions, ofExtensionDifferent)
  else
    Exclude(FOptions, ofExtensionDifferent);
  ViewMode := QClxFileDialog_viewMode(Handle);
  if ViewMode = QClxFileDialogViewMode_Detail then
    Include(FOptions, ofViewDetail)
  else
    Exclude(FOptions, ofViewDetail);
end;

procedure TOpenDialog.SetHistoryList(Value: TStrings);
begin

end;

procedure TOpenDialog.SetOptions;

  procedure SetFilters;
  var
    QSL: QStringListH;
    P, P0: PChar;
    AFilter: string;
    WFilter: WideString;
  begin
    QClxFileDialog_setFilters(Handle, NullWideStr); // is this necessary?
    QSL := QStringList_create;
    try
      P0 := @FFilter[1];
      if FFilter <> '' then
      begin
        P := AnsiStrScan(PChar(FFilter), '|');
        while P <> nil do
        begin
          SetString(AFilter, P0, P - P0);
          WFilter := AFilter;
          QOpenStringList_append(QOpenStringListH(QSL), PWideString(@WFilter));
          Inc(P);
          P0 := P;
          P := AnsiStrScan(P, '|');
        end;
      end;
      SetString(AFilter, P0, @FFilter[Length(FFilter)+1] - P0);
      //QFileDialog can't handle trailing LFs in a filter string.
      if (Length(AFilter) > 0) and (AFilter[Length(AFilter)] = #10) then
        Delete(AFilter, Length(AFilter), 1);
      WFilter := AFilter;
      QOpenStringList_append(QOpenStringListH(QSL), PWideString(@WFilter));
      QClxFileDialog_setFilters(Handle, QSL);
    finally
      QStringList_destroy(QSL);
    end;
  end;

var
  UseFilename: Boolean;
  FilePath: WideString;
  WInitialDir: WideString;
  WFilename: WideString;
  WDefaultExt: WideString;
begin
  FFiles.Clear;
  FSaveDir := GetCurrentDir;
  WInitialDir := FInitialDir;
  if (Length(WInitialDir) > 0) and (WInitialDir[Length(WInitialDir)] <> PathDelim) then
    WInitialDir := WInitialDir + PathDelim;
  WFilename := FFilename;
  WDefaultExt := FDefaultExt;

  FilePath := ExtractFilePath(WFilename);
  UseFilename := DirectoryExists(FilePath);
  if UseFilename then
    WInitialDir := FilePath;

  QClxFileDialog_setDir(Handle, PWideString(@WInitialDir));
  WFilename := ExtractFileName(WFilename);
  QClxFileDialog_setEditText(Handle, @WFilename);
  QClxFileDialog_setDefaultExt(Handle, @WDefaultExt);

  QWidget_setCaption(Handle, PWideString(@FTitle));

  if ofAllowMultiSelect in FOptions then
    QClxFileDialog_setMode(Handle, QClxFileDialogMode_ExistingFiles)
  else
    QClxFileDialog_setMode(Handle, QClxFileDialogMode_ExistingFile);

  if ofViewDetail in FOptions then
    QClxFileDialog_setViewMode(Handle, QClxFileDialogViewMode_Detail);
  QClxFileDialog_setShowHiddenFiles(Handle, ofShowHidden in FOptions);
  SetFilters;
  QClxFileDialog_setFilterIndex(Handle, FFilterIndex-1);
end;

function TOpenDialog.WidgetFlags: Integer;
begin
  if (ofEnableSizing in Options) then
    Result := 0
  else
    Result := inherited WidgetFlags;
end;

{ TSaveDialog }

constructor TSaveDialog.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FTitle := SSave;
end;

{$IFDEF MSWINDOWS}
function TSaveDialog.NativeExecute(Flags: Integer): Boolean;
begin
  Result := WinFileDialogExecute(Self, @GetSaveFileName, Flags);
end;
{$ENDIF}

procedure TSaveDialog.SetOptions;
begin
  inherited SetOptions;
  QClxFileDialog_setMode(Handle, QClxFileDialogMode_AnyFile);
end;

{ TFontDialog }

constructor TFontDialog.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FFont := TFont.Create;
end;

destructor TFontDialog.Destroy;
begin
  inherited Destroy;
  FFont.Free;
end;

function TFontDialog.DoExecute: Boolean;
var
  QFont: QFontH;
begin
  QFont := QFont_create;
  try
    QFontDialog_getFont(QFont, @Result, FFont.Handle, Screen.ActiveWidget, nil);
    if Result then
    begin
      FFont.Handle := QFont;
      FFont.OwnHandle;
    end;
  finally
    if not Result then QFont_destroy(QFont);
  end;
end;

{$IFDEF MSWINDOWS}
function TFontDialog.NativeExecute(Flags: Integer): Boolean;
begin
  Result := WinFontDialogExecute(Self, Flags);
end;
{$ENDIF}

procedure TFontDialog.SetFont(Value: TFont);
begin
  FFont.Assign(Value);
end;

{ TColorDialog }

constructor TColorDialog.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FCustomColors := TStringList.Create;
end;

destructor TColorDialog.Destroy;
begin
  FCustomColors.Free;
  inherited Destroy;
end;

function TColorDialog.DoExecute: Boolean;
const
  ColorPrefix = 'Color';

  procedure GetCustomColors;
  var
    I: Integer;
    Color: QRgb;
  begin
    Color := 0;
    for I := 0 to CustomColorCount - 1 do
    begin
      QColorDialog_customColor(@Color, I);
      FCustomColors.Values[ColorPrefix + Char(Ord('A') + I)] :=
        Format('%.6x', [Color]);
    end;
  end;

  procedure SetCustomColors;
  var
    Value: string;
    I: Integer;
    CustomColor: QRgb;
  begin
    for I := 0 to CustomColorCount - 1 do
    begin
      Value := FCustomColors.Values[ColorPrefix + Char(Ord('A') + I)];
      if Value <> '' then
        CustomColor := QRgb(StrToInt('$' + Value))
      else
        CustomColor := QRgb(0);
      QColorDialog_setCustomColor(I, @CustomColor);
    end;
  end;

var
  QC: QColorH;
begin
  SetCustomColors;
  QC := QColor_create;
  try
    QColorDialog_getColor(QC, QColor(FColor), Screen.ActiveWidget, nil);
    Result := QColor_isValid(QC);
    if Result then
    begin
      FColor := QColorColor(QC);
      GetCustomColors;
    end;
  finally
    QColor_destroy(QC);
  end;
end;

{$IFDEF MSWINDOWS}
function TColorDialog.NativeExecute(Flags: Integer): Boolean;
begin
  Result := WinColorDialogExecute(Self, Flags);
end;
{$ENDIF}

procedure TColorDialog.SetCustomColors(Value: TStrings);
begin
  FCustomColors.Assign(Value);
end;

{ TDialogForm }

procedure TDialogForm.InvokeHelp;
begin
  if ((HelpType = htKeyword) and (HelpKeyword = '')) or
    ((HelpType = htContext) and (HelpContext = 0)) then
      FDialog.InvokeHelp
  else
    inherited;
end;

{ TCustomDialog }

function TCustomDialog.DoExecute: Boolean;
begin
  Result := True;
  DoShow;
  if FModal then
    Result := FForm.ShowModal = mrOK
  else
    FForm.Show;
end;

procedure TCustomDialog.Close(Sender: TObject; var Action: TCloseAction);
begin
  DoClose;
end;

procedure TCustomDialog.DoClose;
begin
  FWidth := FForm.Width;
  FHeight := FForm.Height;
  FPosition.Y := FForm.Top;
  FPosition.X := FForm.Left;
  inherited;
end;

procedure TCustomDialog.DoShow;
begin
  FForm.Caption := FTitle;
  FForm.OnClose := Self.Close;
  inherited;
end;

procedure TCustomDialog.InvokeHelp;
begin
  case HelpType of
    htKeyword:
      Application.KeywordHelp(HelpKeyword);
    htContext:
      Application.ContextHelp(HelpContext);
  end;
end;

procedure TCustomDialog.SetTitle(const Value: WideString);
begin
  inherited;
  if FForm <> nil then FForm.Caption := Value;
end;

procedure TCustomDialog.SetBounds(ALeft, ATop, AWidth, AHeight: Integer);
begin
  if not (csDesigning in ComponentState) and (FForm <> nil) then
    FForm.SetBounds(ALeft, ATop, AWidth, AHeight);
  FPosition.X := ALeft;
  FPosition.Y := ATop;
  FWidth := AWidth;
  FHeight := AHeight;
end;

function TCustomDialog.GetBounds: TRect;
begin
  if FForm <> nil then
    Result := Rect(FForm.Left, FForm.Top, FForm.Width, FForm.Height)
  else
    Result := Rect(FPosition.X, FPosition.Y, FWidth, FHeight);
end;

function TCustomDialog.Execute: Boolean;
begin
  if FForm = nil then
    FForm := CreateForm;
  Result := inherited Execute;
end;

{ TFindDialog }

constructor TFindDialog.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FModal := False;
  FTitle := SFindTitle;
  FOptions := [frDown];
  Position := Point(Screen.Width div 3, Screen.Height div 3);
end;

function TFindDialog.CreateForm: TDialogForm;
begin
  Result := TFindDialogForm.Create(Self);
  Result.FDialog := Self;
end;

procedure TFindDialog.DoShow;
begin
  with TFindDialogForm(FForm) do
  begin
    FindEdit.Text := FindText;
    ActiveControl := FindEdit;
    WholeWord.Visible := not (frHideWholeWord in FOptions);
    WholeWord.Checked := frWholeWord in FOptions;
    WholeWord.Enabled := not (frDisableWholeWord in FOptions);
    MatchCase.Visible := not (frHideMatchCase in FOptions);
    MatchCase.Checked := frMatchCase in Options;
    MatchCase.Enabled := not (frDisableMatchCase in FOptions);
    if frDown in FOptions then Direction.ItemIndex := 1 else Direction.ItemIndex := 0;
    Direction.Enabled := not (frDisableUpDown in FOptions);
    Direction.Visible := not (frHideUpDown in FOptions);
    Help.Visible := frShowHelp in FOptions;
  end;
  inherited DoShow;
end;

procedure TFindDialog.Find;
begin
  if Assigned(FOnFind) then FOnFind(Self);
end;

type
  TWidgetAccess = class(TWidgetControl);

function TextWidth(Control: TWidgetControl; const Text: WideString): Integer;
var
  FM: QFontMetricsH;
begin
  FM := QFontMetrics_create(TWidgetAccess(Control).Font.Handle);
  try
    QWidget_FontMetrics(Control.Handle, FM);
    Result := QFontMetrics_width(FM, PWideString(@Text), -1);
  finally
    QFontMetrics_destroy(FM);
  end;
end;

procedure TFindDialog.SetFindText(const Value: WideString);
begin
  if FindText <> Value then
  begin
    FFindText := Value;
    if FForm <> nil then 
      TFindDialogForm(FForm).FindEdit.Text := Value;
  end;
end;

{ TFindDialogForm }

procedure TFindDialogForm.ButtonPress(Sender: TObject);
begin
  with TFindDialog(FDialog) do
    if Sender = FindNext then
    begin
      Include(FOptions, frFindNext);
      FFindText := FindEdit.Text;
      Find;
    end
    else if Sender = Cancel then
    begin
      SetDialogOption(frFindNext, False);
      Exclude(FOptions, frFindNext);
      Exclude(FOptions, frReplace);
      Self.Close;
    end;
end;

procedure TFindDialogForm.CheckboxCheck(Sender: TObject);
var
  Option: TFindOption;
begin
  if Sender = WholeWord then
    Option := frWholeWord
  else
    Option := frMatchCase;
  if (Sender as TCheckBox).Checked then
    Include(TFindDialog(FDialog).FOptions, Option)
  else
    Exclude(TFindDialog(FDialog).FOptions, Option);
end;

constructor TFindDialogForm.Create(AOwner: TComponent);
begin
  inherited CreateNew(AOwner);
  BorderStyle := fbsDialog;
  DialogUnits := Types.Point(6, 13);
  SetBounds(FLeft, FTop, MulDiv(245, DialogUnits.x, 4),
    MulDiv(65, DialogUnits.y, 8));
  FindLabel := TLabel.Create(Self);
  with FindLabel do
  begin
    Parent := Self;
    Caption := SFindWhat;
    AutoSize := True;
    SetBounds(MulDiv(5, DialogUnits.y, 8), MulDiv(10, DialogUnits.x, 4),
      TextWidth(FindLabel, Caption), Font.Height + 2);
    Visible := True;
    Name := 'FindLabel';
  end;
  FindEdit := TEdit.Create(Self);
  with FindEdit do
  begin
    Parent := Self;
    HandleNeeded;
    AutoSize := True;
    Left := FindLabel.Left + FindLabel.Width + 5;
    Top := FindLabel.Top + ((FindLabel.Height - Height) div 2);
    Width := MulDiv(135, DialogUnits.x, 4);
    FindLabel.FocusControl := FindEdit;
    Visible := True;
    OnChange := EditChanged;
    AutoSelect := True;
    TabOrder := 0;
//    Name := 'FindEdit';
  end;
  WholeWord := TCheckBox.Create(Self);
  with WholeWord do
  begin
    Parent := Self;
    Caption := SWholeWord;
    Left := FindLabel.Left;
    Top := MulDiv(30, DialogUnits.y, 8);
    Width := TextWidth(WholeWord, Caption) + 20;
    Height := Font.Height + 2;
    OnClick := CheckBoxCheck;
    Name := 'WholeWordCheckbox';
    TabOrder := 1;
  end;
  MatchCase := TCheckBox.Create(Self);
  with MatchCase do
  begin
    Parent := Self;
    Caption := SMatchCase;
    Left := FindLabel.Left;
    Top := WholeWord.Top + WholeWord.Height + 7;
    Width := TextWidth(MatchCase, Caption) + 20;
    Height := Font.Height + 2;
    OnClick := CheckBoxCheck;
    Name := 'MatchCaseCheckbox';
    TabOrder := 2;
  end;
  Direction := TRadioGroup.Create(Self);
  with Direction do
  begin
    Parent := Self;
    Caption := SDirection;
    Left := WholeWord.Left + WholeWord.Width + 5;
    Top := FindEdit.Top + FindEdit.Height + 5;
    Width := (FindEdit.Left + FindEdit.Width) - Left;
    Height := (MatchCase.Top + MatchCase.Height) - Top + 5;
    Orientation := orHorizontal;
    Items.Add(SUp);
    Items.Add(SDown);
    OnClick := Self.DirectionClick;
    Name := 'DirectionRadioGroup';
    TabStop := True;
    TabOrder := 3;
  end;
  FindNext := TButton.Create(Self);
  with FindNext do
  begin
    Parent := Self;
    Caption := SFindNext;
    Enabled := False;
    Left := FindEdit.Left + FindEdit.Width + 10;
    Top := FindEdit.Top - 1;
    Height := 24;
    Width := 75;
    Default := True;
    OnClick := Self.ButtonPress;
    Visible := True;
    Name := 'FindNextButton';
    TabOrder := 4;
  end;
  Cancel := TButton.Create(Self);
  with Cancel do
  begin
    Parent := Self;
    Caption := SCancel;
    Left := FindNext.Left;
    Top := FindNext.Top + FindNext.Height + 3;
    Width := FindNext.Width;
    Height := FindNext.Height;
    Cancel := True;
    OnClick := Self.ButtonPress;
    Visible := True;
    Name := 'CancelButton';
    TabOrder := 5;
  end;
  Help := TButton.Create(Self);
  with Help do
  begin
    Parent := Self;
    Caption := SHelp;
    Left := FindNext.Left;
    Top := Self.Cancel.Top + Self.Cancel.Height + 3;
    Width := FindNext.Width;
    Height := FindNext.Height;
    OnClick := Self.ButtonPress;
    Name := 'HelpButton';
    TabOrder := 6;
  end;
  Width := FindNext.Left + FindNext.Width + 10;
end;

procedure TFindDialogForm.DirectionClick(Sender: TObject);
begin
  case Direction.ItemIndex of
    0: SetDialogOption(frDown, False);
    1: SetDialogOption(frDown, True);
  end;
end;

procedure TFindDialogForm.EditChanged(Sender: TObject);
begin
  FindNext.Enabled := FindEdit.Text <> '';
end;

procedure TFindDialogForm.SetDialogOption(Option: TFindOption;
  Value: Boolean);
begin
  if Value then
    Include(TFindDialog(FDialog).FOptions, Option)
  else
    Exclude(TFindDialog(FDialog).FOptions, Option);
end;

{ TReplaceDialog }

constructor TReplaceDialog.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FTitle := SReplaceTitle;
end;

function TReplaceDialog.CreateForm: TDialogForm;
begin
  Result := TReplaceDialogForm.Create(Self);
  Result.FDialog := Self;
end;

procedure TReplaceDialog.DoShow;
begin
  with TReplaceDialogForm(FForm) do
    ReplaceEdit.Text := FReplaceText;
  inherited;
end;

procedure TReplaceDialog.Replace;
begin
  if Assigned(FOnReplace) then FOnReplace(Self);
end;

procedure TReplaceDialog.SetReplaceText(const Value: WideString);
begin
  if ReplaceText <> Value then
  begin
    FReplaceText := Value;
    if FForm <> nil then
      TReplaceDialogForm(FForm).ReplaceEdit.Text := FReplaceText;
  end;
end;

{ TReplaceDialogForm }

procedure TReplaceDialogForm.ButtonPress(Sender: TObject);
begin
  if Sender = ReplaceBtn then
  begin
    SetDialogOption(frReplace, True);
    SetDialogOption(frReplaceAll, False);
  end
  else if Sender = ReplaceAll then
  begin
    SetDialogOption(frReplaceAll, True);
    SetDialogOption(frReplace, False);
  end;
  TReplaceDialog(FDialog).FFindText := FindEdit.Text;
  TReplaceDialog(FDialog).FReplaceText := ReplaceEdit.Text;
  if (Sender = ReplaceBtn) or (Sender = ReplaceAll) then
    TReplaceDialog(FDialog).Replace;
  inherited ButtonPress(Sender);
end;

constructor TReplaceDialogForm.Create(AOwner: TComponent);
begin
  inherited;
  Height := MulDiv(95, DialogUnits.y, 8);
  ReplaceBtn := TButton.Create(Self);
  with ReplaceBtn do
  begin
    Parent := Self;
    HandleNeeded;
    SetBounds(Self.Cancel.Left, Self.Cancel.Top, Self.Cancel.Width,
      Self.Cancel.Height);
    Caption := SReplace;
    OnClick := ButtonPress;
    Visible := True;
    Enabled := False;
    Name := 'ReplaceButton';
    TabOrder := 5;
  end;
  ReplaceAll := TButton.Create(Self);
  with ReplaceAll do
  begin
    Parent := Self;
    HandleNeeded;
    SetBounds(FindNext.Left, ReplaceBtn.Top + ReplaceBtn.Height + 3,
      FindNext.Width, FindNext.Height);
    Caption := SReplaceAll;
    OnClick := ButtonPress;
    Visible := True;
    Enabled := False;
    Name := 'ReplaceAllButton';
    TabOrder := 6;
  end;
  ReplaceLabel := TLabel.Create(Self);
  with ReplaceLabel do
  begin
    Parent := Self;
    Caption := SReplaceWith;
    SetBounds(FindLabel.Left, FindEdit.Top + FindEdit.Height + 13,
      TextWidth(ReplaceLabel, ReplaceLabel.Caption), Font.Height + 4);
    Visible := True;
    Name := 'ReplaceLabel';
  end;

  FindEdit.Left := ReplaceLabel.Left + ReplaceLabel.Width + 5;
  FindEdit.Width := MulDiv(125, DialogUnits.x, 4);
  Cancel.Top := ReplaceAll.Top + ReplaceAll.Height + 3;
  WholeWord.Top := MulDiv(50, DialogUnits.Y, 8);
  MatchCase.Top := WholeWord.Top + WholeWord.Height + 10;

  ReplaceEdit := TEdit.Create(Self);
  with ReplaceEdit do
  begin
    Parent := Self;
    HandleNeeded;
    AutoSize := True;
    Left := ReplaceLabel.Left + ReplaceLabel.Width + 5;
    Top := ReplaceLabel.Top + ((ReplaceLabel.Height - Height) div 2);
    Width := FindEdit.Width;
    Visible := True;
    Name := 'ReplaceEdit';
    TabOrder := 1;
  end;
  ReplaceLabel.FocusControl := ReplaceEdit;
  Direction.Top := WholeWord.Top - 5;
  Help.Top := Cancel.Top + Cancel.Height + 3;
end;

procedure TReplaceDialogForm.EditChanged(Sender: TObject);
begin
  inherited EditChanged(Sender);
  ReplaceBtn.Enabled := FindEdit.Text <> '';
  ReplaceAll.Enabled := FindEdit.Text <> '';
end;

initialization
  CustomColorCount := QColorDialog_customCount;
  StartClassGroup(TControl);
  ActivateClassGroup(TControl);
  GroupDescendentsWith(TDialog, TControl);

end.
