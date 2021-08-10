{ ********************************************************************** }
{                                                                        }
{ Delphi and Kylix Cross-Platform Open Tools API                         }
{                                                                        }
{ Copyright (C) 1995, 2001 Borland Software Corporation                  }
{                                                                        }
{ All Rights Reserved.                                                   }
{                                                                        }
{ ********************************************************************** }


unit DesignEditors;

interface

uses
  Types, SysUtils, Classes, TypInfo, Variants, DesignIntf, DesignMenus
  {$IFDEF LINUX}
  , QtThread
  {$ENDIF LINUX}
  ;

{ Property Editors }

type
  TInstProp = record
    Instance: TPersistent;
    PropInfo: PPropInfo;
  end;

  PInstPropList = ^TInstPropList;
  TInstPropList = array[0..1023] of TInstProp;

  TPropertyEditor = class(TBasePropertyEditor, IProperty)
  private
    FDesigner: IDesigner;
    FPropList: PInstPropList;
    FPropCount: Integer;
    function GetPrivateDirectory: string;
  protected
    procedure SetPropEntry(Index: Integer; AInstance: TPersistent;
      APropInfo: PPropInfo); override;
  protected
    function GetFloatValue: Extended;
    function GetFloatValueAt(Index: Integer): Extended;
    function GetInt64Value: Int64;
    function GetInt64ValueAt(Index: Integer): Int64;
    function GetMethodValue: TMethod;
    function GetMethodValueAt(Index: Integer): TMethod;
    function GetOrdValue: Longint;
    function GetOrdValueAt(Index: Integer): Longint;
    function GetStrValue: string;
    function GetStrValueAt(Index: Integer): string;
    function GetVarValue: Variant;
    function GetVarValueAt(Index: Integer): Variant;
    function GetIntfValue: IInterface;
    function GetIntfValueAt(Index: Integer): IInterface;
    procedure Modified;
    procedure SetFloatValue(Value: Extended);
    procedure SetMethodValue(const Value: TMethod);
    procedure SetInt64Value(Value: Int64);
    procedure SetOrdValue(Value: Longint);
    procedure SetStrValue(const Value: string);
    procedure SetVarValue(const Value: Variant);
    procedure SetIntfValue(const Value: IInterface);
  protected
    { IProperty }
    function GetEditValue(out Value: string): Boolean;
    function HasInstance(Instance: TPersistent): Boolean;
  public
    constructor Create(const ADesigner: IDesigner; APropCount: Integer); override;
    destructor Destroy; override;
    procedure Activate; virtual;
    function AllEqual: Boolean; virtual;
    function AutoFill: Boolean; virtual;
    procedure Edit; virtual;
    function GetAttributes: TPropertyAttributes; virtual;
    function GetComponent(Index: Integer): TPersistent;
    function GetEditLimit: Integer; virtual;
    function GetName: string; virtual;
    procedure GetProperties(Proc: TGetPropProc); virtual;
    function GetPropInfo: PPropInfo; virtual;
    function GetPropType: PTypeInfo;
    function GetValue: string; virtual;
    function GetVisualValue: string;
    procedure GetValues(Proc: TGetStrProc); virtual;
    procedure Initialize; override;
    procedure Revert;
    procedure SetValue(const Value: string); virtual;
    function ValueAvailable: Boolean;
    property Designer: IDesigner read FDesigner;
    property PrivateDirectory: string read GetPrivateDirectory;
    property PropCount: Integer read FPropCount;
    property Value: string read GetValue write SetValue;
  end;

{ TOrdinalProperty
  The base class of all ordinal property editors.  It established that ordinal
  properties are all equal if the GetOrdValue all return the same value. }

  TOrdinalProperty = class(TPropertyEditor)
    function AllEqual: Boolean; override;
    function GetEditLimit: Integer; override;
  end;

{ TIntegerProperty
  Default editor for all Longint properties and all subtypes of the Longint
  type (i.e. Integer, Word, 1..10, etc.).  Restricts the value entered into
  the property to the range of the sub-type. }

  TIntegerProperty = class(TOrdinalProperty)
  public
    function GetValue: string; override;
    procedure SetValue(const Value: string); override;
  end;

{ TCharProperty
  Default editor for all Char properties and sub-types of Char (i.e. Char,
  'A'..'Z', etc.). }

  TCharProperty = class(TOrdinalProperty)
  public
    function GetValue: string; override;
    procedure SetValue(const Value: string); override;
  end;

{ TEnumProperty
  The default property editor for all enumerated properties (e.g. TShape =
  (sCircle, sTriangle, sSquare), etc.). }

  TEnumProperty = class(TOrdinalProperty)
  public
    function GetAttributes: TPropertyAttributes; override;
    function GetValue: string; override;
    procedure GetValues(Proc: TGetStrProc); override;
    procedure SetValue(const Value: string); override;
  end;

{ TBoolProperty is now obsolete.  TEnumProperty handles bool types. }
 TBoolProperty = class(TEnumProperty)
 end deprecated;

{ TInt64Property
  Default editor for all Int64 properties and all subtypes of Int64.  }

  TInt64Property = class(TPropertyEditor)
  public
    function AllEqual: Boolean; override;
    function GetEditLimit: Integer; override;
    function GetValue: string; override;
    procedure SetValue(const Value: string); override;
  end;

{ TFloatProperty
  The default property editor for all floating point types (e.g. Float,
  Single, Double, etc.) }

  TFloatProperty = class(TPropertyEditor)
  public
    function AllEqual: Boolean; override;
    function GetValue: string; override;
    procedure SetValue(const Value: string); override;
  end;

{ TStringProperty
  The default property editor for all strings and sub types (e.g. string,
  string[20], etc.). }

  TStringProperty = class(TPropertyEditor)
  public
    function AllEqual: Boolean; override;
    function GetEditLimit: Integer; override;
    function GetValue: string; override;
    procedure SetValue(const Value: string); override;
  end;

{ TNestedProperty
  A property editor that uses the parent's Designer, PropList and PropCount.
  The constructor and destructor do not call inherited, but all derived classes
  should.  This is useful for properties like the TSetElementProperty. }

  TNestedProperty = class(TPropertyEditor)
  public
    constructor Create(Parent: TPropertyEditor); reintroduce;
    destructor Destroy; override;
  end;

{ TSetElementProperty
  A property editor that edits an individual set element.  GetName is
  changed to display the set element name instead of the property name and
  Get/SetValue is changed to reflect the individual element state.  This
  editor is created by the TSetProperty editor. }

  TSetElementProperty = class(TNestedProperty)
  private
    FElement: Integer;
  protected
    constructor Create(Parent: TPropertyEditor; AElement: Integer); reintroduce;
    property Element: Integer read FElement;
  public
    function AllEqual: Boolean; override;
    function GetAttributes: TPropertyAttributes; override;
    function GetName: string; override;
    function GetValue: string; override;
    procedure GetValues(Proc: TGetStrProc); override;
    procedure SetValue(const Value: string); override;
   end;

{ TSetProperty
  Default property editor for all set properties. This editor does not edit
  the set directly but will display sub-properties for each element of the
  set. GetValue displays the value of the set in standard set syntax. }

  TSetProperty = class(TOrdinalProperty)
  public
    function GetAttributes: TPropertyAttributes; override;
    procedure GetProperties(Proc: TGetPropProc); override;
    function GetValue: string; override;
  end;

