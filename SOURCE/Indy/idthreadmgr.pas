unit IdThreadMgr;

interface

uses
  Classes,
  IdException,
  IdBaseComponent,
  IdThread,
  SyncObjs;

type
  TIdThreadMgr = class(TIdBaseComponent)
  protected
    FActiveThreads: TList;
    FLock: TCriticalSection;
    FThreadClass: TIdThreadClass;
  public
    constructor Create(AOwner: TComponent); override;
    function CreateNewThread: TIdThread; virtual;
    destructor Destroy; override;
    function GetThread: TIdThread; virtual; abstract;
    procedure ReleaseThread(AThread: TIdThread); virtual; abstract;
    procedure TerminateThreads(Threads: TList);
    property ActiveThreads: TList read FActiveThreads;
    property Lock: TCriticalSection read FLock;
    property ThreadClass: TIdThreadClass read FThreadClass write FThreadClass;
  end;

  EIdThreadMgrError = class(EIdException);
  EIdThreadClassNotSpecified = class(EIdThreadMgrError);

implementation

uses
  IdGlobal,
  IdResourceStrings,
  IdTCPServer,
  SysUtils;

constructor TIdThreadMgr.Create(AOwner: TComponent);
begin
  inherited;
  FActiveThreads := TList.Create;
  FLock := TCriticalSection.Create;
end;

function TIdThreadMgr.CreateNewThread: TIdThread;
begin
  if ThreadClass = nil then
  begin
    raise EIdThreadClassNotSpecified.create(RSThreadClassNotSpecified);
  end;
  result := TIdThreadClass(ThreadClass).Create;
end;

destructor TIdThreadMgr.Destroy;
begin
  FreeAndNil(FActiveThreads);
  FreeAndNil(FLock);
  inherited;
end;

procedure TIdThreadMgr.TerminateThreads(Threads: TList);
var
  Thread: TIdThread;
  i: integer;
begin
  for i := Threads.Count - 1 downto 0 do
  begin
    Thread := TObject(Threads[i]) as TIdThread;
    if Thread is TIdPeerThread then
    begin
      TIdPeerThread(Thread).Connection.Disconnect;
    end;
    ReleaseThread(Thread);
    Threads.Delete(i);
  end;
end;

end.
