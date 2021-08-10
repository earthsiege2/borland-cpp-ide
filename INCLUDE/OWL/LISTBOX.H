//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.4  $
//
// Definition of class TListBox and TlistBoxData.  This defines the basic
// behavior of all list box controls.
//----------------------------------------------------------------------------
#if !defined(OWL_LISTBOX_H)
#define OWL_LISTBOX_H

#if !defined(OWL_CONTROL_H)
# include <owl/control.h>
#endif
#if !defined(OWL_CONTAIN_H)
# include <owl/contain.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the
// definition of classes
#include <services/preclass.h>

//
// class TListBox
// ~~~~~ ~~~~~~~~
class _OWLCLASS TListBox : public TControl {
  public:
    TListBox(TWindow*        parent,
             int             id,
             int x, int y, int w, int h,
             TModule*        module = 0);

    TListBox(TWindow* parent, int resourceId, TModule*   module = 0);

    // List box attributes
    //
    virtual int   GetCount() const;
    virtual int   FindString(const char far* str, int index) const;
    int           FindExactString(const char far* str, int searchIndex) const;
    virtual int   GetTopIndex() const;
    virtual int   SetTopIndex(int index);
    bool          SetTabStops(int numTabs, int far* tabs);

    virtual int   GetHorizontalExtent() const;
    virtual void  SetHorizontalExtent(int horzExtent);
    void          SetColumnWidth(int width);
    int           GetCaretIndex() const;
    int           SetCaretIndex(int index, bool partScrollOk);

    // Query individual list items
    //
    virtual int   GetStringLen(int index) const;
    virtual int   GetString(char far* str, int index) const;
    virtual uint32 GetItemData(int index) const;
    virtual int   SetItemData(int index, uint32 itemData);

    int           GetItemRect(int index, TRect& rect) const;
    virtual int   GetItemHeight(int index) const;
    virtual int   SetItemHeight(int index, int height);

    // Operations on the list box itself
    //
    virtual void  ClearList();
    virtual int   DirectoryList(uint attrs, const char far* fileSpec);

    // Operations on individual list box items
    //
    virtual int   AddString(const char far* str);
    virtual int   InsertString(const char far* str, int index);
    virtual int   DeleteString(int index);

    // Single selection list boxes only (combos overload these)
    //
    virtual int   GetSelIndex() const;
    virtual int   SetSelIndex(int index);
            int   GetSelString(char far* str, int maxChars) const;
            int   SetSelString(const char far* str, int searchIndex);

    // Multiple selection list boxes only
    //
    int           GetSelCount() const;
    int           GetSelStrings(char far** strs, int maxCount,
                                int maxChars) const;
    int           SetSelStrings(const char far** prefixes, int numSelections,
                                bool shouldSet);
    int           GetSelIndexes(int* indexes, int maxCount) const;
    int           SetSelIndexes(int* indexes, int numSelections, bool shouldSet);
    bool          GetSel(int index) const;
    int           SetSel(int index, bool select);
    int           SetSelItemRange(bool select, int first, int last);

#if defined(BI_PLAT_WIN32)
    uint32        ItemFromPoint(TPoint& p);
#endif

    // Override TWindow virtual member functions
    //
    uint          Transfer(void* buffer, TTransferDirection direction);

  protected:
    // Override TWindow virtual member functions
    //
    char far*     GetClassName();

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TListBox(const TListBox&);
    TListBox& operator =(const TListBox&);

  DECLARE_STREAMABLE(_OWLCLASS, TListBox, 1);
};

//
// List box notification macros. methods are: void method()
//
// EV_LBN_DBLCLK(id, method)
// EV_LBN_ERRSPACE(id, method)
// EV_LBN_KILLFOCUS(id, method)
// EV_LBN_SELCANCEL(id, method)
// EV_LBN_SELCHANGE(id, method)
// EV_LBN_SETFOCUS(id, method)

//
// class TListBoxData
// ~~~~~ ~~~~~~~~~~~~
class _OWLCLASS TListBoxData {
  public:
    TListBoxData();
   ~TListBoxData();

    TStringArray&   GetStrings();
    TUint32Array&   GetItemDatas();
    TIntArray&      GetSelIndices();