{ TClassProperty
  Default property editor for all objects.  Does not allow modifying the
  property but does display the class name of the object and will allow the
  editing of the object's properties as sub-properties of the property. }

  TClassProperty = class(TPropertyEditor)
  public
    function GetAttributes: TPropertyAttributes; override;
    procedure GetProperties(Proc: TGetPropProc); override;
    function GetValue: string; override;
  end;

{ TMethodProperty
  Property editor for all method properties. }

  TMethodProperty = class(TPropertyEditor, IMethodProperty)
  public
    function AllNamed: Boolean; virtual;
    function AllEqual: Boolean; override;
    procedure Edit; override;
    function GetAttributes: TPropertyAttributes; override;
    function GetEditLimit: Integer; override;
    function GetValue: string; override;
    procedure GetValues(Proc: TGetStrProc); override;
    procedure SetValue(const AValue: string); override;
    function GetFormMethodName: string; virtual;
    function GetTrimmedEventName: string;
  end;

{ TComponentProperty
  The default editor for TComponents.  It does not allow editing of the
  properties of the component.  It allow the user to set the value of this
  property to point to a component in the same form that is type compatible
  with the property being edited (e.g. the ActiveControl property). }

  TComponentProperty = class(TPropertyEditor, IReferenceProperty)
  protected
    function FilterFunc(const ATestEditor: IProperty): Boolean;
    function GetComponentReference: TComponent; virtual;
    function GetSelections: IDesignerSelections; virtual;
  public
    function AllEqual: Boolean; override;
    procedure Edit; override;
    function GetAttributes: TPropertyAttributes; override;
    procedure GetProperties(Proc: TGetPropProc); override;
    function GetEditLimit: Integer; override;
    function GetValue: string; override;
    procedure GetValues(Proc: TGetStrProc); override;
    procedure SetValue(const Value: string); override;
  end;

{ TInterfaceProperty
  The default editor for interface references.  It allows the user to set
  the value of this property to refer to an interface implemented by
  a component on the form (or via form linking) that is type compatible
  with the property being edited. }

  TInterfaceProperty = class(TComponentProperty)
  private
    FGetValuesStrProc: TGetStrProc;
  protected
    procedure ReceiveComponentNames(const S: string);
    function GetComponent(const AInterface: IInterface): TComponent;
    function GetComponentReference: TComponent; override;
    function GetSelections: IDesignerSelections; override;
  public
    function AllEqual: Boolean; override;
    procedure GetValues(Proc: TGetStrProc); override;
    procedure SetValue(const Value: string); override;
  end;

{ TComponentNameProperty
  Property editor for the Name property.  It restricts the name property
  from being displayed when more than one component is selected. }

  TComponentNameProperty = class(TStringProperty)
  public
    function GetAttributes: TPropertyAttributes; override;
    function GetEditLimit: Integer; override;
  end;

{ TDateProperty
  Property editor for date portion of TDateTime type. }

  TDateProperty = class(TPropertyEditor)
    function GetAttributes: TPropertyAttributes; override;
    function GetValue: string; override;
    procedure SetValue(const Value: string); override;
  end;

{ TTimeProperty
  Property editor for time portion of TDateTime type. }

  TTimeProperty = class(TPropertyEditor)
    function GetAttributes: TPropertyAttributes; override;
    function GetValue: string; override;
    procedure SetValue(const Value: string); override;
  end;

{ TDateTimeProperty
  Edits both date and time data simultaneously  }

  TDateTimeProperty = class(TPropertyEditor)
    function GetAttributes: TPropertyAttributes; override;
    function GetValue: string; override;
    procedure SetValue(const Value: string); override;
  end;

{ TVariantProperty }

  TVariantProperty = class(TPropertyEditor)
    function GetAttributes: TPropertyAttributes; override;
    function GetValue: string; override;
    procedure SetValue(const Value: string); override;
    procedure GetProperties(Proc: TGetPropProc); override;
  end;

procedure GetComponentProperties(const Components: IDesignerSelections;
  Filter: TTypeKinds; const Designer: IDesigner; Proc: TGetPropProc;
  EditorFilterFunc: TPropertyEditorFilterFunc = nil);

{ Component Editors }

type
{ TComponentEditor
  This class provides a default implementation for the IComponentEditor
  interface. There is no assumption by the designer that you use this class
  only that your class derive from TBaseComponentEditor and implement
  IComponentEditor. This class is provided to help you implement a class
  that meets those requirements. }
  TComponentEditor = class(TBaseComponentEditor, IComponentEditor)
  private
    FComponent: TComponent;
    FDesigner: IDesigner;
  public
    constructor Create(AComponent: TComponent; ADesigner: IDesigner); override;
    procedure Edit; virtual;
    procedure ExecuteVerb(Index: Integer); virtual;
    function GetComponent: TComponent;
    function GetDesigner: IDesigner;
    function GetVerb(Index: Integer): string; virtual;
    function GetVerbCount: Integer; virtual;
    function IsInInlined: Boolean;
    procedure Copy; virtual;
    procedure PrepareItem(Index: Integer; const AItem: IMenuItem); virtual;
    property Component: TComponent read FComponent;
    property Designer: IDesigner read GetDesigner;
  end;

{ TDefaultEditor
  An editor that provides default behavior for the double-click that will
  iterate through the properties looking the the most appropriate method
  property to edit }
  TDefaultEditor = class(TComponentEditor, IDefaultEditor)
  private
    FFirst: IProperty;
    FBest: IProperty;
    FContinue: Boolean;
    procedure CheckEdit(const Prop: IProperty);
  protected
    procedure EditProperty(const Prop: IProperty; var Continue: Boolean); virtual;
  public
    procedure Edit; override;
  end;

function GetComponentEditor(Component: TComponent;
  const Designer: IDesigner): IComponentEditor;

{ Selection Editors }

type

{ TSelectionEditor
  This provides a default implementation of the ISelectionEditor interface.
  There is no assumption by the designer that you use this class only that
  you have a class derived from TBaseSelectionEditor and implements the
  ISelectionEdtior interface. This class is provided to help you implement a
  class the meets those requirements. This class is also the selection editor
  that will be created if no other selection editor is registered for a class. }
  TSelectionEditor = class(TBaseSelectionEditor, ISelectionEditor)
  private
    FDesigner: IDesigner;
  public
    constructor Create(const ADesigner: IDesigner); override;
    procedure ExecuteVerb(Index: Integer; const List: IDesignerSelections); virtual;
    function GetVerb(Index: Integer): string; virtual;
    function GetVerbCount: Integer; virtual;
    procedure RequiresUnits(Proc: TGetStrProc); virtual;
    procedure PrepareItem(Index: Integer; const AItem: IMenuItem); virtual;
    property Designer: IDesigner read FDesigner;
  end;

function GetSelectionEditors(const Designer: IDesigner): ISelectionEditorList; overload;
function GetSelectionEditors(const Designer: IDesigner;
  const Selections: IDesignerSelections): ISelectionEditorList; overload;
function GetSelectionEditors(const Designer: IDesigner;
  Component: TComponent): ISelectionEditorList; overload;

type
{ TEditActionSelectionEditor }

  TEditActionSelectionEditor = class(TSelectionEditor)
  private
    procedure HandleToBack(Sender: TObject);
    procedure HandleToFront(Sender: TObject);
  protected
    function GetEditState: TEditState;
    procedure EditAction(Action: TEditAction);

    procedure HandleCopy(Sender: TObject);
    procedure HandleCut(Sender: TObject);
    procedure HandleDelete(Sender: TObject);
    procedure HandlePaste(Sender: TObject);
    procedure HandleSelectAll(Sender: TObject);
    procedure HandleUndo(Sender: TObject);
  public
    function GetVerb(Index: Integer): string; override;
    function GetVerbCount: Integer; override;
    procedure PrepareItem(Index: Integer; const AItem: IMenuItem); override;
  end;

{ Custom Modules }

type
{ TCustomModule
  This class provides a default implementation of the ICustomModule interface.
  There is no assumption by the designer that a custom module derives form
  this class only that it derive from TBaseCustomModule and implement the
  ICustomModule interface. This class is provided to help you implement a
  class that meets those requirements. }
  TCustomModule = class(TBaseCustomModule, ICustomModule)
  private
    FRoot: TComponent;
    FDesigner: IDesigner;
    FFinder: TClassFinder;
  public
    constructor Create(ARoot: TComponent; const ADesigner: IDesigner); override;
    destructor Destroy; override;
    procedure ExecuteVerb(Index: Integer); virtual;
    function GetAttributes: TCustomModuleAttributes; virtual;
    function GetVerb(Index: Integer): string; virtual;
    function GetVerbCount: Integer; virtual;
    procedure Saving; virtual;
    procedure PrepareItem(Index: Integer; const AItem: IMenuItem); virtual;
    procedure ValidateComponent(Component: TComponent); virtual;
    function ValidateComponentClass(ComponentClass: TComponentClass): Boolean; virtual;
    function Nestable: Boolean; virtual;
    property Root: TComponent read FRoot;
    property Designer: IDesigner read FDesigner;
  end;

{ ClassInheritsFrom
  Returns true if ClassType, or one of its ancestors, name matches
  ClassName. This allows checking ancestor by name instead of by class
  reference. }

function ClassInheritsFrom(ClassType: TClass; const ClassName: string): Boolean;

{ AncestorNameMatches
  Returns true if either ClassType descends from AncestorClass or doesn't
  contain an ancestor class by the same name as AncestorClass. This ensures that
  if ClassType has an ancestor by the same name it is AncestorClass. }

function AncestorNameMatches(ClassType: TClass; AncestorClass: TClass): Boolean;

{ Find the top level component (form, module, etc) }

type
  TGetTopLevelComponentFunc = function(Ignoring: TComponent = nil): TComponent;

var
  GetTopLevelComponentFunc: TGetTopLevelComponentFunc;

resourcestring
  sClassNotApplicable = 'Class %s is not applicable to this module';
  sNotAvailable = '(Not available)';

function PossibleStream(const S: string): Boolean;

{ Routines used by the form designer for package management }

type
  TGroupChangeProc = procedure(AGroup: Integer);

  IDesignGroupChange = interface
    ['{8B5614E7-A726-4622-B2A7-F79340B1B78E}']
    procedure FreeEditorGroup(Group: Integer);
  end;

function NewEditorGroup: Integer;
procedure FreeEditorGroup(Group: Integer);
procedure NotifyGroupChange(AProc: TGroupChangeProc);
procedure UnnotifyGroupChange(AProc: TGroupChangeProc);

var
  GReferenceExpandable: Boolean = True;
  GShowReadOnlyProps: Boolean = True;

implementation

uses DesignConst, Consts, RTLConsts, Contnrs, Proxies;

function PossibleStream(const S: string): Boolean;
var
  I: Integer;
begin
  Result := True;
  for I := 1 to Length(S) - 6 do
  begin
    if (S[I] in ['O','o']) and (CompareText(Copy(S, I, 6), 'OBJECT') = 0) then Exit;
    if not (S[I] in [' ',#9, #13, #10]) then Break;
  end;
  Result := False;
end;

{ TPropertyEditor }

constructor TPropertyEditor.Create(const ADesigner: IDesigner;
  APropCount: Integer);
begin
  inherited Create(ADesigner, APropCount);
  FDesigner := ADesigner;
  GetMem(FPropList, APropCount * SizeOf(TInstProp));
  FPropCount := APropCount;
end;

destructor TPropertyEditor.Destroy;
begin
  if FPropList <> nil then
    FreeMem(FPropList, FPropCount * SizeOf(TInstProp));
end;

procedure TPropertyEditor.Activate;
begin
end;

function TPropertyEditor.AllEqual: Boolean;
begin
  Result := FPropCount = 1;
end;

procedure TPropertyEditor.Edit;
type
  TGetStrFunc = function(const Value: string): Integer of object;
var
  I: Integer;
  Values: TStringList;
  AddValue: TGetStrFunc;
begin
  if not AutoFill then Exit;
  Values := TStringList.Create;
  Values.Sorted := paSortList in GetAttributes;
  try
    AddValue := Values.Add;
    GetValues(TGetStrProc(AddValue));
    if Values.Count > 0 then
    begin
      I := Values.IndexOf(Value) + 1;
      if I = Values.Count then I := 0;
      Value := Values[I];
    end;
  finally
    Values.Free;
  end;
end;

function TPropertyEditor.AutoFill: Boolean;
begin
  Result := Assigned(GetPropInfo^.SetProc);
end;

function TPropertyEditor.GetAttributes: TPropertyAttributes;
begin
  Result := [paMultiSelect, paRevertable];
end;

function TPropertyEditor.GetComponent(Index: Integer): TPersistent;
begin
  Result := FPropList^[Index].Instance;
end;

function TPropertyEditor.GetFloatValue: Extended;
begin
  Result := GetFloatValueAt(0);
end;

function TPropertyEditor.GetFloatValueAt(Index: Integer): Extended;
begin
  with FPropList^[Index] do Result := GetFloatProp(Instance, PropInfo);
end;

function TPropertyEditor.GetMethodValue: TMethod;
begin
  Result := GetMethodValueAt(0);
end;

function TPropertyEditor.GetMethodValueAt(Index: Integer): TMethod;
begin
  with FPropList^[Index] do Result := GetMethodProp(Instance, PropInfo);
end;

function TPropertyEditor.GetEditLimit: Integer;
begin
  Result := 255;
end;

function TPropertyEditor.GetName: string;
begin
  Result := FPropList^[0].PropInfo^.Name;
end;

function TPropertyEditor.GetOrdValue: Longint;
begin
  Result := GetOrdValueAt(0);
end;

function TPropertyEditor.GetOrdValueAt(Index: Integer): Longint;
begin
  with FPropList^[Index] do Result := GetOrdProp(Instance, PropInfo);
end;

function TPropertyEditor.GetPrivateDirectory: string;
begin
  Result := '';
  if Designer <> nil then
    Result := Designer.GetPrivateDirectory;
end;

procedure TPropertyEditor.GetProperties(Proc: TGetPropProc);
begin
end;

function TPropertyEditor.GetPropInfo: PPropInfo;
begin
  Result := FPropList^[0].PropInfo;
end;

function TPropertyEditor.GetPropType: PTypeInfo;
begin
  Result := FPropList^[0].PropInfo^.PropType^;
end;

function TPropertyEditor.GetStrValue: string;
begin
  Result := GetStrValueAt(0);
end;

function TPropertyEditor.GetStrValueAt(Index: Integer): string;
begin
  with FPropList^[Index] do Result := GetStrProp(Instance, PropInfo);
end;

function TPropertyEditor.GetVarValue: Variant;
begin
  Result := GetVarValueAt(0);
end;

function TPropertyEditor.GetVarValueAt(Index: Integer): Variant;
begin
  with FPropList^[Index] do Result := GetVariantProp(Instance, PropInfo);
end;

function TPropertyEditor.GetValue: string;
begin
  Result := srUnknown;
end;

function TPropertyEditor.GetVisualValue: string;
begin
  if AllEqual then
    Result := GetValue
  else
    Result := '';
end;

procedure TPropertyEditor.GetValues(Proc: TGetStrProc);
begin
end;

procedure TPropertyEditor.Initialize;
begin
end;

procedure TPropertyEditor.Modified;
begin
  if Designer <> nil then
    Designer.Modified;
end;

procedure TPropertyEditor.SetFloatValue(Value: Extended);
var
  I: Integer;
begin
  for I := 0 to FPropCount - 1 do
    with FPropList^[I] do SetFloatProp(Instance, PropInfo, Value);
  Modified;
end;

procedure TPropertyEditor.SetMethodValue(const Value: TMethod);
var
  I: Integer;
begin
  for I := 0 to FPropCount - 1 do
    with FPropList^[I] do SetMethodProp(Instance, PropInfo, Value);
  Modified;
end;

procedure TPropertyEditor.SetOrdValue(Value: Longint);
var
  I: Integer;
begin
  for I := 0 to FPropCount - 1 do
    with FPropList^[I] do SetOrdProp(Instance, PropInfo, Value);
  Modified;
end;

procedure TPropertyEditor.SetPropEntry(Index: Integer;
  AInstance: TPersistent; APropInfo: PPropInfo);
begin
  with FPropList^[Index] do
  begin
    Instance := AInstance;
    PropInfo := APropInfo;
  end;
end;

procedure TPropertyEditor.SetStrValue(const Value: string);
var
  I: Integer;
begin
  for I := 0 to FPropCount - 1 do
    with FPropList^[I] do SetStrProp(Instance, PropInfo, Value);
  Modified;
end;

procedure TPropertyEditor.SetVarValue(const Value: Variant);
var
  I: Integer;
begin
  for I := 0 to FPropCount - 1 do
    with FPropList^[I] do SetVariantProp(Instance, PropInfo, Value);
  Modified;
end;

procedure TPropertyEditor.Revert;
var
  I: Integer;
begin
  if Designer <> nil then
    for I := 0 to FPropCount - 1 do
      with FPropList^[I] do Designer.Revert(Instance, PropInfo);
end;

procedure TPropertyEditor.SetValue(const Value: string);
begin
end;

function TPropertyEditor.ValueAvailable: Boolean;
var
  I: Integer;
  S: string;
begin
  Result := True;
  for I := 0 to FPropCount - 1 do
  begin
    if (FPropList^[I].Instance is TComponent) and
      (csCheckPropAvail in TComponent(FPropList^[I].Instance).ComponentStyle) then
    begin
      try
        S := GetValue;
        AllEqual;
      except
        Result := False;
      end;
      Exit;
    end;
  end;
end;

function TPropertyEditor.GetInt64Value: Int64;
begin
  Result := GetInt64ValueAt(0);
end;

function TPropertyEditor.GetInt64ValueAt(Index: Integer): Int64;
begin
  with FPropList^[Index] do Result := GetInt64Prop(Instance, PropInfo);
end;

procedure TPropertyEditor.SetInt64Value(Value: Int64);
var
  I: Integer;
begin
  for I := 0 to FPropCount - 1 do
    with FPropList^[I] do SetInt64Prop(Instance, PropInfo, Value);
  Modified;
end;

function TPropertyEditor.GetIntfValue: IInterface;
begin
  Result := GetIntfValueAt(0);
end;

function TPropertyEditor.GetIntfValueAt(Index: Integer): IInterface;
begin
  with FPropList^[Index] do Result := GetInterfaceProp(Instance, PropInfo);
end;

procedure TPropertyEditor.SetIntfValue(const Value: IInterface);
var
  I: Integer;
begin
  for I := 0 to FPropCount - 1 do
    with FPropList^[I] do SetInterfaceProp(Instance, PropInfo, Value);
  Modified;
end;

function TPropertyEditor.GetEditValue(out Value: string): Boolean;
begin
  Result := False;
  try
    Value := GetValue;
    Result := Assigned(GetPropInfo^.SetProc);
  except
    on E: EPropWriteOnly do Value := sNotAvailable;
    on E: Exception do Value := Format('(%s)', [E.Message]);
  end;
end;

function TPropertyEditor.HasInstance(Instance: TPersistent): Boolean;
var
  I: Integer;
begin
  Result := True;
  for I := 0 to FPropCount - 1 do
    if FPropList^[I].Instance = Instance then Exit;
  Result := False;
end;

{ TOrdinalProperty }

function TOrdinalProperty.AllEqual: Boolean;
var
  I: Integer;
  V: Longint;
begin
  Result := False;
  if PropCount > 1 then
  begin
    V := GetOrdValue;
    for I := 1 to PropCount - 1 do
      if GetOrdValueAt(I) <> V then Exit;
  end;
  Result := True;
end;

function TOrdinalProperty.GetEditLimit: Integer;
begin
  Result := 63;
end;

{ TIntegerProperty }

function TIntegerProperty.GetValue: string;
begin
  with GetTypeData(GetPropType)^ do
    if OrdType = otULong then // unsigned
      Result := IntToStr(Cardinal(GetOrdValue))
    else
      Result := IntToStr(GetOrdValue);
end;

procedure TIntegerProperty.SetValue(const Value: String);

  procedure Error(const Args: array of const);
  begin
    raise EPropertyError.CreateResFmt(@SOutOfRange, Args);
  end;

var
  L: Int64;
begin
  L := StrToInt64(Value);
  with GetTypeData(GetPropType)^ do
    if OrdType = otULong then
    begin   // unsigned compare and reporting needed
      if (L < Cardinal(MinValue)) or (L > Cardinal(MaxValue)) then
        // bump up to Int64 to get past the %d in the format string
        Error([Int64(Cardinal(MinValue)), Int64(Cardinal(MaxValue))]);
    end
    else if (L < MinValue) or (L > MaxValue) then
      Error([MinValue, MaxValue]);
  SetOrdValue(L);
end;

{ TCharProperty }

function TCharProperty.GetValue: string;
var
  Ch: Char;
begin
  Ch := Chr(GetOrdValue);
  if Ch in [#33..#127] then
    Result := Ch else
    FmtStr(Result, '#%d', [Ord(Ch)]);
end;

procedure TCharProperty.SetValue(const Value: string);
var
  L: Longint;
begin
  if Length(Value) = 0 then L := 0 else
    if Length(Value) = 1 then L := Ord(Value[1]) else
      if Value[1] = '#' then L := StrToInt(Copy(Value, 2, Maxint)) else
        raise EPropertyError.CreateRes(@SInvalidPropertyValue);
  with GetTypeData(GetPropType)^ do
    if (L < MinValue) or (L > MaxValue) then
      raise EPropertyError.CreateResFmt(@SOutOfRange, [MinValue, MaxValue]);
  SetOrdValue(L);
end;

{ TEnumProperty }

function TEnumProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paMultiSelect, paValueList, paSortList, paRevertable];
end;

function TEnumProperty.GetValue: string;
var
  L: Longint;
begin
  L := GetOrdValue;
  with GetTypeData(GetPropType)^ do
    if (L < MinValue) or (L > MaxValue) then L := MaxValue;
  Result := GetEnumName(GetPropType, L);
end;

procedure TEnumProperty.GetValues(Proc: TGetStrProc);
var
  I: Integer;
  EnumType: PTypeInfo;
begin
  EnumType := GetPropType;
  with GetTypeData(EnumType)^ do
  begin
    if MinValue < 0 then  // longbool/wordbool/bytebool
    begin
      Proc(GetEnumName(EnumType, 0));
      Proc(GetEnumName(EnumType, 1));
    end
    else
      for I := MinValue to MaxValue do Proc(GetEnumName(EnumType, I));
  end;
end;

procedure TEnumProperty.SetValue(const Value: string);
var
  I: Integer;
begin
  I := GetEnumValue(GetPropType, Value);
  with GetTypeData(GetPropType)^ do
    if (I < MinValue) or (I > MaxValue) then
      raise EPropertyError.CreateRes(@SInvalidPropertyValue);
  SetOrdValue(I);
end;

{ TBoolProperty  }
{!!
function TBoolProperty.GetValue: string;
begin
  Result := BooleanIdents[GetOrdValue <> 0];
end;

procedure TBoolProperty.GetValues(Proc: TGetStrProc);
begin
  Proc(BooleanIdents[False]);
  Proc(BooleanIdents[True]);
end;

procedure TBoolProperty.SetValue(const Value: string);
var
  I: Integer;
begin
  if SameText(Value, BooleanIdents[False]) then
    I := 0
  else if SameText(Value, BooleanIdents[True]) then
    I := -1
  else
    I := StrToInt(Value);
  SetOrdValue(I);
end;
}
{ TInt64Property }

function TInt64Property.AllEqual: Boolean;
var
  I: Integer;
  V: Int64;
begin
  Result := False;
  if PropCount > 1 then
  begin
    V := GetInt64Value;
    for I := 1 to PropCount - 1 do
      if GetInt64ValueAt(I) <> V then Exit;
  end;
  Result := True;
end;

function TInt64Property.GetEditLimit: Integer;
begin
  Result := 63;
end;

function TInt64Property.GetValue: string;
begin
  Result := IntToStr(GetInt64Value);
end;

procedure TInt64Property.SetValue(const Value: string);
begin
  SetInt64Value(StrToInt64(Value));
end;

{ TFloatProperty }

function TFloatProperty.AllEqual: Boolean;
var
  I: Integer;
  V: Extended;
begin
  Result := False;
  if PropCount > 1 then
  begin
    V := GetFloatValue;
    for I := 1 to PropCount - 1 do
      if GetFloatValueAt(I) <> V then Exit;
  end;
  Result := True;
end;

function TFloatProperty.GetValue: string;
const
  Precisions: array[TFloatType] of Integer = (7, 15, 18, 18, 18);
begin
  Result := FloatToStrF(GetFloatValue, ffGeneral,
    Precisions[GetTypeData(GetPropType)^.FloatType], 0);
end;

procedure TFloatProperty.SetValue(const Value: string);
begin
  SetFloatValue(StrToFloat(Value));
end;

{ TStringProperty }

function TStringProperty.AllEqual: Boolean;
var
  I: Integer;
  V: string;
begin
  Result := False;
  if PropCount > 1 then
  begin
    V := GetStrValue;
    for I := 1 to PropCount - 1 do
      if GetStrValueAt(I) <> V then Exit;
  end;
  Result := True;
end;

function TStringProperty.GetEditLimit: Integer;
begin
  if GetPropType^.Kind = tkString then
    Result := GetTypeData(GetPropType)^.MaxLength
  else
    Result := 255;
end;

function TStringProperty.GetValue: string;
begin
  Result := GetStrValue;
end;

procedure TStringProperty.SetValue(const Value: string);
begin
  SetStrValue(Value);
end;

{ TComponentNameProperty }

function TComponentNameProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paNotNestable];
end;

function TComponentNameProperty.GetEditLimit: Integer;
begin
  Result := MaxIdentLength;
end;

{ TNestedProperty }

constructor TNestedProperty.Create(Parent: TPropertyEditor);
begin
  FDesigner := Parent.Designer;
  FPropList := Parent.FPropList;
  FPropCount := Parent.PropCount;
end;

destructor TNestedProperty.Destroy;
begin
end;

{ TSetElementProperty }

constructor TSetElementProperty.Create(Parent: TPropertyEditor; AElement: Integer);
begin
  inherited Create(Parent);
  FElement := AElement;
end;

function TSetElementProperty.AllEqual: Boolean;
var
  I: Integer;
  S: TIntegerSet;
  V: Boolean;
begin
  Result := False;
  if PropCount > 1 then
  begin
    Integer(S) := GetOrdValue;
    V := FElement in S;
    for I := 1 to PropCount - 1 do
    begin
      Integer(S) := GetOrdValueAt(I);
      if (FElement in S) <> V then Exit;
    end;
  end;
  Result := True;
end;

function TSetElementProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paMultiSelect, paValueList, paSortList];
end;

function TSetElementProperty.GetName: string;
begin
  Result := GetEnumName(GetTypeData(GetPropType)^.CompType^, FElement);
end;

function TSetElementProperty.GetValue: string;
var
  S: TIntegerSet;
begin
  Integer(S) := GetOrdValue;
  Result := BooleanIdents[FElement in S];
end;

procedure TSetElementProperty.GetValues(Proc: TGetStrProc);
begin
  Proc(BooleanIdents[False]);
  Proc(BooleanIdents[True]);
end;

procedure TSetElementProperty.SetValue(const Value: string);
var
  S: TIntegerSet;
begin
  Integer(S) := GetOrdValue;
  if CompareText(Value, BooleanIdents[True]) = 0 then
    Include(S, FElement)
  else
    Exclude(S, FElement);
  SetOrdValue(Integer(S));
end;

{ TSetProperty }

function TSetProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paMultiSelect, paSubProperties, paReadOnly, paRevertable];
end;

