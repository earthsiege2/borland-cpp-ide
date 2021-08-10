//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.25  $
//
// Implementation of TPropertyPage and TPropertySheet classes
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_COMMCTRL_H)
# include <owl/commctrl.h>
#endif
#if !defined(OWL_PROPSHT_H)
# include <owl/propsht.h>
#endif
#if !defined(OWL_TABCTRL_H)
# include <owl/tabctrl.h>
#endif
#if !defined(OWL_RESOURCE_H)
# include <owl/resource.h>
#endif
#if !defined(OWL_PROPSHT_RH)
# include <owl/propsht.rh>
#endif
#if !defined(WINSYS_UIMETRIC_H)
# include <winsys/uimetric.h>
#endif

//----------------------------------------------------------------------------
// TPropertySheet
//----------------------------------------------------------------------------

#if !defined(OWL_NATIVECTRL_ALWAYS)

// The caption of the PropertySheet buttons are loaded from a resource (to
// facilitate localization). However, we have default text.
//
static struct TSheetBtnInfo {
  int   id;         // Identifier of button
  int   strId;      // Identifier of string resource of caption
  char* defStr;     // Pointer to default when resource is not found
} defBtn[]= { 
  {ID_APPLY,  IDS_APPLY,  "&Apply"},
  {IDCANCEL,  IDS_CANCEL, "Cancel"},
  {IDOK,      IDS_OK,     "OK"}
}
;
const int  defBtnSz  = sizeof(defBtn)/sizeof(defBtn[0]);
const char CloseStr[]= "Close";
#endif

//
// Constructs a propertySheet object
//
TPropertySheet::TPropertySheet(TWindow* parent, const char far* title,
                               uint startPage, bool isWizard,
                               uint32 flags, TModule* module)
:
  TWindow(parent, title, module), IsWizard(isWizard), SubClassSheet(false)
#if !defined(OWL_NATIVECTRL_ALWAYS)
  ,Tab(0), Font(0), ActiveIndex(-1), ApplyEnabled(false)
#endif
{
  // Initialize the structure representing the property sheet
  //
  memset(&HeaderInfo, 0, sizeof(HeaderInfo));
  HeaderInfo.dwSize = sizeof(PROPSHEETHEADER);
  HeaderInfo.dwFlags= flags;
  if (IsWizard)
    HeaderInfo.dwFlags |= PSH_WIZARD;
  HeaderInfo.hInstance = *GetModule();
  HeaderInfo.pszCaption = title;
  HeaderInfo.nStartPage = startPage;

  // By default, we'll use the native implementation if it's available
  //
  UseNative = TCommCtrl::IsAvailable();

#if !defined(OWL_NATIVECTRL_ALWAYS)
  //
  // ObjectWindows will provide the underlying implementation of
  // PropertySheet/TabControl under environments without the Common 
  // Control Library support
  //
  if (!UseNative) {
    PageRect.SetNull();

    // Set the Sheet's window style [Non-native implementation only]
    //
    ModifyStyle(WS_CHILD, WS_POPUP|WS_CAPTION|WS_SYSMENU|
                          WS_VISIBLE|DS_MODALFRAME);
    SetExStyle(WS_EX_DLGMODALFRAME);
  }

#else // [OWL_NATIVECTRL_ALWAYS is defined]
  //
  // The Common Control Library must be available when the
  // ObjectWindows does not provide the underlying implementation
  // of PropertySheet/PropertyPage.
  //
  PRECONDITION(TCommCtrl::IsAvailable());
#endif
}

//
// Clean up resources used by PropertySheet objecct
//
TPropertySheet::~TPropertySheet()
{
#if !defined(OWL_NATIVECTRL_ALWAYS)
  delete Font;
#endif  
}

//
// Updates the caption of the property sheet
//
void
TPropertySheet::SetCaption(const char far* title)
{
#if !defined(OWL_NATIVECTRL_ALWAYS)
  //
  // When not using the system's underlying implementation of
  // PropertySheets, TWindow's SetCaption is sufficient.
  //
  if (!UseNative) {
    TWindow::SetCaption(title);
    return;
  }
#endif

  // Here we'll be a little flexible and allow a call to SetCaption
  // even before the underlying window element has been created...
  //
  if (GetHandle())
    SetTitle(title, 0);
  else {
    // TWindow's implementation will cache a copy of the string in the
    // data member 'Title'
    //
    TWindow::SetCaption(title);
    HeaderInfo.pszCaption = Title;
  }
}

//
// Executes modal propertysheet via call to 'Run' method
//
int
TPropertySheet::Execute()
{
#if !defined(OWL_NATIVECTRL_ALWAYS)
  //
  // When ObjectWindows is providing the underlying implementation
  // of PropertySheet, we'll simply invoke TWindow's Execute method
  //
  if (!UseNative) {
    return TWindow::Execute();
  }
#endif

  // Use CommCtrl via 'Run' helper method
  //
  return Run(true);
}

//
// Creates a modeless property sheet.
//
bool
TPropertySheet::Create()
{
#if !defined(OWL_NATIVECTRL_ALWAYS)
  //
  // When ObjectWindows is providing the underlying implementation
  // of PropertySheet, we'll simply invoke TWindow's Create method
  //
  if (!UseNative)
    return TWindow::Create();
#endif

  // Use CommCtrl via 'Run' helper method
  //
  return Run(false) != 0;
}

//
// Brings up modal/modeless propertysheet by invoking COMMCTRL's API.
//
int
TPropertySheet::Run(bool modal)
{
  // At this point our C++ parent object has (should have!) a valid HWND - 
  // hence update our Header structure
  //
  PRECONDITION(Parent->GetHandle());
  HeaderInfo.hwndParent = Parent->GetHandle();

  // We're about to use the Common Control Library's implementation
  // of PropertySheet - Check that it's available
  //
  CHECK(TCommCtrl::IsAvailable());

  HPROPSHEETPAGE pHandle[MAXPROPPAGES];

  // Have each page give us its handle
  //
  HeaderInfo.nPages = 0;
  HeaderInfo.phpage = pHandle;
  GetPageHandles();

  // Flag modal vs. modeless sheet
  //
  if (modal)
    HeaderInfo.dwFlags &= ~PSH_MODELESS;
  else
    HeaderInfo.dwFlags |= PSH_MODELESS;

  // Display property sheet
  //
  return TCommCtrl::Dll()->PropertySheet(&HeaderInfo);
}

//
// Internal routine used to add the page handle of a 'TPropertyPage'
// pointer to the array of page handles stored in a PROPSHEETHEADER
// structure.
//
static void
fillPageInfo(TPropertyPage* page, PROPSHEETHEADER* pHeader)
{
  CHECK(page);
  CHECK(pHeader);
  CHECK(pHeader->phpage != 0);
  pHeader->phpage[pHeader->nPages] = page->CreatePropertyPage();
  pHeader->nPages++;
}

//
// Have each page of dialog hand over the page handle.
//
bool
TPropertySheet::GetPageHandles()
{
#if defined(__TRACE) || defined(__WARN)
  // Retrieve number of pages in this sheet's child list
  //
  int pageCount = GetPageCount();

  // A sheet must have a least one page
  //
  CHECK(pageCount);
  CHECK(pageCount <= MAXPROPPAGES);
#endif

  // Have each page hand over it's handle
  //
  ForEachPage(TActionPageFunc(fillPageInfo), &HeaderInfo);

#if defined(__TRACE) || defined(__WARN)
  // Double check count
  //
  CHECK(pageCount == HeaderInfo.nPages);
#endif
  return true;
}

