{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit mxdsql;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  Db, DBTables, Grids, DBGrids, StdCtrls;

type
  TSQLWindow = class(TForm)
    DBGrid1: TDBGrid;
    Query1: TQuery;
    DataSource1: TDataSource;
    Memo1: TMemo;
  private
    { Private declarations }
  public
    function SInitialize(DataBaseName: string; SQL: string): Boolean;
    { Public declarations }
  end;

var
  Form2: TSQLWindow;

procedure ShowSQLWindow(DataBaseName: string; SQL: string);

implementation

{$R *.DFM}

procedure ShowSQLWindow(DataBaseName: string; SQL: string);
var
  aWindow: TSQLWindow;
  x,y: Integer;
begin
  aWindow := TSQLWindow.Create(application);
  if (aWindow.SInitialize(DataBaseName, SQL)) then
  begin
    x := (Screen.Width - aWindow.Width) div 2;
    y := (Screen.Height - aWindow.Height) div 2;
    if (x < 0) then x := 0;
    if (y < 0) then y := 0;
    aWindow.Left := x;
    aWindow.Top := y;
    aWindow.ShowModal;
  end;
  aWindow.free;
end;

function TSQLWindow.SInitialize(DataBaseName: string; SQL: string): Boolean;
begin
  Query1.DataBaseName := DataBaseName;
  Query1.SQL.text := SQL;
  Query1.active := True;
  Memo1.text := SQL;
  Result := Query1.active;
end;

end.
