{ *************************************************************************** }
{                                                                             }
{ Kylix and Delphi Cross-Platform Visual Component Library                    }
{ Internet Application Runtime                                                }
{                                                                             }
{ Copyright (C) 1997, 2001 Borland Software Corporation                       }
{                                                                             }
{ Licensees holding a valid Borland No-Nonsense License for this Software may }
{ use this file in accordance with such license, which appears in the file    }
{ license.txt that came with this Software.                                   }
{                                                                             }
{ *************************************************************************** }


{ Need denypackage unit because of threadvar }
{$DENYPACKAGEUNIT}

unit WebReq;

interface

uses SyncObjs, SysUtils, Classes, HTTPApp, Contnrs, WebCntxt;

type
  TRequestNotification = (rnActivateModule, rnDeactivateModule, rnCreateModule, rnFreeModule,
    rnStartRequest, rnFinishRequest);

  TWebModuleList = class;

  TWebModuleFactoryList = class(TObject)
  private
    FAppModuleFactory: TAbstractWebModuleFactory;
    FList: TObjectList;
    function GetItemCount: Integer;
  protected
    function GetItem(I: Integer): TAbstractWebModuleFactory;
  public
    constructor Create;
    destructor Destroy; override;
    procedure AddFactory(AFactory: TAbstractWebModuleFactory);
    property AppModuleFactory: TAbstractWebModuleFactory read FAppModuleFactory;
    property Items[I: Integer]: TAbstractWebModuleFactory read GetItem;
    property ItemCount: Integer read GetItemCount;
  end;

  TWebRequestHandler = class(TComponent)
  private
    FCriticalSection: TCriticalSection;
    FActiveWebModules: TList;
    FAddingActiveModules: Integer;
    FInactiveWebModules: TList;
    FMaxConnections: Integer;
    FCacheConnections: Boolean;
    FWebModuleFactories: TWebModuleFactoryList;
    FWebModuleClass: TComponentClass;

    FRequestNotifies: TComponentList;
    function GetActiveCount: Integer;
    function GetInactiveCount: Integer;
    procedure SetCacheConnections(Value: Boolean);
    function GetWebModuleFactory(I: Integer): TAbstractWebModuleFactory;
    function GetWebModuleFactoryCount: Integer;
  protected
    function ActivateWebModules: TWebModuleList;
    procedure DeactivateWebModules(WebModules: TWebModuleList);
    function HandleRequest(Request: TWebRequest; Response: TWebResponse): Boolean;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure HandleException(Sender: TObject);
    property WebModuleClass: TComponentClass read FWebModuleClass write FWebModuleClass;
    procedure AddWebModuleFactory(AFactory: TAbstractWebModuleFactory);
    property ActiveCount: Integer read GetActiveCount;
    property CacheConnections: Boolean read FCacheConnections write SetCacheConnections;
    property InactiveCount: Integer read GetInactiveCount;
    property MaxConnections: Integer read FMaxConnections write FMaxConnections;
    property WebModuleFactoryCount: Integer read GetWebModuleFactoryCount;
    property WebModuleFactory[I: Integer]: TAbstractWebModuleFactory read GetWebModuleFactory;
  end;

  TWebModuleList = class(TAbstractWebModuleList)
  private
    FFactories: TWebModuleFactoryList;
    FList: TComponentList;
    FFixupLevel: Integer;
    FSaveIsUniqueGlobalComponentName: TIsUniqueGlobalComponentName;
    FUnresolvedNames: TStrings;
    FModuleAddedProc: TModuleAddedProc;
    procedure EndFixup;
    procedure StartFixup;
    procedure RecordUnresolvedName(const AName: string);
    procedure PromoteFactoryClass(const AName: string);
  protected
    function GetItem(I: Integer): TComponent; override;
    function GetItemCount: Integer; override;
    function GetOnModuleAdded: TModuleAddedProc; override;
    function GetFactoryCount: Integer; override;
    function GetFactory(I: Integer): TAbstractWebModuleFactory; override;
    procedure SetOnModuleAdded(AProc: TModuleAddedProc); override;
    property Factories: TWebModuleFactoryList read FFactories;
  public
    constructor Create(const AFactories: TWebModuleFactoryList);
    destructor Destroy; override;
    function FindModuleClass(AClass: TComponentClass): TComponent; override;
    function FindModuleName(const AName: string): TComponent; override;
    function AddModuleClass(AClass: TComponentClass): TComponent; override;
    function AddModuleName(const AName: string): TComponent; override;
    procedure AddModule(AComponent: TComponent);
    procedure AutoCreateModules;
    procedure AutoDestroyModules;
  end;

  function WebRequestHandler: TWebRequestHandler;

