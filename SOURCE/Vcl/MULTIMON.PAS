
{*******************************************************}
{                                                       }
{       Borland Delphi Run-time Library                 }
{       Win32 Multi-monitor support Unit                }
{                                                       }
{       Copyright (c) 1985-1999, Microsoft Corporation  }
{                                                       }
{       Translator: Inprise Corporation                 }
{                                                       }
{*******************************************************}

unit MultiMon;

(*
 * MultiMon unit provides access to the new MultiMonitor
 * APIs provided in Win98 and NT5 and greater.  For
 * backwards compatibility, the new APIs are stubbed out
 * here for older Win32 OS systems.
 *)

interface

uses Windows;

{$HPPEMIT '#include <multimon.h>' }

const
  { GetSystemMetrics() codes }
  SM_XVIRTUALSCREEN = 76;
  {$EXTERNALSYM SM_XVIRTUALSCREEN}
  SM_YVIRTUALSCREEN = 77;
  {$EXTERNALSYM SM_YVIRTUALSCREEN}
  SM_CXVIRTUALSCREEN = 78;
  {$EXTERNALSYM SM_CXVIRTUALSCREEN}
  SM_CYVIRTUALSCREEN = 79;
  {$EXTERNALSYM SM_CYVIRTUALSCREEN}
  SM_CMONITORS = 80;
  {$EXTERNALSYM SM_CMONITORS}
  SM_SAMEDISPLAYFORMAT = 81;
  {$EXTERNALSYM SM_SAMEDISPLAYFORMAT}
  SM_CMETRICS = 83;
  {$EXTERNALSYM SM_CMETRICS}

type






  HMONITOR = type Integer;
  {$EXTERNALSYM HMONITOR}

const
  MONITOR_DEFAULTTONULL = $0;
  {$EXTERNALSYM MONITOR_DEFAULTTONULL}
  MONITOR_DEFAULTTOPRIMARY = $1;
  {$EXTERNALSYM MONITOR_DEFAULTTOPRIMARY}
  MONITOR_DEFAULTTONEAREST = $2;
  {$EXTERNALSYM MONITOR_DEFAULTTONEAREST}
  MONITORINFOF_PRIMARY = $1;
  {$EXTERNALSYM MONITORINFOF_PRIMARY}

const
  CCHDEVICENAME = 32;
  {$EXTERNALSYM CCHDEVICENAME}

