//----------------------------------------------------------------------------
//  Project Shell
//  Borland International
//  Copyright © 1995, 1996 Borland International. All Rights Reserved.
//
//  SUBSYSTEM:    shell.exe Application
//  FILE:         shellwin.cpp
//  AUTHOR:       The OWL Team
//
//  OVERVIEW
//  ~~~~~~~~
//  Source file for implementation of TShellWindow (TWindow).
//
//----------------------------------------------------------------------------

#include <owl/pch.h>

#include "shellapp.h"
#include "mdichild.h"
#include "mdiclien.h"
#include "shellwin.h"

#include <stdio.h>


//{{TShellWindow Implementation}}


//
// Build a response table for all messages/commands handled
// by TShellWindow derived from TWindow.
//
DEFINE_RESPONSE_TABLE1(TShellWindow, TWindow)
//{{ShellWindowRSP_TBL_BEGIN}}
  EV_WM_CREATE,
  EV_WM_GETMINMAXINFO,
  EV_WM_SIZE,
  EV_WM_LBUTTONUP,
  EV_WM_RBUTTONUP,
  EV_WM_LBUTTONDBLCLK,
  EV_WM_CHAR,
//{{ShellWindowRSP_TBL_END}}
END_RESPONSE_TABLE;


//--------------------------------------------------------
// TShellWindow
// ~~~~~~~~~~~
// Construction/Destruction handling.
//
TShellWindow::TShellWindow(TWindow* parent, TShellItem* item,
  const char far* title, TModule* module)
:
  TWindow(parent, title, module),
  ItemGrids(0), ClientRectWidth(0), ItemsPerRow(0), SelectedItem(-1)
{
  if (item)
    Folder = TShellItem(*item);
  else
    Folder = TShellItem(TShellItem::Desktop);

  ItemGrids = new TArray<ItemGrid>(10, 0, 10);
}

TShellWindow::~TShellWindow()
{
  Destroy();
  delete ItemGrids;
}


//
// Paint routine for Window, Printer, and PrintPreview for an TWindow client.
//
void TShellWindow::Paint(TDC& dc, bool, TRect& rect)
{
  TShellApp* theApp = TYPESAFE_DOWNCAST(GetApplication(), TShellApp);
  if (theApp) {
    LOGFONT logFont;
    SystemParametersInfo(SPI_GETICONTITLELOGFONT, sizeof (logFont), &logFont, 0);
    TFont font(&logFont);
    dc.SelectObject(font);
    TShellItem item;
    ComputeItemGrids();
    int cnt = 0;
    for (TArrayIterator<ItemGrid> i(*ItemGrids); i; i++, cnt++)
      if (i.Current().Grid.Touches(rect)) {
        item = *CONST_CAST(TShellItem*, &i.Current().Item);
        dc.DrawIcon(i.Current().IconPt, item.GetIcon());
        DrawIconTitle(dc, item.GetDisplayName(), i.Current().TitlePt.x,
                      i.Current().TitlePt.y, i.Current().Grid.Width());
        if (SelectedItem == cnt)
          dc.InvertRect(i.Current().Grid);
      }
  }
}

void TShellWindow::ComputeItemGrids()
{
  if (!ClientRectWidth || ClientRectWidth != GetClientRect().Width()) {
    ClientRectWidth = GetClientRect().Width();
    int iconWidth  = ::GetSystemMetrics(SM_CXICON);
    int iconHeight = ::GetSystemMetrics(SM_CYICON);
    int gridWidth  = ::GetSystemMetrics(SM_CXICONSPACING);
    int gridHeight = ::GetSystemMetrics(SM_CYICONSPACING);

    int x = IconSpacingX;
    int y = IconSpacingY;
    ItemGrids->Flush();
    TShellItem item;
    for (TShellItemIterator i(Folder, *this,
         TShellItemIterator::Folders | TShellItemIterator::NonFolders);
         i.Valid(); x += gridWidth + IconSpacingX) {
      item = i++;
      if (x + gridWidth > ClientRectWidth) {
        x = IconSpacingX;
        y += gridHeight + IconSpacingY;
      }
      ItemGrids->Add(ItemGrid(item, TRect(TPoint(x, y), TSize(gridWidth, gridHeight)),
                     TPoint(x+((gridWidth-iconWidth)/2), y), TPoint(x, y+iconHeight)));
    }
  }
}

