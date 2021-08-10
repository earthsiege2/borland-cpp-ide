//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.6  $
//
// Definition of class TComboBox and TComboBoxData the base class for all
// combobox controls.
//----------------------------------------------------------------------------
#if !defined(OWL_COMBOBOX_H)
#define OWL_COMBOBOX_H

#if !defined(OWL_LISTBOX_H)
# include <owl/listbox.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the
// definition of classes
#include <services/preclass.h>

//
// class TComboBox
// ~~~~~ ~~~~~~~~~
class _OWLCLASS TComboBox : public TListBox {
  public:
    TComboBox(TWindow*        parent,
              int             id,
              int x, int y, int w, int h,
              uint32          style,
              uint            textLimit,
              TModule*        module = 0);

    TComboBox(TWindow*   parent,
              int        resourceId,
              uint       textLimit = 0,
              TModule*   module = 0);
   ~TComboBox();

    // For combo box's edit subcontrol
    //
    int           GetTextLen() const;
    int           GetText(char far* str, int maxChars) const;
    void          SetText(const char far* str);

    uint          GetTextLimit();
    void          SetTextLimit(uint textlimit);

    int           GetEditSel(int& startPos, int& endPos);
    int           SetEditSel(int startPos, int endPos);

    void          Clear();

    // For drop down combo boxes
    //
    void          ShowList(bool show = true);
    void          HideList();

    void          GetDroppedControlRect(TRect& Rect) const;
    bool          GetDroppedState() const;
    bool          GetExtendedUI() const;
    int           SetExtendedUI(bool Extended);

    // Combo's List box virtual functions
    //
    virtual int   AddString(const char far* str);
    virtual int   InsertString(const char far* str, int index);
    virtual int   DeleteString(int index);

    virtual void  ClearList();
    virtual int   DirectoryList(uint attrs, const char far* fileSpec);

    virtual int   GetCount() const;
    virtual int   FindString(const char far* find, int indexStart) const;

    virtual int   GetStringLen(int index) const;
    virtual int   GetString(char far* str, int index) const;

    virtual int   GetTopIndex() const;
    virtual int   SetTopIndex(int index);
    virtual int   GetHorizontalExtent() const;
    virtual void  SetHorizontalExtent(int horzExtent);

    virtual int   GetSelIndex() const;
    virtual int   SetSelIndex(int index);
    virtual int   SetSelString(const char far* findStr, int indexStart);
    virtual uint32 GetItemData(int index) const;
    virtual int   SetItemData(int index, uint32 itemData);

    int           GetItemHeight(int index) const;
    int           SetItemHeight(int index, int height);

#if defined(BI_PLAT_WIN32)
    int           InitStorage(int numItemsToAdd, uint32 memoryToAllocate);
#endif

    // Override TWindow virtual member functions
    //
    uint          Transfer(void* buffer, TTransferDirection direction);

  protected:
    // Override TWindow virtual member functions
    //
    char far*     GetClassName();
    void          SetupWindow();
    void          CleanupWindow();

  public_data:
    union {
#if defined(OWL2_COMPAT)
      uint  TextLen;    // Obsolete name--use TextLimit below
#endif
      uint  TextLimit;  // Maximum length of text in edit subcontrol
    };

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TComboBox(const TComboBox&);
    TComboBox& operator =(const TComboBox&);

  DECLARE_STREAMABLE(_OWLCLASS, TComboBox, 1);
};

//
// combo box notification macros. methods are: void method()
//
// EV_CBN_CLOSEUP(id, method)
// EV_CBN_DBLCLK(id, method)
// EV_CBN_DROPDOWN(id, method)
// EV_CBN_EDITCHANGE(id, method)
// EV_CBN_EDITUPDATE(id, method)
// EV_CBN_ERRSPACE(id, method)
// EV_CBN_KILLFOCUS(id, method)
// EV_CBN_SELCHANGE(id, method)
// EV_CBN_SELENDCANCEL(id, method)
// EV_CBN_SELENDOK(id, method)
// EV_CBN_SETFOCUS(id, method)

//
//  class TComboBoxData
//  ----- -------------
//
class _OWLCLASS TComboBoxData {
  public:
    TComboBoxData();
   ~TComboBoxData();

    TStringArray&   GetStrings();
    TDwordArray&    GetItemDatas();
    int             GetSelIndex();
    string&         GetSelection();

    void    AddString(const char* str, bool isSelected = false);
    void    AddStringItem(const char* str, uint32 itemData, bool isSelected = false);
    void    Clear();

