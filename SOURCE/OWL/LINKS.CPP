//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//----------------------------------------------------------------------------
#define INC_OLE2
#include <owl/owlpch.h>
#include <owl/listbox.h>
#include <owl/radiobut.h>
#include <owl/edit.h>
#include <ocf/ocview.h>
#include <owl/oledlg.h>
#include <owl/except.h>
#include <bwcc.h>   // for IDHELP
#include <dir.h>

static char szNULL[] = "";
DEFINE_GUID(IID_IOleUILinkContainer, 0x000004FF, 0x0000, 0x0000, 0xC0, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x46);

//
// OWL OLE Dialog diagnostic group.
//
DIAG_DECLARE_GROUP(OwlOleDlg);


//
// Constructor of customized (for validation) FileOpen dialog
//
TEditLinksDlg::TChgSrcFileOpenDlg::TChgSrcFileOpenDlg(TWindow* parent,
                                                      TData&   data,
                                                      TChgSrcData& chgSrcData,
                                                      TResId   templateId,
                                                      const char far* title,
                                                      TModule* module)
:
  TFileOpenDialog(parent, data, templateId, title, module),
  ChgSrcData(chgSrcData), Helper(*new THelper)
{
}



//
// Cleanup memory allocated
//
TEditLinksDlg::TChgSrcFileOpenDlg::~TChgSrcFileOpenDlg()
{
  delete &Helper;
}


//
// Initializes custom FileOpen dialog
//
void TEditLinksDlg::TChgSrcFileOpenDlg::SetupWindow()
{
  TLinkInfo far* lpLinkInfo = ChgSrcData.lpLI;

  Helper.bFileNameStored = true;
  Helper.bItemNameStored = true;
  if (lpLinkInfo->lpszDisplayName) {
    strcpyn(Helper.szFileName, lpLinkInfo->lpszDisplayName, MaxPathLen);
    strcpyn(Helper.szEdit, lpLinkInfo->lpszDisplayName, MaxPathLen);
  }
  if (lpLinkInfo->lpszItemName) {
    strcpyn(Helper.szItemName, lpLinkInfo->lpszItemName, MaxPathLen);
  }
}


//
// Builds a TEditLinksDlg::TData using a TOcView - retrieves
// Bolero's implemetation of the IOLEUILinkContainer interface.
//
TEditLinksDlg::TData::TData(const TOcView& ocView)
{
  dwFlags = elShowHelp;

  //
  // Retrieve BOLERO's IOLEUILinkContainer Interface
  //
  lpOleUILinkContainer = 0;
  CONST_CAST(TOcView*, &ocView)->QueryInterface(IID_IOleUILinkContainer,
                                &(LPVOID)lpOleUILinkContainer);
}


//
// Release Bolero's IOLEUILinkContainer Interface
//
TEditLinksDlg::TData::~TData()
{
  //
  // Release BOLERO's IOLEUILinkContainer Interface
  //
  if (lpOleUILinkContainer)
    lpOleUILinkContainer->Release();
}


//
// Constructor of structure which keeps track of the state of
// a particular link.
// NOTE: The 'link' parameter is a container-defined unique
//       identifier for each link - Bolero provides this
//       value.
//
TEditLinksDlg::TLinkInfo::TLinkInfo(DWORD link)
{
  dwLink            = link;
  lpszDisplayName   = 0;
  lpszItemName      = 0;
  lpszShortFileName = 0;
  lpszShortLinkType = 0;
  lpszFullLinkType  = 0;
  clenFileName      = 0;
  fSourceAvailable  = false;
  fIsAuto           = false;
  fIsMarked         = false;
  fDontFree         = false;
  fIsSelected       = false;

  lpszAMX    = new char[LinkTypeLen+1];
  lpszAMX[0] = 0;
}


//
// Cleanup memory.
//
TEditLinksDlg::TLinkInfo::~TLinkInfo()
{
  if (lpszAMX)
   delete []lpszAMX;
}


//
// Initialized Helper object used internally by TEditLinksDlg
//
TEditLinksDlg::THelper::THelper()
{
  //
  // Use memset to initialize private PODS
  //
  memset(this, 0, sizeof(THelper));
}


//
// Initializes data structure for Custom FileOpen dialog.
//
TEditLinksDlg::TChgSrcFileOpenDlg::TChgSrcData::TChgSrcData(TLinkInfo far* li,
                                             TEditLinksDlg::TData& data) :
                                             Data(data)
{
  lpLI = li;
  lpszFrom = 0;
  lpszTo   = 0;
  fValidLink = false;
}


DEFINE_RESPONSE_TABLE1(TEditLinksDlg, TOleDialog)
  EV_WM_COMPAREITEM,
  EV_WM_DRAWITEM,
  EV_WM_DELETEITEM,
  EV_WM_MEASUREITEM,
  EV_BN_CLICKED(IDC_CHANGESOURCE, ChangeSourceClicked),
  EV_BN_CLICKED(IDC_AUTOMATIC, AutomaticClicked),
  EV_BN_CLICKED(IDC_MANUAL, ManualClicked),
  EV_BN_CLICKED(IDC_BREAKLINK, BreakLinkClicked),
  EV_BN_CLICKED(IDC_UPDATENOW, UpdateNowClicked),
  EV_BN_CLICKED(IDC_OPENSOURCE, OpenSourceClicked),
