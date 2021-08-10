//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1996 by Borland International
//   intldemo.cpp
//
//  Program to demonstrate much of the functionality afforded with the
//  setlocale function and the locale libraries. Also demonstrates programming
//  a UI to be language-independent, and allow switching of the language at
//  run-time.
//----------------------------------------------------------------------------
#include <owl\pch.h>
#include <owl\decframe.h>
#include <owl\statusba.h>
#include <owl\dialog.h>
#include <owl\applicat.h>
#include <owl\dc.h>
#include <owl\menu.h>
#include <owl\olefacto.h>
#include <ocf/pch.h>
#include <ocf/ocreg.h>
#include <ocf\automacr.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <bwcc.h>
#include <cstring.h>

#include "intldemo.h"
#include "intldemo.hh"
#include "filelist.h"

TLangId TLocaleString::NativeLangId=MAKELANGID(LANG_ENGLISH,SUBLANG_ENGLISH_US);

// override string's comparison routines
int string::compare(const string& s) const throw()
{
  return strcoll(c_str(), s.c_str());
}

// pointer to functions such as isalpha, isalnum etc.
typedef int (*ClassMacro)(int);

//
// class TLocaleValueWindow
// ----- ------------------
//
// Popup window displaying the current locale values. Note that the locale or
// language can be changed from the main window while we are being displayed,
// and we will update accordingly.
//
class TLocaleValueWindow : public TFrameWindow
{
  public:
    TLocaleValueWindow(lconv *conv, short charWidth, short charHeight, TModule* resModule,
		       TWindow* parent, LPSTR title = 0);

    // Called by the parent after the language or locale has been changed to keep
    // us in synch
    void ResetValues(lconv *conv, short charWidth, short charHeight, TModule* resModule);

  protected:
    void SetupWindow();
    int Max(int a, int b);
    void EvClose();
    void Paint(TDC&, bool, TRect&);

  private:
    TModule* ResourceModule;         // Module containing localized resources
    short CharWidth;                 // Width of a character
    short CharHeight;                // Height of a character
    lconv* Conv;                     // Locale settings struct

  DECLARE_RESPONSE_TABLE(TLocaleValueWindow);
};

DEFINE_RESPONSE_TABLE1(TLocaleValueWindow, TFrameWindow)
  EV_WM_CLOSE,
END_RESPONSE_TABLE;

TLocaleValueWindow::TLocaleValueWindow(lconv *conv, short charWidth, short charHeight, TModule* resModule,
				       TWindow* parent, LPSTR title) : TFrameWindow(parent, title)
{
  Conv = conv;
  CharWidth = charWidth;
  CharHeight = charHeight;
  ResourceModule = resModule;

  Attr.H = CharHeight * 22;
  Attr.W = CharWidth * 70;
  Attr.Style = Attr.Style | WS_THICKFRAME | WS_SYSMENU;
}

inline int TLocaleValueWindow::Max(int a, int b)
{
  return (a > b) ? a : b;
}

void TLocaleValueWindow::EvClose()
{
  // Tell the parent that we're finished.
  Parent -> SendMessage(WM_VALWNDCLOSE, 0, 0);
  TFrameWindow::EvClose();
}

void TLocaleValueWindow::SetupWindow()
{
  TFrameWindow::SetupWindow();

  char title[100];
  ResourceModule -> LoadString(IDS_LOCALETITLE, title, sizeof(title));
  SetCaption(title);
}

void TLocaleValueWindow::ResetValues(lconv *conv, short charWidth, short charHeight,
												 TModule* resModule)
{
  Conv = conv;
  CharWidth = charWidth;
  CharHeight = charHeight;
  ResourceModule = resModule;
  char title[100];
  ResourceModule -> LoadString(IDS_LOCALETITLE, title, sizeof(title));
  SetCaption(title);
}

