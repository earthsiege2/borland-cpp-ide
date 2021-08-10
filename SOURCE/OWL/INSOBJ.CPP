//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1993, 1994 by Borland International, All Rights Reserved
//
//   Implementation of class TInsertObjectDlg
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

//
// OWL OLE Dialog diagnostic group.
//
DIAG_DECLARE_GROUP(OwlOleDlg);

//
//
//
const char szNotInsertable[] = "\\NotInsertable";
const char szProStdEditSrv[] = "\\protocol\\StdFileEditing\\server";
const char szInsertable[]    = "\\Insertable";
const char szCLSID2[]        = "CLSID\\";
const char szInProcServer[]  = "\\InProcServer";
const char szLocalServer[]   = "\\LocalServer";

//
//
//
static bool
GetAssociatedExecutable(char* /*extension*/, char* /*executable*/)
{
  return false; //! BB  For now
}

//
//
//
TInsertObjectDlg::TData::TData()
{
  Flags         = 0;
  cClsIdExclude = 0;
  lpClsIdExclude= 0;
  MetaPict      = 0;
  FileName      = 0;
  ClsId         = CLSID_NULL;
}


DEFINE_RESPONSE_TABLE1(TInsertObjectDlg, TOleDialog)
  EV_BN_CLICKED(IDC_CREATENEW,      CreateNewClicked),
  EV_BN_CLICKED(IDC_CREATEFROMFILE, CreateFromFileClicked),
  EV_BN_CLICKED(IDC_BROWSE,         BrowseFileClicked),
  EV_BN_CLICKED(IDC_LINK,           LinkToFileClicked),
  EV_BN_CLICKED(IDC_DISPLAYASICON,  DisplayAsIconClicked),
  EV_BN_CLICKED(IDC_CHANGEICON,     ChangeIconClicked),
  EV_LBN_SELCHANGE(IDC_OBJECTLIST,  ObjectListChanged),
  EV_LBN_DBLCLK(IDC_OBJECTLIST,     ObjectListDoubleClicked),
  EV_EN_CHANGE(IDC_FILENAME,        FileNameChanged),
  EV_EN_KILLFOCUS(IDC_FILENAME,     FileNameKillFocus),
END_RESPONSE_TABLE;

//
// Static variales of TInserObjectDlg
//
CLSID   TInsertObjectDlg::DynamicScopeClsid = CLSID_NULL;
OLECHAR TInsertObjectDlg::DynamicScopePath[MaxPathLen] = {0};

//
//
//
TInsertObjectDlg::TInsertObjectDlg(TWindow* parent,
                                   TOcInitInfo &initInfo,
                                   TData  *data,
                                   TResId templateId,
                                   const char far* title,
                                   TModule* module)
:
  TOleDialog(parent, templateId ? templateId : TResId(DLG_INSERTOBJECT),
             title, module),
  InitInfo(initInfo), Helper(*new THelper)
{
  ObjectList      = new TListBox(this, IDC_OBJECTLIST);
  ObjectType      = new TStatic(this, IDC_OBJECTTYPE);
  Link            = new TCheckBox(this, IDC_LINK);
  File            = new TStatic(this, IDC_FILE);
  Browse          = new TButton(this, IDC_BROWSE);
  FileName        = new TEdit(this, IDC_FILENAME);
  FileType        = new TStatic(this, IDC_FILETYPE);
  ResultText      = new TStatic(this, IDC_RESULTTEXT);
  DisplayAsIcon   = new TCheckBox(this, IDC_DISPLAYASICON);
  ChangeIcon      = new TButton(this, IDC_CHANGEICON);
  ResultImage     = new TResultImage(this, IDC_RESULTIMAGE);
  IconImage       = new TIconImage(this, IDC_ICONIMAGE);
  CreateNew       = new TRadioButton(this, IDC_CREATENEW);
  CreateFromFile  = new TRadioButton(this, IDC_CREATEFROMFILE);
  Help            = new TButton(this, IDHELP);
  Ok              = new TButton(this, IDOK);

  Data       = data;
  DeleteData = false;
}

