
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1995,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit ToolWin;

{$R-,H+,X+}

interface

uses Windows, Messages, Classes, Controls, Forms;

type

{ TToolWindow }

  TEdgeBorder = (ebLeft, ebTop, ebRight, ebBottom);
  TEdgeBorders = set of TEdgeBorder;

  TEdgeStyle = (esNone, esRaised, esLowered);

  TToolWindow = class(TWinControl)
  private
    FEdgeBorders: TEdgeBorders;
    FEdgeInner: TEdgeStyle;
    FEdgeOuter: TEdgeStyle;
    procedure SetEdgeBorders(Value: TEdgeBorders);
    procedure SetEdgeInner(Value: TEdgeStyle);
    procedure SetEdgeOuter(Value: TEdgeStyle);
    procedure WMNCCalcSize(var Message: TWMNCCalcSize); message WM_NCCALCSIZE;
    procedure WMNCPaint(var Message: TMessage); message WM_NCPAINT;
    procedure CMBorderChanged(var Message: TMessage); message CM_BORDERCHANGED;
    procedure CMCtl3DChanged(var Message: TMessage); message CM_CTL3DCHANGED;
  public
    constructor Create(AOwner: TComponent); override;
    property EdgeBorders: TEdgeBorders read FEdgeBorders write SetEdgeBorders default [ebLeft, ebTop, ebRight, ebBottom];
    property EdgeInner: TEdgeStyle read FEdgeInner write SetEdgeInner default esRaised;
    property EdgeOuter: TEdgeStyle read FEdgeOuter write SetEdgeOuter default esLowered;
  end;

{ TToolDragDockObject }

  TToolDockObject = class(TDragDockObject)
  protected
    procedure AdjustDockRect(ARect: TRect); override;
    procedure DrawDragDockImage; override;
    procedure EraseDragDockImage; override;
  public
    constructor Create(AControl: TControl); override;
  end;

{ TToolDockForm }

  TSizingOrientation = (soNone, soHorizontal, soVertical);

  TToolDockForm = class(TCustomDockForm)
  private
    FPrevWidth: Integer;
    FPrevHeight: Integer;
    FSizingAdjustH: Integer;
    FSizingAdjustW: Integer;
    FSizingOrientation: TSizingOrientation;
    FUpdatingSize: Boolean;
    procedure WMNCCreate(var Message: TWMNCCreate); message WM_NCCREATE;
    procedure WMNCHitTest(var Message: TWMNCHitTest); message WM_NCHITTEST;
    procedure WMNCLButtonDown(var Message: TWMNCLButtonDown); message WM_NCLBUTTONDOWN;
    procedure WMSize(var Message: TWMSize); message WM_SIZE;
    procedure WMSysCommand(var Message: TWMSysCommand); message WM_SYSCOMMAND;
  protected
    function CanResize(var NewWidth, NewHeight: Integer): Boolean; override;
    procedure CreateParams(var Params: TCreateParams); override;
    procedure DoAddDockClient(Client: TControl; const ARect: TRect); override;
  public
    constructor Create(AOwner: TComponent); override;
  end;

implementation

uses SysUtils;

{ TToolWindow }

constructor TToolWindow.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FEdgeBorders := [ebLeft, ebTop, ebRight, ebBottom];
  FEdgeInner := esRaised;
  FEdgeOuter := esLowered;
end;

procedure TToolWindow.SetEdgeBorders(Value: TEdgeBorders);
begin
  if FEdgeBorders <> Value then
  begin
    FEdgeBorders := Value;
    RecreateWnd;
  end;
end;

procedure TToolWindow.SetEdgeInner(Value: TEdgeStyle);
begin
  if FEdgeInner <> Value then
  begin
    FEdgeInner := Value;
    RecreateWnd;
  end;
end;

procedure TToolWindow.SetEdgeOuter(Value: TEdgeStyle);
begin
  if FEdgeOuter <> Value then
  begin
    FEdgeOuter := Value;
    RecreateWnd;
  end;
end;

procedure TToolWindow.WMNCCalcSize(var Message: TWMNCCalcSize);
var
  EdgeSize: Integer;