//
// Applies the specified 'action' function to each TPropertyPage
// child of the Sheet. 
// NOTE: The logic here traverses the TPropertySheet's ChildList. Therefore
//       we will miss any page that does not have an associated TPropertyPage
//       inserted in the sheet's ChildList.
void
TPropertySheet::ForEachPage(TActionPageFunc action, void* paramList)
{
  if (GetLastChild()) {
    TWindow*  curChild;
    TWindow*  nextChild = GetLastChild()->Next();
    TPropertyPage* curPage;
    do {
      curChild = nextChild;
      nextChild = nextChild->Next();
      curPage = TYPESAFE_DOWNCAST(curChild, TPropertyPage);
      if (curPage)
        action(curPage, paramList);
    } while (curChild != GetLastChild() && GetLastChild() != 0);
  }
}

//
// Applies the specified 'test' function to each 'TPropertyPage'
// of  the sheet and returns the first page which causes the
// 'test' function to return true. Returns '0' if no page meets
// the condition.
//
TPropertyPage*
TPropertySheet::FirstPageThat(TCondPageFunc test, void* paramList)
{
  if (GetLastChild()) {
    TWindow*  curChild;
    TWindow*  nextChild = GetLastChild()->Next();
    TPropertyPage* curPage;
    do {
      curChild = nextChild;
      nextChild = nextChild->Next();
      curPage = TYPESAFE_DOWNCAST(curChild, TPropertyPage);
      if (curPage) {
        if (test(curPage, paramList))
          return curPage;
      }
    } while (curChild != GetLastChild() && GetLastChild() != 0);
  }
  return 0;
}

//
// Updates the 'HWINDOW' data member of the PropertySheet Object.
// NOTE: This method is called from the InitHandle method of a
//       page of the sheet.
//
void
TPropertySheet::InitHandle(THandle sheetHandle)
{
  PRECONDITION(GetHandle()==0);
  PRECONDITION(::IsWindow(sheetHandle));
  SetHandle(sheetHandle);

  // When using the system's underlying implementation of PropertySheet
  // should we subclass the Sheet or should be it be treated as a black
  // box? Ideally the Sheet is this abstract container and we're only
  // concerned with our pages [dialogs]. However, there are scenarios where
  // we might want to subclass it. For example, if the sheet is used as a 
  // client of a framewindow and 'ShrinkToClient' is enabled, we'll need to
  // detect when the sheet is resized (i.e. receiving WM_SIZE messages) to
  // allow the frame to adjust.
  //
  if (SubClassSheet)
    SubclassWindowFunction();

  SetupWindow();
}

//
// Adds a new page to the end of the PropertySheet.
// NOTE: The 'pg' must have been created via a call to
//       'TPropertyPage::CreatePropertyPage' before
//       invoking the 'AddPage' method.
// NOTE: The property sheet is not resized to fit the new page. The
//       new page should be no larger that the largest page already
//       in the property sheet.
//
void
TPropertySheet::AddPage(TPropertyPage& pg)
{
  // Update pointer to parent object
  //
  if (pg.GetParentO() != this)
    pg.SetParent(this);

#if !defined(OWL_NATIVECTRL_ALWAYS)

  if (!UseNative) {
    // Create the page
    //
    pg.Create();

    // Save active page
    //
    TPropertyPage* active = GetActivePage();

    // Update tabs to match pages
    // NOTE: Not efficient!! (Revisit and improve)
    //
    SyncTabAndPages();

    // Restore active page
    //
    SetActivePage(IndexOfPage(active));
    return;
  }
#endif

  // Have page create itself it necessary
  //
  pg.CreatePropertyPage();
  CHECK(HPROPSHEETPAGE(pg));

  // Inform sheet about new page
  //
  CHECK(THandle(*this));
  SendMessage(PSM_ADDPAGE, 0, TParam2(HPROPSHEETPAGE(pg)));
}

#if !defined(OWL_NATIVECTRL_ALWAYS)
//
// Internal routine used to send notifications to each page
//
static bool
sendApply(TPropertyPage* pPage, TPshNotify* notInfo)
{
  // Page may not have been created yet!
  //
  if (pPage->GetHandle())
    return pPage->SendNotification(PropPageID, *notInfo) != PSNRET_NOERROR;
  return false;
}
#endif

//
// Simulates the choice of the Apply button, indicating that one or more
// pages have changed and the changes need to be validated or recorded.
// The property sheet sends the PSN_KILLACTIVE notification message to the
// current page. If the current page returns FALSE, the propertysheet
// sends the PSN_APPLY notification message to all pages.
// Returns true if all pages successfully applied the changes or false
// otherwise.
//
bool
TPropertySheet::Apply()
{
#if !defined(OWL_NATIVECTRL_ALWAYS)
  if (!UseNative) {
    TPropertyPage* activePg = GetActivePage();
    TPshNotify info(*this, 0, PSN_KILLACTIVE, 0);
    if (activePg->SendNotification(PropPageID, info) == PSNRET_NOERROR) {
      info.hdr.code = PSN_APPLY;
      TPropertyPage* page = CONST_CAST(TPropertySheet*,
                this)->FirstPageThat(TCondPageFunc(sendApply), &info);

      // Disable Apply button if all pages successfully applied
      //
      if (page == 0) {
        HWND btn = GetDlgItem(ID_APPLY);
        if (btn)
          ::EnableWindow(btn, FALSE);
      }
      return page == 0;
    }
    return false;
  }
#endif

  CHECK(THandle(*this));
  return SendMessage(PSM_APPLY) != 0;
}

//
// Disables the 'Cancel' button and changes the text of the 'OK' button
// to 'Close'. You must invoke this method after applying a change that
// cannot be canceled.
//
void
TPropertySheet::CancelToClose()
{
#if !defined(OWL_NATIVECTRL_ALWAYS)
  if (!UseNative) {
    TAPointer<char> p = new char[_MAX_PATH];
    SetDlgItemText(IDOK, GetModule()->LoadString(IDS_CLOSE, p, _MAX_PATH) ? 
                         (char*)p : CloseStr);
    ::EnableWindow(GetDlgItem(IDCANCEL), FALSE);
    return;
  }
#endif
  CHECK(THandle(*this));
  SendMessage(PSM_CANCELTOCLOSE);
}

//
// Informs the sheet that information in a sheet has changed. The
// sheet enables the 'Apply' button.
//
void
TPropertySheet::PageChanged(const TPropertyPage& pg)
{
#if !defined(OWL_NATIVECTRL_ALWAYS)
  if (!UseNative) {
    HWND btn = GetDlgItem(ID_APPLY);
    if (btn) {
      if (!::IsWindowEnabled(btn))
        ::EnableWindow(btn, TRUE);
    }
    return;
  }
#endif
  PRECONDITION(HPROPSHEETPAGE(pg));
  SendMessage(PSM_CHANGED, TParam1(pg.GetHandle()));
}

//
// Retrieves the handle to the window of the current page of the sheet.
//
HWND
TPropertySheet::GetCurrentPage() const
{
#if !defined(OWL_NATIVECTRL_ALWAYS)
  if (!UseNative) {
    TPropertyPage* activePage = GetActivePage();
    return activePage ? activePage->GetHandle() : 0;  
  }
#endif
  return HWND(CONST_CAST(TPropertySheet*,
                         this)->SendMessage(PSM_GETCURRENTPAGEHWND));
}

//
// Retrieves the handle to a tab control of a property sheet.
//
HWND
TPropertySheet::GetTabControl() const
{
#if !defined(OWL_NATIVECTRL_ALWAYS)
  if (!UseNative) {
    PRECONDITION(Tab);
    return Tab->GetHandle();
  }
#endif
  CHECK(GetHandle());
  return HWND(CONST_CAST(TPropertySheet*,
                         this)->SendMessage(PSM_GETTABCONTROL));
}

