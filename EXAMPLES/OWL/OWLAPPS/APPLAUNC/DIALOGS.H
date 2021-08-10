//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#if !defined(__DIALOGS_H)
#define __DIALOGS_H

#include <owl\dialog.h>
#include <owl\edit.h>
#include <owl\radiobut.h>
#include <owl\checkbox.h>
#include <owl\groupbox.h>
#include <owl\static.h>
#include <owl\opensave.h>
#include <owl\listbox.h>
#include <owl\combobox.h>
#include <dir.h>

#include "appmgr.h"
#include "applaunc.rh"

typedef TCVectorImp<string> StringList;
typedef TCVectorImp<int>    NumberList;

#define ProgramPathLen MAXPATH
#define ProgramArgsLen 256
#define IconPathLen    MAXPATH

//
// Record to communicate the properties of an application to the dialog
// and back to AppLauncher.
//
struct TAppPropertiesData
{
  TAppPropertiesData(TAppRec* ar)
    : AppRec(ar), ChangeBitmap(FALSE) {}

  BOOL      ChangeBitmap;
  TAppRec*  AppRec;
};

//
// Allow user to the properties of an application.
//
class TAppPropertiesDialog : public TDialog {
  public:
    TAppPropertiesDialog(TWindow* parent, int resId, TAppPropertiesData& data);

    void SetupWindow();
    void CmOk();

  protected:
    // Response functions
    //
    void CmBrowseProg();
    void CmBrowseIcon();
    int  GetFilePath(string& path);

  private:
    // Controls.
    //
    TEdit*        ProgramPath;
    TEdit*        ProgramArgs;
    TEdit*        IconPath;
    TCheckBox*    PromptForInput;
    TGroupBox*    StartupStyles;
    TRadioButton* RunNormal;
    TRadioButton* RunMinimized;
    TRadioButton* RunMaximized;

    // Application properties.
    //
    TAppPropertiesData& AppProperties;

    TOpenSaveDialog::TData  FileData;   // save/restore info.

  DECLARE_RESPONSE_TABLE(TAppPropertiesDialog);
};

//////////////////////////////////////////////////////////////////////

//
// Allow user to enter new application.  Can add new application relative to
// another.
//
class TAddAppDialog : public TDialog {
  public:
    TAddAppDialog(TWindow* parent, int resId, string& progPathStr,
                  int& loc, StringList& pathStrs);

    void SetupWindow();
    BOOL CanClose();

  protected:
    string&               ProgPathStr;
    int&                  Loc;
    StringList&           PathStrs;
    TEdit*                ProgramPath;
    TComboBox*            Paths;

    TOpenSaveDialog::TData  FileData;   // save/restore info.

    // response functions.
    //
    void CmBrowseProg();

  DECLARE_RESPONSE_TABLE(TAddAppDialog);
};

//////////////////////////////////////////////////////////////////////

//
// Generic dialog which asks the use to select one or more items from a list.
//
class TPickListDialog : public TDialog {
  public:
    TPickListDialog(TWindow* parent, int resId,
                    StringList& strings, NumberList& selections);

    void SetupWindow();
    void CmOk();

  protected:
    TListBox*  PickList;

  private:
    StringList&  Strings;
    NumberList&      Selections;

  DECLARE_RESPONSE_TABLE(TPickListDialog);
};

//////////////////////////////////////////////////////////////////////

//
// Record to communicate AppLauncher's configuration options to the dialog
// and back to AppLauncher.
//
struct TConfigRec {

  TConfigRec() : Orientation(0), SaveOnExit(0), ConfirmOnRemove(1),
                 SaveNow(0) {}
  TConfigRec(int o, int soe, int cor) : Orientation(o), SaveOnExit(soe),
    ConfirmOnRemove(cor), SaveNow(0) {}

  int Orientation;  // 0 (vertical) or 1 (horizontal).
  int SaveOnExit;
  int ConfirmOnRemove;
  int SaveNow;
};

class TConfigDialog : public TDialog {
  public:
    TConfigDialog(TWindow* parent, int resId, TConfigRec& rec);

    void SetupWindow();
    void CmOk();

  protected:
    void CmSaveNow();

  private:
    TGroupBox*      OrientationGroupBox;
    TRadioButton*   Vertical;
    TRadioButton*   Horizontal;
    TCheckBox*      SaveOnExit;
    TCheckBox*      ConfirmOnRemove;

    TConfigRec&     ConfigRec;

  DECLARE_RESPONSE_TABLE(TConfigDialog);
};

#endif // __DIALOGS_H