//
//
//
TInsertObjectDlg::~TInsertObjectDlg()
{
  delete &Helper;

  if (DeleteData)
    delete Data;
}

//
// Retrieves default parameters for InsertObject [if none was
// specified] before excuting the dialog
//
int
TInsertObjectDlg::DoExecute()
{
  if (!Data) {
    if (!GetDefaultInsertObjectData())
      return IDCANCEL;
  }
  return TDialog::DoExecute();
}

bool
TInsertObjectDlg::GetDefaultInsertObjectData()
{
  Data = new TData;
  DeleteData = true;

  // Init Data members
  //
  Data->Flags         = ioSelectCreateNew|ioShowHelp;
  Data->cClsIdExclude = 0;    //! BB Add code to exclude ourselves using
  Data->lpClsIdExclude= 0;    //  OLE calls
  Data->MetaPict      = 0;
  Data->FileName      = DynamicScopePath;
  Data->ClsId         = CLSID_NULL;

  return true;
}

bool
TInsertObjectDlg::EvInitDialog(HWND hwndFocus)
{
  TOleDialog::EvInitDialog(hwndFocus);

  // Make Copy of Flags
  //
  Helper.Flags    = Data->Flags;
  Helper.ClsId    = Data->ClsId;
  Helper.MetaPict = 0;

  if (Data->FileName  &&  *(Data->FileName))
    strcpyn(Helper.FileName, Data->FileName, MaxPathLen);
  else
    Helper.FileName[0]=0;

  // Set Control Font
  //
  if (Font) {
    ResultText->SetWindowFont(*Font, false);
    FileType->SetWindowFont(*Font, false);
  }

  // Fill ListBox with Insertable Servers
  //
  FillClassList();

  // Adjust ListBox
  //
  TRect lRect;
  uint32 dbUnits = GetDialogBaseUnits();
  ObjectList->GetClientRect(lRect);
  int tabWidth = (8*lRect.right)/LOWORD(dbUnits);
  ObjectList->SetTabStops(1, &tabWidth);

  // Initialize filename
  //
  if (Helper.FileName[0]) {
    FileName->SetText(Helper.FileName);
    Helper.FileDirty = ValidateInsertFile(false);
  }
  else {
    char curDir[MaxPathLen];
    if(getcwd(curDir, sizeof(curDir)));
      FileName->SetText(curDir);

    Helper.FileDirty = true;
  }

  //
  // Init dialog for either CreateNew or CreateFromFile
  //
  if (Helper.Flags & ioSelectCreateNew) {
    Activate(File, false);
    Activate(FileType, false);
    Activate(FileName, false);
    Activate(Link, false);
    Activate(Browse, false);

    CheckRadioButton(IDC_CREATENEW, IDC_CREATEFROMFILE, IDC_CREATENEW);
    ObjectList->SetFocus();
    Helper.AsIconNew = (Helper.Flags & ioCheckDisplayAsIcon) ? true : false;
  }
  else {  // ioSelectCreateFromFile
    Activate(ObjectList, false);
    Activate(ObjectType, false);

    if (Helper.FileDirty)
      Helper.Flags &= ~ioCheckDisplayAsIcon;

    if (Helper.Flags & ioDisableLink) {
      Activate(Link, false);
    }
    else {
      if (Helper.Flags & ioCheckLink)
        Link->Check();
    }

    CheckRadioButton(IDC_CREATENEW, IDC_CREATEFROMFILE, IDC_CREATEFROMFILE);
    Helper.AsIconFile = (Helper.Flags & ioCheckDisplayAsIcon) ? true : false;
    FileName->SetFocus();
  }

  // Handled Icon display flags
  //
  bool fAsIcon = (Helper.Flags & ioCheckDisplayAsIcon) ? true : false;
  DisplayAsIcon->SetCheck(fAsIcon == false ? BF_UNCHECKED : BF_CHECKED);
  Activate(ChangeIcon, fAsIcon);
  Activate(IconImage, fAsIcon);

  // Handle ShowHelp flags
  //
  if (!(Helper.Flags & ioShowHelp))
    Activate(Help, false);

  // Update Result display
  //
  UpdateClassIcon();
  SetInsertObjectResults();

  // Disable IconDisplay control if requested
  //
  if (Helper.Flags & ioDisableDisplayAsIcon) {
    Activate(DisplayAsIcon, false);
    Activate(ChangeIcon, false);
    Activate(IconImage, false);
  }

  return false;
}