//
// Passes a message to a property sheet dialog box and indicates
// whether the dialog processed the message.
// Returns true if the message was processed or false otherwise.
//
bool
TPropertySheet::IsDialogMessage(MSG far& msg)
{
#if !defined(OWL_NATIVECTRL_ALWAYS)
  if (!UseNative) {
    // Not necessary when OWL provides underlying implementation since
    // TPropertySheet can use the 'PreProcessMsg' method to intercept
    // and handle desired events.
    //
    return false;
  }
#endif
  CHECK(GetHandle());
  return SendMessage(PSM_ISDIALOGMESSAGE, 0, TParam2(&msg)) != 0;
}

//
// Simulates the choice of a property sheet button.
// The button parameter can be one of the following:
//
//    PSBTN_APPLYNOW      Apply Now button.
//    PSBTN_BACK          Back button.
//    PSBTN_CANCEL        Cancel button.
//    PSBTN_FINISH        Finish button.
//    PSBTN_HELP          Help button.
//    PSBTN_NEXT          Next button.
//    PSBTN_OK            OK button
//
void
TPropertySheet::PressButton(int button)
{
#if !defined(OWL_NATIVECTRL_ALWAYS)
  if (!UseNative) {
    uint id = 0;
    switch (button) {
      case PSBTN_APPLYNOW: id = ID_APPLY;  break;
      case PSBTN_BACK:     id = ID_BACK;   break;
      case PSBTN_CANCEL:   id = IDCANCEL;  break;
      case PSBTN_FINISH:   id = ID_FINISH; break;
      case PSBTN_HELP:     id = IDHELP;    break;
      case PSBTN_NEXT:     id = ID_NEXT;   break;
      case PSBTN_OK:       id = IDOK;      break;
    }
    if (id) {
      // Could optimize here and use HandleMessage instead to avoid
      // going through Windows msg. queue.
      //
      SendNotification(id, BN_CLICKED, GetDlgItem(id));
    }
    return;
  }
#endif
  CHECK(GetHandle());
  SendMessage(PSM_PRESSBUTTON, TParam1(button));
}

#if !defined(OWL_NATIVECTRL_ALWAYS)
//
// Internal routine used to send notifications to each page
//
static bool
sendQuerySiblings(TPropertyPage* pPage, MSG* msg)
{
  LRESULT result = pPage->SendMessage(PSM_QUERYSIBLINGS, msg->wParam, 
                                                         msg->lParam);
  if (result) {
    msg->lParam = result;
    return true;
  }
  return false;
}
#endif

//
// Forwards the 'PSM_QUERYSIBLINGS' message to each page in the
// property sheet. If a page returns a nonzeroe value, the property
// sheet does not send the message to subsequent pages.
// Returns the nonzero value from a page in the property sheet, or
// zero if no page returns a nonzero value.
//
int
TPropertySheet::QuerySiblings(TParam1 p1, TParam2 p2)
{
#if !defined(OWL_NATIVECTRL_ALWAYS)
  if (!UseNative) {
    MSG msg;
    msg.message = PSM_QUERYSIBLINGS;
    msg.wParam  = p1;
    msg.lParam  = p2;
    TPropertyPage* page = CONST_CAST(TPropertySheet*,
              this)->FirstPageThat(TCondPageFunc(sendQuerySiblings), &msg);
    return page ? int(msg.lParam) : 0;
  }
#endif
  CHECK(GetHandle());
  return (int)SendMessage(PSM_QUERYSIBLINGS, p1, p2);
}

//
// Indicates that the system needs to be restarted for the changes
// to take effect. You should invoke this method only in response to
// the PSN_APPLY or PSN_KILLACTIVE notifications.
// NOTE: It's your responsibility to reboot the system [via ExitWindowEx
//       for example].
// NOTE: Invoking this method causes the TPropertySheet::Execute method
//       to return ID_PSREBOOTSYSTEM.
//
void
TPropertySheet::RebootSystem()
{
#if !defined(OWL_NATIVECTRL_ALWAYS)
  if (!UseNative) {
    if (IsFlagSet(wfModalWindow))
      CloseWindow(ID_PSREBOOTSYSTEM);
    return;
  }
#endif
  CHECK(GetHandle());
  SendMessage(PSM_REBOOTSYSTEM);
}

//
// Removes the specified page from the property sheet
//
void
TPropertySheet::RemovePage(TPropertyPage& pg)
{
#if !defined(OWL_NATIVECTRL_ALWAYS)
  if (!UseNative) {
    if (pg.GetSheet() == this) {
      int index = IndexOfPage(&pg);
      if (index != -1) {
        pg.Destroy(-1);
        Tab->Delete(index);
        if (index == ActiveIndex && GetPageCount())
          SetActivePage((ActiveIndex+1) % GetPageCount());
      }
    }
    return;
  }
#endif
  PRECONDITION(HPROPSHEETPAGE(pg));
  CHECK(GetHandle());
  SendMessage(PSM_REMOVEPAGE, 0, TParam2(HPROPSHEETPAGE(pg)));
  //
  // Should we actually invoke 'DestroyPropertySheetPage' for
  // Pages which are added then removed from the PropertySheet??
}

//
// Removes the page at the specified index from the property sheet
//
void
TPropertySheet::RemovePage(int pgIndex)
{
#if !defined(OWL_NATIVECTRL_ALWAYS)
  if (!UseNative) {
    TPropertyPage* page = PageAtIndex(pgIndex);
    if (page)
      RemovePage(*page);
    return;
  }
#endif
  CHECK(GetHandle());
  SendMessage(PSM_REMOVEPAGE, pgIndex);
  //
  // Should we actually invoke 'DestroyPropertySheetPage' for
  // Pages which are added then removed from the PropertySheet??
}

//
// Indicates that the system needs to be restarted for the changes
// to take effect. You should invoke this method only in response to
// the PSN_APPLY or PSN_KILLACTIVE notifications.
// NOTE: It's your responsibility to reboot the system [via ExitWindowEx
//       for example].
// NOTE: Invoking this method causes the TPropertySheet::Execute method
//       to return ID_PSRESTARTWINDOWS.
//
void
TPropertySheet::RestartWindows()
{
#if !defined(OWL_NATIVECTRL_ALWAYS)
  if (!UseNative) {
    if (IsFlagSet(wfModalWindow))
      CloseWindow(ID_PSRESTARTWINDOWS);
    return;
  }
#endif
  CHECK(GetHandle());
  SendMessage(PSM_RESTARTWINDOWS);
}

//
// Activates the specified page in the property sheet
// Returns true if successful or false otherwise.
// NOTE: The page that's loosing activation receives a PSN_KILLACTIVE
//       notification while the window that's gaining activation receives
//       a PSN_SETACTIVE notification.
//
bool
TPropertySheet::SelectPage(TPropertyPage& pg)
{
#if !defined(OWL_NATIVECTRL_ALWAYS)
  if (!UseNative) {
    TPshNotify info(*this, 0, PSN_KILLACTIVE, 0);
    TPropertyPage* page = GetActivePage();
    if (page && page->SendNotification(PropPageID, info) != PSNRET_NOERROR) 
      return false;

    int index = IndexOfPage(&pg);
    if (index != -1) {
      SetActivePage(index);
      info.hdr.code = PSN_SETACTIVE;
      pg.SendNotification(PropPageID, info);
      return true;
    }
    return false;
  }
#endif
  PRECONDITION(GetHandle());
  PRECONDITION(HPROPSHEETPAGE(pg));
  return SendMessage(PSM_SETCURSEL, 0, TParam2(HPROPSHEETPAGE(pg))) != 0;
}

