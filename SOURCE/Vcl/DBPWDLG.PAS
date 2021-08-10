
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1995,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit DBPWDlg;

{$H+,X+}

interface

uses Windows, Classes, Graphics, Forms, Controls, StdCtrls;

type
  TPasswordDialog = class(TForm)
    GroupBox1: TGroupBox;
    Edit: TEdit;
    AddButton: TButton;
    RemoveButton: TButton;
    RemoveAllButton: TButton;
    OKButton: TButton;
    CancelButton: TButton;
    procedure EditChange(Sender: TObject);
    procedure AddButtonClick(Sender: TObject);
    procedure RemoveButtonClick(Sender: TObject);
    procedure RemoveAllButtonClick(Sender: TObject);
    procedure OKButtonClick(Sender: TObject);
  private
    PasswordAdded: Boolean;
    FSession: TComponent;
  end;

function PasswordDialog(ASession: TComponent): Boolean;

implementation

{$R *.DFM}

uses DBTables;

function PasswordDialog(ASession: TComponent): Boolean;
begin
  with TPasswordDialog.Create(Application) do
  try
    FSession := ASession;
    Result := ShowModal = mrOk;
  finally
    Free;
  end;
end;

procedure TPasswordDialog.EditChange(Sender: TObject);
var
  HasText: Boolean;
begin
  HasText := Edit.Text <> '';
  AddButton.Enabled := HasText;
  RemoveButton.Enabled := HasText;
  OKButton.Enabled := HasText or PasswordAdded;
end;

procedure TPasswordDialog.AddButtonClick(Sender: TObject);
begin
  (FSession as TSession).AddPassword(Edit.Text);
  PasswordAdded := True;
  Edit.Clear;
  Edit.SetFocus;
end;

procedure TPasswordDialog.RemoveButtonClick(Sender: TObject);
begin
  (FSession as TSession).RemovePassword(Edit.Text);
  Edit.Clear;
  Edit.SetFocus;
end;

procedure TPasswordDialog.RemoveAllButtonClick(Sender: TObject);
begin
  (FSession as TSession).RemoveAllPasswords;
  Edit.SetFocus;
end;

procedure TPasswordDialog.OKButtonClick(Sender: TObject);
begin
  (FSession as TSession).AddPassword(Edit.Text);
end;

end.
