
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{   Copyright (c) 1999-2001 Borland Software Corp.      }
{                                                       }
{*******************************************************}

unit WebForm;

interface

{$IFDEF MSWINDOWS}
uses Classes, Messages, HTTPApp, HTTPProd, WebComp, DB, SiteComp, WebModu,
  MidItems, Contnrs;
{$ENDIF}
{$IFDEF LINUX}
uses Classes, HTTPApp, HTTPProd, WebComp, DB, SiteComp, WebModu,
  MidItems, Contnrs;
{$ENDIF}

type

  IGetAdapterVariableName = interface
  ['{0D4BF7F5-332A-11D4-A474-00C04F6BB853}']
    function GetAdapterVariableName: string;
    property AdapterVariableName: string read GetAdapterVariableName;
  end;

  IGetAdapterOfDisplay = interface
  ['{CB84BC96-4C65-11D4-A48B-00C04F6BB853}']
    function GetAdapter: TComponent;
  end;

  IGetVariablesContainerOfDisplay = interface
  ['{D36B6884-33DE-4E50-8397-45A085C09D95}']
    function GetVariablesContainer: TComponent;
  end;

  IGetAdapterModeOfDisplay = interface
  ['{C4175F0B-BF2F-4C2A-ADAA-50F7DD3A8BE2}']
    function GetAdapterModeOfDisplay: string;
    function GetAdapterModeOfAdapter: string;
  end;

  TAbstractControlRequirements = class
  public
    procedure RequiresMultipartForm; virtual; abstract;
    function IsFunctionDefined(const AName: string): Boolean; virtual; abstract;
    procedure DefineFunction(const AName, ABody: string); virtual; abstract;
    procedure DefineVariable(const AName, AValue: string; AAdapter: Boolean); virtual; abstract;
    function IsVariableDefined(const AName: string): Boolean; virtual; abstract;
  end;

  IGetControlRequirements = interface
  ['{4AB9249B-D98D-462D-9AE0-6820D208EF8E}']
    procedure GetControlRequirements(ARequirements: TAbstractControlRequirements);
  end;

  TAdapterControlGroup = class(TWebControlGroup, IWebDataFields,
      INotifyAdapterChange, IGetAdapterVariableName, IGetAdapterOfDisplay, INotifyList,
      IGetVariablesContainerOfDisplay, IGetDesigntimeWarnings, IGetAdapterModeOfDisplay,
      IGetControlRequirements)
  private
    FAdapter: TComponent;
    FNotifyList: TNotifyList;
    FAdapterMode: string;
    FAddDefaultFields: Boolean;
    procedure SetAddDefaultFields(const Value: Boolean);
  protected
    { IGetControlRequirements }
    procedure GetControlRequirements(ARequirements: TAbstractControlRequirements);
    procedure ImplGetControlRequirements(ARequirements: TAbstractControlRequirements); virtual;
    { IGetAdapterModeOfDisplay }
    function GetAdapterModeOfDisplay: string;
    function GetAdapterModeOfAdapter: string;
    { IGetDesigntimeWarnings }
    procedure GetDesigntimeWarnings(AWarnings: TAbstractDesigntimeWarnings);
    { INotifyList }
    procedure AddNotify(ANotify: TObject);
    procedure RemoveNotify(ANotify: TObject);
    { INotifyAdapterChange }
    procedure NotifyAdapterChange(Sender: TComponent);
    { IGetAdapterOfDisplay }
    function GetAdapter: TComponent;
    { IGetVariablesContainerOfDisplay }
    function IGetVariablesContainerOfDisplay.GetVariablesContainer = GetAdapter;
    { IWebDataFields }
    function GetVisibleFields: TWebComponentList;
    procedure GetFieldsList(List: TStrings);
    function FindField(const AName: string): TComponent;
    function IsFieldInUse(const AName: string): Boolean;
    { IGetAdapterVariableName }
    function GetAdapterVariableName: string;

    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure SetAdapter(const Value: TComponent);
    procedure CreateDefaultFields;
    procedure AdapterChange; virtual;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property AddDefaultFields: Boolean read FAddDefaultFields write SetAddDefaultFields default True;
    property VisibleFields: TWebComponentList read GetVisibleFields;
    property Adapter: TComponent read GetAdapter write SetAdapter;
    property AdapterMode: string read FAdapterMode write FAdapterMode;
  end;

  TAbstractFormRequirements = class
  public
    function IsFunctionDefined(const AName: string): Boolean; virtual; abstract;
    procedure DefineFunction(const AName, ABody: string); virtual; abstract;
    function IsVariableDefined(const AName: string): Boolean; virtual; abstract;
    procedure DefineVariable(const AName, AValue: string); virtual; abstract;
  end;

  IGetFormRequirements = interface
  ['{C990BD6A-9250-4C70-B873-F54B3A71DADD}']
    procedure GetFormRequirements(ARequirements: TAbstractFormRequirements);
  end;

  TDisplayFieldHideOption = (hoHideOnNoInputAccess, hoHideOnNoDisplayAccess,
     hoHideOnFieldNotVisible, hoHideAlways);
  TDisplayFieldHideOptions = set of TDisplayFieldHideOption;

  TAdapterDataDisplay = class(TWebDataDisplay, IWebGetFieldName, IWebSetFieldName,
    IGetAdapterVariableName, IRestoreDefaults, IGetControlRequirements,
    IGetVariablesContainerOfDisplay, IGetDesigntimeWarnings, IFormatColumn)
  private
    FFieldName: string;
    FHideOptions: TDisplayFieldHideOptions;
    FAlign: THTMLAlign;
    FVAlign: THTMLVAlign;
  protected
    function FormatCaption: string; override;
    function FindAssociatedField: TComponent;
    function GetCaption: string; override;
    procedure SetCaption(Value: string); override;
    function FieldConditions(Options: TWebContentOptions): string; virtual;
    function GetAdapterModeOfAdapter: string;
    { IFormatColumn }
    function FormatColumnHeading(Options: TWebContentOptions): string;
    function FormatColumnData(const Content: string; Options: TWebContentOptions): string;
    function ImplFormatColumnHeading(Options: TWebContentOptions): string; virtual;
    function ImplFormatColumnData(const Content: string; Options: TWebContentOptions): string; virtual;
    { IGetDesigntimeWarnings }
    procedure GetDesigntimeWarnings(AWarnings: TAbstractDesigntimeWarnings);
    { IGetVariablesContainerOfDisplay }
    function GetVariablesContainer: TComponent;
    { IWebContent }
    function ImplContent(Options: TWebContentOptions;
      ParentLayout: TLayout): string; override;
    { IGetControlRequirements }
    procedure GetControlRequirements(ARequirements: TAbstractControlRequirements);
    procedure ImplGetControlRequirements(ARequirements: TAbstractControlRequirements); virtual;
    { IRestoreDefaults }
    procedure RestoreDefaults;
    procedure ImplRestoreDefaults; virtual;
    { IWebGetFieldName, IWebSetFieldName }
    function GetFieldName: string;
    procedure SetFieldName(const Value: string);
    { IGetAdapterVariableName }
    function GetAdapterVariableName: string;

  public
    constructor Create(AOwner: TComponent); override;
    property FieldName: string read GetFieldName write SetFieldName;
    property HideOptions: TDisplayFieldHideOptions read FHideOptions write FHideOptions
      default [hoHideOnFieldNotVisible];
    property Align: THTMLAlign read FAlign write FAlign default haDefault;
    property VAlign: THTMLVAlign read FVAlign write FVAlign default haVDefault;
  end;

  TAdapterDataDisplayClass = class of TAdapterDataDisplay;

  TAdapterActionsListHelper = class(TObject)
  private
    FComponent: TComponent;
    FHelper: TWebContainerComponentHelper;
    FAddDefaultActions: Boolean;
    procedure CreateDefaultActions;
    procedure SetAddDefaultActions(const Value: Boolean);
  protected
    { IWebActionsList }
    function GetVisibleActions: TWebComponentList;
    procedure GetActionsList(List: TStrings);
    function FindAction(const AName: string): TComponent;
    function IsActionInUse(const AName: string): Boolean;
    { IAddFieldsEditor }
    function GetNewFieldPrefix: string;
    function GetAddFieldsItem: string;
    function GetAddAllFieldsItem: string;
    function GetAddFieldsDlgCaption: string;
  public
    constructor Create(AComponent: TComponent;
      AHelper: TWebContainerComponentHelper);
    property AddDefaultActions: Boolean read FAddDefaultActions write SetAddDefaultActions;
  end;

  TColumnHTMLElementType = (coltDefault, coltText, coltImage, coltList);

  TCustomAdapterDisplayColumn = class(TAdapterDataDisplay)
  private
    FDisplayType: TColumnHTMLElementType;
    FImageWidth: Integer;
    FImageHeight: Integer;
  protected
    { IGetControlRequirements }
    procedure ImplGetControlRequirements(ARequirements: TAbstractControlRequirements); override;
    { IFormatColumn }
    function ImplFormatColumnHeading(Options: TWebContentOptions): string; override;
    { IWebComponentEditor }
    function CanAddClass(AParent: TComponent; AClass: TClass): Boolean;
    function ImplCanAddClass(AParent: TComponent; AClass: TClass): Boolean; virtual;
    { IGetWebComponentsList }

    function FormatTextDisplay(const VarName, HTMLName: string): string;
    function FormatListDisplay(const VarName, HTMLName: string): string;
    function FormatImage(const VarName, HTMLName: string;
      Options: TWebContentOptions): string;
    function ControlContent(Options: TWebContentOptions): string; override;
    procedure ImplRestoreDefaults; override;
  public
    constructor Create(AOwner: TComponent); override;
    class function IsColumn: Boolean; override;
    property DisplayType: TColumnHTMLElementType read FDisplayType write FDisplayType default coltDefault;
    property ImageWidth: Integer read FImageWidth write FImageWidth default -1;
    property ImageHeight: Integer read FImageHeight write FImageHeight default -1;
  end;

  TCustomAdapterCommandColumn = class(TWebControlGroup, IWebActionsList, IAddFieldsEditor,
    IFormatColumn, IGetAdapterDisplayCharacteristics, INotifyAdapterChange)
  private
    FStyle: string;
    FCustom: string;
    FStyleRule: string;
    FCaption: string;
    FCaptionAttributes: TCaptionAttributes;
    FDisplayColumns: Integer;
    FAdapterActionsListHelper: TAdapterActionsListHelper;
    FLayoutAttributes: TLayoutAttributes;
    FAlign: THTMLAlign;
    FVAlign: THTMLVAlign;
    function GetCaption: string;
    procedure SetCaptionAttributes(const Value: TCaptionAttributes);
    procedure SetCaption(const Value: string);
    function GetVisibleActions: TWebComponentList;
    function GetAddDefaultCommands: Boolean;
    procedure SetAddDefaultCommands(const Value: Boolean);
    function IsCaptionStored: Boolean;
  protected
    function GetLayoutAttributes: TLayoutAttributes; override;
    { INotifyAdapterChange }
    procedure NotifyAdapterChange(Sender: TComponent);
    { IGetAdapterDisplayCharacteristics }
    function GetAdapterDisplayCharacteristics: TAdapterDisplayCharacteristics;
    { IWebContent }
    function ImplContent(Options: TWebContentOptions; ParentLayout: TLayout): string; override;
    { IWebComponentEditor }
    function ImplCanAddClass(AParent: TComponent; AClass: TClass): Boolean; override;
    { IFormatColumn }
    function FormatColumnHeading(Options: TWebContentOptions): string;
    function FormatColumnData(const Content: string; Options: TWebContentOptions): string;

    property AdapterActionsListHelper: TAdapterActionsListHelper read FAdapterActionsListHelper
      implements IWebActionsList, IAddFieldsEditor;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property VisibleCommands: TWebComponentList read GetVisibleActions;
    property DisplayColumns: Integer read FDisplayColumns write FDisplayColumns default -1;
    property Style: string read FStyle write FStyle;
    property Custom: string read FCustom write FCustom;
    property StyleRule: string read FStyleRule write FStyleRule;
    property CaptionAttributes: TCaptionAttributes
      read FCaptionAttributes write SetCaptionAttributes;
    property Caption: string read GetCaption write SetCaption
      stored IsCaptionStored;
    property AddDefaultCommands: Boolean read GetAddDefaultCommands write SetAddDefaultCommands default True;
    property Align: THTMLAlign read FAlign write FAlign default haDefault;
    property VAlign: THTMLVAlign read FVAlign write FVAlign default haVDefault;
  end;

  TAdapterCommandColumn = class(TCustomAdapterCommandColumn)
  published
    property Style;
    property Custom;
    property StyleRule;
    property CaptionAttributes;
    property Caption;
    property DisplayColumns;
    property AddDefaultCommands;
    property Align;
    property VAlign;
  end;

  TGeneratedFunctions = class
  private
    FScript: TStrings;
    FNames: TStrings;
    function GetScript(I: Integer): string;
    function GetItemCount: Integer;
    function GetName(I: Integer): string;
  public
    constructor Create;
    destructor Destroy; override;
    procedure Add(const AName, AScript: string);
    function Exists(const AName: string): Boolean;
    property Script[I: Integer]: string read GetScript;
    property ItemCount: Integer read GetItemCount;
    property Names[I: Integer]: string read GetName;
  end;

  TControlRequirements = class(TAbstractControlRequirements)
  private
    FGeneratedFunctions: TGeneratedFunctions;
    FNeedMultipartForm: Boolean;
    FVariables: TStrings;
  public
    procedure RequiresMultipartForm; override;
    function IsFunctionDefined(const AName: string): Boolean; override;
    procedure DefineFunction(const AName, ABody: string); override;
    procedure DefineVariable(const AName, AValue: string; AAdapter: Boolean); override;
    function IsVariableDefined(const AName: string): Boolean; override;
    constructor Create;
    destructor Destroy; override;
    property NeedMultipartForm: Boolean read FNeedMultipartForm;
  end;

  TAdapterFormLayout = class;
  IGetAdapterFormLayout = interface
  ['{C51059F2-AA91-11D4-A502-00C04F6BB853}']
    function GetAdapterFormLayout: TAdapterFormLayout;
  end;

  TCustomAdapterForm = class(TWebControlGroup,
    IHTMLForm, IGetFormRequirements, IGetAdapterFormLayout)
  private
    FStyle: string;
    FCustom: string;
    FStyleRule: string;
    FLayoutAttributes: TLayoutAttributes;
    FControlRequirements: TControlRequirements;
    FFormLayout: TAdapterFormLayout;
    FFormMethod: TFormMethod;
    function FormatForm(ParentLayout: TLayout;
      Options: TWebContentOptions): string;
    function GetHTMLFormTag(Options: TWebContentOptions): string;
    function GetControlRequirements: TControlRequirements;
  protected
    function GetLayoutAttributes: TLayoutAttributes; override;
    { IGetAdapterFormLayout }
    function GetAdapterFormLayout: TAdapterFormLayout;
    { IGetFormRequirements }
    procedure GetFormRequirements(ARequirements: TAbstractFormRequirements);
    { IHTMLForm }
    function GetHTMLFormName: string;
    function GetHTMLFormVarName: string;
    { IWebComponentEditor }
    function ImplCanAddClass(AParent: TComponent; AClass: TClass): Boolean; override;
    { IWebContent }
    function ImplContent(Options: TWebContentOptions; ParentLayout: TLayout): string; override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property Style: string read FStyle write FStyle;
    property Custom: string read FCustom write FCustom;
    property StyleRule: string read FStyleRule write FStyleRule;
    property FormMethod: TFormMethod read FFormMethod write FFormMethod default fmPost;
  end;

  TAdapterForm = class(TCustomAdapterForm)
  published
    property Style;
    property Custom;
    property StyleRule;
    property FormMethod;
  end;

  IAdapterDisplay = interface
  ['{73506462-4D5E-11D4-A48B-00C04F6BB853}']
  end;

  TCustomAdapterGrid = class(TAdapterControlGroup, IAdapterDisplay,
    IGetAdapterDisplayCharacteristics, IAddFieldsEditor, IGetAdapterFormLayout)
  private
    FTableLayout: TAdapterFormLayout;
    FTableAttributes: TGridAttributes;
    FHeadingAttributes: TGridRowAttributes;
    FRowAttributes: TGridRowAttributes;
    function FormatTable(Layout: TLayoutWebContent;
      Options: TWebContentOptions): string;
    procedure SetHeadingAttributes(const Value: TGridRowAttributes);
    procedure SetRowAttributes(const Value: TGridRowAttributes);
    procedure SetTableAttributes(const Value: TGridAttributes);
  protected
    { IGetAdapterFormLayout }
    function GetAdapterFormLayout: TAdapterFormLayout;
    { IAddFieldsEditor }
    function GetNewFieldPrefix: string;
    function GetAddFieldsItem: string;
    function GetAddAllFieldsItem: string;
    function GetAddFieldsDlgCaption: string;
    { IGetAdapterDisplayCharacteristics }
    function GetAdapterDisplayCharacteristics: TAdapterDisplayCharacteristics;
    { IWebComponentEditor }
    function ImplCanAddClass(AParent: TComponent; AClass: TClass): Boolean; override;
    { IWebContent }
    function ImplContent(Options: TWebContentOptions; ParentLayout: TLayout): string; override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property TableAttributes: TGridAttributes read FTableAttributes
      write SetTableAttributes;
    property HeadingAttributes: TGridRowAttributes read FHeadingAttributes
      write SetHeadingAttributes;
    property RowAttributes: TGridRowAttributes read FRowAttributes
      write SetRowAttributes;
  end;

  TAdapterGrid = class(TCustomAdapterGrid)
  published
    property TableAttributes;
    property HeadingAttributes;
    property RowAttributes;
    property Adapter;
    property AdapterMode;
    property AddDefaultFields;
  end;

  TCustomAdapterFieldGroup = class(TAdapterControlGroup, IAdapterDisplay,
    IGetAdapterDisplayCharacteristics, IAddFieldsEditor, IGetAdapterFormLayout)
  private
    FStyle: string;
    FCustom: string;
    FStyleRule: string;
    FLayoutAttributes: TLayoutAttributes;
    FFormLayout: TAdapterFormLayout;
    function FormatFields(ParentLayout: TLayout;
      Options: TWebContentOptions): string;
  protected
    { IAddFieldsEditor }
    function GetNewFieldPrefix: string;
    function GetAddFieldsItem: string;
    function GetAddAllFieldsItem: string;
    function GetAddFieldsDlgCaption: string;
    { IGetAdapterFormLayout }
    function GetAdapterFormLayout: TAdapterFormLayout;

    function GetLayoutAttributes: TLayoutAttributes; override;
    { IGetAdapterDisplayCharacteristics }
    function GetAdapterDisplayCharacteristics: TAdapterDisplayCharacteristics;
    { IWebComponentEditor }
    function ImplCanAddClass(AParent: TComponent; AClass: TClass): Boolean; override;
    { IWebContent }
    function ImplContent(Options: TWebContentOptions; ParentLayout: TLayout): string; override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property Style: string read FStyle write FStyle;
    property Custom: string read FCustom write FCustom;
    property StyleRule: string read FStyleRule write FStyleRule;
  end;

  TAdapterFieldGroup = class(TCustomAdapterFieldGroup)
  published
    property Style;
    property Custom;
    property StyleRule;
    property Adapter;
    property AdapterMode;
    property AddDefaultFields;
  end;

  TInputFieldHTMLElementType = (iftDefault, iftTextInput,
    iftPasswordInput, iftSelect, iftSelectMultiple,
    iftRadio, iftCheckBox, iftTextArea, iftFile);
  TDisplayFieldHTMLElementType = (dftDefault, dftText,
   dftImage, dftList);
  TDisplayFieldViewMode = (vmDefault, vmInput, vmDisplay, vmToggleOnAccess);
  TCustomAdapterDisplayField = class(TAdapterDataDisplay, IGetControlRequirements)
  private
    FDisplayWidth: Integer;
    FDisplayType: TDisplayFieldHTMLElementType;
    FInputType: TInputFieldHTMLElementType;
    FSelectRows: Integer;
    FImageWidth: Integer;
    FImageHeight: Integer;
    FMaxLength: Integer;
    FDisplayRows: Integer;
    FWrap: TTextAreaWrap;
    FViewMode: TDisplayFieldViewMode;
    FDisplayColumns: Integer;
    function FormatTextInput(const VarName, HTMLName: string): string;
    function FormatPasswordInput(const VarName, HTMLName: string): string;
    function FormatSelect(const VarName, HTMLName: string; Multiple: Boolean): string;
    function CalcInputElementType(var AType: TInputFieldHTMLElementType): Boolean;
    function CalcDisplayElementType(var AType: TDisplayFieldHTMLElementType): Boolean;
    function CalcDisplayFieldViewMode(var AMode: TDisplayFieldViewMode): Boolean;
    function FormatTextDisplay(const VarName, HTMLName: string): string;
    function FormatListDisplay(const VarName, HTMLName: string): string;
    function FormatRadioGroup(const VarName, HTMLName: string): string;
    function FormatCheckBoxGroup(const VarName, HTMLName: string): string;
    function FormatInputGroup(const FunctionName, VarName, HTMLName: string; DisplayColumns: Integer): string;
    function FormatTextArea(const VarName, HTMLName: string): string;
    function FormatImage(const VarName, HTMLName: string; Options: TWebContentOptions): string;
    function FormatFileInput(const VarName, HTMLName: string): string;
  protected
    function GetLayoutAttributes: TLayoutAttributes; override;
    procedure AddAttributes(var Attrs: string);
    function ControlContent(Options: TWebContentOptions): string; override;
    { IGetcontrolRequirements }
    procedure ImplGetControlRequirements(
      ARequirements: TAbstractControlRequirements); override;
    { IRestoreDefaults }
    procedure ImplRestoreDefaults; override;
    { IWebContent }
    function ImplContent(Options: TWebContentOptions;
      ParentLayout: TLayout): string; override;
  public
    constructor Create(AOwner: TComponent); override;
    property DisplayWidth: Integer read FDisplayWidth write FDisplayWidth default -1;
    property ViewMode: TDisplayFieldViewMode read FViewMode write FViewMode default vmDefault;
    property DisplayType: TDisplayFieldHTMLElementType read FDisplayType write FDisplayType default dftDefault;
    property InputType: TInputFieldHTMLElementType read FInputType write FInputType default iftDefault;
    property ImageWidth: Integer read FImageWidth write FImageWidth default -1;
    property ImageHeight: Integer read FImageHeight write FImageHeight default -1;
    property SelectRows: Integer read FSelectRows write FSelectRows default 0;
    property MaxLength: Integer read FMaxLength write FMaxLength default -1;
    property TextAreaWrap: TTextAreaWrap read FWrap write FWrap default wrOff;
    property DisplayRows: Integer read FDisplayRows write FDisplayRows default -1;
    property DisplayColumns: Integer read FDisplayColumns write FDisplayColumns default 1;
  end;

  TAdapterDisplayColumn = class(TCustomAdapterDisplayColumn)
  published
    property Caption;
    property CaptionAttributes;
    property FieldName;
    property DisplayType;
    property ImageWidth;
    property ImageHeight;
    property HideOptions;
    property Style;
    property Custom;
    property StyleRule;
    property Align;
    property VAlign;
  end;

  TAdapterDisplayField = class(TCustomAdapterDisplayField)
  published
    property Style;
    property Custom;
    property StyleRule;
    property Caption;
    property DisplayColumns;
    property CaptionAttributes;
    property DisplayWidth;
    property FieldName;
    property DisplayType;
    property CaptionPosition;
    property Align;
    property VAlign;
    property ImageWidth;
    property ImageHeight;
    property SelectRows;
    property MaxLength;
    property TextAreaWrap;
    property DisplayRows;
    property ViewMode;
    property HideOptions;
    property InputType;
  end;

  TCustomAdapterEditColumn = class(TCustomAdapterDisplayField)
  protected
    { IWebContent }
    function ImplContent(Options: TWebContentOptions;
      ParentLayout: TLayout): string; override;
  end;

  TAdapterEditColumn = class(TCustomAdapterEditColumn)
  published
    property Style;
    property Custom;
    property StyleRule;
    property Caption;
    property DisplayColumns;
    property CaptionAttributes;
    property DisplayWidth;
    property FieldName;
    property DisplayType;
    property CaptionPosition;
    property Align;
    property VAlign;
    property ImageWidth;
    property ImageHeight;
    property SelectRows;
    property MaxLength;
    property TextAreaWrap;
    property DisplayRows;
    property ViewMode;
    property HideOptions;
    property InputType;
  end;

  TAdapterDisplayReferenceGroup = class(TWebDisplayReferenceGroup, IGetDesigntimeWarnings,
    INotifyAdapterChange, IGetAdapterDisplayCharacteristics)
  protected
    procedure OnDisplayComponentChange(ASender: TObject);
    procedure DisplayComponentChange; virtual;
    procedure AdapterChange; virtual;
    { IGetDesigntimeWarnings }
    procedure GetDesigntimeWarnings(AWarnings: TAbstractDesigntimeWarnings);
    { IGetAdapterDisplayCharacteristics }
    function GetAdapterDisplayCharacteristics: TAdapterDisplayCharacteristics;
    { INotifyAdapterChange }
    procedure NotifyAdapterChange(Sender: TComponent);
    procedure SetWebDisplayComponent(const AComponent: TComponent); override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property DisplayComponent: TComponent read GetWebDisplayComponent write SetWebDisplayComponent;
  end;

  TCustomAdapterCommandGroup = class(TAdapterDisplayReferenceGroup, IWebActionsList, IGetAdapterOfDisplay,
    IGetVariablesContainerOfDisplay, IAddFieldsEditor, IGetAdapterModeOfDisplay, IGetAdapterFormLayout)
  private
    FStyle: string;
    FCustom: string;
    FStyleRule: string;
    FFormLayout: TAdapterFormLayout;
    FAdapterActionsListHelper: TAdapterActionsListHelper;
    function GetVisibleCommands: TWebComponentList;
    function GetAddDefaultCommands: Boolean;
    procedure SetAddDefaultCommands(const Value: Boolean);
  protected
    { IGetAdapterFormLayout }
    function GetAdapterFormLayout: TAdapterFormLayout;
    { IGetAdapterModeOfDisplay }
    function GetAdapterModeOfDisplay: string;
    function GetAdapterModeOfAdapter: string;
    { IGetAdapterOfDisplay }
    function GetAdapter: TComponent;
    { IGetVariablesContainerOfDisplay }
    function IGetVariablesContainerOfDisplay.GetVariablesContainer = GetAdapter;
    { IWebComponentEditor }
    function ImplCanAddClass(AParent: TComponent; AClass: TClass): Boolean; override;
    { IWebContent implementation }
    function ImplContent(Options: TWebContentOptions; ParentLayout: TLayout): string; override;
    property Adapter: TComponent read GetAdapter;
    property AdapterActionsListHelper: TAdapterActionsListHelper read FAdapterActionsListHelper
      implements IWebActionsList, IAddFieldsEditor;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property Custom: string read FCustom write FCustom;
    property Style: string read FStyle write FStyle;
    property StyleRule: string read FStyleRule write FStyleRule;
    property VisibleCommands: TWebComponentList read GetVisibleCommands;
    property AddDefaultCommands: Boolean read GetAddDefaultCommands write SetAddDefaultCommands default True;
  end;

  TAdapterCommandGroup = class(TCustomAdapterCommandGroup)
  published
    property DisplayComponent;
    property Custom;
    property Style;
    property StyleRule;
    property AddDefaultCommands;
  end;

  TActionButtonHideOption = (bhoHideOnNoExecuteAccess,
     bhoHideOnActionNotVisible, bhoHideOnDisabledAction, bhoHideAlways);
  TActionButtonHideOptions = set of TActionButtonHideOption;
  TCommandHTMLElementType = (ctDefault, ctButton, ctImage, ctAnchor, ctEventImages);
  TCustomAdapterActionButton = class(TWebButton, IWebGetActionName, IWebSetActionName,
    IRestoreDefaults, IGetControlRequirements, IGetAdapterVariableName, IGetDesignTimeWarnings)
  private
    FActionName: string;
    FDisplayType: TCommandHTMLElementType;
    FPageName: string;
    FErrorPageName: string;
    FImageWidth: Integer;
    FImageHeight: Integer;
    FHideOptions: TActionButtonHideOptions;
    FDisplayColumns: Integer;
    FImageProducer: IActionImageProducer;
    FLayoutAttributes: TLayoutAttributes;
    FAlign: THTMLAlign;
    FVAlign: THTMLVAlign;
    procedure SetImageProducer(const Value: IActionImageProducer);
    function GetImageProducerComponent: TComponent;
    function GetImageProducerVariableName: string;
  protected
    function GetLayoutAttributes: TLayoutAttributes; override;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    function GetAdapterModeOfAdapter: string;
    function GetHTMLFormVarName: string;
    { IGetDesigntimeWarnings }
    procedure GetDesigntimeWarnings(AWarnings: TAbstractDesigntimeWarnings);
    { IGetControlRequirements }
    procedure GetControlRequirements(ARequirements: TAbstractControlRequirements);
    procedure ImplGetControlRequirements(ARequirements: TAbstractControlRequirements); virtual;
    { IRestoreDefaults }
    procedure RestoreDefaults;
    procedure ImplRestoreDefaults; virtual;
    { IWebContent implementation }
    function ImplContent(Options: TWebContentOptions; ParentLayout: TLayout): string; override;
    { IWebGetActionName }
    function GetActionName: string;
    { IWebSetActionName }
    procedure SetActionName(const AValue: string);
    procedure SetCaption(const Value: string); override;
    function GetCaption: string; override;
    { IGetAdapterVariableName }
    function GetAdapterVariableName: string;

    function FindAssociatedAction: TComponent;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property ActionName: string read GetActionName write SetActionName;
    property PageName: string read FPageName write FPageName;
    property ErrorPageName: string read FErrorPageName write FErrorPageName;
    property DisplayType: TCommandHTMLElementType read FDisplayType write FDisplayType default ctDefault;
    property ImageWidth: Integer read FImageWidth write FImageWidth default -1;
    property ImageHeight: Integer read FImageHeight write FImageHeight default -1;
    property HideOptions: TActionButtonHideOptions read FHideOptions write FHideOptions
      default [bhoHideOnActionNotVisible];
    property DisplayColumns: Integer read FDisplayColumns write FDisplayColumns default -1;
    property ImageProducer: IActionImageProducer read FImageProducer write SetImageProducer;
    property Align: THTMLAlign read FAlign write FAlign default haDefault;
    property VAlign: THTMLVAlign read FVAlign write FVAlign default haVDefault;
  end;

  TAdapterActionButton = class(TCustomAdapterActionButton)
  published
    property ActionName;
    property Style;
    property Custom;
    property Caption;
    property StyleRule;
    property PageName;
    property ErrorPageName;
    property HideOptions;
    property DisplayType;
    property ImageWidth;
    property ImageHeight;
    property DisplayColumns;
    property ImageProducer;
    property Align;
    property VAlign;
  end;

  TLayoutState = (lsUnknown, lsFields, lsButtons);
  TAdapterFormLayout = class(TLayoutWebContent, IGetAdapterFormLayout)
  private
    FParentIndent: string;
    FFieldLevel: Integer;
    FTableLevel: Integer;
    FLayoutState: TLayoutState;
    FInTable: Boolean;
    FInRow: Boolean;
    FTableHeader: string;
    FColumnCount: Integer;
    FColumnIndex: Integer;
    FBreakButtons: Boolean;
    FButtonIndex: Integer;
    FTableIndent: string;
    FFieldIndent: string;
  protected
    { IGetAdapterFormLayout }
    function GetAdapterFormLayout: TAdapterFormLayout;
    function GetTableIndent: string;
    function GetChildTableIndent: string;
    function GetFieldIndent: string;
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
    function EndField: string;
  public
    constructor Create(AParentLayout: TLayout);
    function EndLayout: string;
    property ColumnCount: Integer read FColumnCount write FColumnCount;
    property BreakButtons: Boolean read FBreakButtons write FBreakButtons;
    property TableHeader: string read FTableHeader write FTableHeader;
    property FieldIndent: string read GetFieldIndent;
    property TableIndent: string read GetTableIndent;
    property ChildTableIndent: string read GetChildTableIndent;
  end;

  TCustomAdapterErrorList = class(TWebContainedComponent, IWebContent, IGetDesigntimeWarnings)
  private
    FAdapter: TComponent;
    FLayoutAttributes: TLayoutAttributes;
    function GetAdapter: TComponent;
    procedure SetAdapter(const Value: TComponent);
    function GetLayoutAttributes: TLayoutAttributes;
  protected
    { IGetDesigntimeWarnings }
    procedure GetDesigntimeWarnings(AWarnings: TAbstractDesigntimeWarnings);
    { IWebContent }
    function Content(Options: TWebContentOptions; Layout: TLayout): string;
    function ImplContent(Options: TWebContentOptions; Layout: TLayout): string; virtual;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property Adapter: TComponent read GetAdapter write SetAdapter;
  end;

  TAdapterErrorList = class(TCustomAdapterErrorList)
  published
    property Adapter;
  end;

  TDesigntimeWarnings = class(TAbstractDesigntimeWarnings)
  private
    FStrings: TStrings;
    FObjects: TObjectList;
  public
    procedure AddString(AWarning: string); override;
    procedure AddObject(AObject: TObject);  override;
    property Strings: TStrings read FStrings;
    constructor Create;
    destructor Destroy; override;
  end;

