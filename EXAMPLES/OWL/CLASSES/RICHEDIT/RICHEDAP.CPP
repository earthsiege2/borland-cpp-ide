//----------------------------------------------------------------------------
// ObjectWindows
// (c) Copyright 1995, 1996 by Borland International, All Rights Reserved
//
// Illustrates usage of TRichEdit class
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/decframe.h>
#include <owl/statusba.h>
#include <owl/controlb.h>
#include <owl/buttonga.h>
#include <owl/applicat.h>
#include <owl/richedit.h>
#include <owl/richedpr.h>
#include <owl/choosefo.h>
#include "richedap.h"

//
//
//
const int  IDRichEd = 0x100;
const int  UnChk    = TCommandEnabler::Unchecked;
const int  Chk      = TCommandEnabler::Checked;

//
// Class TRichEdApp
// ~~~~~ ~~~~~~~~~~
//
class TRichEdApp : public TApplication {
  public:
    void    InitMainWindow();
};

//
// Class TRichEdFrame
// ~~~~~ ~~~~~~~~~~~~
//
class TRichEdFrame : public TDecoratedFrame {
  public:
    TRichEdFrame(TWindow*     parent,
                 const char * title = 0,
                 TWindow*     clientWnd = 0);
    ~TRichEdFrame();

    void  SetupWindow();

    // File Command Handlers
    //
    void  CmFileNew();
    void  CmFileOpen();
    void  CmFilePrint();
    void  CmFilePrintPreview();

    // Format Command Handlers
    //
    void  CmFormatFont();
    void  CmFormatPara();
    void  CmFormatTabs();
    void  CmFormatBold();
    void  CmFormatItalic();
    void  CmFormatUnderline();
    void  CmFormatStrikeout();
    void  CmFormatTextData();
    void  CmFormatRTFData();
    void  CeFormatFont(TCommandEnabler&);
    void  CeFormatPara(TCommandEnabler&);
    void  CeFormatTabs(TCommandEnabler&);
    void  CeFormatBold(TCommandEnabler&);
    void  CeFormatItalic(TCommandEnabler&);
    void  CeFormatUnderline(TCommandEnabler&);
    void  CeFormatStrikeout(TCommandEnabler&);
    void  CeFormatTextData(TCommandEnabler&);
    void  CeFormatRTFData(TCommandEnabler&);

    bool  EnDropFiles(TEnDropFiles&){return false;}
    bool  EnMsgFilter(TMsgFilter&){return false;}
    bool  EnProtected(TEnProtected&){return false;}
    void  EnReqResize(TReqResize&){}

  protected:
    TRichEdit*      Edit;       // Rich Edit Control

    // It's typical to create the 'TPrinter' object at the application level.
    // This allows the same device to be shared between PrintPreview and
    // actual Printing. It also ensures that configurations applied to the
    // printer are visible to all 'printer-related' aspects of the
    // application.
    //
    TPrinter*       Printer;

  DECLARE_RESPONSE_TABLE(TRichEdFrame);
};


DEFINE_RESPONSE_TABLE1(TRichEdFrame, TDecoratedFrame)
  EV_COMMAND(CM_FILENEW, CmFileNew),
  EV_COMMAND(CM_FILEOPEN, CmFileOpen),
  EV_COMMAND(CM_FILEPRINT, CmFilePrint),
  EV_COMMAND(CM_FILEPRINTPREVIEW, CmFilePrintPreview),

  EV_COMMAND(CM_FORMATFONT,      CmFormatFont),
  EV_COMMAND(CM_FORMATPARAGRAPH, CmFormatPara),
  EV_COMMAND(CM_FORMATTABS,      CmFormatTabs),

  EV_COMMAND(CM_FORMATBOLD,      CmFormatBold),
  EV_COMMAND(CM_FORMATITALIC,    CmFormatItalic),
  EV_COMMAND(CM_FORMATUNDERLINE, CmFormatUnderline),
  EV_COMMAND(CM_FORMATSTRIKEOUT, CmFormatStrikeout),
  EV_COMMAND(CM_FORMATTEXTDATA,  CmFormatTextData),
  EV_COMMAND(CM_FORMATRTFDATA,   CmFormatRTFData),

  EV_COMMAND_ENABLE(CM_FORMATFONT,      CeFormatFont),
  EV_COMMAND_ENABLE(CM_FORMATPARAGRAPH, CeFormatPara),
  EV_COMMAND_ENABLE(CM_FORMATTABS,      CeFormatTabs),
  EV_COMMAND_ENABLE(CM_FORMATBOLD,      CeFormatBold),
  EV_COMMAND_ENABLE(CM_FORMATITALIC,    CeFormatItalic),
  EV_COMMAND_ENABLE(CM_FORMATUNDERLINE, CeFormatUnderline),
  EV_COMMAND_ENABLE(CM_FORMATSTRIKEOUT, CeFormatStrikeout),
  EV_COMMAND_ENABLE(CM_FORMATTEXTDATA,  CeFormatTextData),
  EV_COMMAND_ENABLE(CM_FORMATRTFDATA,   CeFormatRTFData),

  EV_EN_DROPFILES(IDRichEd, EnDropFiles),
  EV_EN_MSGFILTER(IDRichEd, EnMsgFilter),
  EV_EN_PROTECTED(IDRichEd, EnProtected),
  EV_EN_REQRESIZE(IDRichEd, EnReqResize),
