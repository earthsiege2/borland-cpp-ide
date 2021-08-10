// Borland C++ - (C) Copyright 1991, 1992 by Borland International
//
//  IDE Style Sheet example

#define  STRICT
#include <windows.h>
#include <stdlib.h>
#include <string.h>

LRESULT CALLBACK _export WndProc( HWND hWnd, UINT iMessage,
                                 WPARAM wParam, LPARAM lParam );

class Main
{
public:
  static HINSTANCE hInstance;
  static HINSTANCE hPrevInstance;
  static int nCmdShow;
  static int MessageLoop( void );
};

class Window
{
protected:
    HWND hWnd;
public:
    // Provide (read) access to the window's handle in case it is needed
    // elsewhere.
    HWND GetHandle( void ) { return hWnd; }

    BOOL Show( int nCmdShow ) { return ShowWindow( hWnd, nCmdShow ); }
    void Update( void ) { UpdateWindow( hWnd ); }
    // Pure virtual function makes Window an abstract class.
    virtual LRESULT WndProc( UINT iMessage, WPARAM wParam, LPARAM lParam ) = 0;
};

class MainWindow : public Window
{
private:
    static char szClassName[];
    
public:
    // Register the class only AFTER WinMain assigns appropriate
    // values to static members of Main and only if no previous
    // instances of the program exist (a previous instance would
    // have already performed the registration).
    static void Register( void )
    {
        WNDCLASS wndclass;   // Structure used to register Windows class.

        wndclass.style         = CS_HREDRAW | CS_VREDRAW;
        wndclass.lpfnWndProc   = ::WndProc;
        wndclass.cbClsExtra    = 0;
        // Reserve extra bytes for each instance of the window;
        // we will use these bytes to store a pointer to the C++
        // (MainWindow) object corresponding to the window.
        // the size of a 'this' pointer depends on the memory model.
        wndclass.cbWndExtra    = sizeof( MainWindow * );
        wndclass.hInstance     = Main::hInstance;
        wndclass.hIcon         = LoadIcon( Main::hInstance, "stylesht" );
        wndclass.hCursor       = LoadCursor( NULL, IDC_ARROW );
        wndclass.hbrBackground = (HBRUSH)GetStockObject( WHITE_BRUSH );
        wndclass.lpszMenuName  = NULL;
        wndclass.lpszClassName = szClassName;

        if ( ! RegisterClass( &wndclass ) )
            exit( FALSE );
    }

    // Do not create unless previously registered.
    MainWindow( void )
    {
        // Pass 'this' pointer in lpParam of CreateWindow().
        hWnd = CreateWindow( szClassName,
            szClassName,
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT,
            0,
            CW_USEDEFAULT,
            0,
            NULL,
            NULL,
            Main::hInstance,
            (LPSTR) this );
        if ( ! hWnd )
            exit( FALSE );

        Show( Main::nCmdShow );
        Update();
    }
    LRESULT WndProc( UINT iMessage, WPARAM wParam, LPARAM lParam );

    // Print a message in the client rectangle.
    void Paint( void );
    
};

HINSTANCE Main::hInstance = 0;
HINSTANCE Main::hPrevInstance = 0;
int       Main::nCmdShow = 0;

int Main::MessageLoop( void )
{
    MSG msg;

    while( GetMessage( &msg, NULL, 0, 0 ) )
    {
        TranslateMessage( &msg );
        DispatchMessage( &msg );
    }
    return msg.wParam;
}

char MainWindow::szClassName[] = "Hello, Style Sheets!";

static char szMessage[] =
{
   "The graph above represents the way that"
   " project options, StyleSheets and local"
   " options on a node all interact to form"
   " the options that will be passed to tools"
   " at various stages of building the project."
   " Note that the Options|Project menu item"
   " behaves slightly different when your project"
   " has a single top-level target."
   " Always refer to the 'View options hierarchy'"
   " menu option on any node's SpeedMenu. The"
   " order of precedence always starts at the"
   " node you are compiling or linking, working"
   " your way up to the tool defaults."
};
   