//
// Activates the page at the specified index in the property sheet.
// Returns true if successful or false otherwise.
// NOTE: The page that's loosing activation receives a PSN_KILLACTIVE
//       notification while the window that's gaining activation receives
//       a PSN_SETACTIVE notification.
//
bool
TPropertySheet::SelectPage(int pgIndex)
{
#if !defined(OWL_NATIVECTRL_ALWAYS)
  if (!UseNative) {
    PRECONDITION(pgIndex < GetPageCount());
    TPropertyPage* page = PageAtIndex(pgIndex);
    if (page)
      return SelectPage(*page);
    return false;
  }
#endif
  PRECONDITION(GetHandle());
  return SendMessage(PSM_SETCURSEL, TParam1(pgIndex)) != 0;
}

//
// Activates the page with the specified resource identifier.
// Returns true if successful or false otherwise.
// NOTE: The page that's loosing activation receives a PSN_KILLACTIVE
//       notification while the window that's gaining activation receives
//       a PSN_SETACTIVE notification.
//
bool
TPropertySheet::SelectPage(TResId pgRes)
{
#if !defined(OWL_NATIVECTRL_ALWAYS)
  if (!UseNative) {
    // This flavour of page selection is not supported by the ObjectWindows
    // emulation of PropertySheet/PropertyPage. 
    return false;
  }
#endif
  CHECK(GetHandle());
  return SendMessage(PSM_SETCURSELID, 0, TParam2((char far*)pgRes));
}

//
// Sets the text for the 'Finish' button in a Wizard property sheet.
// NOTE: The button is enabled while the 'Next' and 'Back' buttons
//       are hidden.
//
void
TPropertySheet::SetFinishText(const char far* txt)
{
#if !defined(OWL_NATIVECTRL_ALWAYS)
  if (!UseNative) {
    HWND finish = GetDlgItem(ID_FINISH);
    HWND next   = GetDlgItem(ID_NEXT);
    HWND back   = GetDlgItem(ID_BACK);
    if (finish)
      ::SetWindowText(finish, txt);
    if (next)
      ::EnableWindow(next, FALSE);  // Disable (rather than hide)
    if (back)
      ::EnableWindow(back, FALSE);  // Disable (rather than hide)
    return;
  }
#endif
  CHECK(GetHandle());
  SendMessage(PSM_SETFINISHTEXT, 0, TParam2(txt));
}

//
// Sets the title of a property sheet.
// If 'style' parameter is the PSH_PROPTITLE value, the prefix
// "Properties of" is included with the specified title ('txt')
// parameter.
//
void
TPropertySheet::SetTitle(const char far* txt, uint32 style)
{
#if !defined(OWL_NATIVECTRL_ALWAYS)
  if (!UseNative) {
    SetWindowText(txt);
    return;
  }
#endif
  CHECK(GetHandle());
  SendMessage(PSM_SETTITLE, TParam1(style), TParam2(txt));
}

//
// Enables the 'Back', 'Next' or 'Finish' button in a wizard
// property sheet. The 'flags' parameter can be a combination of
// the following values:
//
//          PSWIZB_BACK                 Back button
//          PSWIZB_NEXT                 Next button
//          PSWIZB_FINISH               Finish button
//
void
TPropertySheet::SetWizButtons(uint32 flags)
{
#if !defined(OWL_NATIVECTRL_ALWAYS)
  if (!UseNative) {
    HWND finish = GetDlgItem(ID_FINISH);
    HWND next   = GetDlgItem(ID_NEXT);
    HWND back   = GetDlgItem(ID_BACK);
    if (back)
      ::EnableWindow(back, (flags & PSWIZB_BACK) ? TRUE : FALSE);
    if (next)
      ::EnableWindow(next, (flags & PSWIZB_NEXT) ? TRUE : FALSE);
    if (finish)
      ::EnableWindow(finish, (flags & PSWIZB_FINISH) ? TRUE : FALSE);
    return;
  }
#endif
  CHECK(GetHandle());
  SendMessage(PSM_SETWIZBUTTONS, 0, TParam2(flags));
}

#if !defined(OWL_NATIVECTRL_ALWAYS)
//
// Internal routine used to check if there's a dirty page
//
static bool
isModified(TPropertyPage* pPage, void*)
{
  return pPage->IsModified();
}
#endif

//
// Informs the sheet that the information in the specified page
// has reverted to the previously saved state. The sheet disables
// the 'Apply' button if no other pages have registered changes
// with the property sheet.
//
void
TPropertySheet::PageUnchanged(TPropertyPage& pg)
{
#if !defined(OWL_NATIVECTRL_ALWAYS)
  if (!UseNative) {

    // Update the specified page
    //
    pg.SetModified(false);

    // Find out if there are any dirty pages
    //
    TPropertyPage* page = CONST_CAST(TPropertySheet*,
                          this)->FirstPageThat(isModified, 0);

    // Disable APPLY button if all pages are clean
    //
    if (!page) {
      HWND apply = GetDlgItem(ID_APPLY);
      if (apply)
        ::EnableWindow(apply, FALSE);
    }
    return;
  }
#endif
  PRECONDITION(HPROPSHEETPAGE(pg));
  CHECK(GetHandle());
  SendMessage(PSM_UNCHANGED, TParam1(HPROPSHEETPAGE(pg)));
}


// ---------------------------------------------------------------------------
//  TPropertyPage
// ---------------------------------------------------------------------------

DEFINE_RESPONSE_TABLE1(TPropertyPage, TDialog)
  EV_PSN_APPLY(Apply),
  EV_PSN_KILLACTIVE(KillActive),
  EV_PSN_HELP(Help),
  EV_PSN_SETACTIVE(SetActive),
  EV_PSN_WIZBACK(WizBack),
  EV_PSN_WIZFINISH(WizFinish),
  EV_PSN_WIZNEXT(WizNext),
END_RESPONSE_TABLE;

//
// Constructor for TPropertyPage
//
//
TPropertyPage::TPropertyPage(TPropertySheet* parent, TResId resId,
                             const char far* title, TResId iconRes,
                             TModule* module)
:
  TDialog(parent, resId, module),
#if !defined(OWL_NATIVECTRL_ALWAYS)
  Modified(false),
#endif
  HPropPage(0)
{
  // Initialize the PROPSHEETPAGE structure
  // NOTE: We're storing the 'this' pointer in the application-defined
  //       section of the PROPSHEETPAGE structure...
  //
  memset(&PageInfo, 0, sizeof(PageInfo));
  PageInfo.dwSize = sizeof(PROPSHEETPAGE);
  PageInfo.dwFlags= PSP_DEFAULT;
  PageInfo.pszTemplate = resId;
  PageInfo.hInstance = *GetModule();

  if (title)
    SetTitle(title);
  if (iconRes)
    SetIcon(iconRes);

  PageInfo.dwFlags |= PSP_USECALLBACK;
  PageInfo.pfnCallback = PropCallback;
  PageInfo.pfnDlgProc = PropDlgProc;
  PageInfo.lParam = LPARAM(this);

  // By default, we'll use the native implementation if it's available
  //
  UseNative = TCommCtrl::IsAvailable();

#if defined(OWL_NATIVECTRL_ALWAYS)

  // When OWL is built with the NATIVECTRL_ALWAYS option, the
  // Common Control library MUST be available....
  //
  CHECK(TCommCtrl::IsAvailable());
#endif
}


//
// Destructor of TPropertyPage - Clean up allocated buffers used when
// ObjectWindows provides implementation of property pages.
//
TPropertyPage::~TPropertyPage()
{
}

//
// Specifies the icon to be used for this page
// NOTE: This routine must be invoked before the page is created.
//
void
TPropertyPage::SetIcon(const TIcon& icon)
{
  PageInfo.hIcon = icon;
  PageInfo.dwFlags &= ~PSH_USEICONID;
  PageInfo.dwFlags |=  PSH_USEHICON;
}