//
//  Update TOcInitInfo member using the Data information.
//
bool
TInsertObjectDlg::OleDlgOk()
{
  // Set Focus on OK button
  //
  if (GetFocus() != *Ok)
    Ok->SetFocus();

  if ((Helper.Flags & ioSelectCreateFromFile)  &&  Helper.FileDirty) {
    if (ValidateInsertFile()) {
      Helper.FileDirty = false;
      Helper.FileValid = true;
      UpdateClassIcon();
      UpdateClassType(true);
    }
    else {  //  Invalid file name specified
      Helper.FileDirty = false;
      Helper.FileValid = false;
      FileName->SetFocus();
      FileName->SetSelection(0, -1);
      return false;
    }
  }
  else if ((Helper.Flags & ioSelectCreateFromFile) && !Helper.FileValid) {
    char file[MaxPathLen];
    if (FileName->GetText(file, sizeof(file))) {
      OpenFileError(Helper.ErrCode, file);
    }
    Helper.FileDirty = false;
    Helper.FileValid = false;

    FileName->SetFocus();
    FileName->SetSelection(0, -1);

    UpdateClassType(false);
    return false;
  }

  LPSTR lpszCLSID;
  char buff[MaxKeyLen+CLSIDStringLen];

  // Copy info to user's structure
  //
  Data->Flags = Helper.Flags;

  if (Helper.Flags & ioSelectCreateNew) {
    int selIndex = ObjectList->GetSelIndex();

    // Retrieve Icon and set to 0 to prevent deletion
    //
    if (Helper.Flags & ioCheckDisplayAsIcon) {
      Data->MetaPict = (HGLOBAL)ObjectList->GetItemData(selIndex);
      ObjectList->SetItemData(selIndex, 0);
    }
    else {
      Data->MetaPict = 0;
    }

    // Retrieve CLSID
    //
    ObjectList->GetString(buff, selIndex);
    lpszCLSID = PtrToNthField(buff, 2, '\t');
    CLSIDFromString(lpszCLSID, &Data->ClsId);
  }
  else {    //  ioSelectCreateFromFile
    if (Helper.Flags & ioCheckDisplayAsIcon) {
      Data->MetaPict = IconImage->GetMetaPict();
    }
    else {
      Data->MetaPict = 0;
    }
    FileName->GetText(Helper.FileName, MaxPathLen);
    strcpyn(Data->FileName, Helper.FileName, MaxPathLen);
  }

  //
  // Update TOcInitInfo members
  //
  InitInfo.HIcon =(Data->Flags & ioCheckDisplayAsIcon) ?
                  (HICON)Data->MetaPict : NULL;
  if (Data->Flags & ioSelectCreateNew) {
    InitInfo.Where    = iwNew;
    InitInfo.How      = ihEmbed;
    DynamicScopeClsid = Data->ClsId;
    InitInfo.CId      = (BCID)&DynamicScopeClsid;
  }
  else if (Data->Flags & ioSelectCreateFromFile) {
    InitInfo.Where = iwFile;
    InitInfo.How   = (Data->Flags & ioCheckLink) ? ihLink : ihEmbed;
    InitInfo.Path  = strnewdup(Data->FileName);
  }
  return true;
}

//
// Cleanup metafiles stored as itemData in ListBox
//
void
TInsertObjectDlg::CleanupWindow()
{
  int count = ObjectList->GetCount();

  HGLOBAL hMetaPict;
  for (int i=0; i<count; i++) {
    hMetaPict = (HGLOBAL)ObjectList->GetItemData(i);
    if (hMetaPict) {
      TOleMetaPict::Free(hMetaPict);
      ObjectList->SetItemData(i, 0);
    }
  }

  TOleDialog::CleanupWindow();
}

