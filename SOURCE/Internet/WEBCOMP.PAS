{ *************************************************************************** }
{                                                                             }
{ Kylix and Delphi Cross-Platform Visual Component Library                    }
{ Internet Application Runtime                                                }
{                                                                             }
{ Copyright (C) 1999, 2001 Borland Software Corporation                       }
{                                                                             }
{ Licensees holding a valid Borland No-Nonsense License for this Software may }
{ use this file in accordance with such license, which appears in the file    }
{ license.txt that came with this Software.                                   }
{                                                                             }
{ *************************************************************************** }


unit WebComp;

interface

uses Classes, HTTPApp, HTTPProd, Masks;

type

  IProducerEditorViewSupport = interface
  ['{72B13C95-E75C-11D4-A549-00C04F6BB853}']
    function HasScriptView: Boolean;
    function HasXMLBrowserView: Boolean;
    function HasXSLBrowserView: Boolean;
    function HasHTMLBrowserView: Boolean;
    function GetXMLData(var Owned: Boolean): TStream;
    function GetXSLData(var Owned: Boolean): TStream;
    function GetTemplateFileType: string;
  end;

  IGetXMLStream = interface
  ['{646363DA-6311-4750-A187-A9B416B7CAF8}']
    function GetXMLStream(var Owned: Boolean): TStream;
  end;

  TWebContentOptions = class;

  ISetWebContentOptions = interface
  ['{7FD48995-5814-11D4-A492-00C04F6BB853}']
    procedure SetWebContentOptions(AOptions: TWebContentOptions);
  end;

  INotifyWebActivate = interface
  ['{CE18BE42-1358-11D4-ABF4-F18FFAD12B3C}']
    procedure NotifyActivate;
    procedure NotifyDeactivate;
  end;

  INotifyActivateModule = interface
  ['{02B08C86-80D4-42D7-A84A-C0A09F42BDD1}']
    procedure NotifyActivateModule(AWebModule: TComponent);
    procedure NotifyDeactivateModule(AWebModule: TComponent);
  end;

  IWebVariablesContainerName = interface
  ['{14A3B5AC-7A5C-4279-BB7C-B3D6E2EDD7F1}']
    function GetContainerName: string;
    property ContainerName: string read GetContainerName;
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

  IAddFieldsEditor = interface
  ['{73506463-4D5E-11D4-A48B-00C04F6BB853}']
    function GetNewFieldPrefix: string;
    function GetAddFieldsItem: string;
    function GetAddAllFieldsItem: string;
    function GetAddFieldsDlgCaption: string;
  end;

  IGetWebComponentNodeName = interface
  ['{CB84BC91-4C65-11D4-A48B-00C04F6BB853}']
    function GetWebComponentNodeName: string;
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

  ITopLevelWebComponent = interface
  ['{B591F71D-94D0-11D4-A4EA-00C04F6BB853}']
  end;

  IGetWebComponentList = interface
  ['{5CDEB0F2-EEF9-11D2-AFB1-00C04FB16EC3}']
    function GetComponentList: TObject;
    function GetDefaultComponentList: TObject;
  end;

  TWebContentFlag = (coNoScript, coLocalPaths, coNoExecuteScript);
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

  TWebComponentList = class(TPersistent, IWebComponentContainer)
  private
    FParentComponent: TComponent;
    FList: TList;
    FOnChange: TNotifyEvent;
    FLockNotifyCount: Integer;
    FNotifyPending: Boolean;
  protected
    function  GetOwner: TPersistent; override;
    procedure Changed;
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
    procedure LockNotify;
    procedure UnlockNotify;
    function NotifyLocked: Boolean;
    procedure Add(Component: TComponent);
    procedure SetComponentIndex(Component: TComponent; Value: Integer);
    procedure Clear;
    function IndexOf(Component: TComponent): Integer;
    procedure Remove(Component: TComponent);
    property Count: Integer read GetCount;
    property WebComponents[Index: Integer]: TComponent read GetComponent; default;
    property ParentComponent: TComponent read FParentComponent;
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
  end;

  TWebComponentClassDescription = class(TObject)
    ComponentClass: TComponentClass;
    ComponentClassName: string;
    Editor: TObject;
    FrameClass: Boolean;
  end;

  TEnumWebComponentsProc = procedure (WebComponentClass: TWebComponentClassDescription;
    Info: Pointer) of object;

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

  TGetComponentListEvent = procedure(Sender: TObject; var AList: TWebComponentList) of object;
  TSetComponentListEvent = procedure(Sender: TObject; AList: TWebComponentList) of object;
  TWebContainerComponentHelper = class(TObject)
  private
    FComponent: TComponent;
    FWebComponents: TWebComponentList;
    FOnGetDefaultComponentList: TGetComponentListEvent;
    FOnSetDefaultComponentList: TSetComponentListEvent;
  protected
    { IGetWebComponentsList }
    function GetComponentList: TObject;
    function GetDefaultComponentList: TObject;


    function GetDefaultWebComponents: TWebComponentList;
    procedure SetDefaultWebComponents(AList: TWebComponentList);
    property OnGetDefaultComponentList: TGetComponentListEvent read
      FOnGetDefaultComponentList write FOnGetDefaultComponentList;
    property OnSetDefaultComponentList: TSetComponentListEvent read
      FOnSetDefaultComponentList write FOnSetDefaultComponentList;
  public
    procedure GetChildren(Proc: TGetChildProc; Root: TComponent);
    procedure SetChildOrder(Component: TComponent; Order: Integer);
    constructor Create(AComponent: TComponent;
      AOnGetDefaultComponentList: TGetComponentListEvent;
      AOnSetDefaultComponentList: TSetComponentListEvent);
    destructor Destroy; override;
    property Webcomponents: TWebComponentList read FWebComponents;
    property DefaultWebComponents: TWebComponentList read GetDefaultWebComponents write SetDefaultWebComponents;
  end;

  TWebContainerComponent = class(TComponent, IGetWebComponentList)
  private
    FWebContainerComponentHelper: TWebContainerComponentHelper;
    procedure OnGetDefaultComponentList(Sender: TObject;
      var AList: TWebComponentList);
    procedure OnSetDefaultComponentList(Sender: TObject;
      AList: TWebComponentList);
  protected
    { IGetWebComponentsList }
    function ImplGetDefaultComponentList: TObject; virtual;
    procedure GetChildren(Proc: TGetChildProc; Root: TComponent); override;
    procedure SetChildOrder(Component: TComponent; Order: Integer); override;
    property WebContainerComponentHelper: TWebContainerComponentHelper read FWebContainerComponentHelper
      implements IGetWebComponentList;
    function GetWebComponents: TWebComponentList;
    function GetDefaultWebComponents: TWebComponentList; virtual;
    procedure SetDefaultWebComponents(AList: TWebComponentList); virtual;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  end;

  TWebContainedComponentHelper = class(TObject)
  private
    FComponent: TComponent;
    FDefaultField: Boolean;
    FContainerList: TWebComponentList;
    FWebParent: TComponent;
    FOnParentChanged: TNotifyEvent;
  protected
    { IWebComponent }
    function GetIndex: Integer;
    procedure SetIndex(Value: Integer);
    procedure SetContainer(Container: TWebComponentContainer);
    function GetContainer: TWebComponentContainer;
    procedure SetComponentList(List: TObject);

    procedure SetWebParent(Value: TComponent);
    procedure ParentChanged; virtual;
    property OnParentChanged: TNotifyEvent read FOnParentChanged write FOnParentChanged;
  public
    constructor Create(AComponent: TComponent;
      AOnParentChanged: TNotifyEvent);
    destructor Destroy; override;
    function IsDefaultField: Boolean;
    property WebParent: TComponent read FWebParent;
    property ContainerList: TWebComponentList read FContainerList;
  end;

  TWebContainedComponent = class(TComponent, IWebComponent)
  private
    FWebContainedComponentHelper: TWebContainedComponentHelper;
    procedure OnParentChanged(Sender: TObject);
    function GetWebParent: TComponent;
  protected
    procedure SetParentComponent(AParent: TComponent); override;
    procedure SetWebParent(Value: TComponent);
    procedure ReadState(Reader: TReader); override;
    function IsDefaultField: Boolean; virtual;
    procedure ParentChanged; virtual;
    function GetContainerList: TWebComponentList;
    property WebContainedComponentHelper: TWebContainedComponentHelper read FWebContainedComponentHelper
      implements IWebComponent;
    property WebParent: TComponent read GetWebParent;
  public
    function GetParentComponent: TComponent; override;
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function HasParent: Boolean; override;
  end;

  TWebContainedContainerComponent = class(TComponent, IGetWebComponentList, IWebComponent)
  private
    FWebContainerComponentHelper: TWebContainerComponentHelper;
    FWebContainedComponentHelper: TWebContainedComponentHelper;
    procedure OnParentChanged(Sender: TObject);
    procedure OnGetDefaultComponentList(Sender: TObject;
      var AList: TWebComponentList);
    procedure OnSetDefaultComponentList(Sender: TObject;
      AList: TWebComponentList);
    function GetWebParent: TComponent;
  protected
    procedure SetParentComponent(AParent: TComponent); override;
    procedure SetWebParent(Value: TComponent);
    procedure ReadState(Reader: TReader); override;
    function IsDefaultField: Boolean; virtual;
    procedure ParentChanged; virtual;

    function ImplGetDefaultComponentList: TObject; virtual;
    procedure GetChildren(Proc: TGetChildProc; Root: TComponent); override;
    procedure SetChildOrder(Component: TComponent; Order: Integer); override;
    property WebContainerComponentHelper: TWebContainerComponentHelper read FWebContainerComponentHelper
      implements IGetWebComponentList;
    property WebContainedComponentHelper: TWebContainedComponentHelper read FWebContainedComponentHelper
      implements IWebComponent;

    function GetWebComponents: TWebComponentList;
    function GetContainerList: TWebComponentList;
    function GetDefaultWebComponents: TWebComponentList; virtual;
    procedure SetDefaultWebComponents(AList: TWebComponentList); virtual;
    property WebParent: TComponent read GetWebParent;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function GetParentComponent: TComponent; override;
    function HasParent: Boolean; override;
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
function QualifyFileName(const AFileName: string): string;
procedure ValidateWebParent(AComponent: TComponent; AParent: TComponent);
function DesigningComponent(AComponent: TComponent): Boolean;

