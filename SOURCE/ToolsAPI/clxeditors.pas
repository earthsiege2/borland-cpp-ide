{ ********************************************************************** }
{                                                                        }
{ Delphi and Kylix Cross-Platform Open Tools API                         }
{                                                                        }
{ Copyright (C) 2000, 2001 Borland Software Corporation                  }
{                                                                        }
{ ********************************************************************** }


unit ClxEditors;

interface

uses 
  Classes, DesignIntf, DesignEditors, DesignMenus, DsnConst, QControls, QForms,
  QMenus, ClxImgEdit, QImgList, QActnList, QDialogs;

{ Custom Module Types }

type

{ ICustomDesignForm
  Allows a custom module to create a different form for use by the designer
  as the base form.

    CreateDesignForm
      Create a descendent of TCustomForm for use by the designer as the
      instance to design }
  ICustomDesignForm = interface
    ['{833D4D25-3E3D-44DB-82CC-117C02C778B1}']
    procedure CreateDesignerForm(const Designer: IDesigner; Root: TComponent;
      out DesignForm: TCustomForm; out ComponentContainer: TWidgetControl);
  end;

  TAlignProperty = class(TEnumProperty)
  public
    procedure GetValues(Proc: TGetStrProc); override;
  end;


{ TColorProperty
  Property editor for the TColor type.  Displays the color as a clXXX value
  if one exists, otherwise displays the value as hex.  Also allows the
  clXXX value to be picked from a list. }

  TColorProperty = class(TIntegerProperty)
  public
    procedure Edit; override;
    function GetAttributes: TPropertyAttributes; override;
    function GetValue: string; override;
    procedure GetValues(Proc: TGetStrProc); override;
    procedure SetValue(const Value: string); override;
  end;

{ TCursorProperty
  Property editor for the TCursor type.  Displays the cursor as a clXXX value
  if one exists, otherwise displays the value as hex.  Also allows the
  clXXX value to be picked from a list. }

  TCursorProperty = class(TIntegerProperty)
  public
    function GetAttributes: TPropertyAttributes; override;
    function GetValue: string; override;
    procedure GetValues(Proc: TGetStrProc); override;
    procedure SetValue(const Value: string); override;
  end;

{ TFontProperty
  Property editor for the Font property.  Brings up the font dialog as well as
  allowing the properties of the object to be edited. }

  TFontProperty = class(TClassProperty)
  public
    procedure Edit; override;
    function GetAttributes: TPropertyAttributes; override;
  end;

{ TFontNameProperty
  Property editor for the Font's Name property. Displays a drop-down list of all
  the fonts known by Qt. }
  TFontNameProperty = class(TStringProperty)
  public
    function GetAttributes: TPropertyAttributes; override;
    procedure GetValues(Proc: TGetStrProc); override;
  end;

{ TShortCutProperty
  Property editor the ShortCut property.  Allows both typing in a short
  cut value or picking a short-cut value from a list. }

  TShortCutProperty = class(TOrdinalProperty)
  public
    function GetAttributes: TPropertyAttributes; override;
    function GetValue: string; override;
    procedure GetValues(Proc: TGetStrProc); override;
    procedure SetValue(const Value: string); override;
  end;

{ TTabOrderProperty
  Property editor for the TabOrder property.  Prevents the property from being
  displayed when more than one component is selected. }

  TTabOrderProperty = class(TIntegerProperty)
  public
    function GetAttributes: TPropertyAttributes; override;
  end;

{ TCaptionProperty
  Property editor for the Caption and Text properties.  Updates the value of
  the property for each change instead on when the property is approved. }

  TCaptionProperty = class(TStringProperty)
  public
    function GetAttributes: TPropertyAttributes; override;
  end;

type
  TImageListEditor = class(TComponentEditor)
  public
    procedure Edit; override;
    procedure ExecuteVerb(Index: Integer); override;
    function GetVerb(Index: Integer): string; override;
    function GetVerbCount: Integer; override;
  end;

type
  TModalResultProperty = class(TIntegerProperty)
  public
    function GetAttributes: TPropertyAttributes; override;
    function GetValue: string; override;
    procedure GetValues(Proc: TGetStrProc); override;
    procedure SetValue(const Value: string); override;
  end;

  TFileNameProperty = class(TStringProperty)
  protected
    procedure GetDialogOptions(Dialog: TOpenDialog); virtual;
  public
    procedure Edit; override;
    function GetAttributes: TPropertyAttributes; override;
  end;

  THTMLFileNameProperty = class(TFileNameProperty)
  protected
    procedure GetDialogOptions(Dialog: TOpenDialog); override;
  end;

  TNotifyActionListChange = procedure;

