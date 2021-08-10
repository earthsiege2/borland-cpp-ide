//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/dialog.h>
#include <owl/radiobut.h>
#include <owl/edit.h>
#include <owl/listbox.h>
#include <owl/combobox.h>
#include <owl/scrollba.h>
#include <string.h>
#include <cstring.h>
#include "transfer.h"

const MAXNAMELEN    = 26;
const MAXADDRLEN    = 47;
const MAXCITYSTLEN  = 27;
const MAXCOUNTRYLEN = 27;
const MAXLBDATALEN  = 30;
const MAXCBDATALEN  = 30;

const WM_DIALOG_CLOSED = WM_USER + 100;

#include <pshpack1.h>

struct TTransferStruct {
  TTransferStruct();

  uint16          MrTitle;
  uint16          MsTitle;
  uint16          DrTitle;
  char            NameEdit[MAXNAMELEN];
  char            Addr1Edit[MAXADDRLEN];
  char            Addr2Edit[MAXADDRLEN];
  char            CityStEdit[MAXCITYSTLEN];
  char            CountryEdit[MAXCOUNTRYLEN];
  uint16          CheckBox1;
  uint16          CheckBox2;
  uint16          CheckBox3;
  TListBoxData    ListBoxData;
  char            LBDataEdit[MAXLBDATALEN];
  TComboBoxData   ComboBoxData;
  char            CBDataEdit[MAXCBDATALEN];
  TScrollBarData  ScrollBarData;
};

#include <poppack.h>

TTransferStruct::TTransferStruct()
{
  MrTitle = 1;
  MsTitle = DrTitle = 0;
  NameEdit[0]    = 0;
  Addr1Edit[0]   = 0;
  Addr2Edit[0]   = 0;
  CityStEdit[0]  = 0;
  CountryEdit[0] = 0;

  CheckBox1 = CheckBox3 = 1;
  CheckBox2 = 0;

  //
  // Pre-fill the listbox. It may be sorted, and/or multiselect
  //
  ListBoxData.AddString("Zebra");
  ListBoxData.AddString("Aardvark");
  ListBoxData.AddString("Ocelot");
  ListBoxData.AddString("Beaver");
  ListBoxData.AddString("Emu");
  ListBoxData.Select(2);    // Ocelot
  ListBoxData.Select(3);    // Beaver
  LBDataEdit[0] = 0;

  //
  // Pre-fill the combobox
  //
  ComboBoxData.AddString("Red");
  ComboBoxData.AddString("Pink");
  ComboBoxData.AddString("Blue");
  ComboBoxData.AddString("Green");
  ComboBoxData.AddString("Yellow");
  ComboBoxData.Select(2);    // Blue
  CBDataEdit[0] = 0;

  ScrollBarData.LowValue = 0;
  ScrollBarData.HighValue = 100;
  ScrollBarData.Position = 50;
}


//
// class TTransferDialog
// ~~~~~ ~~~~~~~~~~~~~~~
class TTransferDialog : public TDialog {
  public:
    TTransferDialog(TWindow* parent, int resId, TTransferStruct& ts);
    void CmAddListBox();
    void CmAddComboBox();
    void EvDestroy();

    void CloseWindow(int ret);

  private:
    TListBox*   ListBox;         // cache for transfer access.
    TComboBox*  ComboBox;
    TEdit*      ListBoxData;
    TEdit*      ComboBoxData;
    TScrollBar* ScrollBar;

  DECLARE_RESPONSE_TABLE(TTransferDialog);

};

DEFINE_RESPONSE_TABLE1(TTransferDialog, TDialog)
  EV_COMMAND(CM_ADDLISTBOX, CmAddListBox),
  EV_COMMAND(CM_ADDCOMBOBOX, CmAddComboBox),
  EV_WM_DESTROY,
END_RESPONSE_TABLE;

TTransferDialog::TTransferDialog(TWindow* parent, int resId, TTransferStruct& ts)
:
  TDialog(parent, resId)
{
  new TRadioButton(this, ID_MRBUTTON, 0);
  new TRadioButton(this, ID_MSBUTTON, 0);
  new TRadioButton(this, ID_DRBUTTON, 0);
  new TEdit(this, ID_NAMEEDIT, sizeof(ts.NameEdit));
  new TEdit(this, ID_ADDR1EDIT, sizeof(ts.Addr1Edit));
  new TEdit(this, ID_ADDR2EDIT, sizeof(ts.Addr2Edit));
  new TEdit(this, ID_CITYSTEDIT, sizeof(ts.CityStEdit));
  new TEdit(this, ID_COUNTRYEDIT, sizeof(ts.CountryEdit));
  new TCheckBox(this, ID_CHECKBOX1);
  new TCheckBox(this, ID_CHECKBOX2);
  new TCheckBox(this, ID_CHECKBOX3);
  ListBox = new TListBox(this, ID_LISTBOX);
  ListBoxData = new TEdit(this, ID_LISTBOXDATA, sizeof(ts.LBDataEdit));
  ComboBox = new TComboBox(this, ID_COMBOBOX, MAXCBDATALEN);
  ComboBoxData = new TEdit(this, ID_COMBOBOXDATA, sizeof(ts.CBDataEdit));
  ScrollBar = new TScrollBar(this, ID_SCROLLBAR);
  SetTransferBuffer(&ts);
}