function FindVariablesContainer(AComponent: TComponent): TComponent;
function FindVariablesContainerInParent(AComponent: TComponent): TComponent;
function CalcDisplayFieldHTMLElementType(AField: TComponent; const AAdapterMode: string; ADisplayType: TDisplayFieldHTMLElementType; var AType: TDisplayFieldHTMLElementType): Boolean;
function CalcDisplayFieldViewMode(AField: TComponent; const AAdapterMode: string; AViewMode: TDisplayFieldViewMode; var AMode: TDisplayFieldViewMode): Boolean;
function GetAdapterModeOfAdapterInParent(AComponent: TComponent): string;
function MakeAdapterVariableName(AComponent: TComponent): string;
function MakeAdapterHTMLName(AVarName: string): string;

const
  sMultipartForm = 'multipart/form-data'; // Do not localize
  sFormPost = 'post'; // Do not localize
  sFormGet =  'get';  // Do not localize
  // Params 0 - Variable name
  sDisplayText =
  '<%%= %0:s.DisplayText %%>';         // Do not localize

  sFieldText =
  '<%%= %0:s.EditText %%>';            // Do not localize

implementation

uses SysUtils, Variants, WebCntxt, WebDisp, Math, SiteConst, AdaptReq;

const
  sAdapterCommandPrefix = 'Cmd'; // Do not location

const
  sIfCan =
'<%%%% if (%0:s)'#13#10 +  // Do not localize
'   { %%%%>'#13#10 +      // Do not localize
'%%s' +                            // Do not localize
'<%%%% } %%%%>'#13#10;

  sCanViewCondition = '%0:s.CanView';       // Do not localize
  sCanModifyCondition = '%0:s.CanModify';   // Do not localize
  sIsVisibleCondition = '%0:s.Visible';     // Do not localize
  sIfEnabledCondition = '%0:s.Enabled';     // Do not localize
  sCanExecuteCondition = '%0:s.CanExecute'; // Do not localize

  sAccessBased =
'<%% if (%0:s.CanModify)'#13#10 +
'   { %%>'#13#10 +           // Do not localize
'%3:s%1:s'#13#10 +                                      // Do not localize
'<%% } %%>'#13#10 +                                     // Do not localize
'<%% else if (%0:s.CanView)'#13#10 +                    // Do not localize
'   { %%>'#13#10 +              // Do not localize
'%3:s%2:s'#13#10 +                                      // Do not localize
'<%% } %%>'#13#10;

  sAdapterColumnPrefix = 'Col'; // Do not localize

function FindAdapter(AComponent: TComponent): TComponent;
var
  Intf: IGetAdapterOfDisplay;
begin
  while Assigned(AComponent) do
  begin
    if Supports(IInterface(AComponent), IGetAdapterOfDisplay, Intf) then
    begin
      Result := Intf.GetAdapter;
      Exit;
    end;
    AComponent := AComponent.GetParentComponent;
  end;
  Result := nil;
end;

function FieldIndent(AComponent: TComponent): string;
var
  Intf: IGetAdapterFormLayout;
  Temp: TAdapterFormLayout;
  Component: TComponent;
begin
  Component := AComponent;
  while Assigned(Component) do
  begin
    if Supports(IInterface(Component), IGetAdapterFormLayout, Intf) then
    begin
      Temp := Intf.GetAdapterFormLayout;
      if Temp <> nil then
        Result := Temp.FieldIndent
      else
        Result := '';
      Exit;
    end;
    Component := Component.GetParentComponent;
  end;
  Result := '';
end;


function ChildTableIndent(AComponent: TComponent): string;
var
  Intf: IGetAdapterFormLayout;
  Temp: TAdapterFormLayout;
  Component: TComponent;
begin
  Component := AComponent;
  while Assigned(Component) do
  begin
    if Supports(IInterface(Component), IGetAdapterFormLayout, Intf) then
    begin
      Temp := Intf.GetAdapterFormLayout;
      if Temp <> nil then
        Result := Temp.ChildTableIndent
      else
        Result := '';
      Exit;
    end;
    Component := Component.GetParentComponent;
  end;
  Result := '';
end;

function FindVariablesContainer(AComponent: TComponent): TComponent;
var
  Intf: IGetVariablesContainerOfDisplay;
begin
  while Assigned(AComponent) do
  begin
    if Supports(IInterface(AComponent), IGetVariablesContainerOfDisplay, Intf) then
    begin
      Result := Intf.GetVariablesContainer;
      Exit;
    end;
    AComponent := AComponent.GetParentComponent;
  end;
  Result := nil;
end;

function FindVariablesContainerInParent(AComponent: TComponent): TComponent;
begin
  AComponent := AComponent.GetParentComponent;
  Result := FindVariablesContainer(AComponent);
end;

function MakeAdapterVariableName(AComponent: TComponent): string;
var
  GetAdapterVariableName: IGetAdapterVariableName;
begin
  while Assigned(AComponent) do
  begin
    if Supports(IInterface(AComponent), IGetAdapterVariableName, GetAdapterVariableName) then
    begin
      Result := GetAdapterVariableName.GetAdapterVariableName;
      break;
    end;
    AComponent := AComponent.GetParentComponent;
  end;
end;

const
  sVarPrefix = 'v';

function MakeAdapterItemVariableName(AComponent: TComponent): string;
var
  P: PChar;
begin
  if AComponent <> nil then
  begin
    Result := FullyQualifiedName(AComponent, qaNoModuleName);
    P := PChar(Result);
    repeat
      P := StrScan(P, '.');
      if P <> nil then
        P^ := '_';
    until P = nil;
    Result := sVarPrefix + Result
  end
  else
    Result := '';
end;

function MakeAdapterItemVariableValue(AComponent: TComponent): string;
begin
  if AComponent <> nil then
  begin
    Result := FullyQualifiedName(AComponent, qaNoModuleName);
    Result := sVarPrefix + Result
  end
  else
    Result := '';
end;

function MakeAdapterHTMLName(AVarName: string): string;
begin
  if AVarName <> '' then
    Result := Format('%s.InputName', [AVarName])  { do not localize }
  else
    Result := '';
end;

function GetAdapterModeOfAdapterInParent(AComponent: TComponent): string;
var
  Intf: IGetAdapterModeOfDisplay;
begin
  AComponent := AComponent.GetParentComponent;
  while Assigned(AComponent) do
  begin
    if Supports(IInterface(AComponent), IGetAdapterModeOfDisplay, Intf) then
    begin
      Result := Intf.GetAdapterModeOfAdapter;
      Exit;
    end;
    AComponent := AComponent.GetParentComponent;
  end;
  Result := '';
end;

function GetAdapterModeOfDisplayInParent(AComponent: TComponent): string;
var
  Intf: IGetAdapterModeOfDisplay;
begin
  AComponent := AComponent.GetParentComponent;
  while Assigned(AComponent) do
  begin
    if Supports(IInterface(AComponent), IGetAdapterModeOfDisplay, Intf) then
    begin
      Result := Intf.GetAdapterModeOfDisplay;
      Exit;
    end;
    AComponent := AComponent.GetParentComponent;
  end;
  Result := '';
end;

{ TCustomAdapterGrid }

function TCustomAdapterGrid.ImplCanAddClass(AParent: TComponent;
  AClass: TClass): Boolean;
begin
  Result :=
    AClass.InheritsFrom(TCustomAdapterEditColumn) or
    AClass.InheritsFrom(TCustomAdapterDisplayColumn) or
    AClass.InheritsFrom(TCustomAdapterCommandColumn) or
    CanAddClassHelper(Self, AParent, AClass);
end;

type
  TGridLayout = class(TAdapterFormLayout)
  protected
    function ImplLayoutButton(const HTMLButton: string; Attributes: TLayoutAttributes): string; override;
    function ImplLayoutField(const HTMLField: string; Attributes: TLayoutAttributes): string; override;
    function ImplLayoutLabelAndField(const HTMLLabel, HTMLField: string; Attributes: TLayoutAttributes): string; override;
    function ImplLayoutTable(const HTMLTable: string; Attributes: TLayoutAttributes): string; override;
  end;

function TGridLayout.ImplLayoutTable(const HTMLTable: string;
  Attributes: TLayoutAttributes): string;
begin
  // Nested table
  Result := ImplLayoutField(HTMLTable, Attributes);
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

const
  sSetAdapterMode = '<%%'#13#10 +
                     '{'#13#10 +                            // Do not localize
                     '   var lastMode=%0:s.Mode'#13#10 +         // Do not localize
                     '   if(lastMode=="")'#13#10 +     // Do not localize
                     '   {'#13#10 +         // Do not localize
                     '     %0:s.Mode=''%1:s'''#13#10 +          // Do not localize
                     '   } %%>'#13#10 +                          // Do not localize
                     '%2:s'#13#10 +                           // Do not localize
                    '<%% %0:s.Mode=lastMode'#13#10 +         // Do not localize
                     '}  %%>'#13#10;                           // Do not localize


