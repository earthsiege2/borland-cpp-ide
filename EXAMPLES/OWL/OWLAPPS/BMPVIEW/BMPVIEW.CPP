//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Example program that shows Dibs, Bitmaps and Palettes in a scrolling
//   Window. Also uses diagnostics to trace thru some routines
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\dc.h>
#include <owl\menu.h>
#include <owl\framewin.h>
#include <owl\scroller.h>
#include <owl\opensave.h>
#include <owl\clipview.h>
#include <string.h>
#include <dir.h>
#include "bmpview.h"

DIAG_DEFINE_GROUP_INIT(OWL_INI, BmpView, 1, 0);

#define USE_DDB     // Use a DDB, else blts the DIB directly to the screen
//#define PAINT_ICON  // define to paint the icon from the bitmap

#define MAXAPPNAME  20
static const char AppName[] = "BitmapView";

//
// TBmpViewWindow, a Bitmap displaying window derived from TClipboardViewer to
// facilitate receiving of clipboard change notifications. Could mix it in if
// an additional base was desired.
//
class TBmpViewWindow : virtual public TWindow, public TClipboardViewer {
  public:
    char      FileName[MAXPATH];
    TDib*     Dib;
#if defined(USE_DDB)
    TBitmap*  Bitmap;
#endif
    TPalette* Palette;
    TBrush*   BkgndBrush;
    long      Rop;
    int       PixelWidth;
    int       PixelHeight;
    WORD      Colors;
    BOOL      Fit;
    BOOL      AutoClipView;

    TBmpViewWindow();
   ~TBmpViewWindow();

  protected:
    void      CmFileOpen();
    void      CmRead1();
    void      CmRead2();
    void      CmReadBad();
    void      CmCopy();
    void      CmPaste();
    void      CmFit();
    void      CmAutoClipView();
    void      CeCopy(TCommandEnabler& ce);
    void      CePaste(TCommandEnabler& ce);
    void      CeFit(TCommandEnabler& ce);
    void      CeAutoClipView(TCommandEnabler& ce);

    void      Paint(TDC&, BOOL erase, TRect&);
    void      EvSize(UINT sizeType, TSize&);

    void      EvPaletteChanged(HWND hWndPalChg);
    BOOL      EvQueryNewPalette();
    void      EvSetFocus(HWND); // should use above when working
    void      EvDrawClipboard();
    void      EvDestroy();

    BOOL      UpdatePalette(BOOL alwaysRepaint);
    void      AdjustScroller();
    void      SetCaption(const char*);
    void      SetupFromDib(TDib* dib);
    BOOL      LoadBitmapFile(const char*);
    BOOL      LoadBitmapResource(WORD ResId);

  DECLARE_RESPONSE_TABLE(TBmpViewWindow);
};

DEFINE_RESPONSE_TABLE2(TBmpViewWindow, TClipboardViewer, TWindow)
  EV_COMMAND(CM_FILEOPEN, CmFileOpen),
  EV_COMMAND(CM_READ1, CmRead1),
  EV_COMMAND(CM_READ2, CmRead2),
  EV_COMMAND(CM_READBAD, CmReadBad),
  EV_COMMAND(CM_EDITCOPY, CmCopy),
  EV_COMMAND(CM_EDITPASTE, CmPaste),
  EV_COMMAND(CM_FIT, CmFit),
  EV_COMMAND(CM_AUTOCLIPVIEW, CmAutoClipView),
  EV_COMMAND_ENABLE(CM_EDITCOPY, CeCopy),
  EV_COMMAND_ENABLE(CM_EDITPASTE, CePaste),
  EV_COMMAND_ENABLE(CM_FIT, CeFit),
  EV_COMMAND_ENABLE(CM_AUTOCLIPVIEW, CeAutoClipView),
  EV_WM_SIZE,
  EV_WM_PALETTECHANGED,
  EV_WM_QUERYNEWPALETTE,
  EV_WM_SETFOCUS,
  EV_WM_DRAWCLIPBOARD,
  EV_WM_DESTROY,
END_RESPONSE_TABLE;

