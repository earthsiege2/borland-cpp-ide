
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{   Copyright (c) 1999-2001 Borland Software Corp.      }
{                                                       }
{*******************************************************}

unit WebAdapt;

interface

{$IFDEF MSWINDOWS}
uses Classes, Messages, HTTPApp, WebComp, DB, SiteComp, SysUtils,
  WebContnrs, Contnrs, AdaptReq, HTTPProd, WebCntxt;
{$ENDIF}
{$IFDEF LINUX}
uses Classes, HTTPApp, WebComp, DB, SiteComp, SysUtils,
  WebContnrs, Contnrs, AdaptReq, HTTPProd, WebCntxt;
{$ENDIF}

type

  IGetRecordKeys = interface
  ['{903C8BC5-1E1E-4592-BD13-99EB29819876}']
    procedure GetRecordKeys(AParams: TStrings; var AFullyQualify: Boolean);
  end;

  ICheckOrigValue = interface
  ['{BE6A5DCD-A617-11D4-A4FE-00C04F6BB853}']
    procedure CheckOrigValue(AActionRequest: IActionRequest; AFieldIndex: Integer);
  end;

  IValidateValue = interface
  ['{23EA6F48-DC46-47A7-8EC3-0FF9F59D8F57}']
    procedure ValidateValue(AActionRequest: IActionRequest; AFieldIndex: Integer);
  end;

  ICheckValueChange = interface
  ['{7021B26D-B023-11D4-A50F-00C04F6BB853}']
    function CheckValueChange(AActionRequest: IActionRequest; AFieldIndex: Integer): Boolean;
  end;

  IGetAdapterModeNames = interface
  ['{2D71A94A-4D9B-498E-802E-9739C0CE5875}']
    procedure GetAdapterModeNames(AStrings: TStrings);
  end;

  IUpdateValue = interface
  ['{BE6A5DCE-A617-11D4-A4FE-00C04F6BB853}']
    procedure UpdateValue(AActionRequest: IActionRequest; AFieldIndex: Integer);
  end;
                                 
  IExecuteValue = interface
  ['{BBC8AA03-EEB8-4FB5-BADA-EE2543DC728D}']
    procedure ExecuteValue(AActionRequest: IActionRequest; AFieldIndex: Integer);
  end;

  IClearAdapterValues = interface
  ['{274C6B5F-CAD6-11D4-A529-00C04F6BB853}']
    procedure ClearAdapterValues;
  end;

  IWebGetFieldPrevValue = interface
  ['{7AE6735B-6964-11D4-A4AA-00C04F6BB853}']
    function GetNeedPrevValue: Boolean;
    function GetPrevValue: Variant;
    property PrevValue: Variant read GetPrevValue;
    property NeedPrevValue: Boolean read GetNeedPrevValue;
  end;

  ISetWebFieldValue = interface
  ['{9E6E6A7E-574F-11D4-A491-00C04F6BB853}']
    procedure SetValue(const AValue: Variant);
  end;

  IWebFieldsSubcomponent = interface
  ['{5D5A9FD6-9496-11D4-A4E9-00C04F6BB853}']
  end;

  IWebActionsSubcomponent = interface
  ['{29764F06-D0D8-4334-AA97-CB25D40737AE}']
  end;

  IFullyQualifyInputNames = interface
  ['{C6224685-3BDA-4BC4-B618-E9F329845FC2}']
    function FullyQualifyInputNames: Boolean;
  end;

  TAdapterSubComponent = class(TWebContainerComponent, IWebContainerSubComponent, IWebComponentEditor,
    IWebVariablesContainer, IGetWebComponentNodeName, IIterateObjectSupport)
  private
    FParent: TComponent;
    FIteratorIndex: Integer;
    function GetAdapter: TComponent;
  protected
    property Adapter: TComponent read GetAdapter;
    function GetDefaultWebComponents: TWebComponentList; override;
    procedure SetDefaultWebComponents(AList: TWebComponentList); override;
    procedure NotifyAdapterChange;
    { IIterateObjectSupport }
    function StartIterator(var OwnerData: Pointer): Boolean;
    function NextIteration(var OwnerData: Pointer): Boolean;
    procedure EndIterator(OwnerData: Pointer);
    function GetCurrentObject(OwnerData: Pointer): TObject;
    { IWebVariablesContainer }
    function FindVariable(const AName: string): TComponent;
    function FindVariableContainer(const AName: string): TComponent;
    function GetVariableCount: Integer;
    function GetVariable(I: Integer): TComponent;
    function FindNamedVariable(const AName: string): TComponent; virtual;
    { IGetWebComponentNodeName }
    function GetWebComponentNodeName: string;
    function ImplGetWebComponentNodeName: string; virtual;
    { IWebComponentEditor }
    function CanAddClass(AParent: TComponent; AClass: TClass): Boolean;
    function ImplCanAddClass(AParent: TComponent; AClass: TClass): Boolean; virtual;
    procedure SetWebParent(const Value: TComponent); virtual;
    function GetVariablesInUse: TWebComponentList; virtual;
    property VariablesInUse: TWebComponentList read GetVariablesInUse;
  public
    function GetParentComponent: TComponent; override;
    function HasParent: Boolean;  override;
    procedure ReadState(Reader: TReader); override;
    procedure SetParentComponent(AParent: TComponent); override;
  end;

  TAdapterFields = class(TAdapterSubComponent, IWebFieldsSubcomponent)
  protected
    function AdapterCanAddClass(AParent: TComponent; AClass: TClass): Boolean;
    { IWebComponentEditor }
    function ImplCanAddClass(AParent: TComponent; AClass: TClass): Boolean; override;
    procedure SetWebParent(const Value: TComponent); override;
    { IGetWebComponentNodeName }
    function ImplGetWebComponentNodeName: string; override;
  public
    property WebFields: TWebComponentList read GetWebComponents;
  end;

  TAdapterFieldsClass = class of TAdapterFields;

  TAdapterDefaultFields = class(TAdapterFields, IAddFieldsEditor)
  private
    FDefaultWebComponents: TWebComponentList;
  protected
    function GetDefaultWebComponents: TWebComponentList; override;
    procedure SetDefaultWebComponents(AList: TWebComponentList); override;
    { IAddFieldsEditor }
    function GetNewFieldPrefix: string;
    function GetAddFieldsItem: string;
    function GetAddAllFieldsItem: string;
    function GetAddFieldsDlgCaption: string;
    { IWebComponentEditor }
    function GetVariablesInUse: TWebComponentList; override;
  public
    procedure ClearDefaultComponents; virtual;
    destructor Destroy; override;
    property DefaultWebComponents: TWebComponentList read FDefaultWebComponents;
  end;

  TAdapterActions = class(TAdapterSubComponent, IWebActionsSubcomponent)
  protected
    function AdapterCanAddClass(AParent: TComponent; AClass: TClass): Boolean;
    { IWebComponentEditor }
    function ImplCanAddClass(AParent: TComponent; AClass: TClass): Boolean; override;
    procedure SetWebParent(const Value: TComponent); override;
    { IGetWebComponentNodeName }
    function ImplGetWebComponentNodeName: string; override;
  public
    property WebActions: TWebComponentList read GetWebComponents;
  end;

  TAdapterDefaultActions = class(TAdapterActions, IAddFieldsEditor)
  private
    FDefaultWebComponents: TWebComponentList;
  protected
    function GetDefaultWebComponents: TWebComponentList; override;
    procedure SetDefaultWebComponents(AList: TWebComponentList); override;
    { IWebComponentEditor }
    function GetVariablesInUse: TWebComponentList; override;
    { IAddFieldsEditor }
    function GetNewFieldPrefix: string;
    function GetAddFieldsItem: string;
    function GetAddAllFieldsItem: string;
    function GetAddFieldsDlgCaption: string;
  public
    procedure ClearDefaultComponents; virtual;
    destructor Destroy; override;
    property DefaultWebComponents: TWebComponentList read GetDefaultWebComponents;
  end;

  TAdapterErrorsList = class;

  TAdapterError = class(TInterfacedObject, IAdapterError)
  private
    FErrors: TAdapterErrorsList;
    FIndex: Integer;
  protected
    { IAdapterError }
    function GetErrorText: string;
    function GetID: integer;
    function GetField: TComponent;
  public
    constructor Create(AErrors: TAdapterErrorsList; AIndex: Integer);
  end;

  TBaseAdapterErrorsList = class(TInterfacedObject, IAdapterErrors,
    IIterateIntfSupport)
  private
    FIteratorIndex: Integer;
  protected
    { IAdapterErrors }
    function GetErrorCount: Integer;
    function GetError(I: Integer): IAdapterError;
    function HasObjectErrors(const AName: string): Boolean;
    function GetObjectErrors(const AName: string): TObject;
    procedure ImplClearErrors; virtual;
    function ImplGetErrorCount: Integer;  virtual;
    function ImplGetError(I: Integer): IAdapterError; virtual;
    function ImplHasObjectErrors(const AName: string): Boolean; virtual;
    function ImplGetObjectErrors(const AName: string): TObject; virtual;
    procedure ImplDefineLabel(const AName, ALabel: string); virtual;
    { IIterateInterfaceSupport }
    function StartIterator(var OwnerData: Pointer): Boolean;
    function NextIteration(var OwnerData: Pointer): Boolean;
    procedure EndIterator(OwnerData: Pointer);
    function GetCurrentIntf(OwnerData: Pointer): IUnknown;
  public
    procedure DefineLabel(const AName, ALabel: string);
    procedure ClearErrors;
    property ErrorCount: Integer read GetErrorCount;
    property Errors[I: Integer]: IAdapterError read GetError;
    procedure AddError(AException: Exception; const AObjectName: string = ''); overload; virtual;
    procedure AddError(const AMessage: string; const AObjectName: string = ''; AID: Integer = 0); overload; virtual;
    procedure AddError(const AMessage: string; AObject: TObject; AID: Integer = 0); overload; virtual;
    procedure AddError(AException: Exception; AObject: TObject); overload; virtual;
  end;

  TAdapterErrorsList = class(TBaseAdapterErrorsList)
  private
    FAdapter: TObject;
    FMessages: TStrings;
    FFieldNames: TStrings;
    FLabels: TStrings;
    function GetFieldName(I: Integer): string;
    function GetID(I: Integer): integer;
    function GetMessage(I: Integer): string;
  protected
    { IAdapterErrors }
    procedure ImplClearErrors; override;
    function ImplGetErrorCount: Integer;  override;
    function ImplGetError(I: Integer): IAdapterError;  override;
    function ImplHasObjectErrors(const AName: string): Boolean; override;
    function ImplGetObjectErrors(const AName: string): TObject; override;
    procedure ImplDefineLabel(const AName, ALabel: string); override;
  public
    constructor Create(AAdapter: TObject);
    destructor Destroy; override;
    procedure AddError(AException: Exception; const AObjectName: string = ''); override;
    procedure AddError(const AMessage: string; const AObjectName: string = ''; AID: Integer = 0); override;
    procedure AddError(const AMessage: string; AObject: TObject; AID: Integer = 0); override;
    procedure AddError(AException: Exception; AObject: TObject); override;
    property Messages[I: Integer]: string read GetMessage;
    property IDs[I: Integer]: integer read GetID;
    property FieldNames[I: Integer]: string read GetFieldName;
  end;

  TAdapterObjectErrorsList = class(TBaseAdapterErrorsList)
  private
    FErrors: TAdapterErrorsList;
    FIndexes: array of Integer;
  protected
    { IAdapterErrors }
    function ImplGetErrorCount: Integer; override;
    function ImplGetError(I: Integer): IAdapterError; override;
    procedure ImplDefineLabel(const AName, ALabel: string); override;
  public
    constructor Create(AErrors: TAdapterErrorsList; const AName: string);
  end;

  TAdapterActionsClass = class of TAdapterActions;

  IGetAdapterErrorsList = interface
  ['{42DD8EB1-5D9A-11D4-A498-00C04F6BB853}']
    function GetAdapterErrorsList: TBaseAdapterErrorsList;
  end;

  IAdapterEditor = interface
  ['{42DD8EB2-5D9A-11D4-A498-00C04F6BB853}']
    function CanAddFieldClass(AParent: TComponent; AClass: TClass): Boolean;
    function CanAddActionClass(AParent: TComponent; AClass: TClass): Boolean;
  end;

  ISetSubComponents = interface
  ['{274C6B60-CAD6-11D4-A529-00C04F6BB853}']
    procedure SetActions(const Value: TAdapterSubComponent);
    procedure SetData(const Value: TAdapterSubComponent);
  end;

  IEchoAdapterFieldValues = interface
  ['{274C6B62-CAD6-11D4-A529-00C04F6BB853}']
    procedure SetEchoActionFieldValues(AValue: Boolean);
    function GetEchoActionFieldValues: Boolean;
    property EchoActionFieldValues: Boolean read GetEchoActionFieldValues write SetEchoActionFieldValues;
  end;

  ICreateActionRequestContext = interface
  ['{374E4AFB-D11F-11D4-A531-00C04F6BB853}']
    procedure CreateActionRequestContext(DispatchParams: IAdapterDispatchParams);
  end;

  TAdapterHiddenFieldsList = class(TInterfacedObject, IAdapterHiddenFields,
    IIterateIntfSupport)
  private
    FIteratorIndex: Integer;
    FNames: TStrings;
    FValues: TStrings;
  protected
    { IAdapterHiddenFields }
    function GetFieldCount: Integer;
    function GetField(I: Integer): IAdapterHiddenField;
    property FieldCount: Integer read GetFieldCount;
    property Fields[I: Integer]: IAdapterHiddenField read GetField;
    { IIterateInterfaceSupport }
    function StartIterator(var OwnerData: Pointer): Boolean;
    function NextIteration(var OwnerData: Pointer): Boolean;
    procedure EndIterator(OwnerData: Pointer);
    function GetCurrentIntf(OwnerData: Pointer): IUnknown;
  public
    constructor Create;
    destructor Destroy; override;
    procedure Clear;
    procedure Add(const AName, AValue: string);
  end;

  TAdapterHiddenField = class(TInterfacedObject, IAdapterHiddenField)
  private
    FHiddenFields: TAdapterHiddenFieldsList;
    FIndex: Integer;
  protected
    { IAdapterHiddenFields }
    function GetName: string;
    function GetValue: string;
  public
    constructor Create(AHiddenFields: TAdapterHiddenFieldsList; AIndex: Integer);
  end;

  TAdapterActionExecuteEvent = procedure(Sender: TObject; Action: TObject; Params: TStrings) of object;
  TAdapterActionExecuteHandledEvent = procedure(Sender: TObject; Action: TObject; Params: TStrings; var Handled: Boolean) of object;
  TAdapterActionGetParamsEvent = procedure(Sender: TObject; Action: TObject; Params: TStrings) of object;

  IActionRequest = AdaptReq.IActionRequest;
  {$EXTERNALSYM IActionRequest}
  IActionFieldValue = AdaptReq.IActionFieldValue;
  {$EXTERNALSYM IActionFieldValue}
  TObjectList = Contnrs.TObjectList;
  {$EXTERNALSYM TObjectList}

  TIteratorMethod = (itStart, itNext, itEnd);
  TIterateRecordsEvent = procedure(Sender: TObject; Action: TIteratorMethod; var EOF: Boolean) of object;
  TActionRequestFieldsEvent = procedure(Sender: TObject; ActionRequest: IActionRequest;
    AdapterFields: TObjectList) of object;
  TActionRequestFieldsHandledEvent = procedure(Sender: TObject; ActionRequest: IActionRequest;
    AdapterFields: TObjectList; var Handled: Boolean) of object;
  TGetRecordCountEvent = procedure(Sender: TObject; var Count: Integer) of object;
  TGetRecordIndexEvent = procedure(Sender: TObject; var Index: Integer) of object;
  TGetEOFEvent = procedure(Sender: TObject; var EOF: Boolean) of object;
  TGetRecordEvent = procedure(Sender: TObject; var EOF: Boolean) of object;
  IAdapterNotifyAdapterChange = interface
  ['{10D48060-2BD8-472E-871B-2933ACD8F3B3}']
    procedure NotifyAdapterChange;
  end;

  // Identifies an adapter
  IIdentifyAdapter = interface
  ['{1A4AEC52-2960-46BD-89AC-1A5742A85089}']
  end;

  TAdapterHiddenFieldOption = (hoOrigValues, hoMode, hoRecordKeys);
  TAdapterHiddenFieldOptions = set of TAdapterHiddenFieldOption;
  TCustomAdapter = class(TComponent, IIdentifyAdapter, IWebVariableName,
    IWebVariablesContainer, INotifyList,
    IGetAdapterErrors, IGetAdapterErrorsList, INotifyWebActivate, IAdapterEditor,
    IGetScriptObject, IGetAdapterFields, IGetAdapterActions,
    IIteratorSupport, IClearAdapterValues, IEchoAdapterFieldValues,
    IAdapterAccess, IGetAdapterHiddenFields,
    ICreateActionRequestContext, IWebDataFields, IWebActionsList,
    IAdapterNotifyAdapterChange, IIteratorIndex)
  private
    FNotifyList: TNotifyList;
    FData: TAdapterFields;
    FActions: TAdapterActions;
    FErrors: TBaseAdapterErrorsList;
    FErrorsIntf: IAdapterErrors;
    FOnIterateRecords: TIterateRecordsEvent;
    FEchoActionFieldValues: Boolean;
    FOnBeforeValidateFields: TActionRequestFieldsHandledEvent;
    FOnAfterValidateFields: TActionRequestFieldsEvent;
    FOnBeforeUpdateFields: TActionRequestFieldsHandledEvent;
    FOnAfterUpdateFields: TActionRequestFieldsEvent;
    FOnBeforeExecuteAction: TAdapterActionExecuteHandledEvent;
    FOnAfterExecuteAction: TAdapterActionExecuteEvent;
    FOnAfterGetActionResponse: TAdapterActionExecuteEvent;
    FOnBeforeGetActionResponse: TAdapterActionExecuteHandledEvent;
    FOnGetActionParams: TAdapterActionGetParamsEvent;
    FViewAccess: string;
    FModifyAccess: string;
    FExecuteAccess: string;
    FHiddenFields: TAdapterHiddenFieldsList;
    FHiddenRecordFields: TAdapterHiddenFieldsList;
    FHiddenFieldsIntf: IAdapterHiddenFields;
    FHiddenRecordFieldsIntf: IAdapterHiddenFields;
    FIteratorIndex: Integer;
    FInIterator: Boolean;
    procedure ListAdapterUpdateFields(AActionRequest: IActionRequest; AList: TObjectList);
  protected
    function CreateErrorsList: TBaseAdapterErrorsList; virtual;
    procedure ExtractRequestParams(ARequest: IUnknown); virtual;
    procedure EncodeActionParams(AParams: IAdapterItemRequestParams); virtual;
    procedure AddAdapterModeHiddenField(
      AHiddenFields: TAdapterHiddenFieldsList);
    procedure AddRecordKeysHiddenFields(
      AHiddenFields: TAdapterHiddenFieldsList);
    procedure AddOrigValueHiddenFields(
      AHiddenFields: TAdapterHiddenFieldsList);
    procedure CheckModifyAccess;
    procedure UpdateFieldsValidateValues(AActionRequest: IActionRequest;
      AAdapterFields: TObjectList); virtual;
     procedure UpdateRecordsValidateValues(AActionRequest: IActionRequest;
      AAdapterFields: TObjectList); virtual;
    function UpdateRecordsGetAnyChanges(AActionRequest: IActionRequest;
      AAdapterFields: TObjectList): Boolean; virtual;
    function UpdateFieldsGetAnyChanges(AActionRequest: IActionRequest;
      AAdapterFields: TObjectList): Boolean; virtual;
    procedure UpdateFieldsUpdateValues(AActionRequest: IActionRequest;
      AAdapterFields: TObjectList); virtual;
    procedure UpdateFieldsExecuteValues(AActionRequest: IActionRequest;
      AAdapterFields: TObjectList); virtual;
    procedure UpdateRecordsUpdateValues(AActionRequest: IActionRequest;
      AAdapterFields: TObjectList); virtual;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    function GetHiddenFieldOptions: TAdapterHiddenFieldOptions; virtual;
    procedure ListHiddenFields(AHiddenFields: TAdapterHiddenFieldsList);
    procedure ListHiddenRecordFields(AHiddenFields: TAdapterHiddenFieldsList);
    function GetActionsClass: TAdapterActionsClass; virtual;
    function GetDataClass: TAdapterFieldsClass; virtual;
    procedure WebComponentsChange(Sender: TObject);
    procedure ClearErrors;

    { ICreateActionRequestContext }
    procedure CreateActionRequestContext(DispatchParams: IAdapterDispatchParams);
    { IAdapterAccess }
    function HasViewAccess: Boolean;
    function ImplHasViewAccess: Boolean; virtual;
    function HasModifyAccess: Boolean;
    function ImplHasModifyAccess: Boolean; virtual;
    function HasExecuteAccess: Boolean;
    function ImplHasExecuteAccess: Boolean; virtual;
    { IEchoAdapterFieldValues }
    procedure ImplSetEchoActionFieldValues(AValue: Boolean); virtual;
    procedure SetEchoActionFieldValues(AValue: Boolean);
    function ImplGetEchoActionFieldValues: Boolean; virtual;
    function GetEchoActionFieldValues: Boolean;
    { ISetSubComponents }
    procedure ImplSetActions(const Value: TAdapterSubComponent); virtual;
    procedure SetActions(const Value: TAdapterSubComponent);
    procedure SetData(const Value: TAdapterSubComponent); virtual;
    procedure ImplSetData(const Value: TAdapterSubComponent); virtual;
    { IClearAdapterValues }
    procedure ClearAdapterValues;
    procedure ImplClearAdapterValues; virtual;
    { IIteratorIndex }
    function GetIteratorIndex: Integer;
    function ImplGetIteratorIndex: Integer; virtual;
    function InIterator: Boolean;
    function ImplInIterator: Boolean; virtual;
    { IIteratorSupport }
    function StartIterator(var OwnerData: Pointer): Boolean;
    function ImplStartIterator(var OwnerData: Pointer): Boolean; virtual;
    function NextIteration(var OwnerData: Pointer): Boolean;
    function ImplNextIteration(var OwnerData: Pointer): Boolean; virtual;
    procedure EndIterator(OwnerData: Pointer);
    procedure ImplEndIterator(OwnerData: Pointer); virtual;
    { IGetScriptObject }
    function GetScriptObject: IDispatch;
    function ImplGetScriptObject: IDispatch; virtual;
    { IAdapterEditor }
    function CanAddFieldClass(AParent: TComponent; AClass: TClass): Boolean;
    function ImplCanAddFieldClass(AParent: TComponent; AClass: TClass): Boolean; virtual;
    function CanAddActionClass(AParent: TComponent; AClass: TClass): Boolean;
    function ImplCanAddActionClass(AParent: TComponent; AClass: TClass): Boolean; virtual;
    { IGetAdapterErrorsList }
    function GetAdapterErrorsList: TBaseAdapterErrorsList;
    { INotifyWebActivate }
    procedure NotifyActivate;
    procedure NotifyDeactivate;
    procedure ImplNotifyActivate; virtual;
    procedure ImplNotifyDeactivate; virtual;
    { IGetAdapterErrors }
    function GetAdapterErrors: TObject;
    { IGetAdapterHiddenFields }
    function GetAdapterHiddenFields: TObject;
    function GetAdapterHiddenRecordFields: TObject;
    { IGetAdapterFields }
    function GetAdapterFields: TComponent;
    { IGetAdapterActions }
    function GetAdapterActions: TComponent;
    { IWebVariableName }
    function GetVariableName: string;
    function ImplGetVariableName: string; virtual;
    { IWebVariablesContainer }
    function FindVariable(const AName: string): TComponent;
    function FindVariableContainer(const AName: string): TComponent;
    function GetVariableCount: Integer;
    function GetVariable(I: Integer): TComponent;
    function FindNamedVariable(const AName: string): TComponent; virtual;
    function FindNamedField(const AName: string): TComponent;
    function FindNamedAction(const AName: string): TComponent;
    function ImplFindVariable(const AName: string): TComponent; virtual;
    function ImplFindVariableContainer(const AName: string): TComponent;  virtual;
    function ImplGetVariableCount: Integer; virtual;
    function ImplGetVariable(I: Integer): TComponent; virtual;
    { IWebDataFields }
    procedure GetFieldsList(AList: TStrings);
    procedure ImplGetFieldsList(AList: TStrings); virtual;
    function IsFieldInUse(const AName: string): Boolean;
    function GetVisibleFields: TWebComponentList;
    function ImplGetVisibleFields: TWebComponentList; virtual;
    function FindField(const AName: string): TComponent;
    property VisibleFields: TWebComponentList read GetVisibleFields;

    { IWebActionsList }
    procedure GetActionsList(AList: TStrings);
    procedure ImplGetActionsList(AList: TStrings); virtual;
    function IsActionInUse(const AName: string): Boolean;
    function GetVisibleActions: TWebComponentList;
    function ImplGetVisibleActions: TWebComponentList; virtual;
    function FindAction(const AName: string): TComponent;
    property VisibleActions: TWebComponentList read GetVisibleActions;

    procedure NotifyAdapterChange;
    property NotifyList: TNotifyList read FNotifyList implements INotifyList;

    procedure GetChildren(Proc: TGetChildProc; Root: TComponent); override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function UpdateRecords(AActionRequest: IActionRequest=nil): Boolean; virtual;
    property OnIterateRecords: TIterateRecordsEvent read FOnIterateRecords write FOnIterateRecords;
    property Data: TAdapterFields read FData;
    property Actions: TAdapterActions read FActions;
    property Errors: TBaseAdapterErrorsList read GetAdapterErrorsList;
    property EchoActionFieldValues: Boolean read GetEchoActionFieldValues write SetEchoActionFieldValues;
    property OnBeforeUpdateFields: TActionRequestFieldsHandledEvent read FOnBeforeUpdateFields write FOnBeforeUpdateFields;
    property OnAfterUpdateFields: TActionRequestFieldsEvent read FOnAfterUpdateFields write FOnAfterUpdateFields;
    property OnBeforeValidateFields: TActionRequestFieldsHandledEvent read FOnBeforeValidateFields write FOnBeforeValidateFields;
    property OnAfterValidateFields: TActionRequestFieldsEvent read FOnAfterValidateFields write FOnAfterValidateFields;
    property ViewAccess: string read FViewAccess write FViewAccess;
    property ModifyAccess: string read FModifyAccess write FModifyAccess;
    property ExecuteAccess: string read FExecuteAccess write FExecuteAccess;
    property OnBeforeExecuteAction: TAdapterActionExecuteHandledEvent read FOnBeforeExecuteAction write FOnBeforeExecuteAction;
    property OnAfterExecuteAction: TAdapterActionExecuteEvent read FOnAfterExecuteAction write FOnAfterExecuteAction;
    property OnBeforeGetActionResponse: TAdapterActionExecuteHandledEvent read FOnBeforeGetActionResponse write FOnBeforeGetActionResponse;
    property OnAfterGetActionResponse: TAdapterActionExecuteEvent read FOnAfterGetActionResponse write FOnAfterGetActionResponse;
    property OnGetActionParams: TAdapterActionGetParamsEvent read FOnGetActionParams write FOnGetActionParams;
  end;

  TAdapter = class(TCustomAdapter)
  published
    property Data;
    property Actions;
    property ViewAccess;
    property ModifyAccess;
    property OnIterateRecords;
    property OnBeforeUpdateFields;
    property OnAfterUpdateFields;
    property OnBeforeValidateFields;
    property OnAfterValidateFields;
    property OnBeforeExecuteAction;
    property OnAfterExecuteAction;
    property OnBeforeGetActionResponse;
    property OnAfterGetActionResponse;
    property OnGetActionParams;
  end;

  IEchoActionFieldValue = interface
  ['{274C6B61-CAD6-11D4-A529-00C04F6BB853}']
    procedure SetEchoActionFieldValue(AValue: Boolean);
    function GetEchoActionFieldValue: Boolean;
    property EchoActionFieldValue: Boolean read GetEchoActionFieldValue write SetEchoActionFieldValue;
  end;

  TAdapterNamedField = class(TWebContainedComponent, IWebVariableName, IWebInputName,
    IWebGetFieldValue, IEchoActionFieldValue, IAsFormatted,
    IWebGetFieldName,  IWebSetFieldName,
    IWebGetDisplayWidth, IWebGetDisplayLabel, IWebGetMaxLength, IGetScriptObject,
    IAdapterFieldAccess, IAdapterFieldAttributes)
  private
    FFieldName: string;
    FAdapter: TComponent;
    FViewAccess: string;
    FModifyAccess: string;
    function GetActionOrigValue: IActionFieldValue;
    function GetActionValue: IActionFieldValue;
    function IsFieldNameStored: Boolean;
  protected
    function GetDefaultDisplayLabel: string; virtual;
    procedure CheckModifyAccess;
    procedure CheckViewAccess;
    procedure ParentChanged; override;
    function GetAdapter: TComponent;
    property Adapter: TComponent read GetAdapter;
    function FullyQualifyInputName: Boolean; virtual;
    { IWebInputName }
    function GetInputName: string;
    function ImplGetInputName: string; virtual;
    { IAdapterFieldAttributes }
    function GetVisible: Boolean;
    function GetRequired: Boolean;
    function ImplGetVisible: Boolean; virtual;
    function ImplGetRequired: Boolean; virtual;
    { IAdapterFieldAccess }
    function HasViewAccess: Boolean;
    function ImplHasViewAccess: Boolean; virtual;
    function HasModifyAccess: Boolean;
    function ImplHasModifyAccess: Boolean; virtual;
    { IGetScriptObject }
    function GetScriptObject: IDispatch;
    function ImplGetScriptObject: IDispatch; virtual;
    { IWebGetDisplayWidth }
    function GetDisplayWidth: Integer;
    function ImplGetDisplayWidth: Integer; virtual;
    { IWebGetDisplayLabel }
    function GetDisplayLabel: string;
    function ImplGetDisplayLabel: string; virtual;
    { IWebGetMaxLength }
    function GetMaxLength: Integer;
    function ImplGetMaxLength: Integer; virtual;
    { IWebSetFieldName }
    procedure SetFieldName(const AName: string);
    procedure ImplSetFieldName(const Value: string); virtual;
    { IWebVariableName, IWebGetFieldValue, IWebGetFieldName }
    function IWebGetFieldName.GetFieldName = GetVariableName;
    function GetVariableName: string;
    function GetValue: Variant;
    function ImplGetVariableName: string; virtual;
    function GetDefaultFieldName: string; virtual;
    function ImplGetValue: Variant; virtual;
    { IEchoActionFieldValue }
    procedure SetEchoActionFieldValue(AValue: Boolean);
    procedure ImplSetEchoActionFieldValue(AValue: Boolean); virtual;
    function GetEchoActionFieldValue: Boolean;
    function ImplGetEchoActionFieldValue: Boolean; virtual;
    { IAsFormatted }
    function AsFormatted: string;
    function ImplAsFormatted: string; virtual;
  public
    property FieldName: string read GetVariableName write SetFieldName
      stored IsFieldNameStored;
    property Value: Variant read GetValue;
    property ViewAccess: string read FViewAccess write FViewAccess;
    property ModifyAccess: string read FModifyAccess write FModifyAccess;
    property ActionValue: IActionFieldValue read GetActionValue;
    property ActionOrigValue: IActionFieldValue read GetActionOrigValue;
    property EchoActionFieldValue: Boolean read GetEchoActionFieldValue write SetEchoActionFieldValue;
  end;

  TAdapterNamedDisplayField = class(TAdapterNamedField, IGetHTMLStyle)
  private
    FDisplayLabel: string;
    FDisplayWidth: Integer;
    FReadOnly: Boolean;
    FRequired: Boolean;
    function IsDisplayLabelStored: Boolean;
  protected
    { IGetHTMLStyle }
    function GetDisplayStyle(const AAdapterMode: string): string;
    function GetViewMode(const AAdapterMode: string): string;
    function GetInputStyle(const AAdapterMode: string): string;
    function GetDisplayStyleType(const AAdapterMode: string): TAdapterDisplayHTMLElementType; virtual;
    function GetInputStyleType(const AAdapterMode: string): TAdapterInputHTMLElementType; virtual;
    function GetViewModeType(const AAdapterMode: string): TAdapterDisplayViewModeType; virtual;
    { IWebGetDisplayLabel }
    function ImplGetDisplayLabel: string; override;
    { IWebGetDisplayWidth }
    function ImplGetDisplayWidth: Integer; override;
    procedure SetDisplayLabel(const AValue: string);
    { IAdapterFieldAttributes }
    function ImplGetRequired: Boolean; override;
  public
    constructor Create(AOwner: TComponent); override;
    property DisplayLabel: string read ImplGetDisplayLabel write SetDisplayLabel
      stored IsDisplayLabelStored;
    property DisplayWidth: integer read FDisplayWidth write FDisplayWidth default -1;
    property Required: Boolean read FRequired write FRequired default False;
    property ReadOnly: Boolean read FReadOnly write FReadOnly default False;
  end;

  TUpdateFileList = class
  private
    FValue: IActionFieldValue;
    function GetFile(I: Integer): TAbstractWebRequestFile;
    function GetCount: Integer;
  public
    constructor Create(AValue: IActionFieldValue);
    property Count: Integer read GetCount;
    property Files[I: Integer]: TAbstractWebRequestFile read GetFile;
  end;

  TAbstractWebRequestFile = HTTPApp.TAbstractWebRequestFile;
  {$EXTERNALSYM TAbstractWebRequestFile}
  TAdapterFieldValidateValueEvent = procedure(Sender: TObject; AValue: IActionFieldValue; var Handled: Boolean) of object;
  TAdapterFieldGetValueEvent = procedure (Sender: TObject; var Value: Variant) of object;
  TAdapterFieldValueEvent = procedure (Sender: TObject; Value: Variant) of object;
  TAdapterFieldStringsEvent = procedure (Sender: TObject; Values: TStrings) of object;
  TAdapterFieldBooleanValueEvent = procedure (Sender: TObject; Value: Boolean) of object;
  TAdapterFieldFileListEvent = procedure (Sender: TObject; Files: TUpdateFileList) of object;
  TAdapterFieldFileEvent = procedure (Sender: TObject; AFile: TAbstractWebRequestFile) of object;
  TAdapterFieldStringEvent = procedure (Sender: TObject; Value: string) of object;
  TAdapterFieldGetBooleanEvent = procedure (Sender: TObject; var Value: Boolean) of object;
  TAdapterFieldGetStringEvent = procedure (Sender: TObject; var Value: string) of object;
  TAdapterFieldGetMultiValueEvent = procedure (Sender: TObject; Index: Integer; var Value: Variant) of object;
  TAdapterFieldGetMultiValueStringEvent = procedure (Sender: TObject; Index: Integer; var Value: string) of object;
  TAdapterFieldGetValueCountEvent = procedure (Sender: TObject; var Count: Integer) of object;
  TAdapterFieldHasValueEvent = procedure (Sender: TObject; const Value: Variant; var HasValue: Boolean) of object;
  TAdapterUpdateField = class(TAdapterNamedDisplayField, IGetAdapterValuesList,
    IUpdateValue, IValidateValue, ICheckValueChange)
  private
    FValuesList: IValuesListAdapter;
    FOnGetDisplayText: TAdapterFieldGetStringEvent;
    FEchoActionFieldValue: Boolean;
    FOnValidateValue: TAdapterFieldValidateValueEvent;
    procedure SetValuesList(const Value: IValuesListAdapter);
  protected
    function GetValueCount: Integer; virtual;
    function GetValues(I: Integer): Variant; virtual;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure DoOnValidateValue(AValue: IActionFieldValue;
      var AHandled: Boolean); virtual;
    function IsMultiValueField: Boolean; virtual;
    function ConvertValues(AValue: IActionFieldValue; Index: Integer): Variant; virtual;
    function ConvertValue(AValue: IActionFieldValue): Variant; virtual;
    function ConvertValueCount(AValue: IActionFieldValue): Integer; virtual;
    { ICheckValueChange }
    function CheckValueChange(AActionRequest: IActionRequest; AFieldIndex: Integer): Boolean;
    function ImplCheckValueChange(AActionRequest: IActionRequest; AFieldIndex: Integer): Boolean; virtual;
    { IGetAdapterValuesList }
    function GetAdapterValuesList: IValuesListAdapter;
    { IGetHTMLStyle }
    function GetInputStyleType(const AAdapterMode: string): TAdapterInputHTMLElementType; override;
    { IWebVariableName, IWebGetFieldValue }
    function ImplGetVariableName: string; override;
    procedure ImplSetFieldName(const Value: string); override;
    { IWebGetDisplayWidth }
    function ImplGetDisplayWidth: Integer; override;
    { IWebGetDisplayLabel }
    function ImplGetDisplayLabel: string; override;
    { IEchoActionFieldValue }
    procedure ImplSetEchoActionFieldValue(AValue: Boolean); override;
    function ImplGetEchoActionFieldValue: Boolean; override;
    { IAsFormatted }
    function ImplAsFormatted: string; override;
    { IValidateValue }
    procedure ValidateValue(AActionRequest: IActionRequest; AFieldIndex: Integer);
    procedure ImplValidateValue(AActionRequest: IActionRequest; AFieldIndex: Integer); virtual;
    { IUpdateValue }
    procedure UpdateValue(AActionRequest: IActionRequest; AFieldIndex: Integer);
    procedure ImplUpdateValue(AActionRequest: IActionRequest; AFieldIndex: Integer); virtual;
  public
    constructor Create(AOwner: TComponent); override;
    property Value: Variant read GetValue;
    property ValuesList: IValuesListAdapter read FValuesList write SetValuesList;
    property OnGetDisplayText: TAdapterFieldGetStringEvent read FOnGetDisplayText write FOnGetDisplayText;
    property OnValidateValue: TAdapterFieldValidateValueEvent read FOnValidateValue write FOnValidateValue;
  end;

  TCustomAdapterField = class(TAdapterUpdateField)
  private
    FOnGetValue: TAdapterFieldGetValueEvent;
    FOnUpdateValue: TAdapterFieldValueEvent;
  protected
    procedure DoOnValidateValue(AValue: IActionFieldValue;
      var AHandled: Boolean); override;
    function ImplGetValue: Variant; override;
    { IUpdateValue }
    procedure ImplUpdateValue(AActionRequest: IActionRequest; AFieldIndex: Integer); override;
  public
    property OnGetValue: TAdapterFieldGetValueEvent read FOnGetValue write FOnGetValue;
    property OnUpdateValue: TAdapterFieldValueEvent read FOnUpdateValue write FOnUpdateValue;
  end;

  TAdapterField = class(TCustomAdapterField)
  published
    property FieldName;
    property OnGetValue;
    property OnUpdateValue;
    property OnValidateValue;
    property OnGetDisplayText;
    property DisplayWidth;
    property DisplayLabel;
    property ValuesList;
    property ViewAccess;
    property ModifyAccess;
    property Required;
    property ReadOnly;
  end;

  TBaseAdapterMultiValueField = class(TAdapterUpdateField, IGetFieldValuesAdapter,
    IWebGetFieldValues)
  private
    FIteratorIndex: Integer;
    FFieldValuesAdapter: TComponent;
  protected
    function GetValueCount: Integer; override;
    function GetValues(I: Integer): Variant; override;
    { IWebGetFieldValues }
    function StartValueIterator(var OwnerData: Pointer): Boolean;
    function NextValueIteration(var OwnerData: Pointer): Boolean;
    procedure EndValueIterator(OwnerData: Pointer);
    function GetCurrentValue: Variant;
    function ImplGetCurrentValue: Variant; virtual;
    function HasValue(const AValue: Variant): Boolean;
    function ImplHasValue(const Value: Variant): Boolean; virtual;
   { IGetFieldValueAdapters }
    function GetFieldValuesAdapter: TComponent;
    function ImplGetFieldValuesAdapter: TComponent; virtual;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  end;

  TCustomAdapterMultiValueField = class(TBaseAdapterMultiValueField)
  private
    FOnGetValues: TAdapterFieldGetMultiValueEvent;
    FOnGetValueCount: TAdapterFieldGetValueCountEvent;
    FOnHasValue: TAdapterFieldHasValueEvent;
    FOnUpdateValues: TAdapterFieldStringsEvent;
    FOnValidateValues: TAdapterFieldStringsEvent;
  protected
    function GetValues(I: Integer): Variant; override;
    function GetValueCount: Integer; override;
    procedure DoOnValidateValue(AValue: IActionFieldValue;
      var AHandled: Boolean); override;
    { IWebGetFieldValues }
    function ImplHasValue(const Value: Variant): Boolean; override;
    { IGetHTMLStyle }
    function GetDisplayStyleType(const AAdapterMode: string): TAdapterDisplayHTMLElementType; override;
    function GetInputStyleType(const AAdapterMode: string): TAdapterInputHTMLElementType; override;
    { IUpdateValue }
    procedure ImplUpdateValue(AActionRequest: IActionRequest; AFieldIndex: Integer); override;
  public
    property ValueCount: Integer read GetValueCount;
    property Values[I: Integer]: Variant read GetValues;
    property OnGetValues: TAdapterFieldGetMultiValueEvent read FOnGetValues write FOnGetValues;
    property OnGetValueCount: TAdapterFieldGetValueCountEvent read FOnGetValueCount write FOnGetValueCount;
    property OnHasValue: TAdapterFieldHasValueEvent read FOnHasValue write FOnHasValue;
    property OnUpdateValues: TAdapterFieldStringsEvent read FOnUpdateValues write FOnUpdateValues;
    property OnValidateValues: TAdapterFieldStringsEvent read FOnValidateValues write FOnValidateValues;
  end;

  TAdapterMultiValueField = class(TCustomAdapterMultiValueField)
  published
    property OnGetValues;
    property OnGetValueCount;
    property OnHasValue;
    property FieldName;
    property DisplayWidth;
    property DisplayLabel;
    property ValuesList;
    property ViewAccess;
    property ModifyAccess;
    property Required;
    property OnUpdateValues;
    property OnValidateValues;
    property ReadOnly;
  end;

  TCustomAdapterBooleanField = class(TAdapterUpdateField, IWebValueIsEqual)
  private
    FOnGetValue: TAdapterFieldGetBooleanEvent;
    FOnUpdateValue: TAdapterFieldBooleanValueEvent;
  protected
    function ConvertValue(AValue: IActionFieldValue): Variant; override;
    { IWebValueIsEqual }
    function IsEqual(const AValue: Variant): Boolean;
    function ImplIsEqual(const AValue: Variant): Boolean; virtual;
    { IGetHTMLStyle }
    function GetDisplayStyleType(const AAdapterMode: string): TAdapterDisplayHTMLElementType; override;
    function GetInputStyleType(const AAdapterMode: string): TAdapterInputHTMLElementType; override;
    { IGetFieldValue }
    function ImplGetValue: Variant; override;
    { IUpdateValue }
    procedure ImplUpdateValue(AActionRequest: IActionRequest; AFieldIndex: Integer); override;
  public
    property OnGetValue: TAdapterFieldGetBooleanEvent read FOnGetValue write FOnGetValue;
    property OnUpdateValue: TAdapterFieldBooleanValueEvent read FOnUpdateValue write FOnUpdateValue;
  end;

  TAdapterBooleanField = class(TCustomAdapterBooleanField)
  published
    property OnGetValue;
    property OnUpdateValue;
    property FieldName;
    property DisplayWidth;
    property DisplayLabel;
    property OnValidateValue;
    property ValuesList;
    property ViewAccess;
    property ModifyAccess;
    property ReadOnly;
  end;

  TImageFieldGetParamsEvent = procedure(Sender: TObject; Params: TStrings) of object;
  TImageFieldGetImageEvent = procedure(Sender: TObject; Params: TStrings;
    var MimeType: string; var Image: TStream; var Owned: Boolean) of object;
  TImageFieldGetHREFEvent = procedure(Sender: TObject; var HREF: string) of object;

  TCustomAdapterImageField = class(TAdapterUpdateField,
  IGetAdapterImage, IGetAdapterItemRequestParams,
  IAdapterRequestHandler, IWebImageHREF)
  private
    FOnGetParams: TImageFieldGetParamsEvent;
    FOnGetImage: TImageFieldGetImageEvent;
    FOnGetHREF: TImageFieldGetHREFEvent;
    FHREF: string;
    FOnGetImageName: TAdapterFieldGetStringEvent;
    FOnUploadFile: TAdapterFieldFileEvent;
    FOnValidateFile: TAdapterFieldFileEvent;
  protected
    procedure RenderAdapterImage(ARequest: IImageRequest; AResponse: IImageResponse); virtual;
    procedure DoOnValidateValue(AValue: IActionFieldValue;
      var AHandled: Boolean); override;
    { IAdapterRequestHandler }
    procedure CreateRequestContext(DispatchParams: IAdapterDispatchParams);
    procedure ImplCreateRequestContext(DispatchParams: IAdapterDispatchParams);
    function HandleRequest(DispatchParams: IAdapterDispatchParams): Boolean;
    function ImplHandleRequest(DispatchParams: IAdapterDispatchParams): Boolean; virtual;
    { ICheckValueChange }
    function ImplCheckValueChange(AActionRequest: IActionRequest; AFieldIndex: Integer): Boolean; override;
    { IWebImageHREF }
    function WebImageHREF(var AHREF: string): Boolean;
    function ImplWebImageHREF(var AHREF: string): Boolean; virtual;
    { IGetHTMLStyle }
    function GetDisplayStyleType(const AAdapterMode: string): TAdapterDisplayHTMLElementType; override;
    function GetInputStyleType(const AAdapterMode: string): TAdapterInputHTMLElementType; override;
    { IGetAdapterImage }
    function GetAdapterImage: IInterface;
    { IGetAdapterItemRequestParams }
    procedure GetAdapterItemRequestParams(var AIdentifier: string; AParams: IAdapterItemRequestParams);
    { IWebGetFieldValue }
    function ImplGetValue: Variant; override;
    { IUpdateValue }
    procedure ImplUpdateValue(AActionRequest: IActionRequest; AFieldIndex: Integer); override;
  public
    property OnGetImageName: TAdapterFieldGetStringEvent read FOnGetImageName write FOnGetImageName;
    property OnUploadFile: TAdapterFieldFileEvent read FOnUploadFile write FOnUploadFile;
    property OnValidateFile: TAdapterFieldFileEvent read FOnValidateFile write FOnValidateFile;
    property HREF: string read FHREF write FHREF;
    property OnGetParams: TImageFieldGetParamsEvent read FOnGetParams write FOnGetParams;
    property OnGetImage: TImageFieldGetImageEvent read FOnGetImage write FOnGetImage;
    property OnGetHREF: TImageFieldGetHREFEvent read FOnGetHREF write FOnGetHREF;
    property ReadOnly;
  end;

  TAdapterImageField = class(TCustomAdapterImageField)
  published
    property OnGetParams;
    property OnGetImage;
    property OnGetImageName;
    property OnGetHREF;
    property OnValidateFile;
    property OnUploadFile;
    property HREF;
    property FieldName;
    property DisplayWidth;
    property DisplayLabel;
    property ValuesList;
    property ViewAccess;
    property ModifyAccess;
    property Required;
    property ReadOnly;
  end;

  TCustomAdapterFileField = class(TBaseAdapterMultiValueField)
  private
    FOnUploadFiles: TAdapterFieldFileListEvent;
    FOnGetFileNames: TAdapterFieldGetMultiValueStringEvent;
    FOnGetFileCount: TAdapterFieldGetValueCountEvent;
    FOnValidateFiles: TAdapterFieldFileListEvent;
  protected
    function GetFileNames(I: Integer): string;
    function GetValues(I: Integer): Variant; override;
    function GetValueCount: Integer; override;
    procedure DoOnValidateValue(AValue: IActionFieldValue;
      var AHandled: Boolean); override;
    { ICheckValueChange }
    function ImplCheckValueChange(AActionRequest: IActionRequest; AFieldIndex: Integer): Boolean; override;
    { IGetHTMLStyle }
    function GetDisplayStyleType(const AAdapterMode: string): TAdapterDisplayHTMLElementType; override;
    function GetInputStyleType(const AAdapterMode: string): TAdapterInputHTMLElementType; override;
    { IUpdateValue }
    procedure ImplUpdateValue(AActionRequest: IActionRequest; AFieldIndex: Integer); override;
  public
    property OnValidateFiles: TAdapterFieldFileListEvent read FOnValidateFiles write FOnValidateFiles;
    property OnUploadFiles: TAdapterFieldFileListEvent read FOnUploadFiles write FOnUploadFiles;
    property FileCount: Integer read GetValueCount;
    property FileNames[I: Integer]: string read GetFileNames;
    property OnGetFileNames: TAdapterFieldGetMultiValueStringEvent read FOnGetFileNames write FOnGetFileNames;
    property OnGetFileCount: TAdapterFieldGetValueCountEvent read FOnGetFileCount write FOnGetFileCount;
  end;

  TAdapterFileField = class(TCustomAdapterFileField)
  published
    property OnGetFileNames;
    property OnGetFileCount;
    property OnUploadFiles;
    property OnValidateFiles;
    property FieldName;
    property DisplayWidth;
    property DisplayLabel;
    property ViewAccess;
    property ModifyAccess;
    property Required;
    property ReadOnly;
  end;

  TCustomAdapterMemoField = class(TAdapterUpdateField)
  private
    FOnGetValue: TAdapterFieldGetStringEvent;
    FOnUploadFile: TAdapterFieldFileEvent;
    FOnUpdateValue: TAdapterFieldStringEvent;
  protected
    procedure DoOnValidateValue(AValue: IActionFieldValue;
      var AHandled: Boolean); override;
    { ICheckValueChange }
    function ImplCheckValueChange(AActionRequest: IActionRequest; AFieldIndex: Integer): Boolean; override;
    { IGetHTMLStyle }
    function GetDisplayStyleType(const AAdapterMode: string): TAdapterDisplayHTMLElementType; override;
    function GetInputStyleType(const AAdapterMode: string): TAdapterInputHTMLElementType; override;
    { IWebGetFieldValue }
    function ImplGetValue: Variant; override;
    { IUpdateValue }
    procedure ImplUpdateValue(AActionRequest: IActionRequest;
      AFieldIndex: Integer); override;
  public
    property OnUpdateValue: TAdapterFieldStringEvent read FOnUpdateValue write FOnUpdateValue;
    property OnUploadFile: TAdapterFieldFileEvent read FOnUploadFile write FOnUploadFile;
    property OnGetValue: TAdapterFieldGetStringEvent read FOnGetValue write FOnGetValue;
  end;

  TAdapterMemoField = class(TCustomAdapterMemoField)
  published
    property OnGetValue;
    property OnUpdateValue;
    property OnUploadFile;
    property FieldName;
    property DisplayWidth;
    property DisplayLabel;
    property ViewAccess;
    property ModifyAccess;
    property Required;
    property ReadOnly;
  end;

  TDefaultFieldsAdapter = class(TCustomAdapter)
  private
    FData: TAdapterDefaultFields;
    FActions: TAdapterDefaultActions;
  protected
    procedure AddDefaultFields(AComponents: TWebComponentList); virtual;
    procedure AddDefaultActions(AComponents: TWebComponentList); virtual;
    procedure DefaultWebComponentsChange(Sender: TObject);
    function GetActionsClass: TAdapterActionsClass; override;
    function GetDataClass: TAdapterFieldsClass; override;
    { ISetSubComponents }
    procedure ImplSetActions(const Value: TAdapterSubComponent); override;
    procedure ImplSetData(const Value: TAdapterSubComponent); override;
    { IWebDataFields }
    function ImplGetVisibleFields: TWebComponentList; override;
    { IWebActionsList }
    function ImplGetVisibleActions: TWebComponentList; override;
  public
    property Data: TAdapterDefaultFields read FData;
    property Actions: TAdapterDefaultActions read FActions;
  end;

  TDefaultFieldsPagedAdapter = class(TDefaultFieldsAdapter)
  private
    FCurrentPage: Integer;
    FPageSize: Integer;
    FOnGetRecordCount: TGetRecordCountEvent;
    FOnGetRecordIndex: TGetRecordIndexEvent;
    FOnGetEOF: TGetEOFEvent;
    FOnGetNextRecord: TGetRecordEvent;
    FOnGetFirstRecord: TGetRecordEvent;
  protected
    procedure EncodeActionParams(AParams: IAdapterItemRequestParams); override;
    procedure ExtractRequestParams(ARequest: IUnknown); override;
    function GetNextRecord: Boolean; virtual;
    function GetFirstRecord: Boolean; virtual;
    function GetEOF: Boolean; virtual;
    function GetRecordIndex: Integer; virtual;
    function GetRecordCount: Integer; virtual;

    procedure ImplNotifyDeactivate; override;
    function ImplCanAddActionClass(AParent: TComponent;
      AClass: TClass): Boolean; override;
    procedure SkipToPage;
    function EndOfPage: Boolean;
    procedure AddDefaultActions(AComponents: TWebComponentList); override;
    procedure ImplGetActionsList(AList: TStrings); override;
    function GetPageCount: Integer;
    procedure SetPageSize(const Value: Integer);
    function ImplNextIteration(var OwnerData: Pointer): Boolean; override;
    function ImplStartIterator(var OwnerData: Pointer): Boolean; override;
    procedure ImplEndIterator(OwnerData: Pointer); override;
  public
    property OnGetRecordIndex: TGetRecordIndexEvent read FOnGetRecordIndex write FOnGetRecordIndex;
    property OnGetEOF: TGetEOFEvent read FOnGetEOF write FOnGetEOF;
    property OnGetRecordCount: TGetRecordCountEvent read FOnGetRecordCount write FOnGetRecordCount;
    property OnGetFirstRecord: TGetRecordEvent read FOnGetFirstRecord write FOnGetFirstRecord;
    property OnGetNextRecord: TGetRecordEvent read FOnGetNextRecord write FOnGetNextRecord;
    property PageSize: Integer read FPageSize write SetPageSize default 0;
    property PageCount: Integer read GetPageCount;
    property CurrentPage: Integer read FCurrentPage write FCurrentPage;
    property RecordIndex: Integer read GetRecordIndex;
    property RecordCount: Integer read GetRecordCount;
  end;

  TCustomPagedAdapter = class(TDefaultFieldsPagedAdapter)
  end;

  TPagedAdapter = class(TCustomPagedAdapter)
  published
    property Data;
    property Actions;
    property ViewAccess;
    property ModifyAccess;
    property OnBeforeUpdateFields;
    property OnAfterUpdateFields;
    property OnBeforeValidateFields;
    property OnAfterValidateFields;
    property OnBeforeExecuteAction;
    property OnAfterExecuteAction;
    property OnBeforeGetActionResponse;
    property OnAfterGetActionResponse;
    property OnGetActionParams;
    property OnGetRecordIndex;
    property OnGetRecordCount;
    property OnGetEOF;
    property OnGetFirstRecord;
    property OnGetNextRecord;
    property PageSize;
  end;

  TActionExecuteEvent = procedure(Sender: TObject; Params: TStrings) of object;

  TCustomLoginFormAdapter = class;

  TAdapterLoginField = class(TAdapterNamedDisplayField)
  protected
    function GetAdapter: TCustomLoginFormAdapter;
  public
    property Adapter: TCustomLoginFormAdapter read GetAdapter;
  end;

  TAdapterUserNameField = class(TAdapterLoginField)
  protected
    function ImplGetValue: Variant; override;
  published
    property FieldName;
    property DisplayLabel;
    property DisplayWidth;
  end;

  TAdapterPasswordField = class(TAdapterLoginField)
  protected
    { IGetHTMLStyle }
    function GetInputStyleType(const AAdapterMode: string): TAdapterInputHTMLElementType; override;
    function ImplGetValue: Variant; override;
  published
    property FieldName;
    property DisplayLabel;
    property DisplayWidth;
  end;

  TAdapterNextPageField = class(TAdapterLoginField, IGetAdapterValuesList,
    IUpdateValue)
  private
    FPageList: TComponent;
    FEchoActionFieldValue: Boolean;
  protected
    { IEchoActionFieldValue }
    procedure ImplSetEchoActionFieldValue(AValue: Boolean); override;
    function ImplGetEchoActionFieldValue: Boolean; override;
    { IGetHTMLStyle }
    function GetInputStyleType(const AAdapterMode: string): TAdapterInputHTMLElementType; override;
    { IUpdateValue }
    procedure UpdateValue(AActionRequest: IActionRequest; AFieldIndex: Integer);

    function ImplGetValue: Variant; override;
    { IGetAdapterValuesList }
    function GetAdapterValuesList: IValuesListAdapter;
  public
    destructor Destroy; override;
  published
    property FieldName;
    property DisplayLabel;
    property DisplayWidth;
  end;

  TActionExecuteHandledEvent = procedure(Sender: TObject; Params: TStrings; var Handled: Boolean) of object;
  TActionGetParamsEvent = procedure(Sender: TObject; Params: TStrings) of object;
  TActionGetEnabledEvent = procedure(Sender: TObject; var Enabled: Boolean) of object;
  THandledEvent = procedure(Sender: TObject; var Handled: Boolean) of object;

  TBaseAdapterAction = class(TWebContainedComponent, IWebVariableName,
   IWebEnabled, IGetAdapterItemRequestParams, IWebGetActionName,
   IWebGetDisplayLabel, IGetScriptObject, IAdapterActionAccess,
   IAdapterRequestHandler, IGetAdapterActionRedirectOptions,
   IGetHTMLStyle, IAdapterActionAttributes,
   IIteratorSupport, IIteratorIndex, IIsAdapterActionList, IWebIsDefaultAction)
  private
    FIteratorIndex: Integer;
    FInIterator: Boolean;
    FDisplayLabel: string;
    FAdapter: TComponent;
    FExecuteAccess: string;
    FOnBeforeExecute: TActionExecuteHandledEvent;
    FOnAfterExecute: TActionExecuteEvent;
    FOnAfterGetResponse: TActionExecuteEvent;
    FOnBeforeGetResponse: TActionExecuteHandledEvent;
    FRedirectOptions: TAdapterActionRedirectOptions;
    FOnGetParams: TActionGetParamsEvent;
    function IsDisplayLabelStored: Boolean;
  protected
    function GetDefaultDisplayLabel: string; virtual;
    procedure SetDisplayLabel(const Value: string);
    procedure CheckExecuteAccess;
    procedure ParentChanged; override;
    function GetAdapter: TCustomAdapter;
    property Adapter: TCustomAdapter read GetAdapter;
    function GetErrors: TBaseAdapterErrorsList;
    property Errors: TBaseAdapterErrorsList read GetErrors;

    procedure DoBeforeExecuteActionRequest(AActionRequest: IActionRequest;
      AActionResponse: IActionResponse); virtual;
    procedure DoAfterExecuteActionRequest(AActionRequest: IActionRequest;
      AActionResponse: IActionResponse); virtual;
    procedure DoBeforeGetExecuteActionResponse(AActionRequest: IActionRequest;
      AActionResponse: IActionResponse); virtual;
    procedure DoAfterGetExecuteActionResponse(AActionRequest: IActionRequest;
      AActionResponse: IActionResponse); virtual;
    procedure GetExecuteActionResponse(AActionRequest: IActionRequest;
      AActionResponse: IActionResponse);
    procedure ImplGetExecuteActionResponse(AActionRequest: IActionRequest;
      AActionResponse: IActionResponse); virtual;
    procedure ExecuteActionRequest(AActionRequest: IActionRequest; AActionResponse: IActionResponse);
    procedure ImplExecuteActionRequest(AActionRequest: IActionRequest; AActionResponse: IActionResponse); virtual;
    function GetItemCount: Integer; virtual;
    { IIteratorIndex }
    function GetIteratorIndex: Integer;
    function ImplGetIteratorIndex: Integer; virtual;
    function InIterator: Boolean;
    function ImplInIterator: Boolean; virtual;
    { IWebIsDefaultAction }
    function IsDefaultAction(ADisplay: TObject): Boolean;
    function ImplIsDefaultAction(ADisplay: TObject): Boolean; virtual;
    { IIsAdapterActionList }
    function GetIsAdapterActionList: Boolean;
    function ImplGetIsAdapterActionList: Boolean; virtual;
    { IAdapterActionAttributes }
    function GetVisible: Boolean;
    function ImplGetVisible: Boolean; virtual;
    { IGetHTMLStyle }
    function GetDisplayStyle(const AAdapterMode: string): string;
    function GetViewMode(const AAdapterMode: string): string;
    function GetInputStyle(const AAdapterMode: string): string;
    function GetDisplayStyleType(const AAdapterMode: string): TAdapterActionHTMLElementType; virtual;
    function GetViewModeType(const AAdapterMode: string): TAdapterDisplayViewModeType; virtual;
    { IGetAdapterActionRedirectOptions }
    function GetFailureOptions: TAdapterActionRedirectOptions;
    function GetSuccessOptions: TAdapterActionRedirectOptions;
    function ImplGetFailureOptions: TAdapterActionRedirectOptions; virtual;
    function ImplGetSuccessOptions: TAdapterActionRedirectOptions; virtual;
    { IIteratorSupport }
    function StartIterator(var OwnerData: Pointer): Boolean;
    function NextIteration(var OwnerData: Pointer): Boolean;
    procedure EndIterator(OwnerData: Pointer);
    function ImplStartIterator(var OwnerData: Pointer): Boolean;
    function ImplNextIteration(var OwnerData: Pointer): Boolean;
    procedure ImplEndIterator(OwnerData: Pointer);
    { IAdapterRequestHandler }
    procedure CreateRequestContext(DispatchParams: IAdapterDispatchParams);
    procedure ImplCreateRequestContext(DispatchParams: IAdapterDispatchParams);
    function HandleRequest(DispatchParams: IAdapterDispatchParams): Boolean;
    function ImplHandleRequest(DispatchParams: IAdapterDispatchParams): Boolean; virtual;
    { IAdapterActionAccess }
    function HasExecuteAccess: Boolean;
    function ImplHasExecuteAccess: Boolean; virtual;
    { IGetScriptObject }
    function GetScriptObject: IDispatch;
    function ImplGetScriptObject: IDispatch; virtual;
    { IWebGetDisplayLabel }
    function GetDisplayLabel: string;
    function ImplGetDisplayLabel: string; virtual;
    { IWebVariableName }
    function GetVariableName: string;
    function ImplGetVariableName: string;
    { IGetAdapterItemRequestParams }
    procedure GetAdapterItemRequestParams(var AIdentifier: string; Params: IAdapterItemRequestParams);
    procedure ImplGetAdapterItemRequestParams(var AIdentifier: string; Params: IAdapterItemRequestParams); virtual;
    { IWebEnabled }
    function WebEnabled: Boolean;
    function ImplWebEnabled: Boolean; virtual;
    { IWebGetActionName }
    function GetActionName: string;
    function ImplGetActionName: string; virtual;
    function GetDefaultActionName: string; virtual;
  public
    property ActionName: string read GetActionName;
    property ExecuteAccess: string read FExecuteAccess write FExecuteAccess;
    property DisplayLabel: string read ImplGetDisplayLabel write SetDisplayLabel
      stored IsDisplayLabelStored;
    property OnBeforeExecute: TActionExecuteHandledEvent read FOnBeforeExecute write FOnBeforeExecute;
    property OnAfterExecute: TActionExecuteEvent read FOnAfterExecute write FOnAfterExecute;
    property OnBeforeGetResponse: TActionExecuteHandledEvent read FOnBeforeGetResponse write FOnBeforeGetResponse;
    property OnAfterGetResponse: TActionExecuteEvent read FOnAfterGetResponse write FOnAfterGetResponse;
    property RedirectOptions: TAdapterActionRedirectOptions read FRedirectOptions write FRedirectOptions default [];
    property OnGetParams: TActionGetParamsEvent read FOnGetParams write FOnGetParams;
    property ItemCount: Integer read GetItemCount;
    property ItemIndex: Integer read FIteratorIndex;
  end;

  TCustomAdapterAction = class(TBaseAdapterAction, IWebSetActionName)
  private
    FActionName: string;
    FOnExecute: TActionExecuteEvent;
    FOnGetEnabled: TActionGetEnabledEvent;
    function IsActionNameStored: Boolean;
 protected
    procedure ImplExecuteActionRequest(AActionRequest: IActionRequest; AActionResponse: IActionResponse); override;
     { IWebSetActionName }
    procedure SetActionName(const Value: string);
    procedure ImplSetActionName(const Value: string);
    { IGetAdapterItemRequestParams }
    procedure ImplGetAdapterItemRequestParams(var AIdentifier: string; Params: IAdapterItemRequestParams); override;
    { IWebEnabled }
    function ImplWebEnabled: Boolean; override;
    { ISetGetActionName }
    function ImplGetActionName: string; override;
    { IGetAdapterActionRedirectOptions }
    function ImplGetSuccessOptions: TAdapterActionRedirectOptions; override;
  public
    property ActionName: string read ImplGetActionName write ImplSetActionName stored
      IsActionNameStored;
    property OnExecute: TActionExecuteEvent read FOnExecute write FOnExecute;
    property OnGetEnabled: TActionGetEnabledEvent read FOnGetEnabled write FOnGetEnabled;
    property OnBeforeExecute;
    property OnAfterExecute;
    property OnBeforeGetResponse;
    property OnAfterGetResponse;
  end;

  TImplementedAdapterAction = class(TCustomAdapterAction)
  end;

  TCustomPagedAdapterAction = class(TImplementedAdapterAction)
  protected
    function GetAdapter: TDefaultFieldsPagedAdapter;
    property Adapter: TDefaultFieldsPagedAdapter read GetAdapter;
  end;

  TCustomAdapterPageAction = class(TCustomPagedAdapterAction)
  private
  protected
    function GetNewPage(var AValue: Integer): Boolean; virtual;
    procedure ImplExecuteActionRequest(AActionRequest: IActionRequest; AActionResponse: IActionResponse); override;

    { IWebIsDefaultAction }
    function ImplIsDefaultAction(ADisplay: TObject): Boolean; override;
    { IGetAdapterItemRequestParams }
    procedure ImplGetAdapterItemRequestParams(var AIdentifier: string; Params: IAdapterItemRequestParams); override;
    { IWebEnabled }
    function ImplWebEnabled: Boolean; override;
    { IGetHTMLStyle }
    function GetDisplayStyleType(const AAdapterMode: string): TAdapterActionHTMLElementType; override;
  end;

  TAdapterNextPageAction = class(TCustomAdapterPageAction)
  private
  protected
    function GetNewPage(var AValue: Integer): Boolean; override;
    function GetDefaultActionName: string; override;
    function GetDefaultDisplayLabel: string; override;
  published
    property OnGetParams;
    property DisplayLabel;
    property ExecuteAccess;
    property OnBeforeExecute;
    property OnAfterExecute;
    property OnBeforeGetResponse;
    property OnAfterGetResponse;
    property RedirectOptions;
  end;

  TAdapterPrevPageAction = class(TCustomAdapterPageAction)
  protected
    function GetNewPage(var AValue: Integer): Boolean; override;
    function GetDefaultActionName: string; override;
    function GetDefaultDisplayLabel: string; override;
  published
    property OnGetParams;
    property DisplayLabel;
    property ExecuteAccess;
    property OnBeforeExecute;
    property OnAfterExecute;
    property OnBeforeGetResponse;
    property OnAfterGetResponse;
    property RedirectOptions;
  end;

  TWebFormGetPageNameEvent = procedure (Sender: TObject; APageIndex: Integer; var Value: string) of object;

  TCustomAdapterGotoPageAction = class(TCustomPagedAdapterAction)
  private
    FOnGetPageName: TWebFormGetPageNameEvent;
  protected
    function GetItemCount: Integer; override;
    function GetDefaultActionName: string; override;
    procedure ImplExecuteActionRequest(AActionRequest: IActionRequest; AActionResponse: IActionResponse); override;
    { IWebIsDefaultAction }
    function ImplIsDefaultAction(ADisplay: TObject): Boolean; override;
    { IWebGetDisplayLabel }
    function ImplGetDisplayLabel: string; override;
    { IIsAdapterActionList }
    function ImplGetIsAdapterActionList: Boolean; override;
    { IGetAdapterItemRequestParams }
    procedure ImplGetAdapterItemRequestParams(var AIdentifier: string; Params: IAdapterItemRequestParams); override;
    { IWebEnabled }
    function ImplWebEnabled: Boolean; override;
    { IGetHTMLStyle }
    function GetDisplayStyleType(const AAdapterMode: string): TAdapterActionHTMLElementType; override;
  public
    property OnGetPageName: TWebFormGetPageNameEvent read FOnGetPageName write FOnGetPageName;
  end;

  TAdapterGotoPageAction = class(TCustomAdapterGotoPageAction)
  published
    property OnGetParams;
    property ExecuteAccess;
    property OnBeforeExecute;
    property OnAfterExecute;
    property OnBeforeGetResponse;
    property OnAfterGetResponse;
    property RedirectOptions;
    property OnGetPageName;
  end;

  TCustomLoginFormAdapterAction = class(TImplementedAdapterAction)
  private
    function GetAdapter: TCustomLoginFormAdapter;
  protected
    property Adapter: TCustomLoginFormAdapter read GetAdapter;
  end;

  TLoginFormAdapterLoginAction = class(TCustomLoginFormAdapterAction)
  private
    function GetLoginStrings: TStrings;
  protected
    procedure ImplExecuteActionRequest(AActionRequest: IActionRequest; AActionResponse: IActionResponse); override;
    procedure ImplGetAdapterItemRequestParams(var AIdentifier: string; Params: IAdapterItemRequestParams); override;
    function NextPage: string; virtual;
    function GetDefaultActionName: string; override;
  published
    property DisplayLabel;
    property OnBeforeExecute;
    property OnAfterExecute;
    property OnBeforeGetResponse;
    property OnAfterGetResponse;
    property OnGetParams;
  end;

  TAdapterAction = class(TCustomAdapterAction)
  published
    property ActionName;
    property ExecuteAccess;
    property OnExecute;
    property OnGetParams;
    property OnGetEnabled;
    property DisplayLabel;
    property RedirectOptions;
    property OnBeforeGetResponse;
    property OnAfterGetResponse;
  end;

  TAbstractFieldValuesAdapter = class(TDefaultFieldsAdapter, IFieldValuesAdapter)
  protected
    function GetValueFieldClass: TComponentClass; virtual; abstract;
    { IGetScriptObject }
    function ImplGetScriptObject: IDispatch; override;
    { IIteratorSupport }
    function ImplStartIterator(var OwnerData: Pointer): Boolean; override;
    function ImplNextIteration(var OwnerData: Pointer): Boolean; override;
    procedure ImplEndIterator(OwnerData: Pointer); override;
    { IFieldValuesAdapter }
    function GetField: TObject;
    function ImplGetField: TObject; virtual; abstract;
    function GetValueIndex: Integer;
    function ImplGetValueIndex: Integer; virtual; abstract;
    { IAdapterEditor }
    function ImplCanAddFieldClass(AParent: TComponent; AClass: TClass): Boolean; override;
    { IWebDataFields }
    procedure ImplGetFieldsList(AList: TStrings); override;
  end;

  TFieldValuesAdapter = class(TAbstractFieldValuesAdapter)
  private
    FIteratorIndex: Integer;
    FField: TObject;
  protected
    function GetValueFieldClass: TComponentClass; override;
    { IFieldValuesAdapter }
    function ImplGetField: TObject; override;
    function ImplGetValueIndex: Integer; override;
    { IIteratorAdapter }
    function ImplStartIterator(var OwnerData: Pointer): Boolean; override;
    function ImplNextIteration(var OwnerData: Pointer): Boolean; override;
    procedure ImplEndIterator(OwnerData: Pointer); override;
    property Field: TObject read FField;
  public
    constructor Create(AOwner: TComponent; AField: TObject); reintroduce; virtual;
  end;

  TFieldValuesValueField = class(TAdapterNamedField)
  private
    function GetField: TObject;
  protected
    function GetDefaultFieldName: string; override;
    function ImplGetValue: Variant; override;
    { IAsFormatted }
    function ImplAsFormatted: string; override;
    property Field: TObject read GetField;
  end;

  TBaseValuesListAdapter = class(TDefaultFieldsAdapter, IValuesListAdapter)
  protected
    function GetNameFieldClass: TComponentClass; virtual;
    function GetValueFieldClass: TComponentClass; virtual;
    { GetScriptObject }
    function ImplGetScriptObject: IDispatch; override;
    { IIteratorSupport }
    function ImplStartIterator(var OwnerData: Pointer): Boolean; override;
    function ImplNextIteration(var OwnerData: Pointer): Boolean; override;
    procedure ImplEndIterator(OwnerData: Pointer); override;
    { IValuesListAdapter }
    function GetListValue: Variant;
    function GetListName: string;
    function ImplGetListValue: Variant; virtual;
    function ImplGetListName: string; virtual;
    function GetListNameOfValue(Value: Variant): string;
    function GetListImageOfValue(Value: Variant): IInterface;
    function ImplGetListImageOfValue(Value: Variant): IInterface; virtual;
    function GetListImage: IInterface;
    function ImplGetListImage: IInterface; virtual;
    function ImplGetListNameOfValue(Value: Variant): string; virtual;
    { IAdapterEditor }
    function ImplCanAddFieldClass(AParent: TComponent; AClass: TClass): Boolean; override;
    { IWebDataFields }
    procedure ImplGetFieldsList(AList: TStrings); override;
  end;

  TBaseValuesListField = class(TAdapterNamedField)
  protected
    function GetAdapter: TBaseValuesListAdapter;
    property Adapter: TBaseValuesListAdapter read GetAdapter;
  end;

  TValuesListNameField = class(TBaseValuesListField)
  protected
    function GetDefaultFieldName: string; override;
    function ImplGetValue: Variant; override;
  end;

  TValuesListValueField = class(TBaseValuesListField)
  protected
    function GetDefaultFieldName: string; override;
    function ImplGetValue: Variant; override;
  end;

  TCustomStringsValuesList = class(TBaseValuesListAdapter)
  private
    FStrings: TStrings;
    FIndex: Integer;
    FStringsPrepared: Boolean;
    FOnPrepareStrings: TNotifyEvent;
    procedure SetStrings(const Value: TStrings);
    function GetStrings: TStrings;
  protected
    property StringsPrepared: Boolean read FStringsPrepared write FStringsPrepared;
    procedure PrepareStrings; virtual;

    function GetNameFieldClass: TComponentClass; override;
    function GetValueFieldClass: TComponentClass; override;
    { INotifyWebActivate }
    procedure ImplNotifyDeactivate; override;
    { IValuesListAdapter }
    function ImplGetListValue: Variant; override;
    function ImplGetListName: string;  override;
    function ImplGetListNameOfValue(Value: Variant): string; override;
    { IIteratorAdapter }
    function ImplStartIterator(var OwnerData: Pointer): Boolean; override;
    function ImplNextIteration(var OwnerData: Pointer): Boolean; override;
    procedure ImplEndIterator(OwnerData: Pointer); override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property Strings: TStrings read GetStrings write SetStrings;
    property OnPrepareStrings: TNotifyEvent read FOnPrepareStrings write FOnPrepareStrings;
  end;

  TStringsValuesList = class(TCustomStringsValuesList)
  published
    property Strings;
    property Data;
    property Actions;
    property OnPrepareStrings;
  end;

  TLogicalPageList = class(TCustomStringsValuesList)
  public
    constructor Create(AOwner: TComponent); override;
  end;

  TValidateAdapterFieldEvent = procedure(Sender: TObject; Value: Variant; var Handled: Boolean) of object;
  TLoginUserIDEvent = procedure(Sender: TObject; UserID: Variant) of object;

  TCustomLoginFormAdapter = class(TDefaultFieldsAdapter)
  private
    FOnValidateUserName: TValidateAdapterFieldEvent;
    FOnValidatePassword: TValidateAdapterFieldEvent;
    FOnLogin: TLoginUserIDEvent;
    FEndUser: IWebEndUser;
    FUserList: IWebUserList;
    FPasswordRequired: Boolean;
    FNextPage: string;
    function GetPassword: Variant;
    function GetUserName: Variant;
    function GetNextPage: string;
  protected
    procedure RaiseBlankPassword;
    procedure RaiseBlankUserName;
    function EndUser: IWebEndUser;
    function UserList: IWebUserList;
    procedure ValidateUserName;
    procedure ValidatePassword;
    procedure ExecuteLogin(AUserID: Variant);
    property NextPage: string read GetNextPage write FNextPage;

    { INotifyWebActivate }
    procedure ImplNotifyDeactivate; override;
    { IAdapterEditor }
    function ImplCanAddFieldClass(AParent: TComponent; AClass: TClass): Boolean; override;
    function ImplCanAddActionClass(AParent: TComponent; AClass: TClass): Boolean; override;
    { IWebDataFields }
    procedure ImplGetFieldsList(AList: TStrings); override;
    { IWebActionsList }
    procedure ImplGetActionsList(AList: TStrings); override;
  public
    property OnValidateUserName: TValidateAdapterFieldEvent read FOnValidateUserName write FOnValidateUserName;
    property OnValidatePassword: TValidateAdapterFieldEvent read FOnValidatePassword write FOnValidatePassword;
    property OnLogin: TLoginUserIDEvent read FOnLogin write FOnLogin;
    property PasswordRequired: Boolean read FPasswordRequired write FPasswordRequired default False;
    property Password: Variant read GetPassword;
    property UserName: Variant read GetUserName;
  end;

  TLoginFormAdapter = class(TCustomLoginFormAdapter)
  published
    property Data;
    property Actions;
    property OnValidateUserName;
    property OnValidatePassword;
    property OnLogin;
    property PasswordRequired;
    property OnBeforeExecuteAction;
    property OnAfterExecuteAction;
    property OnBeforeGetActionResponse;
    property OnAfterGetActionResponse;
    property OnGetActionParams;
  end;

  TEndUserHandledEvent = procedure(Sender: TObject; var Handled: Boolean) of object;
  TEndUserIsLoggedInEvent = procedure(Sender: TObject; var IsLoggedIn: Boolean) of object;
  TEndUserUserIDEvent = procedure(Sender: TObject; UserID: Variant) of object;
  TEndUserGetUserIDEvent = procedure(Sender: TObject; var UserID: Variant) of object;
  TEndUserGetNameEvent = procedure(Sender: TObject; var Name: string) of object;
  TEndUserRightsEvent = procedure(Sender: TObject; Rights: TStrings; var HasRights, Handled: Boolean) of object;

  TBaseEndUserAdapter = class(TDefaultFieldsAdapter, IWebEndUser)
  private
    FLoginPage: string;
    FOnProduceLoginPage: TEndUserHandledEvent;
    FOnHasRights: TEndUserRightsEvent;
    FUserList: IWebUserList;
  protected
    function UserList: IWebUserList;
    function GetUserID: Variant; virtual;
    // Methods called by adapter actions
    procedure ExecuteLoginForm; virtual;
    function CanExecuteLoginForm: Boolean; virtual;
    procedure ExecuteLogout; virtual;
    function CanExecuteLogout: Boolean; virtual;
    procedure ExecuteLogin(AUserID: Variant); virtual;
    function GetLoggedInValue: Boolean; virtual;
    function GetDisplayNameValue: string; virtual;

    function CanProduceLoginPage: Boolean; virtual;
    function DoOnHasRights(AEvent: TEndUserRightsEvent; const ARights: string): Boolean; virtual;

    { IWebEndUser }
    function GetDisplayName: string;
    function ImplGetDisplayName: string; virtual;
    function GetLoggedIn: Boolean;
    function ImplGetLoggedIn: Boolean; virtual;
    function GetLogoutAction: TComponent;
    function ImplGetLogoutAction: TComponent; virtual;
    function GetLoginFormAction: TComponent;
    function ImplGetLoginFormAction: TComponent;
    function GetEndUserAdapter: TComponent;
    function ImplGetEndUserAdapter: TComponent; virtual;
    procedure LogIn(AUserID: Variant);
    procedure ImplLogIn(AUserID: Variant); virtual;
    function ProduceLoginPage: Boolean;
    function ImplProduceLoginPage: Boolean; virtual;
    function HasExecuteRights(ARights: string): Boolean;
    function ImplHasExecuteRights(ARights: string): Boolean; virtual;
    function HasViewRights(ARights: string): Boolean;
    function ImplHasViewRights(ARights: string): Boolean; virtual;
    function HasModifyRights(ARights: string): Boolean;
    function ImplHasModifyRights(ARights: string): Boolean; virtual;

    { IAdapterEditor }
    function ImplCanAddFieldClass(AParent: TComponent; AClass: TClass): Boolean; override;
    function ImplCanAddActionClass(AParent: TComponent; AClass: TClass): Boolean; override;
    { IWebDataFields }
    procedure ImplGetFieldsList(AList: TStrings); override;
    { IWebActionsList }
    procedure ImplGetActionsList(AList: TStrings); override;
  public
    property LoginPage: string read FLoginPage write FLoginPage;
    property OnProduceLoginPage: TEndUserHandledEvent read FOnProduceLoginPage write FOnProduceLoginPage;
    property OnHasRights: TEndUserRightsEvent read FOnHasRights write FOnHasRights;
  end;

  TCustomEndUserAdapter = class(TBaseEndUserAdapter)
  private
    FOnIsLoggedIn: TEndUserIsLoggedInEvent;
    FOnGetDisplayName: TEndUserGetNameEvent;
    FOnLogout: TNotifyEvent;
    FOnLogin: TEndUserUserIDEvent;
    FOnGetUserID: TEndUserGetUserIDEvent;
  protected
    procedure ExecuteLogout; override;
    procedure ExecuteLogin(AUserID: Variant); override;
    function GetLoggedInValue: Boolean; override;
    function GetDisplayNameValue: string; override;
    function GetUserID: Variant; override;

  public
    property OnIsLoggedIn: TEndUserIsLoggedInEvent read FOnIsLoggedIn write FOnIsLoggedIn;
    property OnGetDisplayName: TEndUserGetNameEvent read FOnGetDisplayName write FOnGetDisplayName;
    property OnLogout: TNotifyEvent read FOnLogout write FOnLogout;
    property OnLogin: TEndUserUserIDEvent read FOnLogin write FOnLogin;
    property OnGetUserID: TEndUserGetUserIDEvent read FOnGetUserID write FOnGetUserID;
  end;

  TEndUserAdapter = class(TCustomEndUserAdapter)
  published
    property OnIsLoggedIn;
    property OnGetDisplayName;
    property OnLogout;
    property OnLogin;
    property OnProduceLoginPage;
    property LoginPage;
    property OnHasRights;
    property Data;
    property Actions;
    property OnBeforeExecuteAction;
    property OnAfterExecuteAction;
    property OnBeforeGetActionResponse;
    property OnAfterGetActionResponse;
    property OnGetActionParams;
  end;

  TCustomEndUserSessionAdapter = class(TBaseEndUserAdapter)
  private
    procedure SetUserID(const Value: Variant);
  protected
    procedure ExecuteLogout; override;
    procedure ExecuteLogin(AUserID: Variant); override;
    function GetLoggedInValue: Boolean; override;
    function GetDisplayNameValue: string; override;
    function GetUserID: Variant; override;
  public
    property UserID: Variant read GetUserID write SetUserID;
  end;

  TEndUserSessionAdapter = class(TCustomEndUserSessionAdapter)
  published
    property OnProduceLoginPage;
    property LoginPage;
    property OnHasRights;
    property Data;
    property Actions;
    property OnBeforeExecuteAction;
    property OnAfterExecuteAction;
    property OnBeforeGetActionResponse;
    property OnAfterGetActionResponse;
    property OnGetActionParams;
  end;

  TCustomApplicationAdapter = class(TDefaultFieldsAdapter,
    IWebApplicationInfo)
  private
    FApplicationTitle: string;
  protected
    { IWebApplicationInfo }
    function GetApplicationTitle: string;
    function GetApplicationAdapter: TComponent;

    { IAdapterEditor }
    function ImplCanAddFieldClass(AParent: TComponent; AClass: TClass): Boolean; override;
    function ImplCanAddActionClass(AParent: TComponent; AClass: TClass): Boolean; override;
    { IWebDataFields }
    procedure ImplGetFieldsList(AList: TStrings); override;
    { IWebActionsList }
    procedure ImplGetActionsList(AList: TStrings); override;
  public
    property ApplicationTitle: string read FApplicationTitle write FApplicationTitle;
  end;

  TApplicationAdapter = class(TCustomApplicationAdapter)
  published
    property ApplicationTitle;
    property Data;
    property Actions;
    property OnBeforeExecuteAction;
    property OnAfterExecuteAction;
    property OnBeforeGetActionResponse;
    property OnAfterGetActionResponse;
    property OnGetActionParams;
  end;

  TCustomEndUserAdapterAction = class(TImplementedAdapterAction)
  private
    function GetAdapter: TBaseEndUserAdapter;
  protected
    property Adapter: TBaseEndUserAdapter read GetAdapter;
  end;

  TEndUserAdapterLoginFormAction = class(TCustomEndUserAdapterAction)
  private
  protected
    procedure ImplExecuteActionRequest(AActionRequest: IActionRequest; AActionResponse: IActionResponse); override;
    { IWebEnabled }
    function ImplWebEnabled: Boolean; override;
    function GetDefaultActionName: string; override;
  published
    property DisplayLabel;
    property OnGetParams;
    property OnBeforeExecute;
    property OnAfterExecute;
    property OnBeforeGetResponse;
    property OnAfterGetResponse;
  end;

  TEndUserAdapterLogoutAction = class(TCustomEndUserAdapterAction)
  protected
    procedure ImplExecuteActionRequest(AActionRequest: IActionRequest; AActionResponse: IActionResponse); override;
    { IWebEnabled }
    function ImplWebEnabled: Boolean; override;

    function GetDefaultActionName: string; override;
  published
    property DisplayLabel;
    property OnGetParams;
    property OnBeforeExecute;
    property OnAfterExecute;
    property OnBeforeGetResponse;
    property OnAfterGetResponse;
  end;

  TAdapterEndUserField = class(TAdapterNamedDisplayField)
  private
    function GetAdapter: TBaseEndUserAdapter;
  protected
    property Adapter: TBaseEndUserAdapter read GetAdapter;
  end;

  TAdapterEndUserLoggedInField = class(TAdapterEndUserField)
  protected
    function GetDefaultFieldName: string; override;
    { IWebGetFieldValue }
    function ImplGetValue: Variant; override;
  end;

  TAdapterEndUserDisplayNameField = class(TAdapterEndUserField)
  protected
    function GetDefaultFieldName: string; override;
    { IWebGetFieldValue }
    function ImplGetValue: Variant; override;
  end;

  TCustomApplicationAdapterAction = class(TImplementedAdapterAction)
  private
    function GetAdapter: TCustomApplicationAdapter;
  protected
    property Adapter: TCustomApplicationAdapter read GetAdapter;
  end;

  TAdapterApplicationField = class(TAdapterNamedDisplayField)
  private
    function GetAdapter: TCustomApplicationAdapter;
  protected
    property Adapter: TCustomApplicationAdapter read GetAdapter;
  end;

  TAdapterApplicationTitleField = class(TAdapterApplicationField)
  protected
    function GetDefaultFieldName: string; override;
    { IWebGetFieldValue }
    function ImplGetValue: Variant; override;
  end;

  EAdapterException = class(EWebBrokerException)
  private
    FID: Integer;
  public
    // Reserved parameter below is for BCB compatibility and should not be used
    constructor CreateID(const AMsg: string; AID: Integer; Reserved: Integer = 0);
    property ID: Integer read FID write FID;
  end;

  EAdapterFieldException = class(EAdapterException)
  private
    FFieldName: string;
  public
    property FieldName: string read FFieldName write FFieldName;
    constructor Create(const AMsg, AFieldName: string; AID: Integer = 0);
  end;

