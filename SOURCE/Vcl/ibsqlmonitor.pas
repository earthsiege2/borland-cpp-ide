{********************************************************}
{                                                        }
{       Borland Delphi Visual Component Library          }
{       InterBase Express core components                }
{                                                        }
{       Copyright (c) 1998-1999 Inprise Corporation      }
{                                                        }
{    InterBase Express is based in part on the product   }
{    Free IB Components, written by Gregory H. Deatz for }
{    Hoagland, Longo, Moran, Dunst & Doukas Company.     }
{    Free IB Components is used under license.           }
{                                                        }
{********************************************************}

unit IBSQLMonitor;

interface

uses
  SysUtils, Windows, Messages, Classes, Forms, Controls, IBUtils,
  IBSQL, IBCustomDataSet, IBDatabase, Dialogs, StdCtrls, IBServices;

resourcestring
  SCantPrintValue = 'Cannot print value';
  SEOFReached = 'SEOFReached'; 
  
const
  WM_MIN_IBSQL_MONITOR = WM_USER;
  WM_MAX_IBSQL_MONITOR = WM_USER + 512;
  WM_IBSQL_SQL_EVENT = WM_MIN_IBSQL_MONITOR + 1;

type
  TIBSQLMonitorHook = class;
  TIBCustomSQLMonitor = class;

  { TIBSQLMonitor }
  TSQLEvent = procedure(EventText: String) of object;

  TIBCustomSQLMonitor = class(TComponent)
  private
    FAtom: TAtom;
    FHWnd: HWND;
    FThread: THandle;
    FOnSQLEvent: TSQLEvent;
    FTraceFlags: TTraceFlags;
  protected
    procedure MonitorHandler(var Msg: TMessage); virtual;
    property OnSQL: TSQLEvent read FOnSQLEvent write FOnSQLEvent;
    property TraceFlags: TTraceFlags read FTraceFlags write FTraceFlags;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  end;

  TIBSQLMonitor = class(TIBCustomSQLMonitor)
  published
    property OnSQL;
  end;

  { TIBSQLMonitorHook }
  TIBSQLMonitorHook = class(TObject)
  private
    FSharedBuffer,                   { MMF for shared memory }
    FWriteLock,                      { Only one writer at a time }
    FWriteEvent,                     { The SQL log has been written }
    FWriteFinishedEvent,             { The SQL log write is finished }
    FReadEvent,                      { All readers are ready }
    FReadFinishedEvent: THandle;     { The SQL log read is now finished }
    FBuffer: PChar;                  { The shared buffer }
    FMonitorCount: PInteger;         { Number of registered monitors }
    FReaderCount: PInteger;          { Number of monitors currently reading }
    FTraceDataType: PInteger;        { Datatype: connect, prepare, trans, .. }
    FBufferSize: PInteger;           { Size of written buffer }
    FTraceFlags: TTraceFlags;
  protected
    procedure ResetStates;
    procedure Lock;
    procedure Unlock;
    procedure BeginWrite;
    procedure EndWrite;
    procedure BeginRead;
    procedure EndRead;
    procedure WriteSQLData(Text: String; DataType: TTraceFlag);
  public
    constructor Create;
    destructor Destroy; override;
    function MonitorCount: Integer;
    procedure RegisterMonitor;
    procedure UnregisterMonitor;
    function ReadSQLData(Arg: TIBCustomSQLMonitor): String;
    procedure SQLPrepare(qry: TIBSQL); virtual;
    procedure SQLExecute(qry: TIBSQL); virtual;
    procedure SQLFetch(qry: TIBSQL); virtual;
    procedure DBConnect(db: TIBDatabase); virtual;
    procedure DBDisconnect(db: TIBDatabase); virtual;
    procedure TRStart(tr: TIBTransaction); virtual;
    procedure TRCommit(tr: TIBTransaction); virtual;
    procedure TRCommitRetaining(tr: TIBTransaction); virtual;
    procedure TRRollback(tr: TIBTransaction); virtual;
    procedure TRRollbackRetaining(tr: TIBTransaction); virtual;
    procedure ServiceAttach(service: TIBCustomService); virtual;
    procedure ServiceDetach(service: TIBCustomService); virtual;
    procedure ServiceQuery(service: TIBCustomService); virtual;
    procedure ServiceStart(service: TIBCustomService); virtual;
    property TraceFlags: TTraceFlags read FTraceFlags write FTraceFlags;
  end;