implementation

{$IFDEF MSWINDOWS}
uses Windows, Messages, SysUtils, WebConst, WbmConst, WebCntxt;
{$ENDIF}
{$IFDEF LINUX}
uses SysUtils, WebConst, WebCntxt;
{$ENDIF}

function ModulePath: string;
var
  ModuleName: string;
begin
  if Assigned(GetModuleFileNameProc) then
  begin
    ModuleName := GetModuleFileNameProc;
    Result := ExtractFilePath(ModuleName);
  end
  else
    Result := '';
end;

function DirExpandFileName(const Dir, FileName: string): string;
var
  I, J: Integer;
  LastWasPathDelim: Boolean;
  TempName: string;
  Drive: string;
begin
  Result := '';
  if Length(Filename) = 0 then Exit;

  Drive := ExtractFileDrive(FileName);
  if Drive = '' then
  begin
    // FileName does not include a drive
    // Save the drive of the current directory.  Prepend this to the path later.
    Drive := ExtractFileDrive(Dir);
    if FileName[1] = PathDelim then
      // Have a root path
      TempName := FileName
    else
      // Use the path of the current directory to make a root path
      TempName := Copy(Dir, Length(Drive)+1, MaxInt) + PathDelim + FileName
  end
  else
  begin
    // FileName has a drive.  Prepend this to the path later.
    // Note that a filename with a drive but a relative path (such as c:temp) is not supported.
    TempName := Copy(FileName, Length(Drive)+1, MaxInt);
    if Length(TempName) = 0 then
    begin
      // Don't continue if there is nothing more than a drive.
      Result := FileName;
      Exit;
    end;
  end;

  I := 1;
  J := 1;

  LastWasPathDelim := False;

  while I <= Length(TempName) do
  begin
    case TempName[I] of
      PathDelim:
        if J < I then
        begin
          // Check for consecutive 'PathDelim' characters and skip them if present
          if (I = 1) or (TempName[I - 1] <> PathDelim) then
            Result := Result + Copy(TempName, J, I - J);
          J := I;
          // Set a flag indicating that we just processed a path delimiter
          LastWasPathDelim := True;
        end;
      '.':
        begin
          // If the last character was a path delimiter then this '.' is
          // possibly a relative path modifier
          if LastWasPathDelim then
          begin
            // Check if the path ends in a '.'
            if I < Length(TempName) then
            begin
              // If the next character is another '.' then this may be a relative path
              // except if there is another '.' after that one.  In this case simply
              // treat this as just another filename.
              if (TempName[I + 1] = '.') and
                ((I + 1 >= Length(TempName)) or (TempName[I + 2] <> '.')) then
              begin
                // Don't attempt to backup past the Root dir
                if Length(Result) > 1 then
                  // For the purpose of this excercise, treat the last dir as a
                  // filename so we can use this function to remove it
                  Result := ExtractFilePath(ExcludeTrailingPathDelimiter(Result));
                J := I;
              end
              // Simply skip over and ignore any 'current dir' constrcucts, './'
              // or the remaining './' from a ../ constrcut.
              else if TempName[I + 1] = PathDelim then
              begin
                Result := IncludeTrailingPathDelimiter(Result);
                if TempName[I] in LeadBytes then
                  Inc(I, StrCharLength(@TempName[I]))
                else
                Inc(I);
                J := I + 1;
              end else
                // If any of the above tests fail, then this is not a 'current dir' or
                // 'parent dir' construct so just clear the state and continue.
                LastWasPathDelim := False;
            end else
            begin
              // Don't let the expanded path end in a 'PathDelim' character
              Result := ExcludeTrailingPathDelimiter(Result);
              J := I + 1;
            end;
          end;
        end;
    else
      LastWasPathDelim := False;
    end;
    if TempName[I] in LeadBytes then
      Inc(I, StrCharLength(@TempName[I]))
    else
    Inc(I);
  end;
  // This will finally append what is left
  if (I - J > 1) or (TempName[I] <> PathDelim) then
    Result := Result + Copy(TempName, J, I - J);
  Result := Drive + Result;
