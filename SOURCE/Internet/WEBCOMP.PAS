
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1999 Inprise Corporation          }
{                                                       }
{*******************************************************}

unit WebComp;

interface

uses Classes, HTTPApp, Midas, Masks;

type

  IScriptManager = interface;
  IScriptProducer = interface
  ['{555DA472-F254-11D2-AA55-00A024C11562}']
    function GetScriptManager: IScriptManager;
    property ScriptManager: IScriptManager read GetScriptManager;
  end;

  IXMLRowSet = interface;
  IXMLDocuments = interface;
  IXMLDocument = interface;
  IXMLRowSets = interface;
  IIncludeFiles = interface;
  IFunctions = interface;
  IVars = interface;
  IScriptBlocks = interface;
  IHTMLBlocks = interface;
  TWebContentOptions = class;
  IAddScriptElements = interface;
  IScriptManager = interface
  ['{94B8B14E-E6D6-11D2-AFA6-00C04FB16EC3}']
    function GetXMLDocuments: IXMLDocuments;
    function GetIncludeFiles: IIncludeFiles;
    function GetFunctions: IFunctions;
    function GetWarnings: TStrings;
    function GetScriptBlocks: IScriptBlocks;
    function GetVars: IVars;
    function GetHTMLBlocks: IHTMLBlocks;
    function GetOptions: TWebContentOptions;
    function GetAddElementsIntf: IAddScriptElements;
    procedure AddError(const Error: string);
    property XMLDocuments: IXMLDocuments read GetXMLDocuments;
    property IncludeFiles: IIncludeFiles read GetIncludeFiles;
    property Warnings: TStrings read GetWarnings;
    property Functions: IFunctions read GetFunctions;
    property Vars: IVars read GetVars;
    property ScriptBlocks: IScriptBlocks read GetScriptBlocks;
    property HTMLBlocks: IHTMLBlocks read GetHTMLBlocks;
    property Options: TWebContentOptions read GetOptions;
    property AddElementsIntf: IAddScriptElements read GetAddElementsIntf;
  end;

  IIncludeFile = interface;
  IIncludeFiles = interface
  ['{F735BC77-E7A4-11D2-AFA7-00C04FB16EC3}']
    function GetCount: Integer;
    function GetItem(I: Integer): IIncludeFile;
    property Count: Integer read GetCount;
    property Items[I: Integer]: IIncludeFile read GetItem;
  end;

  IIncludeFile = interface
  ['{F735BC78-E7A4-11D2-AFA7-00C04FB16EC3}']
    function GetFileName: string;
    property FileName: string read GetFileName;
  end;

  IFunction = interface;
  IFunctions = interface
  ['{3AA43171-EC43-11D2-AFAE-00C04FB16EC3}']
    function GetCount: Integer;
    function GetItem(I: Integer): IFunction;
    property Count: Integer read GetCount;
    property Items[I: Integer]: IFunction read GetItem;
  end;

  IFunction = interface
  ['{3AA43172-EC43-11D2-AFAE-00C04FB16EC3}']
    function GetFunctionName: string;
    function GetBody: string;
    property FunctionName: string read GetFunctionName;
    property Body: string read GetBody;
  end;

  IVar = interface;
  IVars = interface
  ['{8AFBBDE2-2A11-11D3-AAAB-00A024C11562}']
    function GetCount: Integer;
    function GetItem(I: Integer): IVar;
    property Count: Integer read GetCount;
    property Items[I: Integer]: IVar read GetItem;
  end;

  IVar = interface
  ['{8AFBBDE3-2A11-11D3-AAAB-00A024C11562}']
    function GetVarName: string;
    function GetScript: string;
    property VarName: string read GetVarName;
    property Script: string read GetScript;
  end;

  IHTMLBlock = interface;
  IHTMLBlocks = interface
  ['{8AFBBDE4-2A11-11D3-AAAB-00A024C11562}']
    function GetCount: Integer;
    function GetItem(I: Integer): IHTMLBlock;
    property Count: Integer read GetCount;
    property Items[I: Integer]: IHTMLBlock read GetItem;
  end;

  IHTMLBlock = interface
  ['{8AFBBDE5-2A11-11D3-AAAB-00A024C11562}']
    function GetBlockName: string;
    function GetHTML: string;
    property BlockName: string read GetBlockName;
    property HTML: string read GetHTML;
  end;

  IScriptBlock = interface;
  IScriptBlocks = interface
  ['{8AFBBDE6-2A11-11D3-AAAB-00A024C11562}']
    function GetCount: Integer;
    function GetItem(I: Integer): IScriptBlock;
    property Count: Integer read GetCount;
    property Items[I: Integer]: IScriptBlock read GetItem;
  end;

  IScriptBlock = interface
  ['{8AFBBDE7-2A11-11D3-AAAB-00A024C11562}']
    function GetBlockName: string;
    function GetScript: string;
    property BlockName: string read GetBlockName;
    property Script: string read GetScript;
  end;

  IXMLDocuments = interface
  ['{94B8B150-E6D6-11D2-AFA6-00C04FB16EC3}']
    function GetCount: Integer;
    function GetItem(I: Integer): IXMLDocument;
    property Count: Integer read GetCount;
    property Items[I: Integer]: IXMLDocument read GetItem;
  end;

  IXMLDocument = interface
  ['{94B8B151-E6D6-11D2-AFA6-00C04FB16EC3}']
    function GetRowSets: IXMLRowSets;
    function GetComponent: TComponent;
    function GetDocumentVarName: string;
    function GetXMLVarName: string;
    property RowSets: IXMLRowSets read GetRowSets;
    property Component: TComponent read GetComponent;
    property DocumentVarName: string read GetDocumentVarName;
    property XMLVarName: string read GetXMLVarName;
  end;

  IXMLRowSets = interface
  ['{94B8B152-E6D6-11D2-AFA6-00C04FB16EC3}']
    function GetCount: Integer;
    function GetItem(I: Integer): IXMLRowSet;
    property Count: Integer read GetCount;
    property Items[I: Integer]: IXMLRowSet read GetItem;
  end;

  IXMLRowSet = interface
  ['{94B8B14F-E6D6-11D2-AFA6-00C04FB16EC3}']
    function GetPath: TStrings;
    function GetRowSetVarName: string;
    function GetMasterRowSetVarName: string;
    function GetMasterDataSetFieldName: string;
    property MasterRowSetVarName: string read GetMasterRowSetVarName;
    property MasterDataSetFieldName: string read GetMasterDataSetFieldName;
    property RowSetVarName: string read GetRowSetVarName;
  end;

  TAddScriptElementsEvent = procedure(Data: Pointer; AddScriptElements: IAddScriptElements) of object;

  IAddScriptElements = interface
  ['{2FF3A331-E790-11D2-AFA7-00C04FB16EC3}']
    function GetScriptManager: IScriptManager;
    function AddIncludeFile(FileName: string): Boolean;
    function AddRowSet(XMLProducer: TComponent; Path: TStrings): Boolean;
    function AddScriptBlock(Name: string; Script: string): Boolean;
    function AddHTMLBlock(Name: string; HTML: string): Boolean;
    function AddVar(Name: string; Script: string): Boolean;
    function AddFunction(Name: string; Body: string): Boolean;
    procedure AddError(Text: string);
    procedure AddPass(Event: TAddScriptElementsEvent; Data: Pointer);
    procedure AddScriptComponents(List: TObject);
    property ScriptManager: IScriptManager read GetScriptManager;
  end;

  IScriptComponent = interface
  ['{1B9B0962-D28E-11D2-AF8A-00C04FB16EC3}']
    procedure AddElements(AddIntf: IAddScriptElements);
    function GetSubComponents: TObject; // Object implementing IWebComponentContainer
    property SubComponents: TObject read GetSubComponents;
  end;

  TWebComponentContainer = TObject;

  IWebComponentContainer = interface
  ['{44957E12-E039-11D2-AA46-00A024C11562}']
    function GetComponentCount: Integer;
    function GetComponent(I: Integer): TComponent;
    property ComponentCount: Integer read GetComponentCount;
    property Components[I: Integer]: TComponent read GetComponent;
  end;

  IWebComponentEditor = interface
  ['{13F59F61-EF85-11D2-AFB1-00C04FB16EC3}']
    function CanAddClass(AParent: TComponent; AClass: TClass): Boolean;
  end;

  IWebComponentEditorHelper = interface
  ['{13F59F61-EF85-11D2-AFB1-00C04FB16EC3}']
    function CanAddClassHelper(AEditor: TComponent; AParent: TComponent; AClass: TClass): Boolean;
  end;

  IWebComponentCommands = interface
  ['{FCB67B0D-F357-11D2-AFB6-00C04FB16EC3}']
    procedure ExecuteVerb(AComponent: TComponent; Index: Integer);
    function GetVerb(AComponent: TComponent; Index: Integer): string;
    function GetVerbCount(AComponent: TComponent): Integer;
  end;

  IWebComponent = interface
  ['{EB813782-EEAE-11D2-AFB0-00C04FB16EC3}']
    function GetIndex: Integer;
    procedure SetIndex(Value: Integer);
    procedure SetContainer(Container: TWebComponentContainer);
    function GetContainer: TWebComponentContainer;
    procedure SetComponentList(List: TObject);
    property Index: Integer read GetIndex write SetIndex;
    property Container: TWebComponentContainer read GetContainer write SetContainer;
    property ComponentList: TObject write SetComponentList;
  end;

  IGetWebComponentList = interface
  ['{5CDEB0F2-EEF9-11D2-AFB1-00C04FB16EC3}']
    function GetComponentList: TObject;
    function GetDefaultComponentList: TObject;
  end;

  TWebContentFlag = (coNoScript, coLocalPaths);
  TWebContentFlags = set of TWebContentFlag;
  TWebContentOptions = class(TObject)
  private
    FFlags: TWebContentFlags;
  public
    constructor Create(AFlags: TWebContentFlags);
    property Flags: TWebContentFlags read FFlags;
  end;

  TLayout = TObject;

  IWebContent = interface
  ['{1B3E1CD1-DF59-11D2-AA45-00A024C11562}']
    function Content(Options: TWebContentOptions;
      ParentLayout: TLayout): string;
  end;

  TLabelPosition = (lposLeft, lposRight, lposAbove, lposBelow);
  TLayoutAttributes = class(TObject)
  public
    LabelAttributes: string;
    ControlAttributes: string;
    LabelPosition: TLabelPosition;
    constructor Create;
  end;

  ILayoutWebContent = interface
  ['{4E810ED1-F09B-11D2-AA53-00A024C11562}']
    function LayoutButton(const HTMLButton: string; Attributes: TLayoutAttributes): string;
    function LayoutField(const HTMLField: string; Attributes: TLayoutAttributes): string;
    function LayoutLabelAndField(const HTMLLabel, HTMLField: string; Attributes: TLayoutAttributes): string;
    function LayoutTable(const HTMLTable: string; Attributes: TLayoutAttributes): string;
  end;

  TLayoutWebContent = class(TObject, ILayoutWebContent)
  private
    FParentLayout: TLayout;
  protected
    { IUnknown }
    function QueryInterface(const IID: TGUID; out Obj): HResult; virtual; stdcall;
    function _AddRef: Integer; stdcall;
    function _Release: Integer; stdcall;
    { ILayoutWebContent }
    function LayoutButton(const HTMLButton: string; Attributes: TLayoutAttributes): string;
    function LayoutField(const HTMLField: string; Attributes: TLayoutAttributes): string;
    function LayoutLabelAndField(const HTMLLabel, HTMLField: string; Attributes: TLayoutAttributes): string;
    function LayoutTable(const HTMLTable: string; Attributes: TLayoutAttributes): string;

    function ImplLayoutButton(const HTMLButton: string; Attributes: TLayoutAttributes): string; virtual; abstract;
    function ImplLayoutField(const HTMLField: string; Attributes: TLayoutAttributes): string; virtual; abstract;
    function ImplLayoutLabelAndField(const HTMLLabel, HTMLField: string; Attributes: TLayoutAttributes): string; virtual; abstract;
    function ImplLayoutTable(const HTMLTable: string; Attributes: TLayoutAttributes): string; virtual; abstract;
  public
    constructor Create(AParentLayout: TLayout);
    property ParentLayout: TLayout read FParentLayout;
  end;

  TWebComponentList = class(TObject, IWebComponentContainer)
  private
    FParentComponent: TComponent;
    FList: TList;
  protected
    function GetCount: Integer;
    function GetComponent(Index: Integer): TComponent;
    function NewComponent(AOwner: TComponent): TComponent; virtual;
    { IUnknown }
    function QueryInterface(const IID: TGUID; out Obj): HResult; virtual; stdcall;
    function _AddRef: Integer; stdcall;
    function _Release: Integer; stdcall;
    { IWebComponentContainer }
    function IWebComponentContainer.GetComponentCount = WebComponentContainer_GetComponentCount;
    function IWebComponentContainer.GetComponent = WebComponentContainer_GetComponent;
    function WebComponentContainer_GetComponentCount: Integer;
    function WebComponentContainer_GetComponent(I: Integer): TComponent;
  public
    constructor Create(AParentComponent: TComponent);
    destructor Destroy; override;
    procedure Add(Component: TComponent);
    procedure SetComponentIndex(Component: TComponent; Value: Integer);
    procedure Clear;
    function IndexOf(Component: TComponent): Integer;
    procedure Remove(Component: TComponent);
    property Count: Integer read GetCount;
    property WebComponents[Index: Integer]: TComponent read GetComponent; default;
    property ParentComponent: TComponent read FParentComponent;
  end;

  TEnumWebComponentsProc = procedure (WebComponentClass: TComponentClass;
    Editor: TObject; Info: Pointer) of object;

  TWebComponentsEditorHelper = class(TObject, IWebComponentEditorHelper)
  protected
    { IUnknown }
    function QueryInterface(const IID: TGUID; out Obj): HResult; virtual; stdcall;
    function _AddRef: Integer; stdcall;
    function _Release: Integer; stdcall;
    { IWebComponentEditorHelper }
    function CanAddClassHelper(AEditor: TComponent; AParent: TComponent; AClass: TClass): Boolean;
    function ImplCanAddClassHelper(AEditor: TComponent; AParent: TComponent; AClass: TClass): Boolean; virtual;
  end;

