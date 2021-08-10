//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
//   Defines TChangeIconDlg
//----------------------------------------------------------------------------
#define INC_OLE2
#include <owl/owlpch.h>
#include <owl/listbox.h>
#include <owl/radiobut.h>
#include <owl/edit.h>
#include <ocf/ocview.h>
#include <owl/oledlg.h>
#include <bwcc.h>   // for IDHELP

//
// OWL OLE Dialog diagnostic group.
//
DIAG_DECLARE_GROUP(OwlOleDlg);


//
// Class TIconListBox
// ----- ------------
//  OwnerDraw ListBox which displays icons [used by TChangeIconDlg]
//
class _OWLCLASS TIconListBox : public TListBox {
  public:
    TIconListBox(TWindow *parent, int resourceId, TModule* module=0):
    TListBox(parent, resourceId, module){};

    void    DrawIcon(DRAWITEMSTRUCT far& drawInfo);

    void    ODADrawEntire(DRAWITEMSTRUCT far& drawInfo);
    void    ODAFocus(DRAWITEMSTRUCT far& drawInfo);
    void    ODASelect(DRAWITEMSTRUCT far& drawInfo);

    void    MeasureItem(MEASUREITEMSTRUCT far& measureInfo);
    void    DeleteItem(DELETEITEMSTRUCT far& deleteInfo);

    int     AddIcon(TIcon&);
    uint    AddIconsFromFile(const char far* fileName);
};


//
// Specifies each listbox entry's size as slightly bigger than
// the size of an icon
//
void
TIconListBox::MeasureItem(MEASUREITEMSTRUCT far& measureInfo)
{
  measureInfo.itemWidth = GetSystemMetrics(SM_CXICON)+cxIconPad;
  measureInfo.itemHeight= GetSystemMetrics(SM_CYICON)+cyIconPad;
}


//
// Adds an icon to the listbox
//
int
TIconListBox::AddIcon(TIcon &icon)
{
  return (int)HandleMessage(LB_ADDSTRING, 0, (LPARAM)(HICON)icon);
}


//
// Extracts icons from the specified file and adds them to the listbox.
// NOTE: Performs no validation of the filename
// Returns number of icons added
//
uint
TIconListBox::AddIconsFromFile(const char far* filename)
{
  int count = 0;
  for(uint i=0; i<0xffff; i++) {
    HICON hicon = ExtractIcon(*GetModule(), filename, i);
    if ((UINT)hicon > 32) {
      TIcon icon(hicon);
      if (AddIcon(icon) != LB_ERR)
        count++;
    }
    else {
      break;
    }
  }
  return count;
}


//
// Handles deletion of items from the listbox by cleaning up each
// icon inserted.
//
void
TIconListBox::DeleteItem(DELETEITEMSTRUCT far& deleteInfo)
{
  DestroyIcon(HICON(deleteInfo.itemData));
}


//
// Draws a listbox entry by calling DrawIcon [the itemData field
// is really a HICON inserted earlier in the listbox].
//
void
TIconListBox::DrawIcon(DRAWITEMSTRUCT far& drawInfo)
{
  if ((int)drawInfo.itemID < 0)
    return;

  TColor bkColor(GetSysColor(drawInfo.itemState & ODS_SELECTED ?
                             COLOR_HIGHLIGHT : COLOR_WINDOW));

  TDC dc(drawInfo.hDC);
  TColor oldBkColor = dc.GetBkColor();

  dc.TextRect(drawInfo.rcItem, bkColor);
  dc.DrawIcon(drawInfo.rcItem.left+(cxIconPad/2),
              drawInfo.rcItem.top +(cyIconPad/2),
              TIcon(HICON(drawInfo.itemData)));

  dc.SetBkColor(oldBkColor);

  if (drawInfo.itemState & ODS_FOCUS)
    dc.DrawFocusRect(drawInfo.rcItem);
}


