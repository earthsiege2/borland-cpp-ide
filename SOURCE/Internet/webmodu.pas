{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{   Copyright (c) 2000-2001 Borland Software Corp.      }
{                                                       }
{*******************************************************}

unit WebModu;

interface

uses
  Classes, HTTPApp, HTTPProd, Contnrs, WebComp,
    WebDisp, SiteComp, SysUtils;

type

  TWebNotifyContainer = class;

  TSiteModuleHelper = class(TObject)
  private
    FRequest: TWebRequest;
    FResponse: TWebResponse;
    FSession: TAbstractWebSession;
    FModule: TComponent;
    FOnActivate: TNotifyEvent;
    FOnDeactivate: TNotifyEvent;
    FWebModuleContext: TWebModuleContext;
    FWebNotifyContainer: TWebNotifyContainer;
    FIteratorIndex: Integer;
    FIteratorCount: Integer;
    function GetWebModuleContext: TWebModuleContext;
  protected
    { IWebVariablesContainer }
    function FindVariable(const AName: string): TComponent;
    function FindVariableContainer(const AName: string): TComponent;
    function GetVariableCount: Integer;
    function GetVariable(I: Integer): TComponent;
    function FindNamedVariable(const AName: string): TComponent; virtual;
    { IIterateObjectSupport }
    function StartIterator(var OwnerData: Pointer): Boolean;
    function NextIteration(var OwnerData: Pointer): Boolean;
    procedure EndIterator(OwnerData: Pointer);
    function GetCurrentObject(OwnerData: Pointer): TObject;
    { INotifyWebActivate }
    procedure NotifyActivate;
    procedure NotifyDeactivate;
    property Module: TComponent read FModule;
  public
    constructor Create(AModule: TComponent); virtual;
    destructor Destroy; override;
    procedure Notification(AComponent: TComponent;
      Operation: TOperation);
    property WebModuleContext: TWebModuleContext read GetWebModuleContext;
    property OnActivate: TNotifyEvent read FOnActivate write FOnActivate;
    property OnDeactivate: TNotifyEvent read FOnDeactivate write FOnDeactivate;
    property Request: TWebRequest read FRequest;
    property Response: TWebResponse read FResponse;
    property Session: TAbstractWebSession read FSession;
  end;

  TAdapterActionName = class(TPersistent)
  private
    FModule: TComponent;
    FAdapter: TComponent;
    FActionName: string;
    procedure SetAdapter(const Value: TComponent);
    function GetAction: TComponent;
  protected
    procedure AssignTo(Dest: TPersistent); override;
  public
    property Action: TComponent read GetAction;
  published
    constructor Create(AModule: TComponent);
    property Adapter: TComponent read FAdapter write SetAdapter;
    property ActionName: string read FActionName write FActionName;
  end;

  TGetParamsEvent = procedure(Sender: TObject; Params: TStrings);
  TSitePageModuleHelper = class(TSiteModuleHelper)
  private
    FDefaultAction: TAdapterActionName;
    FDefaultPageFileName: string;
    FOnBeforeDispatchPage: TDispatchPageHandledEvent;
    FOnAfterDispatchPage: TDispatchPageEvent;
    FOnAfterRedirectToPage: TDispatchPageEvent;
    FOnBeforeRedirectToPage: TDispatchPageParamsHandledEvent;
    procedure SetDefaultActionName(const Value: TAdapterActionName);
  protected
    procedure GetRedirectParams(const APageName: string; AParams: TStrings);
    function HTMLFromTemplate(AStream: TStream): string;
    { IWebPageModuleEditorViewSupport }
    function GetProducerComponent: TComponent;
    { IWebPageProducerEditorViewSupport }
    function HasScriptView: Boolean;
    function HasXMLBrowserView: Boolean;
    function HasXSLBrowserView: Boolean;
    function HasHTMLBrowserView: Boolean;
    function GetXMLData(var Owned: Boolean): TStream;
    function GetXSLData(var Owned: Boolean): TStream;
    function GetTemplateFileType: string;
    { IGetDefaultAction }
    function GetDefaultAction: TComponent;
    { IDefaultPageFileName }
    procedure SetDefaultPageFileName(const AValue: string);
    { IPageResult }
    function DispatchPage(const APageName: string; AWebResponse: TWebResponse): Boolean;
    function ImplDispatchPage(const APageName: string; AWebResponse: TWebResponse): Boolean; virtual;
    function IncludePage(const APageName: string; var AOwned: Boolean): TStream;
    function ImplIncludePage(const APageName: string; var AOwned: Boolean): TStream; virtual;
    function RedirectToPage(const APageName: string; AParams: TStrings; AResponse: TWebResponse): Boolean;
    function ImplRedirectToPage(const APageName: string; AParams: TStrings; AResponse: TWebResponse): Boolean; virtual;
    { ISetWebContentOptions }
    procedure SetWebContentOptions(AOptions: TWebContentOptions);
    procedure ImplSetWebContentOptions(AOptions: TWebContentOptions); virtual;
    function GetPageProducer: IProduceContent; virtual;

    function GetTemplateStream(const APage: string; out AOwned: Boolean): TStream;
  public
    constructor Create(AModule: TComponent); override;
    destructor Destroy; override;
    property OnBeforeDispatchPage: TDispatchPageHandledEvent read FOnBeforeDispatchPage write FOnBeforeDispatchPage;
    property OnAfterDispatchPage: TDispatchPageEvent read FOnAfterDispatchPage write FOnAfterDispatchPage;
    property OnBeforeRedirectToPage: TDispatchPageParamsHandledEvent read FOnBeforeRedirectToPage write FOnBeforeRedirectToPage;
    property OnAfterRedirectToPage: TDispatchPageEvent read FOnAfterRedirectToPage write FOnAfterRedirectToPage;
    property DefaultAction: TAdapterActionName read FDefaultAction write SetDefaultActionName;
  end;

  TCustomWebDataModule = class(TDataModule,
    IWebVariablesContainer, INotifyWebActivate,
    IGetScriptObject, IIterateObjectSupport)
  private
    FSiteModuleHelper: TSiteModuleHelper;
    function GetOnActivate: TNotifyEvent;
    function GetOnDeactivate: TNotifyEvent;
    function GetRequest: TWebRequest;
    function GetResponse: TWebResponse;
    function GetSession: TAbstractWebSession;
    procedure SetOnActivate(const Value: TNotifyEvent);
    procedure SetOnDeactivate(const Value: TNotifyEvent);
  protected
    function GetSiteModuleHelper: TSiteModuleHelper; virtual;
    property SiteModuleHelper: TSiteModuleHelper read GetSiteModuleHelper
      implements IWebVariablesContainer,
        INotifyWebActivate, IIterateObjectSupport;
    procedure Notification(AComponent: TComponent;
      Operation: TOperation); override;
    { IGetScriptObject }
    function GetScriptObject: IDispatch;
    function ImplGetScriptObject: IDispatch; virtual;
  public
    { Public declarations }
    constructor Create(AOwner: TComponent); override;
    constructor CreateNew(AOwner: TComponent; Dummy: Integer=0); override;
    destructor Destroy; override;
    property Request: TWebRequest read GetRequest;
    property Response: TWebResponse read GetResponse;
    property Session: TAbstractWebSession read GetSession;
    property OnActivate: TNotifyEvent read GetOnActivate write SetOnActivate;
    property OnDeactivate: TNotifyEvent read GetOnDeactivate write SetOnDeactivate;
  end;

  TWebDataModule = class(TCustomWebDataModule)
  published
    property OnActivate;
    property OnDeactivate;
  end;

  TWebPageModuleHelper = class(TSitePageModuleHelper)
  protected
    function GetPageProducer: IProduceContent; override;
  end;

  TCustomWebPageModule = class(TCustomWebDataModule,
    IDefaultPageFileName,
    IPageResult, ISetWebContentOptions,
    IGetDefaultAction, IGetProducerComponent,
    IProducerEditorViewSupport)
  private
    FPageProducer: IProduceContent;
    FSitePageModuleHelper: TSitePageModuleHelper;
    procedure SetPageProducer(Value: IProduceContent);
    function GetOnAfterDispatchPage: TDispatchPageEvent;
    function GetOnBeforeDispatchPage: TDispatchPageHandledEvent;
    procedure SetOnAfterDispatchPage(const Value: TDispatchPageEvent);
    procedure SetOnBeforeDispatchPage(
      const Value: TDispatchPageHandledEvent);
    function GetOnAfterRedirectToPage: TDispatchPageEvent;
    function GetOnBeforeRedirectToPage: TDispatchPageParamsHandledEvent;
    procedure SetOnAfterRedirectToPage(const Value: TDispatchPageEvent);
    procedure SetOnBeforeRedirectToPage(
      const Value: TDispatchPageParamsHandledEvent);
    function GetDefaultActionName: TAdapterActionName;
    procedure SetDefaultActionName(Value: TAdapterActionName);
  protected
    function GetSiteModuleHelper: TSiteModuleHelper; override;
    function GetSitePageModuleHelper: TSitePageModuleHelper; virtual;
    property SitePageModuleHelper: TSitePageModuleHelper read GetSitePageModuleHelper
      implements IDefaultPageFileName,
        IPageResult, ISetWebContentOptions,
        IGetDefaultAction, IGetProducerComponent, IProducerEditorViewSupport;
    procedure Notification(AComponent: TComponent;
      Operation: TOperation); override;
  public
    constructor Create(AOwner: TComponent); override;
    constructor CreateNew(AOwner: TComponent; Dummy: Integer=0); override;
    destructor Destroy; override;
    property PageProducer: IProduceContent read FPageProducer write SetPageProducer;
    property OnBeforeDispatchPage: TDispatchPageHandledEvent read GetOnBeforeDispatchPage write SetOnBeforeDispatchPage;
    property OnAfterDispatchPage: TDispatchPageEvent read GetOnAfterDispatchPage write SetOnAfterDispatchPage;
    property OnBeforeRedirectToPage: TDispatchPageParamsHandledEvent read GetOnBeforeRedirectToPage write SetOnBeforeRedirectToPage;
    property OnAfterRedirectToPage: TDispatchPageEvent read GetOnAfterRedirectToPage write SetOnAfterRedirectToPage;
    property DefaultAction: TAdapterActionName read GetDefaultActionName write SetDefaultActionName;
  end;

  TWebPageModule = class(TCustomWebPageModule)
  published
    property OnActivate;
    property OnDeactivate;
    property PageProducer;
    property OnBeforeDispatchPage;
    property OnAfterDispatchPage;
    property DefaultAction;
  end;

  TCustomWebAppDataModule = class(TCustomWebDataModule, IGetWebAppServices, IInterface
    {IGetWebAppComponents also implemented})
  private
    FAppServices: IWebAppServices;
    procedure SetAppServices(const Value: IWebAppServices);
  protected
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    { IInterface }
    function QueryInterface(const IID: TGUID; out Obj): HResult; override;
    { IGetWebAppServices }
    function GetWebAppServices: IWebAppServices;
  public
    { Public declarations }
    constructor Create(AOwner: TComponent); override;
    constructor CreateNew(AOwner: TComponent; Dummy: Integer=0); override;
    destructor Destroy; override;
    property AppServices: IWebAppServices read FAppServices write SetAppServices;
  end;

  TWebAppDataModule = class(TCustomWebAppDataModule)
  published
    property OnActivate;
    property OnDeactivate;
    property AppServices;
  end;

  TCustomWebAppPageModule = class(TCustomWebPageModule, IGetWebAppServices,
    IInterface {IGetWebAppComponents also implemented})
  private
    FAppServices: IWebAppServices;
  protected
    procedure SetAppServices(const Value: IWebAppServices);
    procedure Notification(AComponent: TComponent;
      Operation: TOperation); override;
    { IInterface }
    function QueryInterface(const IID: TGUID; out Obj): HResult; override;
    { IGetWebAppServices }
    function GetWebAppServices: IWebAppServices;
  public
    { Public declarations }
    constructor Create(AOwner: TComponent); override;
    constructor CreateNew(AOwner: TComponent; Dummy: Integer=0); override;
    destructor Destroy; override;
    property AppServices: IWebAppServices read FAppServices write SetAppServices;
  end;

  TWebAppPageModule = class(TCustomWebAppPageModule)
  published
    property OnBeforeDispatchPage;
    property OnAfterDispatchPage;
    property OnActivate;
    property OnDeactivate;
    property PageProducer;
    property AppServices;
    property DefaultAction;
  end;

  TWebAppPageModuleHelper = class(TSitePageModuleHelper)
  protected
    function GetPageProducer: IProduceContent; override;
  end;

  TWebNotifyContainer = class(TObject)
  private
  protected
    FList: TComponentList;
    function GetCount: Integer;
  public
    constructor Create;
    destructor Destroy; override;
    procedure NotifyWebActivate;
    procedure NotifyWebDeactivate;
    procedure Add(AComponent: TComponent);
  end;

  EWebModuleException = class(EWebBrokerException)
  end;

function FindNamedModuleVariable(AModule: TComponent;
  const AName: string): TComponent;
function GetModuleVariable(AModule: TComponent; Index: Integer): TComponent;
function GetModuleVariableCount(AModule: TComponent): Integer;

implementation

uses WebConst,
 WebScript, WebCntxt, WebAuto;

procedure RaiseVariableIsNotAContainer(const AName: string);
begin
  raise EWebModuleException.CreateFmt(sVariableIsNotAContainer, [AName]);
end;

function FindNamedModuleVariable(AModule: TComponent;
  const AName: string): TComponent;
var
  I: Integer;
  WebVariableName: IWebVariableName;
begin
  if AName <> '' then
    for I := 0 to AModule.ComponentCount - 1 do
    begin
      Result := AModule.Components[I];
      Supports(IInterface(Result), IWebVariableName, WebVariableName);
      if Assigned(WebVariableName) then
        if SameText(WebVariableName.VariableName, AName) then
          Exit;
    end;
  Result := nil;
end;

function GetModuleVariable(AModule: TComponent; Index: Integer): TComponent;
var
  I, J: Integer;
  WebVariableName: IWebVariableName;
begin
  J := 0;
  for I := 0 to AModule.ComponentCount - 1 do
  begin
    Result := AModule.Components[I];
    if Result.GetParentComponent = nil then
    begin
      Supports(IInterface(Result), IWebVariableName, WebVariableName);
      if Assigned(WebVariableName) then
        if Index = J then
          Exit
        else
          Inc(J);
    end;
  end;
  Result := nil;
end;

function GetModuleVariableCount(AModule: TComponent): Integer;
var
  I: Integer;
  WebVariableName: IWebVariableName;
begin
  Result := 0;
  for I := 0 to AModule.ComponentCount - 1 do
    if AModule.Components[I].GetParentComponent = nil then
      if Supports(IInterface(AModule.Components[I]), IWebVariableName, WebVariableName) then
        Inc(Result);
end;

 { TCustomWebAppDataModule }

constructor TCustomWebAppDataModule.Create(AOwner: TComponent);
begin
  // must stream in properties of dispatcher
  CreateNew(AOwner);
  if (ClassType <> TWebAppDataModule) and not (csDesigning in ComponentState) then
  begin
    if not InitInheritedComponent(Self, TCustomWebAppDataModule) then
      raise EResNotFound.CreateFmt(SResNotFound, [ClassName]);
    try
      if Assigned(OnCreate) and OldCreateOrder then OnCreate(Self);
    except
      if Assigned(ApplicationHandleException) then
        ApplicationHandleException(Self);
    end;
  end;
end;

constructor TCustomWebAppDataModule.CreateNew(AOwner: TComponent; Dummy: Integer);
begin
  inherited CreateNew(AOwner);
end;

procedure TCustomWebAppDataModule.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited;
  if (Operation = opRemove) and AComponent.IsImplementorOf(FAppServices) then
    FAppServices := nil;
end;

procedure TCustomWebAppDataModule.SetAppServices(const Value: IWebAppServices);
begin
  ReferenceInterface(FAppServices, opRemove);
  FAppServices := Value;
  ReferenceInterface(FAppServices, opInsert);
end;

function TCustomWebAppDataModule.QueryInterface(const IID: TGUID;
  out Obj): HResult;
begin
  if IsEqualGuid(IID, IGetWebAppComponents) then
    if Supports(AppServices, IGetWebAppComponents, Obj) then
    begin
      Result := S_OK;
      exit;
    end;
  Result := inherited QueryInterface(IID, Obj);
end;

destructor TCustomWebAppDataModule.Destroy;
begin
  // If the AppServices is owned by this module, we may
  // not get a notification when it is destroyed.  Clear the WebAppServices just in case.
  AppServices := nil;
  inherited;
end;

{ TCustomWebAppPageModule }

constructor TCustomWebAppPageModule.Create(AOwner: TComponent);
begin
  //  must stream in properties of dispatcher
  CreateNew(AOwner);
  if (ClassType <> TWebAppPageModule) and not (csDesigning in ComponentState) then
  begin
    if not InitInheritedComponent(Self, TCustomWebAppPageModule) then
      raise EResNotFound.CreateFmt(SResNotFound, [ClassName]);
    try
      if Assigned(OnCreate) and OldCreateOrder then OnCreate(Self);
    except
      if Assigned(ApplicationHandleException) then
        ApplicationHandleException(Self);
    end;
  end;
end;

constructor TCustomWebAppPageModule.CreateNew(AOwner: TComponent; Dummy: Integer);
begin
  inherited CreateNew(AOwner);
end;

function TCustomWebAppPageModule.QueryInterface(const IID: TGUID; out Obj): HResult;
begin
  if IsEqualGuid(IID, IGetWebAppComponents) then
    if Supports(AppServices, IGetWebAppComponents, Obj) then
    begin
      Result := S_OK;
      exit;
    end;
  Result := inherited QueryInterface(IID, Obj);
end;


procedure TCustomWebAppPageModule.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited;
  if Operation = opRemove then
  begin
    if AComponent.IsImplementorOf(FAppServices) then
      FAppServices := nil;
    if AComponent = DefaultAction.Adapter then
      DefaultAction.Adapter := nil;
  end;

end;

procedure TCustomWebAppPageModule.SetAppServices(const Value: IWebAppServices);
begin
  ReferenceInterface(FAppServices, opRemove);
  FAppServices := Value;
  ReferenceInterface(FAppServices, opInsert);
end;

destructor TCustomWebAppPageModule.Destroy;
begin
  // If the AppServices is owned by this module, we may
  // not get a notification when it is destroyed.  Clear the WebAppServices just in case.
  AppServices := nil;
  inherited;
end;

{ TCustomWebDataModule }

destructor TCustomWebDataModule.Destroy;
begin
  inherited;
  FreeAndNil(FSiteModuleHelper);
end;

procedure TCustomWebDataModule.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited;
  if SiteModuleHelper <> nil then
    SiteModuleHelper.Notification(AComponent, Operation);
end;

function TCustomWebAppDataModule.GetWebAppServices: IWebAppServices;
begin
  Result := FAppServices;
end;

constructor TCustomWebDataModule.Create(AOwner: TComponent);
begin
  CreateNew(AOwner);
  if (ClassType <> TWebDataModule) and not (csDesigning in ComponentState) then
  begin
    if not InitInheritedComponent(Self, TCustomWebDataModule) then
      raise EResNotFound.CreateFmt(SResNotFound, [ClassName]);
    try
      if Assigned(OnCreate) and OldCreateOrder then OnCreate(Self);
    except
      if Assigned(ApplicationHandleException) then
        ApplicationHandleException(Self);
      raise;
    end;
  end;
end;

constructor TCustomWebDataModule.CreateNew(AOwner: TComponent; Dummy: Integer);
begin
  inherited CreateNew(AOwner);
end;

function TCustomWebDataModule.GetOnActivate: TNotifyEvent;
begin
  Result := SiteModuleHelper.OnActivate;
end;

function TCustomWebDataModule.GetOnDeactivate: TNotifyEvent;
begin
  Result := SiteModuleHelper.OnDeactivate;
end;

function TCustomWebDataModule.GetRequest: TWebRequest;
begin
  Result := SiteModuleHelper.Request;
end;

function TCustomWebDataModule.GetResponse: TWebResponse;
begin
  Result := SiteModuleHelper.Response;
end;

function TCustomWebDataModule.GetSession: TAbstractWebSession;
begin
  Result := SiteModuleHelper.Session;
end;

procedure TCustomWebDataModule.SetOnActivate(const Value: TNotifyEvent);
begin
  SiteModuleHelper.OnActivate := Value;
end;

procedure TCustomWebDataModule.SetOnDeactivate(const Value: TNotifyEvent);
begin
  SiteModuleHelper.OnDeactivate := Value;
end;

function TCustomWebDataModule.GetSiteModuleHelper: TSiteModuleHelper;
begin
  if FSiteModuleHelper = nil then
    FSiteModuleHelper := TSiteModuleHelper.Create(Self);
  Result := FSiteModuleHelper;
end;

function TCustomWebDataModule.GetScriptObject: IDispatch;
begin
  Result := ImplGetScriptObject;
end;

function TCustomWebDataModule.ImplGetScriptObject: IDispatch;
begin
  Result := TWebModuleWrapper.Create(Self) as IDispatch;
end;

{ TWebAppPageModuleHelper }

function TWebAppPageModuleHelper.GetPageProducer: IProduceContent;
begin
  Result := (Module as TWebAppPageModule).PageProducer;
end;

{ TWebPageModuleHelper }

function TWebPageModuleHelper.GetPageProducer: IProduceContent;
begin
  Result := (Module as TCustomWebPageModule).PageProducer;
end;

{ TCustomWebPageModule }

constructor TCustomWebPageModule.Create(AOwner: TComponent);
begin
  //  must stream in properties of dispatcher
  CreateNew(AOwner);
  if (ClassType <> TWebPageModule) and not (csDesigning in ComponentState) then
  begin
    if not InitInheritedComponent(Self, TWebPageModule) then
      raise EResNotFound.CreateFmt(SResNotFound, [ClassName]);
    try
      if Assigned(OnCreate) and OldCreateOrder then OnCreate(Self);
    except
      if Assigned(ApplicationHandleException) then
        ApplicationHandleException(Self);
    end;
  end;
end;

constructor TCustomWebPageModule.CreateNew(AOwner: TComponent;
  Dummy: Integer);
begin
  inherited CreateNew(AOwner);
end;

destructor TCustomWebPageModule.Destroy;
begin
  // If the PageProducer is owned by this module, we may
  // not get a notification when it is destroyed.  Clear the PageProducer just in case.
  PageProducer := nil;
  inherited;
  FreeAndNil(FSitePageModuleHelper);
end;

function TCustomWebPageModule.GetOnAfterDispatchPage: TDispatchPageEvent;
begin
  Result := SitePageModuleHelper.OnAfterDispatchPage;
end;

function TCustomWebPageModule.GetOnAfterRedirectToPage: TDispatchPageEvent;
begin
  Result := SitePageModuleHelper.OnAfterRedirectToPage;
end;

function TCustomWebPageModule.GetOnBeforeDispatchPage: TDispatchPageHandledEvent;
begin
  Result := SitePageModuleHelper.OnBeforeDispatchPage;
end;

function TCustomWebPageModule.GetOnBeforeRedirectToPage: TDispatchPageParamsHandledEvent;
begin
  Result := SitePageModuleHelper.OnBeforeRedirectToPage;
end;

function TCustomWebPageModule.GetSiteModuleHelper: TSiteModuleHelper;
begin
  Result := GetSitePageModuleHelper;
end;

function TCustomWebPageModule.GetSitePageModuleHelper: TSitePageModuleHelper;
begin
  if FSitePageModuleHelper = nil then
    FSitePageModuleHelper := TWebPageModuleHelper.Create(Self);
  Result := FSitePageModuleHelper;
end;

function TCustomWebAppPageModule.GetWebAppServices: IWebAppServices;
begin
  Result := FAppServices;
end;

procedure TCustomWebPageModule.Notification(
  AComponent: TComponent; Operation: TOperation);
var
  Intf: IProduceContent;
begin
  inherited;
  if (Operation = opInsert) and not (csLoading in ComponentState) then
  begin
    if (FPageProducer = nil) and Supports(AComponent, IProduceContent, Intf) then
      PageProducer := Intf;
  end;
  if Operation = opRemove then
  begin
    if AComponent.IsImplementorOf(FPageProducer) then
      FPageProducer := nil;
    if AComponent = DefaultAction.Adapter then
      DefaultAction.Adapter := nil;
  end;
end;

procedure TCustomWebPageModule.SetOnAfterDispatchPage(
  const Value: TDispatchPageEvent);
begin
  SitePageModuleHelper.OnAfterDispatchPage := Value;
end;

procedure TCustomWebPageModule.SetOnAfterRedirectToPage(
  const Value: TDispatchPageEvent);
begin
  SitePageModuleHelper.OnAfterRedirectToPage := Value;
end;

procedure TCustomWebPageModule.SetOnBeforeDispatchPage(
  const Value: TDispatchPageHandledEvent);
begin
  SitePageModuleHelper.OnBeforeDispatchPage := Value;
end;

procedure TCustomWebPageModule.SetOnBeforeRedirectToPage(
  const Value: TDispatchPageParamsHandledEvent);
begin
  SitePageModuleHelper.OnBeforeRedirectToPage := Value;
end;

procedure TCustomWebPageModule.SetPageProducer(
  Value: IProduceContent);
begin
  ReferenceInterface(FPageProducer, opRemove);
  FPageProducer := Value;
  ReferenceInterface(FPageProducer, opInsert);
end;

procedure TCustomWebPageModule.SetDefaultActionName(Value: TAdapterActionName);
begin
  SitePageModuleHelper.DefaultAction := Value;
end;

function TCustomWebPageModule.GetDefaultActionName: TAdapterActionName;
begin
  Result := SitePageModuleHelper.DefaultAction;
end;

{ TSiteModuleHelper }

constructor TSiteModuleHelper.Create(AModule: TComponent);
begin
  inherited Create;
  FModule := AModule;
  FWebNotifyContainer := TWebNotifyContainer.Create;
end;

function TSiteModuleHelper.FindNamedVariable(
  const AName: string): TComponent;
begin
  Result := FindNamedModuleVariable(FModule, AName);
end;

function TSiteModuleHelper.FindVariable(const AName: string): TComponent;
begin
  Result := FindNamedVariable(AName);
end;

function TSiteModuleHelper.FindVariableContainer(
  const AName: string): TComponent;
var
  Intf: IUnknown;
begin
  Result := FindNamedVariable(AName);
  if Assigned(Result) and
    not Supports(IInterface(Result), IWebVariablesContainer, Intf) then
    RaiseVariableIsNotAContainer(AName);
end;

function TSiteModuleHelper.GetVariable(I: Integer): TComponent;
begin
  Result := GetModuleVariable(FModule, I);
end;

function TSiteModuleHelper.GetVariableCount: Integer;
begin
  Result := GetModuleVariableCount(FModule);
end;

function TSiteModuleHelper.GetWebModuleContext: TWebModuleContext;
begin
  if not Assigned(FWebModuleContext) then
    FWebModuleContext := FindComponentWebModuleContext(FModule);
  Result := FWebModuleContext;
end;

procedure TSiteModuleHelper.NotifyActivate;
begin
  FRequest := WebContext.Request;
  FResponse := WebContext.Response;
  FSession := WebContext.Session;
  if Assigned(FOnActivate) then
  try
    FOnActivate(FModule);
  except 
    if Assigned(ApplicationHandleException) then
      ApplicationHandleException(Self);
  end;
  FWebNotifyContainer.NotifyWebActivate;
end;

procedure TSiteModuleHelper.NotifyDeactivate;
begin
  if Assigned(FOnDeActivate) then
    FOnDeActivate(FModule);
  FWebNotifyContainer.NotifyWebDeactivate;
  FRequest := nil;
  FResponse := nil;
  FSession := nil;
end;

procedure TSiteModuleHelper.Notification(AComponent: TComponent;
  Operation: TOperation);
var
  Intf: IUnknown;
begin
  inherited;
  if Operation = opInsert then
  begin
    if (AComponent <> FModule) and Supports(IInterface(AComponent), INotifyWebActivate, Intf) then
      FWebNotifyContainer.Add(AComponent);
  end;
end;

destructor TSiteModuleHelper.Destroy;
begin
  inherited;
  FWebNotifyContainer.Free;
end;

procedure TSiteModuleHelper.EndIterator(OwnerData: Pointer);
begin
  FIteratorIndex := 0;
end;

function TSiteModuleHelper.GetCurrentObject(OwnerData: Pointer): TObject;
begin
  Result := GetVariable(FIteratorIndex);
end;

function TSiteModuleHelper.NextIteration(var OwnerData: Pointer): Boolean;
begin
  Inc(FIteratorIndex);
  Result := FIteratorIndex < FIteratorCount;
end;

function TSiteModuleHelper.StartIterator(var OwnerData: Pointer): Boolean;
begin
  FIteratorIndex := 0;
  FIteratorCount := GetVariableCount;
  Result := FIteratorIndex < FIteratorCount;
end;

{ TSitePageModuleHelper }

function TSitePageModuleHelper.GetTemplateStream(const APage: string; out AOwned: Boolean): TStream;
var
  GetLocate: IGetLocateFileService;
  ManagerIntf: ILocateFileService;
  PageFile: string;
  PageInfo: TAbstractWebPageInfo;
  GetAppDispatcher: IGetAppDispatcher;
begin
  Result := nil;
  if APage = '' then
    PageFile := FDefaultPageFileName
  else
  begin
    if WebContext.FindPageInfo(APage, [], PageInfo) then
      PageFile := PageInfo.PageFile
   end;

  if PageFile <> '' then
  begin
    if Supports(IUnknown(GetPageProducer), IGetAppDispatcher, GetAppDispatcher) then
      if Supports(IUnknown(GetAppDispatcher.GetAppDispatcher), IGetLocateFileService, GetLocate) then
        ManagerIntf := GetLocate.GetLocateFileService;
    if ManagerIntf <> nil then
      Result := ManagerIntf.GetTemplateStream(GetProducerComponent, PageFile, AOwned);
    if Result = nil then
      if DesignerFileManager <> nil then
        Result := DesignerFileManager.GetStream(PageFile, AOwned);
    if Result = nil then
    begin
      Result := TFileStream.Create(QualifyFileName(PageFile), fmOpenRead or fmShareDenyNone);
      AOwned := True;
    end;
  end
  else
    Result := nil;
end;

function TSitePageModuleHelper.DispatchPage(const APageName: string;
  AWebResponse: TWebResponse): Boolean;
begin
  Result := ImplDispatchPage(APageName, AWebResponse);
end;

function TSitePageModuleHelper.ImplDispatchPage(const APageName: string;
  AWebResponse: TWebResponse): Boolean;
var
  S: string;
  InStream: TStream;
  Owned: Boolean;
  ProduceContent: IProduceContent;
begin
  Result := False;
  if Assigned(OnBeforeDispatchPage) then
    OnBeforeDispatchPage(Self, APageName, Result);
  if not Result then
  begin
    WebContext.DispatchedPageName := APageName;
    InStream := GetTemplateStream(APageName, Owned);
    if InStream <> nil then
      try
        S := HTMLFromTemplate(InStream);
      finally
        if Owned then
          InStream.Free;
      end
    else if Supports(IUnknown(GetPageProducer), IProduceContent, ProduceContent) then
      S := ProduceContent.ProduceContent
    else
      S := '';

    AWebResponse.Content := S;
    Result := True;
    if Assigned(OnAfterDispatchPage) then
      OnAfterDispatchPage(Self, APageName);
  end;
end;

function TSitePageModuleHelper.RedirectToPage(const APageName: string; AParams: TStrings;
  AResponse: TWebResponse): Boolean;
begin
  Result := ImplRedirectToPage(APageName, AParams, AResponse);
end;

function TSitePageModuleHelper.ImplRedirectToPage(const APageName: string;
  AParams: TStrings; AResponse: TWebResponse): Boolean;
var
  S: TStrings;
  R: string;
begin
  Result := False;
  S := TStringList.Create;
  try
    GetRedirectParams(APageName, S);
    if AParams <> nil then
      S.AddStrings(AParams);
    if Assigned(OnBeforeRedirectToPage) then
      OnBeforeRedirectToPage(Self, APageName, S, Result);
    if not Result then
    begin
      R := AResponse.HTTPRequest.InternalScriptName + '/' + APageName + EncodeParamsAsHTTPQuery(S);
      if Response.Cookies.Count > 0 then
        SafeRedirect(Response, R)
      else
        Response.SendRedirect(R);
      Result := True;
      if Assigned(OnAfterRedirectToPage) then
        OnAfterRedirectToPage(Self, APageName);
    end;
  finally
    S.Free;
  end;
end;

procedure TSitePageModuleHelper.SetWebContentOptions(AOptions: TWebContentOptions);
begin
  ImplSetWebContentOptions(AOptions);
end;

procedure TSitePageModuleHelper.SetDefaultPageFileName(const AValue: string);
begin
  FDefaultPageFileName := AValue;
end;

constructor TSitePageModuleHelper.Create(AModule: TComponent);
begin
  inherited;
  FDefaultAction := TAdapterActionName.Create(AModule);
end;

function TSitePageModuleHelper.HTMLFromTemplate(
  AStream: TStream): string;
var
  Intf: IProduceContentFrom;
begin
  if Supports(IUnknown(GetPageProducer), IProduceContentFrom, Intf) then
    Result := Intf.ProduceContentFromStream(AStream)
  else
    Result := '';
end;

function TSitePageModuleHelper.GetProducerComponent: TComponent;
var
  ComponentReference: IInterfaceComponentReference;
begin
  if Supports(GetPageProducer, IInterfaceComponentReference, ComponentReference) then
    Result := ComponentReference.GetComponent
  else
    Result := nil;
end;

procedure TSitePageModuleHelper.ImplSetWebContentOptions(
  AOptions: TWebContentOptions);
var
  Intf: ISetWebContentOptions;
begin
  if Supports(IUnknown(GetPageProducer), ISetWebContentOptions, Intf) then
    Intf.SetWebContentOptions(AOptions);
end;

function TSitePageModuleHelper.GetPageProducer: IProduceContent;
begin
  Assert(False, 'GetPageProducer not implemented');
  Result := nil;
end;

function FindAdapterDispatcher: IAdapterDispatcher;
var
  GetIntf: IGetWebAppComponents;
  AppModule: TComponent;
begin
  AppModule := WebContext.FindApplicationModule(nil);
  if Supports(IUnknown(AppModule), IGetWebAppComponents, GetIntf) then
    Result := GetIntf.GetAdapterDispatcher;
end;

procedure TSitePageModuleHelper.GetRedirectParams(const APageName: string; AParams: TStrings);
var
  AdapterDispatcher: IAdapterDispatcher;
  P: IAdapterItemRequestParams;
begin
  if DefaultAction <> nil then
  begin
    AdapterDispatcher := FindAdapterDispatcher;
    if AdapterDispatcher <> nil then
    begin
      P := TAdapterItemRequestParams.Create;
      try
        AdapterDispatcher.GetAdapterItemRequestParams(DefaultAction.Action, [], P);
        AParams.Assign(P.ParamValues);
      finally
        P := nil;
      end;
    end;
  end;
end;

destructor TSitePageModuleHelper.Destroy;
begin
  inherited;
  FDefaultAction.Free;
end;

procedure TSitePageModuleHelper.SetDefaultActionName(
  const Value: TAdapterActionName);
begin
  FDefaultAction.Assign(Value);
end;

function TSitePageModuleHelper.GetDefaultAction: TComponent;
begin
  Result := FDefaultAction.Action;
end;

function TSitePageModuleHelper.ImplIncludePage(const APageName: string;
  var AOwned: Boolean): TStream;
var
  S: TStream;
  SOwned: Boolean;
  Options: TWebContentOptions;
begin
  Result := nil;
  S := GetTemplateStream(APageName, SOwned);
  if S <> nil then
    try
      Options := TWebContentOptions.Create([coNoExecuteScript]);
      SetWebContentOptions(Options);
      try
        Result := TStringStream.Create(HTMLFromTemplate(S));
        AOwned := True;
      finally
        SetWebContentOptions(nil);
      end;
    finally
      if SOwned then
        S.Free;
    end;
end;

function TSitePageModuleHelper.IncludePage(const APageName: string;
  var AOwned: Boolean): TStream;
begin
  Result := ImplIncludePage(APageName, AOwned);
end;

function TSitePageModuleHelper.GetTemplateFileType: string;
begin
  Result := 'HTML';   // Do not localize
end;

function TSitePageModuleHelper.GetXMLData(var Owned: Boolean): TStream;
begin
  Result := nil;
end;

function TSitePageModuleHelper.GetXSLData(var Owned: Boolean): TStream;
begin
  Result := nil;
end;

function TSitePageModuleHelper.HasHTMLBrowserView: Boolean;
begin
  Result := True;
end;

function TSitePageModuleHelper.HasScriptView: Boolean;
begin
  Result := False;
end;

function TSitePageModuleHelper.HasXMLBrowserView: Boolean;
begin
  Result := False;
end;

function TSitePageModuleHelper.HasXSLBrowserView: Boolean;
begin
  Result := False;
end;

{ TWebNotifyContainer }

procedure TWebNotifyContainer.Add(AComponent: TComponent);
begin
  FList.Add(AComponent);
end;

constructor TWebNotifyContainer.Create;
begin
  inherited;
  FList := TComponentList.Create(False);
end;

destructor TWebNotifyContainer.Destroy;
begin
  inherited;
  FList.Free;
end;

function TWebNotifyContainer.GetCount: Integer;
begin
  Result := FList.Count;
end;

procedure TWebNotifyContainer.NotifyWebActivate;
var
  I: Integer;
  NotifyWebActivate: INotifyWebActivate;
begin
  for I := FList.Count - 1 downto 0 do
    if Supports(IInterface(FList.Items[I]), INotifyWebActivate, NotifyWebActivate) then
       NotifyWebActivate.NotifyActivate;
end;

procedure TWebNotifyContainer.NotifyWebDeactivate;
var
  I: Integer;
  NotifyWebActivate: INotifyWebActivate;
begin
  for I := FList.Count - 1 downto 0 do
    if Supports(IInterface(FList.Items[I]), INotifyWebActivate, NotifyWebActivate) then
       NotifyWebActivate.NotifyDeactivate;
end;

{ TAdapterActionName }

procedure TAdapterActionName.AssignTo(Dest: TPersistent);
begin
  if Dest is TAdapterActionName then
    with TAdapterActionName(Dest) do
    begin
      Adapter := Self.Adapter;
      ActionName := Self.ActionName;
    end
  else
    inherited;
end;

constructor TAdapterActionName.Create(AModule: TComponent);
begin
  FModule := AModule;
  inherited Create;
end;

function TAdapterActionName.GetAction: TComponent;
var
  Actions: IWebActionsList;
begin
  Result := nil;
  if Supports(IUnknown(Adapter), IWebActionsList, Actions) then
    Result := Actions.FindAction(ActionName)
end;

procedure TAdapterActionName.SetAdapter(const Value: TComponent);
begin
  if Value <> FAdapter then
  begin
    FAdapter := Value;
    if FAdapter <> nil then
      FAdapter.FreeNotification(FModule);
  end;
end;

end.
