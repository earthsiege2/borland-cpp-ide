//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//
// Example paint program
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/dc.h>
#include <owl/gdiobjec.h>
#include <owl/decframe.h>
#include <owl/chooseco.h>
#include <owl/choosefo.h>
#include <owl/opensave.h>
#include <owl/printdia.h>
#include <owl/scroller.h>
#include <owl/controlb.h>
#include <owl/floatfra.h>
#include <owl/toolbox.h>
#include <owl/buttonga.h>
#include <owl/editfile.rh>
#include <stdio.h>
#include <dir.h>
#include "paint.rh"
#include "dibattr.h"

DIAG_DEFINE_GROUP(PaintDrw,1,0);  // drawing tracing (set level to 1 for mouse)
DIAG_DEFINE_GROUP(PaintCmd,1,0);  // command tracing

//
// Build options
//
//#define USE_LINEBAR     // comment out for line gadgets instead of line bar
#define USE_TOOLBAR       // comment out for floating tool & line palettes
#define PARALLEL_PEN      // to enable parallel line drawing with pen tool

const int DefWidth  = 640;
const int DefHeight = 480;
      int DefNColors= 0;        // fill in with screen device info
const int DefPenSize= 3;
const TColor DefPalette[] = {
  0x000000L, 0xFFFFFFL, 0x7F7F7FL, 0xC0C0C0L,
  0x00007FL, 0x007F00L, 0x007F7FL, 0x7F0000L, 0x7F007FL, 0x7F7F00L,
  0x0000FFL, 0x00FF00L, 0x00FFFFL, 0xFF0000L, 0xFF00FFL, 0xFFFF00L,
};

const int CM_TOOL   = 300;
const int CM_LINE   = 400;
const int ToolCount = 6;

const int ID_CANVAS = 101;
const int ID_PALETTE= 102;

#if defined(USE_LINEBAR)
const int LineCount = 8;
const int LineBarWidth = LineCount * 4 + 6 + (1 + 2 + 3 + 4 + 5 + 7 + 9 + 12);
const int LineWidth[LineCount] = { 1, 2, 3, 4, 5, 7, 9, 12 };
#endif


//----------------------------------------------------------------------------

class TDrawTool;

//
//
//
struct TState {
    TDrawTool*  DrawTool;
    TDC*        DC;
    TPalette*   Palette;
    TDib*       Dib;
    TBitmap*    Bitmap;
    int         PenSize;
    int         FgColor;
    int         BgColor;
    string      Name;
    string      Title;
    bool        Modified;
};

//
//
//
class TDrawTool {
  public:
    TDrawTool(const char* name);

    void      MouseDown(TWindow& window, const TPoint& point, TState* state);
    void      MouseMove(const TPoint& Point);
    void      MouseUp();

    const char*  GetName() {return Name;}

  protected:
    virtual void DrawBegin(const TPoint& point) {}
    virtual void DrawTo(const TPoint& point) {}
    virtual void DrawEnd() {}
    virtual bool UsesPenOnly() {return false;}

    TCursor*     Cursor;
    TIcon*       Icon;
    TState*      State;
    TWindow*     Window;
    TPen*        Pen;
    TBrush*      Brush;
    TDC*         DC;
    TPoint       LastPoint;
    TRect        Bounds;

  private:
    const char*  Name;
};

//
//
//
class TPenTool : public TDrawTool {
  public:
    TPenTool(const char* name) : TDrawTool(name) {}

  protected:
    virtual void DrawBegin(const TPoint& point);
    virtual void DrawTo(const TPoint& point);
    virtual void DrawEnd();
    virtual bool UsesPenOnly() {return true;}

#if defined(PARALLEL_PEN)
    TPalette*       TmpPalette;
#endif
};

//
//
//
class TFillTool : public TDrawTool {
  public:
    TFillTool(const char* name) : TDrawTool(name) {}
  protected:
    virtual void    DrawBegin(const TPoint& point);
};

class TBoxTool : public TDrawTool {
  public:
    TBoxTool(const char* name, bool filled)
             : TDrawTool(name), Filled(filled) {}

  protected:
    virtual void    DrawBegin(const TPoint& point);
    virtual void    DrawTo(const TPoint& point);
    virtual void    DrawEnd();
    virtual void    DrawObject(TDC& dc) {}

  protected:
    bool        Filled;
    int         X1;
    int         Y1;
    int         X2;
    int         Y2;
};

class TRectTool : public TBoxTool {
  public:
    TRectTool(const char* name, bool filled) : TBoxTool(name, filled) {}
  protected:
    virtual void DrawObject(TDC& dc);
};

class TEllipseTool : public TBoxTool {
  public:
    TEllipseTool(const char* name, bool filled) : TBoxTool(name, filled) {}
  protected:
    virtual void DrawObject(TDC& dc);
};

//----------------------------------------------------------------------------

class TPaletteWindow : public TWindow {
  public:
    TPaletteWindow(TWindow* parent, TState* state);
    void         SelectColor(TPoint& point, int& color);

  protected:
    void         Paint(TDC&, bool, TRect&);

