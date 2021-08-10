{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit mxpbar;

{ the progress dialog with a cancel button }

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls, ComCtrls;

type
  EUserCanceled = class(Exception);

  TProgressDialog = class(TForm)
    ProgressBar: TProgressBar;
    CancelButton: TButton;
    StatusText: TStaticText;
    procedure CancelButtonClick(Sender: TObject);
    procedure FormActivate(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  private
    FCanceled: Boolean;
    FInterval: Integer;
    FCount: Integer;
    FRealMax: Integer;
    FBuilding: Boolean;
    BuildDone: Boolean;
    FExceptMessage: string;
    FOnPerformBuild: TNotifyEvent;
    function GetMax: Integer;
    procedure SetMax(Value: Integer);
    procedure SetInterval(Value: Integer);
    procedure StartBuild(var Message); message WM_USER;
  public
    function StepProgress: Boolean;
    procedure ShowStatus(Msg: string);
    function UpdateProgress: Integer;
    procedure Reset;
    property Max: Integer read GetMax write SetMax;
    property Canceled: Boolean read FCanceled write FCanceled;
    property Interval: Integer read FInterval write SetInterval;
    property OnPerformBuild: TNotifyEvent read FOnPerformBuild write FOnPerformBuild;
    property ExceptMessage: string read FExceptMessage write FExceptMessage;
  end;

var
  ProgressDlg: TProgressDialog = nil;

implementation

{$R *.DFM}

procedure TProgressDialog.StartBuild(var Message);
begin
  try
    FBuilding := True;
    if Assigned(FOnPerformBuild) then
    begin
      try
        FOnPerformBuild(Self);
      except
        FExceptMessage := Exception(ExceptObject).Message;
        ModalResult := mrAbort;
      end;
      ModalResult := mrCancel;
    end;
  finally
    Self.Visible := False;
    BuildDone := True;
    FBuilding := False;
    Canceled := True;
  end;
end;

function TProgressDialog.UpdateProgress: Integer;
begin
  StepProgress;
  Application.ProcessMessages;
  if Canceled then
    Result := -1
  else
    Result := 0;
end;

function TProgressDialog.GetMax: Integer;
begin
  Result := FRealMax;
end;

procedure TProgressDialog.SetMax(Value: Integer);
begin
  if (Value <> FRealMax) then
  begin
    FRealMax := Value;
    ProgressBar.Max := Value;
    ProgressBar.Position := 1;
    if (Value > 10000) then
      Interval := Integer(Trunc(Value * 0.05))
    else if (Value > 100) then
      Interval := Integer(Trunc(Value * 0.10))
    else
      Interval := 1;
  end;
end;

function TProgressDialog.StepProgress: Boolean;
begin
  Result := False;
  if (FCount = FInterval) and (ProgressBar.Max > 0) then
  begin
    if not Visible then Visible := True;
    ProgressBar.StepIt;
    FCount := 0;
    Result := True;
  end;
  Inc(FCount);
end;

procedure TProgressDialog.ShowStatus(Msg: string);
begin
  if (StatusText.Visible = False) then
    StatusText.Visible := True;
  StatusText.Caption := msg;
end;

procedure TProgressDialog.CancelButtonClick(Sender: TObject);
begin
  Canceled := True;
  if BuildDone and (CancelButton.ModalResult <> mrOK) then
    ModalResult := mrCancel;
end;

procedure TProgressDialog.SetInterval(Value: Integer);
begin
  if (Value <> FInterval) then
  begin
    { set the new max based on the interval }
    FInterval := Value;
    FCount := 1;
    ProgressBar.Step := Value;
  end;
end;

procedure TProgressDialog.Reset;
begin
  ProgressBar.Position := 1;
end;

procedure TProgressDialog.FormActivate(Sender: TObject);
begin
  if not FBuilding then
    PostMessage(Handle, WM_USER, 0, 0);
end;

procedure TProgressDialog.FormCreate(Sender: TObject);
begin
  SetBounds((Screen.Width - Width) div 2,
           (GetSystemMetrics(SM_CYSCREEN) - Height) div 3,
           Width, Height);
end;

end.
