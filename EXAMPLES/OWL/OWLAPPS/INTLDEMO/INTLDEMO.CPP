//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   intldemo.cpp
//
//  Program to demonstrate much of the functionality afforded with the
//  setlocale function and the locale libraries. Also demonstrates programming
//  a UI to be language-independent, and allow switching of the language at
//  run-time.
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\decframe.h>
#include <owl\statusba.h>
#include <owl\dialog.h>
#include <owl\mdi.h>
#include <owl\applicat.h>
#include <owl\dc.h>
#include <owl\menu.h>
#include <owl\button.h>
#include <owl\listbox.h>
#include <locale.h>
#include <io.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <dir.h>
#include <ctype.h>
#include <math.h>
#include <bwcc.h>
#include <cstring.h>

#include "intldemo.h"

#define ID_LOCALEWINDOW 101
// language identifiers as defined in winnt.h
#define LANG_ENGLISH 0x09
#define LANG_FRENCH  0x0c
#define LANG_GERMAN  0x07

#pragma warn -inl // functions containing ... are not expanded inline

char* formatVal(char*, long);

// override string's comparison routines
//
int string::compare(const string& s) const throw()
{
  return strcoll(c_str(), s.c_str());
}

//----------------------------------------------------------------------------
// Class to convert a file's date/time value into a struct tm.
//
class DosTime {
  private:
    struct filetime
    {
      int ftime;
      int fdate;
    };

    union dosfiletime
    {
      filetime ft;
      struct ftime ftime;
    };

    dosfiletime dft;
    struct date date;
    struct time time;

  public:
    DosTime(int ftime, int fdate)
    {
      dft.ft.ftime = ftime;
      dft.ft.fdate = fdate;

      time.ti_sec = dft.ftime.ft_tsec * 2;
      time.ti_min = dft.ftime.ft_min;
      time.ti_hour = dft.ftime.ft_hour;
      time.ti_hund = 0;

      date.da_day = dft.ftime.ft_day;
      date.da_mon = dft.ftime.ft_month;
      date.da_year = dft.ftime.ft_year + 1980;
    }

    struct tm *tmvalue()
    {
      time_t t;
      t = dostounix(&date, &time);
      return localtime (&t);
    }
};

//----------------------------------------------------------------------------
//  TFileViewer
//
//  Simple file viewer. Displays up to 100 chars of each of the first 100 lines
//  of a file in a listbox. Allows sorting by lines.
//
class TFileViewer : public TDialog {
  public:
    TFileViewer(TWindow* parent, TModule* module, char* fileName, TResId resourceId = ID_FILEVIEWER);

    void SetupWindow()
    {
      TDialog::SetupWindow();
      SetCaption(caption);
      delete [] caption;
      for (int i = 0; i < stringArray.GetItemsInContainer(); i++)
      {
        lBox -> AddString(stringArray[i]->c_str());
      }
    }

    void CmSort(UINT)
    {
      lBox -> ClearList();
      for (int i = 0; i < sStringArray.GetItemsInContainer(); i++)
      {
        lBox -> AddString(sStringArray[i]->c_str());
      }
      lBox -> SetSelIndex(0);
    }

  protected:
    enum {maxLines = 100, maxLineLength = 100};
    TListBox *lBox;
    TIArrayAsVector<string> stringArray;
    TISArrayAsVector<string> sStringArray;
    char *caption;
    int nLines;

  DECLARE_RESPONSE_TABLE(TFileViewer);
};

DEFINE_RESPONSE_TABLE1(TFileViewer, TDialog)
   EV_CHILD_NOTIFY_ALL_CODES(ID_SORTBUT, CmSort),
END_RESPONSE_TABLE;


TFileViewer::TFileViewer(TWindow* parent, TModule* module, char* fileName, TResId resourceId)
  : TDialog(parent, resourceId, module),
    stringArray(maxLines), sStringArray(maxLines)
{
  sStringArray.OwnsElements(0);
  ifstream f(fileName);
  nLines = 0;
  if (!f.fail())
  {
    caption = strdup(fileName);
    while(!f.eof() && nLines < maxLines)
    {
      char buf[maxLineLength];
      f.get(buf, sizeof buf - 1);
      string *s = new string(buf);
      stringArray.Add(s);
      sStringArray.Add(s);
      // if we're not at the end of the line, try to jump to the next line
      if (f.get() != '\n')
        f.ignore(100, '\n');
    }
    f.close();
  }
  lBox = new TListBox(this, ID_FILELISTBOX, module);
}