type
  {$EXTERNALSYM tagMONITORINFOA}
  tagMONITORINFOA = record
    cbSize: DWORD;
    rcMonitor: TRect;
    rcWork: TRect;
    dwFlags: DWORD;
  end;
  {$EXTERNALSYM tagMONITORINFOW}
  tagMONITORINFOW = record
    cbSize: DWORD;
    rcMonitor: TRect;
    rcWork: TRect;
    dwFlags: DWORD;
  end;
  {$EXTERNALSYM tagMONITORINFO}
  tagMONITORINFO = tagMONITORINFOA;
  {$EXTERNALSYM MONITORINFOA}
  MONITORINFOA = tagMONITORINFOA;
  {$EXTERNALSYM MONITORINFOW}
  MONITORINFOW = tagMONITORINFOW;
  {$EXTERNALSYM MONITORINFO}
  MONITORINFO = MONITORINFOA;
  {$EXTERNALSYM LPMONITORINFOA}
  LPMONITORINFOA = ^tagMONITORINFOA;
  {$EXTERNALSYM LPMONITORINFOW}
  LPMONITORINFOW = ^tagMONITORINFOW;
  {$EXTERNALSYM LPMONITORINFO}
  LPMONITORINFO = LPMONITORINFOA;
  {$EXTERNALSYM PMonitorInfoA}
  PMonitorInfoA = ^tagMONITORINFO;
  {$EXTERNALSYM PMonitorInfoW}
  PMonitorInfoW = ^tagMONITORINFO;
  {$EXTERNALSYM PMonitorInfo}
  PMonitorInfo = PMonitorInfoA;
  {$EXTERNALSYM TMonitorInfoA}
  TMonitorInfoA = tagMONITORINFO;
  {$EXTERNALSYM TMonitorInfoW}
  TMonitorInfoW = tagMONITORINFO;
  {$EXTERNALSYM TMonitorInfo}
  TMonitorInfo = TMonitorInfoA;

  {$EXTERNALSYM tagMONITORINFOEXA}
  tagMONITORINFOEXA = record
    cbSize: DWORD;
    rcMonitor: TRect;
    rcWork: TRect;
    dwFlags: DWORD;
    szDevice: array[0..CCHDEVICENAME] of AnsiChar;
  end;
  {$EXTERNALSYM tagMONITORINFOEXW}
  tagMONITORINFOEXW = record
    cbSize: DWORD;
    rcMonitor: TRect;
    rcWork: TRect;
    dwFlags: DWORD;
    szDevice: array[0..CCHDEVICENAME] of WideChar;
  end;
  {$EXTERNALSYM tagMONITORINFOEX}
  tagMONITORINFOEX = tagMONITORINFOEXA;
  {$EXTERNALSYM MONITORINFOEXA}
  MONITORINFOEXA = tagMONITORINFOEXA;
  {$EXTERNALSYM MONITORINFOEXW}
  MONITORINFOEXW = tagMONITORINFOEXW;
  {$EXTERNALSYM MONITORINFOEX}
  MONITORINFOEX = MONITORINFOEXA;
  {$EXTERNALSYM LPMONITORINFOEXA}
  LPMONITORINFOEXA = ^tagMONITORINFOEXA;
  {$EXTERNALSYM LPMONITORINFOEXW}
  LPMONITORINFOEXW = ^tagMONITORINFOEXW;
  {$EXTERNALSYM LPMONITORINFOEX}
  LPMONITORINFOEX = LPMONITORINFOEXA;
  {$EXTERNALSYM PMonitorInfoExA}
  PMonitorInfoExA = ^tagMONITORINFOEX;
  {$EXTERNALSYM PMonitorInfoExW}
  PMonitorInfoExW = ^tagMONITORINFOEX;
  {$EXTERNALSYM PMonitorInfoEx}
  PMonitorInfoEx = PMonitorInfoExA;
  {$EXTERNALSYM TMonitorInfoExA}
  TMonitorInfoExA = tagMONITORINFOEX;
  {$EXTERNALSYM TMonitorInfoExW}
  TMonitorInfoExW = tagMONITORINFOEX;
  {$EXTERNALSYM TMonitorInfoEx}
  TMonitorInfoEx = TMonitorInfoExA;

{$EXTERNALSYM TMonitorEnumProc}
  TMonitorEnumProc = function(hm: HMONITOR; dc: HDC; r: PRect; l: LPARAM): Boolean; stdcall;
{$EXTERNALSYM TGetSystemMetrics}
  TGetSystemMetrics = function(nIndex: Integer): Integer; stdcall;
{$EXTERNALSYM TMonitorFromWindow}
  TMonitorFromWindow = function(hWnd: HWND; dwFlags: DWORD): HMONITOR; stdcall;
{$EXTERNALSYM TMonitorFromRect}
  TMonitorFromRect = function(lprcScreenCoords: PRect; dwFlags: DWORD): HMONITOR; stdcall;
{$EXTERNALSYM TMonitorFromPoint}
  TMonitorFromPoint = function(ptScreenCoords: TPoint; dwFlags: DWORD): HMONITOR; stdcall;
{$EXTERNALSYM TGetMonitorInfoA}
  TGetMonitorInfoA = function(hMonitor: HMONITOR; lpMonitorInfo: PMonitorInfoA): Boolean; stdcall;
{$EXTERNALSYM TGetMonitorInfoW}
  TGetMonitorInfoW = function(hMonitor: HMONITOR; lpMonitorInfo: PMonitorInfoW): Boolean; stdcall;
  {$EXTERNALSYM TGetMonitorInfo}
  TGetMonitorInfo = TGetMonitorInfoA;
{$EXTERNALSYM TEnumDisplayMonitors}
  TEnumDisplayMonitors = function(hdc: HDC; lprcIntersect: PRect; lpfnEnumProc: TMonitorEnumProc;
    lData: LPARAM): Boolean; stdcall;

var
  {$EXTERNALSYM GetSystemMetrics}
  GetSystemMetrics: TGetSystemMetrics;
  {$EXTERNALSYM MonitorFromWindow}
  MonitorFromWindow: TMonitorFromWindow; 
  {$EXTERNALSYM MonitorFromRect}
  MonitorFromRect: TMonitorFromRect; 
  {$EXTERNALSYM MonitorFromPoint}
  MonitorFromPoint: TMonitorFromPoint;
  {$EXTERNALSYM GetMonitorInfoA}
  {procedure}GetMonitorInfoA: TGetMonitorInfoA;
  {$EXTERNALSYM GetMonitorInfoW}
  {procedure}GetMonitorInfoW: TGetMonitorInfoW;
  {$EXTERNALSYM GetMonitorInfo}
  {procedure}GetMonitorInfo: TGetMonitorInfo;
  {$EXTERNALSYM EnumDisplayMonitors}
  EnumDisplayMonitors: TEnumDisplayMonitors;