//
//
//
int
TInsertObjectDlg::FillClassList()
{
  HKEY hKey;
  CLSID clsid;
  LPSTR pszID= 0;
  int strIndex = 0;

  char* pExec = new char[MaxKeyLen]; 
  TPointer<char> _pe = pExec;

  char* pClass= new char[MaxKeyLen];
  TPointer<char> _pc = pClass;

  char* pKey  = new char[MaxKeyLen];
  TPointer<char> _pk = pKey;

  //
  // Retrieve task memory allocator
  //
  TOleAllocator oleAllocator;

  //
  // Return error if  cannot open the root key
  //
  if (RegOpenKey(HKEY_CLASSES_ROOT, NULL, &hKey) != ERROR_SUCCESS) {
    TRACEX(OwlOleDlg, 1, "Unable to open Reg. DB");
    return -1;
  }

  // Clear ListBox
  //
  ObjectList->ClearList();

  while(RegEnumKey(hKey, strIndex++, pClass, MaxKeyLen) == ERROR_SUCCESS) {
    if (pszID) {
      oleAllocator.Free(pszID);
      pszID = 0;
    }

    int classLen = strlen(pClass);

    // Skip entries with not-insertable subkeys
    //
    LONG buffSize = MaxKeyLen;
    strcpy(pClass+classLen, szNotInsertable);
    if (RegQueryValue(hKey, pClass, pKey, &buffSize) == ERROR_SUCCESS)
      continue;

    // Append and check for "\\protocol\\StdFileEditiing\\server" entry
    //
    buffSize = MaxKeyLen;
    strcpy(pClass+classLen, szProStdEditSrv);
    if (RegQueryValue(hKey, pClass, pKey, &buffSize) == ERROR_SUCCESS) {

      // Retrieve full user type name
      //
      *(pClass+classLen) = 0;
      buffSize = MaxKeyLen;
      if (RegQueryValue(hKey, pClass, pKey, &buffSize) != ERROR_SUCCESS)
        continue;
    }
    else {
      // Skip if no "\\Insertable" entry is found
      //
      strcpy(pClass+classLen, szInsertable);
      buffSize = MaxKeyLen;
      if (RegQueryValue(hKey, pClass, pKey, &buffSize) != ERROR_SUCCESS)
        continue;

      // Reset class
      //
      *(pClass+classLen) = 0;

      // Check for "\\CLSID" subkey as hint to look for second entry
      // [GUID entries] of registration
      //
      buffSize = MaxKeyLen;
      pszID    = (char*)oleAllocator.Alloc(MaxKeyLen);
      strcat(pClass+classLen, ClsIdStr);
      if (RegQueryValue(hKey, pClass, pszID, &buffSize) != ERROR_SUCCESS)
        continue;

      // Look for ROOT\CLSID\'GUID'\LocalServer
      //
      strcpy(pExec, szCLSID2);
      strcat(pExec, pszID);
      int execLen = strlen(pExec);
      strcpy(pExec+execLen, szLocalServer);

      buffSize = MaxKeyLen;
      if (RegQueryValue(hKey, pExec, pKey, &buffSize) != ERROR_SUCCESS) {

        // Look for ROOT\CLSID\'GUID'\InProcServer
        //
        strcpy(pExec+execLen, szInProcServer);

        buffSize = MaxKeyLen;
        if (RegQueryValue(hKey, pExec, pKey, &buffSize)!= ERROR_SUCCESS)
          continue;
      }
    }

    if (!pszID) {
      HRESULT result = CLSIDFromProgID((LPCOLESTR)(char*)pClass, &clsid);
      if (result != S_OK)
        continue;

      StringFromCLSID(clsid,  &pszID);
    }
    else {
      CLSIDFromString(pszID, &clsid);
    }

    if (!pszID || IsEqualCLSID(clsid, CLSID_NULL))
      continue;

    // Tag classID to string and add latter to the list if
    // it's not already there.
    //
    if (ObjectList->FindString(pKey, 0) == LB_ERR) {
      strcat(pKey, "\t");
      strcat(pKey, pszID);
      ObjectList->AddString(pKey);

      TRACEX(OwlOleDlg, 1, "Adding " << pKey);
    }

    // Free CLSID String using task allocator
    //
    if (pszID) {
      oleAllocator.Free(pszID);
      pszID = 0;
    }
  }
  RegCloseKey(hKey);

  // Select first entry
  //
  ObjectList->SetSelIndex(0);

  // Return list count
  //
  return ObjectList->GetCount();
}

