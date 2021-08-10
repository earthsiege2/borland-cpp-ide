//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\inputdia.h>
#include "appwin.h"
#include "dialogs.h"
#include "applaunc.rh"

DEFINE_RESPONSE_TABLE1(TAppWindow, TFloatingFrame)
  EV_WM_NCRBUTTONDOWN,
  EV_WM_DROPFILES,
  EV_WM_ENDSESSION,
  EV_WM_TIMER,
  EV_COMMAND(CM_ADD_APP, CmAddApp),
  EV_COMMAND(CM_REMOVE_APPS, CmRemoveApps),
  EV_COMMAND(CM_CONFIG_OPTIONS, CmConfigOptions),
  EV_COMMAND(CM_READ_CONFIG, CmReadConfig),
  EV_COMMAND(CM_HELP, CmHelp),
  EV_COMMAND(CM_DUMMY, CmDummy),
  EV_REGISTERED("CM_PROPERTIES", CmProperties),
  EV_REGISTERED("CM_BUTTON_PRESSED", CmButtonPressed),
  EV_REGISTERED("CM_BUTTON_DRAG", CmButtonDrag),
  EV_REGISTERED("CM_REQUEST_ID", CmRequestId),
  EV_REGISTERED("CM_SENDING_ID", CmSendingId),
END_RESPONSE_TABLE;

const   int   TAppWindow::NumBufSize = 10;

static  char  NumBuf[TAppWindow::NumBufSize+1];

//
// Constructor.
//
TAppWindow::TAppWindow(char* title, TWindow* client, string& startupPath)
  : TFloatingFrame(0, title, client, TRUE,
                   TFloatingFrame::DefaultCaptionHeight, TRUE),
    StartupPath(startupPath), Orientation(0), CurINISecNum(UINT_MAX),
    SaveOnExit(0), CleanedUp(0), ConfirmOnRemove(1)
{
  Attr.Style |= WS_POPUP | WS_BORDER | WS_MINIMIZEBOX | WS_SYSMENU;
  SetMargins(TSize(4, 4));
  EnableTinyCaption(52);

  // cache client, we know it is a TAppButtonBar.
  //
  AppButtons = TYPESAFE_DOWNCAST(client, TAppButtonBar);

  // Setup menu items.
  //
  PopupMenu.AppendMenu(MF_STRING, CM_ADD_APP, "Add Application(s)...");
  PopupMenu.AppendMenu(MF_STRING, CM_REMOVE_APPS, "Remove Application(s)...");
  PopupMenu.AppendMenu(MF_STRING, CM_CONFIG_OPTIONS, "Config Options...");
  PopupMenu.AppendMenu(MF_STRING, CM_READ_CONFIG, "Read Configuration...");
  PopupMenu.AppendMenu(MF_STRING, CM_HELP, "Help");
  PopupMenu.AppendMenu(MF_STRING, CM_EXIT, "Exit Program");

  // Initialize file open data.
  //
  FileData.Flags = OFN_FILEMUSTEXIST|OFN_HIDEREADONLY|OFN_CREATEPROMPT|
                   OFN_OVERWRITEPROMPT;
  FileData.SetFilter("AllFiles (*.*)|*.*|");

  // Calculate the maximum # of apps that will fix in the button bar given
  // the current screen resolution.  Take the minimum between horizontal
  // and vertical orientation.
  //
  XExt = GetSystemMetrics(SM_CXSCREEN);
  YExt = GetSystemMetrics(SM_CYSCREEN);
  int minPixels = min(XExt, YExt);
  MaxApps = minPixels / TAppButton::ButtonPixelSize - 3;

  // Insert place holder button.
  // Place holder button is used only when there are no apps.
  //
  AppRemoverGadget = new TBitmapGadget(IDB_APPREMOVER, IDB_APPREMOVER,
                                       TGadget::Embossed, 2, 0);
  AppButtons->Insert(*AppRemoverGadget);

  // Register INI section management messages.
  //
  CM_REQUEST_ID = ::RegisterWindowMessage("CM_REQUEST_ID");
  CM_SENDING_ID = ::RegisterWindowMessage("CM_SENDING_ID");

  // Create INI entries array.
  //
  InUseEntries = new char[NEntries];
}

//
// Destructor.  Remove all application records from app manager.
//
TAppWindow::~TAppWindow()
{
  AppMgr.Flush(1);
  delete InUseEntries;
}

