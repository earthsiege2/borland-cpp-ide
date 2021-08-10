
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       ISAPI/NSAPI Web server application components   }
{                                                       }
{  Copyright (c) 2001-2002 Borland Software Corp.       }
{                                                       }
{*******************************************************}

{ The thread pool implemented here is specific to Microsoft's IIS web
  server running on Windows NT/W2K/XP.  This unit is a noop on
  Win95/98/ME since none of them support IO completion ports.  In this case
  the exported functions simply forward all calls to ISAPIApp for execution.
  The same is also true if the application is running on a Netscape server.

References:

1)  John Vert "Writing Scalable Applications for Windows NT"
    http://msdn.microsoft.com/library/techart/msdn_scalabil.htm

2)  Ruediger Asche "Writing Windows NT Server
      Applications in MFC Using I/O Completion Ports"
    http://msdn.microsoft.com/library/techart/msdn_servrapp.htm

3)  Gregory Leake "Architecture Decisions for Dynamic Web
      Applications: Performance, Scalability, and Reliability"
    http://msdn.microsoft.com/library/default.asp?URL=/library/techart/Docu2KBench.htm
}

{$DENYPACKAGEUNIT}

unit ISAPIThreadPool;

interface

uses ISAPI2, Windows;

type
  TISAPIThread = class;

  TISAPIThreadPoolClass = class of TISAPIThreadPool;

   { For Delphi 6.0 Update 2, in order to maintain as much backwards
     compatibility as possible, we've made as few changes to the interface
     of this class as possible.  However in doing so several methods had to
     be marked as deprecated and they will be removed in a future release. }
  TISAPIThreadPool = class(TObject)
  private
    FInitialized: Boolean;
    FThreads: array of THandle;
    FRequestQueue: THandle;
    FInitCOM: Boolean;
    FMin: Integer deprecated;
    FMax: Integer deprecated;
    function GetThreadCount: Integer;
    procedure SetMax(const Value: Integer); deprecated;
    procedure SetMin(const Value: Integer); deprecated;
    procedure SetInitCOM(const Value: Boolean);
  protected
    procedure Initialize; virtual;
    function PushBack(ECB: PEXTENSION_CONTROL_BLOCK): Boolean;
    procedure ShutDown; virtual;
    property RequestQueue: THandle read FRequestQueue;
  public
    constructor Create(InitCOM: Boolean = False); virtual;
    destructor Destroy; override;
    property InitCOM: Boolean read FInitCOM write SetInitCOM;
    function DispatchThread(AECB: PEXTENSION_CONTROL_BLOCK): Boolean; deprecated;
    function RemoveThread(AISAPIThread: TISAPIThread): Boolean; deprecated;
    property Min: Integer read FMin write SetMin default 1;
    property Max: Integer read FMax write SetMax default 32;
    property ThreadCount: Integer read GetThreadCount;
  end;

   { Do not use this class, it is left here to help maintain backwards
     compatibility with shipping Delphi 6.0 only.  It will be removed in the
     future. }
   TISAPIThread = class(TObject)
   private
     FHandle: THandle;
     FThreadID: THandle;
     FSuspended: Boolean;
     FTerminated: Boolean;
     FECB: PEXTENSION_CONTROL_BLOCK;
     FISAPIThreadPool: TISAPIThreadPool;

   public
     constructor Create(AISAPIThreadPool: TISAPIThreadPool);
     destructor Destroy; override;
     procedure Execute;
     procedure Suspend;
     procedure Resume;

     property Suspended: Boolean read FSuspended;
     property Terminated: Boolean read FTerminated write FTerminated;
     property ECB: PEXTENSION_CONTROL_BLOCK read FECB write FECB;
   end deprecated;

var
  { NumberOfThreads is the number of threads used to process incoming
    connections to the server.  If you want to change this value you will
    need to set it prior to the first request (ie your application's main
    program block). }
  NumberOfThreads: Byte;

  { ThreadPoolClass is a class reference which you can set in your main
    program block should you need to implement a descendant of
    TISAPIThreadPool.  Setting this variable to your new thread class
    will cause your class to be used in place of the one provided. }
  ThreadPoolClass: TISAPIThreadPoolClass;

