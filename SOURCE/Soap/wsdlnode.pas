{*******************************************************}
{                                                       }
{ Borland Delphi Visual Component Library               }
{                SOAP Support                           }
{                                                       }
{ Copyright (c) 2001 Borland Software Corporation       }
{                                                       }
{*******************************************************}

unit WSDLNode;

interface

uses Classes, WebNode, OPConvert, XMLDoc, XMLIntf, WSDLItems, TypInfo, SysUtils, IntfInfo;

type

  { To report errors loading WSDLs }
  EWSDLLoadException = class(Exception)
  end;

  TWSDLView = class(TComponent)
  private
    FUserName: string;
    FPassword: string;
    FProxy: string;
    FPortType: string;
    FPort: string;
    FOperation: string;
    FService: string;
    FWSDL: TWSDLItems;
    FIWSDL: IXMLDocument;
    procedure SetWSDL(Value: TWSDLItems);
    procedure SetOperation(const Op: string);
    function  GetService: String;
    function  GetPort: String;
  public
    IntfInfo: PTypeInfo;
    procedure Activate;
    procedure SetDesignState(Designing: Boolean);
  published
    property PortType: string read FPortType write FPortType;
    property Port: string read GetPort write FPort;
    property Operation: string read FOperation write SetOperation;
    property Service: string read GetService write FService;
    property UserName: string read FUserName write FUserName;
    property Password: string read FPassword write FPassword;
    property Proxy: string read FProxy write FProxy;
    property WSDL: TWSDLItems read FWSDL write SetWSDL;
  end;

  TWSDLClientNode = class(TComponent, IWebNode)
  private
    FWSDLView: TWSDLView;
    FTransportNode: IWebNode;
    procedure SetTransportNode(Value: IWebNode);
  public
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure Execute(const DataMsg: WideString; Resp: TStream);
    procedure BeforeExecute(const IntfMetaData: TIntfMetaData; const MethodMetaData: TIntfMethEntry);
  published
    property WSDLView: TWSDLView read FWSDLView write FWSDLView;
    property TransportNode: IWebNode read FTransportNode  write SetTransportNode;
  end;

function ActivateWSDL(WSDL: TWSDLItems; const Name: string; const Password: string; const Proxy: string): Boolean;

implementation

uses WSDLIntf, xmldom, SOAPConst;

{ ActivateWSDL }
function ActivateWSDL(WSDL: TWSDLItems; const Name: string; const Password: string; const Proxy: string): Boolean;
begin
  Result := True;
  try
    { if not WSDL.Active then begin }
    WSDL.StreamLoader.UserName := Name;
    WSDL.StreamLoader.Password := Password;
    WSDL.StreamLoader.Proxy := Proxy;
    WSDL.Load(WSDL.FileName);
    { end }
  except
    on E: EDOMParseError do
    begin
      Result := False;
      raise EWSDLLoadException.CreateFmt(SWSDLError, [WSDL.Filename, E.Message]);
    end;
    on Ex: Exception do
    begin
      Result := False;
      raise Ex;
    end;
  end;
end;

{ TWSDLClientNode }

procedure  TWSDLClientNode.Execute(const DataMsg: WideString; Resp: TStream);
begin
end;

procedure TWSDLClientNode.BeforeExecute(const IntfMetaData: TIntfMetaData; const MethodMetaData: TIntfMethEntry);
begin
end;

procedure TWSDLClientNode.Notification(AComponent: TComponent; Operation: TOperation);
begin
  inherited;
  if (Operation = opRemove) and AComponent.IsImplementorOf(FTransportNode) then
    FTransportNode := nil;
end;

procedure TWSDLClientNode.SetTransportNode(Value: IWebNode);
begin
  if Assigned(Value) then
  begin
    ReferenceInterface(FTransportNode, opRemove);
    FTransportNode := Value;
    ReferenceInterface(FTransportNode, opInsert);
  end;
end;

{ TWSDLView }

procedure TWSDLView.SetDesignState(Designing: Boolean);
begin
  SetDesigning(Designing);
end;

procedure TWSDLView.SetWSDL(Value: TWSDLItems);
begin
  if Assigned(Value) then
  begin
    FWSDL := Value;
    FIWSDL := Value as IXMLDocument;
  end;
end;

procedure TWSDLView.Activate;
begin
  if Assigned(FWSDL) then
  begin
    ActivateWSDL(FWSDL, UserName, Password, Proxy);
  end;
end;

function TWSDLView.GetService: String;
var
  List: TWideStrings;
begin
  Result := FService;
  if Result = '' then
  begin
    { See if we can deduce the Service - i.e. if there's only one }
    if Assigned(FWSDL) and not (csDesigning in ComponentState) then
    begin
      Activate;
      List := TWideStrings.Create;
      try
        FWSDL.GetServices(List);
        if List.Count = 1 then
          FService := List.Strings[0];
        Result := FService;
      finally
        List.Free;
      end;
    end;
  end;
end;

function TWSDLView.GetPort: String;
var
  List: TWideStrings;
  Svc: string;
begin
  Result := FPort;
  if Result = '' then
  begin
    { See if we can deduce the Port - i.e. if there's only one }
    if Assigned(FWSDL) and not (csDesigning in ComponentState) then
    begin
      Svc := Service;
      if (Svc <> '') then
      begin
        List := TWideStrings.Create;
        try
          FWSDL.GetPortsForService(Svc, List);
          if List.Count = 1 then
            FPort := List.Strings[0];
          Result := FPort;
        finally
          List.Free;
        end;
      end;
    end;
  end;
end;

procedure TWSDLView.SetOperation(const Op: string);
begin
  FOperation := Op;
end;

end.