begin
  with Message.CalcSize_Params^ do
  begin
    InflateRect(rgrc[0], -BorderWidth, -BorderWidth);
    EdgeSize := 0;
    if EdgeInner <> esNone then Inc(EdgeSize, 1);
    if EdgeOuter <> esNone then Inc(EdgeSize, 1);
    with rgrc[0] do
    begin
      if ebLeft in FEdgeBorders then Inc(Left, EdgeSize);
      if ebTop in FEdgeBorders then Inc(Top, EdgeSize);
      if ebRight in FEdgeBorders then Dec(Right, EdgeSize);
      if ebBottom in FEdgeBorders then Dec(Bottom, EdgeSize);
    end;
  end;
  inherited;
end;

procedure TToolWindow.WMNCPaint(var Message: TMessage);
const
  InnerStyles: array[TEdgeStyle] of Integer = (0, BDR_RAISEDINNER, BDR_SUNKENINNER);
  OuterStyles: array[TEdgeStyle] of Integer = (0, BDR_RAISEDOUTER, BDR_SUNKENOUTER);
  Ctl3DStyles: array[Boolean] of Integer = (BF_MONO, 0);
var
  DC: HDC;
  RC, RW: TRect;
begin
  { Get window DC that is clipped to the non-client area }
  DC := GetWindowDC(Handle);
  try
    Windows.GetClientRect(Handle, RC);
    GetWindowRect(Handle, RW);
    MapWindowPoints(0, Handle, RW, 2);
    OffsetRect(RC, -RW.Left, -RW.Top);
    ExcludeClipRect(DC, RC.Left, RC.Top, RC.Right, RC.Bottom);
    { Draw borders in non-client area }
    OffsetRect(RW, -RW.Left, -RW.Top);
    DrawEdge(DC, RW, InnerStyles[FEdgeInner] or OuterStyles[FEdgeOuter],
      Byte(FEdgeBorders) or Ctl3DStyles[Ctl3D] or BF_ADJUST);
    { Erase parts not drawn }
    IntersectClipRect(DC, RW.Left, RW.Top, RW.Right, RW.Bottom);
    Windows.FillRect(DC, RW, Brush.Handle);
  finally
    ReleaseDC(Handle, DC);
  end;
end;

procedure TToolWindow.CMBorderChanged(var Message: TMessage);
begin
  RecreateWnd;
  inherited;
end;

procedure TToolWindow.CMCtl3DChanged(var Message: TMessage);
begin
  inherited;
  if FEdgeBorders <> [] then RecreateWnd;
end;

{ TToolDockObject }

constructor TToolDockObject.Create(AControl: TControl);
var
  P: TPoint;
begin
  inherited Create(AControl);
  if not AControl.Floating then
  begin
    GetCursorPos(P);
    AControl.ManualFloat(Bounds(P.X - 10, P.Y - 10, AControl.UndockWidth,
      AControl.UndockHeight));
  end;
end;

procedure TToolDockObject.AdjustDockRect(ARect: TRect);
var
  R: TRect;
