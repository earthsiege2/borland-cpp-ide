//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\framewin.h>
#include <owl\static.h>
#include <owl\combobox.h>
#include <owl\inputdia.h>
#include <owl\validate.h>
#include "combobxx.rh"

const WORD ID_CB_BASE                = 200;
const WORD ID_SIMPLE_COMBOBOX        = ID_CB_BASE;
const WORD ID_DROPDOWN_COMBOBOX      = ID_CB_BASE + 1;
const WORD ID_DROPDOWNLIST_COMBOBOX  = ID_CB_BASE + 2;

class TComboBoxWindow : public TFrameWindow {
  public:
    TComboBoxWindow(const char* title);

    // override method defined by TFrameWindow
    //
    void   Paint(TDC&, BOOL, TRect&);

    // message response functions
    //
    void EvCBNSelChange();

    void CmSimple();                  // create simple combobox.
    void CmDropDown();                // create drop-down combobox.
    void CmDropDownList();            // create drop-down-list combobox.
    void CmAddString();               // add string to listbox of combobox.
    void CmAddStringAt();             // add string at index position.
    void CmFindString();              // goto/display index of given string.
    void CmFindStringAt();            // goto index, display string.
    void CmDeleteString();            // delete string.
    void CmDeleteStringAt();          // delete string at index.
    void CmClear();                   // clear combobox.
    void CmShowList();                // show listbox part.
    void CmHideList();                // hide listbox part.

    void CeSimple(TCommandEnabler& commandHandler);
    void CeDropDown(TCommandEnabler& commandHandler);
    void CeDropDownList(TCommandEnabler& commandHandler);
    void CeNotSimple(TCommandEnabler& commandHandler);
    void CeAny(TCommandEnabler& commandHandler);

  private:
    TComboBox*        ComboBox;               // combobox.
    TStatic*          CurSelOfListBox;        // text of selected string.
    TStatic*          CurSelIndexOfListBox;   // index of selected string.
    TStatic*          CurEditString;          // string of edit control.
    TStatic*          SelStringLength;        // length of selected string.
    TStatic*          EditStringLength;       // length of edit string.
    UINT              WhichComboBox;          // current combobox.

    static const int     TextLen;

    void  ResetTextFields();                  // reset text fields to blanks.
    void  UpdateTextFields();                 // updates from combobox.
    int   InputNumber(char* pmpt, char* s);   // get number from user.
    int   InputString(char* pmpt, char* s);   // get string from user.
                                              // get string and number.
    int   InputStringAndNumber(char* pmpt, char* s, int& n);

  DECLARE_RESPONSE_TABLE(TComboBoxWindow);
};

DEFINE_RESPONSE_TABLE1(TComboBoxWindow, TFrameWindow)
  EV_CBN_SELCHANGE(ID_SIMPLE_COMBOBOX,        EvCBNSelChange),
  EV_CBN_SELCHANGE(ID_DROPDOWN_COMBOBOX,      EvCBNSelChange),
  EV_CBN_SELCHANGE(ID_DROPDOWNLIST_COMBOBOX,  EvCBNSelChange),
  EV_COMMAND(CM_SIMPLE,                 CmSimple),
  EV_COMMAND(CM_DROPDOWN,               CmDropDown),
  EV_COMMAND(CM_DROPDOWN_LIST,          CmDropDownList),
  EV_COMMAND(CM_ADD_STRING,             CmAddString),
  EV_COMMAND(CM_ADD_STRING_AT,          CmAddStringAt),
  EV_COMMAND(CM_FIND_STRING,            CmFindString),
  EV_COMMAND(CM_FIND_STRING_AT,         CmFindStringAt),
  EV_COMMAND(CM_DELETE_STRING,          CmDeleteString),
  EV_COMMAND(CM_DELETE_STRING_AT,       CmDeleteStringAt),
  EV_COMMAND(CM_CLEAR,                  CmClear),
  EV_COMMAND(CM_SHOW_LIST,              CmShowList),
  EV_COMMAND(CM_HIDE_LIST,              CmHideList),
  EV_COMMAND_ENABLE(CM_SIMPLE,          CeSimple),
  EV_COMMAND_ENABLE(CM_DROPDOWN,        CeDropDown),
  EV_COMMAND_ENABLE(CM_DROPDOWN_LIST,   CeDropDownList),
  EV_COMMAND_ENABLE(CM_ADD_STRING,      CeAny),
  EV_COMMAND_ENABLE(CM_ADD_STRING_AT,   CeAny),
  EV_COMMAND_ENABLE(CM_FIND_STRING,     CeAny),
  EV_COMMAND_ENABLE(CM_FIND_STRING_AT,  CeAny),
  EV_COMMAND_ENABLE(CM_DELETE_STRING,   CeAny),
  EV_COMMAND_ENABLE(CM_DELETE_STRING_AT,CeAny),
  EV_COMMAND_ENABLE(CM_CLEAR,           CeAny),
  EV_COMMAND_ENABLE(CM_SHOW_LIST,       CeNotSimple),
  EV_COMMAND_ENABLE(CM_HIDE_LIST,       CeNotSimple),
