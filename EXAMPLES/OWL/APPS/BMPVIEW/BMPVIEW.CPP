//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//
//   Example program that shows Dibs, Bitmaps and Palettes in a scrolling
//   Window. Also uses diagnostics to trace thru some routines
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/dc.h>
#include <owl/menu.h>
#include <owl/dibitmap.h>
#include <owl/framewin.h>
#include <owl/scroller.h>
#include <owl/opensave.h>
#include <owl/clipview.h>
#include <owl/inputdia.h>
#include <string.h>
#include <stdio.h>
#include <dir.h>
#include "bmpview.h"

DIAG_DEFINE_GROUP_INIT(OWL_INI, BmpView, 1, 0);

#define USE_DDB     // Use a DDB, else blts the DIB directly to the screen
//#define PAINT_ICON  // define to paint the icon from the bitmap

static const char AppName[] = "BitmapView";

//
// class TWaitCursor
// ~~~~~ ~~~~~~~~~~~
// General wait cursor wrapper. Changes cursor to an hourglass during its scope
//
class TWaitCursor {
  public:
    TWaitCursor()
    :
      HCursor(::SetCursor(::LoadCursor(0, IDC_WAIT)))
    {
    }

   ~TWaitCursor()
    {
      ::SetCursor(HCursor);
    }
  private:
    HCURSOR HCursor;
};

//
// class TBmpViewWindow
// ~~~~~ ~~~~~~~~~~~~~~
// A bitmap displaying window derived from TClipboardViewer to
// facilitate receiving of clipboard change notifications. Could mix it in if
// an additional base was desired.
//
class _USERCLASS TBmpViewWindow : virtual public TWindow,
                                          public TClipboardViewer {
  public:
    bool      ScreenPalettized;  // True if the screen is a palettized device
    TPalette* DefPalette;        // Palette to use for DIBs w/o color tables
    TBrush*   BkgndBrush;        // Window background brush
    long      Rop;               // Bitmap -> screen raster op

    bool      Fit;               // Stretch bitmap to fit?
    bool      AutoClipView;      // Clipboard auto-display mode
    bool      PaintFromDDB;      // Paint DDB to screen, vs. DIB
    bool      PaintIcon;         // Paint icon from DIB, vs. from resource

    string    FileName;
    TDib*     Dib;
    TBitmap*  Bitmap;
    HBITMAP   MemHandle;
    TPalette* Palette;
    int       PixelWidth;
    int       PixelHeight;
    uint16    Colors;

    TBmpViewWindow();
   ~TBmpViewWindow();

  protected:
    void      CmFileOpen();
    void      CmRead1();
    void      CmRead2();
    void      CmReadBad();
    void      CmMemHandle();
    void      CmMemHandleRefresh();
    void      CmCopy();
    void      CmPaste();
    void      CmFit();
    void      CmAutoClipView();
    void      CmPaintFromDDB();
    void      CmPaintIcon();
    void      CeCopy(TCommandEnabler& ce);
    void      CePaste(TCommandEnabler& ce);
    void      CeFit(TCommandEnabler& ce);
    void      CeAutoClipView(TCommandEnabler& ce);
    void      CePaintFromDDB(TCommandEnabler& ce);
    void      CePaintIcon(TCommandEnabler& ce);

    void      Paint(TDC&, bool erase, TRect&);
    void      EvSize(uint sizeType, TSize&);

    void      EvPaletteChanged(HWND hWndPalChg);
    bool      EvQueryNewPalette();
    void      EvDrawClipboard();
    void      EvDestroy();

    bool      UpdatePalette(bool alwaysRepaint);
    void      AdjustScroller();
    void      SetCaption(const char*);
    void      SetupFromDib(TDib* dib);
    bool      LoadBitmapFile(const char*);
    bool      LoadBitmapResource(uint16 resId);
    bool      LoadMemHandle(HBITMAP hBitmap);

  DECLARE_RESPONSE_TABLE(TBmpViewWindow);
};