procedure TSetProperty.GetProperties(Proc: TGetPropProc);
var
  I: Integer;
begin
  with GetTypeData(GetTypeData(GetPropType)^.CompType^)^ do
    for I := MinValue to MaxValue do
      Proc(TSetElementProperty.Create(Self, I));
end;

function TSetProperty.GetValue: string;
var
  S: TIntegerSet;
  TypeInfo: PTypeInfo;
  I: Integer;
begin
  Integer(S) := GetOrdValue;
  TypeInfo := GetTypeData(GetPropType)^.CompType^;
  Result := '[';
  for I := 0 to SizeOf(Integer) * 8 - 1 do
    if I in S then
    begin
      if Length(Result) <> 1 then Result := Result + ',';
      Result := Result + GetEnumName(TypeInfo, I);
    end;
  Result := Result + ']';
end;

{ TClassProperty }

function TClassProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paMultiSelect, paSubProperties, paReadOnly];
end;

procedure TClassProperty.GetProperties(Proc: TGetPropProc);
var
  I: Integer;
  J: Integer;
  Components: IDesignerSelections;
begin
  Components := TDesignerSelections.Create;
  for I := 0 to PropCount - 1 do
  begin
    J := GetOrdValueAt(I);
    if J <> 0 then
      Components.Add(TComponent(GetOrdValueAt(I)));
  end;
  if Components.Count > 0 then
    GetComponentProperties(Components, tkProperties, Designer, Proc);
