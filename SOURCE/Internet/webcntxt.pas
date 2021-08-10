{ *************************************************************************** }
{                                                                             }
{ Kylix and Delphi Cross-Platform Visual Component Library                    }
{ Internet Application Runtime                                                }
{                                                                             }
{ Copyright (C) 2000, 2001 Borland Software Corporation                       }
{                                                                             }
{ Licensees holding a valid Borland No-Nonsense License for this Software may }
{ use this file in accordance with such license, which appears in the file    }
{ license.txt that came with this Software.                                   }
{                                                                             }
{ *************************************************************************** }


unit WebCntxt;

interface

uses
  SysUtils, Classes, HTTPApp, Contnrs;
   
type
  TWebContext = class;

  IWebPageInfo = interface
  ['{1CFF50D1-6995-11D4-A4AA-00C04F6BB853}']
    function GetPageName: string;
    property PageName: string read GetPageName;
    function GetPageHREF: string;
    property PageHREF: string read GetPageHREF;
    function GetPageTitle: string;
    property PageTitle: string read GetPageTitle;
    function GetPageDescription: string;
    property PageDescription: string read GetPageDescription;
    function GetPageIsPublished: Boolean;
    property PageIsPublished: Boolean read GetPageIsPublished;
    function GetLoginRequired: Boolean;
    property LoginRequired: Boolean read GetLoginRequired;
    function GetHasViewAccess: Boolean;
    property HasViewAccess: Boolean read GetHasViewAccess;
  end;
  TFindPageOption = (fpPublished, fpLoginRequired);
  TFindPageOptions = set of TFindPageOption;

  IWebEndUser = interface
  ['{2DBBD12D-3C07-4F7E-BD11-B3A4E1E287CD}']
    function HasExecuteRights(ARights: string): Boolean;
    function HasViewRights(ARights: string): Boolean;
    function HasModifyRights(ARights: string): Boolean;
    function GetDisplayName: string;
    function GetLoggedIn: Boolean;
    function GetLogoutAction: TComponent;
    function GetLoginFormAction: TComponent;
    function GetEndUserAdapter: TComponent;
    procedure LogIn(UserID: Variant);
    function ProduceLoginPage: Boolean;
    property DisplayName: string read GetDisplayName;
    property LoggedIn: Boolean read GetLoggedIn;
    property LoginFormAction: TComponent read GetLoginFormAction;
    property LogoutAction: TComponent read GetLogoutAction;
    property EndUserAdapter: TComponent read GetEndUserAdapter;
  end;

  TAbstractWebContext = class(TObject)
  protected
    function GetEndUser: IWebEndUser; virtual; abstract;
    function GetWebRequest: TWebRequest; virtual; abstract;
    function GetWebResponse: TWebResponse; virtual; abstract;
    function GetAdapterRequest: IUnknown; virtual; abstract;
    function GetAdapterResponse: IUnknown; virtual; abstract;
    procedure SetAdapterRequest(Intf: IUnknown); virtual; abstract;
    procedure SetAdapterResponse(Intf: IUnknown); virtual; abstract;
    function GetWebModules: TAbstractWebModuleList; virtual; abstract;
    function GetSession: TAbstractWebSession; virtual; abstract;
    function GetPageCount: Integer; virtual; abstract;
    function GetPageInfo(I: Integer): IWebPageInfo; virtual; abstract;
    function GetDispatchedPageName: string; virtual; abstract;
    procedure SetDispatchedPageName(const APageName: string); virtual; abstract;
    function GetRequestedPageName: string; virtual; abstract;
    procedure SetRequestedPageName(const APageName: string); virtual; abstract;
  public
    constructor Create;
    destructor Destroy; override;
    function FindApplicationModule(WebModuleContext: TWebModuleContext): TComponent; virtual; abstract;
    function FindModuleClass(AClass: TComponentClass): TComponent; virtual; abstract;
    function FindModuleName(const AClass: string): TComponent; virtual; abstract;
    function FindPage(const APage: string; AOptions: TFindPageOptions; out AComponent: TObject): Boolean; virtual; abstract;
    function FindPageInfo(const APage: string; AOptions: TFindPageOptions; out APageInfo: TAbstractWebPageInfo): Boolean; virtual; abstract;
    function FindDefaultPageInfo(AComponentClass: TComponentClass; out APageInfo: TAbstractWebPageInfo): Boolean; virtual; abstract;
    function FindVariableContainer(const AIdent: string): TComponent; virtual; abstract;
    property Request: TWebRequest read GetWebRequest;
    property Response: TWebResponse read GetWebResponse;
    property AdapterRequest: IUnknown read GetAdapterRequest;
    property AdapterResponse: IUnknown read GetAdapterResponse;
    property Session: TAbstractWebSession read GetSession;
    property WebModules: TAbstractWebModuleList read GetWebModules;
    property PageCount: Integer read GetPageCount;
    property Pages[I: Integer]: IWebPageInfo read GetPageInfo;
    property EndUser: IWebEndUser read GetEndUser;
    property DispatchedPageName: string read GetDispatchedPageName write SetDispatchedPageName;
    property RequestedPageName: string read GetRequestedPageName write SetRequestedPageName;
  end;

  TWebContext = class(TAbstractWebContext)
  private
    FWebModules: TAbstractWebModuleList;
    FRequest: TWebRequest;
    FResponse: TWebResponse;
    FSession: TAbstractWebSession;
    FWebPageInfoList: IInterfaceList;
    FApplicationModule: TComponent;
    FEndUser: IWebEndUser;
    FAdapterRequest: IUnknown;
    FAdapterResponse: IUnknown;
    FDispatchedPageName: string;
    FRequestedPageName: string;
  protected
    function GetEndUser: IWebEndUser; override;
    function GetWebModules: TAbstractWebModuleList; override;
    function GetWebRequest: TWebRequest; override;
    function GetWebResponse: TWebResponse; override;
    function GetPageCount: Integer; override;
    function GetPageInfo(I: Integer): IWebPageInfo; override;
    function GetSession: TAbstractWebSession; override;
    function GetAdapterRequest: IUnknown; override;
    function GetAdapterResponse: IUnknown; override;
    procedure SetAdapterRequest(Intf: IUnknown); override;
    procedure SetAdapterResponse(Intf: IUnknown); override;
    function GetDispatchedPageName: string; override;
    procedure SetDispatchedPageName(const APageName: string); override;
    function GetRequestedPageName: string; override;
    procedure SetRequestedPageName(const APageName: string); override;
  public
    constructor Create(AWebModuleList: TAbstractWebModuleList; ARequest: TWebRequest;
      AResponse: TWebResponse; ASession: TAbstractWebSession);
    destructor Destroy; override;
    function FindApplicationModule(WebModuleContext: TWebModuleContext): TComponent; override;
    function FindModuleClass(AClass: TComponentClass): TComponent; override;
    function FindModuleName(const AName: string): TComponent; override;
    function FindPage(const APage: string; AOptions: TFindPageOptions; out AComponent: TObject): Boolean; override;
    function FindPageInfo(const APage: string; AOptions: TFindPageOptions; out APageInfo: TAbstractWebPageInfo): Boolean; override;
    function FindDefaultPageInfo(AComponentClass: TComponentClass; out APageInfo: TAbstractWebPageInfo): Boolean; override;
    function FindVariableContainer(const AIdent: string): TComponent; override;
  end;

  TAbstractAdapterRequest = class(TInterfacedObject)
  private
    function GetRequest: TWebRequest;
  protected
    property Request: TWebRequest read GetRequest;
  public
    constructor Create;
  end;

  TAbstractAdapterResponse = class(TInterfacedObject)
  private
    function GetResponse: TWebResponse;
  protected
    property Response: TWebResponse read GetResponse;
  public
    constructor Create;
  end;

  TGetWebContextProc = function: TAbstractWebContext;
  TSetWebContextProc = procedure(AWebContext: TAbstractWebContext);
  TGetWebEndUserProc = function: IWebEndUser;

  function WebContext: TAbstractWebContext;