    void         EvSize(UINT, TSize&);
    void         EvLButtonDown(UINT modKeys, TPoint& point);
    void         EvLButtonDblClk(UINT modKeys, TPoint&);
    void         EvRButtonDown(UINT modKeys, TPoint& point);
    void         EvRButtonDblClk(UINT modKeys, TPoint& point);
    LRESULT      EvSetRGB(TParam1, TParam2);

  private:
    TState*      State;
    bool         Horz;
    int          Cx;      // Count of panes in the X direction
    int          Cy;      // Count of panes in the Y direction
    int          Dx;      // Size of a pane in the X direction
    int          Dy;      // Size of a pane in the Y direction

  DECLARE_RESPONSE_TABLE(TPaletteWindow);
};

DEFINE_RESPONSE_TABLE1(TPaletteWindow, TWindow)
  EV_WM_SIZE,
  EV_WM_LBUTTONDOWN,
  EV_WM_LBUTTONDBLCLK,
  EV_WM_RBUTTONDOWN,
  EV_WM_RBUTTONDBLCLK,
  EV_REGISTERED(SETRGBSTRING, EvSetRGB),
END_RESPONSE_TABLE;

//----------------------------------------------------------------------------

//
// A slightly customized floating frame for use as our tool & style button
// palettes.
//
class TButtonPalette : public TFloatingFrame {
  public:
    TButtonPalette(TWindow*        parent,
                   char*           title = 0,
                   TWindow*        clientWnd = 0,
                   TModule*        module = 0);

  private:
    void SetupWindow();
    void CleanupWindow();
    void EvClose();

  DECLARE_RESPONSE_TABLE(TButtonPalette);
};

DEFINE_RESPONSE_TABLE1(TButtonPalette, TFloatingFrame)
  EV_WM_CLOSE,
END_RESPONSE_TABLE;

TButtonPalette::TButtonPalette(TWindow* parent, char* title,
                               TWindow* clientWnd, TModule* module)
:
  TFloatingFrame(parent, title, clientWnd, true, DefaultCaptionHeight, true,
                 module)
{
}

//
// Supply a reasonable startup position relative to our Parent (owner actually)
//
void
TButtonPalette::SetupWindow()
{
  TFloatingFrame::SetupWindow();

  if (Attr.X < 0 || Attr.Y < 0) {
    TRect parentRect;
    GetParentO()->GetWindowRect(parentRect);
    SetWindowPos(0, parentRect.left+10, parentRect.top+10, 0, 0,
                 SWP_NOSIZE | SWP_NOZORDER);
  }
}

//
// Remember latest position when we are destroyed, so we can reappear in the
// same place when re-enabled.
//
void
TButtonPalette::CleanupWindow()
{
  TRect rect;
  GetWindowRect(rect);
  Attr.X = rect.left;
  Attr.Y = rect.top;

  TFloatingFrame::CleanupWindow();
}

//
// Override EvClose to keep TWindow from having us deleted. We want to keep the
// OWL object around even when the window is destroyed.
//
void
TButtonPalette::EvClose()
{
  CloseWindow();
}

//----------------------------------------------------------------------------

#if defined(USE_LINEBAR)
class TLineBar : public TWindow {
  public:
    TLineBar(TWindow* parent, TState* state);

    void         Paint(TDC&, bool, TRect&);
    void         EvLButtonDown(UINT modKeys, TPoint& point);

  private:
    TState*     State;
    void        Notch(TDC& dc, int x, int w, int y, int dy);

  DECLARE_RESPONSE_TABLE(TLineBar);
};

DEFINE_RESPONSE_TABLE1(TLineBar, TWindow)
  EV_WM_LBUTTONDOWN,
END_RESPONSE_TABLE;
#endif

//----------------------------------------------------------------------------

class TCanvas : public TWindow {
  public:
    TCanvas();
   ~TCanvas();

    TState       State;

  protected:
    // Override TWindow virtuals
    //
    void         SetupWindow();
    bool         CanClose();

    bool         AbandonOk();
    void         SetupDib(TDib* dib, const char* fileName, const char* fileTitle);
    void         NewDib(int width, int height, int nColors);
    void         OpenDib(const char* fileName, const char* fileTitle);
    bool         SaveDib(const char* fileName);

    void         UpdateCaption();
    void         AdjustScroller();
    void         Paint(TDC&, bool, TRect&);

    void         EvSize(UINT, TSize&);
    void         EvLButtonDown(UINT modKeys, TPoint& point);
    void         EvLButtonUp(UINT modKeys, TPoint& point);
    void         EvMouseMove(UINT modKeys, TPoint& point);
    void         EvDropFiles(TDropInfo dropInfo);

    void         CmFileNew();
    void         CmFileOpen();
    void         CmFileSave();
    void         CmFileSaveAs();
    void         CmFilePrint();
    void         CmFilePrintSetup();

    void         CmViewTools();
    void         CeViewTools(TCommandEnabler& ce);
    void         CmViewLines();
    void         CeViewLines(TCommandEnabler& ce);

    void         CmTool(TParam1);
    void         CmLine(TParam1);

    TPrintDialog::TData PrintData;

  private:
    bool         Drawing;
    TDrawTool*   Tools[ToolCount];

    TButtonPalette* ToolsPal;
    TButtonPalette* LinesPal;

