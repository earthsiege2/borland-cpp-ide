//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Font demo window for GDIDemo program
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\dc.h>
#include <owl\scroller.h>
#include <string.h>
#include "fontx.h"

struct FontInfoRec {
  TFont* Font;     // Logical font object
  int    Height;   // Height of logical font in pixels
  int    Width;    // Width of name of the font in pixels
  char   Name[LF_FACESIZE];  // Name of this font
};

// local variables used by EnumerateFonts callback function
//
static int         FontUsers = 0;
static FontInfoRec FontInfo[MaxNumFonts];
static int         NumFonts;            // Number of system fonts available
static TDC*        TheDC = 0;

// EnumerateFont is a call back function.  It receives information
//  about system fonts.  It creates an example of each font by calling
//  CreateFont. When MaxNumFonts have been processed, 0 is returned
//  notifying windows to stop sending information, otherwise 1 is
//  returned telling windows to send more information if available
//
#if defined(__WIN32__)
int __stdcall
#else
int far pascal _export
#endif
EnumerateFont(LOGFONT far* logFont, TEXTMETRIC far*, int, LPARAM)
{
  // Create the font described by logFont
  //
  FontInfo[NumFonts].Font = new TFont(logFont);

  // Save the height of the font for positioning when drawing in the window
  //
  FontInfo[NumFonts].Height = logFont->lfHeight;

  // Save the name of the font for drawing in the window
  //
  strcpy(FontInfo[NumFonts].Name, logFont->lfFaceName);
  TheDC->SelectObject(*FontInfo[NumFonts].Font);

  TSize extent(0,0);
  TheDC->GetTextExtent(logFont->lfFaceName, strlen(logFont->lfFaceName),
                       extent);
  FontInfo[NumFonts].Width = extent.cx;
  TheDC->RestoreFont();
  NumFonts++;

  return NumFonts >= MaxNumFonts ?
      0 :      // Don't send any more information, the array is full
      1;       // Send more information if available
}

// Collect all of the system fonts
//
void
GetFontInfo()
{
  if (FontUsers == 0) {
    TheDC = new TScreenDC;
    NumFonts = 0;

    // Create an instance of the call back function.  This allows
    // our program to refer to an exported function.  Otherwise the
    // Data segment will not be correct. This is a no-op in 32bit.
    //
    TProcInstance enumProc((FARPROC)EnumerateFont);

    // Gather information about all fonts that are allowable in our DC
    //
    EnumFonts(*TheDC, 0, (OLDFONTENUMPROC)(FARPROC)enumProc, 0);

    delete TheDC;
    TheDC = 0;
  }
  FontUsers++;
}

// Release font information
//
void
ReleaseFontInfo()
{
  FontUsers--;
  if (FontUsers == 0)
    for (int i = 0; i < NumFonts; i++) {
      delete FontInfo[i].Font;
      FontInfo[i].Font = 0;
    }
}

// TFontWindow ----------------------------------------------------

DEFINE_RESPONSE_TABLE1(TFontWindow, TBaseDemoWindow)
  EV_WM_SIZE,
END_RESPONSE_TABLE;

IMPLEMENT_CASTABLE1(TFontWindow, TBaseDemoWindow);

// Initialize object and collect font information
//
TFontWindow::TFontWindow() : TBaseDemoWindow()
{
  GetFontInfo();
  Attr.Style |= WS_VSCROLL | WS_HSCROLL;
  FontsHeight = 0;
  FontsWidth = 0;
  for (int i = 0; i < NumFonts; i++) {
    FontsHeight += FontInfo[i].Height;
    if (FontsWidth < FontInfo[i].Width)
      FontsWidth = FontInfo[i].Width;
  }
  Scroller = new TScroller(this, 1, 1, 0, 0);
}

TFontWindow::~TFontWindow()
{
  ReleaseFontInfo();
}

// Draw each font name in it's font in the Display context.  Each
//  line is incremented by the height of the font
//
void
TFontWindow::Paint(TDC& dc, BOOL, TRect&)
{
  TPoint position(10,0);
  for (int i = 0; i < NumFonts; i++) {
    dc.SelectObject(*FontInfo[i].Font);
    dc.TextOut(position, FontInfo[i].Name, strlen(FontInfo[i].Name));
    position.Offset(0, FontInfo[i].Height);
  }
}

void
TFontWindow::EvSize(UINT SizeType, TSize& Size)
{
  TBaseDemoWindow::EvSize(SizeType, Size);
  if (Scroller)
    Scroller->SetRange(FontsWidth - Size.cx + 10,
                       FontsHeight - Size.cy);
}