//
//
//
bool
TInsertObjectDlg::ToggleObjectSource(TInsertObjectFlags flag)
{
  PRECONDITION((flag == ioSelectCreateNew) ||
               (flag == ioSelectCreateFromFile));

  if (Helper.Flags & flag)
    return true;

  // Store current file icon
  //
  if (flag == ioSelectCreateNew  &&  (Helper.Flags & ioCheckDisplayAsIcon))
    Helper.MetaPict = IconImage->GetMetaPict();

  // Enable/Disable Icon related
  //
  bool asIcon = (flag == ioSelectCreateNew) ? Helper.AsIconNew :
                                              Helper.AsIconFile;
  if (asIcon) {
    Helper.Flags |=  ioCheckDisplayAsIcon;
    DisplayAsIcon->Check();
  }
  else {
    Helper.Flags &= ~ioCheckDisplayAsIcon;
    DisplayAsIcon->Uncheck();
  }

  ChangeIcon->EnableWindow(asIcon);

  // Hide/Show appropriate controls
  //
  bool enable = (flag == ioSelectCreateNew) ? true : Helper.FileSelected;
  DisplayAsIcon->EnableWindow(enable);
  Ok->EnableWindow(enable);
  Link->EnableWindow(enable);

  enable = (flag == ioSelectCreateNew) ? true : false;
  FileName->EnableWindow(enable);
  Browse->EnableWindow(enable);
  Activate(ObjectList, enable);
  Activate(ObjectType, enable);

  enable = (flag == ioSelectCreateFromFile) ? true : false;
  Activate(File, enable);
  Activate(FileType, enable);
  Activate(FileName, enable);
  Activate(Browse, enable);

  if (Helper.Flags & ioDisableLink)
    enable = false;
  Activate(Link, enable);

  // Update Flag
  //
  Helper.Flags =
       (Helper.Flags & ~(ioSelectCreateFromFile|ioSelectCreateNew)) | flag;

  enable = (Helper.Flags & ioCheckDisplayAsIcon) ? true : false;
  Activate(ChangeIcon, enable);
  Activate(IconImage, enable);

  // Update result display
  //
  SetInsertObjectResults();

  // Set Focus to newly enable control
  //
  if (flag == ioSelectCreateNew) {
    UpdateClassIcon();
    ObjectList->SetFocus();
  }
  else { // ioSelectCreateFromFile
    if (Helper.AsIconFile  &&  Helper.MetaPict) {
      IconImage->SetMetaPict(Helper.MetaPict);
      Helper.MetaPict = 0;
    }
    else {
      UpdateClassIcon();
    }
    Browse->SetFocus();
  }
  return false;
}

//
//
//
void
TInsertObjectDlg::UpdateClassType(bool setText)
{
  CLSID clsid;
  char  fileName[MaxPathLen];
  char  fileType[MaxLabelLen];

  fileType[0] = 0;

  if (setText) {
    FileName->GetText(fileName, sizeof(fileName));
    if (GetClassFile(fileName, &clsid) == S_OK)
      GetUserTypeOfClass(clsid, fileType, sizeof(fileType));
  }

  FileType->SetText(fileType);
}