//----------------------------------------------------------------------------
//  TFileListBox
//
// Derivation of ListBox to display file information. Note we are using our own
// sort functions rather than Windows' default sorting. This allows different
// instances of the program to demonstrate the different sorting/collating
// sequences of different locales.
//
class TFileListBox : public TListBox
{
  public:
    TFileListBox(TWindow * parent, int ResourceId, TModule* Module) :
      TListBox(parent, ResourceId, Module),
      FRArray(100, 0, 10), SFRArray(100, 0, 10), currCase(upper), currSort(unsorted)
    {
      module = Module;
      SFRArray.OwnsElements(0);
    }

    void SetupWindow()
    {
      TListBox::SetupWindow();
      SetWindowFont(font, 0);
      GetDirList();
      FillListBox();
      SetSelIndex(0);
    }

    void ToLower();

    void FillListBox();

    void GetDirList();

    void EvLButtonDblClk(UINT, TPoint&);

    void Sort()
    {
      currSort = (currSort == sorted) ? unsorted : sorted;
      char buf[MAXFILE + MAXEXT + 1];
      GetSelString(buf, sizeof buf);
      FillListBox();
      SetSelString(buf, 0);
    }

    void ChangeDir();

    void View()
    {
      if (GetSelIndex() >= 0) {
        char buf[100];
        GetSelString(buf, sizeof buf);

        if (strstr(buf, "<DIR>"))
          ChangeDir();
        else {
          char* s = strchr(buf, ' ');
          if (s)
            *s = 0;
          TFileViewer(Parent, module, buf).Execute();
        }
      }
    }

  private:
    // Structure containing file information to be displayed in the
    // FileListBox.
    //
    struct FileRec
    {
      char name[13], datetime[100],  sizeStr[30];
      long fsize;
      char attrib;

      // functions used by sorted arrays
      int operator<(const FileRec& r) const
      {
        return (strcoll(name, r.name) < 0) ? 1 : 0;
      }

      int operator==(const FileRec& r) const
      {
        return (strcoll(name, r.name) == 0) ? 1 : 0;
      }
    };

    // Font to display the filelistbox - we want a non-proportional
    // font for formatting reasons
    class FileListFont : public TFont
    {
      private:
        int HeightInPixels(int pointSize)
        {
          TScreenDC  dc;
          return MulDiv(-pointSize, dc.GetDeviceCaps(LOGPIXELSY), 72);
        }

      public:
        FileListFont() : TFont ("Courier New", HeightInPixels(8)) {}
    };

    int isSorted;
    int nFiles;
    TIArrayAsVector<FileRec> FRArray;
    TISArrayAsVector<FileRec> SFRArray;
    enum cases {upper, lower};
    cases currCase;
    enum sorting {sorted, unsorted};
    sorting currSort;
    TModule* module;
    FileListFont font;

  DECLARE_RESPONSE_TABLE(TFileListBox);
};

DEFINE_RESPONSE_TABLE1(TFileListBox, TListBox)
   EV_WM_LBUTTONDBLCLK,
END_RESPONSE_TABLE;

void TFileListBox::EvLButtonDblClk(UINT, TPoint&)
{
  View();   // view the file or directory
}

void TFileListBox::GetDirList()
{
  SFRArray.Flush();
  FRArray.Flush();
  struct ffblk ffblk;
  struct tm *tm;
  DosTime *dt;
  nFiles = 0;
  int done = findfirst("*.*", &ffblk, 0x3f);
  while (!done)
  {
    FileRec* f = new FileRec;
    OemToAnsiBuff(ffblk.ff_name, ffblk.ff_name, strlen(ffblk.ff_name));
    if (currCase == lower)
    {
      strlwr(ffblk.ff_name);
    }
    strcpy(f->name, ffblk.ff_name);
    dt = new DosTime(ffblk.ff_ftime, ffblk.ff_fdate);
    tm = dt->tmvalue();
    delete dt;
    f->attrib = ffblk.ff_attrib;
    f->fsize = ffblk.ff_fsize;
    formatVal(f->sizeStr, ffblk.ff_fsize);
    strftime(f->datetime, 100, "%c", tm);
    FRArray.Add(f);
    SFRArray.Add(f);
    done = findnext(&ffblk);
  }
}

void TFileListBox::ChangeDir()
{
  char buf[MAXFILE + MAXEXT + 1];
  if (GetSelString(buf, sizeof buf))
  {
    for (int i = 0; i < sizeof buf; i++)
      if (buf[i] == ' ')
      {
        buf[i] = 0;
        break;
      }
    if (!chdir(buf))
    {
      GetDirList();
      FillListBox();
    }
  }
}