end;

function TClassProperty.GetValue: string;
begin
  FmtStr(Result, '(%s)', [GetPropType^.Name]);
end;

{ TComponentProperty }

procedure TComponentProperty.Edit;
var
  Temp: TComponent;
begin
  if (Designer.GetShiftState * [ssCtrl, ssLeft] = [ssCtrl, ssLeft]) then
  begin
    Temp := GetComponentReference;
    if Temp <> nil then
      Designer.SelectComponent(Temp)
    else
      inherited Edit;
  end
  else
    inherited Edit;
end;

function TComponentProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paMultiSelect];
  if Assigned(GetPropInfo^.SetProc) then
    Result := Result + [paValueList, paSortList, paRevertable]
  else
    Result := Result + [paReadOnly];
  if GReferenceExpandable and (GetComponentReference <> nil) and AllEqual then
    Result := Result + [paSubProperties, paVolatileSubProperties];
end;

function TComponentProperty.GetSelections: IDesignerSelections;
var
  I: Integer;
begin
  Result := nil;
  if (GetComponentReference <> nil) and AllEqual then
  begin
    Result := TDesignerSelections.Create;
    for I := 0 to PropCount - 1 do
      Result.Add(TComponent(GetOrdValueAt(I)));
  end;
end;

procedure TComponentProperty.GetProperties(Proc: TGetPropProc);
var
  LComponents: IDesignerSelections;
  LDesigner: IDesigner;
begin
  LComponents := GetSelections;
  if LComponents <> nil then
  begin
    if not Supports(FindRootDesigner(LComponents[0]), IDesigner, LDesigner) then
      LDesigner := Designer;
    GetComponentProperties(LComponents, tkAny, LDesigner, Proc, FilterFunc);
  end;
end;

function TComponentProperty.GetEditLimit: Integer;
begin
  Result := 127;
end;

function TComponentProperty.GetValue: string;
begin
  Result := Designer.GetComponentName(GetComponentReference);
end;

procedure TComponentProperty.GetValues(Proc: TGetStrProc);
begin
  Designer.GetComponentNames(GetTypeData(GetPropType), Proc);
end;

procedure TComponentProperty.SetValue(const Value: string);
var
  Component: TComponent;
begin
  if Value = '' then
    Component := nil
  else
  begin
    Component := Designer.GetComponent(Value);
    if not (Component is GetTypeData(GetPropType)^.ClassType) then
      raise EPropertyError.CreateRes(@SInvalidPropertyValue);
  end;
  SetOrdValue(LongInt(Component));
end;

function TComponentProperty.AllEqual: Boolean;
var
  I: Integer;
  LInstance: TComponent;
begin
  Result := False;
  LInstance := TComponent(GetOrdValue);
  if PropCount > 1 then
    for I := 1 to PropCount - 1 do
      if TComponent(GetOrdValueAt(I)) <> LInstance then
        Exit;
  Result := Supports(FindRootDesigner(LInstance), IDesigner);
end;

function TComponentProperty.GetComponentReference: TComponent;
begin
  Result := TComponent(GetOrdValue);
end;

function TComponentProperty.FilterFunc(const ATestEditor: IProperty): Boolean;
begin
  Result := not (paNotNestable in ATestEditor.GetAttributes);
end;

{ TInterfaceProperty }

function TInterfaceProperty.AllEqual: Boolean;
var
  I: Integer;
  LInterface: IInterface;
begin
  Result := False;
  LInterface := GetIntfValue;
  if PropCount > 1 then
    for I := 1 to PropCount - 1 do
      if GetIntfValueAt(I) <> LInterface then
        Exit;
  Result := Supports(FindRootDesigner(GetComponent(LInterface)), IDesigner);
end;

function TInterfaceProperty.GetComponent(const AInterface: IInterface): TComponent;
var
  ICR: IInterfaceComponentReference;
begin
  if (AInterface <> nil) and
     Supports(AInterface, IInterfaceComponentReference, ICR) then
    Result := ICR.GetComponent
  else
    Result := nil;
end;

function TInterfaceProperty.GetComponentReference: TComponent;
begin
  Result := GetComponent(GetIntfValue);
end;

function TInterfaceProperty.GetSelections: IDesignerSelections;
var
  I: Integer;
begin
  Result := nil;
  if (GetIntfValue <> nil) and AllEqual then
  begin
    Result := TDesignerSelections.Create;
    for I := 0 to PropCount - 1 do
      Result.Add(GetComponent(GetIntfValueAt(I)));
  end;
end;

procedure TInterfaceProperty.ReceiveComponentNames(const S: string);
var
  Temp: TComponent;
  Intf: IInterface;
begin
  Temp := Designer.GetComponent(S);
  if Assigned(FGetValuesStrProc) and
     Assigned(Temp) and
     Supports(TObject(Temp), GetTypeData(GetPropType)^.Guid, Intf) then
    FGetValuesStrProc(S);
end;

procedure TInterfaceProperty.GetValues(Proc: TGetStrProc);
begin
  FGetValuesStrProc := Proc;
  try
    Designer.GetComponentNames(GetTypeData(TypeInfo(TComponent)), ReceiveComponentNames);
  finally
    FGetValuesStrProc := nil;
  end;
end;

procedure TInterfaceProperty.SetValue(const Value: string);
var
  Intf: IInterface;
  Component: TComponent;
begin
  if Value = '' then
    Intf := nil
  else
  begin
    Component := Designer.GetComponent(Value);
    if (Component = nil) or
      not Supports(TObject(Component), GetTypeData(GetPropType)^.Guid, Intf) then
      raise EPropertyError.CreateRes(@SInvalidPropertyValue);
  end;
  SetIntfValue(Intf);
end;

{ TMethodProperty }

function TMethodProperty.AllEqual: Boolean;
var
  I: Integer;
  V, T: TMethod;
begin
  Result := False;
  if PropCount > 1 then
  begin
    V := GetMethodValue;
    for I := 1 to PropCount - 1 do
    begin
      T := GetMethodValueAt(I);
      if (T.Code <> V.Code) or (T.Data <> V.Data) then Exit;
    end;
  end;
  Result := True;
end;

