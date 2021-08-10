{*******************************************************}
{                                                       }
{      x Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 2000    Inprise Corporation       }
{                                                       }
{*******************************************************}

unit SOAPHTTPDisp;

interface

uses Classes;

type

  IHTTPSoapDispatch = interface
  ['{9E733EDC-7639-4DAF-96FF-BCF141F7D8F2}']
    procedure DispatchSOAP(const Path, SoapAction: WideString; const Request: TStream;
      Response: TStream);
  end;

  THTTPSoapDispatchNode = class(TComponent)
  private
    procedure SetSoapDispatcher(const Value: IHTTPSoapDispatch);
  protected
    FSoapDispatcher: IHTTPSoapDispatch;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
  public
    procedure DispatchSOAP(const Path, SoapAction: WideString; const Request: TStream;
      Response: TStream); virtual;
  published
    property Dispatcher: IHTTPSoapDispatch read FSoapDispatcher write SetSoapDispatcher;
  end;

implementation

procedure THTTPSoapDispatchNode.SetSoapDispatcher(const Value: IHTTPSoapDispatch);
begin
  ReferenceInterface(FSoapDispatcher, opRemove);
  FSoapDispatcher := Value;
  ReferenceInterface(FSoapDispatcher, opInsert);
end;

procedure THTTPSoapDispatchNode.Notification(AComponent: TComponent; Operation: TOperation);
begin
  inherited;
  if (Operation = opRemove) and AComponent.IsImplementorOf(FSoapDispatcher) then
    FSoapDispatcher := nil;
end;

procedure THTTPSoapDispatchNode.DispatchSOAP(const Path, SoapAction: WideString;
  const Request: TStream;  Response: TStream);
begin
end;

end.