END_RESPONSE_TABLE;


//
//
//
TEditLinksDlg::TEditLinksDlg(TWindow* parent,
                             const TOcView &ocView,
                             TResId templateId,
                             const char far* title,
                             TModule* module):
               TOleDialog(parent,
                          templateId ? templateId : TResId(DLG_EDITLINKS),
                          title, module), Helper(*new THelper)
{
  LinksList     = new TListBox(this, IDC_LINKLIST);
  UpdateBtn     = new TButton(this, IDC_UPDATENOW);
  OpenBtn       = new TButton(this, IDC_OPENSOURCE);
  ChangeBtn     = new TButton(this, IDC_CHANGESOURCE);
  BreakLinkBtn  = new TButton(this, IDC_BREAKLINK);
  Automatic     = new TRadioButton(this, IDC_AUTOMATIC);
  Manual        = new TRadioButton(this, IDC_MANUAL);
  LinkSource    = new TStatic(this, IDC_SOURCE);
  LinkType      = new TStatic(this, IDC_TYPE);
  Help          = new TButton(this, IDHELP);
  Cancel        = new TButton(this, IDCANCEL);
  Data          = new TData(ocView);

  nMaxCharWidth = 0;
  nHeightLine   = 0;
}


//
// Cleanup objects allocated
//
TEditLinksDlg::~TEditLinksDlg()
{
  delete Data;
  delete &Helper;
}


//
//
//
bool
TEditLinksDlg::EvInitDialog(HWND hwndFocus)
{
  //
  // Chain to base allow control aliasing
  //
  TOleDialog::EvInitDialog(hwndFocus);

  //
  // Compute column position of listbox
  //
  TRect rect;
  LinksList->GetWindowRect(rect);

  int nStart = rect.left;
  ::GetWindowRect(GetDlgItem(IDC_COL1), &rect);
  nColPos[0] = rect.left - nStart;

  ::GetWindowRect(GetDlgItem(IDC_COL2), &rect);
  nColPos[1] = rect.left - nStart;

  ::GetWindowRect(GetDlgItem(IDC_COL3), &rect);
  nColPos[2] = rect.left - nStart;

  //
  // Fill listbox with
  //
  Helper.fItemsExist = LoadLinkLB() ? true : false;

  //
  //
  //
  InitControls();

  //
  // Hide/Disable controls based on flag settings
  //
  if  (!(Data->dwFlags & elShowHelp))
    Activate(Help, false);

  if (Data->dwFlags & elDisableUpdateNow)
    Activate(UpdateBtn, false);

  if (Data->dwFlags & elDisableOpenSource)
    Activate(OpenBtn, false);

  if (Data->dwFlags & elDisableChangeSource)
    Activate(ChangeBtn, false);

  if (Data->dwFlags & elDisableCancelLink)
    Activate(BreakLinkBtn, false);

  //
  // Retrieve 'Close' string to rename CANCEL button
  //
  GetModule()->LoadString(IDS_CLOSE, Helper.szClose, sizeof(Helper.szClose));

  //
  // Set focus to listbox if we have links
  //
  if (Helper.fItemsExist > 0)
    LinksList->SetFocus();
  else
    ::SetFocus(GetDlgItem(IDCANCEL));

  return false;
}


//
//
//
int
TEditLinksDlg::DoExecute()
{
  return TDialog::DoExecute();
}


//
//
//
void
TEditLinksDlg::EvMeasureItem(uint ctlId, MEASUREITEMSTRUCT far& measureInfo)
{
  if (ctlId != IDC_LINKLIST) {
    TOleDialog::EvMeasureItem(ctlId, measureInfo);
    return;
  }

  HFONT hFont = GetWindowFont();
  if (!hFont)
    hFont = (HFONT)GetStockObject(SYSTEM_FONT);

  TFont font(hFont);
  TClientDC hdc(*this);
  hdc.SelectObject(font);

  TEXTMETRIC tm;
  hdc.GetTextMetrics(tm);

  measureInfo.itemHeight = tm.tmHeight;
  nHeightLine   = tm.tmHeight;
  nMaxCharWidth = tm.tmMaxCharWidth;

  hdc.RestoreFont();
}


//
//
//
int
TEditLinksDlg::LBPad() const
{
  return nMaxCharWidth > 0 ? nMaxCharWidth : 5;
}


//
//
//
void
TEditLinksDlg::EvDrawItem(uint ctlId, DRAWITEMSTRUCT far& drawInfo)
{
  if (ctlId != IDC_LINKLIST) {
    TOleDialog::EvDrawItem(ctlId, drawInfo);
    return;
  }

  if ((int)drawInfo.itemID < 0)
    return;

  if (drawInfo.itemAction & (ODA_DRAWENTIRE | ODA_SELECT))
    DrawLinksListEntry(drawInfo);

  InitControls();

  if (drawInfo.itemAction & ODA_FOCUS)  {
    DrawFocusRect(drawInfo.hDC, &drawInfo.rcItem);
  }
}


