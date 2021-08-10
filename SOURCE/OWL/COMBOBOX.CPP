//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.6  $
//
// Implementation of TComboBox & TComboBoxData.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/pch.h>
#if !defined(OWL_COMBOBOX_H)
# include <owl/combobox.h>
#endif

DIAG_DECLARE_GROUP(OwlControl);

#if !defined(SECTION) || SECTION == 1

//
// Constructor for a TComboBoxData object
//
TComboBoxData::TComboBoxData()
:
  Strings(10, 0, 10),
  ItemDatas(10, 0, 10)
{
  SelIndex = 0;
}

//
// Destructor for TComboBoxData
//
TComboBoxData::~TComboBoxData()
{
}

//
// Adds a given string to the "Strings" array and copies it into
// "Selection" if "isSelected" is true
//
void
TComboBoxData::AddString(const char* str, bool isSelected)
{
  Strings.Add(str);
  if (isSelected)
    Select(Strings.GetItemsInContainer()-1);
}

//
// Adds a given string and uint32 item to the "Strings" and "ItemDatas"
// array and copies the string into "Selection" if "isSelected" is true
//
void
TComboBoxData::AddStringItem(const char* str, uint32 itemData, bool isSelected)
{
  ItemDatas.Add(itemData);
  AddString(str, isSelected);
}

//
// Selects an item at a given index.
//
void
TComboBoxData::Select(int index)
{
  if (index != CB_ERR) {
    SelIndex = index;
    if (index < Strings.GetItemsInContainer())
      Selection = Strings[index];
  }
}

//
// Selects "str", marking the matching String entry (if any) as selected
//
void
TComboBoxData::SelectString(const char far* str)
{
  int numStrings = Strings.GetItemsInContainer();
  SelIndex = CB_ERR;
  for (int i = 0; i < numStrings; i++)
    if (strcmp(Strings[i].c_str(), str) == 0) {
      SelIndex = i;
      break;
    }
  if (Selection != str)
    Selection = str;
}

//
// Returns the length of the selection string excluding the terminating 0
//
int
TComboBoxData::GetSelStringLength() const
{
  return Selection.length();
}

//
// Copies the selected string into Buffer. BufferSize includes the terminating 0
//
void
TComboBoxData::GetSelString(char far* buffer, int bufferSize) const
{
  if (bufferSize > 0) {
    strncpy(buffer, Selection.c_str(), bufferSize-1);
    buffer[bufferSize - 1] = 0;
  }
}

//----------------------------------------------------------------------------

//
// Constructors for a TComboBox object
//
// By default, an MS-Windows combobox associated with the TComboBox will have
// a vertical scrollbar and will maintain its entries in alphabetical order
//
TComboBox::TComboBox(TWindow*        parent,
                     int             id,
                     int x, int y, int w, int h,
                     uint32           style,
                     uint            textLimit,
                     TModule*        module)
:
  TListBox(parent, id, x, y, w, h, module),
  TextLimit(textLimit)
{
  Attr.Style = WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP |
               CBS_SORT | CBS_AUTOHSCROLL | WS_VSCROLL | style;
  TRACEX(OwlControl, OWL_CDLEVEL, "TComboBox constructed @" << (void*)this);
}

//
//
//
TComboBox::TComboBox(TWindow*   parent,
                     int        resourceId,
                     uint       textLimit,
                     TModule*   module)
:
  TListBox(parent, resourceId, module),
  TextLimit(textLimit)
{
  TRACEX(OwlControl, OWL_CDLEVEL, "TComboBox constructed from resource @" << (void*)this);
}

//
//
//
TComboBox::~TComboBox()
{
  TRACEX(OwlControl, OWL_CDLEVEL, "TComboBox destructed @" << (void*)this);
}

//
// Sets and selects the contents of the associated edit control to the
// supplied string
//
void
TComboBox::SetText(const char far* str)
{
  // If str is 0, then use empty str
  //
  if (!str)
    str = "";

  // If not in listbox, then set the edit/static portion
  //
  if (SetSelString(str, -1) < 0) {
    SetWindowText(str);
    SetEditSel(0, strlen(str));
  }
}

//
// Sets the text length limit member and associated control
//
void
TComboBox::SetTextLimit(uint textlimit)
{
  TextLimit = textlimit;
  if (GetHandle() && TextLimit != 0)
    SendMessage(CB_LIMITTEXT, TextLimit-1);
}

//
// Returns, in the supplied reference parameters, the starting and
// ending positions of the text selected in the associated edit control
//
// Returns CB_ERR is the combo box has no edit control
//
int
TComboBox::GetEditSel(int& startPos, int& endPos)
{
  TResult  retValue = SendMessage(CB_GETEDITSEL);

  startPos = LoUint16(retValue);
  endPos   = HiUint16(retValue);

  return (int)retValue;
}