function GetExtensionVersion(var Ver: THSE_VERSION_INFO): BOOL; stdcall;
function HttpExtensionProc(var ECB: TEXTENSION_CONTROL_BLOCK): DWORD; stdcall;
function TerminateExtension(dwFlags: DWORD): BOOL; stdcall;

implementation

uses SysUtils, WebBroker, ISAPIApp, ActiveX;

const
  SHUTDOWN_FLAG = $FFFFFFFF; // Posted to the completion port when shutting down

var
  Pool: TISAPIThreadPool;
  IsNetscape: Boolean;     // True, if loaded on a Netscape server, false otherwise

type
  PServerContext = ^TServerContext;
  TServerContext = record
    ECB: PEXTENSION_CONTROL_BLOCK;
    Token: THandle;
  end;

function WorkerFunction(ThreadPool: TISAPIThreadPool): Integer;
var
  ServerContext: PServerContext;
  CompletionKey: Cardinal;
  Overlapped: POverlapped;
begin
  while GetQueuedCompletionStatus(ThreadPool.FRequestQueue, Cardinal(ServerContext),
    CompletionKey, OverLapped, INFINITE) do
  try
    try
      if Cardinal(OverLapped) = SHUTDOWN_FLAG then   // Shut down
        break;
      with ServerContext^ do
      begin
        ImpersonateLoggedOnUser(Token);
        ISAPIApp.HttpExtensionProc(ECB^);
        ECB^.ServerSupportFunction(ECB^.ConnID, HSE_REQ_DONE_WITH_SESSION, nil, nil, nil);
      end;
    finally
      if Assigned(ServerContext) then
      begin
        CloseHandle(ServerContext^.Token);
        Dispose(ServerContext);
        ServerContext := nil;
      end;
    end;
  except
    // All exceptions should have been handled by ISAPIApp.HttpExtensionProc
  end;
  Result := 0;
end;

// Wraps WorkerFunction with a try...finally to handle COM un/initialization.
function COMWorkerFunction(ThreadPool: TISAPIThreadPool): Integer;
begin
  CoInitializeEx(nil, COINIT_MULTITHREADED or COINIT_SPEED_OVER_MEMORY);
  try
    Result := WorkerFunction(ThreadPool);
  finally
    CoUninitialize;
  end;
end;

{ TISAPIThreadPool }

constructor TISAPIThreadPool.Create;
begin
  FRequestQueue := INVALID_HANDLE_VALUE;
end;

destructor TISAPIThreadPool.Destroy;
begin
  ShutDown;
  inherited Destroy;
end;

procedure TISAPIThreadPool.Initialize;
var
  ThreadID: DWORD;
  I: Integer;
begin
  if FInitialized then exit;
  FInitialized := True;
  // Create IO completion port to queue the ISAPI requests
  FRequestQueue := CreateIoCompletionPort(INVALID_HANDLE_VALUE, 0, 0, 0);

  // Create and initialize worker threads
  SetLength(FThreads, NumberOfThreads);
  for I := 0 to NumberOfThreads - 1 do
    if FInitCOM then
      FThreads[I] := BeginThread(nil, 0, @COMWorkerFunction, Self, 0, ThreadID)
    else
      FThreads[I] := BeginThread(nil, 0, @WorkerFunction, Self, 0, ThreadID);
end;

procedure TISAPIThreadPool.ShutDown;
var
  I: Integer;
begin
  if not FInitialized then exit;
  // Tell the threads we're shutting down
  for I := 0 to NumberOfThreads - 1 do
    PostQueuedCompletionStatus(FRequestQueue, 0, 0, POverLapped(SHUTDOWN_FLAG));

  // Wait for threads to finish
  WaitForMultipleObjects(NumberOfThreads, @FThreads[0], True, 60000 * 2);

  // Close the request queue handle
  CloseHandle(FRequestQueue);

  // Clear the queue handle
  FRequestQueue := INVALID_HANDLE_VALUE;

  // Close the thread handles
  for I := 0 to NumberOfThreads - 1 do
    CloseHandle(FThreads[I]);
  SetLength(FThreads, 0);
end;