void TShellWindow::DrawIconTitle(TDC& dc, TString& name, int x, int y, int gridWidth)
{
  int length = name.Length();

  TSize size = dc.GetTextExtent(name, length);
  if (size.cx <= gridWidth) {
	 dc.TextOut(x+(gridWidth - size.cx)/2, y, name);
	 return;
  }

  const char* begin = STATIC_CAST(const char*, name);
  const char* end = 0;
  const char* prevEnd;
  TEXTMETRIC metrics;
  dc.GetTextMetrics(metrics);
  int lineHeight = metrics.tmHeight + metrics.tmExternalLeading;

  for (int i = 0; i <= length; i++) {
	 if (STATIC_CAST(const char*, name)[i] == 0 || STATIC_CAST(const char*, name)[i] == ' ') {
		prevEnd = end;
		end = STATIC_CAST(const char*, name) + i - 1;
		size = dc.GetTextExtent(begin, end - begin + 1);
		if (size.cx > gridWidth) { // restore to previous and print
		  if (!prevEnd)   // no previous, just a word too long to fit
        DrawLongWord(dc, x, y, gridWidth, begin, end);
      else { // restore to previous and print
			 end = prevEnd;
			 i = end - STATIC_CAST(const char*, name) + 1;
			 size = dc.GetTextExtent(begin, end - begin + 1);
			 dc.TextOut(x+(gridWidth - size.cx)/2, y, begin, end - begin + 1);
		  }
		  y += lineHeight;
		  while (STATIC_CAST(const char*, name)[i] == ' ')
			 i++;
		  begin = STATIC_CAST(const char*, name) + i;
		  end = 0;
		}
	 }
  }
  size = dc.GetTextExtent(begin, ::strlen(begin));
		if (size.cx > gridWidth) {
      end = begin + ::strlen(begin) - 1;
      DrawLongWord(dc, x, y, gridWidth, begin, end);
    }
    else
      dc.TextOut(x+(gridWidth - size.cx)/2, y, begin);
}

void TShellWindow::DrawLongWord(TDC& dc, int x, int y, int gridWidth, const char* begin, const char* end)
{
  TSize size;

  // word is too long, print with ellipse
  char* longWord = new char[end - begin + 4];
  ::strncpy(longWord, begin, end - begin + 1);
  longWord[end - begin + 1] = 0;
  int length = ::strlen(longWord);
  int j = 0;
  do {
    ::strcpy(longWord + length - ++j, "..."); // knock off 1 char
    size = dc.GetTextExtent(longWord, ::strlen(longWord));
  } while (size.cx > gridWidth);
  dc.TextOut(x+(gridWidth - size.cx)/2, y, longWord);
}