//
//
//
void
TInsertObjectDlg::UpdateClassIcon()
{
  if (!(Helper.Flags & ioCheckDisplayAsIcon))
    return;

  int index = ObjectList->GetSelIndex();
  if (index == LB_ERR)
    return;

  HGLOBAL iconMeta = 0;

  // Handle 'CreateNew'
  //
  if (Helper.Flags & ioSelectCreateNew) {
    // Check if we did not store the icon earlier
    //
    uint32 itemData = ObjectList->GetItemData(index);
    if (itemData) {
      IconImage->SetMetaPict((HGLOBAL)itemData);
      return;
    }

    // Retrieve CLSID [and Icon] of selection
    //
    if (GetCurrentCLSID(Helper.ClsId)) {
      iconMeta = GetIconFromClass(Helper.ClsId, 0, true);
    }

    // Store Icon for future use
    //
    ObjectList->SetItemData(index, (uint32)iconMeta);
  }
  else { // ioSelectCreateFromFile
    char *fileName = new char[MaxPathLen];

    FileName->GetText(fileName, MaxPathLen);

    CLSID clsid;
    bool  isChkLnk = (Helper.Flags & ioCheckLink) ? true : false;

    if (isChkLnk || (GetClassFile(fileName, &clsid) == S_OK)) {
      iconMeta = GetIconFromFile(fileName, isChkLnk ? true : false);
    }
    else {
      iconMeta = GetIconFromClass(clsid, 0, true);
    }
  }

  // Update icon display
  //
  IconImage->SetMetaPict(iconMeta);
  Activate(IconImage, iconMeta ? true : false );
}

//
//
//
void
TInsertObjectDlg::SetInsertObjectResults()
{
  TModule *module = GetModule();

  const int buffLen = 0x200;

  TPointer<char> str1 = new char[buffLen];
  TPointer<char> str2 = new char[buffLen];
  TPointer<char> str3 = new char[buffLen];
  uint strID1=0, strID2=0;

  uint imageIndex = 0;
  bool asIcon = (Helper.Flags & ioCheckDisplayAsIcon) ? true : false;

  if (Helper.Flags & ioSelectCreateNew) {
    strID1 = asIcon ? IDS_IORESULTNEWICON : IDS_IORESULTNEW;
    imageIndex = asIcon ? riEmbedIcon : riEmbed;
  }

  if (Helper.Flags & ioSelectCreateFromFile) {
    if (Helper.Flags & ioCheckLink) {
      strID1 = asIcon ? IDS_IORESULTLINKFILEICON1 : IDS_IORESULTLINKFILE1;
      strID2 = asIcon ? IDS_IORESULTLINKFILEICON2 : IDS_IORESULTLINKFILE2;
      imageIndex = asIcon ? riLinkIcon : riLink;
    }
    else {
      strID1 = IDS_IORESULTFROMFILE1;
      strID2 = (asIcon==true) ? IDS_IORESULTFROMFILEICON2 :
                                IDS_IORESULTFROMFILE2;
      imageIndex = asIcon ? riEmbedIcon : riEmbed;
    }
  }

  *((char*)str1) = 0;
  if (module->LoadString(strID1, str1, buffLen)) {
    if (strID2  &&  module->LoadString(strID2, str2, buffLen))
      strcat(str1, str2);

    if (Helper.Flags & ioSelectCreateNew) {
      int index = ObjectList->GetSelIndex();
      if (index != LB_ERR) {
        int len = ObjectList->GetStringLen(index)+1;
        TPointer<char> lstEntry = new char[len];
        if (ObjectList->GetString(lstEntry, index) != LB_ERR) {
          char *pTab = strchr(lstEntry, '\t');
          if (pTab)
            *pTab = 0;

          wsprintf((LPSTR)(char*)str3, (LPSTR)(char*)str1,
                   (LPSTR)(char*)lstEntry);
          strcpy(str1, str3);
        }
      }
    }
  }
  ResultText->SetText(str1);
  ResultImage->SetBitmapIndex(imageIndex);
}

//
// Validates file name currently specified in edit control and
// attempts to substitute a full path for any partial/relative
// filenames.
//
bool
TInsertObjectDlg::ValidateInsertFile(bool showErr)
{
  // Retrieve current name
  //
  char fileName[MaxPathLen];
  if (!FileName->GetText(fileName, sizeof(fileName)))
    return false;

  OFSTRUCT of;
  HFILE hFile;
  hFile = DoesFileExist(fileName, of);

  // Sharing Violation's OK since OleCreateFromFile and
  // OleCreateLinkToFile can still succeed under these circumstances.
  //
  const uint ofErrSharingViolation = 0x0020;
  if (hFile==HFILE_ERROR  &&  of.nErrCode != ofErrSharingViolation) {
    if (showErr) {
      OpenFileError(of.nErrCode, fileName);
    }
    return false;
  }
  else {
    OemToAnsi(of.szPathName, of.szPathName);
    FileName->SetText(of.szPathName);
    return true;
  }
}