procedure CopyStreamToClipboard(S: TStream);
function GetClipboardStream: TMemoryStream;

var
  NotifyActionListChange: TNotifyActionListChange = nil;

procedure RegActions(const ACategory: string;
  const AClasses: array of TBasicActionClass; AResource: TComponentClass);
procedure UnRegActions(const Classes: array of TBasicActionClass);
procedure EnumActions(Proc: TEnumActionProc; Info: Pointer);
function CreateAction(AOwner: TComponent; ActionClass: TBasicActionClass): TBasicAction;

implementation

uses SysUtils, TypInfo, Qt, QConsts, QGraphics, QClipbrd, LibHelp, DesignConst;

{ TColorProperty }

procedure TColorProperty.Edit;
var
  ColorDialog: TColorDialog;
begin
  ColorDialog := TColorDialog.Create(Application);
  try
    ColorDialog.Color := GetOrdValue;
    // TODO 3 -oCPJ: Figure out how to preserve the custom colors
    ColorDialog.HelpContext := hcDColorEditor;
    ColorDialog.HelpType := htContext;
    if ColorDialog.Execute then SetOrdValue(ColorDialog.Color);
  finally
    ColorDialog.Free;
  end;
end;

function TColorProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paMultiSelect, paDialog, paValueList, paRevertable];
end;

function TColorProperty.GetValue: string;
begin
  Result := ColorToString(TColor(GetOrdValue));
end;

procedure TColorProperty.GetValues(Proc: TGetStrProc);
begin
  GetColorValues(Proc);
end;

procedure TColorProperty.SetValue(const Value: string);
var
  NewValue: Longint;
begin
  if IdentToColor(Value, NewValue) then
    SetOrdValue(NewValue)
  else
    inherited SetValue(Value);
end;

{ TCursorProperty }

function TCursorProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paMultiSelect, paValueList, paSortList, paRevertable];
end;

function TCursorProperty.GetValue: string;
begin
  Result := CursorToString(TCursor(GetOrdValue));
end;

procedure TCursorProperty.GetValues(Proc: TGetStrProc);
begin
  GetCursorValues(Proc);
end;

procedure TCursorProperty.SetValue(const Value: string);
var
  NewValue: Longint;
begin
  if IdentToCursor(Value, NewValue) then
    SetOrdValue(NewValue)                                                       
  else inherited SetValue(Value);
end;

{ TFontProperty }

procedure TFontProperty.Edit;
var
  FontDialog: TFontDialog;
begin
  FontDialog := TFontDialog.Create(Application);
  try
    FontDialog.Font := TFont(GetOrdValue);
    FontDialog.HelpContext := hcDFontEditor;
    FontDialog.HelpType := htContext;
    // TODO 4 -oCPJ: Figure out what these TFont dialog options mean for CLX
    // FontDialog.Options := FontDialog.Options + [fdShowHelp, fdForceFontExist];
    if FontDialog.Execute then SetOrdValue(Longint(FontDialog.Font));
  finally
    FontDialog.Free;
  end;
end;

function TFontProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paMultiSelect, paSubProperties, paDialog, paReadOnly];
end;

{ TFontNameProperty }

function TFontNameProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paMultiSelect, paValueList, paSortList, paRevertable];
end;

procedure TFontNameProperty.GetValues(Proc: TGetStrProc);
var
  I: Integer;
begin
  for I := 0 to Screen.Fonts.Count - 1 do Proc(Screen.Fonts[I]);
end;

{ TShortCutProperty }