function MonitorHook: TIBSQLMonitorHook;
procedure EnableMonitoring;
procedure DisableMonitoring;
function MonitoringEnabled: Boolean;

implementation

uses
  IB;

var
  bMonitoringEnabled: Boolean;

procedure EnableMonitoring;
begin
  bMonitoringEnabled := True;
end;

procedure DisableMonitoring;
begin
  bMonitoringEnabled := False;
end;

function MonitoringEnabled: Boolean;
begin
  result := bMonitoringEnabled;
end;

{ TIBCustomSQLMonitor }

procedure IBSQLM_Thread(Arg: TIBCustomSQLMonitor); stdcall;
var
  st: String;
  len: Integer;
  FBuffer: PChar;
begin
  while (Arg <> nil) and (Arg.FHWnd <> 0) do begin
    st := MonitorHook.ReadSQLData(Arg);
    if (st <> '') and (Arg.FHWnd <> 0) then begin
      len := Length(st);
      GetMem(FBuffer, len + SizeOf(Integer));
      Move(len, FBuffer[0], SizeOf(Integer));
      Move(st[1], FBuffer[SizeOf(Integer)], len);
      PostMessage(
        Arg.FHWnd,
        WM_IBSQL_SQL_EVENT,
        WPARAM(Arg),
        LPARAM(FBuffer));
    end;
  end;
  ExitThread(0);
end;

{function InitWndProc(HWindow: HWnd; Message, WParam: Longint;
  LParam: Longint): Longint; stdcall;}
function IBSQLM_WindowProc(_hWnd: HWND; Msg: UINT; _wParam: WPARAM;
  _lParam: LPARAM): LRESULT; stdcall;
var
  MsgRec: TMessage;
begin
  MsgRec.Msg := Msg;
  MsgRec.WParam := _wParam;
  MsgRec.LParam := _lParam;
  case Msg of
    WM_CREATE:
      result := 0;
    else begin
      if ((Msg >= WM_MIN_IBSQL_MONITOR) and
          (Msg <= WM_MAX_IBSQL_MONITOR)) then begin
        try
          TIBCustomSQLMonitor(_wParam).MonitorHandler(MsgRec);
        except
          ;
        end;
        result := MsgRec.Result;
      end else
        result := DefWindowProc(_hWnd, Msg, _wParam, _lParam);
    end;
  end;
end;

var
  MonitorClass: TWndClass = (
    style: 0;
    lpfnWndProc: @IBSQLM_WindowProc;
    cbClsExtra: 0;
    cbWndExtra: 0;
    hInstance: 0;
    hIcon: 0;
    hCursor: 0;
    hbrBackground: 0;
    lpszMenuName: nil;
    lpszClassName: 'TIBCustomSQLMonitor' {do not localize}
  );

constructor TIBCustomSQLMonitor.Create(AOwner: TComponent);
var
  TempClass: TWndClass;
  ThreadID: DWORD;
begin
  inherited;
  FTraceFlags := [tfqPrepare .. tfMisc];
  MonitorClass.hInstance := HInstance;
  if not GetClassInfo(HInstance, MonitorClass.lpszClassName,
           TempClass) then begin
    FAtom := Windows.RegisterClass(MonitorClass);
    if FAtom = 0 then
      IBError(ibxeWindowsAPIError, [GetLastError, GetLastError]);
  end;
  FHWnd := CreateWindow(PChar(FAtom), '', 0, 0, 0, 0, 0,
             0, 0, HInstance, nil);
  if FHWnd = 0 then
    IBError(ibxeSQLMonitorAlreadyPresent, []);
  if not (csDesigning in ComponentState) then
  begin
    MonitorHook.RegisterMonitor;
    FThread := CreateThread(nil, 0, @IBSQLM_Thread, Pointer(Self), 0, ThreadID);
    if FThread = 0 then
      IBError(ibxeWindowsAPIError, [GetLastError, GetLastError]);
  end;