//
//
//
bool
TInsertObjectDlg::GetCurrentCLSID(CLSID& clsid)
{
  PRECONDITION(Helper.Flags & ioSelectCreateNew);

  int index = ObjectList->GetSelIndex();
  if (index == LB_ERR)
    return false;

  char *listEntry = new char[MaxKeyLen];
  TPointer<char> p(listEntry);

  // Retrieve ListBox entry and get to CLSID stored beyond tab
  //
  ObjectList->GetString(listEntry, index);
  LPSTR lpszCLSID = PtrToNthField(listEntry, 2, '\t');
  return (CLSIDFromString(lpszCLSID, &clsid) == S_OK) ? true : false;
}

//
//
//
void
TInsertObjectDlg::CreateNewClicked()
{
  ToggleObjectSource(ioSelectCreateNew);
}

//
//
//
void
TInsertObjectDlg::CreateFromFileClicked()
{
  ToggleObjectSource(ioSelectCreateFromFile);
}

//
//
//
void
TInsertObjectDlg::LinkToFileClicked()
{
  if (Link->GetCheck() == BF_CHECKED) {
    Helper.Flags |= ioCheckLink;
  }
  else {
    Helper.Flags &= ~ioCheckLink;
  }
  SetInsertObjectResults();
  UpdateClassIcon();
}

//
//
//
void
TInsertObjectDlg::BrowseFileClicked()
{
  char* initDirPtr = 0;
  char  initDirBuf[MaxPathLen];

  // Save current name
  //
  char curName[MaxPathLen];
  int  nChars = FileName->GetText(curName, sizeof(curName));

  // Try to retrieve initial directory from name
  //
  if (ValidateInsertFile(false)) {
    nChars = FileName->GetText(curName, sizeof(curName));
    GetFileTitle(curName, Helper.FileName, MaxPathLen);
    strcpyn(initDirBuf, curName, nChars-strlen(Helper.FileName));
    initDirPtr = initDirBuf;
  }
  else {    // Default to current directory
    if (getcwd(initDirBuf, MaxPathLen))
      initDirPtr = initDirBuf;

    Helper.FileName[0] = 0;
  }

  uint32 flags = OFN_FILEMUSTEXIST;
  if (Data->Flags & ioShowHelp)
    flags |= OFN_SHOWHELP;

  if (BrowseDlg(Helper.FileName, initDirPtr, IDS_FILTERS, flags)) {
    if (strcmpi(Helper.FileName, curName)) {
      FileName->SetText(Helper.FileName);
      Helper.FileSelected = true;

      if (ValidateInsertFile(true)) {
        Helper.FileDirty = false;
        Helper.FileValid = true;

        UpdateClassIcon();
        UpdateClassType(true);
        Ok->SetFocus();
      }
      else {
        Helper.FileDirty = false;
        Helper.FileValid = false;
        FileName->SetFocus();
        FileName->SetSelection(0, -1);
      }

      DisplayAsIcon->EnableWindow(true);
      Ok->EnableWindow(true);
    }
  }
}

//
//
//
void
TInsertObjectDlg::DisplayAsIconClicked()
{
  bool isChecked = (DisplayAsIcon->GetCheck()==BF_CHECKED) ? true : false;

  ChangeIcon->EnableWindow(isChecked);

  // Update flags
  //
  if (isChecked)
    Helper.Flags |= ioCheckDisplayAsIcon;
  else
    Helper.Flags &= ~ioCheckDisplayAsIcon;

  if (Helper.Flags & ioSelectCreateNew)
    Helper.AsIconNew = isChecked;
  else
    Helper.AsIconFile = isChecked;

  if (isChecked) {
    if (Helper.Flags & ioSelectCreateFromFile) {
      if (ValidateInsertFile()) {
        Helper.FileDirty = false;
        Helper.FileValid = true;
        UpdateClassIcon();
        UpdateClassType(true);
      }
      else {
        Helper.AsIconFile = false;
        Helper.FileDirty  = false;
        Helper.FileValid  = false;

        IconImage->SetMetaPict(0);
        UpdateClassType(false);

        Helper.Flags &= ~ioCheckDisplayAsIcon;

        DisplayAsIcon->Uncheck();

        FileName->SetFocus();
        FileName->SetSelection(0, -1);
        return;
      }
    }
    else { // ioSelectCreateNew
      UpdateClassIcon();
    }
  }

  SetInsertObjectResults();

  Activate(ChangeIcon, isChecked);
  Activate(IconImage, isChecked);
}