const
  ShortCuts: array[0..108] of TShortCut = (
    scNone,
    Byte('A') or scCtrl,
    Byte('B') or scCtrl,
    Byte('C') or scCtrl,
    Byte('D') or scCtrl,
    Byte('E') or scCtrl,
    Byte('F') or scCtrl,
    Byte('G') or scCtrl,
    Byte('H') or scCtrl,
    Byte('I') or scCtrl,
    Byte('J') or scCtrl,
    Byte('K') or scCtrl,
    Byte('L') or scCtrl,
    Byte('M') or scCtrl,
    Byte('N') or scCtrl,
    Byte('O') or scCtrl,
    Byte('P') or scCtrl,
    Byte('Q') or scCtrl,
    Byte('R') or scCtrl,
    Byte('S') or scCtrl,
    Byte('T') or scCtrl,
    Byte('U') or scCtrl,
    Byte('V') or scCtrl,
    Byte('W') or scCtrl,
    Byte('X') or scCtrl,
    Byte('Y') or scCtrl,
    Byte('Z') or scCtrl,
    Byte('A') or scCtrl or scAlt,
    Byte('B') or scCtrl or scAlt,
    Byte('C') or scCtrl or scAlt,
    Byte('D') or scCtrl or scAlt,
    Byte('E') or scCtrl or scAlt,
    Byte('F') or scCtrl or scAlt,
    Byte('G') or scCtrl or scAlt,
    Byte('H') or scCtrl or scAlt,
    Byte('I') or scCtrl or scAlt,
    Byte('J') or scCtrl or scAlt,
    Byte('K') or scCtrl or scAlt,
    Byte('L') or scCtrl or scAlt,
    Byte('M') or scCtrl or scAlt,
    Byte('N') or scCtrl or scAlt,
    Byte('O') or scCtrl or scAlt,
    Byte('P') or scCtrl or scAlt,
    Byte('Q') or scCtrl or scAlt,
    Byte('R') or scCtrl or scAlt,
    Byte('S') or scCtrl or scAlt,
    Byte('T') or scCtrl or scAlt,
    Byte('U') or scCtrl or scAlt,
    Byte('V') or scCtrl or scAlt,
    Byte('W') or scCtrl or scAlt,
    Byte('X') or scCtrl or scAlt,
    Byte('Y') or scCtrl or scAlt,
    Byte('Z') or scCtrl or scAlt,
    Key_F1,
    Key_F2,
    Key_F3,
    Key_F4,
    Key_F5,
    Key_F6,
    Key_F7,
    Key_F8,
    Key_F9,
    Key_F10,
    Key_F11,
    Key_F12,
    Key_F1 or scCtrl,
    Key_F2 or scCtrl,
    Key_F3 or scCtrl,
    Key_F4 or scCtrl,
    Key_F5 or scCtrl,
    Key_F6 or scCtrl,
    Key_F7 or scCtrl,
    Key_F8 or scCtrl,
    Key_F9 or scCtrl,
    Key_F10 or scCtrl,
    Key_F11 or scCtrl,
    Key_F12 or scCtrl,
    Key_F1 or scShift,
    Key_F2 or scShift,
    Key_F3 or scShift,
    Key_F4 or scShift,
    Key_F5 or scShift,
    Key_F6 or scShift,
    Key_F7 or scShift,
    Key_F8 or scShift,
    Key_F9 or scShift,
    Key_F10 or scShift,
    Key_F11 or scShift,
    Key_F12 or scShift,
    Key_F1 or scShift or scCtrl,
    Key_F2 or scShift or scCtrl,
    Key_F3 or scShift or scCtrl,
    Key_F4 or scShift or scCtrl,
    Key_F5 or scShift or scCtrl,
    Key_F6 or scShift or scCtrl,
    Key_F7 or scShift or scCtrl,
    Key_F8 or scShift or scCtrl,
    Key_F9 or scShift or scCtrl,
    Key_F10 or scShift or scCtrl,
    Key_F11 or scShift or scCtrl,
    Key_F12 or scShift or scCtrl,
    Key_Insert,
    Key_Insert or scShift,
    Key_Insert or scCtrl,
    Key_Delete,
    Key_Delete or scShift,
    Key_Delete or scCtrl,
    Key_Backspace or scAlt,
    Key_Backspace or scShift or scAlt);

function TShortCutProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paMultiSelect, paValueList, paRevertable];
end;

function TShortCutProperty.GetValue: string;
var
  CurValue: TShortCut;
begin
  CurValue := GetOrdValue;
  if CurValue = scNone then
    Result := srNone else
    Result := ShortCutToText(CurValue);
end;

procedure TShortCutProperty.GetValues(Proc: TGetStrProc);
var
  I: Integer;
begin
  Proc(srNone);
  for I := 1 to High(ShortCuts) do Proc(ShortCutToText(ShortCuts[I]));
end;

procedure TShortCutProperty.SetValue(const Value: string);
var
  NewValue: TShortCut;
begin
  NewValue := 0;
  if (Value <> '') and (AnsiCompareText(Value, srNone) <> 0) then
  begin
    NewValue := TextToShortCut(Value);
    if NewValue = 0 then
      raise EPropertyError.CreateRes(@sInvalidPropertyValue);
  end;
  SetOrdValue(NewValue);