//
//
//
void
TEditLinksDlg::DrawLinksListEntry(DRAWITEMSTRUCT far& drawInfo)
{
  TDC dc(drawInfo.hDC);
  TLinkInfo* lpLinkInfo = (TLinkInfo*)drawInfo.itemData;

  //
  // Update selection flag and set text color (if selected)
  //
  TColor oldTxtColor;
  if (drawInfo.itemState & ODS_SELECTED) {
    oldTxtColor = dc.SetTextColor(TColor(GetSysColor(COLOR_HIGHLIGHTTEXT)));
    lpLinkInfo->fIsSelected = true;
  }
  else {
    lpLinkInfo->fIsSelected = false;
  }

  //
  // Fill background
  //
  TBrush brush(GetSysColor(drawInfo.itemState & ODS_SELECTED ? COLOR_HIGHLIGHT :
                                          COLOR_WINDOW));
  dc.FillRect(drawInfo.rcItem, brush);

  //
  // Set transparent mode
  //
  int oldMode;
  oldMode = dc.SetBkMode(TRANSPARENT);

  TRect rcClip;
  char* pStr;
  char str[MaxPathLen];
  if (lpLinkInfo->lpszDisplayName) {
    strcpy(str, lpLinkInfo->lpszDisplayName);
    pStr = ChopText(*LinksList, nColPos[1] - nColPos[0] - LBPad(), str);

    rcClip = drawInfo.rcItem;
    rcClip.left  += nColPos[0];
    rcClip.right  = drawInfo.rcItem.left + (nColPos[1] - LBPad());

    dc.ExtTextOut(rcClip.left, rcClip.top, ETO_CLIPPED, &rcClip, pStr,
                  strlen(pStr));
  }

  if (lpLinkInfo->lpszShortLinkType) {
    rcClip = drawInfo.rcItem;
    rcClip.left += nColPos[1];
    rcClip.right = drawInfo.rcItem.left + nColPos[2] - LBPad();
    dc.ExtTextOut(rcClip.left, rcClip.top, ETO_CLIPPED, &rcClip,
                  lpLinkInfo->lpszShortLinkType,
                  strlen(lpLinkInfo->lpszShortLinkType));
  }

  if (lpLinkInfo->lpszAMX) {
    rcClip = drawInfo.rcItem;
    rcClip.left += nColPos[2];
    dc.ExtTextOut(rcClip.left, rcClip.top, ETO_CLIPPED, &rcClip,
                  lpLinkInfo->lpszAMX, strlen(lpLinkInfo->lpszAMX));
  }

  //
  // Restore DC attributes
  //
  dc.SetBkMode(oldMode);
  if (drawInfo.itemState & ODS_SELECTED)
    dc.SetTextColor(oldTxtColor);
}


//
//
//
LRESULT
TEditLinksDlg::EvCompareItem(uint ctlid, COMPAREITEMSTRUCT far& compareInfo)
{
  if (ctlid != IDC_LINKLIST) {
    return TOleDialog::EvCompareItem(ctlid, compareInfo);
  }

  TLinkInfo* lpLI1 = (TLinkInfo*)compareInfo.itemData1;
  TLinkInfo* lpLI2 = (TLinkInfo*)compareInfo.itemData2;

  if (lpLI1->lpszDisplayName  && lpLI2->lpszDisplayName)
    return strcmp(lpLI1->lpszDisplayName, lpLI2->lpszDisplayName);

  return 0;
}


//
//
//
void
TEditLinksDlg::EvDeleteItem(uint ctlid, DELETEITEMSTRUCT far& deleteInfo)
{
  if (ctlid != IDC_LINKLIST) {
    TOleDialog::EvDeleteItem(ctlid, deleteInfo);
    return;
  }

  TLinkInfo* lpLinkInfo = (TLinkInfo*)deleteInfo.itemData;

  if (lpLinkInfo->lpszDisplayName)
    delete []lpLinkInfo->lpszDisplayName;

  if (lpLinkInfo->lpszShortLinkType)
    delete []lpLinkInfo->lpszShortLinkType;

  if (lpLinkInfo->lpszFullLinkType)
    delete []lpLinkInfo->lpszFullLinkType;

  if (lpLinkInfo->fDontFree)
    lpLinkInfo->fDontFree = false;
  else
    delete lpLinkInfo;
}


//
// Handles ChangeSource button by displaying a customized version
// of FileOpen dialog with the LinkName.
//
void
TEditLinksDlg::ChangeSourceClicked()
{
  if (!Container_ChangeSource())
    PopupMessage(IDS_FAILED, IDS_LINKS, MB_ICONEXCLAMATION|MB_OK);
  InitControls();
}


