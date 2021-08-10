{***************************************************************}
{                                                               }
{   Borland Delphi Visual Component Library                     }
{                                                               }
{   Copyright (c) 2000-2001 Borland Software Corporation        }
{                                                               }
{***************************************************************}
unit WebSess;

interface

uses
  Classes, Contnrs, SysUtils, SiteComp, WebContnrs, HTTPApp, SessColn, WebDisp;

type

  TEndSessionReason = (esTimeout, esTerminate);
  TStartSessionEvent = procedure(ASender: TObject; ASession: TAbstractWebSession) of object;
  TEndSessionEvent = procedure(ASender: TObject; ASession: TAbstractWebSession; AReason: TEndSessionReason) of object;

  TCustomSessionsService = class(TComponent, ISessionsService,
    ISessionsServiceConnectID, IWebGetSessionIDs, ISessionsServicePersist)
  private
    FOnStartSession: TStartSessionEvent;
    FOnEndSession: TEndSessionEvent;
    FDefaultTimeout: Integer;
    procedure SetMaxSessions(const Value: Integer);
    function GetMaxSessions: Integer;
  protected
    { ISessionsService }
    function NewSession: IWebSession;
    procedure Clear;
    function CheckStatusChange: Boolean;
    procedure NotifyStatusChange;
    { ISessionsServiceConnectID }
    function Connect(AID: TSessionID): IWebSession;
    function ConnectActive(AID: TSessionID): IWebSession;
    { IWebGetSessionIDs }
    function GetSessionIDs: IWebSessionIDs;
    { ISessionsServicePersist }
    procedure LoadFromFile(const Filename: string);
    procedure SaveToFile(const Filename: string);
    procedure LoadFromStream(S: TStream);
    procedure SaveToStream(S: TStream);

  public
    constructor Create(AOwner: TComponent); override;
    property DefaultTimeout: Integer read FDefaultTimeout write FDefaultTimeout default 20;
    property OnStartSession: TStartSessionEvent read FOnStartSession write FOnStartSession;
    property OnEndSession: TEndSessionEvent read FOnEndSession write FOnEndSession;
    property MaxSessions: Integer read GetMaxSessions write SetMaxSessions default -1;
  end;

  TSessionsService = class(TCustomSessionsService)
  published
    property OnStartSession;
    property OnEndSession;
    property DefaultTimeout;
    property MaxSessions;
  end;

  TWebSessionImpl = class(TInterfacedObject, IWebSession, IWebSessionID,
    IWebSessionValues, IWebSessionAttributes)
  private
    FID: TSessionID;
  protected
    { IWebSession }
    procedure Terminate;
    { IWebSessionValues }
    procedure GetItems(var AItems: TAbstractNamedVariants);
    function GetItemCount: Integer;
    procedure SetValue(const AName: string; const AValue: Variant);
    function GetValue(const AName: string): Variant;
    property Values[const AName: string]: Variant read GetValue write SetValue;
    { IWebSessionAttributes }
    function GetStartTime: TDateTime;
    property StartTime: TDateTime read GetStartTime;
    function GetTimeoutMinutes: Integer;
    procedure SetTimeoutMinutes(AValue: Integer);
    property TimeoutMinutes: Integer read GetTimeoutMinutes;
    function GetTouchTime: TDateTime;
    property TouchTime: TDateTime read GetTouchTime;
    function GetExpired: Boolean;
    property Expired: Boolean read GetExpired;
    function GetTerminated: Boolean;
    property Terminated: Boolean read GetTerminated;
    function GetExpirationTime: TDateTime;
    property ExpirationTime: TDateTime read GetExpirationTime;
    function GetIsActive: Boolean;
    { IWebSessionID }
    function GetID: TSessionID;
    property ID: TSessionID read GetID;
  public
    constructor Create(AID: TSessionID);
    destructor Destroy; override;
  end;

  TWebSessionIDsImpl = class(TInterfacedObject, IWebSessionIDs)
  private
    FList: TList;
  protected
    function GetIDCount: Integer;
    function GetID(I: Integer): TSessionID;
  public
    constructor Create;
    destructor Destroy; override;
  end;

implementation

uses
  DateUtils;

{ TCustomSessionsService }

function TCustomSessionsService.CheckStatusChange: Boolean;
begin
  Result := Sessions.CheckStatusChange;
end;

type
  TSessionStatusChange = class(TAbstractSessionStatusChange)
  private
    FComponent: TCustomSessionsService;
  protected
    procedure SessionTerminated(AID: TSessionID; var AHandled: Boolean); override;
    procedure SessionTimeout(AID: TSessionID; var AHandled: Boolean); override;
    procedure SessionStarted(AID: TSessionID; var AHandled: Boolean); override;
  public
    constructor Create(AComponent: TCustomSessionsService);
  end;

procedure TCustomSessionsService.NotifyStatusChange;
var
  Change: TAbstractSessionStatusChange;
begin
  Change := TSessionStatusChange.Create(Self);
  try
    Sessions.NotifyStatusChange(Change);
  finally
    Change.Free;
  end;
end;

procedure TCustomSessionsService.Clear;
begin
  Sessions.Clear;
end;

function TCustomSessionsService.Connect(AID: TSessionID): IWebSession;
begin
  if Sessions.ConnectSession(AID) then
    Result := TWebSessionImpl.Create(AID)
  else
    Result := nil;
end;

function TCustomSessionsService.ConnectActive(AID: TSessionID): IWebSession;
begin
  if Sessions.ConnectActiveSession(AID) then
    Result := TWebSessionImpl.Create(AID)
  else
    Result := nil;
end;

