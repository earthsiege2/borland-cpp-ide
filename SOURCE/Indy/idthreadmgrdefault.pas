unit IdThreadMgrDefault;

interface

uses
  IdThread, IdThreadMgr;

type
  TIdThreadMgrDefault = class(TIdThreadMgr)
  public
    function GetThread: TIdThread; override;
    procedure ReleaseThread(AThread: TIdThread); override;
  end;

implementation

uses
  IdGlobal;

function TIdThreadMgrDefault.GetThread: TIdThread;
begin
  result := CreateNewThread;
  Lock.Enter;
  try
    ActiveThreads.Add(result);
  finally Lock.Leave;
  end;
end;

procedure TIdThreadMgrDefault.ReleaseThread(AThread: TIdThread);
begin
  if not IsCurrentThread(AThread) then
  begin
    AThread.TerminateAndWaitFor;
    AThread.Free;
  end
  else
  begin
    AThread.FreeOnTerminate := True;
  end;
  Lock.Enter;
  try
    ActiveThreads.Remove(AThread);
  finally Lock.Leave;
  end;
end;

end.