//
// Draws a Focus Rect - Called for the selected entry
//
void
TIconListBox::ODAFocus(DRAWITEMSTRUCT far& drawInfo)
{
  TDC dc(drawInfo.hDC);
  dc.DrawFocusRect(drawInfo.rcItem);
}


void
TIconListBox::ODADrawEntire(DRAWITEMSTRUCT far& drawInfo)
{
  DrawIcon(drawInfo);
}


void
TIconListBox::ODASelect(DRAWITEMSTRUCT far& drawInfo)
{
  DrawIcon(drawInfo);
}


//
// Initialize data members of structure used internally by TChangeIconDlg -
// The structure keeps track of the dialog's state.
//
TChangeIconDlg::THelper::THelper()
{
  //
  // Using memset since class is a private PODS.
  //
  memset(this, 0, sizeof(THelper));
}


DEFINE_RESPONSE_TABLE1(TChangeIconDlg, TOleDialog)
  EV_BN_CLICKED(IDC_CURRENT, CurrentClicked),
  EV_BN_CLICKED(IDC_DEFAULT, DefaultClicked),
  EV_BN_CLICKED(IDC_FROMFILE, FromFileClicked),
  EV_EN_KILLFOCUS(IDC_LABEL, LabelKillFocus),
  EV_CHILD_NOTIFY_ALL_CODES(IDC_FILENAME, FileNameNotification),
  EV_LBN_SETFOCUS(IDC_ICONLIST, IconListSetFocus),
  EV_LBN_SELCHANGE(IDC_ICONLIST, IconListSelChange),
  EV_LBN_DBLCLK(IDC_ICONLIST, IconListDblClk),
  EV_BN_CLICKED(IDC_BROWSE, BrowseClicked),
  EV_BN_CLICKED(IDCANCEL, CmCancel),
END_RESPONSE_TABLE;


//
// Creates C++ objects to wrap controls
//
TChangeIconDlg::TChangeIconDlg(TWindow* parent,
                               TData&   data,
                               TResId   templateId,
                               const char far* title,
                               TModule* module)
               :TOleDialog(parent,
                           templateId ? templateId : TResId(DLG_CHANGEICON),
                           title,
                           module), Data(data), Helper(*new THelper)
{
  CurrentIcon = new TStatic(this, IDC_CURRENTICON);
  DefaultIcon = new TStatic(this, IDC_DEFAULTICON);

  Label       = new TEdit(this, IDC_LABEL, MaxLabelLen);

  ResultIcon  = new TStatic(this, IDC_RESULTICON);
  ResultLabel = new TStatic(this, IDC_DOCUMENTNAME);

  Current     = new TRadioButton(this, IDC_CURRENT);
  Default     = new TRadioButton(this, IDC_DEFAULT);
  FromFile    = new TRadioButton(this, IDC_FROMFILE);

  Help        = new TButton(this, IDHELP);
  Browse      = new TButton(this, IDC_BROWSE);

  IconList    = new TIconListBox(this, IDC_ICONLIST);
  FileName    = new TEdit(this, IDC_FILENAME, MaxPathLen);
}


//
// Clean up dialog
//
TChangeIconDlg::~TChangeIconDlg()
{
  delete &Helper;
}


//
// Initialize members of TData structure
//
TChangeIconDlg::TData::TData()
{
  Flags = 0;
  MetaPict = 0;
  ClsId = CLSID_NULL;
  IconExe[0] = 0;
}


//
// Wrapper to set a static control's icon
//
void
TChangeIconDlg::SetIcon(TStatic& win, HICON hIcon)
{
  win.SendMessage(STM_SETICON, (WPARAM)hIcon);
}


//
// Executes dialog
//
int
TChangeIconDlg::DoExecute()
{
  return TDialog::DoExecute();
}