    void    AddString(const char* str, bool isSelected = false);
    void    AddStringItem(const char* str, uint32 itemData, bool isSelected = false);
    void    Clear();

    void    Select(int index);
    void    SelectString(const char far* str);
    int     GetSelCount() const;
    void    ResetSelections();
    int     GetSelStringLength(int index = 0) const;
    void    GetSelString(char far* buffer, int bufferSize, int index=0) const;
    void    GetSelString(string& str, int index=0) const;

  protected_data:
    TStringArray  Strings;     // Contains all strings in listbox
    TUint32Array  ItemDatas;   // Contains all uint32 item datas in listbox
    TIntArray     SelIndices;  // Contains all selection indices
};

// Generic definitions/compiler options (eg. alignment) following the
// definition of classes
#include <services/posclass.h>

// --------------------------------------------------------------------------
// Inline implementations
//

//
inline int TListBox::GetTopIndex() const {
  PRECONDITION(GetHandle());
  return (int)CONST_CAST(TListBox*,this)->SendMessage(LB_GETTOPINDEX);
}

//
inline int TListBox::SetTopIndex(int index) {
  PRECONDITION(GetHandle());
  return (int)SendMessage(LB_SETTOPINDEX, index);
}

//
inline bool TListBox::SetTabStops(int numTabs, int far* tabs) {
  PRECONDITION(GetHandle());
  return (bool)SendMessage(LB_SETTABSTOPS, numTabs, TParam2(tabs));
}

//
inline int TListBox::GetHorizontalExtent() const {
  PRECONDITION(GetHandle());
  return (int)CONST_CAST(TListBox*,this)->SendMessage(LB_GETHORIZONTALEXTENT);
}

//
inline void TListBox::SetHorizontalExtent(int horzExtent) {
  PRECONDITION(GetHandle());
  SendMessage(LB_SETHORIZONTALEXTENT, horzExtent);
}

//
inline void TListBox::SetColumnWidth(int width) {
  PRECONDITION(GetHandle());
  SendMessage(LB_SETCOLUMNWIDTH, width);
}

//
inline int TListBox::GetCaretIndex() const {
  PRECONDITION(GetHandle());
  return (int)CONST_CAST(TListBox*,this)->SendMessage(LB_GETCARETINDEX);
}

//
inline int TListBox::SetCaretIndex(int index, bool partScrollOk) {
  PRECONDITION(GetHandle());
  return (int)SendMessage(LB_SETCARETINDEX, index, MkParam2(partScrollOk,0));
}

//
inline uint32 TListBox::GetItemData(int index) const {
  PRECONDITION(GetHandle());
  return CONST_CAST(TListBox*,this)->SendMessage(LB_GETITEMDATA, index);
}

//
inline int TListBox::SetItemData(int index, uint32 itemData) {
  PRECONDITION(GetHandle());
  return (int)SendMessage(LB_SETITEMDATA, index, itemData);
}

//
inline int TListBox::GetItemRect(int index, TRect& rect) const {
  PRECONDITION(GetHandle());
  return (int)CONST_CAST(TListBox*,this)->
           SendMessage(LB_GETITEMRECT, index, TParam2((TRect FAR*)&rect));
}

//
inline int TListBox::GetItemHeight(int index) const {
  PRECONDITION(GetHandle());
  return (int)CONST_CAST(TListBox*,this)->
           SendMessage(LB_GETITEMHEIGHT, index);
}

//
inline int TListBox::SetItemHeight(int index, int height) {
  PRECONDITION(GetHandle());
  return (int)SendMessage(LB_SETITEMHEIGHT, index, MkParam2(height, 0));
}

//
inline int TListBox::DirectoryList(uint attrs, const char far* fileSpec) {
  PRECONDITION(GetHandle());
  return (int)SendMessage(LB_DIR, attrs, TParam2(fileSpec));
}

//
// Adds a string to an associated listbox
// Returns index of the string in the list(the first entry is at index 0),
// a negative if an error occurs.
//
inline int TListBox::AddString(const char far* str) {
  PRECONDITION(GetHandle());
  return (int)SendMessage(LB_ADDSTRING, 0, TParam2(str));
}

