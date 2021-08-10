//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   include\owl\listbox.h
//   Definition of class TListBox and TlistBoxData.  This defines the
//   basic behavior of all list box controls.
//----------------------------------------------------------------------------
#if !defined(__OWL_LISTBOX_H)
#define __OWL_LISTBOX_H

#if !defined(__OWL_CONTROL_H)
  #include <owl\control.h>
#endif
#if !defined(__CLASSLIB_ARRAYS_H)
  #include <classlib\arrays.h>
#endif

//
//  class TListBox
//  ----- --------
//
class _OWLCLASS TListBox : public TControl {
  public:
    TListBox(TWindow*        parent,
             int             id,
             int x, int y, int w, int h,
             TModule*        module = 0);

    TListBox(TWindow* parent, int resourceId, TModule*   module = 0);

    //
    // list box attributes
    //
    virtual int   GetCount() const;
    virtual int   FindString(const char far* str, int index) const;
    int           FindExactString(const char far* str, int searchIndex) const;
    int           GetTopIndex() const;
    int           SetTopIndex(int index);
    BOOL          SetTabStops(int numTabs, int far* tabs);

    int           GetHorizontalExtent() const;
    void          SetHorizontalExtent(int horzExtent);
    void          SetColumnWidth(int width);
    int           GetCaretIndex() const;
    int           SetCaretIndex(int index, BOOL partScrollOk);

    //
    // query individual list items
    //
    virtual int   GetStringLen(int index) const;
    virtual int   GetString(char far* str, int index) const;
    virtual DWORD GetItemData(int index) const;
    virtual int   SetItemData(int index, DWORD itemData);

    int           GetItemRect(int index, TRect& rect) const;
    virtual int   GetItemHeight(int index) const;
    virtual int   SetItemHeight(int index, int height);

    //
    // operations on the list box itself
    //
    virtual void  ClearList();
    virtual int   DirectoryList(UINT attrs, const char far* fileSpec);

    //
    // operations on individual list box items
    //
    virtual int   AddString(const char far* str);
    virtual int   InsertString(const char far* str, int index);
    virtual int   DeleteString(int index);

    //
    // single selection list boxes only (combos overload these)
    //
    virtual int   GetSelIndex() const;
    virtual int   SetSelIndex(int index);
            int   GetSelString(char far* str, int maxChars) const;
            int   SetSelString(const char far* str, int searchIndex);

    //
    // multiple selection list boxes only
    //
    int           GetSelCount() const;
    int           GetSelStrings(char far** strs, int maxCount,
                                int maxChars) const;
    int           SetSelStrings(const char far** prefixes, int numSelections,
                                BOOL shouldSet);
    int           GetSelIndexes(int* indexes, int maxCount) const;
    int           SetSelIndexes(int* indexes, int numSelections, BOOL shouldSet);
    BOOL          GetSel(int index) const;
    int           SetSel(int index, BOOL select);
    int           SetSelItemRange(BOOL select, int first, int last);

    //
    // Override TWindow virtual member functions
    //
    UINT          Transfer(void *buffer, TTransferDirection direction);

  protected:
    //
    // Override TWindow virtual member functions
    //
    char far     *GetClassName();

  private:
    //
    // hidden to prevent accidental copying or assignment
    //
    TListBox(const TListBox&);
    TListBox& operator =(const TListBox&);

  DECLARE_STREAMABLE(_OWLCLASS, TListBox, 1);
};

//
// list box notification macros. methods are: void method()
//
// EV_LBN_DBLCLK(id, method)
// EV_LBN_ERRSPACE(id, method)
// EV_LBN_KILLFOCUS(id, method)
// EV_LBN_SELCANCEL(id, method)
// EV_LBN_SELCHANGE(id, method)
// EV_LBN_SETFOCUS(id, method)

//
//  Container classes
//  --------- -------
//

class _OWLCLASS TStringArray
{
  public:
    typedef void (*IterFunc)(string &, void *);
    typedef int  (*CondFunc)(const string &, void *);

    TStringArray( int upper, int lower, int delta );
    int LowerBound() const;
    int UpperBound() const;
    unsigned ArraySize() const;
    int IsFull() const;
    int IsEmpty() const;
    unsigned GetItemsInContainer() const;
    int Add( const string & t );
    int Detach( const string & t );
    int Detach( int loc );
    int Destroy( const string & t );
    int Destroy( int loc );
    int HasMember( const string & t ) const;
    int Find( const string & t ) const;
    string & operator []( int loc );
    string & operator []( int loc ) const;
    void ForEach( IterFunc iter, void *args );
    string *FirstThat( CondFunc cond, void *args ) const;
    string *LastThat( CondFunc cond, void *args ) const;
    void Flush();