//
// Performs initialization of ChangeIcon Dialog.
//
void
TChangeIconDlg::SetupWindow()
{
  TOleDialog::SetupWindow();

  TModule *module = GetModule();

  //
  // Copy Info from user
  //
  Helper.Flags = Data.Flags;

  //
  // Extract info about MetaFile icon
  //
  TOleMetaPict metaPict(Data.MetaPict);

  metaPict.ExtractIconSource(Helper.File, Helper.IconIndex);
  metaPict.ExtractLabel(Helper.Label);
  Helper.CurIcon = metaPict.ExtractIcon(*GetModule());

  //
  // Set Control Font
  //
  if (Font)
    ResultLabel->SetWindowFont(*Font, false);

  //
  // Handle Help button display
  //
  if (!(Helper.Flags & ciShowHelp))
    Activate(Help, false);

  //
  // Init control displays
  //
  FileName->SetText(Helper.File);
  Label->SetText(Helper.Label);
  ResultLabel->SetText(Helper.Label);

  //
  // Use IconExe as IconFile if requested
  //
  Helper.DefIcon = 0;
  if (Helper.Flags & ciUseIconExe) {
    Helper.DefIcon = ExtractIcon(*module, Data.IconExe, 0);
    if (Helper.DefIcon) {
      strcpy(Helper.DefIconFile, Data.IconExe);
      Helper.DefIconIndex = 0;
    }
  }

  if (!Helper.DefIcon) {
    HGLOBAL metaPict = GetIconFromClass(Data.ClsId, 0, TRUE);
    if (metaPict) {
      TOleMetaPict defMetaPict(metaPict, AutoDelete);

      Helper.DefIcon = defMetaPict.ExtractIcon(*GetModule());
      defMetaPict.ExtractIconSource(Helper.DefIconFile,
                                    Helper.DefIconIndex);
    }
  }

  //
  // Init Icon Displays
  //
  SetIcon(*CurrentIcon, Helper.CurIcon);
  SetIcon(*DefaultIcon, Helper.DefIcon);
  SetIcon(*ResultIcon, Helper.CurIcon);

  //
  // Adjust listbox dimensions
  //
  int listHeight = GetSystemMetrics(SM_CYICON)+
                   GetSystemMetrics(SM_CYHSCROLL)+
                   GetSystemMetrics(SM_CYBORDER)*2+
                   cyIconPad;
  TRect lRect;
  IconList->GetClientRect(lRect);
  IconList->SetWindowPos(0, 0, 0, lRect.right, listHeight,
                         SWP_NOMOVE|SWP_NOZORDER);
  IconList->SetColumnWidth(GetSystemMetrics(SM_CXICON)+cxIconPad);

  TRect gRect;
  IconList->GetWindowRect(lRect);
  //! BB Window may need resizing

  //
  // Select appropriate RadioButton
  //
  if (FillIconList(Helper.File)) {
    IconList->SetSelIndex(Helper.IconIndex);
  }
  if (Helper.Flags & ciSelectCurrent) {
    CheckRadioButton(IDC_CURRENT, IDC_FROMFILE, IDC_CURRENT);
  }
  else {
    uint id = (Helper.Flags & ciSelectFromFile) ? IDC_FROMFILE : IDC_DEFAULT;
    CheckRadioButton(IDC_CURRENT, IDC_FROMFILE, id);
  }
}


