
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1995,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit Mask;

{$R-,T-,H+,X+}

interface

uses Windows, SysUtils, Classes, StdCtrls, Controls, Messages,
  Forms, Graphics, Menus;

const
  DefaultBlank: Char = '_';
  MaskFieldSeparator: Char = ';';
  MaskNoSave: Char = '0';

  mDirReverse = '!';         { removes leading blanks if true, else trailing blanks}
  mDirUpperCase = '>';       { all chars that follow to upper case }
  mDirLowerCase = '<';       { all chars that follow to lower case }
                             { '<>' means remove casing directive }
  mDirLiteral = '\';         { char that immediately follows is a literal }

  mMskAlpha = 'L';           { in US = A-Z,a-z }
  mMskAlphaOpt = 'l';
  mMskAlphaNum = 'A';        { in US = A-Z,a-z,0-9 }
  mMskAlphaNumOpt  = 'a';
  mMskAscii = 'C';           { any character}
  mMskAsciiOpt = 'c';
  mMskNumeric = '0';         { 0-9, no plus or minus }
  mMskNumericOpt = '9';
  mMskNumSymOpt = '#';       { 0-9, plus and minus }

   { intl literals }
  mMskTimeSeparator = ':';
  mMskDateSeparator = '/';

type

  TMaskCharType = (mcNone, mcLiteral, mcIntlLiteral, mcDirective, mcMask,
    mcMaskOpt, mcFieldSeparator, mcField);
  TMaskDirectives = set of (mdReverseDir, mdUpperCase, mdLowerCase,
    mdLiteralChar);

type
{ Exception class }
  EDBEditError = class(Exception);

  TMaskedState = set of (msMasked, msReEnter, msDBSetText);

{ TCustomMaskEdit }

  TCustomMaskEdit = class(TCustomEdit)
  private
    FEditMask: string;
    FMaskBlank: Char;
    FMaxChars: Integer;
    FMaskSave: Boolean;
    FMaskState: TMaskedState;
    FCaretPos: Integer;
    FBtnDownX: Integer;
    FOldValue: string;
    FSettingCursor: Boolean;
    function DoInputChar(var NewChar: Char; MaskOffset: Integer): Boolean;
    function InputChar(var NewChar: Char; Offset: Integer): Boolean;
    function DeleteSelection(var Value: string; Offset: Integer;
      Len: Integer): Boolean;
    function InputString(var Value: string; const NewValue: string;
      Offset: Integer): Integer;
    function AddEditFormat(const Value: string; Active: Boolean): string;
    function RemoveEditFormat(const Value: string): string;
    function FindLiteralChar (MaskOffset: Integer; InChar: Char): Integer;
    function GetEditText: string;
    function GetMasked: Boolean;
    function GetText: string;
    function GetMaxLength: Integer;
    function CharKeys(var CharCode: Char): Boolean;
    procedure SetEditText(const Value: string);
    procedure SetEditMask(const Value: string);
    procedure SetMaxLength(Value: Integer);
    procedure SetText(const Value: string);
    procedure DeleteKeys(CharCode: Word);
    procedure HomeEndKeys(CharCode: Word; Shift: TShiftState);
    procedure CursorInc(CursorPos: Integer; Incr: Integer);
    procedure CursorDec(CursorPos: Integer);
    procedure ArrowKeys(CharCode: Word; Shift: TShiftState);
    procedure WMLButtonDown(var Message: TWMLButtonDown); message WM_LBUTTONDOWN;
    procedure WMLButtonUp(var Message: TWMLButtonUp); message WM_LBUTTONUP;
    procedure WMSetFocus(var Message: TWMSetFocus); message WM_SETFOCUS;
    procedure WMCut(var Message: TMessage); message WM_CUT;
    procedure WMPaste(var Message: TMessage); message WM_PASTE;
    procedure CMEnter(var Message: TCMEnter); message CM_ENTER;
    procedure CMExit(var Message: TCMExit);   message CM_EXIT;
    procedure CMTextChanged(var Message: TMessage); message CM_TEXTCHANGED;
    procedure CMWantSpecialKey(var Message: TCMWantSpecialKey); message CM_WANTSPECIALKEY;
  protected
    procedure ReformatText(const NewMask: string);
    procedure GetSel(var SelStart: Integer; var SelStop: Integer);
    procedure SetSel(SelStart: Integer; SelStop: Integer);
    procedure SetCursor(Pos: Integer);
    procedure KeyDown(var Key: Word; Shift: TShiftState); override;
    procedure KeyUp(var Key: Word; Shift: TShiftState); override;
    procedure KeyPress(var Key: Char); override;
    function EditCanModify: Boolean; virtual;
    procedure Reset; virtual;
    function GetFirstEditChar: Integer;
    function GetLastEditChar: Integer;
    function GetNextEditChar(Offset: Integer): Integer;
    function GetPriorEditChar(Offset: Integer): Integer;
    function GetMaxChars: Integer;
    function Validate(const Value: string; var Pos: Integer): Boolean; virtual;
    procedure ValidateError; virtual;
    procedure CheckCursor;
    property EditMask: string read FEditMask write SetEditMask;
    property MaskState: TMaskedState read FMaskState write FMaskState;
    property MaxLength: Integer read GetMaxLength write SetMaxLength default 0;
  public
    constructor Create(AOwner: TComponent); override;
    procedure ValidateEdit; virtual;
    procedure Clear; override;
    function GetTextLen: Integer;
    property IsMasked: Boolean read GetMasked;
    property EditText: string read GetEditText write SetEditText;
    property Text: string read GetText write SetText;
  end;