procedure AddDefaultActions(AList: TStrings; AComponents: TWebComponentList);
procedure AddDefaultFields(AList: TStrings; AComponents: TWebComponentList);
function FindAdapterField(AWebComponents: TWebComponentList; const AName: string): TComponent;
function FindAdapterAction(AWebComponents: TWebComponentList; const AName: string): TComponent;
function FindAdapterInParent(AComponent: TComponent): TComponent;
procedure RaiseMultipleFilesException(AFieldName: string);
procedure RaiseFileUploadNotSupported(AFieldName: string);
procedure RaiseMultipleValuesException(AFieldName: string);
function MakeAdapterRequestIdentifier(AComponent: TComponent): string;
function MakeValidAdapterFieldName(const AFieldName: string): string;

var
  // Designtime notification
  NotifyPossibleHTMLChange: procedure;

const
  sImageRequest = '__img';               { Do not localize }
  sActionRequestLong = '__action';        { Do not localize }
  sCurrentPage = '_cp';                { Do not localize }

  sNextPageAction = 'NextPage'; // Do not localize
  sPrevPageAction = 'PrevPage'; // Do not localize
  sGotoPageAction = 'GotoPage'; // Do not localize

  sLoginUserName = 'UserName';    // Do not localize
  sLoginPassword = 'Password';    // Do not localize

