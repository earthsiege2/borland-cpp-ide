//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\framewin.h>
#include <owl\static.h>
#include <owl\listbox.h>
#include <owl\inputdia.h>
#include <owl\validate.h>
#include <string.h>
#include "listboxx.rh"

// List box ids.

const WORD ID_LB_BASE               = 200;
const WORD ID_STANDARD              = ID_LB_BASE;
const WORD ID_MULTI_SEL             = ID_LB_BASE + 1;
const WORD ID_MULTI_COLUMN          = ID_LB_BASE + 2;

class TListBoxWindow : public TFrameWindow {
  public:
    TListBoxWindow(const char* title);

    // message response functions
    //

    void EvLBNSelChange();

    void CmStandard();               // create standard list box.
    void CmMultiSel();               // create multi-select list box.
    void CmMultiColumn();            // create multi-column list box.
    void CmAddString();              // add string to list box.
    void CmAddStringAt();            // add string at index position.
    void CmFindString();             // goto index of given string, display string.
    void CmFindStringAt();           // goto index, display string.
    void CmDeleteString();           // delete string.
    void CmDeleteStringAt();         // delete string at index.
    void CmClear();                  // clear ListBox.
    void CmDirList();                // show directory list.

    // Command enablers.
    //
    void CmEnableStandard(TCommandEnabler& commandHandler);
    void CmEnableMultiSel(TCommandEnabler& commandHandler);
    void CmEnableMultiColumn(TCommandEnabler& commandHandler);
    void CmEnableOther(TCommandEnabler& commandHandler);

  private:
    TListBox*         ListBox;                 // list box.
    TStatic*          CurSelOfListBox;         // text of selected string.
    TStatic*          CurSelIndexOfListBox;    // index of selected string.
    TStatic*          SelStringLength;         // length of selected string.
    TStatic*          ItemCount;               // number of items in list box.
    TStatic*          TopIndex;                // index of first visible item.
    TStatic*          SelCount;                // # of selected items.
    TStatic*          SelStrings;              // first 3 selected strings.
    TStatic*          SelIndexes;              // first 3 indexes.

    WORD              WhichListBox;            // current ListBox.

    static const int  TextLen;                 // length of input text.

    void  ResetTextFields();                   // reset text fields to blanks.
    void  UpdateTextFields();                  // updates from list box.
    int   InputString(char* pmpt, char* s);    // get string from user.
    int   InputNumber(char* pmpt, char* s);    // get number from user.
                                               // get string and number.
    int   InputStringAndNumber(char* pmpt, char* s, int& n);

  DECLARE_RESPONSE_TABLE(TListBoxWindow);
};

DEFINE_RESPONSE_TABLE1(TListBoxWindow, TFrameWindow)
  EV_WM_INITMENUPOPUP,
  EV_LBN_SELCHANGE(ID_STANDARD,     EvLBNSelChange),
  EV_LBN_SELCHANGE(ID_MULTI_SEL,    EvLBNSelChange),
  EV_LBN_SELCHANGE(ID_MULTI_COLUMN, EvLBNSelChange),
  EV_COMMAND(CM_STANDARD,           CmStandard),
  EV_COMMAND(CM_MULTI_SEL,          CmMultiSel),
  EV_COMMAND(CM_MULTI_COLUMN,       CmMultiColumn),
  EV_COMMAND(CM_ADD_STRING,         CmAddString),
  EV_COMMAND(CM_ADD_STRING_AT,      CmAddStringAt),
  EV_COMMAND(CM_FIND_STRING,        CmFindString),
  EV_COMMAND(CM_FIND_STRING_AT,     CmFindStringAt),
  EV_COMMAND(CM_DELETE_STRING,      CmDeleteString),
  EV_COMMAND(CM_DELETE_STRING_AT,   CmDeleteStringAt),
  EV_COMMAND(CM_CLEAR,              CmClear),
  EV_COMMAND(CM_DIR_LIST,           CmDirList),

  EV_COMMAND_ENABLE(CM_STANDARD,         CmEnableStandard),
  EV_COMMAND_ENABLE(CM_MULTI_SEL,        CmEnableMultiSel),
  EV_COMMAND_ENABLE(CM_MULTI_COLUMN,     CmEnableMultiColumn),
  EV_COMMAND_ENABLE(CM_ADD_STRING,       CmEnableOther),
  EV_COMMAND_ENABLE(CM_ADD_STRING_AT,    CmEnableOther),
  EV_COMMAND_ENABLE(CM_FIND_STRING,      CmEnableOther),
  EV_COMMAND_ENABLE(CM_FIND_STRING_AT,   CmEnableOther),
  EV_COMMAND_ENABLE(CM_DELETE_STRING,    CmEnableOther),
  EV_COMMAND_ENABLE(CM_DELETE_STRING_AT, CmEnableOther),
  EV_COMMAND_ENABLE(CM_CLEAR,            CmEnableOther),
  EV_COMMAND_ENABLE(CM_DIR_LIST,         CmEnableOther),