{ TMaskEdit }

  TMaskEdit = class(TCustomMaskEdit)
  published
    property Anchors;
    property AutoSelect;
    property AutoSize;
    property BiDiMode;
    property BorderStyle;
    property CharCase;
    property Color;
    property Constraints;
    property Ctl3D;
    property DragCursor;
    property DragKind;
    property DragMode;
    property Enabled;
    property EditMask;
    property Font;
    property ImeMode;
    property ImeName;
    property MaxLength;
    property ParentBiDiMode;
    property ParentColor;
    property ParentCtl3D;
    property ParentFont;
    property ParentShowHint;
    property PasswordChar;
    property PopupMenu;
    property ReadOnly;
    property ShowHint;
    property TabOrder;
    property TabStop;
    property Text;
    property Visible;
    property OnChange;
    property OnClick;
    property OnDblClick;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDock;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnKeyDown;
    property OnKeyPress;
    property OnKeyUp;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnStartDock;
    property OnStartDrag;
  end;

function FormatMaskText(const EditMask: string; const Value: string): string;
function MaskGetMaskSave(const EditMask: string): Boolean;
function MaskGetMaskBlank(const EditMask: string): Char;
function MaskGetFldSeparator(const EditMask: string): Integer;


implementation

uses Clipbrd, Consts;

{ Mask utility routines }

function MaskGetCharType(const EditMask: string; MaskOffset: Integer): TMaskCharType;
var
  MaskChar: Char;
begin
  Result := mcLiteral;
  MaskChar := #0;
  if MaskOffset <= Length(EditMask) then
    MaskChar := EditMask[MaskOffset];
  if MaskOffset > Length(EditMask) then
    Result := mcNone

  else if ByteType(EditMask, MaskOffset) <> mbSingleByte then
    Result := mcLiteral

  else if (MaskOffset > 1) and (EditMask[MaskOffset - 1] = mDirLiteral) and
      (ByteType(EditMask, MaskOffset - 1) = mbSingleByte) and
      not ((MaskOffset > 2) and (EditMask[MaskOffset - 2] = mDirLiteral) and
      (ByteType(EditMask, MaskOffset - 2) = mbSingleByte)) then
    Result := mcLiteral

  else if (MaskChar = MaskFieldSeparator) and
         (Length(EditMask) >= 4) and
         (MaskOffset > Length(EditMask) - 4) then
    Result := mcFieldSeparator

  else if (Length(EditMask) >= 4) and
         (MaskOffset > (Length(EditMask) - 4)) and
         (EditMask[MaskOffset - 1] = MaskFieldSeparator) and
         not ((MaskOffset > 2) and (EditMask[MaskOffset - 2] = mDirLiteral) and
         (ByteType(EditMask, MaskOffset - 2) <> mbTrailByte)) then
    Result := mcField

  else if MaskChar in [mMskTimeSeparator, mMskDateSeparator] then
    Result := mcIntlLiteral

  else if MaskChar in [mDirReverse, mDirUpperCase, mDirLowerCase,
      mDirLiteral] then
    Result := mcDirective

  else if MaskChar in [mMskAlphaOpt, mMskAlphaNumOpt, mMskAsciiOpt,
      mMskNumSymOpt, mMskNumericOpt] then
    Result := mcMaskOpt

  else if MaskChar in [mMskAlpha, mMskAlphaNum, mMskAscii, mMskNumeric] then
    Result := mcMask;
end;

function MaskGetCurrentDirectives(const EditMask: string;
  MaskOffset: Integer): TMaskDirectives;
var
  I: Integer;
  MaskChar: Char;
begin
  Result := [];
  for I := 1 to Length(EditMask) do
  begin
    MaskChar := EditMask[I];
    if (MaskChar = mDirReverse) then
      Include(Result, mdReverseDir)
    else if (MaskChar = mDirUpperCase) and (I < MaskOffset) then
    begin
      Exclude(Result, mdLowerCase);
      if not ((I > 1) and (EditMask[I-1] = mDirLowerCase)) then
        Include(Result, mdUpperCase);
    end
    else if (MaskChar = mDirLowerCase) and (I < MaskOffset) then
    begin
      Exclude(Result, mdUpperCase);
      Include(Result, mdLowerCase);
    end;
  end;
  if MaskGetCharType(EditMask, MaskOffset) = mcLiteral then
    Include(Result, mdLiteralChar);
end;

function MaskIntlLiteralToChar(IChar: Char): Char;
begin
  Result := IChar;
  case IChar of
    mMskTimeSeparator: Result := TimeSeparator;
    mMskDateSeparator: Result := DateSeparator;
  end;
end;

function MaskDoFormatText(const EditMask: string; const Value: string;
  Blank: Char): string;
var
  I: Integer;
  Offset, MaskOffset: Integer;
  CType: TMaskCharType;
  Dir: TMaskDirectives;
begin
  Result := Value;
  Dir := MaskGetCurrentDirectives(EditMask, 1);

  if not (mdReverseDir in Dir) then
  begin
      { starting at the beginning, insert literal chars in the string
        and add spaces on the end }
    Offset := 1;
    for MaskOffset := 1 to Length(EditMask) do
    begin
      CType := MaskGetCharType(EditMask, MaskOffset);

      if CType in [mcLiteral, mcIntlLiteral] then
      begin
        Result := Copy(Result, 1, Offset - 1) +
          MaskIntlLiteralToChar(EditMask[MaskOffset]) +
          Copy(Result, Offset, Length(Result) - Offset + 1);
        Inc(Offset);
      end
      else if CType in [mcMask, mcMaskOpt] then
      begin
        if Offset > Length(Result) then
          Result := Result + Blank;
        Inc(Offset);
      end;
    end;
  end
  else
  begin
      { starting at the end, insert literal chars in the string
        and add spaces at the beginning }
    Offset := Length(Result);
    for I := 0 to(Length(EditMask) - 1) do
    begin
      MaskOffset := Length(EditMask) - I;
      CType := MaskGetCharType(EditMask, MaskOffset);
      if CType in [mcLiteral, mcIntlLiteral] then
      begin
        Result := Copy(Result, 1, Offset) +
               MaskIntlLiteralToChar(EditMask[MaskOffset]) +
               Copy(Result, Offset + 1, Length(Result) - Offset);
      end
      else if CType in [mcMask, mcMaskOpt] then
      begin
        if Offset < 1 then
          Result := Blank + Result
        else
          Dec(Offset);
      end;
    end;
  end;