const
  RegisterWebComponentsProc: procedure (
    const AClasses: array of TComponentClass; Editor: TObject) = nil;
  UnRegisterWebComponentsProc: procedure (const AClasses: array of TComponentClass) = nil;
  EnumRegisteredWebComponentsProc: procedure (Proc: TEnumWebComponentsProc; Info: Pointer) = nil;
  FindWebComponentEditorHelperProc: function (AClass: TClass): TObject = nil;

procedure RegisterWebComponents(const AClasses: array of TComponentClass; Editor: TObject = nil);
procedure UnRegisterWebComponents(const AClasses: array of TComponentClass);
procedure EnumRegisteredWebComponents(Proc: TEnumWebComponentsProc; Info: Pointer);
function FindWebComponentEditorHelper(AClass: TClass): TObject;

implementation

uses Windows, Messages, DbConsts, MidConst, ActiveX, ComObj, WebConst, sysutils, DbWeb, Forms,
  WbmConst;

procedure RegisterWebComponents(
  const AClasses: array of TComponentClass; Editor: TObject = nil);
begin
  if Assigned(RegisterWebComponentsProc) then
    RegisterWebComponentsProc(AClasses, Editor) else
    raise Exception.CreateRes(@SInvalidWebComponentsRegistration);
end;

procedure UnRegisterWebComponents(const AClasses: array of TComponentClass);
begin
  if Assigned(UnRegisterWebComponentsProc) then
    UnRegisterWebComponentsProc(AClasses);
