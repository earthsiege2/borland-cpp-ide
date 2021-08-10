//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   include\owl\combobox.h
//   Defines class TComboBox and TComboBoxData.  This defines the basic
//   behavior of all combo box controls.
//----------------------------------------------------------------------------
#if !defined(__OWL_COMBOBOX_H)
#define __OWL_COMBOBOX_H

#if !defined(__OWL_LISTBOX_H)
  #include <owl\listbox.h>
#endif

//
//  class TComboBox
//  ----- ---------
//
class _OWLCLASS TComboBox : public TListBox {
  public:
    UINT  TextLen;

    TComboBox(TWindow*        parent,
              int             id,
              int x, int y, int w, int h,
              DWORD           style,
              UINT            textLen,
              TModule*        module = 0);

    TComboBox(TWindow*   parent,
              int        resourceId,
              UINT       textLen = 0,
              TModule*   module = 0);

    //
    // for combo box's edit control
    //
    int           GetTextLen() const {return GetWindowTextLength();}
    int           GetText(char far* str, int maxChars) const;  // num of chars copied
    void          SetText(const char far* str);

    int           GetEditSel(int& startPos, int& endPos);
    int           SetEditSel(int startPos, int endPos);  //CB_ERR if no edit control

    void          Clear();  // clear the text

    //
    // for drop down combo boxes
    //
    void          ShowList(BOOL show);
    void          ShowList() {ShowList(TRUE);}
    void          HideList() {ShowList(FALSE);}

    void          GetDroppedControlRect(TRect& Rect) const;
    BOOL          GetDroppedState() const;
    BOOL          GetExtendedUI() const;
    int           SetExtendedUI(BOOL Extended);

    //
    // Combo's List box virtual functions
    //
    virtual int   AddString(const char far* str);
    virtual int   InsertString(const char far* str, int index);
    virtual int   DeleteString(int index);

    virtual void  ClearList();
    virtual int   DirectoryList(UINT attrs, const char far* fileSpec);

    virtual int   GetCount() const;
    virtual int   FindString(const char far* find, int indexStart) const;

    virtual int   GetStringLen(int index) const;
    virtual int   GetString(char far* str, int index) const;

    virtual int   GetSelIndex() const;
    virtual int   SetSelIndex(int index);
    virtual int   SetSelString(const char far* findStr, int indexStart);
    virtual DWORD GetItemData(int index) const;
    virtual int   SetItemData(int index, DWORD itemData);

    int           GetItemHeight(int index) const;
    int           SetItemHeight(int index, int height);

    //
    // Override TWindow virtual member functions
    //
    UINT          Transfer(void* buffer, TTransferDirection direction);

  protected:
    //
    // Override TWindow virtual member functions
    //
    char far*     GetClassName();
    void          SetupWindow();

    //
    // message response functions
    //

  private:
    //
    // hidden to prevent accidental copying or assignment
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

    TStringArray&   GetStrings() {return Strings;}
    TDwordArray&    GetItemDatas() {return ItemDatas;}
    int             GetSelIndex() {return SelIndex;}
    string&         GetSelection() {return Selection;}

    void    AddString(const char* str, BOOL isSelected = FALSE);
    void    AddStringItem(const char* str, DWORD itemData, BOOL isSelected = FALSE);
    void    Clear() {Strings.Flush(); ItemDatas.Flush(); ResetSelections();}

    void    Select(int index);
    void    SelectString(const char far* str);
    int     GetSelCount() const {return SelIndex == CB_ERR ? 0 : 1;}
    void    ResetSelections() {SelIndex = CB_ERR;  Selection = "";}
    int     GetSelStringLength() const;
    void    GetSelString(char far* buffer, int bufferSize) const;

  protected:
    TStringArray   Strings;
    TDwordArray    ItemDatas;
    string         Selection;
    int            SelIndex;
};

//----------------------------------------------------------------------------
// Inlines for class TComboBox
//----------------------------------------------------------------------------

inline void TComboBox::Clear() {SetText(0);}

inline int TComboBox::GetText(char far* str, int maxChars) const {
  return GetWindowText(str, maxChars);
}

inline int TComboBox::SetEditSel(int startPos, int endPos) {
  return (int)HandleMessage(CB_SETEDITSEL, 0, MAKELPARAM(startPos, endPos));
}

inline void TComboBox::GetDroppedControlRect(TRect& rect) const {
  CONST_CAST(TComboBox*,this)->
    HandleMessage(CB_GETDROPPEDCONTROLRECT, 0, (LPARAM)(TRect FAR*)&rect);
}