END_RESPONSE_TABLE;

const int TListBoxWindow::TextLen = 31;

//
// Constructor.  Setup menu and text areas.
//
TListBoxWindow::TListBoxWindow(const char* title)
  : TFrameWindow(0, title)
{
  ListBox = 0;
  WhichListBox = 0;
  AssignMenu("LISTBOX_MENU");

  // setup static text areas.
  //
  new TStatic(this, -1, "Current selection:",  200, 30, 122, 18, 18);
  CurSelOfListBox = new TStatic(this, -1, " ",  392, 30, 158, 18, 25);

  new TStatic(this, -1, "Index of current selection:",  200, 52, 176, 18, 18);
  CurSelIndexOfListBox = new TStatic(this, -1, " ",  392, 52, 158, 18, 25);

  new TStatic(this, -1, "Length of current selection:",  200, 76, 184, 18, 18);
  SelStringLength = new TStatic(this, -1, " ",  392, 76, 158, 18, 25);

  new TStatic(this, -1, "Number of items:",  200, 98, 184, 18, 18);
  ItemCount = new TStatic(this, -1, " ",  392, 98, 158, 18, 25);

  new TStatic(this, -1, "First visible item:",  200, 120, 184, 18, 18);
  TopIndex = new TStatic(this, -1, " ",  392, 120, 158, 18, 25);

  new TStatic(this, -1, "<Multi-Select only>",  200, 142, 184, 18, 25);

  new TStatic(this, -1, "Number of selected items:",  200, 164, 184, 18, 25);
  SelCount = new TStatic(this, -1, " ",  392, 164, 158, 18, 25);

  new TStatic(this, -1, "First 3 selected strings:",  200, 186, 184, 18, 25);
  SelStrings = new TStatic(this, -1, " ",  392, 186, 158, 18, 35);

  new TStatic(this, -1, "Indexes of first 3 selected strings:",  200, 208,
              200, 18, 25);
  SelIndexes = new TStatic(this, -1, " ",  392, 208, 158, 18, 25);
}

//
// A selection has taken place, update text info.
//
void
TListBoxWindow::EvLBNSelChange()
{
  UpdateTextFields();
}

//
// 'ListBox|Standard' menu item.  Create simple list box and fill it with some
// strings.
//
void
TListBoxWindow::CmStandard()
{
  if (ListBox) {
    ListBox->Destroy();
    delete ListBox;
  }
  ListBox = new TListBox(this, ID_STANDARD, 10, 30, 150, 150);
  ListBox->Attr.Style;
  ListBox->Create();
  ListBox->SetFocus();
  ListBox->AddString("dog");
  ListBox->AddString("bird");
  ListBox->AddString("mouse");
  ListBox->AddString("car");

  WhichListBox = ID_STANDARD;

  ResetTextFields();
  UpdateTextFields();
}

//
// 'ListBox|Multi-Select' menu item.  Create multi-select list box and fill it
// with some strings.
//
void
TListBoxWindow::CmMultiSel()
{
  if (ListBox) {
    ListBox->Destroy();
    delete ListBox;
  }
  ListBox = new TListBox(this, ID_MULTI_SEL, 10, 30, 150, 150);
  ListBox->Attr.Style |= LBS_MULTIPLESEL;
  ListBox->Create();
  ListBox->SetFocus();
  ListBox->AddString("string1");
  ListBox->AddString("Hello!");
  ListBox->AddString("Box");

  WhichListBox = ID_MULTI_SEL;

  ResetTextFields();
  UpdateTextFields();
}