var
  GetWebContextProc: TGetWebContextProc;
  SetWebContextProc: TSetWebContextProc;
  GetWebEndUserProc: TGetWebEndUserProc;
  
const
  GetModuleFileNameProc: function: string = nil;

implementation


function WebContext: TAbstractWebContext;
begin
  if Assigned(GetWebContextProc) then
    Result := GetWebContextProc
  else
    Result := nil;
end;

{ TWebContext }

constructor TWebContext.Create(AWebModuleList: TAbstractWebModuleList; ARequest: TWebRequest;
      AResponse: TWebResponse; ASession: TAbstractWebSession);
begin
  inherited Create;
  FRequest := ARequest;
  FResponse := AResponse;
  FWebModules := AWebModuleList;
  FSession := ASession;
  // Set thread var
  if Assigned(SetWebContextProc) then
    SetWebContextProc(Self);
end;

destructor TWebContext.Destroy;
begin
  if Assigned(SetWebContextProc) then
    SetWebContextProc(nil);
  if FWebPageInfoList <> nil then
    FWebPageInfoList.Clear;
  inherited;    
end;

function TWebContext.FindPage(const APage: string; AOptions: TFindPageOptions; out AComponent: TObject): Boolean;
var
  PageInfo: TAbstractWebPageInfo;
