{********************************************************}
{                                                        }
{       Borland Delphi Visual Component Library          } 
{       InterBase Express EventAlerter components        }
{                                                        }
{       Copyright (c) 1998-1999 Inprise Corporation      }
{                                                        }
{       Adapted from code written by:                    }
{         James Thorpe                                   }
{         CSA Australasia                                }
{         Compuserve: 100035,2064                        }
{         Internet:   csa@csaa.com.au                    }
{                                                        }
{********************************************************}

unit IBEvents;

interface

uses
  SysUtils, Windows, Messages, Classes, Graphics, Controls,
  Forms, Dialogs, DB, IBHeader, IBExternals, IB, IBDatabase;

const
  MaxEvents = 15;
  EventLength = 64;

type

  TEventAlert = procedure( Sender: TObject; EventName: string; EventCount: longint;
                           var CancelAlerts: Boolean) of object;

  TEventBuffer = array[ 0..MaxEvents-1, 0..EventLength-1] of char;

  TIBEvents = class(TComponent)
  private
    FIBLoaded: Boolean;
    FEvents: TStrings;
    FOnEventAlert: TEventAlert;
    FQueued: Boolean;
    FRegistered: Boolean;
    Buffer: TEventBuffer;
    Changing: Boolean;
    CS: TRTLCriticalSection;
    EventBuffer: PChar;
    EventBufferLen: integer;
    EventID: ISC_LONG;
    ProcessingEvents: Boolean;
    RegisteredState: Boolean;
    ResultBuffer: PChar;
    FDatabase: TIBDatabase;
    procedure SetDatabase( value: TIBDatabase);
    procedure ValidateDatabase( Database: TIBDatabase);
    procedure DoQueueEvents;
    procedure EventChange( sender: TObject);
    procedure UpdateResultBuffer( length: short; updated: PChar);
  protected
    procedure HandleEvent;
    procedure Loaded; override;
    procedure Notification( AComponent: TComponent; Operation: TOperation); override;
    procedure SetEvents( value: TStrings);
    procedure SetRegistered( value: boolean);
    function  GetNativeHandle: TISC_DB_HANDLE;

  public
    constructor Create( AOwner: TComponent); override;
    destructor Destroy; override;
    procedure CancelEvents;
    procedure QueueEvents;
    procedure RegisterEvents;
    procedure UnRegisterEvents;
    property  Queued: Boolean read FQueued;
  published
    property  Database: TIBDatabase read FDatabase write SetDatabase;
    property Events: TStrings read FEvents write SetEvents;
    property Registered: Boolean read FRegistered write SetRegistered;
    property OnEventAlert: TEventAlert read FOnEventAlert write FOnEventAlert;
  end;

implementation

uses
  IBIntf;

function TIBEvents.GetNativeHandle: TISC_DB_HANDLE;
begin
  if assigned( FDatabase) and FDatabase.Connected then
    Result := FDatabase.Handle
  else result := nil;
end;

procedure TIBEvents.ValidateDatabase( Database: TIBDatabase);
begin
  if not assigned( Database) then
    IBError(ibxeDatabaseNameMissing, [nil]);
  if not Database.Connected then
    IBError(ibxeDatabaseOpen, [nil]);
end;

{ TIBEvents }

