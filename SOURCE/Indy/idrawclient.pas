unit IdRawClient;

interface

uses
  IdRawBase;

type
  TIdRawClient = class(TIdRawBase)
  published
    property ReceiveTimeout;
    property Host;
    property Port;
    property Protocol;
  end;

implementation

end.
