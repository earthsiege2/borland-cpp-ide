//---------------------------------------------------------------------
//
//  TODOLIST.CPP - part of TODO example program
//
//      Copyright (c) 1991, 1993 by Borland International
//      All Rights Reserved.
//
//---------------------------------------------------------------------

#define STRICT

#include <services/wsysinc.h>
#include <windowsx.h>
#include <strstrea.h>
#include <fstream.h>
#include <ctype.h>
#include <checks.h>
#include <string.h>

#include "classlib\objstrm.h"
#include "todolist.h"
#include "tododefs.h"
#include "tododlgs.h"

//---------------------------------------------------------------------
//
//  ostream& operator << ( ostream&, const TodoEntry& );
//
//  puts a TodoEntry onto an ostream in text form.
//
//---------------------------------------------------------------------

ostream& operator << ( ostream& os, const TodoEntry& tde )
{
    char temp[ 256 ];
    ostrstream tstr( temp, sizeof temp );
    tstr << tde.Priority
         << '\t'
         << tde.DateCreated
         << '\t'
         << tde.DateDue
         << '\t'
         << tde.Text
         << ends;
    return os << temp;
}

//---------------------------------------------------------------------
//
//  ipstream& operator >> ( ipstream& is, TodoEntry& td );
//  opstream& operator << ( opstream& os, TodoEntry& td );
//
//  inserter and extractor for TodoEntry and persistent streams.  
//  These work together to write entries out to a persistent stream 
//  and read them back in.
//
//---------------------------------------------------------------------

ipstream& operator >> ( ipstream& is, TodoEntry& td )
{
    is >> td.Priority >> td.DateDue >> td.DateCreated >> td.Text;
    td.Dirty = FALSE;
    return is;
}

opstream& operator << ( opstream& os, const TodoEntry& td )
{
    os << td.Priority << td.DateDue << td.DateCreated << td.Text;
    const_cast<TodoEntry&>(td).Dirty = FALSE;
    return os;
}

//---------------------------------------------------------------------
//
//  member functions for class TodoList.
//
//---------------------------------------------------------------------

void TodoList::Add( const TodoEntry& e )
{
    Dirty = TRUE;               // mark that the list has been modified
    Vect.Add( e );              // add the entry
}

void TodoList::Detach( unsigned idx )
{
    Dirty = TRUE;               // mark that the list has been modified
    Vect.Detach( idx );         // remove the entry
}

int TodoList::IndexOf( const TodoEntry& tde )
{
    for( int i = 0; i < Vect.Count(); i++ )
        if( Vect[i] == tde )
            return i;
    return -1;
}

static int CheckModified( const TodoEntry& ent, void * )
{
    return ent.Modified();
}

BOOL TodoList::Modified() const
{
    if( Dirty == TRUE )         // if we've added or deleted entries
        return TRUE;            // we've been modified
                                // otherwise, if any entry has been
                                // modified, the list has been modified.
    else
        return Vect.FirstThat( CheckModified, 0 ) != 0;
}

static void MarkEntrySaved( TodoEntry& ent, void * )
{
    ent.Clear();
}

void TodoList::MarkSaved() const
{
    const_cast<TodoList&>(*this).Dirty = FALSE;
    const_cast<TodoList&>(*this).Vect.ForEach( MarkEntrySaved, 0 );
}

void TodoList::Clear()
{
    Vect.Flush();
}

ipstream& operator >> ( ipstream& is, TodoList& td )
{
    unsigned count;
    is >> count;
    while( count-- != 0 )
        {
        TodoEntry temp;
        is >> temp;
        if( !is )
            return is;  // if stream isn't valid, don't try to add.
        td.Add( temp );
        }
    td.MarkSaved();
    return is;
}

opstream& operator << ( opstream& os, const TodoList& td )
{
    os << td.Vect.Count();
    TSVectorIteratorImp<TodoEntry> iter( td.Vect );
    while( iter )
        {
        os << iter.Current();
        iter++;
        }
    td.MarkSaved();
    return os;
}

//---------------------------------------------------------------------
//
//  const ListBox& ListBox::operator = ( const TodoList& tdl );
//
//  copies the contents of a TodoList into a ListBox.
//
//---------------------------------------------------------------------

const ListBox& ListBox::operator = ( const TodoList& tdl )
{
    PRECONDITION( hListBox != 0 );

    Clear();
    TSVectorIteratorImp<TodoEntry> iter( tdl.Vect );
    while( iter )
        {
        char buf[100];      // write the entry into a string
                            // and insert that string into
                            // the list box

        ostrstream( buf, 100 ) << iter.Current() << ends;
        SendMessage( hListBox, LB_ADDSTRING, NULL, (LONG)(LPSTR)buf );
        iter++;
        }
    Select( 0 );

    return *this;
}