DEFINE_RESPONSE_TABLE2(TBmpViewWindow, TClipboardViewer, TWindow)
  EV_COMMAND(CM_FILEOPEN, CmFileOpen),
  EV_COMMAND(CM_READ1, CmRead1),
  EV_COMMAND(CM_READ2, CmRead2),
  EV_COMMAND(CM_READBAD, CmReadBad),
  EV_COMMAND(CM_MEMHANDLE, CmMemHandle),
  EV_COMMAND(CM_MEMHANDLEREFRESH, CmMemHandleRefresh),
  EV_COMMAND(CM_EDITCOPY, CmCopy),
  EV_COMMAND(CM_EDITPASTE, CmPaste),
  EV_COMMAND(CM_FIT, CmFit),
  EV_COMMAND(CM_AUTOCLIPVIEW, CmAutoClipView),
  EV_COMMAND(CM_PAINTFROMDDB, CmPaintFromDDB),
  EV_COMMAND(CM_PAINTICON, CmPaintIcon),
  EV_COMMAND_ENABLE(CM_EDITCOPY, CeCopy),
  EV_COMMAND_ENABLE(CM_EDITPASTE, CePaste),
  EV_COMMAND_ENABLE(CM_FIT, CeFit),
  EV_COMMAND_ENABLE(CM_AUTOCLIPVIEW, CeAutoClipView),
  EV_COMMAND_ENABLE(CM_PAINTFROMDDB, CePaintFromDDB),
  EV_COMMAND_ENABLE(CM_PAINTICON, CePaintIcon),
  EV_WM_SIZE,
  EV_WM_PALETTECHANGED,
  EV_WM_QUERYNEWPALETTE,
  EV_WM_DRAWCLIPBOARD,
  EV_WM_DESTROY,
END_RESPONSE_TABLE;

//
// Constructor for a TBmpViewWindow, sets scroll styles and constructs
// the Scroller object.  Also sets the Rop based on whether the display
// is monochrome (two-color) or polychrome.
//
TBmpViewWindow::TBmpViewWindow()
:
  TWindow(0, 0, 0),
  TClipboardViewer()
{

  Attr.Style |= WS_BORDER | WS_VSCROLL | WS_HSCROLL;
  Attr.ExStyle |= WS_EX_CLIENTEDGE;

  BkgndBrush = new TBrush(TColor::SysWindow);
  Scroller = new TScroller(this, 1, 1, 200, 200);

  Fit = false;
  AutoClipView = false;
  PaintFromDDB = true;
  PaintIcon = false;

  Dib = 0;
  Bitmap = 0;
  MemHandle = 0;
  Palette = 0;

  // If the screen is a palettized device, then we'll need a halftone palette
  // for dibs with > 8 bpp
  //
  TScreenDC screenDC;
  if (screenDC.GetDeviceCaps(RASTERCAPS) & RC_PALETTE) {
    ScreenPalettized = true;
#if defined(BI_PLAT_WIN32)
    DefPalette = new THalftonePalette;
#else
    DefPalette = new TPalette((HPALETTE)::GetStockObject(DEFAULT_PALETTE));
#endif
  }
  else {
    ScreenPalettized = false;
    DefPalette = 0;
  }

  // Raster op to use when blitting to the screen
  //
  Rop = SRCCOPY;

  SetCaption(0);
  SetBkgndColor(TColor::Transparent);  // Don't pre-erase image background
}

//
//
//
TBmpViewWindow::~TBmpViewWindow()
{
  delete Bitmap;
  if (Palette != DefPalette)
    delete Palette;
  delete DefPalette;
  delete Dib;
  delete BkgndBrush;
}