  DECLARE_RESPONSE_TABLE(TCanvas);
};

DEFINE_RESPONSE_TABLE1(TCanvas, TWindow)
  EV_WM_SIZE,
  EV_WM_LBUTTONDOWN,
  EV_WM_LBUTTONUP,
  EV_WM_MOUSEMOVE,
  EV_WM_DROPFILES,
  EV_COMMAND_AND_ID(CM_TOOL+0, CmTool),
  EV_COMMAND_AND_ID(CM_TOOL+1, CmTool),
  EV_COMMAND_AND_ID(CM_TOOL+2, CmTool),
  EV_COMMAND_AND_ID(CM_TOOL+3, CmTool),
  EV_COMMAND_AND_ID(CM_TOOL+4, CmTool),
  EV_COMMAND_AND_ID(CM_TOOL+5, CmTool),
  EV_COMMAND_AND_ID(CM_LINE+1, CmLine),
  EV_COMMAND_AND_ID(CM_LINE+3, CmLine),
  EV_COMMAND_AND_ID(CM_LINE+5, CmLine),
  EV_COMMAND_AND_ID(CM_LINE+7, CmLine),
  EV_COMMAND_AND_ID(CM_LINE+9, CmLine),
  EV_COMMAND_AND_ID(CM_LINE+11, CmLine),
  EV_COMMAND(CM_FILENEW, CmFileNew),
  EV_COMMAND(CM_FILEOPEN, CmFileOpen),
  EV_COMMAND(CM_FILESAVE, CmFileSave),
  EV_COMMAND(CM_FILESAVEAS, CmFileSaveAs),
  EV_COMMAND(CM_FILEPRINT, CmFilePrint),
  EV_COMMAND(CM_FILEPRINTERSETUP, CmFilePrintSetup),
  EV_COMMAND(CM_VIEWTOOLS, CmViewTools),
  EV_COMMAND_ENABLE(CM_VIEWTOOLS, CeViewTools),
  EV_COMMAND(CM_VIEWLINES, CmViewLines),
  EV_COMMAND_ENABLE(CM_VIEWLINES, CeViewLines),
END_RESPONSE_TABLE;

// --------------- TDrawTool ------------------------

TDrawTool::TDrawTool(const char* name)
:
  State(0), Window(0), Pen(0), Brush(0), DC(0), Name(name)
{
}

void
TDrawTool::MouseDown(TWindow& window, const TPoint& point, TState* state)
{
  TRACEX(PaintDrw,0,"Draw " << GetName() <<
    " started at (" << point.x << "," << point.y << ")");
  Window = &window;
  State = state;
  Window->SetCapture();

  DC = new TClientDC(window);

  //
  if (UsesPenOnly()) {
    Pen = new TPen(TColor(State->FgColor), State->PenSize);
  }
  else {
    Brush = new TBrush(TColor(State->FgColor));
    Pen = new TPen(TColor(State->BgColor), State->PenSize);
  }

  State->DC->SelectObject(*State->Palette);
  State->DC->RealizePalette();
  State->DC->SelectObject(*Pen);
  if (Brush)
    State->DC->SelectObject(*Brush);

  LastPoint = point;
  Bounds = TRect(point, point);
  DrawBegin(point);
}

void
TDrawTool::MouseMove(const TPoint& point)
{
  TRACEX(PaintDrw,1,"Draw " << GetName() <<
    " extends to (" << point.x << "," << point.y << ")");
  Bounds |= TRect(point.x, point.y, point.x, point.y);
  DrawTo(point);
  LastPoint = point;
}

void
TDrawTool::MouseUp()
{
  TRACEX(PaintDrw,1,"Draw " << GetName() << " finished");
  DrawEnd();

  Window->ReleaseCapture();
  State->DC->RestoreObjects();

  delete Brush; Brush = 0;
  delete Pen; Pen = 0;
  delete DC; DC = 0;

  State->Modified = true;
  Window->InvalidateRect(Bounds.
              InflatedBy((State->PenSize+1)/2,(State->PenSize+1)/2), false);
  Window->UpdateWindow();
}

// --------------- TPenTool ------------------------

void
TPenTool::DrawBegin(const TPoint& point)
{
  State->DC->MoveTo(point);

  // Do parallel update onto screen
  //
#if defined(PARALLEL_PEN)
  // can't select a palette into to different device DCs
  TmpPalette = new TPalette(*State->Dib);
  DC->IntersectClipRect(TRect(TPoint(0,0), State->Dib->Size()));
  DC->SelectObject(*TmpPalette);
  DC->RealizePalette();

  DC->SelectObject(*Pen);
  DC->MoveTo(point);
#endif
}

void
TPenTool::DrawTo(const TPoint& point)
{
  State->DC->LineTo(point);
#if defined(PARALLEL_PEN)
  DC->LineTo(point);
#else
  Window->InvalidateRect(TRect(LastPoint, point).Normalized().
                 InflatedBy((State->PenSize+1)/2,(State->PenSize+1)/2),false);
  Window->UpdateWindow();
#endif
}

void
TPenTool::DrawEnd()
{
  State->DC->RestorePen();
#if defined(PARALLEL_PEN)
  DC->RestorePen();
  delete TmpPalette; TmpPalette = 0;
#endif
}