var
  WebRequestHandlerProc: function: TWebRequestHandler = nil;

implementation

{$IFDEF MSWINDOWS}
uses Windows, BrkrConst, WebConst;
{$ENDIF}
{$IFDEF LINUX}
uses BrkrConst, WebComp, WebConst;
{$ENDIF}

threadvar WebContext: TAbstractWebContext;

type

  TDefaultWebModuleFactory = class(TAbstractWebModuleFactory)
  private
    FComponentClass: TComponentClass;
  protected
    procedure PreventDestruction; override;
    function GetModuleName: string; override;
    function GetIsAppModule: Boolean; override;
    function GetCreateMode: TWebModuleCreateMode; override;
    function GetCacheMode: TWebModuleCacheMode; override;
    function GetComponentClass: TComponentClass; override;
  public
    constructor Create(AComponentClass: TComponentClass);
    function GetModule: TComponent; override;
  end;

{ TDefaultWebModuleFactory }

constructor TDefaultWebModuleFactory.Create(AComponentClass: TComponentClass);
begin
  inherited Create;
  FComponentClass := AComponentClass;
end;

function TDefaultWebModuleFactory.GetCacheMode: TWebModuleCacheMode;
begin
  Result := caCache;
end;

function TDefaultWebModuleFactory.GetComponentClass: TComponentClass;
begin
  Result := FComponentClass;
end;

function TDefaultWebModuleFactory.GetCreateMode: TWebModuleCreateMode;
begin
  Result := crAlways
end;

function TDefaultWebModuleFactory.GetIsAppModule: Boolean;
begin
  Result := True;
end;

function TDefaultWebModuleFactory.GetModule: TComponent;
begin
  Result := FComponentClass.Create(nil);
end;

function TDefaultWebModuleFactory.GetModuleName: string;
begin
  Result := Copy(FComponentClass.ClassName, 2, MaxInt);
end;

function GetWebContext: TAbstractWebContext;
begin
  Result := WebContext;
end;

procedure SetWebContext(AWebContext: TAbstractWebContext);
begin
  WebContext := AWebContext;
end;

function WebRequestHandler: TWebRequestHandler;
begin
  if Assigned(WebRequestHandlerProc) then
    Result := WebRequestHandlerProc
  else
    Result := nil;
end;

procedure TDefaultWebModuleFactory.PreventDestruction;
begin
  // Do nothing.  Cache mode is always caCache
end;

{ TWebRequestHandler }

constructor TWebRequestHandler.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FCriticalSection := TCriticalSection.Create;
  FActiveWebModules := TList.Create;
  FInactiveWebModules := TList.Create;
  FWebModuleFactories := TWebModuleFactoryList.Create;
  FMaxConnections := 32;
  FCacheConnections := True;
end;

destructor TWebRequestHandler.Destroy;
var
  I: Integer;
begin
  FCriticalSection.Free;
  for I := 0 to FActiveWebModules.Count - 1 do
    TObject(FActiveWebModules[I]).Free;
  FActiveWebModules.Free;
  for I := 0 to FInactiveWebModules.Count - 1 do
    TObject(FInactiveWebModules[I]).Free;
  FInactiveWebModules.Free;
  FRequestNotifies.Free;
  FWebModuleFactories.Free;
  inherited Destroy;
end;

  threadvar AvailableWebModules: TWebModuleList;

function FindWebModuleComponent(const Name: string): TComponent;
begin
  if AvailableWebModules <> nil then
  begin
    // Global components references are supported by SiteExpress
    Result := AvailableWebModules.FindModuleName(Name);
    if Result = nil then
      AvailableWebModules.RecordUnresolvedName(Name);
  end
  else
    // Global component references are not supported by standard WebBroker 
    Result := nil;
end;

function IsUniqueGlobalWebComponentName(const Name: string): Boolean;
begin
  // Prevent rename of data modules
  Result := True;
end;

