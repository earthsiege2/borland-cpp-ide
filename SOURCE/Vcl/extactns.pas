
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{  Copyright (c) 1995-2001 Borland Software Corporation }
{                                                       }
{*******************************************************}

unit ExtActns;

interface

uses SysUtils, Windows, Controls, Classes, ComCtrls, Graphics, ActnList, StdActns,
  StdCtrls, ShellAPI, Dialogs, ExtDlgs, Registry, ImgList, UrlMon, ActiveX;

type

{ TFileRun }

  TShowCmd = (scHide, scMaximize, scMinimize, scRestore, scShow, scShowDefault,
    scShowMaximized, scShowMinimized, scShowMinNoActive, scShowNA,
    scShowNoActivate, scShowNormal);

  TCustomFileRun = class(TCustomAction)
  private
    FBrowse: Boolean;
    FDirectory: TFileName;
    FFile: TFileName;
    FHInst: HInst;
    FParentHWnd: THandle;
    FParameters: String;
    FOperation: String;
    FShowCmd: TShowCmd;
    FBrowseDlg: TOpenDialog;
    FParentControl: TWinControl;
    procedure SetBrowseDlg(const Value: TOpenDialog);
    procedure SetParentControl(const Value: TWinControl);
  protected
    procedure Notification(AComponent: TComponent; Operation: TOperation);
      override;
  public
    constructor Create(AOwner: TComponent); override;
    procedure ExecuteTarget(Target: TObject); override;
    function HandlesTarget(Target: TObject): Boolean; override;
    procedure SetupBrowseDialog;
    property HInst: HInst read FHInst;
    procedure UpdateTarget(Target: TObject); override;
    property Browse: Boolean read FBrowse write FBrowse;
    property BrowseDlg: TOpenDialog read FBrowseDlg write SetBrowseDlg;
    property Directory: TFileName read FDirectory write FDirectory;
    property FileName: TFileName read FFile write FFile;
    property Operation: String read FOperation write FOperation;
    property ParentControl: TWinControl read FParentControl write SetParentControl;
    property Parameters: String read FParameters write FParameters;
    property ShowCmd: TShowCmd read FShowCmd write FShowCmd;
  end;

  TFileRun = class(TCustomFileRun)
  published
    property Browse;
    property BrowseDlg;
    property Caption;
    property Directory;
    property Enabled;
    property FileName;
    property HelpContext;
    property Hint;
    property ImageIndex;
    property Operation;
    property ParentControl;
    property Parameters;
    property ShowCmd;
    property ShortCut;
    property SecondaryShortCuts;
    property Visible;
    property OnHint;
  end;

{ TRichEditAction }

  TRichEditAction = class(TEditAction)
  protected
    function CurrText(Edit: TCustomRichEdit): TTextAttributes;
    procedure SetFontStyle(Edit: TCustomRichEdit; Style: TFontStyle);
  public
    constructor Create(AOwner: TComponent); override;
    function HandlesTarget(Target: TObject): Boolean; override;
  end;