end;

destructor TIBCustomSQLMonitor.Destroy;
begin
  if csDesigning in ComponentState then
  begin
    DestroyWindow(FHWnd);
    Windows.UnregisterClass(PChar(FAtom), HInstance);
  end
  else begin
    MonitorHook.UnregisterMonitor;
    DestroyWindow(FHWnd);
    FHWnd := 0;
    MonitorHook.ResetStates;
    if WaitForSingleObject(FThread, 10000) = WAIT_TIMEOUT then
      CloseHandle(FThread);
    Windows.UnregisterClass(PChar(FAtom), HInstance);
    FAtom := 0;
  end;
  inherited;
end;

procedure TIBCustomSQLMonitor.MonitorHandler(var Msg: TMessage);
var
  st: String;
begin
  if (Msg.Msg = WM_IBSQL_SQL_EVENT) then begin
    if (Assigned(FOnSQLEvent)) then begin
      begin
        SetString(st, PChar(Msg.LParam) + SizeOf(Integer),
                  PInteger(Msg.LParam)^);
        FreeMem(PChar(Msg.LParam));
        FOnSQLEvent(st);
      end;
    end;
  end else
    Msg.Result := DefWindowProc(FHWnd, Msg.Msg, Msg.WParam, Msg.LParam);
end;

{ TIBSQLMonitorHook }

const
  MonitorHookNames: array[0..5] of String = (
    'IB.SQL.MONITOR.Mutex',
    'IB.SQL.MONITOR.SharedMem',
    'IB.SQL.MONITOR.WriteEvent',
    'IB.SQL.MONITOR.WriteFinishedEvent',
    'IB.SQL.MONITOR.ReadEvent',
    'IB.SQL.MONITOR.ReadFinishedEvent'
  );
  cMonitorHookSize = 1024;
  cMaxBufferSize = cMonitorHookSize - (4 * SizeOf(Integer));
  cDefaultTimeout = 2000; { 2 seconds }

constructor TIBSQLMonitorHook.Create;
  function CreateLocalEvent(Idx: Integer; InitialState: Boolean): THandle;
  begin
    result := CreateEvent(nil, True, InitialState, PChar(MonitorHookNames[Idx]));
    if result = 0 then
      IBError(ibxeCannotCreateSharedResource, [GetLastError]);
  end;

begin
  { Create the MMF with the initial size, and
    create all events with an initial state of non-signalled }
  FWriteLock := CreateMutex(nil, False, PChar(MonitorHookNames[0]));
  if (FWriteLock = 0) then
    IBError(ibxeCannotCreateSharedResource, [GetLastError]);
  Lock; { Serialize the creation of memory mapped files. }
  try
    FWriteEvent := CreateLocalEvent(2, False);
    FWriteFinishedEvent := CreateLocalEvent(3, True);
    FReadEvent := CreateLocalEvent(4, False);
    FReadFinishedEvent := CreateLocalEvent(5, False);
    { Set up the MMF }
    FSharedBuffer := CreateFileMapping(
                       $FFFFFFFF, nil, PAGE_READWRITE, 0, cMonitorHookSize,
                       PChar(MonitorHookNames[1]));
    if (FSharedBuffer = 0) then
      IBError(ibxeCannotCreateSharedResource, [GetLastError]);
    FBuffer := MapViewOfFile(FSharedBuffer, FILE_MAP_ALL_ACCESS, 0, 0, 0);
    FMonitorCount := PInteger(FBuffer + cMonitorHookSize - SizeOf(Integer));
    FReaderCount := PInteger(PChar(FMonitorCount) - SizeOf(Integer));
    FTraceDataType := PInteger(PChar(FReaderCount) - SizeOf(Integer));
    FBufferSize := PInteger(PChar(FTraceDataType) - SizeOf(Integer));
    FMonitorCount^ := 0;
    FReaderCount^ := 0;
    FBufferSize^ := 0;
  finally
    Unlock;
  end;