begin
  if FindPageInfo(APage, AOptions, PageInfo) then
    AComponent := FindModuleName(PageInfo.Factory.ModuleName)
  else
    AComponent := nil;
  Result := AComponent <> nil;
end;

function TWebContext.FindPageInfo(const APage: string; AOptions: TFindPageOptions; out APageInfo: TAbstractWebPageInfo): Boolean;
var
  I: Integer;
  Factory: TAbstractWebModuleFactory;
begin
  for I := 0 to WebModules.FactoryCount - 1 do
  begin
    Factory := WebModules.Factory[I];
    APageInfo := Factory.WebPageInfo;
    if APageInfo <> nil then
    begin
      if (fpPublished in AOptions) and
        (not APageInfo.IsPublished) then
        continue;
      if (fpLoginRequired in AOptions) and
        (not APageInfo.IsLoginRequired) then
        continue;
      if CompareText(APageInfo.PageName, APage) = 0 then
      begin
        Result := True;
        Exit;
      end;
    end;
  end;
  APageInfo := nil;
  Result := False;
end;

function TWebContext.FindDefaultPageInfo(AComponentClass: TComponentClass; out APageInfo: TAbstractWebPageInfo): Boolean;
var
  I: Integer;
  Factory: TAbstractWebModuleFactory;
begin
  for I := 0 to WebModules.FactoryCount - 1 do
  begin
    Factory := WebModules.Factory[I];
    if (Factory.ComponentClass = AComponentClass) and
      (Factory.WebPageInfo <> nil) then
    begin
      APageInfo := Factory.WebPageInfo;
      Result := True;
      Exit;
    end;
  end;
  APageInfo := nil;
  Result := False;
end;

function TWebContext.FindModuleClass(AClass: TComponentClass): TComponent;
begin
  { Dynamically create a module if not in the module list }
  Result := WebModules.FindModuleClass(AClass);
  if not Assigned(Result) then
    Result := WebModules.AddModuleClass(AClass);
end;

function TWebContext.FindModuleName(const AName: string): TComponent;
begin
  { Dynamically create a module if not in the module list }
  Result := WebModules.FindModuleName(AName);
  if not Assigned(Result) then
    Result := WebModules.AddModuleName(AName);
end;

function TWebContext.GetWebModules: TAbstractWebModuleList;
begin
  Result := FWebModules;
end;

function TWebContext.GetEndUser: IWebEndUser;
begin
  if not Assigned(FEndUser) then
    if Assigned(GetWebEndUserProc) then
      FEndUser := GetWebEndUserProc;
  Result := FEndUser;
end;

function TWebContext.GetWebRequest: TWebRequest;
begin
  Result := FRequest;
end;

function TWebContext.GetWebResponse: TWebResponse;
begin
  Result := FResponse;
end;

function TWebContext.GetAdapterRequest: IUnknown;
begin
  Result := FAdapterRequest;
end;

function TWebContext.GetAdapterResponse: IUnknown;
begin
  Result := FAdapterResponse;
end;

function TWebContext.FindVariableContainer(
  const AIdent: string): TComponent;
begin
  Result := WebModules.FindModuleName(AIdent);
  if Result = nil then
    Result := WebModules.AddModuleName(AIdent);
end;

type
  TWebPageInfoWrapper = class(TInterfacedObject, IWebPageInfo)
  private
    FPageInfo: TAbstractWebPageInfo;
  protected
    { IWebPageInfo }
    function GetPageName: string;
    function GetPageHREF: string;
    function GetPageDescription: string;
    function GetPageTitle: string;
    function GetPageIsPublished: Boolean;
    function GetLoginRequired: Boolean;
    function GetHasViewAccess: Boolean;
  public
    constructor Create(const APageInfo: TAbstractWebPageInfo);
  end;