function TMethodProperty.AllNamed: Boolean;
var
  I: Integer;
begin
  Result := True;
  for I := 0 to PropCount - 1 do
    if GetComponent(I).GetNamePath = '' then
    begin
      Result := False;
      Break;
    end;
end;

procedure TMethodProperty.Edit;
var
  FormMethodName: string;
begin
  if not AllNamed then
    raise EPropertyError.CreateRes(@SCannotCreateName);
  FormMethodName := GetValue;
  if (FormMethodName = '') or
    Designer.MethodFromAncestor(GetMethodValue) then
  begin
    if FormMethodName = '' then
      FormMethodName := GetFormMethodName;
    if FormMethodName = '' then
      raise EPropertyError.CreateRes(@SCannotCreateName);
    SetValue(FormMethodName);
  end;
  Designer.ShowMethod(FormMethodName);
end;

function TMethodProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paMultiSelect, paValueList, paSortList, paRevertable];
end;

function TMethodProperty.GetEditLimit: Integer;
begin
  Result := MaxIdentLength;
end;

function TMethodProperty.GetFormMethodName: string;
var
  I: Integer;
begin
  if GetComponent(0) = Designer.GetRoot then
  begin
    Result := Designer.GetRootClassName;
    if (Result <> '') and (Result[1] = 'T') then
      Delete(Result, 1, 1);
  end
  else
  begin
    Result := Designer.GetObjectName(GetComponent(0));
    for I := Length(Result) downto 1 do
      if Result[I] in ['.', '[', ']', '-', '>'] then
        Delete(Result, I, 1);
  end;
  if Result = '' then
    raise EPropertyError.CreateRes(@SCannotCreateName);
  Result := Result + GetTrimmedEventName;
end;

function TMethodProperty.GetTrimmedEventName: string;
begin
  Result := GetName;
  if (Length(Result) >= 2) and
    (Result[1] in ['O', 'o']) and (Result[2] in ['N', 'n']) then
    Delete(Result,1,2);
end;

function TMethodProperty.GetValue: string;
begin
  Result := Designer.GetMethodName(GetMethodValue);
end;

procedure TMethodProperty.GetValues(Proc: TGetStrProc);
begin
  Designer.GetMethods(GetTypeData(GetPropType), Proc);
end;

procedure TMethodProperty.SetValue(const AValue: string);

  procedure CheckChainCall(const MethodName: string; Method: TMethod);
  var
    Persistent: TPersistent;
    Component: TComponent;
    InstanceMethod: string;
    Instance: TComponent;
  begin
    Persistent := GetComponent(0);
    if Persistent is TComponent then
    begin
      Component := TComponent(Persistent);
      if (Component.Name <> '') and (Method.Data <> Designer.GetRoot) and
        (TObject(Method.Data) is TComponent) then
      begin
        Instance := TComponent(Method.Data);
        InstanceMethod := Instance.MethodName(Method.Code);
        if InstanceMethod <> '' then
          Designer.ChainCall(MethodName, Instance.Name, InstanceMethod,
            GetTypeData(GetPropType));
      end;
    end;
  end;

var
  NewMethod: Boolean;
  CurValue: string;
  OldMethod: TMethod;
begin
  if not AllNamed then
    raise EPropertyError.CreateRes(@SCannotCreateName);
  CurValue:= GetValue;
  if (CurValue <> '') and (AValue <> '') and (SameText(CurValue, AValue) or
    not Designer.MethodExists(AValue)) and not Designer.MethodFromAncestor(GetMethodValue) then
    Designer.RenameMethod(CurValue, AValue)
  else
  begin
    NewMethod := (AValue <> '') and not Designer.MethodExists(AValue);
    OldMethod := GetMethodValue;
    SetMethodValue(Designer.CreateMethod(AValue, GetTypeData(GetPropType)));
    if NewMethod then
    begin
      if (PropCount = 1) and (OldMethod.Data <> nil) and (OldMethod.Code <> nil) then
        CheckChainCall(AValue, OldMethod);
      Designer.ShowMethod(AValue);
    end;
  end;
end;

{ TDateProperty }

function TDateProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paMultiSelect, paRevertable];
end;

function TDateProperty.GetValue: string;
var
  DT: TDateTime;
begin
  DT := GetFloatValue;
  if DT = 0.0 then Result := '' else
  Result := DateToStr(DT);
end;

procedure TDateProperty.SetValue(const Value: string);
var
  DT: TDateTime;
begin
  if Value = '' then DT := 0.0
  else DT := StrToDate(Value);
  SetFloatValue(DT);
end;

{ TTimeProperty }

function TTimeProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paMultiSelect, paRevertable];
end;

function TTimeProperty.GetValue: string;
var
  DT: TDateTime;
begin
  DT := GetFloatValue;
  if DT = 0.0 then Result := '' else
  Result := TimeToStr(DT);
end;

procedure TTimeProperty.SetValue(const Value: string);
var
  DT: TDateTime;
begin
  if Value = '' then DT := 0.0
  else DT := StrToTime(Value);
  SetFloatValue(DT);
end;

{ TDateTimeProperty }

function TDateTimeProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paMultiSelect, paRevertable];
end;

function TDateTimeProperty.GetValue: string;
var
  DT: TDateTime;
begin
  DT := GetFloatValue;
  if DT = 0.0 then Result := '' else
  Result := DateTimeToStr(DT);
end;

procedure TDateTimeProperty.SetValue(const Value: string);
var
  DT: TDateTime;
begin
  if Value = '' then DT := 0.0
  else DT := StrToDateTime(Value);
  SetFloatValue(DT);
end;

{ TPropInfoList }

type
  TPropInfoList = class
  private
    FList: PPropList;
    FCount: Integer;
    FSize: Integer;
    function Get(Index: Integer): PPropInfo;
  public
    constructor Create(Instance: TPersistent; Filter: TTypeKinds);
    destructor Destroy; override;
    function Contains(P: PPropInfo): Boolean;
    procedure Delete(Index: Integer);
    procedure Intersect(List: TPropInfoList);
    property Count: Integer read FCount;
    property Items[Index: Integer]: PPropInfo read Get; default;
  end;

constructor TPropInfoList.Create(Instance: TPersistent; Filter: TTypeKinds);
begin
  FCount := GetPropList(Instance.ClassInfo, Filter, nil);
  FSize := FCount * SizeOf(Pointer);
  GetMem(FList, FSize);
  GetPropList(Instance.ClassInfo, Filter, FList);
end;

destructor TPropInfoList.Destroy;
begin
  if FList <> nil then FreeMem(FList, FSize);
end;

function TPropInfoList.Contains(P: PPropInfo): Boolean;
var
  I: Integer;
begin
  for I := 0 to FCount - 1 do
    with FList^[I]^ do
      if (PropType^ = P^.PropType^) and (CompareText(Name, P^.Name) = 0) then
      begin
        Result := True;
        Exit;
      end;
  Result := False;
end;

procedure TPropInfoList.Delete(Index: Integer);
begin
  Dec(FCount);
  if Index < FCount then
    Move(FList^[Index + 1], FList^[Index],
      (FCount - Index) * SizeOf(Pointer));
end;

function TPropInfoList.Get(Index: Integer): PPropInfo;
begin
  Result := FList^[Index];
end;

procedure TPropInfoList.Intersect(List: TPropInfoList);
var
  I: Integer;
begin
  for I := FCount - 1 downto 0 do
    if not List.Contains(FList^[I]) then Delete(I);
end;

function InterfaceInheritsFrom(Child, Parent: PTypeData): Boolean;
begin
  while (Child <> nil) and (Child <> Parent) and (Child^.IntfParent <> nil) do
    Child := GetTypeData(Child^.IntfParent^);
  Result := (Child <> nil) and (Child = Parent);
end;

{ Property Editor registration }

type
  PPropertyClassRec = ^TPropertyClassRec;
  TPropertyClassRec = record
    Group: Integer;
    PropertyType: PTypeInfo;
    PropertyName: string;
    ComponentClass: TClass;
    ClassGroup: TPersistentClass;
    EditorClass: TPropertyEditorClass;
  end;

  PPropertyMapperRec = ^TPropertyMapperRec;
  TPropertyMapperRec = record
    Group: Integer;
    Mapper: TPropertyMapperFunc;
  end;

const
  PropClassMap: array[TypInfo.TTypeKind] of TPropertyEditorClass = (
    nil,                // tkUnknown
    TIntegerProperty,   // tkInteger
    TCharProperty,      // tkChar
    TEnumProperty,      // tkEnumeration
    TFloatProperty,     // tkFloat
    TStringProperty,    // tkString
    TSetProperty,       // tkSet
    TClassProperty,     // tkClass
    TMethodProperty,    // tkMethod
    TPropertyEditor,    // tkWChar
    TStringProperty,    // tkLString
    TStringProperty,    // tkWString
    TVariantProperty,   // tkVariant
    nil,                // tkArray
    nil,                // tkRecord
    TInterfaceProperty, // tkInterface
    TInt64Property,     // tkInt64
    nil);               // tkDynArray

var
  PropertyClassList: TList;
  PropertyMapperList: TList = nil;

procedure RegisterPropertyEditor(PropertyType: PTypeInfo; ComponentClass: TClass;
  const PropertyName: string; EditorClass: TPropertyEditorClass);
var
  P: PPropertyClassRec;
begin
  if PropertyClassList = nil then
    PropertyClassList := TList.Create;
  New(P);
  P.Group := CurrentGroup;
  P.PropertyType := PropertyType;
  P.ComponentClass := ComponentClass;
  P.PropertyName := '';
  P.ClassGroup := nil;
  if Assigned(ComponentClass) then P^.PropertyName := PropertyName;
  P.EditorClass := EditorClass;
  PropertyClassList.Insert(0, P);
end;

procedure SetPropertyEditorGroup(EditorClass: TPropertyEditorClass;
  GroupClass: TPersistentClass);
var
  P: PPropertyClassRec;
  I: Integer;
begin
  for I := 0 to PropertyClassList.Count - 1 do
  begin
    P := PropertyClassList[I];
    if P^.EditorClass = EditorClass then
    begin
      P^.ClassGroup := ClassGroupOf(GroupClass);
      Exit;
    end;
  end;
  // Ignore it if the EditorClass is not found.
end;

function GetEditorClass(PropInfo: PPropInfo;
  Obj: TPersistent): TPropertyEditorClass;
var
  PropType: PTypeInfo;
  P, C: PPropertyClassRec;
  I: Integer;
