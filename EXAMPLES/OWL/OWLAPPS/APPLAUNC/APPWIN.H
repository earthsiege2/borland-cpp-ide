//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#if !defined(__APPWIN_H)
#define __APPWIN_H

#include <owl\menu.h>
#include <owl\floatfra.h>
#include <owl\opensave.h>
#include <owl\bitmapga.h>
#include "appbtnba.h"
#include "appmgr.h"
#include "appbtn.h"

#define NO_ENTRY  '2'       // does not exist in INI file.
#define INUSE     '1'       // in use by another instance of AppLauncher.
#define NOT_INUSE '0'       // open, not used by any instance of AppLauncher.
#define NEntries  128       // maximum number of instances that can be running.

//
// Frame window of app. Contains the button bar and application manager.
//
class TAppWindow : public TFloatingFrame {
  public:
    static const int        NumBufSize;   // max size of number buffer.

    TAppWindow(char* title, TWindow* client, string& startupPath);
    ~TAppWindow();

    void      SetupWindow();
    void      CleanupWindow();

  protected:
    LRESULT   CmProperties(WPARAM wParam, LPARAM lParam);
    LRESULT   CmButtonPressed(WPARAM wParam, LPARAM lParam);
    LRESULT   CmButtonDrag(WPARAM wParam, LPARAM lParam);
    void      EvNCRButtonDown(UINT modKeys, TPoint& point);
    void      EvDropFiles(TDropInfo drop);
    void      EvEndSession(BOOL b);

    void      CmAddApp();
    void      CmRemoveApps();
    void      CmConfigOptions();
    void      CmReadConfig();
    void      CmHelp();
    void      CmDummy() {}
    void      CmPlaceHolder();

  private:
    unsigned                CurINISecNum; // section of INI file in use.
    int                     SaveOnExit;   // save settings to INI file on exit?
    int                     Orientation;  // 0 = Vertical, 1 =  Horizontal.
    string&                 StartupPath;  // dir. AppLauncher was started from.
    unsigned                MaxApps;      // max. # of apps given screen res.
    unsigned                XExt;         // vertical screen size.
    unsigned                YExt;         // horizontal screen size.
    TPopupMenu              PopupMenu;    // main menu.
    TAppMgr                 AppMgr;       // manages internal rep. of apps.
    TAppButtonBar*          AppButtons;   // cache client object.
    TBitmapGadget*          AppRemoverGadget; // used when no apps.
    int                     CleanedUp;    // have we called shutdown routine?
    int                     ConfirmOnRemove;  // confirm on remove enabled?
    char*                   InUseEntries; // INI sections in use.
    int                     CM_REQUEST_ID;// request ids from other instances.
    int                     CM_SENDING_ID;// send id to other instances.
    int                     WaitingForMsg;    // are we waiting for message?
    TOpenSaveDialog::TData  FileData;     // save/restore info.

    int       DoAddApp(const string& path, int loc, const string& rec);
    void      RemoveApp(unsigned loc);
    TGadget*  CreateButton(string& path, int loc);
    int       RestoreFromINIFile(unsigned secNumber = UINT_MAX);
    int       RestoreXYLoc(const string& section);
    int       RestoreOrientation(const string& section);
    int       RestoreSaveOnExit(const string& section);
    int       RestoreConfirmOnRemove(const string& section);
    int       RestoreApps(const string& section);
    int       GetINIEntry(const string& entry, const string& section,
                          char* dest, unsigned destBufLen);
    int       SaveToINIFile(unsigned secNumber);
    int       SaveXYLoc(const string& section);
    int       SaveOrientation(const string& section);
    int       SaveSaveOnExit(const string& section);
    int       SaveConfirmOnRemove(const string& section);
    int       SaveApps(const string& section);
    int       WriteINIEntry(const string& section, const string& entryKey,
                            const string& entryValue);
    void      UpdateAppButtons();
    void      ReIdButtons();
    void      DisplayHelp();
    int       LocOfNearestButtonFromPoint(const TPoint& point);
    void      AppLauncherCleanup();
    BOOL      ConfirmRemove(const string& p);
    void      AnimateAppRemoverGadget();

    // INI section management.
    //
    void      InitEntries();
    int       SectionInUse(unsigned sec);
    BOOL      MarkInUse(unsigned sec, BOOL mark);
    unsigned  NextAvailableSection();
    unsigned  NextSection();
    int       INISectionExists(unsigned sec);
    LRESULT   CmRequestId(WPARAM wParam, LPARAM lParam);
    LRESULT   CmSendingId(WPARAM wParam, LPARAM lParam);
    void      FillEntries(int skipClear = 0);
    void      EvTimer(UINT);

  DECLARE_RESPONSE_TABLE(TAppWindow);
};

#endif // __APPWIN_H