end;

{ TTabOrderProperty }

function TTabOrderProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paRevertable];
end;

{ TCaptionProperty }

function TCaptionProperty.GetAttributes: TPropertyAttributes;
begin
  Result := inherited GetAttributes + [paAutoUpdate];
end;

{ TImageListEditor }

procedure TImageListEditor.Edit;
begin
  if EditImageList(Component as TImageList) and Assigned(Designer) then
    Designer.Modified;
end;

procedure TImageListEditor.ExecuteVerb(Index: Integer);
begin
  if EditImageList(Component as TImageList) and Assigned(Designer) then
    Designer.Modified;
end;

function TImageListEditor.GetVerb(Index: Integer): string;
begin
  Result := SImageListEditor;
end;

function TImageListEditor.GetVerbCount: Integer;
begin
  Result := 1;
end;

{ Clipboard routines }

procedure CopyStreamToClipboard(S: TStream);
var
  T: TStringStream;
  I: TValueType;
  V: Integer;
begin
//  Clipboard.Open;
//  try
    //Clipboard.SetFormat(SDelphiComponent, S);
    S.Position := 0;
    T := TStringStream.Create('');
    try
      repeat
        S.Read(I, SizeOf(I));
        S.Seek(-SizeOf(I), 1);
        if I = vaNull then Break;
        ObjectBinaryToText(S, T);
      until False;
      V := 0;
      T.Write(V, 1);
      Clipboard.AsText := T.DataString;
    finally
      T.Free;
    end;
//  finally
//    Clipboard.Close;
//  end;
end;

function GetClipboardStream: TMemoryStream;
var
  S, T: TMemoryStream;
  Format: string;
  V: TValueType;

  function AnotherObject(S: TStream): Boolean;
  var
    Buffer: array[0..255] of Char;
    Position: Integer;
  begin
    Position := S.Position;
    Buffer[S.Read(Buffer, SizeOf(Buffer))-1] := #0;
    S.Position := Position;
    Result := PossibleStream(Buffer);
  end;

begin
  Result := TMemoryStream.Create;
  try
    {if Clipboard.Provides(SDelphiComponent) then
      Format := SDelphiComponent else}
      Format := 'text/plain';
    Clipboard.GetFormat(Format, Result);
    Result.Position := 0;
    Result.Size := StrLen(Result.Memory);
    {if Format <> SDelphiComponent then
    begin}
      S := TMemoryStream.Create;
      try
        while AnotherObject(Result) do ObjectTextToBinary(Result, S);
        V := vaNull;
        S.Write(V, SizeOf(V));
        T := Result;
        Result := nil;
        T.Free;
      except
        S.Free;
        raise;
      end;
      Result := S;
      Result.Position := 0;
    {end;}
  except
    Result.Free;
    raise;
  end;
end;

{ TModalResultProperty }

const
  ModalResults: array[mrNone..mrYesToAll] of string = (
    'mrNone',
    'mrOk',
    'mrCancel',
    'mrYes',
    'mrNo',
    'mrAbort',
    'mrRetry',
    'mrIgnore',
    'mrAll',
    'mrNoToAll',
    'mrYesToAll');


function TModalResultProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paMultiSelect, paValueList, paRevertable];
end;

function TModalResultProperty.GetValue: string;
var
  CurValue: Longint;
begin
  CurValue := GetOrdValue;
  case CurValue of
    Low(ModalResults)..High(ModalResults):
      Result := ModalResults[CurValue];
  else
    Result := IntToStr(CurValue);
  end;
end;

procedure TModalResultProperty.GetValues(Proc: TGetStrProc);
var
  I: Integer;
begin
  for I := Low(ModalResults) to High(ModalResults) do Proc(ModalResults[I]);
end;

procedure TModalResultProperty.SetValue(const Value: string);
var
  I: Integer;
begin
  if Value = '' then
  begin
    SetOrdValue(0);
    Exit;
  end;
  for I := Low(ModalResults) to High(ModalResults) do
    if CompareText(ModalResults[I], Value) = 0 then
    begin
      SetOrdValue(I);
      Exit;
    end;
  inherited SetValue(Value);
end;

{ TFileNameProperty }

procedure TFileNameProperty.GetDialogOptions(Dialog: TOpenDialog);
begin
  Dialog.Filter := SAllFiles;
  Dialog.Options := Dialog.Options + [ofFileMustExist];
end;

procedure TFileNameProperty.Edit;
var
  OpenDialog: TOpenDialog;