//
// Build up a caption based on a filename, and set it into the title.
//
void
TBmpViewWindow::SetCaption(const char* name)
{
  FileName = name ? name : "untitled";

  if (Parent) {
#if 0 // Old title format
    string caption = string(GetApplication()->GetName()) + " - " + FileName;
#else
    string caption = FileName + " - " + GetApplication()->GetName();
#endif
    Parent->SetCaption(caption.c_str());
  }
}

//
// Make a metafile & put it on the clipboard.
// Make a copy of each of the objects & place the copies on the clipboard
//
void
TBmpViewWindow::CmCopy()
{
  TClipboard clipboard(*this);

  if (clipboard.EmptyClipboard()) {
    TMetaFileDC mfDC;
    mfDC.SetWindowExt(Dib->Size());
    mfDC.SetWindowOrg(0, 0);
    mfDC.SetDIBitsToDevice(TRect(0,0, PixelWidth, PixelHeight), TPoint(0,0), *Dib);
    TMetaFilePict mf(mfDC.Close(), AutoDelete);
    mf.ToClipboard(clipboard, MM_TEXT, TSize(PixelWidth, PixelHeight));

    if (Palette)
      TPalette(*Palette).ToClipboard(clipboard);
    TDib(*Dib).ToClipboard(clipboard);
    if (Bitmap)
      TBitmap(*Bitmap).ToClipboard(clipboard);
  }
}

void
TBmpViewWindow::CeCopy(TCommandEnabler& ce)
{
  ce.Enable(Dib != 0);
}

//
// When a user selects edit.paste, get the data from the clipboard. This
// routine prefers CF_META over CF_DIB over CF_BITMAP
//
void
TBmpViewWindow::CmPaste()
{
  TClipboard clipboard(*this);
  if (!clipboard)
    return;

  TPalette* newPal = 0;
  TDib*     newDib = 0;
  TBitmap*  newBitmap;

  // If there is a palette on the clipboard, get it & realize it
  //
  if (clipboard.IsClipboardFormatAvailable(CF_PALETTE)) {
    newPal = new TPalette(TPalette(clipboard));  // make a copy
    UpdatePalette(false);
  }

  // try DIB format 1st
  //
  if (clipboard.IsClipboardFormatAvailable(CF_DIB)) {
    newDib = new TDib(TDib(clipboard));        // make a copy
    newBitmap = new TBitmap(*newDib, newPal);  // newPal==0 is OK
  }
  // try metafile 2nd
  //
  else if (clipboard.IsClipboardFormatAvailable(CF_METAFILEPICT)) {
    if (!newPal)
      newPal = new TPalette((HPALETTE)GetStockObject(DEFAULT_PALETTE));
    newBitmap = new TBitmap(TMetaFilePict(clipboard), *newPal,
                            GetClientRect().Size());
  }
  // try bitmap (DDB) format 3rd
  //
  else if (clipboard.IsClipboardFormatAvailable(CF_BITMAP)) {
    newBitmap = new TBitmap(TBitmap(clipboard));     // make a copy
  }
  else
    return;  // Should never happen--this command is enabled by above tests

  // Got a bitmap & maybe more. Now keep it & setup things.
  //
  delete Bitmap;
  Bitmap = newBitmap;

  // Make a DIB from the bitmap if we didn't get one yet.
  //
  if (!newDib)
    newDib = new TDib(*newBitmap, newPal);
  delete Dib;
  Dib = newDib;

  // Either use the palette obtained above, or construct one from the
  // color table in the DIB
  //
  try {
    if (!newPal)
      newPal = new TPalette(*newDib);
  }
  catch (...) {
#if defined(BI_PLAT_WIN32)
    newPal = new TPalette(::CreateHalftonePalette(TScreenDC()), AutoDelete);
#else
    throw TXOwl("Cannot create palette from DIB");
#endif
//    newPal = new TPalette((HPALETTE)::GetStockObject(DEFAULT_PALETTE));
  }
  if (Palette != DefPalette)
    delete Palette;
  Palette = newPal;
  Palette->GetObject(Colors);

  PixelWidth  = Dib->Width();
  PixelHeight = Dib->Height();
  AdjustScroller();
  SetCaption("clipboard");

  // We'll paint the icon from the bitmap, or use the icon in the resource
  //
  if (PaintIcon)
    GetApplication()->GetMainWindow()->SetIcon(0, 0);
  else
    GetApplication()->GetMainWindow()->SetIcon(GetApplication(), GetApplication()->GetName());
}