// --------------- TFillTool ------------------------

void
TFillTool::DrawBegin(const TPoint& point)
{
  TBrush fgBrush(State->FgColor);
  State->DC->SelectObject(fgBrush);
  TColor surfaceColor(State->DC->GetPixel(point));
  State->DC->ExtFloodFill(point, surfaceColor, FLOODFILLSURFACE);
  Bounds = Window->GetClientRect();
  State->DC->RestoreBrush();
}

// --------------- TBoxTool ------------------------

void
TBoxTool::DrawBegin(const TPoint& point)
{
  X1 = X2 = point.x;
  Y1 = Y2 = point.y;
  DC->SelectStockObject(BLACK_PEN);
  DC->SelectStockObject(NULL_BRUSH);
  DC->SetROP2(R2_NOT);
  DrawObject(*DC);
}

void
TBoxTool::DrawTo(const TPoint& point)
{
  DrawObject(*DC);
  X2 = point.x;
  Y2 = point.y;
  DrawObject(*DC);
}

void
TBoxTool::DrawEnd()
{
  DrawObject(*DC);
  DC->SetROP2(R2_COPYPEN);
  State->DC->SelectObject(*Pen);
  if (Filled)
    State->DC->SelectObject(*Brush);
  else
    State->DC->SelectStockObject(NULL_BRUSH);
  DrawObject(*State->DC);
}

// --------------- TRectTool ------------------------

void
TRectTool::DrawObject(TDC& dc)
{
  dc.Rectangle(X1, Y1, X2, Y2);
}

// --------------- TEllipseTool ------------------------

void
TEllipseTool::DrawObject(TDC& dc)
{
  dc.Ellipse(X1, Y1, X2, Y2);
}

// --------------- TPaletteWindow ------------------------

TPaletteWindow::TPaletteWindow(TWindow* parent, TState* state)
  : TWindow(parent),
    State(state)
{
  Attr.Style |= WS_BORDER;
  Attr.W = 50;
  Attr.H = 50;
  Attr.Id = ID_PALETTE;
}

void
TPaletteWindow::EvSize(UINT, TSize&)
{
  TRect rect = GetClientRect();
  Horz = true;  // Location==Top || Location==Bottom;
  Cx = (Horz ? 17 : 3);
  Cy = (Horz ? 3 : 17);
  Dx = rect.right / Cx;
  Dy = rect.bottom / Cy;
  if (Horz)
    Cx--;
  else
    Cy--;
  Invalidate(false);
}

void
TPaletteWindow::Paint(TDC& dc, bool, TRect&)
{
  dc.SelectObject(*State->Palette);
  dc.RealizePalette();

  TRect rect = GetClientRect();

  dc.SelectStockObject(BLACK_PEN);

  // Paint color selection cells, each with a black frame
  //
  for (int i = 0; i < 16; i++)
    for (int j = 0; j < 3; j++) {
      TBrush brush(TColor(j*16+i));
      dc.SelectObject(brush);
      TPoint p = Horz ? TPoint(i*Dx, j*Dy) : TPoint(j*Dx, i*Dy);
      dc.Rectangle(p, TSize(Dx+1, Dy+1));
      dc.RestoreBrush();
    }

  // Paint fore & back color display, frame first
  //
  dc.SelectStockObject(NULL_BRUSH);
  TPoint p = Horz ? TPoint(Dx*16, 0) : TPoint(0, Dy*16);
  dc.Rectangle(p, rect.BottomRight());

  TPen pen(TColor(State->BgColor), 5);
  dc.SelectObject(pen);
  TBrush brush(TColor(State->FgColor));
  dc.SelectObject(brush);
  p += TSize(3,3);
  dc.Rectangle(p, TPoint(rect.right-3, rect.bottom-3));
}

void
TPaletteWindow::SelectColor(TPoint& point, int& color)
{
  point.x /= Dx;
  point.y /= Dy;
  if (point.x < Cx && point.y < Cy) {
    int newColor = Horz ? point.x + point.y*Cx : point.x*Cy + point.y;
    if (color != newColor) {
      TColor c = State->Dib->GetColor(newColor);

      InvalidateRect(Horz ? TRect(TPoint(Dx*Cx, 0), GetClientRect().BottomRight()) :
                            TRect(TPoint(0, Dy*Cy), GetClientRect().BottomRight()),
                     false);
      color = newColor;
    }
  }
}

void
TPaletteWindow::EvLButtonDown(UINT, TPoint& point)
{
  SelectColor(point, State->FgColor);
}

void
TPaletteWindow::EvLButtonDblClk(UINT, TPoint& point)
{
  static TColor CustColors[32];

  int editColor = -1;
  SelectColor(point, editColor);
  if (editColor < 0)
    return;
  TChooseColorDialog::TData choose;
  choose.Flags = CC_RGBINIT;
  PALETTEENTRY pe;
  State->Palette->GetPaletteEntry((WORD)editColor, pe);
  choose.Color = pe;
  choose.CustColors = CustColors;

  if (TChooseColorDialog(this, choose).Execute() == IDOK) {
    State->Dib->SetColor(editColor, choose.Color);
    delete State->Palette;
    State->Palette = new TPalette(*State->Dib);
    Invalidate(false);
    TWindow* canvas = GetParentO()->ChildWithId(ID_CANVAS);
    if (canvas && canvas->GetHandle())
      canvas->Invalidate(false);
  }
}