begin
exit;
  { if Control is floating then use its floating dock site's bounds }
  if Control.Floating and (Control.HostDockSite <> nil) then
  begin
    R := Control.HostDockSite.BoundsRect;
    if Control.HostDockSite.Parent <> nil then
      MapWindowPoints(Control.HostDockSite.Parent.Handle, 0, R, 2);
    if PtInRect(R, DragPos) then Exit;
  end;
  inherited AdjustDockRect(ARect)
end;

procedure TToolDockObject.DrawDragDockImage;
var
  P: TPoint;
  Form: TCustomForm;
begin
  if not Control.Floating then
    inherited DrawDragDockImage
  else
  begin
    Form := GetParentForm(Control);
    if Form <> nil then
    begin
      P := Point(Control.Left, Control.Top);
      if Control <> Form then
        MapWindowPoints(Form.Handle, 0, P, 1);
      Form.BoundsRect := Bounds(DockRect.Left + Form.Left - P.X,
        DockRect.Top + Form.Top - P.Y,
        DockRect.Right - DockRect.Left + Form.Width - Control.Width,
        DockRect.Bottom - DockRect.Top + Form.Height - Control.Height);
    end;
  end;
end;

procedure TToolDockObject.EraseDragDockImage;
begin
  if not Control.Floating then
    inherited EraseDragDockImage
end;

{ TToolDockForm }

constructor TToolDockForm.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  BorderWidth := 1;
end;

procedure TToolDockForm.CreateParams(var Params: TCreateParams);
begin
  inherited CreateParams(Params);
  with Params do
    Style := Style or WS_POPUP;
end;

function TToolDockForm.CanResize(var NewWidth, NewHeight: Integer): Boolean;
var
  W, H, NcW, NcH: Integer;
begin
  Result := True;
  if FUpdatingSize or (FSizingOrientation = soNone) or (DockClientCount = 0) or
    (NewWidth = Width) and (NewHeight = Height) then Exit;
  W := NewWidth;
  H := NewHeight;
  case FSizingOrientation of
    soHorizontal: Inc(H, FSizingAdjustH);
    soVertical: Inc(W, FSizingAdjustW);
    soNone: Exit;
  else
    Result := False;
    Exit;
  end;
  FPrevWidth := Width;
  FPrevHeight := Height;
  with DockClients[0] do
  begin
    NcW := Self.Width - Width;
    NcH := Self.Height - Height;
    FUpdatingSize := True;
    try
      SetBounds(Left, Top, W - NcW, H - NcH);
    finally
      FUpdatingSize := False;
    end;
    NewWidth := Width + NcW;
    NewHeight := Height + NcH;
  end;
  Result := (Width <> NewWidth) or (Height <> NewHeight);
end;

procedure TToolDockForm.DoAddDockClient(Client: TControl; const ARect: TRect);
begin
  inherited DoAddDockClient(Client, ARect);
  Client.Align := alNone;
  AutoSize := True;
end;

procedure TToolDockForm.WMNCCreate(var Message: TWMNCCreate);

  procedure ModifySystemMenu;
  var
    SysMenu: HMENU;
  begin
    if (BorderStyle <> bsNone) and (biSystemMenu in BorderIcons) and
      (FormStyle <> fsMDIChild) then
    begin
      { Show only the Make the system menu look like a dialog which has only Move and Close }
      SysMenu := GetSystemMenu(Handle, False);
      DeleteMenu(SysMenu, SC_TASKLIST, MF_BYCOMMAND);
      DeleteMenu(SysMenu, SC_MAXIMIZE, MF_BYCOMMAND);
      DeleteMenu(SysMenu, SC_MINIMIZE, MF_BYCOMMAND);
      DeleteMenu(SysMenu, SC_RESTORE, MF_BYCOMMAND);
    end;
  end;

begin
  inherited;
  if not (csDesigning in ComponentState) then ModifySystemMenu;
end;

procedure TToolDockForm.WMNCHitTest(var Message: TWMNCHitTest);
var
  Bounds: TRect;
  CX, CY: Integer;
begin
  inherited;
  Bounds := BoundsRect;
  CX := GetSystemMetrics(SM_CXFRAME);
  CY := GetSystemMetrics(SM_CYFRAME);
  InflateRect(Bounds, -CX, -CY);
  with Message do
    case Result of
      HTTOPLEFT:
        if YPos < Bounds.Top then
          Result := HTTOP
        else
          Result := HTLEFT;
      HTTOPRIGHT:
        if YPos < Bounds.Top then
          Result := HTTOP
        else
          Result := HTRIGHT;
      HTCLIENT: Result := HTCAPTION;
      HTBOTTOMLEFT:
        if YPos > Bounds.Bottom then
          Result := HTBOTTOM
        else
          Result := HTLEFT;
      HTGROWBOX, HTBOTTOMRIGHT:
        if YPos > Bounds.Bottom then
          Result := HTBOTTOM
        else
          Result := HTRIGHT;
    end;
end;

procedure TToolDockForm.WMNCLButtonDown(var Message: TWMNCLButtonDown);
begin
  FSizingOrientation := soNone;
  case Message.HitTest of
    HTLEFT, HTRIGHT: FSizingOrientation := soHorizontal;
    HTTOP, HTBOTTOM: FSizingOrientation := soVertical;
  end;
  inherited;
end;

procedure TToolDockForm.WMSize(var Message: TWMSize);
begin
  inherited;
  case FSizingOrientation of
    soHorizontal: Inc(FSizingAdjustH, Height - FPrevHeight);
    soVertical: Inc(FSizingAdjustW, Width - FPrevWidth);
  end;
end;

procedure TToolDockForm.WMSysCommand(var Message: TWMSysCommand);
begin
  if Message.CmdType and $FFF0 = SC_SIZE then
  begin
    FSizingAdjustW := 0;
    FSizingAdjustH := 0;
  end;
  inherited;
  FSizingOrientation := soNone;
end;

end.