//
// Constructor for a TBmpViewWindow, sets scroll styles and constructs
// the Scroller object.  Also sets the Rop based on whether the display
// is monochrome (two-color) or polychrome.
//
TBmpViewWindow::TBmpViewWindow()
  : TWindow(0, 0, 0), TClipboardViewer()
{
  // Init TWindow since TClipboardViewer is usually a mixin and doesn't do it
  //
//  Init(0, 0, 0);

  Attr.Style |= WS_VSCROLL | WS_HSCROLL;
  Dib = 0;
#if defined(USE_DDB)
  Bitmap = 0;
#endif
  Palette = 0;
  BkgndBrush = new TBrush(::GetSysColor(COLOR_WINDOW));
  Scroller = new TScroller(this, 1, 1, 200, 200);
  Fit = FALSE;
  AutoClipView = FALSE;

  TScreenDC screenDC;
  if (screenDC.GetDeviceCaps(NUMCOLORS) < 3 )
    Rop = NOTSRCCOPY;
  else
    Rop = SRCCOPY;
  
  SetCaption(0);
}

TBmpViewWindow::~TBmpViewWindow()
{
#if defined(USE_DDB)
  delete Bitmap;
#endif
  delete Palette;
  delete Dib;
  delete BkgndBrush;
}

//
// Build up a caption based on a filename, and set it into the title.
//
void
TBmpViewWindow::SetCaption(const char* name) 
{
  char caption[MAXPATH + MAXAPPNAME + 2 + 1];
  strcpy(FileName, name ? name : "(Untitled)");
  strcpy(caption, GetApplication()->GetName());
  strcat(caption, " - ");
  strcat(caption, FileName);
  if (Parent)
    Parent->SetCaption(caption);
}

