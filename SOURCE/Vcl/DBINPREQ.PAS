
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1996,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit DBInpReq;

{$R-}

interface

uses Windows, Classes, SysUtils, Forms, Controls, StdCtrls, ExtCtrls,
  BDE, Dialogs;

type
  TInputReqDialog = class(TForm)
    OKButton: TButton;
    CancelButton: TButton;
    InputOptions: TPanel;
    NoPromptAgain: TCheckBox;
    ErrorHelp: TLabel;
    InputMessage: TLabel;
    ErrorGroupBox: TPanel;
    ErrorGoupBoxSpacer: TPanel;
    DescriptionGroupBox: TPanel;
    DescriptionGroupBoxSpacer: TPanel;
    procedure InputOptionsClick(Sender: TObject);
  private
    FCBInfo: PCBInputDesc;
    FSelection: Integer;
    procedure SetCBInfo(var CBInfo: CBInputDesc);
    procedure GetCBInfo(var CBInfo: CBInputDesc);
  end;

function InputRequest(var InputReqInfo: CBInputDesc): CBRType;

implementation

uses DB, DBTables;

{$R *.DFM}

function InputRequest(var InputReqInfo: CBInputDesc): CBRType;
begin
  Result := cbrUSEDEF;
  with TInputReqDialog.Create(Application) do
  try
    SetCBInfo(InputReqInfo);
    begin
      ShowModal;
      if ModalResult = mrOK then
      begin
        GetCBInfo(InputReqInfo);
        Result := cbrCHKINPUT;
      end;
    end;
  finally
    Free;
  end;
end;

procedure TInputReqDialog.SetCBInfo(var CBInfo: CBInputDesc);

  procedure CreateRadioButton(Index: Integer; const Cap: string);
  begin
    with TRadioButton.Create(Self) do
    begin
      Top := Index * (Height + 2) + 7;
      Left := 5;
      Width := InputOptions.Width - 10;
      Caption := Cap;
      Tag := Index;
      OnClick := InputOptionsClick;
      Parent := InputOptions;
    end;
  end;

var
  I: Integer;
  Sel: Integer;
begin
  FCBInfo := @CBInfo;
  with CBInfo do
  begin
    InputMessage.Caption := szMsg;
    for I := 0 to iCount - 1 do
      CreateRadioButton(I, acbEntry[I].szKeyWord);
    NoPromptAgain.Checked := bSave;
    Sel := iSelection;
    if (Sel < 1) or (Sel > iCount) then Sel := 1;
    ActiveControl := InputOptions.Controls[Sel - 1] as TWinControl;
  end;
end;

procedure TInputReqDialog.GetCBInfo(var CBInfo: CBInputDesc);
begin
  with CBInfo do
  begin
    iSelection := FSelection + 1;
    bSave := NoPromptAgain.Checked;
  end;
end;

procedure TInputReqDialog.InputOptionsClick(Sender: TObject);
begin
  FSelection := (Sender as TComponent).Tag;
  if (FSelection >= 0) and (FSelection < FCBInfo.iCount) then
    ErrorHelp.Caption := FCBInfo.acbEntry[FSelection].szHelp;
end;

type
  TInputReqClass = class
    FCBInputReq: CBInputDesc;
    FCallBack: TBDECallback;
  public
    destructor Destroy; override;
    function InputReqCallBack(CBInfo: Pointer): CBRType;
    procedure RegisterCallback(Session: TSession);
  end;

destructor TInputReqClass.Destroy;
begin
  if Assigned(Session) and (Session.Active) then
    FCallBack.Free;
end;

procedure TInputReqClass.RegisterCallback(Session: TSession);
begin
  FCallBack := TBDECallback.Create(Self, nil, cbINPUTREQ,
    @FCBInputReq, SizeOf(FCBInputReq), InputReqCallBack, False);
end;

function TInputReqClass.InputReqCallBack(CBInfo: Pointer): CBRType;
begin
  try
    Result := InputRequest(PCBInputDesc(CBInfo)^);
  except
    Result := cbrUseDef;
  end;
end;

var
  InputReqClass: TInputReqClass;

procedure InitProc(Session: TSession);
begin
  InputReqClass.RegisterCallback(Session);
end;

initialization
  InputReqClass := TInputReqClass.Create;
  RegisterBDEInitProc(InitProc);
finalization
  InputReqClass.Free;
end.