function TISAPIThreadPool.PushBack(ECB: PEXTENSION_CONTROL_BLOCK): Boolean;
var
  ServerContext: PServerContext;
begin
  if FRequestQueue <> INVALID_HANDLE_VALUE then
  begin
    New(ServerContext);
    OpenThreadToken(GetCurrentThread(), TOKEN_ALL_ACCESS, False, ServerContext^.Token);
    ServerContext^.ECB := ECB;
    if PostQueuedCompletionStatus(FRequestQueue, Cardinal(ServerContext), 0, nil) then
      Result := True
    else
      Result := False;
  end
  else
    Result := False;
end;

function TISAPIThreadPool.DispatchThread(
  AECB: PEXTENSION_CONTROL_BLOCK): Boolean;
begin
  //  Method has been deprecated
  Result := False;
end;

function TISAPIThreadPool.GetThreadCount: Integer;
begin
  Result := Length(FThreads);
end;

function TISAPIThreadPool.RemoveThread(
  AISAPIThread: TISAPIThread): Boolean;
begin
  //  Method has been deprecated
  Result := False;
end;

procedure TISAPIThreadPool.SetMax(const Value: Integer);
begin
  //  Method has been deprecated
end;

procedure TISAPIThreadPool.SetMin(const Value: Integer);
begin
  //  Method has been deprecated
end;

procedure TISAPIThreadPool.SetInitCOM(const Value: Boolean);
begin
  if FInitialized then exit;
  if Value <> FInitCOM then
    FInitCOM := Value
end;

{ TISAPIThread }

constructor TISAPIThread.Create(AISAPIThreadPool: TISAPIThreadPool);
begin
  FHandle := 0;
  FThreadID := 0;
  FSuspended := False;
  FTerminated := False;
  FECB := nil;
  FISAPIThreadPool := nil;
end;

destructor TISAPIThread.Destroy;
begin
  inherited;
end;

procedure TISAPIThread.Execute;
begin
  // noop, deprecated class
end;

procedure TISAPIThread.Resume;
begin
  // noop, deprecated class
end;

procedure TISAPIThread.Suspend;
begin
  // noop, deprecated class
end;

{ Exported functions }

function GetExtensionVersion(var Ver: THSE_VERSION_INFO): BOOL;
begin
  if (Win32Platform = VER_PLATFORM_WIN32_NT) and not IsNetscape and
     not Assigned(Pool) then
    Pool := ThreadPoolClass.Create;
  Result := ISAPIApp.GetExtensionVersion(Ver);
end;

function HttpExtensionProc(var ECB: TEXTENSION_CONTROL_BLOCK): DWORD;
begin
  if (Win32Platform = VER_PLATFORM_WIN32_NT) and not IsNetscape and
     Assigned(Pool) then
  try
    if not Pool.FInitialized then
      Pool.Initialize;
    Result := HSE_STATUS_ERROR;
    if Pool.PushBack(@ECB) then
      Result := HSE_STATUS_PENDING
  except
    Result := HSE_STATUS_ERROR;
  end
  else
    Result := ISAPIApp.HttpExtensionProc(ECB);
end;

function TerminateExtension(dwFlags: DWORD): BOOL;
begin
  if (Win32Platform = VER_PLATFORM_WIN32_NT) and not IsNetscape and
     Assigned(Pool) then
  begin
    FreeAndNil(Pool);
    Sleep(2000);
    Result := True;
  end
  else
    Result := ISAPIApp.TerminateExtension(dwFlags);
end;

function CheckForNetscapeServer: Boolean;
var
  LoadingModule: string;
begin
  SetLength(LoadingModule, 4096);
  SetLength(LoadingModule, GetModuleFileName(GetModuleHandle(nil),
    PChar(LoadingModule), Length(LoadingModule)));
  Result := CompareText(ExtractFileName(LoadingModule), 'httpd.exe') = 0;  {do not localize}
end;

initialization
  // If we are loading under Netscape do not use the thread pool
  IsNetscape := CheckForNetscapeServer;
  ThreadPoolClass := TISAPIThreadPool;
  NumberOfThreads := 25;
finalization
  FreeAndNil(Pool);
end.

