{*******************************************************}
{                                                       }
{ Borland Delphi Visual Component Library               }
{                SOAP Support                           }
{                                                       }
{ Copyright (c) 2001 Borland Software Corporation       }
{                                                       }
{*******************************************************}

unit SOAPLinked;

interface

uses Classes, Rio, TypInfo, WebNode, SOAPPasInv, IntfInfo;

type

  TLinkedWebNode = class(TComponent, IWebNode)
  private
    FInvoker: TSoapPascalInvoker;
    IntfInfo: PTypeInfo;
    FClass: TClass;
  public
    constructor Create(AOwner: TComponent); override;
    destructor  Destroy; override;
    procedure   BeforeExecute(const IntfMetaData: TIntfMetaData; const MethodMetaData: TIntfMethEntry);
    procedure   Execute(const DataMsg: WideString; Resp: TStream); virtual;
    property Invoker: TSoapPascalInvoker read FInvoker;
  end;

  TLogLinkedWebNode = class(TLinkedWebNode)
  private
    FReqFile: string;
    FRespFile: string;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure  Execute(const DataMsg: WideString; Resp: TStream); override;
  published
    property ReqFile: string read FReqFile write FReqFile;
    property RespFile: string read FRespFile write FRespFile;
  end;

  TLinkedRIO = class(TRIO)
  private
    FLinkedWebNode: TLinkedWebNode;
  public
    function QueryInterface(const IID: TGUID; out Obj): HResult; override; stdcall;
    constructor Create(AOwner: TComponent);  overload; override; 
    constructor CreateFile(AOwner: TComponent; ReqFile, RespFile: string); overload;
    destructor Destroy; override;
    property WebNode: TLinkedWebNode read FLinkedWebNode;
  end;


implementation

uses SysUtils, OPConvert, OPToSOAPDomConv, InvokeRegistry, SOAPConst;

{ TLinkedRIO }

constructor TLinkedRIO.Create(AOwner: TComponent);
begin
  FLinkedWebNode := TLinkedWebNode.Create(nil);
  FLinkedWebNode.IntfInfo :=  IntfMD.Info;
  FWebNode := FLinkedWebNode as IWebNode;
  FConverter := TOPToSoapDomConvert.Create(nil) as IOpConvert;
  inherited;
end;

constructor TLinkedRIO.CreateFile(AOwner: TComponent; ReqFile,
  RespFile: string);
begin
  FLinkedWebNode := TLogLinkedWebNode.Create(nil);
  FLinkedWebNode.IntfInfo :=  IntfMD.Info;
  TLogLinkedWebNode(FLinkedWebNode).FReqFile := ReqFile;
  TLogLinkedWebNode(FLinkedWebNode).FRespFile := RespFile;
  FWebNode := FLinkedWebNode as IWebNode;
  FConverter := TOPToSoapDomConvert.Create(nil) as IOpConvert;
  inherited Create(AOwner);
end;

destructor TLinkedRIO.Destroy;
begin
  FConverter := nil;
  FWebNode := nil;
  WebNode.Free;
  inherited;
end;

function TLinkedRIO.QueryInterface(const IID: TGUID; out Obj): HResult;
begin
  Result := inherited QueryInterface(IID, Obj);
  FLinkedWebNode.IntfInfo := IntfMD.Info;
end;

{ TLinkedWebNode }

constructor TLinkedWebNode.Create(AOwner: TComponent);
begin
  inherited;
  FInvoker := TSoapPascalInvoker.Create(nil);
end;

destructor TLinkedWebNode.Destroy;
begin
  FInvoker.Free;
  inherited;
end;

procedure TLinkedWebNode.BeforeExecute(const IntfMetaData: TIntfMetaData; const MethodMetaData: TIntfMethEntry);
begin
end;

procedure TLinkedWebNode.Execute(const DataMsg: WideString; Resp: TStream);
var
 Stream: TStream;
 W: Widestring;
 S: string;
begin
  Stream := TMemoryStream.Create;
  try
    S := UTF8Encode(DataMsg);
    Stream.WriteBuffer(S[1], Length(S));
    Stream.Position := 0;
    InvRegistry.GetClassFromIntfInfo(IntfInfo, FClass);
    if FClass = nil then
      raise Exception.CreateFmt(SNoClassRegistered, [IntfInfo.Name]);
    FInvoker.Invoke(FClass, IntfInfo, '', Stream, Resp);
    if Resp.Size > 0 then
    begin
      SetLength(W, Resp.Size div 2);
      Resp.Position := 0;
      Resp.ReadBuffer(W[1], Resp.Size);
      S :=  UTF8Encode(W);
      Resp.Size := 0;
      Resp.WriteBuffer(S[1], Length(S));
    end;
  finally
    Stream.Free;
  end;
end;

{ TLogLinkedWebNode }

constructor TLogLinkedWebNode.Create(AOwner: TComponent);
begin
  inherited;
end;

destructor TLogLinkedWebNode.Destroy;
begin
  inherited;
end;

procedure TLogLinkedWebNode.Execute(const DataMsg: WideString;
  Resp: TStream);
var
 LogStream: TStream;
 S: string;
begin
  { Load request from file }
  LogStream := TFileStream.Create(ReqFile, fmCreate);
  try
    S := UTF8Encode(DataMsg);
    LogStream.WriteBuffer(S[1], Length(S));
  finally
    LogStream.Free;
  end;

  { Pass on for processing }
  inherited;

  { Dump result to out file }
  LogStream := TFileStream.Create(RespFile, fmCreate);
  try
    Resp.Position := 0;
    LogStream.CopyFrom(Resp, Resp.Size);
  finally
    LogStream.Free;
    Resp.Position := 0;
  end;
end;

end.