//
// SetupWindow(). Restore from ini file (applaunc.ini in startup dir) and
// tells Windows that we want to accept drag and drop.  Append 'Help' item
// to system menu.
//
void
TAppWindow::SetupWindow()
{
  TFloatingFrame::SetupWindow();

  // Initialize INI entries.
  //
  InitEntries();

  RestoreFromINIFile();
  UpdateAppButtons();
  DragAcceptFiles(TRUE);

  // Append about menu item to system menu.
  //
  TSystemMenu sysMenu(HWindow);
  sysMenu.AppendMenu(MF_SEPARATOR, 0, (LPSTR)0);
  sysMenu.AppendMenu(MF_STRING, CM_HELP, "Help");
}

//
// CleanupWindow(). Tell windows that we are not accepting drag and drop
// any more. Other cleanup.
//
void
TAppWindow::CleanupWindow()
{
  AppLauncherCleanup();
  DragAcceptFiles(FALSE);
  TWindow::CleanupWindow();
}

//
// CmProperties(). If the right mouse button was clicked over a button
// this routine is called to handle it. 'wParam' is id of the button that
// was pressed.  Bring up properties dialog.  If 'OK' terminated the dialog
// then update current app record and button.
//
LRESULT
TAppWindow::CmProperties(WPARAM wParam, LPARAM)
{
  unsigned              loc = AppButtons->LocFromId(wParam);
  TAppRec*              appRec = AppMgr[loc];
  TAppPropertiesData    properties(appRec);
  TAppPropertiesDialog  propDialog(this, ID_APP_PROPERTIES_DIALOG, properties);

  propDialog.Execute();

  if (properties.ChangeBitmap) {
    AppButtons->MoveButton(loc, loc, appRec->GetIconPath());
    ReIdButtons();
    UpdateAppButtons();
  }
  return 1;
}

//
// CmButtonPressed(). When a button is pressed this routine is called
// to handle the starting up of the app.  If requested prompts the user
// for additional input, which will be appended to arguments already
// entered (see properties dialog). Uses WinExec() to run the program.
//
LRESULT
TAppWindow::CmButtonPressed(WPARAM wParam, LPARAM)
{
  TAppRec*  appRec = AppMgr[AppButtons->LocFromId(wParam)];
  int       show;
  string    cmdLine = appRec->ProgramPath;
  char*     appArgs = new char[ProgramArgsLen + 1];
  string    msgBoxTitle;

  strcpy(appArgs, appRec->ProgramArgs.c_str());
  if (appRec->PromptForInput)
    TInputDialog(this, "Application arguments", "Enter application arguments:",
                 appArgs, ProgramArgsLen).Execute();

  cmdLine += " ";
  cmdLine += appArgs;
  switch (appRec->StartupStyle) {
    case 1 :
      show = SW_SHOWNORMAL;
      break;
    case 2 :
      show = SW_MINIMIZE;
      break;
    case 3 :
      show = SW_MAXIMIZE;
      break;
  };

  int result = WinExec(cmdLine.c_str(), show);
  switch (result) {
    case 0:  msgBoxTitle = "Out of memory"; break;
    case 2:  msgBoxTitle = "File not found"; break;
    case 3:  msgBoxTitle = "Path not found"; break;
    default: msgBoxTitle = "Error in WinExec"; break;
  }
  if (result <= 32 ) {
    string appMsg = "App:\n";

    appMsg += appRec->ProgramPath;
    MessageBox(appMsg.c_str(), msgBoxTitle.c_str(), MB_OK);
  }

  delete appArgs;
  return 1;
}

//
// CmButtonDrag().  Called when button is dragged to another part of
// AppLauncher.  The effect is to move the app or remove it.  If the
// drop point is the AppRemoverGadget then remove the app, else move the
// the app to new location.
//
LRESULT
TAppWindow::CmButtonDrag(WPARAM wParam, LPARAM lParam)
{
  unsigned  loc = AppButtons->LocFromId(wParam);
  int       newLoc = LocOfNearestButtonFromPoint(TPoint(LOWORD(lParam),
                                                        HIWORD(lParam)));
  TAppRec*  appRec = AppMgr[loc];

  if (newLoc == -2) {                   // if on app remover.
    if (ConfirmRemove(appRec->ProgramPath)) {
      AnimateAppRemoverGadget();
      RemoveApp(loc);
    }
  }
  else {                                // else move app.
    unsigned  nButtons = AppMgr.Count();

    if (!(newLoc == -1 && loc == nButtons - 1)) {  // don't move self.
      newLoc = newLoc == -1 ? nButtons : newLoc;
      AppButtons->MoveButton(loc, newLoc, appRec->GetIconPath());

      // Move internal app record. Adjust newLoc depending on were
      // button is being moved to.
      //
      AppMgr.Detach(loc, 0);
      AppMgr.AddAt(appRec, newLoc > loc ? newLoc - 1 : newLoc);
    }
  }
  ReIdButtons();
  UpdateAppButtons();
  return 1;
}

