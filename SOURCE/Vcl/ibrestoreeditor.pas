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

unit IBRestoreEditor;

interface

uses
{$IFDEF MSWINDOWS}
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, Grids, StdCtrls, ExtCtrls;
{$ENDIF}
{$IFDEF LINUX}
  SysUtils, Variants, QForms, QStdCtrls, QExtCtrls, Classes, QControls,
  QGrids, QGraphics, Types;
{$ENDIF}

type
  TfrmIBRestoreEditor = class(TForm)
    sgDatabaseFiles: TStringGrid;
    Panel1: TPanel;
    OKBtn: TButton;
    CancelBtn: TButton;
    HelpBtn: TButton;
    procedure sgDatabaseFilesDrawCell(Sender: TObject; ACol, ARow: Integer;
      Rect: TRect; State: TGridDrawState);
    procedure sgDatabaseFilesKeyDown(Sender: TObject; var Key: Word;
      Shift: TShiftState);
    procedure sgDatabaseFilesSelectCell(Sender: TObject; ACol,
      ARow: Integer; var CanSelect: Boolean);
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
    constructor Create(AOwner : TComponent; Values : TStrings); reintroduce;
    procedure GetStrings(s : TStrings);
  end;

implementation

{$IFDEF MSWINDOWS}
uses IBDCLConst;

{$R *.dfm}
{$ENDIF}
{$IFDEF LINUX}
uses VKCodes, IBDCLConst;

{$R *.xfm}
{$ENDIF}

procedure TfrmIBRestoreEditor.sgDatabaseFilesDrawCell(Sender: TObject; ACol,
  ARow: Integer; Rect: TRect; State: TGridDrawState);
const
  INDENT = 2;
var
  lLeft: integer;
  lText: string;
begin
  with Sender as TStringGrid do //sgDatabaseFiles.canvas do
  begin
    if (ACol = 2) and (ARow <> 0) then
    begin
      canvas.font.color := clBlack;
      if canvas.brush.color = clHighlight then
        canvas.font.color := clWhite;
      lText := Cells[ACol,ARow];
      lLeft := Rect.Left + INDENT;
      Canvas.TextRect(Rect, lLeft, Rect.top + INDENT, lText);
    end;
  end;
end;

procedure TfrmIBRestoreEditor.sgDatabaseFilesKeyDown(Sender: TObject; var Key: Word;
  Shift: TShiftState);
var
  lKey : Word;
begin
  if (Key = VK_TAB) and (ssCtrl in Shift) then
  begin
    if sgDatabaseFiles.Col < sgDatabaseFiles.ColCount - 1 then
    begin
      sgDatabaseFiles.Col := sgDatabaseFiles.Col + 1;
    end
    else
    begin
      if sgDatabaseFiles.Row = sgDatabaseFiles.RowCount - 1 then
        sgDatabaseFiles.RowCount := sgDatabaseFiles.RowCount + 1;
      sgDatabaseFiles.Col := 0;
      sgDatabaseFiles.Row := sgDatabaseFiles.Row + 1;
    end;
  end;

  if (Key = VK_RETURN) and
    (sgDatabaseFiles.Cells[sgDatabaseFiles.Col,sgDatabaseFiles.Row] <> '') then
  begin
    lKey := VK_TAB;
    sgDatabaseFilesKeyDown(Self, lKey, [ssCtrl]);
  end;
end;

procedure TfrmIBRestoreEditor.sgDatabaseFilesSelectCell(Sender: TObject; ACol,
  ARow: Integer; var CanSelect: Boolean);
begin
  with Sender as TStringGrid do begin
    if ARow = RowCount-1 then
      RowCount := RowCount + 1;
  end;
end;

procedure TfrmIBRestoreEditor.FormCreate(Sender: TObject);
begin
  sgDatabaseFiles.Cells[0,0] := SFileNames;
  sgDatabaseFiles.Cells[1,0] := SPages;
end;

constructor TfrmIBRestoreEditor.Create(AOwner: TComponent;
  Values: TStrings);
var
  i: integer;
begin
  inherited Create(AOwner);
  for i := 1 to sgDatabaseFiles.RowCount do
  begin
    sgDatabaseFiles.Cells[0,i] := '';   {do not localize}
    sgDatabaseFiles.Cells[1,i] := '';   {do not localize}
  end;

  for i := 0 to Values.Count - 1 do
    if Trim(Values[i]) <> '' then   {do not localize}
    begin
      if Values.Names[i] <> '' then    {do not localize}
      begin
        sgDatabaseFiles.Cells[0,i + 1] := Values.Names[i];
        sgDatabaseFiles.Cells[1,i + 1] := Values.Values[sgDatabaseFiles.Cells[0,i + 1]];
      end
      else
        sgDatabaseFiles.Cells[0,i + 1] := Values[i];
      sgDatabaseFiles.RowCount := sgDatabaseFiles.RowCount + 1;
    end;
end;

procedure TfrmIBRestoreEditor.GetStrings(s: TStrings);
var
  i : Integer;
  temp : String;
begin
  s.Clear;
  for i := 1 to sgDatabaseFiles.RowCount do
  begin
    temp := '';  {do not localize}
    if Trim(sgDatabaseFiles.Cells[0, i]) <> '' then   {do not localize}
    begin
      temp := sgDatabaseFiles.Cells[0, i];
      if Trim(sgDatabaseFiles.Cells[1, i]) <> '' then    {do not localize}
        temp := temp + '=' + sgDatabaseFiles.Cells[1, i];    {do not localize}
      s.Add(temp);
    end;
  end;
end;

end.