begin
  OpenDialog := TOpenDialog.Create(nil);
  GetDialogOptions(OpenDialog);
  if OpenDialog.Execute then
    SetValue(OpenDialog.FileName);
  OpenDialog.Free;
end;

function TFileNameProperty.GetAttributes: TPropertyAttributes;
begin
  Result := [paRevertable, paDialog, paMultiSelect];
end;

{ THTMLFileNameProperty }

resourcestring
{$IFDEF LINUX}
  sHTMLFilter = 'html files (*.htm *.html)';
{$ENDIF}
{$IFDEF MSWINDOWS}
  sHTMLFilter = 'html files (*.htm;*.html)';
{$ENDIF}

procedure THTMLFileNameProperty.GetDialogOptions(Dialog: TOpenDialog);
begin
  inherited GetDialogOptions(Dialog);
  Dialog.Filter := sHTMLFilter;
end;

type
  TBasicActionRecord = record
    ActionClass: TBasicActionClass;
    GroupId: Integer;
  end;

  TActionClassArray = array of TBasicActionRecord;

  TActionClassesEntry = record
    Category: string;
    Actions: TActionClassArray;
    Resource: TComponentClass;
  end;

  TActionClassesArray = array of TActionClassesEntry;

var
  ActionClasses: TActionClassesArray = nil;

procedure RegActions(const ACategory: string;
  const AClasses: array of TBasicActionClass; AResource: TComponentClass);
var
  CategoryIndex, Len, I, J, NewClassCount: Integer;
  NewClasses: array of TBasicActionClass;
  Skip: Boolean;
  S: string;
