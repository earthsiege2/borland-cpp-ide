
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1995,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit AppEvnts;

interface

uses Windows, Messages, SysUtils, Classes, Forms, ActnList;

type
  TCustomApplicationEvents = class(TComponent)
  private
    FOnActionExecute: TActionEvent;
    FOnActionUpdate: TActionEvent;
    FOnException: TExceptionEvent;
    FOnMessage: TMessageEvent;
    FOnHelp: THelpEvent;
    FOnHint: TNotifyEvent;
    FOnIdle: TIdleEvent;
    FOnDeactivate: TNotifyEvent;
    FOnActivate: TNotifyEvent;
    FOnMinimize: TNotifyEvent;
    FOnRestore: TNotifyEvent;
    FOnShortCut: TShortCutEvent;
    FOnShowHint: TShowHintEvent;
    procedure DoActionExecute(Action: TBasicAction; var Handled: Boolean);
    procedure DoActionUpdate(Action: TBasicAction; var Handled: Boolean);
    procedure DoActivate(Sender: TObject);
    procedure DoDeactivate(Sender: TObject);
    procedure DoException(Sender: TObject; E: Exception);
    procedure DoIdle(Sender: TObject; var Done: Boolean);
    function DoHelp(Command: Word; Data: Longint; var CallHelp: Boolean): Boolean;
    procedure DoHint(Sender: TObject);
    procedure DoMessage(var Msg: TMsg; var Handled: Boolean);
    procedure DoMinimize(Sender: TObject);
    procedure DoRestore(Sender: TObject);
    procedure DoShowHint(var HintStr: string; var CanShow: Boolean;
      var HintInfo: THintInfo);
    procedure DoShortcut(var Msg: TWMKey; var Handled: Boolean);
  protected
    property OnActionExecute: TActionEvent read FOnActionExecute write FOnActionExecute;
    property OnActionUpdate: TActionEvent read FOnActionUpdate write FOnActionUpdate;
    property OnActivate: TNotifyEvent read FOnActivate write FOnActivate;
    property OnDeactivate: TNotifyEvent read FOnDeactivate write FOnDeactivate;
    property OnException: TExceptionEvent read FOnException write FOnException;
    property OnIdle: TIdleEvent read FOnIdle write FOnIdle;
    property OnHelp: THelpEvent read FOnHelp write FOnHelp;
    property OnHint: TNotifyEvent read FOnHint write FOnHint;
    property OnMessage: TMessageEvent read FOnMessage write FOnMessage;
    property OnMinimize: TNotifyEvent read FOnMinimize write FOnMinimize;
    property OnRestore: TNotifyEvent read FOnRestore write FOnRestore;
    property OnShowHint: TShowHintEvent read FOnShowHint write FOnShowHint;
    property OnShortCut: TShortCutEvent read FOnShortCut write FOnShortCut;
  public
    constructor Create(AOwner: TComponent); override;
    procedure Activate;
    procedure CancelDispatch;
  end;

  TApplicationEvents = class(TCustomApplicationEvents)
  published
    property OnActionExecute;
    property OnActionUpdate;
    property OnActivate;
    property OnDeactivate;
    property OnException;
    property OnIdle;
    property OnHelp;
    property OnHint;
    property OnMessage;
    property OnMinimize;
    property OnRestore;
    property OnShowHint;
    property OnShortCut;
  end;

implementation

uses Contnrs, Consts, StdActns;

type
  TMultiCaster = class(TComponent)
  private
    FAppEvents: TComponentList;
    FDispatching: Boolean;
    procedure DoActionExecute(Action: TBasicAction; var Handled: Boolean);
    procedure DoActionUpdate(Action: TBasicAction; var Handled: Boolean);
    procedure DoActivate(Sender: TObject);
    procedure DoDeactivate(Sender: TObject);
    procedure DoException(Sender: TObject; E: Exception);
    procedure DoIdle(Sender: TObject; var Done: Boolean);
    function DoHelp(Command: Word; Data: Longint; var CallHelp: Boolean): Boolean;
    procedure DoHint(Sender: TObject);
    procedure DoMessage(var Msg: TMsg; var Handled: Boolean);
    procedure DoMinimize(Sender: TObject);
    procedure DoRestore(Sender: TObject);
    procedure DoShowHint(var HintStr: string; var CanShow: Boolean;
      var HintInfo: THintInfo);
    procedure DoShortcut(var Msg: TWMKey; var Handled: Boolean);
    function GetCount: Integer;
    function GetAppEvents(Index: Integer): TCustomApplicationEvents;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Activate(AppEvent: TCustomApplicationEvents);
    procedure AddAppEvent(AppEvent: TCustomApplicationEvents);
    procedure CancelDispatch;
    procedure CheckDispatching;

    property AppEvents[Index: Integer]: TCustomApplicationEvents
      read GetAppEvents; default;
    property Count: Integer read GetCount;
  end;

var
  MultiCaster: TMultiCaster = nil;

{ TCustomApplicationEvents }

procedure TCustomApplicationEvents.Activate;
begin
  MultiCaster.Activate(Self);
