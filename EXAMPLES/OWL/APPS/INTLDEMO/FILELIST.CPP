//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1996 by Borland International
//   filelist.cpp
//----------------------------------------------------------------------------
#include <owl\pch.h>
#include <owl\dialog.h>
#include <owl\dc.h>
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
#include <cstring.h>
#include <bwcc.h>

#include "intldemo.h"
#include "filelist.h"

char* formatVal(char*, long);

//
//  class TFileViewer
//  ----- -----------
//
//  TFileView displays up to 100 chars of each of the first 100 lines
//  of a file in a listbox. Allows sorting by lines.
//
class TFileViewer : public TDialog {
  public:
    TFileViewer(TWindow* parent, TModule* module, char* fileName, TResId resourceId = ID_FILEVIEWER);
    ~TFileViewer();

  protected:
    void CmSort(uint);
    void SetupWindow();
    enum {maxLines = 100, maxLineLength = 100};
    TListBox* ListBox;
    TIArrayAsVector<string> Unsorted;
    TISArrayAsVector<string> Sorted;
    char* Caption;

  DECLARE_RESPONSE_TABLE(TFileViewer);
};

DEFINE_RESPONSE_TABLE1(TFileViewer, TDialog)
  EV_CHILD_NOTIFY_ALL_CODES(ID_SORTBUT, CmSort),
END_RESPONSE_TABLE;

TFileViewer::TFileViewer(TWindow* parent, TModule* module, char* fileName, TResId resourceId)
  : TDialog(parent, resourceId, module),
	 Unsorted(maxLines), Sorted(maxLines)
{
  Sorted.OwnsElements(0); // strings belong to both Sorted and Unsorted arrays
									  // only one container should delete the strings
  Caption = 0;

  int lines = 0;
  ifstream inputFile(fileName);
  if (!inputFile.fail()) {
    Caption = new char [strlen(fileName)+1];
    strcpy(Caption, fileName);
    while(!inputFile.eof() && lines++ < maxLines) {
    char buf[maxLineLength];
    inputFile.get(buf, sizeof(buf) - 1);
    string* s = new string(buf);
    Unsorted.Add(s);
    Sorted.Add(s);
    // if we're not at the end of the line, try to jump to the next line
    if (inputFile.get() != '\n')
      inputFile.ignore(100, '\n');
    }
    inputFile.close();
  }
  ListBox = new TListBox(this, ID_FILELISTBOX, module);
}

TFileViewer::~TFileViewer()
{
  if (Caption)
    delete [] Caption;
}

void TFileViewer::SetupWindow()
{
  TDialog::SetupWindow();
  SetCaption(Caption);
  for (int i = 0; i < Unsorted.GetItemsInContainer(); i++) {
    ListBox->AddString(Unsorted[i]->c_str());
  }
}

void TFileViewer::CmSort(uint)
{
  ListBox->ClearList();
  for (int i = 0; i < Sorted.GetItemsInContainer(); i++) {
    ListBox->AddString(Sorted[i]->c_str());
  }
  ListBox->SetSelIndex(0);
}

//
// class TDateTime
// ----- --------
//
// TDateTime is used to convert a file's date/time value into a struct tm.
//
class TDateTime {
  private:
    struct filetime
    {
    #if defined (__FLAT__)
      unsigned short ftime;
      unsigned short fdate;
    #else
      int ftime;
      int fdate;
    #endif
    };

    union dosfiletime
    {
      filetime ft;
      struct ftime ftime;
    };

    dosfiletime DosFileTime;
    struct date Date;
    struct time Time;

  public:
    TDateTime(int ftime, int fdate);
    struct tm* tmvalue();
};

#pragma warn -sig
TDateTime::TDateTime(int ftime, int fdate)
{
  DosFileTime.ft.ftime = ftime;
  DosFileTime.ft.fdate = fdate;

  Time.ti_sec  = DosFileTime.ftime.ft_tsec * 2;
  Time.ti_min  = DosFileTime.ftime.ft_min;
  Time.ti_hour = DosFileTime.ftime.ft_hour;
  Time.ti_hund = 0;

  Date.da_day  = DosFileTime.ftime.ft_day;
  Date.da_mon  = DosFileTime.ftime.ft_month;
  Date.da_year = DosFileTime.ftime.ft_year + 1980;
}
#pragma warn +sig