implementation

uses Variants, AutoAdap, WebDisp, WebConst, SiteConst, MidItems;

procedure RaiseVariableIsNotAContainer(const AName: string);
begin
  raise EAdapterException.CreateFmt(sVariableIsNotAContainer, [AName]);
end;

procedure RaiseFieldModificationNotPermitted(const AFieldName: string);
begin
  raise EAdapterFieldException.Create(sFieldModificationNotPermitted, AFieldName);
end;

procedure RaiseActionExecutionNotPermitted(const AFieldName: string);
begin
  raise EAdapterFieldException.Create(sActionExecutionNotPermitted, AFieldName);
end;

procedure RaiseFieldViewNotPermitted(const AFieldName: string);
begin
  raise EAdapterFieldException.Create(sFieldViewNotPermitted, AFieldName);
end;

procedure RaiseAdapterModificationNotPermitted;
begin
  raise EAdapterException.Create(sAdapterModificationNotPermitted);
end;

procedure RaiseRequiredValueException(AFieldName: string);
begin
  raise EAdapterFieldException.Create(sFieldRequiresAValue, AFieldName);
end;

procedure RaiseMultipleValuesException(AFieldName: string);
begin
  raise EAdapterFieldException.Create(sFieldDoesNotAllowMultipleValues, AFieldName);
end;

procedure RaiseMultipleFilesException(AFieldName: string);
begin
  raise EAdapterFieldException.Create(sFieldDoesNotAllowMultipleFiles, AFieldName);
end;

procedure RaiseRequiredFileException(AFieldName: string);
begin
  raise EAdapterFieldException.Create(sFieldRequiresAFile, AFieldName);
end;

procedure RaiseFileUploadNotSupported(AFieldName: string);
begin
  raise EAdapterFieldException.Create(sFileUploadNotSupported, AFieldName);
end;

procedure RaiseImageNotProvided(AFieldName: string);
begin
  raise EAdapterFieldException.Create(sImageNotProvided, AFieldName);
end;

