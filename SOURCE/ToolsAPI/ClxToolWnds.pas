unit ClxToolWnds;

interface

uses
  SysUtils, Types, Classes, QGraphics, QControls, QForms, QDialogs,
  QExtCtrls, QComCtrls, QMenus, QTypes, ClxDesignWindows, DesignIntf,
  QActnList;

type
  TClxToolbarDesignWindow = class(TClxDesignWindow)
    ToolBar1: TToolBar;
    Splitter1: TSplitter;
    PopupMenu1: TPopupMenu;
    PopupMenu2: TPopupMenu;
    Toolbar2: TMenuItem;
    Textlabels1: TMenuItem;
    TextLabelsCmd: TAction;
    ToolbarCmd: TAction;
    procedure Splitter1CanResize(Sender: TObject; var NewSize: Integer;
      var Accept: Boolean);
    procedure Splitter1Moved(Sender: TObject);
    procedure Textlabels1Click(Sender: TObject);
    procedure ToolbarCmdExecute(Sender: TObject);
    procedure TextLabelsCmdExecute(Sender: TObject);
    procedure ToolbarCmdUpdate(Sender: TObject);
    procedure TextLabelsCmdUpdate(Sender: TObject);
  private
    FLargeButtons: Boolean;
    function GetLargeButtons: Boolean;
    procedure SetLargeButtons(Value: Boolean);
  protected
    procedure ResizeButtons(Large: Boolean); virtual;
  public
    property LargeButtons: Boolean read GetLargeButtons write SetLargeButtons;
  end;

implementation

{$R *.xfm}

const
  SmallToolbarSize = 30;
  SmallButtonHeight = 22;
  SmallButtonWidth = 23;
  LargeToolbarSize = 44;
  LargeButtonHeight = 36;
  LargeButtonWidth = 56;

function TClxToolbarDesignWindow.GetLargeButtons: Boolean;
begin
  Result := ToolBar1.Height > SmallToolBarSize;
end;

procedure TClxToolbarDesignWindow.ResizeButtons(Large: Boolean);
var
  NewLargeWidth, NewLargeHeight: Integer;
begin
  if Large <> FLargeButtons then
  begin
    with ToolBar1 do
    begin
      if Large then
      begin
        NewLargeWidth := MulDiv(LargeButtonWidth, PixelsPerInch, 96);
        NewLargeHeight := LargeButtonHeight + MulDiv(13{Height of text}, PixelsPerInch, 96) - 13;
        ShowCaptions := True;
        ButtonWidth := NewLargeWidth;
        ButtonHeight := NewLargeHeight;
        //! Take into account large font systems
        Height := ButtonHeight + 8;//!LargeToolbarSize;
        ShowHint := False;
      end
      else
      begin
        ShowCaptions := False;
        ButtonWidth := SmallButtonWidth;
        ButtonHeight := SmallButtonHeight;
        Height := SmallToolbarSize;
        ShowHint := True;
      end;
    end;
    FLargeButtons := Large;
  end;
end;

procedure TClxToolbarDesignWindow.SetLargeButtons(Value: Boolean);
begin
  ResizeButtons(Value);
end;

procedure TClxToolbarDesignWindow.Splitter1CanResize(Sender: TObject; var NewSize: Integer;
  var Accept: Boolean);
begin
  with Toolbar1 do
    if (Height >= LargeToolbarSize) then
      if (NewSize <= SmallToolbarSize) then
        NewSize := SmallToolbarSize
      else
        NewSize := LargeToolbarSize
    else
      if(NewSize >= LargeToolbarSize) then
        NewSize := LargeToolbarSize
      else
        NewSize := SmallToolbarSize;
end;

procedure TClxToolbarDesignWindow.Splitter1Moved(Sender: TObject);
begin
  ResizeButtons(ToolBar1.Height >= LargeToolbarSize);
end;

procedure TClxToolbarDesignWindow.Textlabels1Click(Sender: TObject);
begin
  with Textlabels1 do
  begin
    Checked := not Checked;
    LargeButtons := Checked;
  end;
end;

procedure TClxToolbarDesignWindow.TextLabelsCmdExecute(Sender: TObject);
begin
  with TextLabelsCmd do
    LargeButtons := not Checked;
end;

procedure TClxToolbarDesignWindow.TextLabelsCmdUpdate(Sender: TObject);
begin
  (Sender as TAction).Checked := LargeButtons;
end;

procedure TClxToolbarDesignWindow.ToolbarCmdExecute(Sender: TObject);
begin
  with ToolbarCmd do
  begin
    Splitter1.Top := Toolbar1.Top + Toolbar1.Height;
    ToolBar1.Visible := not Checked;
    Splitter1.Visible := Toolbar1.Visible;
    Checked := not Checked;
  end;
end;

procedure TClxToolbarDesignWindow.ToolbarCmdUpdate(Sender: TObject);
begin
  (Sender as TAction).Checked := Toolbar1.Visible;
end;

end.
