//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1995 by Borland International, All Rights Reserved
//
//   This program has example code that uses the Common Dialog classes
//   in OWL
//
//   The main window will have menu selections for opening a file, changing
//   the font and changing the color used for the selected font.  When a file
//   is selected the name will be displayed on the client area of the window.
//
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/dialog.h>
#include <owl/dc.h>
#include <owl/chooseco.h>
#include <owl/choosefo.h>
#include <owl/opensave.h>
#include <stdio.h>
#include <string.h>
#include "commdlgx.rh"


//
// class TCommDlgWnd
// ~~~~~ ~~~~~~~~~~~
class TCommDlgWnd : public TFrameWindow {
  public:
    TCommDlgWnd(TWindow*, const char*);
   ~TCommDlgWnd();

    void       Paint(TDC&, bool, TRect&);
    void       CmFileOpen();
    void       CmColor();
    void       CmFont();
    void       CmHelpAbout();

    TColor     Color;
    TFont*     Font;

    TOpenSaveDialog::TData   FilenameData;
    TChooseFontDialog::TData FontData;

    void EvSize(uint sizeType, TSize& size);

  DECLARE_RESPONSE_TABLE(TCommDlgWnd);
};

DEFINE_RESPONSE_TABLE1(TCommDlgWnd, TFrameWindow)
  EV_WM_SIZE,
  EV_COMMAND(CM_FILEOPEN, CmFileOpen),
  EV_COMMAND(CM_COLOR, CmColor),
  EV_COMMAND(CM_FONT, CmFont),
  EV_COMMAND(CM_HELPABOUT, CmHelpAbout),
END_RESPONSE_TABLE;


//
// Note the initialization method of the filter string. The TOpenSave::TData
// class expects to find a filter string that has a '|' terminator between
// strings and an extra '|' that terminates the entire filter data set.
// The '|' characters are translated to 0's within TData's copy of the string.
// Using '|'s allows the filter to be loaded from a resource & copied using
// strcpy.
//
TCommDlgWnd::TCommDlgWnd(TWindow* parent, const char* title)
:
  TFrameWindow(parent, title),
  FilenameData(OFN_FILEMUSTEXIST|OFN_HIDEREADONLY|OFN_PATHMUSTEXIST,
               "All Files (*.*)|*.*|Text Files (*.txt)|*.txt|",
               0, "", "*")
{
  AssignMenu("CMDLGAPMENU");      // Set up the menu
  Color = TColor::Black;          // Use black as the default color
  Font = 0;                       // Empty the handle to the font

  // Take advantage of each OS' enhancements to the FileOpen Dialog
  //
#if defined(BI_PLAT_WIN32)
  if (TSystem::IsNT() || TSystem::IsWin95())
    FilenameData.Flags |= OFN_LONGNAMES;

  if (TSystem::IsWin95())
    FilenameData.Flags |= OFN_EXPLORER;
#endif
}

TCommDlgWnd::~TCommDlgWnd()
{
  delete Font;
}
//
// We need to invalidate the entire area, not just the clip area so that
// paint gets called correctly
//
void
TCommDlgWnd::EvSize(uint sizeType, TSize& size)
{
  Invalidate();
  TFrameWindow::EvSize(sizeType,size);
}

//
// Display the file name using the selected font in the selected color.
//
void
TCommDlgWnd::Paint(TDC& paintDC, bool, TRect&)
{
  paintDC.SetTextColor(Color);
  paintDC.SetBkColor(TColor::SysWindow);
  if (Font)
    paintDC.SelectObject(*Font);
  paintDC.DrawText(FilenameData.FileName, strlen(FilenameData.FileName),
                   GetClientRect(), DT_CENTER | DT_WORDBREAK);
}

//
//
//
void
TCommDlgWnd::CmFileOpen()
{
  // If the call to Execute fails you can examine the Error member
  // of FilenameData to determine the type of error that occured.
  //
  if (TFileOpenDialog(this, FilenameData).Execute() != IDOK) {
    if (FilenameData.Error != 0) {   // 0 value means user selected Cancel
      char  msg[50];
      sprintf(msg, "GetOpenFileName returned Error #%ld", FilenameData.Error);
      MessageBox(msg, "WARNING", MB_OK|MB_ICONSTOP);
    }
  }
  Invalidate();         // Repaint to display the new name
}

//
//
void
TCommDlgWnd::CmColor()
{
  TChooseColorDialog::TData choose;
  static TColor    custColors[16] = {
    0x010101L, 0x101010L, 0x202020L, 0x303030L,
    0x404040L, 0x505050L, 0x606060L, 0x707070L,
    0x808080L, 0x909090L, 0xA0A0A0L, 0xB0B0B0L,
    0xC0C0C0L, 0xD0D0D0L, 0xE0E0E0L, 0xF0F0F0L
  };

  choose.Flags = CC_RGBINIT;
  choose.Color = Color;
  choose.CustColors = custColors;
  if (TChooseColorDialog(this, choose).Execute() == IDOK) {
    Color = choose.Color;
  }
  Invalidate();
}

//
//
//
void
TCommDlgWnd::CmFont()
{
  if (Font) {                    // FontData contains previous selections
    FontData.Flags |= CF_INITTOLOGFONTSTRUCT;
    FontData.Color = Color;
  }
  else {
    FontData.DC = 0;
    FontData.Flags = CF_EFFECTS | CF_FORCEFONTEXIST | CF_SCREENFONTS;
    FontData.Color = Color;      // Color and font dialogs use the same color
    FontData.Style = 0;
    FontData.FontType = SCREEN_FONTTYPE;
    FontData.SizeMin = 0;
    FontData.SizeMax = 0;
  }
  if (TChooseFontDialog(this, FontData).Execute() == IDOK) {
    delete Font;
    Color = FontData.Color;
    Font = new TFont(&FontData.LogFont);
  }
  Invalidate();
}

void
TCommDlgWnd::CmHelpAbout()
{
  MessageBox("Common Dialog Example\nWritten using ObjectWindows\n"
             "Copyright (c) 1993, 1995 Borland",
             "About Common Dialog Example",
             MB_OK);
}


//
// class TCommDlgApp
// ~~~~~ ~~~~~~~~~~~
class TCommDlgApp : public TApplication {
  public:
    TCommDlgApp() : TApplication() {}

    void InitMainWindow() {
      MainWindow = new TCommDlgWnd(0, "Common Dialog Example");
      EnableCtl3d();
    }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TCommDlgApp().Run();
}