void
TPaletteWindow::EvRButtonDown(UINT, TPoint& point)
{
  SelectColor(point, State->BgColor);
}

void
TPaletteWindow::EvRButtonDblClk(UINT modKeys, TPoint& point)
{
  EvLButtonDblClk(modKeys, point);
}

LRESULT
TPaletteWindow::EvSetRGB(TParam1, TParam2)
{
  Invalidate(false);
  return 0;
}

#if defined(USE_LINEBAR)
// --------------- TLineBar ------------------------

TLineBar::TLineBar(TWindow* parent, TState* state)
  : TWindow(parent),
    State(state)
{
  Attr.Style |= WS_BORDER;
  Attr.W = 32;
  Attr.H = 32;
}

void
TLineBar::Notch(TDC& dc, int x, int w, int y, int dy)
{
  for (int l = 3; l >= 0; l--) {
    dc.MoveTo(TPoint(x + w / 2 - l, y));
    dc.LineTo(TPoint(x + w / 2 + l + 1, y));
    y += dy;
  }
}

void
TLineBar::Paint(TDC& dc, bool, TRect&)
{
  int x = 4;
  dc.SelectStockObject(WHITE_BRUSH);
  dc.PatBlt(TRect(0, 0, Attr.W, Attr.H));
  dc.SelectStockObject(BLACK_BRUSH);
  for (int i = 0; i < LineCount; i++) {
    int w = LineWidth[i];
    dc.PatBlt(TRect(x, 5, x + w, 25));
    if (w == State->PenSize) {
      Notch(dc, x, w, 0, 1);
      Notch(dc, x, w, 29, -1);
    }
    x += w + 4;
  }
}

void
TLineBar::EvLButtonDown(UINT, TPoint& point)
{
  int x = 2;
  for (int i = 0; i < LineCount; i++) {
    int w = LineWidth[i];
    if (point.x >= x && point.x < x+w+4) {
      TRACEX(PaintCmd,0,"Width = " << w);
      State->PenSize = w;
      Invalidate(false);
      return;
    }
    x += w + 4;
  }
}
#endif

// --------------- TCanvas ------------------------

TCanvas::TCanvas()
:
  TWindow(0, 0, 0),
  Drawing(false)
{
  State.DrawTool = 0;
  State.Dib = 0;
  State.Bitmap = 0;
  State.DC = 0;
  State.Palette = 0;
  State.PenSize = DefPenSize;
  State.FgColor = 0;
  State.BgColor = 1;
  State.Name = State.Title = "";

  Scroller = 0;

  Tools[0] = new TPenTool("Pen");
  Tools[1] = new TFillTool("Fill");
  Tools[2] = new TRectTool("Rect", false);
  Tools[3] = new TRectTool("FillRect", true);
  Tools[4] = new TEllipseTool("Ellipse", false);
  Tools[5] = new TEllipseTool("FillEllipse", true);
  State.DrawTool = Tools[0];

  Attr.Id = ID_CANVAS;

  ToolsPal = LinesPal = 0;
  
  // Set transparent background to skip EvEraseBkgnd & erase during paint
  //
  SetBkgndColor(TColor::Transparent);
}

TCanvas::~TCanvas()
{
  delete State.DC;
  delete State.Palette;
  delete State.Dib;
  delete State.Bitmap;

  for (int i = 0; i < ToolCount; i++)
    delete Tools[i];
}

void
TCanvas::SetupWindow()
{
  TWindow::SetupWindow();
  NewDib(DefWidth, DefHeight, DefNColors);
  DragAcceptFiles(true);

  // Construct the toolboxes if selected.
  // Could Create() them here, or just wait for the menu selection to create
  // them
  //
#if !defined(USE_TOOLBAR)
  TToolBox* tb = new TToolBox(GetParentO());
  tb->Insert(*new TButtonGadget(CM_TOOL+0, CM_TOOL+0, TButtonGadget::Exclusive,
                                true, TButtonGadget::Down));
  tb->Insert(*new TButtonGadget(CM_TOOL+1, CM_TOOL+1, TButtonGadget::Exclusive, true));
  tb->Insert(*new TButtonGadget(CM_TOOL+2, CM_TOOL+2, TButtonGadget::Exclusive, true));
  tb->Insert(*new TButtonGadget(CM_TOOL+3, CM_TOOL+3, TButtonGadget::Exclusive, true));
  tb->Insert(*new TButtonGadget(CM_TOOL+4, CM_TOOL+4, TButtonGadget::Exclusive, true));
  tb->Insert(*new TButtonGadget(CM_TOOL+5, CM_TOOL+5, TButtonGadget::Exclusive, true));
  ToolsPal = new TButtonPalette(this, "", tb);

  tb = new TToolBox(GetParentO());
  tb->Insert(*new TButtonGadget(CM_LINE+1, CM_LINE+1, TButtonGadget::Exclusive,
                                true, TButtonGadget::Down));
  tb->Insert(*new TButtonGadget(CM_LINE+3, CM_LINE+3, TButtonGadget::Exclusive, true));
  tb->Insert(*new TButtonGadget(CM_LINE+5, CM_LINE+5, TButtonGadget::Exclusive, true));
  tb->Insert(*new TButtonGadget(CM_LINE+7, CM_LINE+7, TButtonGadget::Exclusive, true));
  tb->Insert(*new TButtonGadget(CM_LINE+9, CM_LINE+9, TButtonGadget::Exclusive, true));
  tb->Insert(*new TButtonGadget(CM_LINE+11, CM_LINE+11, TButtonGadget::Exclusive, true));
  LinesPal = new TButtonPalette(this, "", tb);
#endif

  // A scroller on the client area would be nice...
  //
  //Scroller = new TScroller(this,1,1, State.Dib->Width(), State.Dib->Height());
  SetFocus();
}