{ TRichEditBold }

  TRichEditBold = class(TRichEditAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
    procedure UpdateTarget(Target: TObject); override;
  end;

{ TRichEditItalic }

  TRichEditItalic = class(TRichEditAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
    procedure UpdateTarget(Target: TObject); override;
  end;

{ TRichEditUnderline }

  TRichEditUnderline = class(TRichEditAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
    procedure UpdateTarget(Target: TObject); override;
  end;

{ TRichEditStrikeOut }

  TRichEditStrikeOut = class(TRichEditAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
    procedure UpdateTarget(Target: TObject); override;
  end;

{ TRichEditBullets }

  TRichEditBullets = class(TRichEditAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
    procedure UpdateTarget(Target: TObject); override;
  end;

{ TRichEditAlignLeft }

  TRichEditAlignLeft = class(TRichEditAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
    procedure UpdateTarget(Target: TObject); override;
  end;

{ TRichEditAlignRight }

  TRichEditAlignRight = class(TRichEditAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
    procedure UpdateTarget(Target: TObject); override;
  end;

{ TRichEditAlignCenter }

  TRichEditAlignCenter = class(TRichEditAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
    procedure UpdateTarget(Target: TObject); override;
  end;

{ TTabAction }

  TTabAction = class;
  TValidateTabEvent = procedure(Sender: TTabAction; TabControl: TCustomTabControl;
    var Enabled: Boolean) of object;

  TTabAction = class(TCustomAction)
  private
    FAfterTabChange: TNotifyEvent;
    FBeforeTabChange: TNotifyEvent;
    FEnabled: Boolean;    
    FOnValidateTab: TValidateTabEvent;
    FSkipHiddenTabs: Boolean;
    FTabControl: TCustomTabControl;
    FWrap: Boolean;
  protected
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure SelectNextTab(GoForward: Boolean = True);
  public
    constructor Create(AOwner: TComponent); override;
    function HandlesTarget(Target: TObject): Boolean; override;
    procedure UpdateTarget(Target: TObject); override;
    property SkipHiddenTabs :Boolean read FSkipHiddenTabs write FSkipHiddenTabs default True;
    property TabControl: TCustomTabControl read FTabControl write FTabControl;
    property Wrap: Boolean read FWrap write FWrap default False;
    property BeforeTabChange: TNotifyEvent read FBeforeTabChange write FBeforeTabChange;
    property AfterTabChange: TNotifyEvent read FAfterTabChange write FAfterTabChange;
    property OnValidateTab: TValidateTabEvent read FOnValidateTab write FOnValidateTab;
  end;

{ TPreviousTab }

  TPreviousTab = class(TTabAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
    procedure UpdateTarget(Target: TObject); override;
  published
    property TabControl;
    property Caption;
    property Enabled;
    property HelpContext;
    property Hint;
    property ImageIndex;
    property ShortCut;
    property SkipHiddenTabs;    
    property Visible;
    property Wrap;
    property AfterTabChange;
    property BeforeTabChange;
    property OnHint;
    property OnValidateTab;
  end;

{ TNextTab }

  TNextTab = class(TTabAction)
  private
    FOldCaption: String;
    FLastTabCaption: String;
    FOnFinish: TNotifyEvent;
  public
    procedure ExecuteTarget(Target: TObject); override;
    procedure UpdateTarget(Target: TObject); override;
  published
    property LastTabCaption: String read FLastTabCaption write FLastTabCaption;
    property TabControl;
    property Caption;
    property Enabled;
    property HelpContext;
    property Hint;
    property ImageIndex;
    property ShortCut;
    property SkipHiddenTabs;    
    property Visible;
    property Wrap;
    property AfterTabChange;
    property BeforeTabChange;
    property OnFinish: TNotifyEvent read FOnFinish write FOnFinish;
    property OnHint;
    property OnValidateTab;
  end;

{ TOpenPicture }

  TOpenPicture = class(TCommonDialogAction)
  private
    function GetDialog: TOpenPictureDialog;
  protected
    function Getdialogclass: TCommonDialogClass; override;
  published
    property Dialog: TOpenPictureDialog read GetDialog;
    property Caption;
    property Enabled;
    property HelpContext;
    property Hint;
    property ImageIndex;
    property ShortCut;
    property SecondaryShortCuts;
    property Visible;
    property OnHint;
    property OnUpdate;
    property OnAccept;
    property OnCancel;
  end;

{ TSavePicture }

  TSavePicture = class(TCommonDialogAction)
  private
    function GetDialog: TSavePictureDialog;
  protected
    function Getdialogclass: TCommonDialogClass; override;
  published
    property Dialog: TSavePictureDialog read GetDialog;
    property Caption;
    property Enabled;
    property HelpContext;
    property Hint;
    property ImageIndex;
    property ShortCut;
    property SecondaryShortCuts;
    property Visible;
    property OnHint;
    property OnUpdate;
    property OnAccept;
    property OnCancel;
  end;

{ TURLAction }

  TURLAction = class(TCustomAction)
  private
    FURL: String;
  public
    function HandlesTarget(Target: TObject): Boolean; override;
    procedure UpdateTarget(Target: TObject); override;
  published
    property Caption;
    property Enabled;
    property HelpContext;
    property Hint;
    property ImageIndex;
    property ShortCut;
    property SecondaryShortCuts;
    property Visible;
    property URL: String read FURL write FURL;
    property OnHint;
  end;

{ TBrowserURL }

  TBrowseURL = class(TURLAction)
  public
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
    property URL;
    property OnHint;
  end;

{ TDownLoadURL }

  TURLDownloadStatus = (dsFindingResource, dsConnecting, dsRedirecting,
    dsBeginDownloadData, dsDownloadingData, dsEndDownloadData,
    dsBeginDownloadComponents, dsInstallingComponents,
    dsEndDownloadComponents, dsUsingCachedCopy, dsSendingRequest,
    dsClassIDAvailable, dsMIMETypeAvailable, dsCacheFileNameAvailable,
    dsBeginSyncOperation, dsEndSyncOperation, dsBeginUploadData,
    dsUploadingData, dsEndUploadData, dsProtocolClassID, dsEncoding,
    dsVerifiedMIMETypeAvailable, dsClassInstallLocation, dsDecoding,
    dsLoadingMIMIHandler);

  TDownLoadURL = class;

  TDownloadProgressEvent = procedure(Sender: TDownLoadURL; Progress,
    ProgressMax: Cardinal; StatusCode: TURLDownloadStatus; StatusText: String;
    var Cancel: Boolean) of object;

  TDownLoadURL = class(TURLAction, IBindStatusCallback)
  private
    FOnDownloadProgress: TDownloadProgressEvent;
    FFilename: TFilename;
  protected
    { IBindStatusCallback }
    function GetBindInfo(out grfBINDF: Cardinal;
      var bindinfo: _tagBINDINFO): HRESULT; stdcall;
    function GetPriority(out nPriority): HRESULT; stdcall;
    function OnDataAvailable(grfBSCF: Cardinal; dwSize: Cardinal;
      formatetc: PFormatEtc; stgmed: PStgMedium): HRESULT; stdcall;
    function OnLowResource(reserved: Cardinal): HRESULT; stdcall;
    function OnObjectAvailable(const iid: TGUID; punk: IUnknown): HRESULT; stdcall;
    function OnProgress(ulProgress: Cardinal; ulProgressMax: Cardinal;
      ulStatusCode: Cardinal; szStatusText: PWideChar): HRESULT; stdcall;
    function OnStartBinding(dwReserved: Cardinal; pib: IBinding): HRESULT; stdcall;
    function OnStopBinding(hresult: HRESULT; szError: PWideChar): HRESULT; stdcall;
  public
    procedure ExecuteTarget(Target: TObject); override;
  published
    property Caption;
    property Enabled;
    property Filename: TFilename read FFilename write FFilename;
    property HelpContext;
    property Hint;
    property ImageIndex;
    property ShortCut;
    property SecondaryShortCuts;
    property Visible;
    property URL;
    property OnHint;
    property OnUpdate;
    property OnDownloadProgress: TDownloadProgressEvent read FOnDownloadProgress write FOnDownloadProgress;
  end;

{ TSendMail }

  TSendMail = class(TCustomAction)
  private
    FText: TStrings;
    procedure SetText(const Value: TStrings);
    function GetText: TStrings;
  public
    destructor Destroy; override;
    procedure ExecuteTarget(Target: TObject); override;
    function HandlesTarget(Target: TObject): Boolean; override;
    procedure UpdateTarget(Target: TObject); override;
  published
    property Caption;
    property Enabled;
    property HelpContext;
    property Hint;
    property ImageIndex;
    property ShortCut;
    property SecondaryShortCuts;
    property Text: TStrings read GetText write SetText;
    property Visible;
    property OnHint;
    property OnUpdate;
  end;

{ TListControlAction }

  TListControlAction = class(TCustomAction)
  private
    FListControl: TCustomListControl;
    procedure SetListControl(const Value: TCustomListControl);
  protected
    function IsEnabled(Target: TObject): Boolean;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
  public
    constructor Create(AOwner: TComponent); override;
    function HandlesTarget(Target: TObject): Boolean; override;
    property ListControl: TCustomListControl read FListControl write SetListControl;
  end;

{ TListControlSelectAll }

  TListControlSelectAll = class(TListControlAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
    procedure UpdateTarget(Target: TObject); override;
  published
    property Caption;
    property Enabled;
    property HelpContext;
    property Hint;
    property ImageIndex;
    property ListControl;
    property ShortCut;
    property SecondaryShortCuts;
    property Visible;
    property OnHint;
  end;

{ TListControlClearSelection }

  TListControlClearSelection = class(TListControlAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
    procedure UpdateTarget(Target: TObject); override;
  published
    property Caption;
    property Enabled;
    property HelpContext;
    property Hint;
    property ImageIndex;
    property ListControl;
    property ShortCut;
    property SecondaryShortCuts;
    property Visible;
    property OnHint;
  end;

{ TListControlDeleteSelection }

  TListControlDeleteSelection = class(TListControlAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
    procedure UpdateTarget(Target: TObject); override;
  published
    property Caption;
    property Enabled;
    property HelpContext;
    property Hint;
    property ImageIndex;
    property ListControl;
    property ShortCut;
    property SecondaryShortCuts;
    property Visible;
    property OnHint;
  end;

{ TListBoxCopySelection }

  TListControlCopySelection = class(TListControlAction)
  private
    FDestination: TCustomListControl;
    procedure SetDestination(const Value: TCustomListControl);
  public
    procedure ExecuteTarget(Target: TObject); override;
    function HandlesTarget(Target: TObject): Boolean; override;
    procedure UpdateTarget(Target: TObject); override;
  published
    property Caption;
    property Destination: TCustomListControl read FDestination write SetDestination;
    property Enabled;
    property HelpContext;
    property Hint;
    property ImageIndex;
    property ListControl;
    property ShortCut;
    property SecondaryShortCuts;
    property Visible;
    property OnHint;
  end;

{ TListControlMoveSelection }

  TListControlMoveSelection = class(TListControlCopySelection)
  public
    procedure ExecuteTarget(Target: TObject); override;
  end;

implementation

uses Forms, Consts, commctrl, Mapi;

{ TCustomFileRun }

constructor TCustomFileRun.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FBrowse := False;
  FHinst := 0;
  FParentHWnd := 0;
  FOperation := 'open';
  FFile := '';
  FParameters := '';
  FDirectory := '';
  FShowCmd := scShowNormal;
  SetupBrowseDialog;
end;

procedure TCustomFileRun.ExecuteTarget(Target: TObject);
const
  ShowCmds: array[TShowCmd] of Integer = (SW_HIDE, SW_MAXIMIZE, SW_MINIMIZE,
    SW_RESTORE, SW_SHOW, SW_SHOWDEFAULT, SW_SHOWMAXIMIZED, SW_SHOWMINIMIZED,
    SW_SHOWMINNOACTIVE, SW_SHOWNA, SW_SHOWNOACTIVATE, SW_SHOWNORMAL);
var
  ParentHWnd: THandle;
begin
  if Assigned(FParentControl) then
  begin
    if FParentControl.HandleAllocated then
      ParentHwnd := FParentControl.Handle
    else
      ParentHWnd := 0;
  end
  else
    if IsWindow(FParentHWnd) then
      ParentHwnd := FParentHWnd
    else
      ParentHWnd := 0;
  if FBrowse then
  begin
    if FBrowseDlg.Execute then
      FHInst := ShellExecute(ParentHWnd, PChar(FOperation),
        PChar(FBrowseDlg.FileName), PChar(FParameters), PChar(FDirectory),
        ShowCmds[FShowCmd])
    else
      exit;
  end
  else
    FHInst := ShellExecute(ParentHWnd, PChar(FOperation), PChar(FFile),
      PChar(FParameters), PChar(FDirectory), ShowCmds[FShowCmd]);
  if FHInst <= 32 then
    raise Exception.Create(SysErrorMessage(FHinst));
end;

function TCustomFileRun.HandlesTarget(Target: TObject): Boolean;
begin
  Result := True;
end;

procedure TCustomFileRun.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (AComponent = FParentControl) then
    FParentControl := nil;
end;

procedure TCustomFileRun.SetBrowseDlg(const Value: TOpenDialog);
begin
  if Value <> FBrowseDlg then
  begin
    if Value = nil then
      SetupBrowseDialog
    else
    begin
      if FBrowseDlg.Owner = Self then
        FreeAndNil(FBrowseDlg);
      FBrowseDlg := Value;
    end;
  end;
end;

procedure TCustomFileRun.SetParentControl(const Value: TWinControl);
begin
  if FParentControl <> Value then
  begin
    FParentControl := Value;
    FParentControl.FreeNotification(Self);
  end;
end;

procedure TCustomFileRun.SetupBrowseDialog;
begin
  FBrowseDlg := TOpenDialog.Create(Self);
  FBrowseDlg.SetSubComponent(True);
  FBrowseDlg.Title := SFileRunDialogTitle;
end;

procedure TCustomFileRun.UpdateTarget(Target: TObject);
begin
  Enabled := FBrowse or (not FBrowse and (Length(FileName) > 0));
end;

{ TRichEditAction }

constructor TRichEditAction.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  AutoCheck := True;
end;

function TRichEditAction.CurrText(Edit: TCustomRichEdit): TTextAttributes;
begin
  Result := Edit.SelAttributes;
end;

function TRichEditAction.HandlesTarget(Target: TObject): Boolean;
begin
  Result := ((Control <> nil) and (Target = Control) or
    (Control = nil) and (Target is TCustomRichEdit)) and TCustomEdit(Target).Focused;
end;

procedure TRichEditAction.SetFontStyle(Edit: TCustomRichEdit; Style: TFontStyle);
begin
  if Edit = nil then exit;
  if Style in CurrText(Edit).Style then
    CurrText(Edit).Style := CurrText(Edit).Style - [Style]
  else
    CurrText(Edit).Style := CurrText(Edit).Style + [Style];
end;

{ TRichEditBold }

procedure TRichEditBold.ExecuteTarget(Target: TObject);
begin
  SetFontStyle(Target as TCustomRichEdit, fsBold);
end;

procedure TRichEditBold.UpdateTarget(Target: TObject);
begin
  inherited UpdateTarget(Target);
  Enabled := Target is TCustomRichEdit;
  Checked := fsBold in TCustomRichEdit(Target).SelAttributes.Style;
end;

{ TRichEditItalic }

procedure TRichEditItalic.ExecuteTarget(Target: TObject);
begin
  SetFontStyle(Target as TCustomRichEdit, fsItalic);
end;

procedure TRichEditItalic.UpdateTarget(Target: TObject);
begin
  Enabled := Target is TCustomRichEdit;
  Checked := fsItalic in TCustomRichEdit(Target).SelAttributes.Style;
end;

{ TRichEditUnderline }

procedure TRichEditUnderline.ExecuteTarget(Target: TObject);
begin
  SetFontStyle(Target as TCustomRichEdit, fsUnderline);
end;

procedure TRichEditUnderline.UpdateTarget(Target: TObject);
begin
  Enabled := Target is TCustomRichEdit;
  Checked := fsUnderline in TCustomRichEdit(Target).SelAttributes.Style;
end;

{ TRichEditStrikeOut }

procedure TRichEditStrikeOut.ExecuteTarget(Target: TObject);
begin
  if Target is TCustomRichEdit then
    SetFontStyle(Target as TCustomRichEdit, fsStrikeOut);
end;

procedure TRichEditStrikeOut.UpdateTarget(Target: TObject);
begin
  Enabled := Target is TCustomRichEdit;
  if Target is TCustomRichEdit then
    Checked := fsStrikeOut in TCustomRichEdit(Target).SelAttributes.Style;
end;

{ TRichEditBullets }

procedure TRichEditBullets.ExecuteTarget(Target: TObject);
begin
  if Target is TCustomRichEdit then
    if TCustomRichEdit(Target).Paragraph.Numbering = nsNone then
      TCustomRichEdit(Target).Paragraph.Numbering := nsBullet
    else
      TCustomRichEdit(Target).Paragraph.Numbering := nsNone;
end;

procedure TRichEditBullets.UpdateTarget(Target: TObject);
begin
  Enabled := Target is TCustomRichEdit;
  Checked := Enabled and (TCustomRichEdit(Target).Paragraph.Numbering = nsBullet);
end;

{ TRichEditAlignLeft }

procedure TRichEditAlignLeft.ExecuteTarget(Target: TObject);
begin
  if Target is TCustomRichEdit then
    TCustomRichEdit(Target).Paragraph.Alignment := taLeftJustify;
  Checked := True;
end;

procedure TRichEditAlignLeft.UpdateTarget(Target: TObject);
begin
  Enabled := Target is TCustomRichEdit;
  Checked := Enabled and (TCustomRichEdit(Target).Paragraph.Alignment = taLeftJustify);
end;

{ TRichEditAlignRight }

procedure TRichEditAlignRight.ExecuteTarget(Target: TObject);
begin
  if Target is TCustomRichEdit then
    TCustomRichEdit(Target).Paragraph.Alignment := taRightJustify;
  Checked := True;
end;

procedure TRichEditAlignRight.UpdateTarget(Target: TObject);
begin
  Enabled := Target is TCustomRichEdit;
  Checked := Enabled and (TCustomRichEdit(Target).Paragraph.Alignment = taRightJustify);
end;

{ TRichEditAlignCenter }

procedure TRichEditAlignCenter.ExecuteTarget(Target: TObject);
begin
  if Target is TCustomRichEdit then
    TCustomRichEdit(Target).Paragraph.Alignment := taCenter;
  Checked := True;
end;

procedure TRichEditAlignCenter.UpdateTarget(Target: TObject);
begin
  Enabled := Target is TCustomRichEdit;
  Checked := Enabled and (TCustomRichEdit(Target).Paragraph.Alignment = taCenter);
end;

{ TTabAction }

constructor TTabAction.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  DisableIfNoHandler := False;
  Enabled := csDesigning in ComponentState;
  FSkipHiddenTabs := True;
end;

function TTabAction.HandlesTarget(Target: TObject): Boolean;
begin
  Result := Assigned(FTabControl);
end;

procedure TTabAction.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (AComponent = FTabControl) then
    FTabControl := nil;
end;

type
  TTabControlClass = class(TCustomTabControl);

procedure TTabAction.UpdateTarget(Target: TObject);
begin
  if FTabControl is TPageControl then
    FEnabled := Assigned(FTabControl) and FTabControl.Enabled and
      (TPageControl(FTabControl).PageCount > 0)
  else
    FEnabled := Assigned(FTabControl) and FTabControl.Enabled and
      (TTabControlClass(FTabControl).Tabs.Count > 0);
  if FEnabled and Assigned(FOnValidateTab) then
    FOnValidateTab(Self, FTabControl, FEnabled);
end;

procedure TTabAction.SelectNextTab(GoForward: Boolean = True);
const
  Direction: array[Boolean] of Integer = (-1, 1);
begin
  if Assigned(FBeforeTabChange) then
    FBeforeTabChange(Self);
  if FTabControl is TPageControl then
  begin
    with FTabControl as TPageControl do
      if Wrap and GoForward and (ActivePageIndex = PageCount - 1) then
        ActivePageIndex := 0
      else if Wrap and not GoForward and (ActivePageIndex = 0) then
        ActivePageIndex := PageCount - 1
      else
        SelectNextPage(GoForward, FSkipHiddenTabs);
  end
  else if FTabControl is TCustomTabControl then
    with TTabControlClass(FTabControl) do
      if Wrap and GoForward and (TabIndex = Tabs.Count - 1) then
        TabIndex := 0
      else if Wrap and not GoForward and (TabIndex = 0) then
        TabIndex := Tabs.Count - 1
      else
        TabIndex := TabIndex + Direction[GoForward];
  if Assigned(FAfterTabChange) then
    FAfterTabChange(Self);
end;

{ TPreviousTab }

procedure TPreviousTab.ExecuteTarget(Target: TObject);
begin
  SelectNextTab(False)
end;

procedure TPreviousTab.UpdateTarget(Target: TObject);
begin
  inherited UpdateTarget(Target);
  if FEnabled then
  begin
    if FWrap then
      Enabled := True
    else
      if FTabControl is TPageControl then
        Enabled := (TPageControl(FTabControl).ActivePageIndex > 0)
      else
        Enabled := (TTabControlClass(FTabControl).TabIndex > 0);
  end;
end;

{ TNextTab }

procedure TNextTab.ExecuteTarget(Target: TObject);

  function NextPage: Boolean;
  begin
    if FTabControl is TPageControl then
      with TPageControl(FTabControl) do
        Result := ActivePageIndex < PageCount - 1
    else
      with TTabControlClass(FTabControl) do
        Result := TabIndex < Tabs.Count - 1;
  end;

begin
  if NextPage or FWrap then
    SelectNextTab
  else
    if (Length(FLastTabCaption) > 0) and Assigned(FOnFinish) then
      FOnFinish(Self);
end;

procedure TNextTab.UpdateTarget(Target: TObject);

  function OnLastTab: Boolean;
  begin
    if FTabControl is TPageControl then
      with TPageControl(FTabControl) do
        Result := ActivePageIndex = PageCount - 1
    else
      with TTabControlClass(FTabControl) do
        Result := TabIndex = Tabs.Count - 1;
  end;

begin
  inherited UpdateTarget(Target);
  if not FWrap and FEnabled and (Length(FLastTabCaption) = 0) and OnLastTab then
    Enabled := False
  else
    Enabled := FEnabled;
  if not Enabled then exit;
  if not FWrap and OnLastTab then
  begin
    if (Caption <> FLastTabCaption) then
    begin
      FOldCaption := Caption;
      Caption := FLastTabCaption;
    end;
  end
  else
    if (Length(FOldCaption) > 0) and (CompareText(Caption, FOldCaption) <> 0) then
    begin
      Caption := FOldCaption;
      FOldCaption := ''
    end;
end;

{ TOpenPicture }

function TOpenPicture.GetDialog: TOpenPictureDialog;
begin
  Result := TOpenPictureDialog(FDialog);
end;

function TOpenPicture.Getdialogclass: TCommonDialogClass;
begin
  Result := TOpenPictureDialog;
end;

{ TSavePicture }

function TSavePicture.GetDialog: TSavePictureDialog;
begin
  Result := TSavePictureDialog(FDialog);
end;

function TSavePicture.Getdialogclass: TCommonDialogClass;
begin
  Result := TSavePictureDialog;
end;

{ TURLAction }

function TURLAction.HandlesTarget(Target: TObject): Boolean;
begin
  Result := True;
end;

procedure TURLAction.UpdateTarget(Target: TObject);
begin
  Enabled := (Length(FURL) > 0);
end;

{ TBrowseURL }

procedure TBrowseURL.ExecuteTarget(Target: TObject);
begin
  ShellExecute(0, nil, PChar(URL), '', '', SW_SHOWNORMAL);
end;

{ TSendMail }

destructor TSendMail.Destroy;
begin
  if Assigned(FText) then
    FreeAndNil(FText);
  inherited Destroy;
end;

procedure TSendMail.ExecuteTarget(Target: TObject);
var
  MapiMessage: TMapiMessage;
  MError: Cardinal;
begin
  with MapiMessage do
  begin
    ulReserved := 0;
    lpszSubject := nil;
    lpszNoteText := PChar(Text.Text);
    lpszMessageType := nil;
    lpszDateReceived := nil;
    lpszConversationID := nil;
    flFlags := 0;
    lpOriginator := nil;
    nRecipCount := 0;
    lpRecips := nil;
    nFileCount := 0;
    lpFiles := nil;
  end;

  MError := MapiSendMail(0, Application.Handle, MapiMessage,
    MAPI_DIALOG or MAPI_LOGON_UI or MAPI_NEW_SESSION, 0);
  if MError <> 0 then MessageDlg(SSendError, mtError, [mbOK], 0);
end;

function TSendMail.GetText: TStrings;
begin
  if FText = nil then
    FText := TStringList.Create;
  Result := FText;
end;

function TSendMail.HandlesTarget(Target: TObject): Boolean;
begin
  Result := True;
end;

procedure TSendMail.SetText(const Value: TStrings);
begin
  if FText = nil then
    FText := TStringList.Create;
  FText.Assign(Value);
end;

procedure TSendMail.UpdateTarget(Target: TObject);
begin
  Enabled := True;
end;

{ TListControlAction }

constructor TListControlAction.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FListControl := nil;
end;

function TListControlAction.HandlesTarget(Target: TObject): Boolean;
begin
  Result := (ListControl <> nil) or
    (ListControl = nil) and (Target is TCustomListControl) and
    TCustomListControl(Target).Focused;
end;

type
  TCustomListControlType = class(TCustomListControl);
  TCustomMultiSelectListControlType = class(TCustomMultiSelectListControl);

function TListControlAction.IsEnabled(Target: TObject): Boolean;
var
  LC: TCustomListControlType;
begin
  if Target is TCustomListControl then
  begin
    LC := TCustomListControlType(Target);
    Result := (LC.GetCount > 0);
  end
  else
    Result := False;
end;

procedure TListControlAction.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (AComponent = FListControl) then
    FListControl := nil;
end;

procedure TListControlAction.SetListControl(const Value: TCustomListControl);
begin
  if Value <> FListControl then
  begin
    FListControl := Value;
    if Value <> nil then Value.FreeNotification(Self);
  end;
end;

{ TListControlSelectAll }

procedure TListControlSelectAll.ExecuteTarget(Target: TObject);
begin
  TCustomListControl(Target).SelectAll;
end;

procedure TListControlSelectAll.UpdateTarget(Target: TObject);
var
  LC: TCustomMultiSelectListControlType;
begin
  if Target is TCustomMultiSelectListControl then
  begin
    LC := TCustomMultiSelectListControlType(Target);
    Enabled := inherited IsEnabled(Target) and LC.MultiSelect and
      (LC.GetCount > 0) and (LC.SelCount < LC.GetCount);
  end
  else
    Enabled := False;
end;

{ TListControlClearSelection }

procedure TListControlClearSelection.ExecuteTarget(Target: TObject);
begin
  TCustomListControl(Target).ClearSelection;
end;

procedure TListControlClearSelection.UpdateTarget(Target: TObject);
var
  LC: TCustomListControlType;
begin
  LC := TCustomListControlType(Target);
  if Target is TCustomMultiSelectListControl then
    Enabled := inherited IsEnabled(Target) and (LC.GetCount > 0) and
      (LC.ItemIndex <> -1) and (TCustomMultiSelectListControlType(LC).SelCount > 0)
  else
    Enabled := inherited IsEnabled(Target) and (LC.GetCount > 0) and
      (LC.ItemIndex <> -1);
end;

{ TListControlCopySelection }

procedure TListControlCopySelection.ExecuteTarget(Target: TObject);
begin
  ListControl.CopySelection(FDestination);
end;

function TListControlCopySelection.HandlesTarget(Target: TObject): Boolean;
begin
  Result := inherited HandlesTarget(Target) and Assigned(FDestination);
  if Result then
    if ListControl = nil then
      with Target as TCustomListControl do
        Result := ItemIndex <> -1
    else
      Result := ListControl.ItemIndex <> -1
end;

procedure TListControlCopySelection.SetDestination(
  const Value: TCustomListControl);
begin
  if Value <> FDestination then
  begin
    FDestination := Value;
    if Value <> nil then Value.FreeNotification(Self);
  end;
end;

procedure TListControlCopySelection.UpdateTarget(Target: TObject);
var
  LC: TCustomListControlType;
begin
  LC := TCustomListControlType(Target);
  if Target is TCustomMultiSelectListControl then
    Enabled := inherited IsEnabled(Target) and (LC.GetCount > 0) and
      (LC.ItemIndex >= 0) and (TCustomMultiSelectListControlType(LC).SelCount > 0)
  else
    Enabled := inherited IsEnabled(Target) and (LC.GetCount > 0) and
      (LC.ItemIndex >= 0) and (LC.ItemIndex >= 0);
end;

{ TListControlMoveSelection }

procedure TListControlMoveSelection.ExecuteTarget(Target: TObject);
begin
  TCustomListControl(Target).MoveSelection(FDestination);
end;

{ TListControlDeleteSelection }

procedure TListControlDeleteSelection.ExecuteTarget(Target: TObject);
begin
  TCustomListControl(Target).DeleteSelected;
end;

type
  TCustomListControlClass = class(TCustomListControl);

procedure TListControlDeleteSelection.UpdateTarget(Target: TObject);
begin
  Enabled := inherited IsEnabled(Target) and
    (TCustomListControl(Target).ItemIndex <> -1);
end;


{ TDownLoadURL }

const
  // Maps to the status codes for IBindStatusCallBack
  BindStatusCode: array[0..24] of DWORD =
   (BINDSTATUS_FINDINGRESOURCE,
    BINDSTATUS_CONNECTING,
    BINDSTATUS_REDIRECTING,
    BINDSTATUS_BEGINDOWNLOADDATA,
    BINDSTATUS_DOWNLOADINGDATA,
    BINDSTATUS_ENDDOWNLOADDATA,
    BINDSTATUS_BEGINDOWNLOADCOMPONENTS,
    BINDSTATUS_INSTALLINGCOMPONENTS,
    BINDSTATUS_ENDDOWNLOADCOMPONENTS,
    BINDSTATUS_USINGCACHEDCOPY,
    BINDSTATUS_SENDINGREQUEST,
    BINDSTATUS_CLASSIDAVAILABLE,
    BINDSTATUS_MIMETYPEAVAILABLE,
    BINDSTATUS_CACHEFILENAMEAVAILABLE,
    BINDSTATUS_BEGINSYNCOPERATION,
    BINDSTATUS_ENDSYNCOPERATION,
    BINDSTATUS_BEGINUPLOADDATA,
    BINDSTATUS_UPLOADINGDATA,
    BINDSTATUS_ENDUPLOADDATA,
    BINDSTATUS_PROTOCOLCLASSID,
    BINDSTATUS_ENCODING,
    BINDSTATUS_VERIFIEDMIMETYPEAVAILABLE,
    BINDSTATUS_CLASSINSTALLLOCATION,
    BINDSTATUS_DECODING,
    BINDSTATUS_LOADINGMIMEHANDLER);

function DWordEnumToPascalEnumOrd(EnumArray: array of DWORD; Value: DWORD): Integer;
begin
  for Result := Low(EnumArray) to High(EnumArray) do
    if Value = EnumArray[Result] then Exit;
  raise Exception.CreateRes(@SInvalidEnumValue);
end;

type
  TUrlMonDownloadToFile = function(Caller: IUnknown; URL: PAnsiChar; FileName: PAnsiChar;
    Reserved: DWORD; StatusCB: IBindStatusCallback): HResult; stdcall;

var
  UrlMonHandle: HMODULE;
  UrlMonDownloadToFile: TUrlMonDownloadToFile;
  UrlMonInitialized: Boolean;

const
  UrlMonLib = 'URLMON.DLL';
  sURLMonDownloadToFileA = 'URLDownloadToFileA';

procedure TDownLoadURL.ExecuteTarget(Target: TObject);
begin
  if not UrlMonInitialized then
  begin
    UrlMonHandle := LoadLibrary(UrlMonLib);
    if UrlMonHandle <> 0 then
      UrlMonDownloadToFile := GetProcAddress(UrlMonHandle, PChar(sURLMonDownloadToFileA));
    UrlMonInitialized := True;
  end;
  if Assigned(UrlMonDownloadToFile) then
  begin
    if URLMonDownloadToFile(nil, PChar(URL), PChar(FileName), 0, Self as IBindStatusCallBack) <> S_OK then
      raise Exception.CreateResFmt(@SErrorDownloadingURL, [URL]);
  end else
    raise Exception.CreateResFmt(@SUrlMonDllMissing, [UrlMonLib]);
end;

function TDownLoadURL.GetBindInfo(out grfBINDF: Cardinal;
  var bindinfo: _tagBINDINFO): HRESULT;
begin
  Result := E_NOTIMPL;
end;

function TDownLoadURL.GetPriority(out nPriority): HRESULT;
begin
  Result := E_NOTIMPL;
end;

function TDownLoadURL.OnDataAvailable(grfBSCF, dwSize: Cardinal;
  formatetc: PFormatEtc; stgmed: PStgMedium): HRESULT;
begin
  Result := E_NOTIMPL;
end;

function TDownLoadURL.OnLowResource(reserved: Cardinal): HRESULT;
begin
  Result := E_NOTIMPL;
end;

function TDownLoadURL.OnObjectAvailable(const iid: TGUID;
  punk: IUnknown): HRESULT;
begin
  Result := E_NOTIMPL;
end;

function TDownLoadURL.OnProgress(ulProgress, ulProgressMax,
  ulStatusCode: Cardinal; szStatusText: PWideChar): HRESULT;
const
  ContinueDownload: array[Boolean] of Integer = (S_OK, E_ABORT);
var
  Cancel: Boolean;
begin
  Cancel := False;
  if Assigned(FOnDownloadProgress) then
    FOnDownloadProgress(Self, ulProgress, ulProgressMax,
      TURLDownloadStatus(DWordEnumToPascalEnumOrd(BindStatusCode, ulStatusCode)),
      Trim(WideCharToString(szStatusText)), Cancel);
  Result := ContinueDownload[Cancel];
end;

function TDownLoadURL.OnStartBinding(dwReserved: Cardinal;
  pib: IBinding): HRESULT;
begin
  Result := E_NOTIMPL;
end;

function TDownLoadURL.OnStopBinding(hresult: HRESULT;
  szError: PWideChar): HRESULT;
begin
  Result := E_NOTIMPL;
end;

initialization
finalization
  if UrlMonInitialized and (UrlMonHandle <> 0) then
    FreeLibrary(UrlMonHandle);
end.

