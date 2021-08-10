unit IdException;

interface

uses
  SysUtils;

type
  EIdException = class(Exception);
  TClassIdException = class of EIdException;

  EIdAlreadyConnected = class(EIdException);
  EIdSilentException = class(EIdException);

  EIdInvalidServiceName = class(EIdException);
  EIdProtocolReplyError = class(EIdException)
  protected
    FReplyErrorCode: Integer;
  public
    constructor CreateError(const anErrCode: Integer; const asReplyMessage:
      string); reintroduce;
      virtual;
    property ReplyErrorCode: Integer read FReplyErrorCode;
  end;

  EIdDnsResolverError = class(EIdException);
  EIdInvalidSocket = class(EIdException);
  EIdSocketError = class(EIdException)
  private
    FLastError: Integer;
  public
    constructor CreateError(const anErr: Integer; const asMsg: string); virtual;
    property LastError: Integer read FLastError;
  end;

  EIdConnClosedGracefully = class(EIdSilentException);
  EIdResponseError = class(EIdException);
  EIdClosedSocket = class(EIdException);

  EIdTFTPException = class(EIdException);
  EIdTFTPFileNotFound = class(EIdTFTPException);
  EIdTFTPAccessViolation = class(EIdTFTPException);
  EIdTFTPAllocationExceeded = class(EIdTFTPException);
  EIdTFTPIllegalOperation = class(EIdTFTPException);
  EIdTFTPUnknownTransferID = class(EIdTFTPException);
  EIdTFTPFileAlreadyExists = class(EIdTFTPException);
  EIdTFTPNoSuchUser = class(EIdTFTPException);
  EIdTFTPOptionNegotiationFailed = class(EIdTFTPException); // RFC 1782

  EIdIcmpException = class(EIdException);

  EIdSetSizeExceeded = class(EIdException);
implementation

constructor EIdProtocolReplyError.CreateError(const anErrCode: Integer; const
  asReplyMessage: string);
begin
  inherited Create(asReplyMessage);
  FReplyErrorCode := anErrCode;
end;

constructor EIdSocketError.CreateError(const anErr: Integer; const asMsg:
  string);
begin
  FLastError := anErr;
  inherited Create(asMsg);
end;

end.