end;

procedure EnumRegisteredWebComponents(Proc: TEnumWebComponentsProc; Info: Pointer);
begin
  if Assigned(EnumRegisteredWebComponentsProc) then
    EnumRegisteredWebComponentsProc(Proc, Info) else
    raise Exception.CreateRes(@SInvalidWebComponentsEnumeration);
end;

function FindWebComponentEditorHelper(AClass: TClass): TObject;
begin
  if Assigned(FindWebComponentEditorHelperProc) then
    Result := FindWebComponentEditorHelperProc(AClass)
  else
    Result := nil;
end;

{ TWebComponentList }

function TWebComponentList._AddRef: Integer;
begin
  Result := -1;
end;

function TWebComponentList._Release: Integer;
begin
  Result := -1;
end;

procedure TWebComponentList.Add(Component: TComponent);
var
  WebComponentIntf: IWebComponent;
begin
  FList.Add(Component);
  Component.GetInterface(IWebComponent, WebComponentIntf);
  WebComponentIntf.ComponentList := Self;
end;

procedure TWebComponentList.Clear;
var
  F: TComponent;
  WebComponentIntf: IWebComponent;
begin
  while FList.Count > 0 do
  begin
    F := FList.Last;
    F.GetInterface(IWebComponent, WebComponentIntf);
    Assert(Assigned(WebComponentIntf), 'Interface not found');
    WebComponentIntf.ComponentList := nil;
    WebComponentIntf := nil;
    F.Free;
    FList.Delete(FList.Count-1);
  end;
