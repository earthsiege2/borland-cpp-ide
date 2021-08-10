{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       Web server application components               }
{                                                       }
{  Copyright (c) 2001 Borland Software Corporation      }
{                                                       }
{*******************************************************}

unit SessColn;

interface

uses
  SyncObjs, Classes, SysUtils, SiteComp, WebContnrs, HTTPApp;

type

  TSessionItem = class;

  TSessionStatusFlag = (ssStarted, ssTerminated, ssTimeOut);
  TSessionStatusFlags = set of TSessionStatusFlag;
  TSessionItem = class(TCollectionItem)
  private
    FItems: TAbstractNamedVariants;
    FID: string;
    FExpired: Boolean;
    FTerminated: Boolean;
    FTimeoutMinutes: Integer;
    FStartTime: TDateTime;
    FTouchTime: TDateTime;
    FStatusFlags: TSessionStatusFlags;
    procedure SetItems(const Value: TAbstractNamedVariants);
    function GetExpirationTime: TDateTime;
    procedure SetExpired(const Value: Boolean);
    procedure SetTerminated(const Value: Boolean);
  public
    constructor Create(Collection: TCollection); override;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
    property ExpirationTime: TDateTime read GetExpirationTime;
    function IsActive: Boolean;
  published
    property ID: string read FID write FID;
    property StartTime: TDateTime read FStartTime write FStartTime;
    property TimeoutMinutes: Integer read FTimeoutMinutes write FTimeoutMinutes;
    property TouchTime: TDateTime read FTouchTime write FTouchTime;
    property Expired: Boolean read FExpired write SetExpired;
    property Terminated: Boolean read FTerminated write SetTerminated;
    property StatusFlags: TSessionStatusFlags read FStatusFlags write FStatusFlags;
    property Items: TAbstractNamedVariants read FItems write SetItems;
  end;

  TAbstractSessionStatusChange = class;

  TAbstractSessionIDGen = class;
  TSessions = class(TCollection)
  private
    FFileName: string;
    FLock: TMultiReadExclusiveWriteSynchronizer;
    FSessionIDGen: TAbstractSessionIDGen;
    FMaxSessions: Integer;
    function FindSession(AID: TSessionID): TSessionItem;
    function NextSessionID: TSessionID;
    function NewSession: TSessionItem;
    function NewSessionID: TSessionID;
    procedure ReadLock;
    procedure ReadUnlock;
    procedure WriteLock;
    procedure WriteUnlock;
    function GetMaxSessions: Integer;
    procedure SetMaxSessions(const Value: Integer);
    function GetActiveCount: Integer;
    { IWebSessionID }
  public
    constructor Create;
    destructor Destroy; override;
    function GetSessionIDGen: TAbstractSessionIDGen;
    function CreateSessionIDGen: TAbstractSessionIDGen; virtual;
    function ConnectSession(AID: TSessionID): Boolean;
    function ConnectActiveSession(AID: TSessionID): Boolean;
    procedure DisconnectSession(AID: TSessionID);
    function TerminateSession(AID: TSessionID): Boolean;
    procedure GetIDs(var AList: TList);
    function GetIDCount: Integer;
    function StartSession: TSessionID;
    function SessionExists(AID: TSessionID): Boolean;
    function TouchSession(AID: TSessionID): Boolean;
    procedure SetItemValue(AID: TSessionID; const AName: string; const AValue: Variant);
    function ItemValue(AID: TSessionID; const AName: string): Variant;
    procedure GetItems(AID: TSessionID; var AItems: TAbstractNamedVariants);
    function GetItemCount(AID: TSessionID): Integer;
    function GetSession(AID: TSessionID; var AItem: TSessionItem): Boolean;
    function GetStartTime(AID: TSessionID): TDateTime;
    function GetTimeoutMinutes(AID: TSessionID): Integer;
    procedure SetTimeoutMinutes(AID: TSessionID; AValue: Integer);
    function GetTouchTime(AID: TSessionID): TDateTime;
    function GetExpired(AID: TSessionID): Boolean;
    function GetExpirationTime(AID: TSessionID): TDateTime;
    function GetTerminated(AID: TSessionID): Boolean;
    function GetIsActive(AID: TSessionID): Boolean;
    function CheckStatusChange: Boolean;
    procedure NotifyStatusChange(AStatusChange: TAbstractSessionStatusChange);
    procedure LoadFromFile(const Filename: string);
    procedure SaveToFile(const Filename: string);
    procedure LoadFromStream(S: TStream);
    procedure SaveToStream(S: TStream);
    property FileName: string read FFileName write FFileName;
    property MaxSessions: Integer read GetMaxSessions write SetMaxSessions;
    property ActiveCount: Integer read GetActiveCount;
  end;

  TAbstractSessionStatusChange = class
  protected
    procedure SessionTerminated(AID: TSessionID; var AHandled: Boolean); virtual; abstract;
    procedure SessionTimeout(AID: TSessionID; var AHandled: Boolean); virtual; abstract;
    procedure SessionStarted(AID: TSessionID; var AHandled: Boolean); virtual; abstract;
  end;

  TAbstractSessionIDGen = class
  public
    function NextID: string; virtual; abstract;
  end;

  TSessionIDGen = class(TAbstractSessionIDGen)
  private
    FIDSize: Integer;
    FCharMap: array[0..61] of char;
    procedure InitCharMap;
  public
    constructor Create;
    function NextID: string; override;
  end;

  ESessionsException = class(EWebBrokerException);