  private:
    TArrayAsVector<string> Data;

  friend class TStringArrayIterator;
};

class TStringArrayIterator : public TArrayAsVectorIterator<string> {
  public:
    TStringArrayIterator(const TStringArray& array)
        : TArrayAsVectorIterator<string>(array.Data) {}
};

struct TInt {
  int i;
  TInt() {}
  TInt(int _i) {i = _i;}
  operator int() const {return i;}
};

class _OWLCLASS TIntArray
{
  public:
    typedef void (*IterFunc)(TInt &, void *);
    typedef int  (*CondFunc)(const TInt &, void *);

    TIntArray( int upper, int lower, int delta );
    int LowerBound() const;
    int UpperBound() const;
    unsigned ArraySize() const;
    int IsFull() const;
    int IsEmpty() const;
    unsigned GetItemsInContainer() const;
    int Add( const TInt & t );
    int Detach( const TInt & t );
    int Detach( int loc );
    int Destroy( const TInt & t );
    int Destroy( int loc );
    int HasMember( const TInt & t ) const;
    int Find( const TInt & t ) const;
    TInt & operator []( int loc );
    TInt & operator []( int loc ) const;
    void ForEach( IterFunc iter, void *args );
    TInt *FirstThat( CondFunc cond, void *args ) const;
    TInt *LastThat( CondFunc cond, void *args ) const;
    void Flush();

  private:
    TArrayAsVector<TInt> Data;

  friend class TIntArrayIterator;
};

class TIntArrayIterator : public TArrayAsVectorIterator<TInt> {
  public:
    TIntArrayIterator(const TIntArray& array)
        : TArrayAsVectorIterator<TInt>(array.Data) {}
};

class _OWLCLASS TDwordArray
{
  public:
    typedef void (*IterFunc)(DWORD &, void *);
    typedef int  (*CondFunc)(const DWORD &, void *);

    TDwordArray( int upper, int lower, int delta );
    int LowerBound() const;
    int UpperBound() const;
    unsigned ArraySize() const;
    int IsFull() const;
    int IsEmpty() const;
    unsigned GetItemsInContainer() const;
    int Add( const DWORD & t );
    int Detach( const DWORD & t );
    int Detach( int loc );
    int Destroy( const DWORD & t );
    int Destroy( int loc );
    int HasMember( const DWORD & t ) const;
    int Find( const DWORD & t ) const;
    DWORD & operator []( int loc );
    DWORD & operator []( int loc ) const;
    void ForEach( IterFunc iter, void *args );
    DWORD *FirstThat( CondFunc cond, void *args ) const;
    DWORD *LastThat( CondFunc cond, void *args ) const;
    void Flush();

  private:
    TArrayAsVector<DWORD> Data;

  friend class TDwordArrayIterator;
};

class TDwordArrayIterator : public TArrayAsVectorIterator<DWORD> {
  public:
    TDwordArrayIterator(const TDwordArray& array)
        : TArrayAsVectorIterator<DWORD>(array.Data) {}
};

//
//  class TListBoxData
//  ----- ------------
//
class _OWLCLASS TListBoxData {
  public:
    TListBoxData();
   ~TListBoxData();

    TStringArray&   GetStrings() {return Strings;}
    TDwordArray&    GetItemDatas() {return ItemDatas;}
    TIntArray&      GetSelIndices() {return SelIndices;}

    void    AddString(const char* str, BOOL isSelected = FALSE);
    void    AddStringItem(const char* str, DWORD itemData, BOOL isSelected = FALSE);
    void    Clear() {Strings.Flush(); ItemDatas.Flush(); ResetSelections();}

    void    Select(int index);
    void    SelectString(const char far* str);
    int     GetSelCount() const {return SelIndices.GetItemsInContainer();}
    void    ResetSelections() {SelIndices.Flush();}
    int     GetSelStringLength(int index = 0) const;
    void    GetSelString(char far* buffer, int bufferSize, int index=0) const;
    void    GetSelString(string& str, int index=0) const;

  protected:
    TStringArray  Strings;     // Contains all strings in listbox
    TDwordArray   ItemDatas;   // Contains all item data uint32 in listbox
    TIntArray     SelIndices;  // Contains all selection indices
};


//----------------------------------------------------------------------------
// Inlines
//----------------------------------------------------------------------------

inline int TListBox::GetTopIndex() const {
  return (int)CONST_CAST(TListBox*,this)->HandleMessage(LB_GETTOPINDEX);
}

inline int TListBox::SetTopIndex(int index) {
  return (int)HandleMessage(LB_SETTOPINDEX, index);
}