bool
TCanvas::CanClose()
{
  return AbandonOk();
}

bool
TCanvas::AbandonOk()
{
  if (!State.Modified)
    return true;
  const char msgFrmt[] = "%s\nThe image has changed.\n\n"
                         "Do you want to save current changes?";
  char msg[sizeof(msgFrmt)+20];
  sprintf(msg, msgFrmt, State.Name.c_str());
  int resp = MessageBox(msg, GetApplication()->GetName(),
                        MB_ICONEXCLAMATION|MB_YESNOCANCEL);
  if (resp == IDYES)
    CmFileSave();

  return resp != IDCANCEL;
}

//
// Setup state info given a new dib. Assumes ownership of the dib.
//
void
TCanvas::SetupDib(TDib* dib, const char* name, const char* title)
{
  //
  // Make sure we can get the Dib DC and palette before we commit to this dib.
  // Revert to a DDB and a memory DC if we can't create a DIB DC.
  //
  TDC*      newDC;
  TBitmap*  newBM = 0;
  TPalette* newPalette;
  try {
    newDC = new TDibDC(*dib);
  }
  catch (TGdiObject::TXGdi&) {
    newDC = new TMemoryDC;
    newBM = new TBitmap(TScreenDC(), *dib);
    ((TMemoryDC*)newDC)->SelectObject(*newBM);
    newDC->SetDIBits(*newBM, *dib);
    if (dib->NumColors() > NColors(WORD(newBM->Planes()*newBM->BitsPixel())))
      MessageBox("Colors may have been lost during bitmap conversion.",
                 GetApplication()->GetName(), MB_ICONEXCLAMATION|MB_OK);
  }
  newPalette = new TPalette(*dib);
  delete State.DC;
  delete State.Palette;
  delete State.Dib;
  delete State.Bitmap;
  State.DC = newDC;
  State.Palette = newPalette;
  State.Dib = dib;
  State.Bitmap = newBM;

  State.Name = name;
  State.Title = title;
  State.Modified = false;
  UpdateCaption();
  AdjustScroller();
  TWindow* palette = GetParentO()->ChildWithId(ID_PALETTE);
  if (palette && palette->GetHandle())
    palette->Invalidate(false);
  Invalidate(false);
}

//
// Create a new dib & setup state info
//
void
TCanvas::NewDib(int width, int height, int nColors)
{
  // Construct the dib, catching any exptions that might occur & displaying a
  // warning
  //
  TDib* dib;
  try {
    dib = new TDib(width, height, nColors);
  }
  catch (TGdiObject::TXGdi& x) {
    MessageBox("Could Not Create DIB", GetApplication()->GetName(), MB_OK);
    return;
  }

  // Setup a nice palette
  //
  for (int i = 0; i < min(nColors, int(sizeof DefPalette/sizeof DefPalette[0])); i++)
    dib->SetColor(i, DefPalette[i]);

  SetupDib(dib, "", "(Untitled)");

  TBrush brush(TColor(State.BgColor));
  State.DC->SelectObject(*State.Palette);
  State.DC->RealizePalette();
  State.DC->SelectObject(brush);
  State.DC->PatBlt(TRect(TPoint(0,0), State.Dib->Size()));
  State.DC->RestoreObjects();
}

//
// Open a dib & setup state info given a dib filename & title
//
void
TCanvas::OpenDib(const char* fileName, const char* fileTitle)
{
  TDib* dib;
  try {
    dib = new TDib(fileName);
  }
  catch (TGdiObject::TXGdi& x) {
    MessageBox("Invalid Bitmap File", GetApplication()->GetName(), MB_OK);
    return;
  }

  SetupDib(dib, fileName, fileTitle);
}

bool
TCanvas::SaveDib(const char* fileName)
{
  if (State.Bitmap) {
    delete State.Dib;
    State.Dib = new TDib(*State.Bitmap, State.Palette);
  }
  if (State.Dib->WriteFile(fileName))
    return true;
  MessageBox("Disk error saving bitmap!", GetApplication()->GetName(), MB_OK);
  return false;
}

