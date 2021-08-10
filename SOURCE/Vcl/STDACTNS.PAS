
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{  Copyright (c) 1995-2001 Borland Software Corporation }
{                                                       }
{*******************************************************}

unit StdActns;

{$H+,X+}

interface

uses SysUtils, Classes, ActnList, StdCtrls, Forms, Dialogs;

type

{ Hint actions }

  THintAction = class(TCustomAction)
  public
    constructor Create(AOwner: TComponent); override;
  published
    property Hint;
  end;

{ Edit actions }

  TEditAction = class(TAction)
  private
    FControl: TCustomEdit;
    procedure SetControl(Value: TCustomEdit);
  protected
    function GetControl(Target: TObject): TCustomEdit; virtual;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
  public
    function HandlesTarget(Target: TObject): Boolean; override;
    procedure UpdateTarget(Target: TObject); override;
    property Control: TCustomEdit read FControl write SetControl;
  end;

  TEditCut = class(TEditAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
  end;

  TEditCopy = class(TEditAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
  end;

  TEditPaste = class(TEditAction)
  public
    procedure UpdateTarget(Target: TObject); override;
    procedure ExecuteTarget(Target: TObject); override;
  end;

  TEditSelectAll = class(TEditAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
    procedure UpdateTarget(Target: TObject); override;
  end;

  TEditUndo = class(TEditAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
    procedure UpdateTarget(Target: TObject); override;
  end;

  TEditDelete = class(TEditAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
    { UpdateTarget is required because TEditAction.UpdateTarget specifically
      checks to see if the action is TEditCut or TEditCopy }
    procedure UpdateTarget(Target: TObject); override;
  end;

{ MDI Window actions }

  TWindowAction = class(TAction)
  private
    FForm: TForm;
    procedure SetForm(Value: TForm);
  protected
    function GetForm(Target: TObject): TForm; virtual;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
  public
    constructor Create(AOwner: TComponent); override;
    function HandlesTarget(Target: TObject): Boolean; override;
    procedure UpdateTarget(Target: TObject); override;
    property Form: TForm read FForm write SetForm;
  end;

  TWindowClose = class(TWindowAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
    procedure UpdateTarget(Target: TObject); override;
  end;

  TWindowCascade = class(TWindowAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
  end;

  TWindowTileHorizontal = class(TWindowAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
  end;

  TWindowTileVertical = class(TWindowAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
  end;

  TWindowMinimizeAll = class(TWindowAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
  end;

  TWindowArrange = class(TWindowAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
  end;

{ Help actions }

  THelpAction = class(TAction)
  public
    constructor Create(AOwner: TComponent); override;
    function HandlesTarget(Target: TObject): Boolean; override;
    procedure UpdateTarget(Target: TObject); override;
  end;

  THelpContents = class(THelpAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
  end;

  THelpTopicSearch = class(THelpAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
  end;

  THelpOnHelp = class(THelpAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
  end;

  THelpContextAction = class(THelpAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
    procedure UpdateTarget(Target: TObject); override;
  end;

{ TCommonDialogAction }

  TCommonDialogClass = class of TCommonDialog;

  TCommonDialogAction = class(TCustomAction)
  private
    FExecuteResult: Boolean;
    FOnAccept: TNotifyEvent;
    FOnCancel: TNotifyEvent;
    FBeforeExecute: TNotifyEvent;
  protected
    FDialog: TCommonDialog;
    function GetDialogClass: TCommonDialogClass; virtual;
  public
    constructor Create(AOwner: TComponent); override;
    function Handlestarget(Target: TObject): Boolean; override;
    procedure ExecuteTarget(Target: TObject); override;
    property ExecuteResult: Boolean read FExecuteResult;
    property BeforeExecute: TNotifyEvent read FBeforeExecute write FBeforeExecute;
    property OnAccept: TNotifyEvent read FOnAccept write FOnAccept;
    property OnCancel: TNotifyEvent read FOnCancel write FOnCancel;
  end;

{ File Actions }

  TFileAction = class(TCommonDialogAction)
  private
    function GetFileName: TFileName;
    procedure SetFileName(const Value: TFileName);
  protected
    function GetDialog: TOpenDialog;
    property FileName: TFileName read GetFileName write SetFileName;
  end;

  TFileOpen = class(TFileAction)
  protected
    function GetDialogClass: TCommonDialogClass; override;
  public
    constructor Create(AOwner: TComponent); override;
  published
    property Caption;
    property Dialog: TOpenDialog read GetDialog;
    property Enabled;
    property HelpContext;
    property Hint;
    property ImageIndex;
    property ShortCut;
    property SecondaryShortCuts;
    property Visible;
    property BeforeExecute;
    property OnAccept;
    property OnCancel;
    property OnHint;
  end;

  TFileOpenWith = class(TFileOpen)
  private
    FFileName: TFileName;
  public
    procedure ExecuteTarget(Target: TObject); override;
  published
    property FileName: TFileName read FFileName write FFileName;
    property BeforeExecute;
  end;

  TFileSaveAs = class(TFileAction)
  private
    function GetSaveDialog: TSaveDialog;
  protected
    function GetDialogClass: TCommonDialogClass; override;
  public
    constructor Create(AOwner: TComponent); override;
  published
    property Caption;
    property Dialog: TSaveDialog read GetSaveDialog;
    property Enabled;
    property HelpContext;
    property Hint;
    property ImageIndex;
    property ShortCut;
    property SecondaryShortCuts;
    property Visible;
    property BeforeExecute;
    property OnAccept;
    property OnCancel;
    property OnHint;
  end;

  TFilePrintSetup = class(TCommonDialogAction)
  private
    function GetDialog: TPrinterSetupDialog;
  protected
    function GetDialogClass: TCommonDialogClass; override;
  published
    property Caption;
    property Dialog: TPrinterSetupDialog read GetDialog;
    property Enabled;
    property HelpContext;
    property Hint;
    property ImageIndex;
    property ShortCut;
    property SecondaryShortCuts;
    property Visible;
    property BeforeExecute;
    property OnAccept;
    property OnCancel;
    property OnHint;
  end;

  TFileExit = class(TCustomAction)
  public
    function HandlesTarget(Target: TObject): Boolean; override;
    procedure ExecuteTarget(Target: TObject); override;
  published
    property Caption;
    property Enabled;
    property HelpContext;
    property Hint;
    property ImageIndex;
    property ShortCut;
    property SecondaryShortCuts;
    property Visible;
    property OnHint;
  end;

{ Search Actions }

  TSearchAction = class(TCommonDialogAction)
  protected
    FControl: TCustomEdit;
    FFindFirst: Boolean;
  public
    constructor Create(AOwner: TComponent); override;
    function HandlesTarget(Target: TObject): Boolean; override;
    procedure Search(Sender: TObject); virtual;
    procedure UpdateTarget(Target: TObject); override;
    procedure ExecuteTarget(Target: TObject); override;
  end;

  TSearchFind = class(TSearchAction)
  private
    function GetFindDialog: TFindDialog;
  protected
    function GetDialogClass: TCommonDialogClass; override;
  published
    property Caption;
    property Dialog: TFindDialog read GetFindDialog;
    property Enabled;
    property HelpContext;
    property Hint;
    property ImageIndex;
    property ShortCut;
    property SecondaryShortCuts;
    property Visible;
    property BeforeExecute;
    property OnAccept;
    property OnCancel;
    property OnHint;
  end;

  TSearchReplace = class(TSearchAction)
  private
    procedure Replace(Sender: TObject);
    function GetReplaceDialog: TReplaceDialog;
  protected
    function GetDialogClass: TCommonDialogClass; override;
  public
    procedure ExecuteTarget(Target: TObject); override;
  published
    property Caption;
    property Dialog: TReplaceDialog read GetReplaceDialog;
    property Enabled;
    property HelpContext;
    property Hint;
    property ImageIndex;
    property ShortCut;
    property SecondaryShortCuts;
    property Visible;
    property BeforeExecute;
    property OnAccept;
    property OnCancel;
    property OnHint;
  end;

  TSearchFindFirst = class(TSearchFind)
  public
    constructor Create(AOwner: TComponent); override;
  end;

  TSearchFindNext = class(TCustomAction)
  private
    FSearchFind: TSearchFind;
  public
    constructor Create(AOwner: TComponent); override;
    function HandlesTarget(Target: TObject): Boolean; override;
    procedure UpdateTarget(Target: TObject); override;
    procedure ExecuteTarget(Target: TObject); override;
  published
    property Caption;
    property Enabled;
    property HelpContext;
    property Hint;
    property ImageIndex;
    property SearchFind: TSearchFind read FSearchFind write FSearchFind;
    property ShortCut;
    property SecondaryShortCuts;
    property Visible;
    property OnHint;
  end;

{ TFontEdit }

  TFontEdit = class(TCommonDialogAction)
  private
    function GetDialog: TFontDialog;
  protected
    function GetDialogClass: TCommonDialogClass; override;
  published
    property Caption;
    property Dialog: TFontDialog read GetDialog;
    property Enabled;
    property HelpContext;
    property Hint;
    property ImageIndex;
    property ShortCut;
    property SecondaryShortCuts;
    property Visible;
    property BeforeExecute;
    property OnAccept;
    property OnCancel;
    property OnHint;
  end;

{ TColorSelect }

  TColorSelect = class(TCommonDialogAction)
  private
    function GetDialog: TColorDialog;
  protected
    function GetDialogClass: TCommonDialogClass; override;
  published
    property Caption;
    property Dialog: TColorDialog read GetDialog;
    property Enabled;
    property HelpContext;
    property Hint;
    property ImageIndex;
    property ShortCut;
    property SecondaryShortCuts;
    property Visible;
    property BeforeExecute;
    property OnAccept;
    property OnCancel;
    property OnHint;
  end;

{ TPrintDlg }

  TPrintDlg = class(TCommonDialogAction)
  private
    function GetDialog: TPrintDialog;
  protected
    function Getdialogclass: TCommonDialogClass; override;
  published
    property Caption;
    property Dialog: TPrintDialog read GetDialog;
    property Enabled;
    property HelpContext;
    property Hint;
    property ImageIndex;
    property ShortCut;
    property SecondaryShortCuts;
    property Visible;
    property BeforeExecute;
    property OnAccept;
    property OnCancel;
    property OnHint;
  end;

implementation

uses Windows, Messages, Consts, Clipbrd, StrUtils, ShellAPI;

{ THintAction }

constructor THintAction.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  DisableIfNoHandler := False;
end;

{ TEditAction }

{ TEditAction }

function TEditAction.GetControl(Target: TObject): TCustomEdit;
begin
  { We could hard cast Target as a TCustomEdit since HandlesTarget "should" be
    called before ExecuteTarget and UpdateTarget, however, we're being safe. }
  Result := Target as TCustomEdit;
end;

function TEditAction.HandlesTarget(Target: TObject): Boolean;
begin
  Result := ((Control <> nil) and (Target = Control) or
    (Control = nil) and (Target is TCustomEdit)) and TCustomEdit(Target).Focused;
end;

procedure TEditAction.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (AComponent = Control) then Control := nil;
end;

procedure TEditAction.UpdateTarget(Target: TObject);
begin
  if (Self is TEditCut) or (Self is TEditCopy) then
    Enabled := GetControl(Target).SelLength > 0;
end;

procedure TEditAction.SetControl(Value: TCustomEdit);
begin
  if Value <> FControl then
  begin
    FControl := Value;
    if Value <> nil then Value.FreeNotification(Self);
  end;
end;

{ TEditCopy }

procedure TEditCopy.ExecuteTarget(Target: TObject);
begin
  GetControl(Target).CopyToClipboard;
end;

{ TEditCut }

procedure TEditCut.ExecuteTarget(Target: TObject);
begin
  GetControl(Target).CutToClipboard;
end;

{ TEditPaste }

procedure TEditPaste.ExecuteTarget(Target: TObject);
begin
  GetControl(Target).PasteFromClipboard;
end;

procedure TEditPaste.UpdateTarget(Target: TObject);
begin
  Enabled := Clipboard.HasFormat(CF_TEXT);
end;

{ TEditSelectAll }

procedure TEditSelectAll.ExecuteTarget(Target: TObject);
begin
  GetControl(Target).SelectAll;
end;

procedure TEditSelectAll.UpdateTarget(Target: TObject);
begin
  Enabled := Length(GetControl(Target).Text) > 0;
end;

{ TEditUndo }

procedure TEditUndo.ExecuteTarget(Target: TObject);
begin
  GetControl(Target).Undo;
end;

procedure TEditUndo.UpdateTarget(Target: TObject);
begin
  Enabled := GetControl(Target).CanUndo;
end;

{ TEditDelete }

procedure TEditDelete.ExecuteTarget(Target: TObject);
begin
  GetControl(Target).ClearSelection;
end;

procedure TEditDelete.UpdateTarget(Target: TObject);
begin
  Enabled := GetControl(Target).SelLength > 0;
end;

{ TWindowAction }

function TWindowAction.GetForm(Target: TObject): TForm;
begin
  { We could hard cast Target as a TForm since HandlesTarget "should" be called
    before ExecuteTarget and UpdateTarget, however, we're being safe. }
  Result := (Target as TForm);
end;

function TWindowAction.HandlesTarget(Target: TObject): Boolean;
begin
  Result := ((Form <> nil) and (Target = Form) or
    (Form = nil) and (Target is TForm)) and
    (TForm(Target).FormStyle = fsMDIForm);
end;

procedure TWindowAction.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (AComponent = Form) then Form := nil;
end;

procedure TWindowAction.UpdateTarget(Target: TObject);
begin
  Enabled := GetForm(Target).MDIChildCount > 0;
end;

procedure TWindowAction.SetForm(Value: TForm);
begin
  if Value <> FForm then
  begin
    FForm := Value;
    if Value <> nil then Value.FreeNotification(Self);
  end;
end;

constructor TWindowAction.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  DisableIfNoHandler := False;
  Enabled := csDesigning in ComponentState;
end;

{ TWindowClose }

procedure TWindowClose.ExecuteTarget(Target: TObject);
begin
  with GetForm(Target) do
    if ActiveMDIChild <> nil then ActiveMDIChild.Close;
end;

procedure TWindowClose.UpdateTarget(Target: TObject);
begin
  Enabled := GetForm(Target).ActiveMDIChild <> nil;
end;

{ TWindowCascade }

procedure TWindowCascade.ExecuteTarget(Target: TObject);
begin
  GetForm(Target).Cascade;
end;

{ TWindowTileHorizontal }

procedure DoTile(Form: TForm; TileMode: TTileMode);
const
  TileParams: array[TTileMode] of Word = (MDITILE_HORIZONTAL, MDITILE_VERTICAL);
begin
  if (Form.FormStyle = fsMDIForm) and (Form.ClientHandle <> 0) then
    SendMessage(Form.ClientHandle, WM_MDITILE, TileParams[TileMode], 0);
end;

procedure TWindowTileHorizontal.ExecuteTarget(Target: TObject);
begin
  DoTile(GetForm(Target), tbHorizontal);
end;

{ TWindowTileVertical }

procedure TWindowTileVertical.ExecuteTarget(Target: TObject);
begin
  DoTile(GetForm(Target), tbVertical);
end;

{ TWindowMinimizeAll }

procedure TWindowMinimizeAll.ExecuteTarget(Target: TObject);
var
  I: Integer;
begin
  { Must be done backwards through the MDIChildren array }
  with GetForm(Target) do
    for I := MDIChildCount - 1 downto 0 do
      MDIChildren[I].WindowState := wsMinimized;
end;

{ TWindowArrange }

procedure TWindowArrange.ExecuteTarget(Target: TObject);
begin
  GetForm(Target).ArrangeIcons;
end;

{ THelpAction }

constructor THelpAction.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  DisableIfNoHandler := False;
  Enabled := csDesigning in ComponentState;
end;

function THelpAction.HandlesTarget(Target: TObject): Boolean;
begin
  Result := True;
end;

procedure THelpAction.UpdateTarget(Target: TObject);
begin
  Enabled := Assigned(Application);
end;

{ THelpContents }

procedure THelpContents.ExecuteTarget(Target: TObject);
begin
  Application.HelpCommand(HELP_FINDER, 0);
end;

{ THelpTopicSearch }

procedure THelpTopicSearch.ExecuteTarget(Target: TObject);
begin
  Application.HelpCommand(HELP_FINDER, Integer(PChar('')));
end;

{ THelpOnHelp }

procedure THelpOnHelp.ExecuteTarget(Target: TObject);
begin
  Application.HelpCommand(HELP_HELPONHELP, Integer(PChar('')));
end;

{ THelpContextAction }

procedure THelpContextAction.ExecuteTarget(Target: TObject);
begin
  Application.HelpCommand(HELP_CONTEXT, Screen.ActiveControl.HelpContext);
end;

procedure THelpContextAction.UpdateTarget(Target: TObject);
begin
  Enabled := Assigned(Screen) and Assigned(Screen.ActiveControl) and
    (Screen.ActiveControl.HelpContext <> 0);
end;

{ TCommonDialogAction }

constructor TCommonDialogAction.Create(AOwner: TComponent);
var
  DialogClass: TCommonDialogClass;
begin
  inherited Create(AOwner);
  DialogClass := GetDialogClass;
  if Assigned(DialogClass) then
  begin
    FDialog := DialogClass.Create(Self);
    FDialog.Name := Copy(DialogClass.ClassName, 2, Length(DialogClass.ClassName));
    FDialog.SetSubComponent(True);
  end;
  DisableIfNoHandler := False;
  Enabled := True;
end;

procedure TCommonDialogAction.ExecuteTarget(Target: TObject);
begin
  FExecuteResult := False;
  if Assigned(FDialog) then
  begin
    if Assigned(FBeforeExecute) then
      FBeforeExecute(Self);  
    FExecuteResult := FDialog.Execute;
    if FExecuteResult then
    begin
      if Assigned(FOnAccept) then
        FOnAccept(Self)
    end
    else
      if Assigned(FOnCancel) then
        FOnCancel(Self);
  end;
end;

function TCommonDialogAction.GetDialogClass: TCommonDialogClass;
begin
  Result := nil;
end;

function TCommonDialogAction.Handlestarget(Target: TObject): Boolean;
begin
  Result := True;
end;

{ TFileAction }

function TFileAction.GetDialog: TOpenDialog;
begin
  Result := TOpenDialog(FDialog);
end;

function TFileAction.GetFileName: TFileName;
begin
  Result := GetDialog.FileName;
end;

procedure TFileAction.SetFileName(const Value: TFileName);
begin
  GetDialog.FileName := Value;
end;

{ TFileOpen }

constructor TFileOpen.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FDialog.Name := 'OpenDialog';
end;

function TFileOpen.GetDialogClass: TCommonDialogClass;
begin
  Result := TOpenDialog;
end;

{ TFileOpenWith }

procedure TFileOpenWith.ExecuteTarget(Target: TObject);
begin
  if (Length(FFileName) = 0) or not FileExists(FFileName) then
    inherited;
  FFileName := Dialog.FileName;
  if FExecuteResult then
    ShellExecute(0, 'open', 'rundll32.exe',                            { do not localize}
      PChar(Format('shell32.dll,OpenAs_RunDLL %s', [FFileName])), nil, { do not localize}
      SW_SHOW);
end;

{ TFileSaveAs }

constructor TFileSaveAs.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FDialog.Name := 'SaveDialog';
end;

function TFileSaveAs.GetDialogClass: TCommonDialogClass;
begin
  Result := TSaveDialog;
end;

function TFileSaveAs.GetSaveDialog: TSaveDialog;
begin
  Result := TSaveDialog(FDialog);
end;

{ TFilePrintSetup }

function TFilePrintSetup.GetDialog: TPrinterSetupDialog;
begin
  Result := TPrinterSetupDialog(FDialog);
end;

function TFilePrintSetup.GetDialogClass: TCommonDialogClass;
begin
  Result := TPrinterSetupDialog;
end;

{ TFileExit }

procedure TFileExit.ExecuteTarget(Target: TObject);
begin
  if Assigned(Application.MainForm) then
  begin
    Application.HelpCommand(HELP_QUIT, 0);
    Application.MainForm.Close;
  end;
end;

function TFileExit.HandlesTarget(Target: TObject): Boolean;
begin
  Result := True;
end;

{ SearchEdit scans the text of a TCustomEdit-derived component for a given
  search string.  The search starts at the current caret position in the
  control unless FindFirst is true then the search starts at the beginning.
  The Options parameter determines whether the search runs forward
  (frDown) or backward from the caret position, whether or not the text
  comparison is case sensitive, and whether the matching string must be a
  whole word.  If text is already selected in the control, the search starts
  at the 'far end' of the selection (SelStart if searching backwards, SelEnd
  if searching forwards).  If a match is found, the control's text selection
  is changed to select the found text and the function returns True.  If no
  match is found, the function returns False. }

function SearchEdit(EditControl: TCustomEdit; const SearchString: String;
  Options: TFindOptions; FindFirst: Boolean = False): Boolean;
var
  Buffer, P: PChar;
  Size: Word;
  SearchOptions: TStringSearchOptions;
begin
  Result := False;
  if (Length(SearchString) = 0) then Exit;
  Size := EditControl.GetTextLen;
  if (Size = 0) then Exit;
  Buffer := StrAlloc(Size + 1);
  try
    SearchOptions := [];
    if frDown in Options then
      Include(SearchOptions, soDown);
    if frMatchCase in Options then
      Include(SearchOptions, soMatchCase);
    if frWholeWord in Options then
      Include(SearchOptions, soWholeWord);
    EditControl.GetTextBuf(Buffer, Size + 1);
    if FindFirst then
      P := SearchBuf(Buffer, Size, 0, EditControl.SelLength,
             SearchString, SearchOptions)
    else
      P := SearchBuf(Buffer, Size, EditControl.SelStart, EditControl.SelLength,
             SearchString, SearchOptions);
    if P <> nil then
    begin
      EditControl.SelStart := P - Buffer;
      EditControl.SelLength := Length(SearchString);
      Result := True;
    end;
  finally
    StrDispose(Buffer);
  end;
end;

{ TSearchAction }

constructor TSearchAction.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  TFindDialog(FDialog).OnFind := Search;
  FFindFirst := False;
end;

procedure TSearchAction.ExecuteTarget(Target: TObject);
begin
  FControl := TCustomEdit(Target);
  inherited ExecuteTarget(Target);
end;

function TSearchAction.HandlesTarget(Target: TObject): Boolean;
begin
  Result := Screen.ActiveControl is TCustomEdit;
  if not Result then
    Enabled := False;
end;

procedure TSearchAction.Search(Sender: TObject);
begin
  // FControl gets set in ExecuteTarget
  if Assigned(FControl) then
    if not SearchEdit(FControl, TFindDialog(FDialog).FindText,
       TFindDialog(FDialog).Options, FFindFirst) then
      ShowMessage(Format(STextNotFound, [TFindDialog(FDialog).FindText]));
  FControl := nil;
end;

procedure TSearchAction.UpdateTarget(Target: TObject);
begin
  Enabled := Target is TCustomEdit and (TCustomEdit(Target).GetTextLen > 0);
end;

{ TSearchFind }

function TSearchFind.GetDialogClass: TCommonDialogClass;
begin
  Result := TFindDialog;
end;

function TSearchFind.GetFindDialog: TFindDialog;
begin
  Result := TFindDialog(FDialog);
end;

{ TSearchReplace }

procedure TSearchReplace.ExecuteTarget(Target: TObject);
begin
  inherited ExecuteTarget(Target);
  TReplaceDialog(FDialog).OnReplace := Replace;
end;

function TSearchReplace.GetDialogClass: TCommonDialogClass;
begin
  Result := TReplaceDialog;
end;

function TSearchReplace.GetReplaceDialog: TReplaceDialog;
begin
  Result := TReplaceDialog(FDialog);
end;

procedure TSearchReplace.Replace(Sender: TObject);
var
  Found: Boolean;
begin
  if Assigned(FControl) then
    with Sender as TReplaceDialog do
    begin
      if AnsiCompareText(FControl.SelText, FindText) = 0 then
        FControl.SelText := ReplaceText;
      Found := SearchEdit(FControl, Dialog.FindText, Dialog.Options, FFindFirst);
      while Found and (frReplaceAll in Dialog.Options) do
      begin
        FControl.SelText := ReplaceText;
        Found := SearchEdit(FControl, Dialog.FindText, Dialog.Options, FFindFirst);
      end;
      if (not Found) and (frReplace in Dialog.Options) then
        ShowMessage(Format(STextNotFound, [Dialog.FindText]));
    end;
  FControl := nil;
end;

{ TSearchFindFirst }

constructor TSearchFindFirst.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FFindFirst := True;
end;

{ TSearchFindNext }

constructor TSearchFindNext.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  DisableIfNoHandler := False;
end;

procedure TSearchFindNext.ExecuteTarget(Target: TObject);
begin
  FSearchFind.FControl := TCustomEdit(Target);
  if not Assigned(FSearchFind) then exit;
  FSearchFind.Search(Target);
end;

function TSearchFindNext.HandlesTarget(Target: TObject): Boolean;
begin
  Result := Assigned(FSearchFind) and FSearchFind.Enabled and
    (Length(TFindDialog(FSearchFind.Dialog).FindText) <> 0);
  Enabled := Result;
end;

procedure TSearchFindNext.UpdateTarget(Target: TObject);
begin
  if Assigned(FSearchFind) then
    Enabled := FSearchFind.Enabled and (Length(TFindDialog(FSearchFind.Dialog).FindText) <> 0)
  else
    Enabled := False;
end;

{ TFontEdit }

function TFontEdit.GetDialog: TFontDialog;
begin
  Result := TFontDialog(FDialog);
end;

function TFontEdit.GetDialogClass: TCommonDialogClass;
begin
  Result := TFontDialog;
end;

{ TColorSelect }

function TColorSelect.GetDialog: TColorDialog;
begin
  Result := TColorDialog(FDialog);
end;

function TColorSelect.GetDialogClass: TCommonDialogClass;
begin
  Result := TColorDialog;
end;

{ TPrintDlg }

function TPrintDlg.GetDialog: TPrintDialog;
begin
  Result := TPrintDialog(FDialog);
end;

function TPrintDlg.Getdialogclass: TCommonDialogClass;
begin
  Result := TPrintDialog;
end;

end.
