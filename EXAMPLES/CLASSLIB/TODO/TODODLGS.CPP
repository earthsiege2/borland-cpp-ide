//---------------------------------------------------------------------
//
//  TODODLGS.CPP - part of TODO example program
//
//      Copyright (c) 1991, 1993 by Borland International
//      All Rights Reserved.
//
//---------------------------------------------------------------------


#include <services/wsysinc.h>
#include <windowsx.h>
#include <string.h>

#include "tododlgs.h"
#include "tododefs.h"

//---------------------------------------------------------------------
//
//  member functions for class AboutBox.
//
//  not much needed here...
//
//---------------------------------------------------------------------

LPSTR AboutBox::GetDialogName()
{
    return "AboutBox";
}

BOOL AboutBox::Dispatch( HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam )
{
    switch( msg )
        {

        case WM_INITDIALOG:

            return TRUE;                // no initialization.

        case WM_COMMAND:

            if( GET_WM_COMMAND_ID(wParam, lParam) == IDOK ||
            GET_WM_COMMAND_ID(wParam, lParam) == IDCANCEL )
            {
            EndDialog( hDlg, TRUE );    // selecting OK or Cancel
            return TRUE;                // terminates the dialog
            }

        default:                        // if we don't handle it, pass it
                                        // to our parent.

            return ModalDialog::Dispatch( hDlg, msg, wParam, lParam );

  }
}

//---------------------------------------------------------------------
//
//  member functions for class FileBox.
//
//---------------------------------------------------------------------

BOOL FileBox::GetOpenFileName( HWND handle, char *fileName, char *titleName )
{
    ofn.hwndOwner = handle;
    ofn.lpstrFile = fileName;
    ofn.lpstrFileTitle = titleName;
    ofn.Flags = OFN_FILEMUSTEXIST;
    return ::GetOpenFileName( &ofn );
}

BOOL FileBox::GetSaveFileName( HWND handle, char *fileName, char *titleName )
{
    ofn.hwndOwner = handle;
    ofn.lpstrFile = fileName;
    ofn.lpstrFileTitle = titleName;
    ofn.Flags = OFN_OVERWRITEPROMPT;

    return ::GetOpenFileName( &ofn );
}

OPENFILENAME FileBox::ofn =
{
    sizeof(OPENFILENAME),       // lStructSize
    0,                          // hwndOwner
    0,                          // hInstance
    filters[0],                 // lpstrFilter
    0,                          // lpstrCustomFilter
    0,                          // nMaxCustFilter
    0,                          // nFilterIndex
    0,                          // lpstrFile
    MAXPATH,                    // nMaxFile
    0,                          // lpstrFileTitle
    MAXFILE+MAXEXT,             // nMaxFileTitle
    0,                          // lpstrInitialDir
    0,                          // lpstrTitle
    0,                          // Flags
    0,                          // nFileOffset
    0,                          // nFileExtension
    "tdo",                      // lpstrDefExt
    0,                          // lCustData
    0,                          // lpfnHook
    0                           // lpTemplateName
};

char *FileBox::filters[] =
{
    "Todo Files (*.TDO)",   "*.tdo",
    "All Files (*.*)",      "*.*",
    ""
};


//---------------------------------------------------------------------
//
//  member functions for class EditBox.
//
//---------------------------------------------------------------------

LPSTR EditBox::GetDialogName()
{
    return "TodoEdit";
}

//---------------------------------------------------------------------
//
//  void EditBox::InitDlg( HWND hDlg );
//
//  initializes the dialog box.
//
//---------------------------------------------------------------------

void EditBox::InitDlg( HWND hDlg )
{
    // set up the current date edit field.
    SetDlgItemText( hDlg, IDE_DATEENT, 
                    Current.DateCreated.AsString().c_str() );

    // set up the date due edit field.
    SetDlgItemText( hDlg, IDE_DATEDUE, 
                    Current.DateDue.AsString().c_str() );

    // set up the text edit field
    SetDlgItemText( hDlg, IDE_TEXT, Current.Text.c_str() );

    // set up the correct radio button
    Button = IDE_HIGH + 1 - Current.Priority;
    CheckRadioButton( hDlg, IDE_LOW, IDE_HIGH, Button );
}

//---------------------------------------------------------------------
//
//  void EditBox::CheckButton( HWND hDlg, WPARAM wParam );
//
//  called when the user selects one of the radio buttons.
//
//---------------------------------------------------------------------

void EditBox::CheckButton( HWND hDlg, WPARAM wParam )
{
    Button = wParam;
    CheckRadioButton( hDlg, IDE_LOW, IDE_HIGH, Button );
}

//---------------------------------------------------------------------
//
//  void EditBox::OkCmd( HWND hDlg );
//
//  called when the user selects the OK button.  Copies data from the
//  dialog into the Todo entry and terminates the dialog.
//
//---------------------------------------------------------------------

void EditBox::OkCmd( HWND hDlg )
{
    char temp[100 ];

    //  copy date created from dialog.
    GetDlgItemText( hDlg, IDE_DATEENT, temp, sizeof( temp ) );
    {

    istrstream date( temp, sizeof( temp ) );
    date >> Current.DateCreated;
    }

    //  copy date due from dialog.
    GetDlgItemText( hDlg, IDE_DATEDUE, temp, sizeof( temp ) );
    {
    istrstream date( temp, sizeof( temp ) );
    date >> Current.DateDue;
    }

    //  copy text from dialog
    GetDlgItemText( hDlg, IDE_TEXT, temp, sizeof(temp) );
    Current.Text = temp;

    //  copy priority from dialog.
    Current.Priority = IDE_HIGH + 1 - Button;

    //  mark this entry as modified.
    Current.Dirty = TRUE;

    EndDialog( hDlg, TRUE );
}

//---------------------------------------------------------------------
//
//  void EditBox::CancelCmd( HWND hDlg );
//
//  called when the user selects the Cancel button.  Terminates the
//  dialog without changing any fields in the entry.
//
//---------------------------------------------------------------------

void EditBox::CancelCmd( HWND hDlg )
{
    Result = 1;
    EndDialog( hDlg, TRUE );
}

//---------------------------------------------------------------------
//
//  BOOL EditBox::Dispatch( HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam );
//
//  dispatches commands.
//
//---------------------------------------------------------------------

BOOL EditBox::Dispatch( HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam )
{
    switch( msg )
        {
        case WM_INITDIALOG:

            InitDlg( hDlg );
            return TRUE;

        case WM_COMMAND:

            switch( GET_WM_COMMAND_ID(wParam, lParam) )
                {
                case IDE_LOW:
                case IDE_MEDIUM:
                case IDE_HIGH:

                    CheckButton( hDlg, GET_WM_COMMAND_ID(wParam, lParam) );
                    return TRUE;

                case IDOK:

                    OkCmd( hDlg );
                    return TRUE;

                case IDCANCEL:

                    CancelCmd( hDlg );
                    return TRUE;
                }
        }

    return ModalDialog::Dispatch( hDlg, msg, wParam, lParam );
}
