{*******************************************************}
{                                                       }
{       Borland Delphi Test Server                      }
{                                                       }
{   Copyright (c) 2001 Borland Software Corporation     }
{                                                       }
{*******************************************************}

unit SvrMainForm;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  ActnList, StdCtrls, SvrHTTP, Menus, Registry,
  ExtCtrls, ComCtrls,
  SvrLog, SvrLogFrame, SvrStatsFrame;

type
  TWebAppDbgMainForm = class(TForm)
    pbToggle: TButton;
    ActionList1: TActionList;
    ToggleServerAction: TAction;
    MainMenu1: TMainMenu;
    PropertiesItem: TMenuItem;
    StartServer1: TMenuItem;
    StopServer1: TMenuItem;
    Properties1: TMenuItem;
    Exit1: TMenuItem;
    N1: TMenuItem;
    N2: TMenuItem;
    Help1: TMenuItem;
    About1: TMenuItem;
    ExitAction: TAction;
    StopAction: TAction;
    StartAction: TAction;
    AboutAction: TAction;
    PropertiesAction: TAction;
    BrowseAction: TAction;
    PopupMenu1: TPopupMenu;
    Properties2: TMenuItem;
    StartServer2: TMenuItem;
    StopServer2: TMenuItem;
    Exit2: TMenuItem;
    Label2: TLabel;
    Home: TLabel;
    MainUpdateAction: TAction;
    ClearAction: TAction;
    Label1: TLabel;
    Port: TLabel;
    GroupBox1: TGroupBox;
    LogFrame: TLogFrame;
    ToggleLogAction: TAction;
    CheckBox1: TCheckBox;
    PageControl1: TPageControl;
    TabSheet1: TTabSheet;
    TabSheet2: TTabSheet;
    StatsFrame: TStatsFrame;
    procedure ToggleServerActionExecute(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure ToggleServerActionUpdate(Sender: TObject);
    procedure StopActionExecute(Sender: TObject);
    procedure StopActionUpdate(Sender: TObject);
    procedure StartActionExecute(Sender: TObject);
    procedure StartActionUpdate(Sender: TObject);
    procedure PropertiesActionExecute(Sender: TObject);
    procedure ExitActionExecute(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure HomeClick(Sender: TObject);
    procedure HideActionExecute(Sender: TObject);
    procedure SysTray1DblClick(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure MainUpdateActionExecute(Sender: TObject);
    procedure MainUpdateActionUpdate(Sender: TObject);
    procedure ToggleLogActionExecute(Sender: TObject);
    procedure ToggleLogActionUpdate(Sender: TObject);
    procedure AboutActionExecute(Sender: TObject);
  private
    FShowAtStartup: Boolean;
    FActiveAtStartup: Boolean;
    FHideOnClose: Boolean;
    FWebServer: TCustomWebServer;
    FLogOn: Boolean;
    function GetSearchPath: string;
    function GetServerActive: Boolean;
    function GetServerPort: Integer;
    procedure SetSearchPath(const Value: string);
    procedure SetServerActive(const Value: Boolean);
    procedure SetServerPort(const Value: Integer);
    function GetDefaultURL: string;
    procedure SetDefaultURL(const Value: string);
    function CreateRegistry: TRegIniFile;
    procedure Load(Reg: TRegIniFile);
    procedure Save(Reg: TRegIniFile);
    function GetTranslatedDefaultURL: string;
    procedure OnLog(Sender: TObject; Transaction: TTransactionLogEntry;
      var Release: Boolean);
    function GetLogMax: Integer;
    procedure SetLogMax(const Value: Integer);
    function GetLogDelete: Integer;
    procedure SetLogDelete(const Value: Integer);
    property ServerActive: Boolean read GetServerActive write SetServerActive;
    property ServerSearchPath: string read GetSearchPath write SetSearchPath;
    property ServerPort: Integer read GetServerPort write SetServerPort;
    property DefaultURL: string read GetDefaultURL write SetDefaultURL;
    property TranslatedDefaultURL: string read GetTranslatedDefaultURL;
    property LogMax: Integer read GetLogMax write SetLogMax;
    property LogDelete: Integer read GetLogDelete write SetLogDelete;
    property ShowAtStartup: Boolean read FShowAtStartup write FShowAtStartup;
    property ActiveAtStartup: Boolean read FActiveAtStartup write FActiveAtStartup;
    property HideOnClose: Boolean read FHideOnClose write FHideOnClose;
    property LogOn: Boolean read FLogOn write FLogOn;
  end;

var
  WebAppDbgMainForm: TWebAppDbgMainForm;

implementation

uses SvrPropDlg, ShellAPI, SvrConst, WebAppDbgAbout;

{$R *.dfm}

procedure TWebAppDbgMainForm.ToggleServerActionExecute(Sender: TObject);
begin
  ServerActive := not ServerActive;
end;

procedure TWebAppDbgMainForm.FormCreate(Sender: TObject);
var
  Reg: TRegIniFile;
begin
  Caption := sWebAppDebugger;
  Application.Title := sWebAppDebugger;
  FWebServer := TCustomWebServer.Create(Self);
  FWebServer.OnLog := OnLog;
  FWebServer.Port := 1024;
  FWebServer.DefaultURL := 'ServerInfo.ServerInfo';    // Do not localize
  FWebServer.SearchPath := '$(DELPHI)\source\webmidas;$(DELPHI)\demos\websnap\images'; // Do not localize
  LogOn := True;
  ShowAtStartup := True;
  ActiveAtStartup := False;
  Reg := CreateRegistry;
  try
    Load(Reg);
  finally
    Reg.CloseKey;
    Reg.Free;
  end;
  if ActiveAtStartup then
    FWebServer.Active := True;
end;

procedure TWebAppDbgMainForm.ToggleServerActionUpdate(Sender: TObject);
begin
  if ServerActive then
    (Sender as TAction).Caption := sStopServer
  else
    (Sender as TAction).Caption := sStartServer;
end;

procedure TWebAppDbgMainForm.StopActionExecute(Sender: TObject);
begin
  ServerActive := False;
end;

procedure TWebAppDbgMainForm.StopActionUpdate(Sender: TObject);
begin
  (Sender as TAction).Enabled := ServerActive;
end;

procedure TWebAppDbgMainForm.StartActionExecute(Sender: TObject);
begin
  ServerActive := True;
end;

procedure TWebAppDbgMainForm.StartActionUpdate(Sender: TObject);
begin
  (Sender as TAction).Enabled := not ServerActive;
end;

function TWebAppDbgMainForm.GetSearchPath: string;
begin
  Result := FWebServer.SearchPath;
end;

function TWebAppDbgMainForm.GetServerActive: Boolean;
begin
  Result := FWebServer.Active;
end;

function TWebAppDbgMainForm.GetServerPort: Integer;
begin
  Result := FWebServer.Port;
end;

procedure TWebAppDbgMainForm.SetSearchPath(const Value: string);
begin
  FWebServer.SearchPath := Value;
end;

procedure TWebAppDbgMainForm.SetServerActive(const Value: Boolean);
begin
  FWebServer.Active := Value;
end;

procedure TWebAppDbgMainForm.SetServerPort(const Value: Integer);
begin
  if ServerActive and (Value <> FWebServer.Port) then
  begin
    FWebServer.Active := False;
    FWebServer.Port := Value;
    FWebServer.Active := True;
  end
  else
    FWebServer.Port := Value;
end;

procedure TWebAppDbgMainForm.PropertiesActionExecute(Sender: TObject);
var
  Reg: TRegIniFile;
begin
  with TDlgProperties.Create(Application) do
  try
    ServerPort := Self.ServerPort;
    ServerSearchPath := Self.ServerSearchPath;
    DefaultURL := Self.DefaultURL;
    LogMax := Self.LogMax;
    LogDelete := Self.LogDelete;
    ShowAtStartup := Self.ShowAtStartup;
    ActiveAtStartup := Self.ActiveAtStartup;
    HideOnClose := Self.HideOnClose;
    LogFrame := Self.LogFrame;

    if ShowModal = mrOk then
    begin
      Self.ServerPort := ServerPort;
      Self.ServerSearchPath := ServerSearchPath;
      Self.DefaultURL := DefaultURL;
      Self.LogMax := LogMax;
      Self.LogDelete := LogDelete;
      Self.ShowAtStartup := ShowAtStartup;
      Self.ActiveAtStartup := ActiveAtStartup;
      Self.HideOnClose := HideOnClose;
      UpdateColumns;
      Reg := CreateRegistry;
      try
        Save(Reg);
      finally
        Reg.CloseKey;
        Reg.Free;
      end;
    end;
  finally
    Free;
  end;
end;

procedure TWebAppDbgMainForm.ExitActionExecute(Sender: TObject);
begin
  Application.Terminate;
end;

procedure TWebAppDbgMainForm.FormDestroy(Sender: TObject);
var
  Reg: TRegIniFile;
begin
  LogFrame.SynchColumnInfo;
  Reg := CreateRegistry;
  try
    Save(Reg);
  finally
    Reg.CloseKey;
    Reg.Free;
  end;
  FWebServer.Free;
end;

procedure TWebAppDbgMainForm.HomeClick(Sender: TObject);
begin
  // Add browse code here
  if ServerActive then
    if TranslatedDefaultURL <> '' then
      ShellExecute(Application.Handle, nil,
        PChar(TranslatedDefaultURL), nil, nil, SW_SHOWNOACTIVATE);
end;

function TWebAppDbgMainForm.GetDefaultURL: string;
begin
  Result := FWebServer.DefaultURL;
end;

procedure TWebAppDbgMainForm.SetDefaultURL(const Value: string);
begin
  FWebServer.DefaultURL := Value;
end;

function TWebAppDbgMainForm.CreateRegistry: TRegIniFile;
const
  sKey = '\Software\Borland\WebAppDbg';                      { do not localize }
begin
  Result := TRegIniFile.Create;
  try
    Result.RootKey := HKEY_LOCAL_MACHINE;
    if not Result.OpenKey(sKey, True) then
      raise Exception.CreateFmt(sCouldNotOpenRegKey, [sKey]);
  except
    Result.Free;
    raise;
  end;
end;

const
  sPort = 'Port';
  sPath = 'Path';
  sDefaultURL = 'DefaultURL';
  sLogMax = 'LogMax';
  sLogDelete = 'LogDelete';
  sShowAtStartup = 'ShowAtStartup';
  sActiveAtStartup = 'ActiveAtStartup';
  sColumns = 'Columns';
  sHideOnClose = 'HideOnClose';
  sLogOn = 'LogOn';
  sLeft = 'Left';
  sTop = 'Top';
  sWidth = 'Width';
  sHeight = 'Height';
  sWindowState = 'WindowState';

procedure TWebAppDbgMainForm.Save(Reg: TRegIniFile);
begin
  Reg.WriteInteger('', sPort, ServerPort);
  Reg.WriteString('', sPath, ServerSearchPath);
  Reg.WriteString('', sDefaultURL, DefaultURL);
  Reg.WriteInteger('', sLogMax, LogMax);
  Reg.WriteInteger('', sLogDelete, LogDelete);
  Reg.WriteBool('', sShowAtStartup, ShowAtStartup);
  Reg.WriteBool('', sActiveAtStartup, ActiveAtStartup);
  Reg.WriteBool('', sHideOnClose, HideOnClose);
  Reg.WriteBool('', sLogOn, LogOn);
  Reg.WriteInteger('', sWindowState, Integer(Self.WindowState));
  if WindowState = wsNormal then
  begin
    Reg.WriteInteger('', sLeft, Self.Left);
    Reg.WriteInteger('', sTop, Self.Top);
    Reg.WriteInteger('', sWidth, Self.Width);
    Reg.WriteInteger('', sHeight, Self.Height);
  end;
  LogFrame.Save(Reg, sColumns);
end;

procedure TWebAppDbgMainForm.Load(Reg: TRegIniFile);
begin
  ServerPort := Reg.ReadInteger('', sPort, ServerPort);
  ServerSearchPath := Reg.ReadString('', sPath, ServerSearchPath);
  DefaultURL := Reg.ReadString('', sDefaultURL, DefaultURL);
  LogMax := Reg.ReadInteger('', sLogMax, LogMax);
  LogDelete := Reg.ReadInteger('', sLogDelete, LogDelete);
  ShowAtStartup := Reg.ReadBool('', sShowAtStartup, ShowAtStartup);
  ActiveAtStartup := Reg.ReadBool('', sActiveAtStartup, ActiveAtStartup);
  HideOnClose := Reg.ReadBool('', sHideOnClose, HideOnClose);
  LogOn := Reg.ReadBool('', sLogOn, LogOn);
  if Reg.ValueExists(sLeft) then
  begin
    Position := poDesigned;
    Self.Left := Reg.ReadInteger('', sLeft, Self.Left);
    Self.Top := Reg.ReadInteger('', sTop, Self.Top);
    Self.Width := Reg.ReadInteger('', sWidth, Self.Width);
    Self.Height := Reg.ReadInteger('', sHeight, Self.Height);
    Self.WindowState := TWindowState(Reg.ReadInteger('', sWindowState, Integer(Self.WindowState)));
  end;
  LogFrame.Load(Reg, sColumns);
end;

procedure TWebAppDbgMainForm.HideActionExecute(Sender: TObject);
begin
  Visible := False;
end;

procedure TWebAppDbgMainForm.SysTray1DblClick(Sender: TObject);
begin
  Visible := not Visible;
end;

procedure TWebAppDbgMainForm.FormClose(Sender: TObject; var Action: TCloseAction);
begin
   Action := caFree;
end;

procedure TWebAppDbgMainForm.MainUpdateActionExecute(Sender: TObject);
begin
//
end;

procedure TWebAppDbgMainForm.MainUpdateActionUpdate(Sender: TObject);
begin
  if (TranslatedDefaultURL <> '') then
    Home.Caption := TranslatedDefaultURL
  else
    Home.Caption := sNoDefaultURL;
  if ServerActive and (TranslatedDefaultURL <> '') then
  begin
    Home.Font.Color := clHighlight;
    Home.Font.Style := [fsUnderline];
    Home.Cursor := crHandPoint;
  end
  else
  begin
    Home.Font.Color := clWindowText;
    Home.Font.Style := [];
    Home.Cursor := crDefault;
  end;
  Port.Caption := IntToStr(ServerPort);
end;

function TWebAppDbgMainForm.GetTranslatedDefaultURL: string;
begin
  Result := FWebServer.TranslatedDefaultURL;
end;

procedure TWebAppDbgMainForm.OnLog(Sender: TObject; Transaction: TTransactionLogEntry;
  var Release: Boolean);
begin
  StatsFrame.LogStatistics(Transaction);
  if LogOn then
  begin
    LogFrame.Add(Transaction);
    Release := False;
  end
  else
    Release := True;
end;

function TWebAppDbgMainForm.GetLogMax: Integer;
begin
  Result := LogFrame.LogMax;
end;

procedure TWebAppDbgMainForm.SetLogMax(const Value: Integer);
begin
  LogFrame.LogMax := Value;
end;

function TWebAppDbgMainForm.GetLogDelete: Integer;
begin
  Result := LogFrame.LogDelete;
end;

procedure TWebAppDbgMainForm.SetLogDelete(const Value: Integer);
begin
  LogFrame.LogDelete := Value;
end;

procedure TWebAppDbgMainForm.ToggleLogActionExecute(Sender: TObject);
begin
  FLogOn := CheckBox1.Checked;
end;

procedure TWebAppDbgMainForm.ToggleLogActionUpdate(Sender: TObject);
begin
  (Sender as TAction).Checked := FLogOn;
end;

procedure TWebAppDbgMainForm.AboutActionExecute(Sender: TObject);
begin
  ShowAboutBox;
end;

end.
