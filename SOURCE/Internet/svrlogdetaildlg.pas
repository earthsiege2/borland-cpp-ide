{***************************************************************}
{                                                               }
{   Borland Delphi Visual Component Library                     }
{                                                               }
{   Copyright (c) 2000-2001 Borland Software Corporation        }
{                                                               }
{***************************************************************}
unit SvrLogDetailDlg;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls, ActnList, SvrLogFrame, SvrLogDetailFrame, Registry;

type
  TLogDetail = class(TForm)
    ActionList1: TActionList;
    PrevAction: TAction;
    NextAction: TAction;
    CloseAction: TAction;
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    LogDetailFrame: TLogDetailFrame;
    procedure PrevActionExecute(Sender: TObject);
    procedure PrevActionUpdate(Sender: TObject);
    procedure NextActionExecute(Sender: TObject);
    procedure NextActionUpdate(Sender: TObject);
    procedure CloseActionExecute(Sender: TObject);
    procedure FormShow(Sender: TObject);
  private
    FLogFrame: TLogFrame;
  public
    constructor Create(AOwner: TComponent); override;
    procedure Load(Reg: TRegIniFile; const Section: string);
    procedure Save(Reg: TRegIniFile; const Section: string);
    property LogFrame: TLogFrame read FLogFrame write FLogFrame;
  end;

var
  FLogDetail: TLogDetail;

implementation

{$R *.dfm}

procedure TLogDetail.PrevActionExecute(Sender: TObject);
begin
  FLogFrame.Previous;
  FLogFrame.ShowDetail(LogDetailFrame);
end;

procedure TLogDetail.PrevActionUpdate(Sender: TObject);
begin
  (Sender as TAction).Enabled := FLogFrame.Index > 0;
end;

procedure TLogDetail.NextActionExecute(Sender: TObject);
begin
  FLogFrame.Next;
  FLogFrame.ShowDetail(LogDetailFrame);
end;

procedure TLogDetail.NextActionUpdate(Sender: TObject);
begin
  (Sender as TAction).Enabled := (FLogFrame.Count > 0)
    and (FLogFrame.Index < FLogFrame.Count - 1);
end;

constructor TLogDetail.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
end;

procedure TLogDetail.CloseActionExecute(Sender: TObject);
begin
  ModalResult := mrOk;
end;

const
  sLeft = 'Left';
  sTop = 'Top';
  sWidth = 'Width';
  sHeight = 'Height';

procedure TLogDetail.Load(Reg: TRegIniFile; const Section: string);
var
  LastPath: string;
begin
  LastPath := Reg.CurrentPath;
  Reg.OpenKey(Section, True);
  try
    if Reg.ValueExists(sLeft) then
    begin
      Position := poDesigned;
      Self.Left := Reg.ReadInteger('', sLeft, Self.Left);
      Self.Top := Reg.ReadInteger('', sTop, Self.Top);
      Self.Width := Reg.ReadInteger('', sWidth, Self.Width);
      Self.Height := Reg.ReadInteger('', sHeight, Self.Height);
    end;
  finally
    Reg.OpenKey('\' + LastPath, True);
  end;
  LogDetailFrame.Load(Reg, Section);
end;

procedure TLogDetail.Save(Reg: TRegIniFile; const Section: string);
var
  LastPath: string;
begin
  LogDetailFrame.Save(Reg, Section);
  LastPath := Reg.CurrentPath;
  Reg.OpenKey(Section, True);
  try
    Reg.WriteInteger('', sLeft, Self.Left);
    Reg.WriteInteger('', sTop, Self.Top);
    Reg.WriteInteger('', sWidth, Self.Width);
    Reg.WriteInteger('', sHeight, Self.Height);
  finally
    Reg.OpenKey('\' + LastPath, True);
  end;
end;

procedure TLogDetail.FormShow(Sender: TObject);
begin
  FLogFrame.ShowDetail(LogDetailFrame);
end;

end.