//
// Sets a Link [or Links for multiple selections] to automatic
//
void
TEditLinksDlg::AutomaticClicked()
{
  CheckDlgButton(IDC_AUTOMATIC, BF_CHECKED);
  CheckDlgButton(IDC_MANUAL, BF_UNCHECKED);

  if (Container_AutomaticManual(true) != NOERROR)
    PopupMessage(IDS_FAILED, IDS_LINKS, MB_ICONEXCLAMATION|MB_OK);

  InitControls();
}


//
// Set Link [or Links for multiple selections] to manual
//
void
TEditLinksDlg::ManualClicked()
{
  CheckDlgButton(IDC_MANUAL, BF_CHECKED);
  CheckDlgButton(IDC_AUTOMATIC, BF_UNCHECKED);

  if (Container_AutomaticManual(false) != NOERROR)
    PopupMessage(IDS_FAILED, IDS_LINKS, MB_ICONEXCLAMATION|MB_OK);

  InitControls();
}


//
// Breaks the Link.
// NOTE: Object retains its data and becomes a static object
//
void
TEditLinksDlg::BreakLinkClicked()
{
  CancelLink();
  InitControls();
}


//
// Causes immediate update of Link(s). Will start Servers if necessary.
//
void
TEditLinksDlg::UpdateNowClicked()
{
  Container_UpdateNow();
  InitControls();
}


//
// Open the current selection.
// NOTE: This options causes the dialog to close.
//
void
TEditLinksDlg::OpenSourceClicked()
{
  if (Container_OpenSource() != NOERROR)
    InitControls();
  else  {
    //
    // Terminate dialog by simulating an OK
    //
    SendNotification(IDOK, BN_CLICKED, GetDlgItem(IDOK));
  }
}


//
//
//
bool
TEditLinksDlg::ChangeSource(char* file,
                            TChgSrcFileOpenDlg::TChgSrcData& chgSrcData,
                            uint filterId)
{
  if (!file)
   return false;

  //
  // Load Filter(s) string
  //
  char* pFilter = 0;
  TPointer<char> filters = new char[MaxPathLen];
  if (GetModule()->LoadString(filterId, filters, MaxPathLen))
    pFilter = filters;

  //
  // Load Title string
  //
  char* pTitle = 0;
  TPointer<char> title = new char[MaxPathLen];
  if (GetModule()->LoadString(IDS_CHANGESOURCE, title, MaxPathLen))
    pTitle = title;

  //
  // Attempt to retrieve initial directory from file name
  //
  char *pInitDir = 0;
  char *initDir = new char[MaxPathLen];
  TPointer<char> _cln(initDir);
  strcpyn(initDir, file, MaxPathLen);
  for (int i=strlen(initDir)-1; i>=0; i--) {
    if ((initDir[i]=='\\') || (initDir[i]==':') || (initDir[i]=='/'))
      break;
  }
  if (i > 0) {
    initDir[i] = 0;
    pInitDir  = initDir;
  }

  //
  // Execute customized fileOpen dialog
  //
  TPointer<TOpenSaveDialog::TData> data =
      new TOpenSaveDialog::TData(OFN_NOVALIDATE|OFN_HIDEREADONLY,
                                 pFilter, 0, pInitDir);

  TChgSrcFileOpenDlg foDlg(this, *data, chgSrcData,
                           TResId(DLG_FILEOPEN), pTitle);
  if (foDlg.Execute()==IDOK) {
    return true;
  }
  return false;
}


//
// Allows user to change Links using a customized FileOpen dialog.
//
bool
TEditLinksDlg::Container_ChangeSource()
{
  int* rgIndex  = 0;
  int cSelItems = GetSelectedItems(rgIndex);

  if (cSelItems < 0)
    return false;

  if (!cSelItems)
    return true;

  if (!Helper.fClose) {
    Cancel->SetWindowText(Helper.szClose);
    Helper.fClose = true;
  }

  TLinkInfo FAR *lpLinkInfo;
  for( int i=cSelItems-1; i>=0; i--) {
    //
    // Retrieve link information
    //
    LinksList->HandleMessage(LB_GETTEXT, rgIndex[i],
                            (LPARAM)(TLinkInfo far*)&lpLinkInfo);

    //
    // Data for dialog
    //
    TChgSrcFileOpenDlg::TChgSrcData chgSrcData(lpLinkInfo, *Data);

    if (!ChangeSource(lpLinkInfo->lpszDisplayName,
                      chgSrcData, IDS_FILTERS)) {
      //
      // The Cancel button was probably pressed - Stop processing
      // for all remaining links
      //
      delete []rgIndex;
      return true;
    }

    UpdateLinkLBItem(rgIndex[i], true);

    if (chgSrcData.lpszFrom  && chgSrcData.lpszTo) {
      ChangeAllLinks(chgSrcData.lpszFrom, chgSrcData.lpszTo);

      //! BB - Need to free lpszFrom and lpszTo???
    }
  }

  delete []rgIndex;
  return true;
}