void TLocaleValueWindow::Paint(TDC& hdc, bool, TRect&)
{
  char buf[100];
  int maxWidth = 0;
  char yesStr[10], noStr[10], notDefined[20];

  hdc.SelectStockObject ( SYSTEM_FIXED_FONT );
  hdc.SetTextColor(TColor(0,0,255));

  for (short t = IDS_DECIMALPOINT, i = 1; t <= IDS_N_SIGN_POSN; t++, i++) {
    ResourceModule -> LoadString(t, buf, sizeof(buf));
    hdc.TextOut(CharWidth + 10, CharHeight * i, buf, strlen(buf));
    maxWidth = Max(maxWidth, strlen(buf));
  }

  ResourceModule->LoadString(IDS_YES, yesStr, sizeof(yesStr));
  ResourceModule->LoadString(IDS_NO, noStr, sizeof(noStr));
  ResourceModule->LoadString(IDS_NOT_DEFINED, notDefined, sizeof(notDefined));

  hdc.SetTextColor(TColor(255,0,0));
  maxWidth *= CharWidth;
  maxWidth += (5 * CharWidth);
  short i = 1;
  hdc.TextOut(maxWidth, CharHeight * i++, Conv->decimal_point, strlen(Conv->decimal_point));
  hdc.TextOut(maxWidth, CharHeight * i++, Conv->thousands_sep, strlen(Conv->thousands_sep));
  sprintf(buf, "%d", *Conv->grouping);
  hdc.TextOut(maxWidth, CharHeight * i++, buf, strlen(buf));
  hdc.TextOut(maxWidth, CharHeight * i++, Conv->int_curr_symbol, strlen(Conv->int_curr_symbol));
  hdc.TextOut(maxWidth, CharHeight * i++, Conv->currency_symbol, strlen(Conv->currency_symbol));
  hdc.TextOut(maxWidth, CharHeight * i++, Conv->mon_decimal_point, strlen(Conv->mon_decimal_point));
  hdc.TextOut(maxWidth, CharHeight * i++, Conv->mon_thousands_sep, strlen(Conv->mon_thousands_sep));
  sprintf(buf, "%d", *Conv->mon_grouping);
  hdc.TextOut(maxWidth, CharHeight * i++, buf, strlen(buf));
  hdc.TextOut(maxWidth, CharHeight * i++, Conv->positive_sign, strlen(Conv->positive_sign));
  hdc.TextOut(maxWidth, CharHeight * i++, Conv->negative_sign, strlen(Conv->negative_sign));

  char scratch[20];
  sprintf(buf, "%s", (Conv->int_frac_digits == CHAR_MAX) ? notDefined :
							itoa(Conv->int_frac_digits, scratch, 10));
  hdc.TextOut(maxWidth, CharHeight * i++, buf, strlen(buf));
  sprintf(buf, "%s", (Conv->frac_digits == CHAR_MAX) ? notDefined :
							itoa(Conv->frac_digits, scratch, 10));
  hdc.TextOut(maxWidth, CharHeight * i++, buf, strlen(buf));
  sprintf(buf, "%s", (Conv->p_cs_precedes == CHAR_MAX) ? notDefined :
							(Conv->p_cs_precedes == 1) ? yesStr : noStr);
  hdc.TextOut(maxWidth, CharHeight * i++, buf, strlen(buf));
  sprintf(buf, "%s", (Conv->p_sep_by_space == CHAR_MAX) ? notDefined :
							(Conv->p_sep_by_space == 1) ? yesStr : noStr);
  hdc.TextOut(maxWidth, CharHeight * i++, buf, strlen(buf));
  sprintf(buf, "%s", (Conv->n_cs_precedes == CHAR_MAX) ? notDefined :
							(Conv->n_cs_precedes == 1) ? yesStr : noStr);
  hdc.TextOut(maxWidth, CharHeight * i++, buf, strlen(buf));
  sprintf(buf, "%s", (Conv->n_sep_by_space == CHAR_MAX) ? notDefined :
							(Conv->n_sep_by_space == 1) ? yesStr : noStr);
  hdc.TextOut(maxWidth, CharHeight * i++, buf, strlen(buf));
  sprintf(buf, "%s", (Conv->p_sign_posn == CHAR_MAX) ? notDefined :
							itoa(Conv->p_sign_posn, scratch, 10));
  hdc.TextOut(maxWidth, CharHeight * i++, buf, strlen(buf));
  sprintf(buf, "%s", (Conv->n_sign_posn == CHAR_MAX) ? notDefined :
							itoa(Conv->n_sign_posn, scratch, 10));
  hdc.TextOut(maxWidth, CharHeight * i++, buf, strlen(buf));
}

//
// class TLocaleWindow
// ----- -------------
//
// Main window, containing a display of all 256 ANSI chars highlighted according
// to the current classification function.
//

class TLocaleWindow : public TWindow
{
  public:
    TLocaleWindow(TWindow* parent = 0, const char* title = 0);