procedure ValidateSingleValueField(AValue: IActionFieldValue);
begin
  with AValue do
    if ValueCount > 1 then
       RaiseMultipleValuesException(FieldName);
end;

procedure ValidateSingleFileField(AValue: IActionFieldValue);
begin
  with AValue do
    if FileCount > 1 then
       RaiseMultipleFilesException(FieldName);
end;

procedure ValidateSingleFileOrValueField(AValue: IActionFieldValue);
begin
  ValidateSingleFileField(AValue);
  ValidateSingleValueField(AValue);
end;

procedure ValidateRequiredValueField(AValue: IActionFieldValue);
begin
  with AValue do
    if (ValueCount = 0) or VarIsEmpty(Values[0]) or (Values[0] = '') then
       RaiseRequiredValueException(FieldName);
end;

procedure ValidateRequiredFileField(AValue: IActionFieldValue);
begin
  with AValue do
    if FileCount = 0 then
       RaiseRequiredFileException(FieldName);
end;

procedure ValidateRequiredFileOrValueField(AValue: IActionFieldValue);
begin
  with AValue do
    if (FileCount = 0) and  (VarIsEmpty(Values[0]) or (Values[0] = '')) then
       RaiseRequiredValueException(FieldName);
end;

function MakeValidAdapterFieldName(const AFieldName: string): string;
  procedure CrunchFieldName;
  var
    I: Integer;
  begin
    I := 1;
    while I <= Length(Result) do
    begin
      if Result[I] in ['A'..'Z','a'..'z','_','0'..'9'] then
        Inc(I)
      else if Result[I] in LeadBytes then
        Delete(Result, I, 2)
      else
        Delete(Result, I, 1);
    end;
  end;

begin
  Result := AFieldName;
  if Result <> '' then
  begin
    CrunchFieldName;
    if (Result = '') or (Result[1] in ['0'..'9']) then
      Result := '_' + Result;
  end;
end;

function MakeAdapterRequestIdentifier(AComponent: TComponent): string;
begin
  Result := FullyQualifiedName(AComponent, qaNoModulesVar);
end;

procedure TBaseAdapterAction.GetAdapterItemRequestParams(var AIdentifier: string; Params: IAdapterItemRequestParams);
begin
  AIdentifier := MakeAdapterRequestIdentifier(Self);
  ImplGetAdapterItemRequestParams(AIdentifier, Params);
end;

procedure TBaseAdapterAction.ImplGetAdapterItemRequestParams(var AIdentifier: string; Params: IAdapterItemRequestParams);
begin
  if Assigned(Adapter.OnGetActionParams) then
    Adapter.OnGetActionParams(Adapter, Self, Params.ParamValues);
  if Assigned(OnGetParams) then
    OnGetParams(Self, Params.ParamValues);
end;

function FindAdapterInParent(AComponent: TComponent): TComponent;
var
  Intf: IIdentifyAdapter;
begin
  AComponent := AComponent.GetParentComponent;
  while Assigned(AComponent) and
   (not Supports(IInterface(AComponent), IIdentifyAdapter, Intf)) do
   AComponent := AComponent.GetParentComponent;
  Result := AComponent;
end;

{ TCustomAdapter }

function TCustomAdapter.FindNamedField(const AName: string): TComponent;
begin
  Result := Data.FindNamedVariable(AName);
end;

function TCustomAdapter.FindNamedAction(const AName: string): TComponent;
begin
  Result := Actions.FindNamedVariable(AName);
end;

function TCustomAdapter.FindNamedVariable(
  const AName: string): TComponent;
begin
  Result := FindNamedField(AName);
  if not Assigned(Result) then
    Result := FindNamedAction(AName);
end;

function TCustomAdapter.FindVariable(
  const AName: string): TComponent;
begin
  Result := ImplFindVariable(AName);
end;

function TCustomAdapter.ImplFindVariable(
  const AName: string): TComponent;
begin
  Result := FindNamedVariable(AName);
end;

function TCustomAdapter.ImplFindVariableContainer(
  const AName: string): TComponent;
var
  Intf: IUnknown;
begin
  Result := FindNamedVariable(AName);
  if Assigned(Result) and
    not Supports(IInterface(Result), IWebVariablesContainer, Intf) then
    RaiseVariableIsNotAContainer(AName);
end;

function TCustomAdapter.FindVariableContainer(
  const AName: string): TComponent;
begin
  Result := ImplFindVariableContainer(AName);
end;

function TCustomAdapter.GetVariableName: string;
begin
  Result := ImplGetVariableName;
end;

function TCustomAdapter.ImplGetVariableName: string;
begin
  Result := Self.Name;
end;

function TCustomAdapter.GetVariable(I: Integer): TComponent;
begin
  Result := ImplGetVariable(I);
end;

function TCustomAdapter.GetVariableCount: Integer;
begin
  Result := ImplGetVariableCount;
end;

function TCustomAdapter.ImplGetVariable(I: Integer): TComponent;
begin
  if I < Data.VariablesInUse.Count then
    Result := Data.VariablesInUse[I]
  else
    Result := Actions.VariablesInUse[I - Data.VariablesInUse.Count];
end;

function TCustomAdapter.ImplGetVariableCount: Integer;
begin
  Result := Data.VariablesInUse.Count + Actions.VariablesInUse.Count;
end;

function TCustomAdapter.CreateErrorsList: TBaseAdapterErrorsList;
begin
  Result := TAdapterErrorsList.Create(Self);
end;

constructor TCustomAdapter.Create(AOwner: TComponent);
begin
  inherited;
  FInIterator := False;
  FNotifyList := TNotifyList.Create;
  FErrors := CreateErrorsList;
  FErrorsIntf := FErrors; // no need to free FErrors
  FHiddenFields := TAdapterHiddenFieldsList.Create;
  FHiddenRecordFields := TAdapterHiddenFieldsList.Create;
  FHiddenFieldsIntf := FHiddenFields; // no need to free
  FHiddenRecordFieldsIntf := FHiddenRecordFields; // no need to free 
  SetActions(GetActionsClass.Create(AOwner));
  SetData(GetDataClass.Create(AOwner));
end;

procedure TCustomAdapter.WebComponentsChange(Sender: TObject);
begin
  if not (csLoading in ComponentState) then
    NotifyAdapterChange;
end;

procedure TCustomAdapter.NotifyAdapterChange;
var
  I: Integer;
  AdapterChange: INotifyAdapterChange;
begin
  if FNotifyList <> nil then
    for I := 0 to FNotifyList.Count - 1 do
      if Supports(FNotifyList[I], INotifyAdapterChange, AdapterChange) then
        AdapterChange.NotifyAdapterChange(Self);
end;

destructor TCustomAdapter.Destroy;
begin
  inherited;
  FreeAndNil(FNotifyList);
  FData.Free;
  FActions.Free;
end;

procedure TCustomAdapter.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (AComponent = FData) then
    FData := nil;
  if (Operation = opRemove) and (AComponent = FActions) then
    FActions := nil;
end;

procedure TCustomAdapter.ImplSetData(const Value: TAdapterSubComponent);
begin
  if FData <> Value then
    FData.Free;
  FData := Value as TAdapterFields;
  if Assigned(FData) then
  begin
    Value.FreeNotification(Self);
    FData.GetWebComponents.OnChange := WebComponentsChange;
    FData.FParent := Self;
  end;
end;

procedure TCustomAdapter.ImplSetActions(const Value: TAdapterSubComponent);
begin
  if FActions <> Value then
    FActions.Free;
  FActions := Value as TAdapterActions;
  if Assigned(FActions) then
  begin
    Value.FreeNotification(Self);
    FActions.GetWebComponents.OnChange := WebComponentsChange;
    FActions.FParent := Self;
  end;
end;

procedure TCustomAdapter.GetChildren(Proc: TGetChildProc;
  Root: TComponent);
begin
  inherited GetChildren(Proc, Root);
  Proc(Actions);
  Proc(Data);
end;

function TCustomAdapter.GetActionsClass: TAdapterActionsClass;
begin
  Result := TAdapterActions;
end;

function TCustomAdapter.GetDataClass: TAdapterFieldsClass;
begin
  Result := TAdapterFields;
end;

function TCustomAdapter.GetAdapterErrors: TObject;
begin
  Result := FErrors;
end;

procedure TCustomAdapter.ImplNotifyDeactivate;
begin
  ClearErrors;
  ClearAdapterValues;
  FIteratorIndex := 0;
  FInIterator := False;
end;

procedure TCustomAdapter.ImplNotifyActivate;
begin
  // Do nothing
end;

procedure TCustomAdapter.NotifyDeactivate;
begin
  ImplNotifyDeactivate;
end;

procedure TCustomAdapter.NotifyActivate;
begin
  ImplNotifyActivate;
end;

procedure TCustomAdapter.ClearErrors;
begin
  FErrorsIntf.ClearErrors;
end;

procedure TCustomAdapter.ImplClearAdapterValues;
begin
  ImplSetEchoActionFieldValues(False);
end;

procedure TCustomAdapter.ImplSetEchoActionFieldValues(AValue: Boolean);
var
  I: Integer;
  ComponentList: TWebComponentList;
  Component: TComponent;
  EchoActionFieldValue: IEchoActionFieldValue;
begin
  FEchoActionFieldValues := AValue;
  if not AValue then
    ComponentList := Data.GetWebComponents
  else
    ComponentList := GetVisibleFields;
  for I := 0 to ComponentList.Count - 1 do
  begin
    Component := ComponentList.WebComponents[I];
    if Supports(IUnknown(Component), IEchoActionFieldValue, EchoActionFieldValue) then
      EchoActionFieldValue.EchoActionFieldValue := AValue;
  end;
end;

function TCustomAdapter.ImplGetVisibleFields: TWebComponentList;
begin
  Result := Data.GetWebComponents
end;

function TCustomAdapter.ImplGetVisibleActions: TWebComponentList;
begin
  Result := Actions.GetWebComponents
end;

function TCustomAdapter.GetAdapterErrorsList: TBaseAdapterErrorsList;
begin
  Result := FErrors;
end;

function TCustomAdapter.CanAddActionClass(AParent: TComponent;
  AClass: TClass): Boolean;
begin
  Result := ImplCanAddActionClass(AParent, AClass);
end;

function TCustomAdapter.CanAddFieldClass(AParent: TComponent;
  AClass: TClass): Boolean;
begin
  Result := ImplCanAddFieldClass(AParent, AClass);
end;

function TCustomAdapter.ImplCanAddActionClass(AParent: TComponent;
  AClass: TClass): Boolean;
begin
  Result := False;
end;

function TCustomAdapter.ImplCanAddFieldClass(AParent: TComponent;
  AClass: TClass): Boolean;
begin
  Result := False;
end;

function TCustomAdapter.GetScriptObject: IDispatch;
begin
  Result := ImplGetScriptObject;
end;

function TCustomAdapter.ImplGetScriptObject: IDispatch;
begin
  Result := TAdapterWrapper.Create(Self);
end;

function TCustomAdapter.GetAdapterActions: TComponent;
begin
  Result := FActions;
end;

function TCustomAdapter.GetAdapterFields: TComponent;
begin
  Result := FData;
end;

procedure TCustomAdapter.EndIterator(OwnerData: Pointer);
begin
  ImplEndIterator(OwnerData);
end;

procedure TCustomAdapter.ImplEndIterator(OwnerData: Pointer);
var
  Temp: Boolean;
begin
  try
    try
      Temp := False;
      if Assigned(OnIterateRecords) then
        OnIterateRecords(Self, itEnd, Temp);
    except
      on E:Exception do
        Errors.AddError(E);
    end;
  finally
    FIteratorIndex := 0;
    FInIterator := False;
  end;
end;

function TCustomAdapter.NextIteration(
  var OwnerData: Pointer): Boolean;
begin
  Result := ImplNextIteration(OwnerData);
end;

function TCustomAdapter.ImplNextIteration(
  var OwnerData: Pointer): Boolean;
begin
  if Assigned(OnIterateRecords) then
  try
    Result := False;
    OnIterateRecords(Self, itNext, Result);
    Result := not Result;
    if Result then
      Inc(FIteratorIndex);
  except
    on E:Exception do
      Errors.AddError(E);
  end
  else
    Result := False;
end;

function TCustomAdapter.StartIterator(
  var OwnerData: Pointer): Boolean;
begin
  Result := ImplStartIterator(OwnerData);
end;

function TCustomAdapter.ImplStartIterator(
  var OwnerData: Pointer): Boolean;
begin
  if Assigned(OnIterateRecords) then
  try
    Result := False;
    OnIterateRecords(Self, itStart, Result);
    Result := not Result;
    if Result then
    begin
      FInIterator := True;
      FIteratorIndex := 0;
    end;
  except
    on E:Exception do
      Errors.AddError(E);
  end
  else
    Result := False;
end;

procedure TCustomAdapter.ClearAdapterValues;
begin
  ImplClearAdapterValues;
end;

procedure TCustomAdapter.SetActions(
  const Value: TAdapterSubComponent);
begin
  ImplSetActions(Value);
end;

procedure TCustomAdapter.SetData(const Value: TAdapterSubComponent);
begin
  ImplSetData(Value);
end;

function TCustomAdapter.GetEchoActionFieldValues: Boolean;
begin
  Result := ImplGetEchoActionFieldValues;
end;

function TCustomAdapter.ImplGetEchoActionFieldValues: Boolean;
begin
  Result := FEchoActionFieldValues;
end;

procedure TCustomAdapter.SetEchoActionFieldValues(AValue: Boolean);
begin
  ImplSetEchoActionFieldValues(AValue);
end;

function TCustomAdapter.UpdateFieldsGetAnyChanges(AActionRequest: IActionRequest; AAdapterFields: TObjectList): Boolean;
var
  I: Integer;
  CheckValueChange: ICheckValueChange;
begin
  Result := False;
  for I := 0 to AAdapterFields.Count - 1 do
    try
      if Supports(AAdapterFields[I], ICheckValueChange, CheckValueChange) then
      begin
        if CheckValueChange.CheckValueChange(AActionRequest, I) then
          Result := True;
      end
      else if AAdapterFields[I] <> nil then
        Result := True;
      if Result then Break;
    except
      on E: Exception do
        Errors.AddError(E);
    end;
end;

function TCustomAdapter.UpdateRecordsGetAnyChanges(AActionRequest: IActionRequest; AAdapterFields: TObjectList): Boolean;
var
  Enum: IEnumActionFieldValueRecords;
begin
  Result := False;
  if Supports(AActionRequest, IEnumActionFieldValueRecords, Enum) then
  begin
    Enum.GetFirstRecord;
    try
      while not Enum.EOF do
      begin
        // Update list to contain fields of current request record
        ListAdapterUpdateFields(AActionRequest, AAdapterFields);
        Result := UpdateFieldsGetAnyChanges(AActionRequest, AAdapterFields);
        if Result then
          break;
        Enum.GetNextRecord;
      end;
    finally
      Enum.EndIterator;
    end;
  end
  else
    Result := UpdateFieldsGetAnyChanges(AActionRequest, AAdapterFields);
end;

procedure TCustomAdapter.UpdateFieldsValidateValues(AActionRequest: IActionRequest; AAdapterFields: TObjectList);
var
  Handled: Boolean;
  I: Integer;
  ValidateValue: IValidateValue;
begin
  Handled := False;
  if Assigned(OnBeforeValidateFields) then
    OnBeforeValidateFields(Self, AActionRequest, AAdapterFields, Handled);
  if not Handled then
    try
      for I := 0 to AAdapterFields.Count - 1 do
        try
          if Supports(AAdapterFields[I], IValidateValue, ValidateValue) then
            ValidateValue.ValidateValue(AActionRequest, I);
        except
          on E: Exception do
            Errors.AddError(E, AAdapterFields[I]);
        end;
    finally
      if Assigned(OnAfterValidateFields) then
       OnAfterValidateFields(Self, AActionRequest, AAdapterFields)
    end;
end;

procedure TCustomAdapter.UpdateRecordsValidateValues(AActionRequest: IActionRequest; AAdapterFields: TObjectList);
var
  Enum: IEnumActionFieldValueRecords;
begin
  if Supports(AActionRequest, IEnumActionFieldValueRecords, Enum) then
  begin
    Enum.GetFirstRecord;
    try
      while not Enum.EOF do
      begin
        // Update list to contain fields of current request record
        ListAdapterUpdateFields(AActionRequest, AAdapterFields);
        UpdateFieldsValidateValues(AActionRequest, AAdapterFields);
        Enum.GetNextRecord;
      end;
    finally
      Enum.EndIterator;
    end;
  end
  else
    UpdateFieldsValidateValues(AActionRequest, AAdapterFields);
end;

procedure TCustomAdapter.UpdateFieldsExecuteValues(AActionRequest: IActionRequest; AAdapterFields: TObjectList);
var
  I: Integer;
  ExecuteValue: IExecuteValue;
begin
  for I := 0 to AAdapterFields.Count - 1 do
    try
      if Supports(AAdapterFields[I], IExecuteValue, ExecuteValue) then
        ExecuteValue.ExecuteValue(AActionRequest, I);
    except
      on E: Exception do
        Errors.AddError(E, AAdapterFields[I]);
    end;
end;

procedure TCustomAdapter.UpdateFieldsUpdateValues(AActionRequest: IActionRequest; AAdapterFields: TObjectList);
var
  Handled: Boolean;
  I: Integer;
  UpdateValue: IUpdateValue;
begin
  Handled := False;
  if Assigned(OnBeforeUpdateFields) then
    OnBeforeUpdateFields(Self, AActionRequest, AAdapterFields, Handled);
  if not Handled then
    try
      for I := 0 to AAdapterFields.Count - 1 do
        try
          if Supports(AAdapterFields[I], IUpdateValue, UpdateValue) then
            UpdateValue.UpdateValue(AActionRequest, I);
        except
          on E: Exception do
            Errors.AddError(E, AAdapterFields[I]);
        end;
    finally
      if Assigned(OnAfterUpdateFields) then
        OnAfterUpdateFields(Self, AActionRequest, AAdapterFields)
    end;
end;

procedure TCustomAdapter.UpdateRecordsUpdateValues(AActionRequest: IActionRequest; AAdapterFields: TObjectList);
var
  Enum: IEnumActionFieldValueRecords;
begin
  if Supports(AActionRequest, IEnumActionFieldValueRecords, Enum) then
  begin
    Enum.GetFirstRecord;
    try
      while not Enum.EOF do
      begin
        // Update list to contain fields of current request record
        ListAdapterUpdateFields(AActionRequest, AAdapterFields);
        UpdateFieldsExecuteValues(AActionRequest, AAdapterFields);
        UpdateFieldsUpdateValues(AActionRequest, AAdapterFields);
        Enum.GetNextRecord;
      end;
    finally
      Enum.EndIterator;
    end;
  end
  else
  begin
    UpdateFieldsExecuteValues(AActionRequest, AAdapterFields);
    UpdateFieldsUpdateValues(AActionRequest, AAdapterFields);
  end;
end;

function GetActionFieldValues(AActionRequest: IActionRequest): IActionFieldValues;
begin
  if not Supports(AActionRequest, IActionFieldValues, Result) then
    Assert(False);
end;

procedure TCustomAdapter.ListAdapterUpdateFields(AActionRequest: IActionRequest; AList: TObjectList);
var
  AdapterField: TComponent;
  I: Integer;
  ComponentList: TWebComponentList;
  Component: TComponent;
  Attributes: IAdapterFieldAttributes;
  VarName: IWebVariableName;
begin
  AList.Clear;
  with GetActionFieldValues(AActionRequest) do
    for I := 0 to FieldCount - 1 do
    begin
      AdapterField := Self.FindField(FieldNames[I]);
      AList.Add(AdapterField);  // may be null
    end;

  // Add required fields
  ComponentList := GetVisibleFields;
  for I := 0 to ComponentList.Count - 1 do
  begin
    Component := ComponentList.WebComponents[I];
    if AList.IndexOf(Component) = -1 then
      if Supports(IUnknown(Component), IAdapterFieldAttributes, Attributes)
      and Attributes.Required then
      begin
        if Supports(Component, IWebVariableName, VarName) then
        begin
          GetActionFieldValues(AActionRequest).AddValue(VarName.VariableName);
          AList.Add(Component);
        end;
      end;
  end;
end;

function TCustomAdapter.UpdateRecords(AActionRequest: IActionRequest): Boolean;
var
  AdapterFields: TObjectList;
  AnyChanges: Boolean;
begin
  if AActionRequest = nil then
    if (WebContext.AdapterRequest <> nil) then
      Supports(WebContext.AdapterRequest, IActionRequest, AActionRequest);
  if AActionRequest <> nil then
  try
    AdapterFields := TObjectList.Create(False { not owned});
    try
      CheckModifyAccess;
      ListAdapterUpdateFields(AActionRequest, AdapterFields);
      AnyChanges := UpdateRecordsGetAnyChanges(AActionRequest, AdapterFields);
      if AnyChanges and (Errors.ErrorCount = 0) then
        UpdateRecordsValidateValues(AActionRequest, AdapterFields);
      if AnyChanges and (Errors.ErrorCount = 0) then
        UpdateRecordsUpdateValues(AActionRequest, AdapterFields);
    finally
      AdapterFields.Free;
    end;
  except
    on E: Exception do
      Errors.AddError(E);
  end;
  Result := Errors.ErrorCount = 0;
end;

function TCustomAdapter.HasModifyAccess: Boolean;
begin
  Result := ImplHasModifyAccess;
end;

function TCustomAdapter.HasViewAccess: Boolean;
begin
  Result := ImplHasViewAccess;
end;

function TCustomAdapter.ImplHasModifyAccess: Boolean;
begin
  Result := True;
  if ModifyAccess <> '' then
    if WebContext <> nil then
      if WebContext.EndUser <> nil then
        Result := WebContext.EndUser.HasModifyRights(ModifyAccess)
end;

function TCustomAdapter.ImplHasViewAccess: Boolean;
begin
  Result := True;
  if ViewAccess <> '' then
    if WebContext <> nil then
      if WebContext.EndUser <> nil then
        Result := WebContext.EndUser.HasViewRights(ViewAccess)
end;

procedure TCustomAdapter.CheckModifyAccess;
begin
  if not HasModifyAccess then
    RaiseAdapterModificationNotPermitted;
end;

function TCustomAdapter.HasExecuteAccess: Boolean;
begin
  Result := ImplHasExecuteAccess;
end;

function TCustomAdapter.ImplHasExecuteAccess: Boolean;
begin
  Result := True;
  if ExecuteAccess <> '' then
    if WebContext <> nil then
      if WebContext.EndUser <> nil then
        Result := WebContext.EndUser.HasExecuteRights(ExecuteAccess)
end;

function TCustomAdapter.GetAdapterHiddenFields: TObject;
begin
  FHiddenFields.Clear;
  ListHiddenFields(FHiddenFields);
  Result := FHiddenFields;
end;

procedure TCustomAdapter.AddOrigValueHiddenFields(AHiddenFields: TAdapterHiddenFieldsList);
  function AsEditText(const Value: Variant): string;
  begin
    if (not VarIsEmpty(Value)) and (not VarIsNull(Value)) then
      Result := HTMLEncode(Value)
    else
      Result := '';
  end;
var
  I: Integer;
  ComponentList: TWebComponentList;
  Component: TComponent;
  Intf: IUnknown;
  PrevValue: IWebGetFieldPrevValue;
  InputName: IWebInputName;
  VarName: IWebVariableName;
  S: string;
begin
  ComponentList := GetVisibleFields;
  for I := 0 to ComponentList.Count - 1 do
  begin
    Component := ComponentList.WebComponents[I];
    if Supports(IUnknown(Component), ICheckOrigValue, Intf) then
       if Supports(IUnknown(Component), IWebGetFieldPrevValue, PrevValue) then
          if PrevValue.NeedPrevValue then
          begin
            if Supports(IUnknown(Component), IWebInputName, InputName) then
              S := InputName.InputName
            else if Supports(IUnknown(Component), IWebVariableName, VarName) then
              S := VarName.VariableName;
            Assert(S <> '');
            AHiddenFields.Add(Format('%s%s', [sDelimOrigFieldValue, S]), AsEditText(PrevValue.PrevValue));
          end;
  end;
end;

procedure TCustomAdapter.AddRecordKeysHiddenFields(AHiddenFields: TAdapterHiddenFieldsList);
var
  Value: string;
  GetRecordKeys: IGetRecordKeys;
  S: TStrings;
  IteratorIndex: IIteratorIndex;
  Qualify: Boolean;
  VarName: string;
begin
  Value := '';
  Qualify := False;
  if Supports(IUnknown(Self), IGetRecordKeys, GetRecordKeys) then
  begin
    S := TStringList.Create;
    try
      GetRecordKeys.GetRecordKeys(S, Qualify);
      Value := EncodeParamNameValues(S);
    finally
      S.Free;
    end;
  end;
  if Value <> '' then
  begin
    if Qualify then
      VarName := GetVariableName + '-'
    else
      VarName := '';
    if Supports(IInterface(Self), IIteratorIndex, IteratorIndex) and IteratorIndex.InIterator then
      AHiddenFields.Add(Format('%s%s.%d', [sDelimRecordKeys, VarName, IteratorIndex.IteratorIndex]),
        Value)
    else
      AHiddenFields.Add(Format('%s%s', [sDelimRecordKeys, VarName]),
        Value)
  end;
end;

procedure TCustomAdapter.AddAdapterModeHiddenField(AHiddenFields: TAdapterHiddenFieldsList);
var
  AdapterMode: IAdapterMode;
begin
  if Supports(IUnknown(Self), IAdapterMode, AdapterMode) then
  begin
    if AdapterMode.NeedAdapterMode then
      AHiddenFields.Add(Format('%s%s', [sDelimAdapterMode, GetVariableName]),
        AdapterMode.AdapterMode);
  end;
end;

procedure TCustomAdapter.ListHiddenFields(AHiddenFields: TAdapterHiddenFieldsList);
var
  O: TAdapterHiddenFieldOptions;
begin
  O := GetHiddenFieldOptions;
  if hoMode in O then
    AddAdapterModeHiddenField(AHiddenFields);
end;

procedure TCustomAdapter.ListHiddenRecordFields(AHiddenFields: TAdapterHiddenFieldsList);
var
  O: TAdapterHiddenFieldOptions;
begin
  O := GetHiddenFieldOptions;
  if hoOrigValues in O then
    AddOrigValueHiddenFields(AHiddenFields);
  if hoRecordKeys in O then
    AddRecordKeysHiddenFields(AHiddenFields);
end;

function TCustomAdapter.GetAdapterHiddenRecordFields: TObject;
begin
  FHiddenRecordFields.Clear;
  ListHiddenRecordFields(FHiddenRecordFields);
  if FHiddenRecordFields.FieldCount > 0 then
    Result := FHiddenRecordFields
  else
    Result := nil;
end;

procedure TCustomAdapter.CreateActionRequestContext(
  DispatchParams: IAdapterDispatchParams);
var
  Obj: TMultiRecordActionRequestImpl;
begin
  Obj := TMultiRecordActionRequestImpl.Create(DispatchParams);
  TBasicActionResponseImpl.Create(
    Obj);
end;

procedure TCustomAdapter.GetActionsList(AList: TStrings);
begin
  ImplGetActionsList(AList);
end;

procedure TCustomAdapter.GetFieldsList(AList: TStrings);
begin
  ImplGetFieldsList(AList);
end;

function TCustomAdapter.GetVisibleActions: TWebComponentList;
begin
  Result := ImplGetVisibleActions;
end;

function TCustomAdapter.GetVisibleFields: TWebComponentList;
begin
  Result := ImplGetVisibleFields;
end;

function TCustomAdapter.FindAction(const AName: string): TComponent;
begin
  Result := WebAdapt.FindAdapterAction(GetVisibleActions, AName);
end;

function TCustomAdapter.FindField(const AName: string): TComponent;
begin
  Result := WebAdapt.FindAdapterField(GetVisibleFields, AName);
end;

procedure TCustomAdapter.ImplGetActionsList(AList: TStrings);
begin
  AList.Clear;
end;

procedure TCustomAdapter.ImplGetFieldsList(AList: TStrings);
begin
  AList.Clear;
end;

function TCustomAdapter.IsActionInUse(const AName: string): Boolean;
begin
  Result := WebAdapt.FindAdapterAction(Actions.GetWebComponents, AName) <> nil;
end;

function TCustomAdapter.IsFieldInUse(const AName: string): Boolean;
begin
  Result := WebAdapt.FindAdapterField(Data.GetWebComponents, AName) <> nil;
end;

function TCustomAdapter.GetHiddenFieldOptions: TAdapterHiddenFieldOptions;
begin
  Result := [hoOrigValues, hoMode, hoRecordKeys];
end;

{ TAdapterUpdateField }

function TAdapterUpdateField.ImplGetVariableName: string;
begin
  if FFieldName = '' then
    Result := inherited ImplGetVariableName
  else
    Result := FFieldName;
end;

constructor TAdapterUpdateField.Create(AOwner: TComponent);
begin
  inherited;
  FDisplayWidth := -1;
end;

function TAdapterUpdateField.ImplGetDisplayLabel: string;
begin
  if FDisplayLabel = '' then
    Result := inherited ImplGetDisplayLabel
  else
    Result := FDisplayLabel;
end;

function TAdapterUpdateField.ImplGetDisplayWidth: Integer;
begin
  Result := FDisplayWidth;
end;

function TAdapterUpdateField.GetAdapterValuesList: IValuesListAdapter;
begin
  Result := FValuesList;
end;

procedure TAdapterUpdateField.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and AComponent.IsImplementorOf(FValuesList) then
    FValuesList := nil;
end;

procedure TAdapterUpdateField.SetValuesList(
  const Value: IValuesListAdapter);
begin
  ReferenceInterface(FValuesList, opRemove);
  FValuesList := Value;
  ReferenceInterface(FValuesList, opInsert);
end;

function TAdapterUpdateField.GetInputStyleType(const AAdapterMode: string): TAdapterInputHTMLElementType;
begin
  if ValuesList <> nil then
    Result := htmliSelect
  else
    Result := htmliTextInput;
end;

function TAdapterUpdateField.ImplGetEchoActionFieldValue: Boolean;
begin
  Result := FEchoActionFieldValue;
end;

procedure TAdapterUpdateField.ImplSetEchoActionFieldValue(
  AValue: Boolean);
begin
  FEchoActionFieldValue := AValue;
end;

function TAdapterUpdateField.ImplAsFormatted: string;
var
  Value: Variant;