//
// EvNCRButtonDown(). Bring up the main menu if the right mouse button was
// pressed while over the title bar.
//
void
TAppWindow::EvNCRButtonDown(UINT /*modKeys*/, TPoint& point)
{
  if(!IsIconic())
    PopupMenu.TrackPopupMenu(TPM_LEFTBUTTON | TPM_RIGHTBUTTON,
                             point.x, point.y, 0, HWindow, 0);
}

//
// EvDropFiles().  Handle the dropping of files to Applauncher.
//
void
TAppWindow::EvDropFiles(TDropInfo drop)
{
  int totalNumberOfFiles = drop.DragQueryFileCount();
  TPoint  point;

  drop.DragQueryPoint(point);

  int     loc = LocOfNearestButtonFromPoint(point);

  loc = loc == -2 ? -1 : loc;
  for (int i = 0; i < totalNumberOfFiles; i++ ) {
    int     fileLength = drop.DragQueryFileNameLen(i) + 1;
    char*   fileName = new char [fileLength + 1];

    drop.DragQueryFile(i, fileName, fileLength);
    if(!DoAddApp(fileName, loc, string()))
      break;
    delete fileName;
  }
  ReIdButtons();
  UpdateAppButtons();
  drop.DragFinish();
}

//
// EvEndSession().  In case Windows closes us down.
//
void
TAppWindow::EvEndSession(BOOL)
{
  AppLauncherCleanup();
}

//
// CmAddApp().  Add applications to AppLauncher. Continue until cancel has
// been pressed.
//
void
TAppWindow::CmAddApp()
{
  string              progPath;
  int                 loc;
  StringList          paths(20, 1);
  unsigned            stop = AppMgr.Count();

  // Initialize string vector with apps already in AppLauncher.
  //
  for (unsigned i = 0; i < stop ;i++ )
    paths.Add(AppMgr[i]->ProgramPath);

  while (1) {
    if (TAddAppDialog(this, ID_ADD_APP_DIALOG, progPath, loc, paths).Execute()
        == IDOK) {
      if (DoAddApp(progPath, loc, string())) {
        ReIdButtons();
        UpdateAppButtons();
      }
      else
        break;
    }
    else
      break;
  }
}

//
// CmRemoveApps().  Ask user which apps to remove, then removes them.
//
void
TAppWindow::CmRemoveApps()
{
  StringList           strings(MaxApps,1);
  NumberList           selections(MaxApps,1);
  unsigned             stop = AppMgr.Count();

  // initialize vector with apps to pick from.
  //
  for (unsigned i = 0; i < stop ;i++ )
    strings.Add(AppMgr[i]->ProgramPath);

  TPickListDialog   pickListDialog(this, ID_PICK_LIST_DIALOG, strings,
                                   selections);
  if (pickListDialog.Execute() == IDOK && ConfirmRemove(string())) {
    for (int j = selections.Count() - 1; j >= 0; j-- )
      RemoveApp(selections[j]);
    ReIdButtons();
    UpdateAppButtons();
  }
}

//
// CmConfigOptions(). Bring up AppLauncher configuration dialog.
//
void
TAppWindow::CmConfigOptions()
{
  TConfigRec    rec(Orientation, SaveOnExit, ConfirmOnRemove);
  TConfigDialog configDialog(this, ID_CONFIG_DIALOG, rec);

  if (configDialog.Execute() == IDOK) {
    int oldOrientation = Orientation;

    Orientation = rec.Orientation;
    SaveOnExit = rec.SaveOnExit;
    ConfirmOnRemove = rec.ConfirmOnRemove;
    if (oldOrientation != Orientation) {
      AppButtons->ChangeOrientation(!Orientation ?
                                     TGadgetWindow::Vertical :
                                     TGadgetWindow::Horizontal);
      UpdateAppButtons();
    }
    if (rec.SaveNow)
      if (!SaveToINIFile(CurINISecNum))
        MessageBox("Maximum number of INI sections have already been created",
                   "Saving to INI file", MB_OK);
  }
}