END_RESPONSE_TABLE;

const int TComboBoxWindow::TextLen = 31;

TComboBoxWindow::TComboBoxWindow(const char* title)
   : TFrameWindow(0, title), TWindow(0, title)
{
  ComboBox = 0;
  WhichComboBox = 0;
  AssignMenu("COMBOBOX_MENU");

  // setup static text area.
  new TStatic(this, -1, "Current selection:",  200, 30, 122, 18, 18);
  CurSelOfListBox = new TStatic(this, -1, " ",  392, 30, 158, 18, 25);

  new TStatic(this, -1, "Index of current selection:",  200, 52, 176, 18, 28);
  CurSelIndexOfListBox = new TStatic(this, -1, " ",  392, 52, 158, 18, 25);

  new TStatic(this, -1, "Length of current selection:",  200, 76, 184, 18, 30);
  SelStringLength = new TStatic(this, -1, " ",  392, 76, 158, 18, 25);

  new TStatic(this, -1, "Edit control string:",  200, 103, 124, 18, 30);
  CurEditString= new TStatic(this, -1, " ",  392, 103, 158, 18, 25);

  new TStatic(this, -1, "Length of edit control string:",  200, 125, 186, 18, 30);
  EditStringLength = new TStatic(this, -1, " ",  392, 125, 158, 18, 25);
}

//
// make sure comboboxes are not dropped, if they are, they'll be left floating
//
void
TComboBoxWindow::Paint(TDC&, BOOL, TRect&)
{
  if (ComboBox)
    ComboBox->HideList();
}

//
// A selection of the listbox part of the combobox has taken place.
// Update text info.
//
void
TComboBoxWindow::EvCBNSelChange()
{
  UpdateTextFields();
}

//
// 'ComboBox|Simple' menu item.  Create simple combobox and fill it with some
// strings.
//
void
TComboBoxWindow::CmSimple()
{
  if (ComboBox) {
    ComboBox->Destroy();
    delete ComboBox;
  }
  ComboBox = new TComboBox(this, ID_SIMPLE_COMBOBOX, 10, 30, 150, 150,
                           CBS_SIMPLE, 25);
  ComboBox->Create();
  ComboBox->SetFocus();
  ComboBox->AddString("abc");
  ComboBox->AddString("DEFG");
  ComboBox->AddString("12345");
  ComboBox->AddString("OWL");

  WhichComboBox = ID_SIMPLE_COMBOBOX;

  ResetTextFields();
  UpdateTextFields();
}

//
// 'ComboBox|Drop Down' menu item.  Create drop down combobox and fill it some
// some strings.
//
void
TComboBoxWindow::CmDropDown()
{
  if (ComboBox) {
    ComboBox->Destroy();
    delete ComboBox;
  }
  ComboBox = new TComboBox(this, ID_DROPDOWN_COMBOBOX, 10, 30, 150, 150,
                           CBS_DROPDOWN, 25);
  ComboBox->Create();
  ComboBox->SetFocus();
  ComboBox->AddString("Jack");
  ComboBox->AddString("Denice");
  ComboBox->AddString("If then else");
  ComboBox->AddString("a");
  ComboBox->AddString("99");
  ComboBox->AddString("42");
  ComboBox->AddString("Help!");
  ComboBox->AddString("windows");

  WhichComboBox = ID_DROPDOWN_COMBOBOX;

  ResetTextFields();
  UpdateTextFields();
}

