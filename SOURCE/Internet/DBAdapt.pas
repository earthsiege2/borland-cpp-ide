
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{ Copyright (c) 2000, 2001 Borland Software Corporation }
{                                                       }
{*******************************************************}

unit DBAdapt;

interface

{$IFDEF MSWINDOWS}
uses Classes, Messages, HTTPApp, WebComp, HTTPProd, DB, SiteComp, SysUtils,
  WebContnrs, Contnrs, AdaptReq, WebAdapt;
{$ENDIF}
{$IFDEF LINUX}
uses Classes, HTTPApp, WebComp, HTTPProd, DB, SiteComp, SysUtils,
  WebContnrs, Contnrs, AdaptReq, WebAdapt;
{$ENDIF}

type

  TDataSetAdapterRequestParamOption = (poLocateParams, poCurrentPage);
  TDataSetAdapterRequestParamOptions = set of TDataSetAdapterRequestParamOption;
  TDataSetAdapterMode = (amInsert, amEdit, amBrowse, amQuery);
  TDataSetAdapterModes = set of TDataSetAdapterMode;
  const
    DataSetAdapterModeNames: array[TDataSetAdapterMode] of string =
      ('Insert', 'Edit', 'Browse', 'Query');
  type

  TLocateParamsList = class;

  TLocateParams = class(TObject)
  private
    FAdapterName: string;
    FParams: TStrings;
    function GetCount: Integer;
    function GetParamName(I: Integer): string;
    function GetParamValue(I: Integer): string;
    function GetItem(I: Integer): string;
  public
    constructor Create(AList: TLocateParamsList);
    destructor Destroy; override;
    property AdapterName: string read FAdapterName write FAdapterName;
    property Count: Integer read GetCount;
    procedure AddParam(const ANameValue: string); overload;
    procedure AddParam(const AName, AValue: string); overload;
    property ParamNames[I: Integer]: string read GetParamName;
    property ParamValues[I: Integer]: string read GetParamValue;
    property Items[I: Integer]: string read GetItem; default;
  end;

  TLocateParamsList = class(TObject)
  private
    FList: TObjectList;
    function GetCount: Integer;
    function GetItem(I: Integer): TLocateParams;
  public
    constructor Create;
    destructor Destroy; override;
    procedure Clear;
    function Add: TLocateParams;
    property Count: Integer read GetCount;
    property Items[I: Integer]: TLocateParams read GetItem; default;
    function ItemByAdapterName(const AName: string): TLocateParams;
  end;

  IKeyParams = interface
    function Count: Integer;
    function GetName(I: Integer): string;
    function GetValue(I: Integer): string;
    property Names[I: Integer]: string read GetName;
    property Values[I: Integer]: string read GetValue;
  end;

  IGetDataSetKeyName = interface
  ['{A9F1BBDE-9B0A-49E6-AFB9-C19E52A84E83}']
    function GetKeyName: string;
    property KeyName: string read GetKeyName;
  end;

  IAdapterDataSetComponent = interface
  ['{D62DBBC1-2C40-11D4-A46E-00C04F6BB853}']
    function GetDataSet: TDataSet;
    procedure SetDataSet(Value: TDataSet);
    property DataSet: TDataSet read GetDataSet write SetDataSet;
  end;

  IPrepareDataSet = interface
  ['{444E2D2E-F1A6-485D-B0E3-1CF925A4713B}']
    procedure PrepareDataSet;
  end;
  
  TCustomDataSetAdapter = class(TDefaultFieldsPagedAdapter,
    IAdapterMode, IAdapterDataSetComponent, IGetDesigntimeWarnings,
    IGetAdapterModeNames, IGetRecordKeys, IFullyQualifyInputNames)
  private
    FDataSet: TDataSet;
    FDesignerDataLink: TDataLink;
    FLocateParamsList: TLocateParamsList;
    FOnPrepareDataSet: TNotifyEvent;
    FDataSetPrepared: Boolean;
    FMode: TDataSetAdapterMode;
    FDataSetRecNo: Integer;
    FInIterator: Boolean;
    FMasterAdapter: TCustomDataSetAdapter;
    FDetailAdapters: TComponentList;
    FAdapterRowNotFound: TCustomDataSetAdapter;
    FInDefaultMode: Boolean;
    function GetMode: TDataSetAdapterMode;
    procedure CreateDataLink;
    procedure SetMasterAdapter(const Value: TCustomDataSetAdapter);
    procedure SetInDefaultMode(const Value: Boolean);
  protected
    procedure ImplSetEchoActionFieldValues(AValue: Boolean); override;
    function GetDefaultMode: TDataSetAdapterMode; virtual;
    function GetMasterDetailAdapters: TComponentList;
    procedure GetKeyParamStrings(AValues: TStrings);
    function LocateKeyParams(AParams: IKeyParams): Boolean;
    function LocateRequestRecord(AActionRequest: IActionRequest): Boolean;
    procedure OnDataSetStateChange(Sender: TObject); virtual;
    // Paging support
    function GetNextRecord: Boolean; override;
    function GetFirstRecord: Boolean; override;
    function GetEOF: Boolean; override;
    function GetRecordIndex: Integer; override;
    function GetRecordCount: Integer; override;
    { IFullyQualifyInputNames }
    function FullyQualifyInputNames: Boolean;
    { IIteratorIndex }
    function ImplGetIteratorIndex: Integer; override;
    function ImplInIterator: Boolean; override;

    procedure SetMode(const Value: TDataSetAdapterMode); virtual;
    function GetHiddenFieldOptions: TAdapterHiddenFieldOptions; override;
    procedure AddDefaultFields(AComponents: TWebComponentList); override;
    procedure AddDefaultActions(AComponents: TWebComponentList); override;
    function GetKeyFields: string;
    function GetProviderSupport: IProviderSupport;
    procedure GetKeyParams(AParams: TLocateParamsList; ARecurse: Boolean);
    procedure UpdateFieldsValidateValues(AActionRequest: IActionRequest;
      AAdapterFields: TObjectList); override;
    function UpdateFieldsGetAnyChanges(AActionRequest: IActionRequest;
      AAdapterFields: TObjectList): Boolean; override;
    procedure UpdateFieldsUpdateValues(AActionRequest: IActionRequest;
      AAdapterFields: TObjectList); override;
    procedure UpdateFieldsExecuteValues(AActionRequest: IActionRequest;
      AAdapterFields: TObjectList); override;
    { IGetDesigntimeWarnings }
    procedure GetDesigntimeWarnings(AWarnings: TAbstractDesigntimeWarnings);
    { IAdapterEditor }
    function ImplCanAddFieldClass(AParent: TComponent; AClass: TClass): Boolean; override;
    function ImplCanAddActionClass(AParent: TComponent; AClass: TClass): Boolean; override;
    { INotifyWebActivate }
    procedure ImplNotifyDeactivate; override;
    { IGetAdapterModeNames }
    procedure GetAdapterModeNames(AStrings: TStrings);
    { IGetRecordKeys }
    procedure GetRecordKeys(AValues: TStrings; var AFullyQualify: Boolean);
    procedure ImplGetRecordKeys(AValues: TStrings; var AFullyQualify: Boolean); virtual;
    { IAdapterMode }
    function GetAdapterMode: string;
    procedure SetAdapterMode(const AValue: string);
    procedure RestoreDefaultAdapterMode;
    function GetNeedAdapterMode: Boolean;
    { IAdapterDataSetComponent }
    function GetDataSet: TDataSet;
    { IWebDataFields }
    procedure ImplGetFieldsList(AList: TStrings); override;
    { IWebActionsList }
    procedure ImplGetActionsList(AList: TStrings); override;

    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure SetDataSet(ADataSet: TDataSet);
    procedure PrepareDataSet; virtual;
    property DataSetPrepared: Boolean read FDataSetPrepared write FDataSetPrepared;
    property AdapterRowNotFound: TCustomDataSetAdapter read FAdapterRowNotFound write FAdapterRowNotFound;
  public
    function StringToMode(const AValue: string): TDataSetAdapterMode;
    procedure ExtractRequestParams(ARequest: IUnknown); override;
    procedure EncodeActionParams(AParams: IAdapterItemRequestParams); override;
    procedure ExtractRequestParamsFlags(ARequest: IUnknown;
      AOptions: TDataSetAdapterRequestParamOptions);
    procedure EncodeActionParamsFlags(AParams: IAdapterItemRequestParams;
      AOptions: TDataSetAdapterRequestParamOptions);
    function Locate: Boolean;
    function SilentLocate(AParams: TLocateParamsList; ARecurse: Boolean): Boolean;
    procedure ApplyAdapterMode(AActionRequest: IActionRequest);
    function LocateAndApply(AActionRequest: IActionRequest): Boolean;
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure RaiseFieldNotFound(const AFieldName: string);
    procedure RaiseFieldChangedByAnotherUser(const AFieldName: string);
    procedure RaiseRowNotFound;
    procedure RaiseNilDataSet;
    property DataSet: TDataSet read GetDataSet write SetDataSet;
    property InDefaultMode: Boolean read FInDefaultMode write SetInDefaultMode;
    property Mode: TDataSetAdapterMode read GetMode write SetMode;
    property LocateParamsList: TLocateParamsList read FLocateParamsList;
    property OnPrepareDataSet: TNotifyEvent read FOnPrepareDataSet write FOnPrepareDataSet;
    property DetailAdapters: TComponentList read FDetailAdapters;
    property MasterAdapter: TCustomDataSetAdapter read FMasterAdapter write SetMasterAdapter;
  end;

  TDataSetAdapter = class(TCustomDataSetAdapter)
  published
    property DataSet;
    property Data;
    property Actions;
    property ViewAccess;
    property ModifyAccess;
    property OnPrepareDataSet;
    property OnBeforeUpdateFields;
    property OnAfterUpdateFields;
    property OnBeforeValidateFields;
    property OnAfterValidateFields;
    property OnBeforeExecuteAction;
    property OnAfterExecuteAction;
    property OnBeforeGetActionResponse;
    property OnAfterGetActionResponse;
    property OnGetActionParams;
    property OnGetRecordCount;
    property PageSize;
    property MasterAdapter;
  end;

  IDataSetAdapterFieldClass = interface
  ['{C42812E6-D7AD-490B-80C6-3834CE31B66C}']
  end;

  TDataSetAdapterFieldGetValueEvent = procedure (Sender: TObject; Field: TField; var Value: Variant) of object;
  TDataSetAdapterFieldGetStringEvent = procedure (Sender: TObject; Field: TField; var Value: string) of object;
  TDataAdapterFieldValidateValueEvent = procedure(Sender: TObject; Field: TField; Value: IActionFieldValue; var Handled: Boolean) of object;
  TDataSetAdapterFieldValueEvent = procedure (Sender: TObject; Field: TField; Value: Variant) of object;
  TDataSetAdapterFieldFlag = (ffInKey, ffInOrigValues);
  TDataSetAdapterFieldFlags = set of TDataSetAdapterFieldFlag;
  TBaseDataSetAdapterField = class(TAdapterNamedField, IGetHTMLStyle, IUpdateValue, ICheckValueChange,
    IDataSetAdapterFieldClass, IGetDataSetKeyName, IPrepareDataSet)
  private
    FField: TField;
    FDataSetField: string;
    FFieldModes: TDataSetAdapterModes;
    FFieldFlags: TDataSetAdapterFieldFlags;
    FOnGetDisplayText: TDataSetAdapterFieldGetStringEvent;
    FOnGetValue: TDataSetAdapterFieldGetValueEvent;
  protected
    function FullyQualifyInputName: Boolean; override;
    function GetDataSetFieldValue(Field: TField): Variant; virtual;
    procedure SetDataSetField(const Value: string);
    function GetDataSet: TDataSet;
    procedure GetKeyParams(Params: TLocateParamsList);
    function GetReadOnly: Boolean;
    { IPrepareDataSet }
    procedure PrepareDataSet;
    { IGetDataSetKeyName}
    function GetKeyName: string;
    { IAdapterFieldAttributes }
    function ImplGetVisible: Boolean; override;
    function ImplGetRequired: Boolean; override;
    { IUpdateValue }
    procedure UpdateValue(AActionRequest: IActionRequest; AFieldIndex: Integer);
    procedure ImplUpdateValue(AActionRequest: IActionRequest; AFieldIndex: Integer); virtual;
    { ICheckOrigValue }
    procedure CheckOrigValue(AActionRequest: IActionRequest; AFieldIndex: Integer);
    procedure ImplCheckOrigValue(AActionRequest: IActionRequest; AFieldIndex: Integer); virtual;
    { ICheckValueChange }
    function CheckValueChange(AActionRequest: IActionRequest; AFieldIndex: Integer): Boolean;
    function ImplCheckValueChange(AActionRequest: IActionRequest; AFieldIndex: Integer): Boolean; virtual;
    { IGetHTMLStyle }
    function GetViewMode(const AAdapterMode: string): string;
    function GetDisplayStyle(const AAdapterMode: string): string;
    function GetInputStyle(const AAdapterMode: string): string;
    function GetInputStyleType(const AAdapterMode: string): TAdapterInputHTMLElementType; virtual;
    function GetDisplayStyleType(const AAdapterMode: string): TAdapterDisplayHTMLElementType; virtual;
    function GetViewModeType(const AAdapterMode: string): TAdapterDisplayViewModeType; virtual;
    { IWebAsFormatted }
    function ImplAsFormatted: string; override;
    { IWebGetFieldValue }
    procedure ImplSetFieldName(const Value: string); override;
    function ImplGetValue: Variant; override;
    { IWebGetDisplayWidth }
    function ImplGetDisplayWidth: Integer; override;
    { IWebGetDisplayLabel }
    function ImplGetDisplayLabel: string; override;
    function GetAdapter: TCustomDataSetAdapter;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    property Adapter: TCustomDataSetAdapter read GetAdapter;
    property DataSetField: string read FDataSetField write SetDataSetField;
  public
    constructor Create(AOwner: TComponent); override;
    function FindField: TField;
    property FieldModes: TDataSetAdapterModes read FFieldModes write FFieldModes
      default [amInsert, amEdit, amBrowse, amQuery];
    property FieldFlags: TDataSetAdapterFieldFlags read FFieldFlags write FFieldFlags default [ffInOrigValues];
    property OnGetValue: TDataSetAdapterFieldGetValueEvent read FOnGetValue write FOnGetValue;
    property OnGetDisplayText: TDataSetAdapterFieldGetStringEvent read FOnGetDisplayText write FOnGetDisplayText;
  end;

  TBaseDataSetAdapterInputField = class(TBaseDataSetAdapterField, IValidateValue)
  private
    FEchoActionFieldValue: Boolean;
    FOnValidateValue: TDataAdapterFieldValidateValueEvent;
    FOnUpdateValue: TDataSetAdapterFieldValueEvent;
  protected
    { IValidateValue }
    procedure ValidateValue(AActionRequest: IActionRequest; AFieldIndex: Integer);
    procedure ImplValidateValue(AActionRequest: IActionRequest; AFieldIndex: Integer); virtual;
    { IEchoActionFieldValue }
    procedure ImplSetEchoActionFieldValue(AValue: Boolean); override;
    function ImplGetEchoActionFieldValue: Boolean; override;
    function TestValueChange(AField: TField;
      const ANewValue: string): Boolean;
  public
    property OnUpdateValue: TDatasetAdapterFieldValueEvent read FOnUpdateValue write FOnUpdateValue;
    property OnValidateValue: TDataAdapterFieldValidateValueEvent read FOnValidateValue write FOnValidateValue;
  end;

  TCustomDataSetAdapterField = class(TBaseDataSetAdapterInputField, IWebGetFieldPrevValue,
    IGetAdapterValuesList, ICheckOrigValue)
  private
    FValuesList: IValuesListAdapter;
    procedure SetValuesList(const Value: IValuesListAdapter);
  protected
    function ImplGetValue: Variant; override;
    { IUpdateValue }
    procedure ImplUpdateValue(AActionRequest: IActionRequest; AFieldIndex: Integer); override;
    { ICheckOrigValue }
    procedure ImplCheckOrigValue(AActionRequest: IActionRequest; AFieldIndex: Integer); override;
    { ICheckValueChange }
    function ImplCheckValueChange(AActionRequest: IActionRequest;
      AFieldIndex: Integer): Boolean; override;
    { IGetHTMLStyle }
    function GetInputStyleType(const AAdapterMode: string): TAdapterInputHTMLElementType; override;
    { IGetAdapterValuesList }
    function GetAdapterValuesList: IValuesListAdapter;
    { IWebGetFieldPrevValue }
    function GetPrevValue: Variant;
    function ImplGetPrevValue: Variant; virtual;
    function GetNeedPrevValue: Boolean;
    function ImplGetNeedPrevValue: Boolean; virtual;

    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
  public
    property ValuesList: IValuesListAdapter read FValuesList write SetValuesList;
  end;

  TDataSetAdapterField = class(TCustomDataSetAdapterField)
  published
    property DataSetField;
    property ValuesList;
    property ViewAccess;
    property ModifyAccess;
    property FieldModes;
    property FieldFlags;
    property OnGetValue;
    property OnUpdateValue;
    property OnValidateValue;
    property OnGetDisplayText;
  end;

  TCustomDataSetAdapterMemoField = class(TBaseDataSetAdapterInputField)
  protected
    function CheckOrUpdateValue(AActionRequest: IActionRequest;
      AFieldIndex: Integer; AUpdate: Boolean): Boolean;
    { IUpdateValue }
    procedure ImplUpdateValue(AActionRequest: IActionRequest; AFieldIndex: Integer); override;
    function ImplAsFormatted: string; override;
    { IGetHTMLStyle }
    function GetInputStyleType(const AAdapterMode: string): TAdapterInputHTMLElementType; override;
    { ICheckValueChange }
    function ImplCheckValueChange(AActionRequest: IActionRequest;
      AFieldIndex: Integer): Boolean; override;
    { IWebGetFieldPrevValue }
    function ImplGetValue: Variant; override;
  end;

  TDataSetAdapterMemoField = class(TCustomDataSetAdapterMemoField)
  published
    property DataSetField;
    property ViewAccess;
    property ModifyAccess;
    property FieldModes;
    property FieldFlags;
    property OnGetValue;
    property OnUpdateValue;
    property OnValidateValue;
    property OnGetDisplayText;
  end;

  TCustomDataSetAdapterAction = class(TImplementedAdapterAction)
  private
    FActionModes: TDataSetAdapterModes;
    FOnGetEnabled: TActionGetEnabledEvent;
    FOnExecute: TActionExecuteEvent;
  protected
    function GetDataSet: TDataSet;
    { IAdapterActionAttributes }
    function ImplGetVisible: Boolean; override;
    { IWebEnabled }
    function ImplWebEnabled: Boolean; override;
    function GetAdapter: TCustomDataSetAdapter;
    property Adapter: TCustomDataSetAdapter read GetAdapter;
  public
    constructor Create(AOwner: TComponent); override;
    property DataSet: TDataSet read GetDataSet;
    property ActionName;
    property OnExecute: TActionExecuteEvent read FOnExecute write FOnExecute;
    property OnGetEnabled: TActionGetEnabledEvent read FOnGetEnabled write FOnGetEnabled;
    property ActionModes: TDataSetAdapterModes read FActionModes write FActionModes
      default [amInsert, amEdit, amBrowse, amQuery];
  end;

  TCustomDataSetAdapterRowAction = class(TCustomDataSetAdapterAction)
  protected
    { IGetAdapterItemRequestParams }
    procedure ImplGetAdapterItemRequestParams(var AIdentifier: string; Params: IAdapterItemRequestParams); override;
    { IWebEnabled }
    function ImplWebEnabled: Boolean; override;
  public
    constructor Create(AOwner: TComponent); override;
  end;

  // For user defined row actions
  TDataSetAdapterRowAction = class(TCustomDataSetAdapterRowAction)
  protected
    procedure ImplExecuteActionRequest(
      AActionRequest: IActionRequest; AActionResponse: IActionResponse); override;
    { IGetAdapterItemRequestParams }
    procedure ImplGetAdapterItemRequestParams(var AIdentifier: string; Params: IAdapterItemRequestParams); override;
  published
    property OnGetParams;
    property DisplayLabel;
    property ExecuteAccess;
    property OnBeforeExecute;
    property OnAfterExecute;
    property OnBeforeGetResponse;
    property OnAfterGetResponse;
    property RedirectOptions;
    property ActionModes default [amInsert, amEdit, amBrowse {, amQuery}];
  end;

  TDataSetAdapterDeleteRowAction = class(TCustomDataSetAdapterRowAction)
  protected
    procedure ImplExecuteActionRequest(
      AActionRequest: IActionRequest; AActionResponse: IActionResponse); override;
    { IWebIsDefaultAction }
    function ImplIsDefaultAction(ADisplay: TObject): Boolean; override;

    function GetDefaultActionName: string; override;
  published
    property DisplayLabel;
    property ExecuteAccess;
    property OnBeforeExecute;
    property OnAfterExecute;
    property OnBeforeGetResponse;
    property OnAfterGetResponse;
    property OnGetParams;
    property RedirectOptions;
  end;

  TDataSetAdapterMoveRowAction = class(TCustomDataSetAdapterRowAction)
  protected
    { IWebIsDefaultAction }
    function ImplIsDefaultAction(ADisplay: TObject): Boolean; override;
  end;

  TDataSetAdapterNextRowAction = class(TDataSetAdapterMoveRowAction)
  protected
    procedure ImplExecuteActionRequest(AActionRequest: IActionRequest; AActionResponse: IActionResponse); override;
    { IWebEnabled }
    function ImplWebEnabled: Boolean; override;

    function GetDefaultActionName: string; override;
  published
    property DisplayLabel;
    property ExecuteAccess;
    property OnBeforeExecute;
    property OnAfterExecute;
    property OnBeforeGetResponse;
    property OnAfterGetResponse;
    property OnGetParams;
    property RedirectOptions;
  end;

  TDataSetAdapterPrevRowAction = class(TDataSetAdapterMoveRowAction)
  protected
    procedure ImplExecuteActionRequest(AActionRequest: IActionRequest; AActionResponse: IActionResponse); override;
    { IWebEnabled }
    function ImplWebEnabled: Boolean; override;

    function GetDefaultActionName: string; override;
  published
    property DisplayLabel;
    property ExecuteAccess;
    property OnBeforeExecute;
    property OnAfterExecute;
    property OnBeforeGetResponse;
    property OnAfterGetResponse;
    property OnGetParams;
    property RedirectOptions;
  end;

  TDataSetAdapterFirstRowAction = class(TDataSetAdapterMoveRowAction)
  protected
    procedure ImplExecuteActionRequest(AActionRequest: IActionRequest; AActionResponse: IActionResponse); override;
    { IWebEnabled }
    function ImplWebEnabled: Boolean; override;

    function GetDefaultActionName: string; override;
  published
    property DisplayLabel;
    property ExecuteAccess;
    property OnBeforeExecute;
    property OnAfterExecute;
    property OnBeforeGetResponse;
    property OnAfterGetResponse;
    property OnGetParams;
    property RedirectOptions;
  end;

  TDataSetAdapterLastRowAction = class(TDataSetAdapterMoveRowAction)
  protected
    procedure ImplExecuteActionRequest(AActionRequest: IActionRequest; AActionResponse: IActionResponse); override;
    { IWebEnabled }
    function ImplWebEnabled: Boolean; override;

    function GetDefaultActionName: string; override;
  published
    property DisplayLabel;
    property ExecuteAccess;
    property OnBeforeExecute;
    property OnAfterExecute;
    property OnBeforeGetResponse;
    property OnAfterGetResponse;
    property OnGetParams;
    property RedirectOptions;
  end;

  TDataSetAdapterNewRowAction = class(TDataSetAdapterRowAction)
  protected
    procedure ImplExecuteActionRequest(AActionRequest: IActionRequest; AActionResponse: IActionResponse); override;
    { IWebIsDefaultAction }
    function ImplIsDefaultAction(ADisplay: TObject): Boolean; override;
    { IWebEnabled }
    function ImplWebEnabled: Boolean; override;

    function GetDefaultActionName: string; override;
  published
    constructor Create(AOwner: TComponent); override;
    property DisplayLabel;
    property ExecuteAccess;
    property OnBeforeExecute;
    property OnAfterExecute;
    property OnBeforeGetResponse;
    property OnAfterGetResponse;
    property OnGetParams;
    property ActionModes default [amInsert, amEdit, amBrowse, amQuery];
  end;

  TDataSetAdapterCancelRowAction = class(TCustomDataSetAdapterRowAction)
  protected
    procedure ImplExecuteActionRequest(AActionRequest: IActionRequest; AActionResponse: IActionResponse); override;
    { IWebIsDefaultAction }
    function ImplIsDefaultAction(ADisplay: TObject): Boolean; override;
    { IWebEnabled }
    function ImplWebEnabled: Boolean; override;

    function GetDefaultActionName: string; override;
  published
    constructor Create(AOwner: TComponent); override;
    property DisplayLabel;
    property ExecuteAccess;
    property OnBeforeExecute;
    property OnAfterExecute;
    property OnBeforeGetResponse;
    property OnAfterGetResponse;
    property OnGetParams;
    property RedirectOptions;
    property ActionModes default [amInsert, amEdit{amBrowse , amQuery}];
  end;

  TDataSetAdapterApplyRowAction = class(TCustomDataSetAdapterRowAction)
  protected
    procedure ImplExecuteActionRequest(AActionRequest: IActionRequest; AActionResponse: IActionResponse); override;
    { IWebIsDefaultAction }
    function ImplIsDefaultAction(ADisplay: TObject): Boolean; override;
    { IWebEnabled }
    function ImplWebEnabled: Boolean; override;

    function GetDefaultActionName: string; override;
  published
    constructor Create(AOwner: TComponent); override;
    property DisplayLabel;
    property ExecuteAccess;
    property OnBeforeExecute;
    property OnAfterExecute;
    property OnBeforeGetResponse;
    property OnAfterGetResponse;
    property OnGetParams;
    property RedirectOptions;
    property ActionModes default [amInsert, amEdit {amBrowse , amQuery}];
  end;

  TDataSetAdapterRefreshRowAction = class(TCustomDataSetAdapterRowAction)
  protected
    procedure ImplExecuteActionRequest(AActionRequest: IActionRequest; AActionResponse: IActionResponse); override;
    { WebIsDefaultAction }
    function ImplIsDefaultAction(ADisplay: TObject): Boolean; override;
    { IWebEnabled }
    function ImplWebEnabled: Boolean; override;

    function GetDefaultActionName: string; override;
  published
    property DisplayLabel;
    property ExecuteAccess;
    property OnBeforeExecute;
    property OnAfterExecute;
    property OnBeforeGetResponse;
    property OnAfterGetResponse;
    property OnGetParams;
    property RedirectOptions;
 end;

  TDataSetAdapterEditRowAction = class(TCustomDataSetAdapterRowAction)
  protected
    procedure ImplExecuteActionRequest(AActionRequest: IActionRequest; AActionResponse: IActionResponse); override;
    { IWebIsDefaultAction }
    function ImplIsDefaultAction(ADisplay: TObject): Boolean; override;
    { IWebEnabled }
    function ImplWebEnabled: Boolean; override;

    function GetDefaultActionName: string; override;
  published
    constructor Create(AOwner: TComponent); override;
    property DisplayLabel;
    property ExecuteAccess;
    property OnBeforeExecute;
    property OnAfterExecute;
    property OnBeforeGetResponse;
    property OnAfterGetResponse;
    property OnGetParams;
    property ActionModes default [amInsert, amEdit, amBrowse, amQuery];
  end;

  TDataSetAdapterBrowseRowAction = class(TCustomDataSetAdapterRowAction)
  protected
    procedure ImplExecuteActionRequest(AActionRequest: IActionRequest; AActionResponse: IActionResponse); override;
    { IWebIsDefaultAction }
    function ImplIsDefaultAction(ADisplay: TObject): Boolean; override;
    { IWebEnabled }
    function ImplWebEnabled: Boolean; override;

    function GetDefaultActionName: string; override;
  published
    constructor Create(AOwner: TComponent); override;
    property DisplayLabel;
    property ExecuteAccess;
    property OnBeforeExecute;
    property OnAfterExecute;
    property OnBeforeGetResponse;
    property OnAfterGetResponse;
    property OnGetParams;
    property ActionModes default [amInsert, amEdit, amBrowse, amQuery];
  end;

  TDataSetAdapterDataLink = class(TDataLink)
  private
    FAdapter: TComponent;
    FOnDataSetStateChange: TNotifyEvent;
  protected
    procedure RecordChanged(Field: TField); override;
    procedure DataEvent(Event: TDataEvent; Info: Longint); override;
  public
    constructor Create(AAdapter: TComponent);
    property OnDataSetStateChange: TNotifyEvent read FOnDataSetStateChange write FOnDataSetStateChange;
  end;

  TCustomDataSetValuesList = class(TBaseValuesListAdapter, IGetDesigntimeWarnings)
  private
    FDataSet: TDataSet;
    FNameField: string;
    FValueField: string;
    FCache: TNamedVariantsList;
    FCacheInUse: Boolean;
    FIndex: Integer;
    FOnPrepareDataSet: TNotifyEvent;
    FDataSetPrepared: Boolean;
    procedure SetDataSet(const Value: TDataSet);
    procedure CacheValuesList;
    function GetDataSet: TDataSet;
    procedure PrepareDataSet;
  protected
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    function GetNameFieldClass: TComponentClass; override;
    function GetValueFieldClass: TComponentClass; override;
    { IGetDesigntimeWarnings }
    procedure GetDesigntimeWarnings(AWarnings: TAbstractDesigntimeWarnings);
    { INotifyWebActivate }
    procedure ImplNotifyDeactivate; override;
    { IValueListAdapter }
    function ImplGetListValue: Variant; override;
    function ImplGetListName: string;  override;
    function ImplGetListNameOfValue(Value: Variant): string; override;
    { IIteratorAdapter }
    function ImplStartIterator(var OwnerData: Pointer): Boolean; override;
    function ImplNextIteration(var OwnerData: Pointer): Boolean; override;
    procedure ImplEndIterator(OwnerData: Pointer); override;

    property DataSetPrepared: Boolean read FDataSetPrepared write FDataSetPrepared;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property NameField: string read FNameField write FNameField;
    property ValueField: string read FValueField write FValueField;
    property DataSet: TDataSet read GetDataSet write SetDataSet;
    property OnPrepareDataSet: TNotifyEvent read FOnPrepareDataSet write FOnPrepareDataSet;
  end;

  TDataSetValuesList = class(TCustomDataSetValuesList)
  published
    property NameField;
    property ValueField;
    property DataSet;
    property OnPrepareDataSet;
    property Data;
    property Actions;
  end;

  TBaseDataSetAdapterImageField = class(TBaseDataSetAdapterField);

  TDataSetAdapterImageFieldClass = class of TBaseDataSetAdapterImageField;

 procedure AddLocateParamsString(AAdapterName, AKeyName, AKeyValue: string; AParams: TLocateParamsList);