    enum classifications {alnum = CM_ISALNUM, alpha, ascii, cntrl, digit, graph, lower, print, punct, space, upper, xdigit};
    void ChangeUI(TModule *pResModule);

  protected:
    void CmIsAlnum();
    void CmIsAlpha();
    void CmIsAscii();
    void CmIsCntrl();
    void CmIsDigit();
    void CmIsGraph();
    void CmIsLower();
    void CmIsPrint();
    void CmIsPunct();
    void CmIsSpace();
    void CmIsUpper();
    void CmIsXDigit();

    void Paint(TDC&, bool, TRect&);
    void SetupWindow();
    void EvMouseMove(uint /*modKeys*/, TPoint &point);

    int ChangeClassification(classifications newClassification);
    int TrueColor(TDC& hdc);
    int FalseColor(TDC& hdc);

  private:
    classifications Classification;

    short CharWidth;
    short CharHeight;
    int CellWidth;
    int CellHeight;
    TPoint BoxTopLeft;
    TPoint BoxBottomRight;

    static const ClassMacro ClassificationMacros[];
    static const char* MacroNames[];
    char CharacterString[20];

  DECLARE_AUTOCLASS(TLocaleWindow)
    AUTOFUNC0V(IsAlnum, CmIsAlnum, )
    AUTOFUNC0V(IsAlpha, CmIsAlpha, )
    AUTOFUNC0V(IsAscii, CmIsAscii, )
    AUTOFUNC0V(IsCntrl, CmIsCntrl, )
    AUTOFUNC0V(IsDigit, CmIsDigit, )
    AUTOFUNC0V(IsGraph, CmIsGraph, )
    AUTOFUNC0V(IsLower, CmIsLower, )
    AUTOFUNC0V(IsPrint, CmIsPrint, )
    AUTOFUNC0V(IsPunct, CmIsPunct, )
    AUTOFUNC0V(IsSpace, CmIsSpace, )
    AUTOFUNC0V(IsUpper, CmIsUpper, )
    AUTOFUNC0V(IsXDigit, CmIsXDigit, )

  DECLARE_RESPONSE_TABLE(TLocaleWindow);
};

DEFINE_AUTOCLASS(TLocaleWindow)
  EXPOSE_METHOD(IsAlnum, TAutoVoid, "IsAlnum", "IsAlnum", HC_CLIENT_ISALNUM)
  EXPOSE_METHOD(IsAlpha, TAutoVoid, "IsAlpha", "IsAlpha", HC_CLIENT_ISALPHA)
  EXPOSE_METHOD(IsAscii, TAutoVoid, "IsAscii", "IsAscii", HC_CLIENT_ISASCII)
  EXPOSE_METHOD(IsCntrl, TAutoVoid, "IsCntrl", "IsCntrl", HC_CLIENT_ISCNTRL)
  EXPOSE_METHOD(IsDigit, TAutoVoid, "IsDigit", "IsDigit", HC_CLIENT_ISDIGIT)
  EXPOSE_METHOD(IsGraph, TAutoVoid, "IsGraph", "IsGraph", HC_CLIENT_ISGRAPH)
  EXPOSE_METHOD(IsLower, TAutoVoid, "IsLower", "IsLower", HC_CLIENT_ISLOWER)
  EXPOSE_METHOD(IsPrint, TAutoVoid, "IsPrint", "IsPrint", HC_CLIENT_ISPRINT)
  EXPOSE_METHOD(IsPunct, TAutoVoid, "IsPunct", "IsPunct", HC_CLIENT_ISPUNCT)
  EXPOSE_METHOD(IsSpace, TAutoVoid, "IsSpace", "IsSpace", HC_CLIENT_ISSPACE)
  EXPOSE_METHOD(IsUpper, TAutoVoid, "IsUpper", "IsUpper", HC_CLIENT_ISUPPER)
  EXPOSE_METHOD(IsXDigit, TAutoVoid, "IsXDigit", "IsXDigit", HC_CLIENT_ISXDIGIT)
END_AUTOCLASS(TLocaleWindow, tfNormal, "TLocaleWindow", "@TLocaleWindow_", HC_FRAME_WINDOW);

