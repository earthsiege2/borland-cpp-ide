unit IdDsnNewMessagePart;

interface

uses
   Buttons, Classes, Controls, Dialogs, ExtCtrls, Forms, IdMessage,
   StdCtrls;

type
  TfrmNewMessagePart = class(TForm)
    Panel2: TPanel;
    btnOk: TButton;
    btnCancel: TButton;
    lbTypes: TListBox;
    procedure lbTypesClick(Sender: TObject);
    procedure lbTypesDblClick(Sender: TObject);
  protected
  public
    class function PromptForMsgPart(AMsg : TIdMessage): Boolean;
  end;

implementation
{$R *.dfm}

uses
  Graphics, IdGlobal,
  SysUtils;

class function TfrmNewMessagePart.PromptForMsgPart(AMsg : TIdMessage): Boolean;
begin
  with TfrmNewMessagePart.Create(nil) do try
    Result := (ShowModal = mrOk);
    if Result then begin
      case lbTypes.ItemIndex of
        { Attachment - TIdAttachment }
        0 : TIdAttachment.Create( AMsg.MessageParts, '');
        { Text - TIdText }
        1 : TIdText.Create(AMsg.MessageParts);
      end; //case cboType.ItemIndex of
    end; //if Result then
  finally Free; end;
end;

procedure TfrmNewMessagePart.lbTypesClick(Sender: TObject);
begin
  btnOk.Enabled := lbTypes.ItemIndex <> -1
end;

procedure TfrmNewMessagePart.lbTypesDblClick(Sender: TObject);
begin
  if btnOk.Enabled then begin
    btnOk.Click;
  end;
end;

end.