function TWebRequestHandler.ActivateWebModules: TWebModuleList;
begin
  if (FMaxConnections > 0) and (FAddingActiveModules >= FMaxConnections) then
    raise Exception.CreateRes(@sTooManyActiveConnections);

  FCriticalSection.Enter;
  try
    FAddingActiveModules := FActiveWebModules.Count + 1;
    try
      Result := nil;
      if (FMaxConnections > 0) and (FActiveWebModules.Count >= FMaxConnections) then
        raise Exception.CreateRes(@sTooManyActiveConnections);
      if FInactiveWebModules.Count > 0 then
      begin
        Result := FInactiveWebModules[0];
        Result.OnModuleAdded := nil;
        FInactiveWebModules.Delete(0);
        FActiveWebModules.Add(Result);
      end
      else
      begin
        if FWebModuleFactories.ItemCount = 0 then
          if WebModuleClass <> nil then
            FWebModuleFactories.AddFactory(TDefaultWebModuleFactory.Create(WebModuleClass));
        if FWebModuleFactories.ItemCount > 0 then
        begin
          Result := TWebModuleList.Create(FWebModuleFactories);
          FActiveWebModules.Add(Result);
        end
        else
          raise Exception.CreateRes(@sNoDataModulesRegistered);
      end;
    finally
      FAddingActiveModules := 0;
    end;
  finally
    FCriticalSection.Leave;
  end;
end;

procedure TWebRequestHandler.DeactivateWebModules(WebModules: TWebModuleList);
begin
  FCriticalSection.Enter;
  try
    FActiveWebModules.Remove(WebModules);
    WebModules.AutoDestroyModules;
    if FCacheConnections and (WebModules.GetItemCount > 0) then
      FInactiveWebModules.Add(WebModules)
    else
    begin
      WebModules.Free;
    end;
  finally
    FCriticalSection.Leave;
  end;
end;

function TWebRequestHandler.GetActiveCount: Integer;
begin
  FCriticalSection.Enter;
  try
    Result := FActiveWebModules.Count;
  finally
    FCriticalSection.Leave;
  end;
end;

function TWebRequestHandler.GetInactiveCount: Integer;
begin
  FCriticalSection.Enter;
  try
    Result := FInactiveWebModules.Count;
  finally
    FCriticalSection.Leave;
  end;
end;

function TWebRequestHandler.HandleRequest(Request: TWebRequest;
  Response: TWebResponse): Boolean;
var
  I: Integer;
  WebModules: TWebModuleList;
  WebModule: TComponent;
  WebAppServices: IWebAppServices;
  GetWebAppServices: IGetWebAppServices;
begin
  Result := False;
  WebModules := ActivateWebModules;
  if Assigned(WebModules) then
  try
    WebModules.AutoCreateModules;
    if WebModules.ItemCount = 0 then
      raise Exception.CreateRes(@sNoWebModulesActivated);

    try
      // Look at modules for a web application
      for I := 0 to WebModules.ItemCount - 1 do
      begin
        WebModule := WebModules[I];
        if Supports(IInterface(WebModule), IGetWebAppServices, GetWebAppServices) then
          WebAppServices := GetWebAppServices.GetWebAppServices;
        if WebAppServices <> nil then break;
      end;

      if WebAppServices = nil then
        WebAppServices := TDefaultWebAppServices.Create;

      WebAppServices.InitContext(WebModules, Request, Response);
      try
        try
          Result := WebAppServices.HandleRequest;
        except
          ApplicationHandleException(WebAppServices.ExceptionHandler);
        end;
      finally
        WebAppServices.FinishContext;
      end;
      if Result and not Response.Sent then
        Response.SendResponse;
    except
      ApplicationHandleException(nil);
    end;
  finally
    DeactivateWebModules(WebModules);
  end;
end;

procedure TWebRequestHandler.SetCacheConnections(Value: Boolean);
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
          TObject(FInactiveWebModules[I]).Free;
        FInactiveWebModules.Clear;
      finally
        FCriticalSection.Leave;
      end;
    end;
  end;
end;

procedure TWebRequestHandler.AddWebModuleFactory(
  AFactory: TAbstractWebModuleFactory);
begin
  if Assigned(FWebModuleFactories) then
    FWebModuleFactories.AddFactory(AFactory);
end;

function TWebRequestHandler.GetWebModuleFactory(
  I: Integer): TAbstractWebModuleFactory;
begin
  if Assigned(FWebModuleFactories) then
    Result := FWebModuleFactories.Items[I]
  else
    Result := nil;