end;

function QualifyFileName(const AFileName: string): string;
begin
  if DesignerFileManager <> nil then
    Result := DesignerFileManager.QualifyFileName(AFileName)
  else
    Result := DirExpandFileName(ModulePath, AFileName);
end;

// csDesigning flag is not set for default (owner = nil) components.  This
// function finds an owned component.
function DesigningComponent(AComponent: TComponent): Boolean;
begin
  Assert(AComponent <> nil);
  while (AComponent.Owner = nil) and (AComponent.GetParentComponent <> nil) do
    AComponent := AComponent.GetParentComponent;
  Result := csDesigning in AComponent.ComponentState;
end;

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
  if Supports(IInterface(AParent), IWebComponentEditor, Editor) then
    if not Editor.CanAddClass(AParent, AComponent.ClassType) then
      raise EComponentError.CreateRes(@sInvalidParent);
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
  Supports(IInterface(Component), IWebComponent, WebComponentIntf);
  WebComponentIntf.ComponentList := Self;
  Changed;
end;

procedure TWebComponentList.Changed;
begin
  if not NotifyLocked then
  begin
    FNotifyPending := False;
    if Assigned(OnChange) then OnChange(Self)
  end
  else
    FNotifyPending := True;
end;

procedure TWebComponentList.Clear;
var
  F: TComponent;
  WebComponentIntf: IWebComponent;
