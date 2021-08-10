//---------------------------------------------------------------------
//
//  TODODLGS.H
//
//      Copyright (c) 1991, 1995 by Borland International
//      All Rights Reserved.
//
//  Defines the following classes, which handle all the dialog boxes for
//  the Todo program.
//
//      AboutBox
//
//      FileBox     - provides a an interface to the Windows common
//                    dialogs for selecting a file name.
//
//      EditBox     - provides a dialog box for editing an entry in the
//                    Todo list.
//
//---------------------------------------------------------------------
#if !defined(TODODLGS_H)
#define TODODLGS_H

#include <services/wsysinc.h>
#include <commdlg.h>
#include <dir.h>
#include <strstrea.h>

#include "todowin.h"
#include "todolist.h"

//---------------------------------------------------------------------
//
//  class AboutBox
//
//      draws and manages the About dialog.
//
//---------------------------------------------------------------------

class AboutBox : public ModalDialog
{

public:

    AboutBox( HWND );

private:

    virtual LPSTR GetDialogName();

    virtual BOOL Dispatch( HWND, UINT, WPARAM, LPARAM );

};

//---------------------------------------------------------------------
//
//  class FileBox
//
//      draws and manages a dialog box for selecting a file.
//
//---------------------------------------------------------------------

class FileBox
{

public:

    static BOOL GetOpenFileName( HWND handle, char *fileName, char *titleName );
    static BOOL GetSaveFileName( HWND handle, char *fileName, char *titleName );

private:

    static OPENFILENAME ofn;
    static char *filters[];

};

//---------------------------------------------------------------------
//
//  class EditBox
//
//      draws and manages a dialog box to edit an entry in the Todo list.
//
//---------------------------------------------------------------------

class TodoEntry;

class EditBox : public ModalDialog
{

public:

    EditBox( HWND, TodoEntry& );// constructor for the EditBox.
                                //
                                // Arguments:
                                //
                                // HWND owner - handle of the owner
                                //              of this dialog
                                // TodoEntry& td - the entry to be edited

private:

    virtual LPSTR GetDialogName();

    virtual BOOL Dispatch( HWND, UINT, WPARAM, LPARAM );

    TodoEntry& Current;         // the entry being edited

    int Button;                 // current selection among the radio
                                // buttons that set the priority

    void InitDlg( HWND );       // used internally
    void CheckButton( HWND, WPARAM );  // used internally
    void OkCmd( HWND );         // used internally
    void CancelCmd( HWND );     // used internally
};

//---------------------------------------------------------------------
//
//  inline functions
//
//---------------------------------------------------------------------

inline AboutBox::AboutBox( HWND hOwner ) : ModalDialog( hOwner )
{
}

inline EditBox::EditBox( HWND hOwner, TodoEntry& td ) :
    ModalDialog( hOwner ), Current( td )
{
}

#endif  // TODODLGS_H