end;

function TWebRequestHandler.GetWebModuleFactoryCount: Integer;
begin
  if Assigned(FWebModuleFactories) then
    Result := FWebModuleFactories.ItemCount
  else
    Result := 0;
end;

procedure TWebRequestHandler.HandleException(Sender: TObject);
var
  Handled: Boolean;
  Intf: IWebExceptionHandler;
begin
  Handled := False;
  if ExceptObject is Exception and
    Supports(Sender, IWebExceptionHandler, Intf) then
    try
      Intf.HandleException(Exception(ExceptObject), Handled);
    except
      Handled := True;
      SysUtils.ShowException(ExceptObject, ExceptAddr);
    end;
  if (not Handled) then
    SysUtils.ShowException(ExceptObject, ExceptAddr);
end;

{ TWebModuleList }

constructor TWebModuleList.Create(const AFactories: TWebModuleFactoryList);
begin
  inherited Create;
  FUnresolvedNames := TStringList.Create;
  FList := TComponentList.Create;
  FFactories := AFactories;
end;

destructor TWebModuleList.Destroy;
begin
  inherited;
  FList.Free;
  FUnresolvedNames.Free;
end;

function TWebModuleList.GetItem(I: Integer): TComponent;
begin
  Result := FList[I];
end;

function TWebModuleList.GetItemCount: Integer;
begin
  Result := FList.Count;
end;

function TWebModuleList.AddModuleClass(
  AClass: TComponentClass): TComponent;
var
  I: Integer;
  Factory: TAbstractWebModuleFactory;
begin
  Result := nil;
  Assert(FindModuleClass(AClass) = nil);
  for I := 0 to Factories.ItemCount - 1 do
  begin
    Factory := Factories.Items[I];
    if AClass = Factory.ComponentClass then
    begin
      StartFixup;
      try
        Result := Factory.GetModule;
        AddModule(Result);
      finally
        EndFixup;
      end;
    end;
  end;
end;

function TWebModuleList.AddModuleName(const AName: string): TComponent;
var
  I: Integer;
  Factory: TAbstractWebModuleFactory;
begin
  Result := nil;
  Assert(FindModuleName(AName) = nil);
  for I := 0 to Factories.ItemCount - 1 do
  begin
    Factory := Factories.Items[I];
    if CompareText(AName, Factory.ModuleName) = 0 then
    begin
      StartFixup;
      try
        Result := Factory.GetModule;
        AddModule(Result);
        break;
      finally
        EndFixup;
      end;
    end;
  end;
end;

function TWebModuleList.FindModuleClass(
  AClass: TComponentClass): TComponent;
var
  I: Integer;
begin
  for I := 0 to ItemCount - 1 do
  begin
    Result := Items[I];
    if Result.ClassType = AClass then
      Exit;
  end;
  Result := nil;
end;

function TWebModuleList.FindModuleName(const AName: string): TComponent;
var
  I: Integer;
begin
  for I := 0 to ItemCount - 1 do
  begin
    Result := Items[I];
    if CompareText(Result.Name, AName) = 0 then
      Exit;
  end;
  Result := nil;
end;

procedure TWebModuleList.AddModule(AComponent: TComponent);
begin
  Assert(FFixupLevel >= 1, 'Module created outside of fixup block'); { Do not localize }
  FList.Add(AComponent);
  if Assigned(FModuleAddedProc) then
    FModuleAddedProc(AComponent);
end;

procedure TWebModuleList.StartFixup;
begin
  Inc(FFixupLevel);
  if FFixupLevel = 1 then
  begin
    AvailableWebModules := Self;
    FSaveIsUniqueGlobalComponentName := Classes.IsUniqueGlobalComponentNameProc;
    Classes.RegisterFindGlobalComponentProc(FindWebModuleComponent);
    Classes.IsUniqueGlobalComponentNameProc := IsUniqueGlobalWebComponentName;
  end;
end;

procedure TWebModuleList.EndFixup;
var
  Name: string;
