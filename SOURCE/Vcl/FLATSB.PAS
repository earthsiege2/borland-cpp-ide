
{*******************************************************}
{                                                       }
{       Borland Delphi Runtime Library                  }
{       Win32 flat scrollbar interface unit             }
{                                                       }
{       Copyright (C) 1996,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit FlatSB;

//{$WEAKPACKAGEUNIT}

interface

uses Windows;

function InitializeFlatSB(hWnd: HWND): Bool; stdcall;
{$EXTERNALSYM InitializeFlatSB}
procedure UninitializeFlatSB(hWnd: HWND); stdcall;
{$EXTERNALSYM UninitializeFlatSB}
function FlatSB_GetScrollProp(p1: HWND; propIndex: Integer;
  p3: PInteger): Bool; stdcall;
{$EXTERNALSYM FlatSB_GetScrollProp}
function FlatSB_SetScrollProp(p1: HWND; index: Integer; newValue: Integer;
  p4: Bool): Bool; stdcall;
{$EXTERNALSYM FlatSB_SetScrollProp}

var
  FlatSB_EnableScrollBar: function(hWnd: HWND; wSBflags, wArrows: UINT): BOOL; stdcall;
  {$EXTERNALSYM FlatSB_EnableScrollBar}
  FlatSB_ShowScrollBar: function(hWnd: HWND; wBar: Integer; bShow: BOOL): BOOL; stdcall;
  {$EXTERNALSYM FlatSB_ShowScrollBar}
  FlatSB_GetScrollRange: function(hWnd: HWND; nBar: Integer; var lpMinPos,
    lpMaxPos: Integer): BOOL; stdcall;
  {$EXTERNALSYM FlatSB_GetScrollRange}
  FlatSB_GetScrollInfo: function(hWnd: HWND; BarFlag: Integer;
    var ScrollInfo: TScrollInfo): BOOL; stdcall;
  {$EXTERNALSYM FlatSB_GetScrollInfo}
  FlatSB_GetScrollPos: function(hWnd: HWND; nBar: Integer): Integer; stdcall;
  {$EXTERNALSYM FlatSB_GetScrollPos}
  FlatSB_SetScrollPos: function(hWnd: HWND; nBar, nPos: Integer;
    bRedraw: BOOL): Integer; stdcall;
  {$EXTERNALSYM FlatSB_SetScrollPos}
  FlatSB_SetScrollInfo: function(hWnd: HWND; BarFlag: Integer;
    const ScrollInfo: TScrollInfo; Redraw: BOOL): Integer; stdcall;
  {$EXTERNALSYM FlatSB_SetScrollInfo}
  FlatSB_SetScrollRange: function(hWnd: HWND; nBar, nMinPos, nMaxPos: Integer;
    bRedraw: BOOL): BOOL; stdcall;
  {$EXTERNALSYM FlatSB_SetScrollRange}

implementation

var
  _FlatSB_GetScrollProp: function(p1: HWND; propIndex: Integer;
    p3: PInteger): Bool; stdcall;
  _FlatSB_SetScrollProp: function(p1: HWND; index: Integer; newValue: Integer;
    p4: Bool): Bool; stdcall;
  _InitializeFlatSB: function(hWnd: HWND): Bool; stdcall;
  _UninitializeFlatSB: procedure(hWnd: HWND); stdcall;

function FlatSB_GetScrollProp(p1: HWND; propIndex: Integer;
  p3: PInteger): Bool; stdcall;
begin
  Result := Assigned(_FlatSB_GetScrollProp) and
    _FlatSB_GetScrollProp(p1, propIndex, p3);
end;

function FlatSB_SetScrollProp(p1: HWND; index: Integer; newValue: Integer;
  p4: Bool): Bool; stdcall;
begin
  Result := Assigned(_FlatSB_SetScrollProp) and
    _FlatSB_SetScrollProp(p1, index, newValue, p4);
end;

function InitializeFlatSB(hWnd: HWND): Bool; stdcall;
begin
  Result := Assigned(_InitializeFlatSB) and _InitializeFlatSB(hWnd);
end;

procedure UninitializeFlatSB(hWnd: HWND); stdcall;
begin
  if Assigned(_UninitializeFlatSB) then _UninitializeFlatSB(hWnd);
end;

procedure InitFlatSB;
const
  cctrl = 'comctl32.dll';
var
  ComCtl32DLL: THandle;
begin
  ComCtl32DLL := GetModuleHandle(cctrl);
  if ComCtl32DLL <> 0 then
  begin
    @_InitializeFlatSB := GetProcAddress(ComCtl32DLL, 'InitializeFlatSB');
    @_UninitializeFlatSB := GetProcAddress(ComCtl32DLL, 'UninitializeFlatSB');
    @_FlatSB_GetScrollProp := GetProcAddress(ComCtl32DLL, 'FlatSB_GetScrollProp');
    @_FlatSB_SetScrollProp := GetProcAddress(ComCtl32DLL, 'FlatSB_SetScrollProp');
    @FlatSB_EnableScrollBar := GetProcAddress(ComCtl32DLL, 'FlatSB_EnableScrollBar');
    if not Assigned(FlatSB_EnableScrollBar) then
      @FlatSB_EnableScrollBar := @EnableScrollBar;
    @FlatSB_ShowScrollBar := GetProcAddress(ComCtl32DLL, 'FlatSB_ShowScrollBar');
    if not Assigned(FlatSB_ShowScrollBar) then
      @FlatSB_ShowScrollBar := @ShowScrollBar;
    @FlatSB_GetScrollRange := GetProcAddress(ComCtl32DLL, 'FlatSB_GetScrollRange');
    if not Assigned(FlatSB_GetScrollRange) then
      @FlatSB_GetScrollRange := @GetScrollRange;
    @FlatSB_GetScrollInfo := GetProcAddress(ComCtl32DLL, 'FlatSB_GetScrollInfo');
    if not Assigned(FlatSB_GetScrollInfo) then
      @FlatSB_GetScrollInfo := @GetScrollInfo;
    @FlatSB_GetScrollPos := GetProcAddress(ComCtl32DLL, 'FlatSB_GetScrollPos');
    if not Assigned(FlatSB_GetScrollPos) then
      @FlatSB_GetScrollPos := @GetScrollPos;
    @FlatSB_SetScrollPos := GetProcAddress(ComCtl32DLL, 'FlatSB_SetScrollPos');
    if not Assigned(FlatSB_SetScrollPos) then
      @FlatSB_SetScrollPos := @SetScrollPos;
    @FlatSB_SetScrollInfo := GetProcAddress(ComCtl32DLL, 'FlatSB_SetScrollInfo');
    if not Assigned(FlatSB_SetScrollInfo) then
      @FlatSB_SetScrollInfo := @SetScrollInfo;
    @FlatSB_SetScrollRange := GetProcAddress(ComCtl32DLL, 'FlatSB_SetScrollRange');
    if not Assigned(FlatSB_SetScrollRange) then
      @FlatSB_SetScrollRange := @SetScrollRange;
  end;
end;

initialization
  InitFlatSB;
  
end.
 