
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       Win32 Synchronization objects                   }
{                                                       }
{       Copyright (c) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit SyncObjs;

{$H+,X+}

interface

uses Sysutils, Windows, Messages, Classes;

type
  TSynchroObject = class(TObject)
  public
    procedure Acquire; virtual;
    procedure Release; virtual;
  end;

  THandleObject = class(TSynchroObject)
  private
    FHandle: THandle;
    FLastError: Integer;
  public
    destructor Destroy; override;
    property LastError: Integer read FLastError;
    property Handle: THandle read FHandle;
  end;

  TWaitResult = (wrSignaled, wrTimeout, wrAbandoned, wrError);

  TEvent = class(THandleObject)
  public
    constructor Create(EventAttributes: PSecurityAttributes; ManualReset,
      InitialState: Boolean; const Name: string);
    function WaitFor(Timeout: DWORD): TWaitResult;
    procedure SetEvent;
    procedure ResetEvent;
  end;

  TSimpleEvent = class(TEvent)
  public
    constructor Create;
  end;

  TCriticalSection = class(TSynchroObject)
  private
    FSection: TRTLCriticalSection;
  public
    constructor Create;
    destructor Destroy; override;
    procedure Acquire; override;
    procedure Release; override;
    procedure Enter;
    procedure Leave;
  end;

implementation

{ TSynchroObject }

procedure TSynchroObject.Acquire;
begin
end;

procedure TSynchroObject.Release;
begin
end;

{ THandleObject }

destructor THandleObject.Destroy;
begin
  CloseHandle(FHandle);
  inherited Destroy;
end;

{ TEvent }

constructor TEvent.Create(EventAttributes: PSecurityAttributes; ManualReset,
  InitialState: Boolean; const Name: string);
begin
  FHandle := CreateEvent(EventAttributes, ManualReset, InitialState, PChar(Name));
end;

function TEvent.WaitFor(Timeout: DWORD): TWaitResult;
begin
  case WaitForSingleObject(Handle, Timeout) of
    WAIT_ABANDONED: Result := wrAbandoned;
    WAIT_OBJECT_0: Result := wrSignaled;
    WAIT_TIMEOUT: Result := wrTimeout;
    WAIT_FAILED:
      begin
        Result := wrError;
        FLastError := GetLastError;
      end;
  else
    Result := wrError;    
  end;
end;

procedure TEvent.SetEvent;
begin
  Windows.SetEvent(Handle);
end;

procedure TEvent.ResetEvent;
begin
  Windows.ResetEvent(Handle);
end;

{ TSimpleEvent }

constructor TSimpleEvent.Create;
begin
  FHandle := CreateEvent(nil, True, False, nil);
end;

{ TCriticalSection }

constructor TCriticalSection.Create;
begin
  inherited Create;
  InitializeCriticalSection(FSection);
end;

destructor TCriticalSection.Destroy;
begin
  DeleteCriticalSection(FSection);
  inherited Destroy;
end;

procedure TCriticalSection.Acquire;
begin
  EnterCriticalSection(FSection);
end;

procedure TCriticalSection.Release;
begin
  LeaveCriticalSection(FSection);
end;

procedure TCriticalSection.Enter;
begin
  Acquire;
end;

procedure TCriticalSection.Leave;
begin
  Release;
end;

end.