//
// Specifies the icon to be used for this page
// NOTE: This routine must be invoked before the page is created.
//
void
TPropertyPage::SetIcon(TResId iconResId)
{
  PageInfo.pszIcon = iconResId;
  PageInfo.dwFlags &= ~PSH_USEHICON;
  PageInfo.dwFlags |=  PSH_USEICONID;
}

//
// Sets the caption of this page.
// NOTE: This routine must be invoked before the page is created.
//
void
TPropertyPage::SetTitle(const char far* title)
{
  // Let TWindow make a copy of the title to 'Title'
  // Then point to the 'duped' copy...
  //
  SetCaption(title);
  PageInfo.pszTitle = Title;
  PageInfo.dwFlags |= PSP_USETITLE;
}

//
// Sets the caption of this page.
// NOTE: This routine must be invoked before the page is created.
//
void
TPropertyPage::SetTitle(int txtResId)
{
  PageInfo.pszTitle = MAKEINTRESOURCE(txtResId);
  PageInfo.dwFlags &= ~PSP_USETITLE;
}

//
// WM_NOTIFY handler: Scans for property sheet notifications to 'patch'
// the 'idFrom' member to the predefined 'PropPageID'.
// NOTE: This is necessary since WM_NOTIFY subdispatching relies on the
//       id of the sender.
//
TResult
TPropertyPage::EvNotify(uint id, TNotify far& notifyInfo)
{
  if (notifyInfo.code <= PSN_FIRST && notifyInfo.code >= PSN_LAST) {
    // Property sheet notifications require special handling since the
    // concept of ctlId is non-existent. We patch it to the default
    // PageID expected by the ObjectWindows Property Page dispatchers
    //
    notifyInfo.idFrom = PropPageID;
    id = PropPageID;
  }
  return TDialog::EvNotify(id, notifyInfo);
}

//
// This callback is the default 'Dialog box procedure' of each page of our
// property sheet....
//
int CALLBACK OWL_EXPORT16
TPropertyPage::PropDlgProc(HWND hDlg, uint msg, WPARAM wParam, LPARAM lParam)
{
  switch(msg) {
    case  WM_INITDIALOG: {
            // Attach C++ object with it's underlying handle if necessary
            //
            LPPROPSHEETPAGE pageInfo = REINTERPRET_CAST(LPPROPSHEETPAGE,
                                                        lParam);
            InitHandle(hDlg, pageInfo);
          }
          break;

    case WM_NOTIFY: {
          TNotify far& notifyInfo= *(REINTERPRET_CAST(TNotify far*, lParam));
          if (notifyInfo.code <= PSN_FIRST && notifyInfo.code >= PSN_LAST) {

              // Property sheet notifications require special handling
              // since the concept of ctlId is non-existent. We patch it
              // to the default PageID expected by the ObjectWindows
              // Property Page dispatchers
              //
              notifyInfo.idFrom = PropPageID;
              wParam = PropPageID;
            }
          }
          break;

    default:
          break;
  }

  return TDialog::StdDlgProc(hDlg, msg, wParam, lParam);
}

//
// As with TDialog, most of the page's events are dispatch
// directly from 'StdWndProc'. ALthough the Sheet has each
// page's DialogProc, the notifications are not (don't seem
// to be) funelled directly to the dialogProc
//
bool
TPropertyPage::DialogFunction(uint msg, TParam1 p1, TParam2 p2)
{
  switch(msg) {
    case WM_NOTIFY: {
           NMHDR far& nmhdr = *(REINTERPRET_CAST(NMHDR far*, p2));
           if (nmhdr.code >= PSN_LAST && nmhdr.code <= PSN_FIRST) {
             CHECK(p1 != 0);
             CHECK(nmhdr.idFrom != 0);
           }
         }
         break;

    default:
        break;
  }
  return TDialog::DialogFunction(msg, p1, p2);
}

// 'CopyPageInfo' is called by the 'Sheet' object requesting
// the page to fill out a 'PROPSHEETPAGE' structure which
// describes the attribute of the page.
//
void
TPropertyPage::CopyPageInfo(PROPSHEETPAGE& pgInfo) const
{
  pgInfo = PageInfo;
}

//
// 'CreatePropertyPage' is called by the 'Sheet' object requesting
// the page to return a handle used to represent this dialog
// when it's inserted into the 'Sheet'
//
HPROPSHEETPAGE
TPropertyPage::CreatePropertyPage()
{
  if (!HPropPage) 
    HPropPage = TCommCtrl::Dll()->CreatePropertySheetPage(&PageInfo);

  return HPropPage;
}

//
// Destroys the page represented by this object.
//
bool
TPropertyPage::DestroyPropertyPage()
{
  PRECONDITION(HPropPage);
  if (TCommCtrl::Dll()->DestroyPropertySheetPage(HPropPage)) {
    HPropPage= 0;
    return true;
  }
  return false;
}

//
// Creates the page
//
bool
TPropertyPage::Create()
{
#if !defined(OWL_NATIVECTRL_ALWAYS)
  //
  // If we're using ObjectWindows' implementation of PropertySheet/Page,
  // simply chain to the default TDialog::Create method
  //
  if (!UseNative)
    return TDialog::Create();
#endif  //  !OWL_NATIVECTRL_ALWAYS

  // When using the system's implementation if PropertyDialogs, the page
  // is actually created behind the scene when the PropertySheet is
  // created. The callbacks specified by ObjectWindows [PropDlgProc &
  // PropCallback] will update the TPropertyPage's HWindow data member.
  //
  // Therefore, our 'Create' method simply checks that the handle was
  // indeed initialized and happily returns true.
  //
  CHECK(GetHandle() != 0);
  return true;
}

//
// The pages of a propertysheet are created internally by windows...
// Consequently, we must attempt to grab and thunk the 'HWND' as
// early as possible. There are two basic opportunities to do so:
//
// (a) A Sheet can provide a callback which is called whenever a
//     page is created or released. Hence 'TPropertyPage::PropCallback'
//     invokes 'InitHandle'.
//
// (b) Each page provides a dialog-procedure callback. Hence,
//     'TPropertyPage::PropDlgProc' invokes 'InitHandle' upon receiving
//     a WM_INITDIALOG message.
//
void
TPropertyPage::InitHandle(THandle pageHandle, LPPROPSHEETPAGE ppsp)
{
  // First check that the lParam data member of the PROPSHEETPAGE
  // contains a 'this' pointer to an OWL TPropertyPage object
  // wrapping the dialog
  //
  TPropertyPage* page = REINTERPRET_CAST(TPropertyPage*, ppsp->lParam);

  if (page && pageHandle) {
    // Only proceed if the C++ object is not fully initialized
    //
    if (page->GetHandle()) {
      CHECK(page->GetHandle() == pageHandle);
      return;
    }

    // Proceed to initialize the handle of the page object.
    //
    page->SetHandle(pageHandle);

    // We can now retrieve the pointer to the sheet object
    // and initialize the latter if necessary.
    //
    TPropertySheet* sheet = TYPESAFE_DOWNCAST(page->Parent, TPropertySheet);
    if (sheet) {
      if (!sheet->GetHandle()) {
        THandle sheetHandle = ::GetParent(pageHandle);
        if (sheetHandle)
          sheet->InitHandle(sheetHandle);
      }
    }

    // Allow OWL to thunk the page window.
    //
    page->SubclassWindowFunction();

    // NOTE: Typically, we'd call 'GetHWndState', 'PerformDlgInit',
    //       'SetupWindow' and 'SetFlag(wfFullyCreated)' after
    //       thunking a window. However, TDialog's 'EvInitDialog'
    //       method [invoked via the PropDlgProc callback] will
    //       handle that.
  }
}