//
// Inserts a string in the associated listbox at the passed index,
// returns the index of the string in the list, a negative if an error occurs
//
inline int TListBox::InsertString(const char far* str, int index) {
  PRECONDITION(GetHandle());
  return (int)SendMessage(LB_INSERTSTRING, index, TParam2(str));
}

//
// Deletes the string at the passed index in the associated listbox
// Returns a count of the entries remaining in the list, a negative
// value if an error occurs
//
inline int TListBox::DeleteString(int index) {
  PRECONDITION(GetHandle());
  return (int)SendMessage(LB_DELETESTRING, index);
}

//
// Clears all the entries in the associated listbox
//
inline void TListBox::ClearList() {
  PRECONDITION(GetHandle());
  SendMessage(LB_RESETCONTENT);
}

//
// Returns the number of entries in the associated listbox, a negative
// value if an error occurs
//
//
inline int TListBox::GetCount() const {
  PRECONDITION(GetHandle());
  return (int)CONST_CAST(TListBox*,this)->SendMessage(LB_GETCOUNT);
}

//
// Returns the index of the first string in the associated listbox which
// begins with the passed string
//
// Searches for a match beginning at the passed SearchIndex. If a match is
// not found after the last string has been compared, the search continues
// from the beginning of the list until a match is found or until the list
// has been completely traversed
//
// Searches from beginning of list when -1 is passed as the index
//
// Returns the index of the selected string, a negative if an error occurs
//
inline int TListBox::FindString(const char far* find, int indexStart) const {
  PRECONDITION(GetHandle());
  return (int)CONST_CAST(TListBox*,this)->
           SendMessage(LB_FINDSTRING, indexStart, TParam2(find));
}

//
// Retrieves the contents of the string at the passed index of the
// associated listbox. Returns the length of the string (in bytes
// excluding the terminating 0),  a negative if the passed index is not valid
//
// The buffer must be large enough for the string and the terminating 0
//
inline int TListBox::GetString(char far* str, int index) const {
  PRECONDITION(GetHandle());
  return (int)CONST_CAST(TListBox*,this)->
           SendMessage(LB_GETTEXT, index, TParam2(str));
}

//
// Returns the length of the string at the passed index in the associated
// listbox excluding the terminating 0, a negative if an error occurs
//
inline int TListBox::GetStringLen(int index) const {
  PRECONDITION(GetHandle());
  return (int)CONST_CAST(TListBox*,this)->SendMessage(LB_GETTEXTLEN, index);
}

//
// Get the selection state (true/false) of a particular item at 'index'
//
inline bool TListBox::GetSel(int index) const {
  PRECONDITION(GetHandle());
  return (bool)CONST_CAST(TListBox*,this)->SendMessage(LB_GETSEL, index);
}

//
// Set the selection state (true/false) of a particular item at 'index',
// or all items if index is -1
//
//
inline int TListBox::SetSel(int index, bool select) {
  PRECONDITION(GetHandle());
  return (int)SendMessage(LB_SETSEL, select, MkParam2(index, 0));
}

//
inline int TListBox::SetSelItemRange(bool select, int first, int last) {
  PRECONDITION(GetHandle());
  return (int)SendMessage(LB_SELITEMRANGE, select, MkParam2(first, last));
}

#if defined(BI_PLAT_WIN32)
//
inline uint32 TListBox::ItemFromPoint(TPoint& p)
{
  PRECONDITION(GetHandle());
  return (uint32)SendMessage(LB_ITEMFROMPOINT, 0, MkParam2(p.x, p.y));
}
#endif

//
inline TStringArray& TListBoxData::GetStrings() {
  return Strings;
}

//
inline TUint32Array& TListBoxData::GetItemDatas() {
  return ItemDatas;
}

//
inline TIntArray& TListBoxData::GetSelIndices() {
  return SelIndices;
}

//
inline void TListBoxData::Clear() {
  Strings.Flush();
  ItemDatas.Flush();
  ResetSelections();
}

//
inline int TListBoxData::GetSelCount() const {
  return SelIndices.GetItemsInContainer();
}

//
inline void TListBoxData::ResetSelections() {
  SelIndices.Flush();
}

#endif  // OWL_LISTBOX_H
