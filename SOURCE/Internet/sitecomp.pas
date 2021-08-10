{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{ Copyright (c) 2000-2001 Borland Software Corporation  }
{                                                       }
{*******************************************************}

unit SiteComp;

interface

uses
  Classes,
  WebComp,
  HTTPApp,
  WebContnrs,
  ComObj,
  HTTPProd,
  WebCntxt;

type

  IWebApplicationInfo = interface
  ['{B2E0A3B9-6FA7-11D4-A4B8-00C04F6BB853}']
    function GetApplicationTitle: string;
    function GetApplicationAdapter: TComponent;
    property ApplicationTitle: string read GetApplicationTitle;
    property ApplicationAdapter: TComponent read GetApplicationAdapter;
  end;

  IDefaultPageFileName = interface
  ['{7F76F283-065E-11D4-A43E-00C04F6BB853}']
    procedure SetDefaultPageFileName(const APageFile: string);
  end;

  IGetDefaultAction = interface
  ['{F8094BDD-3DBB-445C-805B-80D68624BAD4}']
    function GetDefaultAction: TComponent;
    property DefaultAction: TComponent read GetDefaultAction;
  end;

  TDispatchPageFlag = (dpPublished);
  TDispatchPageFlags = set of TDispatchPageFlag;
  IPageDispatcher = interface(IWebRequestHandler)
  ['{C9FD165A-8F1C-11D4-A4E4-00C04F6BB853}']
    function GetDefaultPageName: string;
    function DispatchPageName(const APageName: string; AResponse: TWebResponse;
      AFlags: TDispatchPageFlags): Boolean;
    function RedirectToPageName(const APageName: string; AParams: TStrings; AResponse: TWebResponse;
      AFlags: TDispatchPageFlags): Boolean;
    function PageNameOfRequest(ARequest: TWebRequest): string;
    function GetLoginRequired(const APageName: string): Boolean;
    function GetCanView(const APageName: string): Boolean;
    property DefaultPageName: string read GetDefaultPageName;
  end;

  TAdapterItemRequestParamOption = (roExcludeID);
  TAdapterItemRequestParamOptions = set of TAdapterItemRequestParamOption;

  IAdapterItemRequestParams = interface
  ['{AB707788-9328-45B7-B071-8A785610474F}']
    procedure SetSuccessPage(const AValue: string);
    procedure SetFailurePage(const AValue: string);
    function GetSuccessPage: string;
    function GetFailurePage: string;
    function GetParamValues: TStrings;
    property SuccessPage: string read GetSuccessPage write SetSuccessPage;
    property FailurePage: string read GetFailurePage write SetFailurePage;
    property ParamValues: TStrings read GetParamValues;
  end;

  IAdapterDispatcher = interface(IWebRequestHandler)
  ['{C9FD1655-8F1C-11D4-A4E4-00C04F6BB853}']
    function EncodeAdapterItemRequestAsHREF(AHandler: IUnknown;
      AOptions: TAdapterItemRequestParamOptions): string;
    function EncodeAdapterItemRequestAsFieldValue(AHandler: IUnknown;
      AOptions: TAdapterItemRequestParamOptions): string;
    procedure GetAdapterItemRequestParams(AHandler: IUnknown;
      AOptions: TAdapterItemRequestParamOptions; AParams: IAdapterItemRequestParams);
  end;

  IPageResult = interface
  ['{608D1F61-F223-4574-89F7-F29A73372FFC}']
    function DispatchPage(const APageName: string; AWebResponse: TWebResponse): Boolean;
    function IncludePage(const APageName: string; var AOwned: Boolean): TStream;
    function RedirectToPage(const APageName: string; AParams: TStrings; AWebResponse: TWebResponse): Boolean;
  end;

  IAdapterDispatchParams = interface
  ['{87018D80-0450-4CAB-BE8C-58F54040BCEB}']
    function GetRequestIdentifier: string;
    function GetObjectIdentifier: string;
    function GetParams: TStrings;
    function GetHandler: TObject;
    property RequestIdentifier: string read GetRequestIdentifier;
    property ObjectIdentifier: string read GetObjectIdentifier;
    property Params: TStrings read GetParams;
    property Handler: TObject read GetHandler;
  end;

  IAdapterRequestHandler = interface
  ['{48C27474-2E1F-4797-9E72-AFA6CE42F826}']
    procedure CreateRequestContext(DispatchParams: IAdapterDispatchParams);
    function HandleRequest(DispatchParams: IAdapterDispatchParams): Boolean;
  end;

  IGetAdapterItemRequestParams = interface
  ['{14D978F5-D1E9-11D4-A532-00C04F6BB853}']
    procedure GetAdapterItemRequestParams(var AIdentifier: string; AParams: IAdapterItemRequestParams);
  end;

  IGetAdapterRequestDefaultResponse = interface
  ['{14D978F4-D1E9-11D4-A532-00C04F6BB853}']
    function GetSuccessPage: string;
    function GetFailurePage: string;
    property SuccessPage: string read GetSuccessPage;
    property FailurePage: string read GetFailurePage;
  end;

  IWebFormComponentContainer = interface
  ['{F7E1CF51-F759-11D3-ABDA-EFF689219731}']
    function GetCount: Integer;
    function GetItem(I: Integer): TComponent;
    property Count: Integer read GetCount;
    property Items[I: Integer]: TComponent read GetItem;
  end;

  IWebUserList = interface
  ['{0877DEAF-AB5D-11D4-A503-00C04F6BB853}']
    function ValidateUser(Strings: TStrings): Variant;
    function CheckAccessRights(UserID: Variant; Rights: string): Boolean;
  end;

  IGetWebAppComponents = interface
  ['{19CD2F0D-E68F-4A6F-92AA-4C7659E83708}']
    function GetLocateFileService: ILocateFileService;
    function GetPageDispatcher: IPageDispatcher;
    function GetAdapterDispatcher: IAdapterDispatcher;
    function GetWebApplicationInfo: IWebApplicationInfo;
    function GetWebEndUser: IWebEndUser;
    function GetWebUserList: IWebUserList;
    property WebEndUser: IWebEndUser read GetWebEndUser;
    property WebApplicationInfo: IWebApplicationInfo read GetWebApplicationInfo;
  end;

  TAbstractDesigntimeWarnings = class
  public
    procedure AddString(AWarning: string); virtual; abstract;
    procedure AddObject(AObject: TObject);  virtual; abstract;
  end;

  IGetDesigntimeWarnings = interface
  ['{20508BF7-A9CE-11D4-A501-00C04F6BB853}']
    procedure GetDesigntimeWarnings(AWarnings: TAbstractDesigntimeWarnings);
  end;

  INotifyList = interface
  ['{0444FED2-835C-4DAD-9C79-49BDC62AFA8A}']
    procedure AddNotify(ANotify: TObject);
    procedure RemoveNotify(ANotify: TObject);
  end;

  INotifyAdapterChange = interface
  ['{442FC843-4F85-4137-8564-FF6EEDBA1465}']
    procedure NotifyAdapterChange(Sender: TComponent);
  end;

  IIteratorSupport = interface
  ['{BDFABA24-F5C3-11D3-ABD8-A00CB821173C}']
    function StartIterator(var OwnerData: Pointer): Boolean;
    function NextIteration(var OwnerData: Pointer): Boolean;
    procedure EndIterator(OwnerData: Pointer);
  end;

  IIteratorIndex = interface
  ['{A6CBA53A-8326-4F7A-BFFE-02A2C6E41B67}']
    function InIterator: Boolean;
    function GetIteratorIndex: Integer;
    property IteratorIndex: Integer read GetIteratorIndex;
  end;

  IIterateObjectSupport = interface(IIteratorSupport)
  ['{76159C52-A181-4F16-B27E-35F7979BE87F}']
    function GetCurrentObject(OwnerData: Pointer): TObject;
  end;

  IIterateIntfSupport = interface(IIteratorSupport)
  ['{064EFCF2-B422-4720-B364-633D28CD3216}']
    function GetCurrentIntf(OwnerData: Pointer): IUnknown;
  end;

  TScriptObject = class(TAutoObject);
  {$EXTERNALSYM TScriptObject}

  TScriptClass = class of TScriptObject;
  {$EXTERNALSYM TScriptClass}

  TScriptComponent = class(TScriptObject, IInterfaceComponentReference)
  private
    FObject: TComponent;
  protected
    { IInterfaceComponentReference }
    function GetComponent: TComponent;
  public
    constructor Create(AObject: TComponent); virtual;
    property Obj: TComponent read FObject;
  end;
  {$EXTERNALSYM TScriptComponent}

  TScriptComponentClass = class of TScriptComponent;

  IGetScriptObject = interface
  ['{CAC16452-9BAD-11D4-A4F2-00C04F6BB853}']
    function GetScriptObject: IDispatch;
  end;

  // Identify a subcomponent container
  IWebContainerSubComponent = interface
  end;

  TSessionID = type string;

  IWebSession = interface
  ['{D2727F50-2399-495C-B2C3-649A3512D087}']
    procedure Terminate;
  end;

  IWebSessionValues = interface
  ['{26F78C60-0D62-42AE-B890-57EF475FB5D3}']
    procedure GetItems(var AItems: TAbstractNamedVariants);
    function GetItemCount: Integer;
    procedure SetValue(const AName: string; const AValue: Variant);
    function GetValue(const AName: string): Variant;
    property Values[const AName: string]: Variant read GetValue write SetValue;
  end;

  IWebSessionID = interface
  ['{FF5D064E-FF1B-480E-BA9D-6B7F8AA4E477}']
    function GetID: TSessionID;
    property ID: TSessionID read GetID;
  end;

  IWebSessionAttributes = interface
  ['{29D2BFB7-4336-4F14-B1FE-417AEC40A12F}']
    function GetStartTime: TDateTime;
    property StartTime: TDateTime read GetStartTime;
    function GetTimeoutMinutes: Integer;
    procedure SetTimeoutMinutes(AValue: Integer);
    property TimeoutMinutes: Integer read GetTimeoutMinutes write SetTimeoutMinutes;
    function GetTouchTime: TDateTime;
    property TouchTime: TDateTime read GetTouchTime;
    function GetExpirationTime: TDateTime;
    property ExpirationTime: TDateTime read GetExpirationTime;
    function GetExpired: Boolean;
    property Expired: Boolean read GetExpired;
    function GetTerminated: Boolean;
    property Terminated: Boolean read GetTerminated;
    function GetIsActive: Boolean;
    property IsActive: Boolean read GetIsActive;
  end;

  ISessionsServiceConnectID = interface
  ['{FA0C1658-726C-47DF-9810-84A207EFCA65}']
    function Connect(AID: TSessionID): IWebSession;
    function ConnectActive(AID: TSessionID): IWebSession;
  end;

  ISessionsServiceStoreID = interface
  ['{2BA89434-8F6B-4119-B700-1D1400E9CC87}']
    function ReadSessionID(ARequest: TWebRequest; AResponse: TWebResponse; out AID: TSessionID): Boolean;
    procedure WriteSessionID(AResponse: TWebResponse; AID: TSessionID);
  end;

  IWebSessionIDs = interface
  ['{CC119E2C-6574-4A59-A3EE-952DB537F76B}']
    function GetIDCount: Integer;
    function GetID(I: Integer): TSessionID;
    property IDCount: Integer read GetIDCount;
    property IDs[I: Integer]: TSessionID read GetID;
  end;

  IWebGetSessionIDs = interface
  ['{6D14F7B1-F503-4B53-B364-2BE7229D33EC}']
    function GetSessionIDs: IWebSessionIDs;
  end;

  ISessionsService = interface
  ['{6EAAC21D-42CF-4486-A8E6-D9C8562BD681}']
    function NewSession: IWebSession;
    procedure Clear;
    function CheckStatusChange: Boolean;
    procedure NotifyStatusChange;
  end;

  ISessionsServicePersist = interface
  ['{6FFA990F-183E-468E-8246-2E1093CEA13D}']
    procedure LoadFromFile(const Filename: string);
    procedure SaveToFile(const Filename: string);
    procedure LoadFromStream(S: TStream);
    procedure SaveToStream(S: TStream);
  end;

  IFindIncludeFile = interface
  ['{93895ECC-E8BA-4F8E-80D0-785D28359932}']
    function FindIncludeFile(AComponent: TComponent; const AFileName: string; var AResult: string): Boolean;
  end;

  TAbstractInetFileType = class(TObject)
  protected
    function GetTypeID: string; virtual; abstract;
    function GetExtCount: Integer;  virtual; abstract;
    function GetFileExt(I: Integer): string;  virtual; abstract;
  public
    property TypeID: string read GetTypeID;
    property FileExtCount: Integer read GetExtCount;
    property FileExt[I: Integer]: string read GetFileExt;
  end;

  IInternetFileTypes = interface
  ['{0257655C-F868-11D4-A55F-00C04F6BB853}']
    function FindFileExt(const AFileExt: string): TAbstractInetFileType;
  end;

  IInternetScriptDebugger = interface
  ['{0257655B-F868-11D4-A55F-00C04F6BB853}']
    procedure DebugScript(AContext: IUnknown);
    function CanDebugScript(AContext: IUnknown): Boolean;
  end;

  IInternetExecuteScript = interface
  ['{0257655E-F868-11D4-A55F-00C04F6BB853}']
    procedure ExecuteScript(AContext: IUnknown);
    function CanExecuteScript(AContext: IUnknown): Boolean;
  end;

  IInternetEnvOptions = interface
  ['{F92A39B5-C7D1-4E10-A67C-AC775042DA0E}']
    function GetDisableDebugging: Boolean;
    function GetHTMLExt: string;
    function GetSampleImageFile: string;
    function GetScriptTimeoutSecs: Integer;
    property DisableDebugger: Boolean read GetDisableDebugging;
    property HTMLExt: string read GetHTMLExt;
    property SampleImageFile: string read GetSampleImageFile;
    property ScriptTimeoutSecs: Integer read GetScriptTimeoutSecs;
  end;

  IIDEFileManager = interface
  ['{B61156EF-7265-43E9-9FAF-D6E1D2EA2075}']
    function SearchFile(const AFileName: string): string;
  end;

  { Adapter interfaces }

  IAdapterError = interface
  ['{27A6D8A1-58E1-11D4-A493-00C04F6BB853}']
    function GetErrorText: string;
    function GetID: integer;
    function GetField: TComponent;
    property ErrorText: string read GetErrorText;
    property ID: integer read GetID;
    property Field: TComponent read GetField;
  end;

  IAdapterHiddenField = interface
  ['{90E9C34B-D054-11D4-A530-00C04F6BB853}']
    function GetName: string;
    function GetValue: string;
    property Name: string read GetName;
    property Value: string read GetValue;
  end;

  IAdapterAccess = interface
  ['{179232C0-CC77-11D4-A52B-00C04F6BB853}']
    function HasViewAccess: Boolean;
    function HasModifyAccess: Boolean;
    function HasExecuteAccess: Boolean;
  end;

  IGetAdapterErrors = interface
  ['{27A6D89F-58E1-11D4-A493-00C04F6BB853}']
    function GetAdapterErrors: TObject;
  end;

  IAdapterHiddenFields = interface
  ['{90E9C34C-D054-11D4-A530-00C04F6BB853}']
    function GetFieldCount: Integer;
    function GetField(I: Integer): IAdapterHiddenField;
    property FieldCount: Integer read GetFieldCount;
    property Fields[I: Integer]: IAdapterHiddenField read GetField;
  end;

  IGetAdapterHiddenFields = interface
  ['{90E9C34D-D054-11D4-A530-00C04F6BB853}']
    function GetAdapterHiddenFields: TObject;
    function GetAdapterHiddenRecordFields: TObject;
  end;

  IAdapterMode = interface
  ['{9E6E6A7C-574F-11D4-A491-00C04F6BB853}']
    function GetAdapterMode: string;
    function GetNeedAdapterMode: Boolean;
    procedure SetAdapterMode(const AValue: string);
    procedure RestoreDefaultAdapterMode;
    property AdapterMode: string read GetAdapterMode write SetAdapterMode;
    property NeedAdapterMode: Boolean read GetNeedAdapterMode;
  end;

  IAdapterErrors = interface
  ['{27A6D8A0-58E1-11D4-A493-00C04F6BB853}']
    procedure ClearErrors;
    function GetErrorCount: Integer;
    function GetError(I: Integer): IAdapterError;
    procedure DefineLabel(const AName, ALabel: string);
    property ErrorCount: Integer read GetErrorCount;
    property Errors[I: Integer]: IAdapterError read GetError;
    function HasObjectErrors(const AName: string): Boolean;
    function GetObjectErrors(const AName: string): TObject;
  end;

  IWebGetFieldValue = interface
  ['{9E6E6A7F-574F-11D4-A491-00C04F6BB853}']
    function GetValue: Variant;
    property Value: Variant read GetValue;
  end;

  IAsFormatted = interface
  ['{18138862-52C0-11D4-A48D-00C04F6BB853}']
    function AsFormatted: string;
  end;

  IWebGetDisplayWidth = interface
  ['{A23C86B6-672A-11D4-A4A7-00C04F6BB853}']
    function GetDisplayWidth: Integer;
  end;

  IImageProducer = interface
  ['{BD76DC8D-BE4B-403D-9080-71DDA287EA5A}']
    function GetAdapterImage(Sender: TComponent; const ACaption: WideString): IInterface;
  end;

  IActionImageProducer = interface(IImageProducer)
  ['{5622A0AA-DD67-4DAC-871A-9C621A762538}']
    function GetDisplayStyle(Sender: TComponent): string;
    function GetAdapterEventImage(Sender: TComponent; const AEvent, ACaption: WideString): IInterface;
  end;

  IWebGetDisplayLabel = interface
  ['{A23C86B7-672A-11D4-A4A7-00C04F6BB853}']
    function GetDisplayLabel: string;
  end;

  IWebGetMaxLength = interface
  ['{772D7639-8209-4744-9146-2B6D3A5F220F}']
    function GetMaxLength: integer;
  end;

  IWebInputName = interface
  ['{CD1644C0-41E8-4C06-9AB8-CD6B05367E27}']
    function GetInputName: string;
    property InputName: string read GetInputName;
  end;

  IValuesListAdapter = interface
  ['{CAC16451-9BAD-11D4-A4F2-00C04F6BB853}']
    function GetListValue: Variant;
    function GetListName: string;
    function GetListNameOfValue(Value: Variant): string;
    function GetListImage: IInterface;
    function GetListImageOfValue(Value: Variant): IInterface;
  end;

  IGetAdapterImage = interface
  ['{59FD8382-A09A-11D4-A4F7-00C04F6BB853}']
    function GetAdapterImage: IInterface;
  end;

  IGetHTMLStyle = interface
  ['{1C1557D1-CA79-4BEE-86E2-253BEC8925E2}']
    function GetDisplayStyle(const AAdapterMode: string): string;
    function GetInputStyle(const AAdapterMode: string): string;
    function GetViewMode(const AAdapterMode: string): string;
  end;

  IAdapterFieldAccess = interface
  ['{98C3D564-3CE4-412C-A7FE-DA05A1A37953}']
    function HasViewAccess: Boolean;
    function HasModifyAccess: Boolean;
  end;

  IGetFieldValuesAdapter = interface
  ['{87BDFE12-CA10-11D4-A528-00C04F6BB853}']
    function GetFieldValuesAdapter: TComponent;
  end;

  IWebValueIsEqual = interface
  ['{495042FB-97CE-4CA1-921F-9A09DD3B65F2}']
    function IsEqual(const Value: Variant): Boolean;
  end;

  IAdapterFieldAttributes = interface
  ['{179232BF-CC77-11D4-A52B-00C04F6BB853}']
    function GetVisible: Boolean;
    function GetRequired: Boolean;
    property Visible: Boolean read GetVisible;
    property Required: Boolean read GetRequired;
  end;

  IIsAdapterActionList = interface
  ['{AFA05E90-DDAA-4B7F-B7A6-D3F9093D9427}']
    function GetIsAdapterActionList: Boolean;
    property IsAdapterActionList: Boolean read GetIsAdapterActionList;
  end;

  IAdapterActionAccess = interface
  ['{55285C44-A3BE-4821-9994-0051647699A7}']
    function HasExecuteAccess: Boolean;
  end;

  IGetAdapterValuesList = interface
  ['{59D7E94D-9BA9-11D4-A4F2-00C04F6BB853}']
    function GetAdapterValuesList: IValuesListAdapter;
  end;

  IWebEnabled = interface
  ['{648F97D7-B299-444A-89CA-E60BD1FB9EA3}']
    function WebEnabled: Boolean;
  end;

  IGetAdapterFields = interface
  ['{30B45B2F-B5B7-4BAE-A6FC-EC47E5B0C941}']
    function GetAdapterFields: TComponent;
  end;

  IAdapterActionAttributes = interface
  ['{B86F48C3-BEEB-43A7-9BEF-1ABE1311E419}']
    function GetVisible: Boolean;
    property Visible: Boolean read GetVisible;
  end;

  IGetAdapterActions = interface
  ['{0C2D1ECE-7BBA-43FE-A466-2D8BC70CC85D}']
    function GetAdapterActions: TComponent;
  end;

  IWebImageHREF = interface
  ['{10E873A2-A6DD-4AE9-8AB5-4597142E4631}']
    function WebImageHREF(var AHREF: string): Boolean;
  end;
  
  IFieldValuesAdapter = interface
  ['{87BDFE13-CA10-11D4-A528-00C04F6BB853}']
    function GetField: TObject;
    function GetValueIndex: Integer;
  end;

  IWebGetFieldValues = interface
  ['{5DC0D607-1C9C-4E67-B3BA-35CE2A5872A0}']
    function GetCurrentValue: Variant;
    function HasValue(const AValue: Variant): Boolean;
    function StartValueIterator(var OwnerData: Pointer): Boolean;
    function NextValueIteration(var OwnerData: Pointer): Boolean;
    procedure EndValueIterator(OwnerData: Pointer);
  end;

  IWebActionsList = interface
  ['{CB84BC93-4C65-11D4-A48B-00C04F6BB853}']
    procedure GetActionsList(AList: TStrings);
    function FindAction(const AName: string): TComponent;
    function IsActionInUse(const AName: string): Boolean;
    function GetVisibleActions: TWebComponentList;
    property VisibleActions: TWebComponentList read GetVisibleActions;
  end;

  IWebDataFields = interface
  ['{D62DBBBD-2C40-11D4-A46E-00C04F6BB853}']
    procedure GetFieldsList(AList: TStrings);
    function IsFieldInUse(const AName: string): Boolean;
    function FindField(const AName: string): TComponent;
    function GetVisibleFields: TWebComponentList;
    property VisibleFields: TWebComponentList read GetVisibleFields;
  end;

  IWebGetFieldName = interface
  ['{D62DBBC0-2C40-11D4-A46E-00C04F6BB853}']
    function GetFieldName: string;
    property FieldName: string read GetFieldName;
  end;

  IWebSetFieldName = interface
  ['{CB84BC94-4C65-11D4-A48B-00C04F6BB853}']
    procedure SetFieldName(const AFieldName: string);
  end;

  IWebGetActionName = interface
  ['{5DC620F7-C14A-4D49-868E-656041ADF017}']
    function GetActionName: string;
    property ActionName: string read GetActionName;
  end;

  IWebSetActionName = interface
  ['{005FC2A6-92C1-4F7D-BC69-F4254672E6C0}']
    procedure SetActionName(const AFieldName: string);
  end;

  TAdapterDisplayCharacteristic = (dcMultipleRecordView, dcCurrentRecordView,
    dcChangeCurrentRecordView);
  TAdapterDisplayCharacteristics = set of TAdapterDisplayCharacteristic;
  IGetAdapterDisplayCharacteristics = interface
  ['{CA500563-1298-400F-814D-DA836E08D8B4}']
    function GetAdapterDisplayCharacteristics: TAdapterDisplayCharacteristics;
  end;

  TAdapterInputHTMLElementType = (
    htmliNone, htmliTextInput, htmliPasswordInput,
    htmliSelect, htmliSelectMultiple,
    htmliRadio, htmliCheckBox, htmliTextArea, htmliFile);

  TAdapterDisplayHTMLElementType = (
    htmldText, htmldImage, htmldList, htmldNone);

  TAdapterDisplayViewModeType = (
    htmlvmInput, htmlvmDisplay, htmlvmToggleOnAccess, htmlvmNone);

  TAdapterActionHTMLElementType = (htmlaButton, htmlaImage, htmlaAnchor, htmlaEventImages);

  { Implement INotifyList }
  TNotifyList = class(TObject)
  private
    FList: TList;
  protected
  public
    constructor Create;
    destructor Destroy; override;
    function GetItem(Index: Integer): TObject;
    function GetCount: Integer;
    procedure AddNotify(ANotify: TObject);
    procedure RemoveNotify(ANotify: TObject);

    property Items[Index: Integer]: TObject read GetItem; default;
    property Count: Integer read GetCount;
  end;

  IWebIsDefaultField = interface
  ['{A22A7CE1-AC68-4DD5-BE09-18CBBAB57890}']
    function IsDefaultField(ADisplay: TObject): Boolean;
  end;

  IWebIsDefaultAction = interface
  ['{E9FD2BD8-CD66-4C91-96FE-8B59C7CD048F}']
    function IsDefaultAction(ADisplay: TObject): Boolean;
  end;

  IGetProducerComponent = interface
  ['{75E6B9BB-5AE1-45DB-BACA-314BBE845B4F}']
    function GetProducerComponent: TComponent;
  end;

  TQualifyOption = (qaUseModulesVar, qaNoModulesVar, qaNoModuleName);

const
  AdapterInputHTMLElementTypeNames: array[TAdapterInputHTMLElementType] of string =
    ('', 'TextInput', 'PasswordInput', 'Select', 'SelectMultiple',
    'Radio', 'CheckBox', 'TextArea', 'File');
  AdapterDisplayHTMLElementTypeNames: array[TAdapterDisplayHTMLElementType] of string =
    ('Text', 'Image', 'List', '');
  AdapterActionHTMLElementTypeNames: array[TAdapterActionHTMLElementType] of string =
    ('Button', 'Image', 'Anchor', 'EventImages');
  AdapterDisplayViewModeTypeNames: array[TAdapterDisplayViewModeType] of string =
    ('Input', 'Display', 'ToggleOnAccess', '');

var
  InetFileTypes: IInternetFileTypes = nil;
  ScriptDebugger: IInternetScriptDebugger = nil;
  InternetEnvOptions: IInternetEnvOptions = nil;
  ExecuteScript: IInternetExecuteScript = nil;
  IDEFileManager: IIDEFileManager = nil;
  GetHTMLSampleImage: function: string = nil;

function FullyQualifiedFieldName(AComponent: TComponent): string;
function FullyQualifiedName(AComponent: TComponent; AOption: TQualifyOption): string;

implementation

uses SysUtils;

function FullyQualifiedName(AComponent: TComponent; AOption: TQualifyOption): string;
var
  VariableName: IWebVariableName;
  Root: TComponent;
  ContainerName: IWebVariablesContainerName;
begin
  Result := '';
  Root := AComponent.Owner;
  while Assigned(AComponent) do
  begin
    if not Assigned(Root) then
      // Default components will not have an owner
      Root := AComponent.Owner;
    if Supports(IInterface(AComponent), IWebVariableName, VariableName) then
    begin
      if Result <> '' then
      begin
        if Supports(IInterface(AComponent), IWebVariablesContainerName, ContainerName) and
          (ContainerName.ContainerName <> '') then
          Result := ContainerName.ContainerName + '.' + Result;
        Result := '.' + Result;
      end;
      Result := VariableName.VariableName + Result;
    end;
    AComponent := AComponent.GetParentComponent;
  end;
  case AOption of
    qaUseModulesVar:
      if Assigned(Root) and (Result <> '') then
        Result := 'Modules.' + Root.Name + '.' + Result;
    qaNoModulesVar:
      if Assigned(Root) and (Result <> '') then
        Result := Root.Name + '.' + Result;
    qaNoModuleName: ; // No change
  end;
end;

function FullyQualifiedFieldName(AComponent: TComponent): string;
begin
  Result := FullyQualifiedName(AComponent, qaUseModulesVar);
end;

{ TScriptComponentObject }

constructor TScriptComponent.Create(AObject: TComponent);
begin
  FObject := AObject;
  inherited Create;
end;

{ TNotifyList }

procedure TNotifyList.AddNotify(ANotify: TObject);
begin
  FList.Add(ANotify);
end;

constructor TNotifyList.Create;
begin
  inherited;
  FList := TList.Create;
end;

destructor TNotifyList.Destroy;
begin
  inherited;
  FList.Free;
end;

function TNotifyList.GetItem(Index: Integer): TObject;
begin
  Result := FList[Index];
end;

function TNotifyList.GetCount: Integer;
begin
  Result := FList.Count;
end;

procedure TNotifyList.RemoveNotify(ANotify: TObject);
begin
  FList.Remove(ANotify);
end;

function TScriptComponent.GetComponent: TComponent;
begin
  Result := FObject;
end;

function GetWebEndUser: IWebEndUser;
var
  GetIntf: IGetWebAppComponents;
begin
  Result := nil;
  if WebContext <> nil then
    if Supports(IUnknown(WebContext.FindApplicationModule(nil)), IGetWebAppComponents, GetIntf) then
      Result := GetIntf.WebEndUser;
end;

initialization
  WebCntxt.GetWebEndUserProc := GetWebEndUser;
end.