END_RESPONSE_TABLE;

//
//
//
TRichEdFrame::TRichEdFrame(TWindow* parent, const char* title,
                           TWindow* client):
TDecoratedFrame(parent, title, client), Printer(0)
{
  Edit = TYPESAFE_DOWNCAST(client, TRichEdit);
  CHECK(Edit);
}

//
//
//
TRichEdFrame::~TRichEdFrame()
{
  delete Printer;
}

//
//
//
void
TRichEdFrame::SetupWindow()
{
  TDecoratedFrame::SetupWindow();

  // Change font to ANSI Variable - 
  //
  HFONT hFont = HFONT(::GetStockObject(ANSI_VAR_FONT));
  if (hFont)
    Edit->SetWindowFont(hFont, true);
}

//
//
//
void
TRichEdFrame::CmFileNew()
{
  if (Edit)
    Edit->NewFile();
}

//
//
//
void
TRichEdFrame::CmFileOpen()
{
  if (Edit)
    Edit->Open();
}

//
//
//
void
TRichEdFrame::CmFilePrint ()
{
  // Create Printer object
  //
  if (!Printer)
    Printer = new TPrinter(GetApplication());

  // Create Printout window and set characteristics.
  //
  const char* title = Edit->GetFileName() ? Edit->GetFileName() : "Untitled";
  TRichEditPrintout printout(*Printer, *Edit, title);
  printout.SetBanding(true);

  // Bring up the Print dialog and print the document.
  //
  Printer->Print(this, printout, true);
}

//
//
//
void
TRichEdFrame::CmFilePrintPreview()
{
  if (Edit) {

    // Create 'TPrinter' object to represent physical printer device
    //
    if (!Printer)
      Printer = new TPrinter(GetApplication());

    // Create 'TRichEditPrintout' object to represent RTF documents
    //
    TRichEditPrintout printout(*Printer,
                               *Edit,
                               "Print Preview");

    // Create a preview window
    //
    TRichEditPreviewFrame *prevW;
    prevW = new TRichEditPreviewFrame(this, *Printer, printout,
                                     *Edit, printout.GetTitle(),
                                      new TLayoutWindow(0));
    prevW->Execute();
  }
}

//
//
//
void
TRichEdFrame::CmFormatFont()
{
  //
  // Retrieve current character format
  //
  TCharFormat chFormat(*Edit);

  //
  // Fill logfont structure using info. from character format
  //
  LOGFONT lf;
  chFormat.SetFontInfo(lf);

  //
  // Initialize structure for Font common dialog
  //
  TChooseFontDialog::TData fontData;
  fontData.LogFont = lf;
  fontData.DC = TClientDC(*this);
  fontData.Flags = CF_SCREENFONTS | CF_INITTOLOGFONTSTRUCT | CF_EFFECTS;
  fontData.Color = chFormat.GetTextColor();
  fontData.FontType = SCREEN_FONTTYPE;

  //
  // Display dialog
  //
  if (TChooseFontDialog(this, fontData).Execute() == IDOK) {
    //
    // Update character format from chosen font info
    //
    chFormat.GetFontInfo(fontData.LogFont);
    chFormat.SetTextColor(fontData.Color);
    Edit->SetCharFormat(chFormat);
  }
}

//
//
//
void
TRichEdFrame::CmFormatPara()
{
}

//
//
//
void
TRichEdFrame::CmFormatTabs()
{
}

//
//
//
void
TRichEdFrame::CmFormatBold()
{
  Edit->ToggleCharAttribute(CFM_BOLD, CFE_BOLD);
}

//
//
//
void
TRichEdFrame::CmFormatItalic()
{
  Edit->ToggleCharAttribute(CFM_ITALIC, CFE_ITALIC);
}

//
//
//
void
TRichEdFrame::CmFormatUnderline()
{
  Edit->ToggleCharAttribute(CFM_UNDERLINE, CFE_UNDERLINE);
}

//
//
//
void
TRichEdFrame::CmFormatStrikeout()
{
  Edit->ToggleCharAttribute(CFM_STRIKEOUT, CFE_STRIKEOUT);
}

//
//
//
void  
TRichEdFrame::CmFormatTextData()
{
  Edit->SetFormat(SF_TEXT);
}

//
//
//
void  
TRichEdFrame::CmFormatRTFData()
{
  Edit->SetFormat(SF_RTF);
}