implementation

type
  TMultiMonApi = (mmGetSystemMetrics, mmMonitorFromWindow, mmMonitorFromRect,
    mmMonitorFromPoint, mmGetMonitorInfo, mmGetMonitorInfoA, mmGetMonitorInfoW,
    mmEnumDisplayMonitors);

const
  xPRIMARY_MONITOR = HMONITOR($12340042);
  sUser32 = 'USER32.DLL';

var
  User32Dll: THandle;
  InitApis: array [mmGetSystemMetrics..mmEnumDisplayMonitors] of Boolean;
  MMAvailable: Boolean;

function InitAnApi(mmAPI: TMultiMonApi; ApiStub: Pointer; ApiName: string): Pointer;
begin
  Result := nil;
  if not InitApis[mmApi] then
  begin
    if User32Dll <> 0 then
    begin
      if (mmAPI = mmGetSystemMetrics) and not MMAvailable then
      begin
        @GetMonitorInfo := InitAnApi(mmGetMonitorInfo, @GetMonitorInfo, 'GetMonitorInfoA');
        if not MMAvailable then
          ApiName := '';
      end;
      Result := GetProcAddress(User32Dll, PChar(ApiName))
    end else Result := nil;
    if not Assigned(Result) then
      Result := ApiStub
    else if (mmAPI <> mmGetSystemMetrics) then
      MMAvailable := True;
    InitApis[mmApi] := True;
  end;
end;

function _GetSystemMetrics(nIndex: Integer): Integer; stdcall;
begin
  if not InitApis[mmGetSystemMetrics] then
  begin
    @GetSystemMetrics := InitAnApi(mmGetSystemMetrics, @GetSystemMetrics, 'GetSystemMetrics');
    Result := GetSystemMetrics(nIndex);
    Exit;
  end;

  Result := -1;
  case nIndex of
    SM_CMONITORS,
    SM_SAMEDISPLAYFORMAT:
      Result := 1;
    SM_XVIRTUALSCREEN,
    SM_YVIRTUALSCREEN:
      Result := 0;
    SM_CXVIRTUALSCREEN:
      nIndex := SM_CXSCREEN;
    SM_CYVIRTUALSCREEN:
      nIndex := SM_CYSCREEN;
  end;
  if Result = -1 then
    Result := Windows.GetSystemMetrics(nIndex);
end;

function xMonitorFromRect(lprcScreenCoords: PRect; dwFlags: DWORD): HMONITOR; stdcall;
begin
  if not InitApis[mmMonitorFromRect] then
  begin
    @MonitorFromRect := InitAnApi(mmMonitorFromRect, @MonitorFromRect, 'MonitorFromRect');
    Result := MonitorFromRect(lprcScreenCoords, dwFlags);
    Exit;
  end;

  Result := 0;
  if Boolean(dwFlags and (MONITOR_DEFAULTTOPRIMARY or MONITOR_DEFAULTTONEAREST)) or
    (lprcScreenCoords.Right > 0) and
    (lprcScreenCoords.Bottom > 0) and
    (lprcScreenCoords.Left < GetSystemMetrics(SM_CXSCREEN)) and
    (lprcScreenCoords.Top < GetSystemMetrics(SM_CYSCREEN)) then
      Result := xPRIMARY_MONITOR;
end;

function xMonitorFromWindow(hWnd: HWND; dwFlags: DWORD): HMONITOR; stdcall;
var
  wp: TWindowPlacement;
begin
  if not InitApis[mmMonitorFromWindow] then
  begin
    @MonitorFromWindow := InitAnApi(mmMonitorFromWindow, @MonitorFromWindow, 'MonitorFromWindow');
    Result := MonitorFromWindow(hWnd, dwFlags);
    Exit;
  end;

  if Boolean(dwFlags and (MONITOR_DEFAULTTOPRIMARY or MONITOR_DEFAULTTONEAREST)) then
    Result := xPRIMARY_MONITOR
  else
  begin
    if IsIconic(hWnd) then
      GetWindowPlacement(hWnd, @wp)
    else
      GetWindowRect(hWnd, wp.rcNormalPosition);
    Result := xMonitorFromRect(@wp.rcNormalPosition, dwFlags);
  end