void TFileListBox::ToLower()
{
  int selection = GetSelIndex();
  if (currCase == upper)
  {
    for (int i = 0; i < FRArray.GetItemsInContainer(); i++)
      strlwr(FRArray[i] -> name);
    currCase = lower;
    FillListBox();
  }
  else
  {
    for (int i = 0; i < FRArray.GetItemsInContainer(); i++)
      strupr(FRArray[i] -> name);
    currCase = upper;
    FillListBox();
  }
  SetSelIndex(selection);
}

void TFileListBox::FillListBox()
{
  char lbformat[] = "%-14.14s\t%-7s\t%10s";
  char s[120];
  SetRedraw(FALSE);
  // Japanese Windows 3.0 repaints horribly with SETREDRAW switched on!
  ClearList();
  int i;
  switch(currSort)
  {
    case sorted:
      for (i = 0; i < SFRArray.GetItemsInContainer(); i++)
      {
        sprintf(s, lbformat, SFRArray[i]->name, SFRArray[i]->datetime,
          ((SFRArray[i]->attrib & FA_DIREC) ? ("<DIR>") : (SFRArray[i]->sizeStr)));
        AddString(s);
      }
      break;

    case unsorted:
      for (i = 0; i < FRArray.GetItemsInContainer(); i++)
      {
        sprintf(s, lbformat, FRArray[i]->name, FRArray[i]->datetime,
          ((FRArray[i]->attrib & FA_DIREC) ? ("<DIR>") : (FRArray[i]->sizeStr)));
        AddString(s);
      }
      break;
  }
  SetRedraw(TRUE);
}

//----------------------------------------------------------------------------
// Dialog box containing the FileListBox.
//
class TFileListDialog : public TDialog
{
  public:
    TFileListDialog(TWindow * parent, TModule* Module, int ResourceId = ID_FILELISTBOX)
      :TDialog(parent, ResourceId, Module)
    {
      ListBox =  new TFileListBox(this, ID_FILELISTBOX, Module);
      viewButton = new TButton(this, ID_VIEWBUTTON, Module);
      startDir = strdup(getcwd(0, MAXPATH));
    }

    virtual ~TFileListDialog()
    {
      chdir(startDir);
      delete [] startDir;
    }

    void Sort(UINT)
    {
      ListBox -> Sort();
    }

    void ToLower(UINT)
    {
      ListBox -> ToLower();
    }

    void View(UINT)
    {
      ListBox -> View();
    }

    void Help(UINT)
    {
    }

  private:
    TFileListBox* ListBox;
    TButton*      viewButton;
    char*         startDir;

  DECLARE_RESPONSE_TABLE(TFileListDialog);
};

DEFINE_RESPONSE_TABLE1(TFileListDialog, TDialog)
  EV_CHILD_NOTIFY_ALL_CODES(ID_SORTBUT, Sort),
  EV_CHILD_NOTIFY_ALL_CODES(ID_TOLOWERBUT, ToLower),
  EV_CHILD_NOTIFY_ALL_CODES(ID_VIEWBUTTON, View),
  EV_CHILD_NOTIFY_ALL_CODES(IDHELP, Help),
END_RESPONSE_TABLE;


//----------------------------------------------------------------------------
// Popup window displaying the current locale values. Note that the locale or
// language can be changed from the main window while we are being displayed,
// and we will update accordingly.
//
class TLocaleValueWindow : public TFrameWindow
{
  public:
    TLocaleValueWindow(lconv *pconv, short cx, short cy, TModule* pResModule,
      TWindow* parent, LPSTR title = 0) :
    TFrameWindow(parent, title)
    {
      conv = pconv;
      cxChar = cx;
      cyChar = cy;
      pResourceModule = pResModule;

      Attr.H = cyChar * 22;
      Attr.W = cxChar * 60;
      Attr.Style = Attr.Style | WS_THICKFRAME | WS_SYSMENU;
    }

    void SetupWindow()
    {
      TFrameWindow::SetupWindow();

      char szTitle[100];
      pResourceModule -> LoadString(STR_LOCALETITLE, szTitle, 100);
      SetCaption(szTitle);
    }

    // Called by the parent after the language or locale has been changed to keep
    // us in synch
    void ResetValues(lconv *pconv, short cx, short cy, TModule* pResModule)
    {
      conv = pconv;
      cxChar = cx;
      cyChar = cy;
      pResourceModule = pResModule;
      char szTitle[100];
      pResourceModule -> LoadString(STR_LOCALETITLE, szTitle, 100);
      SetCaption(szTitle);
    }