DEFINE_RESPONSE_TABLE1(TLocaleWindow, TWindow)
  EV_WM_MOUSEMOVE,
  EV_COMMAND(CM_ISALNUM, CmIsAlnum),
  EV_COMMAND(CM_ISALPHA, CmIsAlpha),
  EV_COMMAND(CM_ISASCII, CmIsAscii),
  EV_COMMAND(CM_ISCNTRL, CmIsCntrl),
  EV_COMMAND(CM_ISDIGIT, CmIsDigit),
  EV_COMMAND(CM_ISGRAPH, CmIsGraph),
  EV_COMMAND(CM_ISLOWER, CmIsLower),
  EV_COMMAND(CM_ISPRINT, CmIsPrint),
  EV_COMMAND(CM_ISPUNCT, CmIsPunct),
  EV_COMMAND(CM_ISSPACE, CmIsSpace),
  EV_COMMAND(CM_ISUPPER, CmIsUpper),
  EV_COMMAND(CM_ISXDIGIT, CmIsXDigit),
END_RESPONSE_TABLE;

TLocaleWindow::TLocaleWindow(TWindow* parent, const char* title)
  : TWindow(parent, title)
{
  Attr.Id = ID_LOCALEWINDOW;
  Classification = alpha;
}

const ClassMacro TLocaleWindow::ClassificationMacros[] = 
  { isalnum, isalpha, isascii, iscntrl, isdigit, isgraph,
    islower, isprint, ispunct, isspace, isupper, isxdigit };

const char* TLocaleWindow::MacroNames[] =
{ "isalnum()", "isalpha()", "isascii()", "iscntrl()",
  "isdigit()", "isgraph()", "islower()", "isprint()", 
  "ispunct()", "isspace()", "isupper()", "isxdigit()" };

void TLocaleWindow::SetupWindow()
{
  TWindow::SetupWindow();
  TWindowDC dc(HWindow);
  dc.SelectStockObject(SYSTEM_FIXED_FONT);
  TEXTMETRIC tm;
  dc.GetTextMetrics (tm);
  CharWidth = short(tm.tmAveCharWidth);
  CharHeight = short(tm.tmHeight + tm.tmExternalLeading);
  SetFocus();
}

int TLocaleWindow::TrueColor(TDC& hdc)
// Sets colour to display characters for which the classification function
// returns TRUE
{
  hdc.SetTextColor(TColor(255, 0, 255));
  hdc.SetBkColor(TColor(0, 220, 0));
  return 0;
}

int TLocaleWindow::FalseColor(TDC& hdc)
// Sets colour to display characters for which the classification function
// returns FALSE
{
  hdc.SetTextColor(TColor(200, 200, 200));
  hdc.SetBkColor(TColor::White);
  return 0;
}

void TLocaleWindow::Paint(TDC& hdc, bool, TRect&)
{
  char buf[100];
  int maxWidth;

  hdc.SelectStockObject(SYSTEM_FIXED_FONT);

  hdc.SetTextColor(TColor::Black);
  hdc.TextOut((30 * CharWidth), (CharHeight / 2), MacroNames[Classification - alnum], strlen(MacroNames[Classification - CM_ISALNUM]));
  maxWidth = (10 * CharWidth);

  const int columns=16;
  const int rows=16;
  const char hexChars[16] = {'0', '1', '2', '3', '4', '5', '6', '7', 
			     '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

  //Display the codepoint values around the character set.
  for (int i = 0; i < rows; i++) {
    sprintf(buf, "%c", hexChars[i]);
    hdc.TextOut(maxWidth + ((i * 3) * CharWidth), CharHeight * 2 , buf, 1);
    hdc.TextOut((maxWidth - (3 * CharWidth)), CharHeight * (i + 3), buf, 1);
  }

  // display the character set in a ROWS x COLUMNS grid, with colours set by
  // trueColor() and falseColor() according to the return value of the current
  // classification function.
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      int c = ((i * columns) + j);
      sprintf(buf, "%c",  c);
      ClassificationMacros[Classification - alnum](c) ? TrueColor(hdc) : FalseColor(hdc);
      if (c < 256) // in case we use different values for row/column.
	hdc.TextOut(maxWidth + ((j * 3) * CharWidth), CharHeight * (i + 3), buf, 1);
    }


  // Draw a box round the characters.
  const int x1 = maxWidth - 6;
  const int y1 = (3 * CharHeight) - 2;
  const int x2 = (maxWidth - 2) + (CharWidth * (columns * 3));
  const int y2 = ((3 * CharHeight) - 2) + (CharHeight  * rows);

  BoxTopLeft.x = x1;
  BoxTopLeft.y = y1;
  BoxBottomRight.x = x2 - x1;
  BoxBottomRight.y = y2 - y1;

  CellWidth = (BoxBottomRight.x / columns);
  CellHeight = (BoxBottomRight.y / rows);

  hdc.SelectObject(TPen(TColor(0, 127, 127)));

  hdc.MoveTo(x1, y1);
  hdc.LineTo(x1, y2);
  hdc.LineTo(x2, y2);
  hdc.LineTo(x2, y1);
  hdc.LineTo(x1, y1);

  for (int i = 0; i < rows; i++) {
    hdc.MoveTo(x1, y1 + (i * CharHeight));
    hdc.LineTo(x2, y1 + (i * CharHeight));
  }

  for (int i = 0; i < columns; i++) {
    hdc.MoveTo(x1 + ((i * 3) * CharWidth), y1);
    hdc.LineTo(x1 + ((i * 3) * CharWidth), y2);
  }
  hdc.RestorePen();
}