//
// CmReadConfig(). Read a configuration from the INI file.  The user is asked
// to choose the configuration (section from ini file) desired.  If the
// list presented is empty then there are no configurations available.
// NOTE: If multiple instances of Applauncher are running and more than
// 2 instances attempt to perform this operation there is a change (depending
// on the sections chosen) that those instances may use the same INI
// section, which can lead to unpredictable results.  It is best if you
// complete this operation on one instance at a time to avoid conflict.
//
void
TAppWindow::CmReadConfig()
{
  StringList           sections(20,1);
  NumberList           selections(20,1);
  unsigned             secNum = 1;

  FillEntries();
  for (; secNum < NEntries; secNum++) {
    if (secNum != CurINISecNum && InUseEntries[secNum-1] == NOT_INUSE &&
        INISectionExists(secNum)) {
      string section = string("AL") + itoa(secNum, NumBuf, 10);
      sections.Add(section);
    }
  }

  if (!sections.IsEmpty()) {
    TPickListDialog   pickListDialog(this, ID_PICK_LIST_DIALOG, sections,
                                     selections);
    if (pickListDialog.Execute() == IDOK && selections.Count() != 0) {
      unsigned oldSecNum = CurINISecNum;

      AppButtons->Remove(*AppRemoverGadget);   // don't want to delete it.
      AppMgr.Flush(1);
      AppButtons->Flush(1);
      AppButtons->Insert(*AppRemoverGadget);   // put it back in.
      UpdateAppButtons();
      if (RestoreFromINIFile(atoi(sections[selections[0]].substr(2).c_str()))) {
        MarkInUse(oldSecNum, FALSE);
        UpdateAppButtons();
      }
      else
        MessageBox("Reading configuration from INI failed", "Error",
                   MB_OK);
    }
  } else
    MessageBox("There are no available INI sections", "Read Configuration",
               MB_OK);

}

//
// CmHelp().  Display help.
//
void
TAppWindow::CmHelp()
{
  DisplayHelp();
}

//
// DoAddApp(). Do the work of adding a new app to AppLauncher.  Remove
// placeholder button if necessary.  If the maximum number of apps have
// been added then display an error message and return 0. A return of
// 1 indicates success.
//
int
TAppWindow::DoAddApp(const string& path, int loc, const string& rec)
{
  unsigned  cnt = AppMgr.Count();

  if (cnt == MaxApps) {
    MessageBox("The maximum number of apps have already been added", "Error", MB_OK);
    return 0;
  }

  TAppRec*  appRec;;
  if (rec.is_null() || rec[0] == ' ') {
    appRec = new TAppRec;
    appRec->ProgramPath = path;
  } else
    appRec = new TAppRec(rec);

  if (loc == -1 || loc < -1 || loc > cnt )
    loc = cnt;

  TGadget*  newButton = CreateButton(appRec->GetIconPath(), loc);
  AppMgr.AddAt(appRec, loc);
  if (loc == cnt)
    AppButtons->Insert(*newButton, TGadgetWindow::Before, AppRemoverGadget);
  else
    AppButtons->Insert(*newButton, TGadgetWindow::Before,
                       AppButtons->ButtonWithId(AppButtons->IdFromLoc(loc)));
  return 1;
}

//
// RemoveApp(). Remove an application from AppLauncher.
//
void
TAppWindow::RemoveApp(unsigned loc)
{
  AppMgr.Detach(loc, 1);
  AppButtons->DestroyButton(loc);
}

//
// CreateButton(). Create a new button from program path and id.
//
TGadget*
TAppWindow::CreateButton(string& path, int loc)
{
  if (loc == -1)
    loc = AppMgr.Count();

  return new TAppButton(GetApplication()->GetInstance(), path,
                        AppButtons->IdFromLoc(loc));
}

//
//  INI file format...
//INI file format:
//[AL##]                    // section
//XYLoc = #;#
//Orientation = <0|1>       // 0 = vertical, 1 = horizontal.
//SaveOnExit = <0|1>
//ConfirmOnRemove = <0|1>
//App## = <appstring>
//...

//<appstring> :=
//  <program path>;<program args>;<icon path>;<prompt for input>;<statrup style>
//