//
// Static callback invoked whenever a Property Page is created is
// destroyed.
//
uint CALLBACK OWL_EXPORT16
TPropertyPage::PropCallback(HWND hwnd, uint uMsg, LPPROPSHEETPAGE ppsp)
{
  switch (uMsg) {
    case PSPCB_CREATE: {

           // A Property Page was just created.. We'll attempt to thunk
           // the underlying 'HWND' if it was specified..
           //
           if (hwnd)
             InitHandle(hwnd, ppsp);
         }
         break;

    case PSPCB_RELEASE: {

            // A Property Page was just released... Currently, we
            // don't have any processing to do here....
            // Should we invoke a virtual method of TPropertyPage
            // from here - just in case a page needs to do something
            // when it's released or are the default ObjectWindows
            // mechanisms (CleanupWindow & Destructor) sufficient....
            //
         }
         break;

    default:
          break;
  }
  // The return is ignored for PSPCB_RELEASE (according to the doc).
  // A non-zero value allows the page to be created...
  //
  return 1;
}

//
// Returns the caption of a PropertyPage
// May be used for PropertyPages with or without an underlying
// window element.
//
bool
TPropertyPage::GetPageCaption(char* txt, int size)
{
  // This method should only be invoked when ObjectWindows
  // is providing the underlying implementation of Property Page.
  //
  CHECK(!UseNative);

  // Retrieve actual text if page has been created
  //
  if (GetHandle()) {
    return GetWindowText(txt, size) != 0;
  }
  else {
    if ((PageInfo.dwFlags & PSP_USETITLE) && Title) {
      strncpy(txt, Title, size);
    }
    else {
      PRECONDITION((char*)ResCaption && *((char*)ResCaption));
      strncpy(txt, ResCaption, size);
    }
  }
  return true;
}

//
// Sets the caption of a PropertyPage
//
void
TPropertyPage::SetPageCaption(char far* caption)
{
  PRECONDITION(caption);
  PRECONDITION(*caption);

  // This method should only be invoked when ObjectWindows
  // is providing the underlying implementation of Property Page.
  //
  CHECK(!UseNative);
  ResCaption = nstrnewdup(caption);
}

// Default implementation of PropertySheet notifications.. Derived classes
// will override - most likely.
//

//
//
//
int
TPropertyPage::Apply(TNotify far&)
{
#if !defined(OWL_NATIVECTRL_ALWAYS)
  if (!UseNative) {
    // Clear modified flag 
    //
    SetModified(false);
  }
#endif

  //
  //
  return PSNRET_NOERROR;
}

//
//
//
bool
TPropertyPage::KillActive(TNotify far&)
{
  return false;
}

//
//
//
void
TPropertyPage::Help(TNotify far&)
{
}

//
//
//
void
TPropertyPage::Reset(TNotify far&)
{
}

//
//
//
int
TPropertyPage::SetActive(TNotify far&)
{
  return 0;
}

//
//
//
int
TPropertyPage::WizBack(TNotify far&)
{
  return 0;
}

//
//
//
bool
TPropertyPage::WizFinish(TNotify far&)
{
  return 0;
}

//
//
//
int
TPropertyPage::WizNext(TNotify far&)
{
  return 0;
}


// ------------------------------------------------------------------------
// The following routines are used by ObjectWindows when it
// provides the underlying support for PropertyPage
// ------------------------------------------------------------------------
#if !defined(OWL_NATIVECTRL_ALWAYS)

//
// Update the style/size of the dialog [PropertyPage]
//
void
TPropertyPage::SetupWindow()
{
  TDialog::SetupWindow();

  if (!UseNative) {
    // Strip off and add undesirable and desirable styles respectively
    //
    ModifyStyle(WS_BORDER|WS_CAPTION|WS_VISIBLE, WS_GROUP|WS_TABSTOP);
    ModifyExStyle(WS_EX_WINDOWEDGE, 0, SWP_DRAWFRAME);

    // Adjust dialog's height since we've truncated the caption
    // and border...
    //
    TRect dlgRect;
    GetWindowRect(dlgRect);
    dlgRect.bottom -= TUIMetric::CyCaption - TUIMetric::CyBorder;
    SetWindowPos(HWND_BOTTOM, dlgRect, SWP_NOACTIVATE|SWP_NOMOVE);
  }
}


#endif  //  !OWL_NATIVECTRL_ALWAYS;

// ------------------------------------------------------------------------
// The following routines are used by ObjectWindows when it
// provides the underlying support for PropertySheet
// ------------------------------------------------------------------------
#if !defined(OWL_NATIVECTRL_ALWAYS)

const int MaxTabTextLen = 100;
const int ID_TabControl = 0x1000;

//
// Used internally [within this module] to match pages and indices
//
struct TPageInfo {
  const TPropertyPage* Page;      // Pointer to PropertyPage within sheet
  int                  Index;     // Index of the page [zero-based]
};

//
// NOTE: The 'rect' passed in should be initialized to (0,0,0,0)
//       before invoking this function for the first time...
//
static void
findDlgResInfo(TPropertyPage* page, TRect* rect)
{
  // Find/Load/Lock dialog resource and retrieve dimensions
  //
  TDialogRes dlgRes(*(page->GetModule()), page->DialogAttr.Name);
  TRect dlgRect;
  dlgRes.GetRect(dlgRect);

  // Store width of widest dialog
  //
  if (dlgRect.Width() > rect->Width()) {
    rect->left = dlgRect.left;
    rect->right= dlgRect.right;
  }

  // Store away the height if this is the tallest resource
  //
  if (dlgRect.Height() > rect->Height()) {
    rect->top = dlgRect.top;
    rect->bottom = dlgRect.bottom;
  }

  // Store away the page's caption
  //
  char caption[100];
  if (dlgRes.GetText(caption, sizeof(caption)))
    page->SetPageCaption(caption);
}

//
// Computes the size of the sheet, activates the designated 'startPage'
// and sets focus to the tab control...
//
void
TPropertySheet::SetupWindow()
{
  TWindow::SetupWindow();

  // Initialization when PropertySheet support is provided by ObjectWindows
  //
  if (!UseNative) {

    // Grab a copy of font based on system's UI
    //
    Font = new TDefaultGUIFont;

    // Create Tab control
    //
    Tab = new TTabControl(this, ID_TabControl, 0, 0, 100, 100);
    if (HeaderInfo.dwFlags & PSH_MULTILINETABS)
      Tab->SetStyle(Tab->GetStyle() | TCS_MULTILINE);
    Tab->Create();


    // Retrieve the size of biggest page/dialog
    // NOTE: As a side-effect, 'findDlgResInfo' also retrieves the
    //       caption of each dialog from it's resource template...
    //
    TRect rect(0, 0, 0, 0);
    ForEachPage(TActionPageFunc(findDlgResInfo), &rect);

    // Update tab with entries of each page and select the
    // tab corresponding to our 'startPage' a page
    //
    SyncTabAndPages();
    Tab->SetSel(HeaderInfo.nStartPage);

    // Activate the startPage index
    //
    SetActivePage(HeaderInfo.nStartPage);

    // The sizes retrieved from the dialog resources are in
    // dialog base units: We convert them to screen coordinates..
    // NOTE: Win95 seems to be aware of 3.1 style dialogs (i.e.
    //       non-DS_3DLOOK ones) and computes the dialog base units
    //       accordingly since these dialogs use the bold font.
    //       At this point we've retrieved the rectangle of the biggest
    //       dialog. However, the first active dialog is the one used
    //       to convert that size from DialogUnits to Pels... So mixing
    //       DS_3DLOOK and non-DS_3DLOOK dialogs with an app. marked
    //       for an earlier version of Windows may result (what am I
    //       saying..., WILL RESULT) in incorrect computation of the
    //       required dimensions...
    //
    PRECONDITION(GetActivePage());
    GetActivePage()->MapDialogRect(rect);

    // Retrieve sizes of buttons and margins
    //
    ComputeMarginAndButton();

    // Update the size of the sheet & tab and position the page
    //
    UpdateTabAndSheetSize(rect);
    PositionPage(GetActivePage());

    // Create Buttons; position them and update their state
    //
    CreateButtons();
    UpdateButtons();

    // Set Focus to tab control
    //
    Tab->SetFocus();
  }
}