constructor TCustomSessionsService.Create(AOwner: TComponent);
begin
  inherited;
  FDefaultTimeout := 20;
  Assert(Assigned(Sessions), 'Sessions variable not initialized');
end;

function TCustomSessionsService.GetSessionIDs: IWebSessionIDs;
begin
  Result := TWebSessionIDsImpl.Create;
end;

procedure TCustomSessionsService.LoadFromFile(const Filename: string);
begin
  Sessions.LoadFromFile(FileName);
end;

procedure TCustomSessionsService.LoadFromStream(S: TStream);
begin
  Sessions.LoadFromStream(S);
end;

function TCustomSessionsService.NewSession: IWebSession;
var
  ID: TSessionID;
  Intf: IWebSessionAttributes;
begin
  // StartSession also connects
  ID := Sessions.StartSession;
  Result := TWebSessionImpl.Create(ID);
  if Supports(Result, IWebSessionAttributes, Intf) then
    Intf.TimeoutMinutes := DefaultTimeout;
end;

procedure TCustomSessionsService.SaveToFile(const Filename: string);
begin
  Sessions.SaveToFile(FileName);
end;

procedure TCustomSessionsService.SaveToStream(S: TStream);
begin
  Sessions.SaveToStream(S);
end;

procedure TCustomSessionsService.SetMaxSessions(const Value: Integer);
begin
  Sessions.MaxSessions := Value;
end;

function TCustomSessionsService.GetMaxSessions: Integer;
begin
  Result := Sessions.MaxSessions;
end;

{ TWebSessionImpl }

constructor TWebSessionImpl.Create(AID: TSessionID);
begin
  FID := AID;
  inherited Create;
end;

destructor TWebSessionImpl.Destroy;
begin
  Sessions.DisconnectSession(FID);
  inherited;
end;

function TWebSessionImpl.GetExpired: Boolean;
begin
  Result := Sessions.GetExpired(FID);
end;

function TWebSessionImpl.GetExpirationTime: TDateTime;
begin
  Result := Sessions.GetExpirationTime(FID);
end;

function TWebSessionImpl.GetID: TSessionID;
begin
  Result := FID;
end;

function TWebSessionImpl.GetItemCount: Integer;
begin
  Result := Sessions.GetItemCount(FID);
end;

procedure TWebSessionImpl.GetItems(var AItems: TAbstractNamedVariants);
begin
  Sessions.GetItems(FID, AItems);
end;

function TWebSessionImpl.GetStartTime: TDateTime;
begin
  Result := Sessions.GetStartTime(FID);
end;

function TWebSessionImpl.GetTerminated: Boolean;
begin
  Result := Sessions.GetTerminated(FID);

end;

function TWebSessionImpl.GetTimeoutMinutes: Integer;
begin
  Result := Sessions.GetTimeoutMinutes(FID);
end;

function TWebSessionImpl.GetTouchTime: TDateTime;
begin
  Result := Sessions.GetTouchtime(FID);

end;

function TWebSessionImpl.GetValue(const AName: string): Variant;
begin
  Result := Sessions.ItemValue(FID, AName);
end;

procedure TWebSessionImpl.SetValue(const AName: string; const AValue: Variant);
begin
  Sessions.SetItemValue(FID, AName, AValue);
end;

procedure TWebSessionImpl.Terminate;
begin
  Sessions.TerminateSession(FID);
end;

function TWebSessionImpl.GetIsActive: Boolean;
begin
  Result := Sessions.GetIsActive(FID);
end;

procedure TWebSessionImpl.SetTimeoutMinutes(AValue: Integer);
begin
  Sessions.SetTimeoutMinutes(FID, AValue);
end;

{ TWebSessionIDsImpl }

constructor TWebSessionIDsImpl.Create;
begin
  FList := TList.Create;
  Sessions.GetIDs(FList);
end;

destructor TWebSessionIDsImpl.Destroy;
begin
  inherited;
  FList.Free;
end;

function TWebSessionIDsImpl.GetID(I: Integer): TSessionID;
begin
  Result := TSessionID(FList[I]);
end;

function TWebSessionIDsImpl.GetIDCount: Integer;
begin
  Result := FList.Count;

end;

{ TSessionStatusChange }

constructor TSessionStatusChange.Create(
  AComponent: TCustomSessionsService);
begin
  FComponent := AComponent;
  inherited Create;
end;

procedure TSessionStatusChange.SessionStarted(AID: TSessionID;
  var AHandled: Boolean);
var
  S: TAbstractWebSession;
begin
  if Assigned(FComponent.OnStartSession) then
  begin
    S := TWebSession.Create(FComponent, AID);
    try
      FComponent.OnStartSession(FComponent, S);
    finally
      S.Free;
    end;
  end;
  AHandled := True;
end;

procedure TSessionStatusChange.SessionTerminated(AID: TSessionID;
  var AHandled: Boolean);
var
  S: TAbstractWebSession;
begin
  if Assigned(FComponent.OnEndSession) then
  begin
    S := TWebSession.Create(FComponent, AID);
    try
      FComponent.OnEndSession(FComponent, S, esTerminate);
    finally
      S.Free;
    end;
  end;
  AHandled := True;
end;

procedure TSessionStatusChange.SessionTimeout(AID: TSessionID;
  var AHandled: Boolean);
var
  S: TAbstractWebSession;
begin
  if Assigned(FComponent.OnEndSession) then
  begin
    S := TWebSession.Create(FComponent, AID);
    try
      FComponent.OnEndSession(FComponent, S, esTimeout);
    finally
      S.Free;
    end;
  end;
  AHandled := True;
end;

end.

