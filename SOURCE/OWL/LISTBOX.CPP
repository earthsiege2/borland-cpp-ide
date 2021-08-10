//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   source\owl\listbox.cpp
//   Implementation of class TListBox and TlistBoxData.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\listbox.h>
#include <stdlib.h>
#include <cstring.h>

#if !defined(SECTION) || SECTION == 1

#define MULTIPLESEL    (LBS_MULTIPLESEL | LBS_EXTENDEDSEL)

//
// TListBoxData constructor
//
TListBoxData::TListBoxData()
 : Strings(10, 0, 10),
   ItemDatas(10, 0, 10),
   SelIndices(1, 0, 10)
{
}

//
// TListBoxData destructor
//
TListBoxData::~TListBoxData()
{
}

//
// adds "str" to "Strings"
//
// if "isSelected" is TRUE, marks it as selected
//
void
TListBoxData::AddString(const char* str, BOOL isSelected)
{
  Strings.Add(str);
  if (isSelected)
    Select(Strings.GetItemsInContainer()-1);
}

//
// adds str and associated item data to strings and datas
//
void
TListBoxData::AddStringItem(const char* str, DWORD itemData, BOOL isSelected)
{
  ItemDatas.Add(itemData);
  AddString(str, isSelected);
}

//
// selects an item at a given index.
//
void
TListBoxData::Select(int index)
{
  if (index != LB_ERR)
    SelIndices.Add(index);
}

//
// adds "str" to selection lists if it is in Strings
//
void
TListBoxData::SelectString(const char far* str)
{
  for (int i = 0; i < Strings.GetItemsInContainer(); i++)
    if (strcmp(Strings[i].c_str(), str) == 0) {
      Select(i);
      break;
    }
}

//
// returns the length of the string at the passed selection index
// excluding the terminating 0
//
int
TListBoxData::GetSelStringLength(int index) const
{
  if (index >= 0 && index < GetSelCount())
    return Strings[SelIndices[index]].length();
  return -1;
}

//
// copies the string at the passed selection index into buffer
//
// bufferSize includes the terminating 0
//
void
TListBoxData::GetSelString(char far* buffer, int bufferSize, int index) const
{
  if (bufferSize > 0) {
    if (index < 0 || index >= GetSelCount())
      *buffer = 0;

    else {
      strncpy(buffer, Strings[SelIndices[index]].c_str(), bufferSize-1);
      buffer[bufferSize - 1] = 0;
    }
  }
}

//
// copies the string at the passed index in SelStrings into str
//
void
TListBoxData::GetSelString(string& str, int index) const
{
  if (index >= 0 && index < GetSelCount())
    str = Strings[SelIndices[index]];
  else
    str = "";
}

TStringArray::TStringArray( int upper, int lower, int delta ) :
    Data( upper, lower, delta )
{
}

int TStringArray::LowerBound() const
{
    return Data.LowerBound();
}

int TStringArray::UpperBound() const
{
    return Data.UpperBound();
}

unsigned TStringArray::ArraySize() const
{
    return Data.ArraySize();
}

int TStringArray::IsFull() const
{
    return Data.IsFull();
}

int TStringArray::IsEmpty() const
{
    return Data.IsEmpty();
}

unsigned TStringArray::GetItemsInContainer() const
{
    return Data.GetItemsInContainer();
}

int TStringArray::Add( const string & t )
{
    return Data.Add(t);
}

int TStringArray::Detach( const string & t )
{
    return Data.Detach(t);
}

int TStringArray::Detach( int loc )
{
    return Data.Detach( loc );
}

int TStringArray::Destroy( const string & t )
{
    return Detach(t);
}

int TStringArray::Destroy( int loc )
{
    return Detach(loc);
}

int TStringArray::HasMember( const string & t ) const
{
    return Data.HasMember(t);
}

int TStringArray::Find( const string & t ) const
{
    return Data.Find(t);
}

string & TStringArray::operator []( int loc )
{
    return Data[loc];
}

string & TStringArray::operator []( int loc ) const
{
    return Data[loc];
}

