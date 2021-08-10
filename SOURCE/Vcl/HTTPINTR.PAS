{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1995,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit HTTPIntr;

interface

uses
  Windows, Messages, SysUtils, Classes, HTTPApp, SConnect;

type

  { THTTPServer }

  THTTPServer = class(TWebModule, ISendDataBlock)
    procedure InterpreterAction(Sender: TObject; Request: TWebRequest;
      Response: TWebResponse; var Handled: Boolean);
  private
    FInterpreter: TDataBlockInterpreter;
    FData: IDataBlock;
  protected
    function Send(const Data: IDataBlock; WaitForResult: Boolean): IDataBlock; stdcall;
  end;

var
  HTTPServer: THTTPServer;

implementation

uses
  ComObj, ActiveX, MidConst, IsapiApp;

{$R *.DFM}

type

  { TPooledDataInterpreter }

  TPooledDataInterpreter = class(TDataBlockInterpreter)
  protected
    function InternalCreateObject(const ClassID: TGUID): OleVariant; override;
    function StoreObject(const Value: OleVariant): Integer; override;
    function LockObject(ID: Integer): IDispatch; override;
    procedure UnLockObject(ID: Integer; const Disp: IDispatch); override;
    procedure ReleaseObject(ID: Integer); override;
  end;

  { TObject List }

  PObjectInfo = ^TObjectInfo;
  TObjectInfo = record
    Obj: IDispatch;
    LastAccessed: TDateTime;
    Locked: Boolean;
  end;

  TObjectList = class
  private
    FClassID: string;
    FLock: TRTLCriticalSection;
    FOwner: TStringList;
    FIndex: Integer;
    FList: TList;
    FMaxObjects: Integer;
    FSingleton: Boolean;
    FTimeout: TDateTime;
  public
    constructor Create(List: TStringList; const ClassID: string);
    destructor Destroy; override;
    procedure Lock;
    procedure UnLock;
    function LockObject: IDispatch;
    procedure UnlockObject(const Dispatch: IDispatch);
    property MaxObjects: Integer read FMaxObjects;
    property Singleton: Boolean read FSingleton;
    property Timeout: TDateTime read FTimeout;
  end;

  { TGarbageCollector }

  TGarbageCollector = class(TThread)
  private
    FEvent: THandle;
  protected
    procedure Execute; override;
  public
    constructor Create;
    destructor Destroy; override;
    property Event: THandle read FEvent;
  end;

  { TObjectManager }

  TObjectManager = class
  private
    FStateObjects: OleVariant;
    FLock: TRTLCriticalSection;
    FList: TStringList;
    FNextID: Integer;
    FSemaphore: THandle;
    FGarbageCollector: TGarbageCollector;
  protected
    procedure Lock;
    procedure Unlock;
    function GetCatID(const ClassID: TGUID): Integer;
    function LockList(CatID: Integer): TObjectList;
  public
    constructor Create;
    destructor Destroy; override;
    property Semaphore: THandle read FSemaphore;
    function CreateObject(const ClassID: TGUID): OleVariant;
    function StoreObject(const Value: OleVariant): Integer;
    function LockObject(ID: Integer): OleVariant;
    procedure UnLockObject(ID: Integer; const Disp: IDispatch);
    procedure ReleaseObject(ID: Integer);
  end;

var
  ObjectManager: TObjectManager;

{ THTTPServer }

function THTTPServer.Send(const Data: IDataBlock; WaitForResult: Boolean): IDataBlock;
begin
  FData := Data;
  Result := nil;
end;

procedure THTTPServer.InterpreterAction(Sender: TObject;
  Request: TWebRequest; Response: TWebResponse; var Handled: Boolean);
var
  DataBlock: IDataBlock;
  S: string;
  BytesRead, ChunkSize: Integer;
  DataPacket: array of Byte;
begin
  FData := nil;
  if not Assigned(FInterpreter) then
    FInterpreter := TPooledDataInterpreter.Create(Self, SWeb);
  S := Request.Content;
  BytesRead := Length(S);
  DataBlock := TDataBlock.Create;
  if BytesRead < Request.ContentLength then
  begin
    SetLength(DataPacket, Request.ContentLength);
    Move(S[1], DataPacket[0], BytesRead);
    repeat
      ChunkSize := TISAPIRequest(Request).ReadClient(Pointer(@Datapacket[BytesRead])^, Request.ContentLength - BytesRead);
      if ChunkSize > 0 then
      begin
        Inc(BytesRead, ChunkSize);
      end;
    until ChunkSize = -1;
    DataBlock.InitData(@DataPacket[0], Request.ContentLength, True);
  end else
    DataBlock.InitData(@S[1], Request.ContentLength, True);
  FInterpreter.InterpretData(DataBlock);
  if Assigned(FData) then
  begin
    Response.ContentStream := FData.Stream;
    FData.IgnoreStream;
  end;
end;

{ TPooledDataInterpreter }

function TPooledDataInterpreter.InternalCreateObject(const ClassID: TGUID): OleVariant;
begin
  Result := ObjectManager.CreateObject(ClassID);
end;

function TPooledDataInterpreter.StoreObject(const Value: OleVariant): Integer;
begin
  Result := ObjectManager.StoreObject(Value);
end;

function TPooledDataInterpreter.LockObject(ID: Integer): IDispatch;
begin
  Result := ObjectManager.LockObject(ID);
end;

procedure TPooledDataInterpreter.UnLockObject(ID: Integer; const Disp: IDispatch);
begin
  ObjectManager.UnLockObject(ID, Disp);
end;

procedure TPooledDataInterpreter.ReleaseObject(ID: Integer);
begin
  ObjectManager.ReleaseObject(ID);
end;

{ TObjectList }

constructor TObjectList.Create(List: TStringList; const ClassID: string);
var
  i: Integer;
begin
  InitializeCriticalSection(FLock);
  FList := TList.Create;
  FClassID := ClassID;
  FOwner := List;
  try
    FMaxObjects := StrToInt(GetRegStringValue(SClsid + ClassID, SMaxObjects));
    if FMaxObjects = 0 then FMaxObjects := MaxInt - 1;
  except
    FMaxObjects := MaxInt;
  end;
  FSingleton := GetRegStringValue(SClsid + ClassID, SSingleton) = SFlagOn;
  try
    i := StrToInt(GetRegStringValue(SClsid + ClassID, STimeout));
    FTimeout := EncodeTime(i div 60, i mod 60, 0, 0);
  except
    FTimeout := 0;
  end;
  FIndex := FOwner.AddObject(ClassID, Self);
end;

destructor TObjectList.Destroy;
var
  i: Integer;
begin
  Lock;
  try
    for i := 0 to FList.Count - 1 do
      Dispose(PObjectInfo(FList[i]));
    FOwner.Delete(FIndex);
    inherited Destroy;
  finally
    UnLock;
    DeleteCriticalSection(FLock);
  end;
end;

procedure TObjectList.Lock;
begin
  EnterCriticalSection(FLock);
end;

procedure TObjectList.UnLock;
begin
  LeaveCriticalSection(FLock);
end;

function TObjectList.LockObject: IDispatch;

  function CreateInfo: PObjectInfo;
  begin
    New(Result);
    try
      Result.LastAccessed := Now;
      { Singleton Object is never locked }
      Result.Locked := not Singleton;
      { For singleton objects, the object create needs to be blocked,
        for pooled objects, the creation shouldn't be blocked }
      if Singleton then
        Result.Obj := CreateComObject(StringToGUID(FClassID)) as IDispatch else
        Result.Obj := nil;
      FList.Add(Result);
    except
      Dispose(Result);
      raise;
    end;
  end;

var
  i: Integer;
  P: PObjectInfo;
begin
  if Singleton then
  begin
    if FList.Count < 1 then
    begin
      Lock;
      try
        if FList.Count < 1 then
          CreateInfo;
      finally
        Unlock;
      end;
    end;
    with PObjectInfo(FList[0])^ do
    begin
      LastAccessed := Now;
      Result := Obj;
    end;
  end else
  begin
    P := nil;
    Lock;
    try
      for i := 0 to FList.Count - 1 do
        with PObjectInfo(FList[i])^ do
          if not Locked then
          begin
            Locked := True;
            LastAccessed := Now;
            Result := Obj;
            Exit;
          end;
      if FList.Count >= MaxObjects then
        raise Exception.CreateRes(@SServerIsBusy);
      P := CreateInfo;
    finally
      Unlock;
    end;
    if Assigned(P) then
    begin
      try
        P.Obj := CreateComObject(StringToGUID(FClassID)) as IDispatch;
      except
        Lock;
        try
          FList.Remove(P);
          Dispose(P);
        finally
          Unlock;
        end;
        raise;
      end;
      Result := P.Obj;
    end;
  end;
end;

procedure TObjectList.UnlockObject(const Dispatch: IDispatch);
var
  i: Integer;
begin
  if Singleton then
  begin
    PObjectInfo(FList[0]).LastAccessed := Now;
  end else
  begin
    Lock;
    try
      for i := 0 to FList.Count - 1 do
        with PObjectInfo(FList[i])^ do
          if Obj = Dispatch then
          begin
            Locked := False;
            LastAccessed := Now;
            Exit;
          end;
    finally
      Unlock;
    end;
  end;
end;

constructor TGarbageCollector.Create;
begin
  FEvent := CreateEvent(nil, False, False, nil);
  inherited Create(False);
end;

destructor TGarbageCollector.Destroy;
begin
  CloseHandle(FEvent);
  inherited Destroy;
end;

procedure TGarbageCollector.Execute;

  function CheckObject(ObjectInfo: PObjectInfo; Timeout: TDateTime): Boolean;
  begin
    Result := False;
    with ObjectInfo^ do
    begin
      if not Locked then
      begin
        Result := (Timeout > 0) and ((Now - LastAccessed) > Timeout);
        if Result then Obj := nil;
      end;
    end;
  end;

  procedure CheckObjectList(ObjectList: TObjectList);
  var
    i: Integer;
  begin
    with ObjectList do
    begin
      if not Singleton then
      begin
        Lock;
        try
          for i := 0 to FList.Count - 1 do
            if CheckObject(PObjectInfo(FList[i]), Timeout) then
            begin
              Dispose(PObjectInfo(FList[i]));
              FList.Delete(i);
            end;
        finally
          Unlock;
        end;
      end;
    end;
  end;

var
  i: Integer;
begin
  while not Terminated do
    if WaitForSingleObject(FEvent, 360000) = WAIT_TIMEOUT then
    begin
      ObjectManager.Lock;
      try
        for i := 0 to ObjectManager.FList.Count - 1 do
          CheckObjectList(TObjectList(ObjectManager.FList.Objects[i]));
      finally
        ObjectManager.Unlock;
      end;
    end else
      Exit;
end;

{ TObjectManager }

constructor TObjectManager.Create;
begin
  InitializeCriticalSection(FLock);
  FNextID := 0;
  FList := TStringList.Create;
  FList.Sorted := True;
  FGarbageCollector := TGarbageCollector.Create;
end;

destructor TObjectManager.Destroy;
var
  i: Integer;
begin
  FGarbageCollector.Terminate;
  PulseEvent(FGarbageCollector.Event);
  FGarbageCollector.WaitFor;
  Lock;
  try
    for i := 0 to FList.Count - 1 do
      TObjectList(FList[i]).Free;
    FList.Free;
    inherited Destroy;
  finally
    UnLock;
    DeleteCriticalSection(FLock);
  end;
end;

procedure TObjectManager.Lock;
begin
  EnterCriticalSection(FLock);
end;

procedure TObjectManager.Unlock;
begin
  LeaveCriticalSection(FLock);
end;

function TObjectManager.GetCatID(const ClassID: TGUID): Integer;
var
  S: string;
begin
  Lock;
  try
    S := GuidToString(ClassID);
    if not FList.Find(S, Result) then
      Result := FList.AddObject(S, TObjectList.Create(FList, S));
    Result := (Result + 1) shl 16;
  finally
    Unlock;
  end;
end;

function TObjectManager.LockList(CatID: Integer): TObjectList;
begin
  Lock;
  try
    Result := TObjectList(FList.Objects[HiWord(CatID) - 1]);
  finally
    Unlock;
  end;
end;

function TObjectManager.CreateObject(const ClassID: TGUID): OleVariant;

  function CreateObject(const ClassID: TGUID): IDispatch;
  var
    Unk: IUnknown;
  begin
    OleCheck(CoCreateInstance(ClassID, nil, CLSCTX_INPROC_SERVER or
      CLSCTX_LOCAL_SERVER or CLSCTX_REMOTE_SERVER, IUnknown, Unk));
    Result := Unk as IDispatch;
  end;

  function IsClassPooled(ClassID: TGUID): Boolean;
  begin
    Result := GetRegStringValue(SClsid + GuidToString(ClassID), SPooled) = SFlagOn;
  end;

begin
  if IsClassPooled(ClassID) then
    Result := GetCatID(ClassID) else
    Result := CreateObject(ClassID);
end;

function TObjectManager.StoreObject(const Value: OleVariant): Integer;
begin
  { This is only used for statefull objects }
  Lock;
  try
    if not VarIsArray(FStateObjects) then
      FStateObjects := VarArrayCreate([0,10], varVariant);
    Result := FNextID;
    if Result > VarArrayHighBound(FStateObjects, 1) then
      VarArrayRedim(FStateObjects, Result + 10);
    if VarIsEmpty(FStateObjects[Result]) then
      FNextID := Result + 1 else
      FNextID := FStateObjects[Result];
    FStateObjects[Result] := Value;
  finally
    UnLock;
  end;
end;

function TObjectManager.LockObject(ID: Integer): OleVariant;
begin
  if HiWord(ID) = 0 then
  begin
    Lock;
    try
      Result := FStateObjects[ID];
    finally
      UnLock;
    end;
  end else
    Result := LockList(ID).LockObject;
end;

procedure TObjectManager.UnLockObject(ID: Integer; const Disp: IDispatch);
begin
  { Only used for stateless objects }
  if HiWord(ID) > 0 then LockList(ID).UnlockObject(Disp);
end;

procedure TObjectManager.ReleaseObject(ID: Integer);
begin
  { This is only used for statefull objects }
  if HiWord(ID) > 0 then Exit;
  Lock;
  try
    if (ID >= 0) and (VarIsArray(FStateObjects)) and
       (ID < VarArrayHighBound(FStateObjects, 1)) then
    begin
      FStateObjects[ID] := FNextID;
      FNextID := ID;
    end;
  finally
    UnLock;
  end;
end;

initialization
  CoInitializeEx(nil, COINIT_MULTITHREADED);
  ObjectManager := TObjectManager.Create;
finalization
  ObjectManager.Free;
  CoUninitialize;
end.