begin
  Value := GetValue;
  if Assigned(OnGetDisplayText) then
    OnGetDisplayText(Self, Result)
  else
    if VarIsEmpty(Value) or VarIsNull(Value) then
      Result := ''
    else
      Result := Value;
end;

procedure TAdapterUpdateField.ImplUpdateValue(
  AActionRequest: IActionRequest; AFieldIndex: Integer);
begin
  // Do nothing
end;

procedure TAdapterUpdateField.ImplValidateValue(
  AActionRequest: IActionRequest; AFieldIndex: Integer);
var
  Handled: Boolean;
begin
  with GetActionFieldValues(AActionRequest) do
    DoOnValidateValue(Values[AFieldIndex], Handled);
end;

procedure TAdapterUpdateField.DoOnValidateValue(
  AValue: IActionFieldValue;
  var AHandled: Boolean);
begin
  if Assigned(OnValidateValue) then
    OnValidateValue(Self, AValue,
      AHandled)
  else
    AHandled := False;
end;

procedure TAdapterUpdateField.UpdateValue(
  AActionRequest: IActionRequest; AFieldIndex: Integer);
begin
  ImplUpdateValue(AActionRequest, AFieldIndex);
end;

procedure TAdapterUpdateField.ValidateValue(
  AActionRequest: IActionRequest; AFieldIndex: Integer);
begin
  ImplValidateValue(AActionRequest, AFieldIndex);
end;

function TAdapterUpdateField.CheckValueChange(
  AActionRequest: IActionRequest; AFieldIndex: Integer): Boolean;
begin
  Result := ImplCheckValueChange(AActionRequest, AFieldIndex);
end;

function TAdapterUpdateField.ImplCheckValueChange(
  AActionRequest: IActionRequest; AFieldIndex: Integer): Boolean;
var
  FieldValue: IActionFieldValue;
  I: Integer;
  Value: Variant;
begin
  // Test single value
  with GetActionFieldValues(AActionRequest) do
    FieldValue := Values[AFieldIndex];
  if GetValueCount = ConvertValueCount(FieldValue) then
  begin
    Result := False;
    if IsMultiValueField then
      for I := 0 to FieldValue.ValueCount do
      begin
        try
          if ConvertValues(FieldValue, I) <> GetValues(I) then
            Result := True;
        except
          Result := True;
        end;
        if Result then break;
      end
    else
      Value := GetValue;
      if VarIsEmpty(Value) then
      begin
        if ConvertValue(FieldValue) <> '' then
          Result := True
      end
      else
        try
          if ConvertValue(FieldValue) <> Value then
            Result := True;
        except
          Result := True;
        end;
  end
  else
    Result := False;
end;

// Convert Variant type to appropriate type for field
function TAdapterUpdateField.ConvertValues(AValue: IActionFieldValue; Index: Integer): Variant;
begin
  Result := AValue.Values[Index];
end;

function TAdapterUpdateField.ConvertValueCount(
  AValue: IActionFieldValue): Integer;
begin
  Result := 1;
end;

function TAdapterUpdateField.ConvertValue(AValue: IActionFieldValue): Variant;
begin
  Result := AValue.Values[0];
end;

function TAdapterUpdateField.IsMultiValueField: Boolean;
begin
  Result := False;
end;

function TAdapterUpdateField.GetValueCount: Integer;
begin
  Result := 1;
end;

function TAdapterUpdateField.GetValues(I: Integer): Variant;
begin
  Result := GetValue;
end;

{ TAdapterNamedField }

function TAdapterNamedField.GetVariableName: string;
begin
  Result := ImplGetVariableName;
end;

function TAdapterNamedField.GetInputName: string;
begin
  Result := ImplGetInputName;
end;

function TAdapterNamedField.FullyQualifyInputName: Boolean;
var
  Intf: IFullyQualifyInputNames;
begin
  if Supports(Adapter, IFullyQualifyInputNames, Intf) then
    Result := Intf.FullyQualifyInputNames
  else
    Result := False;
end;

function TAdapterNamedField.ImplGetInputName: string;
var
  Intf: IIteratorIndex;
  Index: Integer;
  S: String;
  VarNameIntf: IWebVariableName;
begin
  if Supports(IInterface(Adapter), IIteratorIndex, Intf) and Intf.InIterator then
    Index := Intf.IteratorIndex
  else
    Index := -1;
  S := GetVariableName;
  if FullyQualifyInputName then
    if Supports(IInterface(Adapter), IWebVariableName, VarNameIntf) then
      S := Format('%s-%s', [VarNameIntf.VariableName, S]);
  if Index <> -1 then
    Result := Format('%s.%d', [S, Index])
  else
    Result := S;
end;

function TAdapterNamedField.GetValue: Variant;
begin
  Result := ImplGetValue;
end;

function TAdapterNamedField.ImplGetValue: Variant;
begin
  Result := Unassigned;
end;

function TAdapterNamedField.AsFormatted: string;
begin
  Result := ImplAsFormatted;
end;

function TAdapterNamedField.ImplAsFormatted: string;
begin
  Result := ImplGetValue;
end;

procedure TAdapterUpdateField.ImplSetFieldName(const Value: string);
begin
  if Value = GetDefaultFieldName then
    FFieldName := ''
  else
    FFieldName := Value;
end;

procedure TAdapterNamedField.SetFieldName(const AName: string);
begin
  ImplSetFieldName(AName);
end;

function TAdapterNamedField.GetDisplayLabel: string;
begin
  Result := ImplGetDisplayLabel;
end;

function TAdapterNamedField.GetDisplayWidth: Integer;
begin
  Result := ImplGetDisplayWidth;
end;

function TAdapterNamedField.GetDefaultDisplayLabel: string;
begin
  Result := GetVariableName;
end;

function TAdapterNamedField.ImplGetDisplayLabel: string;
begin
  Result := GetDefaultDisplayLabel;
end;

function TAdapterNamedField.ImplGetDisplayWidth: Integer;
begin
  Result := -1;
end;

function TAdapterNamedField.GetMaxLength: Integer;
begin
  Result := ImplGetMaxLength;
end;

function TAdapterNamedField.ImplGetMaxLength: Integer;
begin
  Result := -1;
end;

function TAdapterNamedField.GetAdapter: TComponent;
begin
  if FAdapter = nil then
    FAdapter := FindAdapterInParent(Self);
  Result := FAdapter;
end;

procedure TAdapterNamedField.ParentChanged;
begin
  inherited;
  FAdapter := nil;
end;

function TAdapterNamedField.GetDefaultFieldName: string;
begin
  Result := Self.Name;
end;

function TAdapterNamedField.GetScriptObject: IDispatch;
begin
  Result := ImplGetScriptObject;
end;

function TAdapterNamedField.ImplGetScriptObject: IDispatch;
begin
  Result := TAdapterFieldWrapper.Create(Self);
end;

function TAdapterNamedField.HasModifyAccess: Boolean;
begin
  Result := ImplHasModifyAccess;
end;

function TAdapterNamedField.HasViewAccess: Boolean;
begin
  Result := ImplHasViewAccess;
end;

function TAdapterNamedField.ImplHasModifyAccess: Boolean;
var
  AdapterAccess: IAdapterAccess;
begin
  if Supports(IUnknown(Adapter), IAdapterAccess, AdapterAccess) then
    Result := AdapterAccess.HasModifyAccess
  else
    Result := True;
  if Result then
    if ModifyAccess <> '' then
      if WebContext <> nil then
        if WebContext.EndUser <> nil then
          Result := WebContext.EndUser.HasModifyRights(ModifyAccess);
end;

function TAdapterNamedField.ImplHasViewAccess: Boolean;
var
  AdapterAccess: IAdapterAccess;
begin
  if Supports(IUnknown(Adapter), IAdapterAccess, AdapterAccess) then
    Result := AdapterAccess.HasViewAccess
  else
    Result := True;
  if Result then
    if ViewAccess <> '' then
      if WebContext <> nil then
        if WebContext.EndUser <> nil then
          Result := WebContext.EndUser.HasViewRights(ViewAccess);
end;

function TAdapterNamedField.GetActionOrigValue: IActionFieldValue;
var
  ActionRequest: IActionRequest;
begin
  if Supports(WebContext.AdapterRequest, IActionRequest, ActionRequest) then
    with GetActionFieldValues(ActionRequest) do
      Result := OrigValueOfField(FieldName);
end;

function TAdapterNamedField.GetActionValue: IActionFieldValue;
var
  ActionRequest: IActionRequest;
  IteratorIndex: IIteratorIndex;
  Enum: IEnumActionFieldValueRecords;
  Locate: IActionFieldValuesOfAdapter;
begin
  Result := nil;
  if Supports(WebContext.AdapterRequest, IActionRequest, ActionRequest) then
  begin
    if Supports(ActionRequest, IActionFieldValuesOfAdapter, Locate) then
      Locate.LocateActionFieldValuesOfAdapter(Adapter);
    if Supports(IInterface(Adapter), IIteratorIndex, IteratorIndex) and
      Supports(ActionRequest, IEnumActionFieldValueRecords, Enum) then
      if IteratorIndex.InIterator then
      begin
        if not Enum.GetRecord(IteratorIndex.IteratorIndex) then
        begin
          Result := nil;
          Exit;
        end;
      end
      else if (Enum.GetRecordCount > 0) and
        not (Enum.InIterator) then
      begin
        if not Enum.FindPopulatedRecord then
        begin
          Result := nil;
          Exit;
        end;
      end;

    if Result = nil then
      with GetActionFieldValues(ActionRequest) do
        Result := ValueOfField(FieldName);
  end;
end;

function TAdapterNamedField.GetEchoActionFieldValue: Boolean;
begin
  Result := ImplGetEchoActionFieldValue;
end;

function TAdapterNamedField.ImplGetEchoActionFieldValue: Boolean;
begin
  Result := False;
end;

procedure TAdapterNamedField.ImplSetEchoActionFieldValue(
  AValue: Boolean);
begin
  // Do nothing
end;

procedure TAdapterNamedField.SetEchoActionFieldValue(AValue: Boolean);
begin
  ImplSetEchoActionFieldValue(AValue);
end;

procedure TAdapterNamedField.CheckModifyAccess;
var
  Intf: IAdapterFieldAccess;
begin
  if Supports(IUnknown(Self), IAdapterFieldAccess, Intf) then
    if not Intf.HasModifyAccess then
      RaiseFieldModificationNotPermitted(FieldName);
end;

procedure TAdapterNamedField.CheckViewAccess;
var
  Intf: IAdapterFieldAccess;
begin
  if Supports(IUnknown(Self), IAdapterFieldAccess, Intf) then
    if not Intf.HasViewAccess then
      RaiseFieldViewNotPermitted(FieldName);
end;

function TAdapterNamedField.GetRequired: Boolean;
begin
  Result := ImplGetRequired;
end;

function TAdapterNamedField.GetVisible: Boolean;
begin
  Result := ImplGetVisible;
end;

function TAdapterNamedField.ImplGetRequired: Boolean;
begin
  Result := False;
end;

function TAdapterNamedField.ImplGetVisible: Boolean;
begin
  Result := True;
end;

function TAdapterNamedField.ImplGetVariableName: string;
begin
  if FFieldName <> '' then
    Result := FFieldName
  else
    Result := GetDefaultFieldName;
end;

procedure TAdapterNamedField.ImplSetFieldName(
  const Value: string);
begin
  if Value = GetDefaultFieldName then
    FFieldName := ''
  else
    FFieldName := Value;
end;

const
  sLoginNextPage = 'NextPage';    // Do not localize
  sLoginAction = 'Login';         // Do not localize
  sLogoutAction = 'Logout';       // Do not localize
  sLoginFormAction = 'LoginForm'; // Do not localize

  sEndUserDisplayName = 'DisplayName'; // Do not localize
  sEndUserLoggedIn = 'LoggedIn';      // Do not localize
  sEndUserLoginFormAction = 'LoginForm';// Do not localize
  sEndUserLogoutAction = 'Logout';    // Do not localize

  sApplicationTitle = 'Title';       // Do not localize

procedure AddDefaultFields(AList: TStrings; AComponents: TWebComponentList);
var
  WebComponent: IWebComponent;
  SetName: IWebSetFieldName;
  FieldControl: TComponent;
  FieldClass: TComponentClass;
  I: integer;
begin
  for I := 0 to AList.Count - 1 do
  begin
    FieldClass := TComponentClass(AList.Objects[I]);
    FieldControl := FieldClass.Create(nil);  // not owned
    FieldControl.GetInterface(IWebComponent, WebComponent);
    WebComponent.Container := AComponents;
    if Supports(IInterface(FieldControl), IWebSetFieldName, SetName) then
       SetName.SetFieldName(AList[I]);
  end;
end;

procedure AddDefaultActions(AList: TStrings; AComponents: TWebComponentList);
var
  WebComponent: IWebComponent;
  SetName: IWebSetActionName;
  FieldControl: TComponent;
  FieldClass: TComponentClass;
  I: integer;
begin
  for I := 0 to AList.Count - 1 do
  begin
    FieldClass := TComponentClass(AList.Objects[I]);
    FieldControl := FieldClass.Create(nil);  // not owned
    Supports(IInterface(FieldControl), IWebComponent, WebComponent);
    WebComponent.Container := AComponents;
    if Supports(IInterface(FieldControl), IWebSetActionName, SetName) then
       SetName.SetActionName(AList[I]);
  end;
end;

function FindAdapterField(AWebComponents: TWebComponentList; const AName: string): TComponent;
var
  I: Integer;
  DataField: IWebGetFieldName;
begin
  for I := 0 to AWebComponents.Count - 1 do
  begin
    if Supports(IInterface(AWebComponents.WebComponents[I]), IWebGetFieldName, DataField) then
    begin
      Result := AWebComponents.WebComponents[I];
      if SameText(DataField.FieldName, AName) then Exit;
    end;
  end;
  Result := nil;
end;

function FindAdapterAction(AWebComponents: TWebComponentList; const AName: string): TComponent;
var
  I: Integer;
  ActionName: IWebGetActionName;
begin
  for I := 0 to AWebComponents.Count - 1 do
  begin
    if Supports(IInterface(AWebComponents.WebComponents[I]), IWebGetActionName, ActionName) then
    begin
      Result := AWebComponents.WebComponents[I];
      if SameText(ActionName.ActionName, AName) then Exit;
    end;
  end;
  Result := nil;
end;

{ TBaseAdapterAction }
procedure TBaseAdapterAction.ExecuteActionRequest(AActionRequest: IActionRequest;
  AActionResponse: IActionResponse);
begin
  if not AActionRequest.Handled then
  begin
    CheckExecuteAccess;
    DoBeforeExecuteActionRequest(AActionRequest, AActionResponse);
    if not AActionRequest.Handled then
      try
        try
          ImplExecuteActionRequest(AActionRequest, AActionResponse);
        except
          raise;
        end;
      finally
        DoAfterExecuteActionRequest(AActionRequest, AActionResponse);
      end;
  end;
end;

function GetActionHandleResponse(AActionResponse: IActionResponse): IActionHandleResponse;
begin
  if not Supports(AActionResponse, IActionHandleResponse, Result) then
    Assert(False);
end;

procedure TBaseAdapterAction.GetExecuteActionResponse(AActionRequest: IActionRequest;
  AActionResponse: IActionResponse);
begin
  if not AActionResponse.Handled then
  begin
    DoBeforeGetExecuteActionResponse(AActionRequest, AActionResponse);
    if not AActionResponse.Handled then
    try
      ImplGetExecuteActionResponse(AActionRequest, AActionResponse);
      if not AActionResponse.Handled then
        with GetActionHandleResponse(AActionResponse) do
          HandleResponse;
    finally
      DoAfterGetExecuteActionResponse(AActionRequest, AActionResponse);
    end;
  end;
end;

function TBaseAdapterAction.IsDisplayLabelStored: Boolean;
begin
  Result := FDisplayLabel <> '';
end;

function GetActionRespondWith(AActionResponse: IActionResponse): IActionRespondWith;
begin
  if not Supports(AActionResponse, IActionRespondWith, Result) then
    Assert(False);
end;

procedure TBaseAdapterAction.ImplGetExecuteActionResponse(AActionRequest: IActionRequest;
  AActionResponse: IActionResponse);
begin
  if WebContext.Response.Content <> '' then
    AActionResponse.Handled := True
  else
  begin
    if Errors.ErrorCount > 0 then
      AActionResponse.ExecuteStatus := esFail
    else
      AActionResponse.ExecuteStatus := esSuccess;
    with GetActionRespondWith(AActionResponse) do
      if RespondWith = rwUndefined then
        RespondWithComponentPage(Self);
  end;
end;

procedure TBaseAdapterAction.ImplExecuteActionRequest(AActionRequest: IActionRequest;
  AActionResponse: IActionResponse);
begin
  Assert(False) //  ExecuteActionRequest not implemented
end;

function TBaseAdapterAction.GetActionName: string;
begin
  Result := ImplGetActionName;
end;

function TBaseAdapterAction.ImplGetActionName: string;
begin
  Result := GetDefaultActionName;
end;

function TBaseAdapterAction.WebEnabled: Boolean;
begin
  Result := ImplWebEnabled;
end;

function TBaseAdapterAction.ImplWebEnabled: Boolean;
begin
  Result := True;
end;

function TBaseAdapterAction.GetVariableName: string;
begin
  Result := ImplGetVariableName
end;

function TBaseAdapterAction.ImplGetVariableName: string;
begin
  Result := GetActionName;
end;

function TBaseAdapterAction.GetErrors: TBaseAdapterErrorsList;
var
  GetAdapterErrors: IGetAdapterErrorsList;
begin
  if (Adapter <> nil) and
    Supports(IUnknown(Adapter), IGetAdapterErrorsList, GetAdapterErrors) then
    Result := GetAdapterErrors.GetAdapterErrorsList
  else
    Result := nil;
end;

function TBaseAdapterAction.GetAdapter: TCustomAdapter;
begin
  if FAdapter = nil then
    FAdapter := FindAdapterInParent(Self);
  Result := FAdapter as TCustomAdapter;
end;

procedure TBaseAdapterAction.ParentChanged;
begin
  inherited;
  FAdapter := nil;
end;

function TBaseAdapterAction.GetDisplayLabel: string;
begin
  Result := ImplGetDisplayLabel;
end;

function TBaseAdapterAction.ImplGetDisplayLabel: string;
begin
  if FDisplayLabel = '' then
    Result := ActionName
  else
    Result := FDisplayLabel;
end;

procedure TBaseAdapterAction.SetDisplayLabel(const Value: string);
begin
  if Value = GetDefaultDisplayLabel then
    FDisplayLabel := ''
  else
    FDisplayLabel := Value;
end;

function TBaseAdapterAction.GetDefaultDisplayLabel: string;
begin
  Result := ActionName;
end;

function TBaseAdapterAction.GetDefaultActionName: string;
begin
  Result := Name;
end;

function TBaseAdapterAction.GetScriptObject: IDispatch;
begin
  Result := ImplGetScriptObject;
end;

function TBaseAdapterAction.ImplGetScriptObject: IDispatch;
begin
  Result := TAdapterActionWrapper.Create(Self);
end;

function TBaseAdapterAction.HasExecuteAccess: Boolean;
begin
  Result := ImplHasExecuteAccess;
end;

function TBaseAdapterAction.ImplHasExecuteAccess: Boolean;
var
  Intf: IAdapterAccess;
begin
  if Supports(IUnknown(Adapter), IAdapterAccess, Intf) then
    Result := Intf.HasExecuteAccess
  else
    Result := True;
  if Result then
    if ExecuteAccess <> '' then
      if WebContext <> nil then
        if WebContext.EndUser <> nil then
          Result := WebContext.EndUser.HasExecuteRights(ExecuteAccess);
end;

procedure TBaseAdapterAction.CheckExecuteAccess;
begin
  if not HasExecuteAccess then
    RaiseActionExecutionNotPermitted(ActionName);
end;

procedure TBaseAdapterAction.CreateRequestContext(
  DispatchParams: IAdapterDispatchParams);
begin
  ImplCreateRequestContext(DispatchParams);
end;

function TBaseAdapterAction.HandleRequest(
  DispatchParams: IAdapterDispatchParams): Boolean;
begin
  Result := ImplHandleRequest(DispatchParams);
end;

procedure TBaseAdapterAction.ImplCreateRequestContext(
  DispatchParams: IAdapterDispatchParams);
var
  Handler: ICreateActionRequestContext;
begin
  if Supports(IUnknown(Adapter), ICreateActionRequestContext, Handler) then
    Handler.CreateActionRequestContext(DispatchParams)
  else
  begin
    Assert(False);
  end;
end;

function TBaseAdapterAction.ImplHandleRequest(
  DispatchParams: IAdapterDispatchParams): Boolean;
var
  ActionRequest: IActionRequest;
  ActionResponse: IActionResponse;
begin
  Result := Supports(WebContext.AdapterRequest, IActionRequest, ActionRequest) and
    Supports(WebContext.AdapterResponse, IActionResponse, ActionResponse);
  Assert(Result);
  ExecuteActionRequest(ActionRequest, ActionResponse);
  GetExecuteActionResponse(ActionRequest, ActionResponse);
end;

function GetAdapterRequestParamsIntf(AAdapterRequest: IUnknown): IAdapterRequestParams;
begin
  if not Supports(AAdapterRequest, IAdapterRequestParams, Result) then
    Assert(False);
end;

procedure TBaseAdapterAction.DoAfterExecuteActionRequest(
  AActionRequest: IActionRequest; AActionResponse: IActionResponse);
var
  S: TStrings;
begin
  if Assigned(OnAfterExecute) or Assigned(Adapter.OnAfterExecuteAction) then
  begin
    S := AdapterRequestParamsAsStrings(AActionRequest);
    try
      if Assigned(OnAfterExecute) then
        OnAfterExecute(Self, S);
      if Assigned(Adapter.OnAfterExecuteAction) then
        Adapter.OnAfterExecuteAction(Adapter, Self, S);
    finally
      S.Free;
    end;
  end;
end;

procedure TBaseAdapterAction.DoAfterGetExecuteActionResponse(
  AActionRequest: IActionRequest; AActionResponse: IActionResponse);
var
  S: TStrings;
begin
  if Assigned(OnAfterGetResponse) or Assigned(Adapter.OnAfterGetActionResponse) then
  begin
    S := AdapterRequestParamsAsStrings(AActionRequest);
    try
      if Assigned(OnAfterGetResponse) then
        OnAfterGetResponse(Self, S);
      if Assigned(Adapter.OnAfterGetActionResponse) then
        Adapter.OnAfterGetActionResponse(Adapter, Self, S);
    finally
      S.Free;
    end;
  end;
end;

procedure TBaseAdapterAction.DoBeforeExecuteActionRequest(
  AActionRequest: IActionRequest; AActionResponse: IActionResponse);
var
  Handled: Boolean;
  S: TStrings;
begin
  Handled := False;
  if Assigned(OnBeforeExecute) or Assigned(Adapter.OnBeforeExecuteAction) then
  begin
    S := AdapterRequestParamsAsStrings(AActionRequest);
    try
      if Assigned(Adapter.OnBeforeExecuteAction) then
        Adapter.OnBeforeExecuteAction(Adapter, Self, S, Handled);
      if not Handled then
        if Assigned(OnBeforeExecute) then
           OnBeforeExecute(Self, S, Handled);
    finally
      S.Free;
    end;
    if Handled then
      AActionRequest.Handled := True;
  end;
end;

procedure TBaseAdapterAction.DoBeforeGetExecuteActionResponse(
  AActionRequest: IActionRequest; AActionResponse: IActionResponse);
var
  Handled: Boolean;
  S: TStrings;
begin
  Handled := False;
  if Assigned(OnBeforeGetResponse) or Assigned(Adapter.OnBeforeGetActionResponse) then
  begin
    S := AdapterRequestParamsAsStrings(AActionRequest);
    try
      if Assigned(Adapter.OnBeforeGetActionResponse) then
        Adapter.OnBeforeGetActionResponse(Adapter, Self, S, Handled);
      if not Handled then
        if Assigned(OnBeforeGetResponse) then
          OnBeforeGetResponse(Self, S, Handled);
    finally
      S.Free;
    end;
    if Handled then
      AActionResponse.Handled := True;
  end;
end;

function TBaseAdapterAction.GetSuccessOptions: TAdapterActionRedirectOptions;
begin
  Result := ImplGetSuccessOptions;
end;

function TBaseAdapterAction.GetFailureOptions: TAdapterActionRedirectOptions;
begin
  Result := ImplGetFailureOptions;
end;

function TBaseAdapterAction.ImplGetSuccessOptions: TAdapterActionRedirectOptions;
begin
  Result := RedirectOptions;
end;

function TBaseAdapterAction.ImplGetFailureOptions: TAdapterActionRedirectOptions;
begin
  Result := [];
end;

function TBaseAdapterAction.GetDisplayStyle(const AAdapterMode: string): string;
begin
  Result := AdapterActionHTMLElementTypeNames[GetDisplayStyleType(AAdapterMode)]
end;

function TBaseAdapterAction.GetDisplayStyleType(const AAdapterMode: string): TAdapterActionHTMLElementType;
begin
  Result := htmlaButton;
end;

function TBaseAdapterAction.GetInputStyle(const AAdapterMode: string): string;
begin
  Result := GetDisplayStyle(AAdapterMode);
end;

function TBaseAdapterAction.GetViewMode(const AAdapterMode: string): string;
begin
  Result := AdapterDisplayViewModeTypeNames[GetViewModeType(AAdapterMode)]
end;

function TBaseAdapterAction.GetViewModeType(const AAdapterMode: string): TAdapterDisplayViewModeType;
begin
  Result := htmlvmInput
end;

function TBaseAdapterAction.GetVisible: Boolean;
begin
  Result := ImplGetVisible;
end;

function TBaseAdapterAction.ImplGetVisible: Boolean;
begin
  Result := True;
end;

procedure TBaseAdapterAction.EndIterator(OwnerData: Pointer);
begin
  ImplEndIterator(OwnerData);
end;

procedure TBaseAdapterAction.ImplEndIterator(OwnerData: Pointer);
begin
  FIteratorIndex := 0;
  FInIterator := False;
end;

function TBaseAdapterAction.ImplNextIteration(
  var OwnerData: Pointer): Boolean;
begin
  Inc(FIteratorIndex);
  Result := FIteratorIndex < ItemCount;
end;

function TBaseAdapterAction.ImplStartIterator(
  var OwnerData: Pointer): Boolean;
begin
 FIteratorIndex := 0;
 FInIterator := True;
 Result := True;
end;

function TBaseAdapterAction.NextIteration(var OwnerData: Pointer): Boolean;
begin
  Result := ImplNextIteration(OwnerData);
end;

function TBaseAdapterAction.StartIterator(var OwnerData: Pointer): Boolean;
begin
  Result := ImplStartIterator(OwnerData);
end;

function TBaseAdapterAction.GetItemCount: Integer;
begin
  Result := 1;
end;

function TBaseAdapterAction.GetIsAdapterActionList: Boolean;
begin
  Result := ImplGetIsAdapterActionList;
end;

function TBaseAdapterAction.ImplGetIsAdapterActionList: Boolean;
begin
  Result := False;
end;

function TBaseAdapterAction.ImplIsDefaultAction(ADisplay: TObject): Boolean;
begin
  Result := True;
end;

function TBaseAdapterAction.IsDefaultAction(ADisplay: TObject): Boolean;
begin
  Result := ImplIsDefaultAction(ADisplay);
end;

{ TCustomAdapterAction }

procedure TCustomAdapterAction.ImplExecuteActionRequest(AActionRequest: IActionRequest;
  AActionResponse: IActionResponse);
var
  S: TStrings;
begin
  if Assigned(OnExecute) then
  begin
    S := AdapterRequestParamsAsStrings(AActionRequest);
    try
      OnExecute(Self, S);
    finally
      S.Free;
    end;
  end;
end;

function TCustomAdapterAction.ImplGetActionName: string;
begin
  if FActionName = '' then
    Result := inherited ImplGetActionName
  else
    Result := FActionName;
end;

procedure TCustomAdapterAction.ImplGetAdapterItemRequestParams(var AIdentifier: string; Params: IAdapterItemRequestParams);
begin
  inherited ImplGetAdapterItemRequestParams(AIdentifier, Params);
end;

function TCustomAdapterAction.ImplWebEnabled: Boolean;
begin
  Result := True;
  if Assigned(OnGetEnabled) then
    OnGetEnabled(Self, Result);
end;

procedure TCustomAdapterAction.SetActionName(const Value: string);
begin
  ImplSetActionName(Value);
end;

procedure TCustomAdapterAction.ImplSetActionName(const Value: string);
begin
  if Value = GetDefaultActionName then
    FActionName := ''
  else
    FActionName := Value;
end;

function TCustomAdapterAction.ImplGetSuccessOptions: TAdapterActionRedirectOptions;
begin
  Result := FRedirectOptions;
end;

{ TAdapterActions }
const
  sAdapterFieldsNodeName = 'Fields';   // Do not localize
  sAdapterActionsNodeName = 'Actions';  // Do not localize

function TAdapterActions.ImplCanAddClass(AParent: TComponent;
  AClass: TClass): Boolean;
begin
  Result :=
    (AClass.InheritsFrom(TCustomAdapterAction) and not AClass.InheritsFrom(TImplementedAdapterAction)) or
    AdapterCanAddClass(AParent, AClass) or
    CanAddClassHelper(Self, AParent, AClass);
end;

function TAdapterActions.ImplGetWebComponentNodeName: string;
begin
  Result := sAdapterActionsNodeName;
end;

procedure TAdapterActions.SetWebParent(const Value: TComponent);
begin
  if Value <> FParent then
  begin
    if Value <> nil then
    begin
      FParent := Value;
      (FParent as TCustomAdapter).SetActions(Self);
    end
    else
      FParent := nil;
  end;
end;

function TAdapterActions.AdapterCanAddClass(AParent: TComponent;
  AClass: TClass): Boolean;
var
  AdapterEditor: IAdapterEditor;
begin
  if (Adapter = nil) then
    Result := True
  else if Supports(IInterface(Adapter), IAdapterEditor, AdapterEditor) then
    Result := AdapterEditor.CanAddActionClass(AParent, AClass)
  else
    Result := False;
end;

{ TAdapterFields }

function TAdapterFields.ImplCanAddClass(AParent: TComponent;
  AClass: TClass): Boolean;
begin
  Result :=
    AClass.InheritsFrom(TAdapterUpdateField) or
    AdapterCanAddClass(AParent, AClass) or
    CanAddClassHelper(Self, AParent, AClass);