void ListBox::Insert( int i, const TodoEntry& tde )
{
    char temp[100];
    ostrstream( temp, sizeof( temp ) ) << tde << ends;

    SendMessage( hListBox, LB_INSERTSTRING, i, (LONG)(LPSTR)temp );
    Select( i );
}

void ListBox::Create( HWND owner, HWND hInst, const RECT &wrect )
{
    hListBox = ::CreateWindow(
        "ListBox", NULL,
        LBS_NOTIFY | WS_BORDER | WS_VSCROLL |
            LBS_USETABSTOPS | WS_CHILD | WS_VISIBLE,
        wrect.left,
        wrect.top,
        wrect.right - wrect.left,
        wrect.bottom - wrect.top,
        (HWND)owner,
        (HMENU)IDC_LISTBOX,
        (HINSTANCE)hInst,
        NULL );

    int tabs[] = { 10, 100, 200 };
    SendMessage( hListBox,
                 LB_SETTABSTOPS,
                 sizeof(tabs)/sizeof(*tabs),
                 (LONG)(LPSTR)tabs
                );
    Focus();
}

//---------------------------------------------------------------------
//
//  member functions for class TodoWindow.
//
//  these are mostly self-explanatory.
//
//---------------------------------------------------------------------

BOOL TodoWindow::RegisterClass()
{
    WNDCLASS wc;

    wc.style = 0;
    wc.lpfnWndProc = Window::WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance =(HINSTANCE) hInst;
    wc.hIcon = LoadIcon( NULL, IDI_APPLICATION );
    wc.hCursor = LoadCursor( NULL, IDC_ARROW );
    wc.hbrBackground =(HBRUSH) GetStockObject( WHITE_BRUSH );
    wc.lpszMenuName = "TodoMenu";
    wc.lpszClassName = "TodoClass";

    return ::RegisterClass( &wc );
}

BOOL TodoWindow::CreateNewWindow()
{
    hWindow = ::CreateWindow(
        "TodoClass",
        "Todo List",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        (HINSTANCE)hInst,
        NULL
        );
    if( hWnd() == 0 )
        return FALSE;

    Insert();                   // insert this window into the window list

    RECT wrect;
    GetClientRect( (HWND)hWnd(), (LPRECT) &wrect);
    LB.Create( (HWND)hWnd(), (HWND)hInst, wrect );
                                // build a list box in the client rectangle
    LB = Tdl;                   // copy the Todo list into the list box

    ::ShowWindow( (HWND)hWnd(), Show );
    ::UpdateWindow( (HWND)hWnd() );
    return TRUE;
}

void TodoWindow::ShowAboutBox()
{
    AboutBox ab( (HWND)hWnd() );
    ab.Run();
}

void TodoWindow::ShowEditBox()
{
    int cur = LB.Current();
    if( cur == -1 )             // if there's nothing in the list,
        NewEntry();             // need to create an entry
    else
        {
        EditBox ed( (HWND)hWnd(), Tdl[cur] );
        ed.Run();
        LB.Replace( cur, Tdl[cur] );
        }
}

void TodoWindow::NewEntry()
{
    TodoEntry tde;
    EditBox ed( (HWND)hWnd(), tde );

    if( ed.Run() == 0 )         // ed.Run() returns 0 if terminated by
        {                       // OK, 1 if terminated by Cancel.
        Tdl.Add( tde );
        LB.Insert( Tdl.IndexOf( tde ), tde );
        }
}

void TodoWindow::DelEntry()
{
    int cur = LB.Current();
    if( cur == -1 )             // if there's nothing in the list, there's
        return;                 // nothing to delete.
    Tdl.Detach( cur );
    LB.Remove( cur );
    LB.Select( cur );
}

void TodoWindow::MoveListBox()
{
    RECT wrect;
    GetClientRect( (HWND)hWnd(), (LPRECT) &wrect);

    LB.Move( wrect );
}

//---------------------------------------------------------------------
//
//  void TodoWindow::CheckSave();
//
//  checks whether the Todo list has been modified.  If it has, asks
//  the user whether to save the list or not, and if it is to be saved,
//  writes it to a file.
//
//---------------------------------------------------------------------

void TodoWindow::CheckSave()
{
    if( Tdl.Modified() == TRUE && ShowSaveBox() == TRUE )
        SaveFile();
}