    virtual void Paint(TDC&, BOOL, TRect&);

  protected:
    int max(int a, int b)
    {
      if (a > b)
        return a;
      return b;
    }

    void EvClose()
    {
      // Tell the parent that we're finished.
      Parent -> SendMessage(WM_VALWNDCLOSE, 0, 0);
      TFrameWindow::EvClose();
    }

  private:
    TModule* pResourceModule;
    short cxChar, cyChar;
    lconv *conv;

  DECLARE_RESPONSE_TABLE(TLocaleValueWindow);
};

DEFINE_RESPONSE_TABLE1(TLocaleValueWindow, TFrameWindow)
   EV_WM_CLOSE,
END_RESPONSE_TABLE;


void TLocaleValueWindow::Paint(TDC& hdc, BOOL, TRect&)
{
  short t, i;
  char buf[100];
  int maxWidth = 0;
  char yesStr[10], noStr[10];

  hdc.SelectStockObject ( SYSTEM_FIXED_FONT );

  hdc.SetTextColor(RGB(0, 0, 255));

  for (t = STR_DECIMALPOINT, i = 1; t <= STR_N_SIGN_POSN; t++, i++)
  {
   pResourceModule -> LoadString(t, buf, 100);
   hdc.TextOut(cxChar + 10, cyChar * i, buf,strlen(buf));
   maxWidth = max(maxWidth, strlen(buf));
  }

  pResourceModule -> LoadString(STR_YES, yesStr, 9);
  pResourceModule -> LoadString(STR_NO, noStr, 9);

  hdc.SetTextColor(RGB(255, 0, 0));
  maxWidth *= cxChar;
  maxWidth += (5 * cxChar);
  i = 1;
  hdc.TextOut(maxWidth, cyChar * (i ++), conv -> decimal_point, strlen(conv -> decimal_point));
  hdc.TextOut(maxWidth, cyChar * (i ++), conv -> thousands_sep, strlen(conv -> thousands_sep));
  sprintf(buf, "%d", *conv -> grouping);
  hdc.TextOut(maxWidth, cyChar * (i ++), buf, strlen(buf));
  hdc.TextOut(maxWidth, cyChar * (i ++), conv -> int_curr_symbol, strlen(conv -> int_curr_symbol));
  hdc.TextOut(maxWidth, cyChar * (i ++), conv -> currency_symbol, strlen(conv -> currency_symbol));
  hdc.TextOut(maxWidth, cyChar * (i ++), conv -> mon_decimal_point, strlen(conv ->  mon_decimal_point));
  hdc.TextOut(maxWidth, cyChar * (i ++), conv -> mon_thousands_sep, strlen(conv ->  mon_thousands_sep));
  sprintf(buf, "%d", *conv -> mon_grouping);
  hdc.TextOut(maxWidth, cyChar * (i ++), buf, strlen(buf));
  hdc.TextOut(maxWidth, cyChar * (i ++), conv -> positive_sign, strlen(conv ->  positive_sign));
  hdc.TextOut(maxWidth, cyChar * (i ++), conv -> negative_sign, strlen(conv -> negative_sign));

  sprintf(buf, "%d", conv -> int_frac_digits);
  hdc.TextOut(maxWidth, cyChar * (i ++), buf, strlen(buf));
  sprintf(buf, "%d", conv -> frac_digits);
  hdc.TextOut(maxWidth, cyChar * (i ++), buf, strlen(buf));

  char scratch[10];
  sprintf(buf, "%s", (conv -> p_cs_precedes == CHAR_MAX) ? itoa(CHAR_MAX, scratch, 10) :
   (conv -> p_cs_precedes == 1) ? yesStr : noStr);
  hdc.TextOut(maxWidth, cyChar * (i ++), buf, strlen(buf));
  sprintf(buf, "%s", (conv -> p_sep_by_space == CHAR_MAX) ? itoa(CHAR_MAX, scratch, 10) :
   (conv -> p_sep_by_space == 1) ? yesStr : noStr);
  hdc.TextOut(maxWidth, cyChar * (i ++), buf, strlen(buf));
  sprintf(buf, "%s", (conv -> n_cs_precedes == CHAR_MAX) ? itoa(CHAR_MAX, scratch, 10) :
   (conv -> n_cs_precedes == 1) ? yesStr : noStr);
  hdc.TextOut(maxWidth, cyChar * (i ++), buf, strlen(buf));
  sprintf(buf, "%s", (conv -> n_sep_by_space == CHAR_MAX) ? itoa(CHAR_MAX, scratch, 10) :
   (conv -> n_sep_by_space == 1) ? yesStr : noStr);
  hdc.TextOut(maxWidth, cyChar * (i ++), buf, strlen(buf));
  sprintf(buf, "%d", conv -> p_sign_posn);
  hdc.TextOut(maxWidth, cyChar * (i ++), buf, strlen(buf));
  sprintf(buf, "%d", conv -> n_sign_posn);
  hdc.TextOut(maxWidth, cyChar * (i ++), buf, strlen(buf));
}