void TStringArray::ForEach( IterFunc iter, void *args )
{
    Data.ForEach( iter, args );
}

string *TStringArray::FirstThat( CondFunc cond, void *args ) const
{
    return Data.FirstThat( cond, args );
}

string *TStringArray::LastThat( CondFunc cond, void *args ) const
{
    return Data.LastThat( cond, args );
}

void TStringArray::Flush()
{
    Data.Flush();
}

TIntArray::TIntArray( int upper, int lower, int delta ) :
    Data( upper, lower, delta )
{
}

int TIntArray::LowerBound() const
{
    return Data.LowerBound();
}

int TIntArray::UpperBound() const
{
    return Data.UpperBound();
}

unsigned TIntArray::ArraySize() const
{
    return Data.ArraySize();
}

int TIntArray::IsFull() const
{
    return Data.IsFull();
}

int TIntArray::IsEmpty() const
{
    return Data.IsEmpty();
}

unsigned TIntArray::GetItemsInContainer() const
{
    return Data.GetItemsInContainer();
}

int TIntArray::Add( const TInt & t )
{
    return Data.Add(t);
}

int TIntArray::Detach( const TInt & t )
{
    return Data.Detach(t);
}

int TIntArray::Detach( int loc )
{
    return Data.Detach( loc );
}

int TIntArray::Destroy( const TInt & t )
{
    return Detach(t);
}

int TIntArray::Destroy( int loc )
{
    return Detach(loc);
}

int TIntArray::HasMember( const TInt & t ) const
{
    return Data.HasMember(t);
}

int TIntArray::Find( const TInt & t ) const
{
    return Data.Find(t);
}

TInt & TIntArray::operator []( int loc )
{
    return Data[loc];
}

TInt & TIntArray::operator []( int loc ) const
{
    return Data[loc];
}

void TIntArray::ForEach( IterFunc iter, void *args )
{
    Data.ForEach( iter, args );
}

TInt *TIntArray::FirstThat( CondFunc cond, void *args ) const
{
    return Data.FirstThat( cond, args );
}

TInt *TIntArray::LastThat( CondFunc cond, void *args ) const
{
    return Data.LastThat( cond, args );
}

void TIntArray::Flush()
{
    Data.Flush();
}

TDwordArray::TDwordArray( int upper, int lower, int delta ) :
    Data( upper, lower, delta )
{
}

int TDwordArray::LowerBound() const
{
    return Data.LowerBound();
}

int TDwordArray::UpperBound() const
{
    return Data.UpperBound();
}

unsigned TDwordArray::ArraySize() const
{
    return Data.ArraySize();
}

int TDwordArray::IsFull() const
{
    return Data.IsFull();
}

int TDwordArray::IsEmpty() const
{
    return Data.IsEmpty();
}

unsigned TDwordArray::GetItemsInContainer() const
{
    return Data.GetItemsInContainer();
}

int TDwordArray::Add( const DWORD & t )
{
    return Data.Add(t);
}

int TDwordArray::Detach( const DWORD & t )
{
    return Data.Detach(t);
}

int TDwordArray::Detach( int loc )
{
    return Data.Detach( loc );
}

int TDwordArray::Destroy( const DWORD & t )
{
    return Detach(t);
}

int TDwordArray::Destroy( int loc )
{
    return Detach(loc);
}

int TDwordArray::HasMember( const DWORD & t ) const
{
    return Data.HasMember(t);
}

int TDwordArray::Find( const DWORD & t ) const
{
    return Data.Find(t);
}

DWORD & TDwordArray::operator []( int loc )
{
    return Data[loc];
}

DWORD & TDwordArray::operator []( int loc ) const
{
    return Data[loc];
}

void TDwordArray::ForEach( IterFunc iter, void *args )
{
    Data.ForEach( iter, args );
}

DWORD *TDwordArray::FirstThat( CondFunc cond, void *args ) const
{
    return Data.FirstThat( cond, args );
}