void TodoWindow::NewList()
{
    CheckSave();                // dump the current list
    Tdl.Clear();
    LB.Clear();
    *FileName = '\0';           // mark that there's no file
    *TitleName = '\0';
}

void TodoWindow::OpenFile()
{
    CheckSave();                // dump the current list
    Tdl.Clear();
    LB.Clear();
    if( FileBox::GetOpenFileName( hWnd(), FileName, TitleName ) == TRUE )
        ReadFile();             // read new data from the specified file
}

void TodoWindow::SaveFile()
{
    if( *TitleName == '\0' )
        SaveFileAs();
    else
        WriteFile();
}

void TodoWindow::SaveFileAs()
{
    if( FileBox::GetSaveFileName( hWnd(), FileName, TitleName ) == TRUE )
        WriteFile();
}

void TodoWindow::ReadFile()
{
    ifpstream in( FileName );           // open the input file
    in >> Tdl;                          // read the Todo list
    if( !in )                           // check whether read succeeded
        throw( FileError( FileName ) );
    LB = Tdl;                           // build the list box
}

void TodoWindow::WriteFile()
{
    ofpstream out( FileName );
    out << Tdl;
    if( !out )                          // check whether write succeeded
        throw( FileError( FileName ) );
}

BOOL TodoWindow::ShowSaveBox()
{
    if( MessageBox( (HWND)hWnd(),
        "Save Changes",
        "Current List Modified",
        MB_YESNO | MB_ICONQUESTION ) == IDYES )
        return TRUE;
    else
        return FALSE;
}

//---------------------------------------------------------------------
//
//  BOOL TodoWindow::ProcessCommand( WPARAM wParam, LPARAM lParam );
//
//  dispatches commands to the appropriate member functions.
//
//---------------------------------------------------------------------

BOOL TodoWindow::ProcessCommand( WPARAM wParam, LPARAM lParam )
{
    switch( GET_WM_COMMAND_ID(wParam, lParam) )
        {

        case IDM_QUIT:
            SendMessage((HWND)hWnd(), WM_CLOSE, 0, 0L);
            return TRUE;

        case IDM_NEW_LIST:
            NewList();
            return TRUE;

        case IDM_OPEN:
            OpenFile();
            return TRUE;

        case IDM_SAVE:
            SaveFile();
            return TRUE;

        case IDM_SAVEAS:
            SaveFileAs();
            return TRUE;

        case IDM_EDIT:
            ShowEditBox();
            return TRUE;

        case IDM_NEW_ENTRY:
            NewEntry();
            return TRUE;

        case IDM_DEL_ENTRY:
            DelEntry();
            return TRUE;

        case IDM_ABOUT:
            ShowAboutBox();
            return TRUE;

        case IDC_LISTBOX:
            if( GET_WM_COMMAND_CMD( wParam, lParam ) == LBN_DBLCLK )
                {
                ShowEditBox();
                return TRUE;
                }
            else
                return FALSE;
        default:
            return FALSE;
        }
}

//---------------------------------------------------------------------
//
//  LONG TodoWindow::Dispatch( UINT msg, WPARAM wParam, LPARAM lParam );
//
//  dispatches messages to the appropriate member functions.
//
//---------------------------------------------------------------------

LONG TodoWindow::Dispatch( UINT msg, WPARAM wParam, LPARAM lParam )
{
    switch( msg )
        {
        case WM_COMMAND:

            if( ProcessCommand( wParam, lParam ) == TRUE )
                {
                LB.Focus();
                return 0;
                }
            break;

        case WM_MOVE:
        case WM_SIZE:

            MoveListBox();
            return 0;

        case WM_QUERYENDSESSION:
            return TRUE;

        case WM_CLOSE:

            CheckSave();
            DestroyWindow( (HWND)hWnd() );
            return 0;

        case WM_DESTROY:
        case WM_QUIT:

            PostQuitMessage( 0 );
            break;
        }

    return Window::Dispatch( msg, wParam, lParam );
}

//---------------------------------------------------------------------
//
//  int PASCAL WinMain( HINSTANCE, HINSTANCE, LPSTR, int );
//
//  the main entry point for the program.
//
//---------------------------------------------------------------------

int PASCAL WinMain( HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR     lpCmd,
                    int       nShow)
{
    WinBase::hInst = hInstance;
    WinBase::hPrevInst = hPrevInstance;
    WinBase::Cmd = lpCmd;
    WinBase::Show = nShow;

    TodoWindow td;
    td.Create();
    return td.Run();
}

