
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1999 Inprise Corporation          }
{                                                       }
{*******************************************************}

unit MidItems;

interface

uses Classes, HTTPApp, Db, DbClient, Midas,
  XMLBrokr, WebComp, PagItems, MidProd;

type

  IMidasWebDataSet = interface
  ['{1E494CD4-D598-11D2-AF8C-00C04FB16EC3}']
    function FieldCount: Integer;
    function Fields: TFields;
    procedure FetchParams;
    function Params: TParams;
    function ParamCount: Integer;
    procedure AddOnDataChange(const Value: TNotifyEvent);
    procedure RemoveOnDataChange(const Value: TNotifyEvent);
  end;

  TXMLDataSet = class;

  IDataSetComponent = interface
  ['{D1AE355D-F1C3-11D2-AFB3-00C04FB16EC3}']
    function GetXMLBroker: TXMLBroker;
    function GetDataSet: IMidasWebDataSet;
    function GetXMLDataSet: TXMLDataSet;
    property DataSet: IMidasWebDataSet read GetDataSet;
    property XMLBroker: TXMLBroker read GetXMLBroker;
    property XMLDataSet: TXMLDataSet read GetXMLDataSet;
  end;

  IQueryFields = interface
  ['{DADD9F42-FD2B-11D2-AA78-00A024C11562}']
    procedure ValidateDataSet;
    function IsParamInUse(AName: string): Boolean;
    procedure GetParamsList(AList: TStrings);
  end;
  
  IValidateFields = interface
  ['{10A1C310-2E47-11D3-B00E-00C04FB16EC3}']
    function GetEnableValidateFields: Boolean;
    procedure SetEnableValidateFields(Value: Boolean);
    function ValidateFields(AddIntf: IAddScriptElements): Boolean;
    property EnableValidateFields: Boolean read GetEnableValidateFields
      write SetEnableValidateFields;
  end;

  IValidateField = interface
  ['{10A1C310-2E47-11D3-B00E-00C04FB16EC3}']
    function ValidateField(DataSet: IMidasWebDataSet; AddIntf: IAddScriptElements): Boolean;
  end;

  IDataSetFields = interface
  ['{394C5DD4-F252-11D2-AA55-00A024C11562}']
    procedure ValidateDataSet;
    procedure GetFieldsList(AList: TStrings);
    function IsFieldInUse(AName: string): Boolean;
    function HasStatusField: Boolean;
    function GetVisibleFields: TWebComponentList;
    property VisibleFields: TWebComponentList read GetVisibleFields;
  end;

  IRestoreDefaults = interface
  ['{394C5DD3-F252-11D2-AA55-00A024C11562}']
    procedure RestoreDefaults;
  end;

  IHTMLField = interface
  ['{C72355D9-FE5C-11D2-AFC5-00C04FB16EC3}']
    function GetHTMLControlName: string;
    property HTMLControlName: string read GetHTMLControlName;
  end;

  IQueryField = interface(IHTMLField)
  ['{7C321115-FCFB-11D2-AFC3-00C04FB16EC3}']
    function GetParamName: string;
    procedure SetParamName(AParamName: string);
    function GetText: string;
    procedure SetText(const Value: string);
    property ParamName: string read GetParamName write SetParamName;
    property Text: string read GetText write SetText;
  end;

  IDataSetField = interface(IHTMLField)
  ['{394C5DD5-F252-11D2-AA55-00A024C11562}']
    procedure SetFieldName(AFieldName: string);
    function GetFieldName: string;
    function GetRowSetFieldAttributes(const FieldVarName: string): string;
    property FieldName: string read GetFieldName write SetFieldName;
  end;

  IStatusField = interface(IHTMLField)
  ['{DA9A7341-FE79-11D2-AFC5-00C04FB16EC3}']
  end;

  IXMLDisplay = interface
  ['{394C5DD6-F252-11D2-AA55-00A024C11562}']
    function GetXMLDisplayName: string;
    function GetXMLRowSetName: string;
    function GetIsMultipleRecordView: Boolean;
    property XMLRowSetName: string read GetXMLRowSetName;
    property XMLDisplayName: string read GetXMLDisplayName;
    property IsMultipleRecordView: Boolean read GetIsMultipleRecordView;
  end;

  IXMLDisplayReference = interface
  ['{675ABA92-F660-11D2-AA59-00A024C11562}']
    function GetXMLDisplayComponent: TComponent;
    property XMLDisplayComponent: TComponent read GetXMLDisplayComponent;
  end;

  IHTMLForm = interface
  ['{394C5DD7-F252-11D2-AA55-00A024C11562}']
    function GetHTMLFormName: string;
    function GetHTMLFormVarName: string;
    property HTMLFormName: string read GetHTMLFormName;
    property HTMLFormVarName: string read GetHTMLFormVarName;
  end;

  IFormatColumn = interface
  ['{3417E2F0-22A0-11D3-B003-00C04FB16EC3}']
    function FormatColumnHeading: string;
    function FormatColumnData(Content: string): string;
  end;

  IQueryForm = interface
  ['{95097A4B-3A12-11D3-B01B-00C04FB16EC3}']
  end;

  TWebDataInput = class;
  TWebDataInputClass = class of TWebDataInput;

  TXMLData = class(TObject)
  private
    FParent: TComponent;
    FXMLBroker: TXMLBroker;
    FOnChange: TNotifyEvent;
  protected
    procedure Changed;
    procedure ChangedXMLBroker; virtual;
    procedure SetXMLBroker(const Value: TXMLBroker); virtual;
    function GetXMLBroker: TXMLBroker; virtual;
  public
    procedure Notification(AComponent: TComponent;
      Operation: TOperation); virtual;
    constructor Create(AParent: TComponent);
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
    property Parent: TComponent read FParent;
    property XMLBroker: TXMLBroker read GetXMLBroker write SetXMLBroker;
  end;

  TXMLDataSet = class(TXMLData, INotifyConnectionChange)
  private
    FDataSetField: string;
    FDataSet: IMidasWebDataSet;
    FDataSetPath: TStrings;
    FDiscardDataSetList: IInterfaceList;
  protected
    { IUnknown }
    function QueryInterface(const IID: TGUID; out Obj): HResult; virtual; stdcall;
    function _AddRef: Integer; stdcall;
    function _Release: Integer; stdcall;
    { INotifyConnectionChange }
    procedure ConnectionChange(Sender: TComponent; Connecting: Boolean);

    procedure SetXMLBroker(const Value: TXMLBroker); override;
    function FindDataSet: IMidasWebDataSet;
    function CompareXMLData(XMLDataSet: TXMLDataSet): Boolean;
    procedure ChangedXMLBroker; override;
    procedure ChangedDataSetField; virtual;
    procedure WrapperDataChange(Sender: TObject);
    //procedure AssignTo(Dest: TPersistent); override;
    procedure SetDataSetField(const Value: string);
    function GetDataSet: IMidasWebDataSet;
    function CreateDataSet: IMidasWebDataSet;
    function GetDataSetPath: TStrings;
    function GetDataSetField: string; virtual;
    property Parent: TComponent read FParent;
  public
    constructor Create(AParent: TComponent);
    destructor Destroy; override;
    property DataSet: IMidasWebDataSet read GetDataSet;
    property DataSetPath: TStrings read GetDataSetPath;
    property DataSetField: string read GetDataSetField write SetDataSetField;
  end;

  TXMLDataSetParent = class(TXMLDataSet)
  private
    FUseParent: Boolean;
  protected
    function GetDataSetField: string; override;
    function GetXMLBroker: TXMLBroker; override;
    procedure SetUseParent(const Value: Boolean);
    procedure ChangedDataSetField; override;
    procedure ChangedXMLBroker; override;
    procedure ChangedUseParent; virtual;
    function ParentDataSetField: string;
    function ParentXMLDataSet: TXMLDataSet;
    function ParentXMLBroker: TXMLBroker;
    property UseParent: Boolean read FUseParent write SetUseParent;
  end;

  TXMLDataParent = class(TXMLData)
  private
    FUseParent: Boolean;
  protected
    procedure ChangedUseParent; virtual;
    function GetXMLBroker: TXMLBroker; override;
    procedure SetUseParent(const Value: Boolean);
    procedure ChangedXMLBroker; override;
    function ParentXMLBroker: TXMLBroker;
  published
    property UseParent: Boolean read FUseParent write SetUseParent;
  end;

  TXMLDisplay = class(TObject)
  private
    FParent: TComponent;
    FDisplayComponent: TComponent;
    FOnChange: TNotifyEvent;
  protected
    procedure Changed;
    procedure SetDisplayComponent(const Value: TComponent);
    function GetDisplayComponent: TComponent; virtual;
    procedure ChangedDisplayComponent; virtual;
  public
    procedure Notification(AComponent: TComponent;
      Operation: TOperation); virtual;
    constructor Create(AParent: TComponent);
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
    property Parent: TComponent read FParent;
    property DisplayComponent: TComponent read GetDisplayComponent write SetDisplayComponent;
  end;

  TXMLDisplayParent = class(TXMLDisplay)
  private
    FUseParent: Boolean;
  protected
    function GetDisplayComponent: TComponent; override;
    procedure SetUseParent(const Value: Boolean);
    procedure ChangedDisplayComponent; override;
    procedure ChangedUseParent; virtual;
  public
    constructor Create(AParent: TComponent);
  published
    property UseParent: Boolean read FUseParent write SetUseParent default True;
  end;

  TWebForm = class(TComponent, IWebComponent, IWebContent, IWebComponentEditor,
    IScriptComponent, IGetWebComponentList, IHTMLForm)
  private
    FContainer: TWebComponentList;
    FWebComponents: TWebComponentList;
    FCustom: string;
    FStyle: string;
    FStyleRule: string;
    FWebParent: TComponent;
    FLayoutAttributes: TLayoutAttributes;
  protected
    procedure GetChildren(Proc: TGetChildProc; Root: TComponent); override;
    procedure SetChildOrder(Component: TComponent; Order: Integer); override;
    { IWebComponentEditor }
    function CanAddClass(AParent: TComponent; AClass: TClass): Boolean;
    function ImplCanAddClass(AParent: TComponent; AClass: TClass): Boolean; virtual; abstract;
    { IWebComponent }
    function GetIndex: Integer;
    procedure SetIndex(Value: Integer);
    procedure SetContainer(Container: TWebComponentContainer);
    function GetContainer: TWebComponentContainer;
    procedure SetComponentList(List: TObject);

    { IWebContent }
    function Content(Options: TWebContentOptions; Layout: TLayout): string;
    function ImplContent(Options: TWebContentOptions; Layout: TLayout): string; virtual; abstract;

    procedure ReadState(Reader: TReader); override;
    procedure SetParentComponent(AParent: TComponent); override;
    { IGetWebComponentList }
    function GetComponentList: TObject;
    function GetDefaultComponentList: TObject;

    { IScriptComponent }
    procedure AddElements(AddIntf: IAddScriptElements);
    procedure ImplAddElements(AddIntf: IAddScriptElements); virtual;
    function GetSubComponents: TObject;

    { IHTMLForm }
    function GetHTMLFormName: string;
    function GetHTMLFormVarName: string;

    function GetVisibleFields: TWebComponentList;
    function GetLayoutAttributes: TLayoutAttributes; virtual;
    procedure SetWebParent(const Value: TComponent);
    property VisibleFields: TWebComponentList read GetVisibleFields;
  public
    constructor Create(AComponent: TComponent); override;
    destructor Destroy; override;
    function GetParentComponent: TComponent; override;
    function HasParent: Boolean; override;
    property WebComponents: TWebComponentList read FWebComponents;
    property Style: string read FStyle write FStyle;
    property Custom: string read FCustom write FCustom;
    property StyleRule: string read FStyleRule write FStyleRule;
  end;

  TFormMethod = (fmPost, fmGet);
  TCustomQueryForm = class(TWebForm, IQueryForm)
  private
    FAction: string;
    FMethod: TFormMethod;
    FAssignStrings: TStrings;
  protected
    { IWebComponentEditor implementation }
    function ImplCanAddClass(AParent: TComponent; AClass: TClass): Boolean; override;
    { IScriptComponent implementation }
    procedure ImplAddElements(AddIntf: IAddScriptElements); override;
    { IWebContent implementation }
    function ImplContent(Options: TWebContentOptions; ParentLayout: TLayout): string; override;

    function GetHTMLFormTag(Options: TWebContentOptions): string; virtual;
    function MethodString: string;
    procedure AssignStringsCallback(AComponent: TComponent);
  public
    constructor Create(AOwner: TComponent); override;
    procedure AssignStrings(Value: TStrings);
    property Action: string read FAction write FAction;
    property Method: TFormMethod read FMethod write FMethod;
  end;

  TQueryForm = class(TCustomQueryForm)
  published
    property Action;
    property Method;
    property Style;
    property Custom;
    property StyleRule;
  end;

  TDataForm = class(TWebForm)
  protected
    { IWebComponentEditor implementation }
    function ImplCanAddClass(AParent: TComponent; AClass: TClass): Boolean; override;
    { IWebContent implementatation }
    function ImplContent(Options: TWebContentOptions; ParentLayout: TLayout): string; override;

    function GetHTMLFormTag(Options: TWebContentOptions): string; virtual;
  published
    property Style;
    property Custom;
    property StyleRule;
  end;

  TWebControlGroup = class(TComponent, IWebComponent, IGetWebComponentList, IWebComponentEditor,
    IScriptComponent, IWebContent)
  private
    FContainer: TWebComponentList;
    FWebComponents: TWebComponentList;
    FDefaultField: Boolean;
    FDefaultWebComponents: TWebComponentList;
    FWebParent: TComponent;
  protected
    procedure SetWebParent(const Value: TComponent);
    procedure GetChildren(Proc: TGetChildProc; Root: TComponent); override;
    procedure SetChildOrder(Component: TComponent;
     Order: Integer); override;
    { IScriptComponent }
    procedure AddElements(AddIntf: IAddScriptElements);
    function GetSubComponents: TObject; // Object implementing IWebComponentContainer
    function ImplGetSubComponents: TObject; virtual;
    procedure ImplAddElements(AddIntf: IAddScriptElements); virtual;
    { IWebContent }
    function Content(Options: TWebContentOptions; ParentLayout: TLayout): string;
    function ImplContent(Options: TWebContentOptions; ParentLayout: TLayout): string; virtual;
    { IWebComponent }
    function GetIndex: Integer;
    procedure SetIndex(Value: Integer);
    procedure SetContainer(Container: TWebComponentContainer);
    function GetContainer: TWebComponentContainer;
    procedure SetComponentList(List: TObject);
    { IGetWebComponentList }
    function GetComponentList: TObject;
    function GetDefaultComponentList: TObject;
    { IWebComponentEditor }
    function CanAddClass(AParent: TComponent; AClass: TClass): Boolean;
    function ImplCanAddClass(AParent: TComponent; AClass: TClass): Boolean; virtual;

    procedure ReadState(Reader: TReader); override;
    procedure SetParentComponent(AParent: TComponent); override;
    function GetLayoutAttributes: TLayoutAttributes; virtual;
    property DefaultWebComponents: TWebComponentList read FDefaultWebComponents write FDefaultWebComponents;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function GetParentComponent: TComponent; override;
    function HasParent: Boolean; override;
    property WebFieldControls: TWebComponentList read FWebComponents;
  end;

  TCustomLayoutGroup = class(TWebControlGroup)
  private
    FDisplayColumns: Integer;
    FStyle: string;
    FCustom: string;
    FStyleRule: string;
    FLayoutAttributes: TLayoutAttributes;
  protected
    { IWebComponentEditor implementation }
    function ImplCanAddClass(AParent: TComponent; AClass: TClass): Boolean; override;
    { IWebContent implementation }
    function ImplContent(Options: TWebContentOptions; ParentLayout: TLayout): string; override;

    function GetLayoutAttributes: TLayoutAttributes; override;
  public
    constructor Create(AComponent: TComponent); override;
    destructor Destroy; override;
    property DisplayColumns: Integer read FDisplayColumns write FDisplayColumns;
    property Style: string read FStyle write FStyle;
    property Custom: string read FCustom write FCustom;
    property StyleRule: string read FStyleRule write FStyleRule;
  end;

  TLayoutGroup = class(TCustomLayoutGroup)
  published
    property DisplayColumns;
    property Style;
    property Custom;
    property StyleRule;
  end;

  TXMLDisplayGroup = class(TWebControlGroup,
    IDataSetComponent, IDataSetFields, IXMLDisplay, IValidateFields)
  private
    FXMLDataSet: TXMLDataSet;
    FEnableValidateFields: Boolean;
  protected
    function GetDataSetField: string;
    procedure SetDataSetField(const Value: string);
    procedure SetXMLBroker(const Value: TXMLBroker);
    procedure XMLDataChange(Sender: TObject); virtual;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    { IScriptComponent implementation }
    function ImplGetSubComponents: TObject; override;
    procedure ImplAddElements(AddIntf: IAddScriptElements); override;
    { IXMLDisplay }
    function GetXMLDisplayName: string;
    function GetXMLRowSetName: string;
    function GetIsMultipleRecordView: Boolean;
    function ImplIsMultipleRecordView: Boolean; virtual;
    { IDataSetComponent }
    function GetDataSet: IMidasWebDataSet;
    function GetXMLBroker: TXMLBroker;
    function GetXMLDataSet: TXMLDataSet;

    { IDataSetFields }
    procedure GetFieldsList(List: TStrings); virtual;
    function IsFieldInUse(AName: string): Boolean;
    function GetVisibleFields: TWebComponentList;
    function HasStatusField: Boolean;
    procedure ValidateDataSet;

    { IValidateFields }
    function ValidateFields(AddIntf: IAddScriptElements): Boolean;
    function GetEnableValidateFields: Boolean;
    procedure SetEnableValidateFields(Value: Boolean);

    procedure CreateDefaultFields; virtual;
    function FindField(const AName: string): TComponent;
    property XMLDataSet: TXMLDataSet read FXMLDataSet;
    property EnableValidateFields: Boolean read GetEnableValidateFields write SetEnableValidateFields;
  public
    constructor Create(AComponent: TComponent); override;
    destructor Destroy; override;
    property VisibleFields: TWebComponentList read GetVisibleFields;
  published
    property XMLBroker: TXMLBroker read GetXMLBroker write SetXMLBroker;
    property XMLDataSetField: string read GetDataSetField write SetDataSetField;
  end;

  TGridRowAttributes = class(TPersistent)
  private
    FAlign: THTMLAlign;
    FBgColor: THTMLBgColor;
    FVAlign: THTMLVAlign;
    FStyle: string;
    FStyleRule: string;
    FCustom: string;
    FParent: TComponent;
  protected
    procedure AssignTo(Dest: TPersistent); override;
  public
    constructor Create(AParent: TComponent);
    property Parent: TComponent read FParent;
  published
    property Align: THTMLAlign read FAlign write FAlign default haDefault;
    property BgColor: THTMLBgColor read FBgColor write FBgColor;
    property VAlign: THTMLVAlign read FVAlign write FVAlign default haVDefault;
    property Style: string read FStyle write FStyle;
    property StyleRule: string read FStyleRule write FStyleRule;
    property Custom: string read FCustom write FCustom;
  end;

  TGridAttributes = class(TPersistent)
  private
    FAlign: THTMLAlign;
    FBorder: Integer;
    FBgColor: THTMLBgColor;
    FCellSpacing: Integer;
    FCellPadding: Integer;
    FStyle: string;
    FStyleRule: string;
    FCustom: string;
    FParent: TComponent;
  protected
    procedure AssignTo(Dest: TPersistent); override;
  public
    constructor Create(AParent: TComponent);
    property Parent: TComponent read FParent;
  published
    property Align: THTMLAlign read FAlign write FAlign default haDefault;
    property BgColor: THTMLBgColor read FBgColor write FBgColor;
    property Border: Integer read FBorder write FBorder default 1;
    property CellSpacing: Integer read FCellSpacing write FCellSpacing default -1;
    property CellPadding: Integer read FCellPadding write FCellPadding default -1;
    property Style: string read FStyle write FStyle;
    property StyleRule: string read FStyleRule write FStyleRule;
    property Custom: string read FCustom write FCustom;
  end;

  TCustomDataGrid = class(TXMLDisplayGroup, IDataSetComponent)
  private
    FDisplayRows: Integer;
    FTableAttributes: TGridAttributes;
    FHeadingAttributes: TGridRowAttributes;
    FRowAttributes: TGridRowAttributes;
  protected
    { IWebComponentEditor implementation }
    function ImplCanAddClass(AParent: TComponent; AClass: TClass): Boolean; override;
    { IWebContent implementation }
    function ImplContent(Options: TWebContentOptions; ParentLayout: TLayout): string; override;
    { IScriptContent implementation }
    procedure ImplAddElements(AddIntf: IAddScriptElements); override;
    { IXMLDisplay implementation }
    function ImplIsMultipleRecordView: Boolean; override;

    function FormatTable(Layout: TLayoutWebContent;
      Options: TWebContentOptions): string;
    procedure SetTableAttributes(const Value: TGridAttributes);
    procedure SetHeadingAttributes(
      const Value: TGridRowAttributes);
    procedure SetRowAttributes(
      const Value: TGridRowAttributes);
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property DisplayRows: Integer read FDisplayRows write FDisplayRows default 4;
    property TableAttributes: TGridAttributes read FTableAttributes
      write SetTableAttributes;
    property HeadingAttributes: TGridRowAttributes read FHeadingAttributes
      write SetHeadingAttributes;
    property RowAttributes: TGridRowAttributes read FRowAttributes
      write SetRowAttributes;
  end;

  TDataGrid = class(TCustomDataGrid)
  published
    property DisplayRows;
    property TableAttributes;
    property HeadingAttributes;
    property RowAttributes;
  end;

  TCustomFieldGroup = class(TXMLDisplayGroup)
  private
    FStyle: string;
    FCustom: string;
    FStyleRule: string;
    FLayoutAttributes: TLayoutAttributes;
  protected
    { IWebContent implementation }
    function ImplContent(Options: TWebContentOptions; ParentLayout: TLayout): string; override;
    function GetLayoutAttributes: TLayoutAttributes; override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property Custom: string read FCustom write FCustom;
    property Style: string read FStyle write FStyle;
    property StyleRule: string read FStyleRule write FStyleRule;
  end;

  TQueryFieldGroup = class(TCustomFieldGroup, IQueryFields)
  protected
    { IWebComponentEditor implementation }
    function ImplCanAddClass(AParent: TComponent; AClass: TClass): Boolean;override;
    { IQueryFields }
    function IsParamInUse(AName: string): Boolean;
    procedure GetParamsList(List: TStrings);

    function FindParam(const AName: string): TComponent;
  published
    property Custom;
    property Style;
    property StyleRule;
  end;

  TFieldGroup = class(TCustomFieldGroup)
  protected
    { IScriptContent implementation }
    procedure ImplAddElements(AddIntf: IAddScriptElements); override;
    { IWebComponentEditor implementation }
    function ImplCanAddClass(AParent: TComponent; AClass: TClass): Boolean;override;
  published
    property Custom;
    property Style;
    property StyleRule;
  end;

  TCaptionPosition = (capLeft, capRight, capAbove, capBelow);

  TCaptionAttributes = class(TPersistent)
  private
    FParent: TComponent;
    FStyle: string;
    FCustom: string;
    FStyleRule: string;
  public
    constructor Create(AParent: TComponent);
    property Parent: TComponent read FParent;
  published
    property Style: string read FStyle write FStyle;
    property Custom: string read FCustom write FCustom;
    property StyleRule: string read FStyleRule write FStyleRule;
  end;

  TWebDataDisplay = class(TComponent, IWebComponent, IWebContent, IHTMLField)
  private
    FWebComponents: TWebComponentList;
    FWebParent: TComponent;
    FDefaultField: Boolean;
    FCaption: string;
    FCaptionPosition: TCaptionPosition;
    FCaptionAttributes: TCaptionAttributes;
    FTabIndex: Integer;
    FCustom: string;
    FStyle: string;
    FLayoutAttributes: TLayoutAttributes;
    FStyleRule: string;
  protected
    { IWebComponent }
    function GetIndex: Integer;
    procedure SetIndex(Value: Integer);
    procedure SetContainer(Container: TWebComponentContainer);
    function GetContainer: TWebComponentContainer;
    procedure SetComponentList(List: TObject);
    { IWebContent }
    function Content(Options: TWebContentOptions; ParentLayout: TLayout): string;
    function ImplContent(Options: TWebContentOptions; ParentLayout: TLayout): string; virtual;
    { IHTMLField }
    function GetHTMLControlName: string;
    function ImplGetHTMLControlName: string; virtual;

    function ControlContent(Options: TWebContentOptions): string; virtual; abstract;
    function LabelContent: string; virtual;
    function GetCaption: string; virtual;
    procedure SetCaption(Value: string); virtual;

    function EventContent(Options: TWebContentOptions): string; virtual;

    procedure SetWebParent(Value: TComponent);
    procedure ReadState(Reader: TReader); override;
    procedure SetParentComponent(AParent: TComponent); override;
    function GetHTMLForm: IHTMLForm;
    function GetXmlDisplayName: string;
    function GetXmlRowSetName: string;
    procedure SetCaptionAttributes(const Value: TCaptionAttributes);
    function FormatCaption: string; virtual;
    function GetLayoutAttributes: TLayoutAttributes; virtual;
    property LayoutAttributes: TLayoutAttributes read FLayoutAttributes;
    property CaptionPosition: TCaptionPosition
      read FCaptionPosition write FCaptionPosition default capLeft;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    class function IsColumn: Boolean; virtual;
    class function IsQueryField: Boolean; virtual;
    function GetParentComponent: TComponent; override;
    function HasParent: Boolean; override;
    property Caption: string read GetCaption write FCaption;
    property TabIndex: Integer read FTabIndex write FTabIndex default -1;
    property Custom: string read FCustom write FCustom;
    property Style: string read FStyle write FStyle;
    property StyleRule: string read FStyleRule write FStyleRule;
    property CaptionAttributes: TCaptionAttributes
      read FCaptionAttributes write SetCaptionAttributes;
  end;

  TWebDataDisplayClass = class of TWebDataDisplay;

  TWebDataInput = class(TWebDataDisplay, IRestoreDefaults, IDataSetField,
    IValidateField)
  private
    FFieldName: string;
    FParamName: string;
  protected
    { IRestoreDefaults }
    procedure RestoreDefaults;
    procedure ImplRestoreDefaults; virtual;
    { IValidateField }
    function ValidateField(DataSet: IMidasWebDataSet; AddIntf: IAddScriptElements): Boolean;
    { IDataSetField }
    procedure SetFieldName(Value: string);
    function GetFieldName: string;
    function ImplGetFieldName: string; virtual;
    function GetRowSetFieldAttributes(const FieldVarName: string): string;
    function ImplGetRowSetFieldAttributes(const FieldVarName: string): string; virtual;

    function ImplGetHTMLControlName: string; override;
    procedure RestoreFieldDefaults(AField: TField); virtual;
    function FindAssociatedField(DataSet: IMidasWebDataSet): TField; virtual;
    function GetParamName: string; virtual;
    procedure SetParamName(Value: string);
    function GetCaption: string; override;
    function EventContent(Options: TWebContentOptions): string; override;
    procedure SetCaption(Value: string); override;
    property ParamName: string read GetParamName write SetParamName;
  public
    property FieldName: string read GetFieldName write SetFieldName;
  end;

  TWebStatus = class(TWebDataDisplay, IStatusField)
  private
    FDisplayWidth: Integer;
  protected
    { IStatusField implementation }
    function ImplGetHTMLControlName: string; override;

    function GetCaption: string; override;
    function ControlContent(Options: TWebContentOptions): string; override;
  public
    class function Identifier: string;
    constructor Create(AOwner: TComponent); override;
    property DisplayWidth: Integer read FDisplayWidth write FDisplayWidth default 1;
    property Caption;
    property CaptionAttributes;
    property CaptionPosition;
  end;

  TWebStatusClass = class of TWebStatus;

  TFieldStatus = class(TWebStatus)
  published
    property Caption;
    property CaptionAttributes;
    property CaptionPosition;
    property Style;
    property Custom;
    property StyleRule;
  end;

  TStatusColumn = class(TWebStatus)
  public
    class function IsColumn: Boolean; override;
  published
    property Caption;
    property CaptionAttributes;
    property Style;
    property Custom;
    property StyleRule;
  end;

  TWebTextInput = class(TWebDataInput)
  private
    FDisplayWidth: Integer;
    FReadOnly: Boolean;
  protected
    procedure AddAttributes(var Attrs: string); virtual;
    function ControlContent(Options: TWebContentOptions): string; override;
    procedure RestoreFieldDefaults(AField: TField); override;
    function ImplGetRowSetFieldAttributes(const FieldVarName: string): string; override;
  public
    constructor Create(AOwner: TComponent); override;
    property DisplayWidth: Integer read FDisplayWidth write FDisplayWidth;
    property ReadOnly: Boolean read FReadOnly write FReadOnly default False;
    property Style;
    property Custom;
    property StyleRule;
  end;

  TFieldText = class(TWebTextInput)
  published
    property DisplayWidth;
    property ReadOnly;
    property Caption;
    property CaptionAttributes;
    property CaptionPosition;
    property FieldName;
    property TabIndex;
    property Style;
    property Custom;
    property StyleRule;
  end;

  TTextColumn = class(TWebTextInput)
  public
    class function IsColumn: Boolean; override;
  published
    property DisplayWidth;
    property ReadOnly;
    property Caption;
    property CaptionAttributes;
    property FieldName;
    property TabIndex;
    property Style;
    property Custom;
    property StyleRule;
  end;

  TQueryText = class(TWebTextInput, IQueryField)
  private
    FText: string;
    FMaxWidth: integer;
  protected
    function GetText: string;
    procedure AddAttributes(var Attrs: string); override;
    procedure SetText(const Value: string);
  public
    class function IsQueryField: Boolean; override;
    constructor Create(AOwner: TComponent); override;
  published
    property ParamName;
    property DisplayWidth;
    property ReadOnly;
    property Caption;
    property CaptionAttributes;
    property CaptionPosition;
    property FieldName;
    property TabIndex;
    property Style;
    property Custom;
    property StyleRule;
    property Text: string read GetText write SetText;
    property MaxWidth: Integer read FMaxWidth write FMaxWidth default -1;
  end;

  TTextAreaWrap = (wrOff, wrPhysical, wrVirtual);

  TWebTextAreaInput = class(TWebDataInput)
  private
    FReadOnly: Boolean;
    FWrap: TTextAreaWrap;
    FDisplayWidth: Integer;
    FDisplayRows: Integer;
  protected
    procedure AddAttributes(var Attrs: string); virtual;
    function ControlContent(Options: TWebContentOptions): string; override;
    procedure RestoreFieldDefaults(AField: TField); override;
    function ImplGetRowSetFieldAttributes(const FieldVarName: string): string; override;
    function EventContent(Options: TWebContentOptions): string; override;
  public
    constructor Create(AOwner: TComponent); override;
    property ReadOnly: Boolean read FReadOnly write FReadOnly default False;
    property Wrap: TTextAreaWrap read FWrap write FWrap;
    property DisplayWidth: Integer read FDisplayWidth write FDisplayWidth;
    property DisplayRows: Integer read FDisplayRows write FDisplayRows;
  end;

  TFieldTextArea = class(TWebTextAreaInput)
  published
    property ReadOnly;
    property Caption;
    property CaptionAttributes;
    property CaptionPosition;
    property FieldName;
    property Wrap;
    property DisplayWidth;
    property DisplayRows;
    property TabIndex;
    property Style;
    property Custom;
    property StyleRule;
  end;

  TQueryTextArea = class(TWebTextAreaInput, IQueryField)
  private
    FLines: TStrings;
  protected
    procedure AddAttributes(var Attrs: string); override;
    procedure SetLines(const Value: TStrings);
    function ControlContent(Options: TWebContentOptions): string; override;
    { IQueryField }
    procedure SetText(const Value: string);
    function GetText: string;
  public
    class function IsQueryField: Boolean; override;
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  published
    property ParamName;
    property ReadOnly;
    property Caption;
    property CaptionAttributes;
    property CaptionPosition;
    property FieldName;
    property Wrap;
    property DisplayWidth;
    property DisplayRows;
    property TabIndex;
    property Style;
    property Custom;
    property StyleRule;
    property Lines: TStrings read FLines write SetLines;
  end;

  TTextAreaColumn = class(TWebTextAreaInput)
  public
    class function IsColumn: Boolean; override;
  published
    property ReadOnly;
    property Caption;
    property CaptionAttributes;
    property FieldName;
    property Wrap;
    property DisplayWidth;
    property DisplayRows;
    property TabIndex;
    property Style;
    property Custom;
    property StyleRule;
  end;

  TWebListInput = class(TWebDataInput, IScriptComponent)
  private
    FValues: TStrings;
    FItems: TStrings;
    FDataSet: TDataSet;
    FValuesField: string;
    FItemsField: string;
  protected
    { IScriptComponent }
    procedure AddElements(AddIntf: IAddScriptElements);
    procedure ImplAddElements(AddIntf: IAddScriptElements); virtual;
    function GetSubComponents: TObject;

    procedure SetItems(const Value: TStrings);
    procedure SetValues(const Value: TStrings);
    procedure SetDataSet(const Value: TDataSet);
    function FormatInputs(ItemsStrings, ValuesStrings: TStrings; Options: TWebContentOptions): string; virtual; abstract;
    function ControlContent(Options: TWebContentOptions): string; override;
    procedure Notification(AComponent: TComponent;
      Operation: TOperation); override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property Values: TStrings read FValues write SetValues;
    property Items: TStrings read FItems write SetItems;
    property DataSet: TDataSet read FDataSet write SetDataSet;
    property ValuesField: string Read FValuesField write FValuesField;
    property ItemsField: string read FItemsField write FItemsField;
  end;

  TWebRadioGroupInput = class(TWebListInput)
  private
    FReadOnly: Boolean;
    FDisplayWidth: Integer;
    FDisplayColumns: Integer;
  protected
    procedure AddAttributes(var Attrs: string); virtual;
    function FormatInputs(ItemsStrings, ValuesStrings: TStrings; Options: TWebContentOptions): string; override;
    procedure RestoreFieldDefaults(AField: TField); override;
    function GetCheckIndex(ItemsStrings, ValuesStrings: TStrings): Integer; virtual;
    function EventContent(Options: TWebContentOptions): string; override;
    function ImplGetRowSetFieldAttributes(const FieldVarName: string): string; override;
  public
    constructor Create(AOwner: TComponent); override;
    property ReadOnly: Boolean read FReadOnly write FReadOnly;
    property DisplayWidth: Integer read FDisplayWidth write FDisplayWidth;
    property DisplayColumns: Integer read FDisplayColumns write FDisplayColumns;
  end;

  TFieldRadioGroup = class(TWebRadioGroupInput)
  published
    property ReadOnly;
    property Caption;
    property CaptionAttributes;
    property CaptionPosition;
    property FieldName;
    property DisplayWidth;
    property DisplayColumns;
    property TabIndex;
    property Values;
    property Items;
    property DataSet;
    property ValuesField;
    property ItemsField;
    property Style;
    property Custom;
    property StyleRule;
  end;

  TQueryRadioGroup = class(TWebRadioGroupInput, IQueryField)
  private
    FText: string;
  protected
    function GetText: string;
    procedure SetText(const Value: string);
    function GetCheckIndex(ItemsStrings, ValuesStrings: TStrings): Integer; override;
    procedure AddAttributes(var Attrs: string); override;
  public
    class function IsQueryField: Boolean; override;
  published
    property ParamName;
    property ReadOnly;
    property Caption;
    property CaptionAttributes;
    property CaptionPosition;
    property FieldName;
    property DisplayWidth;
    property DisplayColumns;
    property TabIndex;
    property Values;
    property Items;
    property DataSet;
    property ValuesField;
    property ItemsField;
    property Style;
    property Custom;
    property StyleRule;
    property Text: string read GetText write SetText;
  end;

  TWebSelectOptionsInput = class(TWebListInput)
  private
    FDisplayRows: Integer;
  protected
    procedure AddAttributes(var Attrs: string); virtual;
    function GetSelectIndex(ItemsStrings, ValuesStrings: TStrings): Integer; virtual;
    function FormatInputs(ItemsStrings, ValuesStrings: TStrings; Options: TWebContentOptions): string; override;
    function EventContent(Options: TWebContentOptions): string; override;
  public
    constructor Create(AOwner: TComponent); override;
    property DisplayRows: Integer read FDisplayRows write FDisplayRows;
  end;

  TFieldSelectOptions = class(TWebSelectOptionsInput)
  published
    property DisplayRows;
    property Caption;
    property CaptionAttributes;
    property CaptionPosition;
    property FieldName;
    property TabIndex;
    property Values;
    property Items;
    property DataSet;
    property ValuesField;
    property ItemsField;
    property Style;
    property Custom;
    property StyleRule;
  end;

  TQuerySelectOptions = class(TWebSelectOptionsInput, IQueryField)
  private
    FText: string;
  protected
    function GetText: string;
    procedure SetText(const Value: string);
    function GetSelectIndex(ItemsStrings, ValuesStrings: TStrings): Integer; override;
  public
    class function IsQueryField: Boolean; override;
  published
    property ParamName;
    property DisplayRows;
    property Caption;
    property CaptionAttributes;
    property CaptionPosition;
    property FieldName;
    property TabIndex;
    property Values;
    property Items;
    property DataSet;
    property ValuesField;
    property ItemsField;
    property Style;
    property Custom;
    property StyleRule;
    property Text: string read GetText write SetText;
  end;

  TSelectOptionsColumn = class(TWebSelectOptionsInput)
  public
    class function IsColumn: Boolean; override;
  published
    property DisplayRows;
    property Caption;
    property CaptionAttributes;
    property FieldName;
    property TabIndex;
    property Values;
    property Items;
    property DataSet;
    property ValuesField;
    property ItemsField;
    property Style;
    property Custom;
    property StyleRule;
  end;

  TWebButton = class(TComponent, IWebComponent, IWebContent)
  private
    FWebParent: TComponent;
    FWebButtonsList: TWebComponentList;
    FDefaultButton: Boolean;
    FStyle: string;
    FCustom: string;
    FCaption: string;
    FStyleRule: string;
    procedure SetWebParent(const Value: TComponent);
  protected
    { IWebComponent }
    function GetIndex: Integer;
    procedure SetIndex(Value: Integer);
    procedure SetContainer(Container: TWebComponentContainer);
    function GetContainer: TWebComponentContainer;
    procedure SetComponentList(List: TObject);
    { IWebContent }
    function Content(Options: TWebContentOptions; Layout: TLayout): string;
    function ImplContent(Options: TWebContentOptions; Layout: TLayout): string; virtual; abstract;

    function GetCaption: string; virtual;
    function GetLayoutAttributes: TLayoutAttributes; virtual;
    procedure ReadState(Reader: TReader); override;
    procedure SetParentComponent(AParent: TComponent); override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function GetParentComponent: TComponent; override;
    function HasParent: Boolean; override;
    property Caption: string read GetCaption write FCaption;
    property Style: string read FStyle write FStyle;
    property Custom: string read FCustom write FCustom;
    property StyleRule: string read FStyleRule write FStyleRule;
  end;

  TWebButtonClass = class of TWebButton;

  TXMLDisplayReferenceButton = class(TWebButton)
  private
    FXMLDisplay: TXMLDisplayParent;
  protected
    function GetDisplayComponentParent: Boolean;
    function GetDisplayComponent: TComponent;
    procedure SetDisplayComponent(const Value: TComponent);
    procedure SetDisplayComponentParent(const Value: Boolean);
    function GetXmlDisplayName: string;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    property XMLDisplay: TXMLDisplayParent read FXMLDisplay;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property XMLComponent: TComponent read GetDisplayComponent write SetDisplayComponent;
    property XMLUseParent: Boolean read GetDisplayComponentParent write SetDisplayComponentParent default True;
  end;

  TDataSetButton = class(TXMLDisplayReferenceButton, IScriptComponent)
  protected
    DefaultCaption: string;
    XMLMethodName: string;
    { IScriptComponent }
    procedure AddElements(AddIntf: IAddScriptElements);
    function GetSubComponents: TObject;
    procedure ImplAddElements(AddIntf: IAddScriptElements); virtual;
    { IWebContent implementation }
    function ImplContent(Options: TWebContentOptions; ParentLayout: TLayout): string; override;
    function GetCaption: string; override;
    function GetMethodName: string; virtual;
  published
    property XMLComponent;
    property XMLUseParent;
    property Style;
    property Custom;
    property Caption;
    property StyleRule;
  end;

  TFirstButton = class(TDataSetButton)
  public
    constructor Create(AOwner: TComponent); override;
  end;

  TLastButton = class(TDataSetButton)
  public
    constructor Create(AOwner: TComponent); override;
  end;

  TPriorButton = class(TDataSetButton)
  public
    constructor Create(AOwner: TComponent); override;
  end;

  TNextButton = class(TDataSetButton)
  public
    constructor Create(AOwner: TComponent); override;
  end;

  TPriorPageButton = class(TDataSetButton)
  public
    constructor Create(AOwner: TComponent); override;
  end;

  TNextPageButton = class(TDataSetButton)
  public
    constructor Create(AOwner: TComponent); override;
  end;

  TUndoButton = class(TDataSetButton)
  public
    constructor Create(AOwner: TComponent); override;
  end;

  TDeleteButton = class(TDataSetButton)
  public
    constructor Create(AOwner: TComponent); override;
  end;

  TInsertButton = class(TDataSetButton)
  public
    constructor Create(AOwner: TComponent); override;
  end;

  TPostButton = class(TDataSetButton)
  public
    constructor Create(AOwner: TComponent); override;
  end;

  TXMLButton = class(TWebButton)
  private
    FDefaultCaption: string;
    FXMLData: TXMLDataParent;
  protected
    function GetXMLBroker: TXMLBroker;
    procedure SetXMLBroker(const Value: TXMLBroker);
    function GetXMLUseParent: Boolean;
    procedure SetXMLUseParent(const Value: Boolean);
    function GetCaption: string; override;
    procedure Notification(AComponent: TComponent;
      Operation: TOperation); override;
    property XMLData: TXMLDataParent read FXMLData;
    property DefaultCaption: string read FDefaultCaption write FDefaultCaption;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property XMLBroker: TXMLBroker read GetXMLBroker write SetXMLBroker;
    property XMLUseParent: Boolean read GetXMLUseParent write SetXMLUseParent;
  end;

  TApplyUpdatesButton = class(TXMLButton, IScriptComponent)
  protected
    { IWebContent implementation }
    function ImplContent(Options: TWebContentOptions; ParentLayout: TLayout): string; override;
    { IScriptComponent }
    procedure AddElements(AddIntf: IAddScriptElements);
    procedure ImplAddElements(AddIntf: IAddScriptElements); virtual;
    function GetSubComponents: TObject;
  public
    constructor Create(AOwner: TComponent); override;
  published
    property Custom;
    property Style;
    property StyleRule;
    property Caption;
    property XMLBroker;
    property XMLUseParent;
  end;

  TXMLDisplayReferenceGroup = class(TWebControlGroup, IXMLDisplayReference)
  private
    FXMLDisplay: TXMLDisplay;
  protected
    { IXMLDisplayReference }
    function GetXMLDisplayComponent: TComponent;
    { IScriptComponent implementation }
    procedure ImplAddElements(AddIntf: IAddScriptElements); override;

    procedure SetXMLDisplayComponent(const Value: TComponent);
    property XMLDisplay: TXMLDisplay read FXMLDisplay;
    procedure Notification(AComponent: TComponent;
      Operation: TOperation); override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property XMLComponent: TComponent read GetXMLDisplayComponent write SetXMLDisplayComponent;
  end;

  TCustomDataNavigator = class(TXMLDisplayReferenceGroup)
  private
    FStyle: string;
    FCustom: string;
    FStyleRule: string;
  protected
    { IScriptComponent implementation  }
    function ImplGetSubComponents: TObject; override;
    { IWebComponentEditor implementation }
    function ImplCanAddClass(AParent: TComponent; AClass: TClass): Boolean; override;
    { IWebContent implementation }
    function ImplContent(Options: TWebContentOptions; ParentLayout: TLayout): string; override;

    function VisibleButtons: TWebComponentList;
    procedure GetDefaultButtons; virtual;
  public
    property Custom: string read FCustom write FCustom;
    property Style: string read FStyle write FStyle;
    property StyleRule: string read FStyleRule write FStyleRule;
  end;

  TDataNavigator = class(TCustomDataNavigator)
  published
    property XMLComponent;
    property Style;
    property Custom;
    property StyleRule;
  end;

  TQueryButton = class(TWebButton)
  private
    FCaption: string;
    FXMLComponent: TComponent;
    FXMLUseParent: Boolean;
  protected
    DefaultCaption: string;
    InputType: string;
    function ParentXMLComponent: TComponent;
    function GetXMLComponent: TComponent;
    procedure SetXMLComponent(const Value: TComponent);
    procedure SetXMLUseParent(const Value: Boolean);
    function GetCaption: string; override;
    function GetInputType: string; virtual;
    function GetHTMLControlName: string; virtual;
    function GetHTMLForm: IHTMLForm;
    { IWebContent impl }
    function ImplContent(Options: TWebContentOptions; ParentLayout: TLayout): string; override;
    function EventContent(Options: TWebContentOptions): string; virtual;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
  public
    constructor Create(AOwner: TComponent); override;
  published
    property Caption: string read GetCaption write FCaption;
    property Custom;
    property Style;
    property StyleRule;
    property XMLComponent: TComponent read GetXMLComponent write SetXMLComponent;
    property XMLUseParent: Boolean read FXMLUseParent write SetXMLUseParent default True;
  end;

  TSubmitQueryButton = class(TQueryButton)
  protected
    function EventContent(Options: TWebContentOptions): string; override;
  public
    constructor Create(AOwner: TComponent); override;
  end;

  TResetQueryButton = class(TQueryButton)
  protected
    function EventContent(Options: TWebContentOptions): string; override;
  public
    constructor Create(AOwner: TComponent); override;
  end;

  TCustomQueryButtons = class(TWebControlGroup)
  private
    FStyle: string;
    FCustom: string;
    FStyleRule: string;
  protected
    { IWebComponentEditor implementation }
    function ImplCanAddClass(AParent: TComponent; AClass: TClass): Boolean; override;
    { IScriptComponent implementation }
    procedure ImplAddElements(AddIntf: IAddScriptElements); override;
    { IWebContent }
    function ImplContent(Options: TWebContentOptions; ParentLayout: TLayout): string; override;

    function VisibleButtons: TWebComponentList;
    procedure GetDefaultButtons; virtual;
  public
    property Style: string read FStyle write FStyle;
    property Custom: string read FCustom write FCustom;
    property StyleRule: string read FStyleRule write FStyleRule;
  end;

  TQueryButtons = class(TCustomQueryButtons)
  published
    property Style;
    property Custom;
    property StyleRule;
  end;

  TLayoutState = (lsUnknown, lsFields, lsButtons);
  TFormLayout = class(TLayoutWebContent)
  private
    FLayoutState: TLayoutState;
    FInTable: Boolean;
    FInRow: Boolean;
    FTableHeader: string;
    FColumnCount: Integer;
    FColumnIndex: Integer;
    FBreakButtons: Boolean;
    FButtonIndex: Integer;
  protected
    function ImplLayoutButton(const HTMLButton: string; Attributes: TLayoutAttributes): string; override;
    function ImplLayoutField(const HTMLField: string; Attributes: TLayoutAttributes): string; override;
    function ImplLayoutLabelAndField(const HTMLLabel, HTMLField: string; Attributes: TLayoutAttributes): string; override;
    function ImplLayoutTable(const HTMLTable: string; Attributes: TLayoutAttributes): string; override;
    function StartFields(ColCount: Integer): string;
    function EndButtons: string;
    function StartButtons: string;
    function EndFields: string;
    function StartTable: string;
    function EndTable: string;
    function StartRow: string;
    function EndRow: string;
    function NextColumn(SubItemCount: Integer): string;
  public
    constructor Create(AParentLayout: TLayout);
    function EndLayout: string;
    property ColumnCount: Integer read FColumnCount write FColumnCount;
    property BreakButtons: Boolean read FBreakButtons write FBreakButtons;
    property TableHeader: string read FTableHeader write FTableHeader;
  end;