//
//
//
HRESULT
TEditLinksDlg::Container_AutomaticManual(bool fAutoMan)
{
  HRESULT hErr  = NOERROR;
  int* rgIndex  = 0;
  int cSelItems = GetSelectedItems(rgIndex);

  if (cSelItems < 0)
    return ResultFromScode(E_FAIL);

  if (!cSelItems)
    return NOERROR;

  if (!Helper.fClose) {
    Cancel->SetWindowText(Helper.szClose);
    Helper.fClose = true;
  }

  bool bUpdate = false;
  TLinkInfo*  lpLinkInfo;
  LPOLEUILINKCONTAINER lpLnkCntnr = Data->lpOleUILinkContainer;

  for (int i=0; i < cSelItems; i++) {
    LinksList->HandleMessage(LB_GETTEXT, rgIndex[i],
                            (LPARAM)(TLinkInfo far*)&lpLinkInfo);
    if (fAutoMan) {
      if (!lpLinkInfo->fIsAuto) {
        hErr = lpLnkCntnr->SetLinkUpdateOptions(lpLinkInfo->dwLink,
                                                OLEUPDATE_ALWAYS);
        lpLinkInfo->fIsAuto = true;
        lpLinkInfo->fIsMarked = true;
        bUpdate = true;
      }
    }
    else {
      if (lpLinkInfo->fIsAuto) {
        hErr = lpLnkCntnr->SetLinkUpdateOptions(lpLinkInfo->dwLink,
                                                OLEUPDATE_ONCALL);
        lpLinkInfo->fIsAuto = false;
        lpLinkInfo->fIsMarked = true;
        bUpdate = true;
      }
    }
  }

  if (bUpdate)
    RefreshLinkLB();

  if (rgIndex)
    delete []rgIndex;

  return hErr;
}


HRESULT
TEditLinksDlg::CancelLink()
{
  HRESULT hErr  = NOERROR;
  int* rgIndex  = 0;
  int cSelItems = GetSelectedItems(rgIndex);

  if (cSelItems < 0)
    return ResultFromScode(E_FAIL);

  if (!cSelItems)
    return NOERROR;

  if (!Helper.fClose) {
    Cancel->SetWindowText(Helper.szClose);
    Helper.fClose = true;
  }

  bool bUpdate = false;
  TLinkInfo* lpLinkInfo;
  LPOLEUILINKCONTAINER lpLnkCntnr = Data->lpOleUILinkContainer;

  for (int i=0; i<cSelItems; i++) {
    LinksList->HandleMessage(LB_GETTEXT, rgIndex[i],
                            (LPARAM)(TLinkInfo far*)&lpLinkInfo);

    hErr = lpLnkCntnr->CancelLink(lpLinkInfo->dwLink);

    if (hErr != NOERROR) {
      lpLinkInfo->fIsMarked = true;
      bUpdate = true;
    }
    else {
      LinksList->DeleteString(rgIndex[i]);
    }
  }

  if (bUpdate)
    RefreshLinkLB();

  if (rgIndex)
    delete []rgIndex;

  return hErr;
}


//
//
//
HRESULT
TEditLinksDlg::Container_UpdateNow()
{
  HRESULT hErr   = NOERROR;
  int* rgIndex   = 0;
  int cSelItems  = GetSelectedItems(rgIndex);

  if (cSelItems < 0)
    return ResultFromScode(E_FAIL);

  if (!cSelItems)
    return NOERROR;

  if (!Helper.fClose) {
    Cancel->SetWindowText(Helper.szClose);
    Helper.fClose = true;
  }

  bool bUpdate = false;
  TLinkInfo FAR *lpLinkInfo;
  LPOLEUILINKCONTAINER lpLnkCntnr = Data->lpOleUILinkContainer;

  for (int i=0; i<cSelItems; i++) {
    LinksList->HandleMessage(LB_GETTEXT, rgIndex[i],
                            (LPARAM)(TLinkInfo far*)&lpLinkInfo);

    hErr = lpLnkCntnr->UpdateLink(lpLinkInfo->dwLink, true, false);
    bUpdate = true;
    lpLinkInfo->fIsMarked = true;

    if (hErr != NOERROR)
      break;
  }

  if (bUpdate)
    RefreshLinkLB();

  if (rgIndex)
    delete []rgIndex;

  return hErr;
}


//
//
//
HRESULT
TEditLinksDlg::Container_OpenSource()
{
  HRESULT hErr   = NOERROR;
  int* rgIndex   = 0;
  int cSelItems  = GetSelectedItems(rgIndex);

  if (cSelItems < 0)
    return ResultFromScode(E_FAIL);

  if (cSelItems != 1) {
    TRACEX(OwlOleDlg, 1, "Attempt to open source of multiple items.");
    return NOERROR;
  }

  if (!Helper.fClose) {
    Cancel->SetWindowText(Helper.szClose);
    Helper.fClose = true;
  }

  TLinkInfo* lpLinkInfo;
  LinksList->HandleMessage(LB_GETTEXT, rgIndex[0],
                          (LPARAM)(TLinkInfo far*)&lpLinkInfo);

  LPOLEUILINKCONTAINER lpLnkCntnr = Data->lpOleUILinkContainer;
  hErr = lpLnkCntnr->OpenLinkSource(lpLinkInfo->dwLink);

  UpdateLinkLBItem(rgIndex[0], true);

  if (rgIndex)
    delete []rgIndex;

  return hErr;
}


