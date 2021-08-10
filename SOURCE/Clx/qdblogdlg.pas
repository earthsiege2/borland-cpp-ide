{ *************************************************************************** }
{                                                                             }
{ Delphi and Kylix Cross-Platform Visual Component Library                    }
{                                                                             }
{ Copyright (c) 1995, 2001 Borland Software Corporation                       }
{                                                                             }
{ Licensees holding a valid Borland No-Nonsense License for this Software may }
{ use this file in accordance with such license, which appears in the file    }
{ license.txt that came with this Software.                                   }
{                                                                             }
{ *************************************************************************** }


unit QDBLogDlg;

{$P+,H+,X+}

interface

{$IFDEF MSWINDOWS}
uses SysUtils, Classes, QGraphics, QControls, QForms, QStdCtrls, QExtCtrls, DB;
{$ENDIF}
{$IFDEF LINUX}
uses SysUtils, Libc, Classes, QGraphics, QControls, QForms, QStdCtrls, QExtCtrls,
  DB;
{$ENDIF}

type
  TLoginDialog = class(TForm)
    Panel: TPanel;
    Bevel: TBevel;
    DatabaseName: TLabel;
    OKButton: TButton;
    CancelButton: TButton;
    Panel1: TPanel;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Password: TEdit;
    UserName: TEdit;
    procedure FormShow(Sender: TObject);
  end;

function LoginDialog(const ADatabaseName: string;
  var AUserName, APassword: string): Boolean;

function LoginDialogEx(const ADatabaseName: string;
  var AUserName, APassword: string; NameReadOnly: Boolean): Boolean;

function RemoteLoginDialog(var AUserName, APassword: string): Boolean;

procedure SetCursorType(const CurIndex: Integer);


implementation

{$R *.xfm}

uses QDBConsts;

function LoginDialog(const ADatabaseName: string;
  var AUserName, APassword: string): Boolean;
begin
  with TLoginDialog.Create(Application) do
  try
    DatabaseName.Caption := ADatabaseName;
    UserName.Text := AUserName;
    Result := False;
    if AUserName = '' then ActiveControl := UserName;
    if ShowModal = mrOk then
    begin
      AUserName := UserName.Text;
      APassword := Password.Text;
      Result := True;
    end;
  finally
    Free;
  end;
end;

function LoginDialogEx(const ADatabaseName: string;
  var AUserName, APassword: string; NameReadOnly: Boolean): Boolean;
begin
  with TLoginDialog.Create(Application) do
  try
    DatabaseName.Caption := ADatabaseName;
    UserName.Text := AUserName;
    Result := False;
    if NameReadOnly then
      UserName.Enabled := False
    else
      if AUserName = '' then ActiveControl := UserName;
    if ShowModal = mrOk then
    begin
      AUserName := UserName.Text;
      APassword := Password.Text;
      Result := True;
    end;
  finally
    Free;
  end;
end;

function RemoteLoginDialog(var AUserName, APassword: string): Boolean;
begin
  with TLoginDialog.Create(Application) do
  try
    Caption := SRemoteLogin;
    Bevel.Visible := False;
    DatabaseName.Visible := False;
    Label3.Visible := False;
    Panel.Height := Panel.Height - Bevel.Top;
    OKButton.Top := OKButton.Top - Bevel.Top;
    CancelButton.Top := CancelButton.Top - Bevel.Top;
    Height := Height - Bevel.Top;
    UserName.Text := AUserName;
    Result := False;
    if AUserName = '' then ActiveControl := UserName;
    if ShowModal = mrOk then
    begin
      AUserName := UserName.Text;
      APassword := Password.Text;
      Result := True;
    end;
  finally
    Free;
  end;
end;

procedure TLoginDialog.FormShow(Sender: TObject);
begin
  if (DatabaseName.Width + DatabaseName.Left) >= Panel.ClientWidth then
    DatabaseName.Width := (Panel.ClientWidth - DatabaseName.Left) - 5;
end;

procedure SetCursorType(const CurIndex: Integer);
begin
  Screen.Cursor := TCursor(CurIndex);
end;

initialization
  if not Assigned(LoginDialogProc) then
    LoginDialogProc := LoginDialog;
  if not Assigned(LoginDialogExProc) then
    LoginDialogExProc := LoginDialogEx;
  if not Assigned(RemoteLoginDialogProc) then
    RemoteLoginDialogProc := RemoteLoginDialog;
  ScreenCursorProc := SetCursorType;
end.