struct tm* TDateTime::tmvalue()
{
  time_t t;
  t = dostounix(&Date, &Time);
  return localtime (&t);
}

//
// class TFileListBox
// ----- ------------
//
// TFileListBox is used to display file information.
// Note we are using our own sort functions rather than Windows'
// default sorting. This allows different instances of the program to
// demonstrate the different sorting/collating sequences of different locales.
//
class TFileListBox : public TListBox
{
  public:
    TFileListBox(TWindow* parent, int ResourceId, TModule* Module);
    void ToLower();
    void FillListBox();
    void GetDirList();
    void EvLButtonDblClk(uint, TPoint&);
    void Sort();
    void ChangeDir();
    void View();

  private:
    // Structure containing file information to be displayed in the
    // FileListBox.
    //
    struct FileRec
    {
      char name[13], datetime[100],  sizeStr[30];
      long fsize;
      unsigned long attrib;

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
    class TFileListFont : public TFont
    {
      private:
        int HeightInPixels(int pointSize)
        {
          TScreenDC  dc;
          return MulDiv(-pointSize, dc.GetDeviceCaps(LOGPIXELSY), 72);
        }

      public:
        TFileListFont() : TFont ("Courier New", HeightInPixels(8)) {}
    };

    int IsSorted;
    int NFiles;
    TIArrayAsVector<FileRec> FRArray;
    TISArrayAsVector<FileRec> SFRArray;
    enum cases {upper, lower};
    cases CurrCase;
    enum sorting {sorted, unsorted};
    sorting CurrSort;
    TModule* Module;
    TFileListFont Font;

  protected:
    void SetupWindow();