    void    Select(int index);
    void    SelectString(const char far* str);
    int     GetSelCount() const;
    void    ResetSelections();
    int     GetSelStringLength() const;
    void    GetSelString(char far* buffer, int bufferSize) const;

  protected:
    TStringArray   Strings;
    TDwordArray    ItemDatas;
    string         Selection;
    int            SelIndex;
};

// Generic definitions/compiler options (eg. alignment) following the
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------
// Inline implementations
//

//
inline int TComboBox::GetTextLen() const {
  PRECONDITION(GetHandle());
  return GetWindowTextLength();
}

//
// Return the limit of new characters that can be entered into the edit
// control portion of the combobox.
//
inline uint TComboBox::GetTextLimit() {
  return TextLimit;
}

//
inline void TComboBox::HideList() {
  ShowList(false);
}

//
// Return number of chars copied
//
inline int TComboBox::GetText(char far* str, int maxChars) const {
  PRECONDITION(GetHandle());
  return GetWindowText(str, maxChars);
}

//
// Return CB_ERR if no edit control
//
inline int TComboBox::SetEditSel(int startPos, int endPos) {
  PRECONDITION(GetHandle());
  return (int)SendMessage(CB_SETEDITSEL, 0, MkParam2(startPos, endPos));
}

//
// Clear the text
//
inline void TComboBox::Clear() {
  SetText(0);
}

//
inline void TComboBox::GetDroppedControlRect(TRect& rect) const {
  PRECONDITION(GetHandle());
  CONST_CAST(TComboBox*,this)->
    SendMessage(CB_GETDROPPEDCONTROLRECT, 0, TParam2((TRect far*)&rect));
}

//
inline bool TComboBox::GetDroppedState() const {
  PRECONDITION(GetHandle());
  return (bool)CONST_CAST(TComboBox*,this)->SendMessage(CB_GETDROPPEDSTATE);
}

//
inline bool TComboBox::GetExtendedUI() const {
  PRECONDITION(GetHandle());
  return (bool)CONST_CAST(TComboBox*,this)->SendMessage(CB_GETEXTENDEDUI);
}

//
inline int TComboBox::SetExtendedUI(bool extended) {
  PRECONDITION(GetHandle());
  return (bool)SendMessage(CB_SETEXTENDEDUI, extended);
}

//
// Add a string to the list part of the associated combobox
// Return index of the string in the list (the first entry is at index 0)
// A negative value is returned if an error occurs
//
inline int TComboBox::AddString(const char far* str) {
  PRECONDITION(GetHandle());
  return (int)SendMessage(CB_ADDSTRING, 0, TParam2(str));
}

//
// Insert a string in list part of the associated combobox at the passed
// index, returning the index of the string in the list
// A negative value is returned if an error occurs
//
inline int TComboBox::InsertString(const char far* str, int index) {
  PRECONDITION(GetHandle());
  return (int)SendMessage(CB_INSERTSTRING, index, TParam2(str));
}

//
// Delete the string at the passed index in the list part of the associated
// combobox
// Return a count of the entries remaining in the list; A negative value is
// returned if an error occurs
//
inline int TComboBox::DeleteString(int index) {
  PRECONDITION(GetHandle());
  return (int)SendMessage(CB_DELETESTRING, index);
}

//
inline int TComboBox::DirectoryList(uint attrs, const char far* fileSpec) {
  PRECONDITION(GetHandle());
  return (int)SendMessage(CB_DIR, attrs, TParam2(fileSpec));
}

//
// Clear all the entries in list part of the associated combobox
//
inline void TComboBox::ClearList() {
  PRECONDITION(GetHandle());
  SendMessage(CB_RESETCONTENT);
}

//
// Return the number of entries in list part of the associated combobox. A
// negative value is returned if an error occurs
//
inline int TComboBox::GetCount() const {
  PRECONDITION(GetHandle());
  return (int)CONST_CAST(TComboBox*,this)->SendMessage(CB_GETCOUNT);
}

//
// Return the index of the first string in list part of the associated
// combobox which begins with the passed string.
//
// Search for a match beginning at the passed SearchIndex. If a match is not
// found after the last string has been compared, the search continues from
// the beginning of the list until a match is found or until the list has been
// completely traversed.
//
// Search from beginning of list when -1 is passed as the index
//
// Return the index of the selected string.  A negative value is returned if an
// error occurs
//
inline int TComboBox::FindString(const char far* find, int indexStart) const {
  PRECONDITION(GetHandle());
  return (int)CONST_CAST(TComboBox*,this)->
           SendMessage(CB_FINDSTRING, indexStart,TParam2(find));
}

//
// Retrieve the contents of the string at the passed index of list part of the
// associated combobox, returning the length of the string (in bytes excluding
// the terminating 0) as the value of the call
//
// A negative value is returned if the passed index is not valid
//
// The buffer must be large enough for the string and the terminating 0
//
inline int TComboBox::GetString(char far* str, int index) const {
  PRECONDITION(GetHandle());
  return (int)CONST_CAST(TComboBox*,this)->
           SendMessage(CB_GETLBTEXT, index, TParam2(str));
}

//
// Return the length of the string at the passed index in the associated combo
// list excluding the terminating 0
//
// A negative value is returned if an error occurs
//
inline int TComboBox::GetStringLen(int index) const {
  PRECONDITION(GetHandle());
  return (int)CONST_CAST(TComboBox*,this)->
           SendMessage(CB_GETLBTEXTLEN, index);
}

//
inline int TComboBox::GetTopIndex() const {
  PRECONDITION(GetHandle());
#if defined(BI_PLAT_WIN32)
  return (int)CONST_CAST(TComboBox*,this)->SendMessage(CB_GETTOPINDEX);
#else
  //
  return -1;
#endif
}

//
inline int TComboBox::SetTopIndex(int index) {
  PRECONDITION(GetHandle());
#if defined(BI_PLAT_WIN32)
  return (int)SendMessage(CB_SETTOPINDEX, index);
#else
  //
  return -1;
#endif
}

//
inline int TComboBox::GetHorizontalExtent() const {
  PRECONDITION(GetHandle());
#if defined(BI_PLAT_WIN32)
  return (int)CONST_CAST(TComboBox*,this)->SendMessage(CB_GETHORIZONTALEXTENT);
#else
  //
  return -1;
#endif
}

//
inline void TComboBox::SetHorizontalExtent(int horzExtent) {
  PRECONDITION(GetHandle());
#if defined(BI_PLAT_WIN32)
  SendMessage(CB_SETHORIZONTALEXTENT);
#else
  //
#endif
}

//
inline int TComboBox::GetSelIndex() const {
  PRECONDITION(GetHandle());
  return (int)CONST_CAST(TComboBox*,this)->SendMessage(CB_GETCURSEL);
}

//
inline int TComboBox::SetSelIndex(int index) {
  PRECONDITION(GetHandle());
  return (int)SendMessage(CB_SETCURSEL, index);
}

//
inline int TComboBox::SetSelString(const char far* findStr, int indexStart) {
  PRECONDITION(GetHandle());
  return (int)SendMessage(CB_SELECTSTRING, indexStart, TParam2(findStr));
}

//
inline uint32 TComboBox::GetItemData(int index) const {
  PRECONDITION(GetHandle());
  return CONST_CAST(TComboBox*,this)->SendMessage(CB_GETITEMDATA, index);
}

//
inline int TComboBox::SetItemData(int index, uint32 itemData) {
  PRECONDITION(GetHandle());
  return (int)SendMessage(CB_SETITEMDATA, index, itemData);
}

//
inline int TComboBox::GetItemHeight(int index) const {
  PRECONDITION(GetHandle());
  return (int)CONST_CAST(TComboBox*,this)->
           SendMessage(CB_GETITEMHEIGHT, index);
}

//
inline int TComboBox::SetItemHeight(int index, int height) {
  PRECONDITION(GetHandle());
  return (int)SendMessage(CB_SETITEMHEIGHT, index, MkParam2(height, 0));
}

#if defined(BI_PLAT_WIN32)
//
inline int TComboBox::InitStorage(int numItemsToAdd, uint32 memoryToAllocate) {
  PRECONDITION(GetHandle());
  return (int)SendMessage(CB_INITSTORAGE, numItemsToAdd, memoryToAllocate);
}
#endif

//
inline TStringArray& TComboBoxData::GetStrings() {
  return Strings;
}

//
inline TDwordArray& TComboBoxData::GetItemDatas() {
  return ItemDatas;
}

//
inline int TComboBoxData::GetSelIndex() {
  return SelIndex;
}

//
inline string& TComboBoxData::GetSelection() {
  return Selection;
}

//
inline void TComboBoxData::Clear() {
  Strings.Flush();
  ItemDatas.Flush();
  ResetSelections();
}

//
inline int TComboBoxData::GetSelCount() const {
  return SelIndex == CB_ERR ? 0 : 1;
}

//
inline void TComboBoxData::ResetSelections() {
  SelIndex = CB_ERR;
  Selection = "";
}

#endif  // OWL_COMBOBOX_H