begin
  F := nil;
  while FList.Count > 0 do
  begin
    F := FList.Last;
    Supports(IInterface(F), IWebComponent, WebComponentIntf);
    Assert(Assigned(WebComponentIntf), 'Interface not found');
    WebComponentIntf.ComponentList := nil;
    WebComponentIntf := nil;
    F.Free;
    FList.Delete(FList.Count-1);
  end;
  if Assigned(F) then
    Changed;
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
  Supports(IInterface(Component), IWebComponent, WebComponentIntf);
  WebComponentIntf.ComponentList := nil;
  Changed;
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
      Changed;
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

function TWebComponentList.GetOwner: TPersistent;
begin
  Result := FParentComponent;
end;

procedure TWebComponentList.LockNotify;
begin
  Inc(FLockNotifyCount);
end;

function TWebComponentList.NotifyLocked: Boolean;
begin
  Result := FLockNotifyCount <> 0;
end;

procedure TWebComponentList.UnlockNotify;
begin
  Dec(FLockNotifyCount);
  Assert(FLockNotifyCount >= 0);
  if FLockNotifyCount = 0 then
    if FNotifyPending then
      Changed;
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

{ TWebComponentsEditorHelper }

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

{ TWebContainerComponentHelper }

constructor TWebContainerComponentHelper.Create(AComponent: TComponent;
      AOnGetDefaultComponentList: TGetComponentListEvent;
      AOnSetDefaultComponentList: TSetComponentListEvent);