end;

procedure TCustomApplicationEvents.CancelDispatch;
begin
  MultiCaster.CancelDispatch;
end;

constructor TCustomApplicationEvents.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  MultiCaster.AddAppEvent(Self);
end;

procedure TCustomApplicationEvents.DoActionExecute(Action: TBasicAction;
  var Handled: Boolean);
begin
  if Assigned(FOnActionExecute) then FOnActionExecute(Action, Handled);
end;

procedure TCustomApplicationEvents.DoActionUpdate(Action: TBasicAction;
  var Handled: Boolean);
begin
  if Assigned(FOnActionUpdate) then FOnActionUpdate(Action, Handled);
end;

procedure TCustomApplicationEvents.DoActivate(Sender: TObject);
begin
  if Assigned(FOnActivate) then FOnActivate(Sender);
end;

procedure TCustomApplicationEvents.DoDeactivate(Sender: TObject);
begin
  if Assigned(FOnDeactivate) then FOnDeactivate(Sender);
end;

procedure TCustomApplicationEvents.DoException(Sender: TObject;
  E: Exception);
begin
  if E is Exception then
  begin
    if not (E is EAbort) then
      if Assigned(FOnException) then
        FOnException(Sender, E)
      else
        Application.ShowException(E);
  end else
    SysUtils.ShowException(E, ExceptAddr);
end;

function TCustomApplicationEvents.DoHelp(Command: Word; Data: Integer;
  var CallHelp: Boolean): Boolean;
begin
  if Assigned(FOnHelp) then
    Result := FOnHelp(Command, Data, CallHelp)
  else Result := False;
end;

procedure TCustomApplicationEvents.DoHint(Sender: TObject);
begin
  if Assigned(FOnHint) then
    FOnHint(Sender)
  else
    with THintAction.Create(Application) do
    try
      Hint := Application.Hint;
      Execute;
    finally
      Free;
    end;
end;

procedure TCustomApplicationEvents.DoIdle(Sender: TObject; var Done: Boolean);
begin
  if Assigned(FOnIdle) then FOnIdle(Sender, Done);
end;

procedure TCustomApplicationEvents.DoMessage(var Msg: TMsg; var Handled: Boolean);
begin
  if Assigned(FOnMessage) then FOnMessage(Msg, Handled);
end;

procedure TCustomApplicationEvents.DoMinimize(Sender: TObject);
begin
  if Assigned(FOnMinimize) then FOnMinimize(Sender);
end;

procedure TCustomApplicationEvents.DoRestore(Sender: TObject);
begin
  if Assigned(FOnRestore) then FOnRestore(Sender);
end;

procedure TCustomApplicationEvents.DoShortcut(var Msg: TWMKey;
  var Handled: Boolean);
begin
  if Assigned(FOnShortcut) then FOnShortcut(Msg, Handled);
end;

procedure TCustomApplicationEvents.DoShowHint(var HintStr: string;
  var CanShow: Boolean; var HintInfo: THintInfo);
begin
  if Assigned(FOnShowHint) then FOnShowHint(HintStr, CanShow, HintInfo);
end;

{ TMultiCaster }

procedure TMultiCaster.Activate(AppEvent: TCustomApplicationEvents);
begin
  CheckDispatching;
  if FAppEvents.IndexOf(AppEvent) < FAppEvents.Count - 1 then
  begin
    FAppEvents.Remove(AppEvent);
    FAppEvents.Add(AppEvent);
  end;
end;

procedure TMultiCaster.AddAppEvent(AppEvent: TCustomApplicationEvents);
begin
  if FAppEvents.IndexOf(AppEvent) = -1 then
    FAppEvents.Add(AppEvent);
end;

procedure TMultiCaster.CancelDispatch;
begin
  FDispatching := False;
end;

procedure TMultiCaster.CheckDispatching;
begin
  if FDispatching then
    raise Exception.CreateRes(@sOperationNotAllowed);
end;

constructor TMultiCaster.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FAppEvents := TComponentList.Create(False);
  with Application do
  begin
    OnActionExecute := DoActionExecute;
    OnActionUpdate := DoActionUpdate;
    OnActivate := DoActivate;
    OnDeactivate := DoDeactivate;
    OnException := DoException;
    OnHelp := DoHelp;
    OnHint := DoHint;
    OnIdle := DoIdle;
    OnMessage := DoMessage;
    OnMinimize := DoMinimize;
    OnRestore := DoRestore;
    OnShowHint := DoShowHint;
    OnShortCut := DoShortcut;
  end;
end;

destructor TMultiCaster.Destroy;
begin
  with Application do
  begin
    OnActionExecute := nil;
    OnActionUpdate := nil;
    OnActivate := nil;
    OnDeactivate := nil;
    OnException := nil;
    OnHelp := nil;
    OnHint := nil;
    OnIdle := nil;
    OnMessage := nil;
    OnMinimize := nil;
    OnRestore := nil;
    OnShowHint := nil;
    OnShortCut := nil;
  end;
  FAppEvents.Free;
  inherited Destroy;
end;