const
  TextAreaWrap: array[TTextAreaWrap] of string =
    ('OFF',
     'PHYSICAL',
     'VIRTUAL');            // Always declare explicitly.  IE
                            // and Navigator have different defaults.

  FormMethodNames: array[TFormMethod] of string =
    ('POST',
     'GET');

  // Utility functions
  function GetItemValuesFromDataSet(DataSet: TDataSet;
    const ItemsField, ValuesField: string;
    var ItemsStrings, ValuesStrings: TStrings): Boolean;

  procedure AddIntAttrib(var Attribs: string; const Attrib: string;
    Value: Integer);
  procedure AddStringAttrib(var Attribs: string; const Attrib,
    Value: string);
  procedure AddCustomAttrib(var Attribs: string;
    Value: string);
  procedure AddBoolAttrib(var Attribs: string;
  const Attrib: string; Value: Boolean);
  procedure AddQuotedAttrib(var Attribs: string;
  const Attrib, Value: string);
  function FormatColumnHeading(Field: TWebDataDisplay): string;
  function FormatColumnData(Field: TWebDataDisplay; Content: string): string;
  procedure CreateDefaultButtonClasses(
    Classes: array of TWebButtonClass; Container: TWebComponentList);
  function CanAddClassHelper(AEditor: TComponent; AParent: TComponent; AClass: TClass): Boolean;
  procedure DeclareSubmitForm(Component: TComponent; XMLBroker: TXMLBroker; AddIntf: IAddScriptElements);
  function FindDispatcher(Component: TComponent): TCustomWebDispatcher;
  function FindProducer(Component: TComponent): TCustomContentProducer;