//
// Internal routine used to identify the page at a particular index
//
static bool
matchPageIndex(TPropertyPage* /*pPage*/, int* pArray)
{
  if (pArray[0] == pArray[1])
    return true;
  else
    pArray[0]++;

  return false;
}

//
// Returns a pointer to the object representing the page at the
// specified index. Returns zero if no page is found.
//
TPropertyPage*
TPropertySheet::PageAtIndex(int index) const
{
  PRECONDITION(index < GetPageCount());
  int counts[]={0, index};
  TPropertyPage* page = CONST_CAST(TPropertySheet*,
                this)->FirstPageThat(TCondPageFunc(matchPageIndex), counts);
  CHECK(page == PageAtTabIndex(index));
  return page;
}

//
// Internal callback used to count the number of pages within
// a Property Sheet.
//
static void
countPages(TPropertyPage* /*page*/, int* pCount)
{
  (*pCount)++;
}

//
// Retrieves the number of pages within a particular sheet
//
int
TPropertySheet::GetPageCount() const
{
  int pageCount = 0;
  CONST_CAST(TPropertySheet*,
             this)->ForEachPage(TActionPageFunc(countPages), &pageCount);
  return pageCount;
}

//
// Internal callback used to find the index of a particular page
// within a property sheet.
//
static bool
matchPagePtr(TPropertyPage* pPage, TPageInfo* pageInfo)
{
  if (pPage == pageInfo->Page)
    return true;
  else {
    pageInfo->Index++;
    return false;
  }
}

//
// Returns the index of the specified page or '-1' if the
// specified page could not be found in the child list of
// the sheet object
//
int
TPropertySheet::IndexOfPage(const TPropertyPage* page) const
{
  PRECONDITION(page);
  TPageInfo pi = {page, 0};
  int index = CONST_CAST(TPropertySheet*,
     this)->FirstPageThat(TCondPageFunc(matchPagePtr), &pi) ? pi.Index : -1;
  CHECK(index == TabIndexOfPage(page));
  return index;
}



DEFINE_RESPONSE_TABLE1(TPropertySheet, TWindow)
  // Messages handled by Sheet
  //
  EV_WM_ACTIVATE,
  EV_WM_SETFOCUS,
  EV_WM_SIZE,
  EV_WM_GETFONT,

  // Tab Control Notifications
  //
  EV_TCN_SELCHANGE(ID_TabControl, TabSelChange),
  EV_TCN_SELCHANGING(ID_TabControl, TabSelChanging),
  EV_TCN_KEYDOWN(ID_TabControl, TabKeyDown),

  // Button notifications
  //
  EV_COMMAND_AND_ID(ID_APPLY,  ButtonClicked),
  EV_COMMAND_AND_ID(ID_BACK,   ButtonClicked),
  EV_COMMAND_AND_ID(ID_NEXT,   ButtonClicked),
  EV_COMMAND_AND_ID(ID_FINISH, ButtonClicked),
  EV_COMMAND_AND_ID(IDOK,      ButtonClicked),
  EV_COMMAND_AND_ID(IDCANCEL,  ButtonClicked),
  EV_COMMAND_AND_ID(IDHELP,    ButtonClicked),
END_RESPONSE_TABLE;


//
// Returns a unique name under which the PropertSheet will be
// registered..
//
char far*
TPropertySheet::GetClassName()
{
  // When encapsulating the Common Control's implementation we're
  // unaware of and not concerned with the window's classname
  // since the Common Control DLL exposes a high level DLL to
  // create the interface...
  //
  return "OWL_PropertySheet";
}

//
// Updates the Window CLASS attributes of the PropertySheet.
//
void
TPropertySheet::GetWindowClass(WNDCLASS& wndClass)
{
  TWindow::GetWindowClass(wndClass);
  wndClass.hbrBackground = HBRUSH(COLOR_BTNFACE + 1);
}

//
// WM_SIZE Handler
//
void
TPropertySheet::EvSize(uint sizeType, TSize& size)
{
  TWindow::EvSize(sizeType, size);
  if (!UseNative) {
    PRECONDITION(Tab && Tab->GetHandle());

    // Resize tab control
    //
  }
}

//
// WM_ACTIVATE Handler
//
void
TPropertySheet::EvActivate(uint active, bool minimized, THandle other)
{
  if (!UseNative) {
    // Store the handle of the focus window when we
    // are deactivated...
    //
    if (active == WA_INACTIVE)
      FocusHwnd = GetFocus();
  }
  TWindow::EvActivate(active, minimized, other);
}

//
// WM_SETFOCUS Handler
//
void
TPropertySheet::EvSetFocus(THandle hWndLostFocus)
{
  if (!UseNative) {
    // Restore focus to the saved 'Focus' window
    //
    if (FocusHwnd && ::IsWindow(FocusHwnd))
      ::SetFocus(FocusHwnd);
  }
  TWindow::EvSetFocus(hWndLostFocus);
}

//
// WM_GETFONT Handler
//
HFONT
TPropertySheet::EvGetFont()
{
  if (!UseNative) {
    if (Font) {
      return *Font;
    }
  }
  return HFONT(DefaultProcessing());
}

//
// TCN_SELCHANGE Handler
//
void
TPropertySheet::TabSelChange(TNotify far&)
{
  if (!UseNative) {
    int index = Tab->GetSel();
    SetActivePage(index);
  }
  else {
    DefaultProcessing();
  }
}

//
// TCN_SELCHANGING Handler
//
bool
TPropertySheet::TabSelChanging(TNotify far&)
{
  if (!UseNative) {
    // Do not veto any tab changes
    //
    return false;
  }
  else {
    return DefaultProcessing() != 0;
  }
}

//
// TCN_KEYDOWN Handler
//
void
TPropertySheet::TabKeyDown(TTabKeyDown far&)
{
  if (!UseNative) {
    //
    // NOP
  }
  else {
    DefaultProcessing();
  }
}

//
// WM_COMMAND, code==0 (BN_CLICKED) handler
//
void            
TPropertySheet::ButtonClicked(uint id) 
{
  if (UseNative)
    DefaultProcessing();
  else {
    switch (id) {
      case  IDOK:
            Apply();
            CloseWindow(id);
            break;

      case  IDCANCEL:
            Destroy(id);
            break;

      case  ID_APPLY:
            Apply();
            break;

            break;
    }
  }
}

//
//
//
HWND
TPropertySheet::CreateButton(int id, const char* caption)
{
  return ::CreateWindow("BUTTON", caption, BS_PUSHBUTTON|WS_CHILD|WS_GROUP|
                        WS_TABSTOP|WS_VISIBLE, 0, 0, 0, 0, *this, HMENU(id),
                        *GetModule(), 0);
}