begin
  Dec(FFixupLevel);
  try
    if FFixupLevel = 0 then
      while FUnresolvedNames.Count > 0 do
      begin
        Name := FUnresolvedNames[0];
        FUnresolvedNames.Delete(0);
        if (FindModuleName(Name) <> nil) or (AddModuleName(Name) <> nil) then
        begin
          PromoteFactoryClass(Name);
          GlobalFixupReferences;
        end
      end;
  finally
    if FFixupLevel = 0 then
    begin
      AvailableWebModules := nil;
      //  Once set, the hooks stay in place for this application
      //Classes.UnregisterFindGlobalComponentProc(FindWebModuleComponent);
      //Classes.IsUniqueGlobalComponentNameProc := FSaveIsUniqueGlobalComponentName;
    end;
  end;
end;

procedure TWebModuleList.AutoCreateModules;
var
  I: Integer;
  Factory: TAbstractWebModuleFactory;
begin
  StartFixup;
  try
    for I := 0 to Factories.ItemCount - 1 do
    begin
      Factory := Factories.Items[I];
      if Factory.CreateMode = crAlways then
        if FindModuleClass(Factory.ComponentClass) = nil then
          AddModule(Factory.GetModule);
    end;
  finally
    EndFixup;
  end;
end;

procedure TWebModuleList.AutoDestroyModules;
var
  I: Integer;
  Factory: TAbstractWebModuleFactory;
  Component: TComponent;
begin
  for I := 0 to Factories.ItemCount - 1 do
  begin
    Factory := Factories.Items[I];
    if Factory.CacheMode = caDestroy then
    begin
      Component := FindModuleClass(Factory.ComponentClass);
      if Assigned(Component) then
        Component.Free;
    end;
  end;
end;

procedure TWebModuleList.RecordUnresolvedName(const AName: string);
begin
  if FUnresolvedNames.IndexOf(AName) < 0 then
    FUnresolvedNames.Add(AName);
end;

function TWebModuleList.GetOnModuleAdded: TModuleAddedProc;
begin
  Result := FModuleAddedProc;
end;

procedure TWebModuleList.SetOnModuleAdded(AProc: TModuleAddedProc);
begin
  FModuleAddedProc := AProc;
end;

// Prevent modules referenced by other modules from being destroyed
procedure TWebModuleList.PromoteFactoryClass(const AName: string);
var
  I: Integer;
  Factory: TAbstractWebModuleFactory;
begin
  for I := 0 to Factories.ItemCount - 1 do
  begin
    Factory := Factories.Items[I];
    if CompareText(AName, Factory.ModuleName) = 0 then
    begin
      if Factory.CacheMode = caDestroy then
        Factory.PreventDestruction;
    end;
  end;
end;

function TWebModuleList.GetFactory(I: Integer): TAbstractWebModuleFactory;
begin
  Result := Factories.Items[I];
end;

function TWebModuleList.GetFactoryCount: Integer;
begin
  Result := Factories.ItemCount;
end;

{ TWebModuleFactoryList }

procedure TWebModuleFactoryList.AddFactory(AFactory: TAbstractWebModuleFactory);
begin
  if FList.IndexOf(AFactory) <> -1 then
    raise Exception.Create(sFactoryAlreadyRegistered);
  if AFactory.IsAppModule then
  begin
    if Self.AppModuleFactory <> nil then
      raise Exception.Create(sAppFactoryAlreadyRegistered);
    Self.FAppModuleFactory := AFactory;
  end;
  FList.Add(AFactory);
end;

constructor TWebModuleFactoryList.Create;
begin
  FList := TObjectList.Create;
end;

destructor TWebModuleFactoryList.Destroy;
begin
  inherited;
  FList.Free;

end;

function TWebModuleFactoryList.GetItem(
  I: Integer): TAbstractWebModuleFactory;
begin
  Result := TAbstractWebModuleFactory(FList[I]);
end;

function TWebModuleFactoryList.GetItemCount: Integer;
begin
  Result := FList.Count;
end;

function ImplGetModuleFileName: string;
begin
{$IFDEF MSWINDOWS}
  Result := GetModuleName(hinstance);
{$ENDIF}
{$IFDEF LINUX}
  if IsLibrary then
    Result := GetModuleName(hinstance)
  else
    Result := GetModuleName(Maininstance);
{$ENDIF}
end;

initialization
  if not Assigned(GetWebContextProc) then
    GetWebContextProc := GetWebContext;
  if not Assigned(SetWebContextProc) then
    SetWebContextProc := SetWebContext;
  if not Assigned(GetModuleFileNameProc) then
    GetModuleFileNameProc := ImplGetModuleFileName;
end.