//
//
//
void
TEditLinksDlg::BreakString(TLinkInfo* lpLinkInfo)
{
  if (!lpLinkInfo->clenFileName  ||
      (strlen(lpLinkInfo->lpszDisplayName) == lpLinkInfo->clenFileName)) {
    lpLinkInfo->lpszItemName = 0;
  }
  else {
    lpLinkInfo->lpszItemName = lpLinkInfo->lpszDisplayName +
                               (int)lpLinkInfo->clenFileName;
  }

  char* str;
  str = lpLinkInfo->lpszDisplayName + strlen(lpLinkInfo->lpszDisplayName);
  while (str > lpLinkInfo->lpszDisplayName) {
    str = AnsiPrev(lpLinkInfo->lpszDisplayName, str);
    if ((*str == '\\') || (*str == '/') || (*str == ':'))
      break;
  }

  if (str == lpLinkInfo->lpszDisplayName)
    lpLinkInfo->lpszShortFileName = str;
  else
    lpLinkInfo->lpszShortFileName = AnsiNext(str);
}


//
//
//
int
TEditLinksDlg::GetSelectedItems(int* &lprgIndex)
{
  lprgIndex = 0;

  int count = LinksList->GetSelCount();

  if (count < 0)    // Error
    return count;

  if (count == 0)
    return 0;

  lprgIndex = new int[count];

  if (LinksList->GetSelIndexes(lprgIndex, count) == count) {
    return count;   // Caller will free lprgIndex!
  }
  else {
    if (lprgIndex)
      delete []lprgIndex;
    lprgIndex = 0;
    return 0;
  }
}


//
// Update state of Auto/Manual, Link Source and Link Type information based
// on currently selected entry
//
void
TEditLinksDlg::InitControls()
{
  int* rgIndex   = 0;
  int cSelItems  = GetSelectedItems(rgIndex);
  if (cSelItems < 0)      // Error!
    return;

  //
  // Enable/Disable controls
  //
  Automatic->EnableWindow(cSelItems ? true : false);
  Manual->EnableWindow(cSelItems ? true : false);

  if (!(Data->dwFlags & elDisableCancelLink))
    BreakLinkBtn->EnableWindow(cSelItems ? true : false);

  if (!(Data->dwFlags & elDisableOpenSource))
    OpenBtn->EnableWindow(cSelItems ? true : false);

  if (!(Data->dwFlags & elDisableChangeSource))
    ChangeBtn->EnableWindow(cSelItems ? true : false);

  if (!(Data->dwFlags & elDisableUpdateNow))
    UpdateBtn->EnableWindow(cSelItems ? true : false);

  int cAuto = 0;
  int cManual = 0;
  char* lpszType   = 0;
  char* lpszSource = 0;
  bool bSameType   = true;
  bool bSameSource = true;
  TLinkInfo* lpLinkInfo;
  for (int i=0; i < cSelItems; i++) {
    LinksList->HandleMessage(LB_GETTEXT, rgIndex[i],
                            (LPARAM)(TLinkInfo far*)&lpLinkInfo);
    if (lpszSource && lpLinkInfo->lpszDisplayName) {
      if (bSameSource  &&  strcmp(lpszSource, lpLinkInfo->lpszDisplayName)) {
        bSameSource = false;
      }
    }
    else {
      lpszSource = lpLinkInfo->lpszDisplayName;
    }

    if (lpszType  && lpLinkInfo->lpszFullLinkType) {
      if (bSameType  && strcmp(lpszType, lpLinkInfo->lpszFullLinkType)) {
        bSameType = false;
      }
    }
    else {
      lpszType = lpLinkInfo->lpszFullLinkType;
    }

    if (lpLinkInfo->fIsAuto)
      cAuto++;
    else
      cManual++;
  }

  CheckDlgButton(IDC_AUTOMATIC, cAuto && !cManual);
  CheckDlgButton(IDC_MANUAL, !cAuto && cManual);

  if (!bSameSource || !lpszSource)
    lpszSource = szNULL;

  char* lpsz = szNULL;
  TPointer<char> sz = new char[MaxPathLen];
  strcpy(sz, lpszSource);
  lpsz = ChopText(*LinkSource, 0, sz);
  LinkSource->SetText(lpsz);


  if (!bSameType || !lpszType)
    lpszType = szNULL;
  LinkType->SetText(lpszType);

  if (rgIndex)
    delete []rgIndex;
}


void
TEditLinksDlg::UpdateLinkLBItem(int nIndex, bool bSelect)
{
  if (nIndex <0)
   return;

  TLinkInfo* lpLinkInfo = 0;
  long result = (long)LinksList->HandleMessage(LB_GETTEXT, nIndex,
                                      (LPARAM)(TLinkInfo far*)&lpLinkInfo);

  if (result == LB_ERR  ||  !lpLinkInfo)
    return;

  lpLinkInfo->fDontFree = true;
  LinksList->DeleteString(nIndex);

  nIndex = AddLinkLBItem(lpLinkInfo, false);
  if (bSelect) {
    LinksList->SetSel(nIndex, true);
    LinksList->SetCaretIndex(nIndex, true);
  }
}