//
// Lets transfer on close even though we are modeless
//
void
TTransferDialog::CloseWindow(int ret)
{
  TransferData(tdGetData);
  TDialog::CloseWindow(ret);
}


//
// Add a string to the list box.
//
void
TTransferDialog::CmAddListBox()
{
  char buf[MAXLBDATALEN] = "";

  ListBoxData->GetLine(buf, MAXLBDATALEN - 1, 0);
  if (buf[0] != '\0')
    ListBox->AddString(buf);
  ListBoxData->DeleteLine(0);
}

//
// Add a string to the combo box.
//
void
TTransferDialog::CmAddComboBox()
{
  char buf[MAXCBDATALEN] = "";

  ComboBoxData->GetLine(buf, MAXCBDATALEN - 1, 0);
  if (buf[0] != '\0')
    ComboBox->AddString(buf);
  ComboBoxData->DeleteLine(0);
}

void
TTransferDialog::EvDestroy()
{
  // tell application that dialog is closing.
  //
  Parent->PostMessage(WM_DIALOG_CLOSED);
  TDialog::EvDestroy();
}


//
// class TTransferInfoDialog
// ~~~~~ ~~~~~~~~~~~~~~~~~~~
class TTransferInfoDialog : public TDialog {
  public:
    TTransferInfoDialog(TWindow* parent, int resId, string& info);
    void SetupWindow();

  private:
    TEdit*  DisplayInfo;
    string& Info;
};

TTransferInfoDialog::TTransferInfoDialog(TWindow* parent, int resId, string& info)
:
  TDialog(parent, resId),
  Info(info)
{
  DisplayInfo = new TEdit(this, ID_INFO, 2000);
}

void
TTransferInfoDialog::SetupWindow()
{
  TDialog::SetupWindow();
  DisplayInfo->Insert(Info.c_str());
}


//
// class TTransferWindow
// ~~~~~ ~~~~~~~~~~~~~~~
class TTransferWindow : public TWindow {
  public:
    TTransferWindow(TWindow* parent = 0);
   ~TTransferWindow()
    {
      delete[] Label;
    }

    void CmDialog();
    void CmTransfer();
    void CmDialogEnable(TCommandEnabler& commandHandler);
    TResult EvDialogClosed(TParam1 wParam, TParam2 lParam);

  private:
    TTransferStruct   TransferStruct;
    TTransferDialog*  TransferDialog;
    char*             Label;     // string to print on transfer.

  DECLARE_RESPONSE_TABLE(TTransferWindow);
};

DEFINE_RESPONSE_TABLE1(TTransferWindow, TWindow)
  EV_COMMAND(CM_DIALOG, CmDialog),
  EV_COMMAND(CM_TRANSFER, CmTransfer),
  EV_COMMAND_ENABLE(CM_DIALOG, CmDialogEnable),
  EV_MESSAGE(WM_DIALOG_CLOSED, EvDialogClosed),
END_RESPONSE_TABLE;


TTransferWindow::TTransferWindow(TWindow* parent)
:
  TWindow(parent)
{
  Label = new char[1024];
  Label[0] = 0;
  TransferDialog = 0;
}

//
// Create modeless dialog.
//
void
TTransferWindow::CmDialog()
{
  TransferDialog = new TTransferDialog(this, IDD_DIALOG, TransferStruct);
  TransferDialog->Create();
  TransferDialog->ShowWindow(SW_SHOW);
}

