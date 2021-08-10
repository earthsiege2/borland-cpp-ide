//---------------------------------------------------------------------
//
//  TODOLIST.H
//
//      Copyright (c) 1991, 1995 by Borland International
//      All Rights Reserved.
//
//  Defines the following classes, used in implementing the Todo list:
//
//      TodoEntry   - holds the data for an entry in the Todo list.
//
//      TodoList    - container for holding Todo entries
//
//      ListBox     - wrapper around the Windows listbox, providing
//                    an interface that fits with the Todo list.
//
//      TodoWindow  - the main window for this application.  There's
//                    nothing displayed in the window except for the
//                    list box.
//
//---------------------------------------------------------------------
#if !defined(TODOLIST_H)
#define TODOLIST_H

#include <winsys/wsysinc.h>
#include <classlib/date.h>
#include <classlib/vectimp.h>
#include <classlib/objstrm.h>
#include <classlib/stdtempl.h>
#include <services/except.h>
#include <services/cstring.h>
#include <iostream.h>
#include <string.h>
#include <dir.h>

#include "todowin.h"

//---------------------------------------------------------------------
//
//  class TodoEntry
//
//      holds the data for an entry in the Todo list.
//
//---------------------------------------------------------------------

class TodoEntry
{

    friend class EditBox;

public:

    TodoEntry();                // constructor.

    BOOL Modified() const;      // indicates whether the entry has
                                // been modified.  Used in determining
                                // whether the list should be saved.

    void Clear();               // marks the entry as saved.

    friend int operator == ( const TodoEntry&, const TodoEntry& );
    friend int operator <  ( const TodoEntry&, const TodoEntry& );

    friend ipstream& operator >> ( ipstream& is, TodoEntry& td );
    friend opstream& operator << ( opstream& os, const TodoEntry& td );

    friend ostream& operator << ( ostream& os, const TodoEntry& tde );

private:

    BOOL Dirty;                 // indicates whether this entry has
                                // been modified.

    TDate DateCreated;
    TDate DateDue;
    string Text;                // the note associated with this entry
    int Priority;

};

//---------------------------------------------------------------------
//
//  class TodoList
//
//      container for holding Todo entries.  Currently implemented as
//      a SortedArray, so we don't have to explicitly sort the entries
//      when a new one is added.  The sorting is done according to the
//      operator < defined for a TodoEntry, which sorts according
//      to the due date.
//
//---------------------------------------------------------------------

class TodoList
{

    friend class ListBox;

public:

    TodoList();

    void Add( const TodoEntry& );
                                // adds an entry to the Todo list.

    void Detach( unsigned idx );
                                // removes an entry from the Todo list.

    TodoEntry& operator [] ( unsigned idx );

    int IndexOf( const TodoEntry& );
                                // returns the index of the specified entry.

    BOOL Modified() const;      // indicates whether the list has
                                // been modified by adding or deleting an
                                // entry.  Used in determining
                                // whether the list should be saved.

    void MarkSaved() const;     // marks that the list has been saved.

    void Clear();               // removes all entries from the list.

    friend ipstream& operator >> ( ipstream& is, TodoList& td );
    friend opstream& operator << ( opstream& os, const TodoList& td );

private:

    TSVectorImp<TodoEntry> Vect;// sorted vector that holds the entries

    BOOL Dirty;                 // indicates whether this list has been
                                // modified.

};

//---------------------------------------------------------------------
//
//  class ListBox
//
//      wrapper around the Windows listbox, providing an interface
//      that fits with the Todo list.  This is used to display the
//      Todo list in a window.
//
//---------------------------------------------------------------------

class ListBox
{

public:

    ListBox();

    const ListBox& operator = ( const TodoList& );
                                // copies the entries in the TodoList
                                // into the list box.

