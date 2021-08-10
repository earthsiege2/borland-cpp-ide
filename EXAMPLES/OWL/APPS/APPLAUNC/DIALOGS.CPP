//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/inputdia.h>
#include <dos.h>
#include <dir.h>
#include "dialogs.h"

DEFINE_RESPONSE_TABLE1(TAppPropertiesDialog, TDialog)
  EV_CHILD_NOTIFY(IDOK, BN_CLICKED, CmOk),
  EV_CHILD_NOTIFY(CM_BROWSE_PROG, BN_CLICKED, CmBrowseProg),
  EV_CHILD_NOTIFY(CM_BROWSE_ICON, BN_CLICKED, CmBrowseIcon),
END_RESPONSE_TABLE;

//
// Constructor.  Create controls for later manipulation.  Setup file open
// data. Store TAppProperties record to be filled in later.
//
TAppPropertiesDialog::TAppPropertiesDialog(TWindow* parent, int resId,
                                           TAppPropertiesData& data)
:
  TDialog(parent, resId),
  AppProperties(data)
{
  ProgramPath = new TEdit(this, ID_PROGRAM_PATH, ProgramPathLen);
  ProgramArgs = new TEdit(this, ID_PROGRAM_ARGS, ProgramArgsLen);
  IconPath = new TEdit(this, ID_ICON_PATH, IconPathLen);
  PromptForInput = new TCheckBox(this, ID_PROMPT_FOR_INPUT);
  StartupStyles = new TGroupBox(this, ID_STARTUP_GROUPBOX);
  RunNormal = new TRadioButton(this, ID_RUN_NORMAL, StartupStyles);
  RunMinimized = new TRadioButton(this, ID_RUN_MINIMIZED, StartupStyles);
  RunMaximized = new TRadioButton(this, ID_RUN_MAXIMIZED, StartupStyles);

  FileData.Flags = OFN_FILEMUSTEXIST|OFN_HIDEREADONLY|OFN_CREATEPROMPT|
                   OFN_OVERWRITEPROMPT;
  FileData.SetFilter("AllFiles (*.*)|*.*|");
}

//
// SetupWindow(). Initialize dialog fields with given fields from
// TAppProperties record.
//
void
TAppPropertiesDialog::SetupWindow()
{
  TDialog::SetupWindow();

  // Initialize dialog fields with data from AppProperties record.
  //
  ProgramPath->Insert(AppProperties.AppRec->ProgramPath.c_str());
  ProgramArgs->Insert(AppProperties.AppRec->ProgramArgs.c_str());
  IconPath->Insert(AppProperties.AppRec->IconPath.c_str());

  if (AppProperties.AppRec->PromptForInput)
    PromptForInput->Check();

  switch (AppProperties.AppRec->StartupStyle) {
    case 1:
      RunNormal->Check();
      break;
    case 2:
      RunMinimized->Check();
      break;
    case 3:
      RunMaximized->Check();
    default:
      break;
  };
}

//
// CmOk(). Update TAppProperties record with any fields that the user changed.
// Record the following information in the TAppProperties record:
//  . Does the Bitmap for the button need to be updated.
//
void
TAppPropertiesDialog::CmOk()
{
  char*           buf = new char[ProgramArgsLen*2];

  ProgramPath->GetLine(buf, ProgramPathLen, 0);
  if (AppProperties.AppRec->ProgramPath != buf)
    AppProperties.ChangeBitmap = true;
  AppProperties.AppRec->ProgramPath = buf;

  ProgramArgs->GetLine(buf, ProgramArgsLen, 0);
  AppProperties.AppRec->ProgramArgs = buf;

  IconPath->GetLine(buf, IconPathLen, 0);
  if (AppProperties.AppRec->IconPath != buf)
    AppProperties.ChangeBitmap = true;
  AppProperties.AppRec->IconPath = buf;

  AppProperties.AppRec->PromptForInput = PromptForInput->GetCheck();

  if (RunNormal->GetCheck())
    AppProperties.AppRec->StartupStyle = 1;
  else if (RunMinimized->GetCheck())
    AppProperties.AppRec->StartupStyle = 2;
  else
    AppProperties.AppRec->StartupStyle = 3;

  delete buf;
  TDialog::CmOk();
}