//----------------------------------------------------------------------------
// Main window, containing a display of all 256 ANSI chars highlighted according
// to the current classification function.
//
#define L_CHARSTRING 20

class TLocaleWindow : public TWindow
{
  public:
   TLocaleWindow(TWindow* parent = 0, const char* title = 0)
   : TWindow(parent, title)
   {
    Attr.Id = ID_LOCALEWINDOW;
    classification = alpha;
    classificationmacros[0] = isalnum;
    classificationmacros[1] = isalpha;
    classificationmacros[2] = isascii;
    classificationmacros[3] = iscntrl;
    classificationmacros[4] = isdigit;
    classificationmacros[5] = isgraph;
    classificationmacros[6] = islower;
    classificationmacros[7] = isprint;
    classificationmacros[8] = ispunct;
    classificationmacros[9] = isspace;
    classificationmacros[10] = isupper;
    classificationmacros[11] = isxdigit;

    strcpy(macronames[0], "isalnum()");
    strcpy(macronames[1], "isalpha()");
    strcpy(macronames[2], "isascii()");
    strcpy(macronames[3], "iscntrl()");
    strcpy(macronames[4], "isdigit()");
    strcpy(macronames[5], "isgraph()");
    strcpy(macronames[6], "islower()");
    strcpy(macronames[7], "isprint()");
    strcpy(macronames[8], "ispunct()");
    strcpy(macronames[9], "isspace()");
    strcpy(macronames[10], "isupper()");
    strcpy(macronames[11], "isxdigit()");
   }

   void SetupWindow()
   {
    TWindow::SetupWindow();
    TWindowDC dc(HWindow);
    dc.SelectStockObject(SYSTEM_FIXED_FONT);
    TEXTMETRIC tm;
    dc.GetTextMetrics (tm);
    cxChar = tm.tmAveCharWidth;
    cyChar = tm.tmHeight + tm.tmExternalLeading;
    SetFocus();
   }

   enum classifications {alnum = CM_ISALNUM, alpha, ascii, cntrl, digit, graph, lower, print, punct, space, upper, xdigit};

   int ChangeClassification(classifications newClassification)
   {
    CheckMenuItem(Parent -> GetMenu(), classification, MF_UNCHECKED);
    classification = newClassification;
    CheckMenuItem(Parent -> GetMenu(), classification, MF_CHECKED);

    Invalidate(TRUE);
    return 0;
   }

   void ChangeUI(TModule *pResModule)
   {
    CheckMenuItem(Parent -> GetMenu(), classification, MF_CHECKED);
    pResModule -> LoadString(STR_CHARACTER, characterString, L_CHARSTRING);
   }

   void EvMouseMove(UINT /*modKeys*/, TPoint &point)
   {
    char buf[50];
    point.x -= boxTopLeft.x;
    point.y -= boxTopLeft.y;
    if (((point.x > 0) && (point.x < boxBottomRight.x - 4))
      && ((point.y > 0) && (point.y < boxBottomRight.y)))
    {
      int ch = (((point.y / cellHeight) * 16) + (point.x /cellWidth));
      sprintf(buf, "%s %4d  :  %4c  :  %#x", characterString, ch, (ch == 0) ? 1 : ch, ch, ch);
    }
    else
    {
      buf[0] = 0;
    }
    TYPESAFE_DOWNCAST(Parent -> ChildWithId(IDW_STATUSBAR), TStatusBar)->SetText(buf);
   }

   void CMIsAlnum()
   {
    if (classification != alnum)
      ChangeClassification(alnum);
   }

   void CMIsAlpha()
   {
    if (classification != alpha)
      ChangeClassification(alpha);
   }

   void CMIsAscii()
    {
      if (classification != ascii)
        ChangeClassification(ascii);
    }

    void CMIsCntrl()
    {
      if (classification != cntrl)
        ChangeClassification(cntrl);
    }

    void CMIsDigit()
    {
      if (classification != digit)
        ChangeClassification(digit);
    }

