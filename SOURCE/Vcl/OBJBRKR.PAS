
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit ObjBrkr;

{$T-}

interface

uses
  MConnect, Classes, SysUtils;

type

  EBrokerException = class(Exception);

{ TServerItem }

  TServerItem = class(TCollectionItem)
  private
    FEnabled: Boolean;
    FComputerName: string;
    FHasFailed: Boolean;
    FPort: Integer;
  protected
    function GetDisplayName: string; override;
  public
    constructor Create(AOwner: TCollection); override;
    property HasFailed: Boolean read FHasFailed write FHasFailed;
  published
    property ComputerName: string read FComputerName write FComputerName;
    property Port: Integer read FPort write FPort default 211;
    property Enabled: Boolean read FEnabled write FEnabled default True;
  end;

{ TServerCollection }

  TServerCollection = class(TOwnedCollection)
  private
    function GetItem(Index: Integer): TServerItem;
    procedure SetItem(Index: Integer; Value: TServerItem);
  public
    constructor Create(AOwner: TComponent);
    function GetBalancedName: string;
    function GetNextName: string;
    function FindServer(const ComputerName: string): TServerItem;
    property Items[Index: Integer]: TServerItem read GetItem write SetItem; default;
  end;

{ TSimpleObjectBroker }

  TSimpleObjectBroker = class(TCustomObjectBroker)
  private
    FServers: TServerCollection;
    FLoadBalanced: Boolean;
    procedure SetServers(Value: TServerCollection);
    function IsServersStored: Boolean;
    function GetNextComputer: string;
    function GetServerData: OleVariant;
    procedure SetServerData(const Value: OleVariant);
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure SaveToStream(Stream: TStream);
    procedure LoadFromStream(Stream: TStream);
    property ServerData: OleVariant read GetServerData write SetServerData;
    { From TCustomObjectBroker }
    procedure SetConnectStatus(ComputerName: string; Success: Boolean); override;
    function GetComputerForGUID(GUID: TGUID): string; override;
    function GetComputerForProgID(const ProgID): string; override;
    function GetPortForComputer(const ComputerName: string): Integer; override;
  published
    property Servers: TServerCollection read FServers write SetServers stored IsServersStored;
    property LoadBalanced: Boolean read FLoadBalanced write FLoadBalanced default False;
  end;

implementation

uses MidConst;

{ TServerItem }

constructor TServerItem.Create(AOwner: TCollection);
begin
  inherited Create(AOwner);
  FPort := 211;
  FHasFailed := False;
  FEnabled := True;
end;

function TServerItem.GetDisplayName: string;
begin
  Result := ComputerName;
  if Result = '' then
    Result := inherited GetDisplayName;
end;

{ TServerCollection }

constructor TServerCollection.Create(AOwner: TComponent);
begin
  inherited Create(AOwner, TServerItem);
end;

function TServerCollection.FindServer(const ComputerName: string): TServerItem;
var
  i: Integer;
begin
  Result := nil;
  for i := 0 to Count - 1 do
    if Items[i].ComputerName = ComputerName then
    begin
      Result := Items[i];
      break;
    end;
end;

function TServerCollection.GetItem(Index: Integer): TServerItem;
begin
  Result := TServerItem(inherited GetItem(Index));
end;

function TServerCollection.GetNextName: string;
var
  i :Integer;
begin
  Result := '';
  for i := 0 to Count - 1 do
    if (not Items[i].HasFailed) and (Items[i].Enabled) then
    begin
      Result := Items[i].ComputerName;
      break;
    end;
  if Result = '' then
    raise EBrokerException.CreateRes(@SNoServers);
end;

function TServerCollection.GetBalancedName: string;
var
  i, GoodCount: Integer;
  GoodServers: array of TServerItem;
begin
  GoodCount := 0;
  SetLength(GoodServers, Count);
  for i := 0 to Count - 1 do
    if (not Items[i].HasFailed) and (Items[i].Enabled) then
    begin
      GoodServers[GoodCount] := Items[i];
      Inc(GoodCount);
    end;
  if GoodCount = 0 then
    raise EBrokerException.CreateRes(@SNoServers);
  Randomize;
  Result := GoodServers[Random(GoodCount)].ComputerName;
end;

procedure TServerCollection.SetItem(Index: Integer; Value: TServerItem);
begin
  inherited SetItem(Index, Value);
end;

{ TSimpleObjectBroker }

constructor TSimpleObjectBroker.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FLoadBalanced := False;
  FServers := TServerCollection.Create(Self);
end;

destructor TSimpleObjectBroker.Destroy;
begin
  FServers.Free;
  inherited Destroy;
end;

function TSimpleObjectBroker.GetServerData: OleVariant;
var
  Stream: TMemoryStream;
  P: Pointer;
begin
  Stream := TMemoryStream.Create;
  try
    SaveToStream(Stream);
    Result := VarArrayCreate([0, Stream.Size], varByte);
    P := VarArrayLock(Result);
    try
      Move(Stream.Memory^, P^, Stream.Size);
    finally
      VarArrayUnlock(Result);
    end;
  finally
    Stream.Free;
  end;
end;

procedure TSimpleObjectBroker.SetServerData(const Value: OleVariant);
var
  Stream: TMemoryStream;
  P: Pointer;
begin
  if VarIsNull(Value) or VarIsEmpty(Value) then
    Servers.Clear else
  begin
    Stream := TMemoryStream.Create;
    try
      Stream.Size := VarArrayHighBound(Value, 1);
      P := VarArrayLock(Value);
      try
        Stream.Write(P^, Stream.Size);
      finally
        VarArrayUnlock(Value);
      end;
      Stream.Position := 0;
      LoadFromStream(Stream);
    finally
      Stream.Free;
    end;
  end;
end;

procedure TSimpleObjectBroker.SaveToStream(Stream: TStream);
var
  Writer: TWriter;
begin
  Writer := TWriter.Create(Stream, 1024);
  try
    Writer.WriteCollection(Servers);
  finally
    Writer.Free;
  end;
end;

procedure TSimpleObjectBroker.LoadFromStream(Stream: TStream);
var
  Reader: TReader;
begin
  Servers.Clear;
  Reader := TReader.Create(Stream, 1024);
  try
    Reader.ReadValue;
    Reader.ReadCollection(Servers);
  finally
    Reader.Free;
  end;
end;

function TSimpleObjectBroker.GetNextComputer: string;
begin
  if LoadBalanced then
    Result := Servers.GetBalancedName else
    Result := Servers.GetNextName;
end;

function TSimpleObjectBroker.GetComputerForGUID(GUID: TGUID): string;
begin
  Result := GetNextComputer;
end;

function TSimpleObjectBroker.GetComputerForProgID(const ProgID): string;
begin
  Result := GetNextComputer;
end;

function TSimpleObjectBroker.GetPortForComputer(const ComputerName: string): Integer;
var
  Server: TServerItem;
begin
  Server := Servers.FindServer(ComputerName);
  if Assigned(Server) then
    Result := Server.Port else
    Result := 0;
end;

function TSimpleObjectBroker.IsServersStored: Boolean;
begin
  Result := Servers.Count > 0;
end;

procedure TSimpleObjectBroker.SetConnectStatus(ComputerName: string;
  Success: Boolean);
var
  Server: TServerItem;
begin
  Server := Servers.FindServer(ComputerName);
  if Assigned(Server) then Server.HasFailed := not Success;
end;

procedure TSimpleObjectBroker.SetServers(Value: TServerCollection);
begin
  FServers.Assign(Value);
end;

end.