//
// Called when user selects 'OK'
//
bool
TChangeIconDlg::OleDlgOk()
{
  char file[MaxPathLen];
  FileName->GetText(file, sizeof(file));

  //
  // If the file name has changed we'll simply update the listbox instead
  // of closing the dialog
  //
  if (strcmpi(Helper.File, file)) {
    strcpy(Helper.File, file);
    FillIconList(Helper.File);
    UpdateResultIcon(ciSelectFromFile);
    return false;
  }

  //
  // Validate filename if 'SelectFromFile'
  //
  if (Helper.Flags & ciSelectFromFile) {
    OFSTRUCT ofs;
    if (DoesFileExist(Helper.File, ofs)==HFILE_ERROR) {
      OpenFileError(ofs.nErrCode, Helper.File);
      FileName->SetFocus();
      FileName->SetSelection(0, -1);
      return false;
    }
  }

  //
  // Set Focus to OK button
  //
  if (GetFocus() != GetDlgItem(IDOK))
    ::SetFocus(GetDlgItem(IDOK));

  //
  //
  //
  HICON hIcon = (HICON)ResultIcon->SendMessage(STM_GETICON);
  LPSTR lpsz  = Helper.File;

  //
  // Retrieve default information (if Default)
  //
  if (Helper.Flags & ciSelectDefault) {
    lpsz = Helper.DefIconFile;
    Helper.IconIndex = Helper.DefIconIndex;
    hIcon = Helper.DefIcon;
  }

  //
  // Extract current icon source (if Current)
  //
  if (Helper.Flags & ciSelectCurrent) {
    TOleMetaPict metaPict(Data.MetaPict);
    metaPict.ExtractIconSource(lpsz, Helper.IconIndex);
  }

  //
  // Retrieve filename and index (if FromFile)
  //
  if (Helper.Flags & ciSelectFromFile) {
    FileName->GetText(lpsz, MaxPathLen);
    Helper.IconIndex = IconList->GetSelIndex();
  }

  //
  // Retrieve label to make new metafile
  //
  char label[MaxLabelLen];
  Label->GetText(label, sizeof(label));

  //
  // Create new metafile
  //
  HGLOBAL hMetaPict = OleMetafilePictFromIconAndLabel(hIcon, label, lpsz,
                                                      Helper.IconIndex);

  //
  // Free metafile passed in
  //
  TOleMetaPict::Free(Data.MetaPict);

  //
  // Return new metafile to user along with flags
  //
  Data.MetaPict = hMetaPict;
  Data.Flags    = Helper.Flags;
  return true;
}


//
//
//
void
TChangeIconDlg::CleanupWindow()
{
  //
  // Make sure that icons are properly destroyed
  // (this takes care of destroying the [fromFile] icon)
  //
  IconList->ClearList();

  //
  // Destroy Current Icon
  //
  HICON hIcon = (HICON)CurrentIcon->SendMessage(STM_GETICON);
  if (hIcon)
    DestroyIcon(hIcon);

  //
  // Destroy the Default Icon
  //
  hIcon = (HICON)DefaultIcon->SendMessage(STM_GETICON);
  if (hIcon)
    DestroyIcon(hIcon);

  TOleDialog::CleanupWindow();
}


//
// Fills the Icon ListBox with icons extracted from the specified filename
//
uint
TChangeIconDlg::FillIconList(const char *fileName)
{
  uint numIcons = 0;

  //
  // Clear listbox (which destroys currently extracted icons)
  //
  IconList->ClearList();

  //
  // Check for !NULL filename
  //
  if (!fileName || strlen(fileName) == 0)
    return 0;

  //
  // Enable Wait cursor and Clear List
  //
  HCURSOR oldCursor = HourGlassOn();

  //
  // Validate filename
  //
  OFSTRUCT ofs;
  if (DoesFileExist(fileName, ofs) != HFILE_ERROR) {
    //
    // Check that indeed there are icons in the file
    //
    HICON hIcon = ExtractIcon(*GetModule(), fileName, 0);
    if ((uint)hIcon > 32) {
      //
      // Clean up the extracted icon
      //
      DestroyIcon(hIcon);

      //
      // Pass name to listbox for grunt work and for listbox to update
      //
      IconList->SetRedraw(false);
      numIcons = IconList->AddIconsFromFile(fileName);
      IconList->SetRedraw(true);
      IconList->Invalidate(true);
      IconList->SetSelIndex(0);
    }
    else {
      ErrorWithFile(IDS_CINOICONSINFILE, fileName);
    }
  }
  else {
    OpenFileError(ofs.nErrCode, fileName);
  }

  HourGlassOff(oldCursor);
  return numIcons;
}