end;

function xMonitorFromPoint(ptScreenCoords: TPoint; dwFlags: DWORD): HMONITOR; stdcall;
begin
  if not InitApis[mmMonitorFromPoint] then
  begin
    @MonitorFromPoint := InitAnApi(mmMonitorFromPoint, @MonitorFromPoint, 'MonitorFromPoint');
    Result := MonitorFromPoint(ptScreenCoords, dwFlags);
    Exit;
  end;

  Result := 0;
  if Boolean(dwFlags and (MONITOR_DEFAULTTOPRIMARY or MONITOR_DEFAULTTONEAREST)) or
    (ptScreenCoords.X >= 0) and
    (ptScreenCoords.X < GetSystemMetrics(SM_CXSCREEN)) and
    (ptScreenCoords.Y >= 0 ) and
    (ptScreenCoords.Y < GetSystemMetrics(SM_CYSCREEN)) then
      Result := xPRIMARY_MONITOR;
end;

function xGetMonitorInfoA(hMonitor: HMONITOR; lpMonitorInfo: PMonitorInfoA): Boolean; stdcall;
var
  rcWork: TRect;
begin
  if not InitApis[mmGetMonitorInfoA] then
  begin
    @GetMonitorInfoA := InitAnApi(mmGetMonitorInfoA, @GetMonitorInfoA, 'GetMonitorInfoA');
    Result := GetMonitorInfoA(hMonitor, lpMonitorInfo);
    Exit;
  end;

  Result := False;
  if (hMonitor = xPRIMARY_MONITOR) and (lpMonitorInfo <> nil) and
    (lpMonitorInfo.cbSize >= DWORD(SizeOf(TMonitorInfo))) and
    SystemParametersInfo (SPI_GETWORKAREA, 0, @rcWork, 0) then
    begin
      lpMonitorInfo.rcMonitor.Left := 0;
      lpMonitorInfo.rcMonitor.Top := 0;
      lpMonitorInfo.rcMonitor.Right := GetSystemMetrics(SM_CXSCREEN);
      lpMonitorInfo.rcMonitor.Bottom := GetSystemMetrics(SM_CYSCREEN);
      lpMonitorInfo.rcWork := rcWork;
      lpMonitorInfo.dwFlags := MONITORINFOF_PRIMARY;
      if (lpMonitorInfo.cbSize >= DWORD(SizeOf(TMonitorInfoEx))) then
        lstrcpy(PMonitorInfoEx(lpMonitorInfo).szDevice, 'DISPLAY'); // do not localize
      Result := True;
    end;
end;
function xGetMonitorInfoW(hMonitor: HMONITOR; lpMonitorInfo: PMonitorInfoW): Boolean; stdcall;
var
  rcWork: TRect;
begin
  if not InitApis[mmGetMonitorInfoW] then
  begin
    @GetMonitorInfoW := InitAnApi(mmGetMonitorInfoW, @GetMonitorInfoW, 'GetMonitorInfoW');
    Result := GetMonitorInfoW(hMonitor, lpMonitorInfo);
    Exit;
  end;

  Result := False;
  if (hMonitor = xPRIMARY_MONITOR) and (lpMonitorInfo <> nil) and
    (lpMonitorInfo.cbSize >= DWORD(SizeOf(TMonitorInfo))) and
    SystemParametersInfo (SPI_GETWORKAREA, 0, @rcWork, 0) then
    begin
      lpMonitorInfo.rcMonitor.Left := 0;
      lpMonitorInfo.rcMonitor.Top := 0;
      lpMonitorInfo.rcMonitor.Right := GetSystemMetrics(SM_CXSCREEN);
      lpMonitorInfo.rcMonitor.Bottom := GetSystemMetrics(SM_CYSCREEN);
      lpMonitorInfo.rcWork := rcWork;
      lpMonitorInfo.dwFlags := MONITORINFOF_PRIMARY;
      if (lpMonitorInfo.cbSize >= DWORD(SizeOf(TMonitorInfoEx))) then
        lstrcpy(PMonitorInfoEx(lpMonitorInfo).szDevice, 'DISPLAY'); // do not localize
      Result := True;
    end;