//
// 'ListBox|Multi-Column' menu item.  Create multi-column list box and fill
// it with some strings.
//
void
TListBoxWindow::CmMultiColumn()
{
  if (ListBox) {
    ListBox->Destroy();
    delete ListBox;
  }
  ListBox = new TListBox(this, ID_MULTI_COLUMN, 10, 30, 150, 150);
  ListBox->Attr.Style |= LBS_MULTICOLUMN;
  ListBox->Attr.Style &= ~LBS_SORT;
  ListBox->Create();
  ListBox->SetFocus();
  ListBox->SetColumnWidth(85);   // about half of the list box window.
  ListBox->AddString("Have");
  ListBox->AddString("a");
  ListBox->AddString("nice");
  ListBox->AddString("Day");
  ListBox->AddString("blue");
  ListBox->AddString("green");
  ListBox->AddString("yellow");
  ListBox->AddString("gold");
  ListBox->AddString("red");
  ListBox->AddString("black");
  ListBox->AddString("white");
  ListBox->AddString("grey");

  WhichListBox = ID_MULTI_COLUMN;

  ResetTextFields();
  UpdateTextFields();
}

//
// Add a string to the list box.
//
void
TListBoxWindow::CmAddString()
{
  char  buf[TextLen] = "";

  if (InputString("Enter string:", buf)) {
    ListBox->AddString(buf);
    UpdateTextFields();
  }
}

//
// Insert a string at a given index of the listbox.
//
void
TListBoxWindow::CmAddStringAt()
{
  char  buf[TextLen] = "";
  int   index;

  if (InputStringAndNumber("Enter string:", buf, index)) {
    if (ListBox->InsertString(buf, index) != LB_ERR)
      UpdateTextFields();
    else
      MessageBox("Index out of range", "Error", MB_OK);
  }
}

//
// Find string.  Tell list box to select string at given index.
// Update text fields.
//
void
TListBoxWindow::CmFindString()
{
  char  buf[TextLen] = "";
  int   index;

  if (InputString( "Enter string:", buf)) {
    if ((index = ListBox->FindString(buf, -1)) != LB_ERR) {
      if (WhichListBox == ID_MULTI_SEL)
        ListBox->SetSel(index, TRUE);
      else
        ListBox->HandleMessage(LB_SETCURSEL, index, 0);
      UpdateTextFields();

    } else
      MessageBox("String not found", "Error", MB_OK);
  }
}

//
// Find string.  Tell list box to select string at given index.
// Update text fields.  Assumes index input is correct, else atoi()
// will return 0 and will be used to select the first string.
//
void
TListBoxWindow::CmFindStringAt()
{
  char  buf[TextLen] = "";
  int   index;

  if (InputNumber("Enter number:", buf)) {
    index = atoi(buf);
    if (ListBox->GetString(buf, index) != LB_ERR) {
      if (WhichListBox == ID_MULTI_SEL)
        ListBox->SetSel(index, TRUE);
      else
        ListBox->HandleMessage(LB_SETCURSEL, index, 0);
      UpdateTextFields();

    } else
      MessageBox("Index out of range", "Error", MB_OK);
  }
}

//
// Delete string.  Delete string input by user.
//
void
TListBoxWindow::CmDeleteString()
{
  char  buf[TextLen] = "";

  if (InputString("Enter string:", buf)) {
    int  index;
    if ((index = ListBox->FindString(buf, 0)) != LB_ERR) {
      ListBox->DeleteString(index);
      UpdateTextFields();

    } else
      MessageBox("String not found", "Error", MB_OK);
  }
}

//
// Delete string.  Delete string at given index.
//
void
TListBoxWindow::CmDeleteStringAt()
{
  char  buf[TextLen] = "";
  int   index;

  if (InputNumber("Enter number:", buf)) {
    index = atoi(buf);
    if (ListBox->GetString(buf, index) != LB_ERR) {
      ListBox->DeleteString(index);
      UpdateTextFields();
    }
    else
      MessageBox("Index out of range", "Error", MB_OK);
  }
}

//
// Clear.  Clear list box of all strings.
//
void
TListBoxWindow::CmClear()
{
  ListBox->ClearList();
  ResetTextFields();
}

//
// Directory list.  Add strings representing the files in the current
// directory.
//
void
TListBoxWindow::CmDirList()
{
  ListBox->DirectoryList(0, "*.*");    // all normal files.
  UpdateTextFields();
}

//
// Command Enablers.
//

void
TListBoxWindow::CmEnableStandard(TCommandEnabler& commandHandler)
{
  commandHandler.Enable(WhichListBox != ID_STANDARD ||
                        !ListBox);
}

void
TListBoxWindow::CmEnableMultiSel(TCommandEnabler& commandHandler)
{
  commandHandler.Enable(WhichListBox != ID_MULTI_SEL ||
                        !ListBox);
}

void
TListBoxWindow::CmEnableMultiColumn(TCommandEnabler& commandHandler)
{
  commandHandler.Enable(WhichListBox != ID_MULTI_COLUMN ||
                        !ListBox);
}

