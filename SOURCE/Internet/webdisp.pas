{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{  Copyright (c) 2000-2001 Borland Software Corporation }
{                                                       }
{*******************************************************}

unit WebDisp;

interface

{$IFDEF MSWINDOWS}
uses Classes, Messages, HTTPApp, HTTPProd, WebCntxt,
  Masks, WebComp, Contnrs, SysUtils, SiteComp;
{$ENDIF}
{$IFDEF LINUX}
uses Classes, HTTPApp, HTTPProd, WebCntxt,
  Masks, WebComp, Contnrs, SysUtils, SiteComp;
{$ENDIF}

type

  TActivateWebModuleEvent = procedure(Sender: TObject; WebModule: TComponent) of object;
  TDispatchPageHandledEvent = procedure(Sender: TObject; const PageName: string; var Handled: Boolean) of object;
  TDispatchPageParamsHandledEvent = procedure(Sender: TObject; const PageName: string; Params: TStrings; var Handled: Boolean) of object;
  TDispatchPageEvent = procedure(Sender: TObject; const PageName: string) of object;

  TWebRequest = HTTPApp.TWebRequest;
  {$EXTERNALSYM TWebRequest}
  TWebResponse = HTTPApp.TWebResponse;
  {$EXTERNALSYM TWebResponse}

  TMultiModuleWebAppServices = class(TComponent, IWebAppServices, IWebDispatcherAccess, IWebExceptionHandler)
  private
    FWebContext: TAbstractWebContext;
    FRequest: TWebRequest;
    FResponse: TWebResponse;
    FWebModules: TAbstractWebModuleList;
    FOnBeforeDispatch: THTTPMethodEvent;
    FOnAfterDispatch: THTTPMethodEvent;
  protected
    function DoAfterDispatch(Request: TWebRequest;
      Response: TWebResponse): Boolean;
    function DoBeforeDispatch(Request: TWebRequest;
      Response: TWebResponse): Boolean;
    procedure ModuleAdded(AWebModule: TComponent);
    procedure InitModules; virtual;
    procedure InitModule(AWebModule: TComponent); virtual;
    procedure DoneModule(AWebModule: TComponent); virtual;
    function CreateContext: TAbstractWebContext; virtual;
    { IWebExceptionHandler }
    procedure HandleException(E: Exception; var Handled: Boolean);
    procedure ImplHandleException(E: Exception; var Handled: Boolean); virtual;
    { IWebDispatcherAccess }
    function Access_Request: TWebRequest;
    function Access_Response: TWebResponse;
    function IWebDispatcherAccess.Request = Access_Request;
    function IWebDispatcherAccess.Response = Access_Response;
    { IWebAppServices }
    procedure InitContext(WebModuleList: TAbstractWebModuleList; Request: TWebRequest;
      Response: TWebResponse);
    function HandleRequest: Boolean;
    procedure FinishContext;
    function GetExceptionHandler: TObject;
    procedure ImplInitContext(AWebModuleList: TAbstractWebModuleList; ARequest: TWebRequest;
      AResponse: TWebResponse); virtual;
    function ImplHandleRequest: Boolean; virtual;
    procedure ImplFinishContext; virtual;
    property Request: TWebRequest read FRequest;
    property Response: TWebResponse read FResponse;
    property WebModules: TAbstractWebModuleList read FWebModules;
    property OnBeforeDispatch: THTTPMethodEvent read FOnBeforeDispatch write FOnBeforeDispatch;
    property OnAfterDispatch: THTTPMethodEvent read FOnAfterDispatch write FOnAfterDispatch;
  end;

  TCustomWebAppComponents = class(TMultiModuleWebAppServices, IGetWebAppComponents, IGetLocateFileService)
  private
    FDispatchActions: IWebDispatchActions;
    FSession: TAbstractWebSession;
    FSessions: ISessionsService;
    FLocateFileService: ILocateFileService;
    FPageDispatcher: IPageDispatcher;
    FAdapterDispatcher: IAdapterDispatcher;
    FApplicationAdapter: IWebApplicationInfo;
    FEndUserAdapter: IWebEndUser;
    FUserListService: IWebUserList;
    FOnException: TWebExceptionEvent;
    procedure SetLocateFileService(const Value: ILocateFileService);
    procedure SetDispatcher(const Value: IWebDispatchActions);
    procedure CheckSessionsStatus(ANotify: Boolean = True);
    procedure SetSessions(const Value: ISessionsService);
    procedure SetAdapterDispatcher(const Value: IAdapterDispatcher);
    procedure SetPageDispatcher(const Value: IPageDispatcher);
    procedure SetApplicationAdapter(const Value: IWebApplicationInfo);
    procedure SetEndUserAdapter(const Value: IWebEndUser);
    procedure SetUserListService(const Value: IWebUserList);
    function ExceptionAsContent(E: Exception): string;
  protected
    procedure ListRequestHandlers(L: IInterfaceList); virtual;
    { IGetWebAppComponents }
    function GetLocateFileService: ILocateFileService;
    function GetPageDispatcher: IPageDispatcher;
    function GetAdapterDispatcher: IAdapterDispatcher;
    function GetWebApplicationInfo: IWebApplicationInfo;
    function GetWebEndUser: IWebEndUser;
    function GetWebUserList: IWebUserList;
    { IWebAppServices }
    function ImplHandleRequest: Boolean; override;
    { IWebExceptionHandler }
    procedure ImplHandleException(E: Exception; var Handled: Boolean); override;

    procedure Notification(AComponent: TComponent; Operation: TOperation);  override;
    procedure ImplInitContext(AWebModuleList: TAbstractWebModuleList; ARequest: TWebRequest;
      AResponse: TWebResponse); override;
    procedure ImplFinishContext; override;
    procedure InitModules; override;
    procedure InitModule(AModule: TComponent); override;
    function CreateContext: TAbstractWebContext; override;
  public
    property DispatchActions: IWebDispatchActions read FDispatchActions write SetDispatcher;
    property Sessions: ISessionsService read FSessions write SetSessions;
    property LocateFileService: ILocateFileService read FLocateFileService write SetLocateFileService;
    property PageDispatcher: IPageDispatcher read FPageDispatcher write SetPageDispatcher;
    property AdapterDispatcher: IAdapterDispatcher read FAdapterDispatcher write SetAdapterDispatcher;
    property ApplicationAdapter: IWebApplicationInfo read FApplicationAdapter write SetApplicationAdapter;
    property EndUserAdapter: IWebEndUser read FEndUserAdapter write SetEndUserAdapter;
    property UserListService: IWebUserList read FUserListService write SetUserListService;
    property OnException: TWebExceptionEvent read FOnException write FOnException;
  end;

  TWebAppComponents = class(TCustomWebAppComponents)
  published
    property DispatchActions;
    property Sessions;
    property LocateFileService;
    property PageDispatcher;
    property AdapterDispatcher;
    property ApplicationAdapter;
    property EndUserAdapter;
    property UserListService;
    property OnBeforeDispatch;
    property OnAfterDispatch;
    property OnException;
  end;

  TLocateFileServiceFindFileEvent = procedure(ASender: TObject; AComponent: TComponent; const AFileName: string;
    var AFoundFile: string; var AHandled: Boolean) of object;
  TLocateFileServiceFindStreamEvent = procedure(ASender: TObject; AComponent: TComponent; const AFileName: string;
    var AFoundStream: TStream; var AOwned: Boolean; var AHandled: Boolean) of object;
  TCustomLocateFileService = class(TComponent, ILocateFileService, IFindIncludeFile)
  private
    FOnFindTemplateFile: TLocateFileServiceFindFileEvent;
    FOnFindIncludeFile: TLocateFileServiceFindFileEvent;
    FOnFindStream: TLocateFileServiceFindStreamEvent;
  protected
    { IFindIncludeFile }
    function FindIncludeFile(AComponent: TComponent; const AFileName: string; var AResult: string): Boolean;
    function ImplFindIncludeFile(AComponent: TComponent; const AFileName: string; var AResult: string): Boolean; virtual;
    { ILocateFileService }
    function GetTemplateStream(AComponent: TComponent; AFileName: string; out AOwned: Boolean): TStream;
    function ImplGetTemplateStream(AComponent: TComponent; AFileName: string; out AOwned: Boolean): TStream; virtual;

    function FindTemplateFile(AComponent: TComponent; const AFileName: string;
      var AResult: string): Boolean;
    function FindStream(AComponent: TComponent; const AFileName: string;
      out AResult: TStream; out AOwned: Boolean): Boolean; virtual;
    function GetFileStream(const AFileName: string;
      out AOwned: Boolean): TStream; virtual;
    property OnFindIncludeFile: TLocateFileServiceFindFileEvent read FOnFindIncludeFile write FOnFindIncludeFile;
    property OnFindTemplateFile: TLocateFileServiceFindFileEvent read FOnFindTemplateFile write FOnFindTemplateFile;
    property OnFindStream: TLocateFileServiceFindStreamEvent read FOnFindStream write FOnFindStream;
  end;

  TLocateFileService = class(TCustomLocateFileService)
  published
    property OnFindTemplateFile;
    property OnFindIncludeFile;
    property OnFindStream;
  end;

  TBaseRequestHandler = class(TComponent, IWebRequestHandler, ISetAppDispatcher)
  private
    FAppDispatcher: TComponent;
  protected
    { ISetAppDispatcher }
    procedure SetAppDispatcher(const AWebAppDispatcher: TComponent);
    { IWebRequestHandler }
    function HandleRequest(ARequest: TWebRequest;
      AResponse: TWebResponse): Boolean;
    function ImplHandleRequest(ARequest: TWebRequest;
      AResponse: TWebResponse): Boolean; virtual;
    property AppDispatcher: TComponent read FAppDispatcher;
  end;

  TAdapterDispatchParams = class(TInterfacedObject, IAdapterDispatchParams,
    IGetAdapterRequestDefaultResponse)
  private
    FObjectIdentifier: string;
    FRequestIdentifier: string;
    FSuccessPage: string;
    FFailurePage: string;
    FParams: TStrings;
    FHandler: TObject;
  protected
    { IAdapterDispatchParams }
    function GetRequestIdentifier: string;
    function GetObjectIdentifier: string;
    function GetParams: TStrings;
    function GetHandler: TObject;
    { IGetAdapterRequestDefaultResponse }
    function GetSuccessPage: string;
    function GetFailurePage: string;
  public
    constructor Create(ARequest: TWebRequest);
    destructor Destroy; override;
    property RequestIdentifier: string read GetRequestIdentifier;
    property ObjectIdentifier: string read GetObjectIdentifier;
    property Handler: TObject read GetHandler;
  end;

  TGetAdapterRequestParamsEvent = procedure(Sender: TObject; Handler: IUnknown;
    var Identifer: string; Params: TStrings) of object;
  TDispatchActionEvent = procedure(Sender: TObject; Action: TObject; Params: TStrings) of object;
  TDispatchActionHandledEvent = procedure(Sender: TObject; Action: TObject; Params: TStrings; var Handled: Boolean) of object;
  TDispatchImageEvent = procedure(Sender: TObject; Image: TObject; Params: TStrings) of object;
  TDispatchImageHandledEvent = procedure(Sender: TObject; Image: TObject; Params: TStrings; var Handled: Boolean) of object;

  TCustomAdapterDispatcher = class(TBaseRequestHandler, IAdapterDispatcher)
  private
    FOnGetAdapterRequestParams: TGetAdapterRequestParamsEvent;
    FOnAfterDispatchAction: TDispatchActionEvent;
    FOnBeforeDispatchAction: TDispatchActionHandledEvent;
    FOnAfterDispatchImage: TDispatchImageEvent;
    FOnBeforeDispatchImage: TDispatchImageHandledEvent;
    FOnActionRequestNotHandled: TDispatchActionHandledEvent;
    FOnImageRequestNotHandled: TDispatchImageHandledEvent;
    function GetActionRequestParams(var AStrings: TStrings): Boolean;
    function GetImageRequestParams(var AStrings: TStrings): Boolean;
  protected
    procedure DoAdapterRequestNotHandled(AObject: TObject; var AHandled: Boolean);
    procedure DoAfterDispatchAdapterRequest(AObject: TObject);
    procedure DoBeforeDispatchAdapterRequest(AObject: TObject; var AHandled: Boolean);
    procedure AddSpecialParams(AHandler: IUnknown; Params: IAdapterItemRequestParams); virtual;
    function GetDispatchParams(
      Request: TWebRequest): TAdapterDispatchParams; virtual;
    { IAdapterDispatcher }
    function EncodeAdapterItemRequestAsHREF(AHandler: IUnknown;
      AOptions: TAdapterItemRequestParamOptions): string;
    function ImplEncodeAdapterItemRequestAsHREF(AHandler: IUnknown;
      AOptions: TAdapterItemRequestParamOptions): string; virtual;
    function EncodeAdapterItemRequestAsFieldValue(AHandler: IUnknown;
      AOptions: TAdapterItemRequestParamOptions): string;
    function ImplEncodeAdapterItemRequestAsFieldValue(AHandler: IUnknown;
      AOptions: TAdapterItemRequestParamOptions): string; virtual;
    procedure GetAdapterItemRequestParams(AHandler: IUnknown;
      AOptions: TAdapterItemRequestParamOptions;
      Params: IAdapterItemRequestParams);
    procedure ImplGetAdapterItemRequestParams(AHandler: IUnknown;
      AOptions: TAdapterItemRequestParamOptions;
      Params: IAdapterItemRequestParams); virtual;
    { IWebRequestHandler }
    function ImplHandleRequest(Request: TWebRequest;
      Response: TWebResponse): Boolean; override;
  public
    property OnGetAdapterRequestParams: TGetAdapterRequestParamsEvent read FOnGetAdapterRequestParams write FOnGetAdapterRequestParams;
    property OnBeforeDispatchAction: TDispatchActionHandledEvent read FOnBeforeDispatchAction write FOnBeforeDispatchAction;
    property OnAfterDispatchAction: TDispatchActionEvent read FOnAfterDispatchAction write FOnAfterDispatchAction;
    property OnBeforeDispatchImage: TDispatchImageHandledEvent read FOnBeforeDispatchImage write FOnBeforeDispatchImage;
    property OnAfterDispatchImage: TDispatchImageEvent read FOnAfterDispatchImage write FOnAfterDispatchImage;
    property OnActionRequestNotHandled: TDispatchActionHandledEvent read FOnActionRequestNotHandled write FOnActionRequestNotHandled;
    property OnImageRequestNotHandled: TDispatchImageHandledEvent read FOnImageRequestNotHandled write FOnImageRequestNotHandled;
  end;

  TAdapterDispatcher = class(TCustomAdapterDispatcher)
  published
    property OnGetAdapterRequestParams;
    property OnBeforeDispatchAction;
    property OnBeforeDispatchImage;
    property OnAfterDispatchAction;
    property OnAfterDispatchImage;
    property OnActionRequestNotHandled;
    property OnImageRequestNotHandled;
  end;

  TPageAccessDenied = (adLoginRequired, adCantView);
  TLoginRequiredEvent = procedure(Sender: TObject; const PageName: string; var Required: Boolean) of object;
  TLoginPagedHandledEvent = procedure(Sender: TObject; const PageName: string; var Handled: Boolean) of object;
  TCanViewPageEvent = procedure(Sender: TObject; const PageName: string; var CanView: Boolean; var AHandled: Boolean) of object;
  TPageAccessDeniedEvent = procedure(Sender: TObject; const PageName: string; Reason: TPageAccessDenied;
    var Handled: Boolean) of object;
  TCustomPageDispatcher = class(TBaseRequestHandler, IPageDispatcher)
  private
    FOnIsLoginRequired: TLoginRequiredEvent;
    FEndUserAdapter: IWebEndUser;
    FDefaultPage: string;
    FOnAfterDispatchPage: TDispatchPageEvent;
    FOnBeforeDispatchPage: TDispatchPageHandledEvent;
    FOnPageNotFound: TDispatchPageHandledEvent;
    FOnAfterRedirectToPage: TDispatchPageEvent;
    FOnBeforeRedirectToPage: TDispatchPageParamsHandledEvent;
    FOnCanViewPage: TCanViewPageEvent;
    FOnPageAccessDenied: TPageAccessDeniedEvent;
  protected
    function EndUser: IWebEndUser;
    function ProduceLoginPage: Boolean;
    function IsLoggedIn: Boolean;
    function ValidatePage(const APage: string; var AHandled: Boolean): Boolean;
    function GetRequestedPage(const APageName: string;
      AFlags: TDispatchPageFlags): TObject;
    { IPageDispatcher }
    function PageNameOfRequest(Request: TWebRequest): string;
    function ImplPageNameOfRequest(Request: TWebRequest): string; virtual;
    function DispatchPageName(const APageName: string; AResponse: TWebResponse;
      AFlags: TDispatchPageFlags): Boolean;
    function ImplDispatchPageName(const APageName: string; AResponse: TWebResponse;
      AFlags: TDispatchPageFlags): Boolean;
    function RedirectToPageName(const APageName: string; AParams: TStrings; AResponse: TWebResponse;
      AFlags: TDispatchPageFlags): Boolean;
    function ImplRedirectToPageName(const APageName: string; AParams: TStrings; AResponse: TWebResponse;
      AFlags: TDispatchPageFlags): Boolean;
    function GetDefaultPageName: string;
    function ImplGetDefaultPageName: string; virtual;
    function GetLoginRequired(const APageName: string): Boolean;
    function GetCanView(const APageName: string): Boolean;
    function ImplGetLoginRequired(const APageName: string): Boolean; virtual;
    function ImplGetCanView(const APageName: string): Boolean; virtual;
    { IWebRequestHandler }
    function ImplHandleRequest(Request: TWebRequest;
      Response: TWebResponse): Boolean; override;
  public
    property OnIsLoginRequired: TLoginRequiredEvent read FOnIsLoginRequired write FOnIsLoginRequired;
    property DefaultPage: string read FDefaultPage write FDefaultPage;
    property OnBeforeDispatchPage: TDispatchPageHandledEvent read FOnBeforeDispatchPage write FOnBeforeDispatchPage;
    property OnAfterDispatchPage: TDispatchPageEvent read FOnAfterDispatchPage write FOnAfterDispatchPage;
    property OnBeforeRedirectToPage: TDispatchPageParamsHandledEvent read FOnBeforeRedirectToPage write FOnBeforeRedirectToPage;
    property OnAfterRedirectToPage: TDispatchPageEvent read FOnAfterRedirectToPage write FOnAfterRedirectToPage;
    property OnPageNotFound: TDispatchPageHandledEvent read FOnPageNotFound write FOnPageNotFound;
    property OnCanViewPage: TCanViewPageEvent read FOnCanViewPage write FOnCanViewPage;
    property OnPageAccessDenied: TPageAccessDeniedEvent read FOnPageAccessDenied write FOnPageAccessDenied;
  end;

  TPageDispatcher = class(TCustomPageDispatcher)
  published
    property OnIsLoginRequired;
    property DefaultPage;
    property OnBeforeDispatchPage;
    property OnAfterDispatchPage;
    property OnPageNotFound;
    property OnCanViewPage;
    property OnPageAccessDenied;
  end;

  EPageDispatcherException = class(EWebBrokerException)
  end;

  EAdapterDispatcherException = class(EWebBrokerException)
  end;

  TAdapterItemRequestParams = class(TInterfacedObject, IAdapterItemRequestParams)
  private
    FSuccessPage: string;
    FFailurePage: string;
    FParamValues: TStrings;
  protected
    { IAdapterItemRequestParams }
    procedure SetSuccessPage(const AValue: string);
    procedure SetFailurePage(const AValue: string);
    function GetSuccessPage: string;
    function GetFailurePage: string;
    function GetParamValues: TStrings;
  public
    constructor Create;
    destructor Destroy; override;
    property SuccessPage: string read GetSuccessPage write SetSuccessPage;
    property FailurePage: string read GetFailurePage write SetFailurePage;
    property ParamValues: TStrings read GetParamValues;
  end;

  ESessionException = class(EWebBrokerException);

  IWebSessionAccess = interface
  ['{2C0D625A-9A26-4633-891B-38048E5265F3}']
    function GetWebSession: IWebSession;
    function GetSessionsService: ISessionsService;
  end;

  //   Implements IWebSessionAccess
  //   Uses ISessionsServiceStoreID if implemented by the session service
  TWebSession = class(TAbstractWebSession, IWebSessionAccess)
  private
    FSessions: ISessionsService;
    FWebSession: IWebSession;
    procedure ReadSessionIDFromStore(ASessionsService: ISessionsService;
      ARequest: TWebRequest; AResponse: TWebResponse);
    function ReadSessionCookie(ARequest: TWebRequest; AResponse: TWebResponse; out AID: TSessionID): Boolean;
    constructor Create(ASessions: ISessionsService; AWebSession: IWebSession); overload;
    procedure WriteSessionIDToStore(AResponse: TWebResponse; const AValue: string);
    procedure WriteSessionCookie(AResponse: TWebResponse; const AValue: string);
    { IWebSessionAccess }
    function GetWebSession: IWebSession;
    function GetSessionsService: ISessionsService;
    { IInterface }
    function _AddRef: Integer; stdcall;
    function _Release: Integer;  stdcall;
    function QueryInterface(const IID: TGUID; out Obj): HResult;  stdcall;
  protected
    function GetValue(const AName: string): Variant; override;
    procedure SetValue(const AName: string; const AValue: Variant); override;
    function GetTimeoutMinutes: Integer; override;
    procedure SetTimeoutMinutes(AValue: Integer); override;
    function GetSessionID: string; override;
  public
    procedure UpdateResponse(AResponse: TWebResponse); override;
    procedure Terminate; override;
    constructor Create(ASessions: ISessionsService; ARequest: TWebRequest; AResponse: TWebResponse); overload;
    constructor Create(ASessions: ISessionsService; AID: TSessionID); overload;
  end;

  TInvalidWebSession = class(TAbstractWebSession)
  private
    FMsg: string;
    procedure RaiseInvalidWebSession;
  protected
    function GetValue(const AName: string): Variant; override;
    procedure SetValue(const AName: string; const AValue: Variant); override;
    function GetTimeoutMinutes: Integer; override;
    procedure SetTimeoutMinutes(AValue: Integer); override;
    function GetSessionID: string; override;
  public
    procedure UpdateResponse(AResponse: TWebResponse); override;
    procedure Terminate; override;
    constructor Create(const AMsg: string);
  end;

  function DispatchPageName(const APageName: string; AResponse: TWebResponse;
    AFlags: TDispatchPageFlags): Boolean;
  function RedirectToPageName(const APageName: string; AParams: TStrings; AResponse: TWebResponse;
    AFlags: TDispatchPageFlags): Boolean;
  function FindDefaultAppPageName: string;
  function PageNameOfRequest(ARequest: TWebRequest): string;

  procedure RegisterAdapterRequestIdentifier(const AIdentifier: string);
  function EncodeParamsAsHTTPQuery(AParams: TStrings): string;
  procedure SafeRedirect(AResponse: TWebResponse; const AURL: string);
  procedure ExtractParamNameValues(const AParam: string; AList: TStrings);
  function EncodeParamNameValues(ParamValues: TStrings): string;
  procedure RaiseDispatchBlankPageNameException;
  procedure RaisePageDoesNotProvideContent(const APageName: string);
  procedure RaisePageNotFound(const APageName: string);
  function ExpandScriptException(E: EScriptError): string;
  function AdapterRequestParamsAsStrings(AAdapterRequest: IUnknown): TStrings;

const
  sRequestIDParamName = '__id';    { Do not localize }
  sSuccessPageParamName = '__sp';  { Do not localize }
  sFailurePageParamName = '__fp';  { Do not localize }
  sPageParamName = '__p';  { Do not localize }
  sSessionCookieName = 'WebBrokerSessionID'; { Do not localize }

implementation

{$IFDEF MSWINDOWS}
uses WebConst, Windows,
 WebScript, WebSess, Variants, AdaptReq, SiteConst;
{$ENDIF}
{$IFDEF LINUX}
uses WebConst,
 WebScript, WebSess, Variants, AdaptReq, SiteConst;
{$ENDIF}

var
  RegisteredRequestIdentifiers: TStrings;

procedure SafeRedirect(AResponse: TWebResponse; const AURL: string);
begin
  AResponse.Content := Format(
'<html>'#13#10 +                                                                { do not localize }
'<head>'#13#10 +                                                                { do not localize }
'<title></title>'#13#10 +                                                       { do not localize }
'<META HTTP-EQUIV=''Refresh'' CONTENT=''0; URL=%0:s''>'#13#10 +                 { do not localize }
'</head>'#13#10 +                                                               { do not localize }
'<body>'#13#10 +                                                                { do not localize }
'</BODY>'#13#10 +                                                               { do not localize }
'</HTML>', [AURL]);                                                             { do not localize }
end;

function ExtractStringValue(const S: string): string;
var
  P: Integer;
begin
  P := AnsiPos('=', S);
  if (P <> 0) and (Length(S) > P) then
    Result := Copy(S, P+1, MaxInt) else
    SetLength(Result, 0);
end;

procedure RegisterAdapterRequestIdentifier(const AIdentifier: string);
begin
  if RegisteredRequestIdentifiers = nil then
    RegisteredRequestIdentifiers := TStringList.Create;
  if RegisteredRequestIdentifiers.IndexOf(AIdentifier) < 0 then
    RegisteredRequestIdentifiers.Add(AIdentifier);
end;

procedure RaiseDispatchBlankPageNameException;
begin
  raise EPageDispatcherException.Create(sDispatchBlankPageName);
end;

procedure RaisePageAccessDenied;
begin
  raise EPageDispatcherException.Create(sPageAccessDenied);
end;

procedure RaisePageDoesNotProvideContent(const APageName: string);
begin
  raise EPageDispatcherException.CreateFmt(sPageContentNotProvided, [APageName]);
end;

procedure RaisePageDoesNotSupportRedirect(const APageName: string);
begin
  raise EPageDispatcherException.CreateFmt(sPageDoesNotSupportRedirect, [APageName]);
end;

procedure RaisePageNotFound(const APageName: string);
begin
  raise EPageDispatcherException.CreateFmt(sPageNotFound, [APageName]);
end;

procedure RaiseAdapterRequestNotHandled(ADispatchParams: IAdapterDispatchParams);
begin
  raise EAdapterDispatcherException.CreateFmt(sAdapterRequestNotHandled,
    [ADispatchParams.RequestIdentifier, ADispatchParams.ObjectIdentifier]);
end;

function GetAdapterRequestHTTPPath: string;
begin
  if WebContext.Request <> nil then
    Result := WebContext.Request.InternalScriptName
  else
    Result := '';
end;

function EncodeParamsAsHTTPQuery(AParams: TStrings): string;
var
  I: Integer;
begin
  for I := 0 to AParams.Count - 1 do
  begin
    if Result <> '' then Result := Result + '&';
    Result := Result +
      Format('%s=%s', [HTTPEncode(AParams.Names[I]), HTTPEncode(ExtractStringValue(AParams[I]))]);
  end;
  Result := '/?' + Result;
end;

function LocalHTTPEnc(const AStr: String): String;
// This routine is identical to HTTPApp.HTTPEncode except that it also encodes
// the single quote (') character.  HTTPEncode should be expanded to allow for
// this sort of usage.
const
  NoConversion = ['A'..'Z','a'..'z','*','@','.','_','-',
                  '0'..'9','$','!','(',')'];
var
  Sp, Rp: PChar;
begin
  SetLength(Result, Length(AStr) * 3);
  Sp := PChar(AStr);
  Rp := PChar(Result);
  while Sp^ <> #0 do
  begin
    if Sp^ in NoConversion then
      Rp^ := Sp^
    else
      if Sp^ = ' ' then
        Rp^ := '+'
      else
      begin
        FormatBuf(Rp^, 3, '%%%.2x', 6, [Ord(Sp^)]);
        Inc(Rp,2);
      end;
    Inc(Rp);
    Inc(Sp);
  end;
  SetLength(Result, Rp - PChar(Result));
end;

function EncodeParamNameValues(
  ParamValues: TStrings): string;

  procedure AddNameValue(const AName, AValue: string);
  begin
    Result := Result + Format('%s.%d.%s', [AName, Length(AValue), AValue]);
  end;
var
  I: Integer;
begin
  Result := '';
  for I := 0 to ParamValues.Count - 1 do
    AddNameValue(ParamValues.Names[I], LocalHTTPEnc(ExtractStringValue(ParamValues[I])));
end;

procedure ExtractParamNameValues(const AParam: string; AList: TStrings);
var
  Temp, S: String;
  P: Integer;
  Len: Integer;
  Value: string;
  Name: string;
begin
  Temp := AParam;
  while true do
  begin
    P := Pos('.', Temp);
    if P = 0 then break;
    Name := Copy(Temp, 1, P-1);
    Delete(Temp, 1, P);
    P := Pos('.', Temp);
    if P = 0 then break;
    S := Copy(Temp, 1, P-1);
    Len := StrToInt(S);
    Delete(Temp, 1, P);
    Value :=  HTTPDecode(Copy(Temp, 1, Len));
    Delete(Temp, 1, Len);
    AList.Add(Format('%s=%s', [Name, Value]));
  end;
end;

function PageNameOfRequest(ARequest: TWebRequest): string;
var
  GetIntf: IGetWebAppComponents;
  AppModule: TComponent;
begin
  Result := '';
  AppModule := WebContext.FindApplicationModule(nil);
  if Supports(IUnknown(AppModule), IGetWebAppComponents, GetIntf) then
    if GetIntf.GetPageDispatcher <> nil then
    begin
      Result := GetIntf.GetPageDispatcher.PageNameOfRequest(ARequest);
    end;
end;

function DispatchPageName(const APageName: string; AResponse: TWebResponse;
  AFlags: TDispatchPageFlags): Boolean;
var
  PageComponent: TObject;
  DispatchPage: IPageResult;
  GetIntf: IGetWebAppComponents;
  AppModule: TComponent;
  FindOptions: TFindPageOptions;
begin
  AppModule := WebContext.FindApplicationModule(nil);
  if Supports(IUnknown(AppModule), IGetWebAppComponents, GetIntf) then
    if GetIntf.GetPageDispatcher <> nil then
    begin
      Result := GetIntf.GetPageDispatcher.DispatchPageName(APageName, AResponse, AFlags);
      Exit;
    end;

  WebContext.RequestedPageName := APageName;
  if APageName = '' then
    RaiseDispatchBlankPageNameException;
  if dpPublished in AFlags then
    FindOptions := [fpPublished]
  else
    FindOptions := [];
  if WebCntxt.WebContext.FindPage(APageName, FindOptions, PageComponent) then
  begin
    if not Supports(PageComponent, IPageResult, DispatchPage) then
      RaisePageDoesNotProvideContent(APageName);
    Result := DispatchPage.DispatchPage(APageName, AResponse);
  end
  else
  begin
    RaisePageNotFound(APageName);
    Result := True;
  end;
end;

function RedirectToPageName(const APageName: string; AParams: TStrings; AResponse: TWebResponse;
  AFlags: TDispatchPageFlags): Boolean;
var
  PageComponent: TObject;
  GetIntf: IGetWebAppComponents;
  RedirectToPage: IPageResult;
  AppModule: TComponent;
  FindOptions: TFindPageOptions;
begin
  AppModule := WebContext.FindApplicationModule(nil);
  if Supports(IUnknown(AppModule), IGetWebAppComponents, GetIntf) then
    if GetIntf.GetPageDispatcher <> nil then
    begin
      Result := GetIntf.GetPageDispatcher.RedirectToPageName(APageName, AParams, AResponse, AFlags);
      Exit;
    end;

  WebContext.RequestedPageName := APageName;
  if APageName = '' then
    RaiseDispatchBlankPageNameException;
  if dpPublished in AFlags then
    FindOptions := [fpPublished]
  else
    FindOptions := [];
  if WebCntxt.WebContext.FindPage(APageName, FindOptions, PageComponent) then
  begin
    if not Supports(PageComponent, IPageResult, RedirectToPage) then
      RaisePageDoesNotSupportRedirect(APageName);
    Result := RedirectToPage.RedirectToPage(APageName, AParams, AResponse);
  end
  else
  begin
    RaisePageNotFound(APageName);
    Result := True;
  end;
end;

function TCustomPageDispatcher.EndUser: IWebEndUser;
var
  GetIntf: IGetWebAppComponents;
begin
  if FEndUserAdapter = nil then
    if (AppDispatcher <> nil) and (Supports(IUnknown(AppDispatcher), IGetWebAppComponents, GetIntf)) then
      FEndUserAdapter := GetIntf.WebEndUser;
  Result := FEndUserAdapter;
end;

procedure TCustomAdapterDispatcher.AddSpecialParams(AHandler: IUnknown; Params: IAdapterItemRequestParams);
var
  Intf: IGetAdapterRequestDefaultResponse;
  S, F: string;
begin
  if Supports(AHandler, IGetAdapterRequestDefaultResponse, Intf) then
  begin
    S := Intf.GetSuccessPage;
    F := Intf.GetFailurePage;
    if (F = S) and (S <> '') then
      Params.ParamValues.Add(Format('%s=%s', [sPageParamName, S]))
    else
    begin
      if S <> '' then
        Params.ParamValues.Add(Format('%s=%s', [sSuccessPageParamName, S]));
      if F <> '' then
        Params.ParamValues.Add(Format('%s=%s', [sFailurePageParamName, F]));
    end;
  end;
end;

procedure TCustomAdapterDispatcher.ImplGetAdapterItemRequestParams(
  AHandler: IUnknown; AOptions: TAdapterItemRequestParamOptions; Params: IAdapterItemRequestParams);
var
  Intf: IGetAdapterItemRequestParams;
  Identifier: string;
begin
  if Supports(AHandler, IGetAdapterItemRequestParams, Intf) then
    Intf.GetAdapterItemRequestParams(Identifier, Params);
  AddSpecialParams(AHandler, Params);
  if Identifier <> '' then
    if not (roExcludeID in AOptions) then
      Params.ParamValues.Add(Format('%s=%s', [sRequestIDParamName, Identifier]));
  if Assigned(OnGetAdapterRequestParams) then
    OnGetAdapterRequestParams(Self, AHandler, Identifier, Params.ParamValues);
end;

procedure TCustomAdapterDispatcher.GetAdapterItemRequestParams(
  AHandler: IUnknown; AOptions: TAdapterItemRequestParamOptions; Params: IAdapterItemRequestParams);
begin
  ImplGetAdapterItemRequestParams(AHandler, AOptions, Params);
end;

function TCustomAdapterDispatcher.ImplEncodeAdapterItemRequestAsFieldValue(
  AHandler: IUnknown; AOptions: TAdapterItemRequestParamOptions): string;
var
  Params: IAdapterItemRequestParams;
begin
  Result := '';
  Params := TAdapterItemRequestParams.Create;
  try
    GetAdapterItemRequestParams(AHandler, AOptions, Params);
    Result := EncodeParamNameValues(Params.ParamValues);
  finally
    Params := nil;
  end;
end;

function TCustomAdapterDispatcher.EncodeAdapterItemRequestAsHREF(
  AHandler: IUnknown; AOptions: TAdapterItemRequestParamOptions): string;
begin
  Result := ImplEncodeAdapterItemRequestAsHREF(AHandler, AOptions);
end;

function TCustomAdapterDispatcher.GetDispatchParams(
  Request: TWebRequest): TAdapterDispatchParams;
begin
  Result := TAdapterDispatchParams.Create(Request);
end;

function TCustomAdapterDispatcher.EncodeAdapterItemRequestAsFieldValue(
  AHandler: IUnknown; AOptions: TAdapterItemRequestParamOptions): string;
begin
  Result := ImplEncodeAdapterItemRequestAsFieldValue(AHandler, AOptions);
end;

function TCustomAdapterDispatcher.ImplEncodeAdapterItemRequestAsHREF(
  AHandler: IUnknown;
  AOptions: TAdapterItemRequestParamOptions): string;
var
  Params: IAdapterItemRequestParams;
begin
  Result := '';
  Params := TAdapterItemRequestParams.Create;
  try
    GetAdapterItemRequestParams(AHandler, AOptions, Params);
    Result := GetAdapterRequestHTTPPath + EncodeParamsAsHTTPQuery(Params.ParamValues);
  finally
    Params := nil;
  end;
end;

function AdapterRequestParamsAsStrings(AAdapterRequest: IUnknown): TStrings;
var
  AdapterRequestParams: IAdapterRequestParams;
begin
  if not Supports(AAdapterRequest, IAdapterRequestParams, AdapterRequestParams) then
    Assert(False);
  Result := TStringList.Create;
  try
    AdapterRequestParams.AssignTo(Result);
  except
    Result.Free;
    raise;
  end;
end;

function TCustomAdapterDispatcher.GetActionRequestParams(var AStrings: TStrings): Boolean;
var
  ActionRequest: IActionRequest;
begin
  if Supports(WebContext.AdapterRequest, IActionRequest, ActionRequest) then
    AStrings := AdapterRequestParamsAsStrings(ActionRequest)
  else
    AStrings := nil;
  Result := AStrings <> nil;
end;

function TCustomAdapterDispatcher.GetImageRequestParams(var AStrings: TStrings): Boolean;
var
  ImageRequest: IImageRequest;
begin
  if Supports(WebContext.AdapterRequest, IImageRequest, ImageRequest) then
    AStrings := AdapterRequestParamsAsStrings(ImageRequest)
  else
    AStrings := nil;
  Result := AStrings <> nil;
end;

procedure TCustomAdapterDispatcher.DoBeforeDispatchAdapterRequest(AObject: TObject; var AHandled: Boolean);
var
  S: TStrings;
begin
  if Assigned(OnBeforeDispatchAction) then
    if GetActionRequestParams(S) then
      try
        OnBeforeDispatchAction(Self, AObject, S, AHandled);
      finally
        S.Free;
      end;
  if Assigned(OnBeforeDispatchImage) then
    if GetImageRequestParams(S) then
      try
        OnBeforeDispatchImage(Self, AObject, S, AHandled);
      finally
        S.Free;
      end;
end;

procedure TCustomAdapterDispatcher.DoAfterDispatchAdapterRequest(AObject: TObject);
var
  S: TStrings;
begin
  if Assigned(OnAfterDispatchAction) then
    if GetActionRequestParams(S) then
      try
        OnAfterDispatchAction(Self, AObject, S);
      finally
        S.Free;
      end;
  if Assigned(OnAfterDispatchImage) then
    if GetImageRequestParams(S) then
      try
        OnAfterDispatchImage(Self, AObject, S);
      finally
        S.Free;
      end;
end;

procedure TCustomAdapterDispatcher.DoAdapterRequestNotHandled(AObject: TObject; var AHandled: Boolean);
var
  S: TStrings;
begin
  if GetActionRequestParams(S) then
  try
    if Assigned(OnActionRequestNotHandled) then
      OnActionRequestNotHandled(Self, AObject, nil, AHandled);
    // If the above event handled problem, then don't call the other event
    if not AHandled and Assigned(OnImageRequestNotHandled) then
      OnImageRequestNotHandled(Self, AObject, S, AHandled);
  finally
    S.Free;
  end
  else
    if Assigned(OnActionRequestNotHandled) then    // no params available in this case
      OnActionRequestNotHandled(Self, AObject, nil, AHandled);
end;

function TCustomAdapterDispatcher.ImplHandleRequest(
  Request: TWebRequest; Response: TWebResponse): Boolean;
var
  DispatchParams: TAdapterDispatchParams;
  Obj: TObject;
  Handler: IAdapterRequestHandler;
  Intf: IUnknown;
begin
  Result := False;
  DispatchParams := GetDispatchParams(Request);
  Intf := DispatchParams;
  if (DispatchParams <> nil) and (DispatchParams.ObjectIdentifier <> '') then
  begin
    Obj := DispatchParams.Handler;
    if Supports(Obj, IAdapterRequestHandler, Handler) then
    begin
      Handler.CreateRequestContext(DispatchParams);
      DoBeforeDispatchAdapterRequest(Obj, Result);
      if not Result then
      begin
        Result := Handler.HandleRequest(DispatchParams);
        DoAfterDispatchAdapterRequest(Obj);
      end;
      if not Result then
      begin
        DoAdapterRequestNotHandled(Obj, Result);
        if not Result then
          RaiseAdapterRequestNotHandled(DispatchParams);
      end;
    end
    else
      if Obj = nil then
      begin
        DoAdapterRequestNotHandled(Obj, Result);
        if not Result then
          RaiseAdapterRequestNotHandled(DispatchParams);
      end
      else
        Assert(False, 'Interface not supported');
  end;
end;

// Find first page name of the first webpage (if any) registered
// with the application module
function FindDefaultAppModulePageName: string;
var
  Obj: TComponent;
  PageInfo: TAbstractWebPageInfo;
begin
  Result := '';
  Obj := WebContext.FindApplicationModule(nil);
  if Obj <> nil then
    if WebContext.FindDefaultPageInfo(TComponentClass(Obj.ClassType), PageInfo) then
      Result := PageInfo.PageName
end;

function FindDefaultAppPageName: string;
var
  GetIntf: IGetWebAppComponents;
  AppModule: TComponent;
begin
  Result := '';
  AppModule := WebContext.FindApplicationModule(nil);
  if Supports(IUnknown(AppModule), IGetWebAppComponents, GetIntf) then
    if GetIntf.GetPageDispatcher <> nil then
      Result := GetIntf.GetPageDispatcher.DefaultPageName;
  if Result = '' then
    Result := FindDefaultAppModulePageName;
end;

{ TCustomPageDispatcher }

function TCustomPageDispatcher.DispatchPageName(
  const APageName: string; AResponse: TWebResponse;
    AFlags: TDispatchPageFlags): Boolean;
begin
  Result := ImplDispatchPageName(APageName, AResponse, AFlags);
end;

function TCustomPageDispatcher.ImplDispatchPageName(const APageName: string; AResponse: TWebResponse;
  AFlags: TDispatchPageFlags): Boolean;
var
  Page: string;
  PageComponent: TObject;
  Intf: IPageResult;
begin
  Result := False;
  if APageName = '' then
    Page := FindDefaultAppModulePageName
  else
    Page := APageName;
  if Assigned(OnBeforeDispatchPage) then
    OnBeforeDispatchPage(Self, Page, Result);
  if not Result then
    if Page <> '' then
    begin
      WebContext.RequestedPageName := Page;
      if ValidatePage(Page, Result) then
      begin
        PageComponent := GetRequestedPage(Page, AFlags);
        if PageComponent <> nil then
        begin
          if not Supports(PageComponent, IPageResult, Intf) then
            RaisePageDoesNotProvideContent(APageName);
          Result := Intf.DispatchPage(Page, AResponse);
          if Assigned(OnAfterDispatchPage) then
            OnAfterDispatchPage(Self, Page);
        end
        else
        begin
          if Assigned(OnPageNotFound) then
             OnPageNotFound(Self, Page, Result);
          if not Result then
            RaisePageNotFound(APageName);
        end;
      end;
    end;
end;

function TCustomPageDispatcher.ImplGetDefaultPageName: string;
begin
  Result := DefaultPage;
end;

function TCustomPageDispatcher.GetDefaultPageName: string;
begin
  Result := ImplGetDefaultPageName;
end;

function TCustomPageDispatcher.ImplHandleRequest(
  Request: TWebRequest; Response: TWebResponse): Boolean;
var
  Page: string;
begin
  Page := PageNameOfRequest(Request);
  if Page = '' then
    if DefaultPage <> '' then
      Page := GetDefaultPageName
    else
      Page := FindDefaultAppModulePageName;
  Result := Self.DispatchPageName(Page, Response, [dpPublished]);
end;

function TCustomPageDispatcher.GetRequestedPage(const APageName: string;
  AFlags: TDispatchPageFlags): TObject;
var
  FindOptions: TFindPageOptions;
begin
  Assert(WebContext <> nil, 'Null WebContext');
  if dpPublished in AFlags then
    FindOptions := [fpPublished]
  else
    FindOptions := [];
  if (APageName <> '') and WebContext.FindPage(APageName, FindOptions, Result) then
    Exit
  else
    Result := nil;
end;

function TCustomPageDispatcher.PageNameOfRequest(Request: TWebRequest): string;
begin
  Result := ImplPageNameOfRequest(Request);
end;

function TCustomPageDispatcher.ImplPageNameOfRequest(Request: TWebRequest): string;
var
  Page: string;
  P: Integer;
begin
  Request := WebContext.Request;
  Page := Request.InternalPathInfo;
  P := Pos('?', Page);
  if P <> 0 then
    Delete(Page, P, MaxInt);
  if Page <> '' then
    if Page[Length(Page)] = '/' then
      Delete(Page, Length(Page), 1);
  if Page <> '' then
    if Page[1] = '/' then
      Delete(Page, 1, 1);

  Result := Page;
end;

function TCustomPageDispatcher.ValidatePage(const APage: string;
  var AHandled: Boolean): Boolean;
begin
  AHandled := False;
  Result := True;
  if (not IsLoggedIn) and GetLoginRequired(APage) then
  begin
    Result := False;
    if Assigned(OnPageAccessDenied) then
      OnPageAccessDenied(Self, APage, adLoginRequired, AHandled);
    if not AHandled then
      AHandled := ProduceLoginPage;
  end;
  if Result then
  begin
    Result := GetCanView(APage);
    if not Result then
      if Assigned(OnPageAccessDenied) then
         OnPageAccessDenied(Self, APage, adCantView, AHandled);
  end;
  if not Result and not AHandled then
    RaisePageAccessDenied;
end;

function TCustomPageDispatcher.IsLoggedIn: Boolean;
begin
  if EndUser <> nil then
    Result := EndUser.LoggedIn
  else
    Result := True;
end;

function TCustomPageDispatcher.ProduceLoginPage: Boolean;
begin
  Result := False;
  if EndUser <> nil then
    Result := EndUser.ProduceLoginPage;
end;

function TCustomPageDispatcher.ImplRedirectToPageName(
  const APageName: string; AParams: TStrings; AResponse: TWebResponse;
  AFlags: TDispatchPageFlags): Boolean;
var
  Page: string;
  PageComponent: TObject;
  Intf: IPageResult;
begin
  Result := False;
  if APageName = '' then
    Page := FindDefaultAppModulePageName
  else
    Page := APageName;
  if Assigned(OnBeforeRedirectToPage) then
    OnBeforeRedirectToPage(Self, Page, AParams, Result);
  if not Result then
    if Page <> '' then
    begin
      // WebContext.RequestedPageName := Page;
      if ValidatePage(Page, Result) then
      begin
        PageComponent := GetRequestedPage(Page, AFlags);
        if PageComponent <> nil then
        begin
          if not Supports(PageComponent, IPageResult, Intf) then
            RaisePageDoesNotProvideContent(APageName);
          Result := Intf.RedirectToPage(Page, AParams, AResponse);
          if Assigned(OnAfterRedirectToPage) then
            OnAfterRedirectToPage(Self, Page);
        end
        else
          if Assigned(OnPageNotFound) then
             OnPageNotFound(Self, Page, Result);
          if not Result then
            RaisePageNotFound(APageName);
      end;
    end;
end;

function TCustomPageDispatcher.RedirectToPageName(
  const APageName: string; AParams: TStrings; AResponse: TWebResponse;
  AFlags: TDispatchPageFlags): Boolean;
begin
  Result := ImplRedirectToPageName(APageName, AParams, AResponse, AFlags);
end;

function TCustomPageDispatcher.GetCanView(
  const APageName: string): Boolean;
begin
  Result := ImplGetCanView(APageName);
end;

function TCustomPageDispatcher.GetLoginRequired(
  const APageName: string): Boolean;
begin
  Result := ImplGetLoginRequired(APageName);
end;

function TCustomPageDispatcher.ImplGetCanView(
  const APageName: string): Boolean;
var
  PageInfo: TAbstractWebPageInfo;
  Handled: Boolean;
begin
  Result := True;
  if APageName <> '' then
  begin
    if Assigned(OnCanViewPage) then
    begin
      Handled := False;
      OnCanViewPage(Self, APageName, Result, Handled);
      if Handled then Exit;
    end;
    if (EndUser <> nil) and WebContext.FindPageInfo(APageName, [], PageInfo) then
      Result := EndUser.HasViewRights(PageInfo.ViewAccess);
  end
end;

function TCustomPageDispatcher.ImplGetLoginRequired(
  const APageName: string): Boolean;
var
  PageInfo: TAbstractWebPageInfo;
begin
  if APageName <> '' then
    Result := WebContext.FindPageInfo(APageName, [fpLoginRequired], PageInfo)
  else
    Result := False;
  if Assigned(OnIsLoginRequired) then
    OnIsLoginRequired(Self, APageName, Result)
end;

{ TCustomLocateFileService }

function TCustomLocateFileService.GetTemplateStream(AComponent: TComponent;
  AFileName: string; out AOwned: Boolean): TStream;
begin
  Result := ImplGetTemplateStream(AComponent, AFileName, AOwned);
end;

function TCustomLocateFileService.FindTemplateFile(AComponent: TComponent;
  const AFileName: string; var AResult: string): Boolean;
begin
  AResult := '';
  Result := False;
  if Assigned(OnFindTemplateFile) then
  begin
    Result := True;
    OnFindTemplateFile(Self, AComponent, AFileName, AResult, Result);
    if AResult = '' then
      Result := False;
  end
end;

function TCustomLocateFileService.FindStream(AComponent: TComponent; const AFileName: string; out AResult: TStream; out AOwned: Boolean): Boolean;
begin
  if Assigned(OnFindStream) then
  begin
    Result := True;
    AResult := nil;
    AOwned := True;
    OnFindStream(Self, AComponent, AFileName, AResult, AOwned, Result)
  end
  else
    Result := False;
end;

function TCustomLocateFileService.GetFileStream(const AFileName: string; out AOwned: Boolean): TStream;
begin
  Result := TFileStream.Create(AFileName, fmOpenRead + fmShareDenyWrite);
end;

function TCustomLocateFileService.ImplGetTemplateStream(
  AComponent: TComponent; AFileName: string; out AOwned: Boolean): TStream;
var
  F: string;
begin
  if FindStream(AComponent, AFileName, Result, AOwned) then
    Exit
  else if FindTemplateFile(AComponent, AFileName, F) then
    Result := GetFileStream(F, AOwned)
  else
    Result := nil;
end;

function TCustomLocateFileService.FindIncludeFile(AComponent: TComponent;
  const AFileName: string; var AResult: string): Boolean;
begin
  Result := ImplFindIncludeFile(AComponent, AFileName, AResult);
end;

function TCustomLocateFileService.ImplFindIncludeFile(
  AComponent: TComponent; const AFileName: string; var AResult: string): Boolean;
begin
  AResult := '';
  Result := False;
  if Assigned(OnFindIncludeFile) then
  begin
    Result := True;
    OnFindIncludeFile(Self, AComponent, AFileName, AResult, Result);
    if AResult = '' then
      Result :=  False;
  end;
end;

{ TMultiModuleWebAppServices }

procedure TMultiModuleWebAppServices.ImplFinishContext;
var
  I: Integer;
begin
  inherited;
  for I := WebModules.ItemCount - 1 downto 0 do
    DoneModule(WebModules[I]);
  Assert(Assigned(FWebContext), 'Null WebContext');
  if Assigned(FWebContext) then
    FreeAndNil(FWebContext);
end;

procedure TMultiModuleWebAppServices.ImplInitContext(
  AWebModuleList: TAbstractWebModuleList; ARequest: TWebRequest;
  AResponse: TWebResponse);
begin
  FRequest := ARequest;
  FResponse := AResponse;
  FWebModules := AWebModuleList;
  // Create WebContext thread variable
  Assert(WebContext=nil);
  FWebContext := CreateContext;
  WebModules.OnModuleAdded := ModuleAdded;
  InitModules;
end;

function TMultiModuleWebAppServices.CreateContext: TAbstractWebContext;
begin
  // Create WebContext thread variable
  Result := TWebContext.Create(WebModules, Request, Response, nil { no session });
end;

procedure TMultiModuleWebAppServices.InitModules;
var
  I: Integer;
begin
  // Traverse in reverse order in case a module is instantiated inside loop
  for I := WebModules.ItemCount - 1 downto 0 do
    InitModule(WebModules[I]);
end;

procedure TMultiModuleWebAppServices.InitModule(AWebModule: TComponent);
var
  NotifyWebActivate: INotifyWebActivate;
  SetAppDispatcher: ISetAppDispatcher;
var
  I: Integer;
  Component: TComponent;
begin
  for I := 0 to AWebModule.ComponentCount - 1 do
  begin
    Component := AWebModule.Components[I];
    if Supports(IUnknown(Component), ISetAppDispatcher, SetAppDispatcher) then
      SetAppDispatcher.SetAppDispatcher(Self);
  end;
  if Supports(IUnknown(AWebModule), INotifyWebActivate, NotifyWebActivate) then
    NotifyWebActivate.NotifyActivate;
end;

procedure TMultiModuleWebAppServices.DoneModule(AWebModule: TComponent);
var
  NotifyWebActivate: INotifyWebActivate;
begin
  if Supports(IUnknown(AWebModule), INotifyWebActivate, NotifyWebActivate) then
    NotifyWebActivate.NotifyDeactivate;
end;

procedure TMultiModuleWebAppServices.ModuleAdded(AWebModule: TComponent);
begin
  InitModule(AWebModule);
end;

procedure TMultiModuleWebAppServices.FinishContext;
begin
  ImplFinishContext;
end;

function TMultiModuleWebAppServices.HandleRequest: Boolean;
begin
  Result := ImplHandleRequest;
end;

function TMultiModuleWebAppServices.ImplHandleRequest: Boolean;
begin
  Assert(False, 'ImplHandleRequest not implemented');
  Result := True;
end;

procedure TMultiModuleWebAppServices.InitContext(
  WebModuleList: TAbstractWebModuleList; Request: TWebRequest;
  Response: TWebResponse);
begin
  ImplInitContext(WebModuleList, Request, Response);
end;

function TMultiModuleWebAppServices.Access_Request: TWebRequest;
begin
  Result := FRequest;
end;

function TMultiModuleWebAppServices.Access_Response: TWebResponse;
begin
  Result := FResponse;
end;

function TMultiModuleWebAppServices.DoAfterDispatch(Request: TWebRequest;
  Response: TWebResponse): Boolean;
begin
  Result := True;
  if Assigned(OnAfterDispatch) then
    OnAfterDispatch(Self, Request, Response, Result);
end;

function TMultiModuleWebAppServices.DoBeforeDispatch(
  Request: TWebRequest; Response: TWebResponse): Boolean;
begin
  Result := False;
  if Assigned(OnBeforeDispatch) then
    OnBeforeDispatch(Self, Request, Response, Result);
end;

function TMultiModuleWebAppServices.GetExceptionHandler: TObject;
begin
  Result := Self;
end;

procedure TMultiModuleWebAppServices.HandleException(E: Exception; var Handled: Boolean);
begin
  ImplHandleException(E, Handled);
end;

procedure TMultiModuleWebAppServices.ImplHandleException(E: Exception; var Handled: Boolean);
begin
  Assert(False, 'ImplHandleException not implemented');
end;

{ TCustomWebAppComponents }

procedure TCustomWebAppComponents.ImplFinishContext;
var
  Intf: IMultiModuleSupport;
begin
  if FDispatchActions <> nil then
    if Supports(IUnknown(FDispatchActions), IMultiModuleSupport, Intf) then
      Intf.FinishContext;
  inherited;
  FSession.UpdateResponse(Response);
  if not Response.Sent then
    Response.SendResponse;
  FreeAndNil(FSession);
end;

function TCustomWebAppComponents.ExceptionAsContent(E: Exception): string;
var
  PathInfo: string;
begin
  if E is EScriptError then
    Result := ExpandScriptException(EScriptError(E))
  else
    Result := E.Message;
  if Request <> nil then
    PathInfo := Request.PathInfo;
  Result := Format(sInternalApplicationError, [Result, PathInfo]);
end;

function ExpandScriptException(E: EScriptError): string;
var
  I: Integer;
  SourceLine: string;
begin
  Result := '';
  if (E.Errors = nil) or (E.Errors.Count = 0) then
  begin
    Result := E.message;
    Exit;
  end;
  for I := 0 to E.Errors.Count - 1 do
  begin
    SourceLine := Copy(E.Errors[I].SourceLine, 1, E.Errors[I].CharPos);
    SourceLine := StringReplace(SourceLine, '<', '&lt;', [rfReplaceAll]);       { do not localize }
    SourceLine := StringReplace(SourceLine, '>', '&gt;', [rfReplaceAll]);       { do not localize }
    SourceLine := SourceLine + '<font color="#FF0000">|</font>' +               { do not localize }
        StringReplace(
          StringReplace(Copy(E.Errors[I].SourceLine,
              E.Errors[I].CharPos + 1,
              Length(E.Errors[I].SourceLine) -
                E.Errors[I].CharPos - 1),
              '<', '&lt;', [rfReplaceAll]),                                     { do not localize }
          '>', '&gt;', [rfReplaceAll]);                                         { do not localize }

    Result := Result + Format(sScriptErrorTemplate,
    [I,
     E.Errors[I].Description,
     E.Errors[I].Line,
     E.Errors[I].CharPos,
     SourceLine]);
 end;
end;

procedure TCustomWebAppComponents.ImplHandleException(E: Exception; var Handled: Boolean);
begin
  Handled := False;
  if Assigned(OnException) then
  begin
    Handled := True;
    try
      OnException(Self, E, Handled);
    except
      Handled := True;
      Response.Content := ExceptionAsContent(E);
    end;
  end;
  if not Handled then
    if Response <> nil then
    begin
      Response.Content := ExceptionAsContent(E);
      Handled := True;
    end;
end;

function TCustomWebAppComponents.CreateContext: TAbstractWebContext;
begin
  CheckSessionsStatus(False);
  try
    FSession := TWebSession.Create(FSessions, Request, Response);
  except
    on E: Exception do
      FSession := TInvalidWebSession.Create(E.Message);
  end;
  // Create WebContext thread variable
  Result := TWebContext.Create(WebModules, Request, Response, FSession);
end;

procedure TCustomWebAppComponents.InitModules;
begin
  inherited;
  CheckSessionsStatus;
end;

procedure TCustomWebAppComponents.SetSessions(const Value: ISessionsService);
begin
  ReferenceInterface(FSessions, opRemove);
  FSessions := Value;
  ReferenceInterface(FSessions, opInsert);
end;

procedure TCustomWebAppComponents.CheckSessionsStatus(ANotify: Boolean);
var
  Intf: ISessionsService;
begin
  if Supports(IUnknown(FSessions), ISessionsService, Intf) then
     if Intf.CheckStatusChange and ANotify then
       Intf.NotifyStatusChange;
end;

procedure TCustomWebAppComponents.Notification(AComponent: TComponent;
  Operation: TOperation);
var
  Intf: IUnknown;
begin
  inherited;
  if Operation = opRemove then
  begin
    if AComponent.IsImplementorOf(FDispatchActions) then FDispatchActions := nil;
    if AComponent.IsImplementorOf(FSessions) then FSessions := nil;
    if AComponent.IsImplementorOf(FApplicationAdapter) then FApplicationAdapter := nil;
    if AComponent.IsImplementorOf(FLocateFileService) then FLocateFileService := nil;
    if AComponent.IsImplementorOf(FPageDispatcher) then FPageDispatcher := nil;
    if AComponent.IsImplementorOf(FAdapterDispatcher) then FAdapterDispatcher := nil;
    if AComponent.IsImplementorOf(FEndUserAdapter) then FEndUserAdapter := nil;
    if AComponent.IsImplementorOf(FUserListService) then FUserListService := nil;
  end;
  if (Operation = opInsert) and not (csLoading in ComponentState) then
  begin
    if (FDispatchActions = nil) and Supports(AComponent, IWebDispatchActions, Intf) then
      DispatchActions := AComponent as IWebDispatchActions;
    if (FSessions = nil) and Supports(AComponent, ISessionsService, Intf) then
      Sessions := AComponent as ISessionsService;
    if (FApplicationAdapter = nil) and Supports(AComponent, IWebApplicationInfo, Intf) then
      ApplicationAdapter := AComponent as IWebApplicationInfo;
    if (FLocateFileService = nil) and Supports(AComponent, ILocateFileService, Intf) then
      LocateFileService := AComponent as ILocateFileService;
    if (FPageDispatcher = nil) and Supports(AComponent, IPageDispatcher, Intf) then
      PageDispatcher := AComponent as IPageDispatcher;
    if (FAdapterDispatcher = nil) and Supports(AComponent, IAdapterDispatcher, Intf) then
      AdapterDispatcher := AComponent as IAdapterDispatcher;
    if (FEndUserAdapter = nil) and Supports(AComponent, IWebEndUser, Intf) then
      EndUserAdapter := AComponent as IWebEndUser;
    if (FUserListService = nil) and Supports(AComponent, IWebUserList, Intf) then
      UserListService := AComponent as IWebUserList;
  end;
end;

procedure TCustomWebAppComponents.SetLocateFileService(const Value: ILocateFileService);
begin
  ReferenceInterface(FLocateFileService, opRemove);
  FLocateFileService := Value;
  ReferenceInterface(FLocateFileService, opInsert);
end;

function TCustomWebAppComponents.GetLocateFileService: ILocateFileService;
begin
  Result := FLocateFileService;
end;

procedure TCustomWebAppComponents.SetDispatcher(const Value: IWebDispatchActions);
begin
  ReferenceInterface(FDispatchActions, opRemove);
  FDispatchActions := Value;
  ReferenceInterface(FDispatchActions, opInsert);
end;

procedure TCustomWebAppComponents.SetAdapterDispatcher(
  const Value: IAdapterDispatcher);
begin
  ReferenceInterface(FAdapterDispatcher, opRemove);
  FAdapterDispatcher := Value;
  ReferenceInterface(FAdapterDispatcher, opInsert);
end;

procedure TCustomWebAppComponents.SetPageDispatcher(
  const Value: IPageDispatcher);
begin
  ReferenceInterface(FPageDispatcher, opRemove);
  FPageDispatcher := Value;
  ReferenceInterface(FPageDispatcher, opInsert);
end;

procedure TCustomWebAppComponents.SetApplicationAdapter(const Value: IWebApplicationInfo);
begin
  ReferenceInterface(FApplicationAdapter, opRemove);
  FApplicationAdapter := Value;
  ReferenceInterface(FApplicationAdapter, opInsert);
end;

procedure TCustomWebAppComponents.SetEndUserAdapter(const Value: IWebEndUser);
begin
  ReferenceInterface(FEndUserAdapter, opRemove);
  FEndUserAdapter := Value;
  ReferenceInterface(FEndUserAdapter, opInsert);
end;

procedure TCustomWebAppComponents.SetUserListService(const Value: IWebUserList);
begin
  ReferenceInterface(FUserListService, opRemove);
  FUserListService := Value;
  ReferenceInterface(FUserListService, opInsert);
end;

function TCustomWebAppComponents.GetAdapterDispatcher: IAdapterDispatcher;
begin
  if (FAdapterDispatcher = nil) or
    not Supports(IUnknown(FAdapterDispatcher), IAdapterDispatcher, Result) then
    Result := nil;
end;

function TCustomWebAppComponents.GetPageDispatcher: IPageDispatcher;
begin
  if not Supports(IUnknown(FPageDispatcher), IPageDispatcher, Result) then
    Result := nil;
end;

procedure TCustomWebAppComponents.ListRequestHandlers(L: IInterfaceList);
begin
  L.Add(FAdapterDispatcher);
  L.Add(FDispatchActions);
  L.Add(FPageDispatcher);
end;

function TCustomWebAppComponents.ImplHandleRequest: Boolean;

  function InvokeRequestHandler(AIntf: IInterface): Boolean;
  var
    Intf: IWebRequestHandler;
  begin
    Result := False;
    if Supports(AIntf, IWebRequestHandler, Intf) then
      Result := Intf.HandleRequest(Request, Response)
    else
      Assert(False, 'Expect support for IWebRequestHandler');
  end;

var
  L: IInterfaceList;
  I: Integer;
begin
  Result := DoBeforeDispatch(Request, Response) or Response.Sent;
  if not Result then
  begin
    L := TInterfaceList.Create;
    ListRequestHandlers(L);
    for I := 0 to L.Count - 1 do
    begin
      if L[I] <> nil then
        Result := InvokeRequestHandler(L[I]);
      if Result then break;
    end;
  end;
  if Result and not Response.Sent then
    Result := DoAfterDispatch(Request, Response);
  if not Result then
    raise EWebBrokerException.Create(sNoHandler);
end;

procedure TCustomWebAppComponents.InitModule(AModule: TComponent);
var
  Intf: IMultiModuleSupport;
begin
  inherited;
  if FDispatchActions <> nil then
    if Supports(IUnknown(FDispatchActions), IMultiModuleSupport, Intf) then
      Intf.InitModule(AModule);
end;

procedure TCustomWebAppComponents.ImplInitContext(
  AWebModuleList: TAbstractWebModuleList; ARequest: TWebRequest;
  AResponse: TWebResponse);
var
  Intf: IMultiModuleSupport;
begin
  if FDispatchActions <> nil then
    if Supports(IUnknown(FDispatchActions), IMultiModuleSupport, Intf) then
      Intf.InitContext(ARequest, AResponse);
  inherited;
end;

function TCustomWebAppComponents.GetWebApplicationInfo: IWebApplicationInfo;
begin
  if (FApplicationAdapter = nil) or
    not Supports(IUnknown(FApplicationAdapter), IWebApplicationInfo, Result) then
    Result := nil;
end;

function TCustomWebAppComponents.GetWebEndUser: IWebEndUser;
begin
  if (FEndUserAdapter = nil) or
    not Supports(IUnknown(FEndUserAdapter), IWebEndUser, Result) then
    Result := nil;
end;

function TCustomWebAppComponents.GetWebUserList: IWebUserList;
begin
  if (FUserListService = nil) or
    not Supports(IUnknown(FUserListService), IWebUserList, Result) then
    Result := nil;
end;

{ TBaseRequestHandler }

function TBaseRequestHandler.HandleRequest(ARequest: TWebRequest;
  AResponse: TWebResponse): Boolean;
begin
  Result := ImplHandleRequest(ARequest, AResponse);
end;

function TBaseRequestHandler.ImplHandleRequest(ARequest: TWebRequest;
  AResponse: TWebResponse): Boolean;
begin
  Assert(False, 'ImplHandleRequest not implemented');
  Result := True;
end;

procedure TBaseRequestHandler.SetAppDispatcher(
  const AWebAppDispatcher: TComponent);
begin
  FAppDispatcher := AWebAppDispatcher;
end;

{ TAdapterDispatchParams }

constructor TAdapterDispatchParams.Create(ARequest: TWebRequest);

  procedure StoreValues(S: TStrings);
  var
    I: Integer;
    Name: string;
  begin
    for I := 0 to S.Count - 1 do
    begin
      Name := S.Names[I];
      if SameText(sRequestIDParamName, Name) then
        FObjectIdentifier := ExtractStringValue(S[I])
      else if SameText(sFailurePageParamName, Name) then
        FFailurePage := ExtractStringValue(S[I])
      else if SameText(sSuccessPageParamName, Name) then
        FSuccessPage := ExtractStringValue(S[I])
      else if SameText(sPageParamName, Name) then
      begin
        FFailurePage := ExtractStringValue(S[I]);
        FSuccessPage := ExtractStringValue(S[I])
      end
      else
        FParams.Add(S[I]);
    end;
  end;

var
  Value: string;
  I: Integer;
  Request: TWebRequest;
  Identifier: string;
  HaveRequest: Boolean;
  S: TStrings;
begin
  Request := WebContext.Request;
  HaveRequest := False;
  FParams := TStringList.Create;
  if Request.QueryFields.Values[sRequestIDParamName] <> '' then
  begin
    HaveRequest := True;
    StoreValues(Request.QueryFields);
  end
  else if RegisteredRequestIdentifiers <> nil then
    for I := 0 to RegisteredRequestIdentifiers.Count - 1 do
    begin
      FRequestIdentifier := RegisteredRequestIdentifiers[I];
      Identifier := FRequestIdentifier;
      Value := Request.ContentFields.Values[FRequestIdentifier];
      if Value <> '' then
      begin
        HaveRequest := True;
        S := TStringList.Create;
        try
          ExtractParamNameValues(Value, S);
          StoreValues(S);
        finally
          S.Free;
        end;
      end;
      if not HaveRequest then
      begin
        Value := Request.QueryFields.Values[Identifier];
        if Value <> '' then
        begin
          HaveRequest := True;
          S := TStringList.Create;
          try
            ExtractParamNameValues(Value, S);
            StoreValues(S);
          finally
            S.Free;
          end;
        end;
      end;
      if HaveRequest then break;
    end;
  if FObjectIdentifier = '' then HaveRequest := False;
  if not HaveRequest then
  begin
    FObjectIdentifier := '';
    FRequestIdentifier := '';
  end;
end;

destructor TAdapterDispatchParams.Destroy;
begin
  FParams.Free;
  inherited;
end;

function TAdapterDispatchParams.GetFailurePage: string;
begin
  Result := FFailurePage;
end;

function TAdapterDispatchParams.GetHandler: TObject;
var
  Lookup: TVariableLookup;
begin
  if FHandler = nil then
  begin
    if ObjectIdentifier <> '' then
    begin
      Lookup := TVariableLookup.Create(ObjectIdentifier, nil { app global context });
      try
        FHandler := Lookup.Obj;
     finally
        Lookup.Free;
      end;
    end;
  end;
  Result := FHandler;
end;

function TAdapterDispatchParams.GetObjectIdentifier: string;
begin
  Result := FObjectIdentifier;
end;

function TAdapterDispatchParams.GetParams: TStrings;
begin
  Result := FParams;
end;

function TAdapterDispatchParams.GetRequestIdentifier: string;
begin
  Result := FRequestIdentifier;
end;

function TAdapterDispatchParams.GetSuccessPage: string;
begin
  Result := FSuccessPage;
end;

{ TAdapterItemRequestParams }

constructor TAdapterItemRequestParams.Create;
begin
  FParamValues := TStringList.Create;
  inherited;
end;

destructor TAdapterItemRequestParams.Destroy;
begin
  inherited;
  FParamValues.Free;
end;

function TAdapterItemRequestParams.GetFailurePage: string;
begin
  Result := FFailurePage;
end;

function TAdapterItemRequestParams.GetParamValues: TStrings;
begin
  Result := FParamValues;
end;

function TAdapterItemRequestParams.GetSuccessPage: string;
begin
  Result := FSuccessPage;
end;

procedure TAdapterItemRequestParams.SetFailurePage(const AValue: string);
begin
  FFailurePage := AValue;
end;

procedure TAdapterItemRequestParams.SetSuccessPage(const AValue: string);
begin
  FSuccessPage := AValue;
end;

{ TWebSession }

constructor TWebSession.Create(ASessions: ISessionsService; AWebSession: IWebSession);
begin
  FSessions := ASessions;
  FWebSession := AWebSession;
  inherited Create;
end;

constructor TWebSession.Create(ASessions: ISessionsService; AID: TSessionID);
var
  Intf: ISessionsServiceConnectID;
begin
  FSessions := ASessions;
  inherited Create;
  if Assigned(ASessions) then
    if Supports(ASessions, ISessionsServiceConnectID, Intf) then
      FWebSession := Intf.Connect(AID);
end;

constructor TWebSession.Create(ASessions: ISessionsService; ARequest: TWebRequest; AResponse: TWebResponse);
var
  Intf: ISessionsService;
begin
  FSessions := ASessions;
  if Assigned(FSessions) then
    if Supports(FSessions, ISessionsService, Intf) then
      ReadSessionIDFromStore(Intf, ARequest, AResponse);
  inherited Create;
end;

function TWebSession.GetValue(const AName: string): Variant;
var
  Intf: IWebSessionValues;
begin
  if Assigned(FWebSession) then
    if Supports(FWebSession, IWebSessionValues, Intf) then
    begin
      Result := Intf.Values[AName];
      Exit;
    end;
  Result := '';
end;

procedure TWebSession.ReadSessionIDFromStore(ASessionsService: ISessionsService; ARequest: TWebRequest; AResponse: TWebResponse);
var
  Intf: ISessionsServiceConnectID;
  ID: TSessionID;
  SessionsServiceStoreID: ISessionsServiceStoreID;
  HaveID: Boolean;
begin
  if Assigned(ASessionsService) then
  begin
    if Supports(ASessionsService, ISessionsServiceStoreID, SessionsServiceStoreID) then
      HaveID := SessionsServiceStoreID.ReadSessionID(ARequest, AResponse, ID)
    else
      HaveID := ReadSessionCookie(ARequest, AResponse, ID);
    if HaveID then
      try
        if Supports(ASessionsService, ISessionsServiceConnectID, Intf) then
          FWebSession := Intf.ConnectActive(ID);
      except
      end;
    if FWebSession = nil then
      FWebSession := ASessionsService.NewSession;
  end;
end;

function TWebSession.ReadSessionCookie(ARequest: TWebRequest; AResponse: TWebResponse; out AID: TSessionID): Boolean;
begin
  if ARequest.CookieFields.Values[sSessionCookieName] <> '' then
  begin
    Result := True;
    AID := ARequest.CookieFields.Values[sSessionCookieName];
  end
  else
    Result := False;
  WriteSessionCookie(AResponse, '');
end;

procedure TWebSession.SetValue(const AName: string; const AValue: Variant);
var
  Intf: IWebSessionValues;
begin
  if Assigned(FWebSession) then
    if Supports(FWebSession, IWebSessionValues, Intf) then
    begin
      Intf.Values[AName] := AValue;
      Exit;
    end;
end;

procedure TWebSession.Terminate;
var
  Intf: ISessionsService;
begin
  if Assigned(FWebSession) then
  begin
    // Clear out pending notifications
    if Assigned(FSessions) then
      if Supports(FSessions, ISessionsService, Intf) then
        Intf.NotifyStatusChange;
    FWebSession.Terminate;
    FWebSession := nil;
    if Intf <> nil then
    begin
      FWebSession := Intf.NewSession;
      Intf.NotifyStatusChange;
    end;
  end;
end;

procedure TWebSession.WriteSessionIDToStore(AResponse: TWebResponse; const AValue: string);
var
  SessionsServiceStoreID: ISessionsServiceStoreID;
begin
  if Supports(FWebSession, ISessionsServiceStoreID, SessionsServiceStoreID) then
    SessionsServiceStoreID.WriteSessionID(AResponse, AValue)
  else
    WriteSessionCookie(AResponse, AValue);
end;

procedure TWebSession.WriteSessionCookie(AResponse: TWebResponse; const AValue: string);
var
  I: Integer;
begin
  for I := 0 to AResponse.Cookies.Count - 1 do
    with AResponse.Cookies[I] do
      if SameText(Name, sSessionCookieName) then
      begin
        Value := AValue;
        exit;
      end;
  with AResponse.Cookies.Add do
  begin
    Name := sSessionCookieName;
    Path := AResponse.HTTPRequest.InternalScriptName;
    Value := AValue;
    Expires := -1;
  end;
end;

procedure TWebSession.UpdateResponse(AResponse: TWebResponse);
var
  GetAttributes: IWebSessionAttributes;
  GetID: IWebSessionID;
begin
  if Assigned(FWebSession) then
  begin
    if Supports(FWebsession, IWebSessionAttributes, GetAttributes) then
    begin
      if GetAttributes.IsActive then
      begin
        if Supports(FWebSession, IWebSessionID, GetID) then
          WriteSessionIDToStore(AResponse, GetID.ID)
      end
      else
      begin
        WriteSessionIDToStore(AResponse, '');
      end;
    end;
  end;
end;

function TWebSession.GetTimeoutMinutes: Integer;
var
  Intf: IWebSessionAttributes;
begin
  Result := 0;
  if Assigned(FWebSession) then
    if Supports(FWebSession, IWebSessionAttributes, Intf) then
      Result := Intf.TimeoutMinutes;
end;

procedure TWebSession.SetTimeoutMinutes(AValue: Integer);
var
  Intf: IWebSessionAttributes;
begin
  if Assigned(FWebSession) then
    if Supports(FWebSession, IWebSessionAttributes, Intf) then
      Intf.TimeoutMinutes := AValue;
end;

function TWebSession.GetSessionID: string;
var
  Intf: IWebSessionID;
begin
  if Assigned(FWebSession) then
    if Supports(FWebSession, IWebSessionID, Intf) then
      Result := Intf.ID;
end;

function TWebSession.GetSessionsService: ISessionsService;
begin
  Result := FSessions;
end;

function TWebSession.GetWebSession: IWebSession;
begin
  Result := FWebSession;
end;

function TWebSession.QueryInterface(const IID: TGUID; out Obj): HResult;
begin
  if GetInterface(IID, Obj) then Result := S_OK
  else Result := E_NOINTERFACE
end;

function TWebSession._AddRef: Integer;
begin
  Result := -1;
end;

function TWebSession._Release: Integer;
begin
  Result := -1   // -1 indicates no reference counting is taking place
end;

{ TInvalidWebSession }

constructor TInvalidWebSession.Create(const AMsg: string);
begin
  FMsg := AMsg;
  inherited Create;
end;

function TInvalidWebSession.GetSessionID: string;
begin
  RaiseInvalidWebSession;

end;

function TInvalidWebSession.GetTimeoutMinutes: Integer;
begin
  RaiseInvalidWebSession;
  Result := 0;
end;

function TInvalidWebSession.GetValue(const AName: string): Variant;
begin
  RaiseInvalidWebSession;
end;

procedure TInvalidWebSession.SetTimeoutMinutes(AValue: Integer);
begin
  RaiseInvalidWebSession;
end;

procedure TInvalidWebSession.SetValue(const AName: string;
  const AValue: Variant);
begin
  RaiseInvalidWebSession;
end;

procedure TInvalidWebSession.Terminate;
begin
  RaiseInvalidWebSession;
end;

procedure TInvalidWebSession.UpdateResponse(AResponse: TWebResponse);
begin
  // Do nothing
end;

procedure TInvalidWebSession.RaiseInvalidWebSession;
begin
  raise ESessionException.Create(FMsg);
end;

initialization
finalization
  FreeAndNil(RegisteredRequestIdentifiers);
end.

