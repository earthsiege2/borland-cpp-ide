//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_GLYPHBTN_H)
# include <owl/glyphbtn.h>
#endif
#if !defined(OWL_CHECKBOX_H)
# include <owl/checkbox.h>
#endif
#if !defined(WINSYS_COLOR_H)
# include <winsys/color.h>
#endif
#include "glyphbtn.h"

//
// Class TSampleApp
// ~~~~~ ~~~~~~~~~~
class TSampleApp : public TApplication {
  public:
    void    InitMainWindow();
};

//
// Class TClientWindow
// ~~~~~ ~~~~~~~~~~~~~
class TClientWindow : public TDialog {
  public:
    TClientWindow(TWindow* parent = 0);

    void SetupWindow() {
      TDialog::SetupWindow();
      EnableHelp->Check();
    }

    void CmEnableHelp() {
      HelpButton->EnableWindow(EnableHelp->GetCheck());
    }

  private:
    TCheckBox* EnableHelp;
    TGlyphButton* HelpButton;

  DECLARE_RESPONSE_TABLE(TClientWindow);
};

DEFINE_RESPONSE_TABLE1(TClientWindow, TWindow)
  EV_COMMAND(IDC_ENABLEHELP, CmEnableHelp),
END_RESPONSE_TABLE;


TClientWindow::TClientWindow(TWindow* parent)
:
 TDialog(parent, IDD_CLIENTDLG, 0)
{
  TGlyphButton* glyph1 = new TGlyphButton(this, IDC_1);
  glyph1->SetGlyph(new TBtnBitmap(*GetApplication(), IDB_BORBTNII_OK));
  TGlyphButton* glyph2 = new TGlyphButton(this, IDC_2);
  glyph2->SetGlyph(IDB_BORBTNII_CANCEL);
  HelpButton = new TGlyphButton(this, IDC_3);
  HelpButton->SetGlyph(IDB_BORBTNII_HELP);
  HelpButton->SetGlyph(IDB_BORBTNII_HELPG, 0, TGlyphButton::gtDisabled);

  EnableHelp = new TCheckBox(this, IDC_ENABLEHELP);

  SetBkgndColor(TColor::Sys3dFace);
}

void
TSampleApp::InitMainWindow()
{
  SetMainWindow(new TFrameWindow(0, "Bitmap Button",
                                 new TClientWindow(), true));
  GetMainWindow()->Attr.Style &= ~WS_THICKFRAME;
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TSampleApp().Run();
}