int TLocaleWindow::ChangeClassification(classifications newClassification)
{
  CheckMenuItem(Parent -> GetMenu(), Classification, MF_UNCHECKED);
  Classification = newClassification;
  CheckMenuItem(Parent -> GetMenu(), Classification, MF_CHECKED);

  Invalidate(TRUE);
  return 0;
}

void TLocaleWindow::ChangeUI(TModule* resModule)
{
  CheckMenuItem(Parent -> GetMenu(), Classification, MF_CHECKED);
  resModule -> LoadString(IDS_CHARACTER, CharacterString, sizeof(CharacterString));
}

void TLocaleWindow::EvMouseMove(UINT /*modKeys*/, TPoint& point)
{
  char buf[50];
  point.x -= BoxTopLeft.x;
  point.y -= BoxTopLeft.y;
  if (((point.x > 0) && (point.x < BoxBottomRight.x - 4))
    && ((point.y > 0) && (point.y < BoxBottomRight.y))) {
    int ch = (((point.y / CellHeight) * 16) + (point.x /CellWidth));
    sprintf(buf, "%s %4d  :  %4c  :  %#x", CharacterString, ch, (ch == 0) ? 1 : ch, ch, ch);
  }
  else {
    buf[0] = 0;
  }
  TYPESAFE_DOWNCAST(Parent->ChildWithId(IDW_STATUSBAR), TStatusBar)->SetText(buf);
}

void TLocaleWindow::CmIsAlnum()
{
  if (Classification != alnum)
    ChangeClassification(alnum);
}

void TLocaleWindow::CmIsAlpha()
{
  if (Classification != alpha)
    ChangeClassification(alpha);
}

void TLocaleWindow::CmIsAscii()
{
  if (Classification != ascii)
    ChangeClassification(ascii);
}

void TLocaleWindow::CmIsCntrl()
{
  if (Classification != cntrl)
    ChangeClassification(cntrl);
}

void TLocaleWindow::CmIsDigit()
{
  if (Classification != digit)
    ChangeClassification(digit);
}

void TLocaleWindow::CmIsGraph()
{
  if (Classification != graph)
    ChangeClassification(graph);
}

void TLocaleWindow::CmIsLower()
{
  if (Classification != lower)
    ChangeClassification(lower);
}

void TLocaleWindow::CmIsPrint()
{
  if (Classification != print)
    ChangeClassification(print);
}

void TLocaleWindow::CmIsPunct()
{
  if (Classification != punct)
    ChangeClassification(punct);
}

void TLocaleWindow::CmIsSpace()
{
  if (Classification != space)
    ChangeClassification(space);
}

void TLocaleWindow::CmIsUpper()
{
  if (Classification != upper)
    ChangeClassification(upper);
}

void TLocaleWindow::CmIsXDigit()
{
  if (Classification != xdigit)
    ChangeClassification(xdigit);
}

//
// class TLocaleFrame
// ----- ------------
//
class TLocaleFrame : public TDecoratedFrame
{
  enum languages {langEnglish = CM_LANGUAGEENGLISH, langFrench, langGerman};
  enum locales {locC = CM_LOCALEC, locUS, locUK, locFrench, locGerman};

  public:
    TLocaleFrame(TWindow* client);
    virtual ~TLocaleFrame();