end;

destructor TIBSQLMonitorHook.Destroy;
begin
  Lock;
  try
    UnmapViewOfFile(FBuffer);
    CloseHandle(FSharedBuffer);
    CloseHandle(FWriteEvent);
    CloseHandle(FWriteFinishedEvent);
    CloseHandle(FReadEvent);
    CloseHandle(FReadFinishedEvent);
  finally
    Unlock;
    CloseHandle(FWriteLock);
  end;
  inherited;
end;

procedure TIBSQLMonitorHook.ResetStates;
begin
  SetEvent(FWriteEvent);
  SetEvent(FWriteFinishedEvent);
end;


procedure TIBSQLMonitorHook.Lock;
begin
  WaitForSingleObject(FWriteLock, INFINITE);
end;

procedure TIBSQLMonitorHook.Unlock;
begin
  ReleaseMutex(FWriteLock);
end;

procedure TIBSQLMonitorHook.BeginWrite;
begin
  Lock;
end;

procedure TIBSQLMonitorHook.EndWrite;
begin
  {
   * 1. Wait to end the write until all registered readers have
   *    started to wait for a write event
   * 2. Block all of those waiting for the write to finish.
   * 3. Block all of those waiting for all readers to finish.
   * 4. Unblock all readers waiting for a write event.
   * 5. Wait until all readers have finished reading.
   * 6. Now, block all those waiting for a write event.
   * 7. Unblock all readers waiting for a write to be finished.
   * 8. Unlock the mutex.
   }
  while WaitForSingleObject(FReadEvent, cDefaultTimeout) = WAIT_TIMEOUT do begin
    if FMonitorCount^ > 0 then
      Dec(FMonitorCount^);
    if (FReaderCount^ = FMonitorCount^ - 1) or (FMonitorCount^ = 0) then
      SetEvent(FReadEvent);
  end;
  ResetEvent(FWriteFinishedEvent);
  ResetEvent(FReadFinishedEvent);
  SetEvent(FWriteEvent); { Let all readers pass through. }
  while WaitForSingleObject(FReadFinishedEvent,
          cDefaultTimeout) = WAIT_TIMEOUT do begin
    if (FReaderCount^ = 0) or (InterlockedDecrement(FReaderCount^) = 0) then
      SetEvent(FReadFinishedEvent);
  end;
  ResetEvent(FWriteEvent);
  SetEvent(FWriteFinishedEvent);
  Unlock;
end;

procedure TIBSQLMonitorHook.BeginRead;
begin
  {
   * 1. Wait for the "previous" write event to complete.
   * 2. Increment the number of readers.
   * 3. if the reader count is the number of interested readers, then
   *    inform the system that all readers are ready.
   * 4. Finally, wait for the FWriteEvent to signal.
   }
  WaitForSingleObject(FWriteFinishedEvent, INFINITE);
  InterlockedIncrement(FReaderCount^);
  if FReaderCount^ = FMonitorCount^ then
    SetEvent(FReadEvent);
  WaitForSingleObject(FWriteEvent, INFINITE);
end;

procedure TIBSQLMonitorHook.EndRead;
begin
  if InterlockedDecrement(FReaderCount^) = 0 then
    SetEvent(FReadFinishedEvent);
end;

procedure TIBSQLMonitorHook.RegisterMonitor;
begin
  Lock;
  try
    Inc(FMonitorCount^);
  finally
    Unlock;
  end;
end;

procedure TIBSQLMonitorHook.UnregisterMonitor;
begin
  Lock;
  try
    Dec(FMonitorCount^);
  finally
    Unlock;
  end;
end;

function TIBSQLMonitorHook.MonitorCount: Integer;
begin
  Lock;
  try
    result := FMonitorCount^;
  finally
    Unlock;
  end;
end;

