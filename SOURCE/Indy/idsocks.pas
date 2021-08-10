unit IdSocks;

interface

uses
  Classes,
  IdStack;

type
  TIdSocksRequest = record
    Version: Byte;
    OpCode: Byte;
    Port: Word;
    IpAddr: TIdInAddr;
    UserId: string[255];
  end;

  TIdSocksResponse = record
    Version: Byte;
    OpCode: Byte;
    Port: Word;
    IpAddr: TIdInAddr;
  end;

  TSocksVersion = (svNoSocks, svSocks4, svSocks4A, svSocks5);
  TSocksAuthentication = (saNoAuthentication, saUsernamePassword);

const
  ID_SOCKS_AUTH = saNoAuthentication;
  ID_SOCKS_VER = svNoSocks;
  ID_SOCKS_PORT = 0;

type
  TSocksInfo = class(TPersistent)
  protected
    FAuthentication: TSocksAuthentication;
    FHost: string;
    FPassword: string;
    FPort: Integer;
    FUserID: string;
    FVersion: TSocksVersion;
  public
    constructor Create;
    procedure Assign(Source: TPersistent); override;
  published
    property Authentication: TSocksAuthentication read FAuthentication write
      FAuthentication default ID_SOCKS_AUTH;
    property Host: string read FHost write FHost;
    property Password: string read FPassword write FPassword;
    property Port: Integer read FPort write FPort default ID_SOCKS_PORT;
    property UserID: string read FUserID write FUserID;
    property Version: TSocksVersion read FVersion write FVersion default
      ID_SOCKS_VER;
  end;

implementation

{ TSocksInfo }

procedure TSocksInfo.Assign(Source: TPersistent);
begin
  if Source is TSocksInfo then
    with Source as TSocksInfo do
    begin
      Self.Authentication := Authentication;
      Self.Host := Host;
      Self.Password := Password;
      Self.Port := Port;
      Self.UserID := UserID;
      Self.Version := Version;
    end
  else
    inherited;
end;

constructor TSocksInfo.Create;
begin
  inherited;
  Authentication := ID_SOCKS_AUTH;
  Version := ID_SOCKS_VER;
  Port := ID_SOCKS_PORT;
end;

end.