var
  DataSetAdapterImageFieldClass: TDataSetAdapterImageFieldClass;

const
  AllActionParamOptions = [poLocateParams, poCurrentPage];
  AllImageParamOptions = [poLocateParams];

implementation

uses Variants, WebCntxt, AutoAdap, WebDisp, SiteConst;

{ TCustomDataSetAdapter }

function TCustomDataSetAdapter.GetDataSet: TDataSet;
begin
  if not (csLoading in ComponentState) and not DataSetPrepared then
    PrepareDataSet;
  Result := FDataSet;
end;

procedure TCustomDataSetAdapter.SetDataSet(ADataSet: TDataSet);
begin
  if FDataSet <> ADataSet then
  begin
    if Assigned(FDataSet) then
      FDataSet.RemoveFreeNotification(Self);
    if ADataSet <> nil then ADataSet.FreeNotification(Self);
    FDataSet := ADataSet;
    // Dataset affects list of default fields
    Data.ClearDefaultComponents;
    if not (csLoading in ComponentState) then
      NotifyAdapterChange;
    if FDesignerDataLink <> nil then
      FDesignerDataLink.DataSource.DataSet := FDataSet;
  end;
end;

procedure TCustomDataSetAdapter.Notification(AComponent: TComponent; Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (AComponent = FDataSet) then
  begin
    FDataSet := nil;
    Data.ClearDefaultComponents;
    if not (csLoading in ComponentState) then
      NotifyAdapterChange;
  end;
  if (Operation = opRemove) and (AComponent = FMasterAdapter) then
    FMasterAdapter := nil;
end;

procedure ListDataSetFields(AAdapter: TCustomDataSetAdapter; AList: TStrings);
var
  I: Integer;
begin

  AList.Clear;
  if (AAdapter.DataSet <> nil) then
    with AAdapter.Dataset do
    begin
      if not DesigningComponent(AAdapter) then
        AAdapter.DataSet.Open;
      for I := 0 to FieldCount - 1 do
        if Fields[I].InheritsFrom(TMemoField) then
          AList.AddObject(Fields[I].FullName, TObject(TDataSetAdapterMemoField))
        else if (Fields[I].DataType in [ftGraphic, ftTypedBinary]) then
        begin
            if DataSetAdapterImageFieldClass <> nil then
              AList.AddObject(Fields[I].FullName, TObject(DataSetAdapterImageFieldClass))
        end
        else if not (Fields[I].DataType in [ftADT, ftArray, ftDataSet]) then
          AList.AddObject(Fields[I].FullName, TObject(TDataSetAdapterField));
      for I := 0 to AggFields.Count - 1 do
        AList.AddObject(AggFields[I].FullName, TObject(TDataSetAdapterField))
    end;
end;

const
  sDataSetAdapterDeleteAction = 'DeleteRow';  // Do not localize
  sDataSetAdapterNextAction = 'NextRow'; // Do not localize
  sDataSetAdapterPrevAction = 'PrevRow'; // Do not localize
  sDataSetAdapterLastAction = 'LastRow'; // Do not localize
  sDataSetAdapterFirstAction = 'FirstRow'; // Do not localize
  sDataSetAdapterNewAction = 'NewRow'; // Do not localize
  sDataSetAdapterCancelAction = 'Cancel'; // Do not localize
  sDataSetAdapterApplyAction = 'Apply'; // Do not localize
  sDataSetAdapterRefreshAction = 'RefreshRow'; // Do not localize
  sDataSetAdapterEditAction = 'EditRow'; // Do not localize
  sDataSetAdapterBrowseAction = 'BrowseRow'; // Do not localize

procedure ListDataSetActions(AAdapter: TCustomDataSetAdapter; AList: TStrings);
begin
  Assert(AList.Count = 0);
  AList.AddObject(sDataSetAdapterDeleteAction, TObject(TDataSetAdapterDeleteRowAction));
  AList.AddObject(sDataSetAdapterFirstAction, TObject(TDataSetAdapterFirstRowAction));
  AList.AddObject(sDataSetAdapterPrevAction, TObject(TDataSetAdapterPrevRowAction));
  AList.AddObject(sDataSetAdapterNextAction, TObject(TDataSetAdapterNextRowAction));
  AList.AddObject(sDataSetAdapterLastAction, TObject(TDataSetAdapterLastRowAction));
  AList.AddObject(sDataSetAdapterEditAction, TObject(TDataSetAdapterEditRowAction));
  AList.AddObject(sDataSetAdapterBrowseAction, TObject(TDataSetAdapterBrowseRowAction));
  AList.AddObject(sDataSetAdapterNewAction, TObject(TDataSetAdapterNewRowAction));
  AList.AddObject(sDataSetAdapterCancelAction, TObject(TDataSetAdapterCancelRowAction));
  AList.AddObject(sDataSetAdapterApplyAction, TObject(TDataSetAdapterApplyRowAction));
  AList.AddObject(sDataSetAdapterRefreshAction, TObject(TDataSetAdapterRefreshRowAction));
  if AAdapter.PageSize > 0 then
  begin
    AList.AddObject(sPrevPageAction, TObject(TAdapterPrevPageAction));
    AList.AddObject(sGotoPageAction, TObject(TAdapterGotoPageAction));
    AList.AddObject(sNextPageAction, TObject(TAdapterNextPageAction));
  end;
end;

procedure TCustomDataSetAdapter.ImplGetFieldsList(AList: TStrings);
begin
  ListDataSetFields(Self, AList);
end;

procedure AddDefaultDataSetFields(AAdapter: TCustomDataSetAdapter; AComponents: TWebComponentList);
var
  List: TStrings;
begin
  if (AAdapter.DataSet <> nil) then
  begin
    List := TStringList.Create;
    try
      ListDataSetFields(AAdapter, List);
      AddDefaultFields(List, AComponents);
    finally
      List.Free;
    end;
  end;
end;

procedure AddDefaultDataSetActions(AAdapter: TCustomDataSetAdapter; AComponents: TWebComponentList);
var
  List: TStrings;
begin
  List := TStringList.Create;
  try
    ListDataSetActions(AAdapter, List);
    AddDefaultActions(List, AComponents);
  finally
    List.Free;
  end;
end;

destructor TCustomDataSetAdapter.Destroy;
var
  DS: TDataSource;
begin
  inherited;
  FLocateParamsList.Free;
  if FDesignerDataLink <> nil then
  begin
    TDataSetAdapterDataLink(FDesignerDataLink).OnDataSetStateChange := nil;
    DS := FDesignerDataLink.DataSource;
    // Prevent notifications
    FDesignerDataLink.DataSource := nil;
    FDesignerDataLink.Free;
    DS.Free;
  end;
  FDetailAdapters.Free;
end;

{ TBaseDataSetAdapterField }

function TBaseDataSetAdapterField.ImplAsFormatted: string;
var
  DataSet: TDataSet;
  Field: TField;
begin
  Result := '';
  if FDataSetField <> '' then
  begin
    DataSet := GetDataSet;
    DataSet.Open;
    Field := FindField;
    if Field <> nil then
    begin
      if DataSet.Active or not DesigningComponent(Self) then
      begin
        DataSet.Open;
        if Assigned(OnGetDisplayText) then
          OnGetDisplayText(Self, Field, Result)
        else
          Result := Field.DisplayText;
      end
    end;
  end;
end;

function TBaseDataSetAdapterField.GetDataSet: TDataSet;
begin
  if Adapter <> nil then
    Result := Adapter.DataSet
  else
    Result := nil;
end;

function TBaseDataSetAdapterField.GetDataSetFieldValue(Field: TField): Variant;
begin
  Result := Field.Value
end;

function TBaseDataSetAdapterField.ImplGetValue: Variant;
var
  DataSet: TDataSet;
  Field: TField;
begin
  Result := Unassigned;
  if FDataSetField <> '' then
  begin
    CheckViewAccess;
    DataSet := GetDataSet;
    DataSet.Open;
    Field := FindField;
    if Field <> nil then
    begin
      if DataSet.Active or not DesigningComponent(Self) then
      begin
        DataSet.Open;
        if Assigned(OnGetValue) then
          OnGetValue(Self, Field, Result)
        else
          Result := GetDataSetFieldValue(Field)
      end;
    end;
  end;
end;

function TBaseDataSetAdapterField.ImplGetDisplayLabel: string;
var
  Field: TField;
begin
  Result := '';
  Field := FindField;
  if Field <> nil then
    Result := Field.DisplayLabel
end;

function TBaseDataSetAdapterField.ImplGetDisplayWidth: Integer;
var
  Field: TField;
begin
  Result := -1;
  Field := FindField;
  if Field <> nil then
    Result := Field.DisplayWidth
end;

function TBaseDataSetAdapterField.FindField: TField;
var
  DataSet: TDataSet;
begin
  if FField = nil then
    if FDataSetField <> '' then
    begin
      DataSet := GetDataSet;
      if Assigned(DataSet) then
      begin
        FField := DataSet.FindField(FDataSetField);
        if FField <> nil then
          FField.FreeNotification(Self);
      end;
    end;
  Result := FField;
end;

function TBaseDataSetAdapterField.GetReadOnly: Boolean;
var
  Field: TField;
begin
  Result := False;
  Field := FindField;
  if Field <> nil then
    Result := Field.ReadOnly
end;

procedure TBaseDataSetAdapterField.ImplSetFieldName(const Value: string);
begin
  FDataSetField := Value;
  inherited ImplSetFieldName(MakeValidAdapterFieldName(FDataSetField));
end;

function TBaseDataSetAdapterField.GetDisplayStyle(const AAdapterMode: string): string;
begin
  Result := AdapterDisplayHTMLElementTypeNames[GetDisplayStyleType(AAdapterMode)]
end;

function TBaseDataSetAdapterField.GetInputStyle(const AAdapterMode: string): string;
begin
  Result := AdapterInputHTMLElementTypeNames[GetInputStyleType(AAdapterMode)];
end;

function TBaseDataSetAdapterField.GetAdapter: TCustomDataSetAdapter;
begin
  if (inherited Adapter <> nil) and (inherited Adapter is TCustomDataSetAdapter) then
    Result := TCustomDataSetAdapter(inherited Adapter)
  else
    Result := nil;
end;

procedure TBaseDataSetAdapterField.SetDataSetField(const Value: string);
begin
  if FDataSetField <> Value then
  begin
    FieldName := Value;
  end;
end;

procedure TBaseDataSetAdapterField.GetKeyParams(Params: TLocateParamsList);
begin
  if (Adapter <> nil) then
    Adapter.GetKeyParams(Params, True)
end;

procedure TBaseDataSetAdapterField.CheckOrigValue(
  AActionRequest: IActionRequest; AFieldIndex: Integer);
begin
  ImplCheckOrigValue(AActionRequest, AFieldIndex);
end;

procedure TBaseDataSetAdapterField.ImplCheckOrigValue(
  AActionRequest: IActionRequest; AFieldIndex: Integer);
begin
  // Do nothing
end;

function TBaseDataSetAdapterField.CheckValueChange(
  AActionRequest: IActionRequest; AFieldIndex: Integer): Boolean;
begin
  Result := ImplCheckValueChange(AActionRequest, AFieldIndex);
end;

function TBaseDataSetAdapterField.ImplCheckValueChange(
  AActionRequest: IActionRequest; AFieldIndex: Integer): Boolean;
begin
  // Do nothing
  Result := False;
end;

procedure TBaseDataSetAdapterField.ImplUpdateValue(
  AActionRequest: IActionRequest; AFieldIndex: Integer);
begin
  // Do nothing
end;

procedure TBaseDataSetAdapterField.UpdateValue(
  AActionRequest: IActionRequest; AFieldIndex: Integer);
begin
  ImplUpdateValue(AActionRequest, AFieldIndex);
end;

function TBaseDataSetAdapterField.GetDisplayStyleType(const AAdapterMode: string): TAdapterDisplayHTMLElementType;
begin
  Result := htmldText;
end;

function TBaseDataSetAdapterField.GetInputStyleType(const AAdapterMode: string): TAdapterInputHTMLElementType;
begin
  Result := htmliTextInput;
end;

function TBaseDataSetAdapterField.GetViewModeType(const AAdapterMode: string): TAdapterDisplayViewModeType;
var
  M: TDataSetAdapterMode;
begin
  if GetReadOnly then
    Result := htmlvmDisplay
  else
  begin
    if Adapter <> nil then
      M := Adapter.StringToMode(AAdapterMode)
    else
      M := amBrowse;
    if M in [amBrowse] then
      Result := htmlvmDisplay
    else
      Result := htmlvmInput;
  end;
end;

function TBaseDataSetAdapterField.GetViewMode(const AAdapterMode: string): string;
begin
  Result := AdapterDisplayViewModeTypeNames[GetViewModeType(AAdapterMode)]
end;

constructor TBaseDataSetAdapterField.Create(AOwner: TComponent);
begin
  inherited;
  FieldModes := [amInsert, amEdit, amBrowse, amQuery];
  FieldFlags := [ffInOrigValues];
end;

function TBaseDataSetAdapterField.ImplGetRequired: Boolean;
var
  Field: TField;
begin
  Field := FindField;
  if Field <> nil then
    Result := Field.Required
  else
    Result := False;
end;

function TBaseDataSetAdapterField.ImplGetVisible: Boolean;
var
  Field: TField;
begin
  Result := Adapter.Mode in FieldModes;
  if Result then
  begin
    Field := FindField;
    if Field <> nil then
      Result := Field.Visible;
  end;
end;

procedure TBaseDataSetAdapterField.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited;
  if (Operation = opRemove) and (FField = AComponent) then
    FField := nil;
end;

{ TCustomDataSetAdapterField }

function TCustomDataSetAdapterField.ImplGetPrevValue: Variant;
var
  DataSet: TDataSet;
  Field: TField;
  Value: IActionFieldValue;
begin
  Result := Unassigned;
  if EchoActionFieldValue then
  begin
    Value := ActionOrigValue;
    if (Value <> nil) and (Value.ValueCount > 0) then
      Result := Value.Values[0]
    else
      Result := Unassigned;
  end
  else if FDataSetField <> '' then
  begin
    DataSet := GetDataSet;
    if Assigned(DataSet) then
    begin
      if DesigningComponent(Self) and not DataSet.Active then
        Field := nil
      else
      begin
        DataSet.Open;
        Field := DataSet.FindField(FDataSetField);
      end;
      if Assigned(Field) then
        Result := Field.Value
      else
        Result := Unassigned;
    end;
  end;
end;

function TCustomDataSetAdapterField.GetAdapterValuesList: IValuesListAdapter;
begin
  Result := FValuesList;
end;

procedure TCustomDataSetAdapterField.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and AComponent.IsImplementorOf(FValuesList) then
    FValuesList := nil;
end;

procedure TCustomDataSetAdapterField.SetValuesList(
  const Value: IValuesListAdapter);
begin
  ReferenceInterface(FValuesList, opRemove);
  FValuesList := Value;
  ReferenceInterface(FValuesList, opInsert);
end;

function TCustomDataSetAdapterField.ImplGetValue: Variant;
var
  Value: IActionFieldValue;
begin
  CheckViewAccess;
  if EchoActionFieldValue then
  begin
    Value := ActionValue;
    if Value <> nil then
      if Value.ValueCount > 0 then
        Result := Value.Values[0]
      else
        // No values passed.  Get data value
        Result := inherited ImplGetValue
    else
      Result := Unassigned;
  end
  else if Adapter.Mode <> amQuery then
    Result := inherited ImplGetValue;
end;

function GetActionFieldValues(AActionRequest: IActionRequest): IActionFieldValues;
begin
  if not Supports(AActionRequest, IActionFieldValues, Result) then
    Assert(False);
end;

procedure TCustomDataSetAdapterField.ImplCheckOrigValue(
  AActionRequest: IActionRequest; AFieldIndex: Integer);
var
  Field: TField;
  OrigValue: OleVariant;
  FieldValue: WideString;
  OrigFieldValue: IActionFieldValue;
begin
  if ffInOrigValues in FieldFlags then
  begin
    Assert(Adapter <> nil);
    if Adapter.DataSet = nil then
      Adapter.RaiseNilDataSet;
    with GetActionFieldValues(AActionRequest) do
      OrigFieldValue := OrigValues[AFieldIndex];
    if OrigFieldValue.ValueCount > 0 then
    begin
      Adapter.DataSet.Open;
      Field := Adapter.DataSet.FindField(DataSetField);
      if Field = nil then
        Adapter.RaiseFieldNotFound(DataSetField);
      if (Field.FieldKind <> fkCalculated) and
         (OrigFieldValue.ValueCount = 1) then
      begin
        OrigValue := OrigFieldValue.Values[0];
        if not VarIsEmpty(OrigValue) then
        begin
          if VarIsNull(Field.Value) then
            FieldValue := ''
          else
            FieldValue := Field.Value;
          if (OrigValue <> FieldValue) then
            Adapter.RaiseFieldChangedByAnotherUser(FieldName);
        end;
      end;
    end;
  end;
end;

procedure TCustomDataSetAdapterField.ImplUpdateValue(
  AActionRequest: IActionRequest; AFieldIndex: Integer);
var
  Field: TField;
  FieldValue: IActionFieldValue;
begin
  Assert(Adapter <> nil);
  CheckModifyAccess;
  with GetActionFieldValues(AActionRequest) do
    FieldValue := Values[AFieldIndex];
  if Adapter.Mode <> amQuery then
  begin
    if FieldValue.ValueCount > 0 then
    begin
      Field := FindField;
      if Field = nil then
        Adapter.RaiseFieldNotFound(DataSetField);
      if (Field.FieldKind <> fkCalculated) and
         (FieldValue.ValueCount = 1) then
      begin
        if Assigned(OnUpdateValue) then
          OnUpdateValue(Self, Field, FieldValue.Values[0])
        else
          if TestValueChange(Field, FieldValue.Values[0]) then
            Field.Value := FieldValue.Values[0]
      end
      else
        RaiseMultipleValuesException(FieldName)
    end
    else if FieldValue.FileCount > 0 then
      RaiseFileUploadNotSupported(FieldName);
  end;
end;

function TCustomDataSetAdapterField.ImplCheckValueChange(
  AActionRequest: IActionRequest; AFieldIndex: Integer): Boolean;
var
  OrigFieldValue, FieldValue: IActionFieldValue;
  I: Integer;
begin
  if ffInOrigValues in FieldFlags then
  begin
    with GetActionFieldValues(AActionRequest) do
    begin
      OrigFieldValue := OrigValues[AFieldIndex];
      FieldValue := Values[AFieldIndex];
    end;

    if FieldValue.ValueCount = OrigFieldValue.ValueCount then
    begin
      Result := False;
      for I := 0 to FieldValue.ValueCount - 1 do
        if FieldValue.Values[I] <> OrigFieldValue.Values[I] then
        begin
          Result := True;
          break;
        end
    end
    else
      Result := False;
  end
  else
    // Assume value has been changed
    Result := True;
end;

function TCustomDataSetAdapterField.GetInputStyleType(const AAdapterMode: string): TAdapterInputHTMLElementType;
begin
  if ValuesList <> nil then
    Result := htmliSelect
  else
    Result := inherited GetInputStyleType(AAdapterMode);
end;

function TCustomDataSetAdapterField.GetPrevValue: Variant;
begin
  Result := ImplGetPrevValue;
end;

function TCustomDataSetAdapterField.GetNeedPrevValue: Boolean;
begin
  Result := ImplGetNeedPrevValue;
end;

function TCustomDataSetAdapterField.ImplGetNeedPrevValue: Boolean;
begin
  case Adapter.Mode of
    amQuery, amInsert, amBrowse: Result := False;
    amEdit: Result := ffInOrigValues in FieldFlags;
  else
    Result := False;
    Assert(False);
  end;
end;

{ TCustomDataSetAdapter }

procedure TCustomDataSetAdapter.ImplGetActionsList(AList: TStrings);
begin
  ListDataSetActions(Self, AList);
end;

procedure TCustomDataSetAdapter.AddDefaultFields(AComponents: TWebComponentList);
begin
  AddDefaultDataSetFields(Self, AComponents);
  CreateDataLink; // Need a datalink to monitor changes to dataset
end;

procedure TCustomDataSetAdapter.OnDataSetStateChange(Sender: TObject);
begin
  Data.ClearDefaultComponents;
end;

procedure TCustomDataSetAdapter.AddDefaultActions(AComponents: TWebComponentList);
begin
  AddDefaultDataSetActions(Self, AComponents);
end;

function TCustomDataSetAdapter.GetAdapterMode: string;
begin
  if InDefaultMode then
    Result := ''
  else
    Result := DataSetAdapterModeNames[GetMode];
end;

procedure TCustomDataSetAdapter.SetAdapterMode(const AValue: string);
begin
  if AValue = '' then
    InDefaultMode := True
  else
    Mode := StringToMode(AValue);
end;

procedure TCustomDataSetAdapter.RestoreDefaultAdapterMode;
begin
  InDefaultMode := True;
end;

constructor TCustomDataSetAdapter.Create(AOwner: TComponent);
begin
  inherited;
  FInIterator := False;
  FDetailAdapters := TComponentList.Create(False {Not owned});
  FLocateParamsList := TLocateParamsList.Create;
  InDefaultMode := True;
  CreateDataLink;
end;

procedure TCustomDataSetAdapter.CreateDataLink;
begin
  if FDesignerDataLink = nil then
  begin
    if Assigned(NotifyPossibleHTMLChange) or
       (DesigningComponent(Self) and (Data.WebFields.Count = 0)) then
    begin
      FDesignerDataLink := TDataSetAdapterDataLink.Create(nil);
      FDesignerDataLink.Datasource := TDataSource.Create(nil);
      FDesignerDataLink.DataSource.DataSet := FDataSet;
      TDataSetAdapterDataLink(FDesignerDataLink).OnDataSetStateChange := OnDataSetStateChange;
    end;
  end;
end;

procedure TCustomDataSetAdapter.SetMode(
  const Value: TDataSetAdapterMode);
begin
  FInDefaultMode := False;
  if Value <> Mode then
  begin
    if DataSetPrepared then
      if DataSet <> nil then
        DataSet.Cancel;
    FMode := Value;
    DataSetPrepared := False;
  end;
end;

function TCustomDataSetAdapter.StringToMode(const AValue: string): TDataSetAdapterMode;
var
  I: TDataSetAdapterMode;
begin
  if AValue = '' then
    Result := GetDefaultMode
  else
  begin
    for I := Low(TDataSetAdapterMode) to High(TDataSetAdapterMode) do
    begin
      if SameText(DataSetAdapterModeNames[I], AValue) then
      begin
        Result := I;
        Exit;
      end;
    end;
    raise EAdapterException.CreateFmt(sUnknownAdapterMode, [AValue]);
  end;
end;

function TCustomDataSetAdapter.GetMode: TDataSetAdapterMode;
var
  Mode: string;
  AdapterModes: IAdapterModes;
begin
  if GetEchoActionFieldValues then
  begin
    if Supports(WebContext.AdapterRequest, IAdapterModes, AdapterModes) and
      AdapterModes.FindAdapterMode(Self, Mode) then
      Result := StringToMode(Mode)
    else
      Result := GetDefaultMode
  end
  else
  begin
    if InDefaultMode then
      Result := GetDefaultMode
    else
      Result := FMode;
  end;
end;

function TCustomDataSetAdapter.GetDefaultMode: TDataSetAdapterMode;
begin
  Result := amBrowse;
end;

procedure TCustomDataSetAdapter.ImplNotifyDeactivate;
begin
  inherited;
  if FDataSet <> nil then
    FDataSet.Close;
  InDefaultMode := True;
  DataSetPrepared := False;
  LocateParamsList.Clear;
  FInIterator := False;
  FDataSetRecNo := 0;
  CurrentPage := 0;
  AdapterRowNotFound := nil;
end;

function TCustomDataSetAdapter.ImplCanAddActionClass(
  AParent: TComponent; AClass: TClass): Boolean;
begin
  Result :=
    inherited ImplCanAddActionClass(AParent, AClass) or
    AClass.InheritsFrom(TCustomDataSetAdapterAction);
end;

function TCustomDataSetAdapter.ImplCanAddFieldClass(AParent: TComponent;
  AClass: TClass): Boolean;
begin
  Result :=
    inherited ImplCanAddActionClass(AParent, AClass) or
    Supports(AClass, IDataSetAdapterFieldClass)
end;

function TCustomDataSetAdapter.GetProviderSupport: IProviderSupport;
begin
  Result := nil;
  if DataSet <> nil then
     Result := IProviderSupport(DataSet);
end;

function TCustomDataSetAdapter.GetKeyFields: string;
var
  ProviderSupport: IProviderSupport;
  GetKeyName: IGetDataSetKeyName;
  I: Integer;
  S: string;
  ComponentList: TWebComponentList;
begin
  if DataSet <> nil then
  begin
    ComponentList := GetVisibleFields;
    for I := 0 to ComponentList.Count - 1 do
    begin
      if Supports(ComponentList.WebComponents[I], IGetDataSetKeyName, GetKeyName) then
      begin
        S := GetKeyName.GetKeyName;
        if S <> '' then
        begin
          if Result <> '' then Result := Result + ';';
          Result := Result + S;
        end;
      end;
    end;
    if Result = '' then
    begin
      ProviderSupport := GetProviderSupport;
      if Assigned(ProviderSupport) then
        Result := ProviderSupport.PSGetKeyFields
      else
        Result := '';
    end;
  end;
end;

procedure TCustomDataSetAdapter.GetKeyParams(AParams: TLocateParamsList; ARecurse: Boolean);
var
  I: Integer;
  List: TComponentList;
  S: TStrings;
begin
  if ARecurse then
  begin
    List := GetMasterDetailAdapters;
    try
      if List <> nil then
        for I := 0 to List.Count - 1 do
          (List[I] as TCustomDataSetAdapter).GetKeyParams(AParams, False)
      else
        ARecurse := False;
    finally
      List.Free;
    end;
  end;

  if not ARecurse then
  begin
    S := TStringList.Create;
    try
      GetKeyParamStrings(S);
      if S.Count > 0 then
        with AParams.Add do
        begin
          AdapterName := Self.Name;
          for I := 0 to S.Count - 1 do
            AddParam(S[I]);
        end;
    finally
      S.Free;
    end;
  end;
end;

procedure TCustomDataSetAdapter.GetKeyParamStrings(AValues: TStrings);
var
  KeyFields: string;
  FieldList: TList;
  Field: TField;
  I: Integer;
begin
  KeyFields := GetKeyFields;
  if KeyFields <> '' then
  begin
    FieldList := TList.Create;
    try
      if DataSet.Active or not DesigningComponent(Self) then
      begin
        DataSet.Open;
          DataSet.GetFieldList(FieldList, KeyFields);
      end;
      if FieldList.Count > 0 then
        try
        for I := 0 to FieldList.Count - 1 do
        begin
          Field := TField(FieldList[I]);
          AValues.Add(Format('%s=%s', [Field.FieldName, Field.AsString]));
        end;
        except
          // Use an exception to catch EOF
        end;
    finally
      FieldList.Free;
    end;
  end;
end;

function TCustomDataSetAdapter.Locate: Boolean;
begin
  try
    if DataSet = nil then
      RaiseNilDataSet;
    if not SilentLocate(LocateParamsList, True) then
      RaiseRowNotFound
  except
    // Add to error list
    on E: Exception do
    begin
      Errors.AddError(E);
      Result := False;
      Exit;
    end;
  end;
  Result := True;
end;

procedure  TCustomDataSetAdapter.ApplyAdapterMode(AActionRequest: IActionRequest);
var
  Mode: string;
  Intf: IAdapterModes;
  List: TComponentList;
  C: TCustomDataSetAdapter;
  I: Integer;
begin
  if Supports(AActionRequest, IAdapterModes, Intf) then
  begin
    List := GetMasterDetailAdapters;
    if List <> nil then
      try
        for I := 0 to List.Count - 1 do
        begin
          C := (List[I] as TCustomDataSetAdapter);
          if Intf.FindAdapterMode(C, Mode) then
            C.SetAdapterMode(Mode)
          else
            C.RestoreDefaultAdapterMode;
        end;
      finally
        List.Free;
      end
    else
      if Intf.FindAdapterMode(Self, Mode) then
        SetAdapterMode(Mode)
      else
        RestoreDefaultAdapterMode;
  end
  else
    Assert(False); // interface not supported
end;


function TCustomDataSetAdapter.LocateAndApply(AActionRequest: IActionRequest): Boolean;

  function CalcAdapterMode: TDataSetAdapterMode;
  var
    List: TComponentList;
    I: Integer;
  begin
    Result := Mode;
    if Mode = amBrowse then
    begin
      List := GetMasterDetailAdapters;
      if List <> nil then
        try
          for I := 0 to List.Count - 1 do
          begin
            if (List[I] as TCustomDataSetAdapter).Mode = amEdit then
            begin
              Result := amEdit;
              break;
            end;
          end;
        finally
          List.Free;
        end
    end;
  end;
var
  Found: Boolean;
  List: TComponentList;
  I: Integer;
  ActionFieldValuesOfAdapter: IActionFieldValuesOfAdapter;
  LMode: TDataSetAdapterMode;
begin
  ExtractRequestParams(AActionRequest);
  Result := True;
  try
    ApplyAdapterMode(AActionRequest);
    LMode := CalcAdapterMode;
    if LMode in [amInsert, amEdit] then
    begin
      if DataSet = nil then
        Self.RaiseNilDataSet;
      Found := SilentLocate(LocateParamsList, True);
      if LMode = amInsert then
      begin
        if DataSet = nil then
          Self.RaiseNilDataSet;
        DataSet.Open;
        DataSet.Insert;
        // Update even if locate fails
        Result := UpdateRecords(AActionRequest);
      end
      else
      begin
        if Found then
        begin
          if Supports(AActionRequest, IActionFieldValuesOfAdapter, ActionFieldValuesOfAdapter) then
          begin
            List := GetMasterDetailAdapters;
            try
              if List <> nil then
              begin
                for I := 0 to List.Count - 1 do
                  if ActionFieldValuesOfAdapter.LocateActionFieldValuesOfAdapter(List[I] as TComponent) then
                  begin
                    Result := (List[I] as TCustomDataSetAdapter).UpdateRecords(AActionRequest);
                    if not Result then
                      Break;
                  end
              end
              else
                Result := UpdateRecords(AActionRequest);
            finally
              List.Free;
            end
          end
          else
            Result := UpdateRecords(AActionRequest);
          // Relocate in case we updated repositioned during update
          SilentLocate(LocateParamsList, False);
        end;
        if not Found then
          Self.RaiseRowNotFound
      end
    end
    else
    begin
      if DataSet = nil then
        Self.RaiseNilDataSet;
      DataSet.Open;
      if not DataSet.EOF then
        Result := Locate;
    end;
  except
    on E: Exception do
    begin
      Self.Errors.AddError(E);
      Result := False;
      Exit;
    end;
  end;
  if Result then
  begin
    if (LMode = amInsert) then
      Mode := amEdit;
    if (FDataSet <> nil) and (not DataSet.Active) then
      Dataset.Open;
  end;
end;

function TCustomDataSetAdapter.GetMasterDetailAdapters: TComponentList;

  procedure Add(AMaster: TCustomDataSetAdapter);
  var
    I: Integer;
  begin
    Result.Add(AMaster);
    for I := 0 to AMaster.DetailAdapters.Count - 1 do
      Add(AMaster.DetailAdapters[I] as TCustomDataSetAdapter);
  end;
var
  Master: TCustomDataSetAdapter;
begin
  Result := nil;
  if (MasterAdapter <> nil) or
    (DetailAdapters.Count > 0) then
  begin
    Result := TComponentList.Create(False {Not owned});
    try
      Master := Self;
      while Master.MasterAdapter <> nil do
        Master := Master.MasterAdapter;
      Add(Master)
    except
      Result.Free;
    end;
  end;
end;

type
  TLocateParamsWrapper = class(TInterfacedObject, IKeyParams)
  private
    FLocateParams: TLocateParams;
  protected
    function Count: Integer;
    function GetName(I: Integer): string;
    function GetValue(I: Integer): string;
  public
    constructor Create(ALocateParams: TLocateParams);
  end;

function TLocateParamsWrapper.Count: Integer;
begin
  Result := FLocateParams.Count;
end;

constructor TLocateParamsWrapper.Create(ALocateParams: TLocateParams);
begin
  inherited Create;
  FLocateParams := ALocateParams;
end;

function TLocateParamsWrapper.GetName(I: Integer): string;
begin
  Result := FLocateParams.GetParamName(I);
end;

function TLocateParamsWrapper.GetValue(I: Integer): string;
begin
  Result := FLocateParams.GetParamValue(I);
end;

function TCustomDataSetAdapter.SilentLocate(AParams: TLocateParamsList; ARecurse: Boolean): Boolean;
var
  I: Integer;
  L: TLocateParams;
  List: TComponentList;
  A: TCustomDataSetAdapter;
begin
  Result := True;
  if ARecurse then
  begin
    List := GetMasterDetailAdapters;
    try
      if List <> nil then
        for I := 0 to List.Count - 1 do
        begin
          A := (List[I] as TCustomDataSetAdapter);
          if A.Mode = amInsert then
            break;
          Result := A.SilentLocate(AParams, False);
          if not Result then
          begin
            AdapterRowNotFound := (List[I] as TCustomDataSetAdapter);
            break;
          end;
        end
      else
        ARecurse := False;
    finally
      List.Free;
    end;
  end;

  if (not ARecurse) and (Mode <> amInsert) then
  begin
    L := AParams.ItemByAdapterName(Self.Name);
    if L <> nil then
      Result := LocateKeyParams(TLocateParamsWrapper.Create(L))
    else
      Result := True;
  end;
end;

procedure TCustomDataSetAdapter.RaiseNilDataSet;
begin
  raise EAdapterException.Create(sNilAdapterDataSet);
end;

procedure TCustomDataSetAdapter.RaiseRowNotFound;
var
  DS: TDataSet;
begin
  if AdapterRowNotFound <> nil then
    DS := AdapterRowNotFound.DataSet
  else
    DS := Self.DataSet;

  raise EAdapterException.CreateFmt(sAdapterRowNotFound, [DS.Name]);
end;

procedure TCustomDataSetAdapter.RaiseFieldChangedByAnotherUser(
  const AFieldName: string);
begin
  raise EAdapterFieldException.Create(sFieldChangedByAnotherUser,
    AFieldName);
end;

procedure TCustomDataSetAdapter.RaiseFieldNotFound(
  const AFieldName: string);
begin
  raise EAdapterException.CreateFmt(sAdapterFieldNotFound, [AFieldName]);
end;

procedure TCustomDataSetAdapter.GetDesigntimeWarnings(
  AWarnings: TAbstractDesigntimeWarnings);
begin
  if DataSet = nil then
    AWarnings.AddString(Format(sDataSetPropertyIsNil, [Self.Name]));
  if (DataSet <> nil) and (DataSet.Active = True) then
    if GetKeyFields = '' then
      AWarnings.AddString(Format(sDataSetUnknownKeyFields, [Self.Name, DataSet.Name]));
  if (DataSet <> nil) and (not DataSet.Active) then
    AWarnings.AddString(Format(sDataSetNotActive, [Self.Name, DataSet.Name]));
end;

function TCustomDataSetAdapter.LocateKeyParams(AParams: IKeyParams): Boolean;
var
  I: Integer;
  KeyFields: string;
  FieldList: TStrings;
  Field: TField;
  FieldName: string;
  KeyValues: OleVariant;
begin
  Result := DataSet <> nil;
  if Result then
  begin
    DataSet.Open;
    FieldList := TStringList.Create;
    try
      for I := 0 to AParams.Count - 1 do
      begin
        FieldName := AParams.Names[I];
        Field := DataSet.FindField(FieldName);
        if Assigned(Field) then
          FieldList.AddObject(AParams.Values[I], Field);
      end;
      if FieldList.Count <> 0 then
      begin
        if FieldList.Count > 1 then
        begin
          KeyValues := VarArrayCreate([0, FieldList.Count-1], varVariant);
          for I := 0 to FieldList.Count - 1 do
          begin
            Field := TField(FieldList.Objects[I]);
            if KeyFields <> '' then KeyFields := KeyFields + ';';
            KeyFields := KeyFields + Field.FieldName;
            if FieldList[I] = '' then
              KeyValues[I] := Null
            else
              KeyValues[I] := FieldList[I];
          end;
        end
        else
        begin
          KeyFields := TField(FieldList.Objects[0]).FieldName;
          if FieldList[0] = '' then
            KeyValues := Null
          else
            KeyValues := FieldList[0];
        end;
        Result := DataSet.Locate(KeyFields, KeyValues, []);
      end
      else
        Result := True;  // No locate params
    finally
      FieldList.Free;
    end;
  end;
end;

type
  TAdapterRecordKeysWrapper = class(TInterfacedObject, IKeyParams)
  private
    FKeys: IAdapterRecordKeys;
  protected
    function Count: Integer;
    function GetName(I: Integer): string;
    function GetValue(I: Integer): string;
  public
    constructor Create(AKeys: IAdapterRecordKeys);
  end;

function TAdapterRecordKeysWrapper.Count: Integer;
begin
  Result := FKeys.GetRecordKeyCount;
end;

constructor TAdapterRecordKeysWrapper.Create(AKeys: IAdapterRecordKeys);
begin
  inherited Create;
  FKeys := AKeys;
end;

function TAdapterRecordKeysWrapper.GetName(I: Integer): string;
begin
  Result := FKeys.RecordKeyNames[I];
end;

function TAdapterRecordKeysWrapper.GetValue(I: Integer): string;
begin
  Result := FKeys.RecordKeyValues[I];
end;

function TCustomDataSetAdapter.LocateRequestRecord(AActionRequest: IActionRequest): Boolean;
var
  AdapterRecordKeys: IAdapterRecordKeys;
begin
  Result := True;
  try
    if Supports(AActionRequest, IAdapterRecordKeys, AdapterRecordKeys) then
      if AdapterRecordKeys.GetRecordKeyCount > 0 then
        Result := LocateKeyParams(TAdapterRecordKeysWrapper.Create(AdapterRecordKeys));
  except
    on E: Exception do
    begin
      Errors.AddError(E);
      Result := False;
      Exit;
    end;
  end;
end;

procedure TCustomDataSetAdapter.UpdateFieldsValidateValues(
  AActionRequest: IActionRequest; AAdapterFields: TObjectList);
var
  I: Integer;
  CheckOrigValue: ICheckOrigValue;
begin
  if Mode = amQuery then
  begin
  end
  else
    if DataSet.State <> dsInsert then
      if LocateRequestRecord(AActionRequest) then
        for I := 0 to AAdapterFields.Count - 1 do
          try
            if Supports(AAdapterFields[I], ICheckOrigValue, CheckOrigValue) then
              CheckOrigValue.CheckOrigValue(AActionRequest, I);
          except
            on E: Exception do
              Errors.AddError(E);
          end;
   if Errors.ErrorCount = 0 then
     inherited UpdateFieldsValidateValues(AActionRequest, AAdapterFields);
end;

function TCustomDataSetAdapter.UpdateFieldsGetAnyChanges(
  AActionRequest: IActionRequest; AAdapterFields: TObjectList): Boolean;
begin
  if Mode = amQuery then
    Result := True
  else if DataSet.State = dsInsert then
    Result := True
  else
    Result := LocateRequestRecord(AActionRequest) and
      inherited UpdateFieldsGetAnyChanges(AActionRequest, AAdapterFields);
end;

procedure TCustomDataSetAdapter.UpdateFieldsUpdateValues(
  AActionRequest: IActionRequest; AAdapterFields: TObjectList);
begin
  if Mode = amQuery then
  begin
    inherited UpdateFieldsUpdateValues(AActionRequest, AAdapterFields);
  end
  else
  begin
    if LocateRequestRecord(AActionRequest) then
    begin
      DataSet.Edit;
      inherited UpdateFieldsUpdateValues(AActionRequest, AAdapterFields);
      if (Errors.ErrorCount = 0) and
       (DataSet.State in [dsEdit, dsInsert]) then
        DataSet.Post;
      DataSet.Cancel;
    end;
  end;
end;

procedure TCustomDataSetAdapter.UpdateFieldsExecuteValues(
  AActionRequest: IActionRequest; AAdapterFields: TObjectList);
begin
  if Mode = amQuery then
  begin
    inherited UpdateFieldsUpdateValues(AActionRequest, AAdapterFields);
  end
  else
  begin
    if LocateRequestRecord(AActionRequest) then
    begin
      inherited UpdateFieldsExecuteValues(AActionRequest, AAdapterFields);
    end;
  end;
end;

function TCustomDataSetAdapter.GetNeedAdapterMode: Boolean;
begin
  Result := True;
end;

procedure TCustomDataSetAdapter.GetAdapterModeNames(AStrings: TStrings);
var
  I: TDataSetAdapterMode;
begin
  for I := Low(TDataSetAdapterMode) to High(TDataSetAdapterMode) do
    AStrings.Add(DataSetAdapterModeNames[I]);
end;

const
  sQueryParam = '_q';  // Do not localize
  sLocateParam = '_l'; // Do not localize

procedure TCustomDataSetAdapter.EncodeActionParams(
  AParams: IAdapterItemRequestParams);
begin
  EncodeActionParamsFlags(AParams, AllActionParamOptions);
end;

procedure TCustomDataSetAdapter.EncodeActionParamsFlags(
  AParams: IAdapterItemRequestParams;
  AOptions: TDataSetAdapterRequestParamOptions);
var
  I, J: Integer;
  L: TLocateParamsList;
  P: TLocateParams;
begin
  if poCurrentPage in AOptions then
    inherited EncodeActionParams(AParams);
  if poLocateParams in AOptions then
  begin
    L := nil;
    try
      if (DataSet <> nil) and (DataSet.State = dsInsert) then
        L := LocateParamsList
      else if DataSet <> nil then
      begin
        L := TLocateParamsList.Create;
        GetKeyParams(L, True);
      end;
      if L <> nil then  
      begin 
        for I := 0 to L.Count - 1 do
        begin
          P := L[I];
          for J := 0 to P.Count - 1 do
          begin
            if (P.AdapterName = '') or (P.AdapterName = Self.Name) then
              AParams.ParamValues.Add(Format('%s%s', [sLocateParam, P[J]]))
            else
              AParams.ParamValues.Add(Format('%s-%s-%s', [sLocateParam, P.AdapterName, P[J]]));
          end;
        end;
      end;  
    finally
      if L <> LocateParamsList then
        L.Free;
    end;
  end;
end;

function GetAdapterRequestParamsIntf(AAdapterRequest: IUnknown): IAdapterRequestParams;
begin
  if not Supports(AAdapterRequest, IAdapterRequestParams, Result) then
    Assert(False);
end;

procedure AddLocateParamsString(AAdapterName, AKeyName, AKeyValue: string; AParams: TLocateParamsList);
var
  P: Integer;
  Item: TLocateParams;
begin
  if AKeyName[1] = '-' then
  begin
    Delete(AKeyName, 1, 1);
    P := Pos('-', AKeyName);
    if (P >= 1) and (Length(AKeyName) > 1) then
    begin
      AAdapterName := Copy(AKeyName, 1, P-1);
      AKeyName := Copy(AKeyName, P+1, MaxInt);
    end
    else
      Assert(False); // Expected '-'
  end;
  Item := AParams.ItemByAdapterName(AAdapterName);
  if Item = nil then
  begin
    Item := AParams.Add;
    Item.AdapterName := AAdapterName;
  end;
  with Item do
    AddParam(AKeyName, AKeyValue);
end;

procedure TCustomDataSetAdapter.ExtractRequestParams(
  ARequest: IUnknown);
begin
  ExtractRequestParamsFlags(ARequest, AllActionParamOptions);
end;

procedure TCustomDataSetAdapter.ExtractRequestParamsFlags(
  ARequest: IUnknown;
  AOptions: TDataSetAdapterRequestParamOptions);
var
  Params: IAdapterRequestParams;
  I: Integer;
  S: string;
  AdapterName: string;
  P: Integer;
  Item: TLocateParams;
begin
  Params := GetAdapterRequestParamsIntf(ARequest);
  Assert((not (poLocateParams in AOptions)) or (LocateParamsList.Count = 0));
  Assert((not (poCurrentPage in AOptions)) or (CurrentPage = 0));
  if poLocateParams in AOptions then
  begin
    if MasterAdapter <> nil then
      MasterAdapter.ExtractRequestParamsFlags(ARequest, [poLocateParams]);
    for I := 0 to Params.ParamCount - 1 do
    begin
      if Copy(Params.ParamNames[I], 1, Length(sLocateParam)) = sLocateParam then
      begin
        AdapterName := Self.Name;
        S := Copy(Params.ParamNames[I], Length(sLocateParam)+1, MaxInt);

        if S[1] = '-' then
        begin
          Delete(S, 1, 1);
          P := Pos('-', S);
          if (P >= 1) and (Length(S) > 1) then
          begin
            AdapterName := Copy(S, 1, P-1);
            S := Copy(S, P+1, MaxInt);
          end
          else
            Assert(False); // Expected '-'
        end;
        Item := LocateParamsList.ItemByAdapterName(AdapterName);
        if Item = nil then
        begin
          Item := LocateParamsList.Add;
          Item.AdapterName := AdapterName;
        end;
        with Item do
          AddParam(S, Params.ParamValues[I]);
        (*
        AddLocateParamsString(AdapterName, S, Params.ParamValues[I], LocateParamsList);
        *)

      end;
    end;
  end;
  if poCurrentPage in AOptions then
  begin
    inherited ExtractRequestParams(ARequest);
  end;
end;

procedure TCustomDataSetAdapter.PrepareDataSet;
var
  ComponentList: TWebComponentList;
  I: Integer;
  PrepareDataSet: IPrepareDataSet;
begin
  DataSetPrepared := True;
  if Assigned(OnPrepareDataSet) then
    OnPrepareDataSet(Self);
  if Assigned(DataSet) then
    DataSet.Cancel;
  ComponentList := GetVisibleFields;
  for I := 0 to ComponentList.Count - 1 do
    if Supports(ComponentList.WebComponents[I], IPrepareDataSet, PrepareDataSet) then
      PrepareDataSet.PrepareDataSet;
end;

function TCustomDataSetAdapter.GetHiddenFieldOptions: TAdapterHiddenFieldOptions;
begin
  case Mode of
    amInsert: Result := [hoMode];
    amQuery: Result := [hoMode];
    amBrowse: Result := [hoMode];
    amEdit: Result := [hoMode, hoOrigValues, hoRecordKeys];
  else
    Assert(False); // Unknown mode
  end;
end;

function TCustomDataSetAdapter.GetEOF: Boolean;
begin
  Result := (FDataSet = nil) or FDataSet.EOF;
end;

function TCustomDataSetAdapter.GetFirstRecord: Boolean;
begin
  Result := (FDataSet <> nil) and (FDataSet.Active or not DesigningComponent(Self));
  if Result then
  begin
    DataSet.Open;
    FDataSet.First;
    FDataSetRecNo := 0;
    FInIterator := True;
    Result := not FDataSet.EOF;
  end;
end;

function TCustomDataSetAdapter.GetNextRecord: Boolean;
begin
  Result := FDataSet <> nil;
  if Result then
  begin
    if not FDataSet.EOF then
      FDataSet.Next;
    Result := not FDataSet.EOF;
    if Result then
      Inc(FDataSetRecNo);
  end;
end;

function TCustomDataSetAdapter.GetRecordCount: Integer;
begin
  Result := 0;
  if Assigned(OnGetRecordCount) then
    OnGetRecordCount(Self, Result)
  else
    begin
    if FDataSet <> nil then
    begin
      if DataSet.Active or not DesigningComponent(Self) then
      begin
        FDataSet.Open;
        Result := FDataSet.RecordCount;
      end
    end
  end;
end;

function TCustomDataSetAdapter.GetRecordIndex: Integer;
begin
  Result := FDataSetRecNo;
end;

{ TCustomDataSetAdapterAction }

function TCustomDataSetAdapterAction.GetAdapter: TCustomDataSetAdapter;
begin
  if (inherited Adapter <> nil) and (inherited Adapter is TCustomDataSetAdapter) then
    Result := TCustomDataSetAdapter(inherited Adapter)
  else
    Result := nil;
end;

function TCustomDataSetAdapterAction.GetDataSet: TDataSet;
begin
  if Adapter <> nil then
    Result := Adapter.DataSet
  else
    Result := nil;
end;

function TCustomDataSetAdapterAction.ImplWebEnabled: Boolean;
begin
  Result := DataSet <> nil;
  if Assigned(OnGetEnabled) then
    OnGetEnabled(Self, Result);
end;

constructor TCustomDataSetAdapterAction.Create(AOwner: TComponent);
begin
  inherited;
  ActionModes := [amInsert, amEdit, amBrowse, amQuery];
end;

function TCustomDataSetAdapterAction.ImplGetVisible: Boolean;
begin
  Result := Adapter.Mode in FActionModes;
end;

{ TCustomDataSetAdapterRowAction }

constructor TCustomDataSetAdapterRowAction.Create(AOwner: TComponent);
begin
  inherited;
  ActionModes := [amInsert, amEdit, amBrowse {, amQuery}];
end;

procedure TCustomDataSetAdapterRowAction.ImplGetAdapterItemRequestParams(
  var AIdentifier: string; Params: IAdapterItemRequestParams);
begin
  Adapter.EncodeActionParams(Params);
  inherited ImplGetAdapterItemRequestParams(AIdentifier, Params);
end;

function TCustomDataSetAdapterRowAction.ImplWebEnabled: Boolean;
begin
  Result := inherited ImplWebEnabled and (Adapter.GetKeyFields <> '');
end;

{ TDataSetAdapterRowAction }

procedure TDataSetAdapterRowAction.ImplExecuteActionRequest(AActionRequest: IActionRequest;
  AActionResponse: IActionResponse);
var
  S: TStrings;
begin
  if Assigned(OnExecute) then
  begin
    S := AdapterRequestParamsAsStrings(AActionRequest);
    try
      Adapter.ExtractRequestParams(AActionRequest);
      Adapter.ApplyAdapterMode(AActionRequest);
      OnExecute(Self, S);
    finally
      S.Free;
    end;
  end
  else
  begin
    if not Adapter.LocateAndApply(AActionRequest) then
      Adapter.EchoActionFieldValues := True;
  end;

end;

procedure TDataSetAdapterRowAction.ImplGetAdapterItemRequestParams(var AIdentifier: string; Params: IAdapterItemRequestParams);
begin
  Assert(Params.ParamValues.Count = 0);
  inherited ImplGetAdapterItemRequestParams(AIdentifier, Params);
end;

{ TDataSetAdapterDeleteRowAction }

function TDataSetAdapterDeleteRowAction.GetDefaultActionName: string;
begin
  Result := sDataSetAdapterDeleteAction;
end;

procedure TDataSetAdapterDeleteRowAction.ImplExecuteActionRequest(
  AActionRequest: IActionRequest; AActionResponse: IActionResponse);

  function DeleteRow: Boolean;
  begin
    Result := True;
    try
      DataSet.Delete
    except
      // Add to error list
      on E: Exception do
      begin
        Errors.AddError(E);
        Result := False;
      end;
    end;
  end;

begin
  Adapter.ExtractRequestParams(AActionRequest);
  // Extract mode and preserve for response
  Adapter.ApplyAdapterMode(AActionRequest);
  if Adapter.Mode in [amInsert] then
  begin
    Adapter.Locate;
    Adapter.Mode := amEdit;
  end
  else
    if Adapter.Locate and DeleteRow then
    else
      Adapter.EchoActionFieldValues := True;
end;

function TDataSetAdapterDeleteRowAction.ImplIsDefaultAction(
  ADisplay: TObject): Boolean;
var
  Intf: IGetAdapterDisplayCharacteristics;
begin
  Result := Adapter.Mode <> amQuery;
  if Result then
    if Supports(ADisplay, IGetAdapterDisplayCharacteristics, Intf) then
      Result := dcCurrentRecordView in Intf.GetAdapterDisplayCharacteristics
    else
      Result := True;
end;

{ TDataSetAdapterNextRowAction }

function TDataSetAdapterNextRowAction.GetDefaultActionName: string;
begin
  Result := sDataSetAdapterNextAction;
end;

function TDataSetAdapterNextRowAction.ImplWebEnabled: Boolean;
begin
  Result := inherited ImplWebEnabled and
    (DataSet <> nil) and (not DataSet.Eof);
end;

procedure TDataSetAdapterNextRowAction.ImplExecuteActionRequest(
  AActionRequest: IActionRequest; AActionResponse: IActionResponse);
begin
  if Adapter.LocateAndApply(AActionRequest) then
    DataSet.Next
  else
    Adapter.EchoActionFieldValues := True;
end;

{ TDataSetAdapterPrevRowAction }

function TDataSetAdapterPrevRowAction.GetDefaultActionName: string;
begin
  Result := sDataSetAdapterPrevAction;
end;

function TDataSetAdapterPrevRowAction.ImplWebEnabled: Boolean;
begin
  Result := inherited ImplWebEnabled and
    (DataSet <> nil) and (not DataSet.Bof);
end;

procedure TDataSetAdapterPrevRowAction.ImplExecuteActionRequest(
  AActionRequest: IActionRequest; AActionResponse: IActionResponse);
begin
  if Adapter.LocateAndApply(AActionRequest) then
    DataSet.Prior
  else
    Adapter.EchoActionFieldValues := True;
end;

{ TDataSetAdapterFirstRowAction }

function TDataSetAdapterFirstRowAction.GetDefaultActionName: string;
begin
  Result := sDataSetAdapterFirstAction;
end;

function TDataSetAdapterFirstRowAction.ImplWebEnabled: Boolean;
begin
  Result := inherited ImplWebEnabled and
    (DataSet <> nil) and (not DataSet.Bof);
end;

procedure TDataSetAdapterFirstRowAction.ImplExecuteActionRequest(
  AActionRequest: IActionRequest; AActionResponse: IActionResponse);
begin
  if Adapter.LocateAndApply(AActionRequest) then
    DataSet.First
  else
    Adapter.EchoActionFieldValues := True;
end;

{ TDataSetAdapterLastRowAction }

function TDataSetAdapterLastRowAction.GetDefaultActionName: string;
begin
  Result := sDataSetAdapterLastAction;
end;

function TDataSetAdapterLastRowAction.ImplWebEnabled: Boolean;
begin
  Result := inherited ImplWebEnabled and
    (DataSet <> nil) and (not DataSet.Eof);
end;

procedure TDataSetAdapterLastRowAction.ImplExecuteActionRequest(
  AActionRequest: IActionRequest; AActionResponse: IActionResponse);
begin
  if Adapter.LocateAndApply(AActionRequest) then
    DataSet.Last
  else
    Adapter.EchoActionFieldValues := True;
end;

{ TDataSetAdapterLastRowAction }

function TDataSetAdapterNewRowAction.GetDefaultActionName: string;
begin
  Result := sDataSetAdapterNewAction;
end;

function TDataSetAdapterNewRowAction.ImplWebEnabled: Boolean;
begin
  Result := inherited ImplWebEnabled
end;

procedure TDataSetAdapterNewRowAction.ImplExecuteActionRequest(
  AActionRequest: IActionRequest; AActionResponse: IActionResponse);
begin
  if Adapter.LocateAndApply(AActionRequest) then
  begin
    Adapter.Mode := amInsert;
    DataSet.Open;
    DataSet.Insert;
  end
  else
    Adapter.EchoActionFieldValues := True;
end;

{ TDataSetAdapterCancelRowAction }

function TDataSetAdapterCancelRowAction.GetDefaultActionName: string;
begin
  Result := sDataSetAdapterCancelAction;
end;

function TDataSetAdapterCancelRowAction.ImplWebEnabled: Boolean;
begin
  Result := inherited ImplWebEnabled and (Adapter.Mode <> amBrowse);
end;

procedure TDataSetAdapterCancelRowAction.ImplExecuteActionRequest(
  AActionRequest: IActionRequest; AActionResponse: IActionResponse);
begin
  Adapter.ExtractRequestParams(AActionRequest);
  Adapter.InDefaultMode := True;
  if DataSet = nil then
    Adapter.RaiseNilDataSet;
  DataSet.Open;
  if not DataSet.EOF then
    Adapter.Locate;
end;

function TDataSetAdapterCancelRowAction.ImplIsDefaultAction(
  ADisplay: TObject): Boolean;
var
  Intf: IGetAdapterDisplayCharacteristics;
  C: TAdapterDisplayCharacteristics;
begin
  Result := Adapter.Mode <> amQuery;
  if Result then
    if Supports(ADisplay, IGetAdapterDisplayCharacteristics, Intf) then
    begin
      C := Intf.GetAdapterDisplayCharacteristics;
      Result := (dcCurrentRecordView in C) and
        not (dcMultipleRecordView in C);
    end
    else
      Result := True;
end;

{ TDataSetAdapterRefreshRowAction }

function TDataSetAdapterRefreshRowAction.GetDefaultActionName: string;
begin
  Result := sDataSetAdapterRefreshAction;
end;

function TDataSetAdapterRefreshRowAction.ImplWebEnabled: Boolean;
begin
  Result := inherited ImplWebEnabled
end;

procedure TDataSetAdapterRefreshRowAction.ImplExecuteActionRequest(
  AActionRequest: IActionRequest; AActionResponse: IActionResponse);
begin
  Adapter.ExtractRequestParams(AActionRequest);
  Adapter.ApplyAdapterMode(AActionRequest);
  case Adapter.Mode of
    amInsert:
    begin
      if DataSet = nil then
        Adapter.RaiseNilDataSet;
      Adapter.Locate;
      DataSet.Open;
      DataSet.Insert
    end;
    amBrowse, amEdit:
      Adapter.Locate;  // May raise exception
  else
    Assert(False);
  end;
end;

function TDataSetAdapterRefreshRowAction.ImplIsDefaultAction(
  ADisplay: TObject): Boolean;
var
  Intf: IGetAdapterDisplayCharacteristics;
  C: TAdapterDisplayCharacteristics;
begin
  Result := Adapter.Mode <> amQuery;
  if Result then
    if Supports(ADisplay, IGetAdapterDisplayCharacteristics, Intf) then
    begin
      C := Intf.GetAdapterDisplayCharacteristics;
      Result := (dcCurrentRecordView in C) and
        not (dcMultipleRecordView in C);
    end
    else
      Result := True;
end;

{ TDataSetAdapterEditRowAction }

function TDataSetAdapterEditRowAction.GetDefaultActionName: string;
begin
  Result := sDataSetAdapterEditAction;
end;

function TDataSetAdapterEditRowAction.ImplWebEnabled: Boolean;
begin
  Result := inherited ImplWebEnabled
end;

procedure TDataSetAdapterEditRowAction.ImplExecuteActionRequest(
  AActionRequest: IActionRequest; AActionResponse: IActionResponse);
begin
  if Adapter.LocateAndApply(AActionRequest) then
    Adapter.Mode := amEdit
  else
    Adapter.EchoActionFieldValues := True;
end;

function TDataSetAdapterEditRowAction.ImplIsDefaultAction(
  ADisplay: TObject): Boolean;
var
  Intf: IGetAdapterDisplayCharacteristics;
  C: TAdapterDisplayCharacteristics;
begin
  if Supports(ADisplay, IGetAdapterDisplayCharacteristics, Intf) then
  begin
    C := Intf.GetAdapterDisplayCharacteristics;
    Result := (dcCurrentRecordView in C) and
      (dcMultipleRecordView in C);
  end
  else
    Result := True;
end;

{ TDataSetAdapterBrowseRowAction }

function TDataSetAdapterBrowseRowAction.GetDefaultActionName: string;
begin
  Result := sDataSetAdapterBrowseAction;
end;

function TDataSetAdapterBrowseRowAction.ImplWebEnabled: Boolean;
begin
  Result := inherited ImplWebEnabled
end;

procedure TDataSetAdapterBrowseRowAction.ImplExecuteActionRequest(
  AActionRequest: IActionRequest; AActionResponse: IActionResponse);
begin
  if Adapter.LocateAndApply(AActionRequest) then
    Adapter.Mode := amBrowse
  else
    Adapter.EchoActionFieldValues := True;
end;

function TDataSetAdapterBrowseRowAction.ImplIsDefaultAction(
  ADisplay: TObject): Boolean;
var
  Intf: IGetAdapterDisplayCharacteristics;
  C: TAdapterDisplayCharacteristics;
begin
  if Supports(ADisplay, IGetAdapterDisplayCharacteristics, Intf) then
  begin
    C := Intf.GetAdapterDisplayCharacteristics;
    Result := (dcCurrentRecordView in C) and
      (dcMultipleRecordView in C);
  end
  else
    Result := True;
end;

{ TDataSetAdapterApplyRowAction }

function TDataSetAdapterApplyRowAction.GetDefaultActionName: string;
begin
  Result := sDataSetAdapterApplyAction;
end;

function TDataSetAdapterApplyRowAction.ImplWebEnabled: Boolean;
begin
  Result := inherited ImplWebEnabled and (Adapter.Mode <> amBrowse);
end;

procedure TDataSetAdapterApplyRowAction.ImplExecuteActionRequest(
  AActionRequest: IActionRequest; AActionResponse: IActionResponse);
begin
  // LocateAndApply leaves adapter in edit mode
  if Adapter.LocateAndApply(AActionRequest) then
  else
    Adapter.EchoActionFieldValues := True;
end;

function TDataSetAdapterApplyRowAction.ImplIsDefaultAction(
  ADisplay: TObject): Boolean;
var
  Intf: IGetAdapterDisplayCharacteristics;
  C: TAdapterDisplayCharacteristics;
begin
  Result := Adapter.Mode <> amQuery;
  if Result then
    if Supports(ADisplay, IGetAdapterDisplayCharacteristics, Intf) then
    begin
      C := Intf.GetAdapterDisplayCharacteristics;
      Result := (dcCurrentRecordView in C) and
        not (dcMultipleRecordView in C);
    end
    else
      Result := True;
end;

{ TDataSetAdapterDataLink }

constructor TDataSetAdapterDataLink.Create(AAdapter: TComponent);
begin
  FAdapter := AAdapter;
  inherited Create;
end;

procedure TDataSetAdapterDataLink.DataEvent(Event: TDataEvent;
  Info: Integer);
begin
  inherited;
  case Event of
    (* We don't get these when the tablename is changed because the
      table has already been deactivated
    deLayoutChange,
    dePropertyChange,
    deFieldListChange,
    *)
    deUpdateState:
    begin
     if Assigned(OnDataSetStateChange) then
       OnDataSetStateChange(Self);
     if Assigned(NotifyPossibleHTMLChange) then
       NotifyPossibleHTMLChange;
    end;
  end;
end;

procedure TDataSetAdapterDataLink.RecordChanged(Field: TField);
begin
  // Current record changed
  if Assigned(NotifyPossibleHTMLChange) then
    NotifyPossibleHTMLChange;
end;

{ TCustomDataSetValuesList }

constructor TCustomDataSetValuesList.Create(AOwner: TComponent);
begin
  inherited;
  FCache := TNamedVariantsList.Create;
end;

procedure TCustomDataSetValuesList.PrepareDataSet;
begin
  DataSetPrepared := True;
  if Assigned(OnPrepareDataSet) then
    OnPrepareDataSet(Self);
  if Assigned(DataSet) then
    DataSet.Cancel;
end;

destructor TCustomDataSetValuesList.Destroy;
begin
  inherited;
  FCache.Free;
end;

function TCustomDataSetValuesList.GetNameFieldClass: TComponentClass;
begin
  Result := TValuesListNameField;
end;

function TCustomDataSetValuesList.GetValueFieldClass: TComponentClass;
begin
  Result := TValuesListValueField;
end;

procedure TCustomDataSetValuesList.ImplEndIterator(OwnerData: Pointer);
begin
  if FIndex >= FCache.Count then
  begin
    FIndex := 0;
    FCache.Clear;
    FCacheInUse := False;
  end;
end;

function TCustomDataSetValuesList.ImplGetListNameOfValue(Value: Variant): string;
var
  I: Integer;
begin
  if not FCacheInUse then
    CacheValuesList;
  for I := 0 to FCache.Count - 1 do
  begin
    Result := FCache.Names[I];
    if Result <> '' then
      try
        if FCache.Variants[I] = Value then
          Exit;
      except
      end;
  end;
  Result := '';
end;

function TCustomDataSetValuesList.ImplGetListName: string;
begin
  if FIndex < FCache.Count then
    Result := FCache.Names[FIndex]
  else
    Result := '';
end;

function TCustomDataSetValuesList.ImplGetListValue: Variant;
begin
  if FIndex < FCache.Count then
    Result := FCache.Variants[FIndex]
  else
    Result := Unassigned;
  if VarIsEmpty(Result) then
    Result := ImplGetListName;
end;

function TCustomDataSetValuesList.ImplNextIteration(
  var OwnerData: Pointer): Boolean;
begin
  Inc(FIndex);
  Result := FIndex < FCache.Count;
end;

function TCustomDataSetValuesList.ImplStartIterator(
  var OwnerData: Pointer): Boolean;
begin
  FIndex := 0;
  CacheValuesList;
  FCacheInUse := True;
  Result := FIndex < FCache.Count;
end;

procedure TCustomDatasetValuesList.CacheValuesList;
var
  DSValueField: TField;
  DSNameField: TField;
  N: string;
  V: Variant;
begin
  FCache.Clear;
  if DataSet <> nil then
  begin
    if not DesigningComponent(Self) then
      DataSet.Open;
    if DataSet.Active then
    begin
      DSValueField := DataSet.FindField(ValueField);
      DSNameField := DataSet.FindField(NameField);
      DataSet.First;
      while not DataSet.EOF do
      begin
        if Assigned(DSNameField) and
          not VarIsNull(DSNameField.Value) then
          N := DSNameField.Value
        else
          N := '';
        if Assigned(DSValueField) then
          V := DSValueField.Value
        else
          V := Unassigned;
        FCache.Add(N, V);
        DataSet.Next;
      end;
    end;
  end;
end;

procedure TCustomDataSetValuesList.SetDataSet(
  const Value: TDataSet);
begin
  if FDataSet <> Value then
  begin
    if Value <> nil then Value.FreeNotification(Self);
    FDataSet := Value;
  end;
end;

procedure TCustomDataSetValuesList.Notification(AComponent: TComponent; Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (AComponent = FDataSet) then
    FDataSet := nil;
end;

function TCustomDataSetValuesList.GetDataSet: TDataSet;
begin
  if not (csLoading in ComponentState) and not DataSetPrepared then
    PrepareDataSet;
  Result := FDataSet;
end;

procedure TCustomDataSetValuesList.ImplNotifyDeactivate;
begin
  inherited;
  if FDataSet <> nil then
    FDataSet.Close;
  DataSetPrepared := False;
end;

procedure TCustomDataSetValuesList.GetDesigntimeWarnings(
  AWarnings: TAbstractDesigntimeWarnings);
begin
  if DataSet = nil then
    AWarnings.AddString(Format(sDataSetPropertyIsNil, [Self.Name]));
  if (DataSet <> nil) and (not DataSet.Active) then
    AWarnings.AddString(Format(sDataSetNotActive, [Self.Name, DataSet.Name]));
  if (Self.ValueField = '') then
    AWarnings.AddString(Format(sValueFieldIsBlank, [Self.Name]));
end;

{ TCustomDataSetAdapterMemoField }

function TCustomDataSetAdapterMemoField.ImplAsFormatted: string;
var
  DataSet: TDataSet;
  Field: TField;
begin
  Result := Unassigned;
  if FDataSetField <> '' then
  begin
    DataSet := GetDataSet;
    if Assigned(DataSet) then
    begin
      if DataSet.Active or not DesigningComponent(Self) then
      begin
        DataSet.Open;
        Field := DataSet.FindField(FDataSetField);
      end
      else
        Field := nil;
      if Assigned(Field) then
        if Assigned(OnGetDisplayText) then
          OnGetDisplayText(Self, Field, Result)
        else
          if Field is TMemoField then
            Result := Field.AsString
          else
            Result := Field.DisplayText
      else
        Result := '';
    end;
  end;
end;

function TCustomDataSetAdapterMemoField.ImplGetValue: Variant;
var
  Value: IActionFieldValue;
begin
  CheckViewAccess;
  if EchoActionFieldValue then
  begin
    Value := ActionValue;
    if Value <> nil then
      Result := Value.Values[0]
    else
      Result := Unassigned;
  end
  else if Adapter.Mode <> amQuery then
    Result := inherited ImplGetValue;
end;

function TCustomDataSetAdapterMemoField.CheckOrUpdateValue(
  AActionRequest: IActionRequest; AFieldIndex: Integer; AUpdate: Boolean): Boolean;
var
  Field: TField;
  FieldValue: IActionFieldValue;
begin
  Result := False;
  Assert(Adapter <> nil);
  with GetActionFieldValues(AActionRequest) do
    FieldValue := Values[AFieldIndex];
  if FieldValue.ValueCount > 0 then
  begin
    // Make sure the dataset is open and set
    if Adapter.DataSet = nil then
      Adapter.RaiseNilDataSet;
    Adapter.DataSet.Open;
    Field := FindField;
    if Field = nil then
      Adapter.RaiseFieldNotFound(DataSetField);
    if FieldValue.ValueCount = 1 then
    begin
      if AUpdate and Assigned(OnUpdateValue) then
        OnUpdateValue(Self, Field, FieldValue.Values[0])
      else
      begin
        Result := TestValueChange(Field, FieldValue.Values[0]);
        if Result and AUpdate then
          Field.Value := FieldValue.Values[0]
      end;
    end
    else
      RaiseMultipleValuesException(FieldName)
  end
  else if FieldValue.FileCount > 0 then
    RaiseFileUploadNotSupported(FieldName);
end;

procedure TCustomDataSetAdapterMemoField.ImplUpdateValue(
  AActionRequest: IActionRequest; AFieldIndex: Integer);
begin
  CheckModifyAccess;
  CheckOrUpdateValue(AActionRequest, AFieldIndex, True);
end;

function TCustomDataSetAdapterMemoField.ImplCheckValueChange(
  AActionRequest: IActionRequest; AFieldIndex: Integer): Boolean;
begin
  Result := CheckOrUpdateValue(AActionRequest, AFieldIndex, False);
end;

function TCustomDataSetAdapterMemoField.GetInputStyleType(const AAdapterMode: string): TAdapterInputHTMLElementType;
begin
  Result := htmliTextArea;
end;

{ TDataSetAdapterMoveRowAction }

function TDataSetAdapterMoveRowAction.ImplIsDefaultAction(
  ADisplay: TObject): Boolean;
var
  Intf: IGetAdapterDisplayCharacteristics;
begin
  Result := Adapter.Mode <> amQuery;
  if Result then
    if Supports(ADisplay, IGetAdapterDisplayCharacteristics, Intf) then
      Result := dcChangeCurrentRecordView in Intf.GetAdapterDisplayCharacteristics
    else
      Result := True;
end;

function TDataSetAdapterNewRowAction.ImplIsDefaultAction(
  ADisplay: TObject): Boolean;
begin
  Result := True;
end;

constructor TDataSetAdapterNewRowAction.Create(AOwner: TComponent);
begin
  inherited;
  ActionModes := [amInsert, amEdit, amBrowse, amQuery];
end;

constructor TDataSetAdapterEditRowAction.Create(AOwner: TComponent);
begin
  inherited;
  ActionModes := [amInsert, amEdit, amBrowse, amQuery];
end;

constructor TDataSetAdapterBrowseRowAction.Create(AOwner: TComponent);
begin
  inherited;
  ActionModes := [amInsert, amEdit, amBrowse, amQuery];
end;

constructor TDataSetAdapterCancelRowAction.Create(AOwner: TComponent);
begin
  inherited;
  ActionModes := [amInsert, amEdit];
end;

constructor TDataSetAdapterApplyRowAction.Create(AOwner: TComponent);
begin
  inherited;
  ActionModes := [amInsert, amEdit];
end;

procedure TCustomDataSetAdapter.SetMasterAdapter(
  const Value: TCustomDataSetAdapter);
begin
  if MasterAdapter <> Value then
  begin
    if FMasterAdapter <> nil then
      FMasterAdapter.DetailAdapters.Remove(Self);
    FMasterAdapter := Value;
    if Value <> nil then
    begin
      Value.FreeNotification(Self);
      Value.DetailAdapters.Add(Self);
    end;
  end;
end;

{ TLocateParamsList }

function TLocateParamsList.Add: TLocateParams;
begin
  Result := TLocateParams.Create(Self);
end;

procedure TLocateParamsList.Clear;
begin
  FList.Clear;
end;

constructor TLocateParamsList.Create;
begin
  inherited;
  FList := TObjectList.Create(True {Owned} );
end;

destructor TLocateParamsList.Destroy;
begin
  inherited;
  FList.Free;
end;

function TLocateParamsList.GetCount: Integer;
begin
  Result := FList.Count;
end;

function TLocateParamsList.GetItem(I: Integer): TLocateParams;
begin
  Result := TLocateParams(FList[I]);
end;

{ TLocateParams }

procedure TLocateParams.AddParam(const ANameValue: string);
begin
  FParams.Add(ANameValue)
end;

procedure TLocateParams.AddParam(const AName, AValue: string);
begin
  FParams.Add(Format('%s=%s', [AName, AValue]));
end;

constructor TLocateParams.Create(AList: TLocateParamsList);
begin
  inherited Create;
  FParams := TStringList.Create;
  if AList <> nil then
    AList.FList.Add(Self);
end;

destructor TLocateParams.Destroy;
begin
  inherited;
  FParams.Free;
end;

function TLocateParams.GetCount: Integer;
begin
  Result := FParams.Count;
end;

function TLocateParams.GetItem(I: Integer): string;
begin
  Result := FParams[I];
end;

function TLocateParams.GetParamName(I: Integer): string;
begin
  Result := FParams.Names[I];
end;

function TLocateParams.GetParamValue(I: Integer): string;
begin
  Result := ExtractStringValue(FParams[I]);
end;

function TLocateParamsList.ItemByAdapterName(
  const AName: string): TLocateParams;
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
  begin
    Result := Items[I];
    if SameText(Result.AdapterName, AName) then
      Exit;
  end;
  Result := nil;
end;

function TCustomDataSetAdapter.ImplGetIteratorIndex: Integer;
begin
  Result := FDataSetRecNo;
end;

function TCustomDataSetAdapter.ImplInIterator: Boolean;
begin
  Result := FInIterator;
end;

procedure TCustomDataSetAdapter.GetRecordKeys(AValues: TStrings; var AFullyQualify: Boolean);
begin
  ImplGetRecordKeys(AValues, AFullyQualify);
end;

procedure TCustomDataSetAdapter.ImplGetRecordKeys(AValues: TStrings; var AFullyQualify: Boolean);
begin
  GetKeyParamStrings(AValues);
  AFullyQualify := FullyQualifyInputNames;
end;

function TCustomDataSetAdapter.FullyQualifyInputNames: Boolean;
begin
  Result := (MasterAdapter <> nil) or (DetailAdapters.Count >= 1);
end;

function TBaseDataSetAdapterField.FullyQualifyInputName: Boolean;
begin
  Result := (Adapter <> nil) and
   (Adapter.FullyQualifyInputNames);
end;

function TBaseDataSetAdapterField.GetKeyName: string;
begin
  if ffInKey in FieldFlags then
    Result := DataSetField
  else
    Result := '';
end;

{ TBaseDataSetAdapterInputField }

function TBaseDataSetAdapterInputField.ImplGetEchoActionFieldValue: Boolean;
begin
  Result := FEchoActionFieldValue;
end;

procedure TBaseDataSetAdapterInputField.ImplSetEchoActionFieldValue(
  AValue: Boolean);
begin
  FEchoActionFieldValue := AValue;
end;

procedure TBaseDataSetAdapterInputField.ValidateValue(
  AActionRequest: IActionRequest; AFieldIndex: Integer);
begin
  ImplValidateValue(AActionRequest, AFieldIndex);
end;

procedure TBaseDataSetAdapterInputField.ImplValidateValue(
  AActionRequest: IActionRequest; AFieldIndex: Integer);
var
  Handled: Boolean;
  Field: TField;
begin
  if Assigned(OnValidateValue) then
  begin
    // When validating values, make sure the dataset is not nil, and Open
    if Adapter.DataSet = nil then
      Adapter.RaiseNilDataSet;
    Adapter.DataSet.Open;
    Field := FindField;
    with GetActionFieldValues(AActionRequest) do
      OnValidateValue(Self, Field, Values[AFieldIndex], Handled)
  end;
end;

function TBaseDataSetAdapterInputField.TestValueChange(AField: TField; const ANewValue: string): Boolean;
var
  OrigValue: Variant;
begin
  OrigValue := AField.Value;
  if (VarIsEmpty(OrigValue)) or (VarIsNull(OrigValue)) then
    Result := Length(ANewValue) <> 0
  else
    try
      Result := ANewValue <> OrigValue;
    except
      Result := True;
    end;
end;

procedure TCustomDataSetAdapter.SetInDefaultMode(const Value: Boolean);
begin
  FInDefaultMode := Value;
  FMode := amBrowse;
end;

procedure TCustomDataSetAdapter.ImplSetEchoActionFieldValues(
  AValue: Boolean);
var
  I: Integer;
  C: TCustomDataSetAdapter;
  List: TComponentList;
begin
  if (AValue = True) and
    (GetEchoActionFieldValues <> AValue) then
  begin
    if Mode <> amBrowse then
      inherited ImplSetEchoActionFieldValues(AValue);
    List := GetMasterDetailAdapters;
    if List <> nil then
      try
        for I := 0 to List.Count - 1 do
        begin
          C := (List[I] as TCustomDataSetAdapter);
          if (C <> Self) and (C.Mode <> amBrowse) then
            C.ImplSetEchoActionFieldValues(AValue);
        end
      finally
        List.Free;
      end
    else
      if Mode <> amBrowse then
        inherited ImplSetEchoActionFieldValues(AValue)
  end
  else
    inherited ImplSetEchoActionFieldValues(AValue);
end;

procedure TBaseDataSetAdapterField.PrepareDataSet;
begin
  if Assigned(FField) then
    FField.RemoveFreeNotification(Self);
  FField := nil;
end;

end.