end;

function MaskGetMaskSave(const EditMask: string): Boolean;
var
  I: Integer;
  Sep1, Sep2: Integer;
begin
  Result := True;
  if Length(EditMask) >= 4 then
  begin
    Sep1 := -1;
    Sep2 := -1;
    I := Length(EditMask);
    while Sep2 < 0 do
    begin
      if (MaskGetCharType(EditMask, I) =  mcFieldSeparator) then
      begin
        if Sep1 < 0 then
          Sep1 := I
        else
          Sep2 := I;
      end;
      Dec(I);
      if (I <= 0) or(I < Length(EditMask) - 4) then
        Break;
    end;
    if Sep2 < 0 then
      Sep2 := Sep1;
    if Sep2 <> Length(EditMask) then
      Result := not (EditMask [Sep2 + 1] = MaskNoSave);
  end;
end;

function MaskGetMaskBlank(const EditMask: string): Char;
begin
  Result := DefaultBlank;
  if Length(EditMask) >= 4 then
  begin
    if (MaskGetCharType(EditMask, Length(EditMask) - 1) =
                                                  mcFieldSeparator) then
    begin
        {in order for blank specifier to be valid, there
         must also be a save specifier }
      if (MaskGetCharType(EditMask, Length(EditMask) - 2) =
                                                  mcFieldSeparator) or
        (MaskGetCharType(EditMask, Length(EditMask) - 3) =
                                                  mcFieldSeparator) then
      begin
        Result := EditMask [Length(EditMask)];
      end;
    end;
  end;
end;

function MaskGetFldSeparator(const EditMask: String): Integer;
var
  I: Integer;
begin
  Result := -1;
  if Length(EditMask) >= 4 then
  begin
    for I := (Length(EditMask) - 4) to Length(EditMask) do
    begin
      if (MaskGetCharType(EditMask, I) = mcFieldSeparator) then
      begin
        Result := I;
        Exit;
      end;
    end;
  end;
end;

function MaskOffsetToOffset(const EditMask: String; MaskOffset: Integer): Integer;
var
  I: Integer;
  CType: TMaskCharType;
begin
  Result := 0;
  for I := 1 to MaskOffset do
  begin
    CType := MaskGetCharType(EditMask, I);
    if not (CType in [mcDirective, mcField, mcFieldSeparator]) then
      Inc(Result);
  end;
end;

function OffsetToMaskOffset(const EditMask: string; Offset: Integer): Integer;
var
  I: Integer;
  Count: Integer;
  MaxChars: Integer;
begin
  MaxChars  := MaskOffsetToOffset(EditMask, Length(EditMask));
  if Offset > MaxChars then
  begin
    Result := -1;
    Exit;
  end;

  Result := 0;
  Count := Offset;
  for I := 1 to Length(EditMask) do
  begin
    Inc(Result);
    if not (mcDirective = MaskGetCharType(EditMask, I)) then
    begin
      Dec(Count);
      if Count < 0 then
        Exit;
    end;
  end;
end;

function IsLiteralChar(const EditMask: string; Offset: Integer): Boolean;
var
  MaskOffset: Integer;
  CType: TMaskCharType;
begin
  Result := False;
  MaskOffset := OffsetToMaskOffset(EditMask, Offset);
  if MaskOffset >= 0 then
  begin
    CType := MaskGetCharType(EditMask, MaskOffset);
    Result := CType in [mcLiteral, mcIntlLiteral];
  end;
end;

function PadSubField(const EditMask: String; const Value: string;
  StartFld, StopFld, Len: Integer; Blank: Char): string;
var
  Dir: TMaskDirectives;
  StartPad: Integer;
  K: Integer;
begin
  if (StopFld - StartFld) < Len then
  begin
     { found literal at position J, now pad it }
    Dir := MaskGetCurrentDirectives(EditMask, 1);
    StartPad := StopFld - 1;
    if mdReverseDir in Dir then
      StartPad := StartFld - 1;
    Result := Copy(Value, 1, StartPad);
    for K := 1 to (Len - (StopFld - StartFld)) do
      Result := Result + Blank;
    Result := Result + Copy(Value, StartPad + 1, Length(Value));
  end
  else if (StopFld - StartFld) > Len then
  begin
    Dir := MaskGetCurrentDirectives(EditMask, 1);
    if mdReverseDir in Dir then
      Result := Copy(Value, 1, StartFld - 1) +
        Copy(Value, StopFld - Len, Length(Value))
    else
      Result := Copy(Value, 1, StartFld + Len - 1) +
        Copy(Value, StopFld, Length(Value));
  end
  else
    Result := Value;
end;

function PadInputLiterals(const EditMask: String; const Value: string;
  Blank: Char): string;
var
  J: Integer;
  LastLiteral, EndSubFld: Integer;
  Offset, MaskOffset: Integer;
  CType: TMaskCharType;
  MaxChars: Integer;
begin
  LastLiteral := 0;

  Result := Value;
  for MaskOffset := 1 to Length(EditMask) do
  begin
    CType := MaskGetCharType(EditMask, MaskOffset);
    if CType in [mcLiteral, mcIntlLiteral] then
    begin
      Offset := MaskOffsetToOffset(EditMask, MaskOffset);
      EndSubFld := Length(Result) + 1;
      for J := LastLiteral + 1 to Length(Result) do
      begin
        if Result[J] = MaskIntlLiteralToChar(EditMask[MaskOffset]) then
        begin
          EndSubFld := J;
          Break;
        end;
      end;
       { we have found a subfield, ensure that it complies }
      if EndSubFld > Length(Result) then
        Result := Result + MaskIntlLiteralToChar(EditMask[MaskOffset]);
      Result := PadSubField(EditMask, Result, LastLiteral + 1, EndSubFld,
        Offset - (LastLiteral + 1), Blank);
      LastLiteral := Offset;
    end;
  end;

    {ensure that the remainder complies, too }
  MaxChars  := MaskOffsetToOffset(EditMask, Length(EditMask));
  if Length (Result) <> MaxChars then
    Result := PadSubField(EditMask, Result, LastLiteral + 1, Length (Result) + 1,
      MaxChars - LastLiteral, Blank);

    { replace non-literal blanks with blank char }
  for Offset := 1 to Length (Result) do
  begin
    if Result[Offset] = ' ' then
    begin
      if not IsLiteralChar(EditMask, Offset - 1) then
        Result[Offset] := Blank;
    end;
  end;