begin
  inherited Create;
  FComponent := AComponent;
  Assert(FComponent <> nil);
  FOnGetDefaultComponentList := AOnGetDefaultComponentList;
  FOnSetDefaultComponentList := AOnSetDefaultComponentList;
  FWebComponents := TWebComponentList.Create(FComponent);
end;

destructor TWebContainerComponentHelper.Destroy;
begin
  inherited;
  FWebComponents.Free;
end;

procedure TWebContainerComponentHelper.GetChildren(Proc: TGetChildProc; Root: TComponent);
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

function TWebContainerComponentHelper.GetComponentList: TObject;
begin
  Result := FWebComponents;
end;

function TWebContainerComponentHelper.GetDefaultComponentList: TObject;
begin
  Result := GetDefaultWebComponents;
end;

function TWebContainerComponentHelper.GetDefaultWebComponents: TWebComponentList;
begin
  if Assigned(OnGetDefaultComponentList) then
    OnGetDefaultComponentList(Self, Result)
  else
  begin
    Assert(False, 'No default components list');
    Result := nil;
  end;
end;

procedure TWebContainerComponentHelper.SetChildOrder(Component: TComponent;
  Order: Integer);
var
  Intf: IWebComponent;
begin
  if FWebComponents.IndexOf(Component) >= 0 then
    if Supports(IInterface(Component), IWebComponent, Intf) then
      Intf.Index := Order
    else
      Assert(False, 'Interface not supported');
end;

procedure TWebContainerComponentHelper.SetDefaultWebComponents(
  AList: TWebComponentList);
begin
  if Assigned(OnSetDefaultComponentList) then
    OnSetDefaultComponentList(Self, AList)
  else
    Assert(False); // No set components list

end;

{ TWebContainerComponent }

constructor TWebContainerComponent.Create(AOwner: TComponent);
begin
  inherited;
  FWebContainerComponentHelper := TWebContainerComponentHelper.Create(Self,
     OnGetDefaultComponentList, OnSetDefaultComponentList);
end;

function TWebContainerComponent.GetWebComponents: TWebComponentList;
begin
  Result := FWebContainerComponentHelper.FWebComponents;
end;

destructor TWebContainerComponent.Destroy;
begin
  inherited;
  FWebContainerComponentHelper.Free;
end;

procedure TWebContainerComponent.GetChildren(Proc: TGetChildProc; Root: TComponent);
begin
  FWebContainerComponentHelper.GetChildren(Proc, Root);
end;

procedure TWebContainerComponent.OnGetDefaultComponentList(Sender: TObject; var AList: TWebComponentList);
begin
  AList := GetDefaultWebComponents;
end;

function TWebContainerComponent.ImplGetDefaultComponentList: TObject;
begin
  Result := GetDefaultWebComponents;
end;

procedure TWebContainerComponent.SetChildOrder(Component: TComponent;
  Order: Integer);
begin
  FWebContainerComponentHelper.SetChildOrder(Component, Order);
end;

function TWebContainerComponent.GetDefaultWebComponents: TWebComponentList;
begin
  Assert(False, 'No default components list');
  Result := nil;
end;

procedure TWebContainerComponent.OnSetDefaultComponentList(Sender: TObject;
  AList: TWebComponentList);
begin
  SetDefaultWebComponents(AList);
end;

procedure TWebContainerComponent.SetDefaultWebComponents(
  AList: TWebComponentList);
begin
  Assert(False, 'No default components list');
end;

{ TWebContainedComponentHelper }

function TWebContainedComponentHelper.GetIndex: Integer;
begin
  Result := FContainerList.IndexOf(FComponent);
