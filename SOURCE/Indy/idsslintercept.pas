unit IdSSLIntercept;

interface

uses
  Classes,
  IdIntercept;

type
  TIdSSLConnectionIntercept = class(TIdConnectionIntercept)
  public
    constructor Create(AOwner: TComponent); override;
  end;

  TIdSSLServerIntercept = class(TIdServerIntercept)
  public
  end;

implementation

constructor TIdSSLConnectionIntercept.Create(AOwner: TComponent);
begin
  inherited;
  FRecvHandling := True;
  FSendHandling := True;
end;

end.