  protected:
    void SetupWindow();
    void EvEnterIdle(UINT source, HWND hWndDlg);
    void CmEnglishLanguage();
    void CmFrenchLanguage();
    void CmGermanLanguage();
    void CmFileList();
    void CmCLocale();
    void CmUSLocale();
    void CmUKLocale();
    void CmFrenchLocale();
    void CmGermanLocale();
    void CmShowValues();
    LRESULT WMValWndClose(WPARAM, LPARAM);
    TLocaleWindow& GetWindow();
    int ChangeUI(char* DLLName, languages newLanguage, UINT countryCode);
    char* ChangeLocale(int category, char* localeType, locales newLocale);
    void RedrawValueWindow();

  private:
    languages Language;
    locales   Locale;
    TModule*  ResourceModule;
    TMenu*    Menu;
    TLocaleValueWindow* ValueWin;
    short     CharWidth, CharHeight, ScrX, ScrY;
    lconv*    Conv;

  DECLARE_AUTOCLASS(TLocaleFrame)
    AUTODETACH
    AUTOPROPRO(Window,  GetWindow, TAutoObject<TLocaleWindow>,  )
    AUTOFUNC0V(CLocale, CmCLocale, )
    AUTOFUNC0V(USLocale, CmUSLocale, )
    AUTOFUNC0V(UKLocale, CmUKLocale, )
    AUTOFUNC0V(FrenchLocale, CmFrenchLocale, )
    AUTOFUNC0V(GermanLocale, CmGermanLocale, )
    AUTOFUNC0V(EnglishLanguage, CmEnglishLanguage, )
    AUTOFUNC0V(FrenchLanguage, CmFrenchLanguage, )
    AUTOFUNC0V(GermanLanguage, CmGermanLanguage, )

  DECLARE_RESPONSE_TABLE(TLocaleFrame);
};

DEFINE_AUTOCLASS(TLocaleFrame)
  EXPOSE_PROPRO(Window, TLocaleWindow, "@Wnd", "@wnd_", HC_FRAME_WINDOW)
  EXPOSE_METHOD(CLocale, TAutoVoid, "!CLocale", "@CLocale_", HC_FRAME_CLOCALE)
  EXPOSE_METHOD(USLocale, TAutoVoid, "!USLocale", "@USLocale_", HC_FRAME_USLOCALE)
  EXPOSE_METHOD(UKLocale, TAutoVoid, "!UKLocale", "@UKLocale_", HC_FRAME_UKLOCALE)
  EXPOSE_METHOD(FrenchLocale, TAutoVoid, "!FrenchLocale", "@FrenchLocale_", HC_FRAME_FRALOCALE)
  EXPOSE_METHOD(GermanLocale, TAutoVoid, "!GermanLocale", "@GermanLocale_", HC_FRAME_GERLOCALE)
  EXPOSE_METHOD(EnglishLanguage, TAutoVoid, "!EnglishLanguage", "@EnglishLanguage_", HC_FRAME_ENGLANG)
  EXPOSE_METHOD(FrenchLanguage, TAutoVoid, "!FrenchLanguage", "@FrenchLanguage_", HC_FRAME_FRALANG)
  EXPOSE_METHOD(GermanLanguage, TAutoVoid, "!GermanLanguage", "@GermanLanguage_", HC_FRAME_GERLANG)
END_AUTOCLASS(TLocaleFrame, tfNormal, "TLocaleFrame", "@TLocaleFrame_", HC_APP_WINDOW);

DEFINE_RESPONSE_TABLE1(TLocaleFrame, TDecoratedFrame)
  EV_WM_ENTERIDLE,
  EV_COMMAND(CM_FILELIST, CmFileList),
  EV_COMMAND(CM_LOCALEC, CmCLocale),
  EV_COMMAND(CM_LOCALEUS, CmUSLocale),
  EV_COMMAND(CM_LOCALEUK, CmUKLocale),
  EV_COMMAND(CM_LOCALEFRENCH, CmFrenchLocale),
  EV_COMMAND(CM_LOCALEGERMAN, CmGermanLocale),
  EV_COMMAND(CM_LANGUAGEENGLISH, CmEnglishLanguage),
  EV_COMMAND(CM_LANGUAGEFRENCH, CmFrenchLanguage),
  EV_COMMAND(CM_LANGUAGEGERMAN, CmGermanLanguage),
  EV_COMMAND(CM_SHOWVALUES, CmShowValues),
  EV_MESSAGE(WM_VALWNDCLOSE, WMValWndClose),
END_RESPONSE_TABLE;