void
TChangeIconDlg::UpdateResultIcon(TChangeIconFlags flag)
{
  PRECONDITION(flag == ciSelectCurrent ||
               flag == ciSelectDefault ||
               flag == ciSelectFromFile);

  Helper.Flags &= ~(ciSelectCurrent | ciSelectDefault | ciSelectFromFile);

  long lval = LB_ERR;

  if (flag == ciSelectCurrent)
    lval = CurrentIcon->SendMessage(STM_GETICON);
  else if (flag == ciSelectDefault)
    lval = DefaultIcon->SendMessage(STM_GETICON);
  else if (flag == ciSelectFromFile) {
    int index = IconList->GetSelIndex();
    if (index != LB_ERR)
      IconList->HandleMessage(LB_GETTEXT, index, (LPARAM)(LPLONG)&lval);
    else
      lval = DefaultIcon->SendMessage(STM_GETICON);
  }

  if (lval != LB_ERR)
    SetIcon(*ResultIcon, (HICON)lval);
}


void
TChangeIconDlg::CurrentClicked()
{
  UpdateResultIcon(ciSelectCurrent);
}


void
TChangeIconDlg::DefaultClicked()
{
  UpdateResultIcon(ciSelectDefault);
}


void
TChangeIconDlg::FromFileClicked()
{
  UpdateResultIcon(ciSelectFromFile);
}


void
TChangeIconDlg::LabelKillFocus()
{
  char str[MaxPathLen];
  Label->GetText(str, sizeof(str));
  ResultLabel->SetText(str);
}


void
TChangeIconDlg::FileNameNotification(uint)
{
  char str[MaxPathLen];
  FileName->GetText(str, sizeof(str));
  if (strcmpi(Helper.File, str)) {
    IconList->SetSelIndex(-1);
    CheckRadioButton(IDC_CURRENT, IDC_FROMFILE, IDC_FROMFILE);
  }
}


//
// If the filename has changed when the IconListBox gains focus,
// the list is refilled and the result icon updated.
//
void
TChangeIconDlg::IconListSetFocus()
{
  char str[MaxPathLen];
  FileName->GetText(str, sizeof(str));
  if (strcmpi(Helper.File, str)) {
    strcpy(Helper.File, str);
    FillIconList(Helper.File);
    UpdateResultIcon(ciSelectFromFile);
  }
}


//
// Updates result icon if listbox selection changes
//
void
TChangeIconDlg::IconListSelChange()
{
  UpdateResultIcon(ciSelectFromFile);
}


//
// A double click on the IconListBox is treated as if the 'OK' button
// had been clicked
//
void
TChangeIconDlg::IconListDblClk()
{
  SendNotification(IDOK, BN_CLICKED, GetDlgItem(IDOK));
}


//
// Allows user to browse for a file from which icons can be extracted
//
void
TChangeIconDlg::BrowseClicked()
{
  //
  // Save a copy of filename
  //
  char file[MaxPathLen];
  FileName->GetText(file, sizeof(file));

  //
  // Build flags
  //
  DWORD flags = OFN_FILEMUSTEXIST;
  if (Data.Flags & ciShowHelp)
    flags |= OFN_SHOWHELP;

  //
  // Display OpenFile dialog
  //
  if (BrowseDlg(Helper.File, 0, IDS_ICONFILTERS, flags)) {
    //
    // If filename has changed, update display
    //
    if (strcmpi(file, Helper.File)) {
      CheckRadioButton(IDC_CURRENT, IDC_FROMFILE, IDC_FROMFILE);
      FileName->SetText(Helper.File);
      FillIconList(Helper.File);
      UpdateResultIcon(ciSelectFromFile);
    }
  }
}