function TIBSQLMonitorHook.ReadSQLData(Arg: TIBCustomSQLMonitor): String;
begin
  BeginRead;
  try
    if TTraceFlag(FTraceDataType^) in Arg.TraceFlags then
      SetString(result, FBuffer, FBufferSize^)
    else
      result := '';
  finally
    EndRead;
  end;
end;

procedure TIBSQLMonitorHook.SQLPrepare(qry: TIBSQL);
var
  st: String;
begin
  if bMonitoringEnabled and (MonitorCount > 0)then begin
    if not ((tfQPrepare in FTraceFlags) or (tfStmt in FTraceFlags)) then
      Exit;
    if qry.Owner is TIBDataSet then
      st := TIBDataSet(qry.Owner).Name
    else
      st := qry.Name;
    st := st + ': [Prepare] ' + qry.SQL.Text + CRLF; {do not localize}
    st := st + '  Plan: ' + qry.Plan; {do not localize}
    WriteSQLData(st, tfQPrepare);
  end;
end;

procedure TIBSQLMonitorHook.SQLExecute(qry: TIBSQL);
var
  st: String;
  i: Integer;
begin
  if bMonitoringEnabled and (MonitorCount > 0)then begin
    if not ((tfQExecute in FTraceFlags) or (tfStmt in FTraceFlags)) then
      Exit;
    if qry.Owner is TIBDataSet then
      st := TIBDataSet(qry.Owner).Name
    else
      st := qry.Name;
    st := st + ': [Execute] ' + qry.SQL.Text; {do not localize}
    if qry.Params.Count > 0 then begin
      for i := 0 to qry.Params.Count - 1 do begin
        st := st + CRLF + '  ' + qry.Params[i].Name + ' = '; 
        try
          if qry.Params[i].IsNull then
            st := st + '<NULL>'; {do not localize}
          st := st + qry.Params[i].AsString;
        except
          st := st + '<' + SCantPrintValue + '>';
        end;
      end;
    end;
    WriteSQLData(st, tfQExecute);
  end;
end;

procedure TIBSQLMonitorHook.SQLFetch(qry: TIBSQL);
var
  st: String;
begin
  if bMonitoringEnabled and (MonitorCount > 0)then begin
    if not ((tfQFetch in FTraceFlags) or (tfStmt in FTraceFlags)) then
      Exit;
    if qry.Owner is TIBDataSet then
      st := TIBDataSet(qry.Owner).Name
    else
      st := qry.Name;
    st := st + ': [Fetch] ' + qry.SQL.Text; {do not localize}
    if (qry.EOF) then
      st := st + CRLF + '  ' + SEOFReached;
    WriteSQLData(st, tfQFetch);
  end;
end;

procedure TIBSQLMonitorHook.DBConnect(db: TIBDatabase);
var
  st: String;
begin
  if bMonitoringEnabled and (MonitorCount > 0)then begin
    if not (tfConnect in FTraceFlags) then
      Exit;
    st := db.Name + ': [Connect]'; {do not localize}
    WriteSQLData(st, tfConnect) ;
  end;
end;

procedure TIBSQLMonitorHook.DBDisconnect(db: TIBDatabase);
var
  st: String;
begin
  if (Self = nil) then exit;
  if bMonitoringEnabled and (MonitorCount > 0)then begin
    if not (tfConnect in FTraceFlags) then
      Exit;
    st := db.Name + ': [Disconnect]'; {do not localize}
    WriteSQLData(st, tfConnect);
  end;
end;

procedure TIBSQLMonitorHook.TRStart(tr: TIBTransaction);
var
  st: String;
begin
  if bMonitoringEnabled and (MonitorCount > 0)then begin
    if not (tfTransact in FTraceFlags) then
      Exit;
    st := tr.Name + ': [Start transaction]'; {do not localize}
    WriteSQLData(st, tfTransact);
  end;
end;

procedure TIBSQLMonitorHook.TRCommit(tr: TIBTransaction);
var
  st: String;
begin
  if bMonitoringEnabled and (MonitorCount > 0)then begin
    if not (tfTransact in FTraceFlags) then
      Exit;
    st := tr.Name + ': [Commit (Hard commit)]'; {do not localize}
    WriteSQLData(st, tfTransact);
  end;