void
TListBoxWindow::CmEnableOther(TCommandEnabler& commandHandler)
{
  commandHandler.Enable(ListBox != 0);
}


//
// Updates text fields that reflex the list box's state.
//
void
TListBoxWindow::UpdateTextFields()
{
  char  buf[TextLen] = "";                    // temporary buffers.
  char  buf2[TextLen] = "";
  int   index = ListBox->GetSelIndex();       // Current selection.
  int   strLen;                               // length of string in list box.
  int   multiSelCnt = ListBox->GetSelCount(); // # of selections.

  if (index != LB_ERR || multiSelCnt) {  // is something selected?
    if (WhichListBox == ID_MULTI_SEL) {
      char far* strs[3];
      int  indexes[3];

      // display number of strings selected.
      //
      itoa(multiSelCnt, buf, 10);
      SelCount->SetText(buf);

      // display first 3 selected strings.
      //
      strs[0] = new char[TextLen+1];
      strs[0][0] = 0;
      strs[1] = new char[TextLen+1];
      strs[1][0] = 0;
      strs[2] = new char[TextLen+1];
      strs[2][0] = 0;
      ListBox->GetSelStrings(strs, 3, TextLen);
      strcpy(buf, strs[0]);
      strcat(buf, "  ");
      strcat(strcat(strcat(buf, strs[1]), "  "), strs[2]);
      SelStrings->SetText(buf);

      // display indexes of first 3 selected strings.
      //
      int count = ListBox->GetSelIndexes(indexes, 3);
      if (count != LB_ERR) {
        for (int i = 0; i < count; i++) {
          itoa(indexes[i], buf, 10);
          strcat(strcat(buf2, buf), "  ");
        }
        SelIndexes->SetText( buf2 );
      }
      delete strs[0];
      delete strs[1];
      delete strs[2];
    }
    else {
      // display selected string.
      //
      ListBox->GetString(buf, index);
      strLen = ListBox->GetStringLen(index);
      CurSelOfListBox->SetText(buf);

      // display length of selected string.
      //
      itoa(strLen, buf, 10);
      SelStringLength->SetText(buf);

      // display index of currently selected string.
      //
      itoa(index, buf, 10);
      CurSelIndexOfListBox->SetText(buf);
    }
    // display number of items in list box.
    //
    itoa(ListBox->GetCount(), buf, 10);
    ItemCount->SetText(buf);

    // display index of first visible item in list box.

    itoa(ListBox->GetTopIndex(), buf, 10);
    TopIndex->SetText(buf);
  }
  else
    ResetTextFields();
}

//
// Reset text fields to blanks or default values.
//
void
TListBoxWindow::ResetTextFields()
{
  CurSelOfListBox->SetText(" ");
  SelStringLength->SetText(" ");
  CurSelIndexOfListBox->SetText(" ");
  ItemCount->SetText(" ");
  TopIndex->SetText(" ");
  SelCount->SetText(" ");
  SelStrings->SetText(" ");
  SelIndexes->SetText(" ");
}

//
// Get string from user.  Return 1 if successful, 0 otherwise.
// assumes string length of TextLen - 1.
//
int
TListBoxWindow::InputString(char* pmpt, char* s)
{
  return TInputDialog(this, "String", pmpt, s, TextLen - 1).Execute() == IDOK;
}

int
TListBoxWindow::InputNumber( char* pmpt, char* s )
{
  return TInputDialog(this, "Number", pmpt, s, TextLen-1, 0,
                      new TFilterValidator("0-9")).Execute() == IDOK;
}

//
// Get string and number (index) from user.  Return 1 if successful, 0
// otherwise. Assumes string length of TextLen - 1.
//
int
TListBoxWindow::InputStringAndNumber(char* pmpt, char* s, int& n)
{
  char sbuf[TextLen] = "";
  char nbuf[TextLen] = "";
  TInputDialog getStr(this, "String", pmpt, sbuf, TextLen - 1);

  // This input dialog has a validator that only accepts digits
  //
  TInputDialog getNum(this, "String", "Enter number:", nbuf, TextLen-1, 0,
                      new TFilterValidator("0-9"));

  if (getStr.Execute() == IDOK &&
      getNum.Execute() == IDOK) {
    strcpy(s, sbuf);
    n = atoi(nbuf);
    return 1;
  } else
    return 0;
}

//----------------------------------------------------------------------------

class TListBoxApp : public TApplication {
  public:
    void  InitMainWindow();
};

void
TListBoxApp::InitMainWindow()
{
  MainWindow = new TListBoxWindow("ListBox Example");
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TListBoxApp().Run();
}