//
// CmBrowseProg(). Bring up a file open dialog so the user can choose the
// program path to use for this app.
//
void
TAppPropertiesDialog::CmBrowseProg()
{
  string  s;
  if (GetFilePath(s)) {
    ProgramPath->DeleteLine(0);
    ProgramPath->Insert(s.c_str());
  }
}

//
// CmBrowseIcon(). Bring up a file open dialog so the user can enter the path
// to the icon file to use for this app.
//
void
TAppPropertiesDialog::CmBrowseIcon()
{
  string  s;
  if (GetFilePath(s)) {
    IconPath->DeleteLine(0);
    IconPath->Insert(s.c_str());
  }
}

//
// GetFilePath(). Bring up file open dialog.  If 'OK' button was pressed
// set 'path' parameter to path user has entered.
//
int
TAppPropertiesDialog::GetFilePath(string& path)
{
  *FileData.FileName = 0;
  if (TFileOpenDialog(this, FileData).Execute() == IDOK) {
    path = FileData.FileName;
    return 1;
  }
  return 0;
}

//////////////////////////////////////////////////////////////////////

DEFINE_RESPONSE_TABLE1(TAddAppDialog, TDialog)
  EV_CHILD_NOTIFY(CM_BROWSE_PROG, BN_CLICKED, CmBrowseProg),
END_RESPONSE_TABLE;

//
// Constructor.  Create interface objects and initialize file open record.
//
TAddAppDialog::TAddAppDialog(TWindow* parent, int resId, string& progPathStr,
                             int& loc, StringList& pathStrs)
:
  TDialog(parent, resId),
  ProgPathStr(progPathStr),
  Loc(loc),
  PathStrs(pathStrs)
{
  ProgramPath = new TEdit(this, ID_PROGRAM_PATH, ProgramPathLen);
  Paths = new TComboBox(this, ID_PATHS, ProgramPathLen);

  FileData.Flags = OFN_FILEMUSTEXIST|OFN_HIDEREADONLY|OFN_CREATEPROMPT|
                   OFN_OVERWRITEPROMPT;
  FileData.SetFilter("AllFiles (*.*)|*.*|");
  *FileData.FileName = 0;
}

//
// CanClose().
//
bool
TAddAppDialog::CanClose()
{
  char    path[MAXPATH];
  string  modPath;

  Loc = Paths->GetSelIndex();

  ProgramPath->GetLine(path,MAXPATH,0);
  modPath = path;
  modPath.strip(string::Both);
  if (modPath.is_null() || modPath[0] == ' ') {
    MessageBox("Program Path field can't be left blank", "Error", MB_OK);
    return false;
  }
  ProgPathStr = modPath;
  PathStrs.AddAt(modPath, Loc);
  return true;
}

//
// SetupWindow(). Setup default location for new app as -1 (append).
//
void
TAddAppDialog::SetupWindow()
{
  TDialog::SetupWindow();

  unsigned  stop = PathStrs.Count();
  for (unsigned i = 0; i < stop ;i++ )
    Paths->InsertString(PathStrs[i].c_str(), -1);
  Paths->InsertString("<Append>", -1);
  Paths->SetSelIndex(PathStrs.Count());
}

//
// CmBrowseProg(). Bring up a file open dialog so the user can choose the
// program path to use for this app.
//
void
TAddAppDialog::CmBrowseProg()
{
  *FileData.FileName = 0;
  if (TFileOpenDialog(this, FileData).Execute() == IDOK) {
    ProgramPath->DeleteLine(0);
    ProgramPath->Insert(FileData.FileName);
  }
}