TLocaleFrame::TLocaleFrame(TWindow* client)
  :TDecoratedFrame((TWindow*)0, (char*)0, client, TRUE)
{
  ResourceModule = new TModule("APIENG.DLL");

#if 1
  Menu = new TMenu(ResourceModule->LoadMenu("MAINMENU"), NoAutoDelete);
  if (!HMENU(*Menu))
    throw "Error loading menu";
#else
  Menu = new TMenu(*ResourceModule, "MAINMENU");
#endif

  ValueWin = 0;
  Locale = locC;
  Language = langEnglish;

  TWindowDC dc(HWindow);
  dc.SelectStockObject(SYSTEM_FIXED_FONT);
  TEXTMETRIC tm;
  dc.GetTextMetrics (tm);
  CharWidth = short(tm.tmAveCharWidth);
  CharHeight = short(tm.tmHeight + tm.tmExternalLeading);
  Attr.H = (CharHeight * 25);
  Attr.W = (CharWidth * 80);
}

TLocaleFrame::~TLocaleFrame()
{
  delete Menu;
  delete ResourceModule;
}

void TLocaleFrame::SetupWindow()
{
  TDecoratedFrame::SetupWindow();

  char title[100];
  ResourceModule->LoadString(IDS_APPNAME, title, sizeof(title));
  SetCaption(title);
  SetMenu(*Menu);
  Menu->CheckMenuItem(Locale, MF_CHECKED);
  Menu->CheckMenuItem(Language, MF_CHECKED);
  TYPESAFE_DOWNCAST(GetClientWindow(), TLocaleWindow)->ChangeUI(ResourceModule);
  Conv = localeconv();
}

void TLocaleFrame::EvEnterIdle(UINT source, HWND hWndDlg)
{
  //TDecoratedFrame::EvEnterIdle loads the help hint string, so
  // we change the instance here so it gets it from pResourceModule
  TModule* module = GetModule();
  SetModule(ResourceModule);
  TDecoratedFrame::EvEnterIdle(source, hWndDlg);
  SetModule(module);
}

void TLocaleFrame::CmEnglishLanguage()
{
  ChangeUI("apieng.dll", langEnglish, LANG_ENGLISH);
}

void TLocaleFrame::CmFrenchLanguage()
{
  ChangeUI("apifra.dll", langFrench, LANG_FRENCH);
}

void TLocaleFrame::CmGermanLanguage()
{
  ChangeUI("apiger.dll", langGerman, LANG_GERMAN);
}

void TLocaleFrame::CmFileList()
{
  TFileListDialog(this, ResourceModule).Execute();
}

void TLocaleFrame::CmCLocale()
{
  if (Locale != locC)
    ChangeLocale(LC_ALL, "C", locC);
}

void TLocaleFrame::CmUSLocale()
{
  if (Locale != locUS)
    ChangeLocale(LC_ALL, "en_US.WIN1252", locUS);
}

void TLocaleFrame::CmUKLocale()
{
  if (Locale != locUK)
    ChangeLocale(LC_ALL, "en_GB.WIN1252", locUK);
}

void TLocaleFrame::CmFrenchLocale()
{
  if (Locale != locFrench)
    ChangeLocale(LC_ALL, "fr_FR.WIN1252", locFrench);
}

void TLocaleFrame::CmGermanLocale()
{
  if (Locale != locGerman)
    ChangeLocale(LC_ALL, "de_DE.WIN1252", locGerman);
}

void TLocaleFrame::CmShowValues()
{
  if (!ValueWin) {
    ValueWin = new TLocaleValueWindow(Conv, CharWidth, CharHeight, ResourceModule, this);
    ValueWin->Create();
    ValueWin->Show(SW_SHOW);
  }
  else
    ValueWin->SetFocus();
}

LRESULT TLocaleFrame::WMValWndClose(WPARAM, LPARAM)
{
  ValueWin = 0;
  return 0;
}

TLocaleWindow& TLocaleFrame::GetWindow() 
{
  TLocaleWindow* localeWin = TYPESAFE_DOWNCAST(GetClientWindow(), TLocaleWindow);
  return *localeWin;
}