void
TEditLinksDlg::DiffPrefix(const char* lpsz1, const char* lpsz2,
                          char* &pref1, char* &pref2)
{
  PRECONDITION(lpsz1 && lpsz2 && *lpsz1 && *lpsz2);

  pref1 = 0;
  pref2 = 0;

  pref1 = new char[strlen(lpsz1)+1];
  pref2 = new char[strlen(lpsz2)+1];

  strcpy(pref1, lpsz1);
  strcpy(pref2, lpsz2);

  char* lpstr1 = pref1 + strlen(pref1);
  char* lpstr2 = pref2 + strlen(pref2);

  while ((lpstr1 > pref1) && (lpstr2 > pref2)) {
    lpstr1 = AnsiPrev(pref1, lpstr1);
    lpstr2 = AnsiPrev(pref1, lpstr2);
    if (*lpstr1 != *lpstr2) {
      lpstr1 = AnsiNext(lpstr1);
      lpstr2 = AnsiNext(lpstr2);
      break;
    }
  }

  while(*lpstr1 && *lpstr1!='\\' && *lpstr1!='!')
    lpstr1 = AnsiNext(lpstr1);

  while(*lpstr2 && *lpstr2!='\\' && *lpstr2!='!')
    lpstr2 = AnsiNext(lpstr2);

  *lpstr1 = 0;
  *lpstr2 = 0;
}


void
TEditLinksDlg::ChangeAllLinks(char* lpszFrom, char* lpszTo)
{
  bool bFound = false;
  int cFrom   = strlen(lpszFrom);
  int cItems  = LinksList->GetCount();

  char szTmp[MaxPathLen];
  TLinkInfo* lpLinkInfo = 0;
  for (int nIndex=0; nIndex<cItems; nIndex++) {
    LinksList->HandleMessage(LB_GETTEXT, nIndex,
                            (LPARAM)(TLinkInfo far*)&lpLinkInfo);

    lpLinkInfo->fIsMarked = false;

    if (!*(lpLinkInfo->lpszDisplayName + cFrom) ||
        (*(lpLinkInfo->lpszDisplayName + cFrom) == '\\') ||
        (*(lpLinkInfo->lpszDisplayName + cFrom) == '!')) {
      strcpyn(szTmp, lpLinkInfo->lpszDisplayName, cFrom+1);

      if (!strcmp(szTmp, lpszFrom)) {
        HRESULT hErr;
        int nFileLength;
        ULONG ulDummy;

        if (!bFound) {
          TPointer<char>  pTitle = new char[MaxPathLen];
          TPointer<char>  pMsg   = new char[MaxPathLen];
          TPointer<char>  pBuff  = new char[MaxPathLen];

          GetModule()->LoadString(IDS_CHANGESOURCE, (LPSTR)(char*)pTitle,
                                  MaxPathLen);
          GetModule()->LoadString(IDS_CHANGEADDITIONALLINKS,
                                  (LPSTR)(char*)pMsg, MaxPathLen);
          wsprintf((LPSTR)(char*)pBuff, (LPSTR)(char*)pMsg, lpszFrom);
          if (MessageBox((LPSTR)(char*)pBuff, (LPSTR)(char*)pTitle,
                          MB_ICONQUESTION|MB_YESNO) != IDYES)
            return;

          bFound = true;
        }

        strcpy(szTmp, lpszTo);
        strcat(szTmp, lpLinkInfo->lpszDisplayName + cFrom);

        nFileLength = strlen(szTmp) -
          (lpLinkInfo->lpszItemName ? strlen(lpLinkInfo->lpszItemName) : 0);

        LPOLEUILINKCONTAINER lpLnkCntnr = Data->lpOleUILinkContainer;
        hErr = lpLnkCntnr->SetLinkSource(lpLinkInfo->dwLink, szTmp,nFileLength,
                                         (ULONG FAR*)&ulDummy, true);
        if (hErr != NOERROR)
          lpLnkCntnr->SetLinkSource(lpLinkInfo->dwLink, szTmp, nFileLength,
                                    (ULONG FAR*)&ulDummy, false);
        lpLinkInfo->fIsMarked = true;
      }
    }
  }
}