//
// RestoreFromINIFile(). Restore AppLauncher from INI file. If restore
// was successfull then return 1, else return 0.
//
int
TAppWindow::RestoreFromINIFile(unsigned secNumber)
{

  if (secNumber == UINT_MAX) {
    secNumber = NextAvailableSection();
    if (secNumber == UINT_MAX)        // in this case no INI file exists.
      return 1;
  }
  else if (SectionInUse(secNumber))
    return 0;

  char      numBuf[NumBufSize+1];
  string    section = string("AL") + itoa(secNumber, numBuf, 10);

  if (RestoreXYLoc(section)       &&
      RestoreOrientation(section) &&
      RestoreSaveOnExit(section)  &&
      RestoreConfirmOnRemove(section) &&
      RestoreApps(section)) {
    CurINISecNum = secNumber;
    MarkInUse(CurINISecNum, TRUE);
    return 1;
  }
  return 0;
}

//
// RestoreXYLoc().  Restore the last x and y location of AppLauncher.
// If the x and y locations would put AppLauncher off the screen the
// locations are adjusted.
//
int
TAppWindow::RestoreXYLoc(const string& section)
{
  char* firstNum;
  char* secondNum;

  GetINIEntry(string("XYLoc"), section, NumBuf, NumBufSize);
  if ((firstNum = strtok(NumBuf, ";")) != 0 &&
      (secondNum = strtok(0, ";")) != 0) {
    Attr.X = atoi(firstNum);
    Attr.Y = atoi(secondNum);
    Attr.X = Attr.X < 0 ? 0 : Attr.X;
    Attr.Y = Attr.Y < 0 ? 0 : Attr.Y;
    if (Attr.X > XExt )
      Attr.X = XExt - Attr.W;
    if (Attr.Y + Attr.H > YExt )
      Attr.Y = 0;
    MoveWindow(Attr.X, Attr.Y, Attr.W, Attr.H, TRUE);
  } else {
    MessageBox("XYLoc entry not found or invalid", "Error", MB_OK);
    return 0;
  }
  return 1;
}

//
// RestoreOrientation().  Set the orientation (vertical or horizontal) of
// AppLauncher.
//
int
TAppWindow::RestoreOrientation(const string& section)
{
  if (!GetINIEntry(string("Orientation"), section, NumBuf, NumBufSize)) {
    MessageBox( "Orientation entry not found or invalid", "Error", MB_OK);
    return 0;
  }
  Orientation = strcmp(NumBuf, "0") != 0;
  AppButtons->ChangeOrientation(!Orientation ? TGadgetWindow::Vertical :
                                               TGadgetWindow::Horizontal);
  return 1;
}

//
// RestoreSaveOnExit(). Set save on exit value (0 or 1).
//
int
TAppWindow::RestoreSaveOnExit(const string& section)
{
  if (!GetINIEntry(string("SaveOnExit"), section, NumBuf, NumBufSize)) {
    MessageBox( "SaveOnExit entry not found or invalid", "Error", MB_OK);
    return 0;
  }
  SaveOnExit = strcmp(NumBuf, "0") != 0;
  return 1;
}

//
// RestoreConfirmOnRemove(). Set confirm on remove value (0 or 1).
//
int
TAppWindow::RestoreConfirmOnRemove(const string& section)
{
  if (!GetINIEntry(string("ConfirmOnRemove"), section, NumBuf, NumBufSize)) {
    MessageBox( "ConfirmOnRemove entry not found or invalid", "Error", MB_OK);
    return 0;
  }
  ConfirmOnRemove = strcmp(NumBuf, "0") != 0;
  return 1;
}

//
// RestoreApps().  Add apps from INI file.
//
int
TAppWindow::RestoreApps(const string& section)
{
  char* destBuf = new char[512];
  int   retval = 1;

  for (unsigned x = 1; ; x++ ) {
    itoa(x, NumBuf, 10);
    string app = "App";
    app += NumBuf;
    if (!GetINIEntry(app, section, destBuf, 512))
      break;
    else {
      if (!DoAddApp(string(), x - 1, string(destBuf))) {
        MessageBox("Application record string was invalid or too many apps",
                   "Error", MB_OK);
        retval = 0;
        break;
      }
    }
  }
  delete destBuf;
  return retval;
}

