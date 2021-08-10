{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1995,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit CtlPanel;

interface

uses
  SysUtils, Classes, Forms, Windows, Graphics, cpl, Dialogs;

type
  EAppletException = class(Exception);

  TInitEvent = procedure (Sender: TObject; var AppInitOK: Boolean) of object;
  TCountEvent = procedure (Sender: TObject; var AppCount: Integer) of object;
  TExitEvent = TNotifyEvent;
  TSetupEvent = TNotifyEvent;

  TActivateEvent     = procedure (Sender: TObject; Data: LongInt) of object;
  TStopEvent         = procedure (Sender: TObject; Data: LongInt) of object;
  TInquireEvent      = procedure (Sender: TObject; var idIcon: Integer; var idName: Integer;
                                  var idInfo: Integer; var lData: Integer) of object;
  TNewInquireEvent   = procedure (Sender: TObject; var lData: Integer; var hIcon: HICON;
                                  var AppletName: string; var AppletInfo: string) of object; 
  TStartWParmsEvent  = procedure (Sender: TObject; Params: string) of object;

  TAppletModule = class(TDataModule)
  private
    FOnActivate: TActivateEvent;
    FOnStop: TStopEvent;
    FOnInquire: TInquireEvent;
    FOnNewInquire: TNewInquireEvent;
    FOnStartWParms: TStartWParmsEvent;
    FData: LongInt;
    FResidIcon: Integer;
    FResidName: Integer;
    FResidInfo: Integer;
    FAppletIcon: TIcon;
    FCaption: string;
    FHelp: string;
    procedure SetData(const Value: LongInt);
    procedure SetResidIcon(const Value: Integer);
    procedure SetResidInfo(const Value: Integer);
    procedure SetResidName(const Value: Integer);
    procedure SetAppletIcon(const Value: TIcon);
    procedure SetCaption(const Value: string);
    procedure SetHelp(const Value: string);
    function GetCaption: string;
  protected
    procedure DoStop(Data: LongInt); dynamic;
    procedure DoActivate(Data: LongInt); dynamic;
    procedure DoInquire(var ACPLInfo: TCPLInfo); dynamic;
    procedure DoNewInquire(var ANewCPLInfo: TNewCPLInfo); dynamic;
    procedure DoStartWParms(Params: string); dynamic;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property Data: LongInt read FData write SetData;
  published
    property OnStop: TStopEvent read FOnStop write FOnStop;
    property OnActivate: TActivateEvent read FOnActivate write FOnActivate;
    property OnInquire: TInquireEvent read FOnInquire write FOnInquire;
    property OnNewInquire: TNewInquireEvent read FOnNewInquire write FOnNewInquire;
    property OnStartWParms: TStartWParmsEvent read FOnStartWParms write FOnStartWParms;
    property Caption: string read GetCaption write SetCaption;
    property AppletIcon: TIcon read FAppletIcon write SetAppletIcon;
    property Help: string read FHelp write SetHelp;
    property ResidIcon: Integer read FResidIcon write SetResidIcon;
    property ResidName: Integer read FResidName write SetResidName;
    property ResidInfo: Integer read FResidInfo write SetResidInfo;
  end;

  TAppletModuleClass = class of TAppletModule;
  TCPLAppletClass = class of TAppletModule;
  TDataModuleClass = class of TDataModule;

  TAppletApplication = class(TComponent)
  private
    FComponentClass: TComponentClass;
    FControlPanelHandle: THandle;
    FModules: TList;
    FOnInit: TInitEvent;
    FOnCount: TCountEvent;
    FOnExit: TExitEvent;
    FOnSetup: TSetupEvent;
    FModuleCount: Integer;
    procedure OnExceptionHandler(Sender: TObject; E: Exception);
    function GetModules(Index: Integer): TAppletModule;
    procedure SetModules(Index: Integer; const Value: TAppletModule);
    procedure SetModuleCount(const Value: Integer);
    function GetModuleCount: Integer;
  protected
    procedure DoHandleException(E: Exception); dynamic;
    procedure DoInit(var AppInitOK: Boolean); dynamic;
    procedure DoCount(var AppCount: Integer); dynamic;
    procedure DoExit; dynamic;
    procedure DoSetup; dynamic;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure CreateForm(InstanceClass: TComponentClass; var Reference); virtual;
    procedure Initialize; virtual;
    procedure Run; virtual;
    property Modules[Index: Integer]: TAppletModule read GetModules write SetModules;
    property ModuleCount: Integer read GetModuleCount write SetModuleCount;
    property ControlPanelHandle: THandle read FControlPanelHandle;
    property OnInit: TInitEvent read FOnInit write FOnInit;
    property OnCount: TCountEvent read FOnCount write FOnCount;
    property OnExit: TExitEvent read FOnExit write FOnExit;
    property OnSetup: TSetupEvent read FOnSetup write FOnSetup;
  end;

function CPlApplet(hwndCPl: THandle; uMsg: DWORD;
                   lParam1, lParam2: Longint): Longint; stdcall;

var
  Application: TAppletApplication = nil;

implementation

{ TAppletApp }

resourcestring
  sInvalidClassReference = 'Invalid class reference for TAppletApplication';

constructor TAppletApplication.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FModules := TList.Create;
end;

procedure TAppletApplication.CreateForm(InstanceClass: TComponentClass;
  var Reference);
begin
  if InstanceClass.InheritsFrom(TCustomForm) or InstanceClass.InheritsFrom(TDataModule) then
  begin
    if (FComponentClass = nil) or (FComponentClass <> InstanceClass) then
      FComponentClass := TComponentClass(InstanceClass);
    TComponent(Reference) := FComponentClass.Create(Self);
  end
  else
    raise Exception.CreateRes(@sInvalidClassReference);
end;

destructor TAppletApplication.Destroy;
begin
  while FModules.Count > 0 do
    TObject(FModules[0]).Free;

  FModules.Free;
  Forms.Application.OnException := nil;
  inherited Destroy;
end;

procedure TAppletApplication.DoCount(var AppCount: Integer);
begin
  if assigned(FOnCount) then
    FOnCount(Self, AppCount);
end;

procedure TAppletApplication.DoExit;
begin
  if assigned(FOnExit) then
    FOnExit(Self);
end;

procedure TAppletApplication.DoHandleException(E: Exception);
begin
end;

procedure TAppletApplication.DoInit(var AppInitOK: Boolean);
begin
  if assigned(FOnInit) then
    FOnInit(Self, AppInitOK);
end;

procedure TAppletApplication.DoSetup;
begin
  if assigned(FOnSetup) then
    FOnSetup(Self);
end;

function TAppletApplication.GetModuleCount: Integer;
begin
  Result := FModules.Count;
end;

function TAppletApplication.GetModules(Index: Integer): TAppletModule;
begin
  Result := FModules[Index];
end;

procedure TAppletApplication.Initialize;
begin
end;

procedure TAppletApplication.OnExceptionHandler(Sender: TObject; E: Exception);
begin
  DoHandleException(E);
end;

procedure TAppletApplication.Run;
begin
  Forms.Application.OnException := OnExceptionHandler;
end;

procedure InitApplication;
begin
  Application := TAppletApplication.Create(nil);
end;

procedure DoneApplication;
begin
  Application.Free;
  Application := nil;
end;

function CPlApplet(hwndCPl: THandle; uMsg: DWORD; lParam1, lParam2: Longint): Longint;
var
  Temp: Boolean;
  
begin
  Result := 0;
  Temp := True;

  with Application, Application.Modules[lParam1] do
  begin
    FControlPanelHandle := hwndCPl;

    case (umsg) of
      CPL_INIT : DoInit(Temp);
      CPL_GETCOUNT:
      begin
        Result := ModuleCount;
        DoCount(Result);
        Exit;
      end;
      CPL_INQUIRE     : DoInquire(PCplInfo(lParam2)^);
      CPL_NEWINQUIRE  : DoNewInquire(PNewCPLInfo(lParam2)^);
      CPL_DBLCLK      : DoActivate(LongInt(lParam2));
      CPL_STOP        : DoStop(LongInt(LParam2));
      CPL_EXIT        : DoExit;
      CPL_STARTWPARMS : DoStartWParms(PChar(LParam2));
      CPL_SETUP       : DoSetup;
    end;
  end;

  Result := Integer(Temp);
end;

constructor TAppletModule.Create(AOwner: TComponent);
begin
  FAppletIcon := TIcon.Create;
  inherited Create(AOwner);
  Application.FModules.Add(Self);
end;

destructor TAppletModule.Destroy;
begin
  FAppletIcon.Free;
  Application.FModules.Delete(Application.FModules.IndexOf(Self));
  inherited Destroy;
end;

function TAppletModule.GetCaption: string;
begin
  if FCaption <> '' then
    Result := FCaption
  else
    Result := Name;
end;

procedure TAppletModule.DoActivate(Data: Integer);
begin
  if assigned(FOnActivate) then
    FOnActivate(Self, Data);
end;

procedure TAppletModule.DoInquire(var ACPLInfo: TCPLInfo);
begin
  with ACPLInfo do
  begin
    idIcon := FResidIcon;
    idName := FResidName;
    idInfo := FResidInfo;
    lData := FData;
  end;

  if assigned(FOnInquire) then
    with ACPLInfo do
      FOnInquire(Self, idIcon, idName, idInfo, lData);
end;

procedure TAppletModule.DoNewInquire(var ANewCPLInfo: TNewCPLInfo);
begin
  with ANewCPLInfo do
  begin
    dwSize := SizeOf(TNewCPLInfo);
    lData := FData;
    if (FResidIcon = CPL_DYNAMIC_RES) then
      hIcon := FAppletIcon.Handle
    else
      hIcon := LoadIcon(hInstance, MakeIntResource(FResidIcon));
  end;

  if assigned(fOnNewInquire) then
    with ANewCPLInfo do
      FOnNewInquire(Self, lData, hIcon, FCaption, FHelp);

  if (FResidName = CPL_DYNAMIC_RES) then
    StrLCopy(ANewCPLInfo.szName, PChar(FCaption), SizeOf(ANewCPLInfo.szName))
  else
    StrLCopy(ANewCPLInfo.szName, PChar(LoadStr(FResidName)), SizeOf(ANewCPLInfo.szName));

  if (FResidInfo = CPL_DYNAMIC_RES) then
    StrLCopy(ANewCPLInfo.szInfo, PChar(FHelp), SizeOf(ANewCPLInfo.szInfo))
  else
    StrLCopy(ANewCPLInfo.szInfo, PChar(LoadStr(FResidInfo)), SizeOf(ANewCPLInfo.szInfo));
end;

procedure TAppletModule.DoStartWParms(Params: string);
begin
  if assigned(FOnStartWParms) then
    FOnStartWParms(Self, Params);
end;

procedure TAppletModule.DoStop(Data: Integer);
begin
  if assigned(FOnStop) then
    FOnStop(Self, Data);
end;

procedure TAppletModule.SetAppletIcon(const Value: TIcon);
begin
  if FAppletIcon <> Value then
  begin
    FAppletIcon.Assign(Value);
    ResidIcon := CPL_DYNAMIC_RES;
  end;
end;

procedure TAppletModule.SetCaption(const Value: string);
begin
  if FCaption <> Value then
  begin
    if Value = '' then
      FCaption := Name
    else
      FCaption := Value;
    FResidName := CPL_DYNAMIC_RES;
  end;
end;

procedure TAppletModule.SetData(const Value: Integer);
begin
  if FData <> Value then
    FData := Value;
end;

procedure TAppletModule.SetHelp(const Value: string);
begin
  if FHelp <> Value then
  begin
    FHelp := Value;
    FResidInfo := CPL_DYNAMIC_RES;
  end;
end;

procedure TAppletModule.SetResidIcon(const Value: Integer);
begin
  if FResidIcon <> Value then
    FResidIcon := Value;
end;

procedure TAppletModule.SetResidInfo(const Value: Integer);
begin
  if FResidInfo <> Value then
  begin
    FResidInfo := Value;
    FHelp := '';
  end;
end;

procedure TAppletModule.SetResidName(const Value: Integer);
begin
  if FResidName <> Value then
  begin
    FResidName := Value;
    FCaption := '';
  end;
end;

procedure TAppletApplication.SetModuleCount(const Value: Integer);
begin
  if FModuleCount <> Value then
    FModuleCount := Value;
end;

procedure TAppletApplication.SetModules(Index: Integer;
  const Value: TAppletModule);
begin
  if FModules[Index] <> Value then
    FModules[Index] := Value;
end;

initialization
  InitApplication;

finalization
  DoneApplication;

end.