end;

function FormatMaskText(const EditMask: string; const Value: string ): string;
begin
  if MaskGetMaskSave(EditMask) then
    Result := PadInputLiterals(EditMask, Value, ' ')
  else
    Result := MaskDoFormatText(EditMask, Value, ' ');
end;


{ TCustomMaskEdit }

constructor TCustomMaskEdit.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FMaskState := [];
  FMaskBlank := DefaultBlank;
end;

procedure TCustomMaskEdit.KeyDown(var Key: Word; Shift: TShiftState);
begin
  if not FSettingCursor then inherited KeyDown(Key, Shift);
  if IsMasked and (Key <> 0) and not (ssAlt in Shift) then
  begin
    if (Key = VK_LEFT) or(Key = VK_RIGHT) then
    begin
      ArrowKeys(Key, Shift);
      if not ((ssShift in Shift) or (ssCtrl in Shift)) then
        Key := 0;
      Exit;
    end
    else if (Key = VK_UP) or(Key = VK_DOWN) then
    begin
      Key := 0;
      Exit;
    end
    else if (Key = VK_HOME) or(Key = VK_END) then
    begin
      HomeEndKeys(Key, Shift);
      Key := 0;
      Exit;
    end
    else if ((Key = VK_DELETE) and not (ssShift in Shift)) or
      (Key = VK_BACK) then
    begin
      if EditCanModify then
        DeleteKeys(Key);
      Key := 0;
      Exit;
    end;
    CheckCursor;
  end;
end;

procedure TCustomMaskEdit.KeyUp(var Key: Word; Shift: TShiftState);
begin
  if not FSettingCursor then inherited KeyUp(Key, Shift);
  if IsMasked and (Key <> 0) then
  begin
    if ((Key = VK_LEFT) or(Key = VK_RIGHT)) and (ssCtrl in Shift) then
      CheckCursor;
  end;
end;