end;

function TAdapterFields.ImplGetWebComponentNodeName: string;
begin
  Result := sAdapterFieldsNodeName;
end;

procedure TAdapterFields.SetWebParent(const Value: TComponent);
begin
  if Value <> FParent then
  begin
    if Value <> nil then
    begin
      FParent := Value;
      (FParent as TCustomAdapter).SetData(Self);
    end
    else
      FParent := nil;
  end;
end;

function TAdapterFields.AdapterCanAddClass(AParent: TComponent;
  AClass: TClass): Boolean;
var
  AdapterEditor: IAdapterEditor;
begin
  if (Adapter = nil) then
    Result := True
  else if Supports(IInterface(Adapter), IAdapterEditor, AdapterEditor) then
    Result := AdapterEditor.CanAddFieldClass(AParent, AClass)
  else
    Result := False;
end;

{ TAdapterDefaultFields }

destructor TAdapterDefaultFields.Destroy;
begin
  inherited;
  FreeAndNil(FDefaultWebComponents);
end;

function TAdapterDefaultFields.GetVariablesInUse: TWebComponentList;
begin
  if Assigned(FParent) then
    Result := (FParent as TDefaultFieldsAdapter).VisibleFields
  else
    Result := inherited GetVariablesInUse;
end;

function TAdapterDefaultFields.GetAddAllFieldsItem: string;
begin
  Result := sAddAllAdapterData;
end;

function TAdapterDefaultFields.GetAddFieldsDlgCaption: string;
begin
  Result := sAddAdapterDataDlgCaption;
end;

function TAdapterDefaultFields.GetAddFieldsItem: string;
begin
  Result := sAddAdapterData;
end;

const
  sAdapterDataPrefix = 'Adapt'; // Do not location
function TAdapterDefaultFields.GetNewFieldPrefix: string;
begin
  Result := sAdapterDataPrefix;
end;

procedure TAdapterDefaultFields.ClearDefaultComponents;
begin
  FreeAndNil(FDefaultWebComponents);
  NotifyAdapterChange;
end;

function TAdapterDefaultFields.GetDefaultWebComponents: TWebComponentList;
begin
  Result := FDefaultWebComponents;
end;

procedure TAdapterDefaultFields.SetDefaultWebComponents(
  AList: TWebComponentList);
begin
  FDefaultWebComponents := AList;
end;

{ TAdapterDefaultActions }

destructor TAdapterDefaultActions.Destroy;
begin
  inherited;
  FreeAndNil(FDefaultWebComponents);
end;

function TAdapterDefaultActions.GetVariablesInUse: TWebComponentList;
begin
  if Assigned(FParent) then
    Result := (FParent as TDefaultFieldsAdapter).VisibleActions
  else
    Result := inherited GetVariablesInUse;
end;

function TAdapterDefaultActions.GetAddAllFieldsItem: string;
begin
  Result := sAddAllAdapterActions;
end;

function TAdapterDefaultActions.GetAddFieldsDlgCaption: string;
begin
  Result := sAddAdapterActionsDlgCaption;
end;

function TAdapterDefaultActions.GetAddFieldsItem: string;
begin
  Result := sAddAdapterActions;
end;

const
  sAdapterActionsPrefix = 'Action'; // Do not location

function TAdapterDefaultActions.GetNewFieldPrefix: string;
begin
  Result := sAdapterActionsPrefix;
end;

procedure TAdapterDefaultActions.ClearDefaultComponents;
begin
  FreeAndNil(FDefaultWebComponents);
  NotifyAdapterChange;
end;

function TAdapterDefaultActions.GetDefaultWebComponents: TWebComponentList;
begin
  Result := FDefaultWebComponents;
end;

procedure TAdapterDefaultActions.SetDefaultWebComponents(
  AList: TWebComponentList);
begin
  FDefaultWebComponents := AList;
end;

{ TDefaultFieldsAdapter }

procedure TDefaultFieldsAdapter.ImplSetActions(
  const Value: TAdapterSubComponent);
begin
  inherited;
  FActions := Value as TAdapterDefaultActions;
end;

procedure TDefaultFieldsAdapter.ImplSetData(const Value: TAdapterSubComponent);
begin
  inherited;
  FData := Value as TAdapterDefaultFields;
end;
  
procedure TDefaultFieldsAdapter.DefaultWebComponentsChange(
  Sender: TObject);

  function ListIsClear(AList: TWebComponentList): Boolean;
  begin
    Result := (not Assigned(AList)) or (AList.Count = 0);
  end;
begin
  if ([csLoading, csDestroying] * ComponentState <> []) then
    if ListIsClear(Data.FDefaultWebComponents) or ListIsClear(Actions.FDefaultWebComponents) then
      // Only send notification when cleared to prevent
      // problems when list is populated on demand
      NotifyAdapterChange;
end;

procedure TDefaultFieldsAdapter.AddDefaultFields(AComponents: TWebComponentList);
var
  List: TStrings;
begin
  List := TStringList.Create;
  try
    ImplGetFieldsList(List);
    WebAdapt.AddDefaultFields(List, AComponents);
  finally
    List.Free;
  end;
end;

function TDefaultFieldsAdapter.ImplGetVisibleFields: TWebComponentList;
begin
  if Data.GetWebComponents.Count > 0 then
    Result := inherited ImplGetVisibleFields
  else
  begin
    if not Assigned(Data.FDefaultWebComponents) then
    begin
      Data.FDefaultWebComponents := TWebComponentList.Create(Data);
      Data.FDefaultWebComponents.OnChange := DefaultWebComponentsChange;
      AddDefaultFields(Data.FDefaultWebComponents);
    end;
    Result := Data.FDefaultWebComponents;
  end;
end;

procedure TDefaultFieldsAdapter.AddDefaultActions(AComponents: TWebComponentList);
var
  List: TStrings;
begin
  List := TStringList.Create;
  try
    ImplGetActionsList(List);
    WebAdapt.AddDefaultActions(List, AComponents);
  finally
    List.Free;
  end;
end;

function TDefaultFieldsAdapter.ImplGetVisibleActions: TWebComponentList;
begin
  if Actions.GetWebComponents.Count > 0 then
    Result := inherited ImplGetVisibleActions
  else
  begin
    if not Assigned(Actions.FDefaultWebComponents) then
    begin
      Actions.FDefaultWebComponents := TWebComponentList.Create(Actions);
      Actions.FDefaultWebComponents.OnChange := DefaultWebComponentsChange;
      AddDefaultActions(Actions.FDefaultWebComponents);
    end;
    Result := Actions.FDefaultWebComponents;
  end;
end;

function TDefaultFieldsAdapter.GetActionsClass: TAdapterActionsClass;
begin
  Result := TAdapterDefaultActions;
end;

function TDefaultFieldsAdapter.GetDataClass: TAdapterFieldsClass;
begin
  Result := TAdapterDefaultFields;
end;

{ TAdapterSubComponent }

function TAdapterSubComponent.CanAddClass(AParent: TComponent;
  AClass: TClass): Boolean;
begin
  Result := ImplCanAddClass(AParent, AClass);
end;

function TAdapterSubComponent.GetParentComponent: TComponent;
begin
  if Assigned(FParent) then
    Result := FParent else
    Result := inherited GetParentComponent;
end;

function TAdapterSubComponent.GetVariablesInUse: TWebComponentList;
begin
  Result := GetWebComponents;
end;

function TAdapterSubComponent.HasParent: Boolean;
begin
  if Assigned(FParent) then
    Result := True else
    Result := inherited HasParent;
end;

function TAdapterSubComponent.ImplCanAddClass(AParent: TComponent;
  AClass: TClass): Boolean;
begin
  Assert(False); // ImplCanAddClass not implemented
  Result := False;
end;

procedure TAdapterSubComponent.ReadState(Reader: TReader);
begin
  inherited ReadState(Reader);
  SetWebParent(Reader.Parent);
end;

procedure TAdapterSubComponent.SetParentComponent(AParent: TComponent);
begin
  if not (csLoading in ComponentState) then
    SetWebParent(AParent);
end;

procedure TAdapterSubComponent.SetWebParent(const Value: TComponent);
begin
  Assert(False); // SetWebParent not implemented
end;

procedure TAdapterSubComponent.EndIterator(OwnerData: Pointer);
begin
  // Do nothing
end;

function TAdapterSubComponent.FindNamedVariable(
  const AName: string): TComponent;

  function Find(AVariablesInUse:  TWebComponentList): TComponent;
  var
    I: Integer;
    VariableName: IWebVariableName;
  begin
    for I := 0 to AVariablesInUse.Count - 1 do
    begin
      Result := AVariablesInUse.WebComponents[I];
      Supports(IInterface(Result), IWebVariableName, VariableName);
      if Assigned(VariableName) then
        if SameText(VariableName.VariableName, AName) then
          Exit;
    end;
  Result := nil;
  end;
begin
  Result := Find(VariablesInUse);
end;

function TAdapterSubComponent.FindVariable(
  const AName: string): TComponent;
begin
  Result := FindNamedVariable(AName);
end;

function TAdapterSubComponent.FindVariableContainer(
  const AName: string): TComponent;
var
  Intf: IUnknown;
begin
  Result := FindNamedVariable(AName);
  if Assigned(Result) and
    not Supports(IInterface(Result), IWebVariablesContainer, Intf) then
    RaiseVariableIsNotAContainer(AName);
end;

function TAdapterSubComponent.GetAdapter: TComponent;
begin
  Result := GetParentComponent;
end;

function TAdapterSubComponent.GetCurrentObject(
  OwnerData: Pointer): TObject;
begin
  Result := GetVariable(FIteratorIndex);
end;

function TAdapterSubComponent.GetDefaultWebComponents: TWebComponentList;
begin
  Result := nil;
end;

function TAdapterSubComponent.GetVariable(I: Integer): TComponent;
begin
  Result := VariablesInUse[I]
end;

function TAdapterSubComponent.GetVariableCount: Integer;
begin
  Result := VariablesInUse.Count;
end;

function TAdapterSubComponent.GetWebComponentNodeName: string;
begin
  Result := ImplGetWebComponentNodeName;
end;

function TAdapterSubComponent.ImplGetWebComponentNodeName: string;
begin
  Result := '';
end;

function TAdapterSubComponent.NextIteration(
  var OwnerData: Pointer): Boolean;
begin
  Inc(FIteratorIndex);
  Result := FIteratorIndex < VariablesInUse.Count;
end;

procedure TAdapterSubComponent.NotifyAdapterChange;
var
  Intf: IAdapterNotifyAdapterChange;
begin
  if Supports(IUnknown(Adapter), IAdapterNotifyAdapterChange, Intf) then
    Intf.NotifyAdapterChange;
end;

procedure TAdapterSubComponent.SetDefaultWebComponents(
  AList: TWebComponentList);
begin
  Assert(False); // Unexpected call.  Should be implemented by descendent
end;

function TAdapterSubComponent.StartIterator(
  var OwnerData: Pointer): Boolean;
begin
  FIteratorIndex := 0;
  Result := FIteratorIndex < VariablesInUse.Count;
end;

{ TAdapterErrorsList }

procedure TAdapterErrorsList.AddError(const AMessage: string; AObject: TObject; AID: Integer);
var
  VarName: IWebVariableName;
begin
  if Supports(AObject, IWebVariableName, VarName) then
    AddError(AMessage, VarName.VariableName, AID)
  else
    AddError(AMessage, '', AID);
end;

procedure TAdapterErrorsList.AddError(AException: Exception; AObject: TObject);
var
  VarName: IWebVariableName;
begin
  if Supports(AObject, IWebVariableName, VarName) then
    AddError(AException, VarName.VariableName)
  else
    AddError(AException);
end;

procedure TAdapterErrorsList.AddError(AException: Exception; const AObjectName: string);
var
  ID: Integer;
begin
  if AException is EAdapterException then
    ID := EAdapterException(AException).ID
  else
    ID := 0;
  if AObjectName = '' then
    if AException is EAdapterFieldException then
      AddError(AException.Message, EAdapterFieldException(AException).FieldName, ID)
    else
      AddError(AException.Message, AObjectName, ID)
  else
    AddError(AException.Message, AObjectName, ID);
end;

procedure TAdapterErrorsList.AddError(const AMessage: string; const AObjectName: string; AID: Integer);
begin
  FMessages.AddObject(AMessage, TObject(AID));
  FFieldNames.Add(AObjectName)
end;

procedure TAdapterErrorsList.ImplClearErrors;
begin
  FMessages.Clear;
  FFieldNames.Clear;
end;

constructor TAdapterErrorsList.Create(AAdapter: TObject);
begin
  inherited Create;
  FMessages := TStringList.Create;
  FFieldNames := TStringList.Create;
  FLabels := TStringList.Create;
  FAdapter := AAdapter;
end;

procedure TAdapterErrorsList.ImplDefineLabel(const AName, ALabel: string);
begin
  FLabels.Values[AName] := ALabel;
end;

destructor TAdapterErrorsList.Destroy;
begin
  inherited;
  FMessages.Free;
  FFieldNames.Free;
  FLabels.Free;
end;

function TAdapterErrorsList.ImplGetError(I: Integer): IAdapterError;
begin
  Result := TAdapterError.Create(Self, I);
end;

function TAdapterErrorsList.ImplGetErrorCount: Integer;
begin
  Result := FMessages.Count;
end;

function TAdapterErrorsList.ImplGetObjectErrors(const AName: string): TObject;
var
  I: Integer;
begin
  Result := nil;
  I := FFieldNames.IndexOf(AName);
  if I >= 0 then
  begin
    Result := FFieldNames.Objects[I];
    if Result = nil then
    begin
      Result := TAdapterObjectErrorsList.Create(Self, AName);
      FFieldNames.Objects[I] := Result;
    end;
  end;
end;

function TAdapterErrorsList.ImplHasObjectErrors(const AName: string): Boolean;
begin
  Result := FFieldNames.IndexOf(AName) >= 0;
end;

function TAdapterErrorsList.GetFieldName(I: Integer): string;
begin
  Result := FFieldNames[I];
end;

function TAdapterErrorsList.GetID(I: Integer): integer;
begin
  Result := Integer(FMessages.Objects[I]);
end;

function TAdapterErrorsList.GetMessage(I: Integer): string;
begin
  Result := FMessages[I];
end;


{ TAdapterError }

constructor TAdapterError.Create(AErrors: TAdapterErrorsList; AIndex: Integer);
begin
  inherited Create;
  FErrors := AErrors;
  FIndex := AIndex;
end;

function TAdapterError.GetErrorText: string;
var
  L, F, Msg: string;
  P: Integer;
begin
  Msg := FErrors.Messages[FIndex];
  F := FErrors.FieldNames[FIndex];
  if (F <> '') and (FErrors.FLabels.Values[F] <> '') then
  begin
    L := FErrors.FLabels.Values[F];
    P := Pos(F, Msg);
    if P > 0 then
    begin
      Delete(Msg, P, Length(F));
      Insert(L, Msg, P);
    end;
  end;
  Result := Msg;
end;

function TAdapterError.GetField: TComponent;
var
  Intf: IWebDataFields;
begin
  Result := nil;
  if FErrors.FieldNames[FIndex] <> '' then
    if Supports(FErrors.FAdapter, IWebDataFields, Intf) then
      Result := FindAdapterField(Intf.VisibleFields, FErrors.FieldNames[FIndex]);
end;

function TAdapterError.GetID: integer;
begin
  Result := FErrors.IDs[FIndex];
end;

{ TCustomLoginFormAdapter }

procedure TCustomLoginFormAdapter.ImplGetActionsList(AList: TStrings);
begin
  AList.Clear;
  AList.AddObject(sLoginAction, TObject(TLoginFormAdapterLoginAction));
end;

procedure TCustomLoginFormAdapter.ImplNotifyDeactivate;
begin
  inherited;
  NextPage := '';
end;

procedure TCustomLoginFormAdapter.ImplGetFieldsList(AList: TStrings);
begin
  AList.Clear;
  AList.AddObject(sLoginUserName, TObject(TAdapterUserNameField));
  AList.AddObject(sLoginPassword, TObject(TAdapterPasswordField));
  AList.AddObject(sLoginNextPage, TObject(TAdapterNextPageField));
end;

function TCustomLoginFormAdapter.ImplCanAddActionClass(
  AParent: TComponent; AClass: TClass): Boolean;
begin
  Result :=
    inherited ImplCanAddActionClass(AParent, AClass) or
    AClass.InheritsFrom(TCustomLoginFormAdapterAction);
end;

function TCustomLoginFormAdapter.ImplCanAddFieldClass(AParent: TComponent;
  AClass: TClass): Boolean;
begin
  Result :=
    inherited ImplCanAddFieldClass(AParent, AClass) or
    AClass.InheritsFrom(TAdapterLoginField);
end;

procedure TCustomLoginFormAdapter.RaiseBlankPassword;
begin
  raise EAdapterFieldException.Create(sBlankPassword, sWebUserPassword);
end;

procedure TCustomLoginFormAdapter.RaiseBlankUserName;
begin
  raise EAdapterFieldException.Create(sBlankUserName, sWebUserName);
end;

procedure TCustomLoginFormAdapter.ValidatePassword;
var
  Handled: Boolean;
begin
  if Assigned(OnValidatePassword) then
    OnValidatePassword(Self, Password, Handled)
  else
    Handled := False;
  if not Handled then
    if PasswordRequired then
      if VarIsEmpty(Password) or (Trim(string(Password)) = '') then
        RaiseBlankPassword;
end;

function TCustomLoginFormAdapter.EndUser: IWebEndUser;
var
  AppModule: TComponent;
  GetIntf: IGetWebAppComponents;
begin
  if not Assigned(FEndUser) then
  begin
    AppModule := WebContext.FindApplicationModule(Owner);
    if Supports(IUnknown(AppModule), IGetWebAppComponents, GetIntf) then
      FEndUser := GetIntf.GetWebEndUser;
  end;
  Result := FEndUser;
end;

function TCustomLoginFormAdapter.UserList: IWebUserList;
var
  AppModule: TComponent;
  GetIntf: IGetWebAppComponents;
begin
  if not Assigned(FUserList) then
  begin
    AppModule := WebContext.FindApplicationModule(Owner);
    if Supports(IUnknown(AppModule), IGetWebAppComponents, GetIntf) then
      FUserList := GetIntf.GetWebUserList;
  end;
  Result := FUserList;
end;

procedure TCustomLoginFormAdapter.ExecuteLogin(AUserID: Variant);
begin
  if Assigned(OnLogin) then
    OnLogin(Self, AUserID);
  if EndUser <> nil then
    EndUser.LogIn(AUserID);
end;

procedure TCustomLoginFormAdapter.ValidateUserName;
var
  Handled: Boolean;
begin
  if Assigned(OnValidateUserName) then
    OnValidateUserName(Self, UserName, Handled)
  else
    Handled := False;
  if not Handled then
    if VarIsEmpty(UserName) or (Trim(string(UserName)) = '') then
      RaiseBlankUserName;
end;

function TCustomLoginFormAdapter.GetPassword: Variant;
var
  FieldValue: IActionFieldValue;
  FieldValues: IActionFieldValues;
begin
  Result := Unassigned;
  if Supports(WebContext.AdapterRequest, IActionFieldValues, FieldValues) then
  begin
    FieldValue := FieldValues.ValueOfField(sLoginPassword);
    if FieldValue <> nil then
      Result := FieldValue.Values[0];
  end;
end;

function TCustomLoginFormAdapter.GetUserName: Variant;
var
  FieldValue: IActionFieldValue;
  FieldValues: IActionFieldValues;
begin
  Result := Unassigned;
  if Supports(WebContext.AdapterRequest, IActionFieldValues, FieldValues) then
  begin
    FieldValue := FieldValues.ValueOfField(sLoginUserName);
    if FieldValue <> nil then
      Result := FieldValue.Values[0];
  end;
end;

function TCustomLoginFormAdapter.GetNextPage: string;
var
  DefaultResponse: IGetAdapterRequestDefaultResponse;
begin
  if FNextPage = '' then
    if Supports(WebContext.AdapterRequest, IGetAdapterRequestDefaultResponse, DefaultResponse) then
      FNextPage := DefaultResponse.SuccessPage;
  if FNextPage = '' then
    FNextPage := WebContext.RequestedPageName;
  if FNextPage = '' then
    FNextPage := FindDefaultAppPageName;
  Result := FNextPage;
end;

{ TAdapterUserNameField }

function TAdapterUserNameField.ImplGetValue: Variant;
begin
  Result := '';
end;

{ TAdapterPasswordField }

function TAdapterPasswordField.GetInputStyleType(const AAdapterMode: string): TAdapterInputHTMLElementType;
begin
  Result := htmliPasswordInput
end;

function TAdapterPasswordField.ImplGetValue: Variant;
begin
  Result := '';
end;

{ TAdapterNextPageField }

destructor TAdapterNextPageField.Destroy;
begin
  inherited;
  FPageList.Free;
end;

function TAdapterNextPageField.GetInputStyleType(const AAdapterMode: string): TAdapterInputHTMLElementType;
begin
  Result := htmliSelect
end;

function TAdapterNextPageField.GetAdapterValuesList: IValuesListAdapter;
begin
  if FPageList = nil then
    FPageList := TLogicalPageList.Create(nil);
  Supports(FPageList, IValuesListAdapter, Result);
  Assert((FPageList = nil) or (Result <> nil));
end;

function ActionFieldValueAsString(Value: Variant): string;
begin
  try
    Result := Value
  except
    Result := '';
  end;
end;

function TAdapterNextPageField.ImplGetValue: Variant;
var
  Value: IActionFieldValue;
begin
  if EchoActionFieldValue then
  begin
    Value := ActionValue;
    if Value <> nil then
      Result := ActionFieldValueAsString(Value.Values[0])
    else
      Result := '';
  end
  else
    Result := Adapter.NextPage
end;

procedure TAdapterNextPageField.UpdateValue(
  AActionRequest: IActionRequest; AFieldIndex: Integer);
begin
  Adapter.NextPage := ActionValue.Values[0];
end;

function TAdapterNextPageField.ImplGetEchoActionFieldValue: Boolean;
begin
  Result := FEchoActionFieldValue;
end;

procedure TAdapterNextPageField.ImplSetEchoActionFieldValue(
  AValue: Boolean);
begin
  FEchoActionFieldValue := AValue;
end;

{ TLoginFormAdapterLoginAction }

function TLoginFormAdapterLoginAction.GetDefaultActionName: string;
begin
  Result := sLoginAction;
end;

const
  sNextPage = 'NextPage'; // Do not localize

procedure TLoginFormAdapterLoginAction.ImplGetAdapterItemRequestParams(
  var AIdentifier: string; Params: IAdapterItemRequestParams);
var
  Page: string;
begin
  Page := NextPage;
  if Page = '' then
    Page := WebContext.RequestedPageName;
  if Page <> '' then
    Params.ParamValues.Add(Format('%s=%s', [sNextPage, Page]));
  inherited ImplGetAdapterItemRequestParams(AIdentifier, Params);
end;

function TLoginFormAdapterLoginAction.GetLoginStrings: TStrings;
begin
  Result := TStringList.Create;
  try
    Result.Add(Format('UserName=%s', [Adapter.UserName])); // Do not localize
    Result.Add(Format('Password=%s', [Adapter.Password])); // Do not localize
  except
    Result.Free;
    raise;
  end;
end;

procedure TLoginFormAdapterLoginAction.ImplExecuteActionRequest(
  AActionRequest: IActionRequest; AActionResponse: IActionResponse);
var
  UserID: Variant;
  S: TStrings;
begin
  RedirectOptions := roRedirect;
  if (Adapter <> nil) then
    with Adapter do
    begin
      try
        NextPage := GetAdapterRequestParamsIntf(AActionRequest).ValueOfParam(sNextPage);
        UpdateRecords;
        ValidatePassword;
        ValidateUserName;
        if UserList <> nil then
        begin
          S := GetLoginStrings;
          try
            UserID := UserList.ValidateUser(S);
          finally
            S.Free;
          end;
        end
        else
          UserID := UserName;
        ExecuteLogin(UserID);
        if NextPage <> '' then
          with GetActionRespondWith(AActionResponse) do
          begin
            RespondWithPage(NextPage);
          end;
      except
        on E: Exception do
        begin
          Errors.AddError(E);
        end;
      end;
    end;
  if Errors.ErrorCount > 0 then
     Adapter.EchoActionFieldValues := True;
end;

function TLoginFormAdapterLoginAction.NextPage: string;
begin
  Result := Adapter.NextPage;
end;

{ TCustomLoginFormAdapterAction }

function TCustomLoginFormAdapterAction.GetAdapter: TCustomLoginFormAdapter;
begin
  if (inherited Adapter <> nil) and (inherited Adapter is TCustomLoginFormAdapter) then
    Result := TCustomLoginFormAdapter(inherited Adapter)
  else
  begin
    Result := nil;
    Assert(False); // LoginFormAdapter not found
  end;
end;

{ TBaseEndUserAdapter }

procedure ListEndUserFields(AList: TStrings);
begin
  AList.Clear;
  AList.AddObject(sEndUserDisplayName, TObject(TAdapterEndUserDisplayNameField));
  AList.AddObject(sEndUserLoggedIn, TObject(TAdapterEndUserLoggedInField));
end;

procedure ListEndUserActions(AList: TStrings);
begin
  AList.Clear;
  AList.AddObject(sEndUserLoginFormAction, TObject(TEndUserAdapterLoginFormAction));
  AList.AddObject(sEndUserLogoutAction, TObject(TEndUserAdapterLogoutAction));
end;

procedure TBaseEndUserAdapter.ImplGetActionsList(AList: TStrings);
begin
  ListEndUserActions(AList);
end;

procedure TBaseEndUserAdapter.ImplGetFieldsList(AList: TStrings);
begin
  ListEndUserFields(AList);
end;

function TBaseEndUserAdapter.ImplCanAddActionClass(
  AParent: TComponent; AClass: TClass): Boolean;
begin
  Result :=
    inherited ImplCanAddActionClass(AParent, AClass) or
    AClass.InheritsFrom(TCustomEndUserAdapterAction);
end;

function TBaseEndUserAdapter.ImplCanAddFieldClass(AParent: TComponent;
  AClass: TClass): Boolean;
begin
  Result :=
    inherited ImplCanAddFieldClass(AParent, AClass) or
    AClass.InheritsFrom(TAdapterEndUserField);
end;

function TBaseEndUserAdapter.GetDisplayName: string;
begin
  Result := ImplGetDisplayName;
end;

function TBaseEndUserAdapter.ImplGetDisplayName: string;
var
  Field: TObject;
  Intf: IWebGetFieldValue;
begin
  // Delegate to action
  Field := FindNamedField(sEndUserDisplayName);
  if Field <> nil then
    if Supports(Field, IWebGetFieldValue, Intf) then
      Result := Intf.Value;
end;

function TBaseEndUserAdapter.GetLoggedIn: Boolean;
begin
  Result := ImplGetLoggedIn;
end;

function TBaseEndUserAdapter.ImplGetLoggedIn: Boolean;
var
  Field: TObject;
  Intf: IWebGetFieldValue;
begin
  // Delegate to action
  Result := False;
  Field := FindNamedField(sEndUserLoggedIn);
  if Field <> nil then
    if Supports(Field, IWebGetFieldValue, Intf) then
      Result := Intf.Value;
end;

function TBaseEndUserAdapter.GetLoginFormAction: TComponent;
begin
  Result := ImplGetLoginFormAction;
end;

function TBaseEndUserAdapter.ImplGetLoginFormAction: TComponent;
begin
  Result := FindNamedAction(sEndUserLoginFormAction);
end;

function TBaseEndUserAdapter.GetLogoutAction: TComponent;
begin
  Result := ImplGetLogoutAction;
end;

function TBaseEndUserAdapter.ImplGetLogoutAction: TComponent;
begin
  Result := FindNamedAction(sEndUserLogoutAction);
end;

procedure TBaseEndUserAdapter.ExecuteLoginForm;
begin
  ImplProduceLoginPage;
end;

function TBaseEndUserAdapter.CanProduceLoginPage: Boolean;
begin
  Result := Assigned(OnProduceLoginPage) or (LoginPage <> '');
end;

function TBaseEndUserAdapter.CanExecuteLoginForm: Boolean;
begin
  Result := CanProduceLoginPage and not ImplGetLoggedIn;
end;

function TBaseEndUserAdapter.CanExecuteLogout: Boolean;
begin
  Result := ImplGetLoggedIn;
end;

function TBaseEndUserAdapter.ProduceLoginPage: Boolean;
begin
  Result := ImplProduceLoginPage;
end;

function TBaseEndUserAdapter.ImplProduceLoginPage: Boolean;
var
  PageComponent: TObject;
  Intf: IPageResult;
  Response: TWebResponse;
begin
  Response := WebCntxt.WebContext.Response;
  Result := False;
  if Assigned(OnProduceLoginPage) then
    OnProduceLoginPage(Self, Result);

  if not Result then
  begin
    if LoginPage <> '' then
    begin
      if WebCntxt.WebContext.FindPage(LoginPage, [], PageComponent) then
      begin
        if Supports(PageComponent, IPageResult, Intf) then
          Result := Intf.DispatchPage(LoginPage, Response)
        else
          Result := False;
        if not Result then
          raise EAdapterException.CreateFmt(sPageContentNotProvided, [LoginPage]);
      end
      else
        raise EAdapterException.CreateFmt(sPageNotFound, [LoginPage]);
    end
    else
      raise EAdapterException.Create(sNoLoginPage);
  end;
end;

procedure TBaseEndUserAdapter.ExecuteLogout;
begin
  // Do nothing
end;

procedure TBaseEndUserAdapter.ExecuteLogin(AUserID: Variant);
begin
  // Do nothing
end;

function TBaseEndUserAdapter.GetEndUserAdapter: TComponent;
begin
  Result := Self;
end;

function TBaseEndUserAdapter.GetDisplayNameValue: string;
begin
  Result := '';
end;

function TBaseEndUserAdapter.GetLoggedInValue: Boolean;
begin
  Result := False;
end;

procedure TBaseEndUserAdapter.LogIn(AUserID: Variant);
begin
  ImplLogin(AUserID);
end;

procedure TBaseEndUserAdapter.ImplLogIn(AUserID: Variant);
begin
  ExecuteLogin(AUserID);
end;

function TBaseEndUserAdapter.ImplGetEndUserAdapter: TComponent;
begin
  Result := Self;