//
// Shows or hides the drop-down list
//
void
TComboBox::ShowList(bool show)
{
  if ((GetWindowLong(GWL_STYLE) & CBS_DROPDOWN) == CBS_DROPDOWN)
    SendMessage(CB_SHOWDROPDOWN, show);
}

static void
DoAddStringToCB(string& str, void* comboBox)
{
  ((TListBox*)comboBox)->AddString(str.c_str());
}

//
// Transfers the items and selection of the combo box to or from a transfer
// buffer if tdSetData or tdGetData, respectively, is passed as the
// direction
//
// Buffer should point to a TComboBoxData which points to the data to be
// transferred
//
// Transfer returns the size of TComboBoxData
//
// To retrieve the size without transferring data, pass tdSizeData as the
// direction
//
uint
TComboBox::Transfer(void* buffer, TTransferDirection direction)
{
  TComboBoxData* comboBoxData = (TComboBoxData*)buffer;

  if (direction == tdGetData) {
    // Clear out Strings array and fill with contents of list box part
    // Prescan for longest string to allow a single temp allocation
    //
    comboBoxData->Clear();

    int  count = GetCount();
    int  maxStringLen = 0;
    int  i;
    for (i = 0; i < count; i++) {
      int  stringLen = GetStringLen(i);
      if (stringLen > maxStringLen)
        maxStringLen = stringLen;
    }
    char*  tmpString = new char[maxStringLen+1];
    for (i = 0; i < count; i++) {
      GetString(tmpString, i);
      comboBoxData->AddString(tmpString, false);
      comboBoxData->GetItemDatas()[i] = GetItemData(i);
    }
    delete[] tmpString;

    // Get the sel string from the list by index, or if no index from the
    // edit box
    //
    int selIndex = GetSelIndex();
    if (selIndex >= 0) {
      int  stringLen = GetStringLen(selIndex);
      if (stringLen > 0) {
        char* str = new char[stringLen+1];
        GetString(str, selIndex);
        comboBoxData->SelectString(str);
        delete[] str;
      }
      else
        comboBoxData->SelectString("");
    }
    else {
      int  stringLen = GetWindowTextLength();
      if (stringLen > 0) {
        char* str = new char[stringLen+1];
        GetWindowText(str, stringLen+1);
        comboBoxData->SelectString(str);
        delete[] str;
      }
      else
        comboBoxData->SelectString("");
    }
  }
  else if (direction == tdSetData) {
    ClearList();
    comboBoxData->GetStrings().ForEach(DoAddStringToCB, this);
    for (int i = 0; i < comboBoxData->GetItemDatas().GetItemsInContainer(); i++)
      SetItemData(i, comboBoxData->GetItemDatas()[i]);

    SetWindowText(comboBoxData->GetSelection().c_str());
    if (comboBoxData->GetSelIndex() >= 0)
      SetSelString(comboBoxData->GetSelection().c_str(), 0);
  }

  return sizeof(TComboBoxData);
}

//
// Returns name of predefined Windows combobox class
//
char far*
TComboBox::GetClassName()
{
  return "COMBOBOX";
}

//
// Limits the amount of text that the user can enter in the combo box's
// edit control to the value of TextLimit minus 1
//
// Creates plain TWindow aliases for the children in the combo box so that
// TWindow can handle kill focus messages for focus support.
//
void
TComboBox::SetupWindow()
{
  TRACEX(OwlControl, 1, "TComboBox::SetupWindow() @ " << (void*)this);

  TListBox::SetupWindow();

  SetTextLimit(TextLimit);

  THandle hWnd = ::GetWindow(GetHandle(), GW_CHILD);
  while (hWnd) {
    if (!GetWindowPtr(hWnd))
      (new TWindow(hWnd))->SetParent(this);
    hWnd = ::GetWindow(hWnd, GW_HWNDNEXT);
  }
}

//
// Cleanup aliases created in SetupWindow
//
void
TComboBox::CleanupWindow()
{
  HWND hWnd = ::GetWindow(GetHandle(), GW_CHILD);
  while (hWnd) {
    TWindow* wnd = GetWindowPtr(hWnd);
    delete wnd;
    hWnd = ::GetWindow(hWnd, GW_HWNDNEXT);
  }

  // call base class
  //
  TListBox::CleanupWindow();

  TRACEX(OwlControl, 1, "TComboBox::CleanupWindow() @ " << (void*)this);
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE1(TComboBox, TListBox);

#if !defined(BI_NO_OBJ_STREAMING)

//
// Reads an instance of TComboBox from the supplied ipstream
//
void*
TComboBox::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TListBox*)GetObject(), is);
  is >> GetObject()->TextLimit;
  return GetObject();
}

//
// Writes the TComboBox to the supplied opstream
//
void
TComboBox::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TListBox*)GetObject(), os);
  os << GetObject()->TextLimit;
}

#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif
