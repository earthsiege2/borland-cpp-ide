{************************************************************************}
{                                                                        }
{       Borland Delphi Visual Component Library                          }
{       InterBase Express core components                                }
{                                                                        }
{       Copyright (c) 1998-2001 Borland Software Corporation             }
{                                                                        }
{    InterBase Express is based in part on the product                   }
{    Free IB Components, written by Gregory H. Deatz for                 }
{    Hoagland, Longo, Moran, Dunst & Doukas Company.                     }
{    Free IB Components is used under license.                           }
{                                                                        }
{    The contents of this file are subject to the InterBase              }
{    Public License Version 1.0 (the "License"); you may not             }
{    use this file except in compliance with the License. You may obtain }
{    a copy of the License at http://www.borland.com/interbase/IPL.html  }
{    Software distributed under the License is distributed on            }
{    an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, either              }
{    express or implied. See the License for the specific language       }
{    governing rights and limitations under the License.                 }
{    The Original Code was created by InterBase Software Corporation     }
{       and its successors.                                              }
{    Portions created by Borland Software Corporation are Copyright      }
{       (C) Borland Software Corporation. All Rights Reserved.           }
{    Contributor(s): Jeff Overcash                                       }
{                                                                        }
{************************************************************************}

unit IBServiceEditor;

interface

uses
{$IFDEF MSWINDOWS}
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ExtCtrls, IBServices, IBXConst;
{$ENDIF}
{$IFDEF LINUX}
  SysUtils, Variants, QForms, QControls, Classes,
  QDialogs, QStdCtrls, QExtCtrls, IBServices, IBXConst;
{$ENDIF}

type
  TfrmIBServiceEditor = class(TForm)
    GroupBox2: TGroupBox;
    Label1: TLabel;
    Label7: TLabel;
    Label8: TLabel;
    DatabaseName: TEdit;
    LocalRbtn: TRadioButton;
    RemoteRbtn: TRadioButton;
    Browse: TButton;
    ServerName: TEdit;
    Protocol: TComboBox;
    Panel1: TPanel;
    OKBtn: TButton;
    CancelBtn: TButton;
    HelpBtn: TButton;
    GroupBox1: TGroupBox;
    Label2: TLabel;
    Label3: TLabel;
    Label5: TLabel;
    UserName: TEdit;
    Password: TEdit;
    ServiceParams: TMemo;
    LoginPrompt: TCheckBox;
    chkActive: TCheckBox;
    procedure LocalRbtnClick(Sender: TObject);
    procedure RemoteRbtnClick(Sender: TObject);
    procedure BrowseClick(Sender: TObject);
    procedure UserNameChange(Sender: TObject);
    procedure PasswordChange(Sender: TObject);
  private
    FService: TIBCustomService;
    { Private declarations }
    function GetParam(Name: string): string;
    procedure AddParam(Name, Value: string);
    procedure DeleteParam(Name: string);
  public
    { Public declarations }
    property Service : TIBCustomService read FService write FService;
    function Edit: Boolean;
  end;

function EditIBService(AService: TIBCustomService): Boolean;

implementation

uses TypInfo;

{$IFDEF MSWINDOWS}
{$R *.dfm}
{$ENDIF}
{$IFDEF LINUX}
{$R *.xfm}
{$ENDIF}

function EditIBService(AService: TIBCustomService): Boolean;
begin
  with TfrmIBServiceEditor.Create(Application) do
  try
    Service := AService;
    Result := Edit;
  finally
    Free;
  end;
end;

{ TfrmServiceEditor }

procedure TfrmIBServiceEditor.AddParam(Name, Value: string);
var
  i: Integer;
  found: boolean;
begin
  found := False;
  if Trim(Value) <> '' then  {do not localize}
  begin
    for i := 0 to ServiceParams.Lines.Count - 1 do
    begin
      if (Pos(Name, LowerCase(ServiceParams.Lines.Names[i])) = 1) then {mbcs ok}
      begin
        ServiceParams.Lines.Values[ServiceParams.Lines.Names[i]] := Value;
        found := True;
        break;
      end;
    end;
    if not found then
      ServiceParams.Lines.Add(Name + '=' + Value);   {do not localize}
  end
  else
    DeleteParam(Name);
end;

procedure TfrmIBServiceEditor.DeleteParam(Name: string);
var
  i: Integer;
begin
    for i := 0 to ServiceParams.Lines.Count - 1 do
    begin
      if (Pos(Name, LowerCase(ServiceParams.Lines.Names[i])) = 1) then {mbcs ok}
      begin
        ServiceParams.Lines.Delete(i);
        break;
      end;
    end;
end;

function TfrmIBServiceEditor.Edit: Boolean;
var
  p : TProtocol;
begin
  ServiceParams.Lines := FService.Params;
  LoginPrompt.Checked := FService.LoginPrompt;
  UserName.Text := GetParam('user_name');      {do not localize}
  Password.Text := GetParam('password');    {do not localize}
  DatabaseName.Text := GetPropValue(FService, 'DatabaseName');    {do not localize}
  p := TProtocol(GetEnumValue(TypeInfo(TProtocol), GetPropValue(FService, 'Protocol'))); {do not localize}
  if p = Local then
    LocalRbtn.Checked := true
  else
  begin
    RemoteRbtn.Checked := true;
    case p of
      TCP : Protocol.ItemIndex := 0;
      NamedPipe : Protocol.ItemIndex := 1;
      SPX : Protocol.ItemIndex := 2;
    end;
    ServerName.Text := GetPropValue(FService, 'ServerName');    {do not localize}
  end;
  chkActive.Checked := FService.Active;
  Result := False;
  if ShowModal = mrOk then
  begin
    FService.Active := false;
    SetPropValue(FService, 'DatabaseName', DatabaseName.Text);   {do not localize}
    FService.Params := ServiceParams.Lines;
    FService.LoginPrompt := LoginPrompt.Checked;
    if LocalRbtn.Checked then
    begin
      SetPropValue(FService, 'Protocol', Local);   {do not localize}
      SetPropValue(FService, 'ServerName', 'localhost');  {do not localize}
    end
    else
    begin
      SetPropValue(FService, 'Protocol', GetEnumValue(TypeInfo(TProtocol), Protocol.Text)); {do not localize}
      SetPropValue(FService, 'ServerName', ServerName.Text);  {do not localize}
    end;
    FService.Active := chkActive.Checked;
    Result := True;
  end;
end;

function TfrmIBServiceEditor.GetParam(Name: string): string;
var
  i: Integer;
begin
  Result := '';   {do not localize}
  for i := 0 to ServiceParams.Lines.Count - 1 do
  begin
    if (Pos(Name, LowerCase(ServiceParams.Lines.Names[i])) = 1) then {mbcs ok}
    begin
      Result := ServiceParams.Lines.Values[ServiceParams.Lines.Names[i]];
      break;
    end;
  end;
end;

procedure TfrmIBServiceEditor.LocalRbtnClick(Sender: TObject);
begin
  Browse.Enabled := True;
  Label7.Enabled := False;
  Label8.Enabled := False;
  ServerName.Enabled := False;
  Protocol.Enabled := False;
end;

procedure TfrmIBServiceEditor.RemoteRbtnClick(Sender: TObject);
begin
  Browse.Enabled := False;
  Label7.Enabled := True;
  Label8.Enabled := True;
  Protocol.Enabled := True;
  ServerName.Enabled := True;
end;

procedure TfrmIBServiceEditor.BrowseClick(Sender: TObject);
begin
  with TOpenDialog.Create(Application) do
    try
      InitialDir := ExtractFilePath(DatabaseName.Text);
      Filter := SDatabaseFilter;
      if Execute then
        DatabaseName.Text := FileName;
    finally
      Free
    end;
end;

procedure TfrmIBServiceEditor.UserNameChange(Sender: TObject);
begin
  AddParam('user_name', UserName.Text);  {do not localize}
end;

procedure TfrmIBServiceEditor.PasswordChange(Sender: TObject);
begin
  AddParam('password', Password.Text); {do not localize}
end;

end.