DWORD *TDwordArray::LastThat( CondFunc cond, void *args ) const
{
    return Data.LastThat( cond, args );
}

void TDwordArray::Flush()
{
    Data.Flush();
}

//----------------------------------------------------------------------------

//
// constructor for TListBox
//
// initializes its data fields using parameters passed and default values
//
// by default, an MS-Windows listbox associated with the TListBox will:
//   - be visible upon creation
//   - have a border and a vertical scrollbar
//   - maintain entries in alphabetical order
//   - notify its parent when a selection is made
//
TListBox::TListBox(TWindow*   parent,
                   int        id,
                   int x, int y, int w, int h,
                   TModule*   module)
  : TControl(parent, id, 0, x, y, w, h, module)
{
  Attr.Style |= LBS_STANDARD;
}

TListBox::TListBox(TWindow*   parent,
                   int        resourceId,
                   TModule*   module)
  : TControl(parent, resourceId, module)
{
}

char far*
TListBox::GetClassName()
{
  return "LISTBOX";
}

//
// transfers state information for a TListBox
//
// transfers the items and selection of the list to or from a transfer
// buffer if tdSetData or tdGetData, respectively, is passed as the
// direction
//
// buffer should point to a TListBoxData which points to the data to be
// transferred
//
// Transfer returns the size of TListBoxData
//
// to retrieve the size without transferring data, pass tdSizeData as the
// direction
//
UINT
TListBox::Transfer(void* buffer, TTransferDirection direction)
{
  long           style = GetWindowLong(GWL_STYLE);
  TListBoxData*  listBoxData = (TListBoxData*)buffer;

  if (direction == tdGetData) {
    //
    // first, clear out Strings array and fill with contents of list box
    //
    listBoxData->Clear();

    //
    // pre-calculate max string length so that one big buffer can be used
    //
    int  count = GetCount();
    int  maxStrLen = 0;
    for (int i = 0; i < count; i++) {
      int  strLen = GetStringLen(i);
      if (strLen > maxStrLen)
        maxStrLen = strLen;
    }
    //
    // Get each string and item data in the listbox & add to listboxdata
    //
    char*  tmpStr = new char[maxStrLen+1];
    for (i = 0; i < GetCount(); i++) {
      GetString(tmpStr, i);
      listBoxData->AddStringItem(tmpStr, GetItemData(i), FALSE);
    }
    delete tmpStr;

    //
    // update transfer data with new selected item(s)
    //
    listBoxData->ResetSelections();

    if (!(style & MULTIPLESEL)) {
      //
      // single selection
      //
      listBoxData->Select(GetSelIndex());

    } else {
      //
      // multiple selection
      //
      int  selCount = GetSelCount();
      if (selCount > 0) {
        int*  selections = new int[selCount];

        GetSelIndexes(selections, selCount);

        // Select each item by index
        //
        for (int selIndex = 0; selIndex < selCount; selIndex++)
          listBoxData->Select(selections[selIndex]);

        delete selections;
      }
    }

  } else if (direction == tdSetData) {
    ClearList();

    //
    // add each string, item data and selections in listBoxData to list box
    //
    int  selCount = listBoxData->GetSelCount();  // for multi selection
    int  selIndex;                               // for single selection
    for (int i = 0; i < listBoxData->GetStrings().GetItemsInContainer(); i++) {
      int index = AddString(listBoxData->GetStrings()[i].c_str());
      SetItemData(index, listBoxData->GetItemDatas()[i]);
      if (style & MULTIPLESEL) {
        for (int j = 0; j < selCount; j++)
          if (listBoxData->GetSelIndices()[j] == i) {
            SetSel(index, TRUE);
            break;
          }
      } else {
        if (listBoxData->GetSelIndices()[0] == i)
          selIndex = index;
        else
          if (index <= selIndex)
            selIndex++;
      }
    }
    if (!(style & MULTIPLESEL))
      SetSelIndex(selIndex);
  }
  
  return sizeof(TListBoxData);
}