void TShellWindow::DisplayProperties(TShellItem& item)
{
  char* exeTypeStr[] = {"NonExecutable",
                        "WindowsNE",
                        "WindowsPE",
                        "MSDOS",
                        "Win32Console"};
  char msg[1024];

  ::strcpy(msg,   "Full Name:  ");
  ::strcat(msg, item.GetDisplayName(TShellItem::ForParsing));
  ::strcat(msg, "\nTypename:  ");
  ::strcat(msg, item.GetTypeName());
  ::strcat(msg, "\nExeType:  ");
  uint major, minor;
  TShellItem::TExeKind exeKind = item.GetExeType(&major, &minor);
  ::strcat(msg, exeTypeStr[exeKind]);
  if (exeKind != TShellItem::NonExecutable) {
    char cMajor[10];
    char cMinor[10];
    ::wsprintf(cMajor, "%u", major);
    ::wsprintf(cMinor, "%u", minor);
    ::strcat(msg, ", Version = ");
    ::strcat(msg, cMajor);
    ::strcat(msg, ".");
    ::strcat(msg, cMinor);
  }
  ::strcat(msg, "\nCanBeCopied?  ");
  ::strcat(msg, (item.CanBeCopied())? "Yes": "No");
  ::strcat(msg, "\nCanBeDeleted?  ");
  ::strcat(msg, (item.CanBeDeleted())? "Yes": "No");
  ::strcat(msg, "\nCanCreateShortcut?  ");
  ::strcat(msg, (item.CanCreateShortcut())? "Yes": "No");
  ::strcat(msg, "\nCanBeMoved?  ");
  ::strcat(msg, (item.CanBeMoved())? "Yes": "No");
  ::strcat(msg, "\nCanBeRenamed?  ");
  ::strcat(msg, (item.CanBeRenamed())? "Yes": "No");
  ::strcat(msg, "\nIsADropTarget?  ");
  ::strcat(msg, (item.IsADropTarget())? "Yes": "No");
  ::strcat(msg, "\nHasAPropertySheet?  ");
  ::strcat(msg, (item.HasAPropertySheet())? "Yes": "No");
  ::strcat(msg, "\nDisplayGhosted?  ");
  ::strcat(msg, (item.DisplayGhosted())? "Yes": "No");
  ::strcat(msg, "\nIsShortcut?  ");
  ::strcat(msg, (item.IsShortcut())? "Yes": "No");
  if (item.IsShortcut()) {
    TShellItem resolvedItem = item.ResolveShortcut(*this);
    ::strcat(msg, ", resolves to:  ");
    ::strcat(msg, resolvedItem.GetDisplayName(TShellItem::ForParsing));
  }
  ::strcat(msg, "\nIsReadOnly?  ");
  ::strcat(msg, (item.IsReadOnly())? "Yes": "No");
  ::strcat(msg, "\nIsShared?  ");
  ::strcat(msg, (item.IsShared())? "Yes": "No");
  ::strcat(msg, "\nContainsSubFolder?  ");
  ::strcat(msg, (item.ContainsSubFolder())? "Yes": "No");
  ::strcat(msg, "\nContainsFileSystemFolder?  ");
  ::strcat(msg, (item.ContainsFileSystemFolder())? "Yes": "No");
  ::strcat(msg, "\nIsPartOfFileSystem?  ");
  ::strcat(msg, (item.IsPartOfFileSystem())? "Yes": "No");
  ::strcat(msg, "\nIsFolder?  ");
  ::strcat(msg, (item.IsFolder())? "Yes": "No");
  ::strcat(msg, "\nCanBeRemoved?  ");
  ::strcat(msg, (item.CanBeRemoved())? "Yes": "No");
  ::strcat(msg, "\nIsDesktop?  ");
  ::strcat(msg, (item.IsDesktop())? "Yes": "No");
  MessageBox(msg, item.GetDisplayName(), MB_OK | MB_ICONINFORMATION);
}

int TShellWindow::ComputeItemsPerRow()
{
  int gridWidth  = ::GetSystemMetrics(SM_CXICONSPACING);
  int x = IconSpacingX;
  int count = 0;

  while (x + gridWidth <= GetClientRect().Width()) {
    count++;
    x += gridWidth + IconSpacingX;
  }
  return count;
}

void TShellWindow::OpenExec()
{
  TShellItem item = *CONST_CAST(TShellItem*, &(*ItemGrids)[SelectedItem].Item);

  // if we're working with a shortcut to a folder, switch to underlying if it's a folder
  if (item.IsShortcut()) {
    TShellItem resolvedItem = item.ResolveShortcut(*this);
    if (resolvedItem.IsFolder())
      item = resolvedItem;
  }
  if (item.IsFolder() || item.ContainsSubFolder())
    TYPESAFE_DOWNCAST(GetApplication()->GetMainWindow()->GetClientWindow(), TShellMDIClient)->
      MyFileNew(&item);
  else {
    HINSTANCE inst = ShellExecute(0, 0, item.GetDisplayName(TShellItem::ForParsing),
                                  0, 0, SW_SHOWDEFAULT);
    if ((int)inst <= 32)
      // Houston, we have a problem
      DisplayShellExecuteError((int)inst, item.GetDisplayName(TShellItem::ForParsing));
  }
}

