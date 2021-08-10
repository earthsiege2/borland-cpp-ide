{*******************************************************}
{                                                       }
{       Borland Delphi Test Server                      }
{                                                       }
{ Copyright (c) 2000-2001 Borland Software Corporation  }
{                                                       }
{*******************************************************}
unit SvrStatsFrame;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls, ActnList, SvrLog;

type
  TStatsFrame = class(TFrame)
    Button1: TButton;
    ActionList1: TActionList;
    ResetCountsAction: TAction;
    lblTotalResponseTime: TLabel;
    lblAvgResponseTime: TLabel;
    lblLastResponseTime: TLabel;
    lblRequestCount: TLabel;
    Label3: TLabel;
    Label5: TLabel;
    Label7: TLabel;
    Label8: TLabel;
    Label1: TLabel;
    Label2: TLabel;
    lblMinResponseTime: TLabel;
    lblMaxResponseTime: TLabel;
    GroupBox1: TGroupBox;
    procedure ResetCountsActionExecute(Sender: TObject);
    procedure ResetCountsActionUpdate(Sender: TObject);
  private
    FResponseCount: Uint;
    FRequestCount: Uint;
    FTotalResponseTime: TDateTime;
    FLastResponseTime: TDateTime;
    FMaxResponseTime: TDateTime;
    FMinResponseTime: TDateTime;
    function GetAvgResponseTime: TDateTime;
    procedure UpdateUI;
  public
    procedure LogStatistics(ATransaction: TTransactionLogEntry);
    property RequestCount: Uint read FRequestCount;
    property ResponseCount: Uint read FResponseCount;
    property TotalResponseTime: TDateTime read FTotalResponseTime;
    property AvgResponseTime: TDateTime read GetAvgResponseTime;
    property LastResponseTime: TDateTime read FLastResponseTime;
    property MaxResponseTime: TDateTime read FMaxResponseTime;
    property MinResponseTime: TDateTime read FMinResponseTime;
  end;

implementation

{$R *.dfm}

function TStatsFrame.GetAvgResponseTime: TDateTime;
begin
  if ResponseCount <> 0 then
    Result := TotalResponseTime / ResponseCount
  else
    Result := 0;
end;

procedure TStatsFrame.LogStatistics(ATransaction: TTransactionLogEntry);
begin
  if ATransaction is TRequestTransaction then
    Inc(FRequestCount);
  if ATransaction is TResponseTransaction then
  begin
    Inc(FResponseCount);
    FLastResponseTime := TResponseTransaction(ATransaction).ElapsedTime;
    FTotalResponseTime :=
      FTotalResponseTime + FLastResponseTime;
    if (FMinResponseTime = 0) or (FLastResponseTime < FMinResponseTime) then
      FMinResponseTime := FLastResponseTime;
    if (FLastResponseTime > FMaxResponseTime) then
      FMaxResponseTime := FLastResponseTime;
  end;
  UpdateUI;

end;

procedure TStatsFrame.ResetCountsActionExecute(Sender: TObject);
begin
  FRequestCount := 0;
  FTotalResponseTime := 0;
  FResponseCount := 0;
  FLastResponseTime := 0;
  FMinResponseTime := 0;
  FMaxResponseTime := 0;
  UpdateUI;
end;

procedure TStatsFrame.ResetCountsActionUpdate(Sender: TObject);
begin
  (Sender as TAction).Enabled := RequestCount > 0;
end;

procedure TStatsFrame.UpdateUI;
begin
  lblRequestCount.Caption := IntToStr(RequestCount);
  lblTotalResponseTime.Caption := FormatDateTime('hh:mm:ss:zzz', TotalResponseTime);
  lblAvgResponseTime.Caption := FormatDateTime('hh:mm:ss:zzz', AvgResponseTime);
  lblLastResponseTime.Caption := FormatDateTime('hh:mm:ss:zzz', LastResponseTime);
  lblMinResponseTime.Caption := FormatDateTime('hh:mm:ss:zzz', MinResponseTime);
  lblMaxResponseTime.Caption := FormatDateTime('hh:mm:ss:zzz', MaxResponseTime);
end;

end.