//
// returns the index of the first string in the associated listbox
// which is the same as the passed string
//
// searches for a match beginning at the passed indexStart
//
// if a match is not found after the last string has been compared,
// the search continues from the beginning of the list until a match
// is found or until the list has been completely traversed
//
// searches from beginning of list when -1 is passed as the index
//
// returns the index of the selected string; a negative value is returned
// if an error occurs
//
// for single or multiple-selection list boxes
//
int
TListBox::FindExactString(const char far* findStr, int indexStart) const
{
  BOOL  found = FALSE;
  int   firstMatch = indexStart = FindString(findStr, indexStart);
  do {
    if (indexStart > -1) {
      char*  tmpStr = new char[GetStringLen(indexStart) + 1];

      GetString(tmpStr, indexStart);

      if (strcmp(tmpStr, findStr) == 0)
        found = TRUE;

      else
        indexStart = FindString(findStr, indexStart);

      delete tmpStr;
    }
  } while (!found && indexStart != firstMatch);

  return found ? indexStart : -1;
}

//
// for use with single-selection list boxes (and combo boxes)
//
// retrieves the text of the string which is selected in the associated
// listbox
//
// returns the number of characters copied; -1 is returned if no string
// is selected or this is a multiple-selection list box
//
// since the Windows function is not passed a size parameter, we have to
// allocate a string to hold the largest string (gotten from a query), and
// copy a part of it
//
int
TListBox::GetSelString(char far* str, int maxChars) const
{
  int  index = GetSelIndex();

  if (index > -1) {
    int  length = GetStringLen(index);

    if (maxChars >= length)
      return GetString(str, index);

    else {
      char*  tmpStr = new char[length + 1];

      if (tmpStr) {
        GetString(tmpStr, index);
        strncpy(str, tmpStr, maxChars);
        delete tmpStr;
        return maxChars;
      }
    }
  }
  return -1;
}

//
// returns the number of selected items in the list box. For
// multiple-selection list boxes only
//
int
TListBox::GetSelCount() const
{
  if (!(GetWindowLong(GWL_STYLE) & MULTIPLESEL))
    return GetSelIndex() < 0 ? 0 : 1;

  //
  // multiple-selection list box
  //
  return (int)CONST_CAST(TListBox*,this)->HandleMessage(LB_GETSELCOUNT);
}

//
// retrieves the text of the strings which are selected in the
// associated listbox
//
// returns the number of items put into Strings.  -1 is returned if this is
// not a multiple-selection list box
//
// since the Windows function is not passed a size parameter, we have to
// allocate a string to hold the largest string (gotten from a query), and
// copy a part of it
//
// only for use with multiple-selection list boxes
//
int
TListBox::GetSelStrings(char far** strs, int maxCount, int maxChars) const
{
  if (!(GetWindowLong(GWL_STYLE) & MULTIPLESEL))
    return -1;

  int i = GetSelCount();

  if (i < maxCount)
    maxCount = i;

  if (maxCount > 0) {
    int*  selections = new int[maxCount];

    GetSelIndexes(selections, maxCount);

    for (int selIndex = 0; selIndex < maxCount; selIndex++) {
      int  tmpStrLen = GetStringLen(selections[selIndex]);

      if (maxChars >= tmpStrLen)
        GetString(strs[selIndex], selections[selIndex]);

      else {
        char*  tmpStr = new char[tmpStrLen+1];

        if (tmpStr) {
          GetString(tmpStr, selections[selIndex]);
          strncpy(strs[selIndex], tmpStr, maxChars);
          delete tmpStr;
        }
      }
    }
    delete selections;
  }
  return maxCount;
}

//
// selects the first string in the associated listbox following the
// passed index which begins with the passed string
//
// searches for a match beginning at the passed Index. if a match is not
// found after the last string has been compared, the search continues
// from the beginning of the list until a match is found or until the list
// has been completely traversed
//
// searches from beginning of list when -1 is passed as the index
//
// returns the index of the selected string. a negative value is returned
// if an error occurs
//
// only for single-selection list boxes
//
int
TListBox::SetSelString(const char far* findStr, int indexStart)
{
  if (!(GetWindowLong(GWL_STYLE) & MULTIPLESEL))
    return (int)HandleMessage(LB_SELECTSTRING, indexStart, (LPARAM)findStr);
  return -1;
}