implementation

uses Provider, Windows, Messages, DbConsts, MidConst, ActiveX, ComObj, WebConst, sysutils, DbWeb, Forms,
  WbmConst;

function CanAddClassHelper(AEditor: TComponent; AParent: TComponent; AClass: TClass): Boolean;
var
  Helper: TObject;
  Intf: IWebComponentEditorHelper;
begin
  Helper := FindWebComponentEditorHelper(AClass);
  if (Assigned(Helper) and Helper.GetInterface(IWebComponentEditorHelper, Intf)) then
    Result := Intf.CanAddClassHelper(AEditor, AParent, AClass)
  else
    Result := False;
end;

procedure AddIntAttrib(var Attribs: string; const Attrib: string;
  Value: Integer);
begin
  if Value <> -1 then
    Attribs := Format('%s %s=%d', [Attribs, Attrib, Value]);
end;

procedure AddStringAttrib(var Attribs: string; const Attrib,
  Value: string);
begin
  if Value <> '' then
    Attribs := Format('%s %s=%s', [Attribs, Attrib, Value]);
end;

procedure AddCustomAttrib(var Attribs: string;
  Value: string);
begin
  if Value <> '' then
    Attribs := Format('%s %s', [Attribs, Value]);
end;

procedure AddBoolAttrib(var Attribs: string;
  const Attrib: string; Value: Boolean);
begin
  if Value then
    Attribs := Format('%s %s', [Attribs, Attrib]);
end;

procedure AddQuotedAttrib(var Attribs: string;
  const Attrib, Value: string);
begin
  if Value <> '' then
    Attribs := Format('%s %s="%s"', [Attribs, Attrib, Value]);
end;

function FormatColumnHeading(Field: TWebDataDisplay): string;
var
  Attribs: string;
begin
  AddQuotedAttrib(Attribs, 'STYLE', Field.CaptionAttributes.Style);
  AddCustomAttrib(Attribs, Field.CaptionAttributes.Custom);
  AddQuotedAttrib(Attribs, 'CLASS', Field.CaptionAttributes.StyleRule);
  Result := Format('<TH%s>%s</TH>'#13#10, [Attribs, Field.Caption]);
end;

function FormatColumnData(Field: TWebDataDisplay; Content: string): string;
var
  Attribs: string;
begin
  AddQuotedAttrib(Attribs, 'STYLE', Field.Style);
  AddCustomAttrib(Attribs, Field.Custom);
  AddQuotedAttrib(Attribs, 'CLASS', Field.StyleRule);
  Result := Format('<TD%s><DIV>%s</DIV></TD>'#13#10, [Attribs,
    Content]);
end;

var
  XMLDataSetList: TList;

type

  TClientDataSetEvent = class(TClientDataSet)
  private
    FOnDataChange: TNotifyEvent;
  protected
    procedure DataEvent(Event: TDataEvent; Info: Longint); override;
  public
    property DataChange: TNotifyEvent read FOnDataChange write FOnDataChange;
  end;

  TDataSetWrapper = class(TInterfacedObject, IMidasWebDataSet)
  private
    FDataSet: TClientDataSetEvent;
    FDetailDataSet: TDataSet;
    FOnDataChange: array of TNotifyEvent;
  protected
    procedure OnDataChange(Sender: TObject);
    { IMidasWebDataSet }
    function FieldCount: Integer;
    function Fields: TFields;
    procedure FetchParams;
    function ParamCount: Integer;
    function Params: TParams;
    procedure AddOnDataChange(const Value: TNotifyEvent);
    procedure RemoveOnDataChange(const Value: TNotifyEvent);
  public
    constructor Create;
    destructor Destroy; override;
  end;

type
  TGridLayout = class(TLayoutWebContent)
  protected
    function ImplLayoutButton(const HTMLButton: string; Attributes: TLayoutAttributes): string; override;
    function ImplLayoutField(const HTMLField: string; Attributes: TLayoutAttributes): string; override;
    function ImplLayoutLabelAndField(const HTMLLabel, HTMLField: string; Attributes: TLayoutAttributes): string; override;
    function ImplLayoutTable(const HTMLTable: string; Attributes: TLayoutAttributes): string; override;
  end;

function TGridLayout.ImplLayoutButton(const HTMLButton: string; Attributes: TLayoutAttributes): string;
begin
  Result := ImplLayoutField(HTMLButton, Attributes);
end;

function TGridLayout.ImplLayoutField(const HTMLField: string; Attributes: TLayoutAttributes): string;
begin
  Result := HTMLField;
end;

function TGridLayout.ImplLayoutLabelAndField(const HTMLLabel, HTMLField: string; Attributes: TLayoutAttributes): string;
begin
  // Label ignored
  Result := ImplLayoutField(HTMLField, Attributes);
end;

{ TWebForm }

constructor TWebForm.Create(AComponent: TComponent);
begin
  inherited;
  FWebComponents := TWebComponentList.Create(Self);
  FLayoutAttributes := TLayoutAttributes.Create;
end;

destructor TWebForm.Destroy;
begin
  inherited;
  if Assigned(FContainer) then
    FContainer.Remove(Self);
  FWebComponents.Free;
  FLayoutAttributes.Free;
end;

procedure TWebForm.SetComponentList(List: TObject);
begin
  FContainer := List as TWebComponentList;
end;

function TWebForm.GetContainer: TWebComponentContainer;
begin
  Result := FContainer;
end;

function TWebForm.GetIndex: Integer;
begin
  Result := FContainer.IndexOf(Self);
end;

procedure TWebForm.SetContainer(Container: TWebComponentContainer);
begin
  SetWebParent((Container as TWebComponentList).ParentComponent);
end;

procedure TWebForm.SetIndex(Value: Integer);
begin
  FContainer.SetComponentIndex(Self, Value);
end;

function TWebForm.GetParentComponent: TComponent;
begin
  if Assigned(FWebParent) then
    Result := FWebParent else
    Result := inherited GetParentComponent;
end;

function TWebForm.HasParent: Boolean;
begin
  if Assigned(FWebParent) then
    Result := True else
    Result := inherited HasParent;
end;

procedure TWebForm.ReadState(Reader: TReader);
begin
  inherited ReadState(Reader);
  SetWebParent(Reader.Parent);
end;

procedure TWebForm.SetParentComponent(AParent: TComponent);
begin
  if not (csLoading in ComponentState) then
    SetWebParent(AParent);
end;

function TWebForm.Content(Options: TWebContentOptions; Layout: TLayout): string;
begin
  Result := ImplContent(Options, Layout);
end;

procedure ValidateWebParent(AComponent: TComponent; AParent: TComponent);
var
  P: TComponent;
  Editor: IWebComponentEditor;
begin
  // Don't allow self to be parented by a child of self
  P := AParent;
  while Assigned(P) do
  begin
    if P = AComponent then
      raise EComponentError.CreateRes(@sInvalidParent);
    P := P.GetParentComponent;
  end;
  if AParent.GetInterface(IWebComponentEditor, Editor) then
    if not Editor.CanAddClass(AParent, AComponent.ClassType) then
      raise EComponentError.CreateRes(@sInvalidParent);
end;

procedure TWebForm.SetWebParent(const Value: TComponent);
var
  List: IGetWebComponentList;
begin
  if Value <> FWebParent then
  begin
    if Assigned(Value) and (csDesigning in ComponentState) then
      ValidateWebParent(Self, Value);
    if FWebParent <> nil then
    begin
      FWebParent.GetInterface(IGetWebComponentList, List);
      (List.GetComponentList as TWebComponentList).Remove(Self);
    end;
    if Value <> nil then
    begin
      Value.GetInterface(IGetWebComponentList, List);
      (List.GetComponentList as TWebComponentList).Add(Self);
    end;
    FWebParent := Value;
  end;
end;

function TWebForm.CanAddClass(AParent: TComponent; AClass: TClass): Boolean;
begin
  Result := ImplCanAddClass(AParent, AClass);
end;

  { Inserts line breaks and an indent of Indent characters into the given text in
  place of '|' characters when the line length exceeds 75 characters.  If a line
  break is not necessary the '|' is removed. }
function FormatText(Text: PChar; Col, Indent: Integer): PChar;
const
  MaxLineLen = 75;
var
  Mark, P: PChar;
