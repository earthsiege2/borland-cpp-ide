
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       Web server application components               }
{                                                       }
{       Copyright (c) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

{$DENYPACKAGEUNIT}

unit WebBroker;

interface

uses SyncObjs, SysUtils, Classes, Masks, Forms, HTTPApp, Contnrs;

type
  TWebApplication = class(TComponent)
  private
    FWebModuleClass: TComponentClass;
    FCriticalSection: TCriticalSection;
    FActiveWebModules: TList;
    FInactiveWebModules: TList;
    FTitle: string;
    FMaxConnections: Integer;
    FCacheConnections: Boolean;
    function GetActiveCount: Integer;
    function GetInactiveCount: Integer;
    procedure SetCacheConnections(Value: Boolean);
    procedure OnExceptionHandler(Sender: TObject; E: Exception);
  protected
    function ActivateWebModule: TDataModule;
    procedure DeactivateWebModule(DataModule: TDataModule);
    procedure DoHandleException(E: Exception); dynamic;
    function HandleRequest(Request: TWebRequest; Response: TWebResponse): Boolean;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    // The following is uses the current behaviour of the IDE module manager
    procedure CreateForm(InstanceClass: TComponentClass; var Reference); virtual;
    procedure Initialize; virtual;
    procedure Run; virtual;
    property ActiveCount: Integer read GetActiveCount;
    property CacheConnections: Boolean read FCacheConnections write SetCacheConnections;
    property InactiveCount: Integer read GetInactiveCount;
    property MaxConnections: Integer read FMaxConnections write FMaxConnections;
    property Title: string read FTitle write FTitle;
  end;

var
  Application: TWebApplication = nil;

implementation

uses BrkrConst, Windows;

{ TWebApplication }

procedure DoneVCLApplication;
begin
  with Forms.Application do
  begin
    if Handle <> 0 then ShowOwnedPopups(Handle, False);
    ShowHint := False;
    Destroying;
    DestroyComponents;
  end;
  with Application do
  begin
    Destroying;
    DestroyComponents;
  end;
end;

procedure DLLExitProc(Reason: Integer); register;
begin
  if Reason = DLL_PROCESS_DETACH then DoneVCLApplication;
end;

constructor TWebApplication.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FCriticalSection := TCriticalSection.Create;
  FActiveWebModules := TList.Create;
  FInactiveWebModules := TList.Create;
  FMaxConnections := 32;
  FCacheConnections := True;
  if IsLibrary then
  begin
    IsMultiThread := True;
    DLLProc := @DLLExitProc;
  end;
end;

destructor TWebApplication.Destroy;
begin
  Forms.Application.OnException := nil;
  FCriticalSection.Free;
  FActiveWebModules.Free;
  FInactiveWebModules.Free;
  inherited Destroy;
end;

procedure TWebApplication.CreateForm(InstanceClass: TComponentClass;
  var Reference);
begin
  if FWebModuleClass = nil then
    FWebModuleClass := InstanceClass
  else raise Exception.CreateRes(@sOnlyOneDataModuleAllowed);
end;

function TWebApplication.ActivateWebModule: TDataModule;
begin
  FCriticalSection.Enter;
  try
    Result := nil;
    if (FMaxConnections > 0) and (FActiveWebModules.Count >= FMaxConnections) then
      raise Exception.CreateRes(@sTooManyActiveConnections);
    if FInactiveWebModules.Count > 0 then
    begin
      Result := FInactiveWebModules[0];
      FInactiveWebModules.Delete(0);
      FActiveWebModules.Add(Result);
    end else if FWebModuleClass <> nil then
    begin
      TComponent(Result) := FWebModuleClass.Create(Self);
      FActiveWebModules.Add(Result);
    end else raise Exception.CreateRes(@sNoDataModulesRegistered);
  finally
    FCriticalSection.Leave;
  end;
end;

procedure TWebApplication.DeactivateWebModule(DataModule: TDataModule);
begin
  FCriticalSection.Enter;
  try
    FActiveWebModules.Remove(DataModule);
    if FCacheConnections then
      FInactiveWebModules.Add(DataModule)
    else DataModule.Free;  
  finally
    FCriticalSection.Leave;
  end;
end;

procedure TWebApplication.DoHandleException(E: Exception);
begin
end;

function TWebApplication.GetActiveCount: Integer;
begin
  FCriticalSection.Enter;
  try
    Result := FActiveWebModules.Count;
  finally
    FCriticalSection.Leave;
  end;
end;

function TWebApplication.GetInactiveCount: Integer;
begin
  FCriticalSection.Enter;
  try
    Result := FInactiveWebModules.Count;
  finally
    FCriticalSection.Leave;
  end;
end;

type
  TWebDispatcherAccess = class(TCustomWebDispatcher);

function TWebApplication.HandleRequest(Request: TWebRequest;
  Response: TWebResponse): Boolean;
var
  DataModule: TDataModule;
  Dispatcher: TCustomWebDispatcher;
  I: Integer;
begin
  Result := False;
  DataModule := ActivateWebModule;
  if DataModule <> nil then
  try
    if DataModule is TCustomWebDispatcher then
      Dispatcher := TCustomWebDispatcher(DataModule)
    else with DataModule do
    begin
      Dispatcher := nil;
      for I := 0 to ComponentCount - 1 do
      begin
        if Components[I] is TCustomWebDispatcher then
        begin
          Dispatcher := TCustomWebDispatcher(Components[I]);
          Break;
        end;
      end;
    end;
    if Dispatcher <> nil then
    begin
      Result := TWebDispatcherAccess(Dispatcher).DispatchAction(Request, Response);
      if Result and not Response.Sent then
        Response.SendResponse;
    end else raise Exception.CreateRes(@sNoDispatcherComponent);
  finally
    DeactivateWebModule(DataModule);
  end;
end;

procedure TWebApplication.Initialize;
begin
  // This is a place holder
  if InitProc <> nil then TProcedure(InitProc);
end;

procedure TWebApplication.OnExceptionHandler(Sender: TObject; E: Exception);
begin
  DoHandleException(E);
end;

procedure TWebApplication.SetCacheConnections(Value: Boolean);
var
  I: Integer;
begin
  if Value <> FCacheConnections then
  begin
    FCacheConnections := Value;
    if not Value then
    begin
      FCriticalSection.Enter;
      try
        for I := 0 to FInactiveWebModules.Count - 1 do
          TDataModule(FInactiveWebModules[I]).Free;
        FInactiveWebModules.Clear;  
      finally
        FCriticalSection.Leave;
      end;
    end;
  end;
end;

procedure TWebApplication.Run;
begin
  if not IsLibrary then AddExitProc(DoneVCLApplication);
  Forms.Application.OnException := OnExceptionHandler;
end;

end.
