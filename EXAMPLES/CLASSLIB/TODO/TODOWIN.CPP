//---------------------------------------------------------------------
//
//  TODOWIN.CPP - part of TODO example program
//
//      Copyright (c) 1991, 1993 by Borland International
//      All Rights Reserved.
//
//---------------------------------------------------------------------

#define STRICT

#include <windows.h>
#include <except.h>
#include <checks.h>

#include "todowin.h"

HINSTANCE WinBase::hInst;
HINSTANCE WinBase::hPrevInst;
LPSTR     WinBase::Cmd;
int       WinBase::Show;

//---------------------------------------------------------------------
//
//  members and data for class ModalDialog
//
//---------------------------------------------------------------------

ModalDialog *ModalDialog::CurDlg = 0;

UINT ModalDialog::Run()
{
    FARPROC dlgProc =
        MakeProcInstance( (FARPROC)ModalDialog::DlgProc, (HINSTANCE)hInst );
    DialogBox( (HINSTANCE)hInst, 
               (LPCSTR)GetDialogName(), 
               (HWND)hWnd(), 
               (DLGPROC)dlgProc );
    FreeProcInstance( dlgProc );
    return Result;
}

BOOL CALLBACK _export ModalDialog::DlgProc( HWND hDlg,
                UINT msg,
                WPARAM wParam,
                LPARAM lParam
                                            )
{
    return CurDlg->Dispatch( hDlg, msg, wParam, lParam );
}

BOOL ModalDialog::Dispatch( HWND, UINT, WPARAM, LPARAM )
{
    return FALSE;
}

//---------------------------------------------------------------------
//
//  members and data for class Window
//
//---------------------------------------------------------------------

Window *Window::InCreate = 0;
Window *Window::WinList = 0;

BOOL Window::Create()
{
    if( hPrevInst == 0 && RegisterClass() == FALSE )
        {
        return FALSE;
        }

    InCreate = this;            // flag that we're inside CreateNewWindow()

    CreateNewWindow();

    NextWin = WinList;          // insert this object into the Window list
    WinList = this;

    InCreate = 0;               // now it's OK to use normal dispatching

    return TRUE;
}

UINT Window::Run()
{
    PRECONDITION( hWnd() != 0 );// check that we really exist

    MSG msg;
    while( GetMessage( &msg, NULL, NULL, NULL ) != 0 )
        {
        TranslateMessage( &msg );
        DispatchMessage( &msg );
        }
    return msg.wParam;
}

LONG Window::Dispatch( UINT msg, WPARAM wParam, LPARAM lParam )
{
    return DefWindowProc( (HWND)hWnd(), msg, wParam, lParam );
}

LRESULT CALLBACK Window::WndProc( HWND hWnd,
                                  UINT msg,
                                  WPARAM wParam,
                                  LPARAM lParam )
{
    try {
        Window *cur = Window::WinList;

        //  look up the handle in our Window list
        while( cur != 0 && cur->hWnd() != hWnd )
            cur = cur->NextWin;

        //  normal dispatching
        if( cur != 0 )
            return cur->Dispatch( msg, wParam, lParam );

        //  if we're inside CreateNewWindow(), assume
        //  that the message is for us
        if( InCreate != 0 )
            {
            InCreate->hWindow = hWnd;
            return InCreate->Dispatch( msg, wParam, lParam );
            }

        //  otherwise, pass it on to windows
        return DefWindowProc( hWnd, msg, wParam, lParam );
        }
    catch( const xmsg& msg )
        {
        MessageBox( InCreate ? InCreate->hWindow : hWnd,
                    msg.why().c_str(),
                    "Fatal Error",
                    MB_ICONSTOP | MB_OK );
        PostQuitMessage(0);
        }
    catch( ... )
        {
        MessageBox( InCreate ? InCreate->hWindow : hWnd,
                    "Unknown error",
                    "Fatal Error",
                    MB_ICONSTOP | MB_OK );
        PostQuitMessage(0);
        }
    return DefWindowProc( hWnd, msg, wParam, lParam );
}

