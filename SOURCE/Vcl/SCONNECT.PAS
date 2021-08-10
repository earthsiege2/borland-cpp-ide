
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       Streamed Connection classes                     }
{                                                       }
{       Copyright (c) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit SConnect;

{$R-}

interface

uses
  Variants, Windows, Messages, Classes, SysUtils, MConnect, ScktComp, WinSock,
  WinInet, ComObj;

type

  {$HPPEMIT '#pragma link "wininet.lib"'}

  { IDataBlock }

  IDataBlock = interface(IUnknown)
  ['{CA6564C2-4683-11D1-88D4-00A0248E5091}']
    function GetBytesReserved: Integer; stdcall;
    function GetMemory: Pointer; stdcall;
    function GetSize: Integer; stdcall;
    procedure SetSize(Value: Integer); stdcall;
    function GetStream: TStream; stdcall;
    function GetSignature: Integer; stdcall;
    procedure SetSignature(Value: Integer); stdcall;
    procedure Clear; stdcall;
    function Write(const Buffer; Count: Integer): Integer; stdcall;
    function Read(var Buffer; Count: Integer): Integer; stdcall;
    procedure IgnoreStream; stdcall;
    function InitData(Data: Pointer; DataLen: Integer; CheckLen: Boolean): Integer; stdcall;
    property BytesReserved: Integer read GetBytesReserved;
    property Memory: Pointer read GetMemory;
    property Signature: Integer read GetSignature write SetSignature;
    property Size: Integer read GetSize write SetSize;
    property Stream: TStream read GetStream;
  end;

  { ISendDataBlock }

  ISendDataBlock = interface
  ['{87AD1043-470E-11D1-88D5-00A0248E5091}']
    function Send(const Data: IDataBlock; WaitForResult: Boolean): IDataBlock; stdcall;
  end;

  { ITransport }

  ITransport = interface(IUnknown)
  ['{CA6564C1-4683-11D1-88D4-00A0248E5091}']
    function GetWaitEvent: THandle; stdcall;
    function GetConnected: Boolean; stdcall;
    procedure SetConnected(Value: Boolean); stdcall;
    function Receive(WaitForInput: Boolean; Context: Integer): IDataBlock; stdcall;
    function Send(const Data: IDataBlock): Integer; stdcall;
    property Connected: Boolean read GetConnected write SetConnected;
  end;

  { IDataIntercept }

  IDataIntercept = interface
  ['{B249776B-E429-11D1-AAA4-00C04FA35CFA}']
    procedure DataIn(const Data: IDataBlock); stdcall;
    procedure DataOut(const Data: IDataBlock); stdcall;
  end;

  { TDataBlock }

  TDataBlock = class(TInterfacedObject, IDataBlock)
  private
    FStream: TMemoryStream;
    FReadPos: Integer;
    FWritePos: Integer;
    FIgnoreStream: Boolean;
  protected
    { IDataBlock }
    function GetBytesReserved: Integer; stdcall;
    function GetMemory: Pointer; stdcall;
    function GetSize: Integer; stdcall;
    procedure SetSize(Value: Integer); stdcall;
    function GetStream: TStream; stdcall;
    function GetSignature: Integer; stdcall;
    procedure SetSignature(Value: Integer); stdcall;
    procedure Clear; stdcall;
    function Write(const Buffer; Count: Integer): Integer; stdcall;
    function Read(var Buffer; Count: Integer): Integer; stdcall;
    procedure IgnoreStream; stdcall;
    function InitData(Data: Pointer; DataLen: Integer; CheckLen: Boolean): Integer; stdcall;
    property BytesReserved: Integer read GetBytesReserved;
    property Memory: Pointer read GetMemory;
    property Signature: Integer read GetSignature write SetSignature;
    property Size: Integer read GetSize write SetSize;
    property Stream: TStream read GetStream;
  public
    constructor Create;
    destructor Destroy; override;
  end;

  { TDataBlockInterpreter }

const

  { Action Signatures }

  CallSig         = $DA00; // Call signature
  ResultSig       = $DB00; // Result signature
  asError         = $01;   // Specify an exception was raised
  asInvoke        = $02;   // Specify a call to Invoke
  asGetID         = $03;   // Specify a call to GetIdsOfNames
  asCreateObject  = $04;   // Specify a com object to create
  asFreeObject    = $05;   // Specify a dispatch to free
  asGetServers    = $10;   // Get classname list
  asGetGUID       = $11;   // Get GUID for ClassName
  asGetAppServers = $12;   // Get AppServer classname list
  asSoapCommand   = $14;   // Soap command
  asMask          = $FF;   // Mask for action

type

  PIntArray = ^TIntArray;
  TIntArray = array[0..0] of Integer;

  PVariantArray = ^TVariantArray;
  TVariantArray = array[0..0] of OleVariant;

  TVarFlag = (vfByRef, vfVariant);
  TVarFlags = set of TVarFlag;

  EInterpreterError = class(Exception);

  TDataDispatch = class;


  TCustomDataBlockInterpreter = class
  protected
    procedure AddDispatch(Value: TDataDispatch); virtual; abstract;
    procedure RemoveDispatch(Value: TDataDispatch); virtual; abstract;

    { Sending Calls }
    procedure CallFreeObject(DispatchIndex: Integer); virtual; abstract;
    function CallGetIDsOfNames(DispatchIndex: Integer; const IID: TGUID; Names: Pointer; NameCount, LocaleID: Integer; DispIDs: Pointer): HResult; virtual; stdcall; abstract;
    function CallInvoke(DispatchIndex, DispID: Integer; const IID: TGUID; LocaleID: Integer;
      Flags: Word; var Params; VarResult, ExcepInfo, ArgErr: Pointer): HResult; virtual; stdcall; abstract;
    function CallGetServerList: OleVariant; virtual; abstract;

    { Receiving Calls }


    function InternalCreateObject(const ClassID: TGUID): OleVariant; virtual; abstract;
    function CreateObject(const Name: string): OleVariant; virtual; abstract;
    function StoreObject(const Value: OleVariant): Integer; virtual; abstract;
    function LockObject(ID: Integer): IDispatch; virtual; abstract;
    procedure UnlockObject(ID: Integer; const Disp: IDispatch); virtual; abstract;
    procedure ReleaseObject(ID: Integer); virtual; abstract;
    function CanCreateObject(const ClassID: TGUID): Boolean; virtual; abstract;
    function CallCreateObject(Name: string): OleVariant;  virtual;  abstract;
  public
    procedure InterpretData(const Data: IDataBlock); virtual; abstract;
  end;


  { TBinary... }
  TDataBlockInterpreter = class(TCustomDataBlockInterpreter)
  private
    FDispatchList: TList;
    FDispList: OleVariant;
    FSendDataBlock: ISendDataBlock;
    FCheckRegValue: string;
    function GetVariantPointer(const Value: OleVariant): Pointer;
    procedure CopyDataByRef(const Source: TVarData; var Dest: TVarData);
    function ReadArray(VType: Integer; const Data: IDataBlock): OleVariant;
    procedure WriteArray(const Value: OleVariant; const Data: IDataBlock);
    function ReadVariant(out Flags: TVarFlags; const Data: IDataBlock): OleVariant;
    procedure WriteVariant(const Value: OleVariant; const Data: IDataBlock);
    procedure DoException(const Data: IDataBlock);
  protected
    procedure AddDispatch(Value: TDataDispatch); override;
    procedure RemoveDispatch(Value: TDataDispatch); override;
    function InternalCreateObject(const ClassID: TGUID): OleVariant; override;
    function CreateObject(const Name: string): OleVariant; override;
    function StoreObject(const Value: OleVariant): Integer; override;
    function LockObject(ID: Integer): IDispatch; override;
    procedure UnlockObject(ID: Integer; const Disp: IDispatch); override;
    procedure ReleaseObject(ID: Integer); override;
    function CanCreateObject(const ClassID: TGUID): Boolean; override;

    {Sending Calls}
    procedure CallFreeObject(DispatchIndex: Integer); override;
    function CallGetIDsOfNames(DispatchIndex: Integer; const IID: TGUID; Names: Pointer;
      NameCount, LocaleID: Integer; DispIDs: Pointer): HResult; override;
    function CallInvoke(DispatchIndex, DispID: Integer; const IID: TGUID; LocaleID: Integer;
      Flags: Word; var Params; VarResult, ExcepInfo, ArgErr: Pointer): HResult;  override;
    function CallGetServerList: OleVariant; override;

    {Receiving Calls}
    procedure DoCreateObject(const Data: IDataBlock);
    procedure DoFreeObject(const Data: IDataBlock);
    procedure DoGetIDsOfNames(const Data: IDataBlock);
    procedure DoInvoke(const Data: IDataBlock);
    function DoCustomAction(Action: Integer; const Data: IDataBlock): Boolean; virtual;
    procedure DoGetAppServerList(const Data: IDataBlock);
    procedure DoGetServerList(const Data: IDataBlock);

  public
    constructor Create(SendDataBlock: ISendDataBlock; CheckRegValue: string);
    destructor Destroy; override;
    function CallCreateObject(Name: string): OleVariant;  override;
    procedure InterpretData(const Data: IDataBlock); override;
  end;

{ TDataDispatch }

  TDataDispatch = class(TInterfacedObject, IDispatch)
  private
    FDispatchIndex: Integer;
    FInterpreter: TCustomDataBlockInterpreter;
  protected
    property DispatchIndex: Integer read FDispatchIndex;
    { IDispatch }
    function GetTypeInfoCount(out Count: Integer): HResult; stdcall;
    function GetTypeInfo(Index, LocaleID: Integer; out TypeInfo): HResult; stdcall;
    function GetIDsOfNames(const IID: TGUID; Names: Pointer;
      NameCount, LocaleID: Integer; DispIDs: Pointer): HResult; stdcall;
    function Invoke(DispID: Integer; const IID: TGUID; LocaleID: Integer;
      Flags: Word; var Params; VarResult, ExcepInfo, ArgErr: Pointer): HResult; stdcall;
  public
    constructor Create(Interpreter: TCustomDataBlockInterpreter; DispatchIndex: Integer);
    destructor Destroy; override;
  end;

  { TTransportThread }

const
  THREAD_SENDSTREAM       = WM_USER + 1;
  THREAD_RECEIVEDSTREAM   = THREAD_SENDSTREAM + 1;
  THREAD_EXCEPTION        = THREAD_RECEIVEDSTREAM + 1;
  THREAD_SENDNOTIFY       = THREAD_EXCEPTION + 1;
  THREAD_REPLACETRANSPORT = THREAD_SENDNOTIFY + 1;

type

  TTransportThread = class(TThread)
  private
    FParentHandle: THandle;
    FSemaphore: THandle;
    FTransport: ITransport;
  public
    constructor Create(AHandle: THandle; Transport: ITransport); virtual;
    destructor Destroy; override;
    property Semaphore: THandle read FSemaphore;
    procedure Execute; override;
  end;

  { TStreamedConnection }

  TStreamedConnection = class(TDispatchConnection, ISendDataBlock)
  private
    FRefCount: Integer;
    FHandle: THandle;
    FTransport: TTransportThread;
    FTransIntf: ITransport;
    FInterpreter: TCustomDataBlockInterpreter;
    FSupportCallbacks: Boolean;
    FInterceptGUID: TGUID;
    FInterceptName: string;
    function GetHandle: THandle;
    procedure TransportTerminated(Sender: TObject);
    procedure SetSupportCallbacks(Value: Boolean);
    procedure SetInterceptName(const Value: string);
    function GetInterceptGUID: string;
    procedure SetInterceptGUID(const Value: string);
  protected
    { IUnknown }
    function QueryInterface(const IID: TGUID; out Obj): HResult; reintroduce; stdcall;
    function _AddRef: Integer; stdcall;
    function _Release: Integer; stdcall;
    { ISendDataBlock }
    function Send(const Data: IDataBlock; WaitForResult: Boolean): IDataBlock; stdcall;

    procedure InternalOpen; virtual;
    procedure InternalClose; virtual;

    procedure ThreadReceivedStream(var Message: TMessage); message THREAD_RECEIVEDSTREAM;
    procedure ThreadException(var Message: TMessage); message THREAD_EXCEPTION;
    procedure WndProc(var Message: TMessage);
    function CreateTransport: ITransport; virtual;
    procedure DoConnect; override;
    procedure DoDisconnect; override;
    procedure DoError(E: Exception); virtual;

    function GetInterpreter: TCustomDataBlockInterpreter; virtual;

    property Interpreter: TCustomDataBlockInterpreter read GetInterpreter;
    property Handle: THandle read GetHandle;
    property SupportCallbacks: Boolean read FSupportCallbacks write SetSupportCallbacks default True;
    property InterceptGUID: string read GetInterceptGUID write SetInterceptGUID;
    property InterceptName: string read FInterceptName write SetInterceptName;
  public
    function GetInterceptorList: OleVariant; virtual;
    function GetServerList: OleVariant; override;
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  end;

  { TSocketTransport }

  ESocketConnectionError = class(Exception);

  TSocketTransport = class(TInterfacedObject, ITransport)
  private
    FEvent: THandle;
    FAddress: string;
    FHost: string;
    FPort: Integer;
    FClientSocket: TClientSocket;
    FSocket: TCustomWinSocket;
    FInterceptGUID: string;
    FInterceptor: IDataIntercept;
    FCreateAttempted: Boolean;
    function CheckInterceptor: Boolean;
    procedure InterceptIncoming(const Data: IDataBlock);
    procedure InterceptOutgoing(const Data: IDataBlock);
  protected
    { ITransport }
    function GetWaitEvent: THandle; stdcall;
    function GetConnected: Boolean; stdcall;
    procedure SetConnected(Value: Boolean); stdcall;
    function Receive(WaitForInput: Boolean; Context: Integer): IDataBlock; stdcall;
    function Send(const Data: IDataBlock): Integer; stdcall;
  public
    constructor Create;
    destructor Destroy; override;
    property Host: string read FHost write FHost;
    property Address: string read FAddress write FAddress;
    property Port: Integer read FPort write FPort;
    property Socket: TCustomWinSocket read FSocket write FSocket;
    property InterceptGUID: string read FInterceptGUID write FInterceptGUID;
  end;

  { TSocketConnection }

  TSocketConnection = class(TStreamedConnection)
  private
    FAddress: string;
    FHost: string;
    FPort: Integer;
    procedure SetAddress(Value: string);
    procedure SetHost(Value: string);
    function IsHostStored: Boolean;
    function IsAddressStored: Boolean;
  protected
    function CreateTransport: ITransport; override;
    procedure DoConnect; override;
  public
    constructor Create(AOwner: TComponent); override;
  published
    property Address: string read FAddress write SetAddress stored IsAddressStored;
    property Host: string read FHost write SetHost stored IsHostStored;
    property InterceptGUID;
    property InterceptName;
    property Port: Integer read FPort write FPort default 211;
    property SupportCallbacks;
    property ObjectBroker;
  end;

  { TWebConnection }

  TWebConnection = class(TStreamedConnection, ITransport)
  private
    FAgent: string;
    FUserName: string;
    FPassword: string;
    FURL: string;
    FURLHost: string;
    FURLSite: string;
    FURLPort: Integer;
    FURLScheme: Integer;
    FProxy: string;
    FProxyByPass: string;
    FInetRoot: HINTERNET;
    FInetConnect: HINTERNET;
    FInterpreter: TCustomDataBlockInterpreter;
    procedure Check(Error: Boolean);
    function IsURLStored: Boolean;
    procedure SetURL(const Value: string);
  protected
    { ITransport }
    function GetInterpreter: TCustomDataBlockInterpreter; override;
    function GetWaitEvent: THandle; stdcall;
    function Transport_GetConnected: Boolean; stdcall;
    function ITransport.GetConnected = Transport_GetConnected;
    procedure Transport_SetConnected(Value: Boolean); stdcall;
    procedure ITransport.SetConnected = Transport_SetConnected;
    function Receive(WaitForInput: Boolean; Context: Integer): IDataBlock; stdcall;
    function Send(const Data: IDataBlock): Integer; stdcall;
  protected
    function CreateTransport: ITransport; override;
    procedure DoConnect; override;
    property SupportCallbacks default False;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  published
    property Agent: string read FAgent write FAgent;
    property UserName: string read FUserName write FUserName;
    property Password: string read FPassword write FPassword;
    property URL: string read FURL write SetURL stored IsURLStored;
    property Proxy: string read FProxy write FProxy;
    property ProxyByPass: string read FProxyByPass write FProxyByPass;
    property ObjectBroker;
  end;

  { TPacketInterceptFactory }

  TPacketInterceptFactory = class(TComObjectFactory)
  public
    procedure UpdateRegistry(Register: Boolean); override;
  end;
  {$EXTERNALSYM TPacketInterceptFactory}

{ Utility functions }

function LoadWinSock2: Boolean;
procedure GetPacketInterceptorList(List: TStringList);

var
  WSACreateEvent: function: THandle stdcall;
  WSAResetEvent: function(hEvent: THandle): Boolean stdcall;
  WSACloseEvent: function(hEvent: THandle): Boolean stdcall;
  WSAEventSelect: function(s: TSocket; hEventObject: THandle; lNetworkEvents: Integer): Integer stdcall;

implementation

uses
  ActiveX, MidConst, RTLConsts;

var
  hWinSock2: THandle;

{ Utility functions }

procedure CheckSignature(Sig: Integer);
begin
  if (Sig and $FF00 <> CallSig) and
     (Sig and $FF00 <> ResultSig) then
    raise Exception.CreateRes(@SInvalidDataPacket);
end;

function LoadWinSock2: Boolean;
const
  DLLName = 'ws2_32.dll';
begin
  Result := hWinSock2 > 0;
  if Result then Exit;
  hWinSock2 := LoadLibrary(PChar(DLLName));
  Result := hWinSock2 > 0;
  if Result then
  begin
    WSACreateEvent := GetProcAddress(hWinSock2, 'WSACreateEvent');
    WSAResetEvent := GetProcAddress(hWinSock2, 'WSAResetEvent');
    WSACloseEvent := GetProcAddress(hWinSock2, 'WSACloseEvent');
    WSAEventSelect := GetProcAddress(hWinSock2, 'WSAEventSelect');
  end;
end;

procedure GetPacketInterceptorList(List: TStringList);
var
  EnumGUID: IEnumGUID;
  Fetched: Cardinal;
  Guid: TGUID;
  Rslt: HResult;
  CatInfo: ICatInformation;
  I: Integer;
  ClassIDKey: HKey;
  S: string;
  Buffer: array[0..255] of Char;
begin
  List.Clear;
  Rslt := CoCreateInstance(CLSID_StdComponentCategoryMgr, nil,
    CLSCTX_INPROC_SERVER, ICatInformation, CatInfo);
  if Succeeded(Rslt) then
  begin
    OleCheck(CatInfo.EnumClassesOfCategories(1, @CATID_MIDASInterceptor, 0, nil, EnumGUID));
    while EnumGUID.Next(1, Guid, Fetched) = S_OK do
      List.Add(ClassIDToProgID(Guid));
  end else
  begin
    if RegOpenKey(HKEY_CLASSES_ROOT, 'CLSID', ClassIDKey) <> 0 then
      try
        I := 0;
        while RegEnumKey(ClassIDKey, I, Buffer, SizeOf(Buffer)) = 0 do
        begin
          S := Format(SCatImplKey,[Buffer, GUIDToString(CATID_MIDASInterceptor)]);
          List.Add(ClassIDToProgID(StringToGUID(Buffer)));
          Inc(I);
        end;
      finally
        RegCloseKey(ClassIDKey);
      end;
  end;
end;

procedure FreeWinSock2;
begin
  if hWinSock2 > 0 then
  begin
    WSACreateEvent := nil;
    WSAResetEvent := nil;
    WSACloseEvent := nil;
    WSAEventSelect := nil;
    FreeLibrary(hWinSock2);
  end;
  hWinSock2 := 0;
end;

procedure GetDataBrokerList(List: TStringList; const RegCheck: string);

  function OpenRegKey(Key: HKey; const SubKey: string): HKey;
  begin
    if Windows.RegOpenKey(Key, PChar(SubKey), Result) <> 0 then Result := 0;
  end;

  function EnumRegKey(Key: HKey; Index: Integer; var Value: string): Boolean;
  var
    Buffer: array[0..255] of Char;
  begin
    Result := False;
    if Windows.RegEnumKey(Key, Index, Buffer, SizeOf(Buffer)) = 0 then
    begin
      Value := Buffer;
      Result := True;
    end;
  end;

  function QueryRegKey(Key: HKey; const SubKey: string;
    var Value: string): Boolean;
  var
    BufSize: Longint;
    Buffer: array[0..255] of Char;
  begin
    Result := False;
    BufSize := SizeOf(Buffer);
    if Windows.RegQueryValue(Key, PChar(SubKey), Buffer, BufSize) = 0 then
    begin
      Value := Buffer;
      Result := True;
    end;
  end;

  procedure CloseRegKey(Key: HKey);
  begin
    RegCloseKey(Key);
  end;

var
  I: Integer;
  ClassIDKey: HKey;
  ClassID, S: string;
begin
  List.Clear;
  ClassIDKey := OpenRegKey(HKEY_CLASSES_ROOT, 'CLSID');
  if ClassIDKey <> 0 then
    try
      I := 0;
      while EnumRegKey(ClassIDKey, I, ClassID) do
      begin
        if RegCheck <> '' then
        begin
          QueryRegKey(ClassIDKey, ClassID + '\' + RegCheck, S);
          if S <> SFlagOn then continue;
        end;
        if not QueryRegKey(ClassIDKey, ClassID + '\Control', S) and
           QueryRegKey(ClassIDKey, ClassID + '\ProgID', S) and
           QueryRegKey(ClassIDKey, ClassID + '\TypeLib', S) and
           QueryRegKey(ClassIDKey, ClassID + '\Version', S) and
           QueryRegKey(ClassIDKey, ClassID + '\Borland DataBroker', S) then
          List.Add(ClassIDToProgID(StringToGUID(ClassID)));
        Inc(I);
      end;
    finally
      CloseRegKey(ClassIDKey);
    end;
end;

{ TDataBlock }

constructor TDataBlock.Create;
begin
  inherited Create;
  FIgnoreStream := False;
  FStream := TMemoryStream.Create;
  Clear;
end;

destructor TDataBlock.Destroy;
begin
  if not FIgnoreStream then
    FStream.Free;
  inherited Destroy;
end;

{ TDataBlock.IDataBlock }

function TDataBlock.GetBytesReserved: Integer;
begin
  Result := SizeOf(Integer) * 2;
end;

function TDataBlock.GetMemory: Pointer;
var
  DataSize: Integer;
begin
  FStream.Position := 4;
  DataSize := FStream.Size - BytesReserved;
  FStream.Write(DataSize, SizeOf(DataSize));
  Result := FStream.Memory;
end;

function TDataBlock.GetSize: Integer;
begin
  Result := FStream.Size - BytesReserved;
end;

procedure TDataBlock.SetSize(Value: Integer);
begin
  FStream.Size := Value + BytesReserved;
end;

function TDataBlock.GetStream: TStream;
var
  DataSize: Integer;
begin
  FStream.Position := 4;
  DataSize := FStream.Size - BytesReserved;
  FStream.Write(DataSize, SizeOf(DataSize));
  FStream.Position := 0;
  Result := FStream;
end;

function TDataBlock.GetSignature: Integer;
begin
  FStream.Position := 0;
  FStream.Read(Result, SizeOf(Result));
end;

procedure TDataBlock.SetSignature(Value: Integer);
begin
  FStream.Position := 0;
  FStream.Write(Value, SizeOf(Value));
end;

procedure TDataBlock.Clear;
begin
  FStream.Size := BytesReserved;
  FReadPos := BytesReserved;
  FWritePos := BytesReserved;
end;

function TDataBlock.Write(const Buffer; Count: Integer): Integer;
begin
  FStream.Position := FWritePos;
  Result := FStream.Write(Buffer, Count);
  FWritePos := FStream.Position;
end;

function TDataBlock.Read(var Buffer; Count: Integer): Integer;
begin
  FStream.Position := FReadPos;
  Result := FStream.Read(Buffer, Count);
  FReadPos := FStream.Position;
end;

procedure TDataBlock.IgnoreStream;
begin
  FIgnoreStream := True;
end;

function TDataBlock.InitData(Data: Pointer; DataLen: Integer; CheckLen: Boolean): Integer; stdcall;
var
  Sig: Integer;
  P: Pointer;
begin
  P := Data;
  if DataLen < MINDATAPACKETSIZE then
    raise Exception.CreateRes(@SInvalidDataPacket);
  Sig := Integer(P^);
  P := Pointer(Integer(Data) + SizeOf(Sig));
  CheckSignature(Sig);
  Signature := Sig;
  Result := Integer(P^);
  P := Pointer(Integer(P) + SizeOf(Result));
  if CheckLen then
  begin
    if (Result <> DataLen - MINDATAPACKETSIZE) then
      raise Exception.CreateRes(@SInvalidDataPacket);
    Size := Result;
    if Result > 0 then
      Write(P^, Result);
  end else
  begin
    Size := DataLen - MINDATAPACKETSIZE;
    if Size > 0 then
      Write(P^, Size);
  end;
end;

{ TDataBlockInterpreter }

const

  EasyArrayTypes = [varSmallInt, varInteger, varSingle, varDouble, varCurrency,
                    varDate, varBoolean, varShortInt, varByte, varWord, varLongWord];

  VariantSize: array[0..varLongWord] of Word  = (0, 0, SizeOf(SmallInt), SizeOf(Integer),
    SizeOf(Single), SizeOf(Double), SizeOf(Currency), SizeOf(TDateTime), 0, 0,
    SizeOf(Integer), SizeOf(WordBool), 0, 0, 0, 0, SizeOf(ShortInt), SizeOf(Byte),
    SizeOf(Word), SizeOf(LongWord));

constructor TDataBlockInterpreter.Create(SendDataBlock: ISendDataBlock; CheckRegValue: string);
begin
  inherited Create;
  FSendDataBlock := SendDataBlock;
  FDispatchList := TList.Create;
  FCheckRegValue := CheckRegValue;
end;

destructor TDataBlockInterpreter.Destroy;
var
  i: Integer;
begin
  for i := FDispatchList.Count - 1 downto 0 do
    TDataDispatch(FDispatchList[i]).FInterpreter := nil;
  FDispatchList.Free;
  FSendDataBlock := nil;
  inherited Destroy;
end;

procedure TDataBlockInterpreter.AddDispatch(Value: TDataDispatch);
begin
  if FDispatchList.IndexOf(Value) = -1 then
    FDispatchList.Add(Value);
end;

procedure TDataBlockInterpreter.RemoveDispatch(Value: TDataDispatch);
begin
  FDispatchList.Remove(Value);
end;

{ Variant conversion methods }

function TDataBlockInterpreter.GetVariantPointer(const Value: OleVariant): Pointer;
begin
  case VarType(Value) of
    varEmpty, varNull: Result := nil;
    varDispatch: Result := TVarData(Value).VDispatch;
    varVariant: Result := @Value;
    varUnknown: Result := TVarData(Value).VUnknown;
  else
    Result := @TVarData(Value).VPointer;
  end;
end;

procedure TDataBlockInterpreter.CopyDataByRef(const Source: TVarData; var Dest: TVarData);
var
  VType: Integer;
begin
  VType := Source.VType;
  if Source.VType and varArray = varArray then
  begin
    VarClear(OleVariant(Dest));
    SafeArrayCopy(PSafeArray(Source.VArray), PSafeArray(Dest.VArray));
  end else
    case Source.VType and varTypeMask of
      varEmpty, varNull: ;
      varOleStr:
      begin
        if (Dest.VType and varTypeMask) <> varOleStr then
          Dest.VOleStr := SysAllocString(Source.VOleStr)
        else if (Dest.VType and varByRef) = varByRef then
          SysReallocString(PBStr(Dest.VOleStr)^,Source.VOleStr)
        else
          SysReallocString(Dest.VOleStr,Source.VOleStr);
      end;
      varDispatch: Dest.VDispatch := Source.VDispatch;
      varVariant: CopyDataByRef(PVarData(Source.VPointer)^, Dest);
      varUnknown: Dest.VUnknown := Source.VUnknown;
    else
      if Dest.VType = 0 then
        OleVariant(Dest) := OleVariant(Source)
      else if Dest.VType and varByRef = varByRef then
      begin
        VType := VType or varByRef;
        Move(Source.VPointer, Dest.VPointer^, VariantSize[Source.VType and varTypeMask]);
      end
      else
        Move(Source.VPointer, Dest.VPointer, VariantSize[Source.VType and varTypeMask]);
    end;
  Dest.VType := VType;
end;

function TDataBlockInterpreter.ReadArray(VType: Integer;
  const Data: IDataBlock): OleVariant;
var
  Flags: TVarFlags;
  LoDim, HiDim, Indices, Bounds: PIntArray;
  DimCount, VSize, i: Integer;
  {P: Pointer;}
  V: OleVariant;
  LSafeArray: PSafeArray;
  P: Pointer;
begin
  VarClear(Result);
  Data.Read(DimCount, SizeOf(DimCount));
  VSize := DimCount * SizeOf(Integer);
  GetMem(LoDim, VSize);
  try
    GetMem(HiDim, VSize);
    try
      Data.Read(LoDim^, VSize);
      Data.Read(HiDim^, VSize);
      GetMem(Bounds, VSize * 2);
      try
        for i := 0 to DimCount - 1 do
        begin
          Bounds[i * 2] := LoDim[i];
          Bounds[i * 2 + 1] := HiDim[i];
        end;
        Result := VarArrayCreate(Slice(Bounds^,DimCount * 2), VType and varTypeMask);
      finally
        FreeMem(Bounds);
      end;
      if VType and varTypeMask in EasyArrayTypes then
      begin
        Data.Read(VSize, SizeOf(VSize));
        P := VarArrayLock(Result);
        try
          Data.Read(P^, VSize);
        finally
          VarArrayUnlock(Result);
        end;
      end else
      begin
        LSafeArray := PSafeArray(TVarData(Result).VArray);
        GetMem(Indices, VSize);
        try
          FillChar(Indices^, VSize, 0);
          for I := 0 to DimCount - 1 do
            Indices[I] := LoDim[I];
          while True do
          begin
            V := ReadVariant(Flags, Data);
            if VType and varTypeMask = varVariant then
              OleCheck(SafeArrayPutElement(LSafeArray, Indices^, V)) else
              OleCheck(SafeArrayPutElement(LSafeArray, Indices^, TVarData(V).VPointer^));
            Inc(Indices[DimCount - 1]);
            if Indices[DimCount - 1] > HiDim[DimCount - 1] then
              for i := DimCount - 1 downto 0 do
                if Indices[i] > HiDim[i] then
                begin
                  if i = 0 then Exit;
                  Inc(Indices[i - 1]);
                  Indices[i] := LoDim[i];
                end;
          end;
        finally
          FreeMem(Indices);
        end;
      end;
    finally
      FreeMem(HiDim);
    end;
  finally
    FreeMem(LoDim);
  end;
end;

procedure TDataBlockInterpreter.WriteArray(const Value: OleVariant;
  const Data: IDataBlock);
var
  LVarData: TVarData;
  VType: Integer;
  VSize, i, DimCount, ElemSize: Integer;
  LSafeArray: PSafeArray;
  LoDim, HiDim, Indices: PIntArray;
  V: OleVariant;
  P: Pointer;
begin
  LVarData := FindVarData(Value)^;
  VType := LVarData.VType;
  LSafeArray := PSafeArray(LVarData.VPointer);
                         
  Data.Write(VType, SizeOf(Integer));
  DimCount := VarArrayDimCount(Value);
  Data.Write(DimCount, SizeOf(DimCount));
  VSize := SizeOf(Integer) * DimCount;
  GetMem(LoDim, VSize);
  try
    GetMem(HiDim, VSize);
    try
      for i := 1 to DimCount do
      begin
        LoDim[i - 1] := VarArrayLowBound(Value, i);
        HiDim[i - 1] := VarArrayHighBound(Value, i);
      end;
      Data.Write(LoDim^,VSize);
      Data.Write(HiDim^,VSize);
      if VType and varTypeMask in EasyArrayTypes then
      begin
        ElemSize := SafeArrayGetElemSize(LSafeArray);
        VSize := 1;
        for i := 0 to DimCount - 1 do
          VSize := (HiDim[i] - LoDim[i] + 1) * VSize;
        VSize := VSize * ElemSize;
        P := VarArrayLock(Value);
        try
          Data.Write(VSize, SizeOf(VSize));
          Data.Write(P^,VSize);
        finally
          VarArrayUnlock(Value);
        end;
      end else
      begin
        GetMem(Indices, VSize);
        try
          for I := 0 to DimCount - 1 do
            Indices[I] := LoDim[I];
          while True do
          begin
            if VType and varTypeMask <> varVariant then
            begin
              OleCheck(SafeArrayGetElement(LSafeArray, Indices^, TVarData(V).VPointer));
              TVarData(V).VType := VType and varTypeMask;
            end else
              OleCheck(SafeArrayGetElement(LSafeArray, Indices^, V));
            WriteVariant(V, Data);
            Inc(Indices[DimCount - 1]);
            if Indices[DimCount - 1] > HiDim[DimCount - 1] then
              for i := DimCount - 1 downto 0 do
                if Indices[i] > HiDim[i] then
                begin
                  if i = 0 then Exit;
                  Inc(Indices[i - 1]);
                  Indices[i] := LoDim[i];
                end;
          end;
        finally
          FreeMem(Indices);
        end;
      end;
    finally
      FreeMem(HiDim);
    end;
  finally
    FreeMem(LoDim);
  end;
end;

function TDataBlockInterpreter.ReadVariant(out Flags: TVarFlags;
  const Data: IDataBlock): OleVariant;
var
  I, VType: Integer;
  W: WideString;
  TmpFlags: TVarFlags;
begin
  VarClear(Result);
  Flags := [];
  Data.Read(VType, SizeOf(VType));
  if VType and varByRef = varByRef then
    Include(Flags, vfByRef);
  if VType = varByRef then
  begin
    Include(Flags, vfVariant);
    Result := ReadVariant(TmpFlags, Data);
    Exit;
  end;
  if vfByRef in Flags then
    VType := VType xor varByRef;
  if (VType and varArray) = varArray then
    Result := ReadArray(VType, Data) else
  case VType and varTypeMask of
    varEmpty: VarClear(Result);
    varNull: Result := NULL;
    varOleStr:
    begin
      Data.Read(I, SizeOf(Integer));
      SetLength(W, I);
      Data.Read(W[1], I * 2);
      Result := W;
    end;
    varDispatch:
    begin
      Data.Read(I, SizeOf(Integer));
      Result := TDataDispatch.Create(Self, I) as IDispatch;
    end;
    varUnknown:
      raise EInterpreterError.CreateResFmt(@SBadVariantType,[IntToHex(VType,4)]);
  else
    TVarData(Result).VType := VType;
    Data.Read(TVarData(Result).VPointer, VariantSize[VType and varTypeMask]);
  end;
end;

function TDataBlockInterpreter.CanCreateObject(const ClassID: TGUID): Boolean;
begin
  Result := (FCheckRegValue = '') or
    (GetRegStringValue(SClsid + GuidToString(ClassID), FCheckRegValue) = SFlagOn);
end;

function TDataBlockInterpreter.InternalCreateObject(const ClassID: TGUID): OleVariant;
var
  Unk: IUnknown;
begin
  OleCheck(CoCreateInstance(ClassID, nil, CLSCTX_INPROC_SERVER or
    CLSCTX_LOCAL_SERVER or CLSCTX_REMOTE_SERVER, IUnknown, Unk));
  Result := Unk as IDispatch;
end;

function TDataBlockInterpreter.CreateObject(const Name: string): OleVariant;
var
  ClassID: TGUID;
begin
  if (Name[1] = '{') and (Name[Length(Name)] = '}') then
    ClassID := StringToGUID(Name) else
    ClassID := ProgIDToClassID(Name);
  if CanCreateObject(ClassID) then
    Result := InternalCreateObject(ClassID) else
    raise Exception.CreateResFmt(@SObjectNotAvailable, [GuidToString(ClassID)]);
end;

function TDataBlockInterpreter.StoreObject(const Value: OleVariant): Integer;
begin
  if not VarIsArray(FDispList) then
    FDispList := VarArrayCreate([0,10], varVariant);
  Result := 0;
  while Result <= VarArrayHighBound(FDispList, 1) do
    if VarIsClear(FDispList[Result]) then break else Inc(Result);
  if Result > VarArrayHighBound(FDispList, 1) then
    VarArrayRedim(FDispList, Result + 10);
  FDispList[Result] := Value;
end;

function TDataBlockInterpreter.LockObject(ID: Integer): IDispatch;
begin
  Result := FDispList[ID];
end;

procedure TDataBlockInterpreter.UnlockObject(ID: Integer; const Disp: IDispatch);
begin
end;

procedure TDataBlockInterpreter.ReleaseObject(ID: Integer);
begin
  if (ID >= 0) and (VarIsArray(FDispList)) and
     (ID < VarArrayHighBound(FDispList, 1)) then
    FDispList[ID] := UNASSIGNED;
end;

procedure TDataBlockInterpreter.WriteVariant(const Value: OleVariant;
  const Data: IDataBlock);
var
  I, VType: Integer;
  W: WideString;
begin
  VType := VarType(Value);
  if VType and varArray <> 0 then
    WriteArray(Value, Data)
  else
    case (VType and varTypeMask) of
      varEmpty, varNull:
        Data.Write(VType, SizeOf(Integer));
      varOleStr:
      begin
        W := WideString(Value);
        I := Length(W);
        Data.Write(VType, SizeOf(Integer));
        Data.Write(I,SizeOf(Integer));
        Data.Write(W[1], I * 2);
      end;
      varDispatch:
      begin
        if VType and varByRef = varByRef then
          raise EInterpreterError.CreateResFmt(@SBadVariantType,[IntToHex(VType,4)]);
        I := StoreObject(Value);
        Data.Write(VType, SizeOf(Integer));
        Data.Write(I, SizeOf(Integer));
      end;
      varVariant:
      begin
        if VType and varByRef <> varByRef then
          raise EInterpreterError.CreateResFmt(@SBadVariantType,[IntToHex(VType,4)]);
        I := varByRef;
        Data.Write(I, SizeOf(Integer));
        WriteVariant(Variant(TVarData(Value).VPointer^), Data);
      end;
      varUnknown:
        raise EInterpreterError.CreateResFmt(@SBadVariantType,[IntToHex(VType,4)]);
    else
      Data.Write(VType, SizeOf(Integer));
      if VType and varByRef = varByRef then
        Data.Write(TVarData(Value).VPointer^, VariantSize[VType and varTypeMask])
      else
        Data.Write(TVarData(Value).VPointer, VariantSize[VType and varTypeMask]);
    end;
end;

{ Sending Calls }

function TDataBlockInterpreter.CallGetServerList: OleVariant;
var
  Flags: TVarFlags;
  Data: IDataBlock;
begin
  Data := TDataBlock.Create as IDataBlock;
  Data.Signature := CallSig or asGetAppServers;
  Data := FSendDataBlock.Send(Data, True);
  Result := ReadVariant(Flags, Data);
end;

function TDataBlockInterpreter.CallCreateObject(Name: string): OleVariant;
var
  Flags: TVarFlags;
  Data: IDataBlock;
begin
  Data := TDataBlock.Create as IDataBlock;
  WriteVariant(Name, Data);
  Data.Signature := CallSig or asCreateObject;
  Data := FSendDataBlock.Send(Data, True);
  Result := ReadVariant(Flags, Data);
end;

procedure TDataBlockInterpreter.CallFreeObject(DispatchIndex: Integer);
var
  Data: IDataBlock;
begin
  Data := TDataBlock.Create as IDataBlock;
  WriteVariant(DispatchIndex, Data);
  Data.Signature := CallSig or asFreeObject;
  FSendDataBlock.Send(Data, False);
end;

function TDataBlockInterpreter.CallGetIDsOfNames(DispatchIndex: Integer;
  const IID: TGUID; Names: Pointer; NameCount, LocaleID: Integer;
  DispIDs: Pointer): HResult; stdcall;
var
  Flags: TVarFlags;
  Data: IDataBlock;
begin
  if NameCount <> 1 then
    Result := E_NOTIMPL else
  begin
    Data := TDataBlock.Create as IDataBlock;
    WriteVariant(DispatchIndex, Data);
    WriteVariant(WideString(POleStrList(Names)^[0]), Data);
    Data.Signature := CallSig or asGetID;
    Data := FSendDataBlock.Send(Data, True);
    Result := ReadVariant(Flags, Data);
    if Result = S_OK then
      PDispIdList(DispIDs)^[0] := ReadVariant(Flags, Data);
  end;
end;

function TDataBlockInterpreter.CallInvoke(DispatchIndex, DispID: Integer; const IID: TGUID; LocaleID: Integer;
  Flags: Word; var Params; VarResult, ExcepInfo, ArgErr: Pointer): HResult; stdcall;
var
  VarFlags: TVarFlags;
  PDest: PVarData;
  i: Integer;
  Data: IDataBlock;
begin
  Data := TDataBlock.Create as IDataBlock;
  WriteVariant(DispatchIndex, Data);
  WriteVariant(DispID, Data);
  WriteVariant(Flags, Data);
  WriteVariant(VarResult <> nil, Data);
  WriteVariant(PDispParams(@Params).cArgs, Data);
  WriteVariant(PDispParams(@Params).cNamedArgs, Data);
  for i := 0 to PDispParams(@Params).cNamedArgs - 1 do
    WriteVariant(PDispParams(@Params).rgdispidNamedArgs[i], Data);
  for i := 0 to PDispParams(@Params).cArgs - 1 do
    WriteVariant(OleVariant(PDispParams(@Params).rgvarg^[i]), Data);
  Data.Signature := CallSig or asInvoke;
  Data := FSendDataBlock.Send(Data, True);
  Result := ReadVariant(VarFlags, Data);
  if (Result = DISP_E_EXCEPTION) then
  begin
    PExcepInfo(ExcepInfo).scode := ReadVariant(VarFlags, Data);
    PExcepInfo(ExcepInfo).bstrDescription := ReadVariant(VarFlags, Data);
  end;
  for i := 0 to PDispParams(@Params).cArgs - 1 do
    with PDispParams(@Params)^ do
      if rgvarg^[i].vt and varByRef = varByRef then
      begin
        if rgvarg^[i].vt = (varByRef or varVariant) then
          PDest := @TVarData(TVarData(rgvarg^[i]).VPointer^)
        else
          PDest := @TVarData(rgvarg^[i]);
        CopyDataByRef(TVarData(ReadVariant(VarFlags, Data)), PDest^);
      end;
  if VarResult <> nil then
    PVariant(VarResult)^ := ReadVariant(VarFlags, Data);
end;

{ Receiving Calls }

procedure TDataBlockInterpreter.InterpretData(const Data: IDataBlock);
var
  Action: Integer;
begin
  Action := Data.Signature;
  if (Action and asMask) = asError then DoException(Data);
  try
    case (Action and asMask) of
      asInvoke: DoInvoke(Data);
      asGetID: DoGetIDsOfNames(Data);
      asCreateObject: DoCreateObject(Data);
      asFreeObject: DoFreeObject(Data);
      asGetServers: DoGetServerList(Data);
      asGetAppServers: DoGetAppServerList(Data);
    else
      if not DoCustomAction(Action and asMask, Data) then
        raise EInterpreterError.CreateResFmt(@SInvalidAction, [Action and asMask]);
    end;
  except
    on E: Exception do
    begin
      Data.Clear;
      WriteVariant(E.Message, Data);
      Data.Signature := ResultSig or asError;
      FSendDataBlock.Send(Data, False);
    end;
  end;
end;

procedure TDataBlockInterpreter.DoException(const Data: IDataBlock);
var
  VarFlags: TVarFlags;
begin
  raise Exception.Create(ReadVariant(VarFlags, Data));
end;

procedure TDataBlockInterpreter.DoGetAppServerList(const Data: IDataBlock);
var
  VList: OleVariant;
  List: TStringList;
  i: Integer;
begin
  Data.Clear;
  List := TStringList.Create;
  try
    GetMIDASAppServerList(List, FCheckRegValue);
    if List.Count > 0 then
    begin
      VList := VarArrayCreate([0, List.Count - 1], varOleStr);
      for i := 0 to List.Count - 1 do
        VList[i] := List[i];
    end else
      VList := NULL;
  finally
    List.Free;
  end;
  WriteVariant(VList, Data);
  Data.Signature := ResultSig or asGetAppServers;
  FSendDataBlock.Send(Data, False);
end;

procedure TDataBlockInterpreter.DoGetServerList(const Data: IDataBlock);
var
  VList: OleVariant;
  List: TStringList;
  i: Integer;
begin
  Data.Clear;
  List := TStringList.Create;
  try
    GetDataBrokerList(List, FCheckRegValue);
    if List.Count > 0 then
    begin
      VList := VarArrayCreate([0, List.Count - 1], varOleStr);
      for i := 0 to List.Count - 1 do
        VList[i] := List[i];
    end else
      VList := NULL;
  finally
    List.Free;
  end;
  WriteVariant(VList, Data);
  Data.Signature := ResultSig or asGetServers;
  FSendDataBlock.Send(Data, False);
end;

procedure TDataBlockInterpreter.DoCreateObject(const Data: IDataBlock);
var
  V: OleVariant;
  VarFlags: TVarFlags;
  I: Integer;
begin
  V := CreateObject(ReadVariant(VarFlags, Data));
  Data.Clear;
  I := TVarData(V).VType;
  if (I and varTypeMask) = varInteger then
  begin
    I := varDispatch;
    Data.Write(I, SizeOf(Integer));
    I := V;
    Data.Write(I, SizeOf(Integer));
  end else
    WriteVariant(V, Data);
  Data.Signature := ResultSig or asCreateObject;
  FSendDataBlock.Send(Data, False);
end;

procedure TDataBlockInterpreter.DoFreeObject(const Data: IDataBlock);
var
  VarFlags: TVarFlags;
begin
  try
    ReleaseObject(ReadVariant(VarFlags, Data));
  except
    { Don't return any exceptions }
  end;
end;

procedure TDataBlockInterpreter.DoGetIDsOfNames(const Data: IDataBlock);
var
  ObjID, RetVal, DispID: Integer;
  Disp: IDispatch;
  W: WideString;
  VarFlags: TVarFlags;
begin
  ObjID := ReadVariant(VarFlags, Data);
  Disp := LockObject(ObjID);
  try
    W := ReadVariant(VarFlags, Data);
    Data.Clear;
    RetVal := Disp.GetIDsOfNames(GUID_NULL, @W, 1, 0, @DispID);
  finally
    UnlockObject(ObjID, Disp);
  end;
  WriteVariant(RetVal, Data);
  if RetVal = S_OK then
    WriteVariant(DispID, Data);
  Data.Signature := ResultSig or asGetID;
  FSendDataBlock.Send(Data, False);
end;

procedure TDataBlockInterpreter.DoInvoke(const Data: IDataBlock);
var
  ExcepInfo: TExcepInfo;
  DispParams: TDispParams;
  ObjID, DispID, Flags, i: Integer;
  RetVal: HRESULT;
  ExpectResult: Boolean;
  VarFlags: TVarFlags;
  Disp: IDispatch;
  VarList: PVariantArray;
  V: OleVariant;
begin
  VarList := nil;
  FillChar(ExcepInfo, SizeOf(ExcepInfo), 0);
  FillChar(DispParams, SizeOf(DispParams), 0);
  ObjID := ReadVariant(VarFlags, Data);
  Disp := LockObject(ObjID);
  try
    DispID := ReadVariant(VarFlags, Data);
    Flags := ReadVariant(VarFlags, Data);
    ExpectResult := ReadVariant(VarFlags, Data);
    DispParams.cArgs := ReadVariant(VarFlags, Data);
    DispParams.cNamedArgs := ReadVariant(VarFlags, Data);
    try
      DispParams.rgdispidNamedArgs := nil;
      if DispParams.cNamedArgs > 0 then
      begin
        GetMem(DispParams.rgdispidNamedArgs, DispParams.cNamedArgs * SizeOf(Integer));
        for i := 0 to DispParams.cNamedArgs - 1 do
          DispParams.rgdispidNamedArgs[i] := ReadVariant(VarFlags, Data);
      end;
      if DispParams.cArgs > 0 then
      begin
        GetMem(DispParams.rgvarg, DispParams.cArgs * SizeOf(TVariantArg));
        GetMem(VarList, DispParams.cArgs * SizeOf(OleVariant));
        Initialize(VarList^, DispParams.cArgs);
        for i := 0 to DispParams.cArgs - 1 do
        begin
          VarList[i] := ReadVariant(VarFlags, Data);
          if vfByRef in VarFlags then
          begin
            if vfVariant in VarFlags then
            begin
              DispParams.rgvarg[i].vt := varVariant or varByRef;
              TVarData(DispParams.rgvarg[i]).VPointer := @VarList[i];
            end else
            begin
              DispParams.rgvarg[i].vt := VarType(VarList[i]) or varByRef;
              TVarData(DispParams.rgvarg[i]).VPointer := GetVariantPointer(VarList[i]);
            end;
          end else
            DispParams.rgvarg[i] := TVariantArg(VarList[i]);
        end;
      end;
      Data.Clear;
      RetVal := Disp.Invoke(DispID, GUID_NULL, 0, Flags, DispParams, @V, @ExcepInfo, nil);
      WriteVariant(RetVal, Data);
      if RetVal = DISP_E_EXCEPTION then
      begin
        WriteVariant(ExcepInfo.scode, Data);
        WriteVariant(ExcepInfo.bstrDescription, Data);
      end;
      if DispParams.rgvarg <> nil then
      begin
        for i := 0 to DispParams.cArgs - 1 do
          if DispParams.rgvarg[i].vt and varByRef = varByRef then
            WriteVariant(OleVariant(DispParams.rgvarg[i]), Data);
      end;
      if ExpectResult then WriteVariant(V, Data);
      Data.Signature := ResultSig or asInvoke;
      FSendDataBlock.Send(Data, False);
    finally
      if DispParams.rgdispidNamedArgs <> nil then
        FreeMem(DispParams.rgdispidNamedArgs);
      if VarList <> nil then
      begin
        Finalize(VarList^, DispParams.cArgs);
        FreeMem(VarList);
      end;
      if DispParams.rgvarg <> nil then
        FreeMem(DispParams.rgvarg);
    end;
  finally
    UnlockObject(ObjID, Disp);
  end;
end;

function TDataBlockInterpreter.DoCustomAction(Action: Integer;
  const Data: IDataBlock): Boolean;
begin
  Result := False;
end;

{ TDataDispatch }

constructor TDataDispatch.Create(Interpreter: TCustomDataBlockInterpreter; DispatchIndex: Integer);
begin
  inherited Create;
  FDispatchIndex := DispatchIndex;
  FInterpreter := Interpreter;
  Interpreter.AddDispatch(Self);
end;

destructor TDataDispatch.Destroy;
begin
  if Assigned(FInterpreter) then
  begin
    FInterpreter.CallFreeObject(FDispatchIndex);
    FInterpreter.RemoveDispatch(Self);
  end;
  inherited Destroy;
end;

{ TDataDispatch.IDispatch }

function TDataDispatch.GetTypeInfoCount(out Count: Integer): HResult; stdcall;
begin
  Count := 0;
  Result := S_OK;
end;

function TDataDispatch.GetTypeInfo(Index, LocaleID: Integer; out TypeInfo): HResult; stdcall;
begin
  Result := E_NOTIMPL;
end;

function TDataDispatch.GetIDsOfNames(const IID: TGUID; Names: Pointer;
  NameCount, LocaleID: Integer; DispIDs: Pointer): HResult; stdcall;
begin
  Result := FInterpreter.CallGetIDsOfNames(FDispatchIndex, IID, Names, NameCount,
    LocaleID, DispIDs);
end;

function TDataDispatch.Invoke(DispID: Integer; const IID: TGUID; LocaleID: Integer;
  Flags: Word; var Params; VarResult, ExcepInfo, ArgErr: Pointer): HResult; stdcall;
begin
  Result := FInterpreter.CallInvoke(FDispatchIndex, DispID, IID, LocaleID, Flags,
    Params, VarResult, ExcepInfo, ArgErr);
end;


{ TTransportThread }

constructor TTransportThread.Create(AHandle: THandle; Transport: ITransport);
begin
  FParentHandle := AHandle;
  FTransport := Transport;
  FreeOnTerminate := True;
  FSemaphore := CreateSemaphore(nil, 0, 1, nil);
  inherited Create(False);
end;

destructor TTransportThread.Destroy;
begin
  CloseHandle(FSemaphore);
  inherited Destroy;
end;

procedure TTransportThread.Execute;

  procedure SynchronizeException;
  var
    SendException: TObject;
  begin
    SendException := AcquireExceptionObject;
    if Assigned(FTransport) and (SendException is ESocketConnectionError) then
      FTransport.Connected := False;
    PostMessage(FParentHandle, THREAD_EXCEPTION, 0, Integer(Pointer(SendException)));
  end;

var
  msg: TMsg;
  Data: IDataBlock;
  Event: THandle;
  Context: Integer;
begin
  CoInitialize(nil);
  try
    PeekMessage(msg, 0, WM_USER, WM_USER, PM_NOREMOVE);
    ReleaseSemaphore(FSemaphore, 1, nil);
    try
      FTransport.Connected := True;
      try
        Event := FTransport.GetWaitEvent;
        while not Terminated and FTransport.Connected do
        try
          case MsgWaitForMultipleObjects(1, Event, False, INFINITE, QS_ALLINPUT) of
            WAIT_OBJECT_0:
            begin
              WSAResetEvent(Event);
              Data := FTransport.Receive(False, 0);
              if Assigned(Data) then
              begin
                Data._AddRef;
                PostMessage(FParentHandle, THREAD_RECEIVEDSTREAM, 0, Integer(Pointer(Data)));
                Data := nil;
              end;
            end;
            WAIT_OBJECT_0 + 1:
            begin
              while PeekMessage(msg, 0, 0, 0, PM_REMOVE) do
              begin
                if (msg.hwnd = 0) then
                  case msg.message of
                    THREAD_SENDSTREAM:
                    begin
                      Data := IDataBlock(msg.lParam);
                      Data._Release;
                      Context := FTransport.Send(Data);
                      if msg.wParam = 1 then
                      begin
                        Data := FTransport.Receive(True, Context);
                        Data._AddRef;
                        PostMessage(FParentHandle, THREAD_RECEIVEDSTREAM, 0, Integer(Pointer(Data)));
                        Data := nil;
                      end else
                        PostMessage(FParentHandle, THREAD_SENDNOTIFY, 0, 0);
                    end;
                    THREAD_REPLACETRANSPORT:
                    begin
                      FTransport := ITransport(msg.lParam);
                      FTransport._Release;
                    end;
                  else
                    DispatchMessage(msg);
                  end
                else
                  DispatchMessage(msg);
              end;
            end;
          end;
        except
          SynchronizeException;
        end;
      finally
        Data := nil;
        FTransport.Connected := False;
      end;
    except
      SynchronizeException;
    end;
  finally
    FTransport := nil;
    CoUninitialize();
  end;
end;

{ TStreamedConnection }

constructor TStreamedConnection.Create(AOwner: TComponent);
var
  Obj: ISendDataBlock;
begin
  inherited Create(AOwner);
  GetInterface(ISendDataBlock, Obj);
//  FInterpreter := TDataBlockInterpreter.Create(Self, SSockets);
  FSupportCallbacks := True;
end;

destructor TStreamedConnection.Destroy;
begin
  SetConnected(False);
  FInterpreter.Free;
  if FHandle <> 0 then DeallocateHWnd(FHandle);
  if Assigned(FTransport) then FTransport.OnTerminate := nil;
  FTransIntf := nil;
  inherited Destroy;
end;

function TStreamedConnection.GetInterceptGUID: string;
begin
  if (FInterceptGUID.D1 <> 0) or (FInterceptGUID.D2 <> 0) or (FInterceptGUID.D3 <> 0) then
    Result := GUIDToString(FInterceptGUID) else
    Result := '';
end;

procedure TStreamedConnection.SetInterceptGUID(const Value: string);
var
  InterceptName: PWideChar;
begin
  if not (csLoading in ComponentState) then
    SetConnected(False);
  if Value = '' then
    FillChar(FInterceptGUID, SizeOf(FInterceptGUID), 0)
  else
  begin
    FInterceptGUID := StringToGUID(Value);
    if ProgIDFromCLSID(FInterceptGUID, InterceptName) = 0 then
    begin
      FInterceptName := InterceptName;
      CoTaskMemFree(InterceptName);
    end;
  end;
end;

procedure TStreamedConnection.SetInterceptName(const Value: string);
begin
  if Value <> FInterceptName then
  begin
    if not (csLoading in ComponentState) then
    begin
      SetConnected(False);
      if CLSIDFromProgID(PWideChar(WideString(Value)), FInterceptGUID) <> 0 then
        FillChar(FInterceptGUID, SizeOf(FInterceptGUID), 0);
    end;
    FInterceptName := Value;
  end;
end;

procedure TStreamedConnection.SetSupportCallbacks(Value: Boolean);
begin
  if Connected then Connected := False;
  FSupportCallbacks := Value;
end;

procedure TStreamedConnection.InternalOpen;
begin
  if FSupportCallbacks then
  begin
    FTransport := TTransportThread.Create(Handle, CreateTransport);
    FTransport.OnTerminate := TransportTerminated;
    WaitForSingleObject(FTransport.Semaphore, INFINITE);
  end else
  begin
    FTransIntf := CreateTransport;
    FTransIntf.SetConnected(True);
  end;
end;

procedure TStreamedConnection.InternalClose;
begin
  if Assigned(FTransport) then
  begin
    FTransport.OnTerminate := nil;
    FTransport.Terminate;
    PostThreadMessage(FTransport.ThreadID, WM_USER, 0, 0);
    if Assigned(FTransport.FTransport) then
      WaitForSingleObject(FTransport.Handle, 180000);
    FTransport := nil;
  end else
  if Assigned(FTransIntf) then
  begin
    FTransIntf.Connected := False;
    FTransIntf := nil;
  end;
end;

function TStreamedConnection.GetServerList: OleVariant;
var
  DidConnect: Boolean;
begin
  DidConnect := not Connected;
  if DidConnect then InternalOpen;
  try
    Result := Interpreter.CallGetServerList;
  finally
    if DidConnect then InternalClose;
  end;
end;

function TStreamedConnection.GetInterceptorList: OleVariant;
var
  List: TStringList;
  i: Integer;
begin
  Result := NULL;
  List := TStringList.Create;
  try
    GetPacketInterceptorList(List);
    if List.Count > 0 then
    begin
      Result := VarArrayCreate([0, List.Count - 1], varOleStr);
      for i := 0 to List.Count - 1 do
        Result[i] := List[i];
    end;
  finally
    List.Free;
  end;
end;

function TStreamedConnection.GetHandle: THandle;
begin
  if FHandle = 0 then
    FHandle := AllocateHwnd(WndProc);
  Result := FHandle;
end;

procedure TStreamedConnection.WndProc(var Message: TMessage);
begin
  try
    Dispatch(Message);
  except
    if Assigned(ApplicationHandleException) then
      ApplicationHandleException(Self);
  end;
end;

procedure TStreamedConnection.ThreadReceivedStream(var Message: TMessage);
var
  Data: IDataBlock;
begin
  Data := IDataBlock(Message.lParam);
  Data._Release;
  Interpreter.InterpretData(Data);
end;

procedure TStreamedConnection.ThreadException(var Message: TMessage);
begin
  DoError(Exception(Message.lParam));
end;

procedure TStreamedConnection.DoError(E: Exception);
begin
  raise E;
end;

procedure TStreamedConnection.TransportTerminated(Sender: TObject);
begin
  FTransport := nil;
  SetConnected(False);
end;

procedure TStreamedConnection.DoConnect;
var
  TempStr: string;
begin
  try
    if ServerGUID <> '' then
      TempStr := ServerGUID else
      TempStr := ServerName;
    if TempStr = '' then
      raise Exception.CreateResFmt(@SServerNameBlank, [Name]);
    InternalOpen;
    SetAppServer(Interpreter.CallCreateObject(TempStr));
  except
    InternalClose;
    raise;
  end;
end;

procedure TStreamedConnection.DoDisconnect;
begin
  inherited DoDisconnect;
  InternalClose;
end;

function TStreamedConnection.CreateTransport: ITransport;
begin
  Result := nil;
end;

function TStreamedConnection.GetInterpreter: TCustomDataBlockInterpreter;
begin
  if not Assigned(FInterpreter) then
    FInterpreter := TDataBlockInterpreter.Create(Self, SSockets);
  Result := FInterpreter;
end;

{ TStreamedConnection.IUnknown }

function TStreamedConnection.QueryInterface(const IID: TGUID; out Obj): HResult;
begin
  if GetInterface(IID, Obj) then Result := 0 else Result := E_NOINTERFACE;
end;

function TStreamedConnection._AddRef: Integer;
begin
  Inc(FRefCount);
  Result := FRefCount;
end;

function TStreamedConnection._Release: Integer;
begin
  Dec(FRefCount);
  Result := FRefCount;
end;

{ TStreamedConnection.ISendDataBlock }

function TStreamedConnection.Send(const Data: IDataBlock; WaitForResult: Boolean): IDataBlock;
var
  Msg: TMsg;
  Context: Integer;
begin
  if FSupportCallbacks then
  begin
    if not Assigned(FTransport) then Exit;
    Data._AddRef;
    PostThreadMessage(FTransport.ThreadID, THREAD_SENDSTREAM, Ord(WaitForResult),
      Integer(Pointer(Data)));
    if WaitForResult then
      while True do
      begin
        if GetMessage(Msg, FHandle, THREAD_RECEIVEDSTREAM, THREAD_EXCEPTION) then
        begin
          if Msg.message = THREAD_RECEIVEDSTREAM then
          begin
            Result := IDataBlock(Msg.lParam);
            Result._Release;
            if (Result.Signature and ResultSig) = ResultSig then
              break else
              Interpreter.InterpretData(Result);
          end
          else if Msg.Message <> WM_NULL then
            DoError(Exception(Msg.lParam))
          else
            raise Exception.CreateRes(@SReturnError);
        end else
          raise Exception.CreateRes(@SReturnError);
      end
    else
      GetMessage(Msg, FHandle, THREAD_SENDNOTIFY, THREAD_SENDNOTIFY);
  end else
  begin
    if not Assigned(FTransIntf) then Exit;
    Context := FTransIntf.Send(Data);
    Result := FTransIntf.Receive(WaitForResult, Context);
  end;
  if Assigned(Result) and ((Result.Signature and asMask) = asError) then
    Interpreter.InterpretData(Result);
end;

{ TSocketTransport }

constructor TSocketTransport.Create;
begin
  inherited Create;
  FInterceptor := nil;
  FEvent := 0;
end;

destructor TSocketTransport.Destroy;
begin
  FInterceptor := nil;
  SetConnected(False);
  inherited Destroy;
end;

function TSocketTransport.GetWaitEvent: THandle;
begin
  FEvent := WSACreateEvent;
  WSAEventSelect(FSocket.SocketHandle, FEvent, FD_READ or FD_CLOSE);
  Result := FEvent;
end;

function TSocketTransport.GetConnected: Boolean;
begin
  Result := (FSocket <> nil) and (FSocket.Connected);
end;

procedure TSocketTransport.SetConnected(Value: Boolean);
begin
  if GetConnected = Value then Exit;
  if Value then
  begin
    if (FAddress = '') and (FHost = '') then
      raise ESocketConnectionError.CreateRes(@SNoAddress);
    FClientSocket := TClientSocket.Create(nil);
    FClientSocket.ClientType := ctBlocking;
    FSocket := FClientSocket.Socket;
    FClientSocket.Port := FPort;
    if FAddress <> '' then
      FClientSocket.Address := FAddress else
      FClientSocket.Host := FHost;
    FClientSocket.Open;
  end else
  begin
    FSocket.Close;
    FClientSocket.Free;
    if FEvent <> 0 then WSACloseEvent(FEvent);
  end;
end;

function TSocketTransport.Receive(WaitForInput: Boolean; Context: Integer): IDataBlock;
var
  RetLen, Sig, StreamLen: Integer;
  P: Pointer;
  FDSet: TFDSet;
  TimeVal: PTimeVal;
  RetVal: Integer;
begin
  Result := nil;
  TimeVal := nil;
  FD_ZERO(FDSet);
  FD_SET(FSocket.SocketHandle, FDSet);
  if not WaitForInput then
  begin
    New(TimeVal);
    TimeVal.tv_sec := 0;
    TimeVal.tv_usec := 1;
  end;
  RetVal := select(0, @FDSet, nil, nil, TimeVal);
  if Assigned(TimeVal) then
    FreeMem(TimeVal);
  if RetVal = SOCKET_ERROR then
    raise ESocketConnectionError.Create(SysErrorMessage(WSAGetLastError));
  if (RetVal = 0) then Exit;
  RetLen := FSocket.ReceiveBuf(Sig, SizeOf(Sig));
  if RetLen <> SizeOf(Sig) then
    raise ESocketConnectionError.CreateRes(@SSocketReadError);
  CheckSignature(Sig);
  RetLen := FSocket.ReceiveBuf(StreamLen, SizeOf(StreamLen));
  if RetLen = 0 then
    raise ESocketConnectionError.CreateRes(@SSocketReadError);
  if RetLen <> SizeOf(StreamLen) then
    raise ESocketConnectionError.CreateRes(@SSocketReadError);
  Result := TDataBlock.Create as IDataBlock;
  Result.Size := StreamLen;
  Result.Signature := Sig;
  P := Result.Memory;
  Inc(Integer(P), Result.BytesReserved);
  while StreamLen > 0 do
  begin
    RetLen := FSocket.ReceiveBuf(P^, StreamLen);
    if RetLen = 0 then
      raise ESocketConnectionError.CreateRes(@SSocketReadError);
    if RetLen > 0 then
    begin
      Dec(StreamLen, RetLen);
      Inc(Integer(P), RetLen);
    end;
  end;
  if StreamLen <> 0 then
    raise ESocketConnectionError.CreateRes(@SInvalidDataPacket);
  InterceptIncoming(Result);
end;

function TSocketTransport.Send(const Data: IDataBlock): Integer;
var
  P: Pointer;
begin
  Result := 0;
  InterceptOutgoing(Data);
  P := Data.Memory;
  FSocket.SendBuf(P^, Data.Size + Data.BytesReserved);
end;

function TSocketTransport.CheckInterceptor: Boolean;
var
  GUID: TGUID;
begin
  if not Assigned(FInterceptor) and (FInterceptGUID <> '') then
    if not FCreateAttempted then
    try
      FCreateAttempted := True;
      Guid := StringToGuid(FInterceptGUID);
      FInterceptor := CreateComObject(Guid) as IDataIntercept;
    except
      { raise no exception if the creating failed }
    end;
  Result := Assigned(FInterceptor);
end;

procedure TSocketTransport.InterceptIncoming(const Data: IDataBlock);
begin
  if CheckInterceptor then
    FInterceptor.DataIn(Data);
end;

procedure TSocketTransport.InterceptOutgoing(const Data: IDataBlock);
begin
  if CheckInterceptor then
    FInterceptor.DataOut(Data);
end;

{ TSocketConnection }

constructor TSocketConnection.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FPort := 211;
end;

function TSocketConnection.IsAddressStored: Boolean;
begin
  Result := (ObjectBroker = nil) and (Address <> '');
end;

procedure TSocketConnection.SetAddress(Value: string);
begin
  if Value <> '' then
    FHost := '';
  FAddress := Value;
end;

function TSocketConnection.IsHostStored: Boolean;
begin
  Result := (ObjectBroker = nil) and (Host <> '');
end;

procedure TSocketConnection.SetHost(Value: string);
begin
  if Value <> '' then
    FAddress := '';
  FHost := Value;
end;

function TSocketConnection.CreateTransport: ITransport;
var
  SocketTransport: TSocketTransport;
begin
  if SupportCallbacks then
    if not LoadWinSock2 then raise Exception.CreateRes(@SNoWinSock2);
  if (FAddress = '') and (FHost = '') then
    raise ESocketConnectionError.CreateRes(@SNoAddress);
  SocketTransport := TSocketTransport.Create;
  SocketTransport.Host := FHost;
  SocketTransport.Address := FAddress;
  SocketTransport.Port := FPort;
  SocketTransport.InterceptGUID := InterceptGUID;
  Result := SocketTransport as ITransport;
end;

procedure TSocketConnection.DoConnect;
var
  Comp: string;
  p, i: Integer;
begin
  if (ObjectBroker <> nil) then
  begin
    repeat
      if FAddress <> '' then
        Comp := FAddress else
      if FHost <> '' then
        Comp := FHost else
      if ServerGUID <> '' then
        Comp := ObjectBroker.GetComputerForGUID(GetServerCLSID) else
        Comp := ObjectBroker.GetComputerForProgID(ServerName);
      try
        p := ObjectBroker.GetPortForComputer(Comp);
        if p > 0 then
          FPort := p;
        p := 0;
        for i := 1 to Length(Comp) do
          if (Comp[i] in ['0'..'9', '.']) then
            Inc(p, Ord(Comp[i] = '.')) else
            break;
        if p <> 3 then
          Host := Comp else
          Address := Comp;
        inherited DoConnect;
        ObjectBroker.SetConnectStatus(Comp, True);
      except
        ObjectBroker.SetConnectStatus(Comp, False);
        FAddress := '';
        FHost := '';
      end;
    until Connected;
  end else
    inherited DoConnect;
end;

{ TWebConnection }

constructor TWebConnection.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FInterpreter := TDataBlockInterpreter.Create(Self, SWeb);
  SupportCallbacks := False;
  FInetRoot := nil;
  FInetConnect := nil;
  FAgent := 'DataSnap';
  URL := SDefaultURL;
end;

destructor TWebConnection.Destroy;
begin
  SetConnected(False);
  FInterpreter.Free;
  inherited Destroy;
end;

function TWebConnection.GetInterpreter: TCustomDataBlockInterpreter;
begin
  if not Assigned(FInterpreter) then
    FInterpreter := TDataBlockInterpreter.Create(Self, SWeb);
  Result := FInterpreter;
end;
procedure TWebConnection.SetURL(const Value: string);
var
  URLComp: TURLComponents;
  P: PChar;
begin
  SetConnected(False);
  if FURL = Value then Exit;
  if Value <> '' then
  begin
    FillChar(URLComp, SizeOf(URLComp), 0);
    URLComp.dwStructSize := SizeOf(URLComp);
    URLComp.dwSchemeLength := 1;
    URLComp.dwHostNameLength := 1;
    URLComp.dwURLPathLength := 1;
    P := PChar(Value);
    InternetCrackUrl(P, 0, 0, URLComp);
    if not (URLComp.nScheme in [INTERNET_SCHEME_HTTP, INTERNET_SCHEME_HTTPS]) then
      raise Exception.CreateRes(@SInvalidURL);
    FURLScheme := URLComp.nScheme;
    FURLPort := URLComp.nPort;
    FURLHost := Copy(Value, URLComp.lpszHostName - P + 1, URLComp.dwHostNameLength);
    FURLSite := Copy(Value, URLComp.lpszUrlPath - P + 1, URLComp.dwUrlPathLength);
  end else
  begin
    FURLPort := 0;
    FURLHost := '';
    FURLSite := '';
    FURLScheme := 0;
  end;
  FURL := Value;
end;

function TWebConnection.CreateTransport: ITransport;
begin
  if FURLHost = '' then
    raise Exception.CreateRes(@SURLRequired);
  Result := Self;
end;

function TWebConnection.IsURLStored: Boolean;
begin
  Result := (ObjectBroker = nil) and (URL <> '');
end;

procedure TWebConnection.Check(Error: Boolean);
var
  ErrCode: Integer;
  S: string;
begin
  ErrCode := GetLastError;
  if Error and (ErrCode <> 0) then
  begin
    SetLength(S, 256);
    FormatMessage(FORMAT_MESSAGE_FROM_HMODULE, Pointer(GetModuleHandle('wininet.dll')),
      ErrCode, 0, PChar(S), Length(S), nil);
    SetLength(S, StrLen(PChar(S)));
    while (Length(S) > 0) and (S[Length(S)] in [#10, #13]) do
      SetLength(S, Length(S) - 1);
    raise Exception.Create(S);
  end;
end;

function TWebConnection.GetWaitEvent: THandle;
begin
  Result := 0;
end;

function TWebConnection.Transport_GetConnected: Boolean;
begin
  Result := Assigned(FinetConnect);
end;

procedure TWebConnection.Transport_SetConnected(Value: Boolean);
var
  AccessType: Integer;
begin
  if Value and not GetConnected then
  begin
    if Length(FProxy) > 0 then
      AccessType := INTERNET_OPEN_TYPE_PROXY else
      AccessType := INTERNET_OPEN_TYPE_PRECONFIG;
    FInetRoot := InternetOpen(PChar(Agent), AccessType, PChar(FProxy), PChar(FProxyByPass), 0);
    if InternetAttemptConnect(0) <> ERROR_SUCCESS then SysUtils.Abort;
    Check(not Assigned(FInetRoot));
    try
      FInetConnect := InternetConnect(FInetRoot, PChar(FURLHost), FURLPort, PChar(FUserName),
        PChar(FPassword), INTERNET_SERVICE_HTTP, 0, Cardinal(Self));
      Check(not Assigned(FInetConnect));
    except
      InternetCloseHandle(FInetRoot);
    end;
  end else
  if not Value then
  begin
    if Assigned(FInetConnect) then
      InternetCloseHandle(FInetConnect);
    FInetConnect := nil;
    if Assigned(FInetRoot) then
      InternetCloseHandle(FInetRoot);
    FInetRoot := nil;
  end;
end;

function TWebConnection.Receive(WaitForInput: Boolean; Context: Integer): IDataBlock;
const
  MaxStatusText: Integer = 4096;
var
  Size, Downloaded, Status, Len, Index, Position: DWord;
  Data: array of byte;
  S: string;
begin
  Len := SizeOf(Status);
  Index := 0;
  if HttpQueryInfo(Pointer(Context), HTTP_QUERY_STATUS_CODE or HTTP_QUERY_FLAG_NUMBER,
    @Status, Len, Index) and (Status >= 300) then
  begin
    Index := 0;
    Size := MaxStatusText;
    SetLength(S, Size);
    if HttpQueryInfo(Pointer(Context), HTTP_QUERY_STATUS_TEXT, @S[1], Size, Index) then
    begin
      SetLength(S, Size);
      raise Exception.CreateFmt('%s (%d)', [S, Status]);
    end;
  end;
  Len := 0;
  Position := 0;
  repeat
    Check(not InternetQueryDataAvailable(Pointer(Context), Size, 0, 0));
    if Size > 0 then
    begin
      SetLength(Data, Position + Size);
      Check(not InternetReadFile(Pointer(Context), @Data[Position], Size, Downloaded));
      if Assigned(Result) then
        Result.Write(Data[0], Downloaded)
      else
      begin
        Inc(Position, Downloaded);
        if (Position >= MINDATAPACKETSIZE) then
        begin
          Result := TDataBlock.Create;
          Len := Result.InitData(@Data[0], Position, False);
          Position := 0;
        end
        else
          Continue;
      end;
    end;
  until Size = 0;

  if ((Position > 0) and (Position < MINDATAPACKETSIZE)) or
     (Assigned(Result) and (Len <> DWord(Result.Size))) then
    raise Exception.CreateRes(@SInvalidDataPacket);
end;

function TWebConnection.Send(const Data: IDataBlock): Integer;
var
  Request: HINTERNET;
  RetVal, Flags: DWord;
  P: Pointer;
  AcceptTypes: array of PChar;
begin
  SetLength(AcceptTypes, 2);
  AcceptTypes[0] := PChar('application/octet-stream');
  AcceptTypes[1] := nil;
  Flags := INTERNET_FLAG_KEEP_CONNECTION or INTERNET_FLAG_NO_CACHE_WRITE;
  if FURLScheme = INTERNET_SCHEME_HTTPS then
    Flags := Flags or INTERNET_FLAG_SECURE;
  Request := HttpOpenRequest(FInetConnect, 'POST', PChar(FURLSite), nil,
    nil, Pointer(AcceptTypes), Flags, Integer(Self));
  Check(not Assigned(Request));
  while True do
  begin
    Check(not HttpSendRequest(Request, nil, 0, Data.Memory, Data.Size + Data.BytesReserved));
    RetVal := InternetErrorDlg(GetDesktopWindow(), Request, GetLastError,
      FLAGS_ERROR_UI_FILTER_FOR_ERRORS or FLAGS_ERROR_UI_FLAGS_CHANGE_OPTIONS or
      FLAGS_ERROR_UI_FLAGS_GENERATE_DATA, P);
    case RetVal of
      ERROR_SUCCESS: break;
      ERROR_CANCELLED: SysUtils.Abort;
      ERROR_INTERNET_FORCE_RETRY: {Retry the operation};
    end;
  end;
  Result := Integer(Request)
end;

procedure TWebConnection.DoConnect;
begin
  if (ObjectBroker <> nil) then
  begin
    repeat
      if URL = '' then
        if ServerGUID <> '' then
          URL := ObjectBroker.GetComputerForGUID(GetServerCLSID) else
          URL := ObjectBroker.GetComputerForProgID(ServerName);
      try
        inherited DoConnect;
        ObjectBroker.SetConnectStatus(URL, True);
      except
        ObjectBroker.SetConnectStatus(URL, False);
        URL := '';
      end;
    until Connected;
  end else
    inherited DoConnect;
end;

{ TPacketInterceptFactory }

procedure TPacketInterceptFactory.UpdateRegistry(Register: Boolean);
var
  CatReg: ICatRegister;
  Rslt: HResult;
  CatInfo: TCATEGORYINFO;
  Description: string;
begin
  inherited UpdateRegistry(Register);

  Rslt := CoCreateInstance(CLSID_StdComponentCategoryMgr, nil,
    CLSCTX_INPROC_SERVER, ICatRegister, CatReg);
  if Succeeded(Rslt) then
  begin
    if Register then
    begin
      CatInfo.catid := CATID_MIDASInterceptor;
      CatInfo.lcid := $0409;
      StringToWideChar(MIDASInterceptor_CatDesc, CatInfo.szDescription,
        Length(MIDASInterceptor_CatDesc) + 1);
      OleCheck(CatReg.RegisterCategories(1, @CatInfo));
      OleCheck(CatReg.RegisterClassImplCategories(ClassID, 1, @CATID_MIDASInterceptor));
    end else
    begin
      OleCheck(CatReg.UnRegisterClassImplCategories(ClassID, 1, @CATID_MIDASInterceptor));
      DeleteRegKey(Format(SClsid + SCatImplBaseKey, [GUIDToString(ClassID)]));
    end;
  end else
  begin
    if Register then
    begin
      CreateRegKey('Component Categories\' + GUIDToString(CATID_MIDASInterceptor), '409', MIDASInterceptor_CatDesc);
      CreateRegKey(Format(SClsid + SCatImplKey, [GUIDToString(ClassID), GUIDToString(CATID_MIDASInterceptor)]), '', '');
    end else
    begin
      DeleteRegKey(Format(SClsid + SCatImplKey, [GUIDToString(ClassID), GUIDToString(CATID_MIDASAppServer)]));
      DeleteRegKey(Format(SClsid + SCatImplBaseKey, [GUIDToString(ClassID)]));
    end;
  end;
  if Register then
  begin
    Description := GetRegStringValue(SClsid + GUIDToString(ClassID), '');
    CreateRegKey('AppID\' + GUIDToString(ClassID), '', Description);
    CreateRegKey(SClsid + GUIDToString(ClassID), 'AppID', GUIDToString(ClassID));
  end else
    DeleteRegKey('AppID\' + GUIDToString(ClassID));
end;


initialization
finalization
  FreeWinSock2;
end.