inline BOOL TListBox::SetTabStops(int numTabs, int far* tabs) {
  return (BOOL)HandleMessage(LB_SETTABSTOPS, numTabs, (LPARAM)tabs);
}

inline int TListBox::GetHorizontalExtent() const {
  return (int)CONST_CAST(TListBox*,this)->HandleMessage(LB_GETHORIZONTALEXTENT);
}

inline void TListBox::SetHorizontalExtent(int horzExtent) {
  HandleMessage(LB_SETHORIZONTALEXTENT, horzExtent);
}

inline void TListBox::SetColumnWidth(int width) {
  HandleMessage(LB_SETCOLUMNWIDTH, width);
}

inline int TListBox::GetCaretIndex() const {
  return (int)CONST_CAST(TListBox*,this)->HandleMessage(LB_GETCARETINDEX);
}

inline int TListBox::SetCaretIndex(int index, BOOL partScrollOk) {
  return (int)HandleMessage(LB_SETCARETINDEX, index, MAKELPARAM(partScrollOk,0));
}

inline DWORD TListBox::GetItemData(int index) const {
  return CONST_CAST(TListBox*,this)->HandleMessage(LB_GETITEMDATA, index);
}

inline int TListBox::SetItemData(int index, DWORD itemData) {
  return (int)HandleMessage(LB_SETITEMDATA, index, itemData);
}

inline int TListBox::GetItemRect(int index, TRect& rect) const {
  return (int)CONST_CAST(TListBox*,this)->
           HandleMessage(LB_GETITEMRECT, index, (LPARAM)(TRect FAR*)&rect);
}

inline int TListBox::GetItemHeight(int index) const {
  return (int)CONST_CAST(TListBox*,this)->
           HandleMessage(LB_GETITEMHEIGHT, index);
}

inline int TListBox::SetItemHeight(int index, int height) {
  return (int)HandleMessage(LB_SETITEMHEIGHT, index, MAKELPARAM(height, 0));
}

inline int TListBox::DirectoryList(UINT attrs, const char far* fileSpec) {
  return (int)HandleMessage(LB_DIR, attrs, (LPARAM)fileSpec);
}

// Adds a string to an associated listbox
// Returns index of the string in the list(the first entry is at index 0),
// a negative if an error occurs.
//
inline int TListBox::AddString(const char far* str) {
  return (int)HandleMessage(LB_ADDSTRING, 0, (LPARAM)str);
}

// Inserts a string in the associated listbox at the passed index,
// returns the index of the string in the list, a negative if an error occurs
//
inline int TListBox::InsertString(const char far* str, int index) {
  return (int)HandleMessage(LB_INSERTSTRING, index, (LPARAM)str);
}

// Deletes the string at the passed index in the associated listbox
// Returns a count of the entries remaining in the list, a negative
// value if an error occurs
//
inline int TListBox::DeleteString(int index) {
  return (int)HandleMessage(LB_DELETESTRING, index);
}

// Clears all the entries in the associated listbox
//
inline void TListBox::ClearList() {
  HandleMessage(LB_RESETCONTENT);
}

// Returns the number of entries in the associated listbox, a negative
// value if an error occurs
//
inline int TListBox::GetCount() const {
  return (int)CONST_CAST(TListBox*,this)->HandleMessage(LB_GETCOUNT);
}

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
  return (int)CONST_CAST(TListBox*,this)->
           HandleMessage(LB_FINDSTRING, indexStart, (LPARAM)find);
}

// Retrieves the contents of the string at the passed index of the
// associated listbox. Returns the length of the string (in bytes
// excluding the terminating 0),  a negative if the passed index is not valid
//
// The buffer must be large enough for the string and the terminating 0
//
inline int TListBox::GetString(char far* str, int index) const {
  return (int)CONST_CAST(TListBox*,this)->
           HandleMessage(LB_GETTEXT, index, (LPARAM)str);
}

// Returns the length of the string at the passed index in the associated
// listbox excluding the terminating 0, a negative if an error occurs
//
inline int TListBox::GetStringLen(int index) const {
  return (int)CONST_CAST(TListBox*,this)->HandleMessage(LB_GETTEXTLEN, index);
}

inline int TListBox::SetSel(int index, BOOL select) {
  return (int)HandleMessage(LB_SETSEL, select, MAKELPARAM(index, 0));
}

inline int TListBox::SetSelItemRange(BOOL select, int first, int last) {
  return (int)HandleMessage(LB_SELITEMRANGE, select, MAKELPARAM(first, last));
}

#endif  // __OWL_LISTBOX_H