//
//
//
void
TBmpViewWindow::CePaste(TCommandEnabler& ce)
{
  TClipboard clipboard(*this);
  ce.Enable(
    clipboard && (
      clipboard.IsClipboardFormatAvailable(CF_METAFILEPICT) ||
      clipboard.IsClipboardFormatAvailable(CF_DIB) ||
      clipboard.IsClipboardFormatAvailable(CF_BITMAP)
    )
  );
}

//
// If either of the "Read bitmap" menu items is selected, then we read
// the bitmap resource with the ID of the menu item...
//
void
TBmpViewWindow::CmRead1()
{
  if (LoadBitmapResource(CM_READ1))
    SetCaption("(Bitmap resource 1)");
}

//
//
//
void
TBmpViewWindow::CmRead2()
{
  if (LoadBitmapResource(CM_READ2))
    SetCaption("(Bitmap resource 2)");
}

void
TBmpViewWindow::CmReadBad()
{
  LoadBitmapFile("");   // force a failure for kicks
}

//
//
//
void
TBmpViewWindow::CmMemHandle()
{
  char buf[32];
  sprintf(buf, "%0X", MemHandle);
  if (TInputDialog(this, "Memory Bitmap", "Enter handle", buf, sizeof buf).Execute() == IDOK) {
    HBITMAP handle;
    sscanf(buf, "%x", &handle);
    LoadMemHandle(handle);
  }
}

//
// Reload the bitmaps from the user supplied bitmap handle
//
void
TBmpViewWindow::CmMemHandleRefresh()
{
  if (MemHandle)
    LoadMemHandle(MemHandle);
}

//
// Toggle Fit member variable & adjust scroller as needed
//
void
TBmpViewWindow::CmFit()
{
  Fit = !Fit;
  AdjustScroller();
}

//
// The fit menu item is checked if the Fit member is true
//
void
TBmpViewWindow::CeFit(TCommandEnabler& ce)
{
  ce.SetCheck(Fit ? TCommandEnabler::Checked : TCommandEnabler::Unchecked);
}

//
// Toggle AutoAutoClipView member variable
//
void
TBmpViewWindow::CmAutoClipView()
{
  AutoClipView = !AutoClipView;
}

//
// Check AutoClipView according to flag
//
void
TBmpViewWindow::CeAutoClipView(TCommandEnabler& ce)
{
  ce.SetCheck(AutoClipView ? TCommandEnabler::Checked : TCommandEnabler::Unchecked);
}

//
// Toggle PaintFromDDB member variable
//
void
TBmpViewWindow::CmPaintFromDDB()
{
  PaintFromDDB = !PaintFromDDB;
  Invalidate();
}

//
// Check AutoClipView according to flag
//
void
TBmpViewWindow::CePaintFromDDB(TCommandEnabler& ce)
{
  ce.SetCheck(PaintFromDDB ? TCommandEnabler::Checked : TCommandEnabler::Unchecked);
}

//
// Toggle PaintIcon member variable
//
void
TBmpViewWindow::CmPaintIcon()
{
  PaintIcon = !PaintIcon;
}

//
// Check AutoClipView according to flag
//
void
TBmpViewWindow::CePaintIcon(TCommandEnabler& ce)
{
  ce.SetCheck(PaintIcon ? TCommandEnabler::Checked : TCommandEnabler::Unchecked);
}