end;
function xGetMonitorInfo(hMonitor: HMONITOR; lpMonitorInfo: PMonitorInfo): Boolean; stdcall;
var
  rcWork: TRect;
begin
  if not InitApis[mmGetMonitorInfo] then
  begin
    @GetMonitorInfo := InitAnApi(mmGetMonitorInfo, @GetMonitorInfo, 'GetMonitorInfo');
    Result := GetMonitorInfo(hMonitor, lpMonitorInfo);
    Exit;
  end;

  Result := False;
  if (hMonitor = xPRIMARY_MONITOR) and (lpMonitorInfo <> nil) and
    (lpMonitorInfo.cbSize >= DWORD(SizeOf(TMonitorInfo))) and
    SystemParametersInfo (SPI_GETWORKAREA, 0, @rcWork, 0) then
    begin
      lpMonitorInfo.rcMonitor.Left := 0;
      lpMonitorInfo.rcMonitor.Top := 0;
      lpMonitorInfo.rcMonitor.Right := GetSystemMetrics(SM_CXSCREEN);
      lpMonitorInfo.rcMonitor.Bottom := GetSystemMetrics(SM_CYSCREEN);
      lpMonitorInfo.rcWork := rcWork;
      lpMonitorInfo.dwFlags := MONITORINFOF_PRIMARY;
      if (lpMonitorInfo.cbSize >= DWORD(SizeOf(TMonitorInfoEx))) then
        lstrcpy(PMonitorInfoEx(lpMonitorInfo).szDevice, 'DISPLAY'); // do not localize
      Result := True;
    end;
end;

function xEnumDisplayMonitors(hdcOptionalForPainting: HDC; lprcEnumMonitorsThatIntersect: PRect;
    lpfnEnumProc: TMonitorEnumProc; dwData: LPARAM): Boolean; stdcall;
var
  rcLimit, rcClip: TRect;
  ptOrg: TPoint;
  ClipBox: Integer;
begin
  if not InitApis[mmEnumDisplayMonitors] then
  begin
    @EnumDisplayMonitors := InitAnApi(mmEnumDisplayMonitors, @EnumDisplayMonitors, 'EnumDisplayMonitors');
    Result := EnumDisplayMonitors(hdcOptionalForPainting, lprcEnumMonitorsThatIntersect, lpfnEnumProc, dwData);
    Exit;
  end;

  Result := False;
  if not Assigned(lpfnEnumProc) then Exit;

  rcLimit.Left := 0;
  rcLimit.Top := 0;
  rcLimit.Right := GetSystemMetrics(SM_CXSCREEN);
  rcLimit.Bottom := GetSystemMetrics(SM_CYSCREEN);

  if hdcOptionalForPainting <> 0 then
  begin
    ClipBox := GetClipBox(hdcOptionalForPainting, rcClip);
    if not GetDCOrgEx(hdcOptionalForPainting, ptOrg) then Exit;
    OffsetRect(rcLimit, -ptOrg.x, -ptOrg.y);
    if not (IntersectRect(rcLimit, rcLimit, rcClip) and
      (lprcEnumMonitorsThatIntersect = nil) or
      IntersectRect(rcLimit, rcLimit, lprcEnumMonitorsThatIntersect^)) then
      begin
        if ClipBox = NULLREGION then Result := True;
        Exit;
      end;
   end else
     if (lprcEnumMonitorsThatintersect <> nil) and
       (not IntersectRect(rcLimit, rcLimit, lprcEnumMonitorsThatIntersect^)) then
       begin
         Result := True;
         Exit;
       end;
   Result := lpfnEnumProc( xPRIMARY_MONITOR, hdcOptionalForPainting, @rcLimit, dwData);
end;

procedure InitMultiMonStubs;
begin
  User32Dll := GetModuleHandle(sUser32);
  @GetSystemMetrics := @_GetSystemMetrics;
  @MonitorFromWindow := @xMonitorFromWindow;
  @MonitorFromRect := @xMonitorFromRect;
  @MonitorFromPoint := @xMonitorFromPoint;
  {procedure}@GetMonitorInfoA := @xGetMonitorInfoA;
  {procedure}@GetMonitorInfoW := @xGetMonitorInfoW;
  {procedure}@GetMonitorInfo := @xGetMonitorInfo;
  @EnumDisplayMonitors := @xEnumDisplayMonitors;
end;

initialization
  InitMultiMonStubs;

end.
