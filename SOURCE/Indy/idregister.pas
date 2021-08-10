unit IdRegister;

interface

{ DEFINE IndyCoolIcons}

{$IFDEF IndyCoolIcons}
{$R IdRegisterCool.dcr}
{$ELSE}
{$R IdRegister.dcr}
{$ENDIF}

procedure Register;

implementation

uses
{$IFNDEF Linux}
  IdSSLOpenSSL,
{$ENDIF}
  Classes,
  Controls,
  IdAntiFreeze,
  IdChargenServer, IdCoderIMF, IdCoderText, IdCoder3To4,
  IdCoderMessageDigest,
  IdDateTimeStamp, IdDICTServer, IdDiscardServer, IdDayTimeServer, IdDayTime,
  IdDNSResolver,
  IdEcho, IdEchoServer,
  IdFingerServer, IdFinger, IdFTP,
  IdGopher, IdGopherServer,
  IdHTTP, IdHTTPServer, IdHostnameServer,
  IdIrcServer, IdIPWatch, IdIMAP4Server, IdIcmpClient,
  IdLogDebug,
  IdMappedPortTCP, IdMessage,
  IdNetworkCalculator, IdNNTP, IdNNTPServer,
  IdPOP3,
  IdQotdServer, IdQotd,
  IdResourceStrings,
  IdSMTP, IdSNTP, IdSimpleServer,
  IdTCPClient, IdTCPServer, IdThreadMgrDefault, IdThreadMgrPool, IdTimeServer,
  IdTime, IdTrivialFTP, IdTrivialFTPServer, IdTelnet, IdTelnetServer,
  IdTunnelMaster, IdTunnelSlave,
  IdUDPClient, IdUDPServer,
  IdVCard,
  IdWhois,
  IdWhoIsServer;

procedure Register;
begin
  RegisterComponents(RSRegIndyClients, [{do not localize}
    TIdTCPClient,
      TIdUDPClient,

    TIdDayTime,
      TIdDNSResolver,
      TIdEcho,
      TIdFinger,
      TIdFTP,
      TIdGopher,
      TIdHTTP,
      TIdIcmpClient,
      TIdPOP3,
      TIdNNTP,
      TIdQOTD,
      TIdSMTP,
      TIdSNTP,
      TIdTelnet,
      TIdTime,
      TIdTrivialFTP,
      TIdWhois
      ]);

  RegisterComponents(RSRegIndyServers, [{do not localize}
    TIdTCPServer,
      TIdUDPServer,
      TIdChargenServer,
      TIdDayTimeServer,
      TIdDICTServer,
      TIdDISCARDServer,
      TIdECHOServer,
      TIdFingerServer,
      TIdGopherServer,
      TIdHostNameServer,
      TIdHTTPServer,
      TIdIMAP4Server,
      TIdIRCServer,
      TIdMappedPortTCP,
      TIdNNTPServer,
      TIdQOTDServer,
      TIdSimpleServer,
      TIdTelnetServer,
      TIdTimeServer,
      TIdTrivialFTPServer,
      TIdTunnelMaster,
      TIdTunnelSlave,
      TIdWhoIsServer
      ]);

  RegisterComponents(RSRegIndyMisc, [{do not localize}
    TIdAntiFreeze,
      TIdDateTimeStamp,
      TIdIPWatch,
      TIdLogDebug,
      TIdMessage,
      TIdNetworkCalculator,
      TIdThreadMgrDefault,
      TIdThreadMgrPool,
      TIdVCard,

    TIdIMFDecoder,
      TIdQuotedPrintableEncoder,
      TIdQuotedPrintableDecoder,
      TIdBase64Encoder,
      TIdBase64Decoder,
      TIdUUEncoder,
      TIdUUDecoder,
      TIdXXEncoder,
      TIdXXDecoder,
      TIdCoderMD2,
      TIdCoderMD4,
      TIdCoderMD5
{$IFNDEF Linux}
    , TIdConnectionInterceptOpenSSL,
      TIdServerInterceptOpenSSL
{$ENDIF}
    ]);
end;

initialization
{$IFDEF VER140}
  GroupDescendentsWith(TIdConnectionInterceptOpenSSL, Controls.TControl);
  GroupDescendentsWith(TIdServerInterceptOpenSSL, Controls.TControl);
{$ENDIF}

end.
