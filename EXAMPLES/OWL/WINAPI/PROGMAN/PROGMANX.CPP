//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/dialog.h>
#include <owl/framewin.h>
#include <owl/applicat.h>
#include <owl/listbox.h>
#include <owl/inputdia.h>
#include <string.h>
#include <stdio.h>
#include <ddeml.h>
#include "progmanx.h"     // Dialog item IDs


//
// TDDEProgTalk is the main window of the application.
// It engages in a DDE conversation with the Program Manager
// to create program groups with a
// user specified list of program items.
//
// See DDEML example


class TDDEProgTalk : public TDialog{
  public:
    //  Create a TListBox object to represent the
    //  dialog's list box.
    //
    TDDEProgTalk(TWindow* parent, TResId resId) :
      TDialog(parent, resId),
      CallBackProc((FARPROC)CallBack) {
      ListBox = new TListBox(this, ID_LISTBOX);
    }
    ~TDDEProgTalk();

  private:
    void SetupWindow();
    void CmAddItem();
    void CmDeleteItem();
    void CmClearItems();
    void CmCreateGroup();
    void EvDDEAck(HWND hWnd, LONG lParam);

    TListBox* ListBox;

    //DDEML
    static HDDEDATA FAR PASCAL _export CallBack(WORD, WORD, HCONV, HSZ, HSZ,
                                                HDDEDATA, DWORD, DWORD);
    DWORD   InstId;
    HCONV   HConv;
    HSZ     Service;
    HSZ     Topic;
    TProcInstance CallBackProc;

  DECLARE_RESPONSE_TABLE(TDDEProgTalk);
};

static TDDEProgTalk* This = 0;

DEFINE_RESPONSE_TABLE1(TDDEProgTalk, TDialog)
  EV_COMMAND(CM_ADDITEM, CmAddItem),
  EV_COMMAND(CM_DELETEITEM, CmDeleteItem),
  EV_COMMAND(CM_CLEARITEMS, CmClearItems),
  EV_COMMAND(CM_CREATEGROUP, CmCreateGroup),
END_RESPONSE_TABLE;

TDDEProgTalk::~TDDEProgTalk()
{
  // This clean up is required for those resources that were allocated during
  // the DDEML conversation.
  //
  if (HConv)
    DdeDisconnect(HConv);     // Let the other party know we are leaving

  if (InstId) {
    DdeFreeStringHandle(InstId, Service);
    DdeFreeStringHandle(InstId, Topic);
    DdeUninitialize(InstId);
  }
}

//  SetupWindow is called right after the DDE window
//  is created.  Initiate the DDE conversation.
//
void
TDDEProgTalk::SetupWindow() {
  InstId = 0;         // MUST be 0 the first time DdeInitialize() is called!
  HConv = 0;
  Service = Topic = 0;
  This = this;

  TDialog::SetupWindow();

  // The code below sets up the DDEML call back function that is used by the
  // DDE Management Library to carry out data transfers between
  // applications.
  //
  if (CallBackProc) {
    if (DdeInitialize(&InstId, (PFNCALLBACK)(FARPROC)CallBackProc, APPCMD_CLIENTONLY, 0) == DMLERR_NO_ERROR) {
      Service = DdeCreateStringHandle(InstId, "PROGMAN", CP_WINANSI);
      Topic = DdeCreateStringHandle(InstId, "PROGMAN", CP_WINANSI);
      if (!Service || !Topic) {
        MessageBox("Creation of strings failed.", Title, MB_ICONSTOP);
        PostQuitMessage(0);
      }
    } else {
      MessageBox("Initialization failed.", Title, MB_ICONSTOP);
      PostQuitMessage(0);
    }
  } else {
    MessageBox("Setup of callback failed.", Title, MB_ICONSTOP);
    PostQuitMessage(0);
  }

}

//
// Add item button response method. Bring up the Add item dialog to
// input a program item string, and add that item to the list box.
//
void
TDDEProgTalk::CmAddItem()
{
  char name[64] = "";

  if (TInputDialog(this, "Add an Item to the Group", "Item &name:",
                   name, sizeof(name)).Execute() != IDCANCEL)
    ListBox->AddString(name);
}

//
// Delete item button response method. Delete the currently selected
// item in the list box.
//
void
TDDEProgTalk::CmDeleteItem()
{
  ListBox->DeleteString(ListBox->GetSelIndex());
}

//
// Clear items button response method. Clear the list box.
//
void
TDDEProgTalk::CmClearItems()
{
  ListBox->ClearList();
}

//
// Create group button response method. Bring up the Create Group
// dialog to input the program group name.
//
void
TDDEProgTalk::CmCreateGroup()
{
  char* createGroup = "[CreateGroup(%s)]";
  char* addItem = "[AddItem(%s)]";

  char name[64] = "";

  if (TInputDialog(this,
                   "Create a new group", "&Name of new group:",
                   name, sizeof(name)).Execute() != IDCANCEL) {
    // Connect to the prog manager
    HConv = DdeConnect(InstId, Service, Topic, 0);
    if (!HConv) {
      MessageBox("Can't start conversation.\nMake sure PROGMAN is running.", Title, MB_ICONSTOP);
      return;
      }

      // Subtract 2 for the '%s' in 'createGroup', plus 1 for null terminator.
      //
      int len = strlen(name) + strlen(createGroup) - 2 + 1;
      int count = ListBox->GetCount();

      int i;
      for (i = 0; i < count; i++)
        // Subtract 2 for the '%s' in 'addItem'.
        len += ListBox->GetStringLen(i) + strlen(addItem) - 2;

      char* commands = new char[len];
      char* ptr=commands;
      sprintf(ptr, createGroup, name);
      for (i = 0; i < count; i++) {
        ListBox->GetString(name, i);
        ptr += strlen(ptr);
        sprintf(ptr, addItem, name);
      }

      //Send command to progman
      if (DdeClientTransaction((LPBYTE)commands, len, HConv, 0L, CF_TEXT, XTYP_EXECUTE, 1000, 0))
        ListBox->ClearList();

      delete[] commands;
  }
}

//
// This call back function is the heart of interaction between this program
// and DDEML.  Because Windows doesn't pass C++ 'this' pointers to call
// back functions, a static 'this' pointer was used.  If you wanted to
// create a Client that would allow for more than one conversation, using a
// List of conversations and their associated 'this' pointers would be one
// possible method to try.  The XTYP_ constants are described in detail in
// the online help.
//
HDDEDATA FAR PASCAL _export
TDDEProgTalk::CallBack(WORD type, WORD, HCONV /*hConv*/, HSZ, HSZ, HDDEDATA /*hData*/,
                    DWORD, DWORD)
{
  switch (type) {
    case XTYP_DISCONNECT:
      This->MessageBox("Disconnected.", This->Title, MB_ICONINFORMATION);
      This->HConv = 0;
      break;

    case XTYP_ERROR:
      This->MessageBox("A critical DDE error has occured.", This->Title, MB_ICONINFORMATION);
  }
  return 0;
}

//----------------------------------------------------------------------------

// TDdeApp is the application object. It creates a main window of type
// TDDEProgTalk.
//
class TDDEApp : public TApplication {
  public:
    TDDEApp() : TApplication() {}
    void InitMainWindow() {
      MainWindow = new TFrameWindow(0, "ProgTalk", new TDDEProgTalk(0, IDD_PROGTALK), TRUE);
    }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TDDEApp().Run();
}