int
TEditLinksDlg::AddLinkLBItem(TLinkInfo* lpLinkInfo, bool sel)
{
  PRECONDITION(lpLinkInfo);

  TOleAllocator oleAllocator;
  TRY {
    DWORD dwUpdateOpt;
    HRESULT hErr = NOERROR;
    lpLinkInfo->fDontFree = false;
    LPOLEUILINKCONTAINER lpLnkCntnr = Data->lpOleUILinkContainer;

    CHECK(lpLnkCntnr);

    //
    // Retrieve Link Source Information
    //
    LPSTR lpszDisplayName   = lpLinkInfo->lpszDisplayName;
    LPSTR lpszFullLinkType  = lpLinkInfo->lpszFullLinkType;
    LPSTR lpszShortLinkType = lpLinkInfo->lpszShortLinkType;
    hErr = lpLnkCntnr->GetLinkSource(lpLinkInfo->dwLink,
                                    &lpszDisplayName,
                                    &lpLinkInfo->clenFileName,
                                    &lpszFullLinkType,
                                    &lpszShortLinkType,
                                    &lpLinkInfo->fSourceAvailable,
                                    sel ? &lpLinkInfo->fIsSelected : 0);
    if (hErr != NOERROR)
      THROW(IDS_ERR_GETLINKSOURCE;)

    //
    // Ask for the Update Options
    //
    hErr = lpLnkCntnr->GetLinkUpdateOptions(lpLinkInfo->dwLink, &dwUpdateOpt);
    if (hErr != NOERROR)
      THROW(IDS_ERR_GETLINKUPDATEOPTIONS;)

    if (lpLinkInfo->fSourceAvailable) {
      if (dwUpdateOpt == OLEUPDATE_ALWAYS) {
        lpLinkInfo->fIsAuto = true;
        GetModule()->LoadString(IDS_LINK_AUTO, lpLinkInfo->lpszAMX,
                                LinkTypeLen+1);
      }
      else {
        lpLinkInfo->fIsAuto = false;
        GetModule()->LoadString(IDS_LINK_MANUAL, lpLinkInfo->lpszAMX,
                                LinkTypeLen+1);
      }
    }
    else {
      GetModule()->LoadString(IDS_LINK_UNKNOWN, lpLinkInfo->lpszAMX,
                              LinkTypeLen+1);
    }

    BreakString(lpLinkInfo);

    int index = (int)LinksList->HandleMessage(LB_ADDSTRING, 0,
                                             (LPARAM)lpLinkInfo);

    if (index == LB_ERR)
      THROW(IDS_ERR_ADDSTRING;)

    return index;
  }

  CATCH( ( int errMsgId) {                                        \
    //                                                            \
    // Display error message                                      \
    //                                                            \
    PopupMessage(errMsgId, IDS_LINKS, MB_ICONEXCLAMATION|MB_OK);  \
                                                                  \
    //                                                            \
    // Cleanup up buffers allocated by container                  \
    //                                                            \
    if (lpLinkInfo->lpszDisplayName) {                            \
      oleAllocator.Free(lpLinkInfo->lpszDisplayName);             \
      lpLinkInfo->lpszDisplayName = 0;                            \
    }                                                             \
                                                                  \
    if (lpLinkInfo->lpszShortLinkType) {                          \
      oleAllocator.Free(lpLinkInfo->lpszShortLinkType);           \
      lpLinkInfo->lpszShortLinkType = 0;                          \
    }                                                             \
                                                                  \
    if (lpLinkInfo->lpszDisplayName) {                            \
      oleAllocator.Free(lpLinkInfo->lpszFullLinkType);            \
      lpLinkInfo->lpszFullLinkType = 0;                           \
    }                                                             \
    return -1;                                                    \
  } )           // End-Of-CATCH macro //
}


int
TEditLinksDlg::LoadLinkLB()
{
  int   cLinks = 0;
  DWORD dwLink = 0;
  LPOLEUILINKCONTAINER lpLnkCntnr = Data->lpOleUILinkContainer;

  int index;
  TLinkInfo* lpLinkInfo;
  while((dwLink = lpLnkCntnr->GetNextLink(dwLink)) != 0) {
    lpLinkInfo = new TLinkInfo(dwLink);
    cLinks++;

   index = AddLinkLBItem(lpLinkInfo, true);
    if (index < 0)
      return -1;

    if (lpLinkInfo->fIsSelected)
      LinksList->SetSel(index, true);
  }

  if (LinksList->GetSelIndexes(&index, 1) > 0)
    LinksList->SetCaretIndex(index, true);

  return cLinks;
}


void
TEditLinksDlg::RefreshLinkLB()
{
  int cItems = LinksList->GetCount();
  CHECK(cItems > 0);

  bool bStop;
  TLinkInfo* lpLinkInfo;
  do {
    bStop = true;
    for (int nIndex=0; nIndex<cItems; nIndex++) {
      LinksList->HandleMessage(LB_GETTEXT, nIndex,
                               (LPARAM)(TLinkInfo far*)&lpLinkInfo);
      if (lpLinkInfo->fIsMarked) {
        lpLinkInfo->fIsMarked = false;
        lpLinkInfo->fDontFree = true;

        LinksList->DeleteString(nIndex);

        nIndex =AddLinkLBItem(lpLinkInfo, false);

        if (lpLinkInfo->fIsSelected) {
          LinksList->SetSel(nIndex, true);
          LinksList->SetCaretIndex(nIndex, true);
        }
        bStop = false;
        break;
      }
    }
  } while (!bStop);
}