//
// 'ComboBox|Drop Down List' menu item.  Create drop down list combobox and fill
// it with some strings.
//
void
TComboBoxWindow::CmDropDownList()
{
  if (ComboBox) {
    ComboBox->Destroy();
    delete ComboBox;
  }
  ComboBox = new TComboBox(this, ID_DROPDOWNLIST_COMBOBOX, 10, 30, 150, 150,
                           CBS_DROPDOWNLIST, 25);
  ComboBox->Create();
  ComboBox->SetFocus();
  ComboBox->AddString("A B C D");
  ComboBox->AddString("[^abc]");
  ComboBox->AddString("1234567890");
  ComboBox->AddString("C++");
  ComboBox->AddString("Just a string");
  ComboBox->AddString("and another!");

  WhichComboBox = ID_DROPDOWNLIST_COMBOBOX;

  ResetTextFields();
  UpdateTextFields();
}

//
// Add a string to the listbox part of the combobox.
//
void
TComboBoxWindow::CmAddString()
{
  char  buf[TextLen] = "";

  if (InputString("Enter string:", buf)) {
    ComboBox->AddString(buf);
    UpdateTextFields();
  }
}

//
// Insert a string at a given index in the listbox part of the combobox.
//
void
TComboBoxWindow::CmAddStringAt()
{
  char  buf[TextLen] = "";
  int   index;

  if (InputStringAndNumber("Enter string:", buf, index)) {
    if (ComboBox->InsertString(buf, index) != CB_ERR)
       UpdateTextFields();
    else
       MessageBox("Index out of range", "Error", MB_OK);
  }
}

//
// Find string.  Tell combobox to select string at given index.
// Update text fields.
//
void
TComboBoxWindow::CmFindString()
{
  char  buf[TextLen] = "";
  int   index;

  if (InputString("Enter string:", buf)) {
    if ((index = ComboBox->FindString(buf, 0)) != CB_ERR) {
       ComboBox->SendMessage(CB_SETCURSEL, index, 0);
       UpdateTextFields();
    }
    else
       MessageBox("String not found", "Error", MB_OK);
  }
}

//
// Find string.  Tell combobox to select string at given index.
// Update text fields.  Assumes index input is correct, else atoi()
// will return 0 and will be used to select the first string.
//
void
TComboBoxWindow::CmFindStringAt()
{
  char  buf[TextLen] = "";
  int   index;

  if (InputNumber("Enter number:", buf)) {
    index = atoi(buf);
    if (ComboBox->GetString(buf, index) != CB_ERR) {
       ComboBox->SendMessage(CB_SETCURSEL, index, 0);
       UpdateTextFields();
    }
    else
       MessageBox("Index out of range", "Error", MB_OK);
  }
}

//
// Delete string.  Delete string input by user.
//
void
TComboBoxWindow::CmDeleteString()
{
  char  buf[TextLen] = "";
  int   index;

  if (InputString( "Enter string:", buf)) {
    if ((index = ComboBox->FindString(buf, 0)) != CB_ERR) {
      ComboBox->DeleteString(index);
      UpdateTextFields();
    } else
       MessageBox("String not found", "Error", MB_OK);
  }
}

//
// Delete string.  Delete string at given index.
//
void
TComboBoxWindow::CmDeleteStringAt()
{
  char  buf[TextLen] = "";
  int   index;

  if (InputNumber("Enter number:", buf)) {
    index = atoi(buf);
    if (ComboBox->GetString(buf, index) != CB_ERR) {
      ComboBox->DeleteString(index);
      UpdateTextFields();
    } else
       MessageBox("Index out of range", "Error", MB_OK);
  }
}

//
// Clear.  Clear edit control and listbox part of combobox.
//
void
TComboBoxWindow::CmClear()
{
  ComboBox->Clear();
  ComboBox->ClearList();
  ResetTextFields();
}

//
// Show listbox part of combobox.
//
void
TComboBoxWindow::CmShowList()
{
  ComboBox->ShowList();
}