begin
  if PropertyMapperList <> nil then
  begin
    for I := 0 to PropertyMapperList.Count -1 do
      with PPropertyMapperRec(PropertyMapperList[I])^ do
      begin
        Result := Mapper(Obj, PropInfo);
        if Result <> nil then Exit;
      end;
  end;
  PropType := PropInfo^.PropType^;
  I := 0;
  C := nil;
  while I < PropertyClassList.Count do
  begin
    P := PropertyClassList[I];

    if ( (P^.PropertyType = PropType) {or
         ((P^.PropertyType^.Kind = PropType.Kind) and
          (P^.PropertyType^.Name = PropType.Name)
         )}
       ) or  // compatible class type
       ( (PropType^.Kind = tkClass) and
         (P^.PropertyType^.Kind = tkClass) and
         GetTypeData(PropType)^.ClassType.InheritsFrom(GetTypeData(P^.PropertyType)^.ClassType)
       ) or  // compatible interface type
       ( (PropType^.Kind = tkInterface) and
         (P^.PropertyType^.Kind = tkInterface) and
         InterfaceInheritsFrom(GetTypeData(PropType), GetTypeData(P^.PropertyType))
       ) then
      if ((P^.ComponentClass = nil) or (Obj.InheritsFrom(P^.ComponentClass))) and
         ((P^.ClassGroup = nil) or (P^.ClassGroup = ClassGroupOf(Obj))) and
         ((P^.PropertyName = '') or (CompareText(PropInfo^.Name, P^.PropertyName) = 0)) then
        if (C = nil) or   // see if P is better match than C
           ((C^.ComponentClass = nil) and (P^.ComponentClass <> nil)) or
           ((C^.PropertyName = '') and (P^.PropertyName <> ''))
           or  // P's proptype match is exact, but C's isn't
           ((C^.PropertyType <> PropType) and (P^.PropertyType = PropType))
           or  // P's proptype is more specific than C's proptype
           ( (P^.PropertyType <> C^.PropertyType) and
             ( ( // P has a more specific class type than C.
                 (P^.PropertyType^.Kind = tkClass) and
                 (C^.PropertyType^.Kind = tkClass) and
                 GetTypeData(P^.PropertyType)^.ClassType.InheritsFrom(
                   GetTypeData(C^.PropertyType)^.ClassType)
               ) or // P has a more specific interface type than C.
               ( (P^.PropertyType^.Kind = tkInterface) and
                 (C^.PropertyType^.Kind = tkInterface) and
                 InterfaceInheritsFrom(GetTypeData(P^.PropertyType), GetTypeData(C^.PropertyType))
               )
             )
           ) or // P's component class is more specific than C's component class
           ( (P^.ComponentClass <> nil) and (C^.ComponentClass <> nil) and
             (P^.ComponentClass <> C^.ComponentClass) and
             (P^.ComponentClass.InheritsFrom(C^.ComponentClass))
           ) then
          C := P;
    Inc(I);
  end;
  if C <> nil then
    Result := C^.EditorClass else
    Result := PropClassMap[PropType^.Kind];
end;

procedure GetComponentProperties(const Components: IDesignerSelections;
  Filter: TTypeKinds; const Designer: IDesigner; Proc: TGetPropProc;
  EditorFilterFunc: TPropertyEditorFilterFunc);
var
  I, J, CompCount: Integer;
  CompType: TClass;
  Candidates: TPropInfoList;
  PropLists: TList;
  EditorInstance: TBasePropertyEditor;
  Editor: IProperty;
  EdClass: TPropertyEditorClass;
  PropInfo: PPropInfo;
  AddEditor: Boolean;
  Obj: TPersistent;
begin
  {$IFDEF LINUX}
  Try
    BlockQt;
  {$ENDIF LINUX}
    if (Components = nil) or (Components.Count = 0) then Exit;
    CompCount := Components.Count;
    Obj := Components[0];
    CompType := Components[0].ClassType;
    // Create a property candidate list
    Candidates := TPropInfoList.Create(Components[0], Filter);
    try
      for I := Candidates.Count - 1 downto 0 do
      begin
        PropInfo := Candidates[I];
        EdClass := GetEditorClass(PropInfo, Obj);
        if EdClass = nil then
          Candidates.Delete(I)
        else
        begin
          EditorInstance := EdClass.Create(Designer, 1);
          Editor := EditorInstance as IProperty;
          TPropertyEditor(EditorInstance).SetPropEntry(0, Components[0], PropInfo);
          TPropertyEditor(EditorInstance).Initialize;
          with PropInfo^ do
            if (GetProc = nil) or
               (not GShowReadOnlyProps and
                ((PropType^.Kind <> tkClass) and
                 (SetProc = nil))) or
               ((CompCount > 1) and
                not (paMultiSelect in Editor.GetAttributes)) or
               not Editor.ValueAvailable or
               (Assigned(EditorFilterFunc) and not EditorFilterFunc(Editor)) then
              Candidates.Delete(I);
        end;
      end;
      PropLists := TList.Create;
      try
        PropLists.Capacity := CompCount;
        // Create a property list for each component in the selection
        for I := 0 to CompCount - 1 do
          PropLists.Add(TPropInfoList.Create(Components[I], Filter));
        // Eliminate each property in Candidates that is not in all property list
        for I := 0 to CompCount - 1 do
          Candidates.Intersect(TPropInfoList(PropLists[I]));
        // Eliminate each property in the property list that are not in Candidates
        for I := 0 to CompCount - 1 do
          TPropInfoList(PropLists[I]).Intersect(Candidates);
        // PropList now has a matrix of PropInfo's, create property editors for
        // each property with given each the array of PropInfos
        for I := 0 to Candidates.Count - 1 do
        begin
          EdClass := GetEditorClass(Candidates[I], Obj);
          if EdClass = nil then Continue;
          EditorInstance := EdClass.Create(Designer, CompCount);
          Editor := EditorInstance as IProperty;
          AddEditor := True;
          for J := 0 to CompCount - 1 do
          begin
            if (Components[J].ClassType <> CompType) and
              (GetEditorClass(TPropInfoList(PropLists[J])[I],
                Components[J]) <> EdClass) then
            begin
              AddEditor := False;
              Break;
            end;
            TPropertyEditor(EditorInstance).SetPropEntry(J, Components[J],
              TPropInfoList(PropLists[J])[I]);
          end;
          if AddEditor then
          begin
            TPropertyEditor(EditorInstance).Initialize;
            if Editor.ValueAvailable then Proc(Editor);
          end;
        end;
      finally
        for I := 0 to PropLists.Count - 1 do TPropInfoList(PropLists[I]).Free;
        PropLists.Free;
      end;
    finally
      Candidates.Free;
    end;
  {$IFDEF LINUX}
  finally
    UnblockQt;
  end;
  {$ENDIF LINUX}
end;

procedure RegisterPropertyMapper(Mapper: TPropertyMapperFunc);
var
  P: PPropertyMapperRec;
begin
  if PropertyMapperList = nil then
    PropertyMapperList := TList.Create;
  New(P);
  P^.Group := CurrentGroup;
  P^.Mapper := Mapper;
  PropertyMapperList.Insert(0, P);
end;

{ Component Editors }

{ TComponentEditor }

constructor TComponentEditor.Create(AComponent: TComponent; ADesigner: IDesigner);
begin
  inherited Create(AComponent, ADesigner);
  FComponent := AComponent;
  FDesigner := ADesigner;
end;

procedure TComponentEditor.Edit;
begin
  if GetVerbCount > 0 then ExecuteVerb(0);
end;

function TComponentEditor.GetComponent: TComponent;
begin
  Result := FComponent;
end;

function TComponentEditor.GetDesigner: IDesigner;
begin
  Result := FDesigner;
end;

function TComponentEditor.GetVerbCount: Integer;
begin
  // Intended for descendents to implement
  Result := 0;
end;

function TComponentEditor.GetVerb(Index: Integer): string;
begin
  // Intended for descendents to implement
end;

procedure TComponentEditor.ExecuteVerb(Index: Integer);
begin
  // Intended for descendents to implement
end;

procedure TComponentEditor.Copy;
begin
  // Intended for descendents to implement
end;

function TComponentEditor.IsInInlined: Boolean;
begin
  Result := csInline in Component.Owner.ComponentState;
end;

procedure TComponentEditor.PrepareItem(Index: Integer;
  const AItem: IMenuItem);
begin
  // Intended for descendents to implement
end;

{ TDefaultEditor }

procedure TDefaultEditor.CheckEdit(const Prop: IProperty);
begin
  if FContinue then
    EditProperty(Prop, FContinue);
end;

procedure TDefaultEditor.EditProperty(const Prop: IProperty;
  var Continue: Boolean);
var
  PropName: string;
  BestName: string;
  MethodProperty: IMethodProperty;

  procedure ReplaceBest;
  begin
    FBest := Prop;
    if FFirst = FBest then FFirst := nil;
  end;

begin
  if not Assigned(FFirst) and
    Supports(Prop, IMethodProperty, MethodProperty) then
    FFirst := Prop;
  PropName := Prop.GetName;
  BestName := '';
  if Assigned(FBest) then BestName := FBest.GetName;
  if CompareText(PropName, 'ONCREATE') = 0 then
    ReplaceBest
  else if CompareText(BestName, 'ONCREATE') <> 0 then
    if CompareText(PropName, 'ONCHANGE') = 0 then
      ReplaceBest
    else if CompareText(BestName, 'ONCHANGE') <> 0 then
      if CompareText(PropName, 'ONCLICK') = 0 then
        ReplaceBest;
end;

procedure TDefaultEditor.Edit;
var
  Components: IDesignerSelections;
begin
  Components := TDesignerSelections.Create;
  FContinue := True;
  Components.Add(Component);
  FFirst := nil;
  FBest := nil;
  try
    GetComponentProperties(Components, tkAny, Designer, CheckEdit);
    if FContinue then
      if Assigned(FBest) then
        FBest.Edit
      else if Assigned(FFirst) then
        FFirst.Edit;
  finally
    FFirst := nil;
    FBest := nil;
  end;
end;

{ RegisterComponentEditor }
type
  PComponentClassRec = ^TComponentClassRec;
  TComponentClassRec = record
    Group: Integer;
    ComponentClass: TComponentClass;
    EditorClass: TComponentEditorClass;
  end;

var
  ComponentClassList: TList = nil;

procedure RegisterComponentEditor(ComponentClass: TComponentClass;
  ComponentEditor: TComponentEditorClass);
var
  P: PComponentClassRec;
begin
  if ComponentClassList = nil then
    ComponentClassList := TList.Create;
  New(P);
  P.Group := CurrentGroup;
  P.ComponentClass := ComponentClass;
  P.EditorClass := ComponentEditor;
  ComponentClassList.Insert(0, P);
end;

{ GetComponentEditor }

function GetComponentEditor(Component: TComponent;
  const Designer: IDesigner): IComponentEditor;
var
  P: PComponentClassRec;
  I: Integer;
  ComponentClass: TComponentClass;
  EditorClass: TComponentEditorClass;