//
// If the the "Open..." menu item is selected, then we prompt the user
// for a new bitmap file.  If the user selects one and it is one that
// we can read, we display it in the window and change the window's
// caption to reflect the new bitmap file.
//
void
TBmpViewWindow::CmFileOpen()
{
  static TOpenSaveDialog::TData data (
    OFN_HIDEREADONLY|OFN_FILEMUSTEXIST|OFN_NOREADONLYRETURN,
    "Bitmap Files (*.BMP)|*.bmp|",
    0,
    "",
    "BMP"
  );
  if (TFileOpenDialog(this, data).Execute() == IDOK) {
    char fileTitle[MAXPATH];
    TOpenSaveDialog::GetFileTitle(data.FileName, fileTitle, MAXPATH);
    LoadBitmapFile(fileTitle);
    SetCaption(strlwr(fileTitle));
  }
}

//
// Adjust the Scroller range so that the the origin is the
// upper-most scrollable point and the corner is the
// bottom-most.
//
void
TBmpViewWindow::AdjustScroller()
{
  TRect  clientRect = GetClientRect();

  // Only show scrollbars when image is larger than
  // the client area and we are not stretching to fit.
  //
  if (Fit) {
    Scroller->SetRange(0, 0);
  }
  else {
    TPoint Range(Max(PixelWidth-clientRect.Width(), 0),
                 Max(PixelHeight-clientRect.Height(), 0));
    Scroller->SetRange(Range.x, Range.y);
  }
  Scroller->ScrollTo(0, 0);
  if (!GetUpdateRect(clientRect, false))
    Invalidate(false);
}

//
// Reset scroller range.
//
void
TBmpViewWindow::EvSize(uint SizeType, TSize& Size)
{
  TWindow::EvSize(SizeType, Size);
  if (SizeType != SIZEICONIC) {
    AdjustScroller();
    Invalidate(false);
  }
}

//
// Somebody changed the palette. If its not us, then we need to update.
//
void
TBmpViewWindow::EvPaletteChanged(HWND hWndPalChg)
{
  if (hWndPalChg != GetHandle())
    UpdatePalette(false);    // pass false to UpdateColors() instead of repaint
}

//
// We need to re-realize the logical palette each time we regain the input
// focus
//
bool
TBmpViewWindow::EvQueryNewPalette()
{
  return UpdatePalette(true);
}

//
//
//
void
TBmpViewWindow::EvDrawClipboard()
{
  if (TClipboardViewer::DoDrawClipboard() == esComplete)
    return;
  if (AutoClipView)
    CmPaste();
}

//
//
//
void
TBmpViewWindow::EvDestroy()
{
  if (TClipboardViewer::DoDestroy() == esComplete)
    return;
  TWindow::EvDestroy();
}

//
//
//
bool
TBmpViewWindow::UpdatePalette(bool alwaysRepaint)
{
  TRACEX(BmpView, 2, "Enter UpdatePalette()");
  if (ScreenPalettized && Palette) {
    TClientDC clientDC(*this);
#if defined(BI_PLAT_WIN16)
    Palette->UnrealizeObject();
#endif
    TRACEX(BmpView, 2, "UpdatePalette::Palette: " << hex << (uint)(HPALETTE)*Palette);
    clientDC.SelectObject(*Palette, true); 
    bool needsUpdate = clientDC.RealizePalette() > 0;
    if (alwaysRepaint || needsUpdate)
      Invalidate(false);
//    else if (needsUpdate)
//      clientDC.UpdateColors(); // can use this, but our painting is faster
    TRACEX(BmpView, 2, "Leave UpdatePalette(true)");
    return true;
  }
  TRACEX(BmpView, 2, "Leave UpdatePalette(false)");
  return false;
}