//////////////////////////////////////////////////////////////////////

DEFINE_RESPONSE_TABLE1(TMyPickListDialog, TDialog)
  EV_CHILD_NOTIFY(IDOK, BN_CLICKED, CmOk),
END_RESPONSE_TABLE;

//
// Constructor.  Create interface object for listbox.
//
TMyPickListDialog::TMyPickListDialog(TWindow* parent, int resId,
                                 StringList& strings,
                                 NumberList& selections)
:
  TDialog(parent, resId),
  Strings(strings),
  Selections(selections)
{
  PickList = new TListBox(this, ID_PICK_LIST);
}

//
// SetupWindow(). Load listbox with the paths of all the apps in AppLauncher.
//
void
TMyPickListDialog::SetupWindow()
{
  TDialog::SetupWindow();

  unsigned stop = Strings.Count();
  for (unsigned i = 0; i < stop; i++ )
    PickList->AddString(Strings[i].c_str());
}

//
// CmOk().  Record selections form pick list that user for return from dialog.
//
void
TMyPickListDialog::CmOk()
{
  int* selectionsFromPickList = new int[Strings.Count()+1];
  int nitems = PickList->GetSelIndexes(selectionsFromPickList, Strings.Count());
  for (unsigned i = 0; i < nitems; i++ )
    Selections.Add(selectionsFromPickList[i]);
  delete selectionsFromPickList;
  TDialog::CmOk();
}

//----------------------------------------------------------------------------

DEFINE_RESPONSE_TABLE1(TConfigDialog, TDialog)
  EV_CHILD_NOTIFY(IDOK, BN_CLICKED, CmOk),
  EV_COMMAND(CM_SAVENOW, CmSaveNow),
END_RESPONSE_TABLE;

//
// Constructor. Create interface objects for dialog fields and save
// configuration record for update later.
//
TConfigDialog::TConfigDialog(TWindow* parent, int resId, TConfigRec& rec)
:
  TDialog(parent, resId),
  ConfigRec(rec)
{
  OrientationGroupBox = new TGroupBox(this, ID_ORIENTATION);
  Vertical = new TRadioButton(this, ID_VERTICAL, OrientationGroupBox);
  Horizontal = new TRadioButton(this, ID_HORIZONTAL, OrientationGroupBox);
  SaveOnExit = new TCheckBox(this, ID_SAVE_ON_EXIT);
  ConfirmOnRemove = new TCheckBox(this, ID_CONFIRM_ON_REMOVE);

}

//
// SetupWindow().  Initialize dialog fields with current AppLauncher setup.
//
void
TConfigDialog::SetupWindow()
{
  TDialog::SetupWindow();
  Vertical->SetCheck(ConfigRec.Orientation ? BF_UNCHECKED : BF_CHECKED);
  Horizontal->SetCheck(ConfigRec.Orientation ? BF_CHECKED : BF_UNCHECKED);
  SaveOnExit->SetCheck(ConfigRec.SaveOnExit ? BF_CHECKED : BF_UNCHECKED);
  ConfirmOnRemove->SetCheck(ConfigRec.ConfirmOnRemove ? BF_CHECKED : BF_UNCHECKED);
}

//
// CmOk().  Record any configuration changes in configuration record.
//
void
TConfigDialog::CmOk()
{
  ConfigRec.Orientation = Vertical->GetCheck() == BF_CHECKED ? 0 : 1;
  ConfigRec.SaveOnExit = SaveOnExit->GetCheck() == BF_CHECKED ? 1 : 0;
  ConfigRec.ConfirmOnRemove = ConfirmOnRemove->GetCheck() == BF_CHECKED ? 1 : 0;

  TDialog::CmOk();
}

//
// CmSaveNow().  Send message to parent that the application settings should
// be saved to INI file now.
//
void
TConfigDialog::CmSaveNow()
{
  ConfigRec.SaveNow = 1;
  CmOk();
}
