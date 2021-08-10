//---------------------------------------------------------------------
//
//  TODOWIN.H
//
//      Copyright (c) 1991, 1995 by Borland International
//      All Rights Reserved.
//
//  Defines the following classes, which are useful for building
//  general purpose windows applications:
//
//  WinBase - provides basic data and functionality for
//            windows programming.
//
//  ModalDialog - provides for modal dialog boxes.  Inherits from
//            WinBase, which is a virtual base.
//
//  Window  - provides core functionality for a window under Windows.
//            Inherits from WinBase, which is a virtual base.
//
//---------------------------------------------------------------------
#if !defined(TODOWIN_H)
#define TODOWIN_H

#include <winsys/wsysinc.h>
#include <services/except.h>
#include <services/checks.h>
#include <services/cstring.h>

class FileError : public xmsg
{

public:

    FileError( const char *fileName ) :
        xmsg( string("File error in ") + fileName ) {}

};

//---------------------------------------------------------------------
//
//  class WinBase
//
//      provides the basic data and functionality for all classes
//      used in the windows application.  It is an abstract base class.
//
//---------------------------------------------------------------------

class WinBase
{

public:

    virtual UINT Run() = 0;     // the core function of all windows!  For
                                // the main application window, this
                                // provides the message loop.  In modal
                                // dialogs, it sets up the dialog box,
                                // calls the dialog proc, and closes down
                                // the dialog.



    static  HINSTANCE hInst;    // the handle of the current instance

    static  HINSTANCE hPrevInst;// the handle of the previous instance

    static  LPSTR Cmd;          // pointer to the command line

    static  int Show;           // the nCmdShow parameter of the current
                                // instance

    HWND    hWnd();             // access function

protected:

    HWND hWindow;               // the window handle of the class.  This is
                                // accessed through hWnd(), and it will
                                // provide the correct handle for any
                                // derived class.

                                // NOTE: this field is not initialized by
                                // the constructor of this class.  It must
                                // be initialized by the constructor of a
                                // class derived from this class.

};

//---------------------------------------------------------------------
//
//  class ModalDialog
//
//      provides basic functionality for modal dialog boxes.  It is an
//      abstract base class.
//
//---------------------------------------------------------------------

class ModalDialog : public virtual WinBase
{

public:

    ModalDialog( HWND );        // constructor.  Since a modal dialog
                                // needs to know its owner, the handle
                                // of the owner is passed as a parameter
                                // to the constructor.

    ~ModalDialog();

    virtual UINT Run();         // the core of a modal dialog.  It sets
                                // up the dialog, executes it, and closes
                                // it down.

protected:

    virtual BOOL Dispatch( HWND, UINT, WPARAM, LPARAM );
                                // the core of any window.  Whenever
                                // DlgProc receives a message it passes
                                // the message on to Dispatch().  If
                                // Dispatch() doesn't handle the message
                                // itself, it should call the Dispatch()
                                // function in its base class.  Ultimately,
                                // messages not handled higher up are
                                // handled by this version of Dispatch(),
                                // which just returns FALSE, indicating
                                // that the message wasn't handled by
                                // the dialog box at all.

            UINT Result;        // this holds the value which will be
                                // returned by Run().  If the dialog box
                                // needs to return a success code, that
                                // code should be stored here by the
                                // dialog handler.

private:

    virtual LPSTR GetDialogName() = 0;
                                // returns a far pointer to a string
                                // that contains the name of the dialog
                                // resource for the current dialog box.
                                // This is used in Run() to load the
                                // resource.

    static  BOOL CALLBACK _export DlgProc( HWND, UINT, WPARAM, LPARAM );
                                // the dialog proc that windows calls
                                // when it has messages for the current
                                // dialog.

    static  ModalDialog *CurDlg;
                                // this holds a pointer to the currenly
                                // active ModalDialog.  It is set up when
                                // the constructor is called, and is used
                                // by DlgProc() to route messages to the
                                // right Dispatch() function.

};

//---------------------------------------------------------------------
//
//  class Window
//
//      provides the basic functionality for a normal window under
//      windows.
//
//---------------------------------------------------------------------

class Window : public virtual WinBase
{

public:

    virtual BOOL Create();      // creates the window.  This involves
                                // registering the window class if
                                // it hasn't already been registered,
                                // creating the actual window, and
                                // inserting the window into the internal
                                // window list.

    virtual UINT Run();         // provides the message loop.

protected:

    virtual LONG Dispatch( UINT, WPARAM, LPARAM );
                                // dispatches messages in a class derived
                                // from Window.  When WndProc() receives
                                // a message, it determines which Window
                                // object the message should be routed
                                // to, and calls Dispatch() for that object.
                                // If the Dispatch() function in a derived
                                // class does not handle any particular
                                // message, it should pass that message
                                // on down to the Dispatch() function in
                                // its base class.  The version of Dispatch()
                                // in Window itself just calls DefWindowProc.

    virtual BOOL RegisterClass() = 0;
                                // the derived class should override this
                                // function and register a window class
                                // defined appropriately for the program.

    virtual BOOL CreateNewWindow() = 0;
                                // the derived class should override this
                                // function and create a window that's
                                // appropriate for the program.

    static  LRESULT CALLBACK _export WndProc( HWND, UINT, WPARAM, LPARAM );
                                // the window proc that windows calls
                                // when it has messages for any window
                                // in the current application.  WndProc()
                                // posts the message to the appropriate
                                // window.

            void Insert();      // should be called from CreateNewWindow()
                                // after successfully calling the windows
                                // function CreateWindow().  Insert() adds
                                // the current object to the Window list,
                                // enabling normal dispatching of messages
                                // to the current object.

private:

    static Window *WinList;     // have to maintain a list of Windows so
    Window *NextWin;            // that we can dispatch messages to the
                                // correct one.

    static Window *InCreate;    // sort-of kludgy.  But there are messages
                                // that are sent to a window during the
                                // call to CreateWindow().  We assume that
                                // any message received by WndProc() during
                                // a call to CreateWindow() is meant for
                                // the window being created, and dispatch
                                // those messages to that window.

};

inline HWND WinBase::hWnd()
{
    return hWindow;
}

inline ModalDialog::ModalDialog( HWND hOwner ) : Result( 0 )
{
    CHECK( CurDlg == 0 );
    CurDlg = this;
    hWindow = hOwner;
}

inline ModalDialog::~ModalDialog()
{
    CHECK( CurDlg != 0 );
    CurDlg = 0;
}

inline void Window::Insert()
{
    NextWin = WinList;
    WinList = this;
}

#endif  // TODOWIN_H