void TShellWindow::DisplayShellExecuteError(int error, const char* itemName)
{
  char msg[256];
  switch (error) {
    case 0:
      ::strcpy(msg, "The system is out of memory or resources.");
      break;
    case ERROR_FILE_NOT_FOUND:
      ::strcpy(msg, "The specified file was not found.");
      break;
    case ERROR_PATH_NOT_FOUND:
      ::strcpy(msg, "The specified path was not found.");
      break;
    case ERROR_BAD_FORMAT:
      ::strcpy(msg, "The .EXE file is invalid (non-Win32 .EXE or error "
               "in .EXE image).");
      break;
    case SE_ERR_ASSOCINCOMPLETE:
      ::strcpy(msg, "The filename association is incomplete or invalid.");
      break;
    case SE_ERR_DDEBUSY:
      ::strcpy(msg, "The DDE transaction could not be completed because "
               "other DDE transactions were being processed.");
      break;
    case SE_ERR_DDEFAIL:
      ::strcpy(msg, "The DDE transaction failed.");
      break;
    case SE_ERR_DDETIMEOUT:
      ::strcpy(msg, "The DDE transaction could not be completed because "
               "the request timed out.");
      break;
    case SE_ERR_NOASSOC:
      ::strcpy(msg, "This file does not have a program associated with it "
               "for performing this action.  Create an association in "
               "My Computer by clicking View and then clicking Options.");
      break;
    case SE_ERR_SHARE:
      ::strcpy(msg, "A sharing violation occurred.");
      break;
    default:
      ::strcpy(msg, "Unkown error return code.");
  }
  // !JK MB_ICONERROR is >= Windows 4.0 only, if this causes a build problem
  //     change MB_ICONERROR to MB_ICONHAND
  MessageBox(msg, itemName, MB_OK | MB_ICONERROR);
}

int TShellWindow::EvCreate(CREATESTRUCT far &cs)
{
  GetParentO()->SetCaption(Folder.GetDisplayName());
  TYPESAFE_DOWNCAST(GetParentO(), TShellMDIChild)->SetIcon(Folder.GetIcon());
  TYPESAFE_DOWNCAST(GetParentO(), TShellMDIChild)->SetIconSm(Folder.GetIcon(TShellItem::Small));
  return TWindow::EvCreate(cs);
}

void TShellWindow::EvGetMinMaxInfo(MINMAXINFO far& minmaxinfo)
{
  TWindow::EvGetMinMaxInfo(minmaxinfo);
}

void TShellWindow::EvSize(uint sizeType, TSize& size)
{
  if (ClientRectWidth != GetClientRect().Width()) {
    if (!ClientRectWidth || ItemsPerRow != ComputeItemsPerRow()) {
      ItemsPerRow = ComputeItemsPerRow();
      Invalidate();
    }
  }
  TWindow::EvSize(sizeType, size);
}

void TShellWindow::EvLButtonUp(uint /*modKeys*/, TPoint& point)
{
  int cnt = 0;
  for (TArrayIterator<ItemGrid> i(*ItemGrids); i; i++, cnt++) {
    if (i.Current().Grid.Contains(point)) {
      TShellItem item = *CONST_CAST(TShellItem*, &i.Current().Item);
      if (SelectedItem != cnt) {
        if (SelectedItem != -1)
          InvalidateRect((*ItemGrids)[SelectedItem].Grid);
        SelectedItem = cnt;
        InvalidateRect((*ItemGrids)[SelectedItem].Grid);
      }
      return;
    }
  }
  if (SelectedItem != -1) {
    InvalidateRect((*ItemGrids)[SelectedItem].Grid);
    SelectedItem = -1;
  }
}

void TShellWindow::EvRButtonUp(uint /*modKeys*/, TPoint& point)
{
  int cnt = 0;
  for (TArrayIterator<ItemGrid> i(*ItemGrids); i; i++, cnt++) {
    if (i.Current().Grid.Contains(point)) {
      TShellItem item = *CONST_CAST(TShellItem*, &i.Current().Item);
      if (SelectedItem != cnt) {
        if (SelectedItem != -1)
          InvalidateRect((*ItemGrids)[SelectedItem].Grid);
        SelectedItem = cnt;
        InvalidateRect((*ItemGrids)[SelectedItem].Grid);
      }
      DisplayProperties(item);
      return;
    }
  }
  if (SelectedItem != -1) {
    InvalidateRect((*ItemGrids)[SelectedItem].Grid);
    SelectedItem = -1;
  }
  DisplayProperties(Folder);
}

void TShellWindow::EvLButtonDblClk(uint /*modKeys*/, TPoint& /*point*/)
{
  if (SelectedItem != -1)
    OpenExec();
}

void TShellWindow::EvChar(uint key, uint repeatCount, uint flags)
{
  if (key == ' ' || key == '\r') {
    if (SelectedItem != -1)
      OpenExec();
    }
  else
    TWindow::EvChar(key, repeatCount, flags);
}