begin
  ComponentClass := TComponentClass(TPersistent);
  EditorClass := TDefaultEditor;
  if ComponentClassList <> nil then
    for I := 0 to ComponentClassList.Count-1 do
    begin
      P := ComponentClassList[I];
      if (Component is P^.ComponentClass) and
        (P^.ComponentClass <> ComponentClass) and
        (P^.ComponentClass.InheritsFrom(ComponentClass)) then
      begin
        EditorClass := P^.EditorClass;
        ComponentClass := P^.ComponentClass;
      end;
    end;
  Result := EditorClass.Create(Component, Designer) as IComponentEditor;
end;


{ TSelectionEditor }

constructor TSelectionEditor.Create(const ADesigner: IDesigner);
begin
  inherited Create(ADesigner);
  FDesigner := ADesigner;
end;

procedure TSelectionEditor.ExecuteVerb(Index: Integer; const List: IDesignerSelections);
begin
  // Intended for descendents to implement
end;

function TSelectionEditor.GetVerb(Index: Integer): string;
begin
  // Intended for descendents to implement
  Result := '';
end;

function TSelectionEditor.GetVerbCount: Integer;
begin
  // Intended for descendents to implement
  Result := 0;
end;

procedure TSelectionEditor.RequiresUnits(Proc: TGetStrProc);
begin
  // No implementation needed (see description in DesignIntf)
end;

procedure TSelectionEditor.PrepareItem(Index: Integer;
  const AItem: IMenuItem);
begin
  // Intended for descendents to implement
end;

type
  TSelectionEditorList = class(TInterfacedObject, ISelectionEditorList)
  private
    FList: IInterfaceList;
  protected
    procedure Add(AEditor: ISelectionEditor);
  public
    constructor Create;
    function Get(Index: Integer): ISelectionEditor;
    function GetCount: Integer;
    property Count: Integer read GetCount;
    property Items[Index: Integer]: ISelectionEditor read Get; default;
  end;

{ TSelectionEditorList }

procedure TSelectionEditorList.Add(AEditor: ISelectionEditor);
begin
  FList.Add(AEditor);
end;

constructor TSelectionEditorList.Create;
begin
  inherited;
  FList := TInterfaceList.Create;
end;

function TSelectionEditorList.Get(Index: Integer): ISelectionEditor;
begin
  Result := FList[Index] as ISelectionEditor;
end;

function TSelectionEditorList.GetCount: Integer;
begin
  Result := FList.Count;
end;

type
  TSelectionEditorDefinition = class(TObject)
  private
    FGroup: Integer;
    FClass: TClass;
    FEditor: TSelectionEditorClass;
  public
    constructor Create(AClass: TClass; AEditor: TSelectionEditorClass);
    function Matches(AClass: TClass): Boolean;
    property Editor: TSelectionEditorClass read FEditor;
  end;

  TSelectionEditorDefinitionList = class(TObjectList)
  protected
    function GetItem(Index: Integer): TSelectionEditorDefinition;
    procedure SetItem(Index: Integer; AObject: TSelectionEditorDefinition);
    procedure FreeEditorGroup(AGroup: Integer);
  public
    property Items[Index: Integer]: TSelectionEditorDefinition read GetItem write SetItem; default;
  end;

{ TSelectionEditorDefinition }

constructor TSelectionEditorDefinition.Create(AClass: TClass;
  AEditor: TSelectionEditorClass);
begin
  inherited Create;
  FGroup := CurrentGroup;
  FClass := AClass;
  FEditor := AEditor;
end;

function TSelectionEditorDefinition.Matches(AClass: TClass): Boolean;
begin
  Result := AClass.InheritsFrom(FClass);
end;

{ TSelectionEditorDefinitionList }

procedure TSelectionEditorDefinitionList.FreeEditorGroup(AGroup: Integer);
var
  I: Integer;
begin
  for I := Count - 1 downto 0 do
    if Items[I].FGroup = AGroup then
      Delete(I);
end;

function TSelectionEditorDefinitionList.GetItem(Index: Integer): TSelectionEditorDefinition;
begin
  Result := TSelectionEditorDefinition(inherited Items[Index]);
end;

procedure TSelectionEditorDefinitionList.SetItem(Index: Integer;
  AObject: TSelectionEditorDefinition);
begin
  inherited Items[Index] := AObject;
end;

var
  SelectionEditorDefinitionList: TSelectionEditorDefinitionList;

procedure RegisterSelectionEditor(AClass: TClass; AEditor: TSelectionEditorClass);
begin
  if not Assigned(SelectionEditorDefinitionList) then
    SelectionEditorDefinitionList := TSelectionEditorDefinitionList.Create;
  SelectionEditorDefinitionList.Add(TSelectionEditorDefinition.Create(AClass, AEditor));
end;

function GetSelectionEditors(const Designer: IDesigner;
  const Selections: IDesignerSelections): ISelectionEditorList; overload;
var
  LList: TSelectionEditorList;
  I: Integer;
  LCommonClass, LClass: TClass;
begin
  // either way we return this
  LList := TSelectionEditorList.Create;
  Result := LList as ISelectionEditorList;

  // find out who qualifies
  if Selections.Count > 0 then
  begin
    // grab the first class
    LCommonClass := Selections[0].ClassType;

    // now look for the common class
    for I := 1 to Selections.Count - 1 do
    begin
      LClass := Selections[I].ClassType;
      while LCommonClass <> TObject do
        if not LClass.InheritsFrom(LCommonClass) then
          LCommonClass := LCommonClass.ClassParent
        else
          Break;
    end;

    // now which selection editors qualify?
    for I := 0 to SelectionEditorDefinitionList.Count - 1 do
      if SelectionEditorDefinitionList[I].Matches(LCommonClass) then
        LList.Add(SelectionEditorDefinitionList[I].Editor.Create(Designer) as ISelectionEditor);
  end;
end;


function GetSelectionEditors(const Designer: IDesigner): ISelectionEditorList;
var
  LSelections: IDesignerSelections;
begin
  // what is selected?
  LSelections := TDesignerSelections.Create;
  Designer.GetSelections(LSelections);
  Result := GetSelectionEditors(Designer, LSelections);
end;

function GetSelectionEditors(const Designer: IDesigner;
  Component: TComponent): ISelectionEditorList;
var
  LSelections: IDesignerSelections;
begin
  LSelections := TDesignerSelections.Create;
  LSelections.Add(Component);
  Result := GetSelectionEditors(Designer, LSelections);
end;

{ TCustomModule }

constructor TCustomModule.Create(ARoot: TComponent; const ADesigner: IDesigner);
begin
  inherited Create(ARoot, ADesigner);
  FRoot := ARoot;
  FDesigner := ADesigner;
end;

destructor TCustomModule.Destroy;
begin
  FFinder.Free;
  inherited;
end;

procedure TCustomModule.ExecuteVerb(Index: Integer);
begin
  // Intended for descendents to implement
end;

function TCustomModule.GetAttributes: TCustomModuleAttributes;
begin
  Result := [];
end;

function TCustomModule.GetVerb(Index: Integer): string;
begin
  // Intended for descendents to implement
  Result := '';
end;

function TCustomModule.GetVerbCount: Integer;
begin
  // Intended for descendents to implement
  Result := 0;
end;

function TCustomModule.Nestable: Boolean;
begin
  Result := False;
end;

procedure TCustomModule.PrepareItem(Index: Integer;
  const AItem: IMenuItem);
begin
  // Intended for descendents to implement
end;

procedure TCustomModule.Saving;
begin
  // Intended for descendents to implement
end;

procedure TCustomModule.ValidateComponent(Component: TComponent);
begin
  if not ValidateComponentClass(TComponentClass(Component.ClassType)) then
    raise Exception.CreateResFmt(@sClassNotApplicable, [Component.ClassName]);
end;

function TCustomModule.ValidateComponentClass(ComponentClass: TComponentClass): Boolean;
var
  Base: TComponent;
begin
  if FFinder = nil then
  begin
    Base := Root;
    if Base.Owner <> nil then
      // If the root has an owner then we want to find classes in the owners
      // class group not just the root's. This represents what will be active
      // when the class is loaded at runtime.
      Base := Base.Owner;
    FFinder := TClassFinder.Create(TPersistentClass(Base.ClassType));
  end;
  while IsProxyClass(ComponentClass) do
    ComponentClass := TComponentClass(ComponentClass.ClassParent);
  // We should only accept classes that are the same as the streaming system
  // will see.
  Result := FFinder.GetClass(ComponentClass.ClassName) = ComponentClass;
end;

function ClassInheritsFrom(ClassType: TClass; const ClassName: string): Boolean;
begin
  Result := True;
  while ClassType <> nil do
    if ClassType.ClassNameIs(ClassName) then
      Exit
    else
      ClassType := ClassType.ClassParent;
  Result := False;
end;

function AncestorNameMatches(ClassType: TClass; AncestorClass: TClass): Boolean;
begin
  Result := ClassType.InheritsFrom(AncestorClass) or
    not ClassInheritsFrom(ClassType, AncestorClass.ClassName);
end;

{ package management }

var
  GroupNotifyList: TList;
  EditorGroupList: TBits;

function NewEditorGroup: Integer;
begin
  if EditorGroupList = nil then
    EditorGroupList := TBits.Create;
  CurrentGroup := EditorGroupList.OpenBit;
  EditorGroupList[CurrentGroup] := True;
  Result := CurrentGroup;
end;

procedure NotifyGroupChange(AProc: TGroupChangeProc);
begin
  UnnotifyGroupChange(AProc);
  if not Assigned(GroupNotifyList) then
    GroupNotifyList := TList.Create;
  GroupNotifyList.Add(@AProc);
end;

procedure UnnotifyGroupChange(AProc: TGroupChangeProc);
begin
  if Assigned(GroupNotifyList) then
    GroupNotifyList.Remove(@AProc);
end;

procedure FreeEditorGroup(Group: Integer);
var
  I: Integer;
  P: PPropertyClassRec;
  C: PComponentClassRec;
  M: PPropertyMapperRec;
  SelectionDef: TSelectionEditorDefinition;