inline BOOL TComboBox::GetDroppedState() const {
  return (BOOL)CONST_CAST(TComboBox*,this)->HandleMessage(CB_GETDROPPEDSTATE);
}

inline BOOL TComboBox::GetExtendedUI() const {
  return (BOOL)CONST_CAST(TComboBox*,this)->HandleMessage(CB_GETEXTENDEDUI);
}

inline int TComboBox::SetExtendedUI(BOOL extended) {
  return (BOOL)HandleMessage(CB_SETEXTENDEDUI, extended);
}

//
// Adds a string to the list part of the associated combobox
// Returns index of the string in the list(the first entry is at index 0)
// A negative value is returned if an error occurs
//
inline int TComboBox::AddString(const char far* str) {
  return (int)HandleMessage(CB_ADDSTRING, 0, (LPARAM)str);
}

//
// Inserts a string in list part of the associated combobox at the passed
// index, returning the index of the string in the list
// A negative value is returned if an error occurs
//
inline int TComboBox::InsertString(const char far* str, int index) {
  return (int)HandleMessage(CB_INSERTSTRING, index, (LPARAM)str);
}

//
// Deletes the string at the passed index in the list part of the associated combobox
// Returns a count of the entries remaining in the list; A negative
// value is returned if an error occurs
//
inline int TComboBox::DeleteString(int index) {
  return (int)HandleMessage(CB_DELETESTRING, index);
}

inline int TComboBox::DirectoryList(UINT attrs, const char far* fileSpec) {
  return (int)HandleMessage(CB_DIR, attrs,(LPARAM)fileSpec);
}

//
// Clears all the entries in list part of the associated combobox
//
inline void TComboBox::ClearList() {
  HandleMessage(CB_RESETCONTENT);
}

//
// Returns the number of entries in list part of the associated combobox. a negative
// value is returned if an error occurs
//
inline int TComboBox::GetCount() const {
  return (int)CONST_CAST(TComboBox*,this)->HandleMessage(CB_GETCOUNT);
}

//
// Returns the index of the first string in list part of the associated combobox which
// begins with the passed string
//
// Searches for a match beginning at the passed SearchIndex. If a match is
// not found after the last string has been compared, the search continues
// from the beginning of the list until a match is found or until the list
// has been completely traversed
//
// Searches from beginning of list when -1 is passed as the index
//
// Returns the index of the selected string.  A negative value is returned
// if an error occurs
//
inline int TComboBox::FindString(const char far* find, int indexStart) const {
  return (int)CONST_CAST(TComboBox*,this)->
           HandleMessage(CB_FINDSTRING, indexStart,(LPARAM)find);
}

//
// Retrieves the contents of the string at the passed index of list part of
// the associated combobox, returning the length of the string (in bytes
// excluding the terminating 0) as the value of the call
//
// A negative value is returned if the passed index is not valid
//
// The buffer must be large enough for the string and the terminating
// 0
//
inline int TComboBox::GetString(char far* str, int index) const {
  return (int)CONST_CAST(TComboBox*,this)->
           HandleMessage(CB_GETLBTEXT, index, (LPARAM)str);
}

//
// Returns the length of the string at the passed index in the
// associated combo list excluding the terminating 0
//
// A negative value is returned if an error occurs
//
inline int TComboBox::GetStringLen(int index) const {
  return (int)CONST_CAST(TComboBox*,this)->
           HandleMessage(CB_GETLBTEXTLEN, index);
}

inline int TComboBox::GetSelIndex() const {
  return (int)CONST_CAST(TComboBox*,this)->HandleMessage(CB_GETCURSEL);
}

inline int TComboBox::SetSelIndex(int index) {
  return (int)HandleMessage(CB_SETCURSEL, index);
}

inline int TComboBox::SetSelString(const char far* findStr, int indexStart) {
  return (int)HandleMessage(CB_SELECTSTRING, indexStart, (LPARAM)findStr);
}

inline DWORD TComboBox::GetItemData(int index) const {
  return CONST_CAST(TComboBox*,this)->HandleMessage(CB_GETITEMDATA, index);
}

inline int TComboBox::SetItemData(int index, DWORD itemData) {
  return (int)HandleMessage(CB_SETITEMDATA, index, itemData);
}

inline int TComboBox::GetItemHeight(int index) const {
  return (int)CONST_CAST(TComboBox*,this)->
           HandleMessage(CB_GETITEMHEIGHT, index);
}

inline int TComboBox::SetItemHeight(int index, int height) {
  return (int)HandleMessage(CB_GETITEMHEIGHT, index, MAKELPARAM(height,0));
}

#endif  // __OWL_COMBOBOX_H