void MainWindow::Paint( void )
{
    PAINTSTRUCT ps;

    HDC hDC = BeginPaint( hWnd, &ps );

    HBITMAP bitmap = LoadBitmap( Main::hInstance, "StyleSht" );
    HDC memDC = CreateCompatibleDC( hDC );
    HBITMAP oldBitmap = (HBITMAP)SelectObject( memDC, bitmap );
    BitBlt( hDC, 0, 0, 400, 200, memDC, 0, 0, SRCCOPY );
    SelectObject( memDC, oldBitmap );
    DeleteDC( memDC );
    FreeResource( bitmap );

    HFONT   oldFont   = (HFONT)( SelectObject( hDC, 
                                   GetStockObject( ANSI_VAR_FONT ) ) );
    RECT   rc = { 0, 205, 400, 405 };
    DrawText( hDC, szMessage, sizeof(szMessage) - 1, &rc, 
                           DT_CENTER | DT_VCENTER | DT_WORDBREAK );
    SelectObject( hDC, oldFont );                           
    
    EndPaint( hWnd, &ps );
}

LRESULT MainWindow::WndProc( UINT iMessage, WPARAM wParam, LPARAM lParam )
{
    switch (iMessage)
    {
        case WM_CREATE:
            break;
        case WM_PAINT:
            Paint();
            break;
        case WM_DESTROY:
            PostQuitMessage( 0 );
            break;
        default:
            return DefWindowProc( hWnd, iMessage, wParam, lParam );
    }
    return 0;
}

// If data pointers are near pointers
#if defined(__SMALL__) || defined(__MEDIUM__)
inline Window *GetPointer( HWND hWnd )
{
    return (Window *) GetWindowWord( hWnd, 0 );
}
inline void SetPointer( HWND hWnd, Window *pWindow )
{
    SetWindowWord( hWnd, 0, (WORD) pWindow );
}

// else pointers are far
#elif defined(__LARGE__) || defined(__COMPACT__) || defined(__FLAT__)
inline Window *GetPointer( HWND hWnd )
{
    return (Window *) GetWindowLong( hWnd, 0 );
}
inline void SetPointer( HWND hWnd, Window *pWindow )
{
    SetWindowLong( hWnd, 0, (LONG) pWindow );
}

#else
    #error Choose another memory model!
#endif

LRESULT  CALLBACK _export WndProc( HWND hWnd, UINT iMessage, WPARAM wParam,
                                 LPARAM lParam )
{
    // Pointer to the (C++ object that is the) window.
    Window *pWindow = GetPointer( hWnd );

    // The pointer pWindow will have an invalid value if the WM_CREATE
    // message has not yet been processed (we respond to the WM_CREATE
    // message by setting the extra bytes to be a pointer to the
    // (C++) object corresponding to the Window identified
    // by hWnd).  The messages that
    // precede WM_CREATE must be processed without using pWindow so we
    // pass them to DefWindowProc.
    // How do we know in general if the pointer pWindow is invalid?
    // Simple: Windows allocates the window extra bytes using LocalAlloc
    // which zero initializes memory; thus, pWindow will have a value of
    // zero before we set the window extra bytes to the 'this' pointer.
    // Caveat emptor: the fact that LocalAlloc will zero initialize the
    // window extra bytes is not documented; therefore, it could change
    // in the future.

    if ( pWindow == 0 )
    {
        if ( iMessage == WM_CREATE )
        {
            LPCREATESTRUCT lpcs;

            lpcs = (LPCREATESTRUCT) lParam;
            pWindow = (Window *) lpcs->lpCreateParams;

            // Store a pointer to this object in the window's extra bytes;
            // this will enable us to access this object (and its member
            // functions) in WndProc where we are
            // given only a handle to identify the window.
            SetPointer( hWnd, pWindow );
            // Now let the object perform whatever
            // initialization it needs for WM_CREATE in its own
            // WndProc.
      return pWindow->WndProc( iMessage, wParam, lParam );
        }
        else
            return DefWindowProc( hWnd, iMessage, wParam, lParam );
    }
    else
        return pWindow->WndProc( iMessage, wParam, lParam );
}

// Turn off warning: Parameter 'lpszCmdLine' is never used in function WinMain(unsigned int,unsigned int,char far*,int)
#pragma argsused

// Turn off warning: 'MainWnd' is assigned a value that is never used in function WinMain(unsigned int,unsigned int,char far*,int)
#pragma option -w-aus

int PASCAL WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine,
                    int nCmdShow )
{
    Main::hInstance = hInstance;
    Main::hPrevInstance = hPrevInstance;
    Main::nCmdShow = nCmdShow;

    // A Windows class should be registered with Windows before any windows
    // of that type are created.
    // Register here all Windows classes that will be used in the program.
    // Windows classes should not be registered if an instance of
    // the program is already running.
    if ( ! Main::hPrevInstance ) {
        MainWindow::Register();
    }

    MainWindow MainWnd;

    return Main::MessageLoop();
}