begin
  // Release all property editors associated with the group
  I := PropertyClassList.Count - 1;
  while I > -1 do
  begin
    P := PropertyClassList[I];
    if P.Group = Group then
    begin
      PropertyClassList.Delete(I);
      Dispose(P);
    end;
    Dec(I);
  end;
  // Release all component editors associated with the group
  I := ComponentClassList.Count - 1;
  while I > -1 do
  begin
    C := ComponentClassList[I];
    if C.Group = Group then
    begin
      ComponentClassList.Delete(I);
      Dispose(C);
    end;
    Dec(I);
  end;
  // Release all property mappers associated with the group
  if PropertyMapperList <> nil then
    for I := PropertyMapperList.Count-1 downto 0 do
    begin
      M := PropertyMapperList[I];
      if M.Group = Group then
      begin
        PropertyMapperList.Delete(I);
        Dispose(M);
      end;
    end;
  // Release all selection editors associated with the group
  if SelectionEditorDefinitionList <> nil then
    for I := SelectionEditorDefinitionList.Count-1 downto 0 do
    begin
      SelectionDef := SelectionEditorDefinitionList[I];
      if SelectionDef.FGroup = Group then
        SelectionEditorDefinitionList.Delete(I);
    end;
  // Notify everyone else that have similar registration lists that the group
  // is being unloaded.
  if Assigned(GroupNotifyList) then
    for I := GroupNotifyList.Count - 1 downto 0 do
      TGroupChangeProc(GroupNotifyList[I])(Group);
  // Free the group ID for use by another group
  if (Group >= 0) and (Group < EditorGroupList.Size) then
    EditorGroupList[Group] := False;
end;

{ TVariantTypeProperty }

var
  VarTypeNames: array[varEmpty..varInt64] of string = (
    'Unassigned', // varEmpty
    'Null',       // varNull
    'Smallint',   // varSmallint
    'Integer',    // varInteger
    'Single',     // varSingle
    'Double',     // varDouble
    'Currency',   // varCurrency
    'Date',       // varDate
    'OleStr',     // varOleStr
    '',           // varDispatch
    '',           // varError
    'Boolean',    // varBoolean
    '',           // varVariant
    '',           // varUnknown
    '',           // [varDecimal]
    '',           // [undefined]
    'Shortint',   // varShortInt
    'Byte',       // varByte
    'Word',       // varWord
    'LongWord',   // varLongWord
    'Int64');     // varInt64

type
  TVariantTypeProperty = class(TNestedProperty)
  public
    function AllEqual: Boolean; override;
    function GetAttributes: TPropertyAttributes; override;
    function GetName: string; override;
    function GetValue: string; override;
    procedure GetValues(Proc: TGetStrProc); override;
    procedure SetValue(const Value: string); override;
   end;

function TVariantTypeProperty.AllEqual: Boolean;
var
  i: Integer;
  V1, V2: Variant;
begin
  Result := False;
  if PropCount > 1 then
  begin
    V1 := GetVarValue;
    for i := 1 to PropCount - 1 do
    begin
      V2 := GetVarValueAt(i);
      if VarType(V1) <> VarType(V2) then Exit;
    end;
  end;
  Result := True;
end;

function TVariantTypeProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paMultiSelect, paValueList, paSortList];
end;

function TVariantTypeProperty.GetName: string;
begin
  Result := 'Type';
end;

function TVariantTypeProperty.GetValue: string;
begin
  case VarType(GetVarValue) and varTypeMask of
    Low(VarTypeNames)..High(VarTypeNames):
      Result := VarTypeNames[VarType(GetVarValue)];
    varString:
      Result := SString;
  else
    Result := SUnknown;
  end;
end;

procedure TVariantTypeProperty.GetValues(Proc: TGetStrProc);
var
  i: Integer;
begin
  for i := 0 to High(VarTypeNames) do
    if VarTypeNames[i] <> '' then
      Proc(VarTypeNames[i]);
  Proc(SString);
end;

procedure TVariantTypeProperty.SetValue(const Value: string);

  function GetSelectedType: Integer;
  var
    i: Integer;
  begin
    Result := -1;
    for i := 0 to High(VarTypeNames) do
      if VarTypeNames[i] = Value then
      begin
        Result := i;
        break;
      end;
    if (Result = -1) and (Value = SString) then
      Result := varString;
  end;

var
  NewType: Integer;
  V: Variant;
begin
  V := GetVarValue;
  NewType := GetSelectedType;
  case NewType of
    varEmpty: VarClear(V);
    varNull: V := NULL;
    -1: raise Exception.CreateRes(@SUnknownType);
  else
    try
      VarCast(V, V, NewType);
    except
      { If it cannot cast, clear it and then cast again. }
      VarClear(V);
      VarCast(V, V, NewType);
    end;
  end;
  SetVarValue(V);
end;

{ TVariantProperty }

function TVariantProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paMultiSelect, paSubProperties];
end;

procedure TVariantProperty.GetProperties(Proc: TGetPropProc);
begin
  Proc(TVariantTypeProperty.Create(Self));
end;

function TVariantProperty.GetValue: string;

  function GetVariantStr(const Value: Variant): string;
  begin
    case VarType(Value) of
      varBoolean:
        Result := BooleanIdents[Value = True];
      varCurrency:
        Result := CurrToStr(Value);
    else
      Result := VarToStrDef(Value, SNull);
    end;
  end;

var
  Value: Variant;
begin
  Value := GetVarValue;
  if VarType(Value) <> varDispatch then
    Result := GetVariantStr(Value)
  else
    Result := 'ERROR';
end;

procedure TVariantProperty.SetValue(const Value: string);

  function Cast(var Value: Variant; NewType: Integer): Boolean;
  var
    V2: Variant;
  begin
    Result := True;
    if NewType = varCurrency then
      Result := AnsiPos(CurrencyString, Value) > 0;
    if Result then
    try
      VarCast(V2, Value, NewType);
      Result := (NewType = varDate) or (VarToStr(V2) = VarToStr(Value));
      if Result then Value := V2;
    except
      Result := False;
    end;
  end;

var
  V: Variant;
  OldType: Integer;
begin
  OldType := VarType(GetVarValue);
  V := Value;
  if Value = '' then
    VarClear(V) else
  if (CompareText(Value, SNull) = 0) then
    V := NULL else
  if not Cast(V, OldType) then
    V := Value;
  SetVarValue(V);
end;

{ TEditActionSelectionEditor }

resourcestring
  sEditSubmenu = 'Edit';
  sUndoComponent = 'Undo';
  sCutComponent = 'Cut';
  sCopyComponent = 'Copy';
  sPasteComponent = 'Paste';
  sDeleteComponent = 'Delete';
  sSelectAllComponent = 'Select All';
  sControlSubmenu = 'Control';
  sToFrontControl = 'Bring to Front';
  sToBackControl = 'Send to Back';

function TEditActionSelectionEditor.GetVerb(Index: Integer): string;
begin
  case Index of
    0: Result := sEditSubmenu;
    1: Result := sControlSubmenu;
  end;
end;

function TEditActionSelectionEditor.GetVerbCount: Integer;
begin
  Result := 2;
end;

procedure TEditActionSelectionEditor.PrepareItem(Index: Integer; const AItem: IMenuItem);
var
  LEditState: TEditState;
begin
  case Index of
    0: // edit
      with AItem do
      begin
        LEditState := GetEditState;
        Enabled := ([esCanUndo, esCanCut, esCanCopy, esCanPaste, esCanDelete, esCanSelectAll] * LEditState) <> [];
        AddItem(sUndoComponent, 0, False, esCanUndo in LEditState, HandleUndo);
        AddLine;
        AddItem(sCutComponent, 0, False, esCanCut in LEditState, HandleCut);
        AddItem(sCopyComponent, 0, False, esCanCopy in LEditState, HandleCopy);
        AddItem(sPasteComponent, 0, False, esCanPaste in LEditState, HandlePaste);
        AddItem(sDeleteComponent, 0, False, esCanDelete in LEditState, HandleDelete);
        AddLine;
        AddItem(sSelectAllComponent, 0, False, esCanSelectAll in LEditState, HandleSelectAll);
      end;
    1: // control
      with AItem do
      begin
        LEditState := GetEditState;
        Visible := esCanZOrder in LEditState;
        AddItem(sToFrontControl, 0, False, True, HandleToFront);
        AddItem(sToBackControl, 0, False, True, HandleToBack);
      end;
  end;
end;

procedure TEditActionSelectionEditor.HandleToFront(Sender: TObject);
begin
  EditAction(eaBringToFront);
end;

procedure TEditActionSelectionEditor.HandleToBack(Sender: TObject);
begin
  EditAction(eaSendToBack);
end;

procedure TEditActionSelectionEditor.HandleUndo(Sender: TObject);
begin
  EditAction(eaUndo);
end;

procedure TEditActionSelectionEditor.HandleCut(Sender: TObject);
begin
  EditAction(eaCut);
end;

procedure TEditActionSelectionEditor.HandleCopy(Sender: TObject);
begin
  EditAction(eaCopy);
end;

procedure TEditActionSelectionEditor.HandlePaste(Sender: TObject);
begin
  EditAction(eaPaste);
end;

procedure TEditActionSelectionEditor.HandleDelete(Sender: TObject);
begin
  EditAction(eaDelete);
end;

procedure TEditActionSelectionEditor.HandleSelectAll(Sender: TObject);
begin
  EditAction(eaSelectAll);
end;

procedure TEditActionSelectionEditor.EditAction(Action: TEditAction);
var
  LTopComponent: TComponent;
  LEditHandler: IEditHandler;
begin
  LTopComponent := nil;
  if Assigned(GetTopLevelComponentFunc) then
    LTopComponent := GetTopLevelComponentFunc;
  if Supports(LTopComponent, IEditHandler, LEditHandler) or
     Supports(Designer, IEditHandler, LEditHandler) then
    LEditHandler.EditAction(Action);
end;

function TEditActionSelectionEditor.GetEditState: TEditState;
var
  LTopComponent: TComponent;
  LEditHandler: IEditHandler;
begin
  Result := [];
  LTopComponent := nil;
  if Assigned(GetTopLevelComponentFunc) then
    LTopComponent := GetTopLevelComponentFunc;
  if Supports(LTopComponent, IEditHandler, LEditHandler) or
     Supports(Designer, IEditHandler, LEditHandler) then
    Result := LEditHandler.GetEditState;
end;

initialization
  { Hook the DesignIntf registration routines }
  DesignIntf.RegisterPropertyEditorProc := RegisterPropertyEditor;
  DesignIntf.RegisterPropertyMapperProc := RegisterPropertyMapper;
  DesignIntf.RegisterComponentEditorProc := RegisterComponentEditor;
  DesignIntf.RegisterSelectionEditorProc := RegisterSelectionEditor;
  DesignIntf.SetPropertyEditorGroupProc := SetPropertyEditorGroup;

finalization
  { Unhook DesignIntf registration routines }
  DesignIntf.RegisterPropertyEditorProc := nil;
  DesignIntf.RegisterPropertyMapperProc := nil;
  DesignIntf.RegisterComponentEditorProc := nil;
  DesignIntf.RegisterSelectionEditorProc := nil;
  DesignIntf.SetPropertyEditorGroupProc := nil;
  
end.
