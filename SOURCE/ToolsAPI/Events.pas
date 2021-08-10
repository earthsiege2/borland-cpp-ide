unit Events;

interface

uses Classes;

type
  PHandler = ^THandler;
  THandler = record
    Handler: TNotifyEvent;
  end;

  TEvent = class
  protected
    List: TList;
  public
    constructor Create;
    destructor Destroy; override;
    procedure Add(AHandler: TNotifyEvent);
    function IndexOf(AHandler: TNotifyEvent): Integer;
    procedure Remove(AHandler: TNotifyEvent);
    procedure Send(Sender: TObject);
  end;

implementation

constructor TEvent.Create;
begin
  inherited Create;
  List := TList.Create;
end;

destructor TEvent.Destroy;
var
  I: Integer;
begin
  for I := 0 to List.Count - 1 do
    Dispose(PHandler(List[I]));
  List.Free;
  inherited Destroy;
end;

procedure TEvent.Add(AHandler: TNotifyEvent);
var
  P: PHandler;
begin
  if IndexOf(AHandler) < 0 then
  begin
    New(P);
    P^.Handler := AHandler;
    List.Add(P);
  end;
end;

function TEvent.IndexOf(AHandler: TNotifyEvent): Integer;
type
  TMethodRec = record
    Code, Data: Pointer;
  end;
var
  I: Integer;
  Handler: TNotifyEvent;
begin
  for I := 0 to List.Count - 1 do
  begin
    Handler := PHandler(List[I])^.Handler;
    if (TMethodRec(AHandler).Code = TMethodRec(Handler).Code) and
      (TMethodRec(AHandler).Data = TMethodRec(Handler).Data) then
    begin
      Result := I;
      Exit;
    end;
  end;
  Result := -1;
end;

procedure TEvent.Remove(AHandler: TNotifyEvent);
var
  Index: Integer;
begin
  Index := IndexOf(AHandler);
  if Index > -1 then
  begin
    Dispose(PHandler(List[Index]));
    List.Delete(Index);
  end;
end;

procedure TEvent.Send(Sender: TObject);
var
  I: Integer;
begin
  for I := List.Count - 1 downto 0 do
    PHandler(List[I])^.Handler(Sender);
end;

end.