end;

procedure TWebContainedComponentHelper.SetContainer(Container: TWebComponentContainer);
begin
  SetWebParent((Container as TWebComponentList).ParentComponent);
end;

procedure TWebContainedComponentHelper.SetIndex(Value: Integer);
begin
  FContainerList.SetComponentIndex(FComponent, Value)
end;

procedure TWebContainedComponentHelper.SetWebParent(Value: TComponent);
var
  List: IGetWebComponentList;
  Designing: Boolean;
begin
  if Value <> FWebParent then
  begin
    if Value <> nil then
      Designing := DesigningComponent(Value)
    else
      Designing := DesigningComponent(FComponent);
    if Assigned(Value) and Designing then
      ValidateWebParent(FComponent, Value);
    if FWebParent <> nil then
    begin
      Supports(IInterface(FWebParent), IGetWebComponentList, List);
      if IsDefaultField then
        (List.GetDefaultComponentList as TWebComponentList).Remove(FComponent)
      else
        (List.GetComponentList as TWebComponentList).Remove(FComponent)
    end;
    if Value <> nil then
    begin
      Supports(IInterface(Value), IGetWebComponentList, List);
      if not Assigned(List) then
        raise Exception.CreateResFmt(@sInvalidWebParent, [Value.Classname]);
      if IsDefaultField then
         (List.GetDefaultComponentList as TWebComponentList).Add(FComponent)
      else
        (List.GetComponentList as TWebComponentList).Add(FComponent)
    end;
    FWebParent := Value;
    ParentChanged;
  end;
end;

destructor TWebContainedComponentHelper.Destroy;
begin
  inherited;
  if FContainerList <> nil then
    FContainerList.Remove(FComponent);
end;

procedure TWebContainedComponentHelper.SetComponentList(List: TObject);
begin
  Assert((List = nil) or (List is TWebComponentList));
  FContainerList := TWebComponentList(List);
end;

function TWebContainedComponentHelper.GetContainer: TWebComponentContainer;
var
  List: IGetWebComponentList;
begin
  if Supports(IInterface(FWebParent), IGetWebComponentList, List) then
    if IsDefaultField then
      Result := List.GetDefaultComponentList
    else
      Result := List.GetComponentList
  else
    Result := nil;
end;

function TWebContainedComponentHelper.IsDefaultField: Boolean;
begin
  Result := FDefaultField;
end;

constructor TWebContainedComponentHelper.Create(AComponent: TComponent;
      AOnParentChanged: TNotifyEvent);
begin
  inherited Create;
  FComponent := AComponent;
  FDefaultField := FComponent.Owner = nil;
  FOnParentChanged := AOnParentChanged;
end;

procedure TWebContainedComponentHelper.ParentChanged;
begin
  if Assigned(OnParentChanged) then
    OnParentChanged(Self);
end;

{ TWebContainedComponent }

function TWebContainedComponent.GetParentComponent: TComponent;
begin
  if FWebContainedComponentHelper.WebParent <> nil then
    Result := FWebContainedComponentHelper.WebParent else
    Result := inherited GetParentComponent;
end;

function TWebContainedComponent.HasParent: Boolean;
begin
  if FWebContainedComponentHelper.WebParent <> nil then
    Result := True else
    Result := inherited HasParent;
end;

procedure TWebContainedComponent.ReadState(Reader: TReader);
begin
  inherited ReadState(Reader);
  FWebContainedComponentHelper.SetWebParent(Reader.Parent);
end;

procedure TWebContainedComponent.SetParentComponent(AParent: TComponent);
begin
  if not (csLoading in ComponentState) then
    FWebContainedComponentHelper.SetWebParent(AParent);
end;

destructor TWebContainedComponent.Destroy;
begin
  inherited;
  FWebContainedComponentHelper.Free;
end;

function TWebContainedComponent.IsDefaultField: Boolean;
begin
  Result := FWebContainedComponentHelper.IsDefaultField;
end;

constructor TWebContainedComponent.Create(AOwner: TComponent);
begin
  inherited;
  FWebContainedComponentHelper := TWebContainedComponentHelper.Create(Self,
    OnParentChanged);
end;

procedure TWebContainedComponent.ParentChanged;
begin
  // Do nothing
