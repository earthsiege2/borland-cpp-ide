{*******************************************************}
{                                                       }
{ Borland Delphi Visual Component Library               }
{                SOAP Support                           }
{                                                       }
{ Copyright (c) 2001 Borland Software Corporation       }
{                                                       }
{*******************************************************}

unit SOAPPasInv;

interface
uses
  Invoker, TypInfo, Classes, OPConvert, OPToSOAPDomConv;

type
  { Handlers to peek at data in/out of WebService }
  TBeforeDispatchEvent = procedure(const MethodName: string; const Request: TStream) of object;
  TAfterDispatchEvent  = procedure(const MethodName: string; SOAPResponse: TStream) of object;
  TOnExceptionEvent    = procedure(const MethodName: string; const Request: TStream; const Response: TStream) of object;

  { Allows access to DomConverter }
  IAdapterConverter = interface
  ['{82165DF4-B1B9-D511-9561-00C04FA06B45}']
    function GetDomConverter: TOPToSoapDomConvert;
  end;

  TSoapPascalInvoker = class(TComponent, IAdapterConverter)
  private
    FBeforeDispatchEvent: TBeforeDispatchEvent;
    FAfterDispatchEvent: TAfterDispatchEvent;
    FOnExceptionEvent: TOnExceptionEvent;
    procedure  SetDomConverter(Value: TOPToSoapDomConvert);
  protected
    FConverter: IOPConvert;
    { Hard-coded to DOM converter, for now }
    FDomConverter:  TOPToSoapDomConvert;
    function GetDomConverter: TOPToSoapDomConvert;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Invoke(AClass: TClass; IntfInfo: PTypeInfo; MethName: string; const Request: TStream; Response: TStream); virtual;
  published
    { Events }
    property BeforeDispatchEvent: TBeforeDispatchEvent read FBeforeDispatchEvent write FBeforeDispatchEvent;
    property AfterDispatchEvent: TAfterDispatchEvent read FAfterDispatchEvent write FAfterDispatchEvent;
    property OnExceptionEvent: TOnExceptionEvent read FOnExceptionEvent write FOnExceptionEvent;
    property Converter: TOPToSoapDomConvert read GetDomConverter write SetDomConverter;
  end;

implementation

uses SOAPConst, InvokeRegistry, SysUtils, InvConst, IntfInfo{$IFDEF MSWINDOWS}, ActiveX{$ENDIF}; 

constructor TSoapPascalInvoker.Create(AOwner: TComponent);
begin
  RCS;
  inherited Create(AOwner);
  FDomConverter := TOPToSoapDomConvert.Create(Self);
  FDomConverter.Name := 'Converter1'; { do not localize }
  FDomConverter.SetSubComponent(True);
{$IFDEF LINUX}
  FDomConverter.Options := FDomConverter.Options + [soReturnSuccessForFault];
{$ENDIF}
  FConverter := FDomConverter as IOPConvert;
end;

destructor  TSoapPascalInvoker.Destroy;
begin
  if Assigned(FConverter) then
    FConverter := nil;
  if Assigned(FDOMConverter) and (FDomConverter.Owner = Self) then
    FDomConverter.Free;
  inherited;
end;

procedure TSoapPascalInvoker.Invoke(AClass: TClass; IntfInfo: PTypeInfo; MethName: string; const Request: TStream;
   Response: TStream);
var
  Inv: TInterfaceInvoker;
  Obj: TObject;
  InvContext: TInvContext;
  IntfMD: TIntfMetaData;
  MethNum: Integer;
  ExMsg: WideString;
begin
  try
{$IFDEF MSWINDOWS}
    { Assumes we are using com dependent stuff (like the MSXML DOM) }
    CoInitialize(nil);
{$ENDIF}
    try
      MethNum := -1;
      GetIntfMetaData(IntfInfo, IntfMD, True);
      InvContext := TInvContext.Create;
      SetRemotableDataContext(InvContext);
      try
        { Retrieve index from method name }
        if MethName <> '' then
          MethNum := GetMethNum(IntfMD, MethName);
        { Converts request into context - also fills in MethNum if necessary }
        FConverter.MsgToInvContext(Request, IntfMD, MethNum, InvContext);
        try
          Obj := InvRegistry.GetInvokableObjectFromClass(AClass);
          if Obj = nil then
            raise Exception.CreateFmt(SNoClassRegistered, [IntfMD.Name]);
          { Request peeker }
          if Assigned(FBeforeDispatchEvent) then
            FBeforeDispatchEvent(MethName, Request);
          { Dispatch }
          Inv := TInterfaceInvoker.Create;
          try
            Inv.Invoke(Obj, IntfMD, MethNum, InvContext);
          finally
            Inv.Free;
          end;
          FConverter.MakeResponse(IntfMD, MethNum, InvContext, Response);
          { See if someone wants to monitor the response }
          if Assigned(FAfterDispatchEvent) then
            FAfterDispatchEvent(MethName, Response);
        except
          on E: Exception do
          begin
            ExMsg := FConverter.MakeFault(E);
            Response.Write(ExMsg[1], Length(ExMsg) * 2);
            { Exception peek }
            if Assigned(FOnExceptionEvent) then
              FOnExceptionEvent(MethName, Request, Response);
          end;
        end;
      finally
        InvContext.Free;
        SetRemotableDataContext(nil);
      end;
    except
      on E: Exception do
      begin
        FConverter := TOPToSoapDomConvert.Create(nil) as IOPConvert;
        ExMsg := FConverter.MakeFault(E);
        Response.Write(ExMsg[1], Length(ExMsg) * 2);
      end;
    end;
  finally
{$IFDEF MSWINDOWS}
    CoUnInitialize;
{$ENDIF}
  end;
end;

procedure TSoapPascalInvoker.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited;
  if (Operation = opRemove) and (AComponent = FDomConverter) then
  begin
    FConverter := nil;
    FDomConverter := nil;
  end;
end;

function TSoapPascalInvoker.GetDomConverter: TOPToSoapDomConvert;
begin
  Result := FDomConverter;
end;

procedure TSoapPascalInvoker.SetDomConverter(Value: TOPToSoapDomConvert);
begin
  if Assigned(FDOMConverter) and (FDomConverter.Owner = Self) then
  begin
    FConverter := nil;
    FDomConverter.Free;
  end;
  FDomConverter := Value;
  if Value <> nil then
  begin
    FConverter := Value;
    Value.FreeNotification(Self);
  end;
end;

end.