//
// GetINIEntry().  Read an entry from the INI file.  Specifing the entry (key)
// and section.  On success 1 is returned, else 0.
//
int
TAppWindow::GetINIEntry(const string& entry, const string& section,
                        char* dest, unsigned destBufLen)
{
  string defStr("x");
  string iniPath = StartupPath + "applaunc.ini";

  GetPrivateProfileString(section.c_str(), entry.c_str(), defStr.c_str(), dest,
                          destBufLen, iniPath.c_str());
  if (strcmp(dest, defStr.c_str()) == 0)
    return 0;
  return 1;
}

//
// SaveToINIFile(). Save all settings and apps to INI file.
// Returns 1 on success, 0 otherwise.
//
int
TAppWindow::SaveToINIFile(unsigned secNumber)
{
  if (secNumber == UINT_MAX)
    secNumber = NextSection();

  if (secNumber == UINT_MAX)
    return 0;

  string section = string("AL") + itoa(secNumber, NumBuf, NumBufSize);
  int retval =  (SaveXYLoc(section)       &&
                 SaveOrientation(section) &&
                 SaveSaveOnExit(section)  &&
                 SaveConfirmOnRemove(section)  &&
                 SaveApps(section));
  if (retval) {
    CurINISecNum = secNumber;
    MarkInUse(secNumber, TRUE);
  }
  return retval;
}

//
// SaveXYLoc().  Save current x and y location of AppLauncher.
// Returns 1 on success, 0 otherwise.
//
int
TAppWindow::SaveXYLoc(const string& section)
{
  string xyLocStr;

  Attr.X = Attr.X < 0 ? 0 : Attr.X;
  Attr.Y = Attr.Y < 0 ? 0 : Attr.Y;
  itoa(Attr.X, NumBuf, 10);
  xyLocStr += NumBuf;
  xyLocStr += ";";
  itoa(Attr.Y, NumBuf, 10);
  xyLocStr += NumBuf;
  return WriteINIEntry(section, "XYLoc", xyLocStr);
}

//
// SaveOrientation().  Save current orientation of AppLauncher.
// Returns 1 on success, 0 otherwise.
//
int
TAppWindow::SaveOrientation(const string& section)
{
  string orientationStr;

  itoa(Orientation, NumBuf, NumBufSize);
  orientationStr = NumBuf;
  return WriteINIEntry(section, "Orientation", orientationStr);
}

//
// SaveSaveOnExit(). Save the save on exit indicator.
// Returns 1 on success, 0 otherwise.
//
int
TAppWindow::SaveSaveOnExit(const string& section)
{
  string saveOnExitStr;

  itoa(SaveOnExit, NumBuf, NumBufSize);
  saveOnExitStr = NumBuf;
  return WriteINIEntry(section, "SaveOnExit", saveOnExitStr);
}

//
// SaveConfirmOnRemove(). Save the confirm on remove indicator.
// Returns 1 on success, 0 otherwise.
//
int
TAppWindow::SaveConfirmOnRemove(const string& section)
{
  string confirmOnRemoveStr;

  itoa(ConfirmOnRemove, NumBuf, NumBufSize);
  confirmOnRemoveStr = NumBuf;
  return WriteINIEntry(section, "ConfirmOnRemove", confirmOnRemoveStr);
}

//
// SaveApps().  Save all apps to INI file. Each app is on a separate line.
// Returns 1 on success, 0 otherwise.
//
int
TAppWindow::SaveApps(const string& section)
{
  char*   appBuf = new char[1024];
  int     retval = 1;

  for (unsigned i = 1; i <= AppMgr.Count(); i++) {
    itoa(i, NumBuf, 10);
    if(!WriteINIEntry(section, string("App") + string(NumBuf),
                      AppMgr[i-1]->AsString())) {
      MessageBox("Saving application failed", "Save configuration failure",
                 MB_OK);
      retval = 0;
    }
  }
  // Remove any entries from INI file for apps that have been removed from
  // AppLauncher.
  //
  while (1) {
    itoa(i, NumBuf, 10);
    if (GetINIEntry(string("App") + string(NumBuf), section, appBuf, 1024)) {
      if(!WriteINIEntry(section, string("App") + string(NumBuf), string())) {
        MessageBox("Saving application failed", "Save configuration failure",
                   MB_OK);
        retval = 0;
      }
    } else
      break;
    i++;
  }
  delete appBuf;
  return retval;
}

