{*******************************************************}
{                                                       }
{       Borland Delphi Test Server                      }
{                                                       }
{  Copyright (c) 2001 Borland Software Corporation      }
{                                                       }
{*******************************************************}
unit SvrLogColSettingsFrame;

interface

uses 
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs, SvrLogFrame,
  ComCtrls, SvrLog;

type
  TLogColSettingsFrame = class(TFrame)
    lvColumns: TListView;
    procedure FrameResize(Sender: TObject);
  private
    FLogFrame: TLogFrame;
    procedure SetLogFrame(const Value: TLogFrame);
  public
    procedure UpdateColumns;
    property LogFrame: TLogFrame read FLogFrame write SetLogFrame;

  end;

implementation


{$R *.dfm}

{ TLogColumnsFrame }

procedure TLogColSettingsFrame.SetLogFrame(const Value: TLogFrame);
var
  Item: TListItem;
  I: Integer;
  LogColumn: TLogColumn;
  Positions: TLogColumnOrder;
begin
  FLogFrame := Value;
  FLogFrame.SynchColumnInfo;
  FLogFrame.GetColumnOrder(Positions);
  for I := Low(Positions) to High(Positions) do
  begin
    Item := lvColumns.Items.Add;
    LogColumn := Positions[I];
    Item.Caption := LogFrame.ColumnCaption[LogColumn];
    Item.Checked := LogFrame.ColumnVisible[LogColumn];
    Item.Data := Pointer(LogColumn);
  end;
end;

procedure TLogColSettingsFrame.FrameResize(Sender: TObject);
begin
  lvColumns.Columns[0].Width := lvColumns.ClientWidth;
end;

procedure TLogColSettingsFrame.UpdateColumns;
var
  I: Integer;
  Item: TListItem;
begin
  for I := 0 to lvColumns.Items.Count - 1 do
  begin
    Item := lvColumns.Items[I];
    LogFrame.ColumnVisible[TLogColumn(Item.Data)] := Item.Checked;
  end;
  LogFrame.RefreshColumns;
  LogFrame.RefreshSubItems;
end;

end.