//
// selects the strings in the associated list box which begin with
// the passed prefixes
//
// for each string the search begins at the beginning of the list
// and continues until a match is found or until the list has been
// completely traversed
//
// if ShouldSet is TRUE, the matched strings are selected and highlighted;
// otherwise the highlight is removed from the matched strings and they
// are no longer selected
//
// returns the number of strings successfully selected or deselected
//
// if NumSelections is less than zero, all strings are selected or deselected
// and a negative value is returned on failure
//
// only for multiple-selection list boxes (-1 is returned if this is not
// a multiple-selection list box)
//
int
TListBox::SetSelStrings(const char far** strs, int numSelections, BOOL shouldSet)
{
  if (!(GetWindowLong(GWL_STYLE) & MULTIPLESEL))
    return -1;

  if (numSelections < 0)
    return SetSel(-1, shouldSet);

  int  successes = 0;
  for (int i = 0; i < numSelections; i++) {
    int  selIndex;
    if ((selIndex = FindString(strs[i], -1)) > -1)
      if (SetSel(selIndex, shouldSet) > -1)
        successes++;
  }
  return successes;
}

//
// returns the index of the selected string in the associated listbox
//
// a negative value is returned if no string is selected or this
// is a multiple-selection list box
//
// only for single-selection list boxes
//
int
TListBox::GetSelIndex() const
{
  if (!(GetWindowLong(GWL_STYLE) & MULTIPLESEL))
    return (int)CONST_CAST(TListBox*,this)->HandleMessage(LB_GETCURSEL);
  return -1;
}

//
// fills indexes with the indexes of up to maxCount selected strings
//
// returns number of items put in the array(-1 for single-selection
// list boxes)
//
int
TListBox::GetSelIndexes(int* indexes, int maxCount) const
{
  if (!(GetWindowLong(GWL_STYLE) & MULTIPLESEL))
    return -1;
  return (int)CONST_CAST(TListBox*,this)->HandleMessage(LB_GETSELITEMS,
                                                        maxCount,
                                                        (LPARAM)indexes);
}

// selects the string at passed index in the associated listbox and
// forces the string into view
//
// clears selection when -1 is passed as the index. a negative value is
// returned if an error occurs
//
// only for single-selection list boxes
//
int
TListBox::SetSelIndex(int index)
{
  if (!(GetWindowLong(GWL_STYLE) & MULTIPLESEL))
    return (int)HandleMessage(LB_SETCURSEL, index);
  return -1;
}

//
// selects/deselects the strings in the associated list box at the
// passed indexes
//
// if ShouldSet is TRUE, the indexed strings are selected and highlighted;
// otherwise the highlight is removed and they are no longer selected
//
// returns the number of strings successfully selected or deselected(-1
// if not a multiple-selection list box)
//
// if NumSelections is less than zero, all strings are selected or deselected
// and a negative value is returned on failure
//
// only for multiple-selection list boxes
//
int
TListBox::SetSelIndexes(int* indexes, int numSelections, BOOL shouldSet)
{
  int  successes = 0;

  if (!(GetWindowLong(GWL_STYLE) & MULTIPLESEL))
    return -1;  // including if it's a combobox

  if (numSelections < 0)
    return (int)HandleMessage(LB_SETSEL, shouldSet, -1);

  else {
    for (int i = 0; i < numSelections; i++)
      if ((int)HandleMessage(LB_SETSEL, shouldSet, indexes[i]) > -1)
        successes++;
  }
  return successes;
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE1(TListBox, TControl);

//
// reads an instance of TListBox from the supplied ipstream
//
void*
TListBox::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TControl*)GetObject(), is);
  return GetObject();
}

//
// writes the TListBox to the supplied opstream
//
void
TListBox::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TControl*)GetObject(), os);
}

#endif

