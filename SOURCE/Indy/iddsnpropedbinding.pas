unit IdDsnPropEdBinding;

interface

uses
{$IFDEF VER140}DesignIntf, DesignEditors, {$ELSE}Dsgnintf, {$ENDIF}
{$IFDEF Linux}
  QControls, QForms, QStdCtrls, QButtons, QExtCtrls, QActnList,
{$ELSE}
  Controls, Forms, StdCtrls, Buttons, ExtCtrls, ActnList,
{$ENDIF}
  Classes;

type
  TIdPropEdBindingEntry = class(TForm)
    btnOk: TButton;
    btnCancel: TButton;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    lstBindings: TListBox;
    btnAdd: TButton;
    btnRemove: TButton;
    cmbPort: TComboBox;
    cmbHostname: TComboBox;
    actBndEditor: TActionList;
    actAdd: TAction;
    actRemove: TAction;
    procedure lstBindingsClick(Sender: TObject);
    procedure actAddExecute(Sender: TObject);
    procedure actAddUpdate(Sender: TObject);
    procedure actRemoveExecute(Sender: TObject);
    procedure actRemoveUpdate(Sender: TObject);
    procedure cmbPortKeyPress(Sender: TObject; var Key: Char);
    procedure cmbHostnameKeyPress(Sender: TObject; var Key: Char);
  private
    procedure ValidateAddBinding;
    procedure SetHostname(const Value: string);
    procedure SetPort(const Value: integer);
    function PortDescription(const PortNumber: integer): string;
    function GetHostname: string;
    function GetPort: integer;
    procedure SetBinding(const Binding: string);
    function GetBinding: string;
  public
    constructor Create(AOwner: TComponent); override;
    procedure SetList(const Arg: string);
    function GetList: string;
    property Binding: string read GetBinding write SetBinding;
    property Hostname: string read GetHostname write SetHostname;
    property Port: integer read GetPort write SetPort;
  end;

  TIdPropEdBinding = class(TClassProperty)
  public
    procedure Edit; override;
    function GetAttributes: TPropertyAttributes; override;
    function GetValue: string; override;
    procedure SetValue(const Value: string); override;
  end;

implementation
{$IFDEF Linux}
{$R *.xfm}
{$ELSE}
{$R *.dfm}
{$ENDIF}

uses
  IdGlobal,
  IdResourceStrings,
  IdSocketHandle,
  IdStack,
  SysUtils;

function MakeBindingStr(AIP: string; APort: Cardinal): string;
begin
  Result := Format('%s:%d', [AIP, APort]);
end;

procedure TIdPropEdBinding.Edit;
begin
  inherited;
  with TIdPropEdBindingEntry.Create(nil) do
  try
    SetList(Value);
    if ShowModal = mrOk then
      Value := GetList;
  finally
    Free;
  end;
end;

function TIdPropEdBinding.GetAttributes: TPropertyAttributes;
begin
  result := [paDialog];
end;

function TIdPropEdBinding.GetValue: string;
var
  IdSockets: TIdSocketHandles;
  i: integer;
  sep: string;
begin
  IdSockets := TIdSocketHandles(GetOrdValue);
  result := '';
  sep := '';
  for i := 0 to IdSockets.Count - 1 do
  begin
    result := result + sep + MakeBindingStr(IdSockets[i].IP, IdSockets[i].Port);
    sep := ',';
  end;
end;

procedure TIdPropEdBinding.SetValue(const Value: string);
var
  IdSockets: TIdSocketHandles;
  s: string;
  sl: TStringList;
  i, j: integer;
begin
  inherited;
  IdSockets := TIdSocketHandles(GetOrdValue);
  IdSockets.BeginUpdate;
  IdSockets.Clear;
  sl := TStringList.Create;
  try
    sl.CommaText := Value;
    for i := 0 to sl.Count - 1 do
      with TIdSocketHandle.Create(IdSockets) do
      begin
        s := sl[i];
        j := AnsiPos(':', s);
        IP := Copy(s, 1, j - 1);
        Port := GStack.WSGetServByName(Copy(s, j + 1, Length(s)));
      end;
  finally
    sl.Free;
    IdSockets.EndUpdate;
  end;