var
  Sessions: TSessions;

implementation

uses
  DateUtils, SiteConst;

  { TSessionItem }

const
  NoTimeout = -1;

constructor TSessionItem.Create(Collection: TCollection);
begin
  FItems := TNamedVariantsList.Create;
  FStartTime := Now;
  FTouchTime := FStartTime;
  FTimeoutMinutes := NoTimeout;
  FStatusFlags := [ssStarted];
  inherited;
end;

destructor TSessionItem.Destroy;
begin
  inherited;
  FItems.Free;
end;

procedure TSessionItem.Assign(Source: TPersistent);
begin
  if Source is TSessionItem then
  begin
    if Assigned(Collection) then Collection.BeginUpdate;
    try
      FID := TSessionItem(Source).ID;
      FStartTime := TSessionItem(Source).StartTime;
      FTouchTime := TSessionItem(Source).TouchTime;
      FExpired := TSessionItem(Source).Expired;
      FTimeoutMinutes := TSessionItem(Source).TimeoutMinutes;
      FTerminated := TSessionItem(Source).Terminated;
      FStatusFlags := TSessionItem(Source).StatusFlags;

      Items.Assign(TSessionItem(Source).Items);
    finally
      if Assigned(Collection) then Collection.EndUpdate;
    end;
  end
  else
    inherited Assign(Source);
end;

procedure TSessionItem.SetItems(const Value: TAbstractNamedVariants);
begin
  FItems.Assign(Value);
end;

procedure TSessions.GetIDs(var AList: TList);
var
  I: Integer;
begin
  AList.Clear;
  ReadLock;
  try
    for I := 0 to Count - 1 do
      AList.Add(Pointer(TSessionItem(Items[I]).ID));
  finally
    ReadUnlock;
  end;
end;

function TSessionItem.GetExpirationTime: TDateTime;
begin
  if FTimeoutMinutes = NoTimeout then
    Result := 0
  else
    Result := IncMinute(FTouchTime, FTimeoutMinutes);
end;

function TSessionItem.IsActive: Boolean;
begin
  Result := not(Expired or Terminated);
end;

procedure TSessionItem.SetExpired(const Value: Boolean);
begin
  FExpired := Value;
  if Value then
    Include(FStatusFlags, ssTimeout)
  else
    Exclude(FStatusFlags, ssTimeout);
end;

procedure TSessionItem.SetTerminated(const Value: Boolean);
begin
  FTerminated := Value;
  if Value then
    Include(FStatusFlags, ssTerminated)
  else
    Exclude(FStatusFlags, ssTerminated);
end;

{ TSessions }

constructor TSessions.Create;
begin
  FLock := TMultiReadExclusiveWriteSynchronizer.Create;
  FMaxSessions := -1;
  inherited Create(TSessionItem);
end;

function TSessions.GetSession(AID: TSessionID; var AItem: TSessionItem): Boolean;
var
  Item: TSessionItem;
begin
  ReadLock;
  try
    Item := FindSession(AID);
    if Item <> nil then
    begin
      Result := True;
      AItem.Assign(Item);
      Exit;
    end;
  finally
    ReadUnlock;
  end;
  Result := False;
end;