procedure HandleEvent( param: integer); stdcall;
begin
  { don't let exceptions propogate out of thread }
  try
    TIBEvents( param).HandleEvent;
  except
    Application.HandleException( nil);
  end;
end;

procedure IBEventCallback( ptr: pointer; length: short; updated: PChar); cdecl;
var
  ThreadID: DWORD;
begin
  { Handle events asynchronously in second thread }
  EnterCriticalSection( TIBEvents( ptr).CS);
  TIBEvents( ptr).UpdateResultBuffer( length, updated);
  if TIBEvents( ptr).Queued then
    CloseHandle( CreateThread( nil, 8192, @HandleEvent, ptr, 0, ThreadID));
  LeaveCriticalSection( TIBEvents( ptr).CS);
end;

constructor TIBEvents.Create( AOwner: TComponent);
begin
  inherited Create( AOwner);
  FIBLoaded := False;
  CheckIBLoaded;
  FIBLoaded := True;
  InitializeCriticalSection( CS);
  FEvents := TStringList.Create;
  with TStringList( FEvents) do
  begin
    OnChange := EventChange;
    Duplicates := dupIgnore;
  end;
end;

destructor TIBEvents.Destroy;
begin
  if FIBLoaded then
  begin
    UnregisterEvents;
    SetDatabase( nil);
    TStringList(FEvents).OnChange := nil;
    FEvents.Free;
    DeleteCriticalSection( CS);
  end;
  inherited Destroy;
end;

procedure TIBEvents.CancelEvents;
begin
  if ProcessingEvents then
    IBError(ibxeInvalidCancellation, [nil]);  
  if FQueued then
  begin
    try
      { wait for event handler to finish before cancelling events }
      EnterCriticalSection( CS);
      ValidateDatabase( Database);
      FQueued := false;
      Changing := true;
      if (isc_Cancel_events( StatusVector, @FDatabase.Handle, @EventID) > 0) then
        IBDatabaseError;
    finally
      LeaveCriticalSection( CS);
    end;
  end;
end;

procedure TIBEvents.DoQueueEvents;
var
  callback: pointer;
begin
  ValidateDatabase( DataBase);
  callback := @IBEventCallback;
  if (isc_que_events( StatusVector, @FDatabase.Handle, @EventID, EventBufferLen,
                     EventBuffer, TISC_CALLBACK(callback), PVoid(Self)) > 0) then
    IBDatabaseError;
  FQueued := true;
end;

procedure TIBEvents.EventChange( sender: TObject);
begin
  { check for blank event }
  if TStringList(Events).IndexOf( '') <> -1 then
    IBError(ibxeInvalidEvent, [nil]);
  { check for too many events }
  if Events.Count > MaxEvents then
  begin
    TStringList(Events).OnChange := nil;
    Events.Delete( MaxEvents);
    TStringList(Events).OnChange := EventChange;
    IBError(ibxeMaximumEvents, [nil]);
  end;
  if Registered then RegisterEvents;
end;

procedure TIBEvents.HandleEvent;
var
  Status: PStatusVector;
  CancelAlerts: Boolean;
  i: integer;
begin
  try
    { prevent modification of vital data structures while handling events }
    EnterCriticalSection( CS);
    ProcessingEvents := true;
    isc_event_counts( StatusVector, EventBufferLen, EventBuffer, ResultBuffer);
    CancelAlerts := false;
    if assigned(FOnEventAlert) and not Changing then
    begin
      for i := 0 to Events.Count-1 do
      begin
        try
        Status := StatusVectorArray;
        if (Status[i] <> 0) and not CancelAlerts then
            FOnEventAlert( self, Events[Events.Count-i-1], Status[i], CancelAlerts);
        except
          Application.HandleException( nil);
        end;
      end;
    end;
    Changing := false;
    if not CancelAlerts and FQueued then DoQueueEvents;
  finally
    ProcessingEvents := false;
    LeaveCriticalSection( CS);
  end;
end;

procedure TIBEvents.Loaded;
begin
  inherited Loaded;
  try
    if RegisteredState then RegisterEvents;
  except
    if csDesigning in ComponentState then
      Application.HandleException( self)
    else raise;
  end;
end;

procedure TIBEvents.Notification( AComponent: TComponent;
                                        Operation: TOperation);
begin
  inherited Notification( AComponent, Operation);
  if (Operation = opRemove) and (AComponent = FDatabase) then
  begin
    UnregisterEvents;
    FDatabase := nil;
  end;
end;

procedure TIBEvents.QueueEvents;
begin
  if not FRegistered then
    IBError(ibxeNoEventsRegistered, [nil]);
  if ProcessingEvents then
    IBError(ibxeInvalidQueueing, [nil]);
  if not FQueued then
  begin
    try
      { wait until current event handler is finished before queuing events }
      EnterCriticalSection( CS);
      DoQueueEvents;
      Changing := true;
    finally
      LeaveCriticalSection( CS);
    end;
  end;
end;

procedure TIBEvents.RegisterEvents;
var
  i: integer;
  bufptr: pointer;
  eventbufptr: pointer;
  resultbufptr: pointer;
  buflen: integer;
begin
  ValidateDatabase( Database);
  if csDesigning in ComponentState then FRegistered := true
  else begin
    UnregisterEvents;
    if Events.Count = 0 then exit;
    for i := 0 to Events.Count-1 do
      StrPCopy( @Buffer[i][0], Events[i]);
    i := Events.Count;
    bufptr := @buffer[0];
    eventbufptr :=  @EventBuffer;
    resultBufPtr := @ResultBuffer;
    asm
      mov ecx, dword ptr [i]
      mov eax, dword ptr [bufptr]
      @@1:
      push eax
      add  eax, EventLength
      loop @@1
      push dword ptr [i]
      push dword ptr [resultBufPtr]
      push dword ptr [eventBufPtr]
      call [isc_event_block]
      mov  dword ptr [bufLen], eax
      mov eax, dword ptr [i]
      shl eax, 2
      add eax, 12
      add esp, eax
    end;
    EventBufferlen := Buflen;
    FRegistered := true;
    QueueEvents;
  end;
end;

procedure TIBEvents.SetEvents( value: TStrings);
begin
  FEvents.Assign( value);
end;

procedure TIBEvents.SetDatabase( value: TIBDatabase);
begin
  if value <> FDatabase then
  begin
    UnregisterEvents;
    if assigned( value) and value.Connected then ValidateDatabase( value);
    FDatabase := value;
  end;
end;

procedure TIBEvents.SetRegistered( value: Boolean);
begin
  if (csReading in ComponentState) then
    RegisteredState := value
  else if FRegistered <> value then
    if value then RegisterEvents else UnregisterEvents;
end;

procedure TIBEvents.UnregisterEvents;
begin
  if ProcessingEvents then
    IBError(ibxeInvalidRegistration, [nil]);
  if csDesigning in ComponentState then
    FRegistered := false
  else if not (csLoading in ComponentState) then
  begin
    CancelEvents;
    if FRegistered then
    begin
      isc_free( EventBuffer);
      EventBuffer := nil;
      isc_free( ResultBuffer);
      ResultBuffer := nil;
    end;
    FRegistered := false;
  end;
end;

procedure TIBEvents.UpdateResultBuffer( length: short; updated: PChar);
var
  i: integer;
begin
  for i := 0 to length-1 do
    ResultBuffer[i] := updated[i];
end;

end.