//
// WriteINIEntry().  Write given key and value to given section in INI file.
// Returns 1 on success, 0 otherwise.
//
int
TAppWindow::WriteINIEntry(const string& section, const string& entryKey,
                          const string& entryValue)
{
  string iniPath = StartupPath + "applaunc.ini";
  return WritePrivateProfileString(section.c_str(), entryKey.c_str(),
                                   entryValue.is_null() ? (LPCSTR)0 :
                                                          entryValue.c_str(),
                                   iniPath.c_str());
}

//
// UpdateAppButtons().  Ask button bar to redraw itself (begin a LayoutSession).
//
void
TAppWindow::UpdateAppButtons()
{
  AppButtons->ReDraw();
}

//
// ReIdButtons().  In the event that buttons are moved around or removed the
// remaining buttons need to be re-numbered to stay in sync with the
// internal array of app records.
//
void
TAppWindow::ReIdButtons()
{
  TAppButton* button = TYPESAFE_DOWNCAST(AppButtons->FirstGadget(), TAppButton);
  unsigned  nButtons = AppMgr.Count();
  for (unsigned i = 0; i < nButtons; i++ ) {
    button->RealId = AppButtons->IdFromLoc(i);
    button = TYPESAFE_DOWNCAST(AppButtons->NextGadget(*button), TAppButton);
  }
}

//
// DisplayHelp().
//
void
TAppWindow::DisplayHelp()
{
  string helpPath = StartupPath + "applaunc.hlp";
  WinHelp(helpPath.c_str(), HELP_FORCEFILE, 0L);
}

//
// LocOfNearestButtonFromPoint().  Return location of nearest button to
// given point.  If the drop point is on the margin or title bar then
// -1 (append) is returned.  If the drop point is the app remover then
// -2 is returned.  Otherwise the location of the button
// on the drop point is returned.
//
int
TAppWindow::LocOfNearestButtonFromPoint(const TPoint& point)
{
  TPoint  p(point);
  int     loc = -1;

  TGadget*g = AppButtons->GadgetFromPoint(p);
  if (g)
    if (g == AppRemoverGadget)
      loc = -2;
    else
      loc = AppButtons->LocFromId(TYPESAFE_DOWNCAST(g, TAppButton)->RealId);
  return loc;
}

//
// AppLauncherCleanup(). Save settings to ini file if requested. Mark ini
// file section as not being in use so other instances may use the section.
// Shutdown any help files active.
//
void
TAppWindow::AppLauncherCleanup()
{
  if (!CleanedUp) {
    CleanedUp = 1;
    if (SaveOnExit)
      if (!SaveToINIFile(CurINISecNum))
        ::MessageBox(0, "Maximum number of INI sections have already been created",
                        "Saving to INI file", MB_OK);
    MarkInUse(CurINISecNum, FALSE);
    delete AppRemoverGadget;

    // Close help window if it is up.
    //
    string helpPath = StartupPath + "applaunc.hlp";
    WinHelp(helpPath.c_str(), HELP_QUIT, 0L);
  }
}

//
// ConfirmRemove(). If 'ConfirmOnRemove' != 0 then return whether or not
// the user confirms. Else return TRUE.
//
BOOL
TAppWindow::ConfirmRemove(const string& p)
{
  if (ConfirmOnRemove) {
    string msg("Are you sure you want to remove ");
    if (p.is_null())
      msg += "multiple items?";
    else
      msg += string("item '") + p + "'?";
    if (MessageBox(msg.c_str(), p.is_null() ? "Remove Items" : "Remove Item",
                   MB_YESNO) != IDYES)
      return FALSE;
  }
  return TRUE;
}

//
// AnimateAppRemoverGadget(). Change bitmap when apps are dropped on it.
// waits about 1/2 a second between bitmaps.
//
void
TAppWindow::AnimateAppRemoverGadget()
{
  AppRemoverGadget->SelectImage(1, TRUE);
  for (unsigned long start = GetTickCount(), end = start + 500; start < end; )
    start = GetTickCount();
  AppRemoverGadget->SelectImage(0, TRUE);
}


//
// INI section managment...
//
// The process of managing the INI sections involves communication with
// the other instances of AppLauncher.  This is accomplished through
// broadcast messages.  Whenever INI sections are referenced a
// broadcast message (CM_REQUEST_ID) is sent to all other instances of
// AppLauncher.  They respond by broadcasting a CM_SENDING_ID with their
// Current INI section number.  The result is that all the the instances
// of AppLauncher get 'updated' on the INI sections that are in use.  This
// guarantees that no INI section is being used more than one instance
// of AppLauncher.
//