//
// Transfer data and display.
//
void
TTransferWindow::CmTransfer()
{
  if (TransferDialog)
    TransferDialog->Transfer(&TransferStruct, tdGetData);

  TStringArray& lbStrArray = TransferStruct.ListBoxData.GetStrings();
  TStringArray& cbStrArray = TransferStruct.ComboBoxData.GetStrings();
  unsigned      lbNItems = lbStrArray.GetItemsInContainer();
  unsigned      cbNItems = cbStrArray.GetItemsInContainer();
  unsigned      i;
  char          buf[10];
  string        displayInfo;

  // mailing info.
  //
  displayInfo += "Mailing Label Entered:";
  displayInfo += "\r\n";
  if (TransferStruct.MrTitle)
    displayInfo += "Mr. ";
  else if (TransferStruct.MsTitle)
    displayInfo +=  "Ms. ";
  else if (TransferStruct.DrTitle)
    displayInfo += "Dr. ";
  else
    displayInfo += "??. ";
  displayInfo += TransferStruct.NameEdit;
  displayInfo += "\r\n";
  displayInfo += TransferStruct.Addr1Edit;
  displayInfo += "\r\n";
  if (strcmp(TransferStruct.Addr2Edit, "") != 0) {
    displayInfo += TransferStruct.Addr2Edit;
    displayInfo += "\r\n";
  }
  displayInfo += TransferStruct.CityStEdit;
  displayInfo += "\r\n";
  displayInfo += TransferStruct.CountryEdit;
  displayInfo += "\r\n";
  displayInfo += "\r\n";

  // check boxes.
  //
  if (TransferStruct.CheckBox1)
    displayInfo += "CheckBox #1 checked.\r\n";
  else
    displayInfo += "CheckBox #1 not checked.\r\n";

  if (TransferStruct.CheckBox2)
    displayInfo += "CheckBox #2 checked.\r\n";
  else
    displayInfo += "CheckBox #2 not checked.\r\n";

  if (TransferStruct.CheckBox3)
    displayInfo += "CheckBox #3 checked.\r\n\r\n";
  else
    displayInfo += "CheckBox #3 not checked.\r\n\r\n";

  // list box strings.
  //
  if (lbNItems != 0) {
    TStringArrayIterator iter(lbStrArray);
    displayInfo += "First 5 ListBox strings:\r\n";
    for (i = 0; i < lbNItems && i < 5; i++, iter++) {
      displayInfo += "    ";
      displayInfo += iter.Current();
      displayInfo += "\r\n";
    }
    displayInfo += "\r\n";

    displayInfo += "Listbox selection\r\n    ";
    string sel;
    TransferStruct.ListBoxData.GetSelString(sel);
    displayInfo += sel;
    displayInfo += "\r\n";
  }

  // strings from edit control for list box data.
  //
  if (TransferStruct.LBDataEdit[0] != '\0') {
    displayInfo += "String from Edit control for ListBox data:\r\n    ";
    displayInfo += TransferStruct.LBDataEdit;
    displayInfo += "\r\n";
  }

  // combo box strings.
  //
  if (cbNItems != 0) {
    displayInfo += "First 5 ComboBox strings:\r\n";
    for (i = 0; i < cbNItems && i < 5; i++) {
      displayInfo += "    ";
      displayInfo += cbStrArray[i];
      displayInfo += "\r\n";
    }
    displayInfo += "\r\n";

    displayInfo += "Combobox selection\r\n    ";
    displayInfo += TransferStruct.ComboBoxData.GetSelection();
    displayInfo += "\r\n";
  }

  // strings from edit control for combo box data.
  //
  if (TransferStruct.CBDataEdit[0] != '\0') {
    displayInfo += "String from Edit control for ComboBox data:\r\n    ";
    displayInfo += TransferStruct.CBDataEdit;
  }

  // scroll bar info.
  //
  displayInfo += "\r\nScrollBar Info:\r\n    Low value: ";
  itoa(TransferStruct.ScrollBarData.LowValue, buf, 10);
  displayInfo += buf;
  displayInfo += "  High value: ";
  itoa(TransferStruct.ScrollBarData.HighValue, buf, 10);
  displayInfo += buf;
  displayInfo += "  Current value: ";
  itoa(TransferStruct.ScrollBarData.Position, buf, 10);
  displayInfo += buf;

  // display info.
  //
  TTransferInfoDialog infoDialog(this, ID_DISPLAY_INFO, displayInfo);
  infoDialog.Execute();
}

//
// Disable the 'App|Dialog' menu item if dialog is already active.
//
void
TTransferWindow::CmDialogEnable(TCommandEnabler& commandHandler)
{
  commandHandler.Enable(!TransferDialog);
}

//
// The dialog has closed, notified by dialog.
//
TResult
TTransferWindow::EvDialogClosed(TParam1, TParam2)
{
  TransferDialog = 0;
  return 1;
}


//
// class TTransferApp
// ~~~~~ ~~~~~~~~~~~~
class TTransferApp : public TApplication {
  public:
    TTransferApp()
    :
      TApplication("TransferTest")
    {
    }

    void InitMainWindow()
    {
      TFrameWindow* frame = new TFrameWindow(0, "Test Dialog Transfer",
        new TTransferWindow);
      frame->AssignMenu(ID_MENU);
      SetMainWindow(frame);
    }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TTransferApp().Run();
}