begin
  { Determine whether we're adding a new category, or adding to an existing one }
  CategoryIndex := -1;
  for I := Low(ActionClasses) to High(ActionClasses) do
    if CompareText(ActionClasses[I].Category, ACategory) = 0 then
    begin
      CategoryIndex := I;
      Break;
    end;

  { Adding a new category }
  if CategoryIndex = -1 then
  begin
    CategoryIndex := Length(ActionClasses);
    SetLength(ActionClasses, CategoryIndex + 1);
  end;

  with ActionClasses[CategoryIndex] do
  begin
    SetLength(NewClasses, Length(AClasses));
    { Remove duplicate classes }
    NewClassCount := 0;
    for I := Low(AClasses) to High(AClasses) do
    begin
      Skip := False;
      for J := Low(Actions) to High(Actions) do
        if AClasses[I] = Actions[I].ActionClass then
        begin
          Skip := True;
          Break;
        end;
      if not Skip then
      begin
        NewClasses[Low(NewClasses) + NewClassCount] := AClasses[I];
        Inc(NewClassCount);
      end;
    end;

    { Pack NewClasses }
    SetLength(NewClasses, NewClassCount);

    SetString(S, PChar(ACategory), Length(ACategory));
    Category := S;
    Resource := AResource;
    Len := Length(Actions);
    SetLength(Actions, Len + Length(NewClasses));
    for I := Low(NewClasses) to High(NewClasses) do
    begin
      RegisterNoIcon([NewClasses[I]]);
      RegisterClass(NewClasses[I]);
      with Actions[Len + I] do
      begin
        ActionClass := NewClasses[I];
        GroupId := CurrentGroup;
      end;
    end;
  end;
  { Notify all available designers of new TAction class }
  if Assigned(NotifyActionListChange) then
    NotifyActionListChange;
end;

procedure UnRegActions(const Classes: array of TBasicActionClass);//! far;
var
  I, J, K: Integer;
  LActionClass: TBasicActionClass;
begin
  for I := Low(Classes) to High(Classes) do
  begin
    LActionClass := Classes[I];
    for J := Low(ActionClasses) to High(ActionClasses) do
      for K := Low(ActionClasses[J].Actions) to High(ActionClasses[J].Actions) do
        with ActionClasses[J].Actions[K] do
          if LActionClass = ActionClass then
          begin
            ActionClass := nil;
            GroupId := -1;
          end;
  end;
  if Assigned(NotifyActionListChange) then
    NotifyActionListChange;
end;

procedure UnregisterActionGroup(AGroupId: Integer);
var
  I, J: Integer;
begin
  for I := Low(ActionClasses) to High(ActionClasses) do
    for J := Low(ActionClasses[I].Actions) to High(ActionClasses[I].Actions) do
      with ActionClasses[I].Actions[J] do
        if GroupId = AGroupId then
        begin
          ActionClass := nil;
          GroupId := -1;
        end;
  if Assigned(NotifyActionListChange) then
    NotifyActionListChange;
end;

procedure EnumActions(Proc: TEnumActionProc; Info: Pointer);
var
  I, J, Count: Integer;
  ActionClass: TBasicActionClass;
begin
  if ActionClasses <> nil then
    for I := Low(ActionClasses) to High(ActionClasses) do
    begin
      Count := 0;
      for J := Low(ActionClasses[I].Actions) to High(ActionClasses[I].Actions) do
      begin
        ActionClass := ActionClasses[I].Actions[J].ActionClass;
        if ActionClass = nil then
          Continue;
        Proc(ActionClasses[I].Category, ActionClass, Info);
        Inc(Count);
      end;
      if Count = 0 then
        SetLength(ActionClasses[I].Actions, 0);
    end;
end;

type
  THackAction = class(TCustomAction);

function CreateAction(AOwner: TComponent; ActionClass: TBasicActionClass): TBasicAction;
var
  I, J: Integer;
  Res: TComponentClass;
  Instance: TComponent;
  Action: TBasicAction;

  function FindComponentByClass(AOwner: TComponent; const AClassName: string): TComponent;
  var
    I: Integer;
  begin
    if (AClassName <> '') and (AOwner.ComponentCount > 0) then
      for I := 0 to AOwner.ComponentCount - 1 do
      begin
        Result := AOwner.Components[I];
        if CompareText(Result.ClassName, AClassName) = 0 then Exit;
      end;
    Result := nil;
  end;

  procedure CreateMaskedBmp(ImageList: TCustomImageList; ImageIndex: Integer;
    var Image, Mask: TBitmap);
  begin
    Image := TBitmap.Create;
    try
      Mask := TBitmap.Create;
      try
        with Image do
        begin
          Height := ImageList.Height;
          Width := ImageList.Width;
        end;
        with Mask do
        begin
          Height := ImageList.Height;
          Width := ImageList.Width;
          Monochrome := True;
        end;
        ImageList.Draw(Image.Canvas, 0, 0, ImageIndex);
        ImageList.Draw(Mask.Canvas, 0, 0, ImageIndex, itMask);
      except
        FreeAndNil(Mask);
        raise;
      end;
    except
      FreeAndNil(Image);
      raise
    end;
  end;

begin
  Result := ActionClass.Create(AOwner);
  { Attempt to find the first action with the same class Type as ActionClass in
    the Resource component's resource stream, and use its property values as
    our defaults. }
  Res := nil;
  for I := Low(ActionClasses) to High(ActionClasses) do
    with ActionClasses[I] do
      for J := Low(Actions) to High(Actions) do
        if Actions[J].ActionClass = ActionClass then
        begin
          Res := Resource;
          Break;
        end;
  if Res <> nil then
  begin
    Instance := Res.Create(nil);
    try
      Action := FindComponentByClass(Instance, ActionClass.ClassName) as TBasicAction;
      if Action <> nil then
      begin
        with Action as TCustomAction do
        begin
          TCustomAction(Result).Caption := Caption;
          TCustomAction(Result).Checked := Checked;
          TCustomAction(Result).Enabled := Enabled;
          TCustomAction(Result).HelpContext := HelpContext;
          TCustomAction(Result).Hint := Hint;
          TCustomAction(Result).ImageIndex := ImageIndex;
          TCustomAction(Result).ShortCut := ShortCut;
          TCustomAction(Result).Visible := Visible;
          if (ImageIndex > -1) and (ActionList <> nil) and
            (ActionList.Images <> nil) then
          begin
            THackAction(Result).FImage.Free;
            THackAction(Result).FMask.Free;
            CreateMaskedBmp(ActionList.Images, ImageIndex,
              TBitmap(THackAction(Result).FImage),
              TBitmap(THackAction(Result).FMask));
          end;
        end;
      end;
    finally
      Instance.Free;
    end;
  end;
end;

{ TAlignProperty }

procedure TAlignProperty.GetValues(Proc: TGetStrProc);

  function AlignNames(AAlign: TAlign): string;
  begin
    if AAlign in [AlNone..alClient] then
      Result := GetEnumName(TypeInfo(TAlign), Ord(AAlign)); 
  end;

var
  AAlign: TAlign;
begin
  for AAlign := alNone to alClient do Proc(AlignNames(AAlign));
end;

initialization
  NotifyGroupChange(UnregisterActionGroup);

finalization
  UnNotifyGroupChange(UnregisterActionGroup);

end.