end;

procedure TIBSQLMonitorHook.TRCommitRetaining(tr: TIBTransaction);
var
  st: String;
begin
  if bMonitoringEnabled and (MonitorCount > 0)then begin
    if not (tfTransact in FTraceFlags) then
      Exit;
    st := tr.Name + ': [Commit retaining (Soft commit)]'; {do not localize}
    WriteSQLData(st, tfTransact);
  end;
end;

procedure TIBSQLMonitorHook.TRRollback(tr: TIBTransaction);
var
  st: String;
begin
  if bMonitoringEnabled and (MonitorCount > 0)then begin
    if not (tfTransact in FTraceFlags) then
      Exit;
    st := tr.Name + ': [Rollback]'; {do not localize}
    WriteSQLData(st, tfTransact);
  end;
end;

procedure TIBSQLMonitorHook.TRRollbackRetaining(tr: TIBTransaction);
var
  st: String;
begin
  if bMonitoringEnabled and (MonitorCount > 0)then begin
    if not (tfTransact in FTraceFlags) then
      Exit;
    st := tr.Name + ': [Rollback retaining (Soft rollback)]'; {do not localize}
    WriteSQLData(st, tfTransact);
  end;
end;

procedure TIBSQLMonitorHook.ServiceAttach(service: TIBCustomService);
var
  st: String;
begin
  if bMonitoringEnabled and (MonitorCount > 0)then begin
    if not (tfService in FTraceFlags) then
      Exit;
    st := service.Name + ': [Attach]'; {do not localize}
    WriteSQLData(st, tfService);
  end;
end;

procedure TIBSQLMonitorHook.ServiceDetach(service: TIBCustomService);
var
  st: String;
begin
  if bMonitoringEnabled and (MonitorCount > 0)then begin
    if not (tfService in FTraceFlags) then
      Exit;
    st := service.Name + ': [Detach]'; {do not localize}
    WriteSQLData(st, tfService);
  end;
end;

procedure TIBSQLMonitorHook.ServiceQuery(service: TIBCustomService);
var
  st: String;
begin
  if bMonitoringEnabled and (MonitorCount > 0)then begin
    if not (tfService in FTraceFlags) then
      Exit;
    st := service.Name + ': [Query]'; {do not localize}
    WriteSQLData(st, tfService);
  end;
end;

procedure TIBSQLMonitorHook.ServiceStart(service: TIBCustomService);
var
  st: String;
begin
  if bMonitoringEnabled and (MonitorCount > 0)then begin
    if not (tfService in FTraceFlags) then
      Exit;
    st := service.Name + ': [Start]'; {do not localize}
    WriteSQLData(st, tfService);
  end;
end;

procedure TIBSQLMonitorHook.WriteSQLData(Text: String; DataType: TTraceFlag);
var
  i, len: Integer;

begin
  Text := CRLF + '[Application: ' + Application.Title + ']' + CRLF + Text; {do not localize}
  Lock;
  try
    i := 1;
    len := Length(Text);
    while (len > 0) do begin
      BeginWrite;
      try
        FTraceDataType^ := Integer(DataType);
        FBufferSize^ := Min(len, cMaxBufferSize);
        Move(Text[i], FBuffer[0], FBufferSize^);
        Inc(i, cMaxBufferSize);
        Dec(len, cMaxBufferSize);
      finally
        EndWrite;
      end;
    end;
  finally
    Unlock;
  end;
end;

var
  _MonitorHook: TIBSQLMonitorHook;
  bDone: Boolean;

function MonitorHook: TIBSQLMonitorHook;
begin
  if (_MonitorHook = nil) and (not bDone) then
    _MonitorHook := TIBSQLMonitorHook.Create;
  result := _MonitorHook;
end;

initialization

  bMonitoringEnabled := True;
  _MonitorHook := nil;
  bDone := False;

finalization

  bDone := True;
  _MonitorHook.Free;
  _MonitorHook := nil;

end.