//
//
//
void
TInsertObjectDlg::ChangeIconClicked()
{
  if (Helper.Flags & ioSelectCreateFromFile) {
    if (Helper.FileDirty  &&  !ValidateInsertFile()) {
      Helper.FileDirty = true;
      FileName->SetFocus();
      FileName->SetSelection(0, -1);
      return;
    }
    else {
      Helper.FileDirty = false;
    }
  }

  TChangeIconDlg::TData chgIconData;
  chgIconData.MetaPict = IconImage->GetMetaPict();
  chgIconData.Flags    = ciSelectCurrent;

  if (Helper.Flags & ioShowHelp)
    chgIconData.Flags |= ciShowHelp;

  if (Helper.Flags & ioSelectCreateNew) {
    GetCurrentCLSID(chgIconData.ClsId);
  }
  else {  // ioSelectCreateFromFile
    char fileName[MaxPathLen];
    if (FileName->GetText(fileName, sizeof(fileName))) {
      if (GetClassFile(fileName, &chgIconData.ClsId) == S_OK) {
        char* extension;
        int   nameLen = strlen(fileName);
        extension = fileName+nameLen+1;

        while((extension > fileName) && (*extension != '.'))
          extension--;

        if (GetAssociatedExecutable(extension, chgIconData.IconExe)) {
          chgIconData.Flags |= ciUseIconExe;
        }
      }
    }
  }

  TRY {
    TChangeIconDlg chgIconDlg(this, chgIconData);
    if (chgIconDlg.Execute() == IDOK) {
      IconImage->SetMetaPict(chgIconData.MetaPict);
      if (Helper.Flags & ioSelectCreateNew) {
        int index = ObjectList->GetSelIndex();
        if (index != LB_ERR) {
          ObjectList->SetItemData(index, (uint32)chgIconData.MetaPict);
        }
      }
    }
  }
  CATCH( (xmsg& msg){ GetModule()->Error(msg, 0); } )
}

//
//
//
void
TInsertObjectDlg::ObjectListChanged()
{
  UpdateClassIcon();
  SetInsertObjectResults();
}

//
//
//
void
TInsertObjectDlg::ObjectListDoubleClicked()
{
  SendNotification(IDOK, BN_CLICKED, GetDlgItem(IDOK));
}

//
//
//
void
TInsertObjectDlg::FileNameChanged()
{
  bool hasText = FileName->GetLineLength(0) ? true : false;

  Helper.FileDirty = true;
  Helper.FileValid = false;
  Helper.FileSelected = hasText;

  Link->EnableWindow(hasText);
  DisplayAsIcon->EnableWindow(hasText);
  ChangeIcon->EnableWindow(hasText);
  Ok->EnableWindow(hasText);
}

//
//
//
void
TInsertObjectDlg::FileNameKillFocus()
{
  if (ValidateInsertFile(false)) {
    Helper.FileDirty = false;
    Helper.FileValid = true;
    UpdateClassIcon();
    UpdateClassType(true);
  }
  else {
    Helper.FileDirty = false;
    Helper.FileValid = false;
    UpdateClassType(false);
  }
}

//
// Initialized helper object used internally by TInsertObjectDlg
//
TInsertObjectDlg::THelper::THelper()
{
  Flags        = 0;
  ClsId        = CLSID_NULL;
  FileName[0]  = 0;
  FileSelected = false;
  AsIconNew    = false;
  AsIconFile   = false;
  FileDirty    = true;
  FileValid    = false;
  MetaPict     = 0;
}