void
TCanvas::UpdateCaption()
{
  char captionBuffer[70];
  if (State.Dib)
    sprintf(captionBuffer, "%s - %s [%dx%dx%d]", GetApplication()->GetName(),
             (LPCSTR)State.Title.c_str(),
             State.Dib->Width(), State.Dib->Height(), State.Dib->NumColors());
  else
    sprintf(captionBuffer, "%s - (Bad Dib!)", GetApplication()->GetName());
  GetParentO()->SetCaption(captionBuffer);
}

void
TCanvas::AdjustScroller()
{
  if (!Scroller)
    return;

  TRect  clientRect = GetClientRect();

  // only show scrollbars when image is larger than
  // the client area and we are not stretching to fit.
  //
  TPoint range(Max(State.Dib->Width()-clientRect.Width(), 0),
               Max(State.Dib->Height()-clientRect.Height(), 0));
  Scroller->SetRange(range.x, range.y);
  Scroller->ScrollTo(0, 0);
  if (!GetUpdateRect(clientRect, false))
    Invalidate(false);
}

void
TCanvas::EvSize(UINT SizeType, TSize& Size)
{
  TWindow::EvSize(SizeType, Size);
  if (SizeType != SIZEICONIC)
    AdjustScroller();
}

void
TCanvas::Paint(TDC& dc, bool, TRect&)
{
  TRect drect(TPoint(0,0), State.Dib->Size());
  TRect crect = GetClientRect();
  if (Scroller)
    crect += TPoint((int)Scroller->XPos, (int)Scroller->YPos);

  // optimize this painting!
  //TRect prect(rect);
  //drect &= prect;
  dc.SelectObject(*State.Palette);
  dc.RealizePalette();

  // Blit the DDB or DIB from the working DC to the screen
  //
  if (State.Bitmap)
    dc.BitBlt(drect, *State.DC, TPoint(0,0));
  else
    dc.SetDIBitsToDevice(drect, TPoint(0,0), *State.Dib);

  // Paint around the canvas
  //
  TBrush bkBrush(TColor::SysAppWorkspace);  // or SysWindow
  dc.SelectObject(bkBrush);
  dc.PatBlt(TRect(drect.right, 0, crect.right, crect.bottom));
  dc.PatBlt(TRect(0, drect.bottom, crect.right, crect.bottom));

  dc.RestoreObjects();
}

void
TCanvas::EvLButtonDown(UINT modKeys, TPoint& point)
{
  TWindow::EvLButtonDown(modKeys, point);
  if (!Drawing) {
    Drawing = true;
    State.DrawTool->MouseDown(*this, point, &State);
  }
}

void
TCanvas::EvMouseMove(UINT, TPoint& point)
{
  if (Drawing)
    State.DrawTool->MouseMove(point);
}

void
TCanvas::EvLButtonUp(UINT, TPoint& point)
{
  if (Drawing) {
    State.DrawTool->MouseMove(point);
    State.DrawTool->MouseUp();
    Drawing = false;
  }
}

void
TCanvas::EvDropFiles(TDropInfo dropInfo)
{
  int totalNumberOfFiles = dropInfo.DragQueryFileCount();
  if (totalNumberOfFiles == 1 && AbandonOk()) {
    char filePath[MAXPATH+1];
    char fileTitle[MAXFILE];
    dropInfo.DragQueryFile(0, filePath, MAXPATH + 1);
    fnsplit(filePath, 0, 0, fileTitle, 0);
    OpenDib(filePath, fileTitle);
  }
  dropInfo.DragFinish();
}

void
TCanvas::CmTool(TParam1 toolCmd)
{
  int i = toolCmd - CM_TOOL;
  TRACEX(PaintCmd,0, "Tool = " << Tools[i]->GetName());
  State.DrawTool = Tools[i];

  SetCursor(GetModule(), toolCmd);
}

void
TCanvas::CmLine(TParam1 lineCmd)
{
  State.PenSize = lineCmd - CM_LINE;
}

void
TCanvas::CmFileNew()
{
  TRACEX(PaintCmd,0,"CmFileNew()");
  if (!AbandonOk())
    return;

  static int width = DefWidth;
  static int height = DefHeight;
  static int ncolors = DefNColors;
  if (TDibAttrDialog(this, width, height, ncolors).Execute() == IDOK)
    NewDib(width, height, ncolors);
}

void
TCanvas::CmFileOpen()
{
  TRACEX(PaintCmd,0,"CmFileOpen()");
  if (!AbandonOk())
    return;

  TOpenSaveDialog::TData data (
    OFN_HIDEREADONLY|OFN_FILEMUSTEXIST|OFN_NOREADONLYRETURN,
    "Bitmap Files (*.BMP)|*.bmp|",
    0,
    "",
    "BMP"
  );
  if (TFileOpenDialog(this, data).Execute() == IDOK) {
    char fileTitle[MAXPATH];
    TOpenSaveDialog::GetFileTitle(data.FileName, fileTitle, MAXPATH);
    OpenDib(data.FileName, fileTitle);
  }
}

void
TCanvas::CmFileSave()
{
  TRACEX(PaintCmd,0,"CmFileSave()");
  if (State.Modified) {
    if (!State.Name.length()) {
      CmFileSaveAs();
      return;
    }

    if (SaveDib(State.Name.c_str()))
      State.Modified = false;
  }
}

