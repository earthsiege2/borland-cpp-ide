unit IdIntercept;

interface

uses
  Classes,
  IdBaseComponent, IdSocketHandle;

type
  TIdConnectionIntercept = class(TIdBaseComponent)
  protected
    FBinding: TIdSocketHandle;
    FOnConnect: TNotifyEvent;
    FRecvHandling: Boolean;
    FSendHandling: Boolean;
    FIsClient: Boolean;
  public
    procedure Connect(ABinding: TIdSocketHandle); virtual;
    procedure DataReceived(var ABuffer; const AByteCount: integer); virtual;
    procedure DataSent(var ABuffer; const AByteCount: integer); virtual;
    procedure Disconnect; virtual;
    function Recv(var ABuf; ALen: Integer): Integer; virtual;
    function Send(var ABuf; ALen: Integer): Integer; virtual;

    property Binding: TIdSocketHandle read FBinding;
    property IsClient: Boolean read FIsClient;
    property RecvHandling: boolean read FRecvHandling;
    property SendHandling: boolean read FSendHandling;
  published
    property OnConnect: TNotifyEvent read FOnConnect write FOnConnect;
  end;

  TIdServerIntercept = class(TIdBaseComponent)
  public
    procedure Init; virtual; abstract;
    function Accept(ABinding: TIdSocketHandle): TIdConnectionIntercept; virtual;
      abstract;
  end;

implementation

procedure TIdConnectionIntercept.Disconnect;
begin
  FBinding := nil;
end;

procedure TIdConnectionIntercept.DataReceived(var ABuffer; const AByteCount:
  integer);
begin
end;

function TIdConnectionIntercept.Recv(var ABuf; ALen: Integer): Integer;
begin
  result := 0;
end;

function TIdConnectionIntercept.Send(var ABuf; ALen: Integer): Integer;
begin
  result := 0;
end;

procedure TIdConnectionIntercept.DataSent(var ABuffer; const AByteCount:
  integer);
begin
end;

procedure TIdConnectionIntercept.Connect(ABinding: TIdSocketHandle);
begin
  FBinding := ABinding;
  if assigned(FOnConnect) then
  begin
    FOnConnect(Self);
  end;
end;

end.