//
// Make a metafile & put it on the clipboard.
// Make a copy of each of the objects & place the copies on the clipboard
//
void
TBmpViewWindow::CmCopy()
{
  TClipboard& clipboard = OpenClipboard();
  if (clipboard.EmptyClipboard()) {
    TMetaFileDC mfDC;
    mfDC.SetWindowExt(Dib->Size());
    mfDC.SetWindowOrg(0, 0);
    mfDC.SetDIBitsToDevice(TRect(0,0, PixelWidth, PixelHeight), TPoint(0,0), *Dib);
    TMetaFilePict mf(mfDC.Close(), AutoDelete);
    mf.ToClipboard(clipboard, MM_TEXT, TSize(PixelWidth, PixelHeight));

    TPalette(*Palette).ToClipboard(clipboard);
    TDib(*Dib).ToClipboard(clipboard);
#if defined(USE_DDB)
    TBitmap(*Bitmap).ToClipboard(clipboard);
#endif

    clipboard.CloseClipboard();
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
  TClipboard& clipboard = OpenClipboard();
  if (!clipboard)
    return;

  TPalette* newPal = 0;
  TDib*     newDib = 0;
  TBitmap*  newBitmap = 0;

  // If there is a palette on the clipboard, get it & realize it
  //
  if (clipboard.IsClipboardFormatAvailable(CF_PALETTE)) {
    newPal = new TPalette(TPalette(clipboard));  // make a copy
    UpdatePalette(TRUE);
  }

  // try DIB format 1st
  //
  if (clipboard.IsClipboardFormatAvailable(CF_DIB)) {
    newDib = new TDib(TDib(clipboard));        // make a copy
    newBitmap = new TBitmap(*newDib, newPal);  // newPal==0 is OK

  // try metafile 2nd
  //
  } else if (clipboard.IsClipboardFormatAvailable(CF_METAFILEPICT)) {
    if (!newPal)
      newPal = new TPalette((HPALETTE)GetStockObject(DEFAULT_PALETTE));
    newBitmap = new TBitmap(TMetaFilePict(clipboard), *newPal,
                            GetClientRect().Size());

#if defined(USE_DDB)
  // try bitmap (DDB) format 3rd
  //
  } else if (clipboard.IsClipboardFormatAvailable(CF_BITMAP))
    newBitmap = new TBitmap(TBitmap(clipboard));     // make a copy

  else
    return;  // Should never happen--this command is enabled by above tests

  // Got a bitmap & maybe more. Now keep it & setup things.
  //
  delete Bitmap;
  Bitmap = newBitmap;

  if (!newDib)
    newDib = new TDib(*newBitmap, newPal);
#endif
  delete Dib;
  Dib = newDib;

  delete Palette;
  Palette = newPal ? newPal : new TPalette(*newDib);
  Palette->GetObject(Colors);

  PixelWidth  = Dib->Width();
  PixelHeight = Dib->Height();
  AdjustScroller();
  SetCaption("(Clipboard)");
  
  clipboard.CloseClipboard();

//  Parent->SetIcon(0, 0);  // we'll paint the icon from the bitmap
}

void
TBmpViewWindow::CePaste(TCommandEnabler& ce)
{
  TClipboard& clipboard = OpenClipboard();
  ce.Enable(
    clipboard && (
      clipboard.IsClipboardFormatAvailable(CF_METAFILEPICT) ||
      clipboard.IsClipboardFormatAvailable(CF_DIB) ||
      clipboard.IsClipboardFormatAvailable(CF_BITMAP)
    )
  );
  clipboard.CloseClipboard();
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

  // only show scrollbars when image is larger than
  // the client area and we are not stretching to fit.
  //
  if (Fit)
    Scroller->SetRange(0, 0);

  else {
    TPoint Range(Max(PixelWidth-clientRect.Width(), 0),
                 Max(PixelHeight-clientRect.Height(), 0));
    Scroller->SetRange(Range.x, Range.y);
  }
  Scroller->ScrollTo(0, 0);
  if (!GetUpdateRect(clientRect, FALSE))
    Invalidate(FALSE);
}

//
// Reset scroller range.
//
void
TBmpViewWindow::EvSize(UINT SizeType, TSize& Size)
{
  TWindow::EvSize(SizeType, Size);
  if (SizeType != SIZEICONIC) {
    AdjustScroller();
    Invalidate(FALSE);
  }
}

//
// Somebody changed the palette. If its not us, then we need to update.
//
void
TBmpViewWindow::EvPaletteChanged(HWND hWndPalChg)
{
  if (hWndPalChg != HWindow)
    UpdatePalette(TRUE);    // pass FALSE to UpdateColors() instead of repaint
}

//
// We need to re-realize the logical palette each time
// we regain the input focus
//
BOOL
TBmpViewWindow::EvQueryNewPalette()
{
  return UpdatePalette(TRUE);
}

//
// Use this message temporarily until the palette msgs get routed to us
//
void
TBmpViewWindow::EvSetFocus(HWND)
{
  UpdatePalette(TRUE);
}

void
TBmpViewWindow::EvDrawClipboard()
{
  if (TClipboardViewer::DoDrawClipboard() == esComplete)
    return;
  if (AutoClipView)
    CmPaste();
}

void
TBmpViewWindow::EvDestroy()
{
  if (TClipboardViewer::DoDestroy() == esComplete)
    return;
  TWindow::EvDestroy();
}

BOOL
TBmpViewWindow::UpdatePalette(BOOL alwaysRepaint)
{
  TRACEX(BmpView, 2, "Enter UpdatePalette()");
  if (Palette) {
    TClientDC clientDC(*this);
    #if !defined(__WIN32__)
      Palette->UnrealizeObject();
    #endif
    TRACEX(BmpView, 2, "UpdatePalette::Palette: " << hex << (UINT)(HPALETTE)*Palette);
    clientDC.SelectObject(*Palette, FALSE);
    if (clientDC.RealizePalette() > 0)
      if (alwaysRepaint)
        Invalidate(FALSE);
      else
        clientDC.UpdateColors();
    TRACEX(BmpView, 2, "Leave UpdatePalette(TRUE)");
    return TRUE;
  }
  TRACEX(BmpView, 2, "Leave UpdatePalette(FALSE)");
  return FALSE;
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
TBmpViewWindow::Paint(TDC& dc, BOOL, TRect&)
{
  TRACEX(BmpView, 2, "Enter Paint()");
  TRect clientRect = GetClientRect();
  TRACEX(BmpView, 2, "Paint::BkBrush: " << hex << (UINT)(HBRUSH)*BkgndBrush);
  dc.SelectObject(*BkgndBrush);

#if defined(USE_DDB)
  if (Bitmap) {
    TMemoryDC memoryDC(dc);
    TRACEX(BmpView, 2, "Paint::Bitmap: " << hex << (UINT)(HBITMAP)*Bitmap);
    memoryDC.SelectObject(*Bitmap);
    dc.SetStretchBltMode(COLORONCOLOR);
    if (Palette) {
      TRACEX(BmpView, 2, "Paint::Palette: " << hex << (UINT)(HPALETTE)*Palette);
      dc.SelectObject(*Palette, FALSE);
      dc.RealizePalette();
      memoryDC.SelectObject(*Palette, FALSE);
    }
    if (Rop == SRCCOPY) {
      if (Colors == 2) {
        if (Palette) {
          PALETTEENTRY pe;
          Palette->GetPaletteEntry(0, pe);
          dc.SetTextColor(TColor(pe));
          Palette->GetPaletteEntry(1, pe);
          dc.SetBkColor(TColor(pe));
        } else {
          dc.SetBkColor(TColor(0,0,0));
          dc.SetTextColor(TColor(255,255,255));
        }
      }
    }
#else
  if (Dib) {
#endif

    TRect imageRect(0,0, PixelWidth, PixelHeight);
    if (Parent->IsIconic()) {
      #if defined(USE_DDB)
        dc.StretchBlt(Parent->GetClientRect(), memoryDC, imageRect, Rop);
      #else
        dc.StretchDIBits(Parent->GetClientRect(), imageRect, *Dib, Rop);
      #endif
 
    } else {
      clientRect += TPoint((int)Scroller->XPos, (int)Scroller->YPos);
      if (Fit) {
        #if defined(USE_DDB)
          dc.StretchBlt(clientRect, memoryDC, imageRect, Rop);
        #else
          dc.StretchDIBits(clientRect, imageRect, *Dib);
        #endif

      } else {
        #if defined(USE_DDB)
          dc.BitBlt(imageRect, memoryDC, TPoint(0,0), Rop);
        #else
          dc.SetDIBitsToDevice(imageRect, TPoint(0,0), *Dib);
        #endif
            
        // Clear borders here for no flicker
        //
        dc.PatBlt(TRect(TPoint(PixelWidth,0), clientRect.BottomRight()));
        dc.PatBlt(TRect(TPoint(0,PixelHeight), clientRect.BottomRight()));
      }
    }
  } else
    dc.PatBlt(clientRect, PATCOPY);
  TRACEX(BmpView, 2, "Leave Paint()" << endl);
}

void
TBmpViewWindow::SetupFromDib(TDib* dib)
{
  TRACEX(BmpView, 1, "Enter SetupFromDib()");
  TRACEX(BmpView, 1, "SetupFromDib::Dib: " << hex << (UINT)(HANDLE)*dib);
  delete Dib;
  Dib = dib;
  delete Palette;
  Palette = new TPalette(*dib);
  TRACEX(BmpView, 1, "SetupFromDib::Palette: " << hex << (UINT)(HPALETTE)*Palette);

#if defined(USE_DDB)
  delete Bitmap;
  Bitmap = new TBitmap(*Dib, Palette);
  TRACEX(BmpView, 1, "SetupFromDib::Bitmap: " << hex << (UINT)(HBITMAP)*Bitmap);
#endif

  PixelWidth  = Dib->Width();
  PixelHeight = Dib->Height();
  UpdatePalette(TRUE);
  AdjustScroller();
#if defined(PAINT_ICON)
  Parent->SetIcon(0, 0);  // enable to paint the icon from the bitmap
#endif
  TRACEX(BmpView, 1, "Leave SetupFromDib()");
}

//
// Test if the passed resource is a Windows 3.0 (or PM 1.x) DI bitmap
// and if so read it.
// Report errors if unable to do so. Adjust the Scroller to the new
// bitmap dimensions.
//
BOOL
TBmpViewWindow::LoadBitmapResource(WORD resId)
{
  TDib* newDib;
  try {
    newDib = new TDib(*GetModule(), resId);
  }
  catch (TGdiBase::TXGdi) {
    MessageBox("Cannot access bitmap resource", GetApplication()->GetName(),
               MB_OK);
    return FALSE;
  }
  SetupFromDib(newDib);
  return TRUE;
}

//
// Test if the passed file is a Windows 3.0 DI (or PM 1.x) bitmap
// and if so read it.
// Report errors if unable to do so. Adjust the Scroller to the new
// bitmap dimensions.
//
BOOL
TBmpViewWindow::LoadBitmapFile(const char* name)
{
  TDib* newDib = 0;
  try {
    newDib = new TDib(name);
  }
  catch (TGdiBase::TXGdi) {
    MessageBox("Cannot open bitmap file", GetApplication()->GetName(), MB_OK);
    return FALSE;
  }
  SetupFromDib(newDib);
  return TRUE;
}



//----------------------------------------------------------------------------

class TBmpViewApp : public TApplication {
  public:
    TBmpViewApp(const char far* name) : TApplication(name) {}
    void InitMainWindow() {
      MainWindow = new TFrameWindow(0, Name, new TBmpViewWindow);
      MainWindow->AssignMenu(Name);
      MainWindow->SetIcon(this, Name);
    }
};

//----------------------------------------------------------------------------

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TBmpViewApp(AppName).Run();
}