end;

constructor TWebComponentList.Create(AParentComponent: TComponent);
begin
  inherited Create;
  FList := TList.Create;
  FParentComponent := AParentComponent;
end;

destructor TWebComponentList.Destroy;
begin
  if FList <> nil then
    Clear;
  FList.Free;
  inherited;
end;

function TWebComponentList.GetComponent(Index: Integer): TComponent;
begin
  Result := FList[Index];

end;

function TWebComponentList.GetCount: Integer;
begin
  Result := FList.Count;
end;

function TWebComponentList.IndexOf(Component: TComponent): Integer;
begin
  Result := FList.IndexOf(Component);
end;

function TWebComponentList.QueryInterface(const IID: TGUID; out Obj): HResult;
begin
  if GetInterface(IID, Obj) then Result := S_OK
  else Result := E_NOINTERFACE

end;

procedure TWebComponentList.Remove(Component: TComponent);
var
  WebComponentIntf: IWebComponent;
begin
  FList.Remove(Component);
  Component.GetInterface(IWebComponent, WebComponentIntf);
  WebComponentIntf.ComponentList := nil;
end;

procedure TWebComponentList.SetComponentIndex(Component: TComponent;
  Value: Integer);
var
  CurIndex, Count: Integer;
begin
  CurIndex := FList.IndexOf(Component);
  if CurIndex >= 0 then
  begin
    Count := FList.Count;
    if Value < 0 then Value := 0;
    if Value >= Count then Value := Count - 1;
    if Value <> CurIndex then
    begin
      FList.Delete(CurIndex);
      FList.Insert(Value, Component);
    end;
  end;