  DECLARE_RESPONSE_TABLE(TFileListBox);
};

DEFINE_RESPONSE_TABLE1(TFileListBox, TListBox)
   EV_WM_LBUTTONDBLCLK,
END_RESPONSE_TABLE;

TFileListBox::TFileListBox(TWindow* parent, int resourceId, TModule* module) :
      TListBox(parent, resourceId, module),
      FRArray(100, 0, 10), SFRArray(100, 0, 10), CurrCase(upper), CurrSort(unsorted)
{
  Module = module;
  SFRArray.OwnsElements(0);
}

void TFileListBox::SetupWindow()
{
  TListBox::SetupWindow();
  SetWindowFont(Font, 0);
  GetDirList();
  FillListBox();
  SetSelIndex(0);
}

void TFileListBox::Sort()
{
  CurrSort = (CurrSort == sorted) ? unsorted : sorted;
  char buf[MAXFILE + MAXEXT + 1];
  GetSelString(buf, sizeof(buf));
  FillListBox();
  SetSelString(buf, 0);
}

void TFileListBox::View()
{
  if (GetSelIndex() >= 0) {
    char buf[100];
    GetSelString(buf, sizeof(buf));

    if (strstr(buf, "<DIR>"))
      ChangeDir();
    else {
      char* s = strchr(buf, ' ');
      if (s)
        *s = 0;
      TFileViewer(Parent, Module, buf).Execute();
    }
  }
}


void TFileListBox::EvLButtonDblClk(uint, TPoint&)
{
  View();   // view the file or directory
}

void TFileListBox::GetDirList()
{
  SFRArray.Flush();
  FRArray.Flush();
  struct ffblk ffblk;
  struct tm* tm;
  TDateTime* dt;
  NFiles = 0;
  int done = findfirst("*.*", &ffblk, 0x3f);
  while (!done) {
    FileRec* f = new FileRec;
#if !defined (__FLAT__)
    OemToAnsiBuff(ffblk.ff_name, ffblk.ff_name, strlen(ffblk.ff_name));
#endif
    if (CurrCase == lower) {
      strlwr(ffblk.ff_name);
    }
    strncpy(f->name, ffblk.ff_name, 12);
    f->name[12] = '\0';
    dt = new TDateTime(ffblk.ff_ftime, ffblk.ff_fdate);
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
  if (GetSelString(buf, sizeof(buf)))
  {
    for (int i = 0; i < sizeof buf; i++)
      if (buf[i] == ' ') {
      buf[i] = 0;
      break;
      }
    if (!chdir(buf)) {
      GetDirList();
      FillListBox();
    }
  }
}

void TFileListBox::ToLower()
{
  int selection = GetSelIndex();
  if (CurrCase == upper) {
    for (int i = 0; i < FRArray.GetItemsInContainer(); i++)
      strlwr(FRArray[i]->name);
    CurrCase = lower;
    FillListBox();
  }
  else {
    for (int i = 0; i < FRArray.GetItemsInContainer(); i++)
      strupr(FRArray[i]->name);
    CurrCase = upper;
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
  switch(CurrSort)
  {
    case sorted:
      for (i = 0; i < SFRArray.GetItemsInContainer(); i++) {
        sprintf(s, lbformat, SFRArray[i]->name, SFRArray[i]->datetime,
          ((SFRArray[i]->attrib & FA_DIREC) ? ("<DIR>") : (SFRArray[i]->sizeStr)));
        AddString(s);
      }
      break;

    case unsorted:
      for (i = 0; i < FRArray.GetItemsInContainer(); i++) {
        sprintf(s, lbformat, FRArray[i]->name, FRArray[i]->datetime,
	        ((FRArray[i]->attrib & FA_DIREC) ? ("<DIR>") : (FRArray[i]->sizeStr)));
	      AddString(s);
      }
      break;
  }
  SetRedraw(TRUE);
}

TFileListDialog::TFileListDialog(TWindow* parent, TModule* Module, int ResourceId)
      :TDialog(parent, ResourceId, Module)
{
  char buf[MAXPATH];

  ListBox =  new TFileListBox(this, ID_FILELISTBOX, Module);
  ViewButton = new TButton(this, ID_VIEWBUTTON, Module);

  getcwd(buf, MAXPATH);
  StartDir = new char [strlen(buf)+1];
  strcpy(StartDir, buf);
}

TFileListDialog::~TFileListDialog()
{
  chdir(StartDir);
  delete [] StartDir;
}

void TFileListDialog::Sort(uint)
{
  ListBox->Sort();
}

void TFileListDialog::ToLower(uint)
{
  ListBox->ToLower();
}

void TFileListDialog::View(uint)
{
  ListBox->View();
}

void TFileListDialog::Help(uint)
{
}

DEFINE_RESPONSE_TABLE1(TFileListDialog, TDialog)
  EV_CHILD_NOTIFY_ALL_CODES(ID_SORTBUT, Sort),
  EV_CHILD_NOTIFY_ALL_CODES(ID_TOLOWERBUT, ToLower),
  EV_CHILD_NOTIFY_ALL_CODES(ID_VIEWBUTTON, View),
  EV_CHILD_NOTIFY_ALL_CODES(IDHELP, Help),
END_RESPONSE_TABLE;

char* formatVal(char* s, long l)
{
  lconv* conv = localeconv();
  sprintf(s, "%ld", l);

  int group = *conv->grouping;

  if (!group)
    return s; // no grouping info, quit

  int sLen = strlen(s);

  if (sLen <= group) // not enough chars to worry about.
    return s;

  int tempLen =  sLen + (sLen /3);
  if (!(int)fmod(sLen, 3))
    tempLen--;

  char tempStr[30];
  tempStr[tempLen--] = s[sLen--];

  while (sLen >= group) {
    int groupCount = 0;
    while (groupCount < group) {
      tempStr[tempLen--] = s[sLen--];
      groupCount++;
    }
    tempStr[tempLen--] = *(conv->thousands_sep);
  } 

  while (sLen >= 0)
    tempStr[tempLen--] = s[sLen--];

  strcpy(s, tempStr);

  return s;
}