//
// Responds to an incoming Paint message by redrawing the bitmap.
// The Scroller's BeginView method, which sets the viewport origin
// relative to the present scroll position, has been called by TWindow's
// EvPaint
// Note that we Invalidate() ourselves with false to avoid the background
// paint flicker. Thats why we use
//
// The code can use either the Bitmap member with Stretch- and Bit- Blts,
// or use the Dib member with Stretch- and Set- DIBits...
//
void
TBmpViewWindow::Paint(TDC& dc, bool, TRect&)
{
  TRACEX(BmpView, 2, "Enter Paint()");
  TRect clientRect = GetClientRect();

  TRACEX(BmpView, 2, "Paint::BkBrush: " << hex << (uint)(HBRUSH)*BkgndBrush);
  dc.SelectObject(*BkgndBrush);

  TMemoryDC memoryDC(dc);  // Get ready to possibly use the DDB

  if (PaintFromDDB && Bitmap) {
    TRACEX(BmpView, 2, "Paint::Bitmap: " << hex << (uint)(HBITMAP)*Bitmap);
    memoryDC.SelectObject(*Bitmap);
//    dc.SetStretchBltMode(STRETCH_HALFTONE);
    dc.SetStretchBltMode(STRETCH_ORSCANS);
    if (Palette) {
      TRACEX(BmpView, 2, "Paint::Palette: " << hex << (uint)(HPALETTE)*Palette);
      dc.SelectObject(*Palette, false);
      dc.RealizePalette();
      memoryDC.SelectObject(*Palette, false);
      memoryDC.RealizePalette();  
    }
    if (Rop == SRCCOPY) {
      if (Colors == 2) {
        if (Palette) {
          PALETTEENTRY pe;
          Palette->GetPaletteEntry(0, pe);
          dc.SetTextColor(TColor(pe));
          Palette->GetPaletteEntry(1, pe);
          dc.SetBkColor(TColor(pe));
        }
        else {
          dc.SetBkColor(TColor(0,0,0));
          dc.SetTextColor(TColor(255,255,255));
        }
      }
    }
  }

  if (PaintFromDDB && Bitmap || !PaintFromDDB && Dib) {
    TRect imageRect(0,0, PixelWidth, PixelHeight);
    if (Parent->IsIconic()) {
      if (PaintFromDDB)
        dc.StretchBlt(Parent->GetClientRect(), memoryDC, imageRect, Rop);
      else
        dc.StretchDIBits(Parent->GetClientRect(), imageRect, *Dib, Rop);
    }
    else {
      clientRect += TPoint((int)Scroller->XPos, (int)Scroller->YPos);
      if (Fit) {
        // Stretch to fit
        //
        if (PaintFromDDB)
          dc.StretchBlt(clientRect, memoryDC, imageRect, Rop);
        else
          dc.StretchDIBits(clientRect, imageRect, *Dib);
      }
      else {
        // Let it clip
        //
        if (PaintFromDDB)
          dc.BitBlt(imageRect, memoryDC, TPoint(0,0), Rop);
        else
          dc.SetDIBitsToDevice(imageRect, TPoint(0,0), *Dib);

        // Clear borders here for no flicker
        //
        dc.PatBlt(TRect(TPoint(PixelWidth,0), clientRect.BottomRight()));
        dc.PatBlt(TRect(TPoint(0,PixelHeight), clientRect.BottomRight()));
      }
    }
  }
  else
    // Nothing to paint
    //
    dc.PatBlt(clientRect, PATCOPY);

  TRACEX(BmpView, 2, "Leave Paint()" << endl);
}