end;

function TBaseEndUserAdapter.ImplHasViewRights(ARights: string): Boolean;
begin
  Result := DoOnHasRights(OnHasRights, ARights);
end;

function TBaseEndUserAdapter.HasModifyRights(ARights: string): Boolean;
begin
  Result := ImplHasModifyRights(ARights);
end;

function TBaseEndUserAdapter.HasViewRights(ARights: string): Boolean;
begin
  Result := ImplHasViewRights(ARights);
end;

function TBaseEndUserAdapter.ImplHasModifyRights(ARights: string): Boolean;
begin
  Result := DoOnHasRights(OnHasRights, ARights);
end;

function TBaseEndUserAdapter.HasExecuteRights(ARights: string): Boolean;
begin
  Result := ImplHasExecuteRights(ARights);
end;

function TBaseEndUserAdapter.ImplHasExecuteRights(ARights: string): Boolean;
begin
  Result := DoOnHasRights(OnHasRights, ARights);
end;

function TBaseEndUserAdapter.DoOnHasRights(AEvent: TEndUserRightsEvent; const ARights: string): Boolean;
var
  S: TStrings;
  Handled: Boolean;
begin
  Handled := False;
  if Assigned(AEvent) then
  begin
    S := TStringList.Create;
    try
      ExtractStrings([';', ' ', ','], [], PChar(ARights), S);
      Handled := True;
      AEvent(Self, S, Result, Handled);
    finally
      S.Free;
    end;
  end;
  if not Handled then
  begin
    Result := True;
    if UserList <> nil then
      Result := UserList.CheckAccessRights(GetUserID, ARights);
  end;
end;

function TBaseEndUserAdapter.UserList: IWebUserList;
var
  AppModule: TComponent;
  GetIntf: IGetWebAppComponents;
begin
  if not Assigned(FUserList) then
  begin
    AppModule := WebContext.FindApplicationModule(Owner);
    if Supports(IUnknown(AppModule), IGetWebAppComponents, GetIntf) then
      FUserList := GetIntf.GetWebUserList;
  end;
  Result := FUserList;
end;

function TBaseEndUserAdapter.GetUserID: Variant;
begin
  Result := Unassigned;
end;

{ TCustomEndUserAdapter }

procedure TCustomEndUserAdapter.ExecuteLogout;
begin
  if Assigned(OnLogout) then
    OnLogout(Self);
end;

function TCustomEndUserAdapter.GetUserID: Variant;
begin
  if Assigned(OnGetUserID) then
    OnGetUserID(Self, Result)
  else
    Result := Unassigned;
end;

procedure TCustomEndUserAdapter.ExecuteLogin(AUserID: Variant);
begin
  if Assigned(OnLogin) then
    OnLogin(Self, AUserID);
end;

function TCustomEndUserAdapter.GetLoggedInValue: Boolean;
begin
  if Assigned(OnIsLoggedIn) then
    OnIsLoggedIn(Self, Result)
  else
    Result := False;
end;

function TCustomEndUserAdapter.GetDisplayNameValue: string;
begin
  if Assigned(OnGetDisplayName) then
    OnGetDisplayName(Self, Result)
  else
    Result := '';
end;

{ TCustomEndUserAdapterAction }

function TCustomEndUserAdapterAction.GetAdapter: TBaseEndUserAdapter;
begin
  if (inherited Adapter <> nil) and (inherited Adapter is TBaseEndUserAdapter) then
    Result := TBaseEndUserAdapter(inherited Adapter)
  else
  begin
    Result := nil;
    Assert(False); // EndUserAdapter not found
  end;
end;

{ TEndUserAdapterLoginFormAction }

function TEndUserAdapterLoginFormAction.GetDefaultActionName: string;
begin
  Result := sLoginFormAction;
end;

function TEndUserAdapterLoginFormAction.ImplWebEnabled: Boolean;
begin
  Result := False;
  if (Adapter <> nil) then
    with Adapter do
      Result := CanExecuteLoginForm;
end;

procedure TEndUserAdapterLoginFormAction.ImplExecuteActionRequest(
  AActionRequest: IActionRequest; AActionResponse: IActionResponse);
begin
  RedirectOptions := [];
  if (Adapter <> nil) then
    with Adapter do
    begin
      try
        ExecuteLoginForm;
      except
        on E: Exception do
        begin
          Errors.AddError(E);
          Exit;
        end;
      end;
    end;
end;

{ TCustomApplicationAdapter }

procedure ListApplicationFields(AList: TStrings);
begin
  AList.Clear;
  AList.AddObject(sApplicationTitle, TObject(TAdapterApplicationTitleField));
end;

procedure ListApplicationActions(AList: TStrings);
begin
  AList.Clear;
  // None by default
end;

procedure TCustomApplicationAdapter.ImplGetActionsList(AList: TStrings);
begin
  ListApplicationActions(AList);
end;

procedure TCustomApplicationAdapter.ImplGetFieldsList(AList: TStrings);
begin
  ListApplicationFields(AList);
end;

function TCustomApplicationAdapter.ImplCanAddActionClass(
  AParent: TComponent; AClass: TClass): Boolean;
begin
  Result :=
    inherited ImplCanAddActionClass(AParent, AClass) or
    AClass.InheritsFrom(TCustomApplicationAdapterAction);
end;

function TCustomApplicationAdapter.ImplCanAddFieldClass(AParent: TComponent;
  AClass: TClass): Boolean;
begin
  Result :=
    inherited ImplCanAddFieldClass(AParent, AClass) or
    AClass.InheritsFrom(TAdapterApplicationField);
end;

function TCustomApplicationAdapter.GetApplicationTitle: string;
var
  Field: TObject;
  Intf: IWebGetFieldValue;
begin
  Field := FindNamedField(sApplicationTitle);
  if Field <> nil then
    if Supports(Field, IWebGetFieldValue, Intf) then
      Result := Intf.Value;
end;

function TCustomApplicationAdapter.GetApplicationAdapter: TComponent;
begin
  Result := Self;
end;

{ TEndUserAdapterLogoutAction }

function TEndUserAdapterLogoutAction.GetDefaultActionName: string;
begin
  Result := sLogoutAction;
end;

function TEndUserAdapterLogoutAction.ImplWebEnabled: Boolean;
begin
  Result := False;
  if (Adapter <> nil) then
    with Adapter do
      Result := CanExecuteLogout;
end;

procedure TEndUserAdapterLogoutAction.ImplExecuteActionRequest(
  AActionRequest: IActionRequest; AActionResponse: IActionResponse);
begin
  RedirectOptions := roRedirect;
  if (Adapter <> nil) then
    with Adapter do
    begin
      try
        ExecuteLogout;
      except
        on E: Exception do
        begin
          Errors.AddError(E);
          Exit;
        end;
      end;
    end;
end;

{ TAdapterNamedDisplayField }

constructor TAdapterNamedDisplayField.Create(AOwner: TComponent);
begin
  inherited;
  FDisplayWidth := -1;
end;

function TAdapterNamedDisplayField.ImplGetDisplayLabel: string;
begin
  if FDisplayLabel <> '' then
    Result := FDisplayLabel
  else
    Result := inherited ImplGetDisplayLabel;
end;

function TAdapterNamedDisplayField.GetDisplayStyle(const AAdapterMode: string): string;
begin
  Result := AdapterDisplayHTMLElementTypeNames[GetDisplayStyleType(AAdapterMode)]
end;

function TAdapterNamedDisplayField.GetInputStyleType(const AAdapterMode: string): TAdapterInputHTMLElementType;
begin
  Result := htmliTextInput;
end;

function TAdapterNamedDisplayField.GetDisplayStyleType(const AAdapterMode: string): TAdapterDisplayHTMLElementType;
begin
  Result := htmldText;
end;

function TAdapterNamedDisplayField.ImplGetDisplayWidth: Integer;
begin
  Result := -1;
end;

function TAdapterNamedDisplayField.GetInputStyle(const AAdapterMode: string): string;
begin
  Result := AdapterInputHTMLElementTypeNames[GetInputStyleType(AAdapterMode)];
end;

function TAdapterNamedDisplayField.ImplGetRequired: Boolean;
begin
  Result := FRequired;
end;

procedure TAdapterNamedDisplayField.SetDisplayLabel(const AValue: string);
begin
  if AValue = GetDefaultDisplayLabel then
    FDisplayLabel := ''
  else
    FDisplayLabel := AValue;
end;

function TAdapterNamedDisplayField.GetViewModeType(const AAdapterMode: string): TAdapterDisplayViewModeType;
begin
  if ReadOnly then
    Result := htmlvmDisplay
  else
    Result := htmlvmInput;
end;

function TAdapterNamedDisplayField.GetViewMode(const AAdapterMode: string): string;
begin
  Result := AdapterDisplayViewModeTypeNames[GetViewModeType(AAdapterMode)]
end;

function TAdapterNamedDisplayField.IsDisplayLabelStored: Boolean;
begin
  Result := FDisplayLabel <> '';
end;

{ TCustomApplicationAdapterAction }

function TCustomApplicationAdapterAction.GetAdapter: TCustomApplicationAdapter;
begin
  if (inherited Adapter <> nil) and (inherited Adapter is TCustomApplicationAdapter) then
    Result := TCustomApplicationAdapter(inherited Adapter)
  else
  begin
    Result := nil;
    Assert(False); // ApplicationAdapter not found
  end;
end;

{ TAdapterApplicationTitleField }

function TAdapterApplicationTitleField.GetDefaultFieldName: string;
begin
  Result := sApplicationTitle;
end;

function TAdapterApplicationTitleField.ImplGetValue: Variant;
begin
  Result := '';
  if Adapter <> nil then
    Result := Adapter.ApplicationTitle;
end;

{ TAdapterApplicationField }

function TAdapterApplicationField.GetAdapter: TCustomApplicationAdapter;
begin
  if (inherited Adapter <> nil) and (inherited Adapter is TCustomApplicationAdapter) then
    Result := TCustomApplicationAdapter(inherited Adapter)
  else
  begin
    Result := nil;
    Assert(False); // ApplicationAdapter not found
  end;
end;

{ TAdapterEndUserLoggedInField }

function TAdapterEndUserLoggedInField.GetDefaultFieldName: string;
begin
  Result := sEndUserLoggedIn;
end;

function TAdapterEndUserLoggedInField.ImplGetValue: Variant;
begin
  if Adapter <> nil then
    Result := Adapter.GetLoggedInValue
  else
    Result := False;
end;

{ TAdapterEndUserDisplayNameField }

function TAdapterEndUserDisplayNameField.GetDefaultFieldName: string;
begin
  Result := sEndUserDisplayName;
end;

function TAdapterEndUserDisplayNameField.ImplGetValue: Variant;
begin
  if Adapter <> nil then
    Result := Adapter.GetDisplayNameValue
  else
    Result := '';
end;

{ TAdapterEndUserField }

function TAdapterEndUserField.GetAdapter: TBaseEndUserAdapter;
begin
  if (inherited Adapter <> nil) and (inherited Adapter is TBaseEndUserAdapter) then
    Result := TBaseEndUserAdapter(inherited Adapter)
  else
  begin
    Result := nil;
    Assert(False); // EndUserAdapter not found
  end;
end;

{ TBaseValuesListAdapter }

function TBaseValuesListAdapter.GetNameFieldClass: TComponentClass;
begin
  Assert(False);
  Result := nil;
end;

function TBaseValuesListAdapter.GetListName: string;
begin
  Result := ImplGetListName;
end;

function TBaseValuesListAdapter.ImplGetListName: string;
begin
  Result := '';
end;

function TBaseValuesListAdapter.GetValueFieldClass: TComponentClass;
begin
  Assert(False);
  Result := nil;
end;

function TBaseValuesListAdapter.GetListValue: Variant;
begin
  Result := ImplGetListValue;
end;

function TBaseValuesListAdapter.ImplGetListValue: Variant;
begin
  Result := Unassigned;
end;

function TBaseValuesListAdapter.ImplCanAddFieldClass(
  AParent: TComponent; AClass: TClass): Boolean;
begin
  Result :=
    inherited ImplCanAddFieldClass(AParent, AClass) or
    AClass.InheritsFrom(GetValueFieldClass) or
    AClass.InheritsFrom(GetNameFieldClass);
end;

const
  sNameField = 'NameField';    // Do not localize
  sValueField = 'ValueField';  // Do not localize

procedure TBaseValuesListAdapter.ImplGetFieldsList(AList: TStrings);
begin
  AList.Clear;
  AList.AddObject(sNameField, TObject(GetNameFieldClass));
  AList.AddObject(sValueField, TObject(GetValueFieldClass));
end;

function TBaseValuesListAdapter.ImplGetScriptObject: IDispatch;
begin
  Result := TAdapterValuesListWrapper.Create(Self);
end;

procedure TBaseValuesListAdapter.ImplEndIterator(OwnerData: Pointer);
begin
  Assert(False);
end;

function TBaseValuesListAdapter.ImplNextIteration(
  var OwnerData: Pointer): Boolean;
begin
  Assert(False);
  Result := False;
end;

function TBaseValuesListAdapter.ImplStartIterator(
  var OwnerData: Pointer): Boolean;
begin
  Assert(False);
  Result := False;
end;

function TBaseValuesListAdapter.GetListNameOfValue(
  Value: Variant): string;
begin
  Result := ImplGetListNameOfValue(Value);
end;

function TBaseValuesListAdapter.ImplGetListNameOfValue(
  Value: Variant): string;
begin
  Result := '';
end;

function TBaseValuesListAdapter.GetListImage: IInterface;
begin
  Result := ImplGetListImage;
end;

function TBaseValuesListAdapter.GetListImageOfValue(
  Value: Variant): IInterface;
begin
  Result := ImplGetListImageOfValue(Value);
end;

function TBaseValuesListAdapter.ImplGetListImage: IInterface;
begin
  Result := nil;
end;

function TBaseValuesListAdapter.ImplGetListImageOfValue(
  Value: Variant): IInterface;
begin
  Result := nil;
end;

{ TBaseValuesListField }

function TBaseValuesListField.GetAdapter: TBaseValuesListAdapter;
begin
  if (inherited Adapter <> nil) and (inherited Adapter is TBaseValuesListAdapter) then
    Result := TBaseValuesListAdapter(inherited Adapter)
  else
  begin
    Result := nil;
    Assert(False); // Adapter not found
  end;
end;

{ TCustomStringsValuesList }

constructor TCustomStringsValuesList.Create(AOwner: TComponent);
begin
  inherited;
  FStrings := TStringList.Create;
end;

destructor TCustomStringsValuesList.destroy;
begin
  inherited;
  FStrings.Free;
end;

procedure TCustomStringsValuesList.ImplEndIterator(OwnerData: Pointer);
begin
  // Do nothing
end;

function TCustomStringsValuesList.GetNameFieldClass: TComponentClass;
begin
  Result := TValuesListNameField;
end;

function TCustomStringsValuesList.GetValueFieldClass: TComponentClass;
begin
  Result := TValuesListValueField;
end;

function TCustomStringsValuesList.ImplGetListName: string;
begin
  if FIndex < Strings.Count then
    Result := Strings.Names[FIndex]
  else
    Result := '';
end;

function TCustomStringsValuesList.ImplGetListValue: Variant;
var
  S: string;
begin
  if FIndex < Strings.Count then
  begin
    S := Strings.Names[FIndex];
    if S <> '' then
      Result := Strings.Values[S]
    else
      Result := Strings[FIndex]
  end
  else
    Result := Unassigned;
end;

function TCustomStringsValuesList.ImplNextIteration(
  var OwnerData: Pointer): Boolean;
begin
  Inc(FIndex);
  Result := FIndex < Strings.Count;
end;

procedure TCustomStringsValuesList.SetStrings(const Value: TStrings);
begin
  FStrings.Assign(Value);
end;

function TCustomStringsValuesList.ImplStartIterator(
  var OwnerData: Pointer): Boolean;
begin
  FIndex := 0;
  Result := FIndex < Strings.Count;
end;

function TCustomStringsValuesList.ImplGetListNameOfValue(
  Value: Variant): string;
var
  I: Integer;
begin
  for I := 0 to Strings.Count - 1 do
  begin
    Result := Strings.Names[I];
    if Result <> '' then
    begin
      try
        if Strings.Values[Result] = Value then
          Exit;
      except

      end;
    end;
  end;
  Result := '';
end;

function TCustomStringsValuesList.GetStrings: TStrings;
begin
  if not (csLoading in ComponentState) and not StringsPrepared then
    PrepareStrings;
  Result := FStrings;
end;

procedure TCustomStringsValuesList.PrepareStrings;
begin
  StringsPrepared := True;
  if Assigned(OnPrepareStrings) then
    OnPrepareStrings(Self);
end;

procedure TCustomStringsValuesList.ImplNotifyDeactivate;
begin
  inherited;
  StringsPrepared := False;
end;

{ TLogicalPageList }

constructor TLogicalPageList.Create(AOwner: TComponent);
var
  I: Integer;
  Info: IWebPageInfo;
begin
  inherited;
  for I := 0 to WebContext.PageCount - 1 do
  begin
    Info := WebContext.Pages[I];
    if Info.PageIsPublished then
    begin
      if Info.PageTitle <> '' then
        Strings.Add(Format('%s=%s', [Info.PageTitle, Info.PageName]))
      else
        Strings.Add(Info.PageName);
    end;
  end;

end;

{ TValuesListNameField }

function TValuesListNameField.GetDefaultFieldName: string;
begin
  Result := sNameField;
end;

function TValuesListNameField.ImplGetValue: Variant;
begin
  Result := Adapter.GetListName;
end;

{ TValuesListValueField }

function TValuesListValueField.GetDefaultFieldName: string;
begin
  Result := sValueField;
end;

function TValuesListValueField.ImplGetValue: Variant;
begin
  Result := Adapter.GetListValue;
end;

{ TCustomEndUserSessionAdapter }

const
  sUserID = 'UserID';

procedure TCustomEndUserSessionAdapter.ExecuteLogin(AUserID: Variant);
begin
  UserID := AUserID;
end;

procedure TCustomEndUserSessionAdapter.ExecuteLogout;
begin
  if WebContext <> nil then
    WebContext.Session.Terminate;
end;

function TCustomEndUserSessionAdapter.GetDisplayNameValue: string;
begin
  Result := UserID;
end;

function TCustomEndUserSessionAdapter.GetLoggedInValue: Boolean;
begin
  Result := (not VarIsEmpty(UserID)) and (UserID <> '');
end;

function TCustomEndUserSessionAdapter.GetUserID: Variant;
begin
  if WebContext <> nil then
    Result := WebContext.Session.Values[sUserID]
end;

procedure TCustomEndUserSessionAdapter.SetUserID(const Value: Variant);
begin
  if WebContext <> nil then
    WebContext.Session.Values[sUserID] := Value;
end;

{ TBaseAdapterMultiValueField }

function TBaseAdapterMultiValueField.GetFieldValuesAdapter: TComponent;
begin
  Result := ImplGetFieldValuesAdapter;
end;

function TBaseAdapterMultiValueField.ImplGetFieldValuesAdapter: TComponent;
begin
  Result := FFieldValuesAdapter;
end;

constructor TBaseAdapterMultiValueField.Create(AOwner: TComponent);
begin
  inherited;
  FFieldValuesAdapter := TFieldValuesAdapter.Create(nil, Self);
end;

destructor TBaseAdapterMultiValueField.Destroy;
begin
  inherited;
  FFieldValuesAdapter.Destroy;
end;

procedure TBaseAdapterMultiValueField.EndValueIterator(
  OwnerData: Pointer);
begin
  // Do nothing
end;

function TBaseAdapterMultiValueField.NextValueIteration(
  var OwnerData: Pointer): Boolean;
begin
  Inc(FIteratorIndex);
  Result := FIteratorIndex < GetValueCount;
end;

function TBaseAdapterMultiValueField.StartValueIterator(
  var OwnerData: Pointer): Boolean;
begin
  FIteratorIndex := 0;
  Result := FIteratorIndex < GetValueCount;
end;

function TBaseAdapterMultiValueField.GetCurrentValue: Variant;
begin
  Result := ImplGetCurrentValue;
end;

function TBaseAdapterMultiValueField.GetValueCount: Integer;
begin
  Result := 0;
end;

function TBaseAdapterMultiValueField.HasValue(
  const AValue: Variant): Boolean;
begin
  Result := ImplHasValue(AValue);
end;

function TBaseAdapterMultiValueField.ImplGetCurrentValue: Variant;
begin
  Result := GetValues(FIteratorIndex);
end;

function TBaseAdapterMultiValueField.ImplHasValue(
  const Value: Variant): Boolean;
begin
  Result := False;
end;

function TBaseAdapterMultiValueField.GetValues(I: Integer): Variant;
begin
  Result := Unassigned;
end;

{ TCustomAdapterMultiValueField }

function TCustomAdapterMultiValueField.GetValueCount: Integer;
var
  Value: IActionFieldValue;
begin
  CheckViewAccess;
  if EchoActionFieldValue then
  begin
    Value := ActionValue;
    if Value <> nil then
      Result := Value.ValueCount
    else
      Result := 0;
  end
  else
    if Assigned(OnGetValueCount) then
    begin
      OnGetValueCount(Self, Result);
    end
    else
      Result := 0
end;

function TCustomAdapterMultiValueField.GetValues(I: Integer): Variant;
var
  Value: IActionFieldValue;
begin
  if EchoActionFieldValue then
  begin
    Value := ActionValue;
    if Value <> nil then
      Result := Value.Values[I]
    else
      Result := Unassigned;
  end
  else
    if Assigned(OnGetValues) then
      OnGetValues(Self, I, Result)
    else
      Result := Unassigned;
end;

function TCustomAdapterMultiValueField.ImplHasValue(
  const Value: Variant): Boolean;
var
  V: Variant;
  I: Integer;
begin
  CheckViewAccess;
  if Assigned(OnHasValue) then
    OnHasValue(Self, Value, Result)
  else
  begin
    Result := False;
    for I := 0 to ValueCount - 1 do
    begin
      V := Values[I];
      try
        if (not VarIsEmpty(V)) and
          (V = Value) then
        begin
          Result := True;
          break;
        end;
      except
      end;
    end;
  end;
end;

function TCustomAdapterMultiValueField.GetInputStyleType(const AAdapterMode: string): TAdapterInputHTMLElementType;
begin
  if ValuesList <> nil then
    Result := htmliCheckBox
  else
    Result := htmliTextInput;
end;

function TCustomAdapterMultiValueField.GetDisplayStyleType(const AAdapterMode: string): TAdapterDisplayHTMLElementType;
begin
  Result := htmldList
end;


procedure TCustomAdapterMultiValueField.ImplUpdateValue(
  AActionRequest: IActionRequest; AFieldIndex: Integer);
var
  I: Integer;
  S: TStrings;
begin
  CheckModifyAccess;
  if Assigned(OnUpdateValues) then
  begin
    S := TStringList.Create;
    try
      with GetActionFieldValues(AActionRequest) do
        with Values[AFieldIndex] do
          for I := 0 to ValueCount - 1 do
            S.Add(Values[I]);
      OnUpdateValues(Self, S);
    finally
      S.Free;
    end;
  end;
end;

procedure TCustomAdapterMultiValueField.DoOnValidateValue(
  AValue: IActionFieldValue;
  var AHandled: Boolean);
var
  I: Integer;
  S: TStrings;
begin
  if Assigned(OnValidateValues) then
  begin
    AHandled := False;
    S := TStringList.Create;
    try
      with AValue do
        for I := 0 to ValueCount - 1 do
          S.Add(Values[I]);
      OnValidateValues(Self, S);
    finally
      S.Free;
    end;
  end;
  if Required then
    ValidateRequiredValueField(AValue);
end;

{ TCustomAdapterImageField }

function TCustomAdapterImageField.GetDisplayStyleType(const AAdapterMode: string): TAdapterDisplayHTMLElementType;
begin
  Result := htmldImage;
end;

function TCustomAdapterImageField.GetInputStyleType(const AAdapterMode: string): TAdapterInputHTMLElementType;
begin
  Result := htmliFile;
end;

function TCustomAdapterImageField.GetAdapterImage: IInterface;
begin
  Result := Self;
end;

procedure TCustomAdapterImageField.RenderAdapterImage(
  ARequest: IImageRequest; AResponse: IImageResponse);
var
  Response: TWebResponse;
  MimeType: string;
  Image, S: TStream;
  Owned: Boolean;
  P: TStrings;
begin
  CheckViewAccess;
  Response := WebContext.Response;
  Response.ContentType := 'image/jpeg';
  if Assigned(OnGetImage) then
  begin
    Image := nil;
    Owned := True;
    S := nil;
    P := AdapterRequestParamsAsStrings(ARequest);
    try
      OnGetImage(Self, P, MimeType, Image, Owned);
      if Image <> nil then
        try
          if not Owned then
          begin
            S := TMemoryStream.Create;
            S.CopyFrom(Image, 0);
          end
          else
            S := Image;
          S.Seek(0, soFromBeginning);
        except
          if Owned then
            Image.Free;
          if Image <> S then
            S.Free;
          raise;
        end;
      Assert(MimeType <> '');
      Response.ContentType := MimeType;
      Response.ContentStream := S;
    finally
      P.Free;
    end;
  end;
  if not Response.Sent and (Response.ContentStream = nil) then
    RaiseImageNotProvided(FieldName);
end;

procedure TCustomAdapterImageField.DoOnValidateValue(
  AValue: IActionFieldValue;
  var AHandled: Boolean);
begin
  if Assigned(OnValidateFile) then
    if AValue.FileCount = 1 then
      OnValidateFile(Self, AValue.Files[0])
    else
      OnValidateFile(Self, nil);
  ValidateSingleFileField(AValue);
  if Required then
    ValidateRequiredFileField(AValue);
end;

procedure TCustomAdapterImageField.GetAdapterItemRequestParams(
  var AIdentifier: string; AParams: IAdapterItemRequestParams);
begin
  AIdentifier := MakeAdapterRequestIdentifier(Self);
  Assert(AParams.ParamValues.Count = 0);
  if Assigned(OnGetParams) then
    OnGetParams(Self, AParams.ParamValues);
end;

function ActionFieldValueAsBoolean(Value: Variant): Boolean;
begin
  try
    Result := Value
  except
    Result := False;
  end;
end;

function TCustomAdapterImageField.ImplWebImageHREF(var AHREF: string): Boolean;
begin
  if (FHREF = '') and DesigningComponent(Self) and Assigned(GetHTMLSampleImage) then
    AHREF := GetHTMLSampleImage
  else
  begin
    AHREF := FHREF;
    if Assigned(OnGetHREF) then
      OnGetHREF(Self, AHREF);
  end;
  Result := AHREF <> '';
end;

function TCustomAdapterImageField.WebImageHREF(var AHREF: string): Boolean;
begin
  Result := ImplWebImageHREF(AHREF);
end;

function TCustomAdapterImageField.ImplGetValue: Variant;
var
  S: string;
  Value: IActionFieldValue;
begin
  CheckViewAccess;
  if EchoActionFieldValue then
  begin
    Value := ActionValue;
    if (Value <> nil) and (Value.ValueCount > 0) then
      Result := ActionFieldValueAsString(Value.Values[0])
    else
      Result := '';
  end
  else
    if Assigned(OnGetImageName) then
    begin
      OnGetImageName(Self, S);
      Result := S;
    end
    else
      Result := '';
end;

procedure TCustomAdapterImageField.ImplUpdateValue(
  AActionRequest: IActionRequest; AFieldIndex: Integer);
begin
  CheckModifyAccess;
  if Assigned(OnUploadFile) then
  begin
    with GetActionFieldValues(AActionRequest) do
      with Values[AFieldIndex] do
        if FileCount = 1 then
          OnUploadFile(Self, Files[0])
  end;
end;

function TCustomAdapterImageField.ImplCheckValueChange(
  AActionRequest: IActionRequest; AFieldIndex: Integer): Boolean;
begin
  with GetActionFieldValues(AActionRequest) do
    Result := (Values[AFieldIndex].FileCount > 0) or Required;
end;

procedure TCustomAdapterImageField.CreateRequestContext(
  DispatchParams: IAdapterDispatchParams);
begin
  ImplCreateRequestContext(DispatchParams);
end;

function TCustomAdapterImageField.HandleRequest(
  DispatchParams: IAdapterDispatchParams): Boolean;
begin
  Result := ImplHandleRequest(DispatchParams);
end;

procedure TCustomAdapterImageField.ImplCreateRequestContext(
  DispatchParams: IAdapterDispatchParams);
var
  Obj: TBasicImageRequestImpl;
begin
  Obj := TBasicImageRequestImpl.Create(DispatchParams);
  TBasicImageResponseImpl.Create(Obj);
end;

function TCustomAdapterImageField.ImplHandleRequest(
  DispatchParams: IAdapterDispatchParams): Boolean;
var
  ImageRequest: IImageRequest;
  ImageResponse: IImageResponse;
begin
  Result := Supports(WebContext.AdapterRequest, IImageRequest, ImageRequest) and
    Supports(WebContext.AdapterResponse, IImageResponse, ImageResponse);
  Assert(Result);
  if Result then
    RenderAdapterImage(ImageRequest, ImageResponse);
end;

{ TCustomAdapterFileField }

function TCustomAdapterFileField.GetDisplayStyleType(const AAdapterMode: string): TAdapterDisplayHTMLElementType;
begin
  Result := htmldList;
end;

function TCustomAdapterFileField.GetInputStyleType(const AAdapterMode: string): TAdapterInputHTMLElementType;
begin
  Result := htmliFile;
end;

procedure TCustomAdapterFileField.ImplUpdateValue(
  AActionRequest: IActionRequest; AFieldIndex: Integer);
var
  F: TUpdateFileList;
begin
  CheckModifyAccess;
  if Assigned(OnUploadFiles) then
  begin
    with GetActionFieldValues(AActionRequest) do
      F := TUpdateFileList.Create(Values[AFieldIndex]);
    try
      OnUploadFiles(Self, F);
    finally
      F.Free;
    end;
  end;
end;

function TCustomAdapterFileField.GetFileNames(I: Integer): string;
var
  S: string;
  Value: IActionFieldValue;
begin
  CheckViewAccess;
  if EchoActionFieldValue then
  begin
    Value := ActionValue;
    if Value <> nil then
      Result := Value.Files[I].FileName
    else
      Result := '';
  end
  else
    if Assigned(OnGetFileNames) then
    begin
      OnGetFileNames(Self, I, S);
      Result := S;
    end
    else
      Result := ''