function TWebContext.GetPageCount: Integer;

  function MakeWebPageInfoList: IInterfaceList;
  var
    I: Integer;
    PageInfo: TAbstractWebPageInfo;
  begin
    Result := TInterfaceList.Create;
    for I := 0 to WebModules.FactoryCount - 1 do
    begin
      //if WebModules.Factory[I].
      PageInfo := WebModules.Factory[I].WebPageInfo;
      if PageInfo <> nil then
        Result.Add(TWebPageInfoWrapper.Create(PageInfo));
    end;
  end;

begin
  if FWebPageInfoList = nil then
    FWebPageInfoList := MakeWebPageInfoList;

  Result := FWebPageInfoList.Count;
end;

function TWebContext.GetPageInfo(I: Integer): IWebPageInfo;
begin
  Result := FWebPageInfoList.Items[I] as IWebPageInfo;
end;

function TWebContext.FindApplicationModule(WebModuleContext: TWebModuleContext): TComponent;
var
  I: Integer;
  Factory: TAbstractWebModuleFactory;
begin
  // WebModuleContext parameter is only used while in design mode
  if FApplicationModule = nil then
  begin
    for I := 0 to WebModules.FactoryCount - 1 do
    begin
      Factory := WebModules.Factory[I];
      if Factory.IsAppModule then
      begin
        FApplicationModule := FindModuleClass(Factory.ComponentClass);
        break;
      end;
    end;
  end;
  Result := FApplicationModule;
end;

function TWebContext.GetSession: TAbstractWebSession;
begin
  Result := FSession;
end;

procedure TWebContext.SetAdapterRequest(Intf: IUnknown);
begin
  FAdapterRequest := Intf;
end;

procedure TWebContext.SetAdapterResponse(Intf: IUnknown);
begin
  FAdapterResponse := Intf;
end;

function TWebContext.GetDispatchedPageName: string;
begin
  Result := FDispatchedPageName;
end;

function TWebContext.GetRequestedPageName: string;
begin
  Result := FRequestedPageName;
end;

procedure TWebContext.SetDispatchedPageName(const APageName: string);
begin
  FDispatchedPageName := APageName;
end;

procedure TWebContext.SetRequestedPageName(const APageName: string);
begin
  FRequestedPageName := APageName;
end;

{ TAbstractWebContext }

constructor TAbstractWebContext.Create;
begin
  inherited;
  if Assigned(SetWebContextProc) then
    SetWebContextProc(Self);
end;

destructor TAbstractWebContext.Destroy;
begin
  inherited;
  if Assigned(SetWebContextProc) then
    SetWebContextProc(nil);
end;

{ TWebPageInfoWrapper }

constructor TWebPageInfoWrapper.Create(
  const APageInfo: TAbstractWebPageInfo);
begin
  FPageInfo := APageInfo;
  inherited Create;
end;

function TWebPageInfoWrapper.GetPageDescription: string;
begin
  Result := FPageInfo.PageDescription;
end;

function TWebPageInfoWrapper.GetPageTitle: string;
begin
  Result := FPageInfo.PageTitle;
end;

function TWebPageInfoWrapper.GetPageHREF: string;
begin
  Result := FPageInfo.PageHREF;
end;

function TWebPageInfoWrapper.GetPageIsPublished: Boolean;
begin
  Result := FPageInfo.IsPublished;
end;

function TWebPageInfoWrapper.GetLoginRequired: Boolean;
begin
  Result := FPageInfo.IsLoginRequired;
end;

function TWebPageInfoWrapper.GetPageName: string;
begin
  Result := FPageInfo.PageName;
end;

function TWebPageInfoWrapper.GetHasViewAccess: Boolean;
begin
  Result := True;
  if FPageInfo.ViewAccess <> '' then
    if WebContext <> nil then
      if WebContext.EndUser <> nil then
        Result := WebContext.EndUser.HasViewRights(FPageInfo.ViewAccess)
end;

{ TAbstractAdapterRequest }

constructor TAbstractAdapterRequest.Create;
begin
  inherited;
  WebContext.SetAdapterRequest(Self);
end;

function TAbstractAdapterRequest.GetRequest: TWebRequest;
begin
  Result := WebContext.Request;
end;

{ TAbstractAdapterResponse }

constructor TAbstractAdapterResponse.Create;
begin
  inherited;
  WebContext.SetAdapterResponse(Self);
end;

function TAbstractAdapterResponse.GetResponse: TWebResponse;
begin
  Result := WebContext.Response;
end;

end.