end;

function TWebComponentList.WebComponentContainer_GetComponent(
  I: Integer): TComponent;
begin
  Result := WebComponents[I];

end;

function TWebComponentList.WebComponentContainer_GetComponentCount: Integer;
begin
  Result := Count;

end;

function TWebComponentList.NewComponent(AOwner: TComponent): TComponent;
begin
  Assert(False);
  // Delegate to parent
  Result := nil;
end;

{ TWebContentOptions }

constructor TWebContentOptions.Create(AFlags: TWebContentFlags);
begin
  inherited Create;
  FFlags := AFlags;
end;

{ TLayoutWebContent }

function TLayoutWebContent.LayoutButton(const HTMLButton: string; Attributes: TLayoutAttributes): string;
begin
  Result := ImplLayoutButton(HTMLButton, Attributes);
end;

function TLayoutWebContent.LayoutField(const HTMLField: string; Attributes: TLayoutAttributes): string;
begin
  Result := ImplLayoutField(HTMLField, Attributes);
end;

function TLayoutWebContent.LayoutLabelAndField(const HTMLLabel,
  HTMLField: string; Attributes: TLayoutAttributes): string;
begin
  Result := ImplLayoutLabelAndField(HTMLLabel, HTMLField, Attributes);
end;

function TLayoutWebContent._AddRef: Integer;
begin
  Result := -1;
end;

function TLayoutWebContent._Release: Integer;
begin
  Result := -1;
end;

function TLayoutWebContent.QueryInterface(const IID: TGUID;
  out Obj): HResult;
begin
  if GetInterface(IID, Obj) then Result := S_OK
  else Result := E_NOINTERFACE
end;

constructor TLayoutWebContent.Create(AParentLayout: TLayout);
begin
  inherited Create;
  FParentLayout := AParentLayout;
end;


function TLayoutWebContent.LayoutTable(const HTMLTable: string; Attributes: TLayoutAttributes): string;
begin
  Result := ImplLayoutTable(HTMLTable, Attributes);
end;

{ TLayoutAttributes }

constructor TLayoutAttributes.Create;
begin
  LabelPosition := lposLeft;
end;

{ TWebComponentsEditor }

function TWebComponentsEditorHelper.CanAddClassHelper(AEditor: TComponent; AParent: TComponent;
  AClass: TClass): Boolean;
begin
  Result := ImplCanAddClassHelper(AEditor, AParent, AClass);
end;

function TWebComponentsEditorHelper.ImplCanAddClassHelper(AEditor: TComponent; AParent: TComponent;
  AClass: TClass): Boolean;
begin
  Result := False;
end;

function TWebComponentsEditorHelper._AddRef: Integer;
begin
  Result := -1;
end;

function TWebComponentsEditorHelper._Release: Integer;
begin
  Result := -1;
end;

function TWebComponentsEditorHelper.QueryInterface(const IID: TGUID;
  out Obj): HResult;
begin
  if GetInterface(IID, Obj) then Result := S_OK
  else Result := E_NOINTERFACE
end;

end.