//
// Setup all of the bitmap related members given a new dib
//
void
TBmpViewWindow::SetupFromDib(TDib* dib)
{
  TRACEX(BmpView, 1, "Enter SetupFromDib()");
  TRACEX(BmpView, 1, "SetupFromDib::Dib: " << hex << (uint)(HANDLE)*dib);

  delete Dib;
  Dib = dib;

  if (Palette != DefPalette)
    delete Palette;
  Palette = 0;
  try {
    Palette = new TPalette(*dib);
  }
  catch (...) {
//    Palette = new TPalette(::CreateHalftonePalette(TScreenDC()), AutoDelete);
    Palette = DefPalette;
  }

  TRACEX(BmpView, 1, "SetupFromDib::Palette: " << hex << (uint)(HPALETTE)*Palette);

  {
    TWaitCursor w;
    delete Bitmap;
    Bitmap = new TBitmap(*Dib, Palette);
    TRACEX(BmpView, 1, "SetupFromDib::Bitmap: " << hex << (uint)(HBITMAP)*Bitmap);
  }

  PixelWidth  = Dib->Width();
  PixelHeight = Dib->Height();

  UpdatePalette(true);
  AdjustScroller();

  // We'll paint the icon from the bitmap, or use the icon in the resource
  //
  if (PaintIcon)
    GetApplication()->GetMainWindow()->SetIcon(0, 0);
  else
    GetApplication()->GetMainWindow()->SetIcon(GetApplication(), GetApplication()->GetName());

  TRACEX(BmpView, 1, "Leave SetupFromDib()");
}

//
// Test if the passed resource is a Windows 3.0 (or PM 1.x) DI bitmap
// and if so read it.
// Report errors if unable to do so. Adjust the Scroller to the new
// bitmap dimensions.
//
bool
TBmpViewWindow::LoadBitmapResource(uint16 resId)
{
  TDib* newDib;
  try {
    newDib = new TDib(*GetModule(), TResId(resId));
  }
  catch (TXGdi) {
    MessageBox("Cannot access bitmap resource", GetApplication()->GetName(),
               MB_OK);
    return false;
  }
  SetupFromDib(newDib);
  return true;
}

//
// Test if the passed file is a Windows 3.0 DI (or PM 1.x) bitmap
// and if so read it.
// Report errors if unable to do so. Adjust the Scroller to the new
// bitmap dimensions.
//
bool
TBmpViewWindow::LoadBitmapFile(const char* name)
{
  TDib* newDib;
  try {
    newDib = new TDib(name);
  }
  catch (TXGdi) {
    MessageBox("Cannot open bitmap file", GetApplication()->GetName(), MB_OK);
    return false;
  }
  SetupFromDib(newDib);
  return true;
}

//
//
//
bool
TBmpViewWindow::LoadMemHandle(HBITMAP handle)
{
#if defined(USE_DDB)
#if defined(BI_PLAT_WIN32)
  // Reqest size of info. buffer to validate HBITMAP 
  //
  if (::GetObject(handle, 0, 0)) {
#else
  if (::IsGDIObject(handle)) {
#endif
    TDib* newDib;
    try {
      newDib = new TDib(TBitmap(handle));
      SetupFromDib(newDib);
      MemHandle = handle;

      char buf[20];
      sprintf(buf, "hbm:%0X", MemHandle);
      SetCaption(buf);
      return true;
    }
    catch (TXGdi) {
      MessageBox("Cannot construct Dib from HBITMAP",
                 GetApplication()->GetName(), MB_OK);
    }
  }
  else
    MessageBox("Not a valid bitmap handle",
                GetApplication()->GetName(), MB_OK);
#endif
  return false;
}

//----------------------------------------------------------------------------

//
// class TBmpViewApp
// ~~~~~ ~~~~~~~~~~~
class _USERCLASS TBmpViewApp : public TApplication {
  public:
    TBmpViewApp(const char far* name) : TApplication(name) {}
    void InitMainWindow() {
      TFrameWindow* frame = new TFrameWindow(0, Name, new TBmpViewWindow);
      frame->AssignMenu(Name);
      frame->SetIcon(this, Name);
      frame->Attr.AccelTable = IDA_BMPVIEW;
      SetMainWindow(frame);
    }
};

//----------------------------------------------------------------------------

//
//
//
int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TBmpViewApp(AppName).Run();
}
