{*******************************************************}
{                                                       }
{       Borland Delphi Test Server                      }
{                                                       }
{       Copyright (c) 2001 Borland Corporation          }
{                                                       }
{*******************************************************}

program WebAppDbg;

uses
  Forms,
  Windows,
  SysUtils,
  SvrHTTP in 'SvrHTTP.pas',
  SvrMainForm in 'SvrMainForm.pas' {WebAppDbgMainForm},
  SvrPropDlg in 'SvrPropDlg.pas' {DlgProperties},
  webcat in 'webcat.pas',
  ReqImpl in 'ReqImpl.pas',
  svrlog in 'svrlog.pas',
  SvrLogFrame in 'SvrLogFrame.pas' {LogFrame: TFrame},
  SvrLogDetailDlg in 'SvrLogDetailDlg.pas' {LogDetail},
  SvrLogDetailFrame in 'SvrLogDetailFrame.pas' {LogDetailFrame: TFrame},
  SvrLogColSettingsFrame in 'SvrLogColSettingsFrame.pas' {LogColSettingsFrame: TFrame},
  SvrStatsFrame in 'SvrStatsFrame.pas' {StatsFrame: TFrame},
  HTTPParse in 'HTTPParse.pas',
  SvrConst in 'SvrConst.pas',
  WebAppDbgAbout in 'WebAppDbgAbout.pas' {AboutBox};

{$R *.RES}

var
  Mutex: THandle;
  PrevWnd: THandle;
  Duplicate: Boolean;
  Text: array[0..255] of char;
begin
  Duplicate := False;
  Mutex := CreateMutex(nil, False, 'LaunchWebSnapSvrMutex'); // Do not localize
  try
    if WaitForSingleObject(Mutex, 10000) = WAIT_TIMEOUT then
      exit;
    PrevWnd := FindWindow(PChar(string(TWebAppDbgMainForm.ClassName)), nil);
    if IsWindow(PrevWnd) then
    begin
      GetWindowText(PrevWnd, Text, sizeof(Text));
      if CompareText(Text, sWebAppDebugger) = 0 then
        Duplicate := True;
    end;
    if Duplicate then
    begin
      PrevWnd := GetWindow(PrevWnd, GW_HWNDNEXT);
      if PrevWnd <> 0 then
      begin
        SetForeGroundWindow(PrevWnd);
        if IsIconic(PrevWnd) then
          ShowWindow(PrevWnd, SW_SHOWNORMAL);
        exit;
      end;
    end;
    Application.Initialize;
    Application.CreateForm(TWebAppDbgMainForm, WebAppDbgMainForm);
  finally
    ReleaseMutex(Mutex);
    CloseHandle(Mutex);
  end;
  Application.Run;
end.