    void CMIsGraph()
    {
      if (classification != graph)
        ChangeClassification(graph);
    }

    void CMIsLower()
    {
      if (classification != lower)
        ChangeClassification(lower);
    }

    void CMIsPrint()
    {
      if (classification != print)
        ChangeClassification(print);
    }

    void CMIsPunct()
    {
      if (classification != punct)
        ChangeClassification(punct);
    }

    void CMIsSpace()
    {
      if (classification != space)
        ChangeClassification(space);
    }

    void CMIsUpper()
    {
      if (classification != upper)
        ChangeClassification(upper);
    }

    void CMIsXDigit()
    {
      if (classification != xdigit)
      ChangeClassification(xdigit);
   }

   virtual void Paint(TDC&, BOOL, TRect&);

  protected:
   int trueColor(TDC& hdc)
   // Sets colour to display characters for which the classification function
   // returns TRUE
   {
    hdc.SetTextColor(RGB(255, 0, 255));
    hdc.SetBkColor(RGB(0, 220, 0));
    return 0;
   }

   int falseColor(TDC& hdc)
   // Sets colour to display characters for which the classification function
   // returns FALSE
   {
    hdc.SetTextColor(RGB(200, 200, 200));
    hdc.SetBkColor(RGB(255, 255, 255));
    return 0;
   }

  private:
   classifications classification;
   short cxChar, cyChar;
   int (*classificationmacros[12])(int);
   int cellWidth, cellHeight;
   char macronames[12][12];
   TPoint boxTopLeft, boxBottomRight;
   char characterString[L_CHARSTRING];

  DECLARE_RESPONSE_TABLE(TLocaleWindow);
};

DEFINE_RESPONSE_TABLE1(TLocaleWindow, TWindow)
  EV_WM_MOUSEMOVE,
  EV_COMMAND(CM_ISALNUM, CMIsAlnum),
  EV_COMMAND(CM_ISALPHA, CMIsAlpha),
  EV_COMMAND(CM_ISASCII, CMIsAscii),
  EV_COMMAND(CM_ISCNTRL, CMIsCntrl),
  EV_COMMAND(CM_ISDIGIT, CMIsDigit),
  EV_COMMAND(CM_ISGRAPH, CMIsGraph),
  EV_COMMAND(CM_ISLOWER, CMIsLower),
  EV_COMMAND(CM_ISPRINT, CMIsPrint),
  EV_COMMAND(CM_ISPUNCT, CMIsPunct),
  EV_COMMAND(CM_ISSPACE, CMIsSpace),
  EV_COMMAND(CM_ISUPPER, CMIsUpper),
  EV_COMMAND(CM_ISXDIGIT, CMIsXDigit),
END_RESPONSE_TABLE;