//
// Hide listbox part of combobox.
//
void
TComboBoxWindow::CmHideList()
{
  ComboBox->HideList();
}

//
// Command enablers...
//
// Handle popup menus.  Grey out certain menu items depending on
// whether a combobox has been created or menu item is inappropriate
// for current type of combobox.
//
//

void
TComboBoxWindow::CeSimple(TCommandEnabler& ce)
{
  ce.Enable(WhichComboBox != ID_SIMPLE_COMBOBOX || !ComboBox);
}

void
TComboBoxWindow::CeDropDown(TCommandEnabler& ce)
{
  ce.Enable(WhichComboBox != ID_DROPDOWN_COMBOBOX || !ComboBox);
}

void
TComboBoxWindow::CeDropDownList(TCommandEnabler& ce)
{
  ce.Enable(WhichComboBox != ID_DROPDOWNLIST_COMBOBOX || !ComboBox);
}

void
TComboBoxWindow::CeNotSimple(TCommandEnabler& ce)
{
  ce.Enable(WhichComboBox != ID_SIMPLE_COMBOBOX && ComboBox);
}

void
TComboBoxWindow::CeAny(TCommandEnabler& ce)
{
  ce.Enable(ComboBox != 0);
}

//
// Updates text fields that reflex the combobox's state.
//
void
TComboBoxWindow::UpdateTextFields()
{
  char  buf[TextLen] = "";
  int   index = ComboBox->GetSelIndex();
  int   strLen;

  if (index != -1) {     // is something selected?
    ComboBox->GetString(buf, index);
    strLen = ComboBox->GetStringLen(index);
    CurSelOfListBox->SetText(buf);

    itoa(strLen, buf, 10);
    SelStringLength->SetText(buf);

    itoa(index, buf, 10);
    CurSelIndexOfListBox->SetText(buf);

    ComboBox->GetText(buf, TextLen - 1);
    strLen = ComboBox->GetTextLen();
    CurEditString->SetText(buf);

    if (WhichComboBox == ID_DROPDOWNLIST_COMBOBOX)
      strLen = ComboBox->GetStringLen(ComboBox->GetSelIndex());
    
    itoa(strLen, buf, 10);
    EditStringLength->SetText(buf);
  }
  else
    ResetTextFields();
}

//
// Reset text fields to blanks.
//
void
TComboBoxWindow::ResetTextFields()
{
  CurSelOfListBox->SetText(" ");
  SelStringLength->SetText(" ");
  CurSelIndexOfListBox->SetText(" ");
  CurEditString->SetText(" ");
  EditStringLength->SetText(" ");
}

//
// Get string from user.  Return 1 if successful, 0 otherwise.
// assumes string length of TextLen - 1.
//
int
TComboBoxWindow::InputString(char* pmpt, char* s)
{
  return TInputDialog(this, "String", pmpt, s, TextLen - 1).Execute() == IDOK;
}

int
TComboBoxWindow::InputNumber(char* pmpt, char* s)
{
  return TInputDialog(this, "String", pmpt, s, TextLen-1, 0, 
                      new TFilterValidator("0-9")).Execute() == IDOK;
}

//
// Get string and number (index) from user.  Return 1 if successful, 0
// otherwise. Assumes string length of TextLen - 1.
//
int
TComboBoxWindow::InputStringAndNumber(char* pmpt, char* s, int& n)
{
  char sbuf[TextLen] = "";
  char nbuf[TextLen] = "";
  TInputDialog getStr(this, "String", pmpt, sbuf, TextLen - 1);

  // This input dialog has a validator that only accepts digits
  //
  TInputDialog getNum(this, "String", "Enter number:", nbuf, TextLen - 1,
    0,new TFilterValidator("0-9"));

  if (getStr.Execute() == IDOK &&
      getNum.Execute() == IDOK) {
    strcpy(s, sbuf);
    n = atoi(nbuf);
    return 1;
  } else
    return 0;
}

//----------------------------------------------------------------------------

class TComboBoxApp : public TApplication {
  public:
    void  InitMainWindow();
};

void
TComboBoxApp::InitMainWindow()
{
  MainWindow = new TComboBoxWindow("ComboBox Example");
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TComboBoxApp().Run();
}