//
// Initialize entries array with sections in INI file, if they exist.
//
void
TAppWindow::InitEntries()
{
  for (unsigned i = 0; i < NEntries; i++ ) {
    if (INISectionExists(i+1))
      InUseEntries[i] = NOT_INUSE;
    else
      InUseEntries[i] = NO_ENTRY;
  }

  FillEntries(1);
}

//
// Returns: 0 if not in use, 1 if it is, 2 otherwise (section does not exist).
//
int
TAppWindow::SectionInUse(unsigned sec)
{
  FillEntries();
  if (sec < NEntries && sec != UINT_MAX)
    if (InUseEntries[sec-1] != NO_ENTRY )
      return InUseEntries[sec-1] == INUSE ? 1 : 0;
  return 2;
}

//
// Mark a section as being in use or not.  If 'sec' is out of range FALSE
// is returned, else TRUE.
//
BOOL
TAppWindow::MarkInUse(unsigned sec, BOOL mark)
{
  if (sec < NEntries && sec != UINT_MAX) {
    InUseEntries[sec-1] = mark ? INUSE : NOT_INUSE;
    return TRUE;
  }
  return  FALSE;
}

//
// Return the next section in INI file that is availible (not in use).
//
unsigned
TAppWindow::NextAvailableSection()
{
  FillEntries();
  for (unsigned i = 0; i < NEntries; i++ )
    if (InUseEntries[i] == NOT_INUSE)
      return i+1;
  return UINT_MAX;
}

//
// NextSection(). Return the next section that is not in use or flaged as
// non-existant.  This function is used primarily when creating new
// INI sections because if no sections are available the function
// returns id of new section.
//
unsigned
TAppWindow::NextSection()
{
  FillEntries();
  for (unsigned i = 0; i < NEntries; i++ )
    if (InUseEntries[i] == NO_ENTRY || InUseEntries[i] == NOT_INUSE)
      return i+1;
  return UINT_MAX;
}

//
// INISectionExists().  Return 1 if given INI section exists in the INI
// file, 0 otherwise.
//
int
TAppWindow::INISectionExists(unsigned sec)
{
  char buf[10];
  return GetINIEntry(string("XYLoc"), string("AL") + itoa(sec, buf, 10),
                     NumBuf, NumBufSize);
}

//
// CmRequestId(). Recieved as a result of another instance inquiring
// as to which INI sections are in use.
//
LRESULT
TAppWindow::CmRequestId(WPARAM /*wParam*/, LPARAM lParam)
{
  if (lParam != CurINISecNum)
    ::PostMessage(HWND_BROADCAST, CM_SENDING_ID, 0, CurINISecNum);
  return 1;
}

//
// CmSendingId(). Broadcast CM_SENDING_ID with current INI section number
// in LPARAM.
//
LRESULT
TAppWindow::CmSendingId(WPARAM /*wParam*/, LPARAM lParam)
{
  if (lParam != UINT_MAX)
    InUseEntries[(unsigned)(lParam-1)] = INUSE;
  return 1;
}

//
// FillEntries(). Mark INI section entries array according to which
// INI sections are in use by another instance.  First unmark any entries
// that are marked as being in use by another instance.  We need to do
// this incase one or more instances have been closed since the last time
// this function was called.  Setup timer for a 1/2 second delay so
// other instances have a chance to respond to the CM_REQUEST_ID message.
// Broadcast CM_REQUEST_ID message.  Give control back to OWL (Windows)
// so we (and other apps) can process messages. Finally, destroy timer.
//
void
TAppWindow::FillEntries(int skipClear)
{
  if (!skipClear)
    for (unsigned i = 0; i < NEntries; i++ )
      InUseEntries[i] = InUseEntries[i] == INUSE ? NOT_INUSE : InUseEntries[i];

  unsigned timerId = SetTimer(1, 500U, 0);   // 1/2 second delay.
  WaitingForMsg = 1;
  ::PostMessage(HWND_BROADCAST, CM_REQUEST_ID, 0, CurINISecNum);
  GetApplication()->MessageLoop();
  KillTimer(timerId);
}

//
// EvTimer().  When this gets called ~1/2 second has elapsed since the timer
// was created.  Clear indicator flag and give call EndModal() so
// AppLauncher can resume execution.
//
void
TAppWindow::EvTimer(UINT)
{
  if(WaitingForMsg ) {
    WaitingForMsg = 0;
    GetApplication()->EndModal(1);
  }
}