function TCustomAdapterGrid.ImplContent(
  Options: TWebContentOptions; ParentLayout: TLayout): string;
var
  Intf: ILayoutWebContent;
  A: TLayoutAttributes;
begin
  FTableLayout := TGridLayout.Create(ParentLayout);
  try
    Result := FormatTable(FTableLayout, Options);
  finally
    FreeAndNil(FTableLayout);
  end;
  if Supports(ParentLayout, ILayoutWebContent, Intf) then
    if ParentLayout is TAdapterFormLayout then
    begin
      Result := Result + ChildTableIndent(GetParentComponent) + '</table>'#13#10;  { do not localize }
      Result := Intf.LayoutTable(ChildTableIndent(GetParentComponent) + Result, GetLayoutAttributes)
    end
    else
    begin
      Result := Result + '</table>'#13#10;  { do not localize }
      A := TLayoutAttributes.Create;
      try
        with A do
        begin
          AddQuotedAttrib(ControlAttributes, sAlignAttr, HTMLAlignValues[haCenter]);
          AddQuotedAttrib(ControlAttributes, sVAlignAttr, HTMLVAlignValues[haTop]);
          // Work better with a layout group
          Result := Intf.LayoutTable(#13#10 + Result, A);
        end
      finally
        A.Free;
      end;
    end
  else
    Result := Result + '</table>'#13#10;  { do not localize }

  if (Adapter <> nil) and (AdapterMode <> '') then
    Result := Format(sSetAdapterMode,
                     [MakeAdapterVariableName(Self), AdapterMode, Result]);
end;

const
  // Params 0 - AdapterName, 1 - MemberName, 2 - Indent
  sWriteHiddenFields =
  '<%%%2:s if (%0:s.%1:s != null)'#13#10 +                                      { do not localize }
   '%2:s   {'#13#10 +                                                           { do not localize }
   '%2:s     %0:s.%1:s.WriteFields(Response)'#13#10 +                           { do not localize }
   '%2:s   } %%>'#13#10;                                                        { do not localize }
  sHiddenFields = 'HiddenFields';                                               { do not localize }
  sHiddenRecordFields = 'HiddenRecordFields';                                   { do not localize }
  // Params 0 - AdapterName, 1 - Row
  sJSGridForEach =
  '<%% {'#13#10 +                                                               { do not localize }
   '   var ri = 0'#13#10 +                                                      { do not localize }
   '   var e = new Enumerator(%0:s.Records)'#13#10 +                            { do not localize }
   '   for (; !e.atEnd(); e.moveNext())'#13#10 +                                { do not localize }
   '   { %%>'#13#10 +                                                           { do not localize }
   '%1:s' +                                                                     { do not localize }
  '<%%  ri++'#13#10 +                                                           { do not localize }
   '   }'#13#10 +                                                               { do not localize }
   '   e.moveFirst()'#13#10 +                                                   { do not localize }
   '   } %%>'#13#10;                                                            { do not localize }

function TCustomAdapterGrid.FormatTable(Layout: TLayoutWebContent;
  Options: TWebContentOptions): string;

  function TableHeader: string;
  var
    Attribs: string;
  begin
    with TableAttributes do
    begin
      Attribs := Attribs + HTMLAlign[Align];
      AddIntAttrib(Attribs, sCellSpacingAttr, CellSpacing);
      AddIntAttrib(Attribs, sCellPaddingAttr, CellPadding);
      AddIntAttrib(Attribs, sBorderAttr, Border);
      AddStringAttrib(Attribs, sBgColorAttr, BgColor);
      AddQuotedAttrib(Attribs, sStyleAttr, Style);
      AddQuotedAttrib(Attribs, sClassAttr, StyleRule);
      AddCustomAttrib(Attribs, Custom);
    end;
    Result := Format('<table%s>'#13#10, [Attribs]);   { do not localize }
  end;

  function RowHeader(HeadingAttributes: TGridRowAttributes): string;
  var
    Attribs: string;
  begin
    with HeadingAttributes do
    begin
      Attribs := Attribs + HTMLAlign[Align];
      Attribs := Attribs + HTMLVAlign[VAlign];
      AddQuotedAttrib(Attribs, sBgColorAttr, BgColor);
      AddQuotedAttrib(Attribs, sStyleAttr, Style);
      AddQuotedAttrib(Attribs, sClassAttr, StyleRule);
      AddCustomAttrib(Attribs, Custom);
    end;
    Result := FieldIndent(Self) + Format('<tr%s>'#13#10, [Attribs]);  { do not localize }
  end;

  function FormatHiddenFields(const AdapterVarName: string): string;
  begin
    if AdapterVarName <> '' then
    begin
      Result := Format(sWriteHiddenFields, [AdapterVarName, sHiddenFields, '' { Indent }]);
    end;
  end;

  function FormatHiddenRecordFields(const AdapterVarName: string): string;
  begin
    if AdapterVarName <> '' then
    begin
      Result := Format(sWriteHiddenFields, [AdapterVarName, sHiddenRecordFields, '  ' { Indent }]);
    end;
  end;

var
  I: Integer;
  OneRow: string;
  Field: TComponent;
  FormatColumn: IFormatColumn;
  WebContent: IWebContent;
  VarName: string;
  FieldContent: string;
begin
  Result := TableHeader + RowHeader(HeadingAttributes);
  for I := 0 to VisibleFields.Count - 1 do
  begin
    Field := VisibleFields[I];
    if Supports(IInterface(Field), IWebContent, WebContent) then
      FieldContent := WebContent.Content(Options, Layout)
    else
      FieldContent := '';
    if Supports(IInterface(Field), IFormatColumn, FormatColumn) then
    begin
      Result := Result + FormatColumn.FormatColumnHeading(Options);
      OneRow := OneRow + FormatColumn.FormatColumnData(FieldContent, Options);
    end
    else if Field is TWebDataDisplay then
    begin
      // Default formatting
      Result := Result + FieldIndent(Self) + FormatColumnHeading(TWebDataDisplay(Field));
      OneRow := OneRow + FieldIndent(Self) + FormatColumnData(TWebDataDisplay(Field), FieldContent);
    end
    else
      Assert(False, 'Do not know how to format column');
  end;
  Result := Result + FieldIndent(Self) + '</tr>'#13#10;  { do not localize }

  VarName := MakeAdapterVariableName(Self);
  OneRow := OneRow + FieldIndent(Self) + '</tr>'#13#10 + FormatHiddenRecordFields(VarName);  { do not localize }
  if VarName <> '' then
    Result := Result + Format(sJSGridForEach,
      [VarName, Format('%s%s', [RowHeader(RowAttributes), OneRow])])
  else
    Result := Result + Format('%s%s', [RowHeader(RowAttributes), OneRow]);
  Result := Result + FormatHiddenFields(VarName);
end;

procedure TCustomAdapterGrid.SetHeadingAttributes(
  const Value: TGridRowAttributes);
begin
  FHeadingAttributes.Assign(Value);
end;

procedure TCustomAdapterGrid.SetRowAttributes(
  const Value: TGridRowAttributes);
begin
  FRowAttributes.Assign(Value);
end;

procedure TCustomAdapterGrid.SetTableAttributes(
  const Value: TGridAttributes);
begin
  FTableAttributes.Assign(Value);
end;

constructor TCustomAdapterGrid.Create(AOwner: TComponent);
begin
  inherited;
  FTableAttributes := TGridAttributes.Create(Self);
  FHeadingAttributes := TGridRowAttributes.Create(Self);
  FRowAttributes := TGridRowAttributes.Create(Self);
  FTableAttributes.Border := 1;
end;

destructor TCustomAdapterGrid.Destroy;
begin
  inherited;
  FTableAttributes.Free;
  FHeadingAttributes.Free;
  FRowAttributes.Free;
end;

{ TCustomAdapterDisplayColumn }

const
  sWriteColTextFunctionName = 'WriteColText';  { do not localize }
  sWriteColTextFunctionParameters = '(%s.DisplayText)';  { do not localize }
  sWriteColTextFunction =
  'function %s(t)'#13#10 +  { do not localize }
  '{'#13#10 +
  '   Response.Write((t!="")?t:"&nbsp")'#13#10 +  { do not localize }
  '}'#13#10;


function TCustomAdapterDisplayColumn.FormatTextDisplay(
  const VarName, HTMLName: string): string;
var
  Attrs: string;
begin
  Result := Format('<%% %s%s %%>',
    [sWriteColTextFunctionName,
      Format(sWriteColTextFunctionParameters, [VarName])]);
  AddQuotedAttrib(Attrs, sStyleAttr, Style);
  AddQuotedAttrib(Attrs, sClassAttr, StyleRule);
  AddCustomAttrib(Attrs, Custom);
  if Attrs <> '' then
    Result := Format('<span%s>%s</span>', [Attrs, Result]);  { do not localize }
end;

const
  sListValuesFunctionName = 'ListValues';
  sListValuesFunctionParameters = '(%s)';
  sListValuesFunction =
  'function %s(f)'#13#10 +
  '{'#13#10 +
  '   var s='''''#13#10 +
  '   var v='''''#13#10 +
  '   var n='''''#13#10 +
  '   var c=0;'#13#10 +
  '   if (f.Values == null) return s;'#13#10 +
  '   var e = new Enumerator(f.Values.Records)'#13#10 +
  '   for (; !e.atEnd(); e.moveNext())'#13#10 +
  '   {'#13#10 +
  '     s+= ''<li>'''#13#10 +
  '     s += f.Values.ValueField.DisplayText;'#13#10 +
  '     s += ''</li>'''#13#10 +
  '     c++'#13#10 +
  '   }'#13#10 +
  '   e.moveFirst()'#13#10 +
  '   r = new Object;'#13#10 +
  '   r.text = s'#13#10 +
  '   r.count = c'#13#10 +
  '   return r;'#13#10 +
  ' }'#13#10;

  sSelOptionsFunctionName = 'SelOptions';
  sSelOptionsFunctionParameters = '(%s)';
  sSelOptionsFunction =
  'function %s(f)'#13#10 +
  '{'#13#10 +
  '   var s='''''#13#10 +
  '   var v='''''#13#10 +
  '   var n='''''#13#10 +
  '   var c=0'#13#10 +
  '   if (f.ValuesList != null)'#13#10 +
  '   {'#13#10 +
  '     var e = new Enumerator(f.ValuesList.Records)'#13#10 +
  '     for (; !e.atEnd(); e.moveNext())'#13#10 +
  '     {'#13#10 +
  '       s+= ''<option'''#13#10 +
  '       v = f.ValuesList.Value;'#13#10 +
  '       var selected'#13#10 +
  '       if (f.Values == null)'#13#10 +
  '          selected = f.IsEqual(v)'#13#10 +
  '       else'#13#10 +
  '          selected = f.Values.HasValue(v)'#13#10 +
  '       if (selected)'#13#10 +
  '          s += '' selected'''#13#10 +
  '       n = f.ValuesList.ValueName;'#13#10 +
  '       if (n=='''')'#13#10 +
  '       {'#13#10 +
  '         n = v'#13#10 +
  '         v = '''''#13#10 +
  '       }'#13#10 +
  '       if ((typeof(v) != ''string'') || (v != ''''))'#13#10 +
  '          s += '' value="'' + v + ''"'''#13#10 +
  '       s += ''>'' + n + ''</option>\r\n'''#13#10 +
  '       c++'#13#10 +
  '     }'#13#10 +
  '     e.moveFirst()'#13#10 +
  '   }'#13#10 +
  '   r = new Object;'#13#10 +
  '   r.text = s'#13#10 +
  '   r.count = c'#13#10 +
  '   return r;'#13#10 +
  ' }'#13#10;

  sRadioGroupFunctionName = 'RadioGroup';
  sCheckBoxGroupFunctionName = 'CheckBoxGroup';
  sInputGroupFunctionParameters = '(%0:s, %1:s, %2:d, ''%3:s'')';
  sInputGroupFunction =
  'function %0:s(f,nm,cols,attr)'#13#10 +
  '{'#13#10 +
  '   var s='''''#13#10 +
  '   var v='''''#13#10 +
  '   var n='''''#13#10 +
  '   var c=0;'#13#10 +
  '   if (f.ValuesList == null)'#13#10 +
  '   {'#13#10 +
  '     s+= ''<input type="%1:s"'''#13#10 +
  '     if (f.IsEqual(true)) s+= '' checked'''#13#10 +
  '     s += '' value="true"'' + '' name="'' + nm + ''"'''#13#10 +
  '     if (attr!='''') s+= '' '' + attr'#13#10 +
  '     s += ''>\r\n'''#13#10 +
  '     c = 1'#13#10 +
  '   }'#13#10 +
  '   else'#13#10 +
  '   {'#13#10 +
  '     s += ''<table><tr>'''#13#10 +
  '     var e = new Enumerator(f.ValuesList.Records)'#13#10 +
  '     for (; !e.atEnd(); e.moveNext())'#13#10 +
  '     {'#13#10 +
  '       if (c %% cols == 0 && c != 0) s += ''</tr><tr>'''#13#10 +
  '       s+= ''<td><input type="%1:s"'''#13#10 +
  '       v = f.ValuesList.Value;'#13#10 +
  '       var checked'#13#10 +
  '       if (f.Values == null)'#13#10 +
  '         checked = (f.IsEqual(v))'#13#10 +
  '       else'#13#10 +
  '         checked = f.Values.HasValue(v)'#13#10 +
  '       if (checked)'#13#10 +
  '         s+= '' checked'''#13#10 +
  '       n = f.ValuesList.ValueName;'#13#10 +
  '       if (n=='''')'#13#10 +
  '       {'#13#10 +
  '       n = v'#13#10 +
  '       }'#13#10 +
  '       s += '' value="'' + v + ''"'' + '' name="'' + nm + ''"'''#13#10 +
  '       if (attr!='''') s+= '' '' + attr'#13#10 +
  '       s += ''>'' + n + ''</td>\r\n'''#13#10 +
  '       c++'#13#10 +
  '     }'#13#10 +
  '     e.moveFirst()'#13#10 +
  '     s += ''</tr></table>'''#13#10 +
  '   }'#13#10 +
  '   r = new Object;'#13#10 +
  '   r.text = s'#13#10 +
  '   r.count = c'#13#10 +
  '   return r;'#13#10 +
  ' }'#13#10;

function TCustomAdapterDisplayColumn.FormatListDisplay(
  const VarName, HTMLName: string): string;
var
  Attrs: string;
begin
  AddQuotedAttrib(Attrs, sStyleAttr, Style);
  AddQuotedAttrib(Attrs, sClassAttr, StyleRule);
  AddCustomAttrib(Attrs, Custom);
  Result := Format('<%% obj=%0:s%1:s%%>',
    [sListValuesFunctionName,
      Format(sListValuesFunctionParameters, [VarName])]);
  Result := Result + Format('<ul %0:s>'#13#10'%1:s</ul>',   { do not localize }
                   [Attrs,
                   '<%=obj.text%>']);                       { do not localize }
end;

function CalcDefaultAdapterInputElementType(AField: TComponent; const AAdapterMode: string): TAdapterInputHTMLElementType;
var
  Intf: IGetHTMLStyle;
  S: string;
  I: TAdapterInputHTMLElementType;
begin
  Result := htmliTextInput;
  if Supports(IUnknown(AField), IGetHTMLStyle, Intf) then
  begin
    S := Intf.GetInputStyle(AAdapterMode);
    for I := Low(TAdapterInputHTMLElementType) to High(TAdapterInputHTMLElementType) do
      if CompareText(S, AdapterInputHTMLElementTypeNames[I]) = 0 then
      begin
        Result := I;
        break
      end;
  end;
end;

function CalcDefaultAdapterDisplayElementType(AField: TComponent; const AAdapterMode: string): TAdapterDisplayHTMLElementType;
var
  Intf: IGetHTMLStyle;
  S: string;
  I: TAdapterDisplayHTMLElementType;
begin
  Result := htmldText;
  if Supports(IUnknown(AField), IGetHTMLStyle, Intf) then
  begin
    S := Intf.GetDisplayStyle(AAdapterMode);
    for I := Low(TAdapterDisplayHTMLElementType) to High(TAdapterDisplayHTMLElementType) do
      if CompareText(S, AdapterDisplayHTMLElementTypeNames[I]) = 0 then
      begin
        Result := I;
        break
      end;
  end;
end;

function CalcDefaultAdapterActionElementType(AAction: TComponent; const AAdapterMode: string): TAdapterActionHTMLElementType;
var
  Intf: IGetHTMLStyle;
  S: string;
  I: TAdapterActionHTMLElementType;
begin
  Result := htmlaButton;
  if Supports(IUnknown(AAction), IGetHTMLStyle, Intf) then
  begin
    S := Intf.GetDisplayStyle(AAdapterMode);
    for I := Low(TAdapterActionHTMLElementType) to High(TAdapterActionHTMLElementType) do
      if CompareText(S, AdapterActionHTMLElementTypeNames[I]) = 0 then
      begin
        Result := I;
        break
      end;
  end;
end;

function CalcDefaultAdapterViewModeType(AField: TComponent; const AAdapterMode: string): TAdapterDisplayViewModeType;
var
  Intf: IGetHTMLStyle;
  S: string;
  I: TAdapterDisplayViewModeType;
begin
  Result := htmlvmInput;
  if Supports(IUnknown(AField), IGetHTMLStyle, Intf) then
  begin
    S := Intf.GetViewMode(AAdapterMode);
    for I := Low(TAdapterDisplayViewModeType) to High(TAdapterDisplayViewModeType) do
      if CompareText(S, AdapterDisplayViewModeTypeNames[I]) = 0 then
      begin
        Result := I;
        break
      end;
  end;
end;

function CalcDisplayFieldViewMode(AField: TComponent; const AAdapterMode: string; AViewMode: TDisplayFieldViewMode; var AMode: TDisplayFieldViewMode): Boolean;
  function ConvertViewModeType(T: TAdapterDisplayViewModeType): TDisplayFieldViewMode;
  begin
    case T of
      htmlvmInput:                 Result := vmInput;
      htmlvmDisplay:               Result := vmDisplay;
      htmlvmToggleOnAccess:        Result := vmToggleOnAccess;
    else
      Result := vmInput;
      Assert(False); // unexpected type
    end;
  end;
var
  AdapterModeType: TAdapterDisplayViewModeType;
begin
  if AViewMode = vmDefault then
  begin
    AMode := vmInput;
    Result := True;
    if AField <> nil then
    begin
      AdapterModeType := CalcDefaultAdapterViewModeType(AField, AAdapterMode);
      if AdapterModeType <> htmlvmNone then
      begin
        AMode := ConvertViewModeType(AdapterModeType);
        Result := True;
      end
      else
        Result := False;
    end;
  end
  else
  begin
    AMode := AViewMode;
    Result := True;
  end;
end;


function CalcDisplayFieldHTMLElementType(AField: TComponent; const AAdapterMode: string; ADisplayType: TDisplayFieldHTMLElementType; var AType: TDisplayFieldHTMLElementType): Boolean;
  function ConvertDisplayType(T: TAdapterDisplayHTMLElementType): TDisplayFieldHTMLElementType;
  begin
    case T of
      htmldText:  Result := dftText;
      htmldImage: Result := dftImage;
      htmldList: Result := dftList;
    else
      Result := dftText;
      Assert(False, 'unexpected type');
    end;
  end;
var
  AdapterDisplayType: TAdapterDisplayHTMLElementType;
begin
  if ADisplayType = dftDefault then
  begin
    AType := dftText;
    Result := True;
     if AField <> nil then
    begin
      AdapterDisplayType := CalcDefaultAdapterDisplayElementType(AField, AAdapterMode);
      if AdapterDisplayType <> htmldNone then
      begin
        AType := ConvertDisplayType(AdapterDisplayType);
        Result := True;
      end
      else
        Result := False;
    end;
  end
  else
  begin
    AType := ADisplayType;
    Result := True;
  end;
end;

function TCustomAdapterDisplayColumn.FormatImage(const VarName, HTMLName: string; Options: TWebContentOptions): string;
var
  Attrs: string;
  HREF: string;
begin
  AddQuotedAttrib(Attrs, sStyleAttr, Style);
  AddQuotedAttrib(Attrs, sClassAttr, StyleRule);
  AddIntAttrib(Attrs, 'width', ImageWidth);    { do not localize }
  AddIntAttrib(Attrs, 'height', ImageHeight);  { do not localize }
  AddCustomAttrib(Attrs, Custom);
  HREF := Format('<%%=(%0:s.Image!=null)?%0:s.Image.AsHREF:''''%%>', [VarName]);  { do not localize }
  Result := Format('<img src="%0:s"%2:s alt="<%%=%1:s.DisplayText%%>">', [HREF, VarName,  { do not localize }
    Attrs]);
end;

function TCustomAdapterDisplayColumn.ControlContent(
  Options: TWebContentOptions): string;

  function ConvertDisplayType(T: TAdapterDisplayHTMLElementType): TColumnHTMLElementType;
  begin
    case T of
      htmldText:  Result := coltText;
      htmldImage: Result := coltImage;
      htmldList: Result := coltList;
    else
      Result := coltText;
      Assert(False, 'unexpected type');
    end;
  end;
var
  VarName: string;
  HTMLName: string;
  Field: TComponent;
  DisplayType: TColumnHTMLElementType;
begin
  if hoHideAlways in HideOptions then
  begin
    Result := '';
    Exit;
  end;
  VarName := MakeAdapterVariableName(Self);
  if Varname <> '' then
  begin
    HTMLName := MakeAdapterHTMLName(VarName);
    Field := FindAssociatedField;
    if Field <> nil then
      DisplayType := ConvertDisplayType(CalcDefaultAdapterDisplayElementType(Field, GetAdapterModeOfAdapter))
    else
      DisplayType := coltText;
    case DisplayType of
      coltImage:
        Result := FormatImage(VarName, HTMLName, Options);
      coltList:
        Result := FormatListDisplay(VarName, HTMLName);
    else
      Result := FormatTextDisplay(VarName, HTMLName)
    end
  end
  else
    Result := '';
end;

constructor TCustomAdapterDisplayColumn.Create(AOwner: TComponent);
begin
  inherited;
  FImageWidth := -1;
  FImageHeight := -1;
end;

function TCustomAdapterGrid.GetAdapterDisplayCharacteristics: TAdapterDisplayCharacteristics;
begin
  Result := [dcMultipleRecordView {, dcCurrentRecordView,
    dcChangeCurrentRecordView} ];
end;

function TCustomAdapterGrid.GetAddAllFieldsItem: string;
begin
  Result := sAddAllColumns;
end;

function TCustomAdapterGrid.GetAddFieldsDlgCaption: string;
begin
  Result := sAddColumnsDlgCaption;
end;

function TCustomAdapterGrid.GetAddFieldsItem: string;
begin
  Result := sAddColumns;
end;

function TCustomAdapterGrid.GetNewFieldPrefix: string;
begin
  Result := sAdapterColumnPrefix;
end;

function TCustomAdapterDisplayColumn.ImplFormatColumnHeading(Options: TWebContentOptions): string;
var
  Attribs: string;
  S: string;
  Conditions: string;
begin
  if hoHideAlways in HideOptions then
  begin
    Result := '';
    Exit;
  end;
  AddQuotedAttrib(Attribs, sStyleAttr, Self.CaptionAttributes.Style);
  AddCustomAttrib(Attribs, Self.CaptionAttributes.Custom);
  AddQuotedAttrib(Attribs, sClassAttr, Self.CaptionAttributes.StyleRule);
  AddQuotedAttrib(Attribs, sVAlignAttr, HTMLVAlignValues[Self.CaptionAttributes.VAlign]);
  AddQuotedAttrib(Attribs, sAlignAttr, HTMLAlignValues[Self.CaptionAttributes.Align]);
  S := Self.Caption;
  Result := Format('<th%s>%s</th>'#13#10, [Attribs, S]);   { do not localize }
  Conditions := FieldConditions(Options);
  if Conditions <> '' then
    Result := Format(Conditions, [FieldIndent(Self) + Result])
  else
    Result := FieldIndent(Self) + Result;
end;

function WriteColTextFunction(AComponent: TComponent): string;
begin
  Result := Format('<%%'#13#10 + sWriteColTextFunction + '%%>', [sWriteColTextFunctionName]);
end;

procedure TCustomAdapterDisplayColumn.ImplGetControlRequirements(
  ARequirements: TAbstractControlRequirements);
begin
  inherited ImplGetControlRequirements(ARequirements);
  if not ARequirements.IsFunctionDefined(sWriteColTextFunctionName) then
    ARequirements.DefineFunction(sWriteColTextFunctionName,
      WriteColTextFunction(Self));
end;

function TCustomAdapterDisplayColumn.ImplCanAddClass(AParent: TComponent;
  AClass: TClass): Boolean;
begin
  Result := AClass.InheritsFrom(TCustomAdapterActionButton) or
        CanAddClassHelper(Self, AParent, AClass);
end;

function TCustomAdapterDisplayColumn.CanAddClass(AParent: TComponent;
  AClass: TClass): Boolean;
begin
  Result := ImplCanAddClass(AParent, AClass);
end;

{ TAdapterControlGroup }

function TAdapterControlGroup.GetVisibleFields: TWebComponentList;
begin
  if (AddDefaultFields = False) or (GetWebComponents.Count > 0) then
    Result := GetWebComponents
  else
  begin
    if GetDefaultWebComponents = nil then
      CreateDefaultFields;
    Result := GetDefaultWebComponents;
  end;
end;

procedure TAdapterControlGroup.CreateDefaultFields;
var
  WebComponent: IWebComponent;
  FieldName: IWebSetFieldName;
  FieldControl: TComponent;
  FieldClass: TComponentClass;
  List: TStrings;
  I: integer;
  Components: TWebComponentList;
begin
  if (Adapter <> nil) then
  begin
    List := TStringList.Create;
    try
      GetFieldsList(List);
      Components := TWebComponentList.Create(Self);
      Components.LockNotify;
      try
        SetDefaultWebComponents(Components);
        for I := 0 to List.Count - 1 do
        begin
          if not IsFieldInUse(List[I]) then
          begin
            FieldClass := TComponentClass(List.Objects[I]);
            FieldControl := FieldClass.Create(nil);  // not owned
            Supports(IInterface(FieldControl), IWebComponent, WebComponent);
            WebComponent.Container := Self.WebFieldControls;
            if Supports(IInterface(FieldControl), IWebSetFieldName, FieldName) then
               FieldName.SetFieldName(List[I]);
          end;
        end;
      finally
        Components.UnlockNotify;
      end;
    finally
      List.Free;
    end;
  end
  else
    SetDefaultWebComponents(TWebComponentList.Create(Self));
end;

function TAdapterControlGroup.IsFieldInUse(const AName: string): Boolean;
begin
  Result := FindField(AName) <> nil;
end;

function TAdapterControlGroup.FindField(const AName: string): TComponent;
var
  I: Integer;
  FieldName: IWebGetFieldName;
begin
  for I := 0 to GetWebComponents.Count - 1 do
  begin
    if Supports(IInterface(GetWebComponents.WebComponents[I]), IWebGetFieldName, FieldName) then
    begin
      Result := GetWebComponents.WebComponents[I];
      if AnsiCompareText(FieldName.FieldName, AName) = 0 then Exit;
    end;
  end;
  Result := nil;
end;

function TAdapterControlGroup.GetAdapter: TComponent;
begin
  Result := FAdapter;
end;

procedure TAdapterControlGroup.SetAdapter(
  const Value: TComponent);
var
  NotifyList: INotifyList;
begin
  if FAdapter <> Value then
  begin
    if Value <> nil then Value.FreeNotification(Self);
    if FAdapter <> nil then
      if Supports(IInterface(FAdapter), INotifyList, NotifyList) then
        NotifyList.RemoveNotify(Self);
    FAdapter := Value;
    if Supports(IInterface(FAdapter), INotifyList, NotifyList) then
      NotifyList.AddNotify(Self);
    AdapterChange;
  end;
end;

procedure TAdapterControlGroup.Notification(AComponent: TComponent; Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (AComponent = FAdapter) then
    FAdapter := nil;
end;

procedure TAdapterControlGroup.GetFieldsList(List: TStrings);
var
  I: Integer;
  TextClass: TAdapterDataDisplayClass;
  WebComponent: TComponent;
  WebVariables: IWebVariablesContainer;
  WebVariableName: IWebVariableName;
  GetIntf: IGetAdapterFields;
  IsDefaultField: IWebIsDefaultField;
begin
  if ImplCanAddClass(Self, TAdapterDisplayColumn) then
    TextClass := TAdapterDisplayColumn
  else if ImplCanAddClass(Self, TAdapterDisplayField) then
    TextClass := TAdapterDisplayField
  else
    TextClass := nil;

  List.Clear;
  if Supports(IUnknown(Adapter), IGetAdapterFields, GetIntf) and
    Supports(GetIntf.GetAdapterFields, IWebVariablesContainer, WebVariables) then
  begin
    for I := 0 to WebVariables.VariableCount - 1 do
    begin
      WebComponent := WebVariables.Variables[I];
      if Assigned(TextClass) then
        if Supports(IUnknown(WebComponent), IWebVariableName, WebVariableName) then
          if (not Supports(IUnknown(WebComponent), IWebIsDefaultField, IsDefaultField)) or
            IsDefaultField.IsDefaultField(Self) then
            List.AddObject(WebVariableName.VariableName, TObject(TextClass));
    end;
  end;
end;

destructor TAdapterControlGroup.Destroy;
var
  NotifyList: INotifyList;
begin
  inherited;
  if Supports(IInterface(FAdapter), INotifyList, NotifyList) then
    NotifyList.RemoveNotify(Self);
  FNotifyList.Free;
end;

procedure TAdapterControlGroup.NotifyAdapterChange(Sender: TComponent);
begin
  AdapterChange;
end;

procedure TAdapterControlGroup.AdapterChange;
var
  I: Integer;
  AdapterChange: INotifyAdapterChange;
begin
  // Prevent the components from being freed during
  // the process of populating the defaulit components
  if (GetDefaultWebComponents <> nil) then
  begin
    GetDefaultWebComponents.Free;
    SetDefaultWebComponents(nil);
  end;
  for I := 0 to FNotifyList.Count - 1 do
    if Supports(FNotifyList[I], INotifyAdapterChange, AdapterChange) then
      AdapterChange.NotifyAdapterChange(Self);
  for I := 0 to GetWebComponents.Count - 1 do
    if Supports(IUnknown(GetWebComponents.WebComponents[I]), INotifyAdapterChange, AdapterChange) then
      AdapterChange.NotifyAdapterChange(Self);
end;

function TAdapterControlGroup.GetAdapterVariableName: string;
var
  WebVariableName: IWebVariableName;
begin
  Result := '';
  if Supports(IUnknown(Adapter), IWebVariableName, WebVariableName) then
    Result := sVarPrefix + WebVariableName.VariableName;
end;

procedure TAdapterControlGroup.AddNotify(ANotify: TObject);
begin
  FNotifyList.AddNotify(ANotify);
end;

constructor TAdapterControlGroup.Create(AOwner: TComponent);
begin
  inherited;
  FNotifyList := TNotifyList.Create;
  FAddDefaultFields := True;
end;

procedure TAdapterControlGroup.RemoveNotify(ANotify: TObject);
begin
  FNotifyList.RemoveNotify(ANotify);
end;

procedure TAdapterControlGroup.GetDesigntimeWarnings(
  AWarnings: TAbstractDesigntimeWarnings);
begin
  if Adapter = nil then
    AWarnings.AddString(Format(sAdapterPropertyIsNil, [Self.Name]))
  else
    AWarnings.AddObject(Adapter);
end;

function TAdapterControlGroup.GetAdapterModeOfAdapter: string;
var
  AdapterModeIntf: IAdapterMode;
begin
  if Supports(IUnknown(Adapter), IAdapterMode, AdapterModeIntf) then
    Result := AdapterModeIntf.AdapterMode;

  if Result = '' then
    // Adapter mode may have not been set
    Result := FAdapterMode
end;

function TAdapterControlGroup.GetAdapterModeOfDisplay: string;
begin
  Result := FAdapterMode;
end;

procedure TAdapterControlGroup.SetAddDefaultFields(const Value: Boolean);
begin
  if FAddDefaultFields <> Value then
  begin
    if (GetDefaultWebComponents <> nil) then
    begin
      GetDefaultWebComponents.Free;
      SetDefaultWebComponents(nil);
    end;
    FAddDefaultFields := Value;
  end;
end;

{ TAdapterDataDisplay }

function TAdapterDataDisplay.GetFieldName: string;
begin
  Result := FFieldName;
end;

procedure TAdapterDataDisplay.SetFieldName(const Value: string);
var
  Intf: IValidateFields;
  Component: TComponent;
begin
  if (AnsiCompareText(Value, FFieldName) <> 0) then
  begin
    FFieldName := Value;
    if (inherited GetCaption = Value) then inherited SetCaption('');
    if Assigned(WebParent) and
      not (csLoading in ComponentState) and (Length(Value) > 0) then
      ImplRestoreDefaults;
    if [csLoading, csDesigning] * ComponentState <> [] then
    begin
      Component := GetParentComponent;
      { IValidateFields not implemented by parent }
      while Assigned(Component) and
       (not Supports(IInterface(Component), IValidateFields, Intf)) do
       Component := Component.GetParentComponent;
      if Assigned(Component) then
        Intf.EnableValidateFields := True;
    end;
  end;
end;

function TAdapterDataDisplay.GetCaption: string;
begin
  if inherited GetCaption = '' then
  begin
    Result := FFieldName;
    if Result = '' then
      Result := Name;
  end
  else
    Result := inherited GetCaption;
end;

procedure TAdapterDataDisplay.SetCaption(Value: string);
begin
  if FFieldName <> '' then
    if Value = FFieldName then inherited SetCaption('') else inherited SetCaption(Value)
  else
    if Value = Name then inherited SetCaption('') else inherited SetCaption(Value)
end;

procedure TAdapterDataDisplay.RestoreDefaults;
begin
  ImplRestoreDefaults;
end;

function TAdapterDataDisplay.GetAdapterVariableName: string;
var
  C: TComponent;
begin
  Result := '';
  if FieldName <> '' then
  begin
    C := FindAssociatedField;
    Result := MakeAdapterItemVariableName(C);
  end;
end;

procedure TAdapterDataDisplay.ImplRestoreDefaults;
begin
  // Do nothing
end;

function TAdapterDataDisplay.FindAssociatedField: TComponent;
var
  Intf: IWebVariablesContainer;
  C: TObject;
begin
  Result := nil;
  if FFieldName <> '' then
  begin
    C := FindVariablesContainerInParent(Self);
    if Supports(C, IWebVariablesContainer, Intf) then
      Result := Intf.FindVariable(FFieldName)
    else
      Assert(C=nil);
  end;
end;

function TAdapterDataDisplay.FormatCaption: string;
var
  Attribs: string;
begin
  AddQuotedAttrib(Attribs, sVAlignAttr, HTMLVAlignValues[CaptionAttributes.VAlign]);
  AddQuotedAttrib(Attribs, sAlignAttr, HTMLAlignValues[CaptionAttributes.Align]);
  // Label attributes include alignment only
  LayoutAttributes.LabelAttributes := Attribs;
  Attribs := '';
  AddQuotedAttrib(Attribs, sStyleAttr, CaptionAttributes.Style);
  AddCustomAttrib(Attribs, CaptionAttributes.Custom);
  AddQuotedAttrib(Attribs, sClassAttr, CaptionAttributes.StyleRule);
  case CaptionPosition of
    capLeft: LayoutAttributes.LabelPosition := lposLeft;
    capRight: LayoutAttributes.LabelPosition := lposRight;
    capAbove: LayoutAttributes.LabelPosition := lposAbove;
    capBelow: LayoutAttributes.LabelPosition := lposBelow;
  else
    Assert(False, 'Unknown position');
  end;
  if Attribs <> '' then
    Result := Format('<span%0:s>%1:s</span>', [Attribs, Caption])  { do not localize }
  else
    Result := Caption;
end;

procedure TAdapterDataDisplay.GetControlRequirements(
  ARequirements: TAbstractControlRequirements);
begin
  ImplGetControlRequirements(ARequirements);
end;

procedure TAdapterDataDisplay.ImplGetControlRequirements(
  ARequirements: TAbstractControlRequirements);
var
  S: string;
  C: TComponent;
begin
  S := GetAdapterVariableName;
  if S <> '' then
    if not ARequirements.IsVariableDefined(S) then
    begin
      C := FindAssociatedField;
      ARequirements.DefineVariable(S,
        MakeAdapterItemVariableValue(C), False)
    end;

end;

function TAdapterDataDisplay.ImplContent(Options: TWebContentOptions;
  ParentLayout: TLayout): string;
var
  Intf: ILayoutWebContent;
  S: string;
begin
  S := ControlContent(Options);
  if S <> '' then
  begin
    if Supports(ParentLayout, ILayoutWebContent, Intf) then
      Result := Intf.LayoutLabelAndField(LabelContent, S,
        GetLayoutAttributes)
    else
      Result := LabelContent + S;
  end
  else
    Result := '';
end;

function TAdapterDataDisplay.GetVariablesContainer: TComponent;
begin
  // Contains actions
  Result := FindAssociatedField;
end;

procedure TAdapterDataDisplay.GetDesigntimeWarnings(
  AWarnings: TAbstractDesigntimeWarnings);
begin
  if FieldName = '' then
    AWarnings.AddString(Format(sAdapterFieldNameIsBlank, [Self.Name]))
  else
    if FindAssociatedField = nil then
      AWarnings.AddString(Format(sCantFindAdapterField, [Self.Name, FieldName]));

end;

function FormatHideFieldConditions(const VarName, FieldIndent: string; HideOptions: TDisplayFieldHideOptions): string;
var
  Condition: string;

  procedure AddToCondition(const S: string);
  begin
    if Condition <> '' then
      Condition := Condition + ' && ';
    Condition := Condition + S;
  end;
begin
  Result := '';
  if VarName <> '' then
  begin
    if hoHideAlways in HideOptions then
    begin
      Assert(False); // Unexpected all
      Result := ''
    end
    else
    begin
      if hoHideOnNoInputAccess in HideOptions then
        AddToCondition(sCanModifyCondition);
      if hoHideOnNoDisplayAccess in HideOptions then
        AddToCondition(sCanViewCondition);
      if hoHideOnFieldNotVisible in HideOptions then
        AddToCondition(sIsVisibleCondition);
      if Condition <> '' then
      begin
        Condition := Format(Condition, [VarName]);
        Result := Format(sIfCan, [Condition]);
      end;
    end;
  end
end;

function TAdapterDataDisplay.FieldConditions(
  Options: TWebContentOptions): string;
begin
  Result := FormatHideFieldConditions(MakeAdapterVariableName(Self), FieldIndent(Self), HideOptions);
end;

function TAdapterDataDisplay.FormatColumnData(const Content: string;
  Options: TWebContentOptions): string;
begin
  Result := ImplFormatColumnData(Content, Options);
end;

function TAdapterDataDisplay.FormatColumnHeading(
  Options: TWebContentOptions): string;
begin
  Result := ImplFormatColumnHeading(Options);
end;

function TAdapterDataDisplay.ImplFormatColumnData(const Content: string;
  Options: TWebContentOptions): string;
var
  Conditions: string;
  Attribs: string;
begin
  if hoHideAlways in HideOptions then
  begin
    Result := '';
    Exit;
  end;
  AddQuotedAttrib(Attribs, sAlignAttr, HTMLAlignValues[Align]);
  AddQuotedAttrib(Attribs, sVAlignAttr, HTMLVAlignValues[VAlign]);
  Result := Format('<td%s><div>%s</div></td>'#13#10, [Attribs,  { do not localize }
    Content]);
  Conditions := FieldConditions(Options);
  if Conditions <> '' then
    Result := Format(Conditions, [FieldIndent(Self) + Result])
  else
    Result := FieldIndent(Self) + Result;
end;

function TAdapterDataDisplay.ImplFormatColumnHeading(Options: TWebContentOptions): string;
var
  Attribs: string;
  S: string;
  Conditions: string;
begin
  if hoHideAlways in HideOptions then
  begin
    Result := '';
    Exit;
  end;
  AddQuotedAttrib(Attribs, sStyleAttr, Self.CaptionAttributes.Style);
  AddCustomAttrib(Attribs, Self.CaptionAttributes.Custom);
  AddQuotedAttrib(Attribs, sClassAttr, Self.CaptionAttributes.StyleRule);
  S := Self.Caption;
  Result := Format('<th%s>%s</th>'#13#10, [Attribs, S]);  { do not localize }
  Conditions := FieldConditions(Options);
  if Conditions <> '' then
    Result := Format(Conditions, [FieldIndent(Self) + Result])
  else
    Result := FieldIndent(Self) + Result;
end;

constructor TAdapterDataDisplay.Create(AOwner: TComponent);
begin
  inherited;
  FHideOptions := [hoHideOnFieldNotVisible];
end;

{ TAdapterFormLayout}

constructor TAdapterFormLayout.Create(AParentLayout: TLayout);
begin
  inherited;
  FInTable := False;
  FInRow := False;
  FColumnCount := 1;
  FColumnIndex := 0;
  FTableHeader := '<table>';  { do not localize }
  FLayoutState := lsUnknown;
  FBreakButtons := False;
  if AParentLayout <> nil then
    if AParentLayout is TAdapterFormLayout then
      FParentIndent := TAdapterFormLayout(AParentLayout).ChildTableIndent;
end;

function TAdapterFormLayout.ImplLayoutButton(const HTMLButton: string; Attributes: TLayoutAttributes): string;
begin
  Result := StartButtons;
  if FBreakButtons then
    Result := Format('%0:s%3:s>%1:s</td>'#13#10, [Result, HTMLButton, FieldIndent, Attributes.ControlAttributes])  { do not localize }
  else if FButtonIndex = 1 then
    Result := Format('%0:s%3:s>%1:s</td>'#13#10, [Result, HTMLButton, FieldIndent, Attributes.ControlAttributes])  { do not localize }
  else
    Result := Format('%0:s%2:s<td%3:s>%1:s</td>'#13#10,     { do not localize }
      [Result, HTMLButton, FieldIndent, Attributes.ControlAttributes]);
end;

function TAdapterFormLayout.ImplLayoutField(const HTMLField: string; Attributes: TLayoutAttributes): string;
begin
  if Assigned(Attributes) then
    Result := StartFields(1) + Format('%0:s>%1:s</td>', [Attributes.ControlAttributes, HTMLField]) { do not localize }
  else
    Result := StartFields(1) + Format('>%0:s</td>', [HTMLField]);  { do not localize }
end;

function TAdapterFormLayout.ImplLayoutLabelAndField(const HTMLLabel, HTMLField: string; Attributes: TLayoutAttributes): string;
begin
  if HTMLField = '' then
  begin
    Result := '';
    Exit;
  end;
  if Assigned(Attributes) then
    case Attributes.LabelPosition of
      lposLeft:
      begin
        Result := StartFields(2) +
           Format('%0:s>%1:s</td>'#13#10 + FieldIndent + '<td %2:s>%3:s</td>'#13#10, { do not localize }
            [Attributes.LabelAttributes, HTMLLabel, Attributes.ControlAttributes, HTMLField]);
      end;
      lposRight:
      begin
        Result := StartFields(2) +
          Format('%0:s>%1:s</td>'#13#10'<td %2:s>%3:s</td>'#13#10,  { do not localize }
            [Attributes.ControlAttributes, HTMLField, Attributes.LabelAttributes, HTMLLabel]);
      end;
      lposAbove:
        Result :=
          StartFields(1) +
           Format('%0:s>%1:s</td></tr>'#13#10'<tr><td ' + sColSpanAttr + '="2" %2:s>%3:s</td>'#13#10, { do not localize }
            [Attributes.LabelAttributes, HTMLLabel, Attributes.ControlAttributes, HTMLField]);
      lposBelow:
        Result :=
          StartFields(1) +
           Format('%0:s>%1:s</td></tr>'#13#10'<tr><td ' + sColSpanAttr + '="2" %2:s>%3:s</td>'#13#10,  { do not localize }
            [Attributes.ControlAttributes, HTMLField, Attributes.LabelAttributes, HTMLLabel]);
    else
      Assert(False, 'Unknown position');
    end
  else
    Result :=
        StartFields(2) + Format('>%0:s</td>'#13#10'<td>%1:s</td>'#13#10,  { do not localize }
          [HTMLLabel, HTMLField])
end;

function TAdapterFormLayout.ImplLayoutTable(const HTMLTable: string; Attributes: TLayoutAttributes): string;
begin
  if Assigned(Attributes) then
    Result := StartFields(1) + Format('%0:s>'#13#10 + '%1:s' + FieldIndent + '</td>'#13#10, [Attributes.ControlAttributes, HTMLTable])  { do not localize }
  else
    Result := StartFields(1) + Format('>'#13#10 + '%0:s' + FieldIndent + '</td>'#13#10, [HTMLTable]);  { do not localize }

end;

function TAdapterFormLayout.StartFields(ColCount: Integer): string;
begin
  Result := EndButtons;
  if FLayoutState <> lsFields then
    Inc(FFieldLevel);
  FLayoutState := lsFields;
  Result := Result + StartTable + StartRow + NextColumn(ColCount);
end;


function TAdapterFormLayout.EndField: string;
begin
  Result := '';
  if (FLayoutState = lsButtons) and (not FBreakButtons) and (FButtonIndex = 0) then
    // Do nothing
  else if (FLayoutState <> lsButtons) or FBreakButtons then
    if FInRow and (FColumnIndex = FColumnCount) then
    begin
      Result := FieldIndent + '</tr>'#13#10;  { do not localize }
      FColumnIndex := 0;
      FInRow := False;
    end;
end;

function TAdapterFormLayout.NextColumn(SubItemCount: Integer): string;
begin
  Result := '';
  if (FLayoutState = lsButtons) and (not FBreakButtons) and (FButtonIndex = 0) then
    Result := FieldIndent + '<td'  { do not localize }
  else if (FLayoutState <> lsButtons) or FBreakButtons then
  begin
    if FColumnIndex = FColumnCount then
    begin
      Result := EndRow;
      FColumnIndex := 0;
    end;
    if not FInRow then
      Result := Result + StartRow + FieldIndent + '<td'  { do not localize }
    else
      Result := FieldIndent + '<td';  { do not localize }
    Inc(FColumnIndex);
  end;
  if FLayoutState = lsButtons then
    Inc(FButtonIndex);
end;

function TAdapterFormLayout.StartRow: string;
begin
  if not FInRow then
  begin
    Result := FieldIndent + '<tr>'#13#10;  { do not localize }
    FInRow := True;
  end
  else
    Result := '';
end;

function TAdapterFormLayout.EndRow: string;
begin
  if FInRow then
  begin
    Result := FieldIndent + '</tr>'#13#10;  { do not localize }
    FColumnIndex := 0;
    FInRow := False;
  end
  else
    Result := '';
end;

function TAdapterFormLayout.EndTable: string;
begin
  if FInTable then
  begin
    Result := EndRow + TableIndent + '</table>'#13#10;   { do not localize }
    Dec(FTableLevel);
    FInTable := False;
  end
  else
    Result := '';
end;

function TAdapterFormLayout.EndLayout: string;
begin
  Result := EndFields + EndButtons + EndTable;
end;

function TAdapterFormLayout.StartTable: string;
begin
  if not FInTable then
  begin
    FInTable := True;
    Inc(FTableLevel);
    Result := TableIndent + FTableHeader + #13#10;
  end
  else
    Result := '';
end;

function TAdapterFormLayout.StartButtons: string;
begin
  if FLayoutState <> lsButtons then
    FButtonIndex := 0;
  Result := EndFields;
  FLayoutState := lsButtons;
  Result := Result + StartTable + StartRow + NextColumn(1);
end;

function TAdapterFormLayout.EndButtons: string;
begin
  Result := '';
  if FLayoutState = lsButtons then
  begin
    if not FBreakButtons then
      Result := EndRow;
    FLayoutState := lsUnknown;
  end;
end;

function TAdapterFormLayout.EndFields: string;
begin
  Result := '';
  if FLayoutState = lsFields then
  begin
    if not FBreakButtons then
      Result := EndRow;
    Dec(FFieldLevel);
    FLayoutState := lsUnknown;
  end;
end;

const
  IndentField = 2;

function TAdapterFormLayout.GetFieldIndent: string;
var
  I: Integer;
begin
  I := FFieldLevel;
  if FLayoutState <> lsFields then
    Inc(I);
  I := I * IndentField + Length(FParentIndent);
  if FInTable then I := I + (Length(TableIndent) - Length(FParentIndent));
  if Length(FFieldIndent) <> I then
  begin
    SetLength(FFieldIndent, I);
    FillChar(FFieldIndent[1], I, ' ');
  end;
  Result := FFieldIndent;
end;

const
  IndentTable = 2;

function TAdapterFormLayout.GetTableIndent: string;
var
  I: Integer;
begin
  I := FTableLevel;
  if not FInTable then
    Inc(I);

  I := I * IndentTable + Length(FParentIndent);
  if Length(FTableIndent) <> I then
  begin
    SetLength(FTableIndent, I);
    FillChar(FTableIndent[1], I, ' ');
  end;
  Result := FTableIndent;
end;

function TAdapterFormLayout.GetChildTableIndent: string;
begin
  Inc(FFieldLevel);
  try
    Result := FieldIndent;
  finally
    Dec(FFieldLevel);
  end;
end;

{ TCustomAdapterForm }

function TCustomAdapterForm.GetHTMLFormTag(Options: TWebContentOptions): string;
var
  Attribs: string;
begin
  AddQuotedAttrib(Attribs, sNameAttr, GetHTMLFormName);
  if GetControlRequirements.NeedMultipartForm then
    AddQuotedAttrib(Attribs, sEncTypeAttr, sMultipartForm);
  case FormMethod of
    fmGet:
      AddQuotedAttrib(Attribs, sMethodAttr, sFormGet);
    fmPost:
      AddQuotedAttrib(Attribs, sMethodAttr, sFormPost);
  else
    Assert(False);  // Unknown type
  end;
  if (WebContext <> nil) and (WebContext.Request <> nil) then
    AddQuotedAttrib(Attribs, sActionAttr,
      WebContext.Request.InternalScriptName +
      WebContext.Request.InternalPathInfo);
  Result :=
    Format('<form%s>', [Attribs]);   { do not localize }
end;

function TCustomAdapterForm.FormatForm(ParentLayout: TLayout;
  Options: TWebContentOptions): string;
  function FormatField(Field: TComponent): string;
  var
    Intf: IWebContent;
  begin
    if Supports(IInterface(Field), IWebContent, Intf) then
      Result := Intf.Content(Options, FFormLayout)
    else
      Result := '';
  end;

  function FormatActionField: string;
  begin
    Result := Format('<input ' + sTypeAttr + '="hidden" ' + sNameAttr + '="%s">'#13#10, [sActionRequest]);  { do not localize }
  end;

var
  I: Integer;
  Intf: ILayoutWebContent;
  A: TLayoutAttributes;
begin
  FFormLayout := TAdapterFormLayout.Create(ParentLayout);
  try
    FFormLayout.TableHeader := Format('<table%s>', [GetLayoutAttributes.ControlAttributes]);  { do not localize }
    Result := GetHTMLFormTag(Options);
    Result := Result + #13#10 + FFormLayout.FieldIndent +
      FormatActionField;
    for I := 0 to WebFieldControls.Count - 1 do
      Result := Result + FormatField(WebFieldControls[I]);
    Result := Result + FFormLayout.EndLayout;
    Result := Result + '</form>';  { do not localize }
    if Supports(ParentLayout, ILayoutWebContent, Intf) then
      if ParentLayout is TAdapterFormLayout then
      begin
        Result := Intf.LayoutField(Result, nil)
      end
      else
      begin
        A := TLayoutAttributes.Create;
        try
          with A do
          begin
            AddQuotedAttrib(ControlAttributes, sAlignAttr, HTMLAlignValues[haCenter]);
            AddQuotedAttrib(ControlAttributes, sVAlignAttr, HTMLVAlignValues[haTop]);
          end;
          Result := Intf.LayoutField(Result, A)
        finally
          A.Free;
        end;
      end
  finally
    FreeAndNil(FFormLayout);
  end;
  FreeAndNil(FControlRequirements);

end;

function TCustomAdapterForm.ImplCanAddClass(AParent: TComponent;
  AClass: TClass): Boolean;
begin
  Result := AClass.InheritsFrom(TCustomAdapterGrid) or
    AClass.InheritsFrom(TCustomAdapterFieldGroup) or
    AClass.InheritsFrom(TCustomAdapterCommandGroup) or
    AClass.InheritsFrom(TCustomAdapterErrorList) or
    AClass.InheritsFrom(TCustomLayoutGroup) or
    CanAddClassHelper(Self, AParent, AClass);
end;

function TCustomAdapterForm.ImplContent(
  Options: TWebContentOptions; ParentLayout: TLayout): string;
begin
  Result := FormatForm(ParentLayout, Options);
end;

function TCustomAdapterForm.GetLayoutAttributes: TLayoutAttributes;
begin
  with FLayoutAttributes do
  begin
    ControlAttributes := '';
    AddQuotedAttrib(ControlAttributes, sStyleAttr, Style);
    AddQuotedAttrib(ControlAttributes, sClassAttr, StyleRule);
    AddCustomAttrib(ControlAttributes, Custom);
  end;
  Result := FLayoutAttributes;
end;

constructor TCustomAdapterForm.Create(AOwner: TComponent);
begin
  inherited;
  FLayoutAttributes := TLayoutAttributes.Create;
  FFormMethod := fmPost;
end;

destructor TCustomAdapterForm.Destroy;
begin
  inherited;
  FLayoutAttributes.Free;
  FControlRequirements.Free;
end;

{ TCustomAdapterFieldGroup }

function TCustomAdapterFieldGroup.FormatFields(ParentLayout: TLayout;
  Options: TWebContentOptions): string;

  function FormatField(Field: TComponent): string;
  var
    Intf: IWebContent;
  begin
    if Supports(IInterface(Field), IWebContent, Intf) then
      Result := Intf.Content(Options, FFormLayout)
    else
      Result := '';
  end;

  function FormatHiddenFields(const AdapterVarName: string): string;
  begin
    if AdapterVarName <> '' then
    begin
      Result := Format(sWriteHiddenFields, [AdapterVarName, sHiddenFields, '']) +
      Format(sWriteHiddenFields, [AdapterVarName, sHiddenRecordFields, '']);
    end;
  end;
var
  I: Integer;
  Intf: ILayoutWebContent;
  VarName: string;
  A: TLayoutAttributes;
begin
  FFormLayout := TAdapterFormLayout.Create(ParentLayout);
  try
    FFormLayout.TableHeader := Format('<table%s>', [GetLayoutAttributes.ControlAttributes]);  { do not localize }
    Result := '';
    for I := 0 to VisibleFields.Count - 1 do
      Result := Result + FormatField(VisibleFields[I]);
    VarName := MakeAdapterVariableName(Self);
    Result := Result + FFormLayout.EndLayout;
    if Supports(ParentLayout, ILayoutWebContent, Intf) then
      if ParentLayout is TAdapterFormLayout then
        Result := Intf.LayoutTable(Result, nil)
      else
      begin
        A := TLayoutAttributes.Create;
        try
          with A do
          begin
            AddQuotedAttrib(ControlAttributes, sAlignAttr, HTMLAlignValues[haCenter]);
            AddQuotedAttrib(ControlAttributes, sVAlignAttr, HTMLVAlignValues[haTop]);
            // Work better with a layout group
            Result := Intf.LayoutTable(#13#10 + Result, A);
          end
        finally
          A.Free;
        end;
      end;
    Result := Result + FormatHiddenFields(VarName);
  finally
    FreeAndNil(FFormLayout);
  end;
end;

function TCustomAdapterFieldGroup.ImplCanAddClass(AParent: TComponent;
  AClass: TClass): Boolean;
begin
  Result := ((AClass.InheritsFrom(TAdapterDataDisplay)
    and not TAdapterDataDisplayClass(AClass).IsColumn)) or
    AClass.InheritsFrom(TCustomLayoutGroup) or
    CanAddClassHelper(Self, AParent, AClass);
end;

function TCustomAdapterFieldGroup.ImplContent(
  Options: TWebContentOptions; ParentLayout: TLayout): string;
begin
  Result := FormatFields(ParentLayout, Options);
  if (Adapter <> nil) and (AdapterMode <> '') then
    Result := Format(sSetAdapterMode,
                     [MakeAdapterVariableName(Self), AdapterMode, Result]);
end;

function TCustomAdapterFieldGroup.GetLayoutAttributes: TLayoutAttributes;
begin
  with FLayoutAttributes do
  begin
    ControlAttributes := '';
    AddQuotedAttrib(ControlAttributes, sStyleAttr, Style);
    AddQuotedAttrib(ControlAttributes, sClassAttr, StyleRule);
    AddCustomAttrib(ControlAttributes, Custom);
  end;
  Result := FLayoutAttributes;
end;

constructor TCustomAdapterFieldGroup.Create(AOwner: TComponent);
begin
  inherited;
  FLayoutAttributes := TLayoutAttributes.Create;
end;

destructor TCustomAdapterFieldGroup.Destroy;
begin
  inherited;
  FLayoutAttributes.Free;
end;

function TCustomAdapterFieldGroup.GetAdapterDisplayCharacteristics: TAdapterDisplayCharacteristics;
begin
  Result := [{dcMultipleRecordView } dcCurrentRecordView,
    dcChangeCurrentRecordView ];
end;

function TCustomAdapterFieldGroup.GetAddAllFieldsItem: string;
begin
  Result := sAddAllFieldItems;
end;

function TCustomAdapterFieldGroup.GetAddFieldsDlgCaption: string;
begin
  Result := sAddFieldItemsDlgCaption;
end;

function TCustomAdapterFieldGroup.GetAddFieldsItem: string;
begin
  Result := sAddFieldItems;
end;

function TCustomAdapterFieldGroup.GetAdapterFormLayout: TAdapterFormLayout;
begin
  Result := FFormLayout;
end;

const
  sAdapterFormItemPrefix = 'Fld'; // Do not location
function TCustomAdapterFieldGroup.GetNewFieldPrefix: string;
begin
  Result := sAdapterFormItemPrefix;
end;

function TCustomAdapterForm.GetHTMLFormName: string;
begin
  Result := Self.Name;
end;

function TCustomAdapterForm.GetHTMLFormVarName: string;
begin
  Result := Self.Name;
end;

procedure TCustomAdapterForm.GetFormRequirements(
  ARequirements: TAbstractFormRequirements);
var
  I: Integer;
begin
  GetControlRequirements;
  with FControlRequirements do
  begin
    for I := 0 to FVariables.Count - 1 do
      if not ARequirements.IsVariableDefined(FVariables.Names[I]) then
        ARequirements.DefineVariable(FVariables.Names[I], ExtractStringValue(FVariables[I]));
    for I := 0 to FGeneratedFunctions.ItemCount - 1 do
      if not ARequirements.IsFunctionDefined(FGeneratedFunctions.Names[I]) then
        ARequirements.DefineFunction(FGeneratedFunctions.Names[I],
          FGeneratedFunctions.Script[I])
  end;
end;

function TCustomAdapterForm.GetControlRequirements: TControlRequirements;

  procedure GetRequirements(Components: IWebComponentContainer);
  var
    I: Integer;
    Obj: TObject;
    GetIntf: IGetControlRequirements;
    WebDataFields: IWebDataFields;
    WebActionsList: IWebActionsList;
    GetWebComponentList: IGetWebComponentList;
    Container: IWebComponentContainer;
  begin
    If Assigned(Components) then
    for I := 0 to Components.ComponentCount - 1 do
    begin
      Obj := Components.Components[I];
      if Supports(Obj, IGetControlRequirements, GetIntf) then
        GetIntf.GetControlRequirements(FControlRequirements);
      if Supports(Obj, IWebDataFields, WebDataFields) then
        GetRequirements(WebDataFields.GetVisibleFields)
      else if Supports(Obj, IWebActionsList, WebActionsList) then
        GetRequirements(WebActionsList.GetVisibleActions)
      else if Supports(Obj, IGetWebComponentList, GetWebComponentList) then
      begin
        Supports(GetWebComponentList.GetComponentList, IWebComponentContainer,
          Container);
        GetRequirements(Container);
      end;
    end;
  end;

begin
  if FControlRequirements = nil then
  begin
    FControlRequirements := TControlRequirements.Create;
    GetRequirements(WebFieldControls);
  end;
  Result := FControlRequirements;
end;

function TCustomAdapterForm.GetAdapterFormLayout: TAdapterFormLayout;
begin
  Result := FFormLayout;
end;

{ TCustomAdapterDisplayField }
procedure TCustomAdapterDisplayField.AddAttributes(var Attrs: string);
begin
  AddIntAttrib(Attrs, sTabIndexAttr, TabIndex);
  AddQuotedAttrib(Attrs, sStyleAttr, Style);
  AddQuotedAttrib(Attrs, sClassAttr, StyleRule);
  AddCustomAttrib(Attrs, Custom);
end;

function TCustomAdapterDisplayField.FormatListDisplay(const VarName, HTMLName: string): string;
var
  Attrs: string;
begin
  AddAttributes(Attrs);
  Result := Format('<%% obj=%0:s%1:s%%>',  { do not localize }
    [sListValuesFunctionName,
      Format(sListValuesFunctionParameters, [VarName])]);
  Result := Result + Format('<ul %0:s>'#13#10'%1:s</ul>',  { do not localize }
                   [Attrs,
                   '<%=obj.text%>']);  { do not localize }
end;

function TCustomAdapterDisplayField.FormatTextDisplay(const VarName, HTMLName: string): string;
var
  Attrs: string;
begin
  AddAttributes(Attrs);
  { Value is not encoded. So embedded quotes, '>', '<', may not work properly with some HTML elements }
  Result := Format('%0:s ',
                   [Format(sDisplayText, [VarName])]);
  if Attrs <> '' then
    Result := Format('<span%s>%s</span>', [Attrs, Result]);  { do not localize }
end;

function TCustomAdapterDisplayField.FormatTextInput(const VarName, HTMLName: string): string;
var
  Attrs: string;
begin
  AddAttributes(Attrs);
  AddIntAttrib(Attrs, sSizeAttr, DisplayWidth);
  AddIntAttrib(Attrs, sMaxLengthAttr, MaxLength);
  { Value is not encoded. So embedded quotes, '>', '<', may not work properly with some HTML elements }
  Result := Format('<input ' + sTypeAttr + '="text"%0:s ' + sNameAttr + '="<%%=%2:s%%>" ' + sValueAttr + '="%1:s" >',  { do not localize }
                   [Attrs, Format(sFieldText, [VarName]),
                   HTMLName]);
end;

function TCustomAdapterDisplayField.FormatFileInput(const VarName, HTMLName: string): string;
var
  Attrs: string;
begin
  AddAttributes(Attrs);
  AddIntAttrib(Attrs, sSizeAttr, DisplayWidth);
  { Value is not encoded. So embedded quotes, '>', '<', may not work properly with some HTML elements }
  Result := Format('<input ' + sTypeAttr + '="file"%0:s ' + sNameAttr + '="<%%=%1:s%%>">',  { do not localize }
                   [Attrs,
                   HTMLName]);
end;

function TCustomAdapterDisplayField.FormatTextArea(const VarName, HTMLName: string): string;
var
  Attrs: string;
begin
  AddAttributes(Attrs);
  AddIntAttrib(Attrs, sColsAttr, DisplayWidth);
  AddIntAttrib(Attrs, sRowsAttr, DisplayRows);
  AddStringAttrib(Attrs, sWrapAttr, MidItems.TextAreaWrap[TextAreaWrap]);
  { Value is not encoded. So embedded quotes, '>', '<', may not work properly with some HTML elements }
  Result := Format('<textarea%0:s ' + sNameAttr + '="<%%=%2:s%%>">%1:s</textarea>',  { do not localize }
                   [Attrs, Format(sFieldText, [VarName]),
                   HTMLName]);
end;

function TCustomAdapterDisplayField.FormatPasswordInput(const VarName, HTMLName: string): string;
var
  Attrs: string;
begin
  AddAttributes(Attrs);
  AddIntAttrib(Attrs, sSizeAttr, DisplayWidth);
  AddIntAttrib(Attrs, sMaxLengthAttr, MaxLength);
  { Value is not encoded. So embedded quotes, '>', '<', may not work properly with some HTML elements }
  Result := Format('<input ' + sTypeAttr + '="password"%0:s ' + sNameAttr + '="<%%=%2:s%%>" ' + sValueAttr + '="%1:s" >', { do not localize }
                   [Attrs, Format(sFieldText, [VarName]),
                   HTMLName])
end;


function SelOptionsFunction(AComponent: TComponent): string;
begin
  Result := Format('<%%'#13#10 + sSelOptionsFunction + '%%>', [sSelOptionsFunctionName]);
end;

function ListValuesFunction(AComponent: TComponent): string;
begin
  Result := Format('<%%'#13#10 + sListValuesFunction + '%%>', [sListValuesFunctionName]);
end;

function RadioGroupFunction(AComponent: TComponent): string;
begin
  Result := Format('<%%'#13#10 + sInputGroupFunction + '%%>', [sRadioGroupFunctionName, 'radio']);  { do not localize }
end;

function CheckBoxGroupFunction(AComponent: TComponent): string;
begin
  Result := Format('<%%'#13#10 + sInputGroupFunction + '%%>', [sCheckBoxGroupFunctionName, 'checkbox']);  { do not localize }
end;

procedure TCustomAdapterDisplayField.ImplGetControlRequirements(ARequirements: TAbstractControlRequirements);
var
  T: TInputFieldHTMLElementType;
  D: TDisplayFieldHTMLElementType;
begin
  inherited ImplGetControlRequirements(ARequirements);
  if CalcInputElementType(T) then
  case T of
    iftSelect,
    iftSelectMultiple:
      if not ARequirements.IsFunctionDefined(sSelOptionsFunctionName) then
        ARequirements.DefineFunction(sSelOptionsFunctionName,
          SelOptionsFunction(Self));
    iftRadio:
      if not ARequirements.IsFunctionDefined(sRadioGroupFunctionName) then
        ARequirements.DefineFunction(sRadioGroupFunctionName,
          RadioGroupFunction(Self));
    iftCheckBox:
      if not ARequirements.IsFunctionDefined(sCheckBoxGroupFunctionName) then
        ARequirements.DefineFunction(sCheckBoxGroupFunctionName,
          CheckBoxGroupFunction(Self));
    iftFile:
      ARequirements.RequiresMultipartForm;
  end;
  if CalcDisplayElementType(D) then
  case D of
    dftList:
      if not ARequirements.IsFunctionDefined(sListValuesFunctionName) then
        ARequirements.DefineFunction(sListValuesFunctionName,
          ListValuesFunction(Self));
  end;
end;

function TCustomAdapterDisplayField.FormatSelect(const VarName, HTMLName: string; Multiple: Boolean): string;
var
  Attrs: string;
  SizeAttr: string;
begin
  AddAttributes(Attrs);
  AddBoolAttrib(Attrs, sMultipleAttr, Multiple);
  Result := Format('<%% obj=%0:s%1:s%%>',
    [sSelOptionsFunctionName,
      Format(sSelOptionsFunctionParameters, [VarName])]);
  { Value is not encoded. So embedded quotes, '>', '<', may not work properly with some HTML elements }
  if SelectRows <> -1 then
    SizeAttr := IntToStr(SelectRows)
  else
    SizeAttr := '<%%=obj.count%%>';  { do not localize }
  Result := Result + Format('<select ' + sSizeAttr + '="' + SizeAttr + '" ' + sNameAttr + '="<%%=%1:s%%>"%0:s>%2:s</select>',  { do not localize }
                   [Attrs,
                   HTMLName, '<%=obj.text%>']);  { do not localize }
end;

function TCustomAdapterDisplayField.FormatInputGroup(const FunctionName, VarName, HTMLName: string;
  DisplayColumns: Integer): string;
var
  Attrs: string;
begin
  AddAttributes(Attrs);
  Result := Format('<%% obj=%0:s%1:s%%>',  { do not localize }
    [FunctionName,
      Format(sInputGroupFunctionParameters, [VarName, HTMLName, DisplayColumns, Attrs])]);
  { Value is not encoded. So embedded quotes, '>', '<', may not work properly with some HTML elements }
  Result := Result + '<%=obj.text%>';  { do not localize }
end;

function TCustomAdapterDisplayField.FormatCheckBoxGroup(const VarName, HTMLName: string): string;
begin
  Result := FormatInputGroup(sCheckBoxGroupFunctionName,
    VarName, HTMLName, DisplayColumns);
end;

function TCustomAdapterDisplayField.FormatRadioGroup(const VarName, HTMLName: string): string;
begin
  Result := FormatInputGroup(sRadioGroupFunctionName,
    VarName, HTMLName, DisplayColumns);
end;

function TCustomAdapterDisplayField.CalcInputElementType(var AType: TInputFieldHTMLElementType): Boolean;
  function ConvertInputType(T: TAdapterInputHTMLElementType): TInputFieldHTMLElementType;
  begin
    case T of
      htmliTextInput: Result := iftTextInput;
      htmliPasswordInput:  Result := iftPasswordInput;
      htmliSelect:         Result := iftSelect;
      htmliSelectMultiple: Result := iftSelectMultiple;
      htmliRadio:          Result := iftRadio;
      htmliCheckBox:       Result := iftCheckBox;
      htmliTextArea:       Result := iftTextArea;
      htmliFile:            Result := iftFile;
    else
      Result := iftTextInput;
      Assert(False, 'unexpected type');
    end;
  end;
var
  Field: TComponent;
  AdapterInputType: TAdapterInputHTMLElementType;
begin
  if InputType = iftDefault then
  begin
    AType := iftTextInput;
    Result := True;
    Field := FindAssociatedField;
    if Field <> nil then
    begin
      AdapterInputType := CalcDefaultAdapterInputElementType(Field, GetAdapterModeOfAdapter);
      if AdapterInputType <> htmliNone then
      begin
        AType := ConvertInputType(AdapterInputType);
        Result := True;
      end
      else
        Result := False;
    end;
  end
  else
  begin
    AType := InputType;
    Result := True;
  end;
end;

function TCustomAdapterDisplayField.CalcDisplayFieldViewMode(var AMode: TDisplayFieldViewMode): Boolean;
begin
  if ViewMode = vmDefault then
    Result := WebForm.CalcDisplayFieldViewMode(FindAssociatedField, GetAdapterModeOfAdapter, ViewMode, AMode)
  else
  begin
    AMode := ViewMode;
    Result := True;
  end;
end;

function TCustomAdapterDisplayField.CalcDisplayElementType(var AType: TDisplayFieldHTMLElementType): Boolean;
begin
  if DisplayType = dftDefault then
    Result := CalcDisplayFieldHTMLElementType(FindAssociatedField, GetAdapterModeOfAdapter, DisplayType, AType)
  else
  begin
    AType := DisplayType;
    Result := True;
  end;
end;

function TCustomAdapterDisplayField.GetLayoutAttributes: TLayoutAttributes;
begin
  Result := inherited GetLayoutAttributes;
  with Result do
  begin
    ControlAttributes := '';
    AddQuotedAttrib(ControlAttributes, sAlignAttr, HTMLAlignValues[Align]);
    AddQuotedAttrib(ControlAttributes, sVAlignAttr, HTMLVAlignValues[VAlign]);
  end;
end;

function TCustomAdapterDisplayField.ImplContent(Options: TWebContentOptions;
  ParentLayout: TLayout): string;
var
  Intf: ILayoutWebContent;
  S, T, C: string;
  GetAdapterFormLayout: IGetAdapterFormLayout;
begin
  C := ControlContent(Options);
  if C <> '' then
  begin
    S := FieldConditions(Options);
    if S <> '' then
      if Supports(ParentLayout, IGetAdapterFormLayout, GetAdapterFormLayout) then
        with GetAdapterFormLayout.GetAdapterFormLayout do
          T := StartTable + EndField;

    if Supports(ParentLayout, ILayoutWebContent, Intf) then
      Result := Intf.LayoutLabelAndField(LabelContent, C,
        GetLayoutAttributes)
    else
      Result := LabelContent + C;

    if S <> '' then
      if GetAdapterFormLayout <> nil then
        Result := Result + GetAdapterFormLayout.GetAdapterFormLayout.EndField;
    if S <> '' then
      Result := Format(S, [Result]);
    Result := T + Result;
  end
  else
    Result := '';
end;

function TCustomAdapterDisplayField.ControlContent(
  Options: TWebContentOptions): string;
var
  VarName: string;
  HTMLName: string;

  function FormatInputControl(AType: TInputFieldHTMLElementType): string;
  begin
    case AType of
      iftPasswordInput:
        Result := FormatPasswordInput(VarName, HTMLName);
      iftTextInput:
        Result := FormatTextInput(VarName, HTMLName);
      iftSelect:
        Result := FormatSelect(VarName, HTMLName, False);
      iftSelectMultiple:
        Result := FormatSelect(VarName, HTMLName, True);
      iftRadio:
        Result := FormatRadioGroup(VarName, HTMLName);
      iftCheckBox:
        Result := FormatCheckBoxGroup(VarName, HTMLName);
      iftTextArea:
        Result := FormatTextArea(VarName, HTMLName);
      iftFile:
        Result := FormatFileInput(VarName, HTMLName);
    else
      Assert(False);
    end
  end;

  function FormatDisplayControl(AType: TDisplayFieldHTMLElementType): string;
  begin
    case AType of
      dftImage:
        Result := FormatImage(VarName, HTMLName, Options);
      dftText:
        Result := FormatTextDisplay(VarName, HTMLName);
      dftList:
        Result := FormatListDisplay(VarName, HTMLName);
    else
      Assert(False);
    end;
  end;

  function FormatToggleOnAccess: string;
  var
    DControl, IControl: string;
    I: TInputFieldHTMLElementType;
    D: TDisplayFieldHTMLElementType;
  begin
    if CalcInputElementType(I) then
      IControl := FormatInputControl(I);
    if CalcDisplayElementType(D) then
      DControl := FormatDisplayControl(D);
    Result := Format(sAccessBased, [VarName, IControl, DControl, FieldIndent(Self)]);
  end;

var
  I: TInputFieldHTMLElementType;
  D: TDisplayFieldHTMLElementType;
  M: TDisplayFieldViewMode;
begin
  if hoHideAlways in HideOptions then
  begin
    Result := '';
    Exit;
  end;
  VarName := MakeAdapterVariableName(Self);
  Result := '';
  if VarName <> '' then
  begin
    HTMLName := MakeAdapterHTMLName(VarName);
    if CalcDisplayFieldViewMode(M) then
    case M of
      vmInput:
        if CalcInputElementType(I) then
          Result := FormatInputControl(I)
        else if CalcDisplayElementType(D) then
          Result := FormatDisplayControl(D);
      vmDisplay:
        if CalcDisplayElementType(D) then
          Result := FormatDisplayControl(D);
      vmToggleOnAccess:
        Result := FormatToggleOnAccess;
    else
      Assert(False);
    end;
  end
  else
    Result := ' ';  // Single blank to show label
end;

constructor TCustomAdapterDisplayField.Create(AOwner: TComponent);
begin
  inherited;
  FDisplayWidth := -1;
  FImageWidth := -1;
  FImageHeight := -1;
  FSelectRows := 0;
  FMaxLength := -1;
  FDisplayRows := -1;
  FDisplayColumns := 1;
end;

procedure TCustomAdapterDisplayField.ImplRestoreDefaults;
var
  Field: TComponent;
  WebGetDisplayWidth: IWebGetDisplayWidth;
  WebGetDisplayLabel: IWebGetDisplayLabel;
  WebMaxLength: IWebGetMaxLength;
begin
  inherited;
  Field := FindAssociatedField;
  if Field <> nil then
  begin
    if Supports(IUnknown(Field), IWebGetDisplayWidth, WebGetDisplayWidth) then
      FDisplayWidth := WebGetDisplayWidth.GetDisplayWidth;
    if Supports(IUnknown(Field), IWebGetDisplayLabel, WebGetDisplayLabel) then
      SetCaption(WebGetDisplayLabel.GetDisplayLabel);
    if Supports(IUnknown(Field), IWebGetMaxLength, WebMaxLength) then
      FMaxLength := WebMaxLength.GetMaxLength;
  end;
end;

class function TCustomAdapterDisplayColumn.IsColumn: Boolean;
begin
  Result := True;
end;

function TCustomAdapterDisplayField.FormatImage(const VarName, HTMLName: string; Options: TWebContentOptions): string;
var
  Attrs: string;
  HREF: string;
begin
  AddAttributes(Attrs);
  AddIntAttrib(Attrs, 'width', ImageWidth);  { do not localize }
  AddIntAttrib(Attrs, 'height', ImageHeight);  { do not localize }
  HREF := Format('<%%=(%0:s.Image!=null)?%0:s.Image.AsHREF:''''%%>', [VarName]);  { do not localize }
  Result := Format('<img src="%0:s"%2:s alt="<%%=%1:s.DisplayText%%>">', [HREF, VarName,  { do not localize }
    Attrs]);
end;

{ TCustomAdapterActionButton }

function TCustomAdapterActionButton.GetActionName: string;
begin
  Result := FActionName;
end;

function TCustomAdapterActionButton.GetCaption: string;
begin
  if inherited GetCaption = '' then
  begin
    Result := FActionName;
    if Result = '' then
      Result := Name;
  end
  else
    Result := inherited GetCaption;
end;

procedure TCustomAdapterActionButton.SetCaption(const Value: string);
begin
  if FActionName <> '' then
    if Value = FActionName then inherited SetCaption('') else inherited SetCaption(Value)
  else
    if Value = Name then inherited SetCaption('') else inherited SetCaption(Value)
end;

function TCustomAdapterActionButton.GetHTMLFormVarName: string;
var
  Component: TComponent;
  HTMLForm: IHTMLForm;
begin
  Component := GetParentComponent;
  while Assigned(Component) and not Supports(IUnknown(Component), IHTMLForm, HTMLForm) do
    Component := Component.GetParentComponent;
  if Assigned(Component) then
    Result := HTMLForm.HTMLFormVarName
  else
  begin
    Assert(False, 'Form not found');
    Result := '';
  end;
end;

const
  // 0 - varname
  // 1 - html elements when enabled
  // 2 - html elements when not enabled
  // 3 - Indent
  sIfEnabledElse =    '<%% if (%0:s.Enabled)'#13#10 +
                       '   { %%>'#13#10 +
                       '%3:s%1:s'#13#10 +
                      '<%% }'#13#10 +
                       '   else'#13#10 +
                       '   { %%>'#13#10 +
                       '%3:s%2:s'#13#10 +
                      '<%% } %%>'#13#10;

function TCustomAdapterActionButton.ImplContent(Options: TWebContentOptions; ParentLayout: TLayout): string;
var
  Condition: string;

  function ConvertDisplayType(T: TAdapterActionHTMLElementType): TCommandHTMLElementType;
  begin
    case T of
      htmlaButton:  Result := ctButton;
      htmlaImage: Result := ctImage;
      htmlaAnchor: Result := ctAnchor;
      htmlaEventImages: Result := ctEventImages;
    else
      Result := ctButton;
      Assert(False, 'unexpected type');
    end;
  end;

  function ActionFieldValue(const VarName: string): string;
  var
    LinkToPage: string;
    LinkToErrorPage: string;
  begin
    if Trim(FPageName) = '' then
      LinkToPage := 'Page.Name'  { do not localize }
    else
      LinkToPage := Format('"%s"', [FPageName]);
    if Trim(FErrorPageName) = '' then
      LinkToErrorPage := 'Page.Name'  { do not localize }
    else
      LinkToErrorPage := Format('"%s"', [FErrorPageName]);
    Result :=
       Format('<%%=%0:s.LinkToPage(%1:s, %2:s).AsFieldValue%%>', [VarName,  { do not localize }
         LinkToPage, LinkToErrorPage])
  end;

  function AnchorClickEvent(const VarName: string): string;
  begin
    if not (coNoScript in Options.Flags) then
      Result := Format('%0:s.%1:s.value=''%2:s'';%0:s.submit();return false;', [  { do not localize }
             GetHTMLFormVarName, sActionRequest,
             ActionFieldValue(VarName)])
    else
      Result := 'return false';  { do not localize }
  end;


  function FormatList(const VarName, HTMLElement, Indent: string): string;
  begin
    // 0 - varname
    // 1 - display columns
    // 2 - html element
    // 3 - Indent
    Result := Format(
  '<%% if (%0:s.Array != null)'#13#10 +                                         { do not localize }
   '   {'#13#10 +                                                               { do not localize }
   '     var c=0'#13#10 +                                                       { do not localize }
   '     var cols=%1:d %%>'#13#10 +                                             { do not localize }
   '%3:s<table><tr>'#13#10 +                                                    { do not localize }
  '<%%   var e = new Enumerator(%0:s.Array)'#13#10 +                            { do not localize }
   '     for (; !e.atEnd(); e.moveNext())'#13#10 +                              { do not localize }
   '     {'#13#10 +                                                             { do not localize }
   '       if (cols > 0 && c %% cols == 0 && c != 0)'#13#10 +                   { do not localize }
   '       { %%>'#13#10 +                                                       { do not localize }
   '%3:s  </tr><tr>'#13#10 +                                                    { do not localize }
  '<%%     } %%>'#13#10 +                                                       { do not localize }
   '%3:s  <td>'#13#10 +                                                         { do not localize }
   '%3:s  %2:s'#13#10 +                                                         { do not localize }
   '%3:s  </td>'#13#10 +                                                        { do not localize }
  '<%%     c++'#13#10 +                                                         { do not localize }
   '     } '#13#10 +                                                            { do not localize }
   '     e.moveFirst() %%>'#13#10 +                                             { do not localize }
   '%3:s</tr></table>'#13#10 +                                                  { do not localize }
  '<%% } %%>'#13#10, [VarName, DisplayColumns, HTMLElement, Indent]);           { do not localize }
  end;

  function FormAction: string;
  begin
    if WebContext.Request <> nil then
      Result :=
        WebContext.Request.InternalScriptName +
       WebContext.Request.InternalPathInfo
    else
      Result := '';

  end;

  function FormatImageEvent(const Event, VarName, ImageName, ProducerVarName, Text, Indent: string): string;
  begin
    Result := Format(
  '<%%   {'#13#10 +                                                             { do not localize }
   '     var Image'#13#10 +                                                     { do not localize }
   '     Image = %0:s.GetEventImage(%1:s,''%3:s'', %4:s)'#13#10 +               { do not localize }
   '     if (Image != null)'#13#10 +                                            { do not localize }
   '     { %%>'#13#10 +                                                         { do not localize }
   '%5:s%3:s="if (document.images) document.images.%2:s.src=''<%%= Image.AsHREF %%>''"'#13#10 +  { do not localize }
  '<%%   }'#13#10 +                                                             { do not localize }
   '     } %%>'#13#10, [ProducerVarName, VarName, ImageName, Event, Text, Indent]);  { do not localize }
  end;

  function FormatImageEvents(const ProducerVarName, VarName, ImageName, Text, Indent: string): string;
  begin
    Result := ' ';
    Result := Result + FormatImageEvent('onmousedown', VarName, ImageName, ProducerVarName, Text, Indent);  { do not localize }
    Result := Result + FormatImageEvent('onmouseover', VarName, ImageName, ProducerVarName, Text, Indent);  { do not localize }
    Result := Result + FormatImageEvent('onmouseout', VarName, ImageName, ProducerVarName, Text, Indent);   { do not localize }
    if Result = ' ' then
      Result := '';
  end;

  function InMultirecordView: Boolean;
  var
    Intf: IGetAdapterDisplayCharacteristics;
    Component: TComponent;
  begin
    Component := Self;
    while Assigned(Component) do
    begin
      if Supports(IInterface(Component), IGetAdapterDisplayCharacteristics, Intf) then
      begin
        Result := dcMultipleRecordView in Intf.GetAdapterDisplayCharacteristics;
        Exit;
      end;
      Component := Component.GetParentComponent;
    end;
    Result := False
  end;

  function FormatImage(Action: TComponent; const VarName: string; IsList, UseEvents: Boolean): string;
  var
    Attrs: string;
    HREF: string;
    Text: string;
    ImageName: string;
    ProducerVarName: string;
    Events: string;
    WebVariableName: IWebVariableName;
    Suffix: string;
  begin
    AddQuotedAttrib(Attrs, sStyleAttr, Style);
    AddQuotedAttrib(Attrs, sClassAttr, StyleRule);
    AddCustomAttrib(Attrs, Custom);
    AddIntAttrib(Attrs, 'width', ImageWidth);  { do not localize }
    AddIntAttrib(Attrs, 'height', ImageHeight);  { do not localize }
    if ImageProducer <> nil then
    begin
      ProducerVarName := GetImageProducerVariableName;
      if IsList then
        Text := Format('%0:s.DisplayLabel', [VarName])  { do not localize }
      else
        Text := Format('''%s''', [Self.Caption]);
      HREF := Format('<%%=(%1:s.GetImage(%0:s, %2:s)!=null)?%1:s.GetImage(%0:s, %2:s).AsHREF:''''%%>', [VarName, ProducerVarName,  { do not localize }
        Text]);
      if UseEvents then
      begin
        if Supports(IUnknown(Action), IWebVariableName, WebVariableName) then
        begin
          ImageName := WebVariableName.VariableName;
          Suffix := '';
          if IsList then
            Suffix := Suffix + '+ ''_'' + c';  { do not localize }
          if InMultirecordView then
            Suffix := Suffix + '+ ''_'' + ri';  { do not localize }
          if Suffix <> '' then
            ImageName := Format('<%%= ''%0:s'' %1:s %%>', [ImageName, Suffix]);
        end;

        Events := FormatImageEvents(ProducerVarName, VarName, ImageName, Text, ChildTableIndent(Self));
        if Events <> '' then
          Events := #13#10 + Events + ChildTableIndent(Self);
        AddQuotedAttrib(Attrs, 'name', ImageName);  { do not localize }
      end;
    end;
    if IsList then
      Text := Format('<%%%0:s.DisplayLabel%%>', [VarName])  { do not localize }
    else
      Text := Self.Caption;
    Result := Format('<img border="0" src="%0:s"%1:s alt="%2:s"/>', [HREF, Attrs, Text, ImageName]);  { do not localize }
    Result := Format(#13#10 + sIfEnabledElse,
      [VarName,
      Format('<a %3:shref="%2:s" onclick="%0:s">%1:s</a>', [AnchorClickEvent(VarName), Result, FormAction,  { do not localize }
        Events]),
      Format('<a>%0:s</a>', [Result]),  { do not localize }
      ChildTableIndent(Self)]);
    if IsList then
      Result := #13#10 + FormatList(VarName, Result, ChildTableIndent(Self));
    Result := Result + ChildTableIndent(Self);
  end;

  function FormatAnchor(const VarName: string; IsList: Boolean): string;
  var
    Attrs: string;
    Text: string;
  begin
    AddQuotedAttrib(Attrs, sStyleAttr, Style);
    AddQuotedAttrib(Attrs, sClassAttr, StyleRule);
    AddCustomAttrib(Attrs, Custom);
    if IsList then
      Text := Format('<%%=%0:s.DisplayLabel%%>', [VarName])  { do not localize }
    else
      Text := Self.Caption;
    Result := Format(#13#10 + sIfEnabledElse,
      [VarName,
      Format('<a href="%2:s"%0:s onclick="%3:s">%1:s</a>', [Attrs, Text, FormAction,  { do not localize }
        AnchorClickEvent(VarName)]),
      Format('<a%0:s>%1:s</a>', [Attrs, Text]),  { do not localize }
      ChildTableIndent(Self)]);
    if IsList then
      Result := #13#10 + FormatList(VarName, Result, ChildTableIndent(Self));
    // Result := Result + FieldIndent(Self);
    Result := Result + ChildTableIndent(Self);
  end;

  function FormatButton(const VarName: string; IsList: Boolean): string;
  var
    Attrs: string;
    Text: string;
  begin
    AddQuotedAttrib(Attrs, sStyleAttr, Style);
    AddQuotedAttrib(Attrs, sClassAttr, StyleRule);
    if IsList then
      Text := Format('<%%=%0:s.DisplayLabel%%>', [VarName])  { do not localize }
    else
      Text := Self.Caption;
    AddQuotedAttrib(Attrs, sValueAttr, Text);
    AddCustomAttrib(Attrs, Custom);
    if not (coNoScript in Options.Flags) then
    begin
      AddQuotedAttrib(Attrs, sOnClickAttr,
         Format('%0:s.%1:s.value=''%2:s''', [  { do not localize }
           GetHTMLFormVarName, sActionRequest,
           ActionFieldValue(VarName)]))
    end
    else
      AddQuotedAttrib(Attrs, sOnClickAttr,
        'return false');  { do not localize }
    Result :=
      Format('<input type="submit"%0:s>',  { do not localize }
       [Attrs]);
    if IsList then
      // Result := #13#10 + FormatList(VarName, Result, FieldIndent(Self));
      Result := #13#10 + FormatList(VarName, Result, ChildTableIndent(Self));
  end;

  procedure AddToCondition(const S: string);
  begin
    if Condition <> '' then
      Condition := Condition + ' && ';
    Condition := Condition + S;
  end;

  function CalcImageProducerDisplayType(AAction: TComponent): TCommandHTMLElementType;
  var
    S: string;
    Intf: IActionImageProducer;
    I: TAdapterActionHTMLElementType;
  begin
    S := '';
    if (AAction <> nil) and Supports(ImageProducer, IActionImageProducer, Intf) then
    begin
      S := Intf.GetDisplayStyle(AAction);
      for I := Low(TAdapterActionHTMLElementType) to High(TAdapterActionHTMLElementType) do
        if CompareText(S, AdapterActionHTMLElementTypeNames[I]) = 0 then
        begin
          Result := ConvertDisplayType(I);
          Exit
        end;
    end;
    Result := ctImage;
  end;
var
  Intf: ILayoutWebContent;
  VarName: string;
  DisplayType: TCommandHTMLElementType;
  Action: TComponent;
  IsListIntf: IIsAdapterActionList;
  IsList: Boolean;
  T: string;
  GetAdapterFormLayout: IGetAdapterFormLayout;
begin
  VarName := MakeAdapterVariableName(Self);
  if (VarName <> '') and (not (bhoHideAlways in HideOptions)) then
  begin
    Action := FindAssociatedAction;
    IsList := Supports(IUnknown(Action), IIsAdapterActionList, IsListIntf) and IsListIntf.IsAdapterActionList;
    DisplayType := Self.DisplayType;
    if DisplayType = ctDefault then
      if ImageProducer <> nil then
        DisplayType := CalcImageProducerDisplayType(Action)
      else if Action <> nil then
        DisplayType := ConvertDisplayType(CalcDefaultAdapterActionElementType(Action, GetAdapterModeOfAdapter))
      else
        DisplayType := ctButton;
    case DisplayType of
      ctImage:
        Result := FormatImage(Action, VarName, IsList, False);
      ctEventImages:
        Result := FormatImage(Action, VarName, IsList, True);
      ctButton:
        Result := FormatButton(VarName, IsList);
      ctAnchor:
        Result := FormatAnchor(VarName, IsList);
    else
      Assert(False);
    end;

    if bhoHideOnDisabledAction in HideOptions then
      AddToCondition(sIfEnabledCondition);
    if bhoHideOnNoExecuteAccess in HideOptions then
      AddToCondition(sCanExecuteCondition);
    if bhoHideOnActionNotVisible in HideOptions then
      AddToCondition(sIsVisibleCondition);

    if Condition <> '' then
      if Supports(ParentLayout, IGetAdapterFormLayout, GetAdapterFormLayout) then
        with GetAdapterFormLayout.GetAdapterFormLayout do
          T := EndField + StartTable + StartRow;

    if Supports(ParentLayout, ILayoutWebContent, Intf) then
      Result := Intf.LayoutButton(Result, GetLayoutAttributes);

    if Condition <> '' then
    begin
      if GetAdapterFormLayout <> nil then
        Result := Result + GetAdapterFormLayout.GetAdapterFormLayout.EndField;
      Condition := Format(Condition, [VarName]);
      Condition := Format(sIfCan, [Condition]);
      Result := Format(Condition, [Result]);
    end;
    Result := T + Result;

  end
  else
    Result := '';
end;

procedure TCustomAdapterActionButton.SetActionName(
  const AValue: string);
var
  Intf: IValidateFields;
  Component: TComponent;
begin
  if (AnsiCompareText(AValue, FActionName) <> 0) then
  begin
    FActionName := AValue;
    if (inherited GetCaption = AValue) then inherited SetCaption('');
    if Assigned(WebParent) and
      not (csLoading in ComponentState) and (Length(AValue) > 0) then
      ImplRestoreDefaults;
    if [csLoading, csDesigning] * ComponentState <> [] then
    begin
      Component := GetParentComponent;
      { IValidateFields not implemented by parent }
      while Assigned(Component) and
       (not Supports(IInterface(Component), IValidateFields, Intf)) do
       Component := Component.GetParentComponent;
      if Assigned(Component) then
        Intf.EnableValidateFields := True;
    end;
  end;

end;

procedure TCustomAdapterActionButton.RestoreDefaults;
begin
  ImplRestoreDefaults;
end;

procedure TCustomAdapterActionButton.ImplRestoreDefaults;
var
  Action: TComponent;
  WebGetDisplayLabel: IWebGetDisplayLabel;
begin
  inherited;
  Action := FindAssociatedAction;
  if Action <> nil then
  begin
    if Supports(IUnknown(Action), IWebGetDisplayLabel, WebGetDisplayLabel) then
      SetCaption(WebGetDisplayLabel.GetDisplayLabel);
  end;
end;

function TCustomAdapterActionButton.FindAssociatedAction: TComponent;
var
  Intf: IWebVariablesContainer;
  C: TObject;
begin
  Result := nil;
  if FActionName <> '' then
  begin
    C := FindVariablesContainerInParent(Self);
    if Supports(C, IWebVariablesContainer, Intf) then
      Result := Intf.FindVariable(FActionName)
    else
      Assert(C=nil);
  end;
end;

constructor TCustomAdapterActionButton.Create(AOwner: TComponent);
begin
  inherited;
  FHideOptions := [bhoHideOnActionNotVisible];
  FImageWidth := -1;
  FImageHeight := -1;
  FDisplayColumns := -1;
  FLayoutAttributes := TLayoutAttributes.Create;
end;

destructor TCustomAdapterActionButton.Destroy;
begin
  inherited;
  FLayoutAttributes.Free;
end;

procedure TCustomAdapterActionButton.GetControlRequirements(
  ARequirements: TAbstractControlRequirements);
begin
  ImplGetControlRequirements(ARequirements);
end;

procedure TCustomAdapterActionButton.ImplGetControlRequirements(
  ARequirements: TAbstractControlRequirements);
var
  S: string;
  C: TComponent;
begin
  S := GetAdapterVariableName;
  if S <> '' then
    if not ARequirements.IsVariableDefined(S) then
    begin
      C := FindAssociatedAction;
      ARequirements.DefineVariable(S,
        MakeAdapterItemVariableValue(C), False)
    end;
  S := GetImageProducerVariableName;
  if S <> '' then
    if not ARequirements.IsVariableDefined(S) then
    begin
      C := GetImageProducerComponent;
      ARequirements.DefineVariable(S,
        FullyQualifiedFieldName(C), False)
    end;
end;

function TCustomAdapterActionButton.GetImageProducerVariableName: string;
var
  C: TComponent;
begin
  C := GetImageProducerComponent;
  if C <> nil then
    Result := MakeAdapterItemVariableName(C)
  else
    Result := '';
end;

function TCustomAdapterActionButton.GetImageProducerComponent: TComponent;
var
  ComponentReference: IInterfaceComponentReference;
begin
  if Supports(ImageProducer, IInterfaceComponentReference, ComponentReference) then
    Result := ComponentReference.GetComponent
  else
    Result := nil;
end;

function TCustomAdapterActionButton.GetAdapterVariableName: string;
var
  C: TComponent;
begin
  Result := '';
  if ActionName <> '' then
  begin
    C := FindAssociatedAction;
    Result := MakeAdapterItemVariableName(C);
  end;
end;

procedure TCustomAdapterActionButton.GetDesigntimeWarnings(
  AWarnings: TAbstractDesigntimeWarnings);
begin
  if ActionName = '' then
    AWarnings.AddString(Format(sAdapterActionNameIsBlank, [Self.Name]))
  else
    if FindAssociatedAction = nil then
      AWarnings.AddString(Format(sCantFindAdapterAction, [Self.Name, ActionName]));
end;

{ TCustomAdapterCommandGroup }

function TCustomAdapterCommandGroup.ImplCanAddClass(AParent: TComponent;
  AClass: TClass): Boolean;
begin
  Result := AClass.InheritsFrom(TCustomAdapterActionButton) or
    AClass.InheritsFrom(TCustomLayoutGroup) or
      CanAddClassHelper(Self, AParent, AClass);
end;

function TCustomAdapterCommandGroup.ImplContent(Options: TWebContentOptions; ParentLayout: TLayout): string;

  function FormatButton(Button: TComponent): string;
  var
    Intf: IWebContent;
  begin
    Result := '';
    if Supports(IInterface(Button), IWebContent, Intf) then
      Result := Intf.Content(Options, FFormLayout);
  end;
var
  Button: TComponent;
  I: Integer;
  Intf: ILayoutWebContent;
  Attribs: string;
  VarName: string;
  S: string;
  A: TLayoutAttributes;
begin
  FFormLayout := TAdapterFormLayout.Create(ParentLayout);
  try
    AddQuotedAttrib(Attribs, sStyleAttr, Style);
    AddQuotedAttrib(Attribs, sClassAttr, StyleRule);
    AddCustomAttrib(Attribs, Custom);
    FFormLayout.FTableHeader := Format('<table%s>', [Attribs]);  { do not localize }
    Result := '';
    for I := 0 to VisibleCommands.Count - 1 do
    begin
      Button := VisibleCommands.WebComponents[I];
      S := FormatButton(Button);
      Result := Result + S;
    end;
    Result := Result + FFormLayout.EndLayout;
  finally
    FreeAndNil(FFormLayout);
  end;
  if GetAdapterModeOfDisplay <> '' then
  begin
    VarName := MakeAdapterVariableName(DisplayComponent);
    if VarName <> '' then
      Result := Format(sSetAdapterMode,
                     [VarName, GetAdapterModeOfDisplay, Result]);
  end;
  if Supports(ParentLayout, ILayoutWebContent, Intf) then
    if ParentLayout is TAdapterFormLayout then
      Result := Intf.LayoutTable(Result, nil)
    else
    begin
      A := TLayoutAttributes.Create;
      try
        with A do
        begin
          AddQuotedAttrib(ControlAttributes, sAlignAttr, HTMLAlignValues[haCenter]);
          AddQuotedAttrib(ControlAttributes, sVAlignAttr, HTMLVAlignValues[haTop]);
          // Work better with a layout group
          Result := Intf.LayoutTable(#13#10 + Result, A);
        end
      finally
        A.Free;
      end;
    end;
end;

function TCustomAdapterCommandGroup.GetAdapter: TComponent;
var
  SiteDisplay: TComponent;
begin
  SiteDisplay := GetWebDisplayComponent;
  if Assigned(SiteDisplay) then
    Result := FindAdapter(SiteDisplay)
  else
    Result := nil;
end;

function TCustomAdapterCommandGroup.GetAdapterModeOfDisplay: string;
var
  Intf: IGetAdapterModeOfDisplay;
begin
  if Supports(IUnknown(GetWebDisplayComponent), IGetAdapterModeOfDisplay, Intf) then
    Result := Intf.GetAdapterModeOfDisplay
  else
    Result := '';
end;

function TCustomAdapterCommandGroup.GetAdapterModeOfAdapter: string;
var
  Intf: IGetAdapterModeOfDisplay;
begin
  if Supports(IUnknown(GetWebDisplayComponent), IGetAdapterModeOfDisplay, Intf) then
    Result := Intf.GetAdapterModeOfAdapter
  else
    Result := '';
end;

constructor TCustomAdapterCommandGroup.Create(AOwner: TComponent);
begin
  inherited;
  FAdapterActionsListHelper := TAdapterActionsListHelper.Create(Self,
    WebContainerComponentHelper);
  FAdapterActionsListHelper.AddDefaultActions := True;
end;

destructor TCustomAdapterCommandGroup.Destroy;
begin
  inherited;
  FAdapterActionsListHelper.Free;
end;

function TCustomAdapterCommandGroup.GetVisibleCommands: TWebComponentList;
begin
  Result := FAdapterActionsListHelper.GetVisibleActions;
end;

function TCustomAdapterCommandGroup.GetAddDefaultCommands: Boolean;
begin
  Result := FAdapterActionsListHelper.AddDefaultActions;
end;

procedure TCustomAdapterCommandGroup.SetAddDefaultCommands(
  const Value: Boolean);
begin
  FAdapterActionsListHelper.AddDefaultActions := Value;
end;

{ TCustomAdapterErrorList }

function TCustomAdapterErrorList.Content(Options: TWebContentOptions;
  Layout: TLayout): string;
begin
  Result := ImplContent(Options, Layout);
end;

function TCustomAdapterErrorList.GetAdapter: TComponent;
begin
  Result := FAdapter;
end;

procedure TCustomAdapterErrorList.SetAdapter(const Value: TComponent);
begin
  if FAdapter <> Value then
  begin
    if Value <> nil then Value.FreeNotification(Self);
    FAdapter := Value;
  end;
end;

procedure TCustomAdapterErrorList.Notification(AComponent: TComponent; Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (AComponent = FAdapter) then
    FAdapter := nil;
end;

function TCustomAdapterErrorList.GetLayoutAttributes: TLayoutAttributes;
begin
  Result := FLayoutAttributes;
end;

function TCustomAdapterErrorList.ImplContent(Options: TWebContentOptions;
  Layout: TLayout): string;
var
  Intf: ILayoutWebContent;
  A: TLayoutAttributes;
begin
  if Assigned(FAdapter) then
    Result := Format(
     #13#10 +
    '<%% {'#13#10 +                                                             { do not localize }
     '   var e = new Enumerator(%0:s.Errors)'#13#10 +                           { do not localize }
     '   for (; !e.atEnd(); e.moveNext())'#13#10 +                              { do not localize }
     '   {'#13#10 +                                                             { do not localize }
     '     Response.Write("<li>" + e.item().Message)'#13#10 +                   { do not localize }
     '   }'#13#10 +                                                             { do not localize }
     '   e.moveFirst()'#13#10 +                                                 { do not localize }
     '   } %%>'#13#10 + ChildTableIndent(Self),                                 { do not localize }
     [FullyQualifiedFieldName(FAdapter)])                                       { do not localize }
  else
    Result := '';
  if Result <> '' then
    if Supports(Layout, ILayoutWebContent, Intf) then
      if Layout is TAdapterFormLayout then
        Result := Intf.LayoutField(Result, GetLayoutAttributes) + #13#10
      else
      begin
        A := TLayoutAttributes.Create;
        try
          with A do
          begin
            AddQuotedAttrib(ControlAttributes, sAlignAttr, HTMLAlignValues[haCenter]);
            AddQuotedAttrib(ControlAttributes, sVAlignAttr, HTMLVAlignValues[haTop]);
            // Work better with a layout group
            Result := Intf.LayoutField(#13#10 + Result + #13#10, A);
          end
        finally
          A.Free;
        end;
      end
end;

constructor TCustomAdapterErrorList.Create(AOwner: TComponent);
begin
  inherited;
  FLayoutAttributes := TLayoutAttributes.Create;
end;

destructor TCustomAdapterErrorList.Destroy;
begin
  inherited;
  FLayoutAttributes.Free;
end;

procedure TCustomAdapterErrorList.GetDesigntimeWarnings(
  AWarnings: TAbstractDesigntimeWarnings);
begin
  if Adapter = nil then
    AWarnings.AddString(Format(sAdapterPropertyIsNil, [Self.Name]))
  else
    AWarnings.AddObject(Adapter);
end;

{ TCustomAdapterCommandColumn }

function TCustomAdapterCommandColumn.ImplCanAddClass(
  AParent: TComponent; AClass: TClass): Boolean;
begin
  Result := AClass.InheritsFrom(TCustomAdapterActionButton) or
    AClass.InheritsFrom(TCustomLayoutGroup) or
      CanAddClassHelper(Self, AParent, AClass);
end;

function TCustomAdapterCommandColumn.ImplContent(Options: TWebContentOptions;
  ParentLayout: TLayout): string;
var
  FormLayout: TAdapterFormLayout;

  function FormatCommand(Command: TComponent): string;
  var
    Intf: IWebContent;
  begin
    Result := '';
    if Supports(IInterface(Command), IWebContent, Intf) then
      Result := Intf.Content(Options, FormLayout);
  end;
var
  I: Integer;
  Command: TComponent;
  Intf: ILayoutWebContent;
begin
  Result := '';
  if VisibleCommands.Count = 0 then Exit;
  FormLayout := TAdapterFormLayout.Create(ParentLayout);
  try
    if DisplayColumns >= 1 then
    begin
      FormLayout.ColumnCount := Min(DisplayColumns, VisibleCommands.Count);
      FormLayout.BreakButtons := True;
    end;
    FormLayout.TableHeader :=
      Format('<table%s>', [GetLayoutAttributes.ControlAttributes]);  { do not localize }
    for I := 0 to VisibleCommands.Count - 1 do
    begin
      Command := VisibleCommands.WebComponents[I];
      Result := Result + FormatCommand(Command);
    end;
    Result := Result + FormLayout.EndLayout;

    if Supports(ParentLayout, ILayoutWebContent, Intf) then
      Result := Intf.LayoutTable(Result, nil)
  finally
    FormLayout.Free;
  end;
end;

function TCustomAdapterCommandColumn.FormatColumnData(
  const Content: string; Options: TWebContentOptions): string;
var
  Attribs: string;
begin
  AddQuotedAttrib(Attribs, sAlignAttr, HTMLAlignValues[Align]);
  AddQuotedAttrib(Attribs, sVAlignAttr, HTMLVAlignValues[VAlign]);
  Result := Format(FieldIndent(Self) + '<td%0:s><div>'#13#10'%1:s%2:s</div></td>'#13#10, [Attribs,  { do not localize }
    Content, FieldIndent(Self)]);
end;

function TCustomAdapterCommandColumn.FormatColumnHeading(Options: TWebContentOptions): string;
var
  Attribs: string;
begin
  AddQuotedAttrib(Attribs, sStyleAttr, Self.CaptionAttributes.Style);
  AddCustomAttrib(Attribs, Self.CaptionAttributes.Custom);
  AddQuotedAttrib(Attribs, sClassAttr, Self.CaptionAttributes.StyleRule);
  AddQuotedAttrib(Attribs, sVAlignAttr, HTMLVAlignValues[Self.CaptionAttributes.VAlign]);
  AddQuotedAttrib(Attribs, sAlignAttr, HTMLAlignValues[Self.CaptionAttributes.Align]);
  Result := Format(FieldIndent(Self) + '<th%0:s>%1:s</th>'#13#10, [Attribs, Caption]);  { do not localize }
end;

const
  sDefaultCommandColumnCaption = '&nbsp;';  { do not localize }

function TCustomAdapterCommandColumn.GetCaption: string;
begin
  if FCaption = '' then
    Result := sDefaultCommandColumnCaption
  else
    Result := FCaption;
end;

procedure TCustomAdapterCommandColumn.SetCaptionAttributes(
  const Value: TCaptionAttributes);
begin
  FCaptionAttributes.Assign(Value);
end;

constructor TCustomAdapterCommandColumn.Create(AOwner: TComponent);
begin
  inherited;
  FCaptionAttributes := TCaptionAttributes.Create(Self);
  FDisplayColumns := -1;
  FAdapterActionsListHelper := TAdapterActionsListHelper.Create(Self,
    WebContainerComponentHelper);
  FAdapterActionsListHelper.AddDefaultActions := True;
  FLayoutAttributes := TLayoutAttributes.Create;
end;

destructor TCustomAdapterCommandColumn.Destroy;
begin
  inherited;
  FCaptionAttributes.Free;
  FAdapterActionsListHelper.Free;
  FLayoutAttributes.Free;
end;

function TCustomAdapterCommandColumn.GetAdapterDisplayCharacteristics: TAdapterDisplayCharacteristics;
begin
  Result := [dcMultipleRecordView, dcCurrentRecordView {,
    dcChangeCurrentRecordView} ];
end;

procedure TCustomAdapterCommandColumn.SetCaption(const Value: string);
begin
  if Value <> FCaption then
    if Value = sDefaultCommandColumnCaption then
      FCaption := ''
    else
      FCaption := Value;
end;

function TCustomAdapterCommandColumn.GetVisibleActions: TWebComponentList;
begin
  Result := FAdapterActionsListHelper.GetVisibleActions;
end;

function TCustomAdapterCommandColumn.GetAddDefaultCommands: Boolean;
begin
  Result := FAdapterActionsListHelper.AddDefaultActions;
end;

procedure TCustomAdapterCommandColumn.SetAddDefaultCommands(
  const Value: Boolean);
begin
  FAdapterActionsListHelper.AddDefaultActions := Value;
end;

procedure TCustomAdapterDisplayColumn.ImplRestoreDefaults;
var
  Field: TComponent;
  WebGetDisplayLabel: IWebGetDisplayLabel;
begin
  inherited;
  Field := FindAssociatedField;
  if Field <> nil then
  begin
    if Supports(IUnknown(Field), IWebGetDisplayLabel, WebGetDisplayLabel) then
      SetCaption(WebGetDisplayLabel.GetDisplayLabel);
  end;
end;

{ TControlRequirements }

constructor TControlRequirements.Create;
begin
  FGeneratedFunctions := TGeneratedFunctions.Create;
  FVariables := TStringList.Create;
end;

procedure TControlRequirements.DefineVariable(const AName, AValue: string; AAdapter: Boolean);
var
  S: string;
begin
  if FVariables.IndexOf(AName) = -1 then
  begin
    S := Format('%s=%s', [AName, AValue]);
    if AAdapter then
      FVariables.Insert(0, S)
    else
      FVariables.Add(S);
  end;
end;

procedure TControlRequirements.DefineFunction(const AName, ABody: string);
begin
  FGeneratedFunctions.Add(AName, ABody);
end;

destructor TControlRequirements.Destroy;
begin
  inherited;
  FGeneratedFunctions.Free;
  FVariables.Free;
end;

function TControlRequirements.IsFunctionDefined(
  const AName: string): Boolean;
begin
  Result := FGeneratedFunctions.Exists(AName);
end;

procedure TControlRequirements.RequiresMultipartForm;
begin
  FNeedMultipartForm := True;
end;

{ TAdapterDisplayReferenceGroup }

constructor TAdapterDisplayReferenceGroup.Create(AOwner: TComponent);
begin
  inherited;
  WebDisplay.OnChange := OnDisplayComponentChange;
end;

procedure TAdapterDisplayReferenceGroup.GetDesigntimeWarnings(
  AWarnings: TAbstractDesigntimeWarnings);
begin
  if DisplayComponent = nil then
    AWarnings.AddString(Format(sDisplayComponentPropertyIsNil, [Self.Name]))
  else
    AWarnings.AddObject(DisplayComponent);
end;

procedure TAdapterDisplayReferenceGroup.OnDisplayComponentChange(
  ASender: TObject);
begin
  DisplayComponentChange;
end;

procedure TAdapterDisplayReferenceGroup.NotifyAdapterChange(Sender: TComponent);
begin
  AdapterChange;
end;

procedure TAdapterDisplayReferenceGroup.AdapterChange;
var
  I: Integer;
  AdapterChange: INotifyAdapterChange;
begin
  // Prevent the components from being freed during
  // the process of populating the default components
  if (GetDefaultWebComponents <> nil) then
  begin
    GetDefaultWebComponents.Free;
    SetDefaultWebComponents(nil);
  end;
  for I := 0 to GetWebComponents.Count - 1 do
    if Supports(IUnknown(GetWebComponents.WebComponents[I]), INotifyAdapterChange, AdapterChange) then
      AdapterChange.NotifyAdapterChange(Self);
end;

procedure TAdapterDisplayReferenceGroup.SetWebDisplayComponent(
  const AComponent: TComponent);
var
  NotifyList: INotifyList;
begin
  if AComponent <> WebDisplayComponent then
  begin
    if Supports(IInterface(WebDisplayComponent), INotifyList, NotifyList) then
      NotifyList.RemoveNotify(Self);
    inherited;
    if Supports(IInterface(WebDisplayComponent), INotifyList, NotifyList) then
      NotifyList.AddNotify(Self);
  end;
end;

destructor TAdapterDisplayReferenceGroup.Destroy;
var
  NotifyList: INotifyList;
begin
  if Supports(IInterface(WebDisplayComponent), INotifyList, NotifyList) then
    NotifyList.RemoveNotify(Self);
  inherited;
end;

function TAdapterDisplayReferenceGroup.GetAdapterDisplayCharacteristics: TAdapterDisplayCharacteristics;
var
  Intf: IGetAdapterDisplayCharacteristics;
begin
  if Supports(IUnknown(DisplayComponent), IGetAdapterDisplayCharacteristics, Intf) then
    Result := Intf.GetAdapterDisplayCharacteristics
  else
    Result := [];
end;

procedure TAdapterDisplayReferenceGroup.DisplayComponentChange;
begin
  AdapterChange;
end;

{ TAdapterActionsListHelper }

constructor TAdapterActionsListHelper.Create(AComponent: TComponent;
      AHelper: TWebContainerComponentHelper);
begin
  FComponent := AComponent;
  Assert(FComponent <> nil);
  FHelper := AHelper;
  Assert(FHelper <> nil);
  inherited Create;
end;

function TAdapterActionsListHelper.GetAddAllFieldsItem: string;
begin
  Result := sAddAllCommands;
end;

function TAdapterActionsListHelper.GetAddFieldsDlgCaption: string;
begin
  Result := sAddCommandsDlgCaption;
end;

function TAdapterActionsListHelper.GetAddFieldsItem: string;
begin
  Result := sAddCommands;
end;

function TAdapterActionsListHelper.GetNewFieldPrefix: string;
begin
  Result := sAdapterCommandPrefix;
end;

function TAdapterActionsListHelper.FindAction(
  const AName: string): TComponent;
var
  I: Integer;
  GetName: IWebGetActionName;
begin
  for I := 0 to FHelper.WebComponents.Count - 1 do
  begin
    if Supports(IInterface(FHelper.WebComponents.WebComponents[I]), IWebGetActionName, GetName) then
    begin
      Result := FHelper.WebComponents.WebComponents[I];
      if AnsiCompareText(GetName.ActionName, AName) = 0 then Exit;
    end;
  end;
  Result := nil;
end;

function TAdapterActionsListHelper.GetVisibleActions: TWebComponentList;
begin
  if (FAddDefaultActions = False) or (FHelper.WebComponents.Count > 0) then
    Result := FHelper.WebComponents
  else
  begin
    if FHelper.DefaultWebComponents = nil then
      CreateDefaultActions;
    Result := FHelper.DefaultWebComponents;
  end;
end;

procedure TAdapterActionsListHelper.GetActionsList(List: TStrings);
var
  I: Integer;
  ButtonClass: TComponentClass;
  WebComponent: TComponent;
  WebVariables: IWebVariablesContainer;
  GetName: IWebGetActionName;
  GetIntf: IGetAdapterActions;
  IsDefaultAction: IWebIsDefaultAction;
  EditorIntf: IWebComponentEditor;
  C: TComponent;
begin
  if Supports(IUnknown(FComponent), IWebComponentEditor, EditorIntf) and
    EditorIntf.CanAddClass(FComponent, TAdapterActionButton) then
    ButtonClass := TAdapterActionButton
  else
    ButtonClass := nil;

  List.Clear;
  C := FindVariablesContainer(FComponent);
  if not Supports(IUnknown(C), IGetAdapterActions, GetIntf) then
    Assert(C = nil);
  if Assigned(GetIntf) and
    Supports(GetIntf.GetAdapterActions, IWebVariablesContainer, WebVariables) then
    for I := 0 to WebVariables.VariableCount - 1 do
    begin
      WebComponent := WebVariables.Variables[I];
      if Assigned(ButtonClass) then
        if Supports(IUnknown(WebComponent), IWebGetActionName, GetName) then
          if (not Supports(IUnknown(WebComponent), IWebIsDefaultAction, IsDefaultAction)) or
            IsDefaultAction.IsDefaultAction(Self) then
            List.AddObject(GetName.GetActionName, TObject(ButtonClass));
    end;
end;

function TAdapterActionsListHelper.IsActionInUse(
  const AName: string): Boolean;
begin
  Result := FindAction(AName) <> nil;
end;

procedure TAdapterActionsListHelper.CreateDefaultActions;
var
  WebComponent: IWebComponent;
  SetName: IWebSetActionName;
  FieldControl: TComponent;
  FieldClass: TComponentClass;
  List: TStrings;
  I: integer;
  Components: TWebComponentList;
begin
  List := TStringList.Create;
  try
    GetActionsList(List);
    Assert(FHelper.DefaultWebComponents = nil);
    Components := TWebComponentList.Create(FComponent);
    Components.LockNotify;
    try
      FHelper.DefaultWebComponents := Components;
      for I := 0 to List.Count - 1 do
      begin
        if not IsActionInUse(List[I]) then
        begin
          FieldClass := TComponentClass(List.Objects[I]);
          FieldControl := FieldClass.Create(nil);  // not owned
          Supports(IInterface(FieldControl), IWebComponent, WebComponent);
          WebComponent.Container := FHelper.WebComponents;
          if Supports(IInterface(FieldControl), IWebSetActionName, SetName) then
             SetName.SetActionName(List[I]);
        end;
      end;
    finally
      Components.UnlockNotify;
    end;
  finally
    List.Free;
  end;
end;

procedure TAdapterActionsListHelper.SetAddDefaultActions(
  const Value: Boolean);
begin
  if Value <> FAddDefaultActions then
  begin
    FHelper.DefaultWebComponents.Free;
    FHelper.DefaultWebComponents := nil;
    FAddDefaultActions := Value;
  end;
end;

{ TGeneratedFunctions }

procedure TGeneratedFunctions.Add(const AName, AScript: string);
begin
  Assert(not Exists(AName));
  FNames.Add(AName);
  FScript.Add(AScript);
end;

constructor TGeneratedFunctions.Create;
begin
  FNames := TStringList.Create;
  FScript := TStringList.Create;
  inherited;
end;

destructor TGeneratedFunctions.Destroy;
begin
  inherited;
  FNames.Free;
  FScript.Free;
end;

function TGeneratedFunctions.Exists(const AName: string): Boolean;
begin
  Result := FNames.IndexOf(AName) <> -1;
end;

function TGeneratedFunctions.GetScript(I: Integer): string;
begin
  Result := FScript[I];
end;

function TGeneratedFunctions.GetItemCount: Integer;
begin
  Result := FScript.Count;
end;

function TGeneratedFunctions.GetName(I: Integer): string;
begin
  Result := FNames[I];
end;

{ TDesigntimeWarnings }

procedure TDesigntimeWarnings.AddString(AWarning: string);
begin
  FStrings.Add(AWarning);
end;

procedure TDesigntimeWarnings.AddObject(AObject: TObject);

  procedure ContainerWarnings(Container: IWebComponentContainer);
  var
    I: Integer;
  begin
    if Container <> nil then
      for I := 0 to Container.ComponentCount - 1 do
        Self.AddObject(Container.Components[I]);
  end;
var
  GetIntf: IGetDesignTimeWarnings;
  WebDataFields: IWebDataFields;
  WebActionsList: IWebActionsList;
  GetWebComponentList: IGetWebComponentList;
  Container: IWebComponentContainer;
  I: Integer;
begin
  if FObjects.IndexOf(AObject) > 0 then
    Exit;
  FObjects.Add(AObject);
   if Container <> nil then
    for I := 0 to Container.ComponentCount - 1 do
      Self.AddObject(Container.Components[I]);
  if Supports(AObject, IGetDesigntimeWarnings, GetIntf) then
    GetIntf.GetDesigntimeWarnings(Self);
  if Supports(AObject, IWebDataFields, WebDataFields) then
  begin
    Container := WebDataFields.GetVisibleFields;
    ContainerWarnings(Container);
  end;
  if Supports(AObject, IWebActionsList, WebActionsList) then
  begin
    Container := WebActionsList.GetVisibleActions;
    ContainerWarnings(Container);
  end;
  if Supports(AObject, IGetWebComponentList, GetWebComponentList) then
  begin
    Supports(GetWebComponentList.GetComponentList, IWebComponentContainer,
      Container);
    ContainerWarnings(Container);
  end;
end;

constructor TDesigntimeWarnings.Create;
begin
  FStrings := TStringList.Create;
  FObjects := TObjectList.Create(False { not owned} );
  inherited;
end;

destructor TDesigntimeWarnings.Destroy;
begin
  FStrings.Free;
  FObjects.Free;
  inherited;
end;

function TAdapterDataDisplay.GetAdapterModeOfAdapter: string;
begin
  Result := GetAdapterModeOfAdapterInParent(Self);
end;

function TCustomAdapterActionButton.GetAdapterModeOfAdapter: string;
begin
  Result := GetAdapterModeOfAdapterInParent(Self);
end;

procedure TCustomAdapterCommandColumn.NotifyAdapterChange(
  Sender: TComponent);
var
  I: Integer;
  AdapterChange: INotifyAdapterChange;
begin
  // Prevent the components from being freed during
  // the process of populating the default components
  if (GetDefaultWebComponents <> nil) then
  begin
    GetDefaultWebComponents.Free;
    SetDefaultWebComponents(nil);
  end;
  for I := 0 to GetWebComponents.Count - 1 do
    if Supports(IUnknown(GetWebComponents.WebComponents[I]), INotifyAdapterChange, AdapterChange) then
      AdapterChange.NotifyAdapterChange(Self);
end;

function TCustomAdapterCommandColumn.IsCaptionStored: Boolean;
begin
  Result := FCaption <> '';
end;

procedure TCustomAdapterActionButton.SetImageProducer(
  const Value: IActionImageProducer);
begin
  ReferenceInterface(FImageProducer, opRemove);
  FImageProducer := Value;
  ReferenceInterface(FImageProducer, opInsert);
end;

procedure TCustomAdapterActionButton.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and AComponent.IsImplementorOf(FImageProducer) then
    FImageProducer := nil;
end;

procedure TAdapterControlGroup.GetControlRequirements(
  ARequirements: TAbstractControlRequirements);
begin
  ImplGetControlRequirements(ARequirements);
end;

procedure TAdapterControlGroup.ImplGetControlRequirements(
  ARequirements: TAbstractControlRequirements);
var
  S: string;
begin
  if Assigned(Adapter) then
  begin
    S := GetAdapterVariableName;
    if not ARequirements.IsVariableDefined(S) then
      ARequirements.DefineVariable(S,
        FullyQualifiedFieldName(Adapter), True)
  end;
end;

function TControlRequirements.IsVariableDefined(
  const AName: string): Boolean;
begin
  Result := FVariables.IndexOf(AName) <> -1;
end;

function TAdapterFormLayout.GetAdapterFormLayout: TAdapterFormLayout;
begin
  Result := Self;
end;

function TCustomAdapterGrid.GetAdapterFormLayout: TAdapterFormLayout;
begin
  Result := FTableLayout;
end;

{ TCustomAdapterEditColumn }

function TCustomAdapterEditColumn.ImplContent(Options: TWebContentOptions;
  ParentLayout: TLayout): string;
var
  Intf: ILayoutWebContent;
  S: string;
begin
  S := ControlContent(Options);
  if S <> '' then
  begin
    if Supports(ParentLayout, ILayoutWebContent, Intf) then
      Result := Intf.LayoutLabelAndField(LabelContent, S,
        GetLayoutAttributes)
    else
      Result := LabelContent + S;
  end
  else
    Result := '';
end;

function TCustomAdapterCommandColumn.GetLayoutAttributes: TLayoutAttributes;
begin
  with FLayoutAttributes do
  begin
    ControlAttributes := '';
    AddQuotedAttrib(ControlAttributes, sStyleAttr, Style);
    AddQuotedAttrib(ControlAttributes, sClassAttr, StyleRule);
    AddCustomAttrib(ControlAttributes, Custom);
  end;
  Result := FLayoutAttributes;
end;

function TCustomAdapterCommandGroup.GetAdapterFormLayout: TAdapterFormLayout;
begin
  Result := FFormLayout;
end;

function TCustomAdapterActionButton.GetLayoutAttributes: TLayoutAttributes;
begin
  with FLayoutAttributes do
  begin
    ControlAttributes := '';
    AddQuotedAttrib(ControlAttributes, sAlignAttr, HTMLAlignValues[Align]);
    AddQuotedAttrib(ControlAttributes, sVAlignAttr, HTMLVAlignValues[VAlign]);
  end;
  Result := FLayoutAttributes;
end;

end.