end;

procedure TWebContainedComponent.OnParentChanged(Sender: TObject);
begin
  ParentChanged;
end;

procedure TWebContainedComponent.SetWebParent(Value: TComponent);
begin
  FWebContainedComponentHelper.SetWebParent(Value)
end;

function TWebContainedComponent.GetContainerList: TWebComponentList;
begin
  Result := FWebContainedComponentHelper.ContainerList;
end;

function TWebContainedComponent.GetWebParent: TComponent;
begin
  Result := FWebContainedComponentHelper.WebParent;
end;

{ TWebContainedContainerComponent }

constructor TWebContainedContainerComponent.Create(AOwner: TComponent);
begin
  inherited;
  FWebContainerComponentHelper := TWebContainerComponentHelper.Create(Self,
    OnGetDefaultComponentList, OnSetDefaultComponentList);
  FWebContainedComponentHelper := TWebContainedComponentHelper.Create(Self,
    OnParentChanged);
end;

destructor TWebContainedContainerComponent.Destroy;
begin
  inherited;
  FWebContainerComponentHelper.Free;
  FWebContainedComponentHelper.Free;
end;

procedure TWebContainedContainerComponent.GetChildren(Proc: TGetChildProc; Root: TComponent);
begin
  FWebContainerComponentHelper.GetChildren(Proc, Root);
end;

procedure TWebContainedContainerComponent.OnGetDefaultComponentList(Sender: TObject; var AList: TWebComponentList);
begin
  AList := GetDefaultWebComponents;
end;

function TWebContainedContainerComponent.ImplGetDefaultComponentList: TObject;
begin
  Result := GetDefaultWebComponents;
end;

procedure TWebContainedContainerComponent.SetChildOrder(Component: TComponent;
  Order: Integer);
begin
  FWebContainerComponentHelper.SetChildOrder(Component, Order);
end;

function TWebContainedContainerComponent.GetWebComponents: TWebComponentList;
begin
  Result := FWebContainerComponentHelper.FWebComponents;
end;

function TWebContainedContainerComponent.GetParentComponent: TComponent;
begin
  if FWebContainedComponentHelper.WebParent <> nil then
    Result := FWebContainedComponentHelper.WebParent else
    Result := inherited GetParentComponent;
end;

function TWebContainedContainerComponent.HasParent: Boolean;
begin
  if FWebContainedComponentHelper.WebParent <> nil then
    Result := True else
    Result := inherited HasParent;
end;

procedure TWebContainedContainerComponent.ReadState(Reader: TReader);
begin
  inherited ReadState(Reader);
  FWebContainedComponentHelper.SetWebParent(Reader.Parent);
end;

procedure TWebContainedContainerComponent.SetParentComponent(AParent: TComponent);
begin
  if not (csLoading in ComponentState) then
    FWebContainedComponentHelper.SetWebParent(AParent);
end;

function TWebContainedContainerComponent.IsDefaultField: Boolean;
begin
  Result := FWebContainedComponentHelper.IsDefaultField;
end;

procedure TWebContainedContainerComponent.OnSetDefaultComponentList(Sender: TObject;
  AList: TWebComponentList);
begin
  SetDefaultWebComponents(AList);
end;

procedure TWebContainedContainerComponent.ParentChanged;
begin
  // Do nothing
end;

procedure TWebContainedContainerComponent.OnParentChanged(Sender: TObject);
begin
  ParentChanged;
end;

procedure TWebContainedContainerComponent.SetWebParent(Value: TComponent);
begin
  FWebContainedComponentHelper.SetWebParent(Value)
end;

function TWebContainedContainerComponent.GetContainerList: TWebComponentList;
begin
  Result := FWebContainedComponentHelper.ContainerList;
end;

function TWebContainedContainerComponent.GetDefaultWebComponents: TWebComponentList;
begin
  Assert(False, 'No default components list');
  Result := nil;
end;

function TWebContainedContainerComponent.GetWebParent: TComponent;
begin
  Result := FWebContainedComponentHelper.WebParent;
end;

procedure TWebContainedContainerComponent.SetDefaultWebComponents(
  AList: TWebComponentList);
begin
  Assert(False, 'No default components list');
end;
 
end.