int TLocaleFrame::ChangeUI(char* dllName, languages newLanguage, UINT countryCode)
{
  delete ResourceModule;
  ResourceModule = new TModule(dllName);
  delete Menu;
  Menu = new TMenu(ResourceModule->LoadMenu("MAINMENU"), NoAutoDelete);
  SetMenu(*Menu);
  Menu->CheckMenuItem(Locale, MF_CHECKED);
  TYPESAFE_DOWNCAST(GetClientWindow(), TLocaleWindow)->ChangeUI(ResourceModule);

  char title[100];
  ResourceModule->LoadString(IDS_APPNAME, title, sizeof(title));
  SetCaption(title);

  Invalidate(TRUE);
  RedrawValueWindow();
  Menu->CheckMenuItem(Language, MF_UNCHECKED);
  Language = newLanguage;
  Menu->CheckMenuItem(Language, MF_CHECKED);

  TBwccDll* bwcc = GetApplication()->GetBWCCModule();
  bwcc->IntlTerm();
  bwcc->IntlInit(countryCode);
  return 1;
}

char* TLocaleFrame::ChangeLocale(int category, char *localeType, locales newLocale)
{
  Menu->CheckMenuItem(Locale, MF_UNCHECKED);
  Locale = newLocale;
  Menu->CheckMenuItem(Locale, MF_CHECKED);

  char* c = setlocale(category, localeType);
  Conv = localeconv();
  Invalidate(TRUE);
  RedrawValueWindow();
  ChildWithId(ID_LOCALEWINDOW)->Invalidate(TRUE);
  return c;
}

void TLocaleFrame::RedrawValueWindow()
{
  if (ValueWin) {
    ValueWin->ResetValues(Conv, CharWidth, CharHeight, ResourceModule);
    ValueWin->Invalidate(TRUE);
  }
}

//
// class TLocaleApplication
// ----- ------------------
//
class TLocaleApplication : public TApplication
{
  public:
    TLocaleApplication():TApplication("Intl demo program") {}

    void InitMainWindow();
    TLocaleFrame& GetWindow();

  DECLARE_AUTOCLASS(TLocaleApplication)
    AUTODETACH
    AUTOPROPRO(Window,  GetWindow, TAutoObject<TLocaleFrame>,  )
};

DEFINE_AUTOCLASS(TLocaleApplication)
  EXPOSE_APPLICATION(TLocaleApplication, "!Application", "@appobj_", HC_APP_APPLICATION)
  EXPOSE_QUIT("!Quit", "@quitapp_", HC_APP_QUIT)
  EXPOSE_PROPRO(Window, TLocaleFrame, "!Window", "@window_", HC_APP_WINDOW)
END_AUTOCLASS(TLocaleApplication, tfAppObject | tfCanCreate, "TLocaleApplication", "@TLocaleApp_", HC_APP_APPLICATION);

void TLocaleApplication::InitMainWindow()
{
  try
  {
    nCmdShow = SW_SHOWNORMAL;
    TLocaleFrame* frame = new TLocaleFrame(new TLocaleWindow);
    TStatusBar* sb = new TStatusBar(frame, TGadget::Recessed);
    frame->Insert(*sb, TDecoratedFrame::Bottom);
    MainWindow = frame;
    MainWindow->SetIcon(this, "World_Icon");
    EnableBWCC(TRUE, LANG_ENGLISH);
  }
  catch(xmsg& x)
  {
    MessageBox(0, x.why().c_str(), "Intldemo", MB_OK);
  }
}

TLocaleFrame& TLocaleApplication::GetWindow() 
{
  TLocaleFrame* frame = TYPESAFE_DOWNCAST(GetMainWindow(), TLocaleFrame);
  return *frame;
}

DEFINE_APP_DICTIONARY(AppDictionary);
static TPointer<TRegistrar> Registrar;

REGISTRATION_FORMAT_BUFFER(100)

BEGIN_REGISTRATION(ApplicationReg)
  REGDATA(clsid, "{ABA228C0-BD21-101C-AF42-040224009C00}")
  REGDATA(progid, "Locale.Application")
  REGDATA(appname, "@appname")
  REGDATA(description, "@Desc")
  REGDATA(cmdline, "/Automation")
  REGDATA(typehelp, "@typehelp")
END_REGISTRATION

int OwlMain(int /*argc*/, char* /*argv*/ [])
{
  try {
    ::Registrar = new TRegistrar(::ApplicationReg, TAutoFactory<TLocaleApplication>(), TApplication::GetCmdLine(), _hInstance);
    if (::Registrar->IsOptionSet(amAnyRegOption))
      return 0;

    return ::Registrar->Run();
  }
  catch (xmsg& x) {
    GetApplicationObject()->MessageBox(0, x.why().c_str(), "Exception", MB_OK);
  }
  return -1;
}
