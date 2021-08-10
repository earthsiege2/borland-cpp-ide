
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       Connection compatibility classes                }
{                                                       }
{       Copyright (c) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit MidasCon;

interface

uses
  Classes, MConnect, SConnect;

type

{ TRemoteServer }
{ Provided for compatiblity.  Switch to using the TDCOMConnection }

  TRemoteServer = class(TDCOMConnection)
  end;

{ TMidasConnection }
{ Provided for compatiblity.
  For ConnectType ctDCOM, switch to TDCOMConnection,
  for ctSockets, switch to TSocketConnection,
  for ctOLEnterprise, switch to TOLEnterpriseConnection. }

  TConnectType = (ctDCOM, ctSockets, ctOLEnterprise);

  TMidasConnection = class(TDCOMConnection)
  private
    FSubConnection: TDispatchConnection;
    FConnectType: TConnectType;
    FServerPort: Integer;
    FUseBroker: Boolean;
  protected
    procedure SetConnectType(Value: TConnectType); virtual;
    procedure SetUseBroker(Value: Boolean); virtual;
    procedure DoConnect; override;
    procedure DoDisconnect; override;
  public
    constructor Create(AOwner: TComponent); override;
  published
    property ConnectType: TConnectType read FConnectType write SetConnectType;
    property ServerPort: Integer read FServerPort write FServerPort default 211;
    property UseBroker: Boolean read FUseBroker write SetUseBroker;
  end;

implementation

constructor TMIDASConnection.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FServerPort := 211;
end;

procedure TMIDASConnection.DoConnect;

  procedure InitConnection(Dest: TDispatchConnection);
  begin
    with Dest do
    begin
      ServerName := Self.ServerName;
      ServerGUID := Self.ServerGUID;
    end;
  end;

var
  i: Integer;
begin
  case ConnectType of
    ctDCOM: inherited DoConnect;
    ctOLEnterprise:
    begin
      FSubConnection := TOLEnterpriseConnection.Create(Self);
      try
        with FSubConnection as TOLEnterpriseConnection do
        begin
          InitConnection(FSubConnection);
          if UseBroker then
            BrokerName := Self.ComputerName else
            ComputerName := Self.ComputerName;
          Connected := True;
          Self.SetAppServer(AppServer);
        end;
      except
        FSubConnection.Free;
        raise;
      end;
    end;
    ctSockets:
    begin
      FSubConnection := TSocketConnection.Create(Self);
      try
        with FSubConnection as TSocketConnection do
        begin
          for i := 1 to Length(Self.ComputerName) do
            if not (Self.ComputerName[i] in ['0'..'9','.']) then
            begin
              Host := Self.ComputerName;
              break;
            end;
          InitConnection(FSubConnection);
          if Host = '' then
            Address := Self.ComputerName;
          Port := Self.ServerPort;
          Connected := True;
          Self.SetAppServer(AppServer);
        end;
      except
        FSubConnection.Free;
        raise;
      end;
    end;
  end;
end;

procedure TMIDASConnection.DoDisconnect;
begin
  inherited DoDisconnect;
  FSubConnection.Free;
  FSubConnection := nil;
end;

procedure TMIDASConnection.SetConnectType(Value: TConnectType);
begin
  if Value <> FConnectType then
  begin
    SetConnected(False);
    FConnectType := Value;
  end;
end;

procedure TMIDASConnection.SetUseBroker(Value: Boolean);
begin
  if Value <> FUseBroker then
  begin
    FUseBroker := Value;
    SetConnected(False);
  end;
end;

end.
