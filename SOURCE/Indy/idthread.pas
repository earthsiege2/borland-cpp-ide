unit IdThread;

interface

uses
  Classes, SysUtils;

type
  TIdThreadStopMode = (smTerminate, smSuspend);
  TIdExceptionEvent = procedure(Sender: TObject; E: Exception) of object;

  TIdThread = class(TThread)
  protected
    FData: TObject;
    FStopMode: TIdThreadStopMode;
    FStopped: Boolean;
    FTerminatingException: string;
    FOnException: TIdExceptionEvent;
    function GetStopped: Boolean;

    procedure Execute; override;
    procedure Run; virtual; abstract;
    procedure AfterRun; virtual;
    procedure BeforeRun; virtual;
  public
    constructor Create(ACreateSuspended: Boolean = True); virtual;
    destructor Destroy; override;
    procedure Start;
    procedure Stop;
    procedure Synchronize(Method: TThreadMethod);
    procedure TerminateAndWaitFor; virtual;
    property TerminatingException: string read FTerminatingException;

    property Data: TObject read FData write FData;
    property StopMode: TIdThreadStopMode read FStopMode write FStopMode;
    property Stopped: Boolean read GetStopped;
    property OnException: TIdExceptionEvent read FOnException write
      FOnException;

    property Terminated;
  end;

  TIdThreadClass = class of TIdThread;

implementation

uses
  IdGlobal;

procedure TIdThread.TerminateAndWaitFor;
begin
  Terminate;
  FStopped := True;
  WaitFor;
end;

procedure TIdThread.AfterRun;
begin
end;

procedure TIdThread.BeforeRun;
begin
end;

procedure TIdThread.Execute;
begin
  try
    while not Terminated do
    try
      if Stopped then
      begin
        Suspended := True;
        if Terminated then
        begin
          Break;
        end;
      end;
      BeforeRun;
      while not Stopped do
      begin
        Run;
      end;
    finally
      AfterRun;
    end;
  except
    on E: exception do
    begin
      FTerminatingException := E.Message;
      if Assigned(FOnException) then
        FOnException(self, E);
      Terminate;
    end;
  end;
end;

procedure TIdThread.Synchronize(Method: TThreadMethod);
begin
  inherited Synchronize(Method);
end;

constructor TIdThread.Create(ACreateSuspended: Boolean);
begin
  inherited;
  FStopped := ACreateSuspended;
end;

destructor TIdThread.Destroy;
begin
  FreeAndNil(FData);
  inherited;
end;

procedure TIdThread.Start;
begin
  if Stopped then
  begin
    FStopped := False;
    Suspended := False;
  end;
end;

procedure TIdThread.Stop;
begin
  if not Stopped then
  begin
    case FStopMode of
      smTerminate: Terminate;
      smSuspend: ;
    end;
    FStopped := True;
  end;
end;

function TIdThread.GetStopped: Boolean;
begin
  Result := Terminated or FStopped;
end;

end.