begin
  Result := Text;
  Mark := nil;
  while Text^ <> #0 do
  begin
    while not (Text^ in [#0, #13, '|']) do
    begin
      if (Text^ in LeadBytes) and ((Text+1)^ <> #0) then
      begin
        Inc(Text);
        Inc(Col);
      end;
      Inc(Text);
      Inc(Col);
    end;
    if (Mark <> nil) and (Col > MaxLineLen) then
    begin
      P := Mark;
      while P^ = ' ' do Inc(P);
      StrMove(Mark + Indent + 2, P, StrLen(P) + 1);
      StrMove(Mark, #13#10'          ', Indent + 2);
      Inc(Text, Indent + 2 - (P - Mark));
      Col := Text - Mark - 2;
    end;
    case Text^ of
      #13:
      begin
        Inc(Text, 2);
        Mark := nil;
        Col := 0;
      end;
      '|':
      begin
        StrCopy(Text, Text + 1);
        Mark := Text;
      end;
    end;
  end;
end;

procedure DefineXMLDisplayBlock(AddIntf: IAddScriptElements; AComponent: TComponent;
  RowSetVarName: string);
var
  HTMLForm: IHTMLForm;
  FieldStatus: string;
  Names, Identifiers: string;
  Attributes: TStrings;

  function WrapParameters(const Decl: string; Indent: Integer): string;
  var
    Buffer: array[0..4096] of Char;
  begin
    if Length(Decl) < sizeof(Buffer)-100 then
    begin
      StrCopy(Buffer, PChar(Decl));
      Result := FormatText(Buffer, 0, Indent);
    end
    else
      Result := Decl;
  end;

  function FormatIdentifier(Field: IHTMLField): string;
  begin
    Result := Format('%0:s.%1:s', [HTMLForm.HTMLFormName, Field.HTMLControlName]);
  end;

  procedure TraverseSubComponents(AContainer: TComponent);
  var
    WebComponentContainer: IWebComponentContainer;
    ValidateFields: IValidateFields;
    I: Integer;
    DataSetField: IDataSetField;
    StatusField: IStatusField;
    Component: TComponent;
    S: string;
    ScriptComponent: IScriptComponent;
    SubComponents: TObject;
  begin
    if AContainer.GetInterface(IScriptComponent, ScriptComponent) then
    begin
      SubComponents := ScriptComponent.SubComponents;
      if Assigned(SubComponents) and SubComponents.GetInterface(IWebComponentContainer, WebComponentContainer) then
      begin
        if AContainer.GetInterface(IValidateFields, ValidateFields) then
          ValidateFields.ValidateFields(AddIntf);
        for I := 0 to WebComponentContainer.ComponentCount - 1 do
        begin
          Component := WebComponentContainer.Components[I];
          if Component.GetInterface(IStatusField, StatusField) then
          begin
            if FieldStatus <> '' then
              AddIntf.AddError(Format(sDuplicateStatusField, [Component.Name]))
            else
              FieldStatus := FormatIdentifier(StatusField);
          end
          else if Component.GetInterface(IDataSetField, DataSetField) then
          begin
            if DataSetField.FieldName <> '' then
            begin
              if Names <> '' then
                Names := Names + ', |';
              Names := Names + Format('"%s"', [DataSetField.FieldName]);
              if Identifiers <> '' then
                Identifiers := Identifiers + ', |';
              Identifiers := Identifiers + FormatIdentifier(DataSetField);
              S := DataSetField.GetRowSetFieldAttributes(
                Format('%s.Fields.Field["%s"]', [RowSetVarName, DataSetField.FieldName]));
              if S <> '' then
                Attributes.Add(S);
            end
          end
          else if Component.GetInterface(IScriptComponent, ScriptComponent) then
            TraverseSubComponents(Component);
        end;
      end;
    end;
  end;

var
  IdsVar, NamesVar: string;
  Component: TComponent;
  XMLDisplay: IXMLDisplay;
  XMLDisplayName: string;
begin
  AComponent.GetInterface(IXMLDisplay, XMLDisplay);
  Assert(Assigned(XMLDisplay), 'Component is not an XMLDisplay');
  XMLDisplayName := XMLDisplay.XMLDisplayName;
  FieldStatus := '';
  Attributes := TStringList.Create;
  try
    Component := AComponent;
    while Assigned(Component) do
    begin
      if not Assigned(HTMLForm) then
        Component.GetInterface(IHTMLForm, HTMLForm);
      Component := Component.GetParentComponent;
    end;
    Assert(Assigned(HTMLForm), 'HTMLForm not found');
    TraverseSubComponents(AComponent);
    if Identifiers <> '' then
    begin
      AddIntf.AddVar(HTMLForm.HTMLFormVarName,
        Format('var %0:s = document.forms[''%1:s''];'#13#10, [HTMLForm.HTMLFormVarName, HTMLForm.HTMLFormName]));
      NamesVar := Format(ScriptNamesVar, [AComponent.Name]);
      AddIntf.AddVar(NamesVar, WrapParameters(Format('var %0:s = new Array(%1:s);'#13#10, [NamesVar, Names]), 4));
      IDsVar := Format(ScriptIDsVar, [AComponent.Name]);
      AddIntf.AddVar(IdsVar, WrapParameters(Format('var %0:s = new Array(%1:s);'#13#10, [IDsVar, Identifiers]), 4));
      Attributes.Text := TrimRight(Attributes.Text);
      if Attributes.Count > 0 then
        AddIntf.AddScriptBlock('', Attributes.Text);
      if FieldStatus = '' then FieldStatus := 'null';
      AddIntf.AddVar(XMLDisplayName,
        Format('var %0:s = new xmlDisplay(%1:s, %2:s, %3:s, %4:s);'#13#10,
          [XMLDisplayName, RowSetVarName,
            Format(ScriptIDsVar, [AComponent.Name]),
            Format(ScriptNamesVar, [AComponent.Name]),
            FieldStatus]));
    end;
  finally
    Attributes.Free;
  end;
end;

procedure TWebForm.ImplAddElements(AddIntf: IAddScriptElements);
begin
  inherited;
end;

function TWebForm.GetVisibleFields: TWebComponentList;
begin
  Result := FWebComponents
end;

procedure TWebForm.GetChildren(Proc: TGetChildProc; Root: TComponent);
var
  I: Integer;
  WebComponent: TComponent;
begin
  for I := 0 to FWebComponents.Count - 1 do
  begin
    WebComponent := FWebComponents.WebComponents[I];
    if WebComponent.Owner = Root then Proc(WebComponent);
  end;
end;

procedure TWebForm.SetChildOrder(Component: TComponent;
  Order: Integer);
var
  Intf: IWebComponent;
begin
  if FWebComponents.IndexOf(Component) >= 0 then
    if Component.GetInterface(IWebComponent, Intf) then
      Intf.Index := Order
    else
      Assert(False, 'Interface not supported');
end;

function TWebForm.GetSubComponents: TObject;
begin
  Result := WebComponents;
end;

function TWebForm.GetComponentList: TObject;
begin
  Result := FWebComponents;
end;

function TWebForm.GetDefaultComponentList: TObject;
begin
  Assert(False, 'Form does not support DefaultComponents');
  Result := nil;
end;

procedure TWebForm.AddElements(AddIntf: IAddScriptElements);
begin
  inherited;
  ImplAddElements(AddIntf);
end;

function TWebForm.GetHTMLFormName: string;
begin
  Result := Self.Name;
end;

function TWebForm.GetLayoutAttributes: TLayoutAttributes;
begin
  with FLayoutAttributes do
  begin
    ControlAttributes := '';
    AddQuotedAttrib(ControlAttributes, 'STYLE', Style);
    AddQuotedAttrib(ControlAttributes, 'CLASS', StyleRule);
    AddCustomAttrib(ControlAttributes, Custom);
  end;
  Result := FLayoutAttributes;
end;

function TWebForm.GetHTMLFormVarName: string;
begin
  Result := Self.Name;
end;

{ TDataForm }
function TDataForm.GetHTMLFormTag(Options: TWebContentOptions): string;
var
  Attribs: string;
begin
  AddStringAttrib(Attribs, 'NAME', GetHTMLFormName);
  AddQuotedAttrib(Attribs, 'STYLE', Style);
  AddQuotedAttrib(Attribs, 'CLASS', StyleRule);
  AddCustomAttrib(Attribs, Custom);
  Result :=
    Format(#13#10'<FORM%s>', [Attribs]);
end;

function TDataForm.ImplCanAddClass(AParent: TComponent; AClass: TClass): Boolean;
begin
  Result :=
    AClass.InheritsFrom(TCustomDataGrid) or
    AClass.InheritsFrom(TCustomDataNavigator) or
    AClass.InheritsFrom(TFieldGroup) or
    AClass.InheritsFrom(TCustomLayoutGroup) or
    CanAddClassHelper(Self, AParent, AClass);
end;

{ TFormLayout}

constructor TFormLayout.Create(AParentLayout: TLayout);
begin
  inherited;
  FInTable := False;
  FInRow := False;
  FColumnCount := 1;
  FColumnIndex := 0;
  FTableHeader := #13#10'<TABLE>';
  FLayoutState := lsUnknown;
  FBreakButtons := False;
end;

function TFormLayout.ImplLayoutButton(const HTMLButton: string; Attributes: TLayoutAttributes): string;
begin
  Result := StartButtons;
  if FBreakButtons then
    Result := Format('%s>%s</TD>', [Result, HTMLButton])
  else if FButtonIndex = 1 then
    Result := Format('%s>%s', [Result, HTMLButton])
  else
    Result := Result + HTMLButton;
end;

function TFormLayout.ImplLayoutField(const HTMLField: string; Attributes: TLayoutAttributes): string;
begin
  if Assigned(Attributes) then
    Result := StartFields(1) + Format('%0:s>%1:s</TD>'#13#10, [Attributes.ControlAttributes, HTMLField])
  else
    Result := StartFields(1) + Format('>%0:s</TD>'#13#10, [HTMLField]);
end;

function TFormLayout.ImplLayoutLabelAndField(const HTMLLabel, HTMLField: string; Attributes: TLayoutAttributes): string;
begin
  if Assigned(Attributes) then
    case Attributes.LabelPosition of
      lposLeft:
        Result :=
          StartFields(2) + Format('%0:s>%1:s</TD><TD %2:s>%3:s</TD>'#13#10,
            [Attributes.LabelAttributes, HTMLLabel, Attributes.ControlAttributes, HTMLField]);
      lposRight:
        Result :=
          StartFields(2) + Format('%0:s>%1:s</TD><TD %2:s>%3:s</TD>'#13#10,
            [Attributes.ControlAttributes, HTMLField, Attributes.LabelAttributes, HTMLLabel]);
      lposAbove:
        Result :=
          StartFields(1) + Format('%0:s>%1:s</TD></TR><TR><TD COLSPAN = 2 %2:s>%3:s</TD>'#13#10,
            [Attributes.LabelAttributes, HTMLLabel, Attributes.ControlAttributes, HTMLField]);
      lposBelow:
        Result :=
          StartFields(1) + Format('%0:s>%1:s</TD></TR><TR><TD COLSPAN=2 %2:s>%3:s</TD>'#13#10,
            [Attributes.ControlAttributes, HTMLField, Attributes.LabelAttributes, HTMLLabel]);
    else
      Assert(False, 'Unknown position');
    end
  else
    Result :=
        StartFields(2) + Format('>%0:s</TD><TD>%1:s</TD>'#13#10,
          [HTMLLabel, HTMLField])
end;

function TFormLayout.ImplLayoutTable(const HTMLTable: string; Attributes: TLayoutAttributes): string;
begin
  Result := ImplLayoutField(HTMLTable, Attributes);
end;

function TFormLayout.StartFields(ColCount: Integer): string;
begin
  Result := EndButtons;
  FLayoutState := lsFields;
  Result := Result + StartTable + StartRow + NextColumn(ColCount);
end;

function TFormLayout.NextColumn(SubItemCount: Integer): string;

  function SpanAll: string;
  begin
    Result := Format('<TD COLSPAN=%d', [FColumnCount * 2]);
  end;

  function SpanCalc: string;
  var
    Span: Integer;
  begin
    Span := -1;
    if SubItemCount = 1 then
      Span := 2;
    if Span <> -1 then
      Result := Format('<TD COLSPAN=%d', [Span])
    else
      Result := '<TD';
  end;
begin
  Result := '';
  if (FLayoutState = lsButtons) and (not FBreakButtons) and (FButtonIndex = 0) then
    Result := Format('%s', [SpanAll])
  else if (FLayoutState <> lsButtons) or FBreakButtons then
  begin
    if FColumnIndex = FColumnCount then
      Result := Format('%s%s%s', [EndRow, StartRow, SpanCalc])
    else
      Result := SpanCalc;
    Inc(FColumnIndex);
  end;
  if FLayoutState = lsButtons then
    Inc(FButtonIndex);
end;

function TFormLayout.StartRow: string;
begin
  if not FInRow then
  begin
    Result := '<TR>';
    FInRow := True;
  end
  else
    Result := '';
end;


function TFormLayout.EndRow: string;
begin
  if FInRow then
  begin
    Result := '</TR>';
    FColumnIndex := 0;
    FInRow := False;
  end
  else
    Result := '';
end;

function TFormLayout.EndTable: string;
begin
  if FInTable then
  begin
    Result := EndRow + '</TABLE>';
    FInTable := False;
  end
  else
    Result := '';
end;

function TFormLayout.EndLayout: string;
begin
  Result := EndFields + EndButtons + EndTable;
end;

function TFormLayout.StartTable: string;
begin
  if not FInTable then
  begin
    Result := FTableHeader;
    FInTable := True;
  end
  else
    Result := '';
end;

function TFormLayout.StartButtons: string;
begin
  if FLayoutState <> lsButtons then
    FButtonIndex := 0;
  Result := EndFields;
  FLayoutState := lsButtons;
  Result := Result + StartTable + StartRow + NextColumn(1);
end;

function TFormLayout.EndButtons: string;
begin
  Result := '';
  if FLayoutState = lsButtons then
  begin
    if not FBreakButtons then
      Result := EndRow;
    FLayoutState := lsUnknown;
  end;
end;

function TFormLayout.EndFields: string;
begin
  Result := '';
  if FLayoutState = lsFields then
  begin
    if not FBreakButtons then
      Result := EndRow;
    FLayoutState := lsUnknown;
  end;
end;

{ TDataForm }

function TDataForm.ImplContent(Options: TWebContentOptions; ParentLayout: TLayout): string;
var
  FormLayout: TFormLayout;

  function FormatField(Field: TComponent): string;
  var
    Intf: IWebContent;
  begin
    if Field.GetInterface(IWebContent, Intf) then
      Result := Intf.Content(Options, FormLayout)
    else
      Result := '';
  end;

var
  I: Integer;
  Intf: ILayoutWebContent;
begin
  FormLayout := TFormLayout.Create(ParentLayout);
  try
    Result := GetHTMLFormTag(Options);
    for I := 0 to VisibleFields.Count - 1 do
      Result := Result + FormatField(VisibleFields[I]);
    Result := Result + FormLayout.EndLayout;
    Result := Result + '</FORM>';
    if Assigned(ParentLayout) and ParentLayout.GetInterface(ILayoutWebContent, Intf) then
      Result := Intf.LayoutField(Result, GetLayoutAttributes)
  finally
    FormLayout.Free;
  end;
end;

{ TDataSetWrapper }

procedure TDataSetWrapper.AddOnDataChange(const Value: TNotifyEvent);
var
  I: Integer;
begin
  for I := 0 to Length(FOnDataChange) - 1 do
    if not Assigned(FOnDataChange[I]) then
    begin
      FOnDataChange[I] := Value;
      Exit;
    end;
  I := Length(FOnDataChange);
  SetLength(FOnDataChange, I+1);
  FOnDataChange[I] := Value;
end;

constructor TDataSetWrapper.Create;
begin
  inherited;
  FDataSet := TClientDataSetEvent.Create(nil);
  FDataSet.FOnDataChange := OnDataChange;
end;

destructor TDataSetWrapper.Destroy;
begin
  inherited;
  FreeAndNil(FDataSet);
end;

procedure TDataSetWrapper.FetchParams;
begin
  FDataSet.FetchParams;
end;

function TDataSetWrapper.FieldCount: Integer;
begin
  Result := FDetailDataSet.FieldCount;
end;

function TDataSetWrapper.Fields: TFields;
begin
  Result := FDetailDataSet.Fields;
end;

function TDataSetWrapper.ParamCount: Integer;
begin
  Result := FDataSet.Params.Count;
end;

function TDataSetWrapper.Params: TParams;
begin
  Result := FDataSet.Params;
end;

procedure TDataSetWrapper.RemoveOnDataChange(const Value: TNotifyEvent);
var
  I: Integer;
  P: TNotifyEvent;
begin
  for I := 0 to Length(FOnDataChange) - 1 do
  begin
    P := FOnDataChange[I];
    if (TMethod(P).Code = TMethod(Value).Code) and
      (TMethod(P).Data = TMethod(Value).Data) then
      FOnDataChange[I] := nil;
  end;
end;

procedure TDataSetWrapper.OnDataChange(Sender: TObject);
var
  I: Integer;
begin
  Assert(Assigned(FDataSet));
  for I := 0 to Length(FOnDataChange) - 1 do
  begin
    if Assigned(FOnDataChange[I]) then
      FOnDataChange[I](Sender);
    if not Assigned(FDataSet) then Break;
  end;
end;

{ TXMLDisplayReferenceGroup }

constructor TXMLDisplayReferenceGroup.Create(AOwner: TComponent);
begin
  inherited;
  FXMLDisplay := TXMLDisplay.Create(Self);
end;

destructor TXMLDisplayReferenceGroup.Destroy;
begin
  inherited;
  FXMLDisplay.Free;
end;

function TXMLDisplayReferenceGroup.GetXMLDisplayComponent: TComponent;
begin
  Result := XMLDisplay.DisplayComponent;
end;

procedure TXMLDisplayReferenceGroup.SetXMLDisplayComponent(
  const Value: TComponent);
begin
  FXMLDisplay.DisplayComponent := Value;
end;

procedure TXMLDisplayReferenceGroup.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if Assigned(FXMLDisplay) then
    FXMLDisplay.Notification(AComponent, Operation);
end;

procedure TXMLDisplayReferenceGroup.ImplAddElements(
  AddIntf: IAddScriptElements);
begin
  inherited;
  if XMLComponent = nil then
    AddIntf.AddError(Format(sXMLComponentNotDefined, [Self.Name]));
end;

{ TCustomDataNavigator }

function TCustomDataNavigator.ImplContent(Options: TWebContentOptions; ParentLayout: TLayout): string;
var
  ButtonsLayout: TFormLayout;

  function FormatButton(Button: TComponent): string;
  var
    Intf: IWebContent;
  begin
    Result := '';
    if Button.GetInterface(IWebContent, Intf) then
      Result := Intf.Content(Options, ButtonsLayout);
  end;
var
  Button: TComponent;
  I: Integer;
  Intf: ILayoutWebContent;
  Attribs: string;
begin
  Result := '';
  ButtonsLayout := TFormLayout.Create(ParentLayout);
  try
    // AddStringAttrib(Attribs, 'NAME', Name);
    AddQuotedAttrib(Attribs, 'STYLE', Style);
    AddQuotedAttrib(Attribs, 'CLASS', StyleRule);
    AddCustomAttrib(Attribs, Custom);
    ButtonsLayout.FTableHeader := Format(#13#10'<TABLE%s>', [Attribs]);
    for I := 0 to VisibleButtons.Count - 1 do
    begin
      Button := VisibleButtons.WebComponents[I];
      Result := Result + FormatButton(Button);
    end;
    Result := Result + ButtonsLayout.EndLayout;
  finally
    ButtonsLayout.Free;
  end;
  if Assigned(ParentLayout) and ParentLayout.GetInterface(ILayoutWebContent, Intf) then
    Result := Intf.LayoutTable(Result, nil)
end;


procedure CreateDefaultButtonClasses(
  Classes: array of TWebButtonClass; Container: TWebComponentList);
var
  Button: TWebButton;
  I: Integer;
  Intf: IWebComponent;
begin
  for I := 0 to High(Classes) do
  begin
    Button := Classes[I].Create(nil); // Not owned
    Button.GetInterface(IWebComponent, Intf);
    Intf.Container := Container;
  end;
end;

const
  DefaultFormButtons: array[0..8] of TWebButtonClass =
  (TFirstButton, TPriorButton, TNextButton,
  TLastButton, TInsertButton, TDeleteButton,
  TUndoButton, TPostButton, TApplyUpdatesButton);

  DefaultGridButtons: array[0..10] of TWebButtonClass =
  (TFirstButton, TPriorPageButton, TPriorButton, TNextButton,
  TNextPageButton, TLastButton, TInsertButton, TDeleteButton,
  TUndoButton, TPostButton, TApplyUpdatesButton);

procedure TCustomDataNavigator.GetDefaultButtons;
var
  XMLDisplay: TComponent;
  Intf: IXMLDisplay;
  Count: Integer;
  Grid: Boolean;
begin
  Grid := False;
  XMLDisplay := GetXMLDisplayComponent;
  if Assigned(XMLDisplay) then
    if XMLDisplay.GetInterface(IXMLDisplay, Intf) then
      Grid := Intf.IsMultipleRecordView;
  if Grid then
    Count := Length(DefaultGridButtons)
  else
    Count := Length(DefaultFormButtons);
  if Assigned(DefaultWebComponents) and
    (DefaultWebComponents.Count <> Count) then
  begin
    DefaultWebComponents.Free;
    DefaultWebComponents := nil;
  end;
  if not Assigned(DefaultWebComponents) then
  begin
    DefaultWebComponents := TWebComponentList.Create(Self);
    if Grid then
      CreateDefaultButtonClasses(DefaultGridButtons, WebFieldControls)
    else
      CreateDefaultButtonClasses(DefaultFormButtons, WebFieldControls)
  end;
end;

function TCustomDataNavigator.VisibleButtons: TWebComponentList;
begin
  if WebFieldControls.Count > 0 then
    Result := WebFieldControls
  else
  begin
    GetDefaultButtons;
    Result := DefaultWebComponents;
  end;
end;

function TCustomDataNavigator.ImplCanAddClass(AParent: TComponent; AClass: TClass): Boolean;
var
  I: Integer;
begin
  if AClass.InheritsFrom(TDataSetButton) or
    AClass.InheritsFrom(TXMLButton) then
  begin
    Result := True;
    // Don't allow duplicates
    for I := 0 to WebFieldControls.Count - 1 do
      if WebFieldControls.WebComponents[I].ClassType = AClass then
      begin
        Result := False;
        break;
      end
  end
  else
    Result := AClass.InheritsFrom(TCustomLayoutGroup) or
      CanAddClassHelper(Self, AParent, AClass);
end;

function TCustomDataNavigator.ImplGetSubComponents: TObject;
begin
  Result := VisibleButtons;
end;

{ TWebDataDisplay }

function TWebDataDisplay.GetContainer: TWebComponentContainer;
begin
  Result := FWebComponents;
end;

function TWebDataDisplay.GetIndex: Integer;
begin
  Result := FWebComponents.IndexOf(Self);
end;

procedure TWebDataDisplay.SetContainer(Container: TWebComponentContainer);
begin
  SetWebParent((Container as TWebComponentList).ParentComponent);
end;

procedure TWebDataDisplay.SetIndex(Value: Integer);
begin
  FWebComponents.SetComponentIndex(Self, Value)
end;

function TWebDataDisplay.GetParentComponent: TComponent;
begin
  if FWebParent <> nil then
    Result := FWebParent else
    Result := inherited GetParentComponent;
end;

function TWebDataDisplay.HasParent: Boolean;
begin
  if FWebParent <> nil then
    Result := True else
    Result := inherited HasParent;
end;

procedure TWebDataDisplay.ReadState(Reader: TReader);
begin
  inherited ReadState(Reader);
  SetWebParent(Reader.Parent);
end;

procedure TWebDataDisplay.SetParentComponent(AParent: TComponent);
begin
  if not (csLoading in ComponentState) then
    SetWebParent(AParent);
end;

procedure TWebDataDisplay.SetWebParent(Value: TComponent);
var
  List: IGetWebComponentList;
begin
  if Value <> FWebParent then
  begin
    if Assigned(Value) and (csDesigning in ComponentState) then
      ValidateWebParent(Self, Value);
    if FWebParent <> nil then
    begin
      FWebParent.GetInterface(IGetWebComponentList, List);
      if FDefaultField then
        (List.GetDefaultComponentList as TWebComponentList).Remove(Self)
      else
        (List.GetComponentList as TWebComponentList).Remove(Self)
    end;
    if Value <> nil then
    begin
      Value.GetInterface(IGetWebComponentList, List);
      if FDefaultField then
        (List.GetDefaultComponentList as TWebComponentList).Add(Self)
      else
        (List.GetComponentList as TWebComponentList).Add(Self)
    end;
    FWebParent := Value;
  end;
end;

constructor TWebDataDisplay.Create(AOwner: TComponent);
begin
  inherited;
  FDefaultField := AOwner = nil;
  FTabIndex := -1;
  FCaptionAttributes := TCaptionAttributes.Create(Self);
  FLayoutAttributes := TLayoutAttributes.Create;
  FCaptionPosition := capLeft;
end;

destructor TWebDataDisplay.Destroy;
begin
  inherited;
  if FWebComponents <> nil then
    FWebComponents.Remove(Self);
  FCaptionAttributes.Free;
  FLayoutAttributes.Free;
end;

procedure TWebDataDisplay.SetComponentList(List: TObject);
begin
  Assert((List = nil) or (List is TWebComponentList));
  FWebComponents := TWebComponentList(List);
end;

function TWebDataDisplay.Content(Options: TWebContentOptions; ParentLayout: TLayout): string;
begin
  Result := ImplContent(Options, ParentLayout);
end;

function TWebDataDisplay.GetCaption: string;
begin
  Result := FCaption;
end;

function TWebDataDisplay.EventContent(Options: TWebContentOptions): string;
begin
  Result := '';
end;

function TWebDataDisplay.GetXmlDisplayName: string;
var
  Component: TComponent;
  Intf: IXMLDisplay;
begin
  Component := Self;
  while Assigned(Component) and
    (not Component.GetInterface(IXMLDisplay, Intf)) do
    Component := Component.GetParentComponent;
  if Assigned(Component) then
    Result := Intf.XmlDisplayName;
end;

function TWebDataDisplay.GetXmlRowSetName: string;
var
  Component: TComponent;
  Intf: IXMLDisplay;
begin
  Component := Self;
  while Assigned(Component) and
    (not Component.GetInterface(IXMLDisplay, Intf)) do
    Component := Component.GetParentComponent;
  if Assigned(Component) then
    Result := Intf.XmlRowSetName;
end;

function TWebDataDisplay.GetHTMLForm: IHTMLForm;
var
  Component: TComponent;
begin
  Result := nil;
  Component := GetParentComponent;
  while Assigned(Component) and
    (not Component.GetInterface(IHTMLForm, Result)) do
    Component := Component.GetParentComponent;
end;

function TWebDataDisplay.ImplContent(Options: TWebContentOptions;
  ParentLayout: TLayout): string;
var
  Intf: ILayoutWebContent;
begin
  if Assigned(ParentLayout) and ParentLayout.GetInterface(ILayoutWebContent, Intf) then
    Result := Intf.LayoutLabelAndField(LabelContent, ControlContent(Options),
      GetLayoutAttributes)
  else
    Result := LabelContent + ControlContent(Options);
end;

procedure TWebDataDisplay.SetCaptionAttributes(
  const Value: TCaptionAttributes);
begin
  FCaptionAttributes.Assign(Value);
end;

function TWebDataDisplay.FormatCaption: string;
var
  Attribs: string;
begin
  AddQuotedAttrib(Attribs, 'STYLE', CaptionAttributes.Style);
  AddCustomAttrib(Attribs, CaptionAttributes.Custom);
  AddQuotedAttrib(Attribs, 'CLASS', CaptionAttributes.StyleRule);
  LayoutAttributes.LabelAttributes := Attribs;
  case CaptionPosition of
    capLeft: LayoutAttributes.LabelPosition := lposLeft;
    capRight: LayoutAttributes.LabelPosition := lposRight;
    capAbove: LayoutAttributes.LabelPosition := lposAbove;
    capBelow: LayoutAttributes.LabelPosition := lposBelow;
  else
    Assert(False, 'Unknown position');
  end;
  if Attribs <> '' then
    Result := Format('<SPAN%0:s>%1:s</SPAN>', [Attribs, Caption])
  else
    Result := Caption;
end;

function TWebDataDisplay.LabelContent: string;
begin
  Result := FormatCaption;
end;

function TWebDataDisplay.GetLayoutAttributes: TLayoutAttributes;
begin
  Result := FLayoutAttributes;
end;

class function TWebDataDisplay.IsColumn: Boolean;
begin
  Result := False;
end;

class function TWebDataDisplay.IsQueryField: Boolean;
begin
  Result := False;
end;

function TWebDataDisplay.GetHTMLControlName: string;
begin
  Result := ImplGetHTMLControlName;
end;

function TWebDataDisplay.ImplGetHTMLControlName: string;
begin
  Result := Name;
end;

procedure TWebDataDisplay.SetCaption(Value: string);
begin
  FCaption := Value;
end;

{ TWebDataInput }

procedure TWebDataInput.SetFieldName(Value: string);
var
  Intf: IValidateFields;
  Component: TComponent;
begin
  if (AnsiCompareText(Value, FFieldName) <> 0) then
  begin
    FFieldName := Value;
    if (FCaption = Value) then FCaption := '';
    if Assigned(FWebParent) and
      not (csLoading in ComponentState) and (Length(Value) > 0) then
      RestoreDefaults;
    if [csLoading, csDesigning] * ComponentState <> [] then
    begin
      Component := GetParentComponent;
      while Assigned(Component) and
       (not Component.GetInterface(IValidateFields, Intf)) do
       Component := Component.GetParentComponent;
      if Assigned(Component) then
        Intf.EnableValidateFields := True;
    end;
  end;
end;

function TWebDataInput.ImplGetHTMLControlName: string;
  function CrunchFieldName(const FieldName: string): string;
  var
    I: Integer;
  begin
    Result := FieldName;
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
  if IsQueryField then
  begin
    Result := ParamName;
    if Result = '' then
    begin
      Result := FieldName;
      if Result = '' then
        Result := Name;
    end;
  end
  else
  begin
    Result := Name;
    if Result = '' then
    begin
      Result := Format('%s_%s', [GetParentComponent.Name, CrunchFieldName(FieldName)]);
    end;
  end
end;

function TWebDataInput.GetCaption: string;
begin
  if FCaption = '' then
  begin
    Result := FFieldName;
    if Result = '' then
      Result := ParamName;
    if Result = '' then
      Result := Name;
  end
  else
    Result := FCaption;
end;

procedure TWebDataInput.SetCaption(Value: string);
begin
  if Value = FFieldName then Value := '';
  inherited SetCaption(Value);
end;

function TWebDataInput.EventContent(Options: TWebContentOptions): string;
var
  XMLDisplayName: string;
begin
  Result := '';
  if not IsQueryField then
  begin
    XMLDisplayName := GetXmlDisplayName;
    Result := Result +
      Format(' onFocus=''if(%s)%s.xfocus(this);''', [sXMLReadyVar, XMLDisplayName]);
    Result := Result +
      Format(' onkeydown=''if(%s)%s.keys(this);''', [sXMLReadyVar, XMLDisplayName]);
  end;
end;

procedure TWebDataInput.ImplRestoreDefaults;
var
  Field: TField;
  DataSet: IMidasWebDataSet;
  XMLDataSet: TXMLDataSetParent;
begin
  XMLDataSet := TXMLDataSetParent.Create(Self);
  try
    XMLDataSet.UseParent := True;
    DataSet := XMLDataSet.DataSet;
  finally
    XMLDataSet.Free;
  end;
  if not Assigned(DataSet) then
    Exit;
  Field := FindAssociatedField(DataSet);
  RestoreFieldDefaults(Field);
end;

function TWebDataInput.FindAssociatedField(DataSet: IMidasWebDataSet): TField;
begin
  if FieldName <> '' then
    Result := DataSet.Fields.FindField(FieldName)
  else if IsQueryField then
    Result := DataSet.Fields.FindField(ParamName)
  else
    Result := nil;
end;

procedure TWebDataInput.RestoreFieldDefaults(AField: TField);
begin
  if Assigned(AField) then
    Caption := AField.DisplayName;
end;

function TWebDataInput.GetFieldName: string;
begin
  Result := ImplGetFieldName;
end;

function TWebDataInput.ImplGetFieldName: string;
begin
  Result := FFieldName;
end;

procedure TWebDataInput.RestoreDefaults;
begin
  ImplRestoreDefaults;
end;

function TWebDataInput.GetParamName: string;
begin
  Result := FParamName;
  if (Result = '') and IsQueryField then
    Result := FieldName;
end;

procedure TWebDataInput.SetParamName(Value: string);
begin
  if Value <> FParamName then
  begin
    FParamName := Value;
    if Assigned(FWebParent) and
      not (csLoading in ComponentState) and (Length(Value) > 0) then
    begin
      RestoreDefaults;
    end;
  end;
end;

function TWebDataInput.GetRowSetFieldAttributes(
  const FieldVarName: string): string;
begin
  Result := ImplGetRowSetFieldAttributes(FieldVarName);
end;

function TWebDataInput.ImplGetRowSetFieldAttributes(
  const FieldVarName: string): string;
begin
  Result := '';
end;

function TWebDataInput.ValidateField(DataSet: IMidasWebDataSet;
  AddIntf: IAddScriptElements): Boolean;

  procedure AddError(Value: string);
  begin
    AddIntf.AddError(Value);
    Result := False;
  end;
begin
  Result := True;
  if FieldName = '' then
    AddError(Format(sFieldNameBlank, [Name]))
  else if Assigned(DataSet) then
    if FindAssociatedField(DataSet) = nil then
      AddError(Format(sFieldNotFound, [Name, FieldName]));
end;

{ TWebTextInput }

constructor TWebTextInput.Create(AOwner: TComponent);
begin
  inherited;
  FDisplayWidth := -1;
end;

procedure TWebTextInput.AddAttributes(var Attrs: string);
begin
  AddQuotedAttrib(Attrs, 'NAME', GetHTMLControlName);
  AddIntAttrib(Attrs, 'SIZE', DisplayWidth);
  AddIntAttrib(Attrs, 'TABINDEX', TabIndex);
  AddQuotedAttrib(Attrs, 'STYLE', Style);
  AddQuotedAttrib(Attrs, 'CLASS', StyleRule);
  AddCustomAttrib(Attrs, Custom);
end;

function TWebTextInput.ControlContent(Options: TWebContentOptions): string;
var
  Attrs: string;
  Events: string;
begin
  AddAttributes(Attrs);
  if (not (coNoScript in Options.Flags)) then
    Events := EventContent(Options);
  Result := Format('<INPUT TYPE=TEXT%0:s%1:s>', [Attrs, Events]);
end;

procedure TWebTextInput.RestoreFieldDefaults(AField: TField);
begin
  inherited;
  if Assigned(AField) then
    DisplayWidth := AField.DisplayWidth;
end;

function TWebTextInput.ImplGetRowSetFieldAttributes(
  const FieldVarName: string): string;
begin
  if ReadOnly then
    Result := Format('%s.readonly=true;', [FieldVarName])
  else
    Result := '';
end;

{ TXMLDisplayReferenceButton }

constructor TXMLDisplayReferenceButton.Create(AOwner: TComponent);
begin
  inherited;
  FXMLDisplay := TXMLDisplayParent.Create(Self);
  FXMLDisplay.UseParent := True;
end;

destructor TXMLDisplayReferenceButton.Destroy;
begin
  inherited;
  FXMLDisplay.Free;
end;

function TXMLDisplayReferenceButton.GetDisplayComponent: TComponent;
begin
  Result := FXMLDisplay.DisplayComponent;
end;

function TXMLDisplayReferenceButton.GetDisplayComponentParent: Boolean;
begin
  Result := FXMLDisplay.UseParent;
end;

procedure TXMLDisplayReferenceButton.SetDisplayComponent(const Value: TComponent);
begin
  FXMLDisplay.DisplayComponent := Value;
end;

procedure TXMLDisplayReferenceButton.SetDisplayComponentParent(const Value: Boolean);
begin
  FXMLDisplay.UseParent := Value;
end;

function TXMLDisplayReferenceButton.GetXmlDisplayName: string;
var
  Component: TComponent;
  Intf: IXMLDisplay;
begin
  Component := XMLDisplay.DisplayComponent;
  if Assigned(Component) and
    Component.GetInterface(IXMLDisplay, Intf) then
    Result := Intf.XmlDisplayName
  else
    Result := '';
end;

procedure TXMLDisplayReferenceButton.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if Assigned(FXMLDisplay) then
    FXMLDisplay.Notification(AComponent, Operation);
end;

{ TDataSetButton }

procedure TDataSetButton.AddElements(AddIntf: IAddScriptElements);
begin
  ImplAddElements(AddIntf);
end;

function TDataSetButton.GetCaption: string;
begin
  Result := inherited GetCaption;
  if Result = '' then
    Result := DefaultCaption;
end;

function TDataSetButton.GetMethodName: string;
begin
  Result := XMLMethodName;
end;

constructor TFirstButton.Create(AOwner: TComponent);
begin
  inherited;
  DefaultCaption := sFirstButton;
  XMLMethodName := 'first';
end;

constructor TLastButton.Create(AOwner: TComponent);
begin
  inherited;
  DefaultCaption := sLastButton;
  XMLMethodName := 'last';
end;

constructor TPriorButton.Create(AOwner: TComponent);
begin
  inherited;
  DefaultCaption := sPriorButton;
  XMLMethodName := 'up';
end;

constructor TNextButton.Create(AOwner: TComponent);
begin
  inherited;
  DefaultCaption := sNextButton;
  XMLMethodName := 'down';
end;

constructor TNextPageButton.Create(AOwner: TComponent);
begin
  inherited;
  DefaultCaption := sNextPageButton;
  XMLMethodName := 'pgdown';
end;

constructor TPriorPageButton.Create(AOwner: TComponent);
begin
  inherited;
  DefaultCaption := sPriorPageButton;
  XMLMethodName := 'pgup';
end;

constructor TInsertButton.Create(AOwner: TComponent);
begin
  inherited;
  DefaultCaption := sInsertButton;
  XMLMethodName := 'newRow';
end;

constructor TDeleteButton.Create(AOwner: TComponent);
begin
  inherited;
  DefaultCaption := sDeleteButton;
  XMLMethodName := 'removeRow';
end;

constructor TUndoButton.Create(AOwner: TComponent);
begin
  inherited;
  DefaultCaption := sUndoButton;
  XMLMethodName := 'undo';
end;

function TDataSetButton.GetSubComponents: TObject;
begin
  Result := nil;
end;

procedure TDataSetButton.ImplAddElements(AddIntf: IAddScriptElements);
begin
  if (XMLComponent = nil) and (Self.Name <> '') then
    AddIntf.AddError(Format(sXMLComponentNotDefined, [Self.Name]));
end;

function TDataSetButton.ImplContent(Options: TWebContentOptions; ParentLayout: TLayout): string;
var
  Attrs: string;
  Intf: ILayoutWebContent;
begin
  //AddQuotedAttrib(Attrs, 'NAME', Name);
  AddQuotedAttrib(Attrs, 'STYLE', Style);
  AddQuotedAttrib(Attrs, 'CLASS', StyleRule);
  AddQuotedAttrib(Attrs, 'VALUE', Self.Caption);
  AddCustomAttrib(Attrs, Custom);
  if not (coNoScript in Options.Flags) then
  begin
    Result :=
      Format('<INPUT TYPE=BUTTON%0:s onclick=''if(%3:s)%1:s.%2:s();''>'#13#10,
        [Attrs, Self.GetXmlDisplayName, Self.GetMethodName, sXMLReadyVar]);
  end
  else
    Result :=
      Format('<INPUT TYPE=BUTTON%0:s>'#13#10,
        [Attrs]);
  if Assigned(ParentLayout) and ParentLayout.GetInterface(ILayoutWebContent, Intf) then
    Result := Intf.LayoutButton(Result, GetLayoutAttributes);
end;

{ TApplyUpdatesButton }

procedure TApplyUpdatesButton.AddElements(AddIntf: IAddScriptElements);
begin
  ImplAddElements(AddIntf);
end;

constructor TApplyUpdatesButton.Create(AOwner: TComponent);
begin
  inherited;
  DefaultCaption := sApplyUpdates;
end;


function TApplyUpdatesButton.GetSubComponents: TObject;
begin
  Result := nil;
end;

function FindProducer(Component: TComponent): TCustomContentProducer;
begin
  while Assigned(Component) and not (Component is TCustomContentProducer) do
    Component := Component.GetParentComponent;
  if Assigned(Component) then
    Result := TCustomContentProducer(Component)
  else
    Result := nil;
end;

function FindDispatcher(Component: TComponent): TCustomWebDispatcher;
var
  Producer: TCustomContentProducer;
begin
  Result := nil;
  if not (csDesigning in Component.ComponentState) then
  begin
    Producer := FindProducer(Component);
    if Assigned(Producer) then
      Result := Producer.Dispatcher;
  end;
end;

procedure DeclareSubmitForm(Component: TComponent; XMLBroker: TXMLBroker; AddIntf: IAddScriptElements);
const
  Indent1 = '  ';
var
  PathInfo: string;
  Redirect: string;
  Forms, Vars: string;
  Dispatcher: TCustomWebDispatcher;
  Producer: TCustomContentProducer;
begin
  Forms := '';
  Vars := '';
  if Assigned(XMLBroker) then
  begin
    PathInfo := XMLBroker.WebDispatch.PathInfo;
    if Copy(PathInfo, 1, 1) = '/' then
      Delete(PathInfo, 1, 1);
    Producer := FindProducer(Component);
    if Assigned(Producer) then
      Dispatcher := Producer.Dispatcher
    else
      Dispatcher := nil;
    if Assigned(Dispatcher) and Assigned(Dispatcher.Request) then
      PathInfo := Dispatcher.Request.ScriptName + '/' + PathInfo;
    Forms := Forms +
      Format(#13#10'<FORM NAME=%0:s ACTION="%1:s" METHOD="POST">',
        [XMLBroker.HTMLSubmitFormName, PathInfo]);
    Forms := Forms +
      Format('%0:s<INPUT TYPE=HIDDEN NAME="%1:s" VALUE="%2:s">'#13#10,
        [Indent1, sXMLBroker, XMLBroker.Name]);
    Forms := Forms +
      Format('%0:s<INPUT TYPE=HIDDEN NAME="%1:s">'#13#10,
        [Indent1, SPostDelta]);
    Forms := Forms +
      Format('%0:s<INPUT TYPE=HIDDEN NAME="%1:s" VALUE="%2:s">'#13#10,
        [Indent1, sProducer, Producer.Name]);
    if (Dispatcher <> nil) and (Dispatcher.Request <> nil) then
    begin
      if Assigned(Dispatcher) and Assigned(Dispatcher.Request) then
        Redirect := Format('http://%s%s', [Dispatcher.Request.Host, Dispatcher.Request.ScriptName]);
      if Length(Dispatcher.Request.PathInfo) > 1 then
      begin
        if Redirect <> '' then Redirect := Redirect + '/';
        Redirect := Redirect + Copy(Dispatcher.Request.PathInfo, 2, MaxInt);
      end;
      if Dispatcher.Request.Query <> '' then
        Redirect := Redirect + '?' + Dispatcher.Request.Query;
      Forms := Forms +
        Format('%0:s<INPUT TYPE=HIDDEN NAME="%1:s" VALUE="%2:s">'#13#10,
          [Indent1, sRedirect, Redirect]);
    end;
    Forms := Forms + '</FORM>';
    AddIntf.AddHTMLBlock(XMLBroker.HTMLSubmitFormName, Forms);
    AddIntf.AddVar(XMLBroker.SubmitFormVarName,
       Format('var %0:s = document.forms[''%1:s''];'#13#10,
        [XMLBroker.SubmitFormVarName, XMLBroker.HTMLSubmitFormName]));
  end;
end;

procedure TApplyUpdatesButton.ImplAddElements(AddIntf: IAddScriptElements);
begin
  DeclareSubmitForm(Self, XMLData.XMLBroker, AddIntf);
end;

function TApplyUpdatesButton.ImplContent(Options: TWebContentOptions;
  ParentLayout: TLayout): string;
var
  Attrs: string;
  Intf: ILayoutWebContent;
  FormVarName: string;
  RowSetVarName: string;
begin
  //AddQuotedAttrib(Attrs, 'NAME', Name);
  AddQuotedAttrib(Attrs, 'STYLE', Style);
  AddQuotedAttrib(Attrs, 'CLASS', StyleRule);
  AddQuotedAttrib(Attrs, 'VALUE', Self.Caption);
  AddCustomAttrib(Attrs, Custom);
  if Assigned(XMLData.XMLBroker) then
  begin
    FormVarName := XMLData.XMLBroker.SubmitFormVarName;
    RowSetVarName := XMLData.XMLBroker.RowSetVarName(nil);  
  end;
  if not (coNoScript in Options.Flags) then
    Result :=
      Format('<INPUT TYPE=BUTTON%0:s onclick=''if(%3:s)%1:s.Apply(%2:s, %2:s.postdelta);''>'#13#10,
        [Attrs, RowSetVarName, FormVarName, sXMLReadyVar])
  else
    Result :=
      Format('<INPUT TYPE=BUTTON%0:s>'#13#10,
        [Attrs]);
  if Assigned(ParentLayout) and ParentLayout.GetInterface(ILayoutWebContent, Intf) then
    Result := Intf.LayoutButton(Result, GetLayoutAttributes);
end;

{ TXMLButton }

constructor TXMLButton.Create(AOwner: TComponent);
begin
  inherited;
  FXMLData := TXMLDataParent.Create(Self);
  FXMLData.UseParent := True;
end;

destructor TXMLButton.Destroy;
begin
  inherited;
  FXMLData.Free;
end;

function TXMLButton.GetCaption: string;
begin
  Result := inherited GetCaption;
  if Result = '' then
    Result := DefaultCaption;
end;

function TXMLButton.GetXMLBroker: TXMLBroker;
begin
  Result := FXMLData.XMLBroker;
end;

function TXMLButton.GetXMLUseParent: Boolean;
begin
  Result := XMLData.UseParent;
end;

procedure TXMLButton.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if Assigned(XMLData) then
    XMLData.Notification(AComponent, Operation);
end;

procedure TXMLButton.SetXMLBroker(const Value: TXMLBroker);
begin
  FXMLData.XMLBroker := Value;
end;

procedure TXMLButton.SetXMLUseParent(const Value: Boolean);
begin
  XMLData.UseParent := Value;
end;

{ TWebTextAreaInput }

constructor TWebTextAreaInput.Create(AOwner: TComponent);
begin
  inherited;
  FDisplayWidth := -1;
  FDisplayRows := -1;
  FWrap := wrVirtual;
end;

procedure TWebTextAreaInput.AddAttributes(var Attrs: string);
begin
  AddQuotedAttrib(Attrs, 'NAME', GetHTMLControlName);
  AddIntAttrib(Attrs, 'COLS', DisplayWidth);
  AddIntAttrib(Attrs, 'ROWS', DisplayRows);
  AddIntAttrib(Attrs, 'TABINDEX', TabIndex);
  AddStringAttrib(Attrs, 'WRAP', TextAreaWrap[Wrap]);
  AddQuotedAttrib(Attrs, 'STYLE', Style);
  AddQuotedAttrib(Attrs, 'CLASS', StyleRule);
  AddCustomAttrib(Attrs, Custom);
end;

function TWebTextAreaInput.ControlContent(Options: TWebContentOptions): string;
var
  Attrs: string;
  Events: string;
begin
  AddAttributes(Attrs);
  if (not (coNoScript in Options.Flags)) then
    Events := EventContent(Options);
  Result := Format('<TEXTAREA%0:s%1:s></TEXTAREA>', [Attrs, Events]);
end;

function TWebTextAreaInput.EventContent(Options: TWebContentOptions): string;
var
  XMLDisplayName: string;
begin
  Result := '';
  if not IsQueryField then
  begin
    XMLDisplayName := GetXmlDisplayName;
    Result := Result +
      Format(' onFocus=''if(%s)%s.xfocus(this);''', [sXMLReadyVar, XMLDisplayName]);
  end;
end;

procedure TWebTextAreaInput.RestoreFieldDefaults(AField: TField);
begin
  inherited;
  if Assigned(AField) then
    DisplayWidth := AField.DisplayWidth;
end;

function TWebTextAreaInput.ImplGetRowSetFieldAttributes(
  const FieldVarName: string): string;
begin
  if ReadOnly then
    Result := Format('%s.readonly=true;', [FieldVarName])
  else
    Result := '';
end;

{ TWebListInput }

constructor TWebListInput.Create(AOwner: TComponent);
begin
  inherited;
  FValues := TStringList.Create;
  FItems := TStringList.Create;
end;

destructor TWebListInput.Destroy;
begin
  inherited;
  FValues.Free;
  FItems.Free;
end;

function TWebListInput.ControlContent(Options: TWebContentOptions): string;
var
  ValuesStrings, ItemsStrings: TStrings;
begin
  if GetItemValuesFromDataSet(FDataSet, ItemsField, ValuesField, ItemsStrings, ValuesStrings) then
  begin
    try
      Result := FormatInputs(ItemsStrings, ValuesStrings, Options);
    finally
      ItemsStrings.Free;
      ValuesStrings.Free;
    end;
  end
  else
    Result := FormatInputs(Items, Values, Options);
end;

procedure TWebListInput.SetItems(const Value: TStrings);
begin
  FItems.Assign(Value);
end;

procedure TWebListInput.SetValues(const Value: TStrings);
begin
  FValues.Assign(Value);
end;

procedure TWebListInput.SetDataSet(const Value: TDataSet);
begin
  if FDataSet <> Value then
  begin
    FDataSet := Value;
    if Value <> nil then
    begin
      Value.FreeNotification(Self);
      if not (csLoading in ComponentState) then
        Value.Active := True;
    end;
  end;
end;

procedure TWebListInput.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited;
  if (Operation = opRemove) and (AComponent = FDataSet) then
    DataSet := nil;
end;

procedure TWebListInput.AddElements(AddIntf: IAddScriptElements);
begin
  ImplAddElements(AddIntf);
end;

function TWebListInput.GetSubComponents: TObject;
begin
  Result := nil;
end;

procedure TWebListInput.ImplAddElements(AddIntf: IAddScriptElements);
begin
  if Assigned(FDataSet) and (FDataSet.Active = False) then
    AddIntf.AddError(Format(sDataSetNotActive, [FDataSet.Name]));
end;

{ TWebRadioGroupInput }

constructor TWebRadioGroupInput.Create(AOwner: TComponent);
begin
  inherited;
  FDisplayWidth := -1;
  FDisplayColumns := -1;
  FDisplayColumns := -1;
end;

procedure TWebRadioGroupInput.AddAttributes(var Attrs: string);
begin
  AddQuotedAttrib(Attrs, 'NAME', GetHTMLControlName);
  AddIntAttrib(Attrs, 'WIDTH', DisplayWidth);
  AddIntAttrib(Attrs, 'TABINDEX', TabIndex);
  AddCustomAttrib(Attrs, Custom);
end;

function TWebRadioGroupInput.FormatInputs(ItemsStrings, ValuesStrings: TStrings; Options: TWebContentOptions): string;
  function Min(X, Y: Integer): Integer;
  begin
    Result := X;
    if X > Y then Result := Y;
  end;
var
  I, J, Index: Integer;
  Element, Value, Attrs, Item: string;
  Columns, Rows: Integer;
  Skip: Integer;
  Events: string;
  CheckIndex: Integer;
  ItemAttr: string;
begin
  Skip := 0;
  Result := '';
  if ItemsStrings.Count > 0 then
  begin
    AddAttributes(Attrs);
    if (not (coNoScript in Options.Flags)) then
      Events := EventContent(Options);
    Element := Format('<INPUT TYPE=RADIO%0:s%1:s', [Attrs, Events]);
    CheckIndex := GetCheckIndex(ItemsStrings, ValuesStrings);
    if DisplayColumns > 0 then
    begin
      Columns := Min(DisplayColumns, ItemsStrings.Count);
      Rows := (ItemsStrings.Count + Columns - 1) div Columns;
      for I := 0 to Rows - 1 do
      begin
        Result := Format('%0:s<TR>', [Result]);
        for J := 0 to Columns -1 do
        begin
          Index := (Rows * J) + I + Skip;
          if Index < ItemsStrings.Count then
          begin
            Item := ItemsStrings[Index];
            if ItemsStrings.IndexOf(Item) <> Index then
            begin
              Inc(Skip);
              continue;  // not unique
            end;
            if ValuesStrings.Count > Index then
              Value := ValuesStrings[Index]
            else
              Value := Item;
            ItemAttr := '';
            AddQuotedAttrib(ItemAttr, 'VALUE', Value);
            AddBoolAttrib(ItemAttr, 'CHECKED', Index = CheckIndex);
            Result := Format('%0:s<TD>%1:s%2:s>%3:s</INPUT></TD>'#13#10,
              [Result, Element, ItemAttr, Item]);
          end;
        end;
        Result := Result + '</TR>';
      end;
      Attrs := '';
      AddQuotedAttrib(Attrs, 'STYLE', Style);
      AddQuotedAttrib(Attrs, 'CLASS', StyleRule);
      Result := Format(#13#10'<TABLE%s>%s</TABLE>', [Attrs, Result]);
    end
    else
    begin
      Attrs := '';
      AddQuotedAttrib(Attrs, 'STYLE', Style);
      AddQuotedAttrib(Attrs, 'CLASS', StyleRule);
      LayoutAttributes.ControlAttributes := Attrs;
      for Index := 0 to ItemsStrings.Count - 1 do
      begin
        Item := ItemsStrings[Index];
        if ItemsStrings.IndexOf(Item) <> Index then continue;
        if ValuesStrings.Count > Index then
          Value := ValuesStrings[Index]
        else
          Value := Item;
        ItemAttr := '';
        AddQuotedAttrib(ItemAttr, 'VALUE', Value);
        AddBoolAttrib(ItemAttr, 'CHECKED', Index = CheckIndex);
        Result := Format('%0:s %1:s%2:s>%3:s</INPUT>'#13#10,
          [Result, Element, ItemAttr, Item]);
      end;
    end;
  end;
end;

procedure TWebRadioGroupInput.RestoreFieldDefaults(AField: TField);
begin
  inherited;
  if Assigned(AField) then
    DisplayWidth := AField.DisplayWidth;
end;

function TWebRadioGroupInput.GetCheckIndex(ItemsStrings,
  ValuesStrings: TStrings): Integer;
begin
  Result := -1;
end;

function TWebRadioGroupInput.EventContent(
  Options: TWebContentOptions): string;
var
  XMLDisplayName: string;
begin
  Result := '';
  if not IsQueryField then
  begin
    XMLDisplayName := GetXmlDisplayName;
    Result := Result +
      Format(' onFocus=''if(%s)%s.xfocus(this);''', [sXMLReadyVar, XMLDisplayName]);
  end;
end;

function TWebRadioGroupInput.ImplGetRowSetFieldAttributes(
  const FieldVarName: string): string;
begin
  if ReadOnly then
    Result := Format('%s.readonly=true;', [FieldVarName])
  else
    Result := '';
end;

{ TWebSelectOptionsInput }

constructor TWebSelectOptionsInput.Create(AOwner: TComponent);
begin
  inherited;
  FDisplayRows := -1;
end;

function TWebSelectOptionsInput.EventContent(Options: TWebContentOptions): string;
var
  XMLDisplayName: string;
begin
  Result := '';
  if not IsQueryField then
  begin
    XMLDisplayName := GetXmlDisplayName;
    Result := Result +
      Format(' onFocus=''if(%s)%s.xfocus(this);''', [sXMLReadyVar, XMLDisplayName]);
  end;
end;

procedure TWebSelectOptionsInput.AddAttributes(var Attrs: string);
begin
  AddQuotedAttrib(Attrs, 'NAME', GetHTMLControlName);
  AddIntAttrib(Attrs, 'SIZE', DisplayRows);
  AddIntAttrib(Attrs, 'TABINDEX', TabIndex);
  AddQuotedAttrib(Attrs, 'STYLE', Style);
  AddQuotedAttrib(Attrs, 'CLASS', StyleRule);
  AddCustomAttrib(Attrs, Custom);
end;

function TWebSelectOptionsInput.GetSelectIndex(ItemsStrings, ValuesStrings: TStrings): Integer;
begin
  Result := -1;
end;

function TWebSelectOptionsInput.FormatInputs(ItemsStrings, ValuesStrings: TStrings; Options: TWebContentOptions): string;
var
  Index: Integer;
  Attrs, Value: string;
  Item: string;
  Events: string;
  OptionAttr: string;
  SelectIndex: Integer;
begin
  Result := '';
  AddAttributes(Attrs);
  if (not (coNoScript in Options.Flags)) then
    Events := EventContent(Options);
  Result := Format('<SELECT%0:s%1:s>'#13#10, [Attrs, Events]);
  SelectIndex := GetSelectIndex(ItemsStrings, ValuesStrings);
  for Index := 0 to ItemsStrings.Count - 1 do
  begin
    Item := ItemsStrings[Index];
    if ItemsStrings.IndexOf(Item) <> Index then continue;  // no unique
    if ValuesStrings.Count > Index then
      Value := ValuesStrings[Index]
    else
      Value := Item;
    OptionAttr := '';
    AddQuotedAttrib(OptionAttr, 'VALUE', Value);
    AddBoolAttrib(OptionAttr, 'SELECTED', Index = SelectIndex);

    Result := Format('%0:s <OPTION%1:s>%2:s'#13#10,
      [Result, OptionAttr, Item]);
  end;
  Result := Format('%0:s</SELECT>'#13#10, [Result]);
end;

{ TDataSetPostButton }

constructor TPostButton.Create(AOwner: TComponent);
begin
  inherited;
  DefaultCaption := sPostButton;
  XMLMethodName := 'post';
end;

{ TCustomQueryForm }

procedure TCustomQueryForm.ImplAddElements(AddIntf: IAddScriptElements);
begin
  inherited;
  AddIntf.AddScriptBlock('', Format('var %0:s = document.forms[''%1:s''];'#13#10, [GetHTMLFormVarName, GetHTMLFormName]));
end;

function TCustomQueryForm.GetHTMLFormTag(Options: TWebContentOptions): string;
var
  Attribs: string;
begin
  AddStringAttrib(Attribs, 'NAME', GetHTMLFormName);
  AddQuotedAttrib(Attribs, 'STYLE', Style);
  AddQuotedAttrib(Attribs, 'CLASS', StyleRule);
  AddQuotedAttrib(Attribs, 'ACTION', Action);
  AddStringAttrib(Attribs, 'METHOD', MethodString);
  AddCustomAttrib(Attribs, Custom);
  Result :=
    Format(#13#10'<FORM%0:s>', [Attribs]);
end;

function TCustomQueryForm.MethodString: string;
begin
  Result := FormMethodNames[FMethod];
end;

constructor TCustomQueryForm.Create(AOwner: TComponent);
begin
  inherited;
  FMethod := fmGet;   // Default to Query because it can
                      // be bookmarked and can easily return
                      // to after apply
end;

type TComponentCracker = class(TComponent) end;

procedure TCustomQueryForm.AssignStringsCallback(AComponent: TComponent);
var
  QueryField: IQueryField;
  Index: Integer;
begin
  Assert(Assigned(FAssignStrings), 'Unexpected value');
  if AComponent.GetInterface(IQueryField, QueryField) then
  begin
    Index := FAssignStrings.IndexOfName(QueryField.HTMLControlName);
    if Index <> -1 then
      QueryField.Text := FAssignStrings.Values[FAssignStrings.Names[Index]];
  end;
  TComponentCracker(AComponent).GetChildren(AssignStringsCallback, Owner);
end;

procedure TCustomQueryForm.AssignStrings(Value: TStrings);
begin
  if Value.Count > 0 then
  begin
    FAssignStrings := Value;
    try
      GetChildren(AssignStringsCallback, Owner);
    finally
      FAssignStrings := nil;
    end;
  end;
end;

{ TSubmitQueryButton }

constructor TSubmitQueryButton.Create(AOwner: TComponent);
begin
  inherited;
  DefaultCaption := sSubmitQuery;
  InputType := 'BUTTON';
end;

function TSubmitQueryButton.EventContent(
  Options: TWebContentOptions): string;
var
  HTMLForm: IHTMLForm;
  HTMLFormVarName: string;
begin
  HTMLForm := GetHTMLForm;
  if Assigned(HTMLForm) then
    HTMLFormVarName := HTMLForm.HTMLFormVarName;
  Result :=
    Format(' onclick=''%0:s.submit();''',
      [HTMLFormVarName]);
end;

{ TResetQueryButton }

constructor TResetQueryButton.Create(AOwner: TComponent);
begin
  inherited;
  DefaultCaption := sResetQuery;
  InputType := 'BUTTON';
end;

function TResetQueryButton.EventContent(
  Options: TWebContentOptions): string;
var
  HTMLForm: IHTMLForm;
  HTMLFormVarName: string;
begin
  HTMLForm := GetHTMLForm;
  if Assigned(HTMLForm) then
    HTMLFormVarName := HTMLForm.HTMLFormVarName;
  Result :=
    Format(' onclick=''%0:s.reset();''',
      [HTMLFormVarName]);
end;

{ TQueryButton }

function TQueryButton.GetCaption: string;
begin
  Result := FCaption;
  if Result = '' then
    Result := DefaultCaption;
end;

function TQueryButton.GetInputType: string;
begin
  Result := InputType;
end;

function TQueryButton.ImplContent(Options: TWebContentOptions; ParentLayout: TLayout): string;
var
  Attribs: string;
  Intf: ILayoutWebContent;
  Events: string;
begin
  Attribs := '';
  if not (coNoScript in Options.Flags) then
    Events := EventContent(Options);

  //AddStringAttrib(Attribs, 'NAME', GetHTMLControlName);
  AddStringAttrib(Attribs, 'TYPE', GetInputType);
  AddQuotedAttrib(Attribs, 'VALUE', Self.Caption);
  AddQuotedAttrib(Attribs, 'STYLE', Style);
  AddQuotedAttrib(Attribs, 'CLASS', StyleRule);
  AddCustomAttrib(Attribs, Custom);
  Result :=
    Format('<INPUT%0:s%1:s>'#13#10,
      [Attribs, Events]);
  if Assigned(ParentLayout) and ParentLayout.GetInterface(ILayoutWebContent, Intf) then
    Result := Intf.LayoutButton(Result, GetLayoutAttributes);
end;

function TQueryButton.EventContent(Options: TWebContentOptions): string;
begin
  Result := '';
end;

function TQueryButton.GetHTMLControlName: string;
begin
  Result := '';
end;

function TQueryButton.GetHTMLForm: IHTMLForm;
begin
  if Assigned(XMLComponent) then
    XMLComponent.GetInterface(IHTMLForm, Result)
  else
    Result := nil;
end;

function TQueryButton.ParentXMLComponent: TComponent;
var
  QueryForm: IQueryForm;
begin
  Result := GetParentComponent;
  while Assigned(Result) do
  begin
    if Result.GetInterface(IQueryForm, QueryForm) then Exit;
    Result := Result.GetParentComponent;
  end;
  Result := nil;
end;

function TQueryButton.GetXMLComponent: TComponent;
begin
  if not FXMLUseParent then
    Result := FXMLComponent
  else
    Result := ParentXMLComponent;
end;

procedure TQueryButton.SetXMLComponent(const Value: TComponent);
begin
  if not (csLoading in ComponentState) then
    FXMLUseParent := False;
  FXMLComponent := Value;
  if Value <> nil then Value.FreeNotification(Self);
end;

procedure TQueryButton.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited;
  if (Operation = opRemove) and (AComponent = FXMLComponent) then
    XMLComponent := nil;
end;

procedure TQueryButton.SetXMLUseParent(const Value: Boolean);
begin
  if Value then
    FXMLComponent := nil;
  FXMLUseParent := Value;
end;

constructor TQueryButton.Create(AOwner: TComponent);
begin
  inherited;
  FXMLUseParent := True;
end;

{ TCustomQueryButtons }

const
  DefaultQueryButtons: array[0..1] of TWebButtonClass =
  (TSubmitQueryButton, TResetQueryButton);

procedure TCustomQueryButtons.GetDefaultButtons;
begin
  if not Assigned(DefaultWebComponents) then
  begin
    DefaultWebComponents := TWebComponentList.Create(Self);
    CreateDefaultButtonClasses(DefaultQueryButtons, FWebComponents);
  end;
end;

procedure TCustomQueryButtons.ImplAddElements(AddIntf: IAddScriptElements);
begin
  inherited;
end;

function TCustomQueryButtons.ImplContent(Options: TWebContentOptions; ParentLayout: TLayout): string;
var
  ButtonsLayout: TFormLayout;

  function FormatButton(Button: TComponent): string;
  var
    Intf: IWebContent;
  begin
    Result := '';
    if Button.GetInterface(IWebContent, Intf) then
      Result := Intf.Content(Options, ButtonsLayout);
  end;
var
  Button: TComponent;
  I: Integer;
  Intf: ILayoutWebContent;
  Attribs: string;
begin
  Result := '';
  ButtonsLayout := TFormLayout.Create(ParentLayout);
  try
    // AddStringAttrib(Attribs, 'NAME', Name);
    AddQuotedAttrib(Attribs, 'STYLE', Style);
    AddQuotedAttrib(Attribs, 'CLASS', StyleRule);
    AddCustomAttrib(Attribs, Custom);
    ButtonsLayout.FTableHeader := Format(#13#10'<TABLE%s>', [Attribs]);
    for I := 0 to VisibleButtons.Count - 1 do
    begin
      Button := VisibleButtons.WebComponents[I];
      Result := Result + FormatButton(Button);
    end;
    Result := Result + ButtonsLayout.EndLayout;
  finally
    ButtonsLayout.Free;
  end;
  if Assigned(ParentLayout) and ParentLayout.GetInterface(ILayoutWebContent, Intf) then
    Result := Intf.LayoutField(Result, GetLayoutAttributes)
end;

function GetItemValuesFromDataSet(DataSet: TDataSet;
  const ItemsField, ValuesField: string;
  var ItemsStrings, ValuesStrings: TStrings): Boolean;
var
  DSValuesField, DSItemsField: TField;
begin
  Result := False;
  if Assigned(DataSet) then
  begin
    DSItemsField := nil;
    if ItemsField <> '' then
    begin
      if not (csDesigning in DataSet.ComponentState) then
        DataSet.Active := True;
      if DataSet.Active then
        DSItemsField := DataSet.FindField(ItemsField)
    end;
    if Assigned(DSItemsField) then
    begin
      if ValuesField <> '' then
        DSValuesField := DataSet.FindField(ValuesField)
      else
        DSValuesField := nil;
      ValuesStrings := TStringList.Create;
      ItemsStrings := TStringList.Create;
      try
        DataSet.First;
        while not DataSet.EOF do
        begin
          if not VarIsNull(DSItemsField.Value) then
            ItemsStrings.Add(DSItemsField.Value);
          if Assigned(DSValuesField) then
            if not VarIsNull(DSValuesField.Value) then
              ValuesStrings.Add(DSValuesField.Value);
          DataSet.Next;
        end;
        Result := True;
      except
        FreeAndNil(ValuesStrings);
        FreeAndNil(ItemsStrings);
      end;
    end;
  end
end;

function TCustomQueryButtons.VisibleButtons: TWebComponentList;
begin
  if WebFieldControls.Count > 0 then
    Result := WebFieldControls
  else
  begin
    GetDefaultButtons;
    Result := DefaultWebComponents;
  end;
end;


function TCustomQueryButtons.ImplCanAddClass(AParent: TComponent; AClass: TClass): Boolean;
begin
  Result := AClass.InheritsFrom(TQueryButton) or
     CanAddClassHelper(Self, AParent, AClass);

end;

{ TWebStatus }

function TWebStatus.ControlContent(Options: TWebContentOptions): string;
var
  Attrs: string;
  Events: string;
begin
  AddQuotedAttrib(Attrs, 'NAME', GetHTMLControlName);
  AddIntAttrib(Attrs, 'SIZE', DisplayWidth);
  AddQuotedAttrib(Attrs, 'STYLE', Style);
  AddQuotedAttrib(Attrs, 'CLASS', StyleRule);
  AddCustomAttrib(Attrs, Custom);
  if (not (coNoScript in Options.Flags)) then
    Events := EventContent(Options);
  Result := Format('<INPUT TYPE=TEXT%0:s%1:s>', [Attrs, Events]);
end;

constructor TWebStatus.Create(AOwner: TComponent);
begin
  inherited;
  FDisplayWidth := 1;
  FCaption := '*';
end;

function TWebStatus.GetCaption: string;
begin
  Result := FCaption;
  if Result = '' then
    Result := Name;
end;

function TWebStatus.ImplGetHTMLControlName: string;
begin
  Result := Name;
  if Result = '' then
    Result := Copy(ClassName, 2, Length(ClassName));
end;

class function TWebStatus.Identifier: string;
begin
  Result := '*';    // No not localize
end;

{ TWebControlGroup }

constructor TWebControlGroup.Create(AOwner: TComponent);
begin
  inherited;
  FWebComponents := TWebComponentList.Create(Self);
  FDefaultField := False;
end;

destructor TWebControlGroup.Destroy;
begin
  inherited;
  if FContainer <> nil then
    FContainer.Remove(Self);
  FWebComponents.Free;
  FDefaultWebComponents.Free;
end;

function TWebControlGroup.GetIndex: Integer;
begin
  Result := FContainer.IndexOf(Self);
end;

procedure TWebControlGroup.SetContainer(Container: TWebComponentContainer);
begin
  SetWebParent((Container as TWebComponentList).ParentComponent);
end;

procedure TWebControlGroup.SetIndex(Value: Integer);
begin
  FContainer.SetComponentIndex(Self, Value)
end;

function TWebControlGroup.GetParentComponent: TComponent;
begin
  if Assigned(FWebParent) then
    Result := FWebParent
  else
    Result := inherited GetParentComponent;
end;

function TWebControlGroup.HasParent: Boolean;
begin
  if Assigned(FWebParent) then
    Result := True
  else
    Result := inherited HasParent;
end;

procedure TWebControlGroup.ReadState(Reader: TReader);
begin
  inherited ReadState(Reader);
  SetWebParent(Reader.Parent);
end;

procedure TWebControlGroup.SetParentComponent(AParent: TComponent);
begin
  if not (csLoading in ComponentState) then
    SetWebParent(AParent);
end;

function TWebControlGroup.GetContainer: TWebComponentContainer;
begin
  Result := FContainer;
end;

procedure TWebControlGroup.SetComponentList(List: TObject);
begin
  Assert((List = nil) or (List is TWebComponentList));
  FContainer := TWebComponentList(List);
end;

function TWebControlGroup.GetComponentList: TObject;
begin
  Result := FWebComponents;
end;

function TWebControlGroup.GetDefaultComponentList: TObject;
begin
  Result := FDefaultWebComponents;
end;

procedure TWebControlGroup.SetWebParent(const Value: TComponent);
var
  List: IGetWebComponentList;
begin
  if Value <> FWebParent then
  begin
    if Assigned(Value) and (csDesigning in ComponentState) then
      ValidateWebParent(Self, Value);
    if FWebParent <> nil then
    begin
      FWebParent.GetInterface(IGetWebComponentList, List);
      if FDefaultField then
        (List.GetDefaultComponentList as TWebComponentList).Remove(Self)
      else
        (List.GetComponentList as TWebComponentList).Remove(Self)
    end;
    if Value <> nil then
    begin
      Value.GetInterface(IGetWebComponentList, List);
      if FDefaultField then
        (List.GetDefaultComponentList as TWebComponentList).Add(Self)
      else
        (List.GetComponentList as TWebComponentList).Add(Self)
    end;
    FWebParent := Value;
  end;
end;

procedure TWebControlGroup.GetChildren(Proc: TGetChildProc;
  Root: TComponent);
var
  I: Integer;
  WebComponent: TComponent;
begin
  for I := 0 to FWebComponents.Count - 1 do
  begin
    WebComponent := FWebComponents.WebComponents[I];
    if WebComponent.Owner = Root then Proc(WebComponent);
  end;
end;


procedure TWebControlGroup.SetChildOrder(Component: TComponent;
  Order: Integer);
var
  Intf: IWebComponent;
begin
  if FWebComponents.IndexOf(Component) >= 0 then
    if Component.GetInterface(IWebComponent, Intf) then
      Intf.Index := Order
    else
      Assert(False, 'Interface not supported');
end;

procedure TWebControlGroup.AddElements(AddIntf: IAddScriptElements);
begin
  inherited;
  ImplAddElements(AddIntf);
end;

function TWebControlGroup.CanAddClass(AParent: TComponent; AClass: TClass): Boolean;
begin
  Result := ImplCanAddClass(AParent, AClass);
end;

function TWebControlGroup.GetSubComponents: TObject;
begin
  Result := ImplGetSubComponents;
end;

procedure TWebControlGroup.ImplAddElements(AddIntf: IAddScriptElements);
begin
  inherited;
  //
end;

function TWebControlGroup.ImplCanAddClass(AParent: TComponent; AClass: TClass): Boolean;
begin
  Result := True;
end;

function TWebControlGroup.Content(Options: TWebContentOptions;
  ParentLayout: TLayout): string;
begin
  Result := ImplContent(Options, ParentLayout);
end;

function TWebControlGroup.ImplContent(Options: TWebContentOptions;
  ParentLayout: TLayout): string;
begin
  Result := '';
end;

function TWebControlGroup.GetLayoutAttributes: TLayoutAttributes;
begin
  Result := nil;
end;

function TWebControlGroup.ImplGetSubComponents: TObject;
begin
  Result := WebFieldControls;
end;

{ TXMLDisplayGroup }

constructor TXMLDisplayGroup.Create(AComponent: TComponent);
begin
  inherited;
  FEnableValidateFields := True;
  FXMLDataSet := TXMLDataSet.Create(Self);
  FXMLDataSet.OnChange := XMLDataChange;
end;

procedure TXMLDisplayGroup.XMLDataChange(Sender: TObject);
begin
  FreeAndNil(FDefaultWebComponents);
  EnableValidateFields := True;
end;

destructor TXMLDisplayGroup.Destroy;
begin
  inherited;
  FXMLDataSet.Free;
end;

procedure TXMLDisplayGroup.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if Assigned(XMLDataSet) then
    XMLDataSet.Notification(AComponent, Operation);
end;

function TXMLDisplayGroup.GetXmlDisplayName: string;
begin
  Result := Format(ScriptXMLDisplayName, [Self.Name]);
end;

function TXMLDisplayGroup.GetVisibleFields: TWebComponentList;
begin
  if FWebComponents.Count > 0 then
    Result := FWebComponents
  else
  begin
    if Assigned(FDefaultWebComponents) and
      (FDefaultWebComponents.Count = 0) then
      FreeAndNil(FDefaultWebComponents);
    if not Assigned(FDefaultWebComponents) then
      CreateDefaultFields;
    Result := FDefaultWebComponents;
  end;
end;

procedure TXMLDisplayGroup.CreateDefaultFields;
var
  DataSet: IMidasWebDataSet;
  WebComponent: IWebComponent;
  DataSetField: IDataSetField;
  FieldControl: TComponent;
  FieldClass: TComponentClass;
  List: TStrings;
  I: integer;
begin
  FDefaultWebComponents := TWebComponentList.Create(Self);
  DataSet := XMLDataSet.DataSet;
  if (DataSet <> nil) then
  begin
    List := TStringList.Create;
    try
      GetFieldsList(List);
      for I := 0 to List.Count - 1 do
      begin
        if not IsFieldInUse(List[I]) then
        begin
          FieldClass := TComponentClass(List.Objects[I]);
          FieldControl := FieldClass.Create(nil);  // not owned
          FieldControl.GetInterface(IWebComponent, WebComponent);
          WebComponent.Container := Self.WebFieldControls;
          if FieldControl.GetInterface(IDataSetField, DataSetField) then
             DataSetField.FieldName := List[I];
        end;
      end;
    finally
      List.Free;
    end;
  end;
end;

function TXMLDisplayGroup.FindField(const AName: string): TComponent;
var
  I: Integer;
  DataSetField: IDataSetField;
begin
  for I := 0 to FWebComponents.Count - 1 do
  begin
    if FWebComponents.WebComponents[I].GetInterface(IDataSetField, DataSetField) then
    begin
      Result := FWebComponents.WebComponents[I];
      if AnsiCompareText(DataSetField.FieldName, AName) = 0 then Exit;
    end;
  end;
  Result := nil;
end;

function TXMLDisplayGroup.GetDataSet: IMidasWebDataSet;
begin
  Result := XMLDataSet.DataSet;
end;

procedure TXMLDisplayGroup.GetFieldsList(List: TStrings);
var
  I: Integer;
  DataSet: IMidasWebDataSet;
  TextClass: TWebDataInputClass;
  StatusClass: TWebStatusClass;
begin
  if ImplCanAddClass(Self, TFieldText) then
    TextClass := TFieldText
  else if ImplCanAddClass(Self, TQueryText) then
    TextClass := TQueryText
  else if ImplCanAddClass(Self, TTextColumn) then
    TextClass := TTextColumn
  else
    TextClass := nil;

  if ImplCanAddClass(Self, TFieldStatus) then
    StatusClass := TFieldStatus
  else if ImplCanAddClass(Self, TStatusColumn) then
    StatusClass := TStatusColumn
  else
    StatusClass := nil;
  List.Clear;
  DataSet := XMLDataSet.DataSet;
  if (DataSet <> nil) then
    with Dataset do
    begin
      if Assigned(TextClass) then
        for I := 0 to FieldCount - 1 do
          if not (Fields[I].DataType in [ftADT, ftArray, ftDataSet]) then
            List.AddObject(Fields[I].FullName, TObject(TextClass));
      if Assigned(StatusClass) then
        List.AddObject(TWebStatus.Identifier, TObject(StatusClass));
    end;
end;

function TXMLDisplayGroup.GetXMLBroker: TXMLBroker;
begin
  Result := XMLDataSet.XMLBroker;
end;

function TXMLDisplayGroup.IsFieldInUse(AName: string): Boolean;
begin
  Result := FindField(AName) <> nil;
end;

function TXMLDisplayGroup.HasStatusField: Boolean;
var
  StatusField: IStatusField;
  I: Integer;
begin
  Result := False;
  for I := 0 to WebFieldControls.Count - 1 do
    if WebFieldControls.WebComponents[I].GetInterface(IStatusField, StatusField) then
    begin
      Result := True;
      break;
    end;
end;

function TXMLDisplayGroup.GetXMLDataSet: TXMLDataSet;
begin
  Result := FXMLDataSet;
end;

function TXMLDisplayGroup.GetDataSetField: string;
begin
  Result := FXMLDataSet.DataSetField;
end;

procedure TXMLDisplayGroup.SetDataSetField(const Value: string);
begin
  FXMLDataSet.DataSetField := Value;
end;

procedure TXMLDisplayGroup.SetXMLBroker(const Value: TXMLBroker);
begin
  FXMLDataSet.XMLBroker := Value;
end;

procedure TXMLDisplayGroup.ValidateDataSet;
begin
  if not Assigned(XMLBroker) then
    raise EComponentError.CreateResFmt(@sNoXMLBroker, [Name]);
end;

function TXMLDisplayGroup.GetXMLRowSetName: string;
begin
  if Assigned(XMLDataSet.XMLBroker) then
    Result := XMLDataSet.XMLBroker.RowSetVarName(XMLDataSet.DataSetPath)
  else
    Result := '';
end;

function TXMLDisplayGroup.GetIsMultipleRecordView: Boolean;
begin
  Result := ImplIsMultipleRecordView;
end;

function TXMLDisplayGroup.ImplIsMultipleRecordView: Boolean;
begin
  Result := False;
end;

function TXMLDisplayGroup.ValidateFields(AddIntf: IAddScriptElements): Boolean;
var
  I: Integer;
  ValidateField: IValidateField;
begin
  if EnableValidateFields then
  begin
    EnableValidateFields := False;
    for I := 0 to VisibleFields.Count - 1 do
      if VisibleFields[I].GetInterface(IValidateField, ValidateField) then
        if not ValidateField.ValidateField(XMLDataSet.DataSet, AddIntf) then
          EnableValidateFields := True;
  end;
  Result := not EnableValidateFields;
end;

function TXMLDisplayGroup.GetEnableValidateFields: Boolean;
begin
  Result := FEnableValidateFields;
end;

procedure TXMLDisplayGroup.SetEnableValidateFields(Value: Boolean);
begin
  FEnableValidateFields := Value;
end;

function TXMLDisplayGroup.ImplGetSubComponents: TObject;
begin
  Result := VisibleFields;
end;

procedure TXMLDisplayGroup.ImplAddElements(AddIntf: IAddScriptElements);
begin
  inherited;
  if Assigned(XMLBroker) and not (XMLBroker.Connected) then
    AddIntf.AddError(Format(sXMLBrokerNotConnected, [XMLBroker.Name]));
end;

{ TCustomDataGrid }

constructor TCustomDataGrid.Create(AOwner: TComponent);
begin
  inherited;
  FDisplayRows := 4;
  FTableAttributes := TGridAttributes.Create(Self);
  FHeadingAttributes := TGridRowAttributes.Create(Self);
  FRowAttributes := TGridRowAttributes.Create(Self);
  FTableAttributes.Border := 1;
end;

function TCustomDataGrid.FormatTable(Layout: TLayoutWebContent;
  Options: TWebContentOptions): string;

  function TableHeader: string;
  var
    Attribs: string;
  begin
    with TableAttributes do
    begin
      Attribs := Attribs + HTMLAlign[Align];
      AddIntAttrib(Attribs, 'CELLSPACING', CellSpacing);
      AddIntAttrib(Attribs, 'CELLPADDING', CellPadding);
      AddIntAttrib(Attribs, 'BORDER', Border);
      AddStringAttrib(Attribs, 'BGCOLOR', BgColor);
      AddQuotedAttrib(Attribs, 'STYLE', Style);
      AddQuotedAttrib(Attribs, 'CLASS', StyleRule);
      AddCustomAttrib(Attribs, Custom);
    end;
    Result := Format(#13#10'<TABLE%s>', [Attribs]);
  end;

  function RowHeader(HeadingAttributes: TGridRowAttributes): string;
  var
    Attribs: string;
  begin
    with HeadingAttributes do
    begin
      Attribs := Attribs + HTMLAlign[Align];
      Attribs := Attribs + HTMLVAlign[VAlign];
      AddQuotedAttrib(Attribs, 'BGCOLOR', BgColor);
      AddQuotedAttrib(Attribs, 'STYLE', Style);
      AddQuotedAttrib(Attribs, 'CLASS', StyleRule);
      AddCustomAttrib(Attribs, Custom);
    end;
    Result := Format('<TR%s>', [Attribs]);
  end;

var
  I: Integer;
  OneRow: string;
  Field: TWebDataDisplay;
  RowHeaderStr: string;
  FormatColumn: IFormatColumn;
begin
  Result := TableHeader + RowHeader(HeadingAttributes) + #13#10;
  for I := 0 to VisibleFields.Count - 1 do
  begin
    if VisibleFields[I] is TWebDataDisplay then
    begin
      Field := TWebDataDisplay(VisibleFields[I]);
      if Field.GetInterface(IFormatColumn, FormatColumn) then
      begin
        Result := Result + FormatColumn.FormatColumnHeading;
        OneRow := OneRow + FormatColumn.FormatColumnData(Field.Content(Options, Layout));
      end
      else
      begin
        // Default formatting
        Result := Result + FormatColumnHeading(Field);
        OneRow := OneRow + FormatColumnData(Field, Field.Content(Options, Layout));
      end;
    end;
  end;
  Result := Result + '</TR>';
  RowHeaderStr := RowHeader(RowAttributes);
  for I := 0 to DisplayRows - 1 do
    Result := Format('%0:s%1:s%2:s</TR>'#13#10, [Result, RowHeaderStr, OneRow]);
  Result := Result + '</TABLE>';
end;

function TCustomDataGrid.ImplContent(Options: TWebContentOptions; ParentLayout: TLayout): string;
var
  TableLayout: TGridLayout;
  Intf: ILayoutWebContent;
begin
  TableLayout := TGridLayout.Create(ParentLayout);
  try
    Result := FormatTable(TableLayout, Options);
  finally
    TableLayout.Free;
  end;
  if Assigned(ParentLayout) and ParentLayout.GetInterface(ILayoutWebContent, Intf) then
    Result := Intf.LayoutTable(Result, GetLayoutAttributes)
end;

procedure TCustomDataGrid.SetTableAttributes(
  const Value: TGridAttributes);
begin
  FTableAttributes.Assign(Value);
end;

destructor TCustomDataGrid.Destroy;
begin
  inherited;
  FTableAttributes.Free;
  FHeadingAttributes.Free;
  FRowAttributes.Free;
end;

procedure TCustomDataGrid.SetHeadingAttributes(
  const Value: TGridRowAttributes);
begin
  FHeadingAttributes.Assign(Value);
end;

function TCustomQueryForm.ImplCanAddClass(AParent: TComponent; AClass: TClass): Boolean;
begin
  Result := AClass.InheritsFrom(TCustomQueryButtons) or
    AClass.InheritsFrom(TQueryFieldGroup)
    or
    AClass.InheritsFrom(TCustomLayoutGroup);
end;

function TCustomDataGrid.ImplCanAddClass(AParent: TComponent; AClass: TClass): Boolean;
begin
  Result := AClass.InheritsFrom(TWebDataDisplay) and
    TWebDataInputClass(AClass).IsColumn;
end;

procedure TCustomDataGrid.ImplAddElements(AddIntf: IAddScriptElements);
begin
  inherited;
  if Assigned(XMLDataSet.XMLBroker) then
  begin
    AddIntf.AddRowSet(XMLDataSet.XMLBroker, XMLDataSet.DataSetPath);
    DefineXMLDisplayBlock(AddIntf, Self, GetXMLRowSetName);
  end
  else
    AddIntf.AddError(Format(sXMLBrokerNotDefined, [Self.Name]));
end;

procedure TCustomDataGrid.SetRowAttributes(
  const Value: TGridRowAttributes);
begin
  FRowAttributes.Assign(Value);
end;

function TCustomDataGrid.ImplIsMultipleRecordView: Boolean;
begin
  Result := True;
end;

{ TXMLData }

procedure TXMLData.Changed;
begin
  if Assigned(FOnChange) then FOnChange(Self);
end;

procedure TXMLData.ChangedXMLBroker;
begin
  Changed;
end;

constructor TXMLData.Create(AParent: TComponent);
begin
  inherited Create;
  FParent := AParent;
end;

procedure TXMLData.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  if (Operation = opRemove) and (AComponent = FXMLBroker) then
    XMLBroker := nil;
end;

procedure TXMLData.SetXMLBroker(const Value: TXMLBroker);
begin
  if FXMLBroker <> Value then
  begin
    FXMLBroker := Value;
    if Value <> nil then Value.FreeNotification(FParent);
    ChangedXMLBroker;
    // Automatically connect when setting the XMLBroker property
    if not (csLoading in FParent.ComponentState) then
      if Assigned(FXMLBroker) then
        FXMLBroker.Connected := True;
  end;
end;

function TXMLData.GetXMLBroker: TXMLBroker;
begin
  Result := FXMLBroker;
end;

{ TXMLDataSet }

procedure TXMLDataSet.ChangedDataSetField;
begin
  if Assigned(FDataSet) then
  begin
    FDataSet.RemoveOnDataChange(WrapperDataChange);
    // Add to list to avoid destroying
    // TClientDataSet in a notification
    FDiscardDataSetList.Add(FDataSet);
  end;
  FDataSet := nil;
  Changed;
end;

procedure TXMLDataSet.ChangedXMLBroker;
begin
  if Assigned(FDataSet) then
  begin
    FDataSet.RemoveOnDataChange(WrapperDataChange);
    // Add to list to avoid destroying
    // a TClientDataSet in a notification
    FDiscardDataSetList.Add(FDataSet);
  end;
  FDataSet := nil;
  if not (csLoading in FParent.ComponentState) then
    FDataSetField := '';
  inherited;
end;

constructor TXMLDataSet.Create(AParent: TComponent);
begin
  inherited;
  XMLDataSetList.Add(Self);
  FDiscardDataSetList := TInterfaceList.Create;
end;

function TXMLDataSet.GetDataSetPath: TStrings;
var
  Dot: Integer;
  FieldName: string;
  S: string;
begin
  if not Assigned(FDataSetPath) then
    FDataSetPath := TStringList.Create;
  FDataSetPath.Clear;
  S := DataSetField;
  while S <> '' do
  begin
    Dot := Pos('.', S);
    if Dot = 0 then
    begin
      FieldName := Trim(S);
      S := '';
    end
    else
    begin
      FieldName := Trim(Copy(S, 1, Dot-1));
      System.Delete(S, 1, Dot);
    end;
    if FieldName <> '' then
      FDataSetPath.Add(FieldName);
  end;
  Result := FDataSetPath;
end;

function TXMLDataSet.CreateDataSet: IMidasWebDataSet;
var
  Wrapper: TDataSetWrapper;
  Field: TField;
  I: Integer;
  FieldName: string;
  ProvComp: TComponent;
begin
  Wrapper := nil; 
  if Assigned(XMLBroker) and not (csDesigning in XMLBroker.ComponentState) then
    XMLBroker.Connected := True;
  if Assigned(XMLBroker) and (XMLBroker.Connected) then
  begin
    Wrapper := TDataSetWrapper.Create;
    try
      if Assigned(XMLBroker.Owner) and (XMLBroker.ProviderName <> '') and (not Assigned(XMLBroker.RemoteServer)) then
      begin
        ProvComp := XMLBroker.Owner.FindComponent(XMLBroker.ProviderName);
        if Assigned(ProvComp) and (ProvComp is TCustomProvider) then
          Wrapper.FDataSet.SetProvider(ProvComp)
      end
      else
      begin
        Wrapper.FDataSet.RemoteServer := XMLBroker.RemoteServer;
        Wrapper.FDataSet.ProviderName := XMLBroker.ProviderName;
      end;
      Wrapper.FDataSet.PacketRecords := 0; // Meta data only
      Wrapper.FDataSet.Active := True;
      Wrapper.FDetailDataSet := Wrapper.FDataSet;
      for I := 0 to DataSetPath.Count - 1 do
      begin
        FieldName := DataSetPath[I];
        if FieldName = '' then
          raise Exception.CreateRes(@sDataSetFieldBlank);
        Field := Wrapper.FDetailDataSet.Fields.FieldByName(FieldName);
        if not Assigned(Field) then
          raise Exception.CreateResFmt(@sDataSetFieldNotFound, [FieldName]);
        if not (Field is TDataSetField) then
          raise Exception.CreateResFmt(@sNotDataSetField, [FieldName]);
        Wrapper.FDetailDataSet := TDataSetField(Field).NestedDataSet;
        Assert(Assigned(Wrapper.FDetailDataSet), 'NestedDataSet is nil');
      end
    except
      Wrapper.Free;
      Wrapper := nil;
      Application.HandleException(Self);
    end;
  end;
  if Assigned(Wrapper) then
  begin
    Result := Wrapper as IMidasWebDataSet;
    Result.AddOnDataChange(WrapperDataChange);
  end
  else
    Result := nil;
end;

procedure TXMLDataSet.WrapperDataChange(Sender: TObject);
begin
  FDataSet.RemoveOnDataChange(WrapperDataChange);
  // Add to list to avoid destroying
  // a TClientDataSet in a notification
  FDiscardDataSetList.Add(FDataSet);
  FDataSet := nil;
  Changed;
end;

function TXMLDataSet.FindDataSet: IMidasWebDataSet;
var
  I: Integer;
  XMLDataSet: TXMLDataSet;
begin
  for I := 0 to XMLDataSetList.Count - 1 do
  begin
    XMLDataSet := TXMLDataSet(XMLDataSetList[I]);
    Result := XMLDataSet.FDataSet;
    if (Result <> nil) and (CompareXMLData(XMLDataSet)) then
      Exit;
  end;
  Result := nil;
end;

function TXMLDataSet.GetDataSet: IMidasWebDataSet;
begin
  if not Assigned(FDataSet) then
  begin
    FDiscardDataSetList.Clear;
    FDataSet := FindDataSet;
    if not Assigned(FDataSet) then
      FDataSet := CreateDataSet
    else
      FDataSet.AddOnDataChange(WrapperDataChange);
  end;
  Result := FDataSet;
end;

procedure TXMLDataSet.SetDataSetField(const Value: string);
begin
  if FDataSetField <> Value then
  begin
    FDataSetField := Value;
    ChangedDataSetField;
  end;
end;

destructor TXMLDataSet.Destroy;
begin
  if Assigned(FDataSet) then
    FDataSet.RemoveOnDataChange(WrapperDataChange);
  if XMLBroker <> nil then
    XMLBroker.RemoveNotify(Self);
  inherited;
  FDataSetPath.Free;
  XMLDataSetList.Remove(Self);
end;

function TXMLDataSet.CompareXMLData(XMLDataSet: TXMLDataSet): Boolean;
begin
  Result := (XMLBroker = XMLDataSet.XMLBroker)
     and (DataSetField = XMLDataSet.DataSetField);
end;

function TXMLDataSet.GetDataSetField: string;
begin
  Result := FDataSetField;
end;

function TXMLDataSet._AddRef: Integer;
begin
  Result := -1;
end;

function TXMLDataSet._Release: Integer;
begin
  Result := -1;
end;

function TXMLDataSet.QueryInterface(const IID: TGUID; out Obj): HResult;
begin
  if GetInterface(IID, Obj) then Result := S_OK
  else Result := E_NOINTERFACE
end;

procedure TXMLDataSet.ConnectionChange(Sender: TComponent;
  Connecting: Boolean);
begin
  Changed;
end;

procedure TXMLDataSet.SetXMLBroker(const Value: TXMLBroker);
begin
  if XMLBroker <> nil then
    XMLBroker.RemoveNotify(Self);
  inherited;
  if XMLBroker <> nil then
    XMLBroker.AddNotify(Self);
end;

{ TXMLDataSetParent }

procedure TXMLDataSetParent.ChangedUseParent;
begin
  if UseParent then
  begin
    FXMLBroker := nil;
    FDataSetField := '';
  end;
  Changed;
end;

procedure TXMLDataSetParent.SetUseParent(const Value: Boolean);
begin
  if Value <> FUseParent then
  begin
    FUseParent := Value;
    ChangedUseParent;
  end;
end;

procedure TXMLDataSetParent.ChangedDataSetField;
begin
  if not (csLoading in Parent.ComponentState) then
    FUseParent := False;
  inherited;
end;

procedure TXMLDataSetParent.ChangedXMLBroker;
begin
  if Assigned(Parent) and not (csLoading in Parent.ComponentState) then
    FUseParent := False;
  inherited;
end;

function TXMLDataSetParent.ParentDataSetField: string;
var
  XMLDataSet: TXMLDataSet;
begin
  XMLDataSet := ParentXMLDataSet;
  if Assigned(XMLDataSet) then
    Result := XMLDataSet.DataSetField
  else
    Result := '';
end;

function TXMLDataSetParent.GetDataSetField: string;
begin
  if not UseParent then
    Result := inherited GetDataSetField
  else
    Result := ParentDataSetField;
end;

function TXMLDataSetParent.ParentXMLBroker: TXMLBroker;
var
  XMLDataSet: TXMLDataSet;
begin
  XMLDataSet := ParentXMLDataSet;
  if Assigned(XMLDataSet) then
    Result := XMLDataSet.XMLBroker
  else
    Result := nil;
end;

function TXMLDataSetParent.GetXMLBroker: TXMLBroker;
begin
  if not UseParent then
    Result := inherited GetXMLBroker
  else
    Result := ParentXMLBroker;
end;

function TXMLDataSetParent.ParentXMLDataSet: TXMLDataSet;
var
  Component: TComponent;
  Intf: IDataSetComponent;
begin
  Component := Parent.GetParentComponent;
  while Assigned(Component) do
  begin
    if Component.GetInterface(IDataSetComponent, Intf) then
    begin
      Result := Intf.XMLDataSet;
      Exit;
    end;
    Component := Component.GetParentComponent;
  end;
  Result := nil;
end;

{ TXMLDataParent }

procedure TXMLDataParent.ChangedUseParent;
begin
  if UseParent then
    FXMLBroker := nil;
  Changed;
end;

procedure TXMLDataParent.SetUseParent(const Value: Boolean);
begin
  if Value <> FUseParent then
  begin
    FUseParent := Value;
    ChangedUseParent;
  end;
end;

procedure TXMLDataParent.ChangedXMLBroker;
begin
  if Assigned(Parent) and not (csLoading in Parent.ComponentState) then
    FUseParent := False;
  inherited;
end;

function TXMLDataParent.ParentXMLBroker: TXMLBroker;
var
  Component, XMLDisplay: TComponent;
  DataSetComponent: IDataSetComponent;
  XMLDisplayReference: IXMLDisplayReference;
begin
  Component := Parent.GetParentComponent;
  while Assigned(Component) do
  begin
    if Component.GetInterface(IXMLDisplayReference, XMLDisplayReference) then
    begin
      XMLDisplay := XMLDisplayReference.XMLDisplayComponent;
      if Assigned(XMLDisplay) and
        XMLDisplay.GetInterface(IDataSetComponent, DataSetComponent) then
      begin
        Result := DataSetComponent.XMLDataSet.XMLBroker;
        Exit;
      end;
    end;

    if Component.GetInterface(IDataSetComponent, DataSetComponent) then
    begin
      Result := DataSetComponent.XMLDataSet.XMLBroker;
      Exit;
    end;
    Component := Component.GetParentComponent;
  end;
  Result := nil;
end;

function TXMLDataParent.GetXMLBroker: TXMLBroker;
begin
  if not UseParent then
    Result := inherited GetXMLBroker
  else
    Result := ParentXMLBroker;
end;

{ TXMLDisplay }

procedure TXMLDisplay.Changed;
begin
  if Assigned(FOnChange) then FOnChange(Self);
end;

procedure TXMLDisplay.ChangedDisplayComponent;
begin
  Changed;
end;

constructor TXMLDisplay.Create(AParent: TComponent);
begin
  inherited Create;
  FParent := AParent;
end;

function TXMLDisplay.GetDisplayComponent: TComponent;
begin
  Result := FDisplayComponent;
end;

procedure TXMLDisplay.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  if (Operation = opRemove) and (AComponent = FDisplayComponent) then
    DisplayComponent := nil;
end;

procedure TXMLDisplay.SetDisplayComponent(const Value: TComponent);
begin
  if FDisplayComponent <> Value then
  begin
    FDisplayComponent := Value;
    if Value <> nil then Value.FreeNotification(FParent);
    ChangedDisplayComponent;
  end;
end;

{ TXMLDisplayParent }

procedure TXMLDisplayParent.ChangedDisplayComponent;
begin
  if Assigned(Parent) and not (csLoading in Parent.ComponentState) then
    FUseParent := False;
  inherited;
end;

procedure TXMLDisplayParent.ChangedUseParent;
begin
  if UseParent then
    FDisplayComponent := nil;
  Changed;
end;

constructor TXMLDisplayParent.Create(AParent: TComponent);
begin
  inherited;
  FUseParent := True;
end;

function TXMLDisplayParent.GetDisplayComponent: TComponent;
var
  Intf: IXMLDisplayReference;
  Reference: TComponent;
begin
  if not UseParent then
    Result := inherited GetDisplayComponent
  else
  begin
    Reference := Parent;
    while Assigned(Reference) do
    begin
      if Reference.GetInterface(IXMLDisplayReference, Intf) then
      begin
        Result := Intf.XMLDisplayComponent;
        Exit;
      end;
      Reference := Reference.GetParentComponent;
    end;
    Result := nil;
  end;
end;

procedure TXMLDisplayParent.SetUseParent(const Value: Boolean);
begin
  if Value <> FUseParent then
  begin
    FUseParent := Value;
    Changed;
  end;
end;

function TCustomQueryForm.ImplContent(Options: TWebContentOptions;
  ParentLayout: TLayout): string;
var
  FormLayout: TFormLayout;

  function FormatField(Field: TComponent): string;
  var
    Intf: IWebContent;
  begin
    if Field.GetInterface(IWebContent, Intf) then
      Result := Intf.Content(Options, FormLayout)
    else
      Result := '';
  end;

var
  I: Integer;
  Intf: ILayoutWebContent;
begin
  FormLayout := TFormLayout.Create(ParentLayout);
  try
    Result := GetHTMLFormTag(Options);
    for I := 0 to VisibleFields.Count - 1 do
    begin
      Result := Result +
        FormatField(VisibleFields[I]);
    end;
    Result := Result + FormLayout.EndLayout;
    Result := Result + '</FORM>';
    if Assigned(ParentLayout) and ParentLayout.GetInterface(ILayoutWebContent, Intf) then
      Result := Intf.LayoutField(Result, GetLayoutAttributes)
  finally
    FormLayout.Free;
  end;
end;

{ TStatusColumn }

class function TStatusColumn.IsColumn: Boolean;
begin
  Result := True;
end;

{ TSelectOptionsColumn }

class function TSelectOptionsColumn.IsColumn: Boolean;
begin
  Result := True;
end;

{ TTextColumn }

class function TTextColumn.IsColumn: Boolean;
begin
  Result := True;
end;

{ TFieldGroup }

constructor TCustomFieldGroup.Create(AOwner: TComponent);
begin
  inherited;
  FLayoutAttributes := TLayoutAttributes.Create;
end;

destructor TCustomFieldGroup.Destroy;
begin
  inherited;
  FLayoutAttributes.Free;
end;

function TCustomFieldGroup.ImplContent(Options: TWebContentOptions;
  ParentLayout: TLayout): string;
var
  FormLayout: TFormLayout;

  function FormatField(Field: TComponent): string;
  var
    Intf: IWebContent;
  begin
    if Field.GetInterface(IWebContent, Intf) then
      Result := Intf.Content(Options, FormLayout)
    else
      Result := '';
  end;
var
  I: Integer;
  Intf: ILayoutWebContent;
  Attribs: string;
begin
  Result := '';
  FormLayout := TFormLayout.Create(ParentLayout);
  try
    // AddStringAttrib(Attribs, 'NAME', Name);
    AddQuotedAttrib(Attribs, 'STYLE', Style);
    AddQuotedAttrib(Attribs, 'CLASS', StyleRule);
    AddCustomAttrib(Attribs, Custom);
    FormLayout.TableHeader := Format(#13#10'<TABLE%s>', [Attribs]);
    for I := 0 to VisibleFields.Count - 1 do
    begin
      Result := Result +
        FormatField(VisibleFields[I]);
    end;
    Result := Result +  FormLayout.EndLayout;
    if Assigned(ParentLayout) and ParentLayout.GetInterface(ILayoutWebContent, Intf) then
      Result := Intf.LayoutTable(Result, GetLayoutAttributes)
  finally
    FormLayout.Free;
  end;
end;

{ TFieldGroup }

procedure TFieldGroup.ImplAddElements(AddIntf: IAddScriptElements);
begin
  inherited;
  if Assigned(XMLDataSet.XMLBroker) then
  begin
    AddIntf.AddRowSet(XMLDataSet.XMLBroker, XMLDataSet.DataSetPath);
    DefineXMLDisplayBlock(AddIntf, Self, GetXMLRowSetName);
  end
  else
    AddIntf.AddError(Format(sXMLBrokerNotDefined, [Self.Name]));
end;

function TFieldGroup.ImplCanAddClass(AParent: TComponent;
  AClass: TClass): Boolean;
begin
  Result :=
    (AClass.InheritsFrom(TWebDataDisplay) and not
      (TWebDataDisplayClass(AClass).IsColumn or TWebDataDisplayClass(AClass).IsQueryField))
       or AClass.InheritsFrom(TCustomLayoutGroup);
end;

{ TQueryText }

procedure TQueryText.AddAttributes(var Attrs: string);
begin
  Inherited;
  AddQuotedAttrib(Attrs, 'VALUE', Text);
  AddBoolAttrib(Attrs, 'READONLY', ReadOnly);
  AddIntAttrib(Attrs, 'MAXLENGTH', MaxWidth);
end;

constructor TQueryText.Create(AOwner: TComponent);
begin
  inherited;
  FMaxWidth := -1;
end;

function TQueryText.GetText: string;
begin
  Result := FText;
end;

class function TQueryText.IsQueryField: Boolean;
begin
  Result := True;
end;

procedure TQueryText.SetText(const Value: string);
begin
  FText := Value;
end;

{ TQueryTextArea }

procedure TQueryTextArea.AddAttributes(var Attrs: string);
begin
  inherited;
  AddBoolAttrib(Attrs, 'READONLY', ReadOnly);
end;

function TQueryTextArea.ControlContent(
  Options: TWebContentOptions): string;
var
  Attrs: string;
  Events: string;
begin
  AddAttributes(Attrs);
  if (not (coNoScript in Options.Flags)) then
    Events := EventContent(Options);
  Result := Format('<TEXTAREA%0:s%1:s>%2:s</TEXTAREA>', [Attrs, Events, Lines.Text]);
end;

constructor TQueryTextArea.Create(AOwner: TComponent);
begin
  inherited;
  FLines := TStringList.Create;
end;

destructor TQueryTextArea.Destroy;
begin
  inherited;
  FLines.Free;
end;

function TQueryTextArea.GetText: string;
begin
  Result := Lines.Text;
end;

class function TQueryTextArea.IsQueryField: Boolean;
begin
  Result := True;
end;

procedure TQueryTextArea.SetLines(const Value: TStrings);
begin
  FLines.Assign(Value);
end;

procedure TQueryTextArea.SetText(const Value: string);
begin
  Lines.Text := Value;
end;

{ TQueryRadioGroup }

procedure TQueryRadioGroup.AddAttributes(var Attrs: string);
begin
  inherited;
  AddBoolAttrib(Attrs, 'READONLY', ReadOnly);
end;

function TQueryRadioGroup.GetCheckIndex(ItemsStrings,
  ValuesStrings: TStrings): Integer;
begin
  Result := ItemsStrings.IndexOf(Text);
  if (Result = -1) and Assigned(ValuesStrings) then
    Result := ValuesStrings.IndexOf(Text);
end;

function TQueryRadioGroup.GetText: string;
begin
  Result := FText;
end;

class function TQueryRadioGroup.IsQueryField: Boolean;
begin
  Result := True;
end;

procedure TQueryRadioGroup.SetText(const Value: string);
begin
  FText := Value;
end;

{ TQuerySelectOptions }

function TQuerySelectOptions.GetSelectIndex(ItemsStrings,
  ValuesStrings: TStrings): Integer;
begin
  Result := ItemsStrings.IndexOf(Text);
  if (Result = -1) and Assigned(ValuesStrings) then
    Result := ValuesStrings.IndexOf(Text);
end;

function TQuerySelectOptions.GetText: string;
begin
  Result := FText;
end;

class function TQuerySelectOptions.IsQueryField: Boolean;
begin
  Result := True;
end;

procedure TQuerySelectOptions.SetText(const Value: string);
begin
  FText := Value;
end;

{ TTextAreaColumn }

class function TTextAreaColumn.IsColumn: Boolean;
begin
  Result := True;
end;

{ TCustomLayoutGroup }

constructor TCustomLayoutGroup.Create(AComponent: TComponent);
begin
  inherited;
  FDisplayColumns := -1;
  FLayoutAttributes := TLayoutAttributes.Create;
end;

destructor TCustomLayoutGroup.Destroy;
begin
  inherited;
  FLayoutAttributes.Free;
end;

function TCustomLayoutGroup.ImplCanAddClass(AParent: TComponent; AClass: TClass): Boolean;
var
  Intf: IWebComponentEditor;
  Parent: TComponent;
begin
  Parent := GetParentComponent;
  if Assigned(Parent) and Parent.GetInterface(IWebComponentEditor, Intf) then
    Result := Intf.CanAddClass(AParent, AClass)
  else
    Result := not Assigned(Parent);
end;

function TCustomLayoutGroup.ImplContent(Options: TWebContentOptions;
  ParentLayout: TLayout): string;
var
  FormLayout: TFormLayout;

  function FormatField(Field: TComponent): string;
  var
    Intf: IWebContent;
  begin
    if Field.GetInterface(IWebContent, Intf) then
      Result := Intf.Content(Options, FormLayout)
    else
      Result := '';
  end;

  function Min(X, Y: Integer): Integer;
  begin
    Result := X;
    if X > Y then Result := Y;
  end;
var
  I: Integer;
  Intf: ILayoutWebContent;
  Attribs: string;
begin
  Result := '';
  if WebFieldControls.Count = 0 then
    Exit;
  FormLayout := TFormLayout.Create(ParentLayout);
  try
    // AddStringAttrib(Attribs, 'NAME', Name);
    AddQuotedAttrib(Attribs, 'STYLE', Style);
    AddQuotedAttrib(Attribs, 'CLASS', StyleRule);
    AddCustomAttrib(Attribs, Custom);

    if DisplayColumns >= 1 then
    begin
      FormLayout.ColumnCount := Min(DisplayColumns, WebFieldControls.Count);
      FormLayout.BreakButtons := True;
    end;
    FormLayout.TableHeader :=
      Format(#13#10'<TABLE%s>', [Attribs]);
    for I := 0 to WebFieldControls.Count - 1 do
    begin
      Result := Result +
        FormatField(WebFieldControls[I]);
    end;
    Result := Result + FormLayout.EndLayout;

    if Assigned(ParentLayout) and ParentLayout.GetInterface(ILayoutWebContent, Intf) then
      Result := Intf.LayoutTable(Result, GetLayoutAttributes)
  finally
    FormLayout.Free;
  end;
end;

function TGridLayout.ImplLayoutTable(const HTMLTable: string;
  Attributes: TLayoutAttributes): string;
begin
  Assert(False, 'Unexpected call to ImplLayoutTable');
end;

function TCustomLayoutGroup.GetLayoutAttributes: TLayoutAttributes;
begin
  with FLayoutAttributes do
  begin
    ControlAttributes := '';
    AddQuotedAttrib(ControlAttributes, 'STYLE', Style);
    AddQuotedAttrib(ControlAttributes, 'CLASS', StyleRule);
    AddCustomAttrib(ControlAttributes, Custom);
  end;
  Result := FLayoutAttributes;
end;

{ TCaptionAttributes }

constructor TCaptionAttributes.Create(AParent: TComponent);
begin
  inherited Create;
  FParent := AParent;
end;

{ TQueryFieldGroup }

function TQueryFieldGroup.IsParamInUse(AName: string): Boolean;
begin
  Result := FindParam(AName) <> nil;
end;

function TQueryFieldGroup.FindParam(const AName: string): TComponent;
var
  I: Integer;
  QueryField: IQueryField;
begin
  for I := 0 to FWebComponents.Count - 1 do
  begin
    if FWebComponents.WebComponents[I].GetInterface(IQueryField, QueryField) then
    begin
      Result := FWebComponents.WebComponents[I];
      if AnsiCompareText(QueryField.ParamName, AName) = 0 then Exit;
    end;
  end;
  Result := nil;
end;

procedure TQueryFieldGroup.GetParamsList(List: TStrings);
var
  I: Integer;
  TextClass: TWebDataInputClass;
begin
  if ImplCanAddClass(Self, TFieldText) then
    TextClass := TFieldText
  else if ImplCanAddClass(Self, TQueryText) then
    TextClass := TQueryText
  else if ImplCanAddClass(Self, TTextColumn) then
    TextClass := TTextColumn
  else
    TextClass := nil;

  List.Clear;
  if XMLDataSet.XMLBroker <> nil then
    with XMLDataSet.XMLBroker do
    begin
      if Params.Count = 0 then
        FetchParams;
      for I := 0 to Params.Count - 1 do
        List.AddObject(Params.Items[I].Name, TObject(TextClass));
    end;
end;

function TQueryFieldGroup.ImplCanAddClass(AParent: TComponent;
  AClass: TClass): Boolean;
begin
  Result :=
    (AClass.InheritsFrom(TWebDataDisplay) and
      TWebDataDisplayClass(AClass).IsQueryField)
       or AClass.InheritsFrom(TCustomLayoutGroup);
end;

{ TWebButton }

constructor TWebButton.Create(AOwner: TComponent);
begin
  inherited;
  FDefaultButton := AOwner = nil;
end;

destructor TWebButton.Destroy;
begin
  inherited;
  if FWebButtonsList <> nil then
    FWebButtonsList.Remove(Self);
end;

function TWebButton.GetContainer: TWebComponentContainer;
begin
  Result := FWebButtonsList;
end;

function TWebButton.GetIndex: Integer;
begin
  Result := FWebButtonsList.IndexOf(Self);
end;

function TWebButton.GetParentComponent: TComponent;
begin
  if FWebParent <> nil then
    Result := FWebParent else
    Result := inherited GetParentComponent;
end;

function TWebButton.HasParent: Boolean;
begin
  if FWebParent <> nil then
    Result := True else
    Result := inherited HasParent;
end;

procedure TWebButton.ReadState(Reader: TReader);
begin
  inherited ReadState(Reader);
  SetWebParent(Reader.Parent);
end;

procedure TWebButton.SetComponentList(List: TObject);
begin
  Assert((List = nil) or (List is TWebComponentList));
  FWebButtonsList := TWebComponentList(List);
end;

procedure TWebButton.SetIndex(Value: Integer);
begin
  FWebButtonsList.SetComponentIndex(Self, Value)
end;

procedure TWebButton.SetContainer(
  Container: TWebComponentContainer);
begin
  SetWebParent((Container as TWebComponentList).ParentComponent);
end;

procedure TWebButton.SetParentComponent(AParent: TComponent);
begin
  if not (csLoading in ComponentState) then
    SetWebParent(AParent);
end;

procedure TWebButton.SetWebParent(const Value: TComponent);
var
  List: IGetWebComponentList;
begin
  if Value <> FWebParent then
  begin
    if Assigned(Value) and (csDesigning in ComponentState) then
      ValidateWebParent(Self, Value);
    if FWebParent <> nil then
    begin
      FWebParent.GetInterface(IGetWebComponentList, List);
      if FDefaultButton then
        (List.GetDefaultComponentList as TWebComponentList).Remove(Self)
      else
        (List.GetComponentList as TWebComponentList).Remove(Self)
    end;
    if Value <> nil then
    begin
      Value.GetInterface(IGetWebComponentList, List);
      if FDefaultButton then
        (List.GetDefaultComponentList as TWebComponentList).Add(Self)
      else
        (List.GetComponentList as TWebComponentList).Add(Self)
    end;
    FWebParent := Value;
  end;
end;

function TWebButton.Content(Options: TWebContentOptions; Layout: TLayout): string;
begin
  Result := ImplContent(Options, Layout);
end;

function TWebButton.GetCaption: string;
begin
  Result := FCaption;
end;

function TWebButton.GetLayoutAttributes: TLayoutAttributes;
begin
  Result := nil;
end;

function TCustomFieldGroup.GetLayoutAttributes: TLayoutAttributes;
begin
  with FLayoutAttributes do
  begin
    AddQuotedAttrib(ControlAttributes, 'STYLE', Style);
    AddQuotedAttrib(ControlAttributes, 'CLASS', StyleRule);
    AddCustomAttrib(ControlAttributes, Custom);
  end;
  Result := FLayoutAttributes;
end;

{ TGridAttributes }

procedure TGridAttributes.AssignTo(Dest: TPersistent);
begin
  if Dest is TGridAttributes then
    with TGridAttributes(Dest) do
    begin
      FStyle := Self.FStyle;
      FStyleRule := Self.FStyleRule;
      FAlign := Self.FAlign;
      FBorder := Self.FBorder;
      FBgColor := Self.FBgColor;
      FCellSpacing := Self.FCellSpacing;
      FCellPadding := Self.FCellPadding;
      FCustom := Self.FCustom;
    end else inherited AssignTo(Dest);
end;

constructor TGridAttributes.Create(AParent: TComponent);
begin
  inherited Create;
  FParent := AParent;
  FBorder := 1;
  FCellPadding := -1;
  FCellSpacing := -1;
end;

{ TGridRowAttributes }

procedure TGridRowAttributes.AssignTo(Dest: TPersistent);
begin
  if Dest is TGridRowAttributes then
    with TGridRowAttributes(Dest) do
    begin
      FAlign := Self.FAlign;
      FVAlign := Self.FVAlign;
      FBgColor := Self.FBgColor;
      FStyle := Self.FStyle;
      FStyleRule := Self.FStyleRule;
      FCustom := Self.FCustom;
    end else inherited AssignTo(Dest);
end;

constructor TGridRowAttributes.Create(AParent: TComponent);
begin
  inherited Create;
  FParent := AParent;
  FAlign := haDefault;
  VAlign := haVDefault;
end;

{ TClientDataSetEvent }

procedure TClientDataSetEvent.DataEvent(Event: TDataEvent; Info: Integer);
begin
  inherited;
  if (Event = deConnectChange) and (Info = 0) then
  begin
    if Assigned(FOnDataChange) then
      FOnDataChange(Self);
  end;
end;

initialization
  XMLDataSetList := TList.Create;
finalization
  XMLDataSetList.Free;
  XMLDataSetList := nil;
end.