//
//
//
void
TRichEdFrame::CeFormatFont(TCommandEnabler& /*ce*/)
{
}

//
//
//
void
TRichEdFrame::CeFormatPara(TCommandEnabler& /*ce*/)
{
}

//
//
//
void
TRichEdFrame::CeFormatTabs(TCommandEnabler& /*ce*/)
{
}

//
//
//
void
TRichEdFrame::CeFormatBold(TCommandEnabler& ce)
{
  uint result = Edit->HasCharAttribute(CFM_BOLD, CFE_BOLD);
  ce.SetCheck(result  ? Chk : UnChk);
}

//
//
//
void
TRichEdFrame::CeFormatItalic(TCommandEnabler& ce)
{
  uint result = Edit->HasCharAttribute(CFM_ITALIC, CFE_ITALIC);
  ce.SetCheck(result ? Chk : UnChk);
}

//
//
//
void
TRichEdFrame::CeFormatUnderline(TCommandEnabler& ce)
{
  uint result = Edit->HasCharAttribute(CFM_UNDERLINE, CFE_UNDERLINE);
  ce.SetCheck(result ? Chk : UnChk);
}

//
//
//
void
TRichEdFrame::CeFormatStrikeout(TCommandEnabler& ce)
{
  uint result = Edit->HasCharAttribute(CFM_STRIKEOUT, CFE_STRIKEOUT);
  ce.SetCheck(result ? Chk : UnChk);
}

//
//
//
void  
TRichEdFrame::CeFormatTextData(TCommandEnabler& ce)
{
  ce.SetCheck((Edit->IsRTF() == false) ? Chk : UnChk);
}

//
//
//
void  
TRichEdFrame::CeFormatRTFData(TCommandEnabler& ce)
{
  ce.SetCheck((Edit->IsRTF()) ? Chk : UnChk);
}

// -------------------------------------------------------------------
// Methods of application object
// -------------------------------------------------------------------
void
TRichEdApp::InitMainWindow()
{
  // Create client RICHEDIT object
  //
  TRichEdit* client = new TRichEdit(0, IDRichEd, "", 0, 0, 0, 0, 0);

  // Create main/frame object
  //
  SetMainWindow(new TRichEdFrame(0, 0, client));

  // Setup to use menu
  //
  GetMainWindow()->AssignMenu(IDM_APPMENU);

  // Create decorations
  //
  TStatusBar*  sbar = new TStatusBar(GetMainWindow(), TGadget::Recessed,
           TStatusBar::CapsLock | TStatusBar::NumLock |
           TStatusBar::Overtype | TStatusBar::SizeGrip);
  TControlBar* cbar = new TControlBar(GetMainWindow());

  // Insert gadgets in control bar
  //
  cbar->Insert(*new TButtonGadget(CM_FILENEW, CM_FILENEW));
  cbar->Insert(*new TButtonGadget(CM_FILEOPEN, CM_FILEOPEN));
  cbar->Insert(*new TButtonGadget(CM_FILESAVE, CM_FILESAVE));
  cbar->Insert(*new TButtonGadget(CM_FILEPRINT, CM_FILEPRINT));

  cbar->Insert(*new TSeparatorGadget(6));
  cbar->Insert(*new TButtonGadget(CM_EDITUNDO, CM_EDITUNDO));
  cbar->Insert(*new TButtonGadget(CM_EDITCUT, CM_EDITCUT));
  cbar->Insert(*new TButtonGadget(CM_EDITCOPY, CM_EDITCOPY));
  cbar->Insert(*new TButtonGadget(CM_EDITPASTE, CM_EDITPASTE));

  cbar->Insert(*new TSeparatorGadget(6));
  cbar->Insert(*new TButtonGadget(CM_FORMATBOLD, CM_FORMATBOLD,
                                  TButtonGadget::NonExclusive));
  cbar->Insert(*new TButtonGadget(CM_FORMATITALIC, CM_FORMATITALIC,
                                  TButtonGadget::NonExclusive));
  cbar->Insert(*new TButtonGadget(CM_FORMATUNDERLINE, CM_FORMATUNDERLINE,
                                  TButtonGadget::NonExclusive));

  cbar->Insert(*new TSeparatorGadget(6));
  cbar->Insert(*new TButtonGadget(CM_HELPABOUT, CM_HELPABOUT));

  TYPESAFE_DOWNCAST(GetMainWindow(), TDecoratedFrame)->Insert(
                    *cbar, TDecoratedFrame::Top);
  TYPESAFE_DOWNCAST(GetMainWindow(), TDecoratedFrame)->Insert(
                    *sbar, TDecoratedFrame::Bottom);
  GetMainWindow()->Attr.AccelTable = TResId(IDA_RICHEDIT);
}

//
//
//
int
OwlMain(int /*argc*/, char * /*argv*/ [])
{
  TRichEdApp().Run();
  return 0;
}