function TSessions.SessionExists(AID: TSessionID): Boolean;
begin
  ReadLock;
  try
    Result := FindSession(AID) <> nil;
  finally
    ReadUnlock;
  end;
end;

// Lock before calling this function
function TSessions.FindSession(AID: TSessionID): TSessionItem;
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
  begin
    Result := Items[I] as TSessionItem;
    if Result.ID = AID then
      Exit;
  end;
  Result := nil;
end;

function ItemHasExpired(const Item: TSessionItem): Boolean;
begin
  if Item.TimeoutMinutes <> NoTimeout then
    Result := Item.ExpirationTime < Now
  else
    Result := False;
end;

function TSessions.CheckStatusChange: Boolean;
var
  Item: TSessionItem;
  I: Integer;
begin
  Result := False;
  ReadLock;
  try
    for I := 0 to Count - 1 do
    begin
      Item := Items[I] as TSessionItem;
      if Item.StatusFlags <> [] then
        Result := True
      else if Item.IsActive then
        if ItemHasExpired(Item) then
          Result := True;
      if Result then
        Break;
    end;
  finally
    ReadUnlock;
  end;
  if Result then
  begin
    WriteLock;
    try
      for I := 0 to Count - 1 do
      begin
        Item := Items[I] as TSessionItem;
        if Item.IsActive then
          if ItemHasExpired(Item) then
            Item.Expired := True;
      end;
    finally
      WriteUnlock;
    end;
  end;
end;

procedure TSessions.NotifyStatusChange(AStatusChange: TAbstractSessionStatusChange);
var
  I: Integer;
  Handled: Boolean;
  Item: TSessionItem;
begin
  WriteLock;
  try
    for I := 0 to Count - 1 do
    begin
      Item := Items[I] as TSessionItem;
      if Item.IsActive then
        if ItemHasExpired(Item) then
          Item.Expired := True;
      if ssStarted in Item.StatusFlags then
        if Assigned(AStatusChange) then
        begin
          Handled := False;
          AStatusChange.SessionStarted(Item.ID, Handled);
          if Handled then
            Item.StatusFlags := Item.StatusFlags - [ssStarted];
        end;
      if ssTimeout in Item.StatusFlags then
        if Assigned(AStatusChange) then
        begin
          Handled := False;
          AStatusChange.SessionTimeout(Item.ID, Handled);
          if Handled then
            Item.StatusFlags := Item.StatusFlags - [ssTimeout];
        end;
      if ssTerminated in Item.StatusFlags then
        if Assigned(AStatusChange) then
        begin
          Handled := False;
          AStatusChange.SessionTerminated(Item.ID, Handled);
          if Handled then
            Item.StatusFlags := Item.StatusFlags - [ssTerminated];
        end;
    end;
    for I := Count - 1 downto 0 do
    begin
      Item := Items[I] as TSessionItem;
      if (not Item.IsActive) and
        (([ssTerminated, ssTimeout] * Item.StatusFlags) = []) then
        Delete(I);
    end;
  finally
    WriteUnlock;
  end;
end;

procedure TSessions.LoadFromFile(const Filename: string);
var
  S: TFileStream;
begin
  WriteLock;
  try
    S := TFileStream.Create(Filename, fmOpenRead);
    try
      LoadFromStream(S);
    finally
      S.Free;
    end;
  finally
    WriteUnlock;
  end;
end;

type
  TSessionsWrapper = class(TComponent)
  private
    FSessions: TSessions;
  published
    property Sessions: TSessions read FSessions write FSessions;
  end;

procedure TSessions.LoadFromStream(S: TStream);
var
  Wrapper: TSessionsWrapper;
begin
  WriteLock;
  try
    Wrapper := TSessionsWrapper.Create(nil);
    try
      Wrapper.Sessions := TSessions.Create;
      S.ReadComponent(Wrapper);
      Assign(Wrapper.Sessions);
    finally
      Wrapper.Sessions.Free;
      Wrapper.Free;
    end;
  finally
    WriteUnlock;
  end;
end;

procedure TSessions.SaveToFile(const Filename: string);
var
  S: TStream;
begin
  ReadLock;
  try
    S := TFileStream.Create(Filename, fmCreate);
    try
      SaveToStream(S);
    finally
      S.Free;
    end;
  finally
    ReadUnlock;
  end;
end;

procedure TSessions.SaveToStream(S: TStream);
var
  Wrapper: TSessionsWrapper;