//
// Position the buttons of the property sheet
//
bool
TPropertySheet::CreateButtons()
{
  char rc[_MAX_PATH];
  int size = defBtnSz;
  TSheetBtnInfo* info = defBtn;
  for (int i=0; i<size; i++) {
    char* p = GetModule()->LoadString(info[i].strId, rc, sizeof(rc)) ? 
                                      rc : info[i].defStr;
    HWND btn = CreateButton(defBtn[i].id, p);
    if (!btn)
      return false;
    if (Font)
      ::SendMessage(btn, WM_SETFONT, WPARAM(HFONT(*Font)), TRUE);  
  }
  return true;
}

//
//
bool
TPropertySheet::UpdateButtons()
{
  TRect rect;
  GetClientRect(rect);
  int x = rect.right  - (Margin+ButtonSize.cx);
  int y = rect.bottom - (Margin+ButtonSize.cy);
  HWND btn;
  for (int i=0; i<sizeof(defBtn)/sizeof(defBtn[0]); i++) {
    btn = GetDlgItem(defBtn[i].id);
    if (btn) {
      ::MoveWindow(btn, x, y, ButtonSize.cx, ButtonSize.cy, TRUE);
      x -= (Margin+ButtonSize.cx);
    }
  }      
  
  btn = GetDlgItem(ID_APPLY);
  if (btn)
    ::EnableWindow(btn, ApplyEnabled ? TRUE : FALSE);

  return true; 
}

//
// Returns the TProperPage* of the active page
//
TPropertyPage*
TPropertySheet::GetActivePage() const
{
  return (ActiveIndex < 0) ? 0 : PageAtIndex(ActiveIndex);
}

//
// Activates the page at the specified index
//
bool
TPropertySheet::SetActivePage(int index)
{
  PRECONDITION(index < GetPageCount());
  PRECONDITION(index < Tab->GetCount());
  PRECONDITION(GetHandle());

  // Retrieve pointer to page
  //
  TPropertyPage* page = PageAtIndex(index);
  CHECK(page);

  // Create the page/dialog if necessary
  //
  if (!page->GetHandle()) {
    if (!page->GetParentO())
      page->SetParent(this);
    page->Create();
  }

  // If it's the very first page, skip the positioning - we're in a
  // catch-22 [The sheet/tab can only be positioned after the first
  // page is created since we need a page to invoke MapDialogRect, and
  // the page can only be positioned after the sheet/tab has been
  // positioned.]
  //
  if (ActiveIndex == -1) {
    ActiveIndex = index;
    return true;
  }

  // Position page if it's not current active and hide current
  //
  TPropertyPage* curActive = GetActivePage();
  if (curActive != page) {
    PositionPage(page);
    if (curActive)
      curActive->ShowWindow(SW_HIDE);
  }

  // Select appropriate tab, if necessary
  //
  if (Tab->GetSel() != index)
    Tab->SetSel(index);

  // Update 'ActiveIndex'
  //
  ActiveIndex = index;
  return true;
}

//
// Callback used to set the text of tab items to the captions of a page.
//
static void
addTabItems(TPropertyPage* page, TTabControl* tab)
{
  // Retrieve the caption of the page
  //
  char txt[MaxTabTextLen];
  page->GetPageCaption(txt, sizeof(txt));

  // Set the text and have the tab control store the pointer
  // to the page in the application-defined space allocated
  // to each tab entry...
  //
  tab->Add(TTabItem(txt, 0, TParam2(page)));
}

//
// Synchronize tabs labels with current pages of the sheet
//
void
TPropertySheet::SyncTabAndPages()
{
  // Clear every tab item
  //
  Tab->DeleteAll();

  // Add the dialog/page titles to the tabs
  //
  ForEachPage(TActionPageFunc(addTabItems), Tab);
}

//
// Computes size/spacing of buttons using the active dialog and predefined
// dialog base units measurements
//
void
TPropertySheet::ComputeMarginAndButton()
{
  PRECONDITION(GetActivePage());

  // Margin       == 5 dlg units
  // Button Size  == 50x15 dlg units
  //
  TRect rect(5, 0, 50, 15); 
  GetActivePage()->MapDialogRect(rect);
  ButtonSize.cx = rect.right;
  ButtonSize.cy = rect.bottom;
  Margin = rect.left;
}

//
// Update the sheet's size to accomodate a page of the specified size.
//
void
TPropertySheet::UpdateTabAndSheetSize(const TRect& pageRect)
{
  // Update the tab's size to that it contains the page within its client
  // area...
  //
  TRect rect = pageRect;
  Tab->AdjustRect(true, rect);
  rect.MoveTo(Margin, Margin);
  Tab->SetWindowPos(0, rect, SWP_NOZORDER|SWP_NOACTIVATE);

  // Now update the sheet so that it contains the tab within its client area...
  //
  AdjustWindowRectEx(rect, GetStyle(), false, GetExStyle());

  // Lengthen the sheet to leave room for button and widen for margins
  //
  rect.bottom += ButtonSize.cy + Margin*3;
  rect.right += Margin*2;

  // Move sheet in relation to parent/owner
  //
  if (GetParentO() && GetParentO()->GetHandle()) {
    TRect rc;
    GetParentO()->GetWindowRect(rc);
    rect.MoveTo(rc.left + TUIMetric::CyMenu, rc.top + TUIMetric::CyMenu);
    if (rect.left < 0)
      rect.MoveTo(-rect.left, rect.top);
    else if (rect.right > TUIMetric::CxScreen)
      rect.MoveTo(TUIMetric::CxScreen-rect.Width(), rect.top);
    if (rect.top < 0)
      rect.MoveTo(rect.left, -rect.top);
    else if (rect.bottom > TUIMetric::CyScreen)
      rect.MoveTo(rect.left, TUIMetric::CyScreen-rect.Height());
  }

  // Update the sheet's size to accomodate
  //
  SetWindowPos(0, rect, SWP_NOZORDER|SWP_NOACTIVATE);
}

//
// Update a page's location within the sheet
//
void
TPropertySheet::PositionPage(TPropertyPage* page)
{
  // Retrieve area of tab (in terms of sheet window)
  //
  TRect rect;
  Tab->GetWindowRect(rect);
  ::MapWindowPoints(HWND_DESKTOP, *this, LPPOINT(&rect), 2);

  // Retrieve size of page
  //
  TRect pgRect;
  page->GetWindowRect(pgRect);

  // Request the tab for it's client area's rectangle
  //
  Tab->AdjustRect(false, rect);

  // Center the page
  //
  if (pgRect.Width() < rect.Width())
    rect.left += (rect.Width() - pgRect.Width())/2;
  if (pgRect.Height() < rect.Height())
    rect.top  += (rect.Height()- pgRect.Height())/2;
  page->SetWindowPos(HWND_TOP, rect, SWP_NOSIZE|SWP_SHOWWINDOW|SWP_NOACTIVATE);
}

//
// Returns the index of the tab item representing the specified page. Returns 
// -1 if the page is not currently represented by a tab item.
//
int
TPropertySheet::TabIndexOfPage(const TPropertyPage* page) const
{
  PRECONDITION(page);
  PRECONDITION(Tab && Tab->GetHandle());

  int i = Tab->GetCount();
  while(i) {
    TTabItem item(TCIF_PARAM);
    Tab->GetItem(--i, item);
    if (item.lParam == LPARAM(page))
      return i;
  }
  return -1;
}

//
// Returns the TPropertyPage pointer represented by the tab item at the 
// specified 'index'. Returns '0' if there are no tab items at the specified 
// index.
//
TPropertyPage*
TPropertySheet::PageAtTabIndex(int index) const
{
  PRECONDITION(index >= 0);
  PRECONDITION(Tab && Tab->GetHandle());

  TTabItem item(TCIF_PARAM);
  if (Tab->GetItem(index, item)) {
    return (TPropertyPage*)item.lParam;
  }
  return 0;
}
#endif  // !OWL_NATIVECTRL_ALWAYS