procedure TCustomMaskEdit.KeyPress(var Key: Char);
begin
  inherited KeyPress(Key);
  if IsMasked and (Key <> #0) and not (Char(Key) in [^V, ^X, ^C]) then
  begin
    CharKeys(Key);
    Key := #0;
  end;
end;

procedure TCustomMaskEdit.WMLButtonDown(var Message: TWMLButtonDown);
begin
  inherited;
  FBtnDownX := Message.XPos;
end;

procedure TCustomMaskEdit.WMLButtonUp(var Message: TWMLButtonUp);
var
  SelStart, SelStop : Integer;
begin
  inherited;
  if (IsMasked) then
  begin
    GetSel(SelStart, SelStop);
    FCaretPos := SelStart;
    if (SelStart <> SelStop) and (Message.XPos > FBtnDownX) then
      FCaretPos := SelStop;
    CheckCursor;
  end;
end;

procedure TCustomMaskEdit.WMSetFocus(var Message: TWMSetFocus);
begin
  inherited;
  if (IsMasked) then
    CheckCursor;
end;

procedure TCustomMaskEdit.SetEditText(const Value: string);
begin
  if GetEditText <> Value then
  begin
    SetTextBuf(PChar(Value));
    CheckCursor;
  end;
end;

function TCustomMaskEdit.GetEditText: string;
begin
  Result := inherited Text;
end;

function TCustomMaskEdit.GetTextLen: Integer;
begin
  Result := Length(Text);
end;

function TCustomMaskEdit.GetText: string;
begin
  if not IsMasked then
    Result := inherited Text
  else
  begin
    Result := RemoveEditFormat(EditText);
    if FMaskSave then
      Result := AddEditFormat(Result, False);
  end;
end;

procedure TCustomMaskEdit.SetText(const Value: string);
var
  OldText: string;
  Pos: Integer;
begin
  if not IsMasked then
    inherited Text := Value
  else
  begin
    OldText := Value;
    if FMaskSave then
      OldText := PadInputLiterals(EditMask, OldText, FMaskBlank)
    else
      OldText := AddEditFormat(OldText, True);
    if not (msDBSetText in FMaskState) and
      (csDesigning in ComponentState) and
      not (csLoading in ComponentState) and
      not Validate(OldText, Pos) then
      raise EDBEditError.CreateRes(@SMaskErr);
    EditText := OldText;
  end;
end;

procedure TCustomMaskEdit.WMCut(var Message: TMessage);
begin
  if not (IsMasked) then
    inherited
  else
  begin
    CopyToClipboard;
    DeleteKeys(VK_DELETE);
  end;
end;

procedure TCustomMaskEdit.WMPaste(var Message: TMessage);
var
  Value: string;
  Str: string;
  SelStart, SelStop : Integer;
begin
  if not (IsMasked) or ReadOnly then
    inherited
  else
  begin
    Clipboard.Open;
    Value := Clipboard.AsText;
    Clipboard.Close;

    GetSel(SelStart, SelStop);
    Str := EditText;
    DeleteSelection(Str, SelStart, SelStop - SelStart);
    EditText := Str;
    SelStart := InputString(Str, Value, SelStart);
    EditText := Str;
    SetCursor(SelStart);
  end;
end;

function TCustomMaskEdit.GetMasked: Boolean;
begin
  Result := EditMask <> '';
end;

function TCustomMaskEdit.GetMaxChars: Integer;
begin
  if IsMasked then
    Result := FMaxChars
  else
    Result := inherited GetTextLen;
end;

procedure TCustomMaskEdit.ReformatText(const NewMask: string);
var
  OldText: string;
begin
  OldText := RemoveEditFormat(EditText);
  FEditMask := NewMask;
  FMaxChars  := MaskOffsetToOffset(EditMask, Length(NewMask));
  FMaskSave  := MaskGetMaskSave(NewMask);
  FMaskBlank := MaskGetMaskBlank(NewMask);
  OldText := AddEditFormat(OldText, True);
  EditText := OldText;
end;

procedure TCustomMaskEdit.SetEditMask(const Value: string);
var
  SelStart, SelStop: Integer;
begin
  if Value <> EditMask then
  begin
    if (csDesigning in ComponentState) and (Value <> '') and
      not (csLoading in ComponentState) then
      EditText := '';
    if HandleAllocated then GetSel(SelStart, SelStop);
    ReformatText(Value);
    Exclude(FMaskState, msMasked);
    if EditMask <> '' then Include(FMaskState, msMasked);
    inherited MaxLength := 0;
    if IsMasked and (FMaxChars > 0) then
      inherited MaxLength := FMaxChars;
    if HandleAllocated and (GetFocus = Handle) and
       not (csDesigning in ComponentState) then
      SetCursor(SelStart);
  end;
end;

function TCustomMaskEdit.GetMaxLength: Integer;
begin
  Result := inherited MaxLength;
end;

procedure TCustomMaskEdit.SetMaxLength(Value: Integer);
begin
  if not IsMasked then
    inherited MaxLength := Value
  else
    inherited MaxLength := FMaxChars;
end;

procedure TCustomMaskEdit.GetSel(var SelStart: Integer; var SelStop: Integer);
begin
  SendMessage(Handle, EM_GETSEL, Integer(@SelStart), Integer(@SelStop));
end;

procedure TCustomMaskEdit.SetSel(SelStart: Integer; SelStop: Integer);
begin
  SendMessage(Handle, EM_SETSEL, SelStart, SelStop);
end;

procedure TCustomMaskEdit.SetCursor(Pos: Integer);
const
  ArrowKey: array[Boolean] of Word = (VK_LEFT, VK_RIGHT);
var
  SelStart, SelStop: Integer;
  KeyState: TKeyboardState;
  NewKeyState: TKeyboardState;
  I: Integer;
begin
  if (Pos >= 1) and (ByteType(EditText, Pos) = mbLeadByte) then Dec(Pos);
  SelStart := Pos;
  if (IsMasked) then
  begin
    if SelStart < 0 then
      SelStart := 0;
    SelStop  := SelStart + 1;
    if (Length(EditText) > SelStop) and (EditText[SelStop] in LeadBytes) then
      Inc(SelStop);
    if SelStart >= FMaxChars then
    begin
      SelStart := FMaxChars;
      SelStop  := SelStart;
    end;

    SetSel(SelStop, SelStop);
    
    if SelStart <> SelStop then
    begin
      GetKeyboardState(KeyState);
      for I := Low(NewKeyState) to High(NewKeyState) do
        NewKeyState[I] := 0;
      NewKeyState [VK_SHIFT] := $81;
      NewKeyState [ArrowKey[UseRightToLeftAlignment]] := $81;
      SetKeyboardState(NewKeyState);
      FSettingCursor := True;
      try
        SendMessage(Handle, WM_KEYDOWN, ArrowKey[UseRightToLeftAlignment], 1);
        SendMessage(Handle, WM_KEYUP, ArrowKey[UseRightToLeftAlignment], 1);
      finally
        FSettingCursor := False;
      end;
      SetKeyboardState(KeyState);
    end;
    FCaretPos := SelStart;
  end
  else
  begin
    if SelStart < 0 then
      SelStart := 0;
    if SelStart >= Length(EditText) then
      SelStart := Length(EditText);
    SetSel(SelStart, SelStart);
  end;
end;

procedure TCustomMaskEdit.CheckCursor;
var
  SelStart, SelStop: Integer;
begin
  if not HandleAllocated then  Exit;
  if (IsMasked) then
  begin
    GetSel(SelStart, SelStop);
    if SelStart = SelStop then
      SetCursor(SelStart);
  end;
end;

procedure TCustomMaskEdit.Clear;
begin
  Text := '';
end;

function TCustomMaskEdit.EditCanModify: Boolean;
begin
  Result := True;
end;

procedure TCustomMaskEdit.Reset;
begin
  if Modified then
  begin
    EditText := FOldValue;
    Modified := False;
  end;
end;

function TCustomMaskEdit.CharKeys(var CharCode: Char): Boolean;
var
  SelStart, SelStop : Integer;
  Txt: string;
  CharMsg: TMsg;
begin
  Result := False;
  if Word(CharCode) = VK_ESCAPE then
  begin
    Reset;
    Exit;
  end;
  if not EditCanModify or ReadOnly then Exit;
  if (Word(CharCode) = VK_BACK) then Exit;
  if (Word(CharCode) = VK_RETURN) then
  begin
    ValidateEdit;
    Exit;
  end;

  GetSel(SelStart, SelStop);
  if (SelStop - SelStart) > 1 then
  begin
    DeleteKeys(VK_DELETE);
    SelStart := GetNextEditChar(SelStart);
    SetCursor(SelStart);
  end;

  if (CharCode in LeadBytes) then
    if PeekMessage(CharMsg, Handle, WM_CHAR, WM_CHAR, PM_REMOVE) then
      if CharMsg.Message = WM_Quit then
        PostQuitMessage(CharMsg.wparam);
  Result := InputChar(CharCode, SelStart);
  if Result then
  begin
    if (CharCode in LeadBytes) then
    begin
      Txt := CharCode + Char(CharMsg.wParam);
      SetSel(SelStart, SelStart + 2);
    end
    else
      Txt := CharCode;
    SendMessage(Handle, EM_REPLACESEL, 0, LongInt(PChar(Txt)));
    GetSel(SelStart, SelStop);
    CursorInc(SelStart, 0);
  end;
end;

procedure TCustomMaskEdit.ArrowKeys(CharCode: Word; Shift: TShiftState);
var
  SelStart, SelStop : Integer;
begin
  if (ssCtrl in Shift) then Exit;
  GetSel(SelStart, SelStop);
  if (ssShift in Shift) then
  begin
    if (CharCode = VK_RIGHT) then
    begin
      Inc(FCaretPos);
      if (SelStop = SelStart + 1) then
      begin
        SetSel(SelStart, SelStop);  {reset caret to end of string}
        Inc(FCaretPos);
      end;
      if FCaretPos > FMaxChars then FCaretPos := FMaxChars;
    end
    else  {if (CharCode = VK_LEFT) then}
    begin
      Dec(FCaretPos);
      if (SelStop = SelStart + 2) and
        (FCaretPos > SelStart) then
      begin
        SetSel(SelStart + 1, SelStart + 1);  {reset caret to show up at start}
        Dec(FCaretPos);
      end;
      if FCaretPos < 0 then FCaretPos := 0;
    end;
  end
  else
  begin
    if (SelStop - SelStart) > 1 then
    begin
      if ((SelStop - SelStart) = 2) and (EditText[SelStart+1] in LeadBytes) then
      begin
        if (CharCode = VK_LEFT) then
          CursorDec(SelStart)
        else
          CursorInc(SelStart, 2);
        Exit;
      end;
      if SelStop = FCaretPos then
        Dec(FCaretPos);
      SetCursor(FCaretPos);
    end
    else if (CharCode = VK_LEFT) then
      CursorDec(SelStart)
    else   { if (CharCode = VK_RIGHT) then  }
    begin
      if SelStop = SelStart then
        SetCursor(SelStart)
      else
        if EditText[SelStart+1] in LeadBytes then
          CursorInc(SelStart, 2)
        else
          CursorInc(SelStart, 1);
    end;
  end;
end;

procedure TCustomMaskEdit.CursorInc(CursorPos: Integer; Incr: Integer);
var
  NuPos: Integer;
begin
  NuPos := CursorPos + Incr;
  NuPos := GetNextEditChar(NuPos);
  if IsLiteralChar(EditMask, nuPos) then
    NuPos := CursorPos;
  SetCursor(NuPos);
end;


procedure TCustomMaskEdit.CursorDec(CursorPos: Integer);
var
  nuPos: Integer;
begin
  nuPos := CursorPos;
  Dec(nuPos);
  nuPos := GetPriorEditChar(nuPos);
  SetCursor(NuPos);
end;

function TCustomMaskEdit.GetFirstEditChar: Integer;
begin
  Result := 0;
  if IsMasked then
    Result := GetNextEditChar(0);
end;

function TCustomMaskEdit.GetLastEditChar: Integer;
begin
  Result := GetMaxChars;
  if IsMasked then
    Result := GetPriorEditChar(Result - 1);
end;

function TCustomMaskEdit.GetNextEditChar(Offset: Integer): Integer;
begin
  Result := Offset;
  while(Result < FMaxChars) and (IsLiteralChar(EditMask, Result)) do
    Inc(Result);
end;

function TCustomMaskEdit.GetPriorEditChar(Offset: Integer): Integer;
begin
  Result := Offset;
  while(Result >= 0) and (IsLiteralChar(EditMask, Result)) do
    Dec(Result);
  if Result < 0 then
    Result := GetNextEditChar(Result);
end;

procedure TCustomMaskEdit.HomeEndKeys(CharCode: Word; Shift: TShiftState);
var
  SelStart, SelStop : Integer;
begin
  GetSel(SelStart, SelStop);
  if (CharCode = VK_HOME) then
  begin
    if (ssShift in Shift) then
    begin
      if (SelStart <> FCaretPos) and (SelStop <> (SelStart + 1)) then
        SelStop := SelStart + 1;
      SetSel(0, SelStop);
      CheckCursor;
    end
    else
      SetCursor(0);
    FCaretPos := 0;
  end
  else
  begin
    if (ssShift in Shift) then
    begin
      if (SelStop <> FCaretPos) and (SelStop <> (SelStart + 1)) then
        SelStart := SelStop - 1;
      SetSel(SelStart, FMaxChars);
      CheckCursor;
    end
    else
      SetCursor(FMaxChars);
    FCaretPos := FMaxChars;
  end;
end;

procedure TCustomMaskEdit.DeleteKeys(CharCode: Word);
var
  SelStart, SelStop : Integer;
  NuSelStart: Integer;
  Str: string;
begin
  if ReadOnly then Exit;
  GetSel(SelStart, SelStop);
  if ((SelStop - SelStart) <= 1) and (CharCode = VK_BACK) then
  begin
    NuSelStart := SelStart;
    CursorDec(SelStart);
    GetSel(SelStart, SelStop);
    if SelStart = NuSelStart then Exit;
  end;

  if (SelStop - SelStart) < 1 then Exit;

  Str := EditText;
  DeleteSelection(Str, SelStart, SelStop - SelStart);
  Str := Copy(Str, SelStart+1, SelStop - SelStart);
  SendMessage(Handle, EM_REPLACESEL, 0, LongInt(PChar(Str)));
  if (SelStop - SelStart) <> 1 then
  begin
    SelStart := GetNextEditChar(SelStart);
    SetCursor(SelStart);
  end
  else begin
    GetSel(SelStart, SelStop);
    SetCursor(SelStart - 1);
  end;
end;

procedure TCustomMaskEdit.CMEnter(var Message: TCMEnter);
begin
  if IsMasked and not (csDesigning in ComponentState) then
  begin
    if not (msReEnter in FMaskState) then
    begin
      FOldValue := EditText;
      inherited;
    end;
    Exclude(FMaskState, msReEnter);
    CheckCursor;
  end
  else
    inherited;
end;

procedure TCustomMaskEdit.CMTextChanged(var Message: TMessage);
var
  SelStart, SelStop : Integer;
  Temp: Integer;
begin
  inherited;
  FOldValue := EditText;
  if HandleAllocated then
  begin
    GetSel(SelStart, SelStop);
    Temp := GetNextEditChar(SelStart);
    if Temp <> SelStart then
      SetCursor(Temp);
  end;
end;

procedure TCustomMaskEdit.CMWantSpecialKey(var Message: TCMWantSpecialKey);
begin
  inherited;
  if (Message.CharCode = VK_ESCAPE) and IsMasked and Modified then
    Message.Result := 1;
end;

procedure TCustomMaskEdit.CMExit(var Message: TCMExit);
begin
  if IsMasked and not (csDesigning in ComponentState) then
  begin
    ValidateEdit;
    CheckCursor;
  end;
  inherited;
end;

procedure TCustomMaskEdit.ValidateEdit;
var
  Str: string;
  Pos: Integer;
begin
  Str := EditText;
  if IsMasked and Modified then
  begin
    if not Validate(Str, Pos) then
    begin
      if not (csDesigning in ComponentState) then
      begin
        Include(FMaskState, msReEnter);
        SetFocus;
      end;
      SetCursor(Pos);
      ValidateError;
    end;
  end;
end;

procedure TCustomMaskEdit.ValidateError;
begin
  MessageBeep(0);
  raise EDBEditError.CreateResFmt(@SMaskEditErr, [EditMask]);
end;

function TCustomMaskEdit.AddEditFormat(const Value: string; Active: Boolean): string;
begin
  if not Active then
    Result := MaskDoFormatText(EditMask, Value, ' ')
  else
    Result := MaskDoFormatText(EditMask, Value, FMaskBlank);
end;

function TCustomMaskEdit.RemoveEditFormat(const Value: string): string;
var
  I: Integer;
  OldLen: Integer;
  Offset, MaskOffset: Integer;
  CType: TMaskCharType;
  Dir: TMaskDirectives;
begin
  Offset := 1;
  Result := Value;
  for MaskOffset := 1 to Length(EditMask) do
  begin
    CType := MaskGetCharType(EditMask, MaskOffset);

    if CType in [mcLiteral, mcIntlLiteral] then
      Result := Copy(Result, 1, Offset - 1) +
        Copy(Result, Offset + 1, Length(Result) - Offset);
    if CType in [mcMask, mcMaskOpt] then Inc(Offset);
  end;

  Dir := MaskGetCurrentDirectives(EditMask, 1);
  if mdReverseDir in Dir then
  begin
    Offset := 1;
    for I := 1 to Length(Result) do
    begin
      if Result[I] = FMaskBlank then
        Inc(Offset)
      else
        break;
    end;
    if Offset <> 1 then
      Result := Copy(Result, Offset, Length(Result) - Offset + 1);
  end
  else begin
    OldLen := Length(Result);
    for I := 1 to OldLen do
    begin
      if Result[OldLen - I + 1] = FMaskBlank then
        SetLength(Result, Length(Result) - 1)
      else Break;
    end;
  end;
  if FMaskBlank <> ' ' then
  begin
    OldLen := Length(Result);
    for I := 1 to OldLen do
    begin
      if Result[I] = FMaskBlank then
        Result[I] := ' ';
      if I > OldLen then Break;
    end;
  end;
end;

function TCustomMaskEdit.InputChar(var NewChar: Char; Offset: Integer): Boolean;
var
  MaskOffset: Integer;
  CType: TMaskCharType;
  InChar: Char;
begin
  Result := True;
  if EditMask <> '' then
  begin
    Result := False;
    MaskOffset := OffsetToMaskOffset(EditMask, Offset);
    if MaskOffset >= 0 then
    begin
      CType := MaskGetCharType(EditMask, MaskOffset);
      InChar := NewChar;
      Result := DoInputChar(NewChar, MaskOffset);
      if not Result and (CType in [mcMask, mcMaskOpt]) then
      begin
        MaskOffset := FindLiteralChar (MaskOffset, InChar);
        if MaskOffset > 0 then
        begin
          MaskOffset := MaskOffsetToOffset(EditMask, MaskOffset);
          SetCursor (MaskOffset);
          Exit;
        end;
      end;
    end;
  end;
  if not Result then
    MessageBeep(0)
end;

function TCustomMaskEdit.DoInputChar(var NewChar: Char; MaskOffset: Integer): Boolean;
var
  Dir: TMaskDirectives;
  Str: string;
  CType: TMaskCharType;

  function IsKatakana(const Chr: Byte): Boolean;
  begin
    Result := (SysLocale.PriLangID = LANG_JAPANESE) and (Chr in [$A1..$DF]);
  end;

  function TestChar(NewChar: Char): Boolean;
  var
    Offset: Integer;
  begin
    Offset := MaskOffsetToOffset(EditMask, MaskOffset);
    Result := not ((MaskOffset < Length(EditMask)) and
               (UpCase(EditMask[MaskOffset]) = UpCase(EditMask[MaskOffset+1]))) or
               (ByteType(EditText, Offset) = mbTrailByte) or
               (ByteType(EditText, Offset+1) = mbLeadByte);
  end;

begin
  Result := True;
  CType := MaskGetCharType(EditMask, MaskOffset);
  if CType in [mcLiteral, mcIntlLiteral] then
    NewChar := MaskIntlLiteralToChar(EditMask[MaskOffset])
  else
  begin
    Dir := MaskGetCurrentDirectives(EditMask, MaskOffset);
    case EditMask[MaskOffset] of
      mMskNumeric, mMskNumericOpt:
        begin
          if not ((NewChar >= '0') and (NewChar <= '9')) then
            Result := False;
        end;
      mMskNumSymOpt:
        begin
          if not (((NewChar >= '0') and (NewChar <= '9')) or
                 (NewChar = ' ') or(NewChar = '+') or(NewChar = '-')) then
            Result := False;
        end;
      mMskAscii, mMskAsciiOpt:
        begin
          if (NewChar in LeadBytes) and TestChar(NewChar) then
          begin
            Result := False;
            Exit;
          end;
          if IsCharAlpha(NewChar) then
          begin
            Str := ' ';
            Str[1] := NewChar;
            if (mdUpperCase in Dir)  then
              Str := AnsiUpperCase(Str)
            else if mdLowerCase in Dir then
              Str := AnsiLowerCase(Str);
            NewChar := Str[1];
          end;
        end;
      mMskAlpha, mMskAlphaOpt, mMskAlphaNum, mMskAlphaNumOpt:
        begin
          if (NewChar in LeadBytes) then
          begin
            if TestChar(NewChar) then
              Result := False;
            Exit;
          end;
          Str := ' ';
          Str[1] := NewChar;
          if IsKatakana(Byte(NewChar)) then
          begin
              NewChar := Str[1];
              Exit;
          end;
          if not IsCharAlpha(NewChar) then
          begin
            Result := False;
            if ((EditMask[MaskOffset] = mMskAlphaNum) or
                (EditMask[MaskOffset] = mMskAlphaNumOpt)) and
                (IsCharAlphaNumeric(NewChar)) then
              Result := True;
          end
          else if mdUpperCase in Dir then
            Str := AnsiUpperCase(Str)
          else if mdLowerCase in Dir then
            Str := AnsiLowerCase(Str);
          NewChar := Str[1];
        end;
    end;
  end;
end;

function TCustomMaskEdit.Validate(const Value: string; var Pos: Integer): Boolean;
var
  Offset, MaskOffset: Integer;
  CType: TMaskCharType;
begin
  Result := True;
  Offset := 1;
  for MaskOffset := 1 to Length(EditMask) do
  begin
    CType := MaskGetCharType(EditMask, MaskOffset);

    if CType in [mcLiteral, mcIntlLiteral, mcMaskOpt] then
      Inc(Offset)
    else if (CType = mcMask) and (Value <> '') then
    begin
      if (Value [Offset] = FMaskBlank) or
        ((Value [Offset] = ' ') and (EditMask[MaskOffset] <> mMskAscii)) then
      begin
        Result := False;
        Pos := Offset - 1;
        Exit;
      end;
      Inc(Offset);
    end;
  end;
end;

function TCustomMaskEdit.DeleteSelection(var Value: string; Offset: Integer;
  Len: Integer): Boolean;
var
  EndDel: Integer;
  StrOffset, MaskOffset, Temp: Integer;
  CType: TMaskCharType;
begin
  Result := True;
  if Len = 0 then Exit;

  StrOffset := Offset + 1;
  EndDel := StrOffset + Len;
  Temp := OffsetToMaskOffset(EditMask, Offset);
  if Temp < 0 then  Exit;
  for MaskOffset := Temp to Length(EditMask) do
  begin
    CType := MaskGetCharType(EditMask, MaskOffset);
    if CType in [mcLiteral, mcIntlLiteral] then
      Inc(StrOffset)
    else if CType in [mcMask, mcMaskOpt] then
    begin
      Value[StrOffset] := FMaskBlank;
      Inc(StrOffset);
    end;
    if StrOffset >= EndDel then Break;
  end;
end;

function TCustomMaskEdit.InputString(var Value: string; const NewValue: string;
  Offset: Integer): Integer;
var
  NewOffset, MaskOffset, Temp: Integer;
  CType: TMaskCharType;
  NewVal: string;
  NewChar: Char;
begin
  Result := Offset;
  if NewValue = '' then Exit;
  { replace chars with new chars, except literals }
  NewOffset := 1;
  NewVal := NewValue;
  Temp := OffsetToMaskOffset(EditMask, Offset);
  if Temp < 0 then  Exit;
  MaskOffset := Temp;
  While MaskOffset <= Length(EditMask) do
  begin
    CType := MaskGetCharType(EditMask, MaskOffset);
    if CType in [mcLiteral, mcIntlLiteral, mcMask, mcMaskOpt] then
    begin
      NewChar := NewVal[NewOffset];
      if not (DoInputChar(NewChar, MaskOffset)) then
      begin
        if (NewChar in LeadBytes) then
          NewVal[NewOffset + 1] := FMaskBlank;
        NewChar := FMaskBlank;
      end;
        { if pasted text does not contain a literal in the right place,
          insert one }
      if not ((CType in [mcLiteral, mcIntlLiteral]) and
        (NewChar <> NewVal[NewOffset])) then
      begin
        NewVal[NewOffset] := NewChar;
        if (NewChar in LeadBytes) then
        begin
          Inc(NewOffset);
          Inc(MaskOffset);
        end;
      end
      else
        NewVal := Copy(NewVal, 1, NewOffset-1) + NewChar +
          Copy(NewVal, NewOffset, Length (NewVal));
      Inc(NewOffset);
    end;
    if (NewOffset + Offset) > FMaxChars then Break;
    if (NewOffset) > Length(NewVal) then Break;
    Inc(MaskOffset);
  end;

  if (Offset + Length(NewVal)) < FMaxChars then
  begin
    if ByteType(Value, OffSet + Length(NewVal) + 1) = mbTrailByte then
    begin
      NewVal := NewVal + FMaskBlank;
      Inc(NewOffset);
    end;
    Value := Copy(Value, 1, Offset) + NewVal +
      Copy(Value, OffSet + Length(NewVal) + 1,
        FMaxChars -(Offset + Length(NewVal)));
  end
  else
  begin
    Temp := Offset;
    if (ByteType(NewVal, FMaxChars - Offset) = mbLeadByte) then
      Inc(Temp);
    Value := Copy(Value, 1, Offset) +
             Copy(NewVal, 1, FMaxChars - Temp);
  end;
  Result := NewOffset + Offset - 1;
end;

function TCustomMaskEdit.FindLiteralChar(MaskOffset: Integer; InChar: Char): Integer;
var
  CType: TMaskCharType;
  LitChar: Char;
begin
  Result := -1;
  while MaskOffset < Length(EditMask) do
  begin
    Inc(MaskOffset);
    CType := MaskGetCharType(EditMask, MaskOffset);
    if CType in [mcLiteral, mcIntlLiteral] then
    begin
      LitChar := EditMask[MaskOffset];
      if CType = mcIntlLiteral then
        LitChar := MaskIntlLiteralToChar(LitChar);
      if LitChar = InChar then
        Result := MaskOffset;
      Exit;
    end;
  end;
end;

end.