    void Focus();               // sets focus to the list box.
    void Move( const RECT& );   // moves and resizes the list box.
    int Current();              // returns the index of the current
                                // selection.
    void Remove( int );         // removes the specified entry from
                                // the list box.
    void Insert( int, const TodoEntry& );
                                // adds an entry to the list box.
    void Replace( int, const TodoEntry& );
                                // replaces an entry in the list box
                                // with another entry.
    void Select( int );         // selects the specified entry.
    void Clear();               // removes all entries.

    void Create( HWND, HWND, const RECT& );
                                // builds the list box.  This can't be
                                // done in the constructor because we
                                // don't have enough information at the
                                // time of construction.

private:

    HWND hListBox;              // handle of the list box.

};

//---------------------------------------------------------------------
//
//  class TodoWindow
//
//      the main window for this application.  There's nothing displayed
//      in the window except for the list box.
//---------------------------------------------------------------------

class TodoWindow : public Window
{

public:

    TodoWindow() { *TitleName = '\0'; *FileName = '\0'; }

protected:

    virtual LONG Dispatch( WPARAM, WPARAM, LPARAM );

    virtual BOOL RegisterClass();
    virtual BOOL CreateNewWindow();

private:

    ListBox LB;                 // the list box used by this window.
    TodoList Tdl;               // the Todo list being displayed in this
                                // window.  There's a lot of parallelism
                                // between the operations of these two
                                // objects, and it might be worthwhile
                                // to add a class derived from both
                                // ListBox and TodoList for use here.

    char TitleName[MAXFILE+MAXEXT];
    char FileName[MAXPATH];     // path to the file currently being
                                // used.  "" if there is no file.

    void NewList();
    void OpenFile();
    void SaveFile();
    void SaveFileAs();
    void ShowEditBox();
    void NewEntry();
    void DelEntry();
    void ShowAboutBox();

    BOOL ShowSaveBox();

    void MoveListBox();

    void ReadFile();
    void WriteFile();
    void CheckSave();

    BOOL ProcessCommand( WPARAM, LPARAM );

};

//---------------------------------------------------------------------
//
//  inline functions.
//
//---------------------------------------------------------------------

inline TodoEntry::TodoEntry() : Dirty( FALSE ), Priority( 1 )
{
}

inline void TodoEntry::Clear()
{
    Dirty = 0;
}

inline BOOL TodoEntry::Modified() const
{
    return Dirty;
}

inline int operator == ( const TodoEntry& e1, const TodoEntry& e2 )
{
    return e1.DateDue == e2.DateDue;
}

inline int operator <  ( const TodoEntry& e1, const TodoEntry& e2 )
{
    return e1.DateDue < e2.DateDue;
}

inline TodoList::TodoList() : Vect( 20, 5 )
{
}

inline TodoEntry& TodoList::operator [] ( unsigned idx )
{
    return Vect[idx];
}

inline ListBox::ListBox() : hListBox( 0 )
{
}

inline void ListBox::Focus()
{
    if( IsWindow( hListBox ) )
        SetFocus( hListBox );
}

inline void ListBox::Move( const RECT& wrect )
{
    MoveWindow( hListBox,
                wrect.left,
                wrect.top,
                wrect.right - wrect.left,
                wrect.bottom - wrect.top,
                TRUE
              );
}

inline int ListBox::Current()
{
    return (int)SendMessage( hListBox, LB_GETCURSEL, 0, 0 );
}

inline void ListBox::Remove( int i )
{
    SendMessage( hListBox, LB_DELETESTRING, i, 0 );
    Select( i );
}

inline void ListBox::Replace( int i, const TodoEntry& tde )
{
    Remove( i );
    Insert( i, tde );
}

inline void ListBox::Select( int i )
{
    i = min( i, (int)SendMessage( hListBox, LB_GETCOUNT, 0, 0 ) - 1 );
    SendMessage( hListBox, LB_SETCURSEL, i, 0 );
}

inline void ListBox::Clear()
{
    SendMessage( hListBox, LB_RESETCONTENT, 0, 0 );
}

#endif  // __TODOLIST_H