end;

function TCustomAdapterFileField.GetValueCount: Integer;
var
  Value: IActionFieldValue;
begin
  CheckViewAccess;
  if EchoActionFieldValue then
  begin
    Value := ActionValue;
    if Value <> nil then
      Result := Value.FileCount
    else
      Result := 0;
  end
  else
    if Assigned(OnGetFileCount) then
      OnGetFileCount(Self, Result)
    else
      Result := 0
end;

procedure TCustomAdapterFileField.DoOnValidateValue(
  AValue: IActionFieldValue;
  var AHandled: Boolean);
var
  F: TUpdateFileList;
begin
  inherited DoOnValidateValue(AValue, AHandled);
  if Assigned(OnValidateFiles) then
  begin
    F := TUpdateFileList.Create(AValue);
    try
      OnValidateFiles(Self, F);
    finally
      F.Free;
    end;
  end;
  if Required then
    ValidateRequiredFileField(AValue);
end;

function TCustomAdapterFileField.GetValues(I: Integer): Variant;
begin
  Result := GetFileNames(I);
end;

function TCustomAdapterFileField.ImplCheckValueChange(
  AActionRequest: IActionRequest; AFieldIndex: Integer): Boolean;
begin
  with GetActionFieldValues(AActionRequest) do
    Result := (Values[AFieldIndex].FileCount > 0) or Required;
end;

{ TCustomAdapterMemoField }

function TCustomAdapterMemoField.GetDisplayStyleType(const AAdapterMode: string): TAdapterDisplayHTMLElementType;
begin
  Result := htmldText;
end;

function TCustomAdapterMemoField.GetInputStyleType(const AAdapterMode: string): TAdapterInputHTMLElementType;
begin
  Result := htmliTextArea;
end;

procedure TCustomAdapterMemoField.DoOnValidateValue(
  AValue: IActionFieldValue;
  var AHandled: Boolean);
begin
  inherited DoOnValidateValue(AValue, AHandled);
  ValidateSingleFileOrValueField(AValue);
  if Required then
    ValidateRequiredFileOrValueField(AValue);
end;


function TCustomAdapterMemoField.ImplGetValue: Variant;
var
  S: string;
  Value: IActionFieldValue;
begin
  CheckViewAccess;
  if EchoActionFieldValue then
  begin
    Value := ActionValue;
    if Value <> nil then
      Result := ActionFieldValueAsString(Value.Values[0])
    else
      Result := '';
  end
  else
    if Assigned(OnGetValue) then
    begin
      OnGetValue(Self, S);
      Result := S;
    end
    else
      Result := ''
end;

procedure TCustomAdapterMemoField.ImplUpdateValue(
  AActionRequest: IActionRequest; AFieldIndex: Integer);
begin
  CheckModifyAccess;
  if Assigned(OnUpdateValue) then
    with GetActionFieldValues(AActionRequest) do
      with Values[AFieldIndex] do
        OnUpdateValue(Self, Values[0]);
  if Assigned(OnUploadFile) then
  begin
    with GetActionFieldValues(AActionRequest) do
      with Values[AFieldIndex] do
        if FileCount = 1 then
          OnUploadFile(Self, Files[0])
  end;
end;

function TCustomAdapterMemoField.ImplCheckValueChange(
  AActionRequest: IActionRequest; AFieldIndex: Integer): Boolean;
begin
  Result := inherited ImplCheckValueChange(AActionRequest, AFieldIndex);
  if not Result then
    with GetActionFieldValues(AActionRequest) do
      Result := (Values[AFieldIndex].FileCount > 0);
end;

{ TAbstractFieldValuesAdapter }

function TAbstractFieldValuesAdapter.ImplCanAddFieldClass(
  AParent: TComponent; AClass: TClass): Boolean;
begin
  Result :=
    inherited ImplCanAddFieldClass(AParent, AClass) or
    AClass.InheritsFrom(GetValueFieldClass);
end;

procedure TAbstractFieldValuesAdapter.ImplGetFieldsList(AList: TStrings);
begin
  AList.Clear;
  AList.AddObject(sValueField, TObject(GetValueFieldClass));
end;

function TAbstractFieldValuesAdapter.ImplGetScriptObject: IDispatch;
begin
  Result := TAdapterFieldValuesWrapper.Create(Self);
end;

procedure TAbstractFieldValuesAdapter.ImplEndIterator(OwnerData: Pointer);
begin
  Assert(False);
end;

function TAbstractFieldValuesAdapter.ImplNextIteration(
  var OwnerData: Pointer): Boolean;
begin
  Assert(False);
  Result := False;
end;

function TAbstractFieldValuesAdapter.ImplStartIterator(
  var OwnerData: Pointer): Boolean;
begin
  Assert(False);
  Result := False;
end;

function TAbstractFieldValuesAdapter.GetField: TObject;
begin
  Result := ImplGetField;
end;

function TAbstractFieldValuesAdapter.GetValueIndex: Integer;
begin
  Result := ImplGetValueIndex;
end;

{ TFieldValuesAdapter }

constructor TFieldValuesAdapter.Create(AOwner: TComponent; AField: TObject);
begin
  inherited Create(AOwner);
  FField := AField;
end;

function TFieldValuesAdapter.GetValueFieldClass: TComponentClass;
begin
  Result := TFieldValuesValueField;
end;

function TFieldValuesAdapter.ImplGetField: TObject;
begin
  Result := Field;
end;

function TFieldValuesAdapter.ImplGetValueIndex: Integer;
begin
  Result := FIteratorIndex;
end;

procedure TFieldValuesAdapter.ImplEndIterator(OwnerData: Pointer);
var
  Intf: IWebGetFieldValues;
begin
  if Supports(Field, IWebGetFieldValues, Intf) then
    Intf.EndValueIterator(OwnerData)
end;

function TFieldValuesAdapter.ImplNextIteration(
  var OwnerData: Pointer): Boolean;
var
  Intf: IWebGetFieldValues;
begin
  if Supports(Field, IWebGetFieldValues, Intf) then
    Result := Intf.NextValueIteration(OwnerData)
  else
    Result := False;
end;

function TFieldValuesAdapter.ImplStartIterator(
  var OwnerData: Pointer): Boolean;
var
  Intf: IWebGetFieldValues;
begin
  if Supports(Field, IWebGetFieldValues, Intf) then
    Result := Intf.StartValueIterator(OwnerData)
  else
    Result := False;
end;

{ TFieldValuesValueField }

function TFieldValuesValueField.GetDefaultFieldName: string;
begin
  Result := sValueField;
end;

function TFieldValuesValueField.GetField: TObject;
var
  Intf: IFieldValuesAdapter;
begin
  if Supports(IUnknown(Adapter), IFieldValuesAdapter, Intf) then
    Result := Intf.GetField
  else
    Result := nil;
end;

function TFieldValuesValueField.ImplAsFormatted: string;
var
  GetValuesList: IGetAdapterValuesList;
  AdapterIntf: IValuesListAdapter;
begin
  Result := '';
  if Supports(Field, IGetAdapterValuesList, GetValuesList) then
  begin
    AdapterIntf := GetValuesList.GetAdapterValuesList;
    if AdapterIntf <> nil then
      Result := AdapterIntf.GetListNameOfValue(GetValue);
  end;
  if Result = '' then
    Result := GetValue;
end;

function TFieldValuesValueField.ImplGetValue: Variant;
var
  FieldIntf: IWebGetFieldValues;
begin
  if Supports(Field, IWebGetFieldValues, FieldIntf) then
    Result := FieldIntf.GetCurrentValue
  else
    Result := Unassigned;
end;

{ TCustomAdapterBooleanField }

function TCustomAdapterBooleanField.GetDisplayStyleType(const AAdapterMode: string): TAdapterDisplayHTMLElementType;
begin
  Result := htmldText;
end;

function TCustomAdapterBooleanField.GetInputStyleType(const AAdapterMode: string): TAdapterInputHTMLElementType;
begin
  Result := htmliCheckBox;
end;

function TCustomAdapterBooleanField.ImplGetValue: Variant;
var
  B: Boolean;
  Value: IActionFieldValue;
begin
  CheckViewAccess;
  if EchoActionFieldValue then
  begin
    Value := ActionValue;
    if Value <> nil then
      Result := ActionFieldValueAsBoolean(Value.Values[0])
    else
      Result := False;
  end
  else
    if Assigned(OnGetValue) then
    begin
      OnGetValue(Self, B);
      Result := B;
    end
    else
      Result := False;
end;

function TCustomAdapterBooleanField.ImplIsEqual(
  const AValue: Variant): Boolean; 
begin
  Result := AValue = GetValue;
end;

function TCustomAdapterBooleanField.ConvertValue(AValue: IActionFieldValue): Variant;
begin
  try
    Result := Boolean(AValue.Values[0]);
  except
    Result := False;
  end;
end;

procedure TCustomAdapterBooleanField.ImplUpdateValue(
  AActionRequest: IActionRequest; AFieldIndex: Integer);
begin
  CheckModifyAccess;
  if Assigned(OnUpdateValue) then
    with GetActionFieldValues(AActionRequest) do
      OnUpdateValue(Self, ConvertValue(Values[AFieldIndex]));
end;

function TCustomAdapterBooleanField.IsEqual(
  const AValue: Variant): Boolean;
begin
  Result := ImplIsEqual(AValue);
end;

{ TCustomAdapterField }

procedure TCustomAdapterField.DoOnValidateValue(
  AValue: IActionFieldValue;
  var AHandled: Boolean);
begin
  inherited DoOnValidateValue(AValue, AHandled);
  ValidateSingleValueField(AValue);
  if Required then
    ValidateRequiredValueField(AValue);
end;

function TCustomAdapterField.ImplGetValue: Variant;
var
  Value: IActionFieldValue;
begin
  CheckViewAccess;
  if EchoActionFieldValue then
  begin
    Value := ActionValue;
    if (Value <> nil) and (Value.ValueCount > 0) then
      Result := Value.Values[0]
    else
      Result := Unassigned;
  end
  else
    if Assigned(OnGetValue) then
    begin
      OnGetValue(Self, Result);
    end
    else
      Result := Unassigned;
end;

procedure TCustomAdapterField.ImplUpdateValue(
  AActionRequest: IActionRequest; AFieldIndex: Integer);
begin
  CheckModifyAccess;
  if Assigned(OnUpdateValue) then
    with GetActionFieldValues(AActionRequest) do
      OnUpdateValue(Self, Values[AFieldIndex].Values[0]);
end;

{ TAdapterHiddenFieldsList }

procedure TAdapterHiddenFieldsList.EndIterator(OwnerData: Pointer);
begin
  // Do nothing
end;

function TAdapterHiddenFieldsList.GetCurrentIntf(
  OwnerData: Pointer): IUnknown;
begin
  Result := Fields[FIteratorIndex];
end;

function TAdapterHiddenFieldsList.NextIteration(var OwnerData: Pointer): Boolean;
begin
  Inc(FIteratorIndex);
  Result := FIteratorIndex < GetFieldCount;
end;

function TAdapterHiddenFieldsList.StartIterator(var OwnerData: Pointer): Boolean;
begin
  FIteratorIndex := 0;
  Result := FIteratorIndex < GetFieldCount;
end;

procedure TAdapterHiddenFieldsList.Add(const AName, AValue: string);
begin
  FNames.Add(AName);
  FValues.Add(AValue);
end;

procedure TAdapterHiddenFieldsList.Clear;
begin
  FNames.Clear;
  FValues.Clear;
end;

constructor TAdapterHiddenFieldsList.Create;
begin
  inherited Create;
  FNames := TStringList.Create;
  FValues := TStringList.Create;
end;

destructor TAdapterHiddenFieldsList.Destroy;
begin
  inherited;
  FNames.Free;
  FValues.Free;
end;

function TAdapterHiddenFieldsList.GetField(I: Integer): IAdapterHiddenField;
begin
  Result := TAdapterHiddenField.Create(Self, I);
end;

function TAdapterHiddenFieldsList.GetFieldCount: Integer;
begin
  Result := FNames.Count;
end;

{ TAdapterHiddenField }

constructor TAdapterHiddenField.Create(
  AHiddenFields: TAdapterHiddenFieldsList; AIndex: Integer);
begin
  inherited Create;
  FHiddenFields := AHiddenFields;
  FIndex := AIndex;
end;

function TAdapterHiddenField.GetName: string;
begin
  Result := FHiddenFields.FNames[FIndex];
end;

function TAdapterHiddenField.GetValue: string;
begin
  Result := FHiddenFields.FValues[FIndex];
end;

{ TUpdateFileList }

constructor TUpdateFileList.Create(AValue: IActionFieldValue);
begin
  inherited Create;
  FValue := AValue;
end;

function TUpdateFileList.GetCount: Integer;
begin
  Result := FValue.FileCount;
end;

function TUpdateFileList.GetFile(I: Integer): TAbstractWebRequestFile;
begin
  Result := FValue.Files[I];
end;

{ EAdapterFieldException }

constructor EAdapterFieldException.Create(const AMsg, AFieldName: string; AID: Integer);
begin
  inherited CreateFmt(AMsg, [AFieldName]);
  FFieldName := AFieldName;
  ID := AID;
end;

{ TAdapterObjectErrorsList }

constructor TAdapterObjectErrorsList.Create(AErrors: TAdapterErrorsList;
  const AName: string);
var
  I: Integer;
begin
  inherited Create;
  FErrors := AErrors;
  for I := 0 to AErrors.ErrorCount - 1 do
    if SameText(AErrors.FieldNames[I], AName) then
    begin
      SetLength(FIndexes,Length(FIndexes) + 1);
      FIndexes[Length(FIndexes) - 1] := I;
    end;
end;

procedure TAdapterObjectErrorsList.ImplDefineLabel(const AName,
  ALabel: string);
begin
  FErrors.DefineLabel(AName, ALabel);
end;

function TAdapterObjectErrorsList.ImplGetError(I: Integer): IAdapterError;
begin
  Result := FErrors.GetError(FIndexes[I]);
end;

function TAdapterObjectErrorsList.ImplGetErrorCount: Integer;
begin
  Result := Length(FIndexes);
end;

{ TBaseAdapterErrorsList }

procedure TBaseAdapterErrorsList.AddError(AException: Exception; const AObjectName: string);
begin
  // Do nothing.  Implemented by descendent
end;

procedure TBaseAdapterErrorsList.AddError(const AMessage: string; const AObjectName: string; AID: Integer);
begin
  // Do nothing.  Implemented by descendent
end;

procedure TBaseAdapterErrorsList.AddError(const AMessage: string;
  AObject: TObject; AID: Integer);
begin
  // Do nothing.  Implemented by descendent
end;

procedure TBaseAdapterErrorsList.AddError(AException: Exception;
  AObject: TObject);
begin
  // Do nothing.  Implemented by descendent
end;

procedure TBaseAdapterErrorsList.ClearErrors;
begin
  ImplClearErrors;
end;

procedure TBaseAdapterErrorsList.DefineLabel(const AName,
  ALabel: string);
begin
  ImplDefineLabel(AName, ALabel);
end;

procedure TBaseAdapterErrorsList.EndIterator(OwnerData: Pointer);
begin
  // Do nothing
end;

function TBaseAdapterErrorsList.GetCurrentIntf(
  OwnerData: Pointer): IUnknown;
begin
  Result := Errors[FIteratorIndex];
end;

function TBaseAdapterErrorsList.GetError(I: Integer): IAdapterError;
begin
  Result := ImplGetError(I);
end;

function TBaseAdapterErrorsList.GetErrorCount: Integer;
begin
  Result := ImplGetErrorCount;
end;

function TBaseAdapterErrorsList.GetObjectErrors(
  const AName: string): TObject;
begin
  Result := ImplGetObjectErrors(AName);
end;

function TBaseAdapterErrorsList.HasObjectErrors(
  const AName: string): Boolean;
begin
  Result := ImplHasObjectErrors(AName);
end;

procedure TBaseAdapterErrorsList.ImplClearErrors;
begin
  // Do nothing
end;

procedure TBaseAdapterErrorsList.ImplDefineLabel(const AName,
  ALabel: string);
begin
  // Do nothing
end;

function TBaseAdapterErrorsList.ImplGetError(
  I: Integer): IAdapterError;
begin
  Result := nil;
end;

function TBaseAdapterErrorsList.ImplGetErrorCount: Integer;
begin
  Result := 0;
end;

function TBaseAdapterErrorsList.ImplGetObjectErrors(
  const AName: string): TObject;
begin
  Result := nil;
end;

function TBaseAdapterErrorsList.ImplHasObjectErrors(
  const AName: string): Boolean;
begin
  Result := False;
end;

function TBaseAdapterErrorsList.NextIteration(var OwnerData: Pointer): Boolean;
begin
  Inc(FIteratorIndex);
  Result := FIteratorIndex < GetErrorCount;
end;

function TBaseAdapterErrorsList.StartIterator(var OwnerData: Pointer): Boolean;
begin
  FIteratorIndex := 0;
  Result := FIteratorIndex < GetErrorCount;
end;

{ EAdapterException }

constructor EAdapterException.CreateID(const AMsg: string; AID: Integer;
  Reserved: Integer);
begin
  inherited Create(AMsg);
  FID := AID;
end;

{ TAdapterLoginField }

function TAdapterLoginField.GetAdapter: TCustomLoginFormAdapter;
begin
  if (inherited Adapter <> nil) and (inherited Adapter is TCustomLoginFormAdapter) then
    Result := TCustomLoginFormAdapter(inherited Adapter)
  else
  begin
    Result := nil;
    Assert(False); // LoginFormAdapter not found
  end;
end;

{ TDefaultFieldsPagedAdapter }

procedure ListPagedAdapterActions(AAdapter: TDefaultFieldsPagedAdapter; AList: TStrings);
begin
  Assert(AList.Count = 0);
  if AAdapter.PageSize > 0 then
  begin
    AList.AddObject(sPrevPageAction, TObject(TAdapterPrevPageAction));
    AList.AddObject(sGotoPageAction, TObject(TAdapterGotoPageAction));
    AList.AddObject(sNextPageAction, TObject(TAdapterNextPageAction));
  end;
end;

procedure AddDefaultPagedAdapterActions(AAdapter: TDefaultFieldsPagedAdapter; AComponents: TWebComponentList);
var
  List: TStrings;
begin
  List := TStringList.Create;
  try
    ListPagedAdapterActions(AAdapter, List);
    AddDefaultActions(List, AComponents);
  finally
    List.Free;
  end;
end;

procedure TDefaultFieldsPagedAdapter.AddDefaultActions(AComponents: TWebComponentList);
begin
  AddDefaultPagedAdapterActions(Self, AComponents);
end;

function TDefaultFieldsPagedAdapter.GetPageCount: Integer;
begin
  Result := 1;
  if PageSize > 0 then
    Result := (RecordCount + PageSize - 1) div PageSize;
end;

function TDefaultFieldsPagedAdapter.GetRecordIndex: Integer;
begin
  if Assigned(OnGetRecordIndex) then
    OnGetRecordIndex(Self, Result)
  else
    Result := 0;
end;

procedure TDefaultFieldsPagedAdapter.SetPageSize(const Value: Integer);
begin
  if Value <> FPageSize then
  begin
    FPageSize := Value;
    Actions.ClearDefaultComponents;
  end;
end;

function TDefaultFieldsPagedAdapter.EndOfPage: Boolean;
begin
  Result := (PageSize > 0) and (RecordIndex >= PageSize * (CurrentPage + 1));
end;

function TDefaultFieldsPagedAdapter.ImplNextIteration(
  var OwnerData: Pointer): Boolean;
begin
  // Ancestor should implement
  if RecordIndex < RecordCount then
    GetNextRecord;
  Result := (not GetEOF) and (not EndOfPage);
end;

procedure TDefaultFieldsPagedAdapter.ImplGetActionsList(AList: TStrings);
begin
  ListPagedAdapterActions(Self, AList);
end;

procedure TDefaultFieldsPagedAdapter.SkipToPage;
var
  I: Integer;
begin
  if PageSize > 0 then
  begin
    I := CurrentPage * PageSize;
    while (not GetEof) and (I > 0) do
    begin
      if not GetNextRecord then
        break;
      Dec(I);
    end;
  end;
end;

function TDefaultFieldsPagedAdapter.ImplStartIterator(
  var OwnerData: Pointer): Boolean;
begin
  if GetFirstRecord then
  begin
    if PageSize > 0 then
    begin
      while (CurrentPage > 0) and (CurrentPage * PageSize >= RecordCount) do
        CurrentPage := CurrentPage - 1;
      SkipToPage;
    end;
    Result := not GetEOF;
  end
  else
    Result := False;
end;

procedure TDefaultFieldsPagedAdapter.ImplEndIterator(
 OwnerData: Pointer);
begin
  // Do nothing
end;

procedure TDefaultFieldsPagedAdapter.ImplNotifyDeactivate;
begin
  inherited;
  CurrentPage := 0;
end;

procedure TDefaultFieldsPagedAdapter.EncodeActionParams(
  AParams: IAdapterItemRequestParams);
begin
  if PageSize <> 0 then
    AParams.ParamValues.Add(Format('%s=%d', [sCurrentPage, CurrentPage]));
end;

procedure TDefaultFieldsPagedAdapter.ExtractRequestParams(ARequest: IUnknown);
var
  S: string;
  I: Integer;
  Params: IAdapterRequestParams;
begin
  if not Supports(ARequest, IAdapterRequestParams, Params) then
    Assert(False);
  S := Params.ValueOfParam(sCurrentPage);
  if S = '' then
    I := 0
  else
    try
      I := StrToInt(S);
    except
      I := 0;
    end;
  CurrentPage := I;
end;

function TDefaultFieldsPagedAdapter.GetRecordCount: Integer;
begin
  Result := 0;
  if Assigned(OnGetRecordCount) then
    OnGetRecordCount(Self, Result)
end;

function TDefaultFieldsPagedAdapter.ImplCanAddActionClass(
  AParent: TComponent; AClass: TClass): Boolean;
begin
  Result :=
    inherited ImplCanAddActionClass(AParent, AClass) or
    AClass.InheritsFrom(TCustomPagedAdapterAction);
end;

function TDefaultFieldsPagedAdapter.GetEOF: Boolean;
begin
  if Assigned(OnGetEOF) then
  begin
    Result := True;
    OnGetEOF(Self, Result);
  end
  else
    Result := RecordIndex >= RecordCount;
end;

function TDefaultFieldsPagedAdapter.GetNextRecord: Boolean;
begin
  Result := False;
  if Assigned(OnGetNextRecord) then
  begin
    OnGetNextRecord(Self, Result);
    Result := not Result;
  end;
end;

function TDefaultFieldsPagedAdapter.GetFirstRecord: Boolean;
begin
  Result := True;
  if Assigned(OnGetFirstRecord) then
  begin
    OnGetFirstRecord(Self, Result);
    Result := not Result;
  end;
end;

{ TCustomPagedAdapterAction }

function TCustomPagedAdapterAction.GetAdapter: TDefaultFieldsPagedAdapter;
begin
  if (inherited Adapter <> nil) and (inherited Adapter is TDefaultFieldsPagedAdapter) then
    Result := TDefaultFieldsPagedAdapter(inherited Adapter)
  else
    Result := nil;
end;

{ TCustomAdapterPageAction }

function TCustomAdapterPageAction.GetDisplayStyleType(const AAdapterMode: string): TAdapterActionHTMLElementType;
begin
  Result := inherited GetDisplayStyleType(AAdapterMode);
  if Result = htmlaButton then
    Result := htmlaAnchor;
end;

function TCustomAdapterPageAction.GetNewPage(
  var AValue: Integer): Boolean;
begin
  Assert(False); // Descendent must implement
  Result := False;
end;

procedure TCustomAdapterPageAction.ImplExecuteActionRequest(
  AActionRequest: IActionRequest; AActionResponse: IActionResponse);
var
  NewPage: integer;
begin
  Adapter.ExtractRequestParams(AActionRequest);
  try
    if GetNewPage(NewPage) then
      Adapter.CurrentPage := NewPage;
  except
    on E: Exception do
    begin
      Errors.AddError(E);
    end;
  end;
  if Errors.ErrorCount > 0 then
     Adapter.EchoActionFieldValues := True
end;

procedure TCustomAdapterPageAction.ImplGetAdapterItemRequestParams(
  var AIdentifier: string; Params: IAdapterItemRequestParams);
begin
  Adapter.EncodeActionParams(Params);
  inherited ImplGetAdapterItemRequestParams(AIdentifier, Params);
end;

function TCustomAdapterPageAction.ImplIsDefaultAction(
  ADisplay: TObject): Boolean;
var
  Intf: IGetAdapterDisplayCharacteristics;
  C: TAdapterDisplayCharacteristics;
begin
  Result := True;
  if Result then
    if Supports(ADisplay, IGetAdapterDisplayCharacteristics, Intf) then
    begin
      C := Intf.GetAdapterDisplayCharacteristics;
      Result := (dcMultipleRecordView in C) and (not (dcCurrentRecordView in C));
    end
    else
      Result := True;
end;

function TCustomAdapterPageAction.ImplWebEnabled: Boolean;
var
  NewPage: Integer;
begin
  Result := GetNewPage(NewPage);
end;

{ TAdapterNextPageAction }

function TAdapterNextPageAction.GetDefaultActionName: string;
begin
  Result := sNextPageAction;
end;

const
  sNextPageLabel = '&gt;&gt;';  // Do not localize
  
function TAdapterNextPageAction.GetDefaultDisplayLabel: string;
begin
  Result := sNextPageLabel;
end;

function TAdapterNextPageAction.GetNewPage(
  var AValue: Integer): Boolean;
begin
  Result := (Adapter.PageSize > 0) and
    ((Adapter.RecordCount) > Adapter.PageSize * (Adapter.CurrentPage + 1));
  if Result then
    AValue := Adapter.CurrentPage + 1;
end;

{ TCustomAdapterGotoPageAction }

function TCustomAdapterGotoPageAction.GetDefaultActionName: string;
begin
  Result := sGotoPageAction;
end;

function TCustomAdapterGotoPageAction.GetDisplayStyleType(const AAdapterMode: string): TAdapterActionHTMLElementType;
begin
  Result := inherited GetDisplayStyleType(AAdapterMode);
  if Result = htmlaButton then
    Result := htmlaAnchor;
end;

function TCustomAdapterGotoPageAction.GetItemCount: Integer;
begin
  Result := Adapter.PageCount;
end;

procedure TCustomAdapterGotoPageAction.ImplExecuteActionRequest(
  AActionRequest: IActionRequest; AActionResponse: IActionResponse);
begin
  Adapter.ExtractRequestParams(AActionRequest);
end;

procedure TCustomAdapterGotoPageAction.ImplGetAdapterItemRequestParams(
  var AIdentifier: string; Params: IAdapterItemRequestParams);
begin
  Params.ParamValues.Add(Format('%s=%d', [sCurrentPage, ItemIndex]));
  inherited ImplGetAdapterItemRequestParams(AIdentifier, Params);
end;

function TCustomAdapterGotoPageAction.ImplGetDisplayLabel: string;
begin
  if Assigned(OnGetPageName) then
    OnGetPageName(Self, ItemIndex, Result)
  else
    Result := Format('%d', [ItemIndex + 1]);
end;

function TCustomAdapterGotoPageAction.ImplIsDefaultAction(
  ADisplay: TObject): Boolean;
var
  Intf: IGetAdapterDisplayCharacteristics;
  C: TAdapterDisplayCharacteristics;
begin
  Result := True;
  if Result then
    if Supports(ADisplay, IGetAdapterDisplayCharacteristics, Intf) then
    begin
      C := Intf.GetAdapterDisplayCharacteristics;
      Result := (dcMultipleRecordView in C) and (not (dcCurrentRecordView in C));
    end
    else
      Result := True;
end;

function TCustomAdapterGotoPageAction.ImplGetIsAdapterActionList: Boolean;
begin
  Result := Adapter.PageSize > 0;
end;

function TCustomAdapterGotoPageAction.ImplWebEnabled: Boolean;
begin
  Result := ItemIndex <> Adapter.CurrentPage;
end;

{ TAdapterPrevPageAction }

function TAdapterPrevPageAction.GetDefaultActionName: string;
begin
  Result := sPrevPageAction;
end;

function TAdapterPrevPageAction.GetNewPage(
  var AValue: Integer): Boolean;
begin
  Result := (Adapter.RecordCount > 0) and (Adapter.CurrentPage > 0);
  if Result then
    AValue := Adapter.CurrentPage - 1;
end;

const
  sPrevPageLabel = '&lt;&lt;'; // Do not localize
function TAdapterPrevPageAction.GetDefaultDisplayLabel: string;
begin
  Result := sPrevPageLabel;
end;

function TCustomAdapter.GetIteratorIndex: Integer;
begin
  Result := ImplGetIteratorIndex;
end;

function TCustomAdapter.ImplGetIteratorIndex: Integer;
begin
  Result := FIteratorIndex;
end;

function TCustomAdapter.ImplInIterator: Boolean;
begin
  Result := FInIterator;
end;

function TCustomAdapter.InIterator: Boolean;
begin
  Result := ImplInIterator;
end;

procedure TCustomAdapter.EncodeActionParams(
  AParams: IAdapterItemRequestParams);
begin
  // Do nothing.  Descendent may implement.
end;

procedure TCustomAdapter.ExtractRequestParams(ARequest: IUnknown);
begin
  // Do nothing.  Descendent may implement.
end;

function TAdapterNamedField.IsFieldNameStored: Boolean;
begin
  Result := FFieldName <> '';
end;

function TCustomAdapterAction.IsActionNameStored: Boolean;
begin
  Result := FActionName <> '';
end;

function TBaseAdapterAction.GetIteratorIndex: Integer;
begin
  Result := ImplGetIteratorIndex;
end;

function TBaseAdapterAction.ImplGetIteratorIndex: Integer;
begin
  Result := FIteratorIndex;
end;

function TBaseAdapterAction.ImplInIterator: Boolean;
begin
  Result := FInIterator;
end;

function TBaseAdapterAction.InIterator: Boolean;
begin
  Result := ImplInIterator;
end;

initialization
  RegisterAdapterRequestIdentifier(sActionRequest);
  RegisterAdapterRequestIdentifier(sActionRequestLong);
  RegisterAdapterRequestIdentifier(sImageRequest);
  RegisterClass(TAdapterFields);
  RegisterClass(TAdapterActions);
  RegisterClass(TAdapterDefaultFields);
  RegisterClass(TAdapterDefaultActions);
end.