void TLocaleWindow::Paint(TDC& hdc, BOOL, TRect&)
{
  char buf[100];
  int maxWidth = 0;

  hdc.SelectStockObject(SYSTEM_FIXED_FONT);

  hdc.SetTextColor(RGB(0, 0, 0));
  hdc.TextOut((30 * cxChar), (cyChar / 2), macronames[classification - alnum], strlen(macronames[classification - CM_ISALNUM]));
  maxWidth = (10 * cxChar);

  #define COLUMNS 16
  #define ROWS 16

  char hexChars[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

  //Display the codepoint values around the character set.
  for (int i = 0; i < ROWS; i++)
 {
   sprintf(buf, "%c", hexChars[i]);
   hdc.TextOut(maxWidth + ((i * 3) * cxChar), cyChar * 2 , buf, 1);
   hdc.TextOut((maxWidth - (3 * cxChar)), cyChar * (i + 3), buf, 1);
 }

  // display the character set in a ROWS x COLUMNS grid, with colours set by
  // trueColor() and falseColor() according to the return value of the current
  // classification function.
  for (i = 0; i < ROWS; i++)
   for (int j = 0; j < COLUMNS; j++)
   {
    int c = ((i * COLUMNS) + j);
    sprintf(buf, "%c",  c);
    classificationmacros[classification - alnum](c) ? trueColor(hdc) : falseColor(hdc);
    if (c < 256) // in case we use different values for row/column.
      hdc.TextOut(maxWidth + ((j * 3) * cxChar), cyChar * (i + 3), buf, 1);
   }


  // Draw a box round the characters.
  #define X1  (maxWidth - 6)
  #define Y1  ((3 * cyChar) - 2)
  #define X2  ((maxWidth - 2) + (cxChar * (COLUMNS * 3)))
  #define Y2  (((3 * cyChar) - 2) + (cyChar  * ROWS))

  boxTopLeft.x = X1;
  boxTopLeft.y = Y1;
  boxBottomRight.x = X2 - X1;
  boxBottomRight.y = Y2 - Y1;

  cellWidth = (boxBottomRight.x / COLUMNS);
  cellHeight = (boxBottomRight.y / ROWS);

  hdc.SelectObject(CreatePen(PS_SOLID, 1, RGB(0, 127, 127)));

  hdc.MoveTo(X1, Y1);
  hdc.LineTo(X1, Y2);
  hdc.LineTo(X2, Y2);
  hdc.LineTo(X2, Y1);
  hdc.LineTo(X1, Y1);

  for (i = 0; i < ROWS; i++)
  {
   hdc.MoveTo(X1, Y1 + (i * cyChar));
   hdc.LineTo(X2, Y1 + (i * cyChar));
  }

  for (i = 0; i < COLUMNS; i++)
  {
   hdc.MoveTo(X1 + ((i * 3) * cxChar), Y1);
   hdc.LineTo(X1 + ((i * 3) * cxChar), Y2);
  }
  hdc.RestorePen();
}


//----------------------------------------------------------------------------
//
//
//
class TLocaleFrame : public TDecoratedFrame
{
   enum languages {langEnglish = CM_LANGUAGEENGLISH, langFrench, langGerman};
   enum locales {locC = CM_LOCALEC, locUS, locUK, locFrench, locGerman};

  public:
   TLocaleFrame(TWindow* client)
   :TDecoratedFrame((TWindow*)0, (char*)0, client, TRUE)
   {
    pResourceModule = new TModule("APIENG.DLL");
    tMenu = new TMenu(pResourceModule -> LoadMenu("MAINMENU"), AutoDelete);
    valueWin = 0;
    if (!HMENU(*tMenu))
      throw "Error loading menu";

    locale = locC;
    language = langEnglish;

    TWindowDC dc(HWindow);
    dc.SelectStockObject(SYSTEM_FIXED_FONT);
    TEXTMETRIC tm;
    dc.GetTextMetrics (tm);
    cxChar = tm.tmAveCharWidth;
    cyChar = tm.tmHeight + tm.tmExternalLeading;
    Attr.H = (cyChar * 25);
    Attr.W = (cxChar * 80);
   }

   virtual ~TLocaleFrame()
   {
    delete tMenu;
    delete pResourceModule;
   }

   void SetupWindow()
   {
    TDecoratedFrame::SetupWindow();


    char szTitle[100];
    pResourceModule -> LoadString(STR_APPNAME, szTitle, 100);
    SetCaption(szTitle);
    SetMenu(*tMenu);
    tMenu -> CheckMenuItem(locale, MF_CHECKED);
    tMenu -> CheckMenuItem(language, MF_CHECKED);
    TYPESAFE_DOWNCAST(GetClientWindow(), TLocaleWindow) -> ChangeUI(pResourceModule);
    conv = localeconv();
   }

   void EvEnterIdle(UINT source, HWND hWndDlg)
   {
    //TDecoratedFrame::EvEnterIdle loads the help hint string, so
    // we change the instance here so it gets it from pResourceModule
    TModule* module = GetModule();
    SetModule(pResourceModule);
    TDecoratedFrame::EvEnterIdle(source, hWndDlg);
    SetModule(module);
   }

   void CMEnglishLanguage()
   {
    ChangeUI("apieng.dll", "English", langEnglish, LANG_ENGLISH);
   }

   void CMFrenchLanguage()
   {
    ChangeUI("apifra.dll", "French", langFrench, LANG_FRENCH);
   }

   void CMGermanLanguage()
   {
    ChangeUI("apiger.dll", "German", langGerman, LANG_GERMAN);
   }


   void CMFileList()
   {
    TFileListDialog(this, pResourceModule).Execute();
   }

   void CMCLocale()
   {
    if (locale != locC)
      ChangeLocale(LC_ALL, "C", locC);
   }

   void CMUSLocale()
   {
    if (locale != locUS)
      ChangeLocale(LC_ALL, "en_US.WIN1252", locUS);
   }

   void CMUKLocale()
   {
    if (locale != locUK)
      ChangeLocale(LC_ALL, "en_GB.WIN1252", locUK);
   }

   void CMFrenchLocale()
   {
    if (locale != locFrench)
      ChangeLocale(LC_ALL, "fr_FR.WIN1252", locFrench);
   }

   void CMGermanLocale()
   {
    if (locale != locGerman)
      ChangeLocale(LC_ALL, "de_DE.WIN1252", locGerman);
   }

   void CMShowValues()
   {
    if (!valueWin)
    {
      valueWin = new TLocaleValueWindow(conv, cxChar,
       cyChar, pResourceModule, this);

      valueWin -> Create();
      valueWin -> Show(SW_SHOW);
    }
    else
      valueWin -> SetFocus();
   }

   LRESULT WMValWndClose(WPARAM, LPARAM)
   {
    valueWin = 0;
    return 0;
   }

  protected:
   int ChangeUI(char* DLLName, char* langName, languages newLanguage, UINT countryCode)
   {
    delete pResourceModule;
    pResourceModule = new TModule(DLLName);
    delete tMenu;
    tMenu = new TMenu(pResourceModule -> LoadMenu("MAINMENU"), AutoDelete);
    SetMenu(*tMenu);
    tMenu -> CheckMenuItem(locale, MF_CHECKED);
    TYPESAFE_DOWNCAST(GetClientWindow(), TLocaleWindow) -> ChangeUI(pResourceModule);

    char szTitle[100];
    pResourceModule -> LoadString(STR_APPNAME, szTitle, 100);
    SetCaption(szTitle);

    Invalidate(TRUE);
    RedrawValueWindow();
    tMenu -> CheckMenuItem(language, MF_UNCHECKED);
    language = newLanguage;
    tMenu -> CheckMenuItem(language, MF_CHECKED);
    BWCCIntlTerm();
    BWCCIntlInit(countryCode);
    return 1;
   }

   char *ChangeLocale(int category, char *localeType, locales newLocale)
   {
    tMenu -> CheckMenuItem(locale, MF_UNCHECKED);
    locale = newLocale;
    tMenu -> CheckMenuItem(locale, MF_CHECKED);

    char *c = setlocale(category, localeType);
    conv = localeconv();
    Invalidate(TRUE);
    RedrawValueWindow();
    ChildWithId(ID_LOCALEWINDOW) -> Invalidate(TRUE);
    return c;
   }

   void RedrawValueWindow()
   {
    if (valueWin)
    {
      valueWin -> ResetValues(conv, cxChar,
       cyChar, pResourceModule);
      valueWin -> Invalidate(TRUE);
    }
   }

  private:
   languages language;
   locales   locale;
   TModule*  pResourceModule;
   TMenu*    tMenu;
   TLocaleValueWindow* valueWin;
   short     cxChar, cyChar, scrX, scrY;
   lconv*    conv;

  DECLARE_RESPONSE_TABLE(TLocaleFrame);
};

DEFINE_RESPONSE_TABLE1(TLocaleFrame, TDecoratedFrame)
  EV_WM_ENTERIDLE,
  EV_COMMAND(CM_FILELIST, CMFileList),
  EV_COMMAND(CM_LOCALEC, CMCLocale),
  EV_COMMAND(CM_LOCALEUS, CMUSLocale),
  EV_COMMAND(CM_LOCALEUK, CMUKLocale),
  EV_COMMAND(CM_LOCALEFRENCH, CMFrenchLocale),
  EV_COMMAND(CM_LOCALEGERMAN, CMGermanLocale),
  EV_COMMAND(CM_LANGUAGEENGLISH, CMEnglishLanguage),
  EV_COMMAND(CM_LANGUAGEFRENCH, CMFrenchLanguage),
  EV_COMMAND(CM_LANGUAGEGERMAN, CMGermanLanguage),
  EV_COMMAND(CM_SHOWVALUES, CMShowValues),
  EV_MESSAGE(WM_VALWNDCLOSE, WMValWndClose),
END_RESPONSE_TABLE;


//----------------------------------------------------------------------------
//
//
//
class TLocaleApplication : public TApplication
{
  public:
   TLocaleApplication():TApplication("Intl demo program")
   {
   }

   void InitMainWindow()
   {
    try
    {
      TLocaleFrame* frame = new TLocaleFrame(new TLocaleWindow);
      TStatusBar* sb = new TStatusBar(frame, TGadget::Recessed);
      frame->Insert(*sb, TDecoratedFrame::Bottom);
      MainWindow = frame;
        MainWindow->SetIcon(this, "World_Icon");
        EnableBWCC(TRUE, LANG_ENGLISH);
      }
      catch(const char *s)
      {
        BWCCMessageBox(0, s, "Intldemo", MB_OK);
      }
    }
};

int OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TLocaleApplication().Run();
}