void
TCanvas::CmFileSaveAs()
{
  TRACEX(PaintCmd,0,"CmFileSaveAs()");
  TOpenSaveDialog::TData data (
    OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
    "Bitmap Files (*.BMP)|*.bmp|",
    0,
    "",
    "BMP"
  );
  if (TFileSaveDialog(this, data).Execute() == IDOK) {
    if (SaveDib(data.FileName)) {
      State.Name = data.FileName;
      State.Modified = false;
      char fileTitle[MAXPATH];
      TOpenSaveDialog::GetFileTitle(data.FileName, fileTitle, MAXPATH);
      State.Title = fileTitle;
      UpdateCaption();
    }
  }
}

void
TCanvas::CmFilePrint()
{
  TRACEX(PaintCmd, 0, "CmFilePrint()");
  PrintData.Flags &= ~PD_PRINTSETUP;
  if (TPrintDialog(this, PrintData).Execute() == IDOK) {
    MessageBox("No File|Print yet...", GetApplication()->GetName(), MB_OK);
  }
}

void
TCanvas::CmFilePrintSetup()
{
  TRACEX(PaintCmd, 0, "CmFilePrintSetup()");
  PrintData.Flags |= PD_PRINTSETUP;
  TPrintDialog(this, PrintData, 0).Execute();
}

void
TCanvas::CmViewTools()
{
  if (ToolsPal)
    if (ToolsPal->GetHandle())
      ToolsPal->Destroy();
    else
      ToolsPal->Create();
}

void
TCanvas::CeViewTools(TCommandEnabler& ce)
{
  if (!ToolsPal)
    ce.Enable(false);
  else
    ce.SetCheck(ToolsPal->GetHandle() ?
                TCommandEnabler::Checked : TCommandEnabler::Unchecked);
}

void
TCanvas::CmViewLines()
{
  if (LinesPal)
    if (LinesPal->GetHandle())
      LinesPal->Destroy();
    else
      LinesPal->Create();
}

void
TCanvas::CeViewLines(TCommandEnabler& ce)
{
  if (!LinesPal)
    ce.Enable(false);
  else
    ce.SetCheck(LinesPal->GetHandle() ?
                TCommandEnabler::Checked : TCommandEnabler::Unchecked);
}


//----------------------------------------------------------------------------

class TPaintApp : public TApplication {
  public:
    TPaintApp() : TApplication("OWL Paint") {}
    void InitMainWindow();
};

void TPaintApp::InitMainWindow()
{
  TCanvas& client = *new TCanvas;
  TDecoratedFrame* frame = new TDecoratedFrame(0, Name, &client);

#if defined(USE_TOOLBAR)
  TControlBar* cb = new TControlBar(frame);
  cb->Insert(*new TButtonGadget(CM_TOOL+0, CM_TOOL+0, TButtonGadget::Exclusive,
                                false, TButtonGadget::Down));
  cb->Insert(*new TButtonGadget(CM_TOOL+1, CM_TOOL+1, TButtonGadget::Exclusive));
  cb->Insert(*new TButtonGadget(CM_TOOL+2, CM_TOOL+2, TButtonGadget::Exclusive));
  cb->Insert(*new TButtonGadget(CM_TOOL+3, CM_TOOL+3, TButtonGadget::Exclusive));
  cb->Insert(*new TButtonGadget(CM_TOOL+4, CM_TOOL+4, TButtonGadget::Exclusive));
  cb->Insert(*new TButtonGadget(CM_TOOL+5, CM_TOOL+5, TButtonGadget::Exclusive));
#if !defined(USE_LINEBAR)
  cb->Insert(*new TSeparatorGadget);
  cb->Insert(*new TButtonGadget(CM_LINE+1, CM_LINE+1, TButtonGadget::Exclusive));
  cb->Insert(*new TButtonGadget(CM_LINE+3, CM_LINE+3, TButtonGadget::Exclusive,
                                false, TButtonGadget::Down));
  cb->Insert(*new TButtonGadget(CM_LINE+5, CM_LINE+5, TButtonGadget::Exclusive));
  cb->Insert(*new TButtonGadget(CM_LINE+7, CM_LINE+7, TButtonGadget::Exclusive));
  cb->Insert(*new TButtonGadget(CM_LINE+9, CM_LINE+9, TButtonGadget::Exclusive));
  cb->Insert(*new TButtonGadget(CM_LINE+11, CM_LINE+11, TButtonGadget::Exclusive));
#endif
  frame->Insert(*cb, TDecoratedFrame::Top);
#endif

  frame->Insert(*new TPaletteWindow(frame, &client.State), TDecoratedFrame::Bottom);
#if defined(USE_LINEBAR)
  frame->Insert(*new TLineBar(frame, &client.State), TDecoratedFrame::Bottom);
#endif

  frame->AssignMenu("PaintMenu");
  frame->Attr.AccelTable = "PaintAccels";
  frame->SetIcon(this, "PaintIcon");

  SetMainWindow(frame);
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  TScreenDC screenDC;
  DefNColors = (int)NColors(WORD(screenDC.GetDeviceCaps(BITSPIXEL)*screenDC.GetDeviceCaps(PLANES)));
  return TPaintApp().Run();
}
