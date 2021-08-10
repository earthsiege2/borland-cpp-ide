/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  mpdenv.cpp
  Created: 10/24/95
  Copyright (c) 1995, Borland International
  $Revision:   1.16  $
    
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/ 

#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif

#pragma hdrstop

#include <owl\window.h>
#include <ideaddon\impd.h>
#include <ideaddon\iproj.h>
#include <windowsx.h> // this must come after iproj.h to avoid error

#include "tests.hrc"
#include "addonpg.h"

/******************************************************************************
*  This file contains 3 MPD page implementations.
*
*     AddonPageBase: The minimal page implementation.
*
*     CWindowPage:   A page that demonstrates how to implement
*                    various features of a MPD page
*
*     SubclassWindowPage: Demonstrates how to subclass a page.
*
******************************************************************************/

extern HINSTANCE ghInst;

/******************************************************************************
*
* AddonPageBase is the minimal implementation of a addon MPD page
*
******************************************************************************/

AddonPageBase::AddonPageBase()
                  :  IUnknownImp<IMpdPage> (IID_IUnknown) {
  d_modified = 0;
};


VOID AddonPageBase::Init(HWND hDlg, IStatusBar* isb) {
  d_statusBar = isb;
  d_hDlg = hDlg;
  d_modified = 0;
};

void AddonPageBase::SetStatusText(char* t) {
  IPolyString* pstr = MakePolyString(t);
  //
  // display the status text in MPD and IDE status bar
  //
  d_statusBar->Display(pstr);
};

BOOL AddonPageBase::IsModified() {
  return d_modified;
};

HINSTANCE AddonPageBase::GetHInstance() {
  return ghInst;
}

UINT AddonPageBase::GetResourceId() {
  return d_pageResource;
};

IPolyString*  AddonPageBase::GetPageTitle() {
  return MakePolyString(d_pageTitle);
};

UINT AddonPageBase::GetPageStyle() {
  return d_pageStyle;
};

void AddonPageBase::SetInfo(UINT pStyle, UINT pid, char* title) {
  d_pageResource = pid;
  d_pageStyle = pStyle;
  d_pageTitle = title;
};

void AddonPageBase::Help(BOOL fF1Key) {
  if (fF1Key) {
    ::MessageBox(NULL, "Help on example page", "F1 Help", MB_OK);
  } else {
    ::MessageBox(NULL, "Help on example page", "Help", MB_OK);
  }
};

void AddonPageBase::DisplayPageStatus() {
  SetStatusText("Addon Page");
};

VOID AddonPageBase::Undo() {
  SetDlgItems();
  d_modified = 0;
};

/******************************************************************************
*
* CWindowPage show how to implement an full-feature addon page.
*
******************************************************************************/

struct PageData {
  int d_okToClose;
  int d_checked;
  int d_listCurrent;
  int d_comboCurrent;
  char d_comment[256];
};

class CWindowPage : public AddonPageBase {
public:
  //
  // IMpdPage interface
  //
  virtual BOOL CanClose();
  virtual void SetDlgItems();
  virtual void GetDlgItems();
  virtual VOID Init(HWND hDlg, IStatusBar* isb);
  virtual LRESULT OnCommand(UINT id, HWND hWndCtl, UINT notifyCode);
protected:
  PageData* d_pageData;
};


VOID CWindowPage::Init(HWND hDlg, IStatusBar* isb) {

  //
  // define a static variable to store data
  //
  static PageData pageData;

  d_pageData = &pageData;
  AddonPageBase::Init(hDlg, isb);
  SetDlgItemText(hDlg, IDC_PAGE_TYPE, "C Window");
};