procedure TMultiCaster.DoActionExecute(Action: TBasicAction; var Handled: Boolean);
var
  I: Integer;
begin
  FDispatching := True;
  try
    for I := Count - 1 downto 0 do
    begin
      AppEvents[I].DoActionExecute(Action, Handled);
      if not FDispatching then Break;
    end;
  finally
    FDispatching := False;
  end;
end;

procedure TMultiCaster.DoActionUpdate(Action: TBasicAction; var Handled: Boolean);
var
  I: Integer;
begin
  FDispatching := True;
  try
    for I := Count - 1 downto 0 do
    begin
      AppEvents[I].DoActionUpdate(Action, Handled);
      if not FDispatching then Break;
    end;
  finally
    FDispatching := False;
  end;
end;

procedure TMultiCaster.DoActivate(Sender: TObject);
var
  I: Integer;
begin
  FDispatching := True;
  try
    for I := Count - 1 downto 0 do
    begin
      AppEvents[I].DoActivate(Sender);
      if not FDispatching then Break;
    end;
  finally
    FDispatching := False;
  end;
end;

procedure TMultiCaster.DoDeactivate(Sender: TObject);
var
  I: Integer;
begin
  FDispatching := True;
  try
    for I := Count - 1 downto 0 do
    begin
      AppEvents[I].DoDeactivate(Sender);
      if not FDispatching then Break;
    end;
  finally
    FDispatching := False;
  end;
end;

procedure TMultiCaster.DoException(Sender: TObject; E: Exception);
var
  I: Integer;
begin
  FDispatching := True;
  try
    for I := Count - 1 downto 0 do
    begin
      AppEvents[I].DoException(Sender, E);
      if not FDispatching then Break;
    end;
  finally
    FDispatching := False;
  end;
end;

function TMultiCaster.DoHelp(Command: Word; Data: Integer; var CallHelp: Boolean): Boolean;
var
  I: Integer;
begin
  FDispatching := True;
  try
    Result := False;
    for I := Count - 1 downto 0 do
    begin
      Result := Result or AppEvents[I].DoHelp(Command, Data, CallHelp);
      if not FDispatching then Break;
    end;
  finally
    FDispatching := False;
  end;
end;

procedure TMultiCaster.DoHint(Sender: TObject);
var
  I: Integer;
begin
  FDispatching := True;
  try
    for I := Count - 1 downto 0 do
    begin
      AppEvents[I].DoHint(Sender);
      if not FDispatching then Break;
    end;
  finally
    FDispatching := False;
  end;
end;

procedure TMultiCaster.DoIdle(Sender: TObject; var Done: Boolean);
var
  I: Integer;
begin
  FDispatching := True;
  try
    for I := Count - 1 downto 0 do
    begin
      AppEvents[I].DoIdle(Sender, Done);
      if not FDispatching then Break;
    end;
  finally
    FDispatching := False;
  end;
end;

procedure TMultiCaster.DoMessage(var Msg: TMsg; var Handled: Boolean);
var
  I: Integer;
begin
  FDispatching := True;
  try
    for I := Count - 1 downto 0 do
    begin
      AppEvents[I].DoMessage(Msg, Handled);
      if not FDispatching then Break;
    end;
  finally
    FDispatching := False;
  end;
end;

procedure TMultiCaster.DoMinimize(Sender: TObject);
var
  I: Integer;
begin
  FDispatching := True;
  try
    for I := Count - 1 downto 0 do
    begin
      AppEvents[I].DoMinimize(Sender);
      if not FDispatching then Break;
    end;
  finally
    FDispatching := False;
  end;
end;

procedure TMultiCaster.DoRestore(Sender: TObject);
var
  I: Integer;
begin
  FDispatching := True;
  try
    for I := Count - 1 downto 0 do
    begin
      AppEvents[I].DoRestore(Sender);
      if not FDispatching then Break;
    end;
  finally
    FDispatching := False;
  end;
end;

procedure TMultiCaster.DoShortcut(var Msg: TWMKey; var Handled: Boolean);
var
  I: Integer;
begin
  FDispatching := True;
  try
    for I := Count - 1 downto 0 do
    begin
      AppEvents[I].DoShortcut(Msg, Handled);
      if not FDispatching then Break;
    end;
  finally
    FDispatching := False;
  end;
end;

procedure TMultiCaster.DoShowHint(var HintStr: string;
  var CanShow: Boolean; var HintInfo: THintInfo);
var
  I: Integer;
begin
  FDispatching := True;
  try
    for I := Count - 1 downto 0 do
    begin
      AppEvents[I].DoShowHint(HintStr, CanShow, HintInfo);
      if not FDispatching then Break;
    end;
  finally
    FDispatching := False;
  end;
end;

function TMultiCaster.GetAppEvents(Index: Integer): TCustomApplicationEvents;
begin
  Result := TCustomApplicationEvents(FAppEvents[Index]);
end;

function TMultiCaster.GetCount: Integer;
begin
  Result := FAppEvents.Count;
end;

initialization
  MultiCaster := TMultiCaster.Create(Application);
end.
