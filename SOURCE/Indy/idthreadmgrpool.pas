unit IdThreadMgrPool;

interface

uses
  Classes,
  IdThread, IdThreadMgr;

type
  TIdThreadMgrPool = class(TIdThreadMgr)
  protected
    FPoolSize: Integer;
    FThreadPool: TList;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function GetThread: TIdThread; override;
    procedure ReleaseThread(AThread: TIdThread); override;
  published
    property PoolSize: Integer read FPoolSize write FPoolSize default 0;
  end;

implementation

uses
  IdGlobal, SysUtils;

constructor TIdThreadMgrPool.Create(AOwner: TComponent);
begin
  inherited;
  FThreadPool := TList.Create;
end;

destructor TIdThreadMgrPool.Destroy;
var
  i: integer;
begin
  PoolSize := 0;
  Lock.Enter;
  try
    for i := 0 to FThreadPool.Count - 1 do
    begin
      TIdThread(FThreadPool[i]).Free;
    end;
  finally
    Lock.Leave;
  end;
  FreeAndNil(FThreadPool);
  inherited;
end;

function TIdThreadMgrPool.GetThread: TIdThread;
var
  i: integer;
begin
  Lock.Enter;
  try
    i := FThreadPool.Count - 1;
    while (i > 0) and not (TIdThread(FThreadPool[i]).Suspended and
      TIdThread(FThreadPool[i]).Stopped) do
    begin
      if TIdThread(FThreadPool[i]).Terminated then
      begin
        TIdThread(FThreadPool[i]).Free;
        FThreadPool.Delete(i);
      end;
      Dec(i);
    end;
    if i >= 0 then
    begin
      Result := FThreadPool[i];
      FThreadPool.Delete(i);
    end
    else
    begin
      Result := CreateNewThread;
      Result.StopMode := smSuspend;
    end;
    ActiveThreads.Add(Result);
  finally
    Lock.Leave;
  end;
end;

procedure TIdThreadMgrPool.ReleaseThread(AThread: TIdThread);
begin
  Lock.Enter;
  try
    ActiveThreads.Remove(AThread);
    if (FThreadPool.Count >= PoolSize) or AThread.Terminated then
    begin
      if IsCurrentThread(AThread) then
      begin
        AThread.FreeOnTerminate := True;
        AThread.Terminate;
      end
      else
      begin
        AThread.TerminateAndWaitFor;
        AThread.Free;
      end;
    end
    else
    begin
      AThread.Stop;
      FThreadPool.Add(AThread);
    end;
  finally Lock.Leave;
  end;
end;

end.