end;

constructor TIdPropEdBindingEntry.Create(AOwner: TComponent);
var
  i: integer;
  s: string;
begin
  inherited;
  try
    cmbPort.Items.BeginUpdate;
    for i := 0 to IdPorts.Count - 1 do
      cmbPort.Items.Add(PortDescription(Integer(IdPorts[i])));
  finally
    cmbPort.Items.EndUpdate;
  end;
  SetLength(s, 250);
  cmbHostname.Items := GStack.LocalAddresses;
  cmbHostname.Items.Insert(0, '127.0.0.1');
  lstBindingsClick(self);
end;

function TIdPropEdBindingEntry.GetBinding: string;
begin
  result := MakeBindingStr(Hostname, Port);
end;

function TIdPropEdBindingEntry.GetHostname: string;
begin
  result := cmbHostname.Text;
end;

function TIdPropEdBindingEntry.GetList: string;
begin
  Result := lstBindings.Items.CommaText;
end;

function TIdPropEdBindingEntry.GetPort: integer;
var
  i: integer;
  s: string;
begin
  s := cmbPort.Text;
  i := AnsiPos(':', s);
  if i > 0 then
  begin
    Result := StrToInt(Copy(s, 1, i - 1));
  end
  else
  begin
    Result := GStack.WSGetServByName(s);
  end;
end;

procedure TIdPropEdBindingEntry.lstBindingsClick(Sender: TObject);
begin
  btnRemove.Enabled := lstBindings.ItemIndex > -1;
end;

function TIdPropEdBindingEntry.PortDescription(
  const PortNumber: integer): string;
begin
  with GStack.WSGetServByPort(PortNumber) do
  try
    Result := '';
    if Count > 0 then
    begin
      Result := Format('%d: %s', [PortNumber, CommaText]);
    end;
  finally
    Free;
  end;
end;

procedure TIdPropEdBindingEntry.SetBinding(const Binding: string);
var
  i: integer;
begin
  i := AnsiPos(':', Binding);
  Hostname := Copy(Binding, 1, i - 1);
  Port := StrToInt(Copy(Binding, i + 1, Length(Binding)));
end;

procedure TIdPropEdBindingEntry.SetHostname(const Value: string);
begin
  cmbHostname.Text := Value;
end;

procedure TIdPropEdBindingEntry.SetList(const Arg: string);
begin
  lstBindings.Items.CommaText := Arg;
end;

procedure TIdPropEdBindingEntry.SetPort(const Value: integer);
var
  s: string;
begin
  s := PortDescription(Value);
  if s <> '' then
  begin
    cmbPort.Text := s
  end
  else
  begin
    cmbPort.Text := IntToStr(Value);
  end;
end;

procedure TIdPropEdBindingEntry.ValidateAddBinding;
begin
  btnAdd.Enabled := (Length(cmbPort.Text) > 0) and
    (lstBindings.Items.IndexOf(Binding) = -1);
end;

procedure TIdPropEdBindingEntry.actAddExecute(Sender: TObject);
begin
  lstBindings.Items.Add(Binding);
end;

procedure TIdPropEdBindingEntry.actAddUpdate(Sender: TObject);
begin
  ValidateAddBinding;
end;

procedure TIdPropEdBindingEntry.actRemoveExecute(Sender: TObject);
begin
  with lstBindings do
  begin
    Binding := Items[ItemIndex];
    Items.Delete(ItemIndex);
  end;
end;

procedure TIdPropEdBindingEntry.actRemoveUpdate(Sender: TObject);
begin
  actRemove.Enabled := lstBindings.ItemIndex <> -1;
end;

procedure TIdPropEdBindingEntry.cmbPortKeyPress(Sender: TObject;
  var Key: Char);
begin
  if (Key > #31) and (Key < #128) then
    if not (Key in ['0'..'9']) then
      Key := #0;
end;

procedure TIdPropEdBindingEntry.cmbHostnameKeyPress(Sender: TObject;
  var Key: Char);

begin
  if (Key > #31) and (Key < #128) and (Key <> '.') then
    if not (Key in ['0'..'9']) then
      Key := #0;
end;

end.