//
// OnCommand()
//    Sets the modify state based on user input.
//    Displays status text when focus changed between controls in the page
//
LRESULT CWindowPage::OnCommand(UINT wID, HWND /*hWndCtl*/, UINT wNotifyCode) {
  char* statusText = 0;
  switch (wID)
  {
    case IDC_LIST1:
      switch (wNotifyCode)
      {
        case LBN_SELCHANGE:
          SetModified(1);
          break;
        case LBN_SETFOCUS:
          statusText = "Listbox";
          break;
        case LBN_KILLFOCUS:
          break;
      }
      break;
    //
    //  Special note for button with BS_NOTIFY style:
    //
    //      Button with BS_NOTIFY style will send BN_SETFOCUS and BN_KILLFOCUS
    //      message to its parent, so we must check the notify code to
    //      make sure the button is clicked.
    //
    case IDC_MESSAGE:
      switch (wNotifyCode)
      {
        case BN_SETFOCUS:
          statusText = "Click me to display a message box";
          break;
        case BN_KILLFOCUS:
          break;
        case BN_CLICKED:
          MessageBox(d_hDlg, "This is a message box","Addon", MB_OK);
          break;
      }
      break;
    case IDC_RADIO1:
      switch (wNotifyCode)
      {
        case BN_SETFOCUS:
          statusText = "RadioButton 1";
          break;
        case BN_KILLFOCUS:
          break;
        case BN_CLICKED:
          SetModified(1);
          break;
      }
      break;
    case IDC_RADIO2:
      switch (wNotifyCode)
      {
        case BN_SETFOCUS:
          statusText = "RadioButton 2";
          break;
        case BN_KILLFOCUS:
          break;
        case BN_CLICKED:
          SetModified(1);
          break;
      }
      break;
    case IDC_CHECK1:
      switch (wNotifyCode)
      {
        case BN_SETFOCUS:
          statusText = "CheckButton 1";
          break;
        case BN_KILLFOCUS:
          break;
        case BN_CLICKED:
          SetModified(1);
          break;
      }
      break;
    case IDC_EDIT1:
      switch (wNotifyCode)
      {
        case EN_CHANGE:
          SetModified(1);
          break;
        case EN_SETFOCUS:
          statusText = "Edit";
          break;
        case EN_KILLFOCUS:
          break;
      }
      break;
    case IDC_COMBO1:
    {
      switch (wNotifyCode)
      {
        case CBN_EDITCHANGE:
        case CBN_SELCHANGE:
          SetModified(1);
          break;
        case CBN_SETFOCUS:
          statusText = "Combo";
          break;
        case CBN_KILLFOCUS:
          break;
      }
    }
  };
  if (statusText) {
    SetStatusText(statusText);
  }
  //
  // we must return 0 to tell addon that we have processed this message
  //  any further processing is not necessary
  //
  switch (wID)
  {
    case IDC_LIST1:
    case IDC_MESSAGE:
    case IDC_RADIO1:
    case IDC_RADIO2:
    case IDC_CHECK1:
    case IDC_EDIT1:
    case IDC_COMBO1:
      return 0;
  };
  return 0;
};

//
//  SetDlgItems()
//    Set the controls the correct state. This method is called
//    when the page is displayed and when the "Undo Page" button
//    is clicked.
//
void CWindowPage::SetDlgItems() {

  CheckRadioButton(d_hDlg
            , IDC_RADIO1
            , IDC_RADIO2
            , IDC_RADIO1 + (d_pageData->d_okToClose ? 0 : 1));

  CheckDlgButton(d_hDlg, IDC_CHECK1, d_pageData->d_checked);
  SetDlgItemText(d_hDlg, IDC_EDIT1, d_pageData->d_comment);

  HWND hwndCtl = GetDlgItem(d_hDlg, IDC_LIST1);

  //
  // This can be called multiple times
  //
  if (!ListBox_GetCount(hwndCtl)) {
    ListBox_AddString(hwndCtl, "C");
    ListBox_AddString(hwndCtl, "C++");
    ListBox_AddString(hwndCtl, "Pascal");
  }
  ListBox_SetCurSel(hwndCtl, d_pageData->d_listCurrent);

  hwndCtl = GetDlgItem(d_hDlg, IDC_COMBO1);
  if (!ComboBox_GetCount(hwndCtl)) {
    ComboBox_AddString(hwndCtl, "Dos");
    ComboBox_AddString(hwndCtl, "Windows");
    ComboBox_AddString(hwndCtl, "Windows95");
    ComboBox_AddString(hwndCtl, "NT");
  }
  ComboBox_SetCurSel(hwndCtl, d_pageData->d_comboCurrent);

};

//
//  GetDlgItems()
//    Get the user change. This is callled when user select the OK button.
//
void CWindowPage::GetDlgItems() {

  d_pageData->d_checked = IsDlgButtonChecked(d_hDlg, IDC_CHECK1);
  GetDlgItemText(d_hDlg, IDC_EDIT1, d_pageData->d_comment, sizeof(d_pageData->d_comment));


  HWND hwndCtl = GetDlgItem(d_hDlg, IDC_LIST1);
  d_pageData->d_listCurrent = ListBox_GetCurSel(hwndCtl);

  hwndCtl = GetDlgItem(d_hDlg, IDC_COMBO1);
  d_pageData->d_comboCurrent= ComboBox_GetCurSel(hwndCtl);

  d_pageData->d_okToClose = 0;
};

