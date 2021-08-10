//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   source\owl\combobox.cpp
//   Implementation of TComboBox & TComboBoxData.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\combobox.h>
#include <cstring.h>

#if !defined(SECTION) || SECTION == 1

//
// constructor for a TComboBoxData object
//
TComboBoxData::TComboBoxData()
 : Strings(10, 0, 10),
   ItemDatas(10, 0, 10)
{
  SelIndex = 0;
}

//
// destructor for TComboBoxData
//
TComboBoxData::~TComboBoxData()
{
}

//
// adds the supplied string to the "Strings" array and copies it into
// "Selection" if "isSelected" is TRUE
//
void
TComboBoxData::AddString(const char* str, BOOL isSelected)
{
  Strings.Add(str);
  if (isSelected)
    Select(Strings.GetItemsInContainer()-1);
}

void
TComboBoxData::AddStringItem(const char* str, DWORD itemData, BOOL isSelected)
{
  ItemDatas.Add(itemData);
  AddString(str, isSelected);
}

//
// selects an item at a given index.
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
// selects "str", marking the matching String entry (if any) as selected
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
// returns the length of the selection string excluding the terminating 0
//
int
TComboBoxData::GetSelStringLength() const
{
  return Selection.length();
}

//
// copies the selected string into Buffer. BufferSize includes the terminating 0
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
// constructor for a TComboBox object
//
// by default, an MS-Windows combobox associated with the TComboBox will have
// a vertical scrollbar and will maintain its entries in alphabetical order
//
TComboBox::TComboBox(TWindow*        parent,
                     int             id,
                     int x, int y, int w, int h,
                     DWORD           style,
                     UINT            textLen,
                     TModule*        module)
  : TListBox(parent, id, x, y, w, h, module)
{
  TextLen = textLen;
  Attr.Style = WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP |
               CBS_SORT | CBS_AUTOHSCROLL | WS_VSCROLL | style;
}

TComboBox::TComboBox(TWindow*   parent,
                     int        resourceId,
                     UINT       textLen,
                     TModule*   module)
  : TListBox(parent, resourceId, module)
{
  TextLen = textLen;
}

//
// sets and selects the contents of the associated edit control to the
// supplied string
//
void
TComboBox::SetText(const char far* str)
{
  //
  // if str is 0, then use empty str
  //
  if (!str)
    str = "";

  //
  // if not in listbox, then set the edit/static portion
  //
  if (SetSelString(str, -1) < 0) {
    SetWindowText(str);
    SetEditSel(0, strlen(str));
  }
}

//
// returns, in the supplied reference parameters, the starting and
// ending positions of the text selected in the associated edit control
//
// returns CB_ERR is the combo box has no edit control
//
int
TComboBox::GetEditSel(int& startPos, int& endPos)
{
  LRESULT  retValue = HandleMessage(CB_GETEDITSEL);

  startPos = LOWORD(retValue);
  endPos   = HIWORD(retValue);

  return (int)retValue;
}

//
// shows or hides the drop-down list
//
void
TComboBox::ShowList(BOOL show)
{
  if ((GetWindowLong(GWL_STYLE) & CBS_DROPDOWN) == CBS_DROPDOWN)
    HandleMessage(CB_SHOWDROPDOWN, show);
}

static void
DoAddStringToCB(string& str, void* comboBox)
{
  ((TListBox*)comboBox)->AddString(str.c_str());
}

//
// transfers the items and selection of the combo box to or from a transfer
// buffer if tdSetData or tdGetData, respectively, is passed as the
// direction
//
// buffer should point to a TComboBoxData which points to the data to be
// transferred
//
// Transfer returns the size of TComboBoxData
//
// to retrieve the size without transferring data, pass tdSizeData as the
// direction
//
UINT
TComboBox::Transfer(void* buffer, TTransferDirection direction)
{
  TComboBoxData* comboBoxData = (TComboBoxData*)buffer;

  if (direction == tdGetData) {
    //
    // Clear out Strings array and fill with contents of list box part
    // Prescan for longest string to allow a single temp allocation
    //
    comboBoxData->Clear();

    int  count = GetCount();
    int  maxStringLen = 0;
    for (int i = 0; i < count; i++) {
      int  stringLen = GetStringLen(i);
      if (stringLen > maxStringLen)
        maxStringLen = stringLen;
    }
    char*  tmpString = new char[maxStringLen+1];
    for (i = 0; i < count; i++) {
      GetString(tmpString, i);
      comboBoxData->AddString(tmpString, FALSE);
      comboBoxData->GetItemDatas()[i] = GetItemData(i);
    }
    delete tmpString;

    //
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
        delete str;
      
      } else
        comboBoxData->SelectString("");

    } else {
      int  stringLen = GetWindowTextLength();
      if (stringLen > 0) {
        char* str = new char[stringLen+1];
        GetWindowText(str, stringLen+1);
        comboBoxData->SelectString(str);
        delete str;

      } else
        comboBoxData->SelectString("");
    }

  } else if (direction == tdSetData) {
    ClearList();
    comboBoxData->GetStrings().ForEach(DoAddStringToCB, this);
    for (int i = 0; i < comboBoxData->GetItemDatas().GetItemsInContainer(); i++)
      SetItemData(i, comboBoxData->GetItemDatas()[i]);

    SetWindowText(comboBoxData->GetSelection().c_str());
    if (comboBoxData->GetSelIndex() >= 0)
      SetSelIndex(comboBoxData->GetSelIndex());
  }

  return sizeof(TComboBoxData);
}

//
// Return name of predefined Windows combobox class
//
char far*
TComboBox::GetClassName()
{
  return "COMBOBOX";
}

//
// limits the amount of text that the user can enter in the combo box's
// edit control to the value of TextLen minus 1
//
// creates aliases for the children in the combo box so that TWindow can
// handle kill focus messages for focus support.
//
void
TComboBox::SetupWindow()
{
  TListBox::SetupWindow();

  if (TextLen != 0)
    HandleMessage(CB_LIMITTEXT, TextLen-1);

  HWND hWnd = ::GetWindow(HWindow, GW_CHILD);
  while (hWnd) {
    if (!GetWindowPtr(hWnd))
      new TWindow(hWnd);
    hWnd = ::GetWindow(hWnd, GW_HWNDNEXT);
  }
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE1(TComboBox, TListBox);

//
// reads an instance of TComboBox from the supplied ipstream
//
void*
TComboBox::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TListBox*)GetObject(), is);
  is >> GetObject()->TextLen;
  return GetObject();
}

//
// writes the TComboBox to the supplied opstream
//
void
TComboBox::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TListBox*)GetObject(), os);
  os << GetObject()->TextLen;
}

#endif