begin
  ReadLock;
  try
    Wrapper := TSessionsWrapper.Create(nil);
    try
      Wrapper.Sessions := Self;
      S.WriteComponent(Wrapper);
    finally
      Wrapper.Free;
    end;
  finally
    ReadUnlock;
  end;
end;

// Lock before calling
function TSessions.NewSession: TSessionItem;
var
  ID: TSessionID;
begin
  ID := NewSessionID;
  Result := TSessionItem.Create(Self);
  Result.ID := ID;
end;

procedure TSessions.SetItemValue(AID: TSessionID; const AName: string; const AValue: Variant);
var
  Item: TSessionItem;
begin
  WriteLock;
  try
    Item := FindSession(AID);
    if Assigned(Item) then
      Item.Items.Values[AName] := AValue;
  finally
    WriteUnlock;
  end;
end;

procedure TSessions.GetItems(AID: TSessionID; var AItems: TAbstractNamedVariants);
var
  Item: TSessionItem;
begin
  ReadLock;
  try
    Item := FindSession(AID);
    if Item <> nil then
      AItems.Assign(Item.Items)
    else
      AItems.Clear;
  finally
    ReadUnlock;
  end;
end;

function TSessions.GetItemCount(AID: TSessionID): Integer;
var
  Item: TSessionItem;
begin
  ReadLock;
  try
    Item := FindSession(AID);
    if Item <> nil then
      Result := Item.Items.Count
    else
      Result := 0;
  finally
    ReadUnlock;
  end;
end;

function TSessions.ItemValue(AID: TSessionID; const AName: string): Variant;
var
  S: TAbstractNamedVariants;
begin
  S := TNamedVariantsList.Create;
  try
    GetItems(AID, S);
    Result := S.Values[AName];
  finally
    S.Free;
  end;
end;

function TSessions.NextSessionID: TSessionID;
begin
  Result := GetSessionIDGen.NextID;
end;

// Lock before calling
function TSessions.NewSessionID: TSessionID;
begin
  Result := NextSessionID;
  while FindSession(Result) <> nil do
    Result := NextSessionID;
end;

function TSessions.TouchSession(AID: TSessionID): Boolean;
var
  Item: TSessionItem;
begin
  WriteLock;
  try
    Item := FindSession(AID);
    Result := Item <> nil;
    if Result then
      Item.TouchTime := Now;
  finally
    WriteUnlock;
  end;
end;

procedure TSessions.ReadLock;
begin
  FLock.BeginRead;
end;

procedure TSessions.ReadUnlock;
begin
  FLock.EndRead;
end;

procedure TSessions.WriteLock;
begin
  FLock.BeginWrite;
end;

procedure TSessions.WriteUnlock;
begin
  FLock.EndWrite;
end;

function TSessions.TerminateSession(AID: TSessionID): Boolean;
var
  Item: TSessionItem;
begin
  WriteLock;
  try
    Item := FindSession(AID);
    if Item <> nil then
    begin
      Result := True;
      Item.Terminated := True;
    end
    else
      Result := False;
  finally
    WriteUnlock;
  end;
end;

function TSessions.StartSession: TSessionID;
begin
  WriteLock;
  try
    if (FMaxSessions <> -1) and (ActiveCount >= FMaxSessions) then
      raise ESessionsException.Create(sMaximumSessionsExceeded);
    Result := NewSession.ID;
  finally
    WriteUnlock;
  end;
end;

function TSessions.ConnectSession(AID: TSessionID): Boolean;
begin
  ReadLock;
  try
    Result := FindSession(AID) <> nil;
  finally
    ReadUnlock;
  end;
end;

function TSessions.ConnectActiveSession(AID: TSessionID): Boolean;
begin
  Result := GetIsActive(AID);
  if Result then
    TouchSession(AID);
end;

procedure TSessions.DisconnectSession(AID: TSessionID);
begin
  // Do nothing
end;

function TSessions.GetExpired(AID: TSessionID): Boolean;
var
  Item: TSessionItem;
begin
  ReadLock;
  try
    Item := FindSession(AID);
    if Item <> nil then
      Result := Item.Expired
    else
      Result := False;
  finally
    ReadUnlock;
  end;
end;

function TSessions.GetExpirationTime(AID: TSessionID): TDateTime;
var
  Item: TSessionItem;
begin
  ReadLock;
  try
    Item := FindSession(AID);
    if Item <> nil then
      Result := Item.ExpirationTime
    else
      Result := 0;
  finally
    ReadUnlock;
  end;
end;

function TSessions.GetStartTime(AID: TSessionID): TDateTime;
var
  Item: TSessionItem;
begin
  ReadLock;
  try
    Item := FindSession(AID);
    if Item <> nil then
      Result := Item.StartTime
    else
      Result := 0;
  finally
    ReadUnlock;
  end;
end;

function TSessions.GetTerminated(AID: TSessionID): Boolean;
var
  Item: TSessionItem;
begin
  ReadLock;
  try
    Item := FindSession(AID);
    if Item <> nil then
      Result := Item.Terminated
    else
      Result := False;
  finally
    ReadUnlock;
  end;
end;

function TSessions.GetTimeoutMinutes(AID: TSessionID): Integer;
var
  Item: TSessionItem;
begin
  ReadLock;
  try
    Item := FindSession(AID);
    if Item <> nil then
      Result := Item.TimeoutMinutes
    else
      Result := NoTimeout;
  finally
    ReadUnlock;
  end;
end;

function TSessions.GetTouchTime(AID: TSessionID): TDateTime;
var
  Item: TSessionItem;
begin
  ReadLock;
  try
    Item := FindSession(AID);
    if Item <> nil then
      Result := Item.TouchTime
    else
      Result := 0;
  finally
    ReadUnlock;
  end;
end;

destructor TSessions.Destroy;
begin
  inherited;
  FLock.Free;
  FSessionIDGen.Free; 
end;

function TSessions.GetIsActive(AID: TSessionID): Boolean;
var
  Item: TSessionItem;
begin
  ReadLock;
  try
    Item := FindSession(AID);
    if Item <> nil then
      Result := Item.IsActive
    else
      Result := False;
  finally
    ReadUnlock;
  end;

end;

procedure TSessions.SetTimeoutMinutes(AID: TSessionID; AValue: Integer);
var
  Item: TSessionItem;
begin
  WriteLock;
  try
    Item := FindSession(AID);
    if Item <> nil then
      Item.TimeoutMinutes := AValue;
  finally
    WriteUnlock;
  end;
end;

function TSessions.GetIDCount: Integer;
begin
  ReadLock;
  try
    Result := Count;
  finally
    ReadUnlock;
  end;
end;

function TSessions.CreateSessionIDGen: TAbstractSessionIDGen;
begin
  Result := TSessionIDGen.Create;
end;

function TSessions.GetSessionIDGen: TAbstractSessionIDGen;
begin
  if FSessionIDGen = nil then
    FSessionIDGen := CreateSessionIDGen;
  Result := FSessionIDGen;
end;

function TSessions.GetMaxSessions: Integer;
begin
  ReadLock;
  try
    Result := FMaxSessions;
  finally
    ReadUnlock;
  end;
end;

procedure TSessions.SetMaxSessions(const Value: Integer);
begin
  if GetMaxSessions <> Value then
  begin
    WriteLock;
    try
      FMaxSessions := Value;
    finally
      WriteUnlock;
    end;
  end;
end;

function TSessions.GetActiveCount: Integer;
var
  I: Integer;
begin
  Result := 0;
  ReadLock;
  try
    for I := 0 to Count - 1 do
      if TSessionItem(Items[I]).IsActive then Inc(Result);
  finally
    ReadUnlock;
  end;
end;

{ TSessionIDGen }

constructor TSessionIDGen.Create;
begin
  inherited;
  randomize;
  InitCharMap;
  FIDSize := 16;
end;

procedure TSessionIDGen.InitCharMap;
var
  Chars: string;
  I, J: Integer;
begin
  Chars := 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789';
  Assert(Length(Chars) = Length(FCharMap));
  for I := Low(FCharMap) to High(FCharMap) do
  begin
    J := Random(Length(Chars));
    FCharMap[I] := Chars[J+1];
    Delete(Chars, J+1, 1);
  end;
end;

function TSessionIDGen.NextID: string;
var
  I: Integer;
begin
  SetLength(Result, FIDSize);
  for I := 1 to FIDSize do
    Result[I] := FCharMap[Random(High(FCharMap)+1)];
end;

initialization
  if Sessions = nil then
    Sessions := TSessions.Create;
finalization
  FreeAndNil(Sessions);
end.