//
// CanClose()
//    This method is called to determined if it is ok to close the page.
//
BOOL CWindowPage::CanClose() {
  //
  // This page can not be closed unless IDC_RADIO1 is checked.
  //
  int canClose = IsDlgButtonChecked(d_hDlg, IDC_RADIO1);
  if (!canClose) {
     MessageBox(d_hDlg, "This page can not be closed, because the \"Ok to close page\" radion button is not checked ","Addon", MB_OK);
  };
  return canClose;
};

//*****************************************************************************
//
// SubclassWindowPage is an example that subclass a dialog
// A program can do this when it needs to respond to other dialog messages.
//
//*****************************************************************************

class SubclassWindowPage : public CWindowPage {
public:
  //
  // IMpdPage interface
  //
  virtual VOID Init(HWND hDlg, IStatusBar* isb);
  virtual LRESULT OnCommand(UINT id, HWND hWndCtl, UINT notifyCode);
protected:
};

static DLGPROC oldDlgWinProc;
static CWindowPage* cTester;

BOOL CALLBACK DlgWinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
  switch (msg) {
    case WM_COMMAND:
    {
      WORD wID = LOWORD(wParam);
      WORD wNotifyCode = HIWORD(wParam);
      HWND hWndCtl = (HWND) lParam;
      return cTester->CWindowPage::OnCommand(wID, hWndCtl, wNotifyCode);
    }
  }
  return oldDlgWinProc(hwnd, msg, wParam, lParam);
}


VOID SubclassWindowPage::Init(HWND hDlg, IStatusBar* isb) {

  CWindowPage::Init(hDlg, isb);

  SetDlgItemText(hDlg, IDC_PAGE_TYPE, "Subclass Dialog page");
  oldDlgWinProc = SubclassDialog(hDlg, DlgWinProc);
  cTester = this;
};

//
// WM_COMMAND is processed in DlgWinProc, do nothing in OnCommand() here.
//
LRESULT SubclassWindowPage::OnCommand(UINT id, HWND hWndCtl, UINT notifyCode) {
  id, hWndCtl, notifyCode;
  //
  // must return 1 here in order for DlgWinProc to get WM_COMMAND message
  //
  return 1;
};

/******************************************************************************
*
* IMpdChapterAddon
*  A simple chapter implementation. It displays 3 different pages
*     AddonPageBase: The minimal page implementation.
*
*     CWindowPage:   A page that demonstrates how to implement
*                    various features of a MPD page
*
*     SubclassWindowPage: Demonstrates how to subclass a page.
*                      (not working yet)
*
******************************************************************************/
IMpdChapterAddon::IMpdChapterAddon()
                  :  IUnknownImp<IMpdChapter> (IID_IUnknown) {

  d_nPages = 0;
};

IMpdChapterAddon::~IMpdChapterAddon() {

  unsigned i;
  for (i = 0; i < d_nPages; ++i ) {
    d_pages[i]->Release();
  }
};

void IMpdChapterAddon::Init() {

  d_pages[0] = new AddonPageBase;
  d_pages[0]->SetInfo(MPD_OPENSUMMARY, IDD_MPD_PAGE1, "Addon Summary");

  d_pages[1] = new CWindowPage;
  d_pages[1]->SetInfo(MPD_CLOSEPAGE,   IDD_MPD_PAGE2, "Page1");

  d_pages[2] = new SubclassWindowPage;
  d_pages[2]->SetInfo(MPD_CLOSEPAGE,   IDD_MPD_PAGE3, "Page2");

  d_nPages = 3;
};

UINT IMpdChapterAddon::GetPageCount() {
  return d_nPages;
};

IMpdPage* IMpdChapterAddon::GetPage(UINT iPage) {
  if (iPage && iPage <= d_nPages) {
    IMpdPage* page = d_pages[iPage-1];
    page->AddRef();
    return page;
  }
  return 0;
};

void IMpdChapterAddon::SetEditNode(ProjectNode) {
};


IMpdPage* IMpdChapterAddon::OpenPage(UINT pid, ProjectNode /*node*/) {

  IMpdPage* page;
  switch (pid) {
    case IDD_MPD_PAGE1:
      page = d_pages[0];
      break;
    case IDD_MPD_PAGE2:
      page = d_pages[1];
      break;
    case IDD_MPD_PAGE3:
      page = d_pages[2];
      break;
    default:
      return 0;
  }
  page->AddRef();
  return page;
}

void IMpdChapterAddon::Close(UINT /*fOk*/) {
};
